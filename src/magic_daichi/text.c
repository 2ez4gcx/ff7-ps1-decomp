#include "common.h"
#include "magic_daichi/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0B28();
    return &D_801B6D0C;
}

void func_801B0028(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk8, 0x1000, 0);
    D_801B7780[0] = p->unk2;
    D_801D7790 = func_800D4D90(&D_801B7780[-4], D_801517C0 + 0x70, 0xC, D_801D7790);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B6C14[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B00E8(DcRing *arg0, s32 arg1) {
    DcFT4 *q;
    s32 c;
    s32 i;
    s32 j;
    s32 k;
    s32 t;
    s32 n;
    s32 t0;

    func_8003B48C(D_800FA63C);
    func_8003B51C(D_800FA63C);
    c = (arg1 << 7) >> 12;
    D_801B7784->col = 0x2E000000 | (c << 16) | (c << 8) | c;
    q = (DcFT4 *)D_801D7790;
    n = arg0->n;
    t0 = n - 0x15;
    j = (arg0->pos - t0 - 1) % 21;
    for (i = 0; i < arg0->n; i++) {
        D_801B7784->a.vx = arg0->pt[j].vx;
        D_801B7784->a.vy = arg0->pt[j].vy - 0x64;
        D_801B7784->a.vz = arg0->pt[j].vz;
        D_801B7784->b.vx = arg0->pt[j].vx;
        D_801B7784->b.vy = arg0->pt[j].vy + 0x64;
        D_801B7784->b.vz = arg0->pt[j].vz;
        k = (j + 1) % 21;
        D_801B7784->c.vx = arg0->pt[k].vx;
        D_801B7784->c.vy = arg0->pt[k].vy - 0x64;
        D_801B7784->c.vz = arg0->pt[k].vz;
        D_801B7784->d.vx = arg0->pt[k].vx;
        D_801B7784->d.vy = arg0->pt[k].vy + 0x64;
        D_801B7784->d.vz = arg0->pt[k].vz;
        D_801B7784->r = func_8003BD7C(&D_801B7784->a, &D_801B7784->b, &D_801B7784->c, &D_801B7784->d, &q->xy0, &q->xy1, &q->xy2, &q->xy3, &D_801B7784->ext, &D_801B7784->flag);
        if (!(D_801B7784->flag & 0x60000)) {
            q->tag = 0x09000000;
            q->rgbc = D_801B7784->col;
            if (i == 0) {
                q->uv0 = 0x3F40;
                q->uv1 = 0x3F7F;
                q->uv2 = 0x40;
                q->uv3 = 0x7F;
            } else if (i == arg0->n - 1) {
                q->uv0 = 0x40;
                q->uv1 = 0x7F;
                q->uv2 = 0x3F40;
                q->uv3 = 0x3F7F;
            } else {
                q->uv0 = 0;
                q->uv1 = 0x3F;
                q->uv2 = 0x3F00;
                q->uv3 = 0x3F3F;
            }
            q->clut = 0x7848;
            q->tpage = 0x2D;
            t = ((D_801B7784->r >> 2) << 2) + 0x70;
            func_80046794(t + D_801517C0, q);
            q++;
        }
        j = k;
    }
    D_801D7790 = (u8 *)q;
}

void func_801B03DC(void) {
    DcTask *p;
    DcTask *q;
    s32 i;
    s32 s;
    s32 a;
    s32 k;
    s32 t;

    p = (DcTask *)&D_80162978[D_8015169C];
    if (p->unk2 == 0) {
        p->ring->pt[0].vx = (p->unk10 * func_80039B40(p->unk14)) >> 12;
        p->ring->pt[0].vy = 0;
        p->ring->pt[0].vz = (-p->unk10 * func_80039A74(p->unk14)) >> 12;
        p->ring->n = 0;
        p->ring->pos = 1;
    }
    if (D_80062D98 == 0) {
        i = 0;
        do {
            p->unk14 += 0x1F400 / p->unk10;
            a = p->unk2;
            if (a < 0x1E) {
                p->unk10 += p->unk12;
                t = (a << 12) / 30;
                k = 0;
                if (p->ring->n < 0x14) {
                    p->ring->n++;
                }
                s = t;
            } else {
                a -= 0x1E;
                if (a < 0x3C) {
                    t = (a << 12) / 60;
                    k = -(t * 2000) >> 12;
                    if (a >= 0x29) {
                        if (p->ring->n > 0) {
                            p->ring->n--;
                        }
                    }
                    s = (p->ring->n << 12) / 20;
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
            i++;
            p->ring->pt[p->ring->pos].vx = D_801B7788->vx = p->unk8 + ((p->unk10 * func_80039B40(p->unk14)) >> 12);
            p->ring->pt[p->ring->pos].vy = D_801B7788->vy = k;
            p->ring->pt[p->ring->pos].vz = D_801B7788->vz = p->unkC - ((p->unk10 * func_80039A74(p->unk14)) >> 12);
            p->ring->pos = (p->ring->pos + 1) % 21;
            p->unk2++;
        } while (i < 2);
        i = 0;
        do {
            i++;
            q = (DcTask *)&D_80162978[func_800BBEAC(func_801B0028)];
            q->unk8 = (s16)D_801B7788->vx - 0x12C + func_80042DA8() % 600;
            q->unkA = D_801B7788->vy + (func_80042DA8() % 600 - 0x12C);
            q->unkC = (s16)D_801B7788->vz - 0x12C + func_80042DA8() % 600;
        } while (i <= 0);
    }
    func_801B00E8(p->ring, s);
}

void func_801B0858(void) {
    DcTask *p;
    DcTask *q;
    s32 t;

    p = (DcTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (DcTask *)&D_80162978[func_800BBEAC(func_801B03DC)];
            *(DcB8 *)&q->unk8 = *(DcB8 *)&p->unk8;
            q->unk10 = 0xBB8;
            q->unk12 = -0x53;
            q->ring = &D_801D7794[D_801B6D08];
            q->unk14 = *(u16 *)&D_801B778C;
            D_801B6D08++;
        }
        if (p->unk2 == 0) {
            q = (DcTask *)&D_80162978[func_800BBEAC(func_801B03DC)];
            *(DcB8 *)&q->unk8 = *(DcB8 *)&p->unk8;
            q->unk10 = -0xBB8;
            q->unk12 = 0x53;
            q->ring = &D_801D7794[D_801B6D08++];
            q->unk14 = *(u16 *)&D_801B778C;
            D_801B778C ^= 0x800;
        }
        t = p->unk2;
        if (t == 0xF) {
            func_800D5774(p->unk0);
            if (p->unk2 == t) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0A48(s32 arg0) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(func_801B0858)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], p->pad);
}

void func_801B0AC8(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D7790 = D_801B7790 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0B28(arg0, arg1) {
    u8 pad[8];

    func_800D2980(&D_801B0BB0, 0, 0, 0);
    func_800BBEAC(func_801B0AC8);
    func_800D5444(arg0, arg1, 0, &func_801B0A48);
    func_800D55F4(0x20, func_800D574C(arg0), 0x1DB);
}
