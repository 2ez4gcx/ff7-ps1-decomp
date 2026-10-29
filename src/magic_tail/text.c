#include "common.h"
#include "magic_tail/decls.h"

void func_801B0000(void) {
    func_801B1568();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EAC84 = D_801D2C84 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D2BD0.unk0 = D_801D2BDC[p->unk16];
    D_801D2BD0.unk8 = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D2BD0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D2BDC[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0180(void) {
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
    frame = &D_801D2BFC;
    *frame = f;
    c = 0x60 - p->unk2 * 4;
    D_801D2BF8 = D_801D2BF9 = D_801D2BFA = c;
    D_801EAC84 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EAC84);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 24) {
            p->unk0 = -1;
        }
    }
}

void func_801B0294(void) {
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
    D_801D2C08 = p->unk16;
    D_801D2C07 = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801D2C04;
    *rgb = D_801D2C05 = D_801D2C06 = n << 4;
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

void func_801B04C4(void) {
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
    rgb = &D_801D2C10;
    c = -0x80 - p->unk2 * 16;
    *rgb = D_801D2C11 = D_801D2C12 = c;
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

void func_801B0684(void) {
    MgMat rot;
    MgMat m;
    MgMat lw;
    MgSVec d;
    MgTask *p;
    s16 dist;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D2C38, &m);
    d.vx = p->unkC - D_801EAC88[0].vx;
    d.vy = p->unkE - D_801EAC88[0].vy;
    d.vz = p->unk10 - D_801EAC8C;
    dist = func_80039F5C(d.vx * d.vx + d.vy * d.vy + d.vz * d.vz);
    func_800D44E8(&d, &rot);
    func_8003A79C(&rot, &m, &m);
    D_801D2C2C[0] = (dist << 12) / 2600;
    func_8003B35C(&m, (MgVec *)&D_801D2C2C[-1]);
    m.t[0] = D_801EAC88[0].vx;
    m.t[1] = D_801EAC88[0].vy;
    m.t[2] = (s16)D_801EAC8C;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801D2C22[0] = p->unk2 * 0x400;
    D_801EAC84 = func_800D29D4(&D_801D2C22[-5], D_801517C0 + 0x70, 0xC, D_801EAC84);
    if (D_80062D98 == 0) {
        if (++p->unk2 == 4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0894(void) {
    MgMat lw;
    MgMat m;
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D2C60, &m);
    t = (func_80039A74(p->unk2 * 0x22) << 13 >> 12) + 0x2000;
    D_801D2C50.vx = D_801D2C58 = t;
    func_8003B35C(&m, &D_801D2C50);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D2C4A[0] = func_80039B40(p->unk2 * 0x22) >> 5;
    D_801EAC84 = func_800D29D4(&D_801D2C4A[-5], D_801517C0 + 0x70, 0xC, D_801EAC84);
    if (D_80062D98 == 0) {
        if (++p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B09E8(void) {
    MgMat m;
    MgSVec rot;
    MgSVec v;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 a;
    s16 t;
    s16 t2;
    s32 r;
    s32 u;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        if (p->unk2 == 0) {
            do {
                q = &D_801621F0[func_800BC04C(&func_801B04C4)];
                q->unk4 = p->unkC;
                q->unk6 = 0;
                q->unk8 = p->unk10;
                a = -func_80042DA8() % 0x400;
                q->unk14 = a;
                v.vx = (u32)(func_80039B40(a) * 5) >> 7;
                v.vy = (u32)(func_80039A74(a) * 5) >> 7;
                v.vz = 0;
                rot.vz = 0;
                rot.vx = 0;
                q->unk16 = rot.vy = (u32)(i << 16) >> 8;
                func_8003C21C(&rot, &m);
                func_8003B2CC(&m, &v, (MgSVec *)&q->unkC);
                i++;
            } while (i < 12);
        }
        t = p->unk2;
        if (t < 0xC && !(((volatile MgTask *)p)->unk2 & 3)) {
            t2 = D_801518F6[p->unk1C][0];
            u = t >> 2;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0894)];
            r = u * 0x555;
            q->unk4 = p->unkC + (func_80039A74(r) * t2 >> 12);
            q->unk6 = 0;
            q->unk8 = p->unk10 + ((s32)func_80039B40(r) * t2 >> 12);
        }
        if (p->unk2 < 6) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0180)];
                q->unk4 = p->unkC + func_80042DA8() % 1600 - 0x320;
                q->unk6 = -func_80042DA8() % 500;
                i++;
                q->unk8 = p->unk10 + func_80042DA8() % 1600 - 0x320;
            } while (i < 2);
        }
        if ((u16)(p->unk2 - 0x13) < 0xBU) {
            q = &D_801621F0[func_800BC04C(&func_801B008C)];
            q->unk4 = p->unkC + func_80042DA8() % 1200 - 0x258;
            q->unk6 = p->unkE + -func_80042DA8() % 500 - 0xC8;
            q->unk8 = p->unk10 + func_80042DA8() % 1200 - 0x258;
            q->unk16 = func_80042DA8() % 2 + 2;
            q = &D_801621F0[func_800BC04C(&func_801B008C)];
            q->unk4 = p->unkC + func_80042DA8() % 1200 - 0x258;
            q->unk6 = p->unkE + -func_80042DA8() % 500 - 0xC8;
            q->unk8 = p->unk10 + func_80042DA8() % 1200 - 0x258;
            q->unk16 = func_80042DA8() % 2;
        }
        if (p->unk2 == 0x14) {
            func_800D5774(p->unk1C);
        }
        if (++p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0FA4(void) {
    MgSVec pt;
    MgTask *p;
    MgTask *q;
    s16 *frame;
    s16 i;
    s16 a;
    s32 d;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(D_801EAC88, 0x3000, 0);
    frame = &D_801D2C70;
    *frame = p->unk2 % D_801D22B4;
    D_801EAC84 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EAC84);
    func_800D4368(D_801EAC88, 0x1000, 0);
    func_8003B69C(0, 0, 0);
    D_801EAC84 = func_800D29D4(D_801D2C74, D_801517C0 + 0x70, 0xC, D_801EAC84);
    if (D_80062D98 == 0) {
        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0684)];
        q->unkC = p->unk4;
        q->unk10 = p->unk8;
        q->unkE = 0;
        q->unk16 = p->unk2 % 2 + 3;
        p->unk4 += p->unkC;
        if (!(p->unk2 & 1)) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0294)];
            q->unk4 = p->unk4;
            q->unk8 = p->unk8;
            q->unk6 = 0;
            a = func_80042DA8() % 0x1000;
            q->unkC = func_80039B40(a) * 0x19 >> 10;
            q->unk10 = (u32)(func_80039A74(a) * 0x19) >> 10;
            q->unkE = -func_80042DA8() % 200 - 0x64;
            q->unk16 = func_80042DA8() % 16 + 4;
        }
        q = &D_801621F0[func_800BC04C(&func_801B008C)];
        q->unk4 = p->unk4 + func_80042DA8() % 200 - 0x64;
        q->unk8 = p->unk8 + func_80042DA8() % 200 - 0x64;
        q->unk16 = 5;
        q->unk6 = 0;
        for (i = 0; i < 10; i++) {
            if ((D_801EAC90 >> i) & 1) {
                func_800D3994(i, D_8015190F[i][0], &pt);
                d = pt.vx - p->unk4;
                if (d < 0) {
                    d = -d;
                }
                if (d < 0x258) {
                    q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B09E8)];
                    func_800D3994(i, D_8015190F[i][0], &q->unkC);
                    q->unk1C = i;
                    D_8009A000.v = 0x29;
                    D_8009A004.v = 0x40;
                    D_8009A008.v = 0x176;
                    D_801EAC90 ^= 1 << i;
                    func_8002DA7C();
                }
            }
        }
        if (++p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B144C(void) {
    MgTask *p;
    MgTask *q;
    u16 t;
    u8 pad[0x30];

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0FA4)];
            q->unk4 = p->unk4 + 0x1000;
            q->unk6 = 0;
            t = p->unk8;
            q->unkC = -0x222;
            q->unk10 = 0;
            q->unkE = 0;
            q->unk8 = t;
            D_8009A000.v = 0x28;
            D_8009A004.v = 0x40;
            D_8009A008.v = 0x173;
            func_8002DA7C();
            D_800F5B72 = 0;
            D_800F5B71 = 0;
            D_800F5B70 = 0;
            func_800D52A0(0xC00, 0xA);
        }
        if (++p->unk2 == 0x2D) {
            p->unk0 = -1;
            func_800D52A0(0, 0xA);
        }
    }
}

s32 func_801B1568(arg0, arg1) {
    MgTask *p;

    func_800BBEAC((M2C_UNK *)func_801B0020);
    D_801EAC90 = arg0;
    func_800D2980(&D_801B1634, 0, 0, 0);
    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B144C)];
    p->unk1E = arg1;
    func_800D3994(arg1, D_8015191E[arg1][0], D_801EAC88);
    return func_800D54EC(arg0, &p->unk4);
}
