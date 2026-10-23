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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B383C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B38E0);

void func_800B3934(void) {
    func_800B5D38(2);
    func_800B5CD4(2);
    D_80166F64 = 3;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B3968);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B3A04);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B3AB8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B3B84);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B3C50);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B3CD0);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B5CD4);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B798C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B83C4);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B88CC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B8944);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B8A34);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B8B48);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B8E48);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B8EE4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B8FCC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B905C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B91CC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B950C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800B9568);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BA11C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BA24C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BA2BC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BA360);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BB75C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BB89C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BBA84);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BC81C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BC8B0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BCA58);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BCB1C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BE49C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BE69C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BE86C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BEA38);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BFA98);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BFB10);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BFB88);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BFDA0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800BFF88);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0088);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C018C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0254);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0314);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0410);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0480);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0630);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0900);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0970);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0B20);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C0DD8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C1104);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C1304);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C1394);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C14C0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C169C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C17A0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C1908);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C1D8C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2000);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C20E8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2150);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C223C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2704);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2864);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2928);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2C1C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2F20);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C2FD4);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C5C18);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C614C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C61C0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C627C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C7B60);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C7BE8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800C7C4C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CD400);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CD558);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CD5E4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CD798);

void func_800CD82C(void) {
    D_801590DC = 1;
    D_801621F0[D_801590D4][0] = -1;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CD860);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CDD44);

void func_800CDDA4(void) {
    u16 var_v0;

    if (D_80166F68 != 0) {
        var_v0 = D_800F9DA4 | 1;
    } else {
        var_v0 = D_800F9DA4 & 0xFFFE;
    }
    D_800F9DA4 = var_v0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CDDE8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CDE78);

void func_800CDF6C(s32 arg0, s16 arg1) {
    func_800BBA84(0x14, arg1, 0);
    func_800D58D0(arg0, 1, 1);
    func_800D4D4C(D_800FA6D4, 0x2C);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CDFC4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CE058);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CE0C8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CE21C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CE384);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CE638);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CE75C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CE7E0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CE970);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CEB48);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CF2F0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CF3CC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CF4A8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CF5BC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CF8C0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CFB14);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CFCB0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800CFE60);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D01C0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D0578);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D061C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D06B8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D0760);

void func_800D088C(s32 arg0, s32 arg1) {
    func_80033E34(arg0, arg1, 0x801B0000, 0);
    func_800B7FB4();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D08B8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D0958);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D09D0);

void func_800D0A44(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D0A4C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D0AD4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D0B4C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D0C80);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D1110);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D1530);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D25E8);

void func_800D26F8(void) {
    D_800F01DC = &D_800F4BAC;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D2710);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D2828);

void func_800D2980(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_800D2710(arg0, arg2, arg3);
    func_800D2828(arg0, arg1);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D29D4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D32B4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3354);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3418);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3474);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D34C8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3520);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3548);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D35D8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3658);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D376C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3994);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3A6C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3AF0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3BF0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3D88);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3E8C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3F0C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D3F8C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D415C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D41FC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D4284);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D4368);

void func_800D4484(s32 arg0, s32 arg1) {
    void *temp_s0;

    temp_s0 = D_80163C74;
    func_80044A68(temp_s0, 0, 1, arg1 & 0xFFFF, 0);
    func_80046794(arg0, (s32) temp_s0);
    D_80163C74 = temp_s0 + 0xC;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D44E8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D461C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D4710);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D491C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D4A64);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D4C08);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D4CBC);

void func_800D4D4C(s32 arg0, s32 arg1) {
    func_800D4CBC(arg0, arg1, 0x1000);
}

void func_800D4D6C(s32 arg0, s32 arg1, s32 arg2) {
    func_800D4C08(arg0, arg1, 0x1000, arg2);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D4D90);

Q20 *func_800D4FA8(s32 arg0) {
    s32 i;

    i = D_800F10D8;
    D_800F4CEC[i] = arg0;
    D_800F10D8 = (i + 1) & 0xF;
    return &D_800F4D2C[i];
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D4FF0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D508C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D5138);

void func_800D51D4(s32 arg0) {
    if (D_800F10E0 != NULL) {
        M2C_FIELD(D_800F10E0, s32 *, 0xC) = (s32) ((s32) -M2C_FIELD(D_800F10E0, s32 *, 4) / arg0);
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D5230);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D52A0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D5350);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D5444);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D54EC);

s32 func_800D55A4(s32 arg0) {
    return (D_801518EA[arg0].b * (D_801518EA[arg0].a << 4)) >> 12;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D55F4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D56A8);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D57C0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D58D0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D5938);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D5A68);

s32 func_800D5AC0(s32 arg0, s32 arg1) {
    return (((s32) (arg0 & 0xFF0000) / arg1) & 0xFF0000) | (((s32) (arg0 & 0xFF00) / arg1) & 0xFF00) | (((s32) (arg0 & 0xFF) / arg1) & 0xFF);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D5B6C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D5D28);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D61AC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D6260);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D6394);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D650C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D6734);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D6840);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D6998);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D6ACC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D6C20);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D6D8C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D6F78);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D70C0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D7178);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D72B4);

void func_800D7340(void) {
    func_800BBEAC(&func_800D72B4);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D7368);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D751C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D76B8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D7724);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D7888);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D7A88);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D7B1C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D7BA4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D7C2C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D7D3C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D8304);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D83A4);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D84F8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D85B0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D87EC);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D8A88);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D8B60);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D8D78);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D91DC);

void func_800D93DC(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D93E4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D9BF4);

u8 func_800D9DEC(s16 arg0) {
    return D_800F514C[arg0];
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D9E0C);

void func_800D9F5C(s16 arg0) {
    D_800F514C[arg0] = 3;
}

void func_800D9F80(void) {
    D_800F311C = 0;
    D_800FAFEC = -0x100;
    D_800FAFF0 = -0x100;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800D9FA4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DA380);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DB818);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DBC18);

void func_800DBEA4(s32 arg0, s16 arg1) {
    func_800DBC18(arg0, arg1);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DBEC8);

void func_800DBF54(void) {
    func_800269C0((s32) &D_80077F64);
}

void func_800DBF7C(void) {
    D_800F3122 = 0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DBF8C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DC0CC);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DCFD4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DD690);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DD85C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DDAD8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DDC34);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DDCE8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DDE90);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DDFEC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DE2B4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DE3CC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DE46C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DE618);

void func_800DE910(void) {
}

void func_800DE918(void) {
    D_80151840 = *D_8009D260;
    if ((u32) *D_8009D260 > 0x927C0U) {
        D_80151840 = 0x927C0;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DE94C);

void func_800DEB10(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DEB18);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DEC10);

void func_800DF244(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DF24C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DF2CC);

void func_800DF528(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DF530);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DF5C8);

void func_800DF7BC(void) {
}

void func_800DF7C4(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DF7CC);

void func_800DF8F0(void) {
}

void func_800DF8F8(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DF900);

void func_800DF9F0(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DF9F8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DFA94);

void func_800DFC38(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DFC40);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DFE34);

void func_800DFFDC(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800DFFE4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E010C);

void func_800E026C(void) {
}

void func_800E0274(void) {
    func_800E53C8();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E0294);

void func_800E03C8(void) {
}

void func_800E03D0(void) {
    func_800E4B88();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E03F0);

void func_800E0528(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E0530);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E05E4);

void func_800E078C(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E0794);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E084C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E08C4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E0BE0);

void func_800E0DF4(void) {
    s16 i;

    for (i = 0; i < 0x20; i++) {
        D_800F514C[i] = 0;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E0E34);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E15D8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E16B8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E1938);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E1A2C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E1AC0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E1C40);

void func_800E2054(s32 arg0, s32 arg1) {
    ((void (*)()) func_80027354)(0xB0, arg0, D_800F3184[arg1], 3);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E2098);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E2C6C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E3088);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E33A0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E368C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E3B64);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E3E10);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E3FB4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E4180);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E4394);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E4A64);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E4C08);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E5358);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E53C8);

s32 func_800E54EC(void) {
    if (D_800F33A0 == 0) {
        return 0;
    }
    if (D_800F33AA == D_800F5774) {
        return 2;
    }
    return 1;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E5530);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E5814);

void func_800E58B0(void) {
    D_800F3468 = 0;
    D_800F5760 = 0xA;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E58CC);

u8 func_800E593C(void) {
    return D_800F381C[D_80163604];
}

s32 func_800E5960(s32 arg0) {
    s32 var_v0;

    var_v0 = arg0;
    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }
    return var_v0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2", func_800E5978);
