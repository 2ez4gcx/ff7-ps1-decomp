#include "common.h"
#include "magic_seald/decls.h"

void func_801B0054(void) {
    func_801B0E98();
}

INCLUDE_ASM("../asm/us/magic_seald/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_seald/nonmatchings/text", func_801B0330);

INCLUDE_ASM("../asm/us/magic_seald/nonmatchings/text", func_801B0388);

INCLUDE_ASM("../asm/us/magic_seald/nonmatchings/text", func_801B0728);

void func_801B07A0(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unkC;
    rot.vy = p->unk10;
    rot.vz = p->unk14;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk18;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801C22A8;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t >= 0xC) {
        ((MgScratch *)0x1F800000)->unkA = (t - 0xC) * 0x155;
    }
    func_8003B69C(0, 0, 0);
    D_801DB3AC = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DB3AC);
    if (p->unk2 >= 0x18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk10 += p->unk12;
        p->unk14 += p->unk16;
        p->unk2++;
    }
}

void func_801B0974(void) {
    MgSVec rot;
    u8 pad[8];
    MgMat m;
    MgVec scale;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk18;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    if (p->unk2 >= 0xC) {
        ((MgScratch *)0x1F800000)->unk0 = D_801C1084;
        ((MgScratch *)0x1F800000)->unk4 = 8;
        ((MgScratch *)0x1F800000)->unkA = 0x80;
        ((MgScratch *)0x1F800000)->unk8 = 0;
        ((MgScratch *)0x1F800000)->unkC = 0x20;
        ((MgScratch *)0x1F800000)->unkE = 0;
        D_801DB3AC = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DB3AC);
    } else {
        D_1F800000[0] = (s32)D_801C1084;
        D_1F800000[2] = 0xC;
        D_1F800000[1] = D_801517C0 + 0x70;
        D_1F800000[3] = D_801DB3AC;
        D_801DB3AC = func_801B0728((MgScratch *)0x1F800000, p->unk2);
    }
    if (p->unk2 >= 0xE) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0B3C(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;

    b = D_80162978;
    p = &b[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 1) {
            q = &b[func_800BBEAC(func_801B0974)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unk18 = p->unk18;
        }
        if (p->unk2 == 0xE) {
            func_800D5138(1);
        }
        if (p->unk2 == 0x10) {
            func_800D51D4(3);
        }
        if (p->unk2 == 0xF) {
            q = &b[func_800BBEAC(func_801B07A0)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unkC = 0;
            q->unkE = func_80042DA8() % 16 + 0x2A;
            q->unk10 = 0x10;
            q->unk12 = func_80042DA8() % 8 + 8;
            q->unk14 = 4;
            q->unk16 = func_80042DA8() % 24 + 0x20;
            q->unk18 = p->unk1A;
        }
        if (p->unk2 == 0x20) {
            func_800D5774(D_801DB3B4);
        }
        if (p->unk2 >= 0x2C) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_seald/nonmatchings/text", func_801B0D4C);

INCLUDE_RODATA("../asm/us/magic_seald/nonmatchings/text", D_801B0000);

s32 func_801B0E98(arg0) {
    s32 i;
    s32 n;

    D_801DB3B0 = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(D_801B0F64, 0, 0, 0);
    for (i = 0, n = 0; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801DB3B4 = i;
            }
        }
    }
    func_800BBEAC(func_801B0D4C);
    return func_800D55F4(0x20, func_800D574C(arg0), 0x16D);
}
