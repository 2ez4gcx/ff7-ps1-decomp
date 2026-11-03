#include "common.h"
#include "magic_deadsef/decls.h"

void func_801B0040(void) {
    func_801B384C();
}

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B0060);

s32 func_801B0DE4(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801CF89A[-v];
    }
    return v;
}

s32 func_801B0E20(s32 a, s32 b) {
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

void func_801B0F18(s32 arg0, s32 arg1, MgTask *arg2, MgSVec *arg3) {
    MgMat m;

    if (arg1 != -1) {
        func_800D3994(arg0, arg1, arg3);
    } else {
        arg3->vx = D_80151A4C[arg0][0];
        arg3->vy = D_80151A4C[arg0][1];
        arg3->vz = D_80151A50[arg0][0];
    }
    arg3->vx -= arg2->unk14;
    arg3->vy -= arg2->unk18;
    arg3->vz -= arg2->unk1C;
    func_8003BF3C(arg2, &m);
    func_8003B2CC(&m, arg3, arg3);
}

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B1014);

void func_801B1F6C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B1014)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

s32 func_801B1FD0(s32 arg0, s32 arg1) {
    u8 *list;
    s16 *e;
    volatile DsV *w;
    s32 n;
    s32 i;
    s32 j;
    s32 o8;
    s32 o32;
    s32 k;

    list = (u8 *)arg0 + 4;
    e = (s16 *)(list + *(s32 *)arg0);
    n = *e;
    e = (s16 *)((u8 *)e + 4);
    i = 0;
    if (i < n) {
        o8 = arg1 * 8;
        do {
            j = 0;
            do {
                func_8003BC6C((s32)list + e[j], D_801B4314 + j * 0x10, D_801B4314 + 0x40);
                j++;
            } while (j < 3);
            w = (volatile DsV *)D_801B4314;
            *(s16 *)(D_801C73D4 + o8 + 0) = (*(s32 *)((u8 *)w + 0x0) + *(s32 *)((u8 *)w + 0x10) + *(s32 *)((u8 *)w + 0x20)) / 3;
            *(s16 *)(D_801C73D4 + o8 + 2) = (*(s32 *)((u8 *)w + 0x4) + *(s32 *)((u8 *)w + 0x14) + *(s32 *)((u8 *)w + 0x24)) / 3;
            *(s16 *)((u8 *)D_801C73D8 + o8) = (*(s32 *)((u8 *)w + 0x8) + *(s32 *)((u8 *)w + 0x18) + *(s32 *)((u8 *)w + 0x28)) / 3;
            j = 0;
            k = o8;
            o32 = arg1 << 5;
            do {
                *(s16 *)(D_801B4454 + o32) = w->x - *(u16 *)(D_801C73D4 + k);
                j++;
                *(s16 *)(D_801B4454 + o32 + 2) = w->y - *(u16 *)(D_801C73D4 + k + 2);
                *(s16 *)(D_801B4454 + o32 + 4) = w->z - *(u16 *)((u8 *)D_801C73D8 + k);
                w++;
                o32 += 8;
            } while (j < 3);
            e = (s16 *)((u8 *)e + 0x10);
            o8 += 8;
            i++;
            arg1++;
        } while (i < n);
    }
    n = *e;
    e = (s16 *)((u8 *)e + 4);
    i = 0;
    if (i < n) {
        o8 = arg1 * 8;
        do {
            j = 0;
            do {
                func_8003BC6C((s32)list + e[j], D_801B4314 + j * 0x10, D_801B4314 + 0x40);
                j++;
            } while (j < 4);
            w = (volatile DsV *)D_801B4314;
            *(s16 *)(D_801C73D4 + o8 + 0) = (*(s32 *)((u8 *)w + 0x0) + *(s32 *)((u8 *)w + 0x10) + *(s32 *)((u8 *)w + 0x20) + *(s32 *)((u8 *)w + 0x30)) / 4;
            *(s16 *)(D_801C73D4 + o8 + 2) = (*(s32 *)((u8 *)w + 0x4) + *(s32 *)((u8 *)w + 0x14) + *(s32 *)((u8 *)w + 0x24) + *(s32 *)((u8 *)w + 0x34)) / 4;
            *(s16 *)((u8 *)D_801C73D8 + o8) = (*(s32 *)((u8 *)w + 0x8) + *(s32 *)((u8 *)w + 0x18) + *(s32 *)((u8 *)w + 0x28) + *(s32 *)((u8 *)w + 0x38)) / 4;
            j = 0;
            k = o8;
            o32 = arg1 << 5;
            do {
                *(s16 *)(D_801B4454 + o32) = w->x - *(u16 *)(D_801C73D4 + k);
                j++;
                *(s16 *)(D_801B4454 + o32 + 2) = w->y - *(u16 *)(D_801C73D4 + k + 2);
                *(s16 *)(D_801B4454 + o32 + 4) = w->z - *(u16 *)((u8 *)D_801C73D8 + k);
                w++;
                o32 += 8;
            } while (j < 4);
            e = (s16 *)((u8 *)e + 0x14);
            o8 += 8;
            i++;
            arg1++;
        } while (i < n);
    }
    n = *e;
    e = (s16 *)((u8 *)e + 4);
    i = 0;
    if (i < n) {
        o8 = arg1 * 8;
        do {
            j = 0;
            do {
                func_8003BC6C((s32)list + e[j], D_801B4314 + j * 0x10, D_801B4314 + 0x40);
                j++;
            } while (j < 3);
            w = (volatile DsV *)D_801B4314;
            *(s16 *)(D_801C73D4 + o8 + 0) = (*(s32 *)((u8 *)w + 0x0) + *(s32 *)((u8 *)w + 0x10) + *(s32 *)((u8 *)w + 0x20)) / 3;
            *(s16 *)(D_801C73D4 + o8 + 2) = (*(s32 *)((u8 *)w + 0x4) + *(s32 *)((u8 *)w + 0x14) + *(s32 *)((u8 *)w + 0x24)) / 3;
            *(s16 *)((u8 *)D_801C73D8 + o8) = (*(s32 *)((u8 *)w + 0x8) + *(s32 *)((u8 *)w + 0x18) + *(s32 *)((u8 *)w + 0x28)) / 3;
            j = 0;
            k = o8;
            o32 = arg1 << 5;
            do {
                *(s16 *)(D_801B4454 + o32) = w->x - *(u16 *)(D_801C73D4 + k);
                j++;
                *(s16 *)(D_801B4454 + o32 + 2) = w->y - *(u16 *)(D_801C73D4 + k + 2);
                *(s16 *)(D_801B4454 + o32 + 4) = w->z - *(u16 *)((u8 *)D_801C73D8 + k);
                w++;
                o32 += 8;
            } while (j < 3);
            e = (s16 *)((u8 *)e + 0x14);
            o8 += 8;
            i++;
            arg1++;
        } while (i < n);
    }
    n = *e;
    e = (s16 *)((u8 *)e + 4);
    i = 0;
    if (i < n) {
        o8 = arg1 * 8;
        do {
            j = 0;
            do {
                func_8003BC6C((s32)list + e[j], D_801B4314 + j * 0x10, D_801B4314 + 0x40);
                j++;
            } while (j < 4);
            w = (volatile DsV *)D_801B4314;
            *(s16 *)(D_801C73D4 + o8 + 0) = (*(s32 *)((u8 *)w + 0x0) + *(s32 *)((u8 *)w + 0x10) + *(s32 *)((u8 *)w + 0x20) + *(s32 *)((u8 *)w + 0x30)) / 4;
            *(s16 *)(D_801C73D4 + o8 + 2) = (*(s32 *)((u8 *)w + 0x4) + *(s32 *)((u8 *)w + 0x14) + *(s32 *)((u8 *)w + 0x24) + *(s32 *)((u8 *)w + 0x34)) / 4;
            *(s16 *)((u8 *)D_801C73D8 + o8) = (*(s32 *)((u8 *)w + 0x8) + *(s32 *)((u8 *)w + 0x18) + *(s32 *)((u8 *)w + 0x28) + *(s32 *)((u8 *)w + 0x38)) / 4;
            j = 0;
            k = o8;
            o32 = arg1 << 5;
            do {
                *(s16 *)(D_801B4454 + o32) = w->x - *(u16 *)(D_801C73D4 + k);
                j++;
                *(s16 *)(D_801B4454 + o32 + 2) = w->y - *(u16 *)(D_801C73D4 + k + 2);
                *(s16 *)(D_801B4454 + o32 + 4) = w->z - *(u16 *)((u8 *)D_801C73D8 + k);
                w++;
                o32 += 8;
            } while (j < 4);
            e = (s16 *)((u8 *)e + 0x18);
            o8 += 8;
            i++;
            arg1++;
        } while (i < n);
    }
    return arg1;
}

void func_801B2748(void) {
    MgMat m;
    u8 pad[8];
    s32 i;
    s32 k;
    s32 r;
    s32 t;
    s32 o8;
    s32 o4;
    MgDsList *e;
    u16 *q;

    k = 0;
    i = 0;
    e = &D_80154754;
    if (D_80154764 > 0) {
        do {
            if (e->v[i] != 0) {
                func_800D41FC(&D_800FA63C, (u8 *)e + (i * 0x34 + 0x174), &m);
                func_8003B48C(&m);
                func_8003B51C(&m);
                k = func_801B1FD0(e->v[i], k);
            }
            i++;
        } while (i < e->n);
        i = 0;
    }
    q = D_801CBFB4;
    o8 = 0;
    o4 = 0;
    do {
        i++;
        t = func_80042DA8() % 200 + 0xE74;
        *(s16 *)((u8 *)D_801CD2AC + o4) = (*(s16 *)((u8 *)D_801C73D8 + o8) + t) * 0x1C2 / 3700;
        o8 += 8;
        r = func_80042DA8();
        *(s16 *)((u8 *)D_801CD2AC + o4 + 2) = r / 5 * 5 - r;
        *q = 0;
        q++;
        o4 += 4;
    } while (i < 0x97C);
}

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B2908);

void func_801B2C30(void) {
    MgObj20 *p;
    u8 *a;
    u8 *b;
    u8 *c;
    s32 i;
    MgDsList *e;
    s32 *q;
    u16 *r;
    s16 v;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = p->unk2;
        func_801B2908(i);
    }
    a = D_801B4454;
    b = D_801C73D4;
    c = D_801CBFB4;
    func_8003A63C(&D_800FA63C, &D_801B431C, D_801B434C);
    func_8003B48C(D_801B434C);
    func_8003B51C(D_801B434C);
    func_8003B69C(0xFF, 0xFF, 0xFF);
    i = 0;
    e = &D_80154754;
    if (D_80154764 > 0) {
        do {
            D_801B433C[0] = e->v[i];
            if (D_801B433C[0] != 0) {
                D_80163C74 = func_801B0060(D_801B433C, D_801517C0 + 0x70, 0xC, D_80163C74, &a, &b, &c);
            }
            i++;
        } while (i < e->n);
    }
    if (*(u8 *)0x80062D98 == 0) {
        u8 pad[8];
        q = &D_801B4338;
        r = &D_801B4450;
        *q -= 0x1E;
        *r -= 0x1E;
        v = p->unk2 + 1;
        p->unk2 = v;
        if (v >= 0x1FE) {
            p->unk0 = -1;
        }
    }
}

void func_801B2DFC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            p->unk0 = 0;
        }
        if (p->unk2 == D_801B4350[p->unk0]) {
            func_800D5138(2);
        }
        if (p->unk2 == D_801B4350[p->unk0] + 2) {
            func_800D51D4(6);
            p->unk0++;
            if (D_801B4350[p->unk0] == -1) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B2EFC(s16 arg0) {
    func_8003B69C(0, 0, 0);
    D_801B437E[0] = arg0;
    D_80163C74 = func_800D29D4((u8 *)D_801B437E - 0xA, D_801517C0 + 0x78, 0, D_80163C74);
}

void func_801B2F64(void) {
    MgObj20 *p;
    s32 t;
    s32 w;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x14) {
        w = 0x1000 - (t << 12) / 20;
    } else {
        t -= 0x14;
        w = 0;
        if (t >= 5) {
            t -= 5;
            if (t < 0x14) {
                w = (t << 12) / 20;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    func_800D4284(&D_801B444C, 0, &D_801B4384);
    func_8003C21C((u8 *)p + 0xC, D_801B43C4 + 0x10);
    *(s32 *)(D_801B43C4 + 0x2C) = 0;
    *(s32 *)(D_801B43C4 + 0x28) = 0;
    *(s32 *)(D_801B43C4 + 0x24) = 0;
    func_8003A63C(&D_801B4384, D_801B43C4 + 0x10, D_801B43C4 + 0x10);
    D_801B43A4[0] = *(u16 *)((u8 *)p + 0x14);
    D_801B43BC = *(s16 *)((u8 *)p + 0x16);
    func_8003A63C(D_801B43C4 + 0x10, D_801B43A4, D_801B43C4 + 0x10);
    func_8003B48C(D_801B43C4 + 0x10);
    func_8003B51C(D_801B43C4 + 0x10);
    ((void (*)(s32))func_801B2EFC)(w);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3108(void) {
    MgObj20 *p;
    MgTask *q;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        D_801B43C8 += 0xA0;
        if (D_801B43C8 >= 0x100) {
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B2F64)];
                q->unkC = 0;
                q->unkE = 0;
                t = D_801B4440 + (0x400 + (func_80042DA8() & 0x7FF));
                D_801B4440 = t;
                q->unk10 = t;
                q->unk14 = func_80042DA8() % 0x400 + 0x400;
                q->unk16 = -(func_80042DA8() % 200 + 100);
                D_801B43C8 -= 0x100;
            } while (D_801B43C8 >= 0x100);
        }
        p->unk2++;
        if (p->unk2 >= 0x8C) {
            p->unk0 = -1;
        }
    }
}

void func_801B3274(void) {
    u8 pad[16];
    MgTask *p;
    s32 t;
    s32 v;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 2) {
        v = p->unk14 * func_801B0E20(t << 11, 0x1FF) >> 12;
    } else {
        t -= 2;
        if (t < 2) {
            v = p->unk14 + (-p->unk14 * func_801B0E20((t << 12) >> 1, -0x1FF) >> 12);
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_800D4368(&p->unk4, (s16)v, 0);
    D_80163C74 = func_800D29D4(D_801B43CC, D_801517C0 + 0x74, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B338C(void) {
    MgObj20 *p;
    MgTask *q;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        D_801B43DC += 0x80;
        if (D_801B43DC >= 0x100) {
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B3274)];
                k = 0x320;
                q->unk4 = func_80042DA8() % 1600 + (D_801B4444[0] - k);
                q->unk6 = func_80042DA8() % 1600 + (D_801B4444[1] - k);
                q->unk8 = func_80042DA8() % 1600 + (D_801B4444[2] - k);
                q->unk14 = func_80042DA8() % 0x800;
                D_801B43DC -= 0x100;
            } while (D_801B43DC >= 0x100);
        }
        p->unk2++;
        if (p->unk2 >= 0x8C) {
            p->unk0 = -1;
        }
    }
}

void func_801B3568(void) {
    MgTask *p;
    s32 t;
    s32 c;

    p = &D_801621F0[D_801590D4];
    t = p->unk2;
    if (t < 0x3C) {
        c = (t << 12) / 60 * 0xFF >> 12;
    } else {
        c = 0xFF;
    }
    D_80163C74 = func_800C4FC8(c, c, c);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B361C(void) {
    MgObj20 *p;
    s32 t;
    u32 u;
    s32 i;
    u8 *q;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0xC8) {
            if (t == 0) {
                D_800F5B70 = 0;
                D_800F5B71 = 0;
                D_800F5B72 = 0;
                func_800D52A0(0x400, 0xA);
                D_801513DC[0] |= 2;
                func_800BBEAC((M2C_UNK *)func_801B2DFC);
                D_8015477E = D_8015477D = D_8015477C = 0xFF;
                D_80154768 = 0;
            }
            if (t == 0x3C) {
                func_800BBEAC((M2C_UNK *)func_801B3108);
                func_800BBEAC((M2C_UNK *)func_801B338C);
            }
            if (t == 0xC7) {
                func_801B2748();
                D_80154779[0] |= 2;
                D_801513DC[0] &= 0xFFFD;
            }
            u = func_80039A74(((t << 12) * 3) / 200 + 0xC00) + 0x1000;
            D_80154768 = (u + (u >> 31)) >> 2;
        } else {
            t -= 0xC8;
            i = 0;
            if (t < 0x1FE) {
                if (t == 0) {
                    func_800BBEAC((M2C_UNK *)func_801B2C30);
                }
                if (t == 0x1C2) {
                    func_800BC04C(func_801B3568);
                }
            } else {
                D_80154779[0] = (D_80154779[0] & 0xFD) | 4;
                q = D_80154779 - 0x2E70;
                do {
                    i++;
                    *q = (*q & 0xFD) | 4;
                    q += 0xB9C;
                } while (i < 3);
                D_800FAFDC = 0;
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

s32 func_801B384C(void) {
    s32 i;
    u8 *q;
    u8 *p;

    q = &D_8015477F;
    func_800D3994(4, *q, D_801B4444);
    D_801B444C = D_801B4444[0];
    D_801B444E = D_801B4444[1];
    D_801B42CC = (s16)D_801B4444[0];
    D_801B42D0 = (s16)D_801B4444[1];
    D_801B4450 = D_801B4448;
    D_801B42D4 = (s16)D_801B4448;
    func_800BBEAC((M2C_UNK *)func_801B361C);
    p = q - 0x2E76;
    i = 0;
    do {
        i++;
        *p |= 2;
        p += 0xB9C;
    } while (i < 3);
    func_801B1F6C((s32)&D_801B42DC, (s32)&D_801B42B8, 0);
    D_800FAFDC = 1;
    return func_800D55F4(0x21, 0x40, 0x2DA, 0x2DB);
}
