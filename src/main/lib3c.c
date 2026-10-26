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

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3c", func_80042D38);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3c", func_80042D48);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3c", func_80042D58);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3c", func_80042D68);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3c", func_80042D78);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3c", func_80042D98);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3c", func_80042DC8);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3c", func_80043634);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib3c", func_80043644);

u8 *func_80043654(u8 *arg0, u8 *arg1, s32 arg2) {
    if (arg0 >= arg1) {
        while (arg2-- > 0) {
            arg0[arg2] = arg1[arg2];
        }
    } else {
        while (arg2-- > 0) {
            *arg0++ = *arg1++;
        }
    }
    return arg0;
}

s32 func_800436C0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s16 r[4];

    r[0] = arg3;
    r[3] = arg6;
    r[1] = arg4;
    switch (arg1) {
    case 0:
        r[2] = arg5 / 4;
        break;
    case 1:
        r[2] = arg5 / 2;
        break;
    case 2:
        r[2] = arg5;
        break;
    }
    func_80044000(r, arg0);
    return func_8004656C(arg1, arg2, arg3, arg4) & 0xFFFF;
}

s32 func_800437AC(void *arg0, s32 arg1, s32 arg2) {
    s16 r[4];

    r[2] = 0x100;
    r[0] = arg1;
    r[1] = arg2;
    r[3] = 1;
    func_80044000(r, arg0);
    return func_80046634(arg1, arg2) & 0xFFFF;
}

s32 func_80043814(Spr *arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    func_80043928();
    arg0->x = (u16) arg1;
    arg0->y = (u16) arg2;
    arg0->w = (u16) arg3;
    M2C_FIELD(arg0, s16 *, 0xC) = 0;
    M2C_FIELD(arg0, s16 *, 0xE) = 0;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    arg0->rest[0] = 0;
    arg0->rest[1] = 0;
    arg0->rest[2] = 0;
    arg0->pad16[0] = 1;
    arg0->f = 0;
    M2C_FIELD(arg0, s16 *, 8) = arg1;
    M2C_FIELD(arg0, s16 *, 0xA) = arg2;
    arg0->h = (u16) arg4;
    if (((s32 (*)(void)) func_80043CC0)() != 1) {
        func_80043CC0();
    }
    arg0->e = 0xA;
    arg0->g = 0;
    return (s32) arg0;
}

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
