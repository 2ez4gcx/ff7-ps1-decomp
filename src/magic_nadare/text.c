#include "common.h"
#include "magic_nadare/decls.h"

void func_801B0000(void) {
    func_801B1FDC();
}

INCLUDE_ASM("../asm/us/magic_nadare/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_nadare/nonmatchings/text", func_801B0A48);

void func_801B1158(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801ED378 = D_801D5378 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B11C4(void) {
    s16 i;
    s16 j;
    s16 best;
    s16 idx;
    s16 v;
    NdRec *p;
    u8 *tab;
    u8 *base;

    for (i = 0; i < 0x24; i++) {
        D_801ED47C[i] = 0;
        p = &D_801ED57C[i];
        p->c = 0;
        p->b = 0;
        D_801ED57C[i].a = 0;
    }
    base = D_801D4CA0;
    tab = base + D_801D4C9C;
    tab += 4;
    i = 0;
    do {
        best = -0x8000;
        j = 0;
        do {
            if (D_801ED47C[j] == 0) {
                v = *(s16 *)(base + *(s16 *)(tab + j * 16) + 2);
                if (v > best) {
                    best = v;
                    idx = j;
                }
            }
            j++;
        } while (j < 0x24);
        D_801ED37C[i] = idx;
        i++;
        D_801ED47C[idx] = 1;
    } while (i < 0x24);
    for (i = 0; i < 0x24; i++) {
        D_801ED47C[i] = 0;
    }
}

void func_801B1350(void) {
    MgTask *p;
    s16 i;
    s16 j;
    s16 *q;
    u8 *tab;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x1E) {
            func_800BBA84(0x18A, -1, 0x40);
        }
        if (p->unk2 >= 0x1E) {
            i = 0;
            if (D_801D530A != 0x24) {
                do {
                    i++;
                    D_801ED47C[D_801ED37C[D_801D530A]] = 1;
                    D_801D530A++;
                } while (i < 2);
            }
            tab = D_801D4CA4;
            j = 0;
            tab += D_801D4C9C;
            do {
                if (D_801ED47C[j] == 1) {
                    D_801ED57C[j].b += 0x28;
                    q = (s16 *)(j * 16 + (s32)tab);
                    if (q[3] != 0) {
                        q[3] -= 0x10;
                    }
                }
                j++;
            } while (j < 0x24);
        }
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B1500(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D5314;
    *frame = p->unk2;
    D_801ED378 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801ED378);
    if (D_80062D98 == 0) {
        p->unk6 += 0x50;
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= D_801D5244) {
            p->unk0 = -1;
        }
    }
}

void func_801B15C8(void) {
    MgMat a;
    MgMat b;
    MgTask *p;
    MgTask *q;
    s16 ang;
    s16 k;
    u16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D5318, &a);
    func_8003B35C(&a, &D_801D5320);
    a.t[0] = p->unk4;
    a.t[1] = p->unk6;
    a.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &a, &a);
    func_8003C21C(&D_801D5318, &b);
    func_8003B69C(0, 0, 0);
    D_801ED378 = func_801B0020(D_801D5330, D_801517C0 + 0x70, 0xC, D_801ED378, D_801ED57C, &a, &b);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if ((u16)(t - 0x1E) < 0x12U) {
            k = p->unk2 - 0x1E;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1500)];
            ang = func_80042DA8() % 0x1000;
            q->unk4 = p->unk4 + (func_80039A74(ang) * 0x2BC >> 12);
            q->unk8 = p->unk8 + (func_80039B40(ang) * 0x2BC >> 12);
            q->unk6 = -k * 0x5A + func_80042DA8() % 400 - 0xC8;
        }
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B1820(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    frame = &D_801D5348;
    *frame = p->unk2;
    D_801ED378 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801ED378);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x64;
        p->unk8 += D_801D5308 * 0x384;
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= D_801D4F94) {
            p->unk0 = -1;
        }
    }
}

void func_801B1910(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801D5354[0] = p->unk2;
    D_801ED378 = func_800D4D90(&D_801D5354[-4], D_801517C0 + 0x70, 0xC, D_801ED378);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D511C) {
            p->unk0 = -1;
        }
    }
}

void func_801B19CC(void) {
    MgMat m;
    u8 pad[0x28];
    MgSVec rot;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 c;
    s32 r;
    s32 *fp;
    s32 t3;

    rot.vx = rot.vz = 0;
    rot.vy = D_801D5308 * -0x400;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&rot, &m);
    func_8003B35C(&m, &D_801D5358);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    if (p->unk2 >= 0x2A) {
        c = 0x32 - p->unk2;
        c <<= 4;
    } else {
        c = 0x80;
    }
    D_801D5372 = c;
    fp = &D_801D536C;
    *fp = (*(s16 *)((u8 *)&D_801D536C + 6) != 0x80) * 8;
    D_801ED378 = func_800D29D4((u8 *)fp - 4, D_801517C0 + 0x70, 0xC, D_801ED378);
    if (D_80062D98 == 0) {
        D_801D5358.vx += 0x12C;
        D_801D5358.vy += 0x190;
        if (p->unk2 < 0xF) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1820)];
                r = func_80042DA8();
                q->unk4 = r % 0x4000 - 0x2000;
                i++;
                q->unk8 = p->unk8;
                q->unk6 = 0;
            } while (i < 6);
        }
        p->unk8 += p->unk10;
        p->unk10 -= D_801D5308 * 0xF;
        t3 = D_801031EA[0] + 0x40;
        D_801031EA[0] = t3 - p->unk2 % 2 * 0x80;
        p->unk2++;
        if (p->unk2 == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B1C54(void) {
    MgTask *p;
    MgTask *q;
    u8 pad[0x40];
    s16 i;
    s32 r;
    s32 u1;
    s32 u2;
    s32 u3;
    s32 k1;
    s32 k2;
    s32 k3;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B19CC)];
            q->unk4 = 0;
            q->unk6 = 0;
            q->unk8 = D_801D5308 * -0x2000;
            q->unk10 = D_801D5308 * 0x3E8;
        }
        if ((u16)(p->unk2 - 0x57) < 7U) {
            for (i = 0; i < 10; i++) {
                if ((D_801ED97C >> i) & 1) {
                    q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1910)];
                    func_800D3994(i, D_8015190F[i][0], &q->unk4);
                    u1 = func_80042DA8();
                    k1 = (u16)q->unk4 - 0x12C;
                    q->unk4 = k1 + u1 % 600;
                    u2 = func_80042DA8();
                    k2 = (u16)q->unk6 - 0x12C;
                    q->unk6 = k2 + u2 % 600;
                    u3 = func_80042DA8();
                    k3 = (u16)q->unk8 - 0x12C;
                    q->unk8 = k3 + u3 % 600;
                }
            }
        }
        if (p->unk2 == 0x28) {
            for (i = 0; i < 10; i++) {
                if ((D_801ED97C >> i) & 1) {
                    r = func_800BBEAC(func_801B15C8);
                    q = (MgTask *)((u8 *)D_80162978 + 4);
                    func_800D3994(i, D_8015190F[i][0], (u8 *)q + (r << 5));
                }
            }
            func_800BBEAC(func_801B1350);
            func_800BBA84(0x189, -1, 0x40);
        }
        if (p->unk2 == 0x5A) {
            for (i = 0; i < 10; i++) {
                if ((D_801ED97C >> i) & 1) {
                    func_800D5774(i);
                }
            }
        }
        p->unk2++;
        if (p->unk2 == 0x64) {
            func_800D52A0(0, 0xA);
            p->unk0 = -1;
        }
    }
}

s32 func_801B1FDC(arg0, arg1) {
    MgTask *p;
    s32 t;

    func_800BBEAC(func_801B1158);
    func_800D2980(&D_801B2118, 0, 0, 0);
    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B1C54)];
    p->unk1C = arg1;
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D54EC(arg0, &p->unkC);
    if (p->unk8 > p->unk10) {
        t = D_801D5308;
        D_801D5308 = -t;
    }
    D_801ED97C = arg0;
    func_801B11C4();
    func_800BBA84(0x18B, arg1, 0x40);
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    D_800F5B72 = 0x40;
    return func_800D52A0(0xE00, 0x1E);
}
