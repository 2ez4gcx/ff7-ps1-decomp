#include "common.h"
#include "bginmenu/decls.h"

INCLUDE_ASM("../asm/us/bginmenu/nonmatchings/text", func_801D0000);

INCLUDE_ASM("../asm/us/bginmenu/nonmatchings/text", func_801D00C4);

void func_801D01BC(void) {
}

INCLUDE_ASM("../asm/us/bginmenu/nonmatchings/text", func_801D01C4);

s32 func_801D0258(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0) | (M2C_FIELD(arg0, u8 *, 1) << 8);
}

void func_801D026C(u8 *arg0, u16 arg1) {
    arg0[0] = arg1;
    arg0[1] = arg1 >> 8;
}

INCLUDE_ASM("../asm/us/bginmenu/nonmatchings/text", func_801D027C);

INCLUDE_ASM("../asm/us/bginmenu/nonmatchings/text", func_801D0324);

INCLUDE_ASM("../asm/us/bginmenu/nonmatchings/text", func_801D0408);

INCLUDE_ASM("../asm/us/bginmenu/nonmatchings/text", func_801D0500);

INCLUDE_ASM("../asm/us/bginmenu/nonmatchings/text", func_801D05C4);

INCLUDE_ASM("../asm/us/bginmenu/nonmatchings/text", func_801D0704);
