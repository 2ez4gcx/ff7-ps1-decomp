#include "common.h"
#include "magic_hatena/decls.h"

void func_801B0054(void) {
    func_801B105C();
}

HaPolyEnt *func_801B0074(HaPolyCtx *arg0, u8 *arg1, u16 *arg2) {
    HaPolyEnt *e;
    HaPolyFT3 *p;
    s32 i;
    s32 sh;
    s32 n;
    s32 cnt;
    s32 col;

    col = 0x26808080;
    e = (HaPolyEnt *)(arg2 + 2);
    i = 0;
    cnt = arg0->cnt;
    p = arg0->prim;
    sh = 14 - arg0->shift;
    n = arg2[0];
    if ((u32)i < (u32)n) {
        do {
            *(HaB8 *)&arg0->v28 = *(HaB8 *)(arg1 + e->idx[0]);
            *(HaB8 *)&arg0->v30 = *(HaB8 *)(arg1 + e->idx[1]);
            *(HaB8 *)&arg0->v38 = *(HaB8 *)(arg1 + e->idx[2]);
            gte_ldv3(&arg0->v28, &arg0->v30, &arg0->v38);
            gte_rtpt();
            p->tag.len = 7;
            p->rgbc = col;
            p->uvtp1 = e->uv1 | arg0->w10;
            p->uvclut0 = e->w8;
            gte_nclip();
            p->uv2 = e->uv2;
            gte_stopz(&arg0->area);
            i++;
            if (arg0->area > 0) {
                gte_stsxy3(&p->xy0, &p->xy1, &p->xy2);
                gte_avsz3();
                gte_stotz(&arg0->otz);
                p->tag.addr = (arg0->ot + (arg0->otz >> sh))->addr;
                (arg0->ot + (arg0->otz >> sh))->addr = (u32)p;
                p++;
            }
            cnt++;
            e++;
        } while (i < n);
    }
    arg0->cnt = cnt;
    arg0->prim = p;
    return e;
}

HaQuadEnt *func_801B02AC(HaQuadCtx *arg0, u8 *arg1, u16 *arg2) {
    HaQuadEnt *e;
    HaPolyFT4 *p;
    s32 i;
    s32 sh;
    s32 n;
    s32 cnt;
    s32 col;

    col = 0x2E808080;
    e = (HaQuadEnt *)(arg2 + 2);
    i = 0;
    cnt = arg0->cnt;
    p = arg0->prim;
    sh = 14 - arg0->shift;
    n = arg2[0];
    if ((u32)i < (u32)n) {
        do {
            *(HaB8 *)&arg0->v28 = *(HaB8 *)(arg1 + e->idx[0]);
            *(HaB8 *)&arg0->v30 = *(HaB8 *)(arg1 + e->idx[1]);
            *(HaB8 *)&arg0->v38 = *(HaB8 *)(arg1 + e->idx[2]);
            *(HaB8 *)&arg0->v40 = *(HaB8 *)(arg1 + e->idx[3]);
            gte_ldv3(&arg0->v28, &arg0->v30, &arg0->v38);
            gte_rtpt();
            p->tag.len = 9;
            p->rgbc = col;
            p->uvtp1 = e->uv1 | arg0->w10;
            p->uvclut0 = e->w8;
            gte_nclip();
            p->uv2 = e->uv2;
            p->uv3 = e->uv3;
            gte_stopz(&arg0->area);
            i++;
            if (arg0->area > 0) {
                gte_stsxy3(&p->xy0, &p->xy1, &p->xy2);
                gte_ldv0c(&arg0->v40);
                gte_rtps();
                gte_stsxy(&p->xy3);
                gte_avsz4();
                gte_stotz(&arg0->otz);
                p->tag.addr = (arg0->ot + (arg0->otz >> sh))->addr;
                (arg0->ot + (arg0->otz >> sh))->addr = (u32)p;
                p++;
            }
            cnt++;
            e++;
        } while (i < n);
    }
    arg0->cnt = cnt;
    arg0->prim = p;
    return e;
}

HaG3Ent *func_801B0544(HaG3Ctx *arg0, u8 *arg1, s32 *arg2) {
    HaG3Ent *e;
    HaPolyG3 *p;
    s32 i;
    s32 sh;
    s32 n;
    s32 cnt;

    e = (HaG3Ent *)(arg2 + 1);
    i = 0;
    cnt = arg0->cnt;
    p = arg0->prim;
    sh = 14 - arg0->shift;
    n = arg2[0];
    if (i < n) {
        do {
            *(HaB8 *)&arg0->v28 = *(HaB8 *)(arg1 + e->idx[0]);
            *(HaB8 *)&arg0->v30 = *(HaB8 *)(arg1 + e->idx[1]);
            *(HaB8 *)&arg0->v38 = *(HaB8 *)(arg1 + e->idx[2]);
            gte_ldv3(&arg0->v28, &arg0->v30, &arg0->v38);
            gte_rtpt();
            *(s32 *)&p->r0 = e->c0;
            p->c1 = e->c1;
            p->c2 = e->c2;
            p->tag.len = 6;
            p->code = 0x30;
            gte_nclip();
            gte_stopz(&arg0->area);
            i++;
            if (arg0->area > 0) {
                gte_stsxy3(&p->xy0, &p->xy1, &p->xy2);
                gte_avsz3();
                gte_stotz(&arg0->otz);
                p->tag.addr = (arg0->ot + (arg0->otz >> sh))->addr;
                (arg0->ot + (arg0->otz >> sh))->addr = (u32)p;
                p++;
            }
            cnt++;
            e++;
        } while (i < n);
    }
    arg0->cnt = cnt;
    arg0->prim = p;
    return e;
}

HaG4Ent *func_801B0764(HaG4Ctx *arg0, u8 *arg1, u16 *arg2) {
    HaG4Ent *e;
    HaPolyG4 *p;
    s32 i;
    s32 sh;
    s32 n;
    s32 cnt;

    e = (HaG4Ent *)(arg2 + 2);
    i = 0;
    cnt = arg0->cnt;
    p = arg0->prim;
    sh = 14 - arg0->shift;
    n = arg2[0];
    if ((u32)i < (u32)n) {
        do {
            *(HaB8 *)&arg0->v28 = *(HaB8 *)(arg1 + e->idx[0]);
            *(HaB8 *)&arg0->v30 = *(HaB8 *)(arg1 + e->idx[1]);
            *(HaB8 *)&arg0->v38 = *(HaB8 *)(arg1 + e->idx[2]);
            *(HaB8 *)&arg0->v40 = *(HaB8 *)(arg1 + e->idx[3]);
            gte_ldv3(&arg0->v28, &arg0->v30, &arg0->v38);
            gte_rtpt();
            *(s32 *)&p->r0 = e->c0;
            p->c1 = e->c1;
            p->c2 = e->c2;
            p->c3 = e->c3;
            p->tag.len = 8;
            p->code = 0x38;
            gte_nclip();
            gte_stopz(&arg0->area);
            i++;
            if (arg0->area > 0) {
                gte_stsxy3(&p->xy0, &p->xy1, &p->xy2);
                gte_ldv0c(&arg0->v40);
                gte_rtps();
                gte_stsxy(&p->xy3);
                gte_avsz4();
                gte_stotz(&arg0->otz);
                p->tag.addr = (arg0->ot + (arg0->otz >> sh))->addr;
                (arg0->ot + (arg0->otz >> sh))->addr = (u32)p;
                p++;
            }
            cnt++;
            e++;
        } while (i < n);
    }
    arg0->cnt = cnt;
    arg0->prim = p;
    return e;
}

INCLUDE_ASM("../asm/us/magic_hatena/nonmatchings/text", func_801B09E4);

void func_801B0A90(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;

    rot.vy = 0xABE;
    rot.vx = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6 + p->unk10;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unkC;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_1F800000[0] = (s32)&D_801BA544;
    D_1F800000[2] = 0xC;
    D_1F800000[1] = D_801517C0 + 0x70;
    D_1F800000[3] = D_801D3204;
    D_801D3204 = func_801B09E4(0x1F800000);
    if (p->unk2 >= 0x18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x12) {
            func_800D5774(D_801D320C);
        }
        if (p->unk2 < 6) {
            p->unk10 += p->unk12;
        }
        if (p->unk2 == 6) {
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0xA6);
        }
        p->unk2++;
    }
}

void func_801B0C50(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    frame = &D_801BB200;
    *frame = p->unk2;
    func_800D4368(&p->unk4, p->unkC, 0);
    D_801D3204 = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801D3204);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unk10;
        p->unk8 += p->unk12;
        p->unk2++;
    }
}

void func_801B0D2C(void) {
    MgVec v;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 d;
    s32 w;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((u16)(p->unk2 - 6) < 4U) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(&func_801B0C50)];
                v.vx = func_80042DA8() % 1800 - 0x384;
                v.vy = 0;
                v.vz = func_80042DA8() % 1800 - 0x384;
                func_8003A08C(&v, &v);
                d = func_80042DA8() % 400 + 0x258;
                q->unk4 = p->unk4 + (d * v.vx >> 12);
                q->unk6 = 0;
                q->unk8 = p->unk8 + (d * v.vz >> 12);
                q->unkC = p->unkC;
                w = func_80042DA8() % 32 + 0x64;
                q->unk10 = w * v.vx >> 12;
                i++;
                q->unk12 = w * v.vz >> 12;
            } while (i < 20);
        }
        if (p->unk2 >= 0x18) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0F60(void) {
    MgTask *p;
    MgTask *q;
    MgTask *b;

    D_80162978[D_8015169C].unk0 = -1;
    b = D_80162978;
    p = &b[func_800BBEAC(&func_801B0A90)];
    func_800D3994(D_801D320C, D_8015190F[D_801D320C][0], &p->unk4);
    p->unkC = 0xDB6;
    p->unk10 = -0xDAC;
    p->unk6 = 0;
    p->unk12 = 0x247;
    q = &b[func_800BBEAC(&func_801B0D2C)];
    *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
    q->unkC = 0x1B6D;
}

INCLUDE_RODATA("../asm/us/magic_hatena/nonmatchings/text", D_801B0000);

s32 func_801B105C(arg0) {
    s32 i;
    s32 n;

    D_801D3208 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B1128, 0, 0, 0);
    i = 0;
    n = 0;
    for (; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801D320C = i;
            }
        }
    }
    func_800BBEAC(&func_801B0F60);
    return func_800D55F4(0x20, func_800D574C(arg0), 0x85);
}
