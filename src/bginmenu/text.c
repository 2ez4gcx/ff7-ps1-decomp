#include "common.h"
#include "bginmenu/decls.h"

void func_801D0000(void) {
    u8 pad[8];

    func_80026448(&D_801D0860, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0U);
    func_80026448((u8 *)&D_801D0860 + 0x12, 0, 0, 1, 3, 0, 0, 1, 9, 0, 0, 0, 0, 0U);
    D_801D07F0 = 0;
}

void func_801D00C4(void) {
    u8 pad[16];
    s32 i;
    u8 *p;

    func_800230C4(D_80062F58);
    if (D_801D07F0 == 0) {
        func_8001EB2C(0, D_801D07FE + (D_801D086B << 6) + 0x20);
    }
    func_80026F44(0x10, 0xB, D_801D0804, 7);
    i = 0; p = D_801D07F4; do { func_8001E040(p); i++; p += 8; } while (i < 2);
    func_800264A8(D_801D0860 + D_801D07F0 * 0x12);
    if (D_80062D7E & 0x40) {
        func_8002305C(5, 0);
        func_8002120C(0);
    }
}

void func_801D01BC(void) {
}

s32 func_801D01C4(s32 arg0) {
    s32 *p;
    s32 i;
    s32 n;

    i = 0;
    n = 0;
    p = (s32 *)(D_8009C778 + arg0 * 0x84);
    for (; i < 8; i++) {
        if (p[i] != -1) {
            n++;
        }
    }
    p = (s32 *)(D_8009C798 + arg0 * 0x84);
    for (i = 0; i < 8; i++) {
        if (p[i] != -1) {
            n++;
        }
    }
    return n;
}

s32 func_801D0258(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0) | (M2C_FIELD(arg0, u8 *, 1) << 8);
}

void func_801D026C(u8 *arg0, u16 arg1) {
    arg0[0] = arg1;
    arg0[1] = arg1 >> 8;
}

s32 func_801D027C(void) {
    s32 i;
    s32 v;
    Slot84 *c;
    u16 *w;

    w = (u16 *)(D_8009C6E4 + 0xD18);
    c = (Slot84 *)(D_8009C6E4 + 0x80);
    for (i = 0; i < 5; i++) {
        v = c[i].v * func_801D0258(&w[i]) / 65535;
        if (v <= 0) {
            v = 1;
        }
        c[i].v = v;
    }
}

void func_801D0324(s32 arg0) {
    s32 i;
    s32 j;
    s32 (*w)[0x21];
    s32 (*a)[0x21];
    u16 *fp;

    arg0 |= -0x100;
    i = 0;
    fp = D_8009D78A;
    w = (s32 (*)[0x21])((u8 *)D_8009D78A - 0x1012);
    a = (s32 (*)[0x21])((u8 *)D_8009D78A - 0xFF2);
    for (; i < 9; i++) {
        if ((*fp >> i) & 1) {
            for (j = 0; j < 8; j++) {
                if (w[i][j] == arg0) {
                    w[i][j] = -1;
                    return;
                }
            }
            for (j = 0; j < 8; j++) {
                if (a[i][j] == arg0) {
                    a[i][j] = -1;
                    return;
                }
            }
        }
    }
    for (j = 0; j < 200; j++) {
        if (D_8009CE60[j] == arg0) {
            D_8009CE60[j] = -1;
            return;
        }
    }
}

s32 func_801D0408(s32 arg0) {
    s32 i;
    s32 j;
    s32 (*w)[0x21];
    s32 (*a)[0x21];
    u32 m;
    u32 h;
    int flags;

    i = 0;
    flags = D_8009D78A[0];
    w = (s32 (*)[0x21])((u8 *)D_8009D78A - 0x1012);
    a = (s32 (*)[0x21])((u8 *)D_8009D78A - 0xFF2);
    for (; i < 9; i++) {
        if ((flags >> i) & 1) {
            for (j = 0; j < 8; j++) {
                m = w[i][j];
                h = m >> 8;
                if (h == 0xFFFFFF && (m & 0xFF) == arg0) {
                    return 1;
                }
            }
            for (j = 0; j < 8; j++) {
                m = a[i][j];
                h = m >> 8;
                if (h == 0xFFFFFF && (m & 0xFF) == arg0) {
                    return 1;
                }
            }
        }
    }
    for (j = 0; j < 200; j++) {
        m = D_8009CE60[j];
        h = m >> 8;
        if (h == 0xFFFFFF && (m & 0xFF) == arg0) {
            return 1;
        }
    }
    return 0;
}

s32 func_801D0500(s32 arg0)
{
  s32 i;
  s32 j;
  s32 *a;
  int flags;
  s32 *new_var;
  s32 *w;
  int new_var2;
  i = 0;
  flags = *((u16 *) (D_8009C6E4 + 0x10A6));
  a = (new_var = (s32 *) (D_8009C6E4 + 0xB4));
  w = (s32 *) (D_8009C6E4 + 0x94);
  for (i = 0; i < 9; i++)
  {
    if ((flags >> i) & 1)
    {
      for (j = 0; j < 8; j++)
      {
        if ((*((u8 *) (w + j))) == arg0)
        {
          return 1;
        }
      }

      for (j = 0; j < 8; j++)
      {
        if ((*((u8 *) (a + j))) == arg0)
        {
          return 1;
        }
      }

    }
    a += 0x21;
    new_var2 = 0x21;
    w += new_var2;
  }

  for (j = 0; j < 200; j++)
  {
    if ((*((u8 *) (D_8009CE60 + j))) == arg0)
    {
      return 1;
    }
  }

  return 0;
}

s32 func_801D05C4(s32 arg0) {
    s32 i;

    D_8009D6F7 = 0;
    switch (arg0) {
    case 0:
        for (i = 0; i < 0x15; i++) {
            if (func_801D0408(D_801D082C[i]) == 0) {
                return;
            }
        }
        D_8009D6F7 = 1;
        break;
    case 1:
        for (i = 0; i < 0x10; i++) {
            if (func_801D0408(D_801D0844[i]) == 0) {
                return;
            }
        }
        D_8009D6F7 = 1;
        break;
    case 2:
        for (i = 0; i < 7; i++) {
            if (func_801D0408(D_801D0854[i]) == 0) {
                return;
            }
        }
        D_8009D6F7 = 1;
        break;
    case 3:
        for (i = 0; i < 2; i++) {
            if (func_801D0500(D_801D085C[i]) == 0) {
                return;
            }
        }
        D_8009D6F7 = 1;
        break;
    default:
        D_8009D6F7 = 1;
        break;
    }
}

s32 func_801D0704(s32 arg0) {
    s32 i;

    switch (arg0) {
    case 0:
        for (i = 0; i < 0x15; i++) {
            func_801D0324(D_801D082C[i]);
        }
        func_8002542C(0x49);
        break;
    case 1:
        for (i = 0; i < 0x10; i++) {
            func_801D0324(D_801D0844[i]);
        }
        func_8002542C(0x5A);
        break;
    case 2:
        for (i = 0; i < 7; i++) {
            func_801D0324(D_801D0854[i]);
        }
        func_8002542C(0x30);
        break;
    case 3:
        func_8002542C(0x58);
        break;
    }
}
