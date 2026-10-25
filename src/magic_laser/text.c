#include "common.h"
#include "magic_laser/decls.h"

void func_801B0000(void) {
    func_801B06F4();
}

void func_801B0020(void) {
    MgSVec a;
    MgSVec b;
    MgVec d;
    s32 sxy;
    s32 flag;
    MgObj20 *p;
    MgFT4 *q;
    s32 sum;
    s32 n;
    s32 r;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    sum = func_8003BBDC(&p->unk4, &a, &sxy, &flag);
    sum += func_8003BBDC(&p->pad[4], &b, &sxy, &flag);
    n = sum / 2;
    if (n > 0) {
        q = (MgFT4 *)D_801E88F4;
        D_801E88F4 = (u8 *)(q + 1);
        d.vz = 0;
        d.vx = b.vx - a.vx;
        d.vy = b.vy - a.vy;
        func_8003A08C(&d, &d);
        r = func_8003B66C();
        d.vx = (r * d.vx / n) >> 6;
        d.vy = (r * d.vy / n) >> 6;
        q->tag = 0x09000000;
        q->rgbc = 0x2E808080;
        q->x0 = a.vx + d.vy;
        q->y0 = a.vy - d.vx;
        q->x1 = a.vx - d.vy;
        q->y1 = a.vy + d.vx;
        q->x2 = b.vx + d.vy;
        q->y2 = b.vy - d.vx;
        q->x3 = b.vx - d.vy;
        q->y3 = b.vy + d.vx;
        q->u1 = 0;
        q->u0 = 0;
        q->u3 = 0xFF;
        q->u2 = 0xFF;
        t = p->unk2 << 5;
        q->v2 = t;
        q->v0 = t;
        k = (p->unk2 << 5) | 0x1F;
        q->tpage = 0x2E;
        q->clut = 0x7808;
        q->v3 = k;
        q->v1 = k;
        func_80046794(*(s32 *)((n >> 2) * 4 + D_801517C0 + 0x70), (s32)q);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B02F8(void) {
    MgObj20 *p;
    s16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368((MgSVec *)&p->unk4, 0x1000, -0xC8);
    frame = &D_801C88E4;
    *frame = p->unk2 % 3;
    D_801E88F4 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E88F4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B03D8(void) {
    MgObj20 *p;
    s16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368((MgSVec *)&p->unk4, 0x1000, -0xC8);
    frame = &D_801C88F0;
    *frame = p->unk2;
    D_801E88F4 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E88F4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B048C(void) {
    MgMat m;
    MgSVec s;
    MgVec v;
    MgObj20 *p;
    MgObj20 *q;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 3) {
            q = &D_80162978[func_800BBEAC(func_801B0020)];
            func_800D3994(M2C_FIELD(p, s16 *, 0x16), D_80151918[M2C_FIELD(p, s16 *, 0x16)][0], &q->unk4);
            func_800D3994(M2C_FIELD(p, s16 *, 0x14), D_8015190F[M2C_FIELD(p, s16 *, 0x14)][0], &q->pad[4]);
            q = &D_80162978[func_800BBEAC(func_801B02F8)];
            q->unk4 = v.vx;
            q->unk6 = v.vy;
            M2C_FIELD(q, s16 *, 8) = v.vz;
            func_800D55F4(0x20, &q->pad[4], 0x3A);
        } else if (p->unk2 == 7) {
            q = &D_80162978[func_800BBEAC(func_801B03D8)];
            func_800D3994(M2C_FIELD(p, s16 *, 0x14), D_8015190F[M2C_FIELD(p, s16 *, 0x14)][0], &q->unk4);
            func_800D5774(M2C_FIELD(p, s16 *, 0x14));
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0640(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(func_801B048C)];
    M2C_FIELD(p, s16 *, 0x14) = arg0;
    M2C_FIELD(p, s16 *, 0x16) = arg1;
}

void func_801B0694(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E88F4 = D_801C88F4 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B06F4(arg0, arg1) {
    func_800D2980(&D_801B0764, 0, 0, 0);
    func_800BBEAC(func_801B0694);
    return func_800D5444(arg0, arg1, 1, (M2C_UNK *)func_801B0640);
}
