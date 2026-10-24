#include "common.h"
#include "eqipmenu/decls.h"

void func_801D0124(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_801D0164(void) {
    func_8001F6AC();
}

void func_801D0184(s32 x, s32 y, u8 *slots) {
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

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D0314);

void func_801D0574(void) {
    D_801D8AEC = 0;
    D_801D8AF0 = 0;
    D_801D8AE8 = D_80062F6C;
    func_80026448(D_801D8AA0, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0);
    func_80026448(D_801D8AA0 + 0x12, 0, 0, 1, 8, 0, 0, 1, 0x10, 0, 0, 0, 0, 0);
}

void func_801D064C(void) {
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D0654);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D0BD0);

void func_801D1B8C(void) {
}

void func_801D1B94(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

u32 func_801D1BD4(u32 arg0) {
    return arg0 >> 0x1F;
}

s32 func_801D1BDC(s32 arg0) {
    s32 var_v0;

    var_v0 = arg0;
    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }
    return var_v0;
}

void func_801D1BF4(void) {
    s32 i;
    s32 n;
    s32 color;

    n = 0;
    for (i = 0; i < 8; i++) {
        if (D_801D8B08->v[i] != 0) {
            if (func_801D1BD4(D_801D8B08->v[i]) != 0) {
                ((void (*)(s32, s32, s32, s32))func_8002708C)(0xB4, n * 0xB + 0x9A, 0xE1, 7);
                color = 2;
            } else {
                ((void (*)(s32, s32, s32, s32))func_8002708C)(0xB4, n * 0xB + 0x9A, 0xB3, 7);
                color = 6;
            }
            func_80029114(0xBC, n * 0xB + 0x9A, func_801D1BDC(D_801D8B08->v[i]), 2, color);
            func_80026A34(0, 1, 0x1F, 0);
            func_80026F44(0x78, n * 0xB + 0x98, D_801D8674[i], 7);
            if (i >= 6) {
                ((void (*)(s32, s32, s32, s32))func_8002708C)(0xCA, n * 0xB + 0x9A, 0xD3, 7);
            }
            n++;
        }
    }
    func_80026A34(0, 1, 0x1F, 0);
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D1D5C);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D26A4);

void func_801D2A80(s32 *arg0, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D2A94);

void func_801D2CE4(s32 *arg0, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}

s32 func_801D2CF8(u8 arg0, u8 arg1, u32 arg2, u32 arg3) {
    if (arg0 == arg1) {
        if (arg2 == arg3) {
            return 0;
        }
        if (arg3 < arg2) {
            return -1;
        }
        return 1;
    }
    if (arg1 < arg0) {
        return 1;
    }
    return -1;
}

s16 func_801D2D40(u16 arg0, u16 arg1, u32 **arg2) {
    s32 ca;
    s32 cb;
    u32 ka;
    u32 kb;

    if ((*arg2)[arg0] == -1) {
        ca = 0x80;
        ka = 0;
    } else {
        ca = ((s32 (*)(u32))func_8002603C)((*arg2)[arg0]);
        ka = ((*arg2)[arg0] >> 8) + ((*arg2)[arg0] << 24);
    }
    if ((*arg2)[arg1] == -1) {
        cb = 0x80;
        kb = 0;
    } else {
        cb = ((s32 (*)(u32))func_8002603C)((*arg2)[arg1]);
        kb = ((*arg2)[arg1] >> 8) + ((*arg2)[arg1] << 24);
    }
    return func_801D2CF8(ca, cb, ka, kb);
}

void func_801D2E40(u16 arg0, u16 arg1, s32 **arg2) {
    func_801D2CE4(*arg2 + arg0, *arg2 + arg1);
}

void func_801D2E78(s32 arg0) {
    if (arg0 == 0) {
        func_801D2A94(D_8009CE60, 0xC8, &func_801D2D40, &func_801D2E40);
    }
}

void func_801D2EB4(void) {
}

s32 func_801D2EBC(s32 arg0, s32 arg1) {
    s32 ret;

    switch (arg0) {
    case 1:
        ret = func_80015248(0xD, arg1, 0);
        break;
    case 0:
        ret = func_80015248(5, arg1, 0);
        break;
    }
    return ret;
}

void func_801D2EFC(void) {
    s32 pad[2];
    Rect8 rect;
    u8 *rec;
    s32 rows;
    s32 i;
    s32 j;
    s32 dx;
    s32 x;
    u8 m;

    rec = D_8009D84C[D_801DF6B0];
    rows = rec[0x21];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < 4; j++) {
            m = ((Obj4C *)rec)->e[j + i * 4].a;
            if (m != 0xFF) {
                dx = (rows >= 2 && i > 0) ? 8 : 0;
                x = i * 0x2C + 6;
                func_80026F44(D_801D8834 + x + dx, D_801D8836 + j * 0xC + 5, func_80015248(5, m, 8), 7);
            }
        }
    }
    func_8001DE0C(&rect, D_801D8834, D_801D8836, D_801D884A[rows], D_801D883A);
    func_8001E040(&rect);
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D3074);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D3490);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D373C);

void func_801D3A24(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 0x38; j++) {
            if (((EqpChrMat *)D_8009D954)[i].e[j].id != 0xFF && ((EqpChrMat *)D_8009D954)[i].e[j].flag != 0 && (((EqpChrMat *)D_8009D954)[i].e[j].attr & 0xC) != 0xC) {
                ((EqpChrMat *)D_8009D954)[i].e[j].flag = 0;
            }
        }
    }
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D3AA0);

void func_801D3CB0(void) {
    s32 i;

    D_801D8830 = 1;
    D_801DF6B0 = D_80062F6C;
    func_80026448(&D_801DF590[0], 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0);
    func_80026448(&D_801DF590[1], 0, 0, 8, 2, 0, 0, 8, 2, 0, 0, 0, 0, 0);
    func_80026448(&D_801DF590[3], 0, 0, 1, 0xA, 0, 0, 1, 0xC8, 0, 0, 0, 0, 0);
    for (i = 0; i < 3; i++) {
        func_80020058(i);
        func_8001786C(i & 0xFF);
    }
    func_80017678();
    func_801D827C(0x73, 0x9D);
    D_80062D9C = 1;
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D3E14);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D4418);

void func_801D4678(s32 arg0) {
    D_80063020 = 1;
    func_800197B8(D_8009CE60[D_801DF590[arg0].pos + D_801DF590[arg0].top]);
    func_801D1D5C(D_8009CE60[D_801DF590[arg0].pos + D_801DF590[arg0].top], D_801DF6BC, D_800706A4[D_80062F58]);
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D4760);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D4AA8);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D4D94);

void func_801D509C(void) {
    s16 rect[4];

    func_80020B68(0x3E, 0x13, D_801DF6B0);
    func_8001CF3C(0xA, 0xE, 0x30, 0x30, 0, D_801DF6B0 * 0x30 + 0x38, 0x30, 0x30, D_801DF6B0 + 0xD, 0);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0x100;
    rect[3] = 0x100;
    func_80026A34(0, 1, 0x7F, (s32)rect);
}

void func_801D513C(u8 *a, u8 *b, s32 *c, s32 *d) {
    s32 i;
    s32 t;

    for (i = 0; i < 8; i++) {
        if (a[i] != 0 && b[i] != 0) {
            t = c[i];
            c[i] = d[i];
            d[i] = t;
        }
    }
}

void func_801D5194(void) {
    s32 i;
    s32 n;
    u8 *p;
    u16 *q;

    for (i = 0; i < 9; i++) {
        D_801DF6EC[i] = 0xFF;
    }
    i = 0;
    n = 0;
    q = D_8009D78A;
    p = D_801DF6EC;
    for (; i < 9; i++) {
        if ((*q >> i) & 1) {
            *p++ = i;
            n++;
        }
    }
    D_801DF6E8 = n;
    func_80026448(&D_801DF590[11], 0, 0, 1, 0xA, 0, 0, 1, 0xC8, 0, 0, 0, 0, 0);
    func_80026448(&D_801DF590[12], 0, 0, 8, 2, 0, 0, 8, 2, 0, 0, 0, 0, 0);
    func_80026448(&D_801DF590[13], 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 0, 0);
}

s32 func_801D5300(s32 x, s32 y, s32 item) {
    s16 rect[4];
    s32 i;
    s32 color;
    u8 id;

    id = item;
    func_80026F44(x + 0x10, y, ((void *(*)(s32))func_80021258)(id), 7);
    color = func_8002603C(id);
    func_80028CA0((s16)x, (s16)(y - 1), 0x80, 0x20, 0x10, 0x10, (s16)color, 0);
    func_80026A34(0, 1, 0x3F, 0);
    func_800197B8(item);
    if (id != 0x30 && id != 0x49 && id != 0x5A && id != 0x2C) {
        for (i = 0; i < D_801D8B08->count; i++) {
            if (i < D_801D8B08->filled) {
                func_80028CA0((s16)(0xAA + i * 0xF), 0xB, 0x90, 0x20, 0x10, 0x10, (s16)color, 0);
            } else {
                func_80028CA0((s16)(0xAA + i * 0xF), 0xB, 0x90, 0x30, 0x10, 0x10, (s16)color, 0);
            }
        }
    }
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x7F, (s32)rect);
    return color;
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D54B0);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D5BD0);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D6C2C);

void func_801D7FDC(void) {
    D_80062D9C = 0;
}

void func_801D7FEC(void) {
}

void func_801D7FF4(void) {
    u16 *p;

    if (D_80062D80 & 8) {
        *(volatile s32 *)&D_801D88EC -= 0x80;
    }
    if (D_80062D80 & 2) {
        *(volatile s32 *)&D_801D88EC += 0x80;
    }
    p = &D_801D88E0;
    *p += 0x20;
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D8070);

void func_801D827C(void) {
}

void func_801D8284(void) {
}

void func_801D828C(void) {
}

void func_801D8294(void) {
}

void func_801D829C(void) {
}
