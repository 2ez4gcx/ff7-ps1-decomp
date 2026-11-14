#include "common.h"
#include "magic_kujata/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B88A4();
    return &D_801DDD1C;
}

MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EFCE0.m[0][0] = D_801EFCE0.m[1][1] = D_801EFCE0.m[2][2] = scale;
    func_8003B48C(&D_801F04C8);
    func_8003B51C(&D_801F04C8);
    func_8003BC6C(v, (MgVec *)D_801EFCE0.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EFCE0.t, &n);
        D_801EFCE0.t[0] += (dist * n.vx) >> 12;
        D_801EFCE0.t[1] += (dist * n.vy) >> 12;
        D_801EFCE0.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EFCE0);
    func_8003B51C(&D_801EFCE0);
    return &D_801EFCE0;
}

s32 func_801B0184(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F04FA[-v];
    }
    return v;
}

s32 func_801B01C0(s32 t, s32 s) {
    s32 orig;
    s32 i;
    s32 n;

    orig = t;
    if (s > 0) {
        n = s >> 8;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
    } else {
        s = -s;
        n = s >> 8;
        t = 0x1000 - t;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
        t = 0x1000 - t;
    }
    n = (s & 0xFF) + 1;
    t = (t * n + orig * (0x100 - n)) >> 8;
    return t;
}

void func_801B02B0(void) {
    MgCamTask *p;
    MgSVec *sv;
    MgSVec *sv2;
    MgVec *vec;
    s32 i;
    u16 op;
    s32 k;
    MgCam *cam;
    u8 pad[0x100];
    s32 flag;

    sv2 = (MgSVec *)0x1F800008;
    vec = (MgVec *)0x1F800010;
    p = (MgCamTask *)&D_80162978[D_8015169C];
    sv = (MgSVec *)0x1F800000;
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801F03F4.actor = -1;
            D_801F0420.actor = -1;
            D_801F03F4.frames = 0;
            D_801F0420.frames = 0;
            p->unk2 = 1;
        }
        while (D_801F03F4.frames == 0 || D_801F0420.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801F044C = &D_801F03F4;
                D_801F0450 = &D_801F0420;
            } else {
                D_801F044C = &D_801F0420;
                D_801F0450 = &D_801F03F4;
            }
            D_801F044C->mode = op & 0xFF3F;
            switch (D_801F044C->mode) {
            case 1:
                D_801F044C->pos.vx = *p->script++;
                D_801F044C->pos.vy = *p->script++;
                D_801F044C->pos.vz = *p->script++;
                break;
            case 2:
                D_801F044C->frames = func_801B0184(&p->script);
                D_801F044C->vel.vx = (*p->script++ - D_801F044C->pos.vx) / D_801F044C->frames;
                D_801F044C->vel.vy = (*p->script++ - D_801F044C->pos.vy) / D_801F044C->frames;
                D_801F044C->vel.vz = (*p->script++ - D_801F044C->pos.vz) / D_801F044C->frames;
                break;
            case 3:
                sv->vx = D_801F0450->pos.vx - D_801F044C->pos.vx;
                sv->vy = D_801F0450->pos.vy - D_801F044C->pos.vy;
                sv->vz = D_801F0450->pos.vz - D_801F044C->pos.vz;
                D_801F044C->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801F044C->unk18 = D_801F044C->pos;
                D_801F044C->frames = func_801B0184(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801F044C->vel.vx = (sv->vx - D_801F044C->pos.vx) / D_801F044C->frames;
                D_801F044C->vel.vy = (sv->vy - D_801F044C->pos.vy) / D_801F044C->frames;
                D_801F044C->vel.vz = (sv->vz - D_801F044C->pos.vz) / D_801F044C->frames;
                if (D_801F0450->mode == 2) {
                    sv2->vx = D_801F0450->pos.vx + D_801F0450->vel.vx * D_801F0450->frames;
                    sv2->vy = D_801F0450->pos.vy + D_801F0450->vel.vy * D_801F0450->frames;
                    sv2->vz = D_801F0450->pos.vz + D_801F0450->vel.vz * D_801F0450->frames;
                } else {
                    sv2->vx = D_801F0450->pos.vx;
                    sv2->vy = D_801F0450->pos.vy;
                    sv2->vz = D_801F0450->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801F044C->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801F044C->unk4) / D_801F044C->frames;
                break;
            case 4:
                D_801F044C->frames = func_801B0184(&p->script);
                sv->vx = *p->script++ - D_801F044C->pos.vx;
                sv->vy = *p->script++ - D_801F044C->pos.vy;
                sv->vz = *p->script++ - D_801F044C->pos.vz;
                D_801F044C->unk18.vx = ((sv->vx - D_801F044C->vel.vx * D_801F044C->frames) * 2) / (D_801F044C->frames * D_801F044C->frames);
                D_801F044C->unk18.vy = ((sv->vy - D_801F044C->vel.vy * D_801F044C->frames) * 2) / (D_801F044C->frames * D_801F044C->frames);
                D_801F044C->unk18.vz = ((sv->vz - D_801F044C->vel.vz * D_801F044C->frames) * 2) / (D_801F044C->frames * D_801F044C->frames);
                break;
            case 5:
                D_801F044C->frames = func_801B0184(&p->script);
                D_801F044C->unk28 = *p->script++;
                D_801F044C->unk4 = 0;
                D_801F044C->unk8 = 0x1000 / D_801F044C->frames;
                D_801F044C->unk18.vx = D_801F044C->pos.vx;
                D_801F044C->unk18.vy = D_801F044C->pos.vy;
                D_801F044C->unk18.vz = D_801F044C->pos.vz;
                D_801F044C->vel.vx = *p->script++ - D_801F044C->pos.vx;
                D_801F044C->vel.vy = *p->script++ - D_801F044C->pos.vy;
                D_801F044C->vel.vz = *p->script++ - D_801F044C->pos.vz;
                break;
            case 6:
                if ((D_801F044C->actor = *p->script++) == 0) {
                    D_801F044C->actor = p->actor;
                }
                D_801F044C->part = *p->script++;
                break;
            case 7:
                D_801F044C->actor = -1;
                break;
            case 0:
            case 9:
                D_801F044C->frames = func_801B0184(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801F044C = &D_801F03F4;
        D_801F0450 = &D_801F0420;
        for (i = 0; i < 2; i++) {
            switch (D_801F044C->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801F044C->vel.vx += D_801F044C->unk18.vx;
                D_801F044C->vel.vy += D_801F044C->unk18.vy;
                D_801F044C->vel.vz += D_801F044C->unk18.vz;
            case 2:
                D_801F044C->pos.vx += D_801F044C->vel.vx;
                D_801F044C->pos.vy += D_801F044C->vel.vy;
                D_801F044C->pos.vz += D_801F044C->vel.vz;
                break;
            case 3:
                D_801F044C->unk18.vx += D_801F044C->vel.vx;
                D_801F044C->unk18.vy += D_801F044C->vel.vy;
                D_801F044C->unk18.vz += D_801F044C->vel.vz;
                D_801F044C->unk4 += D_801F044C->unk8;
                vec->vx = D_801F0450->pos.vx - D_801F044C->unk18.vx;
                vec->vy = D_801F0450->pos.vy - D_801F044C->unk18.vy;
                vec->vz = D_801F0450->pos.vz - D_801F044C->unk18.vz;
                func_8003A078(vec, sv);
                D_801F044C->pos.vx = D_801F0450->pos.vx - ((sv->vx * D_801F044C->unk4) >> 12);
                D_801F044C->pos.vy = D_801F0450->pos.vy - ((sv->vy * D_801F044C->unk4) >> 12);
                D_801F044C->pos.vz = D_801F0450->pos.vz - ((sv->vz * D_801F044C->unk4) >> 12);
                break;
            case 5:
                D_801F044C->unk4 += D_801F044C->unk8;
                k = func_801B01C0(D_801F044C->unk4, D_801F044C->unk28);
                D_801F044C->pos.vx = D_801F044C->unk18.vx + ((D_801F044C->vel.vx * k) >> 12);
                D_801F044C->pos.vy = D_801F044C->unk18.vy + ((D_801F044C->vel.vy * k) >> 12);
                D_801F044C->pos.vz = D_801F044C->unk18.vz + ((D_801F044C->vel.vz * k) >> 12);
                break;
            }
            cam = D_801F044C;
            D_801F044C = &D_801F0420;
            D_801F0450 = &D_801F03F4;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801F03F4.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801F03F4.actor == -1) {
                func_8003BC6C(&D_801F03F4.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801F03F4.pos, vec);
                if (D_801F03F4.part != -1) {
                    func_800D3994(D_801F03F4.actor, D_801F03F4.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801F03F4.actor].vx;
                    sv->vy = D_80151A4C[D_801F03F4.actor].vy;
                    sv->vz = D_80151A4C[D_801F03F4.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801F0420.mode != 9) {
            if (D_801F0420.actor == -1) {
                func_8003BC6C(&D_801F0420.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801F0420.pos, vec);
                if (D_801F0420.part != -1) {
                    func_800D3994(D_801F0420.actor, D_801F0420.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801F0420.actor].vx;
                    sv->vy = D_80151A4C[D_801F0420.actor].vy;
                    sv->vz = D_80151A4C[D_801F0420.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801F03F4.mode != 9) {
            D_80158D00 = D_801F03F4.pos;
        }
        if (D_801F0420.mode != 9) {
            D_801031E8 = D_801F0420.pos;
        }
    }
}

void func_801B12E4(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B02B0)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B1348);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B1AF4);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B2250);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B292C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B2DB8);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B3878);

void func_801B3C60(void) {
    MgTask *p;
    u8 c[4];
    s16 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = (u16)p->unkC + (u16)p->unkE;
        p->unkC = t;
        if (t >= 0x1000) {
            p->unkC = 0x1000;
            p->unk0 = -1;
        }
        func_8003B69C(((u8 *)p)[8], ((u8 *)p)[9], ((u8 *)p)[0xA]);
        func_8003B710(&p->unk4, p->unkC, c);
        D_800F5B70 = c[0];
        D_800F5B71 = c[1];
        D_800F5B72 = c[2];
    }
}

void func_801B3D20(KjB4 *src, s32 n) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B3C60)];
    ((u8 *)p)[4] = D_800F5B70;
    ((u8 *)p)[5] = D_800F5B71;
    ((u8 *)p)[6] = D_800F5B72;
    *(KjB4 *)((u8 *)p + 8) = *src;
    p->unkC = 0;
    p->unkE = 0x1000 / n;
}

void func_801B3DE4(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_801B0068((MgSVec *)&p->unk4, p->unk14, -0x3E8);
    D_801F00A0[0] = p->unk2 | 0x8000;
    D_80163C74 = func_800D4D90(&D_801F00A0[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801DDC58[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B3EA8(void) {
    MgSVec pts[151];
    KjQuad *w;
    KjQuad *p;
    KjPart *e;
    s32 i;
    MgTask *t;
    s32 j;
    s32 u;
    MgSVec *q;

    p = (KjQuad *)D_80163C74;
    func_8003B48C(&D_801F04C8);
    func_8003B51C(&D_801F04C8);
    e = D_801F0510;
    do {
        i = 0;
    } while (0);
    if (D_801F0090 > 0) {
        do {
            pts[i].vx = *(u16 *)&e->padC[0] + (func_80039A74(e->f8) * e->f4 >> 12) + (func_80039A74(e->fA) * e->f4 >> 12);
            pts[i].vy = *(u16 *)&e->padC[2];
            pts[i].vz = *(u16 *)&e->padC[4] + (func_80039B40(e->f8) * e->f4 >> 12) + (func_80039B40(e->fA) * e->f4 >> 12);
            if (e->mode != 0) {
                q = &pts[e->mode];
                D_801F01B4->v[0].vx = (*q).vx - e->f6 / 2;
                D_801F01B4->v[1].vx = D_801F01B4->v[0].vx + e->f6;
                D_801F01B4->v[0].vy = D_801F01B4->v[1].vy = (*q).vy;
                D_801F01B4->v[0].vz = D_801F01B4->v[1].vz = (*q).vz;
                D_801F01B4->v[2].vx = pts[i].vx - e->f6 / 2;
                D_801F01B4->v[3].vx = D_801F01B4->v[2].vx + e->f6;
                D_801F01B4->v[2].vy = D_801F01B4->v[3].vy = pts[i].vy;
                D_801F01B4->v[2].vz = D_801F01B4->v[3].vz = pts[i].vz;
                D_801F01B4->otz = func_8003BD7C(&D_801F01B4->v[0], &D_801F01B4->v[1], &D_801F01B4->v[2], &D_801F01B4->v[3], (s32)p + 8, (s32)p + 0x10, (s32)p + 0x18, (s32)p + 0x20, &D_801F01B4->ext, &D_801F01B4->flag);
                if (!(D_801F01B4->flag & 0x60000)) {
                    j = e->life;
                    p->tag = 0x09000000;
                    p->c0 = 0x2E808080;
                    p->cl0 = D_801F00B4[j].a | 0x78080000;
                    p->cl1 = D_801F00B4[j].b | 0x2C0000;
                    w = p;
                    w->uv2 = D_801F00B4[j].c;
                    w->uv3 = D_801F00B4[j].d;
                    u = ((D_801F01B4->otz >> 2) << 2) + 0x70;
                    func_80046794(u + D_801517C0, (s32)p++);
                }
            }
            if (e->pad3 != 0 && D_80062D98 == 0) {
                if ((u8)((e->pad3 & 0x7F) % 3) == 0) {
                    t = &D_80162978[func_800BBEAC(func_801B3DE4)];
                    t->unk4 = (D_801F01B4->v[2].vx + D_801F01B4->v[3].vx) / 2;
                    t->unk6 = D_801F01B4->v[2].vy;
                    t->unk8 = D_801F01B4->v[2].vz;
                    t->unk14 = func_80042DA8() % 0x1000 + 0x6000;
                }
                e->pad3 = (e->pad3 + 1) | 0x80;
            }
            e++;
            i++;
        } while (i < D_801F0090);
    }
    D_80163C74 = (s32)p;
}

void func_801B42B8(void) {
    KjPart *e;
    KjPart *par;
    KjPt *pt;
    s32 i;
    s32 r;
    s32 t;
    u8 pad[8];

    i = 0;
    e = &D_801F0510[D_801F0090];
    if (D_801F0090 > 0) {
        do {
            e--;
            if (e->mode == 0) {
                pt = &D_801F10C8[e->pidx];
                r = func_80042DA8();
                t = (u16)pt->a - 0x100;
                pt->a = t + r % 0x200;
                r = func_80042DA8();
                t = (u16)pt->b - 0x100;
                pt->b = t + r % 0x200;
                r = func_80042DA8();
                t = (u16)pt->d - 0x100;
                pt->d = t + r % 0x200;
                pt->c += func_80039A74(pt->d) << 8 >> 12;
                r = func_80042DA8();
                t = (u16)pt->f - 0x10;
                pt->f = t + r % 0x20;
                pt->e += func_80039A74(pt->f) << 8 >> 12;
                e->life = func_80042DA8() & 0xF;
                e->f8 += func_80039A74(pt->a) << 8 >> 12;
                e->fA += func_80039A74(pt->b) << 8 >> 12;
                e->f4 = (func_80039A74(pt->c) * 0xFA >> 12) + 0xFA;
                e->f6 = (func_80039A74(pt->e) * 0x96 >> 12) + 0x546;
            } else {
                par = &D_801F0510[e->mode];
                e->f8 = par->f8;
                e->fA = par->fA;
                e->f4 = par->f4 + 0x64;
                e->f6 = par->f6;
                e->life = (e->life & 0x10) | (par->life & 0xF);
            }
            i++;
        } while (i < D_801F0090);
    }
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B4570);

void func_801B4B88(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 r;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B4570)];
            q->unk8 = 0;
            q->unk4 = 0;
            q->unk6 = -0x2710;
            D_801F04B0 += 0x200 + (func_80042DA8() & 0x3FF);
            r = func_80042DA8() % 700 + 0x64;
            q->unkC = r * func_80039A74(D_801F04B0) >> 12;
            q->unkE = 0x3E8;
            q->unk10 = r * func_80039B40(D_801F04B0) >> 12;
            q->unk16 = 0xA;
            if (--p->unk0 == 0) {
                p->unk0 = -1;
                return;
            }
        } while (++i < 2);
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B4D10);

void func_801B500C(void) {
    MgTask *p;
    s32 t;
    s16 y;
    s16 r;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x2D) {
        if (D_80062D98 == 0) {
            func_801B42B8();
        }
        func_801B3EA8();
    } else {
        t -= 0x2D;
        if (t < 0xF) {
            if (t == 0) {
                func_801B4D10();
            }
            y = 0;
            t = (t << 12) / 15;
            r = func_801B01C0(t, 0x3C0);
            if (t >= 0x800) {
                y = t - 0x800;
            }
            func_8003A63C(&D_801F04C8, D_801EFCC0, &D_801F01D4->m1);
            D_801F01D4->rot.vx = 0;
            D_801F01D4->rot.vy = t;
            D_801F01D4->rot.vz = 0;
            func_8003C21C(D_801F01D4, &D_801F01D4->m2);
            D_801F01D4->scale.vx = D_801F01D4->scale.vy = D_801F01D4->scale.vz = 0x1000;
            func_8003B35C(&D_801F01D4->m2, &D_801F01D4->scale);
            D_80163C74 = func_801B1348(D_801EFCB0, D_801517C0 + 0x70, 0xC, D_80163C74, D_801F04F4, D_801F04F0, D_801F04F8, r, y, &D_801F01D4->m1, &D_801F01D4->m2);
        } else {
            p->unk0 = -1;
            return;
        }
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B521C(void) {
    MgTask *p;
    s32 t;
    s32 k;
    s16 c;
    u8 pad[8];
    s32 u;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t <= 0) {
        D_801F01E2 = 0;
        k = p->unk14 * (t << 12) >> 12;
    } else {
        t -= 1;
        if (t < 2) {
            u = t << 12;
            t = u >> 1;
            D_801F01E2 = t;
            k = p->unk14;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    c = k;
    D_801F01F8 = c;
    D_801F01F0 = c;
    D_801F01E8.m[0][0] = c;
    D_801F01FC = *(s16 *)((u8 *)p + 4);
    D_801F0200 = *(s16 *)((u8 *)p + 6);
    func_8003B48C(&D_801F01E8);
    func_8003B51C(&D_801F01E8);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801F01D8, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B536C(void) {
    MgTask *p;
    MgTask *q;
    s16 t;
    s32 n;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t >= 10) {
            n = t - 10;
            if (n < 0x3E) {
                if ((n & 1) == 0) {
                    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B521C)];
                    q->unk4 = func_80042DA8() % 400 - 0xC8;
                    q->unk6 = func_80042DA8() % 400 - 0xC8;
                    q->unk14 = func_80042DA8() % 96 + 0x20;
                }
            } else {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B54CC(void) {
    MgTask *p;
    KjFace *f;
    MgSVec *out;
    u8 *vtx;
    MgSVec *v0;
    MgSVec *v1;
    MgSVec *v2;
    s32 i;
    u16 n;
    s32 k;
    u8 pad[8];

    p = &D_80162978[D_8015169C];
    D_801F04EC = (s32)D_801B89E0;
    out = (MgSVec *)D_801F04EC;
    i = 0;
    vtx = D_801DBAF4;
    f = (KjFace *)(D_801DBAF0 + vtx);
    n = *(u16 *)f;
    f = (KjFace *)((u8 *)f + 4);
    if ((s16)n > 0) {
        do {
            v1 = (MgSVec *)(vtx + f->i1);
            v0 = (MgSVec *)(vtx + f->i2);
            v2 = (MgSVec *)(vtx + f->i0);
            D_801F0208->a.vx = v0->vx - v1->vx;
            D_801F0208->a.vy = v0->vy - v1->vy;
            D_801F0208->a.vz = v0->vz - v1->vz;
            D_801F0208->b.vx = v1->vx - v2->vx;
            D_801F0208->b.vy = v1->vy - v2->vy;
            D_801F0208->b.vz = v1->vz - v2->vz;
            func_8003BA68(D_801F0208, &D_801F0208->b, &D_801F0208->n);
            while ((u32)(D_801F0208->n.vx + 0x4000) > 0x8000 || (u32)(D_801F0208->n.vy + 0x4000) > 0x8000 || (u32)(D_801F0208->n.vz + 0x4000) > 0x8000) {
                D_801F0208->n.vx >>= 1;
                D_801F0208->n.vy >>= 1;
                D_801F0208->n.vz >>= 1;
            }
            func_8003A08C(&D_801F0208->n, &D_801F0208->n);
            k = 0x7D0;
            out->vx = D_801F0208->n.vx * k >> 12;
            out->vy = D_801F0208->n.vy * k >> 12;
            out->vz = D_801F0208->n.vz * k >> 12;
            f++;
            i++;
            out++;
        } while (i < (s16)n);
    }
    p->unk0 = -1;
}

void func_801B575C(void) {
    MgTask *p;
    s32 t;
    s32 n;
    s32 k;
    s16 a;
    s16 b;
    s32 f;

    p = &D_80162978[D_8015169C];
    func_8003A63C(&D_801F04C8, D_801EFCC0, &D_801F020C->m1);
    t = p->unk2;
    if (t < 0xF) {
        k = (t << 12) / 15;
        a = 0x1000 - func_801B01C0(k, -0x2FF);
        if (k < 0x800) {
            b = 0x800 - k;
        } else {
            b = 0;
        }
        if (k >= 0xC00) {
            D_801F020C->rot.vx = D_801F020C->rot.vy = D_801F020C->rot.vz = 0;
        } else {
            D_801F020C->rot.vx = 0;
            D_801F020C->rot.vz = 0;
            D_801F020C->rot.vy = 0x800 - (k << 12) / 3072;
        }
        func_8003C21C(&D_801F020C->rot, &D_801F020C->m2);
        D_801F020C->scale.vx = D_801F020C->scale.vy = D_801F020C->scale.vz = 0x1000;
        func_8003B35C(&D_801F020C->m2, &D_801F020C->scale);
        D_80163C74 = func_801B1AF4(D_801EFCB0, D_801517C0 + 0x70, 0xC, D_80163C74, D_801F04F0, D_801F04F8, a, b, &D_801F020C->m1, &D_801F020C->m2);
    } else {
        t -= 0xF;
        if (t < 0x14) {
            func_8003B48C(&D_801F020C->m1);
            func_8003B51C(&D_801F020C->m1);
            D_80163C74 = func_800D29D4(D_801EFCB0, D_801517C0 + 0x70, 0xC, D_80163C74);
        } else {
            t -= 0x14;
            if (t < 0x14) {
                k = (t << 12) / 20;
                f = func_801B01C0(k, 0x2FF);
                if (k < 0x800) {
                    n = 0;
                } else {
                    n = (k - 0x800) * 2;
                }
                D_801F020C->rot.vx = k;
                D_801F020C->rot.vy = k << 13 >> 12;
                D_801F020C->rot.vz = 0;
                func_8003C21C(&D_801F020C->rot, &D_801F020C->m2);
                D_801F020C->scale.vx = D_801F020C->scale.vy = D_801F020C->scale.vz = (-(n << 11) >> 12) + 0x1000;
                func_8003B35C(&D_801F020C->m2, &D_801F020C->scale);
                D_80163C74 = func_801B2250(D_801EFCB0, D_801517C0 + 0x70, 0xC, D_80163C74, D_801F04EC, (s16)f, (s16)n, &D_801F020C->m1, &D_801F020C->m2);
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B5AE0(void) {
    MgTask *p;
    KjEff *s;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    D_801F0220->v4 = D_801F0220->v8 = 0x4000;
    t = p->unk2;
    if (t < 3) {
        k = (t << 12) / 3;
        D_801F0220->v0 = k * 0x4000 >> 12;
        D_801F021A.v = 0;
    } else {
        t -= 3;
        if (t < 3) {
            D_801F0220->v0 = 0x4000;
            k = (t << 12) / 3;
            D_801F021A.v = k;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    s = D_801F0220;
    func_8003C21C(&p->unkC, &s->m);
    s = D_801F0220;
    s->m.t[0] = p->unk4;
    s->m.t[1] = p->unk6;
    s->m.t[2] = p->unk8;
    func_8003B35C(&s->m, s);
    func_8003A63C(&D_801F04C8, &D_801F0220->m, &D_801F0220->m);
    func_8003B48C(&D_801F0220->m);
    func_8003B51C(&D_801F0220->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801F0210, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B5C98(void) {
    MgTask *p;
    MgTask *q;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B5AE0)];
            q->unk4 = 0;
            q->unk6 = -0x3E8;
            q->unk8 = 0;
            q->unkC = func_80042DA8() % 0x400 + 0x100;
            q->unkE = func_80042DA8() & 0xFFF;
            q->unk10 = 0;
            i++;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 5) {
            p->unk0 = -1;
        }
    }
}

void func_801B5D88(void) {
    MgTask *p;
    s32 t;
    s32 k;
    s32 d;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        d = 0;
        t = (t << 12) / 5;
        k = (t * 0x5800 >> 12) + 0x800;
    } else {
        t -= 5;
        if (t < 5) {
            k = 0x6000;
            d = (t << 12) / 5;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003B69C(0, 0, 0);
    D_801F022E[0] = d;
    func_801B0068((MgSVec *)&p->unk4, k, 0);
    D_80163C74 = func_800D29D4(&D_801F022E[-5], D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B5EDC(void) {
    MgTask *p;
    s16 t;
    s16 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x19) {
        k = 0x1000 - func_801B01C0((t << 12) / 25, -0x180);
    } else {
        p->unk0 = -1;
        return;
    }
    func_8003A63C(&D_801F04C8, D_801EFCC0, &D_801F0240->m);
    D_801F0240->rot.vx = 0;
    D_801F0240->rot.vy = 0;
    D_801F0240->rot.vz = 0;
    func_8003C21C(D_801F0240, &D_801F0240->m2);
    D_80163C74 = func_801B292C(D_801EFCB0, D_801517C0 + 0x70, 0xC, D_80163C74, D_801F04EC, k, &D_801F0240->m, &D_801F0240->m2, D_801F0234);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B6034(void) {
    MgTask *p;
    s32 t;
    s32 k;
    s32 a;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        k = (t << 12) / 10;
        D_801F024E.v = 0x1000 - k;
    } else {
        t -= 10;
        if (t < 20) {
            D_801F024E.v = 0;
        } else {
            t -= 20;
            if (t < 10) {
                k = (t << 12) / 10;
                D_801F024E.v = k;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    t = p->unk2;
    if (t < 10) {
        k = (t << 12) / 10;
        a = k * 0x1200 >> 12;
    } else {
        t -= 10;
        if (t < 30) {
            a = 0x1200;
        } else {
            t -= 30;
            if (t < 0) {
                k = (t << 12) / 0;
                a = (-(k * 0x1200) >> 12) + 0x1200;
            }
        }
    }
    func_8003C21C(&p->unkC, &D_801F0254->m);
    D_801F0254->m.t[0] = p->unk4;
    D_801F0254->m.t[1] = p->unk6;
    D_801F0254->m.t[2] = p->unk8;
    D_801F0254->v0 = D_801F0254->v4 = D_801F0254->v8 = a;
    func_8003B35C(&D_801F0254->m, D_801F0254);
    func_8003A63C(&D_801F04C8, &D_801F0254->m, &D_801F0254->m);
    func_8003B48C(&D_801F0254->m);
    func_8003B51C(&D_801F0254->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801F0244, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unkE += 0x50;
        p->unk2++;
    }
}

void func_801B62C0(void) {
    MgTask *p;
    s32 t;
    s32 k;
    s32 a;
    s32 b;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        k = (t << 12) / 5;
        D_801F0262.v = 0x1000 - k;
    } else {
        t -= 5;
        if (t < 5) {
            D_801F0262.v = 0;
        } else {
            t -= 5;
            if (t >= 5) {
                p->unk0 = -1;
                return;
            }
            k = (t << 12) / 5;
            D_801F0262.v = k;
        }
    }
    t = p->unk2;
    if (t < 15) {
        k = (t << 12) / 15;
        a = k * 0x2000 >> 12;
        b = k * 0x1800 >> 12;
    } else {
        t -= 15;
        if (t < 0) {
            a = 0x2000;
            b = 0x1800;
        }
    }
    func_8003C21C(&p->unkC, &D_801F0268->m);
    D_801F0268->m.t[0] = p->unk4;
    D_801F0268->m.t[1] = p->unk6;
    D_801F0268->m.t[2] = p->unk8;
    D_801F0268->v8 = a;
    D_801F0268->v0 = a;
    D_801F0268->v4 = b;
    func_8003B35C(&D_801F0268->m, D_801F0268);
    func_8003A63C(&D_801F04C8, &D_801F0268->m, &D_801F0268->m);
    func_8003B48C(&D_801F0268->m);
    func_8003B51C(&D_801F0268->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801F0258, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unkE += 0x50;
        p->unk2++;
    }
}

void func_801B6500(void) {
    MgTask *p;
    MgTask *q;
    s32 a;
    s32 r;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((p->unk2 & 1) == 0) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B62C0)];
            a = func_80042DA8() & 0xFFF;
            r = func_80042DA8() % 500 + 0x3E8;
            q->unk4 = r * func_80039A74(a) >> 12;
            q->unk6 = 0;
            q->unk8 = r * func_80039B40(a) >> 12;
            q->unk10 = 0;
            q->unkE = 0;
            q->unkC = 0;
        }
        p->unk2++;
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
            p->unkE += 0x40;
        }
    }
}

void func_801B6644(void) {
    s32 i;

    for (i = 0x774; i >= 0; i -= 0xC) {
        *(s16 *)((u8 *)D_801F1140 + i) = 0;
    }
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B666C);

void func_801B66F8(void) {
    MgTask *p;
    KjSlot *s;
    s32 i;
    s32 n;
    s32 c;

    c = 0x2E808080;
    n = 0;
    s = D_801F1140;
    i = 0;
    p = &D_80162978[D_8015169C];
    D_801F0274->m[2][2] = 0x2800;
    D_801F0274->m[1][1] = 0x2800;
    D_801F0274->m[0][0] = 0x2800;
    D_801F0274->m[2][1] = 0;
    D_801F0274->m[2][0] = 0;
    D_801F0274->m[1][2] = 0;
    D_801F0274->m[1][0] = 0;
    D_801F0274->m[0][2] = 0;
    D_801F0274->m[0][1] = 0;
    *(s32 *)((u8 *)D_801F0274 + 0x28) = c;
    *(s16 *)((u8 *)D_801F0274 + 0x2C) = 0;
    do {
        if (s->unk0 != 0) {
            func_8003B48C(&D_801F04C8);
            func_8003B51C(&D_801F04C8);
            func_8003BC6C((MgSVec *)&s->d, (MgVec *)D_801F0274->t, (s32 *)((u8 *)D_801F0274 + 0x20));
            func_8003B48C(D_801F0274);
            func_8003B51C(D_801F0274);
            M2C_SFIELD(D_801F0274, s32 *, 0x24) = D_801EFC48[s->unk2];
            D_80163C74 = func_800D4D90((u8 *)D_801F0274 + 0x24, D_801517C0 + 0x70, 0xC, D_80163C74);
            if (D_80062D98 == 0) {
                s->unk2++;
                if (s->unk2 >= 0x10) {
                    s->unk0 = 0;
                }
                ((MgSVec *)&s->d)->vy -= 0x32;
            }
            n++;
        }
        s++;
        i++;
    } while (i < 0xA0);
    if (n == 0) {
        p->unk0 = -1;
    }
}

void func_801B68C4(void) {
    MgTask *p;
    s32 r;
    s32 t;
    s32 u;
    s32 v;
    s32 k;
    u8 pad[8];

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        r = (s16)((s16)p->unk2 % 12);
        if (r == 0) {
            t = p->unk0;
            if (t >= 3) {
                p->unk0 = -1;
                return;
            }
            u = t << 11;
            D_801F0284->v.vx = -p->unk4;
            D_801F0284->v.vy = 0;
            D_801F0284->v.vz = -0x1388 - p->unk8;
            k = func_80039F5C(func_8003A078(&D_801F0284->v, &D_801F0284->a));
            k = k * (0x2000 - u);
            v = 0x1000 - u;
            p->unkC = (p->unkC * v + D_801F0284->a.vx * u) >> 12;
            p->unkE = (p->unkE * v + D_801F0284->a.vy * u) >> 12;
            p->unk10 = (p->unk10 * v + D_801F0284->a.vz * u) >> 12;
            u = 0x1000 / (3 - p->unk0);
            p->unk16 = (k >> 12) * u / 10 >> 12;
            p->unk14 = func_80042DA8() % 1000 + 0x7D0;
            p->unk0++;
        }
        if (r < 10) {
            u = (r << 12) / 10;
            p->unk4 += p->unkC * p->unk16 >> 12;
            p->unk6 = -p->unk14 * func_80039A74(u / 2) >> 12;
            p->unk8 += p->unk10 * p->unk16 >> 12;
        } else {
            p->unk6 = 0;
        }
        func_801B666C(&p->unk4);
    }
    func_801B0068((MgSVec *)&p->unk4, 0x2800, 0);
    D_80163C74 = func_800D4D90(D_801F0278, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B6C18(void) {
    MgTask *p;
    MgTask *q;
    s32 a;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B68C4)];
        q->unk0 = 0;
        q->unk8 = 0;
        q->unk6 = 0;
        q->unk4 = 0;
        a = func_80042DA8() & 0xFFF;
        q->unkC = func_80039A74(a);
        q->unkE = 0;
        q->unk10 = func_80039B40(a);
        p->unk2++;
        if (p->unk2 >= 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B6CE0(void) {
    MgTask *p;
    s32 t;
    s32 k;
    s32 a;
    s32 b;
    u8 *fd;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0) {
        k = (t << 12) / 0;
        b = 0x1000 - k;
    } else {
        b = 0;
        if (t >= 0x14) {
            t -= 0x14;
            if (t >= 10) {
                p->unk0 = -1;
                return;
            }
            k = (t << 12) / 10;
            b = k;
        }
    }
    t = p->unk2;
    if (t < 0x1E) {
        a = func_801B01C0((t << 12) / 30, 0x2FF) * 0x1400 >> 12;
    } else {
        t -= 0x1E;
        if (t < 0) {
            a = 0x1400;
        }
    }
    func_8003B69C(0, 0, 0);
    D_801F18C0 = a;
    D_801F0308->v8 = a;
    D_801F0308->v4 = a;
    D_801F0308->v0 = a;
    func_8003A63C(&D_801F04C8, &D_801F02A8, &D_801F0308->m);
    func_8003B35C(&D_801F0308->m, D_801F0308);
    D_801F0292.v = b;
    func_8003B48C(&D_801F0308->m);
    func_8003B51C(&D_801F0308->m);
    fd = (u8 *)&D_801F0292 - 0xA;
    D_80163C74 = func_800D29D4(fd, D_801517C0 + 0x70, 0xC, D_80163C74);
    func_8003A63C(&D_801F04C8, &D_801F02C8, &D_801F0308->m);
    func_8003B35C(&D_801F0308->m, D_801F0308);
    D_801F0292.v = b / 2 + 0x800;
    func_8003B48C(&D_801F0308->m);
    func_8003B51C(&D_801F0308->m);
    D_80163C74 = func_800D29D4(fd, D_801517C0 + 0x70, 0xC, D_80163C74);
    func_8003A63C(&D_801F04C8, &D_801F02E8, &D_801F0308->m);
    func_8003B35C(&D_801F0308->m, D_801F0308);
    D_801F02A2.v = b;
    func_8003B48C(&D_801F0308->m);
    func_8003B51C(&D_801F0308->m);
    D_80163C74 = func_800D29D4((u8 *)&D_801F02A2 - 0xA, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        func_8003C8DC(0x40, &D_801F02A8);
        func_8003C8DC(-0x40, &D_801F02C8);
        p->unk2++;
    }
}

void func_801B7028(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    D_801F031C->v4 = D_801F031C->v8 = 0x2000;
    t = p->unk2;
    if (t < 3) {
        k = (t << 12) / 3;
        D_801F031C->v0 = k * 0x2000 >> 12;
        D_801F0316.v = 0;
    } else {
        t -= 3;
        if (t < 5) {
            D_801F031C->v0 = 0x2000;
            k = (t << 12) / 5;
            D_801F0316.v = k;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003C21C(&p->unkC, &D_801F031C->m);
    D_801F031C->m.t[0] = p->unk4 * D_801F18C0 >> 12;
    D_801F031C->m.t[1] = 0;
    D_801F031C->m.t[2] = (p->unk8 * D_801F18C0 >> 12) - 0x1388;
    func_8003A63C(&D_801F04C8, &D_801F031C->m, &D_801F031C->m);
    func_8003B35C(&D_801F031C->m, D_801F031C);
    func_8003B48C(&D_801F031C->m);
    func_8003B51C(&D_801F031C->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801F030C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B7208(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 r;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            i++;
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B7028)];
            r = func_80042DA8() & 0xFFF;
            q->unk4 = (u32)(func_80039A74(r) * 0x447) >> 10;
            q->unk8 = (u32)(func_80039B40(r) * 0x447) >> 10;
            q->unkC = -0x100;
            q->unkE = r;
            q->unk10 = 0;
        } while (i < 1);
        p->unk2++;
        if (p->unk2 >= 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B731C(void) {
    MgTask *p;
    s16 t;
    s32 n;
    s32 k;
    u8 pad[8];

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 2) {
        D_801F032A = 0;
        k = p->unk14 * (t << 11) >> 12;
    } else {
        n = t - 2;
        if (n < 4) {
            n = (n << 12) / 4;
            D_801F032A = n;
            k = p->unk14;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_801B0068((MgSVec *)&p->unk4, k, 0);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801F0320, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B7438(void) {
    MgTask *p;
    MgTask *q;
    s32 a;
    s32 r;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((p->unk2 & 1) == 0) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B731C)];
            a = func_80042DA8() & 0xFFF;
            r = func_80042DA8() % 1000 + 0x1F4;
            q->unk4 = r * func_80039A74(a) >> 12;
            q->unk6 = func_80042DA8() % 1000 - 0x3E8;
            q->unk8 = r * func_80039B40(a) >> 12;
            q->unk14 = func_80042DA8() % 3584 + 0x200;
        }
        p->unk2++;
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B75D8(void) {
    MgMat m;

    D_801F0364 = D_801EFC88;
    D_801F0354 = D_801EFC88;
    if (D_801EFCAA != 0) {
        D_801F0370 = D_801EFCA4;
    } else {
        D_801F0370 = -D_801EFCA4;
    }
    func_8003A63C(&D_801F0334, &D_801F0354, &m);
    func_801B3878(&m, &D_801F0374);
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B7668);

void func_801B794C(s16 arg0) {
    s32 i;
    s32 j;
    s32 r;
    s32 q;

    for (i = 0x20; i > 0; i--) {
        r = i * 128;
        q = (i - 1) * 128;
        for (j = 0; j < 0x10; j++) {
            ((MgSVec *)((u8 *)D_801F0330 + (r + j * 8)))->vy = ((MgSVec *)((u8 *)D_801F0330 + (q + j * 8)))->vy;
        }
    }
    for (i = 0xF; i >= 0; i--) {
        D_801F0330[i].vy = arg0;
    }
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B79C0);

void func_801B7CFC(void) {
    MgTask *p;
    KjActor *act;
    s32 r;
    s32 i;
    s32 f;
    s32 s;

    p = &D_80162978[D_8015169C];
    act = &D_801518E4[p->unk0];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            p->unk6 = act->pos.vy;
            p->unk4 = act->flags;
        }
        D_801F0388->a.vy = 0;
        D_801F0388->a.vx = 0;
        D_801F0388->a.vz = -0x1388;
        func_8003B2CC(&D_801EFC88, D_801F0388, D_801F0388);
        D_801F0388->v.vx = act->pos.vx - (D_801EFC9C + D_801F0388->a.vx);
        D_801F0388->v.vy = 0;
        D_801F0388->v.vz = act->pos.vz - (D_801F0388->a.vz + D_801EFCA4);
        r = func_80039F5C(func_8003A08C(&D_801F0388->v, &D_801F0388->v));
        i = r / 384;
        f = (r % 384 << 12) / 384;
        s = ((MgSVec *)((u8 *)D_801F0330 + (i << 7)))->vy * (0x1000 - f);
        i++;
        s += ((MgSVec *)((u8 *)D_801F0330 + (i << 7)))->vy * f;
        act->pos.vy = s >> 12;
        if (act->pos.vy != p->unk6) {
            act->flags |= 0x10;
        }
        p->unk2++;
        if (p->unk2 >= 0x4B) {
            act->pos.vy = p->unk6;
            act->flags = (act->flags & 0xEF) | (p->unk4 & 0x10);
            p->unk0 = -1;
        }
    }
}

void func_801B7F24(s16 arg0) {
    D_80162978[func_800BBEAC(&func_801B7CFC)].unk0 = arg0;
}

void func_801B7F6C(void) {
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

void func_801B80A8(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B7F6C)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

void func_801B811C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_800D5138(7);
        }
        if (p->unk2 == 0xC) {
            func_800D51D4(0xA);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B81A8(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_8003A63C(&D_801F04C8, D_801F039C, D_801F03BC);
    func_8003B48C(D_801F03BC);
    func_8003B51C(D_801F03BC);
    D_80163C74 = func_800D29D4(D_801F038C, D_801517C0 + 0x4078, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x69) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B8280);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B88A4);
