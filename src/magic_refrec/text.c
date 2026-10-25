#include "common.h"
#include "magic_refrec/decls.h"

void func_801B0000(void) {
    func_801B050C();
}

void func_801B0020(void) {
    MgVec scale;
    MgMat m;
    MgTask *p;
    s32 t;
    s32 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    scale.vx = scale.vy = scale.vz = (p->unk14 * D_801B0C10) >> 12;
    t = p->unk2;
    if (t < 8) {
        a = 0;
    } else {
        a = (t - 8) << 9;
    }
    a = a + (((0x1000 - a) * D_801B0C14) >> 12);
    func_8003C21C(&p->unkC, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    D_801B0C0A[0] = a;
    D_801D0C18 = func_800D29D4(&D_801B0C0A[-5], D_801517C0 + 0x70, 0xC, D_801D0C18);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x10) {
            p->unk0 = -1;
        } else {
            p->unk14 += p->unk16;
        }
    }
}

void func_801B01C0(void) {
    MgObjRef *p;
    MgObjRef *q;

    p = (MgObjRef *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgObjRef *)&D_80162978[func_800BBEAC(&func_801B0020)];
            q->unk4 = p->unk4;
            q->unkC = p->unkC;
            q->unk14 = 0x200;
            q->unk16 = 0x160;
        }
        if (p->unk2 == 8) {
            q = (MgObjRef *)&D_80162978[func_800BBEAC(&func_801B0020)];
            q->unk4 = p->unk4;
            q->unkC = p->unkC;
            q->unk14 = 0x200;
            q->unk16 = 0x180;
        }
        if (p->unk2 == 0x10) {
            q = (MgObjRef *)&D_80162978[func_800BBEAC(&func_801B0020)];
            q->unk4 = p->unk4;
            q->unkC = p->unkC;
            q->unk14 = 0x200;
            q->unk16 = 0x1A0;
        }
        if (p->unk2 == 0x18) {
            func_800D5774(p->unk18);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B03A8(s32 arg0) {
    MgTask *q;
    u8 *a;

    q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B01C0)];
    a = D_801518E4[arg0];
    func_800D3994(arg0, a[0x2B], (u8 *)&q->unk4);
    q->unk4 -= (func_80039A74(*(s16 *)(a + 0x162)) * *(s16 *)(a + 0x12)) >> 12;
    q->unk8 -= (func_80039B40(*(s16 *)(a + 0x162)) * *(s16 *)(a + 0x12)) >> 12;
    *(MgSVec *)&q->unkC = *(MgSVec *)(a + 0x160);
    q->unk18 = arg0;
}

void func_801B04AC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D0C18 = D_801B0C18 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B050C(arg0, arg1) {
    D_801B0C10 = 0x2000;
    D_801B0C14 = 0;
    func_800BBEAC(func_801B04AC);
    func_800D5444(arg0, arg1, 0, &func_801B03A8);
    return func_800D55F4(0x20, 0x40, 0x48);
}
