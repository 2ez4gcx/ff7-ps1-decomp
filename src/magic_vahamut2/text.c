#include "common.h"
#include "magic_vahamut2/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B7C4C();
    return &D_801D8EAC;
}

MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EEE00.m[0][0] = D_801EEE00.m[1][1] = D_801EEE00.m[2][2] = scale;
    func_8003B48C(&D_801F1AC0);
    func_8003B51C(&D_801F1AC0);
    func_8003BC6C(v, (MgVec *)D_801EEE00.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EEE00.t, &n);
        D_801EEE00.t[0] += (dist * n.vx) >> 12;
        D_801EEE00.t[1] += (dist * n.vy) >> 12;
        D_801EEE00.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EEE00);
    func_8003B51C(&D_801EEE00);
    return &D_801EEE00;
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B0184);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B0C44);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B0E54);

s32 func_801B16A8(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F1AFE[-v];
    }
    return v;
}

s32 func_801B16E4(s32 t, s32 s) {
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

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B17D4);

void func_801B2808(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B17D4)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B286C);

void func_801B29A8(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B286C)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

void func_801B2A1C(void) {
    MgMat m;

    D_801EF144 = D_801EEDD8;
    D_801EF134 = D_801EEDD8;
    if (D_801EEDD2 != 0) {
        D_801EF150 = D_801EEDF4;
    } else {
        D_801EF150 = -D_801EEDF4;
    }
    func_8003A63C(&D_801EF114, &D_801EF134, &m);
    func_801B0C44(&m, &D_801EF154);
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B2AAC);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B2E54);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3028);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B33C0);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B34C8);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3600);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3754);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3804);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3904);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3B84);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3E50);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3F90);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B4570);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B4708);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B48E8);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B4AE4);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B4DD4);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B5238);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B5390);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B5604);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B577C);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B57F4);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B5A48);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B5BD8);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B5D80);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B606C);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B6334);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B66C8);

s32 func_801B6828(s32 arg0) {
    return -(arg0 * 0x1388) / -20000;
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B6868);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B6A2C);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B6C18);

void func_801B6EAC(s16 arg0) {
    D_80162978[func_800BBEAC(&func_801B6C18)].unk0 = arg0;
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B6EF4);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B712C);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B7254);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B7340);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B7610);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B7C4C);
