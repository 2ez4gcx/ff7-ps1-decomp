#include "common.h"
#include "main/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
M2C_UNK func_80043F6C(Rect16 *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_80038FB8(s32 arg0);
s32 func_80042C98(s32 arg0);
M2C_UNK func_80042D98();
s32 func_80039A74(s32 arg0);
DispEnv *func_800438D4(DispEnv *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_80046794(MainTag *arg0, MainTag *arg1);
s32 func_80036FFC(s32 arg0, MainWords *arg1);
void func_80039644(s32 arg0);
void func_800396C0(s32 arg0);
M2C_UNK func_80042DC8();
s32 func_80039B40(s32 arg0);
void func_80039BE0(s32 arg0, s32 arg1, s32 arg2);
s32 func_8003CC1C(s32 arg0, s32 arg1);

void func_80036298(void) {
    func_800362B8(0);
}

void func_800362B8(s32 arg0) {
    u16 *p;
    s32 i;
    u16 c;

    func_8003D0C0();
    func_8003642C(arg0);
    if (arg0 == 0) {
        c = 0xC000;
        i = 0x17;
        p = &D_8004A6EA;
        do {
            *p = c;
            i -= 1;
            p -= 1;
        } while (i >= 0);
    }
    func_800363B0();
    D_8004A694 = 0;
    D_8004A698 = 0;
    D_8004A6A4 = 0;
    D_8004A6A8 = 0;
    D_8004A6AA = 0;
    D_8004A6AC = 0;
    D_8004A6B0 = 0;
    D_8004A69C = D_8004AB5C;
    func_80036D98(0xD1, D_8004AB5C, 0);
    D_8004AB50 = 0;
    D_8004AB54 = 0;
    D_8004AB58 = NULL;
    D_8004A690 = 0;
    D_8004AB10 = 0;
    D_8004A68C = 0;
    D_8004A6B8 = 0;
    D_8004A6B4 = 0;
    D_8004AAEC = 0;
}

void func_800363B0(void) {
    s32 temp_v0;

    if (D_8004AAF0 == 0) {
        D_8004AAF0 = 1;
        func_80042AF0();
        func_80036FD8((s32) &func_8003688C);
        temp_v0 = func_80042A00(0xF0000009, 0x20, 0x2000, 0);
        D_8004A688 = temp_v0;
        func_80042A40(temp_v0);
        func_80042B00();
    }
}

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib", D_800104B4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003642C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800366C0);

void func_8003688C(void) {
    u32 i;

    if (D_8004AB44 == 0) {
        func_80036F78();
        func_80036F78();
        func_80036F78();
    }
    D_8004AAF4[0xD5] &= 0xFFCF;
    i = 0;
    while (D_8004AAF4[0xD5] & 0x30) {
        i++;
        if (i > 0xF00) {
            break;
        }
    }
    if (D_8004AB2C != 0) {
        ((void (*)(void)) D_8004AB2C)();
    } else {
        func_800429F0(0xF0000009, 0x20);
    }
}

void func_8003695C(s32 arg0, s32 arg1, s32 arg2) {
    D_8004AAF4[0xD3] = arg1;
    func_80036F78();
    func_80036F78();
    D_8004AAF4[0xD5] |= 0x30;
    func_80036F78();
    func_80036F78();
    func_80036F4C();
    *D_8004AAF8 = arg0;
    *D_8004AAFC = (arg2 << 0x10) | 0x10;
    D_8004AB44 = 1;
    *D_8004AB00 = 0x01000200;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80036A18);

s32 func_80036CA8(s32 arg0, s32 arg1) {
    if (D_8004AB10 == 0) {
        func_80036A18(2, D_8004AB0C << D_8004AB1C);
        func_80036A18(1);
        func_80036A18(3, arg0, arg1);
    } else {
        func_800366C0(arg0, arg1);
    }
    return arg1;
}

s32 func_80036D30(s32 arg0, s32 arg1) {
    func_80036A18(2, D_8004AB0C << D_8004AB1C);
    func_80036A18(0);
    func_80036A18(3, arg0, arg1);
    return arg1;
}

void func_80036D98(s32 arg0, u32 arg1, s32 arg2) {
    if (arg2 == 0) {
        D_8004AAF4[arg0] = arg1;
    } else {
        D_8004AAF4[arg0] = arg1 >> D_8004AB1C;
    }
}

s32 func_80036DE0(arg0, arg1) {
    u32 temp_a3;

    if ((D_8004AB18 != 0) && (((u32) arg1 % D_8004AB20) != 0)) {
        arg1 += D_8004AB20;
        arg1 &= ~D_8004AB24;
    }
    temp_a3 = (u32) arg1 >> D_8004AB1C;
    switch (arg0) {
    case -1:
        return temp_a3 & 0xFFFF;
    case -2:
        return arg1;
    default:
        D_8004AAF4[arg0] = temp_a3;
        return arg1;
    }
}

s32 func_80036E84(s32 arg0, s32 arg1) {
    u16 t;

    t = D_8004AAF4[arg0];
    if (arg1 == -1) {
        return t;
    }
    return t << D_8004AB1C;
}

void func_80036EC0(s32 arg0) {
    *D_8004AB04 &= 0xFFF8FFFF;
    if (arg0 != 0) {
        *D_8004AB04 |= 0x30000;
    } else {
        *D_8004AB04 |= 0x50000;
    }
}

void func_80036F20(void) {
    *D_8004AB08 = (*D_8004AB08 & 0xF0FFFFFF) | 0x20000000;
}

void func_80036F4C(void) {
    *D_8004AB08 = (*D_8004AB08 & 0xF0FFFFFF) | 0x22000000;
}

void func_80036F78(void) {
    volatile s32 i;
    volatile s32 a;

    a = 0xD;
    for (i = 0; i < 0xF0; i++) {
        a *= 3;
    }
}

void func_80036FD8(s32 arg0) {
    func_8003D120(4, arg0);
}

s32 func_80036FFC(s32 arg0, MainWords *arg1) {
    if (arg0 > 0) {
        arg1->w0 = 0x40001010;
        D_8004AB58 = arg1;
        D_8004AB54 = 0;
        D_8004AB50 = arg0;
        arg1->w4 = (0x10000 << D_8004AB1C) - 0x1010;
        return arg0;
    }
    return 0;
}

s32 func_80037050(s32 arg0, s32 arg1, s32 arg2) {
    s32 w;
    s32 len;
    s32 off;
    s32 pad;
    s32 rem;
    s32 n;
    u32 addr;

    w = D_8004AB58[arg0].w0;
    addr = arg1;
    len = D_8004AB58[arg0].w4;
    off = addr - (w & 0x0FFFFFFF);
    if (D_8004A698 == 0) {
        pad = 0;
    } else {
        pad = (0x10000 - D_8004A69C) << D_8004AB1C;
    }
    if (w & 0x40000000) {
        rem = len - off - pad;
    } else {
        rem = len - off;
    }
    if (rem < arg2) {
        return -1;
    }
    if (w & 0x40000000) {
        if (off > 0) {
            s32 m;

            m = D_8004AB54;
            if (D_8004AB50 - 2 < m) {
                return -1;
            }
            D_8004AB54 = m + 1;
            D_8004AB58[m].w4 = off;
            D_8004AB58[m].w0 = (D_8004AB58[m].w0 & 0x0FFFFFFF) | 0x80000000;
            D_8004AB58[D_8004AB54].w0 = addr;
            D_8004AB58[D_8004AB54].w4 = arg2;
        } else {
            s32 m;

            m = D_8004AB54;
            if (D_8004AB50 - 1 < m) {
                return -1;
            }
            D_8004AB58[m].w4 = arg2;
            D_8004AB58[m].w0 &= 0x0FFFFFFF;
        }
        D_8004AB54 += 1;
        D_8004AB58[D_8004AB54].w0 = ((w & 0x0FFFFFFF) + off + arg2) | 0x40000000;
        D_8004AB58[D_8004AB54].w4 = len - off - arg2;
    } else if (off > 0) {
        MainWords *p;
        s32 a;
        s32 b;

        if (rem == arg2) {
            if (D_8004AB50 - 2 < D_8004AB54) {
                return -1;
            }
        } else {
            if (D_8004AB50 - 1 < D_8004AB54) {
                return -1;
            }
        }
        D_8004AB58[arg0].w4 = off;
        n = D_8004AB54;
        p = &D_8004AB58[n];
        a = p->w0;
        b = p->w4;
        p->w0 = addr;
        p->w4 = arg2;
        D_8004AB54 = n + 1;
        p[1].w0 = a;
        p[1].w4 = b;
        if (rem >= arg2) {
            MainWords *q;
            s32 c;
            s32 d;

            q = &D_8004AB58[D_8004AB54];
            c = q->w0;
            d = q->w4;
            q->w0 = ((w & 0x0FFFFFFF) + off + arg2) | 0x80000000;
            q->w4 = rem - arg2;
            D_8004AB54 += 1;
            q[1].w0 = c;
            q[1].w4 = d;
        }
    } else {
        if (arg2 < rem) {
            if (D_8004AB50 - 1 < D_8004AB54) {
                return -1;
            }
        }
        D_8004AB58[arg0].w4 = arg2;
        D_8004AB58[arg0].w0 &= 0x0FFFFFFF;
        if (arg2 < rem) {
            MainWords *p;
            s32 a;
            s32 b;
            s32 m;

            m = D_8004AB54;
            p = &D_8004AB58[m];
            a = p->w0;
            b = p->w4;
            p->w0 = ((w & 0x0FFFFFFF) + arg2) | 0x80000000;
            p->w4 = rem - arg2;
            D_8004AB54 = m + 1;
            p[1].w0 = a;
            p[1].w4 = b;
        }
    }
    func_80037664();
    return addr;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800373AC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80037664);

void func_80037964(s32 arg0, s32 arg1) {
    func_80037988(arg0, arg1, 0xCA, 0xCB);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80037988);

s32 func_80037B90(s32 arg0) {
    s32 v;

    if (arg0 < 0) {
        v = 0;
    } else {
        v = arg0;
        if (v >= 0x40) {
            v = 0x3F;
        }
    }
    D_8004AAF4[0xD5] = (D_8004AAF4[0xD5] & 0xC0FF) | ((v & 0x3F) << 8);
    return v;
}

s32 func_80037BE0(s32 arg0, s32 arg1) {
    s32 var_s0;

    var_s0 = arg1;
    if ((u32) var_s0 > 0x7EFF0U) {
        var_s0 = 0x7EFF0;
    }
    func_80036D30(arg0, var_s0);
    if (D_8004AB2C == 0) {
        D_8004AB28 = 0;
    }
    return var_s0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80037C40);

s32 func_80037D10(u32 arg0) {
    MainWords *p;
    u32 w;
    u32 start;
    u32 m1;
    u32 m2;
    u32 m3;

    if (D_8004AB58 == 0) {
        return 0;
    }
    m1 = 0x80000000;
    m2 = 0x40000000;
    m3 = 0x0FFFFFFF;
    p = D_8004AB58;
    while (1) {
        w = p->w0;
        if (!(w & m1)) {
            if (w & m2) {
                break;
            }
            start = w & m3;
            if (start >= arg0) {
                return 1;
            }
            if (arg0 < start + p->w4) {
                return 1;
            }
        }
        p++;
    }
    return 0;
}

s32 func_80037D90(u32 arg0) {
    MainWords *p;
    u32 w;
    u32 start;
    u32 m1;
    u32 m2;
    u32 m3;

    arg0 <<= D_8004AB1C;
    if (D_8004AB58 == 0) {
        return 0;
    }
    m1 = 0x80000000;
    m2 = 0x40000000;
    m3 = 0x0FFFFFFF;
    p = D_8004AB58;
    while (1) {
        w = p->w0;
        if (!(w & m1)) {
            if (w & m2) {
                break;
            }
            start = w & m3;
            if (start >= arg0) {
                return 1;
            }
            if (arg0 < start + p->w4) {
                return 1;
            }
        }
        p++;
    }
    return 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80037E1C);

void func_8003832C(void *arg0) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0);
    temp_a2 = temp_a1 == 0;
    if ((temp_a2 != 0) || (temp_a1 & 1)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1C0) = (u16) M2C_FIELD(arg0, u16 *, 4);
    }
    if ((temp_a2 != 0) || (temp_a1 & 2)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1C2) = (u16) M2C_FIELD(arg0, u16 *, 6);
    }
    if ((temp_a2 != 0) || (temp_a1 & 4)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1C4) = (u16) M2C_FIELD(arg0, u16 *, 8);
    }
    if ((temp_a2 != 0) || (temp_a1 & 8)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1C6) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x10)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1C8) = (u16) M2C_FIELD(arg0, u16 *, 0xC);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x20)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1CA) = (u16) M2C_FIELD(arg0, u16 *, 0xE);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x40)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1CC) = (u16) M2C_FIELD(arg0, u16 *, 0x10);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x80)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1CE) = (u16) M2C_FIELD(arg0, u16 *, 0x12);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x100)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1D0) = (u16) M2C_FIELD(arg0, u16 *, 0x14);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x200)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1D2) = (u16) M2C_FIELD(arg0, u16 *, 0x16);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x400)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1D4) = (u16) M2C_FIELD(arg0, u16 *, 0x18);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x800)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1D6) = (u16) M2C_FIELD(arg0, u16 *, 0x1A);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x1000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1D8) = (u16) M2C_FIELD(arg0, u16 *, 0x1C);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x2000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1DA) = (u16) M2C_FIELD(arg0, u16 *, 0x1E);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x4000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1DC) = (u16) M2C_FIELD(arg0, u16 *, 0x20);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x8000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1DE) = (u16) M2C_FIELD(arg0, u16 *, 0x22);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x10000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1E0) = (u16) M2C_FIELD(arg0, u16 *, 0x24);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x20000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1E2) = (u16) M2C_FIELD(arg0, u16 *, 0x26);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x40000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1E4) = (u16) M2C_FIELD(arg0, u16 *, 0x28);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x80000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1E6) = (u16) M2C_FIELD(arg0, u16 *, 0x2A);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x100000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1E8) = (u16) M2C_FIELD(arg0, u16 *, 0x2C);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x200000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1EA) = (u16) M2C_FIELD(arg0, u16 *, 0x2E);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x400000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1EC) = (u16) M2C_FIELD(arg0, u16 *, 0x30);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x800000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1EE) = (u16) M2C_FIELD(arg0, u16 *, 0x32);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x01000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1F0) = (u16) M2C_FIELD(arg0, u16 *, 0x34);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x02000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1F2) = (u16) M2C_FIELD(arg0, u16 *, 0x36);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x04000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1F4) = (u16) M2C_FIELD(arg0, u16 *, 0x38);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x08000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1F6) = (u16) M2C_FIELD(arg0, u16 *, 0x3A);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x10000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1F8) = (u16) M2C_FIELD(arg0, u16 *, 0x3C);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x20000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1FA) = (u16) M2C_FIELD(arg0, u16 *, 0x3E);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x40000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1FC) = (u16) M2C_FIELD(arg0, u16 *, 0x40);
    }
    if ((temp_a2 != 0) || (temp_a1 < 0)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1FE) = (u16) M2C_FIELD(arg0, u16 *, 0x42);
    }
}

void func_800387FC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) D_8004A6A4;
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) D_8004A6AC;
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) D_8004A6B0;
    M2C_FIELD(arg0, u16 *, 8) = (u16) D_8004A6A8;
    M2C_FIELD(arg0, u16 *, 0xA) = (u16) D_8004A6AA;
}

s32 func_8003884C(void *arg0) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0);
    temp_a2 = temp_a1 == 0;
    if ((temp_a2 != 0) || (temp_a1 & 2)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x184) = (u16) M2C_FIELD(arg0, u16 *, 8);
        D_8004A6A8 = M2C_FIELD(arg0, u16 *, 8);
    }
    if ((temp_a2 != 0) || (temp_a1 & 4)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x186) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
        D_8004A6AA = M2C_FIELD(arg0, u16 *, 0xA);
    }
    return 0;
}

void func_800388C4(s32 arg0, s32 arg1) {
    func_80037988(arg0, arg1, 0xCC, 0xCD);
}

s32 func_800388E8(u32 arg0) {
    volatile s32 saved;
    s32 old;
    s32 changed;
    s32 more;
    u32 *p;
    u32 *b;
    u32 len;
    u32 addr;
    u32 n;
    u32 a;

    saved = 0;
    changed = 0;
    if (arg0 >= 10) {
        return -1;
    }
    b = &D_8004AB5C;
    p = b + arg0;
    if (func_80037D90(*p) != 0) {
        return -1;
    }
    if (arg0 == 0) {
        len = 0x10 << D_8004AB1C;
        addr = 0xFFF0 << D_8004AB1C;
    } else {
        a = *p;
        len = (0x10000 - a) << D_8004AB1C;
        addr = a << D_8004AB1C;
    }
    old = D_8004AB10;
    if (old == 1) {
        D_8004AB10 = 0;
        changed = 1;
    }
    more = 1;
    if (D_8004AB2C != 0) {
        saved = D_8004AB2C;
        D_8004AB2C = 0;
    }
    do {
        n = len;
        if (len >= 0x401) {
            n = 0x400;
        } else {
            more = 0;
        }
        func_80036A18(2, addr);
        func_80036A18(1);
        func_80036A18(3, &D_8004A6EC, n);
        func_80042A20(D_8004A688);
        len -= 0x400;
        addr += 0x400;
    } while (more != 0);
    if (changed != 0) {
        D_8004AB10 = old;
    }
    if (saved != 0) {
        D_8004AB2C = saved;
    }
    return 0;
}

s32 func_80038A84(s32 arg0) {
    u32 i;

    if (arg0 == 0 || arg0 == 3) {
        D_8004AAF4[0xD5] &= 0xFFBF;
        i = 0;
        while (D_8004AAF4[0xD5] & 0x40) {
            i++;
            if (i > 0xF00) {
                func_80042DC8("SPU:T/O [%s]\n", "wait (IRQ/ON)");
                return -1;
            }
        }
    }
    if (arg0 == 1 || arg0 == 3) {
        D_8004AAF4[0xD5] |= 0x40;
        i = 0;
        while (!(D_8004AAF4[0xD5] & 0x40)) {
            i++;
            if (i > 0xF00) {
                func_80042DC8("SPU:T/O [%s]\n", "wait (IRQ/OFF)");
                return -1;
            }
        }
    }
    return arg0;
}

s32 func_80038BC4(u32 arg0) {
    s32 r;

    if (arg0 <= 0x7FFF8) {
        r = func_80036DE0(0xD2, arg0);
    } else {
        r = 0;
    }
    return r;
}

s32 func_80038C04(s32 arg0) {
    s32 temp_s0;

    temp_s0 = D_8004AB30;
    if (arg0 != temp_s0) {
        D_8004AB30 = arg0;
        func_80038C48(arg0);
    }
    return temp_s0;
}

void func_80038C48(s32 arg0) {
    func_8003D0F0(9, arg0);
}

s32 func_80038C6C(s32 arg0, u32 arg1) {
    u32 mask;
    u32 hi;
    u16 lo16;
    u16 hi16;
    s32 v;

    mask = arg1 & 0xFFFFFF;
    lo16 = mask;
    hi = mask >> 16;
    hi16 = hi;
    if (arg0 != 0) {
        if (arg0 == 1) {
            if (D_8004AAEC & 1) {
                D_80077F28[0] = lo16;
                D_80077F28[1] = hi16;
                D_8004A6B8 |= 1;
                D_8004A6B4 = mask | D_8004A6B4;
                if (D_80077F28[2] & mask) {
                    D_80077F28[2] = D_80077F28[2] & ~mask;
                }
                if (D_80077F28[3] & hi) {
                    D_80077F28[3] = D_80077F28[3] & ~hi;
                }
            } else {
                v = mask | D_8004A68C;
                D_8004AAF4[0xC4] = lo16;
                D_8004AAF4[0xC5] = hi16;
                D_8004A68C = v;
            }
        }
    } else {
        if (D_8004AAEC & 1) {
            D_80077F28[2] = lo16;
            D_80077F28[3] = hi16;
            D_8004A6B8 |= 1;
            D_8004A6B4 = ~mask & D_8004A6B4;
            if (D_80077F28[0] & mask) {
                D_80077F28[0] = D_80077F28[0] & ~mask;
            }
            if (D_80077F28[1] & hi) {
                D_80077F28[1] = D_80077F28[1] & ~hi;
            }
        } else {
            D_8004AAF4[0xC6] = lo16;
            D_8004AAF4[0xC7] = hi16;
            D_8004A68C &= ~mask;
        }
    }
}

s32 func_80038E70(s32 arg0) {
    s32 i;
    s32 ch;
    s32 mask;
    u16 t;

    ch = -1;
    for (i = 0; i < 0x18; i++) {
        mask = 1 << i;
        if (arg0 & mask) {
            ch = i;
            break;
        }
    }
    if (ch == -1) {
        return -1;
    }
    t = D_8004AAF4[ch * 8 + 6];
    if ((1 << ch) & D_8004A68C) {
        if (t != 0) {
            return 1;
        }
        return 3;
    }
    return (t != 0) * 2;
}

s32 func_80038F04(s32 arg0, s32 arg1) {
    s32 var_s0;

    var_s0 = arg1;
    if ((u32) var_s0 > 0x7EFF0U) {
        var_s0 = 0x7EFF0;
    }
    func_80036CA8(arg0, var_s0);
    if (D_8004AB2C == 0) {
        D_8004AB28 = 0;
    }
    return var_s0;
}

u16 func_80038F64(u32 arg0) {
    u16 r;

    if (arg0 - 0x1010 <= 0x7EFE8) {
        D_8004AB0C = func_80036DE0(-1, arg0);
        r = D_8004AB0C;
    } else {
        r = 0;
    }
    return r;
}

void func_80038FB8(s32 arg0) {
    s32 v;

    switch (arg0) {
    case 0:
        v = 0;
        break;
    case 1:
        v = 1;
        break;
    default:
        v = 0;
        break;
    }
    D_8004A690 = arg0;
    D_8004AB10 = v;
}

void func_80038FEC(s32 arg0) {
    if (arg0 != D_8004AB2C) {
        D_8004AB2C = arg0;
    }
}

void func_80039010(s32 arg0, s32 arg1) {
    func_80037988(arg0, arg1, 0xC8, 0xC9);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039034);

void func_800393C8(s32 arg0, s32 arg1, s32 arg2) {
    volatile s32 i;
    volatile s32 a;
    s32 x;
    s32 y;

    x = arg1 & 0x7FFF;
    do {
    } while (0);
    y = arg2 & 0x7FFF;
    D_8004AAF4[arg0 * 8] = x;
    D_8004AAF4[arg0 * 8 + 1] = y;
    a = 1;
    for (i = 0; i < 2; i++) {
        a *= 0xD;
    }
}

void func_80039450(s32 arg0, u16 arg1, s32 arg2, s32 arg3, u16 arg4) {
    volatile s32 i;
    volatile s32 n;
    s32 t0;
    s32 r;
    s32 m;

    arg1 &= 0x7FFF;
    t0 = 0;
    arg0 = arg0 * 8;
    switch ((s16) (arg3 - 1)) {
    case 0:
        t0 = 0x8000;
        break;
    case 1:
        t0 = 0x9000;
        break;
    case 2:
        t0 = 0xA000;
        break;
    case 3:
        t0 = 0xB000;
        break;
    case 4:
        t0 = 0xC000;
        break;
    case 5:
        t0 = 0xD000;
        break;
    case 6:
        t0 = 0xE000;
        break;
    }
    r = arg2 & 0x7FFF;
    arg2 = 0;
    D_8004AAF4[arg0] = arg1 | t0;
    m = arg4;
    switch ((s16) (m - 1)) {
    case 0:
        arg2 = 0x8000;
        break;
    case 1:
        arg2 = 0x9000;
        break;
    case 2:
        arg2 = 0xA000;
        break;
    case 3:
        arg2 = 0xB000;
        break;
    case 4:
        arg2 = 0xC000;
        break;
    case 5:
        arg2 = 0xD000;
        break;
    case 6:
        arg2 = 0xE000;
        break;
    }
    D_8004AAF4[arg0 + 1] = r | arg2;
    n = 1;
    i = 0;
    while (i < 2) {
        n *= 0xD;
        ++i;
    }
}

void func_800395C8(s32 arg0, u16 arg1) {
    volatile s32 i;
    volatile s32 a;

    D_8004AAF4[arg0 * 8 + 2] = arg1;
    a = 1;
    for (i = 0; i < 2; i++) {
        a *= 0xD;
    }
}

void func_80039644(s32 arg0) {
    volatile s32 i;
    volatile s32 a;

    func_80036DE0((arg0 << 3) | 3);
    a = 1;
    for (i = 0; i < 2; i++) {
        a *= 0xD;
    }
}

void func_800396C0(s32 arg0) {
    volatile s32 i;
    volatile s32 a;

    func_80036DE0((arg0 << 3) | 7);
    a = 1;
    for (i = 0; i < 2; i++) {
        a *= 0xD;
    }
}

void func_8003973C(s32 arg0, s32 arg1) {
    volatile s32 i;
    volatile s32 a;
    volatile u16 *p;

    p = D_8004AAF4 + arg0 * 8;
    p[4] = (p[4] & 0xFF0F) | (arg1 << 4);
    a = 1;
    for (i = 0; i < 2; i++) {
        a *= 0xD;
    }
}

void func_800397C8(s32 arg0, s32 arg1) {
    volatile s32 i;
    volatile s32 a;
    volatile u16 *p;

    p = D_8004AAF4 + arg0 * 8;
    p[4] = (p[4] & 0xFFF0) | arg1;
    a = 1;
    for (i = 0; i < 2; i++) {
        a *= 0xD;
    }
}

void func_80039850(s32 arg0, s32 arg1, s32 arg2) {
    volatile s32 i;
    volatile s32 a;
    volatile u16 *p;
    s32 flag;

    p = D_8004AAF4 + arg0 * 8;
    flag = arg2 == 5;
    p[4] = (p[4] & 0xFF) | ((arg1 | (flag << 7)) << 8);
    a = 1;
    for (i = 0; i < 2; i++) {
        a *= 0xD;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800398EC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800399D0);

s32 func_80039A74(s32 arg0) {
    s32 r;

    if (arg0 >= 0) {
        r = func_80039AB0(arg0 & 0xFFF);
    } else {
        r = -func_80039AB0(-arg0 & 0xFFF);
    }
    return r;
}

s32 func_80039AB0(s32 arg0) {
    if (arg0 < 0x801) {
        if (arg0 < 0x401) {
            return D_8004AE54[arg0];
        }
        return D_8004AE54[0x800 - arg0];
    }
    if (arg0 < 0xC01) {
        return -D_80049E54[arg0];
    }
    return -D_8004AE54[0x1000 - arg0];
}

s32 func_80039B40(s32 arg0) {
    if (arg0 < 0) {
        arg0 = -arg0;
    }
    arg0 &= 0xFFF;
    if (arg0 < 0x801) {
        if (arg0 < 0x401) {
            return D_8004AE54[0x400 - arg0];
        }
        return -D_8004A654[arg0];
    }
    if (arg0 < 0xC01) {
        return -D_8004AE54[0xC00 - arg0];
    }
    return D_80049654[arg0];
}

void func_80039BE0(s32 arg0, s32 arg1, s32 arg2) {
    s32 t;
    s32 a;
    s32 q;
    s32 b;

    t = arg1 - arg0;
    if (t >= 100) {
        q = -arg0 * arg1 / t;
        b = ((arg1 << 12) / t) << 12;
        a = (q << 8) / arg2;
        if (a < -0x8000) {
            a = -0x8000;
        }
        if (a > 0x7FFF) {
            a = 0x7FFF;
        }
        func_8003B634(a);
        func_8003B640(b);
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039CEC);

s32 func_80039E40(s32 arg0) {
    s32 t;
    s32 s;
    s32 a;

    if (arg0 == 0) {
        return 0;
    }
    t = 8 - func_8003BAC0(arg0);
    if (t >= 0) {
        s = t >> 1;
        a = arg0 >> (s * 2);
    } else {
        s = (t >> 1) + 1;
        a = arg0 << -(s * 2);
    }
    s -= 6;
    if (s >= 0) {
        return func_80039CEC(a) << s;
    }
    return func_80039CEC(a) >> -s;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039EDC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039F5C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039FEC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A078);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A0E8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A1A4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A28C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A30C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A35C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A3AC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A434);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A4BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A51C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A59C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A63C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A79C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A8A8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A98C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AA74);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AB84);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003ACE4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AD14);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AE38);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AED8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AF78);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AFC0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B008);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B05C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B16C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B27C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B2CC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B32C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B35C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B48C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B4BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B4EC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B51C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B53C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B54C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B55C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B56C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B58C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B5A0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B5B4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B5C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B5D4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B5EC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B600);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B614);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B628);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B634);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B640);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B64C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B66C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B67C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B69C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B6BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B6DC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B6EC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B710);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B72C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B748);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B784);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B7A8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B7F0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B810);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B854);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B87C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B8A0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B8B0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B8CC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B8F4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B91C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B958);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B97C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B9A4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B9CC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B9EC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BA10);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BA68);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BAC0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BADC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BB0C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BB44);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BB7C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BBAC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BBDC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BC0C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BC6C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BC9C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BD1C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BD7C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BDFC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BE8C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BF3C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BF8C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003C21C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003C4AC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003C73C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003C8DC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003CA7C);

s32 func_8003CC1C(s32 arg0, s32 arg1) {
    s32 neg1;
    s32 neg0;
    s32 r;

    neg1 = 0;
    neg0 = 0;
    if (arg1 < 0) {
        neg1 = 1;
        arg1 = -arg1;
    }
    if (arg0 < 0) {
        neg0 = 1;
        arg0 = -arg0;
    }
    if (arg1 == 0 && arg0 == 0) {
        return 0;
    }
    if (arg0 < arg1) {
        if (arg0 & 0x7FE00000) {
            arg0 = arg0 / (arg1 >> 10);
            r = D_8004FC98[arg0];
        } else {
            arg0 = (arg0 << 10) / arg1;
            r = D_8004FC98[arg0];
        }
    } else {
        if (arg1 & 0x7FE00000) {
            arg0 = arg1 / (arg0 >> 10);
            r = 0x400 - D_8004FC98[arg0];
        } else {
            arg0 = (arg1 << 10) / arg0;
            r = 0x400 - D_8004FC98[arg0];
        }
    }
    if (neg1 != 0) {
        r = 0x800 - r;
    }
    if (neg0 != 0) {
        r = -r;
    }
    return r;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003CD9C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003CE0C);

s32 func_8003CE8C(void) {
    func_80042AA0();
    return ~D_8006E11C;
}

void func_8003CEBC(void) {
    func_80042A80();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003CEDC);

void func_8003D024(s32 arg0, s32 arg1) {
    volatile s32 timeout;

    timeout = arg1 << 15;
    while (D_80051568 < arg0) {
        if (--timeout == -1) {
            func_80042D48("VSync: timeout\n\0$Id: intr.c,v 1.73 1995/11/10 05:29:40 suzu Exp $");
            func_80042BA0(0);
            func_80042BB0(3, 0);
            return;
        }
    }
}

void func_8003D0C0(void) {
    M2C_FIELD(D_80051534, M2C_UNK (**)(), 0xC)();
}

s32 func_8003D0F0(s32 arg0, s32 arg1) {
    return M2C_FIELD(D_80051534, s32 (**)(), 8)();
}

s32 func_8003D120(s32 arg0, s32 arg1) {
    return M2C_FIELD(D_80051534, s32 (**)(), 4)();
}

void func_8003D150(s32 arg0) {
    M2C_FIELD(D_80051534, M2C_UNK (**)(M2C_UNK, s32), 0x14)(0, arg0);
}

void func_8003D184(void) {
    M2C_FIELD(D_80051534, M2C_UNK (**)(), 0x14)();
}

void func_8003D1B4(void) {
    M2C_FIELD(D_80051534, M2C_UNK (**)(), 0x10)();
}

void func_8003D1E4(void) {
    M2C_FIELD(D_80051534, M2C_UNK (**)(), 0x18)();
}

u16 func_8003D214(void) {
    return D_800504AE;
}

u16 func_8003D224(void) {
    return *D_8005153C;
}

u16 func_8003D23C(u16 arg0) {
    u16 temp_v0;

    temp_v0 = *D_8005153C;
    *D_8005153C = arg0;
    return temp_v0;
}

void *func_8003D258(void) {
    u16 *p;
    volatile u16 *q;
    volatile u16 *s;
    u8 *b;
    s32 off;

    p = &D_800504AC;
    if (*p != 0) {
        return 0;
    }
    s = D_80051538;
    q = D_8005153C;
    *q = 0;
    *s = *q;
    *D_80051540 = 0x33333333;
    func_8003D7A4((s32 *) p, 0x41A);
    if (func_80042D58((u16 *) ((u8 *) p + 0x38)) != 0) {
        func_8003D334();
    }
    b = D_800504E8;
    off = -0x3C;
    *(u8 **) b = b + 0xFDC;
    func_80042AD0(b - 4);
    *(s16 *) (b + off) = 1;
    *(void **) (D_80051534 + 0x14) = func_8003D7D0();
    *(void **) (D_80051534 + 4) = func_8003D8F8();
    func_800429C0(D_80051534);
    func_80042B00();
    return b + off;
}

s32 func_8003D334(void) {
    u16 *base;
    s32 *t;
    s32 *p;
    s32 cb;
    s32 i;
    s32 n;
    s32 m;
    u32 flags;

    base = &D_800504AC;
    if (*base == 0) {
        func_80042DC8("unexpected interrupt(%04x)\n", *D_80051538);
        func_80042AB0();
    }
    D_800504AE = 1;
    flags = (D_800504DC & *D_80051538) & *D_8005153C;
    if (flags != 0) {
        m = 1;
        t = (s32 *) ((u8 *) base + 4);
        do {
            i = 0;
            if (flags != 0) {
                p = t;
                while (1) {
                    if (i >= 11) {
                        break;
                    }
                    if (flags & 1) {
                        *D_80051538 = ~(m << i);
                        cb = *p;
                        if (cb != 0) {
                            ((void (*)(void)) cb)();
                        }
                    }
                    p++;
                    flags >>= 1;
                    i++;
                    if ((flags & 0xFFFF) == 0) {
                        break;
                    }
                }
            }
            flags = (D_800504DC & *D_80051538) & *D_8005153C;
        } while (flags != 0);
    }
    if (*D_80051538 & *D_8005153C) {
        n = D_80051544;
        D_80051544 = n + 1;
        if (n >= 0x801) {
            func_80042DC8("intr timeout(%04x:%04x)\n", *D_80051538, *D_8005153C);
            D_80051544 = 0;
            *D_80051538 = 0;
        }
    } else {
        D_80051544 = 0;
    }
    D_800504AE = 0;
    return func_80042AB0();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003D51C);

u16 *func_8003D670(void) {
    u16 *p;
    volatile u16 *q;
    volatile u16 *s;
    volatile s32 *r;

    p = &D_800504AC;
    if (*p == 0) {
        return 0;
    }
    func_80042AF0();
    q = D_8005153C;
    r = D_80051540;
    s = D_80051538;
    D_800504DE = *q;
    D_800504E0 = *r;
    *q = 0;
    *s = *q;
    *D_80051540 &= 0x77777777;
    func_80042AC0();
    *p = 0;
    return p;
}

u16 *func_8003D71C(void) {
    u16 *p;
    u16 *r;

    p = &D_800504AC;
    if (*p == 0) {
        func_80042AD0((u8 *) p + 0x38);
        *p = 1;
        *D_8005153C = D_800504DE;
        *D_80051540 = D_800504E0;
        func_80042B00();
        r = p;
    } else {
        r = 0;
    }
    return r;
}

void func_8003D7A4(s32 *arg0, s32 arg1) {
    s32 i;
    s32 pad;

    for (i = arg1 - 1; i != -1; i--) {
        *arg0++ = 0;
    }
}

M2C_UNK *func_8003D7D0(void) {
    *D_8005156C = 0x107;
    D_80051568 = 0;
    func_8003D8CC(&D_80051548, 8);
    func_8003D0F0(0, (s32) &func_8003D828);
    return &func_8003D8A0;
}

void func_8003D828(void) {
    s32 i;
    s32 *p;
    void (*f)();

    i = 0;
    p = D_80051548;
    ++D_80051568;
    do {
        f = (void (*)()) *p++;
        if (f != 0) {
            f();
        }
        i++;
    } while (i < 8);
}

void func_8003D8A0(s32 arg0, s32 arg1) {
    if (arg1 != D_80051548[arg0]) {
        D_80051548[arg0] = arg1;
    }
}

void func_8003D8CC(s32 *arg0, s32 arg1) {
    s32 i;
    s32 pad;

    for (i = arg1 - 1; i != -1; i--) {
        *arg0++ = 0;
    }
}

M2C_UNK *func_8003D8F8(void) {
    func_8003DB74(&D_80051574, 8);
    *D_80051570 = 0;
    func_8003D0F0(3, (s32) &func_8003D948);
    return &func_8003DACC;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003D948);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003DACC);

void func_8003DB74(s32 *arg0, s32 arg1) {
    s32 i;
    s32 pad;

    for (i = arg1 - 1; i != -1; i--) {
        *arg0++ = 0;
    }
}

void func_8003DBA0(s32 arg0, s32 arg1) {
    D_8009C6D4 = arg0;
    D_8009FE90 = arg1;
    func_80040898();
}

s32 func_8003DBD0(void) {
    s32 i;

    i = 4;
loop:
    if (func_8003DD18(1) != 1) {
        i--;
        if (i != -1) {
            goto loop;
        }
        func_80042DC8("CdInit: Init failed
");
        return 0;
    }
    func_8003DE6C((s32) func_8003DC60);
    func_8003DE84((s32) func_8003DC88);
    func_80041EFC((s32) func_8003DCB0);
    return 1;
}

void func_8003DC60(void) {
    func_800429F0(0xF0000003, 0x20);
}

void func_8003DC88(void) {
    func_800429F0(-0x0FFFFFFD, 0x40);
}

void func_8003DCB0(void) {
    func_800429F0(-0x0FFFFFFD, 0x40);
}

u8 func_8003DCD8(void) {
    return D_80051638;
}

u8 func_8003DCE8(void) {
    return D_80051648;
}

u8 func_8003DCF8(void) {
    return D_80051649;
}

M2C_UNK *func_8003DD08(void) {
    return &D_80051644;
}

s32 func_8003DD18(s32 arg0) {
    if (arg0 == 2) {
        func_8003F5F4();
        return 1;
    }
    if (func_8003F644() != 0) {
        return 0;
    }
    if (arg0 == 1) {
        if (func_8003F500() != 0) {
            return 0;
        }
    }
    return 1;
}

void func_8003DD84(void) {
    func_8003F420();
}

s32 func_8003DDA4(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80051634;
    D_80051634 = arg0;
    return temp_v0;
}
