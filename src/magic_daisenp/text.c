#include "common.h"
#include "magic_daisenp/decls.h"

void func_801B0054(void) {
    D_801CF2F4 = 0;
    func_801B0E38();
}

void func_801B007C(void) {
    D_801CF2F4 = 1;
    func_801B0E38();
}

void func_801B00A8(void) {
    MgSVec rot;
    MgSVec pos;
    MgMat m;
    MgTask *p;
    u16 *frame;
    u16 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801B72DC;
    *frame = p->unk2;
    rot.vx = 0;
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    pos.vx = p->unk12;
    pos.vy = 0;
    pos.vz = 0;
    func_8003B2CC(&m, &pos, &pos);
    pos.vx += p->unk4;
    pos.vy += p->unk6;
    pos.vz += p->unk8;
    t = p->unk10;
    func_800D4368(&pos, (s16)t, -((s16)t >> 2));
    D_801CF2EC = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801CF2EC);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk6 += p->unk14;
        p->unkC -= p->unkE;
        p->unk2++;
        p->unk10 += (s16)p->unk10 >> 8;
        p->unk12 += p->unk16;
        p->unk16 += (s16)p->unk16 >> 4;
    }
}

void func_801B0250(void) {
    MgVec d;
    MgTask *p;
    MgSVec *q;
    s32 i;
    s32 j;
    s32 k;
    s32 t;
    s16 v;

    p = &D_80162978[D_8015169C];
    i = 0;
    D_801B72E8.v = p->unk2;
    k = p->unk18;
    q = &D_801CFCB8;
    j = k * 8;
    do {
        k++;
        if (D_80062D98 == 0) {
            d.vx = q->vx - *(s16 *)(D_801CF300 + j);
            d.vy = q->vy - *(s16 *)(D_801CF302 + j);
            d.vz = q->vz - *(s16 *)(D_801CF304 + j);
            t = func_80039F5C(func_8003A08C(&d, &d)) >> 5;
            *(s16 *)(D_801CF300 + j) += t * d.vx >> 12;
            *(s16 *)(D_801CF302 + j) += t * d.vy >> 12;
            *(s16 *)(D_801CF304 + j) += t * d.vz >> 12;
        }
        do {
            v = *(u16 *)(D_801CF306 + j);
            func_800D4368(D_801CF300 + j, v, -(v >> 2));
            j += 8;
            D_801CF2EC = func_800D4D90(D_801B72E0, D_801517C0 + 0x70, 0xC, D_801CF2EC);
        } while (0);
        i++;
        if (k >= 0x137) {
            j = 0;
            k = 0;
        }
    } while (i < 4);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_daisenp/nonmatchings/text", func_801B04AC);

void func_801B0B18(void) {
    MgSVec l;
    MgSVec a;
    MgTask *b;
    MgTask *q;
    s32 d;
    s32 *e;
    s32 n;
    s32 r;
    s32 r2;

    D_80162978[D_8015169C].unk0 = -1;
    b = D_80162978;
    q = &b[func_800BBEAC(&func_801B04AC)];
    func_800D54EC(D_801CF2F8, &q->unk4);
    q->unk6 = 0;
    if (D_801CF2F4 != 0) {
        r = func_80042DA8();
        q->unkC = r % 0x1000;
        d = 0xFC0;
        r2 = func_80042DA8();
        q->unk10 = 0xD80;
        q->unk12 = 0x1B00;
        q->unk14 = 0x2507;
        q->unkE = r2 % 96 + 0x48;
        l.vx = (func_80042DA8() % d - 0x7E0) * 3;
        l.vz = (func_80042DA8() % d - 0x7E0) * 3;
        a.vx = q->unk4 - l.vx;
        a.vy = 0;
        a.vz = q->unk8 - l.vz;
        l.vx = q->unk4 + l.vx;
        l.vy = 0;
        l.vz = q->unk8 + l.vz;
        *(MgSVec *)&q->unk4 = D_801CFCC0 = l;
        D_801CFCCC = 0;
        e = &D_801CFCC8;
        *e = a.vx - l.vx;
        D_801CFCD0 = a.vz - l.vz;
        n = func_80039F5C(func_8003A08C(e, e)) / 60;
        D_801CFCD8.vy = 0;
        D_801CFCE8.vy = 0;
        D_801CFCD8.vz = *e;
        D_801CFCD8.vx = -D_801CFCD0;
        D_801CFCE8.vx = n * *e >> 12;
        D_801CFCE8.vz = n * D_801CFCD0 >> 12;
        q->unk18 = n;
    } else {
        q->unk10 = 0x900;
        q->unk12 = 0x1200;
        q->unk14 = 0x1EA0;
    }
    D_801CFCB8 = *(MgSVec *)&q->unk4;
}

INCLUDE_RODATA("../asm/us/magic_daisenp/nonmatchings/text", D_801B0000);

void func_801B0E38(arg0) {
    D_801CF2F0 = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(D_801B0ED8, 0, 0, 0);
    func_800BBEAC(&func_801B0B18);
    D_801CF2F8 = arg0;
    D_801CF2FC = 0;
    func_800D55F4(0x20, func_800D574C(arg0), 0x16A);
}
