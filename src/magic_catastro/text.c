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

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B0B7C);

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

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B1D00);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B1D7C);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B1E94);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2020);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2278);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B24C8);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B27BC);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2AC4);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2BA4);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2C64);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2D74);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2ECC);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B3184);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B36E4);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B3CF0);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B3E24);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B40C8);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B42A8);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B4538);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B45DC);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B49CC);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B4A34);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B4AB0);
