#include "common.h"
#include "magic_ayasii/decls.h"

void func_801B0054(void) {
    func_801B04E4();
}

INCLUDE_ASM("../asm/us/magic_ayasii/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_ayasii/nonmatchings/text", func_801B0190);

INCLUDE_ASM("../asm/us/magic_ayasii/nonmatchings/text", func_801B0428);

INCLUDE_RODATA("../asm/us/magic_ayasii/nonmatchings/text", D_801B0000);

void func_801B04E4(arg0) {
    D_801CE990 = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(D_801B0584, 0, 0, 0);
    func_800BBEAC(func_801B0428);
    D_801CE994 = arg0;
    D_801CE998 = 0;
    func_800D55F4(0x20, func_800D574C(arg0), 0xA2);
}
