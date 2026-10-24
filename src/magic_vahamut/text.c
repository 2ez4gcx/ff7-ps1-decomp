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

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B14F8);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B1634);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B1804);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B18F0);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B1C48);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B1D60);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B1DC0);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B1F70);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2170);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2238);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2464);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B25E4);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2810);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2970);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2BEC);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B2DA8);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B31D8);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B37F8);

INCLUDE_ASM("../asm/us/magic_vahamut/nonmatchings/text", func_801B3AB8);
