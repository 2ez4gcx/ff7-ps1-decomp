#include "common.h"
#include "magic_queir/decls.h"

void func_801B0074(void) {
    func_801B2DCC();
}

void *func_801B0094(QrCtx *arg0, u8 *arg1, s32 *arg2) {
    QrIdx *t;
    s16 *a;
    s32 i;
    s32 n;
    s32 cnt;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    s32 r;

    t = (QrIdx *)(arg2 + 1);
    cnt = *(u16 *)arg2;
    n = arg0->unk24;
    k = 0x24B90;
    for (i = 0; i < cnt; i++) {
        a = (s16 *)(arg1 + t->a);
        x = a[0];
        y = a[1];
        z = a[2];
        a = (s16 *)(arg1 + t->b);
        x += a[0];
        y += a[1];
        z += a[2];
        a = (s16 *)(arg1 + t->c);
        x += a[0];
        y += a[1];
        z += a[2];
        x /= 3;
        y /= 3;
        z /= 3;
        D_801DC4AC[n].vy = y;
        y = (x * x + z * z) / k;
        D_801DC4AC[n].vx = x;
        D_801DC4AC[n].vz = z;
        D_801DC4AC[n].f6 = y;
        D_801DC4AC[n].f8 = D_801DC4AC[n].fA = D_801DC4AC[n].fC = D_801DC4AC[n].fE = 0;
        r = func_80042DA8();
        if (r & 0x800) {
            D_801DC4AC[n].f10 = (r & 7) * 16;
        } else {
            D_801DC4AC[n].f10 = -((r & 7) * 16);
        }
        D_801DC4AC[n].f12 = 0;
        if (r & 0x204080) {
            D_801DC4AC[n].f14 = ((r >> 3) & 7) * 16;
        } else {
            D_801DC4AC[n].f14 = -(((r >> 3) & 7) * 16);
        }
        D_801DC4AC[n].f16 = (0x1C - y) * ((r & 1) + 3);
        n++;
        t++;
    }
    arg0->unk24 = n;
    return t;
}

void *func_801B033C(QrCtx *arg0, u8 *arg1, s32 *arg2) {
    QrIdx4 *t;
    s16 *a;
    s32 i;
    s32 n;
    s32 cnt;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    s32 r;

    t = (QrIdx4 *)(arg2 + 1);
    cnt = *(u16 *)arg2;
    n = arg0->unk24;
    k = 0x24B90;
    for (i = 0; i < cnt; i++) {
        a = (s16 *)(arg1 + t->a);
        x = a[0];
        y = a[1];
        z = a[2];
        a = (s16 *)(arg1 + t->b);
        x += a[0];
        y += a[1];
        z += a[2];
        a = (s16 *)(arg1 + t->c);
        x += a[0];
        y += a[1];
        z += a[2];
        a = (s16 *)(arg1 + t->d);
        x += a[0];
        y += a[1];
        z += a[2];
        x /= 4;
        y /= 4;
        z /= 4;
        D_801DC4AC[n].vy = y;
        y = (x * x + z * z) / k;
        D_801DC4AC[n].vx = x;
        D_801DC4AC[n].vz = z;
        D_801DC4AC[n].f6 = y;
        D_801DC4AC[n].f8 = D_801DC4AC[n].fA = D_801DC4AC[n].fC = D_801DC4AC[n].fE = 0;
        r = func_80042DA8();
        if (r & 0x800) {
            D_801DC4AC[n].f10 = (r & 7) * 16;
        } else {
            D_801DC4AC[n].f10 = -((r & 7) * 16);
        }
        D_801DC4AC[n].f12 = 0;
        if (r & 0x204080) {
            D_801DC4AC[n].f14 = ((r >> 3) & 7) * 16;
        } else {
            D_801DC4AC[n].f14 = -(((r >> 3) & 7) * 16);
        }
        D_801DC4AC[n].f16 = (0x1C - y) * ((r & 1) + 3);
        n++;
        t++;
    }
    arg0->unk24 = n;
    return t;
}

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B05EC);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B0668);

s32 func_801B0D8C(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801C3C6C[a];
        } else {
            r = D_801C3C6C[0x800 - a];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801C3C6C[a - 0x800];
        } else {
            r = -D_801C3C6C[0x1000 - a];
        }
    }
    return r;
}

s32 func_801B0E30(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801C3C6C[0x400 - a];
        } else {
            r = -D_801C3C6C[a - 0x400];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801C3C6C[0xC00 - a];
        } else {
            r = D_801C3C6C[a - 0xC00];
        }
    }
    return r;
}

s16 *func_801B0ECC(s16 *arg0, s16 *arg1) {
    s32 c0;
    s32 c1;
    s32 c2;
    s32 s0;
    s32 s1;
    s32 s2;
    s32 cb;
    s32 w;

    c0 = func_801B0E30(arg0[0]);
    c1 = func_801B0E30(arg0[1]);
    c2 = func_801B0E30(arg0[2]);
    s0 = func_801B0D8C(arg0[0]);
    s1 = func_801B0D8C(arg0[1]);
    s2 = func_801B0D8C(arg0[2]);
    arg1[2] = s1;
    arg1[0] = (c2 * c1) >> 12;
    arg1[3] = ((s2 * c0) >> 12) - ((((c2 * -s1) >> 12) * s0) >> 12);
    arg1[6] = ((s2 * s0) >> 12) + ((((c2 * -s1) >> 12) * c0) >> 12);
    arg1[1] = (-s2 * c1) >> 12;
    w = (c2 * c0) >> 12;
    cb = (s2 * -s1) >> 12;
    arg1[4] = w + ((cb * s0) >> 12);
    arg1[7] = ((c2 * s0) >> 12) - ((cb * c0) >> 12);
    arg1[5] = (-c1 * s0) >> 12;
    arg1[8] = (c1 * c0) >> 12;
    return arg1;
}

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B104C);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B17F4);

void func_801B1894(void) {
    MgTask *p;
    s32 t;
    s16 *ang;
    u16 *q;

    p = &D_80162978[D_8015169C];
    D_801C4474[0] = *(u8 *)&p->unk12;
    q = &D_801C4480;
    *q = p->unk14;
    ang = &p->unk14;
    D_801C4488 = *ang;
    func_800D4284(&p->unk4, -(*ang >> 4), q);
    func_8003B48C((MgMat *)q);
    func_8003B51C((MgMat *)q);
    t = p->unk2;
    if (t >= 4) {
        D_801C4478 = 0x2E808080 - (t - 4) * 0x202020;
    }
    D_801DC4A0 = func_800D6260(&D_801C4474[-4], D_801517C0 + 0x70, 0xC, D_801DC4A0);
    if (D_80062D98 == 0) {
        p->unk6 += p->unk16;
        p->unk16 += p->unk18;
        if (++p->unk2 >= 8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B19EC);

void func_801B1F00(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    MgMat *q;
    s32 t;
    s32 i;

    rot.vx = rot.vy = rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    i = (p->unk12 << 12) / 1900;
    i = i >= 0 ? (i > 0x1000 ? 0x1000 : i) : 0;
    scale.vx = scale.vy = scale.vz = i;
    func_8003B35C(&m, &scale);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 6) {
            p->unk12 += p->unk14;
        } else if (t >= 0x12) {
            p->unk12 -= p->unk14;
        }
    }
    q = &m;
    func_8003A63C(&D_800FA63C, q, q);
    func_8003B48C(q);
    func_8003B51C(q);
    ((MgScratch *)0x1F800000)->unk0 = D_801C3210;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801DC4A0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DC4A0);
    if (p->unk2 >= 0x18) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        if (p->unk2 == 0x12) {
            for (i = 0; i < 10; i++) {
                if ((1 << i) & D_801DC4A8) {
                    func_800D5774(i);
                }
            }
        }
        p->unk2++;
    }
}

void func_801B2144(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgSVec a;
    MgSVec b;
    MgSVec c;
    MgSVec d;
    s32 ext;
    s32 flag;
    MgTask *p;
    u8 *q;
    MgTag *ot;
    s32 r;
    s32 k;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    k = 0x1000;
    if (p->unk2 > 0) {
        k = 0x1000 - ((p->unk2 - 1) << 11);
    }
    scale.vz = scale.vy = scale.vx = k;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    a.vx = -0xA00;
    a.vy = 0;
    a.vz = 0xA00;
    b.vx = 0xA00;
    b.vy = 0;
    b.vz = 0xA00;
    c.vx = -0xA00;
    c.vy = 0;
    c.vz = -0xA00;
    d.vx = 0xA00;
    d.vy = 0;
    d.vz = -0xA00;
    q = (u8 *)D_801DC4A0;
    r = func_8003BD7C(&a, &b, &c, &d, q + 8, q + 0x10, q + 0x18, q + 0x20, &ext, &flag);
    ((MgTag *)q)->len = 9;
    q[7] = 0x2C;
    *(s16 *)(q + 0x16) = 0x2D;
    *(s16 *)(q + 0xE) = 0x7888;
    *(u16 *)(q + 0xC) = 0x8000;
    *(u16 *)(q + 0x14) = 0x8080;
    *(u16 *)(q + 0x1C) = 0xFF00;
    *(s32 *)(q + 4) = 0x2E808080;
    *(u16 *)(q + 0x24) = 0xFF80;
    ot = (MgTag *)(D_801517C0 + ((r >> 2) << 2)) + 0x1C;
    ((MgTag *)q)->addr = ot->addr;
    ot->addr = (u32)q;
    D_801DC4A0 = (s32)(q + 0x28);
    if (p->unk2 >= 3) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2 += 1;
    }
}

void func_801B237C(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgScratch *sc;
    MgTask *p;
    u8 *tbl;
    s32 k;
    s32 c;
    s32 d;
    s32 f;
    s16 a;
    s16 b;
    s16 w;

    p = &D_80162978[D_8015169C];
    rot.vx = 0;
    rot.vy = (u16)p->unkE + (u16)p->unk10;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    k = (p->unk12 << 12) / 2500;
    d = k;
    scale.vx = d;
    scale.vy = p->unk16;
    scale.vz = k;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    do {
        func_8003B48C(&m);
        func_8003B51C(&m);
    } while (0);
    tbl = D_801C2EE8;
    f = p->unk14;
    if (f != 0) {
        tbl = D_801C307C;
    }
    sc = (MgScratch *)0x1F800000;
    sc->unk0 = tbl;
    sc->unk4 = 8;
    sc->unk8 = 0;
    sc->unkA = (c = 0x80);
    sc->unkC = 0x20;
    sc->unkE = 0;
    a = p->unk2;
    b = p->unkC;
    if (a > b) {
        d = (a - b) * 0x10;
        if (d >= 0x81) {
            d = 0x80;
        }
        sc->unkA = c - d;
    }
    D_801DC4A0 = func_800D29D4(sc, D_801517C0 + 0x70, 0xC, D_801DC4A0);
    if (p->unk2 >= (p->unkC + 8)) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkE = (u16)p->unkE - 0x20;
        w = (u16)p->unk16 + (u16)p->unk18;
        p->unk16 = w;
        if (w >= 0x1001) {
            p->unk16 = 0x1000;
        }
        p->unk2 += 1;
    }
}

void func_801B2590(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 u;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        switch (p->unkC) {
        case 0:
            if (p->unk2 > 0) {
                p->unkC++;
                q = &D_80162978[func_800BBEAC((void *)func_801B237C)];
                q->unkC = 0x17;
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                q->unkE = 0;
                q->unk10 = 0x100;
                t = p->unk12;
                q->unk18 = 0xBA;
                q->unk14 = 0;
                q->unk16 = 0;
                q->unk1A = 1;
                t <<= 1;
                q->unk12 = t;
            }
            break;
        case 1:
            if (p->unk2 >= 5) {
                p->unkC++;
                q = &D_80162978[func_800BBEAC((void *)func_801B237C)];
                q->unkC = 0x19;
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                q->unkE = 0;
                q->unk10 = 0x900;
                t = p->unk12;
                q->unk18 = 0xC3;
                q->unk14 = 0;
                q->unk16 = 0;
                q->unk1A = 1;
                t <<= 1;
                q->unk12 = t;
            }
            break;
        case 2:
            if (p->unk2 >= 0xA) {
                p->unkC++;
                q = &D_80162978[func_800BBEAC((void *)func_801B237C)];
                q->unkC = 0x1A;
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                q->unkE = 0;
                q->unk10 = 0x100;
                u = (u16)p->unk12;
                q->unk18 = 0x111;
                q->unk14 = 0;
                q->unk16 = 0;
                q->unk1A = 1;
                q->unk12 = u;
            }
            break;
        case 3:
            if (p->unk2 >= 0xE) {
                p->unkC++;
                q = &D_80162978[func_800BBEAC((void *)func_801B237C)];
                q->unkC = 0x1B;
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                q->unkE = 0;
                q->unk10 = 0x900;
                u = (u16)p->unk12;
                q->unk18 = 0x13B;
                q->unk14 = 0;
                q->unk16 = 0;
                q->unk1A = 1;
                q->unk12 = u;
            }
            break;
        case 4:
            if (p->unk2 >= 0x14) {
                p->unkC++;
                q = &D_80162978[func_800BBEAC((void *)func_801B2144)];
                q->unk4 = p->unk4 + p->unk12;
                q->unk6 = 0;
                q->unk8 = p->unk8 + p->unk12 - ((s16)p->unk12 >> 2);
            }
            break;
        case 5:
            if (p->unk2 >= 0x1A) {
                p->unkC++;
                q = &D_80162978[func_800BBEAC((void *)func_801B2144)];
                q->unk4 = p->unk4 - p->unk12 - ((s16)p->unk12 >> 2);
                q->unk6 = 0;
                q->unk8 = p->unk8 + p->unk12 - ((s16)p->unk12 >> 3);
            }
            break;
        case 6:
            if (p->unk2 >= 0x1E) {
                p->unkC++;
                q = &D_80162978[func_800BBEAC((void *)func_801B2144)];
                q->unk4 = p->unk4 + ((s16)p->unk12 >> 1);
                q->unk6 = 0;
                q->unk8 = p->unk8 - p->unk12 - ((s16)p->unk12 >> 3);
            }
            break;
        case 7:
            p->unkC++;
            q = &D_80162978[func_800BBEAC((void *)func_801B19EC)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unk12 = 0;
            q->unk14 = (p->unk12 + 0x380) / 24;
        default:
            p->unk0 = -1;
            break;
        }
        p->unk2++;
    }
}

void func_801B2A04(void) {
    MgTask *p;
    MgTask *q;
    u16 u;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        switch (p->unkC) {
        case 0:
            if (p->unk2 > 0) {
                p->unkC++;
                q = &D_80162978[func_800BBEAC((void *)func_801B237C)];
                q->unkC = 0x17;
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                q->unkE = 0;
                q->unk10 = 0x100;
                u = p->unk12;
                q->unk14 = 0;
                q->unk16 = 0;
                q->unk18 = 0xBA;
                q->unk1A = 0;
                q->unk12 = u;
            }
            break;
        case 1:
            if (p->unk2 >= 5) {
                p->unkC++;
                q = &D_80162978[func_800BBEAC((void *)func_801B237C)];
                q->unkC = 0x1A;
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                q->unkE = 0;
                q->unk10 = 0x900;
                u = p->unk12;
                q->unk14 = 0;
                q->unk16 = 0;
                q->unk18 = 0xC3;
                q->unk1A = 0;
                q->unk12 = u;
            }
            break;
        case 2:
            if (p->unk2 >= 0x12) {
                p->unkC++;
                q = &D_80162978[func_800BBEAC((void *)func_801B1F00)];
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                q->unk12 = 0;
                q->unk14 = (s16)p->unk12 / 6;
            }
            break;
        default:
            p->unk0 = -1;
            break;
        }
        p->unk2 += 1;
    }
}

void func_801B2C08(void) {
    MgTask *b;
    MgTask *q;
    s32 i;
    s32 n;
    s32 sel;
    s16 t;

    i = 0;
    n = 0;
    do {
        if ((1 << i) & D_801DC4A8) {
            n++;
            if (n == 1) {
                sel = i;
            }
        }
        i++;
    } while (i < 10);
    D_80162978[D_8015169C].unk0 = -1;
    b = D_80162978;
    if (n == 1) {
        q = &b[func_800BBEAC((void *)func_801B2A04)];
        q->unkC = 0;
        func_800D3994(sel, D_8015190F[sel][0], &q->unk4);
        q->unk6 = 0;
        t = D_801518F6[sel][0] + 0xE0;
        q->unk12 = t;
        if (t >= 0x76D) {
            q->unk12 = 0x76C;
        }
        func_800D55F4(0x20, func_800D574C(D_801DC4A8), 0x40);
    } else {
        q = &b[func_800BBEAC((void *)func_801B2590)];
        q->unkC = 0;
        func_800D54EC(D_801DC4A8, &q->unk4);
        q->unk12 = 0x460;
        ((MgScratch *)0x1F800000)->unk0 = D_801C3210;
        func_801B05EC(0x1F800000);
        func_800D55F4(0x20, func_800D574C(D_801DC4A8), 0xD4);
    }
}

INCLUDE_RODATA("../asm/us/magic_queir/nonmatchings/text", D_801B0020);

void func_801B2DCC(arg0) {
    D_801DC4A4 = &D_80162978[func_800BBEAC(&D_801B0020)];
    func_800D2980(&D_801B2E48, 0, 0, 0);
    func_800BBEAC(&func_801B2C08);
    D_801DC4A8 = arg0;
}
