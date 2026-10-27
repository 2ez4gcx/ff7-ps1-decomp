#include "common.h"
#include "magic_jaki/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0B40();
    return &D_801B1828;
}

void func_801B0028(void) {
    s32 i;

    for (i = 0; i < 0x96; i++) {
        D_801D47B8[i] = 0;
    }
}

JakiSlot *func_801B004C(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x96; i++) {
        if (D_801D47B8[i] == 0) {
            D_801D47B8[i] = arg0;
            D_801D3750[i].unk0 = 0;
            D_801D3750[i].unk2 = 0;
            return &D_801D3750[i];
        }
    }
    return 0;
}

void func_801B00C4(void) {
    MgTask *p;
    s32 i;
    s32 n;

    n = 0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 0x96; i++) {
        if (D_801D47B8[i] != 0) {
            D_801D47B8[i](&D_801D3750[i]);
            if (D_801D3750[i].unk0 == -1) {
                D_801D47B8[i] = 0;
            } else {
                n++;
            }
        }
    }
    if (n == 0 && D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B01BC(MgTask *p) {
    s32 t;
    s32 c;

    t = p->unk2;
    if (t < 2) {
        c = t << 6;
        D_801B2428 = D_801B2429 = D_801B242A = c;
    } else {
        t -= 2;
        if (t < 3) {
            c = -(t << 7) / 2 - 0x80;
            D_801B2428 = D_801B2429 = D_801B242A = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_800D4368(&p->unk4, p->unk18, 0);
    D_801B242C[0] = p->unk0;
    D_801D3740 = func_800D4D90(&D_801B242C[-4], D_801517C0 + 0x70, 0xC, D_801D3740);
    p->unk2++;
    p->unk4 += p->unkC;
    p->unk6 += p->unkE;
    p->unk8 += p->unk10;
}

void func_801B02C4(JakiFx *p) {
    MgMat *m;
    MgVec *v;
    s32 t;
    s32 c;

    m = (MgMat *)0x1F800000;
    v = (MgVec *)0x1F800020;
    t = p->unk2;
    if (t < 2) {
        c = t << 6;
        D_801B2434 = D_801B2435 = D_801B2436 = c;
    } else {
        t -= 2;
        if (t < 3) {
            c = -(t << 7) / 3 - 0x80;
            D_801B2434 = D_801B2435 = D_801B2436 = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    p->unk14->t[0] = p->unk4;
    p->unk14->t[1] = p->unk6;
    p->unk14->t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, p->unk14, m);
    func_800D461C(m);
    v->vx = v->vy = v->vz = p->unk18;
    func_8003B35C(m, v);
    func_8003B48C(m);
    func_8003B51C(m);
    D_801D3740 = func_800D4D90(D_801B2430, D_801517C0 + 0x70, 0xC, D_801D3740);
    p->unk2++;
    p->unk4 += p->unkC;
    p->unk6 += p->unkE;
    p->unk8 += p->unk10;
}

void func_801B0454(void) {
    MgSVec *v;
    MgMat *m;
    MgTask *p;
    JakiFx *q;
    s32 i;
    s32 r;

    m = (MgMat *)0x1F800008;
    p = &D_80162978[D_8015169C];
    v = (MgSVec *)0x1F800000;
    for (i = 0; i < D_801D3744; i++) {
        q = (JakiFx *)func_801B004C((s32)func_801B01BC);
        v->vx = 0;
        v->vy = func_80042DA8() & 0xFFF;
        v->vz = -(func_80042DA8() & 0x7FF);
        func_8003C21C(v, m);
        v->vx = func_80042DA8() % 500 + 500;
        v->vy = 0;
        v->vz = 0;
        func_8003B2CC(m, v, v);
        q->unk4 = p->unk4 + v->vx * 5;
        q->unk6 = p->unk6 + v->vy * 5;
        q->unk8 = p->unk8 + v->vz * 5;
        q->unkC = -v->vx;
        q->unkE = -v->vy;
        q->unk10 = -v->vz;
        q->unk18 = func_80042DA8() % 0x1000 + 0x1000;
        q->unk0 = func_80042DA8() % 3;
    }
    for (i = 0; i < D_801D3748; i++) {
        q = (JakiFx *)func_801B004C((s32)func_801B02C4);
        v->vx = 0;
        v->vy = func_80042DA8() & 0xFFF;
        v->vz = -(func_80042DA8() & 0x7FF);
        func_8003C21C(v, m);
        v->vx = func_80042DA8() % 500 + 500;
        v->vy = 0;
        v->vz = 0;
        func_8003B2CC(m, v, v);
        q->unk4 = p->unk4 + v->vx * 5;
        q->unk6 = p->unk6 + v->vy * 5;
        q->unk8 = p->unk8 + v->vz * 5;
        q->unkC = -v->vx;
        q->unkE = -v->vy;
        q->unk10 = -v->vz;
        q->unk18 = func_80042DA8() % 0x1000 + 0x1000;
        r = func_80042DA8();
        q->unk0 = r % 3;
        func_800D44E8(v, m, r / 3);
        func_8003A79C(m, &D_801B243C, &D_801B2480[D_801B0C2C]);
        q->unk14 = &D_801B2480[D_801B0C2C];
        D_801B0C2C = (D_801B0C2C + 1) % 150;
    }
    p->unk2++;
    if (p->unk2 >= 0xF) {
        p->unk0 = -1;
    }
}

void func_801B08A8(void) {
    MgTask *p;
    MgTask *q;

    p = &D_80162978[D_8015169C];
    if (p->unk2 == 0) {
        q = &D_80162978[func_800BBEAC(func_801B0454)];
        *(JakiB8 *)&q->unk4 = *(JakiB8 *)&p->unk4;
    }
    if (p->unk2 == 0xF) {
        func_800D5774(p->unk0);
    }
    if (p->unk2 == 0x23) {
        p->unk0 = -1;
    }
    p->unk2++;
}

void func_801B0970(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B08A8)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

void func_801B09F0(void) {
    MgTask *p;
    s32 a;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_800D55F4(0x20, func_800D574C(D_801D374C), 0x241);
        }
        t = p->unk2;
        if (t == 0x19) {
            goto blockA;
        }
        if (t == 0x1A) {
            a = 5;
            goto call;
        }
        if (t == 0x1E) {
        blockA:
            func_800D5138(1);
            func_800D55F4(0x20, 0x40, 0x189);
        } else {
            a = 0xA;
            if (t == 0x1F) {
            call:
                func_800D51D4(a);
            }
        }
        if (p->unk2 == 0x23) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0AE0(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801D3740 = D_801B3740 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 3) {
        p->unk0 = -1;
    }
}

s32 func_801B0B40(arg0, arg1) {
    func_800D2980(D_801B0C30, 0, 0, 0);
    D_801D374C = arg0;
    D_801D3744 = D_801D3748 = 0xE / func_800D54BC(arg0);
    func_801B0028();
    func_800BBEAC(func_801B0AE0);
    func_800D5444(arg0, arg1, 0, func_801B0970);
    func_800BBEAC(func_801B00C4);
    return func_800BBEAC(func_801B09F0);
}
