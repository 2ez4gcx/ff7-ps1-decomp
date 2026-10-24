#include "common.h"
#include "magic_vahamut/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B3AB8();
    return &D_801DB958;
}

MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EEEA0.m[0][0] = D_801EEEA0.m[1][1] = D_801EEEA0.m[2][2] = scale;
    func_8003B48C(&D_801EFC68);
    func_8003B51C(&D_801EFC68);
    func_8003BC6C(v, (MgVec *)D_801EEEA0.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EEEA0.t, &n);
        D_801EEEA0.t[0] += (dist * n.vx) >> 12;
        D_801EEEA0.t[1] += (dist * n.vy) >> 12;
        D_801EEEA0.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EEEA0);
    func_8003B51C(&D_801EEEA0);
    return &D_801EEEA0;
}

s32 func_801B0184(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801EFC8A[-v];
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

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B02B0);

void func_801B12E4(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B02B0)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B1348);

void func_801B1484(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B1348)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B14F8);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B1634);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B1804);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B18F0);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B1C48);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B1D60);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B1DC0);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B1F70);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2170);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2238);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2464);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B25E4);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2810);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2970);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2BEC);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2DA8);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B31D8);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B37F8);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B3AB8);
