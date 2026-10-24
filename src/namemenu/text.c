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

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D0054);

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

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D0400);

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

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D07D8);

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D099C);

void func_801D1254(void) {
    if (D_801D9048 != 9 && D_801D9048 != 0) {
        func_801D14E8(D_8009C738[D_800491D0[D_801D9048]]);
        D_8009C760[D_801D9048].hp = D_8009C760[D_801D9048].maxhp;
        D_8009C760[D_801D9048].mp = D_8009C760[D_801D9048].maxmp;
    }
    func_80025C54(D_801D9870);
}

INCLUDE_ASM("../asm/us/namemenu/nonmatchings/text", func_801D131C);
