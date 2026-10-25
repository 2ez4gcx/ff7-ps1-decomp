#include "common.h"
#include "main/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
extern volatile s32 D_80062FC4;
extern u8 *volatile D_80062F24;
void func_8001D3C0(s16 arg0, s16 arg1);
M2C_UNK func_801D4CC0();
M2C_UNK func_801D1774();
M2C_UNK func_801D2D74();
M2C_UNK func_801D2E84();
M2C_UNK func_801D3228();
M2C_UNK func_801D027C();
M2C_UNK func_801D1A6C(s32);
M2C_UNK func_801D4118(s32);
M2C_UNK func_801D2F00(s32);
M2C_UNK func_801D3138(s32);
M2C_UNK func_801D3018(s32);
M2C_UNK func_801D05C4(s32);
M2C_UNK func_801D0704(s32);
M2C_UNK func_801D131C(s32);
M2C_UNK func_801D11A8();
extern Main2C D_800738A4[];
void func_800262D8(void);
M2C_UNK func_800258BC(s32, M2C_UNK);
void func_8001EB2C(s16 arg0, s16 arg1);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001BDB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001C0EC);

void func_8001C3C4(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001C3CC);

void func_8001C434(void) {
    if (D_80062D70 == 0) {
        D_80062D70 = 1;
        func_80042A70();
        func_80042A60(D_800696AB + 1, 4, D_800696AB + 0x23, 4);
    }
    D_80062FA0 = 0;
}

void func_8001C484(s32 arg0) {
    D_80062E9C = arg0;
    D_80062E94 = 0x14;
}

u16 func_8001C498(void) {
    u16 r;

    if (D_800696AC != 0xFF && D_800696AD == 0x41) {
        r = ~(D_800696AF | (D_800696AE << 8));
    } else {
        r = 0;
    }
    return r;
}

u8 *func_8001C4E8(u8 *arg0) {
    s32 i;
    s32 c;

    D_80062D71 = 1;
    func_8001F6E4(1, D_80062D72, D_80062D74);
    func_8001F6C0((s32) arg0, 7);
    for (i = 0; i < 0x100; i++) {
        c = *arg0;
        if (c < 0xFF) {
            if (c >= 0xFA) {
                arg0 += 2;
                goto next;
            }
        }
        arg0 += 1;
    next:
        if (*arg0 == 0xFF) {
            arg0 += 1;
            break;
        }
    }
    return arg0;
}

void func_8001C58C(void) {
    if (!(func_8001F6B4() & 0xFF)) {
        D_80062D71 = 0;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001C5BC);

u16 func_8001C788(void) {
    u16 r;

    r = 0;
    if (D_80062E94 != 0) {
        D_80062E94 -= 1;
    } else if (func_80023050() == 0 || func_80023050() == 1) {
        if (func_80034B44() == 0) {
            r = func_8001C5BC();
        }
    }
    return r;
}

s32 func_8001C808(void) {
    u16 a;
    u16 b;

    if (D_80062FA0 == 0) {
        if (D_800696AC != 0xFF && D_800696AD == 0x41) {
            a = ~(D_800696AF | (D_800696AE << 8));
        } else {
            a = 0;
        }
    } else {
        a = func_8001C788();
    }
    if (D_800696CE != 0xFF && D_800696CF == 0x41) {
        b = ~(D_800696D1 | (D_800696D0 << 8));
    } else {
        b = 0;
    }
    return a | (b << 16);
}

s32 func_8001C8D4(void) {
    s32 pad;
    s32 hi;
    s32 out;
    s32 i;
    s32 bit;

    pad = func_8001C808();
    hi = pad & 0xFFFF0000;
    if (((D_8009D7BC.unk2 >> 2) & 3) && D_80062FA0 == 0) {
        out = 0;
        i = 0;
        while (1) {
            bit = 1 << i;
            if (pad & bit) {
                out |= 1 << D_8009D7BC.unk4[i];
            }
            i++;
            if (i >= 16) {
                goto end;
            }
        }
    }
    out = pad & 0xFFFF;
end:
    return out | hi;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001C980);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001CB48);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001CDA4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001CF3C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001D180);

void func_8001D3C0(s16 arg0, s16 arg1) {
    func_80046974(D_80062F24);
    *(s16 *)(D_80062F24 + 8) = arg0;
    *(s16 *)(D_80062F24 + 10) = arg1;
    D_80062F24[4] = 0xFF;
    D_80062F24[5] = 0xFF;
    D_80062F24[6] = 0;
    func_80046794(D_80062FC4, (s32)D_80062F24);
    D_80062F24 += 12;
}

void func_8001D47C(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    func_800469C4(D_80062F24);
    ((volatile PrimL *) D_80062F24)->r = arg3 >> 16;
    ((volatile PrimL *) D_80062F24)->g = arg3 >> 8;
    ((volatile PrimL *) D_80062F24)->b = arg3;
    ((volatile PrimL *) D_80062F24)->x0 = arg0;
    ((volatile PrimL *) D_80062F24)->y0 = arg2;
    ((volatile PrimL *) D_80062F24)->x1 = arg1;
    ((volatile PrimL *) D_80062F24)->y1 = arg2;
    func_80046794(*(s32 *) &D_80062FC4, (s32) D_80062F24);
    D_80062F24 += 16;
}

void func_8001D56C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    s32 t;
    u8 *p;

    if (arg4 != 0) {
        func_800469C4(D_80062F24);
        D_80062F24[4] = 0xFF;
        D_80062F24[5] = 0xFF;
        D_80062F24[6] = 0;
    } else {
        func_800469C4(D_80062F24);
        D_80062F24[4] = 0x80;
        D_80062F24[5] = 0x80;
        D_80062F24[6] = 0x80;
    }
    p = D_80062F24;
    t = D_80062FC4;
    *(s16 *)(p + 8) = arg0;
    *(s16 *)(D_80062F24 + 10) = arg1;
    *(s16 *)(D_80062F24 + 12) = arg2;
    *(s16 *)(D_80062F24 + 14) = arg3;
    func_80046794(t, (s32)D_80062F24);
    D_80062F24 += 16;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001D6A8);

void func_8001DE0C(void *arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    M2C_FIELD(arg0, s16 *, 0) = arg1;
    M2C_FIELD(arg0, s16 *, 2) = arg2;
    M2C_FIELD(arg0, s16 *, 4) = arg3;
    M2C_FIELD(arg0, s16 *, 6) = (s16) arg4;
}

void func_8001DE24(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, u16 *, 0) = (u16) (M2C_FIELD(arg0, u16 *, 0) + arg1);
    M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + arg2);
}

void func_8001DE40(void *arg0, void *arg1) {
    M2C_FIELD(arg0, u16 *, 0) = (u16) M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg1, u16 *, 2);
    M2C_FIELD(arg0, u16 *, 4) = (u16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg1, u16 *, 6);
}

void func_8001DE70(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        D_800696F0[i] = D_80049208[i];
    }
}

void func_8001DEB0(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        D_80049208[i] = D_800696F0[i];
    }
}

void func_8001DEF0(u8 *arg0) {
    s32 i;

    for (i = 0; i < 12; i++) {
        D_80049208[i] = *arg0++;
    }
}

void func_8001DF24(u16 *arg0, s32 arg1, s8 arg2, s8 arg3) {
    u8 *p;
    s32 t;

    D_80062F24[3] = 3;
    D_80062F24[7] = 0x60;
    func_80046870(*(u8 **)&D_80062F24, 1);
    *(u16 *)(D_80062F24 + 8) = arg0[0];
    *(u16 *)(D_80062F24 + 10) = arg0[1];
    *(u16 *)(D_80062F24 + 12) = arg0[2];
    *(u16 *)(D_80062F24 + 14) = arg0[3];
    D_80062F24[4] = arg1;
    D_80062F24[5] = arg2;
    D_80062F24[6] = arg3;
    p = D_80062F24;
    t = D_80062FC4;
    D_80062F24 = p + 0x10;
    func_80046794(t, (s32)p);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001E040);

void func_8001EB2C(s16 arg0, s16 arg1) {
    Rect16 r;
    u8 *p;
    s32 t;

    D_80062F24[3] = 4;
    D_80062F24[7] = 0x64;
    func_80046848(D_80062F24, 1);
    func_80046870(D_80062F24, 1);
    *(s16 *)(D_80062F24 + 8) = arg0;
    *(s16 *)(D_80062F24 + 10) = arg1;
    D_80062F24[12] = 0xE0;
    D_80062F24[13] = 8;
    *(s16 *)(D_80062F24 + 16) = 0x18;
    *(s16 *)(D_80062F24 + 18) = 0x10;
    *(s16 *)(D_80062F24 + 14) = func_80046634(0x100, 0x1E1);
    p = D_80062F24;
    t = D_80062FC4;
    D_80062F24 = p + 0x14;
    func_80046794(t, (s32)p);
    r.x = 0;
    r.y = 0;
    r.w = 0xFF;
    r.h = 0xFF;
    func_80026A34(0, 1, func_8004656C(0, 2, 0x3C0, 0x100) & 0xFFFF, (s32)&r);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001EC70);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001EF84);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001F1BC);

void func_8001F6AC(void) {
}

u8 func_8001F6B4(void) {
    return D_80062DDB;
}

void func_8001F6C0(s32 arg0, s8 arg1) {
    D_80062DDB = 1;
    D_80062DDC = arg1;
    D_80062DE0 = 0x28;
    D_80062EB8 = arg0;
    D_80062DE5 = 1;
}

void func_8001F6E4(s32 arg0, s16 arg1, s16 arg2) {
    D_80062DE4 = (s8) arg0;
    if ((arg0 << 0x10) != 0) {
        D_80062DE6 = arg1;
        D_80062DE8 = arg2;
        return;
    }
    D_80062DDB = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001F710);

s32 func_8001FA28(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    return func_8002DA7C(temp_a0);
}

void func_8001FA68(s32 arg0) {
    s32 temp_a0;

    D_8009A000 = 0x28;
    temp_a0 = arg0 & 0xFFFF;
    D_8009A004 = 0x40;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_8001FAAC(s32 arg0) {
    s32 temp_a0;

    D_8009A000 = 0x29;
    temp_a0 = arg0 & 0xFFFF;
    D_8009A004 = 0x40;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_8001FAF0(void) {
}

u16 func_8001FAF8(s32 arg0) {
    if (arg0 < 0x80) {
        return D_800722D6[arg0].v;
    }
    if (arg0 < 0x100) {
        return D_800738CA[arg0 - 0x80].v;
    }
    if (arg0 < 0x120) {
        return D_80071E64[arg0 - 0x100].v;
    }
    return D_80071C32[arg0 - 0x120].v;
}

s32 func_8001FBAC(s32 arg0, s32 arg1, s32 arg2) {
    s32 idx;

    idx = D_800491D0[D_8009CBDC[arg0]];
    switch (arg1) {
    case 0:
        arg2 = D_800738A4[D_8009C754[D_800491D0[idx]][0]].v;
        break;
    case 1:
        arg2 = D_80071E46[D_8009C755[D_800491D0[idx]][0]].v;
        break;
    case 2:
        arg2 = 0;
        break;
    case 3:
        arg2 = 0;
        break;
    }
    return arg2;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001FCDC);

void func_8001FE6C(s32 arg0, s32 arg1, u16 arg2) {
    switch (arg1) {
    case 0:
        D_8009D88C[arg0].b |= arg2;
        break;
    case 1:
        D_8009D88C[arg0].a |= arg2;
        break;
    case 2:
        D_8009D88A[arg0].a |= arg2;
        break;
    }
}

void func_8001FF50(s32 arg0, s32 arg1) {
    D_8009D888[arg0].flags |= arg1;
}

void func_8001FF8C(s32 arg0, s32 arg1) {
    if (arg1 < 0x41) {
        D_8009D890[arg0][0] |= 1 << arg1;
    }
}

void func_8001FFD4(s32 arg0, s32 arg1) {
    s32 off;

    if (arg1 < 0x41) {
        off = arg0 * 0x440;
        *(u32 *) (D_8009D894 + off) |= 1 << arg1;
    }
}

void func_8002001C(s32 arg0, u32 arg1) {
    s32 off;

    off = arg0 * 0x440;
    *(u32 *) (D_8009D894 + off) |= arg1;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80020058);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800206E4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80020B68);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80021044);

void func_800211B8(s32 arg0) {
    D_80062DEC = arg0;
}

s32 func_800211C4(s32 arg0) {
    func_80033E34(D_80048F60[arg0 * 2], D_80048F60[arg0 * 2 + 1], D_80062DEC, 0);
    return func_80034B44();
}

void func_8002120C(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80062DD4;
    D_80062DD4 = arg0;
    D_80062DD0 = temp_v0;
    if ((arg0 != 0) && (((u32) (temp_v0 - 3) >= 2U) || ((u32) (arg0 - 3) >= 2U))) {
        func_800211C4(arg0);
    }
}

void func_80021258(s32 arg0) {
    func_80015248(0xD, arg0, 8);
}

void func_80021280(s32 arg0) {
    func_80015248(4, arg0, 8);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800212A8);

void func_80021BAC(s32 arg0, s32 arg1) {
    struct { s16 x, y, w, h; } rect;
    u8 buf[8];

    rect.x = 0;
    rect.y = 0;
    rect.w = 0x100;
    rect.h = 0x100;
    func_80026A34(0, 1, 0x7F, (s32) &rect);
    func_80026F44(arg0 + 8, arg1 + 6, D_80049338, 6);
    ((void (*)()) func_8001DE0C)(buf, arg0, arg1, 0x50, 0x14);
    func_8001E040(buf);
}

void func_80021C4C(s32 arg0, s32 arg1, s32 arg2) {
    struct { s16 x, y, w, h; } rect;
    s32 buf[2];
    s32 s;

    func_80028CA0((s16) (arg0 + 8), (s16) (s = arg1 + 5), 0x80, 0x20, 0x10, 0x10, (s16) ((s32 (*)(s32)) func_8002603C)(arg2), 0);
    rect.x = 0;
    rect.y = 0;
    rect.w = 0x100;
    rect.h = 0x100;
    func_80026A34(0, 1, 0x7F, (s32) &rect);
    func_80026F44(arg0 + 0x18, s, (void *) ((s32 (*)(s32)) func_80021258)(arg2), 7);
    func_80026F44(arg0 + 0x38, arg1 + 0x12, D_80049338, 6);
    ((void (*)()) func_8001DE0C)(buf, arg0, arg1, 0x82, 0x20);
    func_8001E040(buf);
}

void func_80021D5C(s32 arg0, s32 arg1) {
    struct { s16 x, y, w, h; } rect;
    s32 buf[2];
    s32 s;

    func_80028CA0((s16) (arg0 + 8), (s16) (s = arg1 + 5), 0x80, 0x20, 0x10, 0x10, (s16) func_8002603C(D_80062EC0), 0);
    rect.x = 0;
    rect.y = 0;
    rect.w = 0x100;
    rect.h = 0x100;
    func_80026A34(0, 1, 0x7F, (s32) &rect);
    func_80026F44(arg0 + 0x20, arg1 + 0x12, (void *) func_80015248(8, 0x25, 8), 7);
    func_80026F44(arg0 + 0x18, s, (void *) ((s32 (*)(s32)) func_80021258)(D_80062EC0), 7);
    ((void (*)()) func_8001DE0C)(buf, arg0, arg1, 0x82, 0x23);
    func_8001E040(buf);
}

void func_80021E70(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 pad[2];
    s32 buf[2];
    s32 *p;

    func_80026F44(arg0 + 0x2F, arg1 + 0x12, (void *)func_80015248(8, 0x24, 8), 7);
    func_80026F44(arg0 + 8, arg1 + 5, (void *)func_80015248(3, func_80015AFC(D_800491D0[D_8009CBDC[arg2]], arg3), 8), 6);
    p = buf;
    ((void (*)()) func_8001DE0C)(p, arg0, arg1, 0x82, 0x23);
    func_8001E040(p);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80021F58);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80022B5C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80022DE4);

void func_80022FE0(void) {
    func_800159B0();
    func_800444AC(D_8007075C[D_80062F58]);
    func_800443B0(D_800706A4[D_80062F58]);
}

s32 func_80023050(void) {
    return D_80062DF8;
}

void func_8002305C(s32 arg0, s32 arg1) {
    s32 t;

    t = D_80062F94;
    D_80062DF8 = arg0;
    D_80062F94 = arg1 - 1;
    D_80062F0C = t;
    switch (arg0) {
    case 1: break;
    case 2:
        D_80062F20 = 0x10;
        break;

    case 4:
        D_80062F20 = 0x10;
        break;
    case 5:
        D_8009A0D3 = t;
        D_80062ECC = 0;
        D_80062F20 = 0x10;
        break;

    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800230C4);

void func_8002368C(void) {
    D_80062F64 = 0;
    func_80026448(D_8009A0C8, 0, 0, 1, 0xA, 0, 0, 1, 0xA, 0, 0, 0, 1, 0);
    func_80026448(D_8009A0C8 + 0x12, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0);
    func_80026448(D_8009A0C8 + 0x24, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0);
}

s32 func_80023788(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0;
    if (var_a0 > 0x57E3F) {
        var_a0 = 0x57E3F;
    }
    return ((var_a0 / (s32) D_80049474) * 0xA) + ((s32) (var_a0 % (s32) D_80049474) / (s32) D_80049478);
}

s32 func_8002382C(s32 arg0) {
    if (arg0 > 0x57E3F) {
        arg0 = 0x57E3F;
    }
    arg0 = arg0 % D_80049474;
    arg0 = arg0 % D_80049478;
    return (arg0 / D_8004947C) * 10 + arg0 % D_8004947C / D_80049480;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80023940);

void func_80023AC4(void) {
    D_80062FC0 = 2;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80023AD4);

void func_80024A04(void) {
    func_800444AC(&D_8007075C);
    func_800443B0(&D_80070700);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80024A3C);

void func_80024D88(s32 arg0) {
    func_800211C4(0xD);
    do {

    } while (func_80034B44() != 0);
    func_8003CEDC(0x1E);
    func_801D131C(arg0);
}

void func_80024DD4(s32 arg0) {
    func_800211C4(0xE);
    do {

    } while (func_80034B44() != 0);
    func_801D1A6C(arg0);
}

void func_80024E18(s32 arg0) {
    func_800211C4(0xF);
    do {

    } while (func_80034B44() != 0);
    func_801D4118(arg0);
}

void func_80024E5C(void) {
    func_800211C4(0x10);
    do {

    } while (func_80034B44() != 0);
    func_801D4CC0();
}

void func_80024E94(void) {
    func_800211C4(0xA);
    do {

    } while (func_80034B44() != 0);
    func_801D1774();
}

void func_80024ECC(void) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D2D74();
}

void func_80024F04(void) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D2E84();
}

void func_80024F3C(s32 arg0) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D2F00(arg0);
}

void func_80024F80(s32 arg0) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D3138(arg0);
}

void func_80024FC4(s32 arg0) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D3018(arg0);
}

void func_80025008(void) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D3228();
}

void func_80025040(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if ((D_8009D78A[0] >> D_80049500[i]) & 1) {
            D_8009D44C[i] = D_8009C738[D_80049500[i]][1];
        }
    }
}

void func_800250B4(void) {
    func_800211C4(0xC);
    do {

    } while (func_80034B44() != 0);
    func_801D027C();
}

void func_800250EC(s32 arg0) {
    func_800211C4(0xC);
    do {

    } while (func_80034B44() != 0);
    func_801D05C4(arg0);
}

void func_80025130(s32 arg0) {
    func_800211C4(0xC);
    do {

    } while (func_80034B44() != 0);
    func_801D0704(arg0);
}

void func_80025174(void) {
    s32 pad;
    s32 i;
    s32 j;
    s32 k;

    pad = func_8001C808();
    if (pad & 4) {
        func_80024E18(0);
    } else if (pad & 8) {
        func_80024E5C();
        for (i = 0; i < 5; i++) {
            k = 0x13F - i * 6;
            for (j = 0; j < 6; j++) {
                D_8009CBE0[k - j] = (j + 0x47) | 0xC600;
            }
        }
        func_80024E94();
    } else if (pad & 1) {
        func_80024DD4(0);
    } else if (pad & 2) {
        for (i = 0; i < 9; i++) {
            func_80024D88(i);
        }
        func_80024D88(0x64);
    } else {
        D_8009D2A4 = 0xFF;
        D_8009D2A5 = 0xFF;
        func_80024A3C(0);
    }
}

u16 func_80025288(u16 item) {
    s32 id;
    s32 count;
    s32 i;
    s32 n;
    u16 v;
    u16 res;

    id = item & 0x1FF;
    res = 0xFFFF;
    count = item >> 9;
    for (i = 0; i < 320; i++) {
        v = D_8009CBE0[i];
        if (v != 0xFFFF && id == (v & 0x1FF)) {
            res = v >> 9;
            n = res;
            if (count < n) {
                res = item | (count << 9);
                D_8009CBE0[i] = ((n - count) << 9) | id;
            } else {
                res = v;
                D_8009CBE0[i] = 0xFFFF;
            }
            break;
        }
    }
    return res;
}

s32 func_80025310(s32 arg0) {
    s32 id;
    s32 i;
    u16 v;
    u16 none;

    id = arg0 & 0x1FF;
    none = 0xFFFF;
    for (i = 0; i < 320; i++) {
        v = D_8009CBE0[i];
        if (v != 0xFFFF && id == (v & 0x1FF)) {
            return v;
        }
    }
    return none;
}

void func_80025360(void) {
    func_8001FA28(0x19F);
}

void func_80025380(u16 item) {
    s32 id;
    s32 count;
    s32 i;
    u16 v;

    id = item & 0x1FF;
    count = item >> 9;
    for (i = 0; i < 320; i++) {
        v = D_8009CBE0[i];
        if (v != 0xFFFF && id == (v & 0x1FF)) {
            count += v >> 9;
            if (count > 99) {
                count = 99;
            }
            D_8009CBE0[i] = (count << 9) | id;
            return;
        }
    }
    for (i = 0; i < 320; i++) {
        if (D_8009CBE0[i] == 0xFFFF) {
            D_8009CBE0[i] = item;
            return;
        }
    }
}

s32 func_8002542C(s32 arg0) {
    s32 i;
    u8 id;

    id = arg0;
    for (i = 0; i < 200; i++) {
        if (D_8009CE60[i] == -1) {
            D_8009CE60[i] = arg0;
            if (func_8002603C(id) == 0xA) {
                *((u8 *) D_8009CE60 + 0x473) |= 1;
            }
            if (id == 0x2C) {
                *((u8 *) D_8009CE60 + 0x473) |= 2;
            }
            return -1;
        }
    }
    return arg0;
}

void func_800254D8(void) {
    D_80062EBC = 0;
}

void func_800254E4(u8 arg0) {
    D_80069800[D_80062EBC] = arg0;
    D_80062EBC = D_80062EBC + 1;
}

void func_80025514(s32 arg0) {
    s32 i;
    s32 x;
    s32 best;
    u8 id;
    u8 pri;
    u8 bestpri;

    id = arg0 & 0xFF;
    for (i = 0; i < 0xC8; i++) {
        if (D_8009CE60[i] == -1) {
            D_8009CE60[i] = arg0;
            if (func_8002603C(id) == 0xA) {
                ((u8 *)D_8009CE60)[0x473] |= 1;
            }
            if (id == 0x2C) {
                ((u8 *)D_8009CE60)[0x473] |= 2;
            }
            func_800254E4(id);
            return;
        }
    }
    best = -1;
    bestpri = 0xFF;
    for (i = 0; i < 0xC8; i++) {
        x = D_8009CE60[i];
        pri = D_800494A4[x & 0xFF];
        if (pri < bestpri) {
            bestpri = pri;
            best = x;
        }
    }
    for (i = 0; i < 0xC8; i++) {
        if (D_8009CE60[i] == best) {
            D_8009CE60[i] = arg0;
            return;
        }
    }
}

void func_80025648(void) {
}

void func_80025650(void) {
}

u8 func_80025658(void) {
    return D_8009C739;
}

void *func_80025668(s32 arg0) {
    u8 idx;
    void *ret;

    idx = D_8009CBDC[arg0];
    ret = (void *)0xFF;
    if (idx != 0xFF) {
        ret = &D_80071E4D[D_8009C754[D_800491D0[idx]][1] * 0x24];
    }
    return ret;
}

void *func_800256DC(s32 arg0) {
    u8 idx;
    void *ret;

    idx = D_8009CBDC[arg0];
    ret = (void *)0xFF;
    if (idx != 0xFF) {
        ret = D_800738BC[D_8009C754[D_800491D0[idx]][0]];
    }
    return ret;
}

S24 *func_80025758(s32 arg0) {
    return &D_80071E44[arg0];
}

void *func_80025774(s32 arg0) {
    return &D_80071C24[arg0 * 0x10];
}

void *func_80025788(s32 arg0) {
    u8 idx;
    void *ret;

    idx = D_8009CBDC[arg0];
    if (idx == 0xFF) {
        ret = (void *)0xFF;
    } else {
        ret = D_8009D84C[arg0];
    }
    return ret;
}

void func_800257C4(void) {
}

void *func_800257CC(s32 arg0) {
    return D_8009C748[D_800491D0[arg0]];
}

void func_80025800(s32 arg0, s32 arg1) {
    u8 id;
    s32 k;
    s32 hp;

    id = D_8009CBDC[arg0];
    if (id != 0xFF) {
        k = D_800491D0[id];
        hp = D_8009D85C[arg0].hp - arg1;
        if (hp < 0) {
            D_8009D85C[arg0].hp = 0;
        } else {
            D_8009D85C[arg0].hp = hp;
        }
        D_8009C764[k].v = *(u16 *) &D_8009D85C[arg0];
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800258BC);

void func_80025988(s32 arg0, s32 arg1) {
    u8 id;
    s32 v;
    s32 t;

    id = D_8009CBDC[arg0];
    if (id != 0xFF) {
        v = D_800491D0[id];
        t = D_8009D860[arg0].hp - arg1;
        if (t < 0) {
            D_8009D860[arg0].hp = 0;
        } else {
            D_8009D860[arg0].hp = t;
        }
        D_8009C768[v * 33].v = *(u16 *)&D_8009D860[arg0].hp;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025A44);

u32 func_80025B10(u32 arg0) {
    u32 v;

    v = D_8009D260[0];
    if (arg0 > v) {
        D_8009D260[0] = 0;
        return v;
    } else {
        D_8009D260[0] = v - arg0;
        return arg0;
    }
}

void func_80025B48(u32 arg0) {
    u32 t;
    u32 *p = (u32 *)&D_8009C6E4[0xB7C];

    t = *p + arg0;
    if (t < *p) {
        *p = -1;
        return;
    }
    *p = t;
}

s32 func_80025B7C(void) {
    return D_8009D260[0];
}

void func_80025B8C(s32 arg0) {
    Rect16 r;

    r.x = 0x340;
    r.y = 0x184;
    r.w = 0x30;
    r.h = 0x78;
    func_80044064(&r, arg0);
}

void func_80025BD0(void *arg0) {
    Rect16 r;

    r.x = 0x340;
    r.y = 0x184;
    r.w = 0x30;
    r.h = 0x78;
    func_80044000(&r, arg0);
}

void func_80025C14(s32 arg0) {
    Rect16 r;

    r.x = 0x180;
    r.w = 0x100;
    r.y = 0;
    r.h = 9;
    func_80044064(&r, arg0);
}

void func_80025C54(void *arg0) {
    Rect8 r;

    r.x = 0x180;
    r.w = 0x100;
    r.y = 0;
    r.h = 9;
    func_80044000(&r, arg0);
}

void func_80025C94(void *arg0) {
    s16 r[4];

    r[0] = 0x100;
    r[1] = 0x1ED;
    r[2] = 0x100;
    r[3] = 3;
    func_80044000(r, arg0);
}

void func_80025CD4(s32 arg0) {
    Rect16 r;

    r.x = 0x100;
    r.y = 0x1ED;
    r.w = 0x100;
    r.h = 3;
    func_80044064(&r, arg0);
}

void func_80025D14(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Unk80046D0C s;

    func_80046CFC((s32)arg0);
    while (func_80046D0C(&s) != 0) {
        if (s.a_arg != 0) {
            s.a[0] = arg3;
            s.a[1] = arg4;
            func_80044000(s.a, (void *)s.a_arg);
            func_80043DD8(0);
        }
        if (s.b_arg != 0) {
            s.b[0] = arg1;
            s.b[1] = arg2;
            func_80044000(s.b, (void *)s.b_arg);
            func_80043DD8(0);
        }
    }
}

void func_80025DF8(void) {
    u8 pad[8];
    u8 buf[0x1000];
    u8 *p;
    s32 i;

    i = 0;
    p = buf;
    do {
        func_80033F40(D_80048FE8[i * 2], D_80048FE8[i * 2 + 1], (s32)p, 0);
        func_80025D14(p, (i / 5) * 0x18 + 0x340, (i % 5) * 0x30 + 0x100, 0x180, i);
        func_80043DD8(0);
        i++;
    } while (i < 9);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025ED4);

void func_80026034(void) {
}

s32 func_8002603C(u8 arg0) {
    return D_80049520[D_80049528[D_800730DD[arg0].a & 0xF]];
}

void func_80026090(void) {
    do {

    } while (func_80034B44() != 0);
    func_800211C4(7);
    do {

    } while (func_80034B44() != 0);
    func_801D11A8();
    D_80062F90 = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800260DC);

void func_80026258(void) {
    Unk8009D7BC *s;
    s32 i;
    u8 *p;

    D_80062F90 = 0;
    func_8001C434();
    func_80026090();
    func_80025008();
    func_800260DC();
    s = &D_8009D7BC;
    i = 15;
    p = &s->unk4[15];
    s->unk0 = 0x80;
    s->unk1 = 0x80;
    s->unk14 = 0x80;
    s->unk2 = 0x41;
    do {
        *p = i;
        i--;
        p--;
    } while (i >= 0);
}

void func_800262D8(void) {
    s32 i;
    u8 c;

    for (i = 0; i < 3; i++) {
        c = D_8009CBDC[i];
        if (c != 0xFF && (D_8009C756[D_800491D0[c]][0] + 0x120) == 0x13B) {
            func_800258BC(i, 3);
            if (D_8009D85C[i].hp != D_8009D85C[i].maxhp) {
                D_8009D85C[i].hp = D_8009D85C[i].hp & 0xFFFE;
                D_8009C764[D_8009CBDC[i]].v = D_8009C764[D_8009CBDC[i]].v & 0xFFFE;
            }
        }
    }
}

void func_80026408(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_80026448(void *arg0, s8 arg1, s8 arg2, s8 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, u16 arg13) {
    M2C_FIELD(arg0, s8 *, 0xA) = arg1;
    M2C_FIELD(arg0, s8 *, 0xB) = arg2;
    M2C_FIELD(arg0, s8 *, 0xC) = arg3;
    M2C_FIELD(arg0, s8 *, 0xD) = (s8) arg4;
    M2C_FIELD(arg0, s16 *, 0) = (s16) arg5;
    M2C_FIELD(arg0, s16 *, 2) = (s16) arg6;
    M2C_FIELD(arg0, s16 *, 4) = (s16) arg7;
    M2C_FIELD(arg0, s16 *, 6) = (s16) arg8;
    M2C_FIELD(arg0, s8 *, 0xE) = (s8) arg9;
    M2C_FIELD(arg0, s8 *, 0xF) = (s8) arg10;
    M2C_FIELD(arg0, s8 *, 0x10) = (s8) arg11;
    M2C_FIELD(arg0, s8 *, 0x11) = (s8) arg12;
    M2C_FIELD(arg0, u16 *, 8) = arg13;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800264A8);

void func_800269C0(s32 arg0) {
    D_80062F24 = arg0;
}

void func_800269D0(void) {
    D_80063008 = D_80062F24;
}

void func_800269E8(void) {
    D_80062F24 = D_80063008;
}
