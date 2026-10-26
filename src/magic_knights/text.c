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

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B1F74);

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

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B40F4);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4198);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B440C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4694);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4B04);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4B70);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4BF8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4E78);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5670);

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

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5B7C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5C5C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5E4C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5F0C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B603C);

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

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B631C);

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

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B6F9C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B7090);

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

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B85F8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8744);

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

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9700);

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

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BA964);

void func_801BAAFC(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624(&D_801ECDA4, sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BAB58);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BAD78);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BAF80);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB270);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB500);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB548);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB6EC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB8C4);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BBA64);

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

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BBCE0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BBEC8);

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

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC99C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BCB04);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BCF1C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD080);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD2D0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD718);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD758);

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
