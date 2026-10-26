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
s32 func_80048540(s32 arg0);
s32 func_80046D0C(s32 arg0);
s32 func_800484A8(void);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_8004602C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80046168);

void func_800462B0(void) {
    D_80062D18 = func_8003CEDC(-1) + 0xF0;
    D_80062D1C = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_800462E4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80046450);

void func_80046530(u8 *arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 pad;

    for (i = arg2 - 1; i != -1; i--) {
        *arg0++ = arg1;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_8004655C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_8004656C);

s32 func_80046634(s32 arg0, s32 arg1) {
    return ((arg1 << 6) | ((arg0 >> 4) & 0x3F)) & 0xFFFF;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_8004664C);

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib5", D_80010EB0);

void func_8004671C(s32 arg0) {
    D_80062BFC("clut: (%d,%d)\n", (arg0 & 0x3F) * 0x10, (u32) (arg0 & 0xFFFF) >> 6);
}

s32 func_8004675C(s32 *arg0) {
    return (*arg0 & 0xFFFFFF) | 0x80000000;
}

s32 func_80046778(s32 *arg0) {
    return (*arg0 & 0xFFFFFF) == 0xFFFFFF;
}

void func_80046794(MainTag *arg0, MainTag *arg1) {
    arg1->addr = arg0->addr;
    arg0->addr = (u32) arg1;
}

void func_800467D0(MainTag *arg0, u32 arg1, MainTag *arg2) {
    arg2->addr = arg0->addr;
    arg0->addr = arg1;
}

void func_8004680C(s32 *arg0, s32 arg1) {
    *arg0 = (*arg0 & 0xFF000000) | (arg1 & 0xFFFFFF);
}

void func_80046830(s32 *arg0) {
    *arg0 |= 0xFFFFFF;
}

void func_80046848(void *arg0, s32 arg1) {
    u8 var_v0;

    if (arg1 != 0) {
        var_v0 = M2C_FIELD(arg0, u8 *, 7) | 2;
    } else {
        var_v0 = M2C_FIELD(arg0, u8 *, 7) & 0xFD;
    }
    M2C_FIELD(arg0, u8 *, 7) = var_v0;
}

void func_80046870(void *arg0, s32 arg1) {
    u8 var_v0;

    if (arg1 != 0) {
        var_v0 = M2C_FIELD(arg0, u8 *, 7) | 1;
    } else {
        var_v0 = M2C_FIELD(arg0, u8 *, 7) & 0xFE;
    }
    M2C_FIELD(arg0, u8 *, 7) = var_v0;
}

void func_80046898(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 4;
    M2C_FIELD(arg0, s8 *, 7) = 0x20;
}

void func_800468AC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 7;
    M2C_FIELD(arg0, s8 *, 7) = 0x24;
}

void func_800468C0(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 6;
    M2C_FIELD(arg0, s8 *, 7) = 0x30;
}

void func_800468D4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 9;
    M2C_FIELD(arg0, s8 *, 7) = 0x34;
}

void func_800468E8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 5;
    M2C_FIELD(arg0, s8 *, 7) = 0x28;
}

void func_800468FC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 9;
    M2C_FIELD(arg0, s8 *, 7) = 0x2C;
}

void func_80046910(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 8;
    M2C_FIELD(arg0, s8 *, 7) = 0x38;
}

void func_80046924(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 0xC;
    M2C_FIELD(arg0, s8 *, 7) = 0x3C;
}

void func_80046938(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 3;
    M2C_FIELD(arg0, s8 *, 7) = 0x74;
}

void func_8004694C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 3;
    M2C_FIELD(arg0, s8 *, 7) = 0x7C;
}

void func_80046960(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 4;
    M2C_FIELD(arg0, s8 *, 7) = 0x64;
}

void func_80046974(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 2;
    M2C_FIELD(arg0, s8 *, 7) = 0x68;
}

void func_80046988(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 2;
    M2C_FIELD(arg0, s8 *, 7) = 0x70;
}

void func_8004699C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 2;
    M2C_FIELD(arg0, s8 *, 7) = 0x78;
}

void func_800469B0(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 3;
    M2C_FIELD(arg0, s8 *, 7) = 0x60;
}

void func_800469C4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 3;
    M2C_FIELD(arg0, s8 *, 7) = 0x40;
}

void func_800469D8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 4;
    M2C_FIELD(arg0, s8 *, 7) = 0x50;
}

void func_800469EC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 5;
    M2C_FIELD(arg0, s8 *, 7) = 0x48;
    M2C_FIELD(arg0, s32 *, 0x14) = 0x55555555;
}

void func_80046A0C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 7;
    M2C_FIELD(arg0, s8 *, 7) = 0x58;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0x55555555;
}

void func_80046A2C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 6;
    M2C_FIELD(arg0, s8 *, 7) = 0x4C;
    M2C_FIELD(arg0, s32 *, 0x18) = 0x55555555;
}

void func_80046A4C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 9;
    M2C_FIELD(arg0, s8 *, 7) = 0x5C;
    M2C_FIELD(arg0, s32 *, 0x24) = 0x55555555;
}

void func_80046A6C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 3;
    M2C_FIELD(arg0, s8 *, 7) = 2;
}

void func_80046A80(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 5;
    M2C_FIELD(arg0, s8 *, 7) = 1;
    M2C_FIELD(arg0, s32 *, 8) = 0x80000000;
}

s32 func_80046A9C(void *arg0, void *arg1) {
    s32 t;

    t = M2C_FIELD(arg0, u8 *, 3) + M2C_FIELD(arg1, u8 *, 3) + 1;
    if (t > 0x20) {
        return -1;
    }
    M2C_FIELD(arg0, u8 *, 3) = t;
    return 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80046AD0);

void func_80046C50(DispEnv *arg0) {
    D_80062BFC("disp   (%3d,%3d)-(%d,%d)\n", arg0->disp.x, arg0->disp.y, arg0->disp.w, arg0->disp.h);
    D_80062BFC("screen (%3d,%3d)-(%d,%d)\n", arg0->screen.x, arg0->screen.y, arg0->screen.w, arg0->screen.h);
    D_80062BFC("isinter %d\n", arg0->isinter);
    D_80062BFC("isrgb24 %d\n", arg0->isrgb24);
}

s32 func_80046CFC(s32 arg0) {
    D_80070690 = arg0;
    return 0;
}

s32 func_80046D0C(s32 arg0) {
    s32 t;

    t = func_80047060(D_80070690, arg0);
    if (t == -1) {
        return 0;
    }
    D_80070690 += t * 4;
    return arg0;
}

void func_80046D74(s32 arg0, s32 arg1) {
    D_800706A0 = func_80047180(arg0, arg1, &D_8007069C, &D_80070694, &D_80070698);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80046DB4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80047060);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80047180);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80047318);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048498);

s32 func_800484A8(void) {
    s32 zero;
    volatile s32 tmp;

    zero = 0;
    if (!(0x01000000 & *D_80062D28)) {
        return zero;
    }
    if (((u32) (*D_80062D28 & 0x700) >> 8) != 4) {
        return -1;
    }
    *D_80062D28 &= 0xFEFFFFFF;
    tmp = *D_80062D28;
    tmp = *D_80062D20;
    if ((tmp & 0xFFFFFF) == 0xFFFFFF) {
        return zero;
        do {
        } while (zero);
    }
    return tmp;
}

s32 func_80048540(s32 arg0) {
    s32 i;

    i = 0;
    while (!(*D_80062D30 & 0x04000000)) {
        if (arg0 < i++) {
            return -1;
        }
    }
    return 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_800485A0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_800487F0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048968);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_800489D0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_800489E0);

void func_80048A44(void) {
    func_80042AF0();
    func_80048ABC();
    func_80042BA0(0);
    func_80042B00();
}

void func_80048A7C(void) {
    func_80048ACC();
    func_80048BEC();
    func_80048C7C();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048AAC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048ABC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048ACC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048B34);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048BBC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048BEC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048C58);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048C7C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", D_80048CFC);
