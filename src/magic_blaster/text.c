#include "common.h"
#include "magic_blaster/decls.h"

void func_801B0000(void) {
    func_801B19DC();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E9A0C = D_801D9A0C + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0080(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk16 == 0 ? 0x4000 : 0x5000, 0);
    frame = &D_801D98A8;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801D98AC[p->unk16];
    D_801E9A0C = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_801E9A0C);
    if (D_80062D98 == 0) {
        if (p->unk16 == 0) {
            p->unk4 += p->unkC;
            p->unk8 += p->unk10;
            p->unk6 -= 0x64;
        }
        p->unk2++;
        if (p->unk2 >= D_801D98AC[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B01C0(void) {
    MgMat lw;
    MgMat m;
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801D98B8, &m);
    t = 0x4000 - p->unk2 * 0x320;
    D_801D99C0.vx = D_801D99C4 = D_801D99C8 = t;
    func_8003B35C(&m, &D_801D99C0);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D98CA[0] = p->unk2 * 6;
    D_801E9A0C = func_800D29D4(&D_801D98CA[-5], D_801517C0 + 0x70, 0xC, D_801E9A0C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B030C(void) {
    MgMat lw;
    MgMat m;
    MgSVec rot;
    MgTask *p;
    u8 *q;
    s32 t;
    s32 t2;

    rot.vz = rot.vy = rot.vx = 0;
    p = &D_80162978[D_8015169C];
    func_8003C21C(&rot, &m);
    D_801D99D0.vx = D_801D99D4 = D_801D99D8 = p->unk18;
    func_8003B35C(&m, &D_801D99D0);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    t = D_801D98D0;
    D_801D98DE[0] = 0x1000 - (t << 9);
    *(u8 **)&D_801D98DE[-5] = D_801D2070;
    func_8003B69C(0, 0, 0);
    q = (u8 *)D_801D98DE - 0xA;
    D_801E9A0C = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801E9A0C);
    rot.vx = p->unk2 << 8;
    rot.vy = p->unk2 << 9;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    D_801D99D0.vx = D_801D99D4 = D_801D99D8 = p->unk18;
    func_8003B35C(&m, &D_801D99D0);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    *(u8 **)&D_801D98DE[-5] = D_801D2814;
    D_801E9A0C = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801E9A0C);
    func_800D4368(&p->unk4, 0x2000, 0);
    t2 = D_801D98D0;
    D_801D98E8[0] = D_801D98E8[1] = D_801D98E8[2] = t2 * 0x10;
    D_801D98EC = p->unk2 % 2;
    D_801E9A0C = func_800D4D90(D_801D98E8 - 4, D_801517C0 + 0x70, 0xC, D_801E9A0C);
    if (D_80062D98 == 0) {
        if (p->unk2 < 9) {
            D_801D98D0 += 1;
        }
        if (p->unk2 >= 0x17) {
            D_801D98D0 -= 1;
            p->unk18 -= 0x514;
        } else {
            p->unk18 += 0x1F4;
        }
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0654(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 2) {
            func_800D4368(&p->unk4, 0x2000, 0);
            func_8003B69C(0, 0, 0);
            D_801D98F0[0] = D_801D90E0;
            D_801E9A0C = func_800D29D4(D_801D98F0, D_801517C0 + 0x70, 0xC, D_801E9A0C);
            D_801D98F0[0] = D_801D90E0;
            D_801E9A0C = func_800D29D4(D_801D98F0, D_801517C0 + 0x70, 0xC, D_801E9A0C);
        }
        if (p->unk2 == 3) {
            D_80163C74 = func_800C4FC8(0x80, 0x80, 0x80);
            p->unk0 = -1;
        }
        p->unk2 = (u16)p->unk2 + 1;
    }
}

void func_801B0778(void) {
    MgMat m;
    MgMat lw;
    MgVec sc;
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (p->unk2 >= 2) {
        func_8003C21C(&D_801D9900, &m);
        func_8003A79C(&D_801D99EC, &m, &m);
        t = 0x2000 - p->unk2 * 0x320;
        sc.vx = sc.vy = sc.vz = t;
        func_8003B35C(&m, &sc);
        m.t[0] = p->unk4;
        m.t[1] = p->unk6;
        m.t[2] = p->unk8;
        func_8003A63C(&D_800FA63C, &m, &lw);
        func_8003B48C(&lw);
        func_8003B51C(&lw);
        func_8003B69C(0, 0, 0);
        D_801D9912[0] = p->unk2 * 0x190;
        D_801E9A0C = func_800D29D4(&D_801D9912[-5], D_801517C0 + 0x70, 0xC, D_801E9A0C);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B08FC(void) {
    MgMat m;
    MgMat lw;
    MgVec sc;
    MgTask *p;
    s32 n;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    k = p->unk2;
    if (k >= 7) {
        k = 6;
    }
    func_8003C21C(&D_801D992C, &m);
    n = k;
    k = 0;
    func_8003A79C(&D_801D99EC, &m, &m);
    sc.vx = sc.vz = 0x4000 - (n << 10);
    sc.vy = p->unk18 * n / 6;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    t = D_801D9918;
    D_801D9926[0] = 0x1000 - (t << 7);
    D_801E9A0C = func_800D29D4(&D_801D9926[-5], D_801517C0 + 0x70, 0xC, D_801E9A0C);
    func_8003C21C(&D_801D992C, &m);
    func_8003A79C(&D_801D99EC, &m, &m);
    sc.vx = sc.vz = 0x2000 - (n << 9);
    sc.vy = p->unk18 * n / 6;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801E9A0C = func_800D29D4(&D_801D9926[-5], D_801517C0 + 0x70, 0xC, D_801E9A0C);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 7) {
            D_801D9918 -= 2;
        }
        p->unk2++;
        if (p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B0BC4(void) {
    MgMat m;
    MgMat lw;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s32 n;
    s32 t;
    s32 t2;
    u8 *fq;

    p = &D_80162978[D_8015169C];
    n = p->unk2;
    if (n >= 7) {
        n = 6;
    }
    D_801D99E0.vx = 0;
    D_801D99E0.vy = 0;
    D_801D99E0.vz = p->unk18 * n / 6;
    D_801D99EC.t[0] = p->unk4;
    D_801D99EC.t[1] = p->unk6;
    D_801D99EC.t[2] = p->unk8;
    func_8003B48C(&D_801D99EC);
    func_8003B51C(&D_801D99EC);
    func_8003BADC(&D_801D99E0, &D_801D99E0, &flag);
    func_8003C21C(&D_801D9964, &m);
    func_8003A79C(&D_801D99EC, &m, &m);
    func_8003B35C(&m, &D_801D9938);
    m.t[0] = D_801D99E0.vx;
    m.t[1] = D_801D99E0.vy;
    m.t[2] = D_801D99E0.vz;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    t = D_801D9934;
    D_801D9952[0] = 0x1000 - (t << 9);
    func_8003B69C(0, 0, 0);
    fq = (u8 *)D_801D9952 - 0xA;
    *(u8 **)&D_801D9952[-5] = D_801D2FB8;
    D_801E9A0C = func_800D29D4(fq, D_801517C0 + 0x70, 0xC, D_801E9A0C);
    *(u8 **)&D_801D9952[-5] = D_801D3F5C;
    D_801E9A0C = func_800D29D4(fq, D_801517C0 + 0x70, 0xC, D_801E9A0C);
    *(u8 **)&D_801D9952[-5] = D_801D4F00;
    D_801E9A0C = func_800D29D4(fq, D_801517C0 + 0x70, 0xC, D_801E9A0C);
    func_800D4368(&D_801D99E0, 0x3000, 0);
    t2 = D_801D9934;
    D_801D995C[0] = D_801D995C[1] = D_801D995C[2] = t2 * 0x14;
    D_801D9960 = p->unk2 % 2;
    D_801E9A0C = func_800D4D90(D_801D995C - 4, D_801517C0 + 0x70, 0xC, D_801E9A0C);
    if (D_80062D98 == 0) {
        if (p->unk2 < 5) {
            q = &D_80162978[func_800BBEAC(func_801B0778)];
            q->unk4 = D_801D99E0.vx;
            q->unk6 = D_801D99E0.vy;
            q->unk8 = D_801D99E0.vz;
        }
        if (p->unk2 >= 7) {
            D_801D9934 -= 2;
        }
        p->unk2++;
        if (p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B0F50(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    MgVec sc;
    MgTask *p;
    s16 k;

    rot.vx = rot.vy = rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003C21C(&rot, &m);
    sc.vx = sc.vy = sc.vz = func_80039A74(p->unk2 * 0x33) * 0x3000 >> 12;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801D996C[0] = D_801D52A8;
    D_801E9A0C = func_800D29D4(D_801D996C, D_801517C0 + 0x70, 0xC, D_801E9A0C);
    k = p->unk2 % 8;
    D_801D996C[0] = D_801D997C[k];
    D_801E9A0C = func_800D29D4(D_801D996C, D_801517C0 + 0x70, 0xC, D_801E9A0C);
    func_800D4368(&p->unk4, 0x3000, 0);
    D_801D99A4[0] = p->unk2 % 2;
    D_801E9A0C = func_800D4D90((u8 *)D_801D99A4 - 8, D_801517C0 + 0x70, 0xC, D_801E9A0C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B116C(void) {
    MgTask *p;
    MgMat m;
    MgMat lw;
    MgVec scale;
    s32 t;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801D99A8, &m);
    func_8003A79C(&D_801D99EC, &m, &m);
    scale.vx = scale.vy = scale.vz = p->unk2 * 1500;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801D99BA[0] = t << 8;
    D_801E9A0C = func_800D29D4(&D_801D99BA[-5], D_801517C0 + 0x70, 0xC, D_801E9A0C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B12C8(void) {
    MgSVec v;
    u16 w[4];
    u8 pad[8];
    u16 t;
    s32 r1;
    s32 r2;
    s32 r3;
    s32 k1;
    s32 k2;
    s32 k3;
    MgTask *p;
    MgTask *q;
    s16 d;
    s16 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((u16)p->unk2 < 0xB && (p->unk2 & 3) == 0) {
            q = &D_80162978[func_800BBEAC(func_801B01C0)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
        }
        if (p->unk2 == 0) {
            q = &D_80162978[func_800BBEAC(func_801B030C)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk18 = 0;
        }
        if (p->unk2 == 0x1E) {
            q = &D_80162978[func_800BBEAC(func_801B08FC)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            v.vx = p->unkC - q->unk4;
            v.vy = p->unkE - q->unk6;
            v.vz = p->unk10 - q->unk8;
            d = func_80039F5C(v.vx * v.vx + v.vy * v.vy + v.vz * v.vz);
            q->unk18 = d * 0x1200 / 3000;
            q->unk1A = 0;
            q = &D_80162978[func_800BBEAC(func_801B0BC4)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk18 = d;
            q->unk1A = 0;
            q = &D_80162978[func_800BBEAC(func_801B116C)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            D_80163C74 = func_800C4FC8(0x80, 0x80, 0x80);
        }
        if (p->unk2 == 0x24) {
            q = &D_80162978[func_800BBEAC(func_801B0F50)];
            q->unk4 = p->unkC;
            q->unk6 = p->unkE;
            q->unk8 = p->unk10;
            D_800F5B71.v = 0;
            D_800F5B72.v = 0;
            D_800F5B70.v = 0x20;
            func_800D52A0(0x1000, 0xA);
        }
        if ((u32)((u16)p->unk2 - 0x33) < 0xF) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(func_801B0080)];
                t = p->unk2;
                D_801D99E8 = t << 9;
                w[0] = (u32)(((s32 (*)(s16))func_80039A74)(t << 9) * 0x19) >> 7;
                w[2] = (u32)(func_80039B40(D_801D99E8) * 0x19) >> 7;
                q->unk4 = p->unkC + w[0];
                q->unk6 = p->unkE + func_80042DA8() % 800;
                q->unk8 = p->unk10 + w[2];
                q->unkC = (s16)w[0] >> 2;
                i++;
                q->unk10 = (s16)w[2] >> 2;
                q->unk16 = 0;
            } while (i < 2);
        }
        if (p->unk2 == 0x43) {
            q = &D_80162978[func_800BBEAC(func_801B0654)];
            q->unk4 = p->unkC;
            q->unk6 = p->unkE;
            q->unk8 = p->unk10;
        }
        if (p->unk2 == 0x48) {
            func_800D5774(p->unk1C);
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(func_801B0080)];
                q->unk4 = p->unkC;
                q->unk6 = p->unkE;
                q->unk8 = p->unk10;
                r1 = func_80042DA8();
                k1 = (u16)q->unk4 - 0x258;
                q->unk4 = k1 + r1 % 1200;
                r2 = func_80042DA8();
                k2 = (u16)q->unk6 - 0x258;
                q->unk6 = k2 + r2 % 1200;
                r3 = func_80042DA8();
                i++;
                q->unk16 = 1;
                k3 = (u16)q->unk8 - 0x258;
                q->unk8 = k3 + r3 % 1200;
            } while (i < 4);
            func_800BBA84(0xFA, p->unk1C, 0x40);
        }
        p->unk2++;
        if (p->unk2 == 0x50) {
            func_800D52A0(0, 0xA);
            p->unk0 = -1;
        }
    }
}

void func_801B18D8(arg0, arg1) {
    MgSVec v;
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B12C8)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    v.vx = (u16)p->unkC - (u16)p->unk4;
    v.vy = (u16)p->unkE - (u16)p->unk6;
    v.vz = (u16)p->unk10 - (u16)p->unk8;
    func_800D44E8(&v, &D_801D99EC);
    p->unk1C = arg0;
}

s32 func_801B19DC(arg0, arg1) {
    func_800BBEAC(func_801B0020);
    func_800D2980(&D_801B1A58, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B18D8);
    return func_800BBA84(0x78, arg1, 0x40);
}
