#include "common.h"
#include "magic_gaishu/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B094C();
    return &D_801B2F08;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CB434 = D_801B3434 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0094(void) {
    MgMat m;
    MgMat lw;
    s32 sc[3];
    MgTask *p;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_801B33FE[0] = p->unk2 << 7;
    func_8003BF8C((MgSVec *)&D_801B33FE[-1], &m);
    sc[0] = sc[1] = sc[2] = D_801B3416;
    func_8003B35C(&m, sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    v = D_801B3414;
    D_801B340E[0] = 0x1000 - (v << 9);
    D_801CB434 = func_800D29D4(&D_801B340E[-5], D_801517C0 + 0x70, 0xC, D_801CB434);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x1E) {
            D_801B3416 += 0x258;
        } else {
            p->unk6 -= 0x12C;
        }
        if (p->unk2 < 8) {
            D_801B3414++;
        }
        if (p->unk2 >= 0x2B) {
            D_801B3414--;
        }
        p->unk2++;
        if (p->unk2 == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B027C(void) {
    MgMat m;
    MgMat lw;
    s32 sc[3];
    MgTask *p;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_801B341A[0] = p->unk2 << 5;
    func_8003BF8C((MgSVec *)&D_801B341A[-1], &m);
    sc[0] = sc[1] = sc[2] = p->unk2 * 0xC8 + 0x800;
    func_8003B35C(&m, sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    v = D_801B3430;
    D_801B342A[0] = 0x1000 - (v << 8);
    D_801CB434 = func_800D29D4(&D_801B342A[-5], D_801517C0 + 0x70, 0xC, D_801CB434);
    if (D_80062D98 == 0) {
        if (p->unk2 < 8) {
            D_801B3430 += 2;
        }
        if (p->unk2 >= 0x2C) {
            D_801B3430--;
        }
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0434(void) {
    MgMat m;
    MgSVec a;
    MgSVec b;
    s32 flag;
    s32 otz;
    MgTask *p;
    u8 *pkt;
    s32 n;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C((MgSVec *)&p->unkC, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    a.vz = (10 - p->unk2) * 0x320;
    a.vx = a.vy = 0;
    func_8003BADC(&a, &a, &flag);
    b.vz = (10 - p->unk2) * 0xC8;
    b.vx = b.vy = 0;
    func_8003BADC(&b, &b, &flag);
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    pkt = D_801CB434;
    func_800469D8(pkt);
    func_80046848(pkt, 1);
    n = func_8003BBDC(&a, pkt + 8, &otz, &flag);
    if (n > 0) {
        pkt[6] = 0;
        pkt[5] = 0;
        pkt[4] = 0;
        pkt[0xE] = 0x80;
        pkt[0xD] = 0x80;
        pkt[0xC] = 0x80;
        func_8003BBDC(&b, pkt + 0x10, &otz, &flag);
        t = (n >> 2) * 4 + 0x70;
        func_80046794(t + D_801517C0, pkt);
        D_801CB434 = pkt + 0x14;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B0640(void) {
    MgTask *p;
    MgTask *q;
    s32 z;
    u8 pad[24];
    s16 i;
    u16 n;
    MgSVec *c;

    p = (MgTask *)&D_80162978[D_8015169C];
    z = D_80062D98;
    if (z == 0) {
        if (p->unk2 == 0x14) {
            D_8009A000 = 0x21;
            D_8009A004 = func_800D574C(D_801CB438);
            D_8009A008 = 0x130;
            D_8009A00C = 0x145;
            func_8002DA7C();
        }
        if (p->unk2 == 0x1E) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B027C)];
            q->unk4 = ((MgSVec *)D_801CB43C)->vx;
            q->unk6 = ((MgSVec *)D_801CB43C)->vy;
            q->unk8 = ((MgSVec *)D_801CB43C)->vz;
            D_800F5B70.r = D_800F5B70.g = 0;
            D_800F5B70.b = 0x40;
            func_800D52A0(0x1000, 0xA);
        }
        n = p->unk2;
        if ((u32)(n - 0x14) < 0x3CU) {
            i = 0;
            if (i < (0x50 - (s16)n) / 10) {
                c = (MgSVec *)D_801CB43C;
                do {
                    q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0434)];
                    q->unk4 = c->vx;
                    q->unk6 = c->vy;
                    q->unk8 = c->vz;
                    q->unkC = 0;
                    q->unkE = func_80042DA8() % 0x1000;
                    q->unk10 = 0;
                    i++;
                } while (i < (0x50 - p->unk2) / 10);
            }
        }
        if (p->unk2 == 0x28) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0094)];
            q->unk4 = ((MgSVec *)D_801CB43C)->vx;
            q->unk6 = ((MgSVec *)D_801CB43C)->vy;
            q->unk8 = ((MgSVec *)D_801CB43C)->vz;
        }
        if (p->unk2 == 0x50) {
            for (i = 0; i < 10; i++) {
                if ((D_801CB438 >> i) & 1) {
                    func_800D5774(i);
                }
            }
        }
        p->unk2++;
        if (p->unk2 == 0x64) {
            p->unk0 = -1;
            func_800D52A0(0, 0xA);
        }
    }
}

void func_801B094C(arg0, arg1) {
    func_800BBEAC(func_801B0028);
    func_800D2980(D_801B09E0, 0, 0, 0);
    D_801CB438 = arg0;
    func_800D54EC(arg0, D_801CB43C);
    D_80162996[func_800BBEAC(func_801B0640)].unk0 = arg1;
}
