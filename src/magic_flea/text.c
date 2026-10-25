#include "common.h"
#include "magic_flea/decls.h"

void func_801B0054(void) {
    func_801B15CC();
}

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B0234);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B03EC);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B05A4);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B06F8);

void func_801B0880(void) {
    MgObj20 *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    frame = &D_801D3508;
    *frame = D_801D34D0[p->unk2];
    D_801EB5D8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EB5D8);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B094C(void) {
    MgTask *p;
    s32 n;
    s32 t;
    s32 u;
    s32 c;
    u16 a;
    u8 pad[8];

    p = (MgTask *)&D_80162978[D_8015169C];
    n = 0xE;
    if (p->unk18 != 0) {
        a = p->unk16;
        D_801D3514[0] = 7 - (p->unk2 >> 1);
        t = p->unk2;
        c = 0x80;
        if (t >= 8) {
            c = 0x80 - (t - 8) * 0x15;
        }
        D_801D3510 = D_801D3511 = D_801D3512 = c;
    } else {
        n = 7;
        u = p->unk2;
        a = 0x2000 - (u << 9);
        D_801D3514[0] = u;
    }
    func_800D4368(&p->unk4, (s16)a, p->unk14);
    D_801EB5D8 = (u8 *)func_800D4D90(D_801D350C, D_801517C0 + 0x70, 0xC, (s32)D_801EB5D8);
    if (p->unk2 >= n) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B0ACC);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B0E34);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B147C);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B15CC);
