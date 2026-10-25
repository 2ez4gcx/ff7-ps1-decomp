#include "common.h"
#include "magic_brizara/decls.h"

void func_801B0000(void) {
    MgTask *p;
    MgMat *m;
    MgVec *v;
    s32 t;
    s32 f;

    p = &D_80162978[D_8015169C];
    m = (MgMat *)0x1F800010;
    v = (MgVec *)0x1F800000;
    t = (-(p->unk2 * 0xC00) / 15) + 0xC00;
    *(s32 *)0x1F800008 = t;
    *(s32 *)0x1F800004 = t;
    *(s32 *)v = t;
    f = M2C_FIELD(p, s16 *, 2);
    if (f < 5) {
        D_801B8F82 = (f << 7) / 5;
    } else if ((f -= 5) < 0xA) {
        D_801B8F82 = 0x80;
    } else {
        p->unk0 = -1;
        return;
    }
    func_8003C21C((MgSVec *)&p->unk8, m);
    func_8003B35C(m, v);
    m->t[0] = p->unk10;
    m->t[1] = p->unk12;
    m->t[2] = p->unk14;
    func_8003A63C(&D_800FA63C, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    D_801D8F98 = func_800D29D4(&D_801B8F78, D_801517C0 + 0x70, 0xC, D_801D8F98);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk8 += 0x100;
        p->unkA += 0x80;
        p->unkC += 0x40;
    }
}

void func_801B01C8(void) {
    MgTask *p;
    MgMat *m;
    MgVec *v;
    s32 t;
    s32 t2;
    s32 f;
    s32 a;
    s32 g;

    p = &D_80162978[D_8015169C];
    m = (MgMat *)0x1F800010;
    v = (MgVec *)0x1F800000;
    f = M2C_FIELD(p, s16 *, 2);
    if (f < 5) {
        D_801B8F92 = 0x80;
        t = (f << 11) / 5;
        *(s32 *)0x1F800008 = t;
        *(s32 *)0x1F800004 = t;
        *(s32 *)v = t;
    } else {
        a = p->unk0;
        f -= 5;
        if (f < a + 5) {
            D_801B8F92 = 0x80;
            t2 = 0x800;
            *(s32 *)0x1F800008 = t2;
            *(s32 *)0x1F800004 = t2;
            *(s32 *)v = t2;
        } else {
            g = f - 5;
            f = g - a;
            if (f < 5) {
                *(s32 *)0x1F800008 = 0x800;
                *(s32 *)0x1F800004 = 0x800;
                *(s32 *)v = 0x800;
                D_801B8F92 = (-(f << 7) / 5) + 0x80;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    func_8003C21C((MgSVec *)&p->unk8, m);
    func_8003B35C(m, v);
    m->t[0] = p->unk10;
    m->t[1] = p->unk12;
    m->t[2] = p->unk14;
    func_8003A63C(&D_800FA63C, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    D_801D8F98 = func_800D29D4(&D_801B8F88, D_801517C0 + 0x70, 0xC, D_801D8F98);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B03A4(void) {
    MgObjBriz *p;
    MgObjBriz *q;

    p = (MgObjBriz *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgObjBriz *)&D_80162978[func_800BBEAC(&func_801B0000)];
            q->unk10 = p->unk10;
            q->unkC = 0;
            q->unkA = 0;
            q->unk8 = 0;
            q = (MgObjBriz *)&D_80162978[func_800BBEAC(&func_801B0000)];
            q->unk10 = p->unk10;
            q->unkA = 0x200;
            q->unk8 = 0x200;
            q->unkC = -0x200;
            q = (MgObjBriz *)&D_80162978[func_800BBEAC(&func_801B0000)];
            q->unk10 = p->unk10;
            q->unkA = -0x200;
            q->unk8 = -0x200;
            q->unkC = 0x200;
        }
        if (p->unk2 == 0xF) {
            q = (MgObjBriz *)&D_80162978[func_800BBEAC(&func_801B01C8)];
            q->unk0 = 4;
            q->unk10 = p->unk10;
            q->unkC = 0;
            q->unkA = 0;
            q->unk8 = 0;
        }
        if (p->unk2 == 0x11) {
            q = (MgObjBriz *)&D_80162978[func_800BBEAC(&func_801B01C8)];
            q->unk0 = 2;
            q->unk10 = p->unk10;
            q->unkA = 0x200;
            q->unk8 = 0x200;
            q->unkC = -0x200;
        }
        if (p->unk2 == 0x13) {
            q = (MgObjBriz *)&D_80162978[func_800BBEAC(&func_801B01C8)];
            q->unk0 = 0;
            q->unk10 = p->unk10;
            q->unkA = -0x200;
            q->unk8 = -0x200;
            q->unkC = 0x200;
        }
        if (p->unk2 == 0x19) {
            func_800D5774(p->unk4);
            if (p->unk2 == 0x19) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0634(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B03A4)];
    p->unk4 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk10);
}

void func_801B06B4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D8F98 = D_801B8F98 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0714(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B07A4, 0, 0, 0);
    func_800BBEAC(&func_801B06B4);
    func_800D5444(arg0, arg1, 0, &func_801B0634);
    func_800D55F4(0x20, func_800D574C(D_80151774), 0x1D);
}
