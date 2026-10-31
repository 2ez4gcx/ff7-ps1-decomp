#include "common.h"
#include "magic_lamu/decls.h"

M2C_UNK *func_801B0038(void) {
    func_801B38E8();
    return &D_801D6B50;
}

s32 func_801B0060(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801E82CA[-v];
    }
    return v;
}

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B009C);

void func_801B102C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B009C)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B1090);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B13A0);

void func_801B16B0(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 & 1) {
        D_80158D00[0] += p->unk0;
        D_801031E8[0] += p->unk0;
    } else {
        D_80158D00[0] -= p->unk0;
        D_801031E8[0] -= p->unk0;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1774(s32 arg0) {
    if (arg0 != 0) {
        if (D_801E7C98 == NULL) {
            D_801E7C98 = &D_80162978[func_800BBEAC(&func_801B16B0)];
        }
        D_801E7C98->unk0 = arg0;
        return;
    }
    if (D_801E7C98 != NULL) {
        D_801E7C98->unk0 = -1;
    }
}

void func_801B1800(void) {
    MgObj20 *p;
    s8 *frame;
    s32 n;

    p = &D_80162978[D_8015169C];
    frame = &D_801E7CA0;
    p->unk6 = D_801E7AE0[1];
    n = p->unk2;
    *frame = n << 5;
    func_800D4368(&p->unk4, 0x4000, -0x80);
    D_80163C74 = func_800D6260(frame - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B18D4(void) {
    MgTask *p;
    MgMat *s;

    p = (MgTask *)&D_80162978[D_8015169C];
    s = (MgMat *)0x1F800000;
    func_8003C21C((MgSVec *)&p->unkC, s);
    s->t[0] = ((s16 *)D_801E7AE0)[0];
    s->t[1] = ((s16 *)D_801E7AE0)[1];
    s->t[2] = ((s16 *)D_801E7AE0)[2];
    func_8003A63C(&D_801E8258, s, s);
    func_8003A63C((MgMat *)D_800FA63C, s, s);
    func_800D461C(s);
    func_8003B35C(s, &D_801E7CB8);
    func_8003B48C(s);
    func_8003B51C(s);
    D_801E7CB4[0] = 3 - (p->unk2 & 3);
    D_80163C74 = func_801B1090((u8 *)D_801E7CB4 - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2--;
        if (p->unk2 == 0) {
            p->unk0 = -1;
        }
    }
}

void func_801B1A10(void) {
    s32 k;
    MgTask *p;
    MgTask *q;
    MgVec *out;
    s32 flag;

    out = (MgVec *)0x1F800008;
    p = (MgTask *)&D_80162978[D_8015169C];
    k = 0x1F800000;
    if (D_80062D98 == 0) {
        q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B18D4)];
        q->unk8 = 0;
        q->unk6 = 0;
        q->unk4 = 0;
        q->unkC = (func_80042DA8() & 0x3FF) - 0x200;
        q->unkE = 0;
        q->unk10 = (func_80042DA8() & 0x3FF) - 0x200;
        q->unk2 = 3;
        if ((p->unk2 & 3) == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B1800)];
            *(s16 *)k = D_801E7AE0[0] + func_80042DA8() % 100 - 0x32;
            *(s16 *)0x1F800002 = D_801E7AE0[1];
            *(s16 *)0x1F800004 = D_801E7AE0[2] + func_80042DA8() % 100 - 0x32;
            func_8003B48C(&D_801E8258);
            func_8003B51C(&D_801E8258);
            func_8003BC6C((MgSVec *)0x1F800000, out, &flag);
            q->unk4 = out->vx;
            q->unk6 = out->vy;
            q->unk8 = out->vz;
        }
        p->unk2++;
        if (p->unk2 >= 0x9D) {
            p->unk0 = -1;
        }
    }
}

void func_801B1C24(void) {
    LamTask *p;
    MgSVec *rot;
    MgMat *m;
    MgVec *sc;
    s32 t;

    p = (LamTask *)&D_80162978[D_8015169C];
    rot = (MgSVec *)0x1F800020;
    sc = (MgVec *)0x1F800028;
    m = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 8) {
        D_801E7CCC = 0x80;
        D_801E7CD2 = 0;
    } else {
        t -= 8;
        if (t < 4) {
            D_801E7CCC = 0x88;
            D_801E7CD2 = t << 10;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    rot->vx = p->unk14 << 4;
    rot->vy = p->unk15 << 4;
    rot->vz = p->unk16 << 4;
    func_8003C21C(rot, m);
    sc->vx = sc->vy = sc->vz = p->unk1C;
    func_8003B35C(m, sc);
    m->t[0] = p->unk4;
    m->t[1] = p->unk6;
    m->t[2] = p->unk8;
    func_8003A63C(&D_801E8258, m, m);
    func_8003A63C((MgMat *)D_800FA63C, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    D_80163C74 = func_800D29D4(D_801E7CC8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk14 += p->unk18;
        p->unk15 += p->unk19;
        p->unk16 += p->unk1A;
    }
}

void func_801B1E2C(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk1C, -0x3E8);
    frame = &D_801E7CE0;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D3E80[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B1EEC(MgSVec *arg0, MgSVec *arg1, MgSVec *arg2, s32 arg3) {
    s32 i;

    for (i = 0; i < 0x88; i++) {
        arg2->vx = (arg1->vx - arg0->vx) / arg3;
        arg2->vy = (arg1->vy - arg0->vy) / arg3;
        arg2->vz = (arg1->vz - arg0->vz) / arg3;
        arg0++;
        arg1++;
        arg2++;
    }
}

void func_801B1FF0(MgSVec *arg0, MgSVec *arg1) {
    s32 i;

    for (i = 0; i < 0x88; i++) {
        arg0->vx += arg1->vx;
        arg0->vy += arg1->vy;
        arg0->vz += arg1->vz;
        arg0++;
        arg1++;
    }
}

void func_801B2050(void) {
    LamTask *p;
    LamTask *q;
    MgSVec *sc;
    MgVec *out;
    MgSVec *sv;
    s32 i;
    s32 r;
    s32 flag;
    u16 t;

    sc = (MgSVec *)0x1F800020;
    out = (MgVec *)0x1F800028;
    p = (LamTask *)&D_80162978[D_8015169C];
    func_8003A63C(&D_801E8258, &D_801E7CF4, (MgMat *)0x1F800000);
    func_8003A63C((MgMat *)D_800FA63C, (MgMat *)0x1F800000, (MgMat *)0x1F800000);
    func_8003B48C((MgMat *)0x1F800000);
    func_8003B51C((MgMat *)0x1F800000);
    D_80163C74 = func_800D29D4(D_801E7CE4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            do {
                if (p->unk0 == 8) {
                    p->unk0 = -1;
                    return;
                }
                t = D_801E7D24[p->unk0];
                p->unk2 = t;
                if (t != 0) {
                    if ((p->unk0 & 1) == 0) {
                        func_801B1EEC(D_801D4530, D_801E7D14[(s16)p->unk0 >> 1], D_801E7E18, (s16)D_801E7D24[(s16)p->unk0]);
                    }
                }
                p->unk0++;
            } while (p->unk2 == 0);
        }
        if (p->unk0 & 1) {
            func_801B1FF0(D_801D4530, D_801E7E18);
        }
        p->unk2--;
        if (p->unk0 < 8) {
            for (i = 0; i < 3; i++) {
                sv = &D_801D4530[func_80042DA8() % 136];
                q = (LamTask *)&D_80162978[func_800BBEAC(&func_801B1C24)];
                q->unk4 = sv->vx;
                q->unk6 = sv->vy;
                q->unk8 = sv->vz;
                r = func_80042DA8() % 256;
                q->unkC = sv->vx * r >> 12;
                q->unkE = -(func_80042DA8() % 100 + 0xC8);
                q->unk10 = sv->vz * r >> 12;
                q->unk18 = (func_80042DA8() & 0xF) - 8;
                q->unk19 = (func_80042DA8() & 0xF) - 8;
                q->unk1A = (func_80042DA8() & 0xF) - 8;
                q->unk1C = func_80042DA8() % 0x1000 + 0x1000;
            }
            func_8003B48C(&D_801E8258);
            func_8003B51C(&D_801E8258);
            i = 0;
            do {
                i++;
                q = (LamTask *)&D_80162978[func_800BBEAC(&func_801B1E2C)];
                r = func_80042DA8() & 0xFFF;
                sc->vx = (u32)(func_80039A74(r) * 0x271) >> 10;
                sc->vy = 0;
                sc->vz = func_80039B40(r) * 0x9C4 >> 12;
                func_8003BC6C(sc, out, &flag);
                q->unk4 = out->vx;
                q->unk6 = out->vy;
                q->unk8 = out->vz;
                q->unk1C = func_80042DA8() % 0x3000 + 0x1000;
            } while (i < 3);
        }
    }
}

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B24A8);

void func_801B2640(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        k = (t << 11) / 5;
    } else {
        p->unk0 = -1;
        return;
    }
    func_800D4368(&p->unk4, k, 0);
    D_801E7D3C[0] = p->unk2 % D_801D4018;
    D_80163C74 = func_801B13A0((u8 *)D_801E7D3C - 8, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B275C(void) {
    MgTask *p;
    s32 t;
    s32 k;
    s32 c;
    s32 u;
    s32 w;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        c = 0x3200FFFF;
        k = (t << 11) / 5;
    } else {
        t -= 10;
        if (t < 5) {
            k = 0x2000;
            c = t * -0xFF / 5 + 0xFF;
            u = c << 8;
            w = c | 0x32000000;
            c = u | w;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_800D4368(&p->unk4, k, 0);
    func_801B24A8(c);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B2870);

void func_801B2B38(void) {
    MgTask *p;
    MgTask *q;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B2870)];
            q->unk8 = 0;
            q->unk6 = 0;
            q->unk4 = 0;
            q->unkC = func_80042DA8() % 432 - 0x600;
            q->unkE = (i << 9) + func_80042DA8() % 256;
            q->unk10 = 0;
            i++;
        } while (i < 8);
        p->unk0 = -1;
    }
}

void func_801B2C3C(void) {
    MgTask *p;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0) {
        c = 0x80;
        goto store;
    }
    if (t < 0x14) {
        c = -(t << 7) / 20 - 0x80;
store:
        D_801E7D80 = D_801E7D81 = D_801E7D82 = c;
    } else {
        p->unk0 = -1;
        return;
    }
    func_800D4368(&p->unk4, 0x4000, -0x1F4);
    D_801E7D84[0] = p->unk2 % D_801D4018;
    D_80163C74 = func_800D4D90((u8 *)D_801E7D84 - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B2D80(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_801E7D94.m[0][0] = D_801E7D9C.v = p->unk1C;
    D_801E7DA8.v = p->unk4;
    D_801E7DAC.v = p->unk6;
    D_801E7DB0.v = p->unk8;
    func_8003B48C(&D_801E7D94);
    func_8003B51C(&D_801E7D94);
    D_801E7D90[0] = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)D_801E7D90 - 8, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D42CC[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B2E90(void) {
    MgTask *p;
    MgTask *q;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            i++;
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B2D80)];
            q->unk4 = func_80042DA8() % 2560 - 0x500;
            q->unk6 = func_80042DA8() % 1920 - 0x3C0;
            q->unk8 = 0x1000;
            q->unk1C = func_80042DA8() % 3072 + 0x400;
        } while (i < 2);
        p->unk2++;
        if (p->unk2 >= 0x2D) {
            p->unk0 = -1;
        }
    }
}

void func_801B2FF0(void) {
    MgVec v;
    MgMat m;
    s32 flag;

    func_800D41FC(D_800FA63C, D_80154650, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003BC6C(&D_801E7DB4, &v, &flag);
    v.vx -= D_801E826C[0];
    v.vy -= D_801E8270;
    v.vz -= D_801E8274;
    func_8003BF3C((u8 *)D_801E826C - 0x14, &m);
    func_8003AB84(&m, &v, &v);
    D_801E7AE4 = v.vx;
    D_801E7AE6 = v.vy;
    D_801E7AE8 = v.vz;
}

void func_801B30D0(void) {
    MgTask *p;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 10; i++) {
        if ((D_801E8278 >> i) & 1) {
            if (p->unk2 & 1) {
                D_80151A4C[i][0] += p->unk0;
            } else {
                D_80151A4C[i][0] -= p->unk0;
            }
        }
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3180(s32 arg0) {
    if (arg0 != 0) {
        if (D_801E7DBC == NULL) {
            D_801E7DBC = &D_80162978[func_800BBEAC(&func_801B30D0)];
        }
        D_801E7DBC->unk0 = arg0;
        return;
    }
    if (D_801E7DBC != NULL) {
        D_801E7DBC->unk0 = -1;
        D_801E7DBC = NULL;
    }
}

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B3214);

s32 func_801B38E8(arg0, arg1) {
    s32 i;
    s32 v;
    s32 t;

    func_800D2980(D_801B3A9C, 0, 0, 0);
    D_801E8270 = 0;
    D_801E826C[0] = 0;
    D_801E8278 = arg0;
    func_800D54EC(arg0, (void *)0x1F800000);
    v = *(s16 *)0x1F800004;
    if (v < D_80151A50[arg1][0]) {
        D_801E8274 = v + 0x1388;
        D_801E7ADA = 0x800;
    } else {
        D_801E8274 = v - 0x1388;
        D_801E7ADA = 0;
    }
    func_8003C21C(&D_801E7AD8, &D_801E8258);
    for (i = 0; i < 10; i++) {
        if ((D_801E8278 >> i) & 1) {
            D_801E827C[i] = *(LamB8 *)D_80151A4C[i];
        }
    }
    func_800BBEAC(&func_801B3214);
    t = func_80042DA8() & 0x100;
    if (t) {
        ((void (*)(s32, s32, s32))func_801B102C)((s32)D_801E7AEC, (s32)&D_801E8258, arg1);
    } else {
        ((void (*)(s32, s32, s32))func_801B102C)((s32)D_801E7BB0, (s32)&D_801E8258, arg1);
    }
    D_800F8380 |= 8;
}
