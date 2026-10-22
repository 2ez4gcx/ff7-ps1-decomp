#include "common.h"
#include "main/decls.h"

void func_800110B8(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", main_entry);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001117C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800111E4);

void func_80011274(void) {
    func_80033E34(D_80048D1C, D_80048D20, 0x800E0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80033E34(D_80048D14, D_80048D18, 0x800A0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80029818(0x800A0000, 0x800E0000);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800112E8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001146C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001155C);

void func_8001171C(void) {
    func_8003D1B4();
    func_8003D0C0();
    func_80043938(0);
    func_80036298();
    D_80095DD4 = 0;
    func_8003D150((s32) &func_8001155C);
    func_80043BA8(0);
    func_80043D3C(0);
    func_80039EDC();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80011784);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80011860);

void func_80011920(void) {
    D_800965E8 = 0;
    D_80071A5C = 0;
}

void func_80011938(void) {
    func_80033E34(D_80048CFC, D_80048D00, 0x800F0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80033E34(D_80048D04, D_80048D08, 0x801B0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80033E34(D_80048D0C, D_80048D10, 0x801BC800, 0);
    do {

    } while (func_80034B44() != 0);
    func_8002988C(0x800F0000, 0x801BC800);
    func_80029998(0x801B0000);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800119E4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80011AEC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80011BB4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80011C1C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80012840);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800128B8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800129D0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80012A8C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80012DB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800131B8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800134F4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80013564);

s16 func_800135C0(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    return (s16) (arg0 + ((s32) ((s16) (arg1 - arg0) * arg2) / arg3));
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80013624);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80013800);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800138EC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80013C9C);

void func_800140A4(void) {
    s32 temp_v0;

    temp_v0 = D_8019DAA0 + 1;
    D_8019DAA0 = temp_v0;
    if (!(temp_v0 & 1)) {
        func_8004433C(D_8019D5E8);
        func_80013C9C();
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800140F4);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014578);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014610);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014658);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800146A4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014750);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014804);

void func_800148A0(void) {
    D_80062F88 = 0;
    D_800707BE[0] = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800148B4);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014A00);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014A58);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014A84);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014B08);

void func_80014B54(void) {
    D_80062E18 = (D_80062E18 + 1) & 7;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014B70);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014BA8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014BE4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014C44);

void func_80014C70(void) {
    D_80062E1C = 0;
    D_80062E20 = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014C80);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014CBC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014D58);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014D9C);

void func_80014DD0(s32 arg0, s32 arg1, M2C_UNK arg2) {
    func_80014D58(arg2, func_80014D9C(arg0, arg1, 0), -1);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014E0C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80014E74);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800150E4);

s32 func_800151F4(s32 arg0) {
    return func_80014D9C(0x10, arg0, 0);
}

void func_8001521C(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_800151F4(arg0);
    func_800150E4(temp_v0, temp_v0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80015248);

void func_800155A4(s32 arg0) {
    D_80062F14 = arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800155B0);

void func_80015654(s32 a) {
    D_80062E24 = 0;
    D_80062E28 = 0;
    D_80062E2C = a;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80015668);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800159B0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80015AFC);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80015BC0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80015C3C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80015CA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80015D14);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80015D64);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80016340);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800166C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80016808);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800169B8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80016F90);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001708C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80017108);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80017238);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001726C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80017678);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001786C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80017E68);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80017F38);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018028);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018220);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800182FC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018390);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001840C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800184C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800185A8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018630);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018834);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018934);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018A04);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018AB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018B14);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018BB8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018C94);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018D4C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018E18);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018E90);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018ECC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80018FC0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80019064);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800190E8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800191A0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80019254);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80019338);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001937C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800193F4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80019440);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800194BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80019544);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80019608);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001964C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80019690);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800197B8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80019978);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80019D1C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80019D74);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80019DA0);

void func_80019E4C(void) {
    if (D_80063020 == 0) {
        M2C_FIELD(D_80062E60, u8 *, 0x23) = (u8) (M2C_FIELD(D_80062E60, u8 *, 0x23) | 4);
        return;
    }
    D_80062FFC = 0x12;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80019E84);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80019F90);

void func_8001A174(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFF;
    switch (temp_a0) {
    case 2:
        func_8001A280(arg1 & 0xFF, arg2);
        return;
    case 3:
        func_8001A1C8(arg1 & 0xFF, arg2);
        return;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001A1C8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001A280);

void func_8001A384(s32 arg0) {
    func_8001AC9C(arg0 & 0xFF);
    if (D_80063020 != 0) {
        D_80062FFC = 0xB;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001A3B8);

void func_8001A440(void) {
    if (D_80063020 == 0) {
        func_8001B834(5);
        func_8001B834(6);
        func_8001B834(7);
        func_8001B834(9);
        func_8001B834(0xA);
        func_8001B834(0xB);
        func_8001B834(0xC);
        return;
    }
    D_80062FFC = 5;
}

void func_8001A4A8(void) {
    s32 var_s0;

    if (D_80063020 == 0) {
        var_s0 = 0;
        do {
            func_8001BCE8(var_s0 & 0xFF);
            var_s0 += 1;
        } while (var_s0 < 0x38);
        func_8001B834(2);
        if (D_80062E8C == 0) {
            D_80062E8C = 1;
        }
    } else {
        D_80062FFC = 6;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001A518);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001A5B4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001A684);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001A780);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001A874);

void func_8001A980(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFF;
    switch (temp_a0) {
    case 4:
        func_8001AB1C(arg1 & 0xFF, arg2);
        return;
    case 2:
        func_8001A9CC(arg1 & 0xFF, arg2);
        return;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001A9CC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001AB1C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001AC9C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001AE08);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001AEE4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001B4A0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001B570);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001B5E4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001B704);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001B834);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001B8A8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001B944);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001BA54);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001BB30);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001BC18);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001BCE8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001BD50);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001BDB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001C0EC);

void func_8001C3C4(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001C3CC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001C434);

void func_8001C484(s32 arg0) {
    D_80062E9C = arg0;
    D_80062E94 = 0x14;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001C498);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001C4E8);

void func_8001C58C(void) {
    if (!(func_8001F6B4() & 0xFF)) {
        D_80062D71 = 0;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001C5BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001C788);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001C808);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001C8D4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001C980);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001CB48);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001CDA4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001CF3C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001D180);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001D3C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001D47C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001D56C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001D6A8);

void func_8001DE0C(void *arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    M2C_FIELD(arg0, s16 *, 0) = arg1;
    M2C_FIELD(arg0, s16 *, 2) = arg2;
    M2C_FIELD(arg0, s16 *, 4) = arg3;
    M2C_FIELD(arg0, s16 *, 6) = (s16) arg4;
}

void func_8001DE24(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, u16 *, 0) = (u16) (M2C_FIELD(arg0, u16 *, 0) + arg1);
    M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + arg2);
}

void func_8001DE40(void *arg0, void *arg1) {
    M2C_FIELD(arg0, u16 *, 0) = (u16) M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg1, u16 *, 2);
    M2C_FIELD(arg0, u16 *, 4) = (u16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg1, u16 *, 6);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001DE70);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001DEB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001DEF0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001DF24);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001E040);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001EB2C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001EC70);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001EF84);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001F1BC);

void func_8001F6AC(void) {
}

u8 func_8001F6B4(void) {
    return D_80062DDB;
}

void func_8001F6C0(s32 arg0, s8 arg1) {
    D_80062DDB = 1;
    D_80062DDC = arg1;
    D_80062DE0 = 0x28;
    D_80062EB8 = arg0;
    D_80062DE5 = 1;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001F6E4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001F710);

s32 func_8001FA28(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    return func_8002DA7C(temp_a0);
}

void func_8001FA68(s32 arg0) {
    s32 temp_a0;

    D_8009A000 = 0x28;
    temp_a0 = arg0 & 0xFFFF;
    D_8009A004 = 0x40;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_8001FAAC(s32 arg0) {
    s32 temp_a0;

    D_8009A000 = 0x29;
    temp_a0 = arg0 & 0xFFFF;
    D_8009A004 = 0x40;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_8001FAF0(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001FAF8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001FBAC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001FCDC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001FE6C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001FF50);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001FF8C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001FFD4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8002001C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80020058);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800206E4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80020B68);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80021044);

void func_800211B8(s32 arg0) {
    D_80062DEC = arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800211C4);

void func_8002120C(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80062DD4;
    D_80062DD4 = arg0;
    D_80062DD0 = temp_v0;
    if ((arg0 != 0) && (((u32) (temp_v0 - 3) >= 2U) || ((u32) (arg0 - 3) >= 2U))) {
        func_800211C4(arg0);
    }
}

void func_80021258(s32 arg0) {
    func_80015248(0xD, arg0, 8);
}

void func_80021280(s32 arg0) {
    func_80015248(4, arg0, 8);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800212A8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80021BAC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80021C4C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80021D5C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80021E70);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80021F58);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80022B5C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80022DE4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80022FE0);

s32 func_80023050(void) {
    return D_80062DF8;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8002305C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800230C4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8002368C);

s32 func_80023788(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0;
    if (var_a0 > 0x57E3F) {
        var_a0 = 0x57E3F;
    }
    return ((var_a0 / (s32) D_80049474) * 0xA) + ((s32) (var_a0 % (s32) D_80049474) / (s32) D_80049478);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8002382C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80023940);

void func_80023AC4(void) {
    D_80062FC0 = 2;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80023AD4);

void func_80024A04(void) {
    func_800444AC(&D_8007075C);
    func_800443B0(&D_80070700);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80024A3C);

void func_80024D88(s32 arg0) {
    func_800211C4(0xD);
    do {

    } while (func_80034B44() != 0);
    func_8003CEDC(0x1E);
    func_801D131C(arg0);
}

void func_80024DD4(s32 arg0) {
    func_800211C4(0xE);
    do {

    } while (func_80034B44() != 0);
    func_801D1A6C(arg0);
}

void func_80024E18(s32 arg0) {
    func_800211C4(0xF);
    do {

    } while (func_80034B44() != 0);
    func_801D4118(arg0);
}

void func_80024E5C(void) {
    func_800211C4(0x10);
    do {

    } while (func_80034B44() != 0);
    func_801D4CC0();
}

void func_80024E94(void) {
    func_800211C4(0xA);
    do {

    } while (func_80034B44() != 0);
    func_801D1774();
}

void func_80024ECC(void) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D2D74();
}

void func_80024F04(void) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D2E84();
}

void func_80024F3C(s32 arg0) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D2F00(arg0);
}

void func_80024F80(s32 arg0) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D3138(arg0);
}

void func_80024FC4(s32 arg0) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D3018(arg0);
}

void func_80025008(void) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D3228();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025040);

void func_800250B4(void) {
    func_800211C4(0xC);
    do {

    } while (func_80034B44() != 0);
    func_801D027C();
}

void func_800250EC(s32 arg0) {
    func_800211C4(0xC);
    do {

    } while (func_80034B44() != 0);
    func_801D05C4(arg0);
}

void func_80025130(s32 arg0) {
    func_800211C4(0xC);
    do {

    } while (func_80034B44() != 0);
    func_801D0704(arg0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025174);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025288);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025310);

void func_80025360(void) {
    func_8001FA28(0x19F);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025380);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8002542C);

void func_800254D8(void) {
    D_80062EBC = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800254E4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025514);

void func_80025648(void) {
}

void func_80025650(void) {
}

u8 func_80025658(void) {
    return D_8009C739;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025668);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800256DC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025758);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025774);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025788);

void func_800257C4(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800257CC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025800);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800258BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025988);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025A44);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025B10);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025B48);

s32 func_80025B7C(void) {
    return D_8009D260;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025B8C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025BD0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025C14);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025C54);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025C94);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025CD4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025D14);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025DF8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80025ED4);

void func_80026034(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8002603C);

void func_80026090(void) {
    do {

    } while (func_80034B44() != 0);
    func_800211C4(7);
    do {

    } while (func_80034B44() != 0);
    func_801D11A8();
    D_80062F90 = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800260DC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80026258);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800262D8);

void func_80026408(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_80026448(void *arg0, s8 arg1, s8 arg2, s8 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, u16 arg13) {
    M2C_FIELD(arg0, s8 *, 0xA) = arg1;
    M2C_FIELD(arg0, s8 *, 0xB) = arg2;
    M2C_FIELD(arg0, s8 *, 0xC) = arg3;
    M2C_FIELD(arg0, s8 *, 0xD) = (s8) arg4;
    M2C_FIELD(arg0, s16 *, 0) = (s16) arg5;
    M2C_FIELD(arg0, s16 *, 2) = (s16) arg6;
    M2C_FIELD(arg0, s16 *, 4) = (s16) arg7;
    M2C_FIELD(arg0, s16 *, 6) = (s16) arg8;
    M2C_FIELD(arg0, s8 *, 0xE) = (s8) arg9;
    M2C_FIELD(arg0, s8 *, 0xF) = (s8) arg10;
    M2C_FIELD(arg0, s8 *, 0x10) = (s8) arg11;
    M2C_FIELD(arg0, s8 *, 0x11) = (s8) arg12;
    M2C_FIELD(arg0, u16 *, 8) = arg13;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800264A8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800269C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800269D0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800269E8);

void func_80026A00(s32 arg0) {
    D_80062FC4 = arg0;
}

void func_80026A0C(void) {
    D_8006300C = D_80062FC4;
}

void func_80026A20(void) {
    D_80062FC4 = D_8006300C;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80026A34);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80026A94);

void func_80026B5C(void) {
}

void func_80026B64(s8 arg0) {
    D_80062DFC = arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80026B70);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80026C5C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80026F44);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8002708C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80027354);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80027408);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80027990);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80027B84);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80028030);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80028484);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800285AC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80028930);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80028CA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80028E00);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80029114);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800294A4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800294BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800297A4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80029818);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8002988C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80029998);

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
