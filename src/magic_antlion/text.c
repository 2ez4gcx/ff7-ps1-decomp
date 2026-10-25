#include "common.h"
#include "magic_antlion/decls.h"

void func_801B0040(void) {
    func_801B3D30();
}

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B0060);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B0B20);

s32 func_801B0D24(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801E4166[-v];
    }
    return v;
}

s32 func_801B0D60(s32 a, s32 b) {
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

void func_801B0E58(s32 arg0, s32 arg1, MgTask *arg2, MgSVec *arg3) {
    MgMat m;

    if (arg1 != -1) {
        func_800D3994(arg0, arg1, arg3);
    } else {
        arg3->vx = D_80151A4C[arg0][0];
        arg3->vy = D_80151A4E[arg0][0];
        arg3->vz = D_80151A50[arg0][0];
    }
    arg3->vx -= arg2->unk14;
    arg3->vy -= arg2->unk18;
    arg3->vz -= arg2->unk1C;
    func_8003BF3C(arg2, &m);
    func_8003B2CC(&m, arg3, arg3);
}

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B0F48);

void func_801B1EAC(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B0F48)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B1F10(void) {
    MgMat m;

    D_801E3FFC = D_801E3F0C;
    D_801E3FEC = D_801E3F0C;
    if (D_801E3F06 != 0) {
        D_801E4008 = D_801E3F28;
    } else {
        D_801E4008 = -D_801E3F28;
    }
    func_8003A63C(&D_801E3FCC, &D_801E3FEC, &m);
    func_801B0B20(&m, &D_801E400C);
}

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B1FA0);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B22D4);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B241C);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B290C);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B2A7C);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B2B0C);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B2DF8);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B2FB0);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B30C4);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B325C);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B338C);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B3708);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B3910);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B3B24);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B3BD8);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B3D30);
