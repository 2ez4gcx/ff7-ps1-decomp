#include "common.h"
#include "magic_dokueki/decls.h"

void func_801B0000(void) {
    func_801B0840();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D8D34 = D_801C0D34 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;
    u8 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801C0D1C[0] = p->unk2;
    c = 0x60;
    if (p->unk1A == 4) {
        c = 0x40;
    }
    D_801C0D18 = D_801C0D19 = D_801C0D1A = c;
    *(MgAnim **)&D_801C0D1C[-4] = D_801C0D20[*(s16 *)((u8 *)p + 0x1A)];
    D_801D8D34 = func_800D4D90(&D_801C0D1C[-4], D_801517C0 + 0x70, 0xC, D_801D8D34);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801C0D20[p->unk1A]->unk4) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_dokueki/nonmatchings/text", func_801B01A8);

void func_801B02A4(void) {
    MgSVec rot;
    MgSVec pos;
    MgMat m;
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B01A8)];
        q->unk4 = p->unk4;
        q->unk6 = p->unk6;
        q->unk8 = p->unk8;
        q->unk1A = p->unk2 >> 1;
        pos.vx = 0;
        pos.vy = 0;
        pos.vz = p->unk18;
        rot.vx = 0;
        rot.vy = -func_80039A74(p->unk2 * 0x88) / 16;
        rot.vz = 0x200;
        func_8003C4AC(&rot, &m);
        func_8003C8DC(p->unk14, &m);
        func_8003B2CC(&m, &pos, (MgSVec *)&q->unkC);
        p->unk2++;
        if (p->unk2 == 0x20) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_dokueki/nonmatchings/text", func_801B03DC);

void func_801B0780(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B03DC)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B0840(arg0, arg1) {
    func_800D2980(&D_801B08DC, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B0780);
    D_8009A000 = 0x28;
    D_8009A004 = 0x40;
    D_8009A008 = 0xB2;
    func_8002DA7C();
    func_800BBEAC(func_801B0020);
}
