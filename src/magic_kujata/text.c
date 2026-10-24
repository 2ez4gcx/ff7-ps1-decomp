#include "common.h"
#include "magic_kujata/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B88A4();
    return &D_801DDD1C;
}

MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EFCE0.m[0][0] = D_801EFCE0.m[1][1] = D_801EFCE0.m[2][2] = scale;
    func_8003B48C(&D_801F04C8);
    func_8003B51C(&D_801F04C8);
    func_8003BC6C(v, (MgVec *)D_801EFCE0.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EFCE0.t, &n);
        D_801EFCE0.t[0] += (dist * n.vx) >> 12;
        D_801EFCE0.t[1] += (dist * n.vy) >> 12;
        D_801EFCE0.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EFCE0);
    func_8003B51C(&D_801EFCE0);
    return &D_801EFCE0;
}

s32 func_801B0184(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F04FA[-v];
    }
    return v;
}

s32 func_801B01C0(s32 t, s32 s) {
    s32 orig;
    s32 i;
    s32 n;

    orig = t;
    if (s > 0) {
        n = s >> 8;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
    } else {
        s = -s;
        n = s >> 8;
        t = 0x1000 - t;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
        t = 0x1000 - t;
    }
    n = (s & 0xFF) + 1;
    t = (t * n + orig * (0x100 - n)) >> 8;
    return t;
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B02B0);

void func_801B12E4(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B02B0)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B1348);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B1AF4);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B2250);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B292C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B2DB8);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B3878);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B3C60);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B3D20);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B3DE4);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B3EA8);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B42B8);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B4570);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B4B88);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B4D10);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B500C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B521C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B536C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B54CC);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B575C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B5AE0);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B5C98);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B5D88);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B5EDC);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B6034);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B62C0);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B6500);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B6644);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B666C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B66F8);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B68C4);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B6C18);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B6CE0);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B7028);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B7208);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B731C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B7438);

void func_801B75D8(void) {
    MgMat m;

    D_801F0364 = D_801EFC88;
    D_801F0354 = D_801EFC88;
    if (D_801EFCAA != 0) {
        D_801F0370 = D_801EFCA4;
    } else {
        D_801F0370 = -D_801EFCA4;
    }
    func_8003A63C(&D_801F0334, &D_801F0354, &m);
    func_801B3878(&m, &D_801F0374);
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B7668);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B794C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B79C0);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B7CFC);

void func_801B7F24(s16 arg0) {
    D_80162978[func_800BBEAC(&func_801B7CFC)].unk0 = arg0;
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B7F6C);

void func_801B80A8(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B7F6C)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B811C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B81A8);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B8280);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B88A4);
