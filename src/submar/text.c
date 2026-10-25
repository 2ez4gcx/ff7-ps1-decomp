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

void func_800A1444(SubTimBlk *blk, SubImg *im) {
    u32 mode;
    u16 *tp;
    SubRect r;
    u32 v;

    if (((SubTim *)blk)->id == 0x10) {
        mode = ((SubTim *)blk)->flag & 7;
        im->pmode = mode;
        if (((SubTim *)blk)->flag & 8) {
            blk = (SubTimBlk *)((u8 *)blk + 8);
            if (blk->bnum >= 5) {
                r.x = blk->x;
                r.y = blk->y;
                r.w = 0x100;
                r.h = 1;
                func_80044000(&r, blk->data);
                im->clut = (blk->y << 6) | ((blk->x >> 4) & 0x3F);
                im->cx = r.x;
                im->cy = r.y;
                im->cw = r.w;
                im->ch = r.h;
            }
            blk = (SubTimBlk *)((u8 *)blk + blk->bnum);
        } else {
            blk = (SubTimBlk *)((u8 *)blk + 8);
        }
        if (blk->bnum >= 5) {
            func_80044000(&blk->x, blk->data);
            tp = &im->tpage;
            if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
                v = ((mode & 3) << 9) | (((blk->y & 0x300) >> 3) | 0x80) | ((blk->x & 0x3FF) >> 6);
            } else {
                v = ((mode & 3) << 7) | (((blk->y >> 4) & 0x10) | 0x20) | ((blk->x & 0x3FF) >> 6) | ((blk->y & 0x200) << 2);
            }
            *tp = v;
            im->px = blk->x;
            im->py = blk->y;
            im->pw = blk->w;
            im->ph = blk->h;
        }
    }
}

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

void func_800A1AD8(void) {
    u32 pad;
    u32 hold;
    u16 cur;
    u32 press;
    u32 i;
    u32 v;
    u32 n;

    pad = func_8001C808();
    cur = pad;
    i = 0;
    hold = D_800AD45A;
    D_800AD458 = cur;
    D_800AD460 = pad >> 16;
    D_800AD45A = cur;
    press = pad & ~hold;
    hold &= pad;
    D_800AD45C = press;
    do {
        if (D_800AD44C[i] & press) {
            D_800AD440[i] = 10;
        }
        v = D_800AD44C[i];
        if (v & hold) {
            n = D_800AD440[i];
            if (n == 0) {
                press |= v;
                D_800AD440[i] = 1;
            } else {
                n = n - 1;
                D_800AD440[i] = n;
            }
        }
        i++;
    } while (i < 5);
    D_800AD45E = press;
    D_800AD466 = 0;
    cur = D_800AD460;
    hold = D_800AD462;
    D_800AD462 = cur;
    press = cur & ~hold;
    D_800AD464 = press;
}

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

void func_800A4BBC(SubSelIn *in) {
    SubSel *p;
    u8 *t1;
    u8 *t2;
    s32 z;
    s32 cx;
    s32 cy;

    p = D_800B08EC;
    t1 = (u8 *)D_800B265C;
    t2 = D_800AEAA0;
    D_800AD8DC[0] = 0;
    D_800AD8E0 = 0;
    D_800AD8E4 = 0;
    *(s32 *)(u8 *)&D_800AD8E8 = 0;
    do {
        p->x = in->x << 18;
        p->y = in->y << 18;
        z = in->z << 18;
        p->z = z;
        cy = z >> 12;
        cx = p->x >> 12;
        cx = (cx + 0x800) / 64;
        if (cx < 0) {
            cx = 0;
        }
        if (cx >= 0x40) {
            cx = 0x3F;
        }
        cy = (0x800 - cy) / 64;
        if (cy < 0) {
            cy = 0;
        }
        if (cy >= 0x40) {
            cy = 0x3F;
        }
        p->tile = cy * 64 + cx;
        p->f10 = in->f10;
        p->f1C = in->f14;
        p->f1E = in->f16;
        p->f20 = in->f18;
        p->f2C = in->f1C;
        p->f30 = in->f20;
        p->flags = in->f24;
        if (in->f24 & 1) {
            p->p58 = (u8 *)((in->f2C << 5) + (u32)t1);
            p->p54 = (u8 *)((in->f28 << 4) + (u32)t2);
            D_800AD8DC[0] += 1;
            *(s32 *)(u8 *)&D_800AD8E8 += in->f10;
        }
        in++;
        p++;
    } while (p < &D_800B08EC[12]);
}

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A4D90);

void func_800A6158(void) {
    s32 s;
    s32 q;
    s32 d;
    s32 blank;
    s32 *p;
    SubSel *e;

    s = 0;
    e = D_800B08EC;
    p = &e[0].f10;
    do {
        if (p[9] & 3) {
            s += p[0];
        }
        p = (s32 *)((u8 *)p + 0x74);
    } while ((u32)p < (u32)&e[12].f10);
    s = D_800AD8E8 - s;
    s += D_800AE8E0;
    s += D_800AD3B4;
    s -= D_800AE9FC * 100;
    if (s < 0) {
        s = 0;
    }
    if (s > 99999) {
        s = 99999;
    }
    blank = 1;
    q = s / 10000;
    d = q;
    if (q == 0) {
        d = 0xC;
    } else {
        blank = 0;
    }
    D_800AE54C = d << 4;
    s -= q * 10000;
    q = s / 1000;
    d = q;
    if (q == 0 && blank == 1) {
        d = 0xC;
    } else {
        blank = 0;
    }
    D_800AE560 = d << 4;
    s -= q * 1000;
    q = s / 100;
    d = q;
    if (q == 0 && blank == 1) {
        d = 0xC;
    } else {
        blank = 0;
    }
    D_800AE574 = d << 4;
    s -= q * 100;
    q = s / 10;
    d = q;
    if (q == 0 && blank == 1) {
        d = 0xC;
    }
    q = s - q * 10;
    D_800AE588 = d << 4;
    D_800AE59C = q << 4;
}

void func_800A6384(void) {
    s32 s;
    s32 n;

    s = D_800AD8E0 + D_800AD8E4;
    n = s / 10;
    D_800AE484 = n << 4;
    n = s % 10;
    D_800AE498 = n << 4;
}

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

void func_800A65D0(void) {
    s32 flags;
    s32 n;
    u32 *p1;
    u32 *o1;
    u32 v1;
    u32 w1;
    u32 *p2;
    u32 *o2;
    u32 v2;
    u32 w2;
    u32 *p3;
    u32 *o3;
    u32 v3;
    u32 w3;
    u32 *p4;
    u32 *o4;
    u32 v4;
    u32 w4;

    flags = D_800AE96C;
    n = 0;
    if (flags & 0x300) {
        p1 = &D_800AD97C;
        D_800AD996 = D_800AD91A + 3;
        if (flags & 0x200) {
            D_800AD996 = D_800AD91A + 1;
        }
        o1 = &D_801BCF58;
        v1 = *p1 & 0xFF000000;
        v1 |= *o1 & 0xFFFFFF;
        w1 = *o1 & 0xFF000000;
        w1 |= (u32)p1 & 0xFFFFFF;
        *p1 = v1;
        *o1 = w1;
        n = 1;
    }
    if (flags & 0x400) {
        p2 = &D_800AD99C;
        o2 = &D_801BCF5C;
        v2 = *p2 & 0xFF000000;
        v2 |= *o2 & 0xFFFFFF;
        w2 = *o2 & 0xFF000000;
        w2 |= (u32)p2 & 0xFFFFFF;
        *p2 = v2;
        *o2 = w2;
        n += 2;
    }
    if (flags & 0x4000) {
        p3 = &D_800AD9BC;
        o3 = &D_801BCF60;
        v3 = *p3 & 0xFF000000;
        v3 |= *o3 & 0xFFFFFF;
        w3 = *o3 & 0xFF000000;
        w3 |= (u32)p3 & 0xFFFFFF;
        *p3 = v3;
        *o3 = w3;
        n += 3;
    }
    if (flags & 0x8000) {
        p4 = &D_800AD9DC;
        o4 = &D_801BCF60;
        v4 = *p4 & 0xFF000000;
        v4 |= *o4 & 0xFFFFFF;
        w4 = *o4 & 0xFF000000;
        w4 |= (u32)p4 & 0xFFFFFF;
        *p4 = v4;
        *o4 = w4;
        n += 5;
    }
    if (n != 0) {
        n = n * 8;
        if (n >= 0x80) {
            n = 0x7F;
        }
    } else {
        n = 1;
    }
    D_800AD93C = n;
}

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A6778);

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A7060);

void func_800A71B4(void) {
    s32 n;
    s32 sumsq;
    s32 sumv;
    s32 dist;
    s32 v;
    SubObj *e;
    s32 *q;
    s32 x;
    s32 i;

    n = 0;
    sumsq = 0;
    sumv = 0;
    i = 0;
    q = D_800AE8D0;
    e = D_800F5F6C;
    do {
        if (e->a7C & 6) {
            if (e >= &D_800F5F6C[16]) {
                q[39] |= 0x8000;
            }
            dist = *(s32 *)(e->pad50 + 8);
            dist = 0x100 - dist;
            if (dist >= 0) {
                v = *(s32 *)(e->pad50 + 16);
                n += 1;
                if (v < -0x800 && (e->a7C & 2)) {
                    q[39] |= 0x2000;
                }
                if (v < 0) {
                    v = -v;
                }
                v = v / 4;
                x = D_8004BC98[v & 0xFFF];
                x >>= 17;
                if (*(s32 *)(e->pad50 + 12) < 0) {
                    x = -x;
                }
                sumv += x * dist;
                sumsq += dist * dist;
            }
        }
        i++;
        e++;
    } while (i < 0x20);
    if (n != 0) {
        sumv /= 256;
        sumsq /= 256;
        sumv /= n;
        sumsq /= n;
        sumv /= 32;
        sumsq /= 2;
        if (sumv < -0x40) {
            sumv = -0x40;
        }
        if (sumv >= 0x40) {
            sumv = 0x3F;
        }
        if (sumsq >= 0x80) {
            sumsq = 0x7F;
        }
        if (sumsq == 0) {
            sumsq = 1;
        }
        D_8009A000[0] = 0xA6;
        D_8009A004 = 4;
        D_8009A008 = sumsq;
        func_8002DA7C();
        D_8009A000[0] = 0xAE;
        D_8009A004 = 4;
        sumv += 0x40;
        D_8009A008 = sumv;
    } else {
        D_8009A000[0] = 0xA6;
        D_8009A004 = 8;
        D_8009A008 = 1;
        func_8002DA7C();
        D_8009A000[0] = 0xAE;
        D_8009A004 = 2;
        D_8009A008 = 0x40;
    }
    func_8002DA7C();
}

void func_800A7468(void) {
    s32 n;
    s32 sumsq;
    s32 sumv;
    s32 dist;
    s32 v;
    SubSel *e;
    s32 *q;
    s32 x;

    n = 0;
    sumsq = 0;
    sumv = 0;
    q = D_800AE8D0;
    e = D_800B08EC;
    do {
        if (e->flags & 3) {
            if (e->state & 0xF00) {
                q[39] |= 0x4000;
            }
            dist = e->f40;
            dist = 0x100 - dist;
            if (dist >= 0) {
                v = *(s32 *)e->pad44;
                n += 1;
                if (v < -0x800 && (e->flags & 8)) {
                    q[39] |= 0x1000;
                }
                if (v < 0) {
                    v = -v;
                }
                v = v / 4;
                x = D_8004BC98[v & 0xFFF];
                x >>= 17;
                if (*(s32 *)(e->pad44 + 4) < 0) {
                    x = -x;
                }
                sumv += x * dist;
                sumsq += dist * dist;
            }
        }
        e++;
    } while (e < &D_800B08EC[12]);
    if (n != 0) {
        sumv /= 256;
        sumsq /= 256;
        sumv /= n;
        sumsq /= n;
        sumv /= 32;
        sumsq /= 2;
        if (sumv < -0x40) {
            sumv = -0x40;
        }
        if (sumv >= 0x40) {
            sumv = 0x3F;
        }
    }
    sumv += 0x40;
    sumsq += 0x18;
    if (sumsq >= 0x80) {
        sumsq = 0x7F;
    }
    D_8009A000[0] = 0xA5;
    D_8009A004 = 4;
    D_8009A008 = sumsq;
    func_8002DA7C();
    D_8009A000[0] = 0xAD;
    D_8009A004 = 4;
    D_8009A008 = sumv;
    func_8002DA7C();
}

INCLUDE_ASM("../asm/us/submar/nonmatchings/text", func_800A76C8);

void func_800A7D60(s32 n) {
    SubCamEnt *e;
    s32 a;
    s32 t;
    s32 d;

    a = D_800AE914;
    if (D_800AE964.f4 == 0) {
        if (D_800AE7E0[n].f14 != 0) {
            a += D_800AE91C;
        }
    } else {
        if (D_800AE7E0[n].f14 == 0) {
            a -= D_800AE91C;
        }
    }
    e = &D_800AE7E0[n];
    D_801BA30C.a0 = a;
    t = e->ang[0];
    d = ((t + 0x1000) & 0xFFF) - ((a + 0x1000) & 0xFFF);
    D_801BA30C.b0 = t;
    if (d >= 0x801) {
        d -= 0x1000;
    }
    if (d < -0x800) {
        d += 0x1000;
    }
    D_801BA30C.c0 = d;
    a = D_800AE916;
    D_801BA30C.a1 = a;
    t = e->ang[1];
    d = ((t + 0x1000) & 0xFFF) - ((a + 0x1000) & 0xFFF);
    D_801BA30C.b1 = t;
    if (d >= 0x801) {
        d -= 0x1000;
    }
    if (d < -0x800) {
        d += 0x1000;
    }
    D_801BA30C.c1 = d;
    a = D_800AE918;
    D_801BA30C.a2 = a;
    t = e->ang[2];
    d = ((t + 0x1000) & 0xFFF) - ((a + 0x1000) & 0xFFF);
    D_801BA30C.b2 = t;
    if (d >= 0x801) {
        d -= 0x1000;
    }
    if (d < -0x800) {
        d += 0x1000;
    }
    D_801BA30C.c2 = d;
    a = D_800AE944;
    D_801BA30C.f18 = a;
    t = e->f8;
    D_801BA30C.f1C = t;
    D_801BA30C.f20 = t - a;
    a = D_800AD40C;
    D_801BA30C.f24 = a;
    t = e->fC;
    D_801BA30C.f30 = 0;
    D_801BA30C.f34 = 0x100;
    D_801BA30C.f28 = t;
    D_801BA30C.f2C = t - a;
    D_800AE964.f0 = e->f10;
    D_800AE964.f4 = e->f14;
    D_800AEA00 = e->f18;
    D_800AEA04 = e->f1C;
    D_800AEA10 = e->f20;
    D_800AEA14 = e->f24;
    D_800AEA18 = e->f28;
}

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

void func_800AAFF0(void) {
    u32 i;
    SubObj *p;
    SubVec32 *q1;
    SubVec16 *q2;
    SubVec16 *q3;
    SubVec16 *q4;
    SubVec16 *q5;
    s32 *g;

    for (i = 0; i < 0x20; i++) {
        p = &D_800F5F6C[i];
        q1 = &D_800F5F6C[i].v1;
        q2 = &D_800F5F6C[i].s2;
        q3 = &D_800F5F6C[i].s3;
        q4 = &D_800F5F6C[i].s4;
        q5 = &D_800F5F6C[i].s5;
        p->v0.vx = 0;
        p->v0.vy = 0;
        p->v0.vz = 0;
        q1->vx = 0;
        q1->vy = 0;
        q1->vz = 0;
        q2->vx = 0;
        q2->vy = 0;
        q2->vz = 0;
        q3->vx = 0;
        q3->vy = 0;
        q3->vz = 0x1000;
        q4->vx = 0;
        q4->vy = 0;
        q4->vz = 0;
        q5->vx = 0;
        q5->vy = 0;
        q5->vz = 0x1000;
        p->a78 = 0x20;
        p->a64 = 0;
        p->a68 = 0x1000;
        p->a70 = 0;
        p->a74 = 0;
        p->a7C = 1;
        p->a80 = 0;
        p->a84 = 0;
    }
    for (i = 0, g = &D_800B1E74; i < 0x10; i++) {
        p = &D_800F5F6C[i];
        p->a6C = *g;
    }
    for (i = 0x10, g = &D_800B1E80; i < 0x20; i++) {
        p = &D_800F5F6C[i];
        p->a6C = *g;
    }
    D_800AE9FC = 0;
}

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
