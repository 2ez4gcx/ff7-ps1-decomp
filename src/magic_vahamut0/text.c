#include "common.h"
#include "magic_vahamut0/decls.h"

M2C_UNK *func_801B0060(void) {
    func_801B7920();
    return &D_801D823C;
}

MgMat *func_801B0088(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801FC8E0.m[0][0] = D_801FC8E0.m[1][1] = D_801FC8E0.m[2][2] = scale;
    func_8003B48C(&D_801FD11C);
    func_8003B51C(&D_801FD11C);
    func_8003BC6C(v, (MgVec *)D_801FC8E0.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801FC8E0.t, &n);
        D_801FC8E0.t[0] += (dist * n.vx) >> 12;
        D_801FC8E0.t[1] += (dist * n.vy) >> 12;
        D_801FC8E0.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801FC8E0);
    func_8003B51C(&D_801FC8E0);
    return &D_801FC8E0;
}

s32 func_801B01A4(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801FD13E[-v];
    }
    return v;
}

s32 func_801B01E0(s32 a, s32 b) {
    s32 i;
    s32 n;
    s32 orig;

    orig = a;
    if (b > 0) {
        n = b >> 8;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
    } else if (b < 0) {
        b = -b;
        n = b >> 8;
        a = 0x1000 - a;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
        a = 0x1000 - a;
    } else {
        return a;
    }
    n = (b & 0xFF) + 1;
    a = (a * n + orig * (0x100 - n)) >> 8;
    return a;
}

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B02D8);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B03D4);

void func_801B13AC(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B03D4)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B1410);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B24A4);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B24C8);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B251C);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B2610);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B2888);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B2AE8);

void *func_801B2BDC(void *arg0, s32 arg1, void *arg2) {
    void *temp_s2;

    M2C_FIELD(arg2, s32 *, 0) = 0x04000000;
    M2C_FIELD(arg2, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(arg2, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(arg2, u8 *, 0xC) = (u8) M2C_FIELD(arg0, u8 *, 4);
    M2C_FIELD(arg2, u8 *, 0xD) = (u8) M2C_FIELD(arg0, u8 *, 6);
    M2C_FIELD(arg2, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x12);
    M2C_FIELD(arg2, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 8);
    func_80046794(arg1, (s32) arg2);
    temp_s2 = arg2 + 0x14;
    func_80044A68(temp_s2, 0, 1, (s32) M2C_FIELD(arg0, u16 *, 0x10), 0);
    func_80046794(arg1, (s32) temp_s2);
    return arg2 + 0x20;
}

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B2C9C);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B3088);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B320C);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B3398);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B35F0);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B3708);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B38D0);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B3A3C);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B3B88);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B3D14);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B3E0C);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B4018);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B4090);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B42F0);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B4470);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B493C);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B4AEC);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B4C74);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B4D20);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B5094);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B52A0);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B53C0);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B563C);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B57F4);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B5884);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B5B90);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B5CC8);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B5EC4);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B60CC);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B619C);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B6384);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B64D8);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B6584);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B6718);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B68E4);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B6AE0);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B7320);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B7920);
