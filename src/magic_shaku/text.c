#include "common.h"
#include "magic_shaku/decls.h"

void func_801B0000(void) {
    func_801B1970();
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
    D_801ED768 = D_801D5768 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C8(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(D_801D5650, 0, 0);
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 < 0x10) {
            D_801D5650 = (u16) D_801D5650 + 0xF;
        }
        if (temp_s0->unk2 >= 0x23) {
            D_801D5650 = (u16) D_801D5650 - 0xF;
        }
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 == 0x32) {
            temp_s0->unk0 = -1;
        }
    }
}

void func_801B05A8(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2800, 0);
    D_801D565C[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D565C[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D5294) {
            p->unk0 = -1;
        }
    }
}

void func_801B0664(void) {
    MgMat lw;
    MgMat m;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    u8 *rgb;
    s16 i;
    s16 n;

    p = &D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[2][i] = 0;
        m.m[1][i] = 0;
        m.m[0][i] = 0;
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
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x2000;
    func_8003C21C(&rot, &lw);
    func_8003B05C(&m, &lw);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801D5668 = p->unk16;
    D_801D5667 = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801D5664;
    *rgb = D_801D5665 = D_801D5666 = n << 4;
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
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B0880(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    MgTask *p;
    s16 *frame;
    s32 *q;

    rot.vy = 0;
    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vz = p->unk14;
    func_8003BF8C(&rot, &m);
    func_8003B35C(&m, &D_801D566C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801D5686;
    q = (s32 *)((u8 *)frame - 0xA);
    M2C_SFIELD(frame, s16 *, 0) = 0x80 - p->unk2 * 6;
    *q = D_801D568C[p->unk16];
    D_801ED768 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801ED768);
    if (D_80062D98 == 0) {
        p->unk6 -= 200;
        p->unk14 += 0x100;
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B09E0(void) {
    MgTask *p;
    MgMat m;
    MgMat lw;
    MgVec scale;
    s32 t;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801D569C, &m);
    func_8003A79C(&D_801D573C, &m, &m);
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
    D_801D56AE[0] = t << 8;
    D_801ED768 = func_800D29D4(&D_801D56AE[-5], D_801517C0 + 0x70, 0xC, D_801ED768);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B0B3C(void) {
    MgTask *p;
    MgMat m;
    MgMat lw;
    MgVec scale;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 >= 3) {
        func_8003C21C(&D_801D56B4, &m);
        func_8003A79C(&D_801D573C, &m, &m);
        scale.vx = scale.vy = scale.vz = 0x4000 - p->unk2 * 400;
        func_8003B35C(&m, &scale);
        m.t[0] = p->unk4;
        m.t[1] = p->unk6;
        m.t[2] = p->unk8;
        func_8003A63C(&D_800FA63C, &m, &lw);
        func_8003B48C(&lw);
        func_8003B51C(&lw);
        func_8003B69C(0, 0, 0);
        t = p->unk2;
        D_801D56C6[0] = t * 200;
        D_801ED768 = (u8 *)func_800D29D4(&D_801D56C6[-5], D_801517C0 + 0x70, 0xC, (s32)D_801ED768);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B0CC0(void) {
    MgTask *p;
    u16 *frame;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x4000, 0);
    frame = &D_801D56D4;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 >= D_801D54CC) {
            p->unk0 = -1;
        }
    }
}

void func_801B0DAC(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, (s16)(((func_80039A74(p->unk2 * 0x33) << 11 >> 16) << 7) + 0x1000), 0);
    D_801D56E0[0] = p->unk2 % 2;
    D_801ED768 = func_800D4D90(&D_801D56E0[-4], D_801517C0 + 0x70, 0xC, D_801ED768);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0EAC(void) {
    MgMat m;
    MgMat lw;
    MgVec scale;
    MgTask *p;
    s16 *frame;
    s32 **q;
    s32 v;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801D56F8, &m);
    func_8003A79C(&D_801D573C, &m, &m);
    scale.vx = scale.vz = 0x4000 - p->unk2 * 300;
    scale.vy = p->unk2 * 900;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    frame = &D_801D56F2;
    q = (s32 **)((u8 *)frame - 0xA);
    M2C_SFIELD(q, s32 **, 0) = &D_801D1C38;
    v = 0x1000 - (D_801D56E4 << 8);
    *frame = v;
    D_801ED768 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801ED768);
    *q = &D_801D223C;
    D_801ED768 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801ED768);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 13) {
            D_801D56E4--;
        }
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B10A0(void) {
    MgMat m1;
    MgMat m2;
    MgTask *p;
    MgTask *q;
    u16 *frame;
    u8 *pk;
    s8 *col;
    s32 r;
    s32 k;
    s8 c;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801D5730, &m1);
    func_8003A79C(&D_801D573C, &m1, &m1);
    func_8003B35C(&m1, &D_801D5704);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m1, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    frame = &D_801D571E;
    pk = (u8 *)frame - 0xA;
    ((MgPkt *)pk)->tag = D_801D2840;
    *frame = D_801D5700 * 0x10;
    D_801ED768 = func_800D29D4(pk, D_801517C0 + 0x70, 0xC, D_801ED768);
    ((MgPkt *)pk)->tag = D_801D37E4;
    D_801ED768 = func_800D29D4(pk, D_801517C0 + 0x70, 0xC, D_801ED768);
    ((MgPkt *)pk)->tag = D_801D4788;
    D_801ED768 = func_800D29D4(pk, D_801517C0 + 0x70, 0xC, D_801ED768);
    func_800D4368(&p->unk4, 0x4000, 0);
    col = &D_801D5728;
    c = (s16)D_801D5700 * 0x14;
    D_801D572A.v = c;
    D_801D5729.v = c;
    *col = c;
    D_801D572C = (s16)((u16 *)p)[1] % 2;
    D_801ED768 = func_800D4D90(col - 4, D_801517C0 + 0x70, 0xC, D_801ED768);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (!(p->unk2 & 1)) {
            q = &D_80162978[func_800BBEAC(func_801B0B3C)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
        }
        if (p->unk6 < 0) {
            q = &D_80162978[func_800BBEAC(func_801B0664)];
            q->unk4 = p->unk4;
            q->unk8 = p->unk8;
            q->unk6 = 0;
            D_801D5738 = func_80042DA8() % 0x1000;
            q->unkC = (u32)(func_80039B40(D_801D5738) * 0xF) >> 9;
            q->unk10 = (u32)(func_80039A74(D_801D5738) * 0xF) >> 9;
            q->unkE = -func_80042DA8() % 300 - 0x32;
            q->unk16 = func_80042DA8() % 7;
            if ((s16)(p->unk2 % 3) == 0) {
                q = &D_80162978[func_800BBEAC(func_801B0880)];
                q->unk4 = p->unk4 + func_80042DA8() % 4000 - 0x7D0;
                q->unk8 = p->unk8 + func_80042DA8() % 4000 - 0x7D0;
                q->unk6 = 0;
                q->unk16 = func_80042DA8() % 4;
            }
        }
        if (p->unk2 >= 0xD) {
            D_801D5700--;
        }
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B1590(void) {
    MgSVec v;
    MgSVec rot;
    MgMat m;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 r;
    s32 k;
    u16 t;
    u16 *e;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &D_80162978[func_800BBEAC(func_801B09E0)];
            q->unk4 = (u16)p->unk4;
            q->unk6 = (u16)p->unk6;
            q->unk8 = (u16)p->unk8;
            q = &D_80162978[func_800BBEAC(func_801B0DAC)];
            q->unk4 = (u16)p->unk4;
            q->unk6 = (u16)p->unk6;
            q->unk8 = (u16)p->unk8;
            func_800BBA84(0x174, p->unk1E, 0x40);
        }
        if (p->unk2 == 0x14) {
            q = &D_80162978[func_800BBEAC(func_801B0EAC)];
            q->unk4 = (u16)p->unk4;
            q->unk6 = (u16)p->unk6;
            q->unk8 = (u16)p->unk8;
            q = &D_80162978[func_800BBEAC(func_801B10A0)];
            q->unk4 = (u16)p->unk4;
            q->unk6 = (u16)p->unk6;
            q->unk8 = (u16)p->unk8;
            q->unkC = (u16)p->unkC;
            q->unkE = (u16)p->unkE;
            q->unk10 = (u16)p->unk10;
            func_800BBA84(0x176, p->unk1E, 0x40);
            if (p->unk2 == 0x14) {
                func_800BBEAC(func_801B04C8);
            }
        }
        if (p->unk2 == 0x36) {
            func_800D52A0(0, 0x10);
        }
        if ((u32)((u16)p->unk2 - 0x25) < 7) {
            for (i = 0; i < 10; i++) {
                if ((D_801D575C >> i) & 1) {
                    q = &D_801621F0[func_800BC04C(func_801B0CC0)];
                    func_800D3994(i, D_8015190F[i][0], &q->unk4);
                    v.vy = 0x50;
                    v.vz = 0;
                    v.vx = 0;
                    r = func_80042DA8();
                    rot.vx = r % 0x1000;
                    r = func_80042DA8();
                    rot.vz = r % 0x1000;
                    rot.vy = 0;
                    func_8003C21C(&rot, &m);
                    m.t[0] = m.t[1] = m.t[2] = 0;
                    func_8003B48C(&m);
                    func_8003B51C(&m);
                    func_8003BADC(&v, (MgSVec *)&q->unkC, &flag);
                }
            }
        }
        if (p->unk2 == 0x28) {
            for (i = 0; i < 10; i++) {
                if ((D_801D575C >> i) & 1) {
                    func_800D5774(i);
                }
            }
            func_800BBA84(0xFA, -1, 0x40);
        }
        t = p->unk2;
        if ((s16)t >= 0x15) {
            e = &D_801031EA;
            k = *e + 0x10;
            *e = k - (s16)((s16)t % 2) * 32;
        }
        if (++p->unk2 == 0x46) {
            p->unk0 = -1;
        }
    }
}

void func_801B1970(arg0, arg1) {
    MgVec v;
    MgSVec d;
    MgTask *p;

    func_800BBEAC(func_801B045C);
    D_801D575C = arg0;
    p = &D_80162978[func_800BBEAC(func_801B1590)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_801B0020(arg0, &D_801D5760);
    v.vx = d.vx = D_801D5760.vx - p->unk4;
    v.vy = d.vy = D_801D5762 - p->unk6;
    v.vz = d.vz = D_801D5764 - p->unk8;
    func_800D44E8(&d, &D_801D573C);
    func_8003A08C(&v, &v);
    p->unkC = (u32)(v.vx * 75) >> 9;
    p->unkE = (u32)(v.vy * 75) >> 9;
    p->unk10 = (u32)(v.vz * 75) >> 9;
    p->unk1E = arg1;
    func_800D2980(D_801B1B38, 0, 0, 0);
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    func_800D52A0(0x1000, 0x10);
}
