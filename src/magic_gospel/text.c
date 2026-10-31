#include "common.h"
#include "magic_gospel/decls.h"

M2C_UNK *func_801B0048(void) {
    func_801B3914();
    return &D_801DDCE4;
}

MgMat *func_801B0070(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801E0628.m[0][0] = D_801E0628.m[1][1] = D_801E0628.m[2][2] = scale;
    func_8003B48C(&D_801E0988);
    func_8003B51C(&D_801E0988);
    func_8003BC6C(v, (MgVec *)D_801E0628.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801E0628.t, &n);
        D_801E0628.t[0] += (dist * n.vx) >> 12;
        D_801E0628.t[1] += (dist * n.vy) >> 12;
        D_801E0628.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801E0628);
    func_8003B51C(&D_801E0628);
    return &D_801E0628;
}

s32 func_801B018C(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801E09AA[-v];
    }
    return v;
}

void func_801B01C8(void) {
    MgCamTask *p;
    MgSVec *sv;
    MgSVec *sv2;
    MgVec *vec;
    s32 i;
    u16 op;
    s32 k;
    s32 j;
    MgCam *cam;
    u8 pad[0x100];
    s32 flag;

    sv2 = (MgSVec *)0x1F800008;
    vec = (MgVec *)0x1F800010;
    p = (MgCamTask *)&D_80162978[D_8015169C];
    sv = (MgSVec *)0x1F800000;
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801E091C.actor = -1;
            D_801E0948.actor = -1;
            D_801E091C.frames = 0;
            D_801E0948.frames = 0;
            p->unk2 = 1;
        }
        while (D_801E091C.frames == 0 || D_801E0948.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801E0974 = &D_801E091C;
                D_801E0978 = &D_801E0948;
            } else {
                D_801E0974 = &D_801E0948;
                D_801E0978 = &D_801E091C;
            }
            D_801E0974->mode = op & 0xFF3F;
            switch (D_801E0974->mode) {
            case 1:
                D_801E0974->pos.vx = *p->script++;
                D_801E0974->pos.vy = *p->script++;
                D_801E0974->pos.vz = *p->script++;
                break;
            case 2:
                D_801E0974->frames = func_801B018C(&p->script);
                D_801E0974->vel.vx = (*p->script++ - D_801E0974->pos.vx) / D_801E0974->frames;
                D_801E0974->vel.vy = (*p->script++ - D_801E0974->pos.vy) / D_801E0974->frames;
                D_801E0974->vel.vz = (*p->script++ - D_801E0974->pos.vz) / D_801E0974->frames;
                break;
            case 3:
                sv->vx = D_801E0978->pos.vx - D_801E0974->pos.vx;
                sv->vy = D_801E0978->pos.vy - D_801E0974->pos.vy;
                sv->vz = D_801E0978->pos.vz - D_801E0974->pos.vz;
                D_801E0974->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801E0974->unk18 = D_801E0974->pos;
                D_801E0974->frames = func_801B018C(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801E0974->vel.vx = (sv->vx - D_801E0974->pos.vx) / D_801E0974->frames;
                D_801E0974->vel.vy = (sv->vy - D_801E0974->pos.vy) / D_801E0974->frames;
                D_801E0974->vel.vz = (sv->vz - D_801E0974->pos.vz) / D_801E0974->frames;
                if (D_801E0978->mode == 2) {
                    sv2->vx = D_801E0978->pos.vx + D_801E0978->vel.vx * D_801E0978->frames;
                    sv2->vy = D_801E0978->pos.vy + D_801E0978->vel.vy * D_801E0978->frames;
                    sv2->vz = D_801E0978->pos.vz + D_801E0978->vel.vz * D_801E0978->frames;
                } else {
                    sv2->vx = D_801E0978->pos.vx;
                    sv2->vy = D_801E0978->pos.vy;
                    sv2->vz = D_801E0978->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801E0974->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801E0974->unk4) / D_801E0974->frames;
                break;
            case 4:
                D_801E0974->frames = func_801B018C(&p->script);
                sv->vx = *p->script++ - D_801E0974->pos.vx;
                sv->vy = *p->script++ - D_801E0974->pos.vy;
                sv->vz = *p->script++ - D_801E0974->pos.vz;
                D_801E0974->unk18.vx = ((sv->vx - D_801E0974->vel.vx * D_801E0974->frames) * 2) / (D_801E0974->frames * D_801E0974->frames);
                D_801E0974->unk18.vy = ((sv->vy - D_801E0974->vel.vy * D_801E0974->frames) * 2) / (D_801E0974->frames * D_801E0974->frames);
                D_801E0974->unk18.vz = ((sv->vz - D_801E0974->vel.vz * D_801E0974->frames) * 2) / (D_801E0974->frames * D_801E0974->frames);
                break;
            case 5:
                D_801E0974->frames = func_801B018C(&p->script);
                D_801E0974->unk28 = *p->script++;
                D_801E0974->unk4 = 0;
                D_801E0974->unk8 = 0x1000 / D_801E0974->frames;
                D_801E0974->unk18.vx = D_801E0974->pos.vx;
                D_801E0974->unk18.vy = D_801E0974->pos.vy;
                D_801E0974->unk18.vz = D_801E0974->pos.vz;
                D_801E0974->vel.vx = *p->script++ - D_801E0974->pos.vx;
                D_801E0974->vel.vy = *p->script++ - D_801E0974->pos.vy;
                D_801E0974->vel.vz = *p->script++ - D_801E0974->pos.vz;
                break;
            case 6:
                if ((D_801E0974->actor = *p->script++) == 0) {
                    D_801E0974->actor = p->actor;
                }
                D_801E0974->part = *p->script++;
                break;
            case 7:
                D_801E0974->actor = -1;
                break;
            case 0:
            case 8:
                D_801E0974->frames = func_801B018C(&p->script);
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801E0974 = &D_801E091C;
        D_801E0978 = &D_801E0948;
        for (i = 0; i < 2; i++) {
            switch (D_801E0974->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801E0974->vel.vx += D_801E0974->unk18.vx;
                D_801E0974->vel.vy += D_801E0974->unk18.vy;
                D_801E0974->vel.vz += D_801E0974->unk18.vz;
            case 2:
                D_801E0974->pos.vx += D_801E0974->vel.vx;
                D_801E0974->pos.vy += D_801E0974->vel.vy;
                D_801E0974->pos.vz += D_801E0974->vel.vz;
                break;
            case 3:
                D_801E0974->unk18.vx += D_801E0974->vel.vx;
                D_801E0974->unk18.vy += D_801E0974->vel.vy;
                D_801E0974->unk18.vz += D_801E0974->vel.vz;
                D_801E0974->unk4 += D_801E0974->unk8;
                vec->vx = D_801E0978->pos.vx - D_801E0974->unk18.vx;
                vec->vy = D_801E0978->pos.vy - D_801E0974->unk18.vy;
                vec->vz = D_801E0978->pos.vz - D_801E0974->unk18.vz;
                func_8003A078(vec, sv);
                D_801E0974->pos.vx = D_801E0978->pos.vx - ((sv->vx * D_801E0974->unk4) >> 12);
                D_801E0974->pos.vy = D_801E0978->pos.vy - ((sv->vy * D_801E0974->unk4) >> 12);
                D_801E0974->pos.vz = D_801E0978->pos.vz - ((sv->vz * D_801E0974->unk4) >> 12);
                break;
            case 5:
                D_801E0974->unk4 += D_801E0974->unk8;
                k = D_801E0974->unk4;
                for (j = 0; j < D_801E0974->unk28; j++) {
                    k = func_80039A74(k / 4);
                }
                D_801E0974->pos.vx = D_801E0974->unk18.vx + ((D_801E0974->vel.vx * k) >> 12);
                D_801E0974->pos.vy = D_801E0974->unk18.vy + ((D_801E0974->vel.vy * k) >> 12);
                D_801E0974->pos.vz = D_801E0974->unk18.vz + ((D_801E0974->vel.vz * k) >> 12);
                break;
            }
            cam = D_801E0974;
            D_801E0974 = &D_801E0948;
            D_801E0978 = &D_801E091C;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801E091C.mode != 8) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801E091C.actor == -1) {
                func_8003BC6C(&D_801E091C.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801E091C.pos, vec);
                if (D_801E091C.part != -1) {
                    func_800D3994(D_801E091C.actor, D_801E091C.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801E091C.actor].vx;
                    sv->vy = D_80151A4C[D_801E091C.actor].vy;
                    sv->vz = D_80151A4C[D_801E091C.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801E0948.mode != 8) {
            if (D_801E0948.actor == -1) {
                func_8003BC6C(&D_801E0948.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801E0948.pos, vec);
                if (D_801E0948.part != -1) {
                    func_800D3994(D_801E0948.actor, D_801E0948.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801E0948.actor].vx;
                    sv->vy = D_80151A4C[D_801E0948.actor].vy;
                    sv->vz = D_80151A4C[D_801E0948.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801E091C.mode != 8) {
            D_80158D00 = D_801E091C.pos;
        }
        if (D_801E0948.mode != 8) {
            D_801031E8 = D_801E0948.pos;
        }
    }
}

void func_801B120C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B01C8)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B1270(void) {
    s32 *p;
    s32 i;

    i = 299;
    p = &D_801E25DC;
    for (; i >= 0; i--) {
        *p-- = 0;
    }
}

GosPart *func_801B1294(s32 arg0) {
    s32 i;

    for (i = 0; i < 300; i++) {
        if (D_801E2130[i] == 0) {
            D_801E2130[i] = arg0;
            D_801E09C0[i].unk0 = 0;
            D_801E09C0[i].unk2 = 0;
            return &D_801E09C0[i];
        }
    }
    return 0;
}

void func_801B130C(void) {
    MgTask *p;
    s32 n;
    s32 i;

    p = &D_80162978[D_8015169C];
    n = 0;
    for (i = 0; i < 300; i++) {
        if (D_801E2130[i] != 0) {
            ((void (*)(GosPart *))D_801E2130[i])(&D_801E09C0[i]);
            if (D_801E09C0[i].unk0 == -1) {
                D_801E2130[i] = 0;
            } else {
                n++;
            }
        }
    }
    if (n == 0 && D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B1404);

void func_801B15D4(void) {
    MgTask *p;
    MgTask *q;
    s16 n;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        while (D_801E07A8 >= 0x100) {
            q = &D_80162978[func_800BBEAC(&func_801B1404)];
            q->unk4 = func_80042DA8() % 120 + 0xC8;
            q->unk6 = func_80042DA8() % 60 - 0x1E;
            q->unk14 = func_80042DA8() % 100 + 0x64;
            D_801E07A8 -= 0x100;
        }
        D_801E07A8 += 0x40 + func_80042DA8() % 0xC0;
        n = ++p->unk2;
        if (n >= 0x16) {
            p->unk0 = -1;
        }
    }
}

void func_801B179C(MgTask *p) {
    u16 *frame;
    s16 n;

    D_801E07CC[0] = p->unk4;
    D_801E07D4 = p->unk8;
    func_8003A63C(&D_801E0988, (MgMat *)((u8 *)D_801E07CC - 0x14), D_801E07D8);
    func_8003B48C(D_801E07D8);
    func_8003B51C(D_801E07D8);
    frame = &D_801E07B4;
    *frame = p->unk2;
    D_801E09A8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E09A8);
    if (D_80062D98 == 0) {
        n = ++p->unk2;
        if (n >= D_801DDC50.v) {
            p->unk0 = -1;
        }
    }
}

void func_801B1890(GosPtl *p) {
    GosPtl *q;
    GosScr *s;
    u8 *k;
    s32 r;
    s32 t;

    D_801E07DC->pos.vx = p->unk4 + p->unkC;
    D_801E07DC->pos.vy = p->unk6 + p->unkE;
    D_801E07DC->pos.vz = p->unk8 + p->unk10;
    if (D_801E07DC->pos.vy > 0) {
        q = (GosPtl *)func_801B1294((s32)func_801B179C);
        q->unk4 = D_801E07DC->pos.vx;
        q->unk6 = 0;
        q->unk8 = D_801E07DC->pos.vz;
        p->unk0 = -1;
        return;
    }
    func_8003B48C(&D_801E0988);
    func_8003B51C(&D_801E0988);
    k = D_801E09A8;
    r = func_8003BC0C(&p->unk4, D_801E07DC, D_801E07DC, k + 8, k + 0x10, k + 0x10, &D_801E07DC->ext, &D_801E07DC->flag);
    s = D_801E07DC;
    s->depth = r;
    if (!(s->flag & 0x60000)) {
        *(s32 *)k = 0x04000000;
        *(s32 *)(k + 4) = 0x52202020;
        *(s32 *)(k + 0xC) = 0x606060;
        t = (s->depth >> 2) * 4 + 0x70;
        func_80046794(t + D_801517C0, k);
        D_801E09A8 = k + 0x14;
    }
    if (D_80062D98 == 0) {
        p->unk4 = D_801E07DC->pos.vx;
        p->unk6 = D_801E07DC->pos.vy;
        p->unk8 = D_801E07DC->pos.vz;
    }
}

void func_801B1A48(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 n;
    s32 sh;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x16) {
            sh = 0;
            t = (t << 12) / 22;
            n = t * 0x1000 >> 12;
        } else {
            t -= 0x16;
            if (t < 0x12) {
                n = 0x1000;
                sh = 0;
            } else {
                t -= 0x12;
                if (t < 0x14) {
                    sh = 1;
                    t = (t << 12) / 20;
                    n = (0x1000 - t) * 0x1000 >> 12;
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
        }
        n += n * p->unk2 & 0xFF;
        while (n >= 0x100) {
            n -= 0x100;
            q = (MgTask *)func_801B1294((s32)func_801B1890);
            q->unk4 = (func_80042DA8() % 4000 - 2000) >> sh;
            q->unk6 = func_80042DA8() % 500 - 5000;
            q->unk8 = (func_80042DA8() % 4000 - 2000) >> sh;
            q->unkC = 0;
            q->unkE = 500;
            q->unk10 = -50;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B1C6C);

void func_801B22E8(void) {
    MgTask *p;
    s32 t;
    s32 col;
    s32 b;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x19) {
        t = (t << 12) / 25;
        col = t * 0xFF >> 12;
        col = col | (col << 8) | (col << 16);
        b = 0xA00;
    } else {
        t -= 0x19;
        if (t < 10) {
            col = 0xFFFFFF;
            b = 0xA00;
        } else {
            t -= 10;
            if (t < 30) {
                col = 0xFFFFFF;
                t = (t << 12) / 30;
                b = (t * 0x3E00 >> 12) + 0xA00;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    func_801B1C6C(col, b);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B2418(void) {
    MgTask *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x28) {
        D_801E080C = (u32)((t << 12) / 40) >> 8;
    } else {
        p->unk0 = -1;
        return;
    }
    func_8003A63C(&D_801E0988, &D_801E0814, D_801E0834);
    func_8003B48C(D_801E0834);
    func_8003B51C(D_801E0834);
    D_801E09A8 = func_800D29D4(&D_801E0804, D_801517C0 + 0x406C, 0, D_801E09A8);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B252C(void) {
    MgTask *p;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_8003A63C(&D_801E0988, &D_801E0848, D_801E0868);
    func_8003B48C(D_801E0868);
    func_8003B51C(D_801E0868);
    D_801E09A8 = func_800D29D4(&D_801E0838, D_801517C0 + 0x406C, 0, D_801E09A8);
    if (D_80062D98 == 0) {
        n = ++p->unk2;
        if (n >= 0x1E) {
            p->unk0 = -1;
        } else {
            func_8003C8DC(-4, &D_801E0848);
        }
    }
}

INCLUDE_RODATA("../asm/us/magic_gospel/nonmatchings/text", D_801B0040);

void func_801B2620(void) {
    GosB8 loc;
    GosB8 *src;
    GosB8 *dst;
    GosEff *s;
    MgTask *p;
    s32 i;
    s32 x;
    s16 n;

    loc = D_801B0040;
    dst = D_801D3AE8;
    p = &D_80162978[D_8015169C];
    i = 0;
    src = D_801E087C[p->unk0];
    for (; i < 0x103; i++) {
        *dst++ = *src++;
    }
    s = D_801E08A4;
    func_8003C21C((MgSVec *)&p->unkC, &s->m);
    D_801E08A4->m.t[0] = p->unk4 * func_80039A74(p->unkE) >> 12;
    D_801E08A4->m.t[1] = p->unk6;
    x = p->unk4 * func_80039B40(p->unkE) >> 12;
    s = D_801E08A4;
    s->v0 = s->v4 = s->v8 = 0x100;
    s->m.t[2] = x;
    func_8003B35C(&s->m);
    func_8003A63C(&D_801E0988, &D_801E08A4->m, &D_801E08A4->m);
    func_8003B48C(&D_801E08A4->m);
    func_8003B51C(&D_801E08A4->m);
    D_801E09A8 = func_800D29D4(&D_801E086C, D_801517C0 + 0x70, 0xC, D_801E09A8);
    if (D_80062D98 == 0) {
        n = ++p->unk2;
        if (n >= 0x1E) {
            p->unk0 = -1;
        } else {
            p->unk6 = (u16)p->unk6 + (u16)p->unk8;
            p->unkE = (u16)p->unkE + (u16)p->unk18;
            p->unk0 = (p->unk0 + 1) % 10;
        }
    }
}

void func_801B286C(void) {
    MgTask *p;
    GosEff *s;
    s32 t;

    p = &D_80162978[D_8015169C];
    D_801E08B8->v4 = D_801E08B8->v8 = 0x1000;
    t = p->unk2;
    if (t < 5) {
        D_801E08B8->v0 = (t << 12) / 5 * 0x1000 >> 12;
        D_801E08B2.v = 0;
    } else {
        t -= 5;
        if (t < 5) {
            D_801E08B8->v0 = 0x1000;
            D_801E08B2.v = (t << 12) / 5;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    s = D_801E08B8;
    func_8003C21C((MgSVec *)&p->unkC, &s->m);
    s = D_801E08B8;
    s->m.t[0] = p->unk4;
    s->m.t[1] = p->unk6;
    s->m.t[2] = p->unk8;
    func_8003B35C(&s->m);
    func_8003A63C(&D_801E0988, &D_801E08B8->m, &D_801E08B8->m);
    func_8003B48C(&D_801E08B8->m);
    func_8003B51C(&D_801E08B8->m);
    func_8003B69C(0, 0, 0);
    D_801E09A8 = func_800D29D4(&D_801E08A8, D_801517C0 + 0x70, 0xC, D_801E09A8);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B2A2C(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 r;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            i++;
            q = &D_80162978[func_800BBEAC(&func_801B286C)];
            r = func_80042DA8() & 0xFFF;
            q->unk4 = (u32)(func_80039A74(r) * 0x7D) >> 10;
            q->unk6 = -0x2710;
            q->unk8 = (u32)(func_80039B40(r) * 0x7D) >> 10;
            q->unkC = 0x200;
            q->unkE = r;
            q->unk10 = 0;
        } while (i < 1);
        p->unk2++;
        if (p->unk2 >= 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B2B38(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        k = (t << 12) / 10;
        D_801E08E0.v = p->unk4 + (p->unkC * k >> 12);
        D_801E08E4.v = p->unk6 + (p->unkE * k >> 12);
        D_801E08E8.v = p->unk8 + (p->unk10 * k >> 12);
        D_801E08C6.v = 0;
    } else {
        t -= 10;
        if (t < 5) {
            k = (t << 12) / 5;
            D_801E08E0.v = p->unk4 + p->unkC;
            D_801E08E4.v = p->unk6 + p->unkE;
            D_801E08E8.v = p->unk8 + p->unk10;
            D_801E08C6.v = k;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    D_801E08CC.m[0][0] = D_801E08CC.m[1][1] = D_801E08CC.m[2][2] = p->unk14;
    func_8003B48C(&D_801E08CC);
    func_8003B51C(&D_801E08CC);
    func_8003B69C(0, 0, 0);
    D_801E09A8 = func_800D29D4(&D_801E08BC, D_801517C0 + 0x4084, 0, D_801E09A8);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B2D34(void) {
    MgTask *p;
    GosEff *s;
    s32 t;

    p = &D_80162978[D_8015169C];
    D_801E08FC->v4 = D_801E08FC->v8 = 0x2000;
    t = p->unk2;
    if (t < 5) {
        t = (t << 12) / 5;
        D_801E08FC->v0 = t * 0x3000 >> 12;
        D_801E08F6.v = 0;
    } else {
        t -= 5;
        if (t < 10) {
            D_801E08FC->v0 = 0x3000;
            t = (t << 12) / 10;
            D_801E08F6.v = t;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    s = D_801E08FC;
    func_8003C21C((MgSVec *)&p->unkC, &s->m);
    s = D_801E08FC;
    s->m.t[0] = p->unk4;
    s->m.t[1] = p->unk6;
    s->m.t[2] = p->unk8;
    func_8003B35C(&s->m);
    func_8003A63C(&D_801E0988, &D_801E08FC->m, &D_801E08FC->m);
    func_8003B48C(&D_801E08FC->m);
    func_8003B51C(&D_801E08FC->m);
    func_8003B69C(0, 0, 0);
    D_801E09A8 = func_800D29D4(&D_801E08EC, D_801517C0 + 0x70, 0xC, D_801E09A8);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B2F00);

void func_801B3034(void) {
    MgTask *p;
    u16 *f;
    u16 t;
    s32 q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    q = (t << 12) / D_801DDB88[0];
    f = &D_801E0908;
    *f = t;
    func_8003B69C(D_801E0910[p->unk0][0], D_801E0910[p->unk0][1], D_801E0910[p->unk0][2]);
    func_8003B710(&D_801E090C, q, (u16 *)((u8 *)f - 4));
    D_801E0907.v = 0x2E;
    func_800D4368(&p->unk4, p->unk14, -0x1F4);
    D_801E09A8 = func_800D4D90((u8 *)f - 8, D_801517C0 + 0x70, 0xC, D_801E09A8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801DDB88[0]) {
            p->unk0 = -1;
        } else {
            p->unk6 -= 0x14;
        }
    }
}

void func_801B31BC(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = &D_80162978[func_800BBEAC(&func_801B3034)];
            q->unk0 = func_80042DA8() % 3;
            k = 0x320;
            q->unk4 = (u16)p->unk4 - k + func_80042DA8() % 1600;
            q->unk6 = (u16)p->unk6 - k + func_80042DA8() % 1600;
            q->unk8 = (u16)p->unk8 - k + func_80042DA8() % 1600;
            q->unk14 = func_80042DA8() % 0x800 + 0x1800;
            i++;
        } while (i < 1);
        p->unk2++;
        if (p->unk2 >= 0xF) {
            func_800D5774(p->unk0);
            p->unk0 = -1;
        }
    }
}

void func_801B3394(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B31BC)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

void func_801B3414(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 i;
    s32 x;

    p = &D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801E0600, &D_801E0988);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 14) {
            if (t == 0) {
                D_800F5B70 = 0;
                D_800F5B71 = 0;
                D_800F5B72 = 0;
                func_800D52A0(0x800, 0xA);
                func_800BBEAC(&func_801B1A48);
                func_800D55F4(0x20, 0x40, 0x242);
            }
        } else {
            t -= 14;
            if (t < 8) {
            } else {
                t -= 8;
                if (t < 8) {
                } else {
                    t -= 8;
                    if (t < 10) {
                    } else {
                        t -= 10;
                        if (t < 25) {
                            if (t == 0) {
                                func_800BBEAC(&func_801B22E8);
                                func_800D52A0(0, 0x19);
                            }
                        } else {
                            t -= 25;
                            if (t < 10) {
                                if (t == 0) {
                                    func_800BBEAC(&func_801B2418);
                                }
                            } else {
                                t -= 10;
                                if (t < 5) {
                                } else {
                                    t -= 5;
                                    if (t < 5) {
                                    } else {
                                        t -= 5;
                                        if (t < 20) {
                                        } else {
                                            t -= 20;
                                            if (t < 10) {
                                                if (t == 0) {
                                                    func_800BBEAC(&func_801B252C);
                                                    i = 0;
                                                    do {
                                                        q = &D_80162978[func_800BBEAC(&func_801B2620)];
                                                        q->unk0 = func_80042DA8() % 10;
                                                        x = (i << 12) / 3 + func_80042DA8() % 341;
                                                        q->unk4 = func_80042DA8() % 100 + 0x190;
                                                        q->unk6 = func_80042DA8() % 1500 - 0x2710;
                                                        q->unk8 = func_80042DA8() % 40 - 0x14;
                                                        q->unkC = 0x200;
                                                        q->unkE = x;
                                                        q->unk10 = 0;
                                                        q->unk18 = func_80042DA8() % 64 - 0x20;
                                                        i++;
                                                    } while (i < 3);
                                                    func_800BBEAC(&func_801B2A2C);
                                                    for (i = 0; i < 5; i++) {
                                                        q = &D_80162978[func_800BBEAC(&func_801B2B38)];
                                                        q->unk6 = -0x258;
                                                        q->unk4 = 0;
                                                        q->unk8 = 0x1000;
                                                        q->unkC = i * 0xC8;
                                                        q->unkE = i * 0xF0;
                                                        q->unk10 = 0;
                                                        q->unk14 = func_80042DA8() % 0x300 + 0x100;
                                                    }
                                                }
                                            } else {
                                                t -= 10;
                                                if (t < 20) {
                                                } else {
                                                    t -= 20;
                                                    if (t < 30) {
                                                        if (t == 0) {
                                                            func_800BBEAC(&func_801B2F00);
                                                            func_800D5444(D_801E0980, 0, 0, &func_801B3394);
                                                        }
                                                    } else {
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
        }
        p->unk2++;
    }
}

void func_801B38A8(void) {
    u8 *v;
    MgTask *p;

    p = &D_80162978[D_8015169C];
    v = D_801B3A84;
    if (p->unk2 == 0) {
        v += 0x8000;
    }
    D_801E09A8 = v;
    p->unk2 = (u16)p->unk2 ^ 1;
    if (D_80162080 < 3) {
        p->unk0 = -1;
        D_800FAFDC = 0;
    }
}

s32 func_801B3914(arg0, arg1) {
    M2C_UNK sp10;
    u16 *f;
    MgMat *m;
    u8 *a;
    s32 t;

    func_800D2980(D_801B3A84, 0, 0, 0);
    func_800BBEAC(&func_801B38A8);
    D_801E0980 = arg0;
    func_800D54EC(arg0, &sp10);
    f = &D_801E0622;
    *f = D_80151A46[arg1][0] + 0x800;
    m = &D_801E0600;
    func_8003C21C((MgSVec *)((u8 *)f - 2), m);
    t = D_80151A4C[arg1].vx;
    D_801E0614 = t;
    t = D_80151A50[arg1][0];
    D_801E061C = t;
    func_801B1270();
    func_800BBEAC(&func_801B130C);
    t = func_80042DA8() & 0x100;
    a = &D_801E06F8;
    if (t) {
        a = &D_801E0648;
    }
    ((void (*)(s32, s32, s32))func_801B120C)((s32)a, (s32)m, arg1);
    func_800BBEAC(&func_801B3414);
    D_800FAFDC = 1;
    D_800F8380 |= 8;
}
