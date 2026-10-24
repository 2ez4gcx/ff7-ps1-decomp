#include "common.h"
#include "magic_echoes/decls.h"

void func_801B0000(void) {
    func_801B0404();
}

INCLUDE_ASM("../asm/us/magic_echoes/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_echoes/nonmatchings/text", func_801B0108);

INCLUDE_ASM("../asm/us/magic_echoes/nonmatchings/text", func_801B02BC);

void func_801B03A4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D687C = D_801B687C + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0404(arg0, arg1) {
    func_800D2980(&D_801B0474, 0, 0, 0);
    func_800BBEAC(&func_801B03A4);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B02BC);
}
