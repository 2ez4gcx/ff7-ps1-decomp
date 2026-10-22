"""The game's executables as this repository builds them, by name.

A target is named after its source folder: `main` for SCUS_941.63 (src/main),
`field` for FIELD.BIN (src/field), and so on; config/targets.txt lists them.
Each one's paths come from its splat config.
"""
import re
from dataclasses import dataclass
from functools import lru_cache
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


@dataclass(frozen=True)
class Target:
    name: str          # src/<name>, asm/us/<name>
    config: Path
    image: Path        # what the game loads: the executable, or the unpacked overlay
    origin: int        # address of the image's first byte
    elf: Path          # what tools/build.py links
    asm: Path          # splat's asm (nonmatchings/<file>/<function>.s)
    src: Path

    @property
    def decls(self):
        return self.src / 'decls.h'


def _value(text, key):
    m = re.search(rf'^\s*{key}:\s*(\S+)', text, re.M)
    return m.group(1) if m else None


@lru_cache(maxsize=None)
def all_targets():
    """{name: Target} for every config in config/targets.txt."""
    out = {}
    for line in (ROOT / 'config' / 'targets.txt').read_text(encoding='utf-8').splitlines():
        if not line.strip() or line.startswith('#'):
            continue
        config = ROOT / 'config' / line.split()[0]
        text = config.read_text(encoding='utf-8')
        src = ROOT / _value(text, 'src_path')
        # The code segment: its file offset and address.
        m = re.search(r'^\s*start:\s*(0x[0-9A-Fa-f]+)\s*\n\s*vram:\s*(0x[0-9A-Fa-f]+)', text, re.M)
        start, vram = int(m.group(1), 16), int(m.group(2), 16)
        out[src.name] = Target(src.name, config, ROOT / _value(text, 'target_path'), vram - start,
                               ROOT / _value(text, 'elf_path'), ROOT / _value(text, 'asm_path') / 'nonmatchings',
                               src)
    return out


def get(name):
    return all_targets()[name]


def of_source(path):
    """The target a file of src/ belongs to."""
    rel = Path(path).resolve().relative_to(ROOT / 'src')
    return get(rel.parts[0])
