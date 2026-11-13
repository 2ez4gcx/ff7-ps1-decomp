#include "common.h"
#include "main/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
extern s32 D_8019D5E8;
extern s32 D_8019DAA0;
void func_800A3278(void);
void func_800B6D6C(void);
extern u16 D_800F83C6[];
s32 D_800A00CC();
s32 D_800A1158();
s32 func_80017108();
extern s32 D_80062E40;
extern struct { s16 id; s16 qty; u16 flag; } D_8009D808[];
extern struct { s8 a; s8 pad[0xF]; } D_801636B8[];
extern struct { s16 a; s8 pad[0xE]; } D_80163658[];

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80013C9C);

void func_800140A4(void) {
    s32 temp_v0;

    temp_v0 = D_8019DAA0 + 1;
    D_8019DAA0 = temp_v0;
    if (!(temp_v0 & 1)) {
        func_8004433C(D_8019D5E8);
        func_80013C9C();
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_800140F4);

s32 func_800144D8(s32 i) {
    return D_80048D84[i].first;
}

void func_800144F0(s32 a) {
    func_80033DAC(a, 0);
}

void func_80014510(s32 i) {
    func_800144F0(D_80048D84[i].first);
}

void func_80014540(void) {
    func_80033E34(D_80071744, D_80095DD8, D_800722C8, 0);
}

s32 func_80014578(s32 arg0, s32 arg1, s32 arg2) {
    return func_80033E34(D_80048D84[arg0].first, D_80048D84[arg0].second, arg1, arg2);
}

void func_800145BC(M2C_UNK (*arg0)()) {
loop_1:
    if (func_80034B44() != 0) {
        if (arg0 != NULL) {
            arg0();
        }
        goto loop_1;
    }
}

void func_80014608(void) {
}

void func_80014610(void) {
    s32 buf[0x200];

    func_80033E34(0x266, 0x800, (s32) buf, 0);
    func_800145BC(NULL);
    func_80014A00((s32 *) D_80048D84, buf, 0x50);
}

void func_80014658(s32 arg0, M2C_UNK (*arg1)()) {
    func_80014578(arg0, 0x801B0000, 0);
    func_800145BC(NULL);
    func_80015CA0(0x801B0000, 0x800A0000);
    arg1();
}

void func_800146A4(s32 arg0) {
    s32 loop;

    loop = -1;
    do {
        switch (D_8009C560) {
        case 4:
            func_800145BC(NULL);
            func_80014658(3, D_800A00CC);
            break;
        case 2:
            func_800140F4();
            func_80014658(5, D_800A1158);
            break;
        default:
            loop = 0;
            break;
        }
    } while (loop != 0);
}

void func_80014750(void) {
    s32 end;
    s32 op;
    s32 arg;

    func_80015B44(0x801B0000);
    end = 0xFFFF;
    while ((op = func_80015B50() & 0xFFFF) != end) {
        arg = func_80015B88() & 0xFFFF;
        if (op == 9) {
            func_80015BC0(func_80014C80(arg));
        } else if (D_80048DD4[op] != 0) {
            func_80015BC0(D_80048DD4[op]);
        }
    }
}

void func_80014804(void) {
    s32 op;

    func_80015B44(0x801B0000);
    while ((op = func_80015B50() & 0xFFFF) != 0xFFFF) {
        switch (op) {
        case 0:
            func_80015BC0(0x801C0000);
            func_800149E0();
            func_80014980((void *)0x801C0000);
            break;
        case 1:
            func_80015BC0((s32)D_80063048);
            break;
        }
    }
}

void func_800148A0(void) {
    D_80062F88 = 0;
    D_800707BE[0] = 0;
}

s32 func_800148B4(void) {
    func_800148A0();
    D_80063014 = 0x1F800000;
    D_800707C0 = D_80063048;
    func_80014610();
    func_80014C70();
    func_80014578(1, 0x801B0000, (s32) func_80014804);
    func_800145BC(NULL);
    func_80014578(2, 0x801B0000, (s32) func_80014750);
    func_800145BC(NULL);
    return 1;
}

void func_80014934(void) {
    func_800148A0();
    func_80014578(2, 0x801B0000, 0);
    func_800145BC(NULL);
    func_80015C3C(0x801B0000, &D_8009C738, 3);
}

void func_80014980(void *arg0) {
    void *var_s0;

    var_s0 = arg0;
    if (M2C_FIELD(var_s0, s32 *, 4) & 8) {
        func_80044000(var_s0 + 0xC, var_s0 + 0x14);
        var_s0 += ((u32) M2C_FIELD(var_s0, u32 *, 8) >> 2) * 4;
    }
    func_80044000(var_s0 + 0xC, var_s0 + 0x14);
}

void func_800149E0(void) {
    func_80043DD8(0);
}

void func_80014A00(s32 *dst, s32 *src, s32 len) {
    s32 i;

    len >>= 2;
    for (i = 0; i < len; i++) {
        *dst++ = *src++;
    }
}

/* The number of the highest set bit of x (0 for 0 and 1). */
s32 func_80014A38(u32 x) {
    s32 n = 0;
    while (1) {
        x >>= 1;
        if (x == 0) {
            break;
        }
        n++;
    }
    return n;
}

s32 func_80014A58(u32 arg0) {
    s32 var_v1;
    u32 var_a0;

    var_a0 = arg0;
    var_v1 = 0;
    if (var_a0 != 0) {
        do {
            if (var_a0 & 1) {
                var_v1 += 1;
            }
            var_a0 = var_a0 >> 1;
        } while (var_a0 != 0);
    }
    return var_v1;
}

s32 func_80014A84(s32 mask) {
    s32 n;
    s32 bit;

    bit = 0;
    n = func_80014A58(mask);
    if (n != 0) {
        bit = 1;
        n = (func_80014B70() * n) >> 8;
        for (; bit != 0; bit <<= 1) {
            if (mask & bit) {
                if (--n < 0) {
                    break;
                }
            }
        }
    }
    return bit;
}

u32 func_80014B08(u32 arg0, u32 arg1, u32 arg2, s32 arg3) {
    u32 old;

    old = arg0;
    if (arg3 != 0) {
        arg0 += arg1;
        if (arg0 < old) {
            arg0 = arg2;
        }
        if (arg2 < arg0) {
            arg0 = arg2;
        }
    } else {
        arg0 -= arg1;
        if (old < arg0) {
            arg0 = 0;
        }
    }
    return arg0;
}

void func_80014B54(void) {
    D_80062E18 = (D_80062E18 + 1) & 7;
}

s32 func_80014B70(void) {
    u8 *p;

    p = D_80062E10 + D_80062E18;
    return D_80083084[(*p)++];
}

s32 func_80014BA8(s32 arg0) {
    return ((s32) ((func_80014B70() & 0xFF) * arg0) >> 8) & 0xFF;
}

s32 func_80014BE4(void) {
    s32 a;
    s32 n;
    s32 t;

    a = func_80014B70();
    n = D_80062D4C & 7;
    D_80062D4C += 1;
    if (n != 0) {
        func_80014B54();
    }
    t = (func_80014B70() & 0xFF) << 8;
    return (a & 0xFF) | t;
}

void func_80014C44(s32 arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        D_80062E10[i] = arg0;
        arg0 >>= 1;
    }
    D_80062E18 = 0;
}

void func_80014C70(void) {
    D_80062E1C = 0;
    D_80062E20 = 0;
}

u8 *func_80014C80(s32 arg0) {
    s32 idx;
    s32 off;

    idx = D_80062E1C++;
    off = D_80062E20;
    D_80069490[idx] = off;
    D_80062E20 = off + arg0;
    return &D_80063690[off];
}

INCLUDE_RODATA("../asm/us/main/nonmatchings/text2", D_80010100);

s32 func_80014CBC(s32 arg0, s32 arg1) {
    u8 v;
    s32 r;

    v = 0xFF;
    r = -1;
    switch (arg0) {
    case 0:
    case 1:
    case 2:
        v = D_800708D4[D_80010100[arg0] + arg1].b;
        break;
    case 4:
        if (arg1 < 0x80) {
            v = D_800722DC[arg1].b;
        }
        break;
    }
    if (v != 0xFF) {
        r = v;
    }
    return r;
}

u8 *func_80014D58(u8 *dst, u8 *src, s32 n) {
    u8 c;

    c = *src;
    while (c != 0xFF) {
        *dst = c;
        src++;
        n--;
        dst++;
        if (n == -1) {
            break;
        }
        c = *src;
    }
    return dst;
}

s32 func_80014D9C(s32 arg0, s32 arg1, s32 arg2) {
    u8 *p;

    p = D_80063690 + D_80069490[arg0 + arg2];
    return (s32)(p + ((u16 *)p)[arg1]);
}

void func_80014DD0(s32 arg0, s32 arg1, M2C_UNK arg2) {
    func_80014D58(arg2, func_80014D9C(arg0, arg1, 0), -1);
}

u8 *func_80014E0C(s32 arg0, u8 *arg1) {
    s32 i;

    for (i = 0; i < 9; i++) {
        if (D_8009C738[i][0] == arg0) {
            arg1 = func_80014D58(arg1, D_8009C748[i], 0xC);
            break;
        }
    }
    return arg1;
}

INCLUDE_RODATA("../asm/us/main/nonmatchings/text2", D_80010118);

INCLUDE_RODATA("../asm/us/main/nonmatchings/text2", D_80010120);

INCLUDE_RODATA("../asm/us/main/nonmatchings/text2", D_80010124);

u8 *func_80014E74(u8 *arg0, u8 *arg1_) {
    u8 *p;
    u8 c;
    s32 new_var;
    s16 v;
    s32 n;
    u8 *arg1;
    u32 buf[16];
    u32 *bp;
    s32 hi;
    s32 lo;

    p = arg0;
    bp = buf;
    arg1 = arg1_;
    loop:
    {
        c = *(arg1++);
        if (((u8)(c + 0x16)) < 8) {
            hi = *(arg1++);
            lo = *(arg1++);
            v = lo | (hi << 8);
            switch (c) {
            case 0xEA:
                p = func_80014E0C(v & 0xFFFF, p);
                break;
            case 0xEB:
                p = func_80014D58(p, (u8 *)func_80015248(4, new_var = v & 0xFFFF, 8), -1);
                break;
            case 0xEC:
                n = 0;
                do {
                    bp[n] = (u16)(((u16)v) % 10);
                    v = ((u16)v) / 10;
                    n++;
                } while ((hi = ((u16)v) != 0) && (n < 16U));
                while (n > 0) {
                    *(p++) = bp[n - 1] + D_800FAFD0;
                    n--;
                }
                break;
            case 0xED:
                if (((u16)v) < 3) {
                    p = func_80014E0C(D_801636B8[(u16)v].a, p);
                } else if (((u16)v) >= 4) {
                    p = func_80014D58(p, (u8 *)(&D_800F5F44[D_80163658[((u16)v) - 4].a]), 0x20);
                }
                break;
            case 0xEE:
                p = ((u8 *(*)(s32, s32, u8 *)) func_80014DD0)(9, v & 0xFFFF, p);
                break;
            case 0xEF:
                if (((u16)v) < 0x1A) {
                    *(p++) = v + D_800F7ED0;
                }
                break;
            case 0xF0:
                p = ((u8 *(*)(s32, s32, u8 *)) func_80014DD0)(0x10, v & 0xFFFF, p);
                break;
            case 0xF1:
                p = ((u8 *(*)(s32, s32, u8 *)) func_80014DD0)(((u16)v) >> 8, v & 0xFF, p);
                break;
            }
        } else {
            *(p++) = c;
            if (c == 0xF9) {
                *(p++) = *(arg1++);
                do { } while (0);
            }
        }
    }
    if (c != 0xFF) {
        goto loop;
    }
    return arg0;
}

u8 *func_800150E4(u8 *arg0, u8 *arg1) {
    u32 n;
    s32 m;
    u8 c;
    s32 len;
    s32 i;
    s32 off;

    n = 0;
    m = 0;
    do {
        c = *arg0++;
        m++;
        if (c == 0xF9) {
            c = *arg0++;
            m++;
            off = m - 3;
            off -= c & 0x3F;
            len = (c >> 6) * 2 + 4;
            for (i = 0; i < len; i++) {
                c = arg1[off++];
                D_80063560[n++] = c;
            }
        } else if ((u8) (c + 0x16) < 8) {
            D_80063560[n++] = c;
            m++;
            D_80063560[n++] = *arg0++;
            m++;
            D_80063560[n++] = *arg0++;
        } else {
            D_80063560[n++] = c;
        }
    } while (c != 0xFF && n < 0x100);
    return D_80063560;
}

s32 func_800151F4(s32 arg0) {
    return func_80014D9C(0x10, arg0, 0);
}

void func_8001521C(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_800151F4(arg0);
    func_800150E4(temp_v0, temp_v0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80015248);

void func_800155A4(s32 arg0) {
    D_80062F14 = arg0;
}

void func_800155B0(void) {
    if (D_80062F14 >= 0 && !(D_800F83C6[0] & 8)) {
        D_80062F14 |= 0x100;
        D_80062F60 = 0;
        while (D_80062D88 != 0x10C) {
            func_800A3278();
            func_800B6D6C();
        }
        D_800F83C6[0] |= 8;
    }
}

void func_80015654(s32 a) {
    D_80062E24 = 0;
    D_80062E28 = 0;
    D_80062E2C = a;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80015668);

void func_800159B0(void) {
    s32 i;
    s32 j;
    s32 free;
    s16 id;
    s32 qty;
    u16 v;
    u16 *items;
    u32 *mat;

    for (i = 0; i < 4; i++) {
        items = D_8009CBE0;
        if (D_8009D808[i].flag != 0) {
            id = D_8009D808[i].id;
            if (id != -1) {
                qty = D_8009D808[i].qty;
                free = -1;
                if (id < 0x180) {
                    for (j = 0; j < 0x140; j++) {
                        v = items[j];
                        if ((v & 0x1FF) == id) {
                            qty += v >> 9;
                            if (qty > 0x63) {
                                qty = 0x63;
                            }
                            items[j] = id | (qty << 9);
                            break;
                        }
                        if (v == 0xFFFF && free == -1) {
                            free = j;
                        }
                    }
                    if (j == 0x140 && free != -1) {
                        items[free] = id | (qty << 9);
                    }
                } else {
                    for (j = 0; j < 0x100; j++) {
                        if (((u32 *)(D_8009CBE0 + 0x140))[j] == -1) {
                            qty--;
                            ((u32 *)(D_8009CBE0 + 0x140))[j] = id - 0x180;
                            if (qty == 0) {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

s32 func_80015AFC(u32 arg0, s32 arg1) {
    u8 pad[0x30];
    s32 v;
    u8 *p;

    v = 0x7F;
    if (arg0 < 9) {
        p = D_80082274[arg0];
        v = *(u8 *)(arg1 + (s32)p) - 0x80;
    }
    return v;
}

void func_80015B44(s32 arg0) {
    D_80062E30 = arg0;
}

s32 func_80015B50(void) {
    s32 var_a1;

    var_a1 = 0xFFFF;
    if ((M2C_FIELD(D_80062E30, u8 *, 0) | (M2C_FIELD(D_80062E30, u8 *, 1) << 8)) != 0) {
        var_a1 = M2C_FIELD(D_80062E30, u8 *, 4) | (M2C_FIELD(D_80062E30, u8 *, 5) << 8);
    }
    return var_a1;
}

s32 func_80015B88(void) {
    s32 var_a1;

    var_a1 = 0;
    if ((M2C_FIELD(D_80062E30, u8 *, 0) | (M2C_FIELD(D_80062E30, u8 *, 1) << 8)) != 0) {
        var_a1 = M2C_FIELD(D_80062E30, u8 *, 2) | (M2C_FIELD(D_80062E30, u8 *, 3) << 8);
    }
    return var_a1;
}

s32 func_80015BC0(s32 arg0) {
    u16 size;
    s32 ret;

    ret = -1;
    if ((size = D_80062E30[0] | (D_80062E30[1] << 8)) != 0) {
        ret = func_80017108(D_80062E30 + 6, arg0, ret);
        if (ret == (D_80062E30[2] | (D_80062E30[3] << 8))) {
            D_80062E30 += size + 6;
        }
    }
    return ret;
}

s32 func_80015C3C(u8 *arg0, s32 arg1, s32 arg2) {
    u16 size;
    s32 ret;

    ret = -1;
    while ((size = arg0[0] | (arg0[1] << 8)) != 0) {
        if ((arg0[4] | (arg0[5] << 8)) == arg2) {
            ret = func_80017108(arg0 + 6, arg1);
            break;
        }
        arg0 += size + 6;
    }
    return ret;
}

void func_80015CA0(s32 arg0, s32 arg1) {
    u32 *q;
    s32 i;
    s32 n;
    u32 off;

    n = *(u32 *)(arg0 + 4);
    off = *(u32 *)arg0;
    func_80017108(arg0 + 8);
    n = (u32)n >> 2;
    q = (u32 *)arg1 + (off >> 2);
    for (i = 0; i < n; i++) {
        q[i] = 0;
    }
}

s32 func_80015D14(u32 arg0) {
    u32 cur;
    u32 end;
    s32 r;

    cur = D_80062D54;
    end = cur + ((arg0 + 3) >> 2);
    if (end < 0x1001U) {
        D_80062D54 = end;
        r = D_80062E44 + (cur * 4);
    } else {
        D_80062D54 = 0;
        r = func_80015D14(arg0);
    }
    return r;
}

s32 func_80015D64(s32 *arg0, s32 arg1, s32 arg2, M2C_UNK *arg3, M2C_UNK *arg4, void **arg5, s32 *arg6) {
    u32 c[17];
    MainHuft r;
    MainHuft *u[16];
    u32 v[288];
    u32 x[17];
    u32 a;
    u32 f;
    s32 g;
    s32 h;
    u32 i;
    u32 j;
    s32 k;
    s32 l;
    u32 *p;
    MainHuft *q;
    s32 w;
    u32 *xp;
    s32 y;
    u32 z;
    u32 n;
    u32 s;
    u16 *d;
    s32 m;

    n = arg1;
    s = arg2;
    d = (u16 *)arg3;
    for (m = 16; m >= 0; m--) {
        c[m] = 0;
    }
    p = (u32 *)arg0;
    i = n;
    do {
        c[*p]++;
        p++;
    } while (--i);
    if (c[0] == n) {
        *arg5 = NULL;
        *arg6 = 0;
        return 0;
    }
    l = *arg6;
    for (j = 1; j <= 16; j++) {
        if (c[j]) {
            break;
        }
    }
    k = j;
    if ((u32)l < j) {
        l = j;
    }
    for (i = 16; i; i--) {
        if (c[i]) {
            break;
        }
    }
    g = i;
    if ((u32)l > i) {
        l = i;
    }
    *arg6 = l;
    for (y = 1 << j; j < i; j++, y <<= 1) {
        if ((y -= c[j]) < 0) {
            return 2;
        }
    }
    if ((y -= c[i]) < 0) {
        return 2;
    }
    c[i] += y;
    x[1] = j = 0;
    p = c + 1;
    xp = x + 2;
    while (--i) {
        *xp++ = (j += *p++);
    }
    p = (u32 *)arg0;
    i = 0;
    do {
        if ((j = *p++) != 0) {
            v[x[j]++] = i;
        }
    } while (++i < n);
    x[0] = i = 0;
    p = v;
    h = -1;
    w = -l;
    u[0] = NULL;
    q = NULL;
    z = 0;
    for (; k <= g; k++) {
        a = c[k];
        while (a--) {
            while (k > w + l) {
                h++;
                w += l;
                z = g - w;
                z = z > (u32)l ? l : z;
                if ((f = 1 << (j = k - w)) > a + 1) {
                    f -= a + 1;
                    xp = c + k;
                    while (++j < z) {
                        if ((f <<= 1) <= *++xp) {
                            break;
                        }
                        f -= *xp;
                    }
                }
                z = 1 << j;
                if ((q = (MainHuft *)func_80015D14((z + 1) * sizeof(MainHuft))) == NULL) {
                    if (h) {
                        func_80016320(u[0]);
                    }
                    return 3;
                }
                D_80062E50 += z + 1;
                *arg5 = q + 1;
                *(arg5 = (void **)&q->v.t) = NULL;
                u[h] = ++q;
                if (h) {
                    x[h] = i;
                    r.b = l;
                    r.e = j + 16;
                    r.v.t = q;
                    j = i >> (w - l);
                    u[h - 1][j] = r;
                }
            }
            r.b = k - w;
            if (p >= v + n) {
                r.e = 99;
            } else if (*p < s) {
                r.e = (*p < 256 ? 16 : 15);
                r.v.n = *p++;
            } else {
                r.e = ((u16 *)arg4)[*p - s];
                r.v.n = d[*p++ - s];
            }
            f = 1 << (k - w);
            for (j = i >> w; j < z; j += f) {
                q[j] = r;
            }
            for (j = 1 << (k - 1); i & j; j >>= 1) {
                i ^= j;
            }
            i ^= j;
            while ((i & ((1 << w) - 1)) != x[h]) {
                h--;
                w -= l;
            }
        }
    }
    return y != 0 && g != 1;
}

s32 func_80016320(void *arg0) {
    void *var_a0;

    var_a0 = arg0;
    if (var_a0 != NULL) {
        do {
            var_a0 = M2C_FIELD(var_a0, void **, -4);
        } while (var_a0 != NULL);
    }
    return 0;
}

s32 func_80016340(MainHuft *tl, MainHuft *td, s32 bl, s32 bd) {
    u32 e;
    u32 n;
    u32 d;
    s32 w;
    MainHuft *t;
    u32 ml;
    u32 md;
    u32 b;
    u32 k;

    b = D_80062E48;
    k = D_80062E4C;
    w = D_80062E34;
    ml = D_80048F3C[bl];
    md = D_80048F3C[bd];
    while (1) {
        while (k < bl) {
            b |= D_80062E3C[D_80062E38++] << k;
            k += 8;
        }
        t = tl + (b & ml);
        e = t->e;
        if (e > 16) {
            do {
                if (e == 99) {
                    return 1;
                }
                b >>= t->b;
                k -= t->b;
                e -= 16;
                while (k < e) {
                    b |= D_80062E3C[D_80062E38++] << k;
                    k += 8;
                }
                t = t->v.t + (b & D_80048F3C[e]);
                e = t->e;
            } while (e > 16);
        }
        b >>= t->b;
        k -= t->b;
        if (e == 16) {
            *(u8 *) (D_80062E40 + w++) = t->v.n;
            continue;
        }
        if (e == 15) {
            break;
        }
        while (k < e) {
            b |= D_80062E3C[D_80062E38++] << k;
            k += 8;
        }
        n = t->v.n + (b & D_80048F3C[e]);
        b >>= e;
        k -= e;
        while (k < bd) {
            b |= D_80062E3C[D_80062E38++] << k;
            k += 8;
        }
        t = td + (b & md);
        e = t->e;
        if (e > 16) {
            do {
                if (e == 99) {
                    return 1;
                }
                b >>= t->b;
                k -= t->b;
                e -= 16;
                while (k < e) {
                    b |= D_80062E3C[D_80062E38++] << k;
                    k += 8;
                }
                t = t->v.t + (b & D_80048F3C[e]);
                e = t->e;
            } while (e > 16);
        }
        b >>= t->b;
        k -= t->b;
        while (k < e) {
            b |= D_80062E3C[D_80062E38++] << k;
            k += 8;
        }
        d = w - t->v.n - (b & D_80048F3C[e]);
        b >>= e;
        k -= e;
        e = n;
        if (n != 0) {
            do {
                *(u8 *) (D_80062E40 + w++) = *(u8 *) (D_80062E40 + d++);
                e--;
            } while (e != 0);
        }
        n = 0; /* keeps n, not its copy e, as the guard register (cse) */
    }
    D_80062E34 = w;
    D_80062E48 = b;
    D_80062E4C = k;
    return 0;
}

s32 func_800166C0(void) {
    u32 b;
    u32 k;
    s32 n;
    s32 w;
    s32 ret;

    b = D_80062E48;
    k = D_80062E4C;
    w = D_80062E34;
    n = k & 7;
    b >>= n;
    k -= n;
    while (k < 16) {
        b |= D_80062E3C[D_80062E38++] << k;
        k += 8;
    }
    n = b & 0xFFFF;
    b >>= 16;
    k -= 16;
    while (k < 16) {
        b |= D_80062E3C[D_80062E38++] << k;
        k += 8;
    }
    if (n == (~b & 0xFFFF)) {
        b >>= 16;
        n--;
        k -= 16;
        while (n != -1) {
            while (k < 8) {
                b |= D_80062E3C[D_80062E38++] << k;
                k += 8;
            }
            k -= 8;
            n--;
            *(u8 *)(D_80062E40 + w++) = b;
            b >>= 8;
        }
        ret = 0;
        *(volatile s32 *)&D_80062E34 = w;
        *(volatile s32 *)&D_80062E48 = b;
        *(volatile u32 *)&D_80062E4C = k;
        return ret;
    }
    return 1;
}

s32 func_80016808(void) {
    s32 i;
    s32 l[288];
    void *tl;
    s32 bl;
    void *td;
    s32 bd;

    for (i = 0; i < 144; i++) {
        l[i] = 8;
    }
    for (; i < 256; i++) {
        l[i] = 9;
    }
    for (; i < 280; i++) {
        l[i] = 7;
    }
    for (; i < 288; i++) {
        l[i] = 8;
    }
    bl = 7;
    i = func_80015D64(l, 0x120, 0x101, &D_80048E44, &D_80048E84, &tl, &bl);
    if (i != 0) {
        return i;
    }
    for (i = 0; i < 30; i++) {
        l[i] = 5;
    }
    bd = 5;
    i = func_80015D64(l, 0x1E, 0, &D_80048EC4, &D_80048F00, &td, &bd);
    if (i > 1) {
        func_80016320(tl);
        return i;
    }
    if (func_80016340(tl, td, bl, bd) != 0) {
        return 1;
    }
    func_80016320(tl);
    func_80016320(td);
    return 0;
}

s32 func_800169B8(void) {
    s32 i;
    u32 j;
    u32 l;
    u32 m;
    u32 n;
    MainHuft *tl;
    MainHuft *td;
    s32 bl;
    s32 bd;
    u32 nb;
    u32 nl;
    u32 nd;
    u32 ll[316];
    u32 b;
    u32 k;

    b = D_80062E48;
    k = D_80062E4C;
    while (k < 5) {
        b |= D_80062E3C[D_80062E38++] << k;
        k += 8;
    }
    nl = 257 + (b & 0x1F);
    b >>= 5;
    k -= 5;
    while (k < 5) {
        b |= D_80062E3C[D_80062E38++] << k;
        k += 8;
    }
    nd = 1 + (b & 0x1F);
    b >>= 5;
    k -= 5;
    while (k < 4) {
        b |= D_80062E3C[D_80062E38++] << k;
        k += 8;
    }
    nb = 4 + (b & 0xF);
    b >>= 4;
    k -= 4;
    if (nl > 286 || nd > 30) {
        return 1;
    }
    for (j = 0; j < nb; j++) {
        while (k < 3) {
            b |= D_80062E3C[D_80062E38++] << k;
            k += 8;
        }
        ll[D_80048DF8[j]] = b & 7;
        b >>= 3;
        k -= 3;
    }
    for (; j < 19; j++) {
        ll[D_80048DF8[j]] = 0;
    }
    bl = 7;
    if ((i = func_80015D64(ll, 19, 19, NULL, NULL, &tl, &bl)) != 0) {
        if (i == 1) {
            func_80016320(tl);
        }
        return i;
    }
    n = nl + nd;
    m = D_80048F3C[bl];
    i = l = 0;
    while ((u32)i < n) {
        while (k < bl) {
            b |= D_80062E3C[D_80062E38++] << k;
            k += 8;
        }
        td = tl + (b & m);
        j = td->b;
        b >>= j;
        k -= j;
        j = td->v.n;
        if (j < 16) {
            ll[i++] = l = j;
        } else if (j == 16) {
            while (k < 2) {
                b |= D_80062E3C[D_80062E38++] << k;
                k += 8;
            }
            j = 3 + (b & 3);
            b >>= 2;
            k -= 2;
            if ((u32)i + j > n) {
                return 1;
            }
            while (j--) {
                ll[i++] = l;
            }
        } else if (j == 17) {
            while (k < 3) {
                b |= D_80062E3C[D_80062E38++] << k;
                k += 8;
            }
            j = 3 + (b & 7);
            b >>= 3;
            k -= 3;
            if ((u32)i + j > n) {
                return 1;
            }
            while (j--) {
                ll[i++] = 0;
            }
            l = 0;
        } else {
            while (k < 7) {
                b |= D_80062E3C[D_80062E38++] << k;
                k += 8;
            }
            j = 11 + (b & 0x7F);
            b >>= 7;
            k -= 7;
            if ((u32)i + j > n) {
                return 1;
            }
            while (j--) {
                ll[i++] = 0;
            }
            l = 0;
        }
    }
    func_80016320(tl);
    D_80062E48 = b;
    D_80062E4C = k;
    bl = D_80062D58;
    if ((i = func_80015D64(ll, nl, 0x101, &D_80048E44, &D_80048E84, &tl, &bl)) != 0) {
        if (i == 1) {
            return -1;
        }
        return i;
    }
    bd = D_80062D5C;
    if ((i = func_80015D64(ll + nl, nd, 0, &D_80048EC4, &D_80048F00, &td, &bd)) != 0) {
        if (i == 1) {
            return -1;
        }
        func_80016320(tl);
        return i;
    }
    if (func_80016340(tl, td, bl, bd) != 0) {
        return 1;
    }
    func_80016320(tl);
    func_80016320(td);
    return 0;
}
