#include "common.h"
#include "statmenu/decls.h"

void func_801D0000(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_801D0040(void) {
    u8 pad[8];

    func_80026448(D_801D1DE4, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0);
    func_80026448(D_801D1DE4 + 0x12, 0, 0, 1, 3, 0, 0, 1, 9, 0, 0, 0, 0, 0);
    D_801D1968 = 0;
    D_801D1E1C = D_80062F6C;
}

void func_801D0114(void) {
    s16 rect[4];

    func_80020B68(0x3E, 0xE, D_801D1E1C);
    func_8001CF3C(0xA, 9, 0x30, 0x30, 0, D_801D1E1C * 0x30 + 0x38, 0x30, 0x30, D_801D1E1C + 0xD, 0);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0x100;
    rect[3] = 0x100;
    func_80026A34(0, 1, 0x7F, (s32)rect);
}

void func_801D01B4(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 st;
    s32 a0;
    s32 a1;
    s32 a2;
    u8 lo;
    u8 hi;
    u8 *t;
    u8 pad[16];
    s32 c;

    for (i = 0; i < 0x1B; i++) {
        if (i == 0x13) {
            continue;
        }
        t = (u8 *)((s32 (*)(s32, s32, s32))func_80015248)(8, 0xB, 8);
        switch (arg2) {
        case 0:
            st = D_8009D890[D_801D1E1C][0] & (1 << i);
            break;
        case 1:
            st = D_8009D890[D_801D1E1C][1] & (1 << i);
            break;
        }
        if (i != 0x1A) {
            c = arg0 + 0x6A;
            a0 = c + (i % 13) * 0xE;
            if (i >= 0x14) {
                a0 -= 0xE;
            }
            a1 = arg1 + (arg2 << 5);
            if (i / 13 != 0) {
                a1 += 0x10;
            }
            hi = t[i * 2 + 0x13];
            lo = t[i * 2 + 0x12];
            a2 = -(st != 0) & 7;
            func_80026C5C(a0, a1, a2, (hi << 8) | lo);
        } else {
            a0 = arg0 + 0x112;
            a1 = arg1 + (arg2 << 5) + 0x10;
            a2 = -(st != 0) & 7;
            hi = t[0x47];
            lo = t[0x46];
            func_80026C5C(a0, a1, a2, (hi << 8) | lo);
        }
    }
}

void func_801D037C(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 x;
    s32 st;
    u8 *t;
    u8 pad[16];

    for (i = 0; i < 9; i++) {
        t = (u8 *)((s32 (*)(s32, s32, s32))func_80015248)(8, 0xB, 8);
        switch (arg2) {
        case 0:
            st = D_8009D888[D_801D1E1C].flags & (1 << i);
            break;
        case 1:
            st = D_8009D88A[D_801D1E1C].a & (1 << i);
            break;
        case 2:
            st = D_8009D88C[D_801D1E1C].a & (1 << i);
            break;
        case 3:
            st = D_8009D88C[D_801D1E1C].b & (1 << i);
            break;
        }
        func_80026C5C(arg0 + 0x6A + i * 0xE, arg1 + arg2 * 0x10, -(st != 0) & 7, (t[i * 2 + 1] << 8) | t[i * 2]);
    }
}

void func_801D053C(s32 arg0, s32 arg1) {
    s32 a;
    s32 b;
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    s32 st;
    s32 fp;
    s32 k;
    s32 bit;
    u8 *s;

    switch (D_801D1968) {
    case 1:
        func_80026F44(arg0 - 0x10, arg1 - 0x10, D_801D1BE4, 5);
        func_80026F44(arg0, arg1, D_801D1BE4 + 0x1E, 5);
        func_80026F44(arg0, arg1 + 0x22, D_801D1BE4 + 0x3C, 5);
        func_80026F44(arg0, arg1 + 0x44, D_801D1BE4 + 0x4B, 5);
        func_80026F44(arg0, arg1 + 0x66, D_801D1BE4 + 0x5A, 5);
        i = 0;
        fp = arg1;
        do {
            x = arg0 + 0x2D;
            j = 0;
            k = 0;
            y = fp;
            do {
                bit = 1 << j;
                switch (i) {
                case 0:
                    st = D_8009D888[D_801D1E1C].flags & bit;
                    break;
                case 1:
                    st = D_8009D88A[D_801D1E1C].a & bit;
                    break;
                case 2:
                    st = D_8009D88C[D_801D1E1C].a & bit;
                    break;
                case 3:
                    st = D_8009D88C[D_801D1E1C].b & bit;
                    break;
                }
                s = D_801D196C + k;
                if (func_80026B70(s) + x >= 0x15F) {
                    y += 0xE;
                    x = arg0 + 0x2D;
                }
                func_80026F44(x, y, s, -(st != 0) & 7);
                x += 0xA + func_80026B70(s);
                j++;
                k += 0xA;
            } while (j < 9);
            i++;
            fp += 0x22;
        } while (i < 4);
        break;
    case 2:
        arg0 -= 0x10;
        arg1 -= 2;
        func_80026F44(arg0 - 0xE, arg1 - 0xE, D_801D1BF3, 5);
        func_80026F44(arg0 - 0xA, arg1, D_801D1BF3 + 0xF, 5);
        func_80026F44(arg0 - 0xA, arg1 + 0x48, D_801D1BF3 + 0x1E, 5);
        i = 0;
        fp = arg1;
        do {
            x = arg0 + 0x23;
            if (i == 1) {
                func_800269D0();
                func_800269C0((s32)(D_801D1E20 + (D_80062F58 << 13)));
            }
            j = 0;
            k = 0;
            y = fp;
            do {
                if (j != 0x13) {
                    bit = 1 << j;
                    switch (i) {
                    case 0:
                        st = D_8009D890[D_801D1E1C][0] & bit;
                        break;
                    case 1:
                        st = D_8009D890[D_801D1E1C][1] & bit;
                        break;
                    }
                    s = D_801D19C8 + k;
                    if (func_80026B70(s) + x >= 0x15F) {
                        y += 0xE;
                        x = arg0 + 0x23;
                    }
                    func_80026F44(x, y, s, -(st != 0) & 7);
                    x += 6 + func_80026B70(s);
                }
                j++;
                k += 0x14;
            } while (j < 0x1B);
            i++;
            fp += 0x48;
        } while (i < 2);
        func_800269E8();
        break;
    }
}

void func_801D0964(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3) {
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

void func_801D0B74(u8 *arg0, s32 arg1)
{
  u8 pad[8];
  u8 *c;
  u8 (*new_var)[][0x84];
  new_var = &D_8009C738;
  c = (*new_var)[D_800491D0[D_8009CBDC[D_801D1E1C]]];
  func_80026F44((s32) (arg0 + 0x38), arg1, ((s32 (*)(s32)) func_80021280)(c[0x1C] + 0x80), 7);
  func_80026F44((s32) (arg0 + 0x38), arg1 + 0x20, ((s32 (*)(s32)) func_80021280)(c[0x1D] | 0x100), 7);
  if (c[0x1E] != 0xFF)
  {
    func_80026F44((s32) (arg0 + 0x38), arg1 + 0x40, ((s32 (*)(s32)) func_80021280)(c[0x1E] + 0x120), 7);
  }
  func_80026F44((s32) (arg0 + 0x10), arg1, D_801D1D3D, 5);
  func_80026F44((s32) (arg0 + 0x10), arg1 + 0x20, D_801D1D3D + 0xF, 5);
  func_80026F44((s32) (arg0 + 0x10), arg1 + 0x40, D_801D1D3D + 0x1E, 5);
  func_801D0964(arg0 + 0x30, arg1 + 0x10, D_800738BC[c[0x1C]], c + 0x40);
  func_801D0964(arg0 + 0x30, arg1 + 0x30, D_80071E4D + (c[0x1D] * 0x24), c + 0x60);
}

void func_801D0D28(s32 arg0, s32 arg1) {
    s16 rect[4];
    s32 i;
    s32 o;
    s32 sx;
    s32 o1;
    s32 o2;
    s32 o3;
    s32 o4;
    s32 o5;
    s32 o6;
    s32 id;
    s32 A;
    s32 B;
    s32 v;
    u32 g;
    u32 gr;
    s32 e;
    s32 f;
    s32 a;
    s32 b;
    s32 d;
    s32 h;
    u8 c;

    c = D_8009CBDC[D_801D1E1C];
    for (i = 0; i < 6; i++) {
        func_80026F44(arg0, arg1 + i * 0xC - 2, D_801D1C7A + i * 0xF, 5);
    }
    o1 = D_801D1E1C * 0x440;
    func_80028E00(arg0 + 0x4A, arg1, D_8009D84E[o1], 5, 7);
    o2 = D_801D1E1C * 0x440;
    func_80028E00(arg0 + 0x4A, arg1 + 0xC, D_8009D84E[4 + o2], 5, 7);
    o3 = D_801D1E1C * 0x440;
    func_80028E00(arg0 + 0x4A, arg1 + 0x18, D_8009D84E[1 + o3], 5, 7);
    o4 = D_801D1E1C * 0x440;
    func_80028E00(arg0 + 0x4A, arg1 + 0x24, D_8009D84E[2 + o4], 5, 7);
    o5 = D_801D1E1C * 0x440;
    func_80028E00(arg0 + 0x4A, arg1 + 0x30, D_8009D84E[3 + o5], 5, 7);
    o6 = D_801D1E1C * 0x440;
    func_80028E00(arg0 + 0x4A, arg1 + 0x3C, D_8009D84E[5 + o6], 5, 7);
    arg1 += 0x4D;
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x3F, (s32)rect);
    for (i = 0; i < 7; i++) {
        func_80026F44(arg0, arg1 + i * 0xC - 2, D_801D1CD4 + i * 0xF, 5);
    }
    sx = arg0 + 0x4A;
    o = D_801D1E1C * 0x440;
    id = D_800491D0[c];
    a = *(u16 *)(D_8009D84E + 6 + o);
    b = *(u16 *)(D_8009D84E + 8 + o);
    gr = D_8009D84E[4 + o];
    d = *(u16 *)(D_8009D84E + 0xA + o);
    h = *(u16 *)(D_8009D84E + 0xC + o);
    A = D_8009C738[id][0x1C];
    B = D_8009C738[id][0x1D];
    e = D_800738A8[A * 0x2C];
    v = B * 0x24;
    g = (gr >> 2) + D_80071E48[v];
    f = D_80071E48[v + 1];
    func_80028E00(sx, arg1, a, 5, 7);
    func_80028E00(sx, arg1 + 0xC, e, 5, 7);
    func_80028E00(sx, arg1 + 0x18, b, 5, 7);
    func_80028E00(sx, arg1 + 0x24, g, 5, 7);
    func_80028E00(sx, arg1 + 0x30, d, 5, 7);
    func_80028E00(sx, arg1 + 0x3C, h, 5, 7);
    func_80028E00(sx, arg1 + 0x48, f, 5, 7);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x3F, (s32)rect);
}

void func_801D116C(s32 arg0) {
    s16 rect[4];
    s32 id;
    s32 id2;
    u8 r;
    u8 g;
    u8 b;
    s32 k;
    s32 v;
    s32 o;

    id = D_800491D0[D_8009CBDC[D_801D1E1C]];
    id2 = id;
    if (D_8009C747[id * 0x84] == 0xFF) {
        k = ((arg0 >> 1) & 7) * 3;
        r = D_801D1DCC[k];
        g = D_801D1DCD[k];
        b = D_801D1DCE[k];
    } else {
        v = D_8009C757[id * 0x84];
        if (v & 0x10) {
            r = D_801D1DCC[0];
            g = D_801D1DCD[0];
            b = D_801D1DCE[0];
        } else {
            r = 0x80;
            if (v & 0x20) {
                r = D_801D1DD2;
                g = D_801D1DD3;
                b = D_801D1DD4;
            } else {
                g = 0x20;
                b = 0x50;
            }
        }
    }
    v = D_8009C747[id2 * 0x84] * 0x3D / 256;
    func_800285AC(0xFD, 0x33, v, 6, r, g, b);
    func_80026F44(0x94, 0xB, ((s32 (*)(s32, s32, s32))func_80015248)(8, 9, 8), 7);
    func_80026F44(0x94, 0x24, ((s32 (*)(s32, s32, s32))func_80015248)(8, 0x2C, 8), 7);
    func_80026F44(0x94, 0x30, D_801D1D6A, 7);

    o = id * 0x84;
    func_800285AC(0xCE, 0x1B, D_8009C759[o], 6, 0x80, 0x20, 0x20);
    func_80028CA0(0xCD, 0x1A, 0x88, 8, 0x40, 8, 7, 0);
    func_80028CA0(0x10A, 0xD, 0xF8, 8, 8, 8, 7, 0);
    func_80028CA0(0x132, 0x26, 0xF8, 8, 8, 8, 7, 0);
    func_80028E00(0xC4, 0xD, *(s32 *)((u8 *)D_8009C774 + o), 0xA, 7);
    func_80028E00(0xEC, 0x26, *(s32 *)((u8 *)D_8009C7B8 + o), 0xA, 7);
    func_80028E00(0xD4, 0x32, D_8009C746[o], 1, 7);
    func_80028CA0(0xFC, 0x32, 0x88, 8, 0x40, 8, 7, 0);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x3F, (s32)rect);
}

INCLUDE_ASM("../asm/us/statmenu/nonmatchings/text", func_801D14E0);

void func_801D167C(s32 arg0) {
    u8 pad[8];
    s16 rect[4];
    s32 i;

    func_800230C4(D_80062F58);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x7F, (s32)rect);
    func_801D0114();
    if (D_801D1968 == 0) {
        func_801D14E0(0xB2, 0x45);
        func_801D0B74(0xAA, 0x8D);
        func_801D0D28(0x24, 0x3D);
        func_801D116C(arg0);
    } else if (D_801D1968 >= 0) {
        if (D_801D1968 < 3) {
            func_801D053C(0x26, 0x4D);
            func_801D116C(arg0);
        }
    }
    for (i = 0; i < 1; i++) {
        func_8001E040(D_801D1D7C + i * 8);
    }
    if (func_80023050() == 0) {
        switch (D_801D1968) {
        case 0:
            if (D_80062D7C & 0x20) {
                func_801D0000(1);
                D_801D1968 = 1;
            } else if (D_80062D7E & 0x40) {
                func_801D0000(4);
                func_8002305C(5, 0);
                func_8002120C(0);
            }
            break;
        case 1:
            if (D_80062D7C & 0x20) {
                func_801D0000(1);
                D_801D1968 = 2;
            } else if (D_80062D7E & 0x40) {
                func_801D0000(4);
                func_8002305C(5, 0);
                func_8002120C(0);
            }
            break;
        case 2:
            if (D_80062D7C & 0x20) {
                func_801D0000(1);
                D_801D1968 = 0;
            } else if (D_80062D7E & 0x40) {
                func_801D0000(4);
                func_8002305C(5, 0);
                func_8002120C(0);
            }
            break;
        }
        if (D_80062D7E & 4) {
            func_801D0000(1);
            do {
                D_801D1E1C--;
                if (D_801D1E1C < 0) {
                    D_801D1E1C = 2;
                }
            } while (D_8009CBDC[D_801D1E1C] == 0xFF);
            return;
        }
        if (D_80062D7E & 8) {
            func_801D0000(1);
            do {
                D_801D1E1C++;
                if (D_801D1E1C >= 3) {
                    D_801D1E1C = 0;
                }
            } while (D_8009CBDC[D_801D1E1C] == 0xFF);
        }
    }
}

void func_801D1960(void) {
}
