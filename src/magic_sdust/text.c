#include "common.h"
#include "magic_sdust/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B355C();
    return &D_801B7A00;
}

void func_801B007C(void) {
    MgTask *p;
    u16 *frame;
    u16 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801B95B8;
    *frame = p->unk2;
    t = p->unk10;
    func_800D4368(&p->unk4, (s16)t, -((s16)t >> 4));
    D_801E15F8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E15F8);
    if (p->unk2 >= 3) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0148(void) {
    MgTask *p;
    MgTask *q;
    s32 d;
    s32 w;
    s32 i;
    s32 k;
    s32 r;
    s32 a;

    if (D_80062D98 == 0) {
        k = 0xC80;
        p = &D_80162978[D_8015169C];
        d = p->unk10;
        i = 0;
        w = d * 2;
        do {
            q = &D_80162978[func_800BBEAC(&func_801B007C)];
            q->unk4 = p->unk4 + func_80042DA8() % w - d;
            q->unk6 = p->unk6 + func_80042DA8() % w - d;
            q->unk8 = p->unk8 + func_80042DA8() % w - d;
            r = func_80042DA8();
            a = r / 0x1000;
            a = r - a * 0x1000;
            i++;
            q->unk10 = (k * (a + 0x800)) >> 12;
        } while (i < 4);
        if (p->unk2 >= 4) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0318(void) {
    MgSVec rot;
    MgMat m;
    MgVec s;
    MgVec w;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    p = &D_80162978[D_8015169C];
    rot.vz = p->unkC;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = 0x200;
    func_8003AB84(&m, &D_801B91A0, &w);
    s.vx = s.vy = s.vz = p->unk10;
    func_8003B35C(&m, &s);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = &D_801B72D8;
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801E15F8 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x4068, 0, D_801E15F8);
    if (p->unk2 >= 0x14) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += (p->unk12 * w.vx) >> 12;
        p->unk6 += (p->unk12 * w.vy) >> 12;
        p->unk12 += p->unk12 >> 4;
        p->unk2++;
    }
}

void func_801B04C4(SdPos *arg0, s32 arg1, s32 arg2) {
    SdFT4 *pk;

    pk = (SdFT4 *)D_801E15F8;
    pk->x0 = pk->x2 = arg0->x;
    pk->y0 = arg0->y;
    pk->y1 = pk->y0;
    pk->x1 = pk->x3 = pk->x0 + 0x20;
    pk->y2 = pk->y3 = pk->y0 + 0x20;
    if (arg1 != 0) {
        pk->uv0 = 0x78C80000;
        pk->uv2 = 0x1F00;
        pk->uv1 = 0x2D001F;
        pk->uv3 = 0x1F;
    } else {
        pk->uv0 = 0x78C80020;
        pk->uv1 = 0x2D003F;
        pk->uv2 = 0x1F20;
        pk->uv3 = 0x3F;
    }
    pk->rgbc = arg2 | 0x2C000000;
    pk->tag.len = 9;
    pk->tag.addr = ((SdOt *)D_801517C0)->head.addr;
    ((SdOt *)D_801517C0)->head.addr = (u32)pk;
    pk++;
    D_801E15F8 = (s32)pk;
}

void func_801B05BC(void) {
    MgTask *p;
    u8 *q;
    s32 t;
    s32 c;
    s32 i;
    s32 k;
    s32 u;
    s32 o;
    s32 v;
    s32 w;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    c = t * 0x10;
    if (t >= 8) {
        if (t < 0x39) {
            c = 0x80;
        } else {
            c = 0x80 - (t - 0x39) * 0x10;
        }
    }
    k = (c << 16) | (c << 8) | c;
    i = 0;
    q = D_801E3D68;
    o = 0;
    for (; i < 0x1E; i++) {
        if (((SdPart *)(D_801E3D64 + o))->f0 != 0) {
            func_801B04C4((SdPos *)q, ((SdPart *)(D_801E3D64 + o))->f2, k);
        }
        q += 0x18;
        o += 0x18;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x41) {
            p->unk0 = -1;
        }
        if (p->unk2 == 0) {
            i = 0;
            do {
                for (k = 0, v = 0; k < 0x1E; k++, v += 0x18) {
                    if (((SdPart *)(D_801E3D64 + v))->f0 == 0) {
                        break;
                    }
                }
                if (k >= 0x1E) {
                    break;
                }
                w = k * 0x18;
                ((SdPart *)(D_801E3D64 + w))->f0 = 1;
                u = (D_801E4034 + 1) & 0xFF;
                D_801E4034 = u;
                ((SdPart *)(D_801E3D64 + w))->f2 = u;
                i++;
                ((SdPos *)(D_801E3D68 + w))->x = func_80042DA8() % 300;
                ((SdPos *)(D_801E3D68 + w))->y = func_80042DA8() % 150;
            } while (i < 0x18);
        }
        p->unk2++;
    }
}

void func_801B0818(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
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
    v.vx = v.vy = v.vz = p->unk10;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = &D_801B7428;
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
    D_801E15F8 = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801E15F8);
    if (p->unk2 >= 0xC) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk10 += p->unk12;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B09AC);

void func_801B0DCC(void) {
    MgTask *p;
    MgMat *m;
    s32 *s;
    u8 *c;
    u8 *e;
    s32 i;
    s32 j;
    s32 n;
    s32 a;
    s32 b;
    s32 k;
    s32 r;
    s32 o;
    s32 v;
    s32 col;
    s16 t;
    u16 u;
    u8 pad[8];

    s = (s32 *)0x1F800000;
    c = D_801B95C0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 0xB4; i++) {
        if (D_801E1602.e[i].f0 != 0) {
            e = (u8 *)&D_801E1602.e[i].f4;
            col = -0x80 - (u8)D_801E1602.e[i].f2 * 4;
            c[2] = col;
            c[1] = col;
            c[0] = col;
            u = D_801E1602.e[i].f16;
            m = func_800D4368(e, (s16)u, -((s16)u >> 3));
            s[2] = m->t[2] >> 4;
            D_801E15F8 = func_800D4D90(c - 4, D_801517C0 + 0x70, 0xC, D_801E15F8);
            func_801B09AC(s, e, D_801E1602.e[i].f14, c[0]);
            if (D_80062D98 == 0) {
                D_801E1602.e[i].f4 += D_801E1602.e[i].fC;
                D_801E1602.e[i].f6 += D_801E1602.e[i].fE;
                D_801E1602.e[i].f8 += D_801E1602.e[i].f10;
                D_801E1602.e[i].fE += D_801E1602.e[i].f12;
                if (D_801E1602.e[i].fE < 0) {
                    D_801E1602.e[i].fE = 0;
                } else {
                    D_801E1602.e[i].f12 -= 1;
                }
                if (D_801E1602.e[i].f6 > 0 || D_801E1602.e[i].f2 >= 0x1F) {
                    D_801E1602.e[i].f0 = 0;
                }
                D_801E1602.e[i].f2++;
            }
        }
    }
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x37) {
            p->unk0 = -1;
        }
        t = p->unk2;
        if (t < 0x19) {
            n = 8 - (t >> 1);
            i = 0;
            if (n < 4) {
                n = 4;
            }
            k = 0xF33;
            if (n > 0) {
                do {
                    for (j = 0, v = 0; j < 0xB4; j++, v += 0x18) {
                        if (((SdPart *)(D_801E1604 + v))->f0 == 0) {
                            break;
                        }
                    }
                    if (j >= 0xB4) {
                        break;
                    }
                    o = j * 0x18;
                    ((SdPart *)(D_801E1604 + o))->f0 = 1;
                    ((SdPart *)(D_801E1604 + o))->f2 = 0;
                    r = 0;
                    r = func_80042DA8();
                    a = r / 0x1000;
                    a = r - a * 0x1000;
                    b = func_80042DA8() % 180 + 0x50;
                    ((SdPart *)(D_801E1604 + o))->f4 = p->unk4 + ((func_80039B40(a) * b) >> 12);
                    ((SdPart *)(D_801E1604 + o))->f6 = p->unk6;
                    ((SdPart *)(D_801E1604 + o))->f8 = p->unk8 + ((func_80039A74(a) * b) >> 12);
                    b = func_80042DA8() % 80 + 0x32;
                    ((SdPart *)(D_801E1604 + o))->fC = (func_80039B40(a) * b) >> 12;
                    ((SdPart *)(D_801E1604 + o))->fE = func_80042DA8() % 110 + 0xDC;
                    ((SdPart *)(D_801E1604 + o))->f10 = (func_80039A74(a) * b) >> 12;
                    ((SdPart *)(D_801E1604 + o))->f12 = -(func_80042DA8() % 4 + 4);
                    ((SdPart *)(D_801E1604 + o))->f14 = func_80042DA8() % 5 + 3;
                    v = 0xA00;
                    a = func_80042DA8() % 0x1000 - (p->unk2 * 20 - v);
                    ((SdPart *)(D_801E1604 + o))->f16 = (k * a) >> 12;
                    i++;
                } while (i < n);
            }
        }
        p->unk2++;
    }
}

void func_801B1424(void) {
    MgTask *p;
    MgMat *mat;
    u8 *s;
    u8 *c;
    s32 i;
    s32 j;
    s32 n;
    s32 a;
    s32 b;
    s32 k;
    s32 r;
    s32 v;
    s32 o;
    s32 w;
    s32 col;
    s16 t;
    s32 u;
    u16 x;
    u8 pad[8];

    s = (u8 *)0x1F800000;
    c = D_801B95CC;
    mat = (MgMat *)0x1F800160;
    *(s16 *)0x1F8000D0 = 0;
    *(s16 *)0x1F8000D2 = 0;
    *(u16 *)0x1F8000D4 = 0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 0x78; i++) {
        if (D_801E26E2.e[i].f0 != 0) {
            if (D_801E26E2.e[i].f2 >= 0x10) {
                col = -0x80 - ((u8)D_801E26E2.e[i].f2 - 0x10) * 8;
                c[2] = col;
                c[1] = col;
                c[0] = col;
            } else {
                c[2] = 0x80;
                c[1] = 0x80;
                c[0] = 0x80;
            }
            *(u16 *)(s + 0xD4) = D_801E26E2.e[i].f12;
            func_8003BF8C((MgSVec *)(s + 0xD0), mat);
            *(s32 *)(s + 0x180) = *(s32 *)(s + 0x184) = *(s32 *)(s + 0x188) = D_801E26E2.e[i].f16;
            func_8003B35C(mat, (MgVec *)(s + 0x180));
            x = D_801E26E2.e[i].f16;
            func_800D4284(&D_801E26E2.e[i].f4, -((s16)x >> 3), mat);
            func_8003B48C(mat);
            func_8003B51C(mat);
            D_801E15F8 = func_800D4D90(D_801B95C8, D_801517C0 + 0x70, 0xC, D_801E15F8);
            if (D_80062D98 == 0) {
                D_801E26E2.e[i].f4 += D_801E26E2.e[i].fC;
                D_801E26E2.e[i].f6 += D_801E26E2.e[i].fE;
                D_801E26E2.e[i].f8 += D_801E26E2.e[i].f10;
                D_801E26E2.e[i].f12 += D_801E26E2.e[i].f14;
                if (D_801E26E2.e[i].f6 > 0 || D_801E26E2.e[i].f2 >= 0x1F) {
                    D_801E26E2.e[i].f0 = 0;
                }
                D_801E26E2.e[i].f2++;
            }
        }
    }
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x37) {
            p->unk0 = -1;
        }
        t = p->unk2;
        if (t < 0x19) {
            n = 6 - (t >> 1);
            i = 0;
            if (n < 3) {
                n = 3;
            }
            k = 0x10E0;
            if (n > 0) {
                do {
                    for (j = 0, v = 0; j < 0x78; j++, v += 0x18) {
                        if (((SdPart *)(D_801E26E4 + v))->f0 == 0) {
                            break;
                        }
                    }
                    if (j >= 0x78) {
                        break;
                    }
                    o = j * 0x18;
                    ((SdPart *)(D_801E26E4 + o))->f0 = 1;
                    ((SdPart *)(D_801E26E4 + o))->f2 = 0;
                    r = func_80042DA8();
                    a = r / 0x1000;
                    a = r - a * 0x1000;
                    b = func_80042DA8() % 180 + 0x50;
                    ((SdPart *)(D_801E26E4 + o))->f4 = p->unk4 + ((func_80039B40(a) * b) >> 12);
                    ((SdPart *)(D_801E26E4 + o))->f6 = p->unk6 + b;
                    ((SdPart *)(D_801E26E4 + o))->f8 = p->unk8 + ((func_80039A74(a) * b) >> 12);
                    b = func_80042DA8() % 110 + 0x5A;
                    ((SdPart *)(D_801E26E4 + o))->fC = (func_80039B40(a) * b) >> 12;
                    ((SdPart *)(D_801E26E4 + o))->fE = func_80042DA8() % 170 + 0x82;
                    w = func_80039A74(a) * b;
                    u = (D_801E4034 + 1) & 0xFF;
                    D_801E4034 = u;
                    ((SdPart *)(D_801E26E4 + o))->f12 = u;
                    ((SdPart *)(D_801E26E4 + o))->f10 = w >> 12;
                    w = func_80042DA8() % 220 + 0x96;
                    ((SdPart *)(D_801E26E4 + o))->f14 = w;
                    if (((SdPart *)(D_801E26E4 + o))->f12 & 1) {
                        ((SdPart *)(D_801E26E4 + o))->f14 = -w;
                    }
                    i++;
                    v = 0x800;
                    a = func_80042DA8() % 0x1400 - (p->unk2 * 4 - v);
                    ((SdPart *)(D_801E26E4 + o))->f16 = (k * a) >> 12;
                } while (i < n);
            }
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B1ADC);

void func_801B2250(void) {
    MgTask *p;
    u8 *c;
    s32 i;
    s32 j;
    s32 n;
    s32 a;
    s32 b;
    s32 k;
    s32 r;
    s32 col;
    s16 t;
    u16 u;
    u8 pad[8];

    c = D_801B95E4;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 0x78; i++) {
        if (D_801E3224[i].f0 != 0) {
            col = -0x80 - (u8)D_801E3224[i].f2 * 4;
            c[2] = col;
            c[1] = col;
            c[0] = col;
            u = D_801E3224[i].f16;
            func_800D4368(&D_801E3224[i].f4, (s16)u, -((s16)u >> 3));
            D_801E15F8 = func_800D4D90(c - 4, D_801517C0 + 0x70, 0xC, D_801E15F8);
            if (D_80062D98 == 0) {
                D_801E3224[i].f4 += D_801E3224[i].fC;
                D_801E3224[i].f6 += D_801E3224[i].fE;
                D_801E3224[i].f8 += D_801E3224[i].f10;
                if (D_801E3224[i].f6 > 0 || D_801E3224[i].f2 >= 0x1F) {
                    D_801E3224[i].f0 = 0;
                }
                D_801E3224[i].f2++;
            }
        }
    }
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x37) {
            p->unk0 = -1;
        }
        t = p->unk2;
        if (t < 0x19) {
            n = 6 - (t >> 1);
            do {
                i = 0;
            } while (0);
            if (n < 3) {
                n = 3;
            }
            k = 0x1400;
            if (n > 0) {
                do {
                    for (j = 0; j < 0x78; j++) {
                        if (D_801E3224[j].f0 == 0) {
                            break;
                        }
                    }
                    if (j >= 0x78) {
                        break;
                    }
                    D_801E3224[j].f0 = 1;
                    D_801E3224[j].f2 = 0;
                    r = func_80042DA8();
                    a = r / 0x1000;
                    a = r - a * 0x1000;
                    b = func_80042DA8() % 180 + 0x50;
                    D_801E3224[j].f4 = p->unk4 + ((func_80039B40(a) * b) >> 12);
                    D_801E3224[j].f6 = p->unk6 + b;
                    D_801E3224[j].f8 = p->unk8 + ((func_80039A74(a) * b) >> 12);
                    i++;
                    b = func_80042DA8() % 110 + 0x5A;
                    D_801E3224[j].fC = (func_80039B40(a) * b) >> 12;
                    D_801E3224[j].fE = func_80042DA8() % 180 + 0x78;
                    D_801E3224[j].f10 = (func_80039A74(a) * b) >> 12;
                    a = func_80042DA8() % 4608 + 0xA00;
                    D_801E3224[j].f16 = (k * a) >> 12;
                } while (i < n);
            }
        }
        p->unk2++;
    }
}

void func_801B276C(void) {
    MgTask *p;
    u8 *c;
    s32 i;
    s32 j;
    s32 n;
    s32 a;
    s32 b;
    s32 k;
    s32 r;
    s32 col;
    s16 t;
    s16 v;
    u16 u;
    u8 pad[8];

    c = D_801B95F0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 0x78; i++) {
        if (D_801E3224[i].f0 != 0) {
            col = -0x80 - (u8)D_801E3224[i].f2 * 4;
            c[2] = col;
            c[1] = col;
            c[0] = col;
            u = D_801E3224[i].f16;
            func_800D4368(&D_801E3224[i].f4, (s16)u, -((s16)u >> 3));
            D_801E15F8 = func_800D4D90(c - 4, D_801517C0 + 0x70, 0xC, D_801E15F8);
            if (D_80062D98 == 0) {
                D_801E3224[i].f4 += D_801E3224[i].fC;
                D_801E3224[i].f6 += D_801E3224[i].fE;
                D_801E3224[i].f8 += D_801E3224[i].f10;
                v = D_801E3224[i].fE + D_801E3224[i].f12;
                D_801E3224[i].fE = v;
                if (v < 0) {
                    D_801E3224[i].fE = 0;
                } else {
                    D_801E3224[i].f12 -= 1;
                }
                if (D_801E3224[i].f6 > 0 || D_801E3224[i].f2 >= 0x1F) {
                    D_801E3224[i].f0 = 0;
                }
                D_801E3224[i].f2++;
            }
        }
    }
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x37) {
            p->unk0 = -1;
        }
        t = p->unk2;
        if (t < 0x19) {
            n = 6 - (t >> 1);
            do {
                i = 0;
            } while (0);
            if (n < 3) {
                n = 3;
            }
            k = 0x1400;
            if (n > 0) {
                do {
                    for (j = 0; j < 0x78; j++) {
                        if (D_801E3224[j].f0 == 0) {
                            break;
                        }
                    }
                    if (j >= 0x78) {
                        break;
                    }
                    D_801E3224[j].f0 = 1;
                    D_801E3224[j].f2 = 0;
                    r = func_80042DA8();
                    a = r / 0x1000;
                    a = r - a * 0x1000;
                    b = func_80042DA8() % 180 + 0x50;
                    D_801E3224[j].f4 = p->unk4 + ((func_80039B40(a) * b) >> 12);
                    D_801E3224[j].f6 = p->unk6 + b;
                    D_801E3224[j].f8 = p->unk8 + ((func_80039A74(a) * b) >> 12);
                    b = func_80042DA8() % 90 + 0x32;
                    D_801E3224[j].fC = (func_80039B40(a) * b) >> 12;
                    D_801E3224[j].fE = func_80042DA8() % 130 + 0xC8;
                    D_801E3224[j].f10 = (func_80039A74(a) * b) >> 12;
                    D_801E3224[j].f12 = -(func_80042DA8() % 4 + 4);
                    a = func_80042DA8() % 0x1000 + 0x800;
                    i++;
                    D_801E3224[j].f16 = (k * a) >> 12;
                } while (i < n);
            }
        }
        p->unk2++;
    }
}

void func_801B2D3C(s32 arg0, s32 arg1, s32 arg2) {
    SdPolyG4 *pk;
    s32 a;
    s32 b;
    s32 c;
    s32 i;
    s32 step;

    pk = (SdPolyG4 *)D_801E15F8;
    c = 0;
    a = arg1 << 16;
    b = a + 0x13F;
    step = arg2 << 16;
    for (i = 0; i < 0x46; i++) {
        pk->xy0 = a;
        a += step;
        pk->xy1 = b;
        b += step;
        if ((u32)(a & 0xFFFF0000) > 0xAA0000) {
            c += arg0;
        } else {
            pk->c1 = c;
            pk->c0 = c;
            c += arg0;
            pk->xy2 = a;
            pk->xy3 = b;
            if (c > 0xE0E0E0) {
                c = 0xE0E0E0;
            }
            pk->tag.len = 8;
            pk->c3 = c;
            pk->c2 = c;
            *((u8 *)&pk->c0 + 3) = 0x38;
            pk->tag.addr = ((SdOt *)D_801517C0)->head.addr;
            ((SdOt *)D_801517C0)->head.addr = (u32)pk;
            pk++;
        }
    }
    D_801E15F8 = (s32)pk;
}

void func_801B2E38(s32 arg0) {
    SdPolyG4 *pk;
    s32 a;
    s32 b;
    s32 i;
    s32 c;
    s32 step;

    pk = (SdPolyG4 *)D_801E15F8;
    a = 0;
    b = 0x13F;
    step = 0x40000;
    c = (arg0 << 16) | (arg0 << 8) | arg0;
    for (i = 0; i < 0x2A; i++) {
        pk->xy0 = a;
        a += step;
        pk->xy1 = b;
        b += step;
        pk->xy2 = a;
        pk->xy3 = b;
        pk->c3 = c;
        pk->c2 = c;
        pk->c1 = c;
        pk->c0 = c;
        pk->tag.len = 8;
        *((u8 *)&pk->c0 + 3) = 0x38;
        pk->tag.addr = ((SdOt *)D_801517C0)->head.addr;
        ((SdOt *)D_801517C0)->head.addr = (u32)pk;
        pk++;
    }
    D_801E15F8 = (s32)pk;
}

void func_801B2F04(void) {
    MgTask *p;
    MgTask *q;
    MgTask *e;
    s32 t;
    s32 k;
    s32 w;
    s32 r;
    s32 c;
    s32 u;
    s32 b;
    s16 m;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t == 0x1F) {
            q = &D_80162978[func_800BBEAC(&func_801B0DCC)];
            *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
            func_800D55F4(0x29, func_800D56A8(&p->unk4), 0x265);
            u = p->unk2;
            if (u == t) {
                q = &D_80162978[func_800BBEAC(&func_801B1ADC)];
                *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
                if (p->unk2 == u) {
                    q = &D_80162978[func_800BBEAC(&func_801B276C)];
                    *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
                }
            }
        }
        if (p->unk2 == 8) {
            *(MgSVec *)&D_80162978[func_800BBEAC(&func_801B05BC)].unk4 = *(MgSVec *)&p->unk4;
        }
        if (p->unk2 == 0x36) {
            q = &D_80162978[func_800BBEAC(&func_801B0318)];
            q->unk4 = 0xAA;
            q->unk6 = -0x50;
            q->unkC = -0x4D2;
            q->unk10 = 0x28F;
            q->unk12 = 0x10;
        }
        b = (u16)p->unk2;
        if ((u32)(b - 0x28) < 0x15 && (b & 1)) {
            k = p->unk10;
            w = k * 2;
            q = &D_80162978[func_800BBEAC(&func_801B0818)];
            q->unk4 = p->unk4 + func_80042DA8() % w - k;
            q->unk6 = 0;
            q->unk8 = p->unk8 + func_80042DA8() % w - k;
            r = func_80042DA8();
            k = 0x1174;
            c = r % 2560 + 0x800;
            q->unk10 = 0;
            q->unk12 = ((c * k) >> 12) / 6;
        }
        m = p->unk2;
        if (m < 8) {
            D_800F5B70[0] = D_800F5B70[1] = D_800F5B70[2] = 0;
            k = p->unk2 << 9;
        } else if (m >= 0x48) {
            D_800F8380 &= 0xF8;
            k = 0x1000 - (p->unk2 - 0x48) * 0x200;
        } else {
            k = 0x1000;
            D_800F8380 |= 7;
        }
        if (p->unk2 >= 0x26 && (((volatile MgTask *)p)->unk2 & 3) == 0) {
            c = D_801517F0[p->unk1A];
            if (c != 0xFF) {
                e = func_800D4FA8(10);
                e->unk0 = c;
                e->unk10 = p->unk1A;
                p->unk1A++;
                q = &D_80162978[func_800BBEAC(&func_801B0148)];
                func_800D3994(c, D_8015190F[c][0], &q->unk4);
                q->unk10 = D_801518F6[c][0];
            }
        }
        if (p->unk2 >= 0x50) {
            k = 0;
            D_800F5B70[0] = D_800F5B70[1] = D_800F5B70[2] = 0;
            p->unk0 = -1;
            func_800D55F4(0x28, func_800D56A8(&p->unk4), 0);
        }
        D_800F5B74.v = k;
        p->unk2++;
    }
}

void func_801B3418(void) {
    MgTask *p;
    s32 i;
    s32 j;
    MgTask *b;

    D_80162978[D_8015169C].unk0 = -1;
    b = D_80162978;
    p = &b[func_800BBEAC(&func_801B2F04)];
    func_800D54EC(D_801E1600, &p->unk4);
    p->unk6 = -0x10E0;
    p->unk10 = 0x900;
    p->unk1A = 0;
    for (i = 0x10C8; i >= 0; i -= 0x18) {
        *(s16 *)(D_801E1604 + i) = 0;
    }
    for (j = 0xB28; j >= 0; j -= 0x18) {
        *(s16 *)(D_801E26E4 + j) = 0;
    }
    for (j = 0xB28; j >= 0; j -= 0x18) {
        *(s16 *)((u8 *)D_801E3224 + j) = 0;
    }
    for (j = 0x2B8; j >= 0; j -= 0x18) {
        *(s16 *)(D_801E3D64 + j) = 0;
    }
    D_801E4034 = func_80042DA8() % 256;
    func_800D55F4(0x28, func_800D56A8(&p->unk4), 0x128);
}

INCLUDE_RODATA("../asm/us/magic_sdust/nonmatchings/text", D_801B0000);

void func_801B355C(arg0) {
    D_801E15FC = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B35D8, 0, 0, 0);
    func_800BBEAC(&func_801B3418);
    D_801E1600 = arg0;
}
