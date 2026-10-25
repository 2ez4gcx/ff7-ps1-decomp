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

void func_801B03DC(void) {
    MgTask *p;
    MgTask *q;
    MgSVec rot;
    MgSVec pos;
    MgMat m;
    u16 n;
    s16 a;
    s32 v;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B02A4)];
            q->unk14 = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            pos.vx = (u16)p->unkC - (u16)q->unk4;
            pos.vz = (u16)p->unk10 - (u16)q->unk8;
            q->unk18 = func_80039F5C(pos.vx * pos.vx + pos.vz * pos.vz) / 24;
        }
        if (p->unk2 == 0x32) {
            func_800D5774(p->unk1C);
            D_8009A000 = 0x29;
            D_8009A004 = 0x40;
            D_8009A008 = 0x95;
            func_8002DA7C();
        }
        n = p->unk2;
        if ((u32)(n - 0x29) < 7U) {
            a = (s16)n * 0x200 - 0x5400;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B008C)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            q->unk4 += func_80039B40(a) * 0x320 >> 12;
            v = func_80039A74(a);
            q->unk1A = 1;
            q->unk6 += v * 0x320 >> 12;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B008C)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            k = 0x12C;
            q->unk4 = q->unk4 - k + func_80042DA8() % 600;
            k = 0x12C;
            q->unk6 = q->unk6 - k + func_80042DA8() % 600;
            k = 0x12C;
            q->unk8 = q->unk8 - k + func_80042DA8() % 600;
            q->unk1A = 0;
        }
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

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
