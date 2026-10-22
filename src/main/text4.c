#include "common.h"
#include "main/decls.h"

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001BDB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001C0EC);

void func_8001C3C4(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001C3CC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001C434);

void func_8001C484(s32 arg0) {
    D_80062E9C = arg0;
    D_80062E94 = 0x14;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001C498);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001C808);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001D3C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001D47C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001D56C);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001DE70);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001DEB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001DEF0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001DF24);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001E040);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001EB2C);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001F6E4);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001FBAC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001FCDC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001FE6C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001FF50);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001FF8C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001FFD4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8002001C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80020058);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800206E4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80020B68);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80021044);

void func_800211B8(s32 arg0) {
    D_80062DEC = arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800211C4);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80021C4C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80021D5C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80021E70);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80021F58);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80022B5C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80022DE4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80022FE0);

s32 func_80023050(void) {
    return D_80062DF8;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8002305C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800230C4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8002368C);

s32 func_80023788(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0;
    if (var_a0 > 0x57E3F) {
        var_a0 = 0x57E3F;
    }
    return ((var_a0 / (s32) D_80049474) * 0xA) + ((s32) (var_a0 % (s32) D_80049474) / (s32) D_80049478);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8002382C);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025040);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025174);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025288);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025310);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8002542C);

void func_800254D8(void) {
    D_80062EBC = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800254E4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025514);

void func_80025648(void) {
}

void func_80025650(void) {
}

u8 func_80025658(void) {
    return D_8009C739;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025668);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025758);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025774);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025788);

void func_800257C4(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800257CC);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025B10);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025B48);

s32 func_80025B7C(void) {
    return D_8009D260;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025B8C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025BD0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025C14);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025C54);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025C94);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025CD4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025D14);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025DF8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80025ED4);

void func_80026034(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8002603C);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800262D8);

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

void func_80026A00(s32 arg0) {
    D_80062FC4 = arg0;
}

void func_80026A0C(void) {
    D_8006300C = D_80062FC4;
}

void func_80026A20(void) {
    D_80062FC4 = D_8006300C;
}

void func_80026A34(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a1;

    func_80044A68((void *) D_80062F24, arg0, arg1, arg2, arg3);
    temp_a1 = D_80062F24;
    D_80062F24 = temp_a1 + 0xC;
    func_80046794(D_80062FC4, temp_a1);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80026A94);

void func_80026B5C(void) {
}

void func_80026B64(s8 arg0) {
    D_80062DFC = arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80026B70);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80026C5C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80026F44);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8002708C);

void func_80027354(s16 x, s16 y, u8 *str, u8 color) {
    s16 i;

    if (str != NULL) {
        for (i = 0; i < (u8) D_80062DFC; i++) {
            if (*str == 0xFF) {
                break;
            }
            func_8002708C(x, y, *str++, color);
            x += 8;
        }
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80027408);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80027990);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80027B84);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80028030);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80028484);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800285AC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80028930);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80028CA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80028E00);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80029114);

void func_800293D0(void) {
    func_80038FEC(0);
    D_80062E08 = 0;
}

void func_800293F4(void) {
    D_80062E08 = 1;
    func_80038FEC((s32) &func_800293D0);
}

void func_80029424(s32 arg0, M2C_UNK arg1) {
    func_800293F4();
    func_80038F04(arg0, arg1);
}

void func_80029464(s32 arg0, M2C_UNK arg1) {
    func_800293F4();
    func_80037BE0(arg0, arg1);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800294A4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800294BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_800297A4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80029818);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8002988C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_80029998);

void func_800299C8(void) {
    do {

    } while (func_80042CCC(0xF2000002) == 0);
    func_80042AE0(0xF2000002, 2);
    do {

    } while (func_80042A50(D_80062E00) == 0);
    do {

    } while (func_80042A10(D_80062E00) == 0);
    func_80038FEC(0);
    func_80038A84(0);
    func_80038C04(0);
    func_80038C6C(0, 0xFFFFFF);
}
