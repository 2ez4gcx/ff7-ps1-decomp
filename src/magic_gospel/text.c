#include "common.h"
#include "magic_gospel/decls.h"

M2C_UNK *func_801B0048(void) {
    func_801B3914();
    return &D_801DDCE4;
}

MgMat *func_801B0070(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801E0628.m[0][0] = D_801E0628.m[1][1] = D_801E0628.m[2][2] = scale;
    func_8003B48C(&D_801E0988);
    func_8003B51C(&D_801E0988);
    func_8003BC6C(v, (MgVec *)D_801E0628.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801E0628.t, &n);
        D_801E0628.t[0] += (dist * n.vx) >> 12;
        D_801E0628.t[1] += (dist * n.vy) >> 12;
        D_801E0628.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801E0628);
    func_8003B51C(&D_801E0628);
    return &D_801E0628;
}

s32 func_801B018C(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801E09AA[-v];
    }
    return v;
}

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B01C8);

void func_801B120C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B01C8)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B1270);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B1294);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B130C);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B1404);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B15D4);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B179C);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B1890);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B1A48);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B1C6C);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B22E8);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B2418);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B252C);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B2620);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B286C);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B2A2C);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B2B38);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B2D34);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B2F00);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B3034);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B31BC);

void func_801B3394(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B31BC)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B3414);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B38A8);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B3914);
