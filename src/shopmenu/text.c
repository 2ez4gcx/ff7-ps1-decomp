#include "common.h"
#include "shopmenu/decls.h"

void func_801D0084(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_801D00C4(s16 arg0, s16 arg1, s32 arg2) {
    u32 t;
    s32 u;
    s32 v;

    if (arg2 < 0x80) {
        t = 0;
    } else if (arg2 < 0x100) {
        arg2 -= 0x80;
        if (arg2 < 0x10) {
            t = 1;
        } else if (arg2 < 0x20) {
            t = 3;
        } else if (arg2 < 0x30) {
            t = 2;
        } else if (arg2 < 0x3E) {
            t = 5;
        } else if (arg2 < 0x49) {
            t = 4;
        } else if (arg2 < 0x57) {
            t = 9;
        } else if (arg2 < 0x65) {
            t = 6;
        } else if (arg2 < 0x72) {
            t = 7;
        } else {
            t = 8;
        }
    } else if (arg2 < 0x120) {
        t = 0xA;
    } else {
        t = 0xB;
    }
    u = (t & 1) * 0x10 | 0x60;
    v = (t >> 1) * 0x10 + 0x70;
    func_80028CA0(arg0, arg1, u, v, 0x10, 0x10, 1, 0);
}

u32 func_801D01B8(u32 arg0) {
    return arg0 >> 0x1F;
}

s32 func_801D01C0(s32 arg0) {
    s32 var_v0;

    var_v0 = arg0;
    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }
    return var_v0;
}

void func_801D01D8(void) {
    s32 i;
    s32 n;
    s32 color;

    n = 0;
    for (i = 0; i < 8; i++) {
        if (D_801D70DC->v[i] != 0) {
            if (func_801D01B8(D_801D70DC->v[i]) != 0) {
                ((void (*)(s32, s32, s32, s32))func_8002708C)(0xB4, n * 0xB + 0x9A, 0xE1, 7);
                color = 2;
            } else {
                ((void (*)(s32, s32, s32, s32))func_8002708C)(0xB4, n * 0xB + 0x9A, 0xB3, 7);
                color = 6;
            }
            func_80029114(0xBC, n * 0xB + 0x9A, func_801D01C0(D_801D70DC->v[i]), 2, color);
            func_80026A34(0, 1, 0x1F, 0);
            func_80026F44(0x78, n * 0xB + 0x98, D_801D63D0[i], 7);
            if (i >= 6) {
                ((void (*)(s32, s32, s32, s32))func_8002708C)(0xCA, n * 0xB + 0x9A, 0xD3, 7);
            }
            n++;
        }
    }
    func_80026A34(0, 1, 0x1F, 0);
}

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D0340);

s32 func_801D0C88(s32 arg0) {
    s16 rect[4];
    volatile ShopPrim *p;
    volatile ShopPrim *volatile *pp;

    pp = &D_80062F24;
    D_80062F24->len = 3;
    D_80062F24->code = 0x60;
    func_80046848(*pp, 1);
    D_80062F24->x = 0;
    D_80062F24->y = 0;
    D_80062F24->w = 0x180;
    D_80062F24->h = 0xE8;
    D_80062F24->r = D_801D6588;
    D_80062F24->g = D_801D6588;
    D_80062F24->b = D_801D6588;
    p = *pp; *(volatile ShopPrim **)pp = p + 1; func_80046794(D_80062FC4, (s32)p);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x5F, (s32)rect);
    D_801D6588 += arg0;
    if (D_801D6588 < 0) {
        D_801D6588 = 0;
    }
    if (D_801D6588 >= 0x100) {
        D_801D6588 = 0xFF;
    }
    return D_801D6588;
}

void func_801D0E00(s32 x, s32 y, u8 *slots) {
    s16 rect[4];
    s32 i;

    for (i = 0; i < 8; i++) {
        if (slots[i] != 0) {
            switch (slots[i]) {
            case 3:
            case 7:
                func_80028CA0((s16)(x + i * 0x10 - 8), (s16)y, 0x70, 0x30, 0x10, 0x10, 1, 0);
                break;
            }
        }
    }
    for (i = 0; i < 8; i++) {
        if (slots[i] != 0) {
            if (slots[i] >= 5) {
                func_80028CA0((s16)(x + i * 0x10), (s16)y, 0x80, 0x30, 0x10, 0x10, 1, 0);
            } else {
                func_80028CA0((s16)(x + i * 0x10), (s16)y, 0x70, 0x20, 0x10, 0x10, 1, 0);
            }
        }
    }
    rect[0] = x - 2;
    rect[2] = 0x80;
    rect[1] = y;
    rect[3] = 0xB;
    func_80027B84(rect);
    func_80026A34(0, 1, 0x1F, 0);
}

s32 func_801D0F90(s32 id) {
    s32 i;
    s32 n;

    if (id == 0xFF) {
        return 0;
    }
    i = 0;
    n = 0;
    for (; i < 200; i++) {
        if ((u8)D_8009CE60[i] == id) {
            n++;
        }
    }
    return n;
}

void func_801D0FE0(s32 shop) {
    D_80062DFD = 1;
    D_801D70E4 = shop;
    D_801D70EC = D_801D4714[shop].b;
    D_801D70E8 = D_801D4714[shop].a;
    D_801D70F0 = 0;
}

s32 func_801D104C(u32 m) {
    s32 r;

    if (m == -1) {
        return 0;
    }
    r = D_801D70E0->materia[m & 0xFF];
    if (r == 1) {
        return 1;
    }
    m >>= 8;
    if (m == 0xFFFFFF) {
        m = r * 70;
    }
    return m;
}

s32 func_801D10B0(s32 m) {
    s32 r;

    if (m == -1) {
        return 0;
    }
    r = D_801D70E0->materia[m & 0xFF];
    if (r == 1) {
        return 1;
    }
    return r * 70;
}

void func_801D1104(void) {
    s32 w;
    s32 t;
    Rect8 *r;

    ((void (*)(s32))func_80026B5C)(0x80);
    w = func_80026B70(D_801D42C8[D_801D70E8]);
    r = &D_801D70D4;
    t = w / 2 - 0x3B;
    func_80026F44(r->x - t, 0xB, D_801D42C8[D_801D70E8], 7);
    func_8001E040(r);
}

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D11A4);

s32 func_801D16D4(void) {
    s32 n;
    s16 type;
    s32 id;

    type = D_801D4714[D_801D70E4].e[D_801D9605 + D_801D95FC].type;
    id = D_801D4714[D_801D70E4].e[D_801D9605 + D_801D95FC].id;
    switch (type) {
    case 0:
        n = func_80025310(id) & 0xFFFF;
        if (n == 0xFFFF) {
            n = 0;
        } else {
            n >>= 9;
        }
        break;
    case 1:
        n = func_801D0F90(id & 0xFF);
        break;
    case 2:
        n = 0;
        break;
    }
    return n;
}

s32 func_801D17B0(s32 id) {
    s32 i;
    s32 j;
    s32 n;
    s32 (*w)[0x21];
    s32 (*a)[0x21];
    u16 *fp;

    n = 0;
    if (id == 0xFF) {
        return 0;
    }
    i = 0;
    fp = D_8009D78A;
    w = (s32 (*)[0x21])((u8 *)D_8009D78A - 0x1012);
    a = (s32 (*)[0x21])((u8 *)D_8009D78A - 0xFF2);
    for (; i < 9; i++) {
        if ((*fp >> i) & 1) {
            for (j = 0; j < 8; j++) {
                if ((u8)w[i][j] == (id & 0xFF)) {
                    n++;
                }
            }
            for (j = 0; j < 8; j++) {
                if ((u8)a[i][j] == (id & 0xFF)) {
                    n++;
                }
            }
        }
    }
    return n;
}

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D1868);

s32 func_801D1A2C(s32 item) {
    s32 n;
    s32 i;
    u16 *fp;
    u8 (*c)[0x84];

    n = 0;
    fp = D_8009D78A;
    c = (u8 (*)[0x84])((u8 *)D_8009D78A - 0x1035);
    for (i = 0; i < 9; i++) {
        if ((*fp >> i) & 1) {
            if (item >= 0x80) {
                if (item < 0x100) {
                    if (D_8009C754[i][0] + 0x80 == item) {
                        n++;
                    }
                } else if (item < 0x120) {
                    if (c[i][0] + 0x100 == item) {
                        n++;
                    }
                } else if (item < 0x140) {
                    if (c[i][0] + 0x120 == item) {
                        n++;
                    }
                }
            }
        }
    }
    return n;
}

void func_801D1AE0(void) {
    s32 pad[2];

    D_801D70E0 = &D_801D6854;
    func_80026448(D_801D95E8, 0, 0, 3, 1, 0, 0, 3, 1, 0, 0, 1, 0, 0);
    func_80026448(D_801D95E8 + 0x24, 0, 0, 2, 0xA, 0, 0, 2, 0xA0, 0, 0, 2, 0, 0);
    func_80026448(D_801D95E8 + 0x36, 0, 0, 1, 0xA, 0, 0, 1, 0xC8, 0, 0, 0, 0, 0);
    func_80025CD4(&D_801DEBBC);
    func_80043DD8(0);
    func_80025B8C(&D_801DBEBC);
    func_80043DD8(0);
    func_80025C14(&D_801D96BC);
    func_80043DD8(0);
    func_80025DF8();
    D_801D7058 = 0;
}

s32 func_801D1C4C(void) {
    s32 n;

    n = func_801D1868();
    return 0x63 - func_801D16D4() - n;
}

s32 func_801D1C84(void) {
    s32 found;
    s32 i;

    found = 0;
    for (i = 0; i < 200; i++) {
        if (D_8009CE60[i] == -1) {
            found = 1;
        }
    }
    return found;
}

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D1CC4);

void func_801D40A8(void) {
    func_80025C94(&D_801DEBBC);
    func_80025BD0(&D_801DBEBC);
    func_80025C54(&D_801D96BC);
    func_8003CEDC(0);
    func_800444AC(&D_801D95C0);
    func_800443B0(&D_801D9564);
}

void func_801D4118(s32 shop) {
    s32 i;

    func_80021044(D_801D9508, &D_801D95C0);
    func_801D0FE0(shop);
    D_801D70F4 = 0;
    i = 0;
    func_801D1AE0();
    D_801D70F8 = 0;
    while (1) {
        func_8001CB48();
        func_800269C0((s32)(D_80077F64 + D_801D70F8 * 0x3400));
        D_801D70FC = D_801D7100 + D_801D70F8 * 4;
        func_8004418C(D_801D70FC, 1);
        func_80026A00((s32)D_801D70FC);
        func_801D1CC4(i);
        if (D_801D70F4 == -1) {
            break;
        }
        func_80043DD8(0);
        func_8003CEDC(0);
        func_800444AC((void *)((u8 *)&D_801D95C0 + D_801D70F8 * 0x14));
        func_800443B0((void *)(D_801D9508 + D_801D70F8 * 0x5C));
        i++;
        func_8004433C((s32)D_801D70FC);
        D_801D70F8 ^= 1;
    }
    func_801D40A8();
    func_8003CEDC(0);
    func_800444AC((void *)D_801D95D4);
    func_800443B0((void *)D_801D9508);
}
