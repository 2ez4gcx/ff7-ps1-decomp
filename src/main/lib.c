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

void func_80036298(void) {
    func_800362B8(0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800362B8);

void func_800363B0(void) {
    s32 temp_v0;

    if (D_8004AAF0 == 0) {
        D_8004AAF0 = 1;
        func_80042AF0();
        func_80036FD8((s32) &func_8003688C);
        temp_v0 = func_80042A00(0xF0000009, 0x20, 0x2000, 0);
        D_8004A688 = temp_v0;
        func_80042A40(temp_v0);
        func_80042B00();
    }
}

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib", D_800104B4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003642C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800366C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003688C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003695C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80036A18);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80036CA8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80036D30);

void func_80036D98(s32 arg0, u32 arg1, s32 arg2) {
    if (arg2 == 0) {
        D_8004AAF4[arg0] = arg1;
    } else {
        D_8004AAF4[arg0] = arg1 >> D_8004AB1C;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80036DE0);

s32 func_80036E84(s32 arg0, s32 arg1) {
    u16 t;

    t = D_8004AAF4[arg0];
    if (arg1 == -1) {
        return t;
    }
    return t << D_8004AB1C;
}

void func_80036EC0(s32 arg0) {
    *D_8004AB04 &= 0xFFF8FFFF;
    if (arg0 != 0) {
        *D_8004AB04 |= 0x30000;
    } else {
        *D_8004AB04 |= 0x50000;
    }
}

void func_80036F20(void) {
    *D_8004AB08 = (*D_8004AB08 & 0xF0FFFFFF) | 0x20000000;
}

void func_80036F4C(void) {
    *D_8004AB08 = (*D_8004AB08 & 0xF0FFFFFF) | 0x22000000;
}

void func_80036F78(void) {
    volatile s32 i;
    volatile s32 a;

    a = 0xD;
    for (i = 0; i < 0xF0; i++) {
        a *= 3;
    }
}

void func_80036FD8(s32 arg0) {
    func_8003D120(4, arg0);
}

s32 func_80036FFC(s32 arg0, MainWords *arg1) {
    if (arg0 > 0) {
        arg1->w0 = 0x40001010;
        D_8004AB58 = arg1;
        D_8004AB54 = 0;
        D_8004AB50 = arg0;
        arg1->w4 = (0x10000 << D_8004AB1C) - 0x1010;
        return arg0;
    }
    return 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80037050);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800373AC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80037664);

void func_80037964(s32 arg0, s32 arg1) {
    func_80037988(arg0, arg1, 0xCA, 0xCB);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80037988);

s32 func_80037B90(s32 arg0) {
    s32 v;

    if (arg0 < 0) {
        v = 0;
    } else {
        v = arg0;
        if (v >= 0x40) {
            v = 0x3F;
        }
    }
    D_8004AAF4[0xD5] = (D_8004AAF4[0xD5] & 0xC0FF) | ((v & 0x3F) << 8);
    return v;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80037BE0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80037C40);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80037D10);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80037D90);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80037E1C);

void func_8003832C(void *arg0) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0);
    temp_a2 = temp_a1 == 0;
    if ((temp_a2 != 0) || (temp_a1 & 1)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1C0) = (u16) M2C_FIELD(arg0, u16 *, 4);
    }
    if ((temp_a2 != 0) || (temp_a1 & 2)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1C2) = (u16) M2C_FIELD(arg0, u16 *, 6);
    }
    if ((temp_a2 != 0) || (temp_a1 & 4)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1C4) = (u16) M2C_FIELD(arg0, u16 *, 8);
    }
    if ((temp_a2 != 0) || (temp_a1 & 8)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1C6) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x10)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1C8) = (u16) M2C_FIELD(arg0, u16 *, 0xC);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x20)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1CA) = (u16) M2C_FIELD(arg0, u16 *, 0xE);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x40)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1CC) = (u16) M2C_FIELD(arg0, u16 *, 0x10);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x80)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1CE) = (u16) M2C_FIELD(arg0, u16 *, 0x12);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x100)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1D0) = (u16) M2C_FIELD(arg0, u16 *, 0x14);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x200)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1D2) = (u16) M2C_FIELD(arg0, u16 *, 0x16);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x400)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1D4) = (u16) M2C_FIELD(arg0, u16 *, 0x18);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x800)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1D6) = (u16) M2C_FIELD(arg0, u16 *, 0x1A);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x1000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1D8) = (u16) M2C_FIELD(arg0, u16 *, 0x1C);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x2000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1DA) = (u16) M2C_FIELD(arg0, u16 *, 0x1E);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x4000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1DC) = (u16) M2C_FIELD(arg0, u16 *, 0x20);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x8000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1DE) = (u16) M2C_FIELD(arg0, u16 *, 0x22);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x10000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1E0) = (u16) M2C_FIELD(arg0, u16 *, 0x24);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x20000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1E2) = (u16) M2C_FIELD(arg0, u16 *, 0x26);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x40000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1E4) = (u16) M2C_FIELD(arg0, u16 *, 0x28);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x80000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1E6) = (u16) M2C_FIELD(arg0, u16 *, 0x2A);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x100000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1E8) = (u16) M2C_FIELD(arg0, u16 *, 0x2C);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x200000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1EA) = (u16) M2C_FIELD(arg0, u16 *, 0x2E);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x400000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1EC) = (u16) M2C_FIELD(arg0, u16 *, 0x30);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x800000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1EE) = (u16) M2C_FIELD(arg0, u16 *, 0x32);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x01000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1F0) = (u16) M2C_FIELD(arg0, u16 *, 0x34);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x02000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1F2) = (u16) M2C_FIELD(arg0, u16 *, 0x36);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x04000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1F4) = (u16) M2C_FIELD(arg0, u16 *, 0x38);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x08000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1F6) = (u16) M2C_FIELD(arg0, u16 *, 0x3A);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x10000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1F8) = (u16) M2C_FIELD(arg0, u16 *, 0x3C);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x20000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1FA) = (u16) M2C_FIELD(arg0, u16 *, 0x3E);
    }
    if ((temp_a2 != 0) || (temp_a1 & 0x40000000)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1FC) = (u16) M2C_FIELD(arg0, u16 *, 0x40);
    }
    if ((temp_a2 != 0) || (temp_a1 < 0)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x1FE) = (u16) M2C_FIELD(arg0, u16 *, 0x42);
    }
}

void func_800387FC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) D_8004A6A4;
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) D_8004A6AC;
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) D_8004A6B0;
    M2C_FIELD(arg0, u16 *, 8) = (u16) D_8004A6A8;
    M2C_FIELD(arg0, u16 *, 0xA) = (u16) D_8004A6AA;
}

s32 func_8003884C(void *arg0) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0);
    temp_a2 = temp_a1 == 0;
    if ((temp_a2 != 0) || (temp_a1 & 2)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x184) = (u16) M2C_FIELD(arg0, u16 *, 8);
        D_8004A6A8 = M2C_FIELD(arg0, u16 *, 8);
    }
    if ((temp_a2 != 0) || (temp_a1 & 4)) {
        M2C_FIELD(D_8004AAF4, u16 *, 0x186) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
        D_8004A6AA = M2C_FIELD(arg0, u16 *, 0xA);
    }
    return 0;
}

void func_800388C4(s32 arg0, s32 arg1) {
    func_80037988(arg0, arg1, 0xCC, 0xCD);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800388E8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80038A84);

s32 func_80038BC4(u32 arg0) {
    s32 r;

    if (arg0 <= 0x7FFF8) {
        r = func_80036DE0(0xD2, arg0);
    } else {
        r = 0;
    }
    return r;
}

s32 func_80038C04(s32 arg0) {
    s32 temp_s0;

    temp_s0 = D_8004AB30;
    if (arg0 != temp_s0) {
        D_8004AB30 = arg0;
        func_80038C48(arg0);
    }
    return temp_s0;
}

void func_80038C48(s32 arg0) {
    func_8003D0F0(9, arg0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80038C6C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80038E70);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80038F04);

u16 func_80038F64(u32 arg0) {
    u16 r;

    if (arg0 - 0x1010 <= 0x7EFE8) {
        D_8004AB0C = func_80036DE0(-1, arg0);
        r = D_8004AB0C;
    } else {
        r = 0;
    }
    return r;
}

void func_80038FB8(s32 arg0) {
    s32 v;

    switch (arg0) {
    case 0:
        v = 0;
        break;
    case 1:
        v = 1;
        break;
    default:
        v = 0;
        break;
    }
    D_8004A690 = arg0;
    D_8004AB10 = v;
}

void func_80038FEC(s32 arg0) {
    if (arg0 != D_8004AB2C) {
        D_8004AB2C = arg0;
    }
}

void func_80039010(s32 arg0, s32 arg1) {
    func_80037988(arg0, arg1, 0xC8, 0xC9);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039034);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800393C8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039450);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800395C8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039644);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800396C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003973C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800397C8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039850);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800398EC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800399D0);

s32 func_80039A74(s32 arg0) {
    s32 r;

    if (arg0 >= 0) {
        r = func_80039AB0(arg0 & 0xFFF);
    } else {
        r = -func_80039AB0(-arg0 & 0xFFF);
    }
    return r;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039AB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039B40);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039BE0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039CEC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039E40);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039EDC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039F5C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80039FEC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A078);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A0E8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A1A4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A28C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A30C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A35C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A3AC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A434);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A4BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A51C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A59C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A63C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A79C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A8A8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003A98C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AA74);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AB84);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003ACE4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AD14);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AE38);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AED8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AF78);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003AFC0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B008);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B05C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B16C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B27C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B2CC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B32C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B35C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B48C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B4BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B4EC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B51C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B53C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B54C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B55C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B56C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B58C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B5A0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B5B4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B5C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B5D4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B5EC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B600);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B614);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B628);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B634);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B640);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B64C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B66C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B67C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B69C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B6BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B6DC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B6EC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B710);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B72C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B748);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B784);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B7A8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B7F0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B810);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B854);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B87C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B8A0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B8B0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B8CC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B8F4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B91C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B958);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B97C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B9A4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B9CC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003B9EC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BA10);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BA68);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BAC0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BADC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BB0C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BB44);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BB7C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BBAC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BBDC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BC0C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BC6C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BC9C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BD1C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BD7C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BDFC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BE8C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BF3C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003BF8C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003C21C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003C4AC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003C73C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003C8DC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003CA7C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003CC1C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003CD9C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003CE0C);

s32 func_8003CE8C(void) {
    func_80042AA0();
    return ~D_8006E11C;
}

void func_8003CEBC(void) {
    func_80042A80();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003CEDC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003D024);

void func_8003D0C0(void) {
    M2C_FIELD(D_80051534, M2C_UNK (**)(), 0xC)();
}

s32 func_8003D0F0(s32 arg0, s32 arg1) {
    return M2C_FIELD(D_80051534, s32 (**)(), 8)();
}

s32 func_8003D120(s32 arg0, s32 arg1) {
    return M2C_FIELD(D_80051534, s32 (**)(), 4)();
}

void func_8003D150(s32 arg0) {
    M2C_FIELD(D_80051534, M2C_UNK (**)(M2C_UNK, s32), 0x14)(0, arg0);
}

void func_8003D184(void) {
    M2C_FIELD(D_80051534, M2C_UNK (**)(), 0x14)();
}

void func_8003D1B4(void) {
    M2C_FIELD(D_80051534, M2C_UNK (**)(), 0x10)();
}

void func_8003D1E4(void) {
    M2C_FIELD(D_80051534, M2C_UNK (**)(), 0x18)();
}

u16 func_8003D214(void) {
    return D_800504AE;
}

u16 func_8003D224(void) {
    return *D_8005153C;
}

u16 func_8003D23C(u16 arg0) {
    u16 temp_v0;

    temp_v0 = *D_8005153C;
    *D_8005153C = arg0;
    return temp_v0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003D258);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003D334);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003D51C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003D670);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003D71C);

void func_8003D7A4(s32 *arg0, s32 arg1) {
    s32 i;
    s32 pad;

    for (i = arg1 - 1; i != -1; i--) {
        *arg0++ = 0;
    }
}

M2C_UNK *func_8003D7D0(void) {
    *D_8005156C = 0x107;
    D_80051568 = 0;
    func_8003D8CC(&D_80051548, 8);
    func_8003D0F0(0, (s32) &func_8003D828);
    return &func_8003D8A0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003D828);

void func_8003D8A0(s32 arg0, s32 arg1) {
    if (arg1 != D_80051548[arg0]) {
        D_80051548[arg0] = arg1;
    }
}

void func_8003D8CC(s32 *arg0, s32 arg1) {
    s32 i;
    s32 pad;

    for (i = arg1 - 1; i != -1; i--) {
        *arg0++ = 0;
    }
}

M2C_UNK *func_8003D8F8(void) {
    func_8003DB74(&D_80051574, 8);
    *D_80051570 = 0;
    func_8003D0F0(3, (s32) &func_8003D948);
    return &func_8003DACC;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003D948);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003DACC);

void func_8003DB74(s32 *arg0, s32 arg1) {
    s32 i;
    s32 pad;

    for (i = arg1 - 1; i != -1; i--) {
        *arg0++ = 0;
    }
}

void func_8003DBA0(s32 arg0, s32 arg1) {
    D_8009C6D4 = arg0;
    D_8009FE90 = arg1;
    func_80040898();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003DBD0);

void func_8003DC60(void) {
    func_800429F0(0xF0000003, 0x20);
}

void func_8003DC88(void) {
    func_800429F0(-0x0FFFFFFD, 0x40);
}

void func_8003DCB0(void) {
    func_800429F0(-0x0FFFFFFD, 0x40);
}

u8 func_8003DCD8(void) {
    return D_80051638;
}

u8 func_8003DCE8(void) {
    return D_80051648;
}

u8 func_8003DCF8(void) {
    return D_80051649;
}

M2C_UNK *func_8003DD08(void) {
    return &D_80051644;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003DD18);

void func_8003DD84(void) {
    func_8003F420();
}

s32 func_8003DDA4(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80051634;
    D_80051634 = arg0;
    return temp_v0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003DDBC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003DDF4);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003DE9C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003DFD4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003E100);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003E2D0);

s32 func_8003E3D4(void *arg0) {
    u8 temp_a1;
    u8 temp_a2;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0);
    temp_a2 = M2C_FIELD(arg0, u8 *, 1);
    temp_a1 = M2C_FIELD(arg0, u8 *, 2);
    return (((((((temp_v1 >> 4) * 0xA) + (temp_v1 & 0xF)) * 0x3C) + (((temp_a2 >> 4) * 0xA) + (temp_a2 & 0xF))) * 0x4B) + (((temp_a1 >> 4) * 0xA) + (temp_a1 & 0xF))) - 0x96;
}

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib", D_80010668);
INCLUDE_RODATA("../asm/us/main/nonmatchings/lib", D_800107AC);
INCLUDE_RODATA("../asm/us/main/nonmatchings/lib", D_800107BC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003E454);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003E9DC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003EC60);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003EF30);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003F398);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003F420);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003F500);

void func_8003F5F4(void) {
    D_8005162C = 0;
    D_80051628 = 0;
    D_8005163C = 0;
    *(s32 *) &D_80051638 = 0;
    func_8003D0C0();
    func_8003D0F0(2, (s32) &func_8003FAAC);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003F644);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003F830);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003F99C);

void func_8003FA9C(s32 arg0) {
    D_800518D0 = arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003FAAC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003FB8C);

s32 func_8003FE74(s32 arg0, s32 arg1) {
    return func_80042D78(arg0, arg1, 0xC) == 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8003FE98);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8004018C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80040238);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80040648);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8004076C);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80040950);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800409E0);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80040AC8);

s32 func_80040B84(s32 arg0, u32 arg1) {
    u32 i;
    s32 pad;

    for (i = 0; i < arg1; i++) {
        *(s32 *) (((i + arg0) << 5) + D_8009C6D4) = 0;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80040BC4);

void func_80040C88(s32 arg0, s32 arg1, s32 arg2) {
    D_8009C6CC = arg0;
    D_8007E76C = arg1;
    D_8009C6C8 = arg2;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80040CA8);

void func_80041620(s32 *arg0, s32 *arg1, u32 arg2) {
    u32 i;
    s32 pad;

    for (i = 0; i < arg2; i++) {
        *arg0++ = *arg1++;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80041654);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80041810);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800418D8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80041AFC);

void func_80041CD4(void) {
    *(volatile s32 *) &D_80051A34 = 0;
    func_8003DE6C(D_80051A44);
    func_8003DE84(D_80051A48);
    func_8003DE9C(9, NULL, 0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80041D28);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80041E30);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80041F4C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80041FD8);

u16 func_80042038(u16 *arg0) {
    return *arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042044);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042168);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042270);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042304);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042394);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8004242C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800424C4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", D_800425F8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8004262C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042990);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800429A0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800429C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800429D0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800429F0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042A00);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042A10);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042A20);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042A40);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042A50);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042A60);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042A70);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042A80);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042A90);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042AA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042AB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042AC0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042AD0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042AE0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042AF0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042B00);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042B10);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042B20);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042BA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042BB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042BC0);

s32 func_80042C60(s32 arg0) {
    s32 n;

    n = arg0 & 0xFFFF;
    if (n >= 3) {
        return 0;
    }
    return D_80062B94[n].v;
}

s32 func_80042C98(s32 arg0) {
    s32 n;

    n = arg0 & 0xFFFF;
    D_80062B90[1] |= D_80062B98[n];
    return n < 3;
}

s32 func_80042CCC(s32 arg0) {
    D_80062B90[1] &= ~D_80062B98[arg0 & 0xFFFF];
    return 1;
}

s32 func_80042D00(s32 arg0) {
    s32 n;

    n = arg0 & 0xFFFF;
    if (n >= 3) {
        return 0;
    }
    D_80062B94[n].v = 0;
    return 1;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042D38);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042D48);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042D58);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042D68);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042D78);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042D98);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80042DC8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80043634);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80043644);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80043654);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800436C0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800437AC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80043814);

DispEnv *func_800438D4(DispEnv *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->disp.x = arg1;
    arg0->disp.y = arg2;
    arg0->disp.w = arg3;
    arg0->screen.x = 0;
    arg0->screen.y = 0;
    arg0->screen.w = 0;
    arg0->screen.h = 0;
    arg0->isrgb24 = 0;
    arg0->isinter = 0;
    arg0->pad1 = 0;
    arg0->pad0 = 0;
    arg0->disp.h = arg4;
    return arg0;
}

s32 func_80043910(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80062BB4;
    D_80062BB4 = arg0;
    return temp_v0;
}

s32 func_80043928(void) {
    return D_80062BB4;
}

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib", D_80010C98);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80043938);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80043A94);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80043BA8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80043C14);

u8 func_80043CC0(void) {
    return D_80062C00;
}

u8 func_80043CD0(void) {
    return D_80062C02;
}

s32 func_80043CE0(s32 arg0) {
    s32 temp_v0;

    if (D_80062C02 >= 2) {
        D_80062BFC("DrawSyncCallback(%08x)...\n", arg0);
    }
    temp_v0 = D_80062C0C;
    D_80062C0C = arg0;
    return temp_v0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80043D3C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80043DD8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80043E44);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80043F6C);

s32 func_80044000(void *arg0, void *arg1) {
    func_80043E44("LoadImage", arg0);
    return M2C_FIELD(D_80062BF8, s32 (**)(s32, void *, M2C_UNK, void *), 8)(M2C_FIELD(D_80062BF8, s32 *, 0x20), arg0, 8, arg1);
}

void func_80044064(void *arg0, M2C_UNK arg1) {
    func_80043E44("StoreImage", arg0);
    M2C_FIELD(D_80062BF8, M2C_UNK (**)(s32, void *, M2C_UNK, M2C_UNK), 8)(M2C_FIELD(D_80062BF8, s32 *, 0x1C), arg0, 8, arg1);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800440C8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8004418C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80044244);

void func_800442DC(void *arg0) {
    u8 temp_s1;

    temp_s1 = M2C_FIELD(arg0, u8 *, 3);
    M2C_FIELD(D_80062BF8, M2C_UNK (**)(M2C_UNK), 0x3C)(0);
    M2C_FIELD(D_80062BF8, M2C_UNK (**)(void *, u8), 0x14)(arg0 + 4, temp_s1);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8004433C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800443B0);

s32 func_80044474(s32 arg0) {
    func_80042D98(arg0, D_80062C10, 0x5C);
    return arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800444AC);

s32 func_800448D0(s32 arg0) {
    func_80042D98(arg0, D_80062C6C, 0x14);
    return arg0;
}

u32 func_80044908(void) {
    return M2C_FIELD(D_80062BF8, u32 (**)(), 0x38)() >> 0x1F;
}

void func_8004493C(void *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s8 *, 3) = 2;
    M2C_FIELD(arg0, s32 *, 4) = func_80044FA0(arg1);
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

void func_80044978(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s8 *, 3) = 2;
    M2C_FIELD(arg0, s32 *, 4) = func_80044DC0(M2C_FIELD(arg1, s16 *, 0), M2C_FIELD(arg1, s16 *, 2));
    M2C_FIELD(arg0, s32 *, 8) = func_80044E8C((s16) (((u16) M2C_FIELD(arg1, s16 *, 0) + M2C_FIELD(arg1, u16 *, 4)) - 1), (s16) (((u16) M2C_FIELD(arg1, s16 *, 2) + M2C_FIELD(arg1, u16 *, 6)) - 1));
}

void func_800449FC(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s8 *, 3) = 2;
    M2C_FIELD(arg0, s32 *, 4) = func_80044F58(M2C_FIELD(arg1, s16 *, 0), M2C_FIELD(arg1, s16 *, 2));
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

void func_80044A40(void *arg0, s32 arg1, s32 arg2) {
    s32 var_v1;

    M2C_FIELD(arg0, s8 *, 3) = 2;
    var_v1 = 0xE6000000;
    if (arg1 != 0) {
        var_v1 = 0xE6000002;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (var_v1 | (arg2 != 0));
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

void func_80044A68(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, s8 *, 3) = 2;
    M2C_FIELD(arg0, s32 *, 4) = func_80044D64(arg1, arg2, arg3 & 0xFFFF);
    M2C_FIELD(arg0, s32 *, 8) = func_80044FA0(arg4);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80044AC0);

s32 func_80044D64(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_v0;
    s32 var_v1;

    var_v0 = (u8) (*(volatile u8 *) &D_80062C00 - 1) < 2;
    if (var_v0) {
        var_v1 = 0xE1000000;
        if (arg1 != 0) {
            var_v1 = 0xE1000800;
        }
        var_v0 = arg2 & 0x27FF;
        if (arg0 != 0) {
            var_v0 |= 0x1000;
        }
    } else {
        var_v1 = 0xE1000000;
        if (arg1 != 0) {
            var_v1 = 0xE1000200;
        }
        var_v0 = arg2 & 0x9FF;
        if (arg0 != 0) {
            var_v0 |= 0x400;
        }
    }
    return var_v1 | var_v0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80044DC0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80044E8C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80044F58);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80044FA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80045024);

s32 func_800450E0(void) {
    return *D_80062CD4;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800450F8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800451E0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80045400);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80045654);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800458F0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8004591C);

s32 func_80045934(s32 *arg0, s32 arg1) {
    s32 i;
    s32 pad;

    *D_80062CD4 = 0x04000000;
    for (i = arg1 - 1; i != -1; i--) {
        *D_80062CD0 = *arg0++;
    }
    return 0;
}

void func_80045984(s32 arg0) {
    *D_80062CD4 = 0x04000002;
    *D_80062CD8 = arg0;
    *D_80062CDC = 0;
    *D_80062CE0 = 0x01000401;
}

s32 func_800459D0(s32 arg0) {
    *D_80062CD4 = arg0 | 0x10000000;
    return *D_80062CD0 & 0xFFFFFF;
}

void func_80045A00(s32 arg0, s32 arg1, s32 arg2) {
    func_80045A24(arg0, arg1, 0, arg2);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80045A24);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80045D18);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8004602C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80046168);

void func_800462B0(void) {
    D_80062D18 = func_8003CEDC(-1) + 0xF0;
    D_80062D1C = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800462E4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80046450);

void func_80046530(u8 *arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 pad;

    for (i = arg2 - 1; i != -1; i--) {
        *arg0++ = arg1;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8004655C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8004656C);

s32 func_80046634(s32 arg0, s32 arg1) {
    return ((arg1 << 6) | ((arg0 >> 4) & 0x3F)) & 0xFFFF;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_8004664C);

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib", D_80010EB0);

void func_8004671C(s32 arg0) {
    D_80062BFC("clut: (%d,%d)\n", (arg0 & 0x3F) * 0x10, (u32) (arg0 & 0xFFFF) >> 6);
}

s32 func_8004675C(s32 *arg0) {
    return (*arg0 & 0xFFFFFF) | 0x80000000;
}

s32 func_80046778(s32 *arg0) {
    return (*arg0 & 0xFFFFFF) == 0xFFFFFF;
}

void func_80046794(MainTag *arg0, MainTag *arg1) {
    arg1->addr = arg0->addr;
    arg0->addr = (u32) arg1;
}

void func_800467D0(MainTag *arg0, u32 arg1, MainTag *arg2) {
    arg2->addr = arg0->addr;
    arg0->addr = arg1;
}

void func_8004680C(s32 *arg0, s32 arg1) {
    *arg0 = (*arg0 & 0xFF000000) | (arg1 & 0xFFFFFF);
}

void func_80046830(s32 *arg0) {
    *arg0 |= 0xFFFFFF;
}

void func_80046848(void *arg0, s32 arg1) {
    u8 var_v0;

    if (arg1 != 0) {
        var_v0 = M2C_FIELD(arg0, u8 *, 7) | 2;
    } else {
        var_v0 = M2C_FIELD(arg0, u8 *, 7) & 0xFD;
    }
    M2C_FIELD(arg0, u8 *, 7) = var_v0;
}

void func_80046870(void *arg0, s32 arg1) {
    u8 var_v0;

    if (arg1 != 0) {
        var_v0 = M2C_FIELD(arg0, u8 *, 7) | 1;
    } else {
        var_v0 = M2C_FIELD(arg0, u8 *, 7) & 0xFE;
    }
    M2C_FIELD(arg0, u8 *, 7) = var_v0;
}

void func_80046898(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 4;
    M2C_FIELD(arg0, s8 *, 7) = 0x20;
}

void func_800468AC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 7;
    M2C_FIELD(arg0, s8 *, 7) = 0x24;
}

void func_800468C0(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 6;
    M2C_FIELD(arg0, s8 *, 7) = 0x30;
}

void func_800468D4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 9;
    M2C_FIELD(arg0, s8 *, 7) = 0x34;
}

void func_800468E8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 5;
    M2C_FIELD(arg0, s8 *, 7) = 0x28;
}

void func_800468FC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 9;
    M2C_FIELD(arg0, s8 *, 7) = 0x2C;
}

void func_80046910(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 8;
    M2C_FIELD(arg0, s8 *, 7) = 0x38;
}

void func_80046924(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 0xC;
    M2C_FIELD(arg0, s8 *, 7) = 0x3C;
}

void func_80046938(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 3;
    M2C_FIELD(arg0, s8 *, 7) = 0x74;
}

void func_8004694C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 3;
    M2C_FIELD(arg0, s8 *, 7) = 0x7C;
}

void func_80046960(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 4;
    M2C_FIELD(arg0, s8 *, 7) = 0x64;
}

void func_80046974(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 2;
    M2C_FIELD(arg0, s8 *, 7) = 0x68;
}

void func_80046988(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 2;
    M2C_FIELD(arg0, s8 *, 7) = 0x70;
}

void func_8004699C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 2;
    M2C_FIELD(arg0, s8 *, 7) = 0x78;
}

void func_800469B0(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 3;
    M2C_FIELD(arg0, s8 *, 7) = 0x60;
}

void func_800469C4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 3;
    M2C_FIELD(arg0, s8 *, 7) = 0x40;
}

void func_800469D8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 4;
    M2C_FIELD(arg0, s8 *, 7) = 0x50;
}

void func_800469EC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 5;
    M2C_FIELD(arg0, s8 *, 7) = 0x48;
    M2C_FIELD(arg0, s32 *, 0x14) = 0x55555555;
}

void func_80046A0C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 7;
    M2C_FIELD(arg0, s8 *, 7) = 0x58;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0x55555555;
}

void func_80046A2C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 6;
    M2C_FIELD(arg0, s8 *, 7) = 0x4C;
    M2C_FIELD(arg0, s32 *, 0x18) = 0x55555555;
}

void func_80046A4C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 9;
    M2C_FIELD(arg0, s8 *, 7) = 0x5C;
    M2C_FIELD(arg0, s32 *, 0x24) = 0x55555555;
}

void func_80046A6C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 3;
    M2C_FIELD(arg0, s8 *, 7) = 2;
}

void func_80046A80(void *arg0) {
    M2C_FIELD(arg0, s8 *, 3) = 5;
    M2C_FIELD(arg0, s8 *, 7) = 1;
    M2C_FIELD(arg0, s32 *, 8) = 0x80000000;
}

s32 func_80046A9C(void *arg0, void *arg1) {
    s32 t;

    t = M2C_FIELD(arg0, u8 *, 3) + M2C_FIELD(arg1, u8 *, 3) + 1;
    if (t > 0x20) {
        return -1;
    }
    M2C_FIELD(arg0, u8 *, 3) = t;
    return 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80046AD0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80046C50);

s32 func_80046CFC(s32 arg0) {
    D_80070690 = arg0;
    return 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80046D0C);

void func_80046D74(s32 arg0, s32 arg1) {
    D_800706A0 = func_80047180(arg0, arg1, &D_8007069C, &D_80070694, &D_80070698);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80046DB4);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80047060);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80047180);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80047318);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80048498);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800484A8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80048540);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800485A0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800487F0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80048968);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800489D0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_800489E0);

void func_80048A44(void) {
    func_80042AF0();
    func_80048ABC();
    func_80042BA0(0);
    func_80042B00();
}

void func_80048A7C(void) {
    func_80048ACC();
    func_80048BEC();
    func_80048C7C();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80048AAC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80048ABC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80048ACC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80048B34);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80048BBC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80048BEC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80048C58);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", func_80048C7C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib", D_80048CFC);
