#include "common.h"
#include "chocobo/decls.h"

void func_800A3308(s32 arg0, s32 arg1) {
    ChoRacer *c;
    ChoRacer *base;
    s32 v;

    base = D_800B75CC;
    c = base + arg0;
    switch (arg1) {
    case 1:
        c->f98 = D_800F5084->f4 + 0x14;
        break;
    case 2:
        v = c->f6C;
        v = v + (v * 4) / 3;
        c->f68 = c->f6C = v;
        break;
    case 3:
        c->f98 = D_800F5084->f4 - 0x14;
        break;
    case 4:
        c->f4C = 2;
        break;
    case 5:
        c->f9A = 0;
        break;
    case 6:
        c->f64 = 100;
        c->f52 = 0;
        c->f6 = 3;
        break;
    case 7:
        c->f9C = -1;
        break;
    case 8:
        c->f68 = c->f6C = c->f6C / 2;
        break;
    case 9:
        c->f86 &= 2;
        break;
    case 10:
        c->f86 &= 1;
        break;
    case 11:
        c->fA0 = -1;
        if (func_80042DA8() & 1) {
            c->f6C = c->f6C / 2;
        }
        break;
    case 12:
        c->fA2 = -1;
        break;
    case 13:
        c->f52 = 3;
        break;
    }
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text2", func_800A34A8);

void func_800A44E4(void) {
    s32 key[6];
    s32 id[6];
    s32 pad[10];
    s32 i;
    s32 j;
    s32 t;

    for (i = 0; i < 6; i++) {
        key[i] = *(s16 *)((u8 *)D_800B75CC + i * 0xA4);
        id[i] = i;
    }
    for (i = 0; i < 6; i++) {
        for (j = i; j < 6; j++) {
            if (key[i] < key[j]) {
                t = key[i];
                key[i] = key[j];
                key[j] = t;
                t = id[i];
                id[i] = id[j];
                id[j] = t;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        D_800B764E[id[i]].f0 = i;
    }
    D_800B733C = id[5];
    for (i = 0; i < 6; i++) {
        func_800A4888(i);
    }
    if (D_800B7A48 != 0) {
        func_800A6E50(1);
    } else {
        func_800A6E50(0);
    }
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text2", func_800A4888);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text2", func_800A500C);

void func_800A68D4(s32 arg0) {
    ChoVec v;
    ChoRacer *r;
    s32 *p;
    s32 k;

    p = &D_800F5088;
    if (*p != arg0) {
        *p = arg0;
        r = &D_800B75CC[6];
        *r = D_800B75CC[arg0];
        r->f7C = 0x7F;
        k = 0x81;
        r->f10 = (D_800B7500[r->f0].x0 * r->f7C + D_800B7500[r->f0].x1 * k) / 256;
        r->f12 = (D_800B7500[r->f0].y0 * r->f7C + D_800B7500[r->f0].y1 * k) / 256;
        r->f14 = (D_800B7500[r->f0].z0 * r->f7C + D_800B7500[r->f0].z1 * k) / 256;
        r->f28 = (D_800B7500[r->f2].x0 * r->f7C + D_800B7500[r->f2].x1 * k) / 256;
        r->f2A = (D_800B7500[r->f2].y0 * r->f7C + D_800B7500[r->f2].y1 * k) / 256;
        r->f2C = (D_800B7500[r->f2].z0 * r->f7C + D_800B7500[r->f2].z1 * k) / 256;
        v.vy = 0;
        v.vx = r->f28 - r->f10;
        v.vz = r->f2C - r->f14;
        func_8003A08C(&v, &v);
        r->f3A = func_800A89A0((s16)v.vx, (s16)v.vz);
    }
}

void func_800A6B9C(s32 arg0, s32 arg1, s32 arg2) {
    ChoVec v;
    ChoRacer *r;
    s32 k;
    s32 n;
    s32 next;
    s32 t;

    r = &D_800B75CC[6];
    D_800F5088 = arg0;
    *r = D_800B75CC[arg0];
    n = D_800B74FC;
    t = n + 1;
    next = (arg2 + t) % n;
    r->f7C = 0x7F;
    r->f0 = arg2;
    r->f4 = arg1;
    r->f2 = next;
    k = 0x81;
    r->f10 = (D_800B7500[arg2].x0 * r->f7C + D_800B7500[arg2].x1 * k) / 256;
    r->f12 = (D_800B7500[arg2].y0 * r->f7C + D_800B7500[arg2].y1 * k) / 256;
    r->f14 = (D_800B7500[arg2].z0 * r->f7C + D_800B7500[arg2].z1 * k) / 256;
    r->f28 = (D_800B7500[next].x0 * r->f7C + D_800B7500[next].x1 * k) / 256;
    r->f2A = (D_800B7500[next].y0 * r->f7C + D_800B7500[next].y1 * k) / 256;
    r->f2C = (D_800B7500[next].z0 * r->f7C + D_800B7500[next].z1 * k) / 256;
    v.vy = 0;
    v.vx = r->f28 - r->f10;
    v.vz = r->f2C - r->f14;
    func_8003A08C(&v, &v);
    r->f3A = func_800A89A0((s16)v.vx, (s16)v.vz);
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text2", func_800A6E50);

void func_800A7840(s16 arg0, s16 arg1) {
    
    if (D_800B7A48 == -1) {
        D_800F5054.b[0] = -1;
        D_800F5028 = arg1;
        D_800F509C = arg0;
        return;
    }
    D_800B1358 = -1;
    if (arg0 != -1) {
        D_800B753C = arg1;
        D_800F508C = arg1;
        D_800F5054 = D_800F5084->f38[arg0 - 1];
    }
}
