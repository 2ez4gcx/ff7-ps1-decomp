#include "common.h"
#include "brom/decls.h"

void func_800A0000(void) {
    func_80043938(0);
    func_80043BA8(0);
    func_80043D3C(1);
    func_800438D4(&D_800A0728, 0, 0xE8, 0x140, 0xF0);
    func_80043814(&D_800A06CC, 0, 0xF0, 0x140, 0xE0);
    D_800A0739 = 0;
    D_800A06E3 = 1;
    D_800A06E2 = 0;
    D_800A06E4 = 0;
    D_800A06E0 = 0;
    func_8003CEDC(0);
    func_800444AC(&D_800A0728);
    func_800443B0(&D_800A06CC);
}

INCLUDE_ASM("../asm/us/brom/nonmatchings/text", func_800A00CC);

void func_800A015C(void) {
    if (func_80017108(0x801B0000, 0x801C0000) > 0) {
        func_800A0534(0x801C0000);
        func_800A05D4(0x801C0000, -1, -1);
    }
}

INCLUDE_ASM("../asm/us/brom/nonmatchings/text", func_800A01A0);

INCLUDE_ASM("../asm/us/brom/nonmatchings/text", func_800A0514);

INCLUDE_ASM("../asm/us/brom/nonmatchings/text", func_800A0534);

INCLUDE_ASM("../asm/us/brom/nonmatchings/text", func_800A05D4);
