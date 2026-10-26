#include "common.h"
#include "magic_koudan1/decls.h"

void func_801B0030(void) {
    func_801B0AC4();
}

void func_801B0050(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E33D0 = D_801CB3D0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B00BC(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801CB388[0] = p->unk2;
    *(MgAnim **)&D_801CB388[-4] = D_801CB38C[p->unk1A];
    D_801E33D0 = func_800D4D90(&D_801CB388[-4], D_801517C0 + 0x70, 0xC, D_801E33D0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801CB38C[p->unk1A]->unk4) {
            p->unk0 = -1;
        }
    }
}

void func_801B01B0(void) {
    MgSVec v;
    MgTask *p;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 11; i++) {
        v.vx = p->unk4 * (6 - i) / 6;
        v.vy = p->unk6 * (6 - i) / 6;
        v.vz = p->unk8 * (6 - i) / 6;
        switch (i) {
        case 0:
            D_801CB398[0] = D_801CAF80;
            func_800D4368(&v, 0x1000, 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            break;
        case 1:
            D_801CB398[0] = D_801CAFA0;
            func_800D4368(&v, 0x2000 + (func_80039A74(p->unk2 << 10) * 0x800 >> 12), 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            D_801CB398[0] = D_801CAFC0;
            func_800D4368(&v, 0x1000, 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            D_801CB398[0] = D_801CAFE0;
            func_800D4368(&v, 0x1000, 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            break;
        case 2:
            D_801CB398[0] = D_801CB03C;
            func_800D4368(&v, 0x1000, 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            break;
        case 3:
            D_801CB398[0] = D_801CB05C;
            func_800D4368(&v, 0x1000, 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            break;
        case 4:
            D_801CB398[0] = D_801CB07C;
            func_800D4368(&v, 0x1000, 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            break;
        case 5:
            D_801CB398[0] = D_801CB09C;
            func_800D4368(&v, 0x1000, 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            break;
        case 6:
            D_801CB398[0] = D_801CB0BC;
            func_800D4368(&v, 0x1000, 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            break;
        case 7:
            D_801CB398[0] = D_801CB0DC;
            func_800D4368(&v, 0x1000, 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            break;
        case 8:
            D_801CB398[0] = D_801CB0FC;
            func_800D4368(&v, 0x1000, 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            break;
        case 9:
            D_801CB398[0] = D_801CB11C;
            func_800D4368(&v, 0x1000, 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            break;
        case 10:
            D_801CB398[0] = D_801CB13C;
            func_800D4368(&v, 0x1000, 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            break;
        case 11:
            D_801CB398[0] = D_801CB15C;
            func_800D4368(&v, 0x1000, 0);
            D_801E33D0 = func_800D4D90(D_801CB398, D_801517C0 + 0x70, 0xC, D_801E33D0);
            break;
        }
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B052C(void) {
    MgMat m;
    MgMat r;
    s32 flag;
    s16 i;
    s32 t;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = p->unk2 * 0x320 + 0x1000;
    func_8003C21C(&D_801CB3B4, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801CB3AE[0] = t << 8;
    D_801E33D0 = (u8 *)func_800D29D4(&D_801CB3AE[-5], D_801517C0 + 0x70, 0xC, (s32)D_801E33D0);
    if (D_80062D98 == 0) {
        if (++p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B06A4(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 r;
    s32 r2;
    s32 r3;
    s16 t;
    u8 pad[0x38];

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B01B0)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unkC = (p->unkC - p->unk4) / 20;
            q->unkE = (p->unkE - p->unk6) / 20;
            q->unk10 = (p->unk10 - p->unk8) / 20;
        }
        if (p->unk2 == 0x14) {
            func_800D5774(p->unk1C);
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B052C)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            func_800BBA84(0x189, p->unk1C, 0x40);
        }
        if ((u16)(p->unk2 - 0x13) < 9U) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B00BC)];
                func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
                r = func_80042DA8();
                t = q->unk4 - 0x320;
                q->unk4 = t + r % 1600;
                r2 = func_80042DA8();
                t = q->unk6 - 0x320;
                q->unk6 = t + r2 % 1600;
                r3 = func_80042DA8();
                q->unk1A = i;
                i++;
                t = q->unk8 - 0x320;
                q->unk8 = t + r3 % 1600;
            } while (i < 3);
        }
        p->unk2++;
        if (p->unk2 == 0x28) {
            if (--D_801E33D4 == 0) {
                func_800D52A0(0, 0xA);
            }
            p->unk0 = -1;
        }
    }
}

void func_801B09F0(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B06A4)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    D_801E33D4++;
}

s32 func_801B0AC4(arg0, arg1) {
    func_800BBEAC((M2C_UNK *)func_801B0050);
    func_800D2980(&D_801B0B6C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, (M2C_UNK *)func_801B09F0);
    func_800BBA84(0x188, arg1, 0x40);
    D_801E33D4 = 0;
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    return func_800D52A0(0xC00, 0xA);
}
