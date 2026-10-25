#include "common.h"
#include "magic_wep4/decls.h"

void func_801B0054(void) {
    func_801B39A8();
}

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B0178);

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B08D0);

void func_801B0B0C(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s16 k;

    p = &D_80162978[D_8015169C];
    if (p->unk1C > 0) {
        if (D_80062D98 == 0) {
            p->unk1C--;
        }
        return;
    }
    rot.vx = 0;
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    k = p->unk14;
    scale.vx = scale.vz = k;
    scale.vy = p->unk18;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801D3D68;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0xC) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0xC) * 0x10;
    }
    D_801ECF6C = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801ECF6C);
    if (p->unk2 >= 0x14) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk18 += p->unk1A;
        p->unk1A -= p->unk1A / 2;
        if (p->unk18 < 0) {
            p->unk18 = 0;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B0D1C);

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B1044);

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B1348);

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B164C);

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B1CE0);

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B2320);

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B2918);

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B2A4C);

void func_801B3934(void) {
    u8 pad[8];
    D_80162978[D_8015169C].unk0 = -1;
    D_80162994[func_800BBEAC(func_801B2A4C)].unk0 = 0;
    func_800D54EC(D_801ECF74, D_801ECF7C);
}

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B39A8);
