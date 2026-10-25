#include "common.h"
#include "batres/decls.h"

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B0000);

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B09C0);

void func_801B0C74(BrChr *arg0, s32 arg1) {
    s32 i;
    u32 m;

    arg1 <<= 8;
    for (i = 0; i < 8; i++) {
        m = arg0->wpn[i];
        if ((m & 0xFF) != 0xFF && (D_800730DD[m & 0xFF].a & 0xF) == 7) {
            arg0->wpn[i] = m | arg1;
        }
        m = arg0->arm[i];
        if ((m & 0xFF) != 0xFF && (D_800730DD[m & 0xFF].a & 0xF) == 7) {
            arg0->arm[i] = m | arg1;
        }
    }
}

void func_801B0D14(s32 arg0) {
    s32 i;
    u8 *p;
    s32 hp;
    s32 mp;
    s32 cur;

    for (i = 0; i < 9; i++) {
        if (D_8009C738[i][0] < 9 && ((arg0 >> D_8009C738[i][0]) & 1)) {
            p = D_8009C738[i];
            hp = *(u16 *)(p + 0x2E);
            mp = *(u16 *)(p + 0x32);
            func_801B0EF8(p, D_8009D7D8 / 2, -1);
            if (*(u16 *)(p + 0x2C) != 0) {
                cur = *(u16 *)(p + 0x2E);
                if (hp < cur) {
                    *(u16 *)(p + 0x2C) += cur - hp;
                }
                cur = *(u16 *)(p + 0x32);
                if (mp < cur) {
                    *(u16 *)(p + 0x30) += cur - mp;
                }
            }
        }
    }
}

void func_801B0E20(void) {
    s32 mask;
    s32 i;

    mask = 0;
    D_8009D7D8 = 0;
    D_8009D7DC = 0;
    D_8009D7E0 = 0;
    for (i = 0; i < 4; i++) {
        D_8009D808[i].a = -1;
        D_8009D808[i].b = 0;
    }
    for (i = 0; i < 3; i++) {
        D_8009D7EC[i].b = 0;
        D_8009D7EC[i].a = 0;
    }
    for (i = 0; i < 3; i++) {
        if (D_8009CBDC[i] == 0xFF) {
            mask |= 1 << i;
        }
    }
    func_80015654(mask);
}

void func_801B0EF8(u8 *arg0, s32 arg1, s32 arg2) {
    BrLvl lv;
    s32 i;
    s32 *dst;

    func_801B1008(&lv, arg0);
    if (arg2 != -1) {
        D_80075DE4[arg2] = 0;
        D_80075DE8[arg2] = lv.lvl;
    }
    func_801B118C((NmLvl *)&lv);
    lv.f34 = arg1;
    func_801B1204((NmLvl *)&lv);
    if (arg2 != -1) {
        D_80075D14[arg2] = lv.f30;
        D_80075D14[arg2 - 4] = lv.f2C;
        D_80075D24[arg2 * 12] = lv.f38;
        dst = &D_80075D14[arg2 * 12 + 4];
        for (i = 0; i < 11; i++) {
            dst[i + 1] = lv.c[i];
        }
    }
    func_801B108C((NmLvl *)&lv, arg0);
}

void func_801B1008(void *arg0, void *arg1) {
    M2C_FIELD(arg0, u8 *, 4) = (u8) M2C_FIELD(arg1, u8 *, 0);
    M2C_FIELD(arg0, u8 *, 5) = (u8) M2C_FIELD(arg1, u8 *, 1);
    M2C_FIELD(arg0, s16 *, 8) = (s16) M2C_FIELD(arg1, u8 *, 2);
    M2C_FIELD(arg0, s16 *, 0xA) = (s16) M2C_FIELD(arg1, u8 *, 3);
    M2C_FIELD(arg0, s16 *, 0xC) = (s16) M2C_FIELD(arg1, u8 *, 4);
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) M2C_FIELD(arg1, u8 *, 5);
    M2C_FIELD(arg0, s16 *, 0x10) = (s16) M2C_FIELD(arg1, u8 *, 6);
    M2C_FIELD(arg0, s16 *, 0x12) = (s16) M2C_FIELD(arg1, u8 *, 7);
    M2C_FIELD(arg0, u16 *, 0x14) = (u16) M2C_FIELD(arg1, u16 *, 0x2E);
    M2C_FIELD(arg0, u16 *, 0x16) = (u16) M2C_FIELD(arg1, u16 *, 0x32);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg1, s32 *, 0x3C);
}

void func_801B108C(NmLvl *arg0, NmOut *arg1) {
    u32 a;
    u32 b;

    arg1->lvl = arg0->lvl;
    arg1->s[0] = arg0->stat[0];
    arg1->s[1] = arg0->stat[1];
    arg1->s[2] = arg0->stat[2];
    arg1->s[3] = arg0->stat[3];
    arg1->s[4] = arg0->stat[4];
    arg1->s[5] = arg0->stat[5];
    arg1->f2E = arg0->stat[6];
    arg1->f32 = arg0->stat[7];
    arg1->f3C = M2C_FIELD(arg0, s32 *, 0x30);
    arg1->f80 = M2C_FIELD(arg0, s32 *, 0x80) - M2C_FIELD(arg0, s32 *, 0x30);
    arg1->pct = 0;
    a = M2C_FIELD(arg0, u32 *, 0x80);
    b = M2C_FIELD(arg0, u32 *, 0x7C);
    if (a != b) {
        arg1->pct = (M2C_FIELD(arg0, u32 *, 0x30) - b) * 0x3D / (a - b);
    }
    if (arg0->lvl >= 0x63) {
        arg1->f80 = 0;
        arg1->pct = 0x3D;
    }
}

void func_801B118C(NmLvl *arg0) {
    s32 i;
    u16 *q;

    arg0->p = D_80082268 + arg0->id * 0x38;
    q = (u16 *)arg0;
    for (i = 0; i < 8; i++) {
        if (q[i + 4] == 0) {
            q[i + 4] = 1;
        }
        q[i + 12] = q[i + 4];
    }
    for (i = 0; i < 16; i++) {
        arg0->c[i] = 0;
    }
}

void func_801B1204(NmLvl *arg0) {
    s32 n;
    s32 i;
    u32 next;
    u32 exp;
    s32 lvl;
    u32 prev;

    exp = arg0->f2C + M2C_FIELD(arg0, s32 *, 0x34);
    M2C_FIELD(arg0, u32 *, 0x30) = exp;
    n = 0;
    if (exp > 999999999) {
        M2C_FIELD(arg0, u32 *, 0x30) = 999999999;
    }
    prev = func_801B1320(arg0, arg0->lvl - 1);
    M2C_FIELD(arg0, u32 *, 0x38) = prev;
    M2C_FIELD(arg0, u32 *, 0x7C) = prev;
    while ((lvl = arg0->lvl) < 99) {
        next = func_801B1320(arg0, lvl);
        M2C_FIELD(arg0, u32 *, 0x80) = next;
        if (n < 16) {
            arg0->c[n] = next;
            n++;
        }
        if (M2C_FIELD(arg0, u32 *, 0x30) < next) {
            break;
        }
        for (i = 0; i < 6; i++) {
            func_801B1564(arg0, i);
        }
        func_801B15E4(arg0);
        func_801B16D8(arg0);
        arg0->lvl++;
        M2C_FIELD(arg0, u32 *, 0x7C) = next;
    }
}

s32 func_801B1320(NmLvl *arg0, s32 arg1) {
    s32 sum;
    s32 i;

    sum = 0;
    arg0->rank = 0;
    if (arg1 != 0) {
        if (arg1 < 0x3D) {
            arg0->rank = (arg1 - 1) / 10;
        } else {
            arg0->rank = (arg1 - 0x3D) / 20 + 6;
        }
    }
    for (i = 1; i <= arg1; i++) {
        sum += D_80082484[arg0->p[8] * 0x10 + arg0->rank * 2] * i * i / 10;
    }
    return sum;
}

s32 func_801B13F4(s32 arg0) {
    s32 v;

    v = arg0 + (func_80014B70() & 7) + 1;
    if (v < 0) {
        v = 0;
    } else if ((u32)v > 11) {
        v = 11;
    }
    return v;
}

s32 func_801B1448(NmLvl *arg0, s32 arg1, s32 arg2) {
    s32 i;

    i = arg0->rank * 2 + arg0->p[arg2] * 0x10;
    return D_80082484[i] * arg1 / 100 + D_80082485[i];
}

s32 func_801B14AC(NmLvl *arg0, s32 arg1) {
    s32 i;

    i = arg0->rank * 2 + arg0->p[6] * 0x10;
    return D_80082484[i] * arg1 + D_80082485[i] * 0x28;
}

s32 func_801B1500(NmLvl *arg0, s32 arg1) {
    s32 i;

    i = arg0->rank * 2 + arg0->p[7] * 0x10;
    return D_80082484[i] * arg1 / 10 + D_80082485[i] * 2;
}

void func_801B1564(NmLvl *arg0, s32 arg1) {
    s32 v;

    v = func_801B1448(arg0, arg0->lvl + 1, arg1);
    v = arg0->stat[arg1] + D_80082460[func_801B13F4(v - arg0->stat[arg1])];
    if (v > 100) {
        v = 100;
    }
    arg0->stat[arg1] = v;
}

void func_801B15E4(NmLvl *arg0) {
    s32 a;
    s32 b;
    s32 v;

    a = func_801B14AC(arg0, arg0->lvl);
    b = func_801B14AC(arg0, arg0->lvl + 1);
    v = arg0->stat[6] + (b - a) * D_8008246C[func_801B13F4(a * 100 / arg0->stat[6] - 100)] / 100;
    if (v > 9999) {
        v = 9999;
    }
    arg0->stat[6] = v;
}

void func_801B16D8(NmLvl *arg0) {
    s32 a;
    s32 b;
    s32 v;

    a = func_801B1500(arg0, arg0->lvl);
    b = func_801B1500(arg0, arg0->lvl + 1);
    v = arg0->stat[7] + (b - a) * D_80082478[func_801B13F4(a * 100 / arg0->stat[7] - 100)] / 100;
    if (v > 999) {
        v = 999;
    }
    arg0->stat[7] = v;
}

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B17CC);
