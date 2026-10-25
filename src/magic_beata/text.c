#include "common.h"
#include "magic_beata/decls.h"

void func_801B0054(void) {
    func_801B1184();
}

void func_801B0074(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s16 k;
    s32 c;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    k = p->unk10;
    scale.vy = scale.vz = k;
    scale.vz = scale.vx = (s16)(k / 3) + k;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    ((MgScratch *)0x1F800000)->unk0 = D_801C133C;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x2A) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0x2A) * 0x10;
    }
    D_801DAD30 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DAD30);
    if (p->unk2 >= 0x32) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk2++;
    }
}

void func_801B0238(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s16 k;
    s32 c;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    k = p->unk10;
    scale.vy = scale.vz = k;
    scale.vz = scale.vx = (s16)(k / 3) + k;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    ((MgScratch *)0x1F800000)->unk0 = D_801C2130;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x2A) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0x2A) * 0x10;
    }
    D_801DAD30 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DAD30);
    if (p->unk2 >= 0x32) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_beata/nonmatchings/text", func_801B03FC);

INCLUDE_ASM("../asm/us/magic_beata/nonmatchings/text", func_801B0620);

INCLUDE_ASM("../asm/us/magic_beata/nonmatchings/text", func_801B0A04);

INCLUDE_ASM("../asm/us/magic_beata/nonmatchings/text", func_801B0C90);

INCLUDE_ASM("../asm/us/magic_beata/nonmatchings/text", func_801B0E28);

INCLUDE_ASM("../asm/us/magic_beata/nonmatchings/text", func_801B10DC);

INCLUDE_ASM("../asm/us/magic_beata/nonmatchings/text", func_801B1184);
