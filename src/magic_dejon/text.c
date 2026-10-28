#include "common.h"
#include "magic_dejon/decls.h"

void func_801B0000(void) {
    func_801B0D0C();
}

void func_801B0020(void) {
    MgMat m;
    MgTask *p;
    s32 v;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x14) {
        v = t * 0x2500 / 20;
    } else {
        t -= 0x14;
        v = 0x2500;
        if (t >= 0x28) {
            t -= 0x28;
            if (t < 0xA) {
                v = -(t * 0x2500) / 10 + 0x2500;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801C6BC8.m[0][0] = D_801C6BD6 = v;
    D_801C6BD2 = -v;
    D_801C6BDC = *(s16 *)((u8 *)p + 4);
    D_801C6BE0 = 0;
    D_801C6BE4 = *(s16 *)((u8 *)p + 8);
    func_8003A63C(&D_800FA63C, &D_801C6BC8, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801E6E34 = func_800D4D90(&D_801C6BBC, D_801517C0 + 0x70, 0xC, D_801E6E34);
    D_801E6E34 = func_800D4D90(&D_801C6BB0, D_801517C0 + 0x70, 0xC, D_801E6E34);
    func_800D2538(&D_801C6BE8, D_801C6C28[(s16)(p->unk2 % 15)]);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0238(void) {
    MgSVec pos;
    MgTask *p;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 2) {
        c = t << 6;
        D_801C6BFA = c;
        D_801C6BF9 = c;
        D_801C6BF8 = c;
    } else if ((t -= 2) < 0x19) {
        c = 0x80;
        D_801C6BFA = c;
        D_801C6BF9 = c;
        D_801C6BF8 = c;
    } else {
        p->unk0 = -1;
        return;
    }
    pos.vx = p->unk4;
    pos.vy = p->unk6 - (func_80039A74((p->unk2 << 11) / 27) * 0x3E8 >> 12);
    pos.vz = p->unk8;
    func_800D4368(&pos, p->unk14, 0);
    D_801E6E34 = func_800D6260(&D_801C6BF0, D_801517C0 + 0x70, 0xC, D_801E6E34);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
    }
}

void func_801B03A4(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 *rot;
    s32 t;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x14) {
        D_801C6C22 = 0x80;
        v = t * 0x3000 / 20;
        D_801C6C10 = v;
        D_801C6C08.vx = v;
    } else if ((t -= 0x14) < 0x1E) {
        D_801C6C10 = 0x3000;
        D_801C6C08.vx = 0x3000;
        D_801C6C22 = 0x80;
    } else if ((t -= 0x1E) < 0xA) {
        D_801C6C10 = 0x3000;
        D_801C6C08.vx = 0x3000;
        D_801C6C22 = -(t << 7) / 10 + 0x80;
    } else {
        p->unk0 = -1;
        return;
    }
    rot = &D_801C6C02;
    *rot = p->unk2 * 0x20;
    func_8003C21C((MgSVec *)((u8 *)rot - 2), &m);
    func_8003B35C(&m, &D_801C6C08);
    m.t[0] = p->unk4;
    m.t[1] = 0;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801E6E34 = func_800D29D4(&D_801C6C18, D_801517C0 + 0x70, 0xC, D_801E6E34);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0590(void) {
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t >= 0x1E) {
            *(MgBytes8 *)&D_80151A4C[p->unk16] = *(MgBytes8 *)&p->unk4;
            D_801518EA[p->unk16][0] = p->unk14;
            func_800B8E48(p->unk16);
            p->unk0 = -1;
        } else {
            D_801518EA[p->unk16][0] = p->unk14 + -p->unk14 * t / 30;
            D_80151A4C[p->unk16].vx += p->unkC;
            D_80151A4C[p->unk16].vy += p->unkE;
            D_80151A4C[p->unk16].vz += p->unk10;
            p->unk2++;
        }
    }
}

void func_801B0818() {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 off;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0020)];
            *(MgBytes8 *)&q->unk4 = *(MgBytes8 *)&D_801C6E2C;
        }
        if ((u16)p->unk2 < 0x1E) {
            i = 0;
            do {
                i++;
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0238)];
                q->unk4 = D_801C6E2C.vx + func_80042DA8() % 10000 - 5000;
                q->unk6 = -func_80042DA8() % 5000;
                q->unk8 = D_801C6E2C.vz + func_80042DA8() % 10000 - 5000;
                q->unkC = (D_801C6E2C.vx - q->unk4) / 27;
                q->unkE = -q->unk6 / 27;
                q->unk10 = (D_801C6E2C.vz - q->unk8) / 27;
                q->unk14 = func_80042DA8() % 3328 + 0x500;
            } while (i < 3);
        }
        if (p->unk2 == 2) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B03A4)];
            *(MgBytes8 *)&q->unk4 = *(MgBytes8 *)&D_801C6E2C;
            q->unk6 = 0;
        }
        if (p->unk2 == 0x14) {
            for (i = 0; i < 10; i++) {
                off = i * 0xB9C;
                if (D_801C6E28 >> i & 1) {
                    if (D_801517B4 >> i & 1) {
                        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0590)];
                        *(MgBytes8 *)&q->unk4 = *(MgBytes8 *)((u8 *)D_80151A4C + off);
                        q->unk14 = *(u16 *)((u8 *)D_801518EA + off);
                        q->unk16 = i;
                        q->unkC = (D_801C6E2C.vx - q->unk4) / 30;
                        q->unkE = (D_801C6E2C.vy - q->unk6) / 30;
                        q->unk10 = (D_801C6E2C.vz - q->unk8) / 30;
                    }
                }
            }
        }
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0CAC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E6E34 = D_801C6E34 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B0D0C(arg0) {
    s32 i;
    s32 j;
    u16 *p;
    u16 v;

    func_800BBEAC(func_801B0CAC);
    D_801C6E28 = arg0;
    func_800D54EC(arg0, &D_801C6E2C);
    p = D_801B0E3A;
    for (i = 0; i < 15; i++) {
        v = *p++;
        D_801C6C28[i][0] = 0;
        for (j = 0; j < 15; j++) {
            D_801C6C28[j][(j + i) % 15 + 1] = v;
        }
    }
    func_800D2980(&D_801B0E24, 0, 0, 0);
    func_800BBEAC(func_801B0818);
    return func_800D55F4(0x20, 0x40, 0x4F);
}
