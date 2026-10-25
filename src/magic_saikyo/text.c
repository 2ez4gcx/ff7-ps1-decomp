#include "common.h"
#include "magic_saikyo/decls.h"

void func_801B0000(void) {
    func_801B10A8();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EE0F4 = D_801D60F4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B0274);

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B035C);

void func_801B0758(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    D_801D607C[0] = p->unk2;
    D_801EE0F4 = func_800D4D90(&D_801D607C[-4], D_801517C0 + 0x70, 0xC, D_801EE0F4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D5DA4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0810(void) {
    MgMat m;
    MgMat m2;
    MgSVec rot;
    MgTask *p;
    s32 *q;

    rot.vx = rot.vy = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vz = p->unk14;
    func_8003BF8C(&rot, &m);
    q = &D_801D60D4;
    *q = D_801D60D8 = D_801D60DC = 0x1000;
    func_8003B35C(&m, q);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    D_801D608A[0] = 0x80 - p->unk2 * 8;
    *(u8 **)&D_801D608A[-5] = D_801D6090[p->unk16];
    D_801EE0F4 = (u8 *)func_800D29D4(&D_801D608A[-5], D_801517C0 + 0x70, 0xC, (s32)D_801EE0F4);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x190;
        p->unk14 += 0x100;
        if (++p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B0980(void) {
    MgTask *p;
    u8 c;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D60A8[0] = p->unk16;
    c = 0x80 - p->unk2 * 8;
    D_801D60A6 = c;
    D_801D60A5 = c;
    D_801D60A4 = c;
    D_801EE0F4 = func_800D4D90(&D_801D60A8[-4], D_801517C0 + 0x70, 0xC, D_801EE0F4);
    if (D_80062D98 == 0) {
        p->unk6 -= 300;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 15) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B0A68);

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B0F3C);

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B10A8);
