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

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B133C);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B14E8);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B1798);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B1958);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B1C88);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B1E58);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B21F4);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B233C);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B24C4);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B2E1C);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B301C);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B32A0);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B34AC);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B35FC);

INCLUDE_ASM("../asm/us/magic_ifleet/nonmatchings/text", func_801B3BB0);
