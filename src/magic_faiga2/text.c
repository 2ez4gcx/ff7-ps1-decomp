#include "common.h"
#include "magic_faiga2/decls.h"

void func_801B0084(void) {
    func_801B1770();
}

INCLUDE_ASM("../asm/us/magic_faiga2/nonmatchings/text", func_801B00A4);

INCLUDE_ASM("../asm/us/magic_faiga2/nonmatchings/text", func_801B0308);

INCLUDE_ASM("../asm/us/magic_faiga2/nonmatchings/text", func_801B05CC);

INCLUDE_ASM("../asm/us/magic_faiga2/nonmatchings/text", func_801B082C);

INCLUDE_ASM("../asm/us/magic_faiga2/nonmatchings/text", func_801B0B08);

void func_801B0BD0(void) {
    u8 pad[0x38];
    MgTask *p;
    s32 a;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk12, 0);
    a = 0;
    if (p->unk2 >= 0xC) {
        a = (p->unk2 - 0xC) * 0x155;
    }
    *(u8 **)0x1F800000 = D_801C1928;
    *(s32 *)0x1F800004 = D_801517C0 + 0x70;
    *(s32 *)0x1F800008 = 0xC;
    *(s32 *)0x1F80000C = D_801DBABC;
    func_8003B69C(0, 0, 0);
    D_801DBABC = func_801B0B08((void *)0x1F800000, a);
    if (p->unk2 >= 0x18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk12 += p->unk14;
        p->unk14 -= p->unk14 >> 3;
        p->unk2++;
    }
}

void func_801B0D0C(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;
    MgScratch *sp;
    s32 t;

    rot.vx = -0x400;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = 0;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk12;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    sp = (MgScratch *)0x1F800000;
    sp->unk0 = D_801C32E0;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t < 6) {
        ((MgScratch *)0x1F800000)->unkA = 0x1000 - t * 0x255;
    } else if (t >= 0xC) {
        ((MgScratch *)0x1F800000)->unkA = (t - 0xC) * 0x12A;
    } else {
        ((MgScratch *)0x1F800000)->unkA = 0x200;
    }
    func_8003B69C(0, 0, 0);
    D_801DBABC = func_800D29D4(sp, D_801517C0 + 0x70, 0xC, D_801DBABC);
    if (p->unk2 >= 0x18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk12 += p->unk14;
        p->unk2++;
    }
}

void func_801B0EF4(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 mask;
    s32 t;
    s16 v;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 0x20) {
            t = p->unk12 << 12;
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0BD0)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unk12 = 0;
            q->unk14 = t / 2600;
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0D0C)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unk12 = 0;
            q->unk14 = t / 2900;
        }
        if (p->unk2 < 8) {
            D_800F5B70.v = 0x20;
            D_800F5B72.v = 0;
            D_800F5B71.v = 0;
            v = p->unk2 * 0x1C0;
        } else {
            v = 0xE00;
            if (p->unk2 >= 0x3A) {
                v = 0xE00 - (p->unk2 - 0x3A) * 0x255;
                if (v < 0) {
                    v = 0;
                }
            }
        }
        if (p->unk2 == 0x39) {
            i = 0;
            mask = 1;
            for (; i < 10; i++) {
                if (mask << i & D_801DBAC4) {
                    func_800D5774(i);
                }
            }
        }
        if (p->unk2 >= 0x42) {
            v = 0;
            D_800F5B70.v = 0;
            p->unk0 = -1;
        }
        D_800F5B74.v = v;
        p->unk2++;
    }
}

void func_801B1128(void) {
    u8 pad[0x38];
    MgTask *p;
    s16 v;

    p = &D_80162978[D_8015169C];
    v = p->unk12;
    func_800D4368(&p->unk4, v, -(v >> 3));
    ((MgScratch *)0x1F800000)->unk0 = D_801C2D04;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801DBABC = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DBABC);
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

void func_801B128C(void) {
    u8 pad[0x38];
    MgTask *p;
    s16 v;
    s16 t;

    p = &D_80162978[D_8015169C];
    v = p->unk12;
    func_800D4368(&p->unk4, v, -(v >> 3));
    ((MgScratch *)0x1F800000)->unk0 = D_801C2D04;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    ((MgScratch *)0x1F800000)->unkA = t * 0x2AA;
    func_8003B69C(0, 0, 0);
    D_801DBABC = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DBABC);
    if (p->unk2 >= 5) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk12 -= p->unk14;
        p->unk2++;
    }
}

void func_801B13C4(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 w;
    s32 n;
    s32 sc;
    s32 r;
    s32 t;
    s32 u;
    s16 v;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((u16)(p->unk2 - 3) < 0x20U) {
            w = p->unk12;
            sc = (w << 12) / 2000;
            i = 0;
            w += w >> 1;
            n = w << 1;
            do {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B128C)];
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                q->unk4 += func_80042DA8() % n - w;
                q->unk6 += func_80042DA8() % n - w;
                q->unk8 += func_80042DA8() % n - w;
                r = func_80042DA8();
                u = p->unk14;
                t = r % 0x1000 + 0x800;
                v = (u + t) * sc >> 12;
                q->unk12 = v;
                q->unk14 = v / 6;
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

void func_801B162C(void) {
    MgTask *p;
    MgTask *q;
    MgTask *b;
    s32 i;
    s32 mask;

    i = 0;
    mask = 1;
    for (; i < 10; i++) {
        if (mask << i & D_801DBAC4) {
            q = &D_80162978[i];
        }
    }
    D_80162978[D_8015169C].unk0 = -1;
    b = D_80162978;
    p = &b[func_800BBEAC((M2C_UNK *)func_801B1128)];
    func_800D54EC(D_801DBAC4, &p->unk4);
    p->unk6 = -0x700;
    p->unk12 = 0x2ABD;
    p->unk14 = 0x557;
    p->unk10 = 0x300;
    p->unk16 = p->unk12;
    q = &b[func_800BBEAC((M2C_UNK *)func_801B0EF4)];
    *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
    q->unk12 = 0x600;
    q = &b[func_800BBEAC((M2C_UNK *)func_801B13C4)];
    *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
    q->unk12 = 0x600;
    q->unk14 = 0;
    q->unk16 = 0x80;
}

INCLUDE_RODATA("../asm/us/magic_faiga2/nonmatchings/text", D_801B0030);

s32 func_801B1770(arg0) {
    D_801DBAC0 = &D_80162978[func_800BBEAC(D_801B0030)];
    func_800D2980(D_801B1808, 0, 0, 0);
    func_800BBEAC(&func_801B162C);
    D_801DBAC4 = arg0;
    return func_800D55F4(0x20, func_800D574C(arg0), 0xA9);
}
