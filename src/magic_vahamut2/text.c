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

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3028);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B33C0);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B34C8);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3600);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3754);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3804);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3904);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3B84);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3E50);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B3F90);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B4570);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B4708);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B48E8);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B4AE4);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B4DD4);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B5238);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B5390);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B5604);

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

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B5A48);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B5BD8);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B5D80);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B606C);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B6334);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B66C8);

s32 func_801B6828(s32 arg0) {
    return -(arg0 * 0x1388) / -20000;
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B6868);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B6A2C);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B6C18);

void func_801B6EAC(s16 arg0) {
    D_80162978[func_800BBEAC(&func_801B6C18)].unk0 = arg0;
}

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B6EF4);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B712C);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B7254);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B7340);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B7610);

INCLUDE_ASM("../asm/us/magic_vahamut2/nonmatchings/text", func_801B7C4C);
