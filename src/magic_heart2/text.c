#include "common.h"
#include "magic_heart2/decls.h"

void func_801B0054(void) {
    func_801B2014();
}

s32 func_801B0074(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0150(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02CC(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03A8(MgSVec *p, MgSVec *q, MgVec *n) {
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

void func_801B048C(void) {
    MgSVec rot1;
    MgSVec rot2;
    MgSVec ofs;
    MgMat m1;
    MgMat m2;
    MgVec scale;
    MgTask *p;
    s32 ang;

    p = &D_80162978[D_8015169C];
    ang = 0x400;
    if (p->unk2 < 9) {
        ang = p->unk2 << 7;
    }
    rot2.vx = 0;
    rot2.vz = 0;
    rot2.vy = D_801E7DD6;
    func_8003BF8C(&rot2, &m1);
    func_801B0150(-ang, &m2, &D_801CFB18);
    func_8003B16C(&m1, &m2);
    ofs.vx = 0;
    ofs.vy = p->unkA;
    ofs.vz = 0;
    func_8003B2CC(&m2, &ofs, &ofs);
    rot1.vx = 0;
    rot1.vy = 0;
    rot1.vz = 0x800;
    func_8003BF8C(&rot1, &m1);
    func_8003B16C(&m2, &m1);
    m1.t[0] = p->unk4 + ofs.vx;
    m1.t[1] = p->unk6 + ofs.vy;
    m1.t[2] = p->unk8 + ofs.vz;
    scale.vx = scale.vy = scale.vz = p->unk18;
    func_8003B35C(&m1, &scale);
    func_8003A63C(&D_800FA63C, &m1, &m1);
    func_8003B48C(&m1);
    func_8003B51C(&m1);
    ((MgScratch *)0x1F800000)->unk0 = &D_801CDDC0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801E7BA0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801E7BA0);
    if (p->unk2 >= 0x12) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 >= 8) {
            p->unk6 += p->unkE;
            p->unkE += p->unkE / 6;
        }
        p->unk2++;
    }
}

void func_801B06E0(void) {
    MgSVec rot1;
    MgSVec rot2;
    MgSVec pad1;
    MgMat m1;
    MgMat m2;
    MgVec pad2;
    MgTask *p;

    rot1.vx = 0x400;
    rot1.vy = 0;
    rot1.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot1, &m1);
    m1.t[0] = 0;
    m1.t[1] = p->unk6 - 0x28;
    m1.t[2] = 0x380;
    rot2.vx = 0;
    rot2.vy = p->unk14;
    rot2.vz = 0;
    func_8003BF8C(&rot2, &m2);
    func_8003B16C(&m2, &m1);
    func_8003B48C(&m1);
    func_8003B51C(&m1);
    ((MgScratch *)0x1F800000)->unk0 = &D_801CDDC0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801E7BA0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801E7BA0);
    if (p->unk2 >= 0x30) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 8) {
            p->unk6 += p->unkE;
            p->unkE -= p->unkE >> 5;
            if (p->unkE < 2) {
                p->unkE = 1;
            }
        } else if (p->unk2 < 0x28) {
            p->unk6 = (u32)(func_80039A74((p->unk2 - 8) << 7) * 3) >> 9;
            if (p->unk2 >= 0x16 && p->unk2 < 0x22) {
                p->unk14 -= 0xAA;
            }
        } else {
            p->unk6 += p->unkE;
            p->unkE += p->unkE >> 2;
        }
        p->unk2++;
    }
}

void func_801B08F8(void) {
    MgSVec rot1;
    MgSVec rot2;
    MgSVec rot3;
    MgMat m1;
    MgMat m2;
    MgVec v;
    MgTask *p;
    s32 n;

    rot1.vx = 0;
    p = &D_80162978[D_8015169C];
    rot1.vy = p->unk14;
    rot1.vz = 0x800;
    func_8003BF8C(&rot1, &m1);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk18;
    func_8003B35C(&m1, &v);
    func_8003A63C(&D_800FA63C, &m1, &m1);
    func_8003B48C(&m1);
    func_8003B51C(&m1);
    ((MgScratch *)0x1F800000)->unk0 = &D_801CDDC0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0xC) {
        ((MgScratch *)0x1F800000)->unk4 = 8;
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0xC) * 0x10;
    }
    D_801E7BA0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801E7BA0);
    if (p->unk2 >= 0x14) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0xA) {
            n = func_800D56A8(&p->unk4);
            if (n > 0x40) {
                func_800D4D4C(D_801E7BAC, 0x118);
            } else {
                func_800D4D4C(D_801E7BAC, 0x18);
            }
            func_800D55F4(0x20, n, 0x1D8);
        }
        p->unk4 += p->unkC;
        p->unk8 += p->unk10;
        p->unkC += p->unkC >> 4;
        p->unk10 += p->unk10 >> 4;
        p->unk2++;
    }
}

void func_801B0B30(void) {
    MgSVec unused;
    MgMat m;
    MgVec v;
    MgVec axis;
    MgTask *p;
    MgTask *q;
    s32 d;
    s32 ang;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 2) {
            q = &D_80162978[func_800BBEAC(&func_801B048C)];
            *(MgSVec *)&q->unk4 = D_801E7DD0;
            d = *(s16 *)D_80151A4E[D_801E7BB0] - D_801E7DD0.vy;
            if (d < 0) {
                d = -d;
            }
            q->unkE = -0x12C;
            q->unkA = d;
            q->unk18 = 0x2000;
            func_800D55F4(0x20, func_800D56A8(&D_801E7DD0), 0x1D5);
        }
        if (p->unk2 == 0x18) {
            q = &D_80162978[func_800BBEAC(&func_801B06E0)];
            q->unk6 = -0x10A;
            q->unkE = 0x21;
            q->unk14 = 0;
            func_800D55F4(0x20, 0x40, 0x1D6);
        }
        if (p->unk2 == 0x48) {
            func_800D3994(D_801E7BAC, D_8015190F[D_801E7BAC][0], &p->unk4);
            v.vx = p->unk4 - D_80158D00[0];
            v.vy = 0;
            v.vz = p->unk8 - D_80158D00[2];
            d = func_80039F5C(((s32 (*)(MgVec *, MgVec *))func_8003A08C)(&v, &v)) / 12;
            ang = func_801B0074(&D_801CFB08, &v, &axis);
            func_801B0150(ang, &m, &axis);
            func_8003AB84(&m, &D_801CFB08, &v);
            if (axis.vy < 0) {
                ang = -ang;
            }
            q = &D_80162978[func_800BBEAC(&func_801B08F8)];
            q->unk4 = D_80158D00[0];
            q->unk6 = p->unk6;
            q->unk8 = D_80158D00[2];
            q->unkC = (d * v.vx) >> 12;
            q->unkE = 0;
            q->unk10 = (d * v.vz) >> 12;
            q->unk14 = ang;
            q->unk18 = 0x2666;
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x1D7);
        }
        if (p->unk2 >= 0x5A) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0E9C(void) {
    MgSVec rot;
    MgMat m;

    func_800D3994(D_801E7BB0, D_80151919[D_801E7BB0][0], &D_801E7DD0);
    D_801E7DD0.vy -= 0xE0;
    rot.vy = D_801E7DD0.pad = *(u16 *)D_80151A46[D_801E7BB0];
    rot.vx = 0;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    func_8003AB84(&m, &D_801CFB08, &D_801E7DD8);
    func_8003AB84(&m, &D_801CFB18, &D_801E7DE8);
}

void func_801B0F9C(void) {
    MgMat lw;
    MgTask *p;
    s32 t;
    s32 k;
    s32 c;
    s16 i;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x14) {
        k = t * D_801E7BB4 / 20;
        goto copy;
    }
    t -= 0x14;
    if (t < 0x28) {
        k = D_801E7BB4;
        c = k;
        goto body;
    }
    t -= 0x28;
    if (t < 0xA) {
        k = -D_801E7BB4 * t / 10 + D_801E7BB4;
    } else {
        p->unk0 = -1;
        return;
    }
copy:
    c = k;
body:
    D_801CFB40.m[0][0] = D_801CFB4E.v = c;
    D_801CFB4A.v = -k;
    D_801CFB54.v = p->unk4;
    D_801CFB58.v = 0;
    D_801CFB5C.v = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801CFB40, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801E7BA0 = func_800D4D90(D_801CFB34, D_801517C0 + 0x70, 0xC, D_801E7BA0);
    D_801E7BA0 = func_800D4D90(D_801CFB28, D_801517C0 + 0x70, 0xC, D_801E7BA0);
    i = p->unk2 % 15;
    func_800D2538(D_801CFB60, D_801E7BC8[i]);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B11C4(void) {
    MgSVec pos;
    MgTask *p;
    s32 c;
    s32 t;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 2) {
        c = t << 6;
        goto store;
    }
    if ((t -= 2) < 0x1E) {
        c = 0x80;
store:
        D_801CFB72 = c;
        D_801CFB71 = c;
        D_801CFB70 = c;
    } else {
        p->unk0 = -1;
        return;
    }
    pos.vx = p->unk4;
    pos.vy = p->unk6 - (func_80039A74(p->unk2 << 6) * 0x3E8 >> 12);
    pos.vz = p->unk8;
    func_800D4368(&pos, p->unk14, 0);
    D_801E7BA0 = func_800D6260(D_801CFB68, D_801517C0 + 0x70, 0xC, D_801E7BA0);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
    }
}

void func_801B1318(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 *rp;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x14) {
        D_801CFB9A = 0x80;
        k = t * D_801E7BBC / 20;
        D_801CFB80.vx = D_801CFB88 = k;
        goto body;
    }
    t -= 0x14;
    if (t < 0x1E) {
        D_801CFB9A = 0x80;
        D_801CFB80.vx = D_801CFB88 = D_801E7BBC;
        goto body;
    }
    t -= 0x1E;
    if (t < 0xA) {
        D_801CFB80.vx = D_801CFB88 = D_801E7BBC;
        D_801CFB9A = -(t << 7) / 10 + 0x80;
    } else {
        p->unk0 = -1;
        return;
    }
body:
    rp = &D_801CFB7A;
    *rp = p->unk2 * 0x20;
    func_8003C21C((MgSVec *)(rp - 1), &m);
    func_8003B35C(&m, &D_801CFB80);
    m.t[0] = p->unk4;
    m.t[1] = 0;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801E7BA0 = func_800D29D4(D_801CFB90, D_801517C0 + 0x70, 0xC, D_801E7BA0);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1518(void) {
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t >= 0x1E) {
            *(MgB8 *)D_80151A4C[p->unk16] = *(MgB8 *)&p->unk4;
            D_801518EA[p->unk16][0] = p->unk14;
            func_800B8E48((u8)p->unk16);
            p->unk0 = -1;
        } else {
            D_801518EA[p->unk16][0] = p->unk14 + -p->unk14 * t / 30;
            D_80151A4C[p->unk16][0] += p->unkC;
            D_80151A4E[p->unk16][0] += p->unkE;
            D_80151A50[p->unk16][0] += p->unk10;
            p->unk2++;
        }
    }
}

void func_801B17A0(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 off;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0F9C)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)D_801E7DC8;
        }
        if ((u16)p->unk2 < 0x1EU) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B11C4)];
                q->unk4 = D_801E7DC8[0].vx + func_80042DA8() % (D_801E7BB8 * 2) - D_801E7BB8;
                q->unk6 = -func_80042DA8() % D_801E7BB8;
                q->unk8 = D_801E7DC8[0].vz + func_80042DA8() % (D_801E7BB8 * 2) - D_801E7BB8;
                q->unkC = (D_801E7DC8[0].vx - q->unk4) / 32;
                q->unkE = -q->unk6 / 32;
                q->unk10 = (D_801E7DC8[0].vz - q->unk8) / 32;
                i++;
                q->unk14 = D_801E7BC0 + func_80042DA8() % (D_801E7BC4 - D_801E7BC0);
            } while (i < 3);
        }
        if (p->unk2 == 2) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1318)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)D_801E7DC8;
            q->unk6 = 0;
        }
        if (p->unk2 == 0x14) {
            for (i = 0; i < 10; i++) {
                off = i * 0xB9C;
                if ((1 << i) & D_801E7BA8) {
                    if ((D_801517B4 >> i) & 1) {
                        q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1518)];
                        *(MgB8 *)&q->unk4 = *(MgB8 *)((u8 *)D_80151A4C + off);
                        q->unk14 = *(u16 *)((u8 *)D_801518EA + off);
                        q->unk16 = i;
                        q->unkC = (D_801E7DC8[0].vx - q->unk4) / 30;
                        q->unkE = (D_801E7DC8[0].vy - q->unk6) / 30;
                        q->unk10 = (D_801E7DC8[0].vz - q->unk8) / 30;
                    } else {
                        func_800D5774(i);
                    }
                }
            }
        }
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B1C60(void) {
    s32 i;
    s32 j;
    u16 *src;
    u16 c;

    func_800D54EC(D_801E7BA8, D_801E7DC8);
    src = D_801B20F6;
    for (i = 0; i < 15; i++) {
        c = *src++;
        D_801E7BC8[i][0] = 0;
        for (j = 0; j < 15; j++) {
            D_801E7BC8[j][(j + i) % 15 + 1] = c;
        }
    }
    func_800BBEAC(&func_801B17A0);
    func_800D55F4(0x20, func_800D574C(D_801E7BA8), 0x4F);
}

void func_801B1D54(void) {
    MgTask *p;
    s32 idx;
    s32 a;
    s32 v;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x5A) {
            idx = D_801E7BAC;
            a = D_801518F6[idx][0] + 0xE0;
            if (a >= 0x76D) {
                a = 0x76C;
            }
            v = (a << 12) / 560;
            D_801E7BB4 = v;
            D_801E7BB8 = a * 5000 / 1295;
            D_801E7BBC = v * 0x3000 / 9472;
            D_801E7BC0 = v * 0x500 / 9472;
            D_801E7BC4 = v * 0x1200 / 9472;
            ((void (*)(s32, s32))func_801B1C60)(idx, D_801E7BB0);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B1F18(void) {
    MgSVec pos;
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    p->unk0 = -1;
    func_800D3994(D_801E7BAC, D_8015190F[D_801E7BAC][0], &pos);
    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B0B30)];
    p->unk4 = pos;
    func_801B0E9C();
    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B1D54)];
    p->unk4 = pos;
}

INCLUDE_RODATA("../asm/us/magic_heart2/nonmatchings/text", D_801B0000);

void func_801B2014(mask, arg1) {
    s32 i;
    s32 n;

    D_801E7BA4 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B20E0, 0, 0, 0);
    D_801E7BA8 = mask;
    for (i = 0, n = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            n++;
            if (n == 1) {
                D_801E7BAC = i;
            }
        }
    }
    D_801E7BB0 = arg1;
    func_800BBEAC(&func_801B1F18);
}
