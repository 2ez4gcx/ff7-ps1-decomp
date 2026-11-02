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

TuPart *func_801B1E40(s32 arg0) {
    s32 i;

    for (i = 0; i < 300; i++) {
        if (D_801EFF14[i] == 0) {
            D_801EFF14[i] = arg0;
            D_801EDE44[i].unk0 = 0;
            D_801EDE44[i].unk2 = 0;
            return &D_801EDE44[i];
        }
    }
    return 0;
}

void func_801B1EB8(void) {
    MgTask *p;
    s32 n;
    s32 i;

    p = &D_80162978[D_8015169C];
    n = 0;
    for (i = 0; i < 300; i++) {
        if (D_801EFF14[i] != 0) {
            ((void (*)(TuPart *))D_801EFF14[i])(&D_801EDE44[i]);
            if (D_801EDE44[i].unk0 == -1) {
                D_801EFF14[i] = 0;
            } else {
                n++;
            }
        }
    }
    if (n == 0 && D_80162080 < 2) {
        p->unk0 = -1;
    }
}

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

void func_801B20CC(void) {
    TuFade *p;
    TuTile *q;
    u8 c;
    s32 k;

    p = (TuFade *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unkC != 0) {
            p->unk4 = p->unk4 + p->unkC;
            if (p->unk4 <= 0) {
                p->unk0 = -1;
                D_801EDA8C = 0;
                return;
            }
            if (p->unk4 > 0xFFFF) {
                p->unk4 = 0xFFFF;
                p->unkC = 0;
            }
        }
    }
    c = ((u8 *)p)[5];
    k = D_801EDAB0 << 4;
    q = (TuTile *)((u8 *)D_801EDA90 + k);
    D_801EDA94[k] = q->g = q->b = c;
    func_80046794(D_801517C0 + 0x4088, (s32)((u8 *)D_801EDA90 + (D_801EDAB0 << 4)));
    D_801EDAB0 ^= 1;
}

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

void func_801B22B4(void) {
    MgTask *p;
    s16 t;
    s16 q;
    s16 i;
    s32 j;
    s32 f;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        f = ((s16)(t % 16) << 12) / 16;
        q = t / 16;
        i = q % 6;
        j = (i + 1) % 6;
        D_800F5B70.v = D_801EDAB4[i][0] + ((D_801EDAB4[j][0] - D_801EDAB4[i][0]) * f >> 12);
        D_800F5B71.v = D_801EDAB4[i][1] + ((D_801EDAB4[j][1] - D_801EDAB4[i][1]) * f >> 12);
        D_800F5B72.v = D_801EDAB4[i][2] + ((D_801EDAB4[j][2] - D_801EDAB4[i][2]) * f >> 12);
        p->unk2++;
        if (p->unk2 >= 0x195) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B2460);

void func_801B2760(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 u;
    s32 n;
    s32 q6;
    s32 q18;
    s32 a;
    s32 r;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x3C) {
            u = (t << 12) / 60;
            n = (u << 7 >> 12) + 0x80;
            q6 = u;
            q18 = ((u * 3) << 10 >> 12) + 0x400;
        } else {
            t -= 0x3C;
            if (t >= 0x19) {
                p->unk0 = -1;
                return;
            }
            n = 0x100;
            q6 = 0x1000;
            q18 = 0x1000;
        }
        n += (n * p->unk2) & 0xFF;
        while (n >= 0x100) {
            q = &D_80162978[func_800BBEAC(&func_801B2460)];
            q->unk0 = p->unk2;
            a = func_80042DA8() & 0xFFF;
            r = func_80042DA8() % 300;
            k = func_80039A74(a);
            q->unk4 = r * k >> 12;
            q->unk6 = (func_80042DA8() % 4000 - 0x1F40) * q6 >> 12;
            k = func_80039B40(a);
            q->unk8 = r * k >> 12;
            q->unkE = (func_80042DA8() % 20 + 0x1E) * q6 >> 12;
            *(u8 *)&q->unk14 = ((func_80042DA8() % 64) - 0x20) >> 4;
            *((u8 *)&q->unk14 + 1) = func_80042DA8();
            *((u8 *)&q->unk14 + 2) = ((func_80042DA8() % 64) - 0x20) >> 4;
            q->unk18 = (func_80042DA8() % 512 + 0x700) * q18 >> 12;
            n -= 0x100;
        }
        p->unk2++;
    }
}

void func_801B2A50(void) {
    MgTask *p;
    s32 t;
    s32 i;
    s32 u;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    u = t + p->unk0;
    if (u >= 0x5A) {
        u -= 0x5A;
        if (u >= 10) {
            goto kill;
        }
        u = (u << 12) / 10;
        D_801EDAEA = u;
        for (i = 0; i < 3; i++) {
            u = func_80039A74(u / 4);
        }
        k = p->unk18 * ((u << 12 >> 12) + 0x1000) >> 12;
        D_801EDAF0->sc.vy = 0x400;
        D_801EDAF0->sc.vx = D_801EDAF0->sc.vz = k;
        goto rig;
    }
    u = t;
    if (t < 10) {
        u = (u << 12) / 10;
        D_801EDAEA = 0x1000 - u;
        goto scale;
    }
    u -= 10;
    if (u < 10) {
        D_801EDAEA = 0;
        goto scale;
    }
    u = t - 20;
    if (u >= 10) {
kill:
        p->unk0 = -1;
        return;
    }
    u = (u << 12) / 10;
    D_801EDAEA = u;
scale:
    D_801EDAF0->sc.vx = D_801EDAF0->sc.vz = p->unk18;
    D_801EDAF0->sc.vy = 0x400;
rig:
    func_8003C21C((MgSVec *)&p->unkC, &D_801EDAF0->m);
    D_801EDAF0->m.t[0] = p->unk4;
    D_801EDAF0->m.t[1] = p->unk6;
    D_801EDAF0->m.t[2] = p->unk8;
    func_8003B35C(&D_801EDAF0->m, &D_801EDAF0->sc);
    func_8003A63C(&D_801EDDF8, &D_801EDAF0->m, &D_801EDAF0->m);
    func_8003B48C(&D_801EDAF0->m);
    func_8003B51C(&D_801EDAF0->m);
    D_80163C74 = func_800D29D4(&D_801EDAE0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unkE += 0x40;
    }
}

void func_801B2CD0(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 u;
    s32 n;
    s32 q6;
    s32 q18;
    s32 a;
    s32 r;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x3C) {
            u = (t << 12) / 60;
            n = ((u * 3) << 4 >> 12) + 0x10;
            q6 = u;
            q18 = ((u * 3) << 10 >> 12) + 0x400;
        } else {
            t -= 0x3C;
            if (t >= 0x19) {
                p->unk0 = -1;
                return;
            }
            n = 0x40;
            q6 = 0x1000;
            q18 = 0x1000;
        }
        n += (n * p->unk2) & 0xFF;
        while (n >= 0x100) {
            n -= 0x100;
            q = &D_80162978[func_800BBEAC(&func_801B2A50)];
            q->unk0 = p->unk2;
            a = func_80042DA8() & 0xFFF;
            r = func_80042DA8() % 200;
            k = func_80039A74(a);
            q->unk4 = r * k >> 12;
            q->unk6 = (func_80042DA8() % 4000 - 0x1F40) * q6 >> 12;
            k = func_80039B40(a);
            q->unk8 = r * k >> 12;
            q->unkC = 0;
            q->unkE = func_80042DA8() & 0xFFF;
            q->unk10 = 0;
            q->unk18 = (func_80042DA8() % 592 + 0x600) * q18 >> 12;
        }
        p->unk2++;
    }
}

void func_801B2F4C(void) {
    MgTask *p;
    s32 t;
    s32 r;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 3) {
        r = (t << 12) / 3;
        D_801EDAFE = 0;
        k = (r << 11) >> 12;
    } else {
        t -= 3;
        if (t < 12) {
            r = (t << 12) / 12;
            k = ((0x1000 - r) << 11) >> 12;
            D_801EDAFE = r;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003B69C(0, 0, 0);
    func_801B1FB0((MgSVec *)&p->unk4, k, 0);
    D_80163C74 = func_800D29D4(&D_801EDAF4, D_801517C0 + 0x4084, 0, D_80163C74);
    func_801B1FB0((MgSVec *)&p->unkC, k, 0);
    D_80163C74 = func_800D29D4(&D_801EDAF4, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B30D8);

void func_801B32B8(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 a;
    s32 r;
    s32 k;
    s32 u;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = &D_80162978[func_800BBEAC(&func_801B30D8)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&D_801EDB54;
            a = func_80042DA8() & 0xFFF;
            r = func_80042DA8() % 2000;
            k = func_80039A74(a);
            q->unkC = (r * k >> 12) - D_801EDB54.vx;
            q->unkE = -D_801EDB54.vy;
            k = func_80039B40(a);
            u = (u16)D_801EDB54.vz - 0x1B58;
            q->unk10 = (r * k >> 12) - u;
            q->unk18 = func_80042DA8() % 0x1000 + 0x2000;
            i++;
        } while (i < 2);
        p->unk2++;
        if (p->unk2 >= 0x28) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B3464);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B3668);

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B3A08);

void func_801B3E90(void) {
    MgTask *p;
    s32 i;
    s32 q;
    s32 r;
    s32 t;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;

    p = &D_80162978[D_8015169C];
    if (p->unk2 == 0 && D_80062D98 == 0) {
        if (q) {
            func_801B3464();
        } else {
            func_801B3464();
        }
    }
    if (p->unk2 < 0xA) {
        e = (p->unk2 << 7) / 10;
    } else {
        e = 0x80;
    }
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x32) {
            q = (t << 12) / 50;
            a = (q * 0x4A38 >> 12) + 0x3E8;
            b = (q * 0xBB8 >> 12) + 0x3E8;
            c = (q * 0x384 >> 12) + 0x64;
            r = 0x1000 - q;
            for (i = 0; i <= 0; i++) {
                r = func_80039A74(r / 4);
            }
            r = 0x1000 - r;
            d = (-((r << 12) >> 1) >> 12) + 0x800;
        } else {
            t -= 0x32;
            if (t < 0x78) {
                a = 0x4E20;
                b = 0xFA0;
                c = 0x3E8;
                d = 0;
            } else {
                t -= 0x78;
                if (t >= 0xF) {
                    p->unk0 = -1;
                    return;
                }
                a = 0x4E20;
                b = 0xFA0;
                c = 0x3E8;
                d = 0;
                q = (t << 12) / 15;
                e = (-(q << 7) >> 12) + 0x80;
            }
        }
        func_801B3A08(a, b, c, d);
    }
    func_801B3668(p->unk2 << 7, e);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

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

void func_801B4194(MgMat *arg0, s32 arg1, s16 arg2) {
    s32 *frame;

    frame = &D_801EDBD0;
    D_801EDBD8 = arg2;
    *frame = D_801EDBE0[arg1];
    func_8003B48C(arg0);
    func_8003B51C(arg0);
    D_80163C74 = func_800D29D4(frame, D_801517C0 + 0x70, 0xC, D_80163C74);
}

void func_801B421C(void) {
    TuObj *p;
    s16 n;

    p = (TuObj *)&D_80162978[D_8015169C];
    D_801EDBEC->rot.vx = p->c0 << 4;
    D_801EDBEC->rot.vy = p->c1 << 4;
    D_801EDBEC->rot.vz = p->c2 << 4;
    func_8003C21C(&D_801EDBEC->rot, &D_801EDBEC->m);
    D_801EDBEC->m.t[0] = p->unk4;
    D_801EDBEC->m.t[1] = p->unk6;
    D_801EDBEC->m.t[2] = p->unk8;
    D_801EDBEC->sc.vx = D_801EDBEC->sc.vy = D_801EDBEC->sc.vz = p->unk18;
    func_8003B35C(&D_801EDBEC->m, &D_801EDBEC->sc);
    func_8003A63C(&D_801EDDF8, &D_801EDBEC->m, &D_801EDBEC->m);
    ((void (*)(MgMat *, s32, s32))func_801B4194)(&D_801EDBEC->m, p->unk0, p->unk1A);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0xF) {
            p->unk0 = -1;
        } else {
            p->unk6 += p->unkE;
            p->c0 += 1;
            p->c1 += 0x10;
            p->c2 += 0x20;
        }
    }
}

void func_801B4378(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 a;
    s32 r;
    s32 x;
    s32 z;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = &D_80162978[func_800BBEAC(&func_801B421C)];
            i++;
            q->unk0 = func_80042DA8() % 3;
            a = func_80042DA8() & 0xFFF;
            r = func_80042DA8() % 4000 + 1000;
            x = r * func_80039A74(a) >> 12;
            z = r * func_80039B40(a) >> 12;
            q->unk4 = x;
            q->unk6 = 0;
            q->unk8 = z + 0x1B58;
            q->unkE = -(func_80042DA8() % 200 + 0x190);
            *(s32 *)&q->unk14 = func_80042DA8() & 0xFFFFFF;
            q->unk18 = func_80042DA8() % 384 + 0x80;
            q->unk1A = (u8)((x + 5000) / 250 + 20) | (u8)((z + 5000) / 250 + 20) << 8;
        } while (i < 2);
        p->unk2++;
        if (p->unk2 >= 0x32) {
            p->unk0 = -1;
        }
    }
}

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

void func_801B4BCC(TuObj *p) {
    MgTask *q;
    s16 n;

    D_801EDC40->rot.vx = p->c0 << 4;
    D_801EDC40->rot.vy = p->c1 << 4;
    D_801EDC40->rot.vz = p->c2 << 4;
    func_8003C21C(&D_801EDC40->rot, &D_801EDC40->m);
    D_801EDC40->m.t[0] = p->unk4;
    D_801EDC40->m.t[1] = p->unk6;
    D_801EDC40->m.t[2] = p->unk8;
    D_801EDC40->sc.vx = D_801EDC40->sc.vy = D_801EDC40->sc.vz = p->unk18;
    func_8003B35C(&D_801EDC40->m, &D_801EDC40->sc);
    func_8003A63C(&D_801EDDF8, &D_801EDC40->m, &D_801EDC40->m);
    ((void (*)(MgMat *, s32, s32))func_801B4194)(&D_801EDC40->m, p->unk0, p->unk1A);
    if (D_80062D98 == 0) {
        p->unk6 += p->unkE;
        if (p->unk6 < -0x4E1F) {
            q = (MgTask *)func_801B1E40((s32)func_801B4A6C);
            if (q != NULL) {
                q->unk4 = p->unk4;
                q->unk6 = -0x4E20;
                q->unk8 = p->unk8;
                q->unk18 = func_80042DA8() % 0x5000 + 0x3000;
            }
            n = (u16)p->unk2 + 1;
            p->unk2 = n;
            if (n == 1) {
                p->unk6 = -0x4E20;
                p->unkE = func_80042DA8() % 200 + 0x64;
            } else {
                p->unk0 = -1;
            }
        } else {
            p->unkE = (p->unkE * 31 >> 5) - 0x32;
            p->c0 += 1;
            p->c1 += 8;
            p->c2 += 0x10;
        }
    }
}

void func_801B4E00(void) {
    MgTask *p;
    TuF4 *q;
    TuF4 *r;
    s32 i;

    q = D_80163C74;
    p = &D_80162978[D_8015169C];
    func_8003B48C(&D_801EDDF8);
    func_8003B51C(&D_801EDDF8);
    for (i = 0; i < D_801EDC44; i++) {
        func_8003BC9C(&D_801F500C[i * 6], (MgSVec *)(i * 0x30 + (s32)&D_801F500C[1]), (MgSVec *)(i * 0x30 + (s32)&D_801F500C[-1]), (MgSVec *)(i * 0x30 + (s32)&D_801F500C[2]), (s32)&q->xy0, (s32)&q->xy1, (s32)&q->xy2, (s32)&q->xy3, &D_801EDC48->otz, &D_801EDC48->flag);
        if (!(D_801EDC48->flag & 0x60000)) {
            *(s32 *)q = 0x05000000;
            *(s32 *)((u8 *)q + 4) = 0x28000000;
            r = q;
            q++;
            func_80046794(D_801517C0 + 0x406C, (s32)r);
        }
        func_8003BC9C((MgSVec *)(i * 0x30 + (s32)&D_801F500C[-1]), (MgSVec *)(i * 0x30 + (s32)&D_801F500C[2]), (MgSVec *)(i * 0x30 + (s32)&D_801F500C[4]), &D_801F500C[i * 6 + 3], (s32)&q->xy0, (s32)&q->xy1, (s32)&q->xy2, (s32)&q->xy3, &D_801EDC48->otz, &D_801EDC48->flag);
        if (!(D_801EDC48->flag & 0x60000)) {
            *(s32 *)q = 0x05000000;
            *(s32 *)((u8 *)q + 4) = 0x28000000;
            r = q;
            q++;
            func_80046794(D_801517C0 + 0x406C, (s32)r);
        }
    }
    D_80163C74 = q;
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x2D) {
            p->unk0 = -1;
        }
    }
}

void func_801B5050(TuSpr *p) {
    TuFT4 *q;
    s32 c;
    s32 t;

    c = 0x2C808080;
    q = D_80163C74;
    D_801EDC4C->n = func_8003BBDC(&p->pos, &q->xy0, &D_801EDC4C->otz, &D_801EDC4C->flag);
    if (!(D_801EDC4C->flag & 0x60000)) {
        q->tag = 0x09000000;
        q->rgbc = c;
        q->xy1 = q->xy0 + 1;
        q->xy2 = q->xy0 + 0x10000;
        q->xy3 = q->xy0 + 0x10001;
        q->uv0 = p->unk1A;
        q->uv1 = p->unk1A + 1;
        q->uv2 = p->unk1A + 0x100;
        q->uv3 = p->unk1A + 1;
        q->tpage = 0x12E;
        t = (D_801EDC4C->n >> 2) * 4 + 0x70;
        func_80046794(t + D_801517C0, (s32)q);
        D_80163C74 = q + 1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        p->pos.vy += p->unkE;
        if (p->pos.vy < -0x4E1F) {
            p->unk0 = -1;
        } else {
            p->unkE = (p->unkE * 15 >> 4) - 0x32;
        }
    }
}

void func_801B51E0(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 j;
    s32 a;
    s32 r;
    s32 x;
    s32 z;
    s32 ang;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            j = 0;
            q = (MgTask *)func_801B1E40((s32)&func_801B4BCC);
            q->unk0 = func_80042DA8() % 3;
            a = func_80042DA8() & 0xFFF;
            r = func_80042DA8() % 7000 + 3000;
            x = r * func_80039A74(a) >> 12;
            z = r * func_80039B40(a) >> 12;
            q->unk4 = x;
            q->unk6 = 0;
            q->unkE = 0;
            q->unk8 = z + 0x1B58;
            *(s32 *)&q->unk14 = func_80042DA8() & 0xFFFFFF;
            q->unk18 = func_80042DA8() % 0x600 + 0x100;
            q->unk1A = (u8)((x + 10000) / 250) | (u8)((z + 10000) / 250) << 8;
            r = q->unk18 * 625 >> 9;
            ang = 0;
            do {
                a = ang + func_80042DA8() % 512;
                k = r * func_80039A74(a) >> 12;
                D_801F5004[D_801EDC44][j].vy = 0;
                D_801F5004[D_801EDC44][j].vx = k + x;
                D_801F5004[D_801EDC44][j].vz = (r * func_80039B40(a) >> 12) + z + 0x1B58;
                ang += 0x2AA;
                j++;
            } while (j < 6);
            D_801EDC44++;
            i++;
        } while (i < 5);
        p->unk2++;
        if (p->unk2 >= 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B550C(void) {
    MgTask *p;
    MgTask *q;
    TuAct *e;
    s32 i;
    s32 k;
    s32 a;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = (u16)p->unkE - 0x32;
        e = &D_801518E4[p->unk0];
        p->unkE = t;
        e->py += t;
        if (e->py - e->unk12 < -0x4E1F) {
            e->py = e->unk12 - 0x4E20;
            i = 0;
            k = 0;
            do {
                q = (MgTask *)func_801B1E40((s32)&func_801B4B1C);
                i++;
                a = k + func_80042DA8() % 819;
                q->unk4 = e->px + (e->unk12 * func_80039A74(a) >> 12);
                q->unk6 = -0x4E20;
                q->unk8 = e->pz + (e->unk12 * func_80039B40(a) >> 12);
                q->unk18 = func_80042DA8() % 0x5000 + 0x3000;
                k += 0x333;
            } while (i < 5);
            if (p->unk2 == 0) {
                p->unkE = func_80042DA8() % 200 + 0xC8;
                p->unk2++;
            } else {
                func_800D5774(p->unk0);
                p->unk0 = -1;
            }
        }
    }
}

void func_801B575C(s16 arg0) {
    MgObj20 *temp_v0;

    temp_v0 = &D_80162978[func_800BBEAC(&func_801B550C)];
    temp_v0->unk0 = arg0;
    M2C_FIELD(temp_v0, s16 *, 0xE) = 0;
}

void func_801B57A8(void) {
    MgTask *p;
    s32 t;
    s16 *q;
    s32 i;
    s16 n;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            p->unk2++;
        } else {
            t = p->unk2;
            if (t == 1) {
                q = &D_80153BC8.vy;
                *q = -0xBB8;
                D_80153BCC = 0x1000;
                D_80153BC8.c0 = D_80153BC8.c1 = D_80153BC8.c2 = 0;
                D_80153BBE = 0xC00;
                for (i = 0; i < D_80153BC8.n; i++) {
                    D_80153BC8.f[i] |= 8;
                }
            }
            if (t >= 5) {
                D_80153BCC = 0x1000 - ((t - 5) << 12) / 10;
            }
            n = (u16)p->unk2 + 1;
            p->unk2 = n;
            if (n >= 0xF) {
                for (i = 0; i < D_80153BC8.n; i++) {
                    D_80153BC8.f[i] &= 0xF7;
                }
                p->unk0 = -1;
            }
        }
    }
}

INCLUDE_ASM("../asm/us/magic_tupon/nonmatchings/text", func_801B592C);

void func_801B5AB0(void) {
    MgTask *p;
    TuActor *b;
    s32 i;
    s32 t;
    s32 r;

    p = &D_80162978[D_8015169C];
    b = &D_80153BB8;
    if (p->unk2 == 0) {
        func_8003C21C(&D_801EDC70, (MgMat *)&b->w[50]);
    }
    t = p->unk2;
    if (t < 10) {
        r = (t << 12) / 10;
        for (i = 0; i <= 0; i++) {
            r = func_80039A74(r / 4);
        }
        b->w[55] = D_801EDC7C + ((D_801EDC84 - D_801EDC7C) * r >> 12);
        b->w[56] = D_801EDC7E + ((D_801EDC86 - D_801EDC7E) * r >> 12);
        b->w[57] = D_801EDC80 + ((D_801EDC88 - D_801EDC80) * r >> 12);
    } else {
        t -= 10;
        if (t >= 10) {
            t -= 10;
            if (t < 10) {
                r = (t << 12) / 10;
                r = 0x1000 - r;
                for (i = 0; i <= 0; i++) {
                    r = func_80039A74(r / 4);
                }
                r = 0x1000 - r;
                b->w[55] = D_801EDC84 + ((D_801EDC8C - D_801EDC84) * r >> 12);
                b->w[56] = D_801EDC86 + ((D_801EDC8E - D_801EDC86) * r >> 12);
                b->w[57] = D_801EDC88 + ((D_801EDC90 - D_801EDC88) * r >> 12);
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    func_801B592C();
    if (D_80062D98 == 0) {
        p->unk2++;
        D_801EDC78 = func_800D376C((s32)b + 0x174, D_801EDC78, b->n, D_801D84B4);
    }
}

void func_801B5D00(void) {
    MgTask *p;
    s32 c;
    u8 *q;

    p = &D_80162978[D_8015169C];
    if (p->unk2 < 0x14) {
        c = (p->unk2 << 12) / 20;
        func_8003B69C(0xFF, 0xFF, 0xFF);
        func_8003B710(&D_801EDCB4, c, (s32 *)((D_801EDCB8 << 4) + (s32)D_801EDC98));
        func_800D4484(D_801517C0 + 0x40A4, 0x20);
        q = D_801EDC98 - 4;
        func_80046794(D_801517C0 + 0x40A4, (D_801EDCB8 << 4) + (s32)q);
        func_800D4484(D_801517C0 + 0x40A4, 0x40);
        D_801EDCB8 ^= 1;
    } else {
        p->unk0 = -1;
        D_800F8380 |= 4;
        return;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

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

void func_801B64C8(arg0, arg1) {
    MgSVec sp10;
    s32 i;
    s32 k;

    func_800D2980(D_801B6660, 0, 0, 0);
    D_801EDE18 = arg0;
    func_800D54EC(arg0, &sp10);
    if (sp10.vz < D_80151A4C[arg1].vz) {
        D_801ED8DA = 0x800;
        k = sp10.vz + 0x1B58;
    } else {
        k = sp10.vz - 0x1B58;
    }
    D_801ED8D4 = k;
    func_8003C21C((MgSVec *)&D_801ED8D8, (MgMat *)&D_801ED8B8);
    for (i = 0; i < 10; i++) {
        D_801EDE1C[i] = D_80151A4C[i].vy;
    }
    func_801B1E1C();
    func_800BBEAC(&func_801B1EB8);
    if (~D_801517B4 & D_801EDE18) {
        D_801EDE30 = 0xF;
    } else {
        D_801EDE30 = 0;
    }
    ((void (*)(s32, s32, s32))func_801B10E8)((s32)&D_801ED928, (s32)&D_801ED8B8, arg1);
    func_800BBEAC(&func_801B5EE8);
    D_800F8380 |= 8;
}
