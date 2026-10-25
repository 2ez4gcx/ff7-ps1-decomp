#include "common.h"
#include "magic_geki1/decls.h"

void func_801B0000(void) {
    func_801B0E5C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D54CC = D_801BD4CC + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801BD488.unk0 = D_801BD494[p->unk16];
    D_801BD488.unk8 = p->unk2;
    D_80163C74 = func_800D4D90(&D_801BD488, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801BD494[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0180(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801BD4A4;
    *frame = p->unk2;
    D_801D54CC = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D54CC);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801BD3C4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0238(void) {
    MgMat lw;
    MgMat m;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    u8 *rgb;
    s16 i;
    s16 n;
    s16 s;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[2][i] = 0;
        m.m[1][i] = 0;
        m.m[0][i] = 0;
    }
    n = 8;
    if (p->unk2 >= 7) {
        n = 15 - p->unk2;
    }
    rot.vy = 0;
    rot.vx = 0;
    rot.vz = p->unk14;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    s = 0x2000;
    if (p->unk16 < 4) {
        s = 0x1400;
    }
    m.m[0][0] = m.m[1][1] = m.m[2][2] = s;
    func_8003C21C(&rot, &lw);
    func_8003B05C(&m, &lw);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BD4B0 = p->unk16;
    D_801BD4AF = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801BD4AC;
    *rgb = D_801BD4AD = D_801BD4AE = n << 4;
    D_80163C74 = func_800D4D90(rgb - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (p->unk6 > 0) {
            p->unk6 = 0;
            p->unkE *= -1;
        }
        p->unkE += 20;
        p->unk14 += 0x200;
        p->unk2++;
        if (p->unk2 == 15) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_geki1/nonmatchings/text", func_801B0468);

INCLUDE_ASM("../asm/us/magic_geki1/nonmatchings/text", func_801B05EC);

INCLUDE_ASM("../asm/us/magic_geki1/nonmatchings/text", func_801B0854);

void func_801B0D98(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0854)];
    func_800D3994(arg1, D_8015190F[arg1][0], D_801D54D0);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_geki1/nonmatchings/text", func_801B0E5C);
