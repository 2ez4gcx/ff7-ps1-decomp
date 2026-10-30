#include "common.h"
#include "magic_hatena/decls.h"

void func_801B0054(void) {
    func_801B105C();
}

INCLUDE_ASM("../asm/us/magic_hatena/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_hatena/nonmatchings/text", func_801B02AC);

INCLUDE_ASM("../asm/us/magic_hatena/nonmatchings/text", func_801B0544);

INCLUDE_ASM("../asm/us/magic_hatena/nonmatchings/text", func_801B0764);

INCLUDE_ASM("../asm/us/magic_hatena/nonmatchings/text", func_801B09E4);

void func_801B0A90(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;

    rot.vy = 0xABE;
    rot.vx = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6 + p->unk10;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unkC;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_1F800000[0] = (s32)&D_801BA544;
    D_1F800000[2] = 0xC;
    D_1F800000[1] = D_801517C0 + 0x70;
    D_1F800000[3] = D_801D3204;
    D_801D3204 = func_801B09E4(0x1F800000);
    if (p->unk2 >= 0x18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x12) {
            func_800D5774(D_801D320C);
        }
        if (p->unk2 < 6) {
            p->unk10 += p->unk12;
        }
        if (p->unk2 == 6) {
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0xA6);
        }
        p->unk2++;
    }
}

void func_801B0C50(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    frame = &D_801BB200;
    *frame = p->unk2;
    func_800D4368(&p->unk4, p->unkC, 0);
    D_801D3204 = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801D3204);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unk10;
        p->unk8 += p->unk12;
        p->unk2++;
    }
}

void func_801B0D2C(void) {
    MgVec v;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 d;
    s32 w;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((u16)(p->unk2 - 6) < 4U) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(&func_801B0C50)];
                v.vx = func_80042DA8() % 1800 - 0x384;
                v.vy = 0;
                v.vz = func_80042DA8() % 1800 - 0x384;
                func_8003A08C(&v, &v);
                d = func_80042DA8() % 400 + 0x258;
                q->unk4 = p->unk4 + (d * v.vx >> 12);
                q->unk6 = 0;
                q->unk8 = p->unk8 + (d * v.vz >> 12);
                q->unkC = p->unkC;
                w = func_80042DA8() % 32 + 0x64;
                q->unk10 = w * v.vx >> 12;
                i++;
                q->unk12 = w * v.vz >> 12;
            } while (i < 20);
        }
        if (p->unk2 >= 0x18) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0F60(void) {
    MgTask *p;
    MgTask *q;
    MgTask *b;

    D_80162978[D_8015169C].unk0 = -1;
    b = D_80162978;
    p = &b[func_800BBEAC(&func_801B0A90)];
    func_800D3994(D_801D320C, D_8015190F[D_801D320C][0], &p->unk4);
    p->unkC = 0xDB6;
    p->unk10 = -0xDAC;
    p->unk6 = 0;
    p->unk12 = 0x247;
    q = &b[func_800BBEAC(&func_801B0D2C)];
    *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
    q->unkC = 0x1B6D;
}

INCLUDE_RODATA("../asm/us/magic_hatena/nonmatchings/text", D_801B0000);

s32 func_801B105C(arg0) {
    s32 i;
    s32 n;

    D_801D3208 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B1128, 0, 0, 0);
    i = 0;
    n = 0;
    for (; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801D320C = i;
            }
        }
    }
    func_800BBEAC(&func_801B0F60);
    return func_800D55F4(0x20, func_800D574C(arg0), 0x85);
}
