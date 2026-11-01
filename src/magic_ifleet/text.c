#include "common.h"
#include "magic_ifleet/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B3BB0();
    return &D_801DD188;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F0482[-v];
    }
    return v;
}

s32 func_801B00A4(s32 t, s32 s) {
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

void func_801B0194(void) {
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
            D_801F02EC.actor = -1;
            D_801F0318.actor = -1;
            D_801F02EC.frames = 0;
            D_801F0318.frames = 0;
            p->unk2 = 1;
        }
        while (D_801F02EC.frames == 0 || D_801F0318.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801F0344 = &D_801F02EC;
                D_801F0348 = &D_801F0318;
            } else {
                D_801F0344 = &D_801F0318;
                D_801F0348 = &D_801F02EC;
            }
            D_801F0344->mode = op & 0xFF3F;
            switch (D_801F0344->mode) {
            case 1:
                D_801F0344->pos.vx = *p->script++;
                D_801F0344->pos.vy = *p->script++;
                D_801F0344->pos.vz = *p->script++;
                break;
            case 2:
                D_801F0344->frames = func_801B0068(&p->script);
                D_801F0344->vel.vx = (*p->script++ - D_801F0344->pos.vx) / D_801F0344->frames;
                D_801F0344->vel.vy = (*p->script++ - D_801F0344->pos.vy) / D_801F0344->frames;
                D_801F0344->vel.vz = (*p->script++ - D_801F0344->pos.vz) / D_801F0344->frames;
                break;
            case 3:
                sv->vx = D_801F0348->pos.vx - D_801F0344->pos.vx;
                sv->vy = D_801F0348->pos.vy - D_801F0344->pos.vy;
                sv->vz = D_801F0348->pos.vz - D_801F0344->pos.vz;
                D_801F0344->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801F0344->unk18 = D_801F0344->pos;
                D_801F0344->frames = func_801B0068(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801F0344->vel.vx = (sv->vx - D_801F0344->pos.vx) / D_801F0344->frames;
                D_801F0344->vel.vy = (sv->vy - D_801F0344->pos.vy) / D_801F0344->frames;
                D_801F0344->vel.vz = (sv->vz - D_801F0344->pos.vz) / D_801F0344->frames;
                if (D_801F0348->mode == 2) {
                    sv2->vx = D_801F0348->pos.vx + D_801F0348->vel.vx * D_801F0348->frames;
                    sv2->vy = D_801F0348->pos.vy + D_801F0348->vel.vy * D_801F0348->frames;
                    sv2->vz = D_801F0348->pos.vz + D_801F0348->vel.vz * D_801F0348->frames;
                } else {
                    sv2->vx = D_801F0348->pos.vx;
                    sv2->vy = D_801F0348->pos.vy;
                    sv2->vz = D_801F0348->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801F0344->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801F0344->unk4) / D_801F0344->frames;
                break;
            case 4:
                D_801F0344->frames = func_801B0068(&p->script);
                sv->vx = *p->script++ - D_801F0344->pos.vx;
                sv->vy = *p->script++ - D_801F0344->pos.vy;
                sv->vz = *p->script++ - D_801F0344->pos.vz;
                D_801F0344->unk18.vx = ((sv->vx - D_801F0344->vel.vx * D_801F0344->frames) * 2) / (D_801F0344->frames * D_801F0344->frames);
                D_801F0344->unk18.vy = ((sv->vy - D_801F0344->vel.vy * D_801F0344->frames) * 2) / (D_801F0344->frames * D_801F0344->frames);
                D_801F0344->unk18.vz = ((sv->vz - D_801F0344->vel.vz * D_801F0344->frames) * 2) / (D_801F0344->frames * D_801F0344->frames);
                break;
            case 5:
                D_801F0344->frames = func_801B0068(&p->script);
                D_801F0344->unk28 = *p->script++;
                D_801F0344->unk4 = 0;
                D_801F0344->unk8 = 0x1000 / D_801F0344->frames;
                D_801F0344->unk18.vx = D_801F0344->pos.vx;
                D_801F0344->unk18.vy = D_801F0344->pos.vy;
                D_801F0344->unk18.vz = D_801F0344->pos.vz;
                D_801F0344->vel.vx = *p->script++ - D_801F0344->pos.vx;
                D_801F0344->vel.vy = *p->script++ - D_801F0344->pos.vy;
                D_801F0344->vel.vz = *p->script++ - D_801F0344->pos.vz;
                break;
            case 6:
                if ((D_801F0344->actor = *p->script++) == 0) {
                    D_801F0344->actor = p->actor;
                }
                D_801F0344->part = *p->script++;
                break;
            case 7:
                D_801F0344->actor = -1;
                break;
            case 0:
            case 9:
                D_801F0344->frames = func_801B0068(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801F0344 = &D_801F02EC;
        D_801F0348 = &D_801F0318;
        for (i = 0; i < 2; i++) {
            switch (D_801F0344->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801F0344->vel.vx += D_801F0344->unk18.vx;
                D_801F0344->vel.vy += D_801F0344->unk18.vy;
                D_801F0344->vel.vz += D_801F0344->unk18.vz;
            case 2:
                D_801F0344->pos.vx += D_801F0344->vel.vx;
                D_801F0344->pos.vy += D_801F0344->vel.vy;
                D_801F0344->pos.vz += D_801F0344->vel.vz;
                break;
            case 3:
                D_801F0344->unk18.vx += D_801F0344->vel.vx;
                D_801F0344->unk18.vy += D_801F0344->vel.vy;
                D_801F0344->unk18.vz += D_801F0344->vel.vz;
                D_801F0344->unk4 += D_801F0344->unk8;
                vec->vx = D_801F0348->pos.vx - D_801F0344->unk18.vx;
                vec->vy = D_801F0348->pos.vy - D_801F0344->unk18.vy;
                vec->vz = D_801F0348->pos.vz - D_801F0344->unk18.vz;
                func_8003A078(vec, sv);
                D_801F0344->pos.vx = D_801F0348->pos.vx - ((sv->vx * D_801F0344->unk4) >> 12);
                D_801F0344->pos.vy = D_801F0348->pos.vy - ((sv->vy * D_801F0344->unk4) >> 12);
                D_801F0344->pos.vz = D_801F0348->pos.vz - ((sv->vz * D_801F0344->unk4) >> 12);
                break;
            case 5:
                D_801F0344->unk4 += D_801F0344->unk8;
                k = func_801B00A4(D_801F0344->unk4, D_801F0344->unk28);
                D_801F0344->pos.vx = D_801F0344->unk18.vx + ((D_801F0344->vel.vx * k) >> 12);
                D_801F0344->pos.vy = D_801F0344->unk18.vy + ((D_801F0344->vel.vy * k) >> 12);
                D_801F0344->pos.vz = D_801F0344->unk18.vz + ((D_801F0344->vel.vz * k) >> 12);
                break;
            }
            cam = D_801F0344;
            D_801F0344 = &D_801F0318;
            D_801F0348 = &D_801F02EC;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801F02EC.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801F02EC.actor == -1) {
                func_8003BC6C(&D_801F02EC.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801F02EC.pos, vec);
                if (D_801F02EC.part != -1) {
                    func_800D3994(D_801F02EC.actor, D_801F02EC.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801F02EC.actor].vx;
                    sv->vy = D_80151A4C[D_801F02EC.actor].vy;
                    sv->vz = D_80151A4C[D_801F02EC.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801F0318.mode != 9) {
            if (D_801F0318.actor == -1) {
                func_8003BC6C(&D_801F0318.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801F0318.pos, vec);
                if (D_801F0318.part != -1) {
                    func_800D3994(D_801F0318.actor, D_801F0318.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801F0318.actor].vx;
                    sv->vy = D_80151A4C[D_801F0318.actor].vy;
                    sv->vz = D_80151A4C[D_801F0318.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801F02EC.mode != 9) {
            D_80158D00 = D_801F02EC.pos;
        }
        if (D_801F0318.mode != 9) {
            D_801031E8 = D_801F0318.pos;
        }
    }
}

void func_801B11BC(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B0194)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

MgMat *func_801B1220(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801F00A8.m[0][0] = D_801F00A8.m[1][1] = D_801F00A8.m[2][2] = scale;
    func_8003B48C(&D_801F0450);
    func_8003B51C(&D_801F0450);
    func_8003BC6C(v, (MgVec *)D_801F00A8.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801F00A8.t, &n);
        D_801F00A8.t[0] += (dist * n.vx) >> 12;
        D_801F00A8.t[1] += (dist * n.vy) >> 12;
        D_801F00A8.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801F00A8);
    func_8003B51C(&D_801F00A8);
    return &D_801F00A8;
}

void func_801B133C(void) {
    s32 otz;
    s32 flag;
    MgTask *p;
    u8 *pkt;
    s32 n;

    pkt = D_80163C74;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    n = func_8003BBDC(&p->unk4, pkt + 8, &otz, &flag);
    if (*(u16 *)(pkt + 8) < 0x140U && *(u16 *)(pkt + 0xA) < 0xA6U) {
        if (!(flag & 0x60000)) {
            func_800469B0(pkt);
            pkt[4] = 0xFF;
            pkt[5] = func_80042DA8();
            pkt[6] = 0;
            *(s16 *)(pkt + 0xC) = 2;
            *(s16 *)(pkt + 0xE) = 2;
            func_80046794((n >> 2) * 4 + (D_801517C0 + 0x70), pkt);
            D_80163C74 = pkt + 0x10;
        }
        if (D_80062D98 == 0) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unkC = p->unkC * 7 >> 3;
            p->unkE = p->unkE * 7 >> 3;
            p->unk10 = p->unk10 * 7 >> 3;
            if (--p->unk2 == 0) {
                goto kill;
            }
        }
    } else {
kill:
        p->unk0 = -1;
    }
}

void func_801B14E8(void) {
    MgTask *p;
    s32 t;
    s32 u;
    s16 k;
    s32 i;
    MgSVec *a;
    MgSVec *b;
    MgSVec *d;
    u8 *s;

    p = (MgTask *)&D_80162978[D_8015169C];
    s = (u8 *)0x1F800000;
    t = p->unk2;
    if (t < 10) {
        k = (t << 12) / 10;
        D_801F00E8.m[0][0] = D_801F00E8.m[1][1] = D_801F00E8.m[2][2] = k;
    } else if ((t -= 10) < 0x1E) {
        k = 0x1000;
        D_801F00E8.m[0][0] = D_801F00E8.m[1][1] = D_801F00E8.m[2][2] = k;
    } else {
        p->unk0 = -1;
        return;
    }
    func_8003A63C((MgMat *)D_801F0430, (u8 *)&D_801F00E8, (s32)s);
    func_8003A63C(&D_800FA63C, s, (s32)s);
    func_8003B48C((MgMat *)s);
    func_8003B51C((MgMat *)s);
    D_80163C74 = func_800D29D4(&D_801F00C8, D_801517C0 + 0x70, 0xC, D_80163C74);
    D_80163C74 = func_800D29D4(&D_801F00D8, D_801517C0 + 0x406C, 0, D_80163C74);
    func_800D4484(D_801517C0 + 0x406C, 0x40);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x24) {
            if ((t & 3) == 0) {
                u = t;
                i = 0;
                if (u < 0) {
                    u += 3;
                }
                a = D_801D4290;
                b = D_801F0108[u >> 2];
                d = D_801EFEC4;
                do {
                    d[i].vx = (b->vx - a->vx) / 4;
                    d[i].vy = (b->vy - a->vy) / 4;
                    d[i].vz = (b->vz - a->vz) / 4;
                    b++;
                    a++;
                    i++;
                } while (i < 0xCA);
            }
            a = D_801D4290;
            i = 0;
            d = D_801EFEC4;
            do {
                a->vx += d[i].vx;
                a->vy += d[i].vy;
                a->vz += d[i].vz;
                a++;
                i++;
            } while (i < 0xCA);
        }
        p->unk2++;
    }
}

void func_801B1798(void) {
    MgTask *p;
    s32 t;
    s16 v;
    u8 *s;

    p = (MgTask *)&D_80162978[D_8015169C];
    s = (u8 *)0x1F800000;
    t = p->unk2;
    if (t < 10) {
        D_801F0136 = 0;
        v = (t << 11) / 10 + 0x2000;
        D_801F013C.m[0][0] = D_801F013C.m[2][2] = v;
        D_801F013C.m[1][1] = t * 0x3000 / 10;
    } else {
        t -= 10;
        if (t < 5) {
            D_801F013C.m[0][0] = D_801F013C.m[2][2] = 0x2800;
            D_801F013C.m[1][1] = 0x3000;
            D_801F0136 = (t << 12) / 5;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003A63C((MgMat *)D_801F0430, (u8 *)&D_801F013C, (s32)s);
    func_8003A63C(&D_800FA63C, s, (s32)s);
    func_8003B48C((MgMat *)s);
    func_8003B51C((MgMat *)s);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801F012C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1958(void) {
    MgTask *p;
    MgMat *m;
    MgVec *v1;
    MgVec *v2;
    s16 *f;
    s16 *r;
    s32 y;
    s32 t;
    s32 u;
    s32 w;
    s32 h;

    v1 = (MgVec *)0x1F800020;
    v2 = (MgVec *)0x1F800030;
    p = (MgTask *)&D_80162978[D_8015169C];
    m = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 0x1E) {
        v1->vx = *(s32 *)0x1F800024 = *(s32 *)0x1F800028 = 0x1A00;
        v2->vx = *(s32 *)0x1F800034 = *(s32 *)0x1F800038 = 0x1C00;
        D_801F0166 = 0;
        y = -(t * 0x7D0) / 30 - 0x4B0;
    } else {
        t -= 0x1E;
        if (t < 0x32) {
            u = t * 0x5000 / 50 + 0x1000;
            *(s32 *)0x1F800024 = u * 0x1A00 >> 12;
            v2->vx = u * 0x1C00 >> 12;
            h = (t << 12) / 50;
            w = h + 0x1000;
            v1->vx = *(s32 *)0x1F800028 = w * 0x1A00 >> 12;
            *(s32 *)0x1F800034 = *(s32 *)0x1F800038 = w * 0x1C00 >> 12;
            D_801F0166 = h;
            y = -0xC80;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003B69C(0, 0, 0);
    f = &D_801F016E;
    r = f - 1;
    *f = p->unk2 * 0x40;
    func_8003C21C((M2C_UNK *)r, (M2C_UNK *)m);
    func_8003AD14(m, v1);
    m->t[0] = 0;
    m->t[1] = y;
    m->t[2] = 0;
    func_8003A63C(&D_801F0450, (u8 *)m, (s32)m);
    func_8003B48C(m);
    func_8003B51C(m);
    D_80163C74 = func_800D29D4(&D_801F015C, D_801517C0 + 0x70, 0xC, D_80163C74);
    *f = p->unk2 * 0x40;
    func_8003C21C((M2C_UNK *)r, (M2C_UNK *)m);
    func_8003AD14(m, v2);
    m->t[0] = 0;
    m->t[1] = y;
    m->t[2] = 0;
    func_8003A63C(&D_801F0450, (u8 *)m, (s32)m);
    func_8003B48C(m);
    func_8003B51C(m);
    D_80163C74 = func_800D29D4(&D_801F015C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1C88(void) {
    MgTask *p;
    s32 t;
    s16 v;
    u8 *s;

    p = (MgTask *)&D_80162978[D_8015169C];
    s = (u8 *)0x1F800000;
    t = p->unk2;
    if (t < 5) {
        D_801F017E = 0;
    } else {
        t -= 5;
        if (t < 5) {
            D_801F017E = (t << 12) / 5;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    v = (p->unkC - 0x300) * p->unk2 / 10 + 0x300;
    D_801F0184.m[0][0] = D_801F0184.m[1][1] = v;
    D_801F0184.m[2][2] = (p->unkE - 0x300) * p->unk2 / 10 + 0x300;
    D_801F0184.t[0] = p->unk4;
    D_801F0184.t[1] = p->unk6;
    D_801F0184.t[2] = p->unk8;
    func_8003A63C(&D_801F0450, (u8 *)&D_801F0184, (s32)s);
    func_8003B48C((MgMat *)s);
    func_8003B51C((MgMat *)s);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801F0174, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1E58(void) {
    MgTask *p;
    MgTask *q;
    MgSVec *sv;
    MgVec *vec;
    MgSVec *e;
    s16 *g;
    s32 i;
    s32 t;
    s32 flag;

    sv = (MgSVec *)0x1F800040;
    vec = (MgVec *)0x1F800048;
    i = 0x1F800000;
    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t >= 0x14) {
        p->unk0 = -1;
        return;
    }
    D_801F01D0 = t * 0x5DC - 0x1388;
    g = &D_801F01C4;
    *g = -(t * 0x1500 / 20 + 0x300);
    func_8003A63C((MgMat *)D_801F0430, (u8 *)g - 0x10, 0x1F800000);
    func_8003A63C(&D_800FA63C, (u8 *)0x1F800000, 0x1F800020);
    func_8003B48C((MgMat *)0x1F800020);
    func_8003B51C((MgMat *)0x1F800020);
    D_80163C74 = func_800D29D4(&D_801F01A4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        if (!(p->unk2 & 1)) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B1C88)];
            *(s16 *)((u8 *)q + 4) = D_801F01C8;
            *(s16 *)((u8 *)q + 6) = D_801F01CC;
            *(s16 *)((u8 *)q + 8) = D_801F01D0 - 0x3E8;
            q->unkC = func_80042DA8() % 0x100 + 0x300;
            q->unkE = func_80042DA8() % 0x200 + 0x400;
        }
        func_8003B48C((MgMat *)i);
        func_8003B51C((MgMat *)i);
        i = 0;
        do {
            i++;
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B133C)];
            e = D_801D9860;
            e = e + func_80042DA8() % 137;
            func_8003BC6C(e, vec, &flag);
            q->unk4 = vec->vx;
            q->unk6 = vec->vy;
            q->unk8 = vec->vz;
            sv->vx = (s16)(u16)e->vx / 2;
            sv->vy = (s16)(u16)e->vy / 2;
            sv->vz = func_80042DA8() % 50;
            func_8003ACE4(sv, vec);
            q->unkC = vec->vx;
            q->unkE = vec->vy;
            q->unk10 = vec->vz;
            q->unk2 = 0xF;
        } while (i < 0xF);
        p->unk2++;
    }
}

void func_801B21F4(void) {
    MgTask *p;
    s32 *t;
    s32 *f;
    s16 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = &D_801F0218;
    *t = p->unk4;
    D_801F021C.v = 0;
    D_801F0220.v = p->unk8;
    D_801F0210.v = p->unkC;
    D_801F020C.v = p->unkE;
    func_8003A63C(&D_801F0450, (u8 *)t - 0x14, 0x1F800000);
    func_8003B48C((MgMat *)0x1F800000);
    func_8003B51C((MgMat *)0x1F800000);
    k = p->unk2 % 9;
    f = &D_801F01D4;
    *f = D_801F01E0[k];
    D_80163C74 = func_800D4D90(f, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 9) {
            p->unk0 = -1;
        }
    }
}

void func_801B233C(void) {
    MgTask *p;
    MgTask *q;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B21F4)];
            q->unk4 = func_80042DA8() % 6000 - 0xBB8;
            q->unk8 = func_80042DA8() % 10000;
            q->unkC = func_80042DA8() % 0x1000 + 0x1800;
            q->unkE = func_80042DA8() % 0x1000 + 0x1800;
            i++;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 6) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B24C4);

void func_801B2E1C(void) {
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x1E) {
            D_801F0234.vy = -(t * 0x7D0) / 30;
        } else {
            t -= 0x1E;
            if (t >= 0x64) {
                t -= 0x64;
                if (t < 0xF) {
                    D_801F0234.vx = D_801F0234.vx;
                    D_801F0234.vy -= 0xA;
                    D_801F0234.vz -= 0x14;
                } else {
                    t -= 0xF;
                    if (t < 3) {
                        D_801F0234.vx = D_801F0234.vx;
                        D_801F0234.vy += 0x3E8;
                        D_801F0234.vz += 0x7D0;
                    } else {
                        t -= 3;
                        if (t >= 0x14) {
                            p->unk0 = -1;
                            return;
                        }
                        D_801F0234.vy = 0x1F4;
                        D_801F0234.vx = 0;
                        D_801F0234.vz = t * 0x5DC - 0x1388;
                    }
                }
            }
        }
        func_8003B48C((MgMat *)D_801F0430);
        func_8003B51C((MgMat *)D_801F0430);
        func_8003BC6C(&D_801F0234, D_801F023C, &D_801F023C[1].vx);
        D_80153D20[0] = D_801F023C->vx;
        D_80153D20[1] = D_801F023C->vy;
        D_80153D20[2] = D_801F023C->vz;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B301C);

void func_801B32A0(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        D_801F0296 = -(t << 12) / 10 + 0x1000;
    } else {
        t -= 10;
        if (t < 10) {
            D_801F0296 = (t << 12) / 10;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    t = (p->unk2 << 12) / 20;
    k = func_80039A74(t / 4);
    k = p->unk14 * ((k * 0x3000 >> 12) + 0x1000) >> 12;
    D_801F02BC->sx = D_801F02BC->sz = k;
    D_801F02BC->sy = p->unk14;
    func_8003C21C((M2C_UNK *)&p->unkC, (M2C_UNK *)&D_801F02BC->m);
    D_801F02BC->m.t[0] = p->unk4;
    D_801F02BC->m.t[1] = p->unk6;
    D_801F02BC->m.t[2] = p->unk8;
    func_8003B35C(&D_801F02BC->m, &D_801F02BC->sx);
    func_8003A63C(&D_801F0450, (u8 *)&D_801F02BC->m, (s32)&D_801F02BC->m);
    func_8003B48C(&D_801F02BC->m);
    func_8003B51C(&D_801F02BC->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801F028C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unkE += 0x80;
    }
}

void func_801B34AC(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk14, 0);
    D_801F02C8[0] = p->unk2;
    D_80163C74 = func_800D4D90((s32 *)(D_801F02C8 - 4), D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x10) {
            p->unk0 = -1;
            return;
        }
        func_8003B2CC((MgMat *)D_801F0430, &p->unkC, D_801F02CC);
        p->unk4 -= D_801F02CC->vx;
        p->unk6 += D_801F02CC->vy;
        p->unk8 -= D_801F02CC->vz;
        p->unkC = p->unkC * 15 >> 4;
        p->unkE = p->unkE * 15 >> 4;
        p->unk10 = (p->unk10 * 15 >> 4) + 5;
    }
}

void func_801B35FC(void) {
    MgTask *p;
    MgTask *q;
    MgTask *r;
    s32 t;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, D_801F0430, (s32)&D_801F0450);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 4) {
            if (t == 0) {
                func_800D52A0(0x400, 4);
                D_800F5B70 = 0x80;
                D_800F5B71 = 0;
                D_800F5B72 = 0;
            }
        } else {
            t -= 4;
            if (t < 10) {
                if (t == 0) {
                    func_800BBEAC(&func_801B14E8);
                    func_800D55F4(0x22, 0x40, 0x1AC, 0x1AD, 0x1AE);
                }
            } else {
                t -= 10;
                if (t < 10) {
                    if (t == 0) {
                        r = func_800D4FA8(1);
                        *(s16 *)((u8 *)r + 4) = D_801F0444;
                        *(s16 *)((u8 *)r + 6) = D_801F0448;
                        *(s16 *)((u8 *)r + 8) = D_801F044C;
                        *(s16 *)((u8 *)r + 0x10) = D_801EFECA ^ 0x800;
                        func_800BBEAC(&func_801B1798);
                        func_800BBEAC(&func_801B1958);
                        func_800BBEAC(&func_801B2E1C);
                    }
                } else {
                    t -= 10;
                    if (t >= 0x14) {
                        t -= 0x14;
                        if (t < 0x32) {
                            if (t == 0) {
                                func_800D55F4(0x22, 0x40, 0x1AF, 0x1B0, 0x1B1);
                            }
                            if (t < 5) {
                                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B32A0)];
                                q->unk4 = 0;
                                q->unk6 = func_80042DA8() % 1000 - 0xDAC;
                                q->unk8 = 0;
                                q->unkC = 0;
                                q->unkE = func_80042DA8() & 0xFFF;
                                q->unk10 = 0;
                                q->unk14 = func_80042DA8() % 0x80 + 0x180;
                            }
                        } else {
                            t -= 0x32;
                            if (t < 0x15) {
                                if (t == 0) {
                                    func_800D55F4(0x22, 0x40, 0x1B2, 0x1B3, 0x1B4);
                                }
                            } else {
                                t -= 0x15;
                                if (t < 0x1D) {
                                    func_800D41FC(&D_800FA63C, &D_80153E30, &D_801F02E8->m);
                                    func_8003B48C(&D_801F02E8->m);
                                    func_8003B51C(&D_801F02E8->m);
                                    i = 0;
                                    func_8003BC6C(&D_801F02E0, &D_801F02E8->v, &D_801F02E8->flag);
                                    do {
                                        q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B34AC)];
                                        q->unk4 = D_801F02E8->v.vx;
                                        q->unk6 = D_801F02E8->v.vy;
                                        q->unk8 = D_801F02E8->v.vz;
                                        q->unkC = D_801F02D0[i].vx + func_80042DA8() % 10 - 5;
                                        q->unkE = D_801F02D0[i].vy + func_80042DA8() % 10 - 5;
                                        q->unk10 = D_801F02D0[i].vz + func_80042DA8() % 10 - 5;
                                        q->unk14 = func_80042DA8() % 0x200 + 0x200;
                                        i++;
                                    } while (i < 2);
                                } else {
                                    t -= 0x1D;
                                    if (t < 0x12) {
                                        if (t == 0) {
                                            func_800BBEAC(&func_801B301C);
                                        }
                                    } else {
                                        t -= 0x12;
                                        if (t < 0x14) {
                                            if (t == 0) {
                                                func_800BBEAC(&func_801B1E58);
                                                func_800D55F4(0x22, 0x40, 0x1B5, 0x1B6, 0x1B7);
                                            }
                                        } else {
                                            t -= 0x14;
                                            if (t < 0xF) {
                                                if (t == 0) {
                                                    func_800BBEAC(&func_801B233C);
                                                    func_800D4FA8(2);
                                                }
                                            } else {
                                                t -= 0xF;
                                                if (t < 0xF) {
                                                    if (t == 0) {
                                                        i = 0;
                                                        do {
                                                            if (D_801F0480 >> i & 1) {
                                                                func_800D5774(i);
                                                            }
                                                            i++;
                                                        } while (i < 10);
                                                        func_800BBEAC(&func_801B24C4);
                                                    }
                                                } else {
                                                    func_800D52A0(0, 4);
                                                    D_800F8380 = 0;
                                                    p->unk0 = -1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        p->unk2++;
    }
}

void func_801B3BB0(arg0, arg1) {
    u8 *a;
    s32 t;
    s32 u;

    func_800D2980(D_801B3CF0, 0, 0, 0);
    D_801F0448 = 0;
    D_801F0444 = 0;
    D_801F0480 = arg0;
    func_800D54EC(arg0, 0x1F800000);
    t = *(s16 *)0x1F800004;
    if (t < D_80151A50[arg1][0]) {
        u = t + 0x1388;
        D_801F044C = u;
        D_801EFECA = 0x800;
    } else {
        u = t - 0x1388;
        D_801F044C = u;
    }
    func_8003C21C(D_801EFEC8, D_801F0430);
    func_800BBEAC(&func_801B35FC);
    u = func_80042DA8() & 0x100;
    a = D_801EFFB8;
    if (u) {
        a = D_801EFED0;
    }
    ((void (*)(s32, s32, s32))func_801B11BC)((s32)a, (s32)D_801F0430, arg1);
    D_800F8380 |= 8;
}
