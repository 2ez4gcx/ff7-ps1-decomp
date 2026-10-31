#include "common.h"
#include "magic_whirl/decls.h"

void func_801B0000(void) {
    func_801B10E0();
}

MgObj4C *func_801B0020(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_801C2F20[i].unk0 == -1) {
            D_801C2F20[i].unk0 = 0;
            D_801C2F20[i].unk2 = 0;
            D_801C2F20[i].unkA = 0;
            return &D_801C2F20[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_whirl/nonmatchings/text", func_801B0098);

INCLUDE_ASM("../asm/us/magic_whirl/nonmatchings/text", func_801B0398);

MgObj4C *func_801B07CC(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_801C4CD0[i].unk0 == -1) {
            D_801C4CD0[i].unk0 = 0;
            D_801C4CD0[i].unk2 = 0;
            D_801C4CD0[i].unkA = 0;
            return &D_801C4CD0[i];
        }
    }
    return NULL;
}

void func_801B0844(void) {
    MgObj20 *p;
    s32 i;
    s32 n;

    n = 0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 100; i++) {
        if (D_801C2F20[i].unk0 != -1) {
            func_801B0098(&D_801C2F20[i]);
            n++;
        }
    }
    if (p->unk0 == 1 && n == 0) {
        p->unk0 = -1;
    }
}

void func_801B0910(void) {
    MgObj20 *p;
    s32 i;
    s32 n;

    n = 0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 100; i++) {
        if (D_801C4CD0[i].unk0 != -1) {
            func_801B0398(&D_801C4CD0[i]);
            n++;
        }
    }
    if (p->unk0 == 1 && n == 0) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        D_801C2ED8++;
    }
}

void func_801B0A08(void) {
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
        D_801C2EF6 = (t << 7) / 15;
        k = t * 0x1500 / 15;
        *(s32 *)0x1F800028 = k;
        sc->vx = k;
    } else {
        t -= 0xF;
        if (t < 0) {
            D_801C2EF6 = 0x80;
            k = 0x1500;
            goto store;
        }
        if (t < 0x1E) {
            D_801C2EF6 = -(t << 7) / 30 + 0x80;
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
    func_8003C21C(&D_801C2EFC, m, t);
    func_8003B35C(m, sc);
    m->t[0] = p->unk8;
    m->t[1] = 0;
    m->t[2] = p->unkC;
    func_8003A63C(&D_800FA63C, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    D_801C2EEC[0] = &D_801C11B0;
    D_801E6A80 = func_800D29D4(D_801C2EEC, D_801517C0 + 0x70, 0xC, D_801E6A80);
    D_801C2EEC[0] = &D_801C1E84;
    D_801E6A80 = func_800D29D4(D_801C2EEC, D_801517C0 + 0x70, 0xC, D_801E6A80);
    if (D_80062D98 == 0) {
        D_801C2EFC.vy += 0x80;
        p->unk2++;
    }
}

void func_801B0C78(void) {
    MgTask *p;
    MgObj4C *q;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 4) {
            D_801C2F04 = (MgTask *)&D_80162978[func_800BBEAC(func_801B0844)];
            D_801C2F04->unk0 = 0;
            D_801C2F08 = (MgTask *)&D_80162978[func_800BBEAC(func_801B0910)];
            D_801C2F08->unk0 = 0;
            D_801C2F0C = (MgTask *)&D_80162978[func_800BBEAC(func_801B0A08)];
            *(MgB8 *)&D_801C2F0C->unk8 = *(MgB8 *)&D_801C2F14;
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
                    q = func_801B07CC();
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
                    D_801C2F1C = -(t << 12) / 15 + 0x1000;
                } else {
                    D_801C2F04->unk0 = -1;
                    D_801C2F08->unk0 = -1;
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

void func_801B0F4C(s32 arg0, s32 arg1) {
    MgTask *p;
    s32 i;

    for (i = 0; i < 100; i++) {
        D_801C2F20[i].unk0 = -1;
    }
    for (i = 0; i < 100; i++) {
        D_801C4CD0[i].unk0 = -1;
    }
    func_800D3994(arg0, D_8015190F[arg0][0], &D_801C2F14);
    D_801C2F16 = 0;
    D_801C2F1C = 0x1000;
    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B0C78)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    func_800D55F4(0x20, func_800D56A8(&D_801C2F14), 0x4E);
}

void func_801B105C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E6A80 = D_801C6A80 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 4);
        p->unk0 = -1;
    }
}

void func_801B10E0(arg0, arg1) {
    func_800D2980(&D_801B1150, 0, 0, 0);
    func_800BBEAC(&func_801B105C);
    func_800D5444(arg0, arg1, 0x5A, &func_801B0F4C);
}
