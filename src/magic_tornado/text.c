#include "common.h"
#include "magic_tornado/decls.h"

void func_801B0000(void) {
    func_801B10F4();
}

MgObj4C *func_801B0020(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_801C2F34[i].unk0 == -1) {
            D_801C2F34[i].unk0 = 0;
            D_801C2F34[i].unk2 = 0;
            D_801C2F34[i].unkA = 0;
            return &D_801C2F34[i];
        }
    }
    return NULL;
}

void func_801B0098(WhOrb *a) {
    s16 *v;
    s16 *rot;
    MgMat *m;
    s32 i;
    s32 k;
    s32 n;
    s16 t;
    s16 w;
    s32 x;
    s32 u;
    u32 c;

    v = (s16 *)0x1F800000;
    rot = (s16 *)0x1F800008;
    m = (MgMat *)0x1F800010;
    if (D_80062D98 == 0) {
        i = 0;
        do {
            a->unk4[2] += 0x25000 / a->unk4[0];
            t = a->unk4[1] - 0x3A98 / (a->unk4[0] - 0x12C);
            a->unk4[1] = t;
            u = a->unk4[0];
            if (t >> 3 >= -0x6D) {
                x = u + (-0x64 - (t >> 4));
            } else {
                x = u + 0xA;
            }
            a->unk4[0] = x;
            if ((s16)x < 0x190) {
                a->unk4[0] = 0x190;
            }
            v[0] = a->unk4[0];
            w = a->unk4[1];
            v[2] = 0;
            rot[0] = 0;
            rot[2] = 0;
            v[1] = w;
            rot[1] = a->unk4[2];
            func_8003C21C(rot, m);
            func_8003B2CC(m, v, v);
            a->pts[a->unkA].vx = v[0] + D_801C2F28.vx;
            a->pts[a->unkA].vy = v[1];
            a->pts[a->unkA].vz = v[2] + D_801C2F28.vz;
            i++;
            a->unkA = (a->unkA + 1) & 7;
        } while (i < 3);
    }
    n = a->unk2;
    i = 1;
    if (n >= 6) {
        n = 5;
    }
    k = (a->unkA - n) & 7;
    if (i < n) {
        do {
            if ((u32)(func_800D4368(&a->pts[k], 0x1000, 0)->depth - 1) < 0x752F) {
                c = (u32)(((i << 7) / 5) * D_801C2F30) >> 12;
                D_801C2EF8.r = D_801C2EF8.g = D_801C2EF8.b = c;
                D_801E6A94 = func_800D6260((u8 *)&D_801C2EF8 - 8, D_801517C0 + 0x70, 0xC, D_801E6A94);
            }
            k = (k + 1) & 7;
            i++;
        } while (i < n);
    }
    if (D_80062D98 == 0) {
        w = (u16)a->unk2 + 1;
        a->unk2 = w;
        if (w >= 0x33) {
            a->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_tornado/nonmatchings/text", func_801B03AC);

MgObj4C *func_801B07E0(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_801C4CE4[i].unk0 == -1) {
            D_801C4CE4[i].unk0 = 0;
            D_801C4CE4[i].unk2 = 0;
            D_801C4CE4[i].unkA = 0;
            return &D_801C4CE4[i];
        }
    }
    return NULL;
}

void func_801B0858(void) {
    MgObj20 *p;
    s32 i;
    s32 n;

    n = 0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 100; i++) {
        if (D_801C2F34[i].unk0 != -1) {
            func_801B0098(&D_801C2F34[i]);
            n++;
        }
    }
    if (p->unk0 == 1 && n == 0) {
        p->unk0 = -1;
    }
}

void func_801B0924(void) {
    MgObj20 *p;
    s32 i;
    s32 n;

    n = 0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 100; i++) {
        if (D_801C4CE4[i].unk0 != -1) {
            func_801B03AC(&D_801C4CE4[i]);
            n++;
        }
    }
    if (p->unk0 == 1 && n == 0) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        D_801C2EEC++;
    }
}

void func_801B0A1C(void) {
    MgTask *p;
    MgMat *m;
    MgVec *sc;
    s32 t;
    s32 k;

    sc = (MgVec *)0x1F800020;
    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    m = (MgMat *)0x1F800000;
    if (t < 0xF) {
        *(s32 *)0x1F800024 = 0x1500;
        D_801C2F0A = (t << 7) / 15;
        k = t * 0x1500 / 15;
        *(s32 *)0x1F800028 = k;
        sc->vx = k;
    } else {
        t -= 0xF;
        if (t < 0) {
            D_801C2F0A = 0x80;
            k = 0x1500;
            goto store;
        }
        if (t < 0x1E) {
            D_801C2F0A = -(t << 7) / 30 + 0x80;
            k = (t << 12) / 30 + 0x1500;
store:
            *(s32 *)0x1F800028 = k;
            do {
                sc->vx = k;
                *(s32 *)0x1F800024 = k;
            } while (0);
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003C21C(&D_801C2F10, m, t);
    func_8003B35C(m, sc);
    m->t[0] = p->unk8;
    m->t[1] = 0;
    m->t[2] = p->unkC;
    func_8003A63C(&D_800FA63C, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    D_801C2F00[0] = &D_801C11C4;
    D_801E6A94 = func_800D29D4(D_801C2F00, D_801517C0 + 0x70, 0xC, D_801E6A94);
    D_801C2F00[0] = &D_801C1E98;
    D_801E6A94 = func_800D29D4(D_801C2F00, D_801517C0 + 0x70, 0xC, D_801E6A94);
    if (D_80062D98 == 0) {
        D_801C2F10.vy += 0x80;
        p->unk2++;
    }
}

void func_801B0C8C(void) {
    MgTask *p;
    MgObj4C *q;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 4) {
            D_801C2F18 = (MgTask *)&D_80162978[func_800BBEAC(func_801B0858)];
            D_801C2F18->unk0 = 0;
            D_801C2F1C = (MgTask *)&D_80162978[func_800BBEAC(func_801B0924)];
            D_801C2F1C->unk0 = 0;
            D_801C2F20 = (MgTask *)&D_80162978[func_800BBEAC(func_801B0A1C)];
            *(MgB8 *)&D_801C2F20->unk8 = *(MgB8 *)&D_801C2F28;
        }
        if (p->unk2 == 0x22) {
            func_800D5774(p->unk4);
        }
        if (p->unk2 == 0) {
            func_800D52A0(0x400, 4);
            D_800F5B70 = 0;
            D_800F5B71 = 0;
            D_800F5B72 = 0;
        }
        t = p->unk2 - 4;
        if (t >= 0) {
            if (t < 0x1E) {
                if (t % 5 == 0) {
                    q = func_801B07E0();
                    if (q != 0) {
                        q->unk4[0] = func_80042DA8() % 1000 + 5000;
                        q->unk4[1] = 0;
                        q->unk4[2] = func_80042DA8() & 0xFFF;
                    }
                }
                q = func_801B0020();
                if (q != 0) {
                    q->unk4[0] = func_80042DA8() % 1000 + 5000;
                    q->unk4[1] = 0;
                    q->unk4[2] = func_80042DA8() & 0xFFF;
                    q->unk0 = 0;
                }
            } else {
                t = p->unk2 - 0x22;
                if (t < 0xF) {
                    D_801C2F30 = -(t << 12) / 15 + 0x1000;
                } else {
                    D_801C2F18->unk0 = -1;
                    D_801C2F1C->unk0 = -1;
                }
            }
            t = p->unk2;
        }
        if (p->unk2 == 0x31) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0F60(s32 arg0, s32 arg1) {
    MgTask *p;
    s32 i;

    for (i = 0; i < 100; i++) {
        D_801C2F34[i].unk0 = -1;
    }
    for (i = 0; i < 100; i++) {
        D_801C4CE4[i].unk0 = -1;
    }
    func_800D3994(arg0, D_8015190F[arg0][0], &D_801C2F28);
    D_801C2F2A = 0;
    D_801C2F30 = 0x1000;
    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B0C8C)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    func_800D55F4(0x20, func_800D56A8(&D_801C2F28), 0x4E);
}

void func_801B1070(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E6A94 = D_801C6A94 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 4);
        p->unk0 = -1;
    }
}

void func_801B10F4(arg0, arg1) {
    func_800D2980(&D_801B1164, 0, 0, 0);
    func_800BBEAC(&func_801B1070);
    func_800D5444(arg0, arg1, 0x5A, &func_801B0F60);
}
