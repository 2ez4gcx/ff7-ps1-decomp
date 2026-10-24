#include "common.h"
#include "magic_bio/decls.h"

INCLUDE_ASM("../asm/us/magic_bio/nonmatchings/text", func_801B0000);

void func_801B0178(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    frame = &D_801B7884;
    *frame = p->unk2;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801D7888 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801D7888);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 6) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_bio/nonmatchings/text", func_801B0238);

void func_801B0554(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0238)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk8);
}

void func_801B05E0(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D7888 = D_801B7888 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0640(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B06C8, 0, 0, 0);
    func_800BBEAC(&func_801B05E0);
    func_800D5444(arg0, arg1, 0, &func_801B0554);
    func_800D55F4(0x20, func_800D574C(arg0), 0x3F);
}
