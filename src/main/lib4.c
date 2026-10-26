#include "common.h"
#include "main/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
void func_80043F6C(Rect16 *arg0, u8 arg1, u8 arg2, u8 arg3);
void func_80038FB8(s32 arg0);
s32 func_80042C98(s32 arg0);
M2C_UNK func_80042D98();
s32 func_80039A74(s32 arg0);
DispEnv *func_800438D4(DispEnv *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_80046794(MainTag *arg0, MainTag *arg1);
s32 func_80036FFC(s32 arg0, MainWords *arg1);
s32 func_80043DD8(s32 arg0);
s32 func_8004433C(s32 arg0);
s32 func_80043BA8(s32 arg0);
s32 func_80043D3C(s32 arg0);
MainTag *func_8004418C(MainTag *arg0, s32 arg1);
MainTag *func_80044244(MainTag *arg0, M2C_UNK arg1);

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib4", D_80010C98);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_80043938);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_80043A94);

s32 func_80043BA8(s32 arg0) {
    u8 *p;
    u8 old;

    p = &D_80062C02;
    old = *p;
    *p = arg0;
    if (arg0 & 0xFF) {
        D_80062BFC("SetGraphDebug:level:%d,type:%d reverse:%d\n", *p, D_80062C00, D_80062C03);
    }
    return old;
}

s32 func_80043C14(s32 arg0) {
    u8 *p;
    u8 old;

    p = &D_80062C01;
    old = *p;
    if (D_80062C02 >= 2) {
        D_80062BFC("SetGrapQue(%d)...\n", arg0);
    }
    if (arg0 != *p) {
        M2C_FIELD(D_80062BF8, M2C_UNK (**)(M2C_UNK), 0x34)(1);
        *p = arg0;
        func_8003D120(2, 0);
    }
    return old;
}

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

s32 func_80043D3C(s32 arg0) {
    u8 *p;

    p = &D_80062C02;
    if (*p >= 2) {
        D_80062BFC("SetDispMask(%d)...\n", arg0);
    }
    if (arg0 == 0) {
        func_80046530(p + 0x6A, -1, 0x14);
    }
    return M2C_FIELD(D_80062BF8, s32 (**)(s32), 0x10)(arg0 != 0 ? 0x03000000 : 0x03000001);
}

s32 func_80043DD8(s32 arg0) {
    if (D_80062C02 >= 2) {
        D_80062BFC("DrawSync(%d)...\n", arg0);
    }
    return M2C_FIELD(D_80062BF8, s32 (**)(s32), 0x3C)(arg0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_80043E44);

void func_80043F6C(Rect16 *arg0, u8 arg1, u8 arg2, u8 arg3) {
    func_80043E44("ClearImage", arg0);
    M2C_FIELD(D_80062BF8, M2C_UNK (**)(s32, void *, M2C_UNK, s32), 8)(M2C_FIELD(D_80062BF8, s32 *, 0xC), arg0, 8, (arg3 << 0x10) | (arg2 << 8) | arg1);
}

s32 func_80044000(void *arg0, void *arg1) {
    func_80043E44("LoadImage", arg0);
    return M2C_FIELD(D_80062BF8, s32 (**)(s32, void *, M2C_UNK, void *), 8)(M2C_FIELD(D_80062BF8, s32 *, 0x20), arg0, 8, arg1);
}

void func_80044064(void *arg0, M2C_UNK arg1) {
    func_80043E44("StoreImage", arg0);
    M2C_FIELD(D_80062BF8, M2C_UNK (**)(s32, void *, M2C_UNK, M2C_UNK), 8)(M2C_FIELD(D_80062BF8, s32 *, 0x1C), arg0, 8, arg1);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_800440C8);

MainTag *func_8004418C(MainTag *arg0, s32 arg1) {
    if (D_80062C02 >= 2) {
        D_80062BFC("ClearOTag(%08x,%d)...\n", arg0, arg1);
    }
    arg1 -= 1;
    if (arg1 != 0) {
        do {
            arg1 -= 1;
            arg0->len = 0;
            arg0->addr = (u32) (arg0 + 1);
            arg0++;
        } while (arg1 != 0);
    }
    *(u32 *) arg0 = (u32) &D_80062CBC & 0xFFFFFF;
    return arg0;
}

MainTag *func_80044244(MainTag *arg0, M2C_UNK arg1) {
    if (D_80062C02 >= 2) {
        D_80062BFC("ClearOTagR(%08x,%d)...\n", arg0, arg1);
    }
    M2C_FIELD(D_80062BF8, M2C_UNK (**)(MainTag *, M2C_UNK), 0x2C)(arg0, arg1);
    *(u32 *) arg0 = (u32) &D_80062CBC & 0xFFFFFF;
    return arg0;
}

void func_800442DC(void *arg0) {
    u8 temp_s1;

    temp_s1 = M2C_FIELD(arg0, u8 *, 3);
    M2C_FIELD(D_80062BF8, M2C_UNK (**)(M2C_UNK), 0x3C)(0);
    M2C_FIELD(D_80062BF8, M2C_UNK (**)(void *, u8), 0x14)(arg0 + 4, temp_s1);
}

s32 func_8004433C(s32 arg0) {
    if (D_80062C02 >= 2) {
        D_80062BFC("DrawOTag(%08x)...\n", arg0);
    }
    return M2C_FIELD(D_80062BF8, s32 (**)(s32, s32, M2C_UNK, M2C_UNK), 8)(M2C_FIELD(D_80062BF8, s32 *, 0x18), arg0, 0, 0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_800443B0);

s32 func_80044474(s32 arg0) {
    func_80042D98(arg0, D_80062C10, 0x5C);
    return arg0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_800444AC);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_80044AC0);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_80044DC0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_80044E8C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_80044F58);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_80044FA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_80045024);

s32 func_800450E0(void) {
    return *D_80062CD4;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_800450F8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_800451E0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_80045400);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_80045654);

void func_800458F0(s32 arg0) {
    *D_80062CD4 = arg0;
    D_80070590[(u32) arg0 >> 0x18] = arg0;
}

u8 func_8004591C(s32 arg0) {
    return D_80070590[arg0];
}

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

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_80045A24);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib4", func_80045D18);
