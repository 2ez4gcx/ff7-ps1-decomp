#include "common.h"
#include "savemenu/decls.h"

void func_801D0408(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

s32 func_801D0448(s32 arg0) {
    s16 rect[4];
    volatile SvPrim *p;
    volatile SvPrim *volatile *pp;

    pp = &D_80062F24;
    D_80062F24->len = 3;
    D_80062F24->code = 0x60;
    func_80046848(*pp, 1);
    D_80062F24->x = 0;
    D_80062F24->y = 0;
    D_80062F24->w = 0x180;
    D_80062F24->h = 0xE8;
    D_80062F24->r = D_801D4EC4;
    D_80062F24->g = D_801D4EC4;
    D_80062F24->b = D_801D4EC4;
    p = *pp; *(volatile SvPrim **)pp = p + 1; func_80046794(D_80062FC4, (s32)p);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x5F, (s32)rect);
    D_801D4EC4 += arg0;
    if (D_801D4EC4 < 0) {
        D_801D4EC4 = 0;
    }
    if (D_801D4EC4 >= 0x100) {
        D_801D4EC4 = 0xFF;
    }
    return D_801D4EC4;
}

void func_801D05C0(s32 arg0) {
    D_801E3860 = 0xF0;
    D_801E36B8 = arg0 & 0xFF;
    D_801E3850 = 0;
    func_80026448(&D_801E379C, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0U);
    func_80025B8C((s32) &D_801E8F44);
    func_80025C14((s32) &D_801E4538);
    func_80025DF8();
    func_801D19C4();
}

void func_801D0670(void) {
    func_80025BD0(&D_801E8F44);
    func_80025C54(&D_801E4538);
    func_801D1BA4();
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D06B0);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D1774);

u16 func_801D1950(u16 arg0, u8 *arg1) {
    s32 crc;
    u16 i;
    u16 j;

    crc = 0xFFFF;
    for (i = 0; i < arg0; i++) {
        crc ^= arg1[i] << 8;
        for (j = 0; j < 8; j++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ 0x1021;
            } else {
                crc <<= 1;
            }
        }
    }
    return ~crc;
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D19C4);

void func_801D1BA4(void) {
}

void func_801D1BAC(s32 arg0, s32 arg1) {
    func_80042A30((&D_8009A024)[arg1]);
}

s32 func_801D1BE0(u8 *arg0, u8 *arg1) {
    do {
        if (*arg0++ != *arg1++) {
            return 0;
        }
    } while (*arg0 != 0 || *arg1 != 0);
    return 1;
}

INCLUDE_RODATA("../asm/us/savemenu/nonmatchings/text", D_801D0050);

u16 func_801D1C2C(s32 arg0) {
    u8 buf[0x28];
    s32 i;
    s32 dir;
    s32 mask;

    mask = 0;
    i = 0;
    do {
        dir = func_80042B70(arg0 ? "bu10:*" : "bu00:*", buf);
        i++;
    } while (dir == 0 && i < 100);
    if (dir != 0) {
        do {
            for (i = 0; i < 15; i++) {
                if (func_801D1BE0((u8 *)dir, D_801E2C78[i])) {
                    mask |= 1 << i;
                }
            }
            dir = func_80042B80(dir);
        } while (dir != 0);
    } else {
        mask = 0;
    }
    return mask;
}

u8 *func_801D1D1C(s32 arg0) {
    return D_801E3864[arg0];
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D1D40);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D1F40);

s32 func_801D2150(u8 arg0) {
    s32 ret;

    if ((arg0 >= 0x99 && arg0 <= 0x9F) || (arg0 >= 0xE1 && arg0 <= 0xFC)) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

s32 func_801D2184(u8 arg0) {
    s32 ret;

    if ((arg0 >= 0x81 && arg0 <= 0x9F) || (arg0 >= 0xE0 && arg0 <= 0xFC)) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

void func_801D21B8(u8 *arg0, u8 *arg1) {
    s32 var_v1;
    u8 *var_a0;
    u8 *var_a1;
    u8 temp_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v1 = 0;
    do {
        temp_v0 = *var_a1;
        var_a1 += 1;
        var_v1 += 1;
        *var_a0 = temp_v0;
        var_a0 += 1;
    } while (var_v1 < 0x40);
}

void func_801D21E0(s32 arg0) {
    D_801E2CB4 = arg0;
}

void func_801D21F0(u8 *arg0, u8 *arg1) {
    s32 pad;
    s32 i;

    for (i = 0; i < D_801E2CB4; i++) {
        *arg0++ = *arg1;
        if (*arg1 == 0xFF) {
            break;
        }
        arg1++;
    }
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D224C);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D2408);

s16 func_801D2A34(s32 arg0) {
    char path[0x40];
    s32 n;
    s16 ret;

    if (arg0 & 0x10) {
        func_80042DD8(path, D_801D018C, D_801E2C78[arg0 & 0xF]);
    } else {
        func_80042DD8(path, D_801D0194, D_801E2C78[arg0 & 0xF]);
    }
    n = arg0 & 0xF;
    D_801E3D50 = n;
    ret = func_801D2408(path, D_801E2CB8[n]);
    if (ret == 0) {
        *(SvHead *)D_801E3864[n] = *(SvHead *)D_8009C6E4;
    }
    return ret;
}

void func_801D2B58(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

s32 func_801D2B98(s32 arg0) {
    s16 rect[4];
    volatile SvPrim *p;
    volatile SvPrim *volatile *pp;

    pp = &D_80062F24;
    D_80062F24->len = 3;
    D_80062F24->code = 0x60;
    func_80046848(*pp, 1);
    D_80062F24->x = 0;
    D_80062F24->y = 0;
    D_80062F24->w = 0x180;
    D_80062F24->h = 0xE8;
    D_80062F24->r = D_801E2CF4;
    D_80062F24->g = D_801E2CF4;
    D_80062F24->b = D_801E2CF4;
    p = *pp; *(volatile SvPrim **)pp = p + 1; func_80046794(D_80062FC4, (s32)p);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x5F, (s32)rect);
    D_801E2CF4 += arg0;
    if (D_801E2CF4 < 0) {
        D_801E2CF4 = 0;
    }
    if (D_801E2CF4 >= 0x100) {
        D_801E2CF4 = 0xFF;
    }
    return D_801E2CF4;
}

void func_801D2D10(s32 arg0) {
    switch (arg0) {
    case 0:
        D_8009A000 = 0x81;
        D_8009A004 = 0x81;
        D_8009A008 = 0x81;
        break;
    case 1:
        D_8009A000 = 0x80;
        D_8009A004 = 0x80;
        D_8009A008 = 0x80;
        break;
    case 2:
        D_8009A000 = 0x82;
        D_8009A004 = 0x82;
        D_8009A008 = 0x82;
        break;
    }
    func_8002DA7C();
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D2DA8);

void func_801D32C0(void) {
    func_80042A30(D_8009A024);
    func_80042A30(D_8009A028);
    func_80042A30(D_8009A02C);
    func_80042A30(D_8009A030);
}

void func_801D3318(void) {
    func_80042A30(D_8009A034);
    func_80042A30(D_8009A038);
    func_80042A30(D_8009A03C);
    func_80042A30(D_8009A040);
}

s32 func_801D3370(void) {
    s32 *p;
    s32 ret;

    p = &D_8009A024;
    while (1) {
        if (func_80042A30(p[0]) == 1) {
            ret = 0;
            break;
        }
        if (func_80042A30(p[1]) == 1) {
            ret = 1;
            break;
        }
        if (func_80042A30(p[2]) == 1) {
            ret = 2;
            break;
        }
        if (func_80042A30(p[3]) == 1) {
            ret = 3;
            break;
        }
    }
    return ret;
}

s32 func_801D33F4(void) {
    s32 *p;
    s32 ret;

    p = &D_8009A034;
    while (1) {
        if (func_80042A30(p[0]) == 1) {
            ret = 0;
            break;
        }
        if (func_80042A30(p[1]) == 1) {
            ret = 1;
            break;
        }
        if (func_80042A30(p[2]) == 1) {
            ret = 2;
            break;
        }
        if (func_80042A30(p[3]) == 1) {
            ret = 3;
            break;
        }
    }
    return ret;
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D3478);

void func_801D3668(s32 arg0) {
    if (!(arg0 & 0x3F)) {
        func_801D3478(0);
        func_801D3478(1);
    }
}

s32 func_801D3698(s32 arg0, s32 arg1) {
    s32 var_a0;
    s32 var_s0;
    s32 var_v1;

    var_s0 = 0;
loop_1:
    var_a0 = arg1;
    if (arg0 != 0) {
        var_a0 |= 0x10;
    }
    if (func_801D1D40(var_a0) == 0) {
        var_v1 = 0;
    } else {
        var_s0 += 1;
        var_v1 = 1;
        if (var_s0 < 0x14) {
            goto loop_1;
        }
    }
    return var_v1;
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D370C);

void func_801D39C4(void) {
    D_801E3698 = 0;
    D_801E2CF8 = 7;
    func_8001DEF0(&D_801E368C);
    func_80025D14(&D_801D4EDC, 0x380, 0, 0, 0x1E0);
    func_80043DD8(0);
    func_80026448(&D_801E3DFE, 0, 1, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0U);
    func_80025CD4((s32) &D_801E3F2C);
    func_80025B8C((s32) &D_801E8F44);
    func_80025C14((s32) &D_801E4538);
    func_80025DF8();
    func_801D19C4();
}

INCLUDE_RODATA("../asm/us/savemenu/nonmatchings/text", D_801D018C);

INCLUDE_RODATA("../asm/us/savemenu/nonmatchings/text", D_801D0194);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D3AB0);

void func_801D4C38(void) {
    func_80025ED4();
    func_80025CD4((s32)D_800756F8);
    func_80025C94(&D_801E3F2C);
    func_80025BD0(&D_801E8F44);
    func_80025C54(&D_801E4538);
    func_801D1BA4();
    func_800444AC(D_801E3EEC);
    func_800443B0(D_801E3E34);
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D4CC0);
