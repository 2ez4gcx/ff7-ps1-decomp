#include "common.h"
#include "magic_queig/decls.h"

void func_801B0054(void) {
    func_801B33B4();
}

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B034C);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B0638);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B06B8);

s32 func_801B0DBC(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801CCC60[a];
        } else {
            r = D_801CCC60[0x800 - a];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801CCC60[a - 0x800];
        } else {
            r = -D_801CCC60[0x1000 - a];
        }
    }
    return r;
}

s32 func_801B0E60(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801CCC60[0x400 - a];
        } else {
            r = -D_801CCC60[a - 0x400];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801CCC60[0xC00 - a];
        } else {
            r = D_801CCC60[a - 0xC00];
        }
    }
    return r;
}

void func_801B0EFC(s16 *arg0, s16 *arg1, s32 *arg2) {
    s32 cx;
    s32 cy;
    s32 cz;
    s32 sx;
    s32 sy;
    s32 sz;
    s32 m0;
    s32 m1;
    s32 m2;
    s32 m3;
    s32 m4;
    s32 m5;
    s32 m6;
    s32 m7;
    s32 m8;

    cx = func_801B0E60(arg0[0]);
    cy = func_801B0E60(arg0[1]);
    cz = func_801B0E60(arg0[2]);
    sx = func_801B0DBC(arg0[0]);
    sy = func_801B0DBC(arg0[1]);
    sz = func_801B0DBC(arg0[2]);
    m0 = (((cz * cy) >> 12) * arg2[0]) >> 12;
    m3 = ((((sz * cx) >> 12) - (((cz * -sy >> 12) * sx) >> 12)) * arg2[0]) >> 12;
    m6 = ((((sz * sx) >> 12) + (((cz * -sy >> 12) * cx) >> 12)) * arg2[0]) >> 12;
    m1 = (((-sz * cy) >> 12) * arg2[1]) >> 12;
    m4 = ((((cz * cx) >> 12) + (((sz * -sy >> 12) * sx) >> 12)) * arg2[1]) >> 12;
    m7 = ((((cz * sx) >> 12) - (((sz * -sy >> 12) * cx) >> 12)) * arg2[1]) >> 12;
    m2 = (sy * arg2[2]) >> 12;
    m5 = (((-cy * sx) >> 12) * arg2[2]) >> 12;
    m8 = (((cy * cx) >> 12) * arg2[2]) >> 12;
    arg1[0] = m0;
    arg1[3] = m3;
    arg1[6] = m6;
    arg1[1] = m1;
    arg1[4] = m4;
    arg1[7] = m7;
    arg1[2] = m2;
    arg1[5] = m5;
    arg1[8] = m8;
}

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1100);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1898);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1938);

void func_801B1AE0(void) {
    MgTask *p;
    s32 t;
    s16 *ang;
    u16 *q;

    p = &D_80162978[D_8015169C];
    D_801CD468[0] = *(u8 *)&p->unk12;
    q = &D_801CD474;
    *q = p->unk14;
    ang = &p->unk14;
    D_801CD47C = *ang;
    func_800D4284(&p->unk4, -(*ang >> 4), q);
    func_8003B48C((MgMat *)q);
    func_8003B51C((MgMat *)q);
    t = p->unk2;
    if (t >= 4) {
        D_801CD46C = 0x2E808080 - (t - 4) * 0x202020;
    }
    D_801E554C = func_800D6260(&D_801CD468[-4], D_801517C0 + 0x70, 0xC, D_801E554C);
    if (D_80062D98 == 0) {
        p->unk6 += p->unk16;
        p->unk16 += p->unk18;
        if (++p->unk2 >= 8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1C38);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1C84);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1CDC);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B2274);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B2818);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B29E0);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B2BBC);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B2F34);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B318C);

INCLUDE_RODATA("../asm/us/magic_queig/nonmatchings/text", D_801B0000);

void func_801B33B4(arg0) {
    D_801E5550 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B3430, 0, 0, 0);
    func_800BBEAC(&func_801B318C);
    D_801E5554 = arg0;
}
