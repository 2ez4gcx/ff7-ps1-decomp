#include "common.h"
#include "formmenu/decls.h"

void func_801D0198(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

s32 func_801D01D8(s32 arg0) {
    s16 rect[4];
    volatile Prim *p;
    volatile Prim *volatile *pp;

    pp = &D_80062F24;
    D_80062F24->len = 3;
    D_80062F24->code = 0x60;
    func_80046848(*pp, 1);
    D_80062F24->x = 0;
    D_80062F24->y = 0;
    D_80062F24->w = 0x180;
    D_80062F24->h = 0xE8;
    D_80062F24->r = D_801D1CF8;
    D_80062F24->g = D_801D1CF8;
    D_80062F24->b = D_801D1CF8;
    p = *pp; *(volatile Prim **)pp = p + 1; func_80046794(D_80062FC4, (s32)p);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x5F, (s32)rect);
    D_801D1CF8 += arg0;
    if (D_801D1CF8 < 0) {
        D_801D1CF8 = 0;
    }
    if (D_801D1CF8 >= 0x100) {
        D_801D1CF8 = 0xFF;
    }
    return D_801D1CF8;
}

void func_801D0350(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3) {
    s16 rect[4];
    s32 i;
    for (i = 0; i < 8; i++) {
        if (arg2[i] != 0 && (arg2[i] == 3 || arg2[i] == 7)) {
            func_80028CA0((s16)(arg0 + i * 0x10 - 8), (s16)arg1, 0x70, 0x30, 0x10, 0x10, 1, 0);
        }
    }
    for (i = 0; i < 8; i++) {
        if (arg2[i] != 0) {
            if (arg3[i * 4] != 0xFF) {
                func_80028CA0((s16)(arg0 + i * 0x10), (s16)arg1, 0x80, 0x20, 0x10, 0x10, (s16)func_8002603C(arg3[i * 4]), 1);
            }
            if (arg2[i] >= 5) {
                func_80028CA0((s16)(arg0 + i * 0x10), (s16)arg1, 0x80, 0x30, 0x10, 0x10, 1, 0);
            } else {
                func_80028CA0((s16)(arg0 + i * 0x10), (s16)arg1, 0x70, 0x20, 0x10, 0x10, 1, 0);
            }
        }
    }
    func_80026A34(0, 1, 0x3F, 0);
    rect[0] = arg0 - 2;
    rect[1] = arg1;
    rect[2] = 0x80;
    rect[3] = 0xB;
    func_80027B84(rect);
    func_80026A34(0, 1, 0x1F, 0);
}

void func_801D0560(u8 *arg0, s32 arg1)
{
  u8 *c;
  u8 (*new_var)[][0x84];
  new_var = &D_8009C738;
  c = (*new_var)[D_801D3438];
  func_80026F44((s32) (arg0 + 0x38), arg1, ((s32 (*)(s32)) func_80021280)(c[0x1C] + 0x80), 7);
  func_80026F44((s32) (arg0 + 0x38), arg1 + 0x20, ((s32 (*)(s32)) func_80021280)(c[0x1D] | 0x100), 7);
  if (c[0x1E] != 0xFF)
  {
    func_80026F44((s32) (arg0 + 0x38), arg1 + 0x40, ((s32 (*)(s32)) func_80021280)(c[0x1E] + 0x120), 7);
  }
  func_80026F44((s32) (arg0 + 0x10), arg1, D_801D1FDA, 5);
  func_80026F44((s32) (arg0 + 0x10), arg1 + 0x20, D_801D1FDA + 0x16, 5);
  func_80026F44((s32) (arg0 + 0x10), arg1 + 0x40, D_801D1FDA + 0x2C, 5);
  func_801D0350(arg0 + 0x30, arg1 + 0x10, D_800738BC[c[0x1C]], c + 0x40);
  func_801D0350(arg0 + 0x30, arg1 + 0x30, D_80071E4D + (c[0x1D] * 0x24), c + 0x60);
}

void func_801D06F0(void) {
    s16 rect[4];
    s32 i;
    s32 o;
    s32 x;
    s32 y;
    s32 w;
    s32 v;

    i = D_801D3438;
    o = i * 0x84;
    func_800285AC(0x111, 0x6C, D_8009C738[0][o + 0x21], 6, 0x80, 0x20, 0x20);
    func_80028CA0(0x110, 0x6B, 0x88, 8, 0x40, 8, 7, 0);
    func_80028CA0(0x15A, 0x5E, 0xF8, 8, 8, 8, 7, 0);
    func_80028CA0(0x15A, 0x77, 0xF8, 8, 8, 8, 7, 0);
    func_80028E00(0x114, 0x5E, *(s32 *)&D_8009C738[0][o + 0x3C], 0xA, 7);
    func_80028E00(0x114, 0x77, *(s32 *)&D_8009C738[0][o + 0x80], 0xA, 7);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x3F, (s32)rect);
    w = func_80026B70(func_80015248(8, 9, 8)) - 0xD6;
    x = 0x20 - w;
    func_80026F44(x, 0x5C, func_80015248(8, 9, 8), 7);
    v = func_80026B70(func_80015248(8, 0x2C, 8)) - 0xD6;
    y = 0x20 - v;
    func_80026F44(y, 0x75, func_80015248(8, 0x2C, 8), 7);
}

void func_801D08E0(void) {
    D_801DEA60 = D_801D2038;
    switch (D_801D2038) {
    case 0: {
        u16 *fp = (u16 *)(D_8009C6E4 + 0x10A4);
        u8 v = *(D_8009C6E4 + 0x4F8 + D_801D2117);
        if ((*fp >> v) & 1) {
            func_801D0198(3);
            return;
        }
        D_801D3440 = v;
        D_801D3444 = D_8009C6E4 + 0x4F8 + D_801D2117;
        D_801DEA70 = D_801D2117;
        break;
    }
    case 1: {
        u8 *b = D_801D3424;
        u8 *p = b + (D_801D2129 * 3 + D_801D2128);
        u16 fl = *(u16 *)(D_8009C6E4 + 0x10A4);
        if ((fl >> *p) & 1) {
            func_801D0198(3);
            return;
        }
        D_801D3440 = *p;
        D_801D3444 = p;
        D_801DEA6C = D_801D2128;
        D_801DEA70 = D_801D2129;
        break;
    }
    }
    D_801D3430 = 1;
}

s32 func_801D0A00(void)
{
  u8 *t;
  s32 i;
  u8 *a;
  s32 tmp;
  switch (D_801D2038)
  {
    case 0:
    {
      u16 *fp = (u16 *) (D_8009C6E4 + 0x10A4);
      u8 v = *((D_8009C6E4 + 0x4F8) + D_801D2117);
      if (((*fp) >> v) & 1)
      {
        func_801D0198(3);
        return;
      }
      D_801D3448 = v;
      D_801D344C = (D_8009C6E4 + 0x4F8) + D_801D2117;
      break;
    }

    case 1:
    {
      u8 *b = D_801D3424;
      u8 *p = b + ((D_801D2129 * 3) + D_801D2128);
      u16 fl = *((u16 *) (D_8009C6E4 + 0x10A4));
      if ((fl >> (*p)) & 1)
      {
        func_801D0198(3);
        return;
      }
      D_801D3448 = *p;
      D_801D344C = p;
      break;
    }

  }

  D_801D3430 = 0;
  a = D_801D3444;
  if (((*a) == (*D_801D344C)) && ((*a) != 0xFF))
  {
    tmp = D_801D2038;
    D_801D2038 = 2;
    D_801D2034 = tmp;
    D_801D3438 = *D_801D344C;
  }
  t = D_801D3444;
  {
    u8 x = *t;
    *t = *D_801D344C;
    *D_801D344C = x;
  }
  for (i = 0; i < 3; i++)
  {
    if (D_8009CBDC[i] != 0xFF)
    {
      func_80020058(i);
      func_8001786C(i & 0xFF);
    }
  }

}

void func_801D0BCC(void) {
    switch (D_801D3430) {
    case 0:
        func_801D08E0();
        return;
    case 1:
        func_801D0A00();
        return;
    }
}

void func_801D0C1C(s32 arg0) {
    u8 pad[8];
    u8 save;
    s32 i;
    u8 *q;
    u8 *r;
    u8 *p;

    save = D_8009CBDC[0];
    for (i = 0; i < 9; i++) {
        D_8009CBDC[0] = i;
        func_80020058(0);
        func_8001786C(0);
    }
    D_8009CBDC[0] = save;
    func_80020058(0);
    func_8001786C(0);
    D_801D3434 = arg0;
    D_801D3430 = 0;
    if (arg0 != 0) {
        func_80025CD4((s32)&D_801DDE60);
    }
    func_80043DD8(0);
    func_80025B8C((s32)&D_801D8460);
    func_80043DD8(0);
    func_80025C14((s32)&D_801D3460);
    func_80043DD8(0);
    func_80025DF8();
    func_80026448(D_801D210C, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0);
    func_80026448(D_801D210C + 0x12, 0, 0, 3, 3, 0, 0, 3, 3, 0, 0, 0, 0, 0);
    D_801D2038 = 0;
    for (i = 0; i < 9; i++) {
        D_801D3424[i] = 0xFF;
    }
    i = 0;
    p = D_8009CBDC;
    q = D_801D3424;
    for (; i < 9; i++) {
        if (p[0] != i && p[1] != i && p[2] != i && ((*(u16 *)(p + 0xBAE) >> i) & 1)) {
            *q++ = i;
        }
    }
}

s32 func_801D0E24(void)
{
  s32 i;
  s32 n;
  s32 v;
  i = 0;
  n = 0;
  do
  {
    if (D_8009CBDC[i] != 0xFF)
    {
      n++;
    }
    i++;
  }
  while (i < 3);
  if (D_801D3434 != 0)
  {
    i = D_801D20FC;
    v = i;
  }
  else
  {
    v = 3;
  }
  if (n == v)
  {
    v = 1;
  }
  else
  {
    v = 0;
  }
  return v;
}

INCLUDE_ASM("../asm/us/formmenu/nonmatchings/text", func_801D0E94);

void func_801D1A14(void) {
    func_80025CD4((s32) &D_800756F8);
    func_80025C94(&D_801DDE60);
    func_80025BD0(&D_801D8460);
    func_80025C54(&D_801D3460);
}

s32 func_801D1A6C(s32 arg0) {
    u8 buf[0x600];
    s32 i;

    D_801D20FC = arg0;
    D_801D343C = 0;
    if (arg0 == 0) {
        D_801D20FC = 3;
    } else if (arg0 < 4) {
        D_801D20FC = arg0;
    } else {
        D_801D343C = arg0;
        arg0 -= 4;
        if (arg0 >= 0) {
            if (arg0 < 4) {
                D_801D20FC = 3;
            } else if (arg0 == 4) {
                D_801D20FC = 2;
            }
        }
    }
    func_80025CD4((s32)buf);
    i = 0;
    func_80025C94(&D_800756F8);
    func_80021044(D_801D2144, D_801D21FC);
    D_801DEA68 = 0;
    func_801D0C1C(1);
    D_801DEA64 = 0;
    while (1) {
        func_8001CB48();
        func_800269C0((s32)(D_80077F64 + D_801DEA64 * 0x3400));
        D_801D2100 = D_801D2104 + D_801DEA64 * 4;
        func_8004418C(D_801D2100, 1);
        func_80026A00((s32)D_801D2100);
        func_801D0E94(i);
        if (D_801DEA68 == -1) {
            break;
        }
        func_80043DD8(0);
        func_8003CEDC(0);
        func_800444AC((void *)(D_801D21FC + D_801DEA64 * 0x14));
        func_800443B0((void *)(D_801D2144 + D_801DEA64 * 0x5C));
        i++;
        func_8004433C((s32)D_801D2100);
        D_801DEA64 ^= 1;
    }
    func_801D1A14();
    i = 0;
    func_80025C94(buf);
    do {
        if (D_8009CBDC[i] != 0xFF) {
            func_80020058(i);
            func_8001786C(i & 0xFF);
        }
        i++;
    } while (i < 3);
    func_8003CEDC(0);
    func_800444AC((void *)D_801D21FC);
    func_800443B0((void *)D_801D2144);
    func_8003CEDC(0);
    func_800444AC((void *)(D_801D21FC + 0x14));
    return func_800443B0((void *)(D_801D2144 + 0x5C));
}

INCLUDE_RODATA("../asm/us/formmenu/nonmatchings/text", D_801D0000);
