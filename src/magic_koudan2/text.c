#include "common.h"
#include "magic_koudan2/decls.h"

void func_801B0030(void) {
    func_801B0FF0();
}

void func_801B0050(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E3A6C = D_801CBA6C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B00BC(void) {
    MgTask *p;
    u16 *frame;
    u32 c;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk18, 0);
    frame = &D_801CBA18;
    *frame = p->unk1A;
    c = (u32)(func_80039A74(p->unk2 << 7) * 5) >> 8;
    D_801CBA14 = D_801CBA15 = D_801CBA16 = c;
    D_801E3A6C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E3A6C);
    if (D_80062D98 == 0) {
        p->unk18 += 0x180;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        t = (u16)p->unk2 + 1;
        p->unk2 = t;
        if (t == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B01E4(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801CBA24[0] = p->unk2;
    *(MgAnim **)&D_801CBA24[-4] = D_801CBA28[p->unk1A];
    D_801E3A6C = func_800D4D90(&D_801CBA24[-4], D_801517C0 + 0x70, 0xC, D_801E3A6C);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 >= D_801CBA28[p->unk1A]->unk4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0308(void) {
    MgSVec v;
    MgTask *p;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 11; i++) {
        v.vx = p->unk4 * (6 - i) / 6;
        v.vy = p->unk6 * (6 - i) / 6;
        v.vz = p->unk8 * (6 - i) / 6;
        switch (i) {
        case 0:
            D_801CBA34[0] = D_801CB560;
            func_800D4368(&v, 0x1000, 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            break;
        case 1:
            D_801CBA34[0] = D_801CB580;
            func_800D4368(&v, 0x2000 + (func_80039A74(p->unk2 << 10) * 0x800 >> 12), 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            D_801CBA34[0] = D_801CB5A0;
            func_800D4368(&v, 0x1000, 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            D_801CBA34[0] = D_801CB5C0;
            func_800D4368(&v, 0x1000, 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            break;
        case 2:
            D_801CBA34[0] = D_801CB61C;
            func_800D4368(&v, 0x1000, 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            break;
        case 3:
            D_801CBA34[0] = D_801CB63C;
            func_800D4368(&v, 0x1000, 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            break;
        case 4:
            D_801CBA34[0] = D_801CB65C;
            func_800D4368(&v, 0x1000, 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            break;
        case 5:
            D_801CBA34[0] = D_801CB67C;
            func_800D4368(&v, 0x1000, 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            break;
        case 6:
            D_801CBA34[0] = D_801CB69C;
            func_800D4368(&v, 0x1000, 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            break;
        case 7:
            D_801CBA34[0] = D_801CB6BC;
            func_800D4368(&v, 0x1000, 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            break;
        case 8:
            D_801CBA34[0] = D_801CB6DC;
            func_800D4368(&v, 0x1000, 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            break;
        case 9:
            D_801CBA34[0] = D_801CB6FC;
            func_800D4368(&v, 0x1000, 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            break;
        case 10:
            D_801CBA34[0] = D_801CB71C;
            func_800D4368(&v, 0x1000, 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            break;
        case 11:
            D_801CBA34[0] = D_801CB73C;
            func_800D4368(&v, 0x1000, 0);
            D_801E3A6C = func_800D4D90(D_801CBA34, D_801517C0 + 0x70, 0xC, D_801E3A6C);
            break;
        }
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B0684(void) {
    MgMat m;
    MgMat r;
    s32 flag;
    s16 i;
    s32 t;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = p->unk2 * 0x320 + 0x1000;
    func_8003C21C(&D_801CBA50, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801CBA4A[0] = t << 8;
    D_801E3A6C = (u8 *)func_800D29D4(&D_801CBA4A[-5], D_801517C0 + 0x70, 0xC, (s32)D_801E3A6C);
    if (D_80062D98 == 0) {
        if (++p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_koudan2/nonmatchings/text", func_801B07FC);

void func_801B0F30(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B07FC)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B0FF0(arg0, arg1) {
    func_800BBEAC((M2C_UNK *)func_801B0050);
    func_800D2980(&D_801B106C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, (M2C_UNK *)func_801B0F30);
    func_800BBA84(0x188, arg1, 0x40);
}
