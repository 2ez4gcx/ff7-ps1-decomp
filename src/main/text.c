#include "common.h"
#include "main/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
extern struct { s16 a; s16 pad; s32 b; s32 c; } D_8009A000;
M2C_UNK func_8002988C(M2C_UNK, M2C_UNK);
extern volatile s16 D_8009AC42;
void func_800A16CC(void);
void func_800CF60C(void);
extern volatile s16 D_80114488;
u16 func_800A460C(s32 *, s32 *, M2C_UNK *, M2C_UNK);
M2C_UNK func_800D8D78();
extern u8 D_80062D98;
extern u8 D_80062D99;
extern volatile s32 D_8009D264;
extern volatile s32 D_8009D268;
extern u8 D_8009D2E7;

void func_800110B8(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", main_entry);

void func_8001117C(u16 arg0) {
    D_8009A000.a = 0xF1;
    func_8002DA7C();
    D_8009A000.a = 0x20;
    D_8009A000.b = 0x40;
    D_8009A000.c = arg0;
    func_8002DA7C();
}

void func_800111E4(s32 arg0) {
    s32 x;
    D_8009A000.a = 0xF4;
    func_8002DA7C(arg0);
    if (!(D_8009D5E9 & 0x30)) {
        func_8001117C(0x2B);
    }
    x = D_8009ABF6;
    D_800707BC = x;
    (&D_800707BC)[1] = D_8009AC32;
    (&D_800707BC)[1] = D_800716D0 | D_8009AC32;
    func_800146A4(x);
    D_800716D0 = 0;
}

void func_80011274(void) {
    func_80033E34(D_80048D1C, D_80048D20, 0x800E0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80033E34(D_80048D14, D_80048D18, 0x800A0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80029818(0x800A0000, 0x800E0000);
}

void func_800112E8(void) {
    s32 t;

    if (D_800965EC == 2) {
        do {
        } while (func_80034B44() != 0);
        func_80015CA0(0x801C0000, 0x800A0000);
    } else {
        do {
        } while (func_80034B44() != 0);
        func_80033E34(D_80048D2C, D_80048D30, 0x80180000, 0);
        do {
        } while (func_80034B44() != 0);
        func_80015CA0(0x80180000, 0x800A0000);
    }
    if (D_80071E28 != 2) {
        if (D_800965EC == 2) {
            D_80071E28 = 1;
        } else {
            D_80071E28 = 0;
        }
        D_800730CC = (s16)D_8009A05C;
    }
    t = (s16)D_8009A05C;
    if (t != D_80071A5C || t == 0) {
        D_80075DEC = func_800A460C(&D_80071E28, &D_800730CC, &D_80095DDC, 0);
    } else {
        D_80075DEC = func_800A460C(&D_80071E28, &D_800730CC, &D_80095DDC, 0x801B0000);
        D_80071A5C = 0;
        D_800965E8 = 0;
    }
    D_8009A05C = D_8009ABF6;
}

void func_8001146C(void) {
    if (D_80071A58 != 0) {
        D_80075DEC++;
        D_80075DEC &= 1;
        func_80013800();
        func_800444AC((s32 *)&D_8007EB68[(s16) D_80075DEC]);
        func_800443B0((s32 *)((u8 *)D_8007EAAC + (s16) D_80075DEC * 0x5C));
        func_8004433C((s32)(D_8007E7A0 + (s16) D_80075DEC * 4));
    }
}

void func_8001155C(void)
{

  switch (*((volatile s16 *) (&D_80095DD4)))
  {
    case 0:
      break;

    case 1:
      func_8001146C();
      break;

    case 2:
      func_800D8D78();
      break;

    case 3:
      func_800140A4();
      break;

    case 4:
      func_80022B5C();
      break;

  }

  if ((D_80062D98 == 0) && (D_80062D99 == 0))
  {
    D_8009D26C[0] += 0x444;
    if ((D_8009D26C[0] >> 16) != 0)
    {
      ++D_8009D264;
      D_8009D26C[0] &= 0xFFFF;
    }

    D_8009D270 += 0x444;
    if ((D_8009D270 >> 16) != 0)
    {
      if (!(D_8009D2E7 & 2))
      {
        if (D_8009D268 != 0)
        {
          --D_8009D268;
        }
      }
      else
      {
        ++D_8009D268;
      }
      D_8009D26C[1] &= 0xFFFF;
    }
  }
  D_8007E768 = 1;
}

void func_8001171C(void) {
    func_8003D1B4();
    func_8003D0C0();
    func_80043938(0);
    func_80036298();
    D_80095DD4 = 0;
    func_8003D150((s32) &func_8001155C);
    func_80043BA8(0);
    func_80043D3C(0);
    func_80039EDC();
}

void func_80011784(void) {
    func_800438D4(D_8007EB68, 0, 0xE8, 0x140, 0xF0);
    func_800438D4(&D_8007EB68[1], 0, 0, 0x140, 0xF0);
    func_80043814(&D_8007EAAC[0], 0, 8, 0x140, 0xE0);
    func_80043814((Spr *)((u8 *)D_8007EAAC + 0x5C), 0, 0xF0, 0x140, 0xE0);
    D_8007EAC2 = 1;
    D_8007EB1E = 1;
    D_8007EAC4 = 0;
    D_8007EB20 = 0;
    func_800444AC((s32 *) D_8007EB68);
    func_800443B0((s32 *) &D_8007EAAC);
}

void func_80011860(void) {
    if (D_800965EC != 5 && D_800965EC != 13) {
        if (D_800965EC != 2) {
            func_80033E34(D_80048D24, D_80048D28, 0x80180000, 0);
            while (func_80034B44() != 0) {
            }
            func_80015CA0(0x80180000, 0x800A0000);
        } else {
            while (func_80034B44() != 0) {
            }
            func_80015CA0(0x801C0000, 0x800A0000);
        }
    }
    func_800CF60C();
    func_800A16CC();
}

void func_80011920(void) {
    D_800965E8 = 0;
    D_80071A5C = 0;
}

void func_80011938(void) {
    func_80033E34(D_80048CFC, D_80048D00, 0x800F0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80033E34(D_80048D04, D_80048D08, 0x801B0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80033E34(D_80048D0C, D_80048D10, 0x801BC800, 0);
    do {

    } while (func_80034B44() != 0);
    func_8002988C(0x800F0000, 0x801BC800);
    func_80029998(0x801B0000);
}

void func_800119E4(void) {
    s32 i;

    if (D_8009C560 == 3) {
        D_8009D274.a = 2;
        D_8009D278 = 3;
    } else {
        D_8009D274.a = 0;
        D_8009D278 = 1;
    }
    D_8009D274.c = D_8009A05C;
    i = D_800965E0 * 0x84;
    D_8009D27E = *(s32 *)((u8 *)D_80074EB0 + i) >> 12;
    D_8009D280 = *(s32 *)((u8 *)D_80074EB4 + i) >> 12;
    D_8009D282 = *(u16 *)((u8 *)D_80074F16 + i);
    D_8009D284 = *((u8 *)D_80074EDA + i);
    D_8009D285 = D_8009C540;
    D_8009D286 = D_8009AD2C;
}

void func_80011AEC(void) {
    D_80071E28 = D_8009D274.a;
    D_8009C560 = D_8009D274.b;
    if ((u16) D_8009C560 == 0) {
        D_8009C560 = 1;
    }
    D_8009A05C = D_8009D274.c;
    D_8009AC58 = D_8009D274.c;
    D_8009ABF8 = D_8009D274.d;
    D_8009ABFA = D_8009D274.e;
    D_8009AC16 = D_8009D274.f;
    D_8009AC18 = D_8009D274.g;
    D_8009C540 = D_8009D274.h;
    D_8009AD2C = D_8009D274.i;
}

void func_80011BB4(void) {
    D_8009D588[0] = 1;
    *(volatile s32 *)((u8 *)&D_8009D278 - 4) = 0;
    D_8009D278 = 1;
    D_8009D27A = 0x74;
    D_8009D27E = 0;
    D_8009D280 = 0;
    D_8009D282 = 0;
    D_8009D284 = 0;
    D_8009D285 = 0;
    D_8009D286 = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80011C1C);

void func_80012840(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_8004656C(0, arg0, 0, 0) & 0xFFFF;
    func_80044A68(D_8009A068, 0, 0, temp_s0, 0);
    func_80044A68(D_8009A068 + 0x30, 0, 0, temp_s0, 0);
}

void func_800128B8(void) {
    s32 i;
    s32 j;
    Tile16 *q;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            func_800469B0(&((TileBuf *) D_8009A068)[i].tile[j]);
            func_80046848(&((TileBuf *) D_8009A068)[i].tile[j], 1);
            func_80046870(&((TileBuf *) D_8009A068)[i].tile[j], 1);
            q = (Tile16 *) ((u8 *) &((TileBuf *) D_8009A068)[0].tile[0] + (i * 0x30 + j * 0x10));
            q->r0 = 0;
            q->g0 = 0;
            q->b0 = 0;
            q->w = 0xA0;
            q->h = 0xE0;
        }
    }
    D_8009A07C = 0;
    D_8009A07E = 0;
    D_8009A08C = 0xA0;
    D_8009A08E = 0;
    D_8009A0AC = 0;
    D_8009A0AE = 0;
    D_8009A0BC = 0xA0;
    D_8009A0BE = 0;
}

void func_800129D0(void) {
    func_800440C8(&D_8007EB68[(s16) D_80075DEC].disp,
                  D_8007EB68[((s16) D_80075DEC + 1) & 1].disp.x,
                  D_8007EB68[((s16) D_80075DEC + 1) & 1].disp.y);
    while (func_80043DD8(1) != 0) {
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80012A8C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80012DB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800131B8);

void func_800134F4(void) {
    D_8009AC42 -= D_8009AC44;
    D_8009AC2C = 0;
    if (D_8009AC42 <= 0 || D_80114488 == 1) {
        D_8009AC40 = 0;
        D_8009AC42 = 0;
    }
}

void func_80013564(void) {
    D_8009AC2B[1] = 0;
    D_8009AC42 += D_8009AC44;
    if (D_8009AC42 >= 0x100) {
        D_8009AC42 = 0xFF;
    }
}

s16 func_800135C0(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    return (s16) (arg0 + ((s32) ((s16) (arg1 - arg0) * arg2) / arg3));
}

void func_80013624(void) {
    D_8009AC2B[1] = 0;
    D_8009AC42 += 1;
    D_8009AC42;
    if ((s16)D_8009AC42 >= (s16)(*(volatile u16 *)&D_8009AC44)) {
        (*(volatile u16 *)&D_8009AC4C) = (*(volatile u16 *)&D_8009AC52);
        (*(volatile u16 *)&D_8009AC4E) = (*(volatile u16 *)&D_8009AC54);
        (*(volatile u16 *)&D_8009AC50) = (*(volatile u16 *)&D_8009AC56);
        D_8009AC42 = (*(volatile u16 *)&D_8009AC44);
    }
    (*(volatile u16 *)&D_8009AC46) = func_800135C0((s16)(*(volatile u16 *)&D_8009AC4C), (s16)(*(volatile u16 *)&D_8009AC52), (s16)D_8009AC42, (s16)(*(volatile u16 *)&D_8009AC44));
    (*(volatile u16 *)&D_8009AC48) = func_800135C0((s16)(*(volatile u16 *)&D_8009AC4E), (s16)(*(volatile u16 *)&D_8009AC54), (s16)D_8009AC42, (s16)(*(volatile u16 *)&D_8009AC44));
    (*(volatile u16 *)&D_8009AC4A) = func_800135C0((s16)(*(volatile u16 *)&D_8009AC50), (s16)(*(volatile u16 *)&D_8009AC56), (s16)D_8009AC42, (s16)(*(volatile u16 *)&D_8009AC44));
    func_800131B8((s16)(*(volatile u16 *)&D_8009AC46), (s16)(*(volatile u16 *)&D_8009AC48), (s16)(*(volatile u16 *)&D_8009AC4A));
}
