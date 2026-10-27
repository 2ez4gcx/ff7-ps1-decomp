#include "common.h"
#include "magic_dive/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0BD4();
    return &D_801BAA50;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CCFD8 = D_801BCFD8 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0088(void) {
    MgObj20 *p;
    s16 n;

    p = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(D_801BCFA0, 0, D_801BCFA2);
    if (D_80062D98 == 0) {
        if (p->unk2 < 5) {
            D_801BCFA0 += 0x18;
            D_801BCFA2 += 0x18;
        }
        if ((u32)((u16)p->unk2 - 5) < 5) {
            D_801BCFA0 -= 0x18;
        }
        if (p->unk2 >= 0xA) {
            D_801BCFA2 -= 0x18;
        }
        n = ++p->unk2;
        if (n == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B01AC(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x4000, 0);
    frame = &D_801BCFAC;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk6 += p->unkE;
        n = ++p->unk2;
        if (n == D_801BA98C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0274(void) {
    MgMat m;
    MgMat lw;
    MgVec v;
    MgTask *p;
    MgTask *q;
    MgSVec *a;
    MgSVec *b;
    MgSVec *c;
    MgSVec *base_a;
    MgSVec *base_b;
    MgSVec *base_c;
    s16 i;
    s16 ang;
    s32 r;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801BCFB0, &m);
    v.vx = p->unkC;
    v.vy = p->unkE;
    v.vz = p->unk10;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = 0;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801CCFD8 = func_800D29D4(&D_801BCFB8, D_801517C0 + 0x70, 0xC, D_801CCFD8);
    if (D_80062D98 == 0) {
        if (p->unk2 < 10) {
            if (p->unk2 < 5) {
                base_a = D_801BA1E8;
                base_b = D_801BA5B8;
                base_c = D_801B8C68;
                for (i = 0; i < 0x7A; i++) {
                    a = &base_a[i];
                    b = &base_b[i];
                    c = &base_c[i];
                    c->vx = a->vx + (b->vx - a->vx) * (p->unk2 + 1) / 5;
                    c->vy = a->vy + (b->vy - a->vy) * (p->unk2 + 1) / 5;
                    c->vz = a->vz + (b->vz - a->vz) * (p->unk2 + 1) / 5;
                }
            } else {
                p->unkE += 0x190;
            }
        }
        if (p->unk2 >= 10) {
            p->unkC -= 0x190;
            p->unk10 -= 0x190;
            p->unkE += 0xC8;
        } else {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B01AC)];
            r = func_80042DA8();
            ang = r % 0x1000;
            q->unk4 = p->unk4 + (func_80039A74(ang) * 1500 >> 12);
            q->unk8 = p->unk8 + (func_80039B40(ang) * 1500 >> 12);
            t = -func_80042DA8();
            q->unkE = -0x190;
            q->unk6 = t % 1000;
        }
        if (++p->unk2 == 0xF) {
            p->unk0 = -1;
            base_a = D_801BA1E8;
            base_c = D_801B8C68;
            for (i = 0; i < 0x7A; i++) {
                a = &base_a[i];
                c = &base_c[i];
                c->vx = a->vx;
                c->vy = a->vy;
                c->vz = a->vz;
            }
        }
    }
}

void func_801B0650(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    MgTask *q2;
    u8 pad[32];
    s16 n;

    b = (MgTask *)D_80162978;
    p = &b[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0xA) {
            q = func_800D4FA8(0xA);
            q->unk0 = p->unk1C;
            q->unk10 = p->unk1A;
            p->unkE = -0xD2;
            func_800D4CBC(p->unk1C, 0x23, 0x1000);
            func_800BBA84(0x15A, p->unk1E, 0);
        }
        if (p->unk2 == 0xF) {
            q2 = &b[func_800BBEAC((M2C_UNK *)func_801B0274)];
            q2->unk4 = D_80151A4C[p->unk1C][0];
            q2->unk6 = D_80151A4C[p->unk1C][1];
            q2->unk8 = D_80151A50[p->unk1C][0];
            q2->unkC = 0x7D0;
            q2->unkE = 0x7D0;
            q2->unk10 = 0x7D0;
            func_800BBEAC((M2C_UNK *)func_801B0088);
            func_800BBA84(0xFA, p->unk1E, 0);
        }
        n = ++p->unk2;
        if (n == 0x1C) {
            p->unk0 = -1;
        }
        D_80151A4C[p->unk1E][0] = p->unk4;
        D_80151A4C[p->unk1E][1] = p->unk6;
        D_80151A50[p->unk1E][0] = p->unk8;
        D_80151A46[p->unk1E][0] = p->unk14;
    }
}

INCLUDE_ASM("../asm/us/magic_dive/nonmatchings/text", func_801B08E8);

void func_801B0BD4(arg0, arg1) {
    MgTask *q;
    u16 *r;

    func_800BBEAC((M2C_UNK *)func_801B0028);
    func_800D2980(&D_801B0CA4, 0, 0, 0);
    q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B08E8)];
    q->unk1E = arg1;
    q->unk14 = D_80151A46[arg1][0];
    r = D_80151A4C[arg1];
    q->unk4 = r[0];
    q->unk6 = r[1];
    q->unk8 = r[2];
}
