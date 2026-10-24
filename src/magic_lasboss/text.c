#include "common.h"
#include "magic_lasboss/decls.h"

void func_801B0040(void) {
    func_801B2A50();
}

s32 func_801B0060(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801E6C06[-v];
    }
    return v;
}

s32 func_801B009C(s32 t, s32 s) {
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

void func_801B018C(void) {
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
            D_801D6B78.actor = -1;
            D_801D6BA4.actor = -1;
            D_801D6B78.frames = 0;
            D_801D6BA4.frames = 0;
            p->unk2 = 1;
        }
        while (D_801D6B78.frames == 0 || D_801D6BA4.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801D6BD0 = &D_801D6B78;
                D_801D6BD4 = &D_801D6BA4;
            } else {
                D_801D6BD0 = &D_801D6BA4;
                D_801D6BD4 = &D_801D6B78;
            }
            D_801D6BD0->mode = op & 0xFF3F;
            switch (D_801D6BD0->mode) {
            case 1:
                D_801D6BD0->pos.vx = *p->script++;
                D_801D6BD0->pos.vy = *p->script++;
                D_801D6BD0->pos.vz = *p->script++;
                break;
            case 2:
                D_801D6BD0->frames = func_801B0060(&p->script);
                D_801D6BD0->vel.vx = (*p->script++ - D_801D6BD0->pos.vx) / D_801D6BD0->frames;
                D_801D6BD0->vel.vy = (*p->script++ - D_801D6BD0->pos.vy) / D_801D6BD0->frames;
                D_801D6BD0->vel.vz = (*p->script++ - D_801D6BD0->pos.vz) / D_801D6BD0->frames;
                break;
            case 3:
                sv->vx = D_801D6BD4->pos.vx - D_801D6BD0->pos.vx;
                sv->vy = D_801D6BD4->pos.vy - D_801D6BD0->pos.vy;
                sv->vz = D_801D6BD4->pos.vz - D_801D6BD0->pos.vz;
                D_801D6BD0->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801D6BD0->unk18 = D_801D6BD0->pos;
                D_801D6BD0->frames = func_801B0060(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801D6BD0->vel.vx = (sv->vx - D_801D6BD0->pos.vx) / D_801D6BD0->frames;
                D_801D6BD0->vel.vy = (sv->vy - D_801D6BD0->pos.vy) / D_801D6BD0->frames;
                D_801D6BD0->vel.vz = (sv->vz - D_801D6BD0->pos.vz) / D_801D6BD0->frames;
                if (D_801D6BD4->mode == 2) {
                    sv2->vx = D_801D6BD4->pos.vx + D_801D6BD4->vel.vx * D_801D6BD4->frames;
                    sv2->vy = D_801D6BD4->pos.vy + D_801D6BD4->vel.vy * D_801D6BD4->frames;
                    sv2->vz = D_801D6BD4->pos.vz + D_801D6BD4->vel.vz * D_801D6BD4->frames;
                } else {
                    sv2->vx = D_801D6BD4->pos.vx;
                    sv2->vy = D_801D6BD4->pos.vy;
                    sv2->vz = D_801D6BD4->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801D6BD0->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801D6BD0->unk4) / D_801D6BD0->frames;
                break;
            case 4:
                D_801D6BD0->frames = func_801B0060(&p->script);
                sv->vx = *p->script++ - D_801D6BD0->pos.vx;
                sv->vy = *p->script++ - D_801D6BD0->pos.vy;
                sv->vz = *p->script++ - D_801D6BD0->pos.vz;
                D_801D6BD0->unk18.vx = ((sv->vx - D_801D6BD0->vel.vx * D_801D6BD0->frames) * 2) / (D_801D6BD0->frames * D_801D6BD0->frames);
                D_801D6BD0->unk18.vy = ((sv->vy - D_801D6BD0->vel.vy * D_801D6BD0->frames) * 2) / (D_801D6BD0->frames * D_801D6BD0->frames);
                D_801D6BD0->unk18.vz = ((sv->vz - D_801D6BD0->vel.vz * D_801D6BD0->frames) * 2) / (D_801D6BD0->frames * D_801D6BD0->frames);
                break;
            case 5:
                D_801D6BD0->frames = func_801B0060(&p->script);
                D_801D6BD0->unk28 = *p->script++;
                D_801D6BD0->unk4 = 0;
                D_801D6BD0->unk8 = 0x1000 / D_801D6BD0->frames;
                D_801D6BD0->unk18.vx = D_801D6BD0->pos.vx;
                D_801D6BD0->unk18.vy = D_801D6BD0->pos.vy;
                D_801D6BD0->unk18.vz = D_801D6BD0->pos.vz;
                D_801D6BD0->vel.vx = *p->script++ - D_801D6BD0->pos.vx;
                D_801D6BD0->vel.vy = *p->script++ - D_801D6BD0->pos.vy;
                D_801D6BD0->vel.vz = *p->script++ - D_801D6BD0->pos.vz;
                break;
            case 6:
                if ((D_801D6BD0->actor = *p->script++) == 0) {
                    D_801D6BD0->actor = p->actor;
                }
                D_801D6BD0->part = *p->script++;
                break;
            case 7:
                D_801D6BD0->actor = -1;
                break;
            case 0:
            case 9:
                D_801D6BD0->frames = func_801B0060(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801D6BD0 = &D_801D6B78;
        D_801D6BD4 = &D_801D6BA4;
        for (i = 0; i < 2; i++) {
            switch (D_801D6BD0->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801D6BD0->vel.vx += D_801D6BD0->unk18.vx;
                D_801D6BD0->vel.vy += D_801D6BD0->unk18.vy;
                D_801D6BD0->vel.vz += D_801D6BD0->unk18.vz;
            case 2:
                D_801D6BD0->pos.vx += D_801D6BD0->vel.vx;
                D_801D6BD0->pos.vy += D_801D6BD0->vel.vy;
                D_801D6BD0->pos.vz += D_801D6BD0->vel.vz;
                break;
            case 3:
                D_801D6BD0->unk18.vx += D_801D6BD0->vel.vx;
                D_801D6BD0->unk18.vy += D_801D6BD0->vel.vy;
                D_801D6BD0->unk18.vz += D_801D6BD0->vel.vz;
                D_801D6BD0->unk4 += D_801D6BD0->unk8;
                vec->vx = D_801D6BD4->pos.vx - D_801D6BD0->unk18.vx;
                vec->vy = D_801D6BD4->pos.vy - D_801D6BD0->unk18.vy;
                vec->vz = D_801D6BD4->pos.vz - D_801D6BD0->unk18.vz;
                func_8003A078(vec, sv);
                D_801D6BD0->pos.vx = D_801D6BD4->pos.vx - ((sv->vx * D_801D6BD0->unk4) >> 12);
                D_801D6BD0->pos.vy = D_801D6BD4->pos.vy - ((sv->vy * D_801D6BD0->unk4) >> 12);
                D_801D6BD0->pos.vz = D_801D6BD4->pos.vz - ((sv->vz * D_801D6BD0->unk4) >> 12);
                break;
            case 5:
                D_801D6BD0->unk4 += D_801D6BD0->unk8;
                k = func_801B009C(D_801D6BD0->unk4, D_801D6BD0->unk28);
                D_801D6BD0->pos.vx = D_801D6BD0->unk18.vx + ((D_801D6BD0->vel.vx * k) >> 12);
                D_801D6BD0->pos.vy = D_801D6BD0->unk18.vy + ((D_801D6BD0->vel.vy * k) >> 12);
                D_801D6BD0->pos.vz = D_801D6BD0->unk18.vz + ((D_801D6BD0->vel.vz * k) >> 12);
                break;
            }
            cam = D_801D6BD0;
            D_801D6BD0 = &D_801D6BA4;
            D_801D6BD4 = &D_801D6B78;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801D6B78.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801D6B78.actor == -1) {
                func_8003BC6C(&D_801D6B78.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801D6B78.pos, vec);
                if (D_801D6B78.part != -1) {
                    func_800D3994(D_801D6B78.actor, D_801D6B78.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801D6B78.actor].vx;
                    sv->vy = D_80151A4C[D_801D6B78.actor].vy;
                    sv->vz = D_80151A4C[D_801D6B78.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801D6BA4.mode != 9) {
            if (D_801D6BA4.actor == -1) {
                func_8003BC6C(&D_801D6BA4.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801D6BA4.pos, vec);
                if (D_801D6BA4.part != -1) {
                    func_800D3994(D_801D6BA4.actor, D_801D6BA4.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801D6BA4.actor].vx;
                    sv->vy = D_80151A4C[D_801D6BA4.actor].vy;
                    sv->vz = D_80151A4C[D_801D6BA4.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801D6B78.mode != 9) {
            D_80158D00 = D_801D6B78.pos;
        }
        if (D_801D6BA4.mode != 9) {
            D_801031E8 = D_801D6BA4.pos;
        }
    }
}

void func_801B11C0(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B018C)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B1224(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801E6BD8 = D_801D6AB0[p->unk2];
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1288);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1344);

void func_801B141C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D6ACC;
    *frame = p->unk2;
    D_801E6BD8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E6BD8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D5EA8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B14D4);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1620);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1A1C);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1B6C);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1C60);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1D88);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1F04);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B2098);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B21C8);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B22EC);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B2A50);
