#include "common.h"
#include "magic_brizag/decls.h"

void func_801B0054(void) {
    func_801B324C();
}

u16 *func_801B0074(BzCtx2 *arg0, u8 *arg1, s32 *arg2) {
    u16 *e;
    s16 *a;
    s32 i;
    s32 n;
    s32 cnt;
    s32 k;
    s32 u;
    s32 x;
    s32 y;
    s32 z;
    s32 r;

    e = (u16 *)(arg2 + 1);
    n = arg0->unk24;
    cnt = *arg2;
    i = 0;
    k = 0x49DA40 / arg0->unk14;
    u = arg0->unk18;
    for (; i < cnt; i++) {
        a = (s16 *)(arg1 + e[0]);
        x = a[0];
        y = a[1];
        z = a[2];
        a = (s16 *)(arg1 + e[1]);
        x += a[0];
        y += a[1];
        z += a[2];
        a = (s16 *)(arg1 + e[2]);
        x += a[0];
        y += a[1];
        z += a[2];
        x /= 3;
        y /= 3;
        z /= 3;
        D_801D9610[n].a[1] = y;
        y += 0x898;
        y = y * y / k;
        D_801D9610[n].a[0] = x;
        D_801D9610[n].a[2] = z;
        D_801D9610[n].f6 = y;
        D_801D9610[n].b[0] = D_801D9610[n].b[1] = D_801D9610[n].b[2] = D_801D9610[n].fE = 0;
        r = func_80042DA8();
        if (r & 0x800) {
            D_801D9610[n].c[0] = (r & 7) * 12;
        } else {
            D_801D9610[n].c[0] = -((r & 7) * 12);
        }
        D_801D9610[n].c[1] = 0;
        if (r & 0x204080) {
            D_801D9610[n].c[2] = ((r >> 3) & 7) * 12;
        } else {
            D_801D9610[n].c[2] = -(((r >> 3) & 7) * 12);
        }
        D_801D9610[n].f16 = -((y + u) * ((r & 3) + 2));
        n++;
        e += 10;
    }
    arg0->unk24 = n;
    return e;
}

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B0368);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B03C0);

s32 func_801B0A8C(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801C0DB0[a];
        } else {
            r = D_801C0DB0[0x800 - a];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801C0DB0[a - 0x800];
        } else {
            r = -D_801C0DB0[0x1000 - a];
        }
    }
    return r;
}

s32 func_801B0B30(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801C0DB0[0x400 - a];
        } else {
            r = -D_801C0DB0[a - 0x400];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801C0DB0[0xC00 - a];
        } else {
            r = D_801C0DB0[a - 0xC00];
        }
    }
    return r;
}

void func_801B0BCC(s16 *arg0, s16 *arg1, s32 *arg2) {
    s32 cx;
    s32 cy;
    s32 cz;
    s32 sx;
    s32 sy;
    s32 sz;
    s32 m0;
    s32 m1;
    s32 m2;
    s32 m3;
    s32 m4;
    s32 m5;
    s32 m6;
    s32 m7;
    s32 m8;

    cx = func_801B0B30(arg0[0]);
    cy = func_801B0B30(arg0[1]);
    cz = func_801B0B30(arg0[2]);
    sx = func_801B0A8C(arg0[0]);
    sy = func_801B0A8C(arg0[1]);
    sz = func_801B0A8C(arg0[2]);
    m0 = (((cz * cy) >> 12) * arg2[0]) >> 12;
    m3 = ((((sz * cx) >> 12) - (((cz * -sy >> 12) * sx) >> 12)) * arg2[0]) >> 12;
    m6 = ((((sz * sx) >> 12) + (((cz * -sy >> 12) * cx) >> 12)) * arg2[0]) >> 12;
    m1 = (((-sz * cy) >> 12) * arg2[1]) >> 12;
    m4 = ((((cz * cx) >> 12) + (((sz * -sy >> 12) * sx) >> 12)) * arg2[1]) >> 12;
    m7 = ((((cz * sx) >> 12) - (((sz * -sy >> 12) * cx) >> 12)) * arg2[1]) >> 12;
    m2 = (sy * arg2[2]) >> 12;
    m5 = (((-cy * sx) >> 12) * arg2[2]) >> 12;
    m8 = (((cy * cx) >> 12) * arg2[2]) >> 12;
    arg1[0] = m0;
    arg1[3] = m3;
    arg1[6] = m6;
    arg1[1] = m1;
    arg1[4] = m4;
    arg1[7] = m7;
    arg1[2] = m2;
    arg1[5] = m5;
    arg1[8] = m8;
}

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B0DD0);

u16 *func_801B0E48(BzCtx *arg0, u8 *arg1, s32 *arg2) {
    u16 *d;
    s16 *v0;
    s16 *v1;
    s16 *v2;
    s32 n;
    s32 m;
    s32 i;
    s32 t;

    d = (u16 *)(arg2 + 1);
    n = *arg2;
    m = arg0->unk24;
    for (i = 0; i < n; m++, d += 10, i++) {
        v1 = (s16 *)(arg1 + d[1]);
        v0 = (s16 *)(arg1 + d[2]);
        v2 = (s16 *)(arg1 + d[0]);
        arg0->e1.vx = v1[0] - v0[0];
        arg0->e1.vy = v1[1] - v0[1];
        arg0->e1.vz = v1[2] - v0[2];
        arg0->e2.vx = v2[0] - v1[0];
        arg0->e2.vy = v2[1] - v1[1];
        arg0->e2.vz = v2[2] - v1[2];
        func_8003BA10(&arg0->e1, &arg0->e2, &arg0->n);
        func_8003A08C(&arg0->n, &arg0->n);
        D_801D9610[m].a[0] = D_801D9610[m].a[1] = D_801D9610[m].a[2] = 0;
        if (i < 0x80) {
            arg0->n.vx = -arg0->n.vx;
            arg0->n.vy = -arg0->n.vy;
            arg0->n.vz = -arg0->n.vz;
        }
        t = func_80042DA8() % 120 + 0x118;
        D_801D9610[m].b[0] = t * arg0->n.vx >> 12;
        D_801D9610[m].b[1] = t * arg0->n.vy >> 12;
        D_801D9610[m].b[2] = t * arg0->n.vz >> 12;
        t = func_80042DA8() % 12 + 9;
        D_801D9610[m].c[0] = t * arg0->n.vx >> 12;
        D_801D9610[m].c[1] = t * arg0->n.vy >> 12;
        D_801D9610[m].c[2] = t * arg0->n.vz >> 12;
    }
    arg0->unk24 = m;
    return d;
}

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B1114);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B116C);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B15A8);

void func_801B16B0(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s16 v;
    s32 i;
    s32 mask;

    p = &D_80162978[D_8015169C];
    func_8003B69C(0, 0, 0);
    if (p->unk2 < 0xB) {
        rot.vx = 0;
        rot.vy = 0;
        rot.vz = 0;
        func_8003BF8C(&rot, &m);
        m.t[0] = p->unk4;
        m.t[1] = p->unk6;
        m.t[2] = p->unk8;
        scale.vx = scale.vy = scale.vz = p->unk10;
        func_8003B35C(&m, &scale);
        func_8003A63C(&D_800FA63C, &m, &m);
        func_8003B48C(&m);
        func_8003B51C(&m);
        if (p->unk2 < 8) {
            v = 0x1000 - p->unk2 * 0x200;
            if (v < 0) {
                v = 0;
            }
        } else {
            v = 0;
        }
        ((MgScratch *)0x1F800000)->unkA = v;
        ((MgScratch *)0x1F800000)->unk0 = D_801BF4CC;
        ((MgScratch *)0x1F800000)->unk4 = 0x88;
        ((MgScratch *)0x1F800000)->unk8 = 0;
        ((MgScratch *)0x1F800000)->unkC = 0x20;
        ((MgScratch *)0x1F800000)->unkE = 0;
        D_801D95FC = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D95FC);
    } else {
        ((BzScr2 *)0x1F800000)->unk0 = D_801BF4CC;
        ((BzScr2 *)0x1F800000)->unk8 = 0xC;
        ((BzScr2 *)0x1F800000)->unk28 = 3;
        ((BzScr2 *)0x1F800000)->unk4 = D_801517C0 + 0x70;
        ((BzScr2 *)0x1F800000)->unkC = D_801D95FC;
        ((BzScr2 *)0x1F800000)->unk2C = D_800FA63C;
        ((BzScr2 *)0x1F800000)->unk6C = ((BzScr2 *)0x1F800000)->unk70 = ((BzScr2 *)0x1F800000)->unk74 = p->unk10;
        ((BzScr2 *)0x1F800000)->unkAC = *(BzB8 *)&p->unk4;
        D_801D95FC = func_801B0DD0((void *)0x1F800000, p->unk2 - 5);
    }
    v = 0x800;
    if (p->unk2 >= 0x17) {
        v = 0x800 - (p->unk2 - 0x17) * 0xCC;
        if (v < 0) {
            v = 0;
        }
    }
    if (p->unk2 >= 0x21) {
        v = 0;
        p->unk0 = -1;
    }
    D_800F5B74.v = v;
    if (D_80062D98 == 0) {
        if (p->unk2 == 0xF) {
            i = 0;
            mask = 1;
            for (; i < 10; i++) {
                if (mask << i & D_801D9604) {
                    func_800D5774(i);
                }
            }
        }
        p->unk2++;
    }
}

void func_801B19FC(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s16 v;
    s32 i;
    s32 mask;

    p = &D_80162978[D_8015169C];
    func_8003B69C(0, 0, 0);
    if (p->unk2 < 2) {
        rot.vx = 0;
        rot.vy = 0;
        rot.vz = 0;
        func_8003BF8C(&rot, &m);
        m.t[0] = p->unk4;
        m.t[1] = p->unk6;
        m.t[2] = p->unk8;
        scale.vx = scale.vy = scale.vz = p->unk10;
        func_8003B35C(&m, &scale);
        func_8003A63C(&D_800FA63C, &m, &m);
        func_8003B48C(&m);
        func_8003B51C(&m);
        if (p->unk2 < 2) {
            v = 0x1000 - p->unk2 * 0x800;
            if (v < 0) {
                v = 0;
            }
        } else {
            v = 0;
        }
        ((MgScratch *)0x1F800000)->unkA = v;
        ((MgScratch *)0x1F800000)->unk0 = D_801BF4CC;
        ((MgScratch *)0x1F800000)->unk4 = 0x88;
        ((MgScratch *)0x1F800000)->unk8 = 0;
        ((MgScratch *)0x1F800000)->unkC = 0x20;
        ((MgScratch *)0x1F800000)->unkE = 0;
        D_801D95FC = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D95FC);
    } else {
        ((BzScr *)0x1F800000)->unk0 = D_801BF4CC;
        ((BzScr *)0x1F800000)->unk8 = 0xC;
        ((BzScr *)0x1F800000)->unk4 = D_801517C0 + 0x70;
        ((BzScr *)0x1F800000)->unkC = D_801D95FC;
        ((BzScr *)0x1F800000)->unk2C = D_800FA63C;
        ((BzScr *)0x1F800000)->unk6C = ((BzScr *)0x1F800000)->unk70 = ((BzScr *)0x1F800000)->unk74 = p->unk10;
        ((BzScr *)0x1F800000)->unkAC = *(BzB8 *)&p->unk4;
        D_801D95FC = func_801B15A8((void *)0x1F800000, p->unk2 - 2);
    }
    v = 0x800;
    if (p->unk2 >= 0x17) {
        v = 0x800 - (p->unk2 - 0x17) * 0xCC;
        if (v < 0) {
            v = 0;
        }
    }
    if (p->unk2 >= 0x22) {
        v = 0;
        p->unk0 = -1;
    }
    D_800F5B74.v = v;
    if (D_80062D98 == 0) {
        if (p->unk2 == 8) {
            i = 0;
            mask = 1;
            for (; i < 10; i++) {
                if (mask << i & D_801D9604) {
                    func_800D5774(i);
                }
            }
        }
        p->unk2++;
    }
}

void func_801B1D3C(void) {
    MgSVec rot;
    MgSVec pad;
    MgSVec v;
    MgMat m;
    MgMat pad2;
    MgVec scale;
    MgTask *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unkC;
    rot.vy = p->unkE;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    v.vx = 0;
    v.vy = -p->unk14;
    v.vz = 0;
    func_8003B27C(&m, &v, (MgVec *)m.t);
    m.t[0] += p->unk4;
    m.t[1] += p->unk6;
    m.t[2] += p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk10;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801BF388;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801D95FC = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D95FC);
    if (p->unk2 >= p->unk18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        t = p->unk14 - p->unk16;
        p->unk14 = t;
        if (t < 0) {
            p->unk14 = 0;
        }
        p->unk2++;
    }
}

void func_801B1F08(void) {
    MgSVec rot;
    s32 c;
    MgSVec pad;
    MgSVec v;
    MgMat m;
    MgMat pad2;
    MgVec scale;
    MgTask *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unkC;
    rot.vy = p->unkE;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    v.vx = 0;
    v.vy = -p->unk14;
    v.vz = 0;
    func_8003B27C(&m, &v, (MgVec *)m.t);
    m.t[0] += p->unk4;
    m.t[1] += p->unk6;
    m.t[2] += p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk10;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    ((MgScratch *)0x1F800000)->unk0 = D_801BF388;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= p->unk18) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - p->unk18) * 0x15;
    }
    D_801D95FC = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D95FC);
    if (p->unk2 >= p->unk18 + 6) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        t = p->unk14 - p->unk16;
        p->unk14 = t;
        if (t < 0) {
            p->unk14 = 0;
        }
        p->unk2++;
    }
}

void func_801B210C(void) {
    MgTask *p;
    MgTask *q;
    s32 k;
    s32 i;
    s32 t;
    s32 w;
    s16 r;
    s16 d;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        k = p->unk1A;
        if (p->unk2 == D_801C15CC[k] && k < 6) {
            t = p->unk10;
            if (t > 0x3E8) {
                t = 0x3E8;
            }
            i = 0;
            w = (t << 12) / 1250;
            do {
                if (k < 3) {
                    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1F08)];
                    q->unk14 = func_80042DA8() % 2000 + 0xFA0;
                    d = (u16)D_801C15D8[k] + (q->unk14 & 3);
                    q->unk18 = d;
                    q->unk16 = q->unk14 / d;
                } else {
                    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1D3C)];
                    r = func_80042DA8() % 2000 + 0xFA0;
                    q->unk14 = r;
                    q->unk16 = r / (D_801C15D8[k] + (r & 3));
                    q->unk18 = 0x18 - (u16)D_801C15CC[k];
                }
                *(BzB8 *)&q->unk4 = *(BzB8 *)&p->unk4;
                q->unkC = D_801C15B4[i] + D_801C15E4[k];
                q->unkE = D_801C15C0[i] + D_801C15F0[k];
                q->unk10 = w;
            } while (++i < 6);
            k++;
            p->unk1A = k;
        }
        if (p->unk2 == 0x18) {
            func_800D5138(1);
        } else if (p->unk2 == 0x1A) {
            func_800D51D4(4);
            q = &D_80162978[func_800BBEAC((M2C_UNK *)(p->unk18 ? func_801B19FC : func_801B16B0))];
            *(BzB8 *)&q->unk4 = *(BzB8 *)&p->unk4;
            q->unk10 = (p->unk10 << 12) / 1000;
            p->unk0 = -1;
        }
        if (p->unk18 == 0) {
            if (p->unk2 < 10) {
                D_800F5B70.v = D_800F5B71.v = D_800F5B72.v = 0;
                D_800F5B74.v = p->unk2 * 0xCC;
            } else {
                D_800F5B74.v = 0x800;
            }
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B254C);

void func_801B2DF0(void) {
    MgTask *p;
    MgTask *q;
    BzRec *r;
    s32 i;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 < 4) {
            for (i = 0; i < 0x12; i++) {
                if (p->unk2 == D_801C0B70[i].t) {
                    r = (BzRec *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B254C)];
                    r->w[0] = D_801C0B74[i * 8 + 0];
                    r->w[1] = D_801C0B74[i * 8 + 1];
                    r->w[2] = D_801C0B74[i * 8 + 2];
                    r->w[3] = D_801C0B74[i * 8 + 3];
                    r->w[4] = D_801C0B74[i * 8 + 4];
                    r->w[5] = D_801C0B74[i * 8 + 5];
                    r->w[6] = D_801C0B74[i * 8 + 6];
                }
            }
        }
        if (p->unk2 == 0x14) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B210C)];
            *(BzB8 *)&q->unk4 = *(BzB8 *)&p->unk4;
            q->unk10 = p->unk10;
            q->unk18 = 1;
            q->unk1A = 0;
            func_800D55F4(0x28, func_800D574C(D_801D9604), 0x79);
        }
        if (p->unk2 < 10) {
            D_800F5B70.v = D_800F5B71.v = D_800F5B72.v = 0;
            D_800F5B74.v = p->unk2 * 0xCC;
        } else {
            D_800F5B74.v = 0x800;
        }
        if (p->unk2 >= 0x32) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B303C(void) {
    MgTask *p;
    MgTask *a;
    s32 i;
    s32 n;
    s32 k;
    s16 t;

    i = 0;
    n = 0;
    for (; i < 10; i++) {
        if (1 << i & D_801D9604) {
            n++;
            if (n == 1) {
                k = i;
            }
        }
    }
    D_80162978[D_8015169C].unk0 = -1;
    a = D_80162978;
    ((BzScratch *)0x1F800000)->unk0 = D_801BF4CC;
    ((BzScratch *)0x1F800000)->unk14 = 10;
    ((BzScratch *)0x1F800000)->unk18 = 12;
    if (n == 1) {
        p = &a[func_800BBEAC((M2C_UNK *)func_801B210C)];
        func_800D3994(k, D_8015190F[k][0], &p->unk4);
        t = D_801518F6[k][0] + 0x100;
        p->unk10 = t;
        if (t >= 0x66D) {
            p->unk10 = 0x66C;
        }
        p->unk18 = p->unk1A = 0;
        func_801B0368((void *)0x1F800000);
        func_800D55F4(0x20, func_800D574C(D_801D9604), 0x79);
    } else {
        p = &a[func_800BBEAC((M2C_UNK *)func_801B2DF0)];
        func_800D54EC(D_801D9604, &p->unk4);
        p->unk6 = -0x500;
        p->unk10 = 0x700;
        D_801D9608 = *(BzB8 *)&p->unk4;
        func_801B1114((void *)0x1F800000);
        func_800D55F4(0x29, func_800D574C(D_801D9604), 0xA3);
    }
}

INCLUDE_RODATA("../asm/us/magic_brizag/nonmatchings/text", D_801B0000);

void func_801B324C(arg0) {
    D_801D9600 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B32C8, 0, 0, 0);
    func_800BBEAC(&func_801B303C);
    D_801D9604 = arg0;
}
