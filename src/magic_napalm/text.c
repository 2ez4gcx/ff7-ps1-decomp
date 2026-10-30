#include "common.h"
#include "magic_napalm/decls.h"

void func_801B0000(void) {
    func_801B1884();
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
    D_801F088C = D_801D888C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C8(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, D_801D8804[p->unk1A], 0);
    D_801D87F8[0] = p->unk2;
    *(MgGasAnim **)&D_801D87F8[-4] = D_801D87FC[p->unk1A];
    D_801F088C = func_800D4D90(&D_801D87F8[-4], D_801517C0 + 0x70, 0xC, D_801F088C);
    if (D_80062D98 == 0) {
        if (p->unk1A == 0) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
        }
        p->unk2++;
        if (p->unk2 == D_801D87FC[p->unk1A]->unk4) {
            p->unk0 = -1;
        }
    }
}

void func_801B060C(void) {
    MgTask *p;
    s8 c;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801D8810.v = p->unk2;
    c = 0x40 - p->unk2 * 4;
    D_801D880E = c;
    D_801D880D = c;
    D_801D880C = c;
    D_80163C74 = func_800D4D90((u8 *)&D_801D8810 - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D85E4) {
            p->unk0 = -1;
        }
    }
}

void func_801B06F0(void) {
    MgObj20 *temp_s0;
    MgObj20 *temp_v0;
    s16 temp_v0_2;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        M2C_FIELD(temp_s0, u16 *, 4) = (u16) (M2C_FIELD(temp_s0, u16 *, 4) + M2C_FIELD(temp_s0, u16 *, 0xC));
        M2C_FIELD(temp_s0, u16 *, 6) = (u16) (M2C_FIELD(temp_s0, u16 *, 6) + M2C_FIELD(temp_s0, u16 *, 0xE));
        M2C_FIELD(temp_s0, u16 *, 8) = (u16) (M2C_FIELD(temp_s0, u16 *, 8) + M2C_FIELD(temp_s0, u16 *, 0x10));
        M2C_FIELD(temp_s0, u16 *, 0xE) = (u16) (M2C_FIELD(temp_s0, u16 *, 0xE) + 0xA);
        temp_v0 = &D_80162978[func_800BBEAC(&func_801B04C8)];
        M2C_FIELD(temp_v0, u16 *, 4) = (u16) M2C_FIELD(temp_s0, u16 *, 4);
        M2C_FIELD(temp_v0, u16 *, 6) = (u16) M2C_FIELD(temp_s0, u16 *, 6);
        M2C_FIELD(temp_v0, u16 *, 8) = (u16) M2C_FIELD(temp_s0, u16 *, 8);
        M2C_FIELD(temp_v0, s16 *, 0x1A) = 1;
        temp_v0_2 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0_2;
        if (temp_v0_2 == 0xA) {
            temp_s0->unk0 = -1;
        }
    }
}

void func_801B07D4(void) {
    MgMat m;
    MgMat lw;
    MgSVec v;
    MgSVec d;
    MgTask *p;
    s16 *frame;
    s16 i;
    s16 *frame2;

    D_801D8834.vx = -0x400;
    D_801D8836 = -0x400;
    D_801D8838 = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801D8834, &m);
    func_8003C8DC(p->unk14, &m);
    func_8003B35C(&m, &D_801D8814);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801F088C = (u8 *)func_800D29D4(&D_801D8824, D_801517C0 + 0x70, 0xC, (s32)D_801F088C);
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D8844;
    *frame = p->unk2 % 3;
    D_801F088C = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801F088C);
    v.vx = p->unk4;
    v.vy = p->unk6;
    v.vz = p->unk8;
    i = 0;
    d.vx = -func_80039A74(p->unk14) * (p->unk2 % 2 * 0x50 + 0x50) >> 12;
    d.vz = -func_80039B40(p->unk14) * (p->unk2 % 2 * 0x50 + 0x50) >> 12;
    frame2 = &D_801D8850;
    do {
        func_800D4368(&v, 0x2000, 0);
        *frame2 = i >> 1;
        D_801F088C = (u8 *)func_800D4D90((u8 *)frame2 - 8, D_801517C0 + 0x70, 0xC, (s32)D_801F088C);
        i++;
        v.vx += d.vx;
        v.vz += d.vz;
    } while (i < 0xC);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (++p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B0B10(void) {
    MgMat m[2];
    MgSVec rot;
    s32 flag;
    MgGas *p;
    MgMat *mp;
    s16 n;
    s16 i;
    s8 *col;
    s8 c;
    s32 t;

    p = (MgGas *)&D_80162978[D_8015169C];
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
    D_801D885C = p->unk1A;
    D_801D885B = (n == 8) ? 0x2C : 0x2E;
    col = &D_801D8858;
    c = n << 4;
    D_801D885A = c;
    D_801D8859 = c;
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

void func_801B0D2C(void) {
    MgTask *p;
    MgMat m;
    MgMat lw;
    MgVec scale;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801D8860, &m);
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
    D_801D8872[0] = t << 8;
    D_801F088C = (u8 *)func_800D29D4(&D_801D8872[-5], D_801517C0 + 0x70, 0xC, (s32)D_801F088C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 15) {
            p->unk0 = -1;
        }
    }
}

void func_801B0E74(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    u8 pad[0x18];
    MgVec scale;
    MgTask *p;
    MgTask *q;
    MgSVec *ta;
    MgSVec *tb;
    MgSVec *td;
    MgSVec *pa;
    MgSVec *pb;
    MgSVec *pd;
    s16 i;
    s16 n;
    s16 a;
    s16 k;
    s32 t;
    s16 r;
    s32 u;
    u16 *g;

    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vy = p->unk2 * 0x20;
    rot.vz = 0;
    rot.vx = 0;
    func_8003BF8C(&rot, &m);
    scale.vx = scale.vy = scale.vz = p->unk2 * 0x190 + 0x1000;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801D8880[0] = 0x28;
    D_801D8880[-1] = (s32)&D_801D5C5C;
    D_801D8886 = D_801D8878 * 0x10;
    D_801F088C = (u8 *)func_800D29D4(&D_801D8880[-1], D_801517C0 + 0x70, 0xC, (s32)D_801F088C);
    D_801D8880[0] = 0x28;
    D_801D8880[-1] = (s32)D_801D7A00;
    D_801F088C = (u8 *)func_800D29D4(&D_801D8880[-1], D_801517C0 + 0x70, 0xC, (s32)D_801F088C);
    D_801D8880[0] = 0xA8;
    D_801D8880[-1] = (s32)D_801D7B44;
    t = *(s16 *)&D_801D8878;
    D_801D8886 = 0x1000 - (t << 9);
    D_801F088C = (u8 *)func_800D29D4(&D_801D8880[-1], D_801517C0 + 0x70, 0xC, (s32)D_801F088C);
    if (D_80062D98 == 0) {
        ta = D_801D2118;
        tb = D_801D3EBC;
        td = D_801D5C5C.pt;
        n = D_801D5C5C.cnt / 8;
        for (i = 0; i < n; i++) {
            pa = &ta[i];
            pb = &tb[i];
            pd = &td[i];
            pd->vx = pa->vx + (pb->vx - pa->vx) * p->unk2 / 30;
            pd->vy = pa->vy + (pb->vy - pa->vy) * p->unk2 / 30;
            pd->vz = pa->vz + (pb->vz - pa->vz) * p->unk2 / 30;
        }
        if (p->unk2 < 0x16) {
            k = p->unk2 * 0x50;
            for (i = 0; i < 4; i++) {
                a = func_80042DA8() % 0x1000;
                q = &D_801621F0[func_800BC04C(&func_801B060C)];
                q->unk4 = p->unk4 + (func_80039B40(a) * k >> 12);
                q->unk8 = p->unk8 + (func_80039A74(a) * k >> 12);
                q->unk6 = -0x96;
                q->unk1A = 2;
            }
        }
        g = &D_801031EA;
        u = *g;
        r = p->unk2 % 2;
        u -= 8;
        u += r * 0x10;
        *g = u;
        if (p->unk2 >= 0x17) {
            D_801D8878 -= 1;
        }
        if (++p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B12D8(void) {
    u8 pad[0x38];
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 a;
    s16 ang;
    s32 r;
    s32 t;
    s32 u;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 0xA) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B04C8)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                a = func_80042DA8() % 0x1000;
                q->unkC = (u32)(func_80039B40(a) * 5) >> 8;
                q->unk10 = (u32)(func_80039A74(a) * 5) >> 8;
                r = -func_80042DA8();
                i++;
                q->unk1A = 0;
                q->unkE = r % 80;
            } while (i < 4);
        }
        if (p->unk2 == 5) {
            i = 0;
            ang = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B06F0)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                u = i * 0x258 - 0x12C;
                t = ang + u;
                q->unk8 = p->unk8;
                q->unkC = (u32)(func_80039A74(t) * 0x4B) >> 11;
                q->unk10 = (u32)(func_80039B40(t) * 0x4B) >> 11;
                i++;
                q->unkE = -func_80042DA8() % 50 - 0x32;
            } while (i < 2);
        }
        if (p->unk2 == 0xA) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B07D4)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unkC = (p->unkC - p->unk4) / 10;
            q->unkE = (p->unkE - p->unk6) / 10;
            q->unk10 = (p->unk10 - p->unk8) / 10;
            q->unk14 = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
        }
        if (p->unk2 == 0x28) {
            func_800D5774(p->unk1C);
        }
        if (p->unk2 == 0x14) {
            i = 0;
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0E74)];
            q->unk4 = p->unkC;
            q->unk6 = 0;
            q->unk8 = p->unk10;
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0D2C)];
            q->unk4 = p->unkC;
            q->unk6 = -0x12C;
            q->unk8 = p->unk10;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0B10)];
                q->unk4 = p->unkC;
                q->unk8 = p->unk10;
                q->unk6 = 0;
                func_801B01CC(-0xFA, 0x64, (MgSVec *)&q->unkC);
                i++;
                q->unk1A = func_80042DA8() % 7;
            } while (i < 0x14);
            func_800BBA84(0x176, p->unk1C, 0x40);
        }
        if (++p->unk2 == 0x37) {
            p->unk0 = -1;
        }
    }
}

void func_801B17AC(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B12D8)];
    func_800D3994(arg1, D_8015190F[arg1][9], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    func_800BBA84(0x82, arg1, 0x40);
}

void func_801B1884(arg0, arg1) {
    func_800BBEAC(&func_801B045C);
    func_800D2980(&D_801B18F0, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B17AC);
}
