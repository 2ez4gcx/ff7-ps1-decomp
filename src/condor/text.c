#include "common.h"
#include "condor/decls.h"

void func_800A037C(s32 arg0, s32 arg1) {
    s32 otz;
    s32 p;
    s32 flag;
    CondorSV rot;
    CondorSV rot2;
    CondorV scale;
    CondorMat m;
    CondorGfx *g;
    u8 *q;
    u8 *r;
    s32 t;

    rot2.x = D_8012C4CC - 0x100;
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    rot2.z = 0;
    rot2.y = D_8012C4D0 - 0x200;
    scale.x = D_8012C388;
    scale.y = D_8012C388;
    scale.z = D_8012C388;
    func_8003AE38();
    g = D_80129F34;
    g->v[0].x = g->v[2].x = -0x20;
    g->v[1].x = g->v[3].x = D_8012C4D4 * 2;
    g->v[0].y = g->v[1].y = -8;
    g->v[2].y = g->v[3].y = D_8012C4D8 * 2;
    g->v[0].z = g->v[1].z = g->v[2].z = g->v[3].z = D_8012C388 * 2;
    func_8003BF8C(&rot, &m);
    func_8003B35C(&m, &scale);
    func_8003BC6C(&rot2, m.t, &flag);
    func_8003B48C(&m);
    func_8003B51C(&m);
    q = (u8 *)g + 0x6788;
    t = arg1 * 0x18 + 0xC;
    r = q + t;
    func_8003BE8C(&g->v[0], &g->v[1], &g->v[2], &g->v[3], r + 8, r + 0xC, r + 0x10, r + 0x14, &p, &otz, &flag);
    func_80046794(arg0 + otz * 4, r);
    func_80046794(arg0 + otz * 4, q);
    func_8003AED8();
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A0548);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A115C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A1A80);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A1B94);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A1EEC);

s16 func_800A2068(CondorEnt *e, s32 arg1, s32 arg2) {
    CondorEnt *p;
    s16 best;
    s16 found;
    s16 i;
    s32 s;
    s16 a;
    s16 b;
    s16 dx;
    s16 dy;
    s32 r;
    s16 n;
    s16 k;

    D_8012B85C = 0;
    best = 0x4000;
    found = -1;
    p = (CondorEnt *)&D_800BE8C0[(s16)arg1];
    i = arg1;
    n = arg2;
    if ((s16)arg1 < n) {
        do {
            if (p->flags != 0) {
                a = p->w4A;
                b = e->w4A;
                if (a < b) {
                    r = a < b - e->pad14[0xF];
                } else {
                    r = b < a - p->pad14[0xF];
                }
                if (r == 0) {
                    s = (p->pad14[0xE] + e->pad14[0xE]) >> 1;
                    a = p->w48;
                    b = e->w48;
                    if (a < b) {
                        r = a < b - s;
                    } else {
                        r = b < a - s;
                    }
                    if (r == 0 && p != e && p->b05 == 0) {
                        k = D_8012B85C;
                        D_8012B75C[k].p = (CondorObj *)p;
                        *(s16 *)&D_8012B75C[k].x = i;
                        D_8012B85C = k + 1;
                        dx = (u16)p->w48 - e->w48;
                        if (dx < 0) {
                            dx = -dx;
                        }
                        dy = (u16)p->w4A - e->w4A;
                        if (dy < 0) {
                            dy = -dy;
                        }
                        if (dx > dy) {
                            dx = dy;
                        }
                        if (dx < best) {
                            best = dx;
                            found = i;
                        }
                    }
                }
            }
            i++;
            p++;
        } while (i < n);
    }
    return found;
}

s16 func_800A224C(CondorEnt *e, s32 arg1, s32 arg2) {
    CondorEnt *p;
    s16 best;
    s16 found;
    s16 i;
    s16 h;
    s32 s;
    s16 a;
    s16 b;
    s16 dx;
    s16 dy;
    s32 r;
    s16 n;
    s16 k;

    best = 0x4000;
    found = -1;
    p = (CondorEnt *)&D_800BE8C0[(s16)arg1];
    i = arg1;
    n = arg2;
    D_8012B85C = 0;
    h = e->pad14[0xF];
    if ((s16)arg1 < n) {
        do {
            if (p->flags != 0) {
                a = p->w4A;
                b = e->w4A;
                if (a < b) {
                    r = a < b - h;
                } else {
                    r = b < a - h;
                }
                if (r == 0) {
                    s = p->pad14[0xE] + e->pad14[0xE];
                    a = p->w48;
                    b = e->w48;
                    if (a < b) {
                        r = a < b - s;
                    } else {
                        r = b < a - s;
                    }
                    if (r == 0 && p->b05 == 0) {
                        k = D_8012B85C;
                        D_8012B75C[k].p = (CondorObj *)p;
                        *(s16 *)&D_8012B75C[k].x = i;
                        D_8012B85C = k + 1;
                        dx = (u16)p->w48 - e->w48;
                        if (dx < 0) {
                            dx = -dx;
                        }
                        dy = (u16)p->w4A - e->w4A;
                        if (dy < 0) {
                            dy = -dy;
                        }
                        if (dx > dy) {
                            dx = dy;
                        }
                        if (dx < best) {
                            best = dx;
                            found = i;
                        }
                    }
                }
            }
            i++;
            p++;
        } while (i < n);
    }
    return found;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A2414);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A254C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A2640);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A2798);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A28E4);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A2B40);

void func_800A2CB4(u16 arg0, u16 arg1) {
    CondorAnim *a;
    CondorPrim *p;
    CondorPrim *q;
    s32 n;
    s32 i;
    u16 clut;

    a = &D_8010BB94[arg0];
    n = a->w * a->h;
    p = (CondorPrim *)(D_80120C2C + (a->a << 4));
    q = (CondorPrim *)(D_80120C2C + 0x69BC + (a->a << 4));
    clut = func_80046634(0x380, arg1 + 0xF0);
    for (i = 0; i < n; i++) {
        q->clut = clut;
        p->clut = clut;
        p++;
        q++;
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A2D68);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A2FD4);

u8 func_800A3260(u32 arg0) {
    u32 q;

    if (D_8012C53C == 0) {
        if (D_8012C430 == 0) {
            return -(arg0 != 1);
        }
        return 0;
    }
    q = D_8012C53C / arg0;
    if (q == 0) {
        return -(D_8012C430 == 0);
    }
    D_8012C430++;
    D_8012C53C -= q * arg0;
    return q;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A3304);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A3A98);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A427C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A46E4);

void func_800A4B2C(void) {
    if (D_80121EF0[D_8012C3F0].f > 0x50) {
        D_8012C488 = 1;
    } else {
        D_8012C488 = 3;
    }
    D_8012C47C = 2;
    D_8012C484 = 1;
    D_8012C480 = 1;
}

void func_800A4BB0(void) {
    CondorPix *p;
    CondorPix *q;
    s32 i;
    u16 t;

    p = (CondorPix *)(D_80121EEC + D_8012C3F0 * 0x69BC);
    if (D_8012C488 == 1) {
        i = 0;
        if (p->r >= 0x51) {
            do {
                p->r += 0xF0;
                p->g += 0xF0;
                p->b += 0xF0;
                p++;
                i++;
            } while (i < 0x126);
        } else {
            if (D_8012C3F0 == 0) {
                D_8012C480 = 0;
            } else {
                D_8012C484 = 0;
            }
            if ((D_8012C480 | D_8012C484) == 0) {
                t = D_8012C47C;
                D_8012C47C = 0;
                D_8012C488 = t;
            }
        }
    }
    if (D_8012C488 == 3) {
        i = 0;
        if (p->r < 0x50) {
            q = p;
            do {
                q->r += 0x10;
                q->g += 0x10;
                q->b += 0x10;
                q++;
                i++;
            } while (i < 0x126);
        } else {
            if (D_8012C3F0 == 0) {
                D_8012C480 = 0;
            } else {
                D_8012C484 = 0;
            }
            if ((D_8012C480 | D_8012C484) == 0) {
                t = D_8012C47C;
                D_8012C47C = 0;
                D_8012C488 = t;
            }
        }
    }
    if (D_8012C488 == 2) {
        if (D_8012C3F0 == 0) {
            D_8012C480 = 0;
        } else {
            D_8012C484 = 0;
        }
        if ((D_8012C480 | D_8012C484) == 0) {
            t = D_8012C47C;
            D_8012C47C = 0;
            D_8012C488 = t;
        }
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A4DFC);

void func_800A5210(s16 arg0, s32 arg1) {
    arg1 += 0x27;
    D_8009A000 = arg1;
    D_8009A004 = 0x40;
    D_8009A008 = arg0;
    func_8002DA7C(arg0, arg1);
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A5258);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A5B64);

s32 func_800A5E04(void) {

    D_8012C42C = 1;
    if (D_8012C390 & 0xF000) {
        func_800ABA58(D_8012C390);
        func_800ABA58(D_8012C390);
        func_800ABA58(D_8012C390);
        func_800ABA58(D_8012C390);
        if (D_8012C390 & 0x80) {
            func_800ABA58(D_8012C390);
            func_800ABA58(D_8012C390);
            func_800ABA58(D_8012C390);
            func_800ABA58(D_8012C390);
        }
    }
    if (D_8012C39C & 0x800) {
        D_8009A000 = 0x2B;
        D_8009A004 = 0x40;
        D_8009A008 = 1;
        func_8002DA7C();
        if (D_8012C40C != D_8012C410) {
            D_8012C408 = 1;
            return;
        }
        D_8012C3EC = 0;
        D_8012C42C = 0;
        D_8012C488 = (s16) D_8012C48C;
        if ((s16) D_8012C48C == 1) {
            D_8012C47C = 1;
            D_8012C484 = 1;
            D_8012C480 = 1;
        } else {
            if ((u8) D_80121EF0[D_8012C3F0].f > 0x50) {
                D_8012C488 = 1;
            } else {
                D_8012C488 = 3;
            }
            D_8012C47C = 2;
            D_8012C484 = 1;
            D_8012C480 = 1;
        }
        func_800A2D68();
        func_800A95C0();
        D_8012C428 = 1;
        D_8012C3A4 = D_8012C44C + D_8012C434;
        D_8012C3A6 = D_8012C450 + D_8012C438;
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A6048);

s32 func_800A6298(void) {
    s32 n;
    s32 t;
    u8 pad[8];

    if (D_8012C4C0 < D_8012C4C4) {
        D_8012C4C0++;
    } else {
        D_8012C4C0 = D_8012C4C4;
    }
    n = 0;
    if (D_8012C4C0 > 0) {
        do {
            func_800A71D8();
            if (D_8012C3EC == 0) {
                D_8012C41C = D_8012C4E0;
                func_800AB5BC();
                func_800A427C();
                t = D_8012C5CC;
                if (t == 0) {
                    D_8012C41C = -1;
                    D_8012C428 = 1;
                    D_8012C41C = func_800A1EEC(&D_8012C3A4);
                    func_800A93A0();
                } else if (t == 1) {
                    D_8012C3EC = 5;
                    D_800BE8C0[D_8012C424].pad[0x2B] = 1;
                    D_8012C3E8 = t;
                } else {
                    D_8012C3EC = 0;
                    D_8012C5CC = 0;
                    D_8012C42C = 0;
                    D_8012C3E8 = 2;
                }
                return 0;
            }
            n++;
        } while (n < D_8012C4C0);
    }
    return 0;
}

s32 func_800A6430(void) {
    s32 n;
    u32 t;
    u8 pad[8];

    if (D_8012C5C4 != 0) {
        t = D_8012C5C4 >> 2;
        D_8010BCB2 = 0xFFF8;
        D_8010BCB4 = 0xFFE0 - (t - t / 3 * 3);
        do {
        } while (0);
        return 0;
    }
    if (D_8012C4C0 < D_8012C4C4) {
        D_8012C4C0++;
    } else {
        D_8012C4C0 = D_8012C4C4;
    }
    n = 0;
    if (D_8012C4C0 > 0) {
        do {
            if (D_8012C57C == 4) {
                D_8012C3EC = 0;
            } else {
                func_800A71D8();
            }
            n++;
            if (D_8012C3EC == 0) {
                D_8012C47C = 1;
                D_8012C484 = 1;
                D_8012C480 = 1;
                D_8012C42C = 0;
                D_8012C41C = -1;
                D_8012C428 = 1;
                D_8012C41C = func_800A1EEC(&D_8012C3A4);
                func_800A427C();
                return 0;
            }
        } while (n < D_8012C4C0);
    }
    return 0;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A65BC);

void func_800A6808(CondorEnt *arg0) {
    u32 x;
    s32 v;
    s32 c;

    switch (arg0->w06) {
    case 19:
        c = 0x2A;
        x = arg0->w48;
        D_8009A000 = c;
        D_8009A004 = 0x40;
        D_8009A008 = 0;
        func_8002DA7C();
        v = 0xE3;
        break;
    case 4:
        c = 0x2A;
        x = arg0->w48;
        D_8009A000 = c;
        D_8009A004 = 0x40;
        D_8009A008 = 0;
        func_8002DA7C();
        v = 0xE4;
        break;
    case 12:
    case 13:
    case 18:
        c = 0x2A;
        x = arg0->w48;
        D_8009A000 = c;
        D_8009A004 = 0x40;
        D_8009A008 = 0;
        func_8002DA7C();
        v = 0xE1;
        break;
    case 17:
        c = 0x2A;
        x = arg0->w48;
        D_8009A000 = c;
        D_8009A004 = 0x40;
        D_8009A008 = 0;
        func_8002DA7C();
        v = 0xE8;
        break;
    default:
        c = 0x2A;
        x = arg0->w48;
        D_8009A000 = c;
        D_8009A004 = 0x40;
        D_8009A008 = 0;
        func_8002DA7C();
        v = 0xE2;
        break;
    }
    D_8009A000 = c;
    D_8009A008 = v;
    do {
        x = x & 0x1FF;
        x = x >> 2;
        D_8009A004 = x;
        func_8002DA7C();
    } while (0);
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A698C);

void func_800A709C(s32 arg0, s32 arg1) {
    s16 t;
    s32 x0 = arg0 * 0x78;
    s32 x1 = arg1 * 0x78;

    D_8012C3EC = 0;
    D_8012C42C = 0;
    D_800BE8ED[x0] = 0;
    D_800BE8ED[x1] = 0;
    if (D_8012C4BC == 0) {
        t = D_8012C424;
        D_8012C41C = D_8012C424;
        if (D_800BE8C0[t].flags != 0 && D_800BE8C5[t * 0x78] == 0) {
            D_8012C428 = 0;
            if (((s16 (*)(void *))func_800B2CD8)(&D_800BE8C0[t]) != 0) {
                func_800A93A0();
                goto end;
            }
        }
    } else {
        D_8012C3E8 = 1;
        D_8012C41C = -1;
    }
    D_8012C47C = 1;
    D_8012C484 = 1;
    D_8012C480 = 1;
end:
    D_8012C4BC = 0;
}

s32 func_800A71D8(void) {
    s32 t;

    D_8012C3A0 = 0;
    D_8012C55C += D_8012C54C;
    D_8012C560 += D_8012C550;
    if (D_8012C54C == 0) {
        D_8012C554 = 0;
    } else if (D_8012C55C & 0xFF00) {
        if (D_8012C564 == 0) {
            D_8012C3A0 = 0x2000;
        } else {
            D_8012C3A0 = 0x8000;
        }
        if (D_8012C554 != 0) {
            D_8012C554 -= 1;
        } else {
            D_8012C55C = 0;
            D_8012C54C = 0;
        }
    }
    if (D_8012C550 == 0) {
        D_8012C558 = 0;
    } else if (D_8012C560 & 0xFF00) {
        if (D_8012C568 != 0) {
            D_8012C3A0 |= 0x1000;
        } else {
            D_8012C3A0 |= 0x4000;
        }
        if (D_8012C558 != 0) {
            D_8012C558 -= 1;
        } else {
            D_8012C560 = 0;
            D_8012C550 = 0;
        }
    }
    D_8012C55C = (u8)D_8012C55C;
    D_8012C560 = (u8)D_8012C560;
    func_800AB6B0(D_8012C3A0);
    t = (D_8012C554 | D_8012C558) & 0xFFFF;
    if (t == 0) {
        D_8012C3EC = 0;
    }
    return t;
}

void func_800A73AC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 dx;
    s32 dy;
    s32 t;

    dx = arg2 - arg0;
    D_8012C560 = 0;
    D_8012C55C = 0;
    D_8012C568 = 0;
    D_8012C564 = 0;
    D_8012C554 = dx;
    if (dx < 0) {
        D_8012C564 = 1;
        D_8012C554 = -dx;
    }
    dy = arg3 - arg1;
    D_8012C558 = dy;
    if (dy < 0) {
        D_8012C568 = 1;
        D_8012C558 = -dy;
    }
    if (D_8012C554 >= D_8012C558) {
        D_8012C544 = 0x100;
        t = D_8012C558 << 8;
        if (t == 0) {
            D_8012C548 = 1;
        } else {
            D_8012C548 = t / D_8012C554;
        }
        if (D_8012C548 == 0) {
            D_8012C548 = 1;
        }
    } else {
        D_8012C548 = 0x100;
        t = D_8012C554 << 8;
        if (t == 0) {
            D_8012C544 = 1;
        } else {
            D_8012C544 = t / D_8012C558;
        }
        if (D_8012C544 == 0) {
            D_8012C544 = 1;
        }
    }
    if (D_8012C564 != 0) {
        D_8012C544 = -D_8012C544;
    }
    if (D_8012C568 != 0) {
        D_8012C548 = -D_8012C548;
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A7584);

void func_800A76BC(s32 arg0) {
    u32 t;
    s32 oct;

    t = (u32)(arg0 & 0x1FF) >> 1;
    oct = arg0 & 0xE00;
    switch (oct) {
    case 0x200:
        D_8012C544 = -0x100;
        D_8012C548 = 0xFF - t;
        break;
    case 0x400:
        D_8012C544 = -0x100;
        D_8012C548 = -t;
        break;
    case 0x600:
        D_8012C544 = t - 0xFF;
        D_8012C548 = -0x100;
        break;
    case 0x800:
        D_8012C544 = t;
        D_8012C548 = -0x100;
        break;
    case 0xA00:
        D_8012C544 = 0x100;
        D_8012C548 = t - 0xFF;
        break;
    case 0xC00:
        D_8012C544 = 0x100;
        D_8012C548 = t;
        break;
    case 0xE00:
        D_8012C544 = 0xFF - t;
        D_8012C548 = 0x100;
        break;
    case 0:
        D_8012C544 = -t;
        D_8012C548 = 0x100;
        break;
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A77EC);

s16 func_800A7BF4(s16 *arg0, s16 *arg1) {
    CondorUV v;
    s32 dx;
    s32 dy;
    s32 t;
    s32 ya;
    s32 xa;
    s32 yb;

    xa = arg0[0];
    dx = arg1[0] - xa;
    D_8012C560 = 0;
    D_8012C55C = 0;
    D_8012C568 = 0;
    D_8012C564 = 0;
    D_8012C554 = dx;
    ya = arg0[1] + 0x4000;
    yb = arg1[1] + 0x4000;
    if (dx < 0) {
        D_8012C564 = 1;
        D_8012C554 = -dx;
    }
    dy = yb - ya;
    D_8012C558 = dy;
    if (dy < 0) {
        D_8012C568 = 1;
        D_8012C558 = -dy;
    }
    if (D_8012C554 >= D_8012C558) {
        D_8012C544 = 0x100;
        t = D_8012C558 << 8;
        if (t == 0) {
            D_8012C548 = 1;
        } else {
            D_8012C548 = t / D_8012C554;
        }
        if (D_8012C548 == 0) {
            D_8012C548 = 1;
        }
    } else {
        D_8012C548 = 0x100;
        t = D_8012C554 << 8;
        if (t == 0) {
            D_8012C544 = 1;
        } else {
            D_8012C544 = t / D_8012C558;
        }
        if (D_8012C544 == 0) {
            D_8012C544 = 1;
        }
    }
    if (D_8012C564 != 0) {
        D_8012C544 = -D_8012C544;
    }
    if (D_8012C568 != 0) {
        D_8012C548 = -D_8012C548;
    }
    v.z = 0;
    v.x = D_8012C544;
    v.y = D_8012C548;
    return func_800A7584(&v.x);
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A7E20);

s16 func_800A8004(void *arg0) {
    s16 i;
    s16 sx;
    s16 sy;
    u16 x;
    u16 y;
    CondorBox *e;

    e = D_8010C33C;
    i = 0;
    x = M2C_FIELD(arg0, u16 *, 0x50);
    y = M2C_FIELD(arg0, u16 *, 0x52);
    sx = x + 0x4000;
    sy = y + 0x4000;
    if (D_8012C518 > 0) {
        do {
            if (sx >= e->x0 && e->x1 >= sx && sy >= e->y0 && e->y1 >= sy && func_800A7E20(e, x, y) == 0) {
                M2C_FIELD(arg0, u16 *, 0x60) = e->ra;
                M2C_FIELD(arg0, u16 *, 0x64) = e->rb;
                return i;
            }
            i++;
            e++;
        } while (i < D_8012C518);
    }
    return -1;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A8158);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A8454);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A85DC);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A8AA8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A8D08);

s32 func_800A93A0(void) {
    if (D_8012C404 == 1) {
        return 1;
    }
    if (D_8012C41C == -1) {
        return 0;
    }
    func_800A427C();
    D_8012C3E8 = 2;
    D_8012C4E4 = 0;
    D_8012C4F8 = -8;
    D_8012C4F0 = -8;
    D_8012C4FC = 1;
    D_8012C4F4 = 1;
    if (D_80121EF0[D_8012C3F0].f > 0x50) {
        D_8012C488 = 1;
    } else {
        D_8012C488 = 3;
    }
    D_8012C47C = 2;
    D_8012C484 = 1;
    D_8012C480 = 1;
    func_800AB5BC();
    return 0;
}

s32 func_800A94B0(void) {
    CondorPos sp;

    if (D_8012C3EC != 0) {
        return 1;
    }
    if (D_8012C5CC != 0) {
        return 1;
    }
    if (D_8012C41C != -1) {
        return 1;
    }
    if (D_8012C508 >= 0x14) {
        return 1;
    }
    if (D_8012C404 == 1) {
        if (D_8012C3A6 >= 0x2A0) {
            return 1;
        }
    } else {
        if (D_8012C3A6 >= D_8012C530) {
            return 1;
        }
    }
    sp.z = -0x28;
    sp.x = D_8012C3A4;
    sp.y = 0x400 - D_8012C3A6;
    if (func_800AC5C0(0, &sp) == 1) {
        return 1;
    }
    D_8012C5C0 = 1;
    return 0;
}

void func_800A95C0(void) {
    D_8012C41C = -1;
    D_8012C524 = 0x100;
    D_8012C528 = 0;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A95E8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800A9B20);

void func_800AB5BC(void) {
    switch (D_800BE8D0[D_8012C41C].kind) {
    case 0:
        D_8012C56C = 1;
        D_8012C570 = 2;
        break;
    case 3:
    case 4:
        D_8012C56C = 2;
        D_8012C570 = 5;
        D_8012C574 = 2;
        break;
    case 1:
    case 2:
    case 5:
        D_8012C56C = 1;
        D_8012C570 = 3;
        break;
    case 6:
        D_8012C56C = 2;
        D_8012C570 = 3;
        D_8012C574 = 0;
        break;
    case 7:
    default:
        D_8012C56C = 0;
        break;
    }
}

void func_800AB6B0(s32 arg0) {
    u16 *var_a1;

    var_a1 = &D_8012C3A4;
    if (D_8012C5CC == 0) {
        var_a1 = &D_8012C3AC;
    }
    if ((D_8012C3E8 != 3) && (D_8012C3EC == 0)) {
        var_a1 = &D_8012C3A4;
    }
    func_800AB71C(arg0, var_a1);
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AB71C);

void func_800ABA58(s32 arg0) {
    s32 b;
    s32 mk;
    s32 *p1;
    s32 *p2;
    s32 *p3;
    s32 *p4;
    s32 *p5;
    s32 *p6;

    b = arg0;
    if (b & 0x1000) {
        D_8012C438--;
        if (D_8012C438 > 0x8000) {
            D_8012C438 = 0;
        } else {
            p1 = &D_8012C6F0;
            *p1 += 1;
        }
    }
    if (b & 0x4000) {
        D_8012C438++;
        if (D_8012C438 >= 0x325) {
            D_8012C438 = 0x324;
        } else {
            p2 = &D_8012C6F0;
            *p2 -= 1;
        }
    }
    if (b & 0x8000) {
        D_8012C434--;
        if (D_8012C434 > 0x8000) {
            p3 = &D_8012C6EC;
            mk = ~7;
            do {
                *p3 &= mk;
                D_8012C434 = 0;
            } while (0);
        } else {
            p4 = &D_8012C6EC;
            *p4 += 1;
        }
    }
    if (b & 0x2000) {
        D_8012C434++;
        if (D_8012C434 >= 0xC1) {
            p5 = &D_8012C6EC;
            D_8012C434 = 0xC0;
            *p5 &= ~7;
        } else {
            p6 = &D_8012C6EC;
            *p6 -= 1;
        }
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800ABC18);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800ABE54);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AC1A8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AC498);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AC5C0);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AC68C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AC72C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800ACAA4);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800ACDB0);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AD02C);

void func_800AD288(void) {
    u8 v;

    if (D_8012C56C == 0) {
        D_8012C570 = 7;
    }
    v = D_8012C570;
    if (D_8012C4E4 == 1) {
        v = D_8012C574;
    }
    if (D_8012C4E4 == 2) {
        v = D_8012C578;
    }
    switch (v) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
        break;
    case 3:
        func_800AD578(D_8012C41C);
        break;
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AD32C);

void func_800AD578(s32 arg0) {
    CondorObjA *o;

    o = (CondorObjA *)&D_800BE8C0[arg0];
    o->b03 = D_8012C57C;
    D_8012C010 = 0;
    switch (D_8012C57C) {
    case 0:
    case 1:
        func_800A1EEC(&D_8012C3AC);
        if (D_8012B85C >= 2) {
            func_800A8D08();
        }
        if (D_8012C010 != 2) {
            o->b02 = 3;
            o->b04 = 3;
            o->b40 = D_8012C420;
            func_800AD32C(o);
        }
        break;
    case 2:
        func_800A1EEC(&D_8012C3AC);
        if (D_8012B85C >= 2) {
            func_800A8D08();
        }
        if (D_8012C010 != 2) {
            o->b02 = 5;
            o->b04 = 5;
            o->b40 = D_8012C420;
            func_800AD32C(o);
        }
        break;
    case 3:
        o->b02 = 1;
        o->b04 = 1;
        o->b40 = D_8012C420;
        func_800AD32C(o);
        o->b41 = 0xFF;
        o->b2D = 0;
        o->b2E = 0;
        o->b2F = 0;
        o->b40 = 0xFF;
        o->flags &= 0xD3;
        break;
    case 4:
        o->b02 = 0;
        o->b04 = 0;
        o->w26 = 0;
        o->w28 = 0;
        o->b40 = 0xFF;
        break;
    case 5:
        o->b02 = 6;
        o->b04 = 9;
        func_800AD32C(o);
        o->b40 = 0xFF;
        break;
    case 6:
        o->b02 = 7;
        o->b04 = 0x11;
        func_800AD32C(o);
        o->b40 = 0xFF;
        break;
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AD73C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AE0D0);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AE384);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AEB90);

void func_800AEDE0(void) {
    CondorObjC *p;
    s32 v;
    u16 w;

    p = (CondorObjC *)&D_800BE8C0[D_8012C41C];
    if (D_8012C390 & 0x8000) {
        v = D_8012C468 - 0x20;
        D_8012C468 = v;
        if ((s16)v < 0) {
            D_8012C468 = 0;
        }
    }
    if (D_8012C390 & 0x2000) {
        v = D_8012C468 + 0x20;
        D_8012C468 = v;
        if ((s16)v > 0x400) {
            D_8012C468 = 0x400;
        }
    }
    w = D_8012C468 - 0x200;
    p->w34 = w;
    p->w36 = w;
    D_8012C70E = w;
    if (D_8012C39C & 0x20) {
        D_8009A000 = 0x2B;
        D_8009A004 = 0x40;
        D_8009A008 = 1;
        func_8002DA7C();
        D_8012C47C = 1;
        D_8012C484 = 1;
        D_8012C480 = 1;
        D_8012C3EC = 0;
        D_8012C42C = 0;
        p->b14 = D_8012C5DC;
        D_8012C3E8 = 1;
        D_8012C47C = 1;
        D_8012C484 = 1;
        D_8012C480 = 1;
        D_8012C41C = -1;
        D_8012C428 = 1;
    }
    if (D_8012C39C & 0x40) {
        D_8009A000 = 0x2B;
        D_8009A004 = 0x40;
        D_8009A008 = 4;
        func_8002DA7C();
        D_8012C47C = 1;
        D_8012C484 = 1;
        D_8012C480 = 1;
        D_8012C3EC = 0;
        D_8012C42C = 0;
        D_8012C3E8 = 1;
        D_8012C47C = 1;
        D_8012C484 = 1;
        D_8012C480 = 1;
        D_8012C41C = -1;
        D_8012C428 = 1;
        p->w34 = D_8012C460;
        p->w36 = D_8012C460;
    }
}

void func_800AF02C(void) {
    D_800BE8C5[D_8012C41C * 0x78] = 0xFF;
    D_8012C508 -= 1;
    func_800A2D68();
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AF08C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AF278);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AF470);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AF5A8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800AF98C);

s32 func_800AFD74(void *arg0) {
    CondorSpr *p;
    s16 i;
    u32 t;

    p = D_8011CB3C;
    for (i = 0; i < 8; i++) {
        if (p->flag == 0xFF) {
            t = M2C_FIELD(arg0, u16 *, 0x48);
            t = t & 0x1FF;
            D_8009A000 = 0x29;
            D_8009A004 = 0x40;
            D_8009A008 = 0;
            func_8002DA7C();
            D_8009A000 = 0x29;
            D_8009A008 = 0xF;
            D_8009A004 = t >> 2;
            func_8002DA7C();
            D_8011CB44[i].a = 0;
            D_8011CB3C[i].x = M2C_FIELD(arg0, u16 *, 0x50);
            D_8011CB3C[i].y = M2C_FIELD(arg0, u16 *, 0x52);
            D_8011CB40[i].f = M2C_FIELD(arg0, u16 *, 0x54);
            D_8011CB44[i].b = M2C_FIELD(arg0, u8 *, 0x12);
            D_8011CB48[i].f = M2C_FIELD(arg0, u8 *, 0x43);
            return 1;
        }
        p++;
    }
    return 0;
}

s32 func_800AFED4(arg0) {
    CondorAct2 *e = (CondorAct2 *)arg0;
    s16 r;
    s16 f;

    func_800B4720(arg0);
    switch (e->b2B) {
    case 0:
    case 1:
        e->w60 += 0x80;
        func_800AF278(e);
        break;
    case 2:
    case 3:
        e->w60 += 0x200;
        e->w52 = ((s16)e->wE >> 8) + e->w52;
        e->wE += 0x14;
        break;
    case 4:
    case 5:
        func_800B4720(e);
        func_800B4720(e);
        e->w60 = 0x200;
        if (e->b10 >= 4) {
            if (e->b43 == 4) {
                r = func_800AF278(e);
            } else {
                r = func_800AF470(e);
            }
            if (r != 0) {
                e->b10 = 2;
            }
        }
        e->b10--;
        if (e->b10 == 0) {
            e->flags = 0;
        }
        break;
    }
    switch (e->b2B) {
    case 0:
    case 1:
        e->b10--;
        if (e->b10 == 0) {
            *(u16 *)e = 0;
            e->b05 = 0;
            D_8009A000 = 0x29;
            D_8009A004 = 0x40;
            D_8009A008 = 0;
            func_8002DA7C();
        }
        break;
    case 2:
    case 3:
        f = 0;
        if (e->w28 < (s16)e->w52 + 0x200) {
            f = 1;
        } else {
            if (e->w26 == e->x) {
                e->w58 = 0;
            }
            if (e->w28 == e->y) {
                e->w5A = 0;
            }
            if ((e->w58 | e->w5A) == 0) {
                f = 1;
            }
        }
        if (f != 0) {
            e->flags = 0;
            e->b05 = 0;
            func_800AFD74(e);
        }
        break;
    }
}

s32 func_800B00F4(void) {
    s16 i;
    CondorObjB *o;
    CondorObjB *t;
    CondorObjB *u;

    if (D_8012C3E8 < 2 && D_8012C42C == 0 && D_8012C3EC != 7) {
        o = (CondorObjB *)&D_800BE8C0[0x28];
        for (i = 0x28; i < 0x46; o++, i++) {
            if (o->flags == 0) {
                continue;
            }
            o->w18 -= 1;
            if (o->w18 != 0) {
                continue;
            }
            o->w18 = o->w1A;
            if (o->w06 == 0x18) {
                func_800AFED4((CondorActor *)o);
                continue;
            }
            if (o->b2A == 7) {
                t = (CondorObjB *)&D_800BE8C0[o->b43];
                if (t->b05 != 0) {
                    o->flags = 0;
                }
                if (t->b2A != 2) {
                    o->flags = 0;
                }
            }
            if (o->w06 == 0xB && (s16)func_800A2068((CondorEnt *)o, 0x14, 0x28) != -1) {
                o->flags = 0;
                o->b05 = 0;
                func_800AFD74(o);
                u = (CondorObjB *)&D_800BE8C0[o->b41];
                if (u->flags != 0 && u->w06 == 0xD) {
                    u->w24 &= 0x7F;
                }
            }
            func_800B3644((CondorObj *)o);
            if (o->b2C == 0xFF) {
                o->flags = 0;
                o->b05 = 0;
            }
        }
    }
}

void func_800B02E0(s32 arg0, s16 arg1) {
    s32 ang;
    s32 x;
    s32 y;
    s32 quad;

    ang = arg0 & 0x3FF;
    x = (func_80039A74(ang) * arg1) >> 12;
    quad = arg0 & 0xC00;
    y = (func_80039B40(ang) * arg1) >> 12;
    switch (quad) {
    case 0:
        D_8012C544 = -x;
        D_8012C548 = y;
        break;
    case 0x400:
        D_8012C544 = -y;
        D_8012C548 = -x;
        break;
    case 0x800:
        D_8012C544 = x;
        D_8012C548 = -y;
        break;
    case 0xC00:
        D_8012C544 = y;
        D_8012C548 = x;
        break;
    default:
        D_8012C544 = x;
        D_8012C548 = y;
        break;
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B0404);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B0604);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B0D50);

void func_800B1620(void) {
    s16 sp[3];
    CondorObj *p;

    p = &D_800C0918;
    D_800BE8BC->h4 = D_800BE8BC->b3 = 0;
    D_800BE8BC->b1 = D_800BE8BC->b2 = 0;
    sp[2] = 0;
    sp[1] = 0;
    sp[0] = 0;
    D_800BE8BC->b0 = 0x1A;
    func_800AC72C(p, D_800BE8BC, 0x45, sp);
    p--;
    D_800BE8BC->b0 = 0x1B;
    func_800AC72C(p, D_800BE8BC, 0x44, sp);
    D_800C08CB = 0;
    func_800ABC18(p, 1);
    p--;
    D_800BE8BC->b0 = 0x1B;
    func_800AC72C(p, D_800BE8BC, 0x43, sp);
    D_800C0853 = 1;
    func_800ABC18(p, 2);
    D_800C0968 = 0x400;
    D_800C0960 = 0x400;
    D_800C0978 = 0;
    D_800C097A = 0;
    D_800C097C = 0;
    D_800C08F0 = 0x400;
    D_800C08E8 = 0x400;
    D_800C0900 = 0;
    D_800C0902 = 0;
    D_800C0904 = 0;
    D_800C0878 = 0x400;
    D_800C0870 = 0x400;
    D_800C0888 = 0;
    D_800C088A = 0;
    D_800C088C = 0;
}

s16 func_800B17A0(void *arg0, s32 arg1) {
    s16 sp[2];
    CondorObj *obj;
    CondorObj *p;
    s32 n;

    u16 i;

    p = D_800BFB80;
    n = 0x28;
    while (1) {
        i = n;
        if (p->flags != 0) {
            n++;
            p++;
            if (n >= 0x45) {
                i = -1;
                break;
            }
        } else {
            break;
        }
    }
    
    if (i != 0xFFFF) {
        D_800BE8BC->b0 = arg1;
        D_800BE8BC->h4 = D_800BE8BC->b3 = 0;
        D_800BE8BC->b1 = D_800BE8BC->b2 = 0;
        sp[0] = D_800BE8BC->b1;
        sp[1] = D_800BE8BC->b2;
        obj = &D_800BE8C0[i];
        func_800AC72C(obj, D_800BE8BC, i, sp);
        M2C_FIELD(obj, u16 *, 0x48) = M2C_FIELD(arg0, u16 *, 0x48);
        M2C_FIELD(obj, u16 *, 0x4A) = M2C_FIELD(arg0, u16 *, 0x4A);
        M2C_FIELD(obj, u16 *, 0x4C) = M2C_FIELD(arg0, u16 *, 0x4C);
        M2C_FIELD(obj, u16 *, 0x50) = M2C_FIELD(arg0, u16 *, 0x50);
        M2C_FIELD(obj, u16 *, 0x52) = M2C_FIELD(arg0, u16 *, 0x52);
        M2C_FIELD(obj, u16 *, 0x54) = M2C_FIELD(arg0, u16 *, 0x54);
        M2C_FIELD(obj, u16 *, 0x34) = M2C_FIELD(arg0, u16 *, 0x34);
        return i;
    }
    return -1;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B18E0);

void func_800B1FD0(CondorTri *arg0) {
    u8 padA[0x50];
    CondorSV r1;
    CondorSV r2;
    u8 padB[0x28];
    s16 x;
    s32 y;
    s16 ta;
    s16 tb;
    s16 tc;
    s32 m;

    r1.x = 0;
    r1.y = 0;
    r1.z = 0;
    r2.x = 0;
    r2.y = 0;
    r2.z = 0;
    x = arg0->x0;
    if (x & 0x8000) {
        y = (s16)x;
    } else {
        y = x;
    }
    ta = y + 0x4000;
    x = arg0->x1;
    if (x & 0x8000) {
        y = (s16)x;
    } else {
        y = x;
    }
    tb = y + 0x4000;
    x = arg0->x2;
    if (x & 0x8000) {
        y = (s16)x;
    } else {
        y = x;
    }
    tc = y + 0x4000;
    if (ta <= tb) {
        if (tc < ta) {
            m = tc;
        } else {
            m = ta;
        }
    } else {
        if (tc < tb) {
            m = tc;
        } else {
            m = tb;
        }
    }
    arg0->minx = m;
    if (ta >= tb) {
        if (ta >= tc) {
            m = ta;
        } else {
            m = tc;
        }
    } else {
        if (tb < tc) {
            m = tc;
        } else {
            m = tb;
        }
    }
    arg0->maxx = m;
    x = arg0->y0;
    if (x & 0x8000) {
        y = (s16)x;
    } else {
        y = x;
    }
    ta = y + 0x4000;
    x = arg0->y1;
    if (x & 0x8000) {
        y = (s16)x;
    } else {
        y = x;
    }
    tb = y + 0x4000;
    x = arg0->y2;
    if (x & 0x8000) {
        y = (s16)x;
    } else {
        y = x;
    }
    tc = y + 0x4000;
    if (ta <= tb) {
        if (tc < ta) {
            m = tc;
        } else {
            m = ta;
        }
    } else {
        if (tc < tb) {
            m = tc;
        } else {
            m = tb;
        }
    }
    arg0->miny = m;
    if (ta >= tb) {
        if (ta >= tc) {
            m = ta;
        } else {
            m = tc;
        }
    } else {
        if (tb < tc) {
            m = tc;
        } else {
            m = tb;
        }
    }
    arg0->maxy = m;
    arg0->w48 = 0x100;
    arg0->w4A = 0;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B21A8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B2520);

INCLUDE_RODATA("../asm/us/condor/nonmatchings/text", D_800A02EC);

void func_800B2804(void) {
    CondorBytes buf;
    u32 i;
    s32 a;
    s32 b;

    buf = D_800A02EC;
    for (i = 0; i < 0x18; i++) {
        D_8012C760[i] = buf.b[i];
    }
    func_800B2C30(4, 0x10000, 0x80180000);
    func_800B2C84(0, 0x40000, 0x801B0000);
    a = D_801B0008;
    if (a & 3) {
        a &= ~3;
        a += 4;
    }
    func_800B21A8(a + 0x801B0000, &D_8010C33C);
    b = D_801B000C;
    if (b & 3) {
        b &= ~3;
        b += 4;
    }
    func_80042D88(b + 0x801B0000, 0x801B0000, 0x40000);
}

s32 func_800B2940(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Unk80046D0C img;
    s32 ret;
    CondorRect *p;
    CondorRect *r;

    func_80046CFC((arg0 >> 2 << 2) + 0x801B0000);
    func_80046D0C(&img);
    ret = 0;
    if (img.b_arg != 0) {
        r = (CondorRect *)img.b;
        p = &D_8012AF3C;
        p->x = arg1;
        D_8012AF3C.y = arg2;
        D_8012AF3C.w = r->w;
        D_8012AF3C.h = r->h;
        func_80044000(p, (void *)img.b_arg);
        r = (CondorRect *)img.b;
        ret = r->w | (r->h << 16);
    }
    if (img.a_arg != 0) {
        r = (CondorRect *)img.a;
        p = &D_8012AF3C;
        p->x = arg3;
        D_8012AF3C.y = arg4;
        D_8012AF3C.w = r->w;
        D_8012AF3C.h = r->h;
        func_80044000(p, (void *)img.a_arg);
    }
    func_80043DD8(0);
    return ret;
}

s32 func_800B2A70(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 pad[0x18];

    func_800B2C84(1, 0x48000, 0x801B0000);
    D_8012AF3C.x = arg2;
    D_8012AF3E = arg3;
    D_8012AF40 = 0x100;
    D_8012AF42 = 1;
    func_80044000(&D_8012AF3C, (void *)0x801B0014);
    func_80043DD8(0);
    D_8012AF3C.x = arg2;
    D_8012AF3E = arg3 + 8;
    D_8012AF40 = 0x100;
    D_8012AF42 = 1;
    func_80044000(&D_8012AF3C, (void *)0x801B0014);
    func_80043DD8(0);
    D_8012AF3C.x = arg0;
    D_8012AF3E = arg1;
    D_8012AF40 = 0x100;
    D_8012AF42 = 0x200;
    func_80044000(&D_8012AF3C, (void *)0x801B0220);
    func_80043DD8(0);
    func_800B2C84(2, 0x48000, 0x801B0000);
    D_8012AF3C.x = arg0 + 0x100;
    D_8012AF3E = arg1;
    D_8012AF40 = 0x100;
    D_8012AF42 = 0x200;
    func_80044000(&D_8012AF3C, (void *)0x801B0000);
    func_80043DD8(0);
    func_800B2C84(5, 0x130000, 0x80168000);
    D_8012AF3C.x = 0;
    D_8012AF3E = 0x1F1;
    D_8012AF40 = 0x100;
    D_8012AF42 = 1;
    func_80044000(&D_8012AF3C, (void *)0x80168014);
    func_80043DD8(0);
    return 0;
}

void func_800B2C30(s32 arg0, s32 arg1, s32 arg2) {
    extern void func_800B7630();

    func_80033E34(D_800BE7D8[arg0 * 2], D_800BE7D8[arg0 * 2 + 1], arg2, func_800B7630);
    while (func_80034B44() != 0) {
    }
}

void func_800B2C84(s32 arg0, s32 arg1, s32 arg2) {
    extern void func_800B7630();

    func_80033E74(D_800BE7D8[arg0 * 2], D_800BE7D8[arg0 * 2 + 1], arg2, func_800B7630);
    while (func_80034B44() != 0) {
    }
}

s32 func_800B2CD8(void *arg0) {
    s32 v;
    s32 r;

    v = M2C_FIELD(arg0, u8 *, 0x13);
    r = 0;
    if (v != 0) {
        if (v < 3) {
            r = 1;
        } else if (v < 8) {
            if (v >= 5) {
                r = 1;
            }
        }
    }
    return r;
}

void func_800B2D18(void *arg0) {
    s32 base;
    s32 i;
    s32 n;
    u8 pad[8];

    base = D_8012C368;
    i = 0;
    n = D_8012C36C;
    if (n > 0) {
        do {
            *(u8 *)(D_8012C3F0 * 0x28 + base + 4) = M2C_FIELD(arg0, u8 *, 5);
            *(u8 *)(D_8012C3F0 * 0x28 + base + 5) = 0;
            *(u8 *)(D_8012C3F0 * 0x28 + base + 6) = 0;
            *(u8 *)(D_8012C3F0 * 0x28 + base + 0x10) = M2C_FIELD(arg0, u8 *, 5);
            *(u8 *)(D_8012C3F0 * 0x28 + base + 0x11) = 0;
            *(u8 *)(D_8012C3F0 * 0x28 + base + 0x12) = 0;
            *(u8 *)(D_8012C3F0 * 0x28 + base + 0x1C) = M2C_FIELD(arg0, u8 *, 5);
            *(u8 *)(D_8012C3F0 * 0x28 + base + 0x1D) = 0;
            i++;
            *(u8 *)(D_8012C3F0 * 0x28 + base + 0x1E) = 0;
            base += 0x68;
        } while (i < n);
    }
}

void func_800B2E78(void) {
    s32 i;
    CondorObj *p;

    p = &D_800BE8C0;
    i = 0;
    do {
        i++;
        if (p->flags != 0) {
            func_800B3644(p);
        }
        p++;
    } while (i < 0x28);
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B2ED0);

void func_800B32C0(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x1C) != 0) {
        M2C_FIELD(arg0, u16 *, 0x1C) = (u16) (M2C_FIELD(arg0, u16 *, 0x1C) - 1);
        if (M2C_FIELD(arg0, u16 *, 0x1C) == 0) {
            M2C_FIELD(arg0, u16 *, 0) = (u16) (M2C_FIELD(arg0, u16 *, 0) & 0xEF);
            if (M2C_FIELD(arg0, u8 *, 0x2A) != 2) {
                M2C_FIELD(arg0, u8 *, 0x2A) = 1U;
                func_800AC498();
            }
        }
    }
}

s32 func_800B332C(arg0) {
    s32 i;
    s32 o;
    s16 idx;
    s32 off;
    s16 a;
    s16 t;
    u16 g;
    CondorEnt *e;

    e = (CondorEnt *)arg0;
    i = 0;
    o = 0;
    g = D_8018001C;
    e->flags &= 0xBF;
    while (1) {
        if (*(s16 *)(D_8012C5FC + o) == 0) {
            idx = i;
            break;
        }
        i++;
        o += 8;
        if (i >= 0x10) {
            idx = 0xFF;
            break;
        }
    }
    if (idx != 0xFF) {
        off = idx * 8;
        *(s16 *)(D_8012C5FC + off) = -0x7FFF;
        *(u16 *)(D_8012C5FC + 2 + off) = g;
        *(u16 *)(D_8012C600 + off) = e->w48;
        *(u16 *)(D_8012C600 + 2 + off) = e->w4A;
        func_800A2798(idx, g);
    }
    D_8009A000 = 0x2B;
    D_8009A004 = 0x40;
    D_8009A008 = 1;
    func_8002DA7C();
    a = e->b10;
    t = a + g;
    a = t;
    if (t >= e->b11) {
        a = e->b11;
        e->flags &= 0xBF;
    }
    e->b10 = a;
    if (D_8012C41C != -1) {
        return func_800A427C();
    }
    return -1;
}

void func_800B3494(u16 *arg0, s32 arg1)
{
  u16 temp_s1;
  temp_s1 = *arg0;
  if (temp_s1 & 0x40)
  {
    func_800B332C();
  }
  if (!(temp_s1 & 0x50))
  {
 do { func_800B3A48(arg0, arg1); } while (0);
  }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B34F8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B3644);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B37B8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B3A48);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B3B84);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B4060);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B42AC);

void func_800B46D4(void *arg0) {
    if ((M2C_FIELD(arg0, u16 *, 0x58) | M2C_FIELD(arg0, u16 *, 0x5A)) != 0) {
        func_800B4720();
        func_800B42AC(arg0);
    }
}

void func_800B4720(arg0) {
    CondorActor *p = (CondorActor *)arg0;
    u16 d;

    d = p->vx + p->fx;
    p->fx = d;
    d >>= 8;
    if (d != 0) {
        if (d >= 0x80) {
            d |= 0xFF00;
        }
        p->x += d;
        p->x2 += d;
    }
    d = p->vy + p->fy;
    p->fy = d;
    d >>= 8;
    if (d != 0) {
        if (d >= 0x80) {
            d |= 0xFF00;
        }
        p->y += d;
        p->y2 += d;
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B47C8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B4EFC);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B5678);

void func_800B5A50(CondorObj *arg0) {
    u16 ret;
    s32 b;
    s16 r;

    ret = 0;
    switch (M2C_FIELD(arg0, u8 *, 2)) {
    case 0:
        if (M2C_FIELD(arg0, u16 *, 0x3E) != 0) {
            M2C_FIELD(arg0, u16 *, 0x3E) = M2C_FIELD(arg0, u16 *, 0x3E) - 1;
        } else {
            ret = 1;
            M2C_FIELD(arg0, u8 *, 2) = 2;
            M2C_FIELD(arg0, u8 *, 0x2A) = 2;
            M2C_FIELD(arg0, u8 *, 4) |= 2;
        }
        break;
    case 2:
        if (M2C_FIELD(arg0, u8 *, 0x2C) == 0xFF) {
            b = M2C_FIELD(arg0, u8 *, 0x2E);
            if (b == 0) {
                r = func_800B0604(arg0, 0x18);
                if (r != -1) {
                    M2C_FIELD(arg0, u8 *, 0x2E) = r;
                }
            } else if (D_800BE8C0[b].flags == 0) {
                ret = 1;
                M2C_FIELD(arg0, u8 *, 2) = 4;
                M2C_FIELD(arg0, u8 *, 0x2A) = 5;
                M2C_FIELD(arg0, u8 *, 0x2E) = 0;
                M2C_FIELD(arg0, u16 *, 0x3E) = M2C_FIELD(arg0, u8 *, 0x3C);
                M2C_FIELD(arg0, u8 *, 4) &= 0xFD;
            }
        }
        break;
    case 4:
        if (M2C_FIELD(arg0, u16 *, 0x3E) != 0) {
            M2C_FIELD(arg0, u16 *, 0x3E) = M2C_FIELD(arg0, u16 *, 0x3E) - 1;
        } else {
            ret = 1;
            M2C_FIELD(arg0, u8 *, 2) = 0;
            M2C_FIELD(arg0, u8 *, 0x2A) = 0;
            M2C_FIELD(arg0, u8 *, 0x2E) = 0;
            M2C_FIELD(arg0, u16 *, 0x3E) = M2C_FIELD(arg0, u8 *, 0x3D);
        }
        break;
    }
    if (ret != 0) {
        func_800AC498(arg0);
    }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B5BDC);

void func_800B5E38(CondorActor *p)
{
  s32 idx;
  s32 k;
  s32 r;
  s32 v;
  v = 8;
  func_800B5BDC(p);
  idx = p - ((CondorActor *) (&D_800BE8C0));
  if ((p->w26 | p->w28) != 0)
  {
    func_800B46D4(p);
  }
  k = p->kind;
  r = 0;
  if (k != 0)
  {
    if (k < 3)
    {
      r = 1;
    }
    else
      if (k < v)
    {
      if (k >= 5)
      {
        r = 1;
      }
    }
  }
  v = r;
  if (v != 0)
  {
    func_800B47C8(p, idx);
  }
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B5EF4);

s32 func_800B61F4(CondorObj *arg0) {
    CondorEnt tmp;
    CondorEnt *p;
    s16 i;
    s32 k;
    s32 a1;
    s32 a2;
    u8 e;

    tmp.w48 = M2C_FIELD(arg0, u16 *, 0x48);
    tmp.w4A = M2C_FIELD(arg0, u16 *, 0x4A);
    M2C_FIELD(&tmp, u16 *, 0x4C) = M2C_FIELD(arg0, u16 *, 0x4C);
    k = M2C_FIELD(arg0, u8 *, 0x14);
    M2C_FIELD(&tmp, u8 *, 0x23) = k;
    M2C_FIELD(&tmp, u8 *, 0x22) = k;
    p = &tmp;
    if (arg0 - D_800BE8C0 < 0x14) {
        a1 = 0x14;
        a2 = 0x28;
    } else {
        a1 = 0;
        a2 = 0x14;
    }
    func_800A224C(p, a1, a2);
    if (D_8012B85C != 0) {
        for (i = 0; i < D_8012B85C; i++) {
            e = M2C_FIELD(arg0, u8 *, 0x40);
            if (D_8012B75C[i].p == &D_800BE8C0[e]) {
                if (func_800B5EF4(arg0, e) == 1) {
                    M2C_FIELD(arg0, u8 *, 0x2A) = 2;
                    M2C_FIELD(arg0, u8 *, 4) |= 0x80;
                    M2C_FIELD(arg0, s16 *, 0x3E) = M2C_FIELD(arg0, u8 *, 0x3C);
                    func_800AC498(arg0);
                    return 1;
                }
            }
        }
    }
    M2C_FIELD(arg0, s16 *, 0x3E) = M2C_FIELD(arg0, u8 *, 0x3D);
    return 0;
}

s32 func_800B636C(CondorObj *arg0) {
    CondorEnt tmp;
    CondorEnt *p;
    s16 i;
    s32 k;
    s32 a1;
    s32 a2;
    CondorObj *q;

    tmp.w48 = M2C_FIELD(arg0, u16 *, 0x48);
    tmp.w4A = M2C_FIELD(arg0, u16 *, 0x4A);
    M2C_FIELD(&tmp, u16 *, 0x4C) = M2C_FIELD(arg0, u16 *, 0x4C);
    k = M2C_FIELD(arg0, u8 *, 0x14);
    M2C_FIELD(&tmp, u8 *, 0x23) = k;
    M2C_FIELD(&tmp, u8 *, 0x22) = k;
    p = &tmp;
    if (arg0 - D_800BE8C0 < 0x14) {
        a1 = 0x14;
        a2 = 0x28;
    } else {
        a1 = 0;
        a2 = 0x14;
    }
    func_800A224C(p, a1, a2);
    if (D_8012B85C != 0) {
        for (i = 0; i < D_8012B85C; i++) {
            q = D_8012B75C[i].p;
            if (func_800B5EF4(arg0, q - D_800BE8C0) == 1) {
                M2C_FIELD(arg0, u8 *, 0x2A) = 2;
                M2C_FIELD(arg0, u8 *, 4) |= 0x80;
                M2C_FIELD(arg0, s16 *, 0x3E) = M2C_FIELD(arg0, u8 *, 0x3C);
                func_800AC498(arg0);
                return 1;
            }
        }
    }
    M2C_FIELD(arg0, s16 *, 0x3E) = M2C_FIELD(arg0, u8 *, 0x3D);
    return 0;
}

s16 func_800B64EC(CondorActor *arg0) {
    s32 r;

    r = 0;
    if (arg0->pad02[2] & 0x80) {
        if (M2C_FIELD(arg0, u16 *, 0x3E) != 0) {
            M2C_FIELD(arg0, u16 *, 0x3E) = M2C_FIELD(arg0, u16 *, 0x3E) - 1;
        } else {
            arg0->pad02[2] &= 0x7F;
            func_800B37B8(arg0);
        }
        r++;
    } else if (arg0->pad3C[4] != 0xFF) {
        if (M2C_FIELD(arg0, u16 *, 0x3E) == 0) {
            if ((s16)func_800B61F4(arg0) == 0) {
                arg0->w26 = D_800BE908[arg0->pad3C[4]].a;
                arg0->w28 = D_800BE908[arg0->pad3C[4]].b;
                func_800B37B8(arg0);
            } else {
                r = 1;
            }
        } else {
            M2C_FIELD(arg0, u16 *, 0x3E) = M2C_FIELD(arg0, u16 *, 0x3E) - 1;
        }
    } else {
        if (M2C_FIELD(arg0, u16 *, 0x3E) != 0) {
            M2C_FIELD(arg0, u16 *, 0x3E) = M2C_FIELD(arg0, u16 *, 0x3E) - 1;
        } else if ((CondorObj *)arg0 - D_800BE8C0 >= 0x14 || arg0->pad02[0] == 0) {
            if ((s16)func_800B636C(arg0) == 1) {
                r = 1;
            }
        }
    }
    return r;
}

void func_800B6688(CondorActor *p) {
    s32 idx;
    s32 k;
    s32 r;
    s32 v;

    v = 8;
    if (func_800B64EC(p) == 0) {
        func_800B5BDC(p);
        idx = p - (CondorActor *)&D_800BE8C0;
        if ((p->w26 | p->w28) != 0) {
            func_800B46D4(p);
        }
        k = p->kind;
        r = 0;
        if (k != 0) {
            if (k < 3) {
                r = 1;
            } else if (k < v) {
                if (k >= 5) {
                    r = 1;
                }
            }
        }
        v = r;
        if (v != 0) {
            func_800B47C8(p, idx);
        }
    }
}

void func_800B6758(CondorActor *arg0) {
    s16 i;
    s16 cnt;
    CondorObj *e;

    if (arg0->pad02[2] & 4) {
        if (D_800BE8C0[arg0->pad3C[4]].flags == 0) {
            arg0->pad02[2] = 0;
            arg0->vy = 0;
            arg0->vx = 0;
            arg0->w28 = 0;
            arg0->w26 = 0;
            D_8012B85C = 0;
        }
        func_800A2068(arg0, 0, 0x13);
        cnt = 0;
        if (D_8012B85C != 0) {
            for (i = 0; i < D_8012B85C; i++) {
                e = D_8012B75C[i].p;
                if (e == &D_800BE8C0[arg0->pad3C[4]]) {
                    arg0->pad02[0] = 4;
                    arg0->vy = 0;
                    arg0->vx = 0;
                    arg0->w28 = 0;
                    arg0->w26 = 0;
                    arg0->pad02[2] &= 0xFE;
                    if (e->pad[0xE] < e->pad[0xF]) {
                        e->flags |= 0x40;
                        cnt++;
                        M2C_FIELD(arg0, s16 *, 0x18) = arg0->pad3C[0] * M2C_FIELD(arg0, u16 *, 0x1A);
                    } else {
                        arg0->pad02[2] = 0;
                    }
                }
            }
        }
        if (cnt == 0) {
            if (!(arg0->pad02[2] & 1)) {
                arg0->pad02[2] = 0;
                arg0->pad02[0] = 0;
                func_800AC498(arg0);
            }
        }
    }
}

void func_800B6900(CondorActor *p) {
    s32 idx;
    s32 k;
    s32 r;
    s32 v;

    v = 8;
    func_800B6758(p);
    func_800B5BDC(p);
    idx = p - (CondorActor *)&D_800BE8C0;
    if ((p->w26 | p->w28) != 0) {
        func_800B46D4(p);
    }
    k = p->kind;
    r = 0;
    if (k != 0) {
        if (k < 3) {
            r = 1;
        } else if (k < v) {
            if (k >= 5) {
                r = 1;
            }
        }
    }
    v = r;
    if (v != 0) {
        func_800B47C8(p, idx);
    }
}

void func_800B69C4(CondorActor *arg0) {
    s16 rr;
    s32 off;
    s32 idx;
    s32 k;
    s32 r;
    s32 v;

    if (arg0->pad02[0] == 0xA) {
        if (arg0->b2A != 6) {
            arg0->b2A = 6;
            func_800AC498();
            return;
        }
        if (arg0->pad2B[1] == 0xFF) {
            arg0->b2A = 0;
            func_800AC498(arg0);
            arg0->pad02[0] = 0;
            rr = func_800B0604(arg0, 0xB);
            if (rr != -1) {
                off = rr * 0x78;
                M2C_FIELD(arg0, s16 *, 0x24) = 0x80;
                *(s16 *)(D_800BE920 + off) = 0x180;
                *(u8 *)(D_800BE901 + off) = arg0 - (CondorActor *)&D_800BE8C0;
            }
        }
    } else {
        v = 8;
        func_800B5BDC(arg0);
        idx = arg0 - (CondorActor *)&D_800BE8C0;
        if ((arg0->w26 | arg0->w28) != 0) {
            func_800B46D4(arg0);
        }
        k = arg0->kind;
        r = 0;
        if (k != 0) {
            if (k < 3) {
                r = 1;
            } else if (k < v) {
                if (k >= 5) {
                    r = 1;
                }
            }
        }
        v = r;
        if (v != 0) {
            func_800B47C8(arg0, idx);
        }
    }
}

void func_800B6B58(void) {
    s32 a;
    s32 f;
    u8 *p;
    u8 *q;
    s32 x;

    q = D_8009C6E4;
    D_8012C448 = 0xA;
    D_8012C404 = 1;
    x = D_8009D331;
    D_8012C40C = x;
    if (x >= 7) {
        D_8012C40C = 0;
    }
    D_8012C408 = 0;
    D_8012C418 = D_8009D33B;
    D_8012C538 = D_8009D260[0];
    func_800B2520(0xA0, 0x78, 1);
    func_800B2804();
    func_800B70C8();
    a = D_8018800C;
    if (a & 3) {
        a &= ~3;
        a += 4;
    }
    D_8009A000 = 0x10;
    D_8009A004 = a + 0x80188000;
    f = 1;
    func_8002DA7C();
    do {
        func_800B6CF8(func_800A9B20(D_8012C67C, D_8012C69C));
        if (D_8012C408 >= 4) {
            f = 0;
        }
    } while (f != 0);
    func_80043DD8(0);
    func_80043D3C(0);
    p = &D_8012C50C;
    q[0xC4E] = *(u8 *)&D_8012C508;
    q[0xC53] = *p;
    q[0xC4F] = D_8012C510 - *p;
    q[0xC50] = D_8012C408 == 4;
    *(u32 *)(q + 0xB7C) = D_8012C538;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B6CF8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B70C8);

void func_800B7630(void) {
}

void func_800B7638(void) {
    s16 *p;
    s32 c;

    p = &D_8009A000;
    c = 0x40;
    *p = 0x28;
    D_8009A004 = c;
    D_8009A008 = 0;
    func_8002DA7C();
    *p = 0x29;
    D_8009A004 = c;
    D_8009A008 = 0;
    func_8002DA7C();
    *p = 0x2A;
    D_8009A004 = c;
    D_8009A008 = 0;
    func_8002DA7C();
    *p = 0x2B;
    D_8009A004 = c;
    D_8009A008 = 0;
    func_8002DA7C();
    D_8012C41C = -1;
    D_8012C42C = 1;
    D_8012C5D0 = 0;
    D_8012C4B8 = -0x20;
    if (D_80121EF0[D_8012C3F0].f > 0x50) {
        D_8012C488 = 1;
    } else {
        D_8012C488 = 3;
    }
    D_8012C47C = 2;
    D_8012C484 = 1;
    D_8012C480 = 1;
}

void func_800B779C(void) {
    s32 v;
    s32 w;
    s32 base;

    func_800B7638();
    D_8012AF58 = 7;
    if (D_8012C40C == 6) {
        base = 0x80188000;
        v = D_80188008;
        if (v & 3) {
            v &= ~3;
            v += 4;
        }
        D_8009A000 = 0x10;
        D_8009A004 = v + base;
    } else {
        w = D_80188010;
        if (w & 3) {
            w &= ~3;
            w += 4;
        }
        D_8009A000 = 0x10;
        D_8009A004 = w + 0x80188000;
    }
    func_8002DA7C();
    D_8012C3EC = 0xB;
}

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B7874);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B7AEC);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B7EC0);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B8954);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800B9668);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800BA804);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800BAC4C);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800BADD8);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800BAF80);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800BB4EC);

INCLUDE_ASM("../asm/us/condor/nonmatchings/text", func_800BDA24);

void func_800BE77C(void) {
    s32 v;

    if (D_8012C3E8 > 0 && D_8012C41C != -1) {
        v = D_800BE8CA[D_8012C41C].f;
    } else {
        v = -1;
    }
    D_8012C3FC = v;
}
