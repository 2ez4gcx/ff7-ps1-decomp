#include "common.h"
#include "magic_hakugek2/decls.h"

void func_801B0000(void) {
    func_801B117C();
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
    D_801EA96C = D_801D296C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C8(void) {
    MgMat m;
    MgMat r;
    s32 flag;
    s16 i;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[i][0] = m.m[i][1] = m.m[i][2] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x3000;
    func_8003B05C(&m, &D_800FA63C);
    func_8003C21C((MgSVec *)&p->unkC, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801D2924[0] = p->unk2;
    D_801EA96C = (u8 *)func_800D4D90(&D_801D2924[-4], D_801517C0 + 0x70, 0xC, (s32)D_801EA96C);
    if (D_80062D98 == 0) {
        if (++p->unk2 == D_801D2858) {
            p->unk0 = -1;
        }
    }
}

void func_801B062C(void) {
    MgMat m[2];
    MgSVec rot;
    s32 flag;
    MgTask *p;
    MgMat *mp;
    s16 n;
    s16 i;
    s8 c;

    p = (MgTask *)&D_80162978[D_8015169C];
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
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m[1].t, &flag);
    mp = &m[1];
    m[1].m[0][0] = m[1].m[1][1] = m[1].m[2][2] = 0x2000;
    func_8003C21C(&rot, &m[0]);
    func_8003B05C(mp, &m[0]);
    func_8003B48C(mp);
    func_8003B51C(mp);
    c = n << 4;
    D_801D2930[0] = p->unk16 % 3;
    *(s32 *)&D_801D2930[-4] = D_801D2934[p->unk16 / 3];
    D_801D2928[4] = D_801D2928[5] = D_801D2928[6] = c;
    D_80163C74 = func_800D4D90(&D_801D2930[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkE += 0x14;
        p->unk14 += 0x200;
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0878(void) {
    MgSVec rot;
    MgMat m;
    MgMat w;
    MgVec s;
    MgTask *p;
    s16 *c;

    rot.vx = rot.vz = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vy = p->unk14;
    func_8003C21C(&rot, &m);
    s.vy = 0x1000;
    s.vx = s.vz = p->unk18;
    func_8003B35C(&m, &s);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &w);
    func_8003B48C(&w);
    func_8003B51C(&w);
    c = &D_801D294A;
    *c = p->unk2 * 200;
    D_801EA96C = (u8 *)func_800D29D4(c - 5, D_801517C0 + 0x70, 0xC, (s32)D_801EA96C);
    if (D_80062D98 == 0) {
        p->unk18 += 0x200;
        p->unk14 += 0x80;
        p->unk6 += p->unkE;
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B09E0(void) {
    MgSVec rot;
    MgMat m;
    MgMat w;
    MgVec s;
    MgTask *p;
    HakuWord *c;
    HakuPtr *d;
    s32 t;

    rot.vx = rot.vz = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    rot.vy = t << 6;
    func_8003C21C(&rot, &m);
    s.vx = s.vy = s.vz = p->unk2 * 240 + 0x600;
    func_8003B35C(&m, &s);
    m.t[0] = p->unk4;
    m.t[1] = 0;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &w);
    func_8003B48C(&w);
    func_8003B51C(&w);
    c = (HakuWord *)&D_801D2954;
    d = (HakuPtr *)((u8 *)c - 4);
    c->v = 0x28;
    d->p = &D_801D1288;
    D_801D295A = 0x80 - p->unk2 * 6;
    D_801EA96C = func_800D29D4(d, D_801517C0 + 0x70, 0xC, D_801EA96C);
    func_8003C21C(&rot, &m);
    s.vx = s.vy = s.vz = p->unk2 * 320 + 0x800;
    func_8003B35C(&m, &s);
    m.t[0] = p->unk4;
    m.t[1] = 0;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &w);
    func_8003B48C(&w);
    func_8003B51C(&w);
    func_8003C21C(&rot, &m);
    c->v = 0x28;
    d->p = &D_801D1A00;
    D_801D295A = 0x80 - p->unk2 * 6;
    D_801EA96C = func_800D29D4(d, D_801517C0 + 0x70, 0xC, D_801EA96C);
    s.vx = s.vy = s.vz = p->unk2 * 240 + 0x600;
    func_8003B35C(&m, &s);
    m.t[0] = p->unk4;
    m.t[1] = 0;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &w);
    func_8003B48C(&w);
    func_8003B51C(&w);
    c->v = 0xA8;
    d->p = &D_801D15F4;
    D_801D295A = p->unk2 * 48 + 0xC00;
    D_801EA96C = func_800D29D4(d, D_801517C0 + 0x70, 0xC, D_801EA96C);
    c->v = 0xA8;
    d->p = &D_801D1FD0;
    D_801D295A = p->unk2 * 96;
    D_801EA96C = func_800D29D4(d, D_801517C0 + 0x70, 0xC, D_801EA96C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0D64(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 a;
    u8 pad[0x30];

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            a = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B04C8)];
            func_800D3994(p->unk1E, D_80151917[p->unk1E][0], &q->unk4);
            q->unkC = 0;
            q->unkE = a + 0x400;
            q->unk10 = -0x200;
        }
        if (p->unk2 == 0x14) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B062C)];
                q->unk4 = p->unkC + func_80042DA8() % 400 - 0xC8;
                q->unk8 = p->unk10 + func_80042DA8() % 400 - 0xC8;
                q->unk6 = 0;
                func_801B01CC(-0x12C, 0x32, (MgSVec *)&q->unkC);
                i++;
                q->unk16 = func_80042DA8() % 9;
            } while (i < 0x18);
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B09E0)];
            i = 0;
            q->unk4 = p->unkC;
            q->unk6 = 0;
            q->unk8 = p->unk10;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0878)];
                q->unk4 = p->unkC;
                q->unk6 = p->unkE;
                q->unk8 = p->unk10;
                q->unk6 = (i - 4) * 0x50;
                q->unk18 = D_801D2960[i];
                q->unkE = (i - 4) * 10;
                q->unk14 = func_80042DA8() % 0x1000;
                i++;
            } while (i < 5);
            func_800BBA84(0xFA, p->unk1C, 0);
        }
        if (p->unk2 == 0x23) {
            func_800D5774(p->unk1C);
        }
        p->unk2++;
        if (p->unk2 == 0x2D) {
            p->unk0 = -1;
        }
    }
}

void func_801B10A0(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0D64)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    p->unk1E = arg1;
    func_800BBA84(0x14, arg1, 0);
}

void func_801B117C(arg0, arg1) {
    func_800BBEAC(&func_801B045C);
    func_800D2980(&D_801B11E8, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B10A0);
}
