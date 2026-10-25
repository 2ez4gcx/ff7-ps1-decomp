#include "common.h"
#include "magic_faira/decls.h"

void func_801B0000(void) {
    func_801B031C();
}

void func_801B0020(void) {
    MgMat m;
    MgVec unused;
    MgVec scale;
    MgTask *p;
    MgScratch *s;
    s32 k;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    s = (MgScratch *)0x1F800000;
    func_8003C21C(&D_801BD7B8, &D_801BD7C8);
    k = p->unkC;
    scale.vx = scale.vy = scale.vz = k;
    func_8003B35C(&D_801BD7C8, &scale);
    D_801BD7DC.v = p->unk4;
    D_801BD7E0.v = p->unk6;
    D_801BD7E4.v = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801BD7C8, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    s->unk0 = D_801BD3E4;
    s->unk4 = 8;
    s->unk8 = D_801BD7C0[(u16)p->unk2 & 3];
    v = p->unk2;
    if (v < 8) {
        s->unkA = (v + 1) * 14;
    } else if (v < 0x10) {
        s->unkA = 0x80;
    } else if (v < 0x18) {
        s->unkA = 0x80 - (v - 15) * 14;
    } else {
        p->unk0 = -1;
        return;
    }

    s->unkC = (((u16)p->unk2 >> 3) & 1) | 0x20;
    s->unkE = 0;
    D_801DD7E8 = (u8 *)func_800D29D4(s, D_801517C0 + 0x70, 0xC, (s32)D_801DD7E8);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B020C(s32 arg0) {
    MgTask *p;
    s32 v;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0020)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    p->unk6 = 0;
    v = func_800D55A4(arg0);
    if (v > 0x7FFF) {
        v = 0x7FFF;
    }
    p->unkC = v;
    func_800D5774(arg0);
}

void func_801B02BC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DD7E8 = D_801BD7E8 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B031C(arg0, arg1) {
    func_800D2980(&D_801B03A4, 0, 0, 0);
    func_800BBEAC(func_801B02BC);
    func_800D5444(arg0, arg1, 0, &func_801B020C);
    return func_800D55F4(0x20, func_800D574C(arg0), 0xA);
}
