#include "common.h"
#include "magic_siva/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B49CC();
    return &D_801D9E98;
}

MgMat *func_801B007C(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801F0040.m[0][0] = D_801F0040.m[1][1] = D_801F0040.m[2][2] = scale;
    func_8003B48C(&D_801F1374);
    func_8003B51C(&D_801F1374);
    func_8003BC6C(v, (MgVec *)D_801F0040.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801F0040.t, &n);
        D_801F0040.t[0] += (dist * n.vx) >> 12;
        D_801F0040.t[1] += (dist * n.vy) >> 12;
        D_801F0040.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801F0040);
    func_8003B51C(&D_801F0040);
    return &D_801F0040;
}

s32 func_801B0198(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F139E[-v];
    }
    return v;
}

s32 func_801B01D4(s32 t, s32 s) {
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

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B02C4);

void func_801B1300(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B02C4)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B1364);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B1760);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B1B5C);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2078);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2150);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2224);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B249C);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B24C0);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B257C);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B25C4);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B25E8);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2658);

void func_801B274C(s32 arg0) {
    D_801F2674 = arg0;
}

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B275C);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B27AC);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B28A0);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2B1C);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2C6C);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2DE0);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2FAC);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B30DC);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B3188);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B3408);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B3644);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B3938);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B3B10);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B3E00);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B3FD4);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B40F0);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B4334);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B440C);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B47B4);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B49CC);
