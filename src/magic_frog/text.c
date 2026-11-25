#include "common.h"
#include "magic_frog/decls.h"

void func_801B0008(void) {
    func_801B1E14();
}

u8 *func_801B0028(FrgModel *arg0, u32 *arg1, s32 arg2, u8 *arg3, s16 *arg4, MgMat *arg5, MgMat *arg6) {
    u8 *pk;
    s32 flg;
    s32 otz;
    u8 *base;
    s16 *p;
    s16 *va;
    s16 *vb;
    s16 *vc;
    u32 *ot;
    u16 tpage;
    s32 n;
    s32 i;
    s16 *sc;
    MgMat *sm;

    sc = (s16 *)0x1F800300;
    sm = (MgMat *)0x1F800328;
    base = arg0->data + 4;
    p = (s16 *)(base + *(u32 *)arg0->data);
    n = *p;
    p++;
    tpage = arg0->fC | (*(u16 *)p & 0x19F);
    p++;
    va = (s16 *)(base + p[0]);
    vb = (s16 *)(base + p[1]);
    vc = (s16 *)(base + p[2]);
    pk = arg3;
    for (i = 0; i < n; p += 8, i++) {
        FrgFt3 *r;
        u8 c;
        s32 sh;

        r = (FrgFt3 *)p;
        sc[0x10] = (va[0] + vb[0] + vc[0]) / 3;
        sc[0x11] = (va[1] + vb[1] + vc[1]) / 3;
        sc[0x12] = (va[2] + vb[2] + vc[2]) / 3;
        sc[0] = va[0] - sc[0x10];
        sc[1] = va[1] - sc[0x11];
        sc[2] = va[2] - sc[0x12];
        sc[4] = vb[0] - sc[0x10];
        sc[5] = vb[1] - sc[0x11];
        sc[6] = vb[2] - sc[0x12];
        sc[8] = vc[0] - sc[0x10];
        sc[9] = vc[1] - sc[0x11];
        sc[10] = vc[2] - sc[0x12];
        arg6->t[0] = sc[0x10] + arg4[0];
        arg6->t[1] = sc[0x11] + arg4[1];
        arg6->t[2] = sc[0x12] + arg4[2];
        arg4 += 4;
        gte_SetRotMatrix_d(arg5);
        gte_ldmcol4(arg6, 0);
        gte_mvmva(1, 0, 3, 3, 0);
        gte_stir3h(sm);
        gte_ldmcol4((s16 *)arg6 + 1, 0);
        gte_mvmva(1, 0, 3, 3, 0);
        gte_stir3h((s16 *)sm + 1);
        gte_ldmcol4((s16 *)arg6 + 2, 0);
        gte_mvmva(1, 0, 3, 3, 0);
        gte_stir3h((s16 *)sm + 2);
        gte_SetTransMatrix(arg5);
        gte_ldv0w(&arg6->t);
        gte_mvmva(1, 0, 0, 0, 0);
        gte_stir3(&sm->t, 0);
        gte_SetRotMatrix_d(sm);
        gte_SetTransMatrix(sm);
        gte_ldv3(sc, sc + 4, sc + 8);
        gte_rtpt();
        sh = 14 - arg2;
        va = (s16 *)(base + p[8]);
        vb = (s16 *)(base + p[9]);
        vc = (s16 *)(base + p[10]);
        gte_stflg(&flg);
        if ((flg & 0x60000) == 0) {
            gte_avsz3();
            *(u32 *)pk = 0x07000000;
            gte_stotz(&otz);
            ot = (u32 *)otz;
            ot = (u32 *)((s32)ot >> sh);
            ot = (u32 *)((s32)ot << 2);
            ot = (u32 *)((u32)ot + (u32)arg1);
            ((FrgTag *)pk)->addr = ((FrgTag *)ot)->addr;
            ((FrgTag *)ot)->addr = (u32)pk;
            gte_stsxy3(pk + 8, pk + 0x10, pk + 0x18);
            *(u32 *)(pk + 0xC) = r->uv0;
            *(u16 *)(pk + 0x14) = r->uv1;
            *(u16 *)(pk + 0x1C) = r->uv2;
            *(u16 *)(pk + 0x16) = tpage;
            if (arg0->f4 & 0x80) {
                u32 w = r->col << 16;
                u32 x = (r->col << 8) | 0x24000000;
                *(u32 *)(pk + 4) = w | x | r->col;
            } else {
                u32 w = *(s16 *)((u8 *)arg0 + 0xA) << 16;
                u32 x = (*(s16 *)((u8 *)arg0 + 0xA) << 8) | 0x24000000;
                *(u32 *)(pk + 4) = w | x | *(s16 *)((u8 *)arg0 + 0xA);
            }
            c = pk[7];
            if (arg0->f4 & 8) {
                c |= 2;
            }
            pk[7] = c;
            pk += 0x20;
        }
    }
    p += 2;
    n = *p;
    p += 2;
    va = (s16 *)(base + p[0]);
    vb = (s16 *)(base + p[1]);
    vc = (s16 *)(base + p[2]);
    for (i = 0; i < n; p += 10, i++) {
        FrgG3 *r;
        s32 sh;

        r = (FrgG3 *)p;
        sc[0x10] = (va[0] + vb[0] + vc[0]) / 3;
        sc[0x11] = (va[1] + vb[1] + vc[1]) / 3;
        sc[0x12] = (va[2] + vb[2] + vc[2]) / 3;
        sc[0] = va[0] - sc[0x10];
        sc[1] = va[1] - sc[0x11];
        sc[2] = va[2] - sc[0x12];
        sc[4] = vb[0] - sc[0x10];
        sc[5] = vb[1] - sc[0x11];
        sc[6] = vb[2] - sc[0x12];
        sc[8] = vc[0] - sc[0x10];
        sc[9] = vc[1] - sc[0x11];
        sc[10] = vc[2] - sc[0x12];
        arg6->t[0] = sc[0x10] + arg4[0];
        arg6->t[1] = sc[0x11] + arg4[1];
        arg6->t[2] = sc[0x12] + arg4[2];
        arg4 += 4;
        gte_SetRotMatrix_d(arg5);
        gte_ldmcol4(arg6, 0);
        gte_mvmva(1, 0, 3, 3, 0);
        gte_stir3h(sm);
        gte_ldmcol4((s16 *)arg6 + 1, 0);
        gte_mvmva(1, 0, 3, 3, 0);
        gte_stir3h((s16 *)sm + 1);
        gte_ldmcol4((s16 *)arg6 + 2, 0);
        gte_mvmva(1, 0, 3, 3, 0);
        gte_stir3h((s16 *)sm + 2);
        gte_SetTransMatrix(arg5);
        gte_ldv0w(&arg6->t);
        gte_mvmva(1, 0, 0, 0, 0);
        gte_stir3(&sm->t, 0);
        gte_SetRotMatrix_d(sm);
        gte_SetTransMatrix(sm);
        gte_ldv3(sc, sc + 4, sc + 8);
        gte_rtpt();
        sh = 14 - arg2;
        va = (s16 *)(base + p[10]);
        vb = (s16 *)(base + p[11]);
        vc = (s16 *)(base + p[12]);
        gte_stflg(&flg);
        if ((flg & 0x60000) == 0) {
            gte_avsz3();
            *(u32 *)pk = 0x06000000;
            gte_stotz(&otz);
            ot = (u32 *)otz;
            ot = (u32 *)((s32)ot >> sh);
            ot = (u32 *)((s32)ot << 2);
            ot = (u32 *)((u32)ot + (u32)arg1);
            ((FrgTag *)pk)->addr = ((FrgTag *)ot)->addr;
            ((FrgTag *)ot)->addr = (u32)pk;
            gte_stsxy3(pk + 8, pk + 0x10, pk + 0x18);
            gte_ldrgb3(&r->c0, &r->c1, &r->c2);
            gte_mtc2(8, *(u16 *)((u8 *)arg0 + 0xA));
            gte_dpct();
            gte_strgb3(pk + 4, pk + 0xC, pk + 0x14);
            pk[7] = (arg0->f4 & 8) ? 0x32 : 0x30;
            pk += 0x1C;
        }
    }
    return pk;
}

u8 *func_801B0A50(FrgModel *arg0, u32 *arg1, s32 arg2, u8 *arg3) {
    u8 *pk;
    s32 flg;
    s32 opz;
    s32 otz;
    u8 *base;
    s16 *p;
    u8 *va;
    u8 *vb;
    u8 *vc;
    u32 *ot;
    u16 tpage;
    s32 n;
    s32 i;

    base = arg0->data + 4;
    p = (s16 *)(base + *(u32 *)arg0->data);
    n = *p;
    p++;
    tpage = arg0->fC | (*(u16 *)p & 0x19F);
    p++;
    va = base + p[0];
    vb = base + p[1];
    vc = base + p[2];
    pk = arg3;
    for (i = 0; i < n; p += 8, i++) {
        FrgFt3 *r;

        r = (FrgFt3 *)p;
        gte_ldv3(va, vb, vc);
        gte_rtpt();
        va = base + p[8];
        vb = base + p[9];
        vc = base + p[10];
        gte_stflg(&flg);
        gte_nclip();
        if ((flg & 0x60000) == 0) {
            gte_stopz(&opz);
            if (opz > 0) {
                gte_avsz3();
                *(u32 *)pk = 0x07000000;
                gte_stotz(&otz);
                ot = (u32 *)otz;
                ot = (u32 *)((s32)ot >> (14 - arg2));
                ot = (u32 *)((s32)ot << 2);
                ot = (u32 *)((u32)ot + (u32)arg1);
                ((FrgTag *)pk)->addr = ((FrgTag *)ot)->addr;
                ((FrgTag *)ot)->addr = (u32)pk;
                gte_stsxy3(pk + 8, pk + 0x10, pk + 0x18);
                *(u32 *)(pk + 0xC) = r->uv0;
                *(u16 *)(pk + 0x14) = r->uv1;
                *(u16 *)(pk + 0x1C) = r->uv2;
                *(u16 *)(pk + 0x16) = tpage;
                if (arg0->f4 & 0x80) {
                    u32 w = r->col << 16;
                    u32 x = (r->col << 8) | 0x24000000;
                    *(u32 *)(pk + 4) = w | x | r->col;
                } else {
                    *(u32 *)(pk + 4) = 0x24808080;
                }
                pk += 0x20;
            }
        }
    }
    n = *p;
    p += 2;
    va = base + p[0];
    vb = base + p[1];
    vc = base + p[2];
    for (i = 0; i < n; p += 10, i++) {
        FrgFt4 *r;

        r = (FrgFt4 *)p;
        gte_ldv3(va, vb, vc);
        gte_rtpt();
        va = base + p[10];
        vb = base + p[11];
        vc = base + p[12];
        gte_stflg(&flg);
        gte_nclip();
        if ((flg & 0x60000) == 0) {
            gte_stopz(&opz);
            if (opz >= 0) {
                u32 tg;

                tg = 0x09000000;
                gte_stsxy3(pk + 8, pk + 0x10, pk + 0x18);
                gte_ldv0c(base + r->vi[3]);
                gte_rtps();
                gte_stsxy(pk + 0x20);
                gte_avsz4();
                gte_stotz(&otz);
                ot = (u32 *)otz;
                ot = (u32 *)((s32)ot >> (14 - arg2));
                ot = (u32 *)((s32)ot << 2);
                ot = (u32 *)((u32)ot + (u32)arg1);
                *(u32 *)pk = tg;
                ((FrgTag *)pk)->addr = ((FrgTag *)ot)->addr;
                ((FrgTag *)ot)->addr = (u32)pk;
                *(u32 *)(pk + 0xC) = r->uv0;
                *(u16 *)(pk + 0x14) = r->uv1;
                *(u16 *)(pk + 0x1C) = r->uv2;
                *(u16 *)(pk + 0x24) = r->uv3;
                *(u16 *)(pk + 0x16) = tpage;
                if (arg0->f4 & 0x80) {
                    u32 w = r->col << 16;
                    u32 x = (r->col << 8) | 0x2C000000;
                    *(u32 *)(pk + 4) = w | x | r->col;
                } else {
                    *(u32 *)(pk + 4) = 0x2C808080;
                }
                pk += 0x28;
            }
        }
    }
    n = *p;
    p += 2;
    va = base + p[0];
    vb = base + p[1];
    vc = base + p[2];
    for (i = 0; i < n; p += 10, i++) {
        FrgG3 *r;

        r = (FrgG3 *)p;
        gte_ldv3(va, vb, vc);
        gte_rtpt();
        va = base + p[10];
        vb = base + p[11];
        vc = base + p[12];
        gte_stflg(&flg);
        gte_nclip();
        if ((flg & 0x60000) == 0) {
            gte_stopz(&opz);
            if (opz >= 0) {
                gte_avsz3();
                *(u32 *)pk = 0x06000000;
                gte_stotz(&otz);
                ot = (u32 *)otz;
                ot = (u32 *)((s32)ot >> (14 - arg2));
                ot = (u32 *)((s32)ot << 2);
                ot = (u32 *)((u32)ot + (u32)arg1);
                ((FrgTag *)pk)->addr = ((FrgTag *)ot)->addr;
                ((FrgTag *)ot)->addr = (u32)pk;
                gte_stsxy3(pk + 8, pk + 0x10, pk + 0x18);
                *(u32 *)(pk + 4) = r->c0;
                *(u32 *)(pk + 0xC) = r->c1;
                *(u32 *)(pk + 0x14) = r->c2;
                pk += 0x1C;
            }
        }
    }
    n = *p;
    p += 2;
    va = base + p[0];
    vb = base + p[1];
    vc = base + p[2];
    for (i = 0; i < n; p += 12, i++) {
        FrgG4 *r;

        r = (FrgG4 *)p;
        gte_ldv3(va, vb, vc);
        gte_rtpt();
        va = base + p[12];
        vb = base + p[13];
        vc = base + p[14];
        gte_stflg(&flg);
        gte_nclip();
        if ((flg & 0x60000) == 0) {
            gte_stopz(&opz);
            if (opz >= 0) {
                u32 tg;

                tg = 0x08000000;
                gte_stsxy3(pk + 8, pk + 0x10, pk + 0x18);
                gte_ldv0c(base + r->vi[3]);
                gte_rtps();
                gte_stsxy(pk + 0x20);
                gte_avsz4();
                gte_stotz(&otz);
                ot = (u32 *)otz;
                ot = (u32 *)((s32)ot >> (14 - arg2));
                ot = (u32 *)((s32)ot << 2);
                ot = (u32 *)((u32)ot + (u32)arg1);
                *(u32 *)pk = tg;
                ((FrgTag *)pk)->addr = ((FrgTag *)ot)->addr;
                ((FrgTag *)ot)->addr = (u32)pk;
                *(u32 *)(pk + 4) = r->c0;
                *(u32 *)(pk + 0xC) = r->c1;
                *(u32 *)(pk + 0x14) = r->c2;
                *(u32 *)(pk + 0x1C) = r->c3;
                pk += 0x24;
            }
        }
    }
    return pk;
}

void func_801B1160(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E2AE8 = D_801CAAE8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_RODATA("../asm/us/magic_frog/nonmatchings/text", D_801B0000);

INCLUDE_RODATA("../asm/us/magic_frog/nonmatchings/text", D_801B0004);

void func_801B11CC(void) {
    MgPtrPair tbl;
    MgTask *p;
    s32 **hdr;

    tbl = D_801B0000;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2400, 0);
    hdr = &D_801CAA60;
    M2C_SFIELD(hdr, s32 **, 0) = tbl.ptr[p->unk1A];
    D_801CAA68 = p->unk2;
    D_801E2AE8 = (u8 *)func_800D4D90(hdr, D_801517C0 + 0x70, 0xC, (s32)D_801E2AE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= tbl.ptr[p->unk1A][1]) {
            if (p->unk1A == 0) {
                p->unk1A = 1;
                p->unk2 = 0;
            } else {
                p->unk0 = -1;
            }
        }
    }
}

void func_801B12E8(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    D_801CAA74[0] = p->unk2;
    D_801E2AE8 = func_800D4D90(&D_801CAA74[-4], D_801517C0 + 0x70, 0xC, D_801E2AE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801CA93C) {
            p->unk0 = -1;
        }
    }
}

void func_801B13A0(void) {
    MgTask *p;
    MgMat m;
    MgMat rot;
    s32 flag;
    s16 i;
    s32 t;
    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = p->unk2 * 1000 + 0x400;
    func_8003C21C(&D_801CAA88, &rot);
    func_8003B05C(&m, &rot);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801CAA82[0] = t << 8;
    D_801E2AE8 = func_800D29D4(&D_801CAA82[-5], D_801517C0 + 0x70, 0xC, D_801E2AE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 15) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B1518(void) {
    MgMat m;
    MgMat w;
    MgSVec a;
    MgSVec b;
    MgSVec c;
    MgVec scale;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 k;
    s16 fl;
    s16 n;
    s32 t1;
    s32 t2;
    u16 u;
    s32 v;
    u8 *x;
    s16 *r;
    MgScratch *d;

    p = (MgTask *)&D_80162978[D_8015169C];
    fl = p->unk1A;
    k = (fl >> 1) * 2 - 1;
    b.vx = a.vx = func_80039A74(p->unk2 << 8) / 40 * k;
    b.vy = a.vy = (func_80039A74(p->unk2 << 7) >> 5) * k;
    b.vz = a.vz = 0;
    a.vx -= 0x400;
    func_8003C21C(&a, &m);
    func_8003A79C((MgMat *)D_801CAAC8, &m, &m);
    scale.vy = p->unk14;
    scale.vx = scale.vz = 0x3000;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    d = &D_801CAA94;
    x = D_801C9F8C;
    if (!(p->unk1A & 1)) {
        x = D_801CA280;
    }
    d->unk0 = x;
    r = &d->unkA;
    if (!(p->unk1A & 1)) {
        t1 = D_801CAA90;
        v = 0x1000 - t1 * 0x60;
    } else {
        t2 = D_801CAA90;
        v = 0x1000 - (t2 << 5);
    }
    *r = v;
    D_801E2AE8 = func_800D29D4(&D_801CAA94, D_801517C0 + 0x70, 0xC, D_801E2AE8);
    if (D_80062D98 == 0) {
        if (!(p->unk1A & 1)) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B11CC)];
            q->unk4 = (u16)p->unk4;
            q->unk6 = (u16)p->unk6;
            q->unk8 = (u16)p->unk8;
            c.vy = c.vx = 0;
            c.vz = (u16)p->unk18;
            func_8003C21C(&b, &m);
            func_8003A79C((MgMat *)D_801CAAC8, &m, &m);
            m.t[0] = q->unk4;
            m.t[1] = q->unk6;
            m.t[2] = q->unk8;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&c, (MgSVec *)&q->unk4, &flag);
            q->unkC = 0;
            u = p->unkE;
            q->unk10 = 0;
            q->unk1A = 0;
            q->unkE = u;
        }
        if (p->unk2 < 8) {
            D_801CAA90++;
        }
        if (p->unk2 >= 0x19) {
            D_801CAA90--;
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x20) {
            p->unk0 = -1;
        }
    }
}

void func_801B1878(void) {
    MgSVec v;
    MgSVec rot;
    MgMat m;
    s32 flag;
    MgTask *p;
    MgTask *q;
    MgSVec *qv;
    MgMat *mp;
    u16 *w;
    s16 a;
    s16 b;
    s16 c;
    s16 len;
    s32 t;
    s32 r;
    s16 i;
    s16 id;
    s16 ang;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801CAAC0.vx = a = p->unkC - p->unk4;
            D_801CAAC0.vy = b = p->unkE - p->unk6;
            D_801CAAC0.vz = c = p->unk10 - p->unk8;
            t = a * a + b * b;
            len = func_80039F5C(t + c * c, t);
            for (i = 0; i < 4; i++) {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1518)];
                q->unk4 = (u16)p->unk4;
                q->unk6 = (u16)p->unk6;
                q->unk8 = (u16)p->unk8;
                ang = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
                q->unk1A = i;
                q->unkE = ang;
                q->unk18 = len;
                q->unk14 = len * 0x1500 / 2800;
            }
        }
        if (p->unk2 == 0x23) {
            r = func_800BBEAC(func_801B13A0);
            q = (MgTask *)D_8016297C;
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &((MgObj20 *)q)[r]);
        }
        if (p->unk2 == 0x2D) {
            func_800BBA84(0x134, p->unk1C, 0x40);
        }
        if ((u16)p->unk2 - 0x2D < 0x14U) {
            i = 0;
            mp = &m;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B12E8)];
                qv = (MgSVec *)&q->unk4;
                id = p->unk1C;
                func_800D3994(id, D_8015190F[id][0], qv);
                r = func_80042DA8() % p->unk14;
                v.vz = 0;
                v.vx = 0;
                v.vy = r;
                rot.vx = func_80042DA8() % 0x1000;
                rot.vz = func_80042DA8() % 0x1000;
                rot.vy = 0;
                func_8003C21C(&rot, mp);
                m.t[0] = q->unk4;
                m.t[1] = q->unk6;
                m.t[2] = q->unk8;
                func_8003B48C(mp);
                func_8003B51C(mp);
                func_8003BADC(&v, qv, &flag);
                i++;
            } while (i < 5);
        }
        if (p->unk2 == 0x32) {
            if ((D_800F836C >> p->unk1C) & 1) {
                w = func_800D4FA8(6);
            } else if ((D_801517B4 >> p->unk1C) & 1) {
                w = func_800D4FA8(4);
                w[8] = 0;
            } else {
                w = func_800D4FA8(4);
            }
            *w = p->unk1C;
        }
        p->unk2++;
        if (p->unk2 == 0x50) {
            func_800D52A0(0, 0xA);
            p->unk0 = -1;
        }
    }
}

void func_801B1CDC(arg0, arg1) {
    MgSVec v;
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B1878)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk14 = D_801518F6[arg0][0] + 0xC8;
    p->unk1C = arg0;
    v.vx = (u16)p->unkC - (u16)p->unk4;
    v.vy = (u16)p->unkE - (u16)p->unk6;
    v.vz = (u16)p->unk10 - (u16)p->unk8;
    func_800D44E8(&v, D_801CAAC8);
    func_800BBA84(0x62, arg1, 0x40);
}

void func_801B1E14(arg0, arg1) {
    u8 pad[8];

    func_800BBEAC(func_801B1160);
    func_800D2980(D_801B1EAC, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B1CDC);
    func_800D52A0(0x1000, 0xA);
    D_800F5B70 = 0x18;
    D_800F5B71 = 0x10;
    D_800F5B72 = 0;
}
