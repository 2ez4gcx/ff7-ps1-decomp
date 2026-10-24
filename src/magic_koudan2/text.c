#include "common.h"
#include "magic_koudan2/decls.h"

void func_801B0030(void) {
    func_801B0FF0();
}

void func_801B0050(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E3A6C = D_801CBA6C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_koudan2/nonmatchings/text", func_801B00BC);

INCLUDE_ASM("../asm/us/magic_koudan2/nonmatchings/text", func_801B01E4);

INCLUDE_ASM("../asm/us/magic_koudan2/nonmatchings/text", func_801B0308);

INCLUDE_ASM("../asm/us/magic_koudan2/nonmatchings/text", func_801B0684);

INCLUDE_ASM("../asm/us/magic_koudan2/nonmatchings/text", func_801B07FC);

void func_801B0F30(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B07FC)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_koudan2/nonmatchings/text", func_801B0FF0);
