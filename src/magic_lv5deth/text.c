#include "common.h"
#include "magic_lv5deth/decls.h"

void func_801B0054(void) {
    func_801B0508();
}

void func_801B0074(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 t;
    s16 v;
    MgScratch *sp;

    p = &D_80162978[D_8015169C];
    sp = (MgScratch *)0x1F800000;
    v = p->unkC;
    func_800D4368(&p->unk4, v, -(v >> 3));
    ((MgScratch *)0x1F800000)->unk0 = D_801C0868;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0x800;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t < 8) {
        ((MgScratch *)0x1F800000)->unkA = 0x1000 - (t << 8);
    } else if (t >= 0x25) {
        ((MgScratch *)0x1F800000)->unkA = (t << 8) - 0x1D00;
    }
    func_8003B69C(0, 0, 0);
    D_801D8E50 = func_800D29D4(sp, D_801517C0 + 0x70, 0xC, D_801D8E50);
    if (p->unk2 >= 0x2D) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B01BC(void) {
    MgTask *p;
    u8 *rgb;
    s16 t;
    s16 v;
    u8 c;

    p = &D_80162978[D_8015169C];
    D_801C0E4C[0] = p->unk2 & 7;
    t = p->unk2;
    if (t < 8) {
        c = t * 16;
    } else if (t >= 0x25) {
        c = -0x80 - (t - 0x25) * 16;
    } else {
        c = 0x80;
    }
    rgb = D_801C0E48;
    rgb[2] = c;
    rgb[1] = c;
    rgb[0] = c;
    v = p->unkC;
    func_800D4368(&p->unk4, v, -(v >> 2));
    D_801D8E50 = func_800D4D90(rgb - 4, D_801517C0 + 0x70, 0xC, D_801D8E50);
    if (p->unk2 >= 0x2D) {
        p->unk0 = -1;
        D_801D8E58 -= 1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x23) {
            func_800D5774(p->unkE);
        }
        p->unk2++;
    }
}

void func_801B0310(void) {
    s32 pad;
    MgTask *p;
    s16 t;
    s32 v;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 8) {
        D_800F5B70[2] = 0;
        D_800F5B70[1] = 0;
        D_800F5B70[0] = 0;
        v = p->unk2 * 0x140;
    } else if (D_801D8E58 <= 0) {
        if (p->unkE == 0) {
            p->unkE = t;
        }
        v = 0xA00 - (p->unk2 - p->unkE) * 0x140;
    } else {
        v = 0xA00;
    }
    if (p->unk2 >= 0x35) {
        v = 0;
        p->unk0 = -1;
    }
    D_800F5B74 = v;
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0414(arg0) {
    MgTask *p;
    MgTask *q;

    p = &D_80162978[func_800BBEAC(func_801B01BC)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    p->unkC = 0x1CCC;
    p->unkE = arg0;
    q = &D_80162978[func_800BBEAC(func_801B0074)];
    *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
    q->unkC = 0x13DC;
    func_800D55F4(0x20, func_800D56A8(&p->unk4), 0xAA);
}

INCLUDE_RODATA("../asm/us/magic_lv5deth/nonmatchings/text", D_801B0000);

void func_801B0508(arg0, arg1) {
    MgTask *p;
    s32 i;
    s32 n;

    D_801D8E54 = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(D_801B05E0, 0, 0, 0);
    p = &D_80162978[func_800BBEAC(func_801B0310)];
    p->unkE = 0;
    func_800D5444(arg0, arg1, 2, func_801B0414);
    for (i = 0, n = 0; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
        }
    }
    D_801D8E58 = n;
}
