#include "common.h"
#include "magic_threat/decls.h"

void func_801B0000(void) {
    func_801B0364();
}

void func_801B0020(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk14, 0);
    D_801B8550[0] = p->unk2;
    D_801D8554 = (u8 *)func_800D4D90(&D_801B8550[-4], D_801517C0 + 0x70, 0xC, (s32)D_801D8554);
    if (D_80062D98 == 0) {
        if (++p->unk2 >= D_801B8454) {
            p->unk0 = -1;
        }
    }
}

void func_801B00DC(void) {
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0020)];
        *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
        q->unk14 = 0x2000;
        if (++p->unk2 >= 0x10) {
            func_800D4D4C(p->unk16, 0x32);
            func_800D5774(p->unk16);
            p->unk0 = -1;
        }
    }
}

void func_801B01D8(s32 arg0, s32 arg1) {
    MgSVec d;
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B00DC)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &d);
    p->unkC = (d.vx - p->unk4) / 16;
    p->unkE = (d.vy - p->unk6) / 16;
    p->unk10 = (d.vz - p->unk8) / 16;
    p->unk16 = arg0;
}

void func_801B0304(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D8554 = D_801B8554 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B0364(arg0, arg1) {
    func_800D2980(&D_801B0410, 0, 0, 0);
    func_800BBEAC(func_801B0304);
    func_800D5444(arg0, arg1, 4, &func_801B01D8);
    return func_800D55F4(0x20, func_800D56A8(&D_801518F6[arg1][0xAB]), 0x31);
}
