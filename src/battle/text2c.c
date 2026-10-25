#include "common.h"
#include "battle/decls.h"

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800D93E4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800D9BF4);

u8 func_800D9DEC(s16 arg0) {
    return D_800F514C[arg0];
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800D9E0C);

void func_800D9F5C(s16 arg0) {
    D_800F514C[arg0] = 3;
}

void func_800D9F80(void) {
    D_800F311C = 0;
    D_800FAFEC = -0x100;
    D_800FAFF0 = -0x100;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800D9FA4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DA380);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DB818);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DBC18);

void func_800DBEA4(s32 arg0, s16 arg1) {
    func_800DBC18(arg0, arg1);
}

void func_800DBEC8(s32 arg0) {
    if (D_800F3896 == 0) {
        func_800DBEA4(arg0, (s16) D_800F38A9);
        return;
    }
    if ((D_800F3120 != 0) && ((u32) D_800FAFEC < 0x128U) && ((u32) (D_800FAFF0 - 0x10) < 0x96U)) {
        func_800DB818(arg0, D_800FAFEC, D_800FAFF0);
    }
}

void func_800DBF54(void) {
    func_800269C0((s32) &D_80077F64);
}

void func_800DBF7C(void) {
    D_800F3122 = 0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DBF8C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DC0CC);

void func_800DCF58(void) {
}

void func_800DCF60(s16 arg0, s16 arg1) {
    D_800F3138 = 1;
    D_800F313C = (s32) arg0;
    D_800F3140 = (s32) arg1;
}

void func_800DCF94(s16 arg0) {
    if (arg0 == -1) {
        D_800F1E4F = 0;
        return;
    }
    D_800F1E4F = 1;
    D_800F1E50 = arg0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DCFD4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DD690);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DD85C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DDAD8);

void func_800DDC34(u8 *arg0, s16 arg1) {
    func_800DD85C(arg0 + D_800F5628 * 0x14, arg1);
    func_800DDAD8(arg0 + (D_800F5628 * 0x14 + 8), arg1);
    func_800DD690(arg0 + (D_800F5628 * 0x14 + 0x10), arg1);
    D_800F5628++;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DDCE8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DDE90);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DDFEC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DE2B4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DE3CC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DE46C);

void func_800DE5D8(void) {
}

void func_800DE5E0(void) {
}

void func_800DE5E8(void) {
}

void func_800DE5F0(void) {
}

void func_800DE5F8(void) {
}

void func_800DE600(void) {
}

void func_800DE608(void) {
}

void func_800DE610(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DE618);

void func_800DE910(void) {
}

void func_800DE918(void) {
    D_80151840 = *D_8009D260;
    if ((u32) *D_8009D260 > 0x927C0U) {
        D_80151840 = 0x927C0;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DE94C);

void func_800DEB10(void) {
}

void func_800DEB18(void) {
    s16 c;
    s16 idx;
    BtlX240 *p;

    D_800F977C = 0;
    func_800A4F60(D_800F38A0, 0);
    c = D_8009D86D[D_800F38A0].b[0];
    idx = c;
    D_800F1EF0 = D_800F3163[idx];
    D_800F1F02 = D_800F3163[idx];
    p = &D_800F90B4[D_800F38A0];
    if (D_800F57CC == 0) {
        p->bA = 0;
        p->bB = 0;
        p->w0 = 0;
        p->w2 = 0;
    }
    p->bD = 4;
    p->w6 = 4;
    p->bC = c;
    p->w4 = c;
    p->b10 = 0;
    p->b11 = 1;
    p->bE = 0;
    p->bF = 0;
    p->w8 = 0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DEC10);

void func_800DF244(void) {
}

void func_800DF24C(void) {
    T240 *p;

    p = &D_800F90C6[D_800F38A0];
    if (D_800F57CC == 0) {
        p->xA = 0;
        p->xB = 0;
        p->x0 = 0;
        p->x2 = 0;
    }
    p->xC = 1;
    p->xD = 3;
    *(s16 *)((u8 *)p + 4) = 1;
    p->x6 = D_80166F74 * 2;
    p->x10 = 2;
    p->x11 = 0;
    p->xE = 0;
    p->xF = 0;
    p->x8 = 0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DF2CC);

void func_800DF528(void) {
}

void func_800DF530(void) {
    T240 *p;
    p = &D_800F90D8[D_800F38A0];
    if (D_800F57CC == 0) {
        p->xA = 0;
        p->xB = 0;
        p->x0 = 0;
        p->x2 = 0;
    }
    p->xC = 3;
    p->xD = 3;
    p->x4 = 3;
    p->x6 = 0x12;
    p->x10 = 2;
    p->x11 = 0;
    p->xE = 0;
    p->xF = 0;
    p->x8 = 0;
    func_800A4F60(D_800F38A0, 1);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DF5C8);

void func_800DF7BC(void) {
}

void func_800DF7C4(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DF7CC);

void func_800DF8F0(void) {
}

void func_800DF8F8(void) {
}

void func_800DF900(void) {
    if (D_800F3896 == 3 && D_800F99E4 == 0) {
        if (D_80062D7E & 0x20) {
            func_800BB9B8(1);
            D_800F99E4 = 1;
            D_800F3896 = -1;
            func_800A4350(D_800F38A0, D_800F389C, D_800F389E, D_801516F8);
            func_800D9F5C(3);
            func_800D9F5C(1);
        } else if (D_80062D7E & 0x8040) {
            func_800BB9B8(4);
            D_800F99E4 = 1;
            D_800F3896 = 1;
            func_800D9F5C(3);
        }
    }
}

void func_800DF9F0(void) {
}

void func_800DF9F8(void) {
    T240 *p;

    p = &D_800F90EA[D_800F38A0];
    if (D_800F57CC == 0) {
        p->xA = 0;
        p->xB = 0;
        p->x0 = 0;
        p->x2 = 0;
    }
    p->xC = 1;
    p->xD = 3;
    p->x4 = 1;
    p->x6 = 0x10;
    p->x10 = 2;
    p->x11 = 0;
    p->xE = 0;
    p->xF = 0;
    p->x8 = 0;
    func_800A4F60(D_800F38A0, 2);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DFA94);

void func_800DFC38(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DFC40);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DFE34);

void func_800DFFDC(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DFFE4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E010C);

void func_800E026C(void) {
}

void func_800E0274(void) {
    func_800E53C8();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E0294);

void func_800E03C8(void) {
}

void func_800E03D0(void) {
    func_800E4B88();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E03F0);

void func_800E0528(void) {
}

void func_800E0530(void) {
    s32 i;

    func_80026448(D_800F9132, 0, 0, 2, 1, 0, 0, 2, 1, 0, 0, 1, 0, 0);
    for (i = 1; i < 28; i++) {
        if (D_800F514C[i] != 0) {
            func_800D9F5C(i);
        }
    }
    D_800F57D4 = 5;
    func_800E58CC();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E05E4);

void func_800E078C(void) {
}

void func_800E0794(void) {
    s32 i;

    func_80026448(&D_800F9144, 0, 0, 2, 1, 0, 0, 2, 1, 0, 0, 1, 0, 0);
    for (i = 1; i < 32; i++) {
        if (i != 9 && D_800F514C[i] != 0) {
            func_800D9F5C(i);
        }
    }
}

void func_800E084C(void) {
    if (D_800F3896 == 9) {
        func_800264A8(&D_800F9144);
        if (D_80062D7C & 0x20) {
            if (D_800F914E == 0) {
                func_800A4844(1);
            } else {
                func_800A4844(0);
            }
            func_800D9F5C(9);
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E08C4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E0BE0);

void func_800E0DF4(void) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        D_800F514C[i] = 0;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E0E34);

s32 func_800E15D8(void) {
    volatile u16 *p;
    volatile u32 *q;
    s32 r;
    u16 t;

    q = &D_8009D264;
    D_80062DFD = 1;
    D_80163604 = 0;
    D_801635F8 = 0;
    D_80163600 = *q & 0x7F;
    func_800E1C40();
    p = &D_80163762;
    t = *p;
    D_800F3110 = 1;
    D_800F3896 = -1;
    D_800F3150 = t;
    func_800E0DF4();
    if (D_800F3110 != 0) {
        D_800F3110 = 0;
    }
    D_80062D98 = 0;
    D_80062D99 = 0;
    t = *p;
    r = (D_8009D7BE >> 4) & 3;
    D_800F198C = t;
    D_800F57CC = r;
    return r;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E16B8);

void func_800E1938(s16 arg0, s16 arg1, s32 arg2) {
    u32 t;
    s32 u;
    s32 v;

    if (arg2 < 0x80) {
        t = 0;
    } else if (arg2 < 0x100) {
        arg2 -= 0x80;
        if (arg2 < 0x10) {
            t = 1;
        } else if (arg2 < 0x20) {
            t = 3;
        } else if (arg2 < 0x30) {
            t = 2;
        } else if (arg2 < 0x3E) {
            t = 5;
        } else if (arg2 < 0x49) {
            t = 4;
        } else if (arg2 < 0x57) {
            t = 9;
        } else if (arg2 < 0x65) {
            t = 6;
        } else if (arg2 < 0x72) {
            t = 7;
        } else {
            t = 8;
        }
    } else if (arg2 < 0x120) {
        t = 0xA;
    } else {
        t = 0xB;
    }
    u = (t & 1) * 0x10 | 0x60;
    v = (t >> 1) * 0x10 + 0x70;
    func_80028CA0(arg0, arg1, u, v, 0x10, 0x10, 1, 0);
}

s32 func_800E1A2C(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_8009CBDC[i] == 0) {
            return D_8009D85C[i].hp * 0xFFFF / D_8009D85E[i].hp;
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E1AC0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E1C40);

void func_800E2054(s32 arg0, s32 arg1) {
    ((void (*)()) func_80027354)(0xB0, arg0, D_800F3184[arg1], 3);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E2098);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E2C6C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E3088);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E33A0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E368C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E3B64);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E3E10);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E3FB4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E4180);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E4394);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800E4A64);

void func_800E4B88(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v1 = 2;
    var_v0 = &D_800F33A2;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
    D_800F5760 = 0xA;
    D_800F33AA = 0;
    D_800F5764 = 2;
}

s32 func_800E4BCC(void) {
    if (D_800F33A0 == 0) {
        return 0;
    }
    if (D_800F33AA == 3) {
        return 2;
    }
    return 1;
}
