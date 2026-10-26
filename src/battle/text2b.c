#include "common.h"
#include "battle/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
void func_800CD400(s16 arg0, s32 *arg1, s32 arg2);
typedef struct { s16 k; u8 pad[0xB9A]; } BtlB9Ck;
typedef struct { u8 f; u8 pad[0xB9B]; } BtlB9Cf;
extern BtlB9Ck D_801518F2[];
extern BtlB9Cf D_8015190B[];

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800C7C4C);

void func_800CD400(s16 arg0, s32 *arg1, s32 arg2) {
    s16 i;

    i = arg0;
    D_8015191F[i][0] = func_800C7B60(i, D_801518F4[i].n, arg2 + arg1[D_801518F2[i].k]);
    if (i < 4) {
        if (D_8015190B[i].f & 0x80) {
            func_800C7BE8(i, D_800FA714[i].n, arg2 + arg1[D_801518F2[i].k + 0x34]);
        }
    } else if (D_8015190B[i].f & 0x80) {
        func_800C7BE8(i, D_800FA714[i].n, arg2 + arg1[D_801518F2[i].k + 0x10]);
    }
}

s16 func_800CD558(s16 arg0, u8 *arg1) {
    s32 lo;
    s32 hi;
    lo = arg1[D_80151920[arg0][0]++];
    hi = arg1[D_80151920[arg0][0]++];
    return (hi << 8) + lo;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CD5E4);

void func_800CD798(u8 arg0) {
    D_80151A4C[arg0].v.a = D_80163C80[arg0].a;
    D_80151A4C[arg0].v.b = D_80163C80[arg0].b;
    D_80151A4C[arg0].v.c = D_80163C80[arg0].c;
}

void func_800CD82C(void) {
    D_801590DC = 1;
    D_801621F0[D_801590D4][0] = -1;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CD860);

void func_800CDD44(s16 arg0) {
    D_8015191F[arg0][0] = 1;
    D_8015191F[arg0][1] = 0;
    D_8015191F[arg0][2] = 0;
}

void func_800CDDA4(void) {
    u16 var_v0;

    if (D_80166F68 != 0) {
        var_v0 = D_800F9DA4 | 1;
    } else {
        var_v0 = D_800F9DA4 & 0xFFFE;
    }
    D_800F9DA4 = var_v0;
}

void func_800CDDE8(void) {
    func_800BBA84(D_801621F0[D_801590D4][2], D_801590CC, 0);
    func_800D7178(D_801590CC, D_801621F0[D_801590D4][1]);
    D_801621F0[D_801590D4][0] = -1;
}

void func_800CDE78(void) {
    if (D_801516FC[D_801590CC].a.a < D_801516FC[D_801621F0[D_801590D4][4]].a.a) {
        D_80162204[D_801590D4][0] |= 0x100;
    }
    func_800D4D4C(D_801621F0[D_801590D4][4], D_80162204[D_801590D4][0]);
    D_801621F0[D_801590D4][0] = -1;
}

void func_800CDF6C(s32 arg0, s16 arg1) {
    func_800BBA84(0x14, arg1, 0);
    func_800D58D0(arg0, 1, 1);
    func_800D4D4C(D_800FA6D4, 0x2C);
}

void func_800CDFC4(void) {
    if (D_801621F0[D_801590D4][2] == 0) {
        D_80163C74 = ((u8 *(*)(s32, s32, s32))func_800C4FC8)(0xFA, 0xFA, 0xFA);
        D_801621F0[D_801590D4][0] = -1;
    } else {
        D_801621F0[D_801590D4][2]--;
    }
}

void func_800CE058(s16 arg0) {
    D_80151200[arg0].x38 = D_80151200[arg0].x3A = D_80151200[arg0].x3C = 0x1000;
    D_80151200[arg0].c |= 0x20;
}

void func_800CE0C8(s16 arg0, u8 arg1, u8 arg2) {
    s32 n;



    func_800CE058(arg0);
    switch (arg1) {
    case 0:
        n = func_800BBEAC(&func_800C3578);
        *(s16 *)(D_80162980 + (n << 5)) = arg0;
        *(s16 *)(D_8016297E + (n << 5)) = (u8)arg2;
        break;
    case 8:
        n = func_800BBEAC(&func_800C4814);
        *(s16 *)(D_80162980 + (n << 5)) = arg0;
        *(s16 *)(D_8016297E + (n << 5)) = (u8)arg2;
        break;
    case 1:
    case 10:
        n = func_800BBF7C(&func_800C3950);
        *(s16 *)((u8 *)D_801620AC + 6 + (n << 5)) = (u8)arg2;
        *(s16 *)((u8 *)D_801620AC + 8 + (n << 5)) = arg0;
        *(s16 *)((u8 *)D_801620AC + 10 + (n << 5)) = 0xF8;
        break;
    case 2:
        n = func_800BBEAC(&func_800C3CA8);
        *(s16 *)(D_80162980 + (n << 5)) = arg0;
        *(s16 *)(D_8016297E + (n << 5)) = (u8)arg2;
        break;
    case 3:
        n = func_800BBEAC(&func_800C328C);
        *(s16 *)(D_80162980 + (n << 5)) = arg0;
        *(s16 *)(D_8016297E + (n << 5)) = (u8)arg2;
        break;
    case 17:
    case 18:
        n = func_800BBEAC(&func_800C40F4);
        *(s16 *)(D_80162980 + (n << 5)) = arg0;
        *(s16 *)(D_8016297E + (n << 5)) = (u8)arg2;
        break;
    case 7:
        n = func_800BBEAC(&func_800C44B4);
        *(s16 *)(D_80162980 + (n << 5)) = arg0;
        *(s16 *)(D_8016297E + (n << 5)) = (u8)arg2;
        break;
    }
}

void func_800CE21C(s16 arg0, u8 arg1) {
    s32 n;

    func_800CE058(arg0);
    switch (D_801636BC[arg0].a) {
    case 0:
        n = func_800BBEAC(func_800C3578);
        D_8016297A[n].e = arg0;
        D_8016297A[n].d = arg1;
        break;
    case 8:
        n = func_800BBEAC(func_800C4814);
        D_8016297A[n].e = arg0;
        D_8016297A[n].d = arg1;
        break;
    case 1:
    case 10:
        n = func_800BBF7C(func_800C3950);
        D_801620AE[n].d = arg1;
        D_801620AE[n].e = arg0;
        *(s16 *)&D_801620AE[n].f = 0xF8;
        break;
    case 2:
        n = func_800BBEAC(func_800C3CA8);
        D_8016297A[n].e = arg0;
        D_8016297A[n].d = arg1;
        break;
    case 3:
        n = func_800BBEAC(func_800C328C);
        D_8016297A[n].e = arg0;
        D_8016297A[n].d = arg1;
        break;
    case 17:
    case 18:
        n = func_800BBEAC(func_800C40F4);
        D_8016297A[n].e = arg0;
        D_8016297A[n].d = arg1;
        break;
    case 7:
        n = func_800BBEAC(func_800C44B4);
        D_8016297A[n].e = arg0;
        D_8016297A[n].d = arg1;
        break;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CE384);

void func_800CE638(void) {
    switch (D_801621F0[D_801590D4][1]) {
    case 0:
        D_801621F0[D_801590D4][2] = 3;
        D_801621F0[D_801590D4][1]++;
    case 1:
        if (D_801621F0[D_801590D4][2] == 0) {
            D_801621F0[D_801590D4][0] = -1;
            func_800A3534(D_801621F0[D_801590D4][5], D_801621F0[D_801590D4][4]);
        }
        D_801621F0[D_801590D4][2]--;
        break;
    }
}

void func_800CE75C(void) {
    s16 v;

    v = M2C_SFIELD(&D_80162978[D_8015169C], s16 *, 8);
    if ((D_800FA69C >> v) & 1) {
        func_800D67E8(v);
    } else if ((D_80163608 >> v) & 1) {
        func_800D67BC(v);
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CE7E0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CE970);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CEB48);

void func_800CF2F0(void) {
    s16 i;

    if (D_801620AC[D_801590D0][2] == 0) {
        D_801620AC[D_801590D0][0] = -1;
        return;
    }
    i = D_801620AC[D_801590D0][4];
    D_80151A4C[i].v.b += D_801620AC[D_801590D0][5];
    *(s32 *)0x1F80000C = i;
    D_801620AC[D_801590D0][2]--;
}

void func_800CF3CC(void) {
    s16 i;

    i = D_801620AC[D_801590D0][4];
    *(s32 *)0x1F80000C = i;
    if (D_801620AC[D_801590D0][2] == 0) {
        D_801620AC[D_801590D0][0] = -1;
        return;
    }
    D_801518E6[i][0xB0] += D_801620AC[D_801590D0][7];
    D_801620AC[D_801590D0][2]--;
}

void func_800CF4A8(void) {
    s16 i;

    if (D_801620AC[D_801590D0][2] == 0) {
        D_801620AC[D_801590D0][0] = -1;
        return;
    }
    i = D_801620AC[D_801590D0][4];
    D_80151A4C[i].v.a += D_801620AC[D_801590D0][5];
    D_80151A4C[i].v.c += D_801620AC[D_801590D0][6];
    *(s32 *)0x1F80000C = i;
    D_801620AC[D_801590D0][2]--;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CF5BC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CF8C0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CFB14);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CFCB0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CFE60);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D01C0);

void func_800D0578(void) {
    s32 i;
    s16 t;

    i = D_801590D4;
    t = D_801621F0[i][2];
    if (t == 0) {
        func_800D4D4C(D_801621F0[i][4], D_801621F0[i][3]);
        D_801621F0[D_801590D4][0] = -1;
    } else {
        D_801621F0[i][2] = t - 1;
    }
}

void func_800D061C(void) {
    s32 i;
    s16 t;

    i = D_801590D4;
    t = D_801621F0[i][2];
    if (t == 0) {
        func_800BBA84(D_801621F0[i][3], D_801590CC, 0);
        D_801621F0[D_801590D4][0] = -1;
    } else {
        D_801621F0[i][2] = t - 1;
    }
}

void func_800D06B8(void) {
    s32 i;
    s16 t;

    i = D_801590D4;
    t = D_801621F0[i][2];
    if (t == 0) {
        if (D_801518DC == 0) {
            func_800D0C80(D_801621F0[i][3]);
            D_801621F0[D_801590D4][0] = -1;
        }
    } else {
        D_801621F0[i][2] = t - 1;
    }
}

void func_800D0760(void) {
    if (D_80162978[D_8015169C].d == 0) {
        if (D_80162978[D_8015169C].c == 0) {
            D_80162978[D_8015169C].a = -1;
            return;
        }
        func_800DCF60(D_80151906[D_801590CC].a, D_8015123E[D_801590CC].a);
        D_80162978[D_8015169C].c--;
        return;
    }
    D_80162978[D_8015169C].d--;
}

void func_800D088C(s32 arg0, s32 arg1) {
    func_80033E34(arg0, arg1, 0x801B0000, 0);
    func_800B7FB4();
}

void func_800D08B8(s32 arg0, s32 *arg1) {
    s32 i;

    if (arg1 != NULL) {
        for (i = 0; i < 8; i++) {
            *(s32 *)(D_800F8384[arg0 & 0xFF] + (i << 2) + 0xBC) = (s32)arg1 + arg1[i + 1] - D_800F8384[arg0 & 0xFF];
        }
        for (i = 0; i < 8; i++) {
            *(s32 *)(D_800F8384[arg0 & 0xFF] + (i << 2) + 0x18C) = (s32)arg1 + arg1[i + 9] - D_800F8384[arg0 & 0xFF];
        }
    }
}

void func_800D0958(u8 arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        D_800F9984[arg0][i] = *(s32 *)(D_800F8384[arg0] + (i << 2) + 0xBC);
        D_801679BC[arg0][i] = *(s32 *)(D_800F8384[arg0] + (i << 2) + 0x18C);
    }
}

void func_800D09D0(u8 arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        *(s32 *)(D_800F8384[arg0] + (i << 2) + 0xBC) = D_800F9984[arg0][i];
        *(s32 *)(D_800F8384[arg0] + (i << 2) + 0x18C) = D_801679BC[arg0][i];
    }
}

void func_800D0A44(void) {
}

void func_800D0A4C(void) {
    s32 temp_v0;
    s32 var_a0;
    u8 *var_v1;

    var_a0 = 0;
    var_v1 = &D_80151909;
    do {
        var_a0 += 1;
        *var_v1 |= 1;
        var_v1 += 0xB9C;
    } while (var_a0 < 3);
    func_801B0040(D_80151774, D_801590CC);
    temp_v0 = func_800BC04C(func_800D0AD4);
    *(s32 *)0x1F800000 = temp_v0;
    D_801621F0[temp_v0][2] = 2;
}

void func_800D0AD4(void) {
    if (D_801621F0[D_801590D4][2] == 0) {
        D_801621F0[D_801590D4][0] = -1;
        func_800BB978();
    } else {
        D_801621F0[D_801590D4][2]--;
    }
}

void func_800D0B4C(s32 arg0) {
    s32 i;

    D_800F8CF0 = 0;
    func_800D1530();
    i = arg0 & 0xFF;
    switch (D_80151906[i].a) {
    case 4:
        D_800EF9D8[D_80151906[i].pad[0]](D_80151774, D_801590CC);
        break;
    case 7:
        func_801B037C(D_80151774, D_801590CC);
        break;
    case 8:
        D_800EFFE0[D_80151906[i].pad[0]](D_80151774, D_801590CC);
        break;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D0C80);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D1110);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D1530);

void func_800D2538(s32 arg0, s32 arg1) {
    D_800F01DC->op = 0;
    D_800F01DC->a = arg0;
    D_800F01DC->b = arg1;
    D_800F01DC++;
}

void func_800D2564(s32 arg0, s32 arg1) {
    D_800F01DC->op = 1;
    D_800F01DC->a = arg0;
    D_800F01DC->b = arg1;
    D_800F01DC++;
}

void func_800D2590(s32 arg0, s32 arg1, s32 arg2) {
    D_800F01DC->op = 2;
    D_800F01DC->a = arg0;
    D_800F01DC->c = arg1;
    D_800F01DC->d = arg2;
    D_800F01DC++;
}

void func_800D25C0(s32 arg0) {
    D_800F01DC->op = 3;
    D_800F01DC->a = arg0;
    D_800F01DC++;
}

void func_800D25E8(void) {
    BtlCmd *p;
    s32 *q;

    p = D_800F4BAC;
    if (p < D_800F01DC) {
        q = &p->a;
        do {
            switch (p->op) {
            case 0:
                func_80044000((void *)q[0], (void *)q[1]);
                q += 5;
                break;
            case 1:
                func_80044064((void *)q[0], q[1]);
                q += 5;
                break;
            case 2:
                func_800440C8((Rect16 *)q[0], q[2], q[3]);
                q += 5;
                break;
            case 3:
                func_80043F6C((Rect16 *)q[0], 0, 0, 0);
                do {
                } while (0);
                q += 5;
                break;
            default:
                q += 5;
                break;
            }
            p++;
        } while (p < D_800F01DC);
    }
    D_800F01DC = D_800F4BAC;
}

void func_800D26F8(void) {
    D_800F01DC = &D_800F4BAC;
}

void func_800D2710(s32 arg0, s32 arg1, s32 arg2) {
    Unk80046D0C info;

    func_80046CFC(arg0);
    func_80046D0C(&info);
    if (info.a != 0 && info.a_arg != 0) {
        D_800F4B2C[D_800F01E0] = *(BtlRect *)info.a;
        D_800F4B2C[D_800F01E0].x = D_800F4B2C[D_800F01E0].x + (arg1 & ~0xF);
        D_800F4B2C[D_800F01E0].y = arg2 + D_800F4B2C[D_800F01E0].y;
        func_800D2538((s32)&D_800F4B2C[D_800F01E0], info.a_arg);
        D_800F01E0 = (D_800F01E0 + 1) & 7;
    }
}

void func_800D2828(s32 arg0, s32 arg1) {
    Unk80046D0C sp;
    s32 a;
    s32 b;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;

    func_80046CFC(arg0);
    func_80046D0C(&sp);
    if (sp.b != 0 && sp.b_arg != 0) {
        D_800F4B6C[D_800F01E4] = *(BtlR4 *)sp.b;
        a = ((u16)sp.b[1] & 0x300) >> 4 | ((u16)sp.b[0] & 0x3FF) >> 6;
        b = a + arg1;
        t1 = (a & 0xF) << 6;
        t2 = (b & 0xF) << 6;
        D_800F4B6C[D_800F01E4].a = (t2 + (D_800F4B6C[D_800F01E4].a - t1)) & 0x3FF;
        t3 = (a & 0x30) << 4;
        t4 = (b & 0x30) << 4;
        D_800F4B6C[D_800F01E4].b = (t4 + (D_800F4B6C[D_800F01E4].b - t3)) & 0x1FF;
        func_800D2538((s32)&D_800F4B6C[D_800F01E4], sp.b_arg);
        D_800F01E4 = (D_800F01E4 + 1) & 7;
    }
}

void func_800D2980(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_800D2710(arg0, arg2, arg3);
    func_800D2828(arg0, arg1);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D29D4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D32B4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D3354);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D3418);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D3474);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D34C8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D3520);

s32 func_800D3548(u8 *buf, s32 *pos) {
    s32 p = *pos;
    u8 *q = buf + p / 8;
    s32 bit = p & 7;
    s32 v = (q[0] << 8) | q[1];
    s32 m = 1 << (15 - bit);
    s32 r;
    if (v & m) {
        v = (v << 8) | q[2];
        *pos = p + 17;
        r = (s16)((v << (bit + 1)) >> 8);
    } else {
        *pos = p + 8;
        r = (s16)(v << (bit + 1)) >> 9;
    }
    return r;
}

s32 func_800D35D8(u8 *buf, s32 *pos, s32 n) {
    s32 i;
    s32 v;
    s32 pad;

    v = 0;
    for (i = 0; i < n; i++) {
        v <<= 1;
        if ((buf[*pos / 8] >> (7 - (*pos & 7))) & 1) {
            v++;
        }
        (*pos)++;
    }
    v <<= 32 - n;
    v >>= 32 - n;
    return v;
}

s32 func_800D3658(u8 *arg0, s32 *arg1, s32 arg2) {
    s32 n;
    s32 v;

    if (func_800D35D8(arg0, arg1, 1) == 0) {
        return 0;
    }
    n = func_800D35D8(arg0, arg1, 3) & 7;
    switch (n) {
    case 0:
        return (s32) (0xFFFF0000 << arg2) >> 0x10;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        v = func_800D35D8(arg0, arg1, n);
        if (v >= 0) {
            v += 1 << (n - 1);
        } else {
            v -= 1 << (n - 1);
        }
        return (s16) (v << arg2);
    case 7:
        return (s16) (func_800D35D8(arg0, arg1, 0xC - arg2) << arg2);
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D376C);

void func_800D3994(s32 arg0, s32 arg1, BtlSVec *arg2) {
    BtlMatrix m;

    arg2->vx = D_80151A6C[arg0].c[arg1].x - D_800FA63C.t[0];
    arg2->vy = D_80151A6C[arg0].c[arg1].y - D_800FA63C.t[1];
    arg2->vz = D_80151A6C[arg0].c[arg1].z - D_800FA63C.t[2];
    ((void (*)(BtlMatrix *, BtlMatrix *))func_8003BF3C)(&D_800FA63C, &m);
    func_8003B2CC(&m, arg2, arg2);
}

void func_800D3A6C(BtlMatrix *arg0, BtlSVec *arg1) {
    BtlMatrix m;

    arg1->vx = arg0->t[0] - D_800FA63C.t[0];
    arg1->vy = arg0->t[1] - D_800FA63C.t[1];
    arg1->vz = arg0->t[2] - D_800FA63C.t[2];
    func_8003BF3C(&D_800FA63C, &m, arg0);
    func_8003B2CC(&m, arg1, arg1);
}

void func_800D3AF0(void) {
    s16 *p;
    s8 *q;
    MgMat *m;
    s32 t;
    s16 *w;
    u16 u;

    p = D_801621F0[D_801590D4];
    t = p[1] * 32;
    q = &D_800F01EC;
    q[0] = t;
    w = &p[7];
    u = p[7];
    m = &D_800F01F8;
    m->m[0][0] = u;
    D_800F0200 = (u16)p[8];
    func_800D4284((MgSVec *)(p + 2), -*w >> 4, m);
    func_8003B48C(m);
    func_8003B51C(m);
    D_80163C74 = func_800D6260(q - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        if (p[1]++ >= 7) {
            p[0] = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D3BF0);

void func_800D3D88(void) {
    s16 *p;
    s16 *q;
    s16 i;
    u8 c;
    s32 off;

    p = D_801621F0[D_801590D4];
    i = p[0];
    off = i * 0xB9C; c = D_8015191A[off + (p[1] & 1)];
    if (c != 0xFF) {
        q = D_801621F0[func_800BC04C(func_800D3BF0)];
        func_800D3994(i, c, (BtlSVec *)&q[2]);
        q[3] = 0;
        q[7] = p[7];
        q[8] = p[8];
    }
    if (++p[1] == 4) {
        p[0] = -1;
    }
}

void func_800D3E8C(s32 arg0) {
    s16 *p;
    s16 v;

    p = D_801621F0[func_800BC04C(&func_800D3D88)];
    p[0] = arg0;
    v = D_801518EA[arg0].a;
    p[8] = v;
    p[7] = v;
}

void func_800D3F0C(V8 *arg0, s32 arg1, s32 arg2) {
    E21F0b *p;

    p = (E21F0b *)D_801621F0[func_800BC04C(&func_800D3AF0)];
    p->v = *arg0;
    p->d = arg1;
    p->e = arg2;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D3F8C);

void func_800D415C(s32 arg0, V8 *arg1, s32 arg2, s32 arg3, u16 arg4) {
    BtlE415C *p;

    p = (BtlE415C *)D_801621F0[func_800BC04C(&func_800D3F8C)];
    p->f = arg0;
    p->v = *arg1;
    p->c = arg2;
    p->d = arg3;
    p->e = arg4;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D41FC);

MgMat *func_800D4284(MgSVec *arg0, s32 arg1, MgMat *arg2) {
    MgVec v;
    s32 flag;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(arg0, (MgVec *)arg2->t, &flag);
    if (arg1 != 0) {
        func_8003A08C((MgVec *)arg2->t, &v);
        arg2->t[0] += (arg1 * v.vx) >> 12;
        arg2->t[1] += (arg1 * v.vy) >> 12;
        arg2->t[2] += (arg1 * v.vz) >> 12;
    }
    return arg2;
}

MgMat *func_800D4368(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_800F0228.m[0][0] = D_800F0228.m[1][1] = D_800F0228.m[2][2] = scale;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(v, (MgVec *)D_800F0228.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_800F0228.t, &n);
        D_800F0228.t[0] += (dist * n.vx) >> 12;
        D_800F0228.t[1] += (dist * n.vy) >> 12;
        D_800F0228.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_800F0228);
    func_8003B51C(&D_800F0228);
    return &D_800F0228;
}

void func_800D4484(s32 arg0, s32 arg1) {
    void *temp_s0;

    temp_s0 = D_80163C74;
    func_80044A68(temp_s0, 0, 1, arg1 & 0xFFFF, 0);
    func_80046794(arg0, (s32) temp_s0);
    D_80163C74 = temp_s0 + 0xC;
}

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text2b", D_800A0DB8);

void func_800D44E8(MgSVec *arg0, MgMat *arg1) {
    MgVec b;
    MgVec c;
    MgVec a;

    c = D_800A0DB8;
    a.vx = arg0->vx;
    a.vy = arg0->vy;
    a.vz = arg0->vz;
    func_8003A08C(&a, &a);
    b.vx = a.vz;
    b.vy = 0;
    b.vz = -a.vx;
    func_8003A08C(&b, &b);
    func_8003BA10(&a, &b, &c);
    func_8003A08C(&c, &c);
    arg1->m[0][0] = b.vx;
    arg1->m[1][0] = b.vy;
    arg1->m[2][0] = b.vz;
    arg1->m[0][1] = c.vx;
    arg1->m[1][1] = c.vy;
    arg1->m[2][1] = c.vz;
    arg1->m[0][2] = a.vx;
    arg1->m[1][2] = a.vy;
    arg1->m[2][2] = a.vz;
}

void func_800D461C(MgMat *m) {
    MgVec u;
    MgVec v;
    MgVec w;

    v.vx = m->m[0][1];
    v.vy = m->m[1][1];
    v.vz = m->m[2][1];
    func_8003A08C(&v, &v);
    m->m[0][1] = v.vx;
    m->m[1][1] = v.vy;
    m->m[2][1] = v.vz;
    u.vz = 0;
    u.vx = v.vy;
    u.vy = -v.vx;
    func_8003A08C(&u, &u);
    m->m[0][0] = u.vx;
    m->m[1][0] = u.vy;
    m->m[2][0] = u.vz;
    func_8003BA10(&u, &v, &w);
    func_8003A08C(&w, &w);
    m->m[0][2] = w.vx;
    m->m[1][2] = w.vy;
    m->m[2][2] = w.vz;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D4710);

void func_800D491C(u8 *arg0, V8 *arg1, BtlSrc491C *arg2) {
    BtlE491C *p;
    s32 t;

    p = (BtlE491C *)D_801621F0[func_800BC04C(&func_800D4710)];
    p->v = *arg1;
    p->a = ((s8)*arg0++ - 1) | arg2->a;
    if (arg2->a & 0x100) {
        p->x14 = (-((s8)*arg0++ << 3) * arg2->s) >> 12;
    } else {
        p->x14 = (((s8)*arg0++ << 3) * arg2->s) >> 12;
    }
    p->x16 = (((s8)*arg0++ << 3) * arg2->s) >> 12;
    p->e = arg2->w;
    t = (((s8)*arg0++ << 8) * arg2->s) >> 12;
    if (t > 0x7FFF) {
        t = 0x7FFF;
    }
    p->d = t;
    p->x1A = (s8)*arg0 << 6;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D4A64);

void func_800D4C08(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    BtlE4C08 *p;

    p = (BtlE4C08 *)D_801621F0[func_800BC04C(&func_800D4A64)];
    p->a = arg1 & 0xFF00;
    p->c = D_800F0F98[arg1 & 0xFF];
    p->v = *(V8 *)arg0;
    p->d = arg2;
    p->e = arg3;
}

void func_800D4CBC(s32 arg0, s32 arg1, s32 arg2) {
    BtlSVec v;
    func_800D3994(arg0, D_8015190F[arg0][0], &v);
    func_800D4C08((s32)&v, arg1, arg2, -D_801518F6[arg0][0]);
}

void func_800D4D4C(s32 arg0, s32 arg1) {
    func_800D4CBC(arg0, arg1, 0x1000);
}

void func_800D4D6C(s32 arg0, s32 arg1, s32 arg2) {
    func_800D4C08(arg0, arg1, 0x1000, arg2);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D4D90);

Q20 *func_800D4FA8(s32 arg0) {
    s32 i;

    i = D_800F10D8;
    D_800F4CEC[i] = arg0;
    D_800F10D8 = (i + 1) & 0xF;
    return &D_800F4D2C[i];
}

s32 func_800D4FF0(Q20 **arg0) {
    s32 ret;

    if (D_800F10D8 == D_800F10DC) {
        *arg0 = &D_800F4D2C[(D_800F10D8 - 1) & 0xF];
        return 0;
    } else {
        ret = D_800F4CEC[D_800F10DC];
        *arg0 = &D_800F4D2C[D_800F10DC];
        D_800F10DC = (D_800F10DC + 1) & 0xF;
        return ret;
    }
}

void func_800D508C(void) {
    B20 *p;
    s32 v;
    u8 c;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0 && M2C_FIELD(p, s32 *, 0xC) != 0) {
        v = M2C_FIELD(p, s32 *, 4) + M2C_FIELD(p, s32 *, 0xC);
        M2C_FIELD(p, s32 *, 4) = v;
        if (v <= 0) {
            p->a = -1;
            D_800F10E0 = NULL;
            return;
        }
        if (v > 0xFFFF) {
            M2C_FIELD(p, s32 *, 4) = 0xFFFF;
            M2C_FIELD(p, s32 *, 0xC) = 0;
        }
    }
    c = M2C_FIELD(p, u8 *, 5);
    D_80163C74 = ((u8 *(*)(s32, s32, s32))func_800C4FC8)(c, c, c);
}

void func_800D5138(s32 arg0) {
    s32 t;

    if (D_800F10E0 == NULL) {
        D_800F10E0 = (u8 *) &D_80162978[func_800BBEAC(&func_800D508C)];
    }
    t = 0x10000 / arg0;
    M2C_FIELD(D_800F10E0, s32 *, 4) = 0;
    M2C_FIELD(D_800F10E0, s32 *, 0xC) = t;
}

void func_800D51D4(s32 arg0) {
    if (D_800F10E0 != NULL) {
        M2C_FIELD(D_800F10E0, s32 *, 0xC) = (s32) ((s32) -M2C_FIELD(D_800F10E0, s32 *, 4) / arg0);
    }
}

void func_800D5230(void) {
    B20 *p;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        M2C_FIELD(p, s32 *, 4) += M2C_FIELD(p, s32 *, 8);
        D_800F5B74 = M2C_FIELD(p, s32 *, 4) >> 16;
        if (--M2C_FIELD(p, s32 *, 0xC) == 0) {
            D_800F10E4 = 0;
            p->a = -1;
        }
    }
}

void func_800D52A0(s32 arg0, s32 arg1) {
    B20 *p;
    s32 start;

    if (D_800F10E4 == 0) {
        p = &D_80162978[func_800BBEAC(&func_800D5230)];
        start = D_800F5B74 << 16;
        D_800F10E4 = (s32) p;
        M2C_FIELD(p, s32 *, 0xC) = arg1;
        M2C_FIELD(p, s32 *, 4) = start;
        M2C_FIELD(p, s32 *, 8) = ((arg0 << 16) - start) / arg1;
    }
}

void func_800D5350(void) {
    BtlTask20 *p;

    p = (BtlTask20 *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->b == 0) {
            do {
                while (!((p->c >> p->a) & 1)) {
                    p->a++;
                }
                p->fn(p->a, p->d);
                p->a++;
                if (p->c < (1 << p->a)) {
                    p->a = -1;
                    return;
                }
            } while (p->x8 == 0);
        }
        if (++p->b >= p->x8) {
            p->b = 0;
        }
    }
}

void func_800D5444(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    B20 *temp_v0;

    temp_v0 = &D_80162978[func_800BBEAC(&func_800D5350)];
    temp_v0->a = 0;
    temp_v0->c = arg0;
    temp_v0->d = arg1;
    M2C_FIELD(temp_v0, s16 *, 8) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0xC) = arg3;
}

s32 func_800D54BC(s32 arg0) {
    s32 i;
    s32 n;

    n = 0;
    for (i = 0; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
        }
    }
    return n;
}

void *func_800D54EC(s32 arg0, void *arg1) {
    s32 minx, maxx, minz, maxz;
    s32 i;
    BtlB9CPos *p;
    s32 v;

    minx = 0x7FFF;
    minz = 0x7FFF;
    maxx = -0x8000;
    maxz = -0x8000;
    for (i = 0; i < 10; i++) {
        p = &D_80151A24[i];
        if ((arg0 >> i) & 1) {
            v = p->x;
            if (v < minx) {
                minx = v;
            }
            if (v > maxx) {
                maxx = v;
            }
            v = p->z;
            if (v < minz) {
                minz = v;
            }
            if (v > maxz) {
                maxz = v;
            }
        }
    }
    ((s16 *)arg1)[0] = (minx + maxx) / 2;
    ((s16 *)arg1)[2] = (minz + maxz) / 2;
    ((s16 *)arg1)[1] = 0;
    return arg1;
}

s32 func_800D55A4(s32 arg0) {
    return (D_801518EA[arg0].b * (D_801518EA[arg0].a << 4)) >> 12;
}

void func_800D55F4(s32 cmd, ...) {
    s32 n;
    s32 i;
    s32 *args;
    u16 c;

    args = &cmd;
    c = cmd;
    D_8009A000 = c;
    switch (c) {
    case 0x21:
        n = 3;
        break;
    case 0x22:
        n = 4;
        break;
    case 0x23:
        n = 5;
        break;
    default:
        n = 2;
        break;
    }
    for (i = 1; i <= n; i++) {
        (&D_8009A004)[i - 1] = args[i];
    }
    func_8002DA7C();
}

s32 func_800D56A8(void *arg0) {
    s16 xy[2];
    s32 p;
    s32 flag;

    func_8003B48C((s32)&D_800FA63C);
    func_8003B51C((s32)&D_800FA63C);
    func_8003BBDC(arg0, xy, &p, &flag);
    if (xy[0] < 0) {
        xy[0] = 0;
    } else if (xy[0] >= 0x140) {
        xy[0] = 0x13F;
    }
    return (xy[0] << 7) / 320;
}

void func_800D574C(s32 arg0) {
    s32 sp10[2];

    func_800D54EC(arg0, sp10);
    func_800D56A8(sp10);
}

void func_800D5774(s32 arg0) {
    s16 *p;

    if ((D_800F836C >> arg0) & 1) {
        p = (s16 *) func_800D4FA8(6);
    } else {
        p = (s16 *) func_800D4FA8(4);
    }
    *p = arg0;
}

void func_800D57C0(void) {
    B20 *p;
    s16 i;
    s16 b;
    s16 c;
    s16 m;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        b = p->b;
        c = p->c;
        if (b >= c && (b - c) % p->d == 0) {
            i = p->a;
            while (!((M2C_FIELD(p, s16 *, 8) >> i) & 1)) {
                i = i + 1;
                p->a = i;
            }
            *(s16 *)func_800D4FA8(4) = p->a;
            m = (u16)M2C_FIELD(p, s16 *, 8) & ~(1 << p->a);
            M2C_FIELD(p, s16 *, 8) = m;
            if (m == 0) {
                p->a = -1;
            }
        }
        p->b = p->b + 1;
    }
}

void func_800D58D0(s32 arg0, s32 arg1, s32 arg2) {
    B20 *p;

    p = &D_80162978[func_800BBEAC(&func_800D57C0)];
    p->a = 0;
    M2C_SFIELD(p, s16 *, 8) = arg0;
    p->d = arg2;
    p->c = arg1;
}

void func_800D5938(void) {
    B20 *e;
    s16 b;
    s16 c;
    s32 v;
    s16 *p;

    e = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        b = e->b;
        c = e->c;
        if (b >= c && (b - c) % (s16)e->d == 0) {
            v = D_801517F0[e->a];
            if (v == 0xFF) {
                e->a = -1;
            } else {
                p = func_800D4FA8(0xA);
                p[0] = v;
                p[8] = e->a;
                e->a++;
                if (D_801517F0[e->a] == 0xFF) {
                    e->a = -1;
                }
            }
        }
        e->b++;
    }
}

void func_800D5A68(s16 arg0, s16 arg1) {
    B20 *p;

    p = &D_80162978[func_800BBEAC(&func_800D5938)];
    p->a = 0;
    p->d = arg1;
    p->c = arg0;
}

s32 func_800D5AC0(s32 arg0, s32 arg1) {
    return (((s32) (arg0 & 0xFF0000) / arg1) & 0xFF0000) | (((s32) (arg0 & 0xFF00) / arg1) & 0xFF00) | (((s32) (arg0 & 0xFF) / arg1) & 0xFF);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D5B6C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D5D28);

void func_800D61AC(s32 arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    BtlE61AC *p;

    p = (BtlE61AC *)D_801621F0[func_800BC04C(&func_800D5D28)];
    p->a = arg2 >> 24;
    p->b = arg0;
    p->f = -arg1;
    p->c = 0;
    p->d = (arg2 & 0xFFFFFF) | 0x3A000000;
    p->e = func_800D5AC0(arg2, arg3);
    p->g = arg4;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D6260);

void func_800D6394(s32 arg0, s16 arg1) {
    s32 *p;

    p = &D_800F14D0;
    *p = arg0;
    D_800F14DA = arg1;
    func_8003B69C(0, 0, 0);
    func_8003AE38();
    D_80163C74 = func_800D29D4(p, D_801517C0 + 0x70, 0xC, D_80163C74);
    func_8003AED8();
    func_8003AE38();
    D_800F14D4 |= 1;
    D_80163C74 = func_800D29D4(p, D_801517C0 + 0x70, 0xC, D_80163C74);
    func_8003AED8();
    func_8003AE38();
    D_800F14D4 |= 2;
    D_80163C74 = func_800D29D4(p, D_801517C0 + 0x70, 0xC, D_80163C74);
    func_8003AED8();
    D_800F14D4 &= ~1;
    D_80163C74 = func_800D29D4(p, D_801517C0 + 0x70, 0xC, D_80163C74);
    D_800F14D4 &= ~2;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D650C);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text2b", D_800A0DC8);

BtlE6734 *func_800D6734(s32 arg0, s32 arg1) {
    BtlTbl3 t;
    BtlE6734 *p;
    t = D_800A0DC8;
    p = (BtlE6734 *)D_801621F0[func_800BC04C(&func_800D650C)];
    p->x8 = arg0;
    p->x4 = t.a[arg1];
    return p;
}

void func_800D67BC(s32 arg0) {
    D_800F14D4 = 0x88;
    func_800D6734(arg0, 0);
}

void func_800D67E8(s32 arg0) {
    D_800F14D4 = 0xA8;
    func_800D6734(arg0, 1);
}

void func_800D6814(s32 arg0) {
    D_800F14D4 = 0x88;
    func_800D6734(arg0, 2);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D6840);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D6998);

void func_800D6ACC(void) {
    s16 *p;
    s16 v;

    p = D_801621F0[D_801590D4];
    v = p[1] * 0x600;
    D_800F16DC.v = v;
    D_800F16CC.v = v;
    if (p[1] < 8) {
        D_800F16D4.v = p[1] * 0xC00;
        D_800F16A2 = 0;
    } else if (p[1] < 0x10) {
        D_800F16D4.v = 0x6000;
        D_800F16A2 = (p[1] - 8) << 9;
    }
    D_800F16E4 = 0;
    D_800F16E0[0] = p[2];
    D_800F16E8 = p[4];
    func_8003A63C(&D_800FA63C, &D_800F16E0[-5], (MgMat *)D_800F16EC);
    D_800F1698 = &D_800F14E0;
    func_800D6840(D_800F16EC);
    if (D_80062D98 == 0) {
        p[1]++;
        if (p[1] == 0x10) {
            p[0] = -1;
        }
    }
}

void func_800D6C20(void) {
    s16 *p;
    s32 v;
    s32 t;

    p = D_801621F0[D_801590D4];
    D_800F16F8.v = func_80039A74((0xE - p[1]) << 7) + 0x1000;
    v = (0xE - p[1]) << 10;
    D_800F1700.v = v;
    D_800F16F0.v = v;
    t = p[1];
    if (t < 8) {
        D_800F16A2 = -(t << 12) / 8 + 0x1000;
    } else {
        D_800F16A2 = (t - 8) << 9;
    }
    D_800F1708 = 0;
    D_800F1704[0] = p[2];
    D_800F170C = p[4];
    func_8003A63C(&D_800FA63C, &D_800F1704[-5], (MgMat *)D_800F1710);
    D_800F1698 = &D_800F15AC;
    D_800F16A0 = 0x80;
    D_800F16A6 = 0x80;
    func_800D6840(D_800F1710);
    if (D_80062D98 == 0) {
        p[1]++;
        if (p[1] == 0x10) {
            p[0] = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D6D8C);

void func_800D6F78(void) {
    BtlE6F78 *p;
    BtlE6F78 *q;
    s32 r;
    s32 c;
    s32 j;
    u8 pad[0x50];

    p = (BtlE6F78 *)D_801621F0[D_801590D4];
    if (D_80062D98 == 0) {
        q = (BtlE6F78 *)D_801621F0[func_800BC04C(&func_800D6D8C)];
        q->a = (p->b + j) % 5;
        q->v = p->v;
        r = func_80042DA8() & 0xFFF;
        q->xC = ((u32)func_80039A74(r) * 25) >> 9;
        c = func_80039B40(r);
        q->xE = (c * 200) >> 12;
        q->x14 = q->xE;
        q->x16 = -q->xC;
        if (++p->b >= 0x17) {
            p->a = -1;
        }
    }
}

void func_800D70C0(void) {
    BtlE70C0 *p;

    p = (BtlE70C0 *)D_801621F0[D_801590D4];
    if (D_80062D98 == 0) {
        if (!(p->b & 3)) {
            ((BtlE70C0 *)D_801621F0[func_800BC04C(p->fn)])->v = p->v;
        }
        if (++p->b == 13) {
            p->a = -1;
        }
    }
}

void func_800D7178(s32 arg0, s32 arg1) {
    BtlE70C0 *p;

    p = (BtlE70C0 *)D_801621F0[func_800BC04C(func_800D70C0)];
    func_800D3994(arg0, D_8015190F[arg0][0], (BtlSVec *)&p->v);
    switch (arg1) {
    case 0:
        p->fn = (void *)func_800D6998;
        break;
    case 1:
        p->fn = (void *)func_800D6ACC;
        break;
    case 2:
        p->fn = (void *)func_800D6C20;
        break;
    case 3:
        p->fn = (void *)func_800D6998;
        ((BtlE70C0 *)D_801621F0[func_800BC04C(func_800D6F78)])->v = p->v;
        break;
    }
}

void func_800D72B4(void) {
    s16 *temp_s0;

    temp_s0 = D_801621F0[D_801590D4];
    if (D_80062D98 == 0) {
        if (temp_s0[1] == 0) {
            func_800D5138(1);
        }
        if (temp_s0[1] == 2) {
            func_800D51D4(1);
            M2C_FIELD(temp_s0, s16 *, 0) = -1;
        }
        temp_s0[1] = (u16) temp_s0[1] + 1;
    }
}

void func_800D7340(void) {
    func_800BBEAC(&func_800D72B4);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D7368);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D751C);

void func_800D76B8(V8 *arg0) {
    E21F0 *p;

    p = (E21F0 *) D_801621F0[func_800BC04C(func_800D751C)];
    p->v = *arg0;
    p->a = 1;
}

void func_800D7724(void) {
    MgMat m;
    BtlT7724 *p;
    BtlT7724q *q;

    p = (BtlT7724 *)D_801621F0[D_801590D4];
    if (D_80062D98 == 0) {
        if (p->b != 0) {
            p->a = -1;
            return;
        }
    }
    D_800F1978[0] = -p->c;
    func_8003A63C(p->d, &D_800F1978[-7], &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_80163C74 = func_800D29D4(D_800F197C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (*(u8 *)0x80062D98 == 0) {
        q = (BtlT7724q *)D_801621F0[func_800BC04C(func_800D751C)];
        q->v.vx = m.t[0] - D_800FA63C.t[0];
        q->v.vy = m.t[1] - D_800FA63C.t[1];
        q->v.vz = m.t[2] - D_800FA63C.t[2];
        ((void (*)(MgMat *, MgMat *))func_8003BF3C)(&D_800FA63C, &m);
        func_8003B2CC((BtlMatrix *)&m, &q->v, &q->v);
        q->a = 0;
        p->b++;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D7888);

void func_800D7A88(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5) {
    BtlE7A88 *p = (BtlE7A88 *)D_801621F0[func_800BC04C(&func_800D7888)];
    p->x4 = arg0;
    p->x6 = arg1;
    p->x1C = arg2;
    p->x1A = arg3;
    p->x8 = arg4;
    p->xA = arg5;
}

void func_800D7B1C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_800D7A88(arg0, arg1, D_801518FC[arg1].buf + D_801518FC[arg1].x19 * 0x34, D_801518FC[arg1].x2, arg2, arg3);
}

void func_800D7BA4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_800D7A88(arg0, arg1, D_801518FC[arg1].buf + D_801518FC[arg1].x1A * 0x34, D_801518FC[arg1].x4, arg2, arg3);
}

void func_800D7C2C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p;

    p = D_80151A58[arg1];
    func_800D7A88(arg0, arg1, p + D_801518FC[arg1].x19 * 0x34, D_801518FC[arg1].x2, arg2, arg3);
    func_800D7A88(arg0, arg1, p + D_801518FC[arg1].x1A * 0x34, D_801518FC[arg1].x4, arg2, arg3);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D7D3C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D8304);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D83A4);

void func_800D8468(void *arg0, void *arg1) {
    M2C_FIELD(arg0, u16 *, 0) = (u16) M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg1, u16 *, 6);
    M2C_FIELD(arg0, u16 *, 0xC) = (u16) M2C_FIELD(arg1, u16 *, 0xC);
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg1, u16 *, 2);
    M2C_FIELD(arg0, u16 *, 8) = (u16) M2C_FIELD(arg1, u16 *, 8);
    M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg1, u16 *, 0xE);
    M2C_FIELD(arg0, u16 *, 4) = (u16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(arg0, u16 *, 0xA) = (u16) M2C_FIELD(arg1, u16 *, 0xA);
    M2C_FIELD(arg0, u16 *, 0x10) = (u16) M2C_FIELD(arg1, u16 *, 0x10);
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) M2C_FIELD(arg1, s32 *, 0x14);
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) M2C_FIELD(arg1, s32 *, 0x18);
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) M2C_FIELD(arg1, s32 *, 0x1C);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D84F8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D85B0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D87EC);

void func_800D8A04(void) {
}

s32 func_800D8A0C(s32 arg0) {
    s32 var_v0;

    var_v0 = arg0;
    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }
    return var_v0;
}

void func_800D8A24(void) {
}

void func_800D8A2C(void) {
    D_800F199C = 0;
}

void func_800D8A3C(s32 arg0) {
    D_800F9780[D_800F199C++] = arg0;
}

void func_800D8A70(void) {
}

void func_800D8A78(s8 arg0) {
    D_800F19A4 = arg0;
}

s32 func_800D8A88(void) {
    s32 p;
    s32 r;

    func_80043DD8(0);
    r = func_8003CEDC((u8) D_800F19A4);
    p = (s32) D_800FAFF4[0];
    if (D_801517C0 == p) {
        p = (s32) D_800FAFF4[1];
    }
    D_801517C0 = p;
    D_800F8368 ^= 1;
    return r;
}

void func_800D8AF0(s16 arg0) {
    s32 temp_a0;

    D_8009A000 = arg0;
    temp_a0 = arg0 & 0xFFFF;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_800D8B2C(void) {
    if (D_80062D99 != 0) {
        func_800D8AF0(0x98);
    }
    D_80062D99 = 0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D8B60);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D8D78);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D91DC);

void func_800D93DC(void) {
}
