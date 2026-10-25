#include "common.h"
#include "magic_q_ketsu/decls.h"

void func_801B007C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801BDA98;
    *frame = p->unk2;
    D_801D5AE8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D5AE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801BD9CC) {
            p->unk0 = -1;
        }
    }
}

void func_801B0138(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801BDAA4[0] = p->unk2 % D_801BDAA8[p->unk14]->unk4;
    *(MgAnim **)&D_801BDAA4[-4] = D_801BDAA8[p->unk14];
    D_801D5AE8 = func_800D4D90(&D_801BDAA4[-4], D_801517C0 + 0x70, 0xC, D_801D5AE8);
    if (D_80062D98 == 0) {
        p->unk6 += 0x64;
        p->unk2++;
        if (p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B0264(void) {
    MgSVec v;
    MgTask *p;
    s16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    v.vx = p->unk4 + (func_80039A74(p->unk14) * p->unk18 >> 12);
    v.vz = p->unk8 + (func_80039B40(p->unk14) * p->unk18 >> 12);
    v.vy = p->unk6 + p->unk1A;
    func_800D4368(&v, 0x2000, 0);
    frame = &D_801BDAB8;
    *frame = p->unk2 % D_801BD8E4;
    D_801D5AE8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D5AE8);
    if (D_80062D98 == 0) {
        p->unk1A -= 0x32;
        p->unk14 += 0x80;
        p->unk18 -= p->unk18 / 10;
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B03FC(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801BDAC4;
    *frame = p->unk2;
    D_801D5AE8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D5AE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801BD84C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_q_ketsu/nonmatchings/text", func_801B04B4);

INCLUDE_ASM("../asm/us/magic_q_ketsu/nonmatchings/text", func_801B08E0);

INCLUDE_ASM("../asm/us/magic_q_ketsu/nonmatchings/text", func_801B0C5C);

void func_801B0F5C(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B0C5C)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    p->unk1E = arg1;
}

INCLUDE_RODATA("../asm/us/magic_q_ketsu/nonmatchings/text", D_801B0010);

void func_801B1028(arg0, arg1) {
    func_800BBEAC(D_801B0010);
    func_800D2980(D_801B10A4, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0F5C);
    func_800BBA84(0x7E, arg1, 0x40);
}
