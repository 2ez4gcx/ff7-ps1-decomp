#include "common.h"
#include "magic_wep4/decls.h"

void func_801B0054(void) {
    func_801B39A8();
}

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B0178);

void func_801B08D0(void) {
    MgSVec rot;
    MgMat m;
    u8 pad[0x20];
    MgVec v;
    MgTask *p;
    s32 u;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unkC;
    rot.vy = 0;
    rot.vz = p->unk10;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk14;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    u = D_801D4F18[p->unk18];
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = (void *)u;
    if (p->unk2 >= p->unk1E) {
        ((MgScratch *)0x1F800000)->unk4 = 8;
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - p->unk1E) * 0x15;
    }
    D_801ECF6C = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801ECF6C);
    if (p->unk2 >= p->unk1C) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk6 += p->unkE;
        p->unkE += p->unk12;
        if (p->unkE >= -0x31) {
            p->unkE = -0x32;
        } else {
            p->unk12 += p->unk12 >> 4;
        }
        p->unkC += p->unk16;
        p->unk10 += p->unk1A;
        p->unk2++;
    }
}

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

void func_801B2918(void) {
    MgTask *p;
    u16 *frame;
    u16 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801D4F50;
    *frame = p->unk2;
    t = p->unk14;
    func_800D4368(&p->unk4, (s16)t, -((s16)t >> 3));
    D_801ECF6C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801ECF6C);
    if (p->unk2 >= 0xF) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC -= p->unkC >> 4;
        p->unkE -= p->unkE >> 4;
        p->unk10 -= p->unk10 >> 4;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_wep4/nonmatchings/text", func_801B2A4C);

void func_801B3934(void) {
    u8 pad[8];
    D_80162978[D_8015169C].unk0 = -1;
    D_80162994[func_800BBEAC(func_801B2A4C)].unk0 = 0;
    func_800D54EC(D_801ECF74, D_801ECF7C);
}

INCLUDE_RODATA("../asm/us/magic_wep4/nonmatchings/text", D_801B0000);

void func_801B39A8(arg0, arg1) {
    s32 i;
    s32 n;

    D_801ECF70 = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(&D_801B3A98, 0, 0, 0);
    func_800BBEAC(func_801B3934);
    i = 0;
    D_801ECF74 = arg0;
    D_801EF534 = 0;
    do {
        if ((arg0 >> i) & 1) {
            n = D_801EF534;
            D_801EF50C[n] = i;
            D_801EF534 = n + 1;
        }
        i++;
    } while (i < 10);
    D_801ECF78 = arg1;
    D_800FAFDC = 1;
}
