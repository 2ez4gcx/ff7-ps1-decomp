#include "common.h"
#include "magic_utagoe/decls.h"

void func_801B0054(void) {
    func_801B06EC();
}

void func_801B0074(void) {
    MgTask *p;
    MgByte *col;
    s32 c;
    u16 a;
    s32 v;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (p->unk2 >= 0xE) {
        c = -0x80 - (p->unk2 - 0xE) * 0x10;
    } else {
        c = 0x80;
    }
    col = &D_801B4834;
    D_801B4836.v = c;
    D_801B4835.v = c;
    col->v = c;
    a = p->unk14;
    func_800D4368(&p->unk4, (s16)a, -((s16)a >> 2));
    D_801CC83C = func_800D4D90((u8 *)col - 4, D_801517C0 + 0x70, 0xC, D_801CC83C);
    if (p->unk2 >= 0x16) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        v = p->unk18 * func_80039A74(p->unk1A);
        t = (v >> 12) - p->unkA;
        p->unkA = t;
        p->unk6 -= t;
        p->unk18 += p->unk18 >> 4;
        p->unk1A += p->unk12;
        if (p->unk2 < 0xD) {
            p->unk14 += p->unk16;
        }
        p->unk2++;
    }
}

void func_801B0218(void) {
    MgVec v;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 a;
    s32 b;
    s32 r;
    s16 w;
    s32 t;
    s32 u;
    s32 y;
    s32 k;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if ((u16)(p->unk2 - 2) < 0x26U) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(&func_801B0074)];
                *(MgSVec *)&q->unk4 = D_801CC84C;
                q->unkA = 0;
                a = p->unk4 + func_80042DA8() % p->unkE - p->unkC;
                b = p->unk6 - func_80042DA8() % p->unk12 + p->unk10;
                v.vz = p->unk8 + func_80042DA8() % p->unkE - p->unkC - D_801CC84C.vz;
                a -= D_801CC84C.vx;
                v.vx = a;
                b -= D_801CC84C.vy;
                v.vy = b;
                q->unkC = v.vx / 21;
                q->unkE = v.vy / 21;
                q->unk10 = v.vz / 21;
                q->unk14 = 0;
                r = func_80042DA8();
                u = r % 0x1000 + 0x800;
                q->unk16 = (p->unk14 * u >> 12) / 13;
                q->unk18 = func_80039F5C(((s32 (*)(MgVec *, MgVec *))func_8003A08C)(&v, &v)) >> 5;
                q->unk1A = q->unk12 = func_80042DA8() % 96 + 0xDC;
                i++;
            } while (i < 2);
        }
        if (p->unk2 < 8) {
            D_800F5B72.v = 0;
            D_800F5B71.v = 0;
            D_800F5B70.v = 0;
            k = p->unk2;
            w = k << 7;
        } else if (p->unk2 < 0x34) {
            w = 0x400;
        } else {
            t = 0x400 - ((p->unk2 - 0x34) << 7);
            w = t;
            if ((s16)t < 0) {
                w = 0;
            }
        }
        if (p->unk2 == 0x35) {
            i = 0;
            do {
                if ((1 << i) & D_801CC844) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
        }
        if (p->unk2 >= 0x3C) {
            w = 0;
            p->unk0 = -1;
        }
        D_800F5B74.v = w;
        p->unk2++;
    }
}

void func_801B05EC(void) {
    MgTask *p;
    MgTask *base;
    s32 v;

    D_80162978[D_8015169C].unk0 = -1;
    func_800D3994(D_801CC848, D_80151908[D_801CC848][7], &D_801CC84C);
    base = D_80162978;
    p = base + func_800BBEAC(&func_801B0218);
    func_800D54EC(D_801CC844, &p->unk4);
    p->unk6 = -0x600;
    p->unkC = 0xA00;
    p->unkE = 0x1400;
    p->unk14 = 0xA3D;
    v = p->unk6 >> 1;
    p->unk10 = -v;
    p->unk12 = -v * 3;
    p->unk10 = p->unk10 << 1;
}

INCLUDE_RODATA("../asm/us/magic_utagoe/nonmatchings/text", D_801B0000);

s32 func_801B06EC(arg0, arg1) {
    D_801CC840 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B0794, 0, 0, 0);
    func_800BBEAC(&func_801B05EC);
    D_801CC844 = arg0;
    D_801CC848 = arg1;
    return func_800D55F4(0x20, func_800D574C(arg0), 0x16F);
}
