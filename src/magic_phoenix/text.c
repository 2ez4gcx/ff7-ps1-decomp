#include "common.h"
#include "magic_phoenix/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B47DC();
    return &D_801DA084;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801EC976[-v];
    }
    return v;
}

s32 func_801B00A4(s32 t, s32 s) {
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

void func_801B0194(void) {
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
            D_801EC880.actor = -1;
            D_801EC8AC.actor = -1;
            D_801EC880.frames = 0;
            D_801EC8AC.frames = 0;
            p->unk2 = 1;
        }
        while (D_801EC880.frames == 0 || D_801EC8AC.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801EC8D8 = &D_801EC880;
                D_801EC8DC = &D_801EC8AC;
            } else {
                D_801EC8D8 = &D_801EC8AC;
                D_801EC8DC = &D_801EC880;
            }
            D_801EC8D8->mode = op & 0xFF3F;
            switch (D_801EC8D8->mode) {
            case 1:
                D_801EC8D8->pos.vx = *p->script++;
                D_801EC8D8->pos.vy = *p->script++;
                D_801EC8D8->pos.vz = *p->script++;
                break;
            case 2:
                D_801EC8D8->frames = func_801B0068(&p->script);
                D_801EC8D8->vel.vx = (*p->script++ - D_801EC8D8->pos.vx) / D_801EC8D8->frames;
                D_801EC8D8->vel.vy = (*p->script++ - D_801EC8D8->pos.vy) / D_801EC8D8->frames;
                D_801EC8D8->vel.vz = (*p->script++ - D_801EC8D8->pos.vz) / D_801EC8D8->frames;
                break;
            case 3:
                sv->vx = D_801EC8DC->pos.vx - D_801EC8D8->pos.vx;
                sv->vy = D_801EC8DC->pos.vy - D_801EC8D8->pos.vy;
                sv->vz = D_801EC8DC->pos.vz - D_801EC8D8->pos.vz;
                D_801EC8D8->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801EC8D8->unk18 = D_801EC8D8->pos;
                D_801EC8D8->frames = func_801B0068(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801EC8D8->vel.vx = (sv->vx - D_801EC8D8->pos.vx) / D_801EC8D8->frames;
                D_801EC8D8->vel.vy = (sv->vy - D_801EC8D8->pos.vy) / D_801EC8D8->frames;
                D_801EC8D8->vel.vz = (sv->vz - D_801EC8D8->pos.vz) / D_801EC8D8->frames;
                if (D_801EC8DC->mode == 2) {
                    sv2->vx = D_801EC8DC->pos.vx + D_801EC8DC->vel.vx * D_801EC8DC->frames;
                    sv2->vy = D_801EC8DC->pos.vy + D_801EC8DC->vel.vy * D_801EC8DC->frames;
                    sv2->vz = D_801EC8DC->pos.vz + D_801EC8DC->vel.vz * D_801EC8DC->frames;
                } else {
                    sv2->vx = D_801EC8DC->pos.vx;
                    sv2->vy = D_801EC8DC->pos.vy;
                    sv2->vz = D_801EC8DC->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801EC8D8->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801EC8D8->unk4) / D_801EC8D8->frames;
                break;
            case 4:
                D_801EC8D8->frames = func_801B0068(&p->script);
                sv->vx = *p->script++ - D_801EC8D8->pos.vx;
                sv->vy = *p->script++ - D_801EC8D8->pos.vy;
                sv->vz = *p->script++ - D_801EC8D8->pos.vz;
                D_801EC8D8->unk18.vx = ((sv->vx - D_801EC8D8->vel.vx * D_801EC8D8->frames) * 2) / (D_801EC8D8->frames * D_801EC8D8->frames);
                D_801EC8D8->unk18.vy = ((sv->vy - D_801EC8D8->vel.vy * D_801EC8D8->frames) * 2) / (D_801EC8D8->frames * D_801EC8D8->frames);
                D_801EC8D8->unk18.vz = ((sv->vz - D_801EC8D8->vel.vz * D_801EC8D8->frames) * 2) / (D_801EC8D8->frames * D_801EC8D8->frames);
                break;
            case 5:
                D_801EC8D8->frames = func_801B0068(&p->script);
                D_801EC8D8->unk28 = *p->script++;
                D_801EC8D8->unk4 = 0;
                D_801EC8D8->unk8 = 0x1000 / D_801EC8D8->frames;
                D_801EC8D8->unk18.vx = D_801EC8D8->pos.vx;
                D_801EC8D8->unk18.vy = D_801EC8D8->pos.vy;
                D_801EC8D8->unk18.vz = D_801EC8D8->pos.vz;
                D_801EC8D8->vel.vx = *p->script++ - D_801EC8D8->pos.vx;
                D_801EC8D8->vel.vy = *p->script++ - D_801EC8D8->pos.vy;
                D_801EC8D8->vel.vz = *p->script++ - D_801EC8D8->pos.vz;
                break;
            case 6:
                if ((D_801EC8D8->actor = *p->script++) == 0) {
                    D_801EC8D8->actor = p->actor;
                }
                D_801EC8D8->part = *p->script++;
                break;
            case 7:
                D_801EC8D8->actor = -1;
                break;
            case 0:
            case 9:
                D_801EC8D8->frames = func_801B0068(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801EC8D8 = &D_801EC880;
        D_801EC8DC = &D_801EC8AC;
        for (i = 0; i < 2; i++) {
            switch (D_801EC8D8->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801EC8D8->vel.vx += D_801EC8D8->unk18.vx;
                D_801EC8D8->vel.vy += D_801EC8D8->unk18.vy;
                D_801EC8D8->vel.vz += D_801EC8D8->unk18.vz;
            case 2:
                D_801EC8D8->pos.vx += D_801EC8D8->vel.vx;
                D_801EC8D8->pos.vy += D_801EC8D8->vel.vy;
                D_801EC8D8->pos.vz += D_801EC8D8->vel.vz;
                break;
            case 3:
                D_801EC8D8->unk18.vx += D_801EC8D8->vel.vx;
                D_801EC8D8->unk18.vy += D_801EC8D8->vel.vy;
                D_801EC8D8->unk18.vz += D_801EC8D8->vel.vz;
                D_801EC8D8->unk4 += D_801EC8D8->unk8;
                vec->vx = D_801EC8DC->pos.vx - D_801EC8D8->unk18.vx;
                vec->vy = D_801EC8DC->pos.vy - D_801EC8D8->unk18.vy;
                vec->vz = D_801EC8DC->pos.vz - D_801EC8D8->unk18.vz;
                func_8003A078(vec, sv);
                D_801EC8D8->pos.vx = D_801EC8DC->pos.vx - ((sv->vx * D_801EC8D8->unk4) >> 12);
                D_801EC8D8->pos.vy = D_801EC8DC->pos.vy - ((sv->vy * D_801EC8D8->unk4) >> 12);
                D_801EC8D8->pos.vz = D_801EC8DC->pos.vz - ((sv->vz * D_801EC8D8->unk4) >> 12);
                break;
            case 5:
                D_801EC8D8->unk4 += D_801EC8D8->unk8;
                k = func_801B00A4(D_801EC8D8->unk4, D_801EC8D8->unk28);
                D_801EC8D8->pos.vx = D_801EC8D8->unk18.vx + ((D_801EC8D8->vel.vx * k) >> 12);
                D_801EC8D8->pos.vy = D_801EC8D8->unk18.vy + ((D_801EC8D8->vel.vy * k) >> 12);
                D_801EC8D8->pos.vz = D_801EC8D8->unk18.vz + ((D_801EC8D8->vel.vz * k) >> 12);
                break;
            }
            cam = D_801EC8D8;
            D_801EC8D8 = &D_801EC8AC;
            D_801EC8DC = &D_801EC880;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801EC880.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801EC880.actor == -1) {
                func_8003BC6C(&D_801EC880.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801EC880.pos, vec);
                if (D_801EC880.part != -1) {
                    func_800D3994(D_801EC880.actor, D_801EC880.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801EC880.actor].vx;
                    sv->vy = D_80151A4C[D_801EC880.actor].vy;
                    sv->vz = D_80151A4C[D_801EC880.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801EC8AC.mode != 9) {
            if (D_801EC8AC.actor == -1) {
                func_8003BC6C(&D_801EC8AC.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801EC8AC.pos, vec);
                if (D_801EC8AC.part != -1) {
                    func_800D3994(D_801EC8AC.actor, D_801EC8AC.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801EC8AC.actor].vx;
                    sv->vy = D_80151A4C[D_801EC8AC.actor].vy;
                    sv->vz = D_80151A4C[D_801EC8AC.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801EC880.mode != 9) {
            D_80158D00 = D_801EC880.pos;
        }
        if (D_801EC8AC.mode != 9) {
            D_801031E8 = D_801EC8AC.pos;
        }
    }
}

void func_801B11C8(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B0194)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B122C);

MgMat *func_801B179C(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EC6B4.m[0][0] = D_801EC6B4.m[1][1] = D_801EC6B4.m[2][2] = scale;
    func_8003B48C(&D_801EC954);
    func_8003B51C(&D_801EC954);
    func_8003BC6C(v, (MgVec *)D_801EC6B4.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EC6B4.t, &n);
        D_801EC6B4.t[0] += (dist * n.vx) >> 12;
        D_801EC6B4.t[1] += (dist * n.vy) >> 12;
        D_801EC6B4.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EC6B4);
    func_8003B51C(&D_801EC6B4);
    return &D_801EC6B4;
}

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B18B8);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B1978);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B1B74);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B1E40);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B1F80);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B2138);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B2490);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B275C);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B28D0);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B2C04);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B2F34);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B30D0);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B3210);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B3384);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B35F8);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B3960);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B39D0);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B3C08);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B3D30);

void func_801B3F84(void) {
    MgTask *p;
    MgPhElem *e;
    MgPhElem *f;
    s32 i;
    s32 j;
    s32 s;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        *(s32 *)&D_801EC854 = 0x2E808080;
        s = (t << 12) / 5;
    } else {
        t -= 5;
        if (t < 0x14) {
            *(s32 *)&D_801EC854 = 0x2E808080;
            s = 0x1000;
        } else {
            t -= 0x14;
            if (t >= 5) {
                p->unk0 = -1;
                return;
            }
            s = 0x1000;
            c = (-((t << 12) / 5 << 7) >> 12) - 0x80;
            D_801EC854 = D_801EC855 = D_801EC856 = c;
        }
    }
    i = 0;
    j = 0;
    do {
        e = (MgPhElem *)(D_801EC558 + j);
        func_801B179C((MgSVec *)e, (s * e->w * 0x10) >> 16, 0);
        D_80163C74 = func_800D4D90(D_801EC850, D_801517C0 + 0x70, 0xC, D_80163C74);
        i++;
        if (D_80062D98 == 0) {
            f = (MgPhElem *)(D_801EC558 + j);
            f->x += f->vx;
            f->y += f->vy;
            f->z += f->vz;
            f->vx = f->vx * 15 >> 4;
            f->vy = f->vy * 15 >> 4;
            f->vz = f->vz * 15 >> 4;
        }
        j += 0x14;
    } while (i < 100);
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B41C0);

INCLUDE_ASM("../asm/us/magic_phoenix/nonmatchings/text", func_801B47DC);
