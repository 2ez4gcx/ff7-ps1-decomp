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

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0DBC);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0EB8);

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

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B10F4);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B1220);
