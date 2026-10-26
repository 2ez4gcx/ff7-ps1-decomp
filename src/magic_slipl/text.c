#include "common.h"
#include "magic_slipl/decls.h"

void func_801B0054(void) {
    func_801B0824();
}

void func_801B0074(void) {
    MgSVec rot1;
    MgSVec rot2;
    MgSVec ofs;
    MgMat m1;
    MgMat m2;
    MgVec scale;
    MgTask *p;
    MgScratch *sc;
    s32 n;
    s32 c;
    s32 v;
    u16 a;
    u16 b;

    p = (MgTask *)&D_80162978[D_8015169C];
    sc = (MgScratch *)0x1F800000;
    rot1.vx = 0x800;
    rot1.vy = p->unkC + 0x400;
    rot1.vz = 0;
    func_8003C21C(&rot1, &m1);
    rot2.vx = 0;
    rot2.vy = p->unkE;
    rot2.vz = 0;
    func_8003C21C(&rot2, &m2);
    ofs.vx = p->unk10;
    ofs.vy = 0;
    ofs.vz = 0;
    func_8003B27C(&m2, &ofs, (MgVec *)m1.t);
    m1.t[0] += p->unk4;
    m1.t[1] += p->unk6;
    m1.t[2] += p->unk8;
    func_8003A63C(&D_800FA63C, &m1, &m2);
    scale.vx = scale.vy = scale.vz = p->unk16;
    func_8003B35C(&m2, &scale);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    sc->unk0 = D_801B8960;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    c = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    n = p->unk2;
    if (n < 6) {
        v = (6 - n) * 0x15;
        goto store;
    }
    if (n >= 0x26) {
        v = (n - 0x26) * 7;
store:
        ((MgScratch *)0x1F800000)->unkA = c - v;
    }
    D_801D0E64 = func_800D29D4(sc, D_801517C0 + 0x70, 0xC, D_801D0E64);
    if (p->unk2 >= 0x37) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x26) {
            func_800D5774(p->unk1A);
        }
        a = p->unkC - 0x100;
        p->unkC = a;
        if (p->unk2 >= 0x20) {
            p->unkC = a + (p->unk2 - 0x20) * 0xB;
        }
        p->unkE -= 0x100;
        b = p->unk10 - p->unk12;
        p->unk10 = b;
        if ((b << 16) <= 0) {
            p->unk10 = 0;
        }
        a = p->unk6 - p->unk14;
        p->unk6 = a;
        if (p->unk2 >= 0x26) {
            p->unk6 = a - p->unk14;
        }
        a = p->unk16 + p->unk18;
        p->unk16 = a;
        if (p->unk2 >= 0x26) {
            p->unk16 = a + (p->unk18 >> 1);
        }
        p->unk2++;
    }
}

void func_801B035C(void) {
    MgTask *p;
    u16 *q;
    s16 *ang;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    D_801B8E38[0] = t << 5;
    q = &D_801B8E44;
    *q = p->unk12;
    D_801B8E4C = p->unk14;
    ang = &p->unk12;
    func_800D4284(&p->unk4, -(*ang >> 4), q);
    func_8003B48C(q);
    func_8003B51C(q);
    D_801D0E64 = func_800D6260(&D_801B8E38[-4], D_801517C0 + 0x70, 0xC, D_801D0E64);
    if (D_80062D98 == 0) {
        if (++p->unk2 >= 7) {
            p->unk0 = -1;
        }
    }
}

void func_801B0460(void) {
    MgTask *p;
    MgTask *q;
    s32 i;

    if (D_80062D98 == 0) {
        p = (MgTask *)&D_80162978[D_8015169C];
        if (p->unk2 >= 9) {
            i = 0;
            do {
                i++;
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B035C)];
                q->unk4 = p->unk4 + func_80042DA8() % p->unk12 - p->unk10;
                q->unk6 = p->unk6 + func_80042DA8() % p->unk12 - p->unk10;
                q->unk8 = p->unk8 + func_80042DA8() % p->unk12 - p->unk10;
                q->unk12 = q->unk14 = p->unk14;
            } while (i < 2);
        }
        if (p->unk2 >= 0x1F) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0614(s32 arg0) {
    u8 pad[8];
    MgTask *p;
    MgTask *q;
    s16 a;
    s32 t;
    s32 k;
    s32 c;
    s32 x;

    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B0074)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    p->unkE = 0;
    p->unkC = 0;
    p->unk6 -= p->unk6 >> 1;
    a = D_801518F6[arg0][0] * 2;
    p->unk10 = a;
    if (a >= 0x76D) {
        p->unk10 = 0x76C;
    }
    t = p->unk10 / 38;
    c = t > 0 ? t : 1;
    p->unk12 = c;
    k = 0xBC;
    t = -(p->unk6 * 3 / 55);
    c = t;
    if (c < 0x16) {
        c = 0x16;
    }
    p->unk14 = c;
    p->unk16 = 0x400;
    p->unk18 = k;
    p->unk1A = arg0;
    q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0460)];
    *(MgCopy8 *)&q->unk4 = *(MgCopy8 *)&p->unk4;
    x = D_801518F6[arg0][0];
    q->unk10 = x;
    q->unk12 = x * 2;
    q->unk14 = D_801518EC[arg0][0] + D_801518EC[arg0][1];
    t = q->unk14;
    if (t < 0x1000) {
        t = 0x1000;
    }
    q->unk14 = t;
}

INCLUDE_RODATA("../asm/us/magic_slipl/nonmatchings/text", D_801B0000);

void func_801B0824(arg0, arg1) {
    D_801D0E68 = &D_80162978[func_800BBEAC(&func_801B0000)];
    func_800D2980(&D_801B08C0, 0, 0, 0);
    func_800D5444(arg0, arg1, 1, &func_801B0614);
    func_800D55F4(0x20, func_800D574C(arg0), 0x49);
}
