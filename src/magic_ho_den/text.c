#include "common.h"
#include "magic_ho_den/decls.h"

void func_801B0000(void) {
    func_801B10B0();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EED84 = D_801D6D84 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D6C64;
    *frame = p->unk2;
    D_801EED84 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EED84);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D6AD8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_ho_den/nonmatchings/text", func_801B0148);

INCLUDE_ASM("../asm/us/magic_ho_den/nonmatchings/text", func_801B027C);

INCLUDE_ASM("../asm/us/magic_ho_den/nonmatchings/text", func_801B04E4);

INCLUDE_ASM("../asm/us/magic_ho_den/nonmatchings/text", func_801B06C4);

INCLUDE_ASM("../asm/us/magic_ho_den/nonmatchings/text", func_801B09CC);

INCLUDE_ASM("../asm/us/magic_ho_den/nonmatchings/text", func_801B0B10);

INCLUDE_ASM("../asm/us/magic_ho_den/nonmatchings/text", func_801B0F70);

void func_801B10B0(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B111C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0F70);
}
