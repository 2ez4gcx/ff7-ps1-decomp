#include "common.h"
#include "magic_phoenix/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B47DC();
    return &D_801DA084;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801EC976[-v];
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
            D_801EC880.actor = -1;
            D_801EC8AC.actor = -1;
            D_801EC880.frames = 0;
            D_801EC8AC.frames = 0;
            p->unk2 = 1;
        }
        while (D_801EC880.frames == 0 || D_801EC8AC.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801EC8D8 = &D_801EC880;
                D_801EC8DC = &D_801EC8AC;
            } else {
                D_801EC8D8 = &D_801EC8AC;
                D_801EC8DC = &D_801EC880;
            }
            D_801EC8D8->mode = op & 0xFF3F;
            switch (D_801EC8D8->mode) {
            case 1:
                D_801EC8D8->pos.vx = *p->script++;
                D_801EC8D8->pos.vy = *p->script++;
                D_801EC8D8->pos.vz = *p->script++;
                break;
            case 2:
                D_801EC8D8->frames = func_801B0068(&p->script);
                D_801EC8D8->vel.vx = (*p->script++ - D_801EC8D8->pos.vx) / D_801EC8D8->frames;
                D_801EC8D8->vel.vy = (*p->script++ - D_801EC8D8->pos.vy) / D_801EC8D8->frames;
                D_801EC8D8->vel.vz = (*p->script++ - D_801EC8D8->pos.vz) / D_801EC8D8->frames;
                break;
            case 3:
                sv->vx = D_801EC8DC->pos.vx - D_801EC8D8->pos.vx;
                sv->vy = D_801EC8DC->pos.vy - D_801EC8D8->pos.vy;
                sv->vz = D_801EC8DC->pos.vz - D_801EC8D8->pos.vz;
                D_801EC8D8->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801EC8D8->unk18 = D_801EC8D8->pos;
                D_801EC8D8->frames = func_801B0068(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801EC8D8->vel.vx = (sv->vx - D_801EC8D8->pos.vx) / D_801EC8D8->frames;
                D_801EC8D8->vel.vy = (sv->vy - D_801EC8D8->pos.vy) / D_801EC8D8->frames;
                D_801EC8D8->vel.vz = (sv->vz - D_801EC8D8->pos.vz) / D_801EC8D8->frames;
                if (D_801EC8DC->mode == 2) {
                    sv2->vx = D_801EC8DC->pos.vx + D_801EC8DC->vel.vx * D_801EC8DC->frames;
                    sv2->vy = D_801EC8DC->pos.vy + D_801EC8DC->vel.vy * D_801EC8DC->frames;
                    sv2->vz = D_801EC8DC->pos.vz + D_801EC8DC->vel.vz * D_801EC8DC->frames;
                } else {
                    sv2->vx = D_801EC8DC->pos.vx;
                    sv2->vy = D_801EC8DC->pos.vy;
                    sv2->vz = D_801EC8DC->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801EC8D8->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801EC8D8->unk4) / D_801EC8D8->frames;
                break;
            case 4:
                D_801EC8D8->frames = func_801B0068(&p->script);
                sv->vx = *p->script++ - D_801EC8D8->pos.vx;
                sv->vy = *p->script++ - D_801EC8D8->pos.vy;
                sv->vz = *p->script++ - D_801EC8D8->pos.vz;
                D_801EC8D8->unk18.vx = ((sv->vx - D_801EC8D8->vel.vx * D_801EC8D8->frames) * 2) / (D_801EC8D8->frames * D_801EC8D8->frames);
                D_801EC8D8->unk18.vy = ((sv->vy - D_801EC8D8->vel.vy * D_801EC8D8->frames) * 2) / (D_801EC8D8->frames * D_801EC8D8->frames);
                D_801EC8D8->unk18.vz = ((sv->vz - D_801EC8D8->vel.vz * D_801EC8D8->frames) * 2) / (D_801EC8D8->frames * D_801EC8D8->frames);
                break;
            case 5:
                D_801EC8D8->frames = func_801B0068(&p->script);
                D_801EC8D8->unk28 = *p->script++;
                D_801EC8D8->unk4 = 0;
                D_801EC8D8->unk8 = 0x1000 / D_801EC8D8->frames;
                D_801EC8D8->unk18.vx = D_801EC8D8->pos.vx;
                D_801EC8D8->unk18.vy = D_801EC8D8->pos.vy;
                D_801EC8D8->unk18.vz = D_801EC8D8->pos.vz;
                D_801EC8D8->vel.vx = *p->script++ - D_801EC8D8->pos.vx;
                D_801EC8D8->vel.vy = *p->script++ - D_801EC8D8->pos.vy;
                D_801EC8D8->vel.vz = *p->script++ - D_801EC8D8->pos.vz;
                break;
            case 6:
                if ((D_801EC8D8->actor = *p->script++) == 0) {
                    D_801EC8D8->actor = p->actor;
                }
                D_801EC8D8->part = *p->script++;
                break;
            case 7:
                D_801EC8D8->actor = -1;
                break;
            case 0:
            case 9:
                D_801EC8D8->frames = func_801B0068(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801EC8D8 = &D_801EC880;
        D_801EC8DC = &D_801EC8AC;
        for (i = 0; i < 2; i++) {
            switch (D_801EC8D8->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801EC8D8->vel.vx += D_801EC8D8->unk18.vx;
                D_801EC8D8->vel.vy += D_801EC8D8->unk18.vy;
                D_801EC8D8->vel.vz += D_801EC8D8->unk18.vz;
            case 2:
                D_801EC8D8->pos.vx += D_801EC8D8->vel.vx;
                D_801EC8D8->pos.vy += D_801EC8D8->vel.vy;
                D_801EC8D8->pos.vz += D_801EC8D8->vel.vz;
                break;
            case 3:
                D_801EC8D8->unk18.vx += D_801EC8D8->vel.vx;
                D_801EC8D8->unk18.vy += D_801EC8D8->vel.vy;
                D_801EC8D8->unk18.vz += D_801EC8D8->vel.vz;
                D_801EC8D8->unk4 += D_801EC8D8->unk8;
                vec->vx = D_801EC8DC->pos.vx - D_801EC8D8->unk18.vx;
                vec->vy = D_801EC8DC->pos.vy - D_801EC8D8->unk18.vy;
                vec->vz = D_801EC8DC->pos.vz - D_801EC8D8->unk18.vz;
                func_8003A078(vec, sv);
                D_801EC8D8->pos.vx = D_801EC8DC->pos.vx - ((sv->vx * D_801EC8D8->unk4) >> 12);
                D_801EC8D8->pos.vy = D_801EC8DC->pos.vy - ((sv->vy * D_801EC8D8->unk4) >> 12);
                D_801EC8D8->pos.vz = D_801EC8DC->pos.vz - ((sv->vz * D_801EC8D8->unk4) >> 12);
                break;
            case 5:
                D_801EC8D8->unk4 += D_801EC8D8->unk8;
                k = func_801B00A4(D_801EC8D8->unk4, D_801EC8D8->unk28);
                D_801EC8D8->pos.vx = D_801EC8D8->unk18.vx + ((D_801EC8D8->vel.vx * k) >> 12);
                D_801EC8D8->pos.vy = D_801EC8D8->unk18.vy + ((D_801EC8D8->vel.vy * k) >> 12);
                D_801EC8D8->pos.vz = D_801EC8D8->unk18.vz + ((D_801EC8D8->vel.vz * k) >> 12);
                break;
            }
            cam = D_801EC8D8;
            D_801EC8D8 = &D_801EC8AC;
            D_801EC8DC = &D_801EC880;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801EC880.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801EC880.actor == -1) {
                func_8003BC6C(&D_801EC880.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801EC880.pos, vec);
                if (D_801EC880.part != -1) {
                    func_800D3994(D_801EC880.actor, D_801EC880.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801EC880.actor].vx;
                    sv->vy = D_80151A4C[D_801EC880.actor].vy;
                    sv->vz = D_80151A4C[D_801EC880.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801EC8AC.mode != 9) {
            if (D_801EC8AC.actor == -1) {
                func_8003BC6C(&D_801EC8AC.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801EC8AC.pos, vec);
                if (D_801EC8AC.part != -1) {
                    func_800D3994(D_801EC8AC.actor, D_801EC8AC.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801EC8AC.actor].vx;
                    sv->vy = D_80151A4C[D_801EC8AC.actor].vy;
                    sv->vz = D_80151A4C[D_801EC8AC.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801EC880.mode != 9) {
            D_80158D00 = D_801EC880.pos;
        }
        if (D_801EC8AC.mode != 9) {
            D_801031E8 = D_801EC8AC.pos;
        }
    }
}

void func_801B11C8(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B0194)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B122C);

MgMat *func_801B179C(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EC6B4.m[0][0] = D_801EC6B4.m[1][1] = D_801EC6B4.m[2][2] = scale;
    func_8003B48C(&D_801EC954);
    func_8003B51C(&D_801EC954);
    func_8003BC6C(v, (MgVec *)D_801EC6B4.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EC6B4.t, &n);
        D_801EC6B4.t[0] += (dist * n.vx) >> 12;
        D_801EC6B4.t[1] += (dist * n.vy) >> 12;
        D_801EC6B4.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EC6B4);
    func_8003B51C(&D_801EC6B4);
    return &D_801EC6B4;
}

void func_801B18B8(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B179C((MgSVec *)&p->unk4, p->unk14, 0);
    D_801EC6DC[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801EC6DC[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D9FA0[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B1978(void) {
    MgTask *p;
    MgTask *q;
    s32 acc;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B179C((MgSVec *)&p->unk4, 0x400, 0);
    D_80163C74 = func_800D4D90(D_801EC6E0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        acc = (p->unk2 * 0xC0 & 0xFF) + 0xC0;
        if (acc >= 0x100) {
            do {
                acc -= 0x100;
                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B18B8)];
                q->unk4 = p->unk4 + func_80042DA8() % 400 - 0xC8;
                q->unk6 = p->unk6 + func_80042DA8() % 400 - 0xC8;
                q->unk8 = p->unk8 + func_80042DA8() % 400 - 0xC8;
                q->unk14 = 0x1000;
            } while (acc >= 0x100);
        }
        p->unk2++;
        if (p->unk2 >= 0x14) {
            p->unk0 = -1;
            return;
        }
        p->unk6 += p->unkE;
    }
}

void func_801B1B74(void) {
    MgTask *p;
    MgSVec *rot;
    MgVec *sc;
    MgMat *out;
    MgMat *m;
    s32 t;
    s32 v;
    M2C_UNK **fd;

    rot = (MgSVec *)0x1F800020;
    sc = (MgVec *)0x1F800028;
    out = (MgMat *)0x1F800038;
    p = (MgTask *)&D_80162978[D_8015169C];
    m = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 0x14) {
        D_801EC6F6 = 0;
        v = (t << 12) / 20;
        *(s32 *)0x1F800030 = v;
        *(s32 *)0x1F80002C = v;
        sc->vx = v;
    } else {
        t -= 0x14;
        if (t < 0) {
            *(s32 *)0x1F800030 = 0x1000;
            *(s32 *)0x1F80002C = 0x1000;
            sc->vx = 0x1000;
            D_801EC6F6 = 0;
        } else if (t < 0x2D) {
            v = (t << 11) / 45 + 0x1000;
            *(s32 *)0x1F800030 = v;
            *(s32 *)0x1F80002C = v;
            sc->vx = v;
            D_801EC6F6 = (t << 12) / 45;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    rot->vx = 0;
    rot->vy = p->unk2 * 0x80;
    rot->vz = 0;
    func_8003C21C(rot, m);
    func_8003B35C(m, sc);
    m->t[0] = p->unk4;
    m->t[1] = p->unk6;
    m->t[2] = p->unk8;
    func_8003A63C(&D_801EC954, m, out);
    func_8003B48C(out);
    func_8003B51C(out);
    func_8003B69C(0, 0, 0);
    fd = (M2C_UNK **)&D_801EC6EC;
    *fd = &D_801D49DC;
    D_80163C74 = func_800D29D4((M2C_UNK *)fd, D_801517C0 + 0x70, 0xC, D_80163C74);
    rot->vy = -(p->unk2 * 0x80);
    func_8003C21C(rot, m);
    func_8003B35C(m, sc);
    func_8003A79C(&D_801EC954, m, out);
    func_8003B48C(out);
    *fd = &D_801D5670;
    D_80163C74 = func_800D29D4((M2C_UNK *)fd, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1E40(void) {
    MgTask *p;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xA) {
        *(s32 *)&D_801EC700 = 0x2E808080;
    } else {
        t -= 0xA;
        if (t < 5) {
            c = -(t << 7) / 5 - 0x80;
            D_801EC700 = D_801EC701 = D_801EC702 = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_801B179C((MgSVec *)&p->unk4, p->unk14, 0);
    D_80163C74 = func_800D4D90(D_801EC6FC, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk6 += p->unkE;
        p->unkE = p->unkE * 13 >> 4;
    }
}

void func_801B1F80(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 ang;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            i++;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B1E40)];
            q->unk14 = func_80042DA8() % 1536 + 0x200;
            r = func_80042DA8() % 1000 + 0x1F4;
            ang = func_80042DA8();
            ang &= 0xFFF;
            q->unk4 = func_80039A74(ang) * r >> 12;
            q->unk6 = -0x1F4;
            q->unk8 = func_80039B40(ang) * r >> 12;
            q->unkE = -(func_80042DA8() % 500 + 0x1F4);
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 0x2D) {
            p->unk0 = -1;
        }
    }
}

void func_801B2138(void) {
    MgTask *p;
    MgMat *m;
    s32 *res;
    s32 *ext;
    s32 *flag;
    u8 *q;
    u8 *r;
    u8 *tab;
    s32 t;
    s32 i;
    s32 k;
    s32 w;
    s16 *h;
    s32 c;
    s32 a;

    res = (s32 *)0x1F800040;
    ext = (s32 *)0x1F800044;
    flag = (s32 *)0x1F800048;
    p = (MgTask *)&D_80162978[D_8015169C];
    m = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 5) {
        k = p->unk14 * t / 5;
        goto neg;
    }
    t -= 5;
    if (t < 0x1E) {
same:
        k = p->unk14;
        w = -k;
        goto common;
    }
    t -= 0x1E;
    if (t < 5) {
        if (D_80062D98 == 0) {
            p->unkC -= p->unk16;
        }
        goto same;
    }
    t -= 5;
    if (t < 5) {
        if (D_80062D98 == 0) {
            p->unkC -= p->unk16;
        }
        a = p->unk14;
        k = a + -a * t / 5;
        goto neg;
    }
    p->unk0 = -1;
    return;
neg:
    w = -k;
common:
    h = &D_801EC708;
    *h = D_801EC718 = w;
    D_801EC710 = D_801EC720 = k;
    func_8003C21C((MgSVec *)&p->unkC, m);
    m->t[0] = p->unk4;
    m->t[1] = p->unk6;
    m->t[2] = p->unk8;
    func_8003A63C(&D_801EC954, m, m);
    i = 0;
    func_8003B48C(m);
    func_8003B51C(m);
    q = (u8 *)D_80163C74;
    D_801EC712 = -0x3E8;
    D_801EC70A = -0x3E8;
    D_801EC722 = 0;
    D_801EC71A = 0;
    r = q + 0x14;
    tab = (u8 *)h;
    do {
        *res = func_8003BD7C(tab, tab + 8, tab + 0x10, tab + 0x18, q + 8, q + 0xC, q + 0x10, r, ext, flag);
        i++;
        if (!(*flag & 0x60000)) {
            *(s32 *)q = 0x05000000;
            *(s32 *)(r - 0x10) = 0x2A408080;
            func_80046794(D_801517C0 + 0x70 + (*res >> 2 << 2), q);
            r += 0x18;
            q += 0x18;
        }
        c = 0x3E8;
        D_801EC70A = (u16)D_801EC70A - c;
        D_801EC712 = (u16)D_801EC712 - c;
        D_801EC71A = (u16)D_801EC71A - c;
        D_801EC722 = (u16)D_801EC722 - c;
    } while (i < 8);
    D_80163C74 = (s32)q;
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B2490(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    u8 *c;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            i = 0x13;
            c = &D_801EC8F3;
            do {
                *c = 0;
                i--;
                c--;
            } while (i >= 0);
        }
        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B2138)];
        D_801EC72C = func_80042DA8() % 20;
        while (D_801EC8E0[D_801EC72C] != 0) {
            D_801EC72C = (D_801EC72C + 1) % 20;
        }
        D_801EC8E0[D_801EC72C] = 1;
        D_801EC72C = (D_801EC72C << 12) / 20 + func_80042DA8() % 153;
        q->unk4 = (u32)(func_80039A74(D_801EC72C) * 0x177) >> 10;
        q->unk6 = -0x1F4;
        q->unk8 = (u32)(func_80039B40(D_801EC72C) * 0x177) >> 10;
        q->unkC = 0;
        q->unk10 = 0;
        q->unkE = D_801EC72C;
        q->unk14 = func_80042DA8() % 250 + 0x32;
        q->unk16 = func_80042DA8() % 16 + 0x10;
        p->unk2++;
        if (p->unk2 >= 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B275C(void) {
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        D_801EC73A = -(t << 12) / 5 + 0x1000;
    } else {
        t -= 5;
        if (t < 5) {
            D_801EC73A = 0;
        } else {
            t -= 5;
            if (t < 5) {
                D_801EC73A = (t << 12) / 5;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    func_801B179C((MgSVec *)&p->unk4, p->unk2 * 0x300 / 15 + 0x800, -0x3E8);
    D_80163C74 = func_800D29D4(&D_801EC730, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B28D0(void) {
    MgTask *p;
    MgMat *m2;
    MgMat *m3;
    MgVec *vv;
    MgSVec *rot;
    MgMat *m;
    s32 t;
    s32 i;
    s32 v;
    s32 w;
    s16 k;

    m2 = (MgMat *)0x1F800020;
    m3 = (MgMat *)0x1F800040;
    vv = (MgVec *)0x1F800060;
    rot = (MgSVec *)0x1F800070;
    p = (MgTask *)&D_80162978[D_8015169C];
    m = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 0x32) {
        D_801EC75A = 0;
        D_801EC74A = 0;
    } else {
        t -= 0x32;
        if (t >= 0xF) {
            p->unk0 = -1;
            return;
        }
        v = (t << 12) / 15;
        D_801EC75A = v;
        D_801EC74A = v;
    }
    func_8003C21C(&D_801EC770, m3);
    m3->t[0] = 0;
    m3->t[1] = 0;
    m3->t[2] = 0;
    func_8003A63C(&D_801EC954, m3, m3);
    rot->vx = 0;
    rot->vy = 0x800;
    rot->vz = p->unk2 * 0x20;
    func_8003BF8C(rot, m);
    i = 1;
    m->t[0] = p->unk4;
    m->t[1] = p->unk6;
    m->t[2] = p->unk8;
    func_8003B35C(m, &D_801EC760);
    func_8003A63C(m3, m, m2);
    func_8003B48C(m2);
    func_8003B51C(m2);
    func_8003ACE4(&D_801EC778, vv);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4((M2C_UNK *)D_801EC740, D_801517C0 + 0xB18, 0, D_80163C74);
    do {
        m2->t[0] += vv->vx;
        m2->t[1] += vv->vy;
        m2->t[2] += vv->vz;
        func_8003B51C(m2);
        i++;
        D_80163C74 = func_800D29D4((M2C_UNK *)D_801EC740, D_801517C0 + 0xB18, 0, D_80163C74);
    } while (i < 4);
    rot->vz = p->unk2 * 0x20;
    func_8003BF8C(rot, m);
    m->t[0] = p->unkC;
    m->t[1] = p->unkE;
    m->t[2] = p->unk10;
    func_8003B35C(m, &D_801EC760);
    func_8003A63C(m3, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    D_80163C74 = func_800D29D4((M2C_UNK *)D_801EC750, D_801517C0 + 0xB18, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
    w = (u16)p->unk8;
    k = w + 0x3E8;
    p->unk8 = k;
    if (k >= 0x3A98) {
        p->unk8 = w - 0x2018;
    }
}

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B2C04);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B2F34);

void func_801B30D0(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801EC7A8, &D_801EC7B0->m);
    D_801EC7B0->m.t[0] = 0;
    D_801EC7B0->m.t[1] = -0xBB8;
    D_801EC7B0->m.t[2] = 0;
    func_8003B48C(&D_801EC7B0->m);
    func_8003B51C(&D_801EC7B0->m);
    func_8003BC6C((MgSVec *)&p->unk4, &D_801EC7B0->v, &D_801EC7B0->flag);
    D_801EC7B0->pos.vx = D_801EC7B0->v.vx;
    D_801EC7B0->pos.vy = D_801EC7B0->v.vy;
    D_801EC7B0->pos.vz = D_801EC7B0->v.vz;
    func_801B179C(&D_801EC7B0->pos, p->unk14, 0);
    D_80163C74 = func_800D4D90(D_801EC79C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
        p->unk8 += p->unk10;
    }
}

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B3210);

void func_801B3384(MgSVec *arg0, u16 *arg1) {
    s32 sp10;
    s32 sp14;
    s32 *t;
    s32 *t2;
    MgMat *m;
    MgWord *w;

    if (D_801EC54A == 0) {
        t = &D_801EC7D8;
        *t = -arg0->vx - D_801EC53C;
        D_801EC7DC.v = -arg0->vz - D_801EC544;
        D_801EC7E0.v = arg0->vy;
        m = (MgMat *)(t - 5);
    } else {
        t2 = &D_801EC7F8;
        *t2 = arg0->vx - D_801EC53C;
        D_801EC7FC.v = arg0->vz - D_801EC544;
        m = (MgMat *)(t2 - 5);
        D_801EC800.v = arg0->vy;
    }
    func_80044AC0((s32)D_801EC8F4, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801EC8F4);
    func_8003B64C(&sp10, &sp14);
    func_8003B6BC((s16)arg1[2] / 2, (s16)arg1[3] / 2);
    func_8003B48C(m);
    func_8003B51C(m);
    w = &D_801EC7B4;
    w->v = D_8016209C;
    D_80163C74 = func_801B122C((s32 *)w, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B6BC(sp10, sp14);
    D_801EC810.v = arg1[2];
    D_801EC812 = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)&D_801EC810 - 0xC));
    func_80044978(D_801EC934, arg1);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801EC934);
    D_801EC94C.v = arg1[0];
    D_801EC94E = arg1[1];
    func_800449FC(D_801EC940, &D_801EC94C);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801EC940);
}

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B35F8);

void func_801B3960(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 j;
    s32 o;
    s32 t;
    s16 c;
    s32 m;

    i = 0;
    do {
        c = 0;
        if (arg0 >= i) {
            t = arg0 - i;
            if (t < arg1) {
                m = -((t & 7) == 0);
                c = arg2 & m;
            }
        }
        j = 0xF;
        o = (i << 7) + 0x78;
loop:
        *(s16 *)(D_801EC98C + 2 + o) = c;
        j--;
        o -= 8;
        if (j >= 0) {
            goto loop;
        }
        i++;
    } while (i < 0x21);
}

void func_801B39D0(void) {
    MgTask *p;
    s32 t;
    s32 u;
    s32 i;
    s32 j;
    s32 r;
    s32 row;
    s32 off;
    MgVec v;
    s32 c;
    s32 q;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t >= 0x14) {
        u = t;
        t -= 0x14;
        if (t < 0x18) {
            func_801B3960(t * 2, 0x14, -(-(t * 0x96) / 24 + 0x96));
        } else if (t == 0x18) {
            p->unk2 = u + 1;
            return;
        } else {
            func_800D2980(&D_801B48FC, 0, 0, 0);
            p->unk0 = -1;
            return;
        }
    }
    func_8003B48C(&D_801EC954);
    func_8003B51C(&D_801EC954);
    i = 0;
    row = 0;
    do {
        j = 0;
        r = row;
        off = 0;
        do {
            c = off + (s32)D_801EDA0C;
            off += 0x60;
            t = 4;
            k = D_801EC814 * 0x28 + 0x10;
            q = r + c + k;
            c = c + r;
            func_8003BD7C(*(void **)c, *(void **)(c + t), *(void **)(c + 8), *(void **)(c + 12), (void *)(q + 8), (void *)(q + 0x10), (void *)(q + 0x18), (void *)(q + 0x20), &v.vx, &v.vy);
            j++;
        } while (j < 0x10);
        i++;
        row += 0x600;
    } while (i < 0x20);
    func_800467D0(D_801517C0 + 0x4078, D_801EC814 * 0x28 + (s32)D_801EDA0C + 0x10, D_801EC814 * 0x28 + (s32)D_801F99BC);
    D_801EC814 ^= 1;
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3C08(void) {
    MgObj20 *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x2D) {
            D_801EC552 = -(t * 0x5DC) / 45 - 0x3E8;
        } else {
            p->unk0 = -1;
        }
        p->unk2++;
        func_8003B48C(&D_801EC528);
        func_8003B51C(&D_801EC528);
        func_8003BC6C(&D_801EC550, D_801EC818, (s32 *)(D_801EC818 + 1));
        D_80153D20.v = D_801EC818->vx;
        D_80153D22.v = D_801EC818->vy;
        D_80153D24.v = D_801EC818->vz;
    }
}

void func_801B3D30(void) {
    MgTask *p;
    s32 t;
    s16 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x32) {
        D_801EC826 = 0;
    } else {
        t -= 0x32;
        if (t < 0xA) {
            D_801EC826 = (t << 12) / 10;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    c = (p->unk2 << 12) / 60 + 0x800;
    D_801EC82C.m[0][0] = D_801EC834 = c;
    func_8003B48C(&D_801EC954);
    func_8003B51C(&D_801EC954);
    D_801EC84C->pos.vx = D_801EC550.x;
    D_801EC84C->pos.vy = D_801EC550.y - 0x12C;
    D_801EC84C->pos.vz = D_801EC550.z;
    func_8003BC6C(&D_801EC84C->pos, &D_801EC84C->v, &D_801EC84C->flag);
    func_8003A08C(&D_801EC84C->v, &D_801EC84C->n);
    D_801EC840 = (*(s32 *)((u8 *)D_801EC84C + 0x18) * 0x3E8 >> 12) + *(s32 *)((u8 *)D_801EC84C + 8);
    D_801EC844 = (*(s32 *)((u8 *)D_801EC84C + 0x1C) * 0x3E8 >> 12) + *(s32 *)((u8 *)D_801EC84C + 0xC);
    D_801EC848 = (*(s32 *)((u8 *)D_801EC84C + 0x20) * 0x3E8 >> 12) + *(s32 *)((u8 *)D_801EC84C + 0x10);
    func_8003B48C(&D_801EC82C);
    func_8003B51C(&D_801EC82C);
    D_80163C74 = func_800D29D4(&D_801EC81C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3F84(void) {
    MgTask *p;
    MgPhElem *e;
    MgPhElem *f;
    s32 i;
    s32 j;
    s32 s;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        *(s32 *)&D_801EC854 = 0x2E808080;
        s = (t << 12) / 5;
    } else {
        t -= 5;
        if (t < 0x14) {
            *(s32 *)&D_801EC854 = 0x2E808080;
            s = 0x1000;
        } else {
            t -= 0x14;
            if (t >= 5) {
                p->unk0 = -1;
                return;
            }
            s = 0x1000;
            c = (-((t << 12) / 5 << 7) >> 12) - 0x80;
            D_801EC854 = D_801EC855 = D_801EC856 = c;
        }
    }
    i = 0;
    j = 0;
    do {
        e = (MgPhElem *)(D_801EC558 + j);
        func_801B179C((MgSVec *)e, (s * e->w * 0x10) >> 16, 0);
        D_80163C74 = func_800D4D90(D_801EC850, D_801517C0 + 0x70, 0xC, D_80163C74);
        i++;
        if (D_80062D98 == 0) {
            f = (MgPhElem *)(D_801EC558 + j);
            f->x += f->vx;
            f->y += f->vy;
            f->z += f->vz;
            f->vx = f->vx * 15 >> 4;
            f->vy = f->vy * 15 >> 4;
            f->vz = f->vz * 15 >> 4;
        }
        j += 0x14;
    } while (i < 100);
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B41C0);

s32 func_801B47DC(arg0, arg1) {
    MgSVec v;
    MgMat *mat;
    s32 t;

    func_800D2980(&D_801B48FC, 0, 0, 0);
    D_801EC974 = arg0;
    func_800D54EC(arg0, &v);
    t = v.vz;
    if (D_80151A4C[arg1].vz < t) {
        D_801EC544 = t - 0x1388;
    } else {
        D_801EC54A = 0x800;
        D_801EC544 = t + 0x1388;
    }
    mat = &D_801EC528;
    func_8003C21C(&D_801EC548, mat);
    if (func_80042DA8() & 0x100) {
        ((void (*)(s32, s32, s32))func_801B11C8)((s32)&D_801EC55C, (s32)mat, arg1);
    } else {
        ((void (*)(s32, s32, s32))func_801B11C8)((s32)&D_801EC608, (s32)mat, arg1);
    }
    func_800BBEAC((M2C_UNK *)func_801B41C0);
    D_800F8380 |= 8;
}
