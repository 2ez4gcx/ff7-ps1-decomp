#include "common.h"
#include "magic_thunder2/decls.h"

void func_801B0000(void) {
    func_801B147C();
}

void func_801B0020(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801EA20C = D_801D220C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 0xA);
        p->unk0 = -1;
    }
}

void func_801B00B0(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D2174.unk0 = D_801D2180[p->unk16];
    D_801D2174.unk8 = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D2174, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D2180[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B01A4(void) {
    s32 f;
    MgObjAwa *p;
    s16 *frame;
    s16 n;
    s32 c;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    n = p->unk2;
    f = n;
    if (f >= 8) {
        f = 7;
    }
    func_800D4368(&p->unk4, (s16)(n * 0xC0 + 0x2000), 0);
    frame = &D_801D2198;
    *frame = f;
    c = 0x60 - p->unk2 * 4;
    D_801D2194 = D_801D2195 = D_801D2196 = c;
    D_801EA20C = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EA20C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 24) {
            p->unk0 = -1;
        }
    }
}

void func_801B02B8(void) {
    MgMat lw;
    MgMat m;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    u8 *rgb;
    s16 i;
    s16 n;
    s16 s;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[2][i] = 0;
        m.m[1][i] = 0;
        m.m[0][i] = 0;
    }
    n = 8;
    if (p->unk2 >= 7) {
        n = 15 - p->unk2;
    }
    rot.vy = 0;
    rot.vx = 0;
    rot.vz = p->unk14;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    s = 0x2000;
    if (p->unk16 < 4) {
        s = 0x1400;
    }
    m.m[0][0] = m.m[1][1] = m.m[2][2] = s;
    func_8003C21C(&rot, &lw);
    func_8003B05C(&m, &lw);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801D21A4 = p->unk16;
    D_801D21A3 = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801D21A0;
    *rgb = D_801D21A1 = D_801D21A2 = n << 4;
    D_80163C74 = func_800D4D90(rgb - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (p->unk6 > 0) {
            p->unk6 = 0;
            p->unkE *= -1;
        }
        p->unkE += 20;
        p->unk14 += 0x200;
        p->unk2++;
        if (p->unk2 == 15) {
            p->unk0 = -1;
        }
    }
}

void func_801B04E8(void) {
    MgMat lw;
    MgMat m;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    u8 *rgb;
    s16 i;
    s32 c;

    p = &D_801621F0[D_801590D4];
    for (i = 0; i < 3; i++) {
        m.m[2][i] = 0;
        m.m[1][i] = 0;
        m.m[0][i] = 0;
    }
    rot.vz = p->unk14 + 0x400;
    rot.vx = 0;
    rot.vy = p->unk16;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x6000;
    func_8003B05C(&m, &D_800FA63C);
    func_8003C21C(&rot, &lw);
    func_8003B05C(&m, &lw);
    func_8003B48C(&m);
    func_8003B51C(&m);
    rgb = &D_801D21AC;
    c = -0x80 - p->unk2 * 16;
    *rgb = D_801D21AD = D_801D21AE = c;
    D_80163C74 = func_800D4D90(rgb - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B06A8(void) {
    MgMat m10;
    MgMat m30;
    MgMat m50;
    MgSVec v;
    MgVec sc;
    MgTask *p;
    u8 *rgb;
    s16 d;
    s32 c;
    s32 e;

    p = (MgTask *)&D_80162978[D_8015169C];
    v.vx = p->unkC - D_801EA210.vx;
    v.vy = p->unkE - D_801EA210.vy;
    v.vz = p->unk10 - D_801EA210.vz;
    d = func_80039F5C(v.vx * v.vx + v.vy * v.vy + v.vz * v.vz);
    func_800D44E8(&v, &m10);
    func_8003BF8C(&D_801D21C0, &m30);
    func_8003A79C(&m10, &m30, &m30);
    sc.vy = sc.vz = 0x2000;
    sc.vx = (d << 12) / 2000;
    func_8003B35C(&m30, &sc);
    m30.t[0] = D_801EA210.vx;
    m30.t[1] = D_801EA210.vy;
    m30.t[2] = D_801EA210.vz;
    func_8003A63C(&D_800FA63C, &m30, &m50);
    func_8003B48C(&m50);
    func_8003B51C(&m50);
    rgb = &D_801D21B8;
    c = (-0x80) - (p->unk2 << 5);
    rgb[0] = rgb[1] = rgb[2] = c;
    D_801D21BC = p->unk16;
    D_80163C74 = func_800D4D90(&D_801D21B8[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    v.vx = p->unkC - D_801EA210.vx;
    v.vy = 0;
    v.vz = p->unk10 - D_801EA210.vz;
    func_800D44E8(&v, &m10);
    func_8003C21C(&D_801D21C8, &m30);
    func_8003A79C(&m10, &m30, &m30);
    e = 0x1000 - p->unk2 * 512;
    sc.vx = sc.vy = sc.vz = e;
    func_8003B35C(&m30, &sc);
    m30.t[0] = p->unkC;
    m30.t[1] = 0;
    m30.t[2] = p->unk10;
    func_8003A63C(&D_800FA63C, &m30, &m50);
    func_8003B48C(&m50);
    func_8003B51C(&m50);
    D_801D21DA[0] = 0x60 - p->unk2 * 0x18;
    D_801EA20C = (u8 *)func_800D29D4(&D_801D21DA[-5], D_801517C0 + 0x70, 0xC, (s32)D_801EA20C);
    if (D_80062D98 == 0) {
        if (++p->unk2 == 4) {
            p->unk0 = -1;
        }
    }
}

void func_801B09F4(void) {
    MgSVec rot;
    MgMat lw;
    MgMat m;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vx = 0;
    rot.vy = p->unk2 << 6;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    D_801D21FC.vx = D_801D2204[0] = (p->unk2 << 8) + 0x3000;
    D_801D2200 = (p->unk2 << 8) + 0x2000;
    func_8003B35C(&m, &D_801D21FC);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D21EA[0] = 0x80 - p->unk2 * 4;
    D_801EA20C = (u8 *)func_800D29D4(&D_801D21EA[-5], D_801517C0 + 0x70, 0xC, (s32)D_801EA20C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 30) {
            p->unk0 = -1;
        }
    }
}

void func_801B0B50(void) {
    MgTask *p;
    MgTask *q;
    s16 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B06A8)];
        q->unkC = p->unk4;
        q->unk10 = p->unk8;
        q->unkE = 0;
        q->unk16 = p->unk2 % 4 + 3;
        p->unk4 += p->unkC;
        p->unk8 += p->unk10;
        if (!(p->unk2 & 1)) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B02B8)];
            q->unk4 = p->unk4;
            q->unk8 = p->unk8;
            q->unk6 = 0;
            a = func_80042DA8() % 0x1000;
            q->unkC = (u32)(func_80039B40(a) * 25) >> 10;
            q->unk10 = (u32)(func_80039A74(a) * 25) >> 10;
            q->unkE = -func_80042DA8() % 200 - 100;
            q->unk16 = func_80042DA8() % 16 + 4;
        }
        if (++p->unk2 == 0xE) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B0D44);

void func_801B13B8(arg0, arg1) {
    MgObjAwa *q;

    q = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B0D44)];
    func_800D3994(arg1, D_8015190F[arg1][9], &D_801EA210);
    func_800D3994(arg0, D_8015190F[arg0][0], &q->unkC);
    q->unk1C = arg0;
}

s32 func_801B147C(arg0, arg1) {
    func_800BBEAC(func_801B0020);
    func_800D2980(&D_801B151C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B13B8);
    func_800BBA84(0x119, arg1, 0);
    D_800F5B70 = D_800F5B71 = D_800F5B72 = 0;
    return func_800D52A0(0xC00, 0xA);
}
