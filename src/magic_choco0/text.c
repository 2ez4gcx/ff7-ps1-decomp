#include "common.h"
#include "magic_choco0/decls.h"

M2C_UNK *func_801B0038(void) {
    func_801B1F68();
    return &D_801D267C;
}

s32 func_801B0060(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801E5A12[-v];
    }
    return v;
}

INCLUDE_ASM("../asm/us/magic_choco0/nonmatchings/text", func_801B009C);

void func_801B103C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B009C)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

MgMat *func_801B10A0(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801E5898.m[0][0] = D_801E5898.m[1][1] = D_801E5898.m[2][2] = scale;
    func_8003B48C(&D_801E59F0);
    func_8003B51C(&D_801E59F0);
    func_8003BC6C(v, (MgVec *)D_801E5898.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801E5898.t, &n);
        D_801E5898.t[0] += (dist * n.vx) >> 12;
        D_801E5898.t[1] += (dist * n.vy) >> 12;
        D_801E5898.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801E5898);
    func_8003B51C(&D_801E5898);
    return &D_801E5898;
}

INCLUDE_ASM("../asm/us/magic_choco0/nonmatchings/text", func_801B11BC);

INCLUDE_ASM("../asm/us/magic_choco0/nonmatchings/text", func_801B12DC);

INCLUDE_ASM("../asm/us/magic_choco0/nonmatchings/text", func_801B14A8);

INCLUDE_ASM("../asm/us/magic_choco0/nonmatchings/text", func_801B1614);

INCLUDE_ASM("../asm/us/magic_choco0/nonmatchings/text", func_801B1760);

INCLUDE_ASM("../asm/us/magic_choco0/nonmatchings/text", func_801B18BC);

INCLUDE_ASM("../asm/us/magic_choco0/nonmatchings/text", func_801B1998);

INCLUDE_ASM("../asm/us/magic_choco0/nonmatchings/text", func_801B1B40);

INCLUDE_ASM("../asm/us/magic_choco0/nonmatchings/text", func_801B1CA8);

INCLUDE_ASM("../asm/us/magic_choco0/nonmatchings/text", func_801B1F68);
