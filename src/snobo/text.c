#include "common.h"
#include "snobo/decls.h"

void func_800A0390(void) {
    s16 *p = &D_8009A000;

    *p = 0xBA;
    D_8009A004 = 0x40;
    func_8002DA7C();
    *p = 0xB8;
    D_8009A004 = 0x7F;
    func_8002DA7C();
    *p = 0xBC;
    D_8009A004 = 0;
    func_8002DA7C();
    func_800A1514();
    func_800A155C();
    func_800A1624();
    func_8003B6BC(0, 0);
    func_8003B6DC(0xA0);
    func_800A1CC0(0, 0, 0x10);
    func_800A6D04();
    func_800A9DB4();
    D_800DD74C = 0;
    D_800DD740 = 1;
    func_80043F6C(D_800BFEB8, 0, 0, 0);
    func_80043DD8(0);
    func_80043D3C(1);
    D_801027BC = 0;
    D_80102818 = 0;
    D_800FF750 = 0;
    D_800DD748 = func_800A057C;
    if (*(u8 *)&D_800DD740 != 0) {
        do {
            func_800A1470();
            func_800A1670();
            D_800DD748();
            D_8010285C = func_80042B10(0x1F8003FC);
            D_80102798 = func_800AAE98(0x80180000, D_80102794, D_80102798);
            func_80042B10(D_8010285C);
            func_800A16F0();
            func_80034B44();
            D_80102958 += 1;
        } while (*(u8 *)&D_800DD740 != 0);
    }
    func_80043D3C(1);
    func_800A1378();
    func_800A12DC();
}

void func_800A057C(void) {
    s32 *p;
    u32 c;

    p = &D_800FF750;
    *p += 4;
    c = *(u8 *)p;
    func_800A62C4((c << 16) | (c << 8) | c, (s32) D_80102794);
    if (*p >= 0xFC) {
        *p = 0;
        D_800DD748 = func_800A05FC;
    }
}

void func_800A05FC(void) {
    s32 *p;
    s32 n;

    p = &D_800FF750;
    n = *p + 1;
    *p = n;
    if (n < 0x80) {
        func_800A61EC(0x100 - n * 2, (s32)D_80102794);
    }
    if (n < 0x100) {
        D_800BFE90.v[0] = ((n * 3) << 5 >> 8) - 0x20;
        D_800BFE90.v[1] = 0x1000 - ((n << 11) >> 8);
        D_800BFE90.v[5] = ((n << 6) >> 8) + 0x40;
        D_800BFE90.v[2] = 0;
        D_800BFE90.v[4] = 0;
        D_800BFE90.v[6] = (((n * 8 - n) << 5) >> 8) + 0x60;
    } else {
        *(SbRaw16 *)&D_800BFE90 = *(SbRaw16 *)&D_800BFEA0;
    }
    func_800A36C4(&D_800DB1F8, &D_800DB1F8);
    func_800A1874();
    func_800A56C4((void *)0x1F800000);
    func_800A212C(0, 1, 2);
    D_800FF770.x = (D_800DB1F8.v[0] >> 12) - (u16)D_8010284C;
    D_800FF770.y = (D_800DB1FC >> 12) - (u16)D_80102850;
    D_800FF770.z = (D_800DB200 >> 12) - (u16)D_80102854;
    func_800A6D28(&D_800FF770, (void *)0x1F800000, 1, 1);
    func_800A5E80();
    func_800A1978();
    if ((u8)D_800DB1E0 != 0x10) {
        if (D_800FF750 > 0x100) {
            D_801027A4 = 1;
            D_800DD748 = func_800A0820;
        }
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A0820);

void func_800A0CDC(void) {
    s16 *p;

    D_801027B8 = 0;
    D_801027AC = 0;
    func_800A0F1C(1, 1);
    if (D_8010281C == D_800BFE80[D_801028E0]) {
        if (D_801027C8 >= 0x3C) {
            p = &D_800DB1E0;
            switch ((u8)*p) {
            case 1:
            case 0x11:
            case 0x12:
                *p = 3;
                break;
            }
        }
        if (D_800DD744 != 0) {
            D_800FF754 = 0;
            D_800FF750 = 0;
            D_800DD748 = func_800A0DC0;
        }
    }
}

void func_800A0DC0(void) {
    s32 *p;
    s32 *q;
    s32 c;

    p = &D_800DB20C;
    *p -= 0xC00;
    c = (u8)D_800DB1E0;
    if (c >= 3 && c < 7) {
        D_801027B8 = 0;
        D_801027AC |= 0x40;
    } else {
        D_801027B8 = 0;
        D_801027AC = 0;
    }
    func_800A0F1C(1, 1);
    q = &D_800FF750;
    if (++*q >= 0x3D) {
        D_800FF754 += 2;
        func_800A61EC(D_800FF754, (s32)D_80102794);
        if (D_800FF754 >= 0xFC) {
            D_800DD748 = func_800A0EB0;
        }
    }
}

void func_800A0EB0(void) {
    s32 *p;
    u8 *ot;
    s32 c;

    p = &D_800FF754;
    c = *p;
    ot = D_80102794;
    do {
        c -= 4;
        *p = c;
        c &= 0xFF;
        func_800A62C4((c << 16) | (c << 8) | c, (s32) ot);
    } while (0);
    if (*p <= 0) {
        D_800DD740 = 0;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A0F1C);

void func_800A12DC(void) {
    D_8009D456 = D_800BFEC0[D_801028E0];
}

void func_800A1300(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        D_8009A000 = arg0 + 0x9F;
        D_8009A004 = arg2;
        func_8002DA7C();
    }
    D_8009A000 = arg0 + 0x27;
    D_8009A004 = 0x40;
    D_8009A008 = arg1;
    func_8002DA7C();
}

void func_800A1378(void) {
    s16 *p = &D_8009A000;
    

    *p = 0x10;
    D_8009A004 = D_800BFEB0 + 0x801FC000;
    func_8002DA7C();
    *p = 0xC0;
    D_8009A004 = 0x7F;
    func_8002DA7C();
    *p = 0xD8;
    D_8009A004 = 0;
    func_8002DA7C();
    *p = 0x23;
    D_8009A004 = 0x40;
    D_8009A008 = 0;
    D_8009A00C = 0;
    D_8009A010 = 0;
    D_8009A014 = 0;
    func_8002DA7C();
    *p = 0xB8;
    D_8009A004 = 0x7F;
    func_8002DA7C();
    *p = 0xBC;
    D_8009A004 = 0;
    func_8002DA7C();
}

void func_800A1470(void) {
    u32 out;

    D_801027B0 = D_801027AC;
    D_801027AC = ((s32 (*)(s32))func_8001C808)(0);
    D_801027B8 = (D_801027B0 ^ D_801027AC) & D_801027AC;
    if (D_801027B0 != D_801027AC) {
        D_801027A8 = 0;
    }
    out = D_801027AC;
    if (D_801027A8 != 0 && D_801027A8 < 0x10) {
        out = 0;
    }
    D_801027B4 = out;
    D_801027A8 += 1;
}

void func_800A1514(void) {
    func_80033E74(D_800BFD74, D_800BFD78, 0x801FC000, 0);
    do {

    } while (func_80034B44() != 0);
}

void func_800A155C(void) {
    Unk80046D0C tim;
    s32 i;

    func_80033E74(D_800BFD7C, D_800BFD80, 0x80120000, 0);
    do {
    } while (func_80034B44() != 0);
    for (i = 0; i < 7; i++) {
        func_80046CFC(D_800BFEC8[i] + 0x80120000);
        func_80046D0C(&tim);
        func_80044000(tim.b, (void *)tim.b_arg);
        if (tim.a != NULL) {
            func_80044000(tim.a, (void *)tim.a_arg);
        }
    }
    func_80043DD8(0);
    func_80043DD8(0);
}

void func_800A1624(void) {
    func_80033E74(D_800BFD84, D_800BFD88, 0x80180000, 0);
    do {

    } while (func_80034B44() != 0);
    func_800AAE1C(0x80180000);
}

void func_800A1670(void) {
    D_800DD74C ^= 1;
    D_80102794 = D_800F7750[D_800DD74C];
    func_80044244(D_80102794, 0x1000);
    D_80102798 = D_800DD750[D_800DD74C];
}

void func_800A16F0(void) {
    func_80043DD8(0);
    func_8003CEDC((D_80102848 != 0) * 2);
    func_800443B0(&D_800BFD8C[D_800DD74C]);
    func_800444AC(&D_800BFE44[D_800DD74C]);
    func_8004433C((s32)&D_800F7750[D_800DD74C][0x3FFC]);
    D_800FF77C = 0;
}

void func_800A17A4(void) {
    D_801028F8 = D_800DB1F8;
    D_80102908 = D_801027C4;
    D_8010290A = D_8010281C;
    D_8010290C = D_801027C8;
}

void func_800A180C(void) {
    D_800DB1F8 = D_801028F8;
    D_801027C4 = D_80102908;
    D_8010281C = D_8010290A;
    D_801027C8 = D_8010290C;
}

void func_800A1874(void) {
    void *temp_v0;

    temp_v0 = (D_801027C4 * 0xC) + M2C_FIELD(D_801028D4, s32 *, 0x1C);
    D_8010284C = M2C_FIELD(temp_v0, s32 *, 0);
    D_80102850 = M2C_FIELD(temp_v0, s32 *, 4);
    D_80102854 = M2C_FIELD(temp_v0, s32 *, 8);
}

void func_800A18C4(void) {
    s32 d;
    s32 s;

    d = D_800DB234 - D_800DB23C;
    if (d != 0) {
        s = (d < 0 ? -d : d) >> 3;
        if (s == 0) {
            s = 1;
        }
        if (d < 0) {
            s = -s;
        }
        D_800DB23C += s;
    }
    d = D_800DB230 - D_800DB238;
    if (d != 0) {
        s = (d < 0 ? -d : d) >> 2;
        if (s == 0) {
            s = 1;
        }
        if (d < 0) {
            s = -s;
        }
        D_800DB238 += s;
    }
}

void func_800A1978(void) {
    s32 sp10;
    s32 var_v0;

    if (D_801028F4 != 0) {
        if (D_801027A4 != 0) {
            func_800A9DFC(&sp10, D_801028D8);
            D_801028D8 = sp10;
        }
        if (D_80102958 & 1) {
            var_v0 = D_800DB1E8 * 0x96;
            if (var_v0 < 0) {
                var_v0 += 0x7FF;
            }
            D_80102910 = func_800AA574(((u32) var_v0 >> 0xB) & 0xFFFF);
        }
    }
    func_800A9FF8(D_801028D8, -0x98, -0x60);
    func_800AA1D0(D_80102910, 0x5C, -0x60);
    if (D_80102848 != 0) {
        func_800AA44C();
    }
}

void func_800A1A68(void) {
    u8 f;

    f = M2C_FIELD(D_801028D4, u8 **, 0xC)[D_801027C4] & 4;
    if (f != D_800DD73C) {
        D_800DD73C = f;
        if (f != 0) {
            D_8009A004 = 0x1E;
            D_8009A008 = 1;
        } else {
            D_8009A004 = 8;
            D_8009A008 = 0x7F;
        }
        D_8009A000 = 0xC1;
        func_8002DA7C();
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A1B08);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A1CC0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A212C);

void func_800A24C4(void *arg0) {
    SbFF784 *p;

    p = &D_800FF784[M2C_FIELD(arg0, s16 *, 0x36)];
    p->unk0 = M2C_FIELD(arg0, u16 *, 0x26);
    p->unk2 = M2C_FIELD(arg0, u16 *, 0x24);
    p->unk8 = M2C_FIELD(arg0, s32 *, 0x3C);
    p->unkC = M2C_FIELD(arg0, SbBlock32 *, 0x44);
    M2C_FIELD(arg0, s16 *, 0x36) += 1;
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A255C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A27FC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A2934);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A2FD4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A318C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A32E8);

void func_800A3624(void *arg0) {
    SbFF784 *p;
    s16 n;

    p = D_800FF784;
    n = M2C_FIELD(arg0, u16 *, 0x36);
    while (--n != -1) {
        ((void (*)(s32))func_800BC51C)(D_800BFE70[(s16)p->unk0] + (s16)p->unk2);
        p++;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A36C4);

void func_800A38CC(SbObjA *p, s16 i) {
    SbTbl *e;
    SbRec12 *r;
    u16 a;
    s32 b;

    p->unk3C = D_800C000C + p->unk10->unk8[i] * 0x374;
    e = (SbTbl *)(((-p->unk10->unk18[i] & 0xFFF) << 2) + (u8 *)D_8004BC98);
    a = e->a;
    b = e->b;
    p->unk1C = 0x1000;
    p->unk16 = 0;
    p->unk1A = 0;
    p->unk1E = 0;
    p->unk22 = 0;
    p->unk18 = a;
    p->unk14 = b;
    p->unk20 = -a;
    p->unk24 = b;
    r = &p->unk10->unk1C[i];
    p->unk34 = p->unk40 - r->unk0;
    p->unk38 = p->unk48 - r->unk8;
    func_8003B2CC(&p->unk14, &p->unk34, &p->unk34, b);
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A39CC);

s32 func_800A3C4C(u8 *arg0) {
    s32 r;

    r = func_800A39CC(arg0 + 0x34, *(s32 *)(arg0 + 0x3C), arg0);
    *(s16 *)(arg0 + 4) = r;
    if ((s16)r < 0) {
        return 1;
    }
    D_801027C8 = r;
    D_801028EC = arg0[0x63];
    return 0;
}

s32 func_800A3CB4(SbObjD *p) {
    SbTbl *e;
    SbTbl *tbl;
    SbRec12 *r;
    SbRec12 *rp;
    s16 *q;
    SbQ *h;
    s16 i;
    u16 a;
    s32 b;
    s32 res;

    h = p->unk10;
    i = p->unk2 + 1;
    p->unk2 = i;
    if (i >= *(s16 *)h) {
        D_800DD744 = 1;
        return 0;
    }
    q = &p->unk34;
    tbl = D_8004BC98;
    p->unk3C = (SbRecC *)(D_800C000C + h->unk8[i] * 0x374);
    e = (SbTbl *)(((-p->unk10->unk18[i] & 0xFFF) << 2) + (u8 *)tbl);
    a = e->a;
    b = e->b;
    p->unk16 = 0;
    p->unk1C = 0x1000;
    p->unk1A = 0;
    p->unk1E = 0;
    p->unk22 = 0;
    p->unk18 = a;
    p->unk14 = b;
    p->unk20 = -a;
    p->unk24 = b;
    rp = &p->unk10->unk1C[i];
    r = rp;
    p->unk34 = p->unk40 - r->unk0;
    p->unk38 = p->unk48 - r->unk8;
    func_8003B2CC(&p->unk14, q, q);
    if (p->unk38 > 0) {
        p->unk38 = 0;
    }
    res = func_800A39CC(q, (s32)p->unk3C, p);
    p->unk4 = res;
    if ((s16)res < 0) {
        return 1;
    }
    D_801027C4 = p->unk2;
    D_801027C8 = p->unk4;
    D_801028EC = p->unk63;
    return 0;
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A3E58);

s32 func_800A4144(u8 *arg0) {
    s32 r;

    r = func_800A39CC(arg0 + 0x34, *(s32 *)(arg0 + 0x3C), arg0);
    *(s16 *)(arg0 + 4) = r;
    if ((s16)r < 0) {
        return func_800A3CB4(arg0);
    }
    D_801027C8 = r;
    D_801028EC = arg0[0x63];
    return 0;
}

void func_800A41B0(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), u8 *, 4);
    func_800A41DC();
}

s32 func_800A41DC(arg0) {
    SbObjD *p;
    SbTbl *e;
    SbRec12 *r;
    s16 *q;
    u16 a;
    s32 b;
    s32 res;

    p = (SbObjD *)arg0;
    p->unk10 = &D_800D37D4[(s16)p->unk0];
    p->unk2 = 0;
    p->unk3C = (SbRecC *)(D_800C000C + *p->unk10->unk8 * 0x374);
    q = &p->unk34;
    e = (SbTbl *)(((-*p->unk10->unk18 & 0xFFF) << 2) + (u8 *)D_8004BC98);
    a = e->a;
    b = e->b;
    p->unk1C = 0x1000;
    p->unk16 = 0;
    p->unk1A = 0;
    p->unk1E = 0;
    p->unk22 = 0;
    p->unk18 = a;
    p->unk14 = b;
    p->unk20 = -a;
    p->unk24 = b;
    r = p->unk10->unk1C;
    p->unk34 = p->unk40 - r->unk0;
    p->unk38 = p->unk48 - r->unk8;
    func_8003B2CC(&p->unk14, q, q);
    res = func_800A39CC(q, (s32)p->unk3C, p);
    p->unk4 = res;
    if ((s16)res < 0) {
        return 1;
    }
    D_801028E0 = p->unk0;
    D_801027C4 = p->unk2;
    D_801027C8 = p->unk4;
    D_801028D4 = (u8 *)p->unk10;
    D_801028EC = p->unk63;
    return 0;
}

void func_800A435C(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), u8 *, 5);
    func_800A41DC();
}

s32 func_800A4388(u8 *arg0) {
    s32 r;

    r = func_800A39CC(arg0 + 0x34, *(s32 *)(arg0 + 0x3C), arg0);
    *(s16 *)(arg0 + 4) = r;
    if ((s16)r < 0) {
        *(s16 *)arg0 = (*(u8 **)(arg0 + 0x10))[4];
        return func_800A41DC(arg0);
    }
    D_801027C8 = r;
    D_801028EC = arg0[0x63];
    return 0;
}

s32 func_800A4404(u8 *arg0) {
    s32 r;

    r = func_800A39CC(arg0 + 0x34, *(s32 *)(arg0 + 0x3C), arg0);
    *(s16 *)(arg0 + 4) = r;
    if ((s16)r < 0) {
        *(s16 *)arg0 = (*(u8 **)(arg0 + 0x10))[5];
        return func_800A41DC(arg0);
    }
    D_801027C8 = r;
    D_801028EC = arg0[0x63];
    return 0;
}

s32 func_800A4480(void) {
    return 1;
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A4488);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A45AC);

s32 func_800A4728(SbPt3 *p, SbPt3 *a, SbPt3 *b, SbPt3 *c) {
    s16 y1;
    s16 z1;
    s32 nx;
    s32 ny;
    s32 nz;
    s32 x1;
    s32 t1;
    s32 t2;

    y1 = a->y;
    z1 = a->z;
    nx = (y1 - b->y) * (z1 - c->z) - (y1 - c->y) * (z1 - b->z);
    x1 = a->x;
    t1 = nx * (x1 - p->x);
    ny = (z1 - b->z) * (x1 - c->x) - (z1 - c->z) * (x1 - b->x);
    nz = (x1 - b->x) * (y1 - c->y) - (x1 - c->x) * (y1 - b->y);
    t2 = nz * (z1 - p->z);
    if (ny != 0) {
        ny = (t1 + t2) / ny;
    }
    return ny + y1;
}

s16 func_800A4818(void *arg0, void *arg1) {
    s16 d;

    d = M2C_FIELD(arg1, s16 *, 4);
    if (d > 0) {
        D_801028DC = -func_8003CC1C(M2C_FIELD(arg0, s16 *, 4), d + M2C_FIELD(arg0, s16 *, 0));
    } else if (d < 0) {
        D_801028DC = func_8003CC1C(M2C_FIELD(arg0, s16 *, 4), M2C_FIELD(arg1, s16 *, 0x38) - M2C_FIELD(arg0, s16 *, 0) - d);
    } else {
        D_801028DC = 0;
    }
    return M2C_FIELD(D_801028D4, s16 **, 0x18)[D_801027C4] + D_801028DC;
}

void func_800A48D4(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0) = func_8003CC1C((s32) -M2C_FIELD(arg0, s16 *, 4), (s32) M2C_FIELD(arg0, s16 *, 2));
    M2C_FIELD(arg1, s16 *, 2) = 0;
    M2C_FIELD(arg1, s16 *, 4) = func_8003CC1C((s32) M2C_FIELD(arg0, s16 *, 0), (s32) M2C_FIELD(arg0, s16 *, 2));
}

void func_800A4930(s32 arg0, s32 arg1, void *arg2, void *arg3) {
    u8 *base;
    u8 *idx;
    u8 *tbl;
    SbVtx8 *a;
    SbVtx8 *b;
    SbVtx8 *c;
    s32 rec;
    s32 ax, ay, az;
    s32 bx, by, bz;
    s32 cx, cy, cz;

    if (arg1 >= 0) {
        rec = M2C_FIELD(D_801028D4, u8 **, 8)[arg0] * 0x374;
        base = rec + D_800C0260;
        idx = base + arg1 * 4;
        tbl = rec + (D_800C0260 - 0x24C);
        a = (SbVtx8 *)(tbl + idx[0] * 8);
        b = (SbVtx8 *)(tbl + idx[1] * 8);
        c = (SbVtx8 *)(tbl + idx[2] * 8);
        by = b->y;
        bz = b->z;
        az = a->z;
        cy = c->y;
        ay = a->y;
        cz = c->z;
        bx = b->x;
        cx = c->x;
        ax = a->x;
        M2C_FIELD(arg3, s16 *, 0x10) = ((bz - az) * (cy - by) - (by - ay) * (cz - bz)) >> 3;
        M2C_FIELD(arg3, s16 *, 0x12) = ((bz - az) * (cx - bx) - (bx - ax) * (cz - bz)) >> 3;
        M2C_FIELD(arg3, s16 *, 0x14) = ((by - ay) * (cx - bx) - (bx - ax) * (cy - by)) >> 3;
        func_8003B2CC(D_80102820, (u8 *)arg3 + 0x10, arg2);
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A4A8C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A4D38);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A50B4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A5508);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A56C4);

void func_800A5848(SbObjB *p) {
    s32 dx;
    s32 dz;

    dx = (D_800DB1F8.v[0] >> 12) - D_8010284C;
    dz = (D_800DB200 >> 12) - D_80102854;
    p->unk10 = func_8003CC1C((D_800DB1FC >> 12) - D_80102850, func_80039F5C(dx * dx + dz * dz));
    p->unk12 = -func_8003CC1C(dx, dz);
    p->unk14 = 0;
    func_8003BF8C(&p->unk10, &p->unk40);
    p->unk40.v[5] = 0;
    p->unk40.v[6] = 0x60;
    p->unk40.v[7] = 0;
    D_801027F4 = p->unk40;
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A5964);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A5B3C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A5E80);

void func_800A61EC(s32 arg0, s32 arg1) {
    u8 *p;
    s32 h;

    arg0 |= (arg0 << 16) | (arg0 << 8);
    p = D_80102798;
    M2C_FIELD(p, s32 *, 0) = 0x03000000;
    M2C_FIELD(p, s32 *, 4) = arg0 | 0x62000000;
    M2C_FIELD(p, s32 *, 8) = 0xFF88FF60;
    M2C_FIELD(p, s32 *, 0xC) = 0xF00140;
    func_80046794(arg1, (s32)p);
    p += 0x10;
    if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
        h = 0x80;
    } else {
        h = 0x20;
    }
    func_80044A68(p, 1, 0, h, 0);
    func_80046794(arg1, (s32)p);
    D_80102798 = p + 0xC;
}

void func_800A62C4(s32 arg0, s32 arg1) {
    void *temp_s0;

    temp_s0 = D_80102798;
    M2C_FIELD(temp_s0, s32 *, 0) = 0x03000000;
    M2C_FIELD(temp_s0, s32 *, 4) = (s32) ((arg0 & 0xFFFFFF) | 0x61000000);
    M2C_FIELD(temp_s0, s32 *, 8) = 0xFF88FF60;
    M2C_FIELD(temp_s0, s32 *, 0xC) = 0xF00140;
    func_80046794(arg1, (s32) temp_s0);
    D_80102798 = temp_s0 + 0x10;
}

void func_800A633C(void) {
    if ((D_80102814 == 0) && (D_8010281C == 0x116)) {
        func_800A637C();
    }
}

void func_800A637C(void) {
    s32 a;

    s32 c;

    a = 0x1E - (s16) D_801027CC;
    if (a < 0) {
        a = 0;
    }
    D_8010279C = a;
    a = 0x1E - ((s32) (((((u32) D_801028D8 >> 0x10) & 0xF) + ((((u32) D_801028D8 >> 0x14) & 0xF) * 0xA) + ((((u32) D_801028D8 >> 0x18) & 0xF) * 0x3C) + (((u32) D_801028D8 >> 0x1C) * 0xE10)) - 0x78) >> 1);
    if (a >= 0x1F) {
        a = 0x1E;
    } else if (a < 0) {
        a = 0;
    }
    c = (s16) D_801027C0;
    D_8010279E = a;
    if (c >= 0x29) {
        c = 0x28;
    }
    D_801027A0 = c;
    D_80102814 = 1;
    D_801028F0 = 1;
    D_801027A2 = D_8010279C + a + c;
}

s32 func_800A6480(void) {
    s32 i;
    u8 *p;
    u8 op;
    s32 b;
    s32 c;

    goto test;
found:
        D_800FFC18 = D_800FFC24[i];
        D_800FFC20[i] = 0;
        D_800FFC1C[i] = 0;
        D_800D71A6 = 0;
    goto after;
test:
    i = 0;
    do {
        if (D_800FFC1C[i] != 0 && D_800FFC20[i] != 0) {
            goto found;
        }
        i++;
    } while (i < 4);
after:
    if (D_800D71A6 == 0) {
        while (1) {
            b = (u8)D_800DB1E0 << 8;
            c = (s16) D_800FFC18 * 4 + (s32)D_800D71D0;
            p = (u8 *)(b + c);
            op = *p;
            if (op >= 0xE) {
                break;
            }
            if (D_800DB28C[op](p) != 0) {
                break;
            }
        }
    }
    return func_800A6B20();
}

s32 func_800A65A8(void) {
    return 1;
}

s32 func_800A65B0(u8 *arg0) {
    D_800D71A8 = arg0[1];
    func_800A6968(0, arg0[2], arg0[3]);
    D_800FFC18 += 1;
    return 1;
}

s32 func_800A6600(u8 *arg0) {
    if (D_800FFC14 >= 3) {
        return 1;
    }
    D_800FFC14++;
    D_800FFC0C[D_800FFC14] = D_800FFC18 + 1;
    D_800FFC10[D_800FFC14] = arg0[1];
    D_800FFC18++;
    return 0;
}

s32 func_800A6690(void) {
    if (D_800FFC14 <= 0) {
        return 1;
    }
    if (D_800FFC10[D_800FFC14] != 0) {
        D_800FFC10[D_800FFC14]--;
        D_800FFC18 = D_800FFC0C[D_800FFC14];
    } else {
        D_800FFC14--;
        D_800FFC18++;
    }
    return 0;
}

s32 func_800A671C(void *arg0) {
    D_800FFC18 = (u16) M2C_FIELD(arg0, u8 *, 1);
    return 0;
}

s32 func_800A6730(u8 *arg0) {
    D_800FFC1C[arg0[1]] = 1;
    D_800FFC20[arg0[1]] = 0;
    D_800FFC24[arg0[1]] = arg0[2];
    D_800FFC18 += 1;
    return 0;
}

s32 func_800A6788(void) {
    return 1;
}

s32 func_800A6790(void *arg0) {
    D_800DB1E0 = (s16) M2C_FIELD(arg0, u8 *, 1);
    return 1;
}

s32 func_800A67A4(u8 *arg0) {
    s32 n;
    s32 t;

    t = arg0[1];
    do {
        n = D_800FFC18;
        D_800DB214 = 0x1000;
        D_800DB1E6 = 1;
        D_800DB20C = -t << 8;
        D_800FFC18 = ++n;
    } while (0);
    return 0;
}

s32 func_800A67EC(u8 *arg0) {
    u16 pad;

    pad = D_801027AC;
    if (arg0[2] != 0) {
        pad = ~pad;
    }
    if (pad & D_800DB2C4[arg0[1]]) {
        D_800FFC18 += 1;
        return 0;
    }
    return 1;
}

s32 func_800A6854(u8 *arg0) {
    if (D_800FFC28 != 0) {
        D_800FFC18 = arg0[D_800FFC28];
    } else {
        D_800FFC18 += 1;
    }
    return 0;
}

s32 func_800A6898(u8 *arg0) {
    D_800FFC1C[arg0[1]] = 0;
    D_800FFC18 += 1;
    return 0;
}

s32 func_800A68C8(void *arg0) {
    D_800FFC2C = M2C_FIELD(arg0, u8 *, 1);
    D_800FFC18 += 1;
    return 0;
}

s32 func_800A68F0(u8 *arg0) {
    D_8009A000 = arg0[1] + 0x27;
    D_8009A004 = arg0[3];
    D_8009A008 = D_800DB2D4[arg0[2]];
    func_8002DA7C();
    D_800FFC18 += 1;
    return 0;
}

void func_800A6968(s32 arg0, s32 arg1, s32 arg2) {
    s32 *d;
    s32 *s;
    s32 i;

    if (arg0 != 0) {
        D_800D71A8 += arg0;
        if ((s16)D_800D71A8 < 0) {
            D_800D71A8 = 0x74;
        }
        if ((s16)D_800D71A8 >= 0x75) {
            D_800D71A8 = 0;
        }
    }
    func_800A6AF8(D_800FFB14, D_80102860);
    d = (s32 *)D_800FFB88;
    s = D_800D39E4 + (s16)D_800D71A8 * 29;
    for (i = 0x1C; i != -1; i--) {
        *d++ = *s++;
    }
    *(SbBytes8 *)D_800FFB04 = *(SbBytes8 *)D_80102840;
    D_800FFB0C[0] = D_800D6EE8[(s16)D_800D71A8].a;
    D_800FFB0C[1] = D_800D6EE8[(s16)D_800D71A8].b;
    D_800FFB0C[2] = D_800D6EE8[(s16)D_800D71A8].c;
    D_800FFC00 = arg1;
    D_800D71A6 = arg1;
    D_800FFBFC = D_800D71AC[arg2];
}

void func_800A6AF8(s32 *arg0, s32 *arg1) {
    s32 i;

    for (i = 0x1C; i != -1; i--) {
        *arg0++ = *arg1++;
    }
}

s32 func_800A6B20() {
    s16 *p;
    s16 *q;
    s16 *dst;
    s16 n;
    s32 i;
    s32 t;

    n = D_800D71A6;
    if (n != 0) {
        n -= 1;
        D_800D71A6 = n;
        t = D_800FFBFC(((D_800FFC00 - n) << 12) / D_800FFC00);
        if (t < 0) {
            t = 0;
        } else if (t >= 0x1001) {
            t = 0x1000;
        }
        p = D_800FFB14;
        q = D_800FFB88;
        dst = D_80102860;
        for (i = 0x38; i != -1; i--) {
            *dst++ = *p + (((*q - *p) * t) >> 12);
            p++;
            q++;
        }
        p = D_800FFB04;
        q = D_800FFB0C;
        dst = D_80102840;
        for (i = 2; i != -1; i--) {
            *dst++ = *p + (((*q - *p) * t) >> 12);
            p++;
            q++;
        }
    }
}

s32 func_800A6C78(s32 arg0) {
    return arg0;
}

s32 func_800A6C80(s32 arg0) {
    return (s32) (func_80039A74(((arg0 >> 2) * 2) - 0x400) + 0x1000) >> 1;
}

s32 func_800A6CB0(s32 arg0) {
    return 0x1000 - func_80039A74((arg0 >> 2) + 0x400);
}

s32 func_800A6CDC(s32 arg0) {
    return -func_80039A74((arg0 >> 2) + 0x800);
}

void func_800A6D04(void) {
    D_800D71A6 = 0;
    D_800FFC04 = 0;
    D_800FFC08 = 0x7F;
}

void func_800A6D28(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    SbTbl *e;
    u8 *p;
    u8 *q;
    u8 *r;
    s16 *w;
    s32 i;
    s32 f;
    u16 ca;
    u16 cb;

    if (arg2 != 0) {
        f = 0;
        if (!(D_800DB1E0 & 0x8000)) {
            i = 0;
            D_800FFC18 = 0;
            D_800FFC14 = 0;
            D_800FFC28 = 0;
            D_800FFC2C = 0;
            D_800D71A6 = 0;
            D_800DB1D4 = 0;
        lp:
            D_800FFC1C[i] = 0;
            D_800FFC20[i] = 0;
            i++;
            f = 1;
            if (i < 4) {
                goto lp;
            }
            D_800DB1E2 = 0;
            *(u16 *)&D_800DB1E0 |= 0x8000;
        }
        w = &D_800DB1E0;
        p = (u8 *)w - 0xC;
        D_800DB2E4[*(u8 *)&D_800DB1E0](p, f, arg1);
        D_800DB1E2 += 1;
        func_800A8CB4(p);
    }
    q = (u8 *)arg1 + 0x40;
    func_8003C21C(&D_800DB238, q);
    e = &D_8004BC98[D_800DB24A & 0xFFF];
    ca = e->a;
    cb = e->b;
    M2C_FIELD(arg1, s16 *, 0x62) = 0;
    M2C_FIELD(arg1, s16 *, 0x66) = 0;
    M2C_FIELD(arg1, s16 *, 0x68) = 0x1000;
    M2C_FIELD(arg1, s16 *, 0x6A) = 0;
    M2C_FIELD(arg1, s16 *, 0x6E) = 0;
    M2C_FIELD(arg1, u16 *, 0x64) = ca;
    M2C_FIELD(arg1, u16 *, 0x60) = cb;
    M2C_FIELD(arg1, s16 *, 0x6C) = -ca;
    M2C_FIELD(arg1, u16 *, 0x70) = cb;
    func_8003A79C(q, (u8 *)arg1 + 0x60, q);
    r = (u8 *)&D_800DB238 + 0x34;
    func_8003A79C(q, D_800D71BC, r);
    D_800DB280 = M2C_FIELD(arg0, s16 *, 0);
    D_800DB284 = M2C_FIELD(arg0, s16 *, 2);
    D_800DB288 = M2C_FIELD(arg0, s16 *, 4);
    func_800A8E20(r, &D_801027F4);
    if (arg3 != 0) {
        func_800A6F2C(arg1);
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A6F2C);

void func_800A7284(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        D_800DB264 = 0;
        D_800DB262 = 0;
        D_800DB260 = 0;
    }
    func_800A6480();
}

void func_800A72C0(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x72) = 0;
    M2C_FIELD(arg0, s16 *, 0x66) = 0;
    D_800FFC28 = M2C_FIELD(arg0, s16 *, 0x14) < 0x100;
    func_800A6480();
    if ((D_801027B8 & 0x40) && (M2C_FIELD(arg0, s16 *, 0x12) < 8)) {
        M2C_FIELD(arg0, s16 *, 0xC) = func_800A79BC(arg0);
    } else if (D_801027AC & 0x8000) {
        if (M2C_FIELD(arg0, s16 *, 0x14) < 0x21) {
            M2C_FIELD(arg0, u16 *, 0x76) -= 0x20;
        } else {
            M2C_FIELD(arg0, s16 *, 0xC) = 0x11;
        }
    } else if (D_801027AC & 0x2000) {
        if (M2C_FIELD(arg0, s16 *, 0x14) < 0x21) {
            M2C_FIELD(arg0, u16 *, 0x76) += 0x20;
        } else {
            M2C_FIELD(arg0, s16 *, 0xC) = 0x12;
        }
    } else if ((D_801027AC & 0x4080) && (M2C_FIELD(arg0, s16 *, 0x14) >= 0x101)) {
        M2C_FIELD(arg0, s16 *, 0xC) = 0x16;
    } else if ((M2C_FIELD(arg0, s16 *, 0x14) < 0x100) && (D_801027AC & 0x1000)) {
        M2C_FIELD(arg0, s16 *, 0xC) = 2;
    }
    func_800A884C(arg0);
}

void func_800A7404(void *arg0, s32 arg1, void *arg2) {
    s32 *d;
    s32 *s;
    s32 i;
    s32 lim;
    s32 spd;
    s32 a;
    s32 v;
    s32 r;
    s32 w;
    u16 t;
    s16 h;

    if (arg1 != 0) {
        M2C_FIELD(arg0, s16 *, 0x72) = 0;
        M2C_FIELD(arg0, s16 *, 0x10) = 0;
        M2C_FIELD(arg0, s16 *, 0xA) = 0;
        d = (s32 *)D_800FFB14;
        s = D_800D5758;
        for (i = 0x1C; i != -1; i--) {
            *d++ = *s++;
        }
        *(SbBytes8 *)D_800FFB04 = *(SbBytes8 *)D_80102840;
    }
    if (D_801027AC & 0x8000) {
        if (D_801027AC & 0xC) {
            lim = 0x80;
        } else {
            lim = 0x20;
        }
    } else {
        lim = 0;
    }
    spd = 1;
    if (D_801027AC & 0xC) {
        spd = 2;
    }
    if (lim == 0) {
        spd <<= 1;
    }
    h = M2C_FIELD(arg0, s16 *, 0x10);
    a = h;
    if (a < lim) {
        M2C_FIELD(arg0, s16 *, 0x10) = h + spd;
        if (lim < M2C_FIELD(arg0, s16 *, 0x10)) {
            M2C_FIELD(arg0, s16 *, 0x10) = lim;
        }
    } else if (lim < a) {
        M2C_FIELD(arg0, s16 *, 0x10) = h - spd;
        if (M2C_FIELD(arg0, s16 *, 0x10) < 0) {
            M2C_FIELD(arg0, s16 *, 0x10) = 0;
        }
    }
    lim = M2C_FIELD(arg0, s16 *, 0x10);
    if (lim > 0x20) {
        M2C_FIELD(arg0, s16 *, 0x66) = (0x20 - lim) << 3;
        lim = 0x20;
    } else {
        M2C_FIELD(arg0, s16 *, 0x66) = 0;
    }
    func_800A87A0(D_800FFB14, D_800D4368, D_800FFB04, D_800D6F66, lim << 7);
    t = M2C_FIELD(arg0, u16 *, 0x10);
    if ((s16)t > 0x20) {
        M2C_FIELD(arg0, s16 *, 0xA) = M2C_FIELD(arg0, u16 *, 0xA) + ((s16)t >> 5);
    } else if (M2C_FIELD(arg0, s16 *, 0xA) != 0) {
        M2C_FIELD(arg0, s16 *, 0xA) = M2C_FIELD(arg0, s16 *, 0xA) - 1;
    }
    func_800A7A4C(arg0, -M2C_FIELD(arg0, s16 *, 0x10), arg2);
    func_800A884C(arg0);
    r = func_800A7BA0(arg0);
    if (r != 0) {
        w = 0x17;
        goto set;
    }
    if ((D_801027B8 & 0x40) && (M2C_FIELD(arg0, s16 *, 0x12) < 8)) {
        M2C_FIELD(arg0, s16 *, 0xC) = func_800A79BC(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s16 *, 0x10) == 0) {
        v = 1;
        if (D_801027AC & 0x2000) {
            v = 0x12;
        }
        M2C_FIELD(arg0, s16 *, 0xC) = v;
        return;
    }
    if ((D_801027AC & 0x4080) && (M2C_FIELD(arg0, s16 *, 0x14) >= 0x101)) {
        w = 0x16;
        goto set;
    }
    if ((M2C_FIELD(arg0, s16 *, 0x14) < 0x100) && (D_801027AC & 0x1000)) {
        w = 2;
set:
        M2C_FIELD(arg0, s16 *, 0xC) = w;
    }
}

void func_800A76E4(void *arg0, s32 arg1, void *arg2) {
    s32 *d;
    s32 *s;
    s32 i;
    s32 lim;
    s32 spd;
    s32 a;
    s32 v;
    s32 r;
    s32 w;
    u16 t;
    s16 h;

    if (arg1 != 0) {
        M2C_FIELD(arg0, s16 *, 0x72) = 0;
        M2C_FIELD(arg0, s16 *, 0x10) = 0;
        M2C_FIELD(arg0, s16 *, 0xA) = 0;
        d = (s32 *)D_800FFB14;
        s = D_800D5758;
        for (i = 0x1C; i != -1; i--) {
            *d++ = *s++;
        }
        *(SbBytes8 *)D_800FFB04 = *(SbBytes8 *)D_80102840;
    }
    if (D_801027AC & 0x2000) {
        if (D_801027AC & 0xC) {
            lim = 0x80;
        } else {
            lim = 0x20;
        }
    } else {
        lim = 0;
    }
    spd = 1;
    if (D_801027AC & 0xC) {
        spd = 2;
    }
    if (lim == 0) {
        spd <<= 1;
    }
    h = M2C_FIELD(arg0, s16 *, 0x10);
    a = h;
    if (a < lim) {
        M2C_FIELD(arg0, s16 *, 0x10) = h + spd;
        if (lim < M2C_FIELD(arg0, s16 *, 0x10)) {
            M2C_FIELD(arg0, s16 *, 0x10) = lim;
        }
    } else if (lim < a) {
        M2C_FIELD(arg0, s16 *, 0x10) = h - spd;
        if (M2C_FIELD(arg0, s16 *, 0x10) < 0) {
            M2C_FIELD(arg0, s16 *, 0x10) = 0;
        }
    }
    lim = M2C_FIELD(arg0, s16 *, 0x10);
    if (lim > 0x20) {
        M2C_FIELD(arg0, s16 *, 0x66) = (lim - 0x20) << 3;
        lim = 0x20;
    } else {
        M2C_FIELD(arg0, s16 *, 0x66) = 0;
    }
    func_800A87A0(D_800FFB14, D_800D42F4, D_800FFB04, D_800D6F60, lim << 7);
    t = M2C_FIELD(arg0, u16 *, 0x10);
    if ((s16)t > 0x20) {
        M2C_FIELD(arg0, s16 *, 0xA) = M2C_FIELD(arg0, u16 *, 0xA) + ((s16)t >> 5);
    } else if (M2C_FIELD(arg0, s16 *, 0xA) != 0) {
        M2C_FIELD(arg0, s16 *, 0xA) = M2C_FIELD(arg0, s16 *, 0xA) - 1;
    }
    func_800A7A4C(arg0, M2C_FIELD(arg0, s16 *, 0x10), arg2);
    func_800A884C(arg0);
    r = func_800A7BA0(arg0);
    if (r != 0) {
        w = 0x18;
        goto set;
    }
    if ((D_801027B8 & 0x40) && (M2C_FIELD(arg0, s16 *, 0x12) < 8)) {
        M2C_FIELD(arg0, s16 *, 0xC) = func_800A79BC(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s16 *, 0x10) == 0) {
        v = 1;
        if (D_801027AC & 0x8000) {
            v = 0x11;
        }
        M2C_FIELD(arg0, s16 *, 0xC) = v;
        return;
    }
    if ((D_801027AC & 0x4080) && (M2C_FIELD(arg0, s16 *, 0x14) >= 0x101)) {
        w = 0x16;
        goto set;
    }
    if ((M2C_FIELD(arg0, s16 *, 0x14) < 0x100) && (D_801027AC & 0x1000)) {
        w = 2;
set:
        M2C_FIELD(arg0, s16 *, 0xC) = w;
    }
}

s32 func_800A79BC(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x14) > 0x400) {
        if (D_801028EC & 8) {
            return 6;
        }
        if (M2C_FIELD(D_801028D4, u8 **, 0xC)[D_801027C4] & 1) {
            return 6;
        }
    }
    if (D_801027AC & 0x8000) {
        return 5;
    }
    if (D_801027AC & 0x2000) {
        return 4;
    }
    return 3;
}

void func_800A7A4C(void *arg0, s32 arg1, void *arg2) {
    s16 a;
    s16 r;
    s32 t;
    s32 w;
    u16 ca;
    u16 cb;
    SbTbl *e;

    a = M2C_FIELD(arg0, s16 *, 0x12);
    if (a < 0x19) {
        r = M2C_FIELD(arg0, s16 *, 0x14);
        t = (r * r) >> 15;
        arg1 = (arg1 * (0x180 - t)) / 384;
        if (a >= 9) {
            arg1 = (arg1 * (0x18 - a)) >> 4;
        }
        e = (SbTbl *)((arg1 & 0x3FFC) + (u8 *)D_8004BC98);
        ca = e->a;
        cb = e->b;
        M2C_FIELD(arg2, s16 *, 0x42) = 0;
        M2C_FIELD(arg2, s16 *, 0x46) = 0;
        M2C_FIELD(arg2, s16 *, 0x48) = 0x1000;
        M2C_FIELD(arg2, s16 *, 0x4A) = 0;
        M2C_FIELD(arg2, s16 *, 0x4E) = 0;
        M2C_FIELD(arg2, s16 *, 0x44) = ca;
        M2C_FIELD(arg2, s16 *, 0x40) = cb;
        M2C_FIELD(arg2, s16 *, 0x50) = cb;
        M2C_FIELD(arg2, s16 *, 0x4C) = -ca;
        func_8003AB84((u8 *)arg2 + 0x40, (u8 *)arg0 + 0x34, (u8 *)arg2 + 0x20);
        w = arg1 < 0 ? -arg1 : arg1;
        t = (0x4000 - ((t * w) >> 4)) >> 2;
        M2C_FIELD(arg0, s32 *, 0x34) = (t * M2C_FIELD(arg2, s32 *, 0x20)) >> 12;
        M2C_FIELD(arg0, s32 *, 0x3C) = (t * M2C_FIELD(arg2, s32 *, 0x28)) >> 12;
    }
}

s32 func_800A7BA0(void *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x14);
    return (0x8C - ((s32) (temp_v0 * temp_v0) >> 0x10)) < M2C_FIELD(arg0, s16 *, 0x10);
}

void func_800A7BC8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x66) = 0;
    func_800A6480();
    func_800A884C(arg0);
}

void func_800A7BFC(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x66) = 0;
    func_800A6480();
    func_800A884C(arg0);
}

void func_800A7C30(SbObjC *arg0, s32 arg1, void *arg2) {
    s32 v;
    s32 r;
    u16 ca;
    u16 cb;
    s32 a;
    SbTbl *e;
    u16 t;

    if (arg1 != 0) {
        a = 0x18;
        if (arg0->unkC == 8) {
            a = -0x18;
        }
        t = D_801027CC + 1;
        arg0->unk4 = a;
        arg0->unk66 = 0;
        arg0->unk72 = 0;
        arg0->unk34 >>= 1;
        arg0->unk3C >>= 1;
        D_801027CC = t;
    }
    if (D_801027AC & 0x8000) {
        v = -((func_80042DA8() & 0xF) + 4);
    } else if (D_801027AC & 0x2000) {
        v = (func_80042DA8() & 0xF) + 4;
    } else {
        v = 0;
    }
    e = &D_8004BC98[(v + (u16)arg0->unk4) & 0xFFF];
    ca = e->a;
    cb = e->b;
    M2C_FIELD(arg2, s16 *, 0x42) = 0;
    M2C_FIELD(arg2, s16 *, 0x46) = 0;
    M2C_FIELD(arg2, s16 *, 0x48) = 0x1000;
    M2C_FIELD(arg2, s16 *, 0x4A) = 0;
    M2C_FIELD(arg2, s16 *, 0x4E) = 0;
    M2C_FIELD(arg2, u16 *, 0x44) = ca;
    M2C_FIELD(arg2, u16 *, 0x40) = cb;
    M2C_FIELD(arg2, u16 *, 0x50) = cb;
    M2C_FIELD(arg2, s16 *, 0x4C) = -ca;
    func_8003AB84((s32)((u8 *)arg2 + 0x40), &arg0->unk34, &arg0->unk34);
    r = arg0->unk4;
    if (r != 0) {
        if (r > 0) {
            r -= 2;
        } else {
            r += 2;
        }
        arg0->unk4 = r;
    }
    func_800A6480();
    func_800A884C(arg0);
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A7D90);

void func_800A7F7C(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_SFIELD(arg0, s32 *, 0x34) = 0;
        M2C_SFIELD(arg0, s32 *, 0x3C) = 0;
        D_800FFC28 = (s8) D_800FFC30;
        M2C_SFIELD(arg0, s32 *, 0) = (s32) (M2C_SFIELD(arg0, s32 *, 0) | 1);
    }
    func_800A6480();
    if (D_800FFC2C != 0) {
        M2C_SFIELD(arg0, s16 *, 0x76) = func_800A8B20((s32) D_801027BC, M2C_SFIELD(arg0, s16 *, 0x76), 0x10);
    }
}

void func_800A7FFC(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(arg0, s32 *, 0x3C) = 0;
        M2C_FIELD(arg0, s32 *, 0x34) = 0;
        M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0) | 1);
    }
    D_800FFC28 = ((u32) D_801027AC >> 0xC) & 1;
    func_800A6480();
}

void func_800A8050(void *arg0, s32 arg1) {
    s32 t;
    s32 target;

    if (arg1 != 0) {
        M2C_FIELD(arg0, s16 *, 4) = 0;
        M2C_FIELD(arg0, s16 *, 0x10) = 0;
        M2C_FIELD(arg0, s16 *, 0x72) = 4;
    }
    t = M2C_FIELD(arg0, s16 *, 0x10);
    target = 0;
    if (D_801027AC & 0x4080) {
        target = (M2C_FIELD(arg0, s16 *, 4) == 0) << 5;
    }
    if (t < target) {
        t += 2;
    } else if (t > target) {
        t -= 2;
        if (t < 0) {
            t = 0;
        }
    }
    M2C_FIELD(arg0, s16 *, 0x10) = t;
    func_800A87A0(D_800D4280, D_800D4280 + 0x137C, D_800D6F5A, D_800D6F5A + 0x102, -func_80039A74((t << 5) + 0x800));
    if (M2C_FIELD(arg0, s16 *, 0x12) == 0) {
        M2C_FIELD(arg0, s32 *, 0x34) -= M2C_FIELD(arg0, s32 *, 0x34) >> 5;
        M2C_FIELD(arg0, s32 *, 0x3C) -= M2C_FIELD(arg0, s32 *, 0x3C) >> 5;
        func_800A884C(arg0);
    }
    if (M2C_FIELD(arg0, s16 *, 0x10) == 0) {
        M2C_FIELD(arg0, s16 *, 0xC) = 1;
        M2C_FIELD(arg0, s16 *, 0x72) = 0;
    }
}

void func_800A815C(SbObjH *arg0, s32 arg1, void *arg2) {
    s16 a;
    s16 r;
    s32 v;
    s32 t;
    s32 w;
    u16 ca;
    u16 cb;
    SbTbl *e;

    if (arg1 != 0) {
        arg0->unk4 = -0x80;
        arg0->unk6 = 0;
        arg0->unk8 = 0x40;
        arg0->unk66 = 0;
        arg0->unk72 = 0;
        D_801027CC += 1;
    }
    v = -arg0->unk10;
    a = arg0->unk12;
    if (a < 0x19) {
        r = arg0->unk14;
        t = (r * r) >> 15;
        v = (v * (0x180 - t)) / 384;
        if (a >= 9) {
            v = (v * (0x18 - a)) >> 4;
        }
        e = (SbTbl *)((v & 0x3FFC) + (u8 *)D_8004BC98);
        ca = e->a;
        cb = e->b;
        M2C_FIELD(arg2, s16 *, 0x42) = 0;
        M2C_FIELD(arg2, s16 *, 0x46) = 0;
        M2C_FIELD(arg2, s16 *, 0x48) = 0x1000;
        M2C_FIELD(arg2, s16 *, 0x4A) = 0;
        M2C_FIELD(arg2, s16 *, 0x4E) = 0;
        M2C_FIELD(arg2, s16 *, 0x44) = ca;
        M2C_FIELD(arg2, s16 *, 0x40) = cb;
        M2C_FIELD(arg2, s16 *, 0x50) = cb;
        M2C_FIELD(arg2, s16 *, 0x4C) = -ca;
        func_8003AB84((u8 *)arg2 + 0x40, (u8 *)arg0 + 0x34, (u8 *)arg2 + 0x20);
        w = v < 0 ? -v : v;
        t = (0x4000 - ((t * w) >> 4)) >> 2;
        arg0->unk34 = (t * M2C_FIELD(arg2, s32 *, 0x20)) >> 12;
        arg0->unk3C = (t * M2C_FIELD(arg2, s32 *, 0x28)) >> 12;
    }
    ((void (*)(void *, void *))func_800A848C)(arg0, arg2);
}

void func_800A82F4(SbObjH *arg0, s32 arg1, void *arg2) {
    s16 a;
    s16 r;
    s32 v;
    s32 t;
    s32 w;
    u16 ca;
    u16 cb;
    SbTbl *e;

    if (arg1 != 0) {
        arg0->unk4 = 0x80;
        arg0->unk6 = 0;
        arg0->unk8 = 0x40;
        arg0->unk66 = 0;
        arg0->unk72 = 0;
        D_801027CC += 1;
    }
    v = -arg0->unk10;
    a = arg0->unk12;
    if (a < 0x19) {
        r = arg0->unk14;
        t = (r * r) >> 15;
        v = (v * (0x180 - t)) / 384;
        if (a >= 9) {
            v = (v * (0x18 - a)) >> 4;
        }
        e = (SbTbl *)((v & 0x3FFC) + (u8 *)D_8004BC98);
        ca = e->a;
        cb = e->b;
        M2C_FIELD(arg2, s16 *, 0x42) = 0;
        M2C_FIELD(arg2, s16 *, 0x46) = 0;
        M2C_FIELD(arg2, s16 *, 0x48) = 0x1000;
        M2C_FIELD(arg2, s16 *, 0x4A) = 0;
        M2C_FIELD(arg2, s16 *, 0x4E) = 0;
        M2C_FIELD(arg2, s16 *, 0x44) = ca;
        M2C_FIELD(arg2, s16 *, 0x40) = cb;
        M2C_FIELD(arg2, s16 *, 0x50) = cb;
        M2C_FIELD(arg2, s16 *, 0x4C) = -ca;
        func_8003AB84((u8 *)arg2 + 0x40, (u8 *)arg0 + 0x34, (u8 *)arg2 + 0x20);
        w = v < 0 ? -v : v;
        t = (0x4000 - ((t * w) >> 4)) >> 2;
        arg0->unk34 = (t * M2C_FIELD(arg2, s32 *, 0x20)) >> 12;
        arg0->unk3C = (t * M2C_FIELD(arg2, s32 *, 0x28)) >> 12;
    }
    ((void (*)(void *, void *))func_800A848C)(arg0, arg2);
}

void func_800A848C(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x14) < 0x200) {
        M2C_FIELD(arg0, s16 *, 8) = 0;
    }
    if (M2C_FIELD(arg0, s16 *, 8) != 0) {
        if (M2C_FIELD(arg0, s16 *, 4) != M2C_FIELD(arg0, s16 *, 6)) {
            M2C_FIELD(arg0, s16 *, 6) += M2C_FIELD(arg0, s16 *, 4) >> 3;
        }
        M2C_FIELD(arg0, s16 *, 8) -= 1;
    } else if (M2C_FIELD(arg0, s16 *, 6) != 0) {
        M2C_FIELD(arg0, s16 *, 6) -= M2C_FIELD(arg0, s16 *, 4) >> 1;
    } else {
        D_800FFC21 = 1;
    }
    M2C_FIELD(arg0, s16 *, 0x76) += M2C_FIELD(arg0, s16 *, 6);
    func_800A6480();
}

void func_800A8554(void *arg0, s32 arg1) {
    s8 var_a0;

    if (arg1 != 0) {
        if (M2C_SFIELD(arg0, u8 *, 0xC) == 0xC) {
            M2C_SFIELD(arg0, s32 *, 0x34) = (s32) -M2C_SFIELD(arg0, s32 *, 0x34);
            M2C_SFIELD(arg0, s32 *, 0x3C) = (s32) -M2C_SFIELD(arg0, s32 *, 0x3C);
        }
        M2C_SFIELD(arg0, s16 *, 0x66) = 0;
        M2C_SFIELD(arg0, s16 *, 0x72) = 0;
        M2C_SFIELD(arg0, s32 *, 0x34) = (s32) ((s32) M2C_SFIELD(arg0, s32 *, 0x34) >> 1);
        M2C_SFIELD(arg0, s32 *, 0x3C) = (s32) ((s32) M2C_SFIELD(arg0, s32 *, 0x3C) >> 1);
        D_801027CC += 2;
        if (M2C_SFIELD(arg0, s16 *, 0x14) >= 0x501) {
            var_a0 = (D_80102958 % 3) + 1;
        } else {
            var_a0 = 0;
        }
        D_800FFC30 = var_a0;
    }
    if (D_800FFC2C != 0) {
        func_800A86A4(arg0);
    }
    func_800A6480();
    func_800A884C(arg0);
}

void func_800A864C(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_SFIELD(arg0, s16 *, 0x66) = 0;
        D_801027CC += 1;
    }
    func_800A86A4(arg0);
    func_800A6480();
    func_800A884C(arg0);
}

void func_800A86A4(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x12) < 5) {
        M2C_FIELD(arg0, s32 *, 0x34) -= M2C_FIELD(arg0, s32 *, 0x34) >> 5;
        M2C_FIELD(arg0, s32 *, 0x3C) -= M2C_FIELD(arg0, s32 *, 0x3C) >> 5;
        if (M2C_FIELD(arg0, s16 *, 0x14) < 0x180) {
            M2C_FIELD(arg0, s16 *, 0x72) = 3;
        }
        if ((D_800FFC28 == 0 && M2C_FIELD(arg0, s16 *, 0x14) < 0x100) || M2C_FIELD(arg0, s16 *, 0xE) > 0xF0) {
            M2C_FIELD(arg0, s16 *, 0x72) = 0;
            D_800FFC28 = 1;
        }
    }
}

void func_800A8740(void *arg0) {
    func_800A6480();
    if ((D_800FFC2C != 0) && (D_801027AC & 0x1000)) {
        M2C_FIELD(arg0, s16 *, 0xC) = 2;
    }
}

void func_800A8798(void) {
}

void func_800A87A0(s16 *arg0, s16 *arg1, s16 *arg2, s16 *arg3, s32 arg4) {
    s16 *p;
    s16 *q;
    s16 *dst;
    s32 i;

    p = arg0;
    q = arg1;
    dst = D_80102860;
    for (i = 0x38; i != -1; i--) {
        *dst++ = *p + (((*q - *p) * arg4) >> 12);
        p++;
        q++;
    }
    p = arg2;
    q = arg3;
    dst = D_80102840;
    for (i = 2; i != -1; i--) {
        *dst++ = *p + (((*q - *p) * arg4) >> 12);
        p++;
        q++;
    }
}

void func_800A884C(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x14) >= 0x80) {
        M2C_FIELD(arg0, s16 *, 0x76) = func_800A8B20(func_8003CC1C(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x3C)) + 0x800, M2C_FIELD(arg0, s16 *, 0x76), 0x10);
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A88A8);

void func_800A8A80(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x38) += M2C_FIELD(arg0, s32 *, 0x40);
    M2C_FIELD(arg0, s32 *, 0x28) += M2C_FIELD(arg0, s32 *, 0x38);
    if (M2C_FIELD(arg0, s32 *, 0x1C) >= 0 && M2C_FIELD(arg0, s32 *, 0x18) < M2C_FIELD(arg0, s32 *, 0x28)) {
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s32 *, 0x18);
        M2C_FIELD(arg0, s32 *, 0x40) = M2C_FIELD(arg0, s32 *, 0x38);
        M2C_FIELD(arg0, s32 *, 0x38) = 0;
        M2C_FIELD(arg0, s16 *, 0x12) = 0;
        D_800FFC20[0] = 1;
        if (M2C_FIELD(arg0, s32 *, 0x40) > 0x1000) {
            M2C_FIELD(arg0, s32 *, 0x40) -= 0x1000;
        } else {
            M2C_FIELD(arg0, s32 *, 0x40) = 0x1000;
        }
    } else {
        M2C_FIELD(arg0, s32 *, 0x40) = 0x1000;
        M2C_FIELD(arg0, s16 *, 0x12) += 1;
    }
}

s16 func_800A8B20(s32 arg0, s16 arg1, s32 arg2) {
    s32 d;

    d = (arg0 & 0xFFF) - (arg1 & 0xFFF);
    if (d < 0) {
        d += 0x1000;
    }
    if (d < 0x800) {
        if (arg2 < d) {
            d = arg2;
        }
    } else {
        d -= 0x1000;
        arg2 = -arg2;
        if (d < arg2) {
            d = arg2;
        }
    }
    return (arg1 + d) & 0xFFF;
}

void func_800A8B68(void *arg0, s32 arg1) {
    s32 idx;
    s16 a;
    u16 c;
    s16 d;

    a = M2C_FIELD(arg0, s16 *, 0x14);
    idx = M2C_FIELD(arg0, u8 *, 0xC) * 9;
    if (a >= 0x201) {
        idx += 1;
    }
    if (a >= 0x501) {
        idx += 1;
    }
    if (arg1 >= 0x201) {
        idx += 3;
    }
    if (arg1 >= 0x401) {
        idx += 3;
    }
    c = D_800DB3A4[idx];
    switch (c) {
    case 0xFF:
        break;
    case 0xFE:
        func_800A1300(3, 0x135, 0);
        M2C_FIELD(arg0, s32 *, 0x34) -= M2C_FIELD(arg0, s32 *, 0x34) >> 2;
        M2C_FIELD(arg0, s32 *, 0x3C) -= M2C_FIELD(arg0, s32 *, 0x3C) >> 2;
        break;
    case 8:
        d = *(u16 *)&D_801027C8;
        if ((s16)(d % 12) >= 7) {
            c += 1;
        }
    default:
        func_800A1300(3, 0xEF, 0);
        M2C_FIELD(arg0, s16 *, 0xC) = c;
    }
}

void func_800A8CB4(void *arg0) {
    u16 id;
    s16 vol;
    s32 t;

    id = 0;
    if (M2C_FIELD(arg0, s16 *, 0x12) < 9) {
        id = D_800DB4C4[M2C_FIELD(arg0, u8 *, 0xC)];
        if (D_800DB4C4[M2C_FIELD(arg0, u8 *, 0xC)] == 0xED) {
            if (D_801028EC & 4) {
                id = 0x105;
            }
        }
    }
    t = (s16)id;
    if (t != D_800FFC04) {
        D_800FFC04 = id;
        if (t == 0) {
            D_8009A000 = 0xA4;
            D_800FFC08 = 0;
            D_8009A004 = 1;
            D_8009A008 = 0;
        } else {
            D_8009A000 = 0x28;
            D_8009A004 = 0x40;
            D_8009A008 = t;
        }
        func_8002DA7C();
    }
    if (id != 0) {
        vol = M2C_FIELD(arg0, s16 *, 0x14) >> 3;
        if (vol >= 0x80) {
            vol = 0x7F;
        }
        if (vol != D_800FFC08) {
            D_800FFC08 = vol;
            D_8009A000 = 0xA0;
            D_8009A004 = vol;
            func_8002DA7C();
        }
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A8E20);

void func_800A9DB4(void) {
    func_80044A68(&D_800FFC34, 1, 0, func_8004656C(0, 0, 0x180, 0x100) & 0xFFFF, 0);
}

s32 func_800A9DFC(s32 *arg0, s32 arg1) {
    SbBcdU u;
    u32 t;
    u32 c;

    u.w = arg1;
    t = u.b.d0 + 7;
    if (t >= 10) {
        t = u.b.d0 - 3;
        c = 7;
    } else {
        c = 6;
    }
    u.b.d0 = t;
    t = u.b.d1 + c;
    c = 1;
    if (t >= 10) {
        t -= 10;
        c = 2;
    }
    u.b.d1 = t;
    u.b.d2 += c;
    if (u.b.d2 >= 10) {
        u.b.d2 -= 10;
        u.b.d3++;
        if (u.b.d3 >= 10) {
            u.b.d3 -= 10;
            u.b.d4++;
            if (u.b.d4 >= 10) {
                u.b.d4 -= 10;
                u.b.d5++;
                if (u.b.d5 >= 6) {
                    u.b.d5 -= 6;
                    u.b.d6++;
                    if (u.b.d6 >= 10) {
                        u.b.d6 -= 10;
                        u.b.d7++;
                        if (u.b.d7 >= 10) {
                            u.b.d7 = 0;
                        }
                    }
                }
            }
        }
    }
    *arg0 = u.w;
    return (s32)arg0;
}

void func_800A9FF8(u32 arg0, s32 arg1, s32 arg2) {
    SbPrim14 *p;
    s32 base;
    s32 i;
    u32 v;

    p = (SbPrim14 *)D_80102798;
    base = (arg2 << 16) | (arg1 & 0xFFFF);
    for (i = 0; i < 3; i++) {
        func_800AA15C(p++, D_800DBA48[i], D_800DBA50[i], base + D_800DBA5C[i]);
    }
    for (i = 0, v = arg0 >> 8; i < 6; i++, v = (s32)v >> 4) {
        func_800AA15C(p++, (v & 0xF) * 8, 8, base + D_800DBA3C[i]);
    }
    *(SbBlock12 *)p = D_800FFC34;
    M2C_SFIELD(p, s32 *, 0) = (M2C_SFIELD(p, s32 *, 0) & 0xFF000000) | (M2C_SFIELD(D_80102794, s32 *, 4) & 0xFFFFFF);
    D_80102798 = (u8 *)p + 0xC;
    M2C_SFIELD(D_80102794, s32 *, 4) = (M2C_SFIELD(D_80102794, s32 *, 4) & 0xFF000000) | ((s32)p & 0xFFFFFF);
}

void func_800AA15C(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_SFIELD(arg0, s32 *, 0) = 0x04000000;
    M2C_SFIELD(arg0, s32 *, 4) = 0x65000000;
    M2C_SFIELD(arg0, s32 *, 0xC) = (s32) (arg1 | 0x78400000);
    M2C_SFIELD(arg0, s32 *, 0x10) = (s32) ((arg2 & 0xFFFF) | 0xB0000);
    M2C_SFIELD(arg0, s32 *, 8) = arg3;
    M2C_SFIELD(arg0, s32 *, 0) = (s32) ((M2C_SFIELD(arg0, s32 *, 0) & 0xFF000000) | (M2C_SFIELD(D_80102794, s32 *, 4) & 0xFFFFFF));
    M2C_SFIELD(D_80102794, s32 *, 4) = (s32) ((M2C_SFIELD(D_80102794, s32 *, 4) & 0xFF000000) | ((s32) arg0 & 0xFFFFFF));
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AA1D0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AA44C);

u16 func_800AA574(u16 arg0) {
    s32 r;
    u16 *p;

    r = 0;
    p = D_800DBA64;
    while (arg0 != 0) {
        if (arg0 & 1) {
            r = func_800AA5E4(r, *p);
        }
        arg0 >>= 1;
        p++;
    }
    return r;
}

s32 func_800AA5E4(u16 arg0, u16 arg1) {
    s32 r;
    u16 carry;
    s16 sh;
    u16 d;

    r = 0;
    carry = 0;
    for (sh = 0; sh < 13; sh += 4) {
        carry += ((arg0 >> sh) & 0xF) + ((arg1 >> sh) & 0xF);
        d = carry;
        if (d >= 10) {
            d -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        r |= d << sh;
    }
    return (u16)r;
}

void func_800AA66C(void) {
    SbUnkFFC40 *p;
    s32 i;

    D_800FFD40 = 0;
    p = D_800FFC40;
    for (i = 7; i != -1; i--) {
        p->unk0 = 0;
        p++;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AA69C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AA7FC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AAB88);

void func_800AAE1C(SbRelocHdr *h) {
    SbRelocEnt *e;
    s32 n;
    u32 base;

    if (h->unk4 >= 0) {
        n = h->unk8;
        e = h->ents;
        base = (u32)e >> 2;
        while (--n != -1) {
            e->unk0 += base;
            e->unk8 += base;
            e->unk10 += base;
            e++;
        }
        h->unk4 |= 0x80000000;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AAE98);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AAFE8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AB154);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AB350);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AB5A0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AB7E4);

void func_800ABA64(void *arg0) {
    void (*var_v0)(void *);

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        D_80101190 = M2C_FIELD(arg0, u16 *, 2);
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFD8000;
            M2C_FIELD(arg0, s32 *, 0x6C) = (s32) M2C_FIELD(arg0, s32 *, 0x7C);
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x80);
            func_800A1300(3, 0xF0, 0);
            var_v0 = func_800ABAFC;
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
        } else {
            var_v0 = func_800ABB94;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = var_v0;
    }
}

void func_800ABAFC(void *arg0) {
    s32 y;

    y = M2C_FIELD(arg0, s32 *, 0x2C);
    if (M2C_FIELD(arg0, s32 *, 0x34) < y) {
        M2C_FIELD(arg0, s8 *, 0) = 0;
        return;
    }
    M2C_FIELD(arg0, u16 *, 2) = D_8010281C;
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) += M2C_FIELD(arg0, s32 *, 0x6C);
    M2C_FIELD(arg0, s32 *, 0x2C) += M2C_FIELD(arg0, s32 *, 0x70);
    M2C_FIELD(arg0, s32 *, 0x30) += M2C_FIELD(arg0, s32 *, 0x74);
    M2C_FIELD(arg0, s32 *, 0x70) += 0x1000;
    M2C_FIELD(arg0, u16 *, 0x1E) -= 0x20;
    if (M2C_FIELD(arg0, s32 *, 0x70) > 0) {
        M2C_FIELD(arg0, u16 *, 0x8A) += 1;
    }
}

void func_800ABB94(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

void func_800ABBE0(SbFxB *p) {
    s16 t;
    s32 lim;

    if (p->unk1 != 0) {
        D_80101190 = p->unk2;
        if (p->unk1 & 2) {
            p->unk6C = p->unk7C;
            p->unk70 = 0xFFFD8000;
            p->unk74 = p->unk80;
            func_800A1300(3, 0xF0, 0);
            p->unk14 = 0;
            p->unk38 = func_800ABAFC;
            return;
        }
        p->unk38 = func_800ABB94;
        return;
    }
    t = p->unk84;
    p->unk84 = t - 1;
    if (t < 0) {
        p->unk70 = -0x8000;
        p->unk84 = (func_80042DA8() & 0x1F) + 0x20;
    }
    lim = p->unk34;
    p->unk2C += p->unk70;
    p->unk70 += 0x1000;
    if (lim < p->unk2C) {
        p->unk2C = lim;
        p->unk70 = 0;
    }
}

void func_800ABCE4(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1300(3, 0xF0, 0);
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ABD74;
        } else {
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ABDFC;
        }
    }
    if ((M2C_FIELD(arg0, s16 *, 4) - 0xEA) == 2) {
        func_800ABE74(arg0);
    }
}

void func_800ABD74(void *arg0) {
    u16 temp_v0;
    u16 temp_v1;

    M2C_FIELD(arg0, s16 *, 0x1E) = (s16) ((s32) -func_80039A74(func_80039A74(M2C_FIELD(arg0, s16 *, 0x84) << 5) >> 4) >> 3);
    temp_v1 = (u16) M2C_FIELD(arg0, s16 *, 0x84);
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v1 + 1);
    if ((s16) temp_v1 >= 0x79) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0 + 1);
        if ((s16) temp_v0 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

void func_800ABDFC(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
    if ((M2C_FIELD(arg0, s16 *, 4) - 0xEA) == 2) {
        func_800ABE74(arg0);
    }
}

void func_800ABE74(void *arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x86);
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_v0 + 1);
    M2C_FIELD(arg0, s16 *, 0x22) = (s16) (func_80039A74(func_80039A74((s32) (temp_v0 << 0x10) >> 0xB) >> 4) >> 3);
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
}

void func_800ABEC8(void *arg0) {
    s16 temp_v1;
    u16 temp_v0;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x84);
    if (temp_v1 != 0) {
        M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v1 + 1);
        if (temp_v1 >= 0x3D) {
            temp_v0 = M2C_FIELD(arg0, u16 *, 0x8A);
            M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0 + 1);
            if ((s16) temp_v0 >= 0x1F) {
                M2C_FIELD(arg0, s8 *, 0) = 0;
            }
        }
    } else if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1300(2, 0x10C, 0);
        }
        M2C_FIELD(arg0, s16 *, 0x84) = 1;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ABF74);

void func_800AC218(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x29) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
            return;
        }
    }
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + M2C_FIELD(arg0, s32 *, 0x6C));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + M2C_FIELD(arg0, s32 *, 0x70));
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) + M2C_FIELD(arg0, s32 *, 0x74));
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) (M2C_FIELD(arg0, s32 *, 0x70) + 0x1000);
}

void func_800AC2A8(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

void func_800AC2F4(void *arg0) {
    s32 var_a0;
    u16 temp_v0;
    SbFxB *s;
    u16 t;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x86);
    var_a0 = temp_v0 & 0x1F;
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_v0 + 1);
    if (var_a0 >= 0x11) {
        var_a0 = 0x20 - var_a0;
    }
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (var_a0 << 7);
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1300(3, 0x189, 0);
            t = M2C_FIELD(arg0, u16 *, 4) + 1;
            M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFE0000;
            M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800AC458;
            M2C_FIELD(arg0, s32 *, 0x6C) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 0x7C) >> 1);
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 0x80) >> 1);
            M2C_FIELD(arg0, u16 *, 4) = t;
            s = (SbFxB *)0x1F800098;
            *s = *(SbFxB *)arg0;
            s->unk4 += 1;
            func_800AC598(s, 0, -0x300, s + 1);
            func_800AC598(s, 0x800, 0x300, s + 1);
            return;
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800AC518;
    }
}

void func_800AC458(void *arg0) {
    s32 var_a0;
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x86);
    var_a0 = temp_v0 & 0x1F;
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_v0 + 1);
    if (var_a0 >= 0x11) {
        var_a0 = 0x20 - var_a0;
    }
    M2C_FIELD(arg0, s32 *, 0x10) = var_a0 << 7;
    M2C_FIELD(arg0, s32 *, 0x2C) += M2C_FIELD(arg0, s32 *, 0x70);
    if (M2C_FIELD(arg0, s32 *, 0x34) < M2C_FIELD(arg0, s32 *, 0x2C)) {
        M2C_FIELD(arg0, s8 *, 0) = 0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x70) += 0x1000;
    M2C_FIELD(arg0, s32 *, 0x28) += M2C_FIELD(arg0, s32 *, 0x6C);
    M2C_FIELD(arg0, s32 *, 0x30) += M2C_FIELD(arg0, s32 *, 0x74);
    M2C_FIELD(arg0, u16 *, 0x1E) += 0x20;
    if (M2C_FIELD(arg0, s32 *, 0x70) > 0x8000) {
        M2C_FIELD(arg0, u16 *, 0x8A) += 1;
    }
}

void func_800AC518(void *arg0) {
    s32 var_a0;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
            return;
        }
    }
    temp_v0_3 = M2C_FIELD(arg0, u16 *, 0x86);
    var_a0 = temp_v0_3 & 0x1F;
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_v0_3 + 1);
    if (var_a0 >= 0x11) {
        var_a0 = 0x20 - var_a0;
    }
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (var_a0 << 7);
}

void func_800AC598(SbFxB *arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 a1 = arg1;
    SbFxB *p;
    SbFxB *s;
    SbTbl *e;
    u16 ca;
    u16 cb;
    s32 i;
    s32 n;

    n = 0x1F;
    i = D_80100F30;
    do {
        p = (SbFxB *)((u8 *)&D_800FFDB0 + i * 0x8C);
        if (*(u8 *)p == 0) {
            D_80100F30 = (i + 1) & 0x1F;
            s = p;
            goto found;
        }
        i = (i + 1) & 0x1F;
    } while (--n != -1);
    s = NULL;
found:
    if (s != NULL) {
        *s = *arg0;
        s->unk24 = 0;
        *(u16 *)&s->unk20 = a1 + *(u16 *)&s->unk20;
        e = &D_8004BC98[arg2 & 0xFFF];
        ca = e->a;
        cb = e->b;
        M2C_FIELD(arg3, s16 *, 0x42) = 0;
        M2C_FIELD(arg3, s16 *, 0x46) = 0;
        M2C_FIELD(arg3, s16 *, 0x48) = 0x1000;
        M2C_FIELD(arg3, s16 *, 0x4A) = 0;
        M2C_FIELD(arg3, s16 *, 0x4E) = 0;
        M2C_FIELD(arg3, u16 *, 0x44) = ca;
        M2C_FIELD(arg3, u16 *, 0x40) = cb;
        M2C_FIELD(arg3, u16 *, 0x50) = cb;
        M2C_FIELD(arg3, s16 *, 0x4C) = -ca;
        func_8003AB84((u8 *)arg3 + 0x40, &arg0->unk6C, (u8 *)arg3 + 0x20);
        s->unk6C = M2C_FIELD(arg3, s32 *, 0x20);
        s->unk74 = M2C_FIELD(arg3, s32 *, 0x28);
    }
}

void func_800AC704(void *arg0) {
    s32 var_a0;
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x86);
    var_a0 = temp_v0 & 0x1F;
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_v0 + 1);
    if (var_a0 >= 0x11) {
        var_a0 = 0x20 - var_a0;
    }
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (var_a0 << 7);
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1300(3, 0x189, 0);
            M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFE0000;
            M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800AC458;
            M2C_FIELD(arg0, s32 *, 0x6C) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 0x7C) >> 1);
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 0x80) >> 1);
            return;
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800AC518;
    }
}

void func_800AC7BC(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1300(2, 0x10C, 0);
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800AC820;
    }
}

void func_800AC820(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

void func_800AC86C(void *arg0) {
    s16 t;
    s32 y;
    s32 d;

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        M2C_FIELD(arg0, s8 *, 0) = 0;
        func_800A1300(3, 0xF9, 0);
        D_801027C0 += D_800DBD20[M2C_FIELD(arg0, s32 *, 0x3C)];
        return;
    }
    t = M2C_FIELD(arg0, s16 *, 0x84)++;
    M2C_FIELD(arg0, s16 *, 4) = ((t >> 3) & 3) + 0xF0;
    y = func_80039A74(t << 5) * 2 + M2C_FIELD(arg0, s32 *, 0x2C);
    d = (s16)D_80101190 - M2C_FIELD(arg0, s16 *, 2);
    M2C_FIELD(arg0, s32 *, 0x2C) = y;
    if ((d < 0 ? -d : d) < 2) {
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800AC950;
    }
}

void func_800AC950(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x88);
    M2C_FIELD(arg0, u16 *, 0x88) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x79) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
            return;
        }
    }
    temp_v0_3 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0_3 + 1);
    M2C_FIELD(arg0, s16 *, 4) = (s16) (((temp_v0_3 >> 3) & 3) + 0xF0);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + M2C_FIELD(arg0, s32 *, 0x70));
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) (M2C_FIELD(arg0, s32 *, 0x70) - 0x800);
}

void func_800AC9DC(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ACA48;
            func_800A1300(1, 0x10C, 0x7F);
            return;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ACAB8;
    }
}

void func_800ACA48(void *arg0) {
    u16 temp_a0;

    temp_a0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_a0 + 1);
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) + (func_80039A74((s32) (temp_a0 << 0x10) >> 0x11) >> 2));
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    if ((s16) M2C_FIELD(arg0, u16 *, 0x1E) >= 0x481) {
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ACAB8;
    }
}

void func_800ACAB8(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x86);
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

void func_800ACB04(SbFxB *p) {
    s32 d;
    s32 i;
    s32 k;
    void (*f)();

    if (p->unk1 != 0) {
        if (p->unk1 & 2) {
            f = func_800ACCFC;
            p->unk14 = 0;
        } else {
            f = func_800ACDE4;
        }
        p->unk38 = f;
    }
    i = p->unk48;
    p->unk28 += p->unk6C;
    p->unk30 += p->unk74;
    p->unk48 = i + 1;
    k = p->unk78;
    p->unk6 = D_800DBDBC[(i >> 1) % 6];
    d = p->unk3C[k] - p->unk28;
    d = d < 0 ? -d : d;
    if (d <= 0x7FFF) {
        p->unk78 = k ^ 1;
        p->unk44 = 0x10;
        p->unk38 = func_800ACC24;
        p->unk6C = -p->unk6C;
        p->unk74 = -p->unk74;
    }
}

void func_800ACC24(void *arg0) {
    s32 a;

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ACCFC;
        } else {
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ACDE4;
        }
    }
    a = M2C_FIELD(arg0, s16 *, 0x20);
    if (M2C_FIELD(arg0, s32 *, 0x78) != 0) {
        a -= 0x80;
    } else {
        a += 0x80;
    }
    M2C_FIELD(arg0, s16 *, 0x20) = a;
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, u16 *, 6) = D_800DBDBC[(M2C_FIELD(arg0, s32 *, 0x48)++ >> 1) % 6];
    if (--M2C_FIELD(arg0, s32 *, 0x44) == 0) {
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ACB04;
    }
}

void func_800ACCFC(SbFxA *p) {
    if (p->unk1 & 2) {
        p->unk1 = 0;
        p->unk6C = p->unk7C;
        p->unk70 = 0xFFFE0000;
        p->unk74 = p->unk80;
        func_800A1300(3, 0x135, 0);
        p->unk4 = 0x105;
        p->unk6 = 0x10B;
        D_80101190 = p->unk2;
    }
    p->unk2C += p->unk70;
    if (p->unk34 < p->unk2C) {
        p->unk0 = 0;
        return;
    }
    p->unk70 += 0x1000;
    p->unk28 += p->unk6C;
    p->unk30 += p->unk74;
    p->unk24 = 0;
    p->unk20 += 0x100;
    p->unk2 = D_8010281C;
}

void func_800ACDE4(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

void func_800ACE30(void *arg0) {
    if (D_800DB200 < M2C_FIELD(arg0, s32 *, 0x40)) {
        if (D_800DB1E8 >= 0x201) {
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ACE88;
            return;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800AD174;
    }
}

void func_800ACE88(SbFxB *p) {
    s32 d;
    s32 i;
    s32 dx;
    u16 t;
    void (*f)();

    if (p->unk1 != 0) {
        if (p->unk1 & 2) {
            f = func_800ACCFC;
            p->unk14 = 0;
        } else {
            f = func_800ACDE4;
        }
        p->unk38 = f;
    }
    i = p->unk48;
    p->unk28 += p->unk6C;
    p->unk30 += p->unk74;
    p->unk48 = i + 1;
    t = D_800DBDBC[(i >> 1) % 6];
    dx = p->unk3C[0] - p->unk28;
    d = dx;
    d = d < 0 ? -d : d;
    p->unk6 = t;
    if (d <= 0xFFFF) {
        p->unk6 = 0x106;
        p->unk38 = func_800ACF80;
        p->unk44 = 8;
    }
}

void func_800ACF80(void *arg0) {
    s32 a;

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ACCFC;
        } else {
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ACDE4;
        }
    }
    a = M2C_FIELD(arg0, s16 *, 0x20);
    if (M2C_FIELD(arg0, s32 *, 0x6C) > 0) {
        a -= 0x80;
    } else {
        a += 0x80;
    }
    M2C_FIELD(arg0, s16 *, 0x20) = a;
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, u16 *, 6) = D_800DBDBC[(M2C_FIELD(arg0, s32 *, 0x48)++ >> 1) % 6];
    if (--M2C_FIELD(arg0, s32 *, 0x44) == 0) {
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800AD068;
        M2C_FIELD(arg0, s32 *, 0x48) = 8;
        M2C_FIELD(arg0, s32 *, 0x44) = M2C_FIELD(arg0, s32 *, 0x2C);
    }
}

void func_800AD068(SbFxB *p) {
    s32 n;

    if (p->unk1 & 2) {
        p->unk14 = 0;
        p->unk38 = func_800ACCFC;
        return;
    }
    n = p->unk48;
    if (n > 0) {
        p->unk6 = 0x106;
        if (p->unk1 & 1) {
            p->unk38 = func_800ACDE4;
            return;
        }
    } else {
        if (n < 0) {
            p->unk6 = 0x10B;
            p->unk2C += p->unk70;
            p->unk70 += 0x1000;
            if (p->unk70 > 0) {
                if (p->unk2C >= p->unk44) {
                    p->unk2C = p->unk44;
                    p->unk48 = 0x10;
                }
            }
        } else if ((s16) D_80101190 == p->unk2) {
            p->unk38 = func_800AD1BC;
            p->unk44 = 0xE;
            p->unk48 = 0;
            D_80101190 = 0;
        } else {
            p->unk70 = -0x8000;
        }
    }
    p->unk48--;
}

void func_800AD174(void *arg0) {
    M2C_UNK *var_v0;

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            var_v0 = &func_800ACCFC;
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
        } else {
            var_v0 = &func_800ACDE4;
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x38) = var_v0;
    }
}

void func_800AD1BC(SbFxB *p) {
    s32 n;
    s32 a;
    void (*f)();

    if (p->unk1 != 0) {
        if (p->unk1 & 2) {
            f = func_800ACCFC;
            p->unk14 = 0;
        } else {
            f = func_800ACDE4;
        }
        p->unk38 = f;
    }
    n = p->unk44;
    p->unk44 = n - 1;
    if (n > 0) {
        a = p->unk20;
        if (p->unk6C > 0) {
            a += 0x80;
        } else {
            a -= 0x80;
        }
        p->unk20 = a;
        p->unk24 = 0;
        p->unk6 = D_800DBDBC[(p->unk48++ >> 1) % 6];
        return;
    }
    if (n >= -0xB3) {
        p->unk6 = 0x106;
        return;
    }
    p->unk4 = 0x105;
    p->unk44 = 0xC;
    p->unk38 = func_800ACF80;
}

void func_800AD2C0(s16 arg0, s16 arg1, SbVec3 *arg2, SbVec3 *arg3) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    i = D_80100F30;
    D_800DBE2C.h = arg1;
    n = 0x1F;
    D_800DBE34.x = arg2->x;
    D_800DBE34.y = arg2->y;
    D_800DBE34.z = arg2->z;

    do {
        p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
        if (p->flag == 0) {
            D_80100F30 = (i + 1) & 0x1F;
            s = p;
            goto found;
        }
        i = (i + 1) & 0x1F;
    } while (--n != -1);
    s = NULL;
found:
    if (s != NULL) {
        s->flag = 1;
        s->unk1 = 0;
        s->unk2 = arg0;
        s->unk4 = D_800DBE10;
        s->unk6C = 0;
        s->unk70 = 0;
        s->unk74 = 0;
        s->unk78 = 0;
        s->unk84 = 0;
        s->unk86 = 0;
        s->unk88 = 0;
        s->unk8A = 0;
    }
    s->unk6C = arg3->x;
    s->unk70 = arg3->y - 0x1000;
    s->unk74 = arg3->z;
}

void func_800AD3F8(SbFxB *p) {
    s16 t;
    s32 v;
    s32 y;

    t = p->unk84;
    p->unk84 = t + 1;
    if (t < 8) {
        p->unkC = 1;
        p->unk10 = (8 - p->unk84) << 7;
    } else {
        p->unkC = 0;
    }
    p->unk70 += 0x1000;
    p->unk2C += p->unk70;
    if (p->unk34 < p->unk2C) {
        p->unk38 = func_800AD4FC;
        p->unk84 = 0x3C;
    }
    if (p->unk86 == 0 && p->unk34 - 0x20000 < p->unk2C) {
        func_800A1300(3, 0x1AB, 0);
        p->unk86 = 1;
    }
    if (p->unk1 & 2) {
        func_800A1300(2, 0xF0, 0);
        p->unk1 = 0;
        p->unk14 = 0;
    }
}

void func_800AD4FC(void *arg0) {
    s16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x84);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v0 - 1);
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            func_800A1300(2, 0xF0, 0);
            M2C_FIELD(arg0, u8 *, 1) = 0U;
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
        }
    } else {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, s16 *, 0x14) = 0;
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

void func_800AD584(s16 arg0, s32 arg1, s16 arg2, SbVec4 *arg3) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg2 & 2) {
        D_800DBE58.unk34 = NULL;
        D_800DBE58.unk10 = 0;
    } else {
        D_800DBE58.unk34 = func_800BCD30;
    }
    n = 0x1F;
    D_800DBE58.unk0 = (arg2 & 1) + 0x10C;
    D_800DBE58.unk1C = arg1;
    D_800DBE58.unk24 = arg3->x;
    i = D_80100F30;
    D_800DBE58.unk28 = arg3->y - arg3->w;
    D_800DBE58.unk30 = arg3->y + 0x20000;
    D_800DBE58.unk2C = arg3->z;
    D_800DBE58.unk38 = (s16)arg2;
    do {
        p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
        if (p->flag == 0) {
            D_80100F30 = (i + 1) & 0x1F;
            s = p;
            goto found;
        }
        i = (i + 1) & 0x1F;
    } while (--n != -1);
    s = NULL;
found:
    if (s != NULL) {
        s->flag = 1;
        s->unk1 = 0;
        s->unk2 = arg0;
        s->unk4 = *(SbBlock48 *)&D_800DBE58;
        s->unk6C = 0;
        s->unk70 = 0;
        s->unk74 = 0;
        s->unk78 = 0;
        s->unk84 = 0;
        s->unk86 = 0;
        s->unk88 = 0;
        s->unk8A = 0;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AD70C);

void func_800AD8F0(s16 arg0, s32 arg1, s16 arg2, SbVec3 *arg3) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s32 x;

    x = 0xC0000;
    if (arg2 & 1) {
        x = -0xC0000;
    }
    D_800DBEA8.unk1C = arg1;
    D_800DBEA8.unk38 = x + arg3->x;
    D_800DBEA8.unk3C = arg3->y - 0x400000;
    D_800DBEA8.unk40 = x + arg3->z;
    D_800DBEA8.unk30 = arg3->y - 0x80000;
    if (arg2 & 2) {
        D_800DBEA8.unk44 = 0x68;
    } else {
        D_800DBEA8.unk44 = 0x90;
    }
    i = D_80100F30;
    n = 0x1F;
    do {
        p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
        if (p->flag == 0) {
            D_80100F30 = (i + 1) & 0x1F;
            s = p;
            goto found;
        }
        i = (i + 1) & 0x1F;
    } while (--n != -1);
    s = NULL;
found:
    if (s != NULL) {
        s->flag = 1;
        s->unk1 = 0;
        s->unk2 = arg0;
        s->unk4 = *(SbBlock48 *)&D_800DBEA8;
        s->unk6C = 0;
        s->unk70 = 0;
        s->unk74 = 0;
        s->unk78 = 0;
        s->unk84 = 0;
        s->unk86 = 0;
        s->unk88 = 0;
        s->unk8A = 0;
    }
    x = D_800DBEF0[arg2] << 12;
    s->unk8A = -1;
    s->unk6C = x;
    s->unk74 = x;
}

void func_800ADA8C(s16 arg0, s16 arg1, SbVec3 *arg2) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    n = 0x1F;
    D_800DBEF8.unk1C = D_800DBF70[arg1];
    D_800DBEF8.unk38 = arg2->x;
    i = D_80100F30;
    D_800DBEF8.unk3C = arg2->y - 0x80000;
    D_800DBEF8.unk40 = arg2->z;
    D_800DBEF8.unk44 = arg1;

    do {
        p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
        if (p->flag == 0) {
            D_80100F30 = (i + 1) & 0x1F;
            s = p;
            goto found;
        }
        do {
            i = (i + 1) & 0x1F;
        } while (0);
    } while (--n != -1);
    s = NULL;
found:
    if (s != NULL) {
        s->flag = 1;
        s->unk1 = 0;
        s->unk2 = arg0;
        s->unk4 = *(SbBlock48 *)&D_800DBEF8;
        s->unk6C = 0;
        s->unk70 = 0;
        s->unk74 = 0;
        s->unk78 = 0;
        s->unk84 = 0;
        s->unk86 = 0;
        s->unk88 = 0;
        s->unk8A = 0;
    }
    s->unk6C = D_800DBF40[arg1].x;
    s->unk70 = D_800DBF40[arg1].y;
    s->unk74 = D_800DBF40[arg1].z;
    s->unk8A = -1;
}

void func_800ADC20(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 2) - D_8010281C < 4) {
        if (--M2C_FIELD(arg0, s16 *, 0x84) != -1) {
            M2C_FIELD(arg0, s16 *, 0x8A) = -1;
            return;
        }
        M2C_FIELD(arg0, s16 *, 0x14) = 0xA0;
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s32 *, 0x3C);
        M2C_FIELD(arg0, s32 *, 0x2C) = M2C_FIELD(arg0, s32 *, 0x40);
        M2C_FIELD(arg0, s32 *, 0x30) = M2C_FIELD(arg0, s32 *, 0x44);
        M2C_FIELD(arg0, u16 *, 0x84) = D_800DBF78[M2C_FIELD(arg0, s32 *, 0x48) >> 1];
        M2C_FIELD(arg0, s16 *, 0x8A) = 0;
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ADCC0;
    }
}

void func_800ADCC0(SbFxB *p) {
    s16 t;

    if (p->unk1 != 0) {
        p->unk1 = 0;
        p->unk14 = 0;
        p->unk86 = 1;
        func_800A1300(2, 0xF0, 0);
    }
    t = p->unk84;
    p->unk84 = t - 1;
    if (t == 0) {
        if (p->unk86 != 0) {
            p->unk0 = 0;
        } else {
            p->unk1 = 0;
            p->unk38 = func_800ADC20;
            p->unk84 = (func_80042DA8() & 0x1F) + 8;
        }
    } else if (t < 0x10) {
        p->unk8A++;
    }
    p->unk28 += p->unk6C;
    p->unk2C += p->unk70;
    p->unk30 += p->unk74;

    p->unk1E += D_800DBF7C[p->unk48];
    p->unk24 = 0;
}

void func_800ADDD8(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        D_800DBCF4 = 0x800;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DBFD0;
        D_800DBD00 = D_800DBFD4 + 0xFFF60000;
        D_800DBD04 = D_800DBFD8;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800ADF34(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        D_800DBCF4 = 0xB42;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DBFE8;
        D_800DBD00 = D_800DBFEC + 0xFFF60000;
        D_800DBD04 = D_800DBFF0;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AE090(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        D_800DBCF4 = 0xB73;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DBFF4;
        D_800DBD00 = D_800DBFF8 + 0xFFF60000;
        D_800DBD04 = D_800DBFFC;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AE1EC(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        D_800DBCF4 = 0x772;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC000;
        D_800DBD00 = D_800DC004 + 0xFFF60000;
        D_800DBD04 = D_800DC008;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AE348(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEA;
        D_800DBAB4 = 0x43A;
        D_800DBACC = func_800ABA64;
        D_800DBABC = D_800DC00C;
        D_800DBAC8 = D_800DC010;
        D_800DBAC0 = D_800DC010;
        D_800DBAC4 = D_800DC014;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEA;
        D_800DBAB4 = 0x43A;
        D_800DBACC = func_800ABA64;
        D_800DBABC = D_800DC018;
        D_800DBAC8 = D_800DC01C;
        D_800DBAC0 = D_800DC01C;
        D_800DBAC4 = D_800DC020;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AE5E4(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        D_800DBCF4 = 0x41C;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC024;
        D_800DBD00 = D_800DC028 + 0xFFF60000;
        D_800DBD04 = D_800DC02C;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AE740(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    SbSlotA *xp;
    SbSlotA *xs;
    s32 xi;
    s32 xn;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;
    s16 id3;

    if (arg1 != 0) {
        id = arg0;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        xn = 0x1F;
        xi = D_80100F30;
        D_800DBCF4 = 0x41D;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC048;
        D_800DBD00 = D_800DC04C + 0xFFF60000;
        D_800DBD04 = D_800DC050;
        do {
            xp = (SbSlotA *)((u8 *)&D_800FFDB0 + xi * 0x8C);
            if (xp->flag == 0) {
                D_80100F30 = (xi + 1) & 0x1F;
                xs = xp;
                goto found;
            }
            xi = (xi + 1) & 0x1F;
        } while (--xn != -1);
        xs = NULL;
found:
        if (xs != NULL) {
            xs->flag = 1;
            xs->unk1 = 0;
            xs->unk2 = id;
            xs->unk4 = D_800DBCD8;
            xs->unk6C = 0;
            xs->unk70 = 0;
            xs->unk74 = 0;
            xs->unk78 = 0;
            xs->unk84 = 0;
            xs->unk86 = 0;
            xs->unk88 = 0;
            xs->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEA;
        D_800DBAB4 = 0x41D;
        D_800DBACC = func_800ABA64;
        D_800DBABC = D_800DC054;
        D_800DBAC8 = D_800DC058;
        D_800DBAC0 = D_800DC058;
        D_800DBAC4 = D_800DC05C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id3 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEA;
        D_800DBAB4 = 0x41D;
        D_800DBACC = func_800ABA64;
        D_800DBABC = D_800DC060;
        D_800DBAC8 = D_800DC064;
        D_800DBAC0 = D_800DC064;
        D_800DBAC4 = D_800DC068;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found3;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found3:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id3;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AEB2C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    SbSlotA *xp;
    SbSlotA *xs;
    s32 xi;
    s32 xn;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;
    s16 id3;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEA;
        D_800DBAB4 = 0x48D;
        D_800DBACC = func_800ABA64;
        D_800DBABC = D_800DC06C;
        D_800DBAC8 = D_800DC070;
        D_800DBAC0 = D_800DC070;
        D_800DBAC4 = D_800DC074;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEA;
        D_800DBAB4 = 0x48D;
        D_800DBACC = func_800ABA64;
        D_800DBABC = D_800DC078;
        D_800DBAC8 = D_800DC07C;
        D_800DBAC0 = D_800DC07C;
        D_800DBAC4 = D_800DC080;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id3 = arg0;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        xn = 0x1F;
        xi = D_80100F30;
        D_800DBCF4 = 0x48D;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC084;
        D_800DBD00 = D_800DC088 + 0xFFF60000;
        D_800DBD04 = D_800DC08C;
        do {
            xp = (SbSlotA *)((u8 *)&D_800FFDB0 + xi * 0x8C);
            if (xp->flag == 0) {
                D_80100F30 = (xi + 1) & 0x1F;
                xs = xp;
                goto found3;
            }
            xi = (xi + 1) & 0x1F;
        } while (--xn != -1);
        xs = NULL;
found3:
        if (xs != NULL) {
            xs->flag = 1;
            xs->unk1 = 0;
            xs->unk2 = id3;
            xs->unk4 = D_800DBCD8;
            xs->unk6C = 0;
            xs->unk70 = 0;
            xs->unk74 = 0;
            xs->unk78 = 0;
            xs->unk84 = 0;
            xs->unk86 = 0;
            xs->unk88 = 0;
            xs->unk8A = 0;
        }
    }
}

void func_800AEF18(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        D_800DBCF4 = 0x8C4;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC09C;
        D_800DBD00 = D_800DC0A0 + 0xFFF60000;
        D_800DBD04 = D_800DC0A4;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AF074(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        D_800DBCF4 = 0xC00;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC0A8;
        D_800DBD00 = D_800DC0AC + 0xFFF60000;
        D_800DBD04 = D_800DC0B0;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AF1D0(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        D_800DBCF4 = 0x858;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC0CC;
        D_800DBD00 = D_800DC0D0 + 0xFFF60000;
        D_800DBD04 = D_800DC0D4;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AF32C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEB;
        D_800DBAB4 = 0xE3A;
        D_800DBACC = func_800ABA64;
        D_800DBABC = D_800DC0D8;
        D_800DBAC8 = D_800DC0DC;
        D_800DBAC0 = D_800DC0DC;
        D_800DBAC4 = D_800DC0E0;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AF480(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEB;
        D_800DBAB4 = 0xD1C;
        D_800DBACC = func_800ABA64;
        D_800DBABC = D_800DC0E4;
        D_800DBAC8 = D_800DC0E8;
        D_800DBAC0 = D_800DC0E8;
        D_800DBAC4 = D_800DC0EC;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AF5D4(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEB;
        D_800DBAB4 = 0xC00;
        D_800DBACC = func_800ABA64;
        D_800DBABC = D_800DC0F0;
        D_800DBAC8 = D_800DC0F4;
        D_800DBAC0 = D_800DC0F4;
        D_800DBAC4 = D_800DC0F8;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AF728(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEB;
        D_800DBAB4 = 0xAE5;
        D_800DBACC = func_800ABA64;
        D_800DBABC = D_800DC0FC;
        D_800DBAC8 = D_800DC100;
        D_800DBAC0 = D_800DC100;
        D_800DBAC4 = D_800DC104;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AF87C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        D_800DBCF4 = 0x83A;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC108;
        D_800DBD00 = D_800DC10C + 0xFFF60000;
        D_800DBD04 = D_800DC110;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AF9D8(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        D_800DBCF4 = 0xEE5;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC114;
        D_800DBD00 = D_800DC118 + 0xFFF60000;
        D_800DBD04 = D_800DC11C;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AFB34(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCF4 = 0xA00;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC12C;
        D_800DBD00 = D_800DC130 + 0xFFF60000;
        D_800DBD04 = D_800DC134;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        D_800DBD10 = 1;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C40;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCF4 = 0xA00;
        D_800DBCFC = D_800DC138;
        D_800DBD00 = D_800DC13C + 0xFFF60000;
        D_800DBD04 = D_800DC140;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AFDE4(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        D_800DBD10 = 2;
        D_800DBCE4 = 0x02007C80;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCF4 = 0xA00;
        D_800DBCFC = D_800DC144;
        D_800DBD00 = D_800DC148 + 0xFFF60000;
        D_800DBD04 = D_800DC14C;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800AFF44(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        D_800DBCF4 = 0xA00;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC150;
        D_800DBD00 = D_800DC154 + 0xFFF60000;
        D_800DBD04 = D_800DC158;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B00A0(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        D_800DBCF4 = 0xA00;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC15C;
        D_800DBD00 = D_800DC160 + 0xFFF60000;
        D_800DBD04 = D_800DC164;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B01FC(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        D_800DBD10 = 1;
        D_800DBCE4 = 0x02007C40;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCF4 = 0xA00;
        D_800DBCFC = D_800DC168;
        D_800DBD00 = D_800DC16C + 0xFFF60000;
        D_800DBD04 = D_800DC170;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B035C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        D_800DBCF4 = 0xA00;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC174;
        D_800DBD00 = D_800DC178 + 0xFFF60000;
        D_800DBD04 = D_800DC17C;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B04B8(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBFA0 = 0xA00;
        *(u16 *)&D_800DBF84 = D_800DBFCC;
        D_800DBFA8 = D_800DC180;
        D_800DBFAC = D_800DC184;
        D_800DBFB0 = D_800DC188;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBF84;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBFA0 = 0xA00;
        *(u16 *)&D_800DBF84 = D_800DBFCC;
        D_800DBFA8 = D_800DC18C;
        D_800DBFAC = D_800DC190;
        D_800DBFB0 = D_800DC194;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBF84;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B072C(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s32 t;
    s16 id;
    s16 *w;

    if (arg1 != 0) {
        id = arg0;
        D_800DBD10 = 2;
        D_800DBCE4 = 0x02007C80;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCF4 = 0xA00;
        D_800DBCFC = D_800DC198;
        D_800DBD00 = D_800DC19C + 0xFFF60000;
        D_800DBD04 = D_800DC1A0;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (arg0 == D_8010281C && (u16)(D_801027C8 - 0x18) < 0x18 && *(u8 *)(w = &D_800DB1E0) != 0xA && *(u8 *)w != 0xC) {
        t = (D_800DB1EC - D_800DB1FC) >> 12;
        if (t >= 0x50) {
            if (t < 0x1C0) {
                *w = 0xC;
                goto block_19;
            }
            if (t < 0x1C8) {
                *w = 0xA;
block_19:
                func_800A1300(2, 0xF0, 0);
            }
        }
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0948);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0ACC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0C50);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0DF0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0F90);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B1134);

void func_800B12D8(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    SbVec3 *t;
    s32 i;
    s32 n;
    s32 a;
    s32 c;
    s32 new_var;
    s32 new_var2;
    SbTmplJ *g;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        t = &D_800D123C[arg0];
        g = (SbTmplJ *)&D_800DBCD8;
        D_800FFD88.x = (t->x + 0xD0) << 12;
        i = D_80100F30;
        a = (t->y - 0x133) << 12;
        D_800FFD88.y = a;
        new_var2 = t->z;
        g->unk38 = 1;
        g->unk0 = 0xF0;
        g->unk1C = 0xA00;
        new_var = (new_var2 - 0x7AC) << 12;
        g->unkC = 0x02007C40;
        g->unk28 = a + 0xFFF60000;
        c = new_var;
        g->unk24 = D_800FFD84.v;
        D_800FFD88.z = c;
        g->unk2C = c;
        n = 0x1F;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        g = (SbTmplJ *)&D_800DBAE0;
        n = 0x1F;
        i = D_80100F30;
        D_800FFD90 = (t->y + 0x14D) << 12;
        g->unk0 = 0xEB;
        g->unk1C = 0xA00;
        g->unk24 = D_800FFD84.v;
        g->unk28 = D_800FFD90;
        g->unk2C = D_800FFD94;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBAE0;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B15C4(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    SbVec3 *t;
    s32 i;
    s32 n;
    s32 a;
    s32 c;
    s32 new_var;
    s32 new_var2;
    SbTmplJ *g;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        t = &D_800D123C[arg0];
        g = (SbTmplJ *)&D_800DBCD8;
        D_800FFD88.x2 = (t->x + 0xD0) << 12;
        i = D_80100F30;
        a = (t->y - 0x173) << 12;
        D_800FFD88.y2 = a;
        new_var2 = t->z;
        g->unk38 = 2;
        g->unk0 = 0xF0;
        g->unk1C = 0xA00;
        new_var = (new_var2 - 0x7AC) << 12;
        g->unkC = 0x02007C80;
        g->unk28 = a + 0xFFF60000;
        c = new_var;
        g->unk24 = D_800FFD84.v3;
        D_800FFD88.z2 = c;
        g->unk2C = c;
        n = 0x1F;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        g = (SbTmplJ *)&D_800DBAE0;
        n = 0x1F;
        i = D_80100F30;
        D_800FFD9C = (t->y + 0x14D) << 12;
        g->unk0 = 0xEB;
        g->unk1C = 0xA00;
        g->unk24 = D_800FFD84.v3;
        g->unk28 = D_800FFD9C;
        g->unk2C = D_800FFDA0;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBAE0;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B18B0);

void func_800B1AE4(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCF4 = 0x600;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC210;
        D_800DBD00 = D_800DC214 + 0xFFF60000;
        D_800DBD04 = D_800DC218;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        func_800B18B0(arg0);
    }
}

void func_800B1C5C(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCF4 = 0x600;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC21C;
        D_800DBD00 = D_800DC220 + 0xFFF60000;
        D_800DBD04 = D_800DC224;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        func_800B18B0(arg0);
    }
}

void func_800B1DD4(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCF4 = 0x600;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC228;
        D_800DBD00 = D_800DC22C + 0xFFF60000;
        D_800DBD04 = D_800DC230;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        func_800B18B0(arg0);
    }
}

void func_800B1F4C(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCF4 = 0x600;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC234;
        D_800DBD00 = D_800DC238 + 0xFFF60000;
        D_800DBD04 = D_800DC23C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        func_800B18B0(arg0);
    }
}

void func_800B20C4(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCF4 = 0x600;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC240;
        D_800DBD00 = D_800DC244 + 0xFFF60000;
        D_800DBD04 = D_800DC248;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        func_800B18B0(arg0);
    }
}

void func_800B223C(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCF4 = 0x600;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC24C;
        D_800DBD00 = D_800DC250 + 0xFFF60000;
        D_800DBD04 = D_800DC254;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        func_800B18B0(arg0);
    }
}

void func_800B23B4(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    SbSlotA *xp;
    SbSlotA *xs;
    s32 xi;
    s32 xn;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;
    s16 id3;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0xA00;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DC258;
        D_800DBAC8 = D_800DC25C;
        D_800DBAC0 = D_800DC25C;
        D_800DBAC4 = D_800DC260;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0xA00;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DC264;
        D_800DBAC8 = D_800DC268;
        D_800DBAC0 = D_800DC268;
        D_800DBAC4 = D_800DC26C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id3 = arg0;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C00;
        xn = 0x1F;
        xi = D_80100F30;
        D_800DBCF4 = 0xA00;
        D_800DBD10 = 0;
        D_800DBCFC = D_800DC270;
        D_800DBD00 = D_800DC274 + 0xFFF60000;
        D_800DBD04 = D_800DC278;
        do {
            xp = (SbSlotA *)((u8 *)&D_800FFDB0 + xi * 0x8C);
            if (xp->flag == 0) {
                D_80100F30 = (xi + 1) & 0x1F;
                xs = xp;
                goto found3;
            }
            xi = (xi + 1) & 0x1F;
        } while (--xn != -1);
        xs = NULL;
found3:
        if (xs != NULL) {
            xs->flag = 1;
            xs->unk1 = 0;
            xs->unk2 = id3;
            xs->unk4 = D_800DBCD8;
            xs->unk6C = 0;
            xs->unk70 = 0;
            xs->unk74 = 0;
            xs->unk78 = 0;
            xs->unk84 = 0;
            xs->unk86 = 0;
            xs->unk88 = 0;
            xs->unk8A = 0;
        }
    }
}

void func_800B27A0(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0xDC5;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DC27C;
        D_800DBAC8 = D_800DC280;
        D_800DBAC0 = D_800DC280;
        D_800DBAC4 = D_800DC284;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B28F4(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    SbSlotA *xp;
    SbSlotA *xs;
    s32 xi;
    s32 xn;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;
    s16 id3;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0xE45;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DC288;
        D_800DBAC8 = D_800DC28C;
        D_800DBAC0 = D_800DC28C;
        D_800DBAC4 = D_800DC290;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0xE45;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DC294;
        D_800DBAC8 = D_800DC298;
        D_800DBAC0 = D_800DC298;
        D_800DBAC4 = D_800DC29C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id3 = arg0;
        D_800DBD10 = 1;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCE4 = 0x02007C40;
        xn = 0x1F;
        xi = D_80100F30;
        D_800DBCF4 = 0xE28;
        D_800DBCFC = D_800DC2A0;
        D_800DBD00 = D_800DC2A4 + 0xFFF60000;
        D_800DBD04 = D_800DC2A8;
        do {
            xp = (SbSlotA *)((u8 *)&D_800FFDB0 + xi * 0x8C);
            if (xp->flag == 0) {
                D_80100F30 = (xi + 1) & 0x1F;
                xs = xp;
                goto found3;
            }
            xi = (xi + 1) & 0x1F;
        } while (--xn != -1);
        xs = NULL;
found3:
        if (xs != NULL) {
            xs->flag = 1;
            xs->unk1 = 0;
            xs->unk2 = id3;
            xs->unk4 = D_800DBCD8;
            xs->unk6C = 0;
            xs->unk70 = 0;
            xs->unk74 = 0;
            xs->unk78 = 0;
            xs->unk84 = 0;
            xs->unk86 = 0;
            xs->unk88 = 0;
            xs->unk8A = 0;
        }
    }
}

void func_800B2CE4(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0 && D_801027A2 >= 0x3D) {
        id = arg0;
        D_800DBD10 = 3;
        D_800DBCE4 = 0x02007CC0;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCF4 = 0xBE3;
        D_800DBCFC = D_800DC2B8;
        D_800DBD00 = D_800DC2BC + 0xFFF60000;
        D_800DBD04 = D_800DC2C0;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B2E5C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC2C4;
        D_800DBCB8 = D_800DC2C8;
        D_800DBCBC = D_800DC2CC;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC2D0;
        D_800DBCB8 = D_800DC2D4;
        D_800DBCBC = D_800DC2D8;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B30B0(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC390;
        D_800DBCB8 = D_800DC394;
        D_800DBCBC = D_800DC398;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC39C;
        D_800DBCB8 = D_800DC3A0;
        D_800DBCBC = D_800DC3A4;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B3304(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC3A8;
        D_800DBCB8 = D_800DC3AC;
        D_800DBCBC = D_800DC3B0;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC3B4;
        D_800DBCB8 = D_800DC3B8;
        D_800DBCBC = D_800DC3BC;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B3558(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC3C0;
        D_800DBCB8 = D_800DC3C4;
        D_800DBCBC = D_800DC3C8;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC3CC;
        D_800DBCB8 = D_800DC3D0;
        D_800DBCBC = D_800DC3D4;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B37AC(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        func_800ADA8C(arg0, 3, &D_800DC3FC);
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC3E4;
        D_800DBCB8 = D_800DC3E8;
        D_800DBCBC = D_800DC3EC;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC3F0;
        D_800DBCB8 = D_800DC3F4;
        D_800DBCBC = D_800DC3F8;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B3A38(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC480;
        D_800DBCB8 = D_800DC484;
        D_800DBCBC = D_800DC488;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC48C;
        D_800DBCB8 = D_800DC490;
        D_800DBCBC = D_800DC494;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B3C8C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC498;
        D_800DBCB8 = D_800DC49C;
        D_800DBCBC = D_800DC4A0;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC4A4;
        D_800DBCB8 = D_800DC4A8;
        D_800DBCBC = D_800DC4AC;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B3EE0(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC4B0;
        D_800DBCB8 = D_800DC4B4;
        D_800DBCBC = D_800DC4B8;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        func_800ADA8C(arg0, 3, &D_800DC4BC);
        func_800ADA8C(arg0, 2, &D_800DC4BC + 3);
    }
}

void func_800B4064(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC4D4;
        D_800DBCB8 = D_800DC4D8;
        D_800DBCBC = D_800DC4DC;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC4E0;
        D_800DBCB8 = D_800DC4E4;
        D_800DBCBC = D_800DC4E8;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B42B8(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC4EC;
        D_800DBCB8 = D_800DC4F0;
        D_800DBCBC = D_800DC4F4;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC4F8;
        D_800DBCB8 = D_800DC4FC;
        D_800DBCBC = D_800DC500;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B450C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBD90 = 0xA38;
        D_800DBD98 = D_800DC504;
        D_800DBD9C = D_800DC508;
        D_800DBDA4 = D_800DC508 + 0x600000;
        D_800DBDA0 = D_800DC50C;
        D_800DBDAC = D_800DC510;
        D_800DBDB0 = D_800DC514;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBD74;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        *(s32 *)((u8 *)s + 0x6C) = D_800DC518;
        *(s32 *)((u8 *)s + 0x74) = D_800DC51C;
        *(s32 *)((u8 *)s + 0x78) = D_800DC520;
    }
}

void func_800B469C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBD90 = 0x1238;
        D_800DBD98 = D_800DC524;
        D_800DBD9C = D_800DC528;
        D_800DBDA4 = D_800DC528 + 0x600000;
        D_800DBDA0 = D_800DC52C;
        D_800DBDAC = D_800DC530;
        D_800DBDB0 = D_800DC534;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBD74;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        *(s32 *)((u8 *)s + 0x6C) = D_800DC538;
        *(s32 *)((u8 *)s + 0x74) = D_800DC53C;
        *(s32 *)((u8 *)s + 0x78) = D_800DC540;
    }
}

void func_800B482C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBD90 = 0xA38;
        D_800DBD98 = D_800DC544;
        D_800DBD9C = D_800DC548;
        D_800DBDA4 = D_800DC548 + 0x600000;
        D_800DBDA0 = D_800DC54C;
        D_800DBDAC = D_800DC550;
        D_800DBDB0 = D_800DC554;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBD74;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        *(s32 *)((u8 *)s + 0x6C) = D_800DC558;
        *(s32 *)((u8 *)s + 0x74) = D_800DC55C;
        *(s32 *)((u8 *)s + 0x78) = D_800DC560;
    }
}

void func_800B49BC(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBD90 = 0x1238;
        D_800DBD98 = D_800DC564;
        D_800DBD9C = D_800DC568;
        D_800DBDA4 = D_800DC568 + 0x600000;
        D_800DBDA0 = D_800DC56C;
        D_800DBDAC = D_800DC570;
        D_800DBDB0 = D_800DC574;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBD74;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        *(s32 *)((u8 *)s + 0x6C) = D_800DC578;
        *(s32 *)((u8 *)s + 0x74) = D_800DC57C;
        *(s32 *)((u8 *)s + 0x78) = D_800DC580;
    }
}

void func_800B4B4C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBD90 = 0xA38;
        D_800DBD98 = D_800DC584;
        D_800DBD9C = D_800DC588;
        D_800DBDA4 = D_800DC588 + 0x600000;
        D_800DBDA0 = D_800DC58C;
        D_800DBDAC = D_800DC590;
        D_800DBDB0 = D_800DC594;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBD74;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        *(s32 *)((u8 *)s + 0x6C) = D_800DC598;
        *(s32 *)((u8 *)s + 0x74) = D_800DC59C;
        *(s32 *)((u8 *)s + 0x78) = D_800DC5A0;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B4CDC);

void func_800B4FE4(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBDE4 = 0xD8E;
        D_800DBDEC = D_800DC5FC;
        D_800DBDF0 = D_800DC600;
        D_800DBDF8 = D_800DC600 + 0x600000;
        D_800DBDF4 = D_800DC604;
        D_800DBE00 = D_800DC608;
        D_800DBE04 = D_800DC60C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBDC8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        *(s32 *)((u8 *)s + 0x6C) = D_800DC610;
        *(s32 *)((u8 *)s + 0x74) = D_800DC614;
    }
}

void func_800B5164(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBDE4 = 0x58E;
        D_800DBDEC = D_800DC624;
        D_800DBDF0 = D_800DC628;
        D_800DBDF8 = D_800DC628 + 0x600000;
        D_800DBDF4 = D_800DC62C;
        D_800DBE00 = D_800DC630;
        D_800DBE04 = D_800DC634;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBDC8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        *(s32 *)((u8 *)s + 0x6C) = D_800DC638;
        *(s32 *)((u8 *)s + 0x74) = D_800DC63C;
    }
}

void func_800B52E4(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;
    s32 tc;
    s32 t6;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBDE4 = 0xD8E;
        D_800DBDEC = D_800DC658;
        D_800DBDF0 = D_800DC65C;
        D_800DBDF8 = D_800DC65C + 0x600000;
        D_800DBDF4 = D_800DC660;
        D_800DBE00 = D_800DC664;
        D_800DBE04 = D_800DC668;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBDC8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        i = D_80100F30;
        t6 = D_800DC66C;
        tc = D_800DC674;
        *(s32 *)((u8 *)s + 0x6C) = t6;
        *(s32 *)((u8 *)s + 0x74) = D_800DC670;
        id2 = arg0;
        n = 0x1F;
        D_800DBDE4 = 0xD8E;
        D_800DBDEC = tc;
        D_800DBDF0 = D_800DC678;
        D_800DBDF8 = D_800DC678 + 0x600000;
        D_800DBDF4 = D_800DC67C;
        D_800DBE00 = D_800DC680;
        D_800DBE04 = D_800DC684;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBDC8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        *(s32 *)((u8 *)s + 0x6C) = D_800DC688;
        *(s32 *)((u8 *)s + 0x74) = D_800DC68C;
    }
}

void func_800B55D0(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC69C;
        D_800DBB98 = D_800DC6A0;
        D_800DBB9C = D_800DC6A4;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC6A8;
        D_800DBB98 = D_800DC6AC;
        D_800DBB9C = D_800DC6B0;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B5824(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;
    s32 tc;
    s32 t6;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBDE4 = 0x58E;
        D_800DBDEC = D_800DC6B4;
        D_800DBDF0 = D_800DC6B8;
        D_800DBDF8 = D_800DC6B8 + 0x600000;
        D_800DBDF4 = D_800DC6BC;
        D_800DBE00 = D_800DC6C0;
        D_800DBE04 = D_800DC6C4;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBDC8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        i = D_80100F30;
        t6 = D_800DC6C8;
        tc = D_800DC6D0;
        *(s32 *)((u8 *)s + 0x6C) = t6;
        *(s32 *)((u8 *)s + 0x74) = D_800DC6CC;
        id2 = arg0;
        n = 0x1F;
        D_800DBDE4 = 0xD8E;
        D_800DBDEC = tc;
        D_800DBDF0 = D_800DC6D4;
        D_800DBDF8 = D_800DC6D4 + 0x600000;
        D_800DBDF4 = D_800DC6D8;
        D_800DBE00 = D_800DC6DC;
        D_800DBE04 = D_800DC6E0;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBDC8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        *(s32 *)((u8 *)s + 0x6C) = D_800DC6E4;
        *(s32 *)((u8 *)s + 0x74) = D_800DC6E8;
    }
}

void func_800B5B10(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC71C;
        D_800DBB98 = D_800DC720;
        D_800DBB9C = D_800DC724;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC728;
        D_800DBB98 = D_800DC72C;
        D_800DBB9C = D_800DC730;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B5D64(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;
    s32 tc;
    s32 t6;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBDE4 = 0xD8E;
        D_800DBDEC = D_800DC734;
        D_800DBDF0 = D_800DC738;
        D_800DBDF8 = D_800DC738 + 0x600000;
        D_800DBDF4 = D_800DC73C;
        D_800DBE00 = D_800DC740;
        D_800DBE04 = D_800DC744;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBDC8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        i = D_80100F30;
        t6 = D_800DC748;
        tc = D_800DC750;
        *(s32 *)((u8 *)s + 0x6C) = t6;
        *(s32 *)((u8 *)s + 0x74) = D_800DC74C;
        id2 = arg0;
        n = 0x1F;
        D_800DBDE4 = 0x58E;
        D_800DBDEC = tc;
        D_800DBDF0 = D_800DC754;
        D_800DBDF8 = D_800DC754 + 0x600000;
        D_800DBDF4 = D_800DC758;
        D_800DBE00 = D_800DC75C;
        D_800DBE04 = D_800DC760;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBDC8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        *(s32 *)((u8 *)s + 0x6C) = D_800DC764;
        *(s32 *)((u8 *)s + 0x74) = D_800DC768;
    }
}

void func_800B6050(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0 && D_801027A2 >= 0x51) {
        id = arg0;
        D_800DBD10 = 3;
        D_800DBCE4 = 0x02007CC0;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCF4 = 0x955;
        D_800DBCFC = D_800DC76C;
        D_800DBD00 = D_800DC770 + 0xFFF60000;
        D_800DBD04 = D_800DC774;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B61C8(void) {
    s32 var_v1;

    var_v1 = D_800DB20C;
    D_800DB1E0 = 0xB;
    if (var_v1 < 0) {
        var_v1 = -var_v1;
    }
    if (var_v1 <= 0x3FFFF) {
        var_v1 = 0x40000;
    }
    D_800DB20C = var_v1;
    func_800A1300(2, 0x10C, 0);
}

void func_800B6228(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s32 x;
    s32 y;
    s32 z;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xF8;
        D_800DBBD4 = 0xD1C;
        x = D_800DC778;
        z = D_800DC780;
        y = D_800DC77C;
        D_800DBBE0 = y;
        D_800DBBDC = x;
        D_800DBBE4 = z;
        D_800DBBE8 = y + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0 && (u8)D_800DB1E0 != 0xB && ((D_800DB1EC - D_800DB1FC) >> 12) > 0x240) {
        func_800B61C8();
    }
}

void func_800B63E0(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFB;
        D_800DBBD4 = 0xD1C;
        D_800DBBDC = D_800DC784;
        D_800DBBE4 = D_800DC78C;
        D_800DBBE0 = D_800DC788;
        D_800DBBE8 = D_800DC788 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFE;
        D_800DBBD4 = 0xD1C;
        D_800DBBDC = D_800DC790;
        D_800DBBE4 = D_800DC798;
        D_800DBBE0 = D_800DC794;
        D_800DBBE8 = D_800DC794 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0) {
        if ((u8)D_800DB1E0 != 0xB) {
            if (((D_800DB1EC - D_800DB1FC) >> 12) >= 0x241) {
                func_800B61C8();
            }
        }
    }
}

void func_800B66D8(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;
    s16 id3;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xF8;
        D_800DBBD4 = 0xD1C;
        D_800DBBDC = D_800DC79C;
        D_800DBBE4 = D_800DC7A4;
        D_800DBBE0 = D_800DC7A0;
        D_800DBBE8 = D_800DC7A0 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC00 = 0xF9;
        D_800DBC1C = 0xD1C;
        D_800DBC24 = D_800DC7A8;
        D_800DBC28 = D_800DC7AC;
        D_800DBC2C = D_800DC7B0;
        D_800DBC30 = D_800DC7AC + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC00;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id3 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC00 = 0xFC;
        D_800DBC1C = 0x151C;
        D_800DBC24 = D_800DC7B4;
        D_800DBC28 = D_800DC7B8;
        D_800DBC2C = D_800DC7BC;
        D_800DBC30 = D_800DC7B8 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found3;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found3:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id3;
            s->unk4 = D_800DBC00;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0) {
        if ((u8)D_800DB1E0 != 0xB) {
            if (((D_800DB1EC - D_800DB1FC) >> 12) >= 0x241) {
                func_800B61C8();
            }
        }
    }
}

void func_800B6B10(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFB;
        D_800DBBD4 = 0x51C;
        D_800DBBDC = D_800DC7C0;
        D_800DBBE4 = D_800DC7C8;
        D_800DBBE0 = D_800DC7C4;
        D_800DBBE8 = D_800DC7C4 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFE;
        D_800DBBD4 = 0x51C;
        D_800DBBDC = D_800DC7CC;
        D_800DBBE4 = D_800DC7D4;
        D_800DBBE0 = D_800DC7D0;
        D_800DBBE8 = D_800DC7D0 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0) {
        if ((u8)D_800DB1E0 != 0xB) {
            if (((D_800DB1EC - D_800DB1FC) >> 12) >= 0x241) {
                func_800B61C8();
            }
        }
    }
}

void func_800B6E08(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s32 x;
    s32 y;
    s32 z;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xF8;
        D_800DBBD4 = 0x51C;
        x = D_800DC7D8;
        z = D_800DC7E0;
        y = D_800DC7DC;
        D_800DBBE0 = y;
        D_800DBBDC = x;
        D_800DBBE4 = z;
        D_800DBBE8 = y + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0 && (u8)D_800DB1E0 != 0xB && ((D_800DB1EC - D_800DB1FC) >> 12) > 0x240) {
        func_800B61C8();
    }
}

void func_800B6FC0(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFB;
        D_800DBBD4 = 0x51C;
        D_800DBBDC = D_800DC7E4;
        D_800DBBE4 = D_800DC7EC;
        D_800DBBE0 = D_800DC7E8;
        D_800DBBE8 = D_800DC7E8 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFE;
        D_800DBBD4 = 0x51C;
        D_800DBBDC = D_800DC7F0;
        D_800DBBE4 = D_800DC7F8;
        D_800DBBE0 = D_800DC7F4;
        D_800DBBE8 = D_800DC7F4 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0) {
        if ((u8)D_800DB1E0 != 0xB) {
            if (((D_800DB1EC - D_800DB1FC) >> 12) >= 0x241) {
                func_800B61C8();
            }
        }
    }
}

void func_800B72B8(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;
    s16 id3;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xF8;
        D_800DBBD4 = 0x51C;
        D_800DBBDC = D_800DC7FC;
        D_800DBBE4 = D_800DC804;
        D_800DBBE0 = D_800DC800;
        D_800DBBE8 = D_800DC800 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC00 = 0xFF;
        D_800DBC1C = 0x51C;
        D_800DBC24 = D_800DC808;
        D_800DBC28 = D_800DC80C;
        D_800DBC2C = D_800DC810;
        D_800DBC30 = D_800DC80C + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC00;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id3 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC00 = 0xF9;
        D_800DBC1C = 0xD1C;
        D_800DBC24 = D_800DC814;
        D_800DBC28 = D_800DC818;
        D_800DBC2C = D_800DC81C;
        D_800DBC30 = D_800DC818 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found3;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found3:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id3;
            s->unk4 = D_800DBC00;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0) {
        if ((u8)D_800DB1E0 != 0xB) {
            if (((D_800DB1EC - D_800DB1FC) >> 12) >= 0x241) {
                func_800B61C8();
            }
        }
    }
}

void func_800B76F0(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFB;
        D_800DBBD4 = 0x51C;
        D_800DBBDC = D_800DC820;
        D_800DBBE4 = D_800DC828;
        D_800DBBE0 = D_800DC824;
        D_800DBBE8 = D_800DC824 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFE;
        D_800DBBD4 = 0x51C;
        D_800DBBDC = D_800DC82C;
        D_800DBBE4 = D_800DC834;
        D_800DBBE0 = D_800DC830;
        D_800DBBE8 = D_800DC830 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0) {
        if ((u8)D_800DB1E0 != 0xB) {
            if (((D_800DB1EC - D_800DB1FC) >> 12) >= 0x241) {
                func_800B61C8();
            }
        }
    }
}

void func_800B79E8(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;
    s16 id3;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xF8;
        D_800DBBD4 = 0x51C;
        D_800DBBDC = D_800DC838;
        D_800DBBE4 = D_800DC840;
        D_800DBBE0 = D_800DC83C;
        D_800DBBE8 = D_800DC83C + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC00 = 0xFC;
        D_800DBC1C = 0x51C;
        D_800DBC24 = D_800DC844;
        D_800DBC28 = D_800DC848;
        D_800DBC2C = D_800DC84C;
        D_800DBC30 = D_800DC848 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC00;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id3 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC00 = 0xFF;
        D_800DBC1C = 0xD1C;
        D_800DBC24 = D_800DC850;
        D_800DBC28 = D_800DC854;
        D_800DBC2C = D_800DC858;
        D_800DBC30 = D_800DC854 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found3;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found3:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id3;
            s->unk4 = D_800DBC00;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0) {
        if ((u8)D_800DB1E0 != 0xB) {
            if (((D_800DB1EC - D_800DB1FC) >> 12) >= 0x241) {
                func_800B61C8();
            }
        }
    }
}

void func_800B7E20(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFB;
        D_800DBBD4 = 0x51C;
        D_800DBBDC = D_800DC85C;
        D_800DBBE4 = D_800DC864;
        D_800DBBE0 = D_800DC860;
        D_800DBBE8 = D_800DC860 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFE;
        D_800DBBD4 = 0x51C;
        D_800DBBDC = D_800DC868;
        D_800DBBE4 = D_800DC870;
        D_800DBBE0 = D_800DC86C;
        D_800DBBE8 = D_800DC86C + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0) {
        if ((u8)D_800DB1E0 != 0xB) {
            if (((D_800DB1EC - D_800DB1FC) >> 12) >= 0x241) {
                func_800B61C8();
            }
        }
    }
}

void func_800B8118(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;
    s16 id3;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xF8;
        D_800DBBD4 = 0x51C;
        D_800DBBDC = D_800DC874;
        D_800DBBE4 = D_800DC87C;
        D_800DBBE0 = D_800DC878;
        D_800DBBE8 = D_800DC878 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC00 = 0xFC;
        D_800DBC1C = 0x51C;
        D_800DBC24 = D_800DC880;
        D_800DBC28 = D_800DC884;
        D_800DBC2C = D_800DC888;
        D_800DBC30 = D_800DC884 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC00;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id3 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC00 = 0xFF;
        D_800DBC1C = 0xD1C;
        D_800DBC24 = D_800DC88C;
        D_800DBC28 = D_800DC890;
        D_800DBC2C = D_800DC894;
        D_800DBC30 = D_800DC890 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found3;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found3:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id3;
            s->unk4 = D_800DBC00;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0) {
        if ((u8)D_800DB1E0 != 0xB) {
            if (((D_800DB1EC - D_800DB1FC) >> 12) >= 0x241) {
                func_800B61C8();
            }
        }
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B8550);

void func_800B8AC8(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s32 x;
    s32 y;
    s32 z;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xF8;
        D_800DBBD4 = 0xD1C;
        x = D_800DC8C8;
        z = D_800DC8D0;
        y = D_800DC8CC;
        D_800DBBE0 = y;
        D_800DBBDC = x;
        D_800DBBE4 = z;
        D_800DBBE8 = y + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0 && (u8)D_800DB1E0 != 0xB && ((D_800DB1EC - D_800DB1FC) >> 12) > 0x240) {
        func_800B61C8();
    }
}

void func_800B8C80(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFB;
        D_800DBBD4 = 0xD1C;
        D_800DBBDC = D_800DC8D4;
        D_800DBBE4 = D_800DC8DC;
        D_800DBBE0 = D_800DC8D8;
        D_800DBBE8 = D_800DC8D8 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFE;
        D_800DBBD4 = 0xD1C;
        D_800DBBDC = D_800DC8E0;
        D_800DBBE4 = D_800DC8E8;
        D_800DBBE0 = D_800DC8E4;
        D_800DBBE8 = D_800DC8E4 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0) {
        if ((u8)D_800DB1E0 != 0xB) {
            if (((D_800DB1EC - D_800DB1FC) >> 12) >= 0x241) {
                func_800B61C8();
            }
        }
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B8F78);

void func_800B9630(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFB;
        D_800DBBD4 = 0xD1C;
        D_800DBBDC = D_800DC928;
        D_800DBBE4 = D_800DC930;
        D_800DBBE0 = D_800DC92C;
        D_800DBBE8 = D_800DC92C + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBBB8 = 0xFE;
        D_800DBBD4 = 0xD1C;
        D_800DBBDC = D_800DC934;
        D_800DBBE4 = D_800DC93C;
        D_800DBBE0 = D_800DC938;
        D_800DBBE8 = D_800DC938 + 0x400000;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBBB8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
    if (D_8010281C == arg0) {
        if ((u8)D_800DB1E0 != 0xB) {
            if (((D_800DB1EC - D_800DB1FC) >> 12) >= 0x241) {
                func_800B61C8();
            }
        }
    }
}

void func_800B9928(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x102;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DC940;
        D_800DBC70 = D_800DC944;
        D_800DBC74 = D_800DC948;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x101;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DC94C;
        D_800DBC70 = D_800DC950;
        D_800DBC74 = D_800DC954;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B9B94(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x101;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DC958;
        D_800DBC70 = D_800DC95C;
        D_800DBC74 = D_800DC960;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x102;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DC964;
        D_800DBC70 = D_800DC968;
        D_800DBC74 = D_800DC96C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800B9E00(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x101;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DC988;
        D_800DBC70 = D_800DC98C;
        D_800DBC74 = D_800DC990;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x102;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DC994;
        D_800DBC70 = D_800DC998;
        D_800DBC74 = D_800DC99C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BA06C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x101;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DC9B8;
        D_800DBC70 = D_800DC9BC;
        D_800DBC74 = D_800DC9C0;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x101;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DC9C4;
        D_800DBC70 = D_800DC9C8;
        D_800DBC74 = D_800DC9CC;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BA2D8(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x101;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DC9D0;
        D_800DBC70 = D_800DC9D4;
        D_800DBC74 = D_800DC9D8;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x102;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DC9DC;
        D_800DBC70 = D_800DC9E0;
        D_800DBC74 = D_800DC9E4;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BA544(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x102;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DC9E8;
        D_800DBC70 = D_800DC9EC;
        D_800DBC74 = D_800DC9F0;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x102;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DC9F4;
        D_800DBC70 = D_800DC9F8;
        D_800DBC74 = D_800DC9FC;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BA7B0(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x101;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DCA18;
        D_800DBC70 = D_800DCA1C;
        D_800DBC74 = D_800DCA20;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x102;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DCA24;
        D_800DBC70 = D_800DCA28;
        D_800DBC74 = D_800DCA2C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BAA1C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x101;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DCA30;
        D_800DBC70 = D_800DCA34;
        D_800DBC74 = D_800DCA38;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x102;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DCA3C;
        D_800DBC70 = D_800DCA40;
        D_800DBC74 = D_800DCA44;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BAC88(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 2, &D_800DCA6C);
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x102;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DCA78;
        D_800DBC70 = D_800DCA7C;
        D_800DBC74 = D_800DCA80;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x101;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DCA84;
        D_800DBC70 = D_800DCA88;
        D_800DBC74 = D_800DCA8C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BAF30(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x102;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DCAB4;
        D_800DBC70 = D_800DCAB8;
        D_800DBC74 = D_800DCABC;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x101;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DCAC0;
        D_800DBC70 = D_800DCAC4;
        D_800DBC74 = D_800DCAC8;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BB19C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x101;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DCAE4;
        D_800DBC70 = D_800DCAE8;
        D_800DBC74 = D_800DCAEC;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBC48 = 0x102;
        D_800DBC64 = 0xE00;
        D_800DBC6C = D_800DCAF0;
        D_800DBC70 = D_800DCAF4;
        D_800DBC74 = D_800DCAF8;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBC48;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BB408(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0 && D_801027A2 >= 0x51) {
        id = arg0;
        D_800DBD10 = 3;
        D_800DBCE4 = 0x02007CC0;
        *(s16 *)&D_800DBCD8 = 0xF0;
        D_800DBCF4 = 0x785;
        D_800DBCFC = D_800DCAFC;
        D_800DBD00 = D_800DCB00 + 0xFFF60000;
        D_800DBD04 = D_800DCB04;
        n = 0x1F;
        i = D_80100F30;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBCD8;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BB580(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;
    s16 id3;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0x12AB;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DCD38;
        D_800DBAC8 = D_800DCD3C;
        D_800DBAC0 = D_800DCD3C;
        D_800DBAC4 = D_800DCD40;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0x12AB;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DCD44;
        D_800DBAC8 = D_800DCD48;
        D_800DBAC0 = D_800DCD48;
        D_800DBAC4 = D_800DCD4C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id3 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0x12AB;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DCD50;
        D_800DBAC8 = D_800DCD54;
        D_800DBAC0 = D_800DCD54;
        D_800DBAC4 = D_800DCD58;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found3;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found3:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id3;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BB964(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0x12AB;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DCD5C;
        D_800DBAC8 = D_800DCD60;
        D_800DBAC0 = D_800DCD60;
        D_800DBAC4 = D_800DCD64;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0x12AB;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DCD68;
        D_800DBAC8 = D_800DCD6C;
        D_800DBAC0 = D_800DCD6C;
        D_800DBAC4 = D_800DCD70;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BBC00(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;
    s16 id3;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0x12AB;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DCD74;
        D_800DBAC8 = D_800DCD78;
        D_800DBAC0 = D_800DCD78;
        D_800DBAC4 = D_800DCD7C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0x12AB;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DCD80;
        D_800DBAC8 = D_800DCD84;
        D_800DBAC0 = D_800DCD84;
        D_800DBAC4 = D_800DCD88;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id3 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0x12AB;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DCD8C;
        D_800DBAC8 = D_800DCD90;
        D_800DBAC0 = D_800DCD90;
        D_800DBAC4 = D_800DCD94;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found3;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found3:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id3;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BBFE4(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0x12AB;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DCD98;
        D_800DBAC8 = D_800DCD9C;
        D_800DBAC0 = D_800DCD9C;
        D_800DBAC4 = D_800DCDA0;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBA98 = 0xEC;
        D_800DBAB4 = 0x12AB;
        D_800DBACC = func_800ABBE0;
        D_800DBABC = D_800DCDA4;
        D_800DBAC8 = D_800DCDA8;
        D_800DBAC0 = D_800DCDA8;
        D_800DBAC4 = D_800DCDAC;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBA98;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BC280(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;
    s16 id2;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBAE0 = 0xEC;
        D_800DBAFC = 0x2AB;
        D_800DBB04 = D_800DCDB0;
        D_800DBB08 = D_800DCDB4;
        D_800DBB0C = D_800DCDB8;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBAE0;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        id2 = arg0;
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBAE0 = 0xEC;
        D_800DBAFC = 0x2AB;
        D_800DBB04 = D_800DCDBC;
        D_800DBB08 = D_800DCDC0;
        D_800DBB0C = D_800DCDC4;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found2;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found2:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id2;
            s->unk4 = D_800DBAE0;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BC4EC(void) {
    s32 *p;
    s32 i;

    p = D_80100F34;
    for (i = 0x96; i != -1; i--) {
        *p++ = 0;
    }
    D_80101190 = 0;
}

void func_800BC51C(s16 arg0) {
    s32 first;

    first = 0;
    if (((u8 *)D_80100F34)[arg0] == 0) {
        first = 1;
        ((u8 *)D_80100F34)[arg0] = 1;
    }
    if (D_800DCDC8[arg0] != NULL) {
        D_800DCDC8[arg0](arg0, first);
    }
}

void func_800BC58C(void) {
    s32 var_v0;
    s8 *var_v1;

    var_v1 = &D_800FFDB0;
    var_v0 = 0x1F;
    do {
        *var_v1 = 0;
        var_v0 -= 1;
        var_v1 += 0x8C;
    } while (var_v0 != -1);
    D_80100F30 = 0;
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BC5BC);

void func_800BCD30(void *arg0) {
    s32 dx;
    s32 dz;

    M2C_FIELD(arg0, s16 *, 0x8A) = -(M2C_FIELD(arg0, s16 *, 2) - D_8010281C >= 3);
    dx = (D_800DB1F8.v[0] - M2C_FIELD(arg0, s32 *, 0x28)) >> 12;
    dz = (D_800DB200 - M2C_FIELD(arg0, s32 *, 0x30)) >> 12;
    if (func_80039F5C(dx * dx + dz * dz) < D_800DB1E8 + 0x400) {
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800AD3F8;
        if (M2C_FIELD(arg0, s32 *, 0x3C) & 1) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0x60;
        } else {
            M2C_FIELD(arg0, s16 *, 0x14) = 0x40;
        }
        M2C_FIELD(arg0, s16 *, 0x16) = 0x100;
        M2C_FIELD(arg0, s16 *, 0x18) = 0x100;
    }
}

void func_800BCE0C(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 2) - D_8010281C < 4) {
        if (--M2C_FIELD(arg0, s16 *, 0x84) != -1) {
            M2C_FIELD(arg0, s16 *, 0x8A) = -1;
            return;
        }
        M2C_FIELD(arg0, s16 *, 0x14) = 0xA0;
        M2C_FIELD(arg0, s16 *, 0x8A) = 0;
        M2C_FIELD(arg0, s32 *, 0x70) = 0x8000;
        M2C_FIELD(arg0, s16 *, 0x88) = 0;
        M2C_FIELD(arg0, u16 *, 0x84) = M2C_FIELD(arg0, u16 *, 0x48);
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s32 *, 0x3C);
        M2C_FIELD(arg0, s32 *, 0x2C) = ((func_80042DA8() & 0xF) << 16) + M2C_FIELD(arg0, s32 *, 0x40);
        M2C_FIELD(arg0, s32 *, 0x30) = M2C_FIELD(arg0, s32 *, 0x44);
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800AD70C;
    }
}

void func_800BCECC(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBB28 = 0xED;
        D_800DBB44 = 0xADC;
        D_800DBB4C = D_800DBFDC;
        D_800DBB50 = D_800DBFE0;
        D_800DBB54 = D_800DBFE4;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBB28;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BD008(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBAE0 = 0xEA;
        D_800DBAFC = 0x726;
        D_800DBB04 = D_800DC090;
        D_800DBB08 = D_800DC094;
        D_800DBB0C = D_800DC098;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBAE0;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BD144(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBB28 = 0xED;
        D_800DBB44 = 0xF1E;
        D_800DBB4C = D_800DC0B4;
        D_800DBB50 = D_800DC0B8;
        D_800DBB54 = D_800DC0BC;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBB28;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BD280(void) {
}

void func_800BD288(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBB28 = 0xEF;
        D_800DBB44 = 0xB90;
        D_800DBB4C = D_800DC0C0;
        D_800DBB50 = D_800DC0C4;
        D_800DBB54 = D_800DC0C8;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBB28;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BD3C4(void) {
}

void func_800BD3CC(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBAE0 = 0xEA;
        D_800DBAFC = 0xE00;
        D_800DBB04 = D_800DC120;
        D_800DBB08 = D_800DC124;
        D_800DBB0C = D_800DC128;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBAE0;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BD508(void) {
}

void func_800BD510(void) {
}

void func_800BD518(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B18B0();
    }
}

void func_800BD53C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        *(s16 *)&D_800DBAE0 = 0xEC;
        D_800DBAFC = 0xF55;
        D_800DBB04 = D_800DC2AC;
        D_800DBB08 = D_800DC2B0;
        D_800DBB0C = D_800DC2B4;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBAE0;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BD678(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC2DC;
        D_800DBCB8 = D_800DC2E0;
        D_800DBCBC = D_800DC2E4;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BD7A8(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        func_800ADA8C(arg0, 0, &D_800DC2F4);
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC2E8;
        D_800DBCB8 = D_800DC2EC;
        D_800DBCBC = D_800DC2F0;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BD908(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC300;
        D_800DBCB8 = D_800DC304;
        D_800DBCBC = D_800DC308;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        func_800ADA8C(arg0, 1, &D_800DC30C);
    }
}

void func_800BDA64(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC318;
        D_800DBCB8 = D_800DC31C;
        D_800DBCBC = D_800DC320;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        func_800ADA8C(arg0, 0, &D_800DC324);
    }
}

void func_800BDBC0(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC330;
        D_800DBCB8 = D_800DC334;
        D_800DBCBC = D_800DC338;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        func_800ADA8C(arg0, 1, &D_800DC33C);
    }
}

void func_800BDD1C(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC348;
        D_800DBCB8 = D_800DC34C;
        D_800DBCBC = D_800DC350;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        func_800ADA8C(arg0, 0, &D_800DC354);
    }
}

void func_800BDE78(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC360;
        D_800DBCB8 = D_800DC364;
        D_800DBCBC = D_800DC368;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        func_800ADA8C(arg0, 1, &D_800DC36C);
    }
}

void func_800BDFD4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADA8C(arg0, 0, &D_800DC378);
    }
}

void func_800BE008(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC384;
        D_800DBCB8 = D_800DC388;
        D_800DBCBC = D_800DC38C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BE138(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADA8C(arg0, 2, &D_800DC3D8);
    }
}

void func_800BE16C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADA8C(arg0, 3, D_800DC408);
        func_800ADA8C(arg0, 0, D_800DC408 + 3);
    }
}

void func_800BE1C8(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC420;
        D_800DBCB8 = D_800DC424;
        D_800DBCBC = D_800DC428;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BE2F8(s32 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        func_800ADA8C(arg0, 1, &D_800DC438);
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC42C;
        D_800DBCB8 = D_800DC430;
        D_800DBCBC = D_800DC434;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BE458(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;
    s16 id;

    if (arg1 != 0) {
        id = arg0;
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC450;
        D_800DBCB8 = D_800DC454;
        D_800DBCBC = D_800DC458;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = id;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
        func_800ADA8C(arg0, 0, &D_800DC444);
    }
}

void func_800BE5B4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADA8C(arg0, 2, D_800DC45C);
        func_800ADA8C(arg0, 1, D_800DC45C + 3);
    }
}

void func_800BE610(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBCAC = 0x238;
        D_800DBCB4 = D_800DC474;
        D_800DBCB8 = D_800DC478;
        D_800DBCBC = D_800DC47C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBC90;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BE740(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC5E4;
        D_800DBB98 = D_800DC5E8;
        D_800DBB9C = D_800DC5EC;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BE870(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC5F0;
        D_800DBB98 = D_800DC5F4;
        D_800DBB9C = D_800DC5F8;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BE9A0(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC618;
        D_800DBB98 = D_800DC61C;
        D_800DBB9C = D_800DC620;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BEAD0(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC640;
        D_800DBB98 = D_800DC644;
        D_800DBB9C = D_800DC648;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BEC00(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC64C;
        D_800DBB98 = D_800DC650;
        D_800DBB9C = D_800DC654;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BED30(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC690;
        D_800DBB98 = D_800DC694;
        D_800DBB9C = D_800DC698;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BEE60(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC6EC;
        D_800DBB98 = D_800DC6F0;
        D_800DBB9C = D_800DC6F4;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BEF90(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC6F8;
        D_800DBB98 = D_800DC6FC;
        D_800DBB9C = D_800DC700;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BF0C0(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC704;
        D_800DBB98 = D_800DC708;
        D_800DBB9C = D_800DC70C;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BF1F0(s16 arg0, s32 arg1) {
    SbSlotA *p;
    SbSlotA *s;
    s32 i;
    s32 n;

    if (arg1 != 0) {
        n = 0x1F;
        i = D_80100F30;
        D_800DBB8C = 0x98E;
        D_800DBB94 = D_800DC710;
        D_800DBB98 = D_800DC714;
        D_800DBB9C = D_800DC718;
        do {
            p = (SbSlotA *)((u8 *)&D_800FFDB0 + i * 0x8C);
            if (p->flag == 0) {
                D_80100F30 = (i + 1) & 0x1F;
                s = p;
                goto found;
            }
            i = (i + 1) & 0x1F;
        } while (--n != -1);
        s = NULL;
found:
        if (s != NULL) {
            s->flag = 1;
            s->unk1 = 0;
            s->unk2 = arg0;
            s->unk4 = D_800DBB70;
            s->unk6C = 0;
            s->unk70 = 0;
            s->unk74 = 0;
            s->unk78 = 0;
            s->unk84 = 0;
            s->unk86 = 0;
            s->unk88 = 0;
            s->unk8A = 0;
        }
    }
}

void func_800BF320(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 0, D_800DC970);
        func_800AD8F0(arg0, 0x600, 1, D_800DC970 + 3);
    }
}

void func_800BF384(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 0, D_800DC9A0);
        func_800AD8F0(arg0, 0x600, 1, D_800DC9A0 + 3);
    }
}

void func_800BF3E8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 3, &D_800DCA00);
    }
}

void func_800BF420(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 2, &D_800DCA0C);
    }
}

void func_800BF458(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 1, D_800DCA48);
        func_800AD8F0(arg0, 0x600, 0, D_800DCA48 + 3);
    }
}

void func_800BF4BC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 3, &D_800DCA60);
    }
}

void func_800BF4F4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 3, &D_800DCA90);
    }
}

void func_800BF52C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 2, &D_800DCA9C);
    }
}

void func_800BF564(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 1, &D_800DCAA8);
    }
}

void func_800BF59C(s32 arg0, s32 arg1) {
    s32 i;
    s16 *p;
    s32 v;

    if (arg0 == D_8010281C) {
        i = (D_801027C8 - 0x3C) >> 1;
        if (i >= 0) {
            p = &D_800DB1E0;
            if ((u8)*p != 0xB && (D_800DB1EC - D_800DB1FC) >> 12 > D_800DCACC[i]) {
                v = D_800DB20C;
                *p = 0xB;
                if (v < 0) {
                    v = -v;
                }
                if (v <= 0x3FFFF) {
                    v = 0x40000;
                }
                D_800DB20C = v;
                func_800A1300(2, 0x10C, 0);
            }
        }
    }
}

void func_800BF670(s32 arg0, s32 arg1) {
    s32 i;
    s16 *p;
    s32 v;

    if (arg0 == D_8010281C) {
        i = (D_801027C8 - 0x30) >> 1;
        if (i >= 0) {
            p = &D_800DB1E0;
            if ((u8)*p != 0xB && (D_800DB1EC - D_800DB1FC) >> 12 > D_800DCACC[i]) {
                v = D_800DB20C;
                *p = 0xB;
                if (v < 0) {
                    v = -v;
                }
                if (v <= 0x3FFFF) {
                    v = 0x40000;
                }
                D_800DB20C = v;
                func_800A1300(2, 0x10C, 0);
            }
        }
    }
}

void func_800BF744(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800A1300(4, 0xCD, 0);
    }
}

void func_800BF770(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 0, D_800DCB08);
        func_800AD584(arg0, 0xA00, 2, D_800DCB08 + 4);
        func_800AD584(arg0, 0x400, 3, D_800DCB08 + 8);
    }
}

void func_800BF7E8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0x800, 0, D_800DCB38);
        func_800AD584(arg0, 0x300, 2, D_800DCB38 + 4);
    }
}

void func_800BF84C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0xC00, 2, D_800DCB58);
        func_800AD584(arg0, 0, 1, D_800DCB58 + 4);
        func_800AD584(arg0, 0x700, 2, D_800DCB58 + 8);
    }
}

void func_800BF8C4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0x600, 2, D_800DCB88);
        func_800AD584(arg0, 0xC00, 2, D_800DCB88 + 4);
    }
}

void func_800BF928(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0x600, 2, D_800DCBA8);
        func_800AD584(arg0, 0xC00, 2, D_800DCBA8 + 4);
    }
}

void func_800BF98C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0xE00, 0, D_800DCBC8);
        func_800AD584(arg0, 0x700, 0, D_800DCBC8 + 4);
        func_800AD584(arg0, 0x100, 0, D_800DCBC8 + 6);
        func_800AD584(arg0, 0x300, 0, D_800DCBC8 + 8);
    }
}

void func_800BFA18(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 2, D_800DCC08);
        func_800AD584(arg0, 0x800, 2, D_800DCC08 + 4);
        func_800AD584(arg0, 0x400, 3, D_800DCC08 + 8);
    }
}

void func_800BFA90(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 0, D_800DCC38);
        func_800AD584(arg0, 0x100, 2, D_800DCC38 + 4);
    }
}

void func_800BFAF4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 0, D_800DCC58);
        func_800AD584(arg0, 0x500, 2, D_800DCC58 + 4);
    }
}

void func_800BFB58(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 0, D_800DCC78);
        func_800AD584(arg0, 0, 3, D_800DCC78 + 4);
    }
}

void func_800BFBBC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 2, D_800DCC98);
        func_800AD584(arg0, 0xC00, 0, D_800DCC98 + 4);
    }
}

void func_800BFC20(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0x300, 2, D_800DCCB8);
        func_800AD584(arg0, 0xF00, 3, D_800DCCB8 + 4);
    }
}

void func_800BFC84(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 0, D_800DCCD8);
        func_800AD584(arg0, 0x400, 0, D_800DCCD8 + 4);
        func_800AD584(arg0, 0x800, 2, D_800DCCD8 + 8);
        func_800AD584(arg0, 0xC00, 2, D_800DCCD8 + 12);
    }
}

void func_800BFD10(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 1, D_800DCD18);
        func_800AD584(arg0, 0x200, 2, D_800DCD18 + 4);
    }
}

INCLUDE_RODATA("../asm/us/snobo/nonmatchings/text", D_800A0000);
