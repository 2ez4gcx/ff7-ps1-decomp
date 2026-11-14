#include "common.h"
#include "magic_vahamut2/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B7C4C();
    return &D_801D8EAC;
}

MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EEE00.m[0][0] = D_801EEE00.m[1][1] = D_801EEE00.m[2][2] = scale;
    func_8003B48C(&D_801F1AC0);
    func_8003B51C(&D_801F1AC0);
    func_8003BC6C(v, (MgVec *)D_801EEE00.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EEE00.t, &n);
        D_801EEE00.t[0] += (dist * n.vx) >> 12;
        D_801EEE00.t[1] += (dist * n.vy) >> 12;
        D_801EEE00.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EEE00);
    func_8003B51C(&D_801EEE00);
    return &D_801EEE00;
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B0184);

void func_801B0C44(MgMat *arg0, u16 *arg1) {
    s32 sp10;
    s32 sp14;
    MgHalf *p;
    MgHalf *q;
    MgHalf *r;
    MgWord *w;

    func_80044AC0((s32)D_801EF4AC, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801EF4AC);
    p = (MgHalf *)&D_801EEE50;
    p->v = D_801EEE60.v = arg1[2];
    D_801EEE5A = D_801EEE62 = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)p - 0x10));
    func_8003B64C(&sp10, &sp14);
    func_8003B6BC((s16)arg1[2] / 2, (s16)arg1[3] / 2);
    func_8003B48C(arg0);
    func_8003B51C(arg0);
    w = (MgWord *)&D_801EEE20;
    w->v = D_8016209C;
    D_80163C74 = func_801B0184((s32 *)w, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B6BC(sp10, sp14);
    q = (MgHalf *)&D_801EEE3C;
    q->v = arg1[2];
    D_801EEE3E = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)q - 0xC));
    func_80044978(D_801EF4EC, arg1);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801EF4EC);
    r = (MgHalf *)&D_801EF504;
    r->v = arg1[0];
    D_801EF506 = arg1[1];
    func_800449FC(D_801EF4F8, r);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801EF4F8);
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B0E54);

s32 func_801B16A8(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F1AFE[-v];
    }
    return v;
}

s32 func_801B16E4(s32 t, s32 s) {
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

void func_801B17D4(void) {
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
            D_801EF508.actor = -1;
            D_801EF534.actor = -1;
            D_801EF508.frames = 0;
            D_801EF534.frames = 0;
            p->unk2 = 1;
        }
        while (D_801EF508.frames == 0 || D_801EF534.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801EF560 = &D_801EF508;
                D_801EF564 = &D_801EF534;
            } else {
                D_801EF560 = &D_801EF534;
                D_801EF564 = &D_801EF508;
            }
            D_801EF560->mode = op & 0xFF3F;
            switch (D_801EF560->mode) {
            case 1:
                D_801EF560->pos.vx = *p->script++;
                D_801EF560->pos.vy = *p->script++;
                D_801EF560->pos.vz = *p->script++;
                break;
            case 2:
                D_801EF560->frames = func_801B16A8(&p->script);
                D_801EF560->vel.vx = (*p->script++ - D_801EF560->pos.vx) / D_801EF560->frames;
                D_801EF560->vel.vy = (*p->script++ - D_801EF560->pos.vy) / D_801EF560->frames;
                D_801EF560->vel.vz = (*p->script++ - D_801EF560->pos.vz) / D_801EF560->frames;
                break;
            case 3:
                sv->vx = D_801EF564->pos.vx - D_801EF560->pos.vx;
                sv->vy = D_801EF564->pos.vy - D_801EF560->pos.vy;
                sv->vz = D_801EF564->pos.vz - D_801EF560->pos.vz;
                D_801EF560->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801EF560->unk18 = D_801EF560->pos;
                D_801EF560->frames = func_801B16A8(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801EF560->vel.vx = (sv->vx - D_801EF560->pos.vx) / D_801EF560->frames;
                D_801EF560->vel.vy = (sv->vy - D_801EF560->pos.vy) / D_801EF560->frames;
                D_801EF560->vel.vz = (sv->vz - D_801EF560->pos.vz) / D_801EF560->frames;
                if (D_801EF564->mode == 2) {
                    sv2->vx = D_801EF564->pos.vx + D_801EF564->vel.vx * D_801EF564->frames;
                    sv2->vy = D_801EF564->pos.vy + D_801EF564->vel.vy * D_801EF564->frames;
                    sv2->vz = D_801EF564->pos.vz + D_801EF564->vel.vz * D_801EF564->frames;
                } else {
                    sv2->vx = D_801EF564->pos.vx;
                    sv2->vy = D_801EF564->pos.vy;
                    sv2->vz = D_801EF564->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801EF560->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801EF560->unk4) / D_801EF560->frames;
                break;
            case 4:
                D_801EF560->frames = func_801B16A8(&p->script);
                sv->vx = *p->script++ - D_801EF560->pos.vx;
                sv->vy = *p->script++ - D_801EF560->pos.vy;
                sv->vz = *p->script++ - D_801EF560->pos.vz;
                D_801EF560->unk18.vx = ((sv->vx - D_801EF560->vel.vx * D_801EF560->frames) * 2) / (D_801EF560->frames * D_801EF560->frames);
                D_801EF560->unk18.vy = ((sv->vy - D_801EF560->vel.vy * D_801EF560->frames) * 2) / (D_801EF560->frames * D_801EF560->frames);
                D_801EF560->unk18.vz = ((sv->vz - D_801EF560->vel.vz * D_801EF560->frames) * 2) / (D_801EF560->frames * D_801EF560->frames);
                break;
            case 5:
                D_801EF560->frames = func_801B16A8(&p->script);
                D_801EF560->unk28 = *p->script++;
                D_801EF560->unk4 = 0;
                D_801EF560->unk8 = 0x1000 / D_801EF560->frames;
                D_801EF560->unk18.vx = D_801EF560->pos.vx;
                D_801EF560->unk18.vy = D_801EF560->pos.vy;
                D_801EF560->unk18.vz = D_801EF560->pos.vz;
                D_801EF560->vel.vx = *p->script++ - D_801EF560->pos.vx;
                D_801EF560->vel.vy = *p->script++ - D_801EF560->pos.vy;
                D_801EF560->vel.vz = *p->script++ - D_801EF560->pos.vz;
                break;
            case 6:
                if ((D_801EF560->actor = *p->script++) == 0) {
                    D_801EF560->actor = p->actor;
                }
                D_801EF560->part = *p->script++;
                break;
            case 7:
                D_801EF560->actor = -1;
                break;
            case 0:
            case 9:
                D_801EF560->frames = func_801B16A8(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801EF560 = &D_801EF508;
        D_801EF564 = &D_801EF534;
        for (i = 0; i < 2; i++) {
            switch (D_801EF560->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801EF560->vel.vx += D_801EF560->unk18.vx;
                D_801EF560->vel.vy += D_801EF560->unk18.vy;
                D_801EF560->vel.vz += D_801EF560->unk18.vz;
            case 2:
                D_801EF560->pos.vx += D_801EF560->vel.vx;
                D_801EF560->pos.vy += D_801EF560->vel.vy;
                D_801EF560->pos.vz += D_801EF560->vel.vz;
                break;
            case 3:
                D_801EF560->unk18.vx += D_801EF560->vel.vx;
                D_801EF560->unk18.vy += D_801EF560->vel.vy;
                D_801EF560->unk18.vz += D_801EF560->vel.vz;
                D_801EF560->unk4 += D_801EF560->unk8;
                vec->vx = D_801EF564->pos.vx - D_801EF560->unk18.vx;
                vec->vy = D_801EF564->pos.vy - D_801EF560->unk18.vy;
                vec->vz = D_801EF564->pos.vz - D_801EF560->unk18.vz;
                func_8003A078(vec, sv);
                D_801EF560->pos.vx = D_801EF564->pos.vx - ((sv->vx * D_801EF560->unk4) >> 12);
                D_801EF560->pos.vy = D_801EF564->pos.vy - ((sv->vy * D_801EF560->unk4) >> 12);
                D_801EF560->pos.vz = D_801EF564->pos.vz - ((sv->vz * D_801EF560->unk4) >> 12);
                break;
            case 5:
                D_801EF560->unk4 += D_801EF560->unk8;
                k = func_801B16E4(D_801EF560->unk4, D_801EF560->unk28);
                D_801EF560->pos.vx = D_801EF560->unk18.vx + ((D_801EF560->vel.vx * k) >> 12);
                D_801EF560->pos.vy = D_801EF560->unk18.vy + ((D_801EF560->vel.vy * k) >> 12);
                D_801EF560->pos.vz = D_801EF560->unk18.vz + ((D_801EF560->vel.vz * k) >> 12);
                break;
            }
            cam = D_801EF560;
            D_801EF560 = &D_801EF534;
            D_801EF564 = &D_801EF508;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801EF508.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801EF508.actor == -1) {
                func_8003BC6C(&D_801EF508.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801EF508.pos, vec);
                if (D_801EF508.part != -1) {
                    func_800D3994(D_801EF508.actor, D_801EF508.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801EF508.actor].vx;
                    sv->vy = D_80151A4C[D_801EF508.actor].vy;
                    sv->vz = D_80151A4C[D_801EF508.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801EF534.mode != 9) {
            if (D_801EF534.actor == -1) {
                func_8003BC6C(&D_801EF534.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801EF534.pos, vec);
                if (D_801EF534.part != -1) {
                    func_800D3994(D_801EF534.actor, D_801EF534.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801EF534.actor].vx;
                    sv->vy = D_80151A4C[D_801EF534.actor].vy;
                    sv->vz = D_80151A4C[D_801EF534.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801EF508.mode != 9) {
            D_80158D00 = D_801EF508.pos;
        }
        if (D_801EF534.mode != 9) {
            D_801031E8 = D_801EF534.pos;
        }
    }
}

void func_801B2808(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B17D4)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B286C(void) {
    MgTask *p;
    s32 t;
    s32 d;
    s32 v;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        d = p->unk6;
        if (t < d) {
            d = (t << 12) / d;
            v = (p->unk4 * d) >> 12;
        } else {
            t -= d;
            if (t < p->unk8) {
                v = p->unk4;
            } else {
                t -= p->unk8;
                d = p->unkA;
                if (t >= d) {
                    p->unk0 = -1;
                    D_800FA668[0] = 0;
                    return;
                }
                d = (t << 12) / d;
                v = (p->unk4 * (0x1000 - d)) >> 12;
            }
        }
        D_800FA668[0] = (p->unk2 & 1) ? v : -v;
        p->unk2++;
    }
}

void func_801B29A8(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B286C)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

void func_801B2A1C(void) {
    MgMat m;

    D_801EF144 = D_801EEDD8;
    D_801EF134 = D_801EEDD8;
    if (D_801EEDD2 != 0) {
        D_801EF150 = D_801EEDF4;
    } else {
        D_801EF150 = -D_801EEDF4;
    }
    func_8003A63C(&D_801EF114, &D_801EF134, &m);
    func_801B0C44(&m, &D_801EF154);
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B2AAC);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B2E54);

void func_801B3028(void) {
    MgTask *p;
    s32 t;
    s32 u;
    s32 w;
    s32 *q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x1D1) {
        if (t < 0x2D) {
            u = (t << 12) / 45;
            D_801EF16A = D_800F5B74 + (-D_800F5B74 * u >> 12);
            if (D_80062D98 == 0) {
                q = &D_801EF188;
                *q -= 0x6F;
            }
        } else {
            t -= 0x2D;
            if (t < 0x64) {
                if (t == 0) {
                    D_801EF188 = 0;
                    D_801EF16A = 0;
                }
                if (D_80062D98 == 0) {
                    q = &D_801EF188;
                    *q -= 0xC8;
                }
            } else {
                t -= 0x64;
                if (t < 0x140) {
                    if (t == 0) {
                        D_801EF188 = 0;
                    }
                    if (t >= 0x113) {
                        q = &D_801EF184;
                        *q = t & 1 ? 0x1E : -0x1E;
                    }
                }
            }
        }
        func_8003A63C(&D_801F1AC0, &D_801EF170, &D_801EF190->m);
        func_8003B48C(&D_801EF190->m);
        func_8003B51C(&D_801EF190->m);
        func_8003B69C(D_800F5B70, D_800F5B71, D_800F5B72);
        D_80163C74 = func_800D29D4(D_801EF160, D_801517C0 + 0x70, 0xC, D_80163C74);
    } else {
        t -= 0x1D1;
        if (t < 0x4B) {
            if (t == 0) {
                func_801B2AAC();
            }
            if (t < 0x1E) {
                D_801EF190->rot.vy = 0;
                u = (t << 12) / 30;
                D_801EF190->rot.vx = -(u << 6) >> 12;
                D_801EF190->rot.vz = (u32)u >> 5;
                func_8003C21C(D_801EF190, &D_801EF190->m);
                D_801EF190->m.t[0] = t & 1 ? 0x32 : -0x32;
                w = t * 0x1E;
                D_801EF190->m.t[2] = w;
                D_801EF190->m.t[1] = w;
                func_8003A63C(&D_801F1AC0, &D_801EF190->m, &D_801EF190->m);
            } else {
                if (t == 0x1E) {
                    D_801EF180 = 0x100;
                    D_801EF178 = 0x100;
                    D_801EF170.m[0][0] = 0x100;
                    D_801EF184 = -0x1388;
                    D_801EF188 = -0x4E20;
                    D_801EF18C = 0;
                }
                func_8003A63C(&D_801F1AC0, &D_801EF170, &D_801EF190->m);
            }
            func_801B2E54(&D_801EF190->m);
            D_80163C74 = func_801B0E54(D_801EF160, D_801517C0 + 0x70, 0xC, D_80163C74, D_801F4A8C);
        } else {
            p->unk0 = -1;
            return;
        }
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B33C0(void) {
    MgTask *p;
    s32 z;
    u16 *frame;
    s16 t;

    p = &D_80162978[D_8015169C];
    z = func_801B0068((MgSVec *)&p->unk4, p->unk18, -0x3E8)->t[2];
    if (z > 0) {
        func_800D4484(*(s32 *)(((z >> 4) * 4) + D_801517C0 + 0x70), 0x20);
        frame = &D_801EF19C;
        *frame = p->unk2;
        D_80163C74 = func_800D4D90((s16 *)((u8 *)frame - 8), D_801517C0 + 0x70, 0xC, D_80163C74);
    }
    if (D_80062D98 == 0) {
        t = (u16)p->unk2 + 1;
        p->unk2 = t;
        if (t >= D_801D8C2C[0] || t + p->unk0 >= 0x2D) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B34C8);

void func_801B3600(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 n;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x14) {
            n = (((t << 12) / 20 << 7) >> 12) + 0x80;
        } else {
            t -= 0x14;
            if (t < 0x19) {
                n = 0x100;
            } else {
                p->unk0 = -1;
                return;
            }
        }
        n += (n * p->unk2) & 0xFF;
        while (n >= 0x100) {
            q = &D_80162978[func_800BBEAC(&func_801B33C0)];
            q->unk0 = p->unk2;
            func_801B34C8(&q->unk4);
            q->unk18 = func_80042DA8() % 0x1000 + 0x3000;
            n -= 0x100;
        }
        p->unk2++;
    }
}

void func_801B3754(void) {
    MgTask *p;
    s16 *frame;
    s16 t;

    p = &D_80162978[D_8015169C];
    func_801B0068((MgSVec *)&p->unk4, p->unk18, 0);
    frame = &D_801EF1A8;
    *frame = (u16)p->unk2 | 0x8000;
    D_80163C74 = func_800D4D90((s16 *)((u8 *)frame - 8), D_801517C0 + 0x70, 0xC, D_80163C74);
    t = (u16)p->unk2 + 1;
    p->unk2 = t;
    if (t >= D_801D8DDC[0]) {
        p->unk0 = -1;
    }
}

void func_801B3804(void) {
    MgTask *p;
    MgTask *q;
    s32 n;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = (p->unk2 * 0x400 & 0xFF) + 0x400;
        while (n >= 0x100) {
            n -= 0x100;
            q = &D_80162978[func_800BBEAC((s32 *)func_801B3754)];
            func_801B34C8(&q->unk4);
            q->unk18 = func_80042DA8() % 0x3000 + 0x5000;
        }
        p->unk2++;
        if (p->unk2 >= 4) {
            p->unk0 = -1;
        }
    }
}

void func_801B3904(void) {
    Vh2Task *p;
    Vh2Fx *s;
    MgMat *m;
    s32 *frame;
    s32 t;
    s32 u;
    s32 k;
    s16 *g;
    s32 n;

    p = (Vh2Task *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x14) {
        D_801EF1B0 = 0x80;
        D_801EF1B6 = 0;
    } else {
        t -= 0x14;
        if (t < 5) {
            D_801EF1B0 = 0x88;
            k = (t << 12) / 5;
            D_801EF1B6 = k;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    u = p->unk1A;
    if (u != 0) {
        g = &D_801EF1B6;
        k = 0x1000 - *g;
        *g = 0x1000 - (k * (0x1000 - u) >> 12);
    }
    D_801EF1BC->rot.vx = p->rx;
    D_801EF1BC->rot.vy = p->ry;
    D_801EF1BC->rot.vz = p->rz;
    func_8003C21C((s16 *)D_801EF1BC, (u16 *)&D_801EF1BC->m);
    s = D_801EF1BC;
    s->m.t[0] = p->unk4;
    s->m.t[1] = p->unk6;
    s->m.t[2] = p->unk8;
    s->v8 = s->vC = s->v10 = p->unk18;
    ((void (*)(MgMat *, s32 *))func_8003B35C)(&s->m, &s->v8);
    m = &D_801EF1BC->m;
    func_8003A63C(&D_801F1AC0, m, m);
    func_8003B48C(&D_801EF1BC->m);
    func_8003B51C(&D_801EF1BC->m);
    func_8003B69C(0, 0, 0);
    frame = &D_801EF1AC;
    *frame = D_801D8EA0[p->unk0];
    D_80163C74 = func_800D29D4(frame, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk4 += p->unkC;
        n = (u16)p->unk6 + (u16)p->unkE;
        p->unk6 = n;
        if ((s16)n > 0) {
            p->unk0 = -1;
        } else {
            p->unk8 += p->unk10;
            p->unkE += 0x32;
            *((u8 *)p + 0x14) += 8;
            *((u8 *)p + 0x15) += 0x20;
            *((u8 *)p + 0x16) += 0x30;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3B84);

void func_801B3E50(void) {
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xF) {
        D_801EF1CE = 0;
    } else {
        t -= 0xF;
        if (t < 0x1E) {
            D_801EF1CE = (t << 12) / 30;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003A63C(&D_801F1AC0, &D_801EF1D4, (MgMat *)(D_801EF1F4 + 0x10));
    func_8003B48C((MgMat *)(D_801EF1F4 + 0x10));
    func_8003B51C((MgMat *)(D_801EF1F4 + 0x10));
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EF1C4, D_801517C0 + 0x4064, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3F90(void) {
    MgTask *p;
    s16 t;
    s32 q;
    s32 u;

    p = &D_80162978[D_8015169C];
    u = p->unk2;
    if (u < 0) {
        D_801EF202 = 0x1000;
    } else if (u < 0x1E) {
        q = (u << 12) / 30;
        D_801EF202 = 0x1000 - q;
    } else if ((u -= 0x1E) < 0x37) {
        D_801EF202 = 0;
    } else {
        p->unk0 = -1;
        return;
    }
    if (p->unk2 < 0) {
        D_801EF212 = 0x1000;
    } else if (p->unk2 < 0x1E) {
        q = (p->unk2 << 12) / 30;
        D_801EF212 = 0x1000 - q;
    } else {
        D_801EF212 = 0;
    }
    if (p->unk2 == 0xF) {
        D_801EF234 = 0;
        D_801EF224 = 0;
        D_801EF238 = 0x140;
        D_801EF228 = 0x140;
    }
    p->unk4 = (func_801B16E4((p->unk2 << 12) / 85, 0x1C0) * 0x4FB0 >> 12) + 0x2580;
    func_80044244(D_801EF218 * 0x1100 + D_801EF568, 0x440);
    func_8003B69C(0, 0, 0);
    D_801EF23C->rot.vy = 0;
    D_801EF23C->rot.vx = 0;
    D_801EF23C->rot.vz = p->unk2 * 0x18;
    func_8003C21C(D_801EF23C, &D_801EF23C->m);
    D_801EF23C->m.t[0] = p->unk4;
    D_801EF23C->m.t[1] = p->unk6;
    D_801EF23C->m.t[2] = p->unk8;
    t = p->unk18;
    D_801EF23C->v10 = t;
    D_801EF23C->vC = t;
    D_801EF23C->v8 = t;
    ((void (*)(MgMat *, void *))func_8003B35C)(&D_801EF23C->m, &D_801EF23C->v8);
    func_8003A63C(&D_801F1AC0, &D_801EF23C->m, &D_801EF23C->m);
    func_8003B48C(&D_801EF23C->m);
    func_8003B51C(&D_801EF23C->m);
    D_80163C74 = func_800D29D4(&D_801EF1F8, D_801EF218 * 0x1100 + (s32)(D_801EF568 + 0x100), 0xA, D_80163C74);
    D_801EF23C->rot.vz = -D_801EF23C->rot.vz;
    func_8003C21C(D_801EF23C, &D_801EF23C->m);
    D_801EF23C->m.t[0] = -p->unk4;
    D_801EF23C->m.t[1] = p->unk6;
    D_801EF23C->m.t[2] = p->unk8;
    t = p->unk18;
    D_801EF23C->v10 = t;
    D_801EF23C->vC = t;
    D_801EF23C->v8 = t;
    ((void (*)(MgMat *, void *))func_8003B35C)(&D_801EF23C->m, &D_801EF23C->v8);
    func_8003A63C(&D_801F1AC0, &D_801EF23C->m, &D_801EF23C->m);
    func_8003B48C(&D_801EF23C->m);
    func_8003B51C(&D_801EF23C->m);
    D_80163C74 = func_800D29D4(&D_801EF1F8, D_801EF218 * 0x1100 + (s32)(D_801EF568 + 0x100), 0xA, D_80163C74);
    D_801EF23C->rot.vz = p->unk2 * 0x40;
    func_8003C21C(D_801EF23C, &D_801EF23C->m);
    D_801EF23C->m.t[0] = p->unk4;
    D_801EF23C->m.t[1] = p->unk6;
    D_801EF23C->m.t[2] = p->unk8;
    D_801EF23C->v10 = 0x2000;
    D_801EF23C->vC = 0x2000;
    D_801EF23C->v8 = 0x2000;
    ((void (*)(MgMat *, void *))func_8003B35C)(&D_801EF23C->m, &D_801EF23C->v8);
    func_8003A63C(&D_801F1AC0, &D_801EF23C->m, &D_801EF23C->m);
    func_8003B48C(&D_801EF23C->m);
    func_8003B51C(&D_801EF23C->m);
    D_80163C74 = func_800D29D4(&D_801EF208, D_801EF218 * 0x1100 + (s32)D_801EF568, 0xA, D_80163C74);
    D_801EF23C->rot.vz = -D_801EF23C->rot.vz;
    func_8003C21C(D_801EF23C, &D_801EF23C->m);
    D_801EF23C->m.t[0] = -p->unk4;
    D_801EF23C->m.t[1] = p->unk6;
    D_801EF23C->m.t[2] = p->unk8;
    D_801EF23C->v10 = 0x2000;
    D_801EF23C->vC = 0x2000;
    D_801EF23C->v8 = 0x2000;
    ((void (*)(MgMat *, void *))func_8003B35C)(&D_801EF23C->m, &D_801EF23C->v8);
    func_8003A63C(&D_801F1AC0, &D_801EF23C->m, &D_801EF23C->m);
    func_8003B48C(&D_801EF23C->m);
    func_8003B51C(&D_801EF23C->m);
    D_80163C74 = func_800D29D4(&D_801EF208, D_801EF218 * 0x1100 + (s32)D_801EF568, 0xA, D_80163C74);
    func_800467D0((MainTag *)(D_801517C0 + 0x4068), D_801EF218 * 0x1100 + (s32)(D_801EF568 + 0x10FC), (MainTag *)(D_801EF218 * 0x1100 + (s32)D_801EF568));
    func_80046794(D_801517C0 + 0x406C, D_801EF218 * 0x10 + (s32)D_801EF21C);
    D_801EF218 ^= 1;
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B4570(void) {
    MgTask *p;
    s32 t;
    s32 c;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xA) {
        D_801EF25E = 0xF00;
        D_801EF250.m[0][0] = 0xF00;
        D_801EF25A = -0x7D0;
    } else {
        t -= 0xA;
        if (t < 0x5A) {
            k = (t << 12) / 90;
            c = ((k * 0x780) >> 12) + 0xF00;
            D_801EF25E = c;
            D_801EF250.m[0][0] = c;
            D_801EF25A = -(((k * 0x3E8) >> 12) + 0x7D0);
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003B48C(&D_801EF250);
    func_8003B51C(&D_801EF250);
    func_800D4484(D_801517C0 + 0x4084, 0x20);
    D_80163C74 = func_800D29D4(&D_801EF240, D_801517C0 + 0x4084, 0, D_80163C74);
    func_800D4484(D_801517C0 + 0x4084, 0x40);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B4708(void) {
    MgTask *p;
    Vh2Eff *s;
    s32 t;
    s32 k;
    s16 n;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xA) {
        k = (t << 12) / 10;
        D_801EF27A = 0x1000 - k;
    } else {
        t -= 0xA;
        if (t < 5) {
            D_801EF27A = 0;
        } else {
            t -= 5;
            if (t < 0xA) {
                k = (t << 12) / 10;
                D_801EF27A = k;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    s = D_801EF280;
    func_8003C21C(&p->unkC, (u16 *)&s->m);
    s = D_801EF280;
    s->m.t[0] = p->unk4;
    s->m.t[1] = p->unk6;
    s->m.t[2] = p->unk8;
    s->v0 = p->unk18;
    s->v4 = s->v8 = 0x2000;
    func_8003B35C(&s->m);
    s = D_801EF280;
    func_8003A63C(&D_801F1AC0, &s->m, &s->m);
    func_8003B48C(&D_801EF280->m);
    func_8003B51C(&D_801EF280->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EF270, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n + p->unk0 >= 0x46) {
            p->unk0 = -1;
        }
    }
}

void func_801B48E8(void) {
    MgTask *p;
    MgTask *q;
    s32 n;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = ((p->unk2 * 0x60) & 0xFF) + 0x60;
        while (n >= 0x100) {
            q = &D_80162978[func_800BBEAC(&func_801B4708)];
            q->unk0 = p->unk2;
            q->unk4 = func_80042DA8() % 1000 + 0x1388;
            q->unk6 = -0x4E20;
            q->unk8 = func_80042DA8() % 20000 - 0x2710;
            q->unkC = func_80042DA8() % 64 + 0x40;
            if (func_80042DA8() & 0x1000) {
                q->unk4 = -(u16)q->unk4;
                q->unkC = -(u16)q->unkC;
            }
            q->unkE = 0x400;
            q->unk10 = 0;
            n -= 0x100;
            q->unk18 = func_80042DA8() % 0x3000 + 0x5000;
        }
        p->unk2++;
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B4AE4(void) {
    MgTask *p;
    s32 t;
    s16 n;
    s32 u;

    p = &D_80162978[D_8015169C];
    if (p->unk2 == 0) {
        D_801EF2C4->rot.vx = 0;
        D_801EF2C4->rot.vy = 0x400;
        D_801EF2C4->rot.vz = 0;
        func_8003C21C((s16 *)D_801EF2C4, &D_801F1768);
        D_801F177C = 0x3E8;
        D_801F1780 = 0x1388;
        D_801F1784 = 0;
        D_801EF2C4->v8 = (D_801EF2C4->vC = (D_801EF2C4->v10 = 0x3800));
        ((void (*)(MgMat *, s32 *))func_8003B35C)((MgMat *)(&D_801F1768), &D_801EF2C4->v8);
    }
    t = p->unk2;
    if (t < 0xDA) {
        D_801EF28E = 0;
        goto done;
    }
    t -= 0xDA;
    if (t < 0x2A) {
        t = (t << 12) / 42;
        goto set;
    }
    t -= 0x2A;
    if (t >= 0) {
        goto kill;
    }
    u = (t << 12) / 42;
    t = 0x1000 - u;
set:
    D_801EF28E = ((u32)(t * 3)) >> 2;
    goto done;
kill:
    p->unk0 = -1;
    return;
done:
    func_8003A63C(&D_801F1AC0, &D_801F1768, &D_801EF2C4->m);
    func_8003B48C(&D_801EF2C4->m);
    func_8003B51C(&D_801EF2C4->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EF284, D_801517C0 + 0x4068, 0, D_80163C74);
    func_8003A63C(&D_801F1AC0, &D_801EF2A4, &D_801EF2C4->m);
    func_8003B48C(&D_801EF2C4->m);
    func_8003B51C(&D_801EF2C4->m);
    func_800D4484(D_801517C0 + 0x4064, 0x20);
    D_80163C74 = func_800D29D4(&D_801EF294, D_801517C0 + 0x4064, 0, D_80163C74);
    func_800D4484(D_801517C0 + 0x4064, 0x40);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        *(u16 *)&p->unk2 = n;
        D_801F1780 = 0x1388;
        D_801F1784 = 0;
        t = (n << 12) / 260;
        D_801F177C = ((-(t * 2000)) >> 12) + 0x3E8;
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B4DD4);

void func_801B5238(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xA) {
        k = (t << 12) / 10;
        func_8003B69C(0, 0, 0);
        func_8003B710(&D_801EF3CC, 0x1000 - k, &D_801EF3C4);
    } else {
        t -= 0xA;
        if (t < 0xA) {
            D_801EF3C4 = 0x2E808080;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_801B0068((MgSVec *)&p->unk4, p->unk18, 0);
    D_80163C74 = func_800D4D90(&D_801EF3C0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
    }
}

void func_801B5390(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 r;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            i++;
            q = &D_80162978[func_800BBEAC(&func_801B5238)];
            D_801EF3D0->v.vx = func_80042DA8() & 0xFFF;
            D_801EF3D0->v.vy = -0x400;
            D_801EF3D0->v.vz = func_80042DA8() % 768;
            func_8003C21C(&D_801EF3D0->v.vx, (u16 *)&D_801EF3D0->m);
            r = func_80042DA8();
            D_801EF3D0->v.vy = 0;
            D_801EF3D0->v.vz = 0;
            D_801EF3D0->v.vx = r % 2000 + 0xBB8;
            func_8003B2CC(&D_801EF3D0->m, &D_801EF3D0->v, &D_801EF3D0->v);
            q->unk4 = (u16)D_801EEDF8.vx + (u16)D_801EF3D0->v.vx;
            q->unk6 = (u16)D_801EEDF8.vy + (u16)D_801EF3D0->v.vy;
            q->unk8 = (u16)D_801EEDF8.vz + (u16)D_801EF3D0->v.vz;
            q->unkC = -D_801EF3D0->v.vx / 20;
            q->unkE = -D_801EF3D0->v.vy / 20;
            q->unk10 = -D_801EF3D0->v.vz / 20;
            q->unk18 = func_80042DA8() % 768 + 0x300;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 0x16) {
            p->unk0 = -1;
        }
    }
}

void func_801B5604(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x25) {
        t = (t << 12) / 37;
        k = (t << 11) >> 12;
    } else {
        t -= 0x25;
        if (t < 0xA) {
            t = (t << 12) / 10;
            k = ((t * 0x1800) >> 12) + 0x800;
        } else {
            t -= 0xA;
            if (t < 0xF) {
                t = (t << 12) / 15;
                k = (-(t * 0x1800) >> 12) + 0x2000;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    func_801B0068(&D_801EEDF8, k, 0);
    D_80163C74 = func_800D29D4(&D_801EF3D4, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

MgPolyT *func_801B577C(void) {
    s32 p;
    s32 flag;
    MgPolyT *prim;

    prim = D_80163C74;
    func_8003BC0C(&D_801EF3E4[0], &D_801EF3E4[1], &D_801EF3E4[2], &prim->xy0, &prim->xy1, &prim->xy2, &p, &flag);
    prim->tag = 0x06000000;
    D_80163C74 = prim + 1;
    return prim;
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B57F4);

void func_801B5A48(void) {
    MgTask *p;
    MgTask *q;
    s32 n;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = ((p->unk2 << 7) & 0xFF) + 0x80;
        while (n >= 0x100) {
            q = &D_80162978[func_800BBEAC(&func_801B57F4)];
            q->unk0 = p->unk2;
            *(MgB8 *)&q->unk4 = *(MgB8 *)&D_801EEDF8;
            q->unkE = 0;
            q->unkC = 0;
            t = (func_80042DA8() & 0x7FF) + 0x400;
            t += D_801F1788;
            D_801F1788 = t;
            q->unk10 = t;
            q->unk1A = func_80042DA8() % 32 + 0x20;
            if (func_80042DA8() & 0x800) {
                q->unk1A = -q->unk1A;
            }
            q->unk18 = func_80042DA8() % 0x1000 + 0x800;
            n -= 0x100;
        }
        p->unk2++;
        if (p->unk2 >= 0x1B) {
            p->unk0 = -1;
        }
    }
}

void func_801B5BD8(void) {
    MgTask *p;
    Vh2Eff *s;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xA) {
        k = func_801B16E4((t << 12) / 10, 0x1FF);
        D_801EF410->v0 = D_801EF410->v4 = D_801EF410->v8 = (k << 10 >> 12) + 0x400;
        D_801EF40A.v = k;
    } else {
        p->unk0 = -1;
        return;
    }
    s = D_801EF410;
    func_8003C21C(&p->unkC, (u16 *)&s->m);
    s = D_801EF410;
    s->m.t[0] = p->unk4;
    s->m.t[1] = p->unk6;
    s->m.t[2] = p->unk8;
    func_8003B35C(&s->m);
    s = D_801EF410;
    func_8003A63C(&D_801F1AE0, &s->m, &s->m);
    s = D_801EF410;
    func_8003A63C(&D_801F1AC0, &s->m, &s->m);
    func_8003B48C(&D_801EF410->m);
    func_8003B51C(&D_801EF410->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EF400, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk10 += 0x80;
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B5D80);

void func_801B606C(void) {
    Vh2Task2 *p;
    Vh2Fx *s;
    MgMat *m;
    s32 *frame;
    s32 t;
    s32 k;

    p = (Vh2Task2 *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x14) {
        D_801EF452 = 0;
    } else {
        t -= 0x14;
        if (t < 0xA) {
            k = (t << 12) / 10;
            D_801EF452 = k;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003C21C(p->rot, (u16 *)&D_801EF458->m);
    s = D_801EF458;
    s->m.t[0] = p->unk4;
    s->m.t[1] = p->unk6;
    s->m.t[2] = p->unk8;
    s->v8 = s->vC = s->v10 = p->rot[8];
    ((void (*)(MgMat *, s32 *))func_8003B35C)(&s->m, &s->v8);
    m = &D_801EF458->m;
    func_8003A63C(&D_801F1AC0, m, m);
    func_8003B48C(&D_801EF458->m);
    func_8003B51C(&D_801EF458->m);
    func_8003B69C(0, 0, 0);
    frame = &D_801EF448;
    *frame = D_801D8EA0[p->unk0];
    D_80163C74 = func_800D29D4(frame, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC = (p->unkC * 0x1F >> 5) + (u16)p->unk14;
        p->unkE = p->unkE * 0x1F >> 5;
        p->unk10 = (p->unk10 * 0x1F >> 5) + (u16)p->unk18;
        k = func_801B16E4((p->unk2 << 12) / 30, -0x2E0);
        p->rot[0] += k * 0x312 >> 12;
        p->rot[1] = p->rot[1];
        p->rot[2] += k * 0x25 >> 12;
        p->unk2++;
    }
}

void func_801B6334(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 r;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = &D_80162978[func_800BBEAC(func_801B606C)];
            q->unk0 = func_80042DA8() % 3;
            r = func_80042DA8();
            q->unk6 = 0;
            q->unk4 = r % 6000 - 0xBB8;
            q->unk8 = func_80042DA8() % 6000 - 0xBB8;
            D_801EF460->vx = D_801EEDF8.vx - q->unk4;
            D_801EF460->vy = D_801EEDF8.vy - q->unk6;
            D_801EF460->vz = D_801EEDF8.vz - q->unk8;
            while ((u32)(D_801EF460->vx + 0x4000) > 0x8000U || (u32)(D_801EF460->vy + 0x4000) > 0x8000U || (u32)(D_801EF460->vz + 0x4000) > 0x8000U) {
                D_801EF460->vx >>= 1;
                D_801EF460->vy >>= 1;
                D_801EF460->vz >>= 1;
            }
            func_8003A08C(D_801EF460, D_801EF460);
            k = func_80042DA8() % 200 + 0x12C;
            q->unkC = k * D_801EF460->vx >> 12;
            q->unkE = k * D_801EF460->vy >> 12;
            q->unk10 = k * D_801EF460->vz >> 12;
            k = func_80042DA8() % 30 + 0x46;
            q->unk14 = -D_801EF460->vx * k >> 12;
            q->unk16 = 0;
            q->unk18 = -D_801EF460->vz * k >> 12;
            ((s16 *)D_801EF45C)[8] = func_80042DA8() % 256 + 0x20;
            *(void **)&q->unk1C = D_801EF45C;
            i++;
        } while (i <= 0);
        p->unk2++;
        if (p->unk2 >= 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B66C8(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xF) {
        D_801EF46E = 0;
    } else {
        t -= 0xF;
        if (t < 0xF) {
            D_801EF46E = (t << 12) / 15;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    k = func_801B16E4((p->unk2 << 12) / 30, -0x210);
    func_801B0068(&D_801EF474, (k * 0x4B00 >> 12) + 0x500, 0);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EF464, D_801517C0 + 0x4060, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

s32 func_801B6828(s32 arg0) {
    return -(arg0 * 0x1388) / -20000;
}

void func_801B6868(void) {
    Vh2Task *p;
    Vh2Fx *s;
    MgMat *m;
    s32 t;
    s32 *frame;
    s32 k;

    p = (Vh2Task *)&D_80162978[D_8015169C];
    D_801EF48C->rot.vx = p->rx * 0x10;
    D_801EF48C->rot.vy = p->ry * 0x10;
    D_801EF48C->rot.vz = p->rz * 0x10;
    func_8003C21C((s16 *)D_801EF48C, (u16 *)&D_801EF48C->m);
    k = p->unk4 + func_801B6828(p->unk6);
    s = D_801EF48C;
    s->m.t[0] = k;
    s->m.t[1] = p->unk6;
    s->m.t[2] = p->unk8;
    s->v8 = s->vC = s->v10 = p->unk18;
    ((void (*)(MgMat *, s32 *))func_8003B35C)(&s->m, &s->v8);
    m = &D_801EF48C->m;
    func_8003A63C(&D_801F1AC0, m, m);
    func_8003B48C(&D_801EF48C->m);
    func_8003B51C(&D_801EF48C->m);
    frame = &D_801EF47C;
    *frame = D_801D8EA0[p->unk0];
    D_80163C74 = func_800D29D4(frame, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        t = (u16)p->unk6 + (u16)p->unkE;
        p->unk6 = t;
        if ((s16)t >= 0) {
            p->unk0 = -1;
            return;
        }
        p->unkE = (p->unkE * 0x3F >> 6) + 0x3C;
        p->unk2++;
        *((u8 *)p + 0x14) += 1;
        *((u8 *)p + 0x15) += 8;
        *((u8 *)p + 0x16) += 0x10;
    }
}

void func_801B6A2C(void) {
    MgTask *p;
    MgTask *q;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            i++;
            q = &D_80162978[func_800BBEAC(&func_801B6868)];
            q->unk0 = func_80042DA8() % 3;
            q->unk4 = func_80042DA8() % 4000 - 0x7D0;
            q->unk6 = -0x4E20;
            q->unk8 = func_80042DA8() % 4000 - 0x7D0;
            q->unkE = func_80042DA8() % 100;
            q->unk18 = func_80042DA8() % 0x1F0 + 0x50;
            *(s32 *)&q->unk14 = func_80042DA8() & 0xFFFFFF;
        } while (i < 6);
        p->unk2++;
        if (p->unk2 >= 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B6C18(void) {
    MgTask *p;
    Vh2Act2 *a;
    MgSVec *s;
    s32 t;
    s32 u;
    s32 v;

    p = &D_80162978[D_8015169C];
    a = (Vh2Act2 *)(D_801518E4 + p->unk0 * 0xB9C);
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            p->unk4 = a->x;
            p->unk6 = a->y;
            p->unk8 = a->z;
        }
        t = p->unk2;
        if (t < 0x2D) {
            u = (t << 12) / 45;
            v = u * 5000;
            goto sety;
        }
        t -= 0x2D;
        if (t < 0x64) {
            u = (t << 12) / 100;
            v = u * 20000;
sety:
            a->y = -v >> 12;
            goto next;
        }
        t -= 0x64;
        if (t < 0x140) {
            if (t != 0) {
                goto next;
            }
zero:
            a->y = 0;
            goto next;
        }
        do {
            t -= 0x140;
            if (t < 0x1E) {
                goto next;
            }
            t -= 0x1E;
            if (t < 0x28) {
                if (t == 0) {
                    p->unkE = 0;
                    a->y += -0x4E20;
                }
                if ((s16)a->y >= 0) {
                    goto zero;
                }
                a->y = (s16)a->y + (u16)p->unkE;
                p->unkE = (p->unkE * 0x3F >> 6) + 0x3C;
                u = func_801B6828((s16)a->y);
                s = D_801EF490;
                s->vx = u;
                s->vy = 0;
                s->vz = 0;
                func_8003B2CC((MgMat *)&D_801EEDD8, s, s);
                a->x = (u16)p->unk4 + (u16)D_801EF490->vx;
                a->z = (u16)p->unk8 + (u16)D_801EF490->vz;
                goto next;
            }
        } while (0);
        *(MgB8 *)&a->x = *(MgB8 *)&p->unk4;
        p->unk0 = -1;
        return;
next:
        p->unk2++;
    }
}

void func_801B6EAC(s16 arg0) {
    D_80162978[func_800BBEAC(&func_801B6C18)].unk0 = arg0;
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B6EF4);

void func_801B712C(void) {
    MgTask *p;
    MgTask *q;
    s32 n;
    u16 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = (p->unk2 * 0x100 & 0xFF) + 0x100;
        while (n >= 0x100) {
            q = &D_80162978[func_800BBEAC(&func_801B6EF4)];
            t = p->unk2;
            q->unk4 = -0x1388;
            q->unk6 = -0x4E20;
            q->unk8 = 0;
            q->unkE = 0;
            q->unkC = 0;
            q->unk0 = t;
            q->unk10 = func_80042DA8() % 0x800 - 0x200;
            q->unk18 = func_80042DA8() % 0x1000 + 0x800;
            n -= 0x100;
        }
        p->unk2++;
        if (p->unk2 >= 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B7254(void) {
    s32 i;

    if (D_801EF498 == 0) {
        for (i = 0; i < 10; i++) {
            if ((D_801F1ABC >> i) & 1) {
                D_801F1AB0[i] = D_80151909[i][0];
                D_80151909[i][0] |= 0x10;
            }
        }
    } else {
        for (i = 0; i < 10; i++) {
            if ((D_801F1ABC >> i) & 1) {
                D_80151909[i][0] = D_801F1AB0[i];
            }
        }
    }
    D_801EF498 ^= 1;
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B7340);

void func_801B7610(void) {
    MgTask *p;
    MgTask *q;
    MgTask *e;
    s32 t;
    s32 i;

    p = &D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801EEDD8, &D_801F1AC0);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 5) {
            if (t == 0) {
                D_800F5B74 = 0;
            }
            if (t == 4) {
                func_801B2A1C();
            }
        } else {
            t -= 5;
            if (t < 0xA) {
                if (t == 0) {
                    func_800BBEAC((M2C_UNK *)func_801B3600);
                    e = func_800D4FA8(7);
                    e->unk10 = 5;
                    *(u32 *)&e->unkC = (u32)D_801B7DD4;
                    func_801B29A8(0x32, 0, 0x14, 0);
                }
                if (t == 5) {
                    D_800F5B70 = 0;
                    D_800F5B71 = 0;
                    D_800F5B72 = 0;
                    func_800D52A0(0x800, 0x19);
                }
                if (t == 0) {
                    func_800D55F4(0x22, 0x40, 0x288, 0x289, 0x28A);
                }
            } else {
                t -= 0xA;
                if (t < 0xA) {
                    if (t == 9) {
                        func_800D5444(0x3F0, 0, 0, func_801B6EAC);
                        func_801B7254();
                    }
                } else {
                    t -= 0xA;
                    if (t < 0x19) {
                        if (t == 0) {
                            func_800BBEAC((M2C_UNK *)func_801B3028);
                            func_800BBEAC((M2C_UNK *)func_801B3804);
                            func_800BBEAC((M2C_UNK *)func_801B3B84);
                            func_801B29A8(0x64, 0, 0x2D, 0);
                        }
                    } else {
                        t -= 0x19;
                        if (t < 0x14) {
                            if (t == 0x12) {
                                func_800C610C();
                                func_800D2980((M2C_UNK *)D_801B7DD4, 0, 0, 0);
                                D_800F8380 |= 7;
                            }
                        } else {
                            t -= 0x14;
                            if (t < 0x64) {
                                if (t == 0) {
                                    func_800BBEAC((M2C_UNK *)func_801B3E50);
                                    func_800BBEAC((M2C_UNK *)func_801B4570);
                                    e = func_800D4FA8(7);
                                    e->unk10 = 6;
                                    *(u32 *)&e->unkC = (u32)D_801B7DD4;
                                }
                                if (t == 0xF) {
                                    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B3F90)];
                                    q->unk4 = 0x2580;
                                    q->unk6 = -0x4E20;
                                    q->unk8 = 0;
                                    q->unk10 = 0;
                                    q->unkE = 0;
                                    q->unkC = 0;
                                    q->unk18 = 0x1F00;
                                }
                                if (t == 0x1E) {
                                    func_800BBEAC((M2C_UNK *)func_801B48E8);
                                }
                                if (t == 0x50) {
                                    func_800D5138(0xA);
                                }
                                if (t == 0x5A) {
                                    D_800F5B74 = 0;
                                    D_800F8380 |= 7;
                                }
                                if (t == 0x62) {
                                    func_800C610C();
                                    func_800D2980((M2C_UNK *)((u8 *)D_801B7DD4 + D_801B7DD4[1] * 4), 0, 0, 0);
                                    func_800D2980((M2C_UNK *)((u8 *)D_801B7DD4 + D_801B7DD4[2] * 4), 0, 0, 0);
                                }
                            } else {
                                t -= 0x64;
                                if (t < 0x37) {
                                    if (t == 0) {
                                        func_800D51D4(0xF);
                                        func_800BBEAC((M2C_UNK *)func_801B4AE4);
                                        func_800BBEAC((M2C_UNK *)func_801B4DD4);
                                        func_800D55F4(0x22, 0x40, 0x28B, 0x28C, 0x28D);
                                    }
                                } else {
                                    t -= 0x37;
                                    if (t >= 0xA3) {
                                        t -= 0xA3;
                                        if (t < 0x2A) {
                                            if (t == 0) {
                                                func_800BBEAC((M2C_UNK *)func_801B5390);
                                                func_800BBEAC((M2C_UNK *)func_801B5604);
                                                func_800BBEAC((M2C_UNK *)func_801B5A48);
                                                func_800D55F4(0x22, 0x40, 0x28E, 0x28F, 0x290);
                                            }
                                        } else {
                                            t -= 0x2A;
                                            if (t < 0xF) {
                                                if (t == 0) {
                                                    func_800BBEAC((M2C_UNK *)func_801B5D80);
                                                }
                                            } else {
                                                t -= 0xF;
                                                if (t < 0x2D) {
                                                    if (t == 0) {
                                                        func_800BBEAC((M2C_UNK *)func_801B6334);
                                                    }
                                                } else {
                                                    t -= 0x2D;
                                                    if (t >= 0x1E) {
                                                        t -= 0x1E;
                                                        if (t < 0x28) {
                                                            if (t == 0) {
                                                                func_800BBEAC((M2C_UNK *)func_801B66C8);
                                                                func_800BBEAC((M2C_UNK *)func_801B6A2C);
                                                                func_800BBEAC((M2C_UNK *)func_801B712C);
                                                            }
                                                            if (t == 0x14) {
                                                                func_800D5138(0xA);
                                                            }
                                                            if (t == 0x27) {
                                                                D_800F8380 &= 0xF8;
                                                                func_801B7254();
                                                            }
                                                            if (t == 0) {
                                                                func_800D55F4(0x22, 0x40, 0x291, 0x292, 0x293);
                                                            }
                                                        } else {
                                                            t -= 0x28;
                                                            if (t <= 0) {
                                                                if (t == 0) {
                                                                    func_800D51D4(0xA);
                                                                }
                                                            } else {
                                                                ((void (*)(u8))func_8001C3C4)(D_80154779);
                                                                for (i = 0; i < 10; i++) {
                                                                    if ((D_801F1ABC >> i) & 1) {
                                                                        func_800D5774(i);
                                                                    }
                                                                }
                                                                D_800F8380 = 0;
                                                                p->unk0 = -1;
                                                                return;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        p->unk2++;
    }
}

void func_801B7C4C(arg0, arg1) {
    MgSVec v;
    s32 z;
    s32 k;
    M2C_UNK *q;

    func_800D2980(&D_801B7DD4, 0, 0, 0);
    D_801F1ABC = arg0;
    func_800D54EC(arg0, (s16 *)&v);
    if (v.vz < D_80151A50[arg1].vx) {
        k = 0x800;
        D_801EEDD2 = k;
    }
    func_8003C21C(&D_801EEDD0, &D_801EEDD8);
    z = v.vz;
    v.vx = -0x15;
    v.vz = 0;
    v.vy = 0;
    D_801EEDF4 = z;
    func_8003C21C((s16 *)&v, &D_801F1AE0);
    D_801F1AF4 = D_801EEDF8.vx;
    D_801F1AF8 = D_801EEDFA;
    D_801F1AFC = D_801EEDFC;
    func_800BBEAC(&func_801B7340);
    k = func_80042DA8() & 0x100;
    q = &D_801EEFC0;
    if (k) {
        q = &D_801EEE6C;
    }
    ((void (*)(s32, s32, s32))func_801B2808)((s32)q, (s32)&D_801EEDD8, arg1);
    func_800BBEAC(&func_801B7610);
    D_800F8380 |= 8;
    ((void (*)(u8))func_8001C3C4)(D_80154779);
}
