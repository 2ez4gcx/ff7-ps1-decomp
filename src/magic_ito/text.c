#include "common.h"
#include "magic_ito/decls.h"

void func_801B0000(void) {
    func_801B0D98();
}

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B0178);

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B0268);

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B02F4);

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B0440);

void func_801B0574(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u16 *, 4) + ((s32) (func_80039B40(M2C_FIELD(arg0, s16 *, 0x14)) * M2C_FIELD(arg0, s16 *, 0x18)) >> 0xC));
    M2C_FIELD(arg1, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 6);
    M2C_FIELD(arg1, s16 *, 4) = (s16) (M2C_FIELD(arg0, u16 *, 8) + ((s32) (func_80039A74(M2C_FIELD(arg0, s16 *, 0x14)) * M2C_FIELD(arg0, s16 *, 0x18)) >> 0xC));
}

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B0604);

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B076C);

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B0CA8);

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B0D98);
