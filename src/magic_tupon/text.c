#include "common.h"
#include "magic_tupon/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B64C8();
    return &D_801D90DC;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801EDE2E[-v];
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
            D_801EDD34.actor = -1;
            D_801EDD60.actor = -1;
            D_801EDD34.frames = 0;
            D_801EDD60.frames = 0;
            p->unk2 = 1;
        }
        while (D_801EDD34.frames == 0 || D_801EDD60.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801EDD8C = &D_801EDD34;
                D_801EDD90 = &D_801EDD60;
            } else {
                D_801EDD8C = &D_801EDD60;
                D_801EDD90 = &D_801EDD34;
            }
            D_801EDD8C->mode = op & 0xFF3F;
            switch (D_801EDD8C->mode) {
            case 1:
                D_801EDD8C->pos.vx = *p->script++;
                D_801EDD8C->pos.vy = *p->script++;
                D_801EDD8C->pos.vz = *p->script++;
                break;
            case 2:
                D_801EDD8C->frames = func_801B0068(&p->script);
                D_801EDD8C->vel.vx = (*p->script++ - D_801EDD8C->pos.vx) / D_801EDD8C->frames;
                D_801EDD8C->vel.vy = (*p->script++ - D_801EDD8C->pos.vy) / D_801EDD8C->frames;
                D_801EDD8C->vel.vz = (*p->script++ - D_801EDD8C->pos.vz) / D_801EDD8C->frames;
                break;
            case 3:
                sv->vx = D_801EDD90->pos.vx - D_801EDD8C->pos.vx;
                sv->vy = D_801EDD90->pos.vy - D_801EDD8C->pos.vy;
                sv->vz = D_801EDD90->pos.vz - D_801EDD8C->pos.vz;
                D_801EDD8C->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801EDD8C->unk18 = D_801EDD8C->pos;
                D_801EDD8C->frames = func_801B0068(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801EDD8C->vel.vx = (sv->vx - D_801EDD8C->pos.vx) / D_801EDD8C->frames;
                D_801EDD8C->vel.vy = (sv->vy - D_801EDD8C->pos.vy) / D_801EDD8C->frames;
                D_801EDD8C->vel.vz = (sv->vz - D_801EDD8C->pos.vz) / D_801EDD8C->frames;
                if (D_801EDD90->mode == 2) {
                    sv2->vx = D_801EDD90->pos.vx + D_801EDD90->vel.vx * D_801EDD90->frames;
                    sv2->vy = D_801EDD90->pos.vy + D_801EDD90->vel.vy * D_801EDD90->frames;
                    sv2->vz = D_801EDD90->pos.vz + D_801EDD90->vel.vz * D_801EDD90->frames;
                } else {
                    sv2->vx = D_801EDD90->pos.vx;
                    sv2->vy = D_801EDD90->pos.vy;
                    sv2->vz = D_801EDD90->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801EDD8C->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801EDD8C->unk4) / D_801EDD8C->frames;
                break;
            case 4:
                D_801EDD8C->frames = func_801B0068(&p->script);
                sv->vx = *p->script++ - D_801EDD8C->pos.vx;
                sv->vy = *p->script++ - D_801EDD8C->pos.vy;
                sv->vz = *p->script++ - D_801EDD8C->pos.vz;
                D_801EDD8C->unk18.vx = ((sv->vx - D_801EDD8C->vel.vx * D_801EDD8C->frames) * 2) / (D_801EDD8C->frames * D_801EDD8C->frames);
                D_801EDD8C->unk18.vy = ((sv->vy - D_801EDD8C->vel.vy * D_801EDD8C->frames) * 2) / (D_801EDD8C->frames * D_801EDD8C->frames);
                D_801EDD8C->unk18.vz = ((sv->vz - D_801EDD8C->vel.vz * D_801EDD8C->frames) * 2) / (D_801EDD8C->frames * D_801EDD8C->frames);
                break;
            case 5:
                D_801EDD8C->frames = func_801B0068(&p->script);
                D_801EDD8C->unk28 = *p->script++;
                D_801EDD8C->unk4 = 0;
                D_801EDD8C->unk8 = 0x1000 / D_801EDD8C->frames;
                D_801EDD8C->unk18.vx = D_801EDD8C->pos.vx;
                D_801EDD8C->unk18.vy = D_801EDD8C->pos.vy;
                D_801EDD8C->unk18.vz = D_801EDD8C->pos.vz;
                D_801EDD8C->vel.vx = *p->script++ - D_801EDD8C->pos.vx;
                D_801EDD8C->vel.vy = *p->script++ - D_801EDD8C->pos.vy;
                D_801EDD8C->vel.vz = *p->script++ - D_801EDD8C->pos.vz;
                break;
            case 6:
                if ((D_801EDD8C->actor = *p->script++) == 0) {
                    D_801EDD8C->actor = p->actor;
                }
                D_801EDD8C->part = *p->script++;
                break;
            case 7:
                D_801EDD8C->actor = -1;
                break;
            case 0:
            case 8:
                D_801EDD8C->frames = func_801B0068(&p->script);
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801EDD8C = &D_801EDD34;
        D_801EDD90 = &D_801EDD60;
        for (i = 0; i < 2; i++) {
            switch (D_801EDD8C->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801EDD8C->vel.vx += D_801EDD8C->unk18.vx;
                D_801EDD8C->vel.vy += D_801EDD8C->unk18.vy;
                D_801EDD8C->vel.vz += D_801EDD8C->unk18.vz;
            case 2:
                D_801EDD8C->pos.vx += D_801EDD8C->vel.vx;
                D_801EDD8C->pos.vy += D_801EDD8C->vel.vy;
                D_801EDD8C->pos.vz += D_801EDD8C->vel.vz;
                break;
            case 3:
                D_801EDD8C->unk18.vx += D_801EDD8C->vel.vx;
                D_801EDD8C->unk18.vy += D_801EDD8C->vel.vy;
                D_801EDD8C->unk18.vz += D_801EDD8C->vel.vz;
                D_801EDD8C->unk4 += D_801EDD8C->unk8;
                vec->vx = D_801EDD90->pos.vx - D_801EDD8C->unk18.vx;
                vec->vy = D_801EDD90->pos.vy - D_801EDD8C->unk18.vy;
                vec->vz = D_801EDD90->pos.vz - D_801EDD8C->unk18.vz;
                func_8003A078(vec, sv);
                D_801EDD8C->pos.vx = D_801EDD90->pos.vx - ((sv->vx * D_801EDD8C->unk4) >> 12);
                D_801EDD8C->pos.vy = D_801EDD90->pos.vy - ((sv->vy * D_801EDD8C->unk4) >> 12);
                D_801EDD8C->pos.vz = D_801EDD90->pos.vz - ((sv->vz * D_801EDD8C->unk4) >> 12);
                break;
            case 5:
                D_801EDD8C->unk4 += D_801EDD8C->unk8;
                k = D_801EDD8C->unk4;
                for (j = 0; j < D_801EDD8C->unk28; j++) {
                    k = func_80039A74(k / 4);
                }
                D_801EDD8C->pos.vx = D_801EDD8C->unk18.vx + ((D_801EDD8C->vel.vx * k) >> 12);
                D_801EDD8C->pos.vy = D_801EDD8C->unk18.vy + ((D_801EDD8C->vel.vy * k) >> 12);
                D_801EDD8C->pos.vz = D_801EDD8C->unk18.vz + ((D_801EDD8C->vel.vz * k) >> 12);
                break;
            }
            cam = D_801EDD8C;
            D_801EDD8C = &D_801EDD60;
            D_801EDD90 = &D_801EDD34;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801EDD34.mode != 8) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801EDD34.actor == -1) {
                func_8003BC6C(&D_801EDD34.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801EDD34.pos, vec);
                if (D_801EDD34.part != -1) {
                    func_800D3994(D_801EDD34.actor, D_801EDD34.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801EDD34.actor].vx;
                    sv->vy = D_80151A4C[D_801EDD34.actor].vy;
                    sv->vz = D_80151A4C[D_801EDD34.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801EDD60.mode != 8) {
            if (D_801EDD60.actor == -1) {
                func_8003BC6C(&D_801EDD60.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801EDD60.pos, vec);
                if (D_801EDD60.part != -1) {
                    func_800D3994(D_801EDD60.actor, D_801EDD60.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801EDD60.actor].vx;
                    sv->vy = D_80151A4C[D_801EDD60.actor].vy;
                    sv->vz = D_80151A4C[D_801EDD60.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801EDD34.mode != 8) {
            D_80158D00 = D_801EDD34.pos;
        }
        if (D_801EDD60.mode != 8) {
            D_801031E8 = D_801EDD60.pos;
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

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B114C);

void func_801B1C0C(MgMat *arg0, u16 *arg1) {
    s32 sp10;
    s32 sp14;
    MgHalf *p;
    MgHalf *q;
    MgHalf *r;
    MgWord *w;

    func_80044AC0((s32)D_801EDD94, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801EDD94);
    p = (MgHalf *)&D_801ED910;
    p->v = D_801ED920.v = arg1[2];
    D_801ED91A = D_801ED922 = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)p - 0x10));
    func_8003B64C(&sp10, &sp14);
    func_8003B6BC((s16)arg1[2] / 2, (s16)arg1[3] / 2);
    func_8003B48C(arg0);
    func_8003B51C(arg0);
    w = (MgWord *)&D_801ED8E0;
    w->v = D_8016209C;
    D_80163C74 = func_801B114C((s32 *)w, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B6BC(sp10, sp14);
    q = (MgHalf *)&D_801ED8FC;
    q->v = arg1[2];
    D_801ED8FE = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)q - 0xC));
    func_80044978(D_801EDDD4, arg1);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801EDDD4);
    r = (MgHalf *)&D_801EDDEC;
    r->v = arg1[0];
    D_801EDDEE = arg1[1];
    func_800449FC(D_801EDDE0, r);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801EDDE0);
}

void func_801B1E1C(void) {
    s32 *p;
    s32 i;

    i = 299;
    p = &D_801F03C0;
    for (; i >= 0; i--) {
        *p-- = 0;
    }
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B1E40);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B1EB8);

MgMat *func_801B1FB0(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EDA6C.m[0][0] = D_801EDA6C.m[1][1] = D_801EDA6C.m[2][2] = scale;
    func_8003B48C(&D_801EDDF8);
    func_8003B51C(&D_801EDDF8);
    func_8003BC6C(v, (MgVec *)D_801EDA6C.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EDA6C.t, &n);
        D_801EDA6C.t[0] += (dist * n.vx) >> 12;
        D_801EDA6C.t[1] += (dist * n.vy) >> 12;
        D_801EDA6C.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EDA6C);
    func_8003B51C(&D_801EDA6C);
    return &D_801EDA6C;
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B20CC);

void func_801B21C8(s32 arg0) {
    MgObj20 *temp_v0;

    if (D_801EDA8C == NULL) {
        temp_v0 = &D_80162978[func_800BBEAC(&func_801B20CC)];
        D_801EDA8C = (u8 *) temp_v0;
        M2C_FIELD(temp_v0, s32 *, 4) = 0;
        M2C_FIELD(temp_v0, s32 *, 0xC) = (s32) (0x10000 / arg0);
    }
}

void func_801B2258(s32 arg0) {
    if (D_801EDA8C != NULL) {
        M2C_FIELD(D_801EDA8C, s32 *, 0xC) = (s32) ((s32) -M2C_FIELD(D_801EDA8C, s32 *, 4) / arg0);
    }
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B22B4);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B2460);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B2760);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B2A50);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B2CD0);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B2F4C);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B30D8);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B32B8);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B3464);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B3668);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B3A08);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B3E90);

void func_801B4104(void) {
    MgMat m;

    D_801EDBB8 = D_801ED8B8;
    D_801EDBA8 = D_801ED8B8;
    if (D_801ED8DA != 0) {
        D_801EDBC4 = D_801ED8D4;
    } else {
        D_801EDBC4 = -D_801ED8D4;
    }
    func_8003A63C(&D_801EDB88, &D_801EDBA8, &m);
    func_801B1C0C(&m, &D_801EDBC8);
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B4194);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B421C);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B4378);

void func_801B45C0(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    func_8003A63C(&D_801EDDF8, &D_801EDC00, D_801EDC20);
    func_8003B48C(D_801EDC20);
    func_8003B51C(D_801EDC20);
    D_80163C74 = func_800D29D4(&D_801EDBF0, D_801517C0 + 0x406C, 0, D_80163C74);
    if (D_80062D98 == 0) {
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 >= 0x78) {
            temp_s0->unk0 = -1;
            return;
        }
        func_8003C8DC(0x10, &D_801EDC00);
    }
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B46B4);

s32 func_801B4A6C(MgObjTup *p) {
    u16 *frame;
    s16 n;

    func_801B1FB0(&p->unk4, p->unk18, -0x3E8);
    frame = &D_801EDC30;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= D_801D83F0.v) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B4B1C(MgObjTup *p) {
    u16 *frame;
    s16 n;

    func_800D4368(&p->unk4, p->unk18, -0x3E8);
    frame = &D_801EDC3C;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= D_801D83F0.v) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B4BCC);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B4E00);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B5050);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B51E0);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B550C);

void func_801B575C(s16 arg0) {
    MgObj20 *temp_v0;

    temp_v0 = &D_80162978[func_800BBEAC(&func_801B550C)];
    temp_v0->unk0 = arg0;
    M2C_FIELD(temp_v0, s16 *, 0xE) = 0;
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B57A8);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B592C);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B5AB0);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B5D00);

void func_801B5E5C(void) {
    MgObj20 *temp_s0;
    s16 temp_v1;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        temp_v1 = temp_s0->unk2;
        if (temp_v1 == 0) {
            func_801B21C8(4);
        } else if (temp_v1 == 4) {
            func_801B2258(4);
            temp_s0->unk0 = -1;
        }
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B5EE8);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B64C8);
