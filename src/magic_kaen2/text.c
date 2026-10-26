#include "common.h"
#include "magic_kaen2/decls.h"

void func_801B0000(void) {
    func_801B10BC();
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
    D_801EC140 = D_801D4140 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C8(void) {
    MgTask *p;
    MgGasHold *q;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, p->unk16 == 2 ? 0x2000 : 0x3000, 0);
    q = &D_801D40C8;
    q->anim = D_801D40D4[p->unk16];
    D_801D40D0 = p->unk2;
    D_80163C74 = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        if (p->unk16 == 1) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unkC -= p->unkC / 8;
            p->unkE -= p->unkE / 8;
            p->unk10 -= p->unk10 / 8;
        }
        p->unk2++;
        if (p->unk2 == D_801D40D4[p->unk16]->unk4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0658(void) {
    MgMat m[2];
    MgSVec rot;
    s32 flag;
    MgGas *p;
    MgMat *mp;
    s16 n;
    s16 i;
    s16 scale;
    s8 *col;
    s8 c;
    s32 t;

    p = (MgGas *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m[1].m[0][i] = m[1].m[1][i] = m[1].m[2][i] = 0;
    }
    n = 8;
    if (p->unk2 >= 12) {
        n = 20 - p->unk2;
    }
    rot.vy = 0;
    rot.vx = 0;
    rot.vz = p->unk14;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(&p->unk4, (MgVec *)m[1].t, &flag);
    mp = &m[1];
    scale = 0x2000;
    if (p->unk16 < 4) {
        scale = 0x1400;
    }
    m[1].m[0][0] = m[1].m[1][1] = m[1].m[2][2] = scale;
    func_8003C21C(&rot, &m[0]);
    func_8003B05C(mp, &m[0]);
    func_8003B48C(mp);
    func_8003B51C(mp);
    D_801D40E8 = p->unk16;
    D_801D40E7 = (n == 8) ? 0x2C : 0x2E;
    col = &D_801D40E4;
    c = n << 4;
    D_801D40E6 = c;
    D_801D40E5 = c;
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
        p->unk14 += 0x200;
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0888(void) {
    MgMat a;
    MgMat m;
    MgMat w;
    MgSVec pad;
    MgTask *p;
    MgTask *q;
    s32 *f;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D44E8((MgSVec *)&p->unkC, &a);
    func_8003C21C(&D_801D40EC, &m);
    func_8003A79C(&a, &m, &m);
    func_8003B35C(&m, &D_801D40F4);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &w);
    func_8003B48C(&w);
    func_8003B51C(&w);
    f = &D_801D4104;
    *f = D_801D4120[p->unk2 % 8];
    D_801EC140 = func_800D29D4(f, D_801517C0 + 0x70, 0xC, D_801EC140);
    func_800D4368(&p->unk4, 0x1000, 0);
    D_80163C74 = func_800D4D90(&D_801D4114, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        t = p->unk2 + 1;
        p->unk2 = t;
        if (t == 8) {
            q = &D_801621F0[func_800BC04C(func_801B04C8)];
            q->unk4 = p->unk4 + func_80042DA8() % 800 - 0x190;
            q->unk6 = p->unk6 + func_80042DA8() % 800 - 0x190;
            q->unk8 = p->unk8 + func_80042DA8() % 800 - 0x190;
            q->unk16 = 0;
            p->unk0 = -1;
        }
    }
}

void func_801B0B40(void) {
    MgSVec v;
    MgSVec rot;
    MgMat m;
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 0xC) {
            t = (u16)p->unk2;
            if (!(t & 3)) {
                q = &D_801621F0[func_800BC04C(func_801B04C8)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unk16 = 2;
                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0888)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unkC = (p->unkC - p->unk4) / 8;
                q->unkE = (p->unkE - p->unk6) / 8;
                q->unk10 = (p->unk10 - p->unk8) / 8;
                func_800BBA84(0x163, p->unk1E, 0);
            }
        }
        if (p->unk2 == 0xE) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0658)];
                q->unk4 = p->unkC + func_80042DA8() % 400 - 0xC8;
                q->unk8 = p->unk10 + func_80042DA8() % 400 - 0xC8;
                q->unk6 = 0;
                func_801B01CC(-0xFA, 0x64, (MgSVec *)&q->unkC);
                i++;
                q->unk16 = func_80042DA8() % 20;
            } while (i < 8);
            func_800BBA84(0x7C, p->unk1C, 0);
        }
        if ((u16)(p->unk2 - 0xC) < 7U) {
            i = 0;
            do {
                q = &D_801621F0[func_800BC04C(func_801B04C8)];
                q->unk4 = p->unkC + func_80042DA8() % 1200 - 0x258;
                q->unk6 = p->unkE + func_80042DA8() % 1200 - 0x258;
                q->unk8 = p->unk10 + func_80042DA8() % 1200 - 0x258;
                rot.vx = func_80042DA8() % 1200 - 0x258;
                rot.vy = 0;
                rot.vz = func_80042DA8() % 1200 - 0x258;
                v.vx = 0;
                v.vy = -0xA0;
                v.vz = 0;
                func_8003C21C(&rot, &m);
                func_8003B2CC(&m, &v, (MgSVec *)&q->unkC);
                i++;
                q->unk16 = 1;
            } while (i < 2);
        }
        if (p->unk2 == 0xF) {
            func_800D5774(p->unk1C);
        }
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0FF0(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0B40)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    p->unk1E = arg1;
}

void func_801B10BC(arg0, arg1) {
    func_800BBEAC(&func_801B045C);
    func_800D2980(&D_801B1128, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0FF0);
}
