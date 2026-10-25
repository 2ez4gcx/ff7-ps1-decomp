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

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B1744);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B1C10);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B1F8C);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B2104);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B21B0);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B2308);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B254C);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B2670);

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

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B28EC);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B29B0);

INCLUDE_ASM("../asm/us/magic_riva/nonmatchings/text", func_801B309C);
