#include "common.h"
#include "magic_odin1/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B65A0();
    return &D_801DD640;
}

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B0068);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B00F8);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B01C0);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B0E60);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B11C8);

s32 func_801B1630(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F76FE[-v];
    }
    return v;
}

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B166C);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B1758);

void func_801B2778(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B1758)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B27DC(void) {
    s32 i;
    s32 *p;

    i = 0x1F3;
    p = D_801F7EE0;
    do {
        *p = 0;
        i--;
        p--;
    } while (i >= 0);
}

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B2800);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B2854);

MgMat *func_801B2944(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801F27F0.m[0][0] = D_801F27F0.m[1][1] = D_801F27F0.m[2][2] = scale;
    func_8003B48C(&D_801F3554);
    func_8003B51C(&D_801F3554);
    func_8003BC6C(v, (MgVec *)D_801F27F0.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801F27F0.t, &n);
        D_801F27F0.t[0] += (dist * n.vx) >> 12;
        D_801F27F0.t[1] += (dist * n.vy) >> 12;
        D_801F27F0.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801F27F0);
    func_8003B51C(&D_801F27F0);
    return &D_801F27F0;
}

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B2A60);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B2BE0);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B2EC0);

void func_801B2FFC(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B2EC0)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B3070);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B32BC);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B3660);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B379C);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B3A24);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B3BAC);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B3DC0);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B41C4);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B43C4);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B4538);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B4654);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B47E0);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B4A38);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B4C8C);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B4DBC);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B4F30);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B5088);

void func_801B5148(s16 arg0, s16 arg1, s16 arg2) {
    MgTask *temp_v0;

    temp_v0 = &D_80162978[func_800BBEAC(&func_801B5088)];
    temp_v0->unk4 = arg0;
    temp_v0->unk6 = arg1;
    temp_v0->unk8 = arg2;
}

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B51AC);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B5A74);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B5D14);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B65A0);
