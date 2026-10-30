#include "common.h"
#include "magic_sting/decls.h"

void func_801B0040(void) {
    func_801B4770();
}

void func_801B0060(void) {
    func_801B4804();
}

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B0080);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B0B40);

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B165C);

void func_801B1CA8(MgMat *arg0, u16 *arg1) {
    s32 sp10;
    s32 sp14;
    MgHalf *p;
    MgHalf *q;
    MgHalf *r;
    MgWord *w;

    func_80044AC0((s32)D_801CC88C, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801CC88C);
    p = (MgHalf *)&D_801CC728;
    p->v = D_801CC738.v = arg1[2];
    D_801CC732 = D_801CC73A = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)p - 0x10));
    func_8003B64C(&sp10, &sp14);
    func_8003B6BC((s16)arg1[2] / 2, (s16)arg1[3] / 2);
    func_8003B48C(arg0);
    func_8003B51C(arg0);
    w = (MgWord *)&D_801CC6F8;
    w->v = D_8016209C;
    D_80163C74 = func_801B0080((s32 *)w, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B6BC(sp10, sp14);
    q = (MgHalf *)&D_801CC714;
    q->v = arg1[2];
    D_801CC716 = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)q - 0xC));
    func_80044978(D_801CC8CC, arg1);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801CC8CC);
    r = (MgHalf *)&D_801CC8E4;
    r->v = arg1[0];
    D_801CC8E6 = arg1[1];
    func_800449FC(D_801CC8D8, r);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801CC8D8);
}

void func_801B1EAC(MgSVecList *a, MgSVec *b, MgSVec *out) {
    s32 i;
    s32 n;
    MgSVec *s;

    n = a->n / 8;
    s = a->v;
    for (i = 0; i < n; i++) {
        out->vx = s->vx - b->vx;
        out->vy = s->vy - b->vy;
        out->vz = s->vz - b->vz;
        s++;
        b++;
        out++;
    }
}

void func_801B1F3C(MgSVecList *a, MgSVec *b, MgSVec *d, s32 t) {
    s32 i;
    s32 n;
    MgSVec *s;

    n = a->n / 8;
    s = a->v;
    t = 0x1000 - t;
    for (i = 0; i < n; i++) {
        s->vx = b->vx + ((d->vx * t) >> 12);
        s->vy = b->vy + ((d->vy * t) >> 12);
        s->vz = b->vz + ((d->vz * t) >> 12);
        s++;
        b++;
        d++;
    }
}

s32 func_801B2004(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801CD40E[-v];
    }
    return v;
}

s32 func_801B2040(s32 a, s32 b) {
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

void func_801B2138(s32 arg0, s32 arg1, MgTask *arg2, MgSVec *arg3) {
    MgMat m;

    if (arg1 != -1) {
        func_800D3994(arg0, arg1, arg3);
    } else {
        arg3->vx = D_80151A4C[arg0][0];
        arg3->vy = D_80151A4E[arg0][0];
        arg3->vz = D_80151A50[arg0][0];
    }
    arg3->vx -= arg2->unk14;
    arg3->vy -= arg2->unk18;
    arg3->vz -= arg2->unk1C;
    func_8003BF3C(arg2, &m);
    func_8003B2CC(&m, arg3, arg3);
}

INCLUDE_ASM("../asm/us/magic_sting/nonmatchings/text", func_801B2228);

void func_801B318C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B2228)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

MgMat *func_801B31F0(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801CC794.m[0][0] = D_801CC794.m[1][1] = D_801CC794.m[2][2] = scale;
    func_8003B48C(&D_801CD3F0);
    func_8003B51C(&D_801CD3F0);
    func_8003BC6C(v, (MgVec *)D_801CC794.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801CC794.t, &n);
        D_801CC794.t[0] += (dist * n.vx) >> 12;
        D_801CC794.t[1] += (dist * n.vy) >> 12;
        D_801CC794.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801CC794);
    func_8003B51C(&D_801CC794);
    return &D_801CC794;
}

void func_801B330C(void) {
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

void func_801B3448(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B330C)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

void func_801B34BC(MgSVec *arg0, s16 arg1, s16 arg2) {
    func_801B31F0(arg0, arg2, -0x3E8);
    D_801CC7BC[0] = arg1;
    D_80163C74 = func_800D4D90(&D_801CC7BC[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
}

void func_801B3524(void) {
    MgTask *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    func_801B34BC((MgSVec *)&p->unk4, p->unk2, p->unkC);
    if (D_80062D98 == 0) {
        t = (u16)p->unk2 + 1;
        p->unk2 = t;
        if (t >= D_801CC54C[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B35B0(void) {
    MgMat sp10;

    func_8003A63C(&D_801CC7C0, &D_801CC7E0, &sp10);
    func_801B1CA8(&sp10, &D_801CC800);
}

void func_801B35F0(void) {
    MgMat m;
    MgVec v;
    s32 flag;
    MgTask *p;
    u8 *b;
    s32 n;
    s32 r;
    s32 k;

    func_8003BF8C(&D_801CC810, &m);
    func_8003B35C(&m, &D_801CC818);
    m.t[0] = 0x3E8;
    m.t[1] = 0;
    m.t[2] = 0;
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801CC808 += 0x300;
    b = D_801C4980;
    while (D_801CC808 >= 0x100) {
        r = func_80042DA8() % 341;
        for (n = 0; n < 341; n++) {
            k = (r + n) % 341 * 8;
            if (*(s16 *)(D_801CC94A + k) > 0) {
                p = &D_80162978[func_800BBEAC(&func_801B3524)];
                func_8003BC6C((MgSVec *)(b + k), &v, &flag);
                p->unk4 = v.vx;
                p->unk6 = v.vy;
                p->unk8 = v.vz;
                if (D_801CC80C != 0) {
                    p->unk4 = -p->unk4;
                }
                D_801CC80C ^= 1;
                p->unkC = func_80042DA8() % 0x800 + 0x1800;
                break;
            }
        }
        D_801CC808 -= 0x100;
    }
}

void func_801B37F8(void) {
    MgMat m;
    MgTask *p;
    s16 *r;
    s32 *w;
    s32 t;
    s32 i;
    s32 j;
    s32 f;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x1C) {
            f = (t << 12) / 0x1C;
            j = t / 4;
            i = j;
            j = t - i * 4;
            if (j == 0) {
                func_801B1EAC(&D_801C497C, D_801CC83C[i], D_801CC948);
            }
            func_801B1F3C(&D_801C497C, D_801CC83C[i], D_801CC948, ((j + 1) << 12) / 4);
            D_801CC832 = 0x1000 - f;
            /* identical arms: the dead test keeps t, i and j live across the call (saved registers) */
            if (t + i + j) {
                func_801B35F0();
            } else {
                func_801B35F0();
            }
        } else {
            t -= 0x1C;
            if (t >= 0x2D) {
                p->unk0 = -1;
                return;
            }
            D_801CC832 = 0;
        }
        p->unk2++;
    }
    func_8003B69C(0x80, 0x80, 0x80);
    r = &D_801CC85A;
    *r = 0x80;
    func_8003C21C((MgSVec *)(r - 1), &m);
    func_8003B35C(&m, (M2C_UNK *)&D_801CC860);
    m.t[0] = -0x3E8;
    m.t[1] = 0;
    m.t[2] = 0;
    func_8003A63C(&D_801CD3F0, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    w = &D_801CC82C;
    *w |= 1;
    D_80163C74 = func_800D29D4(w - 1, D_801517C0 + 0x70, 0xC, D_80163C74);
    *r = -0x80;
    func_8003C21C((MgSVec *)(r - 1), &m);
    func_8003B35C(&m, (M2C_UNK *)&D_801CC860);
    m.t[0] = 0x3E8;
    m.t[1] = 0;
    m.t[2] = 0;
    func_8003A63C(&D_801CD3F0, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    *w &= -2;
    D_80163C74 = func_801B0B40(w - 1, D_801517C0 + 0x70, 0xC, D_80163C74);
}

s32 func_801B3AB0(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    StDesc d;
    MgMat m;
    u8 *a;
    s32 t;
    s32 i;

    a = D_801518E4[arg0];
    for (i = 0; i < *(s16 *)(a + 0x10); i++) {
        if (*(s32 *)(a + i * 4 + 0x78) != 0) {
            func_800D41FC(&D_800FA63C, a + (i * 0x34 + 0x174), &m);
            t = *(s32 *)(a + i * 4 + 0x78);
            d.unk4 = 0x80;
            d.unk8 = 0;
            d.unkA = 0;
            d.unkC = 0x20;
            d.unk0 = t;
            d.unkE = *(u16 *)(a + 0x16);
            arg3 = func_801B165C((M2C_UNK *)&d, arg1, arg2, arg3, &m, &D_800FA63C);
        }
    }
    return arg3;
}

s32 func_801B3BEC(u16 *arg0, s32 arg1) {
    MgTask *p;
    s32 a;
    s32 k;

    while (arg1 >= 0x100) {
        a = func_80042DA8() & 0xFFF;
        k = func_80042DA8() % 500 + 0x12C;
        p = &D_80162978[func_800BBEAC(&func_801B3524)];
        p->unk4 = arg0[0] + (func_80039A74(a) * k >> 12);
        p->unk6 = 0;
        p->unk8 = arg0[2] + (func_80039B40(a) * k >> 12);
        p->unkC = func_80042DA8() % 0x800 + 0x1800;
        arg1 -= 0x100;
    }
    return arg1;
}

void func_801B3D20(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_80151A4E[p->unk0][0] = 0x1388;
            p->unk2++;
            return;
        }
        if (p->unk2 < 0xF) {
            D_80151A4E[p->unk0][0] = (u16)D_80151A4E[p->unk0][0] - 0x14D;
            if (p->unk2 == 0xE) {
                D_80151909[p->unk0][0] &= 0xFB;
                D_80151A4E[p->unk0][0] = 0;
            }
            D_801CC874 += 0x100;
            D_801CC874 = func_801B3BEC((u16 *)D_80151A4C[p->unk0], D_801CC874);
        } else {
            p->unk0 = -1;
        }
        p->unk2++;
    }
    D_80163C74 = func_801B3AB0(p->unk0, D_801517C0 + 0x70, 0xC, D_80163C74);
}

void func_801B3F1C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_80151909[p->unk0][0] |= 4;
            p->unk2++;
            return;
        }
        if (p->unk2 < 0x1E) {
            D_80151A4E[p->unk0][0] = (u16)D_80151A4E[p->unk0][0] + 0xA6;
            D_801CC878 += 0x100;
            D_801CC878 = func_801B3BEC((u16 *)D_80151A4C[p->unk0], D_801CC878);
        } else {
            p->unk0 = -1;
        }
        p->unk2++;
    }
    D_80163C74 = func_801B3AB0(p->unk0, D_801517C0 + 0x70, 0xC, D_80163C74);
}

void func_801B40A0(s16 arg0) {
    D_80162978[func_800BBEAC(&func_801B3D20)].unk0 = arg0;
}

void func_801B40E4(s16 arg0) {
    D_80162978[func_800BBEAC(&func_801B3F1C)].unk0 = arg0;
}

void func_801B4128(void) {
    MgTask *p;
    MgTask *q;
    s16 t;
    s32 a;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        D_801CC87C += 0x200;
        while (D_801CC87C >= 0x100) {
            a = func_80042DA8() & 0xFFF;
            k = func_80042DA8() % 500 + 0x1F4;
            q = &D_80162978[func_800BBEAC(&func_801B3524)];
            q->unk4 = p->unk4 + (func_80039A74(a) * k >> 12);
            q->unk6 = 0;
            q->unk8 = p->unk8 + (func_80039B40(a) * k >> 12);
            q->unkC = func_80042DA8() % 0x1000 + 0x1800;
            D_801CC87C -= 0x100;
        }
        t = (u16)p->unk2 + 1;
        p->unk2 = t;
        if (t >= 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B42C4(void) {
    MgTask *p;
    MgTask *q;
    s16 t;
    s32 a;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        D_801CC880 += 0x100;
        while (D_801CC880 >= 0x100) {
            a = func_80042DA8() & 0xFFF;
            k = func_80042DA8() % 500 + 0x1F4;
            q = &D_80162978[func_800BBEAC(&func_801B3524)];
            q->unk4 = p->unk4 + (func_80039A74(a) * k >> 12);
            q->unk6 = 0;
            q->unk8 = p->unk8 + (func_80039B40(a) * k >> 12);
            q->unkC = func_80042DA8() % 0x1000 + 0x1800;
            D_801CC880 -= 0x100;
        }
        t = (u16)p->unk2 + 1;
        p->unk2 = t;
        if (t >= 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B4460(void) {
    MgTask *p;
    MgTask *q;
    s32 t;

    p = &D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801CC6D0, &D_801CD3F0);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t <= 0) {
            if (t == 0) {
                func_801B35B0();
            }
        } else if ((t -= 1) < 10) {
            if (t == 0) {
                func_801B3448(0x32, 0, 0xA, 0);
                q = &D_80162978[func_800BBEAC(&func_801B4128)];
                q->unk4 = 0x9C4;
                q->unk8 = -0xDAC;
                q = &D_80162978[func_800BBEAC(&func_801B4128)];
                q->unk4 = -0x9C4;
                q->unk8 = -0xDAC;
                func_800D55F4(0x20, 0x40, 0x14C);
            }
        } else if ((t -= 10) < 0x1C) {
            if (t == 0) {
                func_800BBEAC(&func_801B37F8);
                func_801B3448(0x14, 0, 0x1C, 0xF);
            }
        } else if ((t -= 0x1C) < 0xF) {
            if (t == 0) {
                func_800D5444(0x60, 0, 0, func_801B40A0);
                func_800D55F4(0x20, 0x40, 0x152);
            }
        } else if ((t -= 0xF) >= 0x1E) {
            p->unk0 = -1;
            D_800FAFDC = 0;
            D_80163B3C = 1;
            return;
        }
        p->unk2++;
    }
}

void func_801B4640(void) {
    MgTask *p;
    MgTask *q;

    p = &D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801CC6D0, &D_801CD3F0);
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_801B3448(0x14, 0, 0x1E, 0xA);
            q = &D_80162978[func_800BBEAC(&func_801B42C4)];
            q->unk4 = 0x9C4;
            q->unk8 = -0xDAC;
            q = &D_80162978[func_800BBEAC(&func_801B42C4)];
            q->unk4 = -0x9C4;
            q->unk8 = -0xDAC;
            func_800D5444(0x60, 0, 0, func_801B40E4);
            func_800D55F4(0x20, 0x40, 0x278);
        }
        if (p->unk2 >= 0x2E) {
            p->unk0 = -1;
            return;
        }
        p->unk2 += 1;
    }
}

void func_801B4770(arg0, arg1) {
    func_800D2980(&D_801B485C, 0, 0, 0);
    func_8003C21C(&D_801CC6F0, &D_801CC6D0);
    func_80042DA8();
    ((void (*)(s32, s32, s32))func_801B318C)((s32)&D_801CC740, (s32)&D_801CC6D0, arg1);
    func_800BBEAC(&func_801B4460);
    D_800FAFDC = 1;
}

void func_801B4804(void) {
    func_800D2980(&D_801B485C, 0, 0, 0);
    func_8003C21C(&D_801CC6F0, &D_801CC6D0);
    func_800BBEAC(&func_801B4640);
}
