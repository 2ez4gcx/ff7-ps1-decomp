#include "common.h"
#include "field/decls.h"

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AE23C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AE4DC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AEE24);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AF6EC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AF96C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AFAC4);

void func_800AFDE4(void) {
    List2 *p = &D_800DFDFC;
    s32 n;
    s32 i;
    n = 16;
    p->n = n;
    for (i = 0; i < n; i++) {
        p->e[i].a = 0;
        p->e[i].b = 0;
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AFE1C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B0618);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B0A48);

s32 func_800B0EDC(u8 *arg0, u8 *arg1) {
    s16 x;
    s16 y;
    s16 z;
    s32 q;
    u32 i;
    s32 n;
    u8 pad[8];

    n = arg0[3];
    q = *(u16 *)(arg0 + 0x18) + *(s32 *)(arg0 + 0x1C);
    x = (arg1[1] << 8) | arg1[0];
    y = (arg1[3] << 8) | arg1[2];
    z = (arg1[5] << 8) | arg1[4];
    *(s32 *)0x1F800200 = arg1[6];
    for (i = 0; i < n; i++) {
        func_800B0FB0(q + i * 0x20, x, y, z);
    }
    return 1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B0FB0);

s32 func_800B1C7C(u8 *e, u8 *a) {
    RECT16 r;
    s32 n;
    s32 p;
    s32 t;

    n = a[3];
    if (n <= 0x20) {
        t = a[0];
        p = D_800DFCA0 + *(s32 *)(D_800DFCA0 + 8) + (D_800DFCA4[e[0x15]][t] << 9);
        r.x = (n % 4) * 16 + 0x300;
        r.y = (n / 4) * 32 + 0x100;
        r.w = 8;
        r.h = 0x20;
        func_80044000(&r, p);
        t = a[1];
        p = D_800DFCA0 + *(s32 *)(D_800DFCA0 + 8) + (D_800DFCA4[e[0x15]][t] << 9);
        r.x = (n % 4) * 16 + 0x308;
        r.y = (n / 4) * 32 + 0x100;
        r.w = 8;
        r.h = 0x20;
        func_80044000(&r, p);
        t = a[2];
        p = D_800DFCA0 + *(s32 *)(D_800DFCA0 + 8) + (D_800DFD94[e[0x15]][t] << 9);
        r.x = (n % 8) * 8 + 0x300;
        r.y = (n / 8) * 32 + 0x1A0;
        r.w = 8;
        r.h = 0x20;
        func_80044000(&r, p);
    }
    return 1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B1E40);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B2598);

s32 func_800B2A00(u8 *arg0, u8 *arg1) {
    FdPolyGrp *tab;
    FdPolyGrp *e;
    u8 *q;
    u32 flag;
    u32 i;
    u32 j;
    u32 k;
    u32 n;
    u8 *p0;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 *p4;
    u8 *p5;
    u8 *p6;
    u8 *p7;

    tab = (FdPolyGrp *)(*(u16 *)(arg0 + 0x18) + *(s32 *)(arg0 + 0x1C));
    flag = *arg1;
    for (i = 0; i < arg0[3]; i++) {
        e = &tab[i];
        for (j = 0; j < 2; j++) {
            q = e->data;
            if (j != 0) {
                q += e->off;
            }
            n = e->n[0];
            for (k = 0; k < n; k++) {
                p0 = q + 7;
                if (flag != 0) {
                    *p0 = *p0 | 2;
                } else {
                    *p0 = *p0 & 0xFD;
                }
                if (flag != 0) {
                    *p0 = *p0 | 1;
                } else {
                    *p0 = *p0 & 0xFE;
                }
                q += 0x34;
            }
            n = e->n[1];
            for (k = 0; k < n; k++) {
                p1 = q + 7;
                if (flag != 0) {
                    *p1 = *p1 | 2;
                } else {
                    *p1 = *p1 & 0xFD;
                }
                if (flag != 0) {
                    *p1 = *p1 | 1;
                } else {
                    *p1 = *p1 & 0xFE;
                }
                q += 0x28;
            }
            n = e->n[2];
            for (k = 0; k < n; k++) {
                p2 = q + 7;
                if (flag != 0) {
                    *p2 = *p2 | 2;
                } else {
                    *p2 = *p2 & 0xFD;
                }
                if (flag != 0) {
                    *p2 = *p2 | 1;
                } else {
                    *p2 = *p2 & 0xFE;
                }
                q += 0x28;
            }
            n = e->n[3];
            for (k = 0; k < n; k++) {
                p3 = q + 7;
                if (flag != 0) {
                    *p3 = *p3 | 2;
                } else {
                    *p3 = *p3 & 0xFD;
                }
                if (flag != 0) {
                    *p3 = *p3 | 1;
                } else {
                    *p3 = *p3 & 0xFE;
                }
                q += 0x20;
            }
            n = e->n[4];
            for (k = 0; k < n; k++) {
                p4 = q + 7;
                if (flag != 0) {
                    *p4 = *p4 | 2;
                } else {
                    *p4 = *p4 & 0xFD;
                }
                if (flag != 0) {
                    *p4 = *p4 | 1;
                } else {
                    *p4 = *p4 & 0xFE;
                }
                q += 0x14;
            }
            n = e->n[5];
            for (k = 0; k < n; k++) {
                p5 = q + 7;
                if (flag != 0) {
                    *p5 = *p5 | 2;
                } else {
                    *p5 = *p5 & 0xFD;
                }
                if (flag != 0) {
                    *p5 = *p5 | 1;
                } else {
                    *p5 = *p5 & 0xFE;
                }
                q += 0x18;
            }
            n = e->n[6];
            for (k = 0; k < n; k++) {
                p6 = q + 7;
                if (flag != 0) {
                    *p6 = *p6 | 2;
                } else {
                    *p6 = *p6 & 0xFD;
                }
                if (flag != 0) {
                    *p6 = *p6 | 1;
                } else {
                    *p6 = *p6 & 0xFE;
                }
                q += 0x1C;
            }
            n = e->n[7];
            for (k = 0; k < n; k++) {
                p7 = q + 7;
                if (flag != 0) {
                    *p7 = *p7 | 2;
                } else {
                    *p7 = *p7 & 0xFD;
                }
                if (flag != 0) {
                    *p7 = *p7 | 1;
                } else {
                    *p7 = *p7 & 0xFE;
                }
                q += 0x24;
            }
        }
    }
    return 1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B2DD4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B2F40);

s32 func_800B480C(u8 *arg0, FdCamCmd *arg1) {
    FdCam3C *s;
    s32 f;
    u8 pad[0x38];

    s = &D_800DFE1C.cam[arg1->b[1]];
    switch (arg1->b[0]) {
    case 0:
        s->x0 = arg1->b[2] | (arg1->b[3] << 8);
        s->x2 = arg1->b[4] | (arg1->b[5] << 8);
        s->x4 = arg1->b[6] | (arg1->b[7] << 8);
        s->x6 = arg1->b[8] | (arg1->b[9] << 8);
        s->x8 = arg1->b[10] | (arg1->b[11] << 8);
        s->xA = arg1->b[12] | (arg1->b[13] << 8);
        s->xC = arg1->b[14] | (arg1->b[15] << 8);
        s->xE = arg1->b[16] | (arg1->b[17] << 8);
        s->x10 = arg1->b[18] | (arg1->b[19] << 8);
        s->x12 = arg1->b[20];
        s->x13 = 0;
        return 1;
    case 1:
        D_800DFE1C.b0 = s->x0;
        D_800DFE1C.b1 = (u16)s->x0 >> 8;
        D_800DFE1C.b2 = s->x2;
        D_800DFE1C.b3 = (u16)s->x2 >> 8;
        D_800DFE1C.b4 = s->x4;
        D_800DFE1C.b5 = (u16)s->x4 >> 8;
        D_800DFE1C.b6 = s->x12;
        f = 0;
        func_800B0EDC(arg0, (u8 *)&D_800DFE1C);
        if (s->x13 == 0) {
            s->x0 += s->xC;
            if (s->xC >= 0) {
                if (s->x0 >= s->x6) {
                    goto c1;
                }
            } else if (s->x0 <= s->x6) {
c1:
                f |= 1;
                s->x0 = s->x6;
            }
            s->x2 += s->xE;
            if (s->xE >= 0) {
                if (s->x2 >= s->x8) {
                    goto c2;
                }
            } else if (s->x2 <= s->x8) {
c2:
                f |= 2;
                s->x2 = s->x8;
            }
            s->x4 += s->x10;
            if (s->x10 >= 0) {
                if (s->x4 >= s->xA) {
                    goto c3;
                }
            } else if (s->x4 <= s->xA) {
c3:
                f |= 4;
                s->x4 = s->xA;
            }
            if (f == 7) {
                s->x13 += 1;
            }
            return 0;
        }
        return 1;
    default:
        return 1;
    }
}

s32 func_800B4B04(void *arg0, u8 *arg1) {
    FdSlot3C *r;
    u8 pad[0x38];

    r =&D_800DFE3C[arg1[1]];
    switch (arg1[0]) {
    case 0:
        r->b[0] = arg1[2];
        r->b[1] = arg1[3];
        r->b[2] = arg1[4];
        r->b[3] = arg1[5];
        r->b[4] = arg1[6];
        r->b[5] = arg1[7];
        r->b[6] = arg1[8];
        r->b[7] = arg1[9];
        r->b[8] = arg1[10];
        r->b[9] = arg1[11];
        r->b[10] = arg1[12];
        r->b[11] = arg1[13];
        *(u16 *)&r->b[12] = arg1[14] | (arg1[15] << 8);
        *(u16 *)&r->b[14] = arg1[16] | (arg1[17] << 8);
        *(u16 *)&r->b[16] = arg1[18] | (arg1[19] << 8);
        *(u16 *)&r->b[18] = arg1[20] | (arg1[21] << 8);
        *(u16 *)&r->b[20] = arg1[22] | (arg1[23] << 8);
        *(u16 *)&r->b[22] = arg1[24] | (arg1[25] << 8);
        *(u16 *)&r->b[24] = arg1[26] | (arg1[27] << 8);
        *(u16 *)&r->b[26] = arg1[28] | (arg1[29] << 8);
        *(u16 *)&r->b[28] = arg1[30] | (arg1[31] << 8);
        return 1;
    case 1:
        ((u8 *)D_800DFE3C)[-0x20] = r->b[0];
        D_800DFE1D = r->b[1];
        D_800DFE1E = r->b[2];
        D_800DFE1F = r->b[3];
        D_800DFE20 = r->b[4];
        D_800DFE21 = r->b[5];
        D_800DFE22 = r->b[6];
        D_800DFE23 = r->b[7];
        D_800DFE24 = r->b[8];
        D_800DFE25 = r->b[9];
        D_800DFE26 = r->b[10];
        D_800DFE27 = r->b[11];
        D_800DFE28 = r->b[12];
        D_800DFE29 = *(u16 *)&r->b[12] >> 8;
        D_800DFE2A = r->b[14];
        D_800DFE2B = *(u16 *)&r->b[14] >> 8;
        D_800DFE2C = r->b[16];
        D_800DFE2D = *(u16 *)&r->b[16] >> 8;
        D_800DFE2E = r->b[18];
        D_800DFE2F = *(u16 *)&r->b[18] >> 8;
        D_800DFE30 = r->b[20];
        D_800DFE31 = *(u16 *)&r->b[20] >> 8;
        D_800DFE32 = r->b[22];
        D_800DFE33 = *(u16 *)&r->b[22] >> 8;
        D_800DFE34 = r->b[24];
        D_800DFE35 = *(u16 *)&r->b[24] >> 8;
        D_800DFE36 = r->b[26];
        D_800DFE37 = *(u16 *)&r->b[26] >> 8;
        D_800DFE38 = r->b[28];
        D_800DFE39 = *(u16 *)&r->b[28] >> 8;
        func_800B0618(arg0, (u8 *)D_800DFE3C - 0x20, r);
        return 0;
    default:
        return 0;
    }
}

s32 func_800B4EAC(void *arg0, u8 *arg1) {
    FdSlotB *r;
    s32 flags;
    s16 sum;
    u8 pad[0x50];

    r = &D_800DFE3C[arg1[1]];
    switch (arg1[0]) {
    case 0:
        r->p[0] = arg1[2] | (arg1[3] << 8);
        r->p[1] = arg1[4] | (arg1[5] << 8);
        r->p[2] = arg1[6] | (arg1[7] << 8);
        r->p[3] = arg1[8] | (arg1[9] << 8);
        r->t[0] = arg1[10] | (arg1[11] << 8);
        r->t[1] = arg1[12] | (arg1[13] << 8);
        r->t[2] = arg1[14] | (arg1[15] << 8);
        r->t[3] = arg1[16] | (arg1[17] << 8);
        r->s[0] = arg1[18] | (arg1[19] << 8);
        r->s[1] = arg1[20] | (arg1[21] << 8);
        r->s[2] = arg1[22] | (arg1[23] << 8);
        r->s[3] = arg1[24] | (arg1[25] << 8);
        r->b18 = arg1[0x1A];
        r->b19 = 0;
        return 1;
    case 1:
        ((u8 *)D_800DFE3C)[-0x20] = *(u8 *)&r->p[0];
        D_800DFE1D = *(u16 *)&r->p[0] >> 8;
        D_800DFE1E = *(u8 *)&r->p[1];
        D_800DFE1F = *(u16 *)&r->p[1] >> 8;
        D_800DFE20 = *(u8 *)&r->p[2];
        D_800DFE21 = *(u16 *)&r->p[2] >> 8;
        D_800DFE22 = *(u8 *)&r->p[3];
        D_800DFE23 = *(u16 *)&r->p[3] >> 8;
        D_800DFE24 = r->b18;
        flags = 0;
        func_800B2DD4(arg0, (u8 *)D_800DFE3C - 0x20);
        flags = 0;
        if (r->b19 == 0) {
            sum = r->p[0] + r->s[0];
            r->p[0] = sum;
            if ((r->s[0] >= 0 && sum >= r->t[0]) || (r->s[0] < 0 && sum <= r->t[0])) {
                flags |= 1;
                r->p[0] = r->t[0];
            }
            sum = r->p[1] + r->s[1];
            r->p[1] = sum;
            if ((r->s[1] >= 0 && sum >= r->t[1]) || (r->s[1] < 0 && sum <= r->t[1])) {
                flags |= 2;
                r->p[1] = r->t[1];
            }
            sum = r->p[2] + r->s[2];
            r->p[2] = sum;
            if ((r->s[2] >= 0 && sum >= r->t[2]) || (r->s[2] < 0 && sum <= r->t[2])) {
                flags |= 4;
                r->p[2] = r->t[2];
            }
            sum = r->p[3] + r->s[3];
            r->p[3] = sum;
            if ((r->s[3] >= 0 && sum >= r->t[3]) || (r->s[3] < 0 && sum <= r->t[3])) {
                flags |= 8;
                r->p[3] = r->t[3];
            }
            if (flags == 0xF) {
                r->b19 = r->b19 + 1;
            }
            return 0;
        }
        return 1;
    default:
        return 1;
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B5260);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B5504);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B62C4);

void func_800B69C0(u8 *arg0, s32 arg1) {
    FdItem5C *e;
    FPair *q;
    s32 i;
    s32 n;
    s16 clut;
    s16 tpage;

    e = (FdItem5C *)(D_800E0200 + arg1 * 0xAC8);
    clut = 0x6C2C;
    if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
        tpage = 0x22B;
    } else {
        tpage = 0x9B;
    }
    n = 31;
    q = M2C_FIELD(arg0, FPair **, 0x1C);
    for (i = 1; i < n; i++) {
        e[i].p[0].len = 9;
        e[i].p[1].len = 9;
        e[i].p[0].code = 0x2C;
        e[i].p[1].code = 0x2C;
        e[i].p[1].b0 = 0x80;
        e[i].p[0].b0 = 0x80;
        e[i].p[1].g0 = 0x80;
        e[i].p[0].g0 = 0x80;
        e[i].p[1].r0 = 0x80;
        e[i].p[0].r0 = 0x80;
        e[i].p[1].clut = clut;
        e[i].p[0].clut = clut;
        e[i].p[1].tpage = tpage;
        e[i].p[0].tpage = tpage;
        e[i].x50 = 0;
        e[i].x52 = 0;
        e[i].x54 = 0;
        e[i].p[0].code |= 2;
        e[i].p[1].code |= 2;
        e[i].x58 = -q[i].a;
        e[i].x5A = 0;
    }
}

s32 func_800B6AE4(S6AE4 *a, u8 *b) {
    s32 i;
    s32 n;
    s32 idx;
    u8 *p;

    n = b[0];
    if (n > 0) {
        p = a->base + a->off;
        for (i = 0; i < n; i++) {
            idx = b[1 + i * 2];
            if (idx < a->n) {
                p[idx * 32] = b[2 + i * 2];
            }
        }
    }
    return 1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B6B4C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B79B8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B86D8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B8CF0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B9B0C);

void func_800BA534(u8 *arg0, u8 *arg1, u8 *arg2) {
    s32 f;

    D_8009C6E0 = arg0;
    D_8009C544 = arg1;
    D_8009C6DC = arg2;
    D_80095DCC = 0;
    D_8007EBE0 = 1;
    D_8009FE8C = 0;
    f = M2C_SFIELD(arg0, s16 *, 0x6A);
    if (f & 0x100) {
        D_80095DCC = 1;
        D_80099FFC = 4;
    }
    if ((u8) M2C_FIELD(arg2, u8 *, 0) < 2U) {
        func_800429E0(0x4B, 0xA);
    }
    if (((u8) M2C_FIELD(arg2, u8 *, 0) >= 3U) || ((u8) M2C_FIELD(arg2, u8 *, 1) >= 6U)) {
        func_800429E0(0x4B, 0xC);
    }
    if ((u8) M2C_FIELD(arg2, u8 *, 1) < 5U) {
        func_800429E0(0x4B, 0xB);
    }
    func_800D48C0();
    func_800BA7C4();
    func_800BAF54();
    if (D_800716D4 == 0) {
        func_800C46A4();
        D_8009A000 = 0xF2;
        func_8002DA7C();
    }
}

void func_800BA65C(s32 arg0) {
    if (D_8007EBE0 != 0) {
        func_800D4BFC();
        func_800BC338();
        func_800D7D6C();
        func_800D7F9C();
        D_80095DCC = 0;
        D_8009FE8C = 0;
        D_8007EBE0 = 0;
        if ((u8) M2C_FIELD(D_8009C6DC, u8 *, 1) < 5U) {
            func_800429E0(0x4B, 0xB);
        }
        if ((u8) M2C_FIELD(D_8009C6DC, u8 *, 0) < 2U) {
            func_800429E0(0x4B, 0xA);
        }
        if (((u8) M2C_FIELD(D_8009C6DC, u8 *, 0) >= 3U) || ((u8) M2C_FIELD(D_8009C6DC, u8 *, 1) >= 6U)) {
            func_800429E0(0x4B, 0xC);
        }
    }
    if (((u8) D_80099FFC != 4) && (((u8) D_80099FFC != 5) || (D_80070788 != 0))) {
        func_800BB3A8();
    }
    if (D_80071E2C != 0) {
        func_8001F1BC(&D_80083274, 4, arg0, *D_8009C6E0 ^ 1);
    }
    func_800BC438(arg0);
}

void func_800BA7C4(void) {
    s32 i;
    s32 j;
    s32 off;
    u16 *p;
    u8 *q;

    ((FdScr *)D_8009C6E0)->b01 = 0;
    ((FdScr *)D_8009C6E0)->s02 = 0;
    ((FdScr *)D_8009C6E0)->s26 = 0;
    ((FdScr *)D_8009C6E0)->s28 = D_8009C6DC[3];
    ((FdScr *)D_8009C6E0)->s2A = 0;
    ((FdScr *)D_8009C6E0)->s2C = 0;
    ((FdScr *)D_8009C6E0)->s2E = 1;
    ((FdScr *)D_8009C6E0)->s30 = 2;
    ((FdScr *)D_8009C6E0)->b32 = 0;
    D_80081DC4 = 0;
    ((FdScr *)D_8009C6E0)->b33 = 0;
    ((FdScr *)D_8009C6E0)->b34 = 0;
    ((FdScr *)D_8009C6E0)->b35 = 0;
    ((FdScr *)D_8009C6E0)->b3B = 0;
    ((FdScr *)D_8009C6E0)->b36 = 0;
    ((FdScr *)D_8009C6E0)->b37 = 0;
    ((FdScr *)D_8009C6E0)->w48 = 0;
    ((FdScr *)D_8009C6E0)->w44 = 0;
    ((FdScr *)D_8009C6E0)->s40 = 0;
    ((FdScr *)D_8009C6E0)->s3E = 0;
    ((FdScr *)D_8009C6E0)->b3D = 0;
    ((FdScr *)D_8009C6E0)->b3C = 0;
    ((FdScr *)D_8009C6E0)->b12 = 0;
    ((FdScr *)D_8009C6E0)->b13 = 0;
    ((FdScr *)D_8009C6E0)->b14 = 0;
    ((FdScr *)D_8009C6E0)->s18 = 0;
    ((FdScr *)D_8009C6E0)->s1A = 0;
    ((FdScr *)D_8009C6E0)->b8A = 0;
    ((FdScr *)D_8009C6E0)->b98 = 0;
    ((FdScr *)D_8009C6E0)->b8B = 0;
    ((FdScr *)D_8009C6E0)->b99 = 0;
    ((FdScr *)D_8009C6E0)->s8E = 0;
    ((FdScr *)D_8009C6E0)->s9C = 0;
    ((FdScr *)D_8009C6E0)->s94 = 0;
    ((FdScr *)D_8009C6E0)->sA2 = 0;
    ((FdScr *)D_8009C6E0)->s96 = 0;
    ((FdScr *)D_8009C6E0)->sA4 = 0;
    ((FdScr *)D_8009C6E0)->b3A = 0;
    ((FdScr *)D_8009C6E0)->b1D = 0;
    ((FdScr *)D_8009C6E0)->s10 = *(u16 *)(D_8009C6DC + 8);
    for (i = 0; i < 0x100; i++) {
        D_80075E24[i] = 0;
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < D_8009C6DC[2]; j++) {
            D_80071748[j][i] = 0;
            D_800833F8[j][i] = 0;
            D_80071A88[j][i] = 0xFF;
            D_801142D4[j][i] = 0;
        }
    }
    for (i = 0; i < D_8009C6DC[2]; i++) {
        D_8009A1C4[i] = 7;
        D_8007EB98[i] = 0xFF;
        D_800716DC[i] = 0;
        D_80081D90[i] = 0;
        D_8007078C[i] = 0xFF;
        D_80114498[i] = 0;
    }
    for (i = 0; i < D_8009C6DC[3]; i++) {
        ((FdEntI *)D_8009C544)[i].s66 = 0;
        ((FdEntI *)D_8009C544)[i].w0C = 0;
        ((FdEntI *)D_8009C544)[i].w10 = 0;
        ((FdEntI *)D_8009C544)[i].w14 = 0;
        ((FdEntI *)D_8009C544)[i].s72 = 0;
        ((FdEntI *)D_8009C544)[i].s74 = 0;
        ((FdEntI *)D_8009C544)[i].b36 = 0;
        ((FdEntI *)D_8009C544)[i].b38 = 0;
        ((FdEntI *)D_8009C544)[i].b3B = 0;
        ((FdEntI *)D_8009C544)[i].b39 = 0;
        ((FdEntI *)D_8009C544)[i].b3A = 0;
        ((FdEntI *)D_8009C544)[i].s3C = 0;
        ((FdEntI *)D_8009C544)[i].s3E = 0;
        ((FdEntI *)D_8009C544)[i].s40 = 0;
        ((FdEntI *)D_8009C544)[i].s46 = 0;
        ((FdEntI *)D_8009C544)[i].s4C = 0;
        ((FdEntI *)D_8009C544)[i].s42 = 0;
        ((FdEntI *)D_8009C544)[i].s48 = 0;
        ((FdEntI *)D_8009C544)[i].s4E = 0;
        ((FdEntI *)D_8009C544)[i].s44 = 0;
        ((FdEntI *)D_8009C544)[i].s4A = 0;
        ((FdEntI *)D_8009C544)[i].s50 = 0;
        ((FdEntI *)D_8009C544)[i].s52 = 0;
        ((FdEntI *)D_8009C544)[i].s54 = 0;
        ((FdEntI *)D_8009C544)[i].b56 = 0;
        ((FdEntI *)D_8009C544)[i].b5E = 0;
        ((FdEntI *)D_8009C544)[i].s60 = 0x10;
        ((FdEntI *)D_8009C544)[i].w78 = 0;
        ((FdEntI *)D_8009C544)[i].w7C = 0;
        ((FdEntI *)D_8009C544)[i].w80 = 0;
        ((FdEntI *)D_8009C544)[i].s62 = 0;
        ((FdEntI *)D_8009C544)[i].s64 = 0;
        ((FdEntI *)D_8009C544)[i].b5C = 0;
        ((FdEntI *)D_8009C544)[i].s70 = ((FdScr *)D_8009C6E0)->s10 * 2;
        ((FdEntI *)D_8009C544)[i].b5D = 0;
        ((FdEntI *)D_8009C544)[i].s68 = 0;
        ((FdEntI *)D_8009C544)[i].s6A = 0;
        ((FdEntI *)D_8009C544)[i].b5A = 0;
        ((FdEntI *)D_8009C544)[i].b58 = 0;
        ((FdEntI *)D_8009C544)[i].b59 = 0;
        ((FdEntI *)D_8009C544)[i].b5B = 0;
        ((FdEntI *)D_8009C544)[i].b37 = 0;
        ((FdEntI *)D_8009C544)[i].s6C = ((FdScr *)D_8009C6E0)->s10 * 0x1E / 512;
        ((FdEntI *)D_8009C544)[i].s6E = ((FdScr *)D_8009C6E0)->s10 * 0x50 / 512;
        D_8008325C[i] = 0;
        D_800756E8[i] = 0;
        D_8009D828[i] = 0x10;
        D_80082248[i] = 0x10;
        ((FdEntI *)D_8009C544)[i].s00 = 0;
        ((FdEntI *)D_8009C544)[i].s02 = 0;
        ((FdEntI *)D_8009C544)[i].w04 = 0;
        ((FdEntI *)D_8009C544)[i].b08 = 0;
        ((FdEntI *)D_8009C544)[i].b09 = 0;
    }
    for (i = 0; i < 0x40; i++) {
        (D_8009C6E0 + i)[0xF2] = 0;
    }
    for (i = 0; i < 0x40; i++) {
        (D_8009C6E0 + i)[0xB2] = 0;
    }
    for (i = 0; i < 0x40; i++) {
        p = (u16 *)(D_80095DE0 + i * 0x20);
        for (j = 0; j < 0x10; j++) {
            p[j] = 0;
        }
    }
    for (i = 0, off = 0; i < 0x20; i++) {
        D_8007E7BD[off] = 0;
        D_8007E7BC[off] = 0;
        D_8007E7BB[off] = 0;
        D_8007E7BA[off] = 0;
        D_8007E7BE[off] = 0;
        D_8007E7BE[off + 1] = 0;
        ((u8 *)D_8007E7B8)[off] = 0;
        ((u8 *)D_8007E7B8)[off + 1] = 0;
        D_8007E7C2[off] = 0;
        *(s16 *)((u8 *)D_8007E7AC + off) = 0;
        *(s16 *)((u8 *)D_8007E7AC + off + 2) = 0;
        *(s16 *)(D_8007E7B0 + off) = 0;
        *(s16 *)(D_8007E7B0 + off + 2) = 0;
        *(s16 *)(D_8007E7B4 + off) = 0;
        *(s16 *)(D_8007E7B4 + off + 2) = 0;
        off += 0x18;
    }
    D_80095D84 = 0;
    for (i = 0; i < 9; i++) {
        D_8009AD30[i] = 0xFF;
    }
    q = &D_8009D2A7;
    D_800E48F0 = 0xFF;
    D_80071C1C = 0;
    *q |= 3;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BAF54);

void func_800BB1B4(void) {
    s16 i;
    s16 j;
    u8 c;
    u8 m;
    s32 e;

    for (i = 0; i < 3; i++) {
        c = D_8009D391[i];
        if (c != 0xFF) {
            m = D_8009AD30[c];
            if (m != 0xFF) {
                e = D_8007EB98[m];
                if (e != 0xFF && e < M2C_FIELD(D_8007E770, u16 *, 2)) {
                    M2C_FIELD(e * 8 + D_8008357C, s8 *, 5) = 1;
                }
            }
        }
    }
    for (i = 0; i < M2C_FIELD(D_8007E770, u16 *, 2); i++) {
        if (M2C_FIELD(i * 8 + D_8008357C, u8 *, 5) == 0) {
            for (j = 0; j < D_8009C6DC[2]; j++) {
                e = D_8007EB98[j];
                if (e == i) {
                    D_8007EB98[j] = 0xFF;
                    D_8009C544[e * 0x84 + 0x5C] = 0;
                    D_8009C544[e * 0x84 + 0x59] = 1;
                    D_8009C544[e * 0x84 + 0x5B] = 1;
                }
            }
        }
    }
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A013C);

s32 func_800BB3A8(void) {
    u16 h;
    u16 s;
    s32 n;
    s32 i;
    s32 m;
    s32 j;
    u8 *p;
    volatile u32 *t1;
    volatile u32 *t2;

    t1 = &D_8009D264;
    h = *t1 / 3600;
    i = 0;
    if (h >= 0x100) {
        h = 0xFF;
    }
    D_8009D298 = h;
    h = *t1 % 3600;
    D_8009D299 = h / 60;
    s = h % 60;
    if (D_8009D29A != s) {
        D_8009D29A = s;
        D_8009D29B = 0;
    } else {
        D_8009D29B += 1;
    }
    t2 = &D_8009D268;
    h = *t2 / 3600;
    if (h >= 0x100) {
        h = 0xFF;
    }
    D_8009D29C = h;
    h = *t2 % 3600;
    D_8009D29D = h / 60;
    s = h % 60;
    if (D_8009D29E != s) {
        D_8009D29E = s;
        D_8009D29F = 0x1E;
    } else if (D_8009D29F != 0) {
        D_8009D29F--;
    }
    n = D_8009C6DC[3];
    for (j = 0; j < n; j++) {
        p = D_8009C544 + j * 0x84;
        if (p[0x5A] != 0) {
            if (D_8009C6E0[0x32] == 0 && i == 0) {
                func_800BBF74(p[0x57], 1, 1);
                i = 1;
            }
            D_8009C544[j * 0x84 + 0x5A] = 0;
        }
        p = D_8009C544 + j * 0x84;
        if (p[0x58] != 0) {
            func_800BBF74(p[0x57], 1, 2);
            D_8009C544[j * 0x84 + 0x58] = 0;
        }
    }
    for (i = 0; i < D_80095D84; i++) {
        if (D_8007E7B8[i].pad3[2] != 0) {
            if (D_8009C6E0[0x32] == 0) {
                func_800BBF74(D_8007E7B8[i].x1, 1, 1);
            }
            D_8007E7B8[i].pad3[2] = 0;
        }
        if (D_8007E7B8[i].pad3[1] != 0) {
            func_800BBF74(D_8007E7B8[i].x1, 1, 2);
            D_8007E7B8[i].pad3[1] = 0;
        }
        if (D_8007E7B8[i].pad3[0] != 0) {
            func_800BBF74(D_8007E7B8[i].x1, 1, 3);
            D_8007E7B8[i].pad3[0] = 0;
        }
        if (D_8007E7B8[i].pad3[3] != 0) {
            func_800BBF74(D_8007E7B8[i].x1, 1, 5);
            D_8007E7B8[i].pad3[3] = 0;
        }
        if (D_8007E7B8[i].pad3[4] != 0) {
            func_800BBF74(D_8007E7B8[i].x1, 1, 6);
            D_8007E7B8[i].pad3[4] = 0;
        }
        if (D_8007E7B8[i].x2 != 0) {
            func_800BBF74(D_8007E7B8[i].x1, 1, 4);
        }
    }
    n = D_8009C6DC[2];
    do {
        if (D_800722C4 >= D_8009C6DC[2]) {
            D_800722C4 = 0;
        }
        if ((u8)D_80071E24 & 3) {
            func_800BC9FC(4, D_800722C4);
        }
        if (D_80081D90[D_800722C4] == 0 || D_800E48F0 == D_800722C4) {
            m = 8;
            do {
                if ((u8)D_80099FFC == 5 && (D_8009D820 & 1) && (!((u8)D_80071E24 & 4) || D_80114498[D_800722C4] != 0)) {
                    i = 1;
                    do {
                        func_800DA124(3, i, &D_800A013C);
                        i++;
                    } while (i < 9);
                }
                D_8009A058 = D_8009C6DC[D_800831FC[D_800722C4]];
                if (D_800E0228[D_8009A058]() != 0) {
                    if ((u8)D_80099FFC == 5 && (D_8009D820 & 1) && (!((u8)D_80071E24 & 4) || D_80114498[D_800722C4] != 0)) {
                        D_800722C4 = D_800722C4 + 1;
                        goto out;
                    }
                    break;
                }
                if ((u8)D_80099FFC == 5 && (D_8009D820 & 1) && (!((u8)D_80071E24 & 4) || D_80114498[D_800722C4] != 0)) {
                    D_8009A064 += 1;
                    if (D_8009A064 >= 8) {
                        D_8009A064 = 0;
                        D_800722C4 = D_800722C4 + 1;
                    }
                    goto out;
                }
                m -= 1;
            } while (m != 0);
        }
        D_800722C4 += 1;
        n -= 1;
        if ((u8)D_80099FFC == 5 && ((u8)D_80071E24 & 1) && (!((u8)D_80071E24 & 4) || D_80114498[D_800722C4] != 0)) {
            break;
        }
    } while (n != 0);
out:
    if ((u8)D_80099FFC == 5) {
        D_80070788 = 0;
    }
    return func_800BBBCC();
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BBBCC);

u8 func_800BBF74(s16 arg0, s16 arg1, s16 arg2) {
    s16 sub;
    u16 pc;
    u8 r;
    s32 c;
    u8 *act;

    if (D_8009D820 & 3) {
        sub = arg2 - 1;
        switch (sub) {
        case 0:
            func_800DA334(&D_800E4288, "Talk=");
            break;
        case 1:
            func_800DA334(&D_800E4288, "Push=");
            break;
        case 2:
            func_800DA334(&D_800E4288, "Acrs=");
            break;
        case 3:
            func_800DA334(&D_800E4288, "Toch=");
            break;
        case 4:
            func_800DA334(&D_800E4288, "TochON =");
            break;
        case 5:
            func_800DA334(&D_800E4288, "TochOFF=");
            break;
        }
        func_800DA368(&D_800E4288, &D_8009C6DC[arg0 * 8 + 0x20]);
        func_800BECA4(&D_800E4288, 0, 0);
    }
    if (D_8009A1C4[arg0] > arg1) {
        r = D_800833F8[arg0][arg1];
        if (r == 0) {
            pc = D_8009C6DC[arg2 * 2 + (D_8009C6DC[2] * 8 + arg0 * 64) + (s16)(*(u16 *)(D_8009C6DC + 6) * 4) + 0x20];
            pc |= (((u8 *)((arg0 * 64 + D_8009C6DC[2] * 8) + (s32)D_8009C6DC + arg2 * 2 + (s16)(*(u16 *)(D_8009C6DC + 6) * 4)))[0x21] << 8);
            if (D_8009C6DC[pc] != 0) {
                D_801142D4[arg0][arg1] = arg2;
                D_80071748[arg0][D_8009A1C4[arg0]] = D_800831FC[arg0];
                D_800831FC[arg0] = pc;
                c = D_8007EB98[arg0];
                D_8009A1C4[arg0] = arg1;
                if (c != 0xFF) {
                    act = D_8009C544 + c * 0x84;
                    if (act[0x5D] == 1) {
                        act[0x5E] = 0;
                        *(s16 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0x62) = 0;
                        *(s16 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0x64) = 0;
                    }
                    (D_8009C544 + D_8007EB98[arg0] * 0x84)[0x5D] = 0;
                }
                D_800716DC[arg0] = 0;
                if (D_8009D820 & 3) {
                    func_800BECA4("=recieved", 0, 0);
                }
                return 1;
            }
            if (D_8009D820 & 3) {
                func_800BECA4("=ret", 0, 0);
            }
            return 1;
        }
        return r;
    }
    if (D_8009D820 & 3) {
        func_800BECA4("=ignored", 0, 0);
    }
    return 0;
}

void func_800BC338(void) {
    s16 tp;

    D_80114464 = 0x7FFF;
    D_80114468 = 0x7FFF;
    D_80114490 = 0;
    D_800E48F4[0].len = 9;
    D_800E48F4[0].code = 0x2C;
    D_800E48F4[1].len = 9;
    D_800E48F4[1].code = 0x2C;
    D_800E48F4[0].code &= ~2;
    D_800E48F4[1].code &= ~2;
    D_800E48F4[0].code |= 1;
    D_800E48F4[1].code |= 1;
    if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
        tp = 0x2F;
    } else {
        tp = 0x1F;
    }
    D_800E48F4[0].tpage = D_800E48F4[1].tpage = tp;
    D_800E48F4[0].clut = D_800E48F4[1].clut = 0x7850;
    D_800E48F4[0].r0 = 0;
    D_800E48F4[1].r0 = 0;
    D_800E48F4[0].g0 = 0;
    D_800E48F4[1].g0 = 0;
    D_800E48F4[0].b0 = 0;
    D_800E48F4[1].b0 = 0;
}

void func_800BC438(s32 arg0) {
    u8 *p;
    u8 *q;
    if (M2C_FIELD(D_8009C6E0, s32 *, 0x80) & 0x100) {
        p = &D_8009D5A6;
        *p ^= 1;
    }
    q = &D_8009D5A6;
    if (((*q == 1) && (M2C_FIELD(D_8009C6E0, u8 *, 0x32) == 0)) || (*q & 2)) {
        func_800BC4D4(arg0);
    }
}

void func_800BC4D4(FdTag *arg0) {
    s16 x;
    s16 y;

    if (D_80071C1C != 0) {
        return;
    }
    if (D_80114464 == 0x7FFF && D_80114468 == D_80114464) {
        return;
    }
    x = D_80114464;
    if (D_80114464 >= 0x141) {
        x = 0x140;
    }
    if (D_80114464 < 0) {
        x = 0;
    }
    if (D_80114468 >= 0xE1) {
        y = 0xE0;
    } else {
        y = D_80114468;
    }
    if (D_80114468 < 0) {
        y = 0;
    }
    D_80114490 ^= 1;
    if (x >= 0x123) {
        D_800E48F4[D_80114490].u0 = 0x8F;
        D_800E48F4[D_80114490].u1 = 0x7F;
        D_800E48F4[D_80114490].u2 = 0x8F;
        D_800E48F4[D_80114490].u3 = 0x7F;
        D_800E48F4[D_80114490].x0 = x - 0x10;
        D_800E48F4[D_80114490].x1 = x;
        D_800E48F4[D_80114490].x2 = x - 0x10;
        D_800E48F4[D_80114490].x3 = x;
    } else {
        D_800E48F4[D_80114490].u0 = 0x80;
        D_800E48F4[D_80114490].u1 = 0x90;
        D_800E48F4[D_80114490].u2 = 0x80;
        D_800E48F4[D_80114490].u3 = 0x90;
        D_800E48F4[D_80114490].x0 = x;
        D_800E48F4[D_80114490].x1 = x + 0x10;
        D_800E48F4[D_80114490].x2 = x;
        D_800E48F4[D_80114490].x3 = x + 0x10;
    }
    if (y < 0x11) {
        D_800E48F4[D_80114490].v0 = 0x6F;
        D_800E48F4[D_80114490].v1 = 0x6F;
        D_800E48F4[D_80114490].v2 = 0x5F;
        D_800E48F4[D_80114490].v3 = 0x5F;
        D_800E48F4[D_80114490].y0 = y;
        D_800E48F4[D_80114490].y1 = y;
        D_800E48F4[D_80114490].y2 = y + 0x10;
        D_800E48F4[D_80114490].y3 = y + 0x10;
    } else {
        D_800E48F4[D_80114490].v0 = 0x60;
        D_800E48F4[D_80114490].v1 = 0x60;
        D_800E48F4[D_80114490].v2 = 0x70;
        D_800E48F4[D_80114490].v3 = 0x70;
        D_800E48F4[D_80114490].y0 = y - 0x10;
        D_800E48F4[D_80114490].y1 = y - 0x10;
        D_800E48F4[D_80114490].y2 = y;
        D_800E48F4[D_80114490].y3 = y;
    }
    ((FdTag *)&D_800E48F4[D_80114490])->addr = ((FdTag *)arg0)->addr;
    ((FdTag *)arg0)->addr = (u32)&D_800E48F4[D_80114490];
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BC9FC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0270);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0274);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0278);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A027C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0288);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A028C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0290);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A029C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02A8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02B4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02B8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02BC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02C0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02C4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02C8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02CC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02D0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02D4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02D8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02DC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02E0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02E4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02E8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02EC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02F0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02F4);

void func_800BEAD4(char *name, s32 n) {
    s32 i;
    s32 end;

    if (!(D_80071E24 & 4) || D_80114498[D_800722C4] != 0) {
        func_800DA334(&D_800E4254, D_800E0630);
        func_800DA368(&D_800E4254, name);
        if (D_8009D820 & 1) {
            func_800DA124(3, 0, &D_800E4254);
        }
        if (D_8009D820 & 2) {
            func_800D4840(&D_800E4254);
        }
        end = n + 1;
        for (; n != 0; n--) {
            i = end - n;
            func_800DA334(&D_800E4254, "arg");
            func_800DA424(i, &D_800E4288);
            func_800DA368(&D_800E4254, &D_800E4288);
            func_800DA368(&D_800E4254, "=");
            func_800DA444((D_8009C6DC + D_800831FC[D_800722C4])[i], &D_800E4288);
            func_800DA368(&D_800E4254, &D_800E4288);
            if (D_8009D820 & 1) {
                func_800DA124(3, i, &D_800E4254);
            }
            if (D_8009D820 & 2) {
                func_800D4840(&D_800E4254);
            }
        }
    }
}

void func_800BECA4(char *arg0, s32 arg1, s32 arg2) {
    if (!(D_80071E24 & 4) || D_80114498[D_800722C4] != 0) {
        func_800DA334(&D_800E4254, arg0);
        switch (arg2) {
        case 1:
            func_800DA424(arg1, &D_800E4288);
            break;
        case 2:
            func_800DA444(arg1, &D_800E4288);
            break;
        case 4:
            func_800DA480(arg1, &D_800E4288);
            break;
        default:
            func_800DA334(&D_800E4288, D_800A0270);
            break;
        }
        func_800DA368(&D_800E4254, &D_800E4288);
        if (D_8009D820 & 1) {
            func_800D9F00(2, (s32)&D_800E4254);
        }
        if (D_8009D820 & 2) {
            func_800D4840(&D_800E4254);
        }
    }
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0300);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0308);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0310);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0318);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0320);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A032C);

s32 func_800BEE10(s16 arg0, s16 arg1) {
    s16 sub;
    u8 v;
    s32 i;
    s32 r;

    sub = arg0 - 1;
    switch (sub) {
    case 0:
        v = (D_8009C6DC + D_800831FC[D_800722C4])[1] >> 4;
        break;
    case 1:
        v = (D_8009C6DC + D_800831FC[D_800722C4])[1] & 0xF;
        break;
    case 2:
        v = (D_8009C6DC + D_800831FC[D_800722C4])[2] >> 4;
        break;
    case 3:
        v = (D_8009C6DC + D_800831FC[D_800722C4])[2] & 0xF;
        break;
    case 4:
        v = (D_8009C6DC + D_800831FC[D_800722C4])[3] >> 4;
        break;
    case 5:
        v = (D_8009C6DC + D_800831FC[D_800722C4])[3] & 0xF;
        break;
    }
    switch (v) {
    case 0:
        r = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0300, r, 2);
        }
        break;
    case 1:
    case 2:
        i = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        r = D_8009D288[i];
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, i, 4);
            func_800BECA4(D_800A0310, r, 2);
        }
        break;
    case 3:
    case 4:
        i = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x100;
        r = D_8009D288[i];
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, i, 4);
            func_800BECA4(D_800A0310, r, 2);
        }
        break;
    case 11:
    case 12:
        i = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x200;
        r = D_8009D288[i];
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, i, 4);
            func_800BECA4(D_800A0310, r, 2);
        }
        break;
    case 13:
    case 14:
        i = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x300;
        r = D_8009D288[i];
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, i, 4);
            func_800BECA4(D_800A0310, r, 2);
        }
        break;
    case 7:
    case 15:
        i = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x400;
        r = D_8009D288[i];
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, i, 4);
            func_800BECA4(D_800A0310, r, 2);
        }
        break;
    case 5:
    case 6:
        i = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        r = D_80075E24[i];
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, i, 4);
            func_800BECA4(D_800A0318, r, 2);
        }
        break;
    default:
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0320, v, 2);
        }
        func_800D4848((s32)D_800A032C);
        return 0;
    }
    return r;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0394);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A039C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A03A4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A03AC);

void func_800BF3AC(s16 arg0, s16 arg1, u8 arg2) {
    s16 sub;
    u8 v;
    s32 i;

    sub = arg0 - 1;
    switch (sub) {
    case 0:
        v = (D_8009C6DC + D_800831FC[D_800722C4])[1] >> 4;
        break;
    case 1:
        v = (D_8009C6DC + D_800831FC[D_800722C4])[1] & 0xF;
        break;
    case 2:
        v = (D_8009C6DC + D_800831FC[D_800722C4])[2] >> 4;
        break;
    case 3:
        v = (D_8009C6DC + D_800831FC[D_800722C4])[2] & 0xF;
        break;
    case 4:
        v = (D_8009C6DC + D_800831FC[D_800722C4])[3] >> 4;
        break;
    case 5:
        v = (D_8009C6DC + D_800831FC[D_800722C4])[3] & 0xF;
        break;
    }
    switch (v) {
    case 1:
    case 2:
        i = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        D_8009D288[i] = arg2;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, i, 4);
            func_800BECA4(D_800A039C, arg2, 2);
        }
        break;
    case 3:
    case 4:
        i = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x100;
        D_8009D288[i] = arg2;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, i, 4);
            func_800BECA4(D_800A039C, arg2, 2);
        }
        break;
    case 11:
    case 12:
        i = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x200;
        D_8009D288[i] = arg2;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, i, 4);
            func_800BECA4(D_800A039C, arg2, 2);
        }
        break;
    case 13:
    case 14:
        i = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x300;
        D_8009D288[i] = arg2;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, i, 4);
            func_800BECA4(D_800A039C, arg2, 2);
        }
        break;
    case 7:
    case 15:
        i = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x400;
        D_8009D288[i] = arg2;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, i, 4);
            func_800BECA4(D_800A039C, arg2, 2);
        }
        break;
    case 5:
    case 6:
        i = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        D_80075E24[i] = arg2;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, i, 4);
            func_800BECA4(D_800A03A4, arg2, 2);
        }
        break;
    default:
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A03AC, v, 2);
        }
        func_800D4848((s32)D_800A032C);
        break;
    }
}

u32 func_800BF908(s16 arg0, s16 arg1) {
    u8 op;
    s32 idx;
    s32 val;

    switch (arg0) {
    case 1:
        op = (D_8009C6DC + D_800831FC[D_800722C4])[1] >> 4;
        break;
    case 2:
        op = (D_8009C6DC + D_800831FC[D_800722C4])[1] & 0xF;
        break;
    case 3:
        op = (D_8009C6DC + D_800831FC[D_800722C4])[2] >> 4;
        break;
    case 4:
        op = (D_8009C6DC + D_800831FC[D_800722C4])[2] & 0xF;
        break;
    case 5:
        op = (D_8009C6DC + D_800831FC[D_800722C4])[3] >> 4;
        break;
    case 6:
        op = (D_8009C6DC + D_800831FC[D_800722C4])[3] & 0xF;
        break;
    }
    switch (op) {
    case 0:
        val = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        val |= (D_8009C6DC + D_800831FC[D_800722C4])[arg1 + 1] << 8;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0300, (s16)val, 4);
        }
        return (s16)val;
    case 1:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        val = D_8009D288[idx];
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, idx, 4);
            func_800BECA4(D_800A0310, val, 4);
        }
        return val;
    case 2:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        val = D_8009D288[idx];
        val |= D_8009D289[idx] << 8;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, idx, 4);
            func_800BECA4(D_800A0310, (s16)val, 4);
        }
        return (s16)val;
    case 3:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x100;
        val = D_8009D288[idx];
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, idx, 4);
            func_800BECA4(D_800A0310, val, 4);
        }
        return val;
    case 4:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x100;
        val = D_8009D288[idx];
        val |= D_8009D289[idx] << 8;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, idx, 4);
            func_800BECA4(D_800A0310, (s16)val, 4);
        }
        return (s16)val;
    case 0xB:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x200;
        val = D_8009D288[idx];
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, idx, 4);
            func_800BECA4(D_800A0310, val, 4);
        }
        return val;
    case 0xC:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x200;
        val = D_8009D288[idx];
        val |= D_8009D289[idx] << 8;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, idx, 4);
            func_800BECA4(D_800A0310, (s16)val, 4);
        }
        return (s16)val;
    case 0xD:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x300;
        val = D_8009D288[idx];
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, idx, 4);
            func_800BECA4(D_800A0310, val, 4);
        }
        return val;
    case 0xE:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x300;
        val = D_8009D288[idx];
        val |= D_8009D289[idx] << 8;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, idx, 4);
            func_800BECA4(D_800A0310, (s16)val, 4);
        }
        return (s16)val;
    case 0xF:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x400;
        val = D_8009D288[idx];
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, idx, 4);
            func_800BECA4(D_800A0310, val, 4);
        }
        return val;
    case 7:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x400;
        val = D_8009D288[idx];
        val |= D_8009D289[idx] << 8;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, idx, 4);
            func_800BECA4(D_800A0310, (s16)val, 4);
        }
        return (s16)val;
    case 5:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        val = D_80075E24[idx];
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, idx, 4);
            func_800BECA4(D_800A0318, val, 4);
        }
        return val;
    case 6:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        val = D_80075E24[idx];
        val |= D_80075E24[idx + 1] << 8;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0308, idx, 4);
            func_800BECA4(D_800A0318, (s16)val, 4);
        }
        return (s16)val;
    default:
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0320, op, 2);
        }
        func_800D4848(D_800A032C);
        return 0;
    }
}

void func_800C0248(s16 arg0, s16 arg1, s16 arg2) {
    u8 op;
    s32 idx;

    switch (arg0) {
    case 1:
        op = (D_8009C6DC + D_800831FC[D_800722C4])[1] >> 4;
        break;
    case 2:
        op = (D_8009C6DC + D_800831FC[D_800722C4])[1] & 0xF;
        break;
    case 3:
        op = (D_8009C6DC + D_800831FC[D_800722C4])[2] >> 4;
        break;
    case 4:
        op = (D_8009C6DC + D_800831FC[D_800722C4])[2] & 0xF;
        break;
    case 5:
        op = (D_8009C6DC + D_800831FC[D_800722C4])[3] >> 4;
        break;
    case 6:
        op = (D_8009C6DC + D_800831FC[D_800722C4])[3] & 0xF;
        break;
    }
    switch (op) {
    case 1:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        D_8009D288[idx] = arg2;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, idx, 4);
            func_800BECA4(D_800A039C, arg2, 2);
        }
        break;
    case 2:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        D_8009D288[idx] = arg2;
        D_8009D289[idx] = arg2 >> 8;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, idx, 4);
            func_800BECA4(D_800A039C, arg2, 4);
        }
        break;
    case 3:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x100;
        D_8009D288[idx] = arg2;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, idx, 4);
            func_800BECA4(D_800A039C, arg2, 2);
        }
        break;
    case 4:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x100;
        D_8009D288[idx] = arg2;
        D_8009D289[idx] = arg2 >> 8;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, idx, 4);
            func_800BECA4(D_800A039C, arg2, 4);
        }
        break;
    case 0xB:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x200;
        D_8009D288[idx] = arg2;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, idx, 4);
            func_800BECA4(D_800A039C, arg2, 2);
        }
        break;
    case 0xC:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x200;
        D_8009D288[idx] = arg2;
        D_8009D289[idx] = arg2 >> 8;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, idx, 4);
            func_800BECA4(D_800A039C, arg2, 4);
        }
        break;
    case 0xD:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x300;
        D_8009D288[idx] = arg2;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, idx, 4);
            func_800BECA4(D_800A039C, arg2, 2);
        }
        break;
    case 0xE:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x300;
        D_8009D288[idx] = arg2;
        D_8009D289[idx] = arg2 >> 8;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, idx, 4);
            func_800BECA4(D_800A039C, arg2, 4);
        }
        break;
    case 0xF:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x400;
        D_8009D288[idx] = arg2;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, idx, 4);
            func_800BECA4(D_800A039C, arg2, 2);
        }
        break;
    case 7:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1] | 0x400;
        D_8009D288[idx] = arg2;
        D_8009D289[idx] = arg2 >> 8;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, idx, 4);
            func_800BECA4(D_800A039C, arg2, 4);
        }
        break;
    case 5:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        D_80075E24[idx] = arg2;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, idx, 4);
            func_800BECA4(D_800A03A4, arg2, 2);
        }
        break;
    case 6:
        idx = (D_8009C6DC + D_800831FC[D_800722C4])[arg1];
        D_80075E24[idx] = arg2;
        D_80075E24[idx + 1] = arg2 >> 8;
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0394, idx, 4);
            func_800BECA4(D_800A03A4, arg2, 4);
        }
        break;
    default:
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A03AC, op, 2);
        }
        func_800D4848(D_800A032C);
        break;
    }
}

s32 func_800C0B54(void) {
    if (D_8009D820 & 3) {
        func_800DA444(D_8009A058, &D_800E4288);
        func_800DA368(&D_800E4288, "???");
        func_800BEAD4(&D_800E4288, 8);
        func_800DA214(3, 0x7F, 0, 0);
    } else {
        func_800D4848((s32) "Bad Event code!");
    }
    return 1;
}

s32 func_800C0BE8(void) {
    D_800831FC[D_800722C4]++;
    return 1;
}

s32 func_800C0C18(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("wait", 2);
    }
    if (D_800716DC[D_800722C4] == 0) {
        pc = &D_800831FC[D_800722C4];
        D_800716DC[D_800722C4] = (D_8009C6DC + *pc)[1];
        D_800716DC[D_800722C4] |= (D_8009C6DC + *pc)[2] << 8;
        if (D_8009D820 & 3) {
            func_800BECA4("wait_st=", D_800716DC[D_800722C4], 4);
        }
        if (D_800716DC[D_800722C4] != 0) {
            return 1;
        }
        D_800831FC[D_800722C4] += 3;
        return 1;
    } else if (D_800716DC[D_800722C4] == 1) {
        if (D_8009D820 & 3) {
            func_800BECA4("wait_end=", 1, 4);
        }
        D_800716DC[D_800722C4] = 0;
        D_800831FC[D_800722C4] += 3;
        return 0;
    } else {
        if (D_8009D820 & 3) {
            func_800BECA4("wait=", D_800716DC[D_800722C4], 4);
        }
        D_800716DC[D_800722C4]--;
        return 1;
    }
}

s32 func_800C0DE0(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("set", 3);
    }
    func_800BF3AC(1, 2, func_800BEE10(2, 3) & 0xFF);
    D_800831FC[D_800722C4] += 4;
    return 0;
}

s32 func_800C0E5C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("set2", 4);
    }
    func_800C0248(1, 2, func_800BF908(2, 3));
    D_800831FC[D_800722C4] += 5;
    return 0;
}

s32 func_800C0EDC(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("lbyte", 3);
    }
    func_800BF3AC(1, 2, func_800BEE10(2, 3) & 0xFF);
    D_800831FC[D_800722C4] += 4;
    return 0;
}

s32 func_800C0F58(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("hbyte", 4);
    }
    func_800BF3AC(1, 2, func_800BF908(2, 3) >> 8);
    D_800831FC[D_800722C4] += 5;
    return 0;
}

s32 func_800C0FD8(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("2byte", 5);
    }
    temp_s0 = func_800BEE10(2, 4) & 0xFF;
    func_800C0248(1, 3, (s16) (temp_s0 | ((func_800BEE10(4, 5) & 0xFF) << 8)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 6;
    return 0;
}

s32 func_800C107C(void) {
    s16 i;
    u32 bank;
    u8 v;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("setx", 6);
    }
    bank = (&D_8009C6DC[D_800831FC[D_800722C4]])[1] >> 4;
    i = (&D_8009C6DC[D_800831FC[D_800722C4]])[3] + func_800BF908(2, 3);
    v = func_800BEE10(4, 5);
    switch (bank) {
    case 15:
        i += 0x100;
    case 13:
        i += 0x100;
    case 11:
        i += 0x100;
    case 3:
        i += 0x100;
    case 1:
        if (i >= 0x500) {
            i = 0x4FF;
        }
        D_8009D288[i] = v;
        break;
    case 5:
        if (i >= 0x100) {
            i = 0xFF;
        }
        D_80075E24[i] = v;
        break;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 7;
    return 0;
}

s32 func_800C1214(void) {
    s16 i;
    u32 bank;
    u8 v;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("getx", 6);
    }
    bank = (&D_8009C6DC[D_800831FC[D_800722C4]])[1] >> 4;
    i = (&D_8009C6DC[D_800831FC[D_800722C4]])[3] + func_800BF908(2, 3);
    switch (bank) {
    case 15:
        i += 0x100;
    case 13:
        i += 0x100;
    case 11:
        i += 0x100;
    case 3:
        i += 0x100;
    case 1:
        if (i >= 0x500) {
            i = 0x4FF;
        }
        v = D_8009D288[i];
        break;
    case 5:
        if (i >= 0x100) {
            i = 0xFF;
        }
        v = D_80075E24[i];
        break;
    }
    func_800BF3AC(4, 5, v);
    pc = &D_800831FC[D_800722C4];
    *pc += 7;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C13B0);

s32 func_800C1674(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("biton", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 | (1 << func_800BEE10(2, 3))) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800C1714(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("bitof", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, temp_s0 & ~(1 << func_800BEE10(2, 3)) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800C17B8(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("bitxr", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 ^ (1 << func_800BEE10(2, 3))) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800C1858(void) {
    s32 v;

    if (D_8009D820 & 3) {
        func_800BEAD4("line", 8);
    }
    if (D_80095D84 >= 0x20) {
        func_800D4848("many lineobj!");
        D_800831FC[D_800722C4] += 0xD;
        return 0;
    } else {
        D_8007078C[D_800722C4] = D_80095D84;
        v = (D_8009C6DC + D_800831FC[D_800722C4])[1];
        v |= (D_8009C6DC + D_800831FC[D_800722C4])[2] << 8;
        D_8007E7AC[D_80095D84].a = v;
        v = (D_8009C6DC + D_800831FC[D_800722C4])[3];
        v |= (D_8009C6DC + D_800831FC[D_800722C4])[4] << 8;
        D_8007E7AC[D_80095D84].b = v;
        v = (D_8009C6DC + D_800831FC[D_800722C4])[5];
        v |= (D_8009C6DC + D_800831FC[D_800722C4])[6] << 8;
        D_8007E7AC[D_80095D84].c = v;
        v = (D_8009C6DC + D_800831FC[D_800722C4])[7];
        v |= (D_8009C6DC + D_800831FC[D_800722C4])[8] << 8;
        D_8007E7AC[D_80095D84].d = v;
        v = (D_8009C6DC + D_800831FC[D_800722C4])[9];
        v |= (D_8009C6DC + D_800831FC[D_800722C4])[0xA] << 8;
        D_8007E7AC[D_80095D84].e = v;
        v = (D_8009C6DC + D_800831FC[D_800722C4])[0xB];
        v |= (D_8009C6DC + D_800831FC[D_800722C4])[0xC] << 8;
        D_8007E7AC[D_80095D84].f = v;
        D_8007E7B8[D_80095D84].x0 = 1;
        D_8007E7B8[D_80095D84].x1 = D_800722C4;
        D_80095D84++;
        D_800831FC[D_800722C4] += 0xD;
        return 0;
    }
}

s32 func_800C1AB4(void) {
    u8 n;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("sline", 8);
    }
    n = D_8007078C[D_800722C4];
    D_8007E7AC[n].a = func_800BF908(1, 4);
    D_8007E7AC[n].b = func_800BF908(2, 6);
    D_8007E7AC[n].c = func_800BF908(3, 8);
    D_8007E7AC[n].d = func_800BF908(4, 0xA);
    D_8007E7AC[n].e = func_800BF908(5, 0xC);
    D_8007E7AC[n].f = func_800BF908(6, 0xE);
    pc = &D_800831FC[D_800722C4];
    *pc += 0x10;
    return 0;
}

s32 func_800C1BF4(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("linon", 1);
    }
    D_8007E7B8[D_8007078C[D_800722C4]].x0 = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    if ((D_8009C6DC + D_800831FC[D_800722C4])[1] == 0) {
        D_8007E7B8[D_8007078C[D_800722C4]].x2 = 0;
    }
    D_800831FC[D_800722C4] += 2;
    return 0;
}

s32 func_800C1D24(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("slip", 1);
    }
    D_8007E7C2[D_8007078C[D_800722C4] * 0x18] = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    pc = &D_800831FC[D_800722C4];
    *pc += 2;
    return 0;
}

s32 func_800C1DE4(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("if", 5);
    }
    if (func_800C2000() != 0) {
        if (D_8009D820 & 3) {
            func_800BECA4("if=true", 0, 0);
        }
        pc = &D_800831FC[D_800722C4];
        *pc += 6;
    } else {
        if (D_8009D820 & 3) {
            func_800BECA4("if=false", 0, 0);
        }
        D_800831FC[D_800722C4] += (D_8009C6DC + D_800831FC[D_800722C4])[5] + 5;
    }
    return 0;
}

s32 func_800C1EEC(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("lif", 6);
    }
    if (func_800C2000() != 0) {
        if (D_8009D820 & 3) {
            func_800BECA4("lif=true", 0, 0);
        }
        D_800831FC[D_800722C4] += 7;
    } else {
        if (D_8009D820 & 3) {
            func_800BECA4("lif=false", 0, 0);
        }
        p = &D_800831FC[D_800722C4];
        *p += ((D_8009C6DC + *p)[5] | ((D_8009C6DC + *p)[6] << 8)) + 5;
    }
    return 0;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0674);

s32 func_800C2000(void) {
    u8 v;
    u8 op;

    op = (D_8009C6DC + D_800831FC[D_800722C4])[4];
    switch (op) {
    case 0:
        v = ((func_800BEE10(1, 2) ^ func_800BEE10(2, 3)) & 0xFF) == 0;
        break;
    case 1:
        v = ((func_800BEE10(1, 2) ^ func_800BEE10(2, 3)) & 0xFF) != 0;
        break;
    case 2:
        v = (u32)(func_800BEE10(1, 2) & 0xFF) > (u32)(func_800BEE10(2, 3) & 0xFF);
        break;
    case 3:
        v = (u32)(func_800BEE10(1, 2) & 0xFF) < (u32)(func_800BEE10(2, 3) & 0xFF);
        break;
    case 4:
        v = (u32)(func_800BEE10(1, 2) & 0xFF) >= (u32)(func_800BEE10(2, 3) & 0xFF);
        break;
    case 5:
        v = (u32)(func_800BEE10(1, 2) & 0xFF) <= (u32)(func_800BEE10(2, 3) & 0xFF);
        break;
    case 6:
        v = func_800BEE10(1, 2) & func_800BEE10(2, 3);
        break;
    case 7:
        v = func_800BEE10(1, 2) ^ func_800BEE10(2, 3);
        break;
    case 8:
        v = func_800BEE10(1, 2) | func_800BEE10(2, 3);
        break;
    case 9:
        v = func_800BEE10(1, 2) & (1 << func_800BEE10(2, 3));
        break;
    case 10:
        v = func_800BEE10(1, 2) & (1 << func_800BEE10(2, 3));
        v = (v & 0xFF) == 0;
        break;
    default:
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0674, op, 2);
        }
        break;
    }
    return v;
}

s32 func_800C228C(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4(D_800A06B0, 7);
    }
    if (func_800C24A8() != 0) {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A06B4, 0, 0);
        }
        pc = &D_800831FC[D_800722C4];
        *pc += 8;
    } else {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A06C0, 0, 0);
        }
        D_800831FC[D_800722C4] += (D_8009C6DC + D_800831FC[D_800722C4])[7] + 7;
    }
    return 0;
}

s32 func_800C2394(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4(D_800A06CC, 8);
    }
    if (func_800C24A8() != 0) {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A06D4, 0, 0);
        }
        D_800831FC[D_800722C4] += 9;
    } else {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A06E0, 0, 0);
        }
        p = &D_800831FC[D_800722C4];
        *p += ((D_8009C6DC + *p)[7] | ((D_8009C6DC + *p)[8] << 8)) + 7;
    }
    return 0;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A06B0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A06B4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A06C0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A06CC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A06D4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A06E0);

s32 func_800C24A8(void) {
    u8 r;
    u8 op;

    op = M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 6);
    switch (op) {
    case 0:
        r = (s16)(func_800BF908(1, 2) ^ func_800BF908(2, 4)) == 0;
        break;
    case 1:
        r = (s16)(func_800BF908(1, 2) ^ func_800BF908(2, 4)) != 0;
        break;
    case 2:
        r = (s16)func_800BF908(1, 2) > (s16)func_800BF908(2, 4);
        break;
    case 3:
        r = (s16)func_800BF908(1, 2) < (s16)func_800BF908(2, 4);
        break;
    case 4:
        r = (s16)func_800BF908(1, 2) >= (s16)func_800BF908(2, 4);
        break;
    case 5:
        r = (s16)func_800BF908(1, 2) <= (s16)func_800BF908(2, 4);
        break;
    case 6:
        r = func_800BF908(1, 2) & func_800BF908(2, 4);
        break;
    case 7:
        r = func_800BF908(1, 2) ^ func_800BF908(2, 4);
        break;
    case 8:
        r = func_800BF908(1, 2) | func_800BF908(2, 4);
        break;
    case 9:
        r = func_800BF908(1, 2) & (1 << func_800BF908(2, 4));
        break;
    case 10:
        r = func_800BF908(1, 2) & (1 << func_800BF908(2, 4));
        r = r == 0;
        break;
    default:
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0674, op, 2);
        }
        break;
    }
    return r;
}

s32 func_800C2754(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4(D_800A06B0, 7);
    }
    if (func_800C2970() != 0) {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A06B4, 0, 0);
        }
        pc = &D_800831FC[D_800722C4];
        *pc += 8;
    } else {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A06C0, 0, 0);
        }
        D_800831FC[D_800722C4] += (D_8009C6DC + D_800831FC[D_800722C4])[7] + 7;
    }
    return 0;
}

s32 func_800C285C(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4(D_800A06CC, 8);
    }
    if (func_800C2970() != 0) {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A06D4, 0, 0);
        }
        D_800831FC[D_800722C4] += 9;
    } else {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A06E0, 0, 0);
        }
        p = &D_800831FC[D_800722C4];
        *p += ((D_8009C6DC + *p)[7] | ((D_8009C6DC + *p)[8] << 8)) + 7;
    }
    return 0;
}

s32 func_800C2970(void) {
    u8 v;
    u8 op;

    op = (D_8009C6DC + D_800831FC[D_800722C4])[6];
    switch (op) {
    case 0:
        v = ((func_800BF908(1, 2) ^ func_800BF908(2, 4)) & 0xFFFF) == 0;
        break;
    case 1:
        v = ((func_800BF908(1, 2) ^ func_800BF908(2, 4)) & 0xFFFF) != 0;
        break;
    case 2:
        v = (u32)(func_800BF908(1, 2) & 0xFFFF) > (u32)(func_800BF908(2, 4) & 0xFFFF);
        break;
    case 3:
        v = (u32)(func_800BF908(1, 2) & 0xFFFF) < (u32)(func_800BF908(2, 4) & 0xFFFF);
        break;
    case 4:
        v = (u32)(func_800BF908(1, 2) & 0xFFFF) >= (u32)(func_800BF908(2, 4) & 0xFFFF);
        break;
    case 5:
        v = (u32)(func_800BF908(1, 2) & 0xFFFF) <= (u32)(func_800BF908(2, 4) & 0xFFFF);
        break;
    case 6:
        v = func_800BF908(1, 2) & func_800BF908(2, 4);
        break;
    case 7:
        v = func_800BF908(1, 2) ^ func_800BF908(2, 4);
        break;
    case 8:
        v = func_800BF908(1, 2) | func_800BF908(2, 4);
        break;
    case 9:
        v = func_800BF908(1, 2) & (1 << func_800BF908(2, 4));
        break;
    case 10:
        v = func_800BF908(1, 2) & (1 << func_800BF908(2, 4));
        v = (v & 0xFF) == 0;
        break;
    default:
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A0674, op, 2);
        }
        break;
    }
    return v;
}

void func_800C2BFC(void) {
    u16 var_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("key!", 3);
    }
    if (!(M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 2) & 2)) {
        var_a0 = M2C_FIELD(D_8009C6E0, u16 *, 0x68);
    } else {
        var_a0 = M2C_FIELD(D_8009C6E0, u16 *, 0x78);
    }
    func_800C2E00(var_a0);
}

void func_800C2CA8(void) {
    u16 var_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("keyon", 3);
    }
    if (!(M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 2) & 2)) {
        var_a0 = M2C_FIELD(D_8009C6E0, u16 *, 0x70);
    } else {
        var_a0 = M2C_FIELD(D_8009C6E0, u16 *, 0x80);
    }
    func_800C2E00(var_a0);
}

void func_800C2D54(void) {
    u16 var_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("keyof", 3);
    }
    if (!(M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 2) & 2)) {
        var_a0 = M2C_FIELD(D_8009C6E0, u16 *, 0x74);
    } else {
        var_a0 = M2C_FIELD(D_8009C6E0, u16 *, 0x84);
    }
    func_800C2E00(var_a0);
}

s32 func_800C2E00(u16 arg0) {
    u16 key;
    u16 *pc;

    key = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    key |= (D_8009C6DC + D_800831FC[D_800722C4])[2] << 8;
    if (D_8009D820 & 3) {
        func_800BECA4("key now=", arg0, 4);
        func_800BECA4("key chk=", key, 4);
    }
    if (arg0 & key) {
        if (D_8009D820 & 3) {
            func_800BECA4("key=true", 0, 0);
        }
        D_800831FC[D_800722C4] += 4;
    } else {
        if (D_8009D820 & 3) {
            func_800BECA4("key=false", 0, 0);
        }
        pc = &D_800831FC[D_800722C4];
        *pc += (D_8009C6DC + *pc)[3] + 3;
    }
    return 0;
}

void func_800C2F7C(void) {
    u16 i;

    if (D_8009D820 & 3) {
        func_800BEAD4("req", 2);
    }
    i = D_800831FC[D_800722C4];
    func_800C33B4(1, ((volatile u8 *)D_8009C6DC + i)[1], ((volatile u8 *)D_8009C6DC + i)[2] >> 5, ((volatile u8 *)D_8009C6DC + i)[2] & 0x1F);
}

void func_800C2FFC(void) {
    u16 i;

    if (D_8009D820 & 3) {
        func_800BEAD4("reqsw", 2);
    }
    i = D_800831FC[D_800722C4];
    func_800C33B4(2, ((volatile u8 *)D_8009C6DC + i)[1], ((volatile u8 *)D_8009C6DC + i)[2] >> 5, ((volatile u8 *)D_8009C6DC + i)[2] & 0x1F);
}

void func_800C307C(void) {
    u16 i;

    if (D_8009D820 & 3) {
        func_800BEAD4("reqew", 2);
    }
    i = D_800831FC[D_800722C4];
    func_800C33B4(3, ((volatile u8 *)D_8009C6DC + i)[1], ((volatile u8 *)D_8009C6DC + i)[2] >> 5, ((volatile u8 *)D_8009C6DC + i)[2] & 0x1F);
}

void func_800C30FC(void) {
    u8 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("preq", 2);
    }
    c = D_8009D391[(D_8009C6DC + D_800831FC[D_800722C4])[1]];
    if (c == 0xFF) {
        c = 0xFF;
    } else {
        c = D_8009AD30[c];
    }
    func_800C33B4(1, c, (D_8009C6DC + D_800831FC[D_800722C4])[2] >> 5,
                  (D_8009C6DC + D_800831FC[D_800722C4])[2] & 0x1F);
}

void func_800C31E4(void) {
    u8 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("prqsw", 2);
    }
    c = D_8009D391[(D_8009C6DC + D_800831FC[D_800722C4])[1]];
    if (c == 0xFF) {
        c = 0xFF;
    } else {
        c = D_8009AD30[c];
    }
    func_800C33B4(2, c, (D_8009C6DC + D_800831FC[D_800722C4])[2] >> 5,
                  (D_8009C6DC + D_800831FC[D_800722C4])[2] & 0x1F);
}

void func_800C32CC(void) {
    u8 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("prqew", 2);
    }
    c = D_8009D391[(D_8009C6DC + D_800831FC[D_800722C4])[1]];
    if (c == 0xFF) {
        c = 0xFF;
    } else {
        c = D_8009AD30[c];
    }
    func_800C33B4(3, c, (D_8009C6DC + D_800831FC[D_800722C4])[2] >> 5,
                  (D_8009C6DC + D_800831FC[D_800722C4])[2] & 0x1F);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C33B4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C3A20);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0810);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C3C34);

s32 func_800C3EA0(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("back", 1);
    }
    p = &D_800831FC[D_800722C4];
    *p -= M2C_FIELD(&D_8009C6DC[*p], u8 *, 1);
    return 1;
}

s32 func_800C3F1C(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("lback", 2);
    }
    p = &D_800831FC[D_800722C4];
    *p -= (D_8009C6DC + *p)[1] | ((D_8009C6DC + *p)[2] << 8);
    return 1;
}

s32 func_800C3FA0(void) {
    u16 *p;
    if (D_8009D820 & 3) {
        func_800BEAD4("skip", 1);
    }
    p = &D_800831FC[D_800722C4];
    *p += (D_8009C6DC + *p)[1] + 1;
    return 0;
}

s32 func_800C401C(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("lskip", 2);
    }
    p = &D_800831FC[D_800722C4];
    *p = ((D_8009C6DC + *p)[1] | ((D_8009C6DC + *p)[2] << 8)) + (u16)(*p + 1);
    return 0;
}

s32 func_800C40A4(void) {
    u16 *pc;
    u8 *b;

    if (D_8009D820 & 3) {
        func_800BEAD4("mjump", 8);
    }
    switch (M2C_FIELD(D_8009C6E0, u8 *, 1)) {
    case 0:
        M2C_FIELD(D_8009C6E0, u8 *, 1) = 1;
        pc = &D_800831FC[D_800722C4];
        b = D_8009C6DC;
        M2C_FIELD(D_8009C6E0, s16 *, 0x26) = 0;
        M2C_FIELD(D_8009C6E0, s16 *, 2) = (b + *pc)[1];
        M2C_FIELD(D_8009C6E0, s16 *, 2) |= (D_8009C6DC + *pc)[2] << 8;
        M2C_FIELD(D_8009C6E0, s16 *, 4) = (D_8009C6DC + *pc)[3];
        M2C_FIELD(D_8009C6E0, s16 *, 4) |= (D_8009C6DC + *pc)[4] << 8;
        M2C_FIELD(D_8009C6E0, s16 *, 6) = (D_8009C6DC + *pc)[5];
        M2C_FIELD(D_8009C6E0, s16 *, 6) |= (D_8009C6DC + *pc)[6] << 8;
        M2C_FIELD(D_8009C6E0, s16 *, 0x22) = (D_8009C6DC + *pc)[7];
        M2C_FIELD(D_8009C6E0, s16 *, 0x22) |= (D_8009C6DC + *pc)[8] << 8;
        M2C_FIELD(D_8009C6E0, s16 *, 0x24) = (D_8009C6DC + *pc)[9];
        return 1;
    case 1:
        if (M2C_FIELD(D_8009C6E0, s16 *, 0x26) == 2) {
            D_800831FC[D_800722C4] += 0xA;
            M2C_FIELD(D_8009C6E0, u8 *, 1) = 0;
            return 0;
        }
        break;
    }
    if (D_8009D820 & 3) {
        func_800BECA4(D_800A0848, M2C_FIELD(D_8009C6E0, u8 *, 1), 2);
    }
    return 1;
}

s32 func_800C42B0(void) {
    u8 b;
    s16 v;

    if (D_8009D820 & 3) {
        func_800BEAD4(&D_800A0854, 8);
    }
    b = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    D_80095DD0 = b;
    v = b | ((D_8009C6DC + D_800831FC[D_800722C4])[2] << 8);
    D_800831FC[D_800722C4] += 3;
    D_80095DD0 = v;
    return 0;
}

s32 func_800C4350(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4(&D_800A0854, 8);
    }
    if (D_800965E8 == 2) {
        D_800831FC[D_800722C4]++;
        return 0;
    }
    return 1;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0848);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0854);

s32 func_800C43C4(void) {
    u16 *pc;
    u8 *b;

    if (D_8009D820 & 3) {
        func_800BEAD4("mgame", 8);
    }
    switch (M2C_FIELD(D_8009C6E0, u8 *, 1)) {
    case 0:
        M2C_FIELD(D_8009C6E0, u8 *, 1) = 0xC;
        pc = &D_800831FC[D_800722C4];
        b = D_8009C6DC;
        M2C_FIELD(D_8009C6E0, s16 *, 0x26) = 0;
        M2C_FIELD(D_8009C6E0, s16 *, 2) = (b + *pc)[1];
        M2C_FIELD(D_8009C6E0, s16 *, 2) |= (D_8009C6DC + *pc)[2] << 8;
        M2C_FIELD(D_8009C6E0, s16 *, 4) = (D_8009C6DC + *pc)[3];
        M2C_FIELD(D_8009C6E0, s16 *, 4) |= (D_8009C6DC + *pc)[4] << 8;
        M2C_FIELD(D_8009C6E0, s16 *, 6) = (D_8009C6DC + *pc)[5];
        M2C_FIELD(D_8009C6E0, s16 *, 6) |= (D_8009C6DC + *pc)[6] << 8;
        M2C_FIELD(D_8009C6E0, s16 *, 0x22) = (D_8009C6DC + *pc)[7];
        M2C_FIELD(D_8009C6E0, s16 *, 0x22) |= (D_8009C6DC + *pc)[8] << 8;
        M2C_FIELD(D_8009C6E0, s16 *, 0x24) = (D_8009C6DC + *pc)[9];
        M2C_FIELD(D_8009C6E0, u8 *, 0xF2) = (D_8009C6DC + *pc)[0xA];
        return 1;
    case 12:
        if (M2C_FIELD(D_8009C6E0, s16 *, 0x26) == 2) {
            D_800831FC[D_800722C4] += 0xB;
            M2C_FIELD(D_8009C6E0, u8 *, 1) = 0;
            return 0;
        }
        return 1;
    }
    return 1;
}

s32 func_800C45AC(void) {
    s16 v;

    if (D_8009D820 & 3) {
        func_800BEAD4("batle", 3);
    }
    switch (M2C_FIELD(D_8009C6E0, u8 *, 1)) {
    case 0:
        func_800D4BFC();
        M2C_FIELD(D_8009C6E0, u8 *, 1) = 2;
        v = func_800BF908(2, 2);
        D_8007EBE0 = 1;
        M2C_FIELD(D_8009C6E0, s16 *, 2) = v;
        M2C_FIELD(D_8009C6E0, s16 *, 0x26) = 0;
        return 1;
    case 2:
        if (M2C_FIELD(D_8009C6E0, s16 *, 0x26) == 2) {
            D_800831FC[D_800722C4] += 4;
            M2C_FIELD(D_8009C6E0, u8 *, 1) = 0;
            M2C_FIELD(D_8009C6E0, s16 *, 0x26) = 0;
            return 0;
        }
        break;
    }
    return 1;
}

void func_800C46A4(void) {
    s32 i;
    Block9A000 *p = (Block9A000 *)&D_8009A000;
    p->a = 0;
    for (i = 5; i >= 0; i--) {
        p->list[i] = 0;
    }
}

s32 func_800C46D0(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("akao", 3);
    }
    func_800C46A4();
    D_8009A000 = (D_8009C6DC + D_800831FC[D_800722C4])[4];
    D_8009A004 = func_800BEE10(1, 5) & 0xFF;
    D_8009A008 = (s16)func_800BF908(2, 6);
    D_8009A00C = (s16)func_800BF908(3, 8);
    D_8009A010 = (s16)func_800BF908(4, 10);
    D_8009A014 = (s16)func_800BF908(6, 12);
    func_8002DA7C();
    D_800831FC[D_800722C4] += 14;
    return 0;
}

s32 func_800C4804(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("akao2", 3);
    }
    func_800C46A4();
    D_8009A000 = (D_8009C6DC + D_800831FC[D_800722C4])[4];
    D_8009A004 = (s16)func_800BF908(1, 5);
    D_8009A008 = (s16)func_800BF908(2, 7);
    D_8009A00C = (s16)func_800BF908(3, 9);
    D_8009A010 = (s16)func_800BF908(4, 11);
    D_8009A014 = (s16)func_800BF908(6, 13);
    func_8002DA7C();
    D_800831FC[D_800722C4] += 15;
    return 0;
}

s32 func_800C493C(void) {
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("se", 3);
    }
    func_800C46A4();
    D_8009A000 = 0x20;
    D_8009A004 = func_800BEE10(2, 4) & 0xFF;
    D_8009A008 = (s16) func_800BF908(1, 2);
    func_8002DA7C();
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

void func_800C49EC(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("music", 1);
    }
    func_800C46A4();
    D_8009A000 = 0x10;
    func_800C4BCC();
}

void func_800C4A40(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("musvt", 1);
    }
    func_800C46A4();
    D_8009A000 = 0x14;
    func_800C4BCC();
}

void func_800C4A94(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("musvm", 1);
    }
    func_800C46A4();
    D_8009A000 = 0x15;
    func_800C4BCC();
}

s32 func_800C4AE8(void) {
    u16 *pc;
    s32 ret;

    if (D_8009D820 & 3) {
        func_800BEAD4("cmusc", 5);
    }
    func_800C46A4();
    D_8009A000 = (D_8009C6DC + D_800831FC[D_800722C4])[3];
    D_8009A008 = (s16)func_800BF908(3, 4);
    D_8009A00C = (s16)func_800BF908(4, 6);
    ret = func_800C4BCC();
    pc = &D_800831FC[D_800722C4];
    *pc += 6;
    return ret;
}

s32 func_800C4BCC(void) {
    u16 *pc;
    u8 *p;
    u8 n;

    if (D_800716D4 == 0) {
        n = (D_8009C6DC + D_800831FC[D_800722C4])[1];
        if (D_8009D820 & 3) {
            func_800BECA4("music=", n, 2);
        }
        p = D_8009C6DC + func_800C4C9C(n);
        D_8009A004 = (s32)p;
        M2C_SFIELD(D_8009C6E0, u8 **, 0x48) = p;
        func_8002DA7C(D_8009C6E0);
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 2;
    return 0;
}

s32 func_800C4C9C(s16 arg0) {
    u8 *p;
    s32 r;

    p = &D_8009C6DC[arg0 * 4 + D_8009C6DC[2] * 8];
    r = p[0x20];
    r |= p[0x21] << 8;
    r |= p[0x22] << 0x10;
    r |= p[0x23] << 0x18;
    return r;
}

s32 func_800C4CE8(void) {
    u16 *temp_v1;
    u8 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("bmusc", 1);
    }
    if (D_800716D4 == 0) {
        temp_s0 = M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
        if (D_8009D820 & 3) {
            func_800BECA4(&D_800A08B0, temp_s0, 2);
        }
        M2C_FIELD(D_8009C6E0, u8 **, 0x44) = &D_8009C6DC[func_800C4C9C((s16) temp_s0)];
    } else {
        M2C_FIELD(D_8009C6E0, u8 **, 0x44) = NULL;
    }
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A08B0);

s32 func_800C4DE8(void) {
    u16 *temp_v1;
    u8 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("fmusc", 1);
    }
    if (D_800716D4 == 0) {
        temp_s0 = M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
        if (D_8009D820 & 3) {
            func_800BECA4(&D_800A08B0, temp_s0, 2);
        }
        M2C_FIELD(D_8009C6E0, u8 **, 0x48) = &D_8009C6DC[func_800C4C9C((s16) temp_s0)];
    } else {
        M2C_FIELD(D_8009C6E0, u8 **, 0x48) = NULL;
    }
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800C4EE8(void) {
    u8 st;
    u8 n;

    if (D_8009D820 & 3) {
        func_800BEAD4("tutor", 1);
    }
    st = D_8009C6E0[1];
    if (st == 0) {
        D_8009C6E0[1] = 9;
        D_8007EBE0 = 1;
        M2C_SFIELD(D_8009C6E0, s16 *, 2) = 1;
        M2C_SFIELD(D_8009C6E0, s16 *, 0x26) = 0;
        n = (D_8009C6DC + D_800831FC[D_800722C4])[1];
        if (D_8009D820 & 3) {
            func_800BECA4("data=", n, 2);
        }
        D_800E48E0 = D_8009C6DC + func_800C4C9C(n);
        return 1;
    } else if (st == 9) {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A08D0, *(s16 *)(D_8009C6E0 + 0x26), 2);
        }
        if (*(s16 *)(D_8009C6E0 + 0x26) == 2) {
            D_8009C6E0[1] = 0;
            M2C_SFIELD(D_8009C6E0, s16 *, 0x26) = 0;
            D_800831FC[D_800722C4] += 2;
            return 0;
        }
    }
    return 1;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A08D0);

s32 func_800C506C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("mulck", 1);
    }
    D_800716D4 = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    D_800831FC[D_800722C4] += 2;
    return 0;
}

s32 func_800C50EC(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("bgmovie", 1);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x3A) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800C5194(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("scrlo", 1);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x37) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800C523C(void) {
    u16 *pc;
    s32 v;

    if (D_8009D820 & 3) {
        func_800BEAD4("dskcg", 1);
    }
    v = M2C_SFIELD(D_8009C6E0, u8 *, 1);
    switch (v) {
        do {
        } while (0);
    case 0:
        M2C_SFIELD(D_8009C6E0, u8 *, 1) = 13;
        v = (D_8009C6DC + D_800831FC[D_800722C4])[1];
        *(s8 *)D_8009D588 = v;
        break;
    case 13:
        if (M2C_SFIELD(D_8009C6E0, s16 *, 0x26) == 2) {
            M2C_SFIELD(D_8009C6E0, u8 *, 1) = 0;
            pc = &D_800831FC[D_800722C4];
            *pc += 2;
            return 0;
        }
        break;
    }
    return 1;
}

s32 func_800C532C(void) {
    u16 *pc;
    u8 v;

    if (D_8009D820 & 3) {
        func_800BEAD4("uc", 1);
    }
    D_80081DC4 = M2C_SFIELD(D_8009C6E0, u8 *, 0x32) = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    if (D_80081DC4 == 0) {
        D_800756E8[M2C_SFIELD(D_8009C6E0, s16 *, 0x2A)] = 0;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 2;
    return 0;
}

s32 func_800C5414(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("btlon", 1);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x3B) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800C54BC(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("mpdsp", 1);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x38) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800C5564(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("mvcam", 1);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x39) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800C560C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("gmovr", 0);
    }
    D_8009C6E0[1] = 0x1A;
    *(s16 *)(D_8009C6E0 + 0x26) = 0;
    return 1;
}

s32 func_800C5668(void) {
    u16 *pc;
    u8 n;

    if (D_8009D820 & 3) {
        func_800BEAD4("cc", 1);
    }
    n = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    if (D_8007EB98[n] != 0xFF) {
        M2C_SFIELD(D_8009C6E0, s16 *, 0x2A) = D_8007EB98[n];
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 2;
    return 0;
}

s32 func_800C5740(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("char", 1);
    }
    D_8007EB98[D_800722C4] = D_8009C6C4++;
    *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x66) = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    *(s8 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x5C) = 1;
    *(u8 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x57) = D_800722C4;
    pc = &D_800831FC[D_800722C4];
    *pc += 2;
    return 0;
}

s32 func_800C5898(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("dfanm", 2);
    }
    if (D_8007EB98[D_800722C4] != 0xFF) {
        D_8008325C[D_8007EB98[D_800722C4]] = (&D_8009C6DC[D_800831FC[D_800722C4]])[1];
        D_80082248[D_8007EB98[D_800722C4]] = D_8009D828[D_8007EB98[D_800722C4]] / (&D_8009C6DC[D_800831FC[D_800722C4]])[2];
        if (D_800756E8[D_8007EB98[D_800722C4]] == 3) {
            D_800756E8[D_8007EB98[D_800722C4]] = 0;
        }
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 3;
    return 1;
}

s32 func_800C5A2C(void) {
    u16 *temp_v0;

    if (D_8009D820 & 3) {
        func_800BEAD4("ccanm", 3);
    }
    switch ((D_8009C6DC + D_800831FC[D_800722C4])[3]) {
    case 0:
        M2C_FIELD(D_8009C6E0, s16 *, 0x2C) = (D_8009C6DC + D_800831FC[D_800722C4])[1];
        break;
    case 1:
        M2C_FIELD(D_8009C6E0, s16 *, 0x2E) = (D_8009C6DC + D_800831FC[D_800722C4])[1];
        break;
    case 2:
        M2C_FIELD(D_8009C6E0, s16 *, 0x30) = (D_8009C6DC + D_800831FC[D_800722C4])[1];
        break;
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 4;
    return 0;
}

void func_800C5B38(s32 arg0, s32 arg1) {
    u8 a;
    u8 *p;
    u8 *base;

    (D_8009C544 + D_8007EB98[D_800722C4] * 0x84)[0x5E] = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x60) = D_8009D828[D_8007EB98[D_800722C4]] / (D_8009C6DC + D_800831FC[D_800722C4])[2];
    *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x62) = 0;
    a = D_8007EB98[D_800722C4];
    p = D_8004A62C[1] + ((u8 *)D_8008357C)[a * 8 + 4] * 0x24;
    base = (u8 *)(*(u16 *)(p + 0x1A) + *(s32 *)(p + 0x1C));
    *(s16 *)(D_8009C544 + a * 0x84 + 0x64) = *(u16 *)(base + D_80074F02[a].x0 * 16) - 1;
}

s32 func_800C5CE8(void) {
    s32 i;
    s32 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("anime", 2);
    }
    i = D_800722C4;
    c = D_8007EB98[i];
    if (c == 0xFF) {
        D_800831FC[D_800722C4] += 3;
        return 0;
    }
    switch (D_800756E8[c]) {
    case 0:
    case 1:
    case 3:
        func_800C5B38(i, c);
        if (D_8009A058 == 0xAE) {
            D_800756E8[D_8007EB98[D_800722C4]] = 5;
            D_800831FC[D_800722C4] += 3;
            return 0;
        }
        D_800756E8[D_8007EB98[D_800722C4]] = 2;
        break;
    case 4:
        D_800756E8[c] = 0;
        D_800831FC[D_800722C4] += 3;
        return 0;
    }
    return 1;
}

s32 func_800C5E80(void) {
    s32 i;
    s32 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("anim!", 2);
    }
    i = D_800722C4;
    c = D_8007EB98[i];
    if (c != 0xFF) {
        switch (D_800756E8[c]) {
        case 0:
        case 1:
        case 3:
            func_800C5B38(i, c);
            if (D_8009A058 == 0xAF) {
                D_800756E8[D_8007EB98[D_800722C4]] = 6;
                D_800831FC[D_800722C4] += 3;
                return 0;
            }
            D_800756E8[D_8007EB98[D_800722C4]] = 2;
            break;
        case 4:
            D_800756E8[c] = 3;
            D_800831FC[D_800722C4] += 3;
            return 0;
        }
    } else {
        D_800831FC[D_800722C4] += 3;
        return 0;
    }
    return 1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C5FF4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C63CC);

s32 func_800C6748(void) {
    u16 *pc;
    u8 i;

    if (D_8009D820 & 3) {
        func_800BEAD4("animw", 0);
    }
    i = D_8007EB98[D_800722C4];
    if (i == 0xFF) {
        D_800831FC[D_800722C4]++;
        return 0;
    }
    switch (D_800756E8[i]) {
    case 2:
    case 5:
    case 6:
        return 1;
    case 4:
        D_800756E8[i] = 0;
        break;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 1;
    return 0;
}

s32 func_800C684C(void) {
    u16 *pc;
    u8 *m;

    if (D_8009D820 & 3) {
        func_800BEAD4("animb", 0);
    }
    if (D_8007EB98[D_800722C4] != 0xFF) {
        m = D_8009C544 + D_8007EB98[D_800722C4] * 0x84;
        *(s16 *)(m + 0x64) = (s16)*(u16 *)(m + 0x62) >> 4;
        D_800756E8[D_8007EB98[D_800722C4]] = 3;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 1;
    return 0;
}

s32 func_800C6924(void) {
    u8 *m;
    u8 *n;
    u8 a;
    u8 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("move", 5);
    }
    if (D_8007EB98[D_800722C4] == 0xFF) {
        D_800831FC[D_800722C4] += 6;
        return 0;
    }
    *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x68) = 0;
    *(u8 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x37) = 0;
    *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x78) = (s16)func_800BF908(1, 2) << 12;
    *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x7C) = (s16)func_800BF908(2, 4) << 12;
    m = D_8009C544 + D_8007EB98[D_800722C4] * 0x84;
    if (*(s16 *)(D_8009C6E0 + 0x10) * 3 < *(u16 *)(m + 0x70)) {
        if (m[0x5E] != 2) {
            m[0x5E] = 2;
            goto set;
        }
    } else if (m[0x5E] != 1) {
        m[0x5E] = 1;
set:
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x60) = 0x10;
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x62) = 0;
        a = D_8007EB98[D_800722C4];
        m = (u8 *)((u8 *)D_8008357C)[a * 8 + 4];
        p = D_8004A62C[1] + (s32)m * 0x24;
        m = (u8 *)(*(u16 *)(p + 0x1A) + *(s32 *)(p + 0x1C));
        *(s16 *)(D_8009C544 + a * 0x84 + 0x64) = *(u16 *)(m + D_80074F02[a].x0 * 16) - 1;
    }
    D_800756E8[D_8007EB98[D_800722C4]] = 1;
    n = D_8009C544 + D_8007EB98[D_800722C4] * 0x84;
    if (n[0x5D] == 1) {
        switch (*(s16 *)(n + 0x6A)) {
        case 1:
            return 1;
        case 2:
            n[0x5D] = 0;
            *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x6A) = 0;
            D_800756E8[D_8007EB98[D_800722C4]] = 0;
            D_800831FC[D_800722C4] += 6;
            return 0;
        }
    }
    *(u8 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x5D) = 1;
    *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x6A) = 0;
    return 1;
}

s32 func_800C6D64(void) {
    u8 *m;

    if (D_8009D820 & 3) {
        func_800BEAD4("fmove", 5);
    }
    if (D_8007EB98[D_800722C4] == 0xFF) {
        D_800831FC[D_800722C4] += 6;
        return 0;
    }
    *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x68) = 0;
    *(u8 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x37) = 0;
    *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x78) = (s16)func_800BF908(1, 2) << 12;
    *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x7C) = (s16)func_800BF908(2, 4) << 12;
    m = D_8009C544 + D_8007EB98[D_800722C4] * 0x84;
    if (m[0x5D] == 1) {
        switch (*(s16 *)(m + 0x6A)) {
        case 1:
            return 1;
        case 2:
            m[0x5D] = 0;
            *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x6A) = 0;
            D_800831FC[D_800722C4] += 6;
            return 0;
        }
    }
    *(u8 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x5D) = 1;
    *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x6A) = 0;
    return 1;
}

s32 func_800C6FD8(void) {
    u8 i;
    FdCmv84 *p;
    s16 k;
    u8 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("cmove", 5);
    }
    i = D_8007EB98[D_800722C4];
    if (i == 0xFF) {
        D_800831FC[D_800722C4] += 6;
        return 0;
    }
    ((FdCmv84 *)D_8009C544)[i].s68 = 0;
    ((FdCmv84 *)D_8009C544)[D_8007EB98[D_800722C4]].b37 = 1;
    ((FdCmv84 *)D_8009C544)[D_8007EB98[D_800722C4]].w78 = (s16)func_800BF908(1, 2) << 12;
    ((FdCmv84 *)D_8009C544)[D_8007EB98[D_800722C4]].w7C = (s16)func_800BF908(2, 4) << 12;
    p = &((FdCmv84 *)D_8009C544)[D_8007EB98[D_800722C4]];
    c = *((u8 *)p + 0x5D);
    if (c == 1) {
        k = p->s6A;
        switch (k) {
        case 1:
            return 1;
        case 2:
            p->b37 = 0;
            *((u8 *)&((FdCmv84 *)D_8009C544)[D_8007EB98[D_800722C4]] + 0x5D) = 0;
            ((FdCmv84 *)D_8009C544)[D_8007EB98[D_800722C4]].s6A = 0;
            D_800831FC[D_800722C4] += 6;
            return 0;
        }
    }
    *((u8 *)&((FdCmv84 *)D_8009C544)[D_8007EB98[D_800722C4]] + 0x5D) = 1;
    ((FdCmv84 *)D_8009C544)[D_8007EB98[D_800722C4]].s6A = 0;
    return 1;
}

s32 func_800C728C(void) {
    u16 *temp_v0;
    u8 temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("fcfix", 1);
    }
    temp_a0 = D_8007EB98[D_800722C4];
    if (temp_a0 != 0xFF) {
        M2C_FIELD(((temp_a0 * 0x84) + D_8009C544), u8 *, 0x37) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 2;
    return 0;
}

s32 func_800C7354(void) {
    u8 i;
    FdJmp84 *p;
    s16 k;

    if (D_8009D820 & 3) {
        func_800BEAD4("jump", 8);
    }
    i = D_8007EB98[D_800722C4];
    if (i == 0xFF) {
        D_800831FC[D_800722C4] += 0xB;
        return 0;
    }
    p = (FdJmp84 *)D_8009C544 + i;
    if (p->b5D == 3) {
        k = p->s6A;
        if (k == 1) {
            goto done;
        }
        if (k == 2) {
            p->b5D = 0;
            ((FdJmp84 *)D_8009C544)[D_8007EB98[D_800722C4]].s6A = 0;
            D_800831FC[D_800722C4] += 0xB;
            return 0;
        }
    }
    ((FdJmp84 *)D_8009C544)[D_8007EB98[D_800722C4]].b5D = 3;
    ((FdJmp84 *)D_8009C544)[D_8007EB98[D_800722C4]].s6A = 0;
    ((FdJmp84 *)D_8009C544)[D_8007EB98[D_800722C4]].w78 = (s16)func_800BF908(1, 3) << 12;
    ((FdJmp84 *)D_8009C544)[D_8007EB98[D_800722C4]].w7C = (s16)func_800BF908(2, 5) << 12;
    ((FdJmp84 *)D_8009C544)[D_8007EB98[D_800722C4]].s74 = func_800BF908(3, 7);
    ((FdJmp84 *)D_8009C544)[D_8007EB98[D_800722C4]].s30 = func_800BF908(4, 9);
done:
    return 1;
}

s32 func_800C75F0(void) {
    u8 i;
    FdLad84 *p;
    s16 k;
    s32 c;
    u8 *q;
    u8 *base;

    if (D_8009D820 & 3) {
        func_800BEAD4("lader", 8);
    }
    i = D_8007EB98[D_800722C4];
    if (i == 0xFF) {
        D_800831FC[D_800722C4] += 0xF;
        return 0;
    }
    p = (FdLad84 *)D_8009C544 + i;
    c = p->b5D;
    if (c < 6) {
        if (c >= 4) {
            k = p->s6A;
            switch (k) {
            case 1:
                return 1;
            case 2:
                p->b5D = 0;
                ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].s6A = 0;
                D_800831FC[D_800722C4] += 0xF;
                return 0;
            }
        }
    }
    switch ((D_8009C6DC + D_800831FC[D_800722C4])[0xB]) {
    case 0:
        ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].b5D = 4;
        ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].s68 = 0;
        break;
    case 1:
        ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].b5D = 4;
        ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].s68 = 1;
        break;
    case 2:
        ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].b5D = 5;
        ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].s68 = 0;
        break;
    case 3:
        ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].b5D = 5;
        ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].s68 = 1;
        break;
    }
    ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].s6A = 0;
    ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].w78 = (s16)func_800BF908(1, 3) << 12;
    ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].w7C = (s16)func_800BF908(2, 5) << 12;
    ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].w80 = (s16)func_800BF908(3, 7) << 12;
    ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].s74 = func_800BF908(4, 9);
    ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].b5E = (D_8009C6DC + D_800831FC[D_800722C4])[0xC];
    ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].s60 = D_8009D828[D_8007EB98[D_800722C4]] / (D_8009C6DC + D_800831FC[D_800722C4])[0xE];
    ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].s62 = 0;
    q = D_8004A62C[1] + ((u8 *)D_8008357C)[D_8007EB98[D_800722C4] * 8 + 4] * 0x24;
    base = (u8 *)(*(u16 *)(q + 0x1A) + *(s32 *)(q + 0x1C));
    ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].s64 = *(u16 *)(base + D_80074F02[D_8007EB98[D_800722C4]].x0 * 16) - 1;
    D_800756E8[D_8007EB98[D_800722C4]] = 0;
    ((FdLad84 *)D_8009C544)[D_8007EB98[D_800722C4]].b38 = (D_8009C6DC + D_800831FC[D_800722C4])[0xD];
    return 1;
}

void func_800C7C3C(void) {
    u8 temp_a0;
    u8 var_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("pmova", 1);
    }
    temp_a0 = D_8009D391[M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1)];
    if (temp_a0 == 0xFF) {
        var_a0 = 0xFF;
    } else {
        var_a0 = D_8009AD30[temp_a0];
    }
    func_800C7D5C(var_a0);
}

void func_800C7CE8(void) {
    u16 i;
    if (D_8009D820 & 3) {
        func_800BEAD4("mova", 1);
    }
    i = D_800831FC[D_800722C4]; func_800C7D5C((D_8009C6DC + i)[1]);
}

s32 func_800C7D5C(u8 arg0) {
    u8 *m;
    u8 a;
    u8 *p;

    if (D_8007EB98[D_800722C4] == 0xFF || D_8007EB98[arg0] == 0xFF) {
        D_800831FC[D_800722C4] += 2;
        return 0;
    }
    *(u16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x68) = *(u16 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0x6C);
    *(u8 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x37) = 0;
    *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x78) = *(s32 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0xC);
    *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x7C) = *(s32 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0x10);
    m = D_8009C544 + D_8007EB98[D_800722C4] * 0x84;
    if (m[0x5D] == 1) {
        switch (*(s16 *)(m + 0x6A)) {
        case 1:
            if (*(s16 *)(D_8009C6E0 + 0x10) * 3 < *(u16 *)(m + 0x70)) {
                if (m[0x5E] != 2) {
                    m[0x5E] = 2;
                    goto set;
                }
            } else if (m[0x5E] != 1) {
                m[0x5E] = 1;
set:
                *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x60) = 0x10;
                *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x62) = 0;
                a = D_8007EB98[D_800722C4];
                m = (u8 *)((u8 *)D_8008357C)[a * 8 + 4];
                p = D_8004A62C[1] + (s32)m * 0x24;
                m = (u8 *)(*(u16 *)(p + 0x1A) + *(s32 *)(p + 0x1C));
                *(s16 *)(D_8009C544 + a * 0x84 + 0x64) = *(u16 *)(m + D_80074F02[a].x0 * 16) - 1;
            }
            D_800756E8[D_8007EB98[D_800722C4]] = 1;
            return 1;
        case 2:
            m[0x5D] = 0;
            D_800756E8[D_8007EB98[D_800722C4]] = 0;
            D_800831FC[D_800722C4] += 2;
            return 0;
        }
    }
    *(u8 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x5D) = 1;
    *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x6A) = 0;
    return 1;
}

void func_800C814C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("dira", 1);
    }
    func_800C826C(M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1));
}

void func_800C81C0(void) {
    u8 temp_a0;
    u8 var_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("pdira", 1);
    }
    temp_a0 = D_8009D391[M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1)];
    if (temp_a0 == 0xFF) {
        var_a0 = 0xFF;
    } else {
        var_a0 = D_8009AD30[temp_a0];
    }
    func_800C826C(var_a0);
}

s32 func_800C826C(s16 arg0) {
    FdVec a;
    FdVec b;
    s32 out;

    if (D_8007EB98[D_800722C4] == 0xFF || D_8007EB98[arg0] == 0xFF) {
        D_800831FC[D_800722C4] += 2;
        return 0;
    } else {
        a.x = ((FdEnt84 *)D_8009C544)[D_8007EB98[D_800722C4]].x >> 12;
        a.y = ((FdEnt84 *)D_8009C544)[D_8007EB98[D_800722C4]].y >> 12;
        a.z = ((FdEnt84 *)D_8009C544)[D_8007EB98[D_800722C4]].z >> 12;
        b.x = ((FdEnt84 *)D_8009C544)[D_8007EB98[arg0]].x >> 12;
        b.y = ((FdEnt84 *)D_8009C544)[D_8007EB98[arg0]].y >> 12;
        b.z = ((FdEnt84 *)D_8009C544)[D_8007EB98[arg0]].z >> 12;
        if (a.x == b.x) {
            if (a.y == b.y) {
                a.x = a.x + 1;
            }
        }
        ((FdEnt84 *)D_8009C544)[D_8007EB98[D_800722C4]].b38 = func_800A8640(&a, &b, &out);
        ((FdEnt84 *)D_8009C544)[D_8007EB98[D_800722C4]].b3B = 0;
        ((FdEnt84 *)D_8009C544)[D_8007EB98[D_800722C4]].b3A = 0;
        D_800831FC[D_800722C4] += 2;
        return 1;
    }
}

void func_800C8514(void) {
    u16 i;
    if (D_8009D820 & 3) {
        func_800BEAD4("tura", 3);
    }
    i = D_800831FC[D_800722C4];
    func_800C8634((D_8009C6DC + i)[1]);
}

void func_800C8588(void) {
    u8 temp_a0;
    u8 var_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("ptura", 3);
    }
    temp_a0 = D_8009D391[M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1)];
    if (temp_a0 == 0xFF) {
        var_a0 = 0xFF;
    } else {
        var_a0 = D_8009AD30[temp_a0];
    }
    func_800C8634(var_a0);
}

s32 func_800C8634(s16 arg0) {
    FdVec a;
    FdVec b;
    s32 out;
    FdTurn84 *e;
    s16 d;
    s16 v;

    if (D_8007EB98[D_800722C4] == 0xFF || D_8007EB98[arg0] == 0xFF) {
        D_800831FC[D_800722C4] += 4;
        return 0;
    }
    e = &((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]];
    if (e->b3B == 3) {
        e->b3B = 0;
        ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].b3A = 0;
        ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].b39 = 0;
        D_800831FC[D_800722C4] += 4;
        return 0;
    }
    if (e->b3A == 0 || e->b3B != 2 || e->b39 != (D_8009C6DC + D_800831FC[D_800722C4])[2]) {
        ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3C = ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].b38;
        ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].b3B = 2;
        ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].b39 = (D_8009C6DC + D_800831FC[D_800722C4])[2];
        a.x = ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].x >> 12;
        a.y = ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].y >> 12;
        a.z = ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].z >> 12;
        b.x = ((FdTurn84 *)D_8009C544)[D_8007EB98[arg0]].x >> 12;
        b.y = ((FdTurn84 *)D_8009C544)[D_8007EB98[arg0]].y >> 12;
        b.z = ((FdTurn84 *)D_8009C544)[D_8007EB98[arg0]].z >> 12;
        if (a.x == b.x) {
            if (a.y == b.y) {
                a.x = a.x + 1;
            }
        }
        ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3E = func_800A8640(&a, &b, &out) & 0xFF;
        switch ((D_8009C6DC + D_800831FC[D_800722C4])[3]) {
        case 2:
            d = ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3E - ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3C;
            v = d;
            if (d < 0) {
                v = ~d + 1;
            }
            if (v >= 0x81) {
                if ((s16)((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3E > (s16)((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3C) {
                    ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3E = ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3E - 0x100;
                } else {
                    ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3E = ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3E + 0x100;
                }
            }
            break;
        case 1:
            if (((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].b38 < ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3E) {
                ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3E = ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3E - 0x100;
            }
            break;
        case 0:
            if (((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3E < ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].b38) {
                ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3E = ((FdTurn84 *)D_8009C544)[D_8007EB98[D_800722C4]].s3E + 0x100;
            }
            break;
        }
    }
    return 1;
}

s32 func_800C8B98(void) {
    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            switch ((D_8009C6DC + D_800831FC[D_800722C4])[3]) {
            case 0:
                func_800BEAD4("ofstd", 5);
                break;
            case 1:
                func_800BEAD4("ofstl", 5);
                break;
            case 2:
                func_800BEAD4("ofstc", 5);
                break;
            }
        }
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x54) = 0;
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x52) = func_800BF908(4, 0xA);
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x44) = func_800BF908(1, 4);
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x4A) = func_800BF908(2, 6);
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x50) = func_800BF908(3, 8);
        if (((D_8009C544 + D_8007EB98[D_800722C4] * 0x84)[0x56] = (D_8009C6DC + D_800831FC[D_800722C4])[3]) != 0) {
            *(u16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x42) = *(u16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x40);
            *(u16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x48) = *(u16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x46);
            *(u16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x4E) = *(u16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x4C);
        } else {
            *(u16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x40) = *(u16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x44);
            *(u16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x46) = *(u16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x4A);
            *(u16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x4C) = *(u16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x50);
        }
    }
    D_800831FC[D_800722C4] += 0xC;
    return 0;
}

s32 func_800C8F64(void) {
    u8 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("ofstw", 0);
    }
    if (D_8007EB98[D_800722C4] == 0xFF) {
        D_800831FC[D_800722C4] += 1;
        return 0;
    }
    p = D_8009C544 + D_8007EB98[D_800722C4] * 0x84;
    if (M2C_SFIELD(p, u8 *, 0x56) == 0 || M2C_SFIELD(p, u8 *, 0x56) == 3) {
        M2C_SFIELD(p, u8 *, 0x56) = 0;
        M2C_SFIELD(D_8009C544 + D_8007EB98[D_800722C4] * 0x84, s16 *, 0x54) = 0;
        M2C_SFIELD(D_8009C544 + D_8007EB98[D_800722C4] * 0x84, s16 *, 0x52) = 0;
        D_800831FC[D_800722C4] += 1;
        return 0;
    }
    return 1;
}

s32 func_800C9080(void) {
    u8 *p;
    u8 st;

    if (D_8007EB98[D_800722C4] == 0xFF) {
        D_800831FC[D_800722C4] += 1;
        return 0;
    }
    if (D_8009D820 & 3) {
        func_800BEAD4("turnw", 0);
    }
    p = D_8009C544 + D_8007EB98[D_800722C4] * 0x84;
    st = p[0x3B];
    if (st == 0) {
        D_800831FC[D_800722C4] += 1;
        return 0;
    }
    if (st == 3) {
        p[0x3B] = 0;
        (D_8009C544 + D_8007EB98[D_800722C4] * 0x84)[0x3A] = 0;
        (D_8009C544 + D_8007EB98[D_800722C4] * 0x84)[0x39] = 0;
        D_800831FC[D_800722C4] += 1;
        return 0;
    }
    return 1;
}

s32 func_800C91D8(void) {
    s32 i;
    u8 *act;
    s32 r;

    i = D_800722C4;
    if (D_8007EB98[i] != 0xFF) {
        if (D_8009D820 & 3) {
            switch ((D_8009C6DC + D_800831FC[i])[5]) {
            case 1:
                func_800BEAD4("turn", 5);
                break;
            case 2:
                func_800BEAD4("turnc", 5);
                break;
            }
        }
        act = D_8009C544 + D_8007EB98[D_800722C4] * 0x84;
        if (act[0x3B] == 3) {
            act[0x3B] = 0;
            (D_8009C544 + D_8007EB98[D_800722C4] * 0x84)[0x3A] = 0;
            (D_8009C544 + D_8007EB98[D_800722C4] * 0x84)[0x39] = 0;
            D_800831FC[D_800722C4] += 6;
            return 0;
        }
        r = func_800BF908(2, 2);
        act = D_8009C544 + D_8007EB98[D_800722C4] * 0x84;
        if (act[0x3A] == 0 || (s16)r != *(s16 *)(act + 0x3E) || (act[0x3B] != (D_8009C6DC + D_800831FC[D_800722C4])[5]) || (act[0x39] != (D_8009C6DC + D_800831FC[D_800722C4])[4])) {
            *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x3C) = (D_8009C544 + D_8007EB98[D_800722C4] * 0x84)[0x38];
            (D_8009C544 + D_8007EB98[D_800722C4] * 0x84)[0x3B] = (D_8009C6DC + D_800831FC[D_800722C4])[5];
            (D_8009C544 + D_8007EB98[D_800722C4] * 0x84)[0x39] = (D_8009C6DC + D_800831FC[D_800722C4])[4];
            *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x3E) = r;
        }
    } else {
        D_800831FC[D_800722C4] += 6;
        return 0;
    }
    return 1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C955C);

s32 func_800C9A20(void) {
    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("dir", 2);
        }
        (D_8009C544 + D_8007EB98[D_800722C4] * 0x84)[0x38] = func_800BEE10(2, 2);
        (D_8009C544 + D_8007EB98[D_800722C4] * 0x84)[0x3B] = 0;
        (D_8009C544 + D_8007EB98[D_800722C4] * 0x84)[0x3A] = 0;
        D_800831FC[D_800722C4] += 3;
        return 1;
    }
    D_800831FC[D_800722C4] += 3;
    return 0;
}

s32 func_800C9B88(void) {
    u16 *pc;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("slidR", 2);
        }
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x6C) = (u8)func_800BEE10(2, 2) * M2C_FIELD(D_8009C6E0, s16 *, 0x10) / 512;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 3;
    return 0;
}

s32 func_800C9C84(void) {
    u16 *pc;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("sldR2", 3);
        }
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x6C) = (s16)func_800BF908(2, 2) * M2C_FIELD(D_8009C6E0, s16 *, 0x10) / 512;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 4;
    return 0;
}

s32 func_800C9D80(void) {
    u16 *pc;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("talkR", 2);
        }
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x6E) = (u8)func_800BEE10(2, 2) * M2C_FIELD(D_8009C6E0, s16 *, 0x10) / 512;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 3;
    return 0;
}

s32 func_800C9E7C(void) {
    u16 *pc;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("tlkR2", 3);
        }
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x6E) = (s16)func_800BF908(2, 2) * M2C_FIELD(D_8009C6E0, s16 *, 0x10) / 512;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 4;
    return 0;
}

s32 func_800C9F78(void) {
    u16 *pc;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("msped", 3);
        }
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x70) = (s16)func_800BF908(2, 2) * M2C_FIELD(D_8009C6E0, s16 *, 0x10) / 512;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 4;
    return 0;
}

s32 func_800CA074(void) {
    u16 *pc;
    s16 v;
    u8 i;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("asped", 3);
        }
        v = func_800BF908(2, 2);
        i = D_8007EB98[D_800722C4];
        *(s16 *)(D_8009C544 + i * 0x84 + 0x60) = v;
        D_8009D828[i] = v;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 4;
    return 0;
}

s32 func_800CA158(void) {
    u16 *temp_v0;
    u8 temp_s0;

    temp_s0 = M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 2);
    if (D_8007EB98[temp_s0] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("gtdir", 3);
        }
        func_800BF3AC(2, 3, M2C_FIELD(((D_8007EB98[temp_s0] * 0x84) + D_8009C544), u8 *, 0x38));
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 4;
    return 0;
}

s32 func_800CA254(void) {
    u8 n;
    u8 c;
    u8 m;
    u16 *pc;

    n = (D_8009C6DC + D_800831FC[D_800722C4])[2];
    if (n < 3) {
        c = D_8009D391[n];
        if (c != 0xFF) {
            m = D_8009AD30[c];
            if (m != 0xFF && D_8007EB98[m] != 0xFF) {
                if (D_8009D820 & 3) {
                    func_800BEAD4("pgtdr", 3);
                }
                func_800BF3AC(2, 3, (D_8009C544 + D_8007EB98[m] * 0x84)[0x38]);
            }
        }
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 4;
    return 0;
}

s32 func_800CA394(void) {
    u16 *temp_v0;
    u8 temp_s0;

    temp_s0 = M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 2);
    if (D_8007EB98[temp_s0] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("getai", 3);
        }
        func_800C0248(2, 3, M2C_FIELD(((D_8007EB98[temp_s0] * 0x84) + D_8009C544), s16 *, 0x72));
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 4;
    return 0;
}

s32 func_800CA490(void) {
    u8 n;
    u16 *pc;

    n = (D_8009C6DC + D_800831FC[D_800722C4])[2];
    if (D_8007EB98[n] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("getaxy", 4);
        }
        func_800C0248(1, 3, *(s32 *)(D_8009C544 + D_8007EB98[n] * 0x84 + 0xC) * 16 >> 16);
        func_800C0248(2, 4, *(s32 *)(D_8009C544 + D_8007EB98[n] * 0x84 + 0x10) * 16 >> 16);
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CA5D4(void) {
    u8 n;
    u16 *pc;

    n = (D_8009C6DC + D_800831FC[D_800722C4])[3];
    if (D_8009D820 & 3) {
        func_800BEAD4("axyzi", 7);
    }
    if (D_8007EB98[n] != 0xFF) {
        func_800C0248(1, 4, *(s32 *)(D_8009C544 + D_8007EB98[n] * 0x84 + 0xC) * 16 >> 16);
        func_800C0248(2, 5, *(s32 *)(D_8009C544 + D_8007EB98[n] * 0x84 + 0x10) * 16 >> 16);
        func_800C0248(3, 6, *(s32 *)(D_8009C544 + D_8007EB98[n] * 0x84 + 0x14) * 16 >> 16);
        func_800C0248(4, 7, *(s16 *)(D_8009C544 + D_8007EB98[n] * 0x84 + 0x72));
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 8;
    return 0;
}

s32 func_800CA77C(void) {
    u8 n;
    u8 t;
    u16 *pc;

    n = (D_8009C6DC + D_800831FC[D_800722C4])[3];
    if (D_8009D820 & 3) {
        func_800BEAD4("pxyzi", 7);
    }
    if (n < 3) {
        t = D_8009D391[n];
        if (t < 9) {
            n = D_8009AD30[t];
            if (D_8007EB98[n] != 0xFF) {
                func_800C0248(1, 4, *(s32 *)(D_8009C544 + D_8007EB98[n] * 0x84 + 0xC) * 16 >> 16);
                func_800C0248(2, 5, *(s32 *)(D_8009C544 + D_8007EB98[n] * 0x84 + 0x10) * 16 >> 16);
                func_800C0248(3, 6, *(s32 *)(D_8009C544 + D_8007EB98[n] * 0x84 + 0x14) * 16 >> 16);
                func_800C0248(4, 7, *(s16 *)(D_8009C544 + D_8007EB98[n] * 0x84 + 0x72));
            }
        }
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 8;
    return 0;
}

s32 func_800CA95C(void) {
    u16 *temp_v0;
    u8 temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("visi", 1);
    }
    temp_a0 = D_8007EB98[D_800722C4];
    if (temp_a0 != 0xFF) {
        M2C_FIELD(((temp_a0 * 0x84) + D_8009C544), u8 *, 0x5C) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 2;
    return 0;
}

s32 func_800CAA24(void) {
    u16 *temp_v0;
    u8 temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("tlkon", 1);
    }
    temp_a0 = D_8007EB98[D_800722C4];
    if (temp_a0 != 0xFF) {
        M2C_FIELD(((temp_a0 * 0x84) + D_8009C544), u8 *, 0x5B) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 2;
    return 0;
}

s32 func_800CAAEC(void) {
    u16 *pc;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("xyzi", 8);
        }
        *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0xC) = (s16)func_800BF908(1, 3) << 12;
        *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x10) = (s16)func_800BF908(2, 5) << 12;
        *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x14) = (s16)func_800BF908(3, 7) << 12;
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x72) = func_800BF908(4, 9);
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 11;
    return 1;
}

s32 func_800CAC98(void) {
    u16 *pc;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("xyz", 8);
        }
        *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0xC) = (s16)func_800BF908(1, 3) << 12;
        *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x10) = (s16)func_800BF908(2, 5) << 12;
        *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x14) = (s16)func_800BF908(3, 7) << 12;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 9;
    return 1;
}

s32 func_800CADFC(void) {
    u16 *pc;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("xyi", 8);
        }
        *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0xC) = (s16)func_800BF908(1, 3) << 12;
        *(s32 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x10) = (s16)func_800BF908(2, 5) << 12;
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x72) = func_800BF908(3, 7);
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 9;
    return 1;
}

s32 func_800CAF60(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("mes", 2);
    }
    if (func_800D4EB4((D_8009C6DC + D_800831FC[D_800722C4])[1], (D_8009C6DC + D_800831FC[D_800722C4])[2]) != 0) {
        pc = &D_800831FC[D_800722C4];
        *pc += 3;
        return 0;
    }
    return 1;
}

s32 func_800CB01C(void) {
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("mpnam", 1);
    }
    func_800D7A58(M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 2;
    return 0;
}

s32 func_800CB0B8(void) {
    s16 sp18;

    if (D_8009D820 & 3) {
        func_800BEAD4("ask", 6);
    }
    sp18 = func_800BEE10(2, 6) & 0xFF;
    if (func_800D5228((D_8009C6DC + D_800831FC[D_800722C4])[2], (D_8009C6DC + D_800831FC[D_800722C4])[3],
                      (D_8009C6DC + D_800831FC[D_800722C4])[4], (D_8009C6DC + D_800831FC[D_800722C4])[5], &sp18) != 0) {
        func_800BF3AC(2, 6, sp18);
        D_8009C6E0[0x32] = D_80081DC4;
        D_800831FC[D_800722C4] += 7;
        return 0;
    } else {
        func_800BF3AC(2, 6, sp18);
        D_8009C6E0[0x32] = 1;
        return 1;
    }
}

s32 func_800CB1CC(void) {
    u16 *pc;
    s16 n;

    if (D_8009D820 & 3) {
        func_800BEAD4("wcls!", 0);
    }
    pc = &D_800831FC[D_800722C4];
    n = (D_8009C6DC + *pc)[1];
    if (D_8008326C[n] == 0xFF) {
        *pc += 2;
        return 0;
    }
    ((s32 (*)(s32))func_800D4B28)(n);
    func_800D4EB4(n, 0);
    return 1;
}

s32 func_800CB28C(void) {
    s16 n;

    if (D_8009D820 & 3) {
        func_800BEAD4("wsizw", 8);
    }
    n = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    if (D_8008326C[n] == 0xFF) {
        return func_800CB354(n, D_800722C4);
    }
    if (D_8008326C[n] == D_800722C4) {
        ((s32 (*)(s32))func_800D4B28)(n);
        func_800D4EB4(n, 0);
    }
    return 1;
}

s32 func_800CB354() {
    u8 *p;
    u16 *pc;
    s16 a, b, c, d;

    if (D_8009D820 & 3) {
        func_800BEAD4("wsize", 8);
    }
    p = D_8009C6DC;
    p += D_800831FC[D_800722C4];
    a = p[2] | (p[3] << 8);
    b = p[4] | (p[5] << 8);
    c = p[6] | (p[7] << 8);
    d = p[8] | (p[9] << 8);
    func_800D4C68(p[1], a, b, c, d);
    pc = &D_800831FC[D_800722C4];
    *pc += 10;
    return 0;
}

s32 func_800CB450(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("wrow", 2);
    }
    func_800D4E88((s16) (D_8009C6DC + D_800831FC[D_800722C4])[1], ((D_8009C6DC + D_800831FC[D_800722C4])[2] * 0x10) | 9);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 3;
    return 0;
}

s32 func_800CB4F8(void) {
    u8 *p;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("wmove", 8);
    }
    p = D_8009C6DC;
    p += D_800831FC[D_800722C4];
    func_800D4E24(p[1], (s16)(p[2] | (p[3] << 8)), (s16)(p[4] | (p[5] << 8)));
    pc = &D_800831FC[D_800722C4];
    *pc += 6;
    return 0;
}

s32 func_800CB5C0(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("wrest", 1);
    }
    func_800D493C((s16) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1));
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800CB660(void) {
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("wclse", 1);
    }
    if (func_800D4B28(M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1)) != 0) {
        temp_a0 = &D_800831FC[D_800722C4];
        *temp_a0 += 2;
        return 0;
    }
    return 1;
}

s32 func_800CB718(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("wmode", 3);
    }
    ((void (*)(s16, u8, s16))func_800D4BC0)((D_8009C6DC + D_800831FC[D_800722C4])[1], (D_8009C6DC + D_800831FC[D_800722C4])[2], (D_8009C6DC + D_800831FC[D_800722C4])[3]);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 4;
    return 0;
}

s32 func_800CB7C0(void) {
    u16 *p;
    s32 a;

    if (D_8009D820 & 3) {
        func_800BEAD4("and", 3);
    }
    a = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, a & func_800BEE10(2, 3));
    p = &D_800831FC[D_800722C4];
    *p += 4;
    return 0;
}

s32 func_800CB858(void) {
    u16 *temp_a0;
    u32 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("and2", 3);
    }
    temp_s0 = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16) (temp_s0 & func_800BF908(2, 3)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

s32 func_800CB8F4(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("or", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 | func_800BEE10(2, 3)) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CB98C(void) {
    u16 *temp_a0;
    u32 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("or2", 3);
    }
    temp_s0 = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16) (temp_s0 | func_800BF908(2, 3)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

s32 func_800CBA28(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("xor", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 ^ func_800BEE10(2, 3)) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CBAC0(void) {
    u16 *temp_a0;
    u32 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("xor2", 3);
    }
    temp_s0 = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16) (temp_s0 ^ func_800BF908(2, 3)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

s32 func_800CBB5C(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("plus", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 + func_800BEE10(2, 3)) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CBBF4(void) {
    s32 t;
    u8 v;
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("plus!", 3);
    }
    t = (u8)func_800BEE10(1, 2) + (u8)func_800BEE10(2, 3);
    v = t;
    if (t >= 0x100) {
        v = 0xFF;
    }
    func_800BF3AC(1, 2, v);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 4;
    return 0;
}

s32 func_800CBCA4(void) {
    u16 *temp_a0;
    u32 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("plus2", 3);
    }
    temp_s0 = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16) (temp_s0 + func_800BF908(2, 3)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

s32 func_800CBD40(void) {
    s16 a;
    s32 v;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("pls2!", 3);
    }
    a = func_800BF908(1, 2);
    v = a + (s16)func_800BF908(2, 3);
    if (v > 0x7FFF) {
        v = 0x7FFF;
    }
    func_800C0248(1, 2, v);
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CBDFC(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("minus", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 - func_800BEE10(2, 3)) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CBE94(void) {
    s32 t;
    u8 v;
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("mins!", 3);
    }
    t = (u8)func_800BEE10(1, 2) - (u8)func_800BEE10(2, 3);
    v = t;
    if (t < 0) {
        v = 0;
    }
    func_800BF3AC(1, 2, v);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 4;
    return 0;
}

s32 func_800CBF40(void) {
    u16 *temp_a0;
    u32 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("mins2", 3);
    }
    temp_s0 = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16) (temp_s0 - func_800BF908(2, 3)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

s32 func_800CBFDC(void) {
    s16 a;
    s32 v;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("mns2!", 3);
    }
    a = func_800BF908(1, 2);
    v = a - (s16)func_800BF908(2, 3);
    if (v <= 0x7FFF) {
        v = 0x8000;
    }
    func_800C0248(1, 2, v);
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CC098(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("mul", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 * func_800BEE10(2, 3)) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CC134(void) {
    u16 *temp_a0;
    u32 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("mul2", 3);
    }
    temp_s0 = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16) (temp_s0 * func_800BF908(2, 3)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

s32 func_800CC1D4(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("div", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (u8) ((u32) (temp_s0 & 0xFF) / (u32) (func_800BEE10(2, 3) & 0xFF)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CC284(void) {
    s32 a;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("div2", 3);
    }
    a = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16)a / (s16)func_800BF908(2, 3));
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CC358(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("remai", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (u8) ((u32) (temp_s0 & 0xFF) % (u32) (func_800BEE10(2, 3) & 0xFF)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CC404(void) {
    s32 a;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("rema2", 3);
    }
    a = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16)a % (s16)func_800BF908(2, 3));
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CC4D8(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("inc", 2);
    }
    func_800BF3AC(2, 2, func_800BEE10(2, 2) + 1);
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CC558(void) {
    u16 *p;
    s32 t;
    u8 v;

    if (D_8009D820 & 3) {
        func_800BEAD4("inc!", 2);
    }
    t = (func_800BEE10(2, 2) & 0xFF) + 1;
    v = t;
    if (t >= 0x100) {
        v = 0xFF;
    }
    func_800BF3AC(2, 2, v);
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CC5EC(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("inc2", 3);
    }
    func_800C0248(2, 2, func_800BF908(2, 2) + 1);
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CC670(void) {
    s32 var_a2;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("inc2!", 3);
    }
    var_a2 = (s16) func_800BF908(2, 2) + 1;
    if (var_a2 > 0x7FFF) {
        var_a2 = 0x7FFF;
    }
    func_800C0248(2, 2, var_a2);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 3;
    return 0;
}

s32 func_800CC70C(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("dec", 2);
    }
    func_800BF3AC(2, 2, func_800BEE10(2, 2) - 1);
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CC78C(void) {
    u16 n;
    u16 var_a2;
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("dec!", 2);
    }
    n = func_800BEE10(2, 2) & 0xFF;
    n--;
    var_a2 = n;
    if ((s16) n < 0) {
        var_a2 = 0;
    }
    func_800BF3AC(2, 2, var_a2 & 0xFF);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 3;
    return 0;
}

s32 func_800CC824(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("dec2", 3);
    }
    func_800C0248(2, 2, (s32)func_800BF908(2, 2) - 1);
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CC8A8(void) {
    s32 var_a2;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("dec2!", 3);
    }
    var_a2 = (s16) func_800BF908(2, 2) - 1;
    if (var_a2 <= 0x7FFF) {
        var_a2 = 0x8000;
    }
    func_800C0248(2, 2, var_a2);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 3;
    return 0;
}

s32 func_800CC944(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("randm", 2);
    }
    D_80095DC8 += (u8) D_8004A630;
    func_800BF3AC(2, 2, D_800E0638[D_80095DC8]);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 3;
    return 0;
}

s32 func_800CC9EC(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("rdmsd", 2);
    }
    D_8004A630 = func_800BEE10(2, 2) * 0x10 + 1;
    D_800831FC[D_800722C4] += 3;
    return 0;
}

s32 func_800CCA68(void) {
    s32 a;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("bgon", 3);
    }
    a = func_800BEE10(1, 2);
    M2C_FIELD(&D_8009C6E0[a & 0xFF], u8 *, 0xF2) |= 1 << func_800BEE10(2, 3);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CCB10(void) {
    s32 a;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("bgoff", 3);
    }
    a = func_800BEE10(1, 2);
    M2C_FIELD(&D_8009C6E0[a & 0xFF], u8 *, 0xF2) &= ~(1 << func_800BEE10(2, 3));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CCBBC(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("bgclr", 3);
    }
    M2C_FIELD(&D_8009C6E0[func_800BEE10(2, 2) & 0xFF], s8 *, 0xF2) = 0;
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CCC3C(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4(&D_800A0BE0, 3);
    }
    (D_8009C6E0 + (func_800BEE10(2, 2) & 0xFF))[0xF2] *= 2;
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CCCC8(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4(&D_800A0BE0, 3);
    }
    (D_8009C6E0 + (func_800BEE10(2, 2) & 0xFF))[0xF2] >>= 1;
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0BE0);

s32 func_800CCD54(void) {
    u16 *pc;
    u8 v;

    if (D_8009D820 & 3) {
        func_800BEAD4("pmvie", 1);
    }
    if (D_800716CC != 0) {
        D_800831FC[D_800722C4] += 2;
        return 0;
    } else {
        switch (D_8009C6E0[1]) {
        case 3:
            switch (M2C_FIELD(D_8009C6E0, s16 *, 0x26)) {
            case 1:
                break;
            case 2:
                D_8009C6E0[1] = 0;
                M2C_SFIELD(D_8009C6E0, s16 *, 0x26) = 0;
                D_800831FC[D_800722C4] += 2;
                return 0;
            }
            break;
        case 0:
            D_8009C6E0[1] = 3;
            v = (D_8009C6DC + D_800831FC[D_800722C4])[1];
            M2C_SFIELD(D_8009C6E0, s16 *, 0x26) = 0;
            M2C_SFIELD(D_8009C6E0, s16 *, 2) = v;
            break;
        }
        return 1;
    }
}

s32 func_800CCE94(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("movie", 0);
    }
    D_80071C1C = 1;
    if (D_800716CC != 0) {
        D_801144D4 = 0;
        D_800831FC[D_800722C4] += 1;
        return 0;
    } else {
        switch (D_8009C6E0[1]) {
        case 4:
            switch (M2C_FIELD(D_8009C6E0, s16 *, 0x26)) {
            case 1:
                break;
            case 2:
                D_8009C6E0[1] = 0;
                M2C_SFIELD(D_8009C6E0, s16 *, 0x26) = 0;
                D_800831FC[D_800722C4] += 1;
                return 0;
            }
            break;
        case 0x14:
            D_800831FC[D_800722C4] += 1;
            return 0;
        case 0:
            D_8009C6E0[1] = 4;
            M2C_FIELD(D_8009C6E0, s16 *, 0x26) = 0;
            break;
        }
        return 1;
    }
}

s32 func_800CCFE8(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("mvief", 2);
    }
    if (D_800716CC != 0) {
        func_800C0248(2, 2, D_801144D4);
        D_800831FC[D_800722C4] += 3;
        D_801144D4++;
        return 0;
    } else {
        func_800C0248(2, 2, M2C_SFIELD(D_8009C6E0, s16 *, 0x88));
        pc = &D_800831FC[D_800722C4];
        *pc += 3;
        return 0;
    }
}

s32 func_800CD0C4(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("mpjpo", 0);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x36) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800CD16C(void) {
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("scr2d", 5);
    }
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1D) = 4;
    M2C_SFIELD(D_8009C6E0, s16 *, 0xA) = func_800BF908(1, 2);
    M2C_SFIELD(D_8009C6E0, s16 *, 0xC) = func_800BF908(2, 4);
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1F) = 0;
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 6;
    return 0;
}

s32 func_800CD214(void) {
    u16 *pc;
    s32 pad;

    if (D_8009D820 & 3) {
        func_800BEAD4("scrlc", 0);
    }
    M2C_SFIELD(D_8009C6E0, u8 *, 0x1D) = (D_8009C6DC + D_800831FC[D_800722C4])[4];
    M2C_SFIELD(D_8009C6E0, u8 *, 0x1E) = M2C_SFIELD(D_8009C6E0, u8 *, 0x2A);
    M2C_SFIELD(D_8009C6E0, s16 *, 0x20) = func_800BF908(2, 2);
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1F) = 0;
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CD2E8(void) {
    u16 *temp_a0_2;
    u8 temp_a1;

    if (D_8009D820 & 3) {
        func_800BEAD4("scrla", 0);
    }
    temp_a1 = (D_8009C6DC + D_800831FC[D_800722C4])[4];
    if (D_8007EB98[temp_a1] != 0xFF) {
        M2C_FIELD(D_8009C6E0, u8 *, 0x1D) = (D_8009C6DC + D_800831FC[D_800722C4])[5];
        M2C_FIELD(D_8009C6E0, u8 *, 0x1E) = D_8007EB98[temp_a1];
        M2C_FIELD(D_8009C6E0, s16 *, 0x20) = func_800BF908(2, 2);
        M2C_FIELD(D_8009C6E0, s8 *, 0x1F) = 0;
    }
    temp_a0_2 = &D_800831FC[D_800722C4];
    *temp_a0_2 += 6;
    return 0;
}

s32 func_800CD3F0(void) {
    s32 c;
    s16 m;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("scrlp", 0);
    }
    c = D_8009D391[(D_8009C6DC + D_800831FC[D_800722C4])[4]];
    if (c == 0xFF) {
        m = 0xFF;
    } else {
        m = D_8009AD30[c];
    }
    if (D_8007EB98[m] != 0xFF) {
        D_8009C6E0[0x1D] = (D_8009C6DC + D_800831FC[D_800722C4])[5];
        D_8009C6E0[0x1E] = D_8007EB98[m];
        *(s16 *)(D_8009C6E0 + 0x20) = func_800BF908(2, 2);
        D_8009C6E0[0x1F] = 0;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 6;
    return 0;
}

s32 func_800CD554(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("scrcc", 0);
    }
    M2C_FIELD(D_8009C6E0, s8 *, 0x1D) = 0;
    M2C_FIELD(D_8009C6E0, u8 *, 0x1E) = (u8) M2C_FIELD(D_8009C6E0, u8 *, 0x2A);
    M2C_FIELD(D_8009C6E0, s8 *, 0x1F) = 0;
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 1;
    return 0;
}

s32 func_800CD5F0(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("scr2dc", 8);
    }
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1D) = 6;
    M2C_SFIELD(D_8009C6E0, s16 *, 0xA) = func_800BF908(1, 3);
    M2C_SFIELD(D_8009C6E0, s16 *, 0xC) = func_800BF908(2, 5);
    M2C_SFIELD(D_8009C6E0, s16 *, 0x20) = func_800BF908(4, 7);
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1F) = 0;
    pc = &D_800831FC[D_800722C4];
    *pc += 9;
    return 0;
}

s32 func_800CD6B0(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("scr2dl", 8);
    }
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1D) = 5;
    M2C_SFIELD(D_8009C6E0, s16 *, 0xA) = func_800BF908(1, 3);
    M2C_SFIELD(D_8009C6E0, s16 *, 0xC) = func_800BF908(2, 5);
    M2C_SFIELD(D_8009C6E0, s16 *, 0x20) = func_800BF908(4, 7);
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1F) = 0;
    pc = &D_800831FC[D_800722C4];
    *pc += 9;
    return 0;
}

s32 func_800CD770(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("scrlw", 0);
    }
    if (D_8009C6E0[0x1F] == 2) {
        switch (D_8009C6E0[0x1D]) {
        case 1:
        case 2:
        case 3:
            D_8009C6E0[0x1D] = 1;
            break;
        case 5:
        case 6:
            D_8009C6E0[0x1D] = 4;
            break;
        }
        D_8009C6E0[0x1F] = 0;
        pc = &D_800831FC[D_800722C4];
        *pc += 1;
        return 0;
    }
    return 1;
}

s32 func_800CD834(void) {
    RECT16 r;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("stpal", 4);
    }
    func_800CDC14(&r);
    r.y = (u8)func_800BEE10(1, 2) + 0x1E0;
    r.x = 0;
    r.w = (D_8009C6DC + D_800831FC[D_800722C4])[4] + 1;
    r.h = 1;
    func_80044064(&r, (s32)(D_80095DE0 + ((u8)func_800BEE10(2, 3) << 5)));
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CD91C(void) {
    RECT16 r;
    u16 *pc;
    u8 x;

    if (D_8009D820 & 3) {
        func_800BEAD4("stpls", 4);
    }
    func_800CDC14(&r);
    pc = &D_800831FC[D_800722C4];
    r.y = (D_8009C6DC + *pc)[1] + 0x1E0;
    r.x = x = (D_8009C6DC + *pc)[3];
    r.w = (D_8009C6DC + *pc)[4] + 1;
    r.h = 1;
    ((s32 (*)(RECT16 *, u16 *))func_80044064)(&r, &((u16 (*)[16])D_80095DE0)[(D_8009C6DC + *pc)[2]][x]);
    D_800831FC[D_800722C4] += 5;
    return 0;
}

s32 func_800CDA24(void) {
    RECT16 r;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("ldpal", 4);
    }
    func_800CDC14(&r);
    r.y = (u8)func_800BEE10(2, 3) + 0x1E0;
    r.x = 0;
    r.w = (D_8009C6DC + D_800831FC[D_800722C4])[4] + 1;
    r.h = 1;
    func_80044000(&r, D_80095DE0 + ((u8)func_800BEE10(1, 2) << 5));
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CDB0C(void) {
    RECT16 r;
    u16 *pc;
    u8 x;

    if (D_8009D820 & 3) {
        func_800BEAD4("ldpls", 4);
    }
    func_800CDC14(&r);
    pc = &D_800831FC[D_800722C4];
    r.y = (D_8009C6DC + *pc)[2] + 0x1E0;
    r.x = x = (D_8009C6DC + *pc)[3];
    r.w = (D_8009C6DC + *pc)[4] + 1;
    r.h = 1;
    func_80044000(&r, &((u16 (*)[16])D_80095DE0)[(D_8009C6DC + *pc)[1]][x]);
    D_800831FC[D_800722C4] += 5;
    return 0;
}

void func_800CDC14(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 4) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CDC28);

s32 func_800CDD40(void) {
    s32 n;
    s16 i;
    u8 dst;
    u8 src;
    s16 j;
    s16 end;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4(D_800A0C68, 7);
    }
    n = (func_800BEE10(4, 7) & 0xFF) + 1;
    src = (D_8009C6DC + D_800831FC[D_800722C4])[3];
    dst = (D_8009C6DC + D_800831FC[D_800722C4])[4];
    i = (u8)func_800BEE10(1, 5);
    j = func_800BEE10(2, 6) & 0xFF;
    end = i + n;
    for (; i < end; i++, j++) {
        ((FdRow *)D_80095DE0)[dst].c[j] = ((FdRow *)D_80095DE0)[src].c[i];
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 8;
    return 0;
}

s32 func_800CDE8C(void) {
    u8 dst;
    u8 src;
    u16 *pc;
    s16 end;
    s16 j;
    s16 a;
    s16 b;

    if (D_8009D820 & 3) {
        func_800BEAD4(D_800A0C70, 6);
    }
    end = (D_8009C6DC + D_800831FC[D_800722C4])[6] + 1;
    src = func_800BEE10(1, 3);
    dst = func_800BEE10(2, 4);
    j = (u8)func_800BEE10(4, 5);
    for (a = 0, b = j; b <= end; a++, b++) {
        ((FdRow *)D_80095DE0)[dst].c[b] = ((FdRow *)D_80095DE0)[src].c[a];
    }
    for (a = end - j, b = 0; a <= end; a++, b++) {
        ((FdRow *)D_80095DE0)[dst].c[b] = ((FdRow *)D_80095DE0)[src].c[a];
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 7;
    return 0;
}

s32 func_800CE054(void) {
    u8 dst;
    u8 src;
    u16 *pc;
    s16 n;
    s16 i;
    s16 end;
    s16 j;
    s16 a;
    s16 b;

    if (D_8009D820 & 3) {
        func_800BEAD4(D_800A0C70, 7);
    }
    n = (func_800BEE10(4, 7) & 0xFF) + 1;
    src = (D_8009C6DC + D_800831FC[D_800722C4])[3];
    dst = (D_8009C6DC + D_800831FC[D_800722C4])[4];
    i = (u8)func_800BEE10(1, 5);
    j = (u8)func_800BEE10(2, 6);
    end = n + i;
    for (a = i, b = j; b <= end; a++, b++) {
        ((FdRow *)D_80095DE0)[dst].c[b] = ((FdRow *)D_80095DE0)[src].c[a];
    }
    for (a = end - j, b = i; a <= end; a++, b++) {
        ((FdRow *)D_80095DE0)[dst].c[b] = ((FdRow *)D_80095DE0)[src].c[a];
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 8;
    return 0;
}

s32 func_800CE214(void) {
    s16 n;
    s16 i;
    s32 src;
    s32 dst;
    s32 r;
    s32 g;
    s32 b;
    s16 cr;
    s16 cg;
    s16 cb;
    u16 c;

    if (D_8009D820 & 3) {
        func_800BEAD4(&D_800A0C78, 8);
    }
    n = (D_8009C6DC + D_800831FC[D_800722C4])[9] + 1;
    src = func_800BEE10(1, 4);
    dst = func_800BEE10(2, 5);
    r = (u8)func_800BEE10(3, 6);
    g = (u8)func_800BEE10(4, 7);
    b = (u8)func_800BEE10(5, 8);
    if (r & 0x80) {
        r ^= 0xFF00;
    }
    if (g & 0x80) {
        g ^= 0xFF00;
    }
    if (b & 0x80) {
        b ^= 0xFF00;
    }
    for (i = 0; i < n; i++) {
        c = ((FdRow *)D_80095DE0)[(u8)src].c[i];
        cb = b + (c & 0x1F);
        if (cb >= 0x20) {
            cb = 0x1F;
        }
        if (cb < 0) {
            cb = 0;
        }
        cg = g + ((c >> 5) & 0x1F);
        if (cg >= 0x20) {
            cg = 0x1F;
        }
        if (cg < 0) {
            cg = 0;
        }
        cr = r + ((c >> 10) & 0x1F);
        if (cr >= 0x20) {
            cr = 0x1F;
        }
        if (cr < 0) {
            cr = 0;
        }
        ((FdRow *)D_80095DE0)[(u8)dst].c[i] = cb | ((cr << 10) | (cg << 5)) | (c & 0x8000);
        if (((FdRow *)D_80095DE0)[(u8)dst].c[i] == 0) {
            if (c != 0) {
                ((FdRow *)D_80095DE0)[(u8)dst].c[i] = 0x8000;
            }
        }
    }
    D_800831FC[D_800722C4] += 0xA;
    return 0;
}

s32 func_800CE480(void) {
    u8 dst;
    u8 src;
    s32 n;
    s16 j;
    u16 i;
    s32 r;
    s32 g;
    s32 b;
    s16 cr;
    s16 cg;
    s16 cb;
    u16 c;

    if (D_8009D820 & 3) {
        func_800BEAD4(&D_800A0C78, 8);
    }
    n = (func_800BEE10(6, 0xA) & 0xFF) + 1;
    src = (D_8009C6DC + D_800831FC[D_800722C4])[4];
    dst = (D_8009C6DC + D_800831FC[D_800722C4])[5];
    i = (u8)func_800BEE10(1, 6);
    r = (u8)func_800BEE10(2, 7);
    g = (u8)func_800BEE10(3, 8);
    b = (u8)func_800BEE10(4, 9);
    if (r & 0x80) {
        r ^= 0xFF00;
    }
    if (g & 0x80) {
        g ^= 0xFF00;
    }
    if (b & 0x80) {
        b ^= 0xFF00;
    }
    for (j = i; j < i + n; j++) {
        c = ((FdRow *)D_80095DE0)[src].c[j];
        cb = b + (c & 0x1F);
        if (cb >= 0x20) {
            cb = 0x1F;
        }
        if (cb < 0) {
            cb = 0;
        }
        cg = g + ((c >> 5) & 0x1F);
        if (cg >= 0x20) {
            cg = 0x1F;
        }
        if (cg < 0) {
            cg = 0;
        }
        cr = r + ((c >> 10) & 0x1F);
        if (cr >= 0x20) {
            cr = 0x1F;
        }
        if (cr < 0) {
            cr = 0;
        }
        ((FdRow *)D_80095DE0)[dst].c[j] = cb | ((cr << 10) | (cg << 5)) | (c & 0x8000);
        if (((FdRow *)D_80095DE0)[dst].c[j] == 0) {
            if (c != 0) {
                ((FdRow *)D_80095DE0)[dst].c[j] = 0x8000;
            }
        }
    }
    D_800831FC[D_800722C4] += 0xB;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CE6F4);

s32 func_800CE904(void) {
    u8 dst;
    u8 src;
    s32 n;
    s16 j;
    u16 i;
    s32 r;
    u16 g;
    u16 b;
    u32 cr;
    u32 cg;
    u32 cb;
    u16 c;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4(&D_800A0C80, 8);
    }
    n = (func_800BEE10(6, 0xA) & 0xFF) + 1;
    src = (D_8009C6DC + D_800831FC[D_800722C4])[4];
    dst = (D_8009C6DC + D_800831FC[D_800722C4])[5];
    i = (u8)func_800BEE10(1, 6);
    r = func_800BEE10(2, 7) & 0xFF;
    g = (u8)func_800BEE10(3, 8);
    b = func_800BEE10(4, 9) & 0xFF;
    for (j = i; j < i + n; j++) {
        c = ((FdRow *)D_80095DE0)[src].c[j];
        if (c != 0) {
            cb = (u32)(b * ((u16)(c << 1) & 0x3E)) >> 7;
            cg = (u32)(g * ((c >> 4) & 0x3F)) >> 7;
            cr = (u32)(r * ((c >> 9) & 0x3F)) >> 7;
            if (cr >= 0x20) {
                cr = 0x1F;
            }
            if (cg >= 0x20) {
                cg = 0x1F;
            }
            if (cb >= 0x20) {
                cb = 0x1F;
            }
            ((FdRow *)D_80095DE0)[dst].c[j] = cb | ((cr << 10) | (cg << 5)) | (c & 0x8000);
            if (((FdRow *)D_80095DE0)[dst].c[j] == 0) {
                ((FdRow *)D_80095DE0)[dst].c[j] = 0x8000;
            }
        }
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 0xB;
    return 0;
}

void func_800CEB20(void) {
    u8 temp_a0;

    if (*D_8009D391 != 0xFF) {
        temp_a0 = D_8009AD30[*D_8009D391];
        if ((temp_a0 != 0xFF) && (D_8007EB98[temp_a0] != 0xFF)) {
            M2C_FIELD(D_8009C6E0, s16 *, 0x2A) = (s16) D_8007EB98[temp_a0];
        }
    }
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0C68);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0C70);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0C78);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0C80);

s32 func_800CEB94(void) {
    s32 i;
    u8 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("pc", 1);
    }
    i = 0;
    c = M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    D_8009AD30[c] = D_800722C4;
    for (; i < 3; i++) {
        if (D_8009D391[i] == c) {
            if (i != 0) {
                ((FdEnt84B *)D_8009C544)[D_8007EB98[D_800722C4]].b5C = 0;
                ((FdEnt84B *)D_8009C544)[D_8007EB98[D_800722C4]].b59 = 1;
                ((FdEnt84B *)D_8009C544)[D_8007EB98[D_800722C4]].b5B = 1;
            } else {
                M2C_SFIELD(D_8009C6E0, s16 *, 0x2A) = D_8007EB98[D_800722C4];
            }
            D_800831FC[D_800722C4] += 2;
            return 0;
        }
    }
    D_8009AD30[c] = D_800722C4;
    ((FdEnt84B *)D_8009C544)[D_8007EB98[D_800722C4]].b5C = 0;
    ((FdEnt84B *)D_8009C544)[D_8007EB98[D_800722C4]].b59 = 1;
    ((FdEnt84B *)D_8009C544)[D_8007EB98[D_800722C4]].b5B = 1;
    D_800831FC[D_800722C4] += 2;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CEE44);

s32 func_800CF028(void) {
    s32 i;
    u8 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("prtym", 1);
    }
    c = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    for (i = 0; i < 3; i++) {
        if (D_8009D391[i] == c) {
            D_8009D391[i] = 0xFF;
            ((void (*)(s32))func_800CF5A0)(1);
            func_800CEB20();
            D_800831FC[D_800722C4] += 2;
            return 0;
        }
    }
    ((void (*)(s32))func_800CF5A0)(1);
    func_800CEB20();
    D_800831FC[D_800722C4] += 2;
    return 0;
}

s32 func_800CF140(void) {
    s32 i;
    u8 buf[3];
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("prtye", 3);
    }
    for (i = 0; i < 3; i++) {
        buf[i] = (D_8009C6DC + D_800831FC[D_800722C4])[i + 1];
    }
    func_800CF368(buf);
    pc = &D_800831FC[D_800722C4];
    *pc += 4;
    return 0;
}

s32 func_800CF200(void) {
    s32 i;
    u8 buf[3];
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("sptye", 5);
    }
    for (i = 0; i < 3; i++) {
        buf[i] = ((s32 (*)(s16, s16))func_800BEE10)(i + 1, i + 3);
    }
    func_800CF368(buf);
    pc = &D_800831FC[D_800722C4];
    *pc += 6;
    return 0;
}

s32 func_800CF2BC(void) {
    s32 i;
    u16 *temp_v0;

    if (D_8009D820 & 3) {
        func_800BEAD4("gptye", 5);
    }
    for (i = 0; i < 3; i++) {
        func_800BF3AC(i + 1, i + 3, D_8009D391[i]);
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 6;
    return 0;
}

void func_800CF368(volatile u8 *arg0) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        if (arg0[i] != 0xFF) {
            for (j = 0; j < 3; j++) {
                if (arg0[i] == D_8009D391[j]) {
                    D_8009D391[j] = 0xFF;
                }
            }
        }
    }
    for (j = 0; j < 3; j++) {
        if (D_8009D391[j] != 0xFF) {
            for (i = 0; i < 3; i++) {
                if (arg0[i] == 0xFF) {
                    arg0[i] = D_8009D391[j];
                    i = 3;
                }
            }
        }
    }
    i = 0;
    do {
        if (*arg0 == 0xFE) {
            *arg0 = 0xFF;
        }
        D_8009D391[i] = *arg0;
        i++;
        if (*arg0 != 0xFF) {
            D_8009D788[1] |= 1 << *arg0;
        }
        arg0++;
    } while (i < 3);
    ((void (*)(s32))func_800CF5A0)(1);
    func_800CEB20();
}

void func_800CF4CC(u8 *a, u8 *b, u8 *out1, u8 *out2) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        out1[i] = 0xFF;
        out2[i] = 0xFF;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (b[i] == a[j]) {
                goto found1;
            }
        }
        *out1++ = b[i];
    found1:;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (a[i] == b[j]) {
                goto found2;
            }
        }
        *out2++ = a[i];
    found2:;
    }
}

void func_800CF5A0(void) {
    u8 sp10[8];
    u8 sp18[8];

    func_800CF4CC(D_8009CBDC, D_8009CBDC + 0x7B5, sp10, sp18);
    func_800CF66C(D_8009CBDC, sp18);
    func_800CF6C0(D_8009CBDC, sp10);
    D_80071E34 = 1;
}

void func_800CF60C(void) {
    u8 sp10[8];
    u8 sp18[8];

    func_800CF4CC(D_8009D391, D_8009D391 - 0x7B5, sp10, sp18);
    func_800CF66C(D_8009D391, sp18);
    func_800CF6C0(D_8009D391, sp10);
}

void func_800CF66C(u8 *a, u8 *b) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (b[i] == a[j]) {
                a[j] = 0xFF;
            }
        }
    }
}

void func_800CF6C0(u8 *arg0, u8 *arg1) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (arg0[j] == 0xFF) {
                arg0[j] = arg1[i];
                break;
            }
        }
    }
}

s32 func_800CF718(void) {
    s32 i;
    u8 c;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("prtyq", 2);
    }
    c = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    for (i = 0; i < 3; i++) {
        if (D_8009D391[i] == c) {
            if (D_8009D820 & 3) {
                func_800BECA4("prty=TRUE", 0, 0);
            }
            D_800831FC[D_800722C4] += 3;
            return 0;
        }
    }
    if (D_8009D820 & 3) {
        func_800BECA4("prty=FALSE", 0, 0);
    }
    pc = &D_800831FC[D_800722C4];
    *pc += (D_8009C6DC + *pc)[2] + 2;
    return 0;
}

s32 func_800CF874(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("membq", 2);
    }
    if ((D_8009D788[1] >> (D_8009C6DC + D_800831FC[D_800722C4])[1]) & 1) {
        if (D_8009D820 & 3) {
            func_800BECA4("memb=TRUE", 0, 0);
        }
        D_800831FC[D_800722C4] += 3;
        return 0;
    } else {
        if (D_8009D820 & 3) {
            func_800BECA4("memb=FALSE", 0, 0);
        }
        pc = &D_800831FC[D_800722C4];
        *pc += (D_8009C6DC + *pc)[2] + 2;
        return 0;
    }
}

s32 func_800CF9B8(void) {
    s16 i;
    s16 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("mmb+-", 3);
    }
    c = (D_8009C6DC + D_800831FC[D_800722C4])[2];
    if ((D_8009C6DC + D_800831FC[D_800722C4])[1] != 0) {
        D_8009D78A[0] |= 1 << c;
    } else {
        D_8009D78A[0] &= ~(1 << c);
        for (i = 0; i < 3; i++) {
            if (D_8009D391[i] == c) {
                D_8009D391[i] = 0xFF;
            }
        }
    }
    D_800831FC[D_800722C4] += 3;
    return 0;
}

s32 func_800CFAF0(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("mmblk", 3);
    }
    p = &D_800831FC[D_800722C4];
    D_8009D788[0] |= 1 << (D_8009C6DC + *p)[1];
    *p += 2;
    return 0;
}

s32 func_800CFB84(void) {
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("mmbuk", 3);
    }
    temp_a0 = &D_800831FC[D_800722C4];
    *D_8009D788 &= ~(1 << M2C_FIELD(&D_8009C6DC[*temp_a0], u8 *, 1));
    *temp_a0 += 2;
    return 0;
}

s32 func_800CFC1C(void) {
    u16 *temp_v0;
    u8 temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("solid", 1);
    }
    temp_a0 = D_8007EB98[D_800722C4];
    if (temp_a0 != 0xFF) {
        M2C_FIELD(((temp_a0 * 0x84) + D_8009C544), u8 *, 0x59) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 2;
    return 0;
}

s32 func_800CFCE4(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("vwoft", 6);
    }
    if ((&D_8009C6DC[D_800831FC[D_800722C4]])[6] == 0) {
        M2C_SFIELD(D_8009C6E0, u16 *, 0x16) = func_800BF908(1, 2);
        M2C_FIELD(D_8009C6E0, s8 *, 0x12) = 0;
        M2C_FIELD(D_8009C6E0, s8 *, 0x13) = 0;
        M2C_FIELD(D_8009C6E0, u8 *, 0x14) = 0;
        pc = &D_800831FC[D_800722C4];
        M2C_FIELD(D_8009C6E0, u16 *, 0x18) = 0;
        M2C_FIELD(D_8009C6E0, s16 *, 0x1A) = 0;
        *pc += 7;
        return 0;
    } else {
        M2C_FIELD(D_8009C6E0, u16 *, 0x18) = M2C_FIELD(D_8009C6E0, u16 *, 0x16);
        M2C_FIELD(D_8009C6E0, s16 *, 0x1A) = func_800BF908(1, 2);
        M2C_FIELD(D_8009C6E0, s8 *, 0x12) = func_800BF908(2, 4);
        M2C_FIELD(D_8009C6E0, u8 *, 0x14) = (&D_8009C6DC[D_800831FC[D_800722C4]])[6];
        M2C_FIELD(D_8009C6E0, s8 *, 0x13) = 0;
        D_800831FC[D_800722C4] += 7;
        return 0;
    }
}

s32 func_800CFE78(void) {
    s16 a;
    s16 b;
    s16 i;
    u8 k;
    u8 t;

    if (D_8009D820 & 3) {
        func_800BEAD4("join", 1);
    }
    D_800E48F0 = D_800722C4;
    if (D_8009D392 != 0xFF) {
        a = func_800D0518(D_8009AD30[D_8009D392], M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1));
    } else {
        a = 1;
    }
    if (D_8009D393 != 0xFF) {
        b = func_800D0518(D_8009AD30[D_8009D393], M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1));
    } else {
        b = 1;
    }
    if (a != 0 && b != 0) {
        i = 0;
        do {
            t = D_8009D391[i];
            if (t != 0xFF) {
                D_80081D90[D_8009AD30[t]] = 0;
                if (i == 0) {
                    k = D_8009AD30[t];
                    if (k != 0xFF) {
                        ((FdJn84 *)D_8009C544)[D_8007EB98[k]].b59 = 0;
                    }
                }
            }
            i++;
        } while (i < 3);
        M2C_SFIELD(D_8009C6E0, u8 *, 0x32) = D_80081DC4;
        D_800E48F0 = 0xFF;
        D_800831FC[D_800722C4] += 2;
        return 0;
    }
    M2C_SFIELD(D_8009C6E0, u8 *, 0x32) = 1;
    if (D_8009D391[0] != 0xFF) {
        k = D_8009AD30[D_8009D391[0]];
        if (k != 0xFF) {
            D_80081D90[k] = 1;
            ((FdJn84 *)D_8009C544)[D_8007EB98[k]].b5D = 0;
            ((FdJn84 *)D_8009C544)[D_8007EB98[k]].s6A = 0;
            ((FdJn84 *)D_8009C544)[D_8007EB98[k]].b59 = 1;
        }
    }
    return 1;
}

s32 func_800D0180(void) {
    s32 c2;
    s32 x1;
    s32 y1;
    s32 x2;
    s32 y2;
    s32 a;
    s32 b;
    s16 i;
    s32 j;
    u8 e;
    u8 f;

    if (D_8009D820 & 3) {
        func_800BEAD4("split", 8);
    }
    a = D_8009D392;
    D_800E48F0 = D_800722C4;
    if (a == 0xFF) {
        a = 1;
    } else {
        x1 = (s16)func_800BF908(1, 4);
        y1 = (s16)func_800BF908(2, 6);
        a = func_800D0938(D_8009AD30[a], x1, y1, func_800BEE10(3, 8) & 0xFF, (D_8009C6DC + D_800831FC[D_800722C4])[0xE]);
    }
    c2 = D_8009D393;
    if (c2 == 0xFF) {
        b = 1;
    } else {
        x2 = (s16)func_800BF908(4, 9);
        y2 = (s16)func_800BF908(5, 0xB);
        b = func_800D0938(D_8009AD30[c2], x2, y2, func_800BEE10(6, 0xD) & 0xFF, (D_8009C6DC + D_800831FC[D_800722C4])[0xE]);
    }
    if ((s16)a != 0 && (s16)b != 0) {
        i = 0;
        do {
            j = i;
            e = D_8009D391[j];
            if (e != 0xFF) {
                D_80081D90[D_8009AD30[e]] = 0;
                if (j == 0) {
                    f = D_8009AD30[e];
                    if (f != 0xFF) {
                        (D_8009C544 + D_8007EB98[f] * 0x84)[0x59] = 0;
                    }
                }
            }
            i++;
        } while (i < 3);
        D_8009C6E0[0x32] = D_80081DC4;
        D_800E48F0 = 0xFF;
        D_800831FC[D_800722C4] += 0xF;
        return 0;
    }
    D_8009C6E0[0x32] = 1;
    if (D_8009D391[0] != 0xFF) {
        f = D_8009AD30[D_8009D391[0]];
        if (f != 0xFF) {
            D_80081D90[f] = 1;
            (D_8009C544 + D_8007EB98[f] * 0x84)[0x5D] = 0;
            *(s16 *)(D_8009C544 + D_8007EB98[f] * 0x84 + 0x6A) = 0;
            (D_8009C544 + D_8007EB98[f] * 0x84)[0x59] = 1;
        }
    }
    return 1;
}

s32 func_800D0518(s16 arg0, s16 arg1) {
    FdVec a;
    FdVec b;
    s32 d;
    s32 t;
    u8 m;

    if (D_8009D391[0] == 0xFF) {
        return 1;
    }
    t = D_8009AD30[D_8009D391[0]];
    if (D_8009D820 & 3) {
        func_800BECA4("join p0=", t, 2);
        if (D_8009D820 & 3) {
            func_800BECA4("join p1=", arg0, 2);
        }
    }
    m = t;
    if (m == 0xFF || arg0 == 0xFF) {
        return 1;
    }
    switch (D_80081D90[arg0]) {
    case 0:
        a.x = *(s32 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0xC) >> 12;
        a.y = *(s32 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0x10) >> 12;
        a.z = *(s32 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0x14) >> 12;
        b.x = *(s32 *)(D_8009C544 + D_8007EB98[m] * 0x84 + 0xC) >> 12;
        b.y = *(s32 *)(D_8009C544 + D_8007EB98[m] * 0x84 + 0x10) >> 12;
        b.z = *(s32 *)(D_8009C544 + D_8007EB98[m] * 0x84 + 0x14) >> 12;
        func_800D1350(arg0, *(u8 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0x38), func_800A8640(&a, &b, &d) & 0xFF);
        D_80081D90[arg0] = 2;
        break;
    case 1:
        if (func_800D1200(arg0) != 0) {
            *(u8 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0x59) = 1;
            *(u8 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0x5B) = 1;
            *(u8 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0x5C) = 0;
            D_80081D90[arg0] = 3;
            return 1;
        }
        break;
    case 2:
        if (func_800D152C(arg0) != 0) {
            func_800D0B4C(arg0, (*(s32 *)(D_8009C544 + D_8007EB98[m] * 0x84 + 0xC) * 0x10) >> 0x10, (*(s32 *)(D_8009C544 + D_8007EB98[m] * 0x84 + 0x10) * 0x10) >> 0x10, arg1, 0);
            D_80081D90[arg0] = 1;
            if (D_8009D820 & 3) {
                func_800BECA4("end setmove", 0, 0);
                return 0;
            }
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0D60);

s32 func_800D0938(s16 w, s16 x, s16 y, s32 a3, s16 a4) {
    if (D_8009D820 & 3) {
        func_800BECA4(D_800A0D60, w, 2);
    }
    if (w == 0xFF) {
        return 1;
    }
    switch (D_80081D90[w]) {
    case 0:
        func_800D0B4C(w, x, y, a4, 1);
        D_80081D90[w] = 1;
        break;
    case 1:
        if (func_800D1200(w) != 0) {
            M2C_FIELD(D_8007EB98[w] * 0x84 + D_8009C544, s8 *, 0x59) = 0;
            M2C_FIELD(D_8007EB98[w] * 0x84 + D_8009C544, s8 *, 0x5B) = 0;
            func_800D1350(w, M2C_FIELD(D_8007EB98[w] * 0x84 + D_8009C544, u8 *, 0x38), a3 & 0xFF);
            D_80081D90[w] = 2;
        }
        break;
    case 2:
        if (func_800D152C(w) != 0) {
            D_80081D90[w] = 3;
            return 1;
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800D0B4C);

s32 func_800D1200(s16 arg0) {
    u8 c;

    if (*(s16 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0x6A) == 2) {
        if (D_8009D820 & 3) {
            func_800BECA4("end move", 0, 0);
        }
        *(s8 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0x5D) = 0;
        *(s16 *)(D_8009C544 + D_8007EB98[arg0] * 0x84 + 0x6A) = 0;
        D_800756E8[D_8007EB98[arg0]] = 0;
        c = D_8007EB98[arg0];
        *(u16 *)(D_8009C544 + c * 0x84 + 0x70) = D_800E42A8[c];
        return 1;
    }
    return 0;
}

void func_800D1350(s16 n, s32 from, s32 to) {
    u8 *p;
    u16 b;
    u16 a;
    s16 d;
    s16 m;

    if (D_8009D820 & 3) {
        func_800BECA4("set turn=", to & 0xFF, 2);
    }
    if (D_8007EB98[n] != 0xFF) {
        *(u16 *)(D_8009C544 + D_8007EB98[n] * 0x84 + 0x3C) = from & 0xFF;
        (D_8009C544 + D_8007EB98[n] * 0x84)[0x3B] = 2;
        (D_8009C544 + D_8007EB98[n] * 0x84)[0x3A] = 0;
        (D_8009C544 + D_8007EB98[n] * 0x84)[0x39] = 0x10;
        *(u16 *)(D_8009C544 + D_8007EB98[n] * 0x84 + 0x3E) = to & 0xFF;
        p = D_8009C544 + D_8007EB98[n] * 0x84;
        b = *(u16 *)(p + 0x3E);
        a = *(u16 *)(p + 0x3C);
        d = b - a;
        m = d;
        if (d < 0) {
            m = ~d + 1;
        }
        if (m > 0x80) {
            if ((s16)b > (s16)a) {
                *(u16 *)(p + 0x3E) = b - 0x100;
            } else {
                *(u16 *)(p + 0x3E) = b + 0x100;
            }
        }
    }
}

s32 func_800D152C(s16 arg0) {
    if (D_8007EB98[arg0] == 0xFF) {
        return 1;
    }
    if (M2C_FIELD(D_8009C544 + D_8007EB98[arg0] * 0x84, u8 *, 0x3B) == 3) {
        if (D_8009D820 & 3) {
            func_800BECA4("end turn", 0, 0);
        }
        M2C_FIELD(D_8009C544 + D_8007EB98[arg0] * 0x84, u8 *, 0x3B) = 0;
        M2C_FIELD(D_8009C544 + D_8007EB98[arg0] * 0x84, u8 *, 0x3A) = 0;
        M2C_FIELD(D_8009C544 + D_8007EB98[arg0] * 0x84, u8 *, 0x39) = 0;
        return 1;
    }
    return 0;
}

s32 func_800D1654(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("fade", 8);
    }
    M2C_FIELD(D_8009C6E0, u16 *, 0x4C) = (D_8009C6DC + D_800831FC[D_800722C4])[7];
    switch ((s16)*(volatile u16 *)(D_8009C6E0 + 0x4C)) {
    case 0:
    case 3:
    case 4:
        break;
    case 1:
    case 5:
    case 7:
    case 9:
        M2C_FIELD(D_8009C6E0, s16 *, 0x4E) = (D_8009C6DC + D_800831FC[D_800722C4])[8] + 1;
        break;
    case 2:
    case 6:
    case 8:
    case 10:
        M2C_FIELD(D_8009C6E0, s16 *, 0x4E) = (D_8009C6DC + D_800831FC[D_800722C4])[8];
        break;
    }
    *(volatile s16 *)(D_8009C6E0 + 0x50) = (D_8009C6DC + D_800831FC[D_800722C4])[6];
    M2C_FIELD(D_8009C6E0, s16 *, 0x52) = func_800BEE10(1, 3) & 0xFF;
    M2C_FIELD(D_8009C6E0, s16 *, 0x54) = func_800BEE10(2, 4) & 0xFF;
    M2C_SFIELD(D_8009C6E0, s16 *, 0x56) = func_800BEE10(4, 5) & 0xFF;
    D_800831FC[D_800722C4] += 9;
    return 0;
}

s32 func_800D184C(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("nfade", 8);
    }
    M2C_FIELD(D_8009C6E0, volatile s16 *, 0x4C) = (D_8009C6DC + D_800831FC[D_800722C4])[3];
    M2C_FIELD(D_8009C6E0, s16 *, 0x5E) = (u8)func_800BEE10(1, 4);
    M2C_FIELD(D_8009C6E0, s16 *, 0x60) = (u8)func_800BEE10(2, 5);
    M2C_FIELD(D_8009C6E0, s16 *, 0x62) = (u8)func_800BEE10(3, 6);
    M2C_FIELD(D_8009C6E0, volatile s16 *, 0x4E) = 0;
    M2C_SFIELD(D_8009C6E0, s16 *, 0x50) = func_800BF908(4, 7);
    pc = &D_800831FC[D_800722C4];
    *pc += 9;
    return 0;
}

s32 func_800D195C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("fadew", 0);
    }
    switch ((s16)M2C_FIELD(D_8009C6E0, volatile u16 *, 0x4C)) {
    case 1:
    case 5:
    case 7:
    case 9:
        if (M2C_FIELD(D_8009C6E0, volatile u16 *, 0x4E) == 0) {
            break;
        }
        return 1;
    case 2:
    case 6:
    case 8:
    case 10:
        if ((s16)M2C_FIELD(D_8009C6E0, volatile u16 *, 0x4E) >= 0xFF) {
            break;
        }
        return 1;
    default:
        if ((s16)M2C_FIELD(D_8009C6E0, volatile u16 *, 0x4E) != (s16)M2C_FIELD(D_8009C6E0, volatile u16 *, 0x50)) {
            return 1;
        }
        break;
    case 0:
    case 4:
        break;
    }
    D_800831FC[D_800722C4] += 1;
    return 0;
}

s32 func_800D1A80(void) {
    s32 n;
    s32 idx;
    s32 bit;

    if (D_8009D820 & 3) {
        func_800BEAD4("idlck", 3);
    }
    n = (s16)((D_8009C6DC + D_800831FC[D_800722C4])[1] | ((D_8009C6DC + D_800831FC[D_800722C4])[2] << 8));
    idx = n / 8;
    bit = n - idx * 8;
    if ((D_8009C6DC + D_800831FC[D_800722C4])[3]) {
        (D_8009C6E0 + idx)[0xB2] |= 1 << bit;
    } else {
        (D_8009C6E0 + idx)[0xB2] &= ~(1 << bit);
    }
    D_800831FC[D_800722C4] += 4;
    return 0;
}

s32 func_800D1B94(void) {
    s16 n;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("gwcol", 6);
    }
    n = (u8)func_800BEE10(1, 3);
    n = n * 3;
    func_800BF3AC(2, 4, D_80049208[n]);
    func_800BF3AC(3, 5, D_80049208[n + 1]);
    func_800BF3AC(4, 6, D_80049208[n + 2]);
    pc = &D_800831FC[D_800722C4];
    *pc += 7;
    return 0;
}

s32 func_800D1C68(void) {
    s16 n;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("swcol", 6);
    }
    n = (u8)func_800BEE10(1, 3);
    n = n * 3;
    D_80049208[n] = func_800BEE10(2, 4);
    D_80049208[n + 1] = func_800BEE10(3, 5);
    D_80049208[n + 2] = func_800BEE10(4, 6);
    pc = &D_800831FC[D_800722C4];
    *pc += 7;
    return 0;
}

s32 func_800D1D3C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("lstmp", 2);
    }
    func_800C0248(2, 2, *(s16 *)(D_8009C6E0 + 0x64));
    D_800831FC[D_800722C4] += 3;
    return 0;
}

s32 func_800D1DB8(void) {
    u8 f;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("shake", 7);
    }
    f = (D_8009C6DC + D_800831FC[D_800722C4])[3];
    if (f & 1) {
        D_8009C6E0[0x8A] = 1;
        *(s16 *)(D_8009C6E0 + 0x8E) = func_800BEE10(1, 4) & 0xFF;
        *(s16 *)(D_8009C6E0 + 0x94) = func_800BEE10(2, 5) & 0xFF;
    } else {
        D_8009C6E0[0x8A] = 0;
    }
    if (f & 2) {
        D_8009C6E0[0x98] = 1;
        *(s16 *)(D_8009C6E0 + 0x9C) = func_800BEE10(3, 6) & 0xFF;
        *(s16 *)(D_8009C6E0 + 0xA2) = func_800BEE10(4, 7) & 0xFF;
    } else {
        D_8009C6E0[0x98] = 0;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 8;
    return 0;
}

s32 func_800D1F20(void) {
    s32 temp_s0;
    s32 temp_s0_2;
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("stitm", 4);
    }
    temp_s0 = (func_800BEE10(2, 4) & 0xFF) << 9;
    temp_s0_2 = temp_s0 | func_800BF908(1, 2);
    if (D_8009D820 & 3) {
        func_800BECA4("S item=", temp_s0_2 & 0xFFFF, 4);
    }
    func_80025380(temp_s0_2 & 0xFFFF);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 5;
    return 0;
}

s32 func_800D1FDC(void) {
    s32 temp_s0;
    s32 temp_s0_2;
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("dlitm", 4);
    }
    temp_s0 = (func_800BEE10(2, 4) & 0xFF) << 9;
    temp_s0_2 = temp_s0 | func_800BF908(1, 2);
    if (D_8009D820 & 3) {
        func_800BECA4("G item=", temp_s0_2 & 0xFFFF, 4);
    }
    func_80025288(temp_s0_2 & 0xFFFF);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 5;
    return 0;
}

s32 func_800D2098(void) {
    s32 var_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("ckitm", 4);
    }
    var_s0 = func_80025310(func_800BF908(1, 2) & 0xFFFF);
    if (D_8009D820 & 3) {
        func_800BECA4("C item=", var_s0 & 0xFFFF, 4);
    }
    if ((var_s0 & 0xFFFF) == 0xFFFF) {
        var_s0 = 0;
    }
    func_800BF3AC(2, 4, (u8) ((u32) (var_s0 & 0xFFFF) >> 9));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

s32 func_800D2164(void) {
    s32 i;
    s32 j;
    u8 *q;
    s32 sub;
    u16 n;
    s32 base;
    u16 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("spcal", 8);
    }
    switch ((D_8009C6DC + D_800831FC[D_800722C4])[1]) {
    case 0xFF:
        i = 0;
        if (D_8009D820 & 3) {
            func_800BEAD4("clitm", 8);
        }
        do {
            j = i | 0xC600;
            func_80025288(j);
            i++;
        } while (i < 0x200);
        D_800831FC[D_800722C4] += 2;
        return 0;
    case 0xFE:
        if (D_8009D820 & 3) {
            func_800BEAD4("rsglb", 8);
        }
        func_80033A90();
        D_800831FC[D_800722C4] += 2;
        return 0;
    case 0xFD:
        if (D_8009D820 & 3) {
            func_800BEAD4("spcnm", 8);
        }
        func_800D7C98((D_8009C6DC + D_800831FC[D_800722C4])[2], (D_8009C6DC + D_800831FC[D_800722C4])[3]);
        D_800831FC[D_800722C4] += 4;
        return 0;
    case 0xFC:
        if (D_8009D820 & 3) {
            func_800BEAD4("mvlck", 2);
        }
        D_800716CC = (D_8009C6DC + D_800831FC[D_800722C4])[2];
        D_800831FC[D_800722C4] += 3;
        return 0;
    case 0xFB:
        if (D_8009D820 & 3) {
            func_800BEAD4("btlck", 2);
        }
        D_80071E30 = (D_8009C6DC + D_800831FC[D_800722C4])[2];
        D_800831FC[D_800722C4] += 3;
        return 0;
    case 0xFA:
        i = 0;
        if (D_8009D820 & 3) {
            func_800BEAD4("flitm", 8);
        }
        do {
            j = i | 0xC600;
            func_80025380(j);
            i++;
        } while (i < 0x200);
        D_800831FC[D_800722C4] += 2;
        return 0;
    case 0xF9:
        i = 0;
        if (D_8009D820 & 3) {
            func_800BEAD4("flmat", 8);
        }
        do {
            func_8002542C(i);
            i++;
        } while (i < 0x50);
        D_800831FC[D_800722C4] += 2;
        return 0;
    case 0xF8:
        if (D_8009D820 & 3) {
            func_800BEAD4("smspd", 3);
        }
        D_8009D7D0[0] = ~func_800BEE10(4, 3);
        D_800831FC[D_800722C4] += 4;
        return 0;
    case 0xF7:
        if (D_8009D820 & 3) {
            func_800BEAD4("gmspd", 3);
        }
        func_800BF3AC(4, 3, ~D_8009D7D0[0]);
        D_800831FC[D_800722C4] += 4;
        return 0;
    case 0xF6:
        if (D_8009D820 & 3) {
            func_800BEAD4("pname", 8);
        }
        q = func_800257CC(func_800BEE10(3, 3) & 0xFF);
        sub = (D_8009C6DC + D_800831FC[D_800722C4])[2] & 0xF;
        c = (D_8009C6DC + D_800831FC[D_800722C4])[5];
        base = 0;
        switch (sub) {
        case 0xF:
            base += 0x100;
        case 0xD:
            base += 0x100;
        case 0xB:
            base += 0x100;
        case 3:
            base += 0x100;
        }
        n = c;
        for (i = 0; i < n; i++) {
            D_8009D288[(base & 0xFFFF) + i] = *q;
            q++;
        }
        D_8009D288[(base & 0xFFFF) + i] = 0xFF;
        D_800831FC[D_800722C4] += 6;
        return 0;
    case 0xF5:
        if (D_8009D820 & 3) {
            func_800BEAD4("arrow", 8);
        }
        D_80071C1C = (D_8009C6DC + D_800831FC[D_800722C4])[2];
        D_800831FC[D_800722C4] += 3;
        return 0;
    default:
        if (D_8009D820 & 3) {
            func_800BEAD4("?????", 8);
        }
        D_800831FC[D_800722C4] += 2;
        return 0;
    }
}
