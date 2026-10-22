#include "common.h"
#include "main/decls.h"

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80013C9C);

void func_800140A4(void) {
    s32 temp_v0;

    temp_v0 = D_8019DAA0 + 1;
    D_8019DAA0 = temp_v0;
    if (!(temp_v0 & 1)) {
        func_8004433C(D_8019D5E8);
        func_80013C9C();
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_800140F4);

s32 func_800144D8(s32 i) {
    return D_80048D84[i].first;
}

void func_800144F0(s32 a) {
    func_80033DAC(a, 0);
}

void func_80014510(s32 i) {
    func_800144F0(D_80048D84[i].first);
}

void func_80014540(void) {
    func_80033E34(D_80071744, D_80095DD8, D_800722C8, 0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014578);

void func_800145BC(M2C_UNK (*arg0)()) {
loop_1:
    if (func_80034B44() != 0) {
        if (arg0 != NULL) {
            arg0();
        }
        goto loop_1;
    }
}

void func_80014608(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014610);

void func_80014658(s32 arg0, M2C_UNK (*arg1)()) {
    func_80014578(arg0, 0x801B0000, 0);
    func_800145BC(NULL);
    func_80015CA0(0x801B0000, 0x800A0000);
    arg1();
}

void func_800146A4(s32 arg0) {
    s32 loop;

    loop = -1;
    do {
        switch (D_8009C560) {
        case 4:
            func_800145BC(NULL);
            func_80014658(3, D_800A00CC);
            break;
        case 2:
            func_800140F4();
            func_80014658(5, D_800A1158);
            break;
        default:
            loop = 0;
            break;
        }
    } while (loop != 0);
}

void func_80014750(void) {
    s32 end;
    s32 op;
    s32 arg;

    func_80015B44(0x801B0000);
    end = 0xFFFF;
    while ((op = func_80015B50() & 0xFFFF) != end) {
        arg = func_80015B88() & 0xFFFF;
        if (op == 9) {
            func_80015BC0(func_80014C80(arg));
        } else if (D_80048DD4[op] != 0) {
            func_80015BC0(D_80048DD4[op]);
        }
    }
}

void func_80014804(void) {
    s32 op;

    func_80015B44(0x801B0000);
    while ((op = func_80015B50() & 0xFFFF) != 0xFFFF) {
        switch (op) {
        case 0:
            func_80015BC0(0x801C0000);
            func_800149E0();
            func_80014980((void *)0x801C0000);
            break;
        case 1:
            func_80015BC0((s32)D_80063048);
            break;
        }
    }
}

void func_800148A0(void) {
    D_80062F88 = 0;
    D_800707BE[0] = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_800148B4);

void func_80014934(void) {
    func_800148A0();
    func_80014578(2, 0x801B0000, 0);
    func_800145BC(NULL);
    func_80015C3C(0x801B0000, &D_8009C738, 3);
}

void func_80014980(void *arg0) {
    void *var_s0;

    var_s0 = arg0;
    if (M2C_FIELD(var_s0, s32 *, 4) & 8) {
        func_80044000(var_s0 + 0xC, var_s0 + 0x14);
        var_s0 += ((u32) M2C_FIELD(var_s0, u32 *, 8) >> 2) * 4;
    }
    func_80044000(var_s0 + 0xC, var_s0 + 0x14);
}

void func_800149E0(void) {
    func_80043DD8(0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014A00);

/* The number of the highest set bit of x (0 for 0 and 1). */
s32 func_80014A38(u32 x) {
    s32 n = 0;
    while (1) {
        x >>= 1;
        if (x == 0) {
            break;
        }
        n++;
    }
    return n;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014A58);

s32 func_80014A84(s32 mask) {
    s32 n;
    s32 bit;

    bit = 0;
    n = func_80014A58(mask);
    if (n != 0) {
        bit = 1;
        n = (func_80014B70() * n) >> 8;
        for (; bit != 0; bit <<= 1) {
            if (mask & bit) {
                if (--n < 0) {
                    break;
                }
            }
        }
    }
    return bit;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014B08);

void func_80014B54(void) {
    D_80062E18 = (D_80062E18 + 1) & 7;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014B70);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014BA8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014BE4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014C44);

void func_80014C70(void) {
    D_80062E1C = 0;
    D_80062E20 = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014C80);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014CBC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014D58);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014D9C);

void func_80014DD0(s32 arg0, s32 arg1, M2C_UNK arg2) {
    func_80014D58(arg2, func_80014D9C(arg0, arg1, 0), -1);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014E0C);

INCLUDE_RODATA("../asm/us/main/nonmatchings/text2", D_80010118);

INCLUDE_RODATA("../asm/us/main/nonmatchings/text2", D_80010120);

INCLUDE_RODATA("../asm/us/main/nonmatchings/text2", D_80010124);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80014E74);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_800150E4);

s32 func_800151F4(s32 arg0) {
    return func_80014D9C(0x10, arg0, 0);
}

void func_8001521C(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_800151F4(arg0);
    func_800150E4(temp_v0, temp_v0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80015248);

void func_800155A4(s32 arg0) {
    D_80062F14 = arg0;
}

void func_800155B0(void) {
    if (D_80062F14 >= 0 && !(D_800F83C6[0] & 8)) {
        D_80062F14 |= 0x100;
        D_80062F60 = 0;
        while (D_80062D88 != 0x10C) {
            func_800A3278();
            func_800B6D6C();
        }
        D_800F83C6[0] |= 8;
    }
}

void func_80015654(s32 a) {
    D_80062E24 = 0;
    D_80062E28 = 0;
    D_80062E2C = a;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80015668);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_800159B0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80015AFC);

void func_80015B44(s32 arg0) {
    D_80062E30 = arg0;
}

s32 func_80015B50(void) {
    s32 var_a1;

    var_a1 = 0xFFFF;
    if ((M2C_FIELD(D_80062E30, u8 *, 0) | (M2C_FIELD(D_80062E30, u8 *, 1) << 8)) != 0) {
        var_a1 = M2C_FIELD(D_80062E30, u8 *, 4) | (M2C_FIELD(D_80062E30, u8 *, 5) << 8);
    }
    return var_a1;
}

s32 func_80015B88(void) {
    s32 var_a1;

    var_a1 = 0;
    if ((M2C_FIELD(D_80062E30, u8 *, 0) | (M2C_FIELD(D_80062E30, u8 *, 1) << 8)) != 0) {
        var_a1 = M2C_FIELD(D_80062E30, u8 *, 2) | (M2C_FIELD(D_80062E30, u8 *, 3) << 8);
    }
    return var_a1;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80015BC0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80015C3C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80015CA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80015D14);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80015D64);

s32 func_80016320(void *arg0) {
    void *var_a0;

    var_a0 = arg0;
    if (var_a0 != NULL) {
        do {
            var_a0 = M2C_FIELD(var_a0, void **, -4);
        } while (var_a0 != NULL);
    }
    return 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80016340);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_800166C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_80016808);

INCLUDE_ASM("../asm/us/main/nonmatchings/text2", func_800169B8);
