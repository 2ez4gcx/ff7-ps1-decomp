#include "common.h"
#include "magic_sting/decls.h"

void func_801B0040(void) {
    func_801B4770();
}

void func_801B0060(void) {
    func_801B4804();
}

MgPolyT *func_801B0080(s32 *arg0, s32 arg1, s32 arg2, MgPolyT *arg3) {
    u8 *pk;
    s32 flag;
    s32 opz;
    s32 otz;
    u32 w;
    u32 k2;
    u8 *base;
    s16 *list;
    u8 *va;
    u8 *vb;
    u8 *vc;
    u32 *ot;
    u16 tpage;
    s32 n;
    s32 i;

    base = ((VhModel *)arg0)->data + 4;
    list = (s16 *)(base + *(u32 *)((VhModel *)arg0)->data);
    n = *list;
    list++;
    tpage = ((VhModel *)arg0)->fC | (*(u16 *)list & 0x19F);
    list++;
    va = base + list[0];
    vb = base + list[1];
    vc = base + list[2];
    pk = (u8 *)arg3;
    for (i = 0; i < n; list += 8, i++) {
        VhFt3 *r;

        r = (VhFt3 *)list;
        gte_ldv3_mk(va, vb, vc);
        gte_rtpt();
        va = base + list[8];
        vb = base + list[9];
        vc = base + list[10];
        gte_stflg_mk(&flag);
        if ((flag & 0x60000) == 0) {
            if (((VhModel *)arg0)->f4 & 0x20) {
                opz = 1;
            } else {
                gte_nclip();
                gte_stopz_m(&opz);
            }
            if (opz > 0) {
                gte_avsz3();
                *(u32 *)pk = 0x07000000;
                gte_stotz_m(&otz);
                ot = (u32 *)otz;
                ot = (u32 *)((s32)ot >> (14 - arg2));
                ot = (u32 *)((s32)ot << 2);
                ot = (u32 *)((u32)ot + (u32)arg1);
                ((VhTag *)pk)->addr = ((VhTag *)ot)->addr;
                ((VhTag *)ot)->addr = (u32)pk;
                gte_stsxy3_m(pk + 8, pk + 0x10, pk + 0x18);
                *(u32 *)(pk + 0xC) = r->uv0;
                *(u16 *)(pk + 0x14) = r->uv1;
                *(u16 *)(pk + 0x1C) = r->uv2;
                *(u16 *)(pk + 0x16) = tpage;
                if (((VhModel *)arg0)->f4 & 0x80) {
                    u32 c;
                    u32 a;
                    u32 x;

                    c = r->col;
                    a = c << 16;
                    x = (c << 8) | 0x24000000;
                    w = c | (a | x);
                    if (((VhModel *)arg0)->fA != 0) {
                        gte_ldrgb_m(&w);
                        gte_mv12(*(u16 *)&((VhModel *)arg0)->fA);
                        gte_mtir0_t();
                        gte_dpcs();
                        gte_strgb_m(pk + 4);
                        pk[7] = 0x24;
                    } else {
                        *(u32 *)(pk + 4) = w;
                    }
                } else {
                    u32 c;
                    u32 a;
                    u32 x;

                    c = w;
                    a = c << 16;
                    x = (c << 8) | 0x24000000;
                    *(u32 *)(pk + 4) = a | x | c;
                }
                if (((VhModel *)arg0)->f4 & 8) {
                    pk[7] |= 2;
                }
                pk += 0x20;
            }
        }
    }
    n = *list;
    list += 2;
    i = 0;
    k2 = 0x2C000000;
    va = base + list[0];
    vb = base + list[1];
    vc = base + list[2];
    for (i = 0; i < n; list += 10, i++) {
        VhFt4 *r;
        u32 tg;

        r = (VhFt4 *)list;
        gte_ldv3_mk(va, vb, vc);
        gte_rtpt();
        va = base + list[10];
        vb = base + list[11];
        vc = base + list[12];
        gte_stflg_mk(&flag);
        if ((flag & 0x60000) == 0) {
            if (((VhModel *)arg0)->f4 & 0x20) {
                opz = 1;
            } else {
                gte_nclip();
                gte_stopz_m(&opz);
            }
            if (opz >= 0) {
                tg = 0x09000000;
                gte_stsxy3_m(pk + 8, pk + 0x10, pk + 0x18);
                gte_ldv0(base + r->vi[3]);
                gte_rtps();
                gte_stsxy_m(pk + 0x20);
                gte_avsz4();
                gte_stotz_m(&otz);
                ot = (u32 *)otz;
                *(u32 *)pk = tg;
                ot = (u32 *)((s32)ot >> (14 - arg2));
                ot = (u32 *)((s32)ot << 2);
                ot = (u32 *)((u32)ot + (u32)arg1);
                ((VhTag *)pk)->addr = ((VhTag *)ot)->addr;
                ((VhTag *)ot)->addr = (u32)pk;
                *(u32 *)(pk + 0xC) = r->uv0;
                *(u16 *)(pk + 0x14) = r->uv1;
                *(u16 *)(pk + 0x1C) = r->uv2;
                *(u16 *)(pk + 0x24) = r->uv3;
                *(u16 *)(pk + 0x16) = tpage;
                if (((VhModel *)arg0)->f4 & 0x80) {
                    u32 c;
                    u32 a;
                    u32 x;

                    c = r->col;
                    a = c << 16;
                    x = (c << 8) | 0x2C000000;
                    w = a | x | c;
                    if (((VhModel *)arg0)->fA != 0) {
                        gte_ldrgb_m(&w);
                        gte_mv12(*(u16 *)&((VhModel *)arg0)->fA);
                        gte_mtir0_t();
                        gte_dpcs();
                        gte_strgb_m(pk + 4);
                        pk[7] = 0x2C;
                    } else {
                        *(u32 *)(pk + 4) = w;
                    }
                } else {
                    u32 c;
                    u32 a;
                    u32 x;

                    c = *(u8 *)&((VhModel *)arg0)->fA;
                    w = c;
                    a = c << 16;
                    x = (c << 8) | (k2 = 0x2C000000);
                    *(u32 *)(pk + 4) = a | x | c;
                }
                if (((VhModel *)arg0)->f4 & 8) {
                    pk[7] |= 2;
                }
                pk += 0x28;
            }
        }
    }
    n = *list;
    list += 2;
    i = 0;
    va = base + list[0];
    vb = base + list[1];
    vc = base + list[2];
    for (i = 0; i < n; list += 10, i++) {

        gte_ldv3_mk(va, vb, vc);
        gte_rtpt();
        va = base + list[10];
        vb = base + list[11];
        vc = base + list[12];
        gte_stflg_mk(&flag);
        if ((flag & 0x60000) == 0) {
            if (((VhModel *)arg0)->f4 & 0x20) {
                opz = 1;
            } else {
                gte_nclip();
                gte_stopz_m(&opz);
            }
            if (opz >= 0) {
                gte_avsz3();
                *(u32 *)pk = 0x06000000;
                gte_stotz_m(&otz);
                ot = (u32 *)otz;
                ot = (u32 *)((s32)ot >> (14 - arg2));
                ot = (u32 *)((s32)ot << 2);
                ot = (u32 *)((u32)ot + (u32)arg1);
                ((VhTag *)pk)->addr = ((VhTag *)ot)->addr;
                ((VhTag *)ot)->addr = (u32)pk;
                gte_stsxy3_m(pk + 8, pk + 0x10, pk + 0x18);
                if (((VhModel *)arg0)->fA != 0) {
                    gte_mv12(&((VhG3 *)list)->c0);
                    gte_mv13(&((VhG3 *)list)->c1);
                    gte_mv14(&((VhG3 *)list)->c2);
                    gte_ldrgb3_t();
                    gte_mv12(*(u16 *)&((VhModel *)arg0)->fA);
                    gte_mtir0_t();
                    gte_dpct();
                    gte_mv12(pk + 4);
                    gte_mv13(pk + 0xC);
                    gte_mv14(pk + 0x14);
                    gte_strgb3_t();
                } else {
                    *(u32 *)(pk + 4) = ((VhG3 *)list)->c0;
                    *(u32 *)(pk + 0xC) = ((VhG3 *)list)->c1;
                    *(u32 *)(pk + 0x14) = ((VhG3 *)list)->c2;
                }
                if (((VhModel *)arg0)->f4 & 8) {
                    pk[7] |= 2;
                }
                pk += 0x1C;
            }
        }
    }
    n = *list;
    list += 2;
    i = 0;
    va = base + list[0];
    vb = base + list[1];
    vc = base + list[2];
    for (i = 0; i < n; list += 12, i++) {
        u32 tg;

        gte_ldv3_mk(va, vb, vc);
        gte_rtpt();
        va = base + list[12];
        vb = base + list[13];
        vc = base + list[14];
        gte_stflg_mk(&flag);
        if ((flag & 0x60000) == 0) {
            if (((VhModel *)arg0)->f4 & 0x20) {
                opz = 1;
            } else {
                gte_nclip();
                gte_stopz_m(&opz);
            }
            if (opz >= 0) {
                tg = 0x08000000;
                gte_stsxy3_m(pk + 8, pk + 0x10, pk + 0x18);
                gte_ldv0(base + ((VhG4 *)list)->vi[3]);
                gte_rtps();
                gte_stsxy_m(pk + 0x20);
                gte_avsz4();
                gte_stotz_m(&otz);
                ot = (u32 *)otz;
                *(u32 *)pk = tg;
                ot = (u32 *)((s32)ot >> (14 - arg2));
                ot = (u32 *)((s32)ot << 2);
                ot = (u32 *)((u32)ot + (u32)arg1);
                ((VhTag *)pk)->addr = ((VhTag *)ot)->addr;
                ((VhTag *)ot)->addr = (u32)pk;
                if (((VhModel *)arg0)->fA != 0) {
                    gte_mv12(&((VhG4 *)list)->c0);
                    gte_mv13(&((VhG4 *)list)->c1);
                    gte_mv14(&((VhG4 *)list)->c2);
                    gte_ldrgb3_t();
                    gte_mv12(*(u16 *)&((VhModel *)arg0)->fA);
                    gte_mtir0_t();
                    gte_dpct();
                    gte_mv12(pk + 4);
                    gte_mv13(pk + 0xC);
                    gte_mv14(pk + 0x14);
                    gte_strgb3_t();
                    gte_ldrgb_m(&((VhG4 *)list)->c3);
                    gte_mv12(*(u16 *)&((VhModel *)arg0)->fA);
                    gte_mtir0_t();
                    gte_dpcs();
                    gte_strgb_m(pk + 0x1C);
                } else {
                    *(u32 *)(pk + 4) = ((VhG4 *)list)->c0;
                    *(u32 *)(pk + 0xC) = ((VhG4 *)list)->c1;
                    *(u32 *)(pk + 0x14) = ((VhG4 *)list)->c2;
                    *(u32 *)(pk + 0x1C) = ((VhG4 *)list)->c3;
                }
                if (((VhModel *)arg0)->f4 & 8) {
                    pk[7] |= 2;
                }
                pk += 0x24;
            }
        }
    }
    return (MgPolyT *)pk;
}

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B0B40);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B165C);

void func_801B1CA8(MgMat *arg0, u16 *arg1) {
    s32 sp10;
    s32 sp14;
    MgHalf *p;
    MgHalf *q;
    MgHalf *r;
    MgWord *w;

    func_80044AC0((s32)D_801CC88C, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801CC88C);
    p = (MgHalf *)&D_801CC728;
    p->v = D_801CC738.v = arg1[2];
    D_801CC732 = D_801CC73A = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)p - 0x10));
    func_8003B64C(&sp10, &sp14);
    func_8003B6BC((s16)arg1[2] / 2, (s16)arg1[3] / 2);
    func_8003B48C(arg0);
    func_8003B51C(arg0);
    w = (MgWord *)&D_801CC6F8;
    w->v = D_8016209C;
    D_80163C74 = func_801B0080((s32 *)w, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B6BC(sp10, sp14);
    q = (MgHalf *)&D_801CC714;
    q->v = arg1[2];
    D_801CC716 = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)q - 0xC));
    func_80044978(D_801CC8CC, arg1);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801CC8CC);
    r = (MgHalf *)&D_801CC8E4;
    r->v = arg1[0];
    D_801CC8E6 = arg1[1];
    func_800449FC(D_801CC8D8, r);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801CC8D8);
}

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

void func_801B2138(s32 arg0, s32 arg1, MgTask *arg2, MgSVec *arg3) {
    MgMat m;

    if (arg1 != -1) {
        func_800D3994(arg0, arg1, arg3);
    } else {
        arg3->vx = D_80151A4C[arg0][0];
        arg3->vy = D_80151A4E[arg0][0];
        arg3->vz = D_80151A50[arg0][0];
    }
    arg3->vx -= arg2->unk14;
    arg3->vy -= arg2->unk18;
    arg3->vz -= arg2->unk1C;
    func_8003BF3C(arg2, &m);
    func_8003B2CC(&m, arg3, arg3);
}

void func_801B2228(void) {
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
            D_801CC8E8.actor = -1;
            D_801CC914.actor = -1;
            D_801CC8E8.frames = 0;
            D_801CC914.frames = 0;
            p->unk2 = 1;
        }
        while (D_801CC8E8.frames == 0 || D_801CC914.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801CC940 = &D_801CC8E8;
                D_801CC944 = &D_801CC914;
            } else {
                D_801CC940 = &D_801CC914;
                D_801CC944 = &D_801CC8E8;
            }
            D_801CC940->mode = op & 0xFF3F;
            switch (D_801CC940->mode) {
            case 1:
                D_801CC940->pos.vx = *p->script++;
                D_801CC940->pos.vy = *p->script++;
                D_801CC940->pos.vz = *p->script++;
                break;
            case 2:
                D_801CC940->frames = func_801B2004(&p->script);
                D_801CC940->vel.vx = (*p->script++ - D_801CC940->pos.vx) / D_801CC940->frames;
                D_801CC940->vel.vy = (*p->script++ - D_801CC940->pos.vy) / D_801CC940->frames;
                D_801CC940->vel.vz = (*p->script++ - D_801CC940->pos.vz) / D_801CC940->frames;
                break;
            case 3:
                sv->vx = D_801CC944->pos.vx - D_801CC940->pos.vx;
                sv->vy = D_801CC944->pos.vy - D_801CC940->pos.vy;
                sv->vz = D_801CC944->pos.vz - D_801CC940->pos.vz;
                D_801CC940->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801CC940->unk18 = D_801CC940->pos;
                D_801CC940->frames = func_801B2004(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801CC940->vel.vx = (sv->vx - D_801CC940->pos.vx) / D_801CC940->frames;
                D_801CC940->vel.vy = (sv->vy - D_801CC940->pos.vy) / D_801CC940->frames;
                D_801CC940->vel.vz = (sv->vz - D_801CC940->pos.vz) / D_801CC940->frames;
                if (D_801CC944->mode == 2) {
                    sv2->vx = D_801CC944->pos.vx + D_801CC944->vel.vx * D_801CC940->frames;
                    sv2->vy = D_801CC944->pos.vy + D_801CC944->vel.vy * D_801CC940->frames;
                    sv2->vz = D_801CC944->pos.vz + D_801CC944->vel.vz * D_801CC940->frames;
                } else {
                    sv2->vx = D_801CC944->pos.vx;
                    sv2->vy = D_801CC944->pos.vy;
                    sv2->vz = D_801CC944->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801CC940->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801CC940->unk4) / D_801CC940->frames;
                break;
            case 4:
                D_801CC940->frames = func_801B2004(&p->script);
                sv->vx = *p->script++ - D_801CC940->pos.vx;
                sv->vy = *p->script++ - D_801CC940->pos.vy;
                sv->vz = *p->script++ - D_801CC940->pos.vz;
                D_801CC940->unk18.vx = ((sv->vx - D_801CC940->vel.vx * D_801CC940->frames) * 2) / (D_801CC940->frames * D_801CC940->frames);
                D_801CC940->unk18.vy = ((sv->vy - D_801CC940->vel.vy * D_801CC940->frames) * 2) / (D_801CC940->frames * D_801CC940->frames);
                D_801CC940->unk18.vz = ((sv->vz - D_801CC940->vel.vz * D_801CC940->frames) * 2) / (D_801CC940->frames * D_801CC940->frames);
                break;
            case 5:
                D_801CC940->frames = func_801B2004(&p->script);
                D_801CC940->unk28 = *p->script++;
                D_801CC940->unk4 = 0;
                D_801CC940->unk8 = 0x1000 / D_801CC940->frames;
                D_801CC940->unk18.vx = D_801CC940->pos.vx;
                D_801CC940->unk18.vy = D_801CC940->pos.vy;
                D_801CC940->unk18.vz = D_801CC940->pos.vz;
                D_801CC940->vel.vx = *p->script++ - D_801CC940->pos.vx;
                D_801CC940->vel.vy = *p->script++ - D_801CC940->pos.vy;
                D_801CC940->vel.vz = *p->script++ - D_801CC940->pos.vz;
                break;
            case 6:
                if ((D_801CC940->actor = *p->script++) == 0) {
                    D_801CC940->actor = p->actor;
                }
                op = D_801CC940->part = *p->script++;
                func_801B2138(D_801CC940->actor, (s16)op, (MgTask *)p->mat, sv);
                D_801CC940->pos.vx -= sv->vx;
                D_801CC940->pos.vy -= sv->vy;
                D_801CC940->pos.vz -= sv->vz;
                break;
            case 7:
                func_801B2138(D_801CC940->actor, D_801CC940->part, (MgTask *)p->mat, sv);
                D_801CC940->pos.vx += sv->vx;
                D_801CC940->pos.vy += sv->vy;
                D_801CC940->pos.vz += sv->vz;
                D_801CC940->actor = -1;
                break;
            case 0:
            case 9:
                D_801CC940->frames = func_801B2004(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801CC940 = &D_801CC8E8;
        D_801CC944 = &D_801CC914;
        for (i = 0; i < 2; i++) {
            switch (D_801CC940->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801CC940->vel.vx += D_801CC940->unk18.vx;
                D_801CC940->vel.vy += D_801CC940->unk18.vy;
                D_801CC940->vel.vz += D_801CC940->unk18.vz;
            case 2:
                D_801CC940->pos.vx += D_801CC940->vel.vx;
                D_801CC940->pos.vy += D_801CC940->vel.vy;
                D_801CC940->pos.vz += D_801CC940->vel.vz;
                break;
            case 3:
                D_801CC940->unk18.vx += D_801CC940->vel.vx;
                D_801CC940->unk18.vy += D_801CC940->vel.vy;
                D_801CC940->unk18.vz += D_801CC940->vel.vz;
                D_801CC940->unk4 += D_801CC940->unk8;
                vec->vx = D_801CC944->pos.vx - D_801CC940->unk18.vx;
                vec->vy = D_801CC944->pos.vy - D_801CC940->unk18.vy;
                vec->vz = D_801CC944->pos.vz - D_801CC940->unk18.vz;
                func_8003A078(vec, sv);
                D_801CC940->pos.vx = D_801CC944->pos.vx - ((sv->vx * D_801CC940->unk4) >> 12);
                D_801CC940->pos.vy = D_801CC944->pos.vy - ((sv->vy * D_801CC940->unk4) >> 12);
                D_801CC940->pos.vz = D_801CC944->pos.vz - ((sv->vz * D_801CC940->unk4) >> 12);
                break;
            case 5:
                D_801CC940->unk4 += D_801CC940->unk8;
                k = func_801B2040(D_801CC940->unk4, D_801CC940->unk28);
                D_801CC940->pos.vx = D_801CC940->unk18.vx + ((D_801CC940->vel.vx * k) >> 12);
                D_801CC940->pos.vy = D_801CC940->unk18.vy + ((D_801CC940->vel.vy * k) >> 12);
                D_801CC940->pos.vz = D_801CC940->unk18.vz + ((D_801CC940->vel.vz * k) >> 12);
                break;
            }
            cam = D_801CC940;
            D_801CC940 = &D_801CC914;
            D_801CC944 = &D_801CC8E8;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801CC8E8.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801CC8E8.actor == -1) {
                func_8003BC6C(&D_801CC8E8.pos, vec, &flag);
            } else {
                func_801B2138(D_801CC8E8.actor, D_801CC8E8.part, (MgTask *)p->mat, sv);
                sv->vx += D_801CC8E8.pos.vx;
                sv->vy += D_801CC8E8.pos.vy;
                sv->vz += D_801CC8E8.pos.vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
                func_8003BC6C(sv, vec, &flag);
            }
            D_80158D00.vx = vec->vx;
            D_80158D00.vy = vec->vy;
            D_80158D00.vz = vec->vz;
        }
        if (D_801CC914.mode != 9) {
            if (D_801CC914.actor == -1) {
                func_8003BC6C(&D_801CC914.pos, vec, &flag);
            } else {
                func_801B2138(D_801CC914.actor, D_801CC914.part, (MgTask *)p->mat, sv);
                sv->vx += D_801CC914.pos.vx;
                sv->vy += D_801CC914.pos.vy;
                sv->vz += D_801CC914.pos.vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
                func_8003BC6C(sv, vec, &flag);
            }
            D_801031E8.vx = vec->vx;
            D_801031E8.vy = vec->vy;
            D_801031E8.vz = vec->vz;
        }
    } else {
        if (D_801CC8E8.mode != 9) {
            D_80158D00 = D_801CC8E8.pos;
        }
        if (D_801CC914.mode != 9) {
            D_801031E8 = D_801CC914.pos;
        }
    }
}

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

void func_801B34BC(MgSVec *arg0, s16 arg1, s16 arg2) {
    func_801B31F0(arg0, arg2, -0x3E8);
    D_801CC7BC[0] = arg1;
    D_80163C74 = func_800D4D90(&D_801CC7BC[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
}

void func_801B3524(void) {
    MgTask *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    func_801B34BC((MgSVec *)&p->unk4, p->unk2, p->unkC);
    if (D_80062D98 == 0) {
        t = (u16)p->unk2 + 1;
        p->unk2 = t;
        if (t >= D_801CC54C[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B35B0(void) {
    MgMat sp10;

    func_8003A63C(&D_801CC7C0, &D_801CC7E0, &sp10);
    func_801B1CA8(&sp10, &D_801CC800);
}

void func_801B35F0(void) {
    MgMat m;
    MgVec v;
    s32 flag;
    MgTask *p;
    u8 *b;
    s32 n;
    s32 r;
    s32 k;

    func_8003BF8C(&D_801CC810, &m);
    func_8003B35C(&m, &D_801CC818);
    m.t[0] = 0x3E8;
    m.t[1] = 0;
    m.t[2] = 0;
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801CC808 += 0x300;
    b = D_801C4980;
    while (D_801CC808 >= 0x100) {
        r = func_80042DA8() % 341;
        for (n = 0; n < 341; n++) {
            k = (r + n) % 341 * 8;
            if (*(s16 *)(D_801CC94A + k) > 0) {
                p = &D_80162978[func_800BBEAC(&func_801B3524)];
                func_8003BC6C((MgSVec *)(b + k), &v, &flag);
                p->unk4 = v.vx;
                p->unk6 = v.vy;
                p->unk8 = v.vz;
                if (D_801CC80C != 0) {
                    p->unk4 = -p->unk4;
                }
                D_801CC80C ^= 1;
                p->unkC = func_80042DA8() % 0x800 + 0x1800;
                break;
            }
        }
        D_801CC808 -= 0x100;
    }
}

void func_801B37F8(void) {
    MgMat m;
    MgTask *p;
    s16 *r;
    s32 *w;
    s32 t;
    s32 i;
    s32 j;
    s32 f;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x1C) {
            f = (t << 12) / 0x1C;
            j = t / 4;
            i = j;
            j = t - i * 4;
            if (j == 0) {
                func_801B1EAC(&D_801C497C, D_801CC83C[i], D_801CC948);
            }
            func_801B1F3C(&D_801C497C, D_801CC83C[i], D_801CC948, ((j + 1) << 12) / 4);
            D_801CC832 = 0x1000 - f;
            /* identical arms: the dead test keeps t, i and j live across the call (saved registers) */
            if (t + i + j) {
                func_801B35F0();
            } else {
                func_801B35F0();
            }
        } else {
            t -= 0x1C;
            if (t >= 0x2D) {
                p->unk0 = -1;
                return;
            }
            D_801CC832 = 0;
        }
        p->unk2++;
    }
    func_8003B69C(0x80, 0x80, 0x80);
    r = &D_801CC85A;
    *r = 0x80;
    func_8003C21C((MgSVec *)(r - 1), &m);
    func_8003B35C(&m, (M2C_UNK *)&D_801CC860);
    m.t[0] = -0x3E8;
    m.t[1] = 0;
    m.t[2] = 0;
    func_8003A63C(&D_801CD3F0, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    w = &D_801CC82C;
    *w |= 1;
    D_80163C74 = func_800D29D4(w - 1, D_801517C0 + 0x70, 0xC, D_80163C74);
    *r = -0x80;
    func_8003C21C((MgSVec *)(r - 1), &m);
    func_8003B35C(&m, (M2C_UNK *)&D_801CC860);
    m.t[0] = 0x3E8;
    m.t[1] = 0;
    m.t[2] = 0;
    func_8003A63C(&D_801CD3F0, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    *w &= -2;
    D_80163C74 = func_801B0B40(w - 1, D_801517C0 + 0x70, 0xC, D_80163C74);
}

s32 func_801B3AB0(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    StDesc d;
    MgMat m;
    u8 *a;
    s32 t;
    s32 i;

    a = D_801518E4[arg0];
    for (i = 0; i < *(s16 *)(a + 0x10); i++) {
        if (*(s32 *)(a + i * 4 + 0x78) != 0) {
            func_800D41FC(&D_800FA63C, a + (i * 0x34 + 0x174), &m);
            t = *(s32 *)(a + i * 4 + 0x78);
            d.unk4 = 0x80;
            d.unk8 = 0;
            d.unkA = 0;
            d.unkC = 0x20;
            d.unk0 = t;
            d.unkE = *(u16 *)(a + 0x16);
            arg3 = func_801B165C((M2C_UNK *)&d, arg1, arg2, arg3, &m, &D_800FA63C);
        }
    }
    return arg3;
}

s32 func_801B3BEC(u16 *arg0, s32 arg1) {
    MgTask *p;
    s32 a;
    s32 k;

    while (arg1 >= 0x100) {
        a = func_80042DA8() & 0xFFF;
        k = func_80042DA8() % 500 + 0x12C;
        p = &D_80162978[func_800BBEAC(&func_801B3524)];
        p->unk4 = arg0[0] + (func_80039A74(a) * k >> 12);
        p->unk6 = 0;
        p->unk8 = arg0[2] + (func_80039B40(a) * k >> 12);
        p->unkC = func_80042DA8() % 0x800 + 0x1800;
        arg1 -= 0x100;
    }
    return arg1;
}

void func_801B3D20(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_80151A4E[p->unk0][0] = 0x1388;
            p->unk2++;
            return;
        }
        if (p->unk2 < 0xF) {
            D_80151A4E[p->unk0][0] = (u16)D_80151A4E[p->unk0][0] - 0x14D;
            if (p->unk2 == 0xE) {
                D_80151909[p->unk0][0] &= 0xFB;
                D_80151A4E[p->unk0][0] = 0;
            }
            D_801CC874 += 0x100;
            D_801CC874 = func_801B3BEC((u16 *)D_80151A4C[p->unk0], D_801CC874);
        } else {
            p->unk0 = -1;
        }
        p->unk2++;
    }
    D_80163C74 = func_801B3AB0(p->unk0, D_801517C0 + 0x70, 0xC, D_80163C74);
}

void func_801B3F1C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_80151909[p->unk0][0] |= 4;
            p->unk2++;
            return;
        }
        if (p->unk2 < 0x1E) {
            D_80151A4E[p->unk0][0] = (u16)D_80151A4E[p->unk0][0] + 0xA6;
            D_801CC878 += 0x100;
            D_801CC878 = func_801B3BEC((u16 *)D_80151A4C[p->unk0], D_801CC878);
        } else {
            p->unk0 = -1;
        }
        p->unk2++;
    }
    D_80163C74 = func_801B3AB0(p->unk0, D_801517C0 + 0x70, 0xC, D_80163C74);
}

void func_801B40A0(s16 arg0) {
    D_80162978[func_800BBEAC(&func_801B3D20)].unk0 = arg0;
}

void func_801B40E4(s16 arg0) {
    D_80162978[func_800BBEAC(&func_801B3F1C)].unk0 = arg0;
}

void func_801B4128(void) {
    MgTask *p;
    MgTask *q;
    s16 t;
    s32 a;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        D_801CC87C += 0x200;
        while (D_801CC87C >= 0x100) {
            a = func_80042DA8() & 0xFFF;
            k = func_80042DA8() % 500 + 0x1F4;
            q = &D_80162978[func_800BBEAC(&func_801B3524)];
            q->unk4 = p->unk4 + (func_80039A74(a) * k >> 12);
            q->unk6 = 0;
            q->unk8 = p->unk8 + (func_80039B40(a) * k >> 12);
            q->unkC = func_80042DA8() % 0x1000 + 0x1800;
            D_801CC87C -= 0x100;
        }
        t = (u16)p->unk2 + 1;
        p->unk2 = t;
        if (t >= 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B42C4(void) {
    MgTask *p;
    MgTask *q;
    s16 t;
    s32 a;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        D_801CC880 += 0x100;
        while (D_801CC880 >= 0x100) {
            a = func_80042DA8() & 0xFFF;
            k = func_80042DA8() % 500 + 0x1F4;
            q = &D_80162978[func_800BBEAC(&func_801B3524)];
            q->unk4 = p->unk4 + (func_80039A74(a) * k >> 12);
            q->unk6 = 0;
            q->unk8 = p->unk8 + (func_80039B40(a) * k >> 12);
            q->unkC = func_80042DA8() % 0x1000 + 0x1800;
            D_801CC880 -= 0x100;
        }
        t = (u16)p->unk2 + 1;
        p->unk2 = t;
        if (t >= 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B4460(void) {
    MgTask *p;
    MgTask *q;
    s32 t;

    p = &D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801CC6D0, &D_801CD3F0);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t <= 0) {
            if (t == 0) {
                func_801B35B0();
            }
        } else if ((t -= 1) < 10) {
            if (t == 0) {
                func_801B3448(0x32, 0, 0xA, 0);
                q = &D_80162978[func_800BBEAC(&func_801B4128)];
                q->unk4 = 0x9C4;
                q->unk8 = -0xDAC;
                q = &D_80162978[func_800BBEAC(&func_801B4128)];
                q->unk4 = -0x9C4;
                q->unk8 = -0xDAC;
                func_800D55F4(0x20, 0x40, 0x14C);
            }
        } else if ((t -= 10) < 0x1C) {
            if (t == 0) {
                func_800BBEAC(&func_801B37F8);
                func_801B3448(0x14, 0, 0x1C, 0xF);
            }
        } else if ((t -= 0x1C) < 0xF) {
            if (t == 0) {
                func_800D5444(0x60, 0, 0, func_801B40A0);
                func_800D55F4(0x20, 0x40, 0x152);
            }
        } else if ((t -= 0xF) >= 0x1E) {
            p->unk0 = -1;
            D_800FAFDC = 0;
            D_80163B3C = 1;
            return;
        }
        p->unk2++;
    }
}

void func_801B4640(void) {
    MgTask *p;
    MgTask *q;

    p = &D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801CC6D0, &D_801CD3F0);
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_801B3448(0x14, 0, 0x1E, 0xA);
            q = &D_80162978[func_800BBEAC(&func_801B42C4)];
            q->unk4 = 0x9C4;
            q->unk8 = -0xDAC;
            q = &D_80162978[func_800BBEAC(&func_801B42C4)];
            q->unk4 = -0x9C4;
            q->unk8 = -0xDAC;
            func_800D5444(0x60, 0, 0, func_801B40E4);
            func_800D55F4(0x20, 0x40, 0x278);
        }
        if (p->unk2 >= 0x2E) {
            p->unk0 = -1;
            return;
        }
        p->unk2 += 1;
    }
}

void func_801B4770(arg0, arg1) {
    func_800D2980(&D_801B485C, 0, 0, 0);
    func_8003C21C(&D_801CC6F0, &D_801CC6D0);
    func_80042DA8();
    ((void (*)(s32, s32, s32))func_801B318C)((s32)&D_801CC740, (s32)&D_801CC6D0, arg1);
    func_800BBEAC(&func_801B4460);
    D_800FAFDC = 1;
}

void func_801B4804(void) {
    func_800D2980(&D_801B485C, 0, 0, 0);
    func_8003C21C(&D_801CC6F0, &D_801CC6D0);
    func_800BBEAC(&func_801B4640);
}
