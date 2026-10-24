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

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B2BE8);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B2CE0);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B2D88);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B3014);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B30F8);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B31B8);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B3358);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B37B0);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B391C);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B3C2C);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B3E80);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B40A0);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B4244);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B4910);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B4CC4);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B4F68);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B5190);
