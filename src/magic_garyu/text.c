#include "common.h"
#include "magic_garyu/decls.h"

M2C_UNK *func_801B0060(void) {
    func_801B36B0();
    return &D_801D48D8;
}

M2C_UNK *func_801B0088(void) {
    func_801B3780();
    return &D_801D48D8;
}

void func_801B00B0(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    void *tbl;
    s32 t;

    p = &D_801621F0[D_801590D4];
    rot.vx = p->unk14;
    rot.vy = 0;
    rot.vz = p->unk18;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    t = p->unk1C;
    scale.vx = scale.vy = scale.vz = t;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    tbl = D_801D6268[p->unk1E];
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = tbl;
    if (p->unk2 >= 0xE) {
        ((MgScratch *)0x1F800000)->unk4 = 8;
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0xE) * 0x15;
    }
    D_801D62EC = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D62EC);
    if (p->unk2 >= 0x14) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk6 += p->unkE;
        p->unkE += (s16)p->unkE >> 3;
        p->unk14 += p->unk16;
        p->unk2++;
        p->unk18 += p->unk1A;
    }
}

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B02B0);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B0480);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B0808);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B0C9C);

void func_801B12FC(MgMat *arg0, u16 *arg1, u16 *arg2) {
    u16 v[3];
    MgMat m1;
    MgMat m2;

    v[0] = arg0->t[0] - D_800FA63C.t[0];
    v[1] = arg0->t[1] - D_800FA63C.t[1];
    v[2] = arg0->t[2] - D_800FA63C.t[2];
    func_8003BF3C(&D_800FA63C, &m1);
    func_8003B2CC(&m1, v, v);
    func_8003A79C(&m1, arg0, &m2);
    func_8003B2CC(&m2, arg1, arg2);
    arg2[0] += v[0];
    arg2[1] += v[1];
    arg2[2] += v[2];
}

void func_801B1400(void) {
    MgTask *e;
    u16 *q;
    u16 *p0;
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 r;
    s32 s;
    s32 n;
    s32 u;

    e = &D_801621F0[D_801590D4];
    for (i = 0; i < 0x8C; i++) {
        if (D_801D90B0[i].unk0 != 0) {
            D_801D62BC[0] = D_801D90B0[i].unk2 << 1;
            func_800D4368(&D_801D90B0[i].unk4, D_801D90B0[i].unk16, -(D_801D90B0[i].unk16 >> 3));
            D_801D62EC = func_800D4D90(&D_801D62BC[-4], D_801517C0 + 0x70, 0xC, D_801D62EC);
            if (D_80062D98 == 0) {
                D_801D90B0[i].unk4 += D_801D90B0[i].unkC;
                D_801D90B0[i].unk8 += D_801D90B0[i].unk10;
                D_801D90B0[i].unkC -= D_801D90B0[i].unkC >> 3;
                D_801D90B0[i].unk10 -= D_801D90B0[i].unk10 >> 3;
                if (D_801D90B0[i].unk2 >= 7) {
                    D_801D90B0[i].unk0 = 0;
                }
                D_801D90B0[i].unk2++;
            }
        }
    }
    if (D_80062D98 == 0) {
        if (e->unk2 >= 0x4B) {
            e->unk0 = -1;
        }
        if (e->unk2 < 0x41) {
            p0 = &D_801D9DD6;
            s = (s16)((s16)p0[0] / 3) << 4;
            i = 0;
            q = &D_801D9DD6;
            do {
                for (j = 0; j < 0x8C; j++) {
                    if (D_801D90B0[j].unk0 == 0) {
                        break;
                    }
                }
                if (j >= 0x8C) {
                    break;
                }
                D_801D90B0[j].unk0 = 1;
                D_801D90B0[j].unk2 = 0;
                r = func_80042DA8();
                a = r / 0x1000;
                a = r - a * 0x1000;
                b = func_80042DA8();
                n = (s16)q[0];
                b = n + b % (n >> 2);
                D_801D90B0[j].unk4 = q[-3] + ((func_80039B40(a) * b) >> 12);
                D_801D90B0[j].unk6 = 0;
                D_801D90B0[j].unk8 = q[-1] - ((func_80039A74(a) * b) >> 12);
                i++;
                u = 0x3C;
                b = func_80042DA8() % 50 + (e->unk2 * 8 + u);
                D_801D90B0[j].unkC = (func_80039B40(a) * b) >> 12;
                D_801D90B0[j].unk10 = -((func_80039A74(a) * b) >> 12);
                u = 0x800;
                a = func_80042DA8() % 2560 + (e->unk2 * 8 + u);
                D_801D90B0[j].unk16 = (s * a) >> 12;
            } while (i < 9);
        }
        e->unk2++;
    }
}

void func_801B18DC(void) {
    u8 pad[8];
    MgTask *e;
    MgPart18 *base;
    MgPart18 *p;
    u16 *frame;
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 r;
    s32 s;

    i = 0;
    e = &D_80162978[D_8015169C];
    base = D_801D63B0[e->unk1C];
    frame = D_801D62C8;
    do {
        p = &base[i];
        if (p->unk0 != 0) {
            frame[0] = p->unk2;
            func_800D4368(&p->unk4, p->unk16, -(p->unk16 >> 3));
            D_801D62EC = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801D62EC);
            if (D_80062D98 == 0) {
                p->unk4 += p->unkC;
                p->unk8 += p->unk10;
                p->unkC -= p->unkC >> 3;
                p->unk10 -= p->unk10 >> 3;
                if (p->unk2 >= 0xF) {
                    p->unk0 = 0;
                }
                p->unk2++;
            }
        }
        i++;
    } while (i < 0x30);
    if (D_80062D98 == 0) {
        if (e->unk2 >= 0x14) {
            e->unk0 = -1;
        }
        if (e->unk2 < e->unk18) {
            i = 0;
            s = e->unk10 * 0x10;
            if (e->unk1A > 0) {
                do {
                    for (j = 0; j < 0x30; j++) {
                        if (base[j].unk0 == 0) {
                            break;
                        }
                    }
                    if (j >= 0x30) {
                        break;
                    }
                    p = (MgPart18 *)(j * 0x18 + (s32)base);
                    p->unk0 = 1;
                    p->unk2 = 0;
                    r = func_80042DA8();
                    a = r / 0x1000;
                    a = r - a * 0x1000;
                    b = e->unk14 + func_80042DA8() % e->unk16;
                    p->unk4 = e->unk4 + ((func_80039B40(a) * b) >> 12);
                    p->unk6 = e->unk6;
                    p->unk8 = e->unk8 - ((func_80039A74(a) * b) >> 12);
                    b = e->unkC + func_80042DA8() % e->unkE + (e->unk14 >> 4);
                    p->unkC = (func_80039B40(a) * b) >> 12;
                    p->unk10 = -((func_80039A74(a) * b) >> 12);
                    a = func_80042DA8() % 2816 + 0x600;
                    p->unk16 = (s * a) >> 12;
                    i++;
                } while (i < e->unk1A);
            }
        }
        e->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B1C9C);

void func_801B2654(void) {
    MgTask *p;
    s32 t;
    s32 c;
    s16 v;
    s16 *q;
    s8 *frame;

    p = &D_80162978[D_8015169C];
    D_801D62D4[0] = p->unk2;
    t = p->unk2;
    if (t >= 7) {
        c = 0x60 - (t - 7) * 0xC;
    } else {
        c = 0x60;
    }
    frame = &D_801D62D0;
    q = &p->unk1C;
    *frame = D_801D62D1 = D_801D62D2 = c;
    v = (u16)*q;
    func_800D4368(&p->unk4, v, -(v >> 3));
    D_801D62EC = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801D62EC);
    if (p->unk2 >= 0xF) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk8 += p->unk10;
        p->unk2++;
        p->unkC -= (s16)p->unkC >> 3;
        p->unk10 -= (s16)p->unk10 >> 3;
    }
}

void func_801B27B0(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 t;
    s16 h;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    t = p->unk14 * D_801D62D8[p->unk2] >> 12;
    scale.vx = scale.vy = scale.vz = t;
    func_8003B35C(&m, &scale);
    h = (u16)p->unk14;
    func_800D4284(&p->unk4, -(h >> 3), &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = &D_801D3A04;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801D62EC = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D62EC);
    if (p->unk2 >= 3) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2 += 1;
    }
}

void func_801B2918(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgSVec w;
    MgTask *p;
    s16 *q;
    s32 t;
    s16 h;

    rot.vx = 0;
    rot.vy = 0;
    p = &D_80162978[D_8015169C];
    rot.vz = p->unkC;
    func_8003BF8C(&rot, &m);
    t = p->unk14;
    scale.vx = scale.vy = scale.vz = t;
    func_8003B35C(&m, &scale);
    q = &p->unk4;
    w.vx = 0;
    w.vy = 0;
    w.vz = -0x22B;
    func_801B12FC((MgMat *)((u8 *)D_800FA6E0 + (D_801D62F8 << 6)), (u16 *)&w, (u16 *)q);
    h = (u16)p->unk14;
    func_800D4284(q, -(h >> 3), &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = &D_801D3DE0;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801D62EC = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D62EC);
    if (p->unk2 >= 0xC) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        if (p->unk2 < 5) {
            p->unk14 += p->unk16;
        }
        if (p->unk2 >= 6) {
            p->unk14 -= p->unk1A;
        }
        p->unk2 += 1;
    }
}

void func_801B2AF4(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 ang;
    s32 r;
    s32 mul;
    u8 pad[8];

    if (D_80062D98 == 0) {
        mul = 0xDC0;
        i = 0;
        p = &D_80162978[D_8015169C];
        if (p->unk1A > 0) {
            do {
                q = &D_80162978[func_800BBEAC((void *)func_801B2654)];
                ang = func_80042DA8() % 0x1000;
                r = p->unk14 + func_80042DA8() % p->unk16;
                q->unk4 = p->unk4 + (func_80039B40(ang) * r >> 12);
                q->unk6 = p->unk6;
                q->unk8 = p->unk8 + (func_80039A74(ang) * r >> 12);
                r = p->unkC + func_80042DA8() % p->unkE;
                q->unkC = func_80039B40(ang) * r >> 12;
                q->unkE = 0;
                q->unk10 = func_80039A74(ang) * r >> 12;
                ang = func_80042DA8() % 2560 + 0x800;
                q->unk1C = mul * ang >> 12;
                i++;
            } while (i < p->unk1A);
        }
        if (p->unk2 >= p->unk18) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B2D34);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B3434);

void func_801B35F0(void) {
    MgTask *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    if (D_801D9F90 & p->unk1C) {
        t = (u16)p->unk2 + 1;
        p->unk2 = t;
        if (t >= 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B3654(void) {
    s32 var_v1;

    if (D_800F8368 != 0) {
        var_v1 = D_801D62E8 + 0xE000;
    } else {
        var_v1 = D_801D62E8;
    }
    D_801D62EC = var_v1;
    if (D_801D9F90 < 0) {
        *D_801D62F0 = -1;
    }
}

s32 func_801B36B0(arg0, arg1) {
    s32 r;

    D_801D62E8 = (s32)&D_801B381C;
    D_801D62F0 = (s32 *)&D_801621F0[func_800BC04C((void *)func_801B3654)];
    func_800D2980(&D_801B381C, 0, 0, 0);
    D_80162994[func_800BBEAC((void *)func_801B35F0)].unk0 = 0x40;
    r = func_800BBEAC((void *)func_801B3434);
    D_801D62F4 = arg0;
    D_801D62F8 = arg1;
    D_801D9F90 = 0;
    return r;
}

void func_801B3780(arg0, arg1) {
    D_80162994[func_800BBEAC((void *)func_801B35F0)].unk0 = 0x80;
    D_801D9F90 &= 0xBFFFFFFF;
    if (arg0 == (1 << arg1)) {
        D_801D9F90 |= 0x20000000;
    }
    D_801D62F4 = arg0;
    D_801D62F8 = arg1;
}

INCLUDE_RODATA("../asm/us/magic_garyu/nonmatchings/text", D_801B0000);
