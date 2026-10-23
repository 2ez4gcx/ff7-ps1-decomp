#include "common.h"
#include "cnfgmenu/decls.h"

void func_801D0040(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_801D0080(s32 arg0) {
    switch (arg0) {
    case 0:
        D_8009A000 = 0x81;
        D_8009A004 = 0x81;
        D_8009A008 = 0x81;
        break;
    case 1:
        D_8009A000 = 0x80;
        D_8009A004 = 0x80;
        D_8009A008 = 0x80;
        break;
    case 2:
        D_8009A000 = 0x82;
        D_8009A004 = 0x82;
        D_8009A008 = 0x82;
        break;
    }
    func_8002DA7C(arg0);
}

u8 func_801D0118(u16 arg0) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if ((arg0 >> i) & 1) {
            return i;
        }
    }
    return 0xFF;
}

void func_801D014C(s16 arg0, s16 arg1, s32 arg2) {
    u8 pad[8];
    u8 t;
    u8 b;

    arg2 *= 2;
    t = D_801D1AAC[arg2];
    b = D_801D1AAC[arg2 + 1];
    func_80028CA0(arg0, arg1, (t & 3) * 0x10 + 0x60, (t >> 2) * 0x10 + 0x40, 0x10, 0x10, b, 0);
}

void func_801D01C8(void) {
    s16 r[4];
    s32 base;
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    s32 w;
    s32 k;
    s32 t;
    u8 *s;
    u8 *p2;
    u8 *q;

    base = D_801D24AA + 0x21;
    func_80026F44(0x28, D_801D24AA + 0xE, D_801D1AE8, 5);
    for (i = 1; i < 9; i++) {
        func_80026F44(0x28, base + (i - 1) * 0x12, D_801D1AE8 + i * 0x30, 5);
    }
    func_80026F44(0x28, base + (i - 1) * 0x12, D_801D2118, 5);
    for (i = 0; i < 2; i++) {
        func_80026F44(0xA5 + i * 0x41, base, D_801D2118 - 0x360 + i * 0x30, -((D_8009D7BC.unk2 & 3) == i) & 7);
    }
    for (i = 0; i < 2; i++) {
        func_80026F44(0xA5 + i * 0x41, base + 0x12, D_801D1E48 + i * 0x30, -(((D_8009D7BC.unk2 >> 2) & 3) == i) & 7);
    }
    for (i = 0; i < 2; i++) {
        func_80026F44(0xA5 + i * 0x41, base + 0x24, D_801D1EA8 + i * 0x30, -(((D_8009D7BC.unk2 >> 4) & 3) == i) & 7);
    }
    y = base + 0x36;
    func_80026F44(0xA5, y, D_801D1F08, -(((D_8009D7BC.unk2 >> 6) & 3) == 0) & 7);
    t = func_80026B70(D_801D1F08);
    func_80026F44(t + 0xAF, y, D_801D1F08 + 0x30, -(((D_8009D7BC.unk2 >> 6) & 3) == 1) & 7);
    func_80026F44(t + func_80026B70(D_801D1F08 + 0x30) + 0xB9, y, D_801D1F08 + 0x60, -(((D_8009D7BC.unk2 >> 6) & 3) == 2) & 7);
    for (i = 0; i < 2; i++) {
        func_80026F44(0xA5 + i * 0x41, base + 0x7E, D_801D1F08 + 0x90 + i * 0x30, -(((D_8009D7BC.unk2 >> 8) & 3) == i) & 7);
    }
    for (i = 0; i < 3; i++) {
        q = D_801D248C;
        func_80026F44(0xBD + i * 0x34, base + 0x90, D_801D2148 + (q + ((D_8009D7BC.unk2 >> 10) & 7) * 3)[i] * 0x30, 7);
    }
    func_80026F44(0x95, base + 0x90, D_801D2148 + 0xC0, 7);
    r[1] = base + 0x48;
    r[2] = 8;
    r[3] = 0xB;
    r[0] = (D_8009D7BC.unk0 >> 1) + 0xB8;
    func_80028030(r);
    r[1] = base + 0x5A;
    r[2] = 8;
    r[3] = 0xB;
    r[0] = (D_8009D7BC.unk1 >> 1) + 0xB8;
    func_80028030(r);
    r[1] = base + 0x6C;
    r[2] = 8;
    r[3] = 0xB;
    r[0] = (D_8009D7BC.unk14 >> 1) + 0xB8;
    func_80028030(r);
    for (i = 0; i < 3; i++) {
        x = base + 0x48 + i * 0x12 + 2;
        func_80026F44(0x9D, x, D_801D2148 - 0xF0, 7);
        func_80026F44(0x144, x, D_801D2148 - 0x120, 7);
    }
    for (i = 0; i < 3; i++) {
        r[0] = 0xB8;
        r[1] = base + 0x48 + i * 0x12;
        r[2] = 0x88;
        r[3] = 0xB;
        func_80027B84(r);
    }
    func_80029114(0xAD, base + 0x92, ((D_8009D7BC.unk2 >> 10) & 7) + 1, 1, 7);
    r[0] = 0;
    r[1] = 0;
    r[2] = 0x100;
    r[3] = 0x100;
    func_80026A34(0, 1, 0x1F, (s32)r);
}

void func_801D069C(void) {
    u8 pad[8];
    s32 i;

    func_80026448(D_801D24CC, 0, 0, 1, 0xA, 0, 0, 1, 0xA, 0, 0, 0, 1, 0U);
    func_80026448(D_801D24CC + 0x12, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 1, 1, 0U);
    func_80026448(D_801D24CC + 0x24, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0U);
    func_80026448(D_801D24CC + 0x36, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0U);
    D_801D1AA8 = 0;
    for (i = 0; i < 12; i++) {
        D_801D252C[i] = D_80049208[i];
    }
}

INCLUDE_ASM("../asm/us/cnfgmenu/nonmatchings/text", func_801D080C);

void func_801D1AA0(void) {
}
