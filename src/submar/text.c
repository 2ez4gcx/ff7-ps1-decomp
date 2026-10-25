#include "common.h"
#include "submar/decls.h"

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A00BC);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A10E0);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A11C4);

void func_800A12EC(void) {
    func_80033E34(D_800AD330, D_800AD334, (s32)D_800B365C, 0);
    do {

    } while (func_80034B44() != 0);
    func_80033E34(D_800AD338, D_800AD33C, (s32)D_800B565C, 0);
    do {

    } while (func_80034B44() != 0);
    D_8009A000[0] = 0xC0;
    D_8009A004 = 1;
    func_8002DA7C();
    D_8009A000[0] = 0xA0;
    D_8009A004 = 0x7E;
    func_8002DA7C();
    D_8009A000[0] = 0xA1;
    D_8009A004 = 1;
    func_8002DA7C();
    D_8009A000[0] = 0xA2;
    D_8009A004 = 1;
    func_8002DA7C();
    D_8009A000[0] = 0xA3;
    D_8009A004 = 0x7E;
    func_8002DA7C();
    D_8009A000[0] = 0x29;
    D_8009A004 = 0x40;
    D_8009A008 = 0x238;
    func_8002DA7C();
    D_8009A000[0] = 0x2A;
    D_8009A004 = 0x40;
    D_8009A008 = 0x230;
    func_8002DA7C();
}

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A1444);

void func_800A162C(void) {
    func_80033E74(D_800AD340, D_800AD344, 0x80100000, 0);
    do {

    } while (func_80034B44() != 0);
    func_800A1444(0x80100000, &D_800AD91C);
    func_80033E74(D_800AD348, D_800AD34C, 0x80100000, 0);
    do {

    } while (func_80034B44() != 0);
    func_800A1444(0x80100000, &D_800AD904);
}

void func_800A16BC(s32 arg0) {
    u32 i;
    u32 var_a1;
    u32 var_v1;

    i = arg0 & 0xFF;
    if (i < 6) {
        func_80033E34(D_800AD350[i * 2], D_800AD350[i * 2 + 1], (s32)D_800B0E5C, 0);
        do {

        } while (func_80034B44() != 0);
    }
    func_800A4B50(D_800B265C);
    func_800A4BBC(&D_800B1EB0);
    var_v1 = D_800B1E64;
    if (var_v1 >= 0x10U) {
        var_v1 = 0;
    }
    var_a1 = D_800B1E60;
    var_v1 <<= 0x12;
    D_800B1E64 = var_v1;
    if (var_a1 >= 0x10U) {
        var_a1 = 0;
    }
    D_800B1E60 = var_a1;
    D_800B1E78 = (s32) (D_800B1E70 << 0xC) / (s32) D_800B1E74;
    D_800B1E84 = (s32) (D_800B1E7C << 0xC) / (s32) D_800B1E80;
}

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A1814);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A1AD8);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A1BE8);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A1DA0);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A1F9C);

void func_800A2E7C(void) {
    SubTileM *t;
    u8 *src;
    s32 v;
    s32 i;
    s32 x;
    s32 k;
    s16 *p;

    src = D_800B0E5C;
    t = D_800B5F4C;
    k = D_800B1E60 - 0x30;
    do {
        v = *src++ + k;
        if (v < 0) {
            v = 0;
        }
        if (v > 0x10) {
            v = 0x10;
        }
        x = v << 6;
        t->fE = x;
        t->f0 = x;
        t->fC = x;
        t->flags = 0;
        t++;
    } while (t < &D_800B5F4C[0x1000]);
    for (i = 0; i < 0x1000; i++) {
        p = &D_800B5F4C[i].f8;
        if (i % 64 != 0x3F) {
            p[-1] = p[4];
        } else {
            p[-1] = 0x3C0;
        }
        if (i & 0x3F) {
            p[-2] = p[-12];
        } else {
            p[-2] = 0x3C0;
        }
        if (i / 64 != 0x3F) {
            p[-3] = p[508];
        } else {
            p[-3] = 0x3C0;
        }
        if (i / 64 != 0) {
            p[0] = p[-516];
        } else {
            p[0] = 0x3C0;
        }
    }
}

void func_800A2FB8(s16 arg0) {
    s32 v;
    s32 h;
    s32 cx;
    s32 cy;
    s32 i;
    s32 found;
    s32 x;
    s32 y;
    s32 dy;
    s32 dx;
    SubTileM *t;

    h = D_800B1E64 / 0x1000;
    cx = D_800AE960 / 64;
    cy = cx;
    cx = D_800AE960 - cy * 64;
    if (arg0 > 0x1F4) {
        arg0 = 0x1F4;
    }
    while (arg0 > 0) {
        found = 0;
        for (i = 0; i < 0x1000; i++) {
            t = &D_800B5F4C[i];
            if (t->flags & 0x2000) {
                continue;
            }
            found = 1;
            y = i / 64;
            dy = y - cy;
            x = i - y * 64;
            dx = x - cx;
            if ((u32)(dy + 2) < 5 && (u32)(dx + 2) < 5) {
                continue;
            }
            if (h >= (u16)t->fE) {
                continue;
            }
            if ((s16)func_80042DA8() >= 0x7F) {
                continue;
            }
            t->flags = 0x2000;
            v = 0x400 - (((func_80042DA8() * 8) / 0x7FFF) << 6);
            if (v < 0) {
                v = 0;
            }
            if ((u16)t->fE < v) {
                v = (u16)t->fE;
            }
            arg0--;
            t->fC = v;
            if (arg0 <= 0) {
                break;
            }
        }
        if (!found) {
            break;
        }
    }
}

void func_800A3188(void) {
    SubTileM *t;
    SubTileM *l;
    SubTileM *r;
    SubTileM *u;
    SubTileM *dn;
    u32 i;
    s32 cur;
    s32 fl;
    s32 target;
    s32 d;
    s32 x;
    u32 f2;

    i = 0;
    t = D_800B5F4C;
    l = t - 1;
    r = t + 1;
    u = t - 64;
    dn = t + 64;
    do {
        cur = (u16)t->f0;
        fl = t->flags;
        target = (u16)t->fE;
        if (fl & 0x1000) {
            target = (u16)t->fC;
        }
        if (cur != target) {
            if (cur < target) {
                if (target - cur >= 3) {
                    cur += 2;
                } else {
                    cur += 1;
                }
            } else {
                d = cur - target;
                if (d >= 5) {
                    cur -= d / 4;
                } else {
                    cur -= 1;
                }
            }
            t->f0 = cur;
            x = i & 0x3F;
            if (x != 0) {
                l->f6 = cur;
            }
            if (x != 0x3F) {
                r->f4 = cur;
            }
            x = i >> 6;
            if (x != 0x3F) {
                dn->f8 = cur;
            }
            if (x != 0) {
                u->f2 = cur;
            }
        } else {
            t->flags = fl & 0xEFFF;
        }
        f2 = t->flags;
        if (f2 & 0x8000) {
            cur = f2 & 0xFF;
            cur -= 1;
            f2 &= 0xFF00;
            if (cur < 0) {
                cur = 0;
                f2 = 0;
                t->fC = t->fE;
            }
            t->flags = f2 | cur;
        }
        t++;
        l++;
        r++;
        dn++;
        i++;
        u++;
    } while (i < 0x1000);
}

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A32C8);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A3534);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A35F4);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A36F4);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A435C);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A44A4);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A4624);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A4914);

void func_800A4B50(SubEnt *p) {
    u32 idx;

    do {
        p->x <<= 18;
        idx = p->idx;
        p->y <<= 18;
        p->z <<= 18;
        if (idx > 0x80) {
            idx = 0;
        }
        p->idx = (u32)&D_800B265C[idx];
        p++;
    } while (p < &D_800B265C[0x80]);
}

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A4BBC);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A4D90);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A6158);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A6384);

void func_800A63E4(s32 arg0) {
    s32 var_v0;
    s32 var_v1;

    var_v1 = 0x64808080;
    var_v0 = 0x64202020;
    if (arg0 == 0) {
        var_v1 = 0x64202020;
        var_v0 = 0x64808080;
    }
    D_800AE3C8 = var_v1;
    D_800AE3F0 = var_v0;
}

void func_800A6420(u32 arg0, s32 arg1) {
    SubOtEnt *e;
    u32 *last;
    u32 first;
    u32 w;

    if (arg0 < 0x14) {
        w = D_801BCF08[arg0];
        w &= 0xFF000000;
        w |= (u32)&D_801BCF08[arg0 + 1] & 0xFFFFFF;
        D_801BCF08[arg0] = w;
        if (arg1 == 1) {
            e = &D_800AE5A4[arg0];
            first = e->first;
            last = e->last;
            if (first != 0 && last != 0) {
                *last = (*last & 0xFF000000) | (w & 0xFFFFFF);
                D_801BCF08[arg0] = (D_801BCF08[arg0] & 0xFF000000) | (first & 0xFFFFFF);
            }
        }
    }
}

void func_800A64C0(s32 arg0) {
    SubOtEnt *e;
    u32 *last;
    u32 first;
    u32 *p;
    u32 w;

    p = &D_801BCF48;
    w = *p;
    w &= 0xFF000000;
    w |= (u32)(p + 1) & 0xFFFFFF;
    *p = w;
    if (arg0 != 0) {
        e = &D_800AE644[arg0];
        first = e->first;
        last = e->last;
        if (first != 0 && last != 0) {
            *last = (*last & 0xFF000000) | (w & 0xFFFFFF);
            *p = (*p & 0xFF000000) | (first & 0xFFFFFF);
        }
    }
}

void func_800A6548(s32 arg0) {
    SubOtEnt *e;
    u32 *last;
    u32 first;
    u32 *p;
    u32 w;

    p = &D_801BCF4C;
    w = *p;
    w &= 0xFF000000;
    w |= (u32)(p + 1) & 0xFFFFFF;
    *p = w;
    if (arg0 != 0) {
        e = &D_800AE644[arg0];
        first = e->first;
        last = e->last;
        if (first != 0 && last != 0) {
            *last = (*last & 0xFF000000) | (w & 0xFFFFFF);
            *p = (*p & 0xFF000000) | (first & 0xFFFFFF);
        }
    }
}

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A65D0);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A6778);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A7060);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A71B4);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A7468);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A76C8);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A7D60);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A7FC4);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A8124);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A832C);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A8944);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A9130);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A93B4);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A96C8);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A9914);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A99D4);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A9AD4);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A9CB0);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A9FD0);

void func_800AA180(SubTrail *a) {
    s16 *n;
    s32 x;
    s32 y;
    s32 z;

    x = a->x >> 12;
    n = a->p[4];
    y = a->y >> 12;
    n[0] = x;
    z = a->z >> 12;
    n[1] = y;
    n[2] = z;
    a->p[4] = a->p[3];
    a->p[3] = a->p[2];
    a->p[2] = a->p[1];
    a->p[1] = a->p[0];
    a->p[0] = n;
}

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800AA1D0);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800AA714);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800AAFF0);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800AB118);

void func_800AB484(s32 arg0) {
    s32 i;
    s32 n;
    s32 v;
    SubTile *t;
    SubTileOut *o;


    t = D_800B5F4C;
    o = D_801BCF78;
    for (i = 0, n = 0; i < 0x1000; i++) {
        if (t[i].flags & 0x2000) {
            o[n].a = (i % 64) * 64 - 0x7E0;
            v = t[i].y - 0x20;
            o[n].b = v;
            o[n].c = 0x7E0 - (i / 64) * 64;
            o[n].d = i;
            n++;
            if (n > arg0) {
                break;
            }
        }
    }
}

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800AB518);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800ABA8C);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800ABD4C);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800AC2FC);
