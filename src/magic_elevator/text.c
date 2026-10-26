#include "common.h"
#include "magic_elevator/decls.h"

void func_801B0000(void) {
    func_801B0EF0();
}

INCLUDE_ASM("../asm/us/magic_elevator/nonmatchings/text", func_801B0020);

void func_801B0418(void) {
    MgObj20 *p;
    s32 i;
    s32 n;

    n = 0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 0x258; i++) {
        if (D_801B115C[i].flag != 0) {
            func_801B0020(&D_801B115C[i]);
            n++;
        }
    }
    if (n == 0 && D_80162080 < 3) {
        p->unk0 = -1;
    }
}

ElvPart *func_801B04E0(void) {
    s32 i;

    for (i = 0; i < 0x258; i++) {
        if (D_801B115C[i].flag == 0) {
            D_801B115C[i].flag = 0xF;
            return &D_801B115C[i];
        }
    }
}

void func_801B0528(void) {
    MgTask *p;
    s16 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = p->unk14;
    func_800D4368(&p->unk4, k, -(k << 5) >> 12);
    D_801B1114[0] = (p->unk2 + 4) | 0x8000;
    D_801D65BC = func_800D4D90(&D_801B1114[-4], D_801517C0 + 0x70, 0xC, D_801D65BC);
    p->unk6 = (u16)p->unk6;
    p->unk2++;
    if (p->unk2 >= 4) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_elevator/nonmatchings/text", func_801B05E4);

void func_801B0854(MgSVec *pos, MgSVec *v) {
    MgSVec pad;
    MgMat m;
    MgMat *mp;
    ElvFx *p;
    MgTask *q;
    s32 i;

    i = 0;
    do {
        i++;
        p = (ElvFx *)func_801B04E0();
        p->pos.vx = pos->vx;
        p->pos.vy = pos->vy;
        p->pos.vz = pos->vz;
        D_801B1122[0] = func_80042DA8() % 1792 - 0x380;
        D_801B1122[-1] = func_80042DA8() % 1792 - 0x380;
        mp = &m;
        func_8003C21C((MgSVec *)&D_801B1122[-1], mp);
        func_8003B35C(mp, &D_801B1128);
        func_8003B2CC(mp, v, &p->vel);
        p->rot.vx = p->rot.vy = p->rot.vz = 0;
        p->spin.vx = (func_80042DA8() & 0x3FF) - 0x200;
        p->spin.vy = (func_80042DA8() & 0x3FF) - 0x200;
        p->spin.vz = (func_80042DA8() & 0x3FF) - 0x200;
    } while (i < 0x14);
    q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0528)];
    *(MgSVec *)&q->unk4 = *pos;
    q->unk14 = 0x1000;
}

s32 func_801B0A10(MgSVec *d, MgSVec *p1, MgSVec *p2) {
    s32 r;
    s32 nb;
    s32 t;

    D_801D65C8 = ((d->vx * D_801D65D0 + d->vz * D_801D65D4) * 2) >> 12;
    r = D_801D65C8 * D_801D65C8 - (D_801D65CC << 14);
    if (r < 0) {
        return -1;
    }
    r = func_80039F5C(r);
    nb = -D_801D65C8;
    t = (nb - r) / 2;
    p1->vx = ((MgSVec *)&D_801D65C0)->vx + ((d->vx * t) >> 12);
    p1->vy = ((MgSVec *)&D_801D65C0)->vy + ((d->vy * t) >> 12);
    p1->vz = ((MgSVec *)&D_801D65C0)->vz + ((d->vz * t) >> 12);
    t = (nb + r) / 2;
    p2->vx = ((MgSVec *)&D_801D65C0)->vx + ((d->vx * t) >> 12);
    p2->vy = ((MgSVec *)&D_801D65C0)->vy + ((d->vy * t) >> 12);
    p2->vz = ((MgSVec *)&D_801D65C0)->vz + ((d->vz * t) >> 12);
    return 0;
}

void func_801B0BC0(void) {
    MgTask *p;
    MgTask *q;
    s32 ang;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 < 0x2D) {
        ang = p->unk2 * 0x500 / 45 - 0x300;
        D_801B1150.vx = func_80039A74(ang);
        D_801B1150.vy = func_80042DA8() % 512 - 0x100;
        D_801B1150.vz = func_80039B40(ang);
        D_801B1158 = func_801B0A10(&D_801B1150, &D_801B1140, &D_801B1148);
        if (D_801B1158 == 0) {
            func_801B0854(&D_801B1140, &D_801B1150);
            func_801B0854(&D_801B1148, &D_801B1150);
            if ((p->unk2 & 1) == 0) {
                func_801B05E4(&D_801B1140);
                func_801B05E4(&D_801B1148);
            }
            if (D_801B113C == 0) {
                func_800D55F4(0x29, func_800D56A8(&D_801B1140), 0x227);
                D_801B113C = 1;
            }
        } else {
            k = ((-0xCE4 - D_801D65C0) << 12) / D_801B1150.vx;
            D_801B1140.vz = D_801D65C4 + ((D_801B1150.vz * k) >> 12);
            if ((u16)(D_801B1140.vz + 0xDAB) < 0x1067) {
                *(s16 *)&D_801B1140 = -0xCE4;
                D_801B1140.vy = D_801D65C2 + ((D_801B1150.vy * k) >> 12);
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0528)];
                *(MgSVec *)&q->unk4 = D_801B1140;
                q->unk14 = 0x4000;
            }
            if (D_801B113C == 0) {
                func_800D55F4(0x28, func_800D56A8(&D_801B1140), 0x1E7);
            }
        }
    }
    p->unk2++;
    if (p->unk2 >= 0x2D) {
        p->unk0 = -1;
    }
}

void func_801B0E90(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D65BC = D_801B65BC + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B0EF0(void) {
    s32 x;
    s32 z;
    s32 i;

    x = -D_801B10EC;
    z = -0x1194 - D_801B10F0;
    D_801D65C0 = 0;
    D_801D65C2 = -0x3E8;
    D_801D65C4 = -0x1194;
    D_801D65D0 = x;
    D_801D65D4 = z;
    D_801D65CC = (x * x + z * z - 9000000) >> 12;
    for (i = 0x543C; i >= 0; i -= 0x24) {
        *(s16 *)((u8 *)D_801B115C + i) = 0;
    }
    func_800BBEAC(func_801B0E90);
    func_800BBEAC(func_801B0BC0);
    func_800BBEAC(func_801B0418);
    func_800D7A88(0, 0, D_80154CA4, 0x5DC, 0, 0x2D);
    return func_800D7A88(0, 0, D_80154CA4 + 0x340, 0x5DC, 0, 0x2D);
}
