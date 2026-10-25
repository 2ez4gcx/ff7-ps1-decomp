#include "common.h"
#include "magic_trainn/decls.h"

void func_801B0054(void) {
    func_801B0658();
}

void func_801B0074(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;
    MgScratch *s;
    s32 c;
    s32 i;
    s32 bit;
    s16 f;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unkC;
    rot.vy = p->unk10;
    rot.vz = p->unk14;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk18;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    s = (MgScratch *)0x1F800000;
    c = 0x80;
    s->unk0 = &D_801C0810;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x2C) {
        ((MgScratch *)0x1F800000)->unkA = c - (p->unk2 - 0x2C) * 10;
        if (((MgScratch *)0x1F800000)->unkA < 0) {
            ((MgScratch *)0x1F800000)->unkA = 0;
        }
    }
    D_801D9134 = func_800D29D4(s, D_801517C0 + 0x70, 0xC, D_801D9134);
    if (p->unk2 < 8) {
        D_800F5B70.r = D_800F5B70.g = 0x30;
        D_800F5B70.b = 0;
        f = p->unk2 * 0x180;
    } else if (p->unk2 >= 0x34) {
        f = 0xC00 - (p->unk2 - 0x34) * 0x180;
        if (f < 0) {
            f = 0;
        }
    } else {
        f = 0xC00;
    }
    if (p->unk2 >= 0x3C) {
        f = 0;
        D_800F5B70.r = D_800F5B70.g = 0;
        p->unk0 = -1;
    }
    D_800F5B70.f = f;
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x31) {
            for (i = 0, bit = 1; i < 10; i++) {
                if ((bit << i) & D_801D913C) {
                    func_800D5774(i);
                }
            }
        }
        p->unkC += p->unkE;
        p->unk10 += p->unk12;
        p->unk14 += p->unk16;
        if (p->unk2 < 0x12) {
            p->unk18 += p->unk1A;
        }
        p->unk2++;
    }
}

void func_801B0354(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;
    MgScratch *s;
    s32 c;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unkC;
    rot.vy = p->unk10;
    rot.vz = p->unk14;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk18;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    s = (MgScratch *)0x1F800000;
    c = 0x80;
    s->unk0 = &D_801C0810;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x2C) {
        ((MgScratch *)0x1F800000)->unkA = c - (p->unk2 - 0x2C) * 10;
        if (((MgScratch *)0x1F800000)->unkA < 0) {
            ((MgScratch *)0x1F800000)->unkA = 0;
        }
    }
    D_801D9134 = func_800D29D4(s, D_801517C0 + 0x70, 0xC, D_801D9134);
    if (p->unk2 >= 0x3C) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk10 += p->unk12;
        p->unk14 += p->unk16;
        if (p->unk2 < 0x12) {
            p->unk18 += p->unk1A;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_trainn/nonmatchings/text", func_801B054C);

INCLUDE_RODATA("../asm/us/magic_trainn/nonmatchings/text", D_801B0000);

s32 func_801B0658(arg0) {
    D_801D9138 = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(&D_801B06F0, 0, 0, 0);
    func_800BBEAC(&func_801B054C);
    D_801D913C = arg0;
    return func_800D55F4(0x20, func_800D574C(arg0), 0xA0);
}
