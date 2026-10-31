#include "common.h"
#include "magic_gaisei/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B322C();
    return &D_801BD370;
}

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B0A50);

void func_801B1160(s16 mask, MgSVec *out) {
    MgVec sum;
    MgSVec pos;
    s16 i;
    s16 n;

    n = 0;
    sum.vx = sum.vy = sum.vz = 0;
    for (i = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            func_800D3994(i, D_8015190F[i][0], &pos);
            n++;
            sum.vx += pos.vx;
            sum.vy += pos.vy;
            sum.vz += pos.vz;
        }
    }
    out->vx = sum.vx / n;
    out->vy = sum.vy / n;
    out->vz = sum.vz / n;
}

void func_801B130C(s32 base, s16 range, MgSVec *out) {
    MgSVec v;
    MgSVec rot;
    MgMat m;

    v.vz = 0;
    v.vx = 0;
    v.vy = base + ((func_80042DA8() % range) * 2 - range);
    rot.vy = 0;
    rot.vx = func_80042DA8() % 800 - 400;
    rot.vz = func_80042DA8() % 800 - 400;
    func_8003BF8C(&rot, &m);
    func_8003B2CC(&m, &v, out);
}

void func_801B143C(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist) {
    MgMat m;
    MgMat r;
    MgVec n;
    s32 flag;
    s16 i;

    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(pos, (MgVec *)m.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)m.t, &n);
        m.t[0] += (dist * n.vx) >> 12;
        m.t[1] += (dist * n.vy) >> 12;
        m.t[2] += (dist * n.vz) >> 12;
    }
    m.m[0][0] = m.m[1][1] = m.m[2][2] = scale;
    func_8003C21C(rot, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
}

void func_801B159C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D6EC0 = D_801BEEC0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B1608(MgTask *arg0, u16 *arg1) {
    MgMat m;
    s32 sp30;
    s32 sp34;
    MgHalf *r;
    MgWord *w;

    func_8003BF8C(&D_801BED28, &m);
    func_8003B35C(&m, &D_801BED30);
    m.t[0] = D_801D6EF0;
    m.t[1] = D_801D6EF8;
    m.t[2] = arg0->unk2;
    func_80044AC0((s32)D_801BEE54, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801BEE54);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801BED40);
    func_8003B64C(&sp30, &sp34);
    func_8003B6BC((s16)arg1[2] / 2, (s16)arg1[3] / 2);
    func_8003B48C(&m);
    func_8003B51C(&m);
    w = &D_801BED18;
    w->v = D_8016209C;
    D_80163C74 = func_801B0A50(w, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B6BC(sp30, sp34);
    func_800469B0(D_801BED68);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801BED68);
    func_80044978(D_801BEE94, arg1);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801BEE94);
    r = &D_801BEEAC;
    r->v = arg1[0];
    D_801BEEAE = arg1[1];
    func_800449FC(D_801BEEA0, r);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801BEEA0);
}

void func_801B181C(void) {
    GaFT4 *p;

    p = D_80163C74;
    func_800468FC(p);
    p->x0 = 0;
    p->r = 0x80;
    p->g = 0x80;
    p->x1 = 0x60;
    p->b = 0x80;
    p->y2 = 0x80;
    p->x3 = 0x60;
    p->u0 = 0;
    p->v0 = 0;
    p->y0 = 0;
    p->y3 = 0x80;
    p->u1 = 0xC0;
    p->v2 = 0xFF;
    p->y1 = 0;
    p->x2 = 0;
    p->v1 = 0;
    p->u2 = 0;
    p->tpage = 0x10D;
    p->v3 = 0xFF;
    p->u3 = 0xC0;
    func_80046794(D_801517C0 + 0x4084, p);
    D_80163C74 = p + 1;
}

void func_801B18D4(void) {
    MgMat lw;
    MgMat m;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    u8 *rgb;
    s16 i;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[2][i] = 0;
        m.m[1][i] = 0;
        m.m[0][i] = 0;
    }
    n = 8;
    if (p->unk2 >= 0x16) {
        n = 0x1E - p->unk2;
    }
    rot.vy = 0;
    rot.vx = 0;
    rot.vz = p->unk16;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x800;
    func_8003C21C(&rot, &lw);
    func_8003B05C(&m, &lw);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BED88 = p->unk1A;
    D_801BED87 = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801BED84;
    *rgb = D_801BED85 = D_801BED86 = n << 4;
    D_80163C74 = func_800D4D90(rgb - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (p->unk6 > 0) {
            p->unk6 = 0;
            p->unkE *= -1;
        }
        p->unkE += 20;
        p->unk16 += 0x200;
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B1AF0(void) {
    MgTask *p;
    s32 **tbl;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801BED8C[0] = (s32)D_801BED98[p->unk1A];
    D_801BED94 = p->unk2;
    D_801D6EC0 = (u8 *)func_800D4D90(D_801BED8C, D_801517C0 + 0x70, 0xC, (s32)D_801D6EC0);
    tbl = D_801BED98;
    if (D_80062D98 == 0) {
        p->unkC -= p->unkC / 16;
        p->unkE -= p->unkE / 16;
        p->unk10 -= p->unk10 / 16;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 >= tbl[p->unk1A][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B1C70(void) {
    MgTask *p;
    MgTask *q;
    s16 ang;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1AF0)];
        q->unk4 = p->unk4;
        q->unk6 = p->unk6;
        q->unk8 = p->unk8;
        q->unkC = 0;
        q->unkE = 0;
        q->unk10 = 0;
        q->unk1A = 0;
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1AF0)];
        q->unk4 = p->unk4;
        q->unk6 = p->unk6;
        q->unk8 = p->unk8;
        q->unkE = -0x32;
        q->unkC = 0;
        q->unk10 = 0;
        q->unk1A = 1;
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B18D4)];
        q->unk4 = p->unk4;
        q->unk8 = p->unk8;
        q->unk6 = 0;
        ang = func_80042DA8() % 0x1000;
        q->unkC = (u32)(func_80039B40(ang) * 25) >> 10;
        q->unk10 = (u32)(func_80039A74(ang) * 25) >> 10;
        q->unkE = -func_80042DA8() % 200 - 0x64;
        q->unk1A = func_80042DA8() % 3;
        p->unk2++;
        if (p->unk2 == 10) {
            p->unk0 = -1;
        }
    }
}

void func_801B1EA0(void) {
    MgMat m;
    MgMat n;
    MgVec scale;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801BEDA0, &m);
    scale.vx = scale.vy = scale.vz = p->unk2 * 1000;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &n);
    func_8003B48C(&n);
    func_8003B51C(&n);
    func_8003B69C(0, 0, 0);
    D_801BEDB2[0] = p->unk2 * 0x100;
    D_801D6EC0 = func_800D29D4((u8 *)D_801BEDB2 - 0xA, D_801517C0 + 0x70, 0xC, D_801D6EC0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B1FE0(void) {
    MgMat m;
    MgMat n;
    MgVec scale;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801BEDB8, &m);
    scale.vx = scale.vy = scale.vz = 0x4000 - p->unk2 * 1000;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &n);
    func_8003B48C(&n);
    func_8003B51C(&n);
    func_8003B69C(0, 0, 0);
    D_801BEDCA[0] = p->unk2 * 0x100;
    D_801D6EC0 = func_800D29D4((u8 *)D_801BEDCA - 0xA, D_801517C0 + 0x70, 0xC, D_801D6EC0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B2128(void) {
    MgTask *p;
    s16 lim;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        D_80151A4E[p->unk1C][0] += p->unkE;
        p->unkE += 0xA;
        lim = D_801D6F06[p->unk1C * 4];
        if (D_80151A4E[p->unk1C][0] >= lim) {
            D_80151A4E[p->unk1C][0] = lim;
            if ((D_801D6EC4 >> p->unk1C) & 1) {
                func_800D5774(p->unk1C);
                func_800BBA84(0x149, p->unk1C, 0x40);
            }
            p->unk0 = -1;
        }
    }
}

void func_801B226C(void) {
    MgVec a;
    MgVec c;
    MgVec e;
    MgSVec *tbl;
    MgSVec *out;
    MgSVec *dst;
    MgSVec *q;
    MgSVec *ref;
    u8 (*ent)[0xB9C];
    s16 *src;
    s16 k;
    s16 j;
    s16 idx;
    s16 n;
    u32 best;
    u32 d;

    n = *(s16 *)&D_801BC89C / 8;
    tbl = (MgSVec *)((u8 *)&D_801BC89C + 4);
    k = 0;
    out = D_801D6F04;
    ent = D_80151A4C;
    ref = &D_801D6EFC;
    for (; k < 10; k++) {
        dst = (MgSVec *)(k * 8 + (s32)out);
        src = (s16 *)(k * 0xB9C + (s32)ent);
        dst->vx = src[0];
        dst->vy = src[1];
        dst->vz = src[2];
        a.vx = src[0];
        a.vy = src[1];
        a.vz = src[2];
        best = -1;
        idx = 0;
        a.vx -= ref->vx;
        a.vy = 0;
        a.vz -= ref->vz;
        for (j = 0; j < n; j++) {
            q = (MgSVec *)(&tbl[j]);
            c.vx = q->vx;
            c.vy = q->vy;
            c.vz = q->vz;
            c.vx -= a.vx;
            c.vz -= a.vz;
            e.vx = c.vx * c.vx;
            e.vz = c.vz * c.vz;
            d = e.vx + e.vz;
            if (d < best) {
                best = d;
                idx = j;
            }
        }
        D_801D6EC8[k] = idx;
    }
}

void func_801B2420(void) {
    s16 i;

    for (i = 0; i < 0x70; i++) {
        D_801D6F54[i].vx = D_801D6F54[i].vy = D_801D6F54[i].vz = 0;
        func_801B130C(-0x12C, 0x64, &D_801D72D4[i]);
    }
}

void func_801B24B4(void) {
    s16 i;

    for (i = 0; i < 0x70; i++) {
        D_801D6F54[i].vx += D_801D72D4[i].vx;
        D_801D6F54[i].vy += D_801D72D4[i].vy;
        D_801D6F54[i].vz += D_801D72D4[i].vz;
        D_801D72D4[i].vy += 0x14;
        if (D_801D6F54[i].vy > 0) {
            D_801D6F54[i].vy = 0;
            D_801D72D4[i].vy = -D_801D72D4[i].vy;
        }
    }
}

void func_801B25F0(void) {
    MgMat m;
    MgMat unused;
    MgMat lw;
    MgTask *p;
    MgTask *q;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801BEDE0, &m);
    func_8003B35C(&m, &D_801BEDD0);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    if (p->unk2 >= 0x17) {
        D_801BEDF2 = (0x1E - p->unk2) * 12;
        D_801BEDEC = 8;
    }
    D_801D6EC0 = func_800D29D4(D_801BEDE8, D_801517C0 + 0x70, 0xC, D_801D6EC0);
    if (D_80062D98 == 0) {
        if (p->unk2 < 8) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1AF0)];
                D_801BEEB8.vx = 0;
                D_801BEEB8.vy = -0x3E8;
                D_801BEEB8.vz = 0;
                D_801BEEB0.vx = func_80042DA8() % 0x400;
                D_801BEEB0.vy = func_80042DA8() % 0x1000;
                D_801BEEB0.vz = 0;
                func_8003C21C(&D_801BEEB0, &m);
                func_8003B2CC(&m, &D_801BEEB8, &D_801BEEB8);
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unk4 += D_801BEEB8.vx;
                q->unk6 += D_801BEEB8.vy;
                q->unk8 += D_801BEEB8.vz;
                q->unkC = D_801BEEB8.vx / 2;
                q->unkE = D_801BEEB8.vy / 2;
                q->unk10 = D_801BEEB8.vz / 2;
                q->unk1A = 1;
                i++;
            } while (i < 8);
        }
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B28DC(void) {
    MgMat m;
    MgMat n;
    MgMat lw;
    MgTask *p;
    MgTask *q;
    s32 *fd;
    s16 i;
    s16 cnt;
    s32 idx;
    s32 len;
    u8 z;
    MgSVec *ta;
    MgSVec *tb;
    MgSVec *tc;
    MgSVec *s;
    MgSVec *u;
    MgSVec *e;
    MgSVec *ref;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801BEE08, &m);
    func_8003B35C(&m, &D_801BEDF8);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    if (p->unk2 < 0x1E) {
        func_8003B48C(&lw);
        func_8003B51C(&lw);
        D_801D6EC0 = func_800D29D4(D_801BEE14, D_801517C0 + 0x70, 0xC, D_801D6EC0);
    } else {
        fd = &D_801BEE18;
        *fd = 0x28;
        D_801BEE1E = (0x32 - p->unk2) * 0x10;
        func_8003C21C(&D_801BEE08, &n);
        func_8003C73C((p->unk2 - 0x1E) * 400, &n);
        func_8003CA7C((p->unk2 - 0x1E) * 200, &n);
        D_801D6EC0 = func_801B0028((u8 *)fd - 4, D_801517C0 + 0x70, 0xC, D_801D6EC0, D_801D6F54, &lw, &n);
    }
    z = D_80062D98;
    if (z == 0) {
        if (p->unk2 < 0x1E) {
            ta = D_801BB468;
            tb = D_801BBDA4;
            tc = D_801BC8A0;
            cnt = *(s16 *)&D_801BC89C / 8;
            for (i = 0; i < cnt; i++) {
                s = (MgSVec *)(&ta[i]);
                u = (MgSVec *)(&tb[i]);
                e = (MgSVec *)(&tc[i]);
                e->vx = s->vx + (u->vx - s->vx) * p->unk2 / 30;
                e->vy = s->vy + (u->vy - s->vy) * p->unk2 / 30;
                e->vz = s->vz + (u->vz - s->vz) * p->unk2 / 30;
            }
            i = 0;
            len = cnt;
            ref = (MgSVec *)&D_801D6EFC;
            for (; i < 3; i++) {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1AF0)];
                idx = func_80042DA8() % len;
                e = &tc[idx];
                q->unk4 = e->vx + ref->vx;
                q->unk6 = e->vy + ref->vy - 0x190;
                q->unk8 = e->vz + ref->vz;
                q->unk1A = 1;
                q->unkE = -0xC8;
            }
            for (i = 0; i < 10; i++) {
                e = &tc[D_801D6EC8[i]];
                D_80151A4E[i][0] = e->vy;
            }
        } else {
            func_801B24B4();
        }
        if (p->unk2 == 0x1E) {
            for (i = 0; i < 10; i++) {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B2128)];
                q->unk1C = i;
                q->unkE = -0x28;
            }
            func_800BBA84(0x152, -1, 0x40);
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B25F0)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
        }
        p->unk2++;
        if (p->unk2 == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B2DFC(void) {
    MgTask *p;
    s32 t;
    s32 u;
    u16 *g;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = D_801BEE24;
    if (t > 0) {
        D_80163C74 = func_800C4FC8(t, t, t);
    }
    if (D_80062D98 == 0) {
        if (D_801BEE24 > 0) {
            D_801BEE24 -= 0x40;
        }
        g = &D_801031EA;
        u = *g;
        u += 0x20;
        u -= p->unk2 % 2 * 0x40;
        *g = u;
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B2EEC(void) {
    MgTask *p;
    u16 *g;
    s32 k;
    s32 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        g = &D_801031EA;
        n = 6 - p->unk2;
        k = (1 - p->unk2 % 2 * 2) * 10;
        *g += n * k;
        p->unk2++;
        if (p->unk2 == 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B2F9C(void) {
    MgTask *p;
    MgTask *q;
    s16 *d;
    u8 pad[0x20];

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x20) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1C70)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unkC = (((MgSVec *)&D_801D6EFC)->vx - p->unk4) / 10;
            q->unkE = (((MgSVec *)&D_801D6EFC)->vy - p->unk6) / 10;
            q->unk10 = (((MgSVec *)&D_801D6EFC)->vz - p->unk8) / 10;
            func_800BBA84(0x175, p->unk1E, 0x40);
            func_800BBEAC(func_801B2EEC);
        }
        if (p->unk2 == 0x2A) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1EA0)];
            d = &D_801D6EFC;
            *(s16 *)((u8 *)q + 4) = *d;
            *(s16 *)((u8 *)q + 6) = D_801D6EFE;
            *(s16 *)((u8 *)q + 8) = D_801D6F00;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1FE0)];
            *(s16 *)((u8 *)q + 4) = *d;
            *(s16 *)((u8 *)q + 6) = D_801D6EFE;
            *(s16 *)((u8 *)q + 8) = D_801D6F00;
            func_800BBEAC(func_801B2DFC);
            func_800BBA84(0xFA, -1, 0x40);
        }
        if (p->unk2 == 0x38) {
            func_801B1608((MgTask *)D_801BEE40, D_801BEE38);
        }
        if (p->unk2 == 0x39) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B28DC)];
            *(s16 *)((u8 *)q + 4) = D_801D6EFC;
            *(s16 *)((u8 *)q + 6) = D_801D6EFE;
            *(s16 *)((u8 *)q + 8) = D_801D6F00;
            func_800BBA84(0x1AC, -1, 0x40);
        }
        p->unk2++;
        if (p->unk2 == 0x70) {
            p->unk0 = -1;
        }
    }
}

void func_801B322C(arg0, arg1) {
    MgObj20 *q;
    s16 *d;

    func_800BBEAC(func_801B159C);
    D_801D6EC4 = arg0;
    func_800D2980(&D_801B334C, 0, 0, 0);
    func_800D2538(&D_801BEE4C, &D_801BEE48);
    q = &D_80162978[func_800BBEAC(func_801B2F9C)];
    *(s16 *)((u8 *)q + 0x1E) = arg1;
    func_800D3994(arg1, D_8015190F[arg1][0], &q->unk4);
    d = &D_801D6EFC;
    func_800D54EC(arg0, d);
    *d = 0;
    D_801D6EF0 = 0;
    D_801D6EF4 = D_801D6EFE;
    D_801D6EF8 = D_801D6F00;
    func_801B226C();
    func_801B2420();
}
