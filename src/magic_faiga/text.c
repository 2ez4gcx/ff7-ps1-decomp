#include "common.h"
#include "magic_faiga/decls.h"

void func_801B0084(void) {
    func_801B0F28();
}

void func_801B00A4(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 c;
    s32 t;
    s32 k;
    s32 v;
    MgScratch *s;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC + p->unkE;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk12;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    s = (MgScratch *)0x1F800000;
    s->unk0 = D_801C9364;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t < 0xD) {
        k = 0xD;
        k -= t;
        v = k * 9;
        goto store;
    }
    if (t >= 0x14) {
        k = t - 0x14;
        v = k * 14;
store:
        ((MgScratch *)0x1F800000)->unkA = c - v;
    }
    D_801E2FC4 = func_800D29D4(s, D_801517C0 + 0x70, 0xC, D_801E2FC4);
    if (p->unk2 >= 0x1D) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk12 += p->unk14;
        if (p->unk12 < 0) {
            p->unk12 = 0x7000;
        }
        p->unkC += p->unk10;
        p->unk2++;
    }
}

void func_801B0284(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 c;
    s32 t;
    s32 k;
    MgScratch *s;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC + p->unkE;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk12;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    s = (MgScratch *)0x1F800000;
    s->unk0 = D_801C9D88;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t < 0xD) {
        k = 0xD;
        k -= t;
        goto store;
    }
    if (t >= 0x16) {
        k = t - 0x16;
store:
        ((MgScratch *)0x1F800000)->unkA = c - k * 9;
    }
    D_801E2FC4 = func_800D29D4(s, D_801517C0 + 0x70, 0xC, D_801E2FC4);
    if (p->unk2 >= 0x23) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk12 += p->unk14;
        if (p->unk12 < 0) {
            p->unk12 = 0x7000;
        }
        p->unkC += p->unk10;
        p->unk2++;
    }
}

void func_801B0458(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 c;
    s32 t;
    s32 k;
    MgScratch *s;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC + p->unkE;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk12;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    s = (MgScratch *)0x1F800000;
    s->unk0 = D_801C9D88;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t < 0xD) {
        k = 0xD;
        k -= t;
        goto store;
    }
    if (t >= 0x17) {
        k = t - 0x17;
store:
        ((MgScratch *)0x1F800000)->unkA = c - k * 9;
    }
    D_801E2FC4 = func_800D29D4(s, D_801517C0 + 0x70, 0xC, D_801E2FC4);
    if (p->unk2 >= 0x24) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk12 += p->unk14;
        if (p->unk12 < 0) {
            p->unk12 = 0x7000;
        }
        p->unkC += p->unk10;
        p->unk2++;
    }
}

void func_801B062C(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 mask;
    s32 t;
    s16 v;

    if (D_80062D98 == 0) {
        b = D_80162978;
        p = &b[D_8015169C];
        if (p->unk2 == 8) {
            t = p->unk12 << 12;
            q = &b[func_800BBEAC(func_801B00A4)];
            q->unkC = 0;
            q->unkE = 0;
            q->unk10 = -0x14;
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unk12 = t / 750 >> 1;
            q->unk14 = t / 24000;
            q = &b[func_800BBEAC(func_801B0284)];
            q->unkC = 0;
            q->unkE = -0x400;
            q->unk10 = -0x22;
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unk12 = t / 620 >> 1;
            q->unk14 = t / 19840;
            q = &b[func_800BBEAC(func_801B0458)];
            q->unkC = 0;
            q->unkE = -0x400;
            q->unk10 = -0x1A;
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unk12 = t / 600 >> 1;
            q->unk14 = t / 19200;
        }
        if (p->unk2 < 8) {
            D_800F5B70.v = 0x20;
            D_800F5B72.v = 0;
            D_800F5B71.v = 0;
            v = p->unk2 * 0x1C0;
        } else {
            v = 0xE00;
            if (p->unk2 >= 0x26) {
                v = 0xE00 - (p->unk2 - 0x26) * 0x255;
                if (v < 0) {
                    v = 0;
                }
            }
        }
        if (p->unk2 == 0x1D) {
            i = 0;
            mask = 1;
            for (; i < 10; i++) {
                if (mask << i & D_801E2FCC) {
                    func_800D5774(i);
                }
            }
        }
        if (p->unk2 >= 0x2E) {
            v = 0;
            D_800F5B70.v = 0;
            p->unk0 = -1;
        }
        D_800F5B74.v = v;
        p->unk2++;
    }
}

void func_801B0914(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk12, -p->unk10);
    D_801E2FC4 = func_800D4D90(D_801CAFAC, D_801517C0 + 0x70, 0xC, D_801E2FC4);
    if (p->unk2 >= 0xC) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        switch (p->unk2) {
        case 2:
        case 6:
            func_800D5138(1);
            p->unk12 -= p->unk14;
            break;
        case 3:
            func_800D51D4(2);
            p->unk12 -= p->unk14;
            break;
        case 4:
            p->unk12 = p->unk16;
            break;
        case 7:
            func_800D51D4(4);
            p->unk12 -= p->unk14;
            break;
        case 0:
        case 1:
        case 5:
        case 8:
        case 9:
        case 10:
        case 11:
            p->unk12 -= p->unk14;
            break;
        }
        p->unk2++;
    }
}

void func_801B0A38(void) {
    MgTask *p;
    u16 *frame;
    s16 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801CAFC0;
    *frame = p->unk2;
    t = p->unk12;
    func_800D4368(&p->unk4, t, -(t >> 2));
    D_801E2FC4 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E2FC4);
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0B04(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 w;
    s32 n;
    s32 sc;
    s32 r;
    s32 t;
    s32 u;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((u16)(p->unk2 - 3) < 0x22U) {
            w = p->unk12;
            sc = (w << 12) / 650;
            i = 0;
            w += w >> 1;
            n = w << 1;
            do {
                q = &D_80162978[func_800BBEAC(func_801B0A38)];
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                q->unk4 += func_80042DA8() % n - w;
                q->unk6 += func_80042DA8() % n - w;
                q->unk8 += func_80042DA8() % n - w;
                r = func_80042DA8();
                u = p->unk14;
                t = r % 0x1000 + 0x800;
                q->unk12 = (u + t) * sc >> 12;
                i++;
            } while (i < 3);
            p->unk14 += p->unk16;
        }
        if (p->unk2 >= 0x2E) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0D48(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 n;
    s32 k;
    MgTask *a;

    i = 0;
    n = 0;
    for (; i < 10; i++) {
        if (1 << i & D_801E2FCC) {
            n++;
            if (n == 1) {
                k = i;
            }
        }
    }
    D_80162978[D_8015169C].unk0 = -1;
    a = D_80162978;
    p = &a[func_800BBEAC(func_801B0914)];
    if (n == 1) {
        func_800D3994(k, D_8015190F[k][0], &p->unk4);
        k = D_801518F6[k][0] + 0x100;
        if (k >= 0x76D) {
            k = 0x76C;
        }
    } else {
        func_800D54EC(D_801E2FCC, &p->unk4);
        k = 0x600;
        p->unk6 = -0x500;
    }
    p->unk12 = 0x5555;
    p->unk14 = 0xAAA;
    p->unk10 = k >> 1;
    p->unk16 = p->unk12;
    q = &D_80162978[func_800BBEAC(func_801B062C)];
    *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
    q->unk12 = k;
    q = &D_80162978[func_800BBEAC(func_801B0B04)];
    *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
    q->unk12 = k;
    q->unk14 = 0;
    q->unk16 = 0x80;
}

INCLUDE_RODATA("../asm/us/magic_faiga/nonmatchings/text", D_801B0030);

s32 func_801B0F28(arg0) {
    D_801E2FC8 = &D_80162978[func_800BBEAC(D_801B0030)];
    func_800D2980(D_801B0FC0, 0, 0, 0);
    func_800BBEAC(func_801B0D48);
    D_801E2FCC = arg0;
    return func_800D55F4(0x20, func_800D574C(arg0), 0x8E);
}
