#include "common.h"
#include "snobo/decls.h"

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A0390);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A05FC);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A3CB4);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A41DC);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A6968);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A6D28);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A7404);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A76E4);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A7C30);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A815C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A82F4);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A8CB4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A8E20);

void func_800A9DB4(void) {
    func_80044A68(&D_800FFC34, 1, 0, func_8004656C(0, 0, 0x180, 0x100) & 0xFFFF, 0);
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A9DFC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A9FF8);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AC2F4);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AC598);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AD584);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AD70C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AD8F0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ADA8C);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AE1EC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AE348);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AE5E4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AE740);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AEB2C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AEF18);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AF074);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AF1D0);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AF87C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AF9D8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AFB34);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AFDE4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AFF44);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B00A0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B01FC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B035C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B04B8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B072C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0948);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0ACC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0C50);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0DF0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0F90);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B1134);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B12D8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B15C4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B18B0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B1AE4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B1C5C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B1DD4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B1F4C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B20C4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B223C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B23B4);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B28F4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B2CE4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B2E5C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B30B0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B3304);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B3558);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B37AC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B3A38);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B3C8C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B3EE0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B4064);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B42B8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B450C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B469C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B482C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B49BC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B4B4C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B4CDC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B4FE4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B5164);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B52E4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B55D0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B5824);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B5B10);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B5D64);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B6050);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B6228);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B63E0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B66D8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B6B10);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B6E08);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B6FC0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B72B8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B76F0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B79E8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B7E20);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B8118);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B8550);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B8AC8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B8C80);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B8F78);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B9630);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B9928);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B9B94);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B9E00);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BA06C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BA2D8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BA544);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BA7B0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BAA1C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BAC88);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BAF30);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BB19C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BB408);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BB580);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BB964);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BBC00);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BBFE4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BC280);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BD7A8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BD908);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BDA64);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BDBC0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BDD1C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BDE78);

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

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BE2F8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BE458);

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
