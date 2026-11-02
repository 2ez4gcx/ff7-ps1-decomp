#include "common.h"
#include "magic_knights/decls.h"

void func_801B0050(void) {
    func_801BE87C();
}

MgMat *func_801B0070(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EC474.m[0][0] = D_801EC474.m[1][1] = D_801EC474.m[2][2] = scale;
    func_8003B48C(&D_801EE9AC);
    func_8003B51C(&D_801EE9AC);
    func_8003BC6C(v, (MgVec *)D_801EC474.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EC474.t, &n);
        D_801EC474.t[0] += (dist * n.vx) >> 12;
        D_801EC474.t[1] += (dist * n.vy) >> 12;
        D_801EC474.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EC474);
    func_8003B51C(&D_801EC474);
    return &D_801EC474;
}

void func_801B018C(s32 arg0, s32 arg1, MgSVec *arg2) {
    MgMat m;

    arg2->vx = D_80151A6C[arg0].c[arg1].x - D_801EE9AC.t[0];
    arg2->vy = D_80151A6C[arg0].c[arg1].y - D_801EE9AC.t[1];
    arg2->vz = D_80151A6C[arg0].c[arg1].z - D_801EE9AC.t[2];
    func_8003BF3C(&D_801EE9AC, &m);
    func_8003B2CC(&m, arg2, arg2);
}

void func_801B0264(MgMat *arg0, MgSVec *arg1) {
    MgMat m;

    arg1->vx = arg0->t[0] - D_801EE9AC.t[0];
    arg1->vy = arg0->t[1] - D_801EE9AC.t[1];
    arg1->vz = arg0->t[2] - D_801EE9AC.t[2];
    ((void (*)(MgMat *, MgMat *, MgMat *))func_8003BF3C)(&D_801EE9AC, &m, arg0);
    func_8003B2CC(&m, arg1, arg1);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B02E8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B0DA8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B1244);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B15E8);

void func_801B1C30(MgMat *arg0, u16 *arg1) {
    s32 sp10;
    s32 sp14;
    MgHalf *p;
    MgHalf *q;
    MgHalf *r;
    MgWord *w;

    func_80044AC0((s32)D_801ED128, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801ED128);
    p = (MgHalf *)&D_801EC4D0;
    p->v = D_801EC4E0.v = arg1[2];
    D_801EC4DA = D_801EC4E2 = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)p - 0x10));
    func_8003B64C(&sp10, &sp14);
    func_8003B6BC((s16)arg1[2] / 2, (s16)arg1[3] / 2);
    func_8003B48C(arg0);
    func_8003B51C(arg0);
    w = (MgWord *)&D_801EC4A0;
    w->v = D_8016209C;
    D_80163C74 = func_801B02E8((s32 *)w, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B6BC(sp10, sp14);
    q = (MgHalf *)&D_801EC4BC;
    q->v = arg1[2];
    D_801EC4BE = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)q - 0xC));
    func_80044978(D_801ED168, arg1);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801ED168);
    r = (MgHalf *)&D_801ED180;
    r->v = arg1[0];
    D_801ED182 = arg1[1];
    func_800449FC(D_801ED174, r);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801ED174);
}

s32 func_801B1E40(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801FA76E[-v];
    }
    return v;
}

s32 func_801B1E7C(s32 a, s32 b) {
    s32 i;
    s32 n;
    s32 orig;

    orig = a;
    if (b > 0) {
        n = b >> 8;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
    } else if (b < 0) {
        b = -b;
        n = b >> 8;
        a = 0x1000 - a;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
        a = 0x1000 - a;
    } else {
        return a;
    }
    n = (b & 0xFF) + 1;
    a = (a * n + orig * (0x100 - n)) >> 8;
    return a;
}

void func_801B1F74(s32 arg0, s32 arg1, s32 arg2, MgSVec *arg3) {
    u8 pad[0x20];

    if (arg1 != -1) {
        func_801B0264((MgMat *)&D_801ED23C[arg0].e[arg1 * 0x34], arg3);
    } else {
        arg3->vx = D_801ED23C[arg0].v.vx;
        arg3->vy = D_801ED23C[arg0].v.vy;
        arg3->vz = D_801ED23C[arg0].v.vz;
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B2048);

void func_801B3154(s32 arg0, s32 arg1, s16 arg2) {
    D_8016207C = &func_801B2048;
    D_801635D8 = 0;
    D_801635E4 = arg0;
    D_801635E8 = arg1;
    D_801635EC = arg2;
    D_80162080 += 1;
}

void func_801B31A0(void) {
    MgTask *p;
    s32 t;
    s32 d;
    s32 v;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        d = p->unk6;
        if (t < d) {
            d = (t << 12) / d;
            v = (p->unk4 * d) >> 12;
        } else {
            t -= d;
            if (t < p->unk8) {
                v = p->unk4;
            } else {
                t -= p->unk8;
                d = p->unkA;
                if (t >= d) {
                    p->unk0 = -1;
                    D_800FA666[0] = 0;
                    return;
                }
                d = (t << 12) / d;
                v = (p->unk4 * (0x1000 - d)) >> 12;
            }
        }
        D_800FA666[0] = (p->unk2 & 1) ? v : -v;
        p->unk2++;
    }
}

void func_801B32DC(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B31A0)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

void func_801B3350(void) {
    MgMat m;

    D_801EC868 = D_801EC334;
    D_801EC858 = D_801EC334;
    if (D_801EC32E != 0) {
        D_801EC874 = D_801EC350;
    } else {
        D_801EC874 = -D_801EC350;
    }
    func_8003A63C(&D_801EC838, &D_801EC858, &m);
    func_801B1C30(&m, &D_801EC878);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B33E0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B3748);

void func_801B3890(void) {
    MgTask *p;
    s32 t;
    s32 u;
    s32 i;
    s32 j;
    s32 a;
    s32 *src;
    u8 *d;
    u8 *e;
    u8 *n;
    u8 *m;
    u8 *row;
    s32 w;
    s32 x;
    s32 y;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    u = (s16)t;
    if (t == 0) {
        func_801B3350();
        func_801B33E0();
        p->unk2++;
        return;
    }
    if (u < 0x28) {
        if (u < 0xA) {
            a = (u << 12) / 10;
            if (D_80062D98 == 0) {
                a = func_801B1E7C(a, 0x2FF);
                func_801B3748(a * 1000 >> 12, (-(a << 5) >> 12) + 0x80, (-(a * 0x60) >> 12) + 0x80);
            }
        } else {
            a = ((u - 0xA) << 12) / 30;
            if (D_80062D98 == 0) {
                a = func_801B1E7C(a, 0);
                func_801B3748((a * 500 >> 12) + 0x3E8, (-(a * 0x60) >> 12) + 0x60, (-(a << 5) >> 12) + 0x20);
            }
        }
        func_8003B48C(&D_801EE9AC);
        func_8003B51C(&D_801EE9AC);
        for (i = 0; i < 0x10; i++) {
            for (j = 0; j < 0x20; j++) {
                src = (s32 *)(D_801EC834 + (i * 0xF00 + 0x1100) + j * 0x78);
                m = (u8 *)src + (D_801EC880 * 0x34 + 0x10);
                *(s32 *)(D_801EC884 + 0x18) = func_8003BD7C(src[0], src[1], src[2], src[3], m + 8, m + 0x14, m + 0x20, m + 0x2C, D_801EC884 + 0x1C, D_801EC884 + 0x20);
                if ((*(s32 *)(D_801EC884 + 0x20) & 0x60000) == 0) {
                    w = D_801EC880 * 0x34;
                    row = D_801EC834 + i * 4;
                    x = *(s32 *)(row + 0x10100);
                    *(s32 *)(w + (s32)src + 0x20) = x;
                    *(s32 *)(w + (s32)src + 0x14) = x;
                    y = *(s32 *)(row + 0x10104);
                    *(s32 *)(w + (s32)src + 0x38) = y;
                    *(s32 *)(w + (s32)src + 0x2C) = y;
                    func_80046794(D_801517C0 + 0x4078, (u8 *)src + (w + 0x10));
                }
            }
        }
        D_801EC880 ^= 1;
    } else if ((u -= 0x28) < 0x1E) {
        d = D_80163C74;
        e = D_801EC884;
        *(s16 *)(e + 0x12) = 0;
        *(s16 *)(e + 0xA) = 0;
        *(s16 *)(e + 4) = 0;
        *(s16 *)(e + 2) = 0;
        *(s16 *)(e + 0) = 0;
        func_8003B48C(&D_801EE9AC);
        func_8003B51C(&D_801EE9AC);
        n = d + 0x10;
        for (i = 0; i < 0x20; i++) {
            *(s16 *)(D_801EC884 + 8) = (u32)(func_80039A74(i << 7) * 0x11D) >> 8;
            *(s16 *)(D_801EC884 + 0xC) = (u32)(func_80039B40(i << 7) * 0x11D) >> 8;
            *(s16 *)(D_801EC884 + 0x10) = (u32)(func_80039A74((i + 1) << 7) * 0x11D) >> 8;
            *(s16 *)(D_801EC884 + 0x14) = (u32)(func_80039B40((i + 1) << 7) * 0x11D) >> 8;
            func_8003BC0C(D_801EC884, D_801EC884 + 8, D_801EC884 + 0x10, d + 8, d + 0xC, n, D_801EC884 + 0x1C, D_801EC884 + 0x20);
            if ((*(s32 *)(D_801EC884 + 0x20) & 0x60000) == 0) {
                *(s32 *)d = 0x04000000;
                *(s32 *)(n - 0xC) = 0x20000000;
                func_80046794(D_801517C0 + 0x4078, d);
                n += 0x14;
                d += 0x14;
            }
        }
        D_80163C74 = d;
    } else if ((u = t - 0x32) >= 0x1E && (u = t - 0x50) >= 0x1E) {
        p->unk0 = -1;
        return;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B3DB0);

s32 func_801B40F4(s32 arg0) {
    s32 k;
    s32 a;
    s32 b;

    arg0 = arg0 / 48;
    k = arg0 / 6;
    if (k < 0x10) {
        a = *(s16 *)(D_801EC834 + (k << 8) + 2);
        b = *(s16 *)(D_801EC834 + ((k + 1) << 8) + 2);
        return a + (((b - a) * (((arg0 - k * 6) << 12) / 6)) >> 12);
    }
    return 0;
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4198);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B440C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4694);

void func_801B4B04(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B4694)];
    p->unk0 = arg0;
    p->unkC = func_80042DA8() & 0xFFF;
    D_801FA748[arg0] = p;
}

void func_801B4B70(MgMat *arg0, MgMat *arg1, MgMat *arg2) {
    s32 *t;

    arg2->t[0] = arg1->t[0] - arg0->t[0];
    arg2->t[1] = arg1->t[1] - arg0->t[1];
    arg2->t[2] = arg1->t[2] - arg0->t[2];
    func_8003BF3C(arg0, arg2);
    t = arg2->t;
    func_8003AB84(arg2, t, t);
    func_8003B16C(arg1, arg2);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4BF8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4E78);

void func_801B5670(s32 arg0, s32 arg1, s32 arg2) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B4E78)];
    *(s32 *)&p->unk18 = arg0;
    p->unk1C = arg1;
    *(s32 *)&p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B56D4);

void func_801B5B24(void *arg0) {
    s32 temp_a1;
    s32 temp_v0;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0xBA0);
    if (temp_a1 != -1) {
        temp_v0 = func_800D376C(arg0 + 0x40, temp_a1, M2C_FIELD(arg0, s16 *, 0xBA4), M2C_FIELD(arg0, s32 *, 0xB9C));
        M2C_FIELD(arg0, s32 *, 0xBA0) = temp_v0;
        if (temp_v0 == 0) {
            M2C_FIELD(arg0, s32 *, 0xBA0) = -1;
        }
    }
}

void func_801B5B7C(u16 *arg0, KnDst *arg1) {
    s16 *a;
    u16 *b;
    s32 n;
    s32 t;
    s32 i;
    u32 w;

    a = (s16 *)arg0 + 2;
    t = arg0[0] + 1;
    arg1->n = t;
    n = (s16)t;
    for (i = 0; i < n; i++) {
        b = (u16 *)a + 2;
        arg1->e[i].unk30 = &arg1->e[*a];
        arg1->e[i].unk2A = 0;
        arg1->e[i].unk28 = 0;
        arg1->e[i].unk2C = arg1->h[*a];
        arg1->h[i] = b[-1];
        w = *(u32 *)b & 0x7FFFFFFF;
        if (w != 0) {
            arg1->p[i] = (u8 *)arg0 + w;
        } else {
            arg1->p[i] = 0;
        }
        a += 4;
    }
}

void func_801B5C5C(KnHdr *arg0, KnDst2 *arg1, void *arg2) {
    MgSVec sp10;
    MgSVec sp18;
    MgMat sp20;
    MgTask *q;
    s32 n;

    q = &D_80162978[func_800BBEAC(arg2)];
    func_800C610C();
    func_801B5B7C((u16 *)((u8 *)arg0 + arg0->unk4 * 4), (KnDst *)arg1);
    n = arg0->unk8 * 4;
    arg1->unkBA0 = 0;
    arg1->unk28 = 0;
    arg1->unk26 = 0;
    arg1->unk24 = 0;
    arg1->unkBA8 = 0;
    arg1->unkA6C = 0;
    arg1->unkA6A = 0;
    arg1->unkA68 = 0;
    arg1->unkBA6 = 0x1000;
    arg1->unkB9C = (u8 *)arg0 + n;
    arg1->unkBB0 = D_801EC354[D_801EC92C];
    arg1->unkBAA = 0;
    arg1->unkBAC = D_801EC370[D_801EC92C];
    arg1->unk0 = 0;
    *(KnDst2 **)((u8 *)q + 0x14) = arg1;
    func_8003B2CC(&D_801EC334, &D_801EC3A4[D_801EC92C * 2], &sp10);
    sp10.vx += D_801EC348;
    sp10.vy += D_801EC34C;
    sp10.vz += *(u16 *)((u8 *)&D_801EC34C + 4);
    func_8003B2CC(&D_801EC334, &D_801EC3A4[D_801EC92C * 2 + 1], &sp18);
    sp18.vx += D_801EC348;
    sp18.vy += D_801EC34C;
    sp18.vz += *(u16 *)((u8 *)&D_801EC348 + 8);
    func_800D85B0(&sp20, &sp18, &sp10, D_800E7D10);
    func_8003A63C(&sp20, &D_801EC334, &arg1->unkBB4);
    D_801EC92C++;
}

s32 func_801B5E4C(void) {
    MgTask *p;
    s32 id;

    if (D_80062D98 == 0) {
        while (1) {
            id = D_801517F0[D_801EC930];
            if (id == 0xFF) {
                break;
            }
            p = func_800D4FA8(0xA);
            p->unk0 = id;
            p->unk10 = D_801EC930;
            D_801EC930++;
            if (D_801517F0[D_801EC930] <= D_801517F0[D_801EC930 - 1]) {
                break;
            }
        }
    }
}

void func_801B5F0C(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_801B0070((MgSVec *)&p->unk4, 0x6000, 0);
    frame = &D_801EC93C;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= D_801C8F74.v) {
            p->unk0 = -1;
        } else {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unkC = p->unkC * 15 >> 4;
            p->unkE = p->unkE * 15 >> 4;
            p->unk10 = p->unk10 * 15 >> 4;
        }
    }
}

void func_801B603C(MgSVec *arg0) {
    MgSVec sp10;
    MgSVec sp18;
    MgVec sp20;
    MgMat sp30;
    MgTask *q;
    s32 i;
    s32 j;

    if (D_80062D98 == 0) {
        for (i = 0; i < 10; i++) {
            if ((D_801EE9CC >> i) & 1) {
                for (j = 0; j < 3; j++) {
                    q = &D_80162978[func_800BBEAC(&func_801B5F0C)];
                    func_801B018C(i, D_8015190F[i][0], &sp10);
                    *(MgB8 *)&q->unk4 = *(MgB8 *)&sp10;
                    sp20.vx = sp10.vx - arg0->vx;
                    sp20.vy = sp10.vy - arg0->vy;
                    sp20.vz = sp10.vz - arg0->vz;
                    func_8003A078(&sp20, &sp10);
                    sp10.vx = sp10.vx >> 4;
                    sp10.vy = sp10.vy >> 4;
                    sp10.vz = sp10.vz >> 4;
                    sp18.vx = func_80042DA8() % 0x200 - 0x100;
                    sp18.vy = func_80042DA8() % 0x200 - 0x100;
                    sp18.vz = func_80042DA8() % 0x200 - 0x100;
                    func_8003C21C(&sp18, &sp30);
                    func_8003B2CC(&sp30, &sp10, (MgSVec *)&q->unkC);
                }
            }
        }
    }
}

void func_801B6248(void) {
    MgTask *temp_s0;
    s16 temp_v1;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        temp_v1 = temp_s0->unk2;
        if (temp_v1 == 0) {
            func_800D5138(1);
        } else if (temp_v1 == 1) {
            func_800D51D4(7);
            temp_s0->unk0 = -1;
        }
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

void func_801B62D4(void *arg0) {
    M2C_UNK sp10;

    func_801B0264(arg0 + ((M2C_FIELD(arg0, s16 *, 0xBB0) * 0x34) + 0x40), &sp10);
    func_801B603C(&sp10);
}

void func_801B631C(MgTask *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4, s32 arg5) {
    u8 c[3];
    s16 t;

    func_8003B69C(0, 0, 0);
    func_8003B710(arg4, arg5, c);
    t = arg0->unkA;
    arg0->unkA = t + (((0x1000 - t) * arg5) >> 12);
    func_8003B69C(c[0], c[1], c[2]);
    func_800D29D4(arg0, arg1, arg2, arg3);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B63E4);

void func_801B6624(s32 arg0, void *arg1) {
    MgTask *temp_v0;

    temp_v0 = &D_80162978[func_800BBEAC(&func_801B63E4)];
    temp_v0->unk4 = (s16) M2C_FIELD(arg1, u16 *, 0);
    temp_v0->unk6 = (s16) M2C_FIELD(arg1, u16 *, 2);
    temp_v0->unk8 = (s16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(temp_v0, s32 *, 0xC) = arg0;
}

void func_801B6690(s32 arg0) {
    func_801B6624((s32)&D_801EC954, &D_801EE9D8[arg0]);
}

void func_801B66C4(void) {
    MgTask *p;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            for (i = 0; i < 10; i++) {
                if ((D_801EE9CC >> i) & 1) {
                    func_801B018C(i, D_8015190F[i][0], &D_801EE9D8[i]);
                }
            }
        }
        func_800D5444(D_801EE9CC, 0, 0, (M2C_UNK *)func_801B6690);
        p->unk2++;
        if (p->unk2 > 0) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B67C4);

void func_801B6B78(s32 arg0) {
    func_801B6624((s32)&D_801EC98C, &D_801EE9D8[arg0]);
}

void func_801B6BAC(void) {
    MgTask *p;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            for (i = 0; i < 10; i++) {
                if ((D_801EE9CC >> i) & 1) {
                    func_801B018C(i, D_8015190F[i][0], &D_801EE9D8[i]);
                }
            }
        }
        func_800D5444(D_801EE9CC, 0, 0, (M2C_UNK *)func_801B6B78);
        p->unk2++;
        if (p->unk2 > 0) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B6CAC);

void func_801B6F9C(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_801B0070((MgSVec *)&p->unk4, 0x1000, 0);
    frame = &D_801EC9E0;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= D_801C8DEC.v) {
            p->unk0 = -1;
        } else {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
        }
    }
}

void func_801B7090(void) {
    MgTask *p;
    s32 t;
    s32 k;
    s32 *g;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        D_801EC9E8 = 0x80;
        D_801EC9EE = 0;
    } else {
        t -= 10;
        if (t < 10) {
            g = &D_801EC9E8;
            *g |= 8;
            D_801EC9EE = (t << 12) / 10;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    k = func_801B1E7C((p->unk2 << 12) / 20, 0x3FF);
    D_801EC9F4->scale.vx = D_801EC9F4->scale.vy = D_801EC9F4->scale.vz = (k << 13) >> 12;
    func_8003C21C((MgSVec *)&p->unkC, &D_801EC9F4->m1);
    D_801EC9F4->rot.vx = 0;
    D_801EC9F4->rot.vy = p->unk2 * 0x20;
    D_801EC9F4->rot.vz = 0;
    func_8003C21C(&D_801EC9F4->rot, &D_801EC9F4->m2);
    func_8003A79C(&D_801EC9F4->m1, &D_801EC9F4->m2, &D_801EC9F4->m2);
    D_801EC9F4->m2.t[0] = p->unk4;
    D_801EC9F4->m2.t[1] = p->unk6;
    D_801EC9F4->m2.t[2] = p->unk8;
    func_8003A63C(&D_801EE9AC, &D_801EC9F4->m2, &D_801EC9F4->m2);
    func_8003B35C(&D_801EC9F4->m2, (KnRig3 *)&D_801EC9F4->scale);
    func_8003B48C(&D_801EC9F4->m2);
    func_8003B51C(&D_801EC9F4->m2);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801EC9E4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B72AC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B7498);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B786C);

void func_801B7C28(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624(&D_801ECA58, sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B7C84);

void func_801B8014(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624(&D_801ECA90, sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8070);

void func_801B831C(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624((s32)&D_801ECAC8, sp10);
    func_801B6624((s32)&D_801ECAE8, sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8388);

void func_801B85F8(void) {
    MgTask *p;
    s16 t;
    s32 n;
    s32 k;
    s32 r;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        r = func_801B1E7C((t << 12) / 10, 0x1FF);
        k = (r * -0x2F00 >> 12) + 0x3000;
    } else {
        n = t - 10;
        if (n < 10) {
            r = func_801B1E7C((n << 12) / 10, 0);
            k = (r * -0x100 >> 12) + 0x100;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_801B0070(&D_801ECB30, k, -0x3E8);
    D_80163C74 = func_800D29D4(D_801ECB20, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B8744(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t >= 10) {
        t -= 10;
        if (t < 10) {
            if (t == 0) {
                D_801ECB3C[0] |= 8;
            }
            D_801ECB42 = (t << 12) / 10;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    k = func_801B1E7C((p->unk2 << 12) / 20, 0x2F0);
    D_801ECB48->v0 = D_801ECB48->v4 = D_801ECB48->v8 = (k * 5 << 10) >> 12;
    func_8003C21C((MgSVec *)&p->unkC, &D_801ECB48->m);
    D_801ECB48->m.t[0] = D_801ECB48->m.t[1] = D_801ECB48->m.t[2] = 0;
    func_8003B35C(&D_801ECB48->m, D_801ECB48);
    func_8003A63C(&D_801EE9AC, &D_801ECB48->m, &D_801ECB48->m);
    func_8003B48C(&D_801ECB48->m);
    func_8003B51C(&D_801ECB48->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801ECB38, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unkC = p->unkC;
        p->unkE = p->unkE;
        p->unk10 = p->unk10;
        p->unk2++;
    }
}

void func_801B8924(void) {
    MgTask *temp_s0;
    MgTask *temp_v0;
    s16 temp_s1;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 == 0) {
            func_800BBEAC(&func_801B85F8);
        }
        if (temp_s0->unk2 == 0xA) {
            temp_v0 = &D_80162978[func_800BBEAC(&func_801B8744)];
            temp_v0->unk10 = 0;
            temp_v0->unkE = 0;
            temp_v0->unkC = 0;
        }
        temp_s1 = temp_s0->unk2;
        if (temp_s1 == 0x14) {
            func_801B5E4C();
            if (temp_s0->unk2 == temp_s1) {
                temp_s0->unk0 = -1;
            }
        }
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8A00);

void func_801B8D7C(s32 arg0) {
    func_801B6624((s32)&D_801ECB80, &D_801EE9D8[arg0]);
}

void func_801B8DB0(void) {
    MgTask *p;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            for (i = 0; i < 10; i++) {
                if ((D_801EE9CC >> i) & 1) {
                    func_801B018C(i, D_8015190F[i][0], &D_801EE9D8[i]);
                }
            }
        }
        func_800D5444(D_801EE9CC, 0, 0, (M2C_UNK *)func_801B8D7C);
        p->unk2++;
        if (p->unk2 > 0) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8EB0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B91C8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9408);

void func_801B9700(void) {
    MgTask *p;
    s16 t;
    s32 n;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        k = (p->unk1C * func_801B1E7C((t << 12) / 5, 0x1FF)) >> 12;
    } else {
        n = t - 5;
        if (n < 5) {
            k = (p->unk1C * (0x1000 - func_801B1E7C((n << 12) / 5, -0x1FF))) >> 12;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_801B0070((MgSVec *)&p->unk4, k, -0x1F4);
    D_80163C74 = func_800D29D4(D_801ECBFC, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9834);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9AA0);

void func_801B9DF0(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624(&D_801ECC40, sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9E4C);

void func_801BA230(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624((s32)&D_801ECC94, sp10);
    func_801B6624((s32)&D_801ECCB4, sp10);
}

void func_801BA29C(void) {
    func_801B6624(&D_801ECCD4, &D_801ECCF4);
    func_800D5444(D_801EE9CC, 0, 0, &func_801BA230);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BA2E8);

void func_801BA598(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624((s32)&D_801ECD14, sp10);
    func_801B6624((s32)&D_801ECD34, sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BA604);

void func_801BA964(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 4) {
        k = (t << 12) / 4 >> 3;
        D_801ECD84.m[0][0] = D_801ECD84.m[1][1] = D_801ECD84.m[2][2] = k;
    } else {
        t -= 4;
        if (t < 4) {
            k = 0x200;
            D_801ECD84.m[0][0] = D_801ECD84.m[1][1] = D_801ECD84.m[2][2] = k;
        } else {
            t -= 4;
            if (t >= 0xF) {
                func_800D51D4(5);
                p->unk0 = -1;
                return;
            }
            k = func_801B1E7C((t << 12) / 15, 0x3FF);
            D_801ECD84.m[0][0] = (k * 0x1600 >> 12) + 0x200;
            D_801ECD84.m[1][1] = D_801ECD84.m[2][2] = 0x200;
            if (t == 0xB) {
                func_800D5138(4);
            }
        }
    }
    func_8003B48C(&D_801ECD84);
    func_8003B51C(&D_801ECD84);
    D_80163C74 = func_800D29D4(D_801ECD74, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801BAAFC(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624(&D_801ECDA4, sp10);
}

void func_801BAB58(void) {
    MgTask *p;
    s32 t;
    s32 q;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        q = (t << 12) / 5;
        k = func_801B1E7C(q, 0x1F0);
        D_801ECDE4.m[0][0] = D_801ECDEC = D_801ECDF4 = (u32)k >> 2;
    } else {
        t -= 5;
        if (t < 0x14) {
            q = (t << 12) / 20;
            k = func_801B1E7C(q, -0x1F0);
            D_801ECDE4.m[0][0] = ((k * 31) << 10 >> 12) + 0x400;
            k = func_801B1E7C(q, 0x4FF);
            D_801ECDEC = (-(k << 10) >> 12) + 0x400;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003B48C(&D_801EE9AC);
    func_8003B51C(&D_801EE9AC);
    func_8003BC6C(&D_801ECDD4, (MgVec *)D_801ECE04->a.t, &D_801ECE04->flag);
    func_8003BC6C(&D_801ECDDC, (MgVec *)D_801ECE04->b.t, &D_801ECE04->flag);
    func_8003B48C(&D_801ECDE4);
    func_8003B51C(&D_801ECE04->a);
    D_80163C74 = func_800D29D4(D_801ECDC4, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B51C(&D_801ECE04->b);
    D_80163C74 = func_800D29D4(D_801ECDC4, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

s32 func_801BAD78(void) {
    MgTask *p;
    u8 *r;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    r = *(u8 **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        func_801B5670((s32)r, 0x78, (s32)D_801ECE08);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x6E) {
            func_800BBEAC(&func_801BA964);
        }
        if (p->unk2 == 0x70) {
            func_800D5444(D_801EE9CC, 0, 0, &func_801BAAFC);
            func_801B62D4(r);
            func_801B5E4C();
        }
        t = p->unk2;
        if (t < 0x30) {
            if (t == 0) {
                *(s16 *)(r + 0x30) = -0x1388;
                *(s16 *)(r + 0x2C) = 0;
                *(s16 *)(r + 0x26) = 0x800;
            }
            k = func_801B1E7C((t << 12) / 48, 0x180);
            *(s16 *)(r + 0x2E) = (-(k * 0x2EE0) >> 12) + 0x2710;
            *(s16 *)(r + 0xBAA) = 0x1000 - k;
            *(s16 *)(r + 0xBA6) = k;
        } else {
            t -= 0x30;
            if (t < 0x12) {
                if (t == 0) {
                    *(s16 *)(r + 0x2E) = -0x7D0;
                    *(s16 *)(r + 0xBAA) = 0;
                    *(s16 *)(r + 0xBA6) = 0x1000;
                }
                if (t == 5) {
                    func_800BBEAC(&func_801BAB58);
                }
            } else {
                t -= 0x12;
                if (t >= 0x36) {
                    p->unk0 = -1;
                    return;
                }
            }
        }
        if ((u32)((u16)p->unk2 - 0x30) >= 0x12U) {
            func_801B5B24(r);
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BAF80);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB270);

void func_801BB500(void *arg0) {
    *(s32 *)&D_80162978[func_800BBEAC(&func_801BB270)].unk4 = (s32)arg0;
}

void func_801BB548(void) {
    MgTask *p;
    s32 k;
    s32 s;
    s32 w;
    s32 t;
    s16 n;

    p = &D_80162978[D_8015169C];
    D_801ECE8C->rot.vx = 0;
    D_801ECE8C->rot.vy = 0;
    D_801ECE8C->rot.vz = p->unk10;
    func_8003C21C(&D_801ECE8C->rot, &D_801ECE8C->m);
    k = 0x1000 - func_801B1E7C((p->unk2 << 12) / 10, 0x4E0);
    s = (p->unkC * k) >> 12;
    D_801ECE8C->m.t[0] = -((s * func_80039A74(p->unk10)) >> 12);
    w = k << 8;
    t = s * func_80039B40(p->unk10);
    D_801ECE8C->m.t[2] = 0x200;
    D_801ECE8C->scale.vx = 0x20;
    D_801ECE8C->scale.vy = w >> 12;
    D_801ECE8C->scale.vz = 0;
    D_801ECE8C->m.t[1] = (t >> 12) - 0x25;
    func_8003B35C(&D_801ECE8C->m, &D_801ECE8C->scale);
    func_8003B48C(&D_801ECE8C->m);
    func_8003B51C(&D_801ECE8C->m);
    D_80163C74 = func_800D29D4(D_801ECE7C, D_801517C0 + 0x4064, 0, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 10) {
            p->unk0 = -1;
        }
    }
}

void func_801BB6EC(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s16 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x1E) {
            t = (((t << 12) / 30) << 10) >> 12;
        } else {
            t -= 0x1E;
            if (t < 0x38) {
                t = 0x400;
            } else {
                t -= 0x38;
                if (t >= 0x25) {
                    p->unk0 = -1;
                    return;
                }
                t = (-(((t << 12) / 37) << 10) >> 12) + 0x400;
            }
        }
        D_801ECE90 = t + D_801ECE90;
        if (D_801ECE90 >= 0x100) {
            do {
                q = &D_80162978[func_800BBEAC(&func_801BB548)];
                k = func_80042DA8() % 200 + 0x12C;
                q->unkC = k;
                q->unkE = -k / 10;
                q->unk10 = func_80042DA8() & 0xFFF;
                D_801ECE90 -= 0x100;
            } while (D_801ECE90 >= 0x100);
        }
        p->unk2++;
    }
}

void func_801BB8C4(void) {
    MgTask *p;
    s32 k;
    s32 s;
    s32 w;
    s32 t;
    s16 n;

    p = &D_80162978[D_8015169C];
    D_801ECEA4->rot.vx = 0;
    D_801ECEA4->rot.vy = 0;
    D_801ECEA4->rot.vz = p->unk10;
    func_8003C21C(&D_801ECEA4->rot, &D_801ECEA4->m);
    k = func_801B1E7C((p->unk2 << 12) / 10, -0x4E0);
    s = (p->unkC * k) >> 12;
    D_801ECEA4->m.t[0] = -((s * func_80039A74(p->unk10)) >> 12);
    w = k << 8;
    t = s * func_80039B40(p->unk10);
    D_801ECEA4->m.t[2] = 0x200;
    D_801ECEA4->scale.vx = 0x20;
    D_801ECEA4->scale.vy = w >> 12;
    D_801ECEA4->scale.vz = 0;
    D_801ECEA4->m.t[1] = (t >> 12) - 0x25;
    func_8003B35C(&D_801ECEA4->m, &D_801ECEA4->scale);
    func_8003B48C(&D_801ECEA4->m);
    func_8003B51C(&D_801ECEA4->m);
    w = D_801517C0 + 0x4064;
    D_80163C74 = func_800D29D4(D_801ECE94, w, 0, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 10) {
            p->unk0 = -1;
        }
    }
}

void func_801BBA64(void) {
    MgTask *p;
    MgTask *q;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x39) {
            t = (t << 12) / 57;
            t = (t * 0x300) >> 12;
        } else {
            t -= 0x39;
            if (t < 0x84) {
                t = 0x300;
            } else {
                t -= 0x84;
                if (t >= 0xF) {
                    p->unk0 = -1;
                    return;
                }
                t = (t << 12) / 15;
                t = (t * -0x300 >> 12) + 0x300;
            }
        }
        D_801ECEA8 = t + D_801ECEA8;
        if (D_801ECEA8 >= 0x100) {
            do {
                q = &D_80162978[func_800BBEAC(&func_801BB8C4)];
                q->unkC = func_80042DA8() % 200 + 0x12C;
                q->unk10 = func_80042DA8() & 0xFFF;
                D_801ECEA8 -= 0x100;
            } while (D_801ECEA8 >= 0x100);
        }
        p->unk2++;
    }
}

void *func_801BBC20(void *arg0, s32 arg1, void *arg2) {
    void *temp_s2;

    M2C_FIELD(arg2, s32 *, 0) = 0x04000000;
    M2C_FIELD(arg2, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(arg2, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(arg2, u8 *, 0xC) = (u8) M2C_FIELD(arg0, u8 *, 4);
    M2C_FIELD(arg2, u8 *, 0xD) = (u8) M2C_FIELD(arg0, u8 *, 6);
    M2C_FIELD(arg2, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x12);
    M2C_FIELD(arg2, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 8);
    func_80046794(arg1, (s32) arg2);
    temp_s2 = arg2 + 0x14;
    func_80044A68(temp_s2, 0, 1, (s32) M2C_FIELD(arg0, u16 *, 0x10), 0);
    func_80046794(arg1, (s32) temp_s2);
    return arg2 + 0x20;
}

void func_801BBCE0(void) {
    MgTask *p;
    s32 t;
    s32 c;
    s32 q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < p->unk4) {
        q = (t << 12) / p->unk4;
        c = (u32)q >> 5;
    } else {
        t -= p->unk4;
        if (t < p->unk6) {
            c = 0x80;
        } else {
            t -= p->unk6;
            if (t >= p->unk8) {
                goto kill;
            }
            q = (t << 12) / p->unk8;
            c = (-(q << 7) >> 12) - 0x80;
        }
    }
    D_801ECEB8 = D_801ECEB9 = D_801ECEBA = c;
    goto done;
kill:
    p->unk0 = -1;
    return;
done:
    D_801ECEAC[0] = (u16)D_801ECEC0 - 0x100;
    D_80163C74 = func_801BBC20(D_801ECEAC, D_801517C0 + 0x406C, D_80163C74);
    D_801ECEAC[0] += 0x100;
    D_80163C74 = func_801BBC20(D_801ECEAC, D_801517C0 + 0x406C, D_80163C74);
    D_801ECEAC[0] += 0x100;
    D_80163C74 = func_801BBC20(D_801ECEAC, D_801517C0 + 0x406C, D_80163C74);
    if (D_80062D98 == 0) {
        D_801ECEC0 = (D_801ECEC0 + 4) & 0xFF;
        p->unk2++;
    }
}

void func_801BBEC8(void) {
    MgTask *p;
    s32 t;
    s32 q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < p->unk4) {
        q = (t << 12) / p->unk4;
        D_801ECECE = 0x1000 - q;
    } else {
        t -= p->unk4;
        if (t < p->unk6) {
            D_801ECECE = 0;
        } else {
            t -= p->unk6;
            if (t < p->unk8) {
                q = (t << 12) / p->unk8;
                D_801ECECE = q;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801ECED4->m = D_801EE9AC;
    D_801ECED4->v0 = D_801ECED4->v4 = D_801ECED4->v8 = 0x300;
    func_8003B35C(&D_801ECED4->m, D_801ECED4);
    D_801ECED4->m.t[1] = -0x25;
    D_801ECED4->m.t[0] = 0;
    D_801ECED4->m.t[2] = 0x200;
    func_8003B48C(&D_801ECED4->m);
    func_8003B51C(&D_801ECED4->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801ECEC4, D_801517C0 + 0x4068, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC0E0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC334);

void func_801BC65C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_801BB500(D_801ECF10);
    func_801BB500(D_801ECF10 + 0x34);
    p->unk0 = -1;
}

void func_801BC6BC(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_801BB500(D_801ECF78);
    func_801BB500(D_801ECF78 + 0x34);
    p->unk0 = -1;
}

void func_801BC71C(void) {
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    func_801BB500(&D_801ECFE0);
    func_800BBEAC(&func_801BB6EC);
    temp_s0->unk0 = -1;
}

void func_801BC778(void) {
    MgTask *temp_s0;
    MgTask *temp_v0;
    s16 temp_v1;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        temp_v1 = temp_s0->unk2;
        if (temp_v1 == 0) {
            temp_v0 = &D_80162978[func_800BBEAC(&func_801BBCE0)];
            temp_v0->unk4 = 0x25;
            temp_v0->unk6 = 0x73;
            temp_v0->unk8 = 0x6C;
        } else if (temp_v1 == 0x25) {
            func_801BB500(&D_801ED014);
            temp_s0->unk0 = -1;
        }
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

void func_801BC838(void) {
    MgTask *temp_s0;
    MgTask *temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    func_800BBEAC(&func_801BC334);
    func_801BB500(&D_801ED07C);
    temp_v0 = &D_80162978[func_800BBEAC(&func_801BC0E0)];
    M2C_FIELD(temp_v0, M2C_UNK **, 0x14) = &D_801ED0B0;
    temp_v0->unk6 = -0x25;
    temp_v0->unk4 = 0;
    temp_v0->unk8 = 0x200;
    temp_s0->unk0 = -1;
}

void func_801BC8D4(void) {
    MgTask *temp_s0;
    MgTask *temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    temp_v0 = &D_80162978[func_800BBEAC(&func_801BC0E0)];
    M2C_FIELD(temp_v0, M2C_UNK **, 0x14) = &D_801ED0C8;
    temp_v0->unk6 = -0x25;
    temp_v0->unk4 = 0;
    temp_v0->unk8 = 0x200;
    temp_s0->unk0 = -1;
}

void func_801BC950(void) {
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    func_800BBEAC(&func_801BBA64);
    temp_s0->unk0 = -1;
}

s32 func_801BC99C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    KnDesc d;
    u8 pad[8];
    u8 *a;
    MgMat *m;
    s32 i;
    s32 o;
    s32 o2;
    s32 r;

    r = arg3;
    a = D_801518E4 + arg0 * 0xB9C;
    if (a[0x25] & 0x80) {
        i = 0;
        if (*(s16 *)(a + 0x10) > 0) {
            o2 = arg0 * 0x74;
            o = 0x174;
            do {
                if (*(s32 *)(a + 0x78 + i * 4) != 0) {
                    m = (MgMat *)(a + o);
                    func_8003B48C(m);
                    func_8003B51C(m);
                    d.a = *(s32 *)(a + 0x78 + i * 4);
                    d.b = *(u8 *)(a + i + 0x3F) | 0x90;
                    d.c = *(u16 *)(D_8015122E + o2);
                    d.d = 0;
                    d.e = 0x20;
                    d.f = *(u16 *)(a + 0x16);
                    r = func_800D29D4((M2C_UNK *)&d, arg1, arg2, r);
                }
                o += 0x34;
                i++;
            } while (i < *(s16 *)(a + 0x10));
        }
    }
    return r;
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BCB04);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BCF1C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD080);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD2D0);

void func_801BD718(s32 arg0, s32 arg1) {
    MgTask *p;

    p = func_800D4FA8(7);
    p->unk10 = arg0;
    *(s32 *)&p->unkC = arg1;
}

void func_801BD758(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == p->unk0) {
            func_800D55F4(0x28, 0x40, p->unk4);
            func_800D55F4(0x29, 0x40, p->unk6);
            if (p->unk8 != 0) {
                func_800D55F4(0x2A, 0x40, p->unk8);
            }
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801BD7FC(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *temp_v0;

    temp_v0 = &D_80162978[func_800BBEAC(&func_801BD758)];
    temp_v0->unk0 = arg0;
    temp_v0->unk4 = arg1;
    temp_v0->unk6 = arg2;
    temp_v0->unk8 = arg3;
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD870);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BE87C);
