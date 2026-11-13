#include "common.h"
#include "magic_catastro/decls.h"

M2C_UNK *func_801B0058(void) {
    func_801B4AB0();
    return &D_801C6C08;
}

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B0080);

s32 func_801B0B40(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801D88F2[-v];
    }
    return v;
}

s32 func_801B0B7C(s32 arg0, s32 arg1) {
    s32 n;
    s32 i;
    s32 orig;

    n = arg1 >> 8;
    orig = arg0;
    if (n > 0) {
        for (i = 0; i < n; i++) {
            arg0 = func_80039A74(arg0 / 4);
        }
    } else {
        arg0 = 0x1000 - arg0;
        for (i = 0; i < -n; i++) {
            arg0 = func_80039A74(arg0 / 4);
        }
        arg0 = 0x1000 - arg0;
    }
    i = orig;
    n = arg1 & 0xFF;
    return (arg0 * n + i * (0x100 - n)) >> 8;
}

void func_801B0C68(void) {
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
            D_801C872C.actor = -1;
            D_801C8758.actor = -1;
            D_801C872C.frames = 0;
            D_801C8758.frames = 0;
            p->unk2 = 1;
        }
        while (D_801C872C.frames == 0 || D_801C8758.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801C8784 = &D_801C872C;
                D_801C8788 = &D_801C8758;
            } else {
                D_801C8784 = &D_801C8758;
                D_801C8788 = &D_801C872C;
            }
            D_801C8784->mode = op & 0xFF3F;
            switch (D_801C8784->mode) {
            case 1:
                D_801C8784->pos.vx = *p->script++;
                D_801C8784->pos.vy = *p->script++;
                D_801C8784->pos.vz = *p->script++;
                break;
            case 2:
                D_801C8784->frames = func_801B0B40(&p->script);
                D_801C8784->vel.vx = (*p->script++ - D_801C8784->pos.vx) / D_801C8784->frames;
                D_801C8784->vel.vy = (*p->script++ - D_801C8784->pos.vy) / D_801C8784->frames;
                D_801C8784->vel.vz = (*p->script++ - D_801C8784->pos.vz) / D_801C8784->frames;
                break;
            case 3:
                sv->vx = D_801C8788->pos.vx - D_801C8784->pos.vx;
                sv->vy = D_801C8788->pos.vy - D_801C8784->pos.vy;
                sv->vz = D_801C8788->pos.vz - D_801C8784->pos.vz;
                D_801C8784->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801C8784->unk18 = D_801C8784->pos;
                D_801C8784->frames = func_801B0B40(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801C8784->vel.vx = (sv->vx - D_801C8784->pos.vx) / D_801C8784->frames;
                D_801C8784->vel.vy = (sv->vy - D_801C8784->pos.vy) / D_801C8784->frames;
                D_801C8784->vel.vz = (sv->vz - D_801C8784->pos.vz) / D_801C8784->frames;
                if (D_801C8788->mode == 2) {
                    sv2->vx = D_801C8788->pos.vx + D_801C8788->vel.vx * D_801C8788->frames;
                    sv2->vy = D_801C8788->pos.vy + D_801C8788->vel.vy * D_801C8788->frames;
                    sv2->vz = D_801C8788->pos.vz + D_801C8788->vel.vz * D_801C8788->frames;
                } else {
                    sv2->vx = D_801C8788->pos.vx;
                    sv2->vy = D_801C8788->pos.vy;
                    sv2->vz = D_801C8788->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801C8784->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801C8784->unk4) / D_801C8784->frames;
                break;
            case 4:
                D_801C8784->frames = func_801B0B40(&p->script);
                sv->vx = *p->script++ - D_801C8784->pos.vx;
                sv->vy = *p->script++ - D_801C8784->pos.vy;
                sv->vz = *p->script++ - D_801C8784->pos.vz;
                D_801C8784->unk18.vx = ((sv->vx - D_801C8784->vel.vx * D_801C8784->frames) * 2) / (D_801C8784->frames * D_801C8784->frames);
                D_801C8784->unk18.vy = ((sv->vy - D_801C8784->vel.vy * D_801C8784->frames) * 2) / (D_801C8784->frames * D_801C8784->frames);
                D_801C8784->unk18.vz = ((sv->vz - D_801C8784->vel.vz * D_801C8784->frames) * 2) / (D_801C8784->frames * D_801C8784->frames);
                break;
            case 5:
                D_801C8784->frames = func_801B0B40(&p->script);
                D_801C8784->unk28 = *p->script++;
                D_801C8784->unk4 = 0;
                D_801C8784->unk8 = 0x1000 / D_801C8784->frames;
                D_801C8784->unk18.vx = D_801C8784->pos.vx;
                D_801C8784->unk18.vy = D_801C8784->pos.vy;
                D_801C8784->unk18.vz = D_801C8784->pos.vz;
                D_801C8784->vel.vx = *p->script++ - D_801C8784->pos.vx;
                D_801C8784->vel.vy = *p->script++ - D_801C8784->pos.vy;
                D_801C8784->vel.vz = *p->script++ - D_801C8784->pos.vz;
                break;
            case 6:
                if ((D_801C8784->actor = *p->script++) == 0) {
                    D_801C8784->actor = p->actor;
                }
                D_801C8784->part = *p->script++;
                break;
            case 7:
                D_801C8784->actor = -1;
                break;
            case 0:
            case 9:
                D_801C8784->frames = func_801B0B40(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801C8784 = &D_801C872C;
        D_801C8788 = &D_801C8758;
        for (i = 0; i < 2; i++) {
            switch (D_801C8784->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801C8784->vel.vx += D_801C8784->unk18.vx;
                D_801C8784->vel.vy += D_801C8784->unk18.vy;
                D_801C8784->vel.vz += D_801C8784->unk18.vz;
            case 2:
                D_801C8784->pos.vx += D_801C8784->vel.vx;
                D_801C8784->pos.vy += D_801C8784->vel.vy;
                D_801C8784->pos.vz += D_801C8784->vel.vz;
                break;
            case 3:
                D_801C8784->unk18.vx += D_801C8784->vel.vx;
                D_801C8784->unk18.vy += D_801C8784->vel.vy;
                D_801C8784->unk18.vz += D_801C8784->vel.vz;
                D_801C8784->unk4 += D_801C8784->unk8;
                vec->vx = D_801C8788->pos.vx - D_801C8784->unk18.vx;
                vec->vy = D_801C8788->pos.vy - D_801C8784->unk18.vy;
                vec->vz = D_801C8788->pos.vz - D_801C8784->unk18.vz;
                func_8003A078(vec, sv);
                D_801C8784->pos.vx = D_801C8788->pos.vx - ((sv->vx * D_801C8784->unk4) >> 12);
                D_801C8784->pos.vy = D_801C8788->pos.vy - ((sv->vy * D_801C8784->unk4) >> 12);
                D_801C8784->pos.vz = D_801C8788->pos.vz - ((sv->vz * D_801C8784->unk4) >> 12);
                break;
            case 5:
                D_801C8784->unk4 += D_801C8784->unk8;
                k = func_801B0B7C(D_801C8784->unk4, D_801C8784->unk28);
                D_801C8784->pos.vx = D_801C8784->unk18.vx + ((D_801C8784->vel.vx * k) >> 12);
                D_801C8784->pos.vy = D_801C8784->unk18.vy + ((D_801C8784->vel.vy * k) >> 12);
                D_801C8784->pos.vz = D_801C8784->unk18.vz + ((D_801C8784->vel.vz * k) >> 12);
                break;
            }
            cam = D_801C8784;
            D_801C8784 = &D_801C8758;
            D_801C8788 = &D_801C872C;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801C872C.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801C872C.actor == -1) {
                func_8003BC6C(&D_801C872C.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801C872C.pos, vec);
                if (D_801C872C.part != -1) {
                    func_800D3994(D_801C872C.actor, D_801C872C.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801C872C.actor].vx;
                    sv->vy = D_80151A4C[D_801C872C.actor].vy;
                    sv->vz = D_80151A4C[D_801C872C.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801C8758.mode != 9) {
            if (D_801C8758.actor == -1) {
                func_8003BC6C(&D_801C8758.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801C8758.pos, vec);
                if (D_801C8758.part != -1) {
                    func_800D3994(D_801C8758.actor, D_801C8758.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801C8758.actor].vx;
                    sv->vy = D_80151A4C[D_801C8758.actor].vy;
                    sv->vz = D_80151A4C[D_801C8758.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801C872C.mode != 9) {
            D_80158D00 = D_801C872C.pos;
        }
        if (D_801C8758.mode != 9) {
            D_801031E8 = D_801C8758.pos;
        }
    }
}

void func_801B1C9C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B0C68)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B1D00(void) {
    MgObj20 *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (!(p->unk2 & 1)) {
            D_800FA666.v = -0x64;
        } else {
            D_800FA666.v = 0x64;
        }
        t = p->unk2 + 1;
        p->unk2 = t;
        if (t >= 0x64) {
            D_800FA664.v = 0;
            p->unk0 = -1;
        }
    }
}

void func_801B1D7C(void) {
    MgTask *p;
    s16 t;
    s32 n;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 3) {
        D_801C85DE = 0;
        k = (t << 13) / 3;
    } else {
        n = t - 3;
        if (n < 5) {
            D_801C85DE = (n << 12) / 5;
            k = 0x2000;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_800D4368(&p->unk4, k, 0);
    D_80163C74 = func_800D29D4(&D_801C85D4, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_RODATA("../asm/us/magic_catastro/nonmatchings/text", D_801B0040);

s32 func_801B1E94(MgSVec *a, MgSVec *b, MgMat *m) {
    MgVec x;
    MgVec up;
    MgVec z;
    s32 len;

    up = D_801B0040;
    up.vx = b->vx - a->vx;
    up.vy = b->vy - a->vy;
    up.vz = b->vz - a->vz;
    len = func_80039F5C(func_8003A08C(&up, &up));
    x.vx = up.vy;
    x.vy = -up.vx;
    x.vz = 0;
    func_8003A08C(&x, &x);
    func_8003BA10(&x, &up, &z);
    func_8003A08C(&z, &z);
    m->m[0][0] = x.vx;
    m->m[1][0] = x.vy;
    m->m[2][0] = x.vz;
    m->m[0][1] = up.vx;
    m->m[1][1] = up.vy;
    m->m[2][1] = up.vz;
    m->m[0][2] = z.vx;
    m->m[1][2] = z.vy;
    m->m[2][2] = z.vz;
    m->t[0] = a->vx;
    m->t[1] = a->vy;
    m->t[2] = a->vz;
    return len;
}

void func_801B2020(MgSVec *arg0, u16 *arg1) {
    s32 sp10;
    s32 sp14;
    s32 *t;
    MgMat *m;
    MgWord *w;

    t = &D_801C8608;
    *t = -arg0->vz / 4;
    D_801C860C = -arg0->vx / 4;
    D_801C8610 = arg0->vy;
    func_80044AC0((s32)D_801C878C, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801C878C);
    func_8003B64C(&sp10, &sp14);
    func_8003B6BC((s16)arg1[2] / 2, (s16)arg1[3] / 2);
    m = (MgMat *)(t - 5);
    func_8003B48C(m);
    func_8003B51C(m);
    w = &D_801C85E4;
    w->v = D_8016209C;
    D_801C85EE = D_800F5B74;
    func_8003B69C(D_800F5B70, D_800F5B71, D_800F5B72);
    D_80163C74 = func_801B0080(w, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B6BC(sp10, sp14);
    D_801C8620.v = arg1[2];
    D_801C8622 = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)&D_801C8620 - 0xC));
    func_80044978(D_801C87CC, arg1);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801C87CC);
    D_801C87E4.v = arg1[0];
    D_801C87E6 = arg1[1];
    func_800449FC(D_801C87D8, &D_801C87E4);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801C87D8);
}

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2278);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B24C8);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B27BC);

INCLUDE_RODATA("../asm/us/magic_catastro/nonmatchings/text", D_801B0050);

void func_801B2AC4(void) {
    MgB8 m;
    u8 pad[8];
    MgObj20 *p;

    m = D_801B0050;
    p = &D_80162978[D_8015169C];
    if (p->unk2 == 0) {
        D_801C8650[0] = D_801D8898;
        func_801B2278(&D_801C8650[-2], &m);
        D_801C864E = 0;
    }
    func_801B24C8(D_801C864C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x8A) {
            p->unk0 = -1;
        }
    }
}

void func_801B2BA4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x5000, 0);
    D_801C865C[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801C865C[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C6A1C[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B2C64(void) {
    MgTask *p;
    MgMat *m;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    m = func_800D4368(&p->unk4, p->unk14, 0);
    frame = &D_801C8668;
    *frame = p->unk2;
    if (m->t[2] > 0) {
        func_800D4484(D_801517C0 + 0x70 + (m->t[2] >> 4) * 4, 0x20);
        D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C68F4[0]) {
            p->unk0 = -1;
        } else {
            p->unk6 -= p->unkE;
        }
    }
}

void func_801B2D74(void) {
    MgObj20 *p;
    s32 t;
    s32 v;
    s16 *frame;

    p = &D_80162978[D_8015169C];
    t = (p->unk2 << 12) / 10;
    frame = &D_801C8676;
    v = t * 0x3000 >> 12;
    D_801C869C->v.vx = D_801C869C->v.vy = D_801C869C->v.vz = v;
    *frame = t;
    func_8003A63C(D_800FA6E0 + (D_801C8824 << 6), &D_801C867C, &D_801C869C->mat);
    func_8003B35C(&D_801C869C->mat, &D_801C869C->v);
    func_8003B48C(&D_801C869C->mat);
    func_8003B51C(&D_801C869C->mat);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4((M2C_UNK *)((u8 *)frame - 0xA), D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B2ECC(void) {
    MgTask *p;
    s32 t;
    s32 w;
    u8 *q;
    CatSeg *s;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 3) {
        D_801C86A0->v0.vx = p->unk4;
        D_801C86A0->v0.vy = p->unk6;
        D_801C86A0->v0.vz = p->unk8;
        w = (t << 12) / 3;
        D_801C86A0->v1.vx = p->unk4 + ((p->unkC - p->unk4) * w >> 12);
        D_801C86A0->v1.vy = p->unk6 + ((p->unkE - p->unk6) * w >> 12);
        D_801C86A0->v1.vz = p->unk8 + ((p->unk10 - p->unk8) * w >> 12);
    } else {
        t -= 3;
        if (t < 3) {
            w = 0x1000 - (t << 12) / 3;
            D_801C86A0->v0.vx = p->unk4 + ((p->unkC - p->unk4) * w >> 12);
            D_801C86A0->v0.vy = p->unk6 + ((p->unkE - p->unk6) * w >> 12);
            D_801C86A0->v0.vz = p->unk8 + ((p->unk10 - p->unk8) * w >> 12);
            D_801C86A0->v1.vx = p->unkC;
            D_801C86A0->v1.vy = p->unkE;
            D_801C86A0->v1.vz = p->unk10;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    q = D_80163C74;
    func_8003B48C(&D_801D885C);
    func_8003B51C(&D_801D885C);
    s = D_801C86A0;
    r = func_8003BC0C(&s->v0, &s->v1, &s->v1, q + 8, q + 0xC, q + 0xC, &s->unk34, &s->unk38);
    s = D_801C86A0;
    s->unk30 = r;
    if (!(s->unk38 & 0x60000)) {
        *(s32 *)q = 0x03000000;
        *(s32 *)(q + 4) = 0x40FFFFFF;
        func_80046794(D_801517C0 + 0x70 + (s->unk30 >> 2) * 4, (s32)q);
        D_80163C74 = q + 0x10;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B3184);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B36E4);

void func_801B3CF0(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk14, 0);
    frame = &D_801C86FC;
    *frame = p->unk2;
    D_801D8838 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D8838);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C68F4[0]) {
            p->unk0 = -1;
        } else {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unkC = p->unkC * 5 >> 3;
            p->unkE = (p->unkE * 5 >> 3) - 10;
            p->unk10 = p->unk10 * 5 >> 3;
        }
    }
}

void func_801B3E24(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 w;
    s32 r;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B3CF0)];
            D_801C870C->vx = D_801C8830.vx;
            D_801C870C->vy = D_801C8830.vy;
            D_801C870C->vz = D_801C8830.vz;
            if (p->unk2 != 0) {
                w = (i << 12) / 4;
                D_801C870C->vx = (D_801C8700.vx * w + D_801C870C->vx * (0x1000 - w)) >> 12;
                D_801C870C->vy = (D_801C8700.vy * w + D_801C870C->vy * (0x1000 - w)) >> 12;
                D_801C870C->vz = (D_801C8700.vz * w + D_801C870C->vz * (0x1000 - w)) >> 12;
            }
            q->unk4 = D_801C870C->vx;
            q->unk6 = D_801C870C->vy;
            q->unk8 = D_801C870C->vz;
            r = func_80042DA8() % 100 + 0x32;
            k = func_80042DA8() & 0xFFF;
            q->unkC = r * func_80039A74(k) >> 12;
            q->unkE = 0;
            q->unk10 = r * func_80039B40(k) >> 12;
            q->unk14 = func_80042DA8() % 0x800 + 0x800;
            i++;
        } while (i < 4);
        D_801C8700.vx = q->unk4;
        D_801C8700.vy = q->unk6;
        D_801C8700.vz = q->unk8;
        p->unk2++;
        if (p->unk2 >= 0x23) {
            p->unk0 = -1;
        }
    }
}

void func_801B40C8(void) {
    MgObj20 *p;
    s32 i;
    s32 r1;
    s32 r2;
    s32 r3;
    s32 k;
    s16 x;
    s16 z;
    s16 w;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            r1 = func_80042DA8();
            k = 0x1F4;
            x = (u16)D_80151A4C[D_801C8824].vx - k + r1 % 1000;
            D_801C8710->vx = x;
            D_801C8710->vy = D_80151A4C[D_801C8824].vy + 0x64;
            r2 = func_80042DA8();
            z = (u16)D_80151A50[D_801C8824][0] - k + r2 % 1000;
            D_801C8710->vz = z;
            r3 = func_80042DA8();
            w = r3 % 0x800 + 0x1000;
            func_800D3F0C(D_801C8710, w, w);
            i++;
        } while (i < 2);
        p->unk2++;
        if (p->unk2 >= 4) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B42A8(void) {
    MgTask *p;
    s32 t;
    s32 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        n = t + 1;
        if (n >= 0x36) {
            n = t - 0x35;
            if (n < 0xA) {
                if (n == 0) {
                    func_800BBEAC(&func_801B40C8);
                }
                D_80151A4C[D_801C8824].vy = n * n * 100 - n * 2000;
            } else {
                n = t - 0x3F;
                if (n >= 0x13) {
                    n = t - 0x52;
                    if (n < 0x73) {
                        if (n == 0x31) {
                            D_8015120C[D_801C8824].unk0 |= 2;
                        } else if (n == 0x72) {
                            D_8015120C[D_801C8824].unk0 &= ~2;
                        }
                    } else {
                        n = t - 0xC5;
                        if (n >= 0xA) {
                            func_800BBEAC(&func_801B40C8);
                            D_80151A4C[D_801C8824].vy = 0;
                            p->unk0 = -1;
                            return;
                        }
                        D_80151A4C[D_801C8824].vy = n * n * 100 - 0x2710;
                    }
                }
            }
        }
        p->unk2++;
    }
}

void func_801B4538(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_800D5138(4);
        }
        if (p->unk2 == 4) {
            D_800F5B74 = 0;
        }
        if (p->unk2 == 5) {
            func_800D51D4(5);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B45DC(void) {
    MgTask *p;
    MgTask *q;
    u16 *r;
    s32 t;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D41FC(D_800FA63C, D_800FA6E0 + (D_801C8824 << 6), D_801C8720);
    func_8003B2CC(D_801C8720, D_801C8714, &D_801C8830);
    D_801C8830.vx += D_801C8720->t[0];
    D_801C8830.vy += D_801C8720->t[1];
    D_801C8830.vz += D_801C8720->t[2];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x36) {
            if (t == 0) {
                D_800F5B70 = 0x40;
                D_800F5B71 = 0x10;
                D_800F5B72 = 0;
                func_800D52A0(0x500, 0xA);
            }
            if (t == 0x1E) {
                func_800BBEAC(func_801B3E24);
                func_800D55F4(0x20, func_800D56A8(&D_80151A4C[D_801C8824]), 0x18C);
            }
        } else {
            t -= 0x36;
            if (t >= 0xA) {
                t -= 0xA;
                if (t < 0x13) {
                    if (t == 0) {
                        D_801C881C = &D_80162978[func_800BBEAC(func_801B2AC4)];
                    }
                } else {
                    t -= 0x13;
                    if (t < 0x73) {
                        if (t == 0) {
                            func_800BBEAC(func_801B36E4);
                            q = &D_80162978[func_800BBEAC(func_801B1D7C)];
                            *(MgB8 *)&q->unk4 = *(MgB8 *)&D_801C8830;
                            func_800D55F4(0x20, func_800D56A8(&D_801C8830), 0x182);
                        }
                        if (t == 0xF) {
                            func_800BBEAC(func_801B1D00);
                        }
                        if (t >= 0xF) {
                            t -= 0xF;
                            if (t % 9 == 4) {
                                if (D_801C871C < 10) {
                                    r = func_800D4FA8(10);
                                    k = D_801C871C;
                                    r[0] = *(u16 *)(D_801D88CC + (k << 2));
                                    r[8] = *(u16 *)(D_801D88CC + 2 + (k << 2));
                                    D_801C871C = k + 1;
                                }
                            }
                        }
                    } else {
                        t -= 0x73;
                        if (t < 10) {
                            if (t == 0) {
                                func_800BBEAC(func_801B4538);
                            }
                        } else {
                            t -= 10;
                            if (t < 10) {
                                if (t == 0) {
                                    func_800D55F4(0x20, func_800D56A8(&D_80151A4C[D_801C8824]), 0x38);
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
        p->unk2++;
    }
}

void func_801B49CC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D8838 = D_801C8838 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
        D_800FAFDC = 0;
    }
}

void func_801B4A34(void) {
    s32 i;
    s32 j;
    s32 n;
    s32 k;

    n = 0;
    for (i = 0; i < 10; i++) {
        j = 0;
        k = n * 4;
        for (; j < 10; j++) {
            if (D_801517F0[j] == i) {
                *(s16 *)(D_801D88CC + k) = i;
                *(s16 *)(D_801D88CC + 2 + k) = j;
                k += 4;
                n++;
            }
        }
    }
}

void func_801B4AB0(arg0, arg1) {
    MgTask *p;
    s32 k;

    func_800D2980(&D_801B4CD4, 0, 0, 0);
    func_800BBEAC(&func_801B49CC);
    D_801C8820 = arg0;
    D_801C8824 = arg1;
    func_800D54EC(arg0, &D_801C8828);
    if (D_801C882C < D_80151A50[arg1][0]) {
        D_801C8724.vy = 0x800;
    }
    func_8003C21C(&D_801C8724, &D_801D887C);
    D_801D8890 = 0;
    D_801D8894 = 0;
    *(s32 *)&D_801D8898 = D_801C882C;
    k = 0x5A / func_800D54BC(arg0);
    D_801D88C8 = k;
    D_801D88C4 = k / 2;
    D_801D88C0 = k - k / 2;
    func_801B4A34();
    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B45DC)];
    *(MgB8 *)&p->unk4 = D_801C8828;
    func_800BBEAC(&func_801B42A8);
    ((void (*)(s32, s32, s32))func_801B1C9C)((s32)&D_801C8518, (s32)&D_801D887C, arg1);
    D_800FAFDC = 1;
    D_800F8380 |= 8;
}
