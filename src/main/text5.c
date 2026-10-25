#include "common.h"
#include "main/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
extern s32 D_80062FC4;
extern s32 D_80062F24;
s32 func_8002988C(s32 arg0, s32 arg1);
extern u16 D_80089580[];
extern u8 D_8004A60C[];
extern u8 D_8007E778[];
s32 func_80036FFC();
s32 func_800373AC();
s32 func_80038FB8();
s32 func_800297A4();
s32 func_800294BC();
s32 func_80042BC0();
s32 func_80042C98();
extern void func_80030234();
s32 func_80026B70(u8 *arg0);
M2C_UNK func_80027B84(Rect16 *);
M2C_UNK func_80028030(Rect16 *, s32);

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

s32 func_80026B70(u8 *arg0) {
    s32 pad[1];
    s32 n;
    s32 total;
    s32 base;
    u8 c;
    u8 t;

    total = 0;
    for (n = 0; n < (u8) D_80062DFC; n++) {
        if (arg0 == NULL) {
            return total;
        }
        c = *arg0;
        if (c == 0xFF) {
            break;
        }
        switch (c) {
        case 0xFA:
            arg0++;
            base = 0xE7;
            break;
        case 0xFB:
            arg0++;
            base = 0x1B9;
            break;
        case 0xFC:
            arg0++;
            base = 0x2A0;
            break;
        case 0xFD:
            arg0++;
            base = 0x372;
            break;
        case 0xFE:
            arg0++;
            base = 0x444;
            break;

        default:
            base = 0;
            break;
        }
        t = D_800707C0[*arg0++ + base];
        total += t >> 5;
        total += t & 0x1F;
    }
    return total;
}

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

void func_80028484(MainBox *arg0) {
    Rect16 r;
    s16 h;
    s32 t;
    s32 u;

    h = arg0->h;
    t = h * arg0->f4 / arg0->f2;
    u = h * arg0->f0 / arg0->f2;
    r.x = arg0->x;
    r.y = arg0->y + t;
    r.w = arg0->w - 1;
    r.h = u + 1;
    func_80028030(&r, t);
    r.x = arg0->x;
    r.y = arg0->y;
    r.w = arg0->w;
    r.h = arg0->h;
    func_80027B84(&r);
    func_80026A34(0, 1, 0x1F, 0);
}

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

void func_80029818(u32 *arg0, u32 *arg1) {
    u32 *d;
    s32 n;

    func_80038F64(*arg0++);
    n = *(volatile u32 *)arg0;
    func_80029424((s32)(arg0 + 3), n);
    d = D_80076C68;
    n = 0x4B0;
    do {
        n--;
        *d++ = *arg1++;
    } while (n != 0);
    func_800294A4();
}

s32 func_8002988C(s32 arg0, s32 arg1) {
    s32 r;

    D_80062F74 = D_80089580;
    D_80062F84 = (u8 *) D_80089580 + 0x1000;
    func_80036FFC(4, D_8007E778);
    func_800373AC(0x77000, 0x2000);
    func_80038FB8(0);
    func_800297A4(arg0, arg1);
    func_80038F64(0x76FE0);
    func_80029424(D_8004A60C, 0x20);
    func_800294A4();
    func_800294BC();
    do {
        D_80062E00 = func_80042A00(0xF2000002, 2, 0x1000, func_80030234);
    } while (D_80062E00 == -1);
    while (func_80042A40(D_80062E00) == 0) {
    }
    while (func_80042BC0(0xF2000002, 0x43D1, 0x1000) == 0) {
    }
    do {
        r = func_80042C98(0xF2000002);
    } while (r == 0);
    return r;
}

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
