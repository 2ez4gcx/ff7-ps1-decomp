#include "common.h"
#include "magic_blaver/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0730();
    return &D_801B07A0;
}

void func_801B0028(void) {
    s32 flag;
    BvTask *p;
    u16 t;
    MgVec *vp;
    s16 *fr;

    p = (BvTask *)&D_80162978[D_8015169C];
    t = (s16)p->unk2 >> 8;
    D_801BE97C[0] = t;
    if (t >= D_801BE62C) {
        p->unk0 = -1;
        return;
    }
    func_8003B48C(D_800FA6E0[p->unk6]);
    func_8003B51C(D_800FA6E0[p->unk6]);
    vp = &D_801BE99C;
    func_8003BC6C(&D_801BE980, vp, &flag);
    func_8003B48C((u8 *)vp - 0x14);
    func_8003B51C((u8 *)vp - 0x14);
    D_801DEAD4 = func_800D4D90(&D_801BE97C[-4], D_801517C0 + 0x70, 0xC, D_801DEAD4);
    if (D_80062D98 == 0) {
        p->unk2 += 0x100;
    }
}

void func_801B014C(void) {
    MgMat m;
    MgVec v;
    s32 flag;
    s32 ext;
    MgObj20 *p;
    BvFT4 *q;
    s32 i;
    s32 j;
    s32 r;
    s32 k;

    p = &D_80162978[D_8015169C];
    func_800D41FC(D_800FA63C, D_800FA6E0[p->unk6], &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BE9D4[D_801B15A0].a.vx = m.t[0];
    D_801BE9D4[D_801B15A0].a.vy = m.t[1];
    D_801BE9D4[D_801B15A0].a.vz = m.t[2];
    func_8003BC6C(&D_801BE9B0, &v, &flag);
    D_801BE9D4[D_801B15A0].b.vx = v.vx;
    D_801BE9D4[D_801B15A0].b.vy = v.vy;
    D_801BE9D4[D_801B15A0].b.vz = v.vz;
    if (p->unk2 < 0x14) {
        if (p->unk2 > 0) {
            i = D_801B15A0 & 0xF;
            j = (D_801B15A0 - 1) & 0xF;
            q = (BvFT4 *)D_801DEAD4;
            func_8003B48C(D_800FA63C);
            func_8003B51C(D_800FA63C);
            r = func_8003BD7C(&D_801BE9D4[i].a, &D_801BE9D4[i].b, &D_801BE9D4[j].a, &D_801BE9D4[j].b, &q->xy0, &q->xy1, &q->xy2, &q->xy3, &ext, &flag);
            if ((flag & 0x60000) == 0) {
                q->tag = 0x09000000;
                q->uv0 = 0x5080;
                q->uv1 = 0x50C0;
                q->uv2 = 0x80;
                q->uv3 = 0xC0;
                q->clut = 0x7888;
                *(volatile s32 *)&q->rgbc = 0x2E808080;
                q->tpage = 0x2D;
                k = 0x70;
                func_80046794(((r >> 2) << 2) + k + D_801517C0, (s32)q);
                D_801DEAD4 = (u8 *)(q + 1);
            }
        }
    } else {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        D_801B15A0 = (D_801B15A0 + 1) & 0xF;
        p->unk2++;
    }
}

void func_801B03F4(void) {
    BvTask *p;
    s32 t;

    p = (BvTask *)&D_80162978[D_8015169C];
    t = (s16)p->unk2 >> 8;
    if (t < D_801BE8C8) {
        D_801BE9D0 = t;
    } else {
        p->unk0 = -1;
        return;
    }
    func_800D4368(&p->unk8, 0x1000, p->unk10);
    D_801DEAD4 = func_800D4D90(D_801BE9C8, D_801517C0 + 0x70, 0xC, D_801DEAD4);
    if (D_80062D98 == 0) {
        p->unk2 += 0x100;
    }
}

void func_801B04C0(void) {
    MgObj20 *p;
    MgObj20 *q;
    u8 *d;
    s16 n;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0xA) {
            q = &D_80162978[func_800BBEAC(&func_801B0028)];
            q->unk6 = p->unk6;
        }
        if (p->unk2 == 0x11) {
            q = &D_80162978[func_800BBEAC(&func_801B014C)];
            q->unk6 = p->unk6;
        }
        if (p->unk2 == 0x1A) {
            q = &D_80162978[func_800BBEAC(&func_801B03F4)];
            d = (u8 *)q + 8;
            func_800D3994(p->unk4, D_8015190F[p->unk4][0], d);
            *(s16 *)((u8 *)q + 0x10) = -*(u16 *)D_801518F6[p->unk4];
            func_800D55F4(0x20, func_800D56A8(d), 0x1B);
            func_800D5774(p->unk4);
            func_800D5138(1);
        }
        n = p->unk2;
        if (n == 0x1B) {
            func_800D51D4(1);
            if (p->unk2 == n) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B067C(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B04C0)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B06D0(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DEAD4 = D_801BEAD4 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0730(arg0, arg1) {
    func_800D2980(&D_801B15A8, 0, 0, 0);
    func_800BBEAC(&func_801B06D0);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B067C);
}
