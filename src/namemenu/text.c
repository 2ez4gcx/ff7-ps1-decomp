#include "common.h"
#include "namemenu/decls.h"

void func_801D0014(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

s32 func_801D0054(s32 arg0) {
    s16 rect[4];
    volatile NmPrim *p;
    volatile NmPrim *volatile *pp;

    pp = &D_80062F24;
    D_80062F24->len = 3;
    D_80062F24->code = 0x60;
    func_80046848(*pp, 1);
    D_80062F24->x = 0;
    D_80062F24->y = 0;
    D_80062F24->w = 0x180;
    D_80062F24->h = 0xE8;
    D_80062F24->r = D_801D1E78;
    D_80062F24->g = D_801D1E78;
    D_80062F24->b = D_801D1E78;
    p = *pp; *(volatile NmPrim **)pp = p + 1; func_80046794(D_80062FC4, (s32)p);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x5F, (s32)rect);
    D_801D1E78 += arg0;
    if (D_801D1E78 < 0) {
        D_801D1E78 = 0;
    }
    if (D_801D1E78 >= 0x100) {
        D_801D1E78 = 0xFF;
    }
    return D_801D1E78;
}

void func_801D01CC(void) {
    s32 i;
    s32 m;

    for (i = 0; i < 0x140; i++) {
        D_8009CBE0[i] = i | 0xC600;
    }
    for (i = 0; i < 0x100; i++) {
        m = i - i / 91 * 91;
        if (m != 0x2E && m != 0x2F && m != 0x2D && m != 0x26 && m != 0x3F && m != 0x42 && m != 0x43 && m != 0x11) {
            D_8009CE60[i] = m;
        } else {
            D_8009CE60[i] = 0x1D;
        }
    }
    D_8009CE60[0] = 0x35;
    D_8009D78A[0] = 0xFFFF;
}

void func_801D02C8(s32 arg0) {
    ((NmChr *)D_8009C738)[arg0] = D_801D904C[arg0];
}

void func_801D0328(void) {
    s32 i;

    i = 0;
    D_801D978C = 0;
    for (; i < 15; i++) {
        D_801D977C[i] = D_801D8E6C[D_801D9048][i];
        if (D_801D8E6C[D_801D9048][i] == 0xFF) {
            D_801D977C[i + 1] = 0xFF;
            if (i >= 9) {
                D_801D978C = 8;
            }
            break;
        }
        D_801D978C++;
    }
}

void func_801D0400(void) {
    D_801D9024 = 0;
    D_801D9028 = 2;
    D_801D9744[0].f = 0;
    D_801D9744[0].g = 0;
    D_801D9744[0].x = 0;
    D_801D9744[0].y = 0;
    D_801D9744[0].cols = 10;
    D_801D9744[0].rows = 9;
    D_801D9744[0].w = 10;
    D_801D9744[0].h = 9;
    D_801D9744[0].l = 0;
    D_801D9744[0].m = 0;
    D_801D9744[0].j = 0;
    D_801D9744[0].k = 0;
    D_801D9744[0].e = 0;
    D_801D9744[1].f = 0;
    D_801D9744[1].g = 0;
    D_801D9744[1].x = 0;
    D_801D9744[1].y = 0;
    D_801D9744[1].cols = 1;
    D_801D9744[1].rows = 4;
    D_801D9744[1].w = 1;
    D_801D9744[1].h = 4;
    D_801D9744[1].l = 0;
    D_801D9744[1].m = 1;
    D_801D9744[1].j = 0;
    D_801D9744[1].k = 0;
    D_801D9744[1].e = 0;
    if (D_801D9048 == 6) {
        func_801D02C8(6);
    }
    if (D_801D9048 == 7) {
        func_801D02C8(7);
    }
    if (D_801D9048 >= 100) {
        D_801D9048 = 9;
    }
    func_80025C14((s32)D_801D9870);
    func_80025D14(D_801D8DE4[D_801D9048], 0x340, 0x100, 0x180, 0);
    func_801D0328();
}

s32 func_801D05BC(s32 arg0, s32 arg1, s32 arg2) {
    s32 v;

    switch (arg0) {
    case 0:
        v = D_801D8F24[arg2 * 10 + arg1];
        break;
    case 1:
        v = D_801D8F80[arg2 * 10 + arg1];
        break;
    case 2:
        v = D_801D8FDC[arg2 * 10 + arg1];
        break;
    }
    return v;
}

void func_801D066C(s32 arg0) {
    u8 n;

    if (D_801D9048 != 9) {
        n = D_801D978C;
        if (n == 8) {
            D_801D977C[8] = arg0;
            D_801D977C[9] = 0xFF;
        } else {
            D_801D978C = n + 1;
            D_801D977C[n] = arg0;
            D_801D977C[D_801D978C] = 0xFF;
        }
    } else {
        n = D_801D978C;
        if (n != 5) {
            D_801D978C = n + 1;
            D_801D977C[n] = arg0;
            D_801D977C[D_801D978C] = 0xFF;
        } else {
            D_801D977C[5] = arg0;
            D_801D977C[6] = 0xFF;
        }
    }
}

void func_801D0724(void) {
    u8 n;

    n = D_801D978C;
    if (n != 0) {
        if (D_801D9048 != 9) {
            if (n == 8 && D_801D9784 != 0xFF) {
                D_801D9784 = 0xFF;
            } else {
                D_801D978C = n - 1;
                D_801D977C[(u8)(n - 1)] = 0xFF;
            }
        } else {
            if (n != 5 || D_801D9781 == 0xFF) {
                D_801D978C = n - 1;
                D_801D977C[(u8)(n - 1)] = 0xFF;
            } else {
                D_801D9781 = 0xFF;
            }
        }
    }
}

s32 func_801D07D8(s32 arg0) {
    s32 i;
    s32 j;
    u8 *name;

    for (i = 0; i < 9; i++) {
        name = D_8009C748[D_801D9048];
        if (D_801D8E0C[arg0][i] != name[i]) {
            break;
        }
        if (i == 8) {
            switch (arg0) {
            case 0:
                func_801D01CC();
                break;
            case 1:
                for (j = 0; j < 21; j++) {
                    func_8002542C(D_801D9680[j] - 0x100);
                }
                break;
            case 2:
                for (j = 0; j < 16; j++) {
                    func_8002542C(D_801D96D4[j] - 0x100);
                }
                break;
            case 3:
                for (j = 0; j < 7; j++) {
                    func_8002542C(D_801D9714[j] - 0x100);
                }
                break;
            case 4:
                for (j = 0; j < 2; j++) {
                    func_8002542C(D_801D9730[j] - 0x100);
                }
                break;
            }
        }
    }
}

void func_801D099C(s32 arg0) {
    s16 win[4];
    s16 rect[4];
    s32 i;
    s32 j;
    s32 c;
    s32 old;
    u8 *name;

    if (D_801DC074 == 0) {
        if (func_801D0054(-10) == 0) {
            D_801DC074 = 1;
        }
    } else if (D_801DC074 == 2) {
        if (func_801D0054(10) == 0xFF) {
            D_801DC074 = -1;
        }
    }
    if (D_801DC074 == 1) {
        old = D_801D9744[D_801D9024].f;
        func_800264A8(&D_801D9744[D_801D9024]);
        if (D_80062D7E & 4) {
            func_801D0014(1);
        } else if (D_80062D7E & 8) {
            func_801D0014(1);
        }
        if (D_801D9028 == 2 && D_801D9744[0].g >= 7) {
            D_801D9744[0].g = 6;
        }
        switch (D_801D9024) {
        case 0:
            func_8001EB2C(D_801D9744[0].f * 20 + 20, D_801D9744[0].g * 16 + 100);
            if ((D_80062D7E & 0x2000) && old == D_801D9744[D_801D9024].f && !(D_80062D78 & 0x5000)) {
                func_801D0014(1);
                D_801D9024 = 1;
            } else if (D_80062D7E & 0x20) {
                func_801D0014(1);
                func_801D066C(func_801D05BC(D_801D9028, D_801D9744[0].f, D_801D9744[0].g));
            } else if (D_80062D7E & 0x40) {
                func_801D0014(4);
                func_801D0724();
            }
            break;
        case 1:
            func_8001EB2C(0x114, D_801D9744[1].g * 16 + 0x9B);
            if ((D_80062D7E & 0x8000) && old == D_801D9744[D_801D9024].f) {
                func_801D0014(1);
                D_801D9024 = 0;
            }
            if (D_80062D7E & 0x20) {
                func_801D0014(1);
                switch (D_801D9744[D_801D9024].g) {
                case 0:
                    func_801D066C(0);
                    break;
                case 1:
                    func_801D0724();
                    break;
                case 2:
                    if (D_801D978C != 0) {
                        if (D_801D9048 != 9) {
                            for (i = 0; i < 9; i++) {
                                D_8009C748[D_801D9048][i] = D_801D977C[i];
                                if (D_801D9048 == 0) {
                                    D_8009CA60[i] = D_801D977C[i];
                                }
                            }
                            name = D_8009C748[D_801D9048];
                            name[i] = 0xFF;
                        } else {
                            for (i = 0; i < 6; i++) {
                                D_8009D488[i] = D_801D977C[i];
                            }
                            D_8009D488[i] = 0xFF;
                        }
                        D_801DC074 = 2;
                    }
                    break;
                case 3:
                    func_801D0328();
                    break;
                }
            }
            break;
        }
        if (D_80062D7E & 0x800) {
            D_801D9024 = 1;
            D_801D9744[1].g = 2;
            func_801D0014(1);
        }
    }
    for (j = 0; j < 9; j++) {
        for (i = 0; i < 10; i++) {
            switch (D_801D9028) {
            case 0:
                ((void (*)(s32, s32, s32, s32))func_8002708C)(i * 0x14 + 0x30, j * 14 + 0x62, D_801D8F24[j * 10 + i], 7);
                break;
            case 1:
                ((void (*)(s32, s32, s32, s32))func_8002708C)(i * 0x14 + 0x30, j * 14 + 0x62, D_801D8F80[j * 10 + i], 7);
                break;
            case 2:
                if (j < 7) {
                    func_80026C5C(i * 0x14 + 0x30, j * 16 + 0x62, 7, D_801D8FDC[j * 10 + i]);
                    rect[0] = 0;
                    rect[1] = 0;
                    rect[2] = 0x100;
                    rect[3] = 0x100;
                    func_80026A34(0, 1, 0x7E, (s32)rect);
                }
                break;
            }
        }
    }
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0x100;
    rect[3] = 0x100;
    func_80026A34(0, 1, 0x7F, (s32)rect);
    for (j = 0; j < 4; j++) {
        func_80026F44(0x130, j * 16 + 0x9A, D_801D8EFC[j], 7);
    }
    if (D_801D9048 != 9) {
        for (i = 0; i < 9; i++) {
            if (i == D_801D978C) {
                c = (arg0 & 4) ? 0xFFFF00 : 0x808000;
                ((void (*)(s32, s32, s32, s32))func_8001D47C)(i * 13 + 0x64, i * 13 + 0x6F, 0x42, c);
            } else {
                ((void (*)(s32, s32, s32, s32))func_8001D47C)(i * 13 + 0x64, i * 13 + 0x6F, 0x42, 0xFFFFFF);
            }
        }
    } else {
        for (i = 0; i < 6; i++) {
            if (i == D_801D978C) {
                c = (arg0 & 4) ? 0xFFFF00 : 0x808000;
                ((void (*)(s32, s32, s32, s32))func_8001D47C)(i * 13 + 0x64, i * 13 + 0x6F, 0x42, c);
            } else {
                ((void (*)(s32, s32, s32, s32))func_8001D47C)(i * 13 + 0x64, i * 13 + 0x6F, 0x42, 0xFFFFFF);
            }
        }
    }
    for (i = 0; i < 9; i++) {
        if (D_801D977C[i] == 0xFF) {
            break;
        }
        func_80026C5C(i * 13 + 0x64, 0x34, 7, D_801D977C[i]);
    }
    func_80026F44(0x20, 0xE, func_80015248(8, 10, 8), 7);
    func_8001D180(0x16, 0x24, 0x30, 0x30, 0, 0, 0x30, 0x30, 0, 0);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x7F, (s32)rect);
    func_8001DE0C(win, 0, 5, 0x16C, 0x1B);
    func_8001E040(win);
    func_8001DE0C(win, 0, 0x20, 0x16C, 0x38);
    func_8001E040(win);
    func_8001DE0C(win, 0, 0x58, 0x11C, 0x88);
    func_8001E040(win);
    func_8001DE0C(win, 0x118, 0x58, 0x54, 0x88);
    func_8001E040(win);
}

void func_801D1254(void) {
    if (D_801D9048 != 9 && D_801D9048 != 0) {
        func_801D14E8(D_8009C738[D_800491D0[D_801D9048]]);
        D_8009C760[D_801D9048].hp = D_8009C760[D_801D9048].maxhp;
        D_8009C760[D_801D9048].mp = D_8009C760[D_801D9048].maxmp;
    }
    func_80025C54(D_801D9870);
}

void func_801D131C(s32 arg0) {
    s32 i;

    func_80021044(D_801D9790, D_801D9848);
    D_801D9048 = arg0;
    D_801DC074 = 0;
    i = 0;
    func_801D0400();
    D_801DC070 = 0;
    while (1) {
        func_8001CB48();
        func_800269C0((s32)(D_80077F64 + D_801DC070 * 0x3400));
        D_801D9738 = D_801D973C + D_801DC070 * 4;
        func_8004418C(D_801D9738, 1);
        func_80026A00((s32)D_801D9738);
        func_801D099C(i);
        if (D_801DC074 == -1) {
            break;
        }
        func_80043DD8(0);
        func_8003CEDC(0);
        func_800444AC((void *)(D_801D9848 + D_801DC070 * 0x14));
        func_800443B0((void *)(D_801D9790 + D_801DC070 * 0x5C));
        i++;
        func_8004433C((s32)D_801D9738);
        D_801DC070 ^= 1;
    }
    func_8003CEDC(0);
    func_801D1254();
    func_800444AC((void *)D_801D9848);
    func_800443B0((void *)D_801D9790);
    func_8003CEDC(0);
    func_800444AC((void *)(D_801D9848 + 0x14));
    func_800443B0((void *)(D_801D9790 + 0x5C));
}
