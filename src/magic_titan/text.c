#include "common.h"
#include "magic_titan/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B5190();
    return &D_801C0EC8;
}

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B0068);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B0830);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B0E64);

s32 func_801B1A24(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801D3E02[-v];
    }
    return v;
}

s32 func_801B1A60(s32 t, s32 s) {
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

void func_801B1B50(void) {
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
            D_801D39A8.actor = -1;
            D_801D39D4.actor = -1;
            D_801D39A8.frames = 0;
            D_801D39D4.frames = 0;
            p->unk2 = 1;
        }
        while (D_801D39A8.frames == 0 || D_801D39D4.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801D3A00 = &D_801D39A8;
                D_801D3A04 = &D_801D39D4;
            } else {
                D_801D3A00 = &D_801D39D4;
                D_801D3A04 = &D_801D39A8;
            }
            D_801D3A00->mode = op & 0xFF3F;
            switch (D_801D3A00->mode) {
            case 1:
                D_801D3A00->pos.vx = *p->script++;
                D_801D3A00->pos.vy = *p->script++;
                D_801D3A00->pos.vz = *p->script++;
                break;
            case 2:
                D_801D3A00->frames = func_801B1A24(&p->script);
                D_801D3A00->vel.vx = (*p->script++ - D_801D3A00->pos.vx) / D_801D3A00->frames;
                D_801D3A00->vel.vy = (*p->script++ - D_801D3A00->pos.vy) / D_801D3A00->frames;
                D_801D3A00->vel.vz = (*p->script++ - D_801D3A00->pos.vz) / D_801D3A00->frames;
                break;
            case 3:
                sv->vx = D_801D3A04->pos.vx - D_801D3A00->pos.vx;
                sv->vy = D_801D3A04->pos.vy - D_801D3A00->pos.vy;
                sv->vz = D_801D3A04->pos.vz - D_801D3A00->pos.vz;
                D_801D3A00->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801D3A00->unk18 = D_801D3A00->pos;
                D_801D3A00->frames = func_801B1A24(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801D3A00->vel.vx = (sv->vx - D_801D3A00->pos.vx) / D_801D3A00->frames;
                D_801D3A00->vel.vy = (sv->vy - D_801D3A00->pos.vy) / D_801D3A00->frames;
                D_801D3A00->vel.vz = (sv->vz - D_801D3A00->pos.vz) / D_801D3A00->frames;
                if (D_801D3A04->mode == 2) {
                    sv2->vx = D_801D3A04->pos.vx + D_801D3A04->vel.vx * D_801D3A04->frames;
                    sv2->vy = D_801D3A04->pos.vy + D_801D3A04->vel.vy * D_801D3A04->frames;
                    sv2->vz = D_801D3A04->pos.vz + D_801D3A04->vel.vz * D_801D3A04->frames;
                } else {
                    sv2->vx = D_801D3A04->pos.vx;
                    sv2->vy = D_801D3A04->pos.vy;
                    sv2->vz = D_801D3A04->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801D3A00->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801D3A00->unk4) / D_801D3A00->frames;
                break;
            case 4:
                D_801D3A00->frames = func_801B1A24(&p->script);
                sv->vx = *p->script++ - D_801D3A00->pos.vx;
                sv->vy = *p->script++ - D_801D3A00->pos.vy;
                sv->vz = *p->script++ - D_801D3A00->pos.vz;
                D_801D3A00->unk18.vx = ((sv->vx - D_801D3A00->vel.vx * D_801D3A00->frames) * 2) / (D_801D3A00->frames * D_801D3A00->frames);
                D_801D3A00->unk18.vy = ((sv->vy - D_801D3A00->vel.vy * D_801D3A00->frames) * 2) / (D_801D3A00->frames * D_801D3A00->frames);
                D_801D3A00->unk18.vz = ((sv->vz - D_801D3A00->vel.vz * D_801D3A00->frames) * 2) / (D_801D3A00->frames * D_801D3A00->frames);
                break;
            case 5:
                D_801D3A00->frames = func_801B1A24(&p->script);
                D_801D3A00->unk28 = *p->script++;
                D_801D3A00->unk4 = 0;
                D_801D3A00->unk8 = 0x1000 / D_801D3A00->frames;
                D_801D3A00->unk18.vx = D_801D3A00->pos.vx;
                D_801D3A00->unk18.vy = D_801D3A00->pos.vy;
                D_801D3A00->unk18.vz = D_801D3A00->pos.vz;
                D_801D3A00->vel.vx = *p->script++ - D_801D3A00->pos.vx;
                D_801D3A00->vel.vy = *p->script++ - D_801D3A00->pos.vy;
                D_801D3A00->vel.vz = *p->script++ - D_801D3A00->pos.vz;
                break;
            case 6:
                if ((D_801D3A00->actor = *p->script++) == 0) {
                    D_801D3A00->actor = p->actor;
                }
                D_801D3A00->part = *p->script++;
                break;
            case 7:
                D_801D3A00->actor = -1;
                break;
            case 0:
            case 9:
                D_801D3A00->frames = func_801B1A24(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801D3A00 = &D_801D39A8;
        D_801D3A04 = &D_801D39D4;
        for (i = 0; i < 2; i++) {
            switch (D_801D3A00->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801D3A00->vel.vx += D_801D3A00->unk18.vx;
                D_801D3A00->vel.vy += D_801D3A00->unk18.vy;
                D_801D3A00->vel.vz += D_801D3A00->unk18.vz;
            case 2:
                D_801D3A00->pos.vx += D_801D3A00->vel.vx;
                D_801D3A00->pos.vy += D_801D3A00->vel.vy;
                D_801D3A00->pos.vz += D_801D3A00->vel.vz;
                break;
            case 3:
                D_801D3A00->unk18.vx += D_801D3A00->vel.vx;
                D_801D3A00->unk18.vy += D_801D3A00->vel.vy;
                D_801D3A00->unk18.vz += D_801D3A00->vel.vz;
                D_801D3A00->unk4 += D_801D3A00->unk8;
                vec->vx = D_801D3A04->pos.vx - D_801D3A00->unk18.vx;
                vec->vy = D_801D3A04->pos.vy - D_801D3A00->unk18.vy;
                vec->vz = D_801D3A04->pos.vz - D_801D3A00->unk18.vz;
                func_8003A078(vec, sv);
                D_801D3A00->pos.vx = D_801D3A04->pos.vx - ((sv->vx * D_801D3A00->unk4) >> 12);
                D_801D3A00->pos.vy = D_801D3A04->pos.vy - ((sv->vy * D_801D3A00->unk4) >> 12);
                D_801D3A00->pos.vz = D_801D3A04->pos.vz - ((sv->vz * D_801D3A00->unk4) >> 12);
                break;
            case 5:
                D_801D3A00->unk4 += D_801D3A00->unk8;
                k = func_801B1A60(D_801D3A00->unk4, D_801D3A00->unk28);
                D_801D3A00->pos.vx = D_801D3A00->unk18.vx + ((D_801D3A00->vel.vx * k) >> 12);
                D_801D3A00->pos.vy = D_801D3A00->unk18.vy + ((D_801D3A00->vel.vy * k) >> 12);
                D_801D3A00->pos.vz = D_801D3A00->unk18.vz + ((D_801D3A00->vel.vz * k) >> 12);
                break;
            }
            cam = D_801D3A00;
            D_801D3A00 = &D_801D39D4;
            D_801D3A04 = &D_801D39A8;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801D39A8.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801D39A8.actor == -1) {
                func_8003BC6C(&D_801D39A8.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801D39A8.pos, vec);
                if (D_801D39A8.part != -1) {
                    func_800D3994(D_801D39A8.actor, D_801D39A8.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801D39A8.actor].vx;
                    sv->vy = D_80151A4C[D_801D39A8.actor].vy;
                    sv->vz = D_80151A4C[D_801D39A8.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801D39D4.mode != 9) {
            if (D_801D39D4.actor == -1) {
                func_8003BC6C(&D_801D39D4.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801D39D4.pos, vec);
                if (D_801D39D4.part != -1) {
                    func_800D3994(D_801D39D4.actor, D_801D39D4.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801D39D4.actor].vx;
                    sv->vy = D_80151A4C[D_801D39D4.actor].vy;
                    sv->vz = D_80151A4C[D_801D39D4.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801D39A8.mode != 9) {
            D_80158D00 = D_801D39A8.pos;
        }
        if (D_801D39D4.mode != 9) {
            D_801031E8 = D_801D39D4.pos;
        }
    }
}

void func_801B2B84(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B1B50)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B2BE8(void) {
    MgTask *p;
    s16 n;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    n = p->unk0;
    if (n != -1) {
        if (p->unk2 & 1) {
            D_80158D02[0] += p->unk0;
            D_801031EA[0] += p->unk0;
        } else {
            D_80158D02[0] -= n;
            D_801031EA[0] -= p->unk0;
        }
        if (D_80062D98 == 0) {
            t = p->unk0 - p->unk16;
            p->unk0 = t;
            if (t < 0) {
                p->unk0 = 0;
            }
            p->unk2++;
        }
    }
}

void func_801B2CE0(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        if (D_801D3800 == NULL) {
            D_801D3800 = &D_80162978[func_800BBEAC(&func_801B2BE8)];
        }
        D_801D3800->unk0 = arg0;
        *(s16 *)((u8 *)D_801D3800 + 0x16) = arg1;
        return;
    }
    if (D_801D3800 != NULL) {
        D_801D3800->unk0 = -1;
        D_801D3800 = NULL;
    }
}

void func_801B2D88(TiPos *arg0, u16 *arg1) {
    MgMat *m;
    MgWord *w;
    MgHalf *r;
    MgHalf *r2;
    s32 sp10;
    s32 sp14;

    if (D_801D35B6 == 0) {
        D_801D3828.t0 = -arg0->vx - D_801D3DA0;
        D_801D3828.t1 = -arg0->vz - D_801D3DA8;
        D_801D3828.t2 = arg0->vy;
        m = (MgMat *)((u8 *)&D_801D3828 - 0x14);
    } else {
        D_801D3848.t0 = arg0->vx - D_801D3DA0;
        D_801D3848.t1 = arg0->vz - D_801D3DA8;
        m = (MgMat *)((u8 *)&D_801D3848 - 0x14);
        D_801D3848.t2 = arg0->vy;
    }
    func_80044AC0((s32)D_801D3A08, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, D_801D3A08);
    func_80046794(D_801517C0 + 0x4084, D_801D3854);
    func_8003B64C(&sp10, &sp14);
    func_8003B6BC((s16)arg1[2] / 2, (s16)arg1[3] / 2);
    func_8003B48C(m);
    func_8003B51C(m);
    w = &D_801D3804;
    w->v = D_8016209C;
    D_80163C74 = func_801B0068(w, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B6BC(sp10, sp14);
    r = &D_801D3888;
    r->v = arg1[2];
    D_801D388A = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (u8 *)r - 0xC);
    func_80044978(D_801D3A48, arg1);
    func_80046794(D_801517C0 + 0x4084, D_801D3A48);
    r2 = &D_801D3A60;
    r2->v = arg1[0];
    D_801D3A62 = arg1[1];
    func_800449FC(D_801D3A54, r2);
    func_80046794(D_801517C0 + 0x4084, D_801D3A54);
}

void func_801B3014(void) {
    TiFT4 *p;
    MgTask *t;

    p = D_80163C74;
    t = (MgTask *)&D_80162978[D_8015169C];
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
    p->tpage = 0x10C;
    p->v3 = 0xFF;
    p->u3 = 0xC0;
    func_80046794(D_801517C0 + 0x4084, p);
    D_80163C74 = p + 1;
    t->unk2++;
}

void func_801B30F8(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk14, -0x80);
    frame = &D_801D389C;
    *frame = p->unk2;
    D_80163C74 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C0A2C[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B31B8(void) {
    MgTask *q;
    MgSVec *sv;
    MgVec *vec;
    s32 *flag;
    s32 scale;
    s32 ang;
    s32 i;

    vec = (MgVec *)0x1F800300;
    flag = (s32 *)0x1F800310;
    sv = (MgSVec *)0x1F800314;
    func_8003B48C(&D_801D3D8C);
    func_8003B51C(&D_801D3D8C);
    i = 0;
    *(s16 *)0x1F800316 = 0;
    do {
        i++;
        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B30F8)];
        scale = func_80042DA8() % 1500 + 0x1F4;
        ang = func_80042DA8() & 0xFFF;
        sv->vx = scale * func_80039A74(ang) >> 12;
        sv->vz = scale * func_80039B40(ang) >> 12;
        func_8003BC6C(sv, vec, flag);
        q->unk4 = vec->vx;
        q->unk6 = vec->vy;
        q->unk8 = vec->vz;
        q->unk14 = func_80042DA8() % 0x5000 + 0x3000;
    } while (i < 5);
}

void func_801B3358(void) {
    MgTask *p;
    MgMat *m;
    u8 *s1;
    u8 *s2;
    u8 *s3;
    s32 t;
    s32 i;
    s32 o;

    p = (MgTask *)&D_80162978[D_8015169C];
    m = (MgMat *)0x1F800000;
    if (p->unk2 == 0) {
        for (i = 0; i < 0x65; i++) {
            *(MgB8 *)(D_801D3A64 + i * 8) = *(MgB8 *)(D_801BD4AC + i * 8);
        }
        p->unkC = 0x1000;
        p->unkE = 0x500;
    }
    func_8003A63C(&D_801D3D8C, (M2C_UNK *)D_801D38C0, m);
    func_8003A63C(&D_800FA63C, (M2C_UNK *)m, m);
    t = p->unk2;
    if (t < 0xF) {
        func_8003B48C(m);
        func_8003B51C(m);
        D_80163C74 = func_800D29D4(D_801D38A0, D_801517C0 + 0x70, 0xC, D_80163C74);
    } else {
        t -= 0xF;
        if (t >= 0x3C) {
            p->unk0 = -1;
            return;
        }
        func_8003B69C(0, 0, 0);
        D_80163C74 = func_801B0830(D_801D38A0, D_801517C0 + 0x70, 0xC, D_80163C74, m, D_801D3E18);
        func_8003B48C(m);
        func_8003B51C(m);
        D_80163C74 = func_800D29D4(D_801D38B0, D_801517C0 + 0x406C, 0, D_80163C74);
        func_800D4484(D_801517C0 + 0x406C, 0x40);
    }
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 10) {
            i = 0;
            s3 = D_801BD4AC;
            s2 = D_801BE294;
            s1 = D_801D3A64;
            p->unkC = (u16)p->unkC - (u16)p->unkE;
            p->unkE = (u16)p->unkE - 0x94;
            do {
                func_8003A3AC(s1, s2, p->unkC, 0x1000 - p->unkC, s3);
                s3 += 8;
                s2 += 8;
                s1 += 8;
                i++;
            } while (i < 0x65);
        } else {
            t -= 10;
            if (t >= 5) {
                t -= 5;
                if (t < 0x29) {
                    func_801B31B8();
                }
                if (t < 4) {
                    for (i = t; i < 0xAB; i += 4) {
                        D_801D3E18[i].unk0 = 0x63;
                    }
                }
                for (i = 0; i < 0xAB; i++) {
                    o = i * 0x24;
                    if (D_801D3E18[i].unk0 != 0) {
                        D_801D3E18[i].unk4 += *(u16 *)(D_801D3E24 + o);
                        D_801D3E18[i].unk6 += D_801D3E18[i].unkE;
                        D_801D3E18[i].unk8 += *(u16 *)(D_801D3E28 + o);
                        D_801D3E18[i].unkE += 0x32;
                        D_801D3E18[i].unk14 += *(u16 *)(D_801D3E34 + o);
                        D_801D3E18[i].unk16 += *(u16 *)(D_801D3E34 + 2 + o);
                        D_801D3E18[i].unk18 += *(u16 *)(D_801D3E38 + o);
                        if (D_801D3E18[i].unk0 < 0x1000) {
                            D_801D3E18[i].unk0 += 0x63;
                        }
                    }
                }
            }
        }
        p->unk2++;
    }
}

void func_801B37B0(void) {
    MgTask *p;
    u16 *frame;
    u16 *rot;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D44E8((MgSVec *)&p->unkC, (MgMat *)0x1F800000);
    rot = &D_801D38EC;
    *rot = p->unk16;
    func_8003C21C((MgSVec *)rot, (MgMat *)0x1F800020);
    func_8003B05C((MgMat *)0x1F800000, (MgMat *)0x1F800020);
    ((MgMat *)0x1F800000)->t[0] = p->unk4;
    ((MgMat *)0x1F800000)->t[1] = p->unk6;
    ((MgMat *)0x1F800000)->t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, (MgMat *)0x1F800000, (MgMat *)0x1F800000);
    func_800D461C((MgMat *)0x1F800000);
    ((MgVec *)0x1F800040)->vx = ((MgVec *)0x1F800040)->vy = ((MgVec *)0x1F800040)->vz = p->unk14;
    func_8003B35C((MgMat *)0x1F800000, (MgVec *)0x1F800040);
    func_8003B48C((MgMat *)0x1F800000);
    func_8003B51C((MgMat *)0x1F800000);
    frame = &D_801D38E8;
    *frame = p->unk2;
    D_80163C74 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C0AF4[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B391C(void) {
    MgTask *p;
    MgTask *q;
    MgSVec *e;
    MgSVec *sv;
    MgVec *vec;
    u8 *tbl;
    s32 n;
    s32 i;
    s32 r1;
    u16 x1;
    u16 x2;
    u16 t;
    s32 r2;
    s32 sp10;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        vec = (MgVec *)0x1F800020;
        sv = (MgSVec *)0x1F800030;
        tbl = D_801C06AC;
        n = D_801C06A8 / 8;
        func_8003C21C(&D_801D38F4, (MgMat *)0x1F800000);
        ((MgMat *)0x1F800000)->t[0] = p->unk4;
        ((MgMat *)0x1F800000)->t[1] = p->unk6;
        ((MgMat *)0x1F800000)->t[2] = p->unk8;
        func_8003A63C(&D_801D3D8C, (MgMat *)0x1F800000, (MgMat *)0x1F800000);
        func_8003B35C((MgMat *)0x1F800000, &D_801D38FC);
        i = 0;
        func_8003B48C((MgMat *)0x1F800000);
        func_8003B51C((MgMat *)0x1F800000);
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B37B0)];
            e = (MgSVec *)(tbl + func_80042DA8() % n * 8);
            r1 = func_80042DA8() % 600 - 0x12C;
            x1 = e->vx;
            sv->vy = 0;
            sv->vx = x1 + r1;
            r2 = func_80042DA8() % 600 - 0x12C;
            x2 = e->vz;
            sv->vz = x2 + r2;
            if (D_801D35B6 == 0) {
                t = sv->vx;
                q->unkE = 0;
                q->unkC = t;
                q->unk10 = -sv->vz;
            } else {
                t = sv->vx;
                q->unkE = 0;
                q->unkC = -t;
                q->unk10 = sv->vz;
            }
            func_8003BC6C(sv, vec, &sp10);
            q->unk4 = vec->vx;
            q->unk6 = vec->vy;
            q->unk8 = vec->vz;
            q->unk14 = func_80042DA8() % 0x2800 + 0x2800;
            q->unk16 = -(func_80042DA8() % 0x200 + 0x200);
            i++;
        } while (i < 10);
        p->unk2++;
        if (p->unk2 >= 6) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B3C2C);

void func_801B3E80(MgSVec *arg0, s32 arg1) {
    MgMat *m1;
    MgMat *m2;
    MgSVec *v;
    s16 t;
    s32 i;
    s32 off;
    s32 o8;

    m1 = (MgMat *)0x1F800300;
    m2 = (MgMat *)0x1F800320;
    v = (MgSVec *)0x1F800340;
    func_8003BF3C(&D_801D3D8C, m1);
    func_8003C21C(arg0, m2);
    for (i = 4; i < 10; i++) {
        o8 = i * 8;
        off = i * 0xB9C;
        if (D_801D3DB0 >> i & 1) {
            v->vx = *(u16 *)(D_801D3DB4 + o8) - D_801D3D8C.t[0];
            v->vy = *(u16 *)(D_801D3DB4 + 2 + o8) - D_801D3D8C.t[1];
            v->vz = *(u16 *)(D_801D3DB4 + 4 + o8) - D_801D3D8C.t[2];
            func_8003B2CC(m1, v, v);
            t = v->vz - 0x1388;
            v->vz = t + arg1 * 100;
            if (v->vz < 0) {
                func_8003B2CC(m2, v, v);
                v->vz += 0x1388;
                func_8003B2CC(&D_801D3D8C, v, v);
                *(s16 *)((u8 *)D_80151A4C + off) = v->vx + D_801D3D8C.t[0];
                *(s16 *)((u8 *)D_80151A4C + 2 + off) = v->vy + D_801D3D8C.t[1];
                *(s16 *)((u8 *)D_80151A4C + 4 + off) = v->vz + D_801D3D8C.t[2];
            }
            *(s16 *)((u8 *)D_80151A4C - 8 + off) = arg0->vx;
        }
    }
}

void func_801B40A0(void) {
    MgTask *p;
    MgTask *q;
    MgVec *vec;
    s32 *flag;
    s32 *cnt;
    u8 *tbl;
    s32 n;
    s32 i;

    vec = (MgVec *)0x1F800020;
    flag = (s32 *)0x1F800030;
    cnt = &D_801C06A8;
    p = (MgTask *)&D_80162978[D_8015169C];
    n = *cnt / 8;
    D_801D3930.t0 = p->unk4;
    D_801D3930.t1 = p->unk6;
    D_801D3930.t2 = p->unk8;
    tbl = (u8 *)cnt + 4;
    func_8003A63C(&D_801D3D8C, (MgMat *)((u8 *)&D_801D3930 - 0x14), (MgMat *)0x1F800000);
    func_8003B48C((MgMat *)0x1F800000);
    func_8003B51C((MgMat *)0x1F800000);
    i = 0;
    do {
        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B30F8)];
        func_8003BC6C((MgSVec *)(tbl + func_80042DA8() % n * 8), vec, flag);
        q->unk4 = vec->vx;
        q->unk6 = vec->vy;
        q->unk8 = vec->vz;
        q->unk14 = func_80042DA8() % 0x1000 + 0x2000;
        i++;
    } while (i < 0x1E);
    p->unk0 = -1;
}

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B4244);

void func_801B4910(void) {
    MgTask *p;
    MgTask *q;
    MgTask *r;
    s32 t;
    s32 i;
    s32 off;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 4) {
            if (t == 3) {
                func_801B2D88(D_801D398C, D_801D3984);
            }
            goto end;
        }
        t -= 4;
        if (t < 0xF) {
            if (t == 0) {
                func_800BBEAC((M2C_UNK *)func_801B3358);
                func_801B2CE0(0xA, 0);
                func_800D55F4(0x22, 0x40, 0x149, 0x14A, 0x14B);
            }
            if (t == 10) {
                func_801B2CE0(0, 0);
            }
            goto end;
        }
        t -= 0xF;
        if (t < 0x19) {
            if (t == 0) {
                r = func_800D4FA8(1);
                *(u16 *)((u8 *)r + 4) = D_801D3DA0;
                *(s16 *)((u8 *)r + 6) = 0;
                *(u16 *)((u8 *)r + 8) = D_801D3DA8;
                *(u16 *)((u8 *)r + 0x10) = (u16)D_801D35B6 ^ 0x800;
                func_800D55F4(0x22, 0x40, 0x14C, 0x14D, 0x14E);
            }
            goto end;
        }
        t -= 0x19;
        if (t < 0x14) {
            goto end;
        }
        t -= 0x14;
        if (t < 0xF) {
            if (t == 10) {
                func_801B2CE0(0xA, 0);
            }
            goto end;
        }
        t -= 0xF;
        if (t < 0xA) {
            goto end;
        }
        t -= 0xA;
        if (t < 0xA) {
            if (t == 9) {
                func_801B2D88(D_801D3994, D_801D3984);
            }
            goto end;
        }
        t -= 0xA;
        if (t < 0x1E) {
            if (t == 0) {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B4244)];
                q->unk4 = 0;
                q->unk6 = 0;
                q->unk8 = 0x1388;
            }
            if (t == 10) {
                func_801B2CE0(0, 0);
            }
            goto end;
        }
        t -= 0x1E;
        if (t < 5) {
            goto end;
        }
        t -= 5;
        if (t < 0xF) {
            if (t == 0) {
                func_800D4FA8(2);
                func_800D55F4(0x22, 0x40, 0x14F, 0x150, 0x151);
            }
            goto end;
        }
        t -= 0xF;
        if (t < 0xA) {
            goto end;
        }
        t -= 0xA;
        if (t < 5) {
            goto end;
        }
        t -= 5;
        if (t < 0xF) {
            if (t == 0) {
                for (i = 0; i < 10; i++) {
                    if (D_801D3DB0 >> i & 1) {
                        off = i * 0xB9C;
                        *(MgB8 *)&D_80151A4C[i] = *(MgB8 *)(D_801D3DB4 + i * 8);
                        *(u16 *)((u8 *)D_80151A4C - 8 + off) = 0;
                    }
                }
                func_801B2CE0(0x64, 6);
                func_800D55F4(0x22, 0x40, 0x152, 0x153, 0x154);
            }
            goto end;
        }
        t -= 0x14;
        if (t < 0x14) {
            if (t == 0) {
                i = 0;
                while (1) {
                    if (D_801D3DAC >> i & 1) {
                        func_800D5774(i);
                    }
                    i++;
                    if (i >= 10) {
                        break;
                    }
                }
            }
        } else {
            func_801B2CE0(0, 0);
            D_800F8380 = 0;
            p->unk0 = -1;
        }
end:
        p->unk2++;
    }
}

void func_801B4CC4(void) {
    TiScr *s;
    TiPart *p;
    s16 *src;
    s16 *a;
    s16 *b;
    s16 *c;
    u8 *base;
    s32 i;
    s32 n;

    s = (TiScr *)0x1F800000;
    base = D_801BE294;
    src = (s16 *)&D_801BD4A8[D_801BD4A8[0] / 4 + 1];
    p = D_801D3E18;
    n = *src;
    src += 2;
    for (i = 0; i < n; i++) {
        p->unk4 = p->unk6 = p->unk8 = 0;
        a = (s16 *)(base + src[0]);
        b = (s16 *)(base + src[1]);
        c = (s16 *)(base + src[2]);
        s->a.vx = b[0] - a[0];
        s->a.vy = b[1] - a[1];
        s->a.vz = b[2] - a[2];
        s->b.vx = c[0] - b[0];
        s->b.vy = c[1] - b[1];
        s->b.vz = c[2] - b[2];
        func_8003BA68(&s->a, &s->b, &s->c);
        while (s->c.vx > 0x4000 || s->c.vx < -0x4000 || s->c.vy > 0x4000 || s->c.vy < -0x4000 || s->c.vz > 0x4000 || s->c.vz < -0x4000) {
            s->c.vx >>= 1;
            s->c.vy >>= 1;
            s->c.vz >>= 1;
        }
        func_8003A08C(&s->c, &s->c);
        p->unkC = (u32)(-s->c.vx * 0x19) >> 9;
        src += 8;
        p->unkE = (u32)(-s->c.vy * 0x19) >> 9;
        p->unk10 = (u32)(-s->c.vz * 0x19) >> 9;
        p->unk0 = 0;
        p->unk14 = p->unk16 = p->unk18 = 0;
        p->unk1C = func_80042DA8() & 0xFF;
        p->unk1E = func_80042DA8() & 0xFF;
        p->unk20 = func_80042DA8() & 0xFF;
        p++;
    }
}

void func_801B4F68(void) {
    TiPart *p;
    u16 *e;
    s16 *src;
    u8 *base;
    s32 i;
    s32 n;
    s32 t;

    p = D_801D5624;
    base = D_801BF658;
    src = (s16 *)(D_801BF654 + (s32)base);
    n = *src;
    src += 2;
    for (i = 0; i < n; i++) {
        e = (u16 *)(base + *src);
        p->unk4 = p->unk6 = p->unk8 = 0;
        p->unkC = (s16)e[0] >> 5;
        p->unkE = func_80042DA8() % 190 + 10;
        t = e[2];
        p->unk14 = p->unk16 = p->unk18 = 0;
        p->unk10 = (s16)t >> 5;
        p->unk1C = func_80042DA8() & 0xFF;
        p->unk1E = func_80042DA8() & 0xFF;
        p->unk20 = func_80042DA8() & 0xFF;
        src += 8;
        p->unk0 = 0;
        p++;
    }
    n = *src;
    src += 2;
    for (i = 0; i < n; i++) {
        e = (u16 *)(base + *src);
        p->unk4 = p->unk6 = p->unk8 = 0;
        p->unkC = (s16)e[0] >> 4;
        p->unkE = func_80042DA8() % 190 + 10;
        t = e[2];
        p->unk14 = p->unk16 = p->unk18 = 0;
        p->unk10 = (s16)t >> 4;
        p->unk1C = func_80042DA8() & 0xFF;
        p->unk1E = func_80042DA8() & 0xFF;
        p->unk20 = func_80042DA8() & 0xFF;
        src += 10;
        p->unk0 = 0;
        p++;
    }
}

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B5190);
