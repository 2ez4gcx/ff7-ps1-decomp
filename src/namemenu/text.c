#include "common.h"
#include "namemenu/decls.h"

void func_801D0014(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D0054);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D01CC);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D02C8);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D0328);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D0400);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D05BC);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D066C);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D0724);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D07D8);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D099C);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D1254);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D131C);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D14E8);

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

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D1738);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D1838);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D18B0);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D19CC);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D1AA0);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D1AF4);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D1B58);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D1BAC);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D1C10);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D1C90);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D1D84);
