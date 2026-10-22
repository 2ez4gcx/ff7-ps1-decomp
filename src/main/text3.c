#include "common.h"
#include "main/decls.h"

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80016F90);

s32 func_8001708C(void) {
    s32 sp10;
    s32 ret;

    D_80062E34 = 0;
    D_80062E4C = 0;
    D_80062E48 = 0;
    while (1) {
        D_80062E50 = 0;
        ret = func_80016F90(&sp10);
        if (ret != 0) {
            return ret;
        }
        if (sp10 != 0) {
            break;
        }
    }
    while (D_80062E4C >= 8) {
        D_80062E4C -= 8;
        D_80062E38 -= 1;
    }
    return 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80017108);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80017238);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001726C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80017678);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001786C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80017E68);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80017F38);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80018028);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80018220);

void func_800182FC(s32 arg0, u8 arg1, u8 arg2) {
    s32 i;
    s32 mask;

    i = arg1 * 20;
    mask = (&D_800730D9)[i] + ((&D_800730DA)[i] << 8) + ((&D_800730DB)[i] << 16);
    if (arg2 == 0) {
        *(s32 *) (D_80062E60 + 0x44) |= mask;
    } else {
        *(s32 *) (D_80062E60 + 0x48) |= mask;
    }
}

void func_80018390(s32 arg0, s32 arg1, u32 arg2) {
    s32 id;
    s32 t;
    u32 a2;

    id = arg2 & 0xFF;
    t = *(&D_800730DD + id * 20) & 0xF;
    D_80062E88 = 0;
    a2 = arg2 >> 8;
    switch (t) {
    case 6:
        func_80018630(arg1 & 0xFF, id, a2);
        return;
    case 8:
        func_800185A8(arg1 & 0xFF, 0xFD, a2);
        return;
    }
}

void func_8001840C(s32 arg0, s32 arg1, u32 arg2) {
    s32 idx;
    s32 type;
    s32 hi;

    idx = arg2 & 0xFF;
    type = *(&D_800730DD + idx * 20);
    D_80062E88 = 0;
    hi = arg2 >> 8;
    switch (type & 0xF) {
    case 9:
        func_80018834(arg1, idx, hi);
        break;
    case 10:
        func_800185A8(arg1, 0xFE, hi);
        break;
    case 11:
        func_80018934(arg1, idx, hi);
        break;
    case 12:
        func_800185A8(arg1, 0xFF, hi);
        break;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_800184C0);

void func_800185A8(u8 arg0, u8 arg1, s32 arg2) {
    s32 n;

    if (D_80062E80 != 8) {
        ((Obj *)D_80062E60)->e[D_80062E80].a = D_80062E84 + *(u8 *)&D_80062E88;
        ((Obj *)D_80062E60)->e[D_80062E80].b = arg1;
        n = D_80062E80;
        D_80062E80 = n + 1;
        ((Obj *)D_80062E60)->e[n].c = *((u8 *)&D_80062E50 + 3 + (arg0 & 0xFF));
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80018630);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80018834);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80018934);

void func_80018A04(s32 arg0, u8 arg1, M2C_UNK arg2) {
    s32 i;
    u8 *e;
    u8 *q;
    u8 *p;
    s32 v;
    u8 b;

    i = func_8001AC9C(arg1, arg2);
    if (i > 0) {
        do {
            e = (arg1 * 20 + i) + &D_800730DD;
            q = D_80062E60;
            p = q + *e * 8;
            b = p[0x10F];
            v = (b >> 5) + (arg0 & 0xFF);
            if (v >= 6) {
                v = 5;
            }
            p[0x10F] = (b & 0x1F) | ((v & 7) << 5);
            i--;
        } while (i > 0);
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80018AB0);

void func_80018B14(s32 arg0) {
    s32 i;
    s32 idx;
    s32 v;
    u8 b;

    for (i = 0; i < 0x38; i++) {
        idx = func_8001964C(i);
        if (idx != -1) {
            b = D_80069558[idx].flags;
            v = (b >> 5) + (arg0 & 0xFF);
            if (v >= 6) {
                v = 5;
            }
            D_80069558[idx].flags = (b & 0x1F) | ((v & 7) << 5);
        }
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80018BB8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80018C94);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80018D4C);

void func_80018E18(u8 arg0) {
    s32 i;
    u8 *p;
    u8 *e;
    u8 *q;

    i = func_8001AC9C(arg0);
    if (i > 0) {
        do {
            e = (arg0 * 20 + i) + &D_800730DD;
            q = D_80062E60;
            p = q + *e * 8;
            p[0x10F] |= D_80062E78;
            i--;
        } while (i > 0);
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80018E90);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80018ECC);

void func_80018FC0(void) {
    s32 i;
    s32 idx;

    for (i = 0; i < 16; i++) {
        idx = func_80019608(D_80069508[i].a);
        if (idx != -1) {
            D_80069508[idx].c |= D_80062E78;
        }
    }
}

void func_80019064(void) {
    s32 i;
    s32 idx;

    for (i = 0; i < 0x38; i++) {
        idx = func_8001964C(i);
        if (idx != -1) {
            D_80069558[idx].flags |= D_80062E78;
        }
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_800190E8);

void func_800191A0(s32 arg0, s32 arg1, u32 arg2) {
    u8 id;
    u32 rest;

    id = arg2;
    rest = arg2 >> 8;
    switch (*((id * 20) + &D_800730DD) & 0xF) {
    case 9:
        func_80019254(arg1, id, rest);
        break;
    case 10:
        func_80019338(arg1, id, rest);
        break;
    case 11:
        func_8001937C(arg1 & 0xFF, id);
        break;
    case 12:
        func_800193F4(arg1, id, rest);
        break;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80019254);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80019338);

void func_8001937C(s32 arg0, u8 arg1) {
    s32 idx;

    idx = D_800730DE[arg1 * 0x14] - 0x38;
    D_800694C4[idx]++;
    D_800694D4[idx] += arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_800193F4);

void func_80019440(s32 arg0, s32 arg1, u32 arg2) {
    u8 idx;
    s32 kind;

    idx = arg2;
    kind = (&D_800730DD)[idx * 20] & 0xF;
    arg2 >>= 8;
    switch (kind) {
    case 9:
        func_80019544(arg1, idx, arg2);
        break;
    case 10:
        func_800194BC(arg1, idx, arg2);
        break;
    }
}

void func_800194BC(u8 arg0, u8 arg1, u32 arg2) {
    s32 i;
    s32 r;

    for (i = 0; i < 0x38; i++) {
        r = func_8001964C(i);
        if (r != -1) {
            D_80069554[r].unk1 += arg0;
        }
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80019544);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80019608);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001964C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80019690);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_800197B8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80019978);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80019D1C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80019D74);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80019DA0);

void func_80019E4C(void) {
    if (D_80063020 == 0) {
        M2C_FIELD(D_80062E60, u8 *, 0x23) = (u8) (M2C_FIELD(D_80062E60, u8 *, 0x23) | 4);
        return;
    }
    D_80062FFC = 0x12;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80019E84);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_80019F90);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001A1C8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001A280);

void func_8001A384(s32 arg0) {
    func_8001AC9C(arg0 & 0xFF);
    if (D_80063020 != 0) {
        D_80062FFC = 0xB;
    }
}

void func_8001A3B8(s32 arg0, s32 arg1, s32 arg2) {
    s32 bits;
    s32 i;

    if (D_80063020 == 0) {
        bits = arg2 & 0xFFFFFF;
        i = 0;
        do {
            if (bits & 1) {
                func_8001BD50(i, i + 0x48, i + 0x48);
            }
            bits >>= 1;
            i++;
        } while (i < 0x18);
        func_8001B834(0xD);
        return;
    }
    D_80062FFC = 8;
}

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

void func_8001A518(void) {
    s32 i;
    u8 *p;
    u8 c;

    if (D_80063020 == 0) {
        c = 0xFF;
        i = 15;
        p = &D_800694C3;
        for (; i >= 0; i--) {
            *p-- = c;
        }
        for (i = 0x38; i < 0x48; i++) {
            func_8001BD50(i - 0x38, i, i);
        }
        func_8001B834(3);
        if (D_80062E90 == 0) {
            D_80062E90 = 1;
        }
    } else {
        D_80062FFC = 7;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001A5B4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001A684);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001A780);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001A874);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001A9CC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001AB1C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001AC9C);

void func_8001AE08(void) {
    if (M2C_FIELD(&D_80062E6C, s16 *, 0) >= 0x21) {
        M2C_FIELD(&D_80062E6C, s16 *, 0) = 0x20;
    }
    if (D_80062E70 >= 0x21) {
        D_80062E70 = 0x20;
    }
    if (M2C_FIELD(&D_80062E6C, s16 *, 2) >= 0x100) {
        M2C_FIELD(&D_80062E6C, s16 *, 2) = 0xFF;
    }
    if (D_80062E74 >= 0x100) {
        D_80062E74 = 0xFF;
    }
    M2C_FIELD(D_80062E60, u8 *, 0x43C) = (u8) (M2C_FIELD(D_80062E60, u8 *, 0x43C) + (u8) M2C_FIELD(&D_80062E6C, s16 *, 0));
    M2C_FIELD(D_80062E60, u8 *, 0x43D) = (u8) (M2C_FIELD(D_80062E60, u8 *, 0x43D) + (u8) M2C_FIELD(&D_80062E6C, s16 *, 2));
    M2C_FIELD(D_80062E60, u8 *, 0x437) = (u8) (M2C_FIELD(D_80062E60, u8 *, 0x437) + (u8) D_80062E74);
    M2C_FIELD(D_80062E60, u8 *, 0x43E) = (u8) (M2C_FIELD(D_80062E60, u8 *, 0x43E) + (u8) D_80062E70);
    M2C_FIELD(D_80062E60, u8 *, 0x43F) = (u8) (M2C_FIELD(D_80062E60, u8 *, 0x43F) + D_80062E72);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001AEE4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001B4A0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001B570);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001B5E4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001B704);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001B834);

void func_8001B8A8(void) {
    s32 i;
    s32 found;

    found = 0;
    for (i = 0; i < 16; i++) {
        if (D_80069508[i].a == 0x11) {
            found = 1;
            break;
        }
    }
    for (i = 0; i < 16; i++) {
        if (found == 1) {
            if (D_80069508[i].a == 5) {
                D_80069508[i].a = 0xFF;
            }
        }
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001B944);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001BA54);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001BB30);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001BC18);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001BCE8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text3", func_8001BD50);
