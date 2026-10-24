#include "common.h"
#include "namemenu/decls.h"

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text2", func_801D14E8);

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

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text2", func_801D1738);

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

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text2", func_801D18B0);

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
