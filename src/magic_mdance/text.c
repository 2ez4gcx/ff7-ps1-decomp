#include "common.h"
#include "magic_mdance/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B0754();
    return &D_801B07C8;
}

void func_801B007C(void) {
    MgTask *p;
    MgSprArg *s;
    s32 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk10, -500);
    s = (MgSprArg *)0x1F800000;
    s->y = -16;
    s->x = -16;
    s->u = D_801B6278[p->unk2];
    s->v = ((u8 *)&p->unkC)[1];
    s->w = 0x1F;
    s->h = 0x1F;
    s->tpage = p->unk16;
    s->clut = p->unkE;
    s->rgbc = 0x2E808080;
    D_801CE290 = func_800D6260(s, D_801517C0 + 0x70, 0xC, D_801CE290);
    if (D_80062D98 == 0) {
        p->unk2++;
        n = p->unk2;
        if (((u8 *)&p->unkC)[1] == 0x80) {
            if (n >= 8) {
                goto block;
            }
            return;
        }
        if (n >= 9) {
        block:
            p->unk0 = -1;
        }
    }
}

void func_801B01B8(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 c;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        for (i = 0; i < 2; i++) {
            q = &D_80162978[func_800BBEAC(func_801B007C)];
            p->unk14 = (p->unk14 + (func_80042DA8() & 3) + 1) % D_801518F4[p->unk12][0];
            func_800D3994(p->unk12, p->unk14, &q->unk4);
            c = 0xFA;
            q->unk4 = q->unk4 - c + func_80042DA8() % 500;
            c = 0xFA;
            q->unk6 = q->unk6 - c + func_80042DA8() % 500;
            c = 0xFA;
            q->unk8 = q->unk8 - c + func_80042DA8() % 500;
            *((u8 *)q + 0xD) = func_80042DA8() % 3 << 5;
            q->unkE = D_801B6284[func_80042DA8() % 5];
            q->unk10 = (func_80042DA8() & 0xFFF) + 0x1000;
            q->unk16 = p->unk16;
        }
        p->unk2++;
        if (p->unk2 >= 0x1E) {
            func_800D5774(p->unk12);
            p->unk0 = -1;
        }
    }
}

void func_801B0460(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B01B8)];
    p->unk12 = arg0;
    p->unk14 = 0;
    p->unk16 = 0x3A;
}

void func_801B04B4(s32 arg0, s32 arg1) {
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, func_801B0460);
    func_800D55F4(0x29, func_800D574C(arg0), 8);
}

void func_801B0524(void) {
    MgTask *p;
    MgTask *q;
    u16 *w;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 6) {
            q = func_800D4FA8(1);
            *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
            q->unk10 = p->unkC + 0x800;
        }
        if (p->unk2 == 0x15 || p->unk2 == 0x1D || p->unk2 == 0x25 || p->unk2 == 0x2C || p->unk2 == 0x32) {
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x263);
        }
        if (p->unk2 == 0x24) {
            w = &D_80153D1A;
            *w += 0x800;
        }
        if (p->unk2 == 0x32) {
            func_800D4FA8(2);
            p->unk0 = -1;
        }
        if (p->unk2 == 0x30) {
            func_801B04B4(D_801CE298, D_801CE29C);
        }
        p->unk2++;
    }
}

void func_801B0678(void) {
    MgTask *p;
    s16 v;
    s32 n;
    MgTask *base;

    D_80162978[D_8015169C].unk0 = -1;
    base = D_80162978;
    p = base + func_800BBEAC(func_801B0524);
    func_800D54EC(D_801CE298, &p->unk4);
    v = D_80151A46[D_801CE29C][0];
    p->unkC = v;
    if (v == 0x800) {
        p->unk8 += 0x384;
    } else {
        p->unk8 -= 0x384;
    }
}

INCLUDE_RODATA("../asm/us/magic_mdance/nonmatchings/text", D_801B0000);

s32 func_801B0754(arg0, arg1) {
    s32 v;

    D_801CE294 = &D_80162978[func_800BBEAC(D_801B0000)];
    v = func_800BBEAC(func_801B0678);
    D_801CE298 = arg0;
    D_801CE29C = arg1;
    return v;
}
