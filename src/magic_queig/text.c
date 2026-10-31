#include "common.h"
#include "magic_queig/decls.h"

void func_801B0054(void) {
    func_801B33B4();
}

void *func_801B0074(QgCtx *arg0, u8 *arg1, s32 *arg2) {
    u16 *e;
    s16 *a;
    s32 i;
    s32 n;
    s32 cnt;
    s32 k;
    s32 w;
    s32 x;
    s32 y;
    s32 z;
    s32 r;

    e = (u16 *)(arg2 + 1);
    n = arg0->unk24;
    cnt = *(u16 *)arg2;
    w = arg0->unk18;
    k = 0x02EBAE40 / arg0->unk14;
    for (i = 0; i < cnt; i++) {
        a = (s16 *)(arg1 + e[0]);
        x = a[0];
        y = a[1];
        z = a[2];
        a = (s16 *)(arg1 + e[1]);
        x += a[0];
        y += a[1];
        z += a[2];
        a = (s16 *)(arg1 + e[2]);
        x += a[0];
        y += a[1];
        z += a[2];
        x /= 3;
        y /= 3;
        z /= 3;
        D_801E5860[n].vy = y;
        y = y * y / k;
        D_801E5860[n].vx = x;
        D_801E5860[n].vz = z;
        D_801E5860[n].f6 = y;
        D_801E5860[n].f8 = D_801E5860[n].fA = D_801E5860[n].fC = D_801E5860[n].fE = 0;
        r = func_80042DA8();
        if (r & 0x800) {
            D_801E5860[n].f10 = (r & 7) * 16;
        } else {
            D_801E5860[n].f10 = -((r & 7) * 16);
        }
        D_801E5860[n].f12 = 0;
        if (r & 0x204080) {
            D_801E5860[n].f14 = (r << 1) & 0x70;
        } else {
            D_801E5860[n].f14 = -((r << 1) & 0x70);
        }
        D_801E5860[n].f16 = (y + w) * ((r & 1) + 3);
        n++;
        e += 8;
    }
    arg0->unk24 = n;
    return e;
}

void *func_801B034C(QgCtx *arg0, u8 *arg1, s32 *arg2) {
    u16 *e;
    s16 *a;
    s32 i;
    s32 n;
    s32 cnt;
    s32 k;
    s32 w;
    s32 x;
    s32 y;
    s32 z;
    s32 r;

    e = (u16 *)(arg2 + 1);
    n = arg0->unk24;
    cnt = *(u16 *)arg2;
    w = arg0->unk18;
    k = 0xA12BC4 / arg0->unk14;
    for (i = 0; i < cnt; i++) {
        a = (s16 *)(arg1 + e[0]);
        x = a[0];
        y = a[1];
        z = a[2];
        a = (s16 *)(arg1 + e[1]);
        x += a[0];
        y += a[1];
        z += a[2];
        a = (s16 *)(arg1 + e[2]);
        x += a[0];
        y += a[1];
        z += a[2];
        a = (s16 *)(arg1 + e[3]);
        x += a[0];
        y += a[1];
        z += a[2];
        x /= 4;
        y /= 4;
        z /= 4;
        D_801E5860[n].vy = y;
        y = y * y / k;
        D_801E5860[n].vx = x;
        D_801E5860[n].vz = z;
        D_801E5860[n].f6 = y;
        D_801E5860[n].f8 = D_801E5860[n].fA = D_801E5860[n].fC = D_801E5860[n].fE = 0;
        r = func_80042DA8();
        if (r & 0x800) {
            D_801E5860[n].f10 = (r & 7) * 16;
        } else {
            D_801E5860[n].f10 = -((r & 7) * 16);
        }
        D_801E5860[n].f12 = 0;
        if (r & 0x204080) {
            D_801E5860[n].f14 = (r << 1) & 0x70;
        } else {
            D_801E5860[n].f14 = -((r << 1) & 0x70);
        }
        D_801E5860[n].f16 = (y + w) * ((r & 1) + 3);
        n++;
        e += 10;
    }
    arg0->unk24 = n;
    return e;
}

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B0638);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B06B8);

s32 func_801B0DBC(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801CCC60[a];
        } else {
            r = D_801CCC60[0x800 - a];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801CCC60[a - 0x800];
        } else {
            r = -D_801CCC60[0x1000 - a];
        }
    }
    return r;
}

s32 func_801B0E60(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801CCC60[0x400 - a];
        } else {
            r = -D_801CCC60[a - 0x400];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801CCC60[0xC00 - a];
        } else {
            r = D_801CCC60[a - 0xC00];
        }
    }
    return r;
}

void func_801B0EFC(s16 *arg0, s16 *arg1, s32 *arg2) {
    s32 cx;
    s32 cy;
    s32 cz;
    s32 sx;
    s32 sy;
    s32 sz;
    s32 m0;
    s32 m1;
    s32 m2;
    s32 m3;
    s32 m4;
    s32 m5;
    s32 m6;
    s32 m7;
    s32 m8;

    cx = func_801B0E60(arg0[0]);
    cy = func_801B0E60(arg0[1]);
    cz = func_801B0E60(arg0[2]);
    sx = func_801B0DBC(arg0[0]);
    sy = func_801B0DBC(arg0[1]);
    sz = func_801B0DBC(arg0[2]);
    m0 = (((cz * cy) >> 12) * arg2[0]) >> 12;
    m3 = ((((sz * cx) >> 12) - (((cz * -sy >> 12) * sx) >> 12)) * arg2[0]) >> 12;
    m6 = ((((sz * sx) >> 12) + (((cz * -sy >> 12) * cx) >> 12)) * arg2[0]) >> 12;
    m1 = (((-sz * cy) >> 12) * arg2[1]) >> 12;
    m4 = ((((cz * cx) >> 12) + (((sz * -sy >> 12) * sx) >> 12)) * arg2[1]) >> 12;
    m7 = ((((cz * sx) >> 12) - (((sz * -sy >> 12) * cx) >> 12)) * arg2[1]) >> 12;
    m2 = (sy * arg2[2]) >> 12;
    m5 = (((-cy * sx) >> 12) * arg2[2]) >> 12;
    m8 = (((cy * cx) >> 12) * arg2[2]) >> 12;
    arg1[0] = m0;
    arg1[3] = m3;
    arg1[6] = m6;
    arg1[1] = m1;
    arg1[4] = m4;
    arg1[7] = m7;
    arg1[2] = m2;
    arg1[5] = m5;
    arg1[8] = m8;
}

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1100);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1898);

void func_801B1938(void) {
    MgSVec rot;
    u8 pad[8];
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 k;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    k = p->unk12 << 11;
    scale.vy = 0x1000 - p->unk2 * 0x155;
    scale.vz = scale.vx = k / 1450;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = &D_801CC8CC;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801E554C = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801E554C);
    if (p->unk2 >= 0xC) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk12 += p->unk14;
        p->unk2++;
    }
}

void func_801B1AE0(void) {
    MgTask *p;
    s32 t;
    s16 *ang;
    u16 *q;

    p = &D_80162978[D_8015169C];
    D_801CD468[0] = *(u8 *)&p->unk12;
    q = &D_801CD474;
    *q = p->unk14;
    ang = &p->unk14;
    D_801CD47C = *ang;
    func_800D4284(&p->unk4, -(*ang >> 4), q);
    func_8003B48C((MgMat *)q);
    func_8003B51C((MgMat *)q);
    t = p->unk2;
    if (t >= 4) {
        D_801CD46C = 0x2E808080 - (t - 4) * 0x202020;
    }
    D_801E554C = func_800D6260(&D_801CD468[-4], D_801517C0 + 0x70, 0xC, D_801E554C);
    if (D_80062D98 == 0) {
        p->unk6 += p->unk16;
        p->unk16 += p->unk18;
        if (++p->unk2 >= 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B1C38(QgB8 *src) {
    s32 i;

    for (i = 0; i < 0x61; i++) {
        D_801CB844[i] = src[i];
    }
}

void func_801B1C84(MgSVec *a, MgSVec *b, MgSVec *d) {
    s32 i;

    for (i = 0; i < 0x61; i++) {
        d[i].vx = b[i].vx - a[i].vx;
        d[i].vy = b[i].vy - a[i].vy;
        d[i].vz = b[i].vz - a[i].vz;
    }
}

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1CDC);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B2274);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B2818);

void func_801B29E0(void) {
    MgSVec rot;
    u8 pad[8];
    MgMat m;
    MgVec scale;
    MgMat *mp;
    MgTask *p;
    s32 t;
    s32 v;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkE + p->unk10;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    t = p->unk2;
    if (t < 7) {
        v = p->unk12 - p->unk18 * (7 - t);
    } else if (t < 9) {
        v = p->unk12;
    } else {
        v = p->unk12 - p->unk18 * (t - 9);
    }
    mp = &m;
    scale.vx = v;
    scale.vy = 0x1000;
    scale.vz = p->unk12;
    func_8003B35C(mp, &scale);
    func_8003A63C(&D_800FA63C, mp, mp);
    func_8003B48C(mp);
    func_8003B51C(mp);
    ((MgScratch *)0x1F800000)->unk0 = D_801CD494[p->unk14];
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801E554C = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801E554C);
    if (p->unk2 >= 0x10) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkE -= 0x40;
        p->unk2++;
    }
}

void func_801B2BBC(void) {
    MgTask *p;
    MgTask *q;
    MgTask *r;
    s32 t;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        t = p->unkC;
        if (t < 12) {
            if (t >= 0) {
                if (p->unk2 >= D_801CD4A4[t]) {
                    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B29E0)];
                    q->unkC = 0;
                    *(QgB8 *)&q->unk4 = *(QgB8 *)&p->unk4;
                    q->unkE = 0;
                    q->unk10 = D_801CD4BC[p->unkC];
                    q->unk12 = ((p->unk12 * D_801CD4D4[p->unkC] >> 12) << 12) / 2500;
                    q->unk14 = p->unkC & 3;
                    q->unk18 = q->unk12 / 7;
                    p->unkC++;
                }
            } else {
                p->unk0 = -1;
            }
        } else {
            p->unk0 = -1;
        }
        t = p->unk1C;
        if (t < 7) {
            if (t >= 0) {
                if (p->unk2 >= D_801CD4EC[t]) {
                    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B2818)];
                    q->unk4 = p->unk4 + D_801CD4FC[p->unk1C];
                    q->unk6 = 0;
                    q->unk8 = p->unk8 + D_801CD50C[p->unk1C];
                    p->unk1C++;
                }
            }
        }
        if (p->unk2 == 12) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1CDC)];
            *(QgB8 *)&q->unk4 = *(QgB8 *)&p->unk4;
            q->unk12 = 0;
            q->unk14 = p->unk12 / 12;
            q->unk16 = 0;
            q->unk18 = 0x400;
            func_801B1C84((MgSVec *)D_801CC2BC, (MgSVec *)&D_801CC5C4, (MgSVec *)D_801E5558);
            r = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1938)];
            *(QgB8 *)&r->unk4 = *(QgB8 *)&p->unk4;
            r->unk12 = q->unk14;
            r->unk14 = (u16)q->unk14 + (q->unk14 >> 1);
        }
        p->unk2++;
    }
}

void func_801B2F34(void) {
    MgTask *p;
    MgTask *q;
    s32 t;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        t = p->unkC;
        if (t < 8) {
            if (t >= 0) {
                if (p->unk2 >= D_801CD51C[t]) {
                    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B29E0)];
                    q->unkC = 0;
                    *(QgB8 *)&q->unk4 = *(QgB8 *)&p->unk4;
                    q->unkE = 0;
                    q->unk10 = D_801CD52C[p->unkC];
                    q->unk12 = ((p->unk12 * D_801CD53C[p->unkC] >> 12) << 12) / 2500;
                    q->unk14 = p->unkC & 3;
                    q->unk18 = q->unk12 / 7;
                    p->unkC++;
                }
            } else {
                p->unk0 = -1;
            }
        } else {
            p->unk0 = -1;
        }
        if (p->unk2 == 8) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B2274)];
            *(QgB8 *)&q->unk4 = *(QgB8 *)&p->unk4;
            q->unk12 = 0;
            q->unk14 = p->unk12 / 12;
            q->unk16 = 0;
            q->unk18 = 0x400;
            func_801B1C84((MgSVec *)D_801CC2BC, (MgSVec *)&D_801CC5C4, (MgSVec *)D_801E5558);
        }
        p->unk2++;
    }
}

void func_801B318C(void) {
    MgTask *p;
    MgTask *a;
    QgScratch *s;
    s32 i;
    s32 n;
    s32 k;
    s32 t;

    i = 0;
    n = 0;
    for (; i < 10; i++) {
        if (1 << i & D_801E5554) {
            n++;
            if (n == 1) {
                k = i;
            }
        }
    }
    a = D_80162978;
    D_80162978[D_8015169C].unk0 = -1;
    s = (QgScratch *)0x1F800000;
    s->unk0 = &D_801CB840;
    ((QgScratch *)0x1F800000)->unk4 = &D_801CC5C4;
    if (n == 1) {
        p = &a[func_800BBEAC((M2C_UNK *)func_801B2F34)];
        p->unkC = 0;
        func_800D3994(k, D_8015190F[k][0], &p->unk4);
        p->unk6 = 0;
        t = D_801518F6[k][0] + 0x200;
        p->unk12 = t;
        if ((s16)t >= 0x76D) {
            p->unk12 = 0x76C;
        }
        *(s32 *)0x1F800014 = 0xB;
        *(s32 *)0x1F800018 = 8;
        func_800D55F4(0x20, func_800D574C(D_801E5554), 0x58);
    } else {
        p = &a[func_800BBEAC((M2C_UNK *)func_801B2BBC)];
        p->unk1C = 0;
        p->unkC = 0;
        func_800D54EC(D_801E5554, &p->unk4);
        p->unk12 = 0x800;
        *(s32 *)0x1F800014 = 0xB;
        *(s32 *)0x1F800018 = 0x10;
        func_800D55F4(0x21, func_800D574C(D_801E5554), 0x58, 0x59);
    }
    func_801B0638(s);
    func_801B1C38(D_801CC2BC);
}

INCLUDE_RODATA("../asm/us/magic_queig/nonmatchings/text", D_801B0000);

void func_801B33B4(arg0) {
    D_801E5550 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B3430, 0, 0, 0);
    func_800BBEAC(&func_801B318C);
    D_801E5554 = arg0;
}
