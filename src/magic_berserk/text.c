#include "common.h"
#include "magic_berserk/decls.h"

void func_801B0018(void) {
    func_801B07D0();
}

INCLUDE_ASM("../asm/us/magic_berserk/nonmatchings/text", func_801B0038);

INCLUDE_ASM("../asm/us/magic_berserk/nonmatchings/text", func_801B0228);

INCLUDE_RODATA("../asm/us/magic_berserk/nonmatchings/text", D_801B000C);

void func_801B034C(void) {
    BsSpr t;
    MgTask *p;

    t = D_801B000C;
    p = (MgTask *)&D_80162978[D_8015169C];
    t.frame = p->unk2;
    func_800D4368(&p->unk8, 0x1500, 0);
    D_801EF334 = func_800D4D90(&t, D_801517C0 + 0x70, 0xC, D_801EF334);
    if (D_80062D98 == 0) {
        p->unk8 += p->unk10;
        p->unkA += p->unk12;
        p->unkC += p->unk14;
        p->unk12 -= 8;
        if (++p->unk2 >= 0xE) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_berserk/nonmatchings/text", func_801B0454);

void func_801B06B0(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0454)];
    p->unk6 = arg1;
    p->unk4 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk8);
    func_800D5774(arg0);
    func_800D55F4(0x20, func_800D56A8(D_80151A4C[arg0]), 0x42);
}

void func_801B0764(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EF334 = D_801D1334 + p->unk2 * 0xF000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B07D0(arg0, arg1) {
    s32 t;

    t = (func_800D54BC() >= 4) * 8;
    func_800D2980(&D_801B0858, 0, 0, 0);
    func_800BBEAC(func_801B0764);
    return func_800D5444(arg0, arg1, t, &func_801B06B0);
}
