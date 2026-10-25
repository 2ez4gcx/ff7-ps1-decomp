#include "common.h"
#include "condor/decls.h"

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A037C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A0548);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A115C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A1A80);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A1B94);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A1EEC);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A2068);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A224C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A2414);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A254C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A2640);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A2798);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A28E4);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A2B40);

void func_800A2CB4(u16 arg0, u16 arg1) {
    CondorAnim *a;
    CondorPrim *p;
    CondorPrim *q;
    s32 n;
    s32 i;
    u16 clut;

    a = &D_8010BB94[arg0];
    n = a->w * a->h;
    p = (CondorPrim *)(D_80120C2C + (a->a << 4));
    q = (CondorPrim *)(D_80120C2C + 0x69BC + (a->a << 4));
    clut = func_80046634(0x380, arg1 + 0xF0);
    for (i = 0; i < n; i++) {
        q->clut = clut;
        p->clut = clut;
        p++;
        q++;
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A2D68);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A2FD4);

u8 func_800A3260(u32 arg0) {
    u32 q;

    if (D_8012C53C == 0) {
        if (D_8012C430 == 0) {
            return -(arg0 != 1);
        }
        return 0;
    }
    q = D_8012C53C / arg0;
    if (q == 0) {
        return -(D_8012C430 == 0);
    }
    D_8012C430++;
    D_8012C53C -= q * arg0;
    return q;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A3304);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A3A98);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A427C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A46E4);

void func_800A4B2C(void) {
    if (D_80121EF0[D_8012C3F0].f > 0x50) {
        D_8012C488 = 1;
    } else {
        D_8012C488 = 3;
    }
    D_8012C47C = 2;
    D_8012C484 = 1;
    D_8012C480 = 1;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A4BB0);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A4DFC);

void func_800A5210(s16 arg0, s32 arg1) {
    arg1 += 0x27;
    D_8009A000 = arg1;
    D_8009A004 = 0x40;
    D_8009A008 = arg0;
    func_8002DA7C(arg0, arg1);
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A5258);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A5B64);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A5E04);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A6048);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A6298);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A6430);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A65BC);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A6808);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A698C);

void func_800A709C(s32 arg0, s32 arg1) {
    s16 t;
    s32 x0 = arg0 * 0x78;
    s32 x1 = arg1 * 0x78;

    D_8012C3EC = 0;
    D_8012C42C = 0;
    D_800BE8ED[x0] = 0;
    D_800BE8ED[x1] = 0;
    if (D_8012C4BC == 0) {
        t = D_8012C424;
        D_8012C41C = D_8012C424;
        if (D_800BE8C0[t].flags != 0 && D_800BE8C5[t * 0x78] == 0) {
            D_8012C428 = 0;
            if (((s16 (*)(void *))func_800B2CD8)(&D_800BE8C0[t]) != 0) {
                func_800A93A0();
                goto end;
            }
        }
    } else {
        D_8012C3E8 = 1;
        D_8012C41C = -1;
    }
    D_8012C47C = 1;
    D_8012C484 = 1;
    D_8012C480 = 1;
end:
    D_8012C4BC = 0;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A71D8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A73AC);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A7584);

void func_800A76BC(s32 arg0) {
    u32 t;
    s32 oct;

    t = (u32)(arg0 & 0x1FF) >> 1;
    oct = arg0 & 0xE00;
    switch (oct) {
    case 0x200:
        D_8012C544 = -0x100;
        D_8012C548 = 0xFF - t;
        break;
    case 0x400:
        D_8012C544 = -0x100;
        D_8012C548 = -t;
        break;
    case 0x600:
        D_8012C544 = t - 0xFF;
        D_8012C548 = -0x100;
        break;
    case 0x800:
        D_8012C544 = t;
        D_8012C548 = -0x100;
        break;
    case 0xA00:
        D_8012C544 = 0x100;
        D_8012C548 = t - 0xFF;
        break;
    case 0xC00:
        D_8012C544 = 0x100;
        D_8012C548 = t;
        break;
    case 0xE00:
        D_8012C544 = 0xFF - t;
        D_8012C548 = 0x100;
        break;
    case 0:
        D_8012C544 = -t;
        D_8012C548 = 0x100;
        break;
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A77EC);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A7BF4);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A7E20);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A8004);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A8158);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A8454);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A85DC);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A8AA8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A8D08);

s32 func_800A93A0(void) {
    if (D_8012C404 == 1) {
        return 1;
    }
    if (D_8012C41C == -1) {
        return 0;
    }
    func_800A427C();
    D_8012C3E8 = 2;
    D_8012C4E4 = 0;
    D_8012C4F8 = -8;
    D_8012C4F0 = -8;
    D_8012C4FC = 1;
    D_8012C4F4 = 1;
    if (D_80121EF0[D_8012C3F0].f > 0x50) {
        D_8012C488 = 1;
    } else {
        D_8012C488 = 3;
    }
    D_8012C47C = 2;
    D_8012C484 = 1;
    D_8012C480 = 1;
    func_800AB5BC();
    return 0;
}

s32 func_800A94B0(void) {
    CondorPos sp;

    if (D_8012C3EC != 0) {
        return 1;
    }
    if (D_8012C5CC != 0) {
        return 1;
    }
    if (D_8012C41C != -1) {
        return 1;
    }
    if (D_8012C508 >= 0x14) {
        return 1;
    }
    if (D_8012C404 == 1) {
        if (D_8012C3A6 >= 0x2A0) {
            return 1;
        }
    } else {
        if (D_8012C3A6 >= D_8012C530) {
            return 1;
        }
    }
    sp.z = -0x28;
    sp.x = D_8012C3A4;
    sp.y = 0x400 - D_8012C3A6;
    if (func_800AC5C0(0, &sp) == 1) {
        return 1;
    }
    D_8012C5C0 = 1;
    return 0;
}

void func_800A95C0(void) {
    D_8012C41C = -1;
    D_8012C524 = 0x100;
    D_8012C528 = 0;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A95E8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A9B20);

void func_800AB5BC(void) {
    switch (D_800BE8D0[D_8012C41C].kind) {
    case 0:
        D_8012C56C = 1;
        D_8012C570 = 2;
        break;
    case 3:
    case 4:
        D_8012C56C = 2;
        D_8012C570 = 5;
        D_8012C574 = 2;
        break;
    case 1:
    case 2:
    case 5:
        D_8012C56C = 1;
        D_8012C570 = 3;
        break;
    case 6:
        D_8012C56C = 2;
        D_8012C570 = 3;
        D_8012C574 = 0;
        break;
    case 7:
    default:
        D_8012C56C = 0;
        break;
    }
}

void func_800AB6B0(s32 arg0) {
    u16 *var_a1;

    var_a1 = &D_8012C3A4;
    if (D_8012C5CC == 0) {
        var_a1 = &D_8012C3AC;
    }
    if ((D_8012C3E8 != 3) && (D_8012C3EC == 0)) {
        var_a1 = &D_8012C3A4;
    }
    func_800AB71C(arg0, var_a1);
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AB71C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800ABA58);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800ABC18);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800ABE54);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AC1A8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AC498);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AC5C0);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AC68C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AC72C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800ACAA4);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800ACDB0);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AD02C);

void func_800AD288(void) {
    u8 v;

    if (D_8012C56C == 0) {
        D_8012C570 = 7;
    }
    v = D_8012C570;
    if (D_8012C4E4 == 1) {
        v = D_8012C574;
    }
    if (D_8012C4E4 == 2) {
        v = D_8012C578;
    }
    switch (v) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
        break;
    case 3:
        func_800AD578(D_8012C41C);
        break;
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AD32C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AD578);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AD73C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AE0D0);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AE384);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AEB90);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AEDE0);

void func_800AF02C(void) {
    D_800BE8C5[D_8012C41C * 0x78] = 0xFF;
    D_8012C508 -= 1;
    func_800A2D68();
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AF08C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AF278);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AF470);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AF5A8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AF98C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AFD74);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AFED4);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B00F4);

void func_800B02E0(s32 arg0, s16 arg1) {
    s32 ang;
    s32 x;
    s32 y;
    s32 quad;

    ang = arg0 & 0x3FF;
    x = (func_80039A74(ang) * arg1) >> 12;
    quad = arg0 & 0xC00;
    y = (func_80039B40(ang) * arg1) >> 12;
    switch (quad) {
    case 0:
        D_8012C544 = -x;
        D_8012C548 = y;
        break;
    case 0x400:
        D_8012C544 = -y;
        D_8012C548 = -x;
        break;
    case 0x800:
        D_8012C544 = x;
        D_8012C548 = -y;
        break;
    case 0xC00:
        D_8012C544 = y;
        D_8012C548 = x;
        break;
    default:
        D_8012C544 = x;
        D_8012C548 = y;
        break;
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B0404);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B0604);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B0D50);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B1620);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B17A0);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B18E0);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B1FD0);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B21A8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B2520);

INCLUDE_RODATA("../asm/us/condor/nonmatchings/text", D_800A02EC);

void func_800B2804(void) {
    CondorBytes buf;
    u32 i;
    s32 a;
    s32 b;

    buf = D_800A02EC;
    for (i = 0; i < 0x18; i++) {
        D_8012C760[i] = buf.b[i];
    }
    func_800B2C30(4, 0x10000, 0x80180000);
    func_800B2C84(0, 0x40000, 0x801B0000);
    a = D_801B0008;
    if (a & 3) {
        a &= ~3;
        a += 4;
    }
    func_800B21A8(a + 0x801B0000, &D_8010C33C);
    b = D_801B000C;
    if (b & 3) {
        b &= ~3;
        b += 4;
    }
    func_80042D88(b + 0x801B0000, 0x801B0000, 0x40000);
}

s32 func_800B2940(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Unk80046D0C img;
    s32 ret;
    CondorRect *p;
    CondorRect *r;

    func_80046CFC((arg0 >> 2 << 2) + 0x801B0000);
    func_80046D0C(&img);
    ret = 0;
    if (img.b_arg != 0) {
        r = (CondorRect *)img.b;
        p = &D_8012AF3C;
        p->x = arg1;
        D_8012AF3C.y = arg2;
        D_8012AF3C.w = r->w;
        D_8012AF3C.h = r->h;
        func_80044000(p, (void *)img.b_arg);
        r = (CondorRect *)img.b;
        ret = r->w | (r->h << 16);
    }
    if (img.a_arg != 0) {
        r = (CondorRect *)img.a;
        p = &D_8012AF3C;
        p->x = arg3;
        D_8012AF3C.y = arg4;
        D_8012AF3C.w = r->w;
        D_8012AF3C.h = r->h;
        func_80044000(p, (void *)img.a_arg);
    }
    func_80043DD8(0);
    return ret;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B2A70);

void func_800B2C30(s32 arg0, s32 arg1, s32 arg2) {
    extern void func_800B7630();

    func_80033E34(D_800BE7D8[arg0 * 2], D_800BE7D8[arg0 * 2 + 1], arg2, func_800B7630);
    while (func_80034B44() != 0) {
    }
}

void func_800B2C84(s32 arg0, s32 arg1, s32 arg2) {
    extern void func_800B7630();

    func_80033E74(D_800BE7D8[arg0 * 2], D_800BE7D8[arg0 * 2 + 1], arg2, func_800B7630);
    while (func_80034B44() != 0) {
    }
}

s32 func_800B2CD8(void *arg0) {
    s32 v;
    s32 r;

    v = M2C_FIELD(arg0, u8 *, 0x13);
    r = 0;
    if (v != 0) {
        if (v < 3) {
            r = 1;
        } else if (v < 8) {
            if (v >= 5) {
                r = 1;
            }
        }
    }
    return r;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B2D18);

void func_800B2E78(void) {
    s32 i;
    CondorObj *p;

    p = &D_800BE8C0;
    i = 0;
    do {
        i++;
        if (p->flags != 0) {
            func_800B3644(p);
        }
        p++;
    } while (i < 0x28);
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B2ED0);

void func_800B32C0(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x1C) != 0) {
        M2C_FIELD(arg0, u16 *, 0x1C) = (u16) (M2C_FIELD(arg0, u16 *, 0x1C) - 1);
        if (M2C_FIELD(arg0, u16 *, 0x1C) == 0) {
            M2C_FIELD(arg0, u16 *, 0) = (u16) (M2C_FIELD(arg0, u16 *, 0) & 0xEF);
            if (M2C_FIELD(arg0, u8 *, 0x2A) != 2) {
                M2C_FIELD(arg0, u8 *, 0x2A) = 1U;
                func_800AC498();
            }
        }
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B332C);

void func_800B3494(u16 *arg0, s32 arg1)
{
  u16 temp_s1;
  temp_s1 = *arg0;
  if (temp_s1 & 0x40)
  {
    func_800B332C();
  }
  if (!(temp_s1 & 0x50))
  {
 do { func_800B3A48(arg0, arg1); } while (0);
  }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B34F8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B3644);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B37B8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B3A48);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B3B84);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B4060);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B42AC);

void func_800B46D4(void *arg0) {
    if ((M2C_FIELD(arg0, u16 *, 0x58) | M2C_FIELD(arg0, u16 *, 0x5A)) != 0) {
        func_800B4720();
        func_800B42AC(arg0);
    }
}

void func_800B4720(arg0) {
    CondorActor *p = (CondorActor *)arg0;
    u16 d;

    d = p->vx + p->fx;
    p->fx = d;
    d >>= 8;
    if (d != 0) {
        if (d >= 0x80) {
            d |= 0xFF00;
        }
        p->x += d;
        p->x2 += d;
    }
    d = p->vy + p->fy;
    p->fy = d;
    d >>= 8;
    if (d != 0) {
        if (d >= 0x80) {
            d |= 0xFF00;
        }
        p->y += d;
        p->y2 += d;
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B47C8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B4EFC);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B5678);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B5A50);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B5BDC);

void func_800B5E38(CondorActor *p)
{
  s32 idx;
  s32 k;
  s32 r;
  s32 v;
  v = 8;
  func_800B5BDC(p);
  idx = p - ((CondorActor *) (&D_800BE8C0));
  if ((p->w26 | p->w28) != 0)
  {
    func_800B46D4(p);
  }
  k = p->kind;
  r = 0;
  if (k != 0)
  {
    if (k < 3)
    {
      r = 1;
    }
    else
      if (k < v)
    {
      if (k >= 5)
      {
        r = 1;
      }
    }
  }
  v = r;
  if (v != 0)
  {
    func_800B47C8(p, idx);
  }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B5EF4);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B61F4);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B636C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B64EC);

void func_800B6688(CondorActor *p) {
    s32 idx;
    s32 k;
    s32 r;
    s32 v;

    v = 8;
    if (func_800B64EC(p) == 0) {
        func_800B5BDC(p);
        idx = p - (CondorActor *)&D_800BE8C0;
        if ((p->w26 | p->w28) != 0) {
            func_800B46D4(p);
        }
        k = p->kind;
        r = 0;
        if (k != 0) {
            if (k < 3) {
                r = 1;
            } else if (k < v) {
                if (k >= 5) {
                    r = 1;
                }
            }
        }
        v = r;
        if (v != 0) {
            func_800B47C8(p, idx);
        }
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B6758);

void func_800B6900(CondorActor *p) {
    s32 idx;
    s32 k;
    s32 r;
    s32 v;

    v = 8;
    func_800B6758(p);
    func_800B5BDC(p);
    idx = p - (CondorActor *)&D_800BE8C0;
    if ((p->w26 | p->w28) != 0) {
        func_800B46D4(p);
    }
    k = p->kind;
    r = 0;
    if (k != 0) {
        if (k < 3) {
            r = 1;
        } else if (k < v) {
            if (k >= 5) {
                r = 1;
            }
        }
    }
    v = r;
    if (v != 0) {
        func_800B47C8(p, idx);
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B69C4);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B6B58);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B6CF8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B70C8);

void func_800B7630(void) {
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B7638);

void func_800B779C(void) {
    s32 v;
    s32 w;
    s32 base;

    func_800B7638();
    D_8012AF58 = 7;
    if (D_8012C40C == 6) {
        base = 0x80188000;
        v = D_80188008;
        if (v & 3) {
            v &= ~3;
            v += 4;
        }
        D_8009A000 = 0x10;
        D_8009A004 = v + base;
    } else {
        w = D_80188010;
        if (w & 3) {
            w &= ~3;
            w += 4;
        }
        D_8009A000 = 0x10;
        D_8009A004 = w + 0x80188000;
    }
    func_8002DA7C();
    D_8012C3EC = 0xB;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B7874);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B7AEC);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B7EC0);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B8954);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B9668);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800BA804);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800BAC4C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800BADD8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800BAF80);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800BB4EC);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800BDA24);

void func_800BE77C(void) {
    s32 v;

    if (D_8012C3E8 > 0 && D_8012C41C != -1) {
        v = D_800BE8CA[D_8012C41C].f;
    } else {
        v = -1;
    }
    D_8012C3FC = v;
}
