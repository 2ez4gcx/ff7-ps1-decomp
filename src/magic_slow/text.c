#include "common.h"
#include "magic_slow/decls.h"

void func_801B0000(void) {
    func_801B07FC();
}

void func_801B0020(void *arg0, void *arg1, s32 arg2) {
    MgSVec *p;
    MgSVec *q;
    s32 i;

    p = arg0;
    q = arg1;
    for (i = 0; i < 0x112; i++) {
        D_801BA88C[i].x = (q->vx - p->vx) / arg2;
        D_801BA88C[i].y = (q->vy - p->vy) / arg2;
        D_801BA88C[i].z = (q->vz - p->vz) / arg2;
        p++;
        q++;
    }
}

void func_801B013C(void *arg0) {
    SlowVtx *p;
    s32 i;

    p = arg0;
    for (i = 0; i < 0x112; i++) {
        p->x += D_801BA88C[i].x;
        p->y += D_801BA88C[i].y;
        p->z += D_801BA88C[i].z;
        p++;
    }
}

void func_801B01B8(void) {
    MgMat m;
    MgMat m2;
    MgSVec rot;
    MgVec sc;
    MgVec a;
    MgVec b;
    MgVec c;
    MgTask *p;
    u16 *r;
    s32 t;
    s32 i;
    s32 s;
    s32 u;
    s32 v;
    s32 k;
    s32 col;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x1E) {
        if (D_80062D98 == 0) {
            if (t == 0) {
                func_801B0020(D_801B4A8C, D_801B96E0, 0x1E);
            }
            u = 0;
            func_801B013C(D_801B4A8C);
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
        }
        u = 0;
        s = 0;
        sc.vz = 0x1000;
        sc.vy = 0x1000;
        sc.vx = 0x1000;
    } else {
        t -= 0x1E;
        u = 0;
        if (t < 0xF) {
            s = 0;
            sc.vz = 0x1000;
            sc.vy = 0x1000;
            sc.vx = 0x1000;
        } else {
            t -= 0xF;
            if (t < 0xF) {
            if (D_80062D98 == 0) {
                if (t == 0) {
                    func_801B0020(D_801B4A8C, D_801B9F70, 0xF);
                    for (i = 0; i < 10; i++) {
                        if ((D_801BB11C >> i) & 1) {
                            func_800D5774(i);
                        }
                    }
                    D_801BA868 = 0;
                    D_801BA866 = 0;
                    D_801BA864 = 0;
                }
                func_801B013C(D_801B4A8C);
                r = &D_801BA864;
                *r += 0x104;
                D_801BA866 += 0x87;
            }
            s = 8;
            u = (t << 12) / 15;
            v = (t * 0x3000) / 15 + 0x1000;
            sc.vz = v;
            sc.vy = v;
            sc.vx = v;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801BB128.t[0] = p->unk4;
    D_801BB128.t[1] = p->unk6;
    D_801BB128.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801BB128, &m);
    t = p->unk2;
    if (t >= 0x1E) {
        t -= 0x1E;
        if (t < 0xF) {
            k = 0xF - t;
            a.vx = ((t << 12) + m.m[0][0] * k) / 15;
            a.vy = (m.m[1][0] * k) / 15;
            a.vz = (m.m[2][0] * k) / 15;
            func_8003A08C(&a, &a);
            m.m[0][0] = a.vx;
            m.m[1][0] = a.vy;
            m.m[2][0] = a.vz;
            b.vy = m.m[1][1];
            b.vz = m.m[2][1];
            b.vx = (m.m[0][1] * k) / 15;
            func_8003A08C(&b, &b);
            m.m[0][1] = b.vx;
            m.m[1][1] = b.vy;
            m.m[2][1] = b.vz;
            func_8003BA10(&a, &b, &c);
            func_8003A08C(&c, &c);
            m.m[0][2] = c.vx;
            m.m[1][2] = c.vy;
            m.m[2][2] = c.vz;
        } else {
            m.m[0][0] = 0x1000;
            a.vx = 0x1000;
            m.m[2][0] = 0;
            a.vz = 0;
            m.m[1][0] = 0;
            a.vy = 0;
            b.vx = 0;
            b.vy = m.m[1][1];
            b.vz = m.m[2][1];
            func_8003A08C(&b, &b);
            m.m[0][1] = b.vx;
            m.m[1][1] = b.vy;
            m.m[2][1] = b.vz;
            func_8003BA10(&a, &b, &c);
            func_8003A08C(&c, &c);
            m.m[0][2] = c.vx;
            m.m[1][2] = c.vy;
            m.m[2][2] = c.vz;
            func_8003C21C((MgSVec *)&D_801BA864, &m2);
            func_8003B05C(&m, &m2);
        }
    }
    func_8003B35C(&m, &sc);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    col = s | 0x80;
    D_801BA86C.unk4 = col;
    D_801BA86C.unkA = u;
    D_801DB148 = func_800D29D4(&D_801BA86C, D_801517C0 + 0x70, 0xC, D_801DB148);
    rot.vy = 0;
    rot.vx = 0;
    rot.vz = -(p->unk2 << 8);
    func_8003C21C(&rot, &m2);
    m2.t[2] = 0;
    m2.t[1] = 0;
    m2.t[0] = 0;
    func_8003A63C(&m, &m2, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    func_8003B69C(0, 0, 0);
    D_801BA87C.unk4 = col;
    D_801BA87C.unkA = u;
    D_801DB148 = func_800D29D4(&D_801BA87C, D_801517C0 + 0x70, 0xC, D_801DB148);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B079C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DB148 = D_801BB148 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B07FC(arg0) {
    MgSVec a;
    MgSVec b;
    MgMat m;
    MgVec v;
    s32 flag;
    MgTask *q;
    u16 *g;
    s32 i;
    s32 t;
    s32 *d;
    s32 *s;

    func_800D2980(D_801B0A28, 0, 0, 0);
    func_800BBEAC(func_801B079C);
    s = D_801B6C6C;
    d = D_801B4A88;
    for (i = 0; i < 0x21E4; i += 4) {
        *d = *s;
        s++;
        d++;
    }
    D_801BB11C = arg0;
    func_800D54EC(arg0, &D_801BB120);
    q = (MgTask *)&D_80162978[func_800BBEAC(func_801B01B8)];
    func_8003BC6C((MgSVec *)&D_801BB120, &v, &flag);
    if (v.vx < 0) {
        a.vx = 0x7D0;
    } else {
        a.vx = -0x7D0;
    }
    if (v.vy < 0) {
        a.vy = 0x3E8;
    } else {
        a.vy = -0x3E8;
    }
    g = &D_800FA650;
    a.vx -= *g;
    a.vy -= D_800FA654;
    a.vz = -D_800FA658;
    func_8003BF3C((MgSVec *)(g - 10), &m);
    func_8003B2CC(&m, &a, (MgSVec *)&q->unk4);
    b.vx = q->unkC = (D_801BB120 - q->unk4) / 30;
    t = q->unk6 + 0x3E8;
    b.vy = q->unkE = (D_801BB122 - t) / 30;
    b.vz = q->unk10 = (D_801BB124.v - q->unk8) / 30;
    func_800D44E8(&b, &D_801BB128);
    return func_800D55F4(0x20, func_800D574C(arg0), 0x41);
}
