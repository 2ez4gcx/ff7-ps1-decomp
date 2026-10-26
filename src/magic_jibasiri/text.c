#include "common.h"
#include "magic_jibasiri/decls.h"

void func_801B0000(void) {
    func_801B1094();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D98F0 = D_801C18F0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801C1888.unk0 = D_801C1894[p->unk16];
    D_801C1888.unk8 = p->unk2;
    D_80163C74 = func_800D4D90(&D_801C1888, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801C1894[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0180(void) {
    MgSVec rot;
    MgMat lw;
    MgMat m;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vx = 0;
    rot.vy = p->unk2 << 6;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    D_801C18E0.vx = D_801C18E8[0] = (p->unk2 << 8) + 0x3000;
    D_801C18E4 = (p->unk2 << 8) + 0x2000;
    func_8003B35C(&m, &D_801C18E0);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801C18A6[0] = 0x80 - p->unk2 * 4;
    D_801D98F0 = (u8 *)func_800D29D4(&D_801C18A6[-5], D_801517C0 + 0x70, 0xC, (s32)D_801D98F0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 30) {
            p->unk0 = -1;
        }
    }
}

void func_801B02DC(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801C18B4;
    *frame = p->unk2;
    D_801D98F0 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D98F0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801C17C4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0394(void) {
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
    D_801C18C0 = p->unk16;
    D_801C18BF = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801C18BC;
    *rgb = D_801C18BD = D_801C18BE = n << 4;
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

void func_801B05C4(void) {
    MgMat a;
    MgMat b;
    MgMat c;
    MgSVec v;
    MgVec s;
    MgTask *p;
    u16 *frame;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];

    v.vx = p->unkC - *(u16 *)D_801D98F4;
    v.vy = 0;
    v.vz = p->unk10 - D_801D98F8;
    func_800D44E8(&v, &a);
    func_8003C21C(&D_801C18C4, &b);
    func_8003A79C(&a, &b, &b);
    t = p->unk16 * 0x180 + 0xE00;
    s.vz = t;
    s.vy = t;
    s.vx = t;
    func_8003B35C(&b, &s);

    b.t[0] = p->unkC;
    b.t[1] = 0;
    b.t[2] = p->unk10;
    func_8003A63C(&D_800FA63C, &b, &c);
    func_8003B48C(&c);
    func_8003B51C(&c);
    frame = (u16 *)&D_801C18D6;
    *frame = 0x60 - p->unk2 * 0x18;
    D_801D98F0 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801D98F0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0748(void) {
    MgTask *p;
    MgTask *q;
    s16 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B05C4)];
        q->unkC = p->unk4;
        q->unk10 = p->unk8;
        q->unkE = 0;
        q->unk16 = p->unk2;
        p->unk4 += p->unkC;
        p->unk8 += p->unk10;
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0394)];
        q->unk4 = p->unk4;
        q->unk8 = p->unk8;
        q->unk6 = 0;
        a = func_80042DA8() % 0x1000;
        q->unkC = (u32)(func_80039B40(a) * 25) >> 10;
        q->unk10 = (u32)(func_80039A74(a) * 25) >> 10;
        q->unkE = -func_80042DA8() % 200 - 0x64;
        q->unk16 = func_80042DA8() % 16 + 4;
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B02DC)];
        q->unk4 = p->unk4 + func_80042DA8() % 600 - 0x12C;
        q->unk8 = p->unk8 + func_80042DA8() % 600 - 0x12C;
        q->unk6 = 0;
        p->unk2++;
        if (p->unk2 == 0xC) {
            p->unk0 = -1;
        }
    }
}

void func_801B09B0(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 a;
    u8 pad[48];
    u16 *r;
    MgSVec *t;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(D_801C18DC, 0, 0);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x10) {
            D_801C18DC += 4;
        }
        if (p->unk2 >= 0xF) {
            D_801C18DC -= 4;
        }
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0748)];
            t = (MgSVec *)D_801D98F4;
            *(u16 *)&q->unk4 = t->vx;
            *(u16 *)&q->unk6 = 0;
            *(u16 *)&q->unk8 = D_801D98F8;
            q->unkC = (p->unkC - t->vx) / 10;
            q->unk10 = (p->unk10 - *(s16 *)&D_801D98F8) / 10;
            q->unkE = 0;
            D_8009A000.a = 0x28;
            D_8009A000.b = 0x40;
            D_8009A000.c = 0x173;
            func_8002DA7C();
        }
        if (p->unk2 == 0xA) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0394)];
                q->unk4 = p->unkC + func_80042DA8() % 400 - 0xC8;
                q->unk8 = p->unk10 + func_80042DA8() % 400 - 0xC8;
                q->unk6 = 0;
                a = func_80042DA8() % 0x1000;
                q->unkC = (u32)(func_80039B40(a) * 25) >> 10;
                q->unk10 = (u32)(func_80039A74(a) * 25) >> 10;
                q->unkE = -func_80042DA8() % 200 - 0x64;
                i++;
                q->unk16 = func_80042DA8() % 20;
            } while (i < 8);
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0180)];
            q->unk4 = p->unkC;
            q->unk6 = 0;
            q->unk8 = p->unk10;
            D_8009A000.a = 0x29;
            D_8009A000.b = 0x40;
            D_8009A000.c = 0xFA;
            func_8002DA7C();
        }
        if ((u16)p->unk2 - 7 < 7U) {
            q = &D_801621F0[func_800BC04C(func_801B008C)];
            q->unk4 = p->unkC + func_80042DA8() % 1200 - 0x258;
            q->unk6 = p->unkE + func_80042DA8() % 1200 - 0x258;
            q->unk8 = p->unk10 + func_80042DA8() % 1200 - 0x258;
            q->unk16 = 0;
            q = &D_801621F0[func_800BC04C(func_801B008C)];
            q->unk4 = p->unkC + func_80042DA8() % 1600 - 0x320;
            q->unk6 = p->unkE + func_80042DA8() % 1600 - 0x320;
            q->unk8 = p->unk10 + func_80042DA8() % 1600 - 0x320;
            q->unk16 = 1;
            r = &D_801031EA;
            *r = (u16)(*r + 0x20) - p->unk2 % 2 * 64;
        }
        if (p->unk2 == 0xC) {
            func_800D5774(p->unk1C);
        }
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0FD0(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B09B0)];
    func_800D3994(arg1, D_8015190F[arg1][0], D_801D98F4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B1094(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B1100, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0FD0);
}
