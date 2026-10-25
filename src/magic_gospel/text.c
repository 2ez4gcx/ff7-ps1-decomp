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

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B1294);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B130C);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B1404);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B15D4);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B179C);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B1890);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B1A48);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B1C6C);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B22E8);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B2418);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B252C);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B2620);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B286C);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B2A2C);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B2B38);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B2D34);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B2F00);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B3034);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B31BC);

void func_801B3394(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B31BC)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B3414);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B38A8);

INCLUDE_ASM("../asm/us/magic_gospel/nonmatchings/text", func_801B3914);
