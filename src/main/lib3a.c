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
s32 func_80041D28(s32 arg0, s32 arg1, s32 arg2);

void func_80041620(s32 *arg0, s32 *arg1, u32 arg2) {
    u32 i;
    s32 pad;

    for (i = 0; i < arg2; i++) {
        *arg0++ = *arg1++;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3a", func_80041654);

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

void func_800418D8(u8 arg0, s32 arg1) {
    s32 sp10[4];
    volatile s32 *p;
    volatile s32 *q;
    s32 t;

    if (arg0 == 1) {
        p = &D_80051A34;
        if (*p > 0) {
            if (D_80051A30 == 0x200) {
                ((s32 (*)(s32 *, s32)) func_8003E268)(sp10, 3);
                if (func_8003E3D4(sp10) != D_80051A40) {
                    func_80042D48("CdRead: sector error\n");
                    *p = -1;
                }
            }
            q = &D_80051A28;
            t = *q;
            ((s32 (*)(s32, s32)) func_8003E268)(t, D_80051A30);
            *q += D_80051A30 * 4;
            --D_80051A34;
            ++D_80051A40;
        }
    } else {
        *(volatile s32 *) &D_80051A34 = -1;
    }
    *(volatile s32 *) &D_80051A38 = func_8003CEDC(-1);
    if (D_80051A34 < 0) {
        func_80041AFC(1);
    }
    if (func_8003CEDC(-1) > D_80051A3C[0] + 0x4B0) {
        D_80051A34 = -1;
    }
    /* (&D_80051A38)[1] is D_80051A3C again, through another name, read anew */
    if (D_80051A34 == 0 || func_8003CEDC(-1) > (&D_80051A38)[1] + 0x4B0) {
        func_8003DE6C(D_80051A44);
        func_8003DE84(D_80051A48);
        func_8003DE9C(9, 0, 0);
        if (D_80051A1C != 0) {
            ((void (*)(s32, s32)) D_80051A1C)(D_80051A34 == 0 ? 2 : 5, arg1);
        }
    }
}

s32 func_80041AFC(s32 arg0) {
    s8 sp10;
    s32 temp_s0;
    volatile s32 *p;
    s32 m;

    func_8003DE6C(0);
    func_8003DE84(0);
    if (func_8003DCD8() & 0x10) {
        if (!(func_8003CEDC(-1) & 0x3F)) {
            func_80042D48("CdRead: Shell open...\n");
        }
        func_8003DFD4(1, 0);
        *(volatile s32 *)D_80051A3C = func_8003CEDC(-1);
        D_80051A3C[-2] = -1; /* D_80051A34, through another name: cross-jumping keeps it apart */
    } else {
        if (arg0 != 0) {
            func_80042D48("CdRead: retry...\n");
            func_8003DE9C(9, NULL, 0);
            if (func_8003DE9C(2, func_8003DD08(), 0) == 0) {
                m = -1;
                p = &D_80051A34;
                *p = m;
                return *p;
            }
        }
        func_8003DD84();
        temp_s0 = *(volatile s32 *)&D_80051A2C;
        sp10 = temp_s0;
        if ((((temp_s0 & 0xFF) != ((s32 (*)(void)) func_8003DCE8)()) || (arg0 != 0)) && (func_8003DE9C(0xE, (s32 *) &sp10, 0) == 0)) {
            D_80051A34 = -1;
        } else {
            *(volatile s32 *)&D_80051A40 = func_8003E3D4(func_8003DD08());
            func_8003DE84((s32) &func_800418D8);
            D_80051A28 = D_80051A24;
            func_8003DFD4(6, 0);
            D_80051A34 = D_80051A20;
            D_80051A38 = func_8003CEDC(-1);
        }
    }
    return D_80051A34;
}

void func_80041CD4(void) {
    *(volatile s32 *) &D_80051A34 = 0;
    func_8003DE6C(D_80051A44);
    func_8003DE84(D_80051A48);
    func_8003DE9C(9, NULL, 0);
}

s32 func_80041D28(s32 arg0, s32 arg1, s32 arg2) {
    *(volatile s32 *) &D_80051A2C = arg2;
    switch (*(volatile s32 *) &D_80051A2C & 0x30) {
    case 0:
        D_80051A30 = 0x200;
        break;
    case 32:
        D_80051A30 = 0x249;
        break;
    default:
        *(volatile s32 *) &D_80051A30 = 0x246;
        break;
    }
    *(volatile s32 *) &D_80051A2C |= 0x20;
    D_80051A24 = arg1;
    D_80051A20 = arg0;
    D_80051A44 = func_8003DE6C(0);
    D_80051A48 = func_8003DE84(0);
    D_80051A3C[0] = func_8003CEDC(-1);
    if (func_8003DCD8() & 0xE0) {
        func_8003E100(9, 0, 0);
    }
    return func_80041AFC(0) > 0;
}

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
