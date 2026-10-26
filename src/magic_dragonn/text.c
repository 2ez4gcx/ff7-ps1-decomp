#include "common.h"
#include "magic_dragonn/decls.h"

void func_801B0054(void) {
    func_801B0A54();
}

void func_801B0074(void) {
    MgSVec rot;
    MgMat m;
    MgVec s;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    p = &D_80162978[D_8015169C];
    rot.vz = p->unkC;
    func_8003BF8C(&rot, &m);
    s.vx = s.vy = s.vz = p->unk14;
    func_8003B35C(&m, &s);
    func_800D4284(&p->unk4, -(p->unk14 >> 2), &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801DA954 = func_800D4D90(D_801C2918, D_801517C0 + 0x70, 0xC, D_801DA954);
    if (p->unk2 >= 0x34) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        if (p->unk2 < 0xC) {
            p->unk14 += p->unk12;
        } else if (p->unk2 >= 0x28) {
            p->unk14 -= p->unk16;
        } else {
            p->unk14 = p->unk10;
        }
        p->unk2++;
    }
}

void func_801B01D8(void) {
    MgSVec rot;
    MgMat m;
    MgVec s;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    p = &D_80162978[D_8015169C];
    rot.vz = p->unkC;
    func_8003BF8C(&rot, &m);
    s.vx = s.vy = s.vz = p->unk14;
    func_8003B35C(&m, &s);
    func_800D4284(&p->unk4, -(p->unk14 >> 2), &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801C26FC;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801DA954 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DA954);
    if (p->unk2 >= 0x34) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        if (p->unk2 < 0xC) {
            p->unk14 += p->unk12;
        } else if (p->unk2 >= 0x28) {
            p->unk14 -= p->unk16;
        } else {
            p->unk14 = p->unk10;
        }
        p->unk2++;
    }
}

void func_801B037C(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;
    s32 t;
    void *a;
    s16 w;
    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk10;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    a = D_801C2924[p->unk18];
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = a;
    t = p->unk2;
    if (t < 8) {
        ((MgScratch *)0x1F800000)->unkA = 0x1000 - (t << 9);
    }
    func_8003B69C(0, 0, 0);
    D_801DA954 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DA954);
    if (p->unk2 >= 0xC) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        w = p->unk10 - p->unk12;
        p->unk10 = w;
        if (w < 0) {
            p->unk10 = 0;
        }
        p->unk2++;
    }
}

void func_801B054C(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;
    MgScratch *sp;
    s32 t;
    void *a;
    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk10;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    a = D_801C2934[p->unk18];
    sp = (MgScratch *)0x1F800000;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    sp->unk0 = a;
    t = p->unk2;
    if (t >= 4) {
        t = (t - 4) << 9;
        ((MgScratch *)0x1F800000)->unkA = t;
        if ((s16)t > 0x1000) {
            ((MgScratch *)0x1F800000)->unkA = 0x1000;
        }
    }
    func_8003B69C(0, 0, 0);
    D_801DA954 = func_800D29D4(sp, D_801517C0 + 0x70, 0xC, D_801DA954);
    if (p->unk2 >= 0xC) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk10 += p->unk12;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_dragonn/nonmatchings/text", func_801B0720);

INCLUDE_ASM("../asm/us/magic_dragonn/nonmatchings/text", func_801B08E0);

INCLUDE_RODATA("../asm/us/magic_dragonn/nonmatchings/text", D_801B0000);

s32 func_801B0A54(arg0) {
    s32 i;
    s32 n;

    D_801DA958 = &D_80162978[func_800BBEAC((M2C_UNK *)D_801B0000)];
    func_800D2980(&D_801B0B20, 0, 0, 0);
    for (i = 0, n = 0; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801DA95C = i;
            }
        }
    }
    func_800BBEAC((M2C_UNK *)func_801B08E0);
    return func_800D55F4(0x20, func_800D574C(arg0), 0x130);
}
