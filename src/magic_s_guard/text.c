#include "common.h"
#include "magic_s_guard/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0B5C();
    return &D_801B10DC;
}

INCLUDE_ASM("../asm/us/magic_s_guard/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_s_guard/nonmatchings/text", func_801B0200);

INCLUDE_ASM("../asm/us/magic_s_guard/nonmatchings/text", func_801B0228);

INCLUDE_ASM("../asm/us/magic_s_guard/nonmatchings/text", func_801B0268);

INCLUDE_ASM("../asm/us/magic_s_guard/nonmatchings/text", func_801B0444);

INCLUDE_ASM("../asm/us/magic_s_guard/nonmatchings/text", func_801B064C);

void func_801B09F0(void) {
    MgObj20 *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 == 0x20) {
            func_800D55F4(0x20, func_800D574C(D_801D3B8C), 0x7D);
            temp_s0->unk0 = -1;
        }
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

void func_801B0A7C(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B064C)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

void func_801B0AFC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D3B88 = D_801B3B88 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_s_guard/nonmatchings/text", func_801B0B5C);
