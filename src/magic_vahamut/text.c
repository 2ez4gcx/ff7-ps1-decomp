#include "common.h"
#include "magic_vahamut/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B3AB8();
    return &D_801DB958;
}

MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EEEA0.m[0][0] = D_801EEEA0.m[1][1] = D_801EEEA0.m[2][2] = scale;
    func_8003B48C(&D_801EFC68);
    func_8003B51C(&D_801EFC68);
    func_8003BC6C(v, (MgVec *)D_801EEEA0.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EEEA0.t, &n);
        D_801EEEA0.t[0] += (dist * n.vx) >> 12;
        D_801EEEA0.t[1] += (dist * n.vy) >> 12;
        D_801EEEA0.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EEEA0);
    func_8003B51C(&D_801EEEA0);
    return &D_801EEEA0;
}

s32 func_801B0184(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801EFC8A[-v];
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
            D_801EF2FC.actor = -1;
            D_801EF328.actor = -1;
            D_801EF2FC.frames = 0;
            D_801EF328.frames = 0;
            p->unk2 = 1;
        }
        while (D_801EF2FC.frames == 0 || D_801EF328.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801EF354 = &D_801EF2FC;
                D_801EF358 = &D_801EF328;
            } else {
                D_801EF354 = &D_801EF328;
                D_801EF358 = &D_801EF2FC;
            }
            D_801EF354->mode = op & 0xFF3F;
            switch (D_801EF354->mode) {
            case 1:
                D_801EF354->pos.vx = *p->script++;
                D_801EF354->pos.vy = *p->script++;
                D_801EF354->pos.vz = *p->script++;
                break;
            case 2:
                D_801EF354->frames = func_801B0184(&p->script);
                D_801EF354->vel.vx = (*p->script++ - D_801EF354->pos.vx) / D_801EF354->frames;
                D_801EF354->vel.vy = (*p->script++ - D_801EF354->pos.vy) / D_801EF354->frames;
                D_801EF354->vel.vz = (*p->script++ - D_801EF354->pos.vz) / D_801EF354->frames;
                break;
            case 3:
                sv->vx = D_801EF358->pos.vx - D_801EF354->pos.vx;
                sv->vy = D_801EF358->pos.vy - D_801EF354->pos.vy;
                sv->vz = D_801EF358->pos.vz - D_801EF354->pos.vz;
                D_801EF354->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801EF354->unk18 = D_801EF354->pos;
                D_801EF354->frames = func_801B0184(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801EF354->vel.vx = (sv->vx - D_801EF354->pos.vx) / D_801EF354->frames;
                D_801EF354->vel.vy = (sv->vy - D_801EF354->pos.vy) / D_801EF354->frames;
                D_801EF354->vel.vz = (sv->vz - D_801EF354->pos.vz) / D_801EF354->frames;
                if (D_801EF358->mode == 2) {
                    sv2->vx = D_801EF358->pos.vx + D_801EF358->vel.vx * D_801EF358->frames;
                    sv2->vy = D_801EF358->pos.vy + D_801EF358->vel.vy * D_801EF358->frames;
                    sv2->vz = D_801EF358->pos.vz + D_801EF358->vel.vz * D_801EF358->frames;
                } else {
                    sv2->vx = D_801EF358->pos.vx;
                    sv2->vy = D_801EF358->pos.vy;
                    sv2->vz = D_801EF358->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801EF354->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801EF354->unk4) / D_801EF354->frames;
                break;
            case 4:
                D_801EF354->frames = func_801B0184(&p->script);
                sv->vx = *p->script++ - D_801EF354->pos.vx;
                sv->vy = *p->script++ - D_801EF354->pos.vy;
                sv->vz = *p->script++ - D_801EF354->pos.vz;
                D_801EF354->unk18.vx = ((sv->vx - D_801EF354->vel.vx * D_801EF354->frames) * 2) / (D_801EF354->frames * D_801EF354->frames);
                D_801EF354->unk18.vy = ((sv->vy - D_801EF354->vel.vy * D_801EF354->frames) * 2) / (D_801EF354->frames * D_801EF354->frames);
                D_801EF354->unk18.vz = ((sv->vz - D_801EF354->vel.vz * D_801EF354->frames) * 2) / (D_801EF354->frames * D_801EF354->frames);
                break;
            case 5:
                D_801EF354->frames = func_801B0184(&p->script);
                D_801EF354->unk28 = *p->script++;
                D_801EF354->unk4 = 0;
                D_801EF354->unk8 = 0x1000 / D_801EF354->frames;
                D_801EF354->unk18.vx = D_801EF354->pos.vx;
                D_801EF354->unk18.vy = D_801EF354->pos.vy;
                D_801EF354->unk18.vz = D_801EF354->pos.vz;
                D_801EF354->vel.vx = *p->script++ - D_801EF354->pos.vx;
                D_801EF354->vel.vy = *p->script++ - D_801EF354->pos.vy;
                D_801EF354->vel.vz = *p->script++ - D_801EF354->pos.vz;
                break;
            case 6:
                if ((D_801EF354->actor = *p->script++) == 0) {
                    D_801EF354->actor = p->actor;
                }
                D_801EF354->part = *p->script++;
                break;
            case 7:
                D_801EF354->actor = -1;
                break;
            case 0:
            case 9:
                D_801EF354->frames = func_801B0184(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801EF354 = &D_801EF2FC;
        D_801EF358 = &D_801EF328;
        for (i = 0; i < 2; i++) {
            switch (D_801EF354->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801EF354->vel.vx += D_801EF354->unk18.vx;
                D_801EF354->vel.vy += D_801EF354->unk18.vy;
                D_801EF354->vel.vz += D_801EF354->unk18.vz;
            case 2:
                D_801EF354->pos.vx += D_801EF354->vel.vx;
                D_801EF354->pos.vy += D_801EF354->vel.vy;
                D_801EF354->pos.vz += D_801EF354->vel.vz;
                break;
            case 3:
                D_801EF354->unk18.vx += D_801EF354->vel.vx;
                D_801EF354->unk18.vy += D_801EF354->vel.vy;
                D_801EF354->unk18.vz += D_801EF354->vel.vz;
                D_801EF354->unk4 += D_801EF354->unk8;
                vec->vx = D_801EF358->pos.vx - D_801EF354->unk18.vx;
                vec->vy = D_801EF358->pos.vy - D_801EF354->unk18.vy;
                vec->vz = D_801EF358->pos.vz - D_801EF354->unk18.vz;
                func_8003A078(vec, sv);
                D_801EF354->pos.vx = D_801EF358->pos.vx - ((sv->vx * D_801EF354->unk4) >> 12);
                D_801EF354->pos.vy = D_801EF358->pos.vy - ((sv->vy * D_801EF354->unk4) >> 12);
                D_801EF354->pos.vz = D_801EF358->pos.vz - ((sv->vz * D_801EF354->unk4) >> 12);
                break;
            case 5:
                D_801EF354->unk4 += D_801EF354->unk8;
                k = func_801B01C0(D_801EF354->unk4, D_801EF354->unk28);
                D_801EF354->pos.vx = D_801EF354->unk18.vx + ((D_801EF354->vel.vx * k) >> 12);
                D_801EF354->pos.vy = D_801EF354->unk18.vy + ((D_801EF354->vel.vy * k) >> 12);
                D_801EF354->pos.vz = D_801EF354->unk18.vz + ((D_801EF354->vel.vz * k) >> 12);
                break;
            }
            cam = D_801EF354;
            D_801EF354 = &D_801EF328;
            D_801EF358 = &D_801EF2FC;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801EF2FC.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801EF2FC.actor == -1) {
                func_8003BC6C(&D_801EF2FC.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801EF2FC.pos, vec);
                if (D_801EF2FC.part != -1) {
                    func_800D3994(D_801EF2FC.actor, D_801EF2FC.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801EF2FC.actor].vx;
                    sv->vy = D_80151A4C[D_801EF2FC.actor].vy;
                    sv->vz = D_80151A4C[D_801EF2FC.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801EF328.mode != 9) {
            if (D_801EF328.actor == -1) {
                func_8003BC6C(&D_801EF328.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801EF328.pos, vec);
                if (D_801EF328.part != -1) {
                    func_800D3994(D_801EF328.actor, D_801EF328.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801EF328.actor].vx;
                    sv->vy = D_80151A4C[D_801EF328.actor].vy;
                    sv->vz = D_80151A4C[D_801EF328.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801EF2FC.mode != 9) {
            D_80158D00 = D_801EF2FC.pos;
        }
        if (D_801EF328.mode != 9) {
            D_801031E8 = D_801EF328.pos;
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

void func_801B1348(void) {
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

void func_801B1484(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B1348)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

void func_801B14F8(void) {
    MgTask *p;
    s32 t;
    s32 c;
    M2C_UNK *a;
    u8 *s;
    s16 *q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    D_801EF35C = (u8 *)0x1F800000;
    if (t < 4) {
        c = t << 5;
    } else {
        t -= 4;
        if (t >= 4) {
            goto kill;
        }
        c = -(t << 7) / 4 - 0x80;
    }
    *(u8 *)0x1F800006 = c;
    *(u8 *)0x1F800005 = c;
    *(u8 *)0x1F800004 = c;
    goto draw;
kill:
    p->unk0 = -1;
    return;
draw:
    q = &p->unk4;
    a = &D_801D4018;
    s = D_801EF35C;
    if (p->unk0 == 0) {
        a = &D_801D3FF8;
    }
    s[7] = 0x2E;
    ((VhPtr *)s)->p = a;
    *(s16 *)(D_801EF35C + 8) = 0;
    func_800D4368(q, p->unk14, 0);
    D_80163C74 = func_800D4D90((s32 *)D_801EF35C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1634(void) {
    MgTask *p;
    MgTask *q;
    MgSVec *sv;
    MgVec *vec;
    s32 *flag;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        sv = (MgSVec *)0x1F800000;
        vec = (MgVec *)0x1F800008;
        flag = (s32 *)0x1F800018;
        func_8003B48C(&D_801EEE80);
        func_8003B51C(&D_801EEE80);
        i = 0;
        do {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B14F8)];
            sv->vx = func_80042DA8() % 2000 - 0x3E8;
            sv->vy = -0x4E20;
            sv->vz = func_80042DA8() % 2000 - 0x3E8;
            func_8003BC6C(sv, vec, flag);
            q->unk4 = (u16)vec->vx;
            q->unk6 = (u16)vec->vy;
            q->unk8 = (u16)vec->vz;
            q->unk14 = func_80042DA8() % 0x1000 + 0x1000;
            i++;
        } while (i < 2);
        p->unk2++;
        if (p->unk2 >= 0x29) {
            p->unk0 = -1;
        }
    }
}

void func_801B1804(void) {
    u8 *q;
    s32 i;
    s32 off;

    q = D_801D403C;
    for (i = 0; i < 0x121; i++) {
        off = i * 8;
        *(s16 *)(D_801EF360 + off) = (*(s16 *)(D_801D5D54 + off) - *(s16 *)(q + off)) / 40;
        *(s16 *)(D_801EF360 + off + 2) = (*(s16 *)(D_801D5D54 + off + 2) - *(s16 *)(q + off + 2)) / 40;
        *(s16 *)(D_801EF364 + off) = (*(s16 *)(D_801D5D58 + off) - *(s16 *)(q + off + 4)) / 40;
    }
}

void func_801B18F0(void) {
    MgTask *p;
    MgMat *m;
    MgMat *w;
    s32 *sc;
    s32 *f;
    s16 *r;
    s32 *fd;
    u8 *q;
    s32 t;
    s32 k;
    s32 i;
    s32 off;

    m = (MgMat *)0x1F800000;
    w = (MgMat *)0x1F800020;
    sc = (s32 *)0x1F800040;
    p = &D_80162978[D_8015169C];
    if (p->unk2 == 0) {
        func_801B1804();
    }
    t = p->unk2;
    if (t < 10) {
        k = 0x1000;
    } else {
        t -= 10;
        if (t < 0x19) {
            k = -(t << 12) / 25 + 0x1000;
        } else {
            t -= 0x19;
            if (t < 0x32) {
                D_801EF12E = 0;
                goto rest;
            }
            t -= 0x32;
            if (t >= 0x3C) {
                p->unk0 = -1;
                return;
            }
            k = (t << 12) / 60;
        }
    }
    D_801EF12E = k;
rest:
    r = &D_801EF136;
    f = (s32 *)((u8 *)r - 2);
    m->t[0] = 0;
    m->t[1] = -0x4E84;
    m->t[2] = 0;
    *r = p->unk2 * 0x10;
    func_8003C21C((MgSVec *)f, m);
    sc[0] = sc[1] = sc[2] = 0x2000;
    func_8003B35C(m, sc);
    func_8003A63C(&D_801EEE80, m, w);
    func_8003A63C(&D_800FA63C, w, w);
    func_8003B48C(w);
    func_8003B51C(w);
    fd = &D_801EF128;
    *fd = 0xA0;
    D_80163C74 = func_800D29D4((s32 *)((u8 *)fd - 4), D_801517C0 + 0x406C, 0, D_80163C74);
    m->t[1] = -0x4E20;
    *r = -(p->unk2 * 0x10);
    func_8003C21C((MgSVec *)f, m);
    sc[0] = sc[1] = sc[2] = 0x2000;
    func_8003B35C(m, sc);
    func_8003A63C(&D_801EFC68, m, w);
    func_8003B48C(w);
    func_8003B51C(w);
    *fd = 0xA8;
    D_80163C74 = func_800D29D4((s32 *)((u8 *)fd - 4), D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t >= 0x23) {
            t -= 0x23;
            if (t < 0x1E) {
                q = D_801D403C;
                for (i = 0; i < 0x121; i++) {
                    off = i * 8;
                    *(u16 *)(q + off) += *(u16 *)(D_801EF360 + off);
                    *(u16 *)(q + off + 2) += *(u16 *)(D_801EF360 + off + 2);
                    *(u16 *)(q + off + 4) += *(u16 *)(D_801EF364 + off);
                }
            }
        }
        p->unk2++;
    }
}

void func_801B1C48(void) {
    MgTask *p;
    s32 t;
    s32 a;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 4) {
        a = t * 0x580 + 0x200;
        D_801EF146 = 0;
        goto draw;
    }
    t -= 4;
    if (t < 4) {
        a = 0x1800;
        D_801EF146 = t << 10;
        goto draw;
    }
    p->unk0 = -1;
    return;
draw:
    func_801B0068((MgSVec *)&p->unk4, (a * p->unk14 * 0x10) >> 16, 0);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EF13C, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1D60(MgSVec *arg0, MgMat *arg1) {
    MgSVec rot;

    rot.vx = 0;
    rot.vy = arg0->vy;
    rot.vz = 0;
    func_8003C21C(&rot, arg1);
    func_8003C73C(arg0->vx, arg1);
    func_8003CA7C(arg0->vz, arg1);
}

void func_801B1DC0(void) {
    MgTask *p;
    MgMat *m;
    s32 *sc;
    s32 t;

    m = (MgMat *)0x1F800000;
    sc = (s32 *)0x1F800020;
    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        D_801EF156 = 0;
        goto draw;
    }
    t -= 10;
    if (t < 5) {
        D_801EF156 = (t << 12) / 5;
        goto draw;
    }
    p->unk0 = -1;
    return;
draw:
    sc[0] = sc[1] = sc[2] = p->unk14;
    func_801B1D60((MgSVec *)&p->unkC, m);
    m->t[0] = p->unk4;
    m->t[1] = p->unk6;
    m->t[2] = p->unk8;
    func_8003B35C(m, sc);
    func_8003A63C(&D_801EEE80, m, m);
    func_8003A63C(&D_800FA63C, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EF14C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        p->unk16 = (p->unk16 * 0xF) >> 4;
        p->unk2++;
    }
}

void func_801B1F70(void) {
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xF) {
        func_8003B69C(0xFF, 0x80, 0);
        D_801EF166 = -(t << 12) / 15 + 0x1000;
        goto draw;
    }
    t -= 0xF;
    if (t < 0xA) {
        func_8003B69C(0, 0, 0);
        D_801EF166 = (t << 12) / 10;
        goto draw;
    }
    p->unk0 = -1;
    return;
draw:
    func_801B1D60((MgSVec *)&p->unkC, &D_801EF16C->m);
    D_801EF16C->m.t[0] = p->unk4;
    D_801EF16C->m.t[1] = p->unk6;
    D_801EF16C->m.t[2] = p->unk8;
    D_801EF16C->sc[0] = D_801EF16C->sc[1] = D_801EF16C->sc[2] = p->unk14;
    func_8003B35C(&D_801EF16C->m, D_801EF16C->sc);
    func_8003A63C(&D_801EFC68, &D_801EF16C->m, &D_801EF16C->m);
    func_8003B48C(&D_801EF16C->m);
    func_8003B51C(&D_801EF16C->m);
    D_80163C74 = func_800D29D4(&D_801EF15C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        p->unk16 = (p->unk16 * 0xF) >> 4;
        p->unk2++;
        p->unkE += 0x40;
    }
}

void func_801B2170(void) {
    MgTask *p;
    s32 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk14, -0x100);
    frame = &D_801EF1B0;
    *frame = D_801EF170[p->unk2];
    D_80163C74 = func_800D4D90(frame, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x10) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2238);

void func_801B2464(void) {
    MgTask *p;
    s32 t;
    s16 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x19) {
        k = t * 0x180 / 25;
        D_801EF1C6 = 0;
        goto draw;
    }
    t -= 0x19;
    k = 0x180;
    if (t < 5) {
        D_801EF1C6 = 0;
        goto draw;
    }
    t -= 5;
    if (t < 5) {
        k = t * 0xE80 / 5 + 0x180;
        D_801EF1C6 = (t << 12) / 5;
        goto draw;
    }
    p->unk0 = -1;
    return;
draw:
    func_801B0068(&D_801DB950, k, 0);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EF1BC, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B25E4);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2810);

void func_801B2970(void) {
    MgTask *p;
    MgMat *m;
    s32 t;
    s32 k;
    s32 *q;
    s16 *f;
    s16 *g;

    p = &D_80162978[D_8015169C];
    t = (p->unk2 << 12) / 55;
    k = ((D_80153D22[0] + 0x6B6C) << 12) / 2000;
    q = &D_801EF21C;
    if (k > 0x7FFF) {
        k = 0x7FFF;
    }
    f = &D_801EF1F2;
    *q = k;
    *f = p->unk2 * 0x80;
    m = (MgMat *)0x1F800000;
    func_8003C21C((MgSVec *)((u8 *)f - 2), m);
    func_8003B35C(m, q - 1);
    m->t[0] = D_80153D20;
    m->t[1] = D_80153D22[0] + 0x7D0;
    m->t[2] = D_80153D24;
    func_8003A63C(&D_800FA63C, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    func_8003B69C(0, 0, 0);
    g = &D_801EF1DA;
    *g = t;
    D_80163C74 = func_800D29D4((u8 *)g - 0xA, D_801517C0 + 0x70, 0xC, D_80163C74);
    func_8003A79C(&D_801EFC68, &D_801EF1F8, m);
    func_8003B48C(m);
    if (D_801EF228 != 0) {
        D_801EF1EA = t;
    } else {
        D_801EF1EA = t + (((0x1000 - t) << 8) >> 12);
    }
    D_801EF228 ^= 1;
    D_80163C74 = func_800D29D4(&D_801EF1E0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x37) {
            p->unk0 = -1;
        }
        p->unk6 += p->unkE;
        func_8003C8DC(-0xA0, &D_801EF1F8);
    }
}

void func_801B2BEC(void) {
    MgTask *p;
    s32 t;
    s32 k;
    s32 *f;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        D_801EF236 = 0;
        goto draw;
    }
    t -= 5;
    if (t < 5) {
        D_801EF236 = (t << 12) / 5;
        goto draw;
    }
    p->unk0 = -1;
    return;
draw:
    func_8003A63C(&D_801EFC68, *(MgMat **)((u8 *)p + 0x18), &D_801EF25C->m);
    f = &D_801EF258;
    *f = -p->unk8;
    func_8003A63C(&D_801EF25C->m, (MgMat *)((u8 *)f - 0x1C), &D_801EF25C->m);
    k = func_801B01C0((p->unk2 << 12) / 10, 0x3FF) * 0x1200 >> 12;
    D_801EF25C->sc[0] = D_801EF25C->sc[1] = D_801EF25C->sc[2] = k;
    func_8003B35C(&D_801EF25C->m, D_801EF25C->sc);
    func_8003B48C(&D_801EF25C->m);
    func_8003B51C(&D_801EF25C->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EF22C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2DA8);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B31D8);

void func_801B37F8(void) {
    MgTask *p;
    MgTask *q;
    u8 *b;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    b = (u8 *)&D_80153BB8;
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t >= 0x54) {
            t -= 0x54;
            if (t < 0x3C) {
                if (t == 0) {
                    q = func_800D4FA8(1);
                    func_8003B2CC(&D_801EEE80, &D_801EF2F0, D_801EF2F8);
                    *(s16 *)((u8 *)q + 4) = ((u16 *)D_801EF2F8)[0] + D_801EEE94;
                    *(s16 *)((u8 *)q + 6) = ((u16 *)D_801EF2F8)[1] + D_801EEE98;
                    *(s16 *)((u8 *)q + 8) = ((u16 *)D_801EF2F8)[2] + (u16)D_801EEE9C;
                    *(s16 *)((u8 *)q + 0x10) = D_801EEE7A + 0x800;
                    D_80153BBE = 0xC00;
                }
                k = func_801B01C0((t << 12) / 60, 0x280);
                D_801EF2F2 = (k * 0x5BCC >> 12) - 0x6B6C;
            } else {
                t -= 0x3C;
                if (t < 0x41) {
                    k = func_801B01C0((t << 12) / 65, -0x1FF);
                    D_801EF2F2 = (-(k * 0xBB8) >> 12) - 0xFA0;
                } else {
                    t -= 0x41;
                    if (t < 0x69) {
                        if (t == 0) {
                            D_801EF2F2 = -0x1B58;
                        }
                        if (t == 0x68) {
                            func_800D4FA8(2);
                            p->unk0 = -1;
                        }
                    }
                }
            }
        }
        func_8003B2CC(&D_801EEE80, &D_801EF2F0, D_801EF2F8);
        *(s16 *)(b + 0x168) = ((u16 *)D_801EF2F8)[0] + D_801EEE94;
        *(s16 *)(b + 0x16A) = ((u16 *)D_801EF2F8)[1] + D_801EEE98;
        *(s16 *)(b + 0x16C) = ((u16 *)D_801EF2F8)[2] + (u16)D_801EEE9C;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B3AB8);
