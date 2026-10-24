#include "common.h"
#include "magic_odin2/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B5264();
    return &D_801DCCD0;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F726E[-v];
    }
    return v;
}

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B00A4);

void func_801B10E8(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B00A4)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B114C);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B1C40);

MgMat *func_801B2200(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801F1C3C.m[0][0] = D_801F1C3C.m[1][1] = D_801F1C3C.m[2][2] = scale;
    func_8003B48C(&D_801F6238);
    func_8003B51C(&D_801F6238);
    func_8003BC6C(v, (MgVec *)D_801F1C3C.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801F1C3C.t, &n);
        D_801F1C3C.t[0] += (dist * n.vx) >> 12;
        D_801F1C3C.t[1] += (dist * n.vy) >> 12;
        D_801F1C3C.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801F1C3C);
    func_8003B51C(&D_801F1C3C);
    return &D_801F1C3C;
}

MgMat *func_801B231C(MgSVec *v, s32 d, MgMat *m) {
    MgVec n;
    s32 flag;

    func_8003B48C(&D_801F6238);
    func_8003B51C(&D_801F6238);
    func_8003BC6C(v, (MgVec *)m->t, &flag);
    if (d != 0) {
        func_8003A08C((MgVec *)m->t, &n);
        m->t[0] += (d * n.vx) >> 12;
        m->t[1] += (d * n.vy) >> 12;
        m->t[2] += (d * n.vz) >> 12;
    }
    return m;
}

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B2400);

void func_801B25F8(void) {
    MgObj20 *temp_s0;
    s16 temp_v1;
    s32 temp_v1_2;

    temp_s0 = &D_80162978[D_8015169C];
    temp_v1 = temp_s0->unk2;
    if (temp_v1 >= 0x87) {
        temp_v1_2 = temp_v1 - 0x87;
        if (temp_v1_2 >= 0x19) {
            temp_s0->unk0 = -1;
            return;
        }
        if (temp_v1_2 == 0) {
            M2C_FIELD(temp_s0, s16 *, 6) = -0x1324;
            M2C_FIELD(temp_s0, s16 *, 4) = 0;
            M2C_FIELD(temp_s0, s16 *, 8) = -0x1E0C;
        }
        goto block_5;
    }
block_5:
    func_801B2200((MgSVec *)&temp_s0->unk4, 0x2000, 0);
    D_80163C74 = func_800D4D90(&D_801F1C6C, D_801517C0 + 0x406C, 0, D_80163C74);
    if (D_80062D98 == 0) {
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

void func_801B26D0(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    func_8003A63C(&D_801F6238, &D_801F1C88, D_801F1CA8);
    func_8003B48C(D_801F1CA8);
    func_8003B51C(D_801F1CA8);
    D_80163C74 = func_800D29D4(&D_801F1C78, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 >= 0x3C) {
            temp_s0->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B27A8);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B29C8);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B2B20);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B2D88);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B2F70);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B30B4);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B33DC);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B379C);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B3860);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B3A10);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B3B3C);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B3C14);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B3D10);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B3F54);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B4434);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B447C);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B4B98);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B4C38);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B4DD4);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B5264);
