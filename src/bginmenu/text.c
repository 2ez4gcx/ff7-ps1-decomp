#include "common.h"
#include "bginmenu/decls.h"

void func_801D0000(void) {
    u8 pad[8];

    func_80026448(&D_801D0860, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0U);
    func_80026448((u8 *)&D_801D0860 + 0x12, 0, 0, 1, 3, 0, 0, 1, 9, 0, 0, 0, 0, 0U);
    D_801D07F0 = 0;
}

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

s32 func_801D0704(s32 arg0) {
    s32 i;

    switch (arg0) {
    case 0:
        for (i = 0; i < 0x15; i++) {
            func_801D0324(D_801D082C[i]);
        }
        func_8002542C(0x49);
        break;
    case 1:
        for (i = 0; i < 0x10; i++) {
            func_801D0324(D_801D0844[i]);
        }
        func_8002542C(0x5A);
        break;
    case 2:
        for (i = 0; i < 7; i++) {
            func_801D0324(D_801D0854[i]);
        }
        func_8002542C(0x30);
        break;
    case 3:
        func_8002542C(0x58);
        break;
    }
}
