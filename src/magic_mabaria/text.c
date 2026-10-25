#include "common.h"
#include "magic_mabaria/decls.h"

void func_801B0000(void) {
    func_801B053C();
}

void func_801B0020(void) {
    MgMat m;
    MgVec scale;
    MgTask *p;
    MgHalf *frame;
    s32 v;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    v = ((p->unk2 * 0x3BFF / 16 + 0x400) * D_801B0CA0) >> 12;
    scale.vz = v;
    scale.vy = v;
    scale.vx = v;
    if (p->unk2 < 8) {
        k = 0;
    } else {
        k = (p->unk2 - 8) << 9;
    }
    k = k + (((0x1000 - k) * D_801B0CA4) >> 12);
    func_8003C21C((MgSVec *)&p->unkC, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    frame = (MgHalf *)&D_801B0C9A;
    frame->v = k;
    D_801D0CA8 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801D0CA8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B01C0(void) {
    MgTask *base;
    MgTask *p;
    MgTask *q;

    base = (MgTask *)D_80162978;
    p = base + D_8015169C;
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = base + func_800BBEAC(func_801B0020);
            *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
            *(MgSVec *)&q->unkC = *(MgSVec *)&p->unkC;
        }
        if (p->unk2 == 4) {
            q = base + func_800BBEAC(func_801B0020);
            *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
            *(MgSVec *)&q->unkC = *(MgSVec *)&p->unkC;
        }
        if (p->unk2 == 8) {
            q = base + func_800BBEAC(func_801B0020);
            *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
            *(MgSVec *)&q->unkC = *(MgSVec *)&p->unkC;
        }
        if (p->unk2 == 0x10) {
            func_800D5774(p->unk14);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0378(arg0) {
    MgTask *p;
    s32 a;

    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B01C0)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    p->unk4 -= (func_80039A74(D_80151A46[arg0][0]) * D_801518F6[arg0][0]) >> 12;
    p->unk8 -= (func_80039B40(D_80151A46[arg0][0]) * D_801518F6[arg0][0]) >> 12;
    *(MgSVec *)&p->unkC = *(MgSVec *)D_80151A44[arg0];
    p->unk14 = arg0;
}

void func_801B04DC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D0CA8 = D_801B0CA8 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B053C(arg0, arg1) {
    D_801B0CA0 = 0x2000;
    D_801B0CA4 = 0;
    func_800BBEAC(func_801B04DC);
    func_800D5444(arg0, arg1, 0, &func_801B0378);
    return func_800D55F4(0x20, 0x40, 0x43);
}
