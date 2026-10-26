#include "common.h"
#include "main/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
M2C_UNK func_80043F6C(Rect16 *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_80038FB8(s32 arg0);
s32 func_80042C98(s32 arg0);
M2C_UNK func_80042D98();
s32 func_80039A74(s32 arg0);
DispEnv *func_800438D4(DispEnv *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_80046794(MainTag *arg0, MainTag *arg1);
s32 func_80036FFC(s32 arg0, MainWords *arg1);
s32 func_80042BC0(s32 arg0, s16 arg1, s32 arg2);
s32 func_80041E30(s32 arg0, s32 arg1);
s32 func_800436C0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_80042168(s32);

s32 func_800404F4(s32 arg0, M2C_UNK arg1, s32 arg2) {
    s32 sp10;

    func_8003E2D0(arg1, &sp10);
    func_8003DE9C(2, &sp10, 0);
    func_80041D28(arg0, arg2, 0x80);
    return func_80041E30(0, 0) == 0;
}

void func_80040560(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 i;
    s32 pad;

    for (i = arg2 - 1; i != -1; i--) {
        *arg0++ = *arg1++;
    }
}

s32 func_80040594(s32 arg0) {
    s8 sp10;

    sp10 = (s8) arg0;
    func_8003DE9C(0xE, (s32 *) &sp10, 0);
    if (arg0 & 0x100) {
        if (arg0 & 0x20) {
            D_80071C18 = 0;
        } else {
            D_80071C18 = 1;
        }
        func_8003E28C((s32) &func_80040950);
        func_8003DE84((s32) func_80040628);
    }
    return func_8003DE9C(0x1B, NULL, 0);
}

void func_80040628(void) {
    func_80040CA8();
}

s32 func_80040648(s32 arg0) {
    u8 sp10[8];
    s32 r;
    s32 i;

    func_8003E100(1, 0, (s32) sp10);
    if (sp10[0] & 0x10) {
        return 0x10;
    }
    r = func_8003E100(0x13, 0, (s32) sp10);
    if (arg0 == 1) {
        if (sp10[0] == 2 && r != 0) {
            return 2;
        }
        return 5;
    }
    i = 0;
    do {
        if (sp10[0] & 2) {
            if (sp10[0] == 2 && r != 0) {
                return 2;
            }
            do {
                func_8003CEDC(0x1E);
                r = func_8003E100(0x13, 0, (s32) sp10);
            } while (sp10[0] != 2 || r == 0);
            return 2;
        }
        func_8003CEDC(0x1E);
        r = func_8003E100(0x13, 0, (s32) sp10);
        i++;
    } while (i < 10);
    return 5;
}

s32 func_8004076C(void) {
    u8 loc[8];
    u8 buf[0x800];
    u8 result[8];
    u8 mode;
    s32 i;
    s32 r;
    s32 s;
    s32 t;
    s32 u;

    mode = 0x80;
    func_8003DE9C(1, 0, (s32) result);
    if (result[0] & 0x10) {
        return 0x10;
    }
    func_8003E2D0(0x10, loc);
    func_8003DE9C(0xE, (s32) &mode, 0);
    func_8003DE9C(0x1B, (s32) loc, 0);
    i = 0;
    do {
        r = ((s32 (*)(s32, u8 *)) func_8003DE4C)(0, result);
        i++;
        if (r == 1) {
            break;
        }
        if (i < 10) {
            func_8003DE9C(0x1B, (s32) loc, 0);
        }
    } while (i < 10);
    s = r;
    if (s != 1) {
        t = result[0];
        if (t & 0x10) {
            return 0x10;
        }
        u = t & 2;
        return u != 0;
    }
    func_8003DE9C(9, 0, 0);
    ((void (*)(u8 *, s32)) func_8003E268)(buf, 0x200);
    if (func_80042D78(buf + 1, "CD001", 5) != 0) {
        return 1;
    }
    return 2;
}

s32 func_80040898(void) {
    s32 temp_v0;

    D_8009C550 = 0;
    D_8009C54C = 0;
    D_8009C548 = 0;
    D_80095D80 = 0;
    temp_v0 = func_80040B84(0, D_8009FE90);
    D_80075CFC = 0;
    D_80071C10 = 0;
    D_80071740 = 0;
    return temp_v0;
}

s32 func_800408F8(void) {
    func_80042AF0();
    func_8003E28C(0);
    func_8003DE84(0);
    *D_8005194C = 0;
    *D_80051958 = 0;
    return func_80042B00();
}

void func_80040950(void) {
    MainCdq *p;

    p = (MainCdq *) ((D_8009C54C << 5) + D_8009C6D4);
    p->unk0 = 2;
    D_80070544 = p->unk1C;
    do {
        D_80070548 = p->unk8;
        D_8009C54C = D_8009C548;
        if (D_80074EA0 != 0) {
            D_80074EA0();
        }
    } while (0);
    D_80095D80 = 0;
}

s32 func_800409E0(s32 *arg0) {
    s32 r;

    if (D_80071C18 == 0) {
        func_8003E2D0(func_8003E3D4(&D_80070544) + 1, arg0);
        r = D_80070548;
    } else {
        r = -1;
    }
    return r;
}

void func_80040A40(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_80040C88(1, arg1, arg2);
    D_8009C6C0 = 0;
    D_80074EA0 = arg3;
    D_80071C14 = arg0 & 1;
    D_80081DC0 = 0;
    D_8007E764 = 0;
    D_80071C10 = 0;
    D_80071740 = 0;
    D_800756E4 = arg4;
}

s32 func_80040AC8(s32 *arg0) {
    s32 idx;
    s32 i;
    s32 n;
    void *p;
    s32 pad;

    idx = (arg0 - (s32 *) ((D_8009FE90 << 5) + D_8009C6D4)) / 504;
    p = (void *) ((idx << 5) + D_8009C6D4);
    n = M2C_FIELD(p, u16 *, 6);
    if (M2C_FIELD(p, s16 *, 0) != 4) {
        return 1;
    }
    for (i = 0; i < (s16) n; i++) {
        *(u16 *) (((i + idx) << 5) + D_8009C6D4) = 0;
    }
    D_8009C550 = i + idx;
    return 0;
}

s32 func_80040B84(s32 arg0, u32 arg1) {
    u32 i;
    s32 pad;

    for (i = 0; i < arg1; i++) {
        *(s32 *) (((i + arg0) << 5) + D_8009C6D4) = 0;
    }
}

s32 func_80040BC4(s32 *arg0, void **arg1) {
    volatile u16 *p;

    p = (u16 *) ((D_8009C550 << 5) + D_8009C6D4);
    if (*p == 1) {
        D_8009C550 = 0;
        if (D_8009C6C8 != 0) {
            *p = 0;
        }
        p = (u16 *) ((D_8009C550 << 5) + D_8009C6D4);
    }
    if (*p == 2) {
        *p = 4;
        *arg0 = (D_8009FE90 << 5) + D_8009C6D4 + D_8009C550 * 0x7E0;
        *arg1 = (void *) p;
        return 0;
    }
    return 1;
}

void func_80040C88(s32 arg0, s32 arg1, s32 arg2) {
    D_8009C6CC = arg0;
    D_8007E76C = arg1;
    D_8009C6C8 = arg2;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80040CA8);

void func_80041620(s32 *arg0, s32 *arg1, u32 arg2) {
    u32 i;
    s32 pad;

    for (i = 0; i < arg2; i++) {
        *arg0++ = *arg1++;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80041654);

void func_80041810(s16 *arg0, s16 *arg1) {
    s32 i;
    s16 d;
    u16 *p;

    i = D_8009FE90;
    *arg0 = 0;
    d = (u16) D_8009C548 - (u16) D_8009C550;
    *arg1 = d;
    if (d < 0) {
        i--;
        for (; i >= 0; i--) {
            p = (u16 *) ((i << 5) + D_8009C6D4);
            if (*p == 1) {
                break;
            }
        }
        i++;
        *arg1 = (u16) *arg1 + i;
    }
    while (--i >= 0) {
        if (*(u16 *) ((i << 5) + D_8009C6D4) == 0) {
            p = (u16 *) arg0;
            *arg0 = (u16) *p + 1;
        }
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_800418D8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80041AFC);

void func_80041CD4(void) {
    *(volatile s32 *) &D_80051A34 = 0;
    func_8003DE6C(D_80051A44);
    func_8003DE84(D_80051A48);
    func_8003DE9C(9, NULL, 0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3", func_80041D28);

s32 func_80041E30(s32 arg0, s32 arg1) {
    s32 r;

    do {
        r = -1;
        if (func_8003CEDC(-1) <= D_80051A3C[0] + 0x4B0) {
            if (D_80051A3C[-2] < 0 || func_8003CEDC(-1) > D_80051A3C[-1] + 0x3C) {
                func_80041AFC(1);
                r = D_80051A3C[-7];
            } else {
                r = D_80051A3C[-2];
            }
        }
    } while (arg0 == 0 && r > 0);
    ((void (*)(s32, s32)) func_8003DE4C)(1, arg1);
    return r;
}

s32 func_80041EFC(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80051A1C;
    D_80051A1C = arg0;
    return temp_v0;
}

s32 func_80041F14(s32 arg0) {
    if (arg0 == 0) {
        func_8003D0C0();
    }
    return func_80042168(arg0);
}

s32 *func_80041F4C(s32 *arg0) {
    s32 *d;
    s32 *s;
    s32 i;

    d = arg0;
    s = D_80051A50;
    for (i = 0xF; i != -1; i--) {
        *d++ = *s++;
    }
    d = arg0 + 0x10;
    s = D_80051A90;
    for (i = 0xF; i != -1; i--) {
        *d++ = *s++;
    }
    d = arg0 + 0x20;
    s = D_80051AD4;
    for (i = 0x1F; i != -1; i--) {
        *d++ = *s++;
    }
    return arg0;
}

s32 *func_80041FD8(s32 *arg0) {
    s32 *d;
    s32 *s;
    s32 i;

    d = D_80051A50;
    s = arg0;
    for (i = 0xF; i != -1; i--) {
        *d++ = *s++;
    }
    d = D_80051A90;
    s = arg0 + 0x10;
    for (i = 0xF; i != -1; i--) {
        *d++ = *s++;
    }
    return arg0;
}

u16 func_80042038(u16 *arg0) {
    return *arg0;
}

void func_80042044(volatile u32 *arg0, s32 arg1) {
    s32 mask;

    if (arg1 & 1) {
        *arg0 = *arg0 & 0xF7FFFFFF;
    } else {
        *arg0 = *arg0 | 0x08000000;
    }
    mask = 0x02000000;
    if (arg1 & 2) {
        *arg0 = *arg0 | mask;
    } else {
        *arg0 = *arg0 & 0xFDFFFFFF;
    }
    func_80042270(arg0, *(volatile u16 *) arg0);
}

void func_800420C0(void) {
    func_80042304();
}

void func_800420E0(void) {
    func_80042394();
}

void func_80042100(void) {
    func_8004242C();
}

void func_80042120(s32 arg0) {
    func_8003D120(0, arg0);
}

void func_80042144(s32 arg0) {
    func_8003D120(1, arg0);
}
