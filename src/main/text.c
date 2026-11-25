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
void func_80012A8C(s8 arg0);
extern u8 D_8009ABF5[];
extern s32 D_8009A004;
extern u8 D_8009AC2F;
extern u8 D_8009D2A2[];
extern u8 D_8009D2A3;
extern s16 D_8009AC1A;
extern volatile u8 D_80071E34;
extern volatile u8 D_80071E30;
extern s32 D_800E48E0;

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

void func_8001155C(void) {
    switch (*((volatile s16 *)(&D_80095DD4))) {
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
    if ((D_80062D98 == 0) && (D_80062D99 == 0)) {
        D_8009D26C[0] += 0x444;
        if ((D_8009D26C[0] >> 16) != 0) {
            ++D_8009D264;
            D_8009D26C[0] &= 0xFFFF;
        }
        D_8009D270 += 0x444;
        if ((D_8009D270 >> 16) != 0) {
            if (!(D_8009D2E7 & 2)) {
                if (D_8009D268 != 0) {
                    --D_8009D268;
                }
            } else {
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

INCLUDE_RODATA("../asm/us/main/nonmatchings/text", D_80010014);

INCLUDE_RODATA("../asm/us/main/nonmatchings/text", D_80010020);

void func_80011C1C(void) {
    MnB9 name;
    MnB8 rect;
    u8 *s2;
    u8 *s3;
    u8 *s4;
    u32 c;
    u8 b;
    s32 tA;
    s32 tB;
    s32 tC;
    s32 tD;
    s32 tE;
    volatile u8 *s6;
    s32 v;
    u32 uv;
    u32 hi;

    func_800110B8();
    name = D_80010014;
    rect = D_80010020;
    func_800429D0(8);
    func_8001171C();
    func_80033B70();
    s6 = (volatile u8 *)D_8009D588;
    func_80033F40(D_80048D54, D_80048D58, 0x800A0000, 0);
    s2 = (u8 *)s6 - 0x2E8;
    func_800A0030();
    func_800148B4();
    for (;;) {
        c = (u32)&D_8009AC30[1];
        *(s16 *)c = 0;
        D_8009AC2F = 0;
        func_800148A0();
        func_80011938();
        func_8001C434();
        func_80033F40(D_80048D54, D_80048D58, 0x800A0000, 0);
        func_800A04C4(0);
        D_8009A000.a = 0xC0;
        D_8009A004 = 0x7F;
        func_8002DA7C();
        func_80043F6C(&rect, 0, 0, 0);
        func_80026258();
        func_80011920();
        func_80033A90();
        if (((s32 (*)(void))func_80024E5C)() == 1) {
            func_80014934();
            func_80026258();
            func_80033A90();
            func_80011BB4();
        }
        s3 = (u8 *)(c - 0x3D);
        s4 = (u8 *)(c - 0x3C);
        func_80026090();
        for (;;) {
            b = s6[0];
            if (b != ((s32 (*)(void))func_800343F0)()) {
                func_80033F40(D_80048D4C, D_80048D50, 0x800A0000, 0);
                if (func_800A0000(s6[0]) == 1) {
                    goto stub;
                }
            }
            func_80011784();
            D_8007EBC8 = 0;
            D_8009C6D8 = 0;
            D_8007173C = 0;
            func_80011AEC();
            D_800965EC = 0;
            do {
                switch (D_8009C560) {
                case 1:
                    func_80011860();
                    break;
                case 2:
                case 4:
                    s2[0]++;
                    if (s2[0] == 0) {
                        s2[1]++;
                    }
                    if (D_80071E34 == 1) {
                        func_800260DC();
                        func_80026090();
                        D_80071E34 = 0;
                    }
                    if (D_800965EC == 1) {
                        if (D_80071E30 == 0) {
                            v = D_8009AC38;
                            if (v != 0) {
                                D_8009A000.a = 0x14;
                                D_8009A004 = v;
                                func_8002DA7C();
                            }
                            D_800722C8 = 0x801C0000;
                            D_80071744 = D_80048D24;
                            D_80095DD8 = D_80048D28;
                            ((void (*)(void))func_800111E4)();
                            if (D_800707BE[0] & 8) {
                                s2[2]++;
                                if (s2[2] == 0) {
                                    s2[3]++;
                                }
                            }
                        }
                        if (D_800707BE[0] & 1) {
                            if (D_8009AC31 == 0) {
                                D_8009ABF5[0] = 0x1A;
                                D_800707BE[0] = 0;
                            }
                        }
                        tA = 2;
                        D_800965EC = tA;
                        D_8009C560 = 1;
                        break;
                    }
                    if (D_80095DDC < 0) {
                        D_800716D0 = 4;
                    } else {
                        D_800716D0 = 0;
                    }
                    if (D_80095DDC & 0x20000000) {
                        D_800716D0 |= 2;
                    }
                    D_800722C8 = 0x801C0000;
                    *(u16 *)s4 = D_80095DDC;
                    D_80071744 = D_80048D2C;
                    D_80095DD8 = D_80048D30;
                    ((void (*)(void))func_800111E4)();
                    if (D_800707BE[0] & 8) {
                        D_8009D2A2[0]++;
                        if (D_8009D2A2[0] == 0) {
                            D_8009D2A3++;
                        }
                    } else if ((D_800707BE[0] & 1) || (D_8009D25C[3] == 0 && (D_80095DDC & 0x20000000))) {
                        D_800707BE[0] = 0;
                        s4[-1] = 0x1A;
                    } else if (D_80095DDC & 0x40000000) {
                        while (D_80095DD4 != 0) {
                        }
                        D_800965EC = 1;
                        D_8009C560 = 1;
                        break;
                    }
                    tA = 2;
                    D_800965EC = tA;
                    D_8009C560 = 3;
                    break;
                case 3:
                    func_800119E4();
                    func_800112E8();
                    v = D_80071E28;
                    switch (v) {
                    case 1:
                        D_800965EC = 3;
                        tB = 2;
                        D_8009C560 = tB;
                        break;
                    case 0:
                        D_800965EC = 3;
                        D_8009C560 = 1;
                        break;
                    case 2:
                        D_8009ABF5[0] = 0xA;
                        break;
                    }
                    break;
                case 16:
                    func_80011274();
                    tC = 2;
                    D_8009AC1A = tC;
                    D_800965EC = 0x10;
                    D_8009C560 = 1;
                    break;
                case 5:
                    while (D_80095DD4 != 0) {
                    }
                    while (func_80043DD8(1) != 0) {
                    }
                    func_800119E4();
                    if (D_80071E34 == 1) {
                        func_800260DC();
                        func_80026090();
                        D_80071E34 = 0;
                    }
                    switch (D_8009ABF5[0]) {
                    case 6:
                        func_80024D88(*(s16 *)&D_8009ABF6);
                        break;
                    case 7:
                        func_80024DD4(*(s16 *)&D_8009ABF6);
                        func_800260DC();
                        func_80026090();
                        break;
                    case 8:
                        func_80024E18(*(s16 *)&D_8009ABF6);
                        break;
                    case 9:
                        if (*(s16 *)s4 == 1) {
                            func_80024A3C(D_800E48E0);
                        } else {
                            func_80024A3C(0);
                            s4[-1] = 0;
                        }
                        break;
                    case 14:
                        func_80024E94();
                        break;
                    case 18:
                        func_80024FC4(*(s16 *)&D_8009ABF6);
                        break;
                    case 19:
                        func_80024F80(*(s16 *)&D_8009ABF6);
                        break;
                    }
                    func_800CF60C();
                    tC = 2;
                    D_8009AC1A = tC;
                    D_800965EC = 5;
                    D_8009C560 = 1;
                    break;
                case 13:
                    func_800119E4();
                    switch (D_8009ABF5[0]) {
                    case 15:
                        func_80024ECC();
                        break;
                    case 16:
                        func_80024F04();
                        break;
                    case 17:
                        func_80024F3C(*(s16 *)&D_8009ABF6);
                        break;
                    case 21:
                        func_800250B4();
                        break;
                    case 22:
                        func_800250EC(*(s16 *)&D_8009ABF6);
                        break;
                    case 23:
                        func_80025130(*(s16 *)&D_8009ABF6);
                        break;
                    case 24:
                        func_80025040();
                        break;
                    }
                    if (*s3 != 0x19) {
                        func_800CF60C();
                    }
                    tD = 2;
                    *(s16 *)(s3 + 0x25) = tD;
                    D_800965EC = 0xD;
                    D_8009C560 = 1;
                    break;
                case 12:
                    b = s6[0];
                    c = b;
                    if (c == ((s32 (*)(void))func_800343F0)()) {
                        func_80011784();
                        tE = 2;
                        D_8009AC1A = tE;
                        D_800965EC = 0xC;
                        D_8009C560 = 1;
                        break;
                    }
                    func_80033F40(D_80048D4C, D_80048D50, 0x800A0000, 0);
                    if (func_800A0000(s6[0]) == 1) {
                        D_8009ABF5[0] = 0xA;
                    } else {
                        func_80011784();
                        tE = 2;
                        D_8009AC1A = tE;
                        D_800965EC = 0xC;
                        D_8009C560 = 1;
                    }
                    break;
                case 6:
                    func_80033E34(D_80048D74, D_80048D78, 0x80180000, 0);
                    do {
                    } while (func_80034B44() != 0);
                    func_80015CA0(0x80180000, 0x800A0000);
                    func_800A00D0();
                    D_800965EC = 6;
                    D_8009C560 = 1;
                    D_8009ABF5[0] = 1;
                    break;
                case 7:
                    func_80033E34(D_80048D5C, D_80048D60, 0x80180000, 0);
                    do {
                    } while (func_80034B44() != 0);
                    func_80015CA0(0x80180000, 0x800A0000);
                    func_800A02D0();
                    D_800965EC = 7;
                    D_8009C560 = 1;
                    D_8009ABF5[0] = 1;
                    break;
                case 8:
                    func_80033E34(D_80048D3C, D_80048D40, 0x80180000, 0);
                    do {
                    } while (func_80034B44() != 0);
                    func_80015CA0(0x80180000, 0x800A0000);
                    func_800A0390();
                    D_800965EC = 8;
                    D_8009C560 = 1;
                    D_8009ABF5[0] = 1;
                    break;
                case 14:
                    func_80033E34(D_80048D44, D_80048D48, 0x80180000, 0);
                    do {
                    } while (func_80034B44() != 0);
                    func_80015CA0(0x80180000, 0x800A0000);
                    func_800A0448();
                    D_800965EC = 0xE;
                    D_8009C560 = 1;
                    D_8009ABF5[0] = 1;
                    break;
                case 9:
                    func_80033E34(D_80048D34, D_80048D38, 0x80180000, 0);
                    do {
                    } while (func_80034B44() != 0);
                    func_80015CA0(0x80180000, 0x800A0000);
                    func_800B6B58();
                    D_800965EC = 9;
                    D_8009C560 = 1;
                    D_8009ABF5[0] = 1;
                    break;
                case 11:
                    func_80033E34(D_80048D64, D_80048D68, 0x80180000, 0);
                    do {
                    } while (func_80034B44() != 0);
                    func_80015CA0(0x80180000, 0x800A0000);
                    uv = func_800A0450();
                    hi = uv >> 8;
                    do {
                        D_8009D3EA[0] = uv;
                    } while (0);
                    D_8009D3EB = hi;
                    D_800965EC = 0xB;
                    D_8009C560 = 1;
                    D_8009ABF5[0] = 1;
                    break;
                case 10:
                    func_80033E34(D_80048D6C, D_80048D70, 0x80180000, 0);
                    do {
                    } while (func_80034B44() != 0);
                    func_80015CA0(0x80180000, 0x800A0000);
                    uv = func_800A00BC(D_8009D5E5[0]);
                    D_8009D5E6 = uv;
                    D_8009D5E7 = uv >> 8;
                    D_800965EC = 0xA;
                    D_8009C560 = 1;
                    D_8009ABF5[0] = 1;
                    break;
                }
            } while (*s3 != 5 && *s3 != 0x1A && *s3 != 0xA);
            if (*s3 == 5) {
                goto h5;
            }
            if (*s3 == 0x1A) {
                goto h1a;
            }
            if (*s3 == 0xA) {
                *s3 = 0;
                break;
            }
        }
        goto tail;
h1a:
        *s3 = 0;
        func_8002DA7C();
        func_80033F40(D_80048D4C, D_80048D50, 0x800A0000, 0);
        func_800A0C58();
        D_8009A000.a = 0xC0;
        D_8009A004 = 0x7F;
        func_8002DA7C();
        goto tail;
h5:
        func_80033F40(D_80048D54, D_80048D58, 0x800A0000, 0);
        func_800A04C4(1);
        goto tail;
stub:
        D_8009ABF5[0] = 0;
tail:
        func_80033BE0();
        func_800299C8();
    }
}

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

void func_80012A8C(s8 arg0) {
    u8 *b;

    func_80044244(&D_8007E7A0[(s16) D_80075DEC * 4], 1);
    b = D_8009A074;
    ((Tile16 *) (D_8009A074 + (s16) D_80075DEC * 0x30))->r0 = arg0;
    ((Tile16 *) (D_8009A074 + (s16) D_80075DEC * 0x30))->g0 = arg0;
    ((Tile16 *) (D_8009A074 + (s16) D_80075DEC * 0x30))->b0 = arg0;
    ((Tile16 *) (D_8009A074 + 0x10 + (s16) D_80075DEC * 0x30))->r0 = arg0;
    ((Tile16 *) (D_8009A074 + 0x10 + (s16) D_80075DEC * 0x30))->g0 = arg0;
    ((Tile16 *) (D_8009A074 + 0x10 + (s16) D_80075DEC * 0x30))->b0 = arg0;
    ((MainTag *) (D_8009A074 + (s16) D_80075DEC * 0x30))->addr = ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr;
    ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr = (u32) (D_8009A074 + (s16) D_80075DEC * 0x30);
    ((MainTag *) (D_8009A074 + 0x10 + (s16) D_80075DEC * 0x30))->addr = ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr;
    ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr = (u32) (b + (s16) D_80075DEC * 0x30 + 0x10);
    ((MainTag *) (D_8009A074 - 0xC + (s16) D_80075DEC * 0x30))->addr = ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr;
    ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr = (u32) (D_8009A074 - 0xC + (s16) D_80075DEC * 0x30);
}

void func_80012DB0(s16 arg0, s16 arg1, s16 arg2) {
    u8 *b;

    func_80044244(&D_8007E7A0[(s16) D_80075DEC * 4], 1);
    b = D_8009A074;
    ((Tile16 *) (D_8009A074 + (s16) D_80075DEC * 0x30))->r0 = (s16) *(volatile u16 *) (D_8009AC2B + 0x17) * arg0 / 256;
    ((Tile16 *) (D_8009A074 + (s16) D_80075DEC * 0x30))->g0 = (s16) *(volatile u16 *) (D_8009AC2B + 0x17) * arg1 / 256;
    ((Tile16 *) (D_8009A074 + (s16) D_80075DEC * 0x30))->b0 = (s16) *(volatile u16 *) (D_8009AC2B + 0x17) * arg2 / 256;
    ((Tile16 *) (D_8009A074 + 0x10 + (s16) D_80075DEC * 0x30))->r0 = (s16) *(volatile u16 *) (D_8009AC2B + 0x17) * arg0 / 256;
    ((Tile16 *) (D_8009A074 + 0x10 + (s16) D_80075DEC * 0x30))->g0 = (s16) *(volatile u16 *) (D_8009AC2B + 0x17) * arg1 / 256;
    ((Tile16 *) (D_8009A074 + 0x10 + (s16) D_80075DEC * 0x30))->b0 = (s16) *(volatile u16 *) (D_8009AC2B + 0x17) * arg2 / 256;
    ((MainTag *) (D_8009A074 + (s16) D_80075DEC * 0x30))->addr = ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr;
    ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr = (u32) (D_8009A074 + (s16) D_80075DEC * 0x30);
    ((MainTag *) (D_8009A074 + 0x10 + (s16) D_80075DEC * 0x30))->addr = ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr;
    ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr = (u32) (b + (s16) D_80075DEC * 0x30 + 0x10);
    ((MainTag *) (D_8009A074 - 0xC + (s16) D_80075DEC * 0x30))->addr = ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr;
    ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr = (u32) (D_8009A074 - 0xC + (s16) D_80075DEC * 0x30);
}

void func_800131B8(s16 arg0, s16 arg1, s16 arg2) {
    u8 *b;

    func_80044244(&D_8007E7A0[(s16) D_80075DEC * 4], 1);
    b = D_8009A074;
    ((Tile16 *) (D_8009A074 + (s16) D_80075DEC * 0x30))->r0 = arg0;
    ((Tile16 *) (D_8009A074 + (s16) D_80075DEC * 0x30))->g0 = arg1;
    ((Tile16 *) (D_8009A074 + (s16) D_80075DEC * 0x30))->b0 = arg2;
    ((Tile16 *) (D_8009A074 + 0x10 + (s16) D_80075DEC * 0x30))->r0 = arg0;
    ((Tile16 *) (D_8009A074 + 0x10 + (s16) D_80075DEC * 0x30))->g0 = arg1;
    ((Tile16 *) (D_8009A074 + 0x10 + (s16) D_80075DEC * 0x30))->b0 = arg2;
    ((MainTag *) (D_8009A074 + (s16) D_80075DEC * 0x30))->addr = ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr;
    ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr = (u32) (D_8009A074 + (s16) D_80075DEC * 0x30);
    ((MainTag *) (D_8009A074 + 0x10 + (s16) D_80075DEC * 0x30))->addr = ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr;
    ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr = (u32) (b + (s16) D_80075DEC * 0x30 + 0x10);
    ((MainTag *) (D_8009A074 - 0xC + (s16) D_80075DEC * 0x30))->addr = ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr;
    ((MainTag *) (D_8007E7A0 + (s16) D_80075DEC * 4))->addr = (u32) (D_8009A074 - 0xC + (s16) D_80075DEC * 0x30);
}

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
