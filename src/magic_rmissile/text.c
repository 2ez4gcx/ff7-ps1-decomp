#include "common.h"
#include "magic_rmissile/decls.h"

void func_801B0000(void) {
    func_801B1720();
}

void func_801B0020(s16 mask, MgSVec *out) {
    MgVec sum;
    MgSVec pos;
    s16 i;
    s16 n;

    n = 0;
    sum.vx = sum.vy = sum.vz = 0;
    for (i = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            func_800D3994(i, D_8015190F[i][0], &pos);
            n++;
            sum.vx += pos.vx;
            sum.vy += pos.vy;
            sum.vz += pos.vz;
        }
    }
    out->vx = sum.vx / n;
    out->vy = sum.vy / n;
    out->vz = sum.vz / n;
}

void func_801B01CC(s32 base, s16 range, MgSVec *out) {
    MgSVec v;
    MgSVec rot;
    MgMat m;

    v.vz = 0;
    v.vx = 0;
    v.vy = base + ((func_80042DA8() % range) * 2 - range);
    rot.vy = 0;
    rot.vx = func_80042DA8() % 800 - 400;
    rot.vz = func_80042DA8() % 800 - 400;
    func_8003BF8C(&rot, &m);
    func_8003B2CC(&m, &v, out);
}

void func_801B02FC(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist) {
    MgMat m;
    MgMat r;
    MgVec n;
    s32 flag;
    s16 i;

    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(pos, (MgVec *)m.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)m.t, &n);
        m.t[0] += (dist * n.vx) >> 12;
        m.t[1] += (dist * n.vy) >> 12;
        m.t[2] += (dist * n.vz) >> 12;
    }
    m.m[0][0] = m.m[1][1] = m.m[2][2] = scale;
    func_8003C21C(rot, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
}

void func_801B045C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EC850 = D_801D4850 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C8(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D47CC;
    *frame = p->unk2;
    D_801EC850 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EC850);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D4700) {
            p->unk0 = -1;
        }
    }
}

void func_801B0584(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2800, 0);
    D_801D47D8[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D47D8[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D4638) {
            p->unk0 = -1;
        }
    }
}

void func_801B0640(void) {
    MgMat m[2];
    MgSVec rot;
    s32 flag;
    RmisBody *p;
    MgMat *mp;
    s16 n;
    s16 i;
    s8 *col;
    s8 c;
    s32 t;

    p = (RmisBody *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m[1].m[0][i] = m[1].m[1][i] = m[1].m[2][i] = 0;
    }
    n = 8;
    if (p->unk2 >= 0x16) {
        n = 0x1E - p->unk2;
    }
    rot.vy = 0;
    rot.vx = 0;
    rot.vz = p->unk16;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(&p->unk4, (MgVec *)m[1].t, &flag);
    mp = &m[1];
    m[1].m[0][0] = m[1].m[1][1] = m[1].m[2][2] = 0x2000;
    func_8003C21C(&rot, &m[0]);
    func_8003B05C(mp, &m[0]);
    func_8003B48C(mp);
    func_8003B51C(mp);
    D_801D47E4 = p->unk18;
    D_801D47E3 = (n == 8) ? 0x2C : 0x2E;
    col = &D_801D47E0;
    c = n << 4;
    D_801D47E2 = c;
    D_801D47E1 = c;
    *col = c;
    D_80163C74 = func_800D4D90(col - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4.vx += p->unkC.vx;
        p->unk4.vy += p->unkC.vy;
        p->unk4.vz += p->unkC.vz;
        if (p->unk4.vy > 0) {
            p->unk4.vy = 0;
            t = p->unkC.vy;
            p->unkC.vy = -t;
        }
        p->unkC.vy += 0x14;
        p->unk16 += 0x200;
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B085C(void) {
    MgMat m;
    MgMat lw;
    MgVec sc;
    MgTask *p;
    s16 *frame;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801D47E8, &m);
    sc.vx = sc.vy = sc.vz = p->unk2 * 0x5DC;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801D47FA;
    t = p->unk2;
    *frame = t << 8;
    D_801EC850 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801EC850);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B0994(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    u8 pad[24];
    MgVec scale;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 a;
    s16 k;
    s32 t;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vy = p->unk2 * 0x40;
    rot.vx = rot.vz = 0;
    func_8003BF8C(&rot, &m);
    scale.vx = scale.vy = scale.vz = p->unk2 * 0x12C + 0x1000;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D4808[0] = 0x28;
    D_801D4808[-1] = (s32)D_801D2524;
    D_801D480E = D_801D4800 * 8;
    D_801EC850 = func_800D29D4(&D_801D4808[-1], D_801517C0 + 0x70, 0xC, D_801EC850);
    D_801D4808[0] = 0xA8;
    D_801D4808[-1] = (s32)D_801D42C8;
    v = 0x1000 - ((s16)D_801D4800 << 9);
    D_801D480E = v;
    D_801EC850 = func_800D29D4(&D_801D4808[-1], D_801517C0 + 0x70, 0xC, D_801EC850);
    rot.vy = -p->unk2 * 0x40;
    rot.vx = rot.vz = 0;
    func_8003BF8C(&rot, &m);
    scale.vx = scale.vy = scale.vz = p->unk2 * 0x118 + 0x800;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D4808[0] = 0x28;
    D_801D4808[-1] = (s32)D_801D2524;
    D_801D480E = D_801D4800 * 8;
    D_801EC850 = func_800D29D4(&D_801D4808[-1], D_801517C0 + 0x70, 0xC, D_801EC850);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x16) {
            k = p->unk2 * 0x50;
            i = 0;
            do {
                a = func_80042DA8() % 0x1000;
                q = &D_801621F0[func_800BC04C(func_801B0584)];
                q->unk4 = p->unk4 + (func_80039B40(a) * k >> 12);
                i++;
                q->unk8 = p->unk8 + (func_80039A74(a) * k >> 12);
                q->unk6 = -0x96;
                q->unk18 = 2;
            } while (i < 6);
        }
        t = D_801031EA[0] - 8;
        t += (p->unk2 % 2) << 4;
        D_801031EA[0] = t;
        if (p->unk2 >= 0xF) {
            D_801D4800 -= 1;
        }
        if (++p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0DA0(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    MgSVec pos;
    MgSVec v;
    MgSVec d;
    s32 flag;
    s32 otz;
    MgTask *p;
    u8 *pkt;
    s16 i;
    s32 n;
    s32 t;
    u16 u;

    rot.vy = rot.vx = -0x400;
    rot.vz = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    func_8003C8DC(p->unk14, &m);
    func_8003B35C(&m, &D_801D4814);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801EC850 = func_800D29D4(D_801D4824, D_801517C0 + 0x70, 0xC, D_801EC850);
    rot.vy = p->unk14;
    rot.vx = rot.vz = 0;
    pos.vx = pos.vy = 0;
    pos.vz = -0x64;
    func_8003C21C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003BADC(&pos, &pos, &flag);
    func_800D4368(&pos, 0x2000, 0);
    D_801D483C[0] = p->unk2 % D_801D44A0;
    D_801EC850 = func_800D4D90(&D_801D483C[-4], D_801517C0 + 0x70, 0xC, D_801EC850);
    if (p->unk2 >= 6) {
        v.vx = pos.vx;
        v.vy = pos.vy;
        v.vz = pos.vz;
        i = 0;
        d.vx = -func_80039A74(p->unk14) * (p->unk2 % 2 * 0x50 + 0x50) >> 12;
        d.vz = -func_80039B40(p->unk14) * (p->unk2 % 2 * 0x50 + 0x50) >> 12;
        do {
            func_800D4368(&v, 0x2000, 0);
            D_801D4848[0] = i >> 1;
            D_801EC850 = func_800D4D90(&D_801D4848[-4], D_801517C0 + 0x70, 0xC, D_801EC850);
            i++;
            v.vx += d.vx;
            v.vz += d.vz;
        } while (i < 12);
    }
    if (D_80062D98 == 0) {
        func_8003B48C(&D_800FA63C);
        func_8003B51C(&D_800FA63C);
        for (i = 0; i < 10; i++) {
            v.vx = pos.vx + func_80042DA8() % 400 - 0xC8;
            v.vy = pos.vy + func_80042DA8() % 400 - 0xC8;
            v.vz = pos.vz + func_80042DA8() % 400 - 0xC8;
            pkt = D_801EC850;
            func_80046974(pkt);
            pkt[7] = 0x6A;
            n = func_8003BBDC(&v, pkt + 8, &otz, &flag);
            if (n > 0) {
                pkt[4] = 0x80;
                pkt[5] = 0x40;
                pkt[6] = 0x20;
                t = (n >> 2) * 4 + 0x70;
                func_80046794(t + D_801517C0, pkt);
                D_801EC850 = pkt + 0xC;
            }
        }
        if (p->unk2 < 6) {
            p->unk4 += p->unkC >> 2;
            p->unk6 += (p->unkE >> 2) + p->unk1A;
            p->unk8 += p->unk10 >> 2;
            p->unk1A -= 5;
        }
        if (p->unk2 >= 6) {
            p->unk4 += p->unkC;
            u = p->unk6 - 0xA;
            p->unk6 = u + p->unkE;
            p->unk8 += p->unk10;
        }
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B134C(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    u8 pad[0x38];

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 6 && p->unk2 % 5 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0DA0)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6 - p->unk2 * 0x1E;
            q->unk8 = p->unk8;
            q->unk14 = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q->unkC = (p->unkC - p->unk4) / 15;
            q->unkE = (p->unkE - p->unk6) / 15;
            q->unk10 = (p->unk10 - p->unk8) / 15;
            q->unk1A = 0x32;
            func_800BBA84(0x82, p->unk1E, 0x40);
        }
        if (p->unk2 == 0x32) {
            func_800D5774(p->unk1C);
        }
        if (p->unk2 == 0x14) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0994)];
            q->unk4 = p->unkC;
            q->unk6 = 0;
            q->unk8 = p->unk10;
            q->unk18 = 0;
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B085C)];
            q->unk4 = p->unkC;
            q->unk6 = -0x12C;
            i = 0;
            q->unk8 = p->unk10;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0640)];
                q->unk4 = p->unkC;
                q->unk8 = p->unk10;
                q->unk6 = 0;
                func_801B01CC(-0xFA, 0x64, (MgSVec *)&q->unkC);
                i++;
                q->unk18 = func_80042DA8() % 7;
            } while (i < 0x14);
            func_800BBA84(0x176, p->unk1C, 0x40);
        }
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B1654(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B134C)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    p->unk1E = arg1;
}

void func_801B1720(arg0, arg1) {
    func_800BBEAC(&func_801B045C);
    func_800D2980(&D_801B178C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B1654);
}
