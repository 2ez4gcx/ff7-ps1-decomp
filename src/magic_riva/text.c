#include "common.h"
#include "magic_riva/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B309C();
    return &D_801DD26C;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F49FE[-v];
    }
    return v;
}

s32 func_801B00A4(s32 t, s32 s) {
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

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B0194);

void func_801B11C8(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B0194)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

MgMat *func_801B122C(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801F3518.m[0][0] = D_801F3518.m[1][1] = D_801F3518.m[2][2] = scale;
    func_8003B48C(&D_801F49E0);
    func_8003B51C(&D_801F49E0);
    func_8003BC6C(v, (MgVec *)D_801F3518.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801F3518.t, &n);
        D_801F3518.t[0] += (dist * n.vx) >> 12;
        D_801F3518.t[1] += (dist * n.vy) >> 12;
        D_801F3518.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801F3518);
    func_8003B51C(&D_801F3518);
    return &D_801F3518;
}

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B1348);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B142C);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B1744);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B1C10);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B1F8C);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B2104);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B21B0);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B2308);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B254C);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B2670);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B26E4);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B28EC);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B29B0);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B309C);
