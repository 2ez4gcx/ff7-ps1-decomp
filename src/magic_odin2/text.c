#include "common.h"
#include "magic_odin2/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B5264();
    return &D_801DCCD0;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F726E[-v];
    }
    return v;
}

void func_801B00A4(void) {
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
            D_801F1DC0.actor = -1;
            D_801F1DEC.actor = -1;
            D_801F1DC0.frames = 0;
            D_801F1DEC.frames = 0;
            p->unk2 = 1;
        }
        while (D_801F1DC0.frames == 0 || D_801F1DEC.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801F1E18 = &D_801F1DC0;
                D_801F1E1C = &D_801F1DEC;
            } else {
                D_801F1E18 = &D_801F1DEC;
                D_801F1E1C = &D_801F1DC0;
            }
            D_801F1E18->mode = op & 0xFF3F;
            switch (D_801F1E18->mode) {
            case 1:
                D_801F1E18->pos.vx = *p->script++;
                D_801F1E18->pos.vy = *p->script++;
                D_801F1E18->pos.vz = *p->script++;
                break;
            case 2:
                D_801F1E18->frames = func_801B0068(&p->script);
                D_801F1E18->vel.vx = (*p->script++ - D_801F1E18->pos.vx) / D_801F1E18->frames;
                D_801F1E18->vel.vy = (*p->script++ - D_801F1E18->pos.vy) / D_801F1E18->frames;
                D_801F1E18->vel.vz = (*p->script++ - D_801F1E18->pos.vz) / D_801F1E18->frames;
                break;
            case 3:
                sv->vx = D_801F1E1C->pos.vx - D_801F1E18->pos.vx;
                sv->vy = D_801F1E1C->pos.vy - D_801F1E18->pos.vy;
                sv->vz = D_801F1E1C->pos.vz - D_801F1E18->pos.vz;
                D_801F1E18->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801F1E18->unk18 = D_801F1E18->pos;
                D_801F1E18->frames = func_801B0068(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801F1E18->vel.vx = (sv->vx - D_801F1E18->pos.vx) / D_801F1E18->frames;
                D_801F1E18->vel.vy = (sv->vy - D_801F1E18->pos.vy) / D_801F1E18->frames;
                D_801F1E18->vel.vz = (sv->vz - D_801F1E18->pos.vz) / D_801F1E18->frames;
                if (D_801F1E1C->mode == 2) {
                    sv2->vx = D_801F1E1C->pos.vx + D_801F1E1C->vel.vx * D_801F1E1C->frames;
                    sv2->vy = D_801F1E1C->pos.vy + D_801F1E1C->vel.vy * D_801F1E1C->frames;
                    sv2->vz = D_801F1E1C->pos.vz + D_801F1E1C->vel.vz * D_801F1E1C->frames;
                } else {
                    sv2->vx = D_801F1E1C->pos.vx;
                    sv2->vy = D_801F1E1C->pos.vy;
                    sv2->vz = D_801F1E1C->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801F1E18->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801F1E18->unk4) / D_801F1E18->frames;
                break;
            case 4:
                D_801F1E18->frames = func_801B0068(&p->script);
                sv->vx = *p->script++ - D_801F1E18->pos.vx;
                sv->vy = *p->script++ - D_801F1E18->pos.vy;
                sv->vz = *p->script++ - D_801F1E18->pos.vz;
                D_801F1E18->unk18.vx = ((sv->vx - D_801F1E18->vel.vx * D_801F1E18->frames) * 2) / (D_801F1E18->frames * D_801F1E18->frames);
                D_801F1E18->unk18.vy = ((sv->vy - D_801F1E18->vel.vy * D_801F1E18->frames) * 2) / (D_801F1E18->frames * D_801F1E18->frames);
                D_801F1E18->unk18.vz = ((sv->vz - D_801F1E18->vel.vz * D_801F1E18->frames) * 2) / (D_801F1E18->frames * D_801F1E18->frames);
                break;
            case 5:
                D_801F1E18->frames = func_801B0068(&p->script);
                D_801F1E18->unk28 = *p->script++;
                D_801F1E18->unk4 = 0;
                D_801F1E18->unk8 = 0x1000 / D_801F1E18->frames;
                D_801F1E18->unk18.vx = D_801F1E18->pos.vx;
                D_801F1E18->unk18.vy = D_801F1E18->pos.vy;
                D_801F1E18->unk18.vz = D_801F1E18->pos.vz;
                D_801F1E18->vel.vx = *p->script++ - D_801F1E18->pos.vx;
                D_801F1E18->vel.vy = *p->script++ - D_801F1E18->pos.vy;
                D_801F1E18->vel.vz = *p->script++ - D_801F1E18->pos.vz;
                break;
            case 6:
                if ((D_801F1E18->actor = *p->script++) == 0) {
                    D_801F1E18->actor = p->actor;
                }
                D_801F1E18->part = *p->script++;
                break;
            case 7:
                D_801F1E18->actor = -1;
                break;
            case 0:
            case 8:
                D_801F1E18->frames = func_801B0068(&p->script);
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801F1E18 = &D_801F1DC0;
        D_801F1E1C = &D_801F1DEC;
        for (i = 0; i < 2; i++) {
            switch (D_801F1E18->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801F1E18->vel.vx += D_801F1E18->unk18.vx;
                D_801F1E18->vel.vy += D_801F1E18->unk18.vy;
                D_801F1E18->vel.vz += D_801F1E18->unk18.vz;
            case 2:
                D_801F1E18->pos.vx += D_801F1E18->vel.vx;
                D_801F1E18->pos.vy += D_801F1E18->vel.vy;
                D_801F1E18->pos.vz += D_801F1E18->vel.vz;
                break;
            case 3:
                D_801F1E18->unk18.vx += D_801F1E18->vel.vx;
                D_801F1E18->unk18.vy += D_801F1E18->vel.vy;
                D_801F1E18->unk18.vz += D_801F1E18->vel.vz;
                D_801F1E18->unk4 += D_801F1E18->unk8;
                vec->vx = D_801F1E1C->pos.vx - D_801F1E18->unk18.vx;
                vec->vy = D_801F1E1C->pos.vy - D_801F1E18->unk18.vy;
                vec->vz = D_801F1E1C->pos.vz - D_801F1E18->unk18.vz;
                func_8003A078(vec, sv);
                D_801F1E18->pos.vx = D_801F1E1C->pos.vx - ((sv->vx * D_801F1E18->unk4) >> 12);
                D_801F1E18->pos.vy = D_801F1E1C->pos.vy - ((sv->vy * D_801F1E18->unk4) >> 12);
                D_801F1E18->pos.vz = D_801F1E1C->pos.vz - ((sv->vz * D_801F1E18->unk4) >> 12);
                break;
            case 5:
                D_801F1E18->unk4 += D_801F1E18->unk8;
                k = D_801F1E18->unk4;
                for (j = 0; j < D_801F1E18->unk28; j++) {
                    k = func_80039A74(k / 4);
                }
                D_801F1E18->pos.vx = D_801F1E18->unk18.vx + ((D_801F1E18->vel.vx * k) >> 12);
                D_801F1E18->pos.vy = D_801F1E18->unk18.vy + ((D_801F1E18->vel.vy * k) >> 12);
                D_801F1E18->pos.vz = D_801F1E18->unk18.vz + ((D_801F1E18->vel.vz * k) >> 12);
                break;
            }
            cam = D_801F1E18;
            D_801F1E18 = &D_801F1DEC;
            D_801F1E1C = &D_801F1DC0;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801F1DC0.mode != 8) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801F1DC0.actor == -1) {
                func_8003BC6C(&D_801F1DC0.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801F1DC0.pos, vec);
                if (D_801F1DC0.part != -1) {
                    func_800D3994(D_801F1DC0.actor, D_801F1DC0.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801F1DC0.actor].vx;
                    sv->vy = D_80151A4C[D_801F1DC0.actor].vy;
                    sv->vz = D_80151A4C[D_801F1DC0.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801F1DEC.mode != 8) {
            if (D_801F1DEC.actor == -1) {
                func_8003BC6C(&D_801F1DEC.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801F1DEC.pos, vec);
                if (D_801F1DEC.part != -1) {
                    func_800D3994(D_801F1DEC.actor, D_801F1DEC.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801F1DEC.actor].vx;
                    sv->vy = D_80151A4C[D_801F1DEC.actor].vy;
                    sv->vz = D_80151A4C[D_801F1DEC.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801F1DC0.mode != 8) {
            D_80158D00 = D_801F1DC0.pos;
        }
        if (D_801F1DEC.mode != 8) {
            D_801031E8 = D_801F1DEC.pos;
        }
    }
}

void func_801B10E8(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B00A4)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B114C);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B1C40);

MgMat *func_801B2200(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801F1C3C.m[0][0] = D_801F1C3C.m[1][1] = D_801F1C3C.m[2][2] = scale;
    func_8003B48C(&D_801F6238);
    func_8003B51C(&D_801F6238);
    func_8003BC6C(v, (MgVec *)D_801F1C3C.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801F1C3C.t, &n);
        D_801F1C3C.t[0] += (dist * n.vx) >> 12;
        D_801F1C3C.t[1] += (dist * n.vy) >> 12;
        D_801F1C3C.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801F1C3C);
    func_8003B51C(&D_801F1C3C);
    return &D_801F1C3C;
}

MgMat *func_801B231C(MgSVec *v, s32 d, MgMat *m) {
    MgVec n;
    s32 flag;

    func_8003B48C(&D_801F6238);
    func_8003B51C(&D_801F6238);
    func_8003BC6C(v, (MgVec *)m->t, &flag);
    if (d != 0) {
        func_8003A08C((MgVec *)m->t, &n);
        m->t[0] += (d * n.vx) >> 12;
        m->t[1] += (d * n.vy) >> 12;
        m->t[2] += (d * n.vz) >> 12;
    }
    return m;
}

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B2400);

void func_801B25F8(void) {
    MgObj20 *temp_s0;
    s16 temp_v1;
    s32 temp_v1_2;

    temp_s0 = &D_80162978[D_8015169C];
    temp_v1 = temp_s0->unk2;
    if (temp_v1 >= 0x87) {
        temp_v1_2 = temp_v1 - 0x87;
        if (temp_v1_2 >= 0x19) {
            temp_s0->unk0 = -1;
            return;
        }
        if (temp_v1_2 == 0) {
            M2C_FIELD(temp_s0, s16 *, 6) = -0x1324;
            M2C_FIELD(temp_s0, s16 *, 4) = 0;
            M2C_FIELD(temp_s0, s16 *, 8) = -0x1E0C;
        }
        goto block_5;
    }
block_5:
    func_801B2200((MgSVec *)&temp_s0->unk4, 0x2000, 0);
    D_80163C74 = func_800D4D90(&D_801F1C6C, D_801517C0 + 0x406C, 0, D_80163C74);
    if (D_80062D98 == 0) {
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

void func_801B26D0(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    func_8003A63C(&D_801F6238, &D_801F1C88, D_801F1CA8);
    func_8003B48C(D_801F1CA8);
    func_8003B51C(D_801F1CA8);
    D_80163C74 = func_800D29D4(&D_801F1C78, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 >= 0x3C) {
            temp_s0->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B27A8);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B29C8);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B2B20);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B2D88);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B2F70);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B30B4);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B33DC);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B379C);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B3860);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B3A10);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B3B3C);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B3C14);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B3D10);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B3F54);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B4434);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B447C);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B4B98);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B4C38);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B4DD4);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B5264);
