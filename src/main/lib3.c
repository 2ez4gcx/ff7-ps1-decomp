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

s32 func_800404F4(s32 arg0, M2C_UNK arg1, s32 arg2) {
    s32 sp10;

    func_8003E2D0(arg1, &sp10);
    func_8003DE9C(2, &sp10, 0);
    func_80041D28(arg0, arg2, 0x80);
    return func_80041E30(0, 0) == 0;
}

void func_80040560(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 i;
    s32 pad;

    for (i = arg2 - 1; i != -1; i--) {
        *arg0++ = *arg1++;
    }
}

s32 func_80040594(s32 arg0) {
    s8 sp10;

    sp10 = (s8) arg0;
    func_8003DE9C(0xE, (s32 *) &sp10, 0);
    if (arg0 & 0x100) {
        if (arg0 & 0x20) {
            D_80071C18 = 0;
        } else {
            D_80071C18 = 1;
        }
        func_8003E28C((s32) &func_80040950);
        func_8003DE84((s32) func_80040628);
    }
    return func_8003DE9C(0x1B, NULL, 0);
}

void func_80040628(void) {
    func_80040CA8();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80040648);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_8004076C);

s32 func_80040898(void) {
    s32 temp_v0;

    D_8009C550 = 0;
    D_8009C54C = 0;
    D_8009C548 = 0;
    D_80095D80 = 0;
    temp_v0 = func_80040B84(0, D_8009FE90);
    D_80075CFC = 0;
    D_80071C10 = 0;
    D_80071740 = 0;
    return temp_v0;
}

s32 func_800408F8(void) {
    func_80042AF0();
    func_8003E28C(0);
    func_8003DE84(0);
    *D_8005194C = 0;
    *D_80051958 = 0;
    return func_80042B00();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80040950);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_800409E0);

void func_80040A40(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_80040C88(1, arg1, arg2);
    D_8009C6C0 = 0;
    D_80074EA0 = arg3;
    D_80071C14 = arg0 & 1;
    D_80081DC0 = 0;
    D_8007E764 = 0;
    D_80071C10 = 0;
    D_80071740 = 0;
    D_800756E4 = arg4;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80040AC8);

s32 func_80040B84(s32 arg0, u32 arg1) {
    u32 i;
    s32 pad;

    for (i = 0; i < arg1; i++) {
        *(s32 *) (((i + arg0) << 5) + D_8009C6D4) = 0;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80040BC4);

void func_80040C88(s32 arg0, s32 arg1, s32 arg2) {
    D_8009C6CC = arg0;
    D_8007E76C = arg1;
    D_8009C6C8 = arg2;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80040CA8);

void func_80041620(s32 *arg0, s32 *arg1, u32 arg2) {
    u32 i;
    s32 pad;

    for (i = 0; i < arg2; i++) {
        *arg0++ = *arg1++;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80041654);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80041810);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_800418D8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80041AFC);

void func_80041CD4(void) {
    *(volatile s32 *) &D_80051A34 = 0;
    func_8003DE6C(D_80051A44);
    func_8003DE84(D_80051A48);
    func_8003DE9C(9, NULL, 0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80041D28);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80041E30);

s32 func_80041EFC(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80051A1C;
    D_80051A1C = arg0;
    return temp_v0;
}

s32 func_80041F14(s32 arg0) {
    if (arg0 == 0) {
        func_8003D0C0();
    }
    return func_80042168(arg0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80041F4C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80041FD8);

u16 func_80042038(u16 *arg0) {
    return *arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042044);

void func_800420C0(void) {
    func_80042304();
}

void func_800420E0(void) {
    func_80042394();
}

void func_80042100(void) {
    func_8004242C();
}

void func_80042120(s32 arg0) {
    func_8003D120(0, arg0);
}

void func_80042144(s32 arg0) {
    func_8003D120(1, arg0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042168);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042270);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042304);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042394);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_8004242C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_800424C4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", D_800425F8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_8004262C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042990);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_800429A0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_800429C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_800429D0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_800429F0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042A00);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042A10);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042A20);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042A40);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042A50);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042A60);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042A70);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042A80);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042A90);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042AA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042AB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042AC0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042AD0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042AE0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042AF0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042B00);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042B10);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042B20);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042BA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042BB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042BC0);

s32 func_80042C60(s32 arg0) {
    s32 n;

    n = arg0 & 0xFFFF;
    if (n >= 3) {
        return 0;
    }
    return D_80062B94[n].v;
}

s32 func_80042C98(s32 arg0) {
    s32 n;

    n = arg0 & 0xFFFF;
    D_80062B90[1] |= D_80062B98[n];
    return n < 3;
}

s32 func_80042CCC(s32 arg0) {
    D_80062B90[1] &= ~D_80062B98[arg0 & 0xFFFF];
    return 1;
}

s32 func_80042D00(s32 arg0) {
    s32 n;

    n = arg0 & 0xFFFF;
    if (n >= 3) {
        return 0;
    }
    D_80062B94[n].v = 0;
    return 1;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042D38);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042D48);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042D58);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042D68);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042D78);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042D98);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80042DC8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80043634);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80043644);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80043654);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_800436C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_800437AC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80043814);

DispEnv *func_800438D4(DispEnv *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->disp.x = arg1;
    arg0->disp.y = arg2;
    arg0->disp.w = arg3;
    arg0->screen.x = 0;
    arg0->screen.y = 0;
    arg0->screen.w = 0;
    arg0->screen.h = 0;
    arg0->isrgb24 = 0;
    arg0->isinter = 0;
    arg0->pad1 = 0;
    arg0->pad0 = 0;
    arg0->disp.h = arg4;
    return arg0;
}

s32 func_80043910(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80062BB4;
    D_80062BB4 = arg0;
    return temp_v0;
}

s32 func_80043928(void) {
    return D_80062BB4;
}
