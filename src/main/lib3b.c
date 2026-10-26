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
s32 func_80042BC0(s32 arg0, s16 arg1, s32 arg2);
s32 func_80041E30(s32 arg0, s32 arg1);
s32 func_800436C0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
M2C_UNK func_80042DC8(M2C_UNK *, s32);
void func_80042168(s32 arg0);
M2C_UNK func_80042D38();
extern s32 D_80051A4C;
extern s32 D_80051AD0;

void func_80042168(s32 arg0) {
    switch (arg0) {
    case 0:
        *D_80051B88 = 0x80000000;
        *D_80051B5C = 0;
        *D_80051B68 = 0;
        *D_80051B88 = 0x60000000;
        func_80042270(&D_80051A4C, 0x20U);
        func_80042270(&D_80051AD0, 0x20U);
        return;
    case 1:
        *D_80051B88 = 0x80000000;
        *D_80051B5C = 0;
        *D_80051B68 = 0;
        *D_80051B68;
        *D_80051B88 = 0x60000000;
        return;
    default:
        func_80042DC8("MDEC_rest:bad option(%d)\n", arg0);
        func_80042D38();
        return;
    }
}

void func_80042270(s32 *arg0, u32 arg1) {
    func_80042394();
    *D_80051B8C |= 0x88;
    *D_80051B54 = (s32) (arg0 + 1);
    *D_80051B58 = ((arg1 >> 5) << 0x10) | 0x20;
    *D_80051B84 = *arg0;
    *D_80051B5C = 0x01000201;
}

void func_80042304(arg0, arg1) {
    func_8004242C();
    *D_80051B8C |= 0x88;
    *D_80051B68 = 0;
    *D_80051B60 = arg0;
    *D_80051B64 = (((u32) arg1 >> 5) << 0x10) | 0x20;
    *D_80051B68 = 0x01000200;
}

s32 func_80042394(void) {
    volatile s32 timeout;

    timeout = 0x100000;
    while (*D_80051B88 & 0x20000000) {
        if (--timeout == -1) {
            func_800424C4("MDEC_in_sync");
            return -1;
        }
    }
    return 0;
}

s32 func_8004242C(void) {
    volatile s32 timeout;

    timeout = 0x100000;
    while (*D_80051B68 & 0x01000000) {
        if (--timeout == -1) {
            func_800424C4("MDEC_out_sync");
            return -1;
        }
    }
    return 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_800424C4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", D_800425F8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_8004262C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042990);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_800429A0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_800429C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_800429D0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_800429F0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042A00);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042A10);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042A20);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042A40);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042A50);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042A60);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042A70);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042A80);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042A90);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042AA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042AB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042AC0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042AD0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042AE0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042AF0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042B00);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042B10);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042B20);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042BA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3b", func_80042BB0);

s32 func_80042BC0(s32 arg0, s16 arg1, s32 arg2) {
    s32 n;
    s32 mode;

    n = arg0 & 0xFFFF;
    mode = 0x48;
    if (n >= 3) {
        return 0;
    }
    D_80062B94[n].mode = 0;
    D_80062B94[n].target = arg1;
    if ((u32)n < 2) {
        if (arg2 & 0x10) {
            mode = 0x49;
        }
        if (!(arg2 & 1)) {
            mode |= 0x100;
        }
    } else if (n == 2) {
        if (!(arg2 & 1)) {
            mode = 0x248;
        }
    }
    if (arg2 & 0x1000) {
        mode |= 0x10;
    }
    D_80062B94[n].mode = mode;
    return 1;
}
