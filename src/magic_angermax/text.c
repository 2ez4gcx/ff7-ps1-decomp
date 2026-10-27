#include "common.h"
#include "magic_angermax/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0BEC();
    return &D_801BD6B4;
}

void func_801B0028(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x800, p->unk18);
    D_801DDED4 = func_800D29D4(&D_801BDDC4, D_801517C0 + 0x70, 0xC, D_801DDED4);
    if (D_80062D98 == 0) {
        p->unk0 = -1;
    }
}

void func_801B00B0(void) {
    MgTask *p;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, p->unk18);
    D_801BDDDC[0] = p->unk2;
    D_801DDED4 = func_800D4D90(&D_801BDDDC[-4], D_801517C0 + 0x70, 0xC, D_801DDED4);
    if (D_80062D98 == 0) {
        t = p->unk2 + 1;
        *(s16 *)((u8 *)p + 2) = t;
        if (t >= D_801BD49C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0170(void) {
    MgTask *p;
    u8 *pkt;
    s16 t;
    s32 t2;

    pkt = D_801DDED4;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B48C(D_800FA63C);
    func_8003B51C(D_800FA63C);
    D_801BDDE4->n = func_8003BBDC(&p->unk4, pkt + 8, &D_801BDDE4->otz, &D_801BDDE4->flag);
    if (!(D_801BDDE4->flag & 0x60000)) {
        *(s32 *)pkt = 0x03000000;
        func_8003B69C(0, 0, 0);
        func_8003B710(&p->unk14, (p->unk2 << 12) / 5, pkt + 4);
        *(s32 *)(pkt + 0xC) = 0x20002;
        t2 = (D_801BDDE4->n >> 2) * 4 + 0x70;
        func_80046794(t2 + D_801517C0, pkt);
        D_801DDED4 = pkt + 0x10;
    }
    if (D_80062D98 == 0) {
        t = p->unk2 + 1;
        p->unk2 = t;
        if (t >= 5) {
            p->unk0 = -1;
        } else {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unkC = p->unkC * 7 >> 3;
            p->unkE = (p->unkE * 7 >> 3) + 0xA;
            p->unk10 = p->unk10 * 7 >> 3;
        }
    }
}

void func_801B0350(s32 id) {
    AmPart *q;
    s32 w;
    s32 i;

    i = 0;
    func_800D3994(id, D_8015190F[id][0], D_801BDDE8);
    w = *(s16 *)D_801518F6[id];
    D_801BDDE8->pos.vx += func_80042DA8() % (w / 2 * 2) - w / 2;
    D_801BDDE8->pos.vy += func_80042DA8() % (w / 2 * 2) - w / 2;
    D_801BDDE8->pos.vz += func_80042DA8() % (w / 2 * 2) - w / 2;
    q = (AmPart *)&D_80162978[func_800BBEAC(func_801B0028)];
    *(AmB8 *)&q->pos = *(AmB8 *)&D_801BDDE8->pos;
    q->unk18 = -w;
    q = (AmPart *)&D_80162978[func_800BBEAC(func_801B00B0)];
    *(AmB8 *)&q->pos = *(AmB8 *)&D_801BDDE8->pos;
    q->unk18 = -w;
    do {
        q = (AmPart *)&D_80162978[func_800BBEAC(func_801B0170)];
        *(AmB8 *)&q->pos = *(AmB8 *)&D_801BDDE8->pos;
        q->c0 = 0xFF;
        q->c1 = func_80042DA8();
        q->c2 = 0;
        q->c3 = 0x62;
        D_801BDDE8->rot.vx = func_80042DA8() & 0xFFF;
        D_801BDDE8->rot.vy = D_80151A46[D_801DDEDC][0] - 0x400;
        D_801BDDE8->rot.vz = func_80042DA8() % 256 + 0x300;
        func_8003C21C(&D_801BDDE8->rot, &D_801BDDE8->m);
        i++;
        D_801BDDE8->rot.vx = func_80042DA8() % 200 + 0x12C;
        D_801BDDE8->rot.vy = 0;
        D_801BDDE8->rot.vz = 0;
        func_8003B2CC(&D_801BDDE8->m, &D_801BDDE8->rot, &q->vel);
    } while (i < 0xF);
}

void func_801B06B8(void) {
    MgMat lw;
    s32 ext;
    s32 flag;
    MgObj20 *p;
    AmFT4 *q;
    s32 r;
    s32 t;

    p = &D_80162978[D_8015169C];
    func_800D41FC(D_800FA63C, &D_800FA6E0[D_801DDEDC], &D_801BDE3C->m);
    func_8003B2CC(&D_801BDE3C->m, &D_801BDE34, &D_801BDE3C->v);
    D_801BDE2E[0] = func_80042DA8() & 0x3FF;
    func_8003C21C(&D_801BDE2E[-1], &D_801BDE0C);
    D_801BDE20.vx = D_801BDE3C->v.vx + D_801BDE3C->m.t[0];
    D_801BDE20.vz = D_801BDE3C->v.vz + D_801BDE3C->m.t[2];
    func_8003A63C(D_800FA63C, &D_801BDE0C, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    q = D_80163C74;
    r = func_8003BD7C(D_801BDDEC, D_801BDDF4, D_801BDDFC, D_801BDE04, &q->xy0, &q->xy1, &q->xy2, &q->xy3, &ext, &flag);
    if (r > 0) {
        q->tag = 0x09000000;
        if (p->unk0 == 0) {
            q->rgbc = 0x2E808080;
        } else {
            q->rgbc = 0x2E202020;
        }
        q->clut = 0x78C7;
        q->tpage = 0x3A;
        q->uv0 = -0x4000;
        q->uv1 = -0x3FC1;
        q->uv2 = -0x100;
        q->uv3 = -0xC1;
        t = (r >> 2) * 4 + 0x70;
        func_80046794(t + D_801517C0, q);
        D_80163C74 = q + 1;
    }
    p->unk0 = -1;
}

void func_801B08C0(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    func_8003A63C(&D_800FA6E0[D_801DDEDC], D_801BDE40, D_801BDEA0);
    func_8003B48C(D_801BDEA0);
    func_8003B51C(D_801BDEA0);
    D_801DDED4 = func_800D29D4(D_801BDE80, D_801517C0 + 0x70, 0xC, D_801DDED4);
    func_8003A63C(&D_800FA6E0[D_801DDEDC], D_801BDE60, D_801BDEA0);
    func_8003B48C(D_801BDEA0);
    func_8003B51C(D_801BDEA0);
    D_801DDED4 = func_800D29D4(D_801BDE90, D_801517C0 + 0x70, 0xC, D_801DDED4);
    p->unk0 = -1;
}

void func_801B09F0(void) {
    MgTask *p;
    MgTask *q;
    s32 id;
    u16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 8) {
            func_800D55F4(0x28, func_800D56A8(D_80151A4C[D_801DDEDC]), 0x111);
        }
        if (p->unk2 == D_801BDEAC[p->unk0]) {
            id = D_801517F0[p->unk0];
            D_801BDEA4 = id;
            if (id != 0xFF) {
                func_800BBEAC(func_801B08C0);
                func_801B0350(D_801BDEA4);
                q = func_800D4FA8(0xA);
                q->unk0 = (u16)D_801BDEA4;
                t = p->unk0;
                p->unk0 = t + 1;
                q->unk10 = t;
                func_800D55F4(0x29, func_800D56A8(D_80151A4C[D_801BDEA4]), 0xF);
            } else {
                func_800D55F4(0x28, 0x40, 0);
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0B8C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DDED4 = D_801BDED4 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0BEC(arg0, arg1) {
    D_801DDED8 = arg0;
    D_801DDEDC = arg1;
    func_800D2980(&D_801B0C60, 0, 0, 0);
    func_800BBEAC(func_801B0B8C);
    D_80162978[func_800BBEAC(func_801B09F0)].unk0 = 0;
}
