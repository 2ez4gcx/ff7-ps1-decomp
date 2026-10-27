#include "common.h"
#include "field/decls.h"

s32 func_800D2794(void) {
    u16 *temp_v1_2;
    u8 temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("bgscr", 8);
    }
    temp_v1 = M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 2);
    switch (temp_v1) {
    case 2:
        M2C_FIELD(D_8009C6E0, s16 *, 0xA6) = func_800BF908(1, 3);
        M2C_FIELD(D_8009C6E0, s16 *, 0xA8) = func_800BF908(2, 5);
        break;
    case 3:
        M2C_FIELD(D_8009C6E0, s16 *, 0xAA) = func_800BF908(1, 3);
        M2C_FIELD(D_8009C6E0, s16 *, 0xAC) = func_800BF908(2, 5);
        break;
    }
    temp_v1_2 = &D_800831FC[D_800722C4];
    *temp_v1_2 += 7;
    return 0;
}

s32 func_800D28A8(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("bgdph", 8);
    }
    switch ((D_8009C6DC + D_800831FC[D_800722C4])[2]) {
    case 2:
        M2C_SFIELD(D_8009C6E0, s16 *, 0xB0) = func_800BF908(1, 3);
        break;
    case 3:
        M2C_SFIELD(D_8009C6E0, s16 *, 0xAE) = func_800BF908(1, 3);
        break;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800D298C(void) {
    s32 v;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("smtra", 6);
    }
    v = (u8)func_800BEE10(1, 3);
    v |= (u8)func_800BEE10(2, 4) << 8;
    v |= (u8)func_800BEE10(3, 5) << 16;
    v |= func_800BEE10(4, 6) << 24;
    if (func_8002542C(v) == -1) {
        D_8009D5A7 = 0;
    } else {
        D_8009D5A7 = 1;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 7;
    return 0;
}

s32 func_800D2A70(void) {
    s32 c;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("dmtra", 7);
    }
    c = (u8)func_800BEE10(1, 3);
    c |= (u8)func_800BEE10(2, 4) << 8;
    c |= (u8)func_800BEE10(3, 5) << 16;
    c |= (u8)func_800BEE10(4, 6) << 24;
    ((void (*)(s32, s32))func_80025648)(c, (D_8009C6DC + D_800831FC[D_800722C4])[7]);
    pc = &D_800831FC[D_800722C4];
    *pc += 8;
    return 0;
}

s32 func_800D2B60(void) {
    s32 c;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("cmtra", 8);
    }
    c = (u8)func_800BEE10(1, 4);
    c |= (u8)func_800BEE10(2, 5) << 8;
    c |= (u8)func_800BEE10(3, 6) << 16;
    c |= (u8)func_800BEE10(4, 7) << 24;
    func_800BF3AC(6, 9, ((s32 (*)(s32, s32))func_80025650)(c, (D_8009C6DC + D_800831FC[D_800722C4])[8]));
    pc = &D_800831FC[D_800722C4];
    *pc += 10;
    return 0;
}

s32 func_800D2C60(void) {
    s32 a;
    s32 v;

    if (D_8009D820 & 3) {
        func_800BEAD4(&D_800A0F38, 3);
    }
    if (D_8009D820 & 3) {
        func_800BECA4(D_800A0848, D_8009C6E0[1], 2);
    }
    a = D_8009C6E0[1];
    if (a == 0) {
        D_8009C6E0[1] = (D_8009C6DC + D_800831FC[D_800722C4])[2];
        v = func_800BEE10(2, 3);
        D_8007EBE0 = 1;
        M2C_FIELD(D_8009C6E0, s16 *, 2) = v & 0xFF;
        M2C_FIELD(D_8009C6E0, s16 *, 0x26) = 0;
        if ((M2C_FIELD(D_8009C6E0, s32 *, 0) & ~0xFF) == 0x900) {
            D_800831FC[D_800722C4] += 4;
        }
        return 1;
    }
    if (a == (D_8009C6DC + D_800831FC[D_800722C4])[2]) {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A08D0, M2C_FIELD(D_8009C6E0, s16 *, 0x26), 1);
        }
        if (M2C_FIELD(D_8009C6E0, s16 *, 0x26) == 2) {
            D_800831FC[D_800722C4] += 4;
            D_8009C6E0[1] = 0;
            M2C_FIELD(D_8009C6E0, s16 *, 0x26) = 0;
            func_800CF60C();
            return 0;
        }
    } else if ((D_8009C6DC + D_800831FC[D_800722C4])[2] == 0x14) {
        if (a == 4) {
            D_8009C6E0[1] = (D_8009C6DC + D_800831FC[D_800722C4])[2];
            M2C_FIELD(D_8009C6E0, s16 *, 0x26) = 0;
        }
    }
    return 1;
}

s32 func_800D2E94(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4(&D_800A0F38, 1);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x34) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text5", D_800A0F38);

s32 func_800D2F3C(void) {
    u16 *pc;
    s32 i;

    if (D_8009D820 & 3) {
        func_800BEAD4("getpc", 3);
    }
    i = (D_8009C6DC + D_800831FC[D_800722C4])[2];
    if (i < 3) {
        func_800BF3AC(2, 3, D_8009CBDC[i]);
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 4;
    return 0;
}

s32 func_800D3004(void) {
    s32 a;
    s32 b;
    u16 *p;
    s16 *q;

    if (D_8009D820 & 3) {
        func_800BEAD4("mpara", 4);
    }
    a = (D_8009C6DC + D_800831FC[D_800722C4])[2];
    b = func_800BEE10(1, 3) & 0xFF;
    D_800E4214[a][b] = (D_8009C6DC + D_800831FC[D_800722C4])[1] & 0xF;
    q = D_800E4D48[a];
    p = &D_800831FC[D_800722C4];
    q[b] = (D_8009C6DC + *p)[4];
    *p += 5;
    return 0;
}

s32 func_800D3124(void) {
    s32 a;
    s32 b;
    u16 *p;
    s16 *q;

    if (D_8009D820 & 3) {
        func_800BEAD4("mpra2", 5);
    }
    a = (D_8009C6DC + D_800831FC[D_800722C4])[2];
    b = func_800BEE10(1, 3) & 0xFF;
    D_800E4214[a][b] = (D_8009C6DC + D_800831FC[D_800722C4])[1] & 0xF;
    q = D_800E4D48[a];
    p = &D_800831FC[D_800722C4];
    q[b] = (D_8009C6DC + *p)[4];
    q[b] |= (D_8009C6DC + *p)[5] << 8;
    *p += 6;
    return 0;
}

s32 func_800D3264(void) {
    s32 v;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("sin", 8);
    }
    v = func_80039A74((s16)func_800BF908(1, 3));
    v *= (s16)func_800BF908(2, 5);
    v += (s16)func_800BF908(3, 7);
    func_800C0248(4, 9, (v << 4) >> 16);
    pc = &D_800831FC[D_800722C4];
    *pc += 10;
    return 0;
}

s32 func_800D3330(void) {
    s32 v;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("cos", 8);
    }
    v = func_80039B40((s16)func_800BF908(1, 3));
    v *= (s16)func_800BF908(2, 5);
    v += (s16)func_800BF908(3, 7);
    func_800C0248(4, 9, (v << 4) >> 16);
    pc = &D_800831FC[D_800722C4];
    *pc += 10;
    return 0;
}

void func_800D33FC(void) {
    s16 i;

    for (i = 0; i < 3; i++) {
        if (D_8009CBDC[i] != 0xFF) {
            func_80020058(i);
            func_8001786C(i);
        }
    }
    func_80017678();
}

void func_800D348C(void) {
    s32 i;
    u8 c;
    s32 v;

    func_800D33FC();
    for (i = 0; i < 3; i++) {
        func_800258BC(i, 10000);
        func_80025A44(i, 10000);
        c = D_8009CBDC[i];
        if (c != 0xFF) {
            v = D_800491D0[c];
            if (v < 9) {
                D_8009C738[v][0x1F] = 0;
            }
        }
    }
}

s32 func_800D3548(void) {
    u8 buf[3];
    s32 i;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("mhmmx", 0);
    }
    for (i = 0; i < 3; i++) {
        buf[i] = D_8009CBDC[i];
    }
    for (i = 0; i < 3; i++) {
        D_8009CBDC[i] = i;
    }
    func_800D348C();
    for (i = 0; i < 3; i++) {
        D_8009CBDC[i] = i + 3;
    }
    func_800D348C();
    for (i = 0; i < 3; i++) {
        D_8009CBDC[i] = i + 6;
    }
    func_800D348C();
    for (i = 0; i < 3; i++) {
        D_8009CBDC[i] = buf[i];
    }
    func_800D348C();
    pc = &D_800831FC[D_800722C4];
    *pc += 1;
    return 0;
}

s32 func_800D368C(void) {
    s32 i;
    u16 *temp_v0;

    if (D_8009D820 & 3) {
        func_800BEAD4("hmpmx", 0);
    }
    func_800D33FC();
    for (i = 0; i < 3; i++) {
        func_800258BC(i, 0x2710);
        func_80025A44(i, 0x2710);
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 1;
    return 0;
}

s32 func_800D3728(void) {
    s32 i;
    s32 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("mp+", 4);
    }
    func_800D33FC();
    c = (D_8009C6DC + D_800831FC[D_800722C4])[2];
    if (D_8009D391[c] != 0xFF) {
        c = D_8009D391[c];
        for (i = 0; i < 3; i++) {
            if (D_8009CBDC[i] == c) {
                func_80025A44(i, (s16)func_800BF908(2, 3));
            }
        }
    }
    D_800831FC[D_800722C4] += 5;
    return 0;
}

s32 func_800D3840(void) {
    s32 i;
    s32 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("mp-", 4);
    }
    func_800D33FC();
    c = (D_8009C6DC + D_800831FC[D_800722C4])[2];
    if (D_8009D391[c] != 0xFF) {
        c = D_8009D391[c];
        for (i = 0; i < 3; i++) {
            if (D_8009CBDC[i] == c) {
                func_80025988(i, (s16)func_800BF908(2, 3));
            }
        }
    }
    D_800831FC[D_800722C4] += 5;
    return 0;
}

s32 func_800D3958(void) {
    s32 i;
    s32 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("hp+", 4);
    }
    func_800D33FC();
    c = (D_8009C6DC + D_800831FC[D_800722C4])[2];
    if (D_8009D391[c] != 0xFF) {
        c = D_8009D391[c];
        for (i = 0; i < 3; i++) {
            if (D_8009CBDC[i] == c) {
                func_800258BC(i, (s16)func_800BF908(2, 3));
            }
        }
    }
    D_800831FC[D_800722C4] += 5;
    return 0;
}

s32 func_800D3A70(void) {
    s32 i;
    s32 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("hp-", 4);
    }
    func_800D33FC();
    c = (D_8009C6DC + D_800831FC[D_800722C4])[2];
    if (D_8009D391[c] != 0xFF) {
        c = D_8009D391[c];
        for (i = 0; i < 3; i++) {
            if (D_8009CBDC[i] == c) {
                func_80025800(i, (s16)func_800BF908(2, 3));
            }
        }
    }
    D_800831FC[D_800722C4] += 5;
    return 0;
}

s32 func_800D3B88(void) {
u32 a;
    if (D_8009D820 & 3) {
        func_800BEAD4("gold+", 5);
    }
a = func_800BF908(1, 2) & 0xFFFF; a |= func_800BF908(2, 4) << 16; func_80025B48(a);
    D_800831FC[D_800722C4] += 6;
    return 0;
}

s32 func_800D3C18(void) {
u32 a;
    if (D_8009D820 & 3) {
        func_800BEAD4("gold-", 5);
    }
a = func_800BF908(1, 2) & 0xFFFF; a |= func_800BF908(2, 4) << 16; func_80025B10(a);
    D_800831FC[D_800722C4] += 6;
    return 0;
}

s32 func_800D3CA8(void) {
    s32 temp_v0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("chgld", 3);
    }
    temp_v0 = func_80025B7C();
    func_800C0248(1, 2, temp_v0);
    func_800C0248(2, 3, temp_v0 >> 0x10);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800D3D40(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("chmph", 3);
    }
    func_800C0248(1, 2, D_8009A162);
    func_800BF3AC(2, 3, D_8009A15C);
    p = &D_800831FC[D_800722C4];
    *p += 4;
    return 0;
}

s32 func_800D3DCC(void) {
    u16 *temp_v0;
    u8 temp_v1;
    u8 var_a2;

    if (D_8009D820 & 3) {
        func_800BEAD4("chmst", 2);
    }
    temp_v1 = D_8009A108 != 0;
    var_a2 = temp_v1;
    if (D_80099FCC != 0) {
        var_a2 = temp_v1 | 2;
    }
    func_800BF3AC(2, 2, var_a2);
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 3;
    return 0;
}

s32 func_800D3E64(void) {
    s32 v;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("sttim", 5);
    }
    v = (u8)func_800BEE10(1, 3) * 3600;
    v += (u8)func_800BEE10(2, 4) * 60;
    v += (u8)func_800BEE10(4, 5);
    *(volatile s32 *)&D_8009D268 = v;
    pc = &D_800831FC[D_800722C4];
    *pc += 6;
    return 0;
}

s32 func_800D3F30(void) {
    u16 *pc;
    u8 i;

    if (D_8009D820 & 3) {
        func_800BEAD4("wspcl", 5);
    }
    i = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    D_8008328F[i].v = (D_8009C6DC + D_800831FC[D_800722C4])[2];
    pc = &D_800831FC[D_800722C4];
    D_8008329C[i].v = (D_8009C6DC + *pc)[3];
    D_8008329E[i].v = (D_8009C6DC + *pc)[4];
    *pc += 5;
    return 0;
}

s32 func_800D4038(void) {
    s32 i;
    s32 v;

    if (D_8009D820 & 3) {
        func_800BEAD4("wnumb", 7);
    }
    i = (D_8009C6DC + D_800831FC[D_800722C4])[2];
    v = (s16)func_800BF908(1, 3);
    v |= func_800BF908(2, 5) << 16;
    D_80083290[i].v4 = v;
    D_80083290[i].b1 = (D_8009C6DC + D_800831FC[D_800722C4])[7];
    D_800831FC[D_800722C4] += 8;
    return 0;
}

s32 func_800D4160(void) {
    u16 *temp_a0;
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("btlmd", 2);
    }
    temp_a0 = &D_800831FC[D_800722C4];
    M2C_FIELD(D_8009C6E0, s16 *, 0x3E) = (s16) M2C_FIELD(&D_8009C6DC[*temp_a0], u8 *, 1);
    M2C_FIELD(D_8009C6E0, u8 *, 0x3D) = (u8) M2C_FIELD(&D_8009C6DC[*temp_a0], u8 *, 2);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 3;
    return 0;
}

s32 func_800D4214(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("btmd2", 2);
    }
    M2C_SFIELD(D_8009C6E0, s16 *, 0x3E) = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    M2C_SFIELD(D_8009C6E0, s16 *, 0x3E) |= (D_8009C6DC + D_800831FC[D_800722C4])[2] << 8;
    M2C_SFIELD(D_8009C6E0, u8 *, 0x3D) = (D_8009C6DC + D_800831FC[D_800722C4])[3];
    M2C_SFIELD(D_8009C6E0, u8 *, 0x3D) &= 0xFF;
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800D4300(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("btrlt", 2);
    }
    func_800C0248(2, 2, *D_800707BE);
    D_800831FC[D_800722C4] += 3;
    return 0;
}

s32 func_800D4378(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("btltb", 1);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x3C) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800D4420(void) {
    u16 *temp_v0;
    u8 temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("blink", 8);
    }
    temp_a0 = D_8007EB98[D_800722C4];
    if (temp_a0 != 0xFF) {
        M2C_FIELD(((temp_a0 * 0x84) + D_8009C544), u8 *, 8) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 2;
    return 0;
}

s32 func_800D44E8(void) {
    u8 i;
    u8 b1;
    u8 v;
    u8 t;
    u8 *q;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("kawai", 8);
    }
    i = D_8007EB98[D_800722C4];
    b1 = M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    if (i != 0xFF) {
        t = M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 2);
        (D_8004A62C[1] + ((u8 *)D_8008357C)[i * 8 + 4] * 0x24)[1] = t;
        ((FdKw84 *)D_8009C544)[D_8007EB98[D_800722C4]].a = 1;
        v = t;
        ((FdKw84 *)D_8009C544)[D_8007EB98[D_800722C4]].b = 0;
        ((FdKw84 *)D_8009C544)[D_8007EB98[D_800722C4]].c = &D_8009C6DC[D_800831FC[D_800722C4]] + 3;
    }
    if (v == 0) {
        q = ((FdKw84 *)D_8009C544)[D_8007EB98[D_800722C4]].c;
        if (q[0] == 1 && q[1] == q[0] && q[2] == 0) {
            ((FdKw84 *)D_8009C544)[D_8007EB98[D_800722C4]].d8 = 0;
            ((FdKw84 *)D_8009C544)[D_8007EB98[D_800722C4]].d9 = 0;
        } else {
            ((FdKw84 *)D_8009C544)[D_8007EB98[D_800722C4]].d8 = 1;
        }
    }
    pc = &D_800831FC[D_800722C4];
    { u32 w = *pc; w += b1; *pc = w; }
    return 0;
}

s32 func_800D4780(void) {
    s16 *p;
    u8 i;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("kawiw", 0);
    }
    i = D_8007EB98[D_800722C4];
    if (i != 0xFF) {
        p = (s16 *)(D_8009C544 + i * 0x84);
        if (*p == 1) {
            return 1;
        }
        pc = &D_800831FC[D_800722C4];
        *p = 0;
        *pc += 1;
        return 0;
    }
    D_800831FC[D_800722C4] += 1;
    return 0;
}

void func_800D4838(void) {
}

void func_800D4840(void) {
}

void func_800D4848(s32 arg0) {
    func_800D828C(0, 0x64, 0x64, 0x96, 0xC);
    func_800DA214(0, 0x7F, 0, 0);
    func_800D9F00(0, arg0);
    D_80095DCC = 1;
    D_80099FFC = 4;
}

void func_800D48C0(void) {
    s32 i;
    u16 off;

    D_80071E2C = 0;
    for (i = 0; i < 4; i++) {
        func_800D493C(i);
    }
    off = M2C_FIELD(D_8009C6DC, u16 *, 4);
    if (off != 0) {
        D_8007E7A8 = &D_8009C6DC[off];
    } else {
        D_8007E7A8 = NULL;
    }
}

void func_800D493C(s16 n) {
    s16 (*pb)[8];
    u8 (*pa)[8];
    s32 i;
    u8 *a;
    s16 *b;

    if (n == 1) {
        D_800832AA = 8;
    } else {
        D_8008327A[n].v = 0x95;
    }
    i = 0;
    D_80083278[n].v = 8;
    pb = D_800E4D48;
    b = pb[n];
    pa = D_800E4214;
    a = pa[n];
    D_8008327C[n].a = 0x130;
    D_8008327C[n].b = 0x49;
    D_80083280[n].v = 1;
    D_80083282[n].v = 1;
    D_800832A0[n].v = 0;
    D_8008328D[n].v = 0;
    D_8008328F[n].v = 0;
    D_80083290[n].pad0[0] = 0;
    D_80083290[n].b1 = 6;
    D_8008329C[n].v = 0;
    D_8008329E[n].v = 0;
    D_800832A2[n].v = 0;
    D_8008326C[n] = 0xFF;
    for (; i < 8; i++) {
        *a = 0;
        *b = 0;
        b++;
        a++;
    }
    D_8011445C[n] = 0;
    if (D_8009D820 & 3) {
        func_800BECA4("mes reset=", n, 1);
    }
}

s32 func_800D4B28(s32 arg0) {
    switch (D_800832A0[(s16)arg0].v) {
    case 1:
        return 0;
    case 2:
    case 4:
    case 6:
    case 8:
    case 11:
    case 13:
        D_800832A0[(s16)arg0].v = 7;
    case 3:
    case 5:
    case 7:
    case 9:
    case 10:
    case 12:
        break;
    }
    return 1;
}

void func_800D4BC0(s16 arg0, s8 arg1, s16 arg2) {
    D_8008327C[arg0].x11 = arg1;
    D_8008327C[arg0].y26 = arg2;
}

void func_800D4BFC(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800832A0[i].v = 0;
        D_80083286[i].v = 0;
        D_8008326C[i] = 0xFF;
        D_8011445C[i] = 0;
    }
    D_80071E2C = 0;
}

void func_800D4C68(s16 n, s16 x, s16 y, s16 w, s16 h) {
    if (x < 8) {
        if (D_8009D820 & 3) {
            func_800BECA4("win limit x=", x, 2);
        }
        x = 8;
    }
    if (x + w > 0x138) {
        if (D_8009D820 & 3) {
            func_800BECA4("win limit x=", x + w, 3);
        }
        x = 0x138 - w;
    }
    if (y < 8) {
        if (D_8009D820 & 3) {
            func_800BECA4("win limit y=", y, 2);
        }
        y = 8;
    }
    if (y + h > 0xE0) {
        if (D_8009D820 & 3) {
            func_800BECA4("win limit y=", y + h, 3);
        }
        y = 0xE0 - h;
    }
    D_80083278[n].v = x;
    D_8008327A[n].v = y;
    D_8008327C[n].a = w;
    D_8008327C[n].b = h;
}

void func_800D4E24(s16 arg0, s32 arg1, s32 arg2) {
    D_80083278[arg0].v += arg1;
    D_8008327A[arg0].v += arg2;
}

void func_800D4E88(s16 arg0, s16 arg1) {
    D_8008327C[arg0].b = arg1;
}

s32 func_800D4EB4(u8 arg0, u8 arg1) {
    s16 t;
    s32 w;
    s32 y;
    s32 x;

    switch (D_800832A0[arg0].v) {
    case 0:
        if (func_800D579C(arg0, arg1) != 0) {
            return 1;
        }
        break;
    case 1:
        func_800D5A60(arg0);
        return 0;
    case 2:
        func_800D5C9C(arg0);
        return 0;
    case 8:
        func_800D6D44(arg0);
        return 0;
    case 12:
        func_800D6E0C(arg0);
        return 0;
    case 13:
        if (M2C_FIELD(D_8009C6E0, s32 *, 0x80) & 0x20) {
            D_800832A0[arg0].v = 2;
            return 0;
        }
        break;
    case 3:
        t = D_8011445C[arg0];
        if (t == 0) {
            D_800832A0[arg0].v = 2;
            return 0;
        }
        D_8011445C[arg0] = t - 1;
        break;
    case 4:
        if (M2C_FIELD(D_8009C6E0, s32 *, 0x80) & 0x20) {
            w = D_8008328A[arg0].v;
            y = (D_8008327C[arg0].b - 9) / 16;
            x = D_801142CC[arg0] - 1;
            if (w == y + x) {
                D_800832A0[arg0].v = 8;
                D_80083284[arg0].v = D_80083284[arg0].v - 2;
                D_801142CC[arg0] = D_801142CC[arg0] + 1;
                break;
            }
            return 0;
        }
        break;
    case 6:
        if (*(u16 *)((u8 *)D_800832A0 + 2 + arg0 * 0x30) & 1) {
            return 0;
        }
        if (M2C_FIELD(D_8009C6E0, s32 *, 0x80) & 0x20) {
            D_800832A0[arg0].v = 7;
            func_800D707C(arg0);
            return 0;
        }
        break;
    case 14:
        if (!(M2C_FIELD(D_8009C6E0, s32 *, 0x80) & 0x20)) {
            break;
        }
        goto l9;
    case 11:
        if (M2C_FIELD(D_8009C6E0, s32 *, 0x80) & 0x20) {
            D_800832A0[arg0].v = 0xC;
            D_800E4248[arg0 + 2] = D_8008328A[arg0].v * 0x10 + 0x11;
            D_80083284[arg0].v = D_80083284[arg0].v - 2;
            do {
            } while (0);
            return 0;
        }
        break;
    case 9:
l9:
        func_800D6F6C(arg0);
        return 0;
    case 5:
    case 7:
        if (func_800D707C(arg0) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

s32 func_800D5228(u8 arg0, u8 arg1, u8 arg2, u8 arg3, s16 *arg4) {
    s16 t;
    s32 w;
    s32 y;
    s32 x;

    switch (D_800832A0[arg0].v) {
    case 0:
        if (func_800D579C(arg0, arg1) != 0) {
            return 1;
        }
        break;
    case 1:
        func_800D5A60(arg0);
        return 0;
    case 2:
        func_800D5C9C(arg0);
        return 0;
    case 8:
        func_800D6D44(arg0);
        return 0;
    case 12:
        func_800D6E0C(arg0);
        return 0;
    case 13:
        if (M2C_FIELD(D_8009C6E0, s32 *, 0x80) & 0x20) {
            D_800832A0[arg0].v = 2;
            return 0;
        }
        break;
    case 3:
        t = D_8011445C[arg0];
        if (t == 0) {
            D_800832A0[arg0].v = 2;
            return 0;
        }
        D_8011445C[arg0] = t - 1;
        break;
    case 4:
        if (M2C_FIELD(D_8009C6E0, s32 *, 0x80) & 0x20) {
            w = D_8008328A[arg0].v;
            y = (D_8008327C[arg0].b - 9) / 16;
            x = D_801142CC[arg0] - 1;
            if (w == y + x) {
                D_800832A0[arg0].v = 8;
                D_80083284[arg0].v = D_80083284[arg0].v - 2;
                D_801142CC[arg0] = D_801142CC[arg0] + 1;
                break;
            }
            return 0;
        }
        break;
    case 6:
        if (*(u16 *)((u8 *)D_800832A0 + 2 + arg0 * 0x30) & 1) {
            return 0;
        }
        D_8008328E[arg0].v = 1;
        if (M2C_FIELD(D_8009C6E0, s32 *, 0x70) & 0x1000) {
            if (arg2 < *arg4) {
                func_800D5750();
            }
            *arg4 = *arg4 - 1;
        }
        if (M2C_FIELD(D_8009C6E0, s32 *, 0x70) & 0x4000) {
            if (*arg4 < arg3) {
                func_800D5750();
            }
            *arg4 = *arg4 + 1;
        }
        if (*arg4 < arg2) {
            *arg4 = arg2;
        }
        if (arg3 < *arg4) {
            *arg4 = arg3;
        }
        D_80083298[arg0].v = 5;
        D_8008329A[arg0].v = *arg4 * 0x10 + 6;
        if (M2C_FIELD(D_8009C6E0, s32 *, 0x80) & 0x20) {
            func_800D5750();
            D_800832A0[arg0].v = 7;
            func_800D707C(arg0);
            return 0;
        }
        break;
    case 14:
        if (!(M2C_FIELD(D_8009C6E0, s32 *, 0x80) & 0x20)) {
            break;
        }
        goto l9;
    case 11:
        if (M2C_FIELD(D_8009C6E0, s32 *, 0x80) & 0x20) {
            D_800832A0[arg0].v = 0xC;
            D_800E4248[arg0 + 2] = D_8008328A[arg0].v * 0x10 + 0x11;
            D_80083284[arg0].v = D_80083284[arg0].v - 2;
            do {
            } while (0);
            return 0;
        }
        break;
    case 9:
l9:
        func_800D6F6C(arg0);
        return 0;
    case 5:
    case 7:
        if (func_800D707C(arg0) != 0) {
            D_8008328E[arg0].v = 0;
            return 1;
        }
        D_8008328E[arg0].v = D_8008328E[arg0].v ^ 1;
        break;
    }
    return 0;
}

void func_800D5750(void) {
    func_800C46A4();
    D_8009A000 = 0x30;
    D_8009A004 = 1;
    D_8009A008 = 0x40;
    func_8002DA7C();
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text5", func_800D579C);

void func_800D5A60(s16 n) {
    if (D_8008326C[n] != D_800722C4) {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A10EC, n, 1);
        }
    } else {
        D_80083280[n].v += D_8008327C[n].a / 4;
        if (D_80083280[n].v < 8) {
            D_80083280[n].v = 8;
        }
        if (D_8008327C[n].a < D_80083280[n].v) {
            D_80083280[n].v = D_8008327C[n].a;
        }
        D_80083282[n].v += D_8008327C[n].b / 4;
        if (D_80083282[n].v < 8) {
            D_80083282[n].v = 8;
        }
        if (D_8008327C[n].b < D_80083282[n].v) {
            D_80083282[n].v = D_8008327C[n].b;
        }
        if (D_80083280[n].v == D_8008327C[n].a) {
            if (D_80083282[n].v == D_8008327C[n].b) {
                D_800832A0[n].v = 2;
            }
        }
    }
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text5", D_800A10DC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text5", D_800A10EC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text5", func_800D5C9C);

void func_800D6D44(s16 arg0) {
    if (D_8008326C[arg0] != D_800722C4) {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A10EC, arg0, 1);
        }
    } else {
        if (D_80083284[arg0].v & 0xF) {
            D_80083284[arg0].v -= 2;
        } else {
            D_800832A0[arg0].v = 2;
        }
    }
}

void func_800D6E0C(s16 arg0) {
    if (D_8008326C[arg0] != D_800722C4) {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A10EC, arg0, 1);
        }
    } else {
        if ((s16)D_80083284[arg0].v + D_800E424C[arg0] > 0) {
            D_80083284[arg0].v -= D_80114480[arg0] >> 2;
            if (M2C_FIELD(D_8009C6E0, s32 *, 0x78) & 0x20) {
                if (++D_80114480[arg0] > 0x80) {
                    D_80114480[arg0] = 0x80;
                }
            } else {
                if (--D_80114480[arg0] < 2) {
                    D_80114480[arg0] = 1;
                }
            }
        } else {
            D_800832A0[arg0].v = 9;
        }
    }
}

void func_800D6F6C(s16 arg0) {
    if (D_8008326C[arg0] != D_800722C4) {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A10EC, arg0, 1);
        }
    } else {
        D_800832A0[arg0].v = 2;
        D_80083288[arg0].v = 0;
        D_80083286[arg0].v = 0;
        D_80083284[arg0].v = 0;
        D_8008328A[arg0].v = 0;
        D_800E4944[arg0][0] = 0xFF;
        D_801142CC[arg0] = 0;
        D_80114480[arg0] = 1;
    }
}

s32 func_800D707C(s16 n) {
    s16 v;
    s16 u;

    if (D_8008326C[n] != D_800722C4) {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A10EC, n, 1);
        }
    } else {
        v = D_80083280[n].v;
        D_80083280[n].v = v < 8 ? 8 : v - D_8008327C[n].a / 4;
        u = D_80083282[n].v;
        D_80083282[n].v = u < 8 ? 8 : u - D_8008327C[n].b / 4;
        if (D_80083280[n].v < 9) {
            if (D_80083282[n].v < 9) {
                D_80083286[n].v = 0;
                do {
                } while (0);
                D_800832A0[n].v = 0;
                D_8008326C[n] = 0xFF;
                D_80071E2C--;
                return 1;
            }
        }
        return 0;
    }
}

u16 func_800D726C(s16 arg0) {
    u16 v;
    u16 i;

    switch (D_800E4214[arg0][D_800E4280[arg0]]) {
    case 0:
        v = D_800E4D48[arg0][D_800E4280[arg0]];
        break;
    case 1:
        v = D_8009D288[(u16)D_800E4D48[arg0][D_800E4280[arg0]]];
        break;
    case 2:
        i = D_800E4D48[arg0][D_800E4280[arg0]];
        v = D_8009D288[i] | (D_8009D289[i] << 8);
        break;
    case 3:
        v = D_8009D288[(u16)(D_800E4D48[arg0][D_800E4280[arg0]] + 0x100)];
        break;
    case 4:
        i = D_800E4D48[arg0][D_800E4280[arg0]] + 0x100;
        v = D_8009D288[i] | (D_8009D289[i] << 8);
        break;
    case 11:
        v = D_8009D288[(u16)(D_800E4D48[arg0][D_800E4280[arg0]] + 0x200)];
        break;
    case 12:
        i = D_800E4D48[arg0][D_800E4280[arg0]] + 0x200;
        v = D_8009D288[i] | (D_8009D289[i] << 8);
        break;
    case 13:
        v = D_8009D288[(u16)(D_800E4D48[arg0][D_800E4280[arg0]] + 0x300)];
        break;
    case 15:
        v = D_8009D288[(u16)(D_800E4D48[arg0][D_800E4280[arg0]] + 0x400)];
        break;
    case 14:
        i = D_800E4D48[arg0][D_800E4280[arg0]] + 0x300;
        v = D_8009D288[i];
        v = v | (D_8009D289[i] << 8);
        break;
    case 7:
        i = D_800E4D48[arg0][D_800E4280[arg0]] + 0x400;
        v = D_8009D288[i] | (D_8009D289[i] << 8);
        break;
    case 5:
        v = D_80075E24[(u16)D_800E4D48[arg0][D_800E4280[arg0]]];
        break;
    case 6:
        i = D_800E4D48[arg0][D_800E4280[arg0]];
        v = D_80075E24[i] | (D_80075E24[i + 1] << 8);
        break;
    default:
        v = 0;
        break;
    }
    return v;
}

void func_800D775C(u16 val, u8 *buf) {
    s16 div;
    s16 n;
    s16 d;
    s32 started;

    started = 0;
    div = 10000;
    n = 0;
    do {
        d = val / div;
        if (started || d != 0) {
            started = 1;
            buf[n] = D_800E0738[d];
            n++;
        }
        val -= d * div;
        div /= 10;
    } while (div >= 2);
    buf[n] = D_800E0738[val];
    buf[n + 1] = 0xFF;
}

void func_800D785C(u16 val, u8 *buf) {
    s32 started;
    s16 div;
    s16 i;
    s16 q;

    started = 0;
    div = 10000;
    i = 0;
    do {
        q = val / div;
        if (started || q != 0) {
            started = 1;
            buf[i] = D_800E0738[q];
            i++;
        } else {
            buf[i] = 0;
            i++;
        }
        val -= q * div;
        div /= 10;
    } while (div >= 2);
    buf[i] = D_800E0738[val];
    buf[i + 1] = 0xFF;
}

void func_800D7970(u16 val, u8 *buf) {
    s16 div;
    s16 n;
    s16 d;
    s32 started;
    

    started = 0;
    div = 0x1000;
    n = 0;
    do {
        d = val / div;
        if (started || d != 0) {
            started = 1;
            buf[n] = D_800E0738[d];
            n++;
        }
        val -= d * div;
        div /= 16;
    } while (div >= 2);
    buf[n] = D_800E0738[val];
    buf[n + 1] = 0xFF;
}

s32 func_800D7A58(s16 arg0) {
    u8 *s;
    u8 *p;
    s16 n;
    s16 k;
    u8 two;
    u8 hi;
    u8 lo;

    if (D_8007E7A8 == NULL) {
        func_800D4848(D_800A10DC);
        return 0;
    }
    s = D_8007E7A8;
    k = 0;
    n = 0;
    two = 2;
    lo = s[arg0 * two + two];
    hi = s[arg0 * 2 + 3];
    s += lo;
    s += hi << 8;
    do {
        switch (*s) {
        case 0xE2:
            D_8009D5F0[n] = 0xC;
            n++;
            D_8009D5F0[n] = 0;
            n++;
            s++;
            break;
        case 0xE3:
            s++;
            D_8009D5F0[n] = 0xE;
            n++;
            D_8009D5F0[n] = two;
            n++;
            break;
        case 0xE4:
            s++;
            D_8009D5F0[n] = 0xA9;
            n++;
            D_8009D5F0[n] = two;
            n++;
            break;
        case 0xEA:
        case 0xEB:
        case 0xEC:
        case 0xED:
        case 0xEE:
        case 0xEF:
        case 0xF0:
        case 0xF1:
        case 0xF2:
            p = (u8 *)func_800257CC((s16)(*s - 0xEA)) + k;
            if (*p == 0xFF || k >= 9) {
                s++;
                k = 0;
            } else {
                k++;
                D_8009D5F0[n] = *p;
                n++;
            }
            break;
        case 0xFA:
        case 0xFB:
        case 0xFC:
        case 0xFD:
        case 0xFE:
            D_8009D5F0[n] = *s++;
            n++;
        default:
            D_8009D5F0[n] = *s++;
            n++;
            break;
        case 0xFF:
            goto done;
        }
    } while (n < 0x17);
done:
    D_8009D5F0[n] = 0xFF;
    return 1;
}

void func_800D7C98(s16 arg0, s16 arg1) {
    u8 *src;
    u8 *dst;
    s16 n;

    if (D_8007E7A8 == NULL) {
        func_800D4848((s32)D_800A10DC);
        return;
    }
    src = D_8007E7A8;
    n = 0;
    src += D_8007E7A8[arg1 * 2 + 2];
    src += D_8007E7A8[arg1 * 2 + 3] << 8;
    dst = func_800257CC(arg0);
    while (*src != 0xFF) {
        *dst++ = *src++;
        n++;
    }
    if (n < 9) {
        *dst = 0xFF;
    }
}

void func_800D7D6C(void) {
    s32 i;
    s32 j;
    u8 one;
    s32 col;
    u8 pad[0x20];
    FdE10 *p;
    FdE10 *q;
    FdE18 *p2;
    FdE18 *q2;

    one = 1;
    for (j = 0x762; j >= 0; j -= 0x17A) {
        *((u8 *)D_800E08C0 + j) = one;
    }
    D_8009D824 = 1;
    D_800E1024 = 0;
    D_80071C08 = 0;
    D_800E4210 = 0;
    for (i = 0; i < 0x158; i++) {
        p = &D_800E1028[i];
        q = &D_800E1028[i + 0x158];
        p->b3 = 3;
        p->b7 = 0x74;
        q->b3 = 3;
        q->b7 = 0x74;
        p->b7 |= 1;
        q->b7 |= 1;
    }
    for (i = 0; i < 8; i++) {
        D_800E4200[i] = ((0x1E7 - i) << 6) | 0x10;
    }
    for (i = 0; i < 0xC; i++) {
        p = &D_800E3FA8[i];
        q = &D_800E3FA8[i + 0xC];
        p->b3 = 3;
        p->b7 = 0x60;
        q->b3 = 3;
        q->b7 = 0x60;
        p->b7 |= 2;
        q->b7 |= 2;
    }
    for (i = 0; i < 0x18; i++) {
        p2 = &D_800E3B28[i];
        q2 = &D_800E3B28[i + 0x18];
        p2->b3 = 5;
        p2->b7 = 0x48;
        p2->w14 = 0x55555555;
        q2->b3 = 5;
        q2->b7 = 0x48;
        q2->w14 = 0x55555555;
    }
    if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
        col = 0x2F;
    } else {
        col = 0x1F;
    }
    for (i = 0; i < 6; i++) {
        func_80044A68(&D_800E4128[i], 0, 0, (u16)col, 0);
        func_80044A68(&D_800E4128[i + 6], 0, 0, (u16)col, 0);
    }
}

void func_800D7F9C(void) {
    func_800D828C(5, 0x6C, 0, 0x6C, 0x52);
    func_800DA334(&D_800E4254, "Authr:");
    func_800DA368(&D_800E4254, D_8009C6DC + 0x10);
    func_800D9F00(5, (s32) &D_800E4254);
    func_800DA334(&D_800E4254, "Event:");
    func_800DA368(&D_800E4254, D_8009C6DC + 0x18);
    func_800D9F00(5, (s32) &D_800E4254);
    func_800D9F00(5, (s32) "  Go");
    func_800D9F00(5, (s32) "  Stop");
    func_800D9F00(5, (s32) "  Step");
    func_800DA124(5, 5, "  Actor OFF");
    func_800DA124(5, 6, "  Info  OFF");
    func_800DA2CC(5);
    func_800D828C(4, 0x6C, 0x52, 0x6C, 0x52);
    func_800D9F00(4, (s32) &D_800E0628);
    func_800DA2CC(4);
    func_800D828C(3, 0x6C, 0xA4, 0x6C, 0x5C);
    func_800D9F00(3, (s32) &D_800E0630);
    func_800DA2CC(3);
    func_800D828C(1, 0, 0, 0x6C, 0xCA);
    func_800D9F00(1, (s32) &D_800E0628);
    func_800DA2CC(1);
    D_80099FFC = 3;
    D_8007EBCC = 4;
    D_8007EBDC = 8;
    D_80071E24 = 0;
    D_8009D820 = 0;
    D_80070788 = 0;
    D_80071C08 = 5;
    func_800DA1D4(5, 4);
}

s32 func_800D8194(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 i;

    for (i = 0; i < 6; i++) {
        if (D_800E08C0[i].a != 0) {
            ((void (*)(s16, s16, s16, s16, s16))func_800D8334)(i, arg0, arg1, arg2, arg3);
            func_800D84CC(i);
            return i;
        }
    }
    ((void (*)(s16, s16, s16, s16, s16))func_800D8334)(0, arg0, arg1, arg2, arg3);
    func_800D84CC(0);
    return 0;
}

s32 func_800D828C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    s32 ret;
    ((void (*)(s16, s16, s16, s16, s16))func_800D8334)(arg0, arg1, arg2, arg3, arg4);
    if (D_800E08C0[arg0].a != 2) {
        ret = func_800D84CC(arg0);
    } else {
        ret = 1;
        D_800E08C0[arg0].a = 0;
        D_8009D824 = ret;
    }
    return ret;
}

void func_800D8334(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    D_800E0746[arg0].s02 = arg1;
    D_800E0746[arg0].s04 = arg2;
    D_800E0746[arg0].s06 = arg3;
    D_8009D824 = 1;
    D_800E0746[arg0].s08 = arg4;
}

void func_800D83A8(s16 arg0, s16 arg1, s16 arg2) {
    D_8009D824 = 1;
    D_800E0746[arg0].s02 += arg1;
    D_800E0746[arg0].s04 += arg2;
}

void func_800D8420(s16 arg0, s32 arg1, s32 arg2) {
    D_8009D824 = 1;
    D_800E074C[arg0].a += arg1;
    D_800E074C[arg0].b += arg2;
}

s32 func_800D8498(s16 arg0) {
    return D_800E08C0[arg0].a == 0;
}

s32 func_800D84CC(s16 arg0) {
    s32 i;
    s32 ret;

    for (i = 0; i < 0x18; i++) {
        D_800E0750[arg0].e[i].a = 0;
        D_800E0750[arg0].f158[i] = 0;
    }
    D_800E0750[arg0].x0 = 7;
    D_800E0750[arg0].x1 = 0xF;
    D_800E0750[arg0].x2 = 0x1F;
    D_800E0750[arg0].x6 = 0;
    D_800E0750[arg0].x4 = 0;
    D_800E0750[arg0].x170 = 0;
    ret = 1;
    D_8009D824 = ret;
    return ret;
}

void func_800D85C0(void) {
    D_800E41B8 = 0;
    D_800E41C0 = 0;
    D_800E41BC = 0;
    D_800E41C4 = 0;
    D_800E1024 ^= 1;
}

void func_800D85FC(FdTag *arg0) {
    s32 i;

    if (D_8009D824 != 0) {
        i = 0;
        func_800D85C0();
        func_8004418C(D_800E41C8[(s16)D_800E1024], 7);
        do {
            if (D_800E08C0[i].a == 0) {
                func_800D8710(i);
            }
            i++;
        } while (i < 6);
        D_8009D824 = 0;
    }
    ((FdTag *)&D_800E41C8[(s16)D_800E1024][6])->addr = arg0->addr;
    arg0->addr = (u32)D_800E41C8[(s16)D_800E1024];
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text5", func_800D8710);

INCLUDE_ASM("../asm/us/field/nonmatchings/text5", func_800D9C04);

s32 func_800D9F00(s32 arg0, s32 arg1) {
    s16 i = arg0;

    func_800DA334(&D_800E0748[i].e[D_800E0748[i].line].a, (u8 *)arg1);
    D_800E0748[i].line++;
    if ((D_800E0748[i].h - 8) / 10 < D_800E0748[i].line) {
        D_800E0748[i].line = 0;
    }
    D_8009D824 = 1;
    return 1;
}

s32 func_800D9FFC(s16 arg0, u8 *arg1, s32 arg2) {
    func_800DA334(&D_800E0748[arg0].e[D_800E0748[arg0].line].a, arg1);
    D_800E0748[arg0].f160[D_800E0748[arg0].line] = arg2;
    D_800E0748[arg0].line++;
    if ((D_800E0748[arg0].h - 8) / 10 < D_800E0748[arg0].line) {
        D_800E0748[arg0].line = 0;
    }
    D_8009D824 = 1;
    return 1;
}

s32 func_800DA124(s16 arg0, s16 arg1, u8 *arg2) {
    func_800DA334((u8 *)&D_800E0746[arg0] + 0x12 + arg1 * 0xE, arg2);
    D_8009D824 = 1;
    return 1;
}

s32 func_800DA194(s16 arg0, s16 arg1, s8 arg2) {
    D_800E0746[arg0].f162[arg1] = arg2;
    return 1;
}

s32 func_800DA1D4(s32 arg0, s32 arg1) {
    s32 r = 1;
    D_800E0746[(s16)arg0].s10 = arg1;
    D_8009D824 = r;
    return r;
}

void func_800DA214(s16 arg0, s8 arg1, s8 arg2, s8 arg3) {
    if (D_800E08C0[arg0].a == 0) {
        D_800E0746[arg0].b0A = arg1;
        D_800E0746[arg0].b0B = arg2;
        D_800E0746[arg0].b0C = arg3;
        D_8009D824 = 1;
    }
}

void func_800DA28C(s16 arg0) {
    D_800E08C0[arg0].a = 1;
    D_8009D824 = 1;
}

void func_800DA2CC(s16 arg0) {
    D_800E08C0[arg0].a = 2;
    D_8009D824 = 1;
}

void func_800DA310(void) {
    D_800E4210 = (D_800E4210 + 1) & 3;
}

void func_800DA334(u8 *arg0, u8 *arg1) {
    u8 *var_a0;
    u8 *var_a1;
    u8 temp_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    if (*var_a1 != 0) {
        do {
            temp_v0 = *var_a1;
            var_a1 += 1;
            *var_a0 = temp_v0;
            var_a0 += 1;
        } while (*var_a1 != 0);
    }
    *var_a0 = 0;
}

void func_800DA368(u8 *dst, u8 *src) {
    while (*dst) {
        dst++;
    }
    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
}

s32 func_800DA3C4(u8 *arg0) {
    s32 var_v1;
    u8 *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
    if (*var_a0 != 0) {
        do {
            var_a0 += 1;
            var_v1 += 1;
        } while (*var_a0 != 0);
    }
    return var_v1;
}

void func_800DA3F0(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 pad[8];
    s32 var_v1;
    u8 *var_a0;
    u8 *var_a1;
    u8 temp_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v1 = arg2 - 1;
    if (arg2 != 0) {
        do {
            temp_v0 = *var_a1;
            var_a1 += 1;
            var_v1 -= 1;
            *var_a0 = temp_v0;
            var_a0 += 1;
        } while (var_v1 != -1);
    }
}

void func_800DA424(s32 arg0, u8 *arg1) {
    arg1[1] = 0;
    arg1[0] = D_800E0208[arg0 & 0xF];
}

void func_800DA444(s32 arg0, u8 *arg1) {
    arg1[2] = 0;
    arg1[0] = D_800E0208[(arg0 & 0xF0) >> 4];
    arg1[1] = D_800E0208[arg0 & 0xF];
}

void func_800DA480(s32 arg0, u8 *arg1) {
    arg1[4] = 0;
    arg1[0] = D_800E0208[(arg0 & 0xF000) >> 12];
    arg1[1] = D_800E0208[(arg0 & 0xF00) >> 8];
    arg1[2] = D_800E0208[(arg0 & 0xF0) >> 4];
    arg1[3] = D_800E0208[arg0 & 0xF];
}

void func_800DA4FC(s32 n, u8 *buf) {
    s32 started;
    s32 div;
    s32 len;
    s32 d;

    started = 0;
    div = 10000;
    len = 0;
    do {
        d = n / div;
        if (started || d != 0) {
            started = 1;
            buf[len] = D_800E0208[d];
            len++;
        }
        n -= d * div;
        div /= 10;
    } while (div > 1);
    buf[len] = D_800E0208[n];
    buf[len + 1] = 0;
}
