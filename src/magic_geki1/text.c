#include "common.h"
#include "magic_geki1/decls.h"

void func_801B0000(void) {
    func_801B0E5C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D54CC = D_801BD4CC + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801BD488.unk0 = D_801BD494[p->unk16];
    D_801BD488.unk8 = p->unk2;
    D_80163C74 = func_800D4D90(&D_801BD488, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801BD494[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0180(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801BD4A4;
    *frame = p->unk2;
    D_801D54CC = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D54CC);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801BD3C4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0238(void) {
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
    D_801BD4B0 = p->unk16;
    D_801BD4AF = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801BD4AC;
    *rgb = D_801BD4AD = D_801BD4AE = n << 4;
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

void func_801B0468(void) {
    MgMat a;
    MgMat b;
    MgMat c;
    MgSVec v;
    MgVec s;
    MgTask *p;
    u16 *frame;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];

    v.vx = p->unkC - *(u16 *)D_801D54D0;
    v.vy = 0;
    v.vz = p->unk10 - D_801D54D4;
    func_800D44E8(&v, &a);
    func_8003C21C(&D_801BD4B4, &b);
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
    frame = (u16 *)&D_801BD4C6;
    *frame = 0x60 - p->unk2 * 0x18;
    D_801D54CC = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801D54CC);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 4) {
            p->unk0 = -1;
        }
    }
}

void func_801B05EC(void) {
    MgTask *p;
    MgTask *q;
    s16 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0468)];
        q->unkC = p->unk4;
        q->unk10 = p->unk8;
        q->unkE = 0;
        q->unk16 = p->unk2;
        p->unk4 += p->unkC;
        p->unk8 += p->unk10;
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0238)];
        q->unk4 = p->unk4;
        q->unk8 = p->unk8;
        q->unk6 = 0;
        a = func_80042DA8() % 0x1000;
        q->unkC = (u32)(func_80039B40(a) * 25) >> 10;
        q->unk10 = (u32)(func_80039A74(a) * 25) >> 10;
        q->unkE = -func_80042DA8() % 200 - 100;
        q->unk16 = func_80042DA8() % 16 + 4;
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0180)];
        q->unk4 = p->unk4 + func_80042DA8() % 600 - 300;
        q->unk8 = p->unk8 + func_80042DA8() % 600 - 300;
        q->unk6 = 0;
        if (++p->unk2 == 0xC) {
            p->unk0 = -1;
        }
    }
}

void func_801B0854(void) {
    u8 pad[0x30];
    u16 *g;
    s32 t;
    s16 m;
    s32 n;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B05EC)];
            q->unk4 = ((MgSVec *)D_801D54D0)->vx;
            q->unk6 = 0;
            q->unk8 = ((MgSVec *)D_801D54D0)->vz;
            q->unkC = (p->unkC - ((MgSVec *)D_801D54D0)->vx) / 10;
            q->unk10 = (p->unk10 - ((MgSVec *)D_801D54D0)->vz) / 10;
            q->unkE = 0;
        }
        if (p->unk2 == 0xA) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0238)];
                q->unk4 = p->unkC + func_80042DA8() % 400 - 200;
                q->unk8 = p->unk10 + func_80042DA8() % 400 - 200;
                q->unk6 = 0;
                a = func_80042DA8() % 0x1000;
                q->unkC = (u32)(func_80039B40(a) * 25) >> 10;
                q->unk10 = (u32)(func_80039A74(a) * 25) >> 10;
                q->unkE = -func_80042DA8() % 200 - 100;
                q->unk16 = func_80042DA8() % 20;
                i++;
            } while (i < 8);
            D_8009A000 = 0x29;
            D_8009A004 = 0x40;
            D_8009A008 = 0x14;
            func_8002DA7C();
        }
        if ((u32)((u16)p->unk2 - 7) < 7) {
            q = &D_801621F0[func_800BC04C(&func_801B008C)];
            q->unk4 = p->unkC + func_80042DA8() % 1200 - 600;
            q->unk6 = p->unkE + func_80042DA8() % 1200 - 600;
            q->unk8 = p->unk10 + func_80042DA8() % 1200 - 600;
            q->unk16 = 0;
            q = &D_801621F0[func_800BC04C(&func_801B008C)];
            q->unk4 = p->unkC + func_80042DA8() % 1600 - 800;
            q->unk6 = p->unkE + func_80042DA8() % 1600 - 800;
            q->unk8 = p->unk10 + func_80042DA8() % 1600 - 800;
            q->unk16 = 1;
            g = &D_801031EA;
            t = *g + 0x20;
            *g = t - p->unk2 % 2 * 64;
        }
        if (p->unk2 == 0xC) {
            func_800D5774(p->unk1C);
        }
        p->unk2++;
        if (p->unk2 == 0x23) {
            p->unk0 = -1;
        }
    }
}

void func_801B0D98(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0854)];
    func_800D3994(arg1, D_8015190F[arg1][0], D_801D54D0);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B0E5C(arg0, arg1) {
    func_800BBEAC(func_801B0020);
    func_800D2980(&D_801B0EF4, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B0D98);
    D_8009A000 = 0x28;
    D_8009A004 = 0x40;
    D_8009A008 = 0x173;
    func_8002DA7C();
}
