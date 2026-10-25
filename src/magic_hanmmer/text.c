#include "common.h"
#include "magic_hanmmer/decls.h"

void func_801B0054(void) {
    func_801B0810();
}

void func_801B0074(void) {
    MgSVec a;
    MgSVec b;
    MgSVec c;
    MgMat m;
    MgMat n;
    MgVec scale;
    MgTask *p;

    a.vx = 0;
    a.vy = 0;
    p = &D_80162978[D_8015169C];
    a.vz = p->unkC;
    func_8003BF8C(&a, &m);
    c.vx = p->unk16;
    c.vy = 0;
    c.vz = 0;
    b.vx = 0;
    b.vy = p->unk10 + 0x400;
    b.vz = 0;
    func_8003BF8C(&b, &n);
    func_8003A79C(&n, &m, &m);
    func_8003B27C(&n, &c, (MgVec *)m.t);
    m.t[0] += p->unk4;
    m.t[1] += p->unk6 - p->unk18;
    m.t[2] += p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk12;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = &D_801B087C;
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801C9BF0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801C9BF0);
    if (p->unk2 >= 0x1A) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x10) {
            func_800D5774(p->unk1A);
        }
        if ((u16)(p->unk2 - 0xA) < 4U) {
            p->unkC += p->unkE;
        }
        if (p->unk2 < 8) {
            p->unk12 += p->unk14;
        }
        p->unk2++;
    }
}

void func_801B02B8(void) {
    MgTask *p;
    s8 *frame;
    s32 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801B1BE4;
    t = p->unk2 << 5;
    *frame = t;
    func_800D4368(&p->unk4, p->unk12, 0);
    D_801C9BF0 = func_800D6260(frame - 4, D_801517C0 + 0x70, 0xC, D_801C9BF0);
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unk16;
        p->unk8 += p->unk18;
        p->unk2++;
    }
}

void func_801B0398(void) {
    MgVec v;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 d;
    s32 w;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((u16)(p->unk2 - 0xE) < 4U) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(func_801B02B8)];
                v.vx = func_80042DA8() % 1200 - 0x258;
                v.vy = 0;
                v.vz = func_80042DA8() % 1200 - 0x258;
                func_8003A08C(&v, &v);
                d = p->unkC - p->unkE + func_80042DA8() % (p->unkE * 2);
                q->unk4 = p->unk4 + (d * v.vx >> 12);
                q->unk6 = p->unk6;
                q->unk8 = p->unk8 + (d * v.vz >> 12);
                q->unk12 = p->unk12;
                w = p->unk14 + func_80042DA8() % 32;
                q->unk16 = w * v.vx >> 12;
                i++;
                q->unk18 = w * v.vz >> 12;
            } while (i < 9);
        }
        if (p->unk2 >= 0x1A) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

s32 func_801B05E0(s32 arg0) {
    MgTask *p;
    MgTask *q;
    s32 k;

    p = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0074)];
    func_800D3994(arg0, D_80151919[arg0][0], &p->unk4);
    k = *(s16 *)D_801518F6[arg0] + 0x120;
    if (k >= 0x76D) {
        k = 0x76C;
    }
    p->unkC = 0;
    p->unkE = -0x100;
    p->unk10 = *(u16 *)D_80151A46[arg0];
    p->unk14 = (k << 12) / 6000;
    p->unk16 = k * 750 / 650;
    p->unk18 = k * 750 / 900;
    p->unk12 = 0;
    p->unk1A = arg0;
    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0398)];
    if (k >= 0x4F3) {
        k = 0x4F2;
    }
    *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
    q->unk12 = (k << 12) / 350;
    q->unkC = k / 2;
    q->unkE = q->unkC / 2;
    q->unk14 = k / 12;
    return func_800D55F4(0x20, func_800D56A8(&p->unk4), 0xA4);
}

INCLUDE_RODATA("../asm/us/magic_hanmmer/nonmatchings/text", D_801B0000);

s32 func_801B0810(arg0, arg1) {
    D_801C9BF4 = &D_80162978[func_800BBEAC(&D_801B0000)];
    return func_800D5444(arg0, arg1, 5, &func_801B05E0);
}
