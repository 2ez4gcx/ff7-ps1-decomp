#include "common.h"
#include "magic_debucho/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B1D64();
    return &D_801BAC54;
}

MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801C4058.m[0][0] = D_801C4058.m[1][1] = D_801C4058.m[2][2] = scale;
    func_8003B48C(&D_801C42A0);
    func_8003B51C(&D_801C42A0);
    func_8003BC6C(v, (MgVec *)D_801C4058.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801C4058.t, &n);
        D_801C4058.t[0] += (dist * n.vx) >> 12;
        D_801C4058.t[1] += (dist * n.vy) >> 12;
        D_801C4058.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801C4058);
    func_8003B51C(&D_801C4058);
    return &D_801C4058;
}

s32 func_801B0184(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801C42C2[-v];
    }
    return v;
}

INCLUDE_ASM("../asm/us/magic_debucho/nonmatchings/text", func_801B01C0);

void func_801B11DC(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B01C0)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_debucho/nonmatchings/text", func_801B1240);

INCLUDE_ASM("../asm/us/magic_debucho/nonmatchings/text", func_801B1414);

INCLUDE_ASM("../asm/us/magic_debucho/nonmatchings/text", func_801B1584);

INCLUDE_ASM("../asm/us/magic_debucho/nonmatchings/text", func_801B16BC);

INCLUDE_ASM("../asm/us/magic_debucho/nonmatchings/text", func_801B18B0);

INCLUDE_ASM("../asm/us/magic_debucho/nonmatchings/text", func_801B1980);

INCLUDE_ASM("../asm/us/magic_debucho/nonmatchings/text", func_801B19EC);

INCLUDE_ASM("../asm/us/magic_debucho/nonmatchings/text", func_801B1A98);

INCLUDE_ASM("../asm/us/magic_debucho/nonmatchings/text", func_801B1D64);
