#include "common.h"
#include "snobo2/decls.h"

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A0448);

void func_800A05FC(void) {
    func_800A1CC4();
    func_800A1E30();
    func_800A2EF0(0, 0, 0x10);
    func_800A71E0(0, D_80105380);
    D_800E194C = &func_800A0654;
}

void func_800A0654(void) {
    s32 *p;
    s32 c;
    s32 n;

    p = &D_80103954;
    c = (u8)*p;
    func_800A71E0((c << 16) | (c << 8) | c, (s32)D_80105380);
    n = *p + 4;
    *p = n;
    if (n >= 0x100) {
        *p = 0;
        D_800E194C = &func_800A06CC;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A06CC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A0910);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A0C44);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A0FC0);

void func_800A10B4(void) {
    M2C_UNK *var_v1;
    s32 temp_a0;
    s32 temp_v0;

    if (D_80103958 != 0) {
        temp_a0 = D_80103960;
        D_80103960 = temp_a0 + 1;
        func_800ABC54(temp_a0);
    }
    D_801053B0 = 0;
    D_801053A0 = 0;
    func_800A1874();
    temp_v0 = D_80103954 < 0xF1;
    D_80103954 += 1;
    if (temp_v0 == 0) {
        D_80103954 = 0;
        if (D_801053A4 != 0) {
            D_80103964 = func_800A2294();
        } else {
            func_800A21FC();
        }
        var_v1 = &func_800A1194;
        if (D_801053A4 != 0) {
            var_v1 = &func_800A1280;
        }
        D_800E194C = var_v1;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A1194);

void func_800A1280(void) {
    s16 var_v1;
    s32 a;
    s32 *p;

    func_800AC1C8(D_80106A28 - 1, D_80103964, D_80103954);
    if ((D_80103958 != 0) && (D_80103954 == 0)) {
        func_800A1C4C(4, 0x1B9, 0x7F);
    }
    D_801053B0 = 0;
    D_801053A0 = 0;
    func_800A1874();
    p = &D_80103954;
    a = *p + 1;
    *p = a;
    if (a >= 0x25) {
        if (D_80103958 == 0) {
            if (D_80105392 < 0x1E) {
                var_v1 = 0x1F;
                if (D_80105392 >= 0xF) {
                    var_v1 = 0x1D;
                }
            } else {
                var_v1 = 0;
            }
        } else {
            var_v1 = 0x1E;
        }
        D_8009A000 = 0xA7;
        D_800DDE70 = var_v1;
        D_8009A004 = 0x12C;
        D_8009A008 = 0;
        func_8002DA7C();
        D_8010395C = 0;
        D_80103968 = func_800A7758();
        D_800E194C = &func_800A13C8;
    }
}

void func_800A13C8(void) {
    s32 *p;
    u32 *q;
    u32 a;
    u32 b;
    void (*f)();

    p = &D_8010395C;
    if (*p != 0) {
        if (D_801053B0 & 0x1000) {
            *p = 0;
        }
    } else if (D_801053B0 & 0x4000) {
        *p = 1;
    }
    func_800AB9AC(0, D_8010395C);
    func_800ABE64(D_80103968);
    if (D_801053A4 != 0) {
        func_800AC1C8(D_80106A28 - 1, D_80103964, D_80103954);
    } else {
        func_800ABF3C(0x1F800000, D_80103954, D_80105380 + 4);
    }
    q = &D_8010396C;
    a = D_801053A0;
    b = D_801053B0;
    D_801053B0 = 0;
    D_801053A0 = 0;
    *q = a;
    D_80103970 = b;
    func_800A1874();
    D_801053B0 = D_80103970;
    D_801053A0 = *q;
    if (D_80103970 & 0x860) {
        f = func_800A1544;
        D_80103954 = 0;
        if (D_8010395C != 0) {
            f = func_800A1670;
        }
        D_800E194C = f;
    }
}

void func_800A1544(void) {
    s32 *p;
    s32 a;

    p = &D_80103954;
    a = *p + 8;
    if (*p == 0) {
        func_800A1DBC();
        a = *p + 8;
    }
    *p = a;
    if (a < 0x100) {
        func_800A7108(a, (s32)D_80105380);
        D_801053B0 = 0;
        D_801053A0 = 0;
        D_80106B50 = 0;
        func_800A1718();
        return;
    }
    if (D_800E1948 != 0 && D_801053A4 != 0 && (s16)D_800B83A6 < 0x1BB0 && D_80106AFC < D_800B83B0[D_80106A28][0]) {
        func_800A294C();
    }
    func_800A71E0(0xFFFFFF, (s32)D_80105380);
    D_800E194C = func_800A7804;
}

void func_800A1670(void) {
    s32 *p;
    s32 a;

    p = &D_80103954;
    a = *p + 8;
    if (*p == 0) {
        func_800A1DBC();
        a = *p + 8;
    }
    *p = a;
    if (a < 0x100) {
        func_800A7030(a, D_80105380);
        D_801053B0 = 0;
        D_801053A0 = 0;
        D_80106B50 = 0;
        func_800A1718();
        return;
    }
    func_800A71E0(0, (s32)D_80105380);
    D_800E1944 = 0;
}

s32 func_800A1718(void) {
    s32 r;
    s16 *p;

    func_800A2490();
    if (D_80106B50 != 0) {
        func_800A19C4();
    }
    p = &D_800E1904;
    *p = (D_800DDE88.v[0] >> 0xC) - (u16)D_80106A60;
    D_800E1906 = (D_800DDE8C >> 0xC) - (u16)D_80106A64;
    D_800E1908 = (D_800DDE90 >> 0xC) - (u16)D_80106A68;
    func_800A32C8(1, M2C_FIELD(D_80106AF8, u8 **, 0x10)[D_801069CC] + 1);
    if (D_80106B50 != 0) {
        func_800A25B0();
    }
    D_80106A70 = func_80042B10(0x1F8003FC);
    func_800A8100(p, 0x1F800000, D_80106B50, 1);
    func_80042B10(D_80106A70);
    func_800A6E18();
    func_800A2664();
    r = D_801053A4;
    if (r != 0) {
        func_800A29BC();
        r = func_800A2AE8();
    }
    return r;
}

s32 func_800A1874(void) {
    s32 r;
    s16 *p;

    if (D_80106B50 != 0) {
        func_800A19C4();
    }
    p = &D_800E1910;
    *p = (D_800DDE88.v[0] >> 0xC) - (u16)D_80106A60;
    D_800E1912 = (D_800DDE8C >> 0xC) - (u16)D_80106A64;
    D_800E1914 = (D_800DDE90 >> 0xC) - (u16)D_80106A68;
    func_800A6854(0x1F800000);
    func_800A32C8(1, M2C_FIELD(D_80106AF8, u8 **, 0x10)[D_801069CC] + 1);
    if (D_80106B50 != 0) {
        func_800A25B0();
    }
    D_80106A70 = func_80042B10(0x1F8003FC);
    func_800A8100(p, 0x1F800000, D_80106B50, 1);
    func_80042B10(D_80106A70);
    func_800A6E18();
    func_800A2664();
    r = D_801053A4;
    if (r != 0) {
        r = func_800A2AE8();
    }
    return r;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A19C4);

void func_800A1C4C(s32 arg0, s32 arg1, s32 arg2) {
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

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A1CC4);

void func_800A1DBC(void) {
    s16 *p;

    p = &D_8009A000;
    *p = 0xB9;
    D_8009A004 = 0x1E;
    D_8009A008 = 0;
    func_8002DA7C();
    *p = 0xC1;
    D_8009A004 = 0x1E;
    D_8009A008 = 0;
    func_8002DA7C();
}

void func_800A1E30(void) {
    s16 *p;

    p = &D_8009A000;
    *p = 0x10;
    D_8009A004 = D_800B837C + 0x801F8000;
    func_8002DA7C();
    *p = 0xC2;
    D_8009A004 = 0x12C;
    D_8009A008 = 0;
    D_8009A00C = 0x7F;
    func_8002DA7C();
}

void func_800A1EB4(void) {
    u32 out;

    D_801053A8 = D_801053A0;
    D_801053A0 = ((s32 (*)(s32))func_8001C808)(0);
    D_801053B0 = (D_801053A8 ^ D_801053A0) & D_801053A0;
    if (D_801053A8 != D_801053A0) {
        D_8010539C = 0;
    }
    out = D_801053A0;
    if (D_8010539C != 0 && D_8010539C < 0x10) {
        out = 0;
    }
    D_801053AC = out;
    D_8010539C += 1;
}

void func_800A1F58(void) {
    func_80033E74(D_800B8260, D_800B8264, 0x801F8000, 0);
    do {

    } while (func_80034B44() != 0);
}

void func_800A1FA0(void) {
    Unk80046D0C sp10;
    s32 i;

    func_80033E74(D_800B8268, D_800B826C, 0x80120000, 0);
    do {

    } while (func_80034B44() != 0);
    for (i = 0; i < 0x12; i++) {
        func_80046CFC(D_800B83F0[i] + 0x80120000);
        func_80046D0C(&sp10);
        func_80044000(sp10.b, (void *)sp10.b_arg);
        func_80044000(sp10.a, (void *)sp10.a_arg);
    }
    func_80043DD8(0);
}

void func_800A2050(void) {
    func_80033E74(D_800B8270, D_800B8274, 0x80178000, 0);
    do {

    } while (func_80034B44() != 0);
    func_800ACF90(0x80178000);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A20A0);

void func_800A2194(void) {
    u8 *base;
    u8 *d;
    s32 i;
    u32 v;

    base = D_8009D4F8;
    for (i = 0; i < 3; i++) {
        d = &base[i * 4];
        v = D_801069C0[i];
        d[1] = v >> 8;
        d[0] = v;
        d[2] = v >> 16;
        d[3] = v >> 24;
        base[i + 0xC] = D_80106AF4[i];
    }
}

void func_800A21FC(void) {
    s32 i;
    s32 j;
    u32 t;
    s16 *p;

    i = D_80106A28 - 1;
    j = i << 2;
    t = *(u32 *)((u8 *)D_801069C0 + j);
    if (t == 0 || D_80106AFC < t) {
        *(u32 *)((u8 *)D_801069C0 + j) = D_80106AFC;
    }
    p = &D_80105396;
    if (D_80106AF4[i] < *p) {
        D_80106AF4[i] = *(u8 *)p;
    }
}

s32 func_800A2294(void) {
    s32 i;
    s32 j;
    u32 *row;
    u32 score;

    row = (u32 *)(D_80106AF4 + D_80106A28 * 0x14);
    score = D_80106AFC;
    for (i = 0; i < 5; i++) {
        if (row[i] == 0 || score < row[i]) {
            break;
        }
    }
    if (i < 5) {
        for (j = 3; j >= i; j--) {
            row[j + 1] = row[j];
        }
        row[i] = score;
        if (i == 0) {
            *(u32 *)((u8 *)D_801069C0 + ((D_80106A28 - 1) << 2)) = score;
        }
    }
    return i;
}

void func_800A235C(void) {
    D_800E1950 ^= 1;
    D_80105380 = D_800FB954[D_800E1950];
    func_80044244(D_80105380, 0x1000);
    D_8010538C = D_800E1954[D_800E1950];
}

void func_800A23DC(void) {
    func_80043DD8(0);
    func_8003CEDC((D_80106A5C != 0) * 2);
    func_800443B0(&D_800B8278[D_800E1950]);
    func_800444AC(&D_800B8330[D_800E1950]);
    func_8004433C((s32)D_800FF950[D_800E1950]);
    D_8010398C = 0;
}

void func_800A2490(void) {
    D_80106B54 = D_800DDE88;
    D_80106B64 = D_801069CC;
    D_80106B66 = D_80106A30;
    D_80106B68 = D_801069D0;
}

void func_800A24F8(void) {
    D_800DDE88 = D_80106B54;
    D_801069CC = D_80106B64;
    D_80106A30 = D_80106B66;
    D_801069D0 = D_80106B68;
}

void func_800A2560(void) {
    void *temp_v0;

    temp_v0 = (D_801069CC * 0xC) + M2C_FIELD(D_80106AF8, s32 *, 0x1C);
    D_80106A60 = M2C_FIELD(temp_v0, s32 *, 0);
    D_80106A64 = M2C_FIELD(temp_v0, s32 *, 4);
    D_80106A68 = M2C_FIELD(temp_v0, s32 *, 8);
}

void func_800A25B0(void) {
    s32 d;
    s32 s;

    d = D_800DDEC4 - D_800DDECC;
    if (d != 0) {
        s = (d < 0 ? -d : d) >> 3;
        if (s == 0) {
            s = 1;
        }
        if (d < 0) {
            s = -s;
        }
        D_800DDECC += s;
    }
    d = D_800DDEC0 - D_800DDEC8;
    if (d != 0) {
        s = (d < 0 ? -d : d) >> 2;
        if (s == 0) {
            s = 1;
        }
        if (d < 0) {
            s = -s;
        }
        D_800DDEC8 += s;
    }
}

void func_800A2664(void) {
    s32 sp10;

    if (D_80106B50 != 0) {
        if (D_80105398 != 0) {
            D_8010397C = D_80106AFC;
            func_800AB4DC(&sp10, D_80106AFC, 0x167);
            D_80106AFC = sp10;
        }
        if (D_8010537C & 1) {
            D_80106B6C = func_800ACA34((s16)D_800DDE78 * 0x96 / 0x800);
        }
    }
    func_800AB700(D_80106AFC, -0x98, -0x60);
    func_800AB8D8(D_80106B6C, 0x32, -0x60);
}

void func_800A2740(void) {
    if (!(D_8010537C & 0xF)) {
        D_8009A000 = 0xD0;
        D_8009A004 = (s32) (D_800DDE78 << 0x10) >> 0x15;
        func_8002DA7C();
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A2794);

void func_800A294C(void) {
    s32 *var_a1;
    s32 *var_v1;
    s32 temp_v0_2;
    s32 var_a0;
    void *temp_v0;

    temp_v0 = D_800B83A4 + D_80106A28 * 0x10;
    var_a1 = M2C_FIELD(temp_v0, s32 **, 8);
    M2C_FIELD(temp_v0, s16 *, 0) = 1;
    var_a0 = 0x67FF;
    M2C_FIELD(temp_v0, u16 *, 4) = (u16) D_800B83A6;
    M2C_FIELD(temp_v0, s32 *, 0xC) = (s32) D_80106AFC;
    var_v1 = D_800B83AC;
    do {
        temp_v0_2 = *var_v1;
        var_v1 += 1;
        var_a0 -= 1;
        *var_a1 = temp_v0_2;
        var_a1 += 1;
    } while (var_a0 != -1);
}

void func_800A29BC(void) {
    u8 *p;
    u16 *cnt;
    s32 w;

    if (D_80106A28 != 0 && D_80106B50 != 0) {
        cnt = &D_800B83A6;
        w = (s16)*cnt;
        if (w < 0x1BB0) {
            p = (u8 *)D_800B83AC + w * 15;
            *cnt = w + 1;
            w = D_800DDE88.v[0];
            p[0] = w >> 24;
            p[1] = w >> 16;
            p[2] = w >> 8;
            w = D_800DDE8C;
            p[3] = w >> 24;
            p[4] = w >> 16;
            p[5] = w >> 8;
            w = D_800DDE90;
            p[6] = w >> 24;
            p[7] = w >> 16;
            p[8] = w >> 8;
            w = (s16)(u16)D_800DDEC8;
            p[9] = w >> 8;
            p[10] = w;
            w = (s16)D_800DDEDA;
            p[11] = w >> 8;
            p[12] = w;
            w = (s16)(u16)D_800DDECC;
            p[13] = w >> 8;
            p[14] = w;
        }
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A2AE8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A2EF0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A32C8);

void func_800A3674(void *arg0) {
    SbFF784 *p;

    p = &D_80103994[M2C_FIELD(arg0, s16 *, 0x36)];
    p->unk0 = M2C_FIELD(arg0, u16 *, 0x26);
    p->unk2 = M2C_FIELD(arg0, u16 *, 0x24);
    p->unk8 = M2C_FIELD(arg0, s32 *, 0x3C);
    p->unkC = M2C_FIELD(arg0, SbBlock32 *, 0x44);
    M2C_FIELD(arg0, s16 *, 0x36) += 1;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A370C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A39AC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A3AE4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4180);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4338);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4494);

void func_800A47D0(void *arg0) {
    SbFF784 *p;
    s16 n;

    p = D_80103994;
    n = M2C_FIELD(arg0, u16 *, 0x36);
    while (--n != -1) {
        ((void (*)(s32))func_800B3B44)(D_800B835C[(s16)p->unk0] + (s16)p->unk2);
        p++;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4870);

void func_800A4A78(SbObjA *p, s16 i) {
    SbTbl *e;
    SbRec12 *r;
    u16 a;
    s32 b;

    p->unk3C = D_800B85D8 + p->unk10->unk8[i] * 0x374;
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

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4B78);

s32 func_800A4DF8(u8 *arg0) {
    s32 r;

    r = func_800A4B78(arg0 + 0x34, *(s32 *)(arg0 + 0x3C), arg0);
    *(s16 *)(arg0 + 4) = r;
    if ((s16)r < 0) {
        return 1;
    }
    D_801069D0 = r;
    D_80106B4C = arg0[0x63];
    return 0;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4E60);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4FF8);

s32 func_800A52E4(u8 *arg0) {
    s32 r;

    r = func_800A4B78(arg0 + 0x34, *(s32 *)(arg0 + 0x3C), arg0);
    *(s16 *)(arg0 + 4) = r;
    if ((s16)r < 0) {
        return func_800A4E60(arg0);
    }
    D_801069D0 = r;
    D_80106B4C = arg0[0x63];
    return 0;
}

s32 func_800A5350(Sb2Act *p) {
    Sb2Cmd *c;

    c = p->unk10;
    if (D_800C824E[c->unk4 << 5] != 0) {
        return 3;
    }
    p->unk0 = c->unk4;
    return func_800A53A0();
}

s32 func_800A53A0(arg0) {
    SbObjD *p;
    SbTbl *e;
    SbRec12 *r;
    s16 *q;
    u16 a;
    s32 b;
    s32 res;

    p = (SbObjD *)arg0;
    p->unk10 = &D_800C824C[(s16)p->unk0];
    p->unk2 = 0;
    p->unk3C = (SbRecC *)(D_800B85D8 + *p->unk10->unk8 * 0x374);
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
    res = func_800A4B78(q, (s32)p->unk3C, p);
    p->unk4 = res;
    if ((s16)res < 0) {
        return 1;
    }
    D_80106B04 = p->unk0;
    D_801069CC = p->unk2;
    D_801069D0 = p->unk4;
    D_80106AF8 = (u8 *)p->unk10;
    D_80106B4C = p->unk63;
    return 0;
}

s32 func_800A5520(Sb2Act *p) {
    Sb2Cmd *c;

    c = p->unk10;
    if (D_800C824E[c->unk5 << 5] != 0) {
        return 4;
    }
    p->unk0 = c->unk5;
    return func_800A53A0();
}

s32 func_800A5570(u8 *arg0) {
    s32 r;
    Sb2Cmd *c;

    r = func_800A4B78(arg0 + 0x34, *(s32 *)(arg0 + 0x3C), arg0);
    *(s16 *)(arg0 + 4) = r;
    if ((s16)r < 0) {
        c = *(Sb2Cmd **)(arg0 + 0x10);
        if (D_800C824E[c->unk4 << 5] != 0) {
            return 3;
        }
        *(s16 *)arg0 = c->unk4;
        return func_800A53A0(arg0);
    }
    D_801069D0 = r;
    D_80106B4C = arg0[0x63];
    return 0;
}

s32 func_800A5610(u8 *arg0) {
    s32 r;
    Sb2Cmd *c;

    r = func_800A4B78(arg0 + 0x34, *(s32 *)(arg0 + 0x3C), arg0);
    *(s16 *)(arg0 + 4) = r;
    if ((s16)r < 0) {
        c = *(Sb2Cmd **)(arg0 + 0x10);
        if (D_800C824E[c->unk5 << 5] != 0) {
            return 4;
        }
        *(s16 *)arg0 = c->unk5;
        return func_800A53A0(arg0);
    }
    D_801069D0 = r;
    D_80106B4C = arg0[0x63];
    return 0;
}

s32 func_800A56B0(void) {
    return 1;
}

void func_800A56B8(void) {
    s32 a;

    if (((u8)D_800DDE70 == 2) || ((s16)D_800DDE78 < 0x80)) {
        D_800DDE98 = 0;
        D_800DDEA0 = 0;
        return;
    }
    a = func_800A5744();
    if (a >= 0x801) {
        a = 0x1000 - a;
    }
    func_800AA188((u8 *)&D_800DDE70 - 0xC, a);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A5744);

s32 func_800A58F0(SbPt3 *p, SbPt3 *a, SbPt3 *b, SbPt3 *c) {
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

s16 func_800A59E0(void *arg0, void *arg1) {
    s16 d;

    d = M2C_FIELD(arg1, s16 *, 4);
    if (d > 0) {
        D_80106B00 = -func_8003CC1C(M2C_FIELD(arg0, s16 *, 4), d + M2C_FIELD(arg0, s16 *, 0));
    } else if (d < 0) {
        D_80106B00 = func_8003CC1C(M2C_FIELD(arg0, s16 *, 4), M2C_FIELD(arg1, s16 *, 0x38) - M2C_FIELD(arg0, s16 *, 0) - d);
    } else {
        D_80106B00 = 0;
    }
    return M2C_FIELD(D_80106AF8, s16 **, 0x18)[D_801069CC] + D_80106B00;
}

void func_800A5A9C(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0) = func_8003CC1C((s32) -M2C_FIELD(arg0, s16 *, 4), (s32) M2C_FIELD(arg0, s16 *, 2));
    M2C_FIELD(arg1, s16 *, 2) = 0;
    M2C_FIELD(arg1, s16 *, 4) = func_8003CC1C((s32) M2C_FIELD(arg0, s16 *, 0), (s32) M2C_FIELD(arg0, s16 *, 2));
}

void func_800A5AF8(s32 arg0, s32 arg1, void *arg2, void *arg3) {
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
        rec = M2C_FIELD(D_80106AF8, u8 **, 8)[arg0] * 0x374;
        base = rec + D_800B882C;
        idx = base + arg1 * 4;
        tbl = rec + (D_800B882C - 0x24C);
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
        func_8003B2CC(D_80106A34, (u8 *)arg3 + 0x10, arg2);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A5C54);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A5F00);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A627C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A66D0);

void func_800A6854(s32 arg0) {
    u16 t;
    u16 *p;

    p = &D_800B838A;
    t = *p;
    if ((s16)*p < 0x40) {
        t += 1;
        *p = t;
    }
    D_800B8386 -= (s16)t >> 4;
    if (D_800B838E >= 0x31) {
        D_800B838E -= 1;
    }
    if (D_800B8390 >= 0x101) {
        D_800B8390 -= 1;
    }
    func_800A66D0(arg0, arg0);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A68FC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A6AD4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A6E18);

void func_800A7030(s32 arg0, s32 arg1) {
    u8 *p;
    s32 h;

    arg0 |= (arg0 << 16) | (arg0 << 8);
    p = D_8010538C;
    M2C_FIELD(p, s32 *, 0) = 0x03000000;
    M2C_FIELD(p, s32 *, 4) = arg0 | 0x62000000;
    M2C_FIELD(p, s32 *, 8) = 0xFF88FF60;
    M2C_FIELD(p, s32 *, 0xC) = 0xF00140;
    func_80046794(arg1, (s32)p);
    p += 0x10;
    if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
        h = 0x100;
    } else {
        h = 0x40;
    }
    func_80044A68(p, 1, 0, h, 0);
    func_80046794(arg1, (s32)p);
    D_8010538C = p + 0xC;
}

void func_800A7108(s32 arg0, s32 arg1) {
    u8 *p;
    s32 h;

    arg0 |= (arg0 << 16) | (arg0 << 8);
    p = D_8010538C;
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
    D_8010538C = p + 0xC;
}

void func_800A71E0(s32 arg0, s32 arg1) {
    void *temp_s0;

    temp_s0 = D_8010538C;
    M2C_FIELD(temp_s0, s32 *, 0) = 0x03000000;
    M2C_FIELD(temp_s0, s32 *, 4) = (s32) ((arg0 & 0xFFFFFF) | 0x61000000);
    M2C_FIELD(temp_s0, s32 *, 8) = 0xFF88FF60;
    M2C_FIELD(temp_s0, s32 *, 0xC) = 0xF00140;
    func_80046794(arg1, (s32) temp_s0);
    D_8010538C = temp_s0 + 0x10;
}

void func_800A7258(void)
{
  s32 a;
  s32 b;
  s32 c;
  a = 0x1E - ((s16) (((s16) D_801069D4) / 3));
  if (a < 0)
  {
    a = 0;
  }
  D_80105390 = a;
  a = ((u32) D_80106AFC) >> 0x10;
  b = 0x1E - (((s32) (((((a & 0xF) + (((((u32) D_80106AFC) >> 0x14) & 0xF) * 0xA)) + (((((u32) D_80106AFC) >> 0x18) & 0xF) * 0x3C)) + ((((u32) D_80106AFC) >> 0x1C) * 0xE10)) - D_800B856E[D_80106A28])) >> 1);
  if (b >= 0x1F)
  {
    b = 0x1E;
  }
  else
    if (b < 0)
  {
    b = 0;
  }
  c = D_801069BC;
  D_80105392 = b;
  if (c >= 0x29)
  {
    c = 0x28;
  }
  D_80105394 = c;
  D_80105396 = (D_80105390 + b) + c;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A738C);

s32 func_800A7758(void) {
    u32 a;
    u32 *p;
    s32 i;

    if (D_801053A4 == 0) {
        a = D_80105396;
        if (a >= 0x64) {
            return 8;
        }
        if (a >= 0x46) {
            return 9;
        }
        if (a >= 0x1E) {
            return 10;
        }
        return 11;
    }
    p = D_800B8558[D_80106A28];
    a = D_80106AFC;
    i = 0;
    while (a >= *p) {
        p++;
        i++;
    }
    return i;
}

void func_800A7804(void) {
    func_800A1CC4();
    func_800A1E30();
    func_800A2EF0(0, 0, 0x10);
    func_800A71E0(0xFFFFFF, D_80105380);
    D_800E194C = &func_800A06CC;
}

s32 func_800A7860(void) {
    s32 i;
    u8 *op;
    u8 c;

    goto start;
found:
    D_80103E40 = D_80103E4C[i];
    D_80103E48[i] = 0;
    D_80103E44[i] = 0;
    D_800D1D8E = 0;
    goto after;
start:
    i = 0;
loop:
    if (D_80103E44[i] != 0 && D_80103E48[i] != 0) {
        goto found;
    }
    i += 1;
    if (i < 4) {
        goto loop;
    }
after:
    if (D_800D1D8E == 0) {
        while (1) {
            op = (u8 *)((((u8)D_800DDE70 << 6) + (s16)D_80103E40) * 4 + M2C_FIELD(D_80103E5C, s32 *, 0xC));
            c = *op;
            if (c >= 0xE) {
                break;
            }
            if (D_800DDF1C[c](op) != 0) {
                break;
            }
        }
    }
    return func_800A7ECC();
}

s32 func_800A7984(void) {
    return 1;
}

s32 func_800A798C(u8 *arg0) {
    s32 n;

    D_800D1D90 = arg0[1];
    func_800A7D48(arg0[2], arg0[3]);
    do {
        n = D_80103E40;
        D_80103E40 = ++n;
    } while (0);
    return 1;
}

s32 func_800A79E0(u8 *arg0) {
    if (D_80103E3C >= 3) {
        return 1;
    }
    D_80103E3C++;
    D_80103E34[D_80103E3C] = D_80103E40 + 1;
    D_80103E38[D_80103E3C] = arg0[1];
    D_80103E40++;
    return 0;
}

s32 func_800A7A70(void) {
    if (D_80103E3C <= 0) {
        return 1;
    }
    if (D_80103E38[D_80103E3C] != 0) {
        D_80103E38[D_80103E3C]--;
        D_80103E40 = D_80103E34[D_80103E3C];
    } else {
        D_80103E3C--;
        D_80103E40++;
    }
    return 0;
}

s32 func_800A7AFC(void *arg0) {
    D_80103E40 = (u16) M2C_FIELD(arg0, u8 *, 1);
    return 0;
}

s32 func_800A7B10(u8 *arg0) {
    D_80103E44[arg0[1]] = 1;
    D_80103E48[arg0[1]] = 0;
    D_80103E4C[arg0[1]] = arg0[2];
    D_80103E40 += 1;
    return 0;
}

s32 func_800A7B68(void) {
    return 1;
}

s32 func_800A7B70(void *arg0) {
    D_800DDE70 = (s16) M2C_FIELD(arg0, u8 *, 1);
    return 1;
}

s32 func_800A7B84(u8 *arg0) {
    s32 n;
    s32 t;

    t = arg0[1];
    do {
        n = D_80103E40;
        D_800DDEA4 = 0x1000;
        D_800DDE76 = 1;
        D_800DDE9C = -t << 9;
        D_80103E40 = ++n;
    } while (0);
    return 0;
}

s32 func_800A7BCC(u8 *arg0) {
    u16 pad;

    pad = D_801053A0;
    if (arg0[2] != 0) {
        pad = ~pad;
    }
    if (pad & D_800DDF54[arg0[1]]) {
        D_80103E40 += 1;
        return 0;
    }
    return 1;
}

s32 func_800A7C34(u8 *arg0) {
    if (D_80103E50 != 0) {
        D_80103E40 = arg0[D_80103E50];
    } else {
        D_80103E40 += 1;
    }
    return 0;
}

s32 func_800A7C78(u8 *arg0) {
    D_80103E44[arg0[1]] = 0;
    D_80103E40 += 1;
    return 0;
}

s32 func_800A7CA8(void *arg0) {
    D_80103E54 = M2C_FIELD(arg0, u8 *, 1);
    D_80103E40 += 1;
    return 0;
}

s32 func_800A7CD0(u8 *arg0) {
    D_8009A000 = arg0[1] + 0x27;
    D_8009A004 = arg0[3];
    D_8009A008 = D_800DDF64[arg0[2]];
    func_8002DA7C();
    D_80103E40 += 1;
    return 0;
}

void func_800A7D48(s32 arg0, s32 arg1) {
    s32 *d;
    s32 *s;
    s32 i;
    s32 n;
    Sb2Rec6 *r;

    func_800A7E88((s32 *)&D_80103D24, (s32 *)&D_80106A74);
    n = M2C_FIELD(D_80103E5C, s16 *, 2);
    s = M2C_FIELD(D_80103E5C, s32 **, 4) + D_800D1D90 * n;
    d = (s32 *)&D_80103DA4;
    for (i = n - 1; i != -1; i--) {
        *d++ = *s++;
    }
    *(Sb2Bytes8 *)&D_80103D14 = *(Sb2Bytes8 *)&D_80106A54;
    r = M2C_FIELD(D_80103E5C, Sb2Rec6 **, 8) + D_800D1D90;
    D_80103D1C.a = r->a;
    D_80103D1C.b = r->b;
    D_80103D1C.c = r->c;
    D_80103E28 = arg0;
    D_800D1D8E = arg0;
    D_80103E24 = (s32 (*)(s32))D_800D1D94[arg1];
}

void func_800A7E88(s32 *dst, s32 *src) {
    s32 n;

    n = D_80103E5C->n;
    while (--n != -1) {
        *dst++ = *src++;
    }
}

s32 func_800A7ECC() {
    s16 *p;
    s16 *q;
    s16 *dst;
    s16 n;
    s32 i;
    s32 t;

    n = D_800D1D8E;
    if (n != 0) {
        n -= 1;
        D_800D1D8E = n;
        t = D_80103E24(((D_80103E28 - n) << 12) / D_80103E28);
        if (t < 0) {
            t = 0;
        } else if (t >= 0x1001) {
            t = 0x1000;
        }
        p = &D_80103D24;
        q = &D_80103DA4;
        dst = &D_80106A74;
        i = M2C_FIELD(D_80103E5C, s16 *, 0);
        while (--i != -1) {
            *dst++ = *p + (((*q - *p) * t) >> 12);
            p++;
            q++;
        }
        p = &D_80103D14;
        q = &D_80103D1C;
        dst = &D_80106A54;
        for (i = 2; i != -1; i--) {
            *dst++ = *p + (((*q - *p) * t) >> 12);
            p++;
            q++;
        }
    }
}

s32 func_800A8038(s32 arg0) {
    return arg0;
}

s32 func_800A8040(s32 arg0) {
    return (s32) (func_80039A74(((arg0 >> 2) * 2) - 0x400) + 0x1000) >> 1;
}

s32 func_800A8070(s32 arg0) {
    return 0x1000 - func_80039A74((arg0 >> 2) + 0x400);
}

s32 func_800A809C(s32 arg0) {
    return -func_80039A74((arg0 >> 2) + 0x800);
}

void func_800A80C4(void) {
    D_800D1D8E = 0;
    D_80103E2C = 0;
    D_80103E30 = 0x7F;
}

void func_800A80E8(s32 arg0) {
    D_80103E48[arg0] = 1;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A8100);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A832C);

void func_800A8684(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        D_800DDEF4 = 0;
        D_800DDEF2 = 0;
        D_800DDEF0 = 0;
    }
    func_800A7860();
}

void func_800A86C0(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x66) = 0;
    M2C_FIELD(arg0, s16 *, 0x72) = 0;
    D_80103E50 = M2C_FIELD(arg0, s16 *, 0x14) < 0x100;
    func_800A7860();
    if ((D_801053B0 & 0x40) && (M2C_FIELD(arg0, s16 *, 0x12) < 8)) {
        M2C_FIELD(arg0, s16 *, 0xC) = func_800A8DEC(arg0);
    } else if (D_801053A0 & 0x8000) {
        if (M2C_FIELD(arg0, s16 *, 0x14) < 0x21) {
            M2C_FIELD(arg0, u16 *, 0x76) -= 0x20;
        } else {
            M2C_FIELD(arg0, s16 *, 0xC) = 0x11;
        }
    } else if (D_801053A0 & 0x2000) {
        if (M2C_FIELD(arg0, s16 *, 0x14) < 0x21) {
            M2C_FIELD(arg0, u16 *, 0x76) += 0x20;
        } else {
            M2C_FIELD(arg0, s16 *, 0xC) = 0x12;
        }
    } else if ((D_801053A0 & 0x4080) && (M2C_FIELD(arg0, s16 *, 0x14) >= 0x101)) {
        M2C_FIELD(arg0, s16 *, 0xC) = 0x16;
    } else if ((M2C_FIELD(arg0, s16 *, 0x14) < 0x100) && (D_801053A0 & 0x1000)) {
        M2C_FIELD(arg0, s16 *, 0xC) = 2;
    }
    func_800A9DE4(arg0);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A8804);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A8AFC);

s32 func_800A8DEC(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x14) > 0x400) {
        if (D_80106B4C & 8) {
            return 6;
        }
        if (M2C_FIELD(D_80106AF8, u8 **, 0xC)[D_801069CC] & 1) {
            return 6;
        }
    }
    if (D_801053A0 & 0x8000) {
        return 5;
    }
    if (D_801053A0 & 0x2000) {
        return 4;
    }
    return 3;
}

void func_800A8E7C(void *arg0, s32 arg1, void *arg2) {
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

s32 func_800A8FD0(Sb2B *p) {
    s32 t;

    if (p->f12 != 0) {
        return 0;
    }
    t = p->f14;
    return (0x8C - ((t * t) >> 16)) < p->f10;
}

void func_800A9014(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x66) = 0;
    func_800A7860();
    func_800A9DE4(arg0);
}

void func_800A9048(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x66) = 0;
    func_800A7860();
    func_800A9DE4(arg0);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A907C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A9200);

void func_800A93EC(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_SFIELD(arg0, s32 *, 0x34) = 0;
        M2C_SFIELD(arg0, s32 *, 0x3C) = 0;
        D_80103E50 = (s8) D_80103E58;
        M2C_SFIELD(arg0, s32 *, 0) = (s32) (M2C_SFIELD(arg0, s32 *, 0) | 1);
    }
    func_800A7860();
    if (D_80103E54 != 0) {
        M2C_SFIELD(arg0, s16 *, 0x76) = func_800AA140((s32) D_801053B4, M2C_SFIELD(arg0, s16 *, 0x76), 0x10);
    }
}

void func_800A946C(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(arg0, s32 *, 0x3C) = 0;
        M2C_FIELD(arg0, s32 *, 0x34) = 0;
        M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0) | 1);
    }
    D_80103E50 = ((u32) D_801053A0 >> 0xC) & 1;
    func_800A7860();
}

void func_800A94C0(void *arg0, s32 arg1) {
    s32 t;
    s32 target;

    if (arg1 != 0) {
        M2C_FIELD(arg0, s16 *, 4) = 0;
        M2C_FIELD(arg0, s16 *, 0x10) = 0;
        M2C_FIELD(arg0, s16 *, 0x72) = 4;
    }
    t = M2C_FIELD(arg0, s16 *, 0x10);
    target = 0;
    if (D_801053A0 & 0x4080) {
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
    func_800A9D20(M2C_FIELD(D_80103E5C, s32 *, 0x18), M2C_FIELD(D_80103E5C, s32 *, 0x30), M2C_FIELD(D_80103E5C, s32 *, 0x1C), M2C_FIELD(D_80103E5C, s32 *, 0x34), -func_80039A74((t << 5) + 0x800));
    if (M2C_FIELD(arg0, s16 *, 0x12) == 0) {
        M2C_FIELD(arg0, s32 *, 0x34) -= M2C_FIELD(arg0, s32 *, 0x34) >> 5;
        M2C_FIELD(arg0, s32 *, 0x3C) -= M2C_FIELD(arg0, s32 *, 0x3C) >> 5;
        func_800A9DE4(arg0);
    }
    if (M2C_FIELD(arg0, s16 *, 0x10) == 0) {
        M2C_FIELD(arg0, s16 *, 0xC) = 1;
        M2C_FIELD(arg0, s16 *, 0x72) = 0;
    }
}

void func_800A95D0(SbObjH *arg0, s32 arg1, void *arg2) {
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
        D_801069D4 += 1;
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
    ((void (*)(void *, void *))func_800A9900)(arg0, arg2);
}

void func_800A9768(SbObjH *arg0, s32 arg1, void *arg2) {
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
        D_801069D4 += 1;
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
    ((void (*)(void *, void *))func_800A9900)(arg0, arg2);
}

void func_800A9900(void *arg0) {
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
        D_80103E49 = 1;
    }
    M2C_FIELD(arg0, s16 *, 0x76) += M2C_FIELD(arg0, s16 *, 6);
    func_800A7860();
}

void func_800A99C8(void *arg0, s32 arg1) {
    u8 var_a0;

    if (arg1 != 0) {
        if (M2C_SFIELD(arg0, u8 *, 0xC) == 0xC) {
            M2C_SFIELD(arg0, s32 *, 0x34) = (s32) -M2C_SFIELD(arg0, s32 *, 0x34);
            M2C_SFIELD(arg0, s32 *, 0x3C) = (s32) -M2C_SFIELD(arg0, s32 *, 0x3C);
        }
        M2C_SFIELD(arg0, s16 *, 0x66) = 0;
        M2C_SFIELD(arg0, s16 *, 0x72) = 0;
        M2C_SFIELD(arg0, s32 *, 0x34) = (s32) ((s32) M2C_SFIELD(arg0, s32 *, 0x34) >> 1);
        M2C_SFIELD(arg0, s32 *, 0x3C) = (s32) ((s32) M2C_SFIELD(arg0, s32 *, 0x3C) >> 1);
        D_801069D4 += 2;
        if (M2C_SFIELD(arg0, s16 *, 0x14) >= 0x501) {
            var_a0 = (D_8010537C % 3) + 1;
        } else {
            var_a0 = 0;
        }
        D_80103E58 = var_a0;
    }
    if (D_80103E54 != 0) {
        func_800A9B18(arg0);
    }
    func_800A7860();
    func_800A9DE4(arg0);
}

void func_800A9AC0(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_SFIELD(arg0, s16 *, 0x66) = 0;
        D_801069D4 += 1;
    }
    func_800A9B18(arg0);
    func_800A7860();
    func_800A9DE4(arg0);
}

void func_800A9B18(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x12) < 5) {
        M2C_FIELD(arg0, s32 *, 0x34) -= M2C_FIELD(arg0, s32 *, 0x34) >> 5;
        M2C_FIELD(arg0, s32 *, 0x3C) -= M2C_FIELD(arg0, s32 *, 0x3C) >> 5;
        if (M2C_FIELD(arg0, s16 *, 0x14) < 0x180) {
            M2C_FIELD(arg0, s16 *, 0x72) = 3;
        }
        if ((D_80103E50 == 0 && M2C_FIELD(arg0, s16 *, 0x14) < 0x100) || M2C_FIELD(arg0, s16 *, 0xE) > 0xF0) {
            M2C_FIELD(arg0, s16 *, 0x72) = 0;
            D_80103E50 = 1;
        }
    }
}

void func_800A9BB4(void *arg0) {
    func_800A7860();
    if ((D_80103E54 != 0) && (D_801053A0 & 0x1000)) {
        M2C_FIELD(arg0, s16 *, 0xC) = 2;
    }
}

void func_800A9C0C(s32 *arg0) {
    func_800A7860();
    *arg0 |= 1;
}

void func_800A9C44(void *arg0, s32 arg1) {
    s32 a;
    s32 b;
    s32 d;

    if (arg1 != 0) {
        M2C_FIELD(arg0, s16 *, 6) = 0;
    }
    if (D_80103E50 == 0) {
        a = M2C_FIELD(arg0, s32 *, 0x34);
        b = M2C_FIELD(arg0, s32 *, 0x3C);
        M2C_FIELD(arg0, s32 *, 0x34) = a - (a >> 4);
        M2C_FIELD(arg0, s32 *, 0x3C) = b - (b >> 4);
        if (M2C_FIELD(arg0, s16 *, 6) < 0x40) {
            M2C_FIELD(arg0, s16 *, 6) += 8;
        }
        M2C_FIELD(arg0, u16 *, 0x76) -= M2C_FIELD(arg0, u16 *, 6);
        d = (s16)M2C_FIELD(arg0, u16 *, 0x76) - D_80106A2C;
        if (d < 0) {
            d = -d;
        }
        if (((d + 0x800) & 0xFFF) < 0x40) {
            D_80103E50 = 1;
            M2C_FIELD(arg0, s32 *, 0x3C) = 0;
            M2C_FIELD(arg0, s32 *, 0x34) = 0;
            M2C_SFIELD(arg0, s32 *, 0) |= 1;
        }
    }
    func_800A7860();
}

void func_800A9D20(s16 *arg0, s16 *arg1, s16 *arg2, s16 *arg3, s32 arg4) {
    s16 *p;
    s16 *q;
    s16 *dst;
    s32 n;

    p = arg0;
    q = arg1;
    dst = &D_80106A74;
    n = *(s16 *)D_80103E5C;
    while (--n != -1) {
        *dst++ = *p + (((*q - *p) * arg4) >> 12);
        p++;
        q++;
    }
    p = arg2;
    q = arg3;
    dst = &D_80106A54;
    n = 3;
    while (--n != -1) {
        *dst++ = *p + (((*q - *p) * arg4) >> 12);
        p++;
        q++;
    }
}

void func_800A9DE4(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x14) >= 0x80) {
        M2C_FIELD(arg0, s16 *, 0x76) = func_800AA140(func_8003CC1C(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x3C)) + 0x800, M2C_FIELD(arg0, s16 *, 0x76), 0x10);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A9E40);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AA048);

s16 func_800AA140(s32 arg0, s16 arg1, s32 arg2) {
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

void func_800AA188(void *arg0, s32 arg1) {
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
    c = D_800DE034[idx];
    switch (c) {
    case 0xFF:
        break;
    case 0xFE:
        func_800A1C4C(3, 0x135, 0);
        M2C_FIELD(arg0, s32 *, 0x34) -= M2C_FIELD(arg0, s32 *, 0x34) >> 2;
        M2C_FIELD(arg0, s32 *, 0x3C) -= M2C_FIELD(arg0, s32 *, 0x3C) >> 2;
        break;
    case 8:
        d = *(u16 *)&D_801069D0;
        if ((s16)(d % 12) >= 7) {
            c += 1;
        }
    default:
        func_800A1C4C(3, 0xEF, 0);
        M2C_FIELD(arg0, s16 *, 0xC) = c;
    }
}

void func_800AA2D4(void *arg0) {
    u16 id;
    s16 vol;
    s32 t;

    id = 0;
    if (M2C_FIELD(arg0, s16 *, 0x12) < 9) {
        id = D_800DE154[M2C_FIELD(arg0, u8 *, 0xC)];
        if (D_800DE154[M2C_FIELD(arg0, u8 *, 0xC)] == 0xED) {
            if (D_80106B4C & 4) {
                id = 0x105;
            }
        }
    }
    t = (s16)id;
    if (t != D_80103E2C) {
        D_80103E2C = id;
        if (t == 0) {
            D_8009A000 = 0xA4;
            D_80103E30 = 0;
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
        if (vol != D_80103E30) {
            D_8009A000 = 0xA0;
            D_80103E30 = vol;
            D_8009A004 = vol;
            func_8002DA7C();
        }
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AA440);

void func_800AB494(void) {
    func_80044A68(&D_80103E60, 1, 0, func_8004656C(0, 0, 0x180, 0x100) & 0xFFFF, 0);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AB4DC);

INCLUDE_RODATA("../asm/us/snobo2/nonmatchings/text", D_800A0094);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AB700);

void func_800AB868(void *arg0, u32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s8 *, 0) = (s8) (arg2 + (arg1 >> 0x1C));
    M2C_FIELD(arg0, s8 *, 1) = (s8) (arg2 + ((arg1 >> 0x18) & 0xF));
    M2C_FIELD(arg0, s8 *, 3) = (s8) (arg2 + ((arg1 >> 0x14) & 0xF));
    M2C_FIELD(arg0, s8 *, 4) = (s8) (arg2 + ((arg1 >> 0x10) & 0xF));
    M2C_FIELD(arg0, s8 *, 6) = (s8) (arg2 + ((arg1 >> 0xC) & 0xF));
    M2C_FIELD(arg0, s8 *, 7) = (s8) (arg2 + ((arg1 >> 8) & 0xF));
    M2C_FIELD(arg0, s8 *, 8) = (s8) (arg2 + ((arg1 >> 4) & 0xF));
}

void func_800AB8D8(s32 arg0, s16 arg1, s16 arg2) {
    s16 i;
    s32 sh;

    for (i = 1, sh = 8; i < 4; i++, sh -= 4) {
        D_800DF5DC[i] = (((arg0 & 0xFFFF) >> sh) & 0xF) + 0x10;
    }
    for (i = 1; i < 3; i++) {
        if (D_800DF5DC[i] != 0x10) {
            break;
        }
        D_800DF5DC[i] = 0x40;
    }
    func_800AC42C(D_800DF5DC, arg1, arg2, 0x808080);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AB9AC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ABB50);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ABC54);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ABD5C);

void func_800ABE64(s32 arg0) {
    u8 *p;
    u8 *q;

    p = D_8010538C;
    M2C_FIELD(p, s32 *, 0) = 0x04000000;
    M2C_FIELD(p, s32 *, 4) = 0x65000000;
    q = D_800DF68C + arg0 * 0x10;
    M2C_SFIELD(p, s32 *, 8) = M2C_SFIELD(q, s32 *, 0);
    M2C_SFIELD(p, s32 *, 0xC) = M2C_SFIELD(q, s32 *, 4);
    M2C_SFIELD(p, s32 *, 0x10) = M2C_SFIELD(q, s32 *, 8);
    ((Sb2Tag *)p)->addr = ((Sb2Tag *)(D_80105380 + 8))->addr;
    ((Sb2Tag *)(D_80105380 + 8))->addr = (u32)p;
    p += 0x14;
    M2C_FIELD(p, s32 *, 0) = 0x01000000;
    M2C_SFIELD(p, s32 *, 4) = M2C_SFIELD(q, s32 *, 0xC);
    ((Sb2Tag *)p)->addr = ((Sb2Tag *)(D_80105380 + 8))->addr;
    D_8010538C = p + 8;
    ((Sb2Tag *)(D_80105380 + 8))->addr = (u32)p;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ABF3C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AC1C8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AC42C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AC580);

void *func_800AC914(void *arg0, void *arg1, s32 *arg2) {
    M2C_FIELD(arg1, s32 *, 0) = 0x06000000;
    M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 0) | 0x4C000000);
    M2C_FIELD(arg1, s32 *, 8) = (s32) ((M2C_FIELD(arg0, s16 *, 0x8A) << 0x10) | M2C_FIELD(arg0, u16 *, 0x88));
    M2C_FIELD(arg1, s32 *, 0xC) = (s32) ((M2C_FIELD(arg0, s16 *, 0x8E) << 0x10) | M2C_FIELD(arg0, u16 *, 0x8C));
    M2C_FIELD(arg1, s32 *, 0x10) = (s32) ((M2C_FIELD(arg0, s16 *, 0x92) << 0x10) | M2C_FIELD(arg0, u16 *, 0x90));
    M2C_FIELD(arg1, s32 *, 0x14) = (s32) ((M2C_FIELD(arg0, s16 *, 0x96) << 0x10) | M2C_FIELD(arg0, u16 *, 0x94));
    M2C_FIELD(arg1, s32 *, 0x18) = 0x55555555;
    M2C_FIELD(arg1, s32 *, 0) = (s32) ((M2C_FIELD(arg1, s32 *, 0) & 0xFF000000) | (*arg2 & 0xFFFFFF));
    *arg2 = (*arg2 & 0xFF000000) | ((s32) arg1 & 0xFFFFFF);
    return arg1 + 0x1C;
}

void *func_800AC9C8(void *arg0, void *arg1, s32 *arg2) {
    M2C_FIELD(arg1, s32 *, 0) = 0x02000000;
    M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 0) | 0x68000000);
    M2C_FIELD(arg1, s32 *, 8) = (s32) ((M2C_FIELD(arg0, s16 *, 0x8A) << 0x10) | M2C_FIELD(arg0, u16 *, 0x88));
    M2C_FIELD(arg1, s32 *, 0) = (s32) ((M2C_FIELD(arg1, s32 *, 0) & 0xFF000000) | (*arg2 & 0xFFFFFF));
    *arg2 = (*arg2 & 0xFF000000) | ((s32) arg1 & 0xFFFFFF);
    return arg1 + 0xC;
}

u16 func_800ACA34(u16 arg0) {
    s32 r;
    u16 *p;

    r = 0;
    p = D_800DFA1C;
    while (arg0 != 0) {
        if (arg0 & 1) {
            r = func_800ACAA4(r, *p);
        }
        arg0 >>= 1;
        p++;
    }
    return r;
}

s32 func_800ACAA4(u16 arg0, u16 arg1) {
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

void func_800ACB2C(void) {
    SbUnkFFC40 *p;
    s32 i;

    D_80103F6C = 0;
    p = D_80103E6C;
    for (i = 7; i != -1; i--) {
        p->unk0 = 0;
        p++;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ACB5C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ACCBC);

void func_800ACF90(SbRelocHdr *h) {
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

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AD00C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AD15C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AD2C8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AD4C4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AD714);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AD958);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ADBD8);

void func_800ADD64(void *arg0) {
    void (*var_v0)(void *);

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        D_80105374 = M2C_FIELD(arg0, u16 *, 2);
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFD8000;
            M2C_FIELD(arg0, s32 *, 0x6C) = (s32) M2C_FIELD(arg0, s32 *, 0x7C);
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x80);
            func_800A1C4C(3, 0xF0, 0);
            var_v0 = func_800ADDFC;
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
        } else {
            var_v0 = func_800B43C8;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = var_v0;
    }
}

void func_800ADDFC(void *arg0) {
    s32 y;

    y = M2C_FIELD(arg0, s32 *, 0x2C);
    if (M2C_FIELD(arg0, s32 *, 0x34) < y) {
        M2C_FIELD(arg0, s8 *, 0) = 0;
        return;
    }
    M2C_FIELD(arg0, u16 *, 2) = D_80106A30;
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

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ADE94);

void func_800AE024(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1C4C(3, 0xF0, 0);
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800AE0B0;
        } else {
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) == 2) {
        func_800AE138(arg0);
    }
}

void func_800AE0B0(void *arg0) {
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

void func_800AE138(void *arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x86);
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_v0 + 1);
    M2C_FIELD(arg0, s16 *, 0x22) = (s16) (func_80039A74(func_80039A74((s32) (temp_v0 << 0x10) >> 0xB) >> 4) >> 3);
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AE18C);

void func_800AE324(void *arg0) {
    s32 var_v1;

    if ((M2C_FIELD(arg0, s32 *, 0x30) - D_800DDE90) <= 0x700000) {
        var_v1 = (s32) D_800DDEA0 >> 1;
        if (var_v1 <= 0x7FFF) {
            var_v1 = 0x8000;
        }
        M2C_FIELD(arg0, s32 *, 0x74) = var_v1;
        if (M2C_FIELD(arg0, s16 *, 0x84) != 0) {
            var_v1 = -var_v1;
        }
        M2C_FIELD(arg0, s16 *, 0x14) = 0x40;
        M2C_FIELD(arg0, s32 *, 0x6C) = var_v1;
        M2C_FIELD(arg0, s16 *, 0x8A) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800AE3A4;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AE3A4);

void func_800AE534(void *arg0) {
    s32 var_v0;
    s32 var_v0_2;

    var_v0 = M2C_FIELD(arg0, s32 *, 0x7C) * 3;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    if (var_v0 < 0) {
        var_v0 += 3;
    }
    M2C_FIELD(arg0, s32 *, 0x6C) = (s32) (var_v0 >> 2);
    M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFE0000;
    var_v0_2 = M2C_FIELD(arg0, s32 *, 0x80) * 3;
    if (var_v0_2 < 0) {
        var_v0_2 += 3;
    }
    M2C_FIELD(arg0, s32 *, 0x74) = (s32) (var_v0_2 >> 2);
    M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800AE5B0;
    func_800A1C4C(3, 0x135, 0);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AE5B0);

void func_800AE8A8(void *arg0) {
    s32 temp_v0_3;
    u16 temp_v0;
    u16 temp_v0_2;

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
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + M2C_FIELD(arg0, s32 *, 0x6C));
    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x70) + 0x1000;
    M2C_FIELD(arg0, s32 *, 0x70) = temp_v0_3;
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (temp_v0_3 + M2C_FIELD(arg0, s32 *, 0x2C));
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) + M2C_FIELD(arg0, s32 *, 0x74));
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) - 0x200);
}

void func_800AE944(void *arg0) {
    u16 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1C4C(3, 0x135, 0);
        }
        M2C_FIELD(arg0, u16 *, 0x84) = 0U;
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
    }
    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    M2C_FIELD(arg0, u16 *, 4) = (u16) *(u16 *)(D_800DFBB8 + ((temp_v0 >> 1) & 6));
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AE9D8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AEAD0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AEC70);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AECBC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AEEAC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AF040);

void func_800AF1D8(void *arg0) {
    s32 var_v1;

    if ((M2C_FIELD(arg0, s32 *, 0x30) - D_800DDE90) <= 0x700000) {
        var_v1 = (s32) D_800DDEA0 >> 1;
        if (var_v1 <= 0x7FFF) {
            var_v1 = 0x8000;
        }
        M2C_FIELD(arg0, s32 *, 0x74) = var_v1;
        if (M2C_FIELD(arg0, s16 *, 0x84) != 0) {
            var_v1 = -var_v1;
        }
        M2C_FIELD(arg0, s16 *, 0x14) = 0x40;
        M2C_FIELD(arg0, s32 *, 0x6C) = var_v1;
        M2C_FIELD(arg0, s16 *, 0x8A) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800AF258;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AF258);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AF3D8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AF5EC);

void func_800AF7D4(void *arg0) {
    s32 temp_v0_3;
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
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + M2C_FIELD(arg0, s32 *, 0x6C));
    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x70) + 0x1000;
    M2C_FIELD(arg0, s32 *, 0x70) = temp_v0_3;
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (temp_v0_3 + M2C_FIELD(arg0, s32 *, 0x2C));
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) + M2C_FIELD(arg0, s32 *, 0x74));
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) - 0x200);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AF868);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AFA08);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AFA54);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AFBE8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AFD7C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AFEFC);

void func_800B01EC(void *arg0) {
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

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B027C);

void func_800B0748(Sb2A *p) {
    u16 r;
    s32 t;

    r = p->f84;
    p->f84 = r + 1;
    t = (s16)r;
    if (t >= 0x3D) {
        if (t & 4) {
            p->f4 = 0xDE;
            return;
        }
        p->f4 = 0;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B0788);

void func_800B0888(void *arg0) {
    u16 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFE0000;
            M2C_FIELD(arg0, s16 *, 4) = 0xCA;
            M2C_FIELD(arg0, s16 *, 6) = 0xD0;
            M2C_FIELD(arg0, u8 *, 1) = 0U;
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            M2C_FIELD(arg0, s32 *, 0x6C) = (s32) M2C_FIELD(arg0, s32 *, 0x7C);
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x80);
            *M2C_FIELD(arg0, s8 **, 0x3C) = 0;
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800AF5EC;
            func_800A1C4C(3, 0x135, 0);
            return;
        }
        M2C_FIELD(arg0, u16 *, 0x84) = 0U;
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B0960;
        return;
    }
    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84) + 1;
    M2C_FIELD(arg0, u16 *, 0x84) = temp_v0;
    if ((s16) temp_v0 == 0x3D) {
        M2C_FIELD(arg0, s16 *, 4) = 0xD8;
        M2C_FIELD(arg0, s16 *, 6) = 0xD9;
    }
}

void func_800B0960(void *arg0) {
    u16 temp_a1;
    u16 temp_v0;
    u16 temp_v0_2;
    void *temp_v1;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        temp_v1 = M2C_FIELD(arg0, void **, 0x3C);
        temp_a1 = temp_v0_2 + 1;
        M2C_FIELD(arg0, u16 *, 0x8A) = temp_a1;
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
            M2C_FIELD(temp_v1, s8 *, 0) = 0;
            return;
        }
        M2C_FIELD(temp_v1, u16 *, 0x8A) = temp_a1;
    }
}

void func_800B09B8(Sb2FxC *p)
{
  s32 v;
  s32 a;
  s32 b;
  u16 t;
  p->unk30 += p->unk74;
  v = p->unk70 + 0x1000;
  p->unk28 += p->unk6C;
  a = v + p->unk2C;
  p->unk70 = v;
  b = (((((p->unk30 >> 0xC) - 0xB042) * 0x5865) / 84531) + 0x10A36) << 0xC;
  if (b < a)
  {
    a = b;
    p->unk14 = 0;
    p->unk38 = func_800B43C8;
  }
  t = p->unk86;
  p->unk2C = a;
  p->unk86 = t + 1;
  if (((s16) t) < 0x15)
  {
    p->unk24 = 0;
    p->unk1E += 0x60;
  }
  if (p->unk1 != 0)
  {
    p->unk14 = 0;
    p->unk1 = 0;
    func_800A1C4C(3, 0xF0, 0);
  }
}

void func_800B0AE4(Sb2FxC *p) {
    s32 v;
    s32 a;
    s32 b;

    p->unk30 -= 0x4000;
    v = p->unk70 + 0x1000;
    p->unk28 += p->unk6C;
    a = v + p->unk2C;
    p->unk70 = v;
    b = ((((((p->unk30 >> 0xC) - 0xB042) * 0x5865) / 84531) + 0x10A36) << 0xC) + 0x20;
    if (b < a) {
        a = b;
        p->unk38 = func_800B43C8;
    }
    p->unk2C = a;
}

void func_800B0BA8(Sb2FxQ *arg0) {
    Sb2SlotA *p;
    Sb2SlotA *s;
    s32 i;
    s32 n;
    u8 one;
    u16 id;

    D_800DFD94 = arg0->unk28;
    one = 1;
    n = 0x1F;
    id = D_80106A30;
    i = D_801050F0;
    do {
        p = (Sb2SlotA *)((u8 *)&D_80103F70 + i * 0x8C);
        if (p->flag == 0) {
            D_801050F0 = (i + 1) & 0x1F;
            s = p;
            goto found;
        }
        i = (i + 1) & 0x1F;
    } while (--n != -1);
    s = NULL;
found:
    if (s != NULL) {
        s->flag = one;
        s->unk1 = 0;
        s->unk2 = id;
        s->unk4 = D_800DFD70;
        s->unk6C.x = 0;
        s->unk6C.y = 0;
        s->unk6C.z = 0;
        s->unk6C.w = 0;
        s->unk84 = 0;
        s->unk86 = 0;
        s->unk88 = 0;
        s->unk8A = 0;
    }
    s->unk6C = arg0->unk6C;
}

void func_800B0CF0(Sb2FxQ *arg0, s32 arg1) {
    Sb2SlotA *p;
    Sb2SlotA *s;
    s32 i;
    s32 n;
    s32 *tp;
    u8 one;
    u16 id;

    tp = &D_800DFDF0;
    if (arg1 == 0) {
        goto neg;
    }
    *tp = 0x20;
    goto join;
inner:
    D_801050F0 = (i + 1) & 0x1F;
    s = p;
    goto found;
neg:
    *tp = -0x20;
join:
    D_800DFDDC = arg0->unk28;
    one = 1;
    n = 0x1F;
    id = D_80106A30;
    i = D_801050F0;
    do {
        p = (Sb2SlotA *)((u8 *)&D_80103F70 + i * 0x8C);
        if (p->flag == 0) {
            goto inner;
        }
        i = (i + 1) & 0x1F;
    } while (--n != -1);
    s = NULL;
found:
    if (s != NULL) {
        s->flag = one;
        s->unk1 = 0;
        s->unk2 = id;
        s->unk4 = D_800DFDB8;
        s->unk6C.x = 0;
        s->unk6C.y = 0;
        s->unk6C.z = 0;
        s->unk6C.w = 0;
        s->unk84 = 0;
        s->unk86 = 0;
        s->unk88 = 0;
        s->unk8A = 0;
    }
    s->unk6C = arg0->unk6C;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B0E54);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B0FE4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B1248);

s16 func_800B1588(s32 arg0) {
    return D_800DFE90[arg0 % 6];
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B15C8);

void func_800B192C(void *arg0) {
    s32 temp_v0_3;
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_SFIELD(arg0, u16 *, 0x84);
    M2C_SFIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_SFIELD(arg0, u16 *, 0x8A);
        M2C_SFIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_SFIELD(arg0, s8 *, 0) = 0;
            return;
        }
    }
    M2C_SFIELD(arg0, s32 *, 0x28) = (s32) (M2C_SFIELD(arg0, s32 *, 0x28) + M2C_SFIELD(arg0, s32 *, 0x6C));
    M2C_SFIELD(arg0, s16 *, 0x24) = 0;
    M2C_SFIELD(arg0, u16 *, 2) = (u16) D_80106A30;
    temp_v0_3 = M2C_SFIELD(arg0, s32 *, 0x70) + 0x1000;
    M2C_SFIELD(arg0, s32 *, 0x70) = temp_v0_3;
    M2C_SFIELD(arg0, s32 *, 0x2C) = (s32) (temp_v0_3 + M2C_SFIELD(arg0, s32 *, 0x2C));
    M2C_SFIELD(arg0, s32 *, 0x30) = (s32) (M2C_SFIELD(arg0, s32 *, 0x30) + M2C_SFIELD(arg0, s32 *, 0x74));
    M2C_SFIELD(arg0, u16 *, 0x1E) = (u16) (M2C_SFIELD(arg0, u16 *, 0x1E) + 0x80);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B19D4);

void func_800B1B60(void *arg0) {
    u16 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            func_800B1C7C(arg0);
            return;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
        goto block_4;
    }
block_4:
    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x10) {
        M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFF0000;
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B1BEC;
    }
}

void func_800B1BEC(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    if (M2C_FIELD(arg0, u8 *, 1) & 2) {
        func_800B1C7C(arg0);
        return;
    }
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x70) + 0x1000;
    M2C_FIELD(arg0, s32 *, 0x70) = temp_v0;
    temp_v0_2 = temp_v0 + M2C_FIELD(arg0, s32 *, 0x2C);
    M2C_FIELD(arg0, s32 *, 0x2C) = temp_v0_2;
    if (M2C_FIELD(arg0, s32 *, 0x34) < temp_v0_2) {
        M2C_FIELD(arg0, s16 *, 6) = 0xE5;
        M2C_FIELD(arg0, s16 *, 0x84) = 0;
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B1B60;
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x34);
        return;
    }
    M2C_FIELD(arg0, s16 *, 6) = 0xD0;
}

void func_800B1C7C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0) = 2;
    M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFE0000;
    M2C_FIELD(arg0, s16 *, 0x84) = 0;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800B1CD8;
    M2C_FIELD(arg0, s32 *, 0x6C) = (s32) M2C_FIELD(arg0, s32 *, 0x7C);
    M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x80);
    func_800A1C4C(3, 0x135, 0);
}

void func_800B1CD8(void *arg0) {
    s32 temp_v0_3;
    u16 temp_v0;
    u16 temp_v0_2;

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
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + M2C_FIELD(arg0, s32 *, 0x6C));
    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x70) + 0x1000;
    M2C_FIELD(arg0, s32 *, 0x70) = temp_v0_3;
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (temp_v0_3 + M2C_FIELD(arg0, s32 *, 0x2C));
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) + M2C_FIELD(arg0, s32 *, 0x74));
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) + 0x80);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B1D74);

void func_800B1F34(Sb2FxR *arg0) {
    s32 t;
    s32 u;
    s32 v;
    u16 w;

    if (arg0->unk1 != 0) {
        arg0->unk0 = 0;
        func_800A1C4C(3, 0xF9, 0);
        switch (arg0->unk3C) {
        case 3:
            func_800B2110();
            D_801053A4 = 1;
            return;
        case 4:
            func_800B2260();
            D_80105388 = 1;
            return;
        default:
            D_801069BC += D_800DFF2C[arg0->unk3C];
            return;
        }
    } else {
        w = arg0->unk84;
        t = w << 0x10;
        arg0->unk84 = w + 1;
        arg0->unk4 = ((t >> 0x13) & 3) + 0xB8;
        arg0->unk2C = (func_80039A74(t >> 0xB) * 2) + arg0->unk2C;
        u = (s16)D_80105374;
        if (u != 0) {
            v = u - arg0->unk2;
            if (v < 0) {
                v = -v;
            }
            if (v < 2) {
                arg0->unk38 = func_800B2084;
                D_80105374 = 0;
            }
        }
    }
}

void func_800B2084(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x88);
    M2C_FIELD(arg0, u16 *, 0x88) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
            return;
        }
    }
    temp_v0_3 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0_3 + 1);
    M2C_FIELD(arg0, s16 *, 4) = (s16) (((temp_v0_3 >> 3) & 3) + 0xB8);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + M2C_FIELD(arg0, s32 *, 0x70));
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) (M2C_FIELD(arg0, s32 *, 0x70) - 0x800);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2110);

void func_800B220C(void *arg0) {
    u16 temp_v0;

    func_800ABB50(M2C_FIELD(arg0, s16 *, 0x84));
    temp_v0 = (u16) M2C_FIELD(arg0, s16 *, 0x84);
    M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        M2C_FIELD(arg0, s8 *, 0) = 0;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2260);

void func_800B235C(void *arg0) {
    u16 temp_v0;

    func_800ABD5C(M2C_FIELD(arg0, s16 *, 0x84));
    temp_v0 = (u16) M2C_FIELD(arg0, s16 *, 0x84);
    M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        M2C_FIELD(arg0, s8 *, 0) = 0;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B23B0);

void func_800B2534(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B25A0;
            func_800A1C4C(1, 0x10C, 0x7F);
            return;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
    }
}

void func_800B25A0(void *arg0) {
    u16 temp_a0;

    temp_a0 = M2C_FIELD(arg0, u16 *, 0x86);
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_a0 + 1);
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) - (func_80039A74((s32) (temp_a0 << 0x10) >> 0x11) >> 2));
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    if ((s16) M2C_FIELD(arg0, u16 *, 0x1E) < -0x480) {
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2610);

void func_800B2794(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B2800;
            func_800A1C4C(1, 0x10C, 0x7F);
            return;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
    }
}

void func_800B2800(void *arg0) {
    u16 temp_a0;

    temp_a0 = M2C_FIELD(arg0, u16 *, 0x86);
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_a0 + 1);
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) + (func_80039A74((s32) (temp_a0 << 0x10) >> 0x11) >> 2));
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    if ((s16) M2C_FIELD(arg0, u16 *, 0x1E) >= 0x481) {
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2870);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B29EC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2B60);

void func_800B2D0C(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1C4C(2, 0x10C, 0);
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2D70);

void func_800B2EE4(void *arg0) {
    void (*var_v1)(void *);

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1C4C(2, 0x10C, 0);
            var_v1 = func_800B2FB4;
            if ((u16) D_801053B4 & 0x800) {
                var_v1 = func_800B2F74;
            }
            M2C_FIELD(arg0, void (**)(void *), 0x38) = var_v1;
            return;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
    }
}

void func_800B2F74(void *arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84) + 8;
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) - temp_v0);
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, u16 *, 0x84) = temp_v0;
    if ((s16) M2C_FIELD(arg0, u16 *, 0x1E) < -0x500) {
        M2C_FIELD(arg0, u16 *, 0x84) = 0U;
        M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800B43C8;
    }
}

void func_800B2FB4(void *arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84) + 8;
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (temp_v0 + M2C_FIELD(arg0, u16 *, 0x1E));
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, u16 *, 0x84) = temp_v0;
    if ((s16) M2C_FIELD(arg0, u16 *, 0x1E) >= 0x501) {
        M2C_FIELD(arg0, u16 *, 0x84) = 0U;
        M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800B43C8;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2FF4);

void func_800B31D8(void *arg0) {
    s32 dx;
    s32 dz;

    M2C_FIELD(arg0, s16 *, 0x8A) = -(M2C_FIELD(arg0, s16 *, 2) - D_80106A30 >= 3);
    dx = (D_800DDE88.v[0] - M2C_FIELD(arg0, s32 *, 0x28)) >> 12;
    dz = (D_800DDE90 - M2C_FIELD(arg0, s32 *, 0x30)) >> 12;
    if (func_80039F5C(dx * dx + dz * dz) < (s16)D_800DDE78 + 0x400) {
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B32B0;
        if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0x180;
        } else {
            M2C_FIELD(arg0, s16 *, 0x14) = 0x40;
        }
        M2C_FIELD(arg0, s16 *, 0x16) = 0x100;
        M2C_FIELD(arg0, s16 *, 0x18) = 0x100;
    }
}

void func_800B32B0(Sb2FxE *p) {
    p->unk70 += 0x1000;
    p->unk2C += p->unk70;
    if (p->unk34 < p->unk2C) {
        p->unk38 = func_800B3370;
        p->unk84 = 0x3C;
    }
    if (p->unk86 == 0 && p->unk34 - 0x20000 < p->unk2C) {
        func_800A1C4C(3, 0x1AB, 0);
        p->unk86 = 1;
    }
    if (p->unk1 & 2) {
        func_800A1C4C(2, 0xF0, 0);
        p->unk1 = 0;
        p->unk14 = 0;
    }
}

void func_800B3370(void *arg0) {
    s16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x84);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v0 - 1);
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            func_800A1C4C(2, 0xF0, 0);
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

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B33F8);

void func_800B3598(Sb2FxF *p) {
    s32 t;
    s32 v;

    if (func_800B3664(p) == 0) {
        t = (p->unk86 << 5) + p->unk88;
        p->unk28 = func_80039A74(t) * 0x1C0 + p->unk3C;
        v = func_80039B40(t);
        p->unk2C = 0;
        p->unk24 = 0;
        p->unk30 = v * 0x1C0 + p->unk40;
        p->unk20 += 0x20;
        p->unk2C = (func_80039A74((p->unk86 << 6) + p->unk88) << 6) + p->unk44;
        p->unk86++;
    }
}

s32 func_800B3664(void *arg0) {
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
                return 1;
            }
            goto block_8;
        }
        
        return 0;
    }
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x84) = 0;
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800B3738;
            M2C_FIELD(arg0, s32 *, 0x6C) = (s32) M2C_FIELD(arg0, s32 *, 0x7C);
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x80);
            func_800A1C4C(2, 0x10C, 0);
            return 1;
        }
        M2C_FIELD(arg0, s16 *, 0x84) = 1;
block_8:
        
        return 0;
    }
    return 0;
}

void func_800B3738(Sb2FxD *p) {
    if ((s16)p->unk84++ >= 0x3D) {
        if ((s16)p->unk8A++ >= 0x1F) {
            p->unk0 = 0;
        }
    }
    p->unk24 = 0;
    p->unk28 += p->unk6C;
    p->unk30 += p->unk74;
    p->unk70 -= 0xC00;
    p->unk2C = p->unk70 + p->unk2C;
    p->unk20 += p->unk48;
    if (p->unk48 < 0) {
        p->unk48 -= 4;
    } else {
        p->unk48 += 4;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B37E8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B398C);

void func_800B3AB4(void) {
    s32 var_v1;

    var_v1 = D_800DDE9C;
    D_800DDE70 = 0xB;
    if (var_v1 < 0) {
        var_v1 = -var_v1;
    }
    if (var_v1 <= 0x3FFFF) {
        var_v1 = 0x40000;
    }
    D_800DDE9C = var_v1;
    func_800A1C4C(2, 0x10C, 0);
}

void func_800B3B14(void) {
    s32 *p;
    s32 i;

    p = D_801050F4;
    for (i = 0x9F; i != -1; i--) {
        *p++ = 0;
    }
    D_80105374 = 0;
}

void func_800B3B44(s16 arg0) {
    s32 first;

    first = 0;
    if (((u8 *)D_801050F4)[arg0] == 0) {
        first = 1;
        ((u8 *)D_801050F4)[arg0] = 1;
    }
    if (D_800E0F04[arg0] != NULL) {
        D_800E0F04[arg0](arg0, first);
    }
}

void func_800B3BB4(void) {
    s32 var_v0;
    s8 *var_v1;

    var_v1 = &D_80103F70;
    var_v0 = 0x1F;
    do {
        *var_v1 = 0;
        var_v0 -= 1;
        var_v1 += 0x8C;
    } while (var_v0 != -1);
    D_801050F0 = 0;
    D_80105378 = 0;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B3BEC);

void func_800B43C8(void *arg0) {
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

void func_800B4414(s16 arg0, s32 arg1) {
    if ((arg1 != 0) && ((u8) D_80106AF6 >= 0x46U)) {
        func_800B1D74(arg0, &D_800E01C0);
    }
}

void func_800B4458(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2870(arg0, &D_800E01CC);
        if (D_801053A4 != 0 && D_80106B08 != 0 && D_80106B08 <= 0x104FFFF) {
            func_800B1D74(arg0, &D_800E01D8);
        }
    }
    if (D_80105398 == 0 && D_80106A30 == arg0) {
        D_80106A28 = 1;
        D_80105398 = 1;
    }
}

void func_800B4524(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E01E4);
    }
}

void func_800B4554(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E01F0);
    }
}

void func_800B4584(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E01FC);
    }
}

void func_800B45B4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0208);
    }
}

void func_800B45E4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0214);
    }
}

void func_800B4614(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0220);
    }
}

void func_800B4644(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E022C);
    }
}

void func_800B4674(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0238);
    }
}

void func_800B46A4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0244);
    }
}

void func_800B46D4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0250);
    }
}

void func_800B4704(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E025C);
    }
}

void func_800B4734(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0268);
    }
}

void func_800B4764(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0274);
    }
}

void func_800B4794(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0280);
    }
}

void func_800B47C4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E028C);
    }
}

void func_800B47F4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0298);
    }
}

void func_800B4824(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E02A4);
    }
}

void func_800B4854(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E02B0);
    }
}

void func_800B4884(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, D_800E02D0);
        func_800ADBD8(arg0, D_800E02BC);
        func_800ADBD8(arg0, D_800E02BC + 0xA);
    }
}

void func_800B48E8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E02DC);
    }
}

void func_800B4918(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E02E8);
    }
}

void func_800B4948(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E02F4);
    }
}

void func_800B4978(s32 arg0, s32 arg1) {
    s32 t;

    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0300);
    }
    if (arg0 == D_80106A30 && (u32)((u16)D_801069D0 - 0x18) < 0x18 && (u8)D_800DDE70 != 0xA && (u8)D_800DDE70 != 0xC) {
        t = (D_800DDE7C - D_800DDE8C) >> 12;
        if (t >= 0x100) {
            if (t < 0x1C0) {
                D_800DDE70 = 0xC;
                func_800A1C4C(2, 0xF0, 0);
            } else if (t < 0x1C8) {
                D_800DDE70 = 0xA;
                func_800A1C4C(2, 0xF0, 0);
            }
        }
    }
}

void func_800B4A54(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AE18C(arg0, &D_800E030C);
        func_800B23B0(arg0, &D_800E0314);
    }
}

void func_800B4AA0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AE18C(arg0, &D_800E0320);
        func_800B23B0(arg0, &D_800E0328);
    }
}

void func_800B4AEC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0334);
    }
}

void func_800B4B1C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, &D_800E0340);
        func_800AEAD0(arg0, &D_800E034C);
    }
}

void func_800B4B68(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, &D_800E0358);
        func_800AEAD0(arg0, &D_800E0364);
    }
}

void func_800B4BB4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0370);
    }
}

void func_800B4BE4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E037C);
    }
}

void func_800B4C14(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0388);
    }
}

void func_800B4C44(s16 arg0, s32 arg1) {
    s32 i;

    if (arg1 != 0) {
        for (i = 0; i < 5; i++) {
            func_800B23B0(arg0, D_800E0394 + i * 0xA);
        }
    }
}

void func_800B4CA4(s16 arg0, s32 arg1) {
    s32 i;

    if (arg1 != 0) {
        for (i = 0; i < 6; i++) {
            func_800B23B0(arg0, D_800E03C8 + i * 0xA);
        }
    }
}

void func_800B4D04(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AF040(arg0, &D_800E0404);
        func_800B23B0(arg0, &D_800E040C);
    }
}

void func_800B4D50(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AF040(arg0, &D_800E0418);
        func_800B23B0(arg0, &D_800E0420);
    }
}

void func_800B4D9C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E042C);
    }
}

void func_800B4DCC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0438);
    }
}

void func_800B4DFC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, &D_800E0444);
        func_800AF868(arg0, &D_800E0450);
    }
}

void func_800B4E48(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, &D_800E045C);
        func_800AF868(arg0, &D_800E0468);
    }
}

void func_800B4E94(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, &D_800E0474);
        func_800AF868(arg0, &D_800E0480);
    }
}

void func_800B4EE0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E048C);
    }
}

void func_800B4F10(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, &D_800E0498);
    }
}

void func_800B4F40(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, D_800E04A4);
        func_800AFD7C(arg0, D_800E04A4 + 0xA);
    }
}

void func_800B4F94(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, D_800E04B8);
        func_800AFD7C(arg0, D_800E04B8 + 0xA);
    }
}

void func_800B4FE8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, D_800E04CC);
        func_800AFD7C(arg0, D_800E04CC + 0xA);
    }
}

void func_800B503C(s32 arg0, s32 arg1) {
    s32 t;

    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E04E0);
    }
    if (arg0 == D_80106A30 && (u32)((u16)D_801069D0 - 0x18) < 0x18 && (u8)D_800DDE70 != 0xA && (u8)D_800DDE70 != 0xC) {
        t = (D_800DDE7C - D_800DDE8C) >> 12;
        if (t >= 0x100) {
            if (t < 0x1C0) {
                D_800DDE70 = 0xC;
                func_800A1C4C(2, 0xF0, 0);
            } else if (t < 0x1C8) {
                D_800DDE70 = 0xA;
                func_800A1C4C(2, 0xF0, 0);
            }
        }
    }
}

void func_800B5118(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E04EC);
    }
}

void func_800B5148(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2870(arg0, &D_800E04F8);
    }
}

void func_800B5178(s16 arg0, s32 arg1) {
    if ((arg1 != 0) && (D_800C828E != 0)) {
        func_800B2870(arg0, &D_800E0504);
    }
}

void func_800B51B8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2870(arg0, &D_800E0510);
        func_800B1D74(arg0, &D_800E051C);
        func_800B29EC(arg0, &D_800E0528);
        if (D_801053A4 != 0 && D_80106B1C != 0 && D_80106B1C <= 0x11FFFFF) {
            func_800B1D74(arg0, &D_800E0530);
        }
    }
    if (D_80105398 == 0 && D_80106A30 == arg0) {
        D_80106A28 = 2;
        D_80105398 = 1;
    }
}

void func_800B52A4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E053C);
        func_800B1D74(arg0, &D_800E0544);
    }
}

void func_800B52F0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E0550);
    }
}

void func_800B5320(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E0558);
    }
}

void func_800B5350(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E0560);
    }
}

void func_800B5380(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E0568);
        func_800B1D74(arg0, &D_800E0570);
    }
}

void func_800B53CC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E057C);
    }
}

void func_800B53FC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E0584);
    }
}

void func_800B542C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, D_800E058C);
        func_800B29EC(arg0, D_800E058C + 8);
    }
}

void func_800B5480(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E059C);
    }
}

void func_800B54B0(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E05A8);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B5544(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E05B0);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B55D8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E05B8);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B566C(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E05C0);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B5700(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E05C8);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B5794(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E05DC);
        func_800B1D74(arg0, &D_800E05D0);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B5844(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E05E4);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B58D8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E05EC);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B596C(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E05F4);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B5A00(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E05FC);
    }
}

void func_800B5A30(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E0608);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B5AC4(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, D_800E0610);
        func_800B2D70(arg0, D_800E0610 + 8);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B5B7C(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0620);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B5C10(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, D_800E062C);
        func_800B2D70(arg0, D_800E062C + 8);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B5CC8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E063C);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B5D5C(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, D_800E0644);
        func_800B2D70(arg0, D_800E0644 + 8);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B5E14(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, D_800E0654);
        func_800B2D70(arg0, D_800E0654 + 8);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B5ECC(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E0664);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B5F60(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, D_800E066C);
        func_800B2D70(arg0, D_800E066C + 8);
        func_800B1D74(arg0, &D_800E067C);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B6028(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E0688);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B60BC(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, &D_800E0690);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B6150(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0698);
    }
}

void func_800B6180(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, D_800E06A4);
        func_800B2D70(arg0, D_800E06A4 + 8);
        func_800B2D70(arg0, D_800E06A4 + 0x10);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B6244(s32 arg0) {
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B62AC(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E06BC);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B6340(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, D_800E06C8);
        func_800B2D70(arg0, D_800E06C8 + 8);
        func_800B2D70(arg0, D_800E06C8 + 0x10);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B6404(s32 arg0) {
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B646C(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E06E0);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B6500(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2D70(arg0, D_800E06EC);
        func_800B2D70(arg0, D_800E06EC + 8);
        func_800B2D70(arg0, D_800E06EC + 0x10);
    }
    if ((D_80106A30 == arg0) && ((u8)D_800DDE70 != 0xB) && (((D_800DDE7C - D_800DDE8C) >> 12) >= 0x241)) {
        func_800B3AB4();
    }
}

void func_800B65C4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0704);
    }
}

void func_800B65F4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0710);
    }
}

void func_800B6624(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E071C);
    }
}

void func_800B6654(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, D_800E0728);
        func_800B33F8(arg0, D_800E0734);
        func_800B33F8(arg0, D_800E0734 + 0xA);
    }
}

void func_800B66B8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B37E8(arg0, D_800E0748);
        func_800B37E8(arg0, D_800E0748 + 0xE);
    }
}

void func_800B670C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B37E8(arg0, D_800E0764);
        func_800B37E8(arg0, D_800E0764 + 0xE);
    }
}

void func_800B6760(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B37E8(arg0, D_800E0780);
        func_800B37E8(arg0, D_800E0780 + 0xE);
    }
}

void func_800B67B4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B37E8(arg0, D_800E079C);
        func_800B37E8(arg0, D_800E079C + 0xE);
    }
}

void func_800B6808(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B37E8(arg0, &D_800E07B8);
    }
}

void func_800B6838(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B37E8(arg0, D_800E07C8);
        func_800B37E8(arg0, D_800E07C8 + 0xE);
    }
}

void func_800B688C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, D_800E07E4);
        func_800B1D74(arg0, D_800E07F0);
        func_800ADBD8(arg0, D_800E07FC);
        func_800ADBD8(arg0, D_800E07FC + 0xA);
    }
}

void func_800B6900(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADE94(arg0, &D_800E0810);
    }
}

void func_800B6930(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E081C);
    }
}

void func_800B6960(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0828);
    }
}

void func_800B6990(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0834);
    }
}

void func_800B69C0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0840);
        func_800ADBD8(arg0, &D_800E084C);
    }
}

void func_800B6A0C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0858);
    }
}

void func_800B6A3C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, D_800E0864);
        func_800ADBD8(arg0, D_800E0870);
        func_800ADBD8(arg0, D_800E0870 + 0xA);
    }
}

void func_800B6AA0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0884);
    }
}

void func_800B6AD0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0890);
    }
}

void func_800B6B00(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E089C);
    }
}

void func_800B6B30(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E08A8);
    }
}

void func_800B6B60(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E08B4);
    }
}

void func_800B6B90(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E08C0);
    }
}

void func_800B6BC0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E08CC);
    }
}

void func_800B6BF0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, D_800E08D8);
        func_800B2610(arg0, D_800E08D8 + 0xA);
    }
}

void func_800B6C44(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, D_800E08EC);
        func_800B2610(arg0, D_800E08EC + 0xA);
        func_800B1D74(arg0, D_800E0900);
    }
}

void func_800B6CA8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E090C);
    }
}

void func_800B6CD8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0918);
    }
}

void func_800B6D08(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0924);
    }
}

void func_800B6D38(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0930);
    }
}

void func_800B6D68(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E093C);
    }
}

void func_800B6D98(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, D_800E0948);
        func_800B2610(arg0, D_800E0948 + 0xA);
    }
}

void func_800B6DEC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E095C);
    }
}

void func_800B6E1C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0968);
    }
}

void func_800B6E4C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0974);
    }
}

void func_800B6E7C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0980);
        func_800ADE94(arg0, &D_800E098C);
    }
}

void func_800B6EC8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0998);
    }
}

void func_800B6EF8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E09A4);
    }
}

void func_800B6F28(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E09B0);
    }
}

void func_800B6F58(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E09BC);
    }
}

void func_800B6F88(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADE94(arg0, &D_800E09C8);
    }
}

void func_800B6FB8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E09D4);
    }
}

void func_800B6FE8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E09E0);
    }
}

void func_800B7018(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E09EC);
    }
}

void func_800B7048(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADE94(arg0, &D_800E09F8);
    }
}

void func_800B7078(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E0A04);
    }
}

void func_800B70A8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0A10);
    }
}

void func_800B70D8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E0A1C);
    }
}

void func_800B7108(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0A28);
    }
}

void func_800B7138(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0A34);
    }
}

void func_800B7168(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0A40);
    }
}

void func_800B7198(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0A4C);
    }
}

void func_800B71C8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E0A58);
    }
}

void func_800B71F8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0A64);
    }
}

void func_800B7228(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADE94(arg0, D_800E0A70);
        func_800ADE94(arg0, D_800E0A70 + 0xA);
    }
}

void func_800B727C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0A84);
    }
}

void func_800B72AC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2870(arg0, &D_800E0A90);
    }
}

void func_800B72DC(s16 arg0, s32 arg1) {
    if ((arg1 != 0) && (D_800C82CE != 0)) {
        func_800B2870(arg0, &D_800E0A9C);
    }
}

void func_800B731C(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2870(arg0, &D_800E0AA8);
        if (D_801053A4 != 0 && D_80106B30 != 0 && D_80106B30 <= 0x134FFFF) {
            func_800B1D74(arg0, &D_800E0AB4);
        }
    }
    if (D_80105398 == 0 && D_80106A30 == arg0) {
        D_80106A28 = 3;
        D_80105398 = 1;
    }
}

void func_800B73E8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, D_800E0AC0);
        func_800B1D74(arg0, D_800E0AC0 + 0xA);
    }
}

void func_800B743C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, D_800E0AD4);
        func_800B1D74(arg0, D_800E0AD4 + 0xA);
    }
}

void func_800B7490(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, D_800E0AE8);
        func_800B1D74(arg0, D_800E0AE8 + 0xA);
    }
}

void func_800B74E4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, D_800E0AFC);
        func_800B1D74(arg0, D_800E0AFC + 0xA);
    }
}

void func_800B7538(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0B10);
    }
}

void func_800B7568(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0B1C);
    }
}

void func_800B7598(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0B28);
    }
}

void func_800B75C8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0B34);
    }
}

void func_800B75F8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0B40);
    }
}

void func_800B7628(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0B4C);
    }
}

void func_800B7658(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0B58);
    }
}

void func_800B7688(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0B64);
    }
}

void func_800B76B8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0B74);
    }
}

void func_800B76E8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0B84);
    }
}

void func_800B7718(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0B94);
    }
}

void func_800B7748(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0BA4);
    }
}

void func_800B7778(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0BB4);
    }
}

void func_800B77A8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0BC4);
    }
}

void func_800B77D8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0BD4);
    }
}

void func_800B7808(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0BE4);
    }
}

void func_800B7838(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0BF4);
    }
}

void func_800B7868(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C04);
    }
}

void func_800B7898(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C14);
    }
}

void func_800B78C8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C24);
    }
}

void func_800B78F8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C34);
    }
}

void func_800B7928(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C44);
    }
}

void func_800B7958(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C54);
    }
}

void func_800B7988(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C64);
    }
}

void func_800B79B8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C74);
    }
}

void func_800B79E8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C84);
        func_800B1D74(arg0, &D_800E0C94);
    }
}

void func_800B7A34(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0CA0);
    }
}

void func_800B7A64(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0CB0);
    }
}

void func_800B7A94(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0CC0);
    }
}

void func_800B7AC4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0CD0);
        func_800B1D74(arg0, &D_800E0CE0);
    }
}

void func_800B7B10(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0CEC);
    }
}

void func_800B7B40(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0CF8);
    }
}

void func_800B7B70(void) {
}

void func_800B7B78(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D04);
        func_800B1D74(arg0, &D_800E0D10);
    }
}

void func_800B7BC4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D1C);
    }
}

void func_800B7BF4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D28);
    }
}

void func_800B7C24(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D34);
    }
}

void func_800B7C54(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0D40);
    }
}

void func_800B7C84(void) {
}

void func_800B7C8C(void) {
}

void func_800B7C94(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D4C);
    }
}

void func_800B7CC4(void) {
}

void func_800B7CCC(void) {
}

void func_800B7CD4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D58);
    }
}

void func_800B7D04(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D64);
        func_800B1D74(arg0, &D_800E0D70);
    }
}

void func_800B7D50(void) {
}

void func_800B7D58(void) {
}

void func_800B7D60(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D7C);
    }
}

void func_800B7D90(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D88);
        func_800B1D74(arg0, &D_800E0D94);
    }
}

void func_800B7DDC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, D_800E0DA0);
        func_800B2B60(arg0, D_800E0DA0 + 0xA);
    }
}

void func_800B7E30(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0DB4);
    }
}

void func_800B7E60(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0DC0);
    }
}

void func_800B7E90(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0DCC);
    }
}

void func_800B7EC0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0DD8);
    }
}

void func_800B7EF0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0DE4);
    }
}

void func_800B7F20(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0DF0);
    }
}

void func_800B7F50(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0DFC);
    }
}

void func_800B7F80(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0E08);
    }
}

void func_800B7FB0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0E14);
    }
}

void func_800B7FE0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0E20);
    }
}

void func_800B8010(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1248(arg0, &D_800E0E2C);
        func_800B1D74(arg0, &D_800E0E3C);
    }
}

void func_800B805C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1248(arg0, &D_800E0E48);
    }
}

void func_800B808C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1248(arg0, D_800E0E58);
        func_800B1248(arg0, D_800E0E58 + 0x10);
        func_800B1D74(arg0, D_800E0E78);
    }
}

void func_800B80F0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1248(arg0, &D_800E0E84);
    }
}

void func_800B8120(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1248(arg0, D_800E0E94);
        func_800B1248(arg0, D_800E0E94 + 0x10);
        func_800B1D74(arg0, D_800E0EB4);
    }
}

void func_800B8184(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1248(arg0, &D_800E0EC0);
        func_800B1D74(arg0, &D_800E0ED0);
    }
}

void func_800B81D0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1248(arg0, &D_800E0EDC);
    }
}

void func_800B8200(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0EEC);
    }
}

void func_800B8230(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2870(arg0, &D_800E0EF8);
    }
}
