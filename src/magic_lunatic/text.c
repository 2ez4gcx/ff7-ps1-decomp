#include "common.h"
#include "magic_lunatic/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B0D44();
    return &D_801C96E0;
}

void func_801B007C(void) {
    MgTask *e;
    MgPart18 *base;
    MgPart18 *p;
    u16 *frame;
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 r;
    s32 s;

    i = 0;
    e = &D_80162978[D_8015169C];
    base = D_801E23EC[e->unk14];
    frame = D_801CA3C8;
    do {
        p = &base[i];
        if (p->unk0 != 0) {
            frame[0] = p->unk2;
            func_800D4368(&p->unk4, p->unk16, -(p->unk16 >> 3));
            D_801E23D8 = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801E23D8);
            if (D_80062D98 == 0) {
                p->unk4 += p->unkC;
                p->unk6 += p->unkE;
                p->unk8 += p->unk10;
                p->unkC -= p->unkC >> 3;
                p->unk10 -= p->unk10 >> 3;
                if (p->unk2 >= 0xF) {
                    p->unk0 = 0;
                }
                p->unk2++;
            }
        }
        i++;
    } while (i < 0x64);
    if (D_80062D98 == 0) {
        if (e->unk2 >= 0x23) {
            e->unk0 = -1;
        }
        if (e->unk2 < 0x13) {
            s = 0xDC0;
            i = 0;
            do {
                for (j = 0; j < 0x64; j++) {
                    if (base[j].unk0 == 0) {
                        break;
                    }
                }
                if (j >= 0x64) {
                    break;
                }
                p = (MgPart18 *)(j * 0x18 + (s32)base);
                p->unk0 = 1;
                p->unk2 = 0;
                r = func_80042DA8();
                a = r / 0x1000;
                a = r - a * 0x1000;
                b = ((s16)(e->unkC / 3) << 1) + func_80042DA8() % 100;
                p->unk4 = e->unk4 + ((func_80039B40(a) * b) >> 12);
                p->unk6 = e->unk6;
                p->unk8 = e->unk8 + ((func_80039A74(a) * b) >> 12);
                b = func_80042DA8() % 90 + 0x5A;
                p->unkC = (func_80039B40(a) * b) >> 12;
                p->unkE = -(func_80042DA8() % 10 + 0x14);
                p->unk10 = (func_80039A74(a) * b) >> 12;
                a = func_80042DA8() % 2816 + 0xE00;
                p->unk16 = (s * a) >> 12;
                i++;
            } while (i < 5);
        }
        e->unk2++;
    }
}

void func_801B0484(void) {
    MgTask *p;
    u8 *rgb;
    s16 t;
    s16 v;
    u8 c;

    p = &D_80162978[D_8015169C];
    D_801CA3D4[0] = p->unk2;
    t = p->unk2;
    if (t >= 7) {
        c = 0x60 - (t - 7) * 12;
    } else {
        c = 0x60;
    }
    rgb = D_801CA3D0;
    rgb[2] = c;
    rgb[1] = c;
    rgb[0] = c;
    v = p->unk14;
    func_800D4368(&p->unk4, v, -(v >> 3));
    D_801E23D8 = func_800D4D90(rgb - 4, D_801517C0 + 0x70, 0xC, D_801E23D8);
    if (p->unk2 >= 0xF) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        p->unkC -= p->unkC >> 3;
        p->unk10 -= p->unk10 >> 3;
    }
}

void func_801B05F0(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    MgScratch *s;
    s32 t;
    s32 c;
    u32 n;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unkC;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    n = (u16)p->unk2 & 3;
    s = (MgScratch *)0x1F800000;
    s->unk0 = &D_801C8FF8;
    ((MgScratch *)0x1F800000)->unk4 = 0x28;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk8 = (n & 1) << 7;
    ((MgScratch *)0x1F800000)->unkC = (n >> 1) | 0x20;
    t = p->unk2;
    if (t < 8) {
        c = t * 0x10;
        goto store;
    }
    if (t >= 0x16) {
        t -= 0x16;
        c = 0x80 - t * 0x10;
store:
        ((MgScratch *)0x1F800000)->unkA = c;
    }
    D_801E23D8 = func_800D29D4(s, D_801517C0 + 0x70, 0xC, D_801E23D8);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0798(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    MgScratch *s;
    s32 t;
    s32 c;
    s32 n;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unkC;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    n = p->unk2 + 2;
    s = (MgScratch *)0x1F800000;
    s->unk0 = &D_801C936C;
    ((MgScratch *)0x1F800000)->unk4 = 0x28;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk8 = (n & 1) << 7;
    ((MgScratch *)0x1F800000)->unkC = ((n & 2) >> 1) | 0x20;
    t = p->unk2;
    if (t < 8) {
        c = t * 0x10;
        goto store;
    }
    if (t >= 0x16) {
        t -= 0x16;
        c = 0x80 - t * 0x10;
store:
        ((MgScratch *)0x1F800000)->unkA = c;
    }
    D_801E23D8 = func_800D29D4(s, D_801517C0 + 0x70, 0xC, D_801E23D8);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0944(void) {
    MgTask *p;
    MgTask *q;
    s32 k;
    s32 i;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        k = p->unk2;
        if (k == 1) {
            q = &D_80162978[func_800BBEAC(func_801B05F0)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unkC = (p->unkC << 13) / 750;
            q = &D_80162978[func_800BBEAC(func_801B0798)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unkC = (p->unkC << 13) / 350;
            if (p->unk2 == k) {
                q = &D_80162978[func_800BBEAC(func_801B007C)];
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                q->unkC = p->unkC;
                q->unk14 = p->unk14;
                for (i = 0; i < 0x64; i++) {
                    D_801E23EC[p->unk14][i].unk0 = 0;
                }
            }
        }
        if (p->unk2 >= 0x28) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0B28(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 a;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 0) {
            for (i = 0; i < 10; i++) {
                if (1 << i & D_801E23E0) {
                    q = &D_80162978[func_800BBEAC(func_801B0944)];
                    func_800D3994(i, D_8015190F[i][0], &q->unk4);
                    q->unk6 = 0;
                    q->unkC = D_801518F6[i][0] + 0x12C;
                    q->unk14 = i;
                }
            }
            func_800D55F4(0x20, func_800D574C(D_801E23E0), 0x182);
        }
        if (p->unk2 < 8) {
            D_800F5B70[0] = 0x48;
            D_800F5B70[1] = 0x40;
            D_800F5B70[2] = 0;
            a = p->unk2 << 8;
        } else {
            if (p->unk2 >= 0x20) {
                a = 0x800 - ((p->unk2 - 0x20) << 8);
            } else {
                a = 0x800;
            }
        }
        if (p->unk2 == 0x23) {
            for (i = 0; i < 10; i++) {
                if (1 << i & D_801E23E0) {
                    func_800D5774(i);
                }
            }
        }
        if (p->unk2 >= 0x28) {
            a = 0;
            D_800F5B70[1] = 0;
            D_800F5B70[0] = 0;
            p->unk0 = -1;
            func_800D55F4(0x20, func_800D574C(D_801E23E0), 0);
        }
        D_800F5B74[0] = a;
        p->unk2++;
    }
}

INCLUDE_RODATA("../asm/us/magic_lunatic/nonmatchings/text", D_801B0000);

void func_801B0D44(mask, arg1) {
    s32 i;
    s32 n;

    D_801E23DC = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B0E10, 0, 0, 0);
    D_801E23E0 = mask;
    for (i = 0, n = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            n++;
            if (n == 1) {
                D_801E23E4 = i;
            }
        }
    }
    D_801E23E8 = arg1;
    func_800BBEAC(&func_801B0B28);
}
