#include "common.h"
#include "magic_dynamite/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B13F8();
    return &D_801C2648;
}

void func_801B0028(s16 mask, MgSVec *out) {
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

void func_801B01D4(s32 base, s16 range, MgSVec *out) {
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

void func_801B0304(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist) {
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

void func_801B0464(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DC8D0 = D_801C48D0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B04D0(s16 *arg0, MgSVec *arg1, s32 arg2) {
    MgSVec rot;
    MgSVec a;
    MgSVec b;
    MgMat m;
    s32 flag;
    s32 ext;
    u8 *q;
    s32 r;
    s32 k;
    s16 i;

    func_8003BF8C(arg1, &m);
    func_8003C8DC((s16)arg2, &m);
    m.t[0] = arg0[0];
    m.t[1] = arg0[1];
    m.t[2] = arg0[2];
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003BADC(&D_801C4858, &a, &flag);
    for (i = 0; i < 10; i++) {
        rot.vx = func_80042DA8() % 0x1000;
        rot.vy = func_80042DA8() % 0x1000;
        rot.vz = 0;
        func_8003C21C(&rot, &m);
        m.t[0] = a.vx;
        m.t[1] = a.vy;
        m.t[2] = a.vz;
        func_8003B48C(&m);
        func_8003B51C(&m);
        D_801C4864 = func_80042DA8() % 100 + 0x64;
        func_8003BADC(&D_801C4860, &b, &flag);
        func_8003B48C(&D_800FA63C);
        func_8003B51C(&D_800FA63C);
        q = D_801DC8D0;
        func_800469D8(q);
        func_80046848(q, 1);
        r = func_8003BBDC(&a, q + 8, &ext, &flag);
        if (r > 0) {
            q[0xD] = 0x40;
            q[0xE] = 0;
            q[6] = 0;
            q[5] = 0;
            q[4] = 0;
            q[0xC] = 0x80;
            func_8003BBDC(&b, q + 0x10, &ext, &flag);
            k = 0x70;
            func_80046794(((r >> 2) << 2) + k + D_801517C0, q);
            D_801DC8D0 = q + 0x14;
        }
        rot.vx = func_80042DA8() % 0x1000;
        rot.vy = func_80042DA8() % 0x1000;
        rot.vz = 0;
        func_8003C21C(&rot, &m);
        func_8003B48C(&m);
        func_8003B51C(&m);
        D_801C4864 = func_80042DA8() % 100 + 0x64;
        func_8003BADC(&D_801C4860, &b, &flag);
        func_8003B48C(&D_800FA63C);
        func_8003B51C(&D_800FA63C);
        q = D_801DC8D0;
        func_80046974(q);
        func_80046848(q, 1);
        r = func_8003BBDC(&b, q + 8, &ext, &flag);
        if (r > 0) {
            q[4] = 0x80;
            q[5] = 0x40;
            q[6] = 0;
            k = 0x70;
            func_80046794(((r >> 2) << 2) + k + D_801517C0, q);
            D_801DC8D0 = q + 0xC;
        }
    }
}

void func_801B0898(void) {
    u8 pad[0x20];
    MgMat m;
    MgMat lw;
    MgObj20 *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    D_801C4888.vz = -t << 9;
    D_801C4888.vy = ((MgTask *)p)->unk14 + 0x400;
    func_8003BF8C(&D_801C4888, &m);
    func_8003B35C(&m, &D_801C4868);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = ((MgTask *)p)->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801DC8D0 = func_800D29D4(&D_801C4878, D_801517C0 + 0x70, 0xC, D_801DC8D0);
    func_801B04D0(&p->unk4, &D_801C4888, 0);
    if (D_80062D98 == 0) {
        p->unk4 += ((MgTask *)p)->unkC;
        p->unk6 += ((MgTask *)p)->unkE;
        ((MgTask *)p)->unk8 += ((MgTask *)p)->unk10;
        ((MgTask *)p)->unkE += 0x14;
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0A30(void) {
    u8 pad[0x20];
    MgMat m;
    MgMat lw;
    MgSVec rot;
    MgSVec pos;
    MgSVec off;
    s32 flag[6];
    MgTask *p;
    s16 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D3994(p->unk1E, D_80151915[p->unk1E][0], &pos);
    rot.vx = D_80151A78[p->unk1E].c[D_80151915[p->unk1E][0]].a;
    rot.vy = D_80151A78[p->unk1E].c[D_80151915[p->unk1E][0]].b;
    rot.vz = D_80151A7C[p->unk1E].c[D_80151915[p->unk1E][0]].a;
    a = D_80151A46[p->unk1E][0];
    func_8003BF8C(&rot, &m);
    func_8003C8DC(a, &m);
    off.vx = 0x14;
    off.vy = -0x32;
    off.vz = -0x1E;
    m.t[0] = pos.vx;
    m.t[1] = pos.vy;
    m.t[2] = pos.vz;
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003BADC(&off, &pos, flag);
    rot.vx -= 0x258;
    rot.vz -= 0x190;
    func_8003BF8C(&rot, &m);
    func_8003C8DC(a, &m);
    func_8003B35C(&m, &D_801C4890);
    m.t[0] = pos.vx;
    m.t[1] = pos.vy;
    m.t[2] = pos.vz;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801DC8D0 = func_800D29D4(&D_801C48A0, D_801517C0 + 0x70, 0xC, D_801DC8D0);
    if (p->unk2 >= 0x19) {
        func_801B04D0(&pos, &rot, a);
    }
    if (D_80062D98 == 0) {
        if (++p->unk2 == 0x35) {
            p->unk0 = -1;
        }
    }
}

void func_801B0DB4(void) {
    MgMat lw;
    MgMat m;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    u8 *rgb;
    s16 i;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[2][i] = 0;
        m.m[1][i] = 0;
        m.m[0][i] = 0;
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
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x800;
    func_8003C21C(&rot, &lw);
    func_8003B05C(&m, &lw);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801C48B8 = p->unk1A;
    D_801C48B7 = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801C48B4;
    *rgb = D_801C48B5 = D_801C48B6 = n << 4;
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
        p->unk16 += 0x200;
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0FD0(void) {
    MgMat sp10;
    MgMat sp30;
    MgSVec rot;
    u8 pad[0x18];
    s32 scale[3];
    MgObj20 *p;
    s32 t;
    s16 *frame;

    p = &D_80162978[D_8015169C];
    rot.vy = p->unk2 * 0x20;
    rot.vz = 0;
    rot.vx = 0;
    func_8003BF8C(&rot, &sp10);
    t = p->unk2 * 0xC8 + 0x400;
    scale[2] = t;
    scale[1] = t;
    scale[0] = t;
    func_8003B35C(&sp10, scale);
    sp10.t[0] = p->unk4;
    sp10.t[1] = p->unk6;
    sp10.t[2] = ((MgTask *)p)->unk8;
    func_8003A63C(&D_800FA63C, &sp10, &sp30);
    func_8003B48C(&sp30);
    func_8003B51C(&sp30);
    frame = &D_801C48CA;
    *frame = p->unk2 * 0x78;
    D_801DC8D0 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801DC8D0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B111C(void) {
    MgTask *p;
    MgTask *q;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x11) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0A30)];
            q->unk1E = p->unk1E;
        }
        if (p->unk2 == 0x2A) {
            func_800BBA84(0x116, p->unk1E, 0x40);
        }
        if (p->unk2 == 0x46) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0898)];
            func_800D3994(p->unk1E, D_8015190F[p->unk1E][9], &q->unk4);
            q->unk14 = func_8003CC1C(p->unkC - q->unk4, p->unk10 - q->unk8);
            q->unkC = (p->unkC - q->unk4) / 20;
            q->unkE = -0xC8;
            q->unk10 = (p->unk10 - q->unk8) / 20;
        }
        if (p->unk2 == 0x6E) {
            i = 0;
            do {
                if (D_801DC8D4 >> i & 1) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
        }
        if (p->unk2 == 0x5A) {
            i = 0;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0FD0)];
            q->unk4 = p->unkC;
            q->unk6 = 0;
            q->unk8 = p->unk10;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0DB4)];
                q->unk4 = p->unkC;
                q->unk8 = p->unk10;
                q->unk6 = 0;
                func_801B01D4(-0x12C, 0x32, (MgSVec *)&q->unkC);
                i++;
                q->unk1A = func_80042DA8() % 3;
            } while (i < 0x14);
            func_800BBA84(0xFA, -1, 0x40);
        }
        if (++p->unk2 == 0x78) {
            p->unk0 = -1;
        }
    }
}

void func_801B13F8(arg0, arg1) {
    MgObj20 *p;

    func_800BBEAC(func_801B0464);
    D_801DC8D4 = arg0;
    func_800D2980(&D_801B1484, 0, 0, 0);
    p = &D_80162978[func_800BBEAC(func_801B111C)];
    func_800D54EC(arg0, &p->pad[4]);
    ((MgTask *)p)->unk1E = arg1;
}
