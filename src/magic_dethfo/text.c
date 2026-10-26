#include "common.h"
#include "magic_dethfo/decls.h"

void func_801B0054(void) {
    func_801B0A90();
}

void func_801B0074(void) {
    MgTask *p;
    s8 *frame;
    s16 t;
    s32 n;

    p = &D_80162978[D_8015169C];
    frame = &D_801B880C;
    n = p->unk2;
    *frame = n << 5;
    t = p->unk18;
    func_800D4368(&p->unk4, t, -(t >> 4));
    D_801D0818 = func_800D6260(frame - 4, D_801517C0 + 0x70, 0xC, D_801D0818);
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0144(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;
    MgTask *q;
    MgScratch *s;
    s32 rad;
    s32 diam;
    s32 k;
    s32 n;
    s32 t;
    s32 w;

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
    s = (MgScratch *)0x1F800000;
    s->unk0 = &D_801B7920;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t < 8) {
        ((MgScratch *)0x1F800000)->unkA = 0x1000 - (t << 9);
    } else if (t >= 0x10) {
        ((MgScratch *)0x1F800000)->unkA = (t - 0x10) << 9;
    }
    func_8003B69C(0, 0, 0);
    D_801D0818 = func_800D29D4(s, D_801517C0 + 0x70, 0xC, D_801D0818);
    if (p->unk2 >= 0x18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x14) {
            w = p->unk1A;
            k = (w << 12) / 350;
            rad = w;
            diam = rad << 1;
            n = 0;
            do {
                q = &D_80162978[func_800BBEAC(&func_801B0074)];
                *(DfB8 *)&q->unk4 = *(DfB8 *)&p->unk4;
                q->unk4 = q->unk4 + (func_80042DA8() % diam - rad);
                q->unk6 = q->unk6 + (func_80042DA8() % diam - rad);
                q->unk8 = q->unk8 + (func_80042DA8() % diam - rad);
                q->unk18 = ((s16)(func_80042DA8() % 0x1000 + 0x800) * k) >> 12;
                n++;
            } while (n < 4);
        }
        p->unkC += p->unkE;
        p->unk10 += p->unk12;
        p->unk14 += p->unk16;
        p->unk2++;
    }
}

s32 func_801B04CC(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801B8004[a];
        } else {
            r = D_801B8004[0x800 - a];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801B8004[a - 0x800];
        } else {
            r = -D_801B8004[0x1000 - a];
        }
    }
    return r;
}

void func_801B0570(s32 amp, s32 step, s32 phase, s32 bright) {
    DfSpr *p;
    s32 kx;
    s32 v;
    s16 i;
    s32 uv;
    s32 n;
    s32 col;
    s32 wh;

    col = (bright << 16) + (bright << 8) + bright;
    i = 0;
    uv = 0x3FF00000;
    p = (DfSpr *)D_801D0818;
    wh = 0x200A6;
    kx = 0x4D;
    n = 0;
    do {
        if (amp != 0) {
            v = amp * func_801B04CC(phase) >> 12;
            phase += step;
        } else {
            v = 0;
        }
        *(s16 *)((u8 *)p + 0xA) = i;
        i++;
        *(s32 *)((u8 *)p + 0xC) = uv;
        uv += 0x100;
        n++;
        *(s32 *)((u8 *)p + 4) = col;
        *(s16 *)((u8 *)p + 8) = kx + v;
        *(s32 *)((u8 *)p + 0x10) = wh;
        *((u8 *)p + 3) = 4;
        *((u8 *)p + 7) = 0x66;
        p->tag.addr = ((DfTag *)D_801517C0 + 0x20)->addr;
        ((DfTag *)D_801517C0 + 0x20)->addr = (u32)p;
        p++;
    } while (n < 0xA6);
    func_80044A68(p, 0, 1, 0xAC, 0);
    p->tag.addr = ((DfTag *)D_801517C0 + 0x20)->addr;
    D_801D0818 = (s32)p + 0xC;
    ((DfTag *)D_801517C0 + 0x20)->addr = (u32)p;
}

INCLUDE_ASM("../asm/us/magic_dethfo/nonmatchings/text", func_801B073C);

INCLUDE_ASM("../asm/us/magic_dethfo/nonmatchings/text", func_801B09A0);

INCLUDE_RODATA("../asm/us/magic_dethfo/nonmatchings/text", D_801B0000);

s32 func_801B0A90(arg0) {
    s32 i;
    s32 n;

    D_801D081C = &D_80162978[func_800BBEAC((M2C_UNK *)D_801B0000)];
    func_800D2980(&D_801B0B5C, 0, 0, 0);
    i = 0;
    n = 0;
    do {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801D0820 = i;
            }
        }
        i++;
    } while (i < 10);
    func_800BBEAC((M2C_UNK *)func_801B09A0);
    return func_800D55F4(0x20, func_800D574C(arg0), 0x169);
}
