#include "common.h"
#include "magic_smog2/decls.h"

void func_801B0000(void) {
    func_801B0E84();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E9A18 = D_801D1A18 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, D_801D19D4[p->unk16], 0);
    D_801D19D0[0] = p->unk2;
    *(s32 *)&D_801D19D0[-4] = D_801D19E4[p->unk16];
    D_801E9A18 = func_800D4D90(&D_801D19D0[-4], D_801517C0 + 0x70, 0xC, D_801E9A18);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == ((s32 *)D_801D19E4[p->unk16])[1]) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_smog2/nonmatchings/text", func_801B0190);

void func_801B0458(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    func_801B0190(8, p->unk16, 0x320, 0x78 - p->unk2 * 6);
    p->unk16 += 0x100;
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC -= p->unkC / 8;
        p->unkE -= p->unkE / 8;
        p->unk10 -= p->unk10 / 8;
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0590(void) {
    MgTask *p;
    MgByte *q;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, D_801D1A0C[p->unk14] * 0x18000 >> 16, 0);
    c = -0x80 - p->unk2 * 4;
    q = &D_801D1A04;
    q->v = D_801D1A05.v = D_801D1A06.v = c;
    D_801E9A18 = func_800D4D90((u8 *)q - 4, D_801517C0 + 0x70, 0xC, D_801E9A18);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (++p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_smog2/nonmatchings/text", func_801B06B4);

void func_801B0DC4(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B06B4)];
    func_800D3994(arg1, D_8015190F[arg1][9], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk18 = arg0;
}

s32 func_801B0E84(arg0, arg1) {
    func_800BBEAC(func_801B0020);
    func_800D2980(&D_801B0F00, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0DC4);
    return func_800BBA84(0x8A, arg1, 0x40);
}
