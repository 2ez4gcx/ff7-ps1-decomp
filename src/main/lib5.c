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
s32 func_80048540(s32 arg0);
s32 func_80046D0C(s32 arg0);
s32 func_800484A8(void);
s32 func_8004656C(s32 tp, s32 abr, s32 x, s32 y);
M2C_UNK func_80042DC8();

s32 func_8004602C(s32 arg0) {
    D_80062D14 = ((s32 (*)(s32)) func_8003D23C)(0);
    D_80062D08 = 0;
    D_80062D04 = D_80062D08;
    switch (arg0 & 7) {
    case 0:
        *D_80062CE0 = 0x401;
        *D_80062CF0 |= 0x800;
        *D_80062CD4 = 0;
        func_80046530(D_80070590, 0, 0x100);
        func_80046530(&D_8009AD40, 0, 0x1800);
        break;
    case 1:
        *D_80062CE0 = 0x401;
        *D_80062CF0 |= 0x800;
        *D_80062CD4 = 0x02000000;
        *D_80062CD4 = 0x01000000;
        break;
    }
    ((s32 (*)(s32)) func_8003D23C)(D_80062D14);
    if (!(arg0 & 7)) {
        return func_80046450(arg0);
    }
    return 0;
}

s32 func_80046168(s32 arg0) {
    s32 n;

    if (arg0 == 0) {
        func_800462B0();
        while (D_80062D04 != D_80062D08) {
            func_80045D18();
            if (func_800462E4() != 0) {
                return -1;
            }
        }
        while ((*D_80062CE0 & 0x01000000) || !(*D_80062CD4 & 0x04000000)) {
            if (func_800462E4() != 0) {
                return -1;
            }
        }
        return 0;
    }
    n = (D_80062D04 - D_80062D08) & 0x3F;
    if (n != 0) {
        func_80045D18();
    }
    if ((*D_80062CE0 & 0x01000000) || !(*D_80062CD4 & 0x04000000)) {
        if (n == 0) {
            return 1;
        }
        return n;
    }
    return n;
}

void func_800462B0(void) {
    D_80062D18 = func_8003CEDC(-1) + 0xF0;
    D_80062D1C = 0;
}

s32 func_800462E4(void) {
    if (func_8003CEDC(-1) > D_80062D18 || D_80062D1C++ > 0xF0000) {
        *D_80062CD4;
        func_80042DC8("GPU timeout:que=%d,stat=%08x,chcr=%08x,madr=%08x,", (D_80062D04 - D_80062D08) & 0x3F, *D_80062CD4, *D_80062CE0, *D_80062CD8);
        func_80042DC8("func=(%08x)(%08x,%08x)\n", *(volatile s32 *) &D_80062CF4, D_80062CF8, D_80062CFC);
        D_80062D14 = ((s32 (*)(s32)) func_8003D23C)(0);
        D_80062D08 = 0;
        D_80062D04 = D_80062D08;
        *D_80062CE0 = 0x401;
        *D_80062CF0 |= 0x800;
        *D_80062CD4 = 0x02000000;
        *D_80062CD4 = 0x01000000;
        ((s32 (*)(s32)) func_8003D23C)(D_80062D14);
        return -1;
    }
    return 0;
}

s32 func_80046450(s32 arg0) {
    *D_80062CD4 = 0x10000007;
    if ((*D_80062CD0 & 0xFFFFFF) != 2) {
        *D_80062CD0 = (*D_80062CD4 & 0x3FFF) | 0xE1001000;
        *D_80062CD0;
        if (!(*D_80062CD4 & 0x1000)) {
            return 0;
        }
        if (!(arg0 & 8)) {
            return 1;
        }
        *D_80062CD4 = 0x20000504;
        return 2;
    }
    if (!(arg0 & 8)) {
        return 3;
    }
    *D_80062CD4 = 0x09000001;
    return 4;
}

void func_80046530(u8 *arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 pad;

    for (i = arg2 - 1; i != -1; i--) {
        *arg0++ = arg1;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_8004655C);

s32 func_8004656C(s32 tp, s32 abr, s32 x, s32 y) {
    if (((s32 (*)(void)) func_80043CC0)() == 1 || ((s32 (*)(void)) func_80043CC0)() == 2) {
        return ((tp & 3) << 9) | ((abr & 3) << 7) | ((y & 0x300) >> 3) | ((x & 0x3FF) >> 6);
    }
    return ((tp & 3) << 7) | ((abr & 3) << 5) | ((y & 0x100) >> 4) | ((x & 0x3FF) >> 6) | ((y & 0x200) << 2);
}

s32 func_80046634(s32 arg0, s32 arg1) {
    return ((arg1 << 6) | ((arg0 >> 4) & 0x3F)) & 0xFFFF;
}

void func_8004664C(s32 arg0) {
    u16 t;

    if (((s32 (*)(void)) func_80043CC0)() == 1 || ((s32 (*)(void)) func_80043CC0)() == 2) {
        t = arg0;
        D_80062BFC(D_80010EB0, (t >> 9) & 3, (t >> 7) & 3, (t << 6) & 0x7C0, (t << 3) & 0x300);
    } else {
        t = arg0;
        D_80062BFC(D_80010EB0, (t >> 7) & 3, (t >> 5) & 3, (t << 6) & 0x7C0, ((t << 4) & 0x100) + ((t >> 2) & 0x200));
    }
}

INCLUDE_RODATA("../asm/us/main/nonmatchings/lib5", D_80010EB0);

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

void func_80046AD0(MainDrawEnv *arg0) {
    u16 t;

    D_80062BFC("clip (%3d,%3d)-(%d,%d)\n", arg0->clip.x, arg0->clip.y, arg0->clip.w, arg0->clip.h);
    D_80062BFC("ofs  (%3d,%3d)\n", arg0->ofs[0], arg0->ofs[1]);
    D_80062BFC("tw   (%d,%d)-(%d,%d)\n", arg0->tw.x, arg0->tw.y, arg0->tw.w, arg0->tw.h);
    D_80062BFC("dtd   %d\n", arg0->dtd);
    D_80062BFC("dfe   %d\n", arg0->dfe);
    if (((s32 (*)(void)) func_80043CC0)() == 1 || ((s32 (*)(void)) func_80043CC0)() == 2) {
        t = arg0->tpage;
        D_80062BFC(D_80010EB0, (t >> 9) & 3, (t >> 7) & 3, (t << 6) & 0x7C0, (t << 3) & 0x300);
    } else {
        t = arg0->tpage;
        D_80062BFC(D_80010EB0, (t >> 7) & 3, (t >> 5) & 3, (t << 6) & 0x7C0, ((t << 4) & 0x100) + ((t >> 2) & 0x200));
    }
}

void func_80046C50(DispEnv *arg0) {
    D_80062BFC("disp   (%3d,%3d)-(%d,%d)\n", arg0->disp.x, arg0->disp.y, arg0->disp.w, arg0->disp.h);
    D_80062BFC("screen (%3d,%3d)-(%d,%d)\n", arg0->screen.x, arg0->screen.y, arg0->screen.w, arg0->screen.h);
    D_80062BFC("isinter %d\n", arg0->isinter);
    D_80062BFC("isrgb24 %d\n", arg0->isrgb24);
}

s32 func_80046CFC(s32 arg0) {
    D_80070690 = arg0;
    return 0;
}

s32 func_80046D0C(s32 arg0) {
    s32 t;

    t = func_80047060(D_80070690, arg0);
    if (t == -1) {
        return 0;
    }
    D_80070690 += t * 4;
    return arg0;
}

void func_80046D74(s32 arg0, s32 arg1) {
    D_800706A0 = func_80047180(arg0, arg1, &D_8007069C, &D_80070694, &D_80070698);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80046DB4);

s32 func_80047060(u32 *arg0, u32 *arg1) {
    u32 n;
    u32 t;
    u32 u;
    u32 *p;
    u32 x;

    if (*arg0++ != 0x10) {
        return -1;
    }
    arg1[0] = *arg0++;
    if (((s32 (*)(void)) func_80043CD0)() == 2) {
        func_80042DC8("id  =%08x\n", 0x10);
    }
    if (((s32 (*)(void)) func_80043CD0)() == 2) {
        func_80042DC8("mode=%08x\n", arg1[0]);
    }
    if (((s32 (*)(void)) func_80043CD0)() == 2) {
        func_80042DC8("timaddr=%08x\n", (u32) arg0);
    }
    if (arg1[0] & 8) {
        u = *arg0;
        t = u;
        p = arg0;
        arg1[1] = (u32) (p + 1);
        arg1[2] = (u32) (p + 3);
        n = t >> 2;
        arg0 += n;
    } else {
        n = 0;
        arg1[1] = 0;
        arg1[2] = 0;
    }
    x = *arg0;
    arg1[3] = (u32) (arg0 + 1);
    arg1[4] = (u32) (arg0 + 3);
    x = x >> 2;
    x += 2;
    return n + x;
}

s32 func_80047180(u32 *arg0, s32 arg1, u32 *arg2, u32 *arg3, u32 *arg4) {
    MainTmdObj *o;

    o = (MainTmdObj *) (arg0 + 3);
    if (((s32 (*)(void)) func_80043CD0)() == 2) {
        func_80042DC8("analizing TMD...\n");
    }
    if (((s32 (*)(void)) func_80043CD0)() == 2) {
        func_80042DC8("\tid=%08X, flags=%d, nobj=%d, objid=%d\n", arg0[0], arg0[1], arg0[2], arg1);
    }
    if (((s32 (*)(void)) func_80043CD0)() == 2) {
        func_80042DC8("\tvert=%08X, nvert=%d\n", o[arg1].vert, o[arg1].nvert);
    }
    if (((s32 (*)(void)) func_80043CD0)() == 2) {
        func_80042DC8("\tnorm=%08X, nnorm=%d\n", o[arg1].norm, o[arg1].nnorm);
    }
    if (((s32 (*)(void)) func_80043CD0)() == 2) {
        func_80042DC8("\tprim=%08X, nprim=%d\n", o[arg1].prim, o[arg1].nprim);
    }
    *arg3 = (u32) o + o[arg1].vert;
    *arg4 = (u32) o + o[arg1].norm;
    *arg2 = (u32) o + o[arg1].prim;
    return o[arg1].nprim;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80047318);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048498);

s32 func_800484A8(void) {
    s32 zero;
    volatile s32 tmp;

    zero = 0;
    if (!(0x01000000 & *D_80062D28)) {
        return zero;
    }
    if (((u32) (*D_80062D28 & 0x700) >> 8) != 4) {
        return -1;
    }
    *D_80062D28 &= 0xFEFFFFFF;
    tmp = *D_80062D28;
    tmp = *D_80062D20;
    if ((tmp & 0xFFFFFF) == 0xFFFFFF) {
        return zero;
        do {
        } while (zero);
    }
    return tmp;
}

s32 func_80048540(s32 arg0) {
    s32 i;

    i = 0;
    while (!(*D_80062D30 & 0x04000000)) {
        if (arg0 < i++) {
            return -1;
        }
    }
    return 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_800485A0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_800487F0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048968);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_800489D0);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_800489E0);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048AAC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048ABC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048ACC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048B34);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048BBC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048BEC);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048C58);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", func_80048C7C);

INCLUDE_ASM("../asm/us/main/nonmatchings/lib5", D_80048CFC);
