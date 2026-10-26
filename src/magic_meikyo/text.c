#include "common.h"
#include "magic_meikyo/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0A80();
    return &D_801C1EB0;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DB9D8 = D_801C39D8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0094(MeikyoTask *p) {
    s16 n;
    u8 *q;

    func_800D4368(&p->unk4, 0x800, 0);
    q = &D_801C39B8;
    *q = D_801C39B9 = D_801C39BA = -0x80 - p->unk2 * 8;
    D_801DB9D8 = func_800D4D90(q - 4, D_801517C0 + 0x70, 0xC, D_801DB9D8);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x10) {
            p->unk0 = 0;
        }
    }
}

void func_801B0180(MeikyoTask *p) {
    MgMat m;
    MgSVec a;
    MgSVec b;
    s32 flag;
    s32 ext;
    MeikyoLine *prim;
    s32 r;
    s32 k;

    func_8003C21C(&p->unkC, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    a.vz = (10 - p->unk2) * 0x258;
    a.vy = 0;
    a.vx = 0;
    func_8003BADC(&a, &a, &flag);
    b.vz = (10 - p->unk2) * 0xC8;
    b.vy = 0;
    b.vx = 0;
    func_8003BADC(&b, &b, &flag);
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    prim = (MeikyoLine *)D_801DB9D8;
    func_800469D8(prim);
    func_80046848(prim, 1);
    r = func_8003BBDC(&a, &prim->x0, &ext, &flag);
    if (r > 0) {
        prim->b0 = 0;
        prim->g0 = 0;
        prim->r0 = 0;
        prim->r1 = 0;
        prim->b1 = 0x80;
        prim->g1 = 0x80;
        func_8003BBDC(&b, &prim->x1, &ext, &flag);
        k = 0x70;
        func_80046794(((r >> 2) << 2) + k + D_801517C0, prim);
        D_801DB9D8 = (u8 *)(prim + 1);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0xA) {
            p->unk0 = 0;
        }
    }
}

void func_801B0378(void) {
    MeikyoTask *p;
    s16 i;

    i = 0;
    p = D_801DB9DC;
    do {
        switch (p->unk0) {
        case 1:
            func_801B0180(p);
            break;
        case 2:
            func_801B0094(p);
            break;
        }
        i++;
        p++;
    } while (i < 0x12C);
}

MeikyoTask *func_801B0418(s16 arg0) {
    s16 i;

    for (i = 0; i < 0x12C; i++) {
        if (D_801DB9DC[i].unk0 == 0) {
            D_801DB9DC[i].unk0 = arg0;
            D_801DB9DC[i].unk2 = 0;
            return &D_801DB9DC[i];
        }
    }
    return NULL;
}

void func_801B04A0(void) {
    MgMat m;
    MgMat w;
    MgVec v;
    MgSVec a;
    MgSVec b;
    s32 flag;
    MgTask *p;
    MeikyoTask *q;
    s16 *c;
    u8 *d;
    s16 j;
    s16 k;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801C39D0, &m);
    v.vx = v.vy = v.vz = p->unk18 * p->unk2;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = 0;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &w);
    func_8003B48C(&w);
    func_8003B51C(&w);
    func_8003B69C(0, 0, 0);
    c = &D_801C39CA;
    d = (u8 *)c - 0xA;
    *c = p->unk2 * 0x64;
    *(u8 **)d = &D_801C0B88;
    D_801DB9D8 = func_800D29D4(d, D_801517C0 + 0x70, 0xC, D_801DB9D8);
    func_8003BF8C(&D_801C39D0, &m);
    v.vx = v.vy = v.vz = p->unk18 * p->unk2;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = 0;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &w);
    func_8003B48C(&w);
    func_8003B51C(&w);
    *(u8 **)d = &D_801C196C;
    D_801DB9D8 = func_800D29D4(d, D_801517C0 + 0x70, 0xC, D_801DB9D8);
    if (D_80062D98 == 0) {
        j = 0;
        if (p->unk2 < 0x14) {
            while (j < (0x14 - p->unk2) / 4 + 1) {
                q = func_801B0418(1);
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unkC = func_80042DA8() % 0x1000;
                q->unkE = func_80042DA8() % 0x1000;
                q->unk10 = 0;
                j++;
            }
        }
        if (p->unk2 == 0x23) {
            for (j = 0; j < 2; j++) {
                for (k = 0; k < 0x10; k++) {
                    q = func_801B0418(2);
                    if (q != NULL) {
                        q->unk4 = p->unk4;
                        q->unk6 = p->unk6;
                        q->unk8 = p->unk8;
                        r = (k << 16) >> 8;
                        a.vx = (u32)(func_80039A74(r) * 0x19) >> 9;
                        a.vy = 0;
                        a.vz = (u32)(func_80039B40(r) * 0x19) >> 9;
                        b.vx = b.vy = 0;
                        b.vz = ((j << 16) >> 6) - 0x200;
                        func_8003C4AC(&b, &m);
                        m.t[0] = m.t[1] = m.t[2] = 0;
                        func_8003B48C(&m);
                        func_8003B51C(&m);
                        func_8003BADC(&a, &q->unkC, &flag);
                    }
                }
            }
        }
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B089C(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 v;
    u8 pad[0x30];

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B0378();
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x3C) {
            for (i = 0; i < 10; i++) {
                if ((D_801DD14C >> i) & 1) {
                    q = (MgTask *)&D_80162978[func_800BBEAC(func_801B04A0)];
                    func_800D3994(i, D_8015190F[i][0], &q->unk4);
                    v = (s16)D_801518F6[i][0] / 2;
                    q->unk18 = v;
                    if (v > 0x320) {
                        q->unk18 = 0x320;
                    }
                }
            }
            func_800BBA84(0x130, -1, 0x40);
        }
        if (p->unk2 == 0x64) {
            for (i = 0; i < 10; i++) {
                if ((D_801DD14C >> i) & 1) {
                    func_800D5774(i);
                }
            }
            func_800BBA84(0x6C, -1, 0x40);
        }
        p->unk2++;
        if (p->unk2 == 0x6E) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B0A80(arg0) {
    s16 i;

    func_800BBEAC(func_801B0028);
    D_801DD14C = arg0;
    func_800D2980(&D_801B0B28, 0, 0, 0);
    func_800BBEAC(func_801B089C);
    for (i = 0; i < 0x12C; i++) {
        D_801DB9DC[i].unk0 = 0;
    }
}
