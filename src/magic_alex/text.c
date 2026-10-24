#include "common.h"
#include "magic_alex/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B6AB0();
    return &D_801DED44;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F0632[-v];
    }
    return v;
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B00A4);

void func_801B10C0(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B00A4)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B1124);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B1BE4);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B1E24);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B1EB4);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B1F7C);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B2AE4);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B2B08);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B2B80);

MgMat *func_801B2C78(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EDDEC.m[0][0] = D_801EDDEC.m[1][1] = D_801EDDEC.m[2][2] = scale;
    func_8003B48C(&D_801F0610);
    func_8003B51C(&D_801F0610);
    func_8003BC6C(v, (MgVec *)D_801EDDEC.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EDDEC.t, &n);
        D_801EDDEC.t[0] += (dist * n.vx) >> 12;
        D_801EDDEC.t[1] += (dist * n.vy) >> 12;
        D_801EDDEC.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EDDEC);
    func_8003B51C(&D_801EDDEC);
    return &D_801EDDEC;
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B2D94);

void func_801B2F38(void) {
    MgMat m;

    D_801EDE3C = D_801EDB30;
    D_801EDE2C = D_801EDB30;
    if (D_801EDB52 != 0) {
        D_801EDE48 = D_801EDB4C;
    } else {
        D_801EDE48 = -D_801EDB4C;
    }
    func_8003A63C(&D_801EDE0C, &D_801EDE2C, &m);
    func_801B1BE4(&m, &D_801EDE4C);
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B2FC8);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B3430);

void func_801B3498(void *arg0) {
    s16 temp_v0;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_v0_2;

    func_801B3430(arg0 + 4, M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 0x14));
    if (D_80062D98 == 0) {
        temp_v0 = (u16) M2C_FIELD(arg0, s16 *, 2) + 1;
        M2C_FIELD(arg0, s16 *, 2) = temp_v0;
        if ((s32) D_801DEA40 < temp_v0) {
            M2C_FIELD(arg0, s16 *, 0) = -1;
            return;
        }
        M2C_FIELD(arg0, u16 *, 6) = (u16) (M2C_FIELD(arg0, u16 *, 6) + M2C_FIELD(arg0, u16 *, 0xE));
        temp_s0 = func_80039A74(M2C_FIELD(arg0, s16 *, 0xC));
        temp_v0_2 = func_80039B40(M2C_FIELD(arg0, s16 *, 0xC));
        temp_a1 = (s32) ((temp_v0_2 * M2C_FIELD(arg0, s16 *, 4)) + (temp_s0 * M2C_FIELD(arg0, s16 *, 8))) >> 0xC;
        M2C_FIELD(arg0, s16 *, 4) = (s16) temp_a1;
        M2C_FIELD(arg0, s16 *, 8) = (s16) ((s32) ((-temp_s0 * (s16) temp_a1) + (temp_v0_2 * M2C_FIELD(arg0, s16 *, 8))) >> 0xC);
    }
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B359C);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B3924);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B3BAC);

void func_801B3E14(void *arg0) {
    s16 temp_v0;

    func_801B3430(arg0 + 4, M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 0x14));
    if (D_80062D98 == 0) {
        temp_v0 = (u16) M2C_FIELD(arg0, s16 *, 2) + 1;
        M2C_FIELD(arg0, s16 *, 2) = temp_v0;
        if (temp_v0 >= (s32) D_801DEA40) {
            M2C_FIELD(arg0, s16 *, 0) = -1;
            return;
        }
        M2C_FIELD(arg0, u16 *, 6) = (u16) (M2C_FIELD(arg0, u16 *, 6) + 0x82);
    }
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B3EA0);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B402C);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B4118);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B4200);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B4348);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B4614);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B46E0);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B4970);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B4CD4);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B5084);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B51EC);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B53B0);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B5584);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B5770);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B5850);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B5A90);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B5C14);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B5E98);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B6AB0);
