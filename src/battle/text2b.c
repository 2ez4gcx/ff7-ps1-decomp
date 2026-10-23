#include "common.h"
#include "battle/decls.h"

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800C7C4C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CD400);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CDE78);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CE0C8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CE21C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CE384);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CE638);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CF2F0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CF3CC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800CF4A8);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D0760);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D0B4C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D25E8);

void func_800D26F8(void) {
    D_800F01DC = &D_800F4BAC;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D2710);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D2828);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D3658);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D376C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D3994);

void func_800D3A6C(BtlMatrix *arg0, BtlSVec *arg1) {
    BtlMatrix m;

    arg1->vx = arg0->t[0] - D_800FA63C.t[0];
    arg1->vy = arg0->t[1] - D_800FA63C.t[1];
    arg1->vz = arg0->t[2] - D_800FA63C.t[2];
    func_8003BF3C(&D_800FA63C, &m, arg0);
    func_8003B2CC(&m, arg1, arg1);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D3AF0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D3BF0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D3D88);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D4284);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D4368);

void func_800D4484(s32 arg0, s32 arg1) {
    void *temp_s0;

    temp_s0 = D_80163C74;
    func_80044A68(temp_s0, 0, 1, arg1 & 0xFFFF, 0);
    func_80046794(arg0, (s32) temp_s0);
    D_80163C74 = temp_s0 + 0xC;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D44E8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D461C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D4710);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D491C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D4A64);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D4C08);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D52A0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D5350);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D54EC);

s32 func_800D55A4(s32 arg0) {
    return (D_801518EA[arg0].b * (D_801518EA[arg0].a << 4)) >> 12;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D55F4);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D57C0);

void func_800D58D0(s32 arg0, s32 arg1, s32 arg2) {
    B20 *p;

    p = &D_80162978[func_800BBEAC(&func_800D57C0)];
    p->a = 0;
    M2C_SFIELD(p, s16 *, 8) = arg0;
    p->d = arg2;
    p->c = arg1;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D5938);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D61AC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D6260);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D6394);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D6ACC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D6C20);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D6D8C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D6F78);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D70C0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D7178);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D7724);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2b", func_800D7C2C);

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
