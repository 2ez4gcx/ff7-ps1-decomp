#include "common.h"
#include "magic_tbreath/decls.h"

void func_801B0000(void) {
    func_801B1840();
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
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801E72D0 = D_801D715C[p->unk2];
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C0(void) {
    MgMat m[2];
    u8 pad[8];
    s32 flag;
    MgTask *p;
    s16 i;

    p = &D_801621F0[D_801590D4];
    for (i = 0; i < 3; i++) {
        m[1].m[0][i] = m[1].m[1][i] = m[1].m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m[1].t, &flag);
    m[1].m[0][0] = m[1].m[1][1] = m[1].m[2][2] = 0x3000;
    func_8003C21C((MgSVec *)&p->unkC, &m[0]);
    func_8003B05C(&m[1], &m[0]);
    func_8003B48C(&m[1]);
    func_8003B51C(&m[1]);
    D_801D716C[0] = p->unk2;
    *(s32 **)&D_801D716C[-4] = D_801D7170[p->unk16];
    D_80163C74 = func_800D4D90(&D_801D716C[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D7170[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B063C(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(0, 0, D_801D7178);
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 < 0x10) {
            D_801D7178 = (u16) D_801D7178 + 0xF;
        }
        if (temp_s0->unk2 >= 0x11) {
            D_801D7178 = (u16) D_801D7178 - 0xF;
        }
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 == 0x20) {
            temp_s0->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_tbreath/nonmatchings/text", func_801B071C);

void func_801B0948(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D71A0[0] = D_801D71AC[p->unk2];
    *(s32 *)&D_801D71A0[-4] = D_801D71A4[p->unk16];
    D_80163C74 = func_800D4D90(&D_801D71A0[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x1C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_tbreath/nonmatchings/text", func_801B0A2C);

void func_801B0DD4(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    D_801D7244[0] = p->unk2;
    D_801E72D0 = func_800D4D90(&D_801D7244[-4], D_801517C0 + 0x70, 0xC, D_801E72D0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D69C4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0E8C(void) {
    MgMat m;
    MgMat m2;
    MgSVec rot;
    MgTask *p;
    s32 *q;

    rot.vx = rot.vy = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vz = p->unk14;
    func_8003BF8C(&rot, &m);
    q = &D_801D72B0;
    *q = D_801D72B4 = D_801D72B8 = 0x1000;
    func_8003B35C(&m, q);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    D_801D7252[0] = 0x80 - p->unk2 * 8;
    *(u8 **)&D_801D7252[-5] = D_801D7258[p->unk16];
    D_801E72D0 = (u8 *)func_800D29D4(&D_801D7252[-5], D_801517C0 + 0x70, 0xC, (s32)D_801E72D0);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x190;
        p->unk14 += 0x100;
        if (++p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B0FFC(void) {
    MgTask *p;
    u8 c;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D7270[0] = p->unk16;
    c = 0x80 - p->unk2 * 8;
    D_801D726E = c;
    D_801D726D = c;
    D_801D726C = c;
    D_801E72D0 = func_800D4D90(&D_801D7270[-4], D_801517C0 + 0x70, 0xC, D_801E72D0);
    if (D_80062D98 == 0) {
        p->unk6 -= 300;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 15) {
            p->unk0 = -1;
        }
    }
}

void func_801B10E4(void) {
    MgMat lw;
    MgMat m;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 a;
    s16 k;
    s16 j;
    s32 t;

    D_801D7284.vx = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    D_801D7288 = 0;
    D_801D7286 = p->unk2 << 6;
    func_8003C21C(&D_801D7284, &m);
    D_801D72C0[0] = D_801D72C4 = D_801D72C8 = p->unk2 * 0x7D0;
    func_8003B35C(&m, (MgVec *)D_801D72C0);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801D727E[0] = 0x80 - p->unk2 * 6;
    *(s32 *)&D_801D727E[-5] = (s32)D_801D1AB4;
    D_801E72D0 = (u8 *)func_800D29D4(&D_801D727E[-5], D_801517C0 + 0x70, 0xC, (s32)D_801E72D0);
    func_8003BF8C(&D_801D7284, &m);
    D_801D72C0[0] = D_801D72C4 = D_801D72C8 = p->unk2 * 0x320;
    func_8003B35C(&m, (MgVec *)D_801D72C0);
    m.t[0] = p->unk4;
    m.t[1] = 0;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D727E[0] = 0x80 - p->unk2 * 6;
    *(s32 *)&D_801D727E[-5] = (s32)D_801D1CA8;
    D_801E72D0 = (u8 *)func_800D29D4(&D_801D727E[-5], D_801517C0 + 0x70, 0xC, (s32)D_801E72D0);
    if (D_80062D98 == 0) {
        t = p->unk2;
        k = t * 0xF * 0x10;
        j = t * 0xF0;
        q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0FFC)];
        i = 0;
        do {
            a = func_80042DA8() % 0x1000;
            q->unk4 = func_80039B40(a) * k >> 12;
            q->unk8 = func_80039A74(a) * k >> 12;
            q->unk6 = 0;
            i++;
            q->unk16 = func_80042DA8() % 7;
        } while (i < 2);
        if (!(p->unk2 & 1)) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0E8C)];
            a = func_80042DA8() % 0x1000;
            q->unk4 = func_80039B40(a) * j >> 12;
            q->unk8 = func_80039A74(a) * j >> 12;
            q->unk6 = 0;
            q->unk16 = func_80042DA8() % 4;
            q->unk14 = func_80042DA8() % 0x1000;
        }
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0DD4)];
            a = func_80042DA8() % 0x1000;
            q->unk4 = func_80039B40(a) * j >> 12;
            q->unk8 = func_80039A74(a) * j >> 12;
            i++;
            q->unk6 = 0;
        } while (i < 3);
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B15C4(void) {
    u8 pad[0x30];
    MgTask *p;
    MgTask *q;
    MgTask *r;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((u16)p->unk2 < 8U) {
            q = &D_801621F0[func_800BC04C(func_801B0948)];
            q->unk4 = func_80042DA8() % 6000 - 0xBB8;
            q->unk6 = 0;
            q->unk8 = func_80042DA8() % 6000 - 0xBB8;
            q->unk16 = func_80042DA8() % 2;
            r = (MgTask *)&D_80162978[func_800BBEAC(func_801B071C)];
            r->unk4 = q->unk4;
            r->unk6 = 0;
            r->unk8 = q->unk8;
        }
        if (p->unk2 == 0x14) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0A2C)];
            q->unk4 = 0;
            q->unk6 = -0x4B0;
            q->unk8 = 0;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B10E4)];
            q->unk4 = 0;
            q->unk6 = -0x4B0;
            q->unk8 = 0;
            func_800BBA84(0x164, -1, 0x40);
        }
        if (p->unk2 == 0x20) {
            func_800BBEAC(func_801B063C);
        }
        if (p->unk2 == 0x30) {
            func_800D52A0(0, 0x10);
        }
        if (p->unk2 == 0x3C) {
            i = 0;
            do {
                if ((D_801E72D4 >> i) & 1) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
        }
        p->unk2++;
        if (p->unk2 == 0x46) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B1840(arg0, arg1) {
    MgTask *p;

    func_800BBEAC((void *)func_801B045C);
    func_800D2980(D_801B1934, 0, 0, 0);
    D_801E72D4 = arg0;
    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B15C4)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D54EC(arg0, &p->unkC);
    D_800F5B70 = D_800F5B71 = D_800F5B72 = 0;
    func_800D52A0(0x1000, 0x10);
    return func_800BBA84(0x173, -1, 0x40);
}
