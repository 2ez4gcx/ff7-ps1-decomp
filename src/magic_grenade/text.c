#include "common.h"
#include "magic_grenade/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0F60();
    return &D_801B0FDC;
}

void func_801B0028(void) {
    MgTask *p;
    MgMat *s;
    MgVec *sc;
    s32 k;
    s16 v;
    s32 d;

    s = (MgMat *)0x1F800000;
    sc = (MgVec *)0x1F800020;
    p = (MgTask *)&D_80162978[D_8015169C];
    k = p->unk2;
    if (k < 0xA) {
        D_801D4DFA = D_801D4E0A = D_801D4E1A = 0;
    } else {
        k -= 0xA;
        if (k < 0xA) {
            v = (k << 12) / 10;
            D_801D4DFA = D_801D4E0A = D_801D4E1A = v;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003BF8C(&p->unkC, s);
    s->t[0] = p->unk4;
    s->t[1] = p->unk6;
    s->t[2] = p->unk8;
    d = (p->unk2 << 9) / 20;
    sc->vx = sc->vy = sc->vz = d;
    D_801E4EBC = d;
    func_8003B35C(s, sc);
    func_8003A63C(&D_800FA63C, s, s);
    func_8003B48C(s);
    func_8003B51C(s);
    func_8003B69C(0, 0, 0);
    D_801E4EB8 = func_800D29D4(&D_801D4DF0, D_801517C0 + 0x70, 0xC, D_801E4EB8);
    D_801E4EB8 = func_800D29D4(&D_801D4E00, D_801517C0 + 0x70, 0xC, D_801E4EB8);
    func_8003B35C(s, &D_801D4E20);
    func_8003B48C(s);
    D_801E4EB8 = func_800D29D4(&D_801D4E10, D_801517C0 + 0x70, 0xC, D_801E4EB8);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unkE -= 0x40;
    }
}

void func_801B0264(void) {
    MgTask *p;
    MgMat *s;
    s32 k;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    s = (MgMat *)0x1F800000;
    k = p->unk2;
    if (k < 0xA) {
        D_801D4E3A = 0x800;
    } else {
        k -= 0xA;
        if (k < 0xA) {
            D_801D4E3A = (k << 0xB) / 10 + 0x800;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    v = (p->unk2 << 0xA) / 20;
    D_801D4E40.m[0][0] = D_801D4E40.m[1][1] = D_801D4E40.m[2][2] = v;
    D_801D4E40.t[0] = p->unk4;
    D_801D4E40.t[1] = p->unk6;
    D_801D4E40.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801D4E40, s);
    func_8003B48C(s);
    func_8003B51C(s);
    D_801E4EB8 = func_800D29D4(&D_801D4E30, D_801517C0 + 0x70, 0xC, D_801E4EB8);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B03EC(void) {
    GrBolt *p;
    MgMat *m;
    MgVec *sc;
    MgSVec *r;
    u16 *frame;
    s32 k;
    u8 c;

    m = (MgMat *)0x1F800008;
    sc = (MgVec *)0x1F800028;
    p = (GrBolt *)&D_80162978[D_8015169C];
    r = (MgSVec *)0x1F800000;
    k = p->unk2;
    if (k < 0xA) {
        *(s32 *)&D_801D4E64 = 0x2C808080;
    } else {
        k -= 0xA;
        if (k < 5) {
            D_801D4E67 = 0x2E;
            c = -(k << 7) / 5 - 0x80;
            D_801D4E66 = c;
            D_801D4E65 = c;
            D_801D4E64 = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    r->vx = p->unk14[0] * 0x10;
    r->vy = p->unk14[1] * 0x10;
    r->vz = p->unk14[2] * 0x10;
    func_8003C21C(r, m);
    m->t[0] = p->unk4;
    m->t[1] = p->unk6;
    m->t[2] = p->unk8;
    sc->vx = sc->vy = sc->vz = p->unk1C;
    func_8003B35C(m, sc);
    func_8003A63C(&D_800FA63C, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    frame = &D_801D4E68;
    *frame = p->unk0;
    D_801E4EB8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E4EB8);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC = p->unkC * 15 >> 4;
        p->unkE = (p->unkE * 15 >> 4) + 0x32;
        p->unk10 = p->unk10 * 15 >> 4;
        p->unk14[0] += p->unk18[0];
        p->unk14[1] += p->unk18[1];
        p->unk14[2] += p->unk18[2];
    }
}

void func_801B0664(void) {
    GrBolt *p;
    GrBolt *q;
    MgSVec *s;
    MgMat *m;
    s32 i;
    s16 n;

    p = (GrBolt *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        s = (MgSVec *)0x1F800000;
        m = (MgMat *)0x1F800008;
        i = 0;
        do {
            q = (GrBolt *)&D_80162978[func_800BBEAC(func_801B03EC)];
            *(GrB8 *)&q->unk4 = *(GrB8 *)&p->unk4;
            s->vx = 0;
            s->vy = func_80042DA8() & 0xFFF;
            s->vz = func_80042DA8() % 0x600 - 0x300;
            func_8003C21C(s, m);
            s->vx = 0;
            s->vy = -(func_80042DA8() % 500 + 500);
            s->vz = 0;
            func_8003B2CC(m, s, (MgSVec *)&q->unkC);
            q->unk14[0] = q->unk14[1] = q->unk14[2] = 0;
            q->unk18[0] = func_80042DA8() - 0x80;
            q->unk18[1] = func_80042DA8() - 0x80;
            q->unk18[2] = func_80042DA8() - 0x80;
            q->unk1C = func_80042DA8() % 0x1000 + 0x1000;
            i++;
            q->unk0 = func_80042DA8() % 3;
        } while (i < 7);
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n >= 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B0880(void) {
    MgTask *p;
    MgSVec *s;
    u16 *frame;
    s16 n;

    s = (MgSVec *)0x1F800000;
    p = (MgTask *)&D_80162978[D_8015169C];
    s->vx = (u16)p->unk4 + (p->unkC * D_801E4EBC >> 12);
    s->vy = p->unk6;
    s->vz = (u16)p->unk8 + (p->unk10 * D_801E4EBC >> 12);
    func_800D4368(s, p->unk1C, 0);
    frame = &D_801D4E74;
    *frame = p->unk2;
    D_801E4EB8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E4EB8);
    if (D_80062D98 == 0) {
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n >= D_801D42B4.v) {
            p->unk0 = -1;
        }
    }
}

void func_801B09A0(void) {
    MgTask *p;
    MgTask *q;
    s32 r;
    s32 i;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0880)];
            *(GrB8 *)&q->unk4 = *(GrB8 *)&p->unk4;
            r = func_80042DA8() & 0xFFF;
            q->unkC = (u32)func_80039A74(r) * 0x465 >> 8;
            q->unkE = 0;
            q->unk10 = (u32)func_80039B40(r) * 0x465 >> 8;
            q->unk1C = func_80042DA8() % 0x800 + 0x1000;
            i++;
        } while (i < 4);
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B0AFC(void) {
    MgTask *p;
    MgMat *s;
    s16 *frame;
    s16 v;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    s = (MgMat *)0x1F800000;
    frame = &D_801D4E82;
    *frame = (p->unk2 << 12) / 10;
    v = (p->unk2 << 13) / 10;
    D_801D4E88.m[0][0] = D_801D4E88.m[1][1] = D_801D4E88.m[2][2] = v;
    D_801D4E88.t[0] = p->unk4;
    D_801D4E88.t[1] = p->unk6;
    D_801D4E88.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801D4E88, s);
    func_8003B48C(s);
    func_8003B51C(s);
    func_8003B69C(0, 0, 0);
    D_801E4EB8 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801E4EB8);
    if (D_80062D98 == 0) {
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B0C64(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x28) {
            func_800D5138(1);
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0xFA);
        }
        if (p->unk2 == 0x29) {
            func_800D51D4(3);
        }
        if (p->unk2 == 0x28) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0AFC)];
            *(GrB8 *)&q->unk4 = *(GrB8 *)&p->unk4;
        }
        if (p->unk2 == 0x2B) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0028)];
            *(GrB8 *)&q->unk4 = *(GrB8 *)&p->unk4;
            q->unkC = 0;
            q->unkE = 0;
            q->unk10 = 0;
        }
        if (p->unk2 == 0x2B) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0264)];
            *(GrB8 *)&q->unk4 = *(GrB8 *)&p->unk4;
        }
        if (p->unk2 == 0x2B) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0664)];
            *(GrB8 *)&q->unk4 = *(GrB8 *)&p->unk4;
        }
        if (p->unk2 == 0x2B) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B09A0)];
            *(GrB8 *)&q->unk4 = *(GrB8 *)&p->unk4;
        }
        if (p->unk2 == 0x41) {
            i = 0;
            do {
                if (D_801D4EA8 >> i & 1) {
                    func_800D5774(i);
                    n = i * 0x74;
                    D_80151233[n] = 3;
                }
                i++;
            } while (i < 10);
            if (p->unk2 == 0x41) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0F00(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E4EB8 = D_801D4EB8 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B0F60(arg0) {
    s32 t;

    func_800D2980(&D_801B1E44, 0, 0, 0);
    func_800BBEAC(func_801B0F00);
    t = func_800BBEAC(func_801B0C64) << 5;
    D_801D4EA8 = arg0;
    return func_800D54EC(arg0, (u8 *)&D_8016297C + t);
}
