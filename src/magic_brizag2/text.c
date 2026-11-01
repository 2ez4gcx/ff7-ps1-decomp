#include "common.h"
#include "magic_brizag2/decls.h"

void func_801B0054(void) {
    func_801B58B4();
}

s32 func_801B0074(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0150(s32 ang, MgMat *m, MgVec *v) {
    s32 s;
    s32 c;
    s32 x;
    s32 y;
    s32 z;
    s32 xx;
    s32 yy;
    s32 zz;
    s32 omc;

    s = func_80039A74(ang);
    c = func_80039B40(ang);
    x = v->vx;
    y = v->vy;
    z = v->vz;
    omc = 0x1000 - c;
    xx = (x * x) >> 12;
    yy = (y * y) >> 12;
    zz = (z * z) >> 12;
    m->m[0][0] = xx + (((0x1000 - xx) * c) >> 12);
    m->m[0][1] = ((((x * y) >> 12) * omc) >> 12) - ((z * s) >> 12);
    m->m[0][2] = ((((x * z) >> 12) * omc) >> 12) + ((y * s) >> 12);
    m->m[1][0] = ((((x * y) >> 12) * omc) >> 12) + ((z * s) >> 12);
    m->m[1][1] = yy + (((0x1000 - yy) * c) >> 12);
    m->m[1][2] = ((((y * z) >> 12) * omc) >> 12) - ((x * s) >> 12);
    m->m[2][0] = ((((x * z) >> 12) * omc) >> 12) - ((y * s) >> 12);
    m->m[2][1] = ((((y * z) >> 12) * omc) >> 12) + ((x * s) >> 12);
    m->m[2][2] = zz + (((0x1000 - zz) * c) >> 12);
}

void func_801B02CC(MgSVec *p, MgSVec *o, MgVec *n) {
    MgVec d;
    s32 dot;

    d.vx = p->vx - o->vx;
    d.vy = p->vy - o->vy;
    d.vz = p->vz - o->vz;
    dot = (n->vx * d.vx + n->vy * d.vy + n->vz * d.vz) >> 12;
    p->vx -= (dot * n->vx) >> 12;
    p->vy -= (dot * n->vy) >> 12;
    p->vz -= (dot * n->vz) >> 12;
}

s16 func_801B03A8(MgSVec *p, MgSVec *q, MgVec *n) {
    MgVec up;
    s32 a;
    s32 b;

    up.vx = 0;
    up.vy = -0x1000;
    up.vz = 0;
    a = p->vx * n->vx + p->vy * n->vy + p->vz * n->vz;
    b = q->vx * n->vx + q->vy * n->vy + q->vz * n->vz;
    return (b - a) / ((n->vx * up.vx + n->vy * up.vy + n->vz * up.vz) >> 12);
}

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B048C);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B06F8);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B09C4);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B0C04);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B0EB4);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B0F78);

BzIdx4 *func_801B123C(BzCtx *ctx, u8 *verts, BzList4 *list) {
    BzRec *r;
    s32 cnt;
    BzIdx4 *l;
    MgSVec *va;
    s32 cx;
    s32 cy;
    s32 cz;
    s32 i;
    s32 k;
    s32 t;
    s32 w;

    l = list->e;
    cnt = list->cnt;
    r = ctx->unk2C;
    for (i = 0; i < cnt; i++, l++, r++) {
        va = (MgSVec *)(verts + l->a);
        cx = va->vx;
        cy = va->vy;
        cz = va->vz;
        va = (MgSVec *)(verts + l->b);
        cx += va->vx;
        cy += va->vy;
        cz += va->vz;
        va = (MgSVec *)(verts + l->c);
        cx += va->vx;
        cy += va->vy;
        cz += va->vz;
        va = (MgSVec *)(verts + l->d);
        cx += va->vx;
        cy += va->vy;
        cz += va->vz;
        cx = cx / 4;
        cy = cy / 4;
        cz = cz / 4;
        r->unk0 = cx;
        r->unk2 = cy;
        r->unk4 = cz;
        r->unk8 = r->unkA = r->unkC = r->unkE = 0;
        t = func_80042DA8();
        r->unk10 = (t & 7) << 4;
        r->unk14 = t * 2 & 0x70;
        if (t & 0x800) {
            k = r->unk10;
            r->unk10 = -k;
        }
        if (t & 0x204080) {
            k = r->unk14;
            r->unk14 = -k;
        }
        r->unk18 = r->unk1A = r->unk1C = 0;
        ctx->n.vx = cx - ctx->c.vx;
        ctx->n.vy = cy - ctx->c.vy;
        ctx->n.vz = cz - ctx->c.vz;
        cx = func_8003A08C(&ctx->n, &ctx->n) >> 12;
        w = cx + 0x84;
        cx = w + func_80042DA8() % 160;
        r->unk20 = cx * ctx->n.vx >> 12;
        r->unk22 = cx * ctx->n.vy >> 12;
        r->unk24 = cx * ctx->n.vz >> 12;
        r->unk26 = func_80042DA8() % 100 + 0x48;
    }
    ctx->unk2C = r;
    return l;
}

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B1524);

BzIdx4b *func_801B17E8(BzCtx *ctx, u8 *verts, BzList4b *list) {
    BzRec *r;
    s32 cnt;
    BzIdx4b *l;
    MgSVec *va;
    s32 cx;
    s32 cy;
    s32 cz;
    s32 i;
    s32 k;
    s32 t;
    s32 w;

    l = list->e;
    cnt = list->cnt;
    r = ctx->unk2C;
    for (i = 0; i < cnt; i++, l++, r++) {
        va = (MgSVec *)(verts + l->a);
        cx = va->vx;
        cy = va->vy;
        cz = va->vz;
        va = (MgSVec *)(verts + l->b);
        cx += va->vx;
        cy += va->vy;
        cz += va->vz;
        va = (MgSVec *)(verts + l->c);
        cx += va->vx;
        cy += va->vy;
        cz += va->vz;
        va = (MgSVec *)(verts + l->d);
        cx += va->vx;
        cy += va->vy;
        cz += va->vz;
        cx = cx / 4;
        cy = cy / 4;
        cz = cz / 4;
        r->unk0 = cx;
        r->unk2 = cy;
        r->unk4 = cz;
        r->unk8 = r->unkA = r->unkC = r->unkE = 0;
        t = func_80042DA8();
        r->unk10 = (t & 7) << 4;
        r->unk14 = t * 2 & 0x70;
        if (t & 0x800) {
            k = r->unk10;
            r->unk10 = -k;
        }
        if (t & 0x204080) {
            k = r->unk14;
            r->unk14 = -k;
        }
        r->unk18 = r->unk1A = r->unk1C = 0;
        ctx->n.vx = cx - ctx->c.vx;
        ctx->n.vy = cy - ctx->c.vy;
        ctx->n.vz = cz - ctx->c.vz;
        cx = func_8003A08C(&ctx->n, &ctx->n) >> 12;
        w = cx + 0x84;
        cx = w + func_80042DA8() % 160;
        r->unk20 = cx * ctx->n.vx >> 12;
        r->unk22 = cx * ctx->n.vy >> 12;
        r->unk24 = cx * ctx->n.vz >> 12;
        r->unk26 = func_80042DA8() % 100 + 0x48;
    }
    ctx->unk2C = r;
    return l;
}

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B1AD0);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B1B68);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B200C);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B2548);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B29DC);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B2F08);

void func_801B2FCC(MgSVec *v0, MgSVec *v1, s32 color) {
    MgLineG2 *p;
    MgTag *ot;
    s32 otz;
    s32 sxy;
    s32 flag;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    p = D_801EA264;
    otz = func_8003BBDC(v0, &p->x0, &sxy, &flag);
    func_8003BBDC(v1, &p->x1, &sxy, &flag);
    p->tag.len = 4;
    *(s32 *)&p->r0 = color;
    *(s32 *)&p->r1 = color;
    p->code = 0x52;
    ot = (MgTag *)D_801517C0 + (otz >> 2) + 0x1C;
    p->tag.addr = ot->addr;
    ot->addr = (u32)p;
    p++;
    D_801EA264 = p;
}

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B30D0);

void func_801B3294(void) {
    MgSVec rot;
    MgSVec v;
    MgMat m;
    MgVec n;
    MgTask *p;
    s32 k;
    s32 t;
    s32 c;
    s32 u;

    p = &D_80162978[D_8015169C];
    n.vx = D_80158D00 - p->unk4;
    n.vy = 0;
    n.vz = D_80158D04 - p->unk8;
    k = func_80039F5C(func_8003A08C(&n, &n)) / 3 * 2;
    rot.vx = 0;
    rot.vy = -(p->unk2 << 2) - 0x14;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    func_8003AB84(&m, &n, &n);
    v.vx = p->unk4 + (k * n.vx >> 12);
    u = p->unk2 * 18 - 0xE0;
    v.vy = p->unk6 - u;
    v.vz = p->unk8 + (k * n.vz >> 12);
    t = p->unk2;
    if (t < 6) {
        c = t * 21;
    } else if (t >= 10) {
        c = -0x80 - ((t - 10) << 4);
    } else {
        c = 0x80;
    }
    func_801B30D0((MgSVec *)&p->unk4, &v, c);
    if (p->unk2 >= 0x12) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3474(void) {
    MgSVec rot;
    MgSVec pad;
    MgSVec v;
    MgMat m;
    MgMat pad2;
    MgVec scale;
    MgTask *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unkC;
    rot.vy = p->unkE;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    v.vx = 0;
    v.vy = -p->unk14;
    v.vz = 0;
    func_8003B27C(&m, &v, (MgVec *)m.t);
    m.t[0] += p->unk4;
    m.t[1] += p->unk6;
    m.t[2] += p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk10;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801D5E58;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801EA264 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801EA264);
    if (p->unk2 >= p->unk18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        t = p->unk14 - p->unk16;
        p->unk14 = t;
        if (t < 0) {
            p->unk14 = 0;
        }
        p->unk2++;
    }
}

void func_801B3640(void) {
    MgSVec rot;
    s32 c;
    MgSVec pad;
    MgSVec v;
    MgMat m;
    MgMat pad2;
    MgVec scale;
    MgTask *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unkC;
    rot.vy = p->unkE;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    v.vx = 0;
    v.vy = -p->unk14;
    v.vz = 0;
    func_8003B27C(&m, &v, (MgVec *)m.t);
    m.t[0] += p->unk4;
    m.t[1] += p->unk6;
    m.t[2] += p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk10;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    ((MgScratch *)0x1F800000)->unk0 = D_801D5E58;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= p->unk18) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - p->unk18) * 0x15;
    }
    D_801EA264 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801EA264);
    if (p->unk2 >= p->unk18 + 6) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        t = p->unk14 - p->unk16;
        p->unk14 = t;
        if (t < 0) {
            p->unk14 = 0;
        }
        p->unk2++;
    }
}

void func_801B3844(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk10;
    func_8003B35C(&m, &scale);
    *(M2C_UNK **)0x1F800000 = &D_801D73C0;
    *(s32 *)0x1F800004 = D_801517C0 + 0x70;
    *(s32 *)0x1F800008 = 0xC;
    *(s32 *)0x1F80000C = D_801EA264;
    *(s32 *)0x1F800010 = 0;
    func_8003B69C(0, 0, 0);
    if (p->unk2 < 0x24) {
        func_8003A63C(&D_800FA63C, &m, &m);
        func_8003B48C(&m);
        func_8003B51C(&m);
        D_801EA264 = func_801B0EB4((void *)0x1F800000, 0);
    } else {
        func_8003A63C(&D_800FA63C, &m, (MgMat *)0x1F800034);
        *(M2C_UNK **)0x1F80002C = &D_801ECA7C;
        D_801EA264 = func_801B2F08((void *)0x1F800000, 0);
    }
    if (p->unk2 >= 0x32) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x12) {
            p->unk10 += p->unk12;
        }
        p->unk2++;
    }
}

void func_801B3A1C(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6 + p->unk14;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk10;
    func_8003B35C(&m, &scale);
    *(M2C_UNK **)0x1F800000 = &D_801D5F9C;
    *(s32 *)0x1F800004 = D_801517C0 + 0x70;
    *(s32 *)0x1F800008 = 0xC;
    *(s32 *)0x1F80000C = D_801EA264;
    *(s32 *)0x1F800010 = 0;
    func_8003B69C(0, 0, 0);
    if (p->unk2 < 2) {
        func_8003A63C(&D_800FA63C, &m, &m);
        func_8003B48C(&m);
        func_8003B51C(&m);
        D_801EA264 = func_801B0EB4((void *)0x1F800000, 0);
    } else {
        func_8003A63C(&D_800FA63C, &m, (MgMat *)0x1F800034);
        *(M2C_UNK **)0x1F80002C = &D_801EA27C;
        D_801EA264 = func_801B2F08((void *)0x1F800000, 0);
    }
    if (p->unk2 >= 0x10) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 2) {
            p->unk14 += p->unk16;
        }
        p->unk2++;
    }
}

void func_801B3BFC(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 t;

    rot.vx = -0x400;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003C21C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk10;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = &D_801D879C;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t >= 4) {
        ((MgScratch *)0x1F800000)->unkA = (t - 4) << 9;
    }
    func_8003B69C(0, 0, 0);
    D_801EA264 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801EA264);
    if (p->unk2 >= 0xC) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk10 += p->unk12;
        p->unk2++;
    }
}

void func_801B3D94(void) {
    MgTask *p;
    s32 i;
    s32 k;
    s32 sv;

    p = &D_80162978[D_8015169C];
    D_801D9200.v = p->unk2;
    k = p->unk1A;
    for (i = 0; i < 8; i++) {
        sv = D_801EE87C[k].v[3];
        func_800D4368(&D_801EE87C[k], sv, -(sv >> 3));
        D_801EA264 = func_800D4D90(D_801D91F8, D_801517C0 + 0x70, 0xC, D_801EA264);
        if (D_80062D98 == 0) {
            sv = (s16)D_801EE87C[k].v[7];
            D_801EE87C[k].v[1] += sv;
            D_801EE87C[k].v[7] = sv - (sv >> 4);
        }
        k++;
        if (k >= 0xDE) {
            k = 0;
        }
    }
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3F24(void) {
    MgTask *p;
    MgVec *n;
    u16 *frame;
    s32 k;

    n = (MgVec *)0x1F800084;
    p = &D_80162978[D_8015169C];
    *n = *(MgVec *)&p->unkC;
    func_801B0150(func_801B0074(&D_801D91E8, n, (MgVec *)0x1F800094), (MgMat *)0x1F800054, (MgVec *)0x1F800094);
    ((MgMat *)0x1F800054)->t[0] = p->unk4;
    ((MgMat *)0x1F800054)->t[1] = p->unk6;
    ((MgMat *)0x1F800054)->t[2] = p->unk8;
    ((MgVec *)0x1F800074)->vx = ((MgVec *)0x1F800074)->vy = ((MgVec *)0x1F800074)->vz = p->unk1C;
    func_8003B35C((MgMat *)0x1F800054, (MgVec *)0x1F800074);
    func_8003A63C(&D_800FA63C, (MgMat *)0x1F800054, (MgMat *)0x1F800054);
    func_8003B48C((MgMat *)0x1F800054);
    func_8003B51C((MgMat *)0x1F800054);
    frame = &D_801D920C;
    *frame = p->unk2;
    D_801EA264 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EA264);
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        k = p->unk1E;
        p->unk4 += k * n->vx >> 12;
        p->unk6 += k * n->vy >> 12;
        p->unk8 += k * n->vz >> 12;
        p->unk2++;
    }
}

void func_801B4124(void) {
    MgTask *p;
    s32 i;
    s32 k;
    s32 sv;

    p = &D_80162978[D_8015169C];
    D_801D9218.v = (s16)p->unk2 >> 1;
    k = p->unk1A;
    for (i = 0; i < 0x14; i++) {
        sv = (s16)D_801EE87C[k].v[3];
        func_800D4368(&D_801EE87C[k], sv, -(sv >> 4));
        D_801EA264 = func_800D4D90(D_801D9210, D_801517C0 + 0x70, 0xC, D_801EA264);
        if (D_80062D98 == 0) {
            D_801EE87C[k].v[0] += D_801EE87C[k].v[4];
            D_801EE87C[k].v[1] += D_801EE87C[k].v[5];
            D_801EE87C[k].v[2] += D_801EE87C[k].v[6];
            D_801EE87C[k].v[4] += (s16)D_801EE87C[k].v[4] >> 3;
            D_801EE87C[k].v[5] -= (s16)D_801EE87C[k].v[5] >> 4;
            D_801EE87C[k].v[6] += (s16)D_801EE87C[k].v[6] >> 3;
        }
        k++;
        if (k >= 0xDE) {
            k = 0;
        }
    }
    if (p->unk2 >= 0xD) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B438C);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B46E0);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B498C);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B5258);

void func_801B57EC(void) {
    MgTask *b;
    MgTask *q;

    D_80162978[D_8015169C].unk0 = -1;
    b = D_80162978;
    q = &b[func_800BBEAC((M2C_UNK *)func_801B5258)];
    func_800D54EC(D_801EA26C, &q->unk4);
    q->unk6 = -0x600;
    q->unk10 = 0x900;
    D_801EA270 = *(MgB8 *)&q->unk4;
    func_800D55F4(0x29, func_800D574C(D_801EA26C), 0xA3);
}

INCLUDE_RODATA("../asm/us/magic_brizag2/nonmatchings/text", D_801B0000);

void func_801B58B4(arg0) {
    D_801EA268 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B5938, 0, 0, 0);
    func_800BBEAC(&func_801B57EC);
    D_801EA26C = arg0;
    D_801EA278 = 0;
}
