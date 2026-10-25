#include "common.h"
#include "magic_jibasiri/decls.h"

void func_801B0000(void) {
    func_801B1094();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D98F0 = D_801C18F0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801C1888.unk0 = D_801C1894[p->unk16];
    D_801C1888.unk8 = p->unk2;
    D_80163C74 = func_800D4D90(&D_801C1888, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801C1894[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0180(void) {
    MgSVec rot;
    MgMat lw;
    MgMat m;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vx = 0;
    rot.vy = p->unk2 << 6;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    D_801C18E0.vx = D_801C18E8[0] = (p->unk2 << 8) + 0x3000;
    D_801C18E4 = (p->unk2 << 8) + 0x2000;
    func_8003B35C(&m, &D_801C18E0);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801C18A6[0] = 0x80 - p->unk2 * 4;
    D_801D98F0 = (u8 *)func_800D29D4(&D_801C18A6[-5], D_801517C0 + 0x70, 0xC, (s32)D_801D98F0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 30) {
            p->unk0 = -1;
        }
    }
}

void func_801B02DC(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801C18B4;
    *frame = p->unk2;
    D_801D98F0 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D98F0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801C17C4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0394(void) {
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
    D_801C18C0 = p->unk16;
    D_801C18BF = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801C18BC;
    *rgb = D_801C18BD = D_801C18BE = n << 4;
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

INCLUDE_ASM("../asm/us/magic_jibasiri/nonmatchings/text", func_801B05C4);

INCLUDE_ASM("../asm/us/magic_jibasiri/nonmatchings/text", func_801B0748);

INCLUDE_ASM("../asm/us/magic_jibasiri/nonmatchings/text", func_801B09B0);

void func_801B0FD0(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B09B0)];
    func_800D3994(arg1, D_8015190F[arg1][0], D_801D98F4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B1094(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B1100, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0FD0);
}
