#include "common.h"
#include "magic_queir/decls.h"

void func_801B0074(void) {
    func_801B2DCC();
}

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B0094);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B033C);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B05EC);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B0668);

s32 func_801B0D8C(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801C3C6C[a];
        } else {
            r = D_801C3C6C[0x800 - a];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801C3C6C[a - 0x800];
        } else {
            r = -D_801C3C6C[0x1000 - a];
        }
    }
    return r;
}

s32 func_801B0E30(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801C3C6C[0x400 - a];
        } else {
            r = -D_801C3C6C[a - 0x400];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801C3C6C[0xC00 - a];
        } else {
            r = D_801C3C6C[a - 0xC00];
        }
    }
    return r;
}

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B0ECC);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B104C);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B17F4);

void func_801B1894(void) {
    MgTask *p;
    s32 t;
    s16 *ang;
    u16 *q;

    p = &D_80162978[D_8015169C];
    D_801C4474[0] = *(u8 *)&p->unk12;
    q = &D_801C4480;
    *q = p->unk14;
    ang = &p->unk14;
    D_801C4488 = *ang;
    func_800D4284(&p->unk4, -(*ang >> 4), q);
    func_8003B48C((MgMat *)q);
    func_8003B51C((MgMat *)q);
    t = p->unk2;
    if (t >= 4) {
        D_801C4478 = 0x2E808080 - (t - 4) * 0x202020;
    }
    D_801DC4A0 = func_800D6260(&D_801C4474[-4], D_801517C0 + 0x70, 0xC, D_801DC4A0);
    if (D_80062D98 == 0) {
        p->unk6 += p->unk16;
        p->unk16 += p->unk18;
        if (++p->unk2 >= 8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B19EC);

void func_801B1F00(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    MgMat *q;
    s32 t;
    s32 i;

    rot.vx = rot.vy = rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    i = (p->unk12 << 12) / 1900;
    i = i >= 0 ? (i > 0x1000 ? 0x1000 : i) : 0;
    scale.vx = scale.vy = scale.vz = i;
    func_8003B35C(&m, &scale);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 6) {
            p->unk12 += p->unk14;
        } else if (t >= 0x12) {
            p->unk12 -= p->unk14;
        }
    }
    q = &m;
    func_8003A63C(&D_800FA63C, q, q);
    func_8003B48C(q);
    func_8003B51C(q);
    ((MgScratch *)0x1F800000)->unk0 = D_801C3210;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801DC4A0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DC4A0);
    if (p->unk2 >= 0x18) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        if (p->unk2 == 0x12) {
            for (i = 0; i < 10; i++) {
                if ((1 << i) & D_801DC4A8) {
                    func_800D5774(i);
                }
            }
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B2144);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B237C);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B2590);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B2A04);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B2C08);

INCLUDE_RODATA("../asm/us/magic_queir/nonmatchings/text", D_801B0020);

void func_801B2DCC(arg0) {
    D_801DC4A4 = &D_80162978[func_800BBEAC(&D_801B0020)];
    func_800D2980(&D_801B2E48, 0, 0, 0);
    func_800BBEAC(&func_801B2C08);
    D_801DC4A8 = arg0;
}
