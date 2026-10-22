#include "common.h"
#include "magic_knights/decls.h"

void func_801B0050(void) {
    func_801BE87C();
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B0070);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B018C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B0264);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B02E8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B0DA8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B1244);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B15E8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B1C30);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B1E40);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B1E7C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B1F74);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B2048);

void func_801B3154(s32 arg0, s32 arg1, s16 arg2) {
    D_8016207C = &func_801B2048;
    D_801635D8 = 0;
    D_801635E4 = arg0;
    D_801635E8 = arg1;
    D_801635EC = arg2;
    D_80162080 += 1;
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B31A0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B32DC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B3350);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B33E0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B3748);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B3890);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B3DB0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B40F4);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4198);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B440C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4694);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4B04);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4B70);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4BF8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4E78);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5670);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B56D4);

void func_801B5B24(void *arg0) {
    s32 temp_a1;
    s32 temp_v0;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0xBA0);
    if (temp_a1 != -1) {
        temp_v0 = func_800D376C(arg0 + 0x40, temp_a1, M2C_FIELD(arg0, s16 *, 0xBA4), M2C_FIELD(arg0, s32 *, 0xB9C));
        M2C_FIELD(arg0, s32 *, 0xBA0) = temp_v0;
        if (temp_v0 == 0) {
            M2C_FIELD(arg0, s32 *, 0xBA0) = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5B7C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5C5C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5E4C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5F0C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B603C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B6248);

void func_801B62D4(void *arg0) {
    M2C_UNK sp10;

    func_801B0264(arg0 + ((M2C_FIELD(arg0, s16 *, 0xBB0) * 0x34) + 0x40), &sp10);
    func_801B603C(&sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B631C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B63E4);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B6624);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B6690);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B66C4);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B67C4);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B6B78);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B6BAC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B6CAC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B6F9C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B7090);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B72AC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B7498);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B786C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B7C28);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B7C84);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8014);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8070);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B831C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8388);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B85F8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8744);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8924);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8A00);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8D7C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8DB0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8EB0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B91C8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9408);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9700);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9834);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9AA0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9DF0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9E4C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BA230);

void func_801BA29C(void) {
    func_801B6624(&D_801ECCD4, &D_801ECCF4);
    func_800D5444(D_801EE9CC, 0, 0, &func_801BA230);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BA2E8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BA598);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BA604);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BA964);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BAAFC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BAB58);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BAD78);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BAF80);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB270);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB500);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB548);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB6EC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB8C4);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BBA64);

void *func_801BBC20(void *arg0, s32 arg1, void *arg2) {
    void *temp_s2;

    M2C_FIELD(arg2, s32 *, 0) = 0x04000000;
    M2C_FIELD(arg2, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(arg2, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(arg2, u8 *, 0xC) = (u8) M2C_FIELD(arg0, u8 *, 4);
    M2C_FIELD(arg2, u8 *, 0xD) = (u8) M2C_FIELD(arg0, u8 *, 6);
    M2C_FIELD(arg2, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x12);
    M2C_FIELD(arg2, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 8);
    func_80046794(arg1, (s32) arg2);
    temp_s2 = arg2 + 0x14;
    func_80044A68(temp_s2, 0, 1, (s32) M2C_FIELD(arg0, u16 *, 0x10), 0);
    func_80046794(arg1, (s32) temp_s2);
    return arg2 + 0x20;
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BBCE0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BBEC8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC0E0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC334);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC65C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC6BC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC71C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC778);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC838);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC8D4);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC950);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC99C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BCB04);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BCF1C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD080);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD2D0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD718);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD758);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD7FC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD870);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BE87C);
