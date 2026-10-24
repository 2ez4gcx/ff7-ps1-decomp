#include "common.h"
#include "magic_phoenix/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B47DC();
    return &D_801DA084;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801EC976[-v];
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

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B0194);

void func_801B11C8(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B0194)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B122C);

MgMat *func_801B179C(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EC6B4.m[0][0] = D_801EC6B4.m[1][1] = D_801EC6B4.m[2][2] = scale;
    func_8003B48C(&D_801EC954);
    func_8003B51C(&D_801EC954);
    func_8003BC6C(v, (MgVec *)D_801EC6B4.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EC6B4.t, &n);
        D_801EC6B4.t[0] += (dist * n.vx) >> 12;
        D_801EC6B4.t[1] += (dist * n.vy) >> 12;
        D_801EC6B4.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EC6B4);
    func_8003B51C(&D_801EC6B4);
    return &D_801EC6B4;
}

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B18B8);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B1978);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B1B74);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B1E40);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B1F80);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B2138);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B2490);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B275C);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B28D0);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B2C04);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B2F34);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B30D0);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B3210);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B3384);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B35F8);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B3960);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B39D0);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B3C08);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B3D30);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B3F84);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B41C0);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B47DC);
