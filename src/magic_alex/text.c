#include "common.h"
#include "magic_alex/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B6AB0();
    return &D_801DED44;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F0632[-v];
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
    MgCam *cam;
    u8 pad[0x100];
    s32 flag;

    sv2 = (MgSVec *)0x1F800008;
    vec = (MgVec *)0x1F800010;
    p = (MgCamTask *)&D_80162978[D_8015169C];
    sv = (MgSVec *)0x1F800000;
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801EE17C.actor = -1;
            D_801EE1A4.actor = -1;
            D_801EE17C.frames = 0;
            D_801EE1A4.frames = 0;
            p->unk2 = 1;
        }
        while (D_801EE17C.frames == 0 || D_801EE1A4.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801EE1CC = &D_801EE17C;
                D_801EE1D0 = &D_801EE1A4;
            } else {
                D_801EE1CC = &D_801EE1A4;
                D_801EE1D0 = &D_801EE17C;
            }
            D_801EE1CC->mode = op & 0xFF3F;
            switch (D_801EE1CC->mode) {
            case 1:
                D_801EE1CC->pos.vx = *p->script++;
                D_801EE1CC->pos.vy = *p->script++;
                D_801EE1CC->pos.vz = *p->script++;
                break;
            case 2:
                D_801EE1CC->frames = func_801B0068(&p->script);
                D_801EE1CC->vel.vx = (*p->script++ - D_801EE1CC->pos.vx) / D_801EE1CC->frames;
                D_801EE1CC->vel.vy = (*p->script++ - D_801EE1CC->pos.vy) / D_801EE1CC->frames;
                D_801EE1CC->vel.vz = (*p->script++ - D_801EE1CC->pos.vz) / D_801EE1CC->frames;
                break;
            case 3:
                sv->vx = D_801EE1D0->pos.vx - D_801EE1CC->pos.vx;
                sv->vy = D_801EE1D0->pos.vy - D_801EE1CC->pos.vy;
                sv->vz = D_801EE1D0->pos.vz - D_801EE1CC->pos.vz;
                D_801EE1CC->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801EE1CC->unk18 = D_801EE1CC->pos;
                D_801EE1CC->frames = func_801B0068(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801EE1CC->vel.vx = (sv->vx - D_801EE1CC->pos.vx) / D_801EE1CC->frames;
                D_801EE1CC->vel.vy = (sv->vy - D_801EE1CC->pos.vy) / D_801EE1CC->frames;
                D_801EE1CC->vel.vz = (sv->vz - D_801EE1CC->pos.vz) / D_801EE1CC->frames;
                if (D_801EE1D0->mode == 2) {
                    sv2->vx = D_801EE1D0->pos.vx + D_801EE1D0->vel.vx * D_801EE1D0->frames;
                    sv2->vy = D_801EE1D0->pos.vy + D_801EE1D0->vel.vy * D_801EE1D0->frames;
                    sv2->vz = D_801EE1D0->pos.vz + D_801EE1D0->vel.vz * D_801EE1D0->frames;
                } else {
                    sv2->vx = D_801EE1D0->pos.vx;
                    sv2->vy = D_801EE1D0->pos.vy;
                    sv2->vz = D_801EE1D0->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801EE1CC->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801EE1CC->unk4) / D_801EE1CC->frames;
                break;
            case 4:
                D_801EE1CC->frames = func_801B0068(&p->script);
                sv->vx = *p->script++ - D_801EE1CC->pos.vx;
                sv->vy = *p->script++ - D_801EE1CC->pos.vy;
                sv->vz = *p->script++ - D_801EE1CC->pos.vz;
                D_801EE1CC->unk18.vx = ((sv->vx - D_801EE1CC->vel.vx * D_801EE1CC->frames) * 2) / (D_801EE1CC->frames * D_801EE1CC->frames);
                D_801EE1CC->unk18.vy = ((sv->vy - D_801EE1CC->vel.vy * D_801EE1CC->frames) * 2) / (D_801EE1CC->frames * D_801EE1CC->frames);
                D_801EE1CC->unk18.vz = ((sv->vz - D_801EE1CC->vel.vz * D_801EE1CC->frames) * 2) / (D_801EE1CC->frames * D_801EE1CC->frames);
                break;
            case 5:
                D_801EE1CC->frames = func_801B0068(&p->script);
                D_801EE1CC->unk4 = 0;
                D_801EE1CC->unk8 = 0x1000 / D_801EE1CC->frames;
                D_801EE1CC->unk18.vx = D_801EE1CC->pos.vx;
                D_801EE1CC->unk18.vy = D_801EE1CC->pos.vy;
                D_801EE1CC->unk18.vz = D_801EE1CC->pos.vz;
                D_801EE1CC->vel.vx = *p->script++ - D_801EE1CC->pos.vx;
                D_801EE1CC->vel.vy = *p->script++ - D_801EE1CC->pos.vy;
                D_801EE1CC->vel.vz = *p->script++ - D_801EE1CC->pos.vz;
                break;
            case 6:
                if ((D_801EE1CC->actor = *p->script++) == 0) {
                    D_801EE1CC->actor = p->actor;
                }
                D_801EE1CC->part = *p->script++;
                break;
            case 7:
                D_801EE1CC->actor = -1;
                break;
            case 0:
            case 8:
                D_801EE1CC->frames = func_801B0068(&p->script);
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801EE1CC = &D_801EE17C;
        D_801EE1D0 = &D_801EE1A4;
        for (i = 0; i < 2; i++) {
            switch (D_801EE1CC->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801EE1CC->vel.vx += D_801EE1CC->unk18.vx;
                D_801EE1CC->vel.vy += D_801EE1CC->unk18.vy;
                D_801EE1CC->vel.vz += D_801EE1CC->unk18.vz;
            case 2:
                D_801EE1CC->pos.vx += D_801EE1CC->vel.vx;
                D_801EE1CC->pos.vy += D_801EE1CC->vel.vy;
                D_801EE1CC->pos.vz += D_801EE1CC->vel.vz;
                break;
            case 3:
                D_801EE1CC->unk18.vx += D_801EE1CC->vel.vx;
                D_801EE1CC->unk18.vy += D_801EE1CC->vel.vy;
                D_801EE1CC->unk18.vz += D_801EE1CC->vel.vz;
                D_801EE1CC->unk4 += D_801EE1CC->unk8;
                vec->vx = D_801EE1D0->pos.vx - D_801EE1CC->unk18.vx;
                vec->vy = D_801EE1D0->pos.vy - D_801EE1CC->unk18.vy;
                vec->vz = D_801EE1D0->pos.vz - D_801EE1CC->unk18.vz;
                func_8003A078(vec, sv);
                D_801EE1CC->pos.vx = D_801EE1D0->pos.vx - ((sv->vx * D_801EE1CC->unk4) >> 12);
                D_801EE1CC->pos.vy = D_801EE1D0->pos.vy - ((sv->vy * D_801EE1CC->unk4) >> 12);
                D_801EE1CC->pos.vz = D_801EE1D0->pos.vz - ((sv->vz * D_801EE1CC->unk4) >> 12);
                break;
            case 5:
                D_801EE1CC->unk4 += D_801EE1CC->unk8;
                k = D_801EE1CC->unk4;
                k = ((s32 (*)(s32))func_80039A74)(((s32 (*)(s32))func_80039A74)(k / 4) / 4);
                D_801EE1CC->pos.vx = D_801EE1CC->unk18.vx + ((D_801EE1CC->vel.vx * k) >> 12);
                D_801EE1CC->pos.vy = D_801EE1CC->unk18.vy + ((D_801EE1CC->vel.vy * k) >> 12);
                D_801EE1CC->pos.vz = D_801EE1CC->unk18.vz + ((D_801EE1CC->vel.vz * k) >> 12);
                break;
            }
            cam = D_801EE1CC;
            D_801EE1CC = &D_801EE1A4;
            D_801EE1D0 = &D_801EE17C;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801EE17C.mode != 8) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801EE17C.actor == -1) {
                func_8003BC6C(&D_801EE17C.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801EE17C.pos, vec);
                if (D_801EE17C.part != -1) {
                    func_800D3994(D_801EE17C.actor, D_801EE17C.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801EE17C.actor].vx;
                    sv->vy = D_80151A4C[D_801EE17C.actor].vy;
                    sv->vz = D_80151A4C[D_801EE17C.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801EE1A4.mode != 8) {
            if (D_801EE1A4.actor == -1) {
                func_8003BC6C(&D_801EE1A4.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801EE1A4.pos, vec);
                if (D_801EE1A4.part != -1) {
                    func_800D3994(D_801EE1A4.actor, D_801EE1A4.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801EE1A4.actor].vx;
                    sv->vy = D_80151A4C[D_801EE1A4.actor].vy;
                    sv->vz = D_80151A4C[D_801EE1A4.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801EE17C.mode != 8) {
            D_80158D00 = D_801EE17C.pos;
        }
        if (D_801EE1A4.mode != 8) {
            D_801031E8 = D_801EE1A4.pos;
        }
    }
}

void func_801B10C0(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B00A4)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B1124);

void func_801B1BE4(MgMat *arg0, u16 *arg1) {
    s32 sp10;
    s32 sp14;
    MgHalf *p;
    MgHalf *q;
    MgWord *w;
    u8 *s;
    MgHalf *r;

    func_80044AC0(D_801EE1D4, D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, D_801EE1D4);
    p = (MgHalf *)&D_801EDB88;
    p->v = D_801EDB98.v = arg1[2];
    D_801EDB92 = D_801EDB9A = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (u8 *)p - 0x10);
    func_8003B64C(&sp10, &sp14);
    func_8003B6BC((s16)arg1[2] / 2, (s16)arg1[3] / 2);
    func_8003B48C(arg0);
    func_8003B51C(arg0);
    w = (MgWord *)&D_801EDB58;
    w->v = D_8016209C;
    func_8003B69C(D_800F5B70, D_800F5B71, D_800F5B72);
    D_801EDB62 = D_800F5B74;
    D_80163C74 = func_801B1124((s32 *)w, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B6BC(sp10, sp14);
    q = (MgHalf *)&D_801EDB74;
    q->v = arg1[2];
    D_801EDB76 = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (u8 *)q - 0xC);
    func_80044978(D_801EE214, arg1);
    func_80046794(D_801517C0 + 0x4084, D_801EE214);
    s = D_801EE220;
    r = (MgHalf *)&D_801EE22C;
    r->v = arg1[0];
    D_801EE22E = arg1[1];
    func_800449FC(s, r);
    func_80046794(D_801517C0 + 0x4084, s);
}

void func_801B1E24(MgSVecList *a, MgSVec *b, MgSVec *out) {
    s32 i;
    s32 n;
    MgSVec *s;

    n = a->n / 8;
    s = a->v;
    for (i = 0; i < n; i++) {
        out->vx = s->vx - b->vx;
        out->vy = s->vy - b->vy;
        out->vz = s->vz - b->vz;
        s++;
        b++;
        out++;
    }
}

void func_801B1EB4(MgSVecList *a, MgSVec *b, MgSVec *d, s32 t) {
    s32 i;
    s32 n;
    MgSVec *s;

    n = a->n / 8;
    s = a->v;
    t = 0x1000 - t;
    for (i = 0; i < n; i++) {
        s->vx = b->vx + ((d->vx * t) >> 12);
        s->vy = b->vy + ((d->vy * t) >> 12);
        s->vz = b->vz + ((d->vz * t) >> 12);
        s++;
        b++;
        d++;
    }
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B1F7C);

void func_801B2AE4(void) {
    s32 *p;
    s32 i;

    i = 199;
    p = &D_801F1C24;
    for (; i >= 0; i--) {
        *p-- = 0;
    }
}

AlxPart *func_801B2B08(s32 arg0) {
    s32 i;

    for (i = 0; i < 200; i++) {
        if (D_801F1908[i] == 0) {
            D_801F1908[i] = arg0;
            D_801F0648[i].unk0 = 0;
            D_801F0648[i].unk2 = 0;
            return &D_801F0648[i];
        }
    }
    return 0;
}

void func_801B2B80(void) {
    MgTask *p;
    s32 n;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    n = 0;
    for (i = 0; i < 200; i++) {
        if (D_801F1908[i] != 0) {
            ((void (*)(AlxPart *))D_801F1908[i])(&D_801F0648[i]);
            if (D_801F0648[i].unk0 == -1) {
                D_801F1908[i] = 0;
            } else {
                n++;
            }
        }
    }
    if (n == 0 && D_80162080 < 2) {
        p->unk0 = -1;
    }
}

MgMat *func_801B2C78(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EDDEC.m[0][0] = D_801EDDEC.m[1][1] = D_801EDDEC.m[2][2] = scale;
    func_8003B48C(&D_801F0610);
    func_8003B51C(&D_801F0610);
    func_8003BC6C(v, (MgVec *)D_801EDDEC.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EDDEC.t, &n);
        D_801EDDEC.t[0] += (dist * n.vx) >> 12;
        D_801EDDEC.t[1] += (dist * n.vy) >> 12;
        D_801EDDEC.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EDDEC);
    func_8003B51C(&D_801EDDEC);
    return &D_801EDDEC;
}

void func_801B2D94(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        D_801EE234 = 0;
        D_801EE230 = 0;
        if (t >= 0x28) {
            t -= 0x28;
            if (t < 0x1E) {
                D_801EE234 = 0x32;
                goto shake;
            }
            t -= 0x1E;
            if (t >= 0xA) {
                p->unk0 = -1;
                return;
            }
            k = (((0x1000 - ((t << 12) / 10)) * 2) * 25) >> 12;
        } else {
            k = 0x32;
        }
        D_801EE230 = k;
shake:
        if ((u16)p->unk2 & 1) {
            do {
                D_80158D02[0] += (u16)D_801EE230;
                D_801031EA[0] += (u16)D_801EE230;
            } while (0);
            D_80158D04 += (u16)D_801EE234;
            D_801031EC += (u16)D_801EE234;
        } else {
            do {
                /* identical arms: the dead test keeps the game's registers */
                if (D_801031EC) {
                    D_80158D02[0] -= (u16)D_801EE230;
                    D_801031EA[0] -= (u16)D_801EE230;
                } else {
                    D_80158D02[0] -= (u16)D_801EE230;
                    D_801031EA[0] -= (u16)D_801EE230;
                }
            } while (0);
            D_80158D04 -= (u16)D_801EE234;
            D_801031EC -= (u16)D_801EE234;
        }
        p->unk2++;
    }
}

void func_801B2F38(void) {
    MgMat m;

    D_801EDE3C = D_801EDB30;
    D_801EDE2C = D_801EDB30;
    if (D_801EDB52 != 0) {
        D_801EDE48 = D_801EDB4C;
    } else {
        D_801EDE48 = -D_801EDB4C;
    }
    func_8003A63C(&D_801EDE0C, &D_801EDE2C, &m);
    func_801B1BE4(&m, &D_801EDE4C);
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B2FC8);

M2C_UNK func_801B3430(void *arg0, s16 arg1, s16 arg2) {
    s32 r;

    func_801B2C78((MgSVec *)arg0, arg2, 0);
    D_801EDF9C[0] = arg1;
    r = func_800D4D90(&D_801EDF9C[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    D_80163C74 = r;
    return r;
}

void func_801B3498(void *arg0) {
    s16 temp_v0;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_v0_2;

    func_801B3430(arg0 + 4, M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 0x14));
    if (D_80062D98 == 0) {
        temp_v0 = (u16) M2C_FIELD(arg0, s16 *, 2) + 1;
        M2C_FIELD(arg0, s16 *, 2) = temp_v0;
        if ((s32) D_801DEA40 < temp_v0) {
            M2C_FIELD(arg0, s16 *, 0) = -1;
            return;
        }
        M2C_FIELD(arg0, u16 *, 6) = (u16) (M2C_FIELD(arg0, u16 *, 6) + M2C_FIELD(arg0, u16 *, 0xE));
        temp_s0 = func_80039A74(M2C_FIELD(arg0, s16 *, 0xC));
        temp_v0_2 = func_80039B40(M2C_FIELD(arg0, s16 *, 0xC));
        temp_a1 = (s32) ((temp_v0_2 * M2C_FIELD(arg0, s16 *, 4)) + (temp_s0 * M2C_FIELD(arg0, s16 *, 8))) >> 0xC;
        M2C_FIELD(arg0, s16 *, 4) = (s16) temp_a1;
        M2C_FIELD(arg0, s16 *, 8) = (s16) ((s32) ((-temp_s0 * (s16) temp_a1) + (temp_v0_2 * M2C_FIELD(arg0, s16 *, 8))) >> 0xC);
    }
}

void func_801B359C(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 n;
    s32 i;
    u8 pad[8];

    p = (MgTask *)&D_80162978[D_8015169C];
    i = D_80062D98 == 0;
    if (i) {
        t = p->unk2;
        n = 1;
        if (t >= 0xA) {
            t -= 0xA;
            if (t < 0x1E) {
                n = 2;
            } else {
                t -= 0x1E;
                n = 6;
                if (t < 0x1E) {
                    n = 4;
                }
            }
        }
        i = 0;
        if (n != 0) {
            do {
                q = (MgTask *)func_801B2B08((s32)func_801B3498);
                q->unk6 = 0;
                switch (func_80042DA8() % 3) {
                case 0:
                    q->unk4 = func_80042DA8() % 4000 + 0x7D0;
                    q->unk8 = func_80042DA8() % 12000 - 0x1770;
                    break;
                case 1:
                    q->unk4 = -(func_80042DA8() % 4000 + 0x7D0);
                    q->unk8 = func_80042DA8() % 12000 - 0x1770;
                    break;
                case 2:
                    q->unk4 = func_80042DA8() % 12000 - 0x1770;
                    q->unk8 = func_80042DA8() % 4000 + 0x7D0;
                    break;
                }
                q->unkE = -(func_80042DA8() % 80 + 0x14);
                q->unkC = -(func_80042DA8() % 64);
                q->unk14 = func_80042DA8() % 14336 + 0x1800;
                i++;
            } while (i < n);
        }
        p->unk2++;
        if (p->unk2 >= 0x8C) {
            p->unk0 = -1;
        }
    }
}

void func_801B3924(void) {
    AlxObj *p;
    s32 t;
    s32 k;
    s32 *fd;

    p = (AlxObj *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xA) {
        D_801EDFA8 = 0x80;
        D_801EDFAE = 0;
    } else {
        t -= 0xA;
        if (t < 5) {
            D_801EDFA8 = 0x88;
            D_801EDFAE = (t << 12) / 5;
        } else {
            goto kill;
        }
    }
    D_801EDFC0->rot.vx = p->a0 * 0x10;
    D_801EDFC0->rot.vy = p->a1 * 0x10;
    D_801EDFC0->rot.vz = p->a2 * 0x10;
    func_8003BF8C(&D_801EDFC0->rot, &D_801EDFC0->m);
    D_801EDFC0->m.t[0] = p->unk4;
    D_801EDFC0->m.t[1] = p->unk6;
    D_801EDFC0->m.t[2] = p->unk8;
    k = p->unk18;
    D_801EDFC0->sc.vx = D_801EDFC0->sc.vy = D_801EDFC0->sc.vz = k;
    func_8003B35C(&D_801EDFC0->m, &D_801EDFC0->sc);
    func_8003A63C(&D_801F0610, &D_801EDFC0->m, &D_801EDFC0->m);
    func_8003B48C(&D_801EDFC0->m);
    func_8003B51C(&D_801EDFC0->m);
    fd = &D_801EDFA4;
    *fd = D_801EDFB4[p->unk0];
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(fd, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        if (p->unk6 > 0) {
kill:
            p->unk0 = -1;
        } else {
            p->unk8 += p->unk10;
            p->unkC = p->unkC * 15 >> 4;
            p->unkE = (p->unkE * 15 >> 4) + 0x32;
            p->unk10 = p->unk10 * 15 >> 4;
            p->a0 += 8;
            p->a1 += 0x10;
            p->a2 += 0x20;
        }
    }
}

void func_801B3BAC(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 ang;
    s32 k;
    s32 u;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B3924)];
            q->unk0 = func_80042DA8() % 3;
            ang = func_80042DA8() % 3584 - 0x300;
            q->unk4 = (u32)(((s32 (*)(s32))func_80039B40)(ang) * 0x177) >> 9;
            u = 0x1B58;
            q->unk6 = func_80042DA8() % 4000 + (D_80153D22 - u);
            q->unk8 = (((s32 (*)(s32))func_80039A74)(ang) * 0x5DC >> 12) - 0x1F4;
            k = func_80042DA8() % 70 + 0x50;
            r = k * ((s32 (*)(s32))func_80039B40)(ang);
            q->unkE = 0;
            q->unkC = r >> 12;
            q->unk10 = k * ((s32 (*)(s32))func_80039A74)(ang) >> 12;
            q->unk18 = func_80042DA8() % 256 + 0x50;
            i++;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B3E14(void *arg0) {
    s16 temp_v0;

    func_801B3430(arg0 + 4, M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 0x14));
    if (D_80062D98 == 0) {
        temp_v0 = (u16) M2C_FIELD(arg0, s16 *, 2) + 1;
        M2C_FIELD(arg0, s16 *, 2) = temp_v0;
        if (temp_v0 >= (s32) D_801DEA40) {
            M2C_FIELD(arg0, s16 *, 0) = -1;
            return;
        }
        M2C_FIELD(arg0, u16 *, 6) = (u16) (M2C_FIELD(arg0, u16 *, 6) + 0x82);
    }
}

s32 func_801B3EA0(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s16 ang;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            i++;
            q = (MgTask *)func_801B2B08((s32)func_801B3E14);
            ang = func_80042DA8() & 0x7FF;
            q->unk4 = (u32)(func_80039B40(ang) * 0x177) >> 9;
            q->unk6 = func_80042DA8() % 5000 - 0x1770;
            q->unk8 = (func_80039A74(ang) * 0x5DC >> 12) - 0x1F4;
            q->unk14 = func_80042DA8() % 12288 + 0x1000;
        } while (i < 4);
        p->unk2++;
        if (p->unk2 >= 0x2D) {
            p->unk0 = -1;
        }
    }
}

void func_801B402C(void) {
    MgTask *p;
    s32 t;
    s32 a;
    u8 pad[8];

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        a = (t << 12) / 10;
        a = (0x1000 - a) * 0x28 >> 12;
        if (t & 1) {
            D_80158D02[0] += a;
            D_801031EA[0] += a;
        } else {
            D_80158D02[0] -= a;
            D_801031EA[0] -= a;
        }
        p->unk2++;
        if (p->unk2 >= 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B4118(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B3430(&p->unk4, p->unk2, p->unk18);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= ((MgByte *)&D_801DEA40)->v) {
            p->unk0 = -1;
            return;
        }
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC = p->unkC * 15 >> 4;
        p->unk10 = p->unk10 * 15 >> 4;
    }
}

void func_801B4200(MgTask *p) {
    func_801B2C78((MgSVec *)&p->unk4, p->unk14, 0);
    D_801EDFD0[0] = p->unk2 * ((MgByte *)&D_801DEA40)->v / 10 | 0x8000;
    D_80163C74 = func_800D4D90((s16 *)&D_801EDFD0[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0xA) {
            p->unk0 = -1;
            return;
        }
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC = p->unkC * 7 >> 3;
        p->unkE = p->unkE * 7 >> 3;
        p->unk10 = p->unk10 * 7 >> 3;
    }
}

s32 func_801B4348(void) {
    MgTask *p;
    MgTask *q;
    MgSVec *b;
    u16 *c;
    u16 *z;
    s32 i;
    u16 *r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        if (p->unk2 == 0) {
            i = 2;
            z = &D_801F05FC;
            do {
                *z = 0;
                i--;
                z--;
            } while (i >= 0);
            i = 0;
        }
        b = &D_801EDFD4;
        do {
            r = D_801F05F8;
            c = &r[i];
            *c = (s16)*c - 1;
            if ((s16)*c == -1) {
                D_801F05F0[i] = func_80042DA8() % 1536 + 0x100;
                *c = func_80042DA8() % 3 + 2;
                D_801F0600[i] = func_80042DA8() % 300 + 0x64;
            }
            D_801EDFDC->v.vx = 0;
            D_801EDFDC->v.vy = D_801F05F0[i];
            D_801EDFDC->v.vz = -0x120;
            func_8003C21C(&D_801EDFDC->v, &D_801EDFDC->m);
            q = (MgTask *)func_801B2B08((s32)func_801B4200);
            D_801EDFDC->v.vx = -0x12C;
            D_801EDFDC->v.vy = 0;
            D_801EDFDC->v.vz = 0;
            func_8003B2CC(&D_801EDFDC->m, &D_801EDFDC->v, &D_801EDFDC->v);
            q->unk4 = D_801EDFDC->v.vx + b->vx;
            q->unk6 = D_801EDFDC->v.vy + b->vy;
            q->unk8 = D_801EDFDC->v.vz + b->vz;
            D_801EDFDC->v.vx = -D_801F0600[i];
            D_801EDFDC->v.vy = 0;
            D_801EDFDC->v.vz = 0;
            func_8003B2CC(&D_801EDFDC->m, &D_801EDFDC->v, (MgSVec *)&q->unkC);
            q->unk14 = func_80042DA8() % 0x800 + 0x1000;
            i++;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 5) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B4614(s32 arg0) {
    s32 r;
    s32 g;
    s32 b;
    s32 u;

    if (arg0 < 0x555) {
        arg0 *= 3;
        r = (-(arg0 << 7) >> 12) - 0x80;
        g = (-(arg0 << 6) >> 12) - 0x80;
        b = 0x80;
    } else {
        arg0 -= 0x555;
        if (arg0 < 0x555) {
            arg0 *= 3;
            r = (u32)arg0 >> 7;
            u = -(arg0 << 6) >> 12;
            g = u + 0x40;
            b = u - 0x80;
        } else {
            arg0 -= 0x555;
            if (arg0 >= 0x555) {
                return 0;
            }
            arg0 *= 3;
            r = (-(arg0 << 5) >> 12) + 0x20;
            g = 0;
            b = (-(arg0 << 6) >> 12) + 0x40;
        }
    }
    return (r & 0xFF) | ((g & 0xFF) << 8) | ((b & 0xFF) << 16);
}

void func_801B46E0(void) {
    MgTask *p;
    s32 a;
    s32 b;
    s32 c;
    s32 x;
    s32 q;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_801F0608 = (AxG3 *)D_80163C74;
    func_8003B48C(&D_801F0610);
    func_8003B51C(&D_801F0610);
    gte_ldv3_m(&D_801EDFE0[p->unk0], &p->unk4, &p->unkC);
    gte_rtpt();
    gte_stsxy3_mm(&D_801F0608->xy0, &D_801F0608->xy1, &D_801F0608->xy2);
    gte_stdp_m(&D_801EDFF0->dp);
    gte_stflg_m(&D_801EDFF0->flag);
    gte_avsz3();
    gte_stotz_m(D_801EDFF0);
    if ((D_801EDFF0->flag & 0x60000) == 0) {
        a = p->unk2;
        c = p->unk1C;
        q = (a << 12) / 6;
        x = c + (((0x1000 - c) * q) >> 12);
        a++;
        b = p->unk1E;
        q = (a << 12) / 6;
        b += ((0x1000 - b) * q) >> 12;
        x = func_801B4614(x);
        b = func_801B4614(b);
        D_801F0608->rgbc = x | 0x32000000;
        do {
            D_801F0608->c1 = x;
        } while (0);
        D_801F0608->c2 = b;
        D_801F0608->tag = 0x06000000;
        k = ((D_801EDFF0->otz >> 2) << 2) + 0x70;
        func_80046794(k + D_801517BC.ot, D_801F0608);
        D_80163C74 = (s32)(D_801F0608 + 1);
    }
    if (D_80062D98 == 0) {
        p->unk2 += 2;
        if (p->unk2 >= 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B4970(void) {
    MgTask *p;
    MgMat *mat;
    s32 t;
    s32 k;
    s32 r;
    s32 z;
    s32 c;
    u8 *pk;
    u8 *pk0;
    s32 tag;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_801F060C = (u8 *)D_80163C74;
    mat = &D_801F0610;
    func_8003B48C(mat);
    func_8003B51C(mat);
    t = p->unk2 + p->unk0;
    z = 0x64;
    if (t < 0xF) {
        c = 0x808080;
    } else {
        t -= 0xF;
        if (t < 0xF) {
            k = (t << 12) / 15;
            z = (k * 0x384 >> 12) + 0x64;
            r = (-(k << 7) >> 12) + 0x80;
            c = 0x80 | r << 8 | r << 16;
        } else {
            z = 0x3E8;
            c = 0x80;
        }
    }
    pk0 = D_801F060C;
    D_801EDFF4->v[0].vx = D_801EDFF4->v[2].vx = p->unk4;
    *(s16 *)((u8 *)D_801EDFF4 + 4) = p->unk8 - z;
    D_801EDFF4->v[2].vz = p->unk8;
    D_801EDFF4->v[0].vy = D_801EDFF4->v[2].vy = 0;
    t = p->unkC;
    D_801EDFF4->v[1].vx = D_801EDFF4->v[3].vx = t;
    D_801EDFF4->v[1].vz = p->unk10 - z;
    D_801EDFF4->v[3].vz = p->unk10;
    D_801EDFF4->v[1].vy = D_801EDFF4->v[3].vy = 0;
    func_8003BC9C(&D_801EDFF4->v[0], &D_801EDFF4->v[1], &D_801EDFF4->v[2], &D_801EDFF4->v[3], pk0 + 8, pk0 + 0x10, pk0 + 0x18, pk0 + 0x20, &D_801EDFF4->ext, &D_801EDFF4->flag);
    if (!(D_801EDFF4->flag & 0x60000)) {
        pk = D_801F060C;
        *(s32 *)(pk + 4) = *(s32 *)(pk + 0xC) = 0x3A000000;
        *(s32 *)(pk + 0x14) = *(s32 *)(pk + 0x1C) = c;
        t = D_801517C0 + 0x406C;
        *(s32 *)pk = 0x08000000;
        func_80046794(t, pk);
        D_801F060C += 0x24;
    }
    D_801EDFF4->v[0].vz += z;
    D_801EDFF4->v[2].vz += z;
    D_801EDFF4->v[1].vz += z;
    D_801EDFF4->v[3].vz += z;
    func_8003BC9C(&D_801EDFF4->v[0], &D_801EDFF4->v[1], &D_801EDFF4->v[2], &D_801EDFF4->v[3], D_801F060C + 8, D_801F060C + 0x10, D_801F060C + 0x18, D_801F060C + 0x20, &D_801EDFF4->ext, &D_801EDFF4->flag);
    if (!(D_801EDFF4->flag & 0x60000)) {
        pk = D_801F060C;
        tag = c | 0x3A000000;
        *(s32 *)(pk + 4) = *(s32 *)(pk + 0xC) = tag;
        *(s32 *)(pk + 0x14) = *(s32 *)(pk + 0x1C) = 0x3A000000;
        z = D_801517C0 + 0x406C;
        *(s32 *)pk = 0x08000000;
        func_80046794(z, pk);
        D_801F060C += 0x24;
    }
    D_80163C74 = (s32)D_801F060C;
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 + p->unk0 >= 0x23) {
            p->unk0 = -1;
        }
    }
}

void func_801B4CD4(void) {
    MgTask *p;
    MgTask *q;
    s32 j;
    s32 t;
    s32 s;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        j = 0;
        D_801EDFF8->a.vx = 0;
        D_801EDFF8->a.vy = (u16)p->unk8;
        D_801EDFF8->a.vz = 0;
        func_8003C21C(&D_801EDFF8->a, &D_801EDFF8->m);
        do {
            D_801EDFF8->b.vx = (u32)(((s32 (*)(s32))func_80039B40)(p->unk4) * 0x177) >> 9;
            D_801EDFF8->b.vy = 0;
            s = ((s32 (*)(s32))func_80039A74)(p->unk4);
            k = ((s32 (*)(s32))func_80039A74)(p->unk6);
            D_801EDFF8->b.vz = (s * 0x3E8 >> 12) + (p->unk18 * k >> 12);
            func_8003B2CC(&D_801EDFF8->m, &D_801EDFF8->b, &D_801EDFF8->b);
            D_801EDFF8->b.vz += 0x1388;
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            D_801EDFF8->a.vx = (u32)(((s32 (*)(s32))func_80039B40)(p->unk4) * 0x177) >> 9;
            D_801EDFF8->a.vy = 0;
            s = ((s32 (*)(s32))func_80039A74)(p->unk4);
            k = ((s32 (*)(s32))func_80039A74)(p->unk6);
            D_801EDFF8->a.vz = (s * 0x3E8 >> 12) + (p->unk18 * k >> 12);
            func_8003B2CC(&D_801EDFF8->m, &D_801EDFF8->a, &D_801EDFF8->a);
            D_801EDFF8->a.vz += 0x1388;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B46E0)];
            t = (u16)p->unk0;
            q->unk2 = 1 - j;
            q->unk0 = t;
            t = p->unk2;
            if (t < 0xA) {
                q->unk1C = 0;
                q->unk1E = 0;
            } else {
                t -= 0xA;
                t *= 2;
                t += j;
                q->unk1E = (t << 12) / 10;
                q->unk1C = ((t + 1) << 12) / 10;
            }
            *(MgB8 *)&q->unk4 = *(MgB8 *)&D_801EDFF8->a;
            *(MgB8 *)&q->unkC = *(MgB8 *)&D_801EDFF8->b;
            j++;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B4970)];
            q->unk0 = p->unk2;
            *(MgB8 *)&q->unk4 = *(MgB8 *)&D_801EDFF8->a;
            *(MgB8 *)&q->unkC = *(MgB8 *)&D_801EDFF8->b;
        } while (j < 2);
        p->unk2++;
        if (p->unk2 >= 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B5084(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        D_801EE006 = 0;
    } else {
        t -= 5;
        if (t < 0) {
            k = (t << 12) / 0;
            D_801EE006 = k;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    k = (p->unk2 << 12) / 5;
    func_801B2C78((MgSVec *)&p->unk4, ((k * 0x5B00) >> 12) + 0x500, 0);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EDFFC, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B51EC(void) {
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_801EE0B0->sc.vy = D_801EE0B0->sc.vz = 0x1000;
    t = p->unk2;
    if (t < 5) {
        D_801EE0B0->sc.vx = p->unk18 * ((t << 12) / 5) >> 12;
        D_801EE0AA.v = 0;
    } else {
        t -= 5;
        if (t < 5) {
            D_801EE0B0->sc.vx = p->unk18;
            D_801EE0AA.v = (t << 12) / 5;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003C21C((MgSVec *)&p->unkC, &D_801EE0B0->m);
    D_801EE0B0->m.t[0] = p->unk4;
    D_801EE0B0->m.t[1] = p->unk6;
    D_801EE0B0->m.t[2] = p->unk8;
    func_8003B35C(&D_801EE0B0->m, &D_801EE0B0->sc);
    func_8003A63C(&D_801F0610, &D_801EE0B0->m, &D_801EE0B0->m);
    func_8003B48C(&D_801EE0B0->m);
    func_8003B51C(&D_801EE0B0->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EE0A0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B53B0(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 a;
    s32 ang;
    s32 r;
    s32 u;
    s32 rr;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        a = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B51EC)];
            rr = func_80042DA8();
            r = a / 3;
            u = rr % 1194 - 0x100;
            ang = r + u;
            q->unk4 = (u32)(((s32 (*)(s32))func_80039A74)(ang) * 0x7D) >> 9;
            q->unk6 = 0;
            q->unk8 = (((s32 (*)(s32))func_80039B40)(ang) * 0x3E8 >> 12) + 0x1388;
            q->unkC = -(func_80042DA8() % 256 + 0x200);
            q->unkE = ang;
            q->unk10 = 0;
            q->unk18 = func_80042DA8() % 0x1000 + 0x1000;
            a += 0xE00;
            i++;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 3) {
            p->unk0 = -1;
        }
    }
}

void func_801B5584(void) {
    MgTask *p;
    s32 t;
    s32 i;
    s32 a;
    s32 q;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xF) {
        D_801EE0BE = 0;
    } else {
        t -= 0xF;
        if (t < 0xA) {
            D_801EE0BE = (t << 12) / 10;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    i = 0;
    q = (p->unk2 << 12) / 25;
    a = q;
    do {
        a = ((s32 (*)(s32))func_80039A74)(a / 4);
        i++;
    } while (i < 4);
    q = (a * 0x600 >> 12) + (q * 0xA00 >> 12);
    D_801EE0C4.m[0][0] = D_801EE0C4.m[2][2] = 0x2500;
    D_801EE0C4.m[1][1] = (u32)(q * 0x35) >> 4;
    func_8003A63C(&D_801F0610, &D_801EE0C4, D_801EE0E4);
    func_8003B48C(D_801EE0E4);
    func_8003B51C(D_801EE0E4);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EE0B4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B5770(void) {
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t >= 0xC) {
        p->unk0 = -1;
        return;
    }
    func_8003B48C(&D_801EE124);
    func_8003B51C(&D_801EE124);
    D_801EE118[0] = D_801EE0E8[t];
    D_80163C74 = func_800D4D90(D_801EE118, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B5850(void) {
    AlxObj *p;
    s32 t;
    s32 k;
    s32 *fd;

    p = (AlxObj *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 8) {
        D_801EE148 = 0x80;
        D_801EE14E = 0;
    } else {
        t -= 8;
        if (t < 6) {
            D_801EE148 = 0x88;
            D_801EE14E = (t << 12) / 6;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    D_801EE160->rot.vx = p->a0 * 0x10;
    D_801EE160->rot.vy = p->a1 * 0x10;
    D_801EE160->rot.vz = p->a2 * 0x10;
    func_8003BF8C(&D_801EE160->rot, &D_801EE160->m);
    D_801EE160->m.t[0] = p->unk4;
    D_801EE160->m.t[1] = p->unk6;
    D_801EE160->m.t[2] = p->unk8;
    k = p->unk18;
    D_801EE160->sc.vx = D_801EE160->sc.vy = D_801EE160->sc.vz = k;
    func_8003B35C(&D_801EE160->m, &D_801EE160->sc);
    func_8003A63C(&D_801F0610, &D_801EE160->m, &D_801EE160->m);
    func_8003B48C(&D_801EE160->m);
    func_8003B51C(&D_801EE160->m);
    fd = &D_801EE144;
    *fd = D_801EE154[p->unk0];
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(fd, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        k = 0x1E;
        p->unk6 = (u16)p->unk6 - k + (u16)p->unk1A;
        p->unk1A = p->unk1A * 13 >> 4;
        p->a0 += 4;
        p->a1 += 8;
        p->a2 += 0x15;
    }
}

void func_801B5A90(void) {
    MgTask *p;
    u8 *tab;
    u8 *t;
    u8 *a;
    u8 *c;
    u8 *q;
    u8 *r;
    s32 i;
    s32 off;
    MgMat *mat;

    mat = &D_801F0610;
    q = (u8 *)D_80163C74;
    tab = D_801F1C28;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B48C(mat);
    func_8003B51C(mat);
    i = 0;
    c = tab + 0x10;
    a = tab;
    off = 0;
    r = q + 0x10;
    do {
        t = tab + 8;
        func_8003BC0C(a, (u8 *)(off + (s32)t), c, q + 8, q + 0xC, r, D_801EE164, &D_801EE164->flag);
        c += 0x18;
        if (!(D_801EE164->flag & 0x60000)) {
            *(s32 *)q = 0x04000000;
            *(s32 *)(r - 0xC) = 0x20000000;
            func_80046794(D_801517C0 + 0x406C, q);
            r += 0x14;
            q += 0x14;
        }
        a += 0x18;
        i++;
        off += 0x18;
    } while (i < 0x64);
    D_80163C74 = (s32)q;
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x29) {
            p->unk0 = -1;
        }
    }
}

void func_801B5C14(void) {
    MgTask *p;
    u16 t;
    s32 i;
    s32 a;
    s32 x;
    u16 *r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if ((u32)(t - 0x1E) < 0xA) {
            x = (s16)t - 0x1E;
            a = (x << 12) / 10;
            if (t & 1) {
                D_80153D24 = (u16)D_801EDB4C + (a * 0x3E8 >> 12);
            } else {
                D_80153D24 = (u16)D_801EDB4C - (a * 0x3E8 >> 12);
            }
        } else {
            D_80153D24 = D_801EDB4C;
        }
        a = p->unk2;
        if (a < 0x1E) {
            i = 0;
            a = ((a + 1) << 12) / 30;
            a = 0x1000 - a;
            do {
                a = ((s32 (*)(s32))func_80039A74)(a / 4);
                i++;
            } while (i < 2);
            a = 0x1000 - a;
            D_80153BBE = (a << 11 >> 12) + 0x800;
            D_80153BCC = 0x1000 - a;
        }
        x = p->unk2;
        if (x < 0x28) {
            i = 0;
            a = ((x + 1) << 12) / 40;
            a = 0x1000 - a;
            do {
                a = ((s32 (*)(s32))func_80039A74)(a / 4);
                i++;
            } while (i < 2);
            a = 0x1000 - a;
            D_80153D22 = (-(a * 0x5208) >> 12) + 0x4E20;
        } else {
            x -= 0x28;
            if (x >= 5) {
                p->unk0 = -1;
                return;
            }
            r = &D_80153D22;
            *r += 0xC8;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B5E98);

s32 func_801B6AB0(arg0, arg1) {
    MgSVec v;
    s32 z;

    func_800D2980(&D_801B6BEC, 0, 0, 0);
    D_801F0630 = arg0;
    func_800D54EC(arg0, &v);
    if (v.vz < D_80151A4C[arg1].vz) {
        D_801EDB52 = 0x800;
        z = v.vz + 0x1388;
    } else {
        z = v.vz - 0x1388;
    }
    D_801EDB4C = z;
    func_8003C21C(&D_801EDB50, (MgMat *)&D_801EDB30);
    func_801B2AE4();
    func_800BBEAC((M2C_UNK *)func_801B2B80);
    if (func_80042DA8() & 0x100) {
        ((void (*)(s32, s32, s32))func_801B10C0)((s32)&D_801EDBA0, (s32)&D_801EDB30, arg1);
    } else {
        ((void (*)(s32, s32, s32))func_801B10C0)((s32)&D_801EDCC0, (s32)&D_801EDB30, arg1);
    }
    func_800BBEAC((M2C_UNK *)func_801B5E98);
    D_800F8380 |= 8;
}
