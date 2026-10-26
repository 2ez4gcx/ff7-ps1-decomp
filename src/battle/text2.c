#include "common.h"
#include "battle/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
extern u8 D_8015190B[][0xB9C];

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B30E4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B33A4);

void func_800B36B4(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 p;

    i = D_80163624 & 2;
    if (!(u8)i) {
        for (i = 5; i < D_800F7E04 + 4; i++) {
            k = i - 4;
            for (j = 0; j < k * 4; j++) {
                p = D_800F8384[D_800F7E08[k][0]];
                func_800C7C4C(i, *(s32 *)(p + 8) + 0x68, (void *)(p + 0xC), (void *)p);
            }
        }
    }
}

void func_800B37A0(void) {
    func_800D91DC(0x140, 0xF0, D_80162084, D_800FA6A0, (s32) D_800FA670, (s32) D_800F9F34);
}

void func_800B37EC(void) {
    D_80162094 = 4;
    func_800D8A78(4);
    func_800E15D8();
    func_800D9E0C(-1, -1, 0);
    D_80095DD4 = 2;
}

void func_800B383C(void) {
    func_800B3FFC();
    func_80033FC4(D_800E7D50[D_800FA6D0 * 2], D_800E7D50[D_800FA6D0 * 2 + 1], 0x801A0000, 0);
    func_80033FC4(D_800E7D98[D_80163614 * 2], D_800E7D98[D_80163614 * 2 + 1], 0x801B0000, 0);
    func_800BB4F8();
    func_8001C3CC((s32)D_801590E4, 0x801B0000, 0x8D04);
    func_80043DD8(0);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B38E0);

void func_800B3934(void) {
    func_800B5D38(2);
    func_800B5CD4(2);
    D_80166F64 = 3;
}

void func_800B3968(void) {
    s32 t;
    func_800B5D38(1);
    t = func_800B5CD4(1);
    D_80166F64 = 2;
    D_800F8398 = t + D_800F8394;
    if ((u8)D_800F7DF4 >= 3U) {
        func_80033E74(D_800E8050[D_800F7E00 * 2], D_800E8050[D_800F7E00 * 2 + 1], 0x801B0000, (s32)func_800B3934);
        func_800B7FB4();
    }
}

void func_800B3A04(void) {
    s32 t;

    D_800F8390[0] = (s32) D_80130200;
    func_800B5D38(0);
    t = func_800B5CD4(0);
    D_80166F64 = 1;
    D_800F8394 = t + D_800F8390[0];
    if ((u8)D_800F7DF4 >= 2U) {
        func_80033E74(D_800E8050[D_800F7DFC * 2], D_800E8050[D_800F7DFC * 2 + 1], 0x801B0000, (s32)func_800B3968);
        func_800B7FB4();
    }
}

void func_800B3AB8(void) {
    BtlS16 *p;

    p = (BtlS16 *)&D_800FA9C6;
    D_800F8384[p->a] = (s32)D_80103200[p->a];
    func_800B5E64(p->a);
    func_800B5C1C(p->a);
    if (D_800FA9C8 != 0xC8) {
        func_80033E74(D_800E8068[D_800FA9C8 * 2], D_800E8068[D_800FA9C8 * 2 + 1], 0x801B0000, (s32)func_800B3B84);
        func_800B7FB4();
    } else {
        D_80166F64 = 3;
    }
}

void func_800B3B84(void) {
    BtlS16 *p;

    p = (BtlS16 *)&D_800FA9CA;
    D_800F8384[p->a] = (s32)D_80103200[p->a];
    func_800B5E64(p->a);
    func_800B5C1C(p->a);
    if (D_800FA9CC != 0xC8) {
        func_80033E74(D_800E8068[D_800FA9CC * 2], D_800E8068[D_800FA9CC * 2 + 1], 0x801B0000, (s32)func_800B3C50);
        func_800B7FB4();
    } else {
        D_80166F64 = 3;
    }
}

void func_800B3C50(void) {
    BtlS16 *p;

    p = (BtlS16 *)&D_800FA9CE;
    D_800F8384[p->a] = (s32)D_80103200[p->a];
    func_800B5E64(p->a);
    func_800B5C1C(p->a);
    D_80166F64 = 3;
}

void func_800B3CD0(void) {
    func_800D2980(0x801B0000, 0, 0, 0);
    func_80033E74(D_800E8068[D_800FA9C4 * 2], D_800E8068[D_800FA9C4 * 2 + 1], 0x801B0000, (s32)func_800B3AB8);
    func_800B7FB4();
}

void func_800B3D38(void) {
    func_800C5E94();
    D_800F839C = &D_800EA50C;
    func_80033E74(0x755E, 0xA800, 0x801B0000, (s32) &func_800B3CD0);
    func_800B7FB4();
}

void func_800B3D88(void) {
    func_800B588C();
    func_800B6B98(4, 0xA);
    func_800B36B4();
}

void func_800B3DBC(void) {
    s32 var_a0;
    u8 *var_v1;

    func_800B4794();
    func_800B6B98(0, 3);
    func_800B6B98(3, 3);
    var_a0 = 0;
    if (D_80163614 == 0x39) {
        var_v1 = &D_80151909;
        do {
            var_a0 += 1;
            *var_v1 |= 0x10;
            var_v1 += 0xB9C;
        } while (var_a0 < 0xA);
    }
}

void func_800B3E2C(void) {
    s32 i;
    s32 o;
    s32 *p;

    D_80163C7C = 0;
    D_800F9D94 = 0;
    D_80162974 = 0;
    D_800F7DE4 = 1;
    D_800F837C = 0;
    D_801031E0 = 1;
    D_801590E0 = 0;
    D_801620A0 = 0;
    D_80163B38 = 0;
    D_801590CC = 0;
    D_800FA6D4 = 0;
    D_801517C4 = 0;
    D_801620A4 = 0;
    D_800FAFDC = 0;
    D_800F7ED4 = 0;
    D_800F9D9C = 0;
    D_800F9D98 = 0;
    D_801590D8 = 0;
    D_80166F58 = 0;
    D_801516A0 = 0;
    D_800F8380 = 0;
    for (i = 0; i < 10; i++) {
        o = i * 0xB9C;
        D_8015190A[o] = 1;
    }
    i = 2;
    p = &D_800F9F30;
    do {
        *p = 0;
        i--;
        p--;
    } while (i >= 0);
    D_80151906[D_801590CC].pad[0] = 0;
    D_800F8374 = 0xE;
    D_801637A0[D_801590E0].a = -2;
    func_800BC1E0();
    func_800C5BEC();
}

s32 func_800B3FAC(s32 arg0) {
    s32 i;
    u8 *p;

    p = &D_800F7DF4;
    for (i = 0; i < 6; i++) {
        if (D_80163658[i].a == arg0) {
            *p += 1;
            return 0;
        }
    }
    return -1;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B3FFC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B430C);

void func_800B45F0(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_801636BE[i].a & 1) {
            if (D_800E8F94[D_800FA6D0][i] == 0) {
                D_800E8E88[D_800FA6D0][i][0] += 0x204;
            } else {
                D_800E8E88[D_800FA6D0][i][0] -= 0x204;
            }
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B46B4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B4794);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B4E30);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B5138);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B54B8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B588C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B5AAC);

void func_800B5C1C(s32 arg0) {
    s32 *p;
    u8 *q;
    s32 n;

    p = (s32 *)0x801B0000;
    func_8001C3CC((s32)D_80103200[arg0], 0x801B0000, p[p[0] - 16]);
    q = func_80025788(arg0);
    n = p[0];
    func_8001C3CC((s32)D_80163F34[arg0], p[n + (q[0x411] & 0xF) - 15] + (s32)p, 0x1000);
}

s32 func_800B5CD4(s32 arg0) {
    s32 *p;

    p = (s32 *)0x801B0000;
    func_8001C3CC(D_800F8390[arg0], 0x801B0000, p[*p]);
    return p[*p];
}

void func_800B5D38(s32 arg0) {
    s32 *ov;
    s32 i;

    ov = (s32 *)0x801B0000;
    if (D_80163614 == 0x4E) {
        func_800D2980(ov[ov[0]] + (s32)ov, arg0 + 0x13, 0, 0);
    } else {
        func_800D2980(ov[ov[0]] + (s32)ov, arg0 + 0x12, 0, (arg0 + 3) * 3);
    }
    for (i = 4; i < D_800F7E04 + 4; i++) {
        if (D_800F7E08[i - 4][0] == arg0 + 3) {
            ((void (*)(s32, s32))func_800C614C)((s32)ov + *(s32 *)((s32)ov + (ov[0] << 2)), i);
        }
    }
}

void func_800B5E64(s32 arg0) {
    s32 a;
    s32 b;
    s32 c;
    s32 *p;

    switch (arg0) {
    case 0:
        a = 0;
        b = 0;
        c = 0;
        break;
    case 1:
        a = 0x10;
        b = 1;
        c = 0xC0;
        break;
    case 2:
        a = 0x11;
        b = 2;
        c = 0x180;
        break;
    }
    if (D_801636B8[arg0].a != -1) {
        p = (s32 *)0x801B0000;
        func_800D2980(p[p[0] - 16] + (s32)p, a, 0, arg0 * 3);
        ((void (*)(s32, s32))func_800C614C)(p[p[0] - 16] + (s32)p, b);
        *(s16 *)(&D_801518FA + arg0 * 0xB9C) = c;
        func_800BB67C((s32)&D_80151A24[arg0], &D_80151A24[arg0].x + 0x500);
    }
}

void func_800B5FC4(s16 arg0) {
    func_800B60E0(arg0);
}

void func_800B5FE8(s16 arg0) {
    s32 i;

    for (i = 0; i < D_801518F4[arg0].n; i++) {
        D_801518F4[arg0].b[i] |= 8;
    }
    for (i = 0; i < D_800FA714[arg0].n; i++) {
        D_800FA714[arg0].b[i] |= 8;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B60E0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B64CC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B677C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B6B98);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B6D6C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B7764);

void func_800B798C(void) {
    s32 i;

    for (i = 0; i < 0x4E; i++) {
        D_801517F0[i] = 0xFF;
        D_80163CC0[i].a = 0;
        D_80163CC0[i].b = 0;
        D_80163CC0[i].c = 0;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B79F0);

void func_800B7DB4(void) {
    s32 i;

    D_800FA69C = 0;
    D_80163608 = 0;
    D_80162088 = 0;
    D_80161DE8 = 0;
    D_800F836C = 0;
    D_801517B4 = 0;
    D_80151774 = 0;
    for (i = 0; i < D_800F9774; i++) {
        D_80151774 = (1 << D_80163CC0[i].a) | D_80151774;
        if (D_80163CC0[i].b & 1) {
            D_801517B4 = (1 << D_80163CC0[i].a) | D_801517B4;
        }
        if (D_80163CC0[i].b & 2) {
            D_800F836C = (1 << D_80163CC0[i].a) | D_800F836C;
        }
        if (D_80163CC0[i].b & 4) {
            D_80161DE8 = (1 << D_80163CC0[i].a) | D_80161DE8;
        }
        if (D_80163CC0[i].b & 8) {
            D_80162088 = (1 << D_80163CC0[i].a) | D_80162088;
        }
        if (D_80163CC0[i].b & 0x10) {
            D_80163608 = (1 << D_80163CC0[i].a) | D_80163608;
        }
        if (D_80163CC0[i].b & 0x20) {
            D_800FA69C = (1 << D_80163CC0[i].a) | D_800FA69C;
        }
    }
}

void func_800B7F6C(void) {
 u8 pad[8]; while (D_80062D99 != 0) { func_800B7FB4(); } D_80062D98 = 0; }

void func_800B7FB4(void) {
    D_801518DC = func_80034B44();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B7FDC);

void func_800B8234(s32 arg0) {
    if (arg0 != 0) {
        func_800D0C80(D_801590CC);
        D_801517BC = 0;
    }
}

void func_800B8268(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        D_80163784[i] = D_801636B9[i][0];
        if (!(D_8015120C[i][0] & 8) && D_801518E6[i][0] != D_80163784[i] && D_80151908[i].b == 1) {
            D_80151922[i][0] |= 1;
            D_801518E6[i][0] = D_80163784[i];
        }
    }
    D_80163787 = 0;
}

void func_800B8360(s32 arg0) {
    void *temp_a1;

    func_80044A68(D_80163C74, 1, 1, (arg0 & 3) << 5, 0);
    temp_a1 = D_80163C74;
    D_80163C74 = temp_a1 + 0xC;
    func_80046794(D_801517C0 + 0x4078, (s32) temp_a1);
}

void func_800B83C4(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_80151200[i].c & 1) {
            func_800BA4C8();
            func_800BA40C();
            return;
        }
    }
    func_800BA40C();
    func_800BA4C8();
}

void func_800B8438(void) {
    func_800B9568();
    if (D_801635FC != 0) {
        D_801635FC--;
    }
    switch (D_80163C7C) {
    case 0:
    case 1:
    case 6:
        break;
    case 2:
        func_800B905C();
        func_800BC440();
        func_800BA4C8();
        break;
    case 3:
    case 4:
    case 5:
    default:
        func_800B8EE4();
        func_800B905C();
        func_800B8234((u8)D_801517BC);
        func_800BC440();
        func_800B7FB4();
        func_800B83C4();
        func_800B8B48();
        break;
    }
    func_800B7FB4();
    func_800B91CC();
    D_80151694 = D_8016375A;
    func_800B85E0();
    func_800BC81C(D_800F8370, D_80151906[D_801590CC].pad[0]);
    func_800BC8B0(D_800F8370);
    func_800B8268();
    func_8003B69C(0, 0, 0);
    func_800BC538();
    func_800BC348();
    func_800BB75C((s32)&D_800FA63C, (s32)&D_800FA958, (s32)&D_80158D00, (s32)&D_801031E8);
    func_800C627C();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B85E0);

s16 func_800B888C(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x4E; i++) {
        if (arg0 == D_801517F0[i]) {
            return i;
        }
    }
}

void func_800B88CC(s32 arg0) {
    s32 i;

    i = func_800BBEAC(&func_800CE970);
    D_80162978[i].c = 0;
    M2C_SFIELD(&D_80162978[i], s16 *, 8) = arg0;
    func_800B8A34(func_800B888C(arg0), i);
}

void func_800B8944(s32 arg0, s32 arg1) {
    s32 i;

    i = func_800BBEAC(&func_800CE970);
    D_80162978[i].c = 0;
    M2C_SFIELD(&D_80162978[i], s16 *, 8) = arg0;
    ((void (*)(s32, s32))func_800B8A34)(arg1, i);
    if (D_80163CC0[arg1].b & 4) {
        D_8015120C[arg0][0] |= 0x10;
    } else {
        D_8015120C[arg0][0] &= 0xFFEF;
    }
}

u8 func_800B8A34(s32 arg0, s32 arg1) {
    s32 o;
    s32 t0;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 t7;

    o = arg1 << 5;
    t0 = D_800F99EC[arg0].a;
    *(u16 *)(D_80162980 + 2 + o) = t0;
    t1 = D_801590CC;
    t2 = D_800F99EC[arg0].b;
    *(u16 *)(D_80162984 + o) = t1;
    *(u16 *)(D_80162984 + 2 + o) = t2;
    t3 = D_800F99EC[arg0].c;
    *(s32 *)(D_80162988 + o) = t3;
    t4 = D_800F99EC[arg0].d;
    *(s32 *)(D_8016298C + o) = t4;
    t5 = D_800F8CF0;
    t6 = D_800F99EC[arg0].e;
    *(u8 *)(D_80162990 + o) = t5;
    *(u16 *)(D_8016297E + o) = t6;
    t7 = D_800F99EC[arg0].f;
    *(u8 *)(D_80162990 + 1 + o) = t7;
    return t7;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B8B48);

void func_800B8E48(u8 arg0) {
    D_80151908[arg0].b = 1;
    D_80151908[arg0].a &= 0x7F;
    D_8015120C[arg0][0] &= 0xFFDF;
}

void func_800B8EE4(void) {
    s32 i;
    s32 k;
    s32 p;

    k = 0;
    for (i = 0; i < 3; i++) {
        if (D_801636B8[k++].a != -1) {
            func_800B5FC4(i);
            if (!(D_80151908[i].a & 2)) {
                p = D_800F8384[D_80151232[i][0]];
                func_800C7C4C(i, *(s32 *)(p + 8) + 0x68, (void *)(p + 0xC), (void *)p);
            }
        }
    }
}

void func_800B8FCC(s32 arg0) {
    s32 i;
    s32 p;
    if (D_80151232[arg0][0] == 6) {
        i = 6;
    } else {
        i = D_800F7E08[arg0 - 4][0];
    }
    p = D_800F8384[i];
    func_800C7C4C(arg0, *(s32 *)(p + 8) + 0x68, (void *)(p + 0xC), (void *)p);
}

void func_800B905C(void) {
    s32 a;
    s32 b;
    s32 i;
    s32 o;
    s32 q;
    u8 v;

    for (i = 4; i < D_800F7E04 + 4; i++) {
        func_800B5FC4(i);
        o = i * 0xB9C;
        v = (&D_80151909)[o];
        if (!(v & 0x40) && !(v & 2)) {
            ((void (*)(s32, s32, s32))func_800B8FCC)(i, a, b);
        }
    }
    for (i = 4; i < D_800F7E04 + 4; i++) {
        o = i * 0xB9C;
        q = i * 0x74;
        v = (&D_80151909)[o];
        if (!(v & 0x40) && !(v & 2) && (D_80151922[i][0] & 1) && (*(u16 *)((u8 *)D_8015120C + q) & 4)) {
            ((void (*)(s32, s32, s32))func_800B8FCC)(i, a, b);
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B91CC);

void func_800B950C(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        D_801516FC[i].a.a = D_801516FC[i].b.a;
        D_801516FC[i].a.b = D_801516FC[i].b.b;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B9568);

void func_800BA11C(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    BtlCoord34 *c;
    u8 *r;
    s32 i;

    i = arg0 & 0xFF;
    r = (u8 *)&D_800F8178[i];
    c = (BtlCoord34 *)((u8 *)&D_800F8178[i] - 0x20);
    func_8003C21C((s32)r, (s32)c);
    func_800BAF34(c);
    if (D_800F8178[i].z == arg3) {
        D_800F8178[i].z = arg2;
    }
    D_800F8178[i].z = arg1 + D_800F8178[i].z;
    func_800BA360(8, D_801517C0 + 0x70, 0xC, 0);
    func_800BA360(9, D_801517C0 + 0x70, 0xC, 0);
    func_800BA360(0xA, D_801517C0 + 0x70, 0xC, 0);
}

void func_800BA24C(void) {
    D_800F8180.b = 0;
    if (D_80163B44.a == 0) {
        D_800F8180.b = -0x28;
    }
    if (D_80163B44.b == 0) {
        D_800F8180.b -= 0x50;
    }
    D_80163B44.a = (D_80163B44.a - 1) & 3;
    D_80163B44.b = (D_80163B44.b - 1) & 0x1F;
}

void func_800BA2BC(s32 arg0) {
    if (((s16 *)&D_80163B44)[arg0] < 0x10) {
        D_800F8182[arg0][0] = D_800F8182[arg0][0] - 0x19;
    } else {
        D_800F8182[arg0][0] = D_800F8182[arg0][0] + 0x19;
    }
    ((s16 *)&D_80163B44)[arg0] = (((s16 *)&D_80163B44)[arg0] - 1) & 0x1F;
}

void func_800BA360(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 v;
    s32 f;
    s32 pad[2];

    v = D_801590E8[arg0];
    *(s16 *)0x1F80032C = 0x20;
    *(s16 *)0x1F80032E = 0;
    *(s16 *)0x1F800328 = 0;
    *(u8 **)0x1F800320 = D_801590E4 + (v & 0x7FFFFFFF);
    if (v & 0x80000000) {
        f = 8;
    } else {
        f = 0;
    }
    arg3 |= 0x180;
    *(s32 *)0x1F800324 = f | arg3;
    *(u16 *)0x1F80032A = D_800F5B74;
    D_80163C74 = func_800D29D4((void *)0x1F800320, arg1, arg2, D_80163C74);
}

void func_800BA40C(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (!(D_80151908[i].a & 2)) {
            func_800C1908(i);
            func_800BA598(i);
            if (D_8015190B[i][0] & 0x80) {
                func_800BB2A8(i);
                func_800BB030(i);
            }
        }
    }
}

void func_800BA4C8(void) {
    s32 i;

    for (i = 4; i < D_800F7E04 + 4; i++) {
        if ((D_80151908[i].a & 0x80) && !(D_80151908[i].a & 2)) {
            func_800C1908(i);
            func_800BA598(i);
            if (D_8015190B[i][0] & 0x80) {
                func_800BB030(i);
            }
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BA598);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BACEC);

void func_800BAF34(BtlCoord34 *arg0) {
    s32 flag;
    BtlMatrix *m;

    m = arg0->super;
    *(BtlMatrix **)0x1F800020 = m;
    *(BtlMatrix *)0x1F800024 = *m;
    func_8003B16C(0x1F800024, (s32)arg0);
    func_8003B48C(0x1F800024);
    func_8003B51C(0x1F800024);
    func_8003BC6C((s32)&arg0->t, (s32)arg0->m.t, &flag);
    func_8003B48C((s32)arg0);
    func_8003B51C((s32)arg0);
}

void func_800BAFF8(s32 arg0) {
    func_8003B35C();
    func_8003B48C(arg0);
    func_8003B51C(arg0);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BB030);

void func_800BB2A8(u8 arg0) {
    s32 i;
    u32 c;
    u32 *p;
    u32 a;
    u32 b;
    u32 d;

    if (D_801518E4[arg0].v == 0 && (((u8 *)func_80025788(arg0))[0x411] & 0xF) == 0xF) {
        D_800E8E80 = func_800E1A2C();
        if (D_800E8E80 != (&D_800E8E80)[1]) {
            c = D_800E8E80 >> 8;
            c = c * 0x101 | 0xFFFF0000;
            for (i = 0; i < 0x22; i++) {
                p = (u32 *)&D_80163F34[arg0][D_800E8DF8[i]];
                a = p[0];
                p[0] = ((a & 0xFFFF0000) | ((a & 0xFF0000) >> 8) | ((a & 0xFF0000) >> 16)) & c;
                b = p[1];
                p[1] = ((b & 0xFFFF0000) | ((b & 0xFF0000) >> 8) | ((b & 0xFF0000) >> 16)) & c;
                d = p[2];
                p[2] = ((d & 0xFFFF0000) | ((d & 0xFF0000) >> 8) | ((d & 0xFF0000) >> 16)) & c;
            }
        }
        (&D_800E8E80)[1] = D_800E8E80;
    }
}

void func_800BB430(s16 arg0, s32 arg1) {
    s32 i;
    s32 p;

    for (i = 0; i < D_801518F4[arg0].n; i++) {
        p = D_801518F4[arg0].p[i];
        if (p != 0) {
            func_800D3520(p, arg1);
        }
    }
}

void func_800BB4F8(void) {
    u32 *p;

    p = (u32 *) 0x801B0000;
    func_800D2980(p[p[0]] + (s32) p, 0, 0, 0);
}

void func_800BB538(s16 arg0, void *arg1, s32 arg2) {
    s32 o;
    s32 *q;
    s16 k;

    q = D_801590E8;
    k = arg0;
    if (*(u8 *)((s32)D_801590E8 + q[0] - 4) == 2) {
        if (arg2 == 0) {
            func_800BB67C((s32)&D_800F8158, &D_80151A24[arg0]);
        } else {
            func_800BB67C((s32)&D_800F818C, &D_80151A24[arg0]);
        }
    } else if (arg0 == 3) {
        func_800BB67C((s32)&D_800FA63C, &D_80153CF8);
    } else {
        func_800BB67C((s32)&D_800F8158, &D_80151A24[arg0]);
    }
    o = k * 0xB9C;
    func_800BB67C((s32)&D_80151A24[k], (u8 *)D_80151A24 + 0x34 + o);
    func_800C76C8((u8 *)D_80151A24 - 0x130 + o, arg1, k);
}

void func_800BB67C(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0x30) = arg0;
}

void func_800BB684(void) {
    s16 v;
    u8 m;

    v = D_801637A0[D_801590E0].a;
    if (v != -4) {
        D_800F8370 = v;
        D_801590DC = 0;
        D_801518AC[3].pos = 0xFF;
        D_801518AC[2].pos = 0xFF;
        D_801518AC[1].pos = 0xFF;
        D_801518AC[0].pos = 0xFF;
        D_8015184C[3].pos = 0xFF;
        D_8015184C[2].pos = 0xFF;
        D_8015184C[1].pos = 0xFF;
        D_8015184C[0].pos = 0xFF;
        func_800BC2F0();
        if (D_800F837C != 3) {
            m = D_801516F4 & 3;
            if (m != 3) {
                D_800F837C = m;
            }
        }
    }
}

void func_800BB75C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 flag;

    func_800D85B0(arg1, arg2, arg3, D_800E7D10);
    func_8003C21C(arg0 + 0x20, arg0);
    func_8003B32C(arg0, arg0 + 0x28);
    func_8003B16C(arg1, arg0);
    func_8003B48C(arg1);
    func_8003B51C(arg1);
    func_8003BC6C(arg0 + 0x28, arg0 + 0x14, &flag);
    ((void (*)(s32, void *))func_800BAFF8)(arg0, D_800E7D20);
}

void func_800BB804(void) {
    if (!(D_8016376A & 0x20)) {
        func_80033E34(0x77E7, 0x1000, 0x801D0000, (s32) &func_800BB89C);
        func_800B7FB4();
        return;
    }
    D_80163B80 = 0;
    D_800FA6B8 = 0;
}

void func_800BB864(void) {
    func_80033E34(0x77E6, 0x800, 0x801D0000, (s32) &func_800BB89C);
    func_800B7FB4();
}

void func_800BB89C(void) {
    s32 v;

    D_80163B80 = 0;
    D_800FA6B8 = 0;
    if ((D_8016376A & 0x10) || D_80083338 != 0) {
        v = 0x10;
    } else {
        v = 0x14;
    }
    D_8009A000 = v;
    D_8009A004 = 0x801D0000;
    func_8002DA7C();
}

void func_800BB90C(void) {
    D_8009A000 = 0xA0;
    D_8009A004 = 0x7F;
    func_8002DA7C();
}

void func_800BB944(void) {
    func_800BB90C();
    D_8009A000 = 0xF1;
    func_8002DA7C();
}

void func_800BB978(void) {
    D_8009A000 = 0xC1;
    D_8009A004 = 0x12C;
    D_8009A008 = 0;
    func_8002DA7C();
}

void func_800BB9B8(u16 arg0) {
    D_800F4AD0.op = 0x30;
    D_800F4AD0.a = arg0;
    D_800F4AD0.b = arg0;
    func_8002DF88(&D_800F4AD0);
}

void func_800BB9FC(s32 arg0) {
    s32 temp_a0;

    D_8009A000 = 0x2B;
    temp_a0 = arg0 & 0xFFFF;
    D_8009A004 = 0x40;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_800BBA40(s32 arg0) {
    s32 temp_a0;

    D_8009A000 = 0x20;
    temp_a0 = arg0 & 0xFFFF;
    D_8009A004 = 0x40;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_800BBA84(u16 arg0, s16 arg1, u8 arg2) {
    if (arg1 == -1) {
        D_8009A004 = arg2;
    } else {
        D_8009A004 = (D_801516FC[arg1].a.a / 5 * 2) & 0x7E;
    }
    D_8009A000 = 0x20;
    D_8009A008 = arg0;
    func_8002DA7C();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BBB20);

void func_800BBDF8(void) {
    if (D_800F8368 == 0) {
        D_800F4AF4 = D_80163C74;
        if ((u32) D_80163C74 > 0x80184000U) {
            func_8003CEBC();
            func_80043938(1);
            func_8003D1B4();
            func_800429E0(0x62, 0);
        }
    } else {
        D_800F4AF8 = D_80163C74;
        if ((u32) D_80163C74 > 0x801A0000U) {
            func_8003CEBC();
            func_80043938(1);
            func_8003D1B4();
            func_800429E0(0x62, 1);
        }
    }
}

s32 func_800BBEAC(void *arg0) {
    s16 i;

    for (i = 0; i < 100; i++) {
        if (D_80161EF0[i] == NULL && i >= D_8015169C) {
            D_80161EF0[i] = arg0;
            D_80162978[i].a = D_8015169C;
            D_80162080++;
            return i;
        }
    }
    func_8003CEBC();
    func_80043938(1);
    func_8003D1B4();
    func_800429E0(0x61, 1);
}

s32 func_800BBF7C(void *arg0) {
    s16 i;

    for (i = 0; i < 10; i++) {
        if (D_80163B48[i] == NULL && i >= D_801590D0) {
            D_80163B48[i] = arg0;
            D_801620AC[i][0] = D_801590D0;
            D_80163B7C++;
            return i;
        }
    }
    func_8003CEBC();
    func_80043938(1);
    func_8003D1B4();
    func_800429E0(0x61, 2);
}

s32 func_800BC04C(void *arg0) {
    s16 i;

    for (i = 0; i < 60; i++) {
        if (D_80163B84[i] == NULL && i >= D_801590D4) {
            D_80163B84[i] = arg0;
            D_801621F0[i][0] = D_801590D4;
            D_80163C78++;
            return i;
        }
    }
    func_8003CEBC();
    func_80043938(1);
    func_8003D1B4();
    func_800429E0(0x61, 4);
}

s32 func_800BC11C(void *arg0) {
    s16 i;

    for (i = 0; i < 16; i++) {
        if (D_800FA978[i] == 0) {
            D_800FA978[i] = (s32)arg0;
            D_800F7ED8[i].a = D_800F8360;
            D_800FA9BC++;
            return i;
        }
    }
    func_8003CEBC();
    func_80043938(1);
    func_8003D1B4();
    func_800429E0(0x61, 3);
}

void func_800BC1E0(void) {
    s32 i;
    B20 *p;
    s16 (*q)[16];
    s16 (*r)[16];

    i = 0;
    p = D_80162978;
    D_80163C78 = 0;
    D_80163B7C = 0;
    D_80162080 = 0;
    for (; i < 0x64; i++) {
        D_80161EF0[i] = 0;
        p->b = 0;
        p++;
        D_80162978[i].a = 0;
    }
    i = 0;
    q = D_801620AC;
    for (; i < 0xA; i++) {
        D_80163B48[i] = 0;
        q[0][1] = 0;
        q++;
        D_801620AC[i][0] = 0;
    }
    i = 0;
    r = D_801621F0;
    for (; i < 0x3C; i++) {
        D_80163B84[i] = 0;
        r[0][1] = 0;
        r++;
        D_801621F0[i][0] = 0;
    }
    func_800BC2F0();
}

void func_800BC2F0(void) {
    s32 i;

    D_800FA9BC = 0;
    for (i = 0; i < 16; i++) {
        D_800FA978[i] = 0;
        D_800F7ED8[i].a = 0;
        D_800F7ED8[i].b = 0;
    }
}

void func_800BC348(void) {
    for (D_8015169C = 0; D_8015169C < 100; D_8015169C++) {
        if (D_80161EF0[D_8015169C] != NULL) {
            ((void (*)(void))D_80161EF0[D_8015169C])();
            if (D_80162978[D_8015169C].a == -1) {
                D_80162978[D_8015169C].a = 0;
                D_80162978[D_8015169C].b = 0;
                D_80161EF0[D_8015169C] = NULL;
                D_80162080--;
            }
        }
    }
    D_8015169C = 0;
}

void func_800BC440(void) {
    for (D_801590D0 = 0; D_801590D0 < 10; D_801590D0++) {
        if (D_80163B48[D_801590D0] != NULL) {
            ((void (*)(void))D_80163B48[D_801590D0])();
            if (D_801620AC[D_801590D0][0] == -1) {
                D_801620AC[D_801590D0][0] = 0;
                D_801620AC[D_801590D0][1] = 0;
                D_80163B48[D_801590D0] = NULL;
                D_80163B7C--;
            }
        }
    }
    D_801590D0 = 0;
}

void func_800BC538(void) {
    for (D_801590D4 = 0; D_801590D4 < 60; D_801590D4++) {
        if (D_80163B84[D_801590D4] != NULL) {
            ((void (*)(void))D_80163B84[D_801590D4])();
            if (D_801621F0[D_801590D4][0] == -1) {
                D_801621F0[D_801590D4][0] = 0;
                D_801621F0[D_801590D4][1] = 0;
                D_80163B84[D_801590D4] = NULL;
                D_80163C78--;
            }
        }
    }
    D_801590D4 = 0;
}

void func_800BC630(void) {
    D_800F8360 = 0;
    do {
        if (D_800FA978[D_800F8360] != 0) {
            ((void (*)(void))D_800FA978[D_800F8360])();
            if (D_800F7ED8[D_800F8360].a == -1) {
                D_800F7ED8[D_800F8360].a = 0;
                D_800F7ED8[D_800F8360].b = 0;
                D_800FA978[D_800F8360] = 0;
                D_800FA9BC -= 1;
            }
        }
        D_800F8360 += 1;
    } while (D_800F8360 < 0x10);
    D_800F8360 = 0;
}

void func_800BC72C(void) {
    func_800C1104();
    func_800BCA58(3);
}

void func_800BC754(void) {
    D_80158D00 = D_80163628[D_80163B3C].a;
    D_80158D02 = D_80163628[D_80163B3C].b;
    D_80158D04 = D_80163628[D_80163B3C].c;
    D_801031E8 = D_80163628[D_80163B3C].d;
    D_801031EA = D_80163628[D_80163B3C].e;
    D_801031EC = D_80163628[D_80163B3C].f;
}

void func_800BC81C(s16 arg0, s16 arg1) {
    s32 i;
    if (D_801590DC == 0) {
        for (i = 0; i < 3; i++) {
            func_800BEA38(i, arg1, arg0);
            func_800BCB1C(i, arg1, arg0);
        }
        func_800BC630();
    }
}

void func_800BC8B0(s16 arg0) {
    s32 v;
    u16 *p;

    if (D_80163614 == 0x4E) {
        p = &D_8009D7BE;
        *p &= 0xFCFF;
    }
    if (D_800F7ED4 == 0x64) {
        if ((D_8009D7BE & 0x300) == 0x100) {
            func_800BC754();
        } else {
            D_801031E0 = 1;
            func_800BCA58(D_800F837C);
        }
        return;
    }
    if (D_800F3896 == 0 && D_800FAFDC == 0) {
        func_800BC72C();
        return;
    }
    v = arg0;
    if (v == -2) {
        D_801031E0 = 1;
        func_800BCA58(D_800F837C);
        return;
    }
    if (v == -1) {
        if ((D_8009D7BE & 0x300) == 0x100) {
            func_800BC754();
        } else {
            func_800BC72C();
        }
        return;
    }
    if ((D_8009D7BE & 0x300) == 0x100) {
        if ((u16)(arg0 - 0x3B) < 2 || v == 0x45 || v == 0x59 || v == 0x6D || v == 0x77 || v == 0xCB) {
            if (D_800F7DE4 == 1) {
                func_800BC72C();
            } else {
                D_801031E0 = 1;
                func_800BCA58(D_800F837C);
            }
        } else {
            func_800BC754();
        }
        return;
    }
    if (D_800F7DE4 == 1 && D_80163614 != 0x4E) {
        func_800BC72C();
    } else {
        D_801031E0 = 1;
        func_800BCA58(D_800F837C);
    }
}

void func_800BCA58(s16 arg0) {
    D_80158D00 = D_80151844[arg0].x;
    D_80158D02 = D_80151844[arg0].y;
    D_80158D04 = D_80151844[arg0].z;
    D_801031E8 = D_801518A4[arg0].x;
    D_801031EA = D_801518A4[arg0].y;
    D_801031EC = D_801518A4[arg0].z;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BCB1C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BE49C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BE69C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BE86C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BEA38);

s16 func_800BFA98(u8 *arg0, u8 arg1) {
    s32 lo;
    s32 hi;

    lo = arg0[D_8015184C[arg1].pos++];
    hi = arg0[D_8015184C[arg1].pos++];
    return (hi << 8) + lo;
}

s16 func_800BFB10(u8 *arg0, u8 arg1) {
    s32 lo;
    s32 hi;

    lo = arg0[D_801518AC[arg1].pos++];
    hi = arg0[D_801518AC[arg1].pos++];
    return (hi << 8) + lo;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BFB88);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BFDA0);

void func_800BFF88(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    BtlSVec sp10;
    s16 i;

    if (arg0 == 0xF) {
        func_800D54EC(D_80151774, &sp10);
    } else {
        func_800D3994(arg0, arg1, &sp10);
        func_800C0DD8(arg0, arg2, arg3);
    }
    i = arg2;
    D_80151844[i].x = sp10.vx + *(u16 *)0x1F800000;
    D_80151844[i].y = sp10.vy + *(u16 *)0x1F800004;
    D_80151844[i].z = sp10.vz + *(u16 *)0x1F800008;
}

void func_800C0088(s16 arg0, s16 arg1, s16 arg2) {
    BtlSVec sp10;
    u8 id;
    s16 i;
    s32 *p;

    if (arg0 == 0xF) {
        func_800D54EC(D_80151774, &sp10);
    } else {
        func_800D3994(arg0, arg1, &sp10);
        id = arg0 & 0xFF;
        p = (s32 *)0x1F800004;
        *p = func_800C0314(*p, id);
    }
    i = arg2;
    D_801518A4[i].x = sp10.vx + *(u16 *)0x1F800000;
    D_801518A4[i].y = sp10.vy + *(u16 *)0x1F800004;
    D_801518A4[i].z = sp10.vz + *(u16 *)0x1F800008;
}

void func_800C018C(s16 arg0, s16 arg1, u8 arg2, u8 arg3) {
    BtlSVec v;

    if (arg0 == 15) {
        func_800D54EC(D_80151774, &v);
    } else {
        func_800D3994(arg0, arg1, &v);
        func_800C0DD8(arg0, arg2, arg3);
    }
    *(s32 *)0x1F800000 += v.vx;
    *(s32 *)0x1F800004 += v.vy;
    *(s32 *)0x1F800008 += v.vz;
}

void func_800C0254(s16 arg0, s16 arg1) {
    BtlSVec v;

    if (arg0 == 15) {
        func_800D54EC(D_80151774, &v);
    } else {
        func_800D3994(arg0, arg1, &v);
        *(s32 *)0x1F800004 = ((s32 (*)(s32, u8))func_800C0314)(*(s32 *)0x1F800004, arg0);
    }
    *(s32 *)0x1F800000 += v.vx;
    *(s32 *)0x1F800004 += v.vy;
    *(s32 *)0x1F800008 += v.vz;
}

s32 func_800C0314(s32 arg0, s32 arg1) {
    if (D_801518E6[arg1 & 0xFF][0] == 1 && D_80151230[arg1 & 0xFF][0] > 0) {
        return arg0;
    }
    return arg0 + D_80151230[arg1 & 0xFF][0];
}

s16 func_800C03B8(s16 arg0, s16 arg1) {
    s32 temp_a0;

    temp_a0 = arg0 - arg1;
    return func_80039F5C(temp_a0 * temp_a0, arg1);
}

s32 func_800C03FC(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg1;
    if (arg0 < 0) {
        var_v0 = -var_v0;
    }
    return var_v0;
}

void func_800C0410(void) {
    s32 i;

    i = D_800F8360;
    switch (D_800F7ED8[i].b) {
    case 0:
        func_800C0480(i);
        i = D_800F8360;
    case 1:
        func_800C0630(i);
        break;
    }
}

void func_800C0480(s16 arg0) {
    BtlT28b *p;

    p = (BtlT28b *)&D_800F7ED8[arg0];
    p->b++;
    if (D_80151850[p->x12 * 0xE + 1] == 0) {
        p->x1E = 0;
        p->x1A = p->x4;
        return;
    }
    p->x14 = ((func_800C03FC(p->x6 - p->xC, func_800C03B8(p->x6, p->xC)) + 1) * 16) / p->x4;
    p->x16 = ((func_800C03FC(p->x8 - p->xE, func_800C03B8(p->x8, p->xE)) + 1) * 16) / p->x4;
    p->x18 = ((func_800C03FC(p->xA - p->x10, func_800C03B8(p->xA, p->x10)) + 1) * 16) / p->x4;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0630);

void func_800C0900(void) {
    s32 i;

    i = D_800F8360;
    switch (D_800F7ED8[i].b) {
    case 0:
        func_800C0970(i);
        i = D_800F8360;
    case 1:
        func_800C0B20(i);
        break;
    }
}

void func_800C0970(s16 arg0) {
    BtlT28b *p;

    p = (BtlT28b *)&D_800F7ED8[arg0];
    p->b++;
    if (D_801518B0[p->x12 * 0xE] == 0) {
        p->x1E = 0;
        p->x1A = p->x4;
        return;
    }
    p->x14 = ((func_800C03FC(p->x6 - p->xC, func_800C03B8(p->x6, p->xC)) + 1) * 16) / p->x4;
    p->x16 = ((func_800C03FC(p->x8 - p->xE, func_800C03B8(p->x8, p->xE)) + 1) * 16) / p->x4;
    p->x18 = ((func_800C03FC(p->xA - p->x10, func_800C03B8(p->xA, p->x10)) + 1) * 16) / p->x4;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0B20);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0DD8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C1104);

s32 func_800C1304(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 d;
    d = arg1 - arg0;
    return arg0 + (func_80039B40((arg3 << 11) / arg2 + 0x800) + 0x1000) * d / 8192;
}

void func_800C1394(s32 arg0) {
    s32 i;
    u8 *row;
    u8 *p;

    i = arg0 & 0xFF;
    row = D_80151A58[i];

    D_8015246E[i].b = D_80151226[i].a;
    D_8015246E[i].a += 0x80;
    p = &row[0x9F4];
    func_8003C21C((s32)&row[0xA14], (s32)p);
    func_800BAF34((BtlCoord34 *)p);
    *(u8 **)0x1F800020 = D_800EA470;
    *(s32 *)0x1F800024 = 0x90;
    *(s16 *)0x1F80002E = 0;
    *(s16 *)0x1F80002A = 0;
    *(s16 *)0x1F800028 = 0;
    *(s16 *)0x1F80002C = 0x20;
    D_80163C74 = func_800D29D4((void *)0x1F800020, D_801517C0 + 0x70, 0xC, D_80163C74);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C14C0);

s32 func_800C169C(s32 arg0) {
    s32 i;
    s32 v;
    u32 f;

    i = arg0 & 0xFF;
    v = D_80151908[i].a | 8;
    D_80151908[i].a = v;
    f = D_80151200[i].f;
    if (f & 0x2000) {
        return 0xA;
    }
    if (f & 0x4000) {
        return 5;
    }
    if (f & 8) {
        return 1;
    }
    if (f & 0x800000) {
        return 3;
    }
    if (f & 0x1000000) {
        return 6;
    }
    if (f & 0x4000000) {
        return 8;
    }
    if (f & 0x8000) {
        return 9;
    }
    if (f & 0x400000) {
        return 7;
    }
    D_80151908[i].a = v & 0xF7;
    return 0;
}

void func_800C17A0(s32 arg0, s32 arg1) {
    switch (D_800EA19C[arg1].t) {
    case 0:
        D_801518F8[arg0].w = 0;
        break;
    case 1:
        D_801518F8[arg0].w = 0x800;
        break;
    case 2:
        D_801518F8[arg0].w = 0xC00;
        break;
    }
    D_8015190C[arg0].r = D_800EA19C[arg1].r;
    D_8015190C[arg0].g = D_800EA19C[arg1].g;
    D_8015190C[arg0].bl = D_800EA19C[arg1].b;
    D_80151908[arg0].pad0 = 0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C1908);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C1D8C);

void func_800C2000(u8 arg0, s16 arg1) {
    u16 *p;

    p = D_800F4B04;
    p[0] = D_80151A80[arg0][0];
    p[1] = D_8015122A[arg0][0];
    p[2] = D_80151A80[arg0][2];
    D_80163C74 = func_800C1D8C(D_801517C0 + 0x70, p, D_800EA1E8[(D_800EA1EC >> 3) & 3], arg1);
    D_800EA1EC++;
}

void func_800C20E8(s16 n, s16 *out) {
    s32 i;

    i = 0;
    do {
        out[3 - i++] = n % 10;
        n /= 10;
    } while (i < 4);
}

void func_800C2150(u8 arg0, u8 arg1) {
    u16 *p;

    p = D_800F4B08;
    p[0] = D_80151A80[arg0][0];
    p[1] = D_8015122A[arg0][0];
    p[2] = D_80151A80[arg0][2];
    if (arg1 != 0xFF) {
        func_800C20E8(arg1, D_800F4B0C);
        D_80163C74 = func_800C223C(D_801517C0 + 0x70, D_800F4B08, D_800F4B0C[2], D_800F4B0C[3]);
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C223C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2704);

void func_800C2864(u8 arg0) {
    if (D_80163C7C == 4 && D_800FAFDC == 0 && D_801620A4 == 0) {
        D_80163C74 = func_800C2704(D_801517C0 + 0x4084, D_80151700[arg0].x + 3, D_80151700[arg0].y - 0xE, 0, 0xD0, 0x30, 0x10, 0);
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2928);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2C1C);

u8 func_800C2F20(s16 arg0, s16 *arg1) {
    s32 i;
    s32 t;
    s32 q;
    s32 j;

    for (i = 0; i < 4; i++) {
        j = 3 - i;
        t = arg0;
        q = t / 10;
        arg0 = q;
        arg1[j] = (t - q * 10) * 8 + 0x98;
    }
    for (i = 0; i < 3; i++) {
        if (arg1[i] != 0x98) {
            return 4 - i;
        }
        arg1[i] = 0;
    }
    return 1;
}

void func_800C2FD4(u8 arg0, s16 arg1, u8 arg2) {
    if (arg2 != 0) {
        ((BtlMsgA *)&D_8009A000)->op = 0x2A;
        D_8009A008 = arg1;
        D_8009A004 = (D_801516FC[arg0].a.a / 5 * 2) & 0x7E;
        func_8002DA7C();
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C3068);

void func_800C328C(void) {
    s32 i;
    s32 s;
    s32 v;

    i = D_8015169C;
    switch ((s16)D_8016297A[i].b) {
    case 0:
        D_8016297A[i].c = 0xE;
        s = D_8016297A[i].e;
        D_8016297A[i].b++;
        func_800C2FD4(s, 0x16, (u8)D_8016297A[i].d);
        D_80151232[s][1] = 3;
        v = s * 0xB9C;
        *((u8 *)D_8015190C + v) = 0xF8;
        *((u8 *)D_8015190C + 1 + v) = 0;
        *((u8 *)D_8015190C + 2 + v) = 0;
        *(u16 *)((u8 *)D_801518F8 + v) = 0x800;
        func_800B5FE8(s);
    case 1:
        func_800C3068(D_8015169C);
        return;
    }
}

void func_800C33F0(u8 arg0) {
    s32 s;
    s32 o;

    s = D_8016297A[arg0].e;
    if (D_8016297A[arg0].c == 0) {
        D_80162978[arg0].a = -1;
        o = s * 0xB9C;
        D_8015190A[o - 1] &= 0x7F;
        do {
            D_8015120C[s][0] &= 0xFFDF;
        } while (0);
        D_8015190A[o] = 1;
        func_800B5AAC(s);
    } else {
        D_801518F8[s].w += 0x80;
        D_8015190C[s].r += 0xF0;
        D_8016297A[arg0].c--;
    }
}

void func_800C3578(void) {
    s32 i;
    s32 s;
    s32 v;

    i = D_8015169C;
    switch ((s16)D_8016297A[i].b) {
    case 0:
        D_8016297A[i].c = 0xE;
        s = D_8016297A[i].e;
        D_8016297A[i].b++;
        func_800C2FD4(s, 0x16, (u8)D_8016297A[i].d);
        v = s * 0xB9C;
        *((u8 *)D_8015190C + v) = 0xF8;
        *((u8 *)D_8015190C + 1 + v) = 0;
        *((u8 *)D_8015190C + 2 + v) = 0;
        *(u16 *)((u8 *)D_801518F8 + v) = 0x800;
        func_800B5FE8(s);
    case 1:
        func_800C33F0(D_8015169C);
        return;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C36B4);

void func_800C3950(void) {
    s32 i;
    s32 s;

    i = D_801590D0;
    switch ((s16)D_801620AE[i].b) {
    case 0:
        D_801620AE[i].c = 0xE;
        s = D_801620AE[i].e;
        D_801620AE[i].b++;
        func_800C2FD4(s, 0x16, (u8)D_801620AE[i].d);
        D_801518F8[s].w = 0x800;
        D_8015190C[s].r = D_801620AE[D_801590D0].f;
        D_8015190C[s].g = 0;
        D_8015190C[s].bl = 0;
        func_800B5FE8(s);
    case 1:
        func_800C36B4(D_801590D0);
        return;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C3AA0);

void func_800C3CA8(void) {
    s32 i;
    s32 s;
    s32 v;

    i = D_8015169C;
    switch ((s16)D_8016297A[i].b) {
    case 0:
        D_8016297A[i].c = 0xE;
        s = D_8016297A[i].e;
        D_8016297A[i].b++;
        func_800C2FD4(s, 0x16, (u8)D_8016297A[i].d);
        v = s * 0xB9C;
        *((u8 *)D_8015190C + v) = 0xF8;
        *((u8 *)D_8015190C + 1 + v) = 0;
        *((u8 *)D_8015190C + 2 + v) = 0;
        *(u16 *)((u8 *)D_801518F8 + v) = 0x800;
        func_800B5FE8(s);
    case 1:
        func_800C3AA0(D_8015169C);
        return;
    }
}

void func_800C3DE4(void) {
    s32 i;
    s32 b;

    b = D_801621F0[D_801590D4][4];
    i = D_801590D4;
    if (D_801621F0[D_801590D4][2] == 0) {
        D_801621F0[i][0] = -1;
    } else {
        if (D_801621F0[D_801590D4][2] == 0x3A || D_801621F0[D_801590D4][2] == 0x40) {
            D_80163C74 = ((u8 *(*)(s32, s32, s32))func_800C4FC8)(0xFA, 0xFA, 0xFA);
        }
        if (D_801621F0[i][2] & 1) {
            D_80151A24[b].z = D_801621F0[i][5] + 0x40;
        } else {
            D_80151A24[b].z = D_801621F0[i][5] - 0x40;
        }
        D_801621F0[i][2]--;
    }
}

void func_800C3F44(u8 arg0) {
    s32 s;
    s32 o;

    s = D_8016297A[arg0].e;
    if (D_8016297A[arg0].c == 1) {
        D_80162978[arg0].a = -1;
        o = s * 0xB9C;
        D_8015190A[o - 1] &= 0x7F;
        do {
            D_8015120C[s][0] &= 0xFFDF;
        } while (0);
        D_8015190A[o] = 1;
        D_8015190C[s].r = 0;
        D_801518F8[s].w = 0x1000;
        func_800B5AAC(s);
    } else {
        D_801518F8[s].w += 0x20;
        D_8015190C[s].r += 0xFC;
        D_8016297A[arg0].c--;
    }
}

void func_800C40F4(void) {
    s32 i;
    s32 s;
    s32 r;
    s32 v;

    i = D_8015169C;
    switch ((s16)D_8016297A[i].b) {
    case 0:
        s = *(s16 *)(D_80162980 + (i << 5));
        *(s16 *)(D_80162980 - 4 + (i << 5)) = 0x40;
        D_8016297A[i].b++;
        func_800C2FD4(s, 0x1C0, D_8016297E[i << 5]);
        r = func_800BC04C(func_800C3DE4);
        D_801621F0[r][4] = s;
        D_801621F0[r][2] = 0x40;
        D_801621F0[r][5] = D_80151A4C[s].v.c;
        v = s * 0xB9C;
        *((u8 *)D_8015190C + v) = 0xFF;
        *((u8 *)D_8015190C + 1 + v) = 0;
        *((u8 *)D_8015190C + 2 + v) = 0;
        *(u16 *)((u8 *)D_801518F8 + v) = 0x800;
        func_800B5FE8(s);
    case 1:
        func_800C3F44((u8)D_8015169C);
        return;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C428C);

void func_800C44B4(void) {
    s32 i;
    s32 s;
    s32 v;

    i = D_8015169C;
    switch ((s16)D_8016297A[i].b) {
    case 0:
        D_8016297A[i].c = 0x10;
        s = D_8016297A[i].e;
        D_8016297A[i].b++;
        func_800C2FD4(s, 0x16, (u8)D_8016297A[i].d);
        v = s * 0xB9C;
        *((u8 *)D_8015190C + v) = 0x80;
        *((u8 *)D_8015190C + 1 + v) = 0x80;
        *((u8 *)D_8015190C + 2 + v) = 0x80;
        *(u16 *)((u8 *)D_801518F8 + v) = 0;
        func_800B5FE8(s);
    case 1:
        func_800C428C(D_8015169C);
        return;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C45EC);

void func_800C4814(void) {
    s32 i;
    s32 s;
    s32 v;

    i = D_8015169C;
    switch ((s16)D_8016297A[i].b) {
    case 0:
        D_8016297A[i].c = 0x10;
        s = D_8016297A[i].e;
        D_8016297A[i].b++;
        func_800C2FD4(s, 0x16, (u8)D_8016297A[i].d);
        v = s * 0xB9C;
        *((u8 *)D_8015190C + v) = 0x80;
        *((u8 *)D_8015190C + 1 + v) = 0x80;
        *((u8 *)D_8015190C + 2 + v) = 0x80;
        *(u16 *)((u8 *)D_801518F8 + v) = 0;
        func_800B5FE8(s);
    case 1:
        func_800C45EC(D_8015169C);
        return;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C494C);

void func_800C4B60(s16 arg0) {
    if (D_801621F0[arg0][2] == 0) {
        D_801621F0[arg0][0] = -1;
        return;
    }
    D_80163C74 = func_800C4DC8(0, D_801621F0[arg0][5], 0x140, 0x2F, D_800EA25C);
    D_80163C74 = func_800C4DC8(0, D_801621F0[arg0][5] + 0x2F, 0x140, 0x20, D_800EA258);
    D_80163C74 = func_800C4DC8(0, D_801621F0[arg0][4], 0x140, 0x20, D_800EA260);
    D_80163C74 = func_800C4DC8(0, D_801621F0[arg0][4] + 0x20, 0x140, 0x2F, D_800EA25C);
    D_801621F0[arg0][4] += 4;
    D_801621F0[arg0][5] -= 4;
    D_801621F0[arg0][2]--;
}

void func_800C4D10(void) {
    s32 i;

    i = D_801590D4;
    switch (D_801621F0[i][1]) {
    case 0:
        D_801621F0[i][2] = 0x15;
        D_801621F0[i][4] = 0x57;
        D_801621F0[i][5] = 8;
        D_801621F0[i][1]++;
    case 1:
        func_800C4B60(i);
        break;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C4DC8);

void func_800C4FC8(s32 arg0, s32 arg1, s32 arg2) {
    func_800C5040(arg0 & 0xFF, arg1 & 0xFF, arg2 & 0xFF, 1, D_801517C0 + 0x4084);
}

void func_800C5004(s32 arg0, s32 arg1, s32 arg2) {
    func_800C5040(arg0 & 0xFF, arg1 & 0xFF, arg2 & 0xFF, 2, D_801517C0 + 0x40EC);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C5040);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C5170);

void func_800C5468(s32 arg0) {
    s32 i;
    s32 n;
    u16 a;

    i = arg0 & 0xFF;
    if (D_80151200[i].f & 0x1000) {
        a = D_8015120C[i][0];
        if (!(a & 0x80)) {
            D_8015120C[i][0] = a | 0x80;
            n = func_800BC04C(func_800C55B8);
            D_801621F0[n][3] = (u8)arg0;
            D_801621F0[n][2] = 0x10;
            D_801621F0[n][1] = -0x80;
        }
    } else {
        a = D_8015120C[i][0];
        if (a & 0x80) {
            D_8015120C[i][0] = a & 0xFF7F;
            n = func_800BC04C(func_800C55B8);
            D_801621F0[n][3] = (u8)arg0;
            D_801621F0[n][2] = 0x10;
            D_801621F0[n][1] = 0x80;
        }
    }
}

void func_800C55B8(void) {
    if (D_801621F0[D_801590D4][2] == 0) {
        D_801621F0[D_801590D4][0] = -1;
        return;
    }
    D_801518EA[D_801621F0[D_801590D4][3]].a += D_801621F0[D_801590D4][1];
    D_801621F0[D_801590D4][2]--;
}

void func_800C5694(void) {
    s16 i;

    if (D_80162978[D_8015169C].c == 0) {
        D_80162978[D_8015169C].a = -1;
        i = D_80162978[D_8015169C].d;
        D_8015190A[i * 0xB9C] = 1;
        return;
    }
    i = D_80162978[D_8015169C].d;
    D_801518EA[i].a += D_80162978[D_8015169C].b;
    D_80162978[D_8015169C].c--;
}

void func_800C57B0(void) {
    s32 i;
    BtlCoord34 *p;
    u8 *f;

    p = D_8015E1E8.o;
    f = D_8015E1E8.f[0];
    for (i = 0; i < 256; i++) {
        p->t.vx = (func_800B2F50() & 0x3FFF) - 0x2000;
        p->t.vy = -10000 - func_800B2F50() / 2;
        p->t.vz = (func_800B2F50() & 0x3FFF) - 0x2000;
        p->r.vx = 0;
        p->r.vy = 0;
        p->r.vz = 0;
        p->super = &D_800FA63C;
        p++;
        f[0] = 0;
        f[1] = 0;
        f += 2;
    }
}

void func_800C5864(void) {
    s32 i;
    BtlCoord34 *c;
    u8 *f0;
    u8 *f1;

    c = D_8015E1E8.o;
    f0 = D_8015E1E8.f[0];
    i = 0;
    f1 = &D_8015E1E8.f[0][1];
    for (; i < 256; i++, f0 += 2) {
        switch (*f0) {
        case 0:
            if (c->t.vy > 0) {
                *f0 = 1;
            } else {
                c->t.vy += 0x190;
            }
            break;
        case 8:
            *f0 = 0;
            c->t.vy = -10000 - func_800B2F50() / 2;
            break;
        default:
            c->t.vy = 0;
            break;
        }
        func_8003C21C((s32)&c->r, (s32)c);
        func_800BAF34(c);
        if (*f0 == 0) {
            D_80163C74 = func_800C5ADC(D_801517C0 + 0x70);
        } else {
            *f0 += 1;
            *f1 += 0x20;
            D_80163C74 = func_800C59B8(D_801517C0 + 0x4078, *f1);
        }
        c++;
        f1 += 2;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C59B8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C5ADC);

void func_800C5BEC(void) {
    s32 i;
    s16 v = -1;

    i = 0x17A;
    do {
        *(s16 *) (D_800F9DA8 + i) = v;
        i -= 6;
    } while (i >= 0);
}

void func_800C5C18(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 j;
    s32 c;

    for (i = 0; i < 0x40; i++) {
        j = i * 6;
        if (*(s16 *)(D_800F9DA8 + j) == -1) {
            c = arg1 + 0xFF;
            *(s16 *)(D_800F9DA8 + j) = arg0;
            D_800F9DA8[j + 4] = c;
            *(s16 *)(D_800F9DA8 + j + 2) = arg3;
            if ((u8)arg2 == 0) {
                D_800F9DA8[j + 5] = func_800C60F4();
            } else {
                D_800F9DA8[j + 5] = arg2;
            }
            return;
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C5CC0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C5E94);

s32 func_800C60F4(void) {
    return ((u8) D_8009D7BD >> 2) + 4;
}

void func_800C610C(void) {
    while (D_801518DC != 0) {
        func_800B7FB4();
    }
}

void func_800C614C(s32 arg0, u8 arg1) {
    Unk80046D0C info;
    s32 *dst;
    s32 i;
    s32 *v;

    dst = D_800F8CF4[arg1];
    func_80046CFC(arg0);
    func_80046D0C(&info);
    for (i = 0; i < 0x18; i++) {
        v = (s32 *) info.a_arg;
        info.a_arg += 4;
        *dst++ = *v;
    }
}

void func_800C61C0(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_801636B8[i].a == 6) {
            D_800F4B1C.x = 0x10;
            D_800F4B1C.y = 0x1E0;
            D_800F4B1C.w = 0x10;
            D_800F4B1C.h = 3;
            func_800D2538((s32)&D_800F4B1C, (s32)D_800F8CF4[i]);
        }
    }
}

void func_800C627C(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        func_800C62F4(i);
    }
    D_800F4B24.x = 0;
    D_800F4B24.y = 0x1E0;
    D_800F4B24.w = 0x10;
    D_800F4B24.h = 0x1E;
    func_800D2538((s32)&D_800F4B24, (s32)&D_80158D0C);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C62F4);

void func_800C64AC(void) {
    func_800BBEAC(&func_800C679C);
}

void func_800C64D4(void) {
    s32 i;
    s32 j;
    s32 o;
    s32 o2;

    for (i = 4; i < 10; i++) {
        o = i * 0xB9C;
        D_80151780[i] = (&D_80151909)[o];
        D_80151922[i][0] |= 2;
    }
    for (i = 4; i < 10; i++) {
        if (D_80151780[i] & 4) {
            D_80151922[i][0] &= 0xFD;
        }
        if ((D_80151774 >> i) & 1) {
            for (j = 4; j < 10; j++) {
                o2 = j * 0xB9C;
                if ((s16)D_80163C80[i].a == (s16)D_80163C80[j].a && (s16)D_80163C80[i].c == (s16)D_80163C80[j].c) {
                    (&D_80154792)[o2 - 0x2E70] &= 0xFD;
                }
            }
        }
    }
}

void func_800C6628(void) {
    s32 i;
    s32 j;
    s32 o;
    s32 o2;

    for (i = 4; i < 10; i++) {
        o = i * 0xB9C;
        if (!((D_80151774 >> i) & 1) && !(D_80151780[i] & 4)) {
            (&D_80151909)[o + 0x19] |= 4;
            (&D_80151909)[o] &= 0xFB;
        }
    }
    for (i = 4; i < 10; i++) {
        if ((D_80151774 >> i) & 1) {
            for (j = 4; j < 10; j++) {
                o2 = j * 0xB9C;
                if (i != j && (s16)D_80163C80[i].a == (s16)D_80163C80[j].a && (s16)D_80163C80[i].c == (s16)D_80163C80[j].c) {
                    (&D_80151909)[o2 + 0x19] &= 0xFB;
                    (&D_80151909)[o2] &= 0xFB;
                }
            }
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C679C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C6CB8);

void func_800C70AC(void) {
    s32 j;
    s32 o;
    s16 t;

    if (D_801621F0[D_801590D4][1] == 0) {
        if (D_80162080 == 0) {
            for (j = 0; j < 3; j++) {
                o = j * 0xB9C;
                (&D_80151909)[o + 0x19] |= 4;
                if (D_8009CBDC[j] != 0xFF) {
                    (&D_80151909)[o] &= 0xFD;
                }
            }
            if (D_800FA6D0 == 4) {
                func_800C6628();
            }
            D_800F8374 = 0xE;
            D_801621F0[D_801590D4][1] = 1;
            D_801621F0[D_801590D4][2] = 0xE;
        }
    } else {
        t = D_801621F0[D_801590D4][2];
        if (t == 0) {
            D_801621F0[D_801590D4][0] = -1;
            D_800FAFDC = 0;
            D_80153BDE = 1;
            return;
        }
        D_801621F0[D_801590D4][2] = t - 1;
    }
}

void func_800C7220(void) {
    s16 t;
    s32 o;
    u8 *q;
    u8 *p;

    o = D_801590D4 << 5;
    if (*(s16 *)((u8 *)D_801621F0 + 2 + o) == 0) {
        p = &D_80153BF6;
        *p |= 2;
        D_800F8374 = 0xE;
        *(s16 *)((u8 *)D_801621F0 + 2 + o) = 1;
        *(s16 *)((u8 *)D_801621F0 + 4 + o) = 0xE;
    } else {
        t = *(s16 *)((u8 *)D_801621F0 + 4 + o);
        if (t == 0) {
            q = &D_80153BDD;
            *q = (*q | 2) & 0xEF;
            *(s16 *)((u8 *)D_801621F0 + o) = -1;
            D_80153BDE = 1;
            return;
        }
        *(s16 *)((u8 *)D_801621F0 + 4 + o) = t - 1;
    }
    func_800B60E0(3);
    func_800C74A4();
    if (!(D_80153BDD & 2)) {
        func_800BA598(3);
    }
}

void func_800C7340(void) {
    if (D_800F8364 == 0xFF) {
        D_80162978[D_8015169C].a = -1;
        if (D_80162098 == 0) {
            func_800BC04C(func_800C70AC);
        } else {
            func_800BC04C(func_800C7220);
        }
    }
    if (D_800F8364 == 0) {
        D_800F8364 = 1;
        D_801031E0 = 1;
        D_80153D20 = D_80151778;
        D_80153D22 = D_8015177A;
        D_80153D24 = D_8015177C;
        D_80153D1A = D_800FAFE8;
    }
    func_800B60E0(3);
    func_800C74A4();
    if (D_80162098 != 0 && (s16)D_8016297A[D_8015169C].b == 0) {
        D_8016297A[D_8015169C].b = 1;
        return;
    }
    if (!(D_80153BDD & 2)) {
        func_800BA598(3);
    }
}

void func_800C74A4(void) {
    if (!(D_80153BDD & 2)) {
        func_800C7C4C(3, M2C_FIELD(D_800F57D0, s32 *, 8), D_800F57D0 + 0xC, D_800F57D0);
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C74E4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C76C8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C7924);

s32 func_800C7B60(s16 arg0, s16 arg1, s32 arg2) {
    s32 r;
    r = func_800D376C(D_80151A58[arg0], D_80151958[arg0][0], arg1, arg2);
    D_80151958[arg0][0] = r;
    return r == 0;
}

void func_800C7BE8(s16 arg0, s16 arg1, s32 arg2) {
    D_800FA6D8[arg0].a = func_800D376C(D_800FA6D8[arg0].b, D_800FA6D8[arg0].a, arg1, arg2);
}
