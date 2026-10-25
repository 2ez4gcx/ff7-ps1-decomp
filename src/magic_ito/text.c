#include "common.h"
#include "magic_ito/decls.h"

void func_801B0000(void) {
    func_801B0D98();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CD578 = D_801B5578 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B0178);

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B0268);

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B02F4);

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B0440);

void func_801B0574(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u16 *, 4) + ((s32) (func_80039B40(M2C_FIELD(arg0, s16 *, 0x14)) * M2C_FIELD(arg0, s16 *, 0x18)) >> 0xC));
    M2C_FIELD(arg1, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 6);
    M2C_FIELD(arg1, s16 *, 4) = (s16) (M2C_FIELD(arg0, u16 *, 8) + ((s32) (func_80039A74(M2C_FIELD(arg0, s16 *, 0x14)) * M2C_FIELD(arg0, s16 *, 0x18)) >> 0xC));
}

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B0604);

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B076C);

void func_801B0CA8(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B076C)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    if (p->unk8 > p->unk10) {
        D_801B5550 = -1;
    }
    func_800BBEAC((void *)func_801B0440);
}

INCLUDE_ASM("../asm/us/magic_ito/nonmatchings/text", func_801B0D98);
