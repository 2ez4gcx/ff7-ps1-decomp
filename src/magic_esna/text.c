#include "common.h"
#include "magic_esna/decls.h"

void func_801B0000(void) {
    func_801B051C();
}

void func_801B0020(void) {
    MgTask *p;
    MgSVec *sv;
    MgMat *m;
    s32 t;
    s32 d;
    s32 v;

    m = (MgMat *)0x1F800008;
    sv = (MgSVec *)0x1F800000;
    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xD) {
        D_801B481C = D_801B481D = D_801B481E = 0x80;
    } else {
        d = t - 0xD;
        if (d < 4) {
            v = -(d << 7) / 4 - 0x80;
            D_801B481C = D_801B481D = D_801B481E = v;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_800D4368((MgSVec *)&p->unk8, p->unk1A, 0);
    D_801D483C = func_800D6260(D_801B4814, D_801517C0 + 0x70, 0xC, D_801D483C);
    if (D_80062D98 == 0) {
        p->unk2++;
        sv->vx = p->unk18;
        sv->vy = 0;
        sv->vz = 0;
        func_8003C21C((MgSVec *)&p->unk10, m);
        func_8003B2CC(m, sv, sv);
        p->unk8 += sv->vx >> 4;
        p->unkA += sv->vy >> 4;
        p->unkC += sv->vz >> 4;
        p->unk18 -= p->unk18 >> 3;
        p->unk14 += (-0x400 - p->unk14) >> 2;
        p->unk10 += p->unk1C;
    }
}

void func_801B01E0(void) {
    MgObjAlm *p;
    MgObjAlm *q;
    s32 i;

    p = (MgObjAlm *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 10) {
            i = 0;
            D_801B4826[0] = func_80042DA8() & 0xFFF;
            for (; i < D_801B4834; i++) {
                q = (MgObjAlm *)&D_80162978[func_800BBEAC(&func_801B0020)];
                q->unk8 = p->unk8;
                q->unk1A = func_80042DA8() % 0x800 + 0x800;
                q->unk10 = *(MgSVec *)&D_801B4826[-1];
                q->unk18 = (func_80042DA8() % 400 + 100) << 4;
                q->unk1C = func_80042DA8() % 100 - 50;
                D_801B4826[0] += 0x1000 / D_801B4834;
            }
        } else {
            func_800D5774(p->unk4);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0404(s32 arg0) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B01E0)];
    p->unk4 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], (u8 *)&p->unk8);
    p->unkA = 0;
    if (D_801B4838 >= 4) {
        func_800D55F4(0x20, func_800D56A8((u8 *)&p->unk8), 0x8B);
    }
}

void func_801B04BC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D483C = D_801B483C + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B051C(arg0, arg1) {
    s32 r;
    s32 v;

    func_800D2980(&D_801B05F4, 0, 0, 0);
    func_800BBEAC(func_801B04BC);
    r = func_800D54BC(arg0);
    D_801B4838 = r;
    v = 3;
    if (r == 1) {
        v = 6;
    }
    D_801B4834 = v;
    func_800D5444(arg0, arg1, -(r >= 4) & 0xA, &func_801B0404);
    if (D_801B4838 < 4) {
        func_800D55F4(0x20, func_800D574C(arg0), 0x8B);
    }
}
