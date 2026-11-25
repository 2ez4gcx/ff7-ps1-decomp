#include "common.h"
#include "battle/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
void func_800CD400(s16 arg0, s32 *arg1, s32 arg2);
typedef struct { s16 k; u8 pad[0xB9A]; } BtlB9Ck;
typedef struct { u8 f; u8 pad[0xB9B]; } BtlB9Cf;
extern BtlB9Ck D_801518F2[];
extern BtlB9Cf D_8015190B[];
s32 func_800D3520();

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

void func_800CD5E4(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    s32 t;
    s32 r;
    s32 c;
    s32 *q;

    q = (s32 *)0x1F800000;
    t = 0x800 - *(s16 *)&D_801518FC[arg1 & 0xFF];
    *q = t;
    *(s32 *)0x1F800004 = ((arg2 * D_801518EA[arg0 & 0xFF].a) >> 12) + ((D_801518F6[arg1 & 0xFF][0] * D_801518EA[arg1 & 0xFF].a) >> 12);
    D_80151A4C[arg0 & 0xFF].v.a = D_80151A4C[arg1 & 0xFF].v.a - ((func_80039A74(t) * *(s32 *)0x1F800004) >> 12);
    r = ((s32 (*)(s32))func_80039B40)(*q) * *(s32 *)0x1F800004;
    c = D_80151A4C[arg1 & 0xFF].v.c;
    D_80151A4C[arg0 & 0xFF].v.b = arg3;
    D_80151A4C[arg0 & 0xFF].v.c = c + (r >> 12);
    D_80151A46[arg0 & 0xFF][0] = *q;
}

void func_800CD798(u8 arg0) {
    D_80151A4C[arg0].v.a = D_80163C80[arg0].a;
    D_80151A4C[arg0].v.b = D_80163C80[arg0].b;
    D_80151A4C[arg0].v.c = D_80163C80[arg0].c;
}

void func_800CD82C(void) {
    D_801590DC = 1;
    D_801621F0[D_801590D4][0] = -1;
}

void func_800CD860(s16 arg0, s32 arg1, s16 arg2, void *arg3, u16 arg4, void *arg5) {
    s16 s0;
    s16 s1;
    s16 t0;
    s16 t1;
    s32 sum1;
    s32 cnt;
    s16 sumA;
    s16 sumB;
    s32 i;
    s32 mask;
    s32 off;
    s32 w0;
    s32 w1;

    if (D_801031F0 == 0) {
        s0 = 0x800 - D_8015122C[D_800F99E8][0];
        s1 = ((arg2 * D_801518EA[arg0].a) >> 12) + ((D_801518F6[D_800F99E8][0] * D_801518EA[D_800F99E8].a) >> 12);
    } else {
        sum1 = 0;
        cnt = 0;
        sumA = 0;
        sumB = 0;
        i = 0;
        mask = D_80151774;
        off = 0;
        for (; i < 10; i++) {
            if ((mask >> i) & 1) {
                cnt++;
                sum1 += *(s16 *)((u8 *)D_801518FC + off);
                sumB += *(u16 *)((u8 *)D_801518F6 + off);
                sumA += *(u16 *)((u8 *)D_801518EA + off);
            }
            off += 0xB9C;
        }
        sum1 = sum1 / (cnt & 0xFF);
        sumB = sumB / (cnt & 0xFF);
        sumA = sumA / (cnt & 0xFF);
        s0 = 0x800 - sum1;
        s1 = ((arg2 * D_801518EA[arg0].a) >> 12) + ((sumB * sumA) >> 12);
    }
    t0 = M2C_FIELD(arg5, u16 *, 0) - ((func_80039A74(s0) * s1) >> 12);
    t1 = M2C_FIELD(arg5, u16 *, 4) + ((func_80039B40(s0) * s1) >> 12);
    cnt = func_800BBF7C(arg3);
    D_801620B0[cnt & 0xFF].a6 = D_800F99E8;
    D_801620B0[cnt & 0xFF].a4 = arg0;
    if (D_800F99E8 == arg0) {
        D_801620B0[cnt & 0xFF].a8 = 0;
        D_801620B0[cnt & 0xFF].aA = 0;
    } else {
        D_801620B0[cnt & 0xFF].a8 = (t0 - (s16)D_80151A4C[arg0].v.a) / (s16)arg4;
        D_801620B0[cnt & 0xFF].aA = (t1 - (s16)D_80151A50[arg0][0]) / (s16)arg4;
    }
    w0 = *(s32 *)0x1F800000;
    w1 = *(s32 *)0x1F800004;
    D_801620B0[cnt & 0xFF].b15 = *(u8 *)0x1F800008;
    D_801620B0[cnt & 0xFF].b16 = *(u8 *)0x1F80000C;
    D_801620B0[cnt & 0xFF].a0 = arg4;
    D_801620B0[cnt & 0xFF].aC = w0;
    D_801620B0[cnt & 0xFF].b10 = w1;
    D_801620B0[cnt & 0xFF].b14 = D_80166F58;
}

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

void func_800CE384(void) {
    u8 cont;
    u8 *p;
    u8 n;
    s32 v;
    s32 a;
    s32 b;

    if (D_80151200[D_801621F0[D_801590D4][3]].pad2[0x26] != D_801621F0[D_801590D4][1]) {
        D_801621F0[D_801590D4][0] = -1;
        return;
    }
    if (D_801621F0[D_801590D4][2] != 0) {
        D_801621F0[D_801590D4][2] = D_801621F0[D_801590D4][2] - 1;
        return;
    }
    cont = 1;
    do {
        n = *((u8 *)D_801621F0 + 0x18 + (D_801590D4 << 5));
        p = *(u8 **)((u8 *)D_801621F0 + 0x10 + (D_801590D4 << 5));
        *((u8 *)D_801621F0 + 0x18 + (D_801590D4 << 5)) = n + 1;
        v = p[n];
        switch (v) {
        case 0xFD:
            cont = 0;
            a = p[(*((u8 *)D_801621F0 + 0x18 + (D_801590D4 << 5)))++];
            b = p[(*((u8 *)D_801621F0 + 0x18 + (D_801590D4 << 5)))++];
            D_801621F0[D_801590D4][2] = p[(*((u8 *)D_801621F0 + 0x18 + (D_801590D4 << 5)))++];
            D_8015122E[D_801621F0[D_801590D4][3]].v = a | (b << 8);
            break;
        case 0xFE:
            *((u8 *)D_801621F0 + 0x18 + (D_801590D4 << 5)) = 0;
            break;
        case 0xFF:
            D_801621F0[D_801590D4][0] = -1;
            cont = 0;
            break;
        default:
            cont = 0;
            break;
        }
    } while (cont);
}

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

void func_800CE7E0(void) {
    s32 n;
    s32 q;
    s32 r;

    if (D_8016297A[D_8015169C].c == 0) {
        if (D_8016297A[D_8015169C].d != -1) {
            func_800CE75C();
            n = func_800BC04C(func_800C2928);
            q = D_8015169C;
            q <<= 5;
            D_80162204[n][0] = *(s16 *)(D_80162984 + 2 + q);
            D_801621F0[n][7] = *(u16 *)(D_80162980 + 2 + q);
            *(s32 *)&D_801621F0[n][8] = *(s16 *)(D_80162980 + q);
            n = func_800BC04C(func_800CE638);
            r = D_8015169C;
            r <<= 5;
            D_801621F0[n][5] = D_80162990[1 + r];
            D_801621F0[n][4] = *(u16 *)(D_8016297E + r);
        }
        D_80162978[D_8015169C].a = -1;
    } else {
        D_8016297A[D_8015169C].c = D_8016297A[D_8015169C].c - 1;
    }
}

void func_800CE970(void) {
    s32 o;
    s32 o1;
    s32 o2;
    s32 o3;
    s32 j;
    s32 t;
    s32 raw;
    u8 pad[8];

    o = D_8015169C << 5;
    raw = *(s16 *)(D_8016297C + o);
    t = raw;
    if (t == 0) {
        if (*(u16 *)(D_80162984 + 2 + o) & 2) {
            D_80163C74 = ((u8 *(*)())func_800C4FC8)(0xFA, 0xFA, 0xFA);
        }
        o1 = D_8015169C << 5;
        if (*(s16 *)(D_8016297E + o1) != -1 && D_80162990[o1] != 1) {
            func_800CE75C();
            j = func_800BC04C(func_800C2928);
            o2 = D_8015169C << 5;
            D_80162204[j][0] = *(s16 *)(D_80162984 + 2 + o2);
            D_801621F0[j][7] = *(u16 *)(D_80162980 + 2 + o2);
            D_80162204[j][-1] = *(s16 *)(D_80162980 + o2);
            j = func_800BC04C(func_800CE638);
            o3 = D_8015169C << 5;
            D_801621F0[j][5] = D_80162990[1 + o3];
            D_801621F0[j][4] = *(u16 *)(D_8016297E + o3);
        }
        func_800CEB48();
    } else {
        *(s16 *)(D_8016297C + o) = t - 1;
    }
}

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

void func_800CF5BC(void) {
    s32 i;
    s32 k;
    s32 n;
    u8 c;
    s32 z;

    n = D_801590D0 << 5;
    i = *(s16 *)((u8 *)D_801620AC + n + 8);
    k = *(s16 *)((u8 *)D_801620AC + n + 10);
    z = *(s16 *)((u8 *)D_801620AC + n + 2);
    *(s32 *)0x1F80000C = i;
    *(s32 *)0x1F800008 = k;
    if (z == 0) {
        *(s16 *)((u8 *)D_801620AC + n + 2) = 1;
        if (i >= 4 && D_801031F0 == 0) {
            *(s16 *)((u8 *)D_801620AC + n + 6) = (((s16)D_80151A4C[k].v.b * D_801518EA[k].a >> 12) - ((s16)D_80151A4C[i].v.b * D_801518EA[i].a >> 12)) / *(s16 *)((u8 *)D_801620AC + n + 4);
        } else {
            *(s16 *)((u8 *)D_801620AC + n + 6) = 0;
        }
    }
    n = D_801590D0 << 5;
    c = *((u8 *)D_801620AC + 0x18 + n);
    if (c == 0) {
        D_80166F58 = 0;
        if (D_801620AC[D_801590D0][2] == 0) {
            D_801620AC[D_801590D0][0] = -1;
            return;
        }
        D_80151A4C[*(s32 *)0x1F80000C].v.a += *(u16 *)((u8 *)D_801620AC + n + 12);
        D_80151A4C[*(s32 *)0x1F80000C].v.c += *(u16 *)((u8 *)D_801620AC + n + 14);
        D_80151A4C[*(s32 *)0x1F80000C].v.b += *(u16 *)((u8 *)D_801620AC + n + 6);
        *(s16 *)((u8 *)D_801620AC + n + 4) -= 1;
    } else {
        c--;
        *((u8 *)D_801620AC + 0x18 + n) = c;
    }
}

void func_800CF8C0(s16 arg0, s16 arg1, s8 arg2) {
    s32 n;

    n = (u8)func_800BBF7C(func_800CFB14);
    D_801620AC[n][4] = arg0;
    D_801620AC[n][5] = D_800F99E8;
    D_801620AC[n][2] = arg1;
    *(s8 *)&D_801620AC[n][12] = arg2;
    if (D_800F99E8 == arg0) {
        D_801620AC[n][6] = 0;
        D_801620AC[n][7] = 0;
        D_801620AC[n][3] = 0;
    } else {
        D_801620AC[n][6] = ((s16)D_80163C80[arg0].a - (s16)D_80151A4C[arg0].v.a) / arg1;
        D_801620AC[n][7] = ((s16)D_80163C80[arg0].c - (s16)D_80151A4C[arg0].v.c) / arg1;
        D_801620AC[n][3] = ((s16)D_80163C80[arg0].b - (s16)D_80151A4C[arg0].v.b) / arg1;
    }
}

void func_800CFB14(void) {
    s16 i;
    u8 c;

    i = D_801620AC[D_801590D0][4];
    *(s32 *)0x1F80000C = i;
    *(s32 *)0x1F800008 = D_801620AC[D_801590D0][5];
    c = *((u8 *)D_801620AC + 0x18 + (D_801590D0 << 5));
    if (c == 0) {
        if (D_801620AC[D_801590D0][2] == 0) {
            D_801620AC[D_801590D0][0] = -1;
            return;
        }
        D_80151A4C[i].v.a += (u16)D_801620AC[D_801590D0][6];
        D_80151A4C[i].v.c += (u16)D_801620AC[D_801590D0][7];
        D_80151A4C[i].v.b += (u16)D_801620AC[D_801590D0][3];
        D_801620AC[D_801590D0][2]--;
    } else {
        c--;
        *((u8 *)D_801620AC + 0x18 + (D_801590D0 << 5)) = c;
    }
}

void func_800CFCB0(void) {
    s16 i;
    s32 c;
    s32 x;
    u8 k;

    if (D_801620AC[D_801590D0][2] == 0) {
        D_801620AC[D_801590D0][0] = -1;
        return;
    }
    i = D_801620AC[D_801590D0][4];
    x = D_801620AC[D_801590D0][5];
    c = *(s32 *)((u8 *)D_801620AC + 0x10 + (D_801590D0 << 5));
    *(s32 *)0x1F80000C = i;
    D_80151A4C[i].v.a += (u16)D_801620AC[D_801590D0][6];
    *(s32 *)0x1F800008 = x;
    *(s32 *)0x1F800010 = c;
    D_80151A4C[i].v.c += (u16)D_801620AC[D_801590D0][7];
    k = *((u8 *)D_801620AC + 0x18 + (D_801590D0 << 5));
    *((u8 *)D_801620AC + 0x18 + (D_801590D0 << 5)) = k + 1;
    D_80151A4C[i].v.b += D_800EEB28[c][k];
    D_801620AC[D_801590D0][2]--;
}

void func_800CFE60(void) {
    s32 i;
    s32 k;
    s32 n;
    s32 z;

    n = D_801590D0 << 5;
    i = *(s16 *)((u8 *)D_801620AC + n + 8);
    k = *(s16 *)((u8 *)D_801620AC + n + 10);
    z = *(s16 *)((u8 *)D_801620AC + n + 2);
    *(s32 *)0x1F80000C = i;
    *(s32 *)0x1F800008 = k;
    switch (z) {
    case 0:
        *(s16 *)((u8 *)D_801620AC + n + 2) = 1;
        *(s16 *)((u8 *)D_801620AC + n + 4) = *((u8 *)D_801620AC + n + 0x19);
        break;
    case 1:
        if (*(s16 *)((u8 *)D_801620AC + n + 4) == 0) {
            *(s16 *)((u8 *)D_801620AC + n + 2) = 2;
            *(s16 *)((u8 *)D_801620AC + n + 4) = *((u8 *)D_801620AC + n + 0x1A);
            *(s16 *)((u8 *)D_801620AC + n + 6) = (((s16)D_80151A4C[i].v.b - *(s32 *)((u8 *)D_801620AC + n + 0x10)) * D_801518EA[k].a >> 12) / *((u8 *)D_801620AC + n + 0x1A);
            break;
        }
        D_80151A4C[i].v.b += *(u16 *)((u8 *)D_801620AC + n + 0x14);
        *(s16 *)((u8 *)D_801620AC + n + 4) -= 1;
        break;
    case 2:
        if (*(s16 *)((u8 *)D_801620AC + n + 4) == 0) {
            *(s16 *)((u8 *)D_801620AC + n) = -1;
            break;
        }
        D_80151A4C[i].v.a += *(u16 *)((u8 *)D_801620AC + n + 12);
        D_80151A4C[i].v.c += *(u16 *)((u8 *)D_801620AC + n + 14);
        D_80151A4C[i].v.b -= *(u16 *)((u8 *)D_801620AC + n + 6);
        *(s16 *)((u8 *)D_801620AC + n + 4) -= 1;
        break;
    }
}

void func_800D01C0(void) {
    s32 i;
    s32 t;
    s16 v;

    i = D_801590D0;
    t = D_801620AC[i][4];
    *(s32 *)0x1F800008 = D_801620AC[i][5];
    *(s32 *)0x1F80000C = t;
    switch (D_801620AC[i][1]) {
    case 0:
        D_801620AC[i][2] = *((u8 *)D_801620AC + 0x1A + (i << 5));
        v = (*(s32 *)((u8 *)D_801620AC + 0x14 + (i << 5)) - (s16)D_80151A4C[t].v.b) / *((u8 *)D_801620AC + 0x1A + (i << 5));
        D_801620AC[i][1] = 1;
        D_801620AC[i][3] = v;
        break;
    case 1:
        if (D_801620AC[i][2] == 0) {
            D_801620AC[i][2] = *((u8 *)D_801620AC + 0x19 + (i << 5));
            v = ((*(s32 *)((u8 *)D_801620AC + 0x14 + (i << 5)) - *(s32 *)((u8 *)D_801620AC + 0x10 + (i << 5))) * D_801518EA[D_801620AC[i][5]].a >> 12) / *((u8 *)D_801620AC + 0x19 + (i << 5));
            D_801620AC[i][1] = 2;
            D_801620AC[i][3] = v;
        } else {
            D_80151A4C[t].v.a += D_801620AC[i][6];
            D_80151A50[t][0] += D_801620AC[i][7];
            D_80151A4C[t].v.b += D_801620AC[i][3];
            D_801620AC[i][2] -= 1;
        }
        break;
    case 2:
        if (D_801620AC[i][2] == 0) {
            D_801620AC[i][0] = -1;
        } else {
            D_80151A4C[t].v.b -= D_801620AC[i][3];
            D_801620AC[i][2] -= 1;
        }
        break;
    }
}

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

void func_800D0C80(u8 arg0) {
    s32 i;

    D_800F8CF0 = 0;
    func_800D1530();
    switch (D_80151906[arg0].a) {
    case 2:
        if (D_801031F0 == 0) {
            if (D_80151906[arg0].pad[0] == 0x19) {
                D_8015190A[0] = 1;
                D_801524A6 = 1;
                D_80153042 = 1;
            }
            D_800EFAF0[D_80151906[arg0].pad[0]](D_80151774, D_801590CC);
        } else {
            switch (D_80151906[arg0].pad[0]) {
            case 0x29:
                func_801B0000(D_80151774, D_801590CC);
                break;
            case 0x2C:
                D_801B0000(D_80151774, D_801590CC);
                break;
            case 0x23:
                func_801B000C(D_80151774, D_801590CC);
                break;
            case 0x20:
                func_801B0054(D_80151774, D_801590CC);
                break;
            case 0x1D:
                func_801B0084(D_80151774, D_801590CC);
                break;
            default:
                D_800EFAF0[D_80151906[arg0].pad[0]](D_80151774, D_801590CC);
                break;
            }
        }
        break;
    case 13:
        D_800EFBC8[D_80151906[arg0].pad[0]](D_80151774, D_801590CC);
        break;
    case 20:
        if (D_80151906[arg0].pad[0] == 2) {
            if (D_801590CC == D_800FA9E8) {
                D_80163A98 = 0;
            } else {
                D_80163A98 = 1;
            }
        }
        i = arg0;
        *(s32 *)0x1F800000 = D_800EFEA0[D_80151906[i].pad[0]](D_80151774, D_801590CC);
        switch (D_80151906[i].pad[0]) {
        case 0x2D:
        case 0x2E:
        case 0x2F:
        case 0x30:
        case 0x38:
        case 0x39:
        case 0x3A:
        case 0x3B:
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4A:
        case 0x4B:
        case 0x4C:
        case 0x4D:
        case 0x4F:
            *(s32 *)0x1F800000 = 0;
            break;
        }
        func_800D08B8(arg0, *(s32 **)0x1F800000);
        break;
    case 32:
        D_800EFC28[D_80151906[arg0].pad[0]](D_80151774, D_801590CC);
        break;
    case 3:
        func_800C64AC();
        break;
    }
}

void func_800D1110(s32 arg0) {
    switch (D_80151906[arg0 & 0xFF].a) {
    case 2:
        if (D_801031F0 == 0) {
            func_800D088C(D_800EEBB8[D_800EF63C[D_80151906[arg0 & 0xFF].pad[0]]].a, D_800EEBB8[D_800EF63C[D_80151906[arg0 & 0xFF].pad[0]]].b);
        } else {
            switch (D_80151906[arg0 & 0xFF].pad[0]) {
            case 29:
                func_800D088C(D_800EEE20, D_800EEE24);
                break;
            case 41:
                func_800D088C(D_800EECB8, D_800EECBC);
                break;
            case 44:
                func_800D088C(D_800EEC88, D_800EEC8C);
                break;
            case 32:
                func_800D088C(D_800EF3B0, D_800EF3B4);
                break;
            case 35:
                func_800D088C(D_800EEBE8, D_800EEBEC);
                break;
            default:
                func_800D088C(D_800EEBB8[D_800EF63C[D_80151906[arg0 & 0xFF].pad[0]]].a, D_800EEBB8[D_800EF63C[D_80151906[arg0 & 0xFF].pad[0]]].b);
                break;
            }
        }
        break;
    case 7:
        func_800D088C(D_800EF2A0, D_800EF2A4);
        break;
    case 8:
        func_800D088C(D_800EEBB8[D_800EF8D8[D_80151906[arg0 & 0xFF].pad[0]]].a, D_800EEBB8[D_800EF8D8[D_80151906[arg0 & 0xFF].pad[0]]].b);
        break;
    case 13:
        func_800D088C(D_800EEBB8[D_800EF6A8[D_80151906[arg0 & 0xFF].pad[0]]].a, D_800EEBB8[D_800EF6A8[D_80151906[arg0 & 0xFF].pad[0]]].b);
        break;
    case 20:
        func_800D088C(D_800EEBB8[D_800EF838[D_80151906[arg0 & 0xFF].pad[0]]].a, D_800EEBB8[D_800EF838[D_80151906[arg0 & 0xFF].pad[0]]].b);
        break;
    case 4:
        func_800D088C(D_800EEBB8[D_800EF5B0[D_80151906[arg0 & 0xFF].pad[0]]].a, D_800EEBB8[D_800EF5B0[D_80151906[arg0 & 0xFF].pad[0]]].b);
        break;
    case 32:
        func_800D088C(D_800EEBB8[D_800EF6FC[D_80151906[arg0 & 0xFF].pad[0]]].a, D_800EEBB8[D_800EF6FC[D_80151906[arg0 & 0xFF].pad[0]]].b);
        break;
    case 3:
        func_800D088C(D_800EEBB8[D_800EF6D8[D_80151906[arg0 & 0xFF].pad[0]]].a, D_800EEBB8[D_800EF6D8[D_80151906[arg0 & 0xFF].pad[0]]].b);
        break;
    }
}

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

s32 func_800D3520(arg0, arg1) {
    s16 *p;
    s32 off;
    s32 t;
    s32 d;

    off = *(s32 *)arg0;
    arg0 += 4;
    p = (s16 *)(arg0 + off);
    t = p[1];
    d = arg1 + t;
    *(volatile s16 *)&p[1] = d;
    return d;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D3544);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text2b", D_800A0D98);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text2b", D_800A0DB8);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text2b", D_800A0DC8);
