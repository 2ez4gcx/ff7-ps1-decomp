#include "common.h"
#include "magic_siva/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B49CC();
    return &D_801D9E98;
}

MgMat *func_801B007C(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801F0040.m[0][0] = D_801F0040.m[1][1] = D_801F0040.m[2][2] = scale;
    func_8003B48C(&D_801F1374);
    func_8003B51C(&D_801F1374);
    func_8003BC6C(v, (MgVec *)D_801F0040.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801F0040.t, &n);
        D_801F0040.t[0] += (dist * n.vx) >> 12;
        D_801F0040.t[1] += (dist * n.vy) >> 12;
        D_801F0040.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801F0040);
    func_8003B51C(&D_801F0040);
    return &D_801F0040;
}

s32 func_801B0198(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F139E[-v];
    }
    return v;
}

s32 func_801B01D4(s32 t, s32 s) {
    s32 orig;
    s32 i;
    s32 n;

    orig = t;
    if (s > 0) {
        n = s >> 8;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
    } else {
        s = -s;
        n = s >> 8;
        t = 0x1000 - t;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
        t = 0x1000 - t;
    }
    n = (s & 0xFF) + 1;
    t = (t * n + orig * (0x100 - n)) >> 8;
    return t;
}

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B02C4);

void func_801B1300(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B02C4)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B1364);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B1760);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B1B5C);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2078);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2150);

s32 func_801B2224(void) {
    MgSVec *sp;
    s32 i;
    s32 n;

    n = 0;
    sp = (MgSVec *)0x1F800000;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    for (i = 0; i < 200; i++) {
        if (D_801F13B4[i].life != 0) {
            if (D_80062D98 == 0) {
                func_801B1B5C(&D_801F13B4[i]);
            }
            sp->vx = D_801F13B4[i].x + D_801F13B4[i].vx;
            sp->vy = D_801F13B4[i].y + D_801F13B4[i].vy;
            sp->vz = D_801F13B4[i].z + D_801F13B4[i].vz;
            D_801F13B4[i].fn(sp, &D_801F13B4[i].x, D_801F13B4[i].life);
            if (D_80062D98 == 0) {
                *(MgSVec *)&D_801F13B4[i].x = *sp;
                D_801F13B4[i].vx -= D_801F13B4[i].vx >> 2;
                D_801F13B4[i].vy -= D_801F13B4[i].vy >> 2;
                D_801F13B4[i].vz -= D_801F13B4[i].vz >> 2;
                D_801F13B4[i].life--;
                if ((u16)(D_801F13B4[i].x + 0x4E20) > 0x9C40 || (u16)(D_801F13B4[i].z + 0x4E20) > 0x9C40 || D_801F13B4[i].y > 0) {
                    D_801F13B4[i].life = 0;
                }
            }
            n++;
        }
    }
    return n;
}

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B249C);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B24C0);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B257C);

void func_801B25C4(void) {
    s32 i;
    s32 *p;

    i = 0x1F3;
    p = D_801F45B4;
    do {
        *p = 0;
        i--;
        p--;
    } while (i >= 0);
}

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B25E8);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2658);

void func_801B274C(s32 arg0) {
    D_801F2674 = arg0;
}

void func_801B275C(MgSVec *arg0) {
    func_801B007C(arg0, 0x1000, 0);
    D_80163C74 = func_800D4D90(&D_801F0298, D_801517C0 + 0x70, 0xC, D_80163C74);
}

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B27AC);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B28A0);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2B1C);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2C6C);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2DE0);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B2FAC);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B30DC);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B3188);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B3408);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B3644);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B3938);

void func_801B3B10(void) {
    SvTask *p;
    s32 t;
    s32 q;

    p = (SvTask *)&D_80162978[D_8015169C];
    D_801F0338.v = D_801F0008[p->unk0];
    t = p->unk2;
    if (t < 0x19) {
        if (t < 5) {
            q = (t << 12) / 5;
            D_801F0348->scale.vx = D_801F0348->scale.vy = D_801F0348->scale.vz = q * 0x1200 >> 12;
        } else {
            D_801F0348->scale.vx = D_801F0348->scale.vy = D_801F0348->scale.vz = 0x1200;
        }
        func_8003A63C(&D_801F1374, p->unk14, &D_801F0348->m1);
        func_8003B35C(&D_801F0348->m1, &D_801F0348->scale);
        func_8003B48C(&D_801F0348->m1);
        func_8003B51C(&D_801F0348->m1);
        D_80163C74 = func_801B1364(&D_801F0338, D_801517C0 + 0x70, 0xC, D_80163C74);
    } else {
        t -= 0x19;
        if (t < 0x1E) {
            q = (t << 12) / 30;
            if (t == 0) {
                D_801F0348->scale.vx = D_801F0348->scale.vy = D_801F0348->scale.vz = 0x1200;
                func_8003B35C(p->unk14, &D_801F0348->scale);
            }
            func_8003C21C(&p->unk4, &D_801F0348->m1);
            if (D_80062D98 == 0) {
                p->unk4 += p->unkC;
                p->unk6 += p->unkE;
                p->unk8 += p->unk10;
            }
            func_8003A63C(&D_801F1374, p->unk14, &D_801F0348->m2);
            func_801B3938(D_801F0008[p->unk0], p->unk1A, &D_801F0348->m1, &D_801F0348->m2);
            func_8003B69C(0, 0, 0);
            D_801F0342 = q;
            D_80163C74 = func_801B1760(&D_801F0338, D_801517C0 + 0x70, 0xC, D_80163C74, D_801F45B8 + (*(s16 *)((u8 *)p + 0x1A) << 5));
        } else {
            p->unk0 = -1;
            return;
        }
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B3E00);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B3FD4);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B40F0);

void func_801B4334(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;
    u16 temp_v1;
    u16 temp_v1_2;
    u16 temp_v1_3;

    temp_s0 = &D_80162978[D_8015169C];
    func_800D41FC(&D_801F1374, &D_801546EC, D_801F0374);
    temp_v1 = M2C_FIELD(D_801F0374, u16 *, 0x14);
    M2C_FIELD(D_801F2674, u16 *, 0x18) = temp_v1;
    M2C_FIELD(D_801F2674, u16 *, 4) = temp_v1;
    temp_v1_2 = M2C_FIELD(D_801F0374, u16 *, 0x18);
    M2C_FIELD(D_801F2674, u16 *, 0x1A) = temp_v1_2;
    M2C_FIELD(D_801F2674, u16 *, 6) = temp_v1_2;
    temp_v1_3 = M2C_FIELD(D_801F0374, u16 *, 0x1C);
    M2C_FIELD(D_801F2674, u16 *, 0x1C) = temp_v1_3;
    M2C_FIELD(D_801F2674, u16 *, 8) = temp_v1_3;
    func_8003B2CC(D_801F0374, &D_801F036C, D_801F2674 + 0x20);
    if (D_80062D98 == 0) {
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 >= 0x3C) {
            temp_s0->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B440C);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B47B4);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B49CC);
