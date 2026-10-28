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
M2C_UNK func_80042DC8();
s32 func_8003FB8C(MainCdlFile *arg0, char *arg1);

char *func_8003DDBC(s32 arg0) {
    u32 i;

    i = arg0 & 0xFF;
    if (i >= 0x1C) {
        return D_80010668;
    }
    return D_8005164C[i];
}

char *func_8003DDF4(s32 arg0) {
    u32 i;

    i = arg0 & 0xFF;
    if (i >= 7) {
        return D_80010668;
    }
    return D_800516CC[i];
}

void func_8003DE2C(void) {
    func_8003E9DC();
}

void func_8003DE4C(void) {
    func_8003EC60();
}

s32 func_8003DE6C(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80051628;
    D_80051628 = arg0;
    return temp_v0;
}

s32 func_8003DE84(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_8005162C;
    D_8005162C = arg0;
    return temp_v0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003DE9C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003DFD4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003E100);

s32 func_8003E244(void) {
    func_8003F398();
    return 1;
}

s32 func_8003E268(void) {
    return func_8003F99C() == 0;
}

void func_8003E28C(s32 arg0) {
    func_8003D120(3, arg0);
}

void func_8003E2B0(void) {
    func_8003F830();
}

s32 func_8003E2D0(s32 arg0, u8 *arg1) {
    s32 i;
    s32 s;
    s32 m;

    i = arg0 + 150;
    arg1[2] = ((i % 75) / 10) * 16 + (i % 75) % 10;
    i = i / 75;
    m = i / 60;
    s = i % 60;
    arg1[1] = (s / 10) * 16 + s % 10;
    arg1[0] = (m / 10) * 16 + m % 10;
    return (s32) arg1;
}

s32 func_8003E3D4(void *arg0) {
    u8 temp_a1;
    u8 temp_a2;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0);
    temp_a2 = M2C_FIELD(arg0, u8 *, 1);
    temp_a1 = M2C_FIELD(arg0, u8 *, 2);
    return (((((((temp_v1 >> 4) * 0xA) + (temp_v1 & 0xF)) * 0x3C) + (((temp_a2 >> 4) * 0xA) + (temp_a2 & 0xF))) * 0x4B) + (((temp_a1 >> 4) * 0xA) + (temp_a1 & 0xF))) - 0x96;
}

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib2", D_80010668);

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib2", D_800107AC);

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib2", D_800107BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003E454);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003E9DC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003EC60);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003EF30);

s32 func_8003F398(arg0) {
    *D_800518EC = 2;
    *D_800518F4 = ((u8 *) arg0)[0];
    *D_800518F8 = ((u8 *) arg0)[1];
    *D_800518EC = 3;
    *D_800518F0 = ((u8 *) arg0)[2];
    *D_800518F4 = ((u8 *) arg0)[3];
    *D_800518F8 = 0x20;
    return 0;
}

s32 func_8003F420(void) {
    u8 c;
    u8 *q;

    *D_800518EC = 1;
    if (*D_800518F8 & 7) {
        c = 7;
        do {
            *D_800518EC = 1;
            *D_800518F8 = c;
            *D_800518F4 = c;
        } while (*D_800518F8 & 7);
    }
    D_80051906 = 0;
    *(volatile u8 *) &D_80051905 = D_80051906;
    do {
        q = D_800518EC;
        D_80051904 = 2;
        *q = 0;
    } while (0);
    *D_800518F8 = 0;
    *D_800518FC = 0x1325;
    return 0x1325;
}

s32 func_8003F500(void) {
    u8 b[4];

    if (D_80051900[0xDC] == 0) {
        if (D_80051900[0xDD] == 0) {
            D_80051900[0xC0] = 0x3FFF;
            D_80051900[0xC1] = 0x3FFF;
        }
    }
    D_80051900[0xD8] = 0x3FFF;
    D_80051900[0xD9] = 0x3FFF;
    D_80051900[0xD5] = 0xC001;
    b[2] = 0x80;
    b[0] = 0x80;
    b[3] = 0;
    b[1] = 0;
    *D_800518EC = 2;
    *D_800518F4 = b[0];
    *D_800518F8 = b[1];
    *D_800518EC = 3;
    *D_800518F0 = b[2];
    *D_800518F4 = b[3];
    *D_800518F8 = 0x20;
    return 0;
}

void func_8003F5F4(void) {
    D_8005162C = 0;
    D_80051628 = 0;
    D_8005163C = 0;
    *(s32 *) &D_80051638 = 0;
    func_8003D0C0();
    func_8003D0F0(2, (s32) &func_8003FAAC);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003F644);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003F830);

s32 func_8003F99C(arg0, arg1) {
    volatile u8 *q;

    *D_800518EC = 0;
    *D_800518F8 = 0x80;
    *D_80051920 = 0x20943;
    *D_800518FC = 0x1323;
    *D_80051924 |= 0x8000;
    *D_80051928 = arg0;
    *D_8005192C = arg1 | 0x10000;
    q = D_800518EC;
    while (!(*q & 0x40)) {
    }
    *D_80051930 = 0x11000000;
    while (*D_80051930 & 0x01000000) {
    }
    *D_800518FC = 0x1325;
    return 0;
}

void func_8003FA9C(s32 arg0) {
    D_800518D0 = arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_8003FAAC);

s32 func_8003FB8C(MainCdlFile *arg0, char *arg1) {
    char buf[0x20];
    char *p;
    char *q;
    s32 dir;
    s32 level;
    MainCdlFile *e;

    if (D_80051938 != D_80051640) {
        if (func_8003FE98() == 0) {
            return 0;
        }
        D_80051938 = D_80051640;
    }
    dir = 1;
    if (arg1[0] != 0x5C) {
        return 0;
    }
    buf[0] = 0;
    p = arg1;
    level = 0;
    while (1) {
        q = buf;
        while (*p != 0x5C) {
            if (*p == 0) {
                break;
            }
            *q++ = *p++;
        }
        if (*p == 0) {
            break;
        }
        p++;
        *q = 0;
        dir = func_8004018C(dir, buf);
        if (dir == -1) {
            buf[0] = 0;
            break;
        }
        level++;
        if (level >= 8) {
            break;
        }
    }
    if (level >= 8) {
        if (D_80051634 > 0) {
            func_80042DC8("%s: path level (%d) error\n", arg1, level);
            return 0;
        }
        return 0;
    }
    if (buf[0] == 0) {
        if (D_80051634 > 0) {
            func_80042DC8("%s: dir was not found\n", arg1);
        }
        return 0;
    }
    *q = 0;
    if (func_80040238(dir) == 0) {
        if (D_80051634 > 0) {
            func_80042DC8("CdSearchFile: disc error\n");
            return 0;
        }
        return 0;
    }
    level = 0;
    if (D_80051634 >= 2) {
        func_80042DC8("CdSearchFile: searching %s...\n", buf);
    }
    for (; level < 0x40; level++) {
        if (D_8006E14C[level].name[0] == 0) {
            break;
        }
        if (func_8003FE74((s32) D_8006E14C[level].name, (s32) buf) != 0) {
            if (D_80051634 >= 2) {
                func_80042DC8("%s:  found\n", buf);
            }
            e = (MainCdlFile *) ((u8 *) &D_8006E14C[level] - 8);
            *arg0 = *e;
            return (s32) e;
        }
    }
    if (D_80051634 > 0) {
        func_80042DC8("%s: not found\n", buf);
    }
    return 0;
}

s32 func_8003FE74(s32 arg0, s32 arg1) {
    return func_80042D78(arg0, arg1, 0xC) == 0;
}

s32 func_8003FE98(void) {
    MainBytes4 loc;
    s32 r;
    u8 *p;
    s32 i;
    s32 n;
    s32 len;
    s32 n2;
    u8 *name;

    r = func_800404F4(1, 0x10, (s32) D_8006FD44);
    if (r != 1) {
        if (D_80051634 > 0) {
            func_80042DC8("CD_newmedia: Read error in cd_read(PVD)\n");
        }
        return 0;
    }
    if (func_80042D78(D_8006FD44 + 1, "CD001", 5) != 0) {
        if (D_80051634 > 0) {
            func_80042DC8("CD_newmedia: Disc format error in cd_read(PVD)\n");
        }
        return 0;
    }
    loc = D_8006FDD0;
    if (func_800404F4(1, *(s32 *) &loc, (s32) D_8006FD44) != 1) {
        if (D_80051634 > 0) {
            func_80042DC8("CD_newmedia: Read error (PT:%08x)\n", *(s32 *) &loc);
        }
        return 0;
    }
    p = D_8006FD44;
    if (D_80051634 >= 2) {
        func_80042DC8("CD_newmedia: sarching dir..\n");
    }
    i = 0;
    while (p < D_8006FD44 + 0x800) {
        if (*p == 0) {
            break;
        }
        *(MainBytes4 *) &D_8006E744[i].loc = *(MainBytes4 *) (p + 2);
        name = D_8006E744[i].name;
        n = i + 1;
        D_8006E744[i].parent = p[6];
        D_8006E744[i].num = n;
        func_80040560(name, p + 8, p[0]);
        name[p[0]] = 0;
        len = p[0];
        n2 = (len & 1) + 8;
        p += len + n2;
        if (D_80051634 >= 2) {
            func_80042DC8("\t%08x,%04x,%04x,%s\n", D_8006E744[i].loc, D_8006E744[i].num, D_8006E744[i].parent, name);
        }
        i = n;
        if (i >= 0x80) {
            break;
        }
    }
    if (i < 0x80) {
        D_8006E744[i].parent = 0;
    }
    D_80051934 = 0;
    if (D_80051634 >= 2) {
        func_80042DC8("CD_newmedia: %d dir entries found\n", i);
    }
    return 1;
}

s32 func_8004018C(s32 arg0, char *arg1) {
    s32 i;

    for (i = 0; i < 0x80; i++) {
        if (D_8006E748[i].id == 0) {
            break;
        }
        if (D_8006E748[i].id == arg0 && func_80042D68(arg1, D_8006E748[i].name) == 0) {
            return i + 1;
        }
    }
    return -1;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib2", func_80040238);
