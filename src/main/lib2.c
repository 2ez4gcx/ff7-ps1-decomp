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

char *func_8003DDBC(s32 arg0) {
    u32 i;

    i = arg0 & 0xFF;
    if (i >= 0x1C) {
        return D_80010668;
    }
    return D_8005164C[i];
}

char *func_8003DDF4(s32 arg0) {
    u32 i;

    i = arg0 & 0xFF;
    if (i >= 7) {
        return D_80010668;
    }
    return D_800516CC[i];
}

void func_8003DE2C(void) {
    func_8003E9DC();
}

void func_8003DE4C(void) {
    func_8003EC60();
}

s32 func_8003DE6C(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80051628;
    D_80051628 = arg0;
    return temp_v0;
}

s32 func_8003DE84(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_8005162C;
    D_8005162C = arg0;
    return temp_v0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003DE9C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003DFD4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003E100);

s32 func_8003E244(void) {
    func_8003F398();
    return 1;
}

s32 func_8003E268(void) {
    return func_8003F99C() == 0;
}

void func_8003E28C(s32 arg0) {
    func_8003D120(3, arg0);
}

void func_8003E2B0(void) {
    func_8003F830();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003E2D0);

s32 func_8003E3D4(void *arg0) {
    u8 temp_a1;
    u8 temp_a2;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0);
    temp_a2 = M2C_FIELD(arg0, u8 *, 1);
    temp_a1 = M2C_FIELD(arg0, u8 *, 2);
    return (((((((temp_v1 >> 4) * 0xA) + (temp_v1 & 0xF)) * 0x3C) + (((temp_a2 >> 4) * 0xA) + (temp_a2 & 0xF))) * 0x4B) + (((temp_a1 >> 4) * 0xA) + (temp_a1 & 0xF))) - 0x96;
}

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib2", D_80010668);

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib2", D_800107AC);

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib2", D_800107BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003E454);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003E9DC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003EC60);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003EF30);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003F398);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003F420);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003F500);

void func_8003F5F4(void) {
    D_8005162C = 0;
    D_80051628 = 0;
    D_8005163C = 0;
    *(s32 *) &D_80051638 = 0;
    func_8003D0C0();
    func_8003D0F0(2, (s32) &func_8003FAAC);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003F644);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003F830);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003F99C);

void func_8003FA9C(s32 arg0) {
    D_800518D0 = arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003FAAC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003FB8C);

s32 func_8003FE74(s32 arg0, s32 arg1) {
    return func_80042D78(arg0, arg1, 0xC) == 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003FE98);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8004018C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_80040238);
