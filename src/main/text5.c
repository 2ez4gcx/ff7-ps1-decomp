#include "common.h"
#include "main/decls.h"

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

void func_80026A94(s16 *arg0, u16 *arg1) {
    Spr s;

    func_80043814(&s, arg0[4], arg0[5], arg0[2], arg0[3]);
    s.f = 1;
    s.g = 0;
    s.x += arg1[0];
    s.y += arg1[1];
    s.w = arg1[2];
    s.h = arg1[3];
    s.e = 0x3F;
    func_80044AC0(D_80062F24, &s);
    func_80046794(D_80062FC4, D_80062F24);
    D_80062F24 += 0x40;
}

void func_80026B5C(void) {
}

void func_80026B64(s8 arg0) {
    D_80062DFC = arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80026B70);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80026C5C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80026F44);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_8002708C);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80027408);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80027990);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80027B84);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80028030);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80028484);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_800285AC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80028930);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80028CA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80028E00);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80029114);

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

void func_800294A4(void) {
    while (D_80062E08) {
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_800294BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_800297A4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_80029818);

INCLUDE_ASM("../asm/us/main/nonmatchings/text5", func_8002988C);

void func_80029998(u32 *src) {
    u32 *dst;
    u16 n;

    dst = (u32 *) D_80062F74;
    n = 0x3200;
    do {
        n += 0xFFFF;
        *dst++ = *src++;
    } while (n != 0);
}

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
