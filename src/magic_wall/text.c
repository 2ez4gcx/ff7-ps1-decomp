#include "common.h"
#include "magic_wall/decls.h"

void func_801B0000(void) {
    func_801B074C();
}

void func_801B0020(void) {
    MgVec scale;
    MgMat m;
    MgTask *p;
    s32 t;
    s32 a;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x10) {
        k = -(t << 13) / 16 + 0x3000;
    } else {
        k = 0x1000;
    }
    scale.vx = scale.vy = scale.vz = (k * D_801D1710) >> 12;
    t = p->unk2;
    if (t < 8) {
        a = 0x1000 - (t << 9);
    } else {
        t -= 8;
        if (t < 0x10) {
            a = 0;
        } else {
            t -= 0x10;
            if (t < 8) {
                a = t << 9;
            }
        }
    }
    a = a + (((0x1000 - a) * D_801D1714) >> 12);
    func_8003C21C(&p->unkC, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    D_801B16F6[0] = a;
    D_801D170C = func_800D29D4(&D_801B16F6[-5], D_801517C0 + 0x70, 0xC, D_801D170C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x20) {
            p->unk0 = -1;
        }
    }
}

void func_801B0200(void) {
    MgVec scale;
    MgMat m;
    MgTask *p;
    s32 t;
    s32 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    scale.vx = scale.vy = scale.vz = ((-(p->unk2 << 13) / 16 + 0x3000) * D_801D1710) >> 12;
    t = p->unk2;
    if (t < 8) {
        a = 0x1000 - (t << 9);
    } else {
        t -= 8;
        if (t < 8) {
            a = t << 9;
        }
    }
    a = a + (((0x1000 - a) * D_801D1714) >> 12);
    func_8003C21C(&p->unkC, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    D_801B1706[0] = a;
    D_801D170C = func_800D29D4(&D_801B1706[-5], D_801517C0 + 0x70, 0xC, D_801D170C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B03B4(void) {
    MgObjRef *p;
    MgObjRef *q;

    p = (MgObjRef *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgObjRef *)&D_80162978[func_800BBEAC(func_801B0020)];
            q->unkC = p->unkC;
            q->unk4 = p->unk4;
        }
        if (p->unk2 == 4) {
            q = (MgObjRef *)&D_80162978[func_800BBEAC(func_801B0200)];
            q->unkC = p->unkC;
            q->unk4 = p->unk4;
        }
        if (p->unk2 == 8) {
            q = (MgObjRef *)&D_80162978[func_800BBEAC(func_801B0200)];
            q->unkC = p->unkC;
            q->unk4 = p->unk4;
        }
        if (p->unk2 == 0x10) {
            func_800D5774(p->unk14);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B056C(s32 arg0) {
    MgTask *q;
    u8 *a;

    q = (MgTask *)&D_80162978[func_800BBEAC(func_801B03B4)];
    a = D_801518E4[arg0];
    func_800D3994(arg0, a[0x2B], (u8 *)&q->unk4);
    q->unk4 -= (func_80039A74(*(s16 *)(a + 0x162)) * *(s16 *)(a + 0x12)) >> 12;
    q->unk8 -= (func_80039B40(*(s16 *)(a + 0x162)) * *(s16 *)(a + 0x12)) >> 12;
    *(MgSVec *)&q->unkC = *(MgSVec *)(a + 0x160);
    q->unk14 = arg0;
}

void func_801B0670(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D170C = D_801B170C + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B06D0(s32 arg0, M2C_UNK arg1) {
    D_801D1710 = 0x1000;
    D_801D1714 = 0xD00;
    func_800BBEAC(&func_801B0670);
    func_800D5444(arg0, arg1, 0, &func_801B056C);
    func_800D55F4(0x20, 0x40, 0x44);
}

s32 func_801B074C(arg0, arg1) {
    D_801D1710 = 0x1800;
    D_801D1714 = 0x800;
    func_800BBEAC((s32 *) func_801B0670);
    func_800D5444(arg0, arg1, 0, &func_801B056C);
    return func_800D55F4(0x20, 0x40, 0x44);
}

void func_801B07C8(s32 arg0, M2C_UNK arg1) {
    D_801D1710 = 0x2000;
    D_801D1714 = 0;
    func_800BBEAC(&func_801B0670);
    func_800D5444(arg0, arg1, 0, &func_801B056C);
}
