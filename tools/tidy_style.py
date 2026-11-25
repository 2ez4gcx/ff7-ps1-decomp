"""tidy_style.py [--write] FILE... -- rewrite functions left in the permuter's style
(braces on their own line, 2-space indent, `case` one level in, blank lines after
every block) in the repository's style. Only whitespace, brace placement, the space
after a cast and `int`/`short` declarations (the same types as s32/s16) change.
Without --write it prints a unified diff."""
import difflib
import re
import sys
from pathlib import Path

TYPES = {'s8', 's16', 's32', 's64', 'u8', 'u16', 'u32', 'u64', 'int', 'short', 'char', 'long', 'void',
         'unsigned', 'signed', 'float', 'double'}
NOT_DECL = {'return', 'goto', 'case', 'else', 'do', 'break', 'continue', 'default'}
DECL = re.compile(r'^(?:(?:const|volatile|unsigned|signed|struct|register|static)\s+)*[A-Za-z_]\w*'
                  r'(?:\s+\**|\s*\*+\s*)[A-Za-z_]\w*(?:\[[^\]]*\])*(?:\s*=\s*[^;]+)?;$')
TYPE_MAP = [(r'^unsigned short ', 'u16 '), (r'^unsigned char ', 'u8 '), (r'^unsigned int ', 'u32 '),
            (r'^short ', 's16 '), (r'^int ', 's32 ')]


def is_cast(inner):
    c = inner.strip()
    words = c.replace('*', ' ').split()
    if not words or not all(re.fullmatch(r'[A-Za-z_]\w*', w) for w in words):
        return False
    if '*' in c:
        return True
    return words[-1] in TYPES or words[0] in ('struct', 'volatile', 'const')


def fix_casts(s):
    def rep(m):
        return m.group(0)[:-1] if is_cast(m.group(1)) else m.group(0)
    return re.sub(r'\(([^()]*)\) (?=[\w(&*~!\-])', rep, s)


def code(s):
    """The line without string/char literals and comments, for brace counting."""
    s = re.sub(r'"(?:\\.|[^"\\])*"', '""', s)
    s = re.sub(r"'(?:\\.|[^'\\])*'", "''", s)
    s = re.sub(r'/\*.*?\*/', '', s)
    return s.split('//')[0]


def is_head(line):
    """A line a brace on the next line belongs to (if/for/while/switch/else/do);
    after a statement, a brace-only line opens a block of its own."""
    c = code(line).strip()
    return c.endswith(')') or c in ('else', 'do', '} else') or c.endswith(' else')


def indent_of(s):
    return len(s) - len(s.lstrip(' '))


CASE = re.compile(r'^(case\b.*|default):$')


def merge_lines(lines):
    """Brace-only lines onto their head, `} else`, `else if`, `} while (..);`."""
    merged = []
    heads = []
    last_closed = None
    for s in lines:
        if s == '{' and merged and is_head(merged[-1]):
            heads.append(merged[-1])
            merged[-1] += ' {'
            continue
        if merged and merged[-1] == '}' and s.startswith('else'):
            merged[-1] = '} ' + s
            if s.endswith('{'):
                heads.append(s[:-1].strip())
            continue
        if merged and (merged[-1] == 'else' or merged[-1].endswith('} else')) and s.startswith('if ('):
            merged[-1] += ' ' + s
            if s.endswith('{'):
                heads.append(s[:-1].strip())
            continue
        if merged and merged[-1] == '}' and last_closed == 'do' and re.match(r'while \(.*\);$', s):
            merged[-1] = '} ' + s
            continue
        c = code(s).strip()
        if c.startswith('}'):
            last_closed = heads.pop().strip() if heads else None
            if c.endswith('{'):
                heads.append(c[1:-1].strip())
        elif c.endswith('{'):
            heads.append(c[:-1].strip())
        merged.append(s)
    return merged


def reindent(lines):
    """Indent by structure: 4 spaces a level, `case` at its switch's level, one more
    level for the statement of a brace-less if/else/for/while."""
    out = []
    stack = []  # (indent level of the opening line, is a switch)
    pending = 0
    for s in lines:
        c = code(s).strip()
        base = stack[-1][0] + 1 if stack else 1
        if c.startswith('}'):
            level = stack.pop()[0] if stack else 0
            if c.endswith('{'):
                stack.append((level, False))
            pending = 0
        elif CASE.match(c) and stack and stack[-1][1]:
            level = stack[-1][0]
            pending = 0
        elif c.startswith('#'):
            out.append(s)
            continue
        else:
            level = base + pending
            if c.endswith('{'):
                stack.append((level, c.startswith('switch (')))
                pending = 0
            elif not c or c.startswith(('/*', '//')):
                pass
            elif is_head(s) and not CASE.match(c) and not c.endswith(':'):
                pending += 1
            else:
                pending = 0
        out.append('    ' * level + s)
    return out


def reformat(header, body):
    """header: the function's head line (without `{`); body: lines between the braces."""
    nonblank = [l for l in body if l.strip()]
    pyc = any(indent_of(l) == 2 for l in nonblank)  # the permuter indents by 2
    if pyc:
        joined = reindent(merge_lines([l.strip() for l in nonblank]))
    else:
        # Written by hand, only the braces on their own line: keep its indent and blank lines.
        joined = []
        for l in body:
            if l.strip() == '{' and joined and is_head(joined[-1]):
                joined[-1] += ' {'
            elif l.strip().startswith('else') and joined and joined[-1].strip() == '}':
                joined[-1] += ' ' + l.strip()
            else:
                joined.append(l.rstrip())
        while joined and not joined[0].strip():
            joined.pop(0)
    n = 0
    while n < len(joined):
        s = joined[n].strip()
        if indent_of(joined[n]) == 4 and DECL.match(s) and s.split()[0] not in NOT_DECL:
            for a, b in TYPE_MAP:
                s2 = re.sub(a, b, s)
                if s2 != s:
                    joined[n] = '    ' + s2
                    break
            n += 1
        else:
            break
    if 0 < n < len(joined) and joined[n].strip():
        joined.insert(n, '')
    joined = [fix_casts(l) for l in joined]
    return header.rstrip() + ' {', joined


def tidy(text):
    lines = text.split('\n')
    out = []
    i = 0
    count = 0
    while i < len(lines):
        l = lines[i]
        head = None
        if (l and not l[0].isspace() and not l.startswith(('#', '/', '*', '}', 'typedef', 'extern', 'INCLUDE'))
                and '(' in l and not l.rstrip().endswith(';')):
            if l.rstrip().endswith(')') and i + 1 < len(lines) and lines[i + 1] == '{':
                head, start = l, i + 2
            elif l.rstrip().endswith(') {'):
                head, start = l.rstrip()[:-2], i + 1
        if head is None:
            out.append(l)
            i += 1
            continue
        end = start
        while lines[end] != '}':
            end += 1
        body = lines[start:end]
        allman = start == i + 2
        # Continuation lines may have any indent: the permuter's sign is a body at 2 spaces.
        nonblank = [b for b in body if b.strip()]
        allman_inside = any(b.strip() == '{' and k and is_head([x for x in body[:k] if x.strip()][-1])
                            for k, b in enumerate(body) if [x for x in body[:k] if x.strip()])
        odd = any(indent_of(b) == 2 for b in nonblank) or allman_inside
        if allman or odd:
            h, b = reformat(head, body)
            out.append(h)
            out.extend(b)
            count += 1
        else:
            out.extend(lines[i:end])
        out.append('}')
        i = end + 1
    return '\n'.join(out), count


def main():
    write = '--write' in sys.argv
    for p in [Path(a) for a in sys.argv[1:] if a != '--write']:
        old = p.read_text(encoding='utf-8')
        new, n = tidy(old)
        if new == old:
            continue
        print(f'# {p}: {n} functions', file=sys.stderr)
        if write:
            p.write_text(new, encoding='utf-8', newline='\n')
        else:
            sys.stdout.writelines(difflib.unified_diff(old.splitlines(True), new.splitlines(True), str(p), str(p)))


if __name__ == "__main__":
    main()
