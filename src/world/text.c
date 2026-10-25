#include "common.h"
#include "world/decls.h"

void func_800A0B40(s32 arg0) {
}

void func_800A0B48(void) {
    s32 off;
    s32 v;

    D_800D05E8 = D_800D05E8 == 0;
    off = D_800D05E8 * 0x4074;
    D_800BD130 = (s32)(D_800C8564 + off);
    v = *(s32 *)(D_800CC564 + off);
    D_800D05E4 = D_800C8564 - 0x70 + off;
    D_800D05DC = v;
    D_800D05E0 = v;
    D_800C752C = D_800D05E8;
}

s32 func_800A0BD4(void) {
    return D_800D05E8;
}

u32 func_800A0BE4(s32 arg0) {
    u32 cur;
    u32 next;
    u32 ret;

    cur = D_800D05E0;
    next = arg0 * 0x28 + cur;
    if (next < D_800D05DC + 0x20800) {
        D_800D05E0 = next;
        ret = cur;
    } else {
        func_800A0B40(1);
    }
    return ret;
}

void func_800A0C54(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 (*fn)(s32, s32, s32, s32);
    s32 i;

    while (1) {
        fn = func_80033E34;
        if (arg3 != 0) {
            fn = func_80033E74;
        }
        if (fn(arg0, arg1, arg2, 0) != 0) {
            i = 0x2710;
        } else {
            for (i = 0; i < 0x2710; i++) {
                if (func_80034B44() == 0) {
                    break;
                }
                func_8003CEDC(0);
            }
        }
        if (i < 0x2710) {
            break;
        }
        func_80033B70();
    }
}

void func_800A0D1C(void) {
    D_800E55EC = 0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A0D2C);

void func_800A12AC(void) {
    s32 k;
    s32 i;
    u8 *p;

    for (k = 0; k < 2; k++) {
        for (i = 0; i < 0xD00; i++) {
            p = D_800C84F4[k].ptr + i * 0x28;
            p[3] = 9;
            p[7] = 0x34;
        }
        func_80044A68(D_800E5680[k], 0, 1, 0, 0);
    }
    func_800AE4B8();
}

void func_800A1370(void) {
    s32 t;
    s32 t2;

    func_800A0B48();
    func_8003B6DC(D_800C65EC);
    if (D_800E5630 != 0) {
        t = (((s32 (*)(void))func_800ADFC0)() >> 6) + 0x9E;
        t2 = (((s32 (*)(void))func_800ADFC0)() >> 6) - 2;
        func_8003B6BC(t, t2 + D_800E55F0);
    } else {
        func_8003B6BC(0xA0, D_800E55F0);
    }
    D_800C752D = 0xC;
    D_800C7530 = D_800BD130;
    func_80044244(D_800BD130, 0x1000);
}

void func_800A141C(s16 arg0) {
    s32 n;
    u32 i;
    u32 *p;
    u32 *base;
    WmTexAnim *e;

    n = 0x9C4;
    ((WmTag *)D_800E5680[func_800A0BD4()])->addr = ((WmTag *)D_800BD130)[n].addr;
    ((WmTag *)D_800BD130)[n].addr = (u32)D_800E5680[func_800A0BD4()];
    if (D_800E55F4 != 0) {
        ((WmTag *)func_800AE5B8())->addr = ((WmTag *)D_800BD130)[n].addr;
        ((WmTag *)D_800BD130)[n].addr = (u32)func_800AE5B8();
        ((WmTag *)func_800AE5F0())->addr = ((WmTag *)D_800BD130)[n].addr;
        ((WmTag *)D_800BD130)[n].addr = (u32)func_800AE5F0();
    }
    func_8003CEDC(1);
    e = D_800D75EC.e;
    for (i = 0; i < D_800D75EC.count; i++) {
        base = (u32 *)&D_800D75EC;
        p = (u32 *)((e->off >> 2) * 4 + (u32)&base[(e->size >> 2) * (func_8003CEDC(-1) / e->div % e->n)]);
        func_80044000(p + 1, p + 3);
        e++;
    }
    func_80043DD8(0);
    func_8003CEDC(arg0 - (arg0 == 1));
    func_80043938(1);
    func_800443B0((M2C_UNK *)D_800D05E4);
    func_800444AC((M2C_UNK *)(D_800D05E4 + 0x5C));
    func_8004433C((s32)((u32 *)D_800BD130 + n));
}

void func_800A16D0(s32 arg0) {
    D_800E5630 = arg0;
}

s32 func_800A16E0(void) {
    if (D_800E55F4 == 0) {
        return 0;
    }
    return D_800BD130 + 0x2710;
}

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A0000);

s32 func_800A1710(s32 arg0, s32 arg1) {
    s32 notE0;
    s32 flag;
    s32 b;

    notE0 = (arg0 & 0xE0) != 0xE0;
    flag = 0;
    b = arg1;
    if (func_800A9A44() == 0xD || func_800A9A44() == 0xE) {
        if (((s32 (*)(void))func_800A9174)() == (b & 0xFF)) {
            flag = 1;
        }
    }
    switch (b & 0xFF) {
    case 0:
    case 1:
    case 2:
        return ((flag ? 0x20006000 : 0x721B6F83) >> (arg0 & 0x1F)) & 1;
    case 4:
        if (func_800BC1AC() == 2) {
            return (((flag ? 0x20006000 : 0x321B6F83) >> (arg0 & 0x1F)) & 1) && notE0;
        }
        return ((flag ? 0x20006000 : 0x321B6F83) >> (arg0 & 0x1F)) & 1;
    case 0x13:
        if (func_800BC1AC() == 2) {
            return (((flag ? 0x20006000 : 0x321B6F83) >> (arg0 & 0x1F)) & 1) && notE0;
        }
        return ((flag ? 0x20006000 : D_800C6614[func_800A45F4()]) >> (arg0 & 0x1F)) & 1;
    case 3:
        if (func_800BC1AC() == 2) {
            return ((0x21B6F83 >> (arg0 & 0x1F)) & 1) && notE0;
        }
        if (D_800E5658 < 0) {
            return (arg0 & 0x1F) == 0;
        }
        break;
    case 5:
        if (func_800A98E4() != 0) {
            if (func_800BC1AC() == 2) {
                return (0x70 >> (arg0 & 0x1F)) & 1;
            }
            if (D_800E5658 < 0) {
                return (0x70 >> (arg0 & 0x1F)) & 1;
            }
            break;
        }
        if (func_800BC1AC() == 2) {
            return (0x20800 >> (arg0 & 0x1F)) & 1;
        }
        return (0x70 >> (arg0 & 0x1F)) & 1;
    case 6:
        if (func_800BC1AC() == 2) {
            return ((0x21B6F83 >> (arg0 & 0x1F)) & 1) && notE0;
        }
        return (0x331B6F13 >> (arg0 & 0x1F)) & 1;
    case 0xD:
        if (func_800BC1AC() == 2) {
            return ((0x21B6F83 >> (arg0 & 0x1F)) & 1) && notE0;
        }
        return (0x4048008 >> (arg0 & 0x1F)) & 1;
    case 8:
        return (0x4040008 >> (arg0 & 0x1F)) & 1;
    case 0x64:
        return (arg0 & 0x1F) == 7;
    }
    return 1;
}

s32 func_800A19FC(u8 *obj, s16 *pos, s32 *arg2, s16 *ioY, s32 arg4, s32 arg5, u8 kind) {
    WmTriCache *cache;
    WmTriCache *e;
    u8 *p;
    W4SVec *sp;
    s32 found;
    u8 *best;
    s32 bestDist;
    s32 y0;
    s32 h;
    s32 bestH;
    s32 d;
    s32 id;
    s32 n;

    cache = (WmTriCache *)arg2;
    sp = (W4SVec *)0x1F8003F8;
    found = 0;
    best = NULL;
    *sp = *(W4SVec *)pos;
    bestDist = 0x7FFFFFFF;
    y0 = *ioY;
    if (cache != NULL) {
        for (e = cache; e < cache + 6; e++) {
            if (found > 0) {
                goto done;
            }
            if (e->tri != NULL && *(s32 *)&e->bx == *(s32 *)(obj + 0x10)) {
                if (func_800BCECC(e->tri, sp, &h) != 0) {
                    found = -1;
                    bestH = h;
                    id = e->tri[3] | (e->tri[0xB] << 8);
                    if (func_800A1710(id, kind) != 0) {
                        best = e->tri;
                        found = 1;
                    }
                }
            }
        }
    }
    if (found == 0) {
        for (p = *(u8 **)(obj + 4); p < *(u8 **)(obj + 4) + *(s16 *)(obj + 0x14) * 12; p += 12) {
            if (func_800BCECC(p, sp, &h) != 0) {
                n = p[3] | (p[0xB] << 8);
                if (kind != 3 && kind != 5 && D_800E5634 != 2) {
                    d = h - y0;
                    if (d <= 0) {
                        d = y0 - h;
                    }
                } else {
                    d = h;
                }
                if (d < bestDist) {
                    found++;
                    best = p;
                    id = n;
                    bestDist = d;
                    bestH = h;
                }
            }
        }
        if (found != 0) {
            if (cache != NULL && best != NULL) {
                for (e = cache + 4; e >= cache; e--) {
                    e[1] = e[0];
                }
                cache->tri = best;
                cache->bx = *(s16 *)(obj + 0x10);
                cache->bz = *(s16 *)(obj + 0x12);
            }
            if (func_800A1710(id, kind) == 0) {
                best = NULL;
                found = 0;
            }
        }
    }
done:
    if (arg5 != 0) {
        *(s16 *)arg5 = id;
    }
    if (ioY != NULL) {
        *ioY = bestH;
    }
    if (arg4 != 0) {
        *(u8 **)arg4 = best;
    }
    return found > 0;
}

s32 func_800A1D04(void) {
    return D_800E5648;
}

s32 func_800A1D14(void) {
    return D_800E560C & 0xFFF;
}

void func_800A1D24(s32 arg0) {
    D_800E5608 = arg0 & 0xFFF;
}

void func_800A1D38(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFF;
    D_800E5608 = temp_a0;
    D_800E560C = temp_a0;
}

void func_800A1D54(s32 arg0) {
    D_800E5618 = arg0;
    if (arg0 == 1) {
        D_800E5638 = D_800C6638[D_800E5648];
        D_800E563C = D_800C6628[D_800E5648];
    }
}

s32 func_800A1DB0(void) {
    return D_800E5618;
}

s32 func_800A1DC0(void) {
    return D_800E5654;
}

void func_800A1DD0(s32 arg0) {
    D_800E5654 = arg0;
}

s32 func_800A1DE0(void) {
    return D_800E5634;
}

void func_800A1DF0(s32 arg0) {
    W4SVec rot;
    W4Vec pos;
    W4Vec out;
    W4Mat m1;
    W4Mat m2;
    s32 flag;

    rot.vx = func_800A3304();
    rot.vz = 0;
    rot.vy = 0;
    func_8003BF8C(&rot, &m1);
    pos.vx = pos.vy = pos.vz = 0;
    func_8003B32C(&m1, &pos);
    func_8003B48C((M2C_UNK *)&m1);
    func_8003B51C((M2C_UNK *)&m1);
    rot.vx = rot.vy = 0;
    rot.vz = D_800E5614;
    func_8003BC6C(&rot, &out, &flag);
    pos.vx = 0;
    pos.vy = 0;
    flag = out.vy * 16 - *(s32 *)&D_80116508;
    pos.vz = D_800E5614;
    func_8003B32C(&D_800E56B8, &pos);
    flag = (flag << 8) / (out.vz * 16);
    if (flag < 0) {
        flag = 0;
    } else if (flag >= 0x200) {
        flag = 0x1FF;
    }
    D_800E56D8 = rot.vx = D_800BE1E8[flag] + 0x800;
    rot.vy = arg0;
    rot.vz = 0;
    func_8003BF8C(&rot, &m1);
    rot.vx = rot.vy = 0;
    rot.vz = D_800E5654;
    func_8003BF8C(&rot, &m2);
    func_8003A79C(&m2, &m1, &D_800E5698);
}

void func_800A1FAC(s32 arg0) {
    W4Mat m;
    W4SVec v;
    W4Vec out;
    s32 flag;

    v = *(W4SVec *)arg0;
    v.vy = -D_80116508;
    func_8003B48C(&D_800E5698);
    func_8003B51C(&D_800E56B8);
    func_8003BC6C(&v, &out, &flag);
    func_8003B32C(&m, &out);
    func_8003B51C(&m);
}

void func_800A2040(void) {
    func_8003B48C(&D_800E5698);
    func_8003B51C(&D_800E56B8);
}

s16 func_800A2078(void) {
    return D_800E56D8;
}

void func_800A2088(s32 arg0) {
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = D_800E5648;
    D_800E5648 = arg0;
    D_800E5650 = temp_v0;
    if (((u32) arg0 < 2U) && (D_800E5634 != 3)) {
        D_800E5608 = 0;
    }
    var_v1 = 0xA0;
    if (D_800E5648 == 0) {
        var_v1 = 0x78;
    }
    D_800E564C = var_v1;
    D_800E5604 = -(D_800E5648 != 3) & 0x78;
}

void func_800A2108(s32 arg0, s32 arg1) {
    WQuad32 v;

    if (arg0 != 0) {
        if (arg1 == D_800E5600 || D_800E5600 == 6) {
            D_800E55FC = 1;
            func_800AA0E0(&v);
            func_800A6994(&v, arg1 != 3 || D_800E5600 == 6);
        }
    } else {
        D_800E55FC = 0;
        D_800E5600 = arg1;
    }
}

s32 func_800A21A4(void) {
    return D_800E55FC;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A21B4);

void func_800A31C0(s16 arg0) {
    s32 t;
    t = D_800E5608 - 0x800;
    D_800E5668 = arg0 + t;
}

s32 func_800A31E8(void) {
    return D_800E5628 == 0;
}

void func_800A31F8(void) {
    s32 base;

    if (D_800E5650 == 0) {
        base = 0x78 - ((D_800E5660 * 30) >> 8);
    } else {
        base = 0xA0 - ((D_800E5660 * 70) >> 8);
    }
    D_800E55F0 = base;
    D_800C65EC = 400 - ((D_800E5660 * 200) >> 8);
    D_800E5614 = 10000 - ((D_800E5660 * 6000) >> 8);
    D_800E5678 = 5000 - ((D_800E5660 * 2500) >> 8);
}

s32 func_800A32F4(void) {
    return D_800E5678;
}

s16 func_800A3304(void) {
    WQuad32 sp10;
    WQuad32 sp20;
    s32 base;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 t;
    s32 d;
    s32 w;

    if (D_800E5658 != 0) {
        if (D_800E565C == 0) {
            if (D_800E5658 > 0) {
                func_800A2088(3);
                if (((s32 (*)(void))func_800A9174)() == 3) {
                    a0 = 0xFA0;
                } else {
                    a0 = 0x7D0;
                }
                D_800E5640 = a0;
            }
            D_800C84D4 = D_800E5608;
            if (D_800E5608 >= 0x800) {
                D_800C84D4 = D_800E5608 - 0x1000;
            }
        }
        if (D_800E5660 < 0x80) {
            d = D_800E565C + D_8011650C;
        } else {
            d = -D_8011650C + D_800E565C;
        }
        D_800E565C = d;
        if (d != 0) {
            t = D_800E5660;
            t += d;
            D_800E5660 = t;
            if (t < 0) {
                D_800E5660 = 0;
            } else if (t > 0x100) {
                D_800E5660 = 0x100;
            }
            func_800A31F8();
            func_800AA0E0(&sp10);
            func_800AA170(&sp20);
            base = ((s32 (*)(void))func_800A9910)();
            if (D_800E5658 > 0) {
                w = D_800E5640;
            } else {
                w = sp20.b;
            }
            w = ((w - base) * D_800E5660) >> 8;
            func_800AA04C(base + w);
            if ((u32)D_800E5650 < 2) {
                D_800E5608 = (D_800E5660 * D_800C84D4) >> 8;
            }
        } else {
            if (D_800E5658 < 0) {
                func_800A2088(D_800E5650);
                func_800A2108(0, 2);
            }
            D_800E5658 = 0;
        }
    }
    if (D_800E5658 >= 0 || D_800E5650 != 0) {
        a1 = D_800E5648;
    } else {
        a1 = 0;
    }
    a0 = D_800E563C;
    if (a0 == 0) {
        a0 = D_800C6628[a1] + D_800E5664;
    }
    if (D_8011650C == 1) {
        w = (D_800E5610 * 7 + a0) >> 3;
    } else {
        w = (D_800E5610 * 3 + a0) >> 2;
    }
    D_800E5610 = w;
    a0 = D_800E5638;
    if (a0 == 0) {
        a0 = D_800C6638[a1];
    }
    if (D_8011650C == 1) {
        a2 = (D_800E5614 * 7 + a0) >> 3;
    } else {
        a2 = (D_800E5614 * 3 + a0) >> 2;
    }
    D_800E5614 = a2;
    return ((*(s32 *)&D_80116508 >> 5) + 0x6D6) * D_800E5660 + (0x100 - D_800E5660) * D_800E5610 >> 8;
}

void func_800A368C(s32 arg0) {
    D_800E5658 = arg0;
}

s32 func_800A369C(void) {
    return D_800E5658;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A36AC);

void func_800A38C8(void) {
    if (D_80071E34 == 1) {
        func_800260DC();
        func_80026090();
        D_80071E34 = 0;
    }
}

void func_800A3908(void) {
    s32 t;

    while ((t = func_800484A8()) == -1) {
        func_8003CEDC(0);
    }
    if (t != 0) {
        while (func_80048540(1) != 0) {
        }
    }
}

void func_800A3964(void) {
    WQuad32 q;

    switch (D_800E566C) {
    case 0:
        if (D_800E5638 != 0) {
            D_800E5638 += 0x50;
            if (D_800E5638 >= D_800C6638[D_800E5648] >> 1 && D_800E5634 != 2) {
                D_800E55F4 = 1;
            }
            if (D_800E5638 >= D_800C6638[D_800E5648]) {
                D_800E5638 = 0;
                if (D_800E563C == 0) {
                    D_800E566C = 1;
                }
            }
        }
        if (D_800E563C != 0) {
            D_800E563C += 3;
            if (D_800E563C >= D_800C6628[D_800E5648]) {
                D_800E563C = 0;
                if (D_800E5634 != 2) {
                    D_800E55F4 = 1;
                }
                if (D_800E5638 == 0) {
                    D_800E566C = 1;
                }
            }
        }
        break;
    case 2:
        if (func_800B0240() != 0) {
            func_800B7AC0(func_800A9A70());
            func_800B7480();
            func_800ADC80(3);
            func_800A38C8();
            func_800A3908();
            func_80024A3C(0);
            func_800ADD4C(3);
            func_800A2108(1, 1);
            func_800B7A40();
            func_800A12AC();
            func_800A1370();
            func_800AFFBC(0x10, 1);
            D_800E566C = 1;
        }
        break;
    case 4:
    case 5:
        func_800AA0E0(&q);
        func_800AA02C(q.b + D_800E5644);
        D_800E5644 += D_800E5644 >> 2;
        if (func_800B0240() != 0) {
            D_800E566C = (D_800E566C == 4) ? 6 : 7;
        }
        break;
    case 3:
        D_800E566C = 9;
        break;
    default:
        if (D_800E566C < 0) {
            if (++D_800E566C == 0) {
                func_80043D3C(1);
                if (D_800E5634 != 2) {
                    D_800E55F4 = 1;
                }
                D_800E566C = 1;
                func_800AFFBC(0x10, 1);
            }
        }
        break;
    }
}

void func_800A3C74(void) {
    if (D_800E566C == 1 && D_800E5634 != 2) {
        D_800C84E4 = (D_800C84E4 * 7 + (D_800BD13C << 8)) >> 3;
        D_800C84D8 = D_800C84E4 > 0x80;
        D_800C84EC = D_800C84D8 ? D_800C84EC + 1 : 0;
        if (D_800C84E0 != D_800C84D8) {
            D_800C84DC = 0;
            D_800C84E8 = 0xF;
        }
        if (func_800A9878() != 0 || D_800C84EC >= 0xF) {
            if (D_800C84E8-- < 0) {
                D_800C84DC = 1;
            }
        }
        if (D_800C84DC != 0) {
            if (D_800C84D8 != 0) {
                if (D_800E5664 >= -0x15D) {
                    D_800E5664 -= 5;
                }
            } else {
                if (D_800E5664 < 0) {
                    D_800E5664 += 5;
                }
            }
        }
        D_800C84E0 = D_800C84D8;
    }
}

void func_800A3DFC(void) {
    D_800E566C = 5;
    D_800E5644 = 0x14;
    func_800B7714(0);
    func_800A2108(0, 0);
    func_800B0098(0x10, 1);
}

void func_800A3E4C(void) {
    D_800E566C = 4;
    D_800E5644 = -0x14;
    func_800B7714(0);
    func_800A2108(0, 0);
    func_800B0098(0x10, 1);
}

void func_800A3E9C(void) {
    func_800B7714();
    D_800E566C = 8;
}

void func_800A3EC8(s32 arg0) {
    if (D_800E566C <= 0) {
        D_800E563C = 0;
        D_800E5638 = 0;
        D_800E55F4 = 1;
        D_800E566C = 1;
    }
    if (D_800E566C == 1) {
        D_800E566C = 3;
        func_800A2108(0, 0);
        func_800B7714(arg0);
    }
}

void func_800A3F4C(s32 arg0) {
    if (D_800E566C <= 0) {
        D_800E563C = 0;
        D_800E5638 = 0;
        D_800E55F4 = 1;
        D_800E566C = 1;
    }
    if ((u32) (D_800E566C - 1) < 2U) {
        if (D_80071E30 == 0) {
            D_800E566C = 3;
            func_800A2108(0, 0);
            func_800B77A8(arg0);
            return;
        }
        D_800E5670 = 0x1E;
        func_800B7C44();
    }
}

void func_800A4008(void) {
    if (D_800E566C <= 0) {
        D_800E563C = 0;
        D_800E5638 = 0;
        D_800E55F4 = 1;
        D_800E566C = 1;
    }
    if (D_800E566C == 1) {
        D_800E566C = 3;
        func_800A2108(0, 0);
        func_800B7838();
    }
}

s32 func_800A4080(void) {
    return (D_800E5648 & 3) | ((func_800BCA38() * 4) & 0xC);
}

void func_800A40B8(s32 arg0) {
    func_800A2088(arg0 & 3);
    func_800BC9E8((arg0 >> 2) & 3);
}

u8 *func_800A40F0(s16 arg0) {
    if (arg0 >= 0) {
        if (arg0 < D_800BE5F0[0]) {
            return (u8 *)D_800BE5F0 + D_800BE5F0[arg0 + 1];
        }
        return NULL;
    }
    return NULL;
}

void func_800A4138(void) {
    s32 i;
    s32 tpage;
    W4Sprt *p;

    D_800E56F4 = 0;
    p = D_800C6648;
    for (i = 0; i < 2; i++) {
        p[i].len = 4;
        p[i].code = 0x64;
        if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
            tpage = 0x29;
        } else {
            tpage = 0x19;
        }
        func_80044A68(&D_800E56DC[i], 0, 0, tpage, 0);
    }
}

void func_800A41E8(s32 arg0) {
    s32 var_s0;

    var_s0 = arg0;
    switch (var_s0) {
    case 1:
        func_800A2108(0, 4);
        func_800B0098(4, 1);
        break;
    case 4:
        func_800A2108(1, 4);
        func_800AFFBC(0x10, 1);
        var_s0 = 0;
        break;
    }
    D_800E56F4 = var_s0;
}

void func_800A4268(void) {
    s32 s;
    s32 t;

    s = func_800A0BD4();
    switch (D_800E56F4) {
    case 1:
        if (func_800B0240() != 0) {
            D_800E56F4 = 2;
        }
        break;
    case 2:
        t = func_8003CEDC(-1);
        D_800C6648[s].pad8[5] = ((t >> 2) & 0x10) - 0x80;
        ((WmTag *)&D_800C6648[s])->addr = ((WmTag *)D_800BD130)->addr;
        ((WmTag *)D_800BD130)->addr = (u32)&D_800C6648[s];
        ((WmTag *)&D_800E56DC[s])->addr = ((WmTag *)D_800BD130)->addr;
        ((WmTag *)D_800BD130)->addr = (u32)&D_800E56DC[s];
        if ((u32)(t - D_800C84F0 - 4) < 2) {
            D_800E56F4 = 3;
        }
        D_800C84F0 = t;
        break;
    case 3:
        D_800C6648[s].pad8[5] = 0xA0;
        ((WmTag *)&D_800C6648[s])->addr = ((WmTag *)D_800BD130)->addr;
        ((WmTag *)D_800BD130)->addr = (u32)&D_800C6648[s];
        ((WmTag *)&D_800E56DC[s])->addr = ((WmTag *)D_800BD130)->addr;
        ((WmTag *)D_800BD130)->addr = (u32)&D_800E56DC[s];
        break;
    }
}

void func_800A4494(s32 arg0) {
    D_800E561C = arg0;
}

void func_800A44A4(s32 arg0) {
    D_800E5620 = arg0;
}

void func_800A44B4(s32 arg0) {
    D_800E5624 = arg0;
}

void func_800A44C4(void) {
    switch (D_800E5618) {
    case 0:
        D_800E563C = 0;
        D_800E5638 = 0;
        D_800E5608 += D_800E561C;
        break;
    case 1:
        D_800E5608 += D_800E561C;
        D_800E5638 += D_800E5624;
        if (D_800E5638 > 15000) {
            D_800E5638 = 15000;
        } else if (D_800E5638 < 1000) {
            D_800E5638 = 1000;
        }
        D_800E563C += D_800E5620;
        if (D_800E563C > 0x780) {
            D_800E563C = 0x780;
        } else if (D_800E563C < 0x480) {
            D_800E563C = 0x480;
        }
        break;
    }
}

void func_800A45C4(s32 arg0) {
    D_800E5638 = arg0;
}

void func_800A45D4(s32 arg0) {
    D_800E563C = arg0;
}

void func_800A45E4(s32 arg0) {
    D_800E5674 = arg0;
}

s32 func_800A45F4(void) {
    return D_800E5674;
}

void func_800A4604(void) {
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A460C);

void func_800A4DDC() {
    s16 i;

    D_800E5714 = (u8 *)0x80156000;
    for (i = 0; i < 8; i++) {
        D_800E5718[i].next = &D_800E5718[i + 1];
    }
    D_800E5718[i].next = NULL;
    D_800E5760 = D_800E5718;
    D_800E5768 = NULL;
    D_800E5764 = NULL;
    for (i = 0; i < 19; i++) {
        D_800E576C[i].next = &D_800E576C[i + 1];
    }
    D_800E576C[i].next = NULL;
    D_800E580C = (M2C_UNK *)D_800E576C;
    D_800E5810 = NULL;
    D_800E5814 = 0;
    D_800E5818 = 0;
    D_800E581C = 0;
    D_800E5820 = -1;
    D_800E5824 = 0;
}

s16 func_800A4F08(s16 arg0, s16 arg1) {
    s16 x;
    s16 y;

    x = arg0;
    y = arg1;
    if (arg0 < 0) {
        x = arg0 + 9;
    }
    if (x >= 9) {
        x -= 9;
    }
    if (arg1 < 0) {
        y = arg1 + 7;
    }
    if (y >= 7) {
        y -= 7;
    }
    return x + y * 9;
}

void func_800A4F78(W4Pos *arg0) {
    W4Obj8 *list;
    W4Obj8 *n;
    W4Obj8 *prev;
    W4Obj8 *next;
    W3Node *a;
    W3Node *pa;
    W3Node *head;
    W3Node *next2;
    s32 x;
    s32 z;
    s32 x0;
    s32 z0;
    s32 z1;
    s32 x1;

    x0 = (arg0->x - 0x4000) / 0x8000;
    z0 = (arg0->z - 0x4000) / 0x8000;
    x1 = (arg0->x + 0x4000) / 0x8000;
    z1 = (arg0->z + 0x4000) / 0x8000;
    list = NULL;
    for (z = z0; z <= z1; z++) {
        for (x = x0; x <= x1; x++) {
            n = (W4Obj8 *)D_800E580C;
            if (n == NULL) {
                func_800A0B40(10);
            }
            next = n->next;
            n->next = list;
            list = n;
            D_800E580C = (M2C_UNK *)next;
            n->f4 = func_800A4F08(x, z);
        }
    }
    pa = NULL;
    for (a = D_800E5764; a != NULL;) {
        prev = NULL;
        for (n = list; n != NULL; n = n->next) {
            if ((s16)n->f4 == a->id) {
                break;
            }
            prev = n;
        }
        if (n != NULL) {
            if (prev != NULL) {
                prev->next = n->next;
            } else {
                list = n->next;
            }
            next = (W4Obj8 *)D_800E580C;
            D_800E580C = (M2C_UNK *)n;
            n->next = next;
            if (pa != NULL) {
                next2 = a->next;
                head = D_800E5764;
                D_800E5764 = a;
                pa->next = next2;
                a->next = head;
                a = pa->next;
                continue;
            }
        }
        pa = a;
        a = a->next;
    }
    for (a = D_800E5768; a != NULL; a = a->next) {
        prev = NULL;
        for (n = list; n != NULL; n = n->next) {
            if ((s16)n->f4 == a->id) {
                break;
            }
            prev = n;
        }
        if (n != NULL) {
            if (prev != NULL) {
                prev->next = n->next;
            } else {
                list = n->next;
            }
            next = (W4Obj8 *)D_800E580C;
            D_800E580C = (M2C_UNK *)n;
            n->next = next;
        }
    }
    for (n = list; n != NULL;) {
        n = func_800A5208(n);
    }
}

W4Obj8 *func_800A5208(W4Obj8 *arg0) {
    W3Node *p;
    W4Obj8 *next;

    p = func_800A52A4();
    if (p != NULL) {
        arg0->f6 = p - D_800E5718;
        D_800E5718[arg0->f6].id = arg0->f4;
        next = arg0->next;
        arg0->next = (W4Obj8 *)D_800E5810;
        D_800E5810 = (M2C_UNK *)arg0;
    } else {
        next = arg0->next;
        arg0->next = (W4Obj8 *)D_800E580C;
        D_800E580C = (M2C_UNK *)arg0;
    }
    return next;
}

W3Node *func_800A52A4(void) {
    W3Node *p;
    W3Node *prev;

    if (D_800E5760 != NULL) {
        p = D_800E5760;
        D_800E5760 = p->next;
    } else {
        p = D_800E5764;
        if (p != NULL) {
            prev = NULL;
            while (p->next != NULL) {
                prev = p;
                p = p->next;
            }
            if (prev != NULL) {
                prev->next = NULL;
            } else {
                p = NULL;
            }
        }
    }
    if (p != NULL) {
        p->next = (W3Node *)D_800E5768;
        D_800E5768 = (M2C_UNK *)p;
    }
    return p;
}

void func_800A5348(M2C_UNK *arg0, M2C_UNK **arg1) {
    M2C_UNK *temp_v0;

    if (arg1 != NULL) {
        *arg1 = *arg0;
    } else {
        D_800E5810 = *arg0;
    }
    func_800A54F0(arg0);
    temp_v0 = D_800E580C;
    D_800E580C = arg0;
    *arg0 = temp_v0;
}

void func_800A53A8(s32 arg0, s32 arg1) {
    W4Obj8 *p;
    W4Obj8 *prev;
    W4Obj8 *found;
    W4Obj8 *foundprev;
    s32 best;
    s32 v;
    s32 bx;
    s32 bz;
    s32 dx;
    s32 dz;
    s32 d;

    if (D_800E5814 == 0 && D_800E5810 != NULL) {
        if (func_800ADC80(0) != 0) {
            foundprev = NULL;
            found = NULL;
            best = 0x7FFF;
            prev = NULL;
            for (p = (W4Obj8 *)D_800E5810; p != NULL; p = p->next) {
                v = (s16)p->f4;
                bx = v % 4;
                bz = v / 4;
                dx = bx - (s16)arg0;
                if (dx <= 0) {
                    dx = (s16)arg0 - bx;
                }
                if (dx >= 19) {
                    dx = 36 - dx;
                }
                dz = bz - (s16)arg1;
                if (dz <= 0) {
                    dz = (s16)arg1 - bz;
                }
                if (dz >= 15) {
                    dz = 28 - dz;
                }
                d = dx + dz;
                if (d < best) {
                    best = d;
                    found = p;
                    foundprev = prev;
                }
                prev = p;
            }
            if (found == NULL) {
                func_800A0B40(0x22);
            }
            func_800A5348((M2C_UNK *)found, (M2C_UNK **)foundprev);
        }
    }
}

void func_800A54F0(W4Obj8 *arg0) {
    s32 mode;
    s32 n;
    s32 x;
    s32 y;

    mode = func_800A1DE0();
    if (mode == 0) {
        n = D_800E5824;
        D_800E581C = (n > 0 && (s16)arg0->f4 == 0x32) ? 0x3F
          : (n >= 2 && (s16)arg0->f4 == 0x29) ? 0x40
          : (n >= 2 && (s16)arg0->f4 == 0x2A) ? 0x41
          : (n >= 3 && (s16)arg0->f4 == 0x3C) ? 0x42
          : (n >= 4 && (s16)arg0->f4 == 0x2F) ? 0x43
          : (n >= 4 && (s16)arg0->f4 == 0x30) ? 0x44
          : (s16)arg0->f4;
    } else {
        D_800E581C = (s16)arg0->f4;
    }
    x = D_800E581C;
    if (mode == 2) {
        x = x / 9 - 2;
        if (x < 0) {
            x += 4;
        } else if (x >= 4) {
            x -= 4;
        }
        y = D_800E581C % 9 - 3;
        if (y < 0) {
            y += 3;
        } else if (y >= 3) {
            y -= 3;
        }
        x = x * 3 + y;
    } else if (mode == 3) {
        x = x / 9;
        if (x >= 3) {
            x -= 7;
        }
        if (x < 0) {
            x += 2;
        } else if (x >= 2) {
            x -= 2;
        }
        y = D_800E581C % 9;
        if (y >= 4) {
            y -= 9;
        }
        if (y < 0) {
            y += 2;
        } else if (y >= 2) {
            y -= 2;
        }
        x = x * 2 + y;
    }
    func_80033E34(D_800C74E4[mode][0] + x * 23, 0xB800, (s32)(D_800E5714 + arg0->f6 * 0xB800), (s32)func_800A5924);
    func_80034B44();
    D_800E5814 = D_8011650C * 5;
    D_800E5820 = arg0->f6;
}

void func_800A57C8(void) {
    W3Node *p;
    W3Node *prev;
    W3Node *head;

    if (D_800E5814 >= D_8011650C * 5) {
        func_80034B44();
    }
    if (D_800E5814 < D_8011650C * 5 && D_800E5820 >= 0) {
        prev = NULL;
        for (p = D_800E5768; p != NULL; p = p->next) {
            if (p == &D_800E5718[D_800E5820]) {
                break;
            }
            prev = p;
        }
        if (p == NULL) {
            func_800A0B40(0xB);
        }
        if (prev != NULL) {
            prev->next = p->next;
        } else {
            D_800E5768 = p->next;
        }
        head = D_800E5764;
        D_800E5764 = p;
        p->next = head;
        func_800A5B88(p);
        D_800E5820 = -1;
    }
    D_800E5814 -= (D_800E5814 != 0 && D_800E5814 < D_8011650C * 5);
}

void func_800A5924(void) {
    if (D_800E5820 >= 0) {
        D_800E5814 = (D_8011650C * 5) - 1;
        func_800ADD4C(0);
    }
}

s16 func_800A5970(void) {
    M2C_UNK *var_v1;
    s16 var_v0;

    var_v1 = D_800E5768;
    var_v0 = 0;
    if (var_v1 != NULL) {
        do {
            var_v1 = *var_v1;
            var_v0 += 1;
        } while (var_v1 != NULL);
    }
    return var_v0;
}

void func_800A59A0(void) {
    s16 i;

    for (i = 0; i < 0x3F; i++) {
        D_800E582C[i].next = &D_800E582C[i + 1];
    }
    D_800E582C[i].next = NULL;
    D_800E5A30 = D_800E582C;
    D_800E5A2C = 0;
    D_800E5A34 = 0;
}

W3Node *func_800A5A20(s16 arg0) {
    W3Node *p;
    W3Node *prev;
    W3Node *head;
    W3Node *next;

    p = D_800E5764;
    prev = NULL;
    while (p != NULL) {
        if (p->id == arg0) {
            break;
        }
        prev = p;
        p = p->next;
    }
    if (p != NULL && prev != NULL) {
        next = p->next;
        head = D_800E5764;
        D_800E5764 = p;
        prev->next = next;
        p->next = head;
    }
    return p;
}

s32 func_800A5A94(s16 arg0) {
    WmLink *p;

    p = (WmLink *)D_800E5768;
    while (p != NULL && p->id != arg0) {
        p = p->next;
    }
    return p != NULL;
}

void func_800A5AD8(W4Obj10 *arg0) {
    W4Slot *s;
    W4Slot *next;

    s = (W4Slot *)D_800E5A2C;
    while (s != NULL && s->obj->f10 != arg0->f10) {
        s = s->next;
    }
    if (s == NULL) {
        if (D_800E5A30 == NULL) {
            func_800A0B40(0x16);
        }
        s = (W4Slot *)D_800E5A30;
        next = s->next;
        s->next = (W4Slot *)D_800E5A2C;
        D_800E5A2C = (s32)s;
        s->obj = arg0;
        D_800E5A30 = (W3Slot *)next;
    }
}

void func_800A5B88(void *arg0) {
    void *var_s0;

    var_s0 = D_80109D40;
    if (var_s0 != NULL) {
        do {
            if (((((s32) (M2C_FIELD(var_s0, u16 *, 0x12) << 0x10) >> 0x12) * 9) + ((s32) (M2C_FIELD(var_s0, u16 *, 0x10) << 0x10) >> 0x12)) == M2C_FIELD(arg0, s16 *, 4)) {
                func_800A5AD8(var_s0);
            }
            var_s0 = M2C_FIELD(var_s0, void **, 0);
        } while (var_s0 != NULL);
    }
}

void func_800A5C08(u8 *src, u8 *dst) {
    s32 bits;
    s32 flags;
    u8 *base;
    u8 *end;
    u8 *q;
    u8 *lend;
    s32 lo;
    s32 hi;

    bits = 0;
    base = dst;
    end = src + *(s32 *)src + 3;
    src += 4;
    while (1) {
        if (bits == 0) {
            if (src >= end) {
                return;
            }
            flags = *src++;
            bits = 8;
        }
        if (flags & 1) {
            if (src >= end) {
                return;
            }
            *dst++ = *src++;
        } else {
            if (src >= end) {
                return;
            }
            lo = *src++;
            hi = *src++;
            lo |= (hi & 0xF0) << 4;
            q = dst - ((dst - base + (0xFEE - lo)) & 0xFFF);
            lend = dst + (hi & 0xF) + 3;
            while (q < base) {
                *dst++ = 0;
                q++;
            }
            while (dst < lend) {
                *dst++ = *q++;
            }
        }
        flags >>= 1;
        bits--;
    }
}

void func_800A5D00(W4Ent18 *arg0, W3Node *arg1) {
    u8 *blk;
    u8 *buf;
    WmBlkEnt *e;

    e = (WmBlkEnt *)arg0;
    blk = D_800E5714 + (arg1 - D_800E5718) * 0xB800;
    buf = D_800E5A38[arg0 - D_80109A38];
    func_800A5C08((u8 *)((u32 *)blk + (((u32 *)blk)[((e->bz & 3) << 2) | (e->bx & 3)] >> 2)), buf);
    e->ents = buf + 4;
    e->count = *(s16 *)buf;
    e->f8 = e->ents + e->count * 12;
    e->fC = e->f8 + ((s16 *)buf)[1] * 8;
}

void func_800A5E28(void) {
    W4Ent18 *s;
    W4Ent18 *prev;
    WmSlotB *slot;
    W3Node *n;
    WmSlotB *next;
    s32 id;
    s32 done;

    s = (W4Ent18 *)D_800E5A2C;
    if (s != NULL) {
        do {
            slot = (WmSlotB *)s;
            if (slot->blk == NULL) {
                func_800A0B40(0xC);
            }
            id = ((s16)slot->blk->bz >> 2) * 9 + ((s16)slot->blk->bx >> 2);
            for (n = D_800E5764; n != NULL; n = n->next) {
                if (n->id == id) {
                    break;
                }
            }
            if (n != NULL) {
                prev = NULL;
                func_800A5D00((W4Ent18 *)slot->blk, n);
                for (s = (W4Ent18 *)D_80109D40; s != NULL; s = s->next) {
                    if (s == (W4Ent18 *)slot->blk) {
                        break;
                    }
                    prev = s;
                }
                if (s == NULL) {
                    func_800A0B40(0x17);
                }
                if (prev != NULL) {
                    prev->next = s->next;
                } else {
                    D_80109D40 = (u8 *)s->next;
                }
                s->next = (W4Ent18 *)D_80109D3C;
                next = slot->next;
                D_80109D3C = (WmFlagNode *)s;
                slot->next = (WmSlotB *)D_800E5A30;
                D_800E5A30 = (W3Slot *)slot;
                D_800E5A2C = (s32)next;
            }
            s = (W4Ent18 *)D_800E5A2C;
            done = D_800E5A34;
        } while (s != NULL && done == 0);
    }
    D_800E5A34 = 1;
}

s32 func_800A5FB4(void) {
    W4Ent18 *p;
    W4Ent18 *prev;
    W4Slot *s;
    W4Slot *sprev;
    s32 n;

    n = 0;
    p = (W4Ent18 *)D_80109D40;
    prev = NULL;
    while (p != NULL) {
        if (M2C_FIELD(p, s16 *, 0x16)++ >= 150) {
            if (prev != NULL) {
                prev->next = p->next;
            } else {
                D_80109D40 = (u8 *)p->next;
            }
            s = (W4Slot *)D_800E5A2C;
            p->next = D_80109D38;
            sprev = NULL;
            D_80109D38 = p;
            while (s != NULL) {
                if ((W4Ent18 *)s->obj == p) {
                    break;
                }
                sprev = s;
                s = s->next;
            }
            if (s != NULL) {
                if (sprev != NULL) {
                    sprev->next = s->next;
                } else {
                    D_800E5A2C = (s32)s->next;
                }
                s->next = (W4Slot *)D_800E5A30;
                D_800E5A30 = (W3Slot *)s;
            }
            if (prev != NULL) {
                p = prev->next;
            } else {
                p = (W4Ent18 *)D_80109D40;
            }
        } else {
            prev = p;
            p = p->next;
            n++;
        }
    }
    return n;
}

void func_800A60D8(void) {
    s16 i;

    for (i = 0; i < 31; i++) {
        D_80109A38[i].next = &D_80109A38[i + 1];
    }
    D_80109A38[i].next = NULL;
    D_80109D38 = D_80109A38;
    D_80109D40 = NULL;
    D_80109D3C = NULL;
}

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A01D8);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A01E0);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A01E8);

void func_800A6168(W4Pos *pos, s16 angle, s32 (*out)[5]) {
    W4Mat m;
    W4SVec r1;
    W4SVec r2;
    W4Vec c;
    W4Vec d;
    W4Vec o1;
    W4Vec o2;
    W4Vec p1;
    W4Vec p2;
    W4Vec t;
    s32 flag;
    s16 i;
    s16 j;

    r1 = D_800A01D8;
    r2 = D_800A01E0;
    t = D_800A01E8;
    func_8003B32C(&m, &t);
    func_8003B51C((M2C_UNK *)&m);
    r2.vy = -angle + 0x380;
    func_8003BF8C(&r2, &m);
    func_8003B48C((M2C_UNK *)&m);
    func_8003BC6C(&r1, &p1, &flag);
    r2.vy = -angle - 0x380;
    func_8003BF8C(&r2, &m);
    func_8003B48C((M2C_UNK *)&m);
    func_8003BC6C(&r1, &p2, &flag);
    c.vx = (pos->x & 0x1FFF) - 0x1000;
    c.vy = 0;
    c.vz = (pos->z & 0x1FFF) - 0x1000;
    d.vy = 0;
    for (i = -2; i < 3; i++) {
        for (j = -2; j < 3; j++) {
            if ((j < 0 ? -j : j) < 2 && (i < 0 ? -i : i) < 2) {
                out[i + 2][j + 2] = 1;
            } else {
                d.vx = (j << 13) - c.vx;
                d.vz = (i << 13) - c.vz;
                func_8003BA10(&p1, &d, &o1);
                func_8003BA10(&p2, &d, &o2);
                out[i + 2][j + 2] = o1.vy < 0 && o2.vy > 0;
            }
        }
    }
}

s32 func_800A63FC(W4Blk *arg0, s16 x, s16 z, s16 *dx, s16 *dz) {
    *dx = arg0->bx - x;
    if (*dx >= 19) {
        *dx -= 36;
    } else if (*dx < -18) {
        *dx += 36;
    }
    *dz = arg0->bz - z;
    if (*dz >= 15) {
        *dz -= 28;
    } else if (*dz < -14) {
        *dz += 28;
    }
    return (*dx < 0 ? -*dx : *dx) < 3 && (*dz < 0 ? -*dz : *dz) < 3;
}

void func_800A64AC(W4Pos *pos, s16 angle) {
    s32 grid[5][5];
    s16 bx;
    s16 bz;
    s16 dx;
    s16 dz;
    u8 *p;
    s16 x;
    s16 z;
    s16 id;
    W4Obj8 *n;

    if (func_800A5FB4() < 0x10) {
        func_800A6884(pos, NULL, &bx, &bz);
        func_800A6168(pos, angle, grid);
        for (p = (u8 *)D_80109D3C; p != NULL; p = *(u8 **)p) {
            if (func_800A63FC((W4Blk *)p, bx, bz, &dx, &dz) != 0) {
                grid[dz + 2][dx + 2] = 0;
            }
        }
        for (p = D_80109D40; p != NULL; p = *(u8 **)p) {
            if (func_800A63FC((W4Blk *)p, bx, bz, &dx, &dz) != 0) {
                grid[dz + 2][dx + 2] = 0;
            }
        }
        for (dz = 0; dz < 5; dz++) {
            for (dx = 0; dx < 5; dx++) {
                if (grid[dz][dx] != 0) {
                    x = dx + bx - 2;
                    if (x < 0) {
                        x += 36;
                    } else if (x >= 36) {
                        x -= 36;
                    }
                    z = dz + bz - 2;
                    if (z < 0) {
                        z += 28;
                    } else if (z >= 28) {
                        z -= 28;
                    }
                    p = func_800A67A8();
                    if (p != NULL) {
                        id = (z >> 2) * 9 + (x >> 2);
                        M2C_FIELD(p, s16 *, 0x12) = z;
                        M2C_FIELD(p, s16 *, 0x10) = x;
                        if (func_800A5A20(id) != NULL) {
                            func_800A5AD8((W4Obj10 *)p);
                        } else if (func_800A5A94(id) == 0) {
                            if (D_800E580C == NULL) {
                                func_800A0B40(0xF);
                            }
                            n = (W4Obj8 *)D_800E580C;
                            n->f4 = id;
                            D_800E580C = (M2C_UNK *)n->next;
                            func_800A5208(n);
                        }
                    }
                }
            }
        }
    }
}

u8 *func_800A67A8(void) {
    W4Ent18 *p;
    W4Ent18 *prev;
    u8 *head;

    p = NULL;
    if (D_80109D38 != NULL) {
        p = D_80109D38;
        D_80109D38 = p->next;
    } else if (D_80109D3C != NULL) {
        p = (W4Ent18 *)D_80109D3C;
        prev = NULL;
        while (p->next != NULL) {
            prev = p;
            p = p->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        } else {
            D_80109D3C = NULL;
        }
        func_800A9064(M2C_FIELD(p, s16 *, 0x10), M2C_FIELD(p, s16 *, 0x12));
    }
    if (p != NULL) {
        head = D_80109D40;
        D_80109D40 = (u8 *)p;
        M2C_FIELD(p, s16 *, 0x16) = 0;
        p->next = (W4Ent18 *)head;
    }
    return (u8 *)p;
}

void func_800A6884(W4Pos *arg0, s16 *arg1, s16 *arg2, s16 *arg3) {
    if (arg2 != NULL) {
        *arg2 = arg0->x >> 13;
        if (*arg2 < 0) {
            *arg2 += 36;
        } else if (*arg2 >= 36) {
            *arg2 -= 36;
        }
    }
    if (arg3 != NULL) {
        *arg3 = arg0->z >> 13;
        if (*arg3 < 0) {
            *arg3 += 28;
        } else if (*arg3 >= 28) {
            *arg3 -= 28;
        }
    }
    if (arg1 != NULL) {
        arg1[0] = arg0->x & 0x1FFF;
        arg1[1] = 0;
        arg1[2] = arg0->z & 0x1FFF;
    }
}

void func_800A692C(W3Pos *arg0) {
    s32 v;
    s32 d;
    s32 v2;
    s32 d2;

    if (arg0 != NULL) {
        v = arg0->x;
        if (v > 0x47FFF) {
            d = 0xFFFB0000;
            goto set1;
        }
        if (v < 0) {
            d = 0x40000;
set1:
            arg0->x = v + (d | 0x8000);
        }
        v2 = arg0->z;
        if (v2 > 0x37FFF) {
            d2 = 0xFFFC0000;
            goto set2;
        }
        if (v2 < 0) {
            d2 = 0x30000;
set2:
            arg0->z = v2 + (d2 | 0x8000);
        }
    }
}

void func_800A6994(WQuad32 *arg0, s32 arg1) {
    s32 *p;
    s32 dx;
    s32 dz;
    s32 t;
    if (func_800A1DB0() != 2) {
        if (arg1 < 0) {
            D_800E56F8 = 0;
        } else if (D_800E5A34 != 0) {
            D_800E56F8 |= arg1;
        }
        if (D_800E56F8 != 0) {
            if (arg0->a - ((WQuad32 *)&D_80109D44)->a > 0x24000) {
                ((WQuad32 *)&D_80109D44)->a += 0x48000;
            } else if (arg0->a - ((WQuad32 *)&D_80109D44)->a < -0x24000) {
                ((WQuad32 *)&D_80109D44)->a -= 0x48000;
            }
            p = &D_80109D4C;
            if (arg0->c - *p > 0x1C000) {
                *p += 0x38000;
            } else if (arg0->c - *p < -0x1C000) {
                *p -= 0x38000;
            }
            ((WQuad32 *)&D_80109D44)->a = (((WQuad32 *)&D_80109D44)->a * 3 + arg0->a) >> 2;
            D_80109D4C = (D_80109D4C * 3 + arg0->c) >> 2;
            func_800A692C((W3Pos *)&D_80109D44);
            dx = arg0->a - ((WQuad32 *)&D_80109D44)->a;
            if (dx <= 0) {
                dx = ((WQuad32 *)&D_80109D44)->a - arg0->a;
            }
            dz = arg0->c - D_80109D4C;
            if (dz > 0) {
                t = dx + dz;
            } else {
                t = dx + (D_80109D4C - arg0->c);
            }
            D_800E56F8 = t > 10;
        } else {
            *(WQuad32 *)&D_80109D44 = *arg0;
        }
    }
}

void func_800A6B8C(WQuad32 *arg0) {
    if (arg0 != NULL) {
        *arg0 = *(WQuad32 *)&D_80109D44;
    }
}

void func_800A6BCC(s32 arg0) {
    if (arg0 != 0) {
        func_800A6884(&D_80109D44, arg0, 0, 0);
    }
}

void func_800A6C00(s32 arg0) {
    if (func_800A1DB0() != 2) {
        func_800A1FAC(arg0);
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A6C3C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A6FC0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A71E8);

s32 func_800A7E7C(void) {
    return D_80109D6C;
}

void func_800A7E8C(s32 arg0) {
    D_80109D6C = arg0;
}

void func_800A7E9C(void) {
}

void func_800A7EA4(void) {
    func_800A4DDC();
    func_800A59A0();
    func_800A60D8();
    D_80109D54 = 0;
    D_80109D58 = 0;
    D_80109D5C = 0;
    D_80109D60 = 0;
    D_800E5828 = 1;
    D_80109D64 = 0;
    D_80109D68 = 0;
    D_80109D6C = 0;
}

void func_800A7F18(void) {
    func_800A7F38();
}

void func_800A7F38() {
    W3Node *p;
    W3Node *prev;

    D_800E5828 = 0;
    if (D_800E5820 >= 0 && D_800E5814 >= D_8011650C * 5) {
        prev = NULL;
        func_8003408C();
        for (p = D_800E5768; p != NULL; p = p->next) {
            if (p == &D_800E5718[D_800E5820]) {
                break;
            }
            prev = p;
        }
        if (p == NULL) {
            func_800A0B40(0xD);
        }
        if (prev != NULL) {
            prev->next = p->next;
        } else {
            D_800E5768 = p->next;
        }
        p->next = D_800E5760;
        D_800E5760 = p;
        D_800E5814 = 0;
        D_800E5820 = -1;
    }
}

void func_800A8048(void) {
    D_800E5828 = 1;
}

s32 func_800A805C(void) {
    return D_800E5828;
}

void func_800A806C(s16 arg0, s32 arg1) {
    WQuad32 a;
    WQuad32 b;
    WQuad32 c;
    W4SVec v;
    W4Pos pos;
    s16 px;
    s16 pz;
    s32 old;
    s32 n;
    s32 m;

    func_800A90EC();
    func_800AA0E0(&a);
    func_800AA170(&c);
    if (D_800E5828 != 0) {
        v.vy = 0;
        v.vx = 0;
        v.vz = -0x2000;
        func_800AE0BC(&v, -arg0);
        pos.x = v.vx + a.a;
        pos.y = a.b;
        pos.z = v.vz + a.c;
        if (pos.x < 0) {
            pos.x += 0x48000;
        } else if (pos.x > 0x47FFF) {
            pos.x -= 0x48000;
        }
        if (pos.z < 0) {
            pos.z += 0x38000;
        } else if (pos.z > 0x37FFF) {
            pos.z -= 0x38000;
        }
        func_800A4F78(&pos);
        func_800A64AC(&a, arg0);
        func_800A6884(&pos, NULL, &px, &pz);
        func_800A53A8(px, pz);
        func_800A57C8();
        func_800A5E28();
        old = D_800E5818;
        if (func_800A5970() >= 3) {
            n = D_800E5818 + 1;
        } else {
            n = 0;
        }
        D_800E5818 = n;
        if (old < 300) {
            if (n >= 300) {
                func_800A41E8(1);
            }
        } else {
            if (n == 0) {
                func_800A41E8(4);
            }
        }
    }
    if (func_800BC1AC() == 2) {
        func_800BB8E8(0);
    } else if (D_80109D64 == 1) {
        func_800BB8E8(D_80109D68);
    }
    func_800AA0E0(&b);
    D_800BD134 = 0x157C;
    m = 0;
    if (func_800A1DE0() == 2) {
        m = 0x3E80;
    }
    D_800BD138 = m;
    if (arg1 != 0) {
        func_800A71E8(&c, &a, &b, arg0);
    }
    if (func_800A31E8() != 0) {
        func_800A7E9C();
    }
}

void func_800A82DC(void) {
    D_80109D54 = 1;
}

s32 func_800A82F0(void) {
    return D_80109D58;
}

s32 func_800A8300(s16 arg0, s16 arg1) {
    WmFlagNode *p;

    p = D_80109D3C;
    while (p != NULL) {
        if (p->f10 == arg0 && p->f12 == arg1) {
            break;
        }
        p = p->next;
    }
    return p != NULL;
}

void func_800A835C(void) {
    WQuad32 sp10;
    s32 x;
    s32 y;
    s32 k;
    s32 idx;
    s32 i;
    s32 j;
    s32 yy;
    s32 o;

    func_800AA0E0(&sp10);
    x = (sp10.a - 0x4000) >> 15;
    y = (sp10.c - 0x4000) >> 15;
    k = func_800A1DE0();
    if (k == 2) {
        x -= 3;
        y -= 2;
    }
    if (x < 0) {
        x += D_800C6670[k];
    }
    if (y < 0) {
        y += D_800C6674[k];
    }
    idx = D_800C6670[k] * y + x;
    if (k == 0) {
        if (D_800E5824 > 0) {
            if ((u32)(x - 4) < 2 && (u32)(y - 4) < 2) {
                idx = (y - 4) * 2 + x + 0x3B;
            }
        }
        if (D_800E5824 >= 2) {
            if ((u32)(x - 4) < 3 && (u32)(y - 3) < 2) {
                idx = (y - 3) * 3 + x + 0x3F;
            }
        }
        if (D_800E5824 >= 3) {
            if ((u32)(x - 5) < 2 && y >= 5) {
                idx = y * 2 + x + 0x3A;
            }
        }
        if (D_800E5824 >= 4) {
            if ((u32)(x - 1) < 3 && (u32)(y - 4) < 2) {
                idx = (y - 4) * 3 + x + 0x4C;
            }
        }
    }
    func_80033E34(D_800C74A4[k * 2] + idx * 0x5C, 0x2E000, (s32)D_800E5714, 0);
    while (func_80034B44() != 0) {
    }
    i = 0;
    D_800E5760 = D_800E5738;
    D_800E5764 = &D_800E5738[-4];
    D_800E5730 = 0;
    do {
        yy = y + i;
        j = 0;
        do {
            o = (i * 2 + j) << 3;
            if (k == 2) {
                *(s16 *)(D_800E571C + o) = (yy % 4 + 2) * 9 + (x + j) % 3 + 3;
            } else if (k == 3) {
                *(s16 *)(D_800E571C + o) = (yy & 1) * 9 + ((x + j) & 1);
            } else {
                *(s16 *)(D_800E571C + o) = (yy % 7) * 9 + (x + j) % 9;
            }
            j++;
        } while (j < 2);
        i++;
    } while (i < 2);
}

u8 *func_800A86C4(s32 arg0) {
    W4Obj8 *o;
    W4Obj8 *olast;
    W3Node *p;
    W3Node *prev;
    W3Node *head;

    if (D_800E5828 != 0) {
        func_800A0B40(0xE);
    }
    olast = NULL;
    for (o = (W4Obj8 *)D_800E5810; o != NULL; o = o->next) {
        olast = o;
    }
    if (olast != NULL) {
        olast->next = (W4Obj8 *)D_800E580C;
        D_800E580C = D_800E5810;
        D_800E5810 = NULL;
    }
    prev = NULL;
    for (p = D_800E5768; p != NULL; p = p->next) {
        prev = p;
    }
    if (prev != NULL) {
        prev->next = D_800E5760;
        D_800E5760 = D_800E5768;
        D_800E5768 = NULL;
    }
    p = D_800E5764;
    prev = NULL;
    while (p != NULL) {
        if (p >= &D_800E5718[(s16)arg0]) {
            if (prev != NULL) {
                prev->next = p->next;
            } else {
                D_800E5764 = p->next;
            }
            head = D_800E5760;
            D_800E5760 = p;
            p->next = head;
            if (prev != NULL) {
                p = prev->next;
            } else {
                p = D_800E5764;
            }
        } else {
            prev = p;
            p = p->next;
        }
    }
    return D_800E5714 + (s16)arg0 * 0xB800;
}

void func_800A886C(s32 arg0) {
    D_80109D64 = 2;
    D_80109D68 = arg0;
}

void func_800A8888(s32 arg0) {
    D_800E5824 = arg0;
}

void func_800A8898(void *arg0) {
    s32 temp_v0;
    void *temp_a1;
    void *temp_a2;
    void *temp_v1;

    temp_v0 = M2C_FIELD(D_80109D5C, s32 *, 0xC);
    temp_a2 = (M2C_FIELD(D_80109D60, u8 *, 0) * 8) + temp_v0;
    temp_a1 = (M2C_FIELD(D_80109D60, u8 *, 1) * 8) + temp_v0;
    temp_v1 = (M2C_FIELD(D_80109D60, u8 *, 2) * 8) + temp_v0;
    M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(temp_a2, s16 *, 0) + M2C_FIELD(temp_a1, s16 *, 0) + M2C_FIELD(temp_v1, s16 *, 0));
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(temp_a2, s16 *, 2) + M2C_FIELD(temp_a1, s16 *, 2) + M2C_FIELD(temp_v1, s16 *, 2));
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(temp_a2, s16 *, 4) + M2C_FIELD(temp_a1, s16 *, 4) + M2C_FIELD(temp_v1, s16 *, 4));
}

void func_800A891C(s32 *arg0) {
    s32 i;
    WmObjE0 *p;

    p = (WmObjE0 *)&D_8010AC54;
    for (i = 14 * sizeof(WmObjE0); i >= 0; i -= sizeof(WmObjE0)) {
        *(WmObjE0 **)((u8 *)D_80109F34 + i) = p;
        p--;
    }
    D_8010AC54 = NULL;
    D_8010AD34 = (M2C_UNK *)D_80109F34;
    D_8010AD40 = 0;
    D_8010AD3C = 0;
    D_8010AD38 = NULL;
    func_800A8ABC(&D_80109D74);
    func_800A8ABC((u8 *)&D_80109E54);
    D_80109E54.f50 = 9;
    ((WmObjE0 *)&D_80109D74)->next = NULL;
    D_80109E54.next = NULL;
    func_800AA8D8(0, 0, 0);
    D_8010AD50 = arg0;
    D_8010AD58 = 0;
    D_8010AD54 = 0;
    D_8010AD64 = 0;
    D_8010AD60 = 0;
    D_8010AD5C = 0;
}

u8 *func_800A8A1C(void) {
    void **p;
    void *next;
    void *cur;

    p = (void **)D_8010AD34;
    if (p == NULL) {
        func_800A0B40(0x32);
    }
    next = *p;
    cur = D_8010AD38;
    D_8010AD3C = (s32)p;
    D_8010AD38 = (u8 *)p;
    D_8010AD34 = next;
    *p = cur;
    func_800A8ABC((u8 *)p);
    return (u8 *)p;
}

void func_800A8A88(void) {
    void *var_v0;

    var_v0 = D_8010AD38;
    if (var_v0 != NULL) {
        do {
            M2C_FIELD(var_v0, s8 *, 0x5E) = -1;
            var_v0 = M2C_FIELD(var_v0, void **, 0);
        } while (var_v0 != NULL);
    }
}

void func_800A8ABC(u8 *arg0) {
    s32 *p;
    u8 *end;

    M2C_FIELD(arg0, s8 *, 0x5E) = -1;
    p = (s32 *)(arg0 + 4);
    end = arg0 + 0xE0;
    while ((u8 *)p < end) {
        *p = 0;
        p++;
    }
}

void func_800A8AF4(M2C_UNK *arg0) {
    M2C_UNK *temp_v0;

    func_800A8B30();
    temp_v0 = D_8010AD34;
    D_8010AD34 = arg0;
    *arg0 = temp_v0;
}

void func_800A8B30(arg0) {
    WmObj *obj;
    WmObj *p;
    WmObj *prev;
    WmHdr3 *h;

    obj = (WmObj *)arg0;
    if ((s32)obj == D_8010AD3C) {
        D_8010AD3C = 0;
    }
    if ((s32)obj == D_8010AD40) {
        D_8010AD40 = 0;
    }
    for (p = (WmObj *)D_8010AD38; p != NULL; p = *(WmObj **)p) {
        if (p->link == obj) {
            p->link = NULL;
        }
        if (p->child == obj) {
            p->child = NULL;
        }
    }
    prev = NULL;
    for (p = (WmObj *)D_8010AD38; p != NULL; p = *(WmObj **)p) {
        if (p == obj) {
            break;
        }
        prev = p;
    }
    if (p != NULL) {
        if (prev != NULL) {
            *(WmObj **)prev = *(WmObj **)p;
        } else {
            D_8010AD38 = *(u8 **)p;
        }
        if (p != NULL) {
            *(WmObj **)p = NULL;
        }
    }
    h = func_800B6EFC(obj->pad4E[2]);
    if (h != NULL && (s8)h->pad0[1] == 0xC) {
        func_800B5DD8((WmHdr *)h);
        ((s8 *)obj)[0x5E] = -1;
    }
}

void func_800A8C70(u8 **arg0) {
    u8 *temp_v0;

    if ((arg0 != NULL) && (*arg0 == NULL)) {
        temp_v0 = D_8010AD38;
        D_8010AD38 = (u8 *)arg0;
        *arg0 = temp_v0;
    }
}

s32 func_800A8CA4(void) {
    u8 *var_v1;

    var_v1 = D_8010AD38;
    if (var_v1 != NULL) {
loop_1:
        if ((u8) M2C_FIELD(var_v1, u8 *, 0x50) < 0x20U) {
            var_v1 = M2C_FIELD(var_v1, u8 **, 0);
            if (var_v1 != NULL) {
                goto loop_1;
            }
        }
    }
    return var_v1 != NULL;
}

void func_800A8CE4(void) {
    s32 temp_s0;

    temp_s0 = D_8010AD40;
    if ((temp_s0 != 0) && (D_8010AD3C != 0) && (M2C_FIELD(D_8010AD3C, s32 *, 8) == 0)) {
        func_800A8B30(temp_s0);
        M2C_FIELD(D_8010AD3C, s32 *, 8) = temp_s0;
        D_8010AD40 = D_8010AD3C;
    }
}

void func_800A8D58(void) {
    WmObj *e;
    WmObj *old;

    if (D_8010AD40 != 0) {
        e = ((WmObj *)D_8010AD40)->child;
        if (e != NULL) {
            func_800A8C70((u8 **)e);
            e->link = (WmObj *)D_8010AD40;
            e->a = ((WmObj *)D_8010AD40)->a;
            e->b = ((WmObj *)D_8010AD40)->b;
            e->f40 = ((WmObj *)D_8010AD40)->f40;
            e->f4C = ((WmObj *)D_8010AD40)->f4C;
            e->f3C = ((WmObj *)D_8010AD40)->f3C;
            e->f3E = ((WmObj *)D_8010AD40)->f3E;
            e->f51 |= 2;
            old = (WmObj *)D_8010AD40;
            D_8010AD40 = (s32)e;
            old->child = NULL;
        }
    }
}

void func_800A8E50(void) {
    WmObj *e;
    WmObj *old;

    if (D_8010AD3C != 0) {
        e = ((WmObj *)D_8010AD3C)->child;
        if (e != NULL) {
            func_800A8C70((u8 **)e);
            e->link = (WmObj *)D_8010AD3C;
            e->a = ((WmObj *)D_8010AD3C)->a;
            e->b = ((WmObj *)D_8010AD3C)->b;
            e->f40 = ((WmObj *)D_8010AD3C)->f40;
            e->f4C = ((WmObj *)D_8010AD3C)->f4C;
            e->f3C = ((WmObj *)D_8010AD3C)->f3C;
            e->f3E = ((WmObj *)D_8010AD3C)->f3E;
            e->f51 |= 2;
            old = (WmObj *)D_8010AD3C;
            D_8010AD3C = (s32)e;
            old->child = NULL;
        }
    }
}

s32 func_800A8F48(void) {
    if (D_8010AD3C == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD3C, s32 *, 8) != 0;
}

void func_800A8F74(void) {
    if (D_8010AD40 != 0) {
        func_800A8AF4(D_8010AD40);
    }
}

void func_800A8FA0(void) {
    if (D_8010AD3C != 0) {
        func_800A8AF4(D_8010AD3C);
    }
}

void func_800A8FCC(void) {
    s32 *temp_a0;

    if (D_8010AD40 != 0) {
        temp_a0 = M2C_FIELD(D_8010AD40, s32 **, 8);
        if (temp_a0 != NULL) {
            func_800A8AF4(temp_a0);
            M2C_FIELD(D_8010AD40, s32 **, 8) = NULL;
        }
    }
}

void func_800A9018(void) {
    s32 *temp_a0;

    if (D_8010AD3C != 0) {
        temp_a0 = M2C_FIELD(D_8010AD3C, s32 **, 8);
        if (temp_a0 != NULL) {
            func_800A8AF4(temp_a0);
            M2C_FIELD(D_8010AD3C, s32 **, 8) = NULL;
        }
    }
}

void func_800A9064(s16 arg0, s16 arg1) {
    W4Obj *p;
    W4Trig *t;

    for (p = (W4Obj *)D_8010AD38; p != NULL; p = p->next) {
        for (t = p->trig; t < &p->trig[6]; t++) {
            if (t->a == arg0 && t->b == arg1) {
                t->f0 = 0;
            }
        }
    }
}

void func_800A90EC(void) {
    if (D_8010AD40 != 0) {
        D_8010AD3C = D_8010AD40;
    }
}

void func_800A9110(void) {
    if (D_8010AD3C != 0) {
        D_8010AD40 = D_8010AD3C;
    }
}

s32 func_800A9134(void) {
    s32 var_v0;

    var_v0 = 0;
    if (D_8010AD40 != 0) {
        var_v0 = D_8010AD40 + 0x60;
    }
    return var_v0;
}

u8 func_800A9154(void) {
    u8 var_v0;

    var_v0 = 0;
    if (D_8010AD3C != 0) {
        var_v0 = M2C_FIELD(D_8010AD3C, u8 *, 0x50);
    }
    return var_v0;
}

u8 func_800A9174(void) {
    u8 var_v0;

    var_v0 = 0;
    if (D_8010AD40 != 0) {
        var_v0 = M2C_FIELD(D_8010AD40, u8 *, 0x50);
    }
    return var_v0;
}

s32 func_800A9194(void) {
    return D_8010AD3C;
}

s32 func_800A91A4(s32 arg0) {
    u8 temp_v1;

    if (D_8010AD40 != 0) {
        temp_v1 = M2C_FIELD(D_8010AD40, u8 *, 0x50);
        if (temp_v1 < 0x20U) {
            return (arg0 >> temp_v1) & 1;
        }
    }
    return 0;
}

s32 func_800A91E0(s32 arg0) {
    u8 temp_v1;

    if (D_8010AD3C != 0) {
        temp_v1 = M2C_FIELD(D_8010AD3C, u8 *, 0x50);
        if (temp_v1 < 0x20U) {
            return (arg0 >> temp_v1) & 1;
        }
    }
    return 0;
}

s32 func_800A921C(s32 arg0, u8 arg1) {
    if (arg1 >= 0x20U) {
        return 0;
    }
    return (arg0 >> arg1) & 1;
}

s32 func_800A9240(void) {
    s32 var_a1;
    u8 temp_a0;

    if (D_8010AD40 != 0) {
        temp_a0 = M2C_FIELD(D_8010AD40, u8 *, 0x50);
        var_a1 = 0;
        if ((temp_a0 == 4) || (temp_a0 == 0x13) || ((u32) (M2C_FIELD(D_8010AD40, u8 *, 0x50) - 0x29) < 2U)) {
            var_a1 = 1;
        }
    } else {
        var_a1 = 0;
    }
    return var_a1;
}

s32 func_800A929C(void) {
    s32 var_a1;
    u8 temp_a0;

    if (D_8010AD3C != 0) {
        temp_a0 = M2C_FIELD(D_8010AD3C, u8 *, 0x50);
        var_a1 = 0;
        if ((temp_a0 == 4) || (temp_a0 == 0x13) || ((u32) (M2C_FIELD(D_8010AD3C, u8 *, 0x50) - 0x29) < 2U)) {
            var_a1 = 1;
        }
    } else {
        var_a1 = 0;
    }
    return var_a1;
}

s32 func_800A92F8(s32 arg0) {
    s32 temp_v1;
    s32 var_a1;

    temp_v1 = arg0 & 0xFF;
    var_a1 = 0;
    if ((temp_v1 == 4) || (temp_v1 == 0x13) || ((u32) ((arg0 - 0x29) & 0xFF) < 2U)) {
        var_a1 = 1;
    }
    return var_a1;
}

void func_800A9334(s32 arg0) {
    WmRect r;

    if (D_8010AD3C != 0) {
        ((WmObjFt *)D_8010AD3C)->f50 = arg0;
        switch (arg0) {
        case 3:
            if (func_800B716C() == 0) {
                ((WmObjFt *)D_8010AD3C)->f8 = &D_80109E54;
            }
            r.x = 0x18;
            r.y = 0x48;
            r.w = 0xE;
            r.h = 0x1F;
            break;
        case 10:
            r.x = 0x90;
            r.y = 0;
            r.w = 0xF;
            r.h = 0xF;
            ((WmObjFt *)D_8010AD3C)->f58 = 0x80;
            break;
        case 11:
            r.x = 0;
            r.y = 0x38;
            r.w = 0x17;
            r.h = 0x2F;
            ((WmObjFt *)D_8010AD3C)->f58 = 0x20;
            break;
        case 5:
        case 13:
        case 28:
            break;
        case 4:
            func_800B624C(4, 0);
        default:
            r.x = 0x18;
            r.y = 0x38;
            r.w = 0xF;
            r.h = 0xF;
            ((WmObjFt *)D_8010AD3C)->f58 = 0x20;
            break;
        }
        func_800B58F8(((WmObjFt *)D_8010AD3C)->ft, &r);
        func_800ADA64((WmActor *)D_8010AD3C);
    }
}

void func_800A9480(s16 arg0) {
    if (D_8010AD3C != 0) {
        M2C_FIELD(D_8010AD3C, s16 *, 0x40) = arg0;
        M2C_FIELD(D_8010AD3C, s16 *, 0x4C) = arg0;
        M2C_FIELD(D_8010AD3C, s16 *, 0x3E) = 0;
    }
}

void func_800A94A8(s16 arg0) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s16 *, 0x40) = arg0;
        M2C_FIELD(D_8010AD40, s16 *, 0x4C) = arg0;
        M2C_FIELD(D_8010AD40, s16 *, 0x3E) = 0;
    }
}

void func_800A94D0(s16 arg0) {
    if (D_8010AD3C != 0) {
        M2C_FIELD(D_8010AD3C, s16 *, 0x40) = arg0;
        M2C_FIELD(D_8010AD3C, s16 *, 0x4C) = arg0;
    }
}

void func_800A94F4(s16 arg0) {
    if (D_8010AD3C != 0) {
        M2C_FIELD(D_8010AD3C, s16 *, 0x40) = arg0;
        M2C_FIELD(D_8010AD3C, s16 *, 0x3C) = arg0;
        M2C_FIELD(D_8010AD3C, s16 *, 0x4C) = arg0;
        M2C_FIELD(D_8010AD3C, s16 *, 0x3E) = 0;
    }
}

void func_800A9520(s32 arg0, s32 arg1) {
    WmActor *obj;
    s16 a;
    s16 d1;
    s16 d2;
    s16 d3;
    s16 t;

    obj = (WmActor *)arg0;
    a = arg1;
    if (obj != NULL) {
        if (a < 0) {
            a += 0x1000;
        }
        d1 = (obj->f3C - a) > 0 ? (obj->f3C - a) : -(obj->f3C - a);
        d2 = (obj->f3C - a + 0x1000) > 0 ? (obj->f3C - a + 0x1000) : -(obj->f3C - a + 0x1000);
        d3 = (obj->f3C - a - 0x1000) > 0 ? (obj->f3C - a - 0x1000) : -(obj->f3C - a - 0x1000);
        if (d1 > d2) {
            if (d2 > d3) {
                a += 0x1000;
            } else {
                a -= 0x1000;
            }
        } else if (d1 > d3) {
            a += 0x1000;
        }
        if (D_8011650C == 1) {
            t = (obj->f3C * 7 + a) >> 3;
        } else {
            t = (obj->f3C * 3 + a) >> 2;
        }
        obj->f3C = t;
        if (t < 0) {
            obj->f3C = t + 0x1000;
        } else if (t >= 0x1000) {
            obj->f3C = t - 0x1000;
        }
    }
}

void func_800A9678(s16 arg0) {
    func_800A9520(D_8010AD3C, arg0);
}

void func_800A96A4(s16 arg0) {
    func_800A9520(D_8010AD40, arg0);
}

void func_800A96D0(s16 arg0) {
    u8 *p;
    u32 v;

    if (D_8010AD3C != 0) {
        p = (u8 *)D_8010AD3C;
        if (D_8011650C == 1) {
            if (p[0x51] & 1) {
                v = (u32)(*(s16 *)(p + 0x3E) * 15 + arg0) >> 4;
            } else {
                v = (u32)(*(s16 *)(p + 0x3E) * 3 + arg0) >> 2;
            }
        } else if (p[0x51] & 1) {
            v = (u32)(*(s16 *)(p + 0x3E) * 7 + arg0) >> 3;
        } else {
            v = (u32)(*(s16 *)(p + 0x3E) + arg0) >> 1;
        }
        *(s16 *)(p + 0x3E) = v;
    }
}

s16 func_800A97A8(void) {
    if (D_8010AD3C == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD3C, u16 *, 0x3C) + M2C_FIELD(D_8010AD3C, u16 *, 0x3E);
}

s16 func_800A97E4(void) {
    if (D_8010AD40 == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD40, u16 *, 0x3C) + M2C_FIELD(D_8010AD40, u16 *, 0x3E);
}

void func_800A9820(s32 arg0) {
    if (D_8010AD3C != 0) {
        M2C_FIELD(D_8010AD3C, s32 *, 0x10) = (s32) (arg0 + M2C_FIELD(D_8010AD3C, s32 *, 0x10));
    }
}

s32 func_800A984C(void) {
    if (D_8010AD3C == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD3C, u8 *, 0x51) & 1;
}

s32 func_800A9878(void) {
    if (D_8010AD40 == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD40, u8 *, 0x51) & 1;
}

void func_800A98A4(s32 arg0) {
    u8 *p;
    u8 v;

    p = (u8 *)D_8010AD40;
    if (p != 0) {
        if (arg0 != 0) {
            v = p[0x51] | 0x80;
        } else {
            v = p[0x51] & 0x7F;
        }
        p[0x51] = v;
    }
}

u32 func_800A98E4(void) {
    if (D_8010AD40 == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD40, u8 *, 0x51) >> 7;
}

s16 func_800A9910(void) {
    if (D_8010AD40 == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD40, s16 *, 0x42);
}

s32 func_800A993C(s32 arg0) {
    u8 *var_v1;

    var_v1 = D_8010AD38;
    if (var_v1 != NULL) {
loop_1:
        if (M2C_FIELD(var_v1, u8 *, 0x50) != arg0) {
            var_v1 = M2C_FIELD(var_v1, u8 **, 0);
            if (var_v1 != NULL) {
                goto loop_1;
            }
        }
        if (var_v1 != NULL) {
            D_8010AD3C = (s32) var_v1;
        }
    }
    return var_v1 != NULL;
}

void func_800A9988(void) {
    s32 temp_v0;

    if (D_8010AD40 != 0) {
        temp_v0 = M2C_FIELD(D_8010AD40, s32 *, 4);
        if (temp_v0 != 0) {
            D_8010AD3C = temp_v0;
        }
    }
}

s32 func_800A99BC(void) {
    s32 a;
    s32 b;
    s32 r;
    s32 t;

    r = 0;
    a = D_8010AD40;
    if (a != 0) {
        b = D_8010AD3C;
        if (b != 0 && a != b) {
            t = ((u8 *)b)[0x51] & 0x10;
            r = t == 0;
        }
    }
    return r;
}

void func_800A9A04(s8 arg0) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s8 *, 0x50) = arg0;
    }
}

void func_800A9A24(s16 arg0) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s16 *, 0x4A) = arg0;
    }
}

s32 func_800A9A44(void) {
    if (D_8010AD40 == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD40, u16 *, 0x4A) & 0x1F;
}

s32 func_800A9A70(void) {
    if (D_8010AD40 == 0) {
        return 0;
    }
    return (M2C_FIELD(D_8010AD40, u16 *, 0x4A) >> 9) & 0x1F;
}

u32 func_800A9AA4(void) {
    if (D_8010AD40 == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD40, u16 *, 0x4A) >> 0xF;
}

s32 func_800A9AD0(void) {
    if (D_8010AD40 == 0) {
        return 0;
    }
    return (M2C_FIELD(D_8010AD40, volatile u16 *, 0x4A) >> 5) & 7;
}

s32 func_800A9B04(s16 arg0, u8 arg1) {
    s32 t;
    s32 lim;

    t = arg0 & 0x1F;
    switch (arg1) {
    case 0xD:
        return -0xF0;
    case 8:
        return -0xF;
    case 0x19:
        return 0;
    case 0x13:
        if ((t >= 3 && t <= 6) || t == 0x1A) {
            if (((WmObjQ *)D_8010AD40)->f51 & 1) {
                if (D_8010AD64 >= 0) {
                    return D_8010AD64;
                }
                D_8010AD64 += 0x14;
                if (D_8010AD64 > 0) {
                    D_8010AD64 = 0;
                }
            } else {
                if (t == 4 || t == 6) {
                    t = -0x32;
                } else {
                    t = -0xFA;
                }
                if (t < D_8010AD64) {
                    D_8010AD64 -= 0xA;
                } else if (D_8010AD64 < t - 0x14) {
                    D_8010AD64 = t;
                }
            }
            return D_8010AD64;
        }
        D_8010AD64 = 0;
        break;
    }
    if (t != 1 && t != 0x19) {
        if (t == 4 || t == 7) {
            return -0x40;
        }
        return 0;
    }
    return -0xC0;
}

void func_800A9C64(s32 arg0, s32 arg1) {
    WmObjQ *obj;
    WQuad32 *pos;

    obj = (WmObjQ *)arg0;
    pos = (WQuad32 *)arg1;
    if (pos != NULL && obj != NULL) {
        func_800A692C((W3Pos *)pos);
        if (obj->f51 & 0x80) {
            obj->a.a = pos->a;
            obj->a.c = pos->c;
        } else {
            obj->a = *pos;
            obj->a.b += func_800A9B04(obj->f4A, obj->f50);
        }
        obj->f42 = pos->b;
        if (obj->a.a != obj->b.a || obj->a.c != obj->b.c) {
            obj->f51 |= 1;
        } else {
            obj->f51 &= ~1;
        }
    }
}

void func_800A9D5C(s32 arg0) {
    func_800A9C64(D_8010AD3C, arg0);
}

void func_800A9D88(s32 arg0) {
    func_800A9C64(D_8010AD40, arg0);
}

void func_800A9DB4(s32 arg0) {
    func_800A9C64(D_8010AD40, arg0);
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s32 *, 0x1C) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0xC);
        M2C_FIELD(D_8010AD40, s32 *, 0x20) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x10);
        M2C_FIELD(D_8010AD40, s32 *, 0x24) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x14);
        M2C_FIELD(D_8010AD40, s32 *, 0x28) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x18);
    }
}

void func_800A9E14(s32 arg0) {
    s32 m;
    s32 d;
    s32 lt;
    s32 t;

    m = func_800A9A44();
    func_800A9C64(D_8010AD40, arg0);
    if (m == 1 || m == 25) {
        D_8010AD60 = 30;
    } else if (m == 2 || m == 12) {
        D_8010AD60 = 0;
    }
    if (!(((WmObjQ *)D_8010AD40)->f51 & 0x80) && D_8010AD60 != 0) {
        D_8010AD60 -= ((WmObjQ *)D_8010AD40)->f51 & 1;
        if (D_8010AD5C != 0) {
            lt = ((WmObjQ *)D_8010AD40)->a.b > ((WmObjQ *)D_8010AD40)->b.b;
            if (D_8010AD5C > 0 ? (t = lt ^ 1) : lt) {
                D_8010AD5C = 0;
                ((WmObjQ *)D_8010AD40)->a.b = ((WmObjQ *)D_8010AD40)->b.b;
            } else if (((WmObjQ *)D_8010AD40)->f51 & 1) {
                if (((WmObjQ *)D_8010AD40)->a.b > ((WmObjQ *)D_8010AD40)->b.b) {
                    if (D_8010AD5C < ((WmObjQ *)D_8010AD40)->a.b - ((WmObjQ *)D_8010AD40)->b.b) {
                        ((WmObjQ *)D_8010AD40)->a.b = ((WmObjQ *)D_8010AD40)->b.b + D_8010AD5C;
                        D_8010AD5C *= 2;
                    } else {
                        D_8010AD5C = 0;
                    }
                } else {
                    if (((WmObjQ *)D_8010AD40)->a.b - ((WmObjQ *)D_8010AD40)->b.b < D_8010AD5C) {
                        ((WmObjQ *)D_8010AD40)->a.b = ((WmObjQ *)D_8010AD40)->b.b + D_8010AD5C;
                        D_8010AD5C *= 2;
                    } else {
                        D_8010AD5C = 0;
                    }
                }
            } else {
                ((WmObjQ *)D_8010AD40)->a.b = ((WmObjQ *)D_8010AD40)->b.b;
            }
        } else {
            d = ((WmObjQ *)D_8010AD40)->a.b - ((WmObjQ *)D_8010AD40)->b.b;
            if (d < -50) {
                ((WmObjQ *)D_8010AD40)->a.b = ((WmObjQ *)D_8010AD40)->b.b;
                D_8010AD5C = -1;
            } else if (d > 50) {
                ((WmObjQ *)D_8010AD40)->a.b = ((WmObjQ *)D_8010AD40)->b.b;
                D_8010AD5C = 1;
            }
        }
    } else {
        D_8010AD5C = 0;
        D_8010AD60 = 0;
    }
}

void func_800AA02C(s32 arg0) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s32 *, 0x10) = arg0;
    }
}

void func_800AA04C(s32 arg0) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s32 *, 0x10) = arg0;
        M2C_FIELD(D_8010AD40, u8 *, 0x51) = (u8) (M2C_FIELD(D_8010AD40, u8 *, 0x51) | 4);
    }
}

void func_800AA078(s16 arg0) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s16 *, 0x4E) = arg0;
    }
}

void func_800AA098(WQuad32 *arg0) {
    s32 p;

    if (arg0 != NULL) {
        p = D_8010AD3C;
        if (p != 0) {
            *arg0 = *(WQuad32 *)(p + 0xC);
        }
    }
}

void func_800AA0E0(WQuad32 *arg0) {
    s32 p;

    if (arg0 != NULL) {
        p = D_8010AD40;
        if (p != 0) {
            *arg0 = *(WQuad32 *)(p + 0xC);
        }
    }
}

void func_800AA128(WQuad32 *arg0) {
    s32 p;

    if (arg0 != NULL) {
        p = D_8010AD3C;
        if (p != 0) {
            *arg0 = *(WQuad32 *)(p + 0x1C);
        }
    }
}

void func_800AA170(WQuad32 *arg0) {
    s32 p;

    if (arg0 != NULL) {
        p = D_8010AD40;
        if (p != 0) {
            *arg0 = *(WQuad32 *)(p + 0x1C);
        }
    }
}

void func_800AA1B8(void) {
    if (D_8010AD3C != 0) {
        if (M2C_FIELD(D_8010AD3C, u8 *, 0x51) & 4) {
            M2C_FIELD(D_8010AD3C, s32 *, 0xC) = (s32) M2C_FIELD(D_8010AD3C, s32 *, 0x1C);
            M2C_FIELD(D_8010AD3C, s32 *, 0x14) = (s32) M2C_FIELD(D_8010AD3C, s32 *, 0x24);
        } else {
            M2C_FIELD(D_8010AD3C, s32 *, 0xC) = (s32) M2C_FIELD(D_8010AD3C, s32 *, 0x1C);
            M2C_FIELD(D_8010AD3C, s32 *, 0x10) = (s32) M2C_FIELD(D_8010AD3C, s32 *, 0x20);
            M2C_FIELD(D_8010AD3C, s32 *, 0x14) = (s32) M2C_FIELD(D_8010AD3C, s32 *, 0x24);
            M2C_FIELD(D_8010AD3C, s32 *, 0x18) = (s32) M2C_FIELD(D_8010AD3C, s32 *, 0x28);
        }
        M2C_FIELD(D_8010AD3C, u8 *, 0x51) = (u8) (M2C_FIELD(D_8010AD3C, u8 *, 0x51) & 0xFE);
    }
}

void func_800AA238(void) {
    if (D_8010AD40 != 0) {
        if (M2C_FIELD(D_8010AD40, u8 *, 0x51) & 4) {
            M2C_FIELD(D_8010AD40, s32 *, 0xC) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x1C);
            M2C_FIELD(D_8010AD40, s32 *, 0x14) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x24);
        } else {
            M2C_FIELD(D_8010AD40, s32 *, 0xC) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x1C);
            M2C_FIELD(D_8010AD40, s32 *, 0x10) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x20);
            M2C_FIELD(D_8010AD40, s32 *, 0x14) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x24);
            M2C_FIELD(D_8010AD40, s32 *, 0x18) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x28);
        }
        M2C_FIELD(D_8010AD40, u8 *, 0x51) = (u8) (M2C_FIELD(D_8010AD40, u8 *, 0x51) & 0xFE);
    }
}

void func_800AA2B8(void) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, u8 *, 0x51) = (u8) (M2C_FIELD(D_8010AD40, u8 *, 0x51) & 0xFD);
    }
}

void func_800AA2E4(s8 arg0) {
    if (D_8010AD3C != 0) {
        M2C_FIELD(D_8010AD3C, s8 *, 0x5D) = arg0;
    }
}

s32 func_800AA304(s32 arg0, u8 *arg1) {
    WmObjQ *a;
    WmObjQ *b;
    s32 r;
    s32 dx;
    s32 dz;
    s32 adx;
    s32 adz;
    s32 sum;

    a = (WmObjQ *)arg0;
    b = (WmObjQ *)arg1;
    r = 0;
    if (a != NULL && b != NULL && a != b && !(a->f51 & 0x80) && !(b->f51 & 0x80) && a->f50 < 0x1A && b->f50 < 0x1A
        && b->f50 != 0x15 && b->f50 != 0x16 && b->f50 != 0x17) {
        dx = b->a.a - a->a.a;
        if (dx > 0x24000) {
            dx -= 0x48000;
        } else if (dx < -0x24000) {
            dx += 0x48000;
        }
        dz = b->a.c - a->a.c;
        if (dz > 0x1C000) {
            dz -= 0x38000;
        } else if (dz < -0x1C000) {
            dz += 0x38000;
        }
        adx = dx < 0 ? -dx : dx;
        if (adx < 0x400) {
            adz = dz < 0 ? -dz : dz;
            if (adz < 0x400) {
                sum = adx + adz;
                dx = (dx + 0x400) >> 8;
                dz = (dz + 0x400) >> 8;
                if ((u32)dx < 8 && (u32)dz < 8) {
                    r = 0;
                    if (((D_800C6678[a->f50][dz] >> dx) & 1) || ((D_800C6678[b->f50][7 - dz] >> (7 - dx)) & 1)) {
                        r = 1;
                    }
                    if (r != 0) {
                        dx = b->a.a - a->b.a;
                        if (dx > 0x24000) {
                            dx -= 0x48000;
                        } else if (dx < -0x24000) {
                            dx += 0x48000;
                        }
                        dz = b->a.c - a->b.c;
                        if (dz > 0x1C000) {
                            dz -= 0x38000;
                        } else if (dz < -0x1C000) {
                            dz += 0x38000;
                        }
                        if (sum >= (dx < 0 ? -dx : dx) + (dz < 0 ? -dz : dz)) {
                            r = 2;
                        }
                    }
                }
            }
        }
    }
    return r;
}

s32 func_800AA580(s32 arg0) {
    s32 r;
    u8 *p;

    r = 0;
    p = NULL;
    if (D_8010AD3C != 0) {
        if (M2C_FIELD(D_8010AD3C, u8 *, 0x50) != 0xD || func_800A1DE0() != 0) {
            for (p = D_8010AD38; p != NULL; p = *(u8 **)p) {
                r = func_800AA304(D_8010AD3C, p);
                if (r != 0) {
                    break;
                }
            }
            if (p != NULL) {
                M2C_FIELD(D_8010AD3C, u8 **, 4) = p;
            }
        }
    }
    return r < 2 ? (s32)p : 0;
}

s32 func_800AA640(void) {
    s32 temp_v0;

    temp_v0 = func_800AA580(D_8010AD3C);
    if (temp_v0 != 0) {
        func_800AA1B8();
    }
    return temp_v0;
}

s32 func_800AA684(void) {
    s32 var_v0;

    var_v0 = 0;
    if (D_8010AD3C != 0) {
        var_v0 = M2C_FIELD(D_8010AD3C, s32 *, 4);
    }
    return var_v0;
}

void func_800AA6A4(void) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, u8 *, 0x51) = (u8) (M2C_FIELD(D_8010AD40, u8 *, 0x51) | 2);
    }
}

void func_800AA6D0(u8 *arg0) {
    W4SVec v;
    s16 bx;
    s16 bz;
    WmObj64 *p;

    for (p = (WmObj64 *)D_8010AD38; p != NULL; p = p->next) {
        if (p != (WmObj64 *)D_8010AD40) {
            func_800A6884(&p->pos, &v.vx, &bx, &bz);
            if (bx == M2C_FIELD(arg0, s16 *, 0x10) && bz == M2C_FIELD(arg0, s16 *, 0x12)) {
                func_800A19FC(arg0, &v.vx, &p->f60, &p->f42, 0, (s32)&p->f4A, p->f50);
                if (!(p->f51 & 0x80)) {
                    p->pos.y = p->f42 + func_800A9B04(p->f4A, p->f50);
                }
                p->f51 |= 2;
            }
        }
    }
    func_800B0D98(arg0);
    func_800B1C80(arg0);
}

void func_800AA7DC(s32 arg0, s32 arg1) {
    WmActor *p;

    p = (WmActor *)D_8010AD3C;
    if (p != 0 && (arg0 != 0 || arg1 != 0)) {
        p->fC += arg0;
        p->f14 += arg1;
        if (p->fC < 0) {
            p->fC += 0x48000;
        }
        if (M2C_FIELD(D_8010AD3C, s32 *, 0xC) > 0x47FFF) {
            M2C_FIELD(D_8010AD3C, s32 *, 0xC) -= 0x48000;
        }
        if (M2C_FIELD(D_8010AD3C, s32 *, 0x14) < 0) {
            M2C_FIELD(D_8010AD3C, s32 *, 0x14) += 0x38000;
        }
        if (M2C_FIELD(D_8010AD3C, s32 *, 0x14) > 0x37FFF) {
            M2C_FIELD(D_8010AD3C, s32 *, 0x14) -= 0x38000;
        }
        M2C_FIELD(D_8010AD3C, u8 *, 0x51) |= 1;
    }
}

void func_800AA8D8(s16 arg0, s16 arg1, s16 arg2) {
    D_8010AD44 = arg0;
    D_8010AD48 = arg1;
    D_8010AD4C = arg2;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AA8F8);

s32 func_800AAA00(u8 *arg0) {
    s32 old;
    s32 m;

    old = D_80109D70;
    m = func_800A9A44();
    switch (D_80109D70) {
    case 1:
        if (m == 0xB) {
            D_80109D70 = 2;
        }
        break;
    case 2:
        if (*arg0 >= 6) {
            D_80109D70 = 3;
        }
        break;
    case 3:
        if (m != 4 && m != 0xB) {
            D_80109D70 = 4;
        }
        break;
    case 4:
        if (*arg0 >= 6) {
            D_80109D70 = 1;
        }
        break;
    default:
        D_80109D70 = 1;
        break;
    }
    if (D_80109D70 != old) {
        *arg0 = 0;
    }
    return D_80109D70;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AAB18);

void func_800AB36C(void *arg0) {
    if (arg0 != NULL) {
        M2C_SFIELD(arg0, s16 *, 2) = 0;
        M2C_SFIELD(arg0, u16 *, 0) = (u16) D_8010AD54;
        M2C_SFIELD(arg0, u16 *, 4) = (u16) D_8010AD58;
    }
}

void func_800AB398(void *arg0) {
    u8 temp_v1;

    if ((arg0 != NULL) && (D_8010AD40 != 0) && (M2C_FIELD(arg0, u8 *, 0x51) & 2) && (((((func_800A921C(7, M2C_FIELD(arg0, u8 *, 0x50)) != 0) && ((u32) (M2C_FIELD(arg0, u8 *, 0x5D) - 2) >= 4U)) || (func_800A92F8((s32) M2C_FIELD(arg0, u8 *, 0x50)) != 0)) && ((arg0 != D_8010AD40) || (D_8010AD5C == 0)) && ((0x311B6F05 >> (M2C_FIELD(arg0, u16 *, 0x4A) & 0x1F)) & 1)) || (temp_v1 = M2C_FIELD(arg0, u8 *, 0x50), (temp_v1 == 3)) || (temp_v1 == 0xB))) {
        func_800B5C7C(arg0);
    }
}

void func_800AB48C(W3Ent *arg0) {
    W3Ent *t;

    t = arg0->link;
    if ((t != NULL) && ((arg0->flags & 1) || (t->flags & 1))) {
        arg0->link = NULL;
    }
    arg0->b = arg0->a;
}

void func_800AB4F4(void) {
    W3Obj2 *p;

    p = (W3Obj2 *)D_8010AD38;
    if (p != NULL) {
        do {
            func_800AB48C((u8 *)p);
            p = p->next;
        } while (p != NULL);
    }
    p = (W3Obj2 *)D_8010AD38;
    if (p != NULL) {
        do {
            p->f51 &= 0xF8;
            p = p->next;
        } while (p != NULL);
    }
}

void func_800AB570(void) {
    W3Obj *p;

    p = (W3Obj *)D_8010AD38;
    if (p != NULL) {
        do {
            func_800AAB18((u8 *)p);
            p = p->next;
        } while (p != NULL);
    }
    p = (W3Obj *)D_8010AD38;
    if (p != NULL) {
        do {
            func_800AB398((u8 *)p);
            p = p->next;
        } while (p != NULL);
    }
}

void func_800AB5E4(u8 *arg0) {
    u8 *p;
    s32 i;

    D_8010AD68 = arg0;
    D_8010AD6C = (u16 *)(arg0 + 0x400);
    D_8010AD90 = D_8010AD70;
    D_8010AD94 = &D_8009D288;
    D_8010AD98 = D_8010AD9C = D_8010ADA0 = D_8010ADA4;
    D_8010ADE4 = NULL;
    D_8010ADF0 = 0;
    D_8010ADEC = 0;
    D_8010ADE8 = 0;
    p = D_8010ADA4;
    for (i = 63; i >= 0; i--) {
        p[i] = 0;
    }
    for (i = 0; i < 3; i++) {
        D_8010ADF4[i].a = D_8010ADF4[i].b = D_8010ADF4[i].c = 0;
    }
    D_8010AE24 = D_8010AE28 = 0;
    D_8010AE2C = D_8010AE30 = 0;
    D_8010AE38 = D_8010AE3C = 0;
    D_8010AE34.a = 0;
}

s32 func_800AB6E4(s32 id, s32 prio) {
    s32 pushed;
    s32 step;
    u16 *p;
    WmScrRet *e;

    pushed = 0;
    if (D_8010AD3C != 0 && (((WmScr *)D_8010AD3C)->f57 < prio || (((WmScr *)D_8010AD3C)->f57 == prio && prio == 3) || ((WmScr *)D_8010AD3C)->f46 == 0)) {
        if (((WmScr *)D_8010AD3C)->f54 >= 4) {
            func_800A0B40(0x41);
        }
        if (((WmScr *)D_8010AD3C)->f46 != 0) {
            e = &((WmScr *)D_8010AD3C)->stack[((WmScr *)D_8010AD3C)->f54++];
            e->id = ((WmScr *)D_8010AD3C)->f46;
            e->f2 = ((WmScr *)D_8010AD3C)->f56;
            e->f3 = ((WmScr *)D_8010AD3C)->f57;
            pushed = 1;
        }
        step = 0x40;
        p = (u16 *)(D_8010AD68 + 0x200);
        do {
            if (*p == id) {
                goto found;
            }
            if (*p < id) {
                p += step * 2;
            } else {
                p -= step * 2;
            }
            step >>= 1;
        } while (step != 0);
        if (*p == id) {
        found:
            ((WmScr *)D_8010AD3C)->f46 = p[1];
            ((WmScr *)D_8010AD3C)->f57 = prio;
        } else {
            ((WmScr *)D_8010AD3C)->f46 = 0;
            ((WmScr *)D_8010AD3C)->f57 = 0;
        }
        if (pushed != 0 && ((WmScr *)D_8010AD3C)->f46 == 0) {
            e = &((WmScr *)D_8010AD3C)->stack[--((WmScr *)D_8010AD3C)->f54];
            ((WmScr *)D_8010AD3C)->f46 = e->id;
            ((WmScr *)D_8010AD3C)->f56 = e->f2;
            ((WmScr *)D_8010AD3C)->f57 = e->f3;
        }
    }
}

void func_800AB8EC(s32 arg0) {
    u8 *p;
    u8 v;

    p = (u8 *)D_8010AD40;
    if (p != 0) {
        if (arg0 != 0) {
            v = p[0x51] | 0x10;
        } else {
            v = p[0x51] & 0xEF;
        }
        p[0x51] = v;
    }
}

void func_800AB92C(s32 arg0) {
    s32 var_a1;
    s32 id;

    if (D_8010AD3C != 0) {
        if (!(M2C_FIELD(D_8010AD3C, u8 *, 0x51) & 0x10)) {
            var_a1 = arg0 - 2;
            id = arg0 & 0xFF;
            if (var_a1 < 0) {
                var_a1 = 0;
            }
            if (var_a1 >= 4) {
                var_a1 = 3;
            }
            func_800AB6E4(id, var_a1);
        }
    }
}

void func_800AB988(s32 arg0, s32 arg1) {
    s32 n;
    s32 id;

    func_800A993C(arg0);
    if (D_8010AD3C != 0) {
        if (!(M2C_FIELD(D_8010AD3C, u8 *, 0x51) & 0x10)) {
            n = arg1 - 2;
            id = 0x4000 | ((arg0 << 8) & 0x3F00) | (arg1 & 0xFF);
            if (n < 0) {
                n = 0;
            }
            if (n >= 4) {
                n = 3;
            }
            func_800AB6E4(id, n);
        }
    }
}

s32 func_800ABA18(s32 arg0) {
    s32 var_a1;
    s32 id;

    D_8010AD3C = (s32) &D_80109D74;
    if (arg0 == 1) {
        D_8010ADEC = arg0;
    }
    var_a1 = arg0 - 2;
    id = arg0 & 0xFF;
    if (var_a1 < 0) {
        var_a1 = 0;
    }
    if (var_a1 >= 4) {
        var_a1 = 3;
    }
    return func_800AB6E4(id, var_a1);
}

s32 func_800ABA78(s16 arg0, s16 arg1) {
    s16 bx;
    s16 bz;

    D_8010AD3C = (s32)&D_80109D74;
    func_800A6884((W4Pos *)(D_8010AD40 + 0xC), NULL, &bx, &bz);
    return func_800AB6E4(0x8000 | (((bz * 36 + bx) << 4) & 0x3FF0) | ((arg0 + arg1 * 5) & 0xF), 3);
}

s32 func_800ABB24(void) {
    s32 r;
    u32 k;
    s32 v;
    u8 *p;

    r = 0;
    if (--D_8010AD90 <= &D_8010AD70[-1]) {
        func_800A0B40(0x3E);
    }
    k = D_8010AD90->id & 3;
    if (k < 3) {
        switch (*(volatile u16 *)&D_8010AD90->id & 0xFFFC) {
        case 0x110:
            r = D_8010AD90->val;
            break;
        case 0x114:
            v = D_8010AD90->val;
            r = (((u8 **)&D_8010AD94)[k][v >> 3] >> (v & 7)) & 1;
            break;
        case 0x118:
            r = ((u8 **)&D_8010AD94)[k][D_8010AD90->val];
            break;
        case 0x11C:
            p = ((u8 **)&D_8010AD94)[k] + D_8010AD90->val;
            if ((s32)p & 1) {
                func_800A0B40(0x3F);
            }
            r = *(s16 *)p;
            break;
        }
    } else {
        switch (D_8010AD90->val) {
        case 0:
            r = ((WmActor *)D_8010AD3C)->fC >> 13;
            break;
        case 1:
            r = ((WmActor *)D_8010AD3C)->f14 >> 13;
            break;
        case 2:
            r = ((WmActor *)D_8010AD3C)->fC & 0x1FFF;
            break;
        case 3:
            r = ((WmActor *)D_8010AD3C)->f14 & 0x1FFF;
            break;
        case 4:
            r = (*(u16 *)((u8 *)D_8010AD3C + 0x40) >> 4) & 0xFF;
            break;
        case 5:
            r = func_800B785C();
            break;
        case 6:
            r = func_800B786C();
            break;
        case 7:
            r = func_800A4080();
            break;
        case 8:
            r = ((s32 (*)(void))func_800A9174)();
            break;
        case 15:
            r = ((WmActor *)D_8010AD3C)->f50;
            break;
        case 9:
            r = ((s32 (*)(void))func_800B7B2C)();
            break;
        case 10:
            r = func_800B7B3C();
            break;
        case 11:
            r = func_800B0800();
            break;
        case 12:
            r = func_800B86C4();
            break;
        case 13:
            r = ((WmActorBits *)D_8010AD3C)->dir;
            break;
        case 14:
            r = func_800B79B8();
            break;
        case 16:
            r = ((s32 (*)(void))func_800ADFC0)();
            break;
        case 17:
            r = D_8010AE24;
            break;
        case 18:
            r = D_8010AE28;
            break;
        case 19:
            r = D_8010AE2C;
            break;
        case 20:
            r = D_8010AE30;
            break;
        }
    }
    return r;
}

void func_800ABE58(s32 arg0) {
    u8 *base;
    s32 v;
    s32 m;
    u8 t;
    WmPair8 *p;

    if (--D_8010AD90 <= &D_8010AD70[-1]) {
        func_800A0B40(0x3E);
    }
    base = ((u8 **)&D_8010AD94)[D_8010AD90->id & 3];
    switch (*(volatile u16 *)&D_8010AD90->id & 0xFFFC) {
    case 0x114:
        v = D_8010AD90->val;
        base += v >> 3;
        m = 1 << (v & 7);
        *base &= ~m;
        t = *(volatile u8 *)base;
        if (arg0 != 0) {
            t |= m;
        }
        *base = t;
        break;
    case 0x118:
        base[D_8010AD90->val] = arg0;
        break;
    case 0x11C:
        base += D_8010AD90->val;
        if ((s32)base & 1) {
            func_800A0B40(0x3F);
        }
        *(s16 *)base = arg0;
        break;
    default:
        func_800A0B40(0x40);
        break;
    }
    p = D_8010AD90;
    p->val = arg0;
    p->id = 0x110;
    D_8010AD90 = p + 1;
}

void func_800ABFC0(u16 arg0) {
    WQuad32 pos;
    s32 a;
    s32 r;
    s32 old;
    s32 idx;
    WmPair8 *e;

    switch (arg0) {
    case 0x15:
        D_8010AD90->val = -func_800ABB24();
        break;
    case 0x17:
        D_8010AD90->val = func_800ABB24() == 0;
        break;
    case 0x30:
        a = func_800ABB24();
        D_8010AD90->val = func_800ABB24() * a;
        break;
    case 0x40:
        a = func_800ABB24();
        D_8010AD90->val = func_800ABB24() + a;
        break;
    case 0x41:
        a = func_800ABB24();
        D_8010AD90->val = func_800ABB24() - a;
        break;
    case 0x60:
        a = func_800ABB24();
        D_8010AD90->val = func_800ABB24() < a;
        break;
    case 0x61:
        a = func_800ABB24();
        D_8010AD90->val = a < func_800ABB24();
        break;
    case 0x62:
        a = func_800ABB24();
        D_8010AD90->val = a >= func_800ABB24();
        break;
    case 0x63:
        a = func_800ABB24();
        D_8010AD90->val = func_800ABB24() >= a;
        break;
    case 0x70:
        a = func_800ABB24();
        D_8010AD90->val = func_800ABB24() == a;
        break;
    case 0x71:
        a = func_800ABB24();
        D_8010AD90->val = func_800ABB24() != a;
        break;
    case 0x50:
        a = func_800ABB24();
        D_8010AD90->val = func_800ABB24() << a;
        break;
    case 0x51:
        a = func_800ABB24();
        D_8010AD90->val = func_800ABB24() >> a;
        break;
    case 0x80:
        a = func_800ABB24();
        D_8010AD90->val = func_800ABB24() & a;
        break;
    case 0xA0:
        a = func_800ABB24();
        D_8010AD90->val = func_800ABB24() | a;
        break;
    case 0xB0:
        a = func_800ABB24();
        r = func_800ABB24();
        D_8010AD90->val = r != 0 && a != 0;
        break;
    case 0xC0:
        a = func_800ABB24();
        r = func_800ABB24();
        D_8010AD90->val = r != 0 || a != 0;
        break;
    case 0xE0:
        func_800ABE58(func_800ABB24());
        break;
    case 0x18:
        func_800AF1A8(func_800ABB24(), -1);
        func_800AA098(&pos);
        D_8010AD90->val = func_800AF96C(&pos) >> 5;
        break;
    case 0x19:
        old = D_8010AD3C;
        D_8010AD90->val = 0;
        if (func_800A993C(func_800ABB24()) != 0) {
            D_8010AD90->val = func_800AE024((void *)(D_8010AD3C + 0xC), (void *)(old + 0xC)) >> 4;
        }
        D_8010AD3C = old;
        break;
    case 0x1A:
        idx = func_800ABB24();
        e = D_8010AD90;
        pos = *(WQuad32 *)(D_8010AD3C + 0xC);
        pos.b = 0;
        if ((u32)idx < 3) {
            e->val = func_800AE024(&pos, &D_8010ADF4[idx]) >> 4;
        } else {
            e->val = 0;
        }
        break;
    case 0x1B:
        func_800AF1A8(func_800ABB24(), -1);
        func_800AA098(&pos);
        D_8010AD90->val = func_800AF9A0(&pos) >> 4;
        break;
    }
    D_8010AD90->id = 0x110;
    D_8010AD90 += 1;
}

void func_800AC3C0(u16 arg0) {
    WmPair8 *p;

    if (arg0 == 0x100) {
        D_8010AD90 = D_8010AD70;
        return;
    }
    if (D_8010AD90 == NULL || D_8010ADE4 == NULL) {
        func_800A0B40(0x3D);
    }
    p = D_8010AD90;
    p->id = arg0;
    p->val = D_8010AD6C[(s16)((WmNode46 *)D_8010ADE4)->f46++];
    D_8010AD90 = p + 1;
}

s32 func_800AC484(u16 arg0) {
    s32 r;
    u16 v;
    WmScrRet *e;
    WmObjE0 *p;

    r = 0;
    switch (arg0) {
    case 0x200:
        v = D_8010AD6C[(s16)((WmScrB *)D_8010ADE4)->f46++];
        ((WmScrB *)D_8010ADE4)->f46 = v;
        break;
    case 0x201:
        v = D_8010AD6C[(s16)((WmScrB *)D_8010ADE4)->f46++];
        if (func_800ABB24() == 0) {
            ((WmScrB *)D_8010ADE4)->f46 = v;
        }
        break;
    case 0x203:
        if (((WmScrB *)D_8010ADE4)->f54 != 0) {
            e = &((WmScrB *)D_8010ADE4)->stack[--((WmScrB *)D_8010ADE4)->f54];
            ((WmScrB *)D_8010ADE4)->f46 = e->id;
            ((WmScrB *)D_8010ADE4)->f56 = e->f2;
            ((WmScrB *)D_8010ADE4)->f57 = e->f3;
            break;
        }
        ((WmScrB *)D_8010ADE4)->f46 = ((WmScrB *)D_8010ADE4)->f57 = 0;
        if (D_8010ADEC != 0) {
            if (D_8010ADE4 == &D_80109D74) {
                for (p = (WmObjE0 *)D_8010AD38; p != NULL; p = p->next) {
                    func_800AB988(p->f50, 1);
                }
            }
        } else if (D_8010ADE4 == &D_80109D74) {
            func_800ABA18(2);
        } else {
            func_800AB988(((WmScrB *)D_8010ADE4)->f50, 2);
        }
        r = 1;
        break;
    default:
        ((WmScrB *)D_8010ADE4)->f52 = func_800ABB24();
        if (((WmScrB *)D_8010ADE4)->f52 < 0x40) {
            func_800AB988(((WmScrB *)D_8010ADE4)->f52, arg0 - 0x204);
        } else {
            ((WmScrB *)D_8010ADE4)->f52 = ((WmScrB *)D_8010AD3C)->f50;
            func_800AB92C(arg0 - 0x204);
        }
        r = 1;
        break;
    }
    return r;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AC700);

void func_800AD63C(u8 *arg0) {
    s32 done;
    u16 op;
    s32 n;

    D_8010ADE8 = 0;
    if (M2C_SFIELD(D_8010ADE4, s16 *, 0x46) != 0) {
        done = 0;
        do {
            op = D_8010AD6C[M2C_FIELD(D_8010ADE4, s16 *, 0x46)++];
            if (op < 0x100) {
                func_800ABFC0(op);
            } else if (op < 0x200) {
                func_800AC3C0(op);
            } else if (op < 0x300) {
                done = func_800AC484(op);
            } else {
                done = func_800AC700(op);
            }
        } while (done == 0);
    }
    func_800A9678(M2C_FIELD(arg0, s16 *, 0x40));
    if (M2C_FIELD(arg0, u8 **, 4) != NULL && D_8010ADEC == 0 && func_800A21A4() != 0) {
        if (func_8001C8D4() & 0x20) {
            n = 4;
        } else {
            n = 3;
        }
        func_800AB988(M2C_FIELD(arg0, u8 **, 4)[0x50], n);
    }
}

void func_800AD788(void) {
    W3Obj3 *p;

    D_8010ADE4 = &D_80109D74;
    D_8010AD3C = (s32) &D_80109D74;
    func_800AD63C(&D_80109D74);
    p = (W3Obj3 *)D_8010AD38;
    if (p != NULL) {
        do {
            D_8010AD3C = (s32)p;
            D_8010ADE4 = (u8 *)p;
            func_800AD63C((u8 *)p);
            p = p->next;
        } while (p != NULL);
    }
}

void func_800AD804(void) {
    s32 m;

    if (D_8010ADEC != 0 || (((WmObj64 *)D_8010AD40)->f51 & 8)) {
        return;
    }
    if (func_800A91A4(0x2000) != 0) {
        if (((WmObj64 *)D_8010AD40)->pos.y - ((WmObj64 *)D_8010AD40)->f42 >= 500) {
            return;
        }
    } else if (((WmObj64 *)D_8010AD40)->f51 & 0x80) {
        return;
    }
    m = func_800A9AD0();
    if (m >= 3) {
        if (D_8010ADF0 != m) {
            D_8010ADF0 = m;
            func_800ABA78(m - 3, 0);
        }
        if (m == 7 && func_800A91A4(0x2000) == 0) {
            func_800AA238();
        }
    } else {
        D_8010ADF0 = 0;
    }
}

s32 func_800AD928(void) {
    s32 r;
    WmNode46 *p;
    s32 t;

    r = D_80109DBA != 0;
    p = (WmNode46 *)D_8010AD38;
    while (p != NULL && r == 0) {
        t = p->f46;
        p = p->next;
        r |= t != 0;
    }
    return r;
}

void func_800AD970(u8 *arg0) {
    u8 id;
    u32 slot;
    s32 *p;

    id = arg0[0x50];
    slot = D_800C6748[id];
    if (slot < 6) {
        p = &D_8010AD50[slot * 2];
        p[0] = (M2C_FIELD(arg0, s32 *, 0x1C) & 0x7FFFF) | ((id << 19) & 0xF80000) | ((M2C_FIELD(arg0, s16 *, 0x40) << 20) & 0xFF000000);
        p[1] = (M2C_FIELD(arg0, s32 *, 0x24) & 0x3FFFF) | (M2C_FIELD(arg0, s32 *, 0x20) << 18);
    }
}

void func_800ADA08(void) {
    u8 *var_s0;

    var_s0 = D_8010AD38;
    if (var_s0 != NULL) {
        do {
            if (!(M2C_FIELD(var_s0, u8 *, 0x51) & 8)) {
                func_800AD970(var_s0);
            }
            var_s0 = M2C_FIELD(var_s0, u8 **, 0);
        } while (var_s0 != NULL);
    }
}

void func_800ADA64(WmActor *arg0) {
    s32 *p;

    for (p = D_8010AD50; p < D_8010AD50 + 12; p += 2) {
        if (((p[0] >> 19) & 0x1F) == arg0->f50) {
            break;
        }
    }
    if (p < D_8010AD50 + 12 && arg0 != NULL) {
        arg0->fC = arg0->f1C = p[0] & 0x7FFFF;
        arg0->f10 = arg0->f20 = p[1] >> 18;
        arg0->f14 = arg0->f24 = p[1] & 0x3FFFF;
        arg0->f4C = arg0->f3C = arg0->f40 = (p[0] >> 20) & 0xFF0;
        arg0->f3E = 0;
    }
}

void func_800ADB30(u32 arg0, u32 arg1) {
    u32 bits;
    u32 n;
    s32 i;
    u32 mask;
    s32 *p;

    mask = 0x40;
    bits = arg0 & ~arg1;
    n = 0;
    p = &D_8010AE2C;
    D_8010AE24 = D_8010AE28 = 0;
    *p = D_8010AE30 = 0;
    if (bits & mask) {
        *p = 0x26;
        n = 1;
        bits &= ~mask;
    }
    for (i = 0; n < 2; i++) {
        if (bits == 0) {
            break;
        }
        if (bits & 1) {
            p[n] = i + 0x20;
            n++;
        }
        bits >>= 1;
    }
    bits = ~arg0 & arg1;
    n = 0;
    if (bits & mask) {
        D_8010AE24 = 0x26;
        n = 1;
        bits &= ~mask;
    }
    for (i = 0; n < 2; i++) {
        if (bits == 0) {
            break;
        }
        if (bits & 1) {
            (&D_8010AE24)[n] = i + 0x20;
            n++;
        }
        bits >>= 1;
    }
}

void func_800ADC3C(V4 *arg0) {
    D_8010AE34 = *arg0;
}

void func_800ADC70(void) {
    D_8010AE54 = 0;
}

s32 func_800ADC80(s16 arg0) {
    if ((D_8010AE54 >> arg0) & 1) {
        if (!((-1 << (arg0 + 1)) & D_8010AE54)) {
            return 1;
        }
    }
    if (D_8010AE54 < (1 << arg0)) {
        if (D_8010AE54 == 1) {
            func_800A7F38();
        } else if (D_8010AE54 & 4) {
            func_800B7134();
        }
        D_8010AE54 |= 1 << arg0;
        return 1;
    }
    return 0;
}

void func_800ADD4C(s16 arg0) {
    u32 m;

    if (((-1 << (arg0 + 1)) & D_8010AE54) || !((D_8010AE54 >> arg0) & 1)) {
        func_800A0B40(0x50);
    }
    D_8010AE54 &= ~(1 << arg0);
    if (arg0 != 0) {
        for (m = 1 << (arg0 - 1); m != 0 && !(m & D_8010AE54); m >>= 1) {
        }
        if (m == 1) {
            func_800A8048();
        }
    }
}

void func_800ADE30(void) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        D_8010AE5C[i] ^= D_8010B045[i];
    }
    for (i = 0x20; i < 0x209; i++) {
        D_8010AE5C[i] ^= D_8010AE5C[i - 0x20];
    }
}

void func_800ADEA8(s32 seed) {
    u32 buf[0x209];
    s32 i;
    s32 j;
    u32 r;

    r = 0;
    for (i = 0; i < 17; i++) {
        for (j = 0; j < 32; j++) {
            seed = seed * 0x5D588B65 + 1;
            r = (r >> 1) | (seed & 0x80000000);
        }
        buf[i] = r;
    }
    buf[16] = (buf[16] << 23) ^ (buf[0] >> 9) ^ buf[15];
    for (i = 17; i < 0x209; i++) {
        buf[i] = (buf[i - 17] << 23) ^ (buf[i - 16] >> 9) ^ buf[i - 1];
    }
    for (i = 0; i < 0x209; i++) {
        D_8010AE5C[i] = buf[i];
    }
    func_800ADE30();
    func_800ADE30();
    func_800ADE30();
    D_8010AE58 = 0x208;
}

u8 func_800ADFC0(void) {
    D_8010AE58 += 1;
    if (D_8010AE58 >= 0x209) {
        func_800ADE30();
        D_8010AE58 = 0;
    }
    return D_8010AE5C[D_8010AE58];
}

s32 func_800AE024(void *arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0);
    temp_v0 = M2C_FIELD(arg1, s32 *, 0);
    var_a2 = temp_v1 - temp_v0;
    if (var_a2 <= 0) {
        var_a2 = temp_v0 - temp_v1;
    }
    if (var_a2 > 0x23FFF) {
        var_a2 = 0x48000 - var_a2;
    }
    temp_v1_2 = M2C_FIELD(arg0, s32 *, 4);
    temp_v0_2 = M2C_FIELD(arg1, s32 *, 4);
    var_a3 = temp_v1_2 - temp_v0_2;
    if (var_a3 <= 0) {
        var_a3 = temp_v0_2 - temp_v1_2;
    }
    temp_a0 = M2C_FIELD(arg0, s32 *, 8);
    temp_a1 = M2C_FIELD(arg1, s32 *, 8);
    var_v1 = temp_a0 - temp_a1;
    if (var_v1 <= 0) {
        var_v1 = temp_a1 - temp_a0;
    }
    if (var_v1 > 0x1BFFF) {
        var_v1 = 0x38000 - var_v1;
    }
    return var_a2 + var_a3 + var_v1;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AE0BC);

s16 func_800AE180(s32 x, s32 y, s32 unused) {
    s32 ret;

    ret = 0;
    if (x != 0 || y != 0) {
        if (y >= 0) {
            if (x >= 0) {
                if (x >= y) {
                    ret = 0x400 - ((u16 *)D_800BE1E8)[(y << 8) / x];
                } else {
                    ret = ((u16 *)D_800BE1E8)[(x << 8) / y];
                }
            } else {
                x = -x;
                if (y >= x) {
                    ret = -((u16 *)D_800BE1E8)[(x << 8) / y];
                } else {
                    ret = ((u16 *)D_800BE1E8)[(y << 8) / x] - 0x400;
                }
            }
        } else if (x < 0) {
            x = -x;
            y = -y;
            if (x >= y) {
                ret = -((u16 *)D_800BE1E8)[(y << 8) / x] - 0x400;
            } else {
                ret = ((u16 *)D_800BE1E8)[(x << 8) / y] - 0x800;
            }
        } else {
            y = -y;
            if (y >= x) {
                ret = 0x800 - ((u16 *)D_800BE1E8)[(x << 8) / y];
            } else {
                ret = ((u16 *)D_800BE1E8)[(y << 8) / x] + 0x400;
            }
        }
    }
    return ret;
}

s16 func_800AE47C(void *arg0, void *arg1) {
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg1, s32 *, 0);
    return func_800AE180(temp_a2 - M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg1, s32 *, 8) - M2C_FIELD(arg0, s32 *, 8), temp_a2);
}

void func_800AE4B8(void) {
    s32 i;
    WmG4 *p;

    for (i = 0; i < 2; i++) {
        p = (WmG4 *)&D_800C6770[i];
        p->r0 = p->r1 = D_800C6768[0];
        p->g0 = p->g1 = D_800C6768[1];
        p->b0 = p->b1 = D_800C6768[2];
        p->r2 = p->r3 = D_800C676C[0];
        p->g2 = p->g3 = D_800C676C[1];
        p->b2 = p->b3 = D_800C676C[2];
        ((u8 *)p)[3] = 8;
        p->code = 0x38;
        func_80044A68(&D_8010B068[i], 0, 1, 0, 0);
    }
    D_8010B080 = 0;
}

WmEnt24 *func_800AE5B8(void) {
    return &D_800C6770[func_800A0BD4()];
}

S0C *func_800AE5F0(void) {
    return &D_8010B068[func_800A0BD4()];
}

s32 func_800AE628(void) {
    return D_8010B080;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AE638);

void func_800AE8AC(void) {
    s32 i;
    WmFt4 *p;
    WmFt4 *q;

    for (i = 0; i < 2; i++) {
        for (p = D_8010B084[i]; p < D_8010B084[i] + 3; p++) {
            ((u8 *)p)[3] = 9;
            p->code = 0x2C;
            p->r0 = p->g0 = p->b0 = 0x40;
            p->v0 = p->v1 = 0xC0;
            p->v3 = 0xFF;
            p->v2 = 0xFF;
            p->clut = 0x7B0F;
            p->code |= 2;
            p->tpage = (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) ? 0xA9 : 0x39;
        }
        q = &D_800C67B8[i];
        ((u8 *)q)[3] = 9;
        q->code = 0x2E;
        D_800C67B8[i].tpage = (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) ? 0xAB : 0x3B;
    }
    D_8010B174 = 0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AEA48);

void func_800AF0A0(s32 arg0) {
    D_8010B174 = arg0;
}

void func_800AF0B0(void) {
    s32 i;
    s32 off;

    i = 0;
    off = 0;
    do {
        D_8010B18B[off] = 0;
        *(s32 *)&D_8010B17C[off] = 0;
        off += 0x24;
        i++;
    } while (i < 0x10);
    D_8010B3B8 = NULL;
    func_800AF110(i);
}

void func_800AF110(s32 arg0) {
    u8 *m;

    if (func_800A1DE0() == 2) {
        m = D_800C6828;
    } else {
        m = D_800C6808;
    }
    func_8003B4BC(m);
    if (func_800A1DE0() == 2) {
        func_8003B67C(0x20, 0x20, 0x30);
    } else {
        func_8003B67C(0x40, 0x40, 0x40);
    }
    func_8003B4EC(D_800C6848);
    func_8003B69C(0, 0, 0);
}

void func_800AF1A8(u32 arg0, s32 arg1) {
    u8 *p;

    if (arg0 < 0x10U) {
        p = D_8010B178[arg0];
        D_8010B3B8 = p;
        if (arg1 != -1) {
            p[0x13] = arg1;
        }
    }
}

void func_800AF1E8(u32 arg0, u32 arg1) {
    if ((D_8010B3B8 != NULL) && (arg0 < 0x24U) && (arg1 < 0x1CU)) {
        M2C_SFIELD(D_8010B3B8, s32 *, 0) = (s32) (M2C_SFIELD(D_8010B3B8, s32 *, 0) & 0x1FFF);
        M2C_SFIELD(D_8010B3B8, s32 *, 8) = (s32) (M2C_SFIELD(D_8010B3B8, s32 *, 8) & 0x1FFF);
        M2C_SFIELD(D_8010B3B8, s32 *, 0) = (s32) ((arg0 << 0xD) | M2C_SFIELD(D_8010B3B8, s32 *, 0));
        M2C_SFIELD(D_8010B3B8, s32 *, 8) = (s32) ((arg1 << 0xD) | M2C_SFIELD(D_8010B3B8, s32 *, 8));
    }
}

void func_800AF24C(s32 arg0, s32 arg1) {
    if (D_8010B3B8 != NULL) {
        M2C_SFIELD(D_8010B3B8, s32 *, 0) = (s32) (M2C_SFIELD(D_8010B3B8, s32 *, 0) & ~0x1FFF);
        M2C_SFIELD(D_8010B3B8, s32 *, 8) = (s32) (M2C_SFIELD(D_8010B3B8, s32 *, 8) & ~0x1FFF);
        M2C_SFIELD(D_8010B3B8, s32 *, 0) = (s32) ((arg0 & 0x1FFF) | M2C_SFIELD(D_8010B3B8, s32 *, 0));
        M2C_SFIELD(D_8010B3B8, s32 *, 8) = (s32) ((arg1 & 0x1FFF) | M2C_SFIELD(D_8010B3B8, s32 *, 8));
    }
}

void func_800AF2A4(s8 arg0, s8 arg1, s8 arg2) {
    if (D_8010B3B8 != NULL) {
        M2C_FIELD(D_8010B3B8, s8 *, 0x10) = arg0;
        M2C_FIELD(D_8010B3B8, s8 *, 0x11) = arg1;
        M2C_FIELD(D_8010B3B8, s8 *, 0x12) = arg2;
    }
}

void func_800AF2E4(s32 arg0) {
    if (D_8010B3B8 != NULL) {
        M2C_FIELD(D_8010B3B8, s32 *, 0x1C) = arg0;
    }
}

void func_800AF304(s32 arg0) {
    if (D_8010B3B8 != NULL) {
        M2C_FIELD(D_8010B3B8, s32 *, 0x20) = arg0;
    }
}

void func_800AF324(s8 arg0, s8 arg1, s8 arg2) {
    if (D_8010B3B8 != NULL) {
        M2C_FIELD(D_8010B3B8, s8 *, 0x14) = arg0;
        M2C_FIELD(D_8010B3B8, s8 *, 0x15) = arg1;
        M2C_FIELD(D_8010B3B8, s8 *, 0x16) = arg2;
    }
}

void func_800AF364(s8 arg0, s8 arg1, s8 arg2) {
    if (D_8010B3B8 != NULL) {
        M2C_FIELD(D_8010B3B8, s8 *, 0x18) = arg0;
        M2C_FIELD(D_8010B3B8, s8 *, 0x19) = arg1;
        M2C_FIELD(D_8010B3B8, s8 *, 0x1A) = arg2;
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AF3A4);

s32 func_800AF96C(void *arg0) {
    if (D_8010B3B8 != NULL) {
        return func_800AE024(arg0, D_8010B3B8);
    }
    return 0;
}

s16 func_800AF9A0(void *arg0) {
    if (D_8010B3B8 == NULL) {
        return 0;
    }
    return func_800AE47C(arg0, D_8010B3B8);
}

void func_800AF9DC(void) {
    s32 i;
    WmTile *t;

    for (i = 0; i < 2; i++) {
        t = (WmTile *)&D_8010B3BC[i][0];
        D_8010B3BC[i][0].x0 = D_8010B3BC[i][0].y0 = 0;
        t->len = 3;
        t->w = 0x140;
        t->h = 0xF0;
        t->code = 0x62;
        func_80044A68(D_8010B434[i], 0, 1, (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) ? 0x100 : 0x40, 0);
        ((WmPTag *)&D_8010B3BC[i][1])->len = 4;
        ((WmPTag *)&D_8010B3BC[i][1])->code = 0x64;
        ((WmPTag *)&D_8010B3BC[i][1])->code = ((WmPTag *)&D_8010B3BC[i][1])->code | 2;
        D_8010B3BC[i][1].x0 = D_8010B3BC[i][1].y0 = 0;
        D_8010B3BC[i][1].u0 = D_8010B3BC[i][1].v0 = 0;
        D_8010B3BC[i][1].clut = 0x780E;
        D_8010B3BC[i][1].w = 0x140;
        D_8010B3BC[i][1].h = 0xF0;
        ((WmPTag *)&D_8010B3BC[i][2])->len = 4;
        ((WmPTag *)&D_8010B3BC[i][2])->code = 0x64;
        ((WmPTag *)&D_8010B3BC[i][2])->code = ((WmPTag *)&D_8010B3BC[i][2])->code | 2;
        D_8010B3BC[i][2].x0 = D_8010B3BC[i][2].y0 = 0;
        D_8010B3BC[i][2].u0 = D_8010B3BC[i][2].v0 = 0;
        D_8010B3BC[i][2].clut = 0x780F;
        D_8010B3BC[i][2].w = 0x140;
        D_8010B3BC[i][2].h = 0xF0;
        func_80044A68(D_8010B434[i] + 0xC, 0, 1, (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) ? 0xA6 : 0x36, 0);
        func_80044A68(D_8010B434[i] + 0x18, 0, 1, (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) ? 0xA7 : 0x37, 0);
    }
    *D_8010B488 = 0xFF;
    *D_8010B494 = 0xFF;
    D_8010B484 = 0;
    D_8010B480 = 0;
    D_8010B47C = 0;
    D_8010B4A8 = 0;
    D_8010B4A4 = 0;
    *D_8010B4A0 = 0;
    D_8010B490 = 0;
    D_8010B48C = 0;
    D_8010B49C = 0x80;
    D_8010B498 = 0x80;
}

void func_800AFCC8(void) {
    s32 cur;
    s32 j;
    s32 *speed;

    cur = func_800A0BD4();
    speed = &D_8010B47C;
    for (j = 0; j < 3; j++) {
        D_8010B3BC[cur][j].r0 = D_8010B3BC[cur][j].g0 = D_8010B3BC[cur][j].b0 = D_8010B488[j];
        if (speed[j] != 0) {
            D_8010B488[j] += (j == 0) ? ((D_8010B488[0] + 0x80) * speed[0]) >> 8 : speed[j];
            if (D_8010B488[j] <= 0) {
                D_8010B488[j] = 0;
                speed[j] = 0;
            } else if (D_8010B488[j] >= D_8010B494[j]) {
                D_8010B488[j] = D_8010B494[j];
                speed[j] = 0;
            }
        }
        if (D_8010B488[j] != 0) {
            ((WmTag *)&D_8010B3BC[cur][j])->addr = ((WmTag *)D_800BD130)->addr;
            ((WmTag *)D_800BD130)->addr = (u32)&D_8010B3BC[cur][j];
            ((WmTag *)&D_8010B434[cur][j * 0xC])->addr = ((WmTag *)D_800BD130)->addr;
            ((WmTag *)D_800BD130)->addr = (u32)&D_8010B434[cur][j * 0xC];
        }
        if (D_8010B4A0[j] != 0) {
            if (--D_8010B4A0[j] == 0) {
                func_800B01C4(j);
            }
        }
    }
    D_8010B3BC[cur][1].u0 = func_80039A74((func_8003CEDC(-1) << 4) & 0xFF0) >> 3;
    D_8010B3BC[cur][1].v0 = *(u8 *)&D_8010B4A4 * 8;
    D_8010B3BC[cur][2].u0 = func_80039B40((func_8003CEDC(-1) << 4) & 0xFF0) >> 4;
    D_8010B3BC[cur][2].v0 = *(u8 *)&D_8010B4A8 * 4;
}

void func_800AFFBC(s32 arg0, s32 arg1) {
    s32 i;
    s32 mode;

    if (*D_8010B488 > 0) {
        D_8010B47C = -arg0;
        for (i = 0; i < 2; i++) {
            if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
                mode = 0xA6;
                if (arg1 == 1) {
                    mode = 0x126;
                }
            } else {
                mode = 0x36;
                if (arg1 == 1) {
                    mode = 0x56;
                }
            }
            func_80044A68(D_8010B434[i], 0, 1, mode, 0);
        }
    } else {
        D_8010B47C = 0;
    }
}

void func_800B0098(s32 arg0, s32 arg1) {
    s32 i;
    s32 mode;

    if (*D_8010B488 < *D_8010B494) {
        D_8010B47C = arg0;
        for (i = 0; i < 2; i++) {
            if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
                mode = 0xA6;
                if (arg1 == 1) {
                    mode = 0x126;
                }
            } else {
                mode = 0x36;
                if (arg1 == 1) {
                    mode = 0x56;
                }
            }
            func_80044A68(D_8010B434[i], 0, 1, mode, 0);
        }
    } else {
        D_8010B47C = 0;
    }
}

void func_800B017C(s32 arg0) {
    (&D_8010B47C)[arg0] = (D_8010B488[arg0] < D_8010B494[arg0]) << 4;
}

void func_800B01C4(s32 arg0) {
    (&D_8010B47C)[arg0] = -(D_8010B488[arg0] > 0) & ~0xF;
}

void func_800B0200(s32 arg0) {
    func_800B017C(arg0);
    D_8010B4A0[arg0] = 0x64;
}

s32 func_800B0240(void) {
    return D_8010B47C == 0;
}

void func_800B0250(void) {
    WmRect rect;
    WmRgb16 *p;
    WmRgb16 *end;
    u16 *src;
    s32 i;

    rect.x = 0;
    rect.y = 0x1E0;
    rect.w = 0x100;
    rect.h = 1;
    func_80044064(&rect, (s32)D_8010C0AC);
    func_80043DD8(0);
    src = D_8010C0AC;
    end = D_8010B4AC + 0x100;
    for (p = D_8010B4AC; p < end; p++) {
        p->r = (*src << 10) & 0x7C00;
        p->g = (*src << 5) & 0x7C00;
        p->b = *src & 0x7C00;
        src++;
    }
    for (i = 0; i < 0x100; i++) {
        D_8010BCAC[i] = ((s32 (*)(void))func_800ADFC0)() * 4;
    }
}

void func_800B0334(s32 arg0) {
    W4Vec v;
    W4Mat m;
    WmRect r;
    s32 flag;
    WmRgb16 *p;
    WmRgb16 *end;
    s32 *dp;
    u16 *o;
    s32 d;

    r.x = 0;
    r.y = arg0 + 0x1E0;
    r.w = 0x100;
    r.h = 1;
    m.m[0][0] = m.m[1][1] = m.m[2][2] = D_800C68A8[arg0] << 5;
    m.m[0][1] = m.m[0][2] = m.m[1][0] = m.m[1][2] = m.m[2][0] = m.m[2][1] = 0;
    m.t[0] = 0;
    m.t[1] = 0;
    m.t[2] = D_800C6868[arg0] << 5;
    func_8003B48C((M2C_UNK *)&m);
    func_8003B51C((M2C_UNK *)&m);
    o = D_8010C0AC;
    dp = D_8010BCAC;
    end = D_8010B4AC + 0x100;
    for (p = D_8010B4AC; p < end; p++) {
        func_8003BC6C((W4SVec *)p, &v, &flag);
        d = *dp++;
        v.vx += d;
        v.vy += d;
        v.vz += d;
        *o++ = ((v.vx >> 10) & 0x1F) | ((v.vy >> 5) & 0x3E0) | (v.vz & 0x7C00);
    }
    func_80044000(&r, D_8010C0AC);
}

void func_800B04AC(void) {
    s32 i;
    s32 j;
    WmFt4 *p;
    s16 tp;
    s32 k;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 12; j++) {
            p = (WmFt4 *)&D_8010C430[i][j];
            p->r0 = p->g0 = p->b0 = 0x80;
            ((u8 *)p)[3] = 9;
            p->code = 0x2C;
            if (j < 4) {
                p->clut = ((0x1E8 - j) << 6) | 4;
            } else if (j >= 8) {
                p->clut = ((0x1EC - j) << 6) | 4;
            } else {
                p->clut = 0x7904;
            }
            if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
                tp = 0xF;
            } else {
                tp = 0xF;
            }
            p->tpage = tp;
            if (j < 4) {
                p->u2 = (7 - j) * 16;
            } else if (j >= 8) {
                p->u2 = (0xB - j) * 16;
            } else {
                p->u2 = 0x30;
            }
            p->v0 = p->v1 = 0xE0;
            p->u2 = p->u0 = p->u2;
            p->v2 = p->v3 = p->v0 + 0xF;
            p->u1 = p->u3 = p->u0 + 0xF;
        }
    }
    D_8010C7F8 = 0;
    D_8010C7F4 = 0;
    D_8010C808 = 0;
    D_8010C804 = 0;
    D_8010C800 = 0;
    for (k = 0x28; k >= 0; k -= 8) {
        *(s32 *)((u8 *)D_8010C80C + k) = 0;
    }
}

void func_800B0670(void) {
    WQuad32 pos;
    WmS16x4 *p;

    func_800AA0E0(&pos);
    if (pos.c < 0x23A98) {
        for (p = D_8010C2AC; p < D_8010C2AC + 0x30; p++) {
            p->a = 0x2008;
            p->b = 0x6338;
            p->d = 0;
            p->c = 0;
        }
    } else {
        for (p = D_8010C2AC; p < D_8010C2AC + 0x30; p++) {
            p->a = 0x1D4C;
            p->b = 0x11F8;
            p->d = 0;
            p->c = 0;
        }
    }
    D_8010C7F0 = 0x400;
    D_8010C42C = D_8010C2AC;
}

void func_800B075C(void) {
    if (D_8010C804 == 0) {
        func_800B0670();
        D_8010C804 = 1;
    }
}

s32 func_800B0794(void) {
    WQuad32 sp10;
    s32 r;
    u32 t;

    func_800AA0E0(&sp10);
    r = 0;
    if (D_8010C804 != 0) {
        if ((u32)(sp10.a - 0x30000) <= 0xFFFF) {
            t = sp10.c - 0x1C000;
            r = t <= 0xFFFF;
        }
    }
    return r;
}

s32 func_800B0800(void) {
    return D_8010C808;
}

void func_800B0810(void) {
    W4SVec v;
    WQuad32 pos;
    WmS16x4 *p;
    s16 best;
    s16 score;
    s16 t;
    s16 off;
    s32 d;
    s32 e;
    s32 t2;
    s32 t0;

    v.vy = 0;
    v.vx = 0;
    v.vz = 0x64;
    func_800AE0BC(&v, D_8010C7F0);
    p = D_8010C42C + 1;
    if (p >= (WmS16x4 *)&D_8010C42C) {
        p = (WmS16x4 *)&D_8010C42C - 0x30;
    }
    p->a = (u16)D_8010C42C->a + v.vx;
    p->b = (u16)D_8010C42C->b + v.vz;
    p->c = D_8010C7F0;
    if ((func_800A91A4(7) != 0 || func_800A9240() != 0) && func_800A9A44() == 7) {
        func_800AA0E0(&pos);
        pos.a -= 0x34000;
        pos.c -= 0x20000;
        d = (u16)p->a - pos.a;
        if (d <= 0) {
            d = pos.a - (u16)p->a;
        }
        e = (u16)p->b - pos.c;
        if (e > 0) {
            t0 = d + e;
        } else {
            t0 = d + (pos.c - (u16)p->b);
        }
        best = t0;
        if (best >= 0x12D) {
            off = 0x493E0 / best;
        } else {
            off = 0;
        }
        v.vy = 0;
        v.vx = 0;
        v.vz = 0x64;
        func_800AE0BC(&v, off + (u16)D_8010C7F0);
        d = (u16)D_8010C42C->a + v.vx - pos.a;
        if (d <= 0) {
            d = pos.a - ((u16)D_8010C42C->a + v.vx);
        }
        t0 = (u16)D_8010C42C->b + v.vz;
        if (t0 - pos.c > 0) {
            t2 = d + (t0 - pos.c);
        } else {
            t2 = d + (pos.c - t0);
        }
        score = t2;
        if (score < best) {
            p->a = (u16)D_8010C42C->a + v.vx;
            p->b = (u16)D_8010C42C->b + v.vz;
            p->c = off + (u16)D_8010C7F0;
        }
        v.vy = 0;
        v.vx = 0;
        v.vz = 0x64;
        func_800AE0BC(&v, (u16)D_8010C7F0 - off);
        d = (u16)D_8010C42C->a + v.vx - pos.a;
        if (d <= 0) {
            d = pos.a - ((u16)D_8010C42C->a + v.vx);
        }
        t0 = (u16)D_8010C42C->b + v.vz;
        if (t0 - pos.c > 0) {
            t2 = d + (t0 - pos.c);
        } else {
            t2 = d + (pos.c - t0);
        }
        score = t2;
        if (score < best) {
            p->a = (u16)D_8010C42C->a + v.vx;
            p->b = (u16)D_8010C42C->b + v.vz;
            p->c = (u16)D_8010C7F0 - off;
        }
        D_8010C7F0 = p->c;
    } else if (D_8010C7F4-- <= 0) {
        D_8010C7F4 = (((s32 (*)(void))func_800ADFC0)() + 0x40) >> 2;
        D_8010C7F8 = (((s32 (*)(void))func_800ADFC0)() - 0x80) >> 2;
    }
    D_8010C42C = p;
    t = (u16)D_8010C7F0 + (u16)D_8010C7F8;
    D_8010C7F0 = t;
    if (t < 0) {
        D_8010C7F0 = t + 0x1000;
    } else if (t >= 0x1000) {
        D_8010C7F0 = t - 0x1000;
    }
}

void func_800B0BF4(void) {
    WQuad32 pos;
    WmS16x4 *p;
    WmSpr28 *s;
    s32 idx;
    s32 dx;
    s32 dz;
    s32 t;

    idx = func_800A0BD4();
    func_800A6B8C(&pos);
    p = D_8010C42C - 1;
    if (p < D_8010C2AC) {
        p = &D_8010C2AC[0x2F];
    }
    for (s = D_8010C430[idx]; s < D_8010C430[idx] + 12; s++) {
        p += 4;
        if (p >= D_8010C2AC + 0x30) {
            p -= 0x30;
        }
        if (func_800A8300(((u16)p->a >> 13) + 0x1A, ((u16)p->b >> 13) | 0x10) != 0) {
            t = pos.a - 0x34000;
            dx = (u16)p->a - t;
            if (dx >= -30000 && dx <= 30000) {
                s->x = dx;
                t = pos.c - 0x20000;
                dz = (u16)p->b - t;
                if (dz >= -30000 && dz <= 30000) {
                    s->z = dz;
                    func_800B59F4(300, 300, p->d - func_800AA8F8(s->x, s->z) * 4, p->c + 0x800, s, 0);
                }
            }
        }
    }
}

void func_800B0D98(u8 *arg0) {
    W4Pos pos;
    s16 v[4];
    s16 bx;
    s16 bz;

    if (func_800B0794() != 0) {
        pos.x = (u16)D_8010C42C->a + 0x34000;
        pos.z = (u16)D_8010C42C->b + 0x20000;
        func_800A6884(&pos, v, &bx, &bz);
        if (bx == *(s16 *)(arg0 + 0x10) && bz == *(s16 *)(arg0 + 0x12)) {
            D_8010C800 = func_800A19FC(arg0, v, D_8010C80C, &D_8010C42C->d, 0, 0, 100);
            if (D_8010C800 == 0) {
                D_8010C42C->d = 0;
            }
        }
    }
}

void func_800B0E84(void) {
    WQuad32 pos;
    WmS16x4 *p;
    s32 dx;
    s32 dz;
    s32 d;
    s32 m;
    s32 r;
    s32 t;

    func_800AA0E0(&pos);
    if (func_800B0794() != 0) {
        if (D_8010C800 == 0) {
            p = D_8010C42C;
            p->a = ((u16)p->a * 63 + 10000) >> 6;
            p->b = ((u16)p->b * 63 + 15000) >> 6;
            D_8010C7F0 = p->c + 0x800;
        }
        D_8010C800 = 0;
        dx = pos.a - (u16)D_8010C42C->a;
        d = dx - 0x34000;
        if (d <= 0) {
            d = 0x34000 - dx;
        }
        dz = pos.c - (u16)D_8010C42C->b;
        if (dz - 0x20000 > 0) {
            t = d + (dz - 0x20000);
        } else {
            t = d + (0x20000 - dz);
        }
        if (t > 200 || (func_800A91A4(7) == 0 && func_800A9240() == 0)) {
            func_800B0810();
        } else {
            func_800ABA18(7);
            D_8010C804 = 0;
        }
        func_800B0BF4();
    }
    m = func_800A9A44() & 0x1F;
    r = ((s32 (*)(void))func_800A9174)();
    if (r != D_8010AE50) {
        m = D_8010AE4C;
    }
    D_8010AE50 = r;
    if (m == 7 && D_8010AE4C == 0) {
        D_8010C808 = pos.a > 0x36000;
    }
    D_8010AE4C = m;
}

void func_800B104C(void) {
    D_8010CA20 = 0;
    D_8010CA1C = 0;
    D_8010CA78 = 0;
    D_8010CA74 = 0;
    D_800BD144 = 0;
    D_8010CAF0 = 0;
    D_8010CA8C = 0;
    D_8010CAC8 = 0;
    D_8010CAC4 = 0;
    D_8010CAC0 = 0;
    D_8010CAF4 = 0;
}

void func_800B10AC(arg0) {
    WmEntList *obj;
    WmEntList **p;
    WmEntB *e;

    obj = (WmEntList *)arg0;
    if (obj != NULL) {
        for (p = (WmEntList **)D_8010CA24; p < (WmEntList **)D_8010CA74; p++) {
            if (*p == obj) {
                break;
            }
        }
        if (p < (WmEntList **)D_8010CA74) {
            return;
        }
        if ((WmEntList **)D_8010CA74 >= (WmEntList **)&D_8010CA74) {
            func_800A0B40(0x47);
        }
        p = (WmEntList **)D_8010CA74;
        D_8010CA74 = (s32)(p + 1);
        *p = obj;
        for (e = obj->ents; e < obj->ents + obj->count; e++) {
            e->fB &= ~0x40;
        }
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B11C4);

s32 func_800B1650(u8 a, u8 b, u8 c) {
    WQuad32 q;
    W4SVec *v;

    v = (*(WmBlkV **)D_8010CA1C)->verts;
    if (D_8010CAF8 != 0) {
        q.a = 0x3A681;
        q.c = 0x2195F;
        return ((q.a - ((v[a].vx + v[b].vx) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bx << 13)) > 0 ? (q.a - ((v[a].vx + v[b].vx) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bx << 13)) : -(q.a - ((v[a].vx + v[b].vx) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bx << 13))) + ((q.c - ((v[a].vz + v[b].vz) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bz << 13)) > 0 ? (q.c - ((v[a].vz + v[b].vz) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bz << 13)) : -(q.c - ((v[a].vz + v[b].vz) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bz << 13))) < ((q.a - ((v[b].vx + v[c].vx) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bx << 13)) > 0 ? (q.a - ((v[b].vx + v[c].vx) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bx << 13)) : -(q.a - ((v[b].vx + v[c].vx) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bx << 13))) + ((q.c - ((v[b].vz + v[c].vz) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bz << 13)) > 0 ? (q.c - ((v[b].vz + v[c].vz) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bz << 13)) : -(q.c - ((v[b].vz + v[c].vz) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bz << 13)));
    }
    func_800AA0E0(&q);
    return ((q.a - ((v[a].vx + v[b].vx) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bx << 13)) > 0 ? (q.a - ((v[a].vx + v[b].vx) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bx << 13)) : -(q.a - ((v[a].vx + v[b].vx) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bx << 13))) + ((q.c - ((v[a].vz + v[b].vz) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bz << 13)) > 0 ? (q.c - ((v[a].vz + v[b].vz) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bz << 13)) : -(q.c - ((v[a].vz + v[b].vz) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bz << 13))) > ((q.a - ((v[b].vx + v[c].vx) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bx << 13)) > 0 ? (q.a - ((v[b].vx + v[c].vx) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bx << 13)) : -(q.a - ((v[b].vx + v[c].vx) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bx << 13))) + ((q.c - ((v[b].vz + v[c].vz) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bz << 13)) > 0 ? (q.c - ((v[b].vz + v[c].vz) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bz << 13)) : -(q.c - ((v[b].vz + v[c].vz) >> 1) - ((*(WmBlkV **)D_8010CA1C)->bz << 13)));
}

void func_800B190C(void) {
    s32 r;
    u8 *s;
    s32 t;
    s32 v;
    s32 p;

    r = 1;
    if (D_8010CA1C != 0 && D_8010CA78 == 0 && (D_800BD144 == 0 || D_8010CAF8 != 0)) {
        s = ((WmTriF *)D_8010CA1C)->idx;
        D_800BD144 = (s32)s;
        switch (((WmTriF *)D_8010CA1C)->f8 & 7) {
        case 0:
            t = func_800B2304((WmTri *)D_8010CA1C);
            ((WmTriF *)D_8010CA1C)->f8 |= t;
            switch (t) {
            case 1:
                r = func_800B11C4(s[0], s[1]);
                break;
            case 2:
                r = func_800B11C4(s[1], s[2]);
                break;
            case 4:
                r = func_800B11C4(s[2], s[0]);
                break;
            }
            break;
        case 6:
            ((WmTriF *)D_8010CA1C)->f8 = 7;
            r = func_800B11C4(s[0], s[1]);
            break;
        case 5:
            ((WmTriF *)D_8010CA1C)->f8 = 7;
            r = func_800B11C4(s[1], s[2]);
            break;
        case 3:
            ((WmTriF *)D_8010CA1C)->f8 = 7;
            r = func_800B11C4(s[2], s[0]);
            break;
        case 4:
            if (func_800B1650(s[0], s[1], s[2]) != 0) {
                ((WmTriF *)D_8010CA1C)->f8 = 5;
                r = func_800B11C4(s[0], s[1]);
            } else {
                ((WmTriF *)D_8010CA1C)->f8 = 6;
                r = func_800B11C4(s[1], s[2]);
            }
            break;
        case 1:
            if (func_800B1650(s[1], s[2], s[0]) != 0) {
                ((WmTriF *)D_8010CA1C)->f8 = 3;
                r = func_800B11C4(s[1], s[2]);
            } else {
                ((WmTriF *)D_8010CA1C)->f8 = 5;
                r = func_800B11C4(s[2], s[0]);
            }
            break;
        case 2:
            if (func_800B1650(s[2], s[0], s[1]) != 0) {
                ((WmTriF *)D_8010CA1C)->f8 = 6;
                r = func_800B11C4(s[2], s[0]);
            } else {
                ((WmTriF *)D_8010CA1C)->f8 = 3;
                r = func_800B11C4(s[0], s[1]);
            }
            break;
        case 7:
            D_8010CA1C = D_8010CA1C - 0xC;
            if ((u32)D_8010CA1C < (u32)&D_8010C83C) {
                r = 4;
            }
            break;
        }
    } else {
        if (D_8010CA78 < 0) {
            D_8010CA78 = 0;
            D_8010CA1C = D_8010CA1C - 0xC;
            if ((u32)D_8010CA1C < (u32)&D_8010C83C) {
                r = 4;
            }
        } else {
            D_8010CA78 = 0;
            if (D_8010CA1C != 0) {
                r = 3;
            }
        }
    }
    if ((u32)(r - 3) < 2) {
        p = D_8010CA1C;
        D_8010CA1C = 0;
        D_8010CA20 = p;
        if ((u32)p >= (u32)&D_8010CA1C) {
            D_8010CA20 = p - 0xC;
        }
        v = 3;
        if (r == 3) {
            v = 2;
        }
        D_8010CA8C = v;
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B1C80);

void func_800B21E4(s32 arg0, u8 *arg1) {
    WQuad32 pos;
    s32 *p;

    if (D_8010CA8C == 0 || D_8010CA8C == 2 || D_8010CA8C == 3) {
        p = &D_8010C83C;
        D_8010CA1C = (s32)p;
        *p = arg0;
        D_8010C840 = arg1;
        D_8010C844 = 0;
        D_8010CA20 = 0;
        D_8010CA78 = 0;
        D_8010CA74 = (s32)D_8010CA24;
        func_800B10AC();
        if (arg1 != NULL) {
            arg1[0xB] |= 0x40;
        }
        D_800BD144 = 0;
        D_8010CA8C = 1;
        func_800AA0E0(&pos);
        D_8010CAF8 = pos.a >= 0x36000 && pos.a < 0x40000 && pos.c >= 0x1C000 && pos.c < 0x26000;
    }
}

void func_800B22E4(void) {
    func_800B190C();
}

s32 func_800B2304(WmTri *arg0) {
    W4Vec c;
    W4Vec m;
    W4Vec q;
    u8 *idx;
    s16 (*v)[4];
    s32 best;
    s32 ref;
    s32 d;
    s32 e;
    s32 x;
    s32 z;

    idx = arg0->idx;
    v = arg0->mesh->verts;
    best = 1;
    func_800A1D14();
    c.vx = x = (v[idx[0]][0] + v[idx[1]][0] + v[idx[2]][0]) / 3;
    c.vz = z = (v[idx[0]][2] + v[idx[1]][2] + v[idx[2]][2]) / 3;
    if (D_8010CAF8 != 0) {
        q.vx = (arg0->mesh->f10 << 13) + x;
        q.vz = (arg0->mesh->f12 << 13) + z;
        m.vx = 0x3A681;
        m.vz = 0x2195F;
        ref = func_800AE47C(&q, &m);
    } else {
        ref = func_800A1D14();
    }
    m.vx = (v[idx[0]][0] + v[idx[1]][0]) >> 1;
    m.vz = (v[idx[0]][2] + v[idx[1]][2]) >> 1;
    d = (func_800AE47C(&c, &m) - ref) & 0xFFF;
    if (d >= 0x800) {
        d = 0x1000 - d;
    }
    m.vx = (v[idx[1]][0] + v[idx[2]][0]) >> 1;
    m.vz = (v[idx[1]][2] + v[idx[2]][2]) >> 1;
    e = (func_800AE47C(&c, &m) - ref) & 0xFFF;
    if (e >= 0x800) {
        e = 0x1000 - e;
    }
    if (e < d) {
        d = e;
        best = 2;
    }
    m.vx = (v[idx[2]][0] + v[idx[0]][0]) >> 1;
    m.vz = (v[idx[2]][2] + v[idx[0]][2]) >> 1;
    e = (func_800AE47C(&c, &m) - ref) & 0xFFF;
    if (e >= 0x800) {
        e = 0x1000 - e;
    }
    if (e < d) {
        best = 4;
    }
    return best;
}

void func_800B2638(WmTri *arg0, s32 *arg1) {
    s16 (*v)[4];
    u8 *idx;
    WmMesh *m;

    if (arg1 != NULL) {
        idx = arg0->idx;
        m = arg0->mesh;
        v = m->verts;
        arg1[0] = (v[idx[0]][0] + v[idx[1]][0] + v[idx[2]][0]) / 3 + (m->f10 << 13);
        arg1[1] = 0;
        arg1[2] = (v[idx[0]][2] + v[idx[1]][2] + v[idx[2]][2]) / 3 + (arg0->mesh->f12 << 13);
    }
}

void func_800B271C(s32 arg0) {
    s32 v[3];
    s32 i;
    s32 r;

    if (D_8010CA8C == 2) {
        r = ((s32 (*)(void))func_800A9154)();
        if (r != 0x29) {
            i = (r == 0x2A) * 2;
        } else {
            i = 1;
        }
        switch (arg0) {
        case 1:
            (&D_8010CAC0)[i] = D_8010CA20;
            (&D_8010CACC)[i] = 5;
            func_800B2638((WmTri *)(&D_8010CAC0)[i], v);
            func_800A9D5C((s32)v);
            break;
        case 2:
            (&D_8010CAC0)[i] = (u32)&D_8010C854 < (u32)D_8010CA20 ? (s32)&D_8010C854 : D_8010CA20;
            (&D_8010CACC)[i] = 7;
            func_800B2638((WmTri *)(&D_8010CAC0)[i], v);
            func_800A9D5C((s32)v);
            break;
        case 3:
            (&D_8010CAC0)[i] = (u32)&D_8010C83C < (u32)D_8010CA20 ? (s32)&D_8010C83C : D_8010CA20;
            func_800A993C(4);
            func_800B2638((WmTri *)(&D_8010CAC0)[i], v);
            func_800A9D5C((s32)v);
            (&D_8010CACC)[i] = 7;
            break;
        }
        D_8010CAF0 = arg0;
    }
}

void func_800B28CC(s32 arg0) {
    s32 var_a0;

    if (D_8010CAF0 != 3) {
        if (arg0 != 1) {
            var_a0 = 0x26;
            if (arg0 == 2) {
                var_a0 = 0x2A;
            }
        } else {
            var_a0 = 0x29;
        }
    } else {
        var_a0 = 4;
    }
    func_800A993C(var_a0);
    switch (D_8010CAF0) {
    case 3:
        func_800A8FA0();
        D_8010CAF0 = 0;
        return;
    case 1:
        if (func_800A8F48() != 0) {
            func_800A9110();
            func_800BBD0C();
            return;
        }
        func_800AB988(((s32 (*)(void))func_800A9154)(), 5);
        return;
    case 2:
        func_800A9018();
        func_800A8FA0();
        return;
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B29CC);

void func_800B2E90(void) {
    func_800B22E4();
    if (D_8010CAF4 != 0) {
        if (D_8010CA8C == 3) {
            D_8010CAF4 = 0;
            D_8010CA8C = 0;
            func_800A2108(1, 5);
        } else if (D_8010CA8C == 2) {
            func_800A1D54(1);
            func_800A45C4(0x1770);
            func_800A45D4(0x5DC);
            func_800ABA18(8);
            D_8010CAF4 = 0;
        }
    }
    if ((D_8010CAF0 == 3) && ((u32) (D_8010CA8C - 2) < 2U) && (D_8010CACC == 0) && (D_8010CAD0 == 0)) {
        func_800B271C(3);
    }
    func_800B29CC();
}

void func_800B2F94(s32 arg0) {
    D_8010CAF0 = arg0;
}

s32 func_800B2FA4(void) {
    if (D_8010CA8C != 2) {
        return -(D_8010CA8C == 3);
    }
    return 1;
}

s32 func_800B2FD0(void) {
    s32 var_v1;

    var_v1 = 0;
    if ((D_8010CACC != 0) || (D_8010CAD0 != 0) || (D_8010CAD4 != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_800B3018(void) {
    D_8010CAF4 = 1;
    if (D_8010CA8C != 1) {
        D_8010CA8C = 0;
    }
}

void func_800B3044(s16 arg0) {
    D_8010CAFC = arg0;
    D_8010CB10 = 0;
    D_8010CB0C = 0;
    D_8010CB08 = 0;
    D_8010CB04 = 0;
    D_8010CB00 = 0;
}

s16 func_800B307C(s32 arg0, s32 arg1) {
    WQuad32 q;
    W4SVec v;
    s16 x;
    s16 neg;
    s32 n;

    x = func_800A1D14();
    if (D_8010CB04 == D_8010CB08) {
        D_8010CB10 = func_800A97A8() + x;
        func_800B0200(1);
        func_800B0200(2);
    } else if (D_8010CB04 < D_8010CB08) {
        func_800A94D0(D_8010CB10 - x);
    }
    n = 0;
    if (arg0 != 0 || D_8010CB04 < D_8010CB08) {
        n = 1;
    }
    D_8010CB04 -= n;
    if (D_8010CB04 <= 0) {
        D_8010CB04 = D_8010CB0C = ((s32 (*)(void))func_800ADFC0)() + 0x80;
        D_8010CB08 = (((s32 (*)(void))func_800ADFC0)() >> 3) + 0x40;
        D_8010CB00 = ((((s32 (*)(void))func_800ADFC0)() & 2) - 1) * 16;
    }
    if (D_8010CB04 >= D_8010CB08) {
        if (arg1 != 0) {
            if (func_800A993C(D_8010CAFC + 0x15) == 0) {
                func_800A8A1C();
                func_800A9334(D_8010CAFC + 0x15);
            }
            neg = -x;
            v.vy = 0;
            v.vx = 0;
            v.vz = 300;
            D_8010CAFC = (D_8010CAFC + 1) % 3;
            func_800AE0BC(&v, neg);
            func_800AA0E0(&q);
            q.a += v.vx;
            q.c += v.vz;
            func_800A9D5C((s32)&q);
            func_800A94F4(neg);
            func_800A90EC();
        }
    }
    if (D_8010CB04 < D_8010CB08) {
        return D_8010CB00;
    }
    return 0;
}

s16 func_800B32F0(void) {
    return D_8010CAFC;
}

void func_800B3300(u32 arg0) {
    D_800C68EE = arg0 & 0xFF;
    D_800C6902 = (arg0 >> 8) & 0xFF;
    D_800C6916 = (arg0 >> 0x10) & 0xFF;
    D_8010CB14 = (s32) (arg0 >> 0x18);
    D_8010CB1C = 0;
    D_8010CB18 = 0;
}

s32 func_800B3350(void) {
    return D_800C68EE | (D_800C6902 << 8) | (D_800C6916 << 0x10) | (D_8010CB14 << 0x18);
}

u8 *func_800B338C(s16 arg0, s16 arg1) {
    u8 *p;

    if (arg0 != 5 || arg1 != 0x12) {
        if (arg0 != 4 || arg1 != 0x11) {
            p = NULL;
            if (arg0 == 4 && arg1 == 0xE) {
                p = D_800C6910;
            }
        } else {
            p = D_800C68FC;
        }
    } else {
        p = D_800C68E8;
    }
    return p;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B3418);

void func_800B37E0(s32 *arg0, s32 *arg1) {
    if (arg0 != NULL) {
        *arg0 += D_8010CB18;
    }
    if (arg1 != NULL) {
        *arg1 += D_8010CB1C;
    }
}

void func_800B3828(void) {
    W4Pos pos;
    s16 bx;
    s16 bz;
    WmE14 *e;

    if (func_800A9A44() == 0xE && (func_8001C8D4() & 0xF000)) {
        func_800AA0E0((WQuad32 *)&pos);
        func_800A6884(&pos, NULL, &bx, &bz);
        e = (WmE14 *)func_800B338C(bx, bz);
        if (e != NULL && e->f6 < 100) {
            e->f6 += 10;
        }
        func_800B65E0(0xCB);
    }
    for (e = (WmE14 *)D_800C68E8; e < (WmE14 *)D_800C68E8 + 3; e++) {
        e->f6 -= e->f6 > 0;
        if (e->f6 == 1) {
            func_800B65E0(-0xCB);
        }
    }
}

void func_800B392C(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 31; i++) {
        D_8010CB24[i].next = &D_8010CB24[i + 1];
    }
    D_8010D930 = 0;
    D_8010D9A4 = D_8010CB24;
    D_8010D9B0 = 0;
    D_8010D9AC = 0;
    D_8010D9A8 = 0;
    D_8010D9B4 = 0;
    for (j = 1; j >= 0; j--) {
        D_8010D9B8[j][2] = 0;
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B39B4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B3C40);

void func_800B40B4(void) {
    WQuad32 pos;
    W4SVec v;
    W4SVec rot;
    W4Mat m1;
    W4Mat m2;
    W4Mat m3;
    WmEnt74 *e;
    s32 dx;
    s32 dy;
    s32 dz;
    W4Mat *m;

    rot.vx = 0;
    rot.vy = -func_800A1D14();
    rot.vz = 0;
    func_8003C21C(&rot, &m3);
    rot.vx = -func_800A2078();
    func_8003C21C(&rot, &m2);
    func_800A6B8C(&pos);
    for (e = (WmEnt74 *)D_8010D9A8; e != NULL; e = e->next) {
        dx = e->x - pos.a;
        dy = e->y - *(s32 *)&D_80116508;
        dz = e->z - pos.c;
        if (dx > -30000 && dx < 30000 && dz > -30000 && dz < 30000) {
            v.vx = dx;
            v.vy = dy - func_800AA8F8(dx, dz);
            v.vz = dz;
            if (e->f1E != 0) {
                rot.vz = 0;
                rot.vx = 0;
                rot.vy = e->f1A;
                func_8003BF8C(&rot, &m1);
                m = &m1;
            } else {
                m = &m2;
            }
            func_8003B48C((M2C_UNK *)m);
            func_800B3C40(e->prim[func_800A0BD4()], &D_800C6A10[e->f1C], &v, e->f1E);
        }
    }
}

void func_800B4244(void) {
    W4Fx *p;
    W4Fx *prev;
    W4Ent0Cb *e;
    u8 *c;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 t7;
    u8 v1;
    u8 v5;
    u8 v6;
    u8 v7;
    u8 v4;

    prev = NULL;
    p = (W4Fx *)D_8010D9A8;
    if (p != NULL) {
        do {
            c = (u8 *)p + (func_800A0BD4() * 0x28 + 0x24);
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            p->vy -= p->f1F;
            e = &D_800C6A10[p->f1C];
            if (e->f1 == 2) {
                t1 = p->f20 - 1;
                p->f20 = t1;
                c[6] = t1;
                c[5] = t1;
                c[4] = t1;
            } else {
                switch (e->f1 & 0x1C) {
                case 4:
                    t2 = p->f20 - 0xC;
                    p->f20 = t2;
                    if ((s16)t2 < 0) {
                        p->f20 = 0;
                    }
                    v1 = p->f20;
                    c[6] = v1;
                    c[5] = v1;
                    c[4] = v1;
                    v4 = e->f3 + 0x10;
                    goto tail;
                case 8:
                    if (p->f10 == 0) {
                        t3 = p->f20 + 8;
                        p->f20 = t3;
                        c[6] = t3;
                        c[5] = t3;
                        c[4] = t3;
                        if ((u8)t3 >= 0x80) {
                            p->f10 = 1;
                        }
                    } else {
                        t4 = p->f20 - 8;
                        p->f20 = t4;
                        if ((s16)t4 < 0) {
                            p->f20 = 0;
                        }
                        v5 = p->f20;
                        c[6] = v5;
                        c[5] = v5;
                        c[4] = v5;
                    }
                    break;
                case 12:
                    if (p->f10 == 0) {
                        p->f10 = 1;
                        p->vy = 0xC8;
                        p->f1F = 0x1E;
                    }
                    break;
                case 16:
                    t5 = p->f20 - 0x10;
                    p->f20 = t5;
                    if ((s16)t5 < 0) {
                        p->f20 = 0;
                    }
                    v6 = p->f20;
                    c[6] = v6;
                    c[5] = v6;
                    c[4] = v6;
                    break;
                case 20:
                    t4 = p->f20 - 8;
                    p->f20 = t4;
                    if ((s16)t4 < 0) {
                        p->f20 = 0;
                    }
                    v7 = p->f20;
                    c[6] = v7;
                    c[5] = v7;
                    c[4] = v7;
                    break;
                case 24:
                    t7 = e->f3;
                    if (e->f2 < 0x20) {
                        if (e->f2 & 0xF) {
                            v4 = t7 + 3;
                        } else {
                            v4 = t7 - 5;
                        }
                    } else {
                        v4 = t7;
                    }
                tail:
                    e->f3 = v4;
                    e->f2 = v4;
                    break;
                }
            }
            if (--p->f1D == 0) {
                if ((p->f1D = D_800C6A10[++p->f1C].f0) & 0x80) {
                    if ((e->f1 & 0x1C) == 0x18) {
                        for (;;) {
                            if ((p->f1D = D_800C6A10[--p->f1C].f0) & 0x80) {
                                break;
                            }
                        }
                        p->f1D &= 0x7F;
                    } else {
                        if (prev != NULL) {
                            prev->next = p->next;
                        } else {
                            D_8010D9A8 = (s32)p->next;
                        }
                        p->next = (W4Fx *)D_8010D9AC;
                        D_8010D9AC = (s32)p;
                        if (D_8010D9B0 == 0) {
                            D_8010D9B0 = (s32)p;
                        }
                        if (prev != NULL) {
                            p = prev->next;
                        } else {
                            p = (W4Fx *)D_8010D9A8;
                        }
                        continue;
                    }
                }
            }
            prev = p;
            p = p->next;
        } while (p != NULL);
    }
    D_8010D9B4 += 1;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B45DC);

void func_800B5274(void) {
    W4Scratch *s;
    W4Ent0Cb *e;

    s = (W4Scratch *)0x1F800000;
    s->f10 = 0;
    s->f12 = 0x32;
    s->f14 = 0;
    s->f20 = 0;
    func_800AA0E0(&s->q);
    s->f1C = 0;
    s->f1A = 0;
    s->f18 = 0;
    func_800B39B4(0, 0, 7, 0);
    e = &D_800C6A10[D_800C6940];
    e->f3 = 0x10;
    e->f2 = 0x10;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B5314);

void func_800B579C(s32 arg0, s8 arg1, s8 arg2, s8 arg3) {
    u8 *temp_a0;

    temp_a0 = D_8010D9B8[arg0];
    temp_a0[0] = arg1;
    temp_a0[1] = arg2;
    temp_a0[2] = arg3;
    temp_a0[3] = 0;
}

void func_800B57C0(s32 arg0) {
    D_8010D9B8[arg0][2] = 0;
}

void func_800B57DC(void) {
    WmTimer *t;

    if (D_8010D9AC != 0 && D_8010D9B0 != 0) {
        ((W4Ent74 *)D_8010D9B0)->next = D_8010D9A4;
        D_8010D9A4 = (W4Ent74 *)D_8010D9AC;
        D_8010D9B0 = 0;
        D_8010D9AC = 0;
    }
    func_800B40B4();
    func_800B4244();
    for (t = (WmTimer *)D_8010D9B8; t < (WmTimer *)D_8010D9B8 + 2; t++) {
        if (t->period > 0 && t->count-- < 2) {
            if (func_800A993C(t->id) != 0) {
                t->count = t->period;
                func_800B5314(((s32 (*)(s32))func_800A9194)(t->id), t->arg);
            } else {
                t->period = 0;
            }
        }
    }
}

void func_800B58F8(WmFt4 *arg0, WmRect *arg1) {
    s32 i;
    s16 tp;

    if (arg0 != 0 && arg1 != 0) {
        for (i = 0; i < 2; i++, arg0++) {
            ((u8 *)arg0)[3] = 9;
            arg0->code = 0x2E;
            arg0->r0 = arg0->g0 = arg0->b0 = 0x20;
            arg0->clut = 0x7CC4;
            if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
                tp = 0x129;
            } else {
                tp = 0x59;
            }
            arg0->tpage = tp;
            arg0->u0 = arg0->u2 = arg1->x;
            arg0->v0 = arg0->v1 = arg1->y;
            arg0->u1 = arg0->u3 = arg1->x + arg1->w;
            arg0->v2 = arg0->v3 = arg1->y + arg1->h;
        }
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B59F4);

void func_800B5C7C(WmObj90 *arg0) {
    s32 c;
    u32 s;
    s16 h;
    WmFt4 *p;

    c = 0x20 - ((arg0->f10 - arg0->f48) >> 8);
    if (c < 0) {
        c = 0;
    }
    p = &arg0->ft[func_800A0BD4()];
    p->r0 = p->g0 = p->b0 = c;
    s = 100 - ((arg0->f10 - arg0->f48) >> 6);
    switch (arg0->f50) {
    case 4:
    case 19:
    case 41:
    case 42:
        s = s * 3 / 2;
        h = s;
        break;
    case 3:
        h = s * 2;
        s = s * 6;
        break;
    case 11:
        h = s * 6;
        s = s * 12;
        break;
    default:
        h = s;
        break;
    }
    func_800B59F4(h, s, arg0->f48, arg0->f3C + (arg0->f3E + 0x800) + func_800A1DC0() * 4, (WmSpr28 *)p, 0);
}

void func_800B5DD8(WmHdr *arg0) {
    s8 *p;
    s32 i;
    s32 pad;

    p = (s8 *)(arg0->off + arg0->base);
    if (p != NULL) {
        for (i = 0; i < (s32)arg0->cnt; i++) {
            *p = 1;
            p += 0x20;
        }
    }
}

void func_800B5E28(WmHdr4 *arg0, WmObj5 *obj, s16 arg2, s16 arg3, s32 arg4) {
    W4Mat n;
    W4Mat m;
    u8 *buf;
    u8 kind;
    s32 v;
    s32 t;
    s32 *d;

    buf = (u8 *)0x1F800000;
    kind = 0xFF;
    if (obj != NULL) {
        kind = obj->f50;
    }
    func_800A36AC(arg0, arg4, &n, kind == ((s32 (*)(void))func_800A9174)());
    if (obj != NULL) {
        v = obj->f4A & 0x1F;
    } else {
        v = 0;
    }
    arg0->f1 = -1;
    if (((0x60400FA >> v) & 1 && func_800A1DE0() != 2 && kind != 3 && kind != 0x19) || kind == 0x1D) {
        arg0->f1 = 0xC;
    }
    if (obj != NULL) {
        if (obj->f5E == 0xC && arg0->f1 <= 0) {
            func_800B5DD8((WmHdr *)arg0);
        }
    }
    if (obj != NULL) {
        obj->f5E = arg0->f1;
    }
    t = arg0->f1;
    if (t > 0 && (arg0->f1 == 4 || arg0->f1 == 8 || arg0->f1 == 9 || arg0->f1 == 0xB || arg0->f1 == 0xC)) {
        m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x1000;
        m.t[0] = m.t[1] = m.t[2] = 0;
        m.m[0][1] = m.m[0][2] = m.m[1][0] = m.m[1][2] = m.m[2][0] = m.m[2][1] = 0;
        *(s32 *)0x1F800000 = 3;
        func_800C1490((u32)arg0, &m, arg2, arg3);
        d = (s32 *)arg0->f20;
        d[0] = ((s32 *)&n)[0];
        d[1] = ((s32 *)&n)[1];
        d[2] = ((s32 *)&n)[2];
        d[3] = ((s32 *)&n)[3];
        d[4] = ((s32 *)&n)[4];
        d[5] = ((s32 *)&n)[5];
        d[6] = ((s32 *)&n)[6];
        d[7] = ((s32 *)&n)[7];
    } else {
        *(s32 *)0x1F800000 = 3;
        func_800C1490((u32)arg0, &n, arg2, arg3);
    }
    if (obj != NULL) {
        if (arg0->f1 == 0xC) {
            buf[0] = 0;
            buf[1] = 0;
            buf[2] = 0;
            buf[3] = 0;
            buf[4] = 1;
            buf[5] = 0;
            buf[6] = 0;
            buf[7] = 0;
            buf[8] = -((obj->f10 - obj->f42 + obj->f44) >> 2);
            buf[9] = -((obj->f10 - obj->f42 + obj->f44) >> 2) >> 8;
            func_800C4148(arg0, buf);
            buf[0] = 1;
            buf[1] = 0;
            buf[2] = 0;
            buf[3] = 0;
            buf[4] = 0;
            buf[5] = 0;
            buf[6] = 0;
            buf[7] = 0;
            buf[8] = 0;
            buf[9] = 0;
            func_800C4148(arg0, buf);
        }
    }
    if (kind == 0x11 || kind == 0x12 || kind == 0x1A || kind == 0x1B || kind == 0x1C || kind == 0x1E) {
        v = 0xFF - ((n.t[2] - 0xFA0) >> 3);
        if (v < 0) {
            v = 0;
        } else if (v >= 0x100) {
            v = 0xFF;
        }
        buf[0] = 0x20;
        buf[1] = 0x20;
        buf[2] = 0x30;
        buf[3] = v;
        buf[4] = v;
        buf[5] = v;
        buf[6] = 0;
        buf[7] = 0;
        buf[8] = 0;
        buf[9] = 0;
        buf[10] = 0;
        buf[11] = 0;
        buf[12] = 0;
        buf[13] = 0;
        buf[14] = 0;
        buf[15] = 0xF0;
        buf[16] = 0;
        buf[17] = 0;
        buf[18] = 0;
        buf[19] = 0;
        buf[20] = 0;
        buf[21] = 0;
        buf[22] = 0;
        buf[23] = 0;
        buf[24] = 0;
        buf[25] = 0;
        buf[26] = 0;
        buf[27] = 0;
        buf[28] = 0;
        buf[29] = 0;
        func_800C5CD4(arg0, buf);
        ((void (*)(void))func_800AF110)();
    }
    func_800C08A8(arg0);
}

void func_800B624C(s16 arg0, s32 arg1) {
    WmHdr3 *h;
    s32 i;
    WmU16x4 *e;
    u8 *buf;
    u8 *f;

    h = func_800B6EFC(arg0);
    buf = (u8 *)0x1F800000;
    if (h != NULL) {
        h->pad0[1] = 2;
        i = 0;
        e = &D_800C70DC[(s16)arg1];
        f = &D_800C752C;
        do {
            buf[0] = e->x;
            buf[1] = e->x >> 8;
            buf[2] = e->y;
            buf[3] = e->y >> 8;
            buf[4] = e->z;
            buf[5] = e->z >> 8;
            buf[6] = 1;
            func_800C2450(h, buf);
            i++;
            *f = *f == 0;
        } while (i < 2);
    }
}

void func_800B6348(W4Hdr7 *arg0) {
    s32 i;
    s32 *src;

    src = (s32 *)arg0 + arg0->off[0] / 4;
    for (i = 0; i < 0x2000; i++) {
        D_8010D9C0[i] = src[i];
    }
    for (i = 0; i < 7; i++) {
        D_801159C0[i] = &D_8010D9C0[(arg0->off[i] - arg0->off[0]) / 4];
    }
    D_801159DC = 0;
    D_801159E0 = 0;
}

void func_800B63E0(s32 arg0) {
    D_801159DC = arg0;
}

void func_800B63F0(s32 arg0) {
    s16 *p;
    s16 v;

    if (D_801159DC != 0) {
        p = &D_8009A000;
        if (arg0 != 1) {
            if (D_801159E0 == 1) {
                v = 0x14;
            } else {
                v = 0x10;
            }
            *p = v;
        } else {
            *p = 0x18;
        }
        D_8009A008 = 4;
        D_8009A004 = (s32)D_801159C0[arg0 - 1];
        func_8002DA7C();
    }
    D_80116510 = D_801159E0;
    D_801159E0 = arg0;
}

void func_800B64A0(void) {
    func_800B63F0(D_801159E0);
}

s32 func_800B64C8(void) {
    return D_801159E0;
}

void func_800B64D8(s32 arg0) {
    D_8009A000 = 0x30;
    D_8009A004 = arg0;
    func_8002DA7C();
}

void func_800B650C(void) {
    s16 *p;

    p = &D_8009A000;
    *p = 0xF1;
    func_8002DA7C();
    *p = 0xE4;
    D_8009A004 = 0;
    func_8002DA7C();
    *p = 0xBC;
    D_8009A004 = 0;
    func_8002DA7C();
}

void func_800B6570(s32 arg0) {
    D_8009A000 = 0xC0;
    D_8009A004 = arg0;
    func_8002DA7C();
}

void func_800B65A4(s32 arg0, s32 arg1) {
    D_8009A000 = 0xBD;
    D_8009A004 = arg0;
    D_8009A008 = arg1;
    func_8002DA7C();
}

void func_800B65E0(s32 arg0) {
    s16 *p;

    if (D_8010CB20 < arg0) {
        D_8009A000 = 0x20;
        D_8010CB20 = arg0;
        D_8009A004 = 0x40;
        D_8009A008 = arg0;
        func_8002DA7C();
    } else if (arg0 == -D_8010CB20) {
        p = &D_8009A000;
        D_8010CB20 = 0;
        *p = 0xF1;
        func_8002DA7C();
        *p = 0xBC;
        D_8009A004 = 0;
        func_8002DA7C();
    }
}

void func_800B667C(void) {
    s32 i;

    for (i = 0; i < 43; i++) {
        D_801159E8[i] = -1;
        D_80115A14[i] = 0;
    }
    D_80115A40 = 0;
    D_80115A44 = 0;
    D_80115A50 = 0;
    D_80115A4C = 0;
    D_80115A48 = 0;
    D_80115A54 = 0;
    D_80115A64 = 0;
    D_80115A5C = 0;
    D_80115A60 = 0;
    D_80115A58 = 0;
    D_80115A68 = 0;
    D_800C80BC = D_80115A6C;
}

void func_800B6724(u32 arg0) {
    W4Mat m;
    u8 *buf;
    u8 *f;

    buf = (u8 *)0x1F800000;
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x1000;
    m.t[0] = m.t[1] = m.t[2] = 0;
    m.m[0][1] = m.m[0][2] = m.m[1][0] = m.m[1][2] = m.m[2][0] = m.m[2][1] = 0;
    *(s32 *)buf = 1;
    func_800C1490(arg0, &m, 0, 0);
    buf[0] = 0x40;
    buf[1] = 0x40;
    buf[2] = 0x40;
    buf[3] = 0x6E;
    buf[4] = 0x6E;
    buf[5] = 0x6E;
    buf[6] = 0xAA;
    buf[7] = 0xAA;
    buf[8] = 0xAA;
    buf[9] = 0x3C;
    buf[10] = 0x3C;
    buf[11] = 0x3C;
    buf[12] = 0x6D;
    buf[13] = 0xFD;
    buf[14] = 0x9B;
    buf[15] = 1;
    buf[16] = 0xC2;
    buf[17] = 0x0F;
    buf[18] = 0;
    buf[19] = 6;
    buf[20] = 0xEB;
    buf[21] = 0xF2;
    buf[22] = 0xD1;
    buf[23] = 0xF8;
    buf[24] = 0x98;
    buf[25] = 0xF4;
    buf[26] = 0x3E;
    buf[27] = 0xFA;
    buf[28] = 0x4C;
    buf[29] = 0xF6;
    buf[30] = 0;
    func_800C31F0(arg0, buf);
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 0;
    buf[5] = 0;
    buf[6] = 1;
    func_800C2450((WmHdr3 *)arg0, buf);
    f = &D_800C752C;
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 0;
    buf[5] = 0;
    buf[6] = 1;
    *f ^= 1;
    func_800C2450((WmHdr3 *)arg0, buf);
    *f ^= 1;
    ((void (*)(void))func_800AF110)();
}

void func_800B69A4(s16 arg0) {

    if (D_80115A60 == 0 && func_800ADC80(2) != 0) {
        D_80115A48 = 0;
        func_80033E74(D_800C74C4[arg0 * 2], D_800C74C4[arg0 * 2 + 1], 0x8014A600, (s32)func_800B6AEC);
        func_80034B44();
        D_80115A60 = 1;
    }
    D_80115A5C = arg0;
}

void func_800B6A4C(void) {
    W4File *f;
    u32 s;

    f = (W4File *)0x8014A600;
    func_800C0808((W4ImgHdr *)(&f->f4 + f->off8 / 4));
    s = f->f10;
    func_800BFBF0(s, 0x8014FC00, 0);
    func_800B6724(s);
    D_80115A48 = 1;
    D_801159EA = -1;
    D_801159E9 = -1;
    D_801159E8[0] = -1;
    D_801159E8[D_80115A5C] = 0;
}

void func_800B6AEC(void) {
    if (D_80115A60 != 0) {
        D_80115A60 = 0;
        func_800ADD4C(2);
        func_800B6A4C();
    }
}

void func_800B6B28(s16 arg0) {
    s32 a;
    s32 i;
    s32 j;
    s32 q;
    WmHdr3 *h;

    a = 0x80117000;
    for (i = 0; i < D_8013A800; i++) {
        a = func_800BFBF0(&D_8013A804[i], a, i);
    }
    for (i = 3; i < 0x20; i++) {
        D_801159E8[i] = D_800C7114[D_80115A58][i];
        if (D_801159E8[i] >= 0 && i == 0x18) {
            h = &D_8013A804[D_80115A00 - 1];
            q = h->off + h->base;
            for (j = 0; j < h->cnt; j++) {
                func_800C3DB0(q + j * 0x20, 1);
            }
        }
    }
    D_80115A4C = 1;
}

void func_800B6C84(void) {
    if (D_80115A60 == 0) {
        func_800A7F38();
        D_80115A40 = func_800A86C4(2);
        if (func_800ADC80(2) != 0) {
            D_80115A60 = 1;
            D_80115A50 = 0;
            func_80033E74(D_800C74DC, D_800C74E0, D_80115A40, (s32) func_800B6DCC);
            func_80034B44();
        }
    }
}

void func_800B6D10(void) {
    s32 i;
    u32 *p;

    p = (u32 *)D_80115A40;
    D_80115A50 = 1;
    D_80115A44 = (s32)&((u32 *)D_80115A40)[(p[2] >> 2) + 1];
    for (i = 0x20; i < 0x2B; i++) {
        D_801159E8[i] = i - 0x13;
        if (D_801159E8[i] >= 0 && i >= 0x29 && i < 0x2B) {
            func_800B624C(i, 0);
        }
    }
}

void func_800B6DCC(void) {
    if (D_80115A60 != 0) {
        D_80115A60 = 0;
        func_800ADD4C(2);
        func_800B6D10();
    }
}

void func_800B6E08(void) {
    s32 i;
    s8 *p;

    if (D_80115A50 != 0) {
        i = 0x2A;
        p = &D_80115A3E;
        D_80115A50 = 0;
        D_80115A64 = 3;
        do {
            *p = 0;
            i--;
            p--;
        } while (i >= 0);
        i = 0x20;
        do {
            D_801159E8[i] = -1;
            i++;
        } while (i < 0x2B);
    }
}

void func_800B6E78(void) {
    if (D_80115A60 != 0) {
        func_80034B44();
    }
    if (D_80115A50 != 0 && func_800A8CA4() == 0) {
        func_800B6E08();
    }
    if (D_80115A64 != 0) {
        if (--D_80115A64 == 0) {
            func_800A8048();
        }
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B6EFC);

void func_800B7104(s16 arg0) {
    D_80115A58 = (s32) arg0;
    func_800B6B28(arg0);
}

void func_800B7134(void) {
    func_8003408C();
    D_80115A60 = 0;
}

void func_800B715C(s32 arg0) {
    D_80115A68 = arg0;
}

s32 func_800B716C(void) {
    return D_80115A68;
}

s32 func_800B717C(void) {
    s32 temp_a0;
    s32 temp_v1;
    s32 var_v0;

    var_v0 = 0;
    if ((u16) D_8009D288 >= 0x3E8U) {
        if ((u16) D_8009D288 < 0x62CU) {
            temp_a0 = D_8009D302 & 1;
            if ((u16) D_8009D288 >= 0x654U) {
                return (temp_a0 | 2) + 1;
            }
            return temp_a0 + 1;
        }
        temp_v1 = (u16) D_8009D288 >= 0x654U;
        if (D_8009D60E & 0x10) {
            return (temp_v1 | 2) + 5;
        }
        var_v0 = temp_v1 + 5;
        
        return var_v0;
    }
    return var_v0;
}

s32 func_800B7200(void) {
    return (u32) (D_8009D288 - 0x3E8) < 0xC8U;
}

u8 func_800B7218(void) {
    return D_8009D686;
}

void func_800B7228(s32 *arg0, s32 *arg1, s32 arg2) {
    WQuad32 q;
    s32 i;
    s32 sum;
    u32 v;
    u8 *p;
    u16 *e;
    s32 *w;

    sum = 0;
    for (i = 0x380; i < 0x400; i++) {
        sum += ((u8 *)&D_8009D288)[i];
    }
    if (sum & 0xFF) {
        func_800A0B40(2);
    }
    if (arg0 != NULL) {
        D_8011626C = *arg0;
    } else {
        D_8011626C = 0;
    }
    if (arg1 != NULL) {
        D_80116270 = *arg1;
    } else {
        D_80116270 = 0;
    }
    v = ((u16)D_8009D680 >> 12) & 3;
    func_800A2088(v < 3 ? v : 0);
    if ((D_8011626C == 0 && D_80116270 == 0) || (u32)(D_8011626C - 1) < 2) {
        func_800A1D38((u16)D_8009D680 & 0xFFF);
    }
    p = (u8 *)&D_8009D680;
    func_800BC9E8(*(u16 *)p >> 14);
    func_800B787C(p - 0x2EF, p - 0xAA4, 0);
    func_800ADEA8(D_8009D264);
    func_800B3300(D_8009D67C);
    func_800A7E8C((u16)D_8009D63E);
    func_800A891C((s32 *)(p - 0x40));
    if (arg2 != 0) {
        D_8009D2A6 &= 0xFCFF;
    } else {
        func_800B3044((u8)D_8009D683);
        if (D_8011626C == 1) {
            i = 0;
            for (e = (u16 *)(p - 0x10); i < 3; i++) {
                if (*(s32 *)e != 0) {
                    func_800A8A1C();
                    func_800A9334(i + 0x15);
                    q.a = e[0];
                    q.b = 0;
                    q.c = e[1];
                    func_800A9D5C((s32)&q);
                }
                e += 2;
            }
        } else {
            w = (s32 *)(p - 0x10);
            for (i = 2; i >= 0; i--) {
                w[i] = 0;
            }
        }
    }
    func_800B7820();
}

void func_800B7480(void) {
    WQuad32 q;
    s32 i;
    s32 sum;
    s32 *p;

    if (func_800A1D04() == 0 && func_800A1DE0() != 3) {
        func_800A1D38(0);
    }
    D_8009D680 = (func_800A1D14() & 0xFFF) | ((func_800A1D04() << 12) & 0x3000) | (func_800BCA38() << 14);
    D_8009D685 = func_800A9174();
    if (D_8009D685 == 3 && func_800A92F8(func_800BBA0C()) != 0) {
        D_8009D685 = 0x2B;
    }
    func_800ADA08();
    ((u8 *)&D_8009D288)[0x3FE] = func_800A1DE0();
    D_8009D67C = func_800B3350();
    D_8009D63E = func_800A7E7C();

    if (((u8 *)&D_8009D288)[0x3FE] == 3) {
        D_8009D683 = func_800B32F0();
        p = (s32 *)&((u8 *)&D_8009D288)[0x3E8];
        for (i = 0; i < 3; i++) {
            if (func_800A993C(i + 0x15) != 0) {
                func_800AA098(&q);
                p[i] = (u16)q.a | (q.c << 16);
            } else {
                p[i] = 0;
            }
        }
    }
    sum = 0;
    for (i = 0x380; i < 0x3FF; i++) {
        sum += ((u8 *)&D_8009D288)[i];
    }
    D_8009D687 = -sum;
}

void func_800B7620(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 v;
    u16 *p;

    if (arg0 != NULL) {
        *arg0 = D_8011626C;
    }
    if (arg1 != NULL) {
        *arg1 = D_80116270;
    }
    if (arg2 != NULL) {
        v = D_80116274;
        if (D_80116278 != 0) {
            v |= 0x20000000;
        }
        *arg2 = v;
    }
    p = &D_8009D2A6;
    *p |= 0x300;
    func_800B7480();
}

void func_800B76A8(void) {
    u32 v;

    v = D_8009D685;
    if (v >= 3) {
        if (v >= 0x2B) {
            func_800A993C(0x13);
            func_800BBA5C();
            v = 3;
        }
        func_800A993C(v);
        func_800BBA5C();
        func_800A31C0(func_800A97A8());
    }
}

void func_800B7714(arg0) {
    W4Ent0C *e;

    e = &D_800BF5F0[((((arg0 >> 8) - 1) * 2) & 0x1FE) | (arg0 & 1)];
    M2C_SFIELD(&D_8009ABF4, u16 *, 2) = e->f6;
    M2C_SFIELD(&D_8009ABF4, u16 *, 4) = e->f0;
    M2C_SFIELD(&D_8009ABF4, u16 *, 6) = e->f2;
    D_8011626C = 0;
    D_80116270 = arg0;
    M2C_SFIELD(&D_8009ABF4, u16 *, 0x22) = e->f4;
    M2C_SFIELD(&D_8009ABF4, s16 *, 0x24) = e->f8;
}

void func_800B77A8(s32 arg0) {
    if (arg0 & 0x40000000) {
        func_800B7714(0x2100);
    }
    D_8011626C = 1;
    D_80116274 = arg0;
}

void func_800B77F4(s32 arg0) {
    *(volatile s32 *)&D_8009D268 = arg0;
    D_80116278 = 1;
    D_8009D2E7 = 1;
}

void func_800B7820(void) {
    D_80116278 = 0;
    D_8009D2E7 = 0;
}

void func_800B7838(void) {
    D_8011626C = 2;
    D_80116270 = 0;
    D_80116274 = 0;
}

s32 func_800B785C(void) {
    return D_8011626C;
}

s32 func_800B786C(void) {
    return D_80116270;
}

void func_800B787C(u8 *arg0, u8 *arg1, s32 arg2) {
    u32 old;
    u32 new;
    u32 bits;
    u32 i;
    u8 id;

    old = (1 << arg0[0]) | (1 << arg0[1]) | (1 << arg0[2]);
    new = (1 << arg1[0]) | (1 << arg1[1]) | (1 << arg1[2]);
    if (arg2 != 0) {
        func_800ADB30(old, new);
    }
    bits = old & ~new;
    for (i = 0; i < 3; i++) {
        if (bits & (1 << arg0[i])) {
            arg0[i] = 0xFF;
        }
    }
    bits = ~old & new;
    i = 0;
    id = 0;
    while (bits != 0) {
        if (bits & 1) {
            for (; i < 3; i++) {
                if (arg0[i] == 0xFF) {
                    break;
                }
            }
            if (i >= 3) {
                break;
            }
            arg0[i++] = id;
        }
        bits >>= 1;
        id++;
    }
}

s32 func_800B79B8(void) {
    if ((D_8009D391 != 0) && (D_8009D392 != 0)) {
        if (D_8009D393 != 0) {
            if ((D_8009D391 != 2) && (D_8009D392 != 2) && (D_8009D393 != 2)) {
                if ((D_8009D391 == 8) || (D_8009D392 == 8) || (D_8009D393 == 8)) {
                    return 2;
                }
                
                return 0;
            }
            return 1;
        }
        
        return 0;
    }
    return 0;
}

void func_800B7A40(void) {
    s32 id;
    void (*fn)();

    func_800B787C(&D_8009D391, &D_8009D391 - 0x7B5, func_800A1DE0() != 2);
    if (func_800A1DE0() != 2) {
        id = func_800B79B8() & 0xFF;
        if (func_800BBA44() != 0) {
            fn = func_800BBA34;
        } else {
            fn = func_800A9A04;
        }
        fn(id);
    }
}

void func_800B7AC0(s16 arg0) {
    u8 *base;
    u8 *dst;
    u8 *src;
    u8 c;
    s32 stop;

    src = func_800A40F0(arg0);
    stop = 0xFF;
    base = (u8 *)&D_8009D288;
    dst = base + 0x368;
    do {
        c = *src++;
        *dst++ = c;
    } while (c != stop && (s32)dst < (s32)(base + 0x380));
}

void func_800B7B1C(u8 arg0) {
    D_8009D684 = arg0;
}

u8 func_800B7B2C(void) {
    return D_8009D684;
}

s32 func_800B7B3C(void) {
    return ((u16) *D_800707BE >> 3) & 1;
}

s32 func_800B7B54(void) {
    u32 var_v1;

    var_v1 = D_80062F19;
    if (var_v1 >= 0x11U) {
        var_v1 *= 2;
    }
    return var_v1;
}

s32 func_800B7B78(void) {
    s32 var_v1;

    var_v1 = D_80062F1B & 0x7F;
    if (var_v1 >= 0x11) {
        var_v1 *= 2;
    }
    return var_v1;
}

u32 func_800B7BA0(void) {
    return (u8) D_80062F1B >> 7;
}

u8 func_800B7BB0(void) {
    return D_80062F1A;
}

s32 func_800B7BC0(void) {
    return D_8009D40D & 1;
}

s32 func_800B7BD0(void) {
    return 1;
}

s32 func_800B7BD8(void) {
    s32 var_a0;
    s32 var_v1;
    u8 temp_v0;

    var_a0 = 0;
    var_v1 = 0;
    do {
        temp_v0 = D_8009CBDC[var_v1];
        var_v1 += 1;
        var_a0 += temp_v0 != 0xFF;
    } while (var_v1 < 3);
    return var_a0 >= 2;
}

s32 func_800B7C14(void) {
    return 1;
}

void func_800B7C1C(void) {
    D_80116284 = 0;
    func_800B7C44();
}

void func_800B7C44(void) {
    D_8011627C = -0x8C;
}

void func_800B7C58(void) {
    D_8011627C = -0x1E;
}

void func_800B7C6C(s32 arg0) {
    D_80116280 = arg0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B7C7C);

void func_800B832C(void) {
    WQuad32 a;
    WQuad32 b;
    s32 r;
    s32 m;
    s32 k;

    r = func_800A1DE0();
    if (D_8009AC2F == 0 && r != 2 && func_800B2FD0() == 0 && func_800A21A4() != 0) {
        m = func_800A9AD0();
        func_800AA0E0(&a);
        func_800AA170(&b);
        if (func_800A91A4(0x47) != 0 && D_80116280 != 0) {
            if (m == 0 && (a.a != b.a || a.c != b.c)) {
                if (D_8011627C == 8 || D_8011627C == 0x10) {
                    func_800262D8();
                }
                if (D_8011627C++ >= 0x10) {
                    D_8011627C = 0;
                    k = func_800B7C7C();
                    if (k != -1) {
                        func_800A9D88((s32)&b);
                        func_800A3F4C(k);
                    }
                }
            }
        } else {
            D_8011627C = 0;
        }
    }
}

void func_800B8488(void *arg0) {
    D_8008326C = 0xFF;
    D_800722C4 = 0xFF;
    D_8009C6DC = arg0;
    M2C_FIELD(arg0, s16 *, 4) = 8;
    func_800B8760();
    D_8009C6E0 = &D_8009ABF4;
}

void func_800B84D8(s32 arg0) {
    if (D_800832A0 == 0) {
        D_8011628C = 0;
        D_80116288 = 0;
        func_800B8D4C(0, arg0 & 0xFF);
    }
}

void func_800B851C(s32 arg0, s16 arg1, s16 arg2) {
    if (D_800832A0 == 0) {
        D_80116288 = arg1;
        D_8011628C = arg2;
        func_800B90C0(0, arg0 & 0xFF, (u8) D_80116288, (u8) D_8011628C, &D_80116290);
    }
}

s32 func_800B857C(void) {
    return D_800832A0 != 0;
}

s32 func_800B858C(void) {
    if ((D_800832A0 != 0) && (D_800832A0 != 7)) {
        func_800B89C4(0);
    }
    return D_800832A0 != 0;
}

void func_800B85D4(void) {
    s32 cur;

    if (D_800832A0 != 0) {
        cur = func_8001C8D4();
        D_8009C6E0[0x70 / 4] = cur & ~D_8009C6E0[0x68 / 4];
        D_8009C6E0[0x68 / 4] = cur;
        cur = func_8001C8D4();
        D_8009C6E0[0x80 / 4] = cur & ~D_8009C6E0[0x78 / 4];
        D_8009C6E0[0x78 / 4] = cur;
        if (D_80116288 != 0 || D_8011628C != 0) {
            func_800B90C0(0, 0, D_80116288, D_8011628C, (s32 *)&D_80116290);
        } else {
            func_800B8D4C(0, 0);
        }
        func_8001F1BC(D_80083274, 1, D_800BD130, func_800A0BD4() == 0);
    }
}

s16 func_800B86C4(void) {
    if (D_800832A0 == 0) {
        return D_80116290;
    }
    return -1;
}

void func_800B86E8(void *arg0) {
    if (arg0 != NULL) {
        func_800B8B00(0, M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4), (s32) M2C_FIELD(arg0, s16 *, 6));
    }
}

void func_800B8720(s16 arg0, s16 arg1) {
    func_800B8A5C(0, arg0, arg1);
}

void func_800B8750(void) {
}

void func_800B8758(void) {
}

void func_800B8760(void) {
    s32 i;
    u32 off;

    D_80071E2C = 0;
    for (i = 0; i < 1; i++) {
        func_800B87D8(i);
    }
    off = M2C_FIELD(D_8009C6DC, u16 *, 4);
    if (off != 0) {
        D_80116298 = (u8 *)D_8009C6DC + off;
    } else {
        D_80116298 = NULL;
    }
}

void func_800B87D8(s16 arg0) {
    void func_800B8750();
    s32 j;

    if (arg0 == 1) {
        D_80083278[1].f2 = 8;
    } else {
        D_80083278[arg0].f2 = 0x95;
    }
    D_80083278[arg0].f0 = 8;
    D_80083278[arg0].f4 = 0x130;
    D_80083278[arg0].f6 = 0x49;
    D_80083278[arg0].f8 = 1;
    D_80083278[arg0].fA = 1;
    D_80083278[arg0].f28 = 0;
    D_80083278[arg0].f15 = 0;
    D_80083278[arg0].f17 = 0;
    D_80083278[arg0].f18 = 0;
    D_80083278[arg0].f19 = 6;
    D_80083278[arg0].f24 = 0;
    D_80083278[arg0].f26 = 0;
    D_80083278[arg0].f2A = 0;
    (&D_8008326C)[arg0] = 0xFF;
    for (j = 0; j < 4; j++) {
        D_801163B4[arg0][j] = 0;
        D_801163B8[arg0][j] = 0;
    }
    D_801163D0[arg0] = 0;
    if (D_8009D820 & 3) {
        ((void (*)(char *, s32, s32))func_800B8750)("mes reset=", arg0, 1);
    }
}

s32 func_800B89C4(s16 arg0) {
    switch ((s16)D_80083278[arg0].f28) {
    case 1:
        return 0;
    case 2:
    case 4:
    case 6:
    case 8:
    case 11:
    case 13:
        D_80083278[arg0].f28 = 7;
        break;
    }
    return 1;
}

void func_800B8A5C(s16 arg0, s16 arg1, s16 arg2) {
    s32 off = arg0 * 0x30;
    D_8008328D[off] = arg1;
    *(s16 *)&D_800832A2[off] = arg2;
}

void func_800B8A98(void) {
    s32 i;

    for (i = 0; i < 1; i++) {
        D_80083278[i].f28 = 0;
        D_80083278[i].fE = 0;
        (&D_8008326C)[i] = 0xFF;
        D_801163D0[i] = 0;
    }
    D_80071E2C = 0;
}

void func_800B8B00(s16 id, s16 x, s16 y, s16 w, s16 h) {
    void func_800B8750();

    if (x < 8) {
        if (D_8009D820 & 3) {
            ((void (*)(char *, s32, s32))func_800B8750)("win limit x=", x, 2);
        }
        x = 8;
    }
    if (x + w > 0x138) {
        if (D_8009D820 & 3) {
            ((void (*)(char *, s32, s32))func_800B8750)("win limit x=", x + w, 3);
        }
        x = 0x138 - w;
    }
    if (y < 8) {
        if (D_8009D820 & 3) {
            ((void (*)(char *, s32, s32))func_800B8750)("win limit y=", y, 2);
        }
        y = 8;
    }
    if (y + h > 0xE0) {
        if (D_8009D820 & 3) {
            ((void (*)(char *, s32, s32))func_800B8750)("win limit y=", y + h, 3);
        }
        y = 0xE0 - h;
    }
    D_80083278[id].f0 = x;
    D_80083278[id].f2 = y;
    D_8008327C[id].a = w;
    D_8008327C[id].b = h;
}

void func_800B8CBC(s16 arg0, s32 arg1, s32 arg2) {
    D_80083278[arg0].f0 += arg1;
    D_80083278[arg0].f2 += arg2;
}

void func_800B8D20(s16 arg0, s16 arg1) {
    D_8008327C[arg0].b = arg1;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B8D4C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B90C0);

void func_800B95E8(void) {
    D_8009A000 = 0x30;
    D_8009A004 = 1;
    D_8009A008 = 0x40;
    func_8002DA7C();
}

s32 func_800B962C(s16 arg0, s16 arg1) {
    if (D_80116298 == NULL) {
        ((void (*)(u8 *))func_800B8758)(D_800A09AC);
        return 1;
    }
    if ((&D_8008326C)[arg0] != 0xFF) {
        if (D_8009D820 & 3) {
            ((void (*)(u8 *, s16, s32))func_800B8750)(D_800A09BC, arg0, 1);
        }
        return 0;
    }
    (&D_8008326C)[arg0] = D_800722C4;
    D_80083278[arg0].f8 = D_80083278[arg0].f4 / 4;
    D_80083278[arg0].fA = D_80083278[arg0].f6 / 4;
    if (D_80083278[arg0].fA < 8) {
        D_80083278[arg0].fA = 8;
    }
    if (D_80083278[arg0].f8 < 8) {
        D_80083278[arg0].f8 = 8;
    }
    *(u8 **)&D_80083274[arg0 * 0x30] = D_801162B4[arg0];
    *(u16 *)D_80083278[arg0].padC = 0;
    D_80083284[arg0].f2 = 0;
    D_80083284[arg0].f4 = 0;
    D_80083284[arg0].f6 = 0;
    D_80083284[arg0].pad8[2] = 0;
    D_801162B4[arg0][0] = 0xFF;
    D_801162B0[arg0] = D_80116298;
    D_801162B0[arg0] += ((u8 *)D_80116298)[arg1 * 2 + 2];
    D_801162B0[arg0] += ((u8 *)D_80116298)[arg1 * 2 + 3] << 8;
    D_80071E2C++;
    D_8011629C[arg0] = 1;
    D_801162A0[arg0] = 0;
    D_801162A4[arg0] = 0;
    D_801162AC[arg0] = 0;
    D_801163C0[arg0] = 0;
    D_801163C4[arg0] = -1;
    D_80083278[arg0].f28 = 1;
    return 0;
}

void func_800B98F0(s16 arg0) {
    void func_800B8750();

    if ((&D_8008326C)[arg0] != D_800722C4) {
        if (D_8009D820 & 3) {
            ((void (*)(u8 *, s16, s32))func_800B8750)(D_800A09BC, arg0, 1);
        }
    } else {
        D_80083278[arg0].f8 += D_80083278[arg0].f4 / 4;
        if (D_80083278[arg0].f8 < 8) {
            D_80083278[arg0].f8 = 8;
        }
        if (D_80083278[arg0].f4 < D_80083278[arg0].f8) {
            D_80083278[arg0].f8 = D_80083278[arg0].f4;
        }
        D_80083278[arg0].fA += D_80083278[arg0].f6 / 4;
        if (D_80083278[arg0].fA < 8) {
            D_80083278[arg0].fA = 8;
        }
        if (D_80083278[arg0].f6 < D_80083278[arg0].fA) {
            D_80083278[arg0].fA = D_80083278[arg0].f6;
        }
        if (D_80083278[arg0].f8 == D_80083278[arg0].f4 && D_80083278[arg0].fA == D_80083278[arg0].f6) {
            D_80083278[arg0].f28 = 2;
        }
    }
}

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A09AC);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A09BC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B9B2C);

void func_800BA938(s16 arg0) {
    void func_800B8750();

    if ((&D_8008326C)[arg0] != D_800722C4) {
        if (D_8009D820 & 3) {
            ((void (*)(u8 *, s16, s32))func_800B8750)(D_800A09BC, arg0, 1);
        }
    } else {
        if (D_80083284[arg0].f0 & 0xF) {
            D_80083284[arg0].f0 -= 2;
        } else {
            D_80083284[arg0].f1C = 2;
        }
    }
}

void func_800BAA00(s16 arg0) {
    void func_800B8750();
    s16 *p;
    s32 v;


    if ((&D_8008326C)[arg0] != D_800722C4) {
        if (D_8009D820 & 3) {
            ((void (*)(u8 *, s16, s32))func_800B8750)(D_800A09BC, arg0, 1);
        }
    } else {

        if ((s16)D_80083284[arg0].f0 + D_801162A8[arg0] > 0) {
            p = &D_8011629C[arg0];
            D_80083284[arg0].f0 = (s16)D_80083284[arg0].f0 - (*p >> 2);
            if (M2C_FIELD(D_8009C6E0, s32 *, 0x78) & 0x20) {
                if (++*p > 0x80) {
                    *p = 0x80;
                }
            } else {
                if (--*p < 2) {
                    *p = 1;
                }
            }
        } else {
            D_80083284[arg0].f1C = 9;
        }
    }
}

void func_800BAB60(s16 arg0) {
    void func_800B8750();

    if ((&D_8008326C)[arg0] != D_800722C4) {
        if (D_8009D820 & 3) {
            ((void (*)(u8 *, s16, s32))func_800B8750)(D_800A09BC, arg0, 1);
        }
    } else {
        D_80083284[arg0].f1C = 2;
        D_80083284[arg0].f4 = 0;
        D_80083284[arg0].f2 = 0;
        D_80083284[arg0].f0 = 0;
        D_80083284[arg0].f6 = 0;
        D_801162B4[arg0][0] = 0xFF;
        D_801162A4[arg0] = 0;
        D_8011629C[arg0] = 1;
    }
}

s32 func_800BAC70(s16 arg0) {
    void func_800B8750();

    if ((&D_8008326C)[arg0] != D_800722C4) {
        if (D_8009D820 & 3) {
            ((void (*)(u8 *, s16, s32))func_800B8750)(D_800A09BC, arg0, 1);
        }
        return 1;
    }
    if (D_80083278[arg0].f8 < 8) {
        D_80083278[arg0].f8 = 8;
    } else {
        D_80083278[arg0].f8 = D_80083278[arg0].f8 - D_80083278[arg0].f4 / 4;
    }
    if (D_80083278[arg0].fA < 8) {
        D_80083278[arg0].fA = 8;
    } else {
        D_80083278[arg0].fA = D_80083278[arg0].fA - D_80083278[arg0].f6 / 4;
    }
    if (D_80083278[arg0].f8 < 9 && D_80083278[arg0].fA < 9) {
        D_80083278[arg0].fE = 0;
        D_80083278[arg0].f28 = 0;
        (&D_8008326C)[arg0] = 0xFF;
        D_80071E2C--;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BAE60);

void func_800BB350(u16 val, u8 *out) {
    s32 started;
    s16 div;
    s16 n;
    s16 q;

    started = 0;
    div = 10000;
    n = 0;
    do {
        q = val / div;
        if (started || q != 0) {
            started = 1;
            out[n] = D_800C7304[q];
            n++;
        }
        val -= q * div;
        div /= 10;
    } while (div >= 2);
    out[n] = D_800C7304[val];
    out[n + 1] = 0xFF;
}

void func_800BB450(u16 val, u8 *out) {
    s32 started;
    s16 div;
    s16 n;
    s16 q;

    started = 0;
    div = 10000;
    n = 0;
    do {
        q = val / div;
        if (started || q != 0) {
            started = 1;
            out[n] = D_800C7304[q];
            n++;
        } else {
            out[n] = 0x3F;
            n++;
        }
        val -= q * div;
        div /= 10;
    } while (div >= 2);
    out[n] = D_800C7304[val];
    out[n + 1] = 0xFF;
}

void func_800BB568(u16 val, u8 *out) {
    s32 started;
    s16 div;
    s16 n;
    s16 q;

    started = 0;
    div = 0x1000;
    n = 0;
    do {
        q = val / div;
        if (started || q != 0) {
            started = 1;
            out[n] = D_800C7304[q];
            n++;
        }
        val -= q * div;
        div /= 16;
    } while (div >= 2);
    out[n] = D_800C7304[val];
    out[n + 1] = 0xFF;
}

s32 func_800BB650(s16 arg0) {
    void func_800B8758();
    u8 *p;
    u8 *src;
    u8 *name;
    s16 n;
    s16 k;

    if (D_80116298 == NULL) {
        ((void (*)(u8 *))func_800B8758)(D_800A09AC);
        return 0;
    }
    p = D_80116298;
    src = p;
    k = 0;
    n = 0;
    src += p[arg0 * 2 + 2];
    src += p[arg0 * 2 + 3] << 8;
    do {
        switch (*src) {
        case 0xEA:
        case 0xEB:
        case 0xEC:
        case 0xED:
        case 0xEE:
        case 0xEF:
        case 0xF0:
        case 0xF1:
        case 0xF2:
            name = (u8 *)func_800257CC((s16)(*src - 0xEA)) + k;
            if (*name == 0xFF || k >= 9) {
                src++;
                k = 0;
            } else {
                k++;
                D_8009D5F0[n] = *name;
                n++;
            }
            break;
        case 0xFA:
        case 0xFB:
        case 0xFC:
        case 0xFD:
        case 0xFE:
            D_8009D5F0[n] = *src++;
            n++;
        default:
            D_8009D5F0[n] = *src++;
            n++;
            break;
        case 0xFF:
            goto end;
        }
    } while (n < 0x17);
end:
    D_8009D5F0[n] = 0xFF;
    return 1;
}

void func_800BB7DC(s16 arg0, s16 arg1) {
    void func_800B8758();
    u8 *p;
    u8 *src;
    u8 *dst;
    s16 n;

    if (D_80116298 == NULL) {
        ((void (*)(u8 *))func_800B8758)(D_800A09AC);
        return;
    }
    p = D_80116298;
    src = p;
    n = 0;
    src += p[arg1 * 2 + 2];
    src += p[arg1 * 2 + 3] << 8;
    dst = func_800257CC(arg0);
    while (*src != 0xFF) {
        *dst++ = *src++;
        n++;
    }
    if (n < 9) {
        *dst = 0xFF;
    }
}

void func_800BB8B0(void) {
    D_801163D4 = 0;
    D_801163D8 = 0;
    D_801163E8 = (u32) &D_801163E0;
    D_801163EC = 0;
    D_801163DC = 0;
}

void func_800BB8E8(s32 arg0) {
    W4SVec v;
    s32 m;

    func_800AA238();
    func_800A90EC();
    v.vy = 0;
    v.vx = 0;
    m = ((s32 (*)(void))func_800A9174)();
    if (m == 5 || m == 13) {
        if (arg0 != 0) {
            v.vz = arg0;
        } else {
            v.vz = func_800A98E4() != 0 ? 0x64 : 0x320;
        }
        func_800AE0BC(&v, func_800A97E4());
    } else {
        v.vz = 0x12C;
        func_800AE0BC(&v, func_800A97E4() + 0x400);
    }
    func_800AA7DC(v.vx, v.vz);
}

void func_800BB9A0(s8 arg0) {
    u8 *p;

    p = D_801163E8;
    if (p < (u8 *)&D_801163E8) {
        D_801163E8 = p + 1;
        *p = arg0;
    }
}

u8 func_800BB9D0(void) {
    u8 *p;

    p = D_801163E8;
    if ((u32)p <= (u32)&D_801163E0) {
        return 0;
    }
    D_801163E8 = p - 1;
    return p[-1];
}

u8 func_800BBA0C(void) {
    u8 var_a0;

    var_a0 = 0;
    if ((u32) &D_801163E0 < (u32) D_801163E8) {
        var_a0 = M2C_FIELD(D_801163E8, u8 *, -1);
    }
    return var_a0;
}

void func_800BBA34(s8 arg0) {
    D_801163E0 = arg0;
}

s32 func_800BBA44(void) {
    return (u32) &D_801163E0 < (u32) D_801163E8;
}

void func_800BBA5C() {
    WQuad32 pos;
    s32 dir;
    s32 n;

    if (((s32 (*)(void))func_800A9174)() == 5 && D_801163EC != 0) {
        func_800A98A4(1);
        func_800A368C(1);
        return;
    }
    if (func_800A99BC() != 0) {
        func_800AA098(&pos);
        if (((s32 (*)(void))func_800A9154)() == 3) {
            dir = -1;
        } else {
            dir = 1;
        }
        func_800A6994(&pos, dir);
        ((void (*)(s32))func_800BB9A0)(((s32 (*)(void))func_800A9174)() & 0xFF);
        if (func_800A929C() != 0) {
            func_800A8CE4();
            n = 2;
        call:
            func_800B63F0(n);
            return;
        }
        func_800A8FCC();
        func_800A8F74();
        func_800A9110();
        switch (((s32 (*)(void))func_800A9174)()) {
        case 3:
            func_800A98A4(1);
            func_800A368C(1);
            func_800B5274();
            if (func_800B64C8() < 6) {
                if (func_800B7200() != 0) {
                    n = 1;
                } else {
                    n = 3;
                }
                goto call;
            }
            break;
        case 6:
            func_800B65E0(0x1EC);
            break;
        }
    }
}

s32 func_800BBBB0(void) {
    s32 n;

    n = func_800A9A44();
    if (func_800A9240() != 0) {
        return (0x221B0F03 >> n) & 1;
    }
    switch (((s32 (*)(void))func_800A9174)()) {
    case 5:
        return (0x70 >> n) & 1;
    case 3:
        return n == 0;
    case 6:
        return (0x221B0F83 >> n) & 1;
    case 13:
        return 1;
    }
    return 0;
}

void func_800BBC4C(void) {
    s32 temp_s0;

    temp_s0 = ((s32 (*)(void))func_800A9174)();
    if (D_801163D4 == 0) {
        if (func_800BBBB0() != 0) {
            if ((temp_s0 == 3) || ((temp_s0 == 5) && (func_800A98E4() != 0))) {
                func_800A368C(-1);
            } else {
                func_800A2108(0, 2);
            }
            D_801163D4 = 1;
            if ((u32) (temp_s0 - 3) < 2U) {
                func_800AB8EC(1);
            }
        }
        if (func_800A9A44() == 0x1B) {
            func_800ABA18(9);
        }
    }
}

void func_800BBD0C(void) {
    D_801163D4 = 1;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BBD20);

s32 func_800BC1AC(void) {
    return D_801163D4;
}

void func_800BC1BC(s32 arg0) {
    D_801163EC = arg0;
}

void func_800BC1CC(void) {
    s32 i;
    s32 j;
    WmFt4L *p;
    W4Sprt *s;
    WmSprt8 *q;
    WmG3L *g;
    s32 tpage;

    for (i = 0; i < 2; i++) {
        p = &D_800C7314[i];
        p->len = 9;
        p->code = 0x2E;
        D_800C7314[i].tpage = (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) ? 0x2B : 0x1B;
        s = D_800C7364;
        s[i].len = 4;
        s[i].code = 0x66;
        if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
            tpage = 0x29;
        } else {
            tpage = 0x19;
        }
        func_80044A68(&D_801164B0[i], 0, 1, tpage, 0);
        for (j = 0; j < 6; j++) {
            q = &D_801163F0[i][j];
            *(s32 *)&q->r0 = D_800C73C4[j];
            q->len = 3;
            q->code = 0x76;
            q->u0 = 0x84;
            q->clut = 0x7CC8;
        }
        if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
            tpage = 0x29;
        } else {
            tpage = 0x19;
        }
        func_80044A68(&D_801164C8[i], 0, 1, tpage, 0);
        g = D_800C738C;
        g[i].len = 6;
        g[i].code = 0x32;
        if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
            tpage = 0xA9;
        } else {
            tpage = 0x39;
        }
        func_80044A68(&D_801164E0[i], 0, 1, tpage, 0);
    }
    D_801164FC = 0;
    D_801164F8 = 0;
    D_80116500 = 8;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BC420);

void func_800BC9E8(s32 arg0) {
    D_801164F8 = (s16) arg0;
    if (((s32 (*)(void)) func_800A9174)() != 3) {
        D_801164FC = D_801164F8;
    }
}

s16 func_800BCA38(void) {
    return D_801164F8;
}

void func_800BCA48(void) {
    if (D_801164F8 == 1) {
        D_801164F8 = D_801164FC;
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BCA78);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BCB2C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BCBE8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BCECC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BD948);

s32 func_800BFBF0(WmHdr3 *arg0, s32 arg1, s32 arg2) {
    u32 i;
    s32 q;

    arg0->f20 = arg1;
    arg1 += arg0->a << 5;
    q = arg0->off + arg0->base;
    for (i = 0; i < arg0->cnt; i++) {
        arg1 = func_800BFCAC(q + i * 0x20, arg1, 0, arg2);
    }
    func_800C1D58(arg0, arg0->f16, 0);
    return arg1;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BFCAC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C02F4);

void func_800C0808(W4ImgHdr *arg0) {
    W4Rect r;
    u32 i;
    u32 n;
    W4Img *e;

    i = 0;
    n = arg0->count;
    e = arg0->img;
    for (; i < n; i++) {
        r.x = e[i].x;
        r.y = e[i].y;
        r.w = e[i].w;
        r.h = e[i].h;
        func_80044000(&r, (u8 *)arg0 + e[i].off);
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C08A8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C0B48);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C1490);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C1D58);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C1FD8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C2130);

s32 func_800C2450(WmHdr3 *arg0, u8 *arg1) {
    u32 i;
    u32 cnt;
    s32 pad[2];
    s32 q;
    s16 x;
    s16 y;
    s16 z;

    cnt = arg0->cnt;
    q = arg0->off + arg0->base;
    x = (arg1[1] << 8) | arg1[0];
    y = (arg1[3] << 8) | arg1[2];
    z = (arg1[5] << 8) | arg1[4];
    *(s32 *)0x1F800200 = arg1[6];
    for (i = 0; i < cnt; i++) {
        func_800C2524(q + i * 0x20, x, y, z);
    }
    return 1;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C2524);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C31F0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C3948);

void func_800C3DB0(WmPrimHdr *hdr, s32 flag) {
    u8 *p;
    u32 i;
    u32 n;
    u32 pass;

    for (pass = 0; pass < 2; pass++) {
        p = hdr->f1C;
        if (pass != 0) {
            p += hdr->f16;
        }
        n = hdr->n[0];
        for (i = 0; i < n; i++, p += 0x34) {
            if (flag != 0) {
                p[7] |= 2;
            } else {
                p[7] &= 0xFD;
            }
            if (flag != 0) {
                p[7] |= 1;
            } else {
                p[7] &= 0xFE;
            }
        }
        n = hdr->n[1];
        for (i = 0; i < n; i++, p += 0x28) {
            if (flag != 0) {
                p[7] |= 2;
            } else {
                p[7] &= 0xFD;
            }
            if (flag != 0) {
                p[7] |= 1;
            } else {
                p[7] &= 0xFE;
            }
        }
        n = hdr->n[2];
        for (i = 0; i < n; i++, p += 0x28) {
            if (flag != 0) {
                p[7] |= 2;
            } else {
                p[7] &= 0xFD;
            }
            if (flag != 0) {
                p[7] |= 1;
            } else {
                p[7] &= 0xFE;
            }
        }
        n = hdr->n[3];
        for (i = 0; i < n; i++, p += 0x20) {
            if (flag != 0) {
                p[7] |= 2;
            } else {
                p[7] &= 0xFD;
            }
            if (flag != 0) {
                p[7] |= 1;
            } else {
                p[7] &= 0xFE;
            }
        }
        n = hdr->n[4];
        for (i = 0; i < n; i++, p += 0x14) {
            if (flag != 0) {
                p[7] |= 2;
            } else {
                p[7] &= 0xFD;
            }
            if (flag != 0) {
                p[7] |= 1;
            } else {
                p[7] &= 0xFE;
            }
        }
        n = hdr->n[5];
        for (i = 0; i < n; i++, p += 0x18) {
            if (flag != 0) {
                p[7] |= 2;
            } else {
                p[7] &= 0xFD;
            }
            if (flag != 0) {
                p[7] |= 1;
            } else {
                p[7] &= 0xFE;
            }
        }
        n = hdr->n[6];
        for (i = 0; i < n; i++, p += 0x1C) {
            if (flag != 0) {
                p[7] |= 2;
            } else {
                p[7] &= 0xFD;
            }
            if (flag != 0) {
                p[7] |= 1;
            } else {
                p[7] &= 0xFE;
            }
        }
        n = hdr->n[7];
        for (i = 0; i < n; i++, p += 0x24) {
            if (flag != 0) {
                p[7] |= 2;
            } else {
                p[7] &= 0xFD;
            }
            if (flag != 0) {
                p[7] |= 1;
            } else {
                p[7] &= 0xFE;
            }
        }
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C4148);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C4FB4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C5CD4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C6104);

s32 func_800C6598(WmHdr2 *arg0) {
    WmEnt *p;
    s32 sum;
    u32 i;
    s32 pad;

    sum = arg0->a << 5;
    p = (WmEnt *)(arg0->off + arg0->base);
    for (i = 0; i < arg0->cnt; i++) {
        sum += p->f16 * 2;
        p++;
    }
    return sum;
}
