#include "common.h"
#include "magic_raise/decls.h"

M2C_UNK *func_801B0054(void) {
    D_801DBD1C = 0;
    func_801B0C3C();
    return &D_801B8874;
}

M2C_UNK *func_801B0084(void) {
    D_801DBD1C = 0;
    func_801B1FF8();
    return &D_801B8874;
}

M2C_UNK *func_801B00B4(void) {
    D_801DBD1C = 1;
    func_801B1FF8();
    return &D_801B8874;
}

M2C_UNK *func_801B00E8(void) {
    D_801DBD1C = 1;
    func_801B0C3C();
    return &D_801B8874;
}

void func_801B011C(void) {
    MgTask *p;
    s8 *frame;
    s16 t;
    s32 n;

    if (D_801DBD1C != 0) {
        D_801C3CEA = 0x7947;
    }
    p = &D_80162978[D_8015169C];
    frame = &D_801C3CE0;
    n = (u16)p->unk2;
    *frame = ((s16)n >> 1) << 5;
    t = p->unk14;
    func_800D4368(&p->unk4, t, -(t >> 4));
    D_801DBD08 = func_800D6260(frame - 4, D_801517C0 + 0x70, 0xC, D_801DBD08);
    if (p->unk2 >= 0xE) {
        p->unk0 = -1;
    }
    if (p->unk6 > 0) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        p->unkE += p->unk18;
        p->unk18 -= p->unk18 >> 4;
    }
}

void func_801B0270(void) {
    MgTask *p;
    s8 *frame;
    s16 t;
    s32 n;

    if (D_801DBD1C != 0) {
        D_801C3CFA = 0x7947;
    }
    p = &D_80162978[D_8015169C];
    frame = &D_801C3CF0;
    n = (u16)p->unk2;
    *frame = (n & 7) << 5;
    t = p->unkE;
    func_800D4368(&p->unk4, t, -(t >> 4));
    D_801DBD08 = func_800D6260(frame - 4, D_801517C0 + 0x70, 0xC, D_801DBD08);
    if (p->unk2 >= 0xA) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk6 += p->unk12;
        p->unk12 -= p->unk12 >> 3;
        p->unk2++;
    }
}

void func_801B037C(void) {
    MgTask *p;
    MgTask *q;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (p->unk2 == 1) {
        q = func_800D4FA8(1);
        *(RaB8 *)&q->unk4 = *(RaB8 *)&p->unk4;
        q->unk10 = p->unkC;
    } else if (p->unk2 == 0x20) {
        func_800D4FA8(2);
    }
    if ((u32)((u16)p->unk2 - 2) < 0xF) {
        D_80153D22[0] += p->unk14;
    }
    if ((u32)((u16)p->unk2 - 0x21) < 0xF) {
        D_80153D22[0] -= p->unk14;
    }
    if (p->unk2 == 0x28) {
        for (i = 0; i < 10; i++) {
            if (1 << i & D_801DBD10) {
                func_800D5774(i);
            }
        }
    }
    if (p->unk2 >= 0x2D) {
        p->unk0 = -1;
    }
    p->unk2++;
}

void func_801B04F0(void) {
    MgVec v;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 k;
    s32 m;

    p = &D_80162978[D_8015169C];
    if ((u32)((u16)p->unk2 - 0x12) < 4) {
        m = 0x22AA;
        i = 0;
        do {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B011C)];
            *(RaB8 *)&q->unk4 = *(RaB8 *)&p->unk4;
            v.vx = func_80042DA8() % 0x1000 - 0x800;
            v.vy = 0;
            v.vz = func_80042DA8() % 0x1000 - 0x800;
            func_8003A08C(&v, &v);
            k = p->unkE + func_80042DA8() % 448;
            q->unkC = q->unk4 + (k * v.vx >> 12);
            q->unkE = 0;
            q->unk10 = q->unk8 + (k * v.vz >> 12);
            q->unkC = (q->unkC - q->unk4) / 16;
            q->unkE = -(func_80042DA8() % 60 + 0xFA);
            q->unk10 = (q->unk10 - q->unk8) / 16;
            k = func_80042DA8() % 0xC00 + 0xA00;
            q->unk14 = m * k >> 12;
            q->unk18 = -q->unk6 / 24;
            i++;
        } while (i < 0x10);
    }
    if (p->unk2 >= 0x2D) {
        p->unk0 = -1;
    }
    p->unk2++;
}

void func_801B07A4(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 k;
    s32 m;

    p = &D_80162978[D_8015169C];
    if ((u32)((u16)p->unk2 - 0x12) < 0xB) {
        m = 0x22AA;
        i = 0;
        do {
            i++;
            q = &D_80162978[func_800BBEAC(&func_801B0270)];
            k = func_80042DA8() % 3072 + 0xA00;
            q->unk4 = p->unk4 + func_80042DA8() % p->unk10 - p->unkE;
            q->unk6 = p->unk6 + func_80042DA8() % 100 - 0x12C;
            q->unk8 = p->unk8 + func_80042DA8() % p->unk10 - p->unkE;
            q->unkE = m * k >> 12;
            q->unk12 = p->unkE / 6 + func_80042DA8() % 100;
        } while (i < 2);
    }
    if (p->unk2 >= 0x2D) {
        p->unk0 = -1;
    }
    p->unk2++;
}

void func_801B09FC(void) {
    MgSVec v;
    MgTask *p;
    MgTask *q;
    MgTask *a;
    s32 i;
    s32 n;
    s32 k;
    s32 w;

    i = 0;
    n = 0;
    for (; i < 10; i++) {
        if (1 << i & D_801DBD10) {
            n++;
            if (n == 1) {
                k = i;
            }
        }
    }
    D_80162978[D_8015169C].unk0 = -1;
    a = D_80162978;
    p = &a[func_800BBEAC((M2C_UNK *)func_801B037C)];
    if (n == 1) {
        func_800D3994(k, D_8015190F[k][0], &p->unk4);
        func_800D3994(k, D_80151919[k][0], &v);
        p->unk6 = v.vy - 0x1C0;
        w = D_801518F6[k][0] + 0xE0;
        if (w >= 0x3B7) {
            w = 0x3B6;
        }
        q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B07A4)];
        *(RaB8 *)&q->unk4 = *(RaB8 *)&p->unk4;
        q->unkE = w;
        q->unk10 = w * 2;
    } else {
        func_800D54EC(D_801DBD10, &p->unk4);
        w = 0xA80;
        p->unk6 = -0x620;
        q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B04F0)];
        *(RaB8 *)&q->unk4 = *(RaB8 *)&p->unk4;
        q->unkE = w;
    }
    p->unk6 -= 0x2A0;
    p->unkC = (D_80151A46[D_801DBD18][0] + 0x800) & 0xFFF;
    p->unk14 = 0x2A;
}

s32 func_801B0C3C(arg0, arg1) {
    D_801DBD0C = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800BBEAC(&func_801B09FC);
    D_801DBD10 = arg0;
    D_801DBD18 = arg1;
    return func_800D55F4(0x20, func_800D574C(arg0), 0x17E);
}

void func_801B0CCC(void) {
    MgTask *p;
    MgTask *q;
    s32 t;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 1) {
            q = func_800D4FA8(1);
            *(RaB8 *)&q->unk4 = *(RaB8 *)&p->unk4;
            q->unk10 = p->unkC;
        } else if (p->unk2 == 0x1A) {
            func_800D4FA8(2);
        }
        t = (u16)p->unk2;
        if ((u32)(t - 2) < 0xE) {
            D_80153D22[0] += p->unk14 >> 1;
        } else if ((s16)t >= 0x10) {
            D_80153D22[0] += p->unk14;
        }
        if (p->unk2 >= 0x2A) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0DF4(void) {
    MgTask *p;
    s8 *col;
    s16 t;
    s8 c;

    p = &D_80162978[D_8015169C];
    t = p->unkE;
    func_800D4368(&p->unk4, t, -(t >> 3));
    col = &D_801C3D00;
    c = -0x80 - p->unk2 * 6;
    D_801C3D02 = c;
    D_801C3D01 = c;
    *col = c;
    D_801DBD08 = func_800D4D90(col - 4, D_801517C0 + 0x70, 0xC, D_801DBD08);
    if (p->unk2 >= 0x10) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk6 += p->unk12;
        if (p->unkE < 0) {
            p->unkE = 0;
        }
        p->unk12 -= p->unk12 >> 4;
        p->unk2++;
    }
}

void func_801B0F08(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 t;
    MgScratch *s;
    s16 k;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unkC;
    rot.vy = 0;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vz = p->unkE;
    scale.vy = p->unk12;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    s = (MgScratch *)0x1F800000;
    s->unk0 = &D_801B8140;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t >= 2) {
        t -= 2;
        ((MgScratch *)0x1F800000)->unkA = 0x80 - t * 0x10;
    } else {
        ((MgScratch *)0x1F800000)->unkA = 0x80;
    }
    D_801DBD08 = func_800D29D4(s, D_801517C0 + 0x70, 0xC, D_801DBD08);
    if (p->unk2 >= 0xA) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkE += p->unk10;
        k = p->unk12 - p->unk14;
        p->unk12 = k;
        if (k < 0) {
            p->unk12 = 0;
        }
        p->unk14 -= p->unk14 >> 4;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B10D0);

void func_801B14BC(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 k;
    s32 i;
    s32 w;
    s32 n;
    s32 diam;
    s16 h;
    u8 pad[8];

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        t = (u16)p->unk2;
        if ((u32)(t - 0xA) < 0x17 && (s16)t % 3 == 0) {
            k = (p->unkE << 12) / 700;
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0F08)];
            *(RaB8 *)&q->unk4 = *(RaB8 *)&p->unk4;
            q->unkC = 0x800;
            q->unkE = k >> 1;
            q->unk10 = k / 8;
            q->unk12 = k / 3 * 2;
            q->unk14 = (s16)(k / 3 * 2) / 8;
        }
        if ((u32)((u16)p->unk2 - 0x18) < 0xF) {
            i = 0;
            w = p->unkE;
            diam = w * 2;
            n = p->unk10 + 4;
            if (n > 0) {
                do {
                    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0DF4)];
                    *(RaB8 *)&q->unk4 = *(RaB8 *)&p->unk4;
                    q->unk4 += func_80042DA8() % diam - w;
                    q->unk6 -= func_80042DA8() % 233;
                    q->unk8 += func_80042DA8() % diam - w;
                    q->unkE = 0x555;
                    h = q->unkE * (func_80042DA8() % 0xC00 + 0x800) >> 12;
                    q->unkE = h;
                    q->unk10 = h >> 4;
                    q->unk12 = -(func_80042DA8() % 120 + 0x64);
                    i++;
                } while (i < n);
            }
        }
        if (p->unk2 == 0x1C) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0CCC)];
            *(RaB8 *)&q->unk4 = *(RaB8 *)&p->unk4;
            q->unkC = p->unkC;
            q->unk14 = -0x50;
        }
        if (p->unk2 == 0x3C) {
            for (i = 0; i < 10; i++) {
                if (1 << i & D_801DBD10) {
                    func_800D5774(i);
                }
            }
        }
        if (p->unk2 >= 0x4B) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B18D8(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 k;
    s32 i;
    s32 w;
    s32 n;
    s32 diam;
    s16 h;
    s32 r;
    s16 u;
    u8 pad[8];

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        t = (u16)p->unk2;
        if ((u32)(t - 0xA) < 0x17 && (s16)t % 3 == 0) {
            k = (p->unkE << 12) / 700;
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0F08)];
            *(RaB8 *)&q->unk4 = *(RaB8 *)&p->unk4;
            q->unkC = 0;
            q->unkE = k >> 1;
            q->unk10 = k / 8;
            q->unk12 = k / 3 * 2;
            q->unk14 = (s16)(k / 3 * 2) / 8;
        }
        if ((u32)((u16)p->unk2 - 0x18) < 0xF) {
            i = 0;
            w = p->unkE;
            diam = w * 2;
            n = p->unk10 + 4;
            if (n > 0) {
                do {
                    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0DF4)];
                    *(RaB8 *)&q->unk4 = *(RaB8 *)&p->unk4;
                    q->unk4 += func_80042DA8() % diam - w;
                    r = func_80042DA8();
                    u = q->unk6 + 0x64;
                    q->unk6 = u + r % 233;
                    q->unk8 += func_80042DA8() % diam - w;
                    q->unkE = 0x555;
                    h = q->unkE * (func_80042DA8() % 0xC00 + 0x800) >> 12;
                    q->unkE = h;
                    q->unk10 = h >> 4;
                    q->unk12 = func_80042DA8() % 100 + 0x5A;
                    i++;
                } while (i < n);
            }
        }
        if (p->unk2 == 0x1C) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0CCC)];
            *(RaB8 *)&q->unk4 = *(RaB8 *)&p->unk4;
            q->unk6 += 0x200;
            q->unkC = p->unkC;
            q->unk14 = 0x3C;
        }
        if (p->unk2 == 0x3C) {
            for (i = 0; i < 10; i++) {
                if (1 << i & D_801DBD10) {
                    func_800D5774(i);
                }
            }
        }
        if (p->unk2 >= 0x4B) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B1D04(void) {
    MgTask *p;
    MgTask *a;
    s32 i;
    s32 n;

    i = 0;
    n = 0;
    for (; i < 10; i++) {
        if (1 << i & D_801DBD10) {
            n++;
            if (n == 1) {
                D_801DBD14 = i;
            }
        }
    }
    a = D_80162978;
    D_80162978[D_8015169C].unk0 = -1;
    if (n == 1) {
        if (D_801DBD1C != 0) {
            p = &a[func_800BBEAC(&func_801B18D8)];
            func_800D3994(D_801DBD14, D_8015190F[D_801DBD14][0], &p->unk4);
            p->unk6 = D_80151A4E[D_801DBD14][0] - 0xA00;
            func_800D55F4(0x20, func_800D574C(D_801DBD10), 0x1A7);
            p->unkC = D_80151A46[D_801DBD14][0];
            p->unkE = 0x2BC;
            p->unk10 = 0;
        } else {
            p = &a[func_800BBEAC(&func_801B14BC)];
            func_800D3994(D_801DBD14, D_8015190F[D_801DBD14][0], &p->unk4);
            p->unk6 = D_80151A4E[D_801DBD14][0];
            func_800D55F4(0x20, func_800D574C(D_801DBD10), 0x1A7);
            p->unkC = D_80151A46[D_801DBD14][0];
            p->unkE = 0x2BC;
            p->unk10 = 0;
        }
    } else {
        p = &a[func_800BBEAC(&func_801B14BC)];
        func_800D54EC(D_801DBD10, &p->unk4);
        p->unk6 = D_80151A4E[D_801DBD18][0];
        p->unkC = D_80151A46[D_801DBD18][0];
        p->unkE = 0x578;
        p->unk10 = 1;
        func_800D55F4(0x20, func_800D574C(D_801DBD10), 0x1A7);
    }
    func_800BBEAC(&func_801B10D0);
}

void func_801B1FF8(arg0, arg1) {
    D_801DBD0C = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B2084, 0, 0, 0);
    func_800BBEAC(&func_801B1D04);
    D_801DBD10 = arg0;
    D_801DBD18 = arg1;
}

INCLUDE_RODATA("../asm/us/magic_raise/nonmatchings/text", D_801B0000);
