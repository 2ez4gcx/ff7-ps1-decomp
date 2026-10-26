#include "common.h"
#include "battle/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
M2C_UNK func_800E53C8();

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800D93E4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800D9BF4);

u8 func_800D9DEC(s16 arg0) {
    return D_800F514C[arg0];
}

s32 func_800D9E0C(s16 arg0, s16 arg1, s16 arg2) {
    D_800F514C[arg2] = 1;
    if (arg0 != -1 && arg1 != -1) {
        D_800F1E54[arg2].x = arg0;
        D_800F1E54[arg2].y = arg1;
    }
    D_800F1E54[arg2].f1 = 1;
    D_800F1E54[arg2].f2 = 1;
    D_800F1E54[arg2].hw = (s16)D_800F1E54[arg2].w / 2;
    D_800F1E54[arg2].hh = (s16)D_800F1E54[arg2].h / 2;
    return D_800F2F8C[arg2]();
}

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

void func_800DBF8C(s32 arg0) {
    u8 n;
    u8 first;
    s32 i;
    s32 q;

    n = 0;
    first = 1;
    for (i = 0; i < 5; i++) {
        q = arg0 / D_800F3124[i];
        if (q == 0) {
            if (first == 0) {
                D_800F55D8[n++] = 0x10;
            }
        } else {
            first = 0;
            D_800F55D8[n++] = q + 0x10;
        }
        arg0 = arg0 % D_800F3124[i];
    }
    D_800F55D8[n++] = 0x10;
    for (i = 0; i < 5; i++) {
        D_800F55D8[n++] = D_800492FC[i];
    }
}

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

void func_800DDAD8(void *arg0, s16 arg1) {
    BtlRect sp18;
    BtlRect sp20;
    s16 i;
    s32 o;
    s32 k;
    u16 xa;
    u16 xb;
    u16 xc;
    u16 xd;

    func_80026A00((s32)arg0);
    sp20.x = 0;
    sp20.y = 0;
    sp20.w = 0xFF;
    sp20.h = 0xFF;
    func_80026A34(0, 1, func_8004656C(0, 1, 0x3C0, 0x100) & 0xFFFF, (s32)&sp20);
    if (*(s16 *)(D_800F1E64 + arg1 * 0x98) > 0) {
        i = 0;
        o = arg1 * 0x98;
        do {
            k = (i << 3) + o;
            xa = *(volatile u16 *)(D_800F1E64 + 2 + k);
            xb = *(volatile u16 *)(D_800F1E64 + 4 + k);
            xc = *(volatile u16 *)(D_800F1E64 + 6 + k);
            xd = *(volatile u16 *)(D_800F1E64 + 8 + k);
            func_8001DE0C(&sp18, (s16)xa, (s16)xb, (s16)(xc - xa), (s16)(xd - xb));
            func_8001E040(&sp18);
            i++;
        } while (i < *(s16 *)(D_800F1E64 + o));
    }
}

void func_800DDC34(u8 *arg0, s16 arg1) {
    func_800DD85C(arg0 + D_800F5628 * 0x14, arg1);
    func_800DDAD8(arg0 + (D_800F5628 * 0x14 + 8), arg1);
    func_800DD690(arg0 + (D_800F5628 * 0x14 + 0x10), arg1);
    D_800F5628++;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DDCE8);

void func_800DDE90(u8 *arg0) {
    s16 i;

    if (D_80062D99 != 0) {
        func_800DDCE8();
    }
    if (D_800F514D != 0) {
        if (D_8009CBDC[D_800F38A0] == 0xFF) {
            for (i = 1; i < 0x20; i++) {
                if (D_800F514C[i] != 0) {
                    func_800D9F5C(i);
                }
            }
        }
    }
    D_800F5628 = 0;
    for (i = 0; i < 0x20; i++) {
        if (i == 0 || (D_800F514C[i] != 0 && !(D_80062D78 & 0x80))) {
            if (D_800F514C[i] != 0) {
                func_800DDC34(arg0, i);
            }
        }
    }
    func_800D93E4(arg0);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DDFEC);

void func_800DE2B4(void) {
    u8 n0;
    u16 n3;
    u16 n4;
    u16 n1;
    u8 n2;
    u8 n5;
    u16 s4;
    u16 s5;
    u8 s0;
    u16 s1;
    u8 s2;
    u8 s3;

    n0 = D_800F5630;
    n3 = D_800F314E;
    n4 = D_800F562C;
    n1 = D_800F5634;
    n2 = D_800F5638;
    n5 = D_800F563C;
    s4 = D_800F389E;
    s5 = D_800FAFD4;
    s0 = D_800F38A6;
    s1 = D_801516F8;
    s2 = D_800F38A7;
    s3 = D_80151698;
    D_800F38A6 = n0;
    D_801516F8 = n1;
    D_800F38A7 = n2;
    D_800F389E = n3;
    do {} while (0);
    D_800FAFD4 = n4;
    D_80151698 = n5;
    func_800DDFEC(n0, n5, n3, n4);
    D_800F38A6 = s0;
    D_801516F8 = s1;
    D_800F38A7 = s2;
    D_800F389E = s4;
    D_800FAFD4 = s5;
    D_80151698 = s3;
    func_800DDFEC();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2c", func_800DE3CC);

void func_800DE46C(void) {
    u8 *p;
    u8 *q;

    if (D_800F977C == 0) {
        func_800BB9B8(2);
        D_800F977C = 1;
    }
    p = D_80166F78 + D_80158CFC * 0x60;
    if (D_800F3896 == 0x13 && D_800F99E4 == 0) {
        func_800264A8(&D_800F92E2);
        if (D_80062D7E & 0x20) {
            D_800F99E4 = 1;
            q = (u8 *)((D_800F92ED + D_800F92E4) * 6 + (s32)p);
            if (!(q[3] & 2)) {
                func_800BB9B8(1);
                D_800F389C = 0x20;
                D_800F389E = q[0];
                D_801516F8 = D_8016375E;
                if (q[1] == 0) {
                    D_800F3894 = 0x13;
                    D_800F3896 = 0;
                    D_800F38A2 = q[2];
                    func_800E6B94();
                }
            } else {
                func_800BB9B8(3);
            }
        }
    }
}

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

void func_800DF7CC(void) {
    s32 a;
    s32 v;

    v = D_80163626;
    a = 1;
    if (v < 9) {
        a = v < 3;
    }
    if (D_800F3896 == 2 && D_800F99E4 == 0) {
        if (D_80062D7E & 0x20) {
            if (a != 0) {
                func_800BB9B8(1);
                D_800F99E4 = 1;
                D_800F3896 = -1;
                func_800A4350(D_800F38A0, D_800F389C, D_800F389E, D_801516F8);
                func_800D9F5C(1);
                func_800D9F5C(2);
            } else {
                func_800BB9B8(3);
            }
        } else if (D_80062D7E & 0x2040) {
            func_800BB9B8(4);
            D_800F99E4 = 1;
            D_800F3896 = 1;
            func_800D9F5C(2);
        }
    }
}

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

void func_800E010C(void) {
    BtlX440 *p;
    s8 *q;
    u16 v;

    p = &D_8009D8F8[D_800F38A1];
    q = (s8 *)&D_800F910C[D_800F38A1].w2;
    if (D_800F3896 == 0x18 && D_800F99E4 == 0) {
        func_800264A8(q);
        v = D_80062D7E;
        if (v & 0x20) {
            func_800BB9B8(1);
            D_800F38A2 = p->b[q[0xB] + 3];
            D_800F389E = p->b[q[0xB]];
            D_800FAFD4 = (s8)(u8)q[0xB];
            func_800E6B94();
            D_800F3894 = 0x18;
            D_800F3896 = 0;
            D_800F99E4 = 1;
            return;
        }
        if (v & 0x40) {
            func_800BB9B8(4);
            D_800F99E4 = 1;
            D_800F3896 = 1;
            func_800D9F5C(0x18);
        }
    }
}

void func_800E026C(void) {
}

void func_800E0274(void) {
    func_800E53C8();
}

void func_800E0294(void) {
    BtlX440 *p;
    u8 v;
    u16 b;

    p = &D_8009D8F8[D_800F38A1];
    if (D_800F3896 == 0x1B && D_800F99E4 == 0) {
        b = D_80062D7E;
        if (b & 0x20) {
            if (func_800E54EC() == 2) {
                D_800F99E4 = 1;
                func_800BB9B8(1);
                D_800F38A2 = p->b[3];
                v = p->b[0];
                D_800FAFD4 = 0;
                D_800F389E = v;
                func_800E6B94();
                func_800DDFEC();
                func_800E5814();
                func_800D9F5C(0x1B);
                func_800D9F5C(1);
            }
        } else if (b & 0x40) {
            if (func_800E54EC() == 0) {
                func_800BB9B8(4);
                D_800F99E4 = 1;
                D_800F3896 = 1;
                func_800D9F5C(0x1B);
            }
        }
    }
}

void func_800E03C8(void) {
}

void func_800E03D0(void) {
    func_800E4B88();
}

void func_800E03F0(void) {
    BtlX440 *p;
    s32 a;
    u16 k;

    p = &D_8009D8F8[D_800F38A1];
    if (D_800F3896 == 0x1A && D_800F99E4 == 0) {
        k = D_80062D7E;
        if (k & 0x20) {
            D_800F99E4 = 1;
            if (func_800E4BCC() == 2) {
                func_800BB9B8(1);
                D_800F38A2 = p->b[3];
                D_800F389E = p->b[0];
                D_800FAFD4 = 0;
                func_800E6B94();
                func_800DDFEC();
                func_800E5358();
                func_800D9F5C(0x1A);
                a = 1;
                goto block_8;
            }
        } else if ((k & 0x40) && func_800E4BCC() == 0) {
            func_800BB9B8(4);
            a = 0x1A;
            D_800F99E4 = 1;
            D_800F3896 = 1;
block_8:
            func_800D9F5C(a);
        }
    }
}

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
