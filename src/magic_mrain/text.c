#include "common.h"
#include "magic_mrain/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B289C();
    return &D_801D4384;
}

s32 func_801B007C(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0158(s32 ang, MgMat *m, MgVec *v) {
    s32 s;
    s32 c;
    s32 x;
    s32 y;
    s32 z;
    s32 xx;
    s32 yy;
    s32 zz;
    s32 omc;

    s = func_80039A74(ang);
    c = func_80039B40(ang);
    x = v->vx;
    y = v->vy;
    z = v->vz;
    omc = 0x1000 - c;
    xx = (x * x) >> 12;
    yy = (y * y) >> 12;
    zz = (z * z) >> 12;
    m->m[0][0] = xx + (((0x1000 - xx) * c) >> 12);
    m->m[0][1] = ((((x * y) >> 12) * omc) >> 12) - ((z * s) >> 12);
    m->m[0][2] = ((((x * z) >> 12) * omc) >> 12) + ((y * s) >> 12);
    m->m[1][0] = ((((x * y) >> 12) * omc) >> 12) + ((z * s) >> 12);
    m->m[1][1] = yy + (((0x1000 - yy) * c) >> 12);
    m->m[1][2] = ((((y * z) >> 12) * omc) >> 12) - ((x * s) >> 12);
    m->m[2][0] = ((((x * z) >> 12) * omc) >> 12) - ((y * s) >> 12);
    m->m[2][1] = ((((y * z) >> 12) * omc) >> 12) + ((x * s) >> 12);
    m->m[2][2] = zz + (((0x1000 - zz) * c) >> 12);
}

void func_801B02D4(MgSVec *p, MgSVec *o, MgVec *n) {
    MgVec d;
    s32 dot;

    d.vx = p->vx - o->vx;
    d.vy = p->vy - o->vy;
    d.vz = p->vz - o->vz;
    dot = (n->vx * d.vx + n->vy * d.vy + n->vz * d.vz) >> 12;
    p->vx -= (dot * n->vx) >> 12;
    p->vy -= (dot * n->vy) >> 12;
    p->vz -= (dot * n->vz) >> 12;
}

s16 func_801B03B0(MgSVec *p, MgSVec *q, MgVec *n) {
    MgVec up;
    s32 a;
    s32 b;

    up.vx = 0;
    up.vy = -0x1000;
    up.vz = 0;
    a = p->vx * n->vx + p->vy * n->vy + p->vz * n->vz;
    b = q->vx * n->vx + q->vy * n->vy + q->vz * n->vz;
    return (b - a) / ((n->vx * up.vx + n->vy * up.vy + n->vz * up.vz) >> 12);
}

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B0494);

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B083C);

void func_801B08AC(void) {
    s32 otz;
    s32 flag;
    MgTask *p;
    u8 *pkt;
    s32 n;

    pkt = D_801ED820;
    p = &D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    n = func_8003BBDC(&p->unk4, pkt + 8, &otz, &flag);
    if (!(flag & 0x60000)) {
        func_80046974(pkt);
        pkt[4] = 0xFF;
        pkt[5] = func_80042DA8();
        pkt[6] = 0;
        func_80046794((n >> 2) * 4 + (D_801517C0 + 0x70), (s32)pkt);
        D_801ED820 = pkt + 0xC;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 3) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
        }
        if (++p->unk2 >= 5) {
            p->unk0 = -1;
        }
    }
}

void func_801B0A08(void) {
    MgSVec rot;
    s32 flag;
    MgTask *p;
    MgTask *q;
    u8 *pk;
    s32 i;
    s32 r;
    s32 a;
    s16 v;
    MgSVec *sv;
    MgVec *vv;

    sv = (MgSVec *)0x1F800060;
    vv = (MgVec *)0x1F800068;
    p = &D_80162978[D_8015169C];
    D_801D57B8.vx = D_801D57B8.vy = D_801D57B8.vz = p->unk1C;
    v = (p->unk1C << 12) / 2560;
    D_801D57C8.m[0][0] = D_801D57D0.v = D_801D57D8.v = v;
    rot.vx = -p->unkC;
    rot.vy = -p->unkE;
    rot.vz = -p->unk10;
    func_800D44E8(&rot, (MgMat *)0x1F800000);
    ((MgMat *)0x1F800000)->t[0] = p->unk4;
    ((MgMat *)0x1F800000)->t[1] = p->unk6;
    ((MgMat *)0x1F800000)->t[2] = p->unk8;
    func_8003B35C((MgMat *)0x1F800000, &D_801D57B8);
    func_8003A63C(&D_800FA63C, (MgMat *)0x1F800000, (MgMat *)0x1F800020);
    func_8003B48C((MgMat *)0x1F800020);
    func_8003B51C((MgMat *)0x1F800020);
    D_801ED820 = func_800D29D4(D_801D57A0, D_801517C0 + 0x70, 0xC, D_801ED820);
    func_8003C21C(D_801D57B0, (MgMat *)0x1F800040);
    func_8003A63C((MgMat *)0x1F800020, (MgMat *)0x1F800040, (MgMat *)0x1F800040);
    func_8003B48C((MgMat *)0x1F800040);
    pk = func_800D29D4(D_801D5790, D_801517C0 + 0x70, 0xC, D_801ED820);
    D_801D57C8.t[0] = p->unk4;
    D_801ED820 = pk;
    D_801D57C8.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801D57C8, (MgMat *)0x1F800020);
    func_8003B48C((MgMat *)0x1F800020);
    func_8003B51C((MgMat *)0x1F800020);
    D_801ED820 = func_800D29D4(D_801D57E8, D_801517C0 + 0x4078, 1, D_801ED820);
    if (D_80062D98 == 0) {
        func_8003B48C((MgMat *)0x1F800000);
        func_8003B51C((MgMat *)0x1F800000);
        i = 0;
        do {
            r = func_80042DA8();
            a = (i << 12) + r % 4096;
            sv->vx = (u32)(func_80039A74(a) * 0x7D) >> 9;
            sv->vy = func_80039B40(a) * 0x3E8 >> 12;
            sv->vz = func_80042DA8() % 1000;
            func_8003BC6C(sv, vv, &flag);
            i++;
            q = &D_80162978[func_800BBEAC(&func_801B08AC)];
            q->unk4 = *(u16 *)&vv->vx;
            q->unk6 = *(u16 *)&vv->vy;
            q->unk8 = *(u16 *)&vv->vz;
            sv->vz = 0;
            func_8003ACE4(sv, vv);
            q->unkC = -vv->vx / 3;
            q->unkE = -vv->vy / 3;
            q->unk10 = -vv->vz / 3;
        } while (i <= 0);
        D_801D57A8[0] ^= 0x80;
        D_801D57B0[0] += 0x80;
        D_801D57B0[1] += 0x100;
        D_801D57B0[2] += 0x180;
        p->unk2++;
        if (p->unk2 >= 6) {
            p->unk0 = -1;
        }
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
    }
}

void func_801B0EA8(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    frame = &D_801D5800;
    *frame = p->unk2;
    func_800D4368(&p->unk4, 0x2500, 0);
    D_801ED820 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801ED820);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D2A2C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0F6C(void) {
    MgTask *p;
    MrPart *base;
    s32 o;
    MrPart *e;
    s32 i;
    s32 j;
    s32 r;
    s32 s2;
    s32 s1;
    s16 v;

    i = 0;
    p = &D_80162978[D_8015169C];
    base = D_801ED838[p->unk1C].e;
    do {
        e = &base[i];
        if (e->flag != 0) {
            D_801D580C.v = e->timer;
            v = e->w;
            func_800D4368(&e->x, v, -(v >> 3));
            D_801ED820 = func_800D4D90((u8 *)&D_801D580C - 8, D_801517C0 + 0x70, 0xC, D_801ED820);
            if (D_80062D98 == 0) {
                if (e->timer >= 7) {
                    e->flag = 0;
                }
                e->timer++;
            }
        }
        i++;
    } while (i < 0x40);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x10) {
            p->unk0 = -1;
        }
        j = 0;
        if (p->unk2 < 6) {
            s1 = p->unk18;
            i = 0;
            s2 = s1 * 2;
            do {
                for (j = 0; j < 0x40; j++) {
                    if (base[j].flag == 0) {
                        break;
                    }
                }
                if (j >= 0x40) {
                    break;
                }
                o = j * 0x18;
                e = (MrPart *)(o + (s32)base);
                e->flag = 1;
                e->timer = 0;
                e->x = p->unk4 + (func_80042DA8() % s2 - s1);
                e->y = p->unk6 - func_80042DA8() % s1;
                e->z = p->unk8 + (func_80042DA8() % s2 - s1);
                r = func_80042DA8();
                e->w = r % 0x800 + 0x2000;
                i++;
                j = 0;
            } while (i < 2);
        }
        p->unk2++;
    }
}

void func_801B1238(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk18;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801D2E64;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 8) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 8) * 0x10;
    }
    D_801ED820 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801ED820);
    if (p->unk2 >= 0x10) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk18 += p->unk1A;
        p->unk1A -= p->unk1A >> 2;
        p->unk2++;
        p->unkE -= p->unkE / 5;
    }
}

void func_801B1420(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk18;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801D33C0;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 8) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 8) * 0x10;
    }
    D_801ED820 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801ED820);
    if (p->unk2 >= 0x10) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk18 += p->unk1A;
        p->unk1A -= p->unk1A >> 2;
        p->unk2++;
        p->unkE -= p->unkE / 5;
    }
}

void func_801B1608(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 t;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk18;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801D3614;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t >= 4) {
        ((MgScratch *)0x1F800000)->unkA = (t - 4) << 9;
    }
    func_8003B69C(0, 0, 0);
    D_801ED820 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801ED820);
    if (p->unk2 >= 0xC) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk18 += p->unk1A;
        p->unk2++;
    }
}

void func_801B179C(void) {
    u8 pad[0x38];
    MgTask *p;
    MgScratch *s;
    s32 t;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk18, -0x240);
    s = (MgScratch *)0x1F800000;
    s->unk0 = D_801D38A8;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t < 6) {
        ((MgScratch *)0x1F800000)->unkA = 0x1000 - t * 0x2AA;
    } else if (t >= 0x11) {
        ((MgScratch *)0x1F800000)->unkA = (t - 0x11) * 0x199;
    } else {
        ((MgScratch *)0x1F800000)->unkA = 0;
    }
    func_8003B69C(0, 0, 0);
    D_801ED820 = func_800D29D4(s, D_801517C0 + 0x70, 0xC, D_801ED820);
    if (p->unk2 >= 0x1B) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 8) {
            p->unk18 -= p->unk1A;
        }
        p->unk2++;
    }
}

void func_801B1940(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 c;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vz = p->unk10;
    scale.vy = p->unk14;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801D2AF0;
    ((MgScratch *)0x1F800000)->unk4 = 0x28;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c = 0x80;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0xC) {
        ((MgScratch *)0x1F800000)->unkA = c - (p->unk2 - 0xC) * 0x10;
    }
    D_801ED820 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801ED820);
    if (p->unk2 >= 0x14) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unkE -= p->unkE >> 6;
        p->unk10 += p->unk12;
        if (p->unk2 < 9) {
            p->unk14 += p->unk16;
        }
        p->unk2++;
    }
}

void func_801B1B24(void) {
    MgTask *p;
    s16 t;
    s32 w;

    p = &D_80162978[D_8015169C];
    w = p->unk2 << 5;
    D_801D5814[0] = w;
    t = p->unk18;
    func_800D4368(&p->unk4, t, -(t >> 3));
    D_801ED820 = func_800D6260(&D_801D5814[-4], D_801517C0 + 0x70, 0xC, D_801ED820);
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk6 += p->unk1A;
        p->unk1A -= p->unk1A >> 4;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B1C14);

void func_801B2048(void) {
    MgTask *p;
    MgTask *q;
    u16 *wv;
    s32 k;
    s32 w;
    s32 t;
    s16 h;
    s32 i;
    s32 n;
    s32 c;
    s32 x;
    s32 y;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 1) {
            i = (s16)D_801ED836 + 0x120;
            q = &D_80162978[func_800BBEAC((void *)func_801B1940)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&D_801ED830;
            h = (i << 12) / 750;
            q->unk10 = h;
            q->unk12 = h / 9;
            q->unk6 = 0;
            q->unkC = 0;
            q->unk14 = 0;
            q->unkE = -0x120;
            q->unk16 = (s16)q->unk10 / 9 * 2;
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x21B);
        }
        if (p->unk2 == 0x19) {
            func_800D3994(D_801ED82C, D_8015190F[D_801ED82C][0], &D_801ED830);
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC((void *)func_801B1B24)];
                *(MgB8 *)&q->unk4 = *(MgB8 *)&D_801ED830;
                k = 0xC8;
                q->unk4 = (u16)q->unk4 - k + func_80042DA8() % 400;
                q->unk8 = (u16)q->unk8 - k + func_80042DA8() % 400;
                D_801ED830.vy = (u16)D_801ED830.vy + (func_80042DA8() % 60 + (i * 4 + 0x96));
                q->unk18 = 0x2000 - i * 0x200;
                x = func_80042DA8();
                y = i + 0x50;
                q->unk1A = x % 30 + y;
                i++;
            } while (i < 8);
            func_800D55F4(0x29, func_800D56A8(&p->unk4), 0x30);
        }
        if (p->unk2 == 0x1C) {
            i = (s16)D_801ED836 + 0x240;
            q = &D_80162978[func_800BBEAC((void *)func_801B179C)];
            func_800D3994(D_801ED82C, D_8015190F[D_801ED82C][0], &q->unk4);
            n = i * 8;
            q->unk18 = (i << 15) / 1000;
            q->unk1A = ((n - i) << 12) / 8000;
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x188);
        }
        if (p->unk2 == 0x28) {
            func_800D3994(D_801ED82C, D_8015190F[D_801ED82C][0], &D_801ED830);
            i = 0;
            while (1) {
                n = D_801517F0[i];
                if (n == 0xFF) {
                    break;
                }
                q = &D_80162978[func_800BBEAC((void *)func_801B1C14)];
                func_800D3994(n, D_8015190F[n][0], &q->unk4);
                w = *(s16 *)D_801518F6[n] + 0x120;
                if (w >= 0x76D) {
                    w = 0x76C;
                }
                k = w * 2;
                q->unk4 = (u16)q->unk4 + (func_80042DA8() % k - w);
                q->unk6 = 0;
                q->unk8 = (u16)q->unk8 + (func_80042DA8() % k - w);
                q->unkA = func_80042DA8() % 9 + (i >> 1) + 1;
                q->unkC = i;
                q->unkE = n;
                q->unk18 = func_80042DA8() % 768 + 0x500;
                q->unk1C = 0;
                i++;
                if (i >= 8) {
                    break;
                }
            }
        }
        if (p->unk2 < 0x10) {
            D_800F5B70[0] = 0x54;
            D_800F5B71[0] = 0x1C;
            D_800F5B72[0] = 4;
            c = p->unk2 * 9 << 4;
        } else if (p->unk2 >= 0x43) {
            c = 0x900 - (p->unk2 - 0x43) * 0x120;
        } else {
            c = 0x900;
        }
        t = p->unk2;
        if (t >= 0x32 && (s16)(t % 3) == 0) {
            i = D_801517F0[p->unk1C];
            if (i != 0xFF) {
                wv = func_800D4FA8(0xA);
                wv[0] = i;
                wv[8] = p->unk1C;
                p->unk1C++;
            }
        }
        if (p->unk2 >= 0x4B) {
            c = 0;
            p->unk0 = -1;
        }
        D_800F5B74[0] = c;
        p->unk2++;
    }
}

void func_801B27A4(void) {
    u8 pad[8];

    D_80162978[D_8015169C].unk0 = -1;
    func_800D3994(D_801ED82C, D_8015190F[D_801ED82C][0], &D_801ED830);
    D_801ED836 = D_801518F6[D_801ED82C][0];
    D_80162994[func_800BBEAC(&func_801B2048)].unk0 = 0;
    ((MgScratch *)0x1F800000)->unk0 = D_801D2AF0;
    func_801B083C((void *)0x1F800000);
}

INCLUDE_RODATA("../asm/us/magic_mrain/nonmatchings/text", D_801B0000);

void func_801B289C(arg0, arg1) {
    D_801ED824 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B2928, 0, 0, 0);
    func_800BBEAC(&func_801B27A4);
    D_801ED828 = arg0;
    D_801ED82C = arg1;
}
