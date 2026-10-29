#include "common.h"
#include "main/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
extern s32 D_80062FC4;
extern void *D_80062F24;
s32 func_8002988C(s32 arg0, s32 arg1);
extern u16 D_80089580[];
extern u8 D_8004A60C[];
extern u8 D_8007E778[];
s32 func_80036FFC();
s32 func_800373AC();
s32 func_80038FB8();
s32 func_800297A4();
s32 func_800294BC();
s32 func_80042BC0();
s32 func_80042C98();
extern void func_80030234();
s32 func_80026B70(u8 *arg0);
M2C_UNK func_80027B84(Rect16 *);
M2C_UNK func_80028030(Rect16 *arg0, s32 arg1);
void func_80026F44(s16 arg0, s16 arg1, u8 *arg2, s32 arg3);
s16 func_80026C5C(s16, s16, s32, s32);
extern u8 D_80062DFD;
s32 func_80028CA0(s16 arg0, s16 arg1, s8 arg2, s8 arg3, u16 arg4, u16 arg5, s16 arg6, s32 arg7);
void func_80028E00(s32 arg0, s16 arg1, u32 value, s32 n, u8 clut);

void func_80026A00(s32 arg0) {
    D_80062FC4 = arg0;
}

void func_80026A0C(void) {
    D_8006300C = D_80062FC4;
}

void func_80026A20(void) {
    D_80062FC4 = D_8006300C;
}

void func_80026A34(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a1;

    func_80044A68((void *) D_80062F24, arg0, arg1, arg2, arg3);
    temp_a1 = D_80062F24;
    D_80062F24 = temp_a1 + 0xC;
    func_80046794(D_80062FC4, temp_a1);
}

void func_80026A94(s16 *arg0, u16 *arg1) {
    Spr s;

    func_80043814(&s, arg0[4], arg0[5], arg0[2], arg0[3]);
    s.f = 1;
    s.g = 0;
    s.x += arg1[0];
    s.y += arg1[1];
    s.w = arg1[2];
    s.h = arg1[3];
    s.e = 0x3F;
    func_80044AC0(D_80062F24, &s);
    func_80046794(D_80062FC4, D_80062F24);
    D_80062F24 += 0x40;
}

void func_80026B5C(void) {
}

void func_80026B64(s8 arg0) {
    D_80062DFC = arg0;
}

s32 func_80026B70(u8 *arg0) {
    s32 pad[1];
    s32 n;
    s32 total;
    s32 base;
    u8 c;
    u8 t;

    total = 0;
    for (n = 0; n < (u8) D_80062DFC; n++) {
        if (arg0 == NULL) {
            return total;
        }
        c = *arg0;
        if (c == 0xFF) {
            break;
        }
        switch (c) {
        case 0xFA:
            arg0++;
            base = 0xE7;
            break;
        case 0xFB:
            arg0++;
            base = 0x1B9;
            break;
        case 0xFC:
            arg0++;
            base = 0x2A0;
            break;
        case 0xFD:
            arg0++;
            base = 0x372;
            break;
        case 0xFE:
            arg0++;
            base = 0x444;
            break;

        default:
            base = 0;
            break;
        }
        t = D_800707C0[*arg0++ + base];
        total += t >> 5;
        total += t & 0x1F;
    }
    return total;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80026C5C);

void func_80026F44(s16 arg0, s16 arg1, u8 *arg2, s32 arg3) {
    s16 sp18[4];
    s16 i;
    u8 c;
    void *p;

    if (arg2 != NULL) {
        i = 0;
        if (D_80062DFC != 0) {
            while (1) {
                c = *arg2;
                if (c == 0xFF) {
                    break;
                }
                if ((u8)(c + 6) < 5 || c == 0xF8) {
                    arg0 = func_80026C5C(arg0, arg1, arg3 & 0xFF, c | (arg2[1] << 8));
                    arg2 += 2;
                } else {
                    arg2 += 1;
                    arg0 = func_80026C5C(arg0, arg1, arg3 & 0xFF, c);
                }
                i++;
                if (!(i < D_80062DFC)) {
                    break;
                }
            }
        }
        if (D_80062DFD != 0) {
            sp18[2] = 0xFF;
            sp18[3] = 0xFF;
            sp18[0] = 0;
            sp18[1] = 0;
            func_80044A68(D_80062F24, 0, 1, 0x3E, (s32)sp18);
            p = D_80062F24;
            D_80062F24 = (u8 *)p + 0xC;
            func_80046794(D_80062FC4, (s32)p);
        }
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_8002708C);

void func_80027354(s16 x, s16 y, u8 *str, u8 color) {
    s16 i;

    if (str != NULL) {
        for (i = 0; i < (u8) D_80062DFC; i++) {
            if (*str == 0xFF) {
                break;
            }
            func_8002708C(x, y, *str++, color);
            x += 8;
        }
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80027408);

void func_80027990(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s16 temp_a2;
    s16 temp_s1;
    void *temp_a1;
    void *temp_a1_2;

    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 3) = 6;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 7) = 0x4C;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s32 *, 0x18) = 0x55555555;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 8) = arg0;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 0xA) = arg1;
    temp_a2 = (arg0 + arg2) - 1;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 0xC) = temp_a2;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 0xE) = arg1;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 0x10) = temp_a2;
    temp_s1 = (arg1 + arg3) - 1;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 0x12) = temp_s1;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 0x14) = arg0;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 0x16) = temp_s1;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 4) = (s8) arg4;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 5) = (s8) arg4;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 6) = (s8) arg4;
    temp_a1 = (*(void *volatile *)&D_80062F24);
    (*(void *volatile *)&D_80062F24) = temp_a1 + 0x1C;
    func_80046794(D_80062FC4, (s32) temp_a1);
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 3) = 3;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 7) = 0x40;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 8) = arg0;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 0xA) = arg1;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 0xC) = arg0;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 0xE) = temp_s1;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 4) = (s8) arg4;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 5) = (s8) arg4;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 6) = (s8) arg4;
    temp_a1_2 = (*(void *volatile *)&D_80062F24);
    (*(void *volatile *)&D_80062F24) = temp_a1_2 + 0x10;
    func_80046794(D_80062FC4, (s32) temp_a1_2);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80027B84);

M2C_UNK func_80028030(Rect16 *arg0, s32 arg1) {
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;
    void *temp_a1_5;

    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 3) = 3;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 7) = 0x40;
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 8) = (u16) M2C_FIELD(arg0, u16 *, 0);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xA) = (u16) M2C_FIELD(arg0, u16 *, 2);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xC) = (u16) ((M2C_FIELD(arg0, u16 *, 0) + M2C_FIELD(arg0, u16 *, 4)) - 1);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 2);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u8 *, 4) = 0xF0;
    M2C_FIELD((*(void *volatile *)&D_80062F24), u8 *, 5) = 0xF0;
    M2C_FIELD((*(void *volatile *)&D_80062F24), u8 *, 6) = 0xF0;
    temp_a1 = (*(void *volatile *)&D_80062F24);
    (*(void *volatile *)&D_80062F24) = temp_a1 + 0x10;
    func_80046794(D_80062FC4, (s32) temp_a1);
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 3) = 3;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 7) = 0x40;
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 8) = (u16) M2C_FIELD(arg0, u16 *, 0);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xA) = (u16) ((M2C_FIELD(arg0, u16 *, 2) + M2C_FIELD(arg0, u16 *, 6)) - 1);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xC) = (u16) ((M2C_FIELD(arg0, u16 *, 0) + M2C_FIELD(arg0, u16 *, 4)) - 1);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xE) = (u16) ((M2C_FIELD(arg0, u16 *, 2) + M2C_FIELD(arg0, u16 *, 6)) - 1);
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 4) = 0x40;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 5) = 0x40;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 6) = 0x40;
    temp_a1_2 = (*(void *volatile *)&D_80062F24);
    (*(void *volatile *)&D_80062F24) = temp_a1_2 + 0x10;
    func_80046794(D_80062FC4, (s32) temp_a1_2);
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 3) = 3;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 7) = 0x40;
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 8) = (u16) M2C_FIELD(arg0, u16 *, 0);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xA) = (u16) M2C_FIELD(arg0, u16 *, 2);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xC) = (u16) M2C_FIELD(arg0, u16 *, 0);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xE) = (u16) ((M2C_FIELD(arg0, u16 *, 2) + M2C_FIELD(arg0, u16 *, 6)) - 1);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u8 *, 4) = 0xC8;
    M2C_FIELD((*(void *volatile *)&D_80062F24), u8 *, 5) = 0xC8;
    M2C_FIELD((*(void *volatile *)&D_80062F24), u8 *, 6) = 0xC8;
    temp_a1_3 = (*(void *volatile *)&D_80062F24);
    (*(void *volatile *)&D_80062F24) = temp_a1_3 + 0x10;
    func_80046794(D_80062FC4, (s32) temp_a1_3);
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 3) = 3;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 7) = 0x40;
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 8) = (u16) ((M2C_FIELD(arg0, u16 *, 0) + M2C_FIELD(arg0, u16 *, 4)) - 1);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xA) = (u16) M2C_FIELD(arg0, u16 *, 2);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xC) = (u16) ((M2C_FIELD(arg0, u16 *, 0) + M2C_FIELD(arg0, u16 *, 4)) - 1);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xE) = (u16) ((M2C_FIELD(arg0, u16 *, 2) + M2C_FIELD(arg0, u16 *, 6)) - 1);
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 4) = 0x70;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 5) = 0x70;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 6) = 0x70;
    temp_a1_4 = (*(void *volatile *)&D_80062F24);
    (*(void *volatile *)&D_80062F24) = temp_a1_4 + 0x10;
    func_80046794(D_80062FC4, (s32) temp_a1_4);
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 3) = 3;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 7) = 0x60;
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 8) = (u16) M2C_FIELD(arg0, u16 *, 0);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xA) = (u16) M2C_FIELD(arg0, u16 *, 2);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xC) = (u16) M2C_FIELD(arg0, u16 *, 4);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 6);
    M2C_FIELD((*(void *volatile *)&D_80062F24), u8 *, 4) = 0xA0;
    M2C_FIELD((*(void *volatile *)&D_80062F24), u8 *, 5) = 0xA0;
    M2C_FIELD((*(void *volatile *)&D_80062F24), u8 *, 6) = 0xA0;
    temp_a1_5 = (*(void *volatile *)&D_80062F24);
    (*(void *volatile *)&D_80062F24) = temp_a1_5 + 0x10;
    func_80046794(D_80062FC4, (s32) temp_a1_5);
}

void func_80028484(MainBox *arg0) {
    Rect16 r;
    s16 h;
    s32 t;
    s32 u;

    h = arg0->h;
    t = h * arg0->f4 / arg0->f2;
    u = h * arg0->f0 / arg0->f2;
    r.x = arg0->x;
    r.y = arg0->y + t;
    r.w = arg0->w - 1;
    r.h = u + 1;
    func_80028030(&r, t);
    r.x = arg0->x;
    r.y = arg0->y;
    r.w = arg0->w;
    r.h = arg0->h;
    func_80027B84(&r);
    func_80026A34(0, 1, 0x1F, 0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_800285AC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80028930);

s32 func_80028CA0(s16 arg0, s16 arg1, s8 arg2, s8 arg3, u16 arg4, u16 arg5, s16 arg6, s32 arg7) {
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 3) = 4;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 7) = 0x64;
    func_80046870((*(void *volatile *)&D_80062F24), 1);
    if ((arg7 << 0x10) != 0) {
        func_80046848((*(void *volatile *)&D_80062F24), 1);
    }
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 8) = arg0;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 0xA) = arg1;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 0xC) = arg2;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s8 *, 0xD) = arg3;
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0x10) = arg4;
    M2C_FIELD((*(void *volatile *)&D_80062F24), u16 *, 0x12) = arg5;
    M2C_FIELD((*(void *volatile *)&D_80062F24), s16 *, 0xE) = func_80046634(0x100, (s16) arg6 + 0x1E0);
    func_80046794(*(const s32 *)&D_80062FC4, (s32) (*(void *volatile *)&D_80062F24));
    (*(void *volatile *)&D_80062F24) = (*(void *volatile *)&D_80062F24) + 0x14;
}

void func_80028E00(s32 arg0, s16 arg1, u32 value, s32 n, u8 clut) {
  s32 x;
  s16 y;
  u32 div;
  void * volatile *new_var;
  s32 new_var2;
  u32 rem;
  s16 flag;
  s16 i;
  u32 digit;
  div = 1;
  flag = 1;
  x = arg0;
  y = arg1;
  new_var2 = n;
  for (i = 1; i < (new_var2 & 0xFF); i++)
  {
    div = div * 10;
  }

  rem = value;
  if ((new_var2 & 0xFF) == 3)
  {
    if (rem >= 1000)
    {
      rem = 999;
    }
  }
  for (i = 1; i < (new_var2 & 0xFF); i++)
  {
    *((s8 *) (((s8 *) (*(&D_80062F24))) + 3)) = 4;
    *((s8 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 7)) = 0x64;
    func_80046870(*((void * volatile *) (&D_80062F24)), 1);
    digit = rem / div;
    *((s16 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 8)) = x + ((i - 1) * 7);
    new_var = (void * volatile *) (&D_80062F24);
    *((s16 *) (((s8 *) (*new_var)) + 0xA)) = y;
    *((s8 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 0xC)) = (digit * 8) + 0x88;
    *((s8 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 0xD)) = 0;
    *((s16 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 0x10)) = 7;
    *((s16 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 0x12)) = 8;
    *((s16 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 0xE)) = func_80046634(0x100, clut + 0x1E0);
    if ((flag == 0) || (digit != 0))
    {
      flag = 0;
      func_80046794(*((const s32 *) (&D_80062FC4)), (s32) (*((void * volatile *) (&D_80062F24))));
      do
      {
      }
      while (0);
      *((void * volatile *) (&D_80062F24)) = (*((void * volatile *) (&D_80062F24))) + 0x14;
    }
    rem = rem % div;
    div = div / 10;
  }

  *((s8 *) (((s8 *) (*(&D_80062F24))) + 3)) = 4;
  *((s8 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 7)) = 0x64;
  func_80046870(*((void * volatile *) (&D_80062F24)), 1);
  *((s16 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 8)) = x + (((new_var2 & 0xFF) - 1) * 7);
  *((s16 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 0xA)) = y;
  *((s8 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 0xC)) = (rem * 8) + 0x88;
  *((s8 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 0xD)) = 0;
  *((s16 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 0x10)) = 7;
  *((s16 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 0x12)) = 8;
  *((s16 *) (((s8 *) (*((void * volatile *) (&D_80062F24)))) + 0xE)) = func_80046634(0x100, clut + 0x1E0);
  func_80046794(*((const s32 *) (&D_80062FC4)), (s32) (*((void * volatile *) (&D_80062F24))));
  *((void * volatile *) (&D_80062F24)) = (*((void * volatile *) (&D_80062F24))) + 0x14;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80029114);

void func_800293D0(void) {
    func_80038FEC(0);
    D_80062E08 = 0;
}

void func_800293F4(void) {
    D_80062E08 = 1;
    func_80038FEC((s32) &func_800293D0);
}

void func_80029424(s32 arg0, M2C_UNK arg1) {
    func_800293F4();
    func_80038F04(arg0, arg1);
}

void func_80029464(s32 arg0, M2C_UNK arg1) {
    func_800293F4();
    func_80037BE0(arg0, arg1);
}

void func_800294A4(void) {
    while (D_80062E08) {
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_800294BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_800297A4);

void func_80029818(u32 *arg0, u32 *arg1) {
    u32 *d;
    s32 n;

    func_80038F64(*arg0++);
    n = *(volatile u32 *)arg0;
    func_80029424((s32)(arg0 + 3), n);
    d = D_80076C68;
    n = 0x4B0;
    do {
        n--;
        *d++ = *arg1++;
    } while (n != 0);
    func_800294A4();
}

s32 func_8002988C(s32 arg0, s32 arg1) {
    s32 r;

    D_80062F74 = D_80089580;
    D_80062F84 = (u8 *) D_80089580 + 0x1000;
    func_80036FFC(4, D_8007E778);
    func_800373AC(0x77000, 0x2000);
    func_80038FB8(0);
    func_800297A4(arg0, arg1);
    func_80038F64(0x76FE0);
    func_80029424(D_8004A60C, 0x20);
    func_800294A4();
    func_800294BC();
    do {
        D_80062E00 = func_80042A00(0xF2000002, 2, 0x1000, func_80030234);
    } while (D_80062E00 == -1);
    while (func_80042A40(D_80062E00) == 0) {
    }
    while (func_80042BC0(0xF2000002, 0x43D1, 0x1000) == 0) {
    }
    do {
        r = func_80042C98(0xF2000002);
    } while (r == 0);
    return r;
}

void func_80029998(u32 *src) {
    u32 *dst;
    u16 n;

    dst = (u32 *) D_80062F74;
    n = 0x3200;
    do {
        n += 0xFFFF;
        *dst++ = *src++;
    } while (n != 0);
}

void func_800299C8(void) {
    do {

    } while (func_80042CCC(0xF2000002) == 0);
    func_80042AE0(0xF2000002, 2);
    do {

    } while (func_80042A50(D_80062E00) == 0);
    do {

    } while (func_80042A10(D_80062E00) == 0);
    func_80038FEC(0);
    func_80038A84(0);
    func_80038C04(0);
    func_80038C6C(0, 0xFFFFFF);
}
