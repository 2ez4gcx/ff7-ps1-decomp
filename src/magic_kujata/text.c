#include "common.h"
#include "magic_kujata/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B88A4();
    return &D_801DDD1C;
}

MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EFCE0.m[0][0] = D_801EFCE0.m[1][1] = D_801EFCE0.m[2][2] = scale;
    func_8003B48C(&D_801F04C8);
    func_8003B51C(&D_801F04C8);
    func_8003BC6C(v, (MgVec *)D_801EFCE0.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EFCE0.t, &n);
        D_801EFCE0.t[0] += (dist * n.vx) >> 12;
        D_801EFCE0.t[1] += (dist * n.vy) >> 12;
        D_801EFCE0.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EFCE0);
    func_8003B51C(&D_801EFCE0);
    return &D_801EFCE0;
}

s32 func_801B0184(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F04FA[-v];
    }
    return v;
}

s32 func_801B01C0(s32 t, s32 s) {
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

void func_801B02B0(void) {
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
            D_801F03F4.actor = -1;
            D_801F0420.actor = -1;
            D_801F03F4.frames = 0;
            D_801F0420.frames = 0;
            p->unk2 = 1;
        }
        while (D_801F03F4.frames == 0 || D_801F0420.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801F044C = &D_801F03F4;
                D_801F0450 = &D_801F0420;
            } else {
                D_801F044C = &D_801F0420;
                D_801F0450 = &D_801F03F4;
            }
            D_801F044C->mode = op & 0xFF3F;
            switch (D_801F044C->mode) {
            case 1:
                D_801F044C->pos.vx = *p->script++;
                D_801F044C->pos.vy = *p->script++;
                D_801F044C->pos.vz = *p->script++;
                break;
            case 2:
                D_801F044C->frames = func_801B0184(&p->script);
                D_801F044C->vel.vx = (*p->script++ - D_801F044C->pos.vx) / D_801F044C->frames;
                D_801F044C->vel.vy = (*p->script++ - D_801F044C->pos.vy) / D_801F044C->frames;
                D_801F044C->vel.vz = (*p->script++ - D_801F044C->pos.vz) / D_801F044C->frames;
                break;
            case 3:
                sv->vx = D_801F0450->pos.vx - D_801F044C->pos.vx;
                sv->vy = D_801F0450->pos.vy - D_801F044C->pos.vy;
                sv->vz = D_801F0450->pos.vz - D_801F044C->pos.vz;
                D_801F044C->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801F044C->unk18 = D_801F044C->pos;
                D_801F044C->frames = func_801B0184(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801F044C->vel.vx = (sv->vx - D_801F044C->pos.vx) / D_801F044C->frames;
                D_801F044C->vel.vy = (sv->vy - D_801F044C->pos.vy) / D_801F044C->frames;
                D_801F044C->vel.vz = (sv->vz - D_801F044C->pos.vz) / D_801F044C->frames;
                if (D_801F0450->mode == 2) {
                    sv2->vx = D_801F0450->pos.vx + D_801F0450->vel.vx * D_801F0450->frames;
                    sv2->vy = D_801F0450->pos.vy + D_801F0450->vel.vy * D_801F0450->frames;
                    sv2->vz = D_801F0450->pos.vz + D_801F0450->vel.vz * D_801F0450->frames;
                } else {
                    sv2->vx = D_801F0450->pos.vx;
                    sv2->vy = D_801F0450->pos.vy;
                    sv2->vz = D_801F0450->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801F044C->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801F044C->unk4) / D_801F044C->frames;
                break;
            case 4:
                D_801F044C->frames = func_801B0184(&p->script);
                sv->vx = *p->script++ - D_801F044C->pos.vx;
                sv->vy = *p->script++ - D_801F044C->pos.vy;
                sv->vz = *p->script++ - D_801F044C->pos.vz;
                D_801F044C->unk18.vx = ((sv->vx - D_801F044C->vel.vx * D_801F044C->frames) * 2) / (D_801F044C->frames * D_801F044C->frames);
                D_801F044C->unk18.vy = ((sv->vy - D_801F044C->vel.vy * D_801F044C->frames) * 2) / (D_801F044C->frames * D_801F044C->frames);
                D_801F044C->unk18.vz = ((sv->vz - D_801F044C->vel.vz * D_801F044C->frames) * 2) / (D_801F044C->frames * D_801F044C->frames);
                break;
            case 5:
                D_801F044C->frames = func_801B0184(&p->script);
                D_801F044C->unk28 = *p->script++;
                D_801F044C->unk4 = 0;
                D_801F044C->unk8 = 0x1000 / D_801F044C->frames;
                D_801F044C->unk18.vx = D_801F044C->pos.vx;
                D_801F044C->unk18.vy = D_801F044C->pos.vy;
                D_801F044C->unk18.vz = D_801F044C->pos.vz;
                D_801F044C->vel.vx = *p->script++ - D_801F044C->pos.vx;
                D_801F044C->vel.vy = *p->script++ - D_801F044C->pos.vy;
                D_801F044C->vel.vz = *p->script++ - D_801F044C->pos.vz;
                break;
            case 6:
                if ((D_801F044C->actor = *p->script++) == 0) {
                    D_801F044C->actor = p->actor;
                }
                D_801F044C->part = *p->script++;
                break;
            case 7:
                D_801F044C->actor = -1;
                break;
            case 0:
            case 9:
                D_801F044C->frames = func_801B0184(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801F044C = &D_801F03F4;
        D_801F0450 = &D_801F0420;
        for (i = 0; i < 2; i++) {
            switch (D_801F044C->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801F044C->vel.vx += D_801F044C->unk18.vx;
                D_801F044C->vel.vy += D_801F044C->unk18.vy;
                D_801F044C->vel.vz += D_801F044C->unk18.vz;
            case 2:
                D_801F044C->pos.vx += D_801F044C->vel.vx;
                D_801F044C->pos.vy += D_801F044C->vel.vy;
                D_801F044C->pos.vz += D_801F044C->vel.vz;
                break;
            case 3:
                D_801F044C->unk18.vx += D_801F044C->vel.vx;
                D_801F044C->unk18.vy += D_801F044C->vel.vy;
                D_801F044C->unk18.vz += D_801F044C->vel.vz;
                D_801F044C->unk4 += D_801F044C->unk8;
                vec->vx = D_801F0450->pos.vx - D_801F044C->unk18.vx;
                vec->vy = D_801F0450->pos.vy - D_801F044C->unk18.vy;
                vec->vz = D_801F0450->pos.vz - D_801F044C->unk18.vz;
                func_8003A078(vec, sv);
                D_801F044C->pos.vx = D_801F0450->pos.vx - ((sv->vx * D_801F044C->unk4) >> 12);
                D_801F044C->pos.vy = D_801F0450->pos.vy - ((sv->vy * D_801F044C->unk4) >> 12);
                D_801F044C->pos.vz = D_801F0450->pos.vz - ((sv->vz * D_801F044C->unk4) >> 12);
                break;
            case 5:
                D_801F044C->unk4 += D_801F044C->unk8;
                k = func_801B01C0(D_801F044C->unk4, D_801F044C->unk28);
                D_801F044C->pos.vx = D_801F044C->unk18.vx + ((D_801F044C->vel.vx * k) >> 12);
                D_801F044C->pos.vy = D_801F044C->unk18.vy + ((D_801F044C->vel.vy * k) >> 12);
                D_801F044C->pos.vz = D_801F044C->unk18.vz + ((D_801F044C->vel.vz * k) >> 12);
                break;
            }
            cam = D_801F044C;
            D_801F044C = &D_801F0420;
            D_801F0450 = &D_801F03F4;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801F03F4.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801F03F4.actor == -1) {
                func_8003BC6C(&D_801F03F4.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801F03F4.pos, vec);
                if (D_801F03F4.part != -1) {
                    func_800D3994(D_801F03F4.actor, D_801F03F4.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801F03F4.actor].vx;
                    sv->vy = D_80151A4C[D_801F03F4.actor].vy;
                    sv->vz = D_80151A4C[D_801F03F4.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801F0420.mode != 9) {
            if (D_801F0420.actor == -1) {
                func_8003BC6C(&D_801F0420.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801F0420.pos, vec);
                if (D_801F0420.part != -1) {
                    func_800D3994(D_801F0420.actor, D_801F0420.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801F0420.actor].vx;
                    sv->vy = D_80151A4C[D_801F0420.actor].vy;
                    sv->vz = D_80151A4C[D_801F0420.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801F03F4.mode != 9) {
            D_80158D00 = D_801F03F4.pos;
        }
        if (D_801F0420.mode != 9) {
            D_801031E8 = D_801F0420.pos;
        }
    }
}

void func_801B12E4(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B02B0)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B1348);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B1AF4);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B2250);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B292C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B2DB8);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B3878);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B3C60);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B3D20);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B3DE4);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B3EA8);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B42B8);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B4570);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B4B88);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B4D10);

void func_801B500C(void) {
    MgTask *p;
    s32 t;
    s16 y;
    s16 r;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x2D) {
        if (D_80062D98 == 0) {
            func_801B42B8();
        }
        func_801B3EA8();
    } else {
        t -= 0x2D;
        if (t < 0xF) {
            if (t == 0) {
                func_801B4D10();
            }
            y = 0;
            t = (t << 12) / 15;
            r = func_801B01C0(t, 0x3C0);
            if (t >= 0x800) {
                y = t - 0x800;
            }
            func_8003A63C(&D_801F04C8, D_801EFCC0, &D_801F01D4->m1);
            D_801F01D4->rot.vx = 0;
            D_801F01D4->rot.vy = t;
            D_801F01D4->rot.vz = 0;
            func_8003C21C(D_801F01D4, &D_801F01D4->m2);
            D_801F01D4->scale.vx = D_801F01D4->scale.vy = D_801F01D4->scale.vz = 0x1000;
            func_8003B35C(&D_801F01D4->m2, &D_801F01D4->scale);
            D_80163C74 = func_801B1348(D_801EFCB0, D_801517C0 + 0x70, 0xC, D_80163C74, D_801F04F4, D_801F04F0, D_801F04F8, r, y, &D_801F01D4->m1, &D_801F01D4->m2);
        } else {
            p->unk0 = -1;
            return;
        }
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B521C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B536C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B54CC);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B575C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B5AE0);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B5C98);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B5D88);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B5EDC);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B6034);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B62C0);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B6500);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B6644);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B666C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B66F8);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B68C4);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B6C18);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B6CE0);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B7028);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B7208);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B731C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B7438);

void func_801B75D8(void) {
    MgMat m;

    D_801F0364 = D_801EFC88;
    D_801F0354 = D_801EFC88;
    if (D_801EFCAA != 0) {
        D_801F0370 = D_801EFCA4;
    } else {
        D_801F0370 = -D_801EFCA4;
    }
    func_8003A63C(&D_801F0334, &D_801F0354, &m);
    func_801B3878(&m, &D_801F0374);
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B7668);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B794C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B79C0);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B7CFC);

void func_801B7F24(s16 arg0) {
    D_80162978[func_800BBEAC(&func_801B7CFC)].unk0 = arg0;
}

void func_801B7F6C(void) {
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
                    D_800FA666[0] = 0;
                    return;
                }
                d = (t << 12) / d;
                v = (p->unk4 * (0x1000 - d)) >> 12;
            }
        }
        D_800FA666[0] = (p->unk2 & 1) ? v : -v;
        p->unk2++;
    }
}

void func_801B80A8(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B7F6C)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B811C);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B81A8);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B8280);

INCLUDE_ASM("../asm/us/magic_kujata/nonmatchings/text", func_801B88A4);
