#include "common.h"
#include "magic_riva/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B309C();
    return &D_801DD26C;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F49FE[-v];
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
            D_801F3678.actor = -1;
            D_801F36A4.actor = -1;
            D_801F3678.frames = 0;
            D_801F36A4.frames = 0;
            p->unk2 = 1;
        }
        while (D_801F3678.frames == 0 || D_801F36A4.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801F36D0 = &D_801F3678;
                D_801F36D4 = &D_801F36A4;
            } else {
                D_801F36D0 = &D_801F36A4;
                D_801F36D4 = &D_801F3678;
            }
            D_801F36D0->mode = op & 0xFF3F;
            switch (D_801F36D0->mode) {
            case 1:
                D_801F36D0->pos.vx = *p->script++;
                D_801F36D0->pos.vy = *p->script++;
                D_801F36D0->pos.vz = *p->script++;
                break;
            case 2:
                D_801F36D0->frames = func_801B0068(&p->script);
                D_801F36D0->vel.vx = (*p->script++ - D_801F36D0->pos.vx) / D_801F36D0->frames;
                D_801F36D0->vel.vy = (*p->script++ - D_801F36D0->pos.vy) / D_801F36D0->frames;
                D_801F36D0->vel.vz = (*p->script++ - D_801F36D0->pos.vz) / D_801F36D0->frames;
                break;
            case 3:
                sv->vx = D_801F36D4->pos.vx - D_801F36D0->pos.vx;
                sv->vy = D_801F36D4->pos.vy - D_801F36D0->pos.vy;
                sv->vz = D_801F36D4->pos.vz - D_801F36D0->pos.vz;
                D_801F36D0->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801F36D0->unk18 = D_801F36D0->pos;
                D_801F36D0->frames = func_801B0068(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801F36D0->vel.vx = (sv->vx - D_801F36D0->pos.vx) / D_801F36D0->frames;
                D_801F36D0->vel.vy = (sv->vy - D_801F36D0->pos.vy) / D_801F36D0->frames;
                D_801F36D0->vel.vz = (sv->vz - D_801F36D0->pos.vz) / D_801F36D0->frames;
                if (D_801F36D4->mode == 2) {
                    sv2->vx = D_801F36D4->pos.vx + D_801F36D4->vel.vx * D_801F36D4->frames;
                    sv2->vy = D_801F36D4->pos.vy + D_801F36D4->vel.vy * D_801F36D4->frames;
                    sv2->vz = D_801F36D4->pos.vz + D_801F36D4->vel.vz * D_801F36D4->frames;
                } else {
                    sv2->vx = D_801F36D4->pos.vx;
                    sv2->vy = D_801F36D4->pos.vy;
                    sv2->vz = D_801F36D4->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801F36D0->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801F36D0->unk4) / D_801F36D0->frames;
                break;
            case 4:
                D_801F36D0->frames = func_801B0068(&p->script);
                sv->vx = *p->script++ - D_801F36D0->pos.vx;
                sv->vy = *p->script++ - D_801F36D0->pos.vy;
                sv->vz = *p->script++ - D_801F36D0->pos.vz;
                D_801F36D0->unk18.vx = ((sv->vx - D_801F36D0->vel.vx * D_801F36D0->frames) * 2) / (D_801F36D0->frames * D_801F36D0->frames);
                D_801F36D0->unk18.vy = ((sv->vy - D_801F36D0->vel.vy * D_801F36D0->frames) * 2) / (D_801F36D0->frames * D_801F36D0->frames);
                D_801F36D0->unk18.vz = ((sv->vz - D_801F36D0->vel.vz * D_801F36D0->frames) * 2) / (D_801F36D0->frames * D_801F36D0->frames);
                break;
            case 5:
                D_801F36D0->frames = func_801B0068(&p->script);
                D_801F36D0->unk28 = *p->script++;
                D_801F36D0->unk4 = 0;
                D_801F36D0->unk8 = 0x1000 / D_801F36D0->frames;
                D_801F36D0->unk18.vx = D_801F36D0->pos.vx;
                D_801F36D0->unk18.vy = D_801F36D0->pos.vy;
                D_801F36D0->unk18.vz = D_801F36D0->pos.vz;
                D_801F36D0->vel.vx = *p->script++ - D_801F36D0->pos.vx;
                D_801F36D0->vel.vy = *p->script++ - D_801F36D0->pos.vy;
                D_801F36D0->vel.vz = *p->script++ - D_801F36D0->pos.vz;
                break;
            case 6:
                if ((D_801F36D0->actor = *p->script++) == 0) {
                    D_801F36D0->actor = p->actor;
                }
                D_801F36D0->part = *p->script++;
                break;
            case 7:
                D_801F36D0->actor = -1;
                break;
            case 0:
            case 9:
                D_801F36D0->frames = func_801B0068(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801F36D0 = &D_801F3678;
        D_801F36D4 = &D_801F36A4;
        for (i = 0; i < 2; i++) {
            switch (D_801F36D0->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801F36D0->vel.vx += D_801F36D0->unk18.vx;
                D_801F36D0->vel.vy += D_801F36D0->unk18.vy;
                D_801F36D0->vel.vz += D_801F36D0->unk18.vz;
            case 2:
                D_801F36D0->pos.vx += D_801F36D0->vel.vx;
                D_801F36D0->pos.vy += D_801F36D0->vel.vy;
                D_801F36D0->pos.vz += D_801F36D0->vel.vz;
                break;
            case 3:
                D_801F36D0->unk18.vx += D_801F36D0->vel.vx;
                D_801F36D0->unk18.vy += D_801F36D0->vel.vy;
                D_801F36D0->unk18.vz += D_801F36D0->vel.vz;
                D_801F36D0->unk4 += D_801F36D0->unk8;
                vec->vx = D_801F36D4->pos.vx - D_801F36D0->unk18.vx;
                vec->vy = D_801F36D4->pos.vy - D_801F36D0->unk18.vy;
                vec->vz = D_801F36D4->pos.vz - D_801F36D0->unk18.vz;
                func_8003A078(vec, sv);
                D_801F36D0->pos.vx = D_801F36D4->pos.vx - ((sv->vx * D_801F36D0->unk4) >> 12);
                D_801F36D0->pos.vy = D_801F36D4->pos.vy - ((sv->vy * D_801F36D0->unk4) >> 12);
                D_801F36D0->pos.vz = D_801F36D4->pos.vz - ((sv->vz * D_801F36D0->unk4) >> 12);
                break;
            case 5:
                D_801F36D0->unk4 += D_801F36D0->unk8;
                k = func_801B00A4(D_801F36D0->unk4, D_801F36D0->unk28);
                D_801F36D0->pos.vx = D_801F36D0->unk18.vx + ((D_801F36D0->vel.vx * k) >> 12);
                D_801F36D0->pos.vy = D_801F36D0->unk18.vy + ((D_801F36D0->vel.vy * k) >> 12);
                D_801F36D0->pos.vz = D_801F36D0->unk18.vz + ((D_801F36D0->vel.vz * k) >> 12);
                break;
            }
            cam = D_801F36D0;
            D_801F36D0 = &D_801F36A4;
            D_801F36D4 = &D_801F3678;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801F3678.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801F3678.actor == -1) {
                func_8003BC6C(&D_801F3678.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801F3678.pos, vec);
                if (D_801F3678.part != -1) {
                    func_800D3994(D_801F3678.actor, D_801F3678.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801F3678.actor].vx;
                    sv->vy = D_80151A4C[D_801F3678.actor].vy;
                    sv->vz = D_80151A4C[D_801F3678.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801F36A4.mode != 9) {
            if (D_801F36A4.actor == -1) {
                func_8003BC6C(&D_801F36A4.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801F36A4.pos, vec);
                if (D_801F36A4.part != -1) {
                    func_800D3994(D_801F36A4.actor, D_801F36A4.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801F36A4.actor].vx;
                    sv->vy = D_80151A4C[D_801F36A4.actor].vy;
                    sv->vz = D_80151A4C[D_801F36A4.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801F3678.mode != 9) {
            D_80158D00 = D_801F3678.pos;
        }
        if (D_801F36A4.mode != 9) {
            D_801031E8 = D_801F36A4.pos;
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

MgMat *func_801B122C(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801F3518.m[0][0] = D_801F3518.m[1][1] = D_801F3518.m[2][2] = scale;
    func_8003B48C(&D_801F49E0);
    func_8003B51C(&D_801F49E0);
    func_8003BC6C(v, (MgVec *)D_801F3518.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801F3518.t, &n);
        D_801F3518.t[0] += (dist * n.vx) >> 12;
        D_801F3518.t[1] += (dist * n.vy) >> 12;
        D_801F3518.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801F3518);
    func_8003B51C(&D_801F3518);
    return &D_801F3518;
}

MgMat *func_801B1348(MgSVec *arg0, s32 arg1, MgMat *arg2) {
    MgVec v;
    s32 flag;

    func_8003B48C(&D_801F49E0);
    func_8003B51C(&D_801F49E0);
    func_8003BC6C(arg0, (MgVec *)arg2->t, &flag);
    if (arg1 != 0) {
        func_8003A08C((MgVec *)arg2->t, &v);
        arg2->t[0] += (arg1 * v.vx) >> 12;
        arg2->t[1] += (arg1 * v.vy) >> 12;
        arg2->t[2] += (arg1 * v.vz) >> 12;
    }
    return arg2;
}

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B142C);

void func_801B1744(void) {
    MgMat m;
    MgVec scale;
    MgTask *p;
    s16 *frame;
    s16 *frame2;
    s16 v;
    s32 t;
    s32 w;
    s16 nw;
    s32 i;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x2D) {
        v = t * 0xF0 / 45;
        if (v < 0) {
            v = 0;
        } else if (v >= 0x100) {
            v = 0xFF;
        }
        frame = &D_801F3552;
        *frame = v;
        func_8003C21C(&D_801F3538, &m);
        w = p->unk2 * 0x66 + 0x600;
        scale.vx = scale.vy = scale.vz = w;
        func_8003B35C(&m, &scale);
        m.t[0] = p->unk4;
        m.t[1] = p->unk6;
        m.t[2] = p->unk8;
        func_8003A63C(&D_801F49E0, &m, &m);
        func_8003B48C(&m);
        func_8003B51C(&m);
        D_80163C74 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_80163C74);
        func_8003C21C(&D_801F3540, &m);
        w = p->unk2 * 0x88 + 0x800;
        scale.vx = scale.vy = scale.vz = w;
        func_8003B35C(&m, &scale);
        func_8003A63C(&D_801F49E0, &m, &m);
        func_8003B48C(&m);
        D_80163C74 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_80163C74);
    } else {
        if (D_80062D98 == 0) {
            for (i = 0; i < D_801F499C; i++) {
                D_801F36DC[i][0] += D_801F403C[i][0];
                D_801F36DC[i][1] += D_801F403C[i][1];
                D_801F36DC[i][2] += D_801F403C[i][2];
            }
        }
        frame2 = &D_801F3562;
        *frame2 = 0xFF - (p->unk2 - 0x2D) * 0xFF / 19;
        func_8003C21C(&D_801F3538, &m);
        scale.vx = scale.vy = scale.vz = 0x1800;
        func_8003B35C(&m, &scale);
        m.t[0] = p->unk4;
        m.t[1] = p->unk6;
        m.t[2] = p->unk8;
        func_8003A63C(&D_801F49E0, &m, &m);
        func_8003B48C(&m);
        func_8003B51C(&m);
        D_80163C74 = func_800D7D3C((u8 *)frame2 - 0xA, D_801517C0 + 0x70, 0xC, D_80163C74);
        func_8003C21C(&D_801F3540, &m);
        scale.vx = scale.vy = scale.vz = 0x2000;
        func_8003B35C(&m, &scale);
        func_8003A63C(&D_801F49E0, &m, &m);
        func_8003B48C(&m);
        D_80163C74 = func_800D7D3C((u8 *)frame2 - 0xA, D_801517C0 + 0x70, 0xC, D_80163C74);
    }
    if (D_80062D98 == 0) {
        nw = p->unk2 + 1;
        p->unk2 = nw;
        if (nw < 0x41) {
            D_801F3538.vx += 0x10;
            D_801F3538.vy += 0x20;
            D_801F3538.vz += 0x40;
            D_801F3540.vx -= 0x10;
            D_801F3540.vy -= 0x20;
            D_801F3540.vz -= 0x40;
        }
        if (p->unk2 == 0x2D) {
            func_801B142C();
        }
        if (p->unk2 >= 0x41) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B1C10);

void func_801B1F8C(RivaPart *p) {
    s32 t;

    if (D_80062D98 == 0) {
        p->pos.vx += p->vel.vx;
        p->pos.vy += p->vel.vy;
        p->pos.vz += p->vel.vz;
        if (p->pos.vy >= 0) {
            p->unk0 = -1;
            return;
        }
    }
    p->vel.vy += 0xC;
    p->vel.vx -= p->vel.vx >> 3;
    p->vel.vz -= p->vel.vz >> 3;
    D_801F35AC.m[0][0] = func_80039A74((p->unk2 * 0x1F4) & 0xFFC) / 16 + 0x600;
    t = func_80039B40((p->unk2 * 0x1F4) & 0xFFC);
    D_801F35B4 = t / 16 + 0x600;
    func_801B1348(&p->pos, 0, &D_801F35AC);
    func_8003B48C(&D_801F35AC);
    func_8003B51C(&D_801F35AC);
    D_80163C74 = func_800D6260(D_801F359C, D_801517C0 + 0x70, 0xC, D_80163C74);
}

void func_801B2104(void) {
    MgTask *p;
    RivaPart *q;
    s32 n;
    s32 i;

    n = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 0x12C; i++) {
        q = &D_801DD260[i];
        if (q->unk0 != -1) {
            n++;
            func_801B1F8C(q);
        }
    }
    if (n == 0) {
        p->unk0 = -1;
    }
}

void func_801B21B0(void) {
    MgMat m;
    MgTask *p;
    s16 c;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    c = (func_80039A74((p->unk2 << 6) & 0xFC0) >> 5) + 0x1000;
    D_801F35DC[0] = D_801F35E4 = D_801F35EC = c;
    func_8003A63C(&D_801F49E0, D_801F35DC, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    t = p->unk2;
    if (t - 0x87 < 0) {
        D_801F35D0[0] = 0;
        D_801F35D6 = 0x80;
        D_80163C74 = func_800D29D4((u8 *)&D_801F35D0[0] - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
        goto tail;
    }
    if (t - 0xB6 < 0) {
        D_801F35D0[0] = 0;
        D_801F35D6 = 0x80;
    } else {
        p->unk0 = -1;
        return;
    }
    D_80163C74 = func_800D29D4(&D_801F35CC, D_801517C0 + 0x406C, 0, D_80163C74);
tail:
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B2308(void) {
    MgSVec sp10;
    MgTask *p;
    s32 n;
    s32 k;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B48C(&D_801F49E0);
    func_8003B51C(&D_801F49E0);
    func_8003C21C(D_801F361C, (MgMat *)0x1F800000);
    ((MgMat *)0x1F800000)->t[0] = p->unk4;
    ((MgMat *)0x1F800000)->t[1] = 0x1000 - p->unk2 * 0x5D;
    ((MgMat *)0x1F800000)->t[2] = p->unk8;
    func_8003A63C(&D_801F49E0, (MgMat *)0x1F800000, (MgMat *)0x1F800020);
    func_8003B48C((MgMat *)0x1F800020);
    func_8003B51C((MgMat *)0x1F800020);
    n = (func_8003BBDC(D_801F362C, &sp10, &sp10, &sp10) >> 2) * 4;
    k = n + 0x74;
    D_80163C74 = func_800D29D4(D_801F35FC, k + D_801517C0, 0, D_80163C74);
    func_8003C21C(D_801F3624, (MgMat *)0x1F800000);
    ((MgMat *)0x1F800000)->t[1] -= p->unk2 * 0x64 / 45;
    func_8003A63C(&D_801F49E0, (MgMat *)0x1F800000, (MgMat *)0x1F800020);
    func_8003B48C((MgMat *)0x1F800020);
    func_8003B51C((MgMat *)0x1F800020);
    n += 0x70;
    D_80163C74 = func_800D29D4(D_801F360C, n + D_801517C0, 0, D_80163C74);
    if (D_80062D98 == 0) {
        D_801F361C[0] -= 0x40;
        p->unk8 += p->unk10;
        t = p->unk2 + 1;
        p->unk2 = t;
        if (t >= 0x2D) {
            p->unk0 = -1;
        }
    }
}

void func_801B254C(MgSVec *a, MgSVec *b, MgSVec *d, s32 n, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        d->vx = (b->vx - a->vx) / n;
        d->vy = (b->vy - a->vy) / n;
        d->vz = (b->vz - a->vz) / n;
        a++;
        b++;
        d++;
    }
}

void func_801B2670(MgSVec *a, MgSVec *b, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        a->vx += b->vx;
        a->vy += b->vy;
        a->vz += b->vz;
        a++;
        b++;
    }
}

void func_801B26E4(void) {
    MgMat m1;
    MgMat m2;
    MgTask *p;
    s32 v;
    s16 w;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        v = p->unk2;
        if (v < 0x1B) {
            if (!(*(volatile s16 *)&p->unk2 & 3)) {
                if (v < 0) {
                    v += 3;
                }
                func_801B254C(D_801D1934, D_801DD178[v >> 2], D_801DD25C, 4, 0x1E0);
            }
            func_801B2670(D_801D1934, D_801DD25C, 0x1E0);
        }
    }
    func_8003C21C(D_801F3644, &m1);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    func_8003A63C(&D_801F49E0, &m1, &m2);
    if (p->unk2 >= 0x2F) {
        func_8003B69C(0, 0, 0);
        D_801F3634.unk4 = 0xC8;
        D_801F3634.unkA = ((p->unk2 - 0x2F) << 12) / 15;
    } else {
        D_801F3634.unk4 = 0xC0;
        D_801F3634.unkA = 0;
    }
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    D_80163C74 = func_800D29D4(&D_801F3634, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (*(u8 *)0x80062D98 == 0) {
        p->unk8 += p->unk10;
        w = p->unk2 + 1;
        p->unk2 = w;
        if (w >= 0x3E) {
            p->unk0 = -1;
        }
    }
}

void func_801B28EC(void) {
    MgTask *p;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_801F3664[0] = p->unk2;
    func_800D4368(&p->unk4, 0x2000, -0x1F4);
    D_80163C74 = func_800D4D90(&D_801F3664[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        t = p->unk2 + 1;
        p->unk2 = t;
        if (t >= D_801DD198) {
            p->unk0 = -1;
        }
    }
}

void func_801B29B0(void) {
    MgMat m;
    MgSVec v;
    MgTask *p;
    MgTask *q;
    MgTask *q2;
    s32 t;
    RivaPart *r;
    s32 k;
    s32 i;
    s32 off;
    s32 w;
    s16 *tp;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801F49C0, &D_801F49E0);
    if (D_80062D98 == 0) {
        k = p->unk2;
        if (k < 0x3C) {
            if (k == 0) {
                func_800D55F4(0x2A, 0x40, 0x13);
            }
            if (p->unk2 == 0xF) {
                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B1744)];
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            }
            if (p->unk2 < 0x2D) {
                i = 0;
                do {
                    i++;
                    q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B1C10)];
                    D_801F3668.vx += 0x456;
                    D_801F3668.vy += 0x567;
                    D_801F3668.vz += 0x678;
                    func_8003C21C(&D_801F3668, &m);
                    D_801F3670.vx = ((k * 0x1800 / 45 + 0x600) * 1000 >> 12) + 0xBB8;
                    func_8003B2CC(&m, &D_801F3670, &v);
                    q->unk4 = p->unk4 + v.vx;
                    q->unk6 = p->unk6 + v.vy;
                    q->unk8 = p->unk8 + v.vz;
                    q->unkC = -v.vx / 15;
                    q->unkE = -v.vy / 15;
                    q->unk10 = -v.vz / 15;
                } while (i < 2);
            }
        } else {
            k -= 0x3C;
            if (k < 0xF) {
                if (k == 0) {
                    i = 0;
                    do {
                        D_801DD260[i].unk0 = 0;
                        D_801F3668.vx += 0x456;
                        D_801F3668.vy += 0x567;
                        D_801F3668.vz += 0x678;
                        func_8003C21C(&D_801F3668, &m);
                        D_801F3670.vx = 0x5DC;
                        func_8003B2CC(&m, &D_801F3670, &v);
                        r = &D_801DD260[i];
                        r->pos.vx = p->unk4 + v.vx;
                        r->pos.vy = p->unk6 + v.vy;
                        r->pos.vz = p->unk8 + v.vz;
                        r->vel.vx = (s16)v.vx >> 2;
                        i++;
                        r->vel.vy = (s16)v.vy >> 2;
                        r->vel.vz = (s16)v.vz >> 2;
                    } while (i < 0x12C);
                    func_800BBEAC((M2C_UNK *)func_801B2104);
                    D_801F36D8 = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B21B0)];
                    q2 = func_800D4FA8(1);
                    *(s16 *)((u8 *)q2 + 4) = 0;
                    *(s16 *)((u8 *)q2 + 6) = 0;
                    t = *(u16 *)&D_801F49DC;
                    q2->unk8 = t;
                    t = D_801DD266;
                    t += 0x800;
                    q2->unk10 = t;
                }
            } else {
                k -= 0xF;
                if (k >= 0x14) {
                    k -= 0x14;
                    if (k >= 0xA) {
                        do {
                            k -= 0xA;
                        } while (0);
                        if (k < 0x1E) {
                            if (k == 0) {
                                func_800D55F4(0x28, 0x40, 0xE);
                                func_800D55F4(0x29, 0x40, 0x11);
                            }
                        } else {
                            k -= 0x1E;
                            if (k >= 0xF) {
                                k -= 0xF;
                                if (k < 0x1E) {
                                    if (k == 0) {
                                        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B2308)];
                                        q->unk8 = -0x1388;
                                        q->unk4 = 0;
                                        q->unk6 = 0;
                                        q->unkC = 0;
                                        q->unk10 = 0x50;
                                        q->unk1C = p->unk1C;
                                        D_801F49A0 = q;
                                        q->unk1E = p->unk1E;
                                    }
                                } else {
                                    k -= 0x1E;
                                    if (k < 0xF) {
                                        if (k == 0xD) {
                                            func_800D4FA8(2);
                                        }
                                    } else {
                                        k -= 0xF;
                                        if (k < 0x1B) {
                                            if (k == 0) {
                                                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B26E4)];
                                                q->unk6 = -0xC8;
                                                q->unk8 = -0x3A98;
                                                q->unk4 = 0;
                                                q->unkC = 0;
                                                q->unkE = 0;
                                                q->unk10 = 0x1F4;
                                            }
                                        } else {
                                            k -= 0x1B;
                                            if (k < 0x23) {
                                                if (k == 0) {
                                                    for (i = 0; i < 10; i++) {
                                                        if ((D_801F49A4 >> i) & 1) {
                                                            func_800D5774(i);
                                                        }
                                                    }
                                                }
                                                if (k < 0x14) {
                                                    i = 0;
                                                    tp = D_801518F6[0];
                                                    off = 0;
                                                    for (; i < 10; i++) {
                                                        if ((D_801F49A4 >> i) & 1) {
                                                            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B28EC)];
                                                            func_800D3994(i, *((u8 *)D_8015190F + off), (MgSVec *)&q->unk4);
                                                            w = (((s32 (*)(void))func_80042DA8)() & 0x3FF) + 0x600;
                                                            k = *(s16 *)(D_801F49B8 + 0x162);
                                                            k += w;
                                                            k &= 0xFFF;
                                                            q->unk4 += func_80039A74(k) * *tp >> 12;
                                                            q->unk6 = -0x320;
                                                            q->unk8 -= func_80039B40(k) * *tp >> 12;
                                                        }
                                                        tp += 0x5CE;
                                                        off += 0xB9C;
                                                    }
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
        p->unk2++;
    }
}

s32 func_801B309C(arg0, arg1) {
    MgSVec sp10;
    MgMat *m;
    MgTask *p;
    u8 *a;
    s32 t;
    s16 id;
    int c;

    func_800D2980(D_801B3268, 0, 0, 0);
    D_801F49D4 = 0;
    D_801F49D8 = 0;
    D_801F49A4 = arg0;
    func_800D54EC(arg0, (M2C_UNK *)&sp10);
    if (sp10.vz > D_80151A50[arg1][0]) {
        D_801F49DC = sp10.vz - 0x1388;
    } else {
        D_801DD264[1] = 0x800;
        D_801F49DC = sp10.vz + 0x1388;
    }
    m = &D_801F49C0;
    func_8003C21C(D_801DD264, m);
    D_801F49A4 = arg0;
    D_801F49AC = id = arg1;
    D_801F49B8 = D_801518E4[id];
    D_801F49B0 = 3;
    D_801F49BC = D_801518E4[3];
    p = &D_80162978[func_800BBEAC(&func_801B29B0)];
    c = D_800FA6D4;
    p->unk4 = 0;
    p->unk6 = -0x7D0;
    p->unk8 = 0;
    p->unk1E = id;
    p->unk1C = c;
    do {
        t = func_80042DA8(c) & 0x100;
    } while (0);
    a = D_801F3444;
    if (t) {
        a = D_801F337C;
    }
    ((void (*)(s32, s32, s32))func_801B11C8)((s32)a, (s32)m, arg1);
    D_800F8380 |= 8;
}
