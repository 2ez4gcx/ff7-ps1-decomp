#include "common.h"
#include "magic_altema/decls.h"

void func_801B0054(void) {
    func_801B0EC4();
}

void func_801B0074(void) {
    MgTask *p;
    MgMat *q;
    s16 a;
    s32 t;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk16 != 0) {
        t = (0xF - p->unk2) >> 2;
    } else {
        a = p->unk2;
        t = a >> 2;
    }
    D_801C1DF0[0] = t << 5;
    v = p->unk12;
    q = &D_801C1DFC;
    q->m[0][0] = D_801C1E04[0] = v;
    D_801C1E10[0] = p->unk4;
    D_801C1E10[1] = p->unk6;
    D_801C1E10[2] = p->unk8;
    func_8003B48C(q);
    func_8003B51C(q);
    D_801D9EB0 = func_800D6260(&D_801C1DEC, D_801517C0 + 0x70, 0xC, D_801D9EB0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0xF) {
            p->unk0 = -1;
        }
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
    }
}

void func_801B01E0(void) {
    MgSVec rot;
    MgMat m;
    MgVec sc;
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 c;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0x400;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk10;
    m.t[1] = -0x1E;
    m.t[2] = p->unkE;
    sc.vx = sc.vy = sc.vz = p->unkC;
    func_8003B35C(&m, &sc);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = &D_801C1074;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c = 0x80;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t >= 0x1C) {
        ((MgScratch *)0x1F800000)->unkA = c - (t - 0x1C) * 10;
    }
    D_801D9EB0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D9EB0);
    if (p->unk2 >= 0x28) {
        p->unk0 = -1;
    }
    if (p->unk10 >= p->unk14) {
        p->unk0 = -1;
    }
    if (p->unk16 != 0 && p->unk0 != -1 && p->unk10 >= 0) {
        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B01E0)];
        q->unk2 = p->unk2;
        q->unkC = p->unkC;
        q->unkE = p->unkE;
        q->unk10 = p->unk10 - p->unk14;
        q->unk12 = p->unk12;
        q->unk14 = p->unk14;
        q->unk16 = 1;
        p->unk16 = 0;
    }
    if (D_80062D98 == 0) {
        p->unk10 += p->unk12;
        p->unk2++;
    }
}

void func_801B0420(void) {
    MgSVec rot;
    MgMat m;
    MgVec sc;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[1] = -0x1E;
    m.t[0] = 0;
    m.t[2] = 0x200;
    sc.vx = sc.vy = sc.vz = p->unkC;
    func_8003B35C(&m, &sc);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = &D_801C1810;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801D9EB0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D9EB0);
    if (p->unk2 >= 0x20) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x14) {
            p->unkC += p->unkE;
        }
        p->unk2++;
    }
}

AtPoly *func_801B0580(AtGrad *arg0) {
    AtPoly *pk;
    s32 a;
    s32 b;
    s32 i;
    s32 n;
    s32 c;
    s32 step;

    a = 0;
    b = 0x13F;
    i = 0;
    pk = arg0->buf;
    n = arg0->n;
    c = arg0->color;
    step = arg0->step << 16;
    for (i = 0; i < n; i++) {
        pk->xy2 = a;
        a += step;
        pk->xy3 = b;
        b += step;
        pk->xy0 = a;
        pk->xy1 = b;
        pk->c3 = c;
        pk->c2 = c;
        pk->c1 = c;
        pk->c0 = c;
        pk->tag.len = 8;
        *((u8 *)&pk->c0 + 3) = 0x3A;
        pk->tag.addr = arg0->ot->head.addr;
        arg0->ot->head.addr = (u32)pk;
        pk++;
    }
    return pk;
}

AtPoly *func_801B0650(AtGrad *arg0, s16 arg1) {
    AtPoly *pk;
    s32 a;
    s32 b;
    s32 c;
    s32 i;
    s32 n;
    s32 inc;
    s32 step;

    a = 0x5A0000;
    b = 0x5A013F;
    c = 0;
    i = 0;
    pk = arg0->buf;
    inc = arg0->color;
    step = arg0->step << 16;
    n = arg0->n;
    for (i = 0; i < n; i++) {
        if (i < arg1) {
            a -= step;
            b -= step;
        } else {
            pk->xy2 = a;
            a -= step;
            pk->xy3 = b;
            b -= step;
            pk->c3 = c;
            pk->c2 = c;
            c += inc;
            pk->xy0 = a;
            pk->xy1 = b;
            if (c > 0xFFFFFF) {
                c = 0xFFFFFF;
            }
            pk->tag.len = 8;
            pk->c1 = c;
            pk->c0 = c;
            *((u8 *)&pk->c0 + 3) = 0x3A;
            pk->tag.addr = arg0->ot->head.addr;
            arg0->ot->head.addr = (u32)pk;
            pk++;
        }
    }
    a = 0x5A0000;
    b = 0x5A013F;
    c = 0;
    inc = arg0->color;
    for (i = 0; i < n; i++) {
        if (i < arg1) {
            a += step;
            b += step;
        } else {
            pk->xy0 = a;
            a += step;
            pk->xy1 = b;
            b += step;
            pk->c1 = c;
            pk->c0 = c;
            c += inc;
            pk->xy2 = a;
            pk->xy3 = b;
            if (c > 0xFFFFFF) {
                c = 0xFFFFFF;
            }
            pk->tag.len = 8;
            pk->c3 = c;
            pk->c2 = c;
            *((u8 *)&pk->c0 + 3) = 0x3A;
            pk->tag.addr = arg0->ot->head.addr;
            arg0->ot->head.addr = (u32)pk;
            pk++;
        }
    }
    return pk;
}

void func_801B0850(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 i;
    s32 a;
    s32 b;
    u16 u;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 < 0x20) {
        ((AtGrad *)0x1F800000)->step = 6;
        ((AtGrad *)0x1F800000)->n = 0x1E;
        ((AtGrad *)0x1F800000)->ot = (AtOt *)(D_801517C0 + 0x70);
        ((AtGrad *)0x1F800000)->buf = (AtPoly *)D_801D9EB0;
        ((AtGrad *)0x1F800000)->color = *(s32 *)&p->unk4;
        D_801D9EB0 = (s32)((AtPoly *(*)(AtGrad *, s32))func_801B0580)((AtGrad *)0x1F800000, p->unk2);
    } else {
        ((AtGrad *)0x1F800000)->step = 3;
        ((AtGrad *)0x1F800000)->n = 0x1E;
        ((AtGrad *)0x1F800000)->ot = (AtOt *)(D_801517C0 + 0x70);
        ((AtGrad *)0x1F800000)->buf = (AtPoly *)D_801D9EB0;
        ((AtGrad *)0x1F800000)->color = *(s32 *)&p->unk8;
        D_801D9EB0 = (s32)((AtPoly *(*)(AtGrad *, s32))func_801B0650)((AtGrad *)0x1F800000, p->unk2 - 0x20);
    }
    t = p->unk2;
    if (t == 0x20) {
        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B01E0)];
        q->unkC = 0xB6;
        q->unkE = 0x200;
        q->unk12 = 0xA;
        q->unk10 = 0;
        q->unk14 = 0x107;
        q->unk16 = 1;
        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B01E0)];
        q->unkC = 0xDA;
        q->unkE = 0x228;
        q->unk12 = 4;
        q->unk14 = 0x13B;
        q->unk10 = 0;
        q->unk16 = 1;
        D_800F5B70[0] = D_800F5B70[1] = D_800F5B70[2] = 0;
        D_801C1E1C = 0x1000;
        D_800F8380 |= 7;
        t = *(s16 *)((u8 *)p + 2);
    }
    if (t >= 0x4A) {
        if (t == 0x4B) {
            D_800F8380 &= 0xF8;
        }
        u = 0x1000 - (p->unk2 - 0x4A) * 0x199;
        D_801C1E1C = u;
        if ((s16)u < 0) {
            D_801C1E1C = 0;
        }
    }
    if (p->unk2 >= 0x54) {
        D_801C1E1C = 0;
        p->unk0 = -1;
    }
    D_800F5B74 = D_801C1E1C;
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x4E) {
            i = 0;
            do {
                if ((1 << i) & D_801D9EB8) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
        }
        if (p->unk2 < 0x20) {
            a = *(s32 *)&p->unk4 + 0x80808;
            *(s32 *)&p->unk4 = a;
            if (a > 0xFFFFFF) {
                *(s32 *)&p->unk4 = 0xFFFFFF;
            }
        } else {
            b = *(s32 *)&p->unk8 + 0xFFFDFDFE;
            *(s32 *)&p->unk8 = b;
            if (b <= 0x10100) {
                *(s32 *)&p->unk8 = 0x10101;
            }
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_altema/nonmatchings/text", func_801B0BBC);

void func_801B0E7C(void) {
    D_80162978[D_8015169C].unk0 = -1;
    func_800BBEAC(&func_801B0BBC);
}

INCLUDE_RODATA("../asm/us/magic_altema/nonmatchings/text", D_801B0000);

void func_801B0EC4(arg0) {
    D_801D9EB4 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B0F54, 0, 0, 0);
    func_800BBEAC((M2C_UNK *)func_801B0E7C);
    D_801D9EB8 = arg0;
    func_800D55F4(0x21, 0x40, 0x136, 0x137);
}
