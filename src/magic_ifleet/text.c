#include "common.h"
#include "magic_ifleet/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B3BB0();
    return &D_801DD188;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F0482[-v];
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

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B0194);

void func_801B11BC(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B0194)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

MgMat *func_801B1220(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801F00A8.m[0][0] = D_801F00A8.m[1][1] = D_801F00A8.m[2][2] = scale;
    func_8003B48C(&D_801F0450);
    func_8003B51C(&D_801F0450);
    func_8003BC6C(v, (MgVec *)D_801F00A8.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801F00A8.t, &n);
        D_801F00A8.t[0] += (dist * n.vx) >> 12;
        D_801F00A8.t[1] += (dist * n.vy) >> 12;
        D_801F00A8.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801F00A8);
    func_8003B51C(&D_801F00A8);
    return &D_801F00A8;
}

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B133C);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B14E8);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B1798);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B1958);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B1C88);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B1E58);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B21F4);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B233C);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B24C4);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B2E1C);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B301C);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B32A0);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B34AC);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B35FC);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B3BB0);
