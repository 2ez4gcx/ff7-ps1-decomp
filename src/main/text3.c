#include "common.h"
#include "main/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
s32 func_80017108(u8 *arg0, s32 arg1);
extern s32 D_80062E40;
void func_800197B8(u32 arg0);
void func_80017678(void);
extern u8 D_8009D302[];
extern M2C_UNK D_800730D0;

s32 func_80016F90(s32 *arg0) {
    u32 t;
    u32 b;
    u32 k;

    b = D_80062E48;
    k = D_80062E4C;
    while (k < 1) {
        b |= (u32) D_80062E3C[D_80062E38++] << k;
        k += 8;
    }
    *arg0 = b & 1;
    b >>= 1;
    k -= 1;
    while (k < 2) {
        b |= (u32) D_80062E3C[D_80062E38++] << k;
        k += 8;
    }
    t = b & 3;
    b >>= 2;
    k -= 2;
    D_80062E48 = b;
    D_80062E4C = k;
    if (t == 2) {
        return func_800169B8();
    }
    if (t == 0) {
        return func_800166C0();
    }
    if (t == 1) {
        return func_80016808();
    }
    return 2;
}

s32 func_8001708C(void) {
    s32 sp10;
    s32 ret;

    D_80062E34 = 0;
    D_80062E4C = 0;
    D_80062E48 = 0;
    while (1) {
        D_80062E50 = 0;
        ret = func_80016F90(&sp10);
        if (ret != 0) {
            return ret;
        }
        if (sp10 != 0) {
            break;
        }
    }
    while (D_80062E4C >= 8) {
        D_80062E4C -= 8;
        D_80062E38 -= 1;
    }
    return 0;
}

s32 func_80017108(u8 *arg0, s32 arg1) {
    u8 hdr[8];
    u8 window[0x4000];
    s32 i;
    s32 r;
    s32 crc;
    u8 b0;
    u8 b1;

    D_80062E44 = (s32)window;
    D_80062E3C = arg0;
    D_80062E40 = arg1;
    D_80062E38 = 0;
    D_80062E34 = 0;
    D_80062E38 = 1;
    b0 = arg0[0];
    D_80062E38 = 2;
    b1 = arg0[1];
    if ((b0 != 0x1F) | (b1 != 0x8B)) {
        return -1;
    }
    D_80062E38 = 3;
    if (arg0[2] != 8) {
        return -1;
    }
    D_80062E38 = 4;
    if (arg0[3] != 0) {
        return -1;
    }
    D_80062E38 = 0xA;
    r = func_8001708C();
    if (r == 3 || r != 0) {
        return -1;
    }
    for (i = 0; i < 8; i++) {
        hdr[i] = D_80062E3C[D_80062E38++];
    }
    crc = hdr[4] | (hdr[5] << 8) | ((hdr[6] | (hdr[7] << 8)) << 16);
    if (crc != D_80062E34) {
        return -1;
    }
    return crc;
}

void func_80017238(u32 arg0, u32 *arg1, u8 *arg2) {
    *arg2 = arg0;
    arg0 >>= 8;
    *arg1 = arg0;
    func_8001AC9C(*arg2, arg0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001726C);

void func_80017678(void)
{
  s32 i;
  s32 xs;
  s32 ys;
  s32 t;
  u8 *m;
  xs = 0;
  ys = 0;
  i = 0;
  D_80062F18.a = 0x10;
  D_80062F18.b = 0x10;
  D_80062F18.c = 0;
  D_80062F18.d = 0x10;
  D_8009D302[0] &= 0x7F;
  do
  {
    if (D_8009CBDC[i] != 0xFF)
    {
      m = func_80025788(i);
      D_80062E60 = m;
      D_80062F18.a += m[0x43C];
      xs += m[0x43D];
      ys += m[0x437];
      D_80062F18.c += m[0x43E];
      D_80062F18.d += m[0x43F];
      if (m[0x23] & 1)
      {
        D_8009D302[0] |= 0x80;
      }
    }
    i++;
  }
  while (i < 3);
  t = xs + 0x10;
  if (t >= ys)
  {
    D_80062F18.b = t - ys;
  }
  else
  {
    D_80062F18.b = 2;
  }
  if (D_80062F18.a > 0x20)
  {
    D_80062F18.a = 0x20;
  }
  if (D_80062F18.b > 0x20)
  {
    D_80062F18.b = 0x20;
  }
  if (D_80062F18.c > 0x20)
  {
    D_80062F18.c = 0x20;
  }
  if (D_80062F18.d > 0x55)
  {
    D_80062F18.d = 0x55;
  }
  if ((*((u8 *) (&D_80062E5C))) != 0)
  {
    D_80062F18.d |= 0x80;
  }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001786C);

void func_80017E68(u8 arg0, u8 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6) {
    if (arg0 == 2 && arg1 == 3) {
        func_80017F38(arg2, arg3, arg4, arg5, arg6);
    }
    if (arg0 == 6 && arg1 == 7) {
        func_80017F38(arg2, arg3, arg4, arg5, arg6);
    }
}

void func_80017F38(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4) {
    u8 kind[8];
    u8 id[8];

    id[0] = arg0;
    kind[0] = D_800730DD[id[0]].a & 0xF;
    id[1] = arg1;
    kind[1] = D_800730DD[id[1]].a & 0xF;
    if (id[0] != 0xFF && id[1] != 0xFF) {
        if (kind[0] == 5 || kind[1] == 5) {
            if (kind[0] != 5 || kind[1] != 5) {
                if (kind[0] == 5) {
                    func_80018028(arg0, arg1, arg3, arg4);
                } else {
                    func_80018028(arg1, arg0, arg2, arg4);
                }
            }
        }
    }
}

void func_80018028(u32 a, s32 b, s32 c, u8 d)
{
  s32 id;
  s32 n;
  int new_var;
  s32 i;
  u8 b0;
  u8 v;
  s32 w;
  b0 = a;
  id = b0;
  n = func_8001AC9C(id, a >> 8);
  i = 0;
  new_var = id * 0x14;
  do
  {
    D_80062E54[i] = D_800730DF[new_var + i];
    i++;
  }
  while (i < 5);
  switch (D_800730DE[b0 * 0x14])
  {
    case 0x63:
      func_800191A0(b0, n & 0xFF, b);
      break;

    case 0x51:
      func_80019440(b0, n & 0xFF, b);
      break;

    case 0x59:
      v = 1;
      goto set78;

    case 0x5A:
      v = 2;
      goto set78;

    case 0x58:
      func_80018C94(n & 0xFF, b);
      break;

    case 0x5D:
      v = 8;
      goto set78;

    case 0x5C:
      v = 0x10;
      set78:
    D_80062E78 = v;

      func_80018D4C(b);
      break;

    case 0x57:
      w = 1;
      goto set84;

    case 0x56:
      w = 4;
      set84:
    *((s32 *) (&D_80062E84)) = w;

      ((void (*)(s32, s32, u32)) func_800184C0)(b0, n & 0xFF, b);
      break;

    case 0x55:
      *((s32 *) (&D_80062E84)) = 7;
      func_8001840C(b0, n & 0xFF, b);
      break;

    case 0x54:
      *((s32 *) (&D_80062E84)) = 8;
      func_80018390(b0, n & 0xFF, b);
      break;

    case 0x5E:
      func_80018220(n & 0xFF, b, d);
      break;

    case 0x5F:
      ((void (*)(s32, s32, s32)) func_800182FC)(n & 0xFF, b, d);
      break;

  }

}

void func_80018220(s32 arg0, s32 arg1, s32 arg2) {
    u8 v1;
    u16 a1;
    s32 a0;

    v1 = D_800730DC[(arg1 & 0xFF) * 0x14];
    if (v1 < 0x20U) {
        a1 = D_800491B0[v1];
        a0 = arg0 & 0xFF;
        if ((arg2 & 0xFF) == 0) {
            *(u16 *)(D_80062E60 + 0x3C) |= a1;
            return;
        }
        switch (a0) {
        case 1:
            *(u16 *)(D_80062E60 + 0x3E) |= a1;
            return;
        case 2:
            *(u16 *)(D_80062E60 + 0x40) |= a1;
            return;
        case 3:
        default:
            *(u16 *)(D_80062E60 + 0x42) |= a1;
            break;
        }
    }
}

void func_800182FC(s32 arg0, u8 arg1, u8 arg2) {
    s32 i;
    s32 mask;

    i = arg1 * 20;
    mask = (&D_800730D9)[i] + ((&D_800730DA)[i] << 8) + ((&D_800730DB)[i] << 16);
    if (arg2 == 0) {
        *(s32 *) (D_80062E60 + 0x44) |= mask;
    } else {
        *(s32 *) (D_80062E60 + 0x48) |= mask;
    }
}

void func_80018390(s32 arg0, s32 arg1, u32 arg2) {
    s32 id;
    s32 t;
    u32 a2;

    id = arg2 & 0xFF;
    t = *((u8 *)D_800730DD + id * 20) & 0xF;
    D_80062E88 = 0;
    a2 = arg2 >> 8;
    switch (t) {
    case 6:
        func_80018630(arg1 & 0xFF, id, a2);
        return;
    case 8:
        func_800185A8(arg1 & 0xFF, 0xFD, a2);
        return;
    }
}

void func_8001840C(s32 arg0, s32 arg1, u32 arg2) {
    s32 idx;
    s32 type;
    s32 hi;

    idx = arg2 & 0xFF;
    type = *((u8 *)D_800730DD + idx * 20);
    D_80062E88 = 0;
    hi = arg2 >> 8;
    switch (type & 0xF) {
    case 9:
        func_80018834(arg1, idx, hi);
        break;
    case 10:
        func_800185A8(arg1, 0xFE, hi);
        break;
    case 11:
        func_80018934(arg1, idx, hi);
        break;
    case 12:
        func_800185A8(arg1, 0xFF, hi);
        break;
    }
}

void func_800184C0(s32 arg0, s32 arg1, u32 arg2) {
    u8 id;
    s32 t;

    id = arg2;
    t = *((u8 *) D_800730DD + id * 20) & 0xF;
    D_80062E88 = 0;
    arg2 >>= 8;
    switch (t) {
    case 6:
        D_80062E88 = 1;
        func_80018630(arg1 & 0xFF, id, arg2);
        break;
    case 8:
        D_80062E88 = 1;
        func_800185A8(arg1 & 0xFF, 0xFD, arg2);
        break;
    case 9:
        func_80018834(arg1 & 0xFF, id, arg2);
        break;
    case 10:
        func_800185A8(arg1 & 0xFF, 0xFE, arg2);
        break;
    case 11:
        func_80018934(arg1 & 0xFF, id, arg2);
        break;
    case 12:
        func_800185A8(arg1 & 0xFF, 0xFF, arg2);
        break;
    }
}

void func_800185A8(u8 arg0, u8 arg1, s32 arg2) {
    s32 n;

    if (D_80062E80 != 8) {
        ((Obj *)D_80062E60)->e[D_80062E80].a = D_80062E84 + *(u8 *)&D_80062E88;
        ((Obj *)D_80062E60)->e[D_80062E80].b = arg1;
        n = D_80062E80;
        D_80062E80 = n + 1;
        ((Obj *)D_80062E60)->e[n].c = *((u8 *)&D_80062E50 + 3 + (arg0 & 0xFF));
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80018630);

void func_80018834(u8 arg0, u8 arg1, s32 arg2) {
    s32 id;
    s32 cnt;
    s32 idx;
    s32 n;
    u8 *p;

    id = arg1;
    cnt = func_8001AC9C(id, arg2);
    while (cnt > 0) {
        idx = id * 0x14 + cnt;
        p = (u8 *) D_800730DD + idx;
        cnt--;
        if (*p != 0xFF) {
            if (D_80062E80 != 8) {
                ((Obj *) D_80062E60)->e[D_80062E80].a = D_80062E84 + *(u8 *) &D_80062E88;
                ((Obj *) D_80062E60)->e[D_80062E80].b = *p;
                n = D_80062E80++;
                ((Obj *) D_80062E60)->e[n].c = *((u8 *) &D_80062E50 + 3 + (arg0 & 0xFF));
            }
            break;
        }
    }
}

void func_80018934(u8 arg0, u8 arg1, s32 arg2) {
    s32 id;
    s32 n;

    id = arg1;
    func_8001AC9C(id, arg2);
    if (D_80062E80 != 8) {
        ((Obj *) D_80062E60)->e[D_80062E80].a = D_80062E84 + *(u8 *) &D_80062E88;
        ((Obj *) D_80062E60)->e[D_80062E80].b = D_800730DE[id * 0x14];
        n = D_80062E80++;
        ((Obj *) D_80062E60)->e[n].c = *((u8 *) &D_80062E50 + 3 + (arg0 & 0xFF));
    }
}

void func_80018A04(s32 arg0, u8 arg1, M2C_UNK arg2) {
    s32 i;
    u8 *e;
    u8 *q;
    u8 *p;
    s32 v;
    u8 b;

    i = func_8001AC9C(arg1, arg2);
    if (i > 0) {
        do {
            e = (arg1 * 20 + i) + (u8 *)D_800730DD;
            q = D_80062E60;
            p = q + *e * 8;
            b = p[0x10F];
            v = (b >> 5) + (arg0 & 0xFF);
            if (v >= 6) {
                v = 5;
            }
            p[0x10F] = (b & 0x1F) | ((v & 7) << 5);
            i--;
        } while (i > 0);
    }
}

void func_80018AB0(u8 arg0) {
    s32 i;
    s32 v;
    u8 *p;
    u8 b;
    u8 *base;
    for (i = 0; i < 0x10; i++) {
        base = D_80062E60;
        p = base + 0x1C0 + i * 8;
        b = p[0x10F];
        v = (b >> 5) + arg0;
        if (v >= 6) {
            v = 5;
        }
        p[0x10F] = (b & 0x1F) | ((v & 7) << 5);
    }
}

void func_80018B14(s32 arg0) {
    s32 i;
    s32 idx;
    s32 v;
    u8 b;

    for (i = 0; i < 0x38; i++) {
        idx = func_8001964C(i);
        if (idx != -1) {
            b = D_80069558[idx].flags;
            v = (b >> 5) + (arg0 & 0xFF);
            if (v >= 6) {
                v = 5;
            }
            D_80069558[idx].flags = (b & 0x1F) | ((v & 7) << 5);
        }
    }
}

void func_80018BB8(u8 arg0, u8 arg1, u32 arg2) {
    s32 s1;
    s32 s0;
    s32 id;
    s32 v;
    s32 idx;
    u8 f;

    s1 = arg1 & 0xFF;
    s0 = func_8001AC9C(s1, arg2);
    while (s0 > 0) {
        idx = s1 * 0x14 + s0;
        id = func_8001964C(((u8 *) D_800730DD)[idx]);
        if (id != -1) {
            f = D_80069558[id].flags;
            v = (f >> 5) + arg0;
            if (v >= 6) {
                v = 5;
            }
            D_80069558[id].flags = (f & 0x1F) | ((v & 7) << 5);
        }
        s0 -= 1;
    }
}

void func_80018C94(s32 arg0, u32 arg1) {
    u8 idx;
    u32 hi;
    s32 type;

    idx = arg1;
    type = D_800730DD[idx].a & 0xF;
    hi = arg1 >> 8;
    switch (type) {
    case 9:
        func_80018BB8(arg0, idx, hi);
        break;
    case 10:
        func_80018B14(arg0 & 0xFF);
        break;
    case 11:
        func_80018A04(arg0 & 0xFF, idx, hi);
        break;
    case 12:
        func_80018AB0(arg0);
        break;
    }
}

void func_80018D4C(u32 arg0) {
    u8 id;
    u32 x;

    id = arg0;
    x = arg0 >> 8;
    switch (D_800730DD[id].a & 0xF) {
    case 6:
        ((void (*)(s32, u32)) func_80018ECC)(id, x);
        break;
    case 8:
        func_80018FC0();
        break;
    case 9:
        func_800190E8(id);
        break;
    case 10:
        func_80019064();
        break;
    case 11:
        func_80018E18(id);
        break;
    case 12:
        func_80018E90();
        break;
    }
}

void func_80018E18(u8 arg0) {
    s32 i;
    u8 *p;
    u8 *e;
    u8 *q;

    i = func_8001AC9C(arg0);
    if (i > 0) {
        do {
            e = (arg0 * 20 + i) + (u8 *)D_800730DD;
            q = D_80062E60;
            p = q + *e * 8;
            p[0x10F] |= D_80062E78;
            i--;
        } while (i > 0);
    }
}

void func_80018E90(void) {
    s32 i;
    s32 off;

    i = 0;
    off = 0x1C0;
    do {
        i++;
        *(D_80062E60 + off + 0x10F) |= D_80062E78;
        off += 8;
    } while (i < 0x10);
}

void func_80018ECC(u8 arg0) {
    s32 idx;
    u8 t;

    idx = func_80019608(D_800730DE[arg0 * 0x14]);
    if (idx != -1) {
        D_80069508[idx].c |= D_80062E78;
    }
    t = D_800730DF[arg0 * 0x14];
    if (t == 7 || t == 0x11) {
        idx = func_80019608(t);
        if (idx != -1) {
            D_80069508[idx].c |= D_80062E78;
        }
    }
}

void func_80018FC0(void) {
    s32 i;
    s32 idx;

    for (i = 0; i < 16; i++) {
        idx = func_80019608(D_80069508[i].a);
        if (idx != -1) {
            D_80069508[idx].c |= D_80062E78;
        }
    }
}

void func_80019064(void) {
    s32 i;
    s32 idx;

    for (i = 0; i < 0x38; i++) {
        idx = func_8001964C(i);
        if (idx != -1) {
            D_80069558[idx].flags |= D_80062E78;
        }
    }
}

void func_800190E8(u8 arg0) {
    s32 i;
    s32 idx;
    s32 off;
    u8 *tbl;

    i = func_8001AC9C(arg0);
    if (i > 0) {
        do {
            off = arg0 * 20;
            tbl = (u8 *)D_800730DD;
            idx = func_8001964C(tbl[off + i]);
            if (idx != -1) {
                D_80069558[idx].flags |= D_80062E78;
            }
        } while (--i > 0);
    }
}

void func_800191A0(s32 arg0, s32 arg1, u32 arg2) {
    u8 id;
    u32 rest;

    id = arg2;
    rest = arg2 >> 8;
    switch (*((id * 20) + (u8 *)D_800730DD) & 0xF) {
    case 9:
        func_80019254(arg1, id, rest);
        break;
    case 10:
        func_80019338(arg1, id, rest);
        break;
    case 11:
        func_8001937C(arg1 & 0xFF, id);
        break;
    case 12:
        func_800193F4(arg1, id, rest);
        break;
    }
}

void func_80019254(u8 arg0, u8 arg1, u32 arg2) {
    s32 s1;
    s32 s0;
    s32 id;
    s32 base;

    s1 = arg1 & 0xFF;
    s0 = func_8001AC9C(s1, arg2);
    while (s0 > 0) {
        base = s1 * 0x14;
        id = func_8001964C(((u8 *) D_800730DD)[base + s0]);
        if (id != -1) {
            D_80069554[id].unk2 += 1;
            D_80069554[id].unk3 += arg0;
        }
        s0 -= 1;
    }
}

void func_80019338(u8 arg0, u8 arg1, u32 arg2) {
    s32 i;

    for (i = 0; i < 0x38; i++) {
        D_80069554[i].unk2 += 1;
        D_80069554[i].unk3 += arg0;
    }
}

void func_8001937C(s32 arg0, u8 arg1) {
    s32 idx;

    idx = D_800730DE[arg1 * 0x14] - 0x38;
    D_800694C4[idx]++;
    D_800694D4[idx] += arg0;
}

void func_800193F4(u8 arg0, u8 arg1, u32 arg2) {
    u8 *p;
    u8 *q;

    p = D_800694D4;
    q = D_800694C4;
    do {
        *q += 1;
        *p += arg0;
        p++;
        q++;
    } while ((s32) p < (s32) (D_800694D4 + 0x10));
}

void func_80019440(s32 arg0, s32 arg1, u32 arg2) {
    u8 idx;
    s32 kind;

    idx = arg2;
    kind = ((u8 *)D_800730DD)[idx * 20] & 0xF;
    arg2 >>= 8;
    switch (kind) {
    case 9:
        func_80019544(arg1, idx, arg2);
        break;
    case 10:
        func_800194BC(arg1, idx, arg2);
        break;
    }
}

void func_800194BC(u8 arg0, u8 arg1, u32 arg2) {
    s32 i;
    s32 r;

    for (i = 0; i < 0x38; i++) {
        r = func_8001964C(i);
        if (r != -1) {
            D_80069554[r].unk1 += arg0;
        }
    }
}

void func_80019544(u8 arg0, u8 arg1, u32 arg2) {
    s32 s1;
    s32 s0;
    s32 id;
    s32 base;

    s1 = arg1 & 0xFF;
    s0 = func_8001AC9C(s1, arg2);
    while (s0 > 0) {
        base = s1 * 0x14;
        id = func_8001964C(((u8 *)D_800730DD)[base + s0]);
        if (id != -1) {
            D_80069554[id].unk1 += arg0;
        }
        s0 -= 1;
    }
}

s32 func_80019608(u8 arg0) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (D_80069508[i].a == arg0) {
            return i;
        }
    }
    return -1;
}

s32 func_8001964C(u8 id) {
    s32 i;

    for (i = 0; i < 0x38; i++) {
        if (D_80069554[i].id == id) {
            return i;
        }
    }
    return -1;
}

void func_80019690(u32 arg0) {
    s32 id;
    s32 d;
    s32 i;
    s32 x;
    u32 sub;

    id = arg0 & 0xFF;
    sub = arg0 >> 8;
    if ((D_800730DD[id].a & 0xF) == 4) {
        d = ((s32 (*)(s32, u32))func_8001AC9C)(id, sub);
        for (i = 0; i < 0x38; i++) {
            if (((MainObj108 *)D_80062E60)->e[i].a != 0xFF) {
                ((MainObj108 *)D_80062E60)->e[i].b += d;
            }
        }
        for (i = 0; i < 16; i++) {
            x = ((Obj4C *)D_80062E60)->e[i].a;
            if (x != 0xFF) {
                switch (x) {
                case 5:
                case 6:
                case 9:
                case 10:
                case 11:
                case 0x11:
                    ((Obj4C *)D_80062E60)->e[i].e += d;
                    break;
                }
            }
        }
        if (((Obj4C *)D_80062E60)->e[0].a != 0x1A) {
            func_8001BB30(0x18, 0);
        }
    }
}

void func_800197B8(u32 arg0) {
    Obj1A *p;
    u8 i;
    s32 id;
    u32 arg2;
    u8 kind;
    u8 b;
    u32 hi;
    u32 lo;

    if (D_80063020 != 0) {
        p = D_80062F7C;
        for (i = 0; i < 8; i++) {
            *(u16 *)((u8 *)p + 0xA + i * 2) = 0;
        }
    }
    b = arg0;
    id = b;
    arg2 = arg0 >> 8;
    if (id != 0xFF) {
        func_80019978(id);
        kind = D_800730DD[id].a;
        hi = kind >> 4;
        lo = kind & 0xF;
        switch (lo) {
        case 0:
            func_8001A5B4(hi, b, arg2);
            break;
        case 1:
            func_8001A980(hi, b, arg2);
            break;
        case 2:
            func_80019D1C(hi, b, arg2);
            break;
        case 3:
            func_80019F90(hi, b, arg2);
            break;
        case 4:
            ((void (*)(s32, u32))func_8001A384)(b, arg2);
            break;
        case 5:
            func_8001A174(hi, b, arg2);
            break;
        case 6:
            func_8001B704(b, arg2);
            break;
        case 7:
            func_8001A3B8(hi, b, arg2);
            break;
        case 8:
            func_8001A440();
            break;
        case 9:
            ((void (*)(s32, u32))func_8001B5E4)(b, arg2);
            break;
        case 10:
            func_8001A4A8();
            break;
        case 11:
            ((void (*)(s32, u32))func_8001B4A0)(b, arg2);
            break;
        case 12:
            func_8001A518();
            break;
        }
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80019978);

void func_80019D1C(s32 arg0, s32 arg1, s32 arg2) {
    s32 id;
    s32 r;

    id = arg1 & 0xFF;
    r = func_8001AC9C(id, arg2);
    if ((arg0 & 0xFF) == 1) {
        func_80019E84(r & 0xFF, id);
    }
}

void func_80019D74(u8 arg0, u8 arg1) {
    if (arg1 == 0xB) {
        ((void (*)(u8))func_80019E4C)(arg0);
    }
}

void func_80019DA0(u8 arg0, u8 arg1) {
    s32 n;

    if (D_80063020 == 0) {
        if (D_80062E80 != 8) {
            ((Obj *)D_80062E60)->e[D_80062E80].a = 9;
            ((Obj *)D_80062E60)->e[D_80062E80].b = 9;
            n = D_80062E80;
            D_80062E80 = n + 1;
            ((Obj *)D_80062E60)->e[n].c = D_800730DD[arg1].b[arg0];
        }
    } else {
        D_80062FFC = 0x12;
    }
}

void func_80019E4C(void) {
    if (D_80063020 == 0) {
        M2C_FIELD(D_80062E60, u8 *, 0x23) = (u8) (M2C_FIELD(D_80062E60, u8 *, 0x23) | 4);
        return;
    }
    D_80062FFC = 0x12;
}

void func_80019E84(u8 arg0, u8 arg1) {
    s32 i;
    s32 idx;
    u8 *p;
    u8 *q;
    s32 ff;
    ObjSlots *obj;

    i = 0;
    if (D_80063020 == 0) {
        i = arg0 - 1;
        if (i > 0) {
            ff = 0xFF;
            p = D_800730DE + arg1 * 0x14;
            while (i > 0 && p[i] == ff) {
                i--;
            }
        }
        q = D_800730DE + arg1 * 0x14;
        D_80069508[0].a = q[i];
        return;
    }
    obj = (ObjSlots *) D_80062F7C;
    p = D_800730DE + arg1 * 0x14;
    for (i = 0; i < 5; i++) {
        obj->e[i].a = p[i];
        obj->e[i].b = 0;
    }
    if (obj->f1 == arg0) {
        idx = arg0 - 2;
    } else {
        idx = arg0 - 1;
    }
    obj->e[idx].b = 1;
    D_80062FFC = 0x13;
}

void func_80019F90(s32 arg0, s32 arg1, s32 arg2) {
    s32 id;
    s32 n;
    s32 idx;
    s32 off;
    Obj1A *q;

    id = arg1 & 0xFF;
    n = func_8001AC9C(id, arg2);
    if (D_80063020 == 0) {
        off = id * 0x14;
        switch (D_800730DE[off]) {
        case 0x15:
            D_80062E8C = 2;
            idx = func_80019608(2);
            if (idx == -1) {
                D_80069508[func_8001B834(2)].b = n;
            } else {
                D_80069508[idx].a = 2;
                D_80069508[idx].b = n;
            }
            break;
        case 0x16:
            D_80062E90 = 2;
            idx = func_80019608(3);
            if (idx == -1) {
                D_80069508[func_8001B834(3)].b = n;
            } else {
                D_80069508[idx].a = 3;
                D_80069508[idx].b = n;
            }
            break;
        case 0x17:
            idx = func_80019608(4);
            D_80069508[idx].a = D_800730DE[off];
            D_80069508[idx].b = n;
            break;
        }
    } else {
        D_80062FFC = 0xE;
        q = D_80062F7C;
        q->a = D_800730DE[id * 0x14];
        q->b = n;
    }
}

void func_8001A174(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFF;
    switch (temp_a0) {
    case 2:
        func_8001A280(arg1 & 0xFF, arg2);
        return;
    case 3:
        func_8001A1C8(arg1 & 0xFF, arg2);
        return;
    }
}

void func_8001A1C8(s32 arg0, s32 arg1) {
    s32 id;
    s32 r;
    s32 x;
    s32 off;
    Obj1A *p;

    id = arg0 & 0xFF;
    r = func_8001AC9C(id);
    if (D_80063020 != 0) {
        off = id * 20;
        p = D_80062F7C;
        p->a = *(D_800730DE + off);
        p->b = r;
        switch (*(D_800730DE + off)) {
        case 0x57:
            x = 0x10;
            break;
        case 0x51:
        case 0x63:
            x = 0xF;
            break;
        default:
            return;
        }
        D_80062FFC = x;
    }
}

void func_8001A280(s32 arg0, s32 arg1) {
    s32 id;
    s32 r;
    s32 off;
    Obj1A *p;

    id = arg0 & 0xFF;
    r = func_8001AC9C(id);
    if (D_80063020 != 0) {
        off = id * 20;
        p = D_80062F7C;
        p->a = *(D_800730DE + off);
        p->b = r * 10;
        switch (*(D_800730DE + off)) {
        case 0x64:
            D_80062FFC = 0x10;
            break;
        case 0x58:
            D_80062FFC = 0x10;
            break;
        case 0x59:
            D_80062FFC = 0x10;
            break;
        case 0x5A:
            D_80062FFC = 0x10;
            break;
        case 0x56:
            D_80062FFC = 0x10;
            break;
        case 0x5C:
            D_80062FFC = 0x10;
            break;
        case 0x5D:
            D_80062FFC = 0x10;
            break;
        case 0x5E:
            D_80062FFC = 0x10;
            break;
        case 0x5F:
            D_80062FFC = 0x10;
            break;
        case 0x54:
        case 0x55:
            D_80062FFC = 0xF;
            break;
        }
    }
}

void func_8001A384(s32 arg0) {
    func_8001AC9C(arg0 & 0xFF);
    if (D_80063020 != 0) {
        D_80062FFC = 0xB;
    }
}

void func_8001A3B8(s32 arg0, s32 arg1, s32 arg2) {
    s32 bits;
    s32 i;

    if (D_80063020 == 0) {
        bits = arg2 & 0xFFFFFF;
        i = 0;
        do {
            if (bits & 1) {
                func_8001BD50(i, i + 0x48, i + 0x48);
            }
            bits >>= 1;
            i++;
        } while (i < 0x18);
        func_8001B834(0xD);
        return;
    }
    D_80062FFC = 8;
}

void func_8001A440(void) {
    if (D_80063020 == 0) {
        func_8001B834(5);
        func_8001B834(6);
        func_8001B834(7);
        func_8001B834(9);
        func_8001B834(0xA);
        func_8001B834(0xB);
        func_8001B834(0xC);
        return;
    }
    D_80062FFC = 5;
}

void func_8001A4A8(void) {
    s32 var_s0;

    if (D_80063020 == 0) {
        var_s0 = 0;
        do {
            func_8001BCE8(var_s0 & 0xFF);
            var_s0 += 1;
        } while (var_s0 < 0x38);
        func_8001B834(2);
        if (D_80062E8C == 0) {
            D_80062E8C = 1;
        }
    } else {
        D_80062FFC = 6;
    }
}

void func_8001A518(void) {
    s32 i;
    u8 *p;
    u8 c;

    if (D_80063020 == 0) {
        c = 0xFF;
        i = 15;
        p = &D_800694C3;
        for (; i >= 0; i--) {
            *p-- = c;
        }
        for (i = 0x38; i < 0x48; i++) {
            func_8001BD50(i - 0x38, i, i);
        }
        func_8001B834(3);
        if (D_80062E90 == 0) {
            D_80062E90 = 1;
        }
    } else {
        D_80062FFC = 7;
    }
}

void func_8001A5B4(u8 arg0, u8 arg1, M2C_UNK arg2) {
    s32 r;

    r = func_8001AC9C(arg1, arg2);
    switch (arg0) {
    case 0:
        func_8001A684(arg1, arg2);
        break;
    case 2:
        func_8001A780(arg1, arg2);
        break;
    case 4:
        func_8001A874(arg1, arg2);
        break;
    case 3:
        func_80019D74(r & 0xFF, arg1);
        break;
    }
}

void func_8001A684(u8 arg0, s32 arg1) {
    s32 off;

    func_8001AC9C(arg0, arg1);
    if (D_80063020 == 0) {
        off = arg0 * 0x14;
        if (D_800730DE[off] == 0x62) {
            D_80062E60[0x23] |= 8;
        }
        if (D_800730DE[off] == 0xC) {
            D_80062E60[0x23] |= 1;
        }
    } else {
        off = arg0 * 0x14;
        if (D_800730DE[off] == 0x62) {
            D_80062FFC = 0x11;
        }
        if (D_800730DE[off] == 0xC) {
            D_80062FFC = 0x11;
        }
    }
}

void func_8001A780(u8 arg0, s32 arg1) {
    s32 s0;
    s32 a1;
    Obj1A *p;

    s0 = arg0 & 0xFF;
    a1 = func_8001AC9C(s0);
    if (s0 == 0xD) {
        func_80019DA0(a1 & 0xFF, 0xD);
        return;
    }
    if (D_80063020 == 0) {
        D_800694E4[D_800730DD[s0].b[0]] += D_800730DD[s0].b[a1];
        return;
    }
    p = D_80062F7C;
    p->a = D_800730DD[s0].b[0];
    p->b = D_800730DD[s0].b[a1];
    D_80062FFC = 4;
}

void func_8001A874(u8 arg0, s32 arg1) {
    s32 s0;
    s32 n;
    s32 s2;
    s32 c;
    Obj1A *q;

    s0 = arg0 & 0xFF;
    n = func_8001AC9C(s0);
    while (n > 0) {
        c = D_800730DD[s0].b[n];
        if (c != 0xFF) {
            s2 = c;
            break;
        }
        n--;
    }
    if (D_80063020 == 0) {
        D_800694E4[D_800730DD[arg0].b[0]] += s2;
        return;
    }
    q = D_80062F7C;
    q->a = D_800730DD[arg0].b[0];
    q->b = s2;
    D_80062FFC = 0xD;
}

void func_8001A980(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFF;
    switch (temp_a0) {
    case 4:
        func_8001AB1C(arg1 & 0xFF, arg2);
        return;
    case 2:
        func_8001A9CC(arg1 & 0xFF, arg2);
        return;
    }
}

void func_8001A9CC(arg0) {
    s32 id;
    s32 n;
    s32 i;
    s32 a;
    u8 *p;
    Obj1A *q;
    s32 last;
    s32 b;

    id = arg0 & 0xFF;
    n = func_8001AC9C(id);
    for (i = n; i > 0; i--) {
        p = D_800730DE + id * 0x14;
        b = p[i];
        if (b != 0xFF) {
            last = b;
            break;
        }
    }
    if (D_80063020 == 0) {
        a = arg0 & 0xFF;
        ((u16 *)&D_80062E6C)[D_800730DE[a * 0x14]] += last;
        if (a == 0xA) {
            if (*(s16 *)&D_80062E72 >= 0x56) {
                *(s16 *)&D_80062E72 = 0x55;
            }
            if (n == 5) {
                D_80062E5C = 1;
            }
        }
    } else {
        q = D_80062F7C;
        q->a = D_800730DE[(arg0 & 0xFF) * 0x14];
        q->b = n;
        D_80062FFC = 0xA;
    }
}

void func_8001AB1C(arg0)
{
  s32 id;
  s32 n;
  s32 i;
  u8 *p;
  Obj1A *q;
  u8 *new_var;
  s32 last2;
  s32 last3;
  s32 b;
  id = arg0 & 0xFF;
  n = func_8001AC9C(id);
  if (id == 7)
  {
    for (i = n; i > 0; i--)
    {
      new_var = D_8007316A;
      b = new_var[i];
      if (b != 0xFF)
      {
        last3 = b;
        break;
      }
    }

  }
  else
  {
    for (i = n; i > 0; i--)
    {
      p = D_800730DE + (id * 0x14);
      b = p[i];
      if (b != 0xFF)
      {
        last2 = b;
        break;
      }
    }

  }
  if (D_80063020 == 0)
  {
    if ((arg0 & 0xFF) == 7)
    {
      *((u16 *) (&D_80062E74)) += last3;
    }
    else
    {
      ((u16 *) (&D_80062E6C))[D_800730DE[(arg0 & 0xFF) * 0x14]] += last2;
    }
  }
  else
  {
    q = D_80062F7C;
    q->a = D_800730DE[(arg0 & 0xFF) * 0x14];
    q->b = last2;
    D_80062FFC = 9;
  }
}

s32 func_8001AC9C(arg0, arg1) {
    s32 i;
    s32 ff1;
    s32 ff2;
    s32 w;
    s32 id20;
    s32 t0;
    s32 v;
    u16 *p;
    u8 *q;
    u8 *e;

    t0 = 1;
    for (i = 3, ff1 = 0xFFFF, p = (u16 *)((u8 *)&D_800730D6 + (arg0 & 0xFF) * 0x14); i >= 0; p--, i--) {
        v = *p;
        if (v == ff1 || arg1 < v * 100) {
            continue;
        }
        t0 = i + 2;
        break;
    }
    D_80062FBC = 1;
    for (i = 0, ff2 = 0xFFFF, p = (u16 *)((u8 *)&D_800730D0 + (arg0 & 0xFF) * 0x14); i < 4; p++, i++) {
        if (*p != ff2) {
            D_80062FBC += 1;
        }
    }
    if (D_80063020 != 0) {
        id20 = (arg0 & 0xFF) * 0x14;
        e = D_800730CE;
        w = *(u16 *)(e + t0 * 2 + id20);
        if (w == 0xFFFF || t0 == D_80062FBC) {
            D_80062F10 = 0;
        } else {
            D_80062F10 = w * 100 - arg1;
        }
        q = (u8 *)D_80062F7C;
        q[0] = t0;
        q[1] = D_80062FBC;
        *(s32 *)(q + 4) = D_80062F10;
    }
    return t0;
}

void func_8001AE08(void) {
    if (M2C_FIELD(&D_80062E6C, s16 *, 0) >= 0x21) {
        M2C_FIELD(&D_80062E6C, s16 *, 0) = 0x20;
    }
    if (D_80062E70 >= 0x21) {
        D_80062E70 = 0x20;
    }
    if (M2C_FIELD(&D_80062E6C, s16 *, 2) >= 0x100) {
        M2C_FIELD(&D_80062E6C, s16 *, 2) = 0xFF;
    }
    if (D_80062E74 >= 0x100) {
        D_80062E74 = 0xFF;
    }
    M2C_FIELD(D_80062E60, u8 *, 0x43C) = (u8) (M2C_FIELD(D_80062E60, u8 *, 0x43C) + (u8) M2C_FIELD(&D_80062E6C, s16 *, 0));
    M2C_FIELD(D_80062E60, u8 *, 0x43D) = (u8) (M2C_FIELD(D_80062E60, u8 *, 0x43D) + (u8) M2C_FIELD(&D_80062E6C, s16 *, 2));
    M2C_FIELD(D_80062E60, u8 *, 0x437) = (u8) (M2C_FIELD(D_80062E60, u8 *, 0x437) + (u8) D_80062E74);
    M2C_FIELD(D_80062E60, u8 *, 0x43E) = (u8) (M2C_FIELD(D_80062E60, u8 *, 0x43E) + (u8) D_80062E70);
    M2C_FIELD(D_80062E60, u8 *, 0x43F) = (u8) (M2C_FIELD(D_80062E60, u8 *, 0x43F) + D_80062E72);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001AEE4);

void func_8001B4A0(s32 arg0) {
    s32 s0;
    s32 a0;
    s32 a1;
    s32 v1;
    Obj1A *p;

    s0 = arg0 & 0xFF;
    a0 = func_8001AC9C(s0);
    a1 = D_800730DE[s0 * 0x14];
    if (D_80063020 == 0) {
        v1 = D_8006947C[a1];
        if (v1 != 0xFF) {
            D_8006947C[a1] = v1 + a0;
        }
        func_8001BD50((a1 - 0x38) & 0xFF, a1, a1);
        func_8001B834(3);
        if (D_80062E90 == 0) {
            D_80062E90 = 1;
        }
    } else {
        p = D_80062F7C;
        p->a = a1 - 0x38;
        p->b = a0;
        D_80062FFC = 2;
    }
}

void func_8001B570(void) {
    s32 a;
    s32 i;

    a = 0x1C0;
    i = 0x38;
    do {
        *(D_80062E60 + a + 0x10A) = D_8006947C[i];
        *(D_80062E60 + a + 0x10B) = D_8006948C[i];
        *(D_80062E60 + a + 0x10C) = D_8006949C[i];
        a += 8;
        i++;
    } while (a < 0x240);
}

void func_8001B5E4(s32 arg0) {
    ObjSlots *obj;
    u8 *p;
    s32 id;
    s32 cnt;
    s32 i;
    s32 v;

    id = arg0 & 0xFF;
    cnt = func_8001AC9C(id);
    if (D_80063020 == 0) {
        for (i = cnt - 1; i >= 0; i--) {
            p = D_800730DE + id * 0x14;
            v = p[i];
            if (v != 0xFF) {
                func_8001BCE8(v);
            }
        }
        func_8001B834(2);
        if (D_80062E8C == 0) {
            D_80062E8C = 1;
        }
    } else {
        obj = (ObjSlots *) D_80062F7C;
        p = D_800730DE + id * 0x14;
        for (i = 0; i < 5; i++) {
            obj->e[i].a = p[i];
            obj->e[i].b = 0;
        }
        for (i = 0; i < cnt; i++) {
            obj->e[i].b = 1;
        }
        D_80062FFC = 1;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001B704);

s32 func_8001B834(s32 arg0) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (D_80069508[i].a == (arg0 & 0xFF)) {
            return i;
        }
    }
    D_80069508[D_80062E64++].a = arg0;
    return D_80062E64 - 1;
}

void func_8001B8A8(void) {
    s32 i;
    s32 found;

    found = 0;
    for (i = 0; i < 16; i++) {
        if (D_80069508[i].a == 0x11) {
            found = 1;
            break;
        }
    }
    for (i = 0; i < 16; i++) {
        if (found == 1) {
            if (D_80069508[i].a == 5) {
                D_80069508[i].a = 0xFF;
            }
        }
    }
}

void func_8001B944(void) {
    s32 i;
    s32 n;

    D_80062E7C = 0;
    D_80062E80 = 0;
    func_8001B8A8();
    for (i = 0; i < 16; i++) {
        if (D_80069508[i].a != 0xFF) {
            if (D_80069508[i].a == 2 && D_80062E8C == 2) {
                D_80069508[i].a = 0x15;
            }
            if (D_80069508[i].a == 3 && D_80062E90 == 2) {
                D_80069508[i].a = 0x16;
            }
            func_8001BB30(D_80069508[i].a, func_8001BA54(D_80069508[i].a));
            D_80062E7C++;
        }
    }
    n = D_80062E7C;
    D_80062E60[0x21] = (n - 1) / 4 + 1;
}

s32 func_8001BA54(s32 arg0) {
    s32 i;
    u8 *p;

    if (arg0 == 24) { return 0; }
    if (arg0 == 25) { return 0; }
    if (arg0 == 26) { return 0; }
    if (arg0 == 27) { return 0; }
    if (arg0 == 1) { return 0; }
    if (arg0 == 4) { return 3; }
    if (arg0 == 23) { return 3; }
    if (arg0 == 2) { return 1; }
    if (arg0 == 21) { return 1; }
    if (arg0 == 3) { return 2; }
    if (arg0 == 22) { return 2; }
    if (D_80062E8C == 0) {
        D_80062E8C = 1;
        return 1;
    }
    if (D_80062E90 == 0) {
        D_80062E90 = 1;
        return 2;
    }
    p = D_80062E60 + 0x18;
    for (i = 4; i < 0x10; i++) {
        if (p[0x4C] == 0xFF) {
            return i;
        }
        p += 6;
    }

}

void func_8001BB30(u8 arg0, u8 arg1) {
    s32 i;

    ((Obj4C *) D_80062E60)->e[arg1].a = arg0;
    ((Obj4C *) D_80062E60)->e[arg1].d = 0;
    ((Obj4C *) D_80062E60)->e[arg1].b = D_800707C4[arg0].a;
    ((Obj4C *) D_80062E60)->e[arg1].c = D_800707C4[arg0].b;
    for (i = 0; i < 16; i++) {
        if (arg0 == D_80069508[i].a) {
            ((Obj4C *) D_80062E60)->e[arg1].e = D_80069508[i].b;
            ((Obj4C *) D_80062E60)->e[arg1].f = D_80069508[i].c;
            return;
        }
    }
}

void func_8001BC18(void) {
    s32 i;

    for (i = 0; i < 0x38; i++) {
        func_8001BD50(D_80069554[i].id, i, D_80069554[i].id);
        ((Obj10A *) D_80062E60)->e[i].a = D_80069554[i].unk1;
        ((Obj10A *) D_80062E60)->e[i].b = D_80069554[i].unk2;
        ((Obj10A *) D_80062E60)->e[i].c = D_80069554[i].unk3;
        ((Obj10A *) D_80062E60)->e[i].f = D_80069554[i].unk4;
    }
}

void func_8001BCE8(u8 id) {
    s32 i;

    for (i = 0; i < 0x38; i++) {
        if (D_80069554[i].id == id) {
            return;
        }
    }
    D_80069554[D_80062E68++].id = id;
}

void func_8001BD50(u8 arg0, u8 arg1, u8 arg2) {
    s32 a;
    s32 b;

    a = arg1 * 8;
    b = arg2 * 0x1C;
    *(D_80062E60 + a + 0x108) = arg0;
    *(D_80062E60 + a + 0x109) = D_800708C8[b];
    *(D_80062E60 + a + 0x10D) = D_800708D0[b];
}
