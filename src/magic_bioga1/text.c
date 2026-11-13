#include "common.h"
#include "magic_bioga1/decls.h"

void func_801B0000(void) {
    func_801B0C8C();
}

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B0020);

void func_801B03B0(void) {
    MgTask *p;
    MgVec *q;
    MgMat *r;
    MgB8 *s;
    MgB8 *d;
    s32 i;
    s32 t;
    s32 k;
    s32 w;
    s32 g;
    s32 z;
    u8 pad[8];

    p = &D_80162978[D_8015169C];
    q = (MgVec *)0x1F800020;
    r = (MgMat *)0x1F800000;
    k = func_80039A74(p->unk2 * 0x111);
    k = ((k << 8) >> 13) + 0xE80;
    t = p->unk2;
    if (t < 10) {
        w = (t << 12) / 10;
    } else {
        t -= 10;
        if (t < 20) {
            w = 0x1000;
        } else {
            t -= 20;
            if (t >= 10) {
                p->unk0 = -1;
                return;
            }
            w = -(t << 12) / 10 + 0x1000;
        }
    }
    g = (k * w >> 12) * p->unk10 >> 12;
    if (g > 0x7FFF) {
        g = 0x7FFF;
    }
    q->vx = q->vy = q->vz = g;
    if (D_80062D98 == 0) {
        i = 0;
        s = D_801DDD88[p->unk2 & 0xF];
        d = (MgB8 *)D_801D0E88;
        do {
            *d = *s;
            d++;
            i++;
            s++;
        } while (i < 0x146);
    }
    D_801E1CC0.t[0] = p->unk8;
    D_801E1CC0.t[1] = p->unkA;
    D_801E1CC0.t[2] = p->unkC;
    func_8003A63C(&D_800FA63C, &D_801E1CC0, r);
    func_8003B35C(r, q);
    func_8003B48C(r);
    func_8003B51C(r);
    D_801EDEF4 = func_800D29D4(D_801E1CB0, D_801517C0 + 0x70, 0xC, D_801EDEF4);
    if (*(u8 *)0x80062D98 == 0) {
        z = p->unk2;
        if (z * 4 % 15 == 0) {
            i = 0;
        }
        p->unk2 = z + 1;
    }
}

void func_801B0600(void) {
    MgTask *p;
    s16 *frame;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        *(s32 *)&D_801E1CEC = 0x2C808080;
    } else {
        t -= 10;
        if (t < 10) {
            D_801E1CEF = 0x2E;
            c = -(t << 7) / 10 - 0x80;
            D_801E1CEC = D_801E1CED = D_801E1CEE = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    frame = &D_801E1CF0;
    *frame = p->unk2 % 7;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801EDEF4 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EDEF4);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unkA -= p->unk12;
    }
}

void func_801B0778(void) {
    MgTask *p;
    MgTask *q;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0600)];
        q->unk8 = p->unk8 + ((func_80042DA8() % 2000 - 0x3E8) * p->unk10 >> 12);
        q->unkA = 0;
        q->unkC = p->unkC + ((func_80042DA8() % 2000 - 0x3E8) * p->unk10 >> 12);
        v = (func_80042DA8() % 2560 + 0x1000) * p->unk10 >> 12;
        if (v > 0x7FFF) {
            v = 0x7FFF;
        }
        q->unk10 = v;
        q->unk12 = func_80042DA8() % 140 + 10;
        if (++p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0958(void) {
    MgTask *p;
    MgTask *q;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B03B0)];
            *(MgB8 *)&q->unk8 = *(MgB8 *)&p->unk8;
            q->unk10 = p->unk10;
        }
        if ((u16)p->unk2 < 8) {
            if ((p->unk2 & 1) == 0) {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0020)];
                q->unk0 = p->unk2 / 2;
                q->unk8 = p->unk8 + func_80042DA8() % 0x800 - 0x400;
                q->unkA = p->unkA + func_80042DA8() % 0x800 - 0x400;
                q->unkC = p->unkC + func_80042DA8() % 0x800 - 0x400;
                q->unk10 = p->unk10;
            }
        }
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0778)];
            *(MgB8 *)&q->unk8 = *(MgB8 *)&p->unk8;
            q->unk10 = p->unk10;
        }
        k = p->unk2;
        if (k == 0x1E) {
            func_800D5774(p->unk4);
            if (p->unk2 == k) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0B94(s32 arg0) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B0958)];
    p->unk4 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk8);
    p->unk10 = func_800D55A4(arg0);
}

void func_801B0C24(void) {
    MgTask *p;
    u8 *buf;

    p = &D_80162978[D_8015169C];
    buf = D_801B0DA4;
    if (p->unk2 == 0) {
        buf = D_801E1EF4;
    }
    D_801EDEF4 = buf;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0C8C(arg0, arg1) {
    s32 i;
    s32 j;
    s32 k;
    u16 *tbl;

    func_800BBEAC(func_801B0C24);
    if (D_801517BC == 0) {
        tbl = D_801B0E38;
        for (i = 0; i < 0xF; i++) {
            D_801E1CF4[i][0] = 0;
            for (j = 1; j < 0x10; j++) {
                k = j - i;
                if (k >= 2) {
                    D_801E1CF4[i][j] = tbl[k];
                } else {
                    D_801E1CF4[i][j] = tbl[1];
                }
            }
        }
        func_800D2980(D_801B0DA4, 0, 0, 0);
    }
    func_800D5444(arg0, arg1, 0, func_801B0B94);
    func_800D55F4(0x20, func_800D574C(arg0), 0x5A);
}
