#include "common.h"
#include "batres/decls.h"

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B0000);

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B09C0);

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B0C74);

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B0D14);

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B0E20);

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B0EF8);

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

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B108C);

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B118C);

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

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B1320);

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

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B1448);

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B14AC);

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B1500);

void func_801B1564(NmLvl *arg0, s32 arg1) {
    s32 v;

    v = func_801B1448(arg0, arg0->lvl + 1, arg1);
    v = arg0->stat[arg1] + D_80082460[func_801B13F4(v - arg0->stat[arg1])];
    if (v > 100) {
        v = 100;
    }
    arg0->stat[arg1] = v;
}

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B15E4);

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B16D8);

INCLUDE_ASM("../asm/us/batres/nonmatchings/text", func_801B17CC);
