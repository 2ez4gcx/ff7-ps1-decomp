#include "common.h"
#include "magic_lasboss3/decls.h"

void func_801B0040(void) {
    func_801BA85C();
}

void func_801B0060(s16 mask, MgSVec *out) {
    MgVec sum;
    MgSVec pos;
    s16 i;
    s16 n;

    n = 0;
    sum.vx = sum.vy = sum.vz = 0;
    for (i = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            func_800D3994(i, D_8015190F[i][0], &pos);
            n++;
            sum.vx += pos.vx;
            sum.vy += pos.vy;
            sum.vz += pos.vz;
        }
    }
    out->vx = sum.vx / n;
    out->vy = sum.vy / n;
    out->vz = sum.vz / n;
}

void func_801B0208(s32 base, s16 range, MgSVec *out) {
    MgSVec v;
    MgSVec rot;
    MgMat m;

    v.vz = 0;
    v.vx = 0;
    v.vy = base + ((func_80042DA8() % range) * 2 - range);
    rot.vy = 0;
    rot.vx = func_80042DA8() % 800 - 400;
    rot.vz = func_80042DA8() % 800 - 400;
    func_8003BF8C(&rot, &m);
    func_8003B2CC(&m, &v, out);
}

void func_801B0338(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist) {
    MgMat m;
    MgMat pad;
    MgVec n;
    MgVec v;
    s32 flag;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(pos, (MgVec *)m.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)m.t, &n);
        m.t[0] += (dist * n.vx) >> 12;
        m.t[1] += (dist * n.vy) >> 12;
        m.t[2] += (dist * n.vz) >> 12;
    }
    func_8003C21C(rot, &m);
    v.vx = v.vy = v.vz = scale;
    func_8003B35C(&m, &v);
    func_8003B48C(&m);
    func_8003B51C(&m);
}

void func_801B0464(MgSVec *pos, MgSVec *rot, MgVec *scale, s32 dist) {
    MgMat m;
    MgMat r;
    MgVec n;
    s32 flag;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(pos, (MgVec *)m.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)m.t, &n);
        m.t[0] += (dist * n.vx) >> 12;
        m.t[1] += (dist * n.vy) >> 12;
        m.t[2] += (dist * n.vz) >> 12;
    }
    func_8003C21C(rot, &m);
    func_8003B35C(&m, scale);
    func_8003B48C(&m);
    func_8003B51C(&m);
}

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B057C);

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B0C18);

s32 func_801B1254(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801FC706[-v];
    }
    return v;
}

s32 func_801B1290(s32 t, s32 s) {
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

void func_801B1380(void) {
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
            D_801BBCDC.actor = -1;
            D_801BBD08.actor = -1;
            D_801BBCDC.frames = 0;
            D_801BBD08.frames = 0;
            p->unk2 = 1;
        }
        while (D_801BBCDC.frames == 0 || D_801BBD08.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801BBD34 = &D_801BBCDC;
                D_801BBD38 = &D_801BBD08;
            } else {
                D_801BBD34 = &D_801BBD08;
                D_801BBD38 = &D_801BBCDC;
            }
            D_801BBD34->mode = op & 0xFF3F;
            switch (D_801BBD34->mode) {
            case 1:
                D_801BBD34->pos.vx = *p->script++;
                D_801BBD34->pos.vy = *p->script++;
                D_801BBD34->pos.vz = *p->script++;
                break;
            case 2:
                D_801BBD34->frames = func_801B1254(&p->script);
                D_801BBD34->vel.vx = (*p->script++ - D_801BBD34->pos.vx) / D_801BBD34->frames;
                D_801BBD34->vel.vy = (*p->script++ - D_801BBD34->pos.vy) / D_801BBD34->frames;
                D_801BBD34->vel.vz = (*p->script++ - D_801BBD34->pos.vz) / D_801BBD34->frames;
                break;
            case 3:
                sv->vx = D_801BBD38->pos.vx - D_801BBD34->pos.vx;
                sv->vy = D_801BBD38->pos.vy - D_801BBD34->pos.vy;
                sv->vz = D_801BBD38->pos.vz - D_801BBD34->pos.vz;
                D_801BBD34->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801BBD34->unk18 = D_801BBD34->pos;
                D_801BBD34->frames = func_801B1254(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801BBD34->vel.vx = (sv->vx - D_801BBD34->pos.vx) / D_801BBD34->frames;
                D_801BBD34->vel.vy = (sv->vy - D_801BBD34->pos.vy) / D_801BBD34->frames;
                D_801BBD34->vel.vz = (sv->vz - D_801BBD34->pos.vz) / D_801BBD34->frames;
                if (D_801BBD38->mode == 2) {
                    sv2->vx = D_801BBD38->pos.vx + D_801BBD38->vel.vx * D_801BBD38->frames;
                    sv2->vy = D_801BBD38->pos.vy + D_801BBD38->vel.vy * D_801BBD38->frames;
                    sv2->vz = D_801BBD38->pos.vz + D_801BBD38->vel.vz * D_801BBD38->frames;
                } else {
                    sv2->vx = D_801BBD38->pos.vx;
                    sv2->vy = D_801BBD38->pos.vy;
                    sv2->vz = D_801BBD38->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801BBD34->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801BBD34->unk4) / D_801BBD34->frames;
                break;
            case 4:
                D_801BBD34->frames = func_801B1254(&p->script);
                sv->vx = *p->script++ - D_801BBD34->pos.vx;
                sv->vy = *p->script++ - D_801BBD34->pos.vy;
                sv->vz = *p->script++ - D_801BBD34->pos.vz;
                D_801BBD34->unk18.vx = ((sv->vx - D_801BBD34->vel.vx * D_801BBD34->frames) * 2) / (D_801BBD34->frames * D_801BBD34->frames);
                D_801BBD34->unk18.vy = ((sv->vy - D_801BBD34->vel.vy * D_801BBD34->frames) * 2) / (D_801BBD34->frames * D_801BBD34->frames);
                D_801BBD34->unk18.vz = ((sv->vz - D_801BBD34->vel.vz * D_801BBD34->frames) * 2) / (D_801BBD34->frames * D_801BBD34->frames);
                break;
            case 5:
                D_801BBD34->frames = func_801B1254(&p->script);
                D_801BBD34->unk28 = *p->script++;
                D_801BBD34->unk4 = 0;
                D_801BBD34->unk8 = 0x1000 / D_801BBD34->frames;
                D_801BBD34->unk18.vx = D_801BBD34->pos.vx;
                D_801BBD34->unk18.vy = D_801BBD34->pos.vy;
                D_801BBD34->unk18.vz = D_801BBD34->pos.vz;
                D_801BBD34->vel.vx = *p->script++ - D_801BBD34->pos.vx;
                D_801BBD34->vel.vy = *p->script++ - D_801BBD34->pos.vy;
                D_801BBD34->vel.vz = *p->script++ - D_801BBD34->pos.vz;
                break;
            case 6:
                if ((D_801BBD34->actor = *p->script++) == 0) {
                    D_801BBD34->actor = p->actor;
                }
                D_801BBD34->part = *p->script++;
                break;
            case 7:
                D_801BBD34->actor = -1;
                break;
            case 0:
            case 9:
                D_801BBD34->frames = func_801B1254(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801BBD34 = &D_801BBCDC;
        D_801BBD38 = &D_801BBD08;
        for (i = 0; i < 2; i++) {
            switch (D_801BBD34->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801BBD34->vel.vx += D_801BBD34->unk18.vx;
                D_801BBD34->vel.vy += D_801BBD34->unk18.vy;
                D_801BBD34->vel.vz += D_801BBD34->unk18.vz;
            case 2:
                D_801BBD34->pos.vx += D_801BBD34->vel.vx;
                D_801BBD34->pos.vy += D_801BBD34->vel.vy;
                D_801BBD34->pos.vz += D_801BBD34->vel.vz;
                break;
            case 3:
                D_801BBD34->unk18.vx += D_801BBD34->vel.vx;
                D_801BBD34->unk18.vy += D_801BBD34->vel.vy;
                D_801BBD34->unk18.vz += D_801BBD34->vel.vz;
                D_801BBD34->unk4 += D_801BBD34->unk8;
                vec->vx = D_801BBD38->pos.vx - D_801BBD34->unk18.vx;
                vec->vy = D_801BBD38->pos.vy - D_801BBD34->unk18.vy;
                vec->vz = D_801BBD38->pos.vz - D_801BBD34->unk18.vz;
                func_8003A078(vec, sv);
                D_801BBD34->pos.vx = D_801BBD38->pos.vx - ((sv->vx * D_801BBD34->unk4) >> 12);
                D_801BBD34->pos.vy = D_801BBD38->pos.vy - ((sv->vy * D_801BBD34->unk4) >> 12);
                D_801BBD34->pos.vz = D_801BBD38->pos.vz - ((sv->vz * D_801BBD34->unk4) >> 12);
                break;
            case 5:
                D_801BBD34->unk4 += D_801BBD34->unk8;
                k = func_801B1290(D_801BBD34->unk4, D_801BBD34->unk28);
                D_801BBD34->pos.vx = D_801BBD34->unk18.vx + ((D_801BBD34->vel.vx * k) >> 12);
                D_801BBD34->pos.vy = D_801BBD34->unk18.vy + ((D_801BBD34->vel.vy * k) >> 12);
                D_801BBD34->pos.vz = D_801BBD34->unk18.vz + ((D_801BBD34->vel.vz * k) >> 12);
                break;
            }
            cam = D_801BBD34;
            D_801BBD34 = &D_801BBD08;
            D_801BBD38 = &D_801BBCDC;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801BBCDC.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801BBCDC.actor == -1) {
                func_8003BC6C(&D_801BBCDC.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801BBCDC.pos, vec);
                if (D_801BBCDC.part != -1) {
                    func_800D3994(D_801BBCDC.actor, D_801BBCDC.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801BBCDC.actor].vx;
                    sv->vy = D_80151A4C[D_801BBCDC.actor].vy;
                    sv->vz = D_80151A4C[D_801BBCDC.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801BBD08.mode != 9) {
            if (D_801BBD08.actor == -1) {
                func_8003BC6C(&D_801BBD08.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801BBD08.pos, vec);
                if (D_801BBD08.part != -1) {
                    func_800D3994(D_801BBD08.actor, D_801BBD08.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801BBD08.actor].vx;
                    sv->vy = D_80151A4C[D_801BBD08.actor].vy;
                    sv->vz = D_80151A4C[D_801BBD08.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801BBCDC.mode != 9) {
            D_80158D00 = D_801BBCDC.pos;
        }
        if (D_801BBD08.mode != 9) {
            D_801031E8 = D_801BBD08.pos;
        }
    }
}

void func_801B23A8(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B1380)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B240C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801BC6FC = D_801BC6F4[p->unk2].v;
    p->unk2 = p->unk2 ^ 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B246C(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;
    s32 temp_a0;

    temp_s0 = &D_80162978[D_8015169C];
    temp_a0 = (s32) (func_80039A74(D_801BB7D0 * 0x33) * 0xFF0) >> 0x10;
    D_80163C74 = func_800C4FC8(temp_a0, temp_a0, temp_a0);
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 >= (M2C_FIELD(temp_s0, s16 *, 0x16) - 0x14)) {
            D_801BB7D0 = (u16) D_801BB7D0 - 1;
        }
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 == M2C_FIELD(temp_s0, s16 *, 0x16)) {
            D_801BB7D0 = 0x14;
            temp_s0->unk0 = -1;
        }
    }
}

void func_801B2554(void) {
    MgTask *p;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    v = (func_80039A74(D_801BB7D2 * 0x33) * 0xFF0) >> 16;
    D_80163C74 = func_800C4FC8(v, v, v);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x14) {
            D_801BB7D2 = (u16)D_801BB7D2 + 1;
        }
        if (p->unk2 >= p->unk16 - 0x14) {
            D_801BB7D2 = (u16)D_801BB7D2 - 1;
        }
        p->unk2++;
        if (p->unk2 == p->unk16) {
            p->unk0 = -1;
        }
    }
}

void func_801B265C(void) {
    s16 i;
    s32 o;
    s16 *p;
    s16 *q;
    s32 r;

    for (i = 0; i < 0x100; i++) {
        o = i * 12;
        if (*(s16 *)(o + D_801BBD48) == 0) {
            func_80042DA8();
            p = (s16 *)(o + D_801BBD48);
            p[0] = 1;
            p[1] = 0;
            *(s16 *)(o + D_801BBD48 + 4) = func_80042DA8() % 3000 - 0x5DC;
            r = func_80042DA8();
            q = (s16 *)(o + D_801BBD48);
            q[4] = 0x2EE0;
            q[3] = r % 3000 - 0x5DC;
            return;
        }
    }
}

void func_801B279C(void) {
    MgTask *p;
    s16 i;
    s16 k;
    s32 o;
    Lb3Rec *r;
    u8 *prim;
    s32 depth;
    s32 t;
    u32 c;
    s32 ox;
    s32 oy;
    s32 sx;
    s32 sy;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = (s16)(u16)p->unk2 - 0x3C;
    c = 0x80;
    if (k >= 0) {
        c = (u32)func_80039B40(k * 0x66) >> 5;
    }
    func_8003B64C(&ox, &oy);
    func_8003B6BC(0xA0, 0x5A);
    func_8003B48C(&D_801BB7D4);
    func_8003B51C(&D_801BB7D4);
    for (i = 0; i < 0x100; i++) {
        o = i * 12;
        r = (Lb3Rec *)(o + D_801BBD48);
        if (r->flag == 1) {
            prim = D_801BC6FC;
            depth = func_8003BBDC(&r->pos, prim + 8, &sx, &sy);
            if (depth > 0) {
                func_80046974(prim);
                func_80046848(prim, 1);
                prim[4] = prim[5] = prim[6] = c;
                t = (depth >> 2) * 4 + 0x70;
                func_80046794(t + D_801517C0, prim);
                D_801BC6FC = prim + 0xC;
            }
        }
    }
    func_8003B6BC(ox, oy);
    if (D_80062D98 == 0) {
        for (i = 0; i < 8; i++) {
            func_801B265C();
        }
        for (i = 0; i < 0x100; i++) {
            o = i * 12;
            r = (Lb3Rec *)(o + D_801BBD48);
            if (r->flag != 0) {
                r->pos.vz -= 0x258;
                if (++r->frame == 0x14) {
                    r->flag = 0;
                }
            }
        }
        p->unk2++;
        if (p->unk2 == 0x46) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B2A08);

void func_801B2DCC(u8 *arg0, MgSVec *arg1) {
    MgObj20 *p;

    D_801BC6C8 = arg0;
    D_801BC6CC = *(u16 *)(arg0 + *(s32 *)arg0 + 4);
    p = &D_80162978[func_800BBEAC(&func_801B2A08)];
    p->unk4 = arg1->vx;
    p->unk6 = arg1->vy;
    *(s16 *)&p->pad[0] = arg1->vz;
}

void func_801B2E4C(u8 *arg0, s16 arg1) {
    s16 i;
    s16 n;
    u8 *base;
    u8 *tab;
    s16 *src;

    i = 0;
    D_801BC6C8 = arg0;
    base = arg0 + 4;
    tab = base + *(s32 *)arg0;
    n = *(u16 *)tab;
    tab += 4;
    if (n > 0) {
        do {
            src = (s16 *)(base + *(s16 *)(tab + i * 16));
            D_801BC6BC[i].a = src[0] / arg1;
            D_801BC6BC[i].b = src[1] / arg1;
            D_801BC6BC[i].c = src[2] / arg1;
            i++;
        } while (i < n);
    }
}

void func_801B2F80(void) {
    s16 i;
    s16 n;

    n = D_801BC6CC;
    for (i = 0; i < n; i++) {
        if (D_801BC6C4[i] > 0) {
            D_801BC6B8[i].a += D_801BC6BC[i].a;
            D_801BC6B8[i].b += D_801BC6BC[i].b;
            D_801BC6B8[i].c += D_801BC6BC[i].c;
            D_801BC6BC[i].a -= (s16)D_801BC6BC[i].a / 10;
            D_801BC6BC[i].b -= (s16)D_801BC6BC[i].b / 10;
            D_801BC6BC[i].c -= (s16)D_801BC6BC[i].c / 10;
            D_801BC6C4[i] += 1;
        }
    }
}

void func_801B30D0(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368((MgSVec *)&p->unk4, 0x1000, 0);
    D_801BB7F4.v = D_801BBED0;
    D_80163C74 = func_800D4D90(&D_801BB7F4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkE -= 0x32;
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B31C0(void) {
    MgTask *p;
    MgMat m;
    s32 v;
    s16 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801BB814, &m);
    func_8003B35C(&m, &D_801BB81C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BB800.v = *D_801BB80C[p->unk16];
    v = (func_80039A74((0x800 / p->unk14) * p->unk2) << 7) >> 12;
    c = v;
    if ((s16)v > 0x80) {
        c = 0x80;
    }
    D_801BB804 = D_801BB805 = D_801BB806 = c;
    D_80163C74 = func_800D4D90(&D_801BB800, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == p->unk14) {
            p->unk0 = -1;
        }
    }
}

void func_801B3360(void) {
    MgTask *p;
    MgMat m;
    s32 v;
    s16 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801BB838, &m);
    func_8003B35C(&m, &D_801BB840);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BB82C.v = D_801BBEB4;
    D_801BB834.v = p->unk16;
    v = (func_80039A74(p->unk2 * 0x44) << 7) >> 12;
    c = v;
    if ((s16)v > 0x80) {
        c = 0x80;
    }
    D_801BB830 = D_801BB831 = D_801BB832 = c;
    D_80163C74 = func_800D4D90(&D_801BB82C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B34C0(void) {
    MgTask *p;
    MgTask *q;
    s16 n;
    s32 t;
    s16 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 % 5 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B3360)];
            q->unk4 = 0xC8;
            n = p->unk16;
            t = n * 0x8C;
            k = t - 0x12C;
            if (n == 3) {
                k = t - 0xA0;
            }
            q->unk6 = k;
            q->unk8 = 0xFA0;
            q->unk16 = p->unk16;
            p->unk16++;
            if (p->unk16 == 4) {
                t = 1;
                p->unk0 = -t;
            }
        }
        p->unk2++;
    }
}

void func_801B35E4(void) {
    MgTask *p;
    MgMat m;
    s32 v;
    s16 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801BB85C, &m);
    func_8003B35C(&m, &D_801BB864);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BB850.v = D_801BBEAC;
    D_801BB858.v = p->unk16;
    v = (func_80039B40(p->unk2 * 0x14) << 8) >> 12;
    c = v;
    if ((s16)v > 0x80) {
        c = 0x80;
    }
    D_801BB854 = D_801BB855 = D_801BB856 = c;
    D_80163C74 = func_800D4D90(&D_801BB850, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        if (p->unk1A++ < 8) {
            p->unk4 += p->unkC;
            p->unkC -= p->unkC / 8;
        }
        p->unk2++;
        if (p->unk2 == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B3790(void) {
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 % 10 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B35E4)];
            q->unk4 = -0xBB8;
            q->unk6 = p->unk16 * 0x64 - 0x320;
            q->unk8 = 0xFA0;
            q->unkC = 0x15E;
            q->unk2 = p->unk16 * 0xA;
            q->unk16 = p->unk16;
            q->unk1A = 0;
            p->unk16++;
            if (p->unk16 == 4) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B38C8(void) {
    MgTask *p;
    MgMat m;
    s32 ox;
    s32 oy;
    s16 k;
    u32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = (s16)(u16)p->unk2 - 0x3C;
    c = 0x80;
    if (k >= 0) {
        c = (u32)func_80039B40(k * 0x66) >> 5;
    }
    func_8003B64C(&ox, &oy);
    func_8003B6BC(0xA0, 0x5A);
    D_801BB884.vz = p->unk2 * 4;
    func_8003BF8C(&D_801BB884, &m);
    func_8003B35C(&m, &D_801BB88C);
    m.t[0] = 0;
    m.t[1] = 0;
    m.t[2] = 0xFA0;
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BB87E = c;
    D_801BB874.v = D_801BBEA4;
    D_80163C74 = func_800D29D4(&D_801BB874, D_801517C0 + 0x70, 0xC, D_80163C74);
    func_8003B6BC(ox, oy);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x46) {
            p->unk0 = -1;
        }
    }
}

void func_801B3A30(void) {
    MgTask *p;
    MgMat m;
    MgSVec rot;
    s32 ox;
    s32 oy;
    s16 k;
    u32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = (s16)(u16)p->unk2 - 0x3C;
    c = 0x80;
    if (k >= 0) {
        c = (u32)func_80039B40(k * 0x66) >> 5;
    }
    func_8003B64C(&ox, &oy);
    func_8003B6BC(0xA0, 0x5A);
    rot.vx = 0;
    rot.vy = 0;
    rot.vz = p->unk2 * 8;
    func_8003BF8C(&rot, &m);
    func_8003B35C(&m, &D_801BB8A8);
    m.t[0] = 0;
    m.t[1] = 0;
    m.t[2] = 0x1770;
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BB89C.v = D_801BBECC;
    D_80163C74 = func_800D4D90(&D_801BB89C, D_801517C0 + 0x4070, 1, D_80163C74);
    rot.vx = 0;
    rot.vy = 0;
    rot.vz = -p->unk2 * 8;
    func_8003BF8C(&rot, &m);
    func_8003B35C(&m, &D_801BB8A8);
    m.t[0] = 0;
    m.t[1] = 0;
    m.t[2] = 0x1770;
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BB8A0 = D_801BB8A1 = D_801BB8A2 = c;
    D_80163C74 = func_800D4D90(&D_801BB89C, D_801517C0 + 0x4070, 1, D_80163C74);
    func_8003B6BC(ox, oy);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x46) {
            p->unk0 = -1;
        }
    }
}

void func_801B3C4C(void) {
    MgTask *p;
    MgMat m;
    s32 ox;
    s32 oy;
    s16 k;
    u32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = (s16)(u16)p->unk2 - 0x3C;
    c = 0x80;
    if (k >= 0) {
        c = (u32)func_80039B40(k * 0x66) >> 5;
    }
    func_8003B64C(&ox, &oy);
    func_8003B6BC(0xA0, 0x5A);
    func_8003BF8C(&D_801BB8C4, &m);
    func_8003B35C(&m, &D_801BB8CC);
    m.t[0] = 0;
    m.t[1] = 0;
    m.t[2] = 0x1770;
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BB8BC = D_801BB8BD = D_801BB8BE = c;
    D_801BB8B8.v = D_801BBEC8;
    D_80163C74 = func_800D4D90(&D_801BB8B8, D_801517C0 + 0x4070, 1, D_80163C74);
    func_8003B6BC(ox, oy);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x46) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B3DB8);

void func_801B4004(void) {
    MgTask *p;
    MgTask *q;
    s16 n;
    s32 t;
    s32 r1;
    s32 r2;
    s32 r3;
    s32 r4;
    s32 r5;
    s32 r6;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x8C) {
            if (!(((volatile Lb3U *)p)->u2 & 1)) {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B3DB8)];
                t = func_80042DA8();
                t = t % 4000;
                r1 = func_80042DA8();
                q->unk6 = 0;
                q->unk8 = t - 0x3E8;
                q->unkC = 0;
                q->unk4 = r1 % 6000 - 0xBB8;
                r2 = func_80042DA8();
                q->unk10 = 0;
                q->unkE = -0x1F4 - r2 % 1500;
                r3 = func_80042DA8();
                q->unk1A = 0;
                v = r3 % 0x3800 + 0x800;
                goto block_6;
            }
        } else {
            D_801BA9B0 = 0xF00;
            if (!(((volatile Lb3U *)p)->u2 & 1)) {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B3DB8)];
                q->unk4 = func_80042DA8() % 10000 - 0x1388;
                q->unk6 = func_80042DA8() % 500 - 0x1F4;
                r4 = func_80042DA8();
                q->unkC = 0;
                q->unk8 = r4 % 2000 - 0x7D0;
                q->unkE = -0x32 - func_80042DA8() % 200;
                q->unk10 = 0x30C - func_80042DA8() % 400;
                r5 = func_80042DA8();
                q->unk1A = 0;
                v = r5 % 0x2C00 + 0x400;
block_6:
                q->unk18 = v;
                r6 = func_80042DA8();
                q->unk14 = 0x14;
                q->unk16 = r6 % 3;
            }
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xDC) {
            p->unk0 = -1;
        }
    }
}

void func_801B43CC(void) {
    MgTask *p;
    MgTask *q;
    MgMat m;
    MgMat pad;
    MgVec v;
    MgSVec rot;
    MgSVec pos;
    s16 i;
    s32 r;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vx = p->unk2 * 0x20;
    rot.vy = p->unk2 * 0x10;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    v.vx = v.vy = v.vz = p->unk18;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BB8FC = 0;
    D_801BB902 = 0x80;
    D_801BB8F8.v = D_801BBE6C;
    D_80163C74 = func_800D29D4(&D_801BB8F8, D_801517C0 + 0x406C, 0, D_80163C74);
    rot.vx = p->unk2 * 0x20;
    rot.vy = -(p->unk2 * 0x20);
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    v.vx = v.vy = v.vz = p->unk18;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BB8FC = 8;
    D_801BB902 = 0x80;
    D_801BB8F8.v = D_801BBE6C;
    D_80163C74 = func_800D29D4(&D_801BB8F8, D_801517C0 + 0x50, 0xC, D_80163C74);
    i = 0;
    if (D_80062D98 == 0) {
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B30D0)];
            rot.vx = 0;
            r = func_80042DA8();
            rot.vy = r % 0x800 - 0x400;
            rot.vz = 0;
            func_8003BF8C(&rot, &m);
            pos.vx = 0;
            pos.vy = 0;
            pos.vz = (s16)(u16)p->unk18 / 2 + 0x1F4;
            func_8003B2CC(&m, &pos, &pos);
            q->unk4 = p->unk4 + pos.vx;
            q->unk6 = 0;
            q->unk8 = p->unk8 + pos.vz;
            pos.vx = 0;
            pos.vy = 0;
            pos.vz = 0xC8;
            func_8003B2CC(&m, &pos, (MgSVec *)&q->unkC);
            i++;
        } while (i < 3);
        p->unk18 += 0x40;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xF0) {
            p->unk0 = -1;
        }
    }
}

void func_801B4704(void) {
    MgTask *p;
    MgMat m;
    MgMat pad;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801BB928, &m);
    func_8003B35C(&m, &D_801BB918);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BB908.v = D_801BBE94;
    D_80163C74 = func_800D29D4(&D_801BB908, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x77) {
            p->unk0 = -1;
        }
    }
}

void func_801B4804(void) {
    MgTask *p;
    MgMat m;
    MgMat pad;
    u16 t;
    s16 k;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_801BB930.v = D_801BBE90;
    func_8003C21C(&D_801BB950, &m);
    func_8003B35C(&m, &D_801BB940);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    if (p->unk2 < 0x1F) {
        func_8003B48C(&m);
        func_8003B51C(&m);
        D_80163C74 = func_800D29D4(&D_801BB930, D_801517C0 + 0x70, 0xC, D_80163C74);
    } else {
        D_80163C74 = func_801B0C18(&D_801BB930, D_801517C0 + 0x70, 0xC, D_80163C74, D_801BC6B8, D_801BC6C4, &m);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x1E) {
            func_801B2E4C(D_801BBE90, 2);
        }
        t = p->unk2;
        if ((u32)(t - 0x1E) < 0x10) {
            k = (s16)t - 0x1E;
            i = 0;
            do {
                D_801BC6C4[D_801BC6C0[k * 0x14 + i]] = 1;
                i++;
            } while (i < 0x14);
        }
        if (p->unk2 >= 0x1E) {
            func_801B2F80();
        }
        p->unk2++;
        if (p->unk2 == 0x5A) {
            p->unk0 = -1;
        }
    }
}

void func_801B4A28(void) {
    MgTask *p;
    MgMat m;
    MgMat pad;
    u16 t;
    s16 k;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_801BB958.v = D_801BBE8C;
    func_8003C21C(&D_801BB978, &m);
    func_8003B35C(&m, &D_801BB968);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    if (p->unk2 < 0x1F) {
        func_8003B48C(&m);
        func_8003B51C(&m);
        D_80163C74 = func_800D29D4(&D_801BB958, D_801517C0 + 0x70, 0xC, D_80163C74);
    } else {
        D_80163C74 = func_801B0C18(&D_801BB958, D_801517C0 + 0x70, 0xC, D_80163C74, D_801BC6B8, D_801BC6C4, &m);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x1E) {
            func_801B2E4C(D_801BBE8C, 2);
        }
        t = p->unk2;
        if ((u32)(t - 0x1E) < 0x10) {
            k = (s16)t - 0x1E;
            i = 0;
            do {
                D_801BC6C4[D_801BC6C0[k * 0x14 + i]] = 1;
                i++;
            } while (i < 0x14);
        }
        if (p->unk2 >= 0x1E) {
            func_801B2F80();
        }
        p->unk2++;
        if (p->unk2 == 0x5A) {
            p->unk0 = -1;
        }
    }
}

void func_801B4C4C(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 == 1) {
        D_80163C74 = func_800C4FC8(0xFF, 0xFF, 0xFF);
    } else {
        func_800D4368((MgSVec *)&p->unk4, 0x7F00, 0);
        D_801BB980.v = *D_801BB990[p->unk2];
        D_801BB980.f = (p->unk2 == 4) << 12;
        D_80163C74 = func_800D29D4(&D_801BB980, D_801517C0 + 0x4084, 3, D_80163C74);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B4D54(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    func_800D4368((MgSVec *)&p->unk4, (s16)(func_80039A74(p->unk2 << 7) * 3), -0x3E8);
    D_801BB9A8.f = 0;
    D_801BB9A8.v = D_801BBE88;
    D_80163C74 = func_800D29D4(&D_801BB9A8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B4E28(void) {
    MgObj20 *p;
    MgVec v;

    p = &D_80162978[D_8015169C];
    v.vx = (func_80039A74(p->unk2 << 7) * 0x1000) >> 12;
    v.vy = (func_80039B40(p->unk2 << 7) * 0x20) >> 12;
    v.vz = 0;
    func_801B0464((MgSVec *)&p->unk4, &D_801BB9C8, &v, -0x3E8);
    D_801BB9B8.f = 0;
    D_801BB9B8.v = D_801BBE30;
    D_80163C74 = func_800D29D4(&D_801BB9B8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B4F20(void) {
    MgTask *p;
    MgMat m;
    MgMat pad;
    MgVec v;
    MgSVec rot;
    MgSVec *q;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vx = p->unk2 * 0x20;
    rot.vy = p->unk2 * 0x10;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    v.vx = v.vy = v.vz = p->unk18;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BB9D4 = 0;
    D_801BB9DA = 0x80;
    D_801BB9D0.v = D_801BBE6C;
    D_80163C74 = func_800D29D4(&D_801BB9D0, D_801517C0 + 0xF0, 0xC, D_80163C74);
    rot.vx = p->unk2 * 0x20;
    rot.vy = -(p->unk2 * 0x20);
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    v.vx = v.vy = v.vz = p->unk18;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BB9D4 = 8;
    D_801BB9DA = 0x80;
    D_801BB9D0.v = D_801BBE6C;
    D_80163C74 = func_800D29D4(&D_801BB9D0, D_801517C0 + 0x50, 0xC, D_80163C74);
    q = (MgSVec *)&p->unk4;
    rot.vx = 0;
    rot.vy = 0;
    rot.vz = p->unk2 * 0x10;
    func_801B0338(q, &rot, (p->unk18 * 0xF800) >> 16, 0);
    D_801BB9DA = 0x40;
    D_801BB9D0.v = D_801BBE70;
    D_80163C74 = func_800D29D4(&D_801BB9D0, D_801517C0 + 0x70, 0xC, D_80163C74);
    rot.vx = 0;
    rot.vy = 0;
    rot.vz = -(p->unk2 * 0x10);
    func_801B0338(q, &rot, (p->unk18 * 0xF800) >> 16, 0);
    D_801BB9DA = 0x40;
    D_801BB9D0.v = D_801BBE74;
    D_80163C74 = func_800D29D4(&D_801BB9D0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x18) {
            p->unk18 += 0x12;
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x16C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B5270);

void func_801B567C(void) {
    MgTask *p;
    MgSVec v;
    MgMat m;
    s32 flag;
    s16 i;
    s16 n;
    u16 *q;
    s32 t;
    u32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    i = 1;
    func_8003BADC(&D_801BBA4C, &v, &flag);
    do {
        func_8003BF8C(&D_801BBA54, &m);
        func_8003B35C(&m, &D_801BBA5C);
        m.t[0] = v.vx + (p->unk4 * i) / 6;
        m.t[1] = v.vy + (p->unk6 * i) / 6;
        m.t[2] = v.vz + (p->unk8 * i) / 6;
        func_8003B48C(&m);
        func_8003B51C(&m);
        D_801BBA24.v = D_801BBEC4;
        q = (u16 *)(D_801BBA30 + i * 4);
        t = *q - 1;
        D_801BBA24.f8 = t | 0x8000;
        t = *q - 1;
        D_801BBA24.fA = t << 6;
        c = (u32)func_80039B40(p->unk2 * 0x22) >> 5;
        D_801BBA24.r = D_801BBA24.g = D_801BBA24.b = c;
        D_80163C74 = func_800D4D90(&D_801BBA24, D_801517C0 + 0x4084, 3, D_80163C74);
        i++;
    } while (i < 7);
    if (D_80062D98 == 0) {
        p->unkC -= p->unkC / 6;
        n = p->unk2 + 1;
        p->unk2 = n;
        p->unkE -= p->unkE / 6;
        p->unk4 += p->unkC;
        p->unk10 -= p->unk10 / 6;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (n == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B5978(void) {
    MgTask *p;
    MgMat m;
    MgMat pad;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C4AC(&D_801BBA8C, &m);
    func_8003B35C(&m, &D_801BBA7C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BBA6C.v = D_801BBE38;
    D_80163C74 = func_800D29D4(&D_801BBA6C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x5A) {
            p->unk4 = -0xC8;
            p->unk6 = 0x384;
            p->unk8 = 0x3E80;
        }
        p->unk2++;
        if (p->unk2 == 0x76) {
            p->unk0 = -1;
        }
    }
}

void func_801B5A9C(void) {
    MgTask *p;
    MgMat m;
    MgVec v;

    p = (MgTask *)&D_80162978[D_8015169C];
    v.vx = v.vy = v.vz = p->unk18;
    func_8003C21C(&D_801BBAA4, &m);
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BBA94.v = *D_801BBAAC[p->unk16];
    D_80163C74 = func_800D29D4(&D_801BBA94, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x76) {
            p->unk0 = -1;
        }
    }
}

void func_801B5BB8(void) {
    MgTask *p;
    MgMat *m;

    p = (MgTask *)&D_80162978[D_8015169C];
    m = func_800D4368((MgSVec *)&p->unk4, p->unk18, 0);
    if (p->unk16 == 0) {
        m->t[2] = 0x4E20;
        func_8003B51C(m);
    }
    D_801BBAB4.v = *D_801BBAC0[p->unk16];
    D_80163C74 = func_800D4D90(&D_801BBAB4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x76) {
            p->unk0 = -1;
        }
    }
}

void func_801B5C98(void) {
    MgTask *p;
    MgMat m;
    MgMat pad;
    MgVec v;
    s32 flag;
    s32 *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    func_8003C21C(&D_801BBAD8, &m);
    v.vx = v.vy = v.vz = (func_80039A74(p->unk2 * 0x33) * p->unk18) >> 12;
    func_8003B35C(&m, &v);
    func_8003B48C(&m);
    func_8003B51C(&m);
    q = &D_801BBAC8;
    *q = D_801BBE30;
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(q, D_801517C0 + 0x4084, 3, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B5DE8(void) {
    MgTask *p;
    MgMat m;
    MgMat pad;
    MgVec v;
    s32 flag;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    func_8003C21C(&D_801BBAF0, &m);
    v.vx = v.vy = v.vz = (func_80039A74(p->unk2 * 0x22) * p->unk18) >> 12;
    func_8003B35C(&m, &v);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BBAE0.f = func_80039A74(p->unk2 * 0x22);
    D_801BBAE0.v = D_801BBE30;
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801BBAE0, D_801517C0 + 0x4084, 3, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B5F54(void) {
    MgTask *p;
    MgMat m;
    MgMat pad;
    s32 flag;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    func_8003C4AC((MgSVec *)&p->unkC, &m);
    D_801BBB08.v = (func_80039A74(p->unk2 * 0x2D) * p->unk18) >> 12;
    func_8003B35C(&m, (MgVec *)&D_801BBB08);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BBAF8.f = func_80039A74(p->unk2 * 0x16);
    D_801BBAF8.v = D_801BBE34;
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801BBAF8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x2D) {
            p->unk0 = -1;
        }
    }
}

void func_801B60C4(void) {
    MgTask *p;
    MgMat m;
    MgVec v;
    s32 k;
    s32 t;
    s16 n;
    s16 d;
    s16 s;
    s16 g;
    s16 i;
    s32 o;
    s32 pa;
    s32 pb;
    s32 pr;
    MgSVec *a;
    MgSVec *b;
    MgSVec *r;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = p->unk2;
    if (k >= 0x47) {
        k = 0x46;
    }
    t = (k << 14) / 70;
    v.vz = v.vy = v.vx = t;
    n = (s16)(u16)p->unk2 - 0x46;
    if (n > 0) {
        v.vz = v.vy = v.vx = (n << 7) + t;
    }
    func_8003C4AC(&D_801BBB28, &m);
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    k = p->unk2;
    if (k >= 0x55) {
        D_801BBB22 = ((k - 0x55) * 0x7F) / 54 + 0x80;
    }
    D_801BBB18.v = D_801BBE24;
    D_80163C74 = func_800D29D4(&D_801BBB18, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x46) {
            g = D_801BBB30;
            d = (0x100 - g) / 2;
            if (d > 0) {
                s = d + g;
                i = 0;
                pa = D_801BBE28;
                pb = D_801BBE2C;
                pr = D_801BBE24 + 4;
                D_801BBB30 = s;
                do {
                    o = i * 8;
                    a = (MgSVec *)(pa + o);
                    b = (MgSVec *)(pb + o);
                    r = (MgSVec *)(pr + o);
                    r->vx = a->vx + (((b->vx - a->vx) * s) >> 8);
                    r->vy = a->vy + (((b->vy - a->vy) * s) >> 8);
                    r->vz = a->vz + (((b->vz - a->vz) * s) >> 8);
                    i++;
                } while (i < 0x438);
            }
        }
        p->unk2++;
        if (p->unk2 == 0x8B) {
            p->unk0 = -1;
        }
    }
}

void func_801B637C(void) {
    MgTask *p;
    s32 *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368((MgSVec *)&p->unk4, p->unk18, -0x1F4);
    D_801BBB3E = 0;
    q = &D_801BBB34;
    *q = D_801BBE20;
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk18 += (0x1000 - p->unk18) / 4;
        if (*D_801BBD44 == 0) {
            p->unk0 = -1;
        }
    }
}

void func_801B6470(u8 *arg0) {
    MgTask *p;
    MgTask *q;
    MgMat m;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C((MgSVec *)(arg0 + 0xC), &m);
    func_8003B35C(&m, &D_801BBB44);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    q = (MgTask *)&D_800FA63C;
    func_8003A63C((MgMat *)q, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BBB54.v = *D_801BBB64[p->unk16];
    D_80163C74 = func_800D29D4(&D_801BBB54, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == p->unk1A) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B637C)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk18 = 0;
            q->unk1A = 0;
            p->unk0 = -1;
        }
    }
}

void func_801B65C4(void) {
    MgTask *p;
    MgMat m;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C4AC(&D_801BBB90, &m);
    func_8003B35C(&m, &D_801BBB70);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BBB80.v = D_801BBE10;
    D_80163C74 = func_800D29D4(&D_801BBB80, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x5F) {
            p->unk0 = -1;
        }
    }
}

void func_801B66C4(void) {
    MgTask *p;
    MgMat m;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C4AC(&D_801BBBB8, &m);
    func_8003B35C(&m, &D_801BBB98);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BBBA8.v = D_801BBE0C;
    D_80163C74 = func_800D29D4(&D_801BBBA8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x5F) {
            p->unk0 = -1;
        }
    }
}

void func_801B67C4(void) {
    MgTask *p;
    MgMat m;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C4AC(&D_801BBBE0, &m);
    func_8003B35C(&m, &D_801BBBC0);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BBBD0.v = D_801BBE0C;
    D_80163C74 = func_800D29D4(&D_801BBBD0, D_801517C0 + 0x70, 0xC, D_80163C74);
    D_801BBBD0.v = D_801BBE08;
    D_80163C74 = func_800D29D4(&D_801BBBD0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x30) {
            p->unk0 = -1;
        }
    }
}

void func_801B6900(void) {
    MgTask *p;
    MgMat m;
    s32 v;
    s16 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801BBBF4, &m);
    func_8003B35C(&m, &D_801BBBFC);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    v = (func_80039A74(p->unk2 * 0x44) << 9) >> 12;
    c = v;
    if ((s16)v > 0x80) {
        c = 0x80;
    }
    D_801BBBE8.c = D_801BBBED = D_801BBBEE = c;
    D_801BBBF0 = p->unk16;
    D_80163C74 = func_800D4D90(&D_801BBBE8, D_801517C0 + 0x4084, 3, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B6A48(void) {
    MgTask *p;
    MgMat m;
    s16 i;
    s16 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801BBC2C, &m);
    func_8003B35C(&m, &D_801BBC0C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    D_801BBC1C.v = D_801BBE04;
    if (p->unk2 < 0x33) {
        func_8003B48C(&m);
        func_8003B51C(&m);
        D_80163C74 = func_800D29D4(&D_801BBC1C, D_801517C0 + 0x70, 0xC, D_80163C74);
    } else {
        D_80163C74 = func_801B0C18(&D_801BBC1C, D_801517C0 + 0x70, 0xC, D_80163C74, D_801BC6B8, D_801BC6C4, &m);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x32) {
            func_801B2E4C(D_801BBE04, 2);
        }
        if ((u16)p->unk2 == 0x32) {
            k = (s16)(u16)p->unk2 - 0x32;
            i = 0;
            do {
                D_801BC6C4[D_801BC6C0[k * 0x140 + i]] = 1;
                i++;
            } while (i < 0x140);
        }
        if (p->unk2 >= 0x32) {
            func_801B2F80();
        }
        p->unk2++;
        if (p->unk2 == 0x53) {
            p->unk0 = -1;
        }
    }
}

void func_801B6C6C(void) {
    MgTask *p;
    MgMat m;
    MgMat m2;
    MgVec v;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D44E8((MgSVec *)&p->unkC, &m2);
    D_801BBC44.vz = p->unk2 * 0x20;
    func_8003C21C(&D_801BBC44, &m);
    func_8003A79C(&m2, &m, &m);
    v.vx = (D_801BC6E0 - D_801BC6D0) * p->unk2 / p->unk1A + D_801BC6D0;
    v.vy = (D_801BC6E4 - D_801BC6D4) * p->unk2 / p->unk1A + D_801BC6D4;
    v.vz = (D_801BC6E8 - D_801BC6D8) * p->unk2 / p->unk1A + D_801BC6D8;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BBC34.v = D_801BBE00;
    D_80163C74 = func_800D29D4(&D_801BBC34, D_801517C0 + 0x70, 0xC, D_80163C74);
    D_801BBC44.vz = -p->unk2 * 0x20;
    func_8003C21C(&D_801BBC44, &m);
    func_8003A79C(&m2, &m, &m);
    v.vx -= v.vx / 3;
    v.vy -= v.vy / 3;
    v.vz -= v.vz / 3;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BBC34.v = D_801BBE00;
    D_80163C74 = func_800D29D4(&D_801BBC34, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        n = p->unk2 + 1;
        p->unk8 += p->unk10;
        p->unk2 = n;
        if (n == p->unk1A) {
            p->unk0 = -1;
        }
    }
}

void func_801B7028(void) {
    MgTask *p;
    MgMat m;
    MgMat m2;
    MgVec v;
    s32 k;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = p->unk2;
    if (k >= 0x5B) {
        k = 0x5A;
    }
    t = (k * 0x6000) / 90;
    v.vz = v.vy = v.vx = t;
    func_8003C21C((MgSVec *)&p->unkC, &m);
    func_8003C21C(&D_801BBC5C, &m2);
    func_8003B16C((s32)&m2, (s32)&m);
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    D_801BBC4C.v = D_801BBDFC;
    D_80163C74 = func_800D29D4(&D_801BBC4C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unkC = p->unkC;
        p->unkE -= 8;
        p->unk10 = p->unk10;
        D_801BBC5C.vx -= 3;
        D_801BBC5C.vy = D_801BBC5C.vy;
        D_801BBC5C.vz += 2;
        p->unk2++;
        if (p->unk2 == 0x87) {
            p->unk0 = -1;
        }
    }
}

void func_801B71EC(void) {
    MgTask *p;
    MgMat m;
    s32 v;
    s16 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801BBC70, &m);
    func_8003B35C(&m, &D_801BBC78);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    v = (func_80039A74(p->unk2 * 0x22) << 7) >> 12;
    c = v;
    if ((s16)v > 0x80) {
        c = 0x80;
    }
    D_801BBC68 = D_801BBC69 = D_801BBC6A = c;
    D_801BBC64.v = D_801BBEA8;
    D_80163C74 = func_800D4D90(&D_801BBC64, D_801517C0 + 0x4070, 1, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x14;
        if (++p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B7340);

void func_801B7610(void) {
    MgMat m;
    MgSVec rot;
    MgSVec v;
    s16 i;

    for (i = 0; i < 200; i++) {
        v.vx = 0;
        v.vy = 0;
        v.vz = func_80042DA8() % 20000 + 0x2710;
        rot.vx = func_80042DA8() % 4096;
        rot.vy = func_80042DA8() % 4096;
        rot.vz = 0;
        func_8003BF8C(&rot, &m);
        func_8003B2CC(&m, &v, &D_801BBEE8[i]);
        D_801BC528[i] = func_80042DA8() % 5 + (func_80042DA8() % 3) * 16;
    }
}

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B7798);

void func_801B7A94(void) {
    MgTask *p;
    MgMat m;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801BBCB8, &m);
    func_8003B35C(&m, &D_801BBC98);
    func_8003A79C(&D_800FA63C, &m, &m);
    m.t[1] = 0;
    m.t[0] = 0;
    m.t[2] = 0x7D0;
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_80163C74 = func_800D29D4(&D_801BBCA8, D_801517C0 + 0x4070, 1, D_80163C74);
    if (D_80062D98 == 0 && D_801BBD74 == 0) {
        p->unk0 = -1;
    }
}

void func_801B7B74(void) {
    s16 i;
    s16 n;
    s16 *flag;

    n = D_801BC6CC;
    for (i = 0; i < n; i++) {
        flag = (s16 *)((u8 *)D_801BC6C4 + i * 2);
        if (*flag > 0) {
            D_801BC6B8[i].c += D_801BC6BC[i].c;
            *flag += 1;
        }
    }
}

void func_801B7C18(Lb3Coord *arg0) {
    s32 flag;
    MgMat *m;

    m = arg0->super;
    *(MgMat **)0x1F800020 = m;
    *(MgMat *)0x1F800024 = *m;
    func_8003B16C(0x1F800024, (s32)arg0);
    func_8003B48C((MgMat *)0x1F800024);
    func_8003B51C((MgMat *)0x1F800024);
    func_8003BC6C(&arg0->t, (MgVec *)arg0->m.t, &flag);
    func_8003B48C((MgMat *)arg0);
    func_8003B51C((MgMat *)arg0);
}

void func_801B7CD8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Lb3Coord *arg4) {
    s32 v;
    s32 f;
    s32 pad[10];

    v = D_801590E8[arg0];
    *(s16 *)0x1F80032C = 0x20;
    *(s16 *)0x1F80032E = 0;
    *(s16 *)0x1F800328 = 0;
    *(u8 **)0x1F800320 = D_801590E4 + (v & 0x7FFFFFFF);
    if (v & 0x80000000) {
        f = 8;
    } else {
        f = 0;
    }
    arg3 |= 0x180;
    *(s32 *)0x1F800324 = f | arg3;
    *(u16 *)0x1F80032A = D_800F5B74;
    D_80163C74 = func_801B057C((void *)0x1F800320, arg1, arg2, D_80163C74, D_801BC6B8, D_801BC6C4, arg4);
}

void func_801B7DA0(void) {
    MgTask *p;
    u16 *q;
    Lb3Coord *o0;
    Lb3Coord *o1;
    Lb3Coord *o2;
    MgMat pad;
    s16 k;

    q = &D_800F81B0;
    D_800F81B6 = -0x9C4;
    *q += 8;
    p = (MgTask *)&D_80162978[D_8015169C];
    o0 = (Lb3Coord *)((u8 *)q - 0x24);
    func_8003C21C((MgSVec *)((u8 *)q - 4), (MgMat *)o0);
    func_801B7C18(o0);
    func_801B7CD8(6, D_801517C0 + 0x4070, 0, 0, o0);
    o1 = (Lb3Coord *)((u8 *)q + 0x10);
    D_800F81EA = -0x9C4;
    D_800F81E4 += 6;
    func_8003C21C((MgSVec *)((u8 *)q + 0x30), (MgMat *)o1);
    func_801B7C18(o1);
    func_801B7CD8(7, D_801517C0 + 0x4070, 0, 0, o1);
    o2 = (Lb3Coord *)((u8 *)q + 0x44);
    D_800F821E = -0x9C4;
    D_800F8218 += 4;
    func_8003C21C((MgSVec *)((u8 *)q + 0x64), (MgMat *)o2);
    func_801B7C18(o2);
    func_801B7CD8(8, D_801517C0 + 0x4070, 0, 0, o2);
    if (D_80062D98 == 0) {
        k = p->unk2;
        if (k < 0x28) {
            D_801BC6BC[((s16 *)D_801BC6C0)[k * 2]].c = ~k * 0x1E;
            D_801BC6C4[((s16 *)D_801BC6C0)[p->unk2 * 2]] = 1;
            k = p->unk2;
            D_801BC6BC[((s16 *)D_801BC6C0)[k * 2 + 1]].c = ~k * 0x1E;
            D_801BC6C4[((s16 *)D_801BC6C0)[p->unk2 * 2 + 1]] = 1;
        }
        func_801B7B74();
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_lasboss3/nonmatchings/text", func_801B7FF4);

void func_801BA6A8(void) {
    MgTask *p;
    s16 n;
    s16 d1;
    s16 d2;
    s16 d3;
    u16 a1;
    u16 b1;
    u16 a2;
    u16 b2;
    u16 a3;
    u16 b3;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        a1 = D_800F81B0 & 0xFFF;
        b1 = D_800F81E4 & 0xFFF;
        n = 0;
        if (a1 - b1 >= 0) {
            d1 = a1 - b1;
        } else {
            d1 = b1 - a1;
        }
        if (d1 > 0x800) {
            d1 = 0x1000 - d1;
        }
        if (d1 > 0x100) {
            n++;
        }
        a2 = D_800F81B0 & 0xFFF;
        b2 = D_800F8218 & 0xFFF;
        if (a2 - b2 >= 0) {
            d2 = a2 - b2;
        } else {
            d2 = b2 - a2;
        }
        if (d2 > 0x800) {
            d2 = 0x1000 - d2;
        }
        if (d2 > 0x100) {
            n++;
        }
        a3 = D_800F81E4 & 0xFFF;
        b3 = D_800F8218 & 0xFFF;
        if (a3 - b3 >= 0) {
            d3 = a3 - b3;
        } else {
            d3 = b3 - a3;
        }
        if (d3 > 0x800) {
            d3 = 0x1000 - d3;
        }
        if (d3 > 0x100) {
            n++;
        }
        if (n != 0) {
            func_801B23A8((s32)&D_801BB4A8, (s32)&D_801BBD4C, D_801BBD70);
            func_800BBEAC(&func_801B7FF4);
            p->unk0 = -1;
        }
    }
}

void func_801BA85C(arg0, arg1) {
    s16 i;

    D_801BC6F4[0].v = (s32)D_801D4708;
    D_801BC6F8 = (s32)D_801D4708 + 0x4000;
    func_800BBEAC(&func_801B240C);
    D_801BBD48 = (s32)D_801D4708 - 0x4000;
    D_801BBD6C = arg0;
    D_801BBD70 = arg1;
    func_800BBEAC(&func_801BA6A8);
    func_8003C21C(&D_801BBCD4, &D_801BBD4C);
    D_801BC700 = (s32)D_801BC708;
    D_801BBD60 = D_801BBD64 = D_801BBD68 = 0;
    D_801BC704 = (s32)D_801DC708;
    for (i = 0; i < 10; i++) {
        D_801BBED4[i] = D_80151909[i][0];
    }
    D_801BBD74 = 0;
    D_801BBD78 = 0;
    D_800FAFDC = 1;
}
