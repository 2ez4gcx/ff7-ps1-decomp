#include "common.h"
#include "magic_alex/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B6AB0();
    return &D_801DED44;
}

s32 func_801B0068(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F0632[-v];
    }
    return v;
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B00A4);

void func_801B10C0(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B00A4)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B1124);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B1BE4);

void func_801B1E24(MgSVecList *a, MgSVec *b, MgSVec *out) {
    s32 i;
    s32 n;
    MgSVec *s;

    n = a->n / 8;
    s = a->v;
    for (i = 0; i < n; i++) {
        out->vx = s->vx - b->vx;
        out->vy = s->vy - b->vy;
        out->vz = s->vz - b->vz;
        s++;
        b++;
        out++;
    }
}

void func_801B1EB4(MgSVecList *a, MgSVec *b, MgSVec *d, s32 t) {
    s32 i;
    s32 n;
    MgSVec *s;

    n = a->n / 8;
    s = a->v;
    t = 0x1000 - t;
    for (i = 0; i < n; i++) {
        s->vx = b->vx + ((d->vx * t) >> 12);
        s->vy = b->vy + ((d->vy * t) >> 12);
        s->vz = b->vz + ((d->vz * t) >> 12);
        s++;
        b++;
        d++;
    }
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B1F7C);

void func_801B2AE4(void) {
    s32 *p;
    s32 i;

    i = 199;
    p = &D_801F1C24;
    for (; i >= 0; i--) {
        *p-- = 0;
    }
}

AlxPart *func_801B2B08(s32 arg0) {
    s32 i;

    for (i = 0; i < 200; i++) {
        if (D_801F1908[i] == 0) {
            D_801F1908[i] = arg0;
            D_801F0648[i].unk0 = 0;
            D_801F0648[i].unk2 = 0;
            return &D_801F0648[i];
        }
    }
    return 0;
}

void func_801B2B80(void) {
    MgTask *p;
    s32 n;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    n = 0;
    for (i = 0; i < 200; i++) {
        if (D_801F1908[i] != 0) {
            ((void (*)(AlxPart *))D_801F1908[i])(&D_801F0648[i]);
            if (D_801F0648[i].unk0 == -1) {
                D_801F1908[i] = 0;
            } else {
                n++;
            }
        }
    }
    if (n == 0 && D_80162080 < 2) {
        p->unk0 = -1;
    }
}

MgMat *func_801B2C78(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EDDEC.m[0][0] = D_801EDDEC.m[1][1] = D_801EDDEC.m[2][2] = scale;
    func_8003B48C(&D_801F0610);
    func_8003B51C(&D_801F0610);
    func_8003BC6C(v, (MgVec *)D_801EDDEC.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EDDEC.t, &n);
        D_801EDDEC.t[0] += (dist * n.vx) >> 12;
        D_801EDDEC.t[1] += (dist * n.vy) >> 12;
        D_801EDDEC.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EDDEC);
    func_8003B51C(&D_801EDDEC);
    return &D_801EDDEC;
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B2D94);

void func_801B2F38(void) {
    MgMat m;

    D_801EDE3C = D_801EDB30;
    D_801EDE2C = D_801EDB30;
    if (D_801EDB52 != 0) {
        D_801EDE48 = D_801EDB4C;
    } else {
        D_801EDE48 = -D_801EDB4C;
    }
    func_8003A63C(&D_801EDE0C, &D_801EDE2C, &m);
    func_801B1BE4(&m, &D_801EDE4C);
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B2FC8);

M2C_UNK func_801B3430(void *arg0, s16 arg1, s16 arg2) {
    s32 r;

    func_801B2C78((MgSVec *)arg0, arg2, 0);
    D_801EDF9C[0] = arg1;
    r = func_800D4D90(&D_801EDF9C[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    D_80163C74 = r;
    return r;
}

void func_801B3498(void *arg0) {
    s16 temp_v0;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_v0_2;

    func_801B3430(arg0 + 4, M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 0x14));
    if (D_80062D98 == 0) {
        temp_v0 = (u16) M2C_FIELD(arg0, s16 *, 2) + 1;
        M2C_FIELD(arg0, s16 *, 2) = temp_v0;
        if ((s32) D_801DEA40 < temp_v0) {
            M2C_FIELD(arg0, s16 *, 0) = -1;
            return;
        }
        M2C_FIELD(arg0, u16 *, 6) = (u16) (M2C_FIELD(arg0, u16 *, 6) + M2C_FIELD(arg0, u16 *, 0xE));
        temp_s0 = func_80039A74(M2C_FIELD(arg0, s16 *, 0xC));
        temp_v0_2 = func_80039B40(M2C_FIELD(arg0, s16 *, 0xC));
        temp_a1 = (s32) ((temp_v0_2 * M2C_FIELD(arg0, s16 *, 4)) + (temp_s0 * M2C_FIELD(arg0, s16 *, 8))) >> 0xC;
        M2C_FIELD(arg0, s16 *, 4) = (s16) temp_a1;
        M2C_FIELD(arg0, s16 *, 8) = (s16) ((s32) ((-temp_s0 * (s16) temp_a1) + (temp_v0_2 * M2C_FIELD(arg0, s16 *, 8))) >> 0xC);
    }
}

void func_801B359C(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 n;
    s32 i;
    u8 pad[8];

    p = (MgTask *)&D_80162978[D_8015169C];
    i = D_80062D98 == 0;
    if (i) {
        t = p->unk2;
        n = 1;
        if (t >= 0xA) {
            t -= 0xA;
            if (t < 0x1E) {
                n = 2;
            } else {
                t -= 0x1E;
                n = 6;
                if (t < 0x1E) {
                    n = 4;
                }
            }
        }
        i = 0;
        if (n != 0) {
            do {
                q = (MgTask *)func_801B2B08((s32)func_801B3498);
                q->unk6 = 0;
                switch (func_80042DA8() % 3) {
                case 0:
                    q->unk4 = func_80042DA8() % 4000 + 0x7D0;
                    q->unk8 = func_80042DA8() % 12000 - 0x1770;
                    break;
                case 1:
                    q->unk4 = -(func_80042DA8() % 4000 + 0x7D0);
                    q->unk8 = func_80042DA8() % 12000 - 0x1770;
                    break;
                case 2:
                    q->unk4 = func_80042DA8() % 12000 - 0x1770;
                    q->unk8 = func_80042DA8() % 4000 + 0x7D0;
                    break;
                }
                q->unkE = -(func_80042DA8() % 80 + 0x14);
                q->unkC = -(func_80042DA8() % 64);
                q->unk14 = func_80042DA8() % 14336 + 0x1800;
                i++;
            } while (i < n);
        }
        p->unk2++;
        if (p->unk2 >= 0x8C) {
            p->unk0 = -1;
        }
    }
}

void func_801B3924(void) {
    AlxObj *p;
    s32 t;
    s32 k;
    s32 *fd;

    p = (AlxObj *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xA) {
        D_801EDFA8 = 0x80;
        D_801EDFAE = 0;
    } else {
        t -= 0xA;
        if (t < 5) {
            D_801EDFA8 = 0x88;
            D_801EDFAE = (t << 12) / 5;
        } else {
            goto kill;
        }
    }
    D_801EDFC0->rot.vx = p->a0 * 0x10;
    D_801EDFC0->rot.vy = p->a1 * 0x10;
    D_801EDFC0->rot.vz = p->a2 * 0x10;
    func_8003BF8C(&D_801EDFC0->rot, &D_801EDFC0->m);
    D_801EDFC0->m.t[0] = p->unk4;
    D_801EDFC0->m.t[1] = p->unk6;
    D_801EDFC0->m.t[2] = p->unk8;
    k = p->unk18;
    D_801EDFC0->sc.vx = D_801EDFC0->sc.vy = D_801EDFC0->sc.vz = k;
    func_8003B35C(&D_801EDFC0->m, &D_801EDFC0->sc);
    func_8003A63C(&D_801F0610, &D_801EDFC0->m, &D_801EDFC0->m);
    func_8003B48C(&D_801EDFC0->m);
    func_8003B51C(&D_801EDFC0->m);
    fd = &D_801EDFA4;
    *fd = D_801EDFB4[p->unk0];
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(fd, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        if (p->unk6 > 0) {
kill:
            p->unk0 = -1;
        } else {
            p->unk8 += p->unk10;
            p->unkC = p->unkC * 15 >> 4;
            p->unkE = (p->unkE * 15 >> 4) + 0x32;
            p->unk10 = p->unk10 * 15 >> 4;
            p->a0 += 8;
            p->a1 += 0x10;
            p->a2 += 0x20;
        }
    }
}

void func_801B3BAC(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 ang;
    s32 k;
    s32 u;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B3924)];
            q->unk0 = func_80042DA8() % 3;
            ang = func_80042DA8() % 3584 - 0x300;
            q->unk4 = (u32)(((s32 (*)(s32))func_80039B40)(ang) * 0x177) >> 9;
            u = 0x1B58;
            q->unk6 = func_80042DA8() % 4000 + (D_80153D22 - u);
            q->unk8 = (((s32 (*)(s32))func_80039A74)(ang) * 0x5DC >> 12) - 0x1F4;
            k = func_80042DA8() % 70 + 0x50;
            r = k * ((s32 (*)(s32))func_80039B40)(ang);
            q->unkE = 0;
            q->unkC = r >> 12;
            q->unk10 = k * ((s32 (*)(s32))func_80039A74)(ang) >> 12;
            q->unk18 = func_80042DA8() % 256 + 0x50;
            i++;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B3E14(void *arg0) {
    s16 temp_v0;

    func_801B3430(arg0 + 4, M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 0x14));
    if (D_80062D98 == 0) {
        temp_v0 = (u16) M2C_FIELD(arg0, s16 *, 2) + 1;
        M2C_FIELD(arg0, s16 *, 2) = temp_v0;
        if (temp_v0 >= (s32) D_801DEA40) {
            M2C_FIELD(arg0, s16 *, 0) = -1;
            return;
        }
        M2C_FIELD(arg0, u16 *, 6) = (u16) (M2C_FIELD(arg0, u16 *, 6) + 0x82);
    }
}

s32 func_801B3EA0(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s16 ang;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            i++;
            q = (MgTask *)func_801B2B08((s32)func_801B3E14);
            ang = func_80042DA8() & 0x7FF;
            q->unk4 = (u32)(func_80039B40(ang) * 0x177) >> 9;
            q->unk6 = func_80042DA8() % 5000 - 0x1770;
            q->unk8 = (func_80039A74(ang) * 0x5DC >> 12) - 0x1F4;
            q->unk14 = func_80042DA8() % 12288 + 0x1000;
        } while (i < 4);
        p->unk2++;
        if (p->unk2 >= 0x2D) {
            p->unk0 = -1;
        }
    }
}

void func_801B402C(void) {
    MgTask *p;
    s32 t;
    s32 a;
    u8 pad[8];

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        a = (t << 12) / 10;
        a = (0x1000 - a) * 0x28 >> 12;
        if (t & 1) {
            D_80158D02[0] += a;
            D_801031EA[0] += a;
        } else {
            D_80158D02[0] -= a;
            D_801031EA[0] -= a;
        }
        p->unk2++;
        if (p->unk2 >= 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B4118(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B3430(&p->unk4, p->unk2, p->unk18);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= ((MgByte *)&D_801DEA40)->v) {
            p->unk0 = -1;
            return;
        }
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC = p->unkC * 15 >> 4;
        p->unk10 = p->unk10 * 15 >> 4;
    }
}

void func_801B4200(MgTask *p) {
    func_801B2C78((MgSVec *)&p->unk4, p->unk14, 0);
    D_801EDFD0[0] = p->unk2 * ((MgByte *)&D_801DEA40)->v / 10 | 0x8000;
    D_80163C74 = func_800D4D90((s16 *)&D_801EDFD0[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0xA) {
            p->unk0 = -1;
            return;
        }
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC = p->unkC * 7 >> 3;
        p->unkE = p->unkE * 7 >> 3;
        p->unk10 = p->unk10 * 7 >> 3;
    }
}

s32 func_801B4348(void) {
    MgTask *p;
    MgTask *q;
    MgSVec *b;
    u16 *c;
    u16 *z;
    s32 i;
    u16 *r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        if (p->unk2 == 0) {
            i = 2;
            z = &D_801F05FC;
            do {
                *z = 0;
                i--;
                z--;
            } while (i >= 0);
            i = 0;
        }
        b = &D_801EDFD4;
        do {
            r = D_801F05F8;
            c = &r[i];
            *c = (s16)*c - 1;
            if ((s16)*c == -1) {
                D_801F05F0[i] = func_80042DA8() % 1536 + 0x100;
                *c = func_80042DA8() % 3 + 2;
                D_801F0600[i] = func_80042DA8() % 300 + 0x64;
            }
            D_801EDFDC->v.vx = 0;
            D_801EDFDC->v.vy = D_801F05F0[i];
            D_801EDFDC->v.vz = -0x120;
            func_8003C21C(&D_801EDFDC->v, &D_801EDFDC->m);
            q = (MgTask *)func_801B2B08((s32)func_801B4200);
            D_801EDFDC->v.vx = -0x12C;
            D_801EDFDC->v.vy = 0;
            D_801EDFDC->v.vz = 0;
            func_8003B2CC(&D_801EDFDC->m, &D_801EDFDC->v, &D_801EDFDC->v);
            q->unk4 = D_801EDFDC->v.vx + b->vx;
            q->unk6 = D_801EDFDC->v.vy + b->vy;
            q->unk8 = D_801EDFDC->v.vz + b->vz;
            D_801EDFDC->v.vx = -D_801F0600[i];
            D_801EDFDC->v.vy = 0;
            D_801EDFDC->v.vz = 0;
            func_8003B2CC(&D_801EDFDC->m, &D_801EDFDC->v, (MgSVec *)&q->unkC);
            q->unk14 = func_80042DA8() % 0x800 + 0x1000;
            i++;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 5) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B4614(s32 arg0) {
    s32 r;
    s32 g;
    s32 b;
    s32 u;

    if (arg0 < 0x555) {
        arg0 *= 3;
        r = (-(arg0 << 7) >> 12) - 0x80;
        g = (-(arg0 << 6) >> 12) - 0x80;
        b = 0x80;
    } else {
        arg0 -= 0x555;
        if (arg0 < 0x555) {
            arg0 *= 3;
            r = (u32)arg0 >> 7;
            u = -(arg0 << 6) >> 12;
            g = u + 0x40;
            b = u - 0x80;
        } else {
            arg0 -= 0x555;
            if (arg0 >= 0x555) {
                return 0;
            }
            arg0 *= 3;
            r = (-(arg0 << 5) >> 12) + 0x20;
            g = 0;
            b = (-(arg0 << 6) >> 12) + 0x40;
        }
    }
    return (r & 0xFF) | ((g & 0xFF) << 8) | ((b & 0xFF) << 16);
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B46E0);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B4970);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B4CD4);

void func_801B5084(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        D_801EE006 = 0;
    } else {
        t -= 5;
        if (t < 0) {
            k = (t << 12) / 0;
            D_801EE006 = k;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    k = (p->unk2 << 12) / 5;
    func_801B2C78((MgSVec *)&p->unk4, ((k * 0x5B00) >> 12) + 0x500, 0);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EDFFC, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B51EC(void) {
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_801EE0B0->sc.vy = D_801EE0B0->sc.vz = 0x1000;
    t = p->unk2;
    if (t < 5) {
        D_801EE0B0->sc.vx = p->unk18 * ((t << 12) / 5) >> 12;
        D_801EE0AA.v = 0;
    } else {
        t -= 5;
        if (t < 5) {
            D_801EE0B0->sc.vx = p->unk18;
            D_801EE0AA.v = (t << 12) / 5;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003C21C((MgSVec *)&p->unkC, &D_801EE0B0->m);
    D_801EE0B0->m.t[0] = p->unk4;
    D_801EE0B0->m.t[1] = p->unk6;
    D_801EE0B0->m.t[2] = p->unk8;
    func_8003B35C(&D_801EE0B0->m, &D_801EE0B0->sc);
    func_8003A63C(&D_801F0610, &D_801EE0B0->m, &D_801EE0B0->m);
    func_8003B48C(&D_801EE0B0->m);
    func_8003B51C(&D_801EE0B0->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EE0A0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B53B0(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 a;
    s32 ang;
    s32 r;
    s32 u;
    s32 rr;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        a = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B51EC)];
            rr = func_80042DA8();
            r = a / 3;
            u = rr % 1194 - 0x100;
            ang = r + u;
            q->unk4 = (u32)(((s32 (*)(s32))func_80039A74)(ang) * 0x7D) >> 9;
            q->unk6 = 0;
            q->unk8 = (((s32 (*)(s32))func_80039B40)(ang) * 0x3E8 >> 12) + 0x1388;
            q->unkC = -(func_80042DA8() % 256 + 0x200);
            q->unkE = ang;
            q->unk10 = 0;
            q->unk18 = func_80042DA8() % 0x1000 + 0x1000;
            a += 0xE00;
            i++;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 3) {
            p->unk0 = -1;
        }
    }
}

void func_801B5584(void) {
    MgTask *p;
    s32 t;
    s32 i;
    s32 a;
    s32 q;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xF) {
        D_801EE0BE = 0;
    } else {
        t -= 0xF;
        if (t < 0xA) {
            D_801EE0BE = (t << 12) / 10;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    i = 0;
    q = (p->unk2 << 12) / 25;
    a = q;
    do {
        a = ((s32 (*)(s32))func_80039A74)(a / 4);
        i++;
    } while (i < 4);
    q = (a * 0x600 >> 12) + (q * 0xA00 >> 12);
    D_801EE0C4.m[0][0] = D_801EE0C4.m[2][2] = 0x2500;
    D_801EE0C4.m[1][1] = (u32)(q * 0x35) >> 4;
    func_8003A63C(&D_801F0610, &D_801EE0C4, D_801EE0E4);
    func_8003B48C(D_801EE0E4);
    func_8003B51C(D_801EE0E4);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801EE0B4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B5770);

void func_801B5850(void) {
    AlxObj *p;
    s32 t;
    s32 k;
    s32 *fd;

    p = (AlxObj *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 8) {
        D_801EE148 = 0x80;
        D_801EE14E = 0;
    } else {
        t -= 8;
        if (t < 6) {
            D_801EE148 = 0x88;
            D_801EE14E = (t << 12) / 6;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    D_801EE160->rot.vx = p->a0 * 0x10;
    D_801EE160->rot.vy = p->a1 * 0x10;
    D_801EE160->rot.vz = p->a2 * 0x10;
    func_8003BF8C(&D_801EE160->rot, &D_801EE160->m);
    D_801EE160->m.t[0] = p->unk4;
    D_801EE160->m.t[1] = p->unk6;
    D_801EE160->m.t[2] = p->unk8;
    k = p->unk18;
    D_801EE160->sc.vx = D_801EE160->sc.vy = D_801EE160->sc.vz = k;
    func_8003B35C(&D_801EE160->m, &D_801EE160->sc);
    func_8003A63C(&D_801F0610, &D_801EE160->m, &D_801EE160->m);
    func_8003B48C(&D_801EE160->m);
    func_8003B51C(&D_801EE160->m);
    fd = &D_801EE144;
    *fd = D_801EE154[p->unk0];
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(fd, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        k = 0x1E;
        p->unk6 = (u16)p->unk6 - k + (u16)p->unk1A;
        p->unk1A = p->unk1A * 13 >> 4;
        p->a0 += 4;
        p->a1 += 8;
        p->a2 += 0x15;
    }
}

void func_801B5A90(void) {
    MgTask *p;
    u8 *tab;
    u8 *t;
    u8 *a;
    u8 *c;
    u8 *q;
    u8 *r;
    s32 i;
    s32 off;
    MgMat *mat;

    mat = &D_801F0610;
    q = (u8 *)D_80163C74;
    tab = D_801F1C28;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B48C(mat);
    func_8003B51C(mat);
    i = 0;
    c = tab + 0x10;
    a = tab;
    off = 0;
    r = q + 0x10;
    do {
        t = tab + 8;
        func_8003BC0C(a, (u8 *)(off + (s32)t), c, q + 8, q + 0xC, r, D_801EE164, &D_801EE164->flag);
        c += 0x18;
        if (!(D_801EE164->flag & 0x60000)) {
            *(s32 *)q = 0x04000000;
            *(s32 *)(r - 0xC) = 0x20000000;
            func_80046794(D_801517C0 + 0x406C, q);
            r += 0x14;
            q += 0x14;
        }
        a += 0x18;
        i++;
        off += 0x18;
    } while (i < 0x64);
    D_80163C74 = (s32)q;
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x29) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B5C14);

INCLUDE_ASM("../asm/us/magic_alex/nonmatchings/text", func_801B5E98);

s32 func_801B6AB0(arg0, arg1) {
    MgSVec v;
    s32 z;

    func_800D2980(&D_801B6BEC, 0, 0, 0);
    D_801F0630 = arg0;
    func_800D54EC(arg0, &v);
    if (v.vz < D_80151A4C[arg1].vz) {
        D_801EDB52 = 0x800;
        z = v.vz + 0x1388;
    } else {
        z = v.vz - 0x1388;
    }
    D_801EDB4C = z;
    func_8003C21C(&D_801EDB50, (MgMat *)&D_801EDB30);
    func_801B2AE4();
    func_800BBEAC((M2C_UNK *)func_801B2B80);
    if (func_80042DA8() & 0x100) {
        ((void (*)(s32, s32, s32))func_801B10C0)((s32)&D_801EDBA0, (s32)&D_801EDB30, arg1);
    } else {
        ((void (*)(s32, s32, s32))func_801B10C0)((s32)&D_801EDCC0, (s32)&D_801EDB30, arg1);
    }
    func_800BBEAC((M2C_UNK *)func_801B5E98);
    D_800F8380 |= 8;
}
