#include "common.h"
#include "magic_sting/decls.h"

void func_801B0040(void) {
    func_801B4770();
}

void func_801B0060(void) {
    func_801B4804();
}

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B0080);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B0B40);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B165C);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B1CA8);

void func_801B1EAC(MgSVecList *a, MgSVec *b, MgSVec *out) {
    s32 i;
    s32 n;
    MgSVec *s;

    n = a->n / 8;
    s = a->v;
    for (i = 0; i < n; i++) {
        out->vx = s->vx - b->vx;
        out->vy = s->vy - b->vy;
        out->vz = s->vz - b->vz;
        s++;
        b++;
        out++;
    }
}

void func_801B1F3C(MgSVecList *a, MgSVec *b, MgSVec *d, s32 t) {
    s32 i;
    s32 n;
    MgSVec *s;

    n = a->n / 8;
    s = a->v;
    t = 0x1000 - t;
    for (i = 0; i < n; i++) {
        s->vx = b->vx + ((d->vx * t) >> 12);
        s->vy = b->vy + ((d->vy * t) >> 12);
        s->vz = b->vz + ((d->vz * t) >> 12);
        s++;
        b++;
        d++;
    }
}

s32 func_801B2004(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801CD40E[-v];
    }
    return v;
}

s32 func_801B2040(s32 a, s32 b) {
    s32 i;
    s32 n;
    s32 orig;

    orig = a;
    if (b > 0) {
        n = b >> 8;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
    } else if (b < 0) {
        b = -b;
        n = b >> 8;
        a = 0x1000 - a;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
        a = 0x1000 - a;
    } else {
        return a;
    }
    n = (b & 0xFF) + 1;
    a = (a * n + orig * (0x100 - n)) >> 8;
    return a;
}

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B2138);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B2228);

void func_801B318C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B2228)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

MgMat *func_801B31F0(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801CC794.m[0][0] = D_801CC794.m[1][1] = D_801CC794.m[2][2] = scale;
    func_8003B48C(&D_801CD3F0);
    func_8003B51C(&D_801CD3F0);
    func_8003BC6C(v, (MgVec *)D_801CC794.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801CC794.t, &n);
        D_801CC794.t[0] += (dist * n.vx) >> 12;
        D_801CC794.t[1] += (dist * n.vy) >> 12;
        D_801CC794.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801CC794);
    func_8003B51C(&D_801CC794);
    return &D_801CC794;
}

void func_801B330C(void) {
    MgTask *p;
    s32 t;
    s32 d;
    s32 v;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        d = p->unk6;
        if (t < d) {
            d = (t << 12) / d;
            v = (p->unk4 * d) >> 12;
        } else {
            t -= d;
            if (t < p->unk8) {
                v = p->unk4;
            } else {
                t -= p->unk8;
                d = p->unkA;
                if (t >= d) {
                    p->unk0 = -1;
                    D_800FA666[0] = 0;
                    return;
                }
                d = (t << 12) / d;
                v = (p->unk4 * (0x1000 - d)) >> 12;
            }
        }
        D_800FA666[0] = (p->unk2 & 1) ? v : -v;
        p->unk2++;
    }
}

void func_801B3448(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B330C)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B34BC);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B3524);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B35B0);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B35F0);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B37F8);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B3AB0);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B3BEC);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B3D20);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B3F1C);

void func_801B40A0(s16 arg0) {
    D_80162978[func_800BBEAC(&func_801B3D20)].unk0 = arg0;
}

void func_801B40E4(s16 arg0) {
    D_80162978[func_800BBEAC(&func_801B3F1C)].unk0 = arg0;
}

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B4128);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B42C4);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B4460);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B4640);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B4770);

void func_801B4804(void) {
    func_800D2980(&D_801B485C, 0, 0, 0);
    func_8003C21C(&D_801CC6F0, &D_801CC6D0);
    func_800BBEAC(&func_801B4640);
}
