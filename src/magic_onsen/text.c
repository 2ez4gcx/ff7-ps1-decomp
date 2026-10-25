#include "common.h"
#include "magic_onsen/decls.h"

void func_801B0000(void) {
    func_801B078C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C8D44 = D_801B0D44 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

MgObj18 *func_801B008C(void) {
    s16 i;

    for (i = 0; i < 300; i++) {
        if (D_801C8D48[i].unk0 == 0) {
            D_801C8D48[i].unk0 = 1;
            D_801C8D48[i].unk2 = 0;
            return &D_801C8D48[i];
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

    i = 0;
    col = D_801B0D30;
    p = (MgTask *)&D_80162978[D_8015169C];
    for (; i < 0x12C; i++) {
        if (D_801C8D48[i].unk0 == 1) {
            c = -0x80 - D_801C8D48[i].unk2 * 8;
            col[2] = c;
            col[1] = c;
            col[0] = c;
            func_800D4368(&D_801C8D48[i].unk8, D_801C8D48[i].unk4, 0);
            D_801C8D44 = func_800D4D90(col - 4, D_801517C0 + 0x70, 0xC, D_801C8D44);
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
                    q->unk8 = D_801B0D3C.vx + ((func_80039B40(a) * b) >> 12);
                    q->unkC = D_801B0D3C.vz + ((func_80039A74(a) * b) >> 12);
                    q->unkA = D_801B0D3C.vy;
                    r = func_80042DA8();
                    a = r % 0x1000;
                    b = func_80042DA8() % 100;
                    q->unk10 = (func_80039B40(a) * b) >> 12;
                    q->unk14 = (func_80039A74(a) * b) >> 12;
                    t = (func_80039A74(p->unk2 << 10) * 0x14) >> 12;
                    u = p->unk2 * 2 - 0x15E;
                    q->unk12 = t + u;
                    q->unk4 = func_80042DA8() % 4 * 0x200 + 0x800;
                }
            }
        }
        i = 0;
        n = 0;
        q = D_801C8D48;
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

void func_801B05AC(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(D_801B0D38, D_801B0D38, D_801B0D38);
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_800BBEAC(&func_801B0118);
        }
        if (p->unk2 < 0x10) {
            D_801B0D38 += 4;
        }
        if (p->unk2 >= 0x37) {
            D_801B0D38 -= 4;
        }
        if (p->unk2 == 0x3C) {
            func_800D5774(p->unk18);
        }
        if (++p->unk2 == 0x46) {
            p->unk0 = -1;
        }
    }
}

void func_801B06C8(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B05AC)];
    func_800D3994(arg1, D_8015190F[arg1][9], &D_801B0D3C);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk18 = arg0;
}

void func_801B078C(arg0, arg1) {
    s16 i;

    func_800BBEAC((void *)func_801B0020);
    func_800D2980(D_801B084C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, (void *)func_801B06C8);
    func_800BBA84(0x10B, arg1, 0x40);
    for (i = 0; i < 0x12C; i++) {
        D_801C8D48[i].unk0 = 0;
    }
}
