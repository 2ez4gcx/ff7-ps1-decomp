#include "common.h"
#include "magic_pink/decls.h"

void func_801B0000(void) {
    func_801B11D4();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E1BD0 = D_801C9BD0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, 0);
    D_801C9B58[0] = p->unk2;
    D_801E1BD0 = func_800D4D90(&D_801C9B58[-4], D_801517C0 + 0x70, 0xC, D_801E1BD0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C9A28) {
            p->unk0 = -1;
        }
    }
}

MgObj8 *func_801B0148(void) {
    s16 i;

    for (i = 0; i < 200; i++) {
        if (D_801E1BD8[i].unk0 == 0) {
            D_801E1BD8[i].unk0 = 1;
            D_801E1BD8[i].unk6 = 0;
            return &D_801E1BD8[i];
        }
    }
    return NULL;
}

void func_801B01C8(MgTask *p) {
    MgSVec rot;
    MgSVec pt;
    MgMat m;
    s32 flag;
    s16 i;
    s16 k;

    rot.vx = rot.vz = 0;
    rot.vy = p->unk14;
    func_8003C21C(&rot, &m);
    m.t[0] = m.t[1] = m.t[2] = 0;
    for (i = 0; i < 200; i++) {
        if (D_801E1BD8[i].unk0 != 0) {
            pt.vx = ((func_80039B40(D_801E1BD8[i].unk4) * D_801E1BD8[i].unk2 * D_801E1BD8[i].unk6) / 20 * (p->unk1A + 0x100)) >> 20;
            pt.vy = ((func_80039A74(D_801E1BD8[i].unk4) * D_801E1BD8[i].unk2 * D_801E1BD8[i].unk6) / 20 * (p->unk1A + 0x100)) >> 20;
            pt.vz = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&pt, &pt, &flag);
            pt.vx += p->unk4 + p->unkC * D_801E1BD8[i].unk6;
            pt.vy += p->unk6 + p->unkE * D_801E1BD8[i].unk6;
            pt.vz += p->unk8 + p->unk10 * D_801E1BD8[i].unk6;
            if (D_801E1BD8[i].unk6 >= 0x11) {
                k = 0x19 - D_801E1BD8[i].unk6;
            } else {
                k = 8;
            }
            func_800D4368(&pt, (s16)(D_801E1BD8[i].unk6 * 0x40 + 0x800), 0);
            D_801C9B60[0] = D_801C9B60[1] = D_801C9B60[2] = k << 4;
            D_801E1BD0 = func_800D4D90(&D_801C9B60[-4], D_801517C0 + 0x70, 0xC, D_801E1BD0);
        }
    }
}

void func_801B04EC(void) {
    MgTask *p;
    MgObj8 *q;
    s16 i;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B01C8(p);
    if (D_80062D98 == 0) {
        p->unk1A += 0xA;
        if ((u16)(p->unk2 - 1) < 0x18U) {
            for (i = 0; i < 4; i++) {
                q = func_801B0148();
                if (q != NULL) {
                    q->unk2 = func_80042DA8() % 800;
                    q->unk4 = func_80042DA8() & 0xFFF;
                }
            }
        }
        for (i = 0, n = 0; i < 200; i++) {
            if (D_801E1BD8[i].unk0 != 0) {
                D_801E1BD8[i].unk4 -= 0x80;
                n++;
                if (++D_801E1BD8[i].unk6 == 0x19) {
                    D_801E1BD8[i].unk0 = 0;
                }
            }
        }
        if (++p->unk2 >= 0x1A && n == 0) {
            p->unk0 = -1;
        }
    }
}

void func_801B06D4(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 *frame;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    p->unkC = -p->unk2 << 7;
    func_8003C21C((MgSVec *)&p->unkC, &m);
    D_801C9B70[0] = p->unk18;
    t = (p->unk1A + 0x100) * 0x1A;
    D_801C9B74 = t;
    D_801C9B70[-1] = t;
    func_8003B35C(&m, (MgVec *)&D_801C9B70[-1]);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801C9B86;
    *frame = D_801C9B68 * 0x10;
    D_801E1BD0 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801E1BD0);
    if (D_80062D98 == 0) {
        p->unk1A += 0xA;
        if (p->unk2 < 8) {
            D_801C9B68 += 1;
        }
        if (p->unk2 >= 0x26) {
            D_801C9B68 -= 1;
        }
        if (++p->unk2 == 0x2D) {
            p->unk0 = -1;
        }
    }
}

void func_801B0884(void) {
    MgTask *p;
    MgColTag *q;
    s32 t;

    p = (MgTask *)&D_801E2218[(s16)D_801E34D8];
    t = p->unk16;
    func_800D4368(&p->unk4, (s16)((t << 11) + 0x800), 0);
    q = &D_801C9B8C;
    q->tag = D_801C9B98[p->unk16];
    D_801C9B8C.r = D_801C9B8C.g = D_801C9B8C.b = (p->unk2 >= 0x16) ? (0x1E - (u8)p->unk2) * 0x10 : 0x80;
    D_801E1BD0 = (u8 *)func_800D4D90(&D_801C9B8C, D_801517C0 + 0x70, 0xC, (s32)D_801E1BD0);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkE += 0xA;
        if (++p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B09DC(void) {
    MgMat m;
    MgMat r;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 *frame;
    s16 i;
    s16 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = p->unk2 * 0xF0 + 0x800;
    func_8003C21C(&D_801C9BB0, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    frame = &D_801C9BAA;
    *frame = p->unk2 * 0x64;
    D_801E1BD0 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801E1BD0);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x14) {
            q = (MgTask *)&D_801E2218[(s16)func_801B1164()];
            q->unk4 = p->unk4;
            q->unk6 = -func_80042DA8() % 100;
            q->unk8 = p->unk8;
            a = func_80042DA8() % 0x1000;
            q->unkC = (u32)(func_80039A74(a) * 0xF) >> 10;
            q->unk10 = (u32)(func_80039B40(a) * 0xF) >> 10;
            q->unkE = -0x96 - func_80042DA8() % 50;
            q->unk16 = func_80042DA8() % 2;
        }
        if (++p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0C94(void) {
    MgSVec v;
    MgTask *p;
    MgTask *q;
    MgObj20 *b;
    s16 i;
    s16 d;
    s16 a;
    s32 r;

    b = D_80162978;
    p = (MgTask *)&b[D_8015169C];
    D_80163C74 = func_800C4FC8(D_801C9BB8, 0, D_801C9BB8);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x10) {
            D_801C9BB8 += 4;
        }
        if (p->unk2 >= 0x5F) {
            D_801C9BB8 -= 4;
        }
        if (p->unk2 == 0) {
            a = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q = (MgTask *)&b[func_800BBEAC(func_801B04EC)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unkC = (p->unkC - p->unk4) / 20;
            q->unkE = 0;
            q->unk10 = (p->unk10 - p->unk8) / 20;
            q->unk1A = 0;
            q->unk14 = a;
            q = (MgTask *)&b[func_800BBEAC(func_801B06D4)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk10 = 0x400;
            q->unkE = a - 0x400;
            v.vx = p->unkC - p->unk4;
            v.vz = p->unk10 - p->unk8;
            d = func_80039F5C(v.vx * v.vx + v.vz * v.vz);
            q->unk1A = 0;
            q->unk18 = d * 0x1500 / 2800;
        }
        if (p->unk2 == 0x30) {
            for (i = 0; i < 10; i++) {
                if ((D_801E1BD4 >> i) & 1) {
                    r = func_800BBEAC(func_801B09DC);
                    q = (MgTask *)D_8016297C;
                    func_800D3994(i, D_8015190F[i][0], &q[r]);
                }
            }
            func_800BBA84(0x19B, -1, 0x40);
        }
        if (p->unk2 == 0x50) {
            for (i = 0; i < 10; i++) {
                if ((D_801E1BD4 >> i) & 1) {
                    func_800D5774(i);
                }
            }
        }
        p->unk2++;
        if (p->unk2 == 0x6E) {
            D_801C9B4C = 1;
            p->unk0 = -1;
        }
    }
}

void func_801B1030(void) {
    MgObj20 *q;
    MgObj20 *p;

    q = D_801E2218;
    D_801E34D8 = 0;
    p = &D_80162978[D_8015169C];
    do {
        if (q->unk0 == 1) {
            func_801B0884();
            if (q->unk0 == -1) {
                q->unk2 = 0;
                q->unk0 = 0;
            }
        }
        D_801E34D8++;
        q++;
    } while ((s16)D_801E34D8 < 0x96);
    if (D_801C9B4C == 1) {
        p->unk0 = -1;
    }
}

void func_801B110C(void) {
    MgObj20 *p;
    s16 i;

    p = D_801E2218;
    for (i = 0; i < 150; i++) {
        p->unk2 = 0;
        p->unk0 = 0;
        p++;
    }
    func_800BBEAC(&func_801B1030);
}

s32 func_801B1164(void) {
    MgObj20 *p;
    s16 i;

    p = D_801E2218;
    for (i = 0; i < 150; i++) {
        if (p->unk0 == 0) {
            p->unk0 = 1;
            return i;
        }
        p++;
    }
    return func_800BBA84(6, -1, 0x40);
}

s32 func_801B11D4(arg0, arg1) {
    MgTask *p;
    s16 i;

    func_800BBEAC((void *)func_801B0020);
    func_800D2980((void *)D_801B12EC, 0, 0, 0);
    D_801E1BD4 = arg0;
    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0C94)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D54EC(arg0, &p->unkC);
    i = 0;
    do {
        D_801E1BD8[i].unk0 = 0;
        i++;
    } while (i < 200);
    func_801B110C();
    return func_800BBA84(0x11F, arg1, 0x40);
}
