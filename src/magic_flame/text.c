#include "common.h"
#include "magic_flame/decls.h"

void func_801B0000(s32 arg0) {
    D_801DD870 = 0;
    func_801B1014();
    func_800D55F4(0x20, func_800D574C(arg0), 0x1DE);
}

void func_801B0048(void) {
    D_801DD870 = 1;
    func_801B1014(D_80151774);
    func_800D55F4(0x20, func_800D574C((s32) D_80151774), 0x1FA);
}

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B009C);

void func_801B00F0(s32 arg0) {
    D_801DD870 = 0;
    func_801B10F4();
    func_800D55F4(0x20, func_800D574C(arg0), 0x1DE);
}

void func_801B0138(void) {
    D_801DD870 = 1;
    func_801B10F4();
}

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0164);

void func_801B01B4(s32 arg0) {
    D_801DD870 = 0;
    func_801B1220();
    func_800D55F4(0x20, func_800D574C(arg0), 0x1DE);
}

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B01FC);

void func_801B03C0(void) {
    MgObj20 *p;
    s32 i;
    s32 off;
    s32 n;

    n = 0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 200; i++) {
        off = i * 0x20;
        if (*(s16 *)(&D_801DD874 + off) != -1) {
            func_801B01FC(&D_801DD874 + off);
            n++;
        }
    }
    if (n == 0 && D_80162080 < 3) {
        p->unk0 = -1;
    }
}

void func_801B0484(void) {
    s32 off;
    s16 c;

    c = -1;
    off = 0x18E0;
    do {
        *(s16 *)(&D_801DD874 + off) = c;
        off -= 0x20;
    } while (off >= 0);
}

MgObj20 *func_801B04B0(void) {
    s32 i;
    s32 off;

    for (i = 0; i < 200; i++) {
        off = i * 0x20;
        if (*(s16 *)(&D_801DD874 + off) == -1) {
            *(s16 *)(&D_801DD874 + off) = 0;
            *(s16 *)(&D_801DD874 + 2 + off) = 0;
            return (MgObj20 *)(&D_801DD874 + off);
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0514);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B082C);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0908);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0B38);

void func_801B0DBC(s32 arg0, s32 arg1) {
    MgTask *p;
    MgSVec v;
    u8 pad[8];

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B082C)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &v);
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    p->unkC = v.vx - p->unk4;
    p->unkE = v.vy - p->unk6;
    p->unk10 = v.vz - p->unk8;
}

void func_801B0EB8(s32 arg0, s32 arg1) {
    MgTask *p;
    MgSVec v;
    u8 pad[8];

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B082C)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &v);
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    p->unkC = v.vx - p->unk4;
    p->unkE = v.vy - p->unk6;
    p->unk10 = v.vz - p->unk8;
}

void func_801B0FB4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DD868 = D_801BD868 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B1014(arg0, arg1) {
    func_800D2980(&D_801B134C, 0, 0, 0);
    func_800BBEAC(&func_801B0FB4);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B0DBC);
}

void func_801B1084(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B134C, 0, 0, 0);
    func_800BBEAC(&func_801B0FB4);
    func_800D5444(arg0, arg1, 0, &func_801B0EB8);
}

void func_801B10F4(arg0, arg1) {
    MgSVec v;
    MgSVec w;
    MgTask *p;

    func_800D2980(&D_801B134C, 0, 0, 0);
    func_800BBEAC(func_801B0FB4);
    D_801DD86C = arg0;
    func_800D54EC(arg0, &v);
    v.vy = -0x1F4;
    func_800D3994(arg1, D_8015190F[arg1][0], &w);
    v.vx -= w.vx;
    v.vy -= w.vy;
    v.vz -= w.vz;
    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B0908)];
    p->unk0 = arg1;
    *(MgSVec *)&p->unkC = v;
    p->unk14 = 0x200;
    p->unk16 = -0x38;
}

void func_801B1220(arg0, arg1) {
    MgSVec v;
    MgSVec w;
    MgTask *p;

    func_800D2980(&D_801B134C, 0, 0, 0);
    func_800BBEAC(func_801B0FB4);
    D_801DD86C = arg0;
    func_800D54EC(arg0, &v);
    v.vy = -0x1F4;
    func_800D3994(arg1, D_8015190F[arg1][0], &w);
    v.vx -= w.vx;
    v.vy -= w.vy;
    v.vz -= w.vz;
    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B0B38)];
    p->unk0 = arg1;
    *(MgSVec *)&p->unkC = v;
    p->unk14 = 0x200;
    p->unk16 = -0x38;
}
