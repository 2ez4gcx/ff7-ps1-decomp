#include "common.h"
#include "namemenu/decls.h"

void func_801D14E8(u8 *arg0) {
    NmLvlFull lv;
    s32 sum;
    s32 n;
    s32 i;
    s32 j;
    u8 flags;

    sum = 0;
    n = 0;
    flags = 0;
    if (arg0[0] < 9) {
        flags = D_80082268[arg0[0]][0xA];
    }
    for (i = 0; i < 9; i++) {
        if ((D_8009D78A[0] >> i) & 1) {
            for (j = 0; j < 9; j++) {
                if (D_8009C738[j][0] == i) {
                    if (i != arg0[0]) {
                        n++;
                        sum += D_8009C738[j][1];
                    }
                    break;
                }
            }
        }
    }
    if (n == 0) {
        n = 1;
        sum = arg0[1];
    }
    sum /= n;
    if (flags & 1) {
        sum = D_8009D28A;
    } else {
        sum += (s8)flags / 2;
    }
    if (sum <= 0) {
        sum = 1;
    }
    func_801D16B4(&lv, arg0);
    if (flags & 1) {
        lv.l.f2C = 0;
        lv.l.lvl = 1;
        for (i = 0; i < 8; i++) {
            lv.l.base[i] = 0;
        }
    }
    func_801D1838(&lv.l);
    M2C_FIELD(&lv, u32 *, 0x34) = func_801D19CC(&lv.l, sum - 1);
    func_801D18B0(&lv.l);
    func_801D1738(&lv.l, arg0);
}

void func_801D16B4(void *arg0, void *arg1) {
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

void func_801D1738(NmLvl *arg0, u8 *arg1) {
    u32 next;
    u32 prev;
    u32 left;

    arg1[1] = arg0->lvl;
    arg1[2] = arg0->stat[0];
    arg1[3] = arg0->stat[1];
    arg1[4] = arg0->stat[2];
    arg1[5] = arg0->stat[3];
    arg1[6] = arg0->stat[4];
    arg1[7] = arg0->stat[5];
    *(u16 *)(arg1 + 0x2E) = arg0->stat[6];
    *(u16 *)(arg1 + 0x32) = arg0->stat[7];
    *(u32 *)(arg1 + 0x3C) = M2C_FIELD(arg0, u32 *, 0x30);
    left = M2C_FIELD(arg0, u32 *, 0x80) - M2C_FIELD(arg0, u32 *, 0x30);
    arg1[0x21] = 0;
    *(u32 *)(arg1 + 0x80) = left;
    next = M2C_FIELD(arg0, u32 *, 0x80);
    prev = M2C_FIELD(arg0, u32 *, 0x7C);
    if (next != prev) {
        arg1[0x21] = (M2C_FIELD(arg0, u32 *, 0x30) - prev) * 61 / (next - prev);
    }
    if (arg0->lvl >= 99) {
        *(u32 *)(arg1 + 0x80) = 0;
        arg1[0x21] = 61;
    }
}

void func_801D1838(NmLvl *arg0) {
    s32 i;

    arg0->p = D_80082268[arg0->id];
    for (i = 0; i < 8; i++) {
        if (arg0->base[i] == 0) {
            arg0->base[i] = 1;
        }
        arg0->stat[i] = arg0->base[i];
    }
    for (i = 15; i >= 0; i--) {
        arg0->c[i] = 0;
    }
}

void func_801D18B0(NmLvl *arg0) {
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
    prev = func_801D19CC(arg0, arg0->lvl - 1);
    M2C_FIELD(arg0, u32 *, 0x38) = prev;
    M2C_FIELD(arg0, u32 *, 0x7C) = prev;
    while ((lvl = arg0->lvl) < 99) {
        next = func_801D19CC(arg0, lvl);
        M2C_FIELD(arg0, u32 *, 0x80) = next;
        if (n < 16) {
            arg0->c[n] = next;
            n++;
        }
        if (M2C_FIELD(arg0, u32 *, 0x30) < next) {
            break;
        }
        for (i = 0; i < 6; i++) {
            func_801D1C10(arg0, i);
        }
        func_801D1C90(arg0);
        func_801D1D84(arg0);
        arg0->lvl++;
        M2C_FIELD(arg0, u32 *, 0x7C) = next;
    }
}

s32 func_801D19CC(NmLvl *arg0, s32 arg1) {
    s32 sum;
    s32 i;
    u8 base;

    sum = 0;
    arg0->rank = 0;
    if (arg1 != 0) {
        if (arg1 < 61) {
            arg0->rank = (arg1 - 1) / 10;
        } else {
            arg0->rank = (arg1 - 61) / 20 + 6;
        }
    }
    for (i = 1; i <= arg1; i++) {
        base = D_80082484[arg0->p[8]][arg0->rank].a;
        sum += base * i * i / 10;
    }
    return sum;
}

s32 func_801D1AA0(s32 arg0) {
    s32 v;

    v = arg0 + (func_80014B70() & 7) + 1;
    if (v < 0) {
        v = 0;
    } else if ((u32)v > 11) {
        v = 11;
    }
    return v;
}

s32 func_801D1AF4(NmLvl *arg0, s32 arg1, s32 arg2) {
    return D_80082484[arg0->p[arg2]][arg0->rank].a * arg1 / 100 + D_80082484[arg0->p[arg2]][arg0->rank].b;
}

s32 func_801D1B58(NmLvl *arg0, s32 arg1) {
    return D_80082484[arg0->p[6]][arg0->rank].a * arg1 + D_80082484[arg0->p[6]][arg0->rank].b * 40;
}

s32 func_801D1BAC(NmLvl *arg0, s32 arg1) {
    return D_80082484[arg0->p[7]][arg0->rank].a * arg1 / 10 + D_80082484[arg0->p[7]][arg0->rank].b * 2;
}

void func_801D1C10(NmLvl *arg0, s32 arg1) {
    s32 v;

    v = func_801D1AF4(arg0, arg0->lvl + 1, arg1);
    v = arg0->stat[arg1] + D_80082460[func_801D1AA0(v - arg0->stat[arg1])];
    if (v > 100) {
        v = 100;
    }
    arg0->stat[arg1] = v;
}

void func_801D1C90(NmLvl *arg0) {
    s32 cur;
    s32 next;
    s32 v;

    cur = func_801D1B58(arg0, arg0->lvl);
    next = func_801D1B58(arg0, arg0->lvl + 1);
    v = arg0->stat[6] + (next - cur) * D_8008246C[func_801D1AA0(cur * 100 / arg0->stat[6] - 100)] / 100;
    if (v > 9999) {
        v = 9999;
    }
    arg0->stat[6] = v;
}

void func_801D1D84(NmLvl *arg0) {
    s32 cur;
    s32 next;
    s32 v;

    cur = func_801D1BAC(arg0, arg0->lvl);
    next = func_801D1BAC(arg0, arg0->lvl + 1);
    v = arg0->stat[7] + (next - cur) * D_80082478[func_801D1AA0(cur * 100 / arg0->stat[7] - 100)] / 100;
    if (v > 999) {
        v = 999;
    }
    arg0->stat[7] = v;
}
