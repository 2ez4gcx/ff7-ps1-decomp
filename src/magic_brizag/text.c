#include "common.h"
#include "magic_brizag/decls.h"

void func_801B0054(void) {
    func_801B324C();
}

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B0368);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B03C0);

s32 func_801B0A8C(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801C0DB0[a];
        } else {
            r = D_801C0DB0[0x800 - a];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801C0DB0[a - 0x800];
        } else {
            r = -D_801C0DB0[0x1000 - a];
        }
    }
    return r;
}

s32 func_801B0B30(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801C0DB0[0x400 - a];
        } else {
            r = -D_801C0DB0[a - 0x400];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801C0DB0[0xC00 - a];
        } else {
            r = D_801C0DB0[a - 0xC00];
        }
    }
    return r;
}

void func_801B0BCC(s16 *arg0, s16 *arg1, s32 *arg2) {
    s32 cx;
    s32 cy;
    s32 cz;
    s32 sx;
    s32 sy;
    s32 sz;
    s32 m0;
    s32 m1;
    s32 m2;
    s32 m3;
    s32 m4;
    s32 m5;
    s32 m6;
    s32 m7;
    s32 m8;

    cx = func_801B0B30(arg0[0]);
    cy = func_801B0B30(arg0[1]);
    cz = func_801B0B30(arg0[2]);
    sx = func_801B0A8C(arg0[0]);
    sy = func_801B0A8C(arg0[1]);
    sz = func_801B0A8C(arg0[2]);
    m0 = (((cz * cy) >> 12) * arg2[0]) >> 12;
    m3 = ((((sz * cx) >> 12) - (((cz * -sy >> 12) * sx) >> 12)) * arg2[0]) >> 12;
    m6 = ((((sz * sx) >> 12) + (((cz * -sy >> 12) * cx) >> 12)) * arg2[0]) >> 12;
    m1 = (((-sz * cy) >> 12) * arg2[1]) >> 12;
    m4 = ((((cz * cx) >> 12) + (((sz * -sy >> 12) * sx) >> 12)) * arg2[1]) >> 12;
    m7 = ((((cz * sx) >> 12) - (((sz * -sy >> 12) * cx) >> 12)) * arg2[1]) >> 12;
    m2 = (sy * arg2[2]) >> 12;
    m5 = (((-cy * sx) >> 12) * arg2[2]) >> 12;
    m8 = (((cy * cx) >> 12) * arg2[2]) >> 12;
    arg1[0] = m0;
    arg1[3] = m3;
    arg1[6] = m6;
    arg1[1] = m1;
    arg1[4] = m4;
    arg1[7] = m7;
    arg1[2] = m2;
    arg1[5] = m5;
    arg1[8] = m8;
}

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B0DD0);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B0E48);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B1114);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B116C);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B15A8);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B16B0);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B19FC);

void func_801B1D3C(void) {
    MgSVec rot;
    MgSVec pad;
    MgSVec v;
    MgMat m;
    MgMat pad2;
    MgVec scale;
    MgTask *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unkC;
    rot.vy = p->unkE;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    v.vx = 0;
    v.vy = -p->unk14;
    v.vz = 0;
    func_8003B27C(&m, &v, (MgVec *)m.t);
    m.t[0] += p->unk4;
    m.t[1] += p->unk6;
    m.t[2] += p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk10;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801BF388;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801D95FC = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D95FC);
    if (p->unk2 >= p->unk18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        t = p->unk14 - p->unk16;
        p->unk14 = t;
        if (t < 0) {
            p->unk14 = 0;
        }
        p->unk2++;
    }
}

void func_801B1F08(void) {
    MgSVec rot;
    s32 c;
    MgSVec pad;
    MgSVec v;
    MgMat m;
    MgMat pad2;
    MgVec scale;
    MgTask *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unkC;
    rot.vy = p->unkE;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    v.vx = 0;
    v.vy = -p->unk14;
    v.vz = 0;
    func_8003B27C(&m, &v, (MgVec *)m.t);
    m.t[0] += p->unk4;
    m.t[1] += p->unk6;
    m.t[2] += p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk10;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    ((MgScratch *)0x1F800000)->unk0 = D_801BF388;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= p->unk18) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - p->unk18) * 0x15;
    }
    D_801D95FC = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D95FC);
    if (p->unk2 >= p->unk18 + 6) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        t = p->unk14 - p->unk16;
        p->unk14 = t;
        if (t < 0) {
            p->unk14 = 0;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B210C);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B254C);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B2DF0);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B303C);

INCLUDE_RODATA("../asm/us/magic_brizag/nonmatchings/text", D_801B0000);

void func_801B324C(arg0) {
    D_801D9600 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B32C8, 0, 0, 0);
    func_800BBEAC(&func_801B303C);
    D_801D9604 = arg0;
}
