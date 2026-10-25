#include "common.h"
#include "magic_kinzan/decls.h"

void func_801B0000(void) {
    func_801B0678();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C90B4 = D_801B10B4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgMat r;
    MgMat m;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    s16 i;
    s16 n;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    n = 8;
    if (p->unk2 >= 0x16) {
        n = 0x1E - p->unk2;
    }
    rot.vx = p->unk14;
    rot.vy = p->unk14 >> 1;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x1000;
    func_8003C21C(&rot, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801B10A4 = p->unk16;
    D_801B10A0.v = D_801B10A1.v = D_801B10A2.v = n << 4;
    D_801B10A3 = n == 8 ? 0x2C : 0x2E;
    D_801C90B4 = func_800D4D90(D_801B109C, D_801517C0 + 0x70, 0xC, D_801C90B4);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (p->unk6 > 0) {
            p->unk6 = 0;
            t = p->unkE;
            p->unkE = -t;
        }
        p->unkE += 0x14;
        p->unk14 += 0x100;
        i = p->unk2 + 1;
        p->unk2 = i;
        if (i == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B02B0(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 a;
    s16 b;
    s16 x;
    u16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    x = D_801B10A8 * ((s16)((s16)t % 2) + 3) >> 2;
    D_80163C74 = func_800C4FC8(x, x, x >> 1);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x10) {
            D_801B10A8 += 4;
        }
        if (p->unk2 >= 0x37) {
            D_801B10A8 -= 4;
        }
        if (p->unk2 < 0x26) {
            for (i = 0; i < 3; i++) {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B008C)];
                q->unk4 = D_801B10AC.vx;
                q->unk6 = D_801B10AC.vy;
                q->unk8 = D_801B10AC.vz;
                a = func_80042DA8() % 0x1000;
                b = func_80042DA8() % 200;
                q->unkC = (func_80039A74(a) * b) >> 12;
                q->unk10 = (func_80039B40(a) * b) >> 12;
                q->unkE = -200 - func_80042DA8() % 200;
                q->unk16 = func_80042DA8() % 4;
                q->unk14 = func_80042DA8() % 0x1000;
            }
        }
        if (p->unk2 == 0x3C) {
            func_800D5774(p->unk18);
        }
        if (++p->unk2 == 0x46) {
            p->unk0 = -1;
        }
    }
}

void func_801B05B4(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B02B0)];
    func_800D3994(arg1, D_8015190F[arg1][9], &D_801B10AC);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk18 = arg0;
}

s32 func_801B0678(arg0, arg1) {
    func_800BBEAC(func_801B0020);
    func_800D2980(&D_801B06F4, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B05B4);
    func_800BBA84(0x11E, arg1, 0x40);
}
