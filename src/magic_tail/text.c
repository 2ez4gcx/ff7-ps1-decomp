#include "common.h"
#include "magic_tail/decls.h"

void func_801B0000(void) {
    func_801B1568();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EAC84 = D_801D2C84 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D2BD0.unk0 = D_801D2BDC[p->unk16];
    D_801D2BD0.unk8 = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D2BD0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D2BDC[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0180(void) {
    s32 f;
    MgObjAwa *p;
    s16 *frame;
    s16 n;
    s32 c;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    n = p->unk2;
    f = n;
    if (f >= 8) {
        f = 7;
    }
    func_800D4368(&p->unk4, (s16)(n * 0xC0 + 0x2000), 0);
    frame = &D_801D2BFC;
    *frame = f;
    c = 0x60 - p->unk2 * 4;
    D_801D2BF8 = D_801D2BF9 = D_801D2BFA = c;
    D_801EAC84 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EAC84);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 24) {
            p->unk0 = -1;
        }
    }
}

void func_801B0294(void) {
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
    D_801D2C08 = p->unk16;
    D_801D2C07 = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801D2C04;
    *rgb = D_801D2C05 = D_801D2C06 = n << 4;
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

void func_801B04C4(void) {
    MgMat lw;
    MgMat m;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    u8 *rgb;
    s16 i;
    s32 c;

    p = &D_801621F0[D_801590D4];
    for (i = 0; i < 3; i++) {
        m.m[2][i] = 0;
        m.m[1][i] = 0;
        m.m[0][i] = 0;
    }
    rot.vz = p->unk14 + 0x400;
    rot.vx = 0;
    rot.vy = p->unk16;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x6000;
    func_8003B05C(&m, &D_800FA63C);
    func_8003C21C(&rot, &lw);
    func_8003B05C(&m, &lw);
    func_8003B48C(&m);
    func_8003B51C(&m);
    rgb = &D_801D2C10;
    c = -0x80 - p->unk2 * 16;
    *rgb = D_801D2C11 = D_801D2C12 = c;
    D_80163C74 = func_800D4D90(rgb - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B0684);

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B0894);

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B09E8);

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B0FA4);

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B144C);

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B1568);
