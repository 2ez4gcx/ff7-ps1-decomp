#include "common.h"
#include "magic_laser2/decls.h"

void func_801B0010(void) {
    func_801B0E20();
}

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B0030);

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B009C);

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B01F8);

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B02B4);

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B0340);

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B0558);

void func_801B065C(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u16 *, 4) + ((s32) (func_80039B40(M2C_FIELD(arg0, s16 *, 0x14)) * M2C_FIELD(arg0, s16 *, 0x18)) >> 0xC));
    M2C_FIELD(arg1, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 6);
    M2C_FIELD(arg1, s16 *, 4) = (s16) (M2C_FIELD(arg0, u16 *, 8) + ((s32) (func_80039A74(M2C_FIELD(arg0, s16 *, 0x14)) * M2C_FIELD(arg0, s16 *, 0x18)) >> 0xC));
}

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B06EC);

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B082C);

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B0D30);

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B0E20);
