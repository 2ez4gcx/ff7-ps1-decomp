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

void func_801B275C(MgSVec *arg0) {
    func_801B007C(arg0, 0x1000, 0);
    D_80163C74 = func_800D4D90(&D_801F0298, D_801517C0 + 0x70, 0xC, D_80163C74);
}

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

void func_801B4334(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;
    u16 temp_v1;
    u16 temp_v1_2;
    u16 temp_v1_3;

    temp_s0 = &D_80162978[D_8015169C];
    func_800D41FC(&D_801F1374, &D_801546EC, D_801F0374);
    temp_v1 = M2C_FIELD(D_801F0374, u16 *, 0x14);
    M2C_FIELD(D_801F2674, u16 *, 0x18) = temp_v1;
    M2C_FIELD(D_801F2674, u16 *, 4) = temp_v1;
    temp_v1_2 = M2C_FIELD(D_801F0374, u16 *, 0x18);
    M2C_FIELD(D_801F2674, u16 *, 0x1A) = temp_v1_2;
    M2C_FIELD(D_801F2674, u16 *, 6) = temp_v1_2;
    temp_v1_3 = M2C_FIELD(D_801F0374, u16 *, 0x1C);
    M2C_FIELD(D_801F2674, u16 *, 0x1C) = temp_v1_3;
    M2C_FIELD(D_801F2674, u16 *, 8) = temp_v1_3;
    func_8003B2CC(D_801F0374, &D_801F036C, D_801F2674 + 0x20);
    if (D_80062D98 == 0) {
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 >= 0x3C) {
            temp_s0->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B440C);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B47B4);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B49CC);
