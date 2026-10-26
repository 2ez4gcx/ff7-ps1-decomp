#include "common.h"
#include "magic_mytyg/decls.h"

void func_801B0054(void) {
    func_801B0A40();
}

void func_801B0074(void) {
    MgSVec rot;
    MgSVec ang;
    MgMat m;
    MgVec v;
    MgTask *p;
    s32 c;
    s32 t;

    p = &D_80162978[D_8015169C];
    rot.vx = 0;
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    ang.vx = 0;
    ang.vy = 0;
    ang.vz = -p->unk10;
    func_8003B27C(&m, &ang, (MgVec *)m.t);
    m.t[0] += p->unk4;
    m.t[1] += p->unk6;
    m.t[2] += p->unk8;
    v.vx = v.vy = v.vz = p->unk18;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    ((MgScratch *)0x1F800000)->unk0 = &D_801C0BFC;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t >= 8) {
        ((MgScratch *)0x1F800000)->unkA = c - (t - 8) * 0x10;
    }
    func_8003B69C(0, 0, 0);
    D_801D996C = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D996C);
    if (p->unk2 >= 0x10) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk18 += p->unk1A;
        p->unk2++;
    }
}

void func_801B0254(void) {
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
    ((MgScratch *)0x1F800000)->unk0 = &D_801C1278;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t >= 2) {
        ((MgScratch *)0x1F800000)->unkA = (t - 2) << 9;
    }
    func_8003B69C(0, 0, 0);
    D_801D996C = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D996C);
    if (p->unk2 >= 0xA) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk10 += p->unk12;
        p->unk14 += p->unk16;
        p->unk2++;
        p->unk18 += p->unk1A;
    }
}

void func_801B0424(void) {
    MgTask *p;
    s8 *frame;
    s16 t;
    s32 n;

    p = &D_80162978[D_8015169C];
    frame = &D_801C1960;
    n = p->unk2;
    *frame = n << 5;
    t = p->unk18;
    func_800D4368(&p->unk4, t, -(t >> 4));
    D_801D996C = func_800D6260(frame - 4, D_801517C0 + 0x70, 0xC, D_801D996C);
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk6 -= p->unkE;
        p->unk2++;
    }
}

void func_801B0500(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 rad;
    s32 diam;
    s32 k;
    s32 n;
    s32 r;
    s32 v;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = (u16)p->unk2;
        if ((u32)(t - 1) < 0x2C && (t & 1)) {
            rad = p->unk18;
            diam = rad << 1;
            k = (rad << 12) / 350;
            n = 0;
            do {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0424)];
                *(MyB8 *)&q->unk4 = *(MyB8 *)&p->unk4;
                q->unk4 = q->unk4 + (func_80042DA8() % diam - rad);
                q->unk6 = -(func_80042DA8() % rad);
                q->unk8 = q->unk8 + (func_80042DA8() % diam - rad);
                r = func_80042DA8();
                q->unkE = r % 90 + 0x32;
                q->unk18 = ((s16)(r % 0x1000 + 0x800) * k) >> 12;
                n++;
            } while (n < 3);
            t = (u16)p->unk2;
        }
        if ((u32)(t - 2) < 0x11 && (s16)t % 6 == 0) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0254)];
            *(MyB8 *)&q->unk4 = *(MyB8 *)&p->unk4;
            q->unkC = 0;
            v = func_80042DA8() % 48 + 0x64;
            q->unkE = v;
            q->unk10 = v * (u16)p->unk2;
            q->unk12 = func_80042DA8() % 48 + 0x14;
            q->unk14 = 0;
            q->unk16 = -(func_80042DA8() % 32 + 0x46);
            q->unk18 = 0;
            q->unk1A = (p->unk18 << 12) / 2250;
        }
        if (p->unk2 == 0x1A) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0074)];
            *(MyB8 *)&q->unk4 = *(MyB8 *)&p->unk4;
            q->unkC = p->unk1A;
            q->unk10 = p->unk18;
            q->unk18 = 0;
            q->unk1A = (p->unk18 << 12) / 7000;
        }
        if (p->unk2 == 0x30) {
            func_800D5774(p->unk1C);
        }
        if (p->unk2 >= 0x37) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0974(s32 arg0) {
    MgTask *p;
    s32 t;

    p = &D_80162978[func_800BBEAC(&func_801B0500)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    t = D_801518F6[arg0][0] + 0xE0;
    if (t >= 0x76D) {
        t = 0x76C;
    }
    p->unk18 = t;
    p->unk1A = D_80151A46[arg0][0];
    p->unk1C = arg0;
}

INCLUDE_RODATA("../asm/us/magic_mytyg/nonmatchings/text", D_801B0000);

s32 func_801B0A40(arg0, arg1) {
    D_801D9970 = &D_80162978[func_800BBEAC((M2C_UNK *)D_801B0000)];
    func_800D2980(&D_801B0ADC, 0, 0, 0);
    func_800D5444(arg0, arg1, 3, func_801B0974);
    return func_800D55F4(0x20, func_800D574C(arg0), 0x170);
}
