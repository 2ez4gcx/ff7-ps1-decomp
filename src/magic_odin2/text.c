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

void func_801B2400(void) {
    MgTask *p;
    MgMat *m;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        D_801F1C60[0] = D_801F1C60[1] = D_801F1C60[2] = (u32)((t << 12) / 10) >> 5;
    } else {
        t -= 10;
        if (t < 0x7D) {
            *(s32 *)D_801F1C60 = 0x2E808080;
        } else {
            t -= 0x7D;
            if (t >= 0x19) {
                p->unk0 = -1;
                return;
            }
            if (t == 0) {
                p->unk6 = -0x1324;
                p->unk4 = 0;
                p->unk8 = -0x1E0C;
            }
        }
    }
    m = func_801B2200((MgSVec *)&p->unk4, 0x2000, 0);
    m->t[0] += D_801F1C68;
    func_8003B51C(m);
    D_80163C74 = func_800D4D90((M2C_UNK *)&D_801F1C5C, D_801517C0 + 0x4068, 0, D_80163C74);
    m->t[0] -= 0x1000;
    func_8003B51C(m);
    D_80163C74 = func_800D4D90((M2C_UNK *)&D_801F1C5C, D_801517C0 + 0x4068, 0, D_80163C74);
    m->t[0] = m->t[0] + 0x2000;
    func_8003B51C(m);
    D_80163C74 = func_800D4D90((M2C_UNK *)&D_801F1C5C, D_801517C0 + 0x4068, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        D_801F1C68 -= 0x10;
    }
}

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

void func_801B27A8(void) {
    MgTask *p;
    s32 t;
    s32 c;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x23) {
        *(s32 *)D_801F1CB0 = 0x2E000000;
    } else {
        t -= 0x23;
        if (t < 10) {
            c = (t << 12) / 10 << 6 >> 12;
            goto store;
        }
        t -= 10;
        if (t < 0xF) {
            c = 0x40;
store:
            D_801F1CB0[0] = c;
            D_801F1CB0[1] = c;
            D_801F1CB0[2] = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_801B231C((MgSVec *)&p->unk4, 0, &D_801F1CB8);
    func_8003B48C(&D_801F1CB8);
    D_801F1CCC += D_801F1CD8;
    func_8003B51C(&D_801F1CB8);
    D_80163C74 = func_800D4D90((M2C_UNK *)&D_801F1CAC, D_801517C0 + 0x4084, 0, D_80163C74);
    D_801F1CCC += 0x800;
    func_8003B51C(&D_801F1CB8);
    D_80163C74 = func_800D4D90((M2C_UNK *)&D_801F1CAC, D_801517C0 + 0x4084, 0, D_80163C74);
    D_801F1CCC += 0x800;
    func_8003B51C(&D_801F1CB8);
    D_80163C74 = func_800D4D90((M2C_UNK *)&D_801F1CAC, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        v = D_801F1CD8;
        p->unk2++;
        D_801F1CD8 = v + 8;
        if (v + 8 >= -0x400) {
            D_801F1CD8 = v - 0x7F8;
        }
    }
}

s32 func_801B29C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    OdDesc d;
    u8 pad[8];
    u8 *a;
    MgMat *m;
    s32 i;
    s32 o;
    s32 o2;
    s32 r;

    r = arg3;
    a = D_801518E4 + arg0 * 0xB9C;
    i = 0;
    if (*(s16 *)(a + 0x10) > 0) {
        o2 = arg0 * 0x74;
        o = 0x174;
        do {
            if (*(s32 *)(a + 0x78 + i * 4) != 0) {
                m = (MgMat *)(a + o);
                func_8003B48C(m);
                func_8003B51C(m);
                d.a = *(s32 *)(a + 0x78 + i * 4);
                d.b = *(u8 *)(a + i + 0x3F) | 0x90;
                d.c = *(u16 *)(D_8015122E + o2);
                d.d = 0;
                d.e = 0x20;
                d.f = *(u16 *)(a + 0x16);
                r = func_801B114C(&d, arg1, arg2, r);
            }
            o += 0x34;
            i++;
        } while (i < *(s16 *)(a + 0x10));
    }
    return r;
}

void func_801B2B20(s32 arg0, u16 *arg1, MgSVec *arg2) {
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    u8 *ot;
    MgHalf *r;
    MgHalf *r2;
    MgMat *m;
    s32 o;

    func_80044244(D_801F1E20, 0x1000);
    ot = D_801F1E20 + 0x3FF8;
    r = &D_801F1CE8;
    r->v = arg1[2];
    D_801F1CEA = arg1[3];
    func_80046794((s32)ot, (u8 *)r - 0xC);
    func_80044978(D_801F5E30, arg1);
    func_80046794((s32)ot, D_801F5E30);
    r2 = &D_801F5E20;
    r2->v = arg1[0];
    D_801F5E22 = arg1[1];
    func_800449FC(D_801F5E24, r2);
    func_80046794((s32)ot, D_801F5E24);
    func_8003B64C(&sp10, &sp14);
    o = arg0 * 0xB9C;
    m = (MgMat *)(D_80151A58 + o);
    m = (MgMat *)((u8 *)m + D_8015190F[o] * 0x34);
    func_8003B48C(m);
    func_8003B51C(m);
    arg2->vz = func_8003BBDC(D_801F1CEC, arg2, &sp18, &sp1C);
    func_8003B6BC((s16)arg1[2] / 2 - (arg2->vx - sp10), (s16)arg1[3] / 2 - (arg2->vy - sp14));
    D_80163C74 = func_801B29C8(arg0, (s32)D_801F1E20, 0xC, D_80163C74);
    func_8003B6BC(sp10, sp14);
    func_80044AC0((s32)D_801F5E3C, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794((s32)(D_801F1E20 + 4), D_801F5E3C);
    func_800467D0((MainTag *)(D_801517C0 + 0x4084), (u32)(D_801F1E20 + 0x3FFC), (MainTag *)D_801F1E20);
}

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B2D88);

void func_801B2F70(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    OdG4 *q;
    s32 o;
    s32 e;
    s32 d;
    s16 a;
    s16 b;

    if (arg1 < 0) {
        arg0 = -arg0;
    }
    o = arg3 * 0x10;
    e = arg3 * 0x28 + arg2 * 0x50;
    q = (OdG4 *)(D_801F7284 + e);
    a = *(u16 *)(D_801F7324 + o) + arg0;
    q->x2 = a;
    *(s16 *)(D_801F7284 + 8 + e) = a;
    b = *(u16 *)(D_801F7324 + 4 + o) + arg0;
    q->x3 = b;
    *(s16 *)(D_801F7284 + 0x10 + e) = b;
    d = arg1 * arg0 >> 12;
    *(s16 *)(D_801F7284 + 0xA + e) = *(u16 *)(D_801F7324 + 2 + o) + d;
    *(s16 *)(D_801F7284 + 0x12 + e) = *(u16 *)(D_801F7324 + 6 + o) + d;
    *(s16 *)(D_801F7284 + 0x1A + e) = *(u16 *)(D_801F7324 + 0xA + o) + d;
    *(s16 *)(D_801F7284 + 0x22 + e) = *(u16 *)(D_801F7324 + 0xE + o) + d;
}

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B30B4);

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B33DC);

void func_801B379C(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk1C, 0);
    frame = &D_801F1D10;
    *frame = p->unk2 | 0x8000;
    D_80163C74 = func_800D4D90((M2C_UNK *)((u8 *)frame - 8), D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801DC840[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B3860(arg0) {
    MgTask *q;
    s32 i;
    s32 k;

    for (i = 0; i < arg0; i++) {
        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B379C)];
        func_800D3994(3, D_801F1D14[func_80042DA8() % 6], &q->unk4);
        k = 0xC8;
        q->unk4 = (u16)q->unk4 - k + func_80042DA8() % 400;
        q->unk6 = (u16)q->unk6 - k + func_80042DA8() % 400;
        q->unk8 = (u16)q->unk8 - k + func_80042DA8() % 400;
        q->unk1C = func_80042DA8() % 0x1000 + 0x1000;
    }
}

void func_801B3A10(void) {
    MgTask *p;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t + p->unk0 < 0xF && t < 9) {
        D_801F1D2A = (t << 12) / 9;
    } else {
        p->unk0 = -1;
        return;
    }
    func_8003A63C(&D_801F6238, *(M2C_UNK **)((u8 *)p + 0x14), D_801F1D30);
    func_8003B48C(D_801F1D30);
    func_8003B51C(D_801F1D30);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4((M2C_UNK *)&D_801F1D20, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3B3C(void) {
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B3A10)];
        q->unk0 = p->unk2;
        func_800D41FC(&D_801F6238, D_801540D4, D_801F5EA4 + (p->unk2 << 5));
        *(u8 **)((u8 *)q + 0x14) = D_801F5EA4 + (p->unk2 << 5);
        p->unk2++;
        if (p->unk2 >= 9) {
            p->unk0 = -1;
        }
    }
}

void func_801B3C14(MgSVec *a, MgSVec *b, s32 k, MgSVec *out) {
    MgVec d;

    d.vx = b->vx - a->vx;
    d.vy = b->vy - a->vy;
    d.vz = b->vz - a->vz;
    func_8003A08C(&d, &d);
    out->vx = a->vx + ((k * d.vx) >> 12) - b->vx;
    out->vy = a->vy + ((k * d.vy) >> 12) - b->vy;
    out->vz = a->vz + ((k * d.vz) >> 12) - b->vz;
}

void func_801B3D10(void) {
    MgTask *p;
    u8 *q;
    s32 t;
    s32 u;
    s32 n;
    s32 k0;
    s32 k1;
    s32 ext;
    s32 flag;
    s32 c;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    u = t + p->unk0;
    if (u < 0x24) {
        if (t >= 0x24) {
            goto kill;
        }
        k0 = ((t + 1) << 12) / 36;
        k1 = (t << 12) / 36;
    } else {
        u -= 0x24;
        if (u >= 0x18) {
            goto kill;
        }
        n = t - u;
        k0 = ((n + 1) << 12) / 36;
        k1 = (n << 12) / 36;
    }
    goto draw;
kill:
    p->unk0 = -1;
    return;
draw:
    func_8003B48C(&D_801F6238);
    func_8003B51C(&D_801F6238);
    q = (u8 *)D_80163C74;
    r = func_8003BD7C(*(s32 *)&p->unk18 - 0x10, *(s32 *)&p->unk18 - 8, *(s32 *)&p->unk18, *(s32 *)&p->unk18 + 8, q + 8, q + 0x10, q + 0x18, q + 0x20, &ext, &flag);
    if (!(flag & 0x60000)) {
        *(s32 *)q = 0x08000000;
        func_8003B710(D_801F1D34, k0, &c);
        *(s32 *)(q + 4) = *(s32 *)(q + 0xC) = c | 0x3A000000;
        func_8003B710(D_801F1D34, k1, &c);
        *(s32 *)(q + 0x14) = *(s32 *)(q + 0x1C) = c;
        func_80046794(D_801517C0 + 0x70 + ((r >> 2) << 2), q);
        D_80163C74 = (s32)(q + 0x24);
    }
    if (D_80062D98 == 0) {
        p->unk2 += 4;
    }
}

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B3F54);

void func_801B4434(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (D_801F6258 >> i & 1) {
            D_8015120C[i].unk0 ^= 2;
        }
    }
}

void func_801B447C(void) {
    MgTask *p;
    s32 t;
    s32 i;
    s16 *q;
    u8 pad[8];

    p = &D_80162978[D_8015169C];
    if (D_801F1D98 != 0) {
        t = D_801F1D9C % 5;
        D_801F1D92[0] = (func_80039A74((t << 12) / 5) << 10 >> 12) + 0x400;
        func_8003B48C((MgMat *)D_801540D4);
        func_8003B51C((MgMat *)D_801540D4);
        func_8003B69C(0, 0, 0);
        D_80163C74 = func_801B1C40(&D_801F1D92[-5], D_801517C0 + 0x70, 0xC, D_80163C74);
    }
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t >= 0x54) {
            t -= 0x54;
            if (t < 0x3C) {
                if (t == 0) {
                    q = func_800D4FA8(1);
                    q[2] = 0;
                    q[3] = -0x7530;
                    q[4] = 0;
                    q[8] = D_801DCCC8.vy + 0x800;
                    D_801F1D54->b28 = 0;
                    D_801F1D54->b29 = 0;
                    D_801F1D54->b2A = 0;
                    D_801F1D98 = 1;
                    D_801F1D54->s14 = 0x1000;
                    D_801F1D54->s06 = 0x200;
                }
            } else {
                t -= 0x3C;
                if (t < 0x19) {
                    if (t == 0) {
                        D_801F1D54->s06 = 0x1000;
                        D_801F1D54->s14 = 0;
                        D_801F1D4C[1] = -0x1388;
                        D_801F1D4C[2] = -0x1194;
                    }
                    D_801F1D9C++;
                } else {
                    t -= 0x19;
                    if (t < 0x23) {
                        if (t == 0) {
                            p->unkE = -0x96;
                        }
                        if (t < 0xF) {
                            func_801B3860(3);
                        }
                        D_801F1D4C[1] += p->unkE;
                        D_801F1D4C[2] += 0x64;
                        D_801F1D9C++;
                        p->unkE = p->unkE + 5;
                    } else {
                        t -= 0x23;
                        if (t < 0x19) {
                            if (t == 0) {
                                D_801F1D4C[1] = -0x12C;
                                D_801F1D4C[2] = -0xBB8;
                            }
                            if (t < 0x13) {
                                if (D_801F1D4C[1] < 0) {
                                    D_801F1D4C[1] = D_801F1D4C[1] + 0xF;
                                    D_801F1D4C[2] += 0x12C;
                                }
                                D_801F1D9C++;
                            }
                            if (t == 0xA) {
                                func_800BBEAC((M2C_UNK *)func_801B3B3C);
                                D_80162978[func_800BBEAC((M2C_UNK *)func_801B3F54)].unk0 = 0;
                            }
                        } else {
                            t -= 0x19;
                            if (t < 0xF || (t -= 0xF) < 0xF) {
                                if (t == 0) {
                                    D_801F1D4C[1] = -0x96;
                                    D_801F1D4C[2] = 0;
                                }
                                if (t < 9) {
                                    if (D_801F1D4C[1] < 0) {
                                        D_801F1D4C[1] = D_801F1D4C[1] + 0xF;
                                        D_801F1D4C[2] += 0x12C;
                                    }
                                    D_801F1D9C++;
                                }
                                if (t == 0) {
                                    func_800BBEAC((M2C_UNK *)func_801B3B3C);
                                    D_80162978[func_800BBEAC((M2C_UNK *)func_801B3F54)].unk0 = 0;
                                }
                            } else {
                                t -= 0xF;
                                if (t < D_801F625C) {
                                    if (t == 0) {
                                        D_801F1D54->b25 |= 2;
                                        D_801F1D98 = 0;
                                    }
                                    goto inc;
                                }
                                t -= D_801F625C;
                                if (t < 0xF) {
                                    if (t == 0) {
                                        D_801F1D54->b25 &= 0xFC;
                                        D_801F1D98 = 1;
                                        D_801F1D4C[1] = -0x640;
                                        D_801F1D4C[2] = 0;
                                    }
                                    if (t < 8) {
                                        D_801F1D4C[1] += 0xC8;
                                    } else if (t == 8) {
                                        p->unkE = -0x1F4;
                                        D_801F1D54->b28 = D_801F1D54->b29 = D_801F1D54->b2A = 0;
                                        D_801F1D54->s14 = 0;
                                        for (i = 0; i < D_801F1D54->s10; i++) {
                                            D_801F1D54->b3F[i] = 8;
                                        }
                                    } else {
                                        D_801F1D54->s14 = (t - 8 << 12) / 7;
                                        D_801F1D4C[1] += p->unkE;
                                        p->unkE = p->unkE + 0x32;
                                    }
                                    D_801F1D4C[2] += 0x1F4;
                                    if (t != 0) {
                                        D_801F1D74 = D_801F1D4C[2] - 0x3E8;
                                        D_801F1D70 = 0;
                                        D_801F1D6C[0] = D_801F1D4C[0];
                                        func_8003A63C(&D_801F6238, (M2C_UNK *)&D_801F1D6C[-5], &D_801F1DA0->mm);
                                        func_8003B48C(&D_801F1DA0->mm);
                                        func_8003B51C(&D_801F1DA0->mm);
                                        D_80163C74 = func_800D29D4(&D_801F1D78, D_801517C0 + 0x4078, 0, D_80163C74);
                                    }
                                    if (t == 0xE) {
                                        func_800D4FA8(2);
                                    }
                                    D_801F1D9C++;
                                } else {
                                    p->unk0 = -1;
                                }
                            }
                        }
                    }
                }
            }
        }
        func_8003B2CC(&D_801DCCA8, D_801F1D4C, D_801F1DA0);
        D_801F1D54->s168 = D_801DCCBC + D_801F1DA0->vv[0];
        D_801F1D54->s16A = D_801DCCC0 + D_801F1DA0->vv[1];
        D_801F1D54->s16C = (u16)D_801DCCC4 + D_801F1DA0->vv[2];
inc:
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_odin2/nonmatchings/text", func_801B4B98);

void func_801B4C38(void) {
    MgTask *p;
    u8 *q;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t == 0) {
            q = D_801F6210;
            D_800F5B70 = 0x80;
            D_800F5B71 = 0x80;
            D_800F5B72 = 0x80;
            D_800F5B74 = 0x1000;
            func_80046A80(q);
            D_801F6220 = 0x140;
            D_801F6222 = 0x1F8;
            D_801F6224 = 0x100;
            D_801F6226 = 8;
            D_801F621C = 0x300;
            D_801F621E = 8;
            func_80046794(D_801517C0 + 0x4084, q);
        } else if (t == 6) {
            q = D_801F6210;
            D_800F5B70 = D_800F5B71 = D_800F5B72 = 0;
            D_800F5B74 = 0x800;
            func_80046A80(q);
            D_801F6220 = 0x140;
            D_801F6222 = 0x1F8;
            D_801F6224 = 0x100;
            D_801F6226 = 8;
            D_801F621C = 0x300;
            D_801F621E = 0;
            func_80046794(D_801517C0 + 0x4084, q);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B4DD4(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 k;
    u16 *h;

    b = D_80162978;
    p = &b[D_8015169C];
    func_8003A63C(&D_800FA63C, (M2C_UNK *)&D_801DCCA8, &D_801F6238);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 10) {
            if (t == 0) {
                D_800F5B70 = 0;
                D_800F5B71 = 0;
                D_800F5B72 = 0;
                func_800D52A0(0x1000, 0xA);
                func_800D2564(D_801F1DAC, D_801F6260);
            }
            if (t == 9) {
                D_800F8380 |= 0xF;
            }
            goto end;
        }
        t -= 10;
        if (t < 0x32) {
            if (t == 0) {
                k = -0x1388;
                q = &b[func_800BBEAC((M2C_UNK *)func_801B2400)];
                q->unk4 = 0;
                q->unk6 = 0;
                q->unk8 = k;
                q = &b[func_800BBEAC((M2C_UNK *)func_801B25F8)];
                q->unk4 = 0;
                q->unk6 = 0;
                q->unk8 = k;
                func_800D55F4(0x22, 0x40, 0x239, 0x23A, 0x23B);
            }
            goto end;
        }
        t -= 0x32;
        if (t < 0x19) {
            goto end;
        }
        t -= 0x19;
        if (t < 0x28) {
            if (t == 0) {
                func_800BBEAC((M2C_UNK *)func_801B26D0);
                q = &b[func_800BBEAC((M2C_UNK *)func_801B27A8)];
                q->unk6 = -0x46;
                q->unk4 = 0;
                q->unk8 = -0x388;
            }
            goto end;
        }
        t -= 0x28;
        if (t < 0x14) {
            goto end;
        }
        t -= 0x14;
        if (t < 0x19) {
            if (t == 0) {
                func_800D55F4(0x22, 0x40, 0x23C, 0x23D, 0x23E);
            }
            goto end;
        }
        t -= 0x19;
        if (t < 0x23) {
            if (t == 0) {
                D_800F8380 &= 0xF0;
                func_800D52A0(0, 0x23);
                func_800D2538(D_801F1DB4, D_801F6260);
            }
            if (t == 5) {
                func_801B4B98();
                h = &D_801F1DB6;
                *h += D_801F1DBA;
                func_800D2538((u8 *)h - 2, D_801F6260);
            }
            goto end;
        }
        t -= 0x23;
        if (t < 0x19) {
            if (t == 0x12) {
                func_800BBEAC((M2C_UNK *)func_801B4C38);
                func_801B4434();
            }
            if (t == 0x18) {
                func_801B4434();
            }
            if (t != 10) {
                goto end;
            }
            goto call;
        }
        t -= 0x19;
        if (t < 0xF) {
            if (t == 8) {
                func_800BBEAC((M2C_UNK *)func_801B4C38);
                func_801B4434();
            }
            if (t == 0xE) {
                goto call4434;
            }
            goto test0;
        }
        t -= 0xF;
        if (t < 0xF) {
            if (t == 8) {
                func_800BBEAC((M2C_UNK *)func_801B4C38);
                func_801B4434();
            }
            if (t == 0xE) {
                D_800F5B70 = 0;
                D_800F5B71 = 0;
                D_800F5B72 = 0;
                D_800F5B74 = 0x800;
                q = &b[func_800BBEAC((M2C_UNK *)func_801B33DC)];
                q->unk0 = 0;
call4434:
                func_801B4434();
            }
test0:
            if (t != 0) {
                goto end;
            }
call:
            func_800D55F4(0x22, 0x40, 0x247, 0x248, 0x249);
            goto end;
        }
        t -= 0xF;
        if (t < 0) {
            goto end;
        }
        if (t < D_801F625C) {
            if (t == D_801F625C - 1) {
                D_800F5B74 = 0;
            }
        } else {
            t -= D_801F625C;
            if (t < 0xF) {
                if (t == 0) {
                    func_800D55F4(0x22, 0x40, 0x24A, 0x24B, 0x24C);
                }
            } else {
                p->unk0 = -1;
            }
        }
end:
        p->unk2++;
    }
}

void func_801B5264(arg0, arg1) {
    MgSVec v;
    s32 t;

    func_800D2980(&D_801B53B0, 0, 0, 0);
    t = func_800D54BC(arg0) * 15;
    D_801F625C = t;
    D_801F7270 = t;
    D_801F6258 = arg0;
    func_800D54EC(arg0, &v);
    if (v.vz > *(s16 *)(D_80151A50 + arg1 * 0xB9C)) {
        D_801DCCC4 = v.vz - 0x1388;
    } else {
        D_801DCCCA = 0x800;
        D_801DCCC4 = v.vz + 0x1388;
    }
    func_8003C21C(&D_801DCCC8, &D_801DCCA8);
    D_80162978[func_800BBEAC((M2C_UNK *)func_801B4DD4)].unk0 = 0;
    func_800BBEAC((M2C_UNK *)func_801B447C);
    if (func_80042DA8() & 0x100) {
        ((void (*)(s32, s32, s32))func_801B10E8)((s32)D_801F1A4C, (s32)&D_801DCCA8, arg1);
    } else {
        ((void (*)(s32, s32, s32))func_801B10E8)((s32)D_801F1B44, (s32)&D_801DCCA8, arg1);
    }
}
