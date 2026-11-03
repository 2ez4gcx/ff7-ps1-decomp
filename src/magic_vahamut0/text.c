#include "common.h"
#include "magic_vahamut0/decls.h"

M2C_UNK *func_801B0060(void) {
    func_801B7920();
    return &D_801D823C;
}

MgMat *func_801B0088(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801FC8E0.m[0][0] = D_801FC8E0.m[1][1] = D_801FC8E0.m[2][2] = scale;
    func_8003B48C(&D_801FD11C);
    func_8003B51C(&D_801FD11C);
    func_8003BC6C(v, (MgVec *)D_801FC8E0.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801FC8E0.t, &n);
        D_801FC8E0.t[0] += (dist * n.vx) >> 12;
        D_801FC8E0.t[1] += (dist * n.vy) >> 12;
        D_801FC8E0.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801FC8E0);
    func_8003B51C(&D_801FC8E0);
    return &D_801FC8E0;
}

s32 func_801B01A4(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801FD13E[-v];
    }
    return v;
}

s32 func_801B01E0(s32 a, s32 b) {
    s32 i;
    s32 n;
    s32 orig;

    orig = a;
    if (b > 0) {
        n = b >> 8;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
    } else if (b < 0) {
        b = -b;
        n = b >> 8;
        a = 0x1000 - a;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
        a = 0x1000 - a;
    } else {
        return a;
    }
    n = (b & 0xFF) + 1;
    a = (a * n + orig * (0x100 - n)) >> 8;
    return a;
}

void func_801B02D8(s32 arg0, s32 arg1, MgTask *arg2, MgSVec *arg3) {
    MgMat m;

    if (arg1 != -1) {
        func_800D3994(arg0, arg1, arg3);
    } else {
        arg3->vx = D_80151A4C[arg0][0];
        arg3->vy = D_80151A4C[arg0][1];
        arg3->vz = D_80151A50[arg0][0];
    }
    arg3->vx -= arg2->unk14;
    arg3->vy -= arg2->unk18;
    arg3->vz -= arg2->unk1C;
    func_8003BF3C(arg2, &m);
    func_8003B2CC(&m, arg3, arg3);
}

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B03D4);

void func_801B13AC(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B03D4)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B1410);

void func_801B24A4(void) {
    s32 i;
    s32 *p;

    i = 0x1F3;
    p = D_801FD924;
    do {
        *p = 0;
        i--;
        p--;
    } while (i >= 0);
}

MgObj20 *func_801B24C8(s32 arg0) {
    s32 i;
    MgObj20 *p;

    p = D_801FD154;
    for (i = 0; i < 500; i++) {
        if (D_801FD158[i] == 0) {
            D_801FD158[i] = arg0;
            p[i].unk0 = 0;
            p[i].unk2 = 0;
            return &p[i];
        }
    }
    return 0;
}

void func_801B251C(void) {
    MgTask *p;
    s32 n;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    n = 0;
    for (i = 0; i < 500; i++) {
        if (D_801FD158[i] != 0) {
            ((void (*)(MgObj20 *))D_801FD158[i])(&D_801FD154[i]);
            if (D_801FD154[i].unk0 == -1) {
                D_801FD158[i] = 0;
            } else {
                n++;
            }
        }
    }
    if (n == 0 && D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B2610);

void func_801B2888(void) {
    MgTask *p;
    Vh0Eff *s;
    s32 t;
    s32 c;
    s32 e;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x6E) {
        D_801FCC12 = 0;
        D_801FCC02 = 0;
    } else {
        t -= 0x6E;
        if (t < 0x5A) {
            e = 0x1000;
            D_801FCC12 = e;
            D_801FCC02 = e;
        } else {
            t -= 0x5A;
            if (t < 0x37) {
                c = 0x1000 - (t << 12) / 55;
                D_801FCC12 = c;
                D_801FCC02 = c;
            } else {
                t -= 0x37;
                if (t < 0x127) {
                    D_801FCC12 = 0;
                    D_801FCC02 = 0;
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
        }
    }
    func_8003C21C((MgSVec *)&p->unk4, &D_801FCC38->m);
    s = D_801FCC38;
    s->m.t[0] = s->m.t[1] = s->m.t[2] = 0;
    func_8003B35C(&s->m, &D_801FCC18);
    func_8003A63C(&D_801FD11C, &D_801FCC38->m, &D_801FCC38->m);
    func_8003B48C(&D_801FCC38->m);
    func_8003B51C(&D_801FCC38->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801FCBF8, D_801517C0 + 0x4060, 0, D_80163C74);
    func_8003C21C((MgSVec *)&p->unkC, &D_801FCC38->m);
    s = D_801FCC38;
    s->m.t[0] = s->m.t[1] = s->m.t[2] = 0;
    func_8003B35C(&s->m, &D_801FCC28);
    func_8003A63C(&D_801FD11C, &D_801FCC38->m, &D_801FCC38->m);
    func_8003B48C(&D_801FCC38->m);
    func_8003B51C(&D_801FCC38->m);
    D_80163C74 = func_800D29D4(&D_801FCC08, D_801517C0 + 0x405C, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk6 = p->unk6;
        p->unkE -= 4;
    }
}

void func_801B2AE8(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003A79C(&D_801FD11C, &D_801FCC4C, D_801FCC7C);
    func_8003AD14(D_801FCC7C, &D_801FCC6C);
    func_8003B48C(D_801FCC7C);
    func_8003B51C(&D_801FCC4C);
    D_80163C74 = func_800D29D4(&D_801FCC3C, D_801517C0 + 0x406C, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x226) {
            p->unk0 = -1;
        }
    }
}

void *func_801B2BDC(void *arg0, s32 arg1, void *arg2) {
    void *temp_s2;

    M2C_FIELD(arg2, s32 *, 0) = 0x04000000;
    M2C_FIELD(arg2, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(arg2, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(arg2, u8 *, 0xC) = (u8) M2C_FIELD(arg0, u8 *, 4);
    M2C_FIELD(arg2, u8 *, 0xD) = (u8) M2C_FIELD(arg0, u8 *, 6);
    M2C_FIELD(arg2, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x12);
    M2C_FIELD(arg2, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 8);
    func_80046794(arg1, (s32) arg2);
    temp_s2 = arg2 + 0x14;
    func_80044A68(temp_s2, 0, 1, (s32) M2C_FIELD(arg0, u16 *, 0x10), 0);
    func_80046794(arg1, (s32) temp_s2);
    return arg2 + 0x20;
}

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B2C9C);

void func_801B3088(void) {
    MgTask *p;
    MgMat *m;
    s32 t;
    s32 k;
    s32 a;
    s32 b;
    s32 x;

    p = (MgTask *)&D_80162978[D_8015169C];
    m = func_801B0088(&D_801FCCF0, 0x2800, 0);
    t = p->unk2;
    if (t < 0x1E) {
        k = func_801B01E0((t << 12) / 30, 0x180);
        x = -(k * 500) >> 12;
        a = m->t[0];
        b = m->t[1];
        a -= 0x190;
        a += x;
        b -= 0x1F4;
        b += -(k * 700) >> 12;
        m->t[0] = a;
        m->t[1] = b;
    } else {
        t -= 0x1E;
        if (t < 0x50) {
            m->t[0] -= 0x384;
            m->t[1] -= 0x4B0;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003B48C(m);
    func_8003B51C(m);
    D_80163C74 = func_800D29D4(&D_801FCCE0, D_801517C0 + 0x4060, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B320C(void) {
    MgTask *p;
    MgMat *m;
    s32 t;
    s32 k;
    s32 a;
    s32 b;
    s32 x;

    p = (MgTask *)&D_80162978[D_8015169C];
    m = func_801B0088(&D_801FCD08, 0x3000, 0);
    t = p->unk2;
    if (t < 0x3C) {
        k = func_801B01E0((t << 12) / 60, 0x180);
        x = -(k * 1250) >> 12;
        a = m->t[0];
        b = m->t[1];
        a -= 0x4B0;
        a += x;
        b -= 0xBB8;
        b += -(k * 1500) >> 12;
        m->t[0] = a;
        m->t[1] = b;
    } else {
        t -= 0x3C;
        if (t < 0x2C) {
            m->t[0] -= 0x992;
            m->t[1] -= 0x1194;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003B48C(m);
    func_8003B51C(m);
    D_80163C74 = func_800D29D4(&D_801FCCF8, D_801517C0 + 0x4060, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3398(void) {
    MgTask *p;
    MgMat *m;
    s32 *d;
    s32 i;
    s32 t;
    s32 a;
    s32 b;
    s32 sn;
    s32 cs;
    s32 u;
    s32 w;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 3) {
        a = 0;
        b = (t << 12) / 3;
    } else {
        t -= 3;
        if (t < 0x16) {
            b = 0x1000;
            a = (t << 12) / 22;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003B69C(0, 0, 0);
    func_8003B710(D_801FCD30, a, D_801FCD28);
    m = func_801B0088(&D_801FCD44, 0x2000, 0);
    D_801FCD4C->t[2] = m->t[2];
    sn = func_80039A74(0x280);
    cs = func_80039B40(0x280);
    d = &D_801FCD28[-1];
    for (i = 0; i < 5; i++) {
        u = m->t[0] - 0x6A4;
        D_801FCD4C->t[0] = u + ((D_801FCD10[i].b * sn >> 12) * b >> 12);
        w = m->t[1] - 0x1194;
        D_801FCD4C->t[1] = w + ((D_801FCD10[i].b * cs >> 12) * b >> 12);
        func_8003B51C(D_801FCD4C);
        d[0] = D_801FCD30[D_801FCD10[i].a].v;
        D_80163C74 = func_800D4D90(d, D_801517C0 + 0x4084, 0, D_80163C74);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B35F0(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_800BBEAC(&func_801B3088);
            D_801FCD50++;
        }
        if (p->unk2 == 6) {
            func_800BBEAC(&func_801B320C);
            D_801FCD50++;
        }
        if (p->unk2 == 0x17) {
            func_800BBEAC(&func_801B3398);
            D_801FCD50++;
        }
        if (D_801FCD50 >= 3) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B3708(void) {
    MgTask *p;
    Vh0Eff *s;
    s32 u;
    s32 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    u = (p->unk2 << 12) / 10;
    a = func_801B01E0(u, 0);
    a = 0x12FF - a;
    func_8003C21C((MgSVec *)&p->unk14, &D_801FCD64->m);
    s = D_801FCD64;
    s->m.t[0] = p->unk4 + (p->unkC * a >> 12);
    s->m.t[1] = p->unk6 + (p->unkE * a >> 12);
    s->m.t[2] = p->unk8 + (p->unk10 * a >> 12);
    s->v0 = s->v8 = 0x400;
    s->v4 = ((0x1000 - u) * 5 << 12) >> 12;
    func_8003B35C(&s->m, s);
    func_8003A63C(&D_801FD11C, &D_801FCD64->m, &D_801FCD64->m);
    func_8003B48C(&D_801FCD64->m);
    func_8003B51C(&D_801FCD64->m);
    D_80163C74 = func_800D29D4(&D_801FCD54, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B38D0(void) {
    MgTask *p;
    MgTask *q;
    s32 n;
    s32 a;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = (p->unk2 * 0x800 & 0xFF) + 0x800;
        while (n >= 0x100) {
            n -= 0x100;
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B3708)];
            q->unk14 = 0;
            q->unk16 = 0;
            a = func_80042DA8() & 0xFFF;
            q->unk18 = a;
            r = func_80042DA8() % 600 + 0x578;
            q->unkC = r * func_80039A74(a) >> 12;
            q->unkE = -r * func_80039B40(a) >> 12;
            q->unk10 = 0;
            q->unk4 = 0;
            q->unk6 = -0x2710;
            q->unk8 = -0x2710;
        }
        p->unk2++;
        if (p->unk2 >= 0x23) {
            p->unk0 = -1;
        }
    }
}

void func_801B3A3C(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        D_801FCD76 = 0;
    } else {
        t -= 10;
        if (t < 0x23) {
            k = (t << 12) / 35;
            D_801FCD76 = k;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    k = func_801B01E0((p->unk2 << 12) / 45, 0);
    func_801B0088(&D_801FCD7C, (k * 5 << 13) >> 16, 0);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801FCD6C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3B88(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        k = (t << 12) / 5;
        D_801FCD8E = 0x1000 - k;
    } else {
        t -= 5;
        if (t < 5) {
            D_801FCD8E = 0;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    k = func_801B01E0((p->unk2 << 12) / 10, -0x2FF);
    k = (-(k << 12) >> 12) + 0x1000;
    D_801FCD94.m[0][0] = D_801FCD94.m[1][1] = D_801FCD94.m[2][2] = k;
    func_8003A63C(&D_80153E64, &D_801FCD94, D_801FCDB4);
    func_8003B48C(D_801FCDB4);
    func_8003B51C(D_801FCDB4);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801FCD84, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3D14(void) {
    MgTask *p;
    s32 q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = (p->unk2 << 12) / 65;
        D_801FCDB8 += 4 + (q * 0x7C >> 12);
        while (D_801FCDB8 >= 0x100) {
            func_800BBEAC(&func_801B3B88);
            D_801FCDB8 -= 0x100;
        }
        p->unk2++;
        if (p->unk2 >= 0x41) {
            p->unk0 = -1;
        }
    }
}

void func_801B3E0C(void) {
    MgTask *p;
    MgVec n;
    s32 flag[3];
    s32 t;
    s32 k;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x4B) {
        k = func_801B01E0((t << 12) / 75, 0);
        c = k << 10 >> 12;
    } else {
        t -= 0x4B;
        if (t < 8) {
            k = func_801B01E0((t << 12) / 8, 0x4FF);
            c = (k * 7 << 10 >> 12) + 0x400;
        } else {
            t -= 8;
            if (t < 2) {
                k = func_801B01E0((t << 12) >> 1, 0x1FF);
                c = (-(k * 13 << 9) >> 12) + 0x2000;
            } else {
                t -= 2;
                if (t < 5) {
                    c = 0x600;
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
        }
    }
    D_801FCDCC.m[0][0] = D_801FCDCC.m[1][1] = D_801FCDCC.m[2][2] = c;
    func_8003B48C(&D_80153E64);
    func_8003B51C(&D_80153E64);
    func_8003BC6C(&D_801FCDEC, (MgVec *)D_801FCDCC.t, flag);
    func_8003A08C((MgVec *)D_801FCDCC.t, &n);
    D_801FCDCC.t[0] = D_801FCDCC.t[0];
    D_801FCDCC.t[1] = D_801FCDCC.t[1];
    D_801FCDCC.t[2] = D_801FCDCC.t[2];
    func_8003B48C(&D_801FCDCC);
    func_8003B51C(&D_801FCDCC);
    D_80163C74 = func_800D29D4(&D_801FCDBC, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

MgPolyT *func_801B4018(void) {
    s32 p;
    s32 flag;
    MgPolyT *prim;

    prim = D_80163C74;
    func_8003BC0C(&D_801FCDF4[0], &D_801FCDF4[1], &D_801FCDF4[2], &prim->xy0, &prim->xy1, &prim->xy2, &p, &flag);
    prim->tag = 0x06000000;
    D_80163C74 = prim + 1;
    return prim;
}

void func_801B4090(void) {
    MgTask *p;
    Vh0Fx *s;
    Vh0Fx *u;
    Vh0Fx *v;
    Vh0Fx *x;
    Vh0Fx *y;
    u8 *pk;
    s32 t;
    s32 w;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 3) {
        w = (t << 12) / 3;
        D_801FCE0C->w0 = p->unk1C * w >> 12;
    } else {
        t -= 3;
        if (t < 6) {
            D_801FCE0C->w0 = p->unk1C;
        } else {
            t -= 6;
            if (t < 3) {
                w = (t << 12) / 3;
                D_801FCE0C->w0 = p->unk1C * (0x1000 - w) >> 12;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    func_8003B48C(&D_80153E64);
    func_8003B51C(&D_80153E64);
    s = D_801FCE0C;
    r = func_8003BBDC(&p->unk4, &s->sx, &s->ext, &s->flag);
    u = D_801FCE0C;
    u->otz = r;
    func_8003C21C((MgSVec *)&p->unkC, &u->m);
    v = D_801FCE0C;
    func_8003B64C(&v->px, &v->py);
    x = D_801FCE0C;
    x->m.t[0] = x->sx - x->px;
    x->m.t[1] = x->sy - x->py;
    r = func_8003B66C();
    y = D_801FCE0C;
    y->m.t[2] = r;
    y->v4 = y->v8 = 0x1000;
    func_8003B35C(&y->m, y);
    func_8003B48C(&D_801FCE0C->m);
    func_8003B51C(&D_801FCE0C->m);
    pk = (u8 *)func_801B4018();
    *(s32 *)(pk + 4) = 0x32808080;
    *(s32 *)(pk + 0xC) = 0x802020;
    *(s32 *)(pk + 0x14) = 0x802020;
    r = D_801FCE0C->otz >> 2;
    if (r > 0) {
        func_80046794(D_801517C0 + 0x70 + r * 4, pk);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk10 += p->unk1E;
    }
}

void func_801B42F0(void) {
    MgTask *p;
    MgTask *q;
    s32 n;
    u16 t;
    s32 r;
    s32 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = (p->unk2 * 0x100 & 0xFF) + 0x100;
        while (n >= 0x100) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B4090)];
            t = p->unk2;
            q->unk4 = 0;
            q->unk6 = 0x96;
            q->unk8 = -0x2EE;
            q->unkE = 0;
            q->unkC = 0;
            q->unk0 = t;
            r = (func_80042DA8() & 0x7FF) + 0x400;
            a = r + D_801FD104;
            D_801FD104 = a;
            q->unk10 = a;
            q->unk1E = func_80042DA8() % 32 + 0x20;
            if (func_80042DA8() & 0x800) {
                q->unk1E = -q->unk1E;
            }
            n -= 0x100;
            q->unk1C = func_80042DA8() % 0xA00 + 0x600;
        }
        p->unk2++;
        if (p->unk2 >= 0x3F) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B4470);

void func_801B493C(void) {
    MgTask *p;
    Vh0Eff *s;
    Vh0Eff *u;
    s32 t;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        D_801FCE7E = 0;
    } else {
        t -= 5;
        if (t < 0x19) {
            k = (t << 12) / 25;
            D_801FCE7E = k;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    s = D_801FCE8C;
    k = (p->unk2 << 12) / 30;
    s->v0 = s->v4 = s->v8 = (k * 3 << 11) >> 12;
    func_8003C21C(&D_801FCE84, &s->m);
    u = D_801FCE8C;
    u->m.t[0] = 0;
    u->m.t[1] = -0xDD0;
    u->m.t[2] = -0xDD0;
    func_8003B35C(&u->m, u);
    func_8003A63C(&D_801FD11C, &D_801FCE8C->m, &D_801FCE8C->m);
    func_8003B48C(&D_801FCE8C->m);
    func_8003B51C(&D_801FCE8C->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801FCE74, D_801517C0 + 0x4054, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B4AEC(void) {
    MgTask *p;
    Vh0Eff *s;
    Vh0Eff *u;

    p = (MgTask *)&D_80162978[D_8015169C];
    s = D_801FCEA8;
    s->v0 = s->v4 = s->v8 = ((p->unk2 << 12) / 40 << 13) >> 12;
    func_8003C21C(&D_801FCEA0, &s->m);
    u = D_801FCEA8;
    u->m.t[0] = 0;
    u->m.t[1] = -0xDD0;
    u->m.t[2] = -0xDD0;
    func_8003B35C(&u->m, u);
    func_8003A63C(&D_801FD11C, &D_801FCEA8->m, &D_801FCEA8->m);
    func_8003B48C(&D_801FCEA8->m);
    func_8003B51C(&D_801FCEA8->m);
    func_8003B69C(0, 0, 0);
    func_800D4484(D_801517C0 + 0x4058, 0x20);
    D_80163C74 = func_800D29D4(&D_801FCE90, D_801517C0 + 0x4058, 0, D_80163C74);
    func_800D4484(D_801517C0 + 0x4058, 0x40);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B4C74(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    func_80046794(D_801517C0 + 0x406C, D_801FCECC * 0x10 + D_801FCEAC);
    D_801FCECC ^= 1;
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x46) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B4D20);

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B5094);

void func_801B52A0(void) {
    MgTask *p;
    s32 t;
    s32 u;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x2D) {
        u = (t << 12) / 45;
        c = func_801B01E0(u, -0x2F0);
        c = (c * 0x3E0 >> 12) + 0x10;
        D_801FCF68.m[0][0] = D_801FCF68.m[1][1] = D_801FCF68.m[2][2] = c;
    } else {
        p->unk0 = -1;
        return;
    }
    func_8003B48C(&D_801FCF68);
    func_8003B51C(&D_801FCF68);
    D_80163C74 = func_800D29D4(&D_801FCF58, D_801517C0 + 0x4068, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B53C0);

void func_801B563C(void) {
    s32 i;
    s32 j;
    s32 t;
    s32 c;

    for (i = 0; i < 0x21; i++) {
        t = ((Vh0Big *)D_801FD928)->a[i] + ((Vh0Big *)D_801FD928)->b[i];
        ((Vh0Big *)D_801FD928)->a[i] = t;
        if (t > 0) {
            ((Vh0Big *)D_801FD928)->a[i] = 0;
        }
        for (j = 0; j < 0x10; j++) {
            ((Vh0Big *)D_801FD928)->row[i].e[j].vy = ((Vh0Big *)D_801FD928)->a[i] >> 10;
        }
        ((Vh0Big *)D_801FD928)->b[i] += 0x5DC;
        ((Vh0Big *)D_801FD928)->b[i] += func_801B01E0(func_80039A74(i * 32 + 0x400), -0x3C0) * 5000 >> 12;
        t = ((Vh0Big *)D_801FD928)->row[i].e[0].vy;
        if (-t < 500) {
            c = (t << 12) / 500 + 0x1000;
        } else {
            c = 0;
        }
        func_8003B710(&D_801FCF8C, c, &((Vh0Big *)D_801FD928)->c[i]);
    }
}

void func_801B57F4(s32 arg0) {
    s32 i;
    s32 a;
    s32 k;
    s32 t;
    s32 *p;

    i = 0;
    k = 0x10104;
    a = 0x400;
    for (; i < 0x21; i++) {
        t = func_80039A74(a) * arg0;
        a += 0x20;
        p = (s32 *)(i * 4 + D_801FD928 + k);
        *p -= t >> 12;
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B5884);

void func_801B5B90(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        D_801FCFA6 = 0;
    } else {
        t -= 5;
        if (t < 10) {
            k = (t << 12) / 10;
            D_801FCFA6 = k;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    k = (p->unk2 << 12) / 15;
    func_801B0088(&D_801FCFAC, k, 0);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801FCF9C, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_RODATA("../asm/us/magic_vahamut0/nonmatchings/text", D_801B0040);

void func_801B5CC8(void) {
    MgMat m;
    MgTask *p;
    s32 t;

    m = D_801B0040;
    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 == 0) {
        D_801FCFB4 = (s32)((s32 *)&D_801B7A40[-1] + D_801B7A40[0]);
    }
    t = p->unk2;
    if (t < 0x59) {
        m.m[0][0] = m.m[1][1] = m.m[2][2] = (u32)(func_801B01E0((t << 12) / 89, -0x280) << 13) >> 12;
    } else {
        p->unk0 = -1;
        return;
    }
    func_8003A63C(&D_801FD11C, &m, &D_801FCFC4->m);
    func_8003B48C(&D_801FCFC4->m);
    func_8003B51C(&D_801FCFC4->m);
    D_80163C74 = func_800D29D4(&D_801FCFB4, D_801517C0 + 0x70, 0xC, D_80163C74);
    D_801FCFC4->v0 = D_801FCFC4->v4 = D_801FCFC4->v8 = 0xF00;
    func_8003B35C(&D_801FCFC4->m, D_801FCFC4);
    func_8003B48C(&D_801FCFC4->m);
    D_80163C74 = func_800D29D4(&D_801FCFB4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B5EC4(void) {
    MgTask *p;
    Vh0Eff *s;
    Vh0Eff *u;
    s32 t;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_801FCFC8[0] == 0) {
        D_801FCFC8[0] = (s32)((s32 *)&D_801B7A44[-2] + D_801B7A44[0]);
    }
    t = p->unk2;
    if (t < 10) {
        D_801FCFD2 = 0;
    } else {
        t -= 10;
        if (t < 5) {
            D_801FCFD2 = (t << 12) / 5;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003C21C((MgSVec *)&p->unkC, &D_801FCFD8->m);
    s = D_801FCFD8;
    s->m.t[0] = p->unk4;
    s->m.t[1] = p->unk6;
    s->m.t[2] = p->unk8;
    k = func_801B01E0((p->unk2 << 12) / 15, -0x280);
    k = p->unk1C * k >> 12;
    u = D_801FCFD8;
    u->v4 = 0x1000;
    u->v0 = u->v8 = k;
    func_8003B35C(&u->m, u);
    func_8003A63C(&D_801FD11C, &D_801FCFD8->m, &D_801FCFD8->m);
    func_8003B48C(&D_801FCFD8->m);
    func_8003B51C(&D_801FCFD8->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801FCFC8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B60CC(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 a;
    s32 b;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        a = 0x6000;
        i = 0;
        b = -0x1388;
    loop:
        q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B5EC4)];
        i++;
        q->unk8 = 0;
        q->unk4 = 0;
        q->unk6 = b;
        q->unk10 = 0;
        q->unkC = 0;
        q->unkE = func_80042DA8() & 0xFFF;
        q->unk1C = a + 0x1000;
        a >>= 1;
        b -= 0x7D0;
        if (i < 5) {
            goto loop;
        }
        p->unk0 = -1;
    }
}

void func_801B619C(MgTask *arg0) {
    MgTask *p;
    MgMat *m;
    s32 t;
    s32 k;

    p = arg0;
    if (D_801FCFDC[0] == 0) {
        D_801FCFDC[0] = (s32)((s32 *)&D_801B7A48[-3] + D_801B7A48[0]);
    }
    t = p->unk2;
    if (t < 10) {
        D_801FCFE6 = 0;
    } else {
        t -= 10;
        if (t < 5) {
            D_801FCFE6 = (t << 12) / 5;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003C21C((MgSVec *)&p->unkC, D_801FD00C);
    m = D_801FD00C;
    m->t[0] = m->t[1] = m->t[2] = 0;
    func_8003A63C(&D_801FD11C, m, m);
    k = (p->unk2 << 12) / 15;
    D_801FCFF4 = 0x1000;
    D_801FCFEC[0] = 0x1000;
    D_801FCFFC.v = k;
    D_801FD008 = p->unk8 + 0x7D0;
    func_8003A63C(D_801FD00C, (MgMat *)D_801FCFEC, D_801FD00C);
    func_8003B48C(D_801FD00C);
    func_8003B51C(D_801FD00C);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801FCFDC, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk8 += p->unk4;
    }
}

void func_801B6384(void) {
    MgTask *p;
    MgTask *q;
    s32 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = 0xA00 + (-((p->unk2 << 12) / 30 << 11) >> 12);
        n += n * p->unk2 & 0xFF;
        while (n >= 0x100) {
            q = (MgTask *)func_801B24C8((s32)&func_801B619C);
            n -= 0x100;
            q->unkC = -func_80042DA8() & 0x3FF;
            q->unkE = func_80042DA8() & 0xFFF;
            q->unk10 = 0;
            q->unk8 = 0;
            q->unk4 = func_80042DA8() % 200 + 0x320;
        }
        p->unk2++;
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B64D8(MgTask *arg0) {
    MgTask *p;

    p = arg0;
    func_801B0088((MgSVec *)&p->unk4, p->unk1C, 0);
    D_801FD018[0] = p->unk2;
    D_80163C74 = func_801B2610((MgSVec *)&D_801FD018[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801F0650[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B6584(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 u;
    s32 n;
    s32 k;
    s32 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        u = (t << 12) / 30;
        n = 0xA00 + (-(u << 11) >> 12);
        n += n * t & 0xFF;
        k = u * 10000 >> 12;
        while (n >= 0x100) {
            q = (MgTask *)func_801B24C8((s32)func_801B64D8);
            n -= 0x100;
            a = func_80042DA8() & 0xFFF;
            q->unk4 = k * func_80039A74(a) >> 12;
            q->unk6 = 0;
            q->unk8 = k * func_80039B40(a) >> 12;
            q->unk1C = func_80042DA8() % 0x600 + 0x1000;
        }
        p->unk2++;
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B6718(void) {
    MgTask *p;
    MgMat *m;
    s32 t;
    s32 q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_801FD01C[0] == 0) {
        D_801FD01C[0] = (s32)((s32 *)&D_801B7A4C[-4] + D_801B7A4C[0]);
        p->unk8 = 0;
        p->unk6 = 0;
        p->unk4 = 0;
    }
    t = p->unk2;
    if (t < 0) {
        D_801FD03C = 0x7000;
    } else if (t < 0xF) {
        q = (t << 12) / 15;
        D_801FD03C = (-(q * 7 << 12) >> 12) + 0x7000;
    } else {
        p->unk0 = -1;
        return;
    }
    func_8003B48C(&D_801FD11C);
    func_8003B51C(&D_801FD11C);
    func_8003BC6C((MgSVec *)&p->unk4, &D_801FD050, (s32 *)(D_801FD07C + 0x28));
    m = (MgMat *)((u8 *)&D_801FD050 - 0x14);
    func_8003B48C(m);
    func_8003B51C(m);
    D_80163C74 = func_800D29D4(D_801FD01C, D_801517C0 + 0x70, 0xC, D_80163C74);
    func_8003B48C(&D_801FD05C);
    D_80163C74 = func_800D29D4(&D_801FD02C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B68E4(arg0) {
    s32 k;

    if (arg0 < 0x2D) {
        k = func_801B01E0((arg0 << 12) / 45, -0x1FF);
        D_801FD080->rot.vx = 0;
        D_801FD080->rot.vy = (u32)k >> 2;
        D_801FD080->rot.vz = 0;
    } else {
        arg0 -= 0x2D;
        if (arg0 < 0x2D) {
            k = func_801B01E0((arg0 << 12) / 45, 0x2FF);
            D_801FD080->rot.vy = (k << 10 >> 12) + 0x400;
            D_801FD080->rot.vx = 0;
            D_801FD080->rot.vz = (u32)k >> 3;
        } else {
            arg0 -= 0x2D;
            if (arg0 < 0x2D) {
                k = func_801B01E0((arg0 << 12) / 45, -0x3FF);
                D_801FD080->rot.vx = (u32)(k * 3) >> 3;
                D_801FD080->rot.vy = (k << 10 >> 12) + 0x800;
                D_801FD080->rot.vz = (-(k * 3 << 8) >> 12) + 0x200;
            } else {
                arg0 -= 0x2D;
                k = func_801B01E0((arg0 << 12) / 45, 0x2FF);
                D_801FD080->rot.vx = (-(k * 3 << 9) >> 12) + 0x600;
                D_801FD080->rot.vy = (k << 10 >> 12) + 0xC00;
                D_801FD080->rot.vz = (k << 8 >> 12) - 0x100;
            }
        }
    }
    D_801FD080->rot.vz = 0;
    D_801FD080->rot.vx = 0;
    func_8003C21C(&D_801FD080->rot, &D_801FD080->m);
    D_801FD080->m.t[0] = D_801FD080->m.t[1] = D_801FD080->m.t[2] = 0;
    func_8003A63C(&D_801FD080->m, &D_801FD11C, &D_801FD11C);
}

void func_801B6AE0(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    MgTask *r;
    s32 *w;
    s32 *s2;
    s32 *s1;
    s32 t;
    s32 i;
    s32 o;

    b = (MgTask *)D_80162978;
    p = &b[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801FC8C0, &D_801FD11C);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t >= 5) {
            t -= 5;
            if (t < 0x1E) {
                if (t == 0) {
                    q = func_800D4FA8(7);
                    q->unk10 = 7;
                    *(M2C_UNK **)((u8 *)q + 0xC) = &D_801B7A3C;
                }
                if (t == 0x1C) {
                    func_800C610C();
                    w = D_801B7A40;
                    s2 = w - 1;
                    s1 = w + 1;
                    func_800D2538(&s2[w[0]], &s1[w[0]]);
                    func_800D2538(&s2[w[1]], &s1[w[1]]);
                    func_800D2538(&s2[D_801B7A48[0]], &s1[D_801B7A48[0]]);
                }
                if (t == 0) {
                    func_800D5138(0x19);
                }
                if (t == 0x1D) {
                    D_800F8380 |= 7;
                    for (i = 4; i < 10; i++) {
                        o = i * 0xB9C;
                        D_801FD110[i] = D_80151909[o];
                        D_80151909[o] |= 2;
                    }
                }
                if (t == 0) {
                    func_800D55F4(0x22, 0x40, 0x2A2, 0x2A3, 0x2A4);
                }
            } else {
                t -= 0x1E;
                if (t < 0x14) {
                    if (t == 5) {
                        func_800D51D4(0xF);
                    }
                    if (t == 0) {
                        r = (MgTask *)((func_800BBEAC((M2C_UNK *)func_801B2888) << 5) + (s32)b);
                        r->unk8 = 0;
                        r->unk6 = 0;
                        r->unk4 = 0;
                        r->unk10 = 0;
                        r->unkE = 0;
                        r->unkC = 0;
                        func_800BBEAC((M2C_UNK *)func_801B2AE8);
                        func_800BBEAC((M2C_UNK *)func_801B2C9C);
                    }
                } else {
                    t -= 0x14;
                    if (t < 0xB4) {
                        func_801B68E4(t);
                    } else {
                        t -= 0xB4;
                        if (t < 0x1E) {
                            if (t == 0) {
                                func_800BBEAC((M2C_UNK *)func_801B35F0);
                            }
                            if (t == 5) {
                                func_800D55F4(0x22, 0x40, 0x2A5, 0x2A6, 0x2A7);
                            }
                        } else {
                            t -= 0x1E;
                            if (t >= 0xF) {
                                t -= 0xF;
                                if (t >= 0xA) {
                                    t -= 0xA;
                                    if (t >= 0xF) {
                                        t -= 0xF;
                                        if (t >= 0x14) {
                                            t -= 0x14;
                                            if (t >= 0x14) {
                                                t -= 0x14;
                                                if (t >= 0x14) {
                                                    t -= 0x14;
                                                    if (t >= 0x1E) {
                                                        t -= 0x1E;
                                                        if (t < 0x1E) {
                                                            if (t == 0) {
                                                                func_800BBEAC((M2C_UNK *)func_801B38D0);
                                                                func_800BBEAC((M2C_UNK *)func_801B3A3C);
                                                            }
                                                        } else {
                                                            t -= 0x1E;
                                                            if (t >= 0xF) {
                                                                t -= 0xF;
                                                                if (t < 0x5A) {
                                                                    if (t == 0) {
                                                                        func_800BBEAC((M2C_UNK *)func_801B3D14);
                                                                        func_800BBEAC((M2C_UNK *)func_801B3E0C);
                                                                        func_800BBEAC((M2C_UNK *)func_801B42F0);
                                                                    }
                                                                    if (t == 0x4B) {
                                                                        func_800BBEAC((M2C_UNK *)func_801B4470);
                                                                    }
                                                                    if (t == 0) {
                                                                        func_800D55F4(0x22, 0x40, 0x2A8, 0x2A9, 0x2AA);
                                                                    }
                                                                } else {
                                                                    t -= 0x5A;
                                                                    if (t < 0x37) {
                                                                        if (t == 0xF) {
                                                                            func_800BBEAC((M2C_UNK *)func_801B493C);
                                                                            func_800BBEAC((M2C_UNK *)func_801B4AEC);
                                                                        }
                                                                        if (t == 0x23) {
                                                                            q = func_800D4FA8(7);
                                                                            q->unk10 = 8;
                                                                            *(M2C_UNK **)((u8 *)q + 0xC) = (M2C_UNK *)D_801C167C;
                                                                        }
                                                                        if (t == 0x2E) {
                                                                            func_800D5138(6);
                                                                        }
                                                                        if (t == 0x34) {
                                                                            func_800C610C();
                                                                            func_800D2980((M2C_UNK *)(D_801C1680 - 1 + D_801C1680[0]), 0, 0, 0);
                                                                        }
                                                                    } else {
                                                                        t -= 0x37;
                                                                        if (t < 0x46) {
                                                                            if (t == 0) {
                                                                                q = func_800D4FA8(7);
                                                                                q->unk10 = 9;
                                                                                *(M2C_UNK **)((u8 *)q + 0xC) = &D_801B7A3C;
                                                                                func_800D51D4(6);
                                                                                func_800BBEAC((M2C_UNK *)func_801B4D20);
                                                                                func_800BBEAC((M2C_UNK *)func_801B4C74);
                                                                                func_800BBEAC((M2C_UNK *)func_801B5094);
                                                                            }
                                                                            if (t == 0x19) {
                                                                                func_800BBEAC((M2C_UNK *)func_801B52A0);
                                                                            }
                                                                            if (t == 0x37) {
                                                                                func_800C610C();
                                                                                func_800D2980((M2C_UNK *)(D_801B7A40 - 1 + D_801B7A40[0]), 0, 0, 0);
                                                                            }
                                                                            if (t == 0x39) {
                                                                                q = func_800D4FA8(7);
                                                                                q->unk10 = 0xA;
                                                                                *(M2C_UNK **)((u8 *)q + 0xC) = &D_801B7A3C;
                                                                            }
                                                                            if (t == 0xA) {
                                                                                func_800D55F4(0x22, 0x40, 0x2AB, 0x2AC, 0x2AD);
                                                                            }
                                                                        } else {
                                                                            t -= 0x46;
                                                                            if (t < 0xA) {
                                                                                if (t == 0) {
                                                                                    D_800F5B70[2] = 0;
                                                                                    D_800F5B70[1] = 0;
                                                                                    D_800F5B70[0] = 0;
                                                                                    D_800F5B74 = 0;
                                                                                    D_800F8380 &= 0xF8;
                                                                                    func_800D52A0(0x1000, 0xA);
                                                                                    for (i = 4; i < 10; i++) {
                                                                                        o = i * 0xB9C;
                                                                                        D_80151909[o] = D_801FD110[i];
                                                                                    }
                                                                                }
                                                                                if (t == 0) {
                                                                                    func_800C610C();
                                                                                    func_800D2980((M2C_UNK *)(D_801B7A50 - 5 + D_801B7A50[0]), 0, 0, 0);
                                                                                }
                                                                                if (t == 9) {
                                                                                    D_800F8380 |= 7;
                                                                                }
                                                                            } else {
                                                                                t -= 0xA;
                                                                                if (t < 0x5A) {
                                                                                    if (t == 0) {
                                                                                        D_801FD154 = (MgObj20 *)(D_801B7A50 - 5 + D_801B7A50[0]);
                                                                                        func_801B24A4();
                                                                                        func_800BBEAC((M2C_UNK *)func_801B6718);
                                                                                        func_800BBEAC((M2C_UNK *)func_801B6584);
                                                                                        func_800BBEAC((M2C_UNK *)func_801B251C);
                                                                                    }
                                                                                    if (t == 1) {
                                                                                        func_800BBEAC((M2C_UNK *)func_801B5B90);
                                                                                        func_800BBEAC((M2C_UNK *)func_801B5CC8);
                                                                                        func_800BBEAC((M2C_UNK *)func_801B5884);
                                                                                        func_800BBEAC((M2C_UNK *)func_801B60CC);
                                                                                        func_800BBEAC((M2C_UNK *)func_801B6384);
                                                                                    }
                                                                                    if (t == 0x3C) {
                                                                                        func_800D5138(0xF);
                                                                                    }
                                                                                    if (t == 0) {
                                                                                        func_800D55F4(0x22, 0x40, 0x2AE, 0x2AF, 0x2B0);
                                                                                    }
                                                                                } else {
                                                                                    func_800D51D4(0xF);
                                                                                    D_800F5B74 = 0;
                                                                                    D_800F8380 &= 0xF8;
                                                                                    for (i = 0; i < 10; i++) {
                                                                                        if (D_801FD13C >> i & 1) {
                                                                                            func_800D5774(i);
                                                                                        }
                                                                                    }
                                                                                    D_800F8380 = 0;
                                                                                    p->unk0 = -1;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_vahamut0/nonmatchings/text", func_801B7320);

void func_801B7920(arg0, arg1) {
    MgSVec v;

    func_800D2980(&D_801B7A3C, 0, 0, 0);
    D_801FD13C = arg0;
    func_800D54EC(arg0, &v);
    if (v.vz < D_80151A50[arg1][0]) {
        D_801FC8B8.vy = 0x800;
    }
    func_8003C21C(&D_801FC8B8, &D_801FC8C0);
    D_801FC8C0.t[2] = v.vz;
    func_800BBEAC(&func_801B6AE0);
    func_800BBEAC(&func_801B7320);
    func_80042DA8();
    ((void (*)(s32, s32, s32))func_801B13AC)((s32)&D_801FC904, (s32)&D_801FC8C0, arg1);
    D_800F8380 |= 8;
}
