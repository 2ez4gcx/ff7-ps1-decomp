#include "common.h"
#include "magic_missile/decls.h"

void func_801B0000(void) {
    func_801B0AB0();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E19E8 = D_801C99E8 + p->unk2 * 0xC000;
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
    frame = &D_801C99A8;
    *frame = p->unk2;
    D_801E19E8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E19E8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C981C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_missile/nonmatchings/text", func_801B0148);

INCLUDE_ASM("../asm/us/magic_missile/nonmatchings/text", func_801B0704);

void func_801B09F0(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0704)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B0AB0(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B0B2C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B09F0);
    func_800BBA84(0x82, arg1, 0x40);
}
