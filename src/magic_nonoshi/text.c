#include "common.h"
#include "magic_nonoshi/decls.h"

void func_801B0000(void) {
    func_801B2400();
}

INCLUDE_ASM("../asm/us/magic_nonoshi/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_nonoshi/nonmatchings/text", func_801B0A48);

void func_801B1158(s16 mask, MgSVec *out) {
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

void func_801B1304(s32 base, s16 range, MgSVec *out) {
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

void func_801B1434(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist) {
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

void func_801B1594(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DE41C = D_801C641C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B1600(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x1000, 0);
    D_801C5BA4[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801C5BA4[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C5938) {
            p->unk0 = -1;
        }
    }
}

void func_801B16BC(void) {
    MgTask *p;
    s16 t;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801C5BB0[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801C5BB0[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x14;
        t = p->unk2 + 1;
        p->unk2 = t;
        if (t >= D_801C5870) {
            p->unk0 = -1;
        }
    }
}

void func_801B1784(void) {
    s16 i;

    i = 0;
    do {
        D_801C5C1C[i][0] = D_801C5C1C[i][1] = D_801C5C1C[i][2] = 0;
        func_801B1304(-0x96, 0x32, (MgSVec *)D_801C601C[i]);
        i++;
    } while (i < 0x80);
}

void func_801B1818(void) {
    s16 i;

    i = 0;
    do {
        D_801C5C1C[i][0] += D_801C601C[i][0];
        D_801C5C1C[i][1] += D_801C601C[i][1];
        D_801C5C20[i][0] += D_801C6020[i][0];
        D_801C601C[i][1] += 0x14;
        if (D_801C5C1C[i][1] > 0) {
            D_801C5C1C[i][1] = 0;
            D_801C601C[i][1] = -D_801C601C[i][1];
        }
        i++;
    } while (i < 0x80);
}

void func_801B1954(void) {
    MgVec s;
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 *frame;
    u8 *q;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801C5BC4, &m);
    s.vx = s.vy = s.vz = p->unk2 * 0x640;
    func_8003B35C(&m, &s);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    frame = &D_801C5BBE;
    q = (u8 *)frame - 0xA;
    *frame = 0x80 - p->unk2 * 6;
    D_801DE41C = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801DE41C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B1AA8(void) {
    MgMat lw;
    MgMat m;
    MgMat rm;
    MgSVec rot;
    MgTask *p;
    s16 *frame;
    u8 *q;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801C5BEC, &m);
    func_8003B35C(&m, &D_801C5BDC);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B69C(0, 0, 0);
    rot.vx = p->unk2 << 9;
    rot.vz = 0;
    rot.vy = 0;
    func_8003C21C(&rot, &rm);
    frame = &D_801C5BD6;
    q = (u8 *)frame - 0xA;
    *frame = p->unk2 * 0xC8;
    D_801DE41C = func_801B0020(q, D_801517C0 + 0x70, 0xC, D_801DE41C, D_801C5C1C, &lw, &rm);
    if (D_80062D98 == 0) {
        func_801B1818();
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B1C0C(void) {
    MgMat lw;
    MgVec s;
    MgSVec v;
    MgSVec rot;
    MgMat m;
    u8 pad[32];
    MgTask *p;
    MgTask *q;
    s32 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    v.vx = func_80039A74(p->unk14) * p->unk18 >> 12;
    v.vz = func_80039B40(p->unk14) * p->unk18 >> 12;
    rot.vx = p->unk1C;
    rot.vy = p->unk14;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    s.vx = s.vy = s.vz = p->unk1A;
    func_8003B35C(&m, &s);
    m.t[0] = p->unk4 + v.vx;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8 + v.vz;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B69C(0, 0, 0);
    frame = &D_801C5BF4;
    *frame = D_801C5C04[p->unk16];
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801DE41C = func_800D29D4(frame, D_801517C0 + 0x70, 0xC, D_801DE41C);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x14) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unk1A += 0xC0;
            p->unk18 = (u32)(func_80039A74(p->unk2 * 0x3C) * 0x7D) >> 9;
            p->unk1C += 0xBE;
        }
        if ((u16)(p->unk2 - 0x14) < 0x15U) {
            p->unk18 -= 0x1E;
        }
        if (p->unk2 == 0x28 && p->unk16 == 4) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1AA8)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            D_801C5B98 = 1;
            q->unk8 = p->unk8;
            q->unk6 += 0xC8;
        }
        if (D_801C5B98 == 1) {
            p->unk0 = -1;
        }
        p->unk14 += 0x100;
        p->unk2++;
    }
}

void func_801B1EE0(void) {
    MgTask *p;
    MgTask *q;
    u8 pad[8];
    s16 i;
    s32 r;
    s32 t;
    s32 r2;
    s32 t2;
    s32 r3;
    s32 t3;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 0xF && p->unk2 % 3 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B1C0C)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unkC = (p->unkC - p->unk4) / 20;
            q->unkE = (p->unkE - p->unk6) / 20;
            q->unk10 = (p->unk10 - p->unk8) / 20;
            q->unk14 = 0;
            q->unk18 = 0;
            q->unk1C = 0;
            q->unk1A = 0x400;
            q->unk16 = p->unk2 / 3;
            q = (MgTask *)&D_801621F0[func_800BC04C(func_801B16BC)];
            q->unk4 = (u16)p->unk4 + func_80042DA8() % 400 - 0xC8;
            q->unk6 = (u16)p->unk6 + func_80042DA8() % 400 - 0xC8;
            q->unk8 = (u16)p->unk8 + func_80042DA8() % 400 - 0xC8;
        }
        if (p->unk2 == 0x32) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B1954)];
            q->unk4 = p->unkC;
            q->unk6 = p->unkE;
            q->unk8 = p->unk10;
            if (p->unk2 == 0x32) {
                func_800D5774(p->unk1C);
            }
        }
        if ((u16)(p->unk2 - 0x29) < 7U) {
            i = 0;
            do {
                q = (MgTask *)&D_801621F0[func_800BC04C(func_801B1600)];
                func_800D3994(p->unk1C, D_8015190F[D_800FA6D4][0], &q->unk4);
                r = func_80042DA8();
                t = (u16)q->unk4 - 0x1F4;
                q->unk4 = t + r % 1000;
                r2 = func_80042DA8();
                t2 = (u16)q->unk6 - 0x1F4;
                q->unk6 = t2 + r2 % 1000;
                i++;
                r3 = func_80042DA8();
                t3 = (u16)q->unk8 - 0x1F4;
                q->unk8 = t3 + r3 % 1000;
            } while (i < 2);
        }
        p->unk2++;
        if (p->unk2 == 0x50) {
            p->unk0 = -1;
        }
    }
}

void func_801B2340(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B1EE0)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B2400(arg0, arg1) {
    func_800BBEAC((M2C_UNK *)func_801B1594);
    func_800D2980(&D_801B2484, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, (M2C_UNK *)func_801B2340);
    func_800BBA84(0x121, arg1, 0x40);
    func_801B1784();
}
