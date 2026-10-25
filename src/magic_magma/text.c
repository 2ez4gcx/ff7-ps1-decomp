#include "common.h"
#include "magic_magma/decls.h"

void func_801B0000(void) {
    func_801B07E0();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C8D98 = D_801B0D98 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

MgObj18 *func_801B008C(void) {
    s16 i;

    for (i = 0; i < 300; i++) {
        if (D_801C8D9C[i].unk0 == 0) {
            D_801C8D9C[i].unk0 = 1;
            D_801C8D9C[i].unk2 = 0;
            return &D_801C8D9C[i];
        }
    }
    return NULL;
}

void func_801B0118(void) {
    MgTask *p;
    MgObj18 *e;
    MgObj18 *q;
    u8 *col;
    s16 i;
    s16 a;
    s16 b;
    s16 n;
    s32 c;
    s32 r;
    s32 t;
    s32 u;
    s32 w;

    i = 0;
    col = D_801B0D84;
    p = (MgTask *)&D_80162978[D_8015169C];
    for (; i < 0x12C; i++) {
        if (D_801C8D9C[i].unk0 == 1) {
            c = -0x80 - D_801C8D9C[i].unk2 * 8;
            col[2] = c;
            col[1] = c;
            col[0] = c;
            func_800D4368(&D_801C8D9C[i].unk8, D_801C8D9C[i].unk4, 0);
            D_801C8D98 = func_800D4D90(col - 4, D_801517C0 + 0x70, 0xC, D_801C8D98);
        }
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x3C) {
            for (i = 0; i < (0x3C - p->unk2) / 5 + 1; i++) {
                q = func_801B008C();
                if (q != 0) {
                    r = func_80042DA8();
                    a = r % 0x1000;
                    b = func_80042DA8() % 200;
                    q->unk8 = D_801B0D90.vx + ((func_80039B40(a) * b) >> 12);
                    q->unkC = D_801B0D90.vz + ((func_80039A74(a) * b) >> 12);
                    q->unkA = D_801B0D90.vy;
                    r = func_80042DA8();
                    a = r % 0x1000;
                    b = func_80042DA8() % 100;
                    q->unk10 = (func_80039B40(a) * b) >> 12;
                    q->unk14 = (func_80039A74(a) * b) >> 12;
                    t = (func_80039A74(p->unk2 << 10) * 0x14) >> 12;
                    u = p->unk2 * 2 - 0x15E;
                    q->unk12 = t + u;
                    w = func_80042DA8() % 4 * 0x200 + 0xC00;
                    q->unk4 = w - p->unk2 * 0x1E;
                }
            }
        }
        i = 0;
        n = 0;
        q = D_801C8D9C;
        for (; i < 0x12C; i++) {
            if (q->unk0 == 1) {
                q->unk8 += q->unk10;
                q->unkA += q->unk12;
                q->unkC += q->unk14;
                q->unk12 += 0x14;
                if (q->unk2 == 0) {
                    if ((s16)(q->unk12 - 0x14) < 0 && q->unk12 >= 0) {
                        q->unk2 = 1;
                    }
                } else {
                    q->unk2++;
                    if (q->unk2 == 0x10) {
                        q->unk0 = 0;
                    }
                }
                n++;
            }
            q++;
        }
        p->unk2++;
        if (p->unk2 >= 0x3D && n == 0) {
            p->unk0 = -1;
        }
    }
}

void func_801B05C0(void) {
    MgTask *p;
    u16 *q;
    s32 t;
    s32 x;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(D_801B0D8C, 0, 0);
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_800BBEAC(func_801B0118);
        }
        if (p->unk2 < 0x10) {
            D_801B0D8C += 4;
        }
        if (p->unk2 > 0x40) {
            D_801B0D8C -= 4;
        }
        if (p->unk2 == 0x3C) {
            func_800D5774(p->unk18);
        }
        q = &D_801031EA;
        t = *q + 0x20;
        x = (p->unk2 % 2) << 6;
        *q = t - x;
        p->unk2++;
        if (p->unk2 == 0x50) {
            p->unk0 = -1;
        }
    }
}

void func_801B071C(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B05C0)];
    func_800D3994(arg1, D_8015190F[arg1][9], &D_801B0D90);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk18 = arg0;
}

s32 func_801B07E0(arg0, arg1) {
    s16 i;

    func_800BBEAC(func_801B0020);
    func_800D2980(&D_801B08A0, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B071C);
    func_800BBA84(0x165, arg1, 0x40);
    for (i = 0; i < 300; i++) {
        D_801C8D9C[i].unk0 = 0;
    }
}
