#include "common.h"
#include "battle/decls.h"

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B30E4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B33A4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B36B4);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B3A04);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B3AB8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B3B84);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B3E2C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B45F0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B46B4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B4794);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B4E30);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B5138);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B54B8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B588C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B5AAC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B5C1C);

s32 func_800B5CD4(s32 arg0) {
    s32 *p;

    p = (s32 *)0x801B0000;
    func_8001C3CC(D_800F8390[arg0], 0x801B0000, p[*p]);
    return p[*p];
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B5D38);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B5E64);

void func_800B5FC4(s16 arg0) {
    func_800B60E0(arg0);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B5FE8);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B7DB4);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B8268);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B8438);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B8944);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B8A34);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B8B48);

void func_800B8E48(u8 arg0) {
    D_80151908[arg0].b = 1;
    D_80151908[arg0].a &= 0x7F;
    D_8015120C[arg0][0] &= 0xFFDF;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B8EE4);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B905C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B91CC);

void func_800B950C(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        D_801516FC[i].a.a = D_801516FC[i].b.a;
        D_801516FC[i].a.b = D_801516FC[i].b.b;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B9568);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BA11C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BA40C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BA4C8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BA598);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BACEC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BAF34);

void func_800BAFF8(s32 arg0) {
    func_8003B35C();
    func_8003B48C(arg0);
    func_8003B51C(arg0);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BB030);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BB2A8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BB430);

void func_800BB4F8(void) {
    u32 *p;

    p = (u32 *) 0x801B0000;
    func_800D2980(p[p[0]] + (s32) p, 0, 0, 0);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BB538);

void func_800BB67C(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0x30) = arg0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BB684);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BBDF8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BBEAC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BBF7C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BC04C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BC11C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BC1E0);

void func_800BC2F0(void) {
    s32 i;

    D_800FA9BC = 0;
    for (i = 0; i < 16; i++) {
        D_800FA978[i] = 0;
        D_800F7ED8[i].a = 0;
        D_800F7ED8[i].b = 0;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BC348);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BC440);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BC538);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BC630);

void func_800BC72C(void) {
    func_800C1104();
    func_800BCA58(3);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BC754);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BC8B0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BCA58);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BFF88);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0088);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C018C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0254);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0480);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0970);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0B20);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0DD8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C1104);

s32 func_800C1304(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 d;
    d = arg1 - arg0;
    return arg0 + (func_80039B40((arg3 << 11) / arg2 + 0x800) + 0x1000) * d / 8192;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C1394);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C14C0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C169C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C17A0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C1908);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C1D8C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2000);

void func_800C20E8(s16 n, s16 *out) {
    s32 i;

    i = 0;
    do {
        out[3 - i++] = n % 10;
        n /= 10;
    } while (i < 4);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2150);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C223C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2704);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2864);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2928);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2C1C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2F20);

void func_800C2FD4(u8 arg0, s16 arg1, u8 arg2) {
    if (arg2 != 0) {
        ((BtlMsgA *)&D_8009A000)->op = 0x2A;
        D_8009A008 = arg1;
        D_8009A004 = (D_801516FC[arg0].a.a / 5 * 2) & 0x7E;
        func_8002DA7C();
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C3068);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C328C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C33F0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C3578);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C36B4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C3950);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C3AA0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C3CA8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C3DE4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C3F44);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C40F4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C428C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C44B4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C45EC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C4814);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C494C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C4B60);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C4D10);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C4DC8);

void func_800C4FC8(s32 arg0, s32 arg1, s32 arg2) {
    func_800C5040(arg0 & 0xFF, arg1 & 0xFF, arg2 & 0xFF, 1, D_801517C0 + 0x4084);
}

void func_800C5004(s32 arg0, s32 arg1, s32 arg2) {
    func_800C5040(arg0 & 0xFF, arg1 & 0xFF, arg2 & 0xFF, 2, D_801517C0 + 0x40EC);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C5040);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C5170);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C5468);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C55B8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C5694);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C57B0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C5864);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C61C0);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C64D4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C6628);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C679C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C6CB8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C70AC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C7220);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C7340);

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
