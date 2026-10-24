#include "common.h"
#include "magic_lasboss2/decls.h"

void func_801B0000(void) {
    func_801B1834();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E5EE8 = D_801CDEE8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B013C);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0248);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0338);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0410);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B04F4);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B05FC);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B06DC);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0824);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0948);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0A34);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0B3C);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0C28);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0D8C);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B1024);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B1834);
