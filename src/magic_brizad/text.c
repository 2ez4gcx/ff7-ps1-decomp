#include "common.h"
#include "magic_brizad/decls.h"

void func_801B0000(void) {
    MgMat m;
    MgVec scale;
    MgTask *p;
    MgHalf *frame;
    s32 v;
    s32 t;
    s16 ang;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk18 * 0x36D;
    v = (p->unk2 * t) >> 12;
    if (v > 0x7FFF) {
        v = 0x7FFF;
    }
    scale.vz = v;
    scale.vy = v;
    scale.vx = v;
    if (p->unk2 < 0) {
        ang = 0;
    } else {
        ang = p->unk2 * 0x124;
    }
    func_8003C21C((MgSVec *)&p->unk8, &m);
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk10;
    m.t[1] = p->unk12;
    m.t[2] = p->unk14;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    frame = (MgHalf *)&D_801B100E;
    frame->v = ang;
    D_801D1014 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801D1014);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B018C(void) {
    MgTask *p;
    MgTask *q;
    s16 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0000)];
            a = p->unk4;
            func_800D3994(a, D_8015190F[a][0], &q->unk10);
            q->unkC = 0;
            q->unkA = 0;
            q->unk8 = 0;
            q->unk18 = func_800D55A4(p->unk4);
            func_800D5774(p->unk4);
            if (p->unk2 == 0) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B028C(s16 arg0) {
    D_8016297C[func_800BBEAC(&func_801B018C)].unk0 = arg0;
}

void func_801B02D4(s16 arg0) {
    D_8016297C[func_800BBEAC(&func_801B018C)].unk0 = arg0;
}

void func_801B031C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D1014 = D_801B1014 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B037C(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B031C);
    func_800D5444(arg0, arg1, 4, &func_801B02D4);
    func_800D55F4(0x20, func_800D574C(D_80151774), 0x18);
}
