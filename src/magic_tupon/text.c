#include "common.h"
#include "magic_tupon/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B64C8();
    return &D_801D90DC;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801EDE2E[-v];
    }
    return v;
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B00A4);

void func_801B10E8(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B00A4)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B114C);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B1C0C);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B1E1C);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B1E40);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B1EB8);

MgMat *func_801B1FB0(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EDA6C.m[0][0] = D_801EDA6C.m[1][1] = D_801EDA6C.m[2][2] = scale;
    func_8003B48C(&D_801EDDF8);
    func_8003B51C(&D_801EDDF8);
    func_8003BC6C(v, (MgVec *)D_801EDA6C.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EDA6C.t, &n);
        D_801EDA6C.t[0] += (dist * n.vx) >> 12;
        D_801EDA6C.t[1] += (dist * n.vy) >> 12;
        D_801EDA6C.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EDA6C);
    func_8003B51C(&D_801EDA6C);
    return &D_801EDA6C;
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B20CC);

void func_801B21C8(s32 arg0) {
    MgObj20 *temp_v0;

    if (D_801EDA8C == NULL) {
        temp_v0 = &D_80162978[func_800BBEAC(&func_801B20CC)];
        D_801EDA8C = (u8 *) temp_v0;
        M2C_FIELD(temp_v0, s32 *, 4) = 0;
        M2C_FIELD(temp_v0, s32 *, 0xC) = (s32) (0x10000 / arg0);
    }
}

void func_801B2258(s32 arg0) {
    if (D_801EDA8C != NULL) {
        M2C_FIELD(D_801EDA8C, s32 *, 0xC) = (s32) ((s32) -M2C_FIELD(D_801EDA8C, s32 *, 4) / arg0);
    }
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B22B4);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B2460);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B2760);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B2A50);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B2CD0);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B2F4C);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B30D8);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B32B8);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B3464);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B3668);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B3A08);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B3E90);

void func_801B4104(void) {
    MgMat m;

    D_801EDBB8 = D_801ED8B8;
    D_801EDBA8 = D_801ED8B8;
    if (D_801ED8DA != 0) {
        D_801EDBC4 = D_801ED8D4;
    } else {
        D_801EDBC4 = -D_801ED8D4;
    }
    func_8003A63C(&D_801EDB88, &D_801EDBA8, &m);
    func_801B1C0C(&m, &D_801EDBC8);
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B4194);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B421C);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B4378);

void func_801B45C0(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    func_8003A63C(&D_801EDDF8, &D_801EDC00, D_801EDC20);
    func_8003B48C(D_801EDC20);
    func_8003B51C(D_801EDC20);
    D_80163C74 = func_800D29D4(&D_801EDBF0, D_801517C0 + 0x406C, 0, D_80163C74);
    if (D_80062D98 == 0) {
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 >= 0x78) {
            temp_s0->unk0 = -1;
            return;
        }
        func_8003C8DC(0x10, &D_801EDC00);
    }
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B46B4);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B4A6C);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B4B1C);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B4BCC);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B4E00);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B5050);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B51E0);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B550C);

void func_801B575C(s16 arg0) {
    MgObj20 *temp_v0;

    temp_v0 = &D_80162978[func_800BBEAC(&func_801B550C)];
    temp_v0->unk0 = arg0;
    M2C_FIELD(temp_v0, s16 *, 0xE) = 0;
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B57A8);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B592C);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B5AB0);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B5D00);

void func_801B5E5C(void) {
    MgObj20 *temp_s0;
    s16 temp_v1;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        temp_v1 = temp_s0->unk2;
        if (temp_v1 == 0) {
            func_801B21C8(4);
        } else if (temp_v1 == 4) {
            func_801B2258(4);
            temp_s0->unk0 = -1;
        }
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B5EE8);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B64C8);
