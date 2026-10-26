#include "common.h"
#include "magic_lasboss3/decls.h"

void func_801B0040(void) {
    func_801BA85C();
}

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B0060);

void func_801B0208(s32 base, s16 range, MgSVec *out) {
    MgSVec v;
    MgSVec rot;
    MgMat m;

    v.vz = 0;
    v.vx = 0;
    v.vy = base + ((func_80042DA8() % range) * 2 - range);
    rot.vy = 0;
    rot.vx = func_80042DA8() % 800 - 400;
    rot.vz = func_80042DA8() % 800 - 400;
    func_8003BF8C(&rot, &m);
    func_8003B2CC(&m, &v, out);
}

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B0338);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B0464);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B057C);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B0C18);

s32 func_801B1254(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801FC706[-v];
    }
    return v;
}

s32 func_801B1290(s32 t, s32 s) {
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

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B1380);

void func_801B23A8(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B1380)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B240C);

void func_801B246C(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;
    s32 temp_a0;

    temp_s0 = &D_80162978[D_8015169C];
    temp_a0 = (s32) (func_80039A74(D_801BB7D0 * 0x33) * 0xFF0) >> 0x10;
    D_80163C74 = func_800C4FC8(temp_a0, temp_a0, temp_a0);
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 >= (M2C_FIELD(temp_s0, s16 *, 0x16) - 0x14)) {
            D_801BB7D0 = (u16) D_801BB7D0 - 1;
        }
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 == M2C_FIELD(temp_s0, s16 *, 0x16)) {
            D_801BB7D0 = 0x14;
            temp_s0->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B2554);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B265C);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B279C);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B2A08);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B2DCC);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B2E4C);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B2F80);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B30D0);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B31C0);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B3360);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B34C0);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B35E4);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B3790);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B38C8);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B3A30);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B3C4C);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B3DB8);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B4004);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B43CC);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B4704);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B4804);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B4A28);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B4C4C);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B4D54);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B4E28);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B4F20);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B5270);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B567C);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B5978);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B5A9C);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B5BB8);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B5C98);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B5DE8);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B5F54);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B60C4);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B637C);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B6470);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B65C4);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B66C4);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B67C4);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B6900);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B6A48);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B6C6C);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B7028);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B71EC);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B7340);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B7610);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B7798);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B7A94);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B7B74);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B7C18);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B7CD8);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B7DA0);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B7FF4);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801BA6A8);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801BA85C);
