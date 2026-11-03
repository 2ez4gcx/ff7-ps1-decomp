#include "common.h"
#include "magic_s_beam/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B2220();
    return &D_801C3740;
}

void func_801B0028(void) {
    MgTask *p;
    u16 *v;
    u16 *b;
    s32 *otz;
    s32 *fl;
    BmLine *pk;
    s32 t;
    s32 n;
    u16 c;
    s32 r;

    otz = (s32 *)0x1F800008;
    fl = (s32 *)0x1F80000C;
    b = (u16 *)0x1F800010;
    p = (MgTask *)&D_80162978[D_8015169C];
    v = (u16 *)0x1F800000;
    t = p->unk2;
    if (t < 5) {
        s32 ax;
        s32 ay;
        s32 az;
        s32 u;
        s32 w;
        s16 *h;

        h = &p->unk10;
        ax = p->unkC;
        u = (t << 12) / 5;
        w = 0x1000 - u;
        ax = (u32)(ax * u + p->unk4 * w) >> 12;
        v[0] = ax;
        *(s16 *)((u8 *)p + 4) = ax;
        ay = (u32)(p->unkE * u + p->unk6 * w) >> 12;
        *(u16 *)0x1F800002 = ay;
        p->unk6 = ay;
        az = (u32)(*h * u + p->unk8 * w) >> 12;
        *(u16 *)0x1F800004 = az;
        p->unk8 = az;
        r = 0x140;
    } else {
        n = t - 5;
        if (n < 5) {
            c = p->unkC;
            v[0] = c;
            c = p->unkE;
            *(u16 *)0x1F800002 = c;
            c = p->unk10;
            *(u16 *)0x1F800004 = c;
            r = -(n * 0x130) / 5 + 0x140;
        } else {
            r = 0x10;
            if (p->unk0 + t < 0x41) {
                c = p->unkC;
                v[0] = c;
                c = p->unkE;
                *(u16 *)0x1F800002 = c;
                c = p->unk10;
                *(u16 *)0x1F800004 = c;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BBDC(v, b, otz, fl);
    if (!(*fl & 0x60000)) {
        s32 lo;
        s32 hi;

        pk = (BmLine *)D_801E5640;
        pk->w0 = 0x03000000;
        pk->w1 = 0x40FFFFFF;
        pk->x0 = pk->x1 = b[0];
        lo = (s16)b[1] - r;
        if (lo < 0) {
            lo = 0;
        }
        pk->y0 = lo;
        hi = (s16)b[1] + r;
        if (hi >= 0xA7) {
            hi = 0xA6;
        }
        pk->y1 = hi;
        func_80046794(D_801517C0 + 0x4084, (u8 *)pk);
        pk++;
        pk->w0 = 0x03000000;
        pk->w1 = 0x40FFFFFF;
        pk->y0 = pk->y1 = b[1];
        lo = (s16)b[0] - r;
        if (lo < 0) {
            lo = 0;
        }
        pk->x0 = lo;
        hi = (s16)b[0] + r;
        if (hi >= 0x141) {
            hi = 0x140;
        }
        pk->x1 = hi;
        func_80046794(D_801517C0 + 0x4084, (u8 *)pk);
        D_801E5640 = (u8 *)(pk + 1);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B03A0);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B072C);

void func_801B0A5C(void) {
    MgTask *p;
    MgTask *q;
    MgSVec *sv;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        sv = (MgSVec *)0x1F800020;
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B0028)];
            q->unk0 = p->unk0 + p->unk2;
            func_8003BF3C(&D_800FA63C, (MgMat *)0x1F800000);
            sv->vx = (u16)D_801C5560.vx - (u16)D_800FA63C.t[0];
            *(s16 *)0x1F800022 = (u16)D_801C5560.vy - (u16)D_800FA63C.t[1];
            *(s16 *)0x1F800024 = (u16)D_801C5560.vz - (u16)D_800FA63C.t[2];
            func_8003B2CC((MgMat *)0x1F800000, sv, &q->unk4);
            *(MgB8 *)&q->unkC = *(MgB8 *)&p->unk4;
        }
        if (p->unk2 == 5) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B03A0)];
            q->unk0 = p->unk0 + p->unk2;
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
        }
        if (p->unk2 == 5) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B072C)];
            q->unk0 = p->unk0 + p->unk2;
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unkC = func_80042DA8() % 40 + 0x50;
            q->unkE = func_80042DA8() % 30 + 0x3C;
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0CC8(void) {
    MgTask *p;
    MgTask *q;
    s16 id;
    s16 r;
    s16 id2;
    s32 m;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4484(D_801517C0 + 0x4088, 0x20);
    func_80046794(D_801517C0 + 0x4088, D_801C5568 + D_800F8368 * 0x10);
    func_800D4484(D_801517C0 + 0x4088, 0x40);
    if (D_80062D98 == 0) {
        id = p->unk0;
        m = D_801C5638;
        if (m >= 1 << id) {
            r = p->unk2 % 5;
            if (r == 0) {
                if (!(m >> id & 1)) {
                    do {
                        n = id + 1;
                        p->unk0 = n;
                        id = n;
                    } while (!(m >> n & 1));
                }
                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B0A5C)];
                q->unk0 = p->unk2;
                id2 = p->unk0;
                func_800D3994(id2, D_8015190F[id2][0], &q->unk4);
                p->unk0++;
            }
        }
        if (p->unk2 >= 0x41) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0E84(void) {
    MgTask *p;
    MgMat *m;
    MgVec *sv;
    s32 t;
    s32 u;

    sv = (MgVec *)0x1F800020;
    p = (MgTask *)&D_80162978[D_8015169C];
    m = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 10) {
        *(s32 *)0x1F800024 = sv->vx = *(s32 *)0x1F800028 = 0x800;
    } else {
        t -= 10;
        if (t < 5) {
            *(s32 *)0x1F800024 = 0x800;
            u = -(t << 11) / 5 + 0x800;
            sv->vx = *(s32 *)0x1F800028 = u;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003C21C(&p->unkC, m);
    m->t[0] = p->unk4;
    m->t[1] = p->unk6;
    m->t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, m, m);
    func_800D461C(m);
    func_8003B35C(m, sv);
    func_8003A08C((MgVec *)m->t, sv);
    m->t[0] -= p->unk18 * sv->vx >> 12;
    m->t[1] -= p->unk18 * sv->vy >> 12;
    m->t[2] -= p->unk18 * sv->vz >> 12;
    func_8003B48C(m);
    func_8003B51C(m);
    D_801E5640 = func_800D29D4(&D_801C5588, D_801517C0 + 0x70, 0xC, D_801E5640);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1084(void) {
    MgTask *p;
    MgMat *m;
    MgMat *n;
    MgVec *sv;
    s32 t;
    s32 u;

    sv = (MgVec *)0x1F800020;
    n = (MgMat *)0x1F800030;
    p = (MgTask *)&D_80162978[D_8015169C];
    m = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 5) {
        D_801C55A2 = 0;
    } else {
        t -= 5;
        if (t < 0xF) {
            D_801C55A2 = (t << 12) / 15;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    u = (p->unk2 << 12) / 20;
    sv->vx = sv->vy = sv->vz = u;
    func_8003C21C(&p->unkC, m);
    m->t[0] = p->unk4;
    m->t[1] = p->unk6;
    m->t[2] = p->unk8;
    func_8003B35C(m, sv);
    func_8003A63C(&D_800FA63C, m, n);
    func_8003B48C(n);
    func_8003B51C(n);
    func_8003B69C(0, 0, 0);
    D_801C5598[0] = &D_801C3288;
    D_801E5640 = func_800D29D4((u8 *)D_801C5598, D_801517C0 + 0x70, 0xC, D_801E5640);
    D_801C5598[0] = &D_801C2F1C;
    D_801E5640 = func_800D29D4((u8 *)D_801C5598, D_801517C0 + 0x70, 0xC, D_801E5640);
    func_8003C21C((s16 *)&D_801C55A8, m);
    u = sv->vx * 2;
    sv->vx = sv->vy = sv->vz = u;
    func_8003B35C(m, sv);
    func_8003A63C(&D_800FA63C, m, n);
    func_8003B48C(n);
    D_801C5598[0] = &D_801C284C;
    D_801E5640 = func_800D29D4((u8 *)D_801C5598, D_801517C0 + 0x70, 0xC, D_801E5640);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1304(void) {
    MgTask *p;
    s16 *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    q = &D_801C55BA;
    *q = (p->unk2 << 12) / 3;
    D_801C55C0.m[0][0] = D_801C55C0.m[1][1] = D_801C55C0.m[2][2] = p->unk16;
    D_801C55C0.t[0] = p->unk4;
    D_801C55C0.t[1] = p->unk6;
    D_801C55C0.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801C55C0, (MgMat *)0x1F800000);
    func_8003B48C((MgMat *)0x1F800000);
    func_8003B51C((MgMat *)0x1F800000);
    func_8003B69C(0, 0, 0);
    D_801E5640 = func_800D29D4((u8 *)q - 0xA, D_801517C0 + 0x70, 0xC, D_801E5640);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 3) {
            p->unk0 = -1;
        }
    }
}

void func_801B144C(void) {
    MgTask *p;
    MgTask *q;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B1304)];
        *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
        q->unk16 = p->unk2 * 0xC00 / 13 + 0x400;
        t = p->unk2;
        if (t >= 0xB) {
            q->unk2 = t - 10;
        }
        p->unk6 -= 0x64;
        p->unk2++;
        if (p->unk2 >= 0xD) {
            p->unk0 = -1;
        }
    }
}

void func_801B1550(void) {
    MgTask *p;
    MgMat *m;
    MgSVec *sv;
    s32 t;
    s32 c;

    sv = (MgSVec *)0x1F800020;
    p = (MgTask *)&D_80162978[D_8015169C];
    m = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 10) {
        *(s32 *)&D_801C55E4 = 0x2C808080;
    } else {
        t -= 10;
        if (t < 5) {
            D_801C55E7 = 0x2E;
            c = -(t << 7) / 5 - 0x80;
            D_801C55E4 = D_801C55E5 = D_801C55E6 = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    sv->vx = (u16)p->unk2 * (u16)p->unk16;
    sv->vy = (u16)p->unk2 * (u16)p->unk18;
    sv->vz = 0;
    func_8003C21C(sv, m);
    m->t[0] = p->unk4;
    m->t[1] = p->unk6;
    m->t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    D_801E5640 = func_800D4D90(&D_801C55E0, D_801517C0 + 0x70, 0xC, D_801E5640);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC = p->unkC * 15 >> 4;
        p->unkE = (p->unkE * 15 >> 4) + 0x3C;
        p->unk10 = p->unk10 * 15 >> 4;
    }
}

void func_801B1760(void) {
    MgTask *p;
    s16 *q;
    s32 t;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = (p->unk2 << 12) / 10;
    q = &D_801C55F6;
    *q = -(t << 7) >> 12;
    *q += 0x80;
    t = (t * 0xE00 >> 12) + 0x200;
    k = (u32)(p->unk16 * t) >> 12;
    D_801C55FC.m[0][0] = D_801C55FC.m[1][1] = D_801C55FC.m[2][2] = k;
    D_801C55FC.t[0] = p->unk4;
    D_801C55FC.t[1] = 0;
    D_801C55FC.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801C55FC, D_801C561C);
    func_8003B48C(D_801C561C);
    func_8003B51C(D_801C561C);
    D_801E5640 = func_800D29D4((u8 *)q - 0xA, D_801517C0 + 0x406C, 0, D_801E5640);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B18D8(void) {
    MgTask *p;
    MgTask *q;
    MgSVec *rot;
    MgMat *m;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        m = (MgMat *)0x1F800008;
        rot = (MgSVec *)0x1F800000;
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B0E84)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unk6 = 0;
            q->unkE = 0;
            q->unk10 = 0;
            q->unk18 = -0x3E8;
            q->unkC = D_801E5644;
        }
        if (p->unk2 == 1) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B1084)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unkC = 0;
            q->unkE = 0;
            q->unk10 = 0;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B144C)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            i = 0;
            do {
                i++;
                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B1550)];
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                rot->vx = 0;
                rot->vy = func_80042DA8() & 0xFFF;
                rot->vz = -((func_80042DA8() & 0x1FF) + 0x200);
                func_8003C21C(rot, m);
                rot->vx = func_80042DA8() % 300 + 0x1F4;
                rot->vy = 0;
                rot->vz = 0;
                func_8003B2CC(m, rot, &q->unkC);
                q->unk16 = func_80042DA8() & 0x3F;
                q->unk18 = func_80042DA8() & 0x3F;
            } while (i < 0xF);
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B1760)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unk16 = 0x2000;
            if (p->unk14 != -1) {
                func_800D5774(p->unk14);
            }
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B1BA4(void) {
    MgTask *p;
    MgMat *m;
    MgVec *sv;
    s32 t;
    s32 u;

    sv = (MgVec *)0x1F800020;
    p = (MgTask *)&D_80162978[D_8015169C];
    m = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 5) {
        sv->vx = *(s32 *)0x1F800028 = 0x200;
        *(s32 *)0x1F800024 = 0x800;
    } else {
        t -= 5;
        if (t < 5) {
            *(s32 *)0x1F800024 = 0x800;
            u = -(t << 9) / 5 + 0x200;
            sv->vx = *(s32 *)0x1F800028 = u;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003C21C(&p->unkC, m);
    m->t[0] = p->unk4;
    m->t[1] = p->unk6;
    m->t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, m, m);
    func_800D461C(m);
    func_8003B35C(m, sv);
    func_8003A08C((MgVec *)m->t, sv);
    m->t[0] -= p->unk18 * sv->vx >> 12;
    m->t[1] -= p->unk18 * sv->vy >> 12;
    m->t[2] -= p->unk18 * sv->vz >> 12;
    func_8003B48C(m);
    func_8003B51C(m);
    D_801E5640 = func_800D29D4(&D_801C5620, D_801517C0 + 0x70, 0xC, D_801E5640);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1DA8(void) {
    MgTask *p;
    MgTask *q;
    MgTask *r;
    s16 n;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = p->unk2 % 3;
        if (n == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B1BA4)];
            k = 0xBB8;
            q->unk4 = *(u16 *)&D_801C5630 - k + func_80042DA8() % 6000;
            q->unk6 = 0;
            q->unk8 = D_801C5634 - k + func_80042DA8() % 6000;
            q->unk18 = -0x12C;
            q->unkE = 0;
            q->unk10 = 0;
            q->unkC = D_801E5644;
            r = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B1760)];
            *(MgB8 *)&r->unk4 = *(MgB8 *)&q->unk4;
            r->unk16 = 0x800;
        }
        p->unk2++;
        if (p->unk2 >= 0x21) {
            p->unk0 = -1;
        }
    }
}

void func_801B1F78(arg0) {
    MgTask *q;
    s32 k;

    q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B18D8)];
    if (D_801C5638 >> arg0 & 1) {
        func_800D3994(arg0, D_8015190F[arg0][0], &q->unk4);
        q->unk6 = 0;
        q->unk18 = D_801518F6[arg0][0];
        q->unk14 = arg0;
    } else {
        k = 0xBB8;
        q->unk4 = *(u16 *)&D_801C5630 - k + func_80042DA8() % 6000;
        q->unk6 = 0;
        q->unk8 = D_801C5634 - k + func_80042DA8() % 6000;
        q->unk18 = 0x3E8;
        q->unk14 = -1;
    }
}

void func_801B20EC(void) {
    MgObj20 *p;
    MgObj20 *q;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x12) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)&func_801B0CC8)];
            q->unk0 = 0;
            func_800D55F4(0x20, 0x40, 0x246);
        }
        if (p->unk2 == 0x5A) {
            func_800D5444(0x3F0, 0, 5, func_801B1F78);
            func_800BBEAC((M2C_UNK *)&func_801B1DA8);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B21C0(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E5640 = D_801C5640 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B2220(arg0, arg1) {
    s32 t;
    s32 k;

    D_801C5638 = arg0;
    D_801C563C = (func_800D54BC() - 1) * 5 + 0x17;
    func_800D54EC(arg0, &D_801C5630);
    func_800D2980(&D_801B2308, 0, 0, 0);
    func_800BBEAC((M2C_UNK *)&func_801B21C0);
    func_800BBEAC((M2C_UNK *)&func_801B20EC);
    t = D_80151A46[arg1][0] + 0x400 < 0x800;
    k = 0x100;
    if (t) {
        k = -0x100;
    }
    D_801E5644 = k;
}
