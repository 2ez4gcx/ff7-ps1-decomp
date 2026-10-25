#include "common.h"
#include "batini/decls.h"

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B0050);

void func_801B0490(s32 arg0) {
    s32 i;
    s32 j;
    s32 lim;
    BiE *p;

    lim = 4;
    if (D_8016376C != 0) {
        lim = 0;
        func_800A7254(0, 0, 0xF, 0);
        func_800A7254(0, 0, 0xE, 0);
    }
    for (i = 0; i < 0x40; i++) {
        if (D_800F6936[i * 8] >= lim) {
            D_800F6936[i * 8] = -1;
        }
    }
    for (j = 0x68; j >= 0; j -= 0x34) {
        D_800F5E66[j] = 0;
    }
    if (D_8016376C != 0) {
        func_801B0F08();
    }
    func_801B23E0(arg0, func_800A3354);
    func_801B1E0C();
    D_800F83AE.mask = 0;
    p = D_800F83AE.e;
    for (i = 0; i < 10; i++) {
        func_800AE954(i);
        if (p[i].b8 != -1) {
            *(u16 *)((u8 *)p - 0x32) |= 1 << i;
        }
    }
    D_800F83CC = arg0;
    D_800F83A8 = D_80163626;
    func_801B19AC();
    func_800A4540();
    func_801B2308();
    func_800A4540();
    for (i = 4; i < 10; i++) {
        D_800F5BBC[i][0] = ((func_80014BA8(0x40) & 0xFF) + 0x80) << 8;
        func_800B108C(i);
    }
}

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B0668);

void func_801B085C(s32 arg0) {
    D_800F7DA6 = 0x10000 / (((arg0 * 0x1E0) / 256 + 0x78) * 2);
}

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B08C0);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B0F08);

void func_801B1120(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_801636B8[i].a != -1 && !(D_800F83E0[i].a & 1)) {
            func_800A6000(i, 0, 0);
        }
    }
}

void func_801B11BC(s32 arg0) {
    u8 *base;
    u8 *p;
    s32 i;
    s32 id;
    s32 n;
    s32 k;
    s32 r;

    base = D_8009D84C[arg0];
    base[0x21] = 1;
    for (i = 0; i < 0x10; i++) {
        p = base + i * 6;
        id = p[0x4C];
        r = 0xFF;
        if (id != 0xFF) {
            r = D_800707C5[id][0];
            if (r == 0xFF) {
                r = D_800F5EFC[arg0][0];
            }
            if (id < 0x1C) {
                if (id >= 0x18) {
                    p[0x50] = 0xFF;
                }
            }
            if (p[0x4D] == 7) {
                if (D_800F5BE1[arg0][0] & 2) {
                    p[0x4D] = 0;
                }
                if (p[0x50] != 0) {
                    if (p[0x4C] != 0x19) {
                        r |= 0xC;
                    }
                }
                if (p[0x4C] == 5 || p[0x4C] == 0x11) {
                    r |= 0x10;
                    if (p[0x50] != 0) {
                        p[0x4D] = 0;
                    }
                }
            }
            base[0x21] = i / 4 + 1;
        }
        p[0x4E] = r;
    }
    for (i = 0; i < 0x60; i++) {
        n = base[i * 8 + 0x108];
        if (n != 0xFF) {
            if (i >= 0x48) {
                n += 0x48;
            } else if (i >= 0x38) {
                n += 0x38;
            }
            if (i < 0x38) {
                k = n * 0x1C;
                if (!(D_800708D0[k] & 8)) {
                    base[i * 8 + 0x10A] = 0;
                }
            }
        }
    }
}

void func_801B137C(s32 arg0) {
    s32 i;
    u8 *p;

    p = D_8009D84C[arg0];
    p[0x21] = 1;
    for (i = 1; i < 4; i++) {
        p[i * 6 + 0x4C] = 0xFF;
        p[i * 6 + 0x4D] = 0;
        p[i * 6 + 0x4E] = 0;
        p[i * 6 + 0x4F] = 3;
        p[i * 6 + 0x50] = 0;
        p[i * 6 + 0x51] = 0;
    }
}

void func_801B13DC(u32 arg0, s32 arg1, u8 *arg2) {
    s32 i;
    s32 j;
    s8 n;

    n = 0;
    for (i = 0; i < 3; i++) {
        j = 0;
        if (arg2[i] != 0xFF) {
            for (j = 0; j < 0xC; j++) {
                if (func_80015AFC(arg0, j) == arg2[i]) {
                    break;
                }
            }
            if (j == 0xC) {
                func_800155A4(0x26);
            } else if ((arg1 >> j) & 1) {
                n++;
                arg2[i + 3] = arg2[i * 0x1C + 0x14];
            }
        }
    }
    arg2[7] = 0;
    arg2[6] = n;
}

s32 func_801B14E8(u32 arg0) {
    s32 temp_v1;
    s32 var_a1;

    temp_v1 = arg0 & 0xFF;
    var_a1 = 0;
    if ((temp_v1 != 0xFF) && ((D_800730DD[temp_v1].a & 0xF) == 7)) {
        var_a1 = (arg0 >> 8) | 0x80000000;
    }
    return var_a1;
}

s32 func_801B1530(u32 *arg0) {
    s32 r;
    s32 i;

    r = 0;
    for (i = 0; i < 8; i++) {
        r |= func_801B14E8(arg0[i + 0x10]);
        r |= func_801B14E8(arg0[i + 0x18]);
    }
    return r;
}

void func_801B1598(s32 arg0, s32 arg1) {
    BiP *p;
    BiQ *q;
    volatile u32 *r;
    u32 v;

    p = &D_800F5BB8[arg0];
    q = (BiQ *)((u8 *)D_800F5BB8 + 0x2A8) + arg0;
    r = &D_800F83E0[arg0].a;
    *r &= ~q->w20;
    p->w34 &= ~q->w20;
    q->w20 = 0;
    p->bD = 0xFF;
    if (arg1 != 0xFF) {
        v = D_80071C29[arg1][0];
        p->bD = v;
        switch (v & 0xFF) {
        case 0:
            *r |= 0x100;
            p->w34 |= 0x100;
            q->w20 |= 0x100;
            break;
        case 1:
            *r |= 0x800000;
            p->w34 |= 0x800000;
            q->w20 |= 0x800000;
            break;
        case 2:
            *r |= 0x200000;
            p->w34 |= 0x200000;
            q->w20 |= 0x200000;
            p->b12 = 0xFF;
            break;
        case 3:
            *r |= 0x40000;
            p->w34 |= 0x40000;
            q->w20 |= 0x40000;
            break;
        case 6:
            *r |= 0x30000;
            q->w20 |= 0x30000;
            break;
        }
    }
}

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B1734);

void func_801B18F8(BiSrc *arg0, BiDst *arg1, BiAct *arg2) {
    arg2->b14 = arg0->b6;
    arg2->b15 = arg0->b7;
    arg2->w30 = arg0->s12;
    arg2->h2A = arg0->h16;
    arg2->bD = arg0->h8;
    arg2->bE = arg0->hC;
    arg2->h20 = arg0->hA;
    arg2->h22 = arg0->hE;
    if (arg2->bD == 0) {
        arg2->bD = 1;
    }
    arg1->s12 = arg2->w30;
    arg1->h10 = arg2->h2A;
    if (arg0->b23 & 8) {
        arg1->s16 = 0x3E7;
        arg1->s14 = 0x270F;
    } else {
        arg1->s16 = 0x270F;
        arg1->s14 = 0x3E7;
    }
}

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B19AC);

void func_801B1CB0(void) {
    s32 n;
    s32 i;
    s32 flags;
    s32 id;
    u8 qty;
    u8 a;
    BiInv *p;
    s32 rows;

    n = 0;
    for (i = 0; i < 0x140; i++) {
        p = &D_801671B8[i];
        id = D_8009CBE0[i];
        qty = 0;
        a = 0;
        flags = 0xB;
        if (id != 0xFFFF) {
            qty = id >> 9;
            id &= 0x1FF;
            if (id < 0x80) {
                a = D_800722D8[id][0];
                flags = D_800722D6[id].v & 0xB;
            } else if (id < 0x100) {
                a = D_800738A0[id - 0x80][0];
                flags = D_800738CA[id - 0x80].v & 0xB;
            } else if (id < 0x120) {
                a = 3;
                flags = D_80071E64[id - 0x100].v & 0xB;
            } else if (id < 0x140) {
                a = 3;
                flags = D_80071C32[id - 0x120].v & 0xB;
            }
            n = i + 1;
        }
        p->id = id;
        p->qty = qty;
        p->a = a;
        p->f = flags;
    }
    rows = (n + 1) / 2;
    if (rows < 3) {
        rows = 3;
    }
    D_80166F74 = rows;
}

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B1E0C);

void func_801B2308(void) {
    s32 i;
    u32 t;

    for (i = 0; i < 6; i++) {
        if (D_80163658[i].a != -1) {
            func_800A6000(i + 4, 0, 0);
        }
    }
    for (i = 0; i < 6; i++) {
        t = D_800F83E4[i + 4][0];
        D_80163624[i + 4][0] = t;
        D_801636B9[i + 4][0] = D_800F83F0[i + 4][0];
        D_800F8424[i + 4][0] = D_800F83E0[i + 4].a;
    }
}

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B23E0);

s32 func_801B2738(s32 arg0) {
    u32 i;

    for (i = 1; i < 0x40; i++) {
        if (arg0 < D_80083184[i]) {
            break;
        }
    }
    return i - 1;
}

s32 func_801B2770(s32 arg0) {
    arg0 = (arg0 * 0x7D) / 100;
    if (arg0 >= 0x100) {
        arg0 = 0xFF;
    }
    return arg0;
}
