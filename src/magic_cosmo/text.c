#include "common.h"
#include "magic_cosmo/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B1B54();
    return &D_801DBBBC;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801F4A44 = D_801DCA44 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0094(void) {
    MgObj20 *p;
    s16 n;

    p = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(D_801DC89C, D_801DC89E, D_801DC8A0);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x18) {
            D_801DC89E -= 0xA;
            D_801DC8A0 -= 0xA;
        }
        D_801DC89C -= 4;
        n = ++p->unk2;
        if (n == 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0174(void) {
    MgTask *p;

    p = (MgTask *)&D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x4000, 0);
    D_801DC8AC[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801DC8AC[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801DBAF8) {
            p->unk0 = -1;
        }
    }
}

void func_801B0230(void) {
    MgTask *p;
    u8 c;

    p = (MgTask *)&D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801DC8B8[0] = p->unk2 != 0;
    c = -0x80 - p->unk2 * 0x10;
    D_801DC8B4 = D_801DC8B5 = D_801DC8B6 = c;
    D_80163C74 = func_800D4D90(&D_801DC8B8[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B0310(void) {
    MgMat m;
    MgMat lw;
    MgVec sc;
    MgSVec rot;
    MgTask *p;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = 0x2000;
    if (p->unk16 < 2) {
        k = 0x800;
    }
    sc.vx = sc.vy = sc.vz = k;
    rot.vy = 0;
    rot.vx = 0;
    rot.vz = p->unk14;
    func_8003BF8C(&rot, &m);
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801DC8BC[0] = D_801DC8CC[p->unk16];
    D_801F4A44 = func_800D29D4(D_801DC8BC, D_801517C0 + 0x70, 0xC, D_801F4A44);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x190;
        p->unk14 += 0x100;
        p->unk2++;
        if (p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B0470(void) {
    MgMat m;
    MgMat lw;
    MgVec sc;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801DC8DC, &m);
    func_8003A79C(D_801DCA18, &m, &m);
    sc.vx = sc.vy = sc.vz = p->unk2 * 0x5DC;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801DC8EE[0] = p->unk2 * 0x100;
    D_801F4A44 = func_800D29D4(&D_801DC8EE[-5], D_801517C0 + 0x70, 0xC, D_801F4A44);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B05CC(void) {
    MgMat m;
    MgMat lw;
    MgVec sc;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801DC8F4, &m);
    sc.vx = sc.vy = sc.vz = p->unk2 * 0x7D0;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801DC906[0] = p->unk2 * 0x100;
    D_801F4A44 = func_800D29D4(&D_801DC906[-5], D_801517C0 + 0x70, 0xC, D_801F4A44);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B070C(void) {
    MgMat m;
    MgMat lw;
    MgVec sc;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801DC920, &m);
    func_8003A79C(D_801DCA18, &m, &m);
    sc.vx = sc.vz = 0x5000 - p->unk2 * 0x258;
    sc.vy = 0x4000;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801DC91A[0] = 0x1000 - D_801DC90C * 0x100;
    M2C_SFIELD(&D_801DC91A[-5], s32 *, 0) = (s32)D_801D49A8;
    D_801F4A44 = func_800D29D4(&D_801DC91A[-5], D_801517C0 + 0x70, 0xC, D_801F4A44);
    *(s32 *)&D_801DC91A[-5] = (s32)D_801DC928[p->unk2 % 8];
    D_801F4A44 = func_800D29D4(&D_801DC91A[-5], D_801517C0 + 0x70, 0xC, D_801F4A44);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x16) {
            D_801DC90C -= 1;
        }
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0918(void) {
    MgMat m;
    MgMat lw;
    MgVec sc;
    MgTask *p;
    MgTask *q;
    s16 k;
    s16 a;
    s16 i;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801DC958, &m);
    sc.vx = sc.vz = p->unk2 * 0x190 + 0x1000;
    sc.vy = 0x7F00;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801DC952[0] = p->unk2 * 0x44;
    M2C_SFIELD(&D_801DC952[-5], s32 *, 0) = (s32)D_801DC960[p->unk2 % 8];
    D_801F4A44 = func_800D29D4(&D_801DC952[-5], D_801517C0 + 0x70, 0xC, D_801F4A44);
    *(s32 *)&D_801DC952[-5] = (s32)D_801DB868;
    D_801F4A44 = func_800D29D4(&D_801DC952[-5], D_801517C0 + 0x70, 0xC, D_801F4A44);
    if (D_80062D98 == 0) {
        k = p->unk2 * 0x46 + 0x190;
        if (p->unk2 < 0x32) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0310)];
            a = func_80042DA8() % 0x1000;
            q->unk4 = p->unk4 + (func_80039A74(a) * k >> 12);
            q->unk8 = p->unk8 + (func_80039B40(a) * k >> 12);
            q->unk6 = 0;
            q->unk16 = func_80042DA8() % 4;
            q->unk14 = func_80042DA8() % 0x1000;
        }
        i = 0;
        do {
            q = (MgTask *)&D_801621F0[func_800BC04C(func_801B0174)];
            a = func_80042DA8() % 0x1000;
            q->unk4 = p->unk4 + (func_80039A74(a) * k >> 12);
            q->unk8 = p->unk8 + (func_80039B40(a) * k >> 12);
            q->unk6 = 0;
            i++;
        } while (i < 4);
        t = D_801031EA[0] + 0x40;
        t -= p->unk2 % 2 * 0x80;
        D_801031EA[0] = t;
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0CDC(void) {
    MgMat b;
    MgMat a;
    MgMat lw;
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D44E8(&p->unkC, &a);
    func_8003C21C(&D_801DC9A0, &b);
    func_8003A79C(&a, &b, &b);
    func_8003B35C(&b, &D_801DC990);
    b.t[0] = p->unk4;
    b.t[1] = p->unk6;
    b.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &b, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801F4A44 = func_800D29D4(D_801DC980, D_801517C0 + 0x70, 0xC, D_801F4A44);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 == 9) {
            q = (MgTask *)&D_801621F0[func_800BC04C(func_801B0230)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            p->unk0 = -1;
        }
    }
}

void func_801B0E80(void) {
    MgMat m;
    MgMat lw;
    MgVec sc;
    MgSVec v;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    sc.vx = sc.vy = sc.vz = D_801DC9CC;
    func_8003C21C(&D_801DC9C4, &m);
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801DC9A8[0] = D_801D239C;
    D_801F4A44 = func_800D29D4(D_801DC9A8, D_801517C0 + 0x70, 0xC, D_801F4A44);
    D_801DC9A8[0] = D_801D3440;
    D_801F4A44 = func_800D29D4(D_801DC9A8, D_801517C0 + 0x70, 0xC, D_801F4A44);
    func_800D4368(&p->unk4, D_801DC9CC, 0);
    D_801DC9C0[0] = p->unk2 % 2;
    D_801F4A44 = func_800D4D90(&D_801DC9C0[-4], D_801517C0 + 0x70, 0xC, D_801F4A44);
    if (D_80062D98 == 0) {
        if ((u16)(p->unk2 - 0x14) < 0x5AU) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0CDC)];
            v.vx = 0;
            v.vy = 0;
            v.vz = 0xFA0;
            rot.vx = func_80042DA8() % 0x1000;
            rot.vy = func_80042DA8() % 0x1000;
            rot.vz = 0;
            func_8003C21C(&rot, &m);
            m.t[0] = m.t[1] = m.t[2] = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&v, &v, &flag);
            q->unk4 = p->unk4 + v.vx;
            q->unk6 = p->unk6 + v.vy;
            q->unk8 = p->unk8 + v.vz;
            q->unkC = -v.vx / 10;
            q->unkE = -v.vy / 10;
            q->unk10 = -v.vz / 10;
        }
        if (p->unk2 < 0x78) {
            D_801DC9CC += 0x40;
        } else {
            D_801DC9CC -= 0x100;
        }
        p->unk2++;
        if (p->unk2 == 0x96) {
            p->unk0 = -1;
        }
    }
}

void func_801B11F4(void) {
    MgMat m;
    u8 pad[0x20];
    MgVec sc;
    MgSVec v;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    s16 i;
    s16 j;
    s16 t;
    s32 a;

    sc.vx = sc.vy = sc.vz = D_801DC9DC;
    p = (MgTask *)&D_80162978[D_8015169C];
    i = 0;
    t = p->unk2 * 0x80;
    do {
        j = 0;
        do {
            a = j * 0x100 + t;
            v.vx = (u32)(func_80039B40(a) * 0x4B) >> 9;
            v.vy = (u32)(func_80039A74(a) * 0x4B) >> 9;
            v.vz = 0;
            rot.vx = p->unk2 * 0x40;
            rot.vy = i * 0x555;
            rot.vz = 0;
            func_8003BF8C(&rot, &m);
            func_8003B35C(&m, &sc);
            m.t[0] = p->unk4;
            m.t[1] = p->unk6;
            m.t[2] = p->unk8;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&v, &v, &flag);
            func_800D4368(&v, 0x1000, 0);
            D_801F4A44 = (u8 *)func_800D4D90(D_801DC9D0, D_801517C0 + 0x70, 0xC, (s32)D_801F4A44);
            j++;
        } while (j < 0x10);
        i++;
    } while (i < 3);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x28) {
            D_801DC9DC += 0x80;
        } else {
            D_801DC9DC -= 0x48;
        }
        p->unk2++;
        if (p->unk2 == 0x78) {
            p->unk0 = -1;
        }
    }
}

void func_801B1440(void) {
    MgMat m2;
    MgMat m;
    MgMat lw;
    MgVec sc;
    MgSVec v;
    u8 pad[8];
    MgSVec rot;
    s32 flag;
    MgTask *p;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B69C(0, 0, 0);
    D_801DC9EA = 0x1000 - D_801DCA14 * 0x100;
    i = 0;
    do {
        sc.vx = sc.vy = sc.vz = 0x1000 - p->unk2 * 0x28;
        v.vx = 0;
        v.vy = 0;
        v.vz = (i - 1) * 0x320;
        rot.vz = 0;
        rot.vy = p->unk2 * 0x10 + 0x400;
        rot.vx = p->unk2 * 0x10;
        func_8003C21C(&rot, &m);
        func_8003B35C(&m, &sc);
        m.t[0] = p->unk4;
        m.t[1] = p->unk6;
        m.t[2] = p->unk8;
        func_8003B48C(&m);
        func_8003B51C(&m);
        func_8003BADC(&v, &v, &flag);
        D_801DC9FE[0] = p->unk2 * (i * 0x10 + 0x30);
        func_8003BF8C((MgSVec *)&D_801DC9FE[-1], &m2);
        rot.vz = 0;
        rot.vy = p->unk2 * 0x10 + 0x400;
        rot.vx = p->unk2 * 0x10;
        func_8003C21C(&rot, &m);
        func_8003A79C(&m, &m2, &m);
        sc.vx = sc.vy = sc.vz = 0x7F00 - p->unk2 * 0x10E;
        func_8003B35C(&m, &sc);
        if (i != 1) {
            func_8003B35C(&m, &D_801DCA04);
        }
        m.t[0] = v.vx;
        m.t[1] = v.vy;
        m.t[2] = v.vz;
        func_8003A63C(&D_800FA63C, &m, &lw);
        func_8003B48C(&lw);
        func_8003B51C(&lw);
        D_801F4A44 = func_800D29D4(D_801DC9E0, D_801517C0 + 0x70, 0xC, D_801F4A44);
        i++;
    } while (i < 3);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x10) {
            D_801DCA14 += 1;
        }
        p->unk2++;
        if (p->unk2 == 0x78) {
            p->unk0 = -1;
        }
    }
}

void func_801B174C(void) {
    u8 pad[0x30];
    MgTask *p;
    MgTask *q;
    s16 t;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t == 0x14) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1440)];
            *(s16 *)((u8 *)q + 4) = p->unk4;
            *(s16 *)((u8 *)q + 6) = p->unk6;
            *(s16 *)((u8 *)q + 8) = p->unk8;
            if (p->unk2 == t) {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0E80)];
                *(s16 *)((u8 *)q + 4) = p->unk4;
                *(s16 *)((u8 *)q + 6) = p->unk6;
                *(s16 *)((u8 *)q + 8) = p->unk8;
            }
        }
        if (p->unk2 == 0x32) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B11F4)];
            *(s16 *)((u8 *)q + 4) = p->unk4;
            *(s16 *)((u8 *)q + 6) = p->unk6;
            *(s16 *)((u8 *)q + 8) = p->unk8;
        }
        if (p->unk2 == 0x87) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0470)];
            *(s16 *)((u8 *)q + 4) = p->unk4;
            *(s16 *)((u8 *)q + 6) = p->unk6;
            *(s16 *)((u8 *)q + 8) = p->unk8;
        }
        if ((u16)(p->unk2 - 0xAA) < 0x1EU && p->unk2 % 5 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B05CC)];
            *(s16 *)((u8 *)q + 4) = D_801DCA3C[0];
            *(s16 *)((u8 *)q + 6) = D_801DCA3E;
            *(s16 *)((u8 *)q + 8) = D_801DCA40;
        }
        if (p->unk2 == 0x8C) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B070C)];
            *(s16 *)((u8 *)q + 4) = p->unk4;
            *(s16 *)((u8 *)q + 6) = p->unk6;
            *(s16 *)((u8 *)q + 8) = p->unk8;
            D_8009A000[0] = 0x28;
            D_8009A004 = func_800D56A8(&q->unk4);
            D_8009A008 = 0x182;
            func_8002DA7C();
        }
        t = p->unk2;
        if (t == 0xAA) {
            func_800BBEAC(func_801B0094);
            if (p->unk2 == t) {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0918)];
                *(s16 *)((u8 *)q + 4) = D_801DCA3C[0];
                *(s16 *)((u8 *)q + 6) = D_801DCA3E;
                *(s16 *)((u8 *)q + 8) = D_801DCA40;
                D_8009A000[0] = 0x28;
                D_8009A004 = func_800D56A8(&q->unk4);
                D_8009A008 = 0x20D;
                func_8002DA7C();
                D_8009A000[0] = 0x29;
                D_8009A004 = func_800D56A8(&q->unk4);
                D_8009A008 = 0x25A;
                func_8002DA7C();
            }
        }
        if (p->unk2 == 0xE6) {
            i = 0;
            do {
                if ((D_801DCA38 >> i) & 1) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 0xA);
        }
        p->unk2++;
        if (p->unk2 == 0xFA) {
            func_800D52A0(0, 0xC);
            D_800FAFDC = 0;
            p->unk0 = -1;
        }
    }
}

void func_801B1B54(arg0, arg1) {
    CoSVec v;
    MgTask *p;
    s16 *pos;

    func_800BBEAC(func_801B0028);
    D_801DCA38 = arg0;
    func_800D54EC(arg0, D_801DCA3C);
    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B174C)];
    pos = &p->unk4;
    func_800D3994(arg1, D_80151919[arg1][0], pos);
    p->unk6 -= 0x3E8;
    v.vx = D_801DCA3C[0] - p->unk4;
    v.vy = 0;
    v.vz = D_801DCA40 - p->unk8;
    func_800D44E8(&v, (MgMat *)D_801DCA18);
    p->unk1E = arg1;
    func_800D2980(&D_801B1D08, 0, 0, 0);
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    func_800D52A0(0x1000, 0x10);
    D_8009A000[0] = 0x28;
    D_8009A004 = func_800D56A8(pos);
    D_8009A008 = 0x128;
    func_8002DA7C();
    D_8009A000[0] = 0x29;
    D_8009A004 = func_800D56A8(pos);
    D_8009A008 = 0x1AA;
    func_8002DA7C();
    D_800FAFDC = 1;
}
