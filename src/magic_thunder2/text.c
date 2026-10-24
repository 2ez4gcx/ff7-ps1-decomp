#include "common.h"
#include "magic_thunder2/decls.h"

void func_801B0000(void) {
    func_801B147C();
}

void func_801B0020(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801EA20C = D_801D220C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 0xA);
        p->unk0 = -1;
    }
}

void func_801B00B0(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D2174.unk0 = D_801D2180[p->unk16];
    D_801D2174.unk8 = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D2174, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D2180[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B01A4(void) {
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
    frame = &D_801D2198;
    *frame = f;
    c = 0x60 - p->unk2 * 4;
    D_801D2194 = D_801D2195 = D_801D2196 = c;
    D_801EA20C = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EA20C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 24) {
            p->unk0 = -1;
        }
    }
}

void func_801B02B8(void) {
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
    D_801D21A4 = p->unk16;
    D_801D21A3 = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801D21A0;
    *rgb = D_801D21A1 = D_801D21A2 = n << 4;
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

void func_801B04E8(void) {
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
    rgb = &D_801D21AC;
    c = -0x80 - p->unk2 * 16;
    *rgb = D_801D21AD = D_801D21AE = c;
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

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B06A8);

void func_801B09F4(void) {
    MgSVec rot;
    MgMat lw;
    MgMat m;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vx = 0;
    rot.vy = p->unk2 << 6;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    D_801D21FC.vx = D_801D2204[0] = (p->unk2 << 8) + 0x3000;
    D_801D2200 = (p->unk2 << 8) + 0x2000;
    func_8003B35C(&m, &D_801D21FC);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D21EA[0] = 0x80 - p->unk2 * 4;
    D_801EA20C = (u8 *)func_800D29D4(&D_801D21EA[-5], D_801517C0 + 0x70, 0xC, (s32)D_801EA20C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 30) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B0B50);

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B0D44);

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B13B8);

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B147C);
