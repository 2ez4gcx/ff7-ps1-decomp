#include "common.h"
#include "magic_sflea/decls.h"

void func_801B0054(void) {
    func_801B1D3C();
}

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B0144);

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B0304);

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B04BC);

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B0674);

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B07C8);

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B0A3C);

void func_801B0BC4(void) {
    MgObj20 *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    frame = &D_801D3C80;
    *frame = D_801D3C48[p->unk2];
    D_801EBD50 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EBD50);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0C90(void) {
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
        D_801D3C8C[0] = 7 - (p->unk2 >> 1);
        t = p->unk2;
        c = 0x80;
        if (t >= 8) {
            c = 0x80 - (t - 8) * 0x15;
        }
        D_801D3C88 = D_801D3C89 = D_801D3C8A = c;
    } else {
        n = 7;
        u = p->unk2;
        a = 0x2000 - (u << 9);
        D_801D3C8C[0] = u;
    }
    func_800D4368(&p->unk4, (s16)a, p->unk14);
    D_801EBD50 = (u8 *)func_800D4D90(D_801D3C84, D_801517C0 + 0x70, 0xC, (s32)D_801EBD50);
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

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B0E10);

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B0F7C);

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B17C8);

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B1938);

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B1D3C);
