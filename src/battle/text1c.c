#include "common.h"
#include "battle/decls.h"

s32 func_800A3828(void) {
    s32 r;

    r = 0;
    if (D_800F39E0 == 3) {
        D_800F39E4 += D_800F7DA6;
    }
    if (D_800F7DAA == 2) {
        switch (D_800F3896) {
        case 0:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 24:
        case 26:
        case 27:
            r = 1;
            break;
        }
    }
    r |= func_800A4A80();
    r |= (D_800F83D0[0] & 3) != 0;
    if (D_800F39E4 > 0x4000) {
        r = 1;
    }
    return r;
}

void func_800A38FC(void) {
    u16 pad;
    s32 i;
    s32 a;
    s32 v;
    s32 cur;
    BtlK44 *p;
    S44h *tab;
    u8 *q;

    pad = D_80062D78;
    func_800A72C8(0);
    D_800F7DE8 |= 1;
    if (func_800A3828() == 0) {
        D_800F7DE8 &= 0xFFFE;
        if (D_800F7DB2[0] != 0 && D_800F7DB2[0] == D_800F7DB6) {
            if ((pad & 0xC) == 0xC) {
                D_800F7DAE += 1;
            }
            D_800F7DB0 += 1;
            D_800F7DB4 += D_800F7DA6;
            if (D_800F7DB4 > 0x2000) {
                D_800F7DB4 -= 0x2000;
                if (D_800F7DB0 < D_800F7DAE * 2 && (D_800F7DD0 < 0x4000 || D_800F7DC8 == 1 || D_800F7DC8 == 3)) {
                    D_800F7DB2[0] -= 1;
                }
                D_800F7DB0 = 0;
                D_800F7DAE = 0;
            }
        }
        func_800B0170();
        tab = D_800F5BB8;
        for (i = 0; i < 10; i++) {
            if ((((D_8016375A | 0x3F0) & (D_80163768 | 7)) >> i) & 1) {
                p = (BtlK44 *)&tab[i];
                v = p->f4;
                a = p->f2;
                if (v != 0xFFFF) {
                    if (p->f8 & 1) {
                        a *= 4;
                    }
                    if ((*(u16 *)((u8 *)tab + 0x2212) >> i) & 1) {
                        a = 0;
                    }
                    v += a;
                    if (v > 0xFFFF) {
                        v = 0xFFFF;
                    }
                    p->f4 = v;
                    if (v == 0xFFFF) {
                        if (i >= 3 || (D_800F83E4[i][0] & 0x10)) {
                            func_800A4350(i, -1, 0, 0);
                        } else if ((*(u16 *)((u8 *)tab + 0x220C) >> i) & 1) {
                            func_800A4350(i, ((s32 (*)(s32))func_800A4CA8)(i), 0, 0);
                        } else {
                            func_800A4D2C(i);
                            *(u16 *)((u8 *)tab + 0x21F4) |= 1 << i;
                        }
                        p->f8 &= 0xFFFE;
                        D_800F39E0 |= 2;
                    }
                }
            }
        }
    }
    func_800B0234();
    for (i = 0; i < 3; i++) {
        q = D_8009D84C[i];
        a = D_800F5E6A[i][0];
        cur = *(u16 *)(q + 0x1A) >> 8;
        if (D_800F83D0[0] & 8) {
            a = D_800F39E8 * 0xFF / D_800F83D0[2];
            if (a >= 0x100) {
                a = 0xFF;
            }
        }
        if (cur < a) {
            cur += 4;
            if (a < cur) {
                cur = a;
            }
            if (cur == 0xFF) {
                func_800A4E80(i);
                func_800A7254(1, i, 1, 0);
            }
            *(u16 *)(q + 0x1A) = cur << 8;
        }
    }
    for (i = 0; i < 3; i++) {
        D_8009D864[i][0] = D_800F5BBC[i].a;
    }
    func_800A5750();
}

void func_800A3D4C(E8s *arg0) {
    s32 i;
    s32 a;

    a = arg0->a;
    for (i = 0; i < 0x40; i++) {
        if (D_800F6934[i].a == 0xFF) {
            arg0->b = D_800F6B9B[a];
            D_800F6934[i] = *arg0;
            D_800F6B9B[a]++;
            *(s16 *)((u8 *)D_800F6934 + 0x14AA) = a;
            if (arg0->a >= 2) {
                D_800F83E4[arg0->c][0] &= ~0x20;
                if ((((u8 *)arg0)[3] & 0x3F) == 0x13) {
                    D_800F83E4[arg0->c][0] |= 0x20;
                }
            }
            break;
        }
    }
}

void func_800A3E98(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Q8 q;

    q.c = arg0;
    q.a = arg1;
    q.d = arg2;
    q.e = arg3;
    q.f = arg4;
    func_800A3D4C(&q);
}

void func_800A3ED0(void) {
    u16 buf[2];
    s32 i;
    s32 o;
    s32 mask;
    s32 flag;
    s32 t;
    s32 v;
    s32 m;
    s32 c;
    s32 f;
    s32 lt;
    s32 k;
    u8 *p;
    u8 *q;
    u8 *r;
    u16 *w;

    mask = 0;
    D_800F39E8 += 1;
    flag = (D_80062D78 & 0xC) == 0xC;
    if (D_80062F14 >= 0x100) {
        k = D_80062F60++ / 32 % 3 + 0x6E;
        buf[1] = D_80062F14 & 0xFF;
        buf[0] = D_80062F54;
        func_800DCF94(func_800A5EB0((u8 *)func_800151F4(k), buf) + 0x100);
        return;
    }
    i = 0;
    D_800F7DD0 = func_80014BE4();
    func_800A72C8(1);
    for (i = 0; i < 3; i++) {
        t = 1 << i;
        if ((D_800F83BC & t) && D_800F5BBA[i].a == 0) {
            mask |= t;
        }
    }
    if (D_800F83C6[0] == 0 && flag != 0) {
        if (!(D_8016376A & 8) && mask != D_800F83BC && D_80163780 < 2) {
            if (D_800F7DB6 != D_800F7DB2[0] && D_800F7DB2[0] == 0) {
                D_800F83C6[0] |= 4;
                c = 0xD;
                for (o = 0xD0; o >= 0; o -= 0x68) {
                    D_800F83F6[o] = c;
                }
            }
            D_800F7DB6 = D_800F7DB2[0];
        } else {
            func_800DCF94(0x36);
        }
    }
    w = &D_800F7DC0;
    if (*w != 0) {
        func_800DCF94(D_800F7DBE);
        *w -= 1;
    }
    i = 0;
    if (D_800F39D8 != D_800F39DC) {
        do {
            func_800A3D4C((E8s *)&D_800F3958[D_800F39D8]);
            D_800F39D8 = (D_800F39D8 + 1) & 0xF;
        } while (D_800F39D8 != D_800F39DC);
    }
    for (i = 0; i < 3; i++) {
        q = D_8009D84C[i];
        p = (u8 *)&D_800F83E0[i];
        lt = (*(s16 *)(q + 0x10) << 2) < *(s16 *)(q + 0x12);
        m = p[0x16];
        f = D_801636C4[i].v;
        if (f & 1) {
            m = 2;
        } else if (M2C_FIELD(D_800F83E0, u16 *, -0x1A) == 0 && m == 0) {
            if (lt || (f & 0x0E20008C)) {
                m = 1;
            }
            if (flag != 0 && !((mask >> i) & 1)) {
                m = 0xD;
            }
        }
        p[0x10] = m;
    }
    for (i = 0; i < 10; i++) {
        r = (u8 *)D_800F5BB8 + i * 0x44;
        v = 0xFF;
        if (D_801636C4[i].v & 0x200000) {
            v = r[0x12];
            if (v != 0xFF) {
                v -= func_800AFE98(i);
            }
            if (v < 0) {
                v = 0;
            }
        }
        D_801636BA[i][0] = v;
        v = 0xFF;
        if (D_801636C4[i].v & 0x2000) {
            v = r[0x13] - func_800AFE98(i);
            if (v < 0) {
                v = 0;
            }
        }
        D_801636BB[i][0] = v;
    }
    for (i = 0; i < 3; i++) {
        D_801636B9[i][0] = D_800F83F0[i][0];
    }
}

void func_800A4350(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    Q8 *e;
    s32 i;
    s32 mask;
    u16 *p;

    if (D_800F39D8 != ((D_800F39DC + 1) & 0xF)) {
        e = &D_800F3958[D_800F39DC];
        e->a = arg1 == 0x14 ? 5 : 6;
        e->c = arg0;
        e->d = arg1;
        e->e = arg2;
        e->f = arg3;
        switch (arg1) {
        case 4:
        case 8:
        case 0x17:
            func_800A5660(arg0, arg2);
            break;
        }
        i = arg0;
        func_800A4D88(func_800A44D8(i));
        p = &D_800F7DAC;
        mask = 1 << i;
        *p &= ~mask;
        D_800F7DC2 |= mask;
        D_800F39DC = (D_800F39DC + 1) & 0xF;
    }
}

void func_800A4480(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        D_800F5BF2[i].a = D_800F8408[i].b;
        D_800F5BF2[i].b = D_800F8408[i].a;
    }
}

s32 func_800A44D8(s32 arg0) {
    s32 i;

    if (arg0 >= 4 && ((D_800F7DCA >> arg0) & 1)) {
        for (i = 0; i < 3; i++) {
            if (D_800F5E66[i][0] == arg0) {
                arg0 = i;
                break;
            }
        }
    }
    return arg0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800A4540);

void func_800A4844(s32 arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (arg0 != 0) {
        var_v0 = 3;
    }
    D_800F39EC = var_v0;
}

s32 func_800A4860(void) {
    s32 i;
    s32 ret;

    ret = 0;
    D_800F39EC = 0;
    D_800F83D0[0] |= 2;
    for (i = 0; i < 3; i++) {
        func_800A7254(0, i, 4, 0);
    }
    for (i = 0; i < 4; i++) {
        func_800A3354();
    }
    D_800F3896 = 0x1C;
    func_800D9E0C(-1, -1, 0x1C);
    while (D_800F39EC == 0) {
        func_800A3354();
    }
    if (D_800F39EC & 2) {
        func_800E60F8();
        ret = 1;
    }
    return ret;
}

s32 func_800A4954(void) {
    s32 i;
    s32 ret;

    ret = 0;
    D_800F39EC = 0;
    D_800F83D0[0] |= 2;
    for (i = 0; i < 3; i++) {
        func_800A7254(0, i, 4, 0);
    }
    for (i = 0; i < 4; i++) {
        func_800A3354();
    }
    D_800F3896 = 9;
    func_800D9E0C(-1, -1, 9);
    while (D_800F39EC == 0) {
        func_800A3354();
    }
    D_800F83D0[0] &= 0xFFFD;
    for (i = 0; i < 3; i++) {
        func_800A7254(0, i, 6, 0);
    }
    if (D_800F39EC & 2) {
        ret = 1;
    }
    return ret;
}

s32 func_800A4A80(void) {
    s32 var_v1;

    var_v1 = 1;
    if (((u32) (D_80163C7C - 4) < 2U) && !(D_800F9DA4 & 1)) {
        var_v1 = D_800FAFDC != 0;
    }
    return var_v1;
}

void func_800A4ACC(s16 arg0, s32 arg1) {
    func_8001726C(arg0, arg1 & 0xFFFF);
}

void func_800A4AF4(void) {
    if (D_800F9DA4 & 2) {
        do {
            func_800B6D6C();
        } while (D_800F9DA4 & 2);
    }
}

u8 func_800A4B3C(s32 arg0, s32 arg1) {
    if (arg1 != -1) {
        D_8015190F[arg0][0] = arg1;
    }
    return D_8015190F[arg0][0];
}

void func_800A4B9C(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800A4BA4);

u8 func_800A4CA8(s32 arg0) {
    return D_800F39F0[arg0].a;
}

s32 func_800A4CC8(s32 arg0) {
    s32 v;

    if (arg0 < 3) {
        v = D_800F5E66[arg0][0];
        if (v >= 4 && ((D_800F7DCA >> v) & 1)) {
            arg0 = v;
        }
    }
    return arg0;
}

void func_800A4D2C(s32 arg0) {
    u32 i;
    u8 *p;

    if (D_800F83C6[0] == 0) {
        p = &D_800E7A48;
        for (i = 0; i < 16; i++) {
            if (p[i] == arg0) {
                return;
            }
            if (p[i] == 0xFF) {
                p[i] = arg0;
                return;
            }
        }
    }
}

void func_800A4D88(arg0) {
    u32 i;

    for (i = 0; i < 16; i++) {
        if ((&D_800E7A48)[i] == arg0) {
            for (; i < 15; i++) {
                if (((&D_800E7A48)[i] = (&D_800E7A48)[i + 1]) == 0xFF) {
                    break;
                }
            }
            return;
        }
    }
}

s16 func_800A4E00(void) {
    s16 r;
    s16 t;

    r = -1;
    t = D_800E7A48;
    if ((u8) t != 0xFF) {
        r = func_800A4CC8(t);
    }
    return r;
}

void func_800A4E40(void) {
    u8 temp_s0;

    temp_s0 = D_800E7A48;
    if (temp_s0 != 0xFF) {
        func_800A4D88(temp_s0);
        func_800A4D2C(temp_s0);
    }
}

void func_800A4E80(s32 arg0) {
    u16 *p;
    if (D_800F5E65[arg0][0] != 0xFF) {
        p = &D_80163762;
        *p |= 1 << arg0;
        D_800F5BC0[arg0].a |= 1;
        D_800F5BC6[arg0].a |= 1;
    }
}

void func_800A4F14(s32 arg0) {
    D_800F5BC0[arg0].a &= 0xFFFE;
    D_800F5BC0[arg0].b |= 1;
}

void func_800A4F60(s32 arg0, s32 arg1) {
    s32 f;
    s32 w;

    if (arg0 < 3) {
        f = D_800F5BC6[arg0].a;
        if ((f >> arg1) & 1) {
            w = D_801636C0[arg0].v;
            f &= ~(1 << arg1);
            D_800F5BC6[arg0].a = f;
            switch (arg1) {
            case 0:
                func_800A5250(arg0, w, f);
                break;
            case 1:
                D_800F5BC6[arg0].a = f & 0xDF;
                if (func_800A50E0(arg0, w, 0, 0x38) != 0) {
                    D_800F5BC6[arg0].a |= 0x20;
                }
                break;
            case 2:
                D_800F5BC6[arg0].a = f & 0xBF;
                if (func_800A50E0(arg0, w, 0x38, 0x10) != 0) {
                    D_800F5BC6[arg0].a |= 0x40;
                }
                break;
            case 3:
                D_800F5BC6[arg0].a = f & 0x7F;
                if (func_800A50E0(arg0, w, 0x48, 0x18) != 0) {
                    D_800F5BC6[arg0].a |= 0x80;
                }
                break;
            }
        }
    }
}

s32 func_800A50E0(s32 arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 ret;
    s32 f1;
    s32 h;
    s32 base;
    s32 nv;
    s32 t;
    s32 p;
    s32 id;
    s32 k;
    s32 bad;
    s32 v;
    s32 flags;

    ret = 1;
    f1 = arg1 >> 7;
    f1 ^= 1;
    f1 &= 1;
    arg1 >>= 11;
    arg1 ^= 1;
    arg1 &= 1;
    h = D_800F5BF6[arg0].a;
    t = arg0 * 0x440;
    nv = (s32)D_8009D954;
    base = nv + t + arg2 * 8;
    if (arg3 > 0) {
        p = base;
    loop:
        id = *(u8 *)p;
        flags = 2;
        if (id != 0xFF) {
            k = id + arg2;
            v = D_800708D0[k * 0x1C];
            bad = 0;
            if (k < 0x38) {
                if (v & 8) {
                    if (*(u8 *)(p + 2) == 0 && *(u8 *)(p + 4) == 0) {
                        v &= 0xF3;
                    }
                    if (v & 8) {
                        flags |= 0x10;
                    }
                }
                if (*(u8 *)(p + 4) != 0) {
                    flags |= 0x10;
                    v &= ~8;
                    v |= 4;
                }
            } else {
                do {
                    if (k < 0x48 && *(u8 *)(p + 2) == 0) {
                        bad = 1;
                    }
                } while (0);
            }
            *(u8 *)(p + 5) = v;
            if (h >= *(u8 *)(p + 1) && bad == 0 && f1 && (arg1 || k == 0xA)) {
                flags &= ~2;
                ret = 0;
            }
        }
        *(u8 *)(p + 6) = flags;
        p += 8;
        if (p < arg3 * 8 + base) {
            goto loop;
        }
    }
    return ret;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800A5250);

void func_800A555C(s32 arg0, s32 arg1) {
    Ent8 *p;

    p = &((Row440 *)D_8009D84C)[arg0].e[arg1];
    p->g = 2;
    p->f = D_800708D0[arg1 * 0x1C];
    p->b = *(u16 *)&D_800708C8[arg1 * 0x1C];
    p->a = arg1 - 0x48;
}

void func_800A55BC(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_800F3A40[i].a = -1;
        D_800F3A40[i].b = -1;
    }
}

void func_800A55F4(s16 arg0, s16 arg1) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (D_800F3A40[i].a == arg0 && D_800F3A40[i].b == arg1) {
            D_800F3A40[i].a = -1;
            D_800F3A40[i].b = -1;
            break;
        }
    }
}

void func_800A5660(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (D_800F3A40[i].b == -1) {
            D_800F3A40[i].a = arg0;
            D_800F3A40[i].b = arg1;
            break;
        }
    }
}

void func_800A56B0(s16 arg0) {
    s32 i;
    s16 v;

    for (i = 0; i < 16; i++) {
        v = D_800F3A40[i].b;
        if (v != -1 && D_800F3A40[i].a == arg0) {
            D_800F3A20[D_800F3A1C++] = v;
            D_800F3A1C &= 0xF;
            D_800F3A40[i].a = -1;
            D_800F3A40[i].b = -1;
        }
    }
}

void func_800A5750(void) {
    BtlInvSlot *tab;
    BtlInvSlot *q;
    s16 id;
    s32 x;
    s32 i;
    s32 e;
    s32 n;
    u8 pad[8];

    if (D_800F3A1C != D_800F3A18) {
        tab = D_801671B8;
        do {
            e = -1;
            x = D_800F3A20[D_800F3A18];
            id = x;
            D_800F3A18++;
            if (x < 0x180) {
                n = 0;
                i = 0;
                do {
                    if (tab[i].a == x) {
                        if (tab[i].qty < 0x63) {
                            tab[i].qty++;
                        }
                        break;
                    }
                    if (tab[i].a == 0xFFFF && e == -1) {
                        e = i;
                    }
                    i++;
                } while (i < 0x140);
                if (i == 0x140 && e != -1) {
                    q = (BtlInvSlot *)(e * 6 + (s32)tab);
                    q->qty = 1;
                    q->kind = 3;
                    q->a = id;
                    if (id < 0x80) {
                        q->kind = D_800722D8[id][0];
                        q->c = D_800722D6[id].v;
                    } else if (id < 0x100) {
                        q->kind = D_800738A0[id - 0x80][0];
                        q->c = D_800738CA[id - 0x80].v;
                    } else if (id < 0x120) {
                        q->c = D_80071E64[id - 0x100].v;
                    } else if (id < 0x140) {
                        q->c = D_80071C32[id - 0x120].v;
                    }
                    n = (e + 1) / 2;
                    q->c &= 0xB;
                }
                D_80166F75 = 0xFF;
                if (D_80166F74 < n) {
                    D_80166F74 = n;
                }
            }
            D_800F3A18 &= 0xF;
        } while (D_800F3A1C != D_800F3A18);
    }
}

s32 func_800A5990(void) {
    s32 i;
    s32 n;
    u16 v;
    u8 c;
    u16 buf[320];
    s32 w;
    s32 r;

    r = 0xFFFF;
    n = 0;
    for (i = 0; i < 320; i++) {
        v = D_801671B8[i].a;
        c = D_801671B8[i].c;
        if (v != 0xFFFF && !(c & 9)) {
            buf[n++] = v;
        }
    }
    if (n != 0) {
        w = buf[func_80014BA8(n)];
        if ((u32)(w - 0x80) < 0x80) {
            func_800A7254(0, 0, 0x10, w);
            r = w;
        }
    }
    return r;
}

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text1c", D_800A0240);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800A5A5C);

void func_800A5A88(void) {
    func_80014BA8(0x36);
}

s32 func_800A5AA8(void) {
    return func_80014BA8(0x10) + 0x38;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800A5AC8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800A5BC8);

s32 func_800A5E0C(u8 *dst, u8 *src, u16 *args) {
    s32 n;
    u8 c;
    u8 hi;
    u8 lo;
    u16 v;

    n = 0;
    while (1) {
        c = *src++;
        n++;
        *dst++ = c;
        if (c == 0xFF) {
            break;
        }
        if (c == 0xF9) {
            *dst++ = *src++;
            n++;
        } else if ((u8)(c + 0x16) < 8) {
            hi = *src++;
            lo = *src++;
            if (hi == 0xFF && lo == hi) {
                v = *args++;
                hi = v >> 8;
                lo = v;
            }
            *dst++ = hi;
            *dst++ = lo;
            n += 2;
        }
    }
    return n;
}

s32 func_800A5EB0(u8 *arg0, u16 *arg1) {
    u8 buf[0x100];
    s32 n;
    s32 i;
    s32 idx;

    n = func_800A5E0C(buf, arg0, arg1);
    if (D_800F4300 + n > 0x800) {
        D_800F4300 = 0;
    }
    idx = D_800F4304++;
    D_800F4280[idx] = D_800F4300;
    D_800F4304 &= 0x3F;
    for (i = 0; i < n; i++) {
        D_800F3A80[D_800F4300 + i] = buf[i];
    }
    D_800F4300 += n;
    return idx;
}

u8 *func_800A5F90(s32 arg0) {
    return D_800F4280[arg0] + D_800F3A80;
}

u8 *func_800A5FB0(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *r;

    r = 0;
    if (arg1 != -1) {
        arg1 = ((u16 *) arg0)[arg1];
        if (arg1 != 0xFFFF) {
            arg0 += arg1 & 0xFFFE;
            arg1 = ((u16 *) arg0)[arg2];
            if (arg1 != 0xFFFF) {
                r = arg0 + arg1;
            }
        }
    }
    return r;
}

s32 func_800A6000(s32 arg0, s32 arg1, s32 arg2) {
    u8 buf[10][5];
    u8 *r;
    s32 id;
    s32 i;
    u16 *p;
    s32 v;

    r = 0;
    id = -1;
    p = &D_800F7DBC;
    *p |= 1 << arg1;
    if (arg0 >= 4) {
        r = func_800A5FB0((u8 *)p - 0x1018, D_80163658[arg0 - 4].a, arg1);
    } else if (arg0 < 3) {
        id = D_801636B8[arg0].a;
        if (id != -1) {
            v = D_800E7A58[id];
            if (v != 0xFF) {
                id = v;
            }
        }
        r = func_800A5FB0(D_80082884, id, arg1);
    }
    if (r != 0) {
        for (i = 0; i < 10; i++) {
            buf[i][0] = D_800F83F3[i][0];
            buf[i][1] = D_800F83F0[i][0];
            buf[i][2] = D_800F83F1[i][0];
        }
        func_800B2A2C(arg0, arg2);
        func_800B1D48(arg0, r, id);
        for (i = 0; i < 10; i++) {
            if (buf[i][0] != D_800F83F3[i][0]) {
                func_800A31A0(i, 4, D_800F83F3[i][0], 0x10);
            }
            if (buf[i][2] != D_800F83F1[i][0]) {
                func_800A34CC(i, buf[i][2], D_800F83F1[i][0], 0);
            }
        }
    }
}

void func_800A61D4(void) {
    s32 i;
    u8 *p;
    u16 *m;

    func_800B2A2C(-1, 0);
    i = 0;
    m = &D_800F7DBC;
loop:
    if ((*m >> i) & 1) {
        *m &= ~(1 << i);
        p = func_800A5FB0((u8 *)m - 0x1218, D_800F83CC & 3, i);
        if (p != NULL) {
            func_800B1D48(3, p, -1);
        }
    }
    i++;
    if (i < 8) goto loop;
}

void func_800A6278(s32 arg0, s32 arg1, s32 arg2) {
    s32 r;
    u8 c;

    r = 0;
    if (arg1 >= 4) {
        if (!(D_800F5BE1[arg1].a & 0x20)) {
            D_800F5BE1[arg1].a |= 0x20;
            if (arg0 < 3) {
                D_800F5E67[arg0][0] += 1;
            }
        }
    }
    if (!(D_800F83E4[arg1][0] & 0x2000)) {
        c = D_800F6B9B[0];
        D_800F83E4[arg1][0] |= 0x2000;
        if (arg0 >= 4) {
            func_800A5BC8(arg1, 0);
        }
        if (arg0 != arg1) {
            D_800F83F8[arg1][1] = 1 << arg0;
        } else {
            D_800F83F8[arg1][1] = 0;
        }
        func_800A6000(arg1, 3, 0);
        if (D_800F6B9B[0] != c || arg2 != 0) {
            if (!(D_800F83E4[arg1][0] & 0x1000)) {
                D_800F83B2 = 1 << arg1;
                ((void (*)(s32, s32, s32))func_800B2B5C)(arg1, 0x25, 0);
            }
            r = 1;
        }
    }
    if (D_800F83E4[arg1][0] & 0x1000) {
        r = 1;
    }
    if (r != 0 && arg2 == 0) {
        func_800A3488(arg1);
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800A64A0);

u16 func_800A64B4(s32 arg0) {
    u16 r;

    r = 0xFFFF;
    if (D_801671BA[arg0][0] != 0) {
        D_801671BA[arg0][0]--;
        r = D_801671B8[arg0].a;
        if (D_801671BA[arg0][0] == 0) {
            D_801671B8[arg0].a = 0xFFFF;
            D_801671BC[arg0][0] = 10;
        }
        D_80166F75 = 0xFF;
    }
    return r;
}

void func_800A653C(s32 arg0) {
    s32 i;
    u16 *p;

    i = func_800A44D8(arg0);
    D_800F5BBC[i].a = 0;
    p = &D_800F7DC2;
    *p = *p & ~(1 << i);
}

void func_800A6590(void) {
    func_800A4D88();
}

void func_800A65B0(s32 arg0) {
    u16 *p;

    if (arg0 < 3) {
        func_800A4F14(arg0);
        p = &D_80163762;
        D_8009D866[arg0].v = 0;
        *p &= ~(1 << arg0);
    }
}

void func_800A661C(s32 arg0) {
    u16 *p;

    func_800A4D88();
    p = &D_800F7DAC;
    if ((*p >> arg0) & 1) {
        if (D_800F5BBC[arg0].a == 0xFFFF) {
            func_800A4D2C(arg0);
        } else {
            *p &= ~(1 << arg0);
        }
    }
}

void func_800A66A4(s32 arg0, s32 arg1) {
    u16 *p;

    func_800A653C(arg0);
    ((void (*)(s32, s32))func_800A65B0)(arg0, arg1);
    func_800A4D88(arg0);
    p = &D_800F7DAC;
    *p &= ~(1 << arg0);
    D_800F7DC4 &= ~(1 << arg0);
}

void func_800A6720(s32 arg0, s16 arg1) {
    func_800A5660(0xA, arg1);
}

void func_800A6748(s32 arg0) {
    u16 *p;

    func_800A653C(arg0);
    func_800A4D88(arg0);
    p = &D_800F7DAC;
    *p = *p & ~(1 << arg0);
}

void func_800A6798(s32 arg0, s32 arg1) {
    func_800A37F8(arg1);
}

void func_800A67B8(s32 arg0) {
    u16 *p;

    func_800A4D88();
    p = &D_800F7DC4;
    *p |= 1 << arg0;
    if ((D_800F7DAC >> arg0) & 1) {
        func_800A4350(arg0, ((s32 (*)(s32))func_800A4CA8)(arg0), 0, 0);
    }
}

void func_800A6834(s32 arg0) {
    u16 *p = &D_800F7DC4;
    *p = *p & ~(1 << arg0);
}

void func_800A6858(s32 arg0, s32 arg1) {
    u16 *p;
    u16 *q;

    if (arg1 != 0) {
        func_800A66A4(arg0, arg1);
        p = &D_800F7DCA;
        *p |= 1 << arg0;
    } else {
        q = &D_800F7DCA;
        *q &= ~(1 << arg0);
        if ((D_800F7DAC >> arg0) & 1) {
            func_800A4D88(arg0);
            func_800A4350(arg0, -1, 0, 0);
        }
    }
}

void func_800A68FC(s32 arg0) {
    s32 i;
    s32 n;
    s32 k;
    u16 r;

    n = 0;
    r = 0xFFFF;
    for (i = 0; i < 0x140; i++) {
        if (D_801671B8[i].a != 0xFFFF && !(D_801671B8[i].c & 1)) {
            n++;
        }
    }
    if (n != 0) {
        k = D_800F7DD0 % n;
        for (i = 0; i < 0x140; i++) {
            if (D_801671B8[i].a != 0xFFFF && !(D_801671B8[i].c & 1)) {
                k--;
                if (k < 0) {
                    r = func_800A64B4(i);
                    break;
                }
            }
        }
        if (r != 0xFFFF) {
            func_800A7254(1, arg0, 2, r);
        }
    }
}

void func_800A6A3C(s32 arg0, s32 arg1) {
    D_800F5BC6[arg0].a |= arg1;
}

void func_800A6A70(s32 arg0, s32 arg1) {
    func_800A555C(arg0, arg1);
    D_800F5BC6[arg0].a |= 9;
}

void func_800A6AC4(void) {
    u16 *p;

    p = &D_800F7DC4;
    *p = *p & 0xFC0F;
    D_800F7DCA &= 0xFC0F;
    D_800F7DAC &= 0xFC0F;
    D_800F7DC2 &= 0xFC0F;
}

void func_800A6B1C(void) {
    s32 i;
    u16 *p = &D_800F7DC4;

    for (i = 0; i < 3; i++) {
        if (!((*p >> i) & 1)) {
            if ((p[-1] >> i) & 1) {
                p[-1] &= ~(1 << i);
                p[-12] |= 1 << i;
            }
        }
    }
}

void func_800A6B88(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 0x140; i++) {
        if (D_801671B8[i].a == arg1) {
            if (!(D_801671B8[i].c & 9)) {
                func_800A64B4(i);
            }
            break;
        }
    }
}

void func_800A6BFC(void) {
}

void func_800A6C04(s32 arg0) {
    s16 buf;

    buf = D_801636B8[arg0].a;
    D_800F7DBE = func_800A5EB0(func_800151F4(0x26), &buf) + 0x100;
    D_800F7DC0 = 0xF;
}

void func_800A6C5C(s32 arg0, s32 arg1) {
    func_800A7254(2, arg0, 0x14, arg1);
    D_800F8432[arg0][0] = arg1;
}

void func_800A6CC0(s32 arg0, s32 arg1) {
    s32 m;

    m = 1 << D_800A04D0[arg1];
    D_800F83E0[arg0].a &= ~m;
}

void func_800A6D10(s32 arg0) {
    func_800A3E98(arg0, 3, 2, 0x36, 0);
}

void func_800A6D3C(s32 arg0) {
    if (D_800F83E0[arg0].a & 0x2000) {
        D_800F83E0[arg0].a = (D_800F83E0[arg0].a & ~0x2000) | 0x4000;
    }
}

void func_800A6D88(s32 arg0) {
    if (D_800F83E0[arg0].a & 8) {
        D_800F5BC8[arg0][6] = 0xA;
        func_800A3E98(arg0, 3, 0x23, 0, 0);
    }
}

void func_800A6DFC(void) {
}

void func_800A6E04(void) {
}

void func_800A6E0C(s32 arg0) {
    if (arg0 < 3) {
        D_800F5E68[arg0].b = 0;
        D_800F5E68[arg0].a = 0;
        func_800A7254(0, arg0, 1, 0);
    }
}

void func_800A6E6C(s32 arg0, M2C_UNK arg1) {
    func_800A7254(0, arg0, 0xD, arg1);
}

void func_800A6E9C(s32 arg0, s32 arg1) {
    s32 i;
    s32 j;
    s32 m;

    for (i = 0; i < 3; i++) {
        m = 1 << i;
        if (arg1 & m) {
            D_800F83AE[0] &= ~m;
            D_800F83AE[7] &= ~m;
            D_8009CBDC[i] = 0xFF;
            D_801636B8[i].a = -1;
            D_800F83E8[i].a = -1;
            D_800F83EC[i].a = 0xFF;
            D_800F83E0[i].a = 0;
            D_800F83E4[i][0] = 0;
            D_800F5BBE[i].a = 0;
            for (j = 0; j < 0x10; j++) {
                D_800F5BC8[i][j] = 0;
            }
            for (j = 0; j < 0x40; j++) {
                if (D_800F6936[j][0] == i) {
                    D_800F6936[j][0] = -1;
                }
            }
            func_800AE954(i);
            func_800A56B0(i);
            func_800A7254(0, i, 2, 0);
        }
    }
}

void func_800A7034(s32 arg0, u16 arg1) {
    u16 sp10;

    sp10 = arg1;
    func_800B0FFC(arg0, 0x53, 1, &sp10);
}

void func_800A7060(s32 arg0, M2C_UNK arg1) {
    func_800A7254(0, arg0, 0xC, arg1);
}

void func_800A7090(s32 arg0) {
    D_800F5BE0[arg0].b[0] |= 0x40;
}

void func_800A70C4(s32 arg0, s32 arg1) {
    func_800B10F0(arg0, 0x34, 2, D_800708D0[arg1 * 0x1C + 1], 0, 9, D_800F83E0[arg0].a);
}

void func_800A7130(s32 arg0, s32 arg1) {
    if (arg0 < 3) {
        if (arg1 != 0) {
            ((BtlSlotV *)D_8009D85C)[arg0].hp = D_800F8410[arg0][0];
            D_8009D862[arg0].v = D_800F840A[arg0][0];
        } else {
            ((BtlSlotV *)D_8009D85C)[arg0].hp = D_800F5E72[arg0][0];
            D_8009D862[arg0].v = D_800F5E70[arg0][0];
        }
    }
}

void func_800A71E0(void) {
}

s32 func_800A71E8(s32 arg0) {
    return (arg0 + 1) & 0x7F;
}

void func_800A71F4(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        for (j = 0x7F; j >= 0; j--) {
            D_800F4308[i][j].a = 0xFF;
        }
        D_800F4908[i] = 0;
        D_800F4914[i] = 0;
    }
}

void func_800A7254(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *p;
    s32 n;
    T4 *e;

    n = D_800F4914[arg0];
    p = &D_800F4914[arg0];
    e = &D_800F4308[arg0][n];
    if (e->a == 0xFF) {
        M2C_SFIELD(e, s16 *, 2) = arg3;
        M2C_SFIELD(e, u8 *, 1) = arg2;
        e->a = arg1;
        *p = func_800A71E8(n);
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800A72C8);

void func_800A73C0(void) {
    M2C_FIELD(D_80063014, s32 *, 0x2C) = (s32) M2C_FIELD(D_80063014, s32 *, 0x10);
}

void func_800A73D8(void) {
    M2C_FIELD(D_80063014, s32 *, 0x2C) = (s32) (M2C_FIELD(D_80063014, s32 *, 0x10) + 0x38);
}

void func_800A73F8(void) {
    s32 v;
    s32 p;

    M2C_FIELD(D_80063014, s32 *, 0x2C) = M2C_FIELD(D_80063014, s32 *, 0x10);
    M2C_FIELD(D_80063014, s32 *, 0x24) = M2C_FIELD(D_80063014, s32 *, 0x10);
    func_800A55F4(M2C_FIELD(D_80063014, s16 *, 0), M2C_FIELD(D_80063014, s16 *, 0x2C));
    p = D_80063014;
    v = M2C_FIELD(p, s32 *, 0x18) & 0xF;
    if (v) {
        v = 0x20;
    } else {
        v = 0x21;
    }
    M2C_FIELD(p, s32 *, 0x20) = v;
}

void func_800A7458(void) {
    s32 t;
    s32 off;

    if (M2C_FIELD(D_80063014, s32 *, 0x10) == 0xFFFF) {
        M2C_FIELD(D_80063014, s32 *, 0x10) = func_800A5990() & 0xFFFF;
    }
    t = M2C_FIELD(D_80063014, s32 *, 0x10);
    if (t != 0xFFFF) {
        M2C_FIELD(D_80063014, s32 *, 0x2C) = t;
        M2C_FIELD(D_80063014, s32 *, 0x98) = M2C_FIELD(D_80063014, s32 *, 0x10);
        M2C_FIELD(D_80063014, s32 *, 0x24) = M2C_FIELD(D_80063014, s32 *, 0x10) - 0x80;
        func_800A55F4(M2C_FIELD(D_80063014, s16 *, 0), M2C_FIELD(D_80063014, s16 *, 0x2C));
        M2C_FIELD(D_80063014, s32 *, 0x48) = 0x10;
        off = M2C_FIELD(D_80063014, s32 *, 0x24) * 0x2C;
        M2C_FIELD(D_80063014, s32 *, 0xD8) = *(&D_800738A4 + off) + *(&D_8009D84E + M2C_FIELD(D_80063014, s32 *, 0) * 0x440);
        M2C_FIELD(D_80063014, s32 *, 0x68) = *(&D_800738C7 + off);
        return;
    }
    M2C_FIELD(D_80063014, s32 *, 0x20) = -1;
}

void func_800A7560(void) {
    s32 amount;
    s32 i;
    s32 n;
    u32 max;
    s32 mask;
    u32 *p;
    u32 g;

    amount = M2C_FIELD(D_80063014, s32 *, 0x10) * 10;
    if (M2C_FIELD(D_80063014, s32 *, 0x10) == 0xFFFF) {
        max = 0;
        n = 0;
        mask = D_80163758 & 0x3F0;
        for (i = 4; i < 10; i++) {
            if ((mask >> i) & 1) {
                if (max < D_800F840C[i].a) {
                    max = D_800F840C[i].a;
                }
                n++;
            }
        }
        if ((s32)max >= 0x2711) {
            max = 0x2710;
        }
        amount = max * n * 10;
    }
    if (amount > 0x927C0) {
        amount = 0x927C0;
    }
    if (!(M2C_FIELD(D_80063014, s32 *, 0x90) & 0x400000)) {
        p = D_8009D260;
        g = *p;
        if (g < (u32)amount) {
            amount = g;
        }
        *p = g - amount;
    }
    M2C_FIELD(D_80063014, s32 *, 0x48) = M2C_FIELD(D_80063014, s32 *, 0x10) = amount / 10;
    M2C_FIELD(D_80063014, s32 *, 0x98) = M2C_FIELD(D_80063014, s32 *, 0x10);
}

void func_800A76AC(void) {
    M2C_FIELD(D_80063014, s32 *, 0x2C) = (s32) (M2C_FIELD(D_80063014, s32 *, 0x10) + 0x48);
}

void func_800A76CC(void) {
    s32 v;

    M2C_FIELD(D_80063014, s32 *, 0x20) = -1;
    if (func_800B12DC() != 0) {
        v = 4;
        if (D_800F83E4[M2C_FIELD(D_80063014, s32 *, 0)][0] & 0x40) {
            v = 3;
        }
        M2C_FIELD(D_80063014, s32 *, 0x20) = v;
        D_800F83E4[M2C_FIELD(D_80063014, s32 *, 0)][0] ^= 0x40;
    }
}

void func_800A7784(void) {
}

void func_800A778C(void) {
    s32 i;
    s32 v;

    i = M2C_FIELD(D_80063014, s32 *, 0);
    if (i >= 4) {
        func_800155A4(0x25);
    } else {
        v = M2C_FIELD(D_80063014, s32 *, 0x10);
        M2C_FIELD(D_80063014, s32 *, 0x2C) = v;
        if (v < 0x60) {
            M2C_FIELD(D_80063014, s32 *, 0x2C) = v + 0x80;
            D_800F5E68[i].a = 0;
            D_800F5E64[i][0]++;
            if (!(D_800F83D0[0] & 8)) {
                func_800A7254(2, i, 0x11, 0);
            }
        }
    }
}

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text1c", D_800A0290);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text1c", D_800A029C);

void func_800A784C(void) {
    BtlU16x5 t;
    BtlU8x4 ids;
    u32 i;
    s32 p;

    M2C_FIELD(D_80063014, s32 *, 0x2C) = D_800F64EC[M2C_FIELD(D_80063014, s32 *, 0x10)];
    if (M2C_FIELD(D_80063014, s32 *, 0xC) == 0x20) {
        t = D_800A0290;
        ids = D_800A029C;
        p = D_80063014;
        for (i = 0; i < 4; i++) {
            if (M2C_FIELD(p, s32 *, 0x2C) < t.v[i + 1]) {
                M2C_FIELD(p, s32 *, 0x28) = ids.v[i];
                M2C_FIELD(p, s32 *, 0x98) = M2C_FIELD(p, s32 *, 0x2C) - t.v[i];
                return;
            }
        }
    }
}

void func_800A7940(void) {
    M2C_FIELD(D_80063014, s32 *, 0x80) = 0x400000;
    M2C_FIELD(D_80063014, s32 *, 0xE4) = 0x59;
}

void func_800A795C(void) {
    func_800B1060(M2C_FIELD(D_80063014, s32 *, 0x10));
}

void func_800A7988(void) {
    func_800AF9C8();
}

void func_800A79A8(void) {
    M2C_FIELD(D_80063014, s32 *, 0x50) = 0;
    M2C_FIELD(D_80063014, s32 *, 0x18) = (s32) (1 << M2C_FIELD(D_80063014, s32 *, 0));
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800A79CC);

void func_800A80DC(void) {
    BtlE722CC *e;
    u16 v;

    M2C_FIELD(D_80063014, s32 *, 0x3C) = 0xFF;
    e = &D_800722CC[M2C_FIELD(D_80063014, s32 *, 0x2C)];
    M2C_FIELD(D_80063014, s32 *, 0x40) = e->xE;
    M2C_FIELD(D_80063014, s32 *, 0x48) = e->xF;
    v = e->x18;
    if (v != 0xFFFF) {
        M2C_FIELD(D_80063014, s32 *, 0x44) = v;
    }
    M2C_FIELD(D_80063014, s32 *, 0x60) = e->x8;
    M2C_FIELD(D_80063014, s32 *, 0x64) = e->x8;
    M2C_FIELD(D_80063014, s32 *, 0x24) = e->xD;
    M2C_FIELD(D_80063014, s32 *, 0x6C) = e->x1A;
    func_800A8D60(e->xC);
    func_800A8DCC(e->x11, e->x14);
    func_800A8D88(e->x12, e->x13);
}

void func_800A81B8(void) {
    s32 p;
    s32 i;
    S24b *q;
    s32 r;
    s32 n;

    p = D_80063014;
    i = M2C_FIELD(p, s32 *, 0);
    M2C_FIELD(p, s32 *, 0x48) = 0x10;
    if (i < 3) {
        q = &D_800F5EFC[i];
        M2C_FIELD(p, s32 *, 0x24) = q->pad[0];
        M2C_FIELD(p, s32 *, 0x40) = q->pad[1];
        M2C_FIELD(p, s32 *, 0x3C) = q->pad[2];
        M2C_FIELD(p, s32 *, 0x68) = q->pad[3];
        M2C_FIELD(p, s32 *, 0x44) = M2C_FIELD(q, u16 *, 0xE);
        func_800A8DCC(5, M2C_FIELD(q, s32 *, 0x14));
        if (M2C_FIELD(D_80063014, s32 *, 0x60) == 0xFFFF) {
            M2C_FIELD(D_80063014, s32 *, 0x60) = M2C_FIELD(q, u16 *, 0x10);
        }
        if (M2C_FIELD(D_80063014, s32 *, 0x64) == 0xFFFF) {
            M2C_FIELD(D_80063014, s32 *, 0x64) = M2C_FIELD(q, u16 *, 0x10);
        }
        M2C_FIELD(D_80063014, s32 *, 0x6C) = M2C_FIELD(q, u16 *, 0x12);
        func_800A8D60(q->a);
        r = D_80063014;
        for (n = 0; n < 3; n++) {
            M2C_FIELD(r, s32 *, 0x54) = M2C_FIELD(q, s16 *, 8 + n * 2);
            r += 4;
        }
        M2C_FIELD(D_80063014, s32 *, 0x44) |= D_8009D888[M2C_FIELD(D_80063014, s32 *, 0)].flags;
    }
    if (D_800F83E0[M2C_FIELD(D_80063014, s32 *, 0)].a & 0x04000000) {
        M2C_FIELD(D_80063014, s32 *, 0x3C) >>= 1;
    }
    if (D_800F83E0[M2C_FIELD(D_80063014, s32 *, 0)].a & 0x800) {
        M2C_FIELD(D_80063014, s32 *, 0x54) = 0x16B;
        M2C_FIELD(D_80063014, s32 *, 0x58) = 0x16C;
        M2C_FIELD(D_80063014, s32 *, 0x5C) = 5;
        M2C_FIELD(D_80063014, s32 *, 0x68) = 0;
    }
    if (D_800F5BF4[M2C_FIELD(D_80063014, s32 *, 0)].a == 0x1E61) {
        M2C_FIELD(D_80063014, s32 *, 0x44) = 0;
        M2C_FIELD(D_80063014, s32 *, 0x80) = 0;
        M2C_FIELD(D_80063014, s32 *, 0x84) = 0;
        M2C_FIELD(D_80063014, s32 *, 0x88) = 0;
    }
}

void func_800A8424(void) {
    BEnt12 *p;
    s8 *q;

    if (M2C_FIELD(D_80063014, s32 *, 0x20) >= 0) {
        p = func_800A2F4C();
        p->a = M2C_FIELD(D_80063014, s32 *, 0);
        p->b = M2C_FIELD(D_80063014, s32 *, 0x1C);
        p->c = M2C_FIELD(D_80063014, s32 *, 0x20);
        p->pad[1] = M2C_FIELD(D_80063014, s32 *, 0x28);
        p->pad[0] = M2C_FIELD(D_80063014, s32 *, 0x24);
        p->e = M2C_FIELD(D_80063014, s32 *, 0x60);
        p->pad[2] = 0;
        q = func_800A2FD0();
        q[0] = M2C_FIELD(D_80063014, s32 *, 0);
        q[1] = M2C_FIELD(D_80063014, s32 *, 0);
        q[2] = 0;
        *(s16 *)(q + 4) = 0;
        func_800A317C();
    }
}

void func_800A8528(void) {
    M2C_FIELD(D_80063014, s32 *, 0xB4) = 4;
}

void func_800A853C(void) {
    s32 var_s0;

    var_s0 = 0;
    do {
        if (((s32) M2C_FIELD(D_80063014, s32 *, 0x18) >> var_s0) & 1) {
            func_800A6000(var_s0, M2C_FIELD(D_80063014, s32 *, 0x10), 0);
        }
        var_s0 += 1;
    } while (var_s0 < 0xA);
}

void func_800A85A0(void) {
    M2C_FIELD(D_80063014, s32 *, 0xB4) = 2;
}

void func_800A85B4(void) {
    M2C_FIELD(D_80063014, s32 *, 0x44) = 0x10;
    M2C_FIELD(D_80063014, s32 *, 0x48) = 1;
    M2C_FIELD(D_80063014, s32 *, 0x50) = 0;
    if (!(((s32) D_8016375A >> M2C_FIELD(D_80063014, s32 *, 0)) & 1)) {
        M2C_FIELD(D_80063014, s32 *, 0x20) = -1;
    }
}

void func_800A85FC(void) {
    u32 x;

    if (M2C_SFIELD(D_80063014, s32 *, 0) < 3) {
        M2C_SFIELD(D_80063014, s32 *, 0x20) = -1;
    } else {
        M2C_SFIELD(D_80063014, s32 *, 0xC) = 1;
        M2C_SFIELD(D_80063014, s32 *, 0x50) = 0;
        x = func_800B3030(M2C_SFIELD(D_80063014, u16 *, 0x18)) & 0xFFFF;
        M2C_SFIELD(D_80063014, s32 *, 0x18) = x;
        M2C_SFIELD(D_80063014, s32 *, 0) = func_80014A38(x);
        M2C_SFIELD(D_80063014, s32 *, 0x20) = 0x2F;
    }
}

void func_800A866C(void) {
    s32 sp10[10];
    s32 ids[3];
    u16 msg[4];
    s32 mask;
    s32 cnt;
    s32 n;
    s32 i;
    s32 j;
    s32 id;
    s32 t;
    s32 div;
    s32 flag;
    u16 *p;
    s32 a;

    flag = 0x20;
    n = 0;
    cnt = 0;
    mask = M2C_FIELD(D_80063014, s32 *, 0x18);
    for (i = 0; i < 3; i++) {
        ids[i] = -1;
    }
    for (i = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            if ((u32)D_800F8410[i][0] >= 0x7530) {
                mask &= ~(1 << i);
            }
        }
    }
    i = 0;
    if (mask == 0) {
        func_800B0FFC(M2C_FIELD(D_80063014, s32 *, 0), 0x76, flag, msg);
        return;
    }
    do {
        sp10[i] = 0;
        if ((mask >> i) & 1) {
            id = D_800F8404[i].a;
            for (j = 0; j < 3; j++) {
                if (id == ids[j]) {
                    break;
                }
            }
            if (j == 3) {
                for (j = 0; j < 3; j++) {
                    if (ids[j] == -1) {
                        ids[j] = id;
                        break;
                    }
                }
                for (j = 0; j < 0x10; j++) {
                    t = 1 << j;
                    if (func_800AE6C0(i, t, 0) < 3) {
                        n++;
                        sp10[i] |= t;
                    }
                }
            }
            cnt++;
        }
        i++;
    } while (i < 10);
    div = 0x3C;
    if (cnt >= 2) {
        div = 0x5A;
    }
    if (cnt * 2 + n != 0) {
        div = div / (cnt * 2 + n);
    }
    i = 0;
    if (div < 4) {
        div = 4;
    }
    p = msg;
    do {
        if ((mask >> i) & 1) {
            func_800A7254(2, i, 0x16, 0);
            msg[0] = i;
            msg[1] = 0xFFFF;
            if (D_800F5BC7[i].a != 0xFF) {
                msg[1] = D_800F5BC7[i].a;
            }
            msg[2] = D_800F83E8[i].b;
            func_800B0FFC(M2C_FIELD(D_80063014, s32 *, 0), 0x74, flag, p);
            func_800A3208(div, 0x2D7);
            msg[0] = D_800F840C[i].a;
            msg[1] = D_800F8410[i][0];
            msg[2] = D_800F8408[i].a;
            msg[3] = D_800F840A[i][0];
            a = 0x72;
            if (D_800F840A[i][0] != 0) {
                a = 0x75;
            }
            func_800B0FFC(M2C_FIELD(D_80063014, s32 *, 0), a, 1, p);
            j = 0;
            func_800A3208(div, 0);
            do {
                if ((sp10[i] >> j) & 1) {
                    msg[0] = j + 0x5D;
                    func_800B0FFC(M2C_FIELD(D_80063014, s32 *, 0), 0x6D, 1, msg);
                    func_800A3208(div, 0);
                }
                j++;
            } while (j < 0x10);
            flag = 1;
        }
        i++;
    } while (i < 10);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800A8A6C);

void func_800A8C94(void) {
    M2C_FIELD(D_80063014, s32 *, 0x8C) = 0xFF;
    M2C_FIELD(D_80063014, s32 *, 0x40) = 0xB0;
    M2C_FIELD(D_80063014, s32 *, 0x80) = (s32) (M2C_FIELD(D_80063014, s32 *, 0x80) | 1);
    M2C_FIELD(D_80063014, s32 *, 0x3C) = (s32) ((s32) M2C_FIELD(D_80063014, s32 *, 0x3C) >> 1);
}

void func_800A8CC8(void) {
    s32 p = D_80063014;

    M2C_FIELD(p, s32 *, 0x6C) &= ~0x2000;
    M2C_FIELD(p, s32 *, 0x3C) /= 3;
}

void func_800A8D04(void) {
    M2C_FIELD(D_80063014, s32 *, 0x48) = 2;
}

void func_800A8D18(void) {
    func_800A8D60(D_800F5EFC[M2C_FIELD(D_80063014, s32 *, 0)].a);
}

void func_800A8D60(s32 arg0) {
    if (M2C_FIELD(D_80063014, s32 *, 0x50) == 0xFF) {
        M2C_FIELD(D_80063014, s32 *, 0x50) = arg0;
    }
}

void func_800A8D88(s32 arg0, s32 arg1) {
    M2C_FIELD(D_80063014, s32 *, 0xBC) = -1;
    if (arg0 != 0xFF) {
        M2C_FIELD(D_80063014, s32 *, 0xBC) = arg0;
        M2C_FIELD(D_80063014, s32 *, 0xC0) = arg1;
        func_800A8E84(2);
    }
}

void func_800A8DCC(u32 arg0, s32 arg1) {
    s32 i;
    s32 s;

    i = arg0 >> 6;
    M2C_FIELD(D_80063014, s32 *, 0x80) = 0;
    M2C_FIELD(D_80063014, s32 *, 0x84) = 0;
    M2C_FIELD(D_80063014, s32 *, 0x88) = 0;
    if (i < 3) {
        s = (arg0 & 0x3F) * 4;
        if (arg1 & 0x80000000) {
            M2C_FIELD(D_80063014, s32 *, 0x80) = 0x80000000;
            D_800F7DC6 = arg1 & 3;
        } else {
            M2C_FIELD(D_80063014, s32 *, 0x8C) = s;
            ((s32 *)(D_80063014 + 0x80))[i] = arg1;
        }
    }
}

void func_800A8E34(void) {
    func_800A79CC();
}

void func_800A8E54(s32 arg0) {
    s32 temp_a0;

    M2C_FIELD(D_80063014, s32 *, 0xF8) = arg0;
    temp_a0 = arg0 + 3;
    M2C_FIELD(D_80063014, s32 *, 0xAC) = temp_a0;
    if (temp_a0 >= 9) {
        M2C_FIELD(D_80063014, s32 *, 0xAC) = 8;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800A8E84);

void func_800A9C24(void) {
    s32 s;
    s32 i;
    s32 t;

    for (i = 0; i < 7; i++) {
        if (D_80163774[0] == D_800E7BA4[i].r && D_80163774[1] == D_800E7BA4[i].g && D_80163774[2] == D_800E7BA4[i].b) {
            break;
        }
    }
    if (i != 0) {
        M2C_FIELD(D_80063014, s32 *, 0x2C) = i + 0x68;
    } else {
        s = 4;
        for (i = 0; i < 4; i++) {
            s += func_80014BA8(10) & 0xFF;
            func_80014B54();
        }
        s = s + M2C_FIELD(D_80063014, s32 *, 4) / 21;
        s /= 2;
        s -= 4;
        if (s < 0) {
            s = 0;
        }
        if (s >= 0x10) {
            s = 0xF;
        }
        M2C_FIELD(D_80063014, s32 *, 0x2C) = s + 0x38;
        M2C_FIELD(D_80063014, s32 *, 0x28) = 3;
    }
    t = M2C_FIELD(D_80063014, s32 *, 0x20);
    M2C_FIELD(D_80063014, s32 *, 0x50) = 0xFF;
    M2C_FIELD(D_80063014, s32 *, 0x98) = M2C_FIELD(D_80063014, s32 *, 0x2C);
    func_800A8E34();
    M2C_FIELD(D_80063014, s32 *, 0x20) = t;
    M2C_FIELD(D_80063014, s32 *, 0x38) = 0;
}

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text1c", D_800A0398);

void func_800A9DA0(void) {
    s32 acc[8];
    s32 n;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 id;
    s32 i;
    s32 t;
    s32 lim1;
    s32 lim2;
    u16 *p;
    s32 one;

    n = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    id = M2C_FIELD(D_80063014, s32 *, 0);
    lim1 = D_800F5E70[id][3];
    lim2 = D_800F5E70[id][2];
    for (i = 0; i < 8; i++) {
        acc[i] = 0;
    }
    i = 0;
    one = 1;
    p = &D_800F7DD2;
    for (; i < 3; i++) {
        if (D_800F83E8[i].a != -1) {
            acc[0] += D_800F83ED[i].a;
            acc[1] += D_800F83EE[i].a;
            acc[2] += D_800F8400[i][0];
            acc[3] += D_800F8402[i][0];
            acc[4] += D_800F83EF[i][0];
            acc[5] += D_800F842D[i * 0x68];
            acc[6] += D_800F83F4[i][0];
            acc[7] += D_800F83F5[i * 0x68];
            a += D_800F840C[i].a;
            b += D_800F8408[i].a;
            c += D_800F8410[i][0];
            d += D_800F840A[i][0];
            if (id != i) {
                func_800A7254(2, i, 0x13, one << i);
            }
            n++;
            *p |= one << i;
        }
    }
    for (i = 0; i < 8; i++) {
        t = acc[i] / n;
        acc[i] = t;
        t = t + t * D_800A0398[i] / 100;
        acc[i] = t;
        if (t >= 0x100) {
            acc[i] = 0xFF;
        }
    }
    if (lim1 < a) {
        a = lim1;
    }
    if (lim1 < c) {
        c = lim1;
    }
    if (lim2 < b) {
        b = lim2;
    }
    if (lim2 < d) {
        d = lim2;
    }
    D_800F83ED[id].a = acc[0];
    D_800F83EE[id].a = acc[1];
    D_800F8400[id][0] = acc[2];
    D_800F8402[id][0] = acc[3];
    D_800F83EF[id][0] = acc[4];
    D_800F842D[id * 0x68] = acc[5];
    D_800F83F4[id][0] = acc[6];
    D_800F83F5[id * 0x68] = acc[7];
    D_800F840C[id].a = a;
    D_800F8408[id].a = b;
    D_800F8410[id][0] = c;
    D_800F840A[id][0] = d;
    func_800A7254(2, id, 0x18, 1);
    D_800F5E65[id][0] = 0xFF;
}

void func_800AA1C8(void) {
    s32 i;

    i = M2C_FIELD(D_80063014, s32 *, 0);
    D_800F83E4[i][0] |= 0x10;
    D_800F83E0[i].a &= 0xFF7FF7BF;
    D_800F5BC8[i][0x19] |= 8;
    func_800A3E98(i, 0, -1, 0, 0);
    D_800F83AB = M2C_FIELD(D_80063014, s32 *, 0xC0);
    switch (M2C_FIELD(D_80063014, s32 *, 0xC0)) {
    case 0:
        func_800B1268(i, 0x14, 0x10);
        func_800B1268(i, 0x32, 0x20);
        D_800F8410[i][0] = (u32)(D_800F8410[i][0] * 13) / 10;
        break;
    case 1:
        func_800B1268(i, 0x32, 4);
        func_800B1268(i, -0x46, 8);
        func_800B1268(i, -0x14, 0x20);
        D_800F8410[i][0] = D_800F8410[i][0] * 2;
        break;
    case 2:
        func_800B1268(i, 0x32, 4);
        func_800B1268(i, 0x32, 0x10);
        break;
    case 3:
        func_800B1268(i, 0x64, 4);
        func_800B1268(i, 0x64, 8);
        break;
    }
    if ((u32)D_800F8410[i][0] > D_800F5E70[i][3]) {
        D_800F8410[i][0] = D_800F5E70[i][3];
    }
    D_800F840C[i].a = D_800F8410[i][0];
    func_800AE954(i);
    func_800A7254(2, i, 0x18, 1);
}

void func_800AA468(void) {
    u32 m;
    s32 a;
    m = M2C_FIELD(D_80063014, s32 *, 0xC8);
    if (func_800B10B4(M2C_FIELD(D_80063014, s32 *, 0)) != 0) {
        m |= 2;
    }
    a = func_80014A58(m & 0x0400029A);
    a += func_80014A58(m & 0x202000) * 2;
    M2C_FIELD(D_80063014, s32 *, 0x214) *= a + 1;
}

void func_800AA4FC(void) {
    s32 var_s0;

    var_s0 = 1;
    if (func_800B10B4(M2C_FIELD(D_80063014, s32 *, 0)) != 0) {
        var_s0 = 2;
    }
    if (M2C_FIELD(D_80063014, s32 *, 0xC8) & 0x200000) {
        var_s0 *= 4;
    }
    M2C_FIELD(D_80063014, s32 *, 0x214) = (s32) (M2C_FIELD(D_80063014, s32 *, 0x214) * var_s0);
}

void func_800AA574(void) {
    s32 i;
    s32 j;
    s32 total;
    s32 lim;
    s32 val;
    u32 v;
    u8 *p;
    u16 *e;
    u16 w;

    total = 0;
    i = 0;
    p = D_800F5E60[M2C_FIELD(D_80063014, s32 *, 0)].p;
    do {
        v = *(u32 *)(p + 0x40);
        if (v != 0xFFFFFFFF) {
            lim = v >> 8;
            val = 0;
            for (j = 0; j < 4; j++) { w = D_800730D0[v & 0xFF][j]; if (w != 0xFFFF) { val = w * 0x64; } }
            if (val < lim) {
                lim = val;
            }
            total += lim;
        }
        i++;
        p += 4;
    } while (i < 8);
    M2C_FIELD(D_80063014, s32 *, 0x48) = (total / 10000 * M2C_FIELD(D_80063014, s32 *, 0xC4)) / 16 + 1;
}

void func_800AA688(void) {
    s32 i;
    s32 n;

    n = 1;
    for (i = 0; i < 3; i++) {
        if (D_800F83E0[i].a & 1) {
            n++;
        }
    }
    M2C_FIELD(D_80063014, s32 *, 0x214) *= n;
}

s32 func_800AA6E8(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg0 < 4;
    if (arg1 < 4) {
        var_v0 += 1;
    }
    return var_v0 & 1;
}

u16 func_800AA700(s32 arg0) {
    s32 mask;

    mask = 0xF;
    if (arg0 < 4) {
        mask = 0x3F0;
    }
    return func_800B3030(D_80163758 & mask);
}

void func_800AA738(u32 arg0) {
    BEnt12 *e;
    s32 i;
    s32 c;
    s32 t;
    u16 v;

    e = func_800A2F4C();
    M2C_FIELD(D_80063014, s32 *, 0xB8) = func_80014A58(arg0);
    e->a = M2C_FIELD(D_80063014, s32 *, 0);
    e->b = M2C_FIELD(D_80063014, s32 *, 0x1C);
    t = M2C_FIELD(D_80063014, s32 *, 0x20);
    e->c = t;
    if (M2C_FIELD(D_80063014, s32 *, 0) >= 4 && (M2C_FIELD(D_80063014, s32 *, 0xC8) & 0x800) && (s8)t != 0x34) {
        if (M2C_FIELD(D_80063014, s32 *, 0x28) == 0x20 && M2C_FIELD(D_80063014, s32 *, 0x24) == 0xFF) {
            e->c = 0x14;
        } else if (M2C_FIELD(D_80063014, s32 *, 0x28) < 0x21) {
            e->c = 0x1D;
        }
    }
    if (M2C_FIELD(D_80063014, s32 *, 0) < 3 && (M2C_FIELD(D_80063014, s32 *, 0xB8) >= 2 || (M2C_FIELD(D_80063014, s32 *, 0x90) & 0x20000))) {
        c = (s8)e->c;
        for (i = 0; i < 0xE; i += 2) {
            if (c == D_800E7BBC[i]) {
                e->c = D_800E7BBC[i + 1];
                break;
            }
        }
    }
    e->pad[1] = M2C_FIELD(D_80063014, s32 *, 0x28);
    e->pad[0] = M2C_FIELD(D_80063014, s32 *, 0x24);
    if (M2C_FIELD(D_80063014, s32 *, 0xB8) >= 2) {
        v = M2C_FIELD(D_80063014, u16 *, 0x64);
    } else {
        v = M2C_FIELD(D_80063014, u16 *, 0x60);
    }
    e->e = v;
    e->d = M2C_FIELD(D_80063014, s32 *, 0x98);
    e->pad[2] = 0;
}

void func_800AA950(u8 *arg0) {
    s32 i;
    s32 j;
    s32 f;
    s32 t;
    u16 m;
    s32 mask;
    s32 c;

    t = (s8)arg0[0];
    for (j = 0; j < 3; j++) {
        m = D_8016376E[j];
        if ((m >> t) & 1) {
            break;
        }
    }
    if (t < 3 && M2C_FIELD(D_80063014, s32 *, 0x48) != 0 && t != M2C_FIELD(D_80063014, s32 *, 0) && M2C_FIELD(D_80063014, s32 *, 0xB8) == 1 && (f = M2C_FIELD(D_80063014, s32 *, 0x80) | M2C_FIELD(D_80063014, s32 *, 0x84) | M2C_FIELD(D_80063014, s32 *, 0x88), !(M2C_FIELD(D_80063014, s32 *, 0x6C) & 4)) && !(f & 0x800) && (M2C_FIELD(D_80063014, s32 *, 0x28) != 0x20 || M2C_FIELD(D_80063014, s32 *, 0x24) == 0xFF)) {
        mask = 0;
        for (i = 0; i < 3; i++) {
            if (!(D_800F5BE1[i].a & 8) && ((m >> i) & 1)) {
                c = D_8009D84D[i][0];
                if (c != 0 && M2C_FIELD(D_80063014, s32 *, 0) != i && t != i && !(D_800F83E0[i].a & 0x86805C45) && (func_80014BA8(0x64) & 0xFF) < c) {
                    mask |= 1 << i;
                }
            }
        }
        mask = func_80014A84(mask & D_800F83BC);
        if (mask != 0) {
            arg0[0] = func_80014A38(mask);
            arg0[1] = t;
            *((u8 *)D_800F83E0 + 0x17 + (s8)arg0[0] * 0x68) = D_800F83EC[t].a;
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800AABBC);

void func_800AB308(void) {
    s32 a;
    s32 b;
    s32 c;

    if (M2C_FIELD(D_80063014, s32 *, 0x230) & 0x40) {
        a = M2C_FIELD(D_80063014, s32 *, 0x23C);
        M2C_FIELD(D_80063014, s32 *, 0x23C) = M2C_FIELD(D_80063014, s32 *, 0x238);
        M2C_FIELD(D_80063014, s32 *, 0x238) = a;
        if (a & 1) {
            M2C_FIELD(D_80063014, s32 *, 0x238) = a & ~1;
            M2C_FIELD(D_80063014, s32 *, 0x230) = 1;
        }
        b = M2C_FIELD(D_80063014, s32 *, 0x23C);
        if (b & 1) {
            M2C_FIELD(D_80063014, s32 *, 0x23C) = b & ~1;
            M2C_FIELD(D_80063014, s32 *, 0x230) = 0x80;
        }
    }
    if (M2C_FIELD(D_80063014, s32 *, 0x230) & 1) {
        c = M2C_FIELD(D_80063014, s32 *, 0xA4);
        if (c < 5) {
            if (c >= 3 && (func_80014BA8(0x20) & 0xFF) >= M2C_FIELD(D_80063014, s32 *, 0x48)) {
                M2C_FIELD(D_80063014, s32 *, 0x230) = (M2C_FIELD(D_80063014, s32 *, 0x230) & ~1) | 0x20;
            }
        }
    }
    if (M2C_FIELD(D_80063014, s32 *, 0x48) == 0) {
        if (M2C_FIELD(D_80063014, s32 *, 0x230) & 4) {
            M2C_FIELD(D_80063014, s32 *, 0x260) = M2C_FIELD(D_80063014, s32 *, 0x260) * 2;
        }
        if (M2C_FIELD(D_80063014, s32 *, 0x230) & 0x10) {
            M2C_FIELD(D_80063014, s32 *, 0x260) = M2C_FIELD(D_80063014, s32 *, 0x260) >> 1;
        }
    }
}

void func_800AB480(void) {
    u8 *p;
    s32 f1;
    s32 f;
    s32 v;
    s32 i;

    f1 = M2C_FIELD(D_80063014, s32 *, 0x230);
    if (f1 & 0x40) {
        M2C_FIELD(D_80063014, s32 *, 0x220) ^= 1;
    } else {
        if (f1 & 4) {
            M2C_FIELD(D_80063014, s32 *, 0x214) *= 2;
        }
        if (M2C_FIELD(D_80063014, s32 *, 0x230) & 0x10) {
            M2C_FIELD(D_80063014, s32 *, 0x214) = (M2C_FIELD(D_80063014, s32 *, 0x214) + 1) >> 1;
        }
    }
    p = (u8 *)D_80063014;
    f = *(s32 *)(p + 0x230);
    if (f & 1) {
        if (*(s32 *)(p + 0x228) & 1) {
            v = *(s32 *)(p + 0x218) | 3;
            goto store;
        }
        *(s32 *)(p + 0x250) = -2;
        *(s32 *)(p + 0x238) |= 1;
        *(s32 *)(p + 0x23C) &= ~1;
        *(s32 *)(p + 0x218) &= ~2;
        *(s32 *)(p + 0x220) &= ~1;
        return;
    }
    if (f & 0x80) {
        i = *(s32 *)(p + 0x208);
        D_800F840C[i].a = D_800F8410[i][0];
        i = *(s32 *)(p + 0x208);
        D_800F8408[i].a = D_800F840A[i][0];
        *(s32 *)(p + 0x220) = 1;
        *(s32 *)(p + 0x250) = -3;
        *(s32 *)(p + 0x218) &= ~2;
        *(s32 *)(p + 0x238) &= ~1;
        return;
    }
    if (f & 0x20) {
        if (*(s32 *)(p + 0x244) != 0 || (*(s32 *)(p + 0x44) & 8)) {
            v = *(s32 *)(p + 0x218) | 1;
store:
            *(s32 *)(p + 0x218) = v;
        }
        func_800ACA24();
    }
}

void func_800AB674(void) {
    s32 i;
    s32 o;
    s32 m;

    if (!(M2C_FIELD(D_80063014, s32 *, 0x90) & 0x10) && (M2C_FIELD(D_80063014, s32 *, 0) < 3) && ((M2C_FIELD(D_80063014, s32 *, 0x44) & 0x1C00) || (M2C_FIELD(D_80063014, s32 *, 0x28) == 5))) {
        m = M2C_FIELD(D_80063014, s32 *, 0x18);
        for (i = 4; i < 10; i++) {
            o = i * 0x68;
            if (D_800F842E[o] >= 0x10U) {
                m &= ~(1 << i);
            }
        }
        if (m != M2C_FIELD(D_80063014, s32 *, 0x18)) {
            if (D_8009D86F[M2C_FIELD(D_80063014, s32 *, 0) * 0x440] & 4) {
                M2C_FIELD(D_80063014, s32 *, 0x90) = (s32) (M2C_FIELD(D_80063014, s32 *, 0x90) | 0x20000);
                return;
            }
            M2C_FIELD(D_80063014, s32 *, 0x18) = m;
            if (m == 0) {
                M2C_FIELD(D_80063014, s32 *, 0xDC) = 0x77;
            }
        }
    }
}

void func_800AB788(void) {
    u16 sp10;
    s32 temp_a0;
    s32 temp_v1;
    void *temp_t0;

    temp_a0 = 1 << (M2C_SFIELD(D_80063014, s32 *, 0x2C) - 0x48);
    if (!(D_8016376A & 0x40)) {
        temp_t0 = M2C_SFIELD(D_80063014, void **, 0x204);
        temp_v1 = M2C_SFIELD(temp_t0, s32 *, 0x24);
        if (!(temp_v1 & temp_a0)) {
            M2C_SFIELD(temp_t0, s32 *, 0x24) = (s32) (temp_v1 | temp_a0);
            sp10 = (u16) M2C_SFIELD(D_80063014, s32 *, 0x2C);
            func_800B0FFC(M2C_SFIELD(D_80063014, s32 *, 0x208), 0x73, 1, &sp10);
            func_800A7254(2, M2C_SFIELD(D_80063014, s32 *, 0x208), 0x12, (s32) sp10);
            M2C_SFIELD(D_80063014, s32 *, 0x224) = 0xA;
        }
    }
}

void func_800AB830(s32 arg0, s32 arg1) {
    s32 flags;
    s32 v;
    BtlE12b *q;

    flags = 1;
    if (arg1 != 0) {
        v = D_800F5BE8[arg0][0];
        D_800F5BE8[arg0][0] = 0;
    } else {
        v = D_800F5BE4[arg0][0];
        D_800F5BE4[arg0][0] = 0;
    }
    M2C_FIELD(D_80063014, s32 *, 0x208) = arg0;
    if (arg1 != 0) {
        M2C_FIELD(D_80063014, s32 *, 0x220) = 4;
    } else {
        M2C_FIELD(D_80063014, s32 *, 0x220) = 0;
    }
    if (v < 0) {
        v = -v;
        M2C_FIELD(D_80063014, s32 *, 0x220) |= 1;
    }
    if (func_800ACE14(arg0) != 0) {
        v = 0;
    }
    M2C_FIELD(D_80063014, s32 *, 0x214) = v;
    func_800AD0FC();
    if (D_800F83E0[arg0].a & 1) {
        flags |= 4;
        M2C_FIELD(D_80063014, s32 *, 0x7C) |= 1 << arg0;
    }
    q = (BtlE12b *)func_800A2FD0();
    q->a = arg0;
    q->b = arg0;
    q->c = 0x2E;
    q->d = flags;
    q->e = D_800F83E0[arg0].a;
    func_800ABA68(q, (s16)M2C_FIELD(D_80063014, s32 *, 0x214), (u16)M2C_FIELD(D_80063014, s32 *, 0x220), -1, -1);
}

void func_800AB9C4(s32 arg0, s32 arg1) {
    BEnt12 *p;

    if (!(D_800F83E0[arg0].a & 1)) {
        p = func_800A2F4C();
        p->b = 1;
        p->c = 0x2E;
        p->a = arg0;
        p->pad[1] = 0;
        p->pad[0] = 0;
        p->e = -1;
        p->d = 0;
        p->pad[2] = 0;
        func_800AB830(arg0, arg1);
        func_800A317C();
    }
}

void func_800ABA68(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 n;
    E0E *p;
    u16 e;

    e = *(u16 *)&arg4;
    n = *(s8 *)arg0;
    p = ((E0E *(*)(void *))func_800A311C)(arg0);
    p->pad[0] = arg1;
    p->pad[1] = arg2;
    p->pad2[0] = arg3;
    p->pad2[1] = e;
    p->d = D_800F840C[n].a;
    p->e = D_800F8408[n].a;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800ABB0C);

void func_800AC6B4(s32 arg0) {
    if (arg0 != 0) {
        if (M2C_FIELD(D_80063014, s32 *, 0x208) >= 4) {
            M2C_FIELD(D_80063014, s32 *, 0x224) = 0x39;
        }
    } else if (M2C_FIELD(D_80063014, s32 *, 0x228) & 0x400) {
        M2C_FIELD(D_80063014, s32 *, 0x224) = 0x30;
    } else if (M2C_FIELD(D_80063014, s32 *, 0x228) & 0x800) {
        M2C_FIELD(D_80063014, s32 *, 0x224) = 5;
    } else {
        M2C_FIELD(D_80063014, s32 *, 0x224) = ((s32 (*)(void))func_800A2D0C)();
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800AC73C);

void func_800ACA24(void) {
    M2C_FIELD(D_80063014, s32 *, 0x238) = 0;
    M2C_FIELD(D_80063014, s32 *, 0x23C) = 0;
    M2C_FIELD(D_80063014, s32 *, 0x240) = 0;
    M2C_FIELD(D_80063014, s32 *, 0x244) = 0;
    M2C_FIELD(D_80063014, s32 *, 0x230) = 0;
    M2C_FIELD(D_80063014, s32 *, 0x214) = 0;
}

void func_800ACA4C(s32 arg0) {
    u16 buf[2];
    s32 v;
    s32 s0;
    u8 c;

    s0 = 3;
    switch (M2C_FIELD(D_80063014, s32 *, 0x28)) {
    case 2:
        s0 = 0x38;
        break;
    case 3:
        s0 = 0x36;
        break;
    case 13:
        s0 = 0x37;
        break;
    case 20:
        s0 = 0x35;
        break;
    }
    v = M2C_FIELD(D_80063014, s32 *, 0);
    if (v < 3) {
        func_800A2CC4(s0);
        if (arg0 != -1) {
            func_800B1060(arg0);
            func_800A2CC4(0x3B);
        }
        if (s0 == 3) {
            func_800A2CC4(4);
        }
    } else if (arg0 != -1) {
        buf[0] = v;
        buf[1] = 0xFFFF;
        c = D_800F5BC7[M2C_FIELD(D_80063014, s32 *, 0)].a;
        if (c != 0xFF) {
            buf[1] = c;
        }
        func_800B0FFC(M2C_FIELD(D_80063014, s32 *, 0), arg0, 1, buf);
    }
}

s32 func_800ACB98(void) {
    s32 ret;
    s32 f;
    s32 a0;
    s32 id;
    s32 cost;
    s32 v;
    u16 cur;

    ret = 0;
    if (!(D_800F83E4[M2C_FIELD(D_80063014, s32 *, 0)][0] & 0x400) && M2C_FIELD(D_80063014, s32 *, 0x20) != 0x34) {
        f = 0;
        if (M2C_FIELD(D_80063014, s32 *, 0xC8) & 0x80) {
            switch (M2C_FIELD(D_80063014, s32 *, 0x28)) {
            case 32:
                if (M2C_FIELD(D_80063014, s32 *, 0x38) != 0) {
                case 2:
                case 3:
                case 13:
                case 21:
                case 22:
                    f = 1;
                }
                break;
            }
        }
        if (M2C_FIELD(D_80063014, s32 *, 0xC8) & 0x800) {
            switch (M2C_FIELD(D_80063014, s32 *, 0x28)) {
            case 1:
            case 4:
                break;
            case 2:
            case 21:
                if (M2C_FIELD(D_80063014, s32 *, 0x2C) != 0xA) {
                    f = 1;
                }
                break;
            case 32:
                if (M2C_FIELD(D_80063014, s32 *, 0x38) != 0) {
                default:
                case 3:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                    f = 1;
                }
                break;
            }
        }
        a0 = -1;
        if (f == 0) {
            id = M2C_FIELD(D_80063014, s32 *, 0);
            cur = D_800F8408[id].a;
            cost = M2C_FIELD(D_80063014, s32 *, 0x38);
            if (cur >= cost) {
                D_800F8408[id].a = cur - cost;
                goto done;
            }
            v = 0x5C;
            if (id < 3) {
                v = 0x5B;
            }
            a0 = v;
        }
        func_800ACA4C(a0);
        ret = 1;
    }
done:
    M2C_FIELD(D_80063014, s32 *, 0x38) = 0;
    return ret;
}

s32 func_800ACD88(s32 arg0) {
    s32 var_v1;
    u32 t;
    var_v1 = 0;
    if (M2C_FIELD(D_80063014, s32 *, 0x6C) & 4) {
        t = D_800F83E4[arg0][0] & 0x200;
        var_v1 = t != 0;
    } else if (D_800F83E4[arg0][0] & 0x100) {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_800ACE14(s32 arg0) {
    s32 r;

    r = 0;
    if (func_800ACD88(arg0) || (D_800F83E0[arg0].a & 0x01004000)) {
        r = 1;
    }
    return r;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800ACE88);

void func_800AD088(void *arg0) {
    s8 temp_v1;

    if ((M2C_FIELD(D_80063014, s32 *, 0x80) | M2C_FIELD(D_80063014, s32 *, 0x84) | M2C_FIELD(D_80063014, s32 *, 0x88)) & ~M2C_FIELD(D_80063014, s32 *, 0x22C)) {
        temp_v1 = M2C_FIELD(arg0, s8 *, 3);
        if (temp_v1 == -1) {
            func_800ABA68(arg0, -1, 0, -1, (s32) temp_v1);
        }
    }
}

void func_800AD0FC(void) {
    T68 *e;
    s32 f;
    s32 b;
    u32 amt;
    u32 old;
    u32 nv;
    s32 idx;
    u8 *t;
    u8 *t2;
    u32 lo;
    u32 hi;
    s32 flg;
    s32 m;
    s32 w;

    e = &D_800F83E0[M2C_FIELD(D_80063014, s32 *, 0x208)];
    f = M2C_FIELD(D_80063014, s32 *, 0x220);
    amt = M2C_FIELD(D_80063014, u32 *, 0x214);
    b = f & 1;
    if (amt != 0) {
        if (f & 4) {
            M2C_FIELD(e, u16 *, 0x28) = func_80014B08(M2C_FIELD(e, u16 *, 0x28), amt, M2C_FIELD(e, u16 *, 0x2A), b);
            return;
        }
        do {
            old = M2C_FIELD(e, u32 *, 0x2C);
            nv = func_80014B08(old, amt, M2C_FIELD(e, u32 *, 0x30), b);
        } while (0);
        M2C_FIELD(e, u32 *, 0x2C) = nv;
        if (nv == 0 && old != 0) {
            e->a |= 1;
            if (M2C_FIELD(D_80063014, s32 *, 0x90) & 0x2000) {
                func_800A2DB0();
            }
        }
        idx = M2C_FIELD(D_80063014, s32 *, 0x208);
        if (idx < 3 && M2C_FIELD(D_80063014, s32 *, 0) >= 4 && b == 0 && (t = M2C_FIELD(D_80063014, u8 **, 0x204), t[5] < 4) && !(D_800F5BE1[idx].a & 8)) {
            w = M2C_FIELD(t, u16 *, 8);
            m = 0x100;
            if (M2C_FIELD(t, s32 *, 0x1C) == 0) {
                func_800155A4(0x22);
                return;
            }
            flg = M2C_FIELD(D_80063014, s32 *, 0x228);
            lo = (u32)M2C_FIELD(D_80063014, u32 *, 0x214) * 300 / M2C_FIELD(e, u32 *, 0x30);
            if (flg & 0x20) {
                m = 0x200;
            } else if (flg & 0x10) {
                m = 0x80;
            }
            hi = lo * m;
            t2 = M2C_FIELD(D_80063014, u8 **, 0x204);
            w += hi / M2C_FIELD(t2, u32 *, 0x1C);
            if (w >= 0x100) {
                w = 0xFF;
            }
            M2C_FIELD(t2, s16 *, 8) = w;
        }
    }
}

void func_800AD324(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 t;
    s32 v;

    t = M2C_FIELD(D_80063014, s32 *, 0x220) & 1;
    if (arg3 & 1) {
        if (arg1 == M2C_FIELD(D_80063014, s32 *, 0x208)) {
            v = M2C_FIELD(D_80063014, s32 *, 0x25C);
            if (v < arg2) {
                arg2 = v;
            }
        }
        if (t != 0) {
            arg2 = -arg2;
        }
        D_800F5BE8[arg0][0] -= arg2;
    }
    if (arg3 & 2) {
        if (arg1 == M2C_FIELD(D_80063014, s32 *, 0x208)) {
            v = M2C_FIELD(D_80063014, s32 *, 0x258);
            if (v < arg2) {
                arg2 = v;
            }
        }
        if (t != 0) {
            arg2 = -arg2;
        }
        D_800F5BE4[arg0][0] -= arg2;
    }
}

void func_800AD420(void) {
    s32 v;
    s32 m;

    v = 2;
    if (M2C_FIELD(D_80063014, s32 *, 0x220) & 4) {
        v = 1;
    }
    m = 0;
    if (!(M2C_FIELD(D_80063014, s32 *, 0x6C) & 0x20)) {
        m = 3;
    }
    func_800AD324(M2C_FIELD(D_80063014, s32 *, 0xF4), M2C_FIELD(D_80063014, s32 *, 0x208),
                  M2C_FIELD(D_80063014, s32 *, 0x214), v | m);
}

void func_800AD480(void) {
    s32 n;
    u32 i;
    u32 start;

    n = 0;
    for (i = 0, start = 0; i < 30; i++) {
        if (n < 16) {
            if (i == start) {
                D_800F495C[n] = i;
                n++;
            }
            if (D_800E7BCC[i] == 8) {
                start = i + 1;
            }
        }
    }
}

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text1c", D_800A04B0);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text1c", D_800A04BC);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text1c", D_800A04D0);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text1c", D_800A04E0);

void func_800AD4EC(void) {
    void (*fn)(void);
    u32 idx;
    s32 op;

    idx = D_800F495C[M2C_FIELD(D_80063014, s32 *, 0xA0)];
    op = D_800E7BCC[idx++];
    fn = D_800E7BFC[M2C_FIELD(D_80063014, s32 *, 0xA4)];
    while (op != 8) {
        D_800A04E0[op]();
        op = D_800E7BCC[idx++];
    }
    if (M2C_FIELD(D_80063014, s32 *, 0x48) != 0 && fn != 0) {
        func_800A8E84(0);
        fn();
        func_800A8E84(1);
    }
}

void func_800AD5E8(void) {
    s32 v;
    s32 f;
    u8 c;

    v = M2C_FIELD(D_80063014, s32 *, 0x40);
    M2C_FIELD(D_80063014, s32 *, 0xA0) = (v & 0xF0) >> 4;
    M2C_FIELD(D_80063014, s32 *, 0xA4) = v & 0xF;
    f = D_800E7BEC[M2C_FIELD(D_80063014, s32 *, 0xA0)];
    if (f & 1) {
        M2C_FIELD(D_80063014, s32 *, 0x6C) &= ~4;
    }
    if (f & 2) {
        M2C_FIELD(D_80063014, s32 *, 0xA4) |= 0x10;
    }
    if (f & 4) {
        c = D_800A04B0[M2C_FIELD(D_80063014, s32 *, 0xA4)];
        M2C_FIELD(D_80063014, s32 *, 0xA4) = 1;
        M2C_FIELD(D_80063014, s32 *, 0xBC) = c;
    }
    if (M2C_FIELD(D_80063014, s32 *, 0x6C) & 4) {
        M2C_FIELD(D_80063014, s32 *, 0x4C) = func_800B1218(M2C_FIELD(D_80063014, s32 *, 0), D_800F83EE[M2C_FIELD(D_80063014, s32 *, 0)].a, 1);
    } else {
        M2C_FIELD(D_80063014, s32 *, 0x4C) = func_800B1218(M2C_FIELD(D_80063014, s32 *, 0), D_800F83ED[M2C_FIELD(D_80063014, s32 *, 0)].a, 0);
    }
}

s32 func_800AD73C(s32 arg0) {
    s32 m;

    if (M2C_FIELD(D_80063014, s32 *, 0x6C) & 4) {
        if (M2C_FIELD(D_80063014, s32 *, 0x228) & 0x20000) {
            M2C_FIELD(D_80063014, s32 *, 0x218) |= 0x8000;
        }
    } else if (M2C_FIELD(D_80063014, s32 *, 0x228) & 0x10000) {
        M2C_FIELD(D_80063014, s32 *, 0x218) |= 0x4000;
    }
    if (M2C_FIELD(D_80063014, s32 *, 0x218) & 0xC000) {
        arg0 /= 2;
    }
    m = M2C_FIELD(D_80063014, s32 *, 0xE8);
    if (m != 0) {
        arg0 += arg0 * m / 100;
    }
    return arg0;
}

s32 func_800AD804(s32 arg0, s32 arg1) {
    s32 var_a0;
    s32 var_a1;

    var_a0 = arg0;
    var_a1 = arg1;
    if ((var_a1 == 0) && ((M2C_FIELD(D_80063014, s32 *, 0xB8) < 2) || (M2C_FIELD(D_80063014, s32 *, 0x50) & 0x80))) {
        var_a1 = 1;
    }
    if (M2C_FIELD(D_80063014, s32 *, 0xAC) != 0) {
        var_a0 = var_a0 >> 1;
    } else if (var_a1 == 0) {
        var_a0 = (var_a0 * 2) / 3;
    }
    return var_a0;
}

s32 func_800AD890(s32 arg0) {
    if (M2C_FIELD(D_80063014, s32 *, 0x228) & 0x10) {
        arg0 -= arg0 * 3 / 10;
    }
    return arg0;
}

s32 func_800AD8DC(s32 arg0) {
    arg0 = (arg0 * (func_80014B70() + 0xF01)) >> 12;
    if (arg0 == 0) {
        arg0 = 1;
    }
    return arg0;
}

void func_800AD924(void) {
    M2C_FIELD(D_80063014, s32 *, 0x218) = (s32) (M2C_FIELD(D_80063014, s32 *, 0x218) | 2);
}

s32 func_800AD944(void) {
    s32 v;
    s32 a;
    s32 b;
    s32 flag;
    s32 i;
    s32 r;
    s32 t;

    if (!(M2C_FIELD(D_80063014, s32 *, 0x6C) & 0x2000)) {
        M2C_FIELD(D_80063014, s32 *, 0x220) |= 2;
    }
    a = M2C_FIELD(D_80063014, s32 *, 0x4C);
    b = M2C_FIELD(D_80063014, s32 *, 4);
    v = (b * a / 32 * ((b + a) / 32) + a) * (0x200 - M2C_FIELD(D_80063014, s32 *, 0x210)) * M2C_FIELD(D_80063014, s32 *, 0x48) / 8192;
    if (M2C_FIELD(D_80063014, s32 *, 0x220) & 2) {
        v *= 2;
    }
    if (M2C_FIELD(D_80063014, s32 *, 0xC8) & 0x800000) {
        v *= 3;
        v >>= 1;
    }
    t = D_800F83E4[M2C_FIELD(D_80063014, s32 *, 0x208)][0] & 0x40;
    flag = t != 0;
    if ((M2C_FIELD(D_80063014, s32 *, 0x50) & 0x20) || M2C_FIELD(D_80063014, s32 *, 0x28) == 0x20) {
        if (D_800F83E4[M2C_FIELD(D_80063014, s32 *, 0)][0] & 0x40) {
            flag = 1;
        }
    } else {
        flag = 0;
    }
    if (flag != 0) {
        v /= 2;
    }
    i = M2C_FIELD(D_80063014, s32 *, 0x208);
    if (D_800F83E4[i][0] & 0x20) {
        v /= 2;
    }
    if (M2C_FIELD(D_80063014, s32 *, 0x234) & 1) {
        v = v * D_800F83F2[i * 0x68] >> 3;
    }
    if (M2C_FIELD(D_80063014, s32 *, 0xC8) & 0x800) {
        v >>= 2;
    }
    v = func_800AD73C(func_800AD804(func_800AD890(v), 0));
    if (M2C_FIELD(D_80063014, s32 *, 0xC8) & 0x1000) {
        v = 0;
    }
    r = func_800AD8DC(v);
    M2C_FIELD(D_80063014, s32 *, 0x214) = r;
    return r;
}

void func_800ADBBC(void) {
    s32 v;
    s32 flag;

    v = (M2C_FIELD(D_80063014, s32 *, 0x4C) + M2C_FIELD(D_80063014, s32 *, 4)) * 6;
    v = v * (0x200 - M2C_FIELD(D_80063014, s32 *, 0x210)) * M2C_FIELD(D_80063014, s32 *, 0x48);
    flag = (M2C_FIELD(D_80063014, s32 *, 0x50) & 0xC) == 4;
    M2C_FIELD(D_80063014, s32 *, 0x214) = func_800AD8DC(func_800AD73C(func_800AD804(func_800AD890(v / 8192), flag)));
}

void func_800ADC70(void) {
    s32 v;

    if (M2C_FIELD(D_80063014, s32 *, 0x6C) & 1) {
        v = D_800F840C[M2C_FIELD(D_80063014, s32 *, 0x208)].a;
    } else {
        v = D_800F8408[M2C_FIELD(D_80063014, s32 *, 0x208)].a;
    }
    v = v * M2C_FIELD(D_80063014, s32 *, 0x48) / 32;
    if (M2C_FIELD(D_80063014, s32 *, 0xAC) != 0) {
        v >>= 1;
    }
    M2C_FIELD(D_80063014, s32 *, 0x214) = v;
}

void func_800ADD2C(void) {
    s32 v;

    if (M2C_FIELD(D_80063014, s32 *, 0x6C) & 1) {
        v = D_800F8410[M2C_FIELD(D_80063014, s32 *, 0x208)][0];
    } else {
        v = D_800F840A[M2C_FIELD(D_80063014, s32 *, 0x208)][0];
    }
    v = v * M2C_FIELD(D_80063014, s32 *, 0x48) / 32;
    if (M2C_FIELD(D_80063014, s32 *, 0xAC) != 0) {
        v >>= 1;
    }
    M2C_FIELD(D_80063014, s32 *, 0x214) = v;
}

void func_800ADDE8(void) {
    M2C_FIELD(D_80063014, s32 *, 0x214) = func_800AD8DC(func_800AD73C(func_800AD804((M2C_FIELD(D_80063014, s32 *, 0x4C) + M2C_FIELD(D_80063014, s32 *, 4)) * 6 + M2C_FIELD(D_80063014, s32 *, 0x48) * 22, 0)));
}

void func_800ADE5C(void) {
    M2C_FIELD(D_80063014, s32 *, 0x214) = (s32) (M2C_FIELD(D_80063014, s32 *, 0x48) * 0x14);
}

void func_800ADE84(void) {
    M2C_FIELD(D_80063014, s32 *, 0x214) = func_800AD8DC(M2C_FIELD(D_80063014, s32 *, 0x48) * (0x200 - M2C_FIELD(D_80063014, s32 *, 0x210)) / 32);
}

void func_800ADED8(void) {
    s8 *p = (s8 *)D_80063014;
    s32 x = M2C_FIELD(p, s32 *, 0x230) & 0x40;

    if (!x) {
        x = 0x80;
    } else {
        x = 1;
    }
    M2C_FIELD(p, s32 *, 0x230) = x;
}

void func_800ADF04(void) {
    M2C_FIELD(D_80063014, s32 *, 0x4C) = (s32) (M2C_FIELD(D_80063014, s32 *, 0xD8) * 2);
    func_800AD944();
}

void func_800ADF38(void) {
    s32 d;
    s32 r;

    d = func_80014A58(M2C_FIELD(D_80063014, u32 *, 0x18));
    r = 0;
    if (d != 0) {
        r = (M2C_FIELD(D_80063014, s32 *, 0x48) + (d - 1)) / d;
    }
    M2C_FIELD(D_80063014, s32 *, 0x214) = r;
}

void func_800ADFC0(void) {
    s32 p = D_80063014;

    M2C_FIELD(p, s32 *, 0x214) = D_800F5BF4[M2C_FIELD(p, s32 *, 0)].a;
}

void func_800ADFF4(void) {
    s32 i;

    i = M2C_FIELD(D_80063014, s32 *, 0);
    M2C_FIELD(D_80063014, s32 *, 0x214) = D_800F840C[i].b - D_800F5BF4[i].a;
}

void func_800AE050(void) {
}

void func_800AE058(void) {
}

void func_800AE060(void) {
}

void func_800AE068(void) {
}

void func_800AE070(void) {
}

void func_800AE078(void) {
}

void func_800AE080(void) {
    s32 d[6];
    u8 pad[8];
    s32 n;
    s32 i;
    s32 j;
    s32 r;
    s32 t;
    s32 sum;
    s32 cnt;
    s32 max;

    n = M2C_FIELD(D_80063014, s32 *, 4) / 10;
    if (n < 2) {
        n = 2;
    }
    if (n >= 7) {
        n = 6;
    }
    for (i = 0; i < 4; i++) {
        D_80163774[i] = 0xFF;
    }
    sum = 0;
    for (i = 0; i < n; i++) {
        r = func_80014BA8(6);
        d[i] = r;
        t = sum + 1;
        sum = t + r;
        if (i & 1) {
            D_80163774[i / 2] = (r << 4) | (D_80163774[i / 2] & 0xF);
        } else {
            D_80163774[i / 2] = r | 0xF0;
        }
        func_80014B54();
    }
    max = 0;
    for (i = 0; i < 6; i++) {
        cnt = 0;
        for (j = 0; j < n; j++) {
            if (d[j] == i) {
                cnt++;
            }
        }
        if (max < cnt) {
            max = cnt;
        }
    }
    t = sum * 100;
    sum = t * max;
    M2C_FIELD(D_80063014, s32 *, 0x214) = sum;
}

void func_800AE234(void) {
    M2C_FIELD(D_80063014, s32 *, 0x214) = (s32) (D_8009D2A2 + (D_8009D2A3 << 8));
}

void func_800AE25C(void) {
    s32 p = D_80063014;

    M2C_FIELD(p, s32 *, 0x214) = D_800F840C[M2C_FIELD(p, s32 *, 0x208)].a - 1;
}

void func_800AE2A0(void) {
    s32 t;

    t = *(volatile u32 *)&D_8009D264 / 60;
    M2C_FIELD(D_80063014, s32 *, 0x214) = (t / 60) * 100 + t % 60;
}

void func_800AE318(void) {
    s32 v;

    v = 0;
    if (M2C_FIELD(D_80063014, s32 *, 0x208) < 3) {
        v = M2C_FIELD(D_800F5E60[M2C_FIELD(D_80063014, s32 *, 0x208)].p, u16 *, 0x24);
    }
    M2C_FIELD(D_80063014, s32 *, 0x214) = v * 10;
}

void func_800AE378(void) {
    s32 idx;
    s32 n;
    s32 i;
    s32 *p;

    idx = M2C_FIELD(D_80063014, s32 *, 0x208);
    n = 0;
    if (idx < 3) {
        p = (s32 *) D_800F5E60[idx].p;
        for (i = 0; i < 8; i++) {
            if (p[0x10 + i] != -1) {
                n++;
            }
            if (p[0x18 + i] != -1) {
                n++;
            }
        }
    }
    M2C_FIELD(D_80063014, s32 *, 0x214) = n * 0x457;
}

void func_800AE42C(s32 arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4, s32 arg5) {
    s32 i;
    s32 c;
    s32 n;
    s32 k;
    s32 id;
    u8 *p;
    u8 *e;
    u8 *q;

    for (i = 0; i < 8; i++) {
        arg3[i] = 0;
        arg3[i + 8] = 0;
    }
    if (arg2 < 3) {
        e = D_8009D84C[arg2];
        arg3[4] = *(u16 *)(e + 0x3E);
        arg3[5] = *(u16 *)(e + 0x40);
        arg3[6] = *(u16 *)(e + 0x42);
    } else if (arg2 >= 4) {
        id = D_80163658[arg2 - 4].a;
        p = (u8 *)&D_800F5F44[id];
        for (i = 0; i < 8U; i++) {
            q = p + i;
            c = q[0x28];
            n = q[0x30];
            if (c != 0xFF) {
                k = c / 32;
                arg3[k * 8 + n] |= 1 << (c - k * 32);
            }
        }
    }
    arg3[13] |= func_800AF874(arg2, arg4, arg5);
    if (arg4 != 0) {
        if (D_800F83E0[arg2].a & 0x100000) {
            arg3[6] |= 0x1FF;
            arg3[5] |= 0x7E00;
        }
    }
    arg3[6] |= D_800F8406[arg2].a;
    arg3[5] |= D_800F8434[arg2].a;
    if ((arg3[5] & 0x10) || (arg3[13] & 8)) {
        arg3[5] |= 0x10;
        arg3[13] |= 8;
    }
    for (i = 0; i < 8; i++) {
        arg3[i] &= arg0;
        arg3[i + 8] &= arg1;
        if (i == 5) {
            if (arg3[13] != arg1) {
                arg3[13] = 0;
            }
        }
    }
}

s32 func_800AE6C0(s32 arg0, s32 arg1, s32 arg2) {
    s32 buf[16];
    s32 i;

    func_800AE42C(arg1, arg2, arg0, buf, 0, 0);
    for (i = 0; i < 8; i++) {
        if ((buf[i] & arg1) || (buf[i + 8] & arg2)) {
            break;
        }
    }
    if (i == 8) {
        i = 3;
    }
    return i;
}

void func_800AE764(s32 arg0, s32 arg1, s32 arg2) {
    s32 pad[16];
    s32 i;
    s32 r;
    s16 mask;

    mask = 0;
    for (i = 0; i < 10; i++) {
        D_800F83EB[i][0] = 3;
        if ((arg0 >> i) & 1) {
            r = func_800AE6C0(i, arg1, arg2);
            if (r != 3) {
                D_800F83EB[i][0] = r;
                mask |= 1 << i;
            }
        }
    }
    D_800F83B2 = mask;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800AE82C);

void func_800AE954(arg0) {
    s32 a;
    s32 b;
    u32 f;
    s32 t;
    s32 v;

    f = D_800F83E0[arg0].a;
    a = 0;
    b = 0;
    if ((s32)f < 0) {
        switch (D_800F7DC6) {
        case 0:
        case 3:
            f |= 0x400;
            break;
        case 1:
            f |= 0x02000000;
            break;
        }
    }
    if ((f & 0x401) == 0) {
        a = D_800F7DA6;
        b = 0x22;
        if (!(f & 0x200)) {
            a *= 2;
            b = 0x44;
            if (f & 0x100) {
                a *= 2;
                b = 0x88;
            }
        }
    }
    if (arg0 < 3) {
        t = func_800B1218(arg0, D_800F83F4[arg0][0], 5) + 0x32;
    } else {
        t = D_800F83F4[arg0][0];
    }
    v = a * t / D_800F7DA8;
    do {
        if (f & 0x02004004) {
            v = 0;
        }
    } while (0);
    D_800F5BB8[arg0].a = a;
    D_800F5BBA[arg0].a = v;
    D_800F5BC2[arg0].a = b;
}

void func_800AEB20(s32 arg0, s32 arg1) {
    s32 i;
    u8 *p;

    i = func_800AF834(arg1);
    if (i >= 0) {
        p = D_800F5BC8[arg0];
        p[i] = D_800A04BC[i];
    }
}

void func_800AEB80(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    u8 *p;

    i = func_800AF834(arg1);
    if (i >= 0) {
        p = D_800F5BC8[arg0];
        p[i] = 0;
        if ((0xD8B >> i) & 1) {
            func_800B108C(arg0);
        }
    }
}

void func_800AEBF0(void) {
    func_800AE954();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800AEC10);

void func_800AEF68(s32 arg0) {
    u16 *p;
    s32 o;

    if (D_800F840C[arg0].a == 0) {
        D_800F840C[arg0].a = D_800F8410[arg0][0];
    }
    if (arg0 >= 3) {
        D_800F83E4[arg0][0] |= 0x18;
    }
    o = arg0 * 0x10;
    D_800F83E4[arg0][0] &= ~0x2000;
    do {} while (0);
    *((u8 *)D_801636BC + o) = D_800F5BE3[arg0].a;
    ((void (*)(s32))func_800AEBF0)(arg0);
    if (D_800F83E0[arg0].a & 0x200000) {
        ((void (*)(s32, s32, s32))func_800AEB20)(arg0, 0x15, 1);
    }
    if (D_800F83E0[arg0].a & 0x800000) {
        func_800A7254(0, arg0, 8, 0);
    }
    p = &D_800F7DE0;
    *p &= ~(1 << arg0);
}

void func_800AF0C4(s32 arg0, s32 arg1, s32 arg2) {
    if (!(D_800F83E0[arg0].a & 0x02804444)) {
        func_800A7254(0, arg0, 6, 0);
    }
    if (!(D_800F83E0[arg0].a & 0x02004404)) {
        if ((D_800F6B34.mask >> arg0) & 1) {
            if (D_800F6B34.e[arg0].a != 0xFF) {
                func_800A3D4C(&D_800F6B34.e[arg0]);
                D_800F6B34.e[arg0].a = 0xFF;
            }
        }
    }
}

void func_800AF1A8(s32 arg0) {
    func_800A7254(0, arg0, 8, 0);
}

void func_800AF1D4(s32 arg0, s32 arg1, s32 arg2) {
    if (!(D_800F83E0[arg0].a & 0x800040)) {
        func_800A7254(0, arg0, 9, 0);
        func_800AF0C4(arg0, arg1, arg2);
    }
}

void func_800AF264(s32 arg0, s32 arg1, s32 arg2) {
    func_800AEBF0();
    ((void (*)(s32, s32, s32))func_800AEB20)(arg0, arg1, arg2);
    func_800A7254(0, arg0, 4, 0);
    D_800F83E0[arg0].a &= ~0x400000;
    if (arg1 == 0xE) {
        D_800F83E0[arg0].a &= 0xF7FF7FB3;
    }
}

void func_800AF320(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_800AEBF0();
    func_800AEB80(arg0, arg1, arg2);
    func_800AF0C4(arg0, arg1, arg2);
}

void func_800AF380(s32 arg0) {
    func_800A7254(2, arg0, 0x15, 0xF);
}

void func_800AF3AC(s32 arg0, s32 arg1, s32 arg2) {
    s32 n;
    u32 flags;
    u32 v;

    n = 0;
    v = (u32)D_800F8410[arg0][0] >> 5;
    flags = D_800F83E0[arg0].a;
    if ((s32)flags < 0 && D_800F7DC6 == 1) {
        flags |= 0x08000000;
    }
    if (flags & 0x8000) {
        n += v;
    }
    if (flags & 0x08000000) {
        n -= v;
    }
    D_800F5BBE[arg0].a = n;
    if (arg2 != 0) {
        func_800AEB20(arg0, arg1);
    } else {
        func_800AEB80(arg0, arg1, 0);
    }
}

void func_800AF470(s32 arg0) {
    D_800F5BE0[arg0].a = 3;
}

void func_800AF494(s32 arg0, s32 arg1, s32 arg2) {
    s32 off;

    switch (D_800F7DC6) {
    case 1:
        func_800AF3AC(arg0, arg1, arg2);
    case 3:
    case 0:
        if (arg2 != 0) {
            func_800AF264(arg0, arg1, arg2);
        } else {
            func_800AF320(arg0, arg1, 0);
        }
        break;
    }
    if (D_800F7DC6 == 3) {
        off = (arg0 * 13) << 3;
        if (arg2 != 0) {
            D_800F83F6[off] = 0x13;
        } else {
            D_800F83F6[off] = 0;
        }
    }
}

void func_800AF594(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;

    func_800A7254(0, arg0, 0xA, arg2);
    i = 0;
    if (arg2 != 0) {
        func_800A23BC(arg0);
    } else {
        for (i = 0; i < 3; i++) {
            if (D_800F5E66[i][0] == arg0) {
                D_800F5E66[i][0] = 0;
                func_800A7254(0, i, 6, 0);
            }
        }
        func_800B108C(arg0);
    }
}

void func_800AF63C(void) {
    func_800B108C();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800AF65C);

s32 func_800AF834(s32 arg0) {
    s32 r;
    s32 i;

    r = -1;
    for (i = 0; i < 16; i++) {
        if (D_800A04D0[i] == arg0) {
            r = i;
        }
    }
    return r;
}

s32 func_800AF874(s32 arg0, s32 arg1, s32 arg2) {
    s32 r;
    u32 t;

    r = D_800F5BEC[arg0].a;
    if (D_800F5BE1[arg0].a & 8) {
        r |= 0x800840;
    }
    if (arg1 != 0) {
        t = D_800F83E0[arg0].a;
        if (t & 0x20000000) {
            r |= 0x5FFFFFFF;
        }
        if (t & 0x10000000) {
            r |= 1;
        }
    }
    if (D_800F83E0[arg0].a & 0x01000000) {
        r |= 0x7FFFFFFF;
    }
    if (r & 0x300) {
        r |= 0x300;
    }
    if (arg0 < 3 && arg2 != 0) {
        r &= ~1;
    }
    if (D_800F83E4[arg0][0] & 0x1000) {
        r |= 1;
    }
    if (r & 1) {
        r |= 0x200000;
    }
    if (!(M2C_FIELD(D_80063014, s32 *, 0x6C) & 0x80)) {
        r = 0;
    }
    return r;
}

s32 func_800AF9C8(void) {
    s32 flags;
    s32 mask;
    s32 sel;
    s32 hit;
    s32 inv;
    s32 sw;
    s32 i;
    s32 off;
    s32 bits;
    s32 b;
    s32 n;
    s32 bt;
    s32 k;
    s32 v;
    s32 x;
    s32 y;
    s32 t4;
    u32 r;
    s32 mk;
    s32 tv;
    u16 *q;

    flags = M2C_FIELD(D_80063014, s32 *, 0x50);
    mask = D_8016375A;
    if (!(M2C_FIELD(D_80063014, s32 *, 0x90) & 0x01000000)) {
        mask &= D_80163758;
        if ((M2C_FIELD(D_80063014, s32 *, 0x6C) & 0x900) != 0x900) {
            mask |= D_80163766 & ~D_800F7DCC;
        }
    } else {
        mask |= D_80163766;
    }
    v = M2C_FIELD(D_80063014, s32 *, 0x18);
    bits = (v ^ mask) & v;
    if (bits != 0) {
        for (i = 0; i < 10; i++) {
            off = i * 0x44;
            if ((bits >> i) & 1) {
                bt = D_800F5BC4[off];
                if (bt != 0xFF) {
                    M2C_SFIELD(D_80063014, s32 *, 0x18) |= 1 << bt;
                }
            }
        }
    }
    if (flags == 0) {
        M2C_FIELD(D_80063014, s32 *, 0x18) = 1 << M2C_FIELD(D_80063014, s32 *, 0);
    } else {
        hit = 0;
        if (flags & 0x40) {
            M2C_FIELD(D_80063014, s32 *, 0x18) = D_80163758 & ~D_80163766;
        } else {
            sw = 0;
            do {
                n = M2C_FIELD(D_80063014, s32 *, 0);
                b = flags & 2;
                inv = b != 0;
                if (n < 4) {
                    inv ^= 1;
                }
                k = M2C_FIELD(D_80063014, s32 *, 0x28);
                if (k != 3 && k != 0x14) {
                    mk = 0x400040;
                    tv = D_800F83E0[n].a;
                    if (tv & mk) {
                        inv ^= 1;
                    }
                    if (tv & 0x40) {
                        sw = 1;
                    }
                }
            } while (0);
            if ((flags & 0xC) == 4) {
                hit = 1;
            }
            if (M2C_FIELD(D_80063014, s32 *, 0xAC) != 0) {
                hit = 1;
                flags |= 4;
            }
            sel = 0x3F0;
            if (inv != 0) {
                sel = 0xF;
            }
            if (sw != 0) {
                M2C_FIELD(D_80063014, s32 *, 0x18) = sel;
                if (!(M2C_FIELD(D_80063014, s32 *, 0x90) & 0x200)) {
                    M2C_FIELD(D_80063014, s32 *, 0x18) = func_80014A84(sel);
                }
            }
            if (flags & 0x10) {
                mask &= sel;
            } else if (flags & 0x20) {
                mask &= D_8016375C;
            }
            sel &= mask;
            x = M2C_FIELD(D_80063014, s32 *, 0x18) & mask;
            M2C_FIELD(D_80063014, s32 *, 0x18) = x;
            if (!(M2C_FIELD(D_80063014, s32 *, 0x90) & 0x200000)) {
                if ((x != 0 && func_80014A58(M2C_FIELD(D_80063014, u32 *, 0x94)) >= 2) || hit != 0) {
                    if (M2C_FIELD(D_80063014, s32 *, 0x18) & 0xF) {
                        mask &= 0xF;
                    } else {
                        mask &= 0x3F0;
                    }
                    y = M2C_FIELD(D_80063014, s32 *, 0x18);
                    if (!(y & D_8016376E[0])) {
                        mask &= ~D_8016376E[0];
                    }
                    if (!(y & D_80163772)) {
                        mask &= ~D_80163772;
                    }
                    M2C_FIELD(D_80063014, s32 *, 0x18) = mask;
                }
                if (M2C_FIELD(D_80063014, s32 *, 0x18) == 0) {
                    t4 = flags & 4;
                    if (t4 != 0 && (flags & 8) && !(M2C_FIELD(D_80063014, s32 *, 0x90) & 0x200)) {
                        sel = func_80014A84(sel);
                    }
                    M2C_FIELD(D_80063014, s32 *, 0x18) = sel;
                }
                if ((flags & 4) == 0 || (M2C_FIELD(D_80063014, s32 *, 0x90) & 0x100200) == 0x100200) {
                    M2C_FIELD(D_80063014, s32 *, 0x18) = func_80014A84(M2C_FIELD(D_80063014, s32 *, 0x18));
                }
            }
            if ((M2C_FIELD(D_80063014, s32 *, 0x18) & D_8016376E[0]) && (M2C_FIELD(D_80063014, s32 *, 0x18) & D_80163772)) {
                q = &D_8016376E[func_80014B70() & 2];
                M2C_FIELD(D_80063014, s32 *, 0x18) = M2C_FIELD(D_80063014, s32 *, 0x18) & *q;
                M2C_FIELD(D_80063014, s32 *, 0xEC) = M2C_FIELD(D_80063014, s32 *, 0xEC) & *q;
            }
        }
    }
    r = M2C_FIELD(D_80063014, u32 *, 0x94);
    if (r == 0) {
        r = M2C_FIELD(D_80063014, s32 *, 0x18);
        M2C_FIELD(D_80063014, u32 *, 0x94) = r;
    }
    return r;
}

s32 func_800AFE98(s32 arg0) {
    return D_800F49F8[D_800F499C][arg0] >> 12;
}

void func_800AFECC(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 t;
    s32 v;
    s32 r;
    s32 h;
    s32 a2;
    s32 b;
    s32 a3;
    s32 a0;
    s32 v1;
    s32 m;
    s32 mx;
    s32 hi;
    s32 s12;
    s32 s15;
    s32 s18;
    s32 *p5;
    s32 *p6;
    s32 *q;

    k = D_800F499C;
    p6 = D_800F49F8[k];
    p5 = D_800F49A8[k];
    q = &D_800F49A0[k];
    t = *q;
    D_800F499C ^= 1;
    hi = t >> 13;
    *q = t & 0x1FFF;
    for (i = 0; i < 10; i++) {
        a2 = p5[i];
        m = a2 * (s16)D_800F5BBE[i].a;
        a3 = D_800F4A48[i] + a2;
        b = p6[i];
        s18 = a3 >> 13;
        D_800F4A48[i] = a3 & 0x1FFF;
        a0 = D_800F4A70[i] + b;
        D_800F4A70[i] = a0 & 0xFFF;
        v1 = D_800F4A98[i] + m;
        D_800F4A98[i] = v1 & 0x7FFF;
        p5[i] = 0;
        s12 = a0 >> 12;
        p6[i] = 0;
        s15 = v1 >> 15;
        if (!(D_800F83E0[i].a & 1)) {
            mx = D_800F8410[i][0];
            h = D_800F840C[i].a + s15;
            if (h < 0) {
                D_800F83E0[i].a |= 1;
                func_800A6278(i, i, 1);
                func_800A61D4();
                h = 0;
            } else if (mx < h) {
                h = mx;
            }
            D_800F840C[i].a = h;
        }
        for (j = 0; j < 0x10; j++) {
            v = D_800F5BC8[i][j];
            if (v != 0) {
                if (j == 0) {
                    r = hi;
                } else {
                    r = s18;
                    if (j >= 0) {
                        if (j < 4) {
                            if (j >= 2) {
                                r = s12;
                            }
                        }
                    }
                }
                v -= r;
                if (v < 0) {
                    v = 0;
                }
                if (v == 0) {
                    func_800A7254(2, i, j, j);
                }
                D_800F5BC8[i][j] = v;
            }
        }
    }
}

void func_800B0170(void) {
    s32 i;
    s32 *p;
    s32 *q;

    p = D_800F49A8[D_800F499C];
    q = D_800F49F8[D_800F499C];
    D_800F49A0[D_800F499C] += D_800F7DA6;
    for (i = 0; i < 10; i++) {
        p[i] += D_800F5BB8[i].a;
        q[i] += D_800F5BC2[i].a;
    }
}

void func_800B0234(void) {
    s32 i;
    s32 *p;
    s32 t;
    s32 k;
    s32 a;
    s32 v;
    s32 b;
    s32 c;
    u16 h;
    u32 m;

    p = D_800F49A8[D_800F499C];
    for (i = 0; i < 3; i++) {
        a = D_800F5BF4[i].a;
        k = (s16)D_800F5BBE[i].a;
        t = p[i];
        a += (k * t) >> 15;
        b = D_800F5BCC[i].a;
        c = D_800F5BCD[i].a;
        h = D_800F5BF6[i].a;
        if (a < 0) {
            a = 0;
        } else {
            m = D_800F8410[i][0];
            if (m < (u32)a) {
                a = m;
            }
        }
        v = t >> 13;
        b = b - v;
        c = c - v;
        if (b < 0) {
            b = 0;
        }
        if (c < 0) {
            c = 0;
        }
        if (!(D_800F83D0[0] & 2)) {
            D_8009D85C[i].hp = a;
            *(s16 *)((s32)D_8009D860 + i * 0x440) = h;
        }
        D_8009D868[i].v = b * 2;
        *(s16 *)((s32)D_8009D86A + i * 0x440) = c * 2;
    }
}

void func_800B0378(void) {
    T68 *e;
    s32 s0;
    s32 s1;
    s32 s2;
    s32 r;
    s32 id;
    s32 v;

    e = &D_800F83E0[M2C_FIELD(D_80063014, s32 *, 0)];
    func_800B0C14();
    s0 = -1;
    if (M2C_FIELD(D_80063014, s32 *, 0x234) & 1) {
        s0 = 0xFF;
    }
    if (M2C_FIELD(D_80063014, s32 *, 0x230) & 0x63) {
        s0 = 0xFF;
    }
    if (M2C_FIELD(D_80063014, s32 *, 0x228) & 0x2404445) {
        if (M2C_FIELD(D_80063014, s32 *, 0x228) & 4) {
            M2C_FIELD(D_80063014, s32 *, 0x23C) |= 4;
        }
        if (M2C_FIELD(D_80063014, s32 *, 0x228) & 0x40) {
            M2C_FIELD(D_80063014, s32 *, 0x23C) |= 0x40;
        }
        s0 = 0xFF;
        if (M2C_FIELD(D_80063014, s32 *, 0x228) & 0x400000) {
            M2C_FIELD(D_80063014, s32 *, 0x23C) |= 0x400000;
        }
    }
    if (M2C_FIELD(D_80063014, s32 *, 0x218) & 0x20) {
        s0 = 0xFF;
    }
    s2 = M2C_FIELD(D_80063014, s32 *, 0x260) + func_800B1218(M2C_FIELD(D_80063014, s32 *, 0), e->pad[0x10], 5) / 4;
    s1 = func_800B0B94(M2C_FIELD(D_80063014, s32 *, 0));
    v = func_800B0B94(M2C_FIELD(D_80063014, s32 *, 0x208));
    if (s0 == -1) {
        s0 = func_800B0E5C(s2 + s1 - v);
    }
    if (s0 <= 0) {
        s0 = 1;
    }
    r = func_80014BA8(0x64);
    id = M2C_FIELD(D_80063014, s32 *, 0);
    if (r < (D_800F83E0[id].pad[0x11] >> 2)) {
        s0 = 0xFF;
    } else if (id >= 4) {
        v = M2C_FIELD(D_80063014, s32 *, 0x208);
        if (v < 3) {
            if (r < (D_800F83E0[v].pad[0x11] >> 2)) {
                s0 = 0;
            }
        }
    }
    if (func_800B2F70() < s0) {
        func_800B0DF8();
    } else {
        M2C_FIELD(D_80063014, s32 *, 0x218) |= 1;
    }
}

void func_800B062C(void) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    a = M2C_FIELD(D_80063014, s32 *, 0x260);
    d = M2C_FIELD(D_80063014, s32 *, 4) - (D_800F83E9[M2C_FIELD(D_80063014, s32 *, 0x208) * 0x68] >> 1);
    b = func_80014BA8(0x64);
    c = func_80014BA8(0x64) + 1;
    if (a < 0xFF && !(M2C_FIELD(D_80063014, s32 *, 0x230) & 0x63)
        && ((M2C_FIELD(D_80063014, s32 *, 0x6C) & 0x200) || !(M2C_FIELD(D_80063014, s32 *, 0x228) & 0x40000))
        && (M2C_FIELD(D_80063014, s32 *, 0x80) != 0 || !(M2C_FIELD(D_80063014, s32 *, 0x228) & 0x2004445))) {
        a = func_800B0E5C(a);
        if (b < D_800F842D[M2C_FIELD(D_80063014, s32 *, 0x208) * 0x68] || c >= a + d) {
            M2C_FIELD(D_80063014, s32 *, 0x218) |= 1;
        }
    }
}

void func_800B079C(void) {
    s32 a;
    s32 b;
    s32 v;
    s32 s;

    a = M2C_FIELD(D_80063014, s32 *, 0);
    b = M2C_FIELD(D_80063014, s32 *, 0x208);
    if (!(M2C_FIELD(D_80063014, s32 *, 0x218) & 1)) {
        s = 0xFF;
        if (!(M2C_FIELD(D_80063014, s32 *, 0xC8) & 0x40000000)) {
            v = M2C_FIELD(D_80063014, s32 *, 4) + D_800F83F5[(a * 13) << 3] - D_800F83E9[(b * 13) << 3];
            s = v / 4;
            if (a < 3) {
                s += D_800F5F01[(a * 3) << 3];
            }
        }
        if (s >= func_800B2F70()) {
            M2C_FIELD(D_80063014, s32 *, 0x220) |= 2;
        }
    }
}

void func_800B089C(void) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(D_80063014, s32 *, 0x3C);
    if ((temp_v1 != 0) && (((s32) M2C_FIELD(D_80063014, s32 *, 0x254) % temp_v1) != 0)) {
        M2C_FIELD(D_80063014, s32 *, 0x218) = (s32) (M2C_FIELD(D_80063014, s32 *, 0x218) | 1);
    }
}

void func_800B0910(void) {
    u16 buf[2];
    s32 id;
    s32 i;
    s32 found;
    s32 cur;
    s32 f;
    s32 v;
    s32 t;
    u8 c;

    found = 0;
    id = M2C_FIELD(D_80063014, s32 *, 0x208);
    for (i = 0; i < 3; i++) {
        if (D_800F5E66[i][0] == id) {
            break;
        }
    }
    if (i == 3 && id >= 4) {
        cur = M2C_FIELD(D_80063014, s32 *, 0);
        if (cur < 3 && D_800F5E66[cur][0] == 0 && !(M2C_FIELD(D_80063014, s32 *, 0x228) & 0x400000) && D_800F5BBA[id].a != 0) {
            f = M2C_FIELD(D_80063014, s32 *, 0x230);
            if (!(f & 0x20)) {
                t = M2C_FIELD(D_80063014, s32 *, 0x254) - 0x32;
                v = M2C_FIELD(D_80063014, s32 *, 4) - t;
                if (v < 0) {
                    v = 0;
                }
                if (M2C_FIELD(D_80063014, s32 *, 0xB8) >= 2) {
                    v = v * 4 / 5;
                }
                if (M2C_FIELD(D_80063014, s32 *, 0xAC) != 0) {
                    v >>= 1;
                }
                if (f & 2) {
                    v = 0xFF;
                }
                if (D_800F5BC5[cur * 0x44] == 5 && v < 0x64) {
                    v = 0x64;
                }
                if (func_80014BA8(0x64) < v) {
                    found = 1;
                }
            }
        }
    }
    if (found != 0) {
        buf[1] = 0xFFFF;
        buf[0] = id;
        c = D_800F5BC7[id].a;
        if (c != 0xFF) {
            buf[1] = c;
        }
        D_800F5E66[M2C_FIELD(D_80063014, s32 *, 0)][0] = id;
        func_800B0FFC(M2C_FIELD(D_80063014, s32 *, 0), 0x5A, 1, buf);
        M2C_FIELD(D_80063014, s32 *, 0xE4) = -1;
        return;
    }
    M2C_FIELD(D_80063014, s32 *, 0x218) |= 1;
}

void func_800B0B8C(void) {
}

s32 func_800B0B94(s32 arg0) {
    s32 v;

    if (arg0 < 4) {
        v = (D_800F83F4[arg0][0] >> 2) + D_800F83EF[arg0][0];
    } else {
        v = D_800F83EF[arg0][0];
    }
    return func_800B1218(arg0, v, 4);
}

void func_800B0C14(void) {
    s32 g0;
    s32 g1;
    s32 t0;
    s32 a1;
    s32 a3;
    s32 t4;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 x;
    s32 i;

    t3 = 0;
    t2 = 0;
    t1 = 0;
    g0 = M2C_FIELD(D_80063014, s32 *, 0);
    t0 = 1 << g0;
    g1 = M2C_FIELD(D_80063014, s32 *, 0x208);
    a3 = t0 & -((D_800F83E4[g0][0] & 0x80) != 0);
    a1 = 1 << g1;
    if (D_800F83E4[g1][0] & 0x80) {
        a3 |= a1;
    }
    t4 = a3;
    for (i = 0; i < 3; i++) {
        if (D_8016376E[i] & t0) {
            t3 = i;
        }
        if (D_8016376E[i] & a1) {
            t2 = i;
        }
    }
    if (t3 == 1) {
        x = 0;
        switch (t2) {
        case 0:
            x = 1;
        case 2:
            break;
        default:
            goto skip;
        }
        if (a3 & t0) {
            x ^= 1;
        }
        if (x != 0) {
            a3 ^= t0;
        }
    }
skip:
    if (t0 & a3) {
        t1 ^= 1;
    }
    if (a1 & a3) {
        t1 ^= 1;
    }
    if (t3 != t2 && t1 == 0) {
        a3 ^= a1;
        M2C_FIELD(D_80063014, s32 *, 0x234) |= 1;
    }
    a3 ^= t4;
    if (a3 & t0) {
        D_800F83E4[M2C_FIELD(D_80063014, s32 *, 0)][0] ^= 0x80;
    }
    if (a3 & a1) {
        M2C_FIELD(D_80063014, s32 *, 0x234) |= 2;
    }
}

void func_800B0DF8(void) {
    if (M2C_FIELD(D_80063014, s32 *, 0x234) & 2) {
        D_800F83E4[M2C_FIELD(D_80063014, s32 *, 0x208)][0] ^= 0x80;
    }
}

s32 func_800B0E5C(s32 arg0) {
    if (arg0 < 0xFF) {
        if (M2C_FIELD(D_80063014, s32 *, 0xC8) & 0x20) {
            arg0 -= arg0 * 3 / 10;
        }
    }
    return arg0;
}

s32 func_800B0EB4(s32 arg0) {
    u32 f;
    s32 r;

    f = D_800F83E0[arg0].a;
    r = arg0 < 4;
    if (f & 0x40) {
        r++;
    }
    if (f & 0x400000) {
        r++;
    }
    return r & 1;
}

u16 func_800B0F04(BtlB0F04 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 n;
    s32 v;
    u16 ret;
    BtlB0F04 *p;

    ret = 0xFFFF;
    p = arg0;
    for (i = 0; i < 4; i++) {
        v = p->a[i];
        if ((v & ~0x3F) == arg1) {
            n = v & 0x3F;
            if (arg2 != 0) {
                n = 0x100;
            } else {
                n = n * arg3 / 256;
            }
            if (n >= (func_80014B70() & 0x3F)) {
                ret = p->b[i];
                break;
            }
        }
    }
    return ret;
}

s32 func_800B0FFC(s32 arg0, s32 arg1, s32 arg2, u16 *arg3) {
    return func_800A31A0(arg0, 2, arg2, func_800A5EB0(((s32 (*)(s32))func_8001521C)(arg1), arg3) + 0x100);
}

void func_800B1060(s32 arg0) {
    func_800A31A0(0xA, 2, 1, arg0);
}

s32 func_800B108C(arg0)
{
    return func_800A31A0(arg0, 5, 0, 0);
}

s32 func_800B10B4(s32 arg0) {
    return D_800F840C[arg0].b >> 2 >= D_800F840C[arg0].a;
}

void func_800B10F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    BEnt12 *p;
    s8 *q;

    p = func_800A2F4C();
    q = func_800A2FD0();
    p->b = 1;
    p->e = -1;
    p->a = arg0;
    p->c = arg1;
    p->pad[1] = arg2;
    p->pad[0] = arg3;
    p->pad[2] = 0;
    p->d = arg4;
    q[0] = arg0;
    q[1] = arg0;
    q[2] = 0x33;
    *(s16 *)(q + 4) = arg5;
    *(s32 *)(q + 8) = arg6;
    func_800A317C();
}

s32 func_800B11B4(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        if (D_800F64EC[i] == arg0) {
            break;
        }
    }
    if (i == 0x20) {
        func_800155A4(0x20);
    }
    return i;
}

s32 func_800B1218(s32 arg0, s32 arg1, s32 arg2) {
    return arg1 + arg1 * D_800F5BD8[arg0].a[arg2] / 100;
}

void func_800B1268(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 v;

    for (i = 0; i < 8; i++) {
        if ((arg2 >> i) & 1) {
            v = D_800F5BD8[arg0].a[i] + arg1;
            if (v > 100) {
                v = 100;
            }
            if (v < -100) {
                v = -100;
            }
            D_800F5BD8[arg0].a[i] = v;
        }
    }
}

u32 func_800B12DC(void) {
    u32 r;
    s32 x;

    x = D_800F7DC8;
    r = 0;
    if (x < 3) {
        r = (u32) ~x >> 31;
    }
    return r;
}

void func_800B1304(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 0x40; i++) {
        if (D_800F6934[i].c == arg0 && D_800F6934[i].a != 0xFF && D_800F6934[i].a >= arg1) {
            D_800F6934[i].c = -1;
        }
    }
}

s32 func_800B1368(void) {
 s32 v; v = D_800F4AC0[D_800F4AC4[1]++]; v |= D_800F4AC0[D_800F4AC4[1]++] << 8; return v; }

s32 func_800B13B0(s32 arg0, s32 arg1, void **arg2) {
    if (arg1 < 0x2000) {
        *arg2 = D_800F87F0[arg0];
    } else if (arg1 < 0x4000) {
        *arg2 = D_800F83A4;
        arg1 -= 0x2000;
    } else {
        *arg2 = &D_800F83E0[arg0];
        arg1 -= 0x4000;
    }
    return arg1;
}

void func_800B141C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p;
    u8 *q;
    s32 n;
    s32 mask;

    n = func_800B13B0(arg0, arg2, (void **)&p);
    switch (arg1) {
    case 0:
        mask = 1 << (n & 7);
        q = p;
        q += n >> 3;
        *q &= ~mask;
        if (arg3 != 0) {
            *q |= mask;
        }
        break;
    case 1:
        q = p;
        q += n / 8;
        *q = arg3;
        break;
    case 2:
        q = p;
        q += n / 16 * 2;
        *(s16 *)q = arg3;
        break;
    case 3:
        p = p + n / 32 * 4;
        *(s32 *)p = arg3;
        break;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800B153C);

void func_800B1624(s32 arg0, u32 v) {
    switch (arg0) {
    case 3:
        ((BtlStk *)D_800F4AC4)->buf[--((BtlStk *)D_800F4AC4)->sp] = v;
        v >>= 8;
    case 2:
        ((BtlStk *)D_800F4AC4)->buf[--((BtlStk *)D_800F4AC4)->sp] = v;
        v >>= 8;
    case 0:
    case 1:
        ((BtlStk *)D_800F4AC4)->buf[--((BtlStk *)D_800F4AC4)->sp] = v;
        break;
    }
}

void func_800B16D0(s32 arg0) {
    s32 hi;
    s32 lo;
    s32 i;

    hi = arg0 >> 4;
    lo = arg0 & 0xF;
    switch (hi) {
    case 0:
        func_800B1624(lo, ((B1C1C_T *)D_800F4AC4)->w[0][0]);
        break;
    case 1:
        func_800B1624(2, ((B1C1C_T *)D_800F4AC4)->w[0][0]);
        break;
    case 2:
        i = 10;
        do {
            if ((((B1C1C_T *)D_800F4AC4)->mask[0] >> (i - 1)) & 1) {
                func_800B1624(lo, ((B1C1C_T *)D_800F4AC4)->w[0][i - 1]);
            }
        } while (--i > 0);
        func_800B1624(2, ((B1C1C_T *)D_800F4AC4)->mask[0]);
        break;
    }
    ((BtlStk *)D_800F4AC4)->buf[--((BtlStk *)D_800F4AC4)->sp] = arg0;
}

s32 func_800B17F0(s32 arg0) {
    s32 v;

    v = 0;
    switch (arg0) {
    case 3:
        v = ((BtlStk *)D_800F4AC4)->buf[((BtlStk *)D_800F4AC4)->sp++];
    case 2:
        v <<= 8;
        v |= ((BtlStk *)D_800F4AC4)->buf[((BtlStk *)D_800F4AC4)->sp++];
    case 0:
    case 1:
        v <<= 8;
        v |= ((BtlStk *)D_800F4AC4)->buf[((BtlStk *)D_800F4AC4)->sp++];
        break;
    }
    return v;
}

s32 func_800B18A8(arg0) {
    s32 b;
    s32 hi;
    s32 lo;
    s32 v;
    s32 i;

    b = ((BtlStk *)D_800F4AC4)->buf[((BtlStk *)D_800F4AC4)->sp++];
    hi = b >> 4;
    lo = b & 0xF;
    D_800F4AC4[arg0 + 6] = hi;
    D_800F4AC4[arg0 + 8] = lo;
    switch (hi) {
    case 0:
        ((B1C1C_T *)D_800F4AC4)->mask[arg0] = 0x3FF;
        v = func_800B17F0(lo);
        for (i = 0; i < 10; i++) {
            ((B1C1C_T *)D_800F4AC4)->w[arg0][i] = v;
        }
        break;
    case 1:
        ((B1C1C_T *)D_800F4AC4)->w[arg0][0] = func_800B17F0(2);
        break;
    case 2:
        ((B1C1C_T *)D_800F4AC4)->mask[arg0] = func_800B17F0(2);
        for (i = 0; i < 10; i++) {
            if ((((B1C1C_T *)D_800F4AC4)->mask[arg0] >> i) & 1) {
                ((B1C1C_T *)D_800F4AC4)->w[arg0][i] = func_800B17F0(lo);
            }
        }
        break;
    }
    return b;
}

s32 func_800B1A5C(void) {
    s32 t;
    s32 r;

    t = D_800F4AC4[2];
    r = func_800B18A8();
    D_800F4AC4[2] = t;
    return r;
}

s32 func_800B1AA0(s32 arg0, s32 arg1) {
    s32 op;
    u32 a;
    u32 b;
    s32 r;

    op = D_800F4AC4[3];
    a = D_800F4AC4[arg0 + 11];
    b = D_800F4AC4[arg1 + 21];
    r = 0;
    switch (op) {
    case 0x30:
        r = a + b;
        break;
    case 0x31:
        r = a - b;
        break;
    case 0x32:
        r = a * b;
        break;
    case 0x33:
        r = a / b;
        break;
    case 0x34:
        r = a % b;
        break;
    case 0x35:
        r = a & b;
        break;
    case 0x36:
        r = a | b;
        break;
    case 0x37:
        r = ~a;
        break;
    }
    return r;
}

s32 func_800B1B64(s32 arg0, s32 arg1) {
    s32 op;
    u32 a;
    u32 b;
    s32 r;

    op = D_800F4AC4[3];
    a = D_800F4AC4[arg0 + 11];
    b = D_800F4AC4[arg1 + 21];
    r = 0;
    switch (op) {
    case 0x40:
        if (a == b) {
            r = 1;
        }
        break;
    case 0x41:
        if (a != b) {
            r = 1;
        }
        break;
    case 0x42:
        if (a >= b) {
            r = 1;
        }
        break;
    case 0x43:
        if (a <= b) {
            r = 1;
        }
        break;
    case 0x44:
        if (a > b) {
            r = 1;
        }
        break;
    case 0x45:
        if (a < b) {
            r = 1;
        }
        break;
    }
    return r;
}

s32 func_800B1C1C(s32 arg0) {
    s32 i;
    u16 r;

    r = 0;
    for (i = 0; i < 10; i++) {
        if ((((B1C1C_T *)D_800F4AC4)->mask[arg0] >> i) & 1 && ((B1C1C_T *)D_800F4AC4)->w[arg0][i] != 0) {
            r |= 1 << i;
        }
    }
    return r != 0;
}

s32 func_800B1C94(s32 arg0) {
    s32 i;
    s32 v;
    u16 mask;

    i = 0;
    if (D_800F4AC4[arg0 + 6] == 2) {
        v = 0;
        mask = ((B1C1C_T *)D_800F4AC4)->mask[arg0];
        for (i = 0; i < 10; i++) {
            if ((mask >> i) & 1) {
                v = ((B1C1C_T *)D_800F4AC4)->w[arg0][i];
                break;
            }
        }
        ((B1C1C_T *)D_800F4AC4)->mask[arg0] = 0x3FF;
        for (i = 9; i >= 0; i--) {
            ((B1C1C_T *)D_800F4AC4)->w[arg0][i] = v;
        }
        i = 1;
    }
    return i;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800B1D48);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1c", func_800B2A2C);

void func_800B2B5C(s16 arg0, s16 arg1, s16 arg2) {
    Q8 q;
    u8 a[2] = {3, 0xD};
    u8 b[2] = {0x38, 0x48};
    u32 i;

    for (i = 0; i < 2; i++) {
        if (arg1 == a[i]) {
            arg2 -= b[i];
        }
    }
    if (arg1 == 0x20) {
        arg2 = func_800B11B4(arg2);
    }
    D_800F83F8[arg0][0] = D_800F83B2;
    q.a = D_800F4AC8;
    q.c = arg0;
    q.d = arg1;
    q.e = arg2;
    q.f = D_800F83B2;
    func_800A3D4C(&q);
}

u16 func_800B2C60(s32 arg0) {
    u16 var_s0;
    void *temp_v0;

    var_s0 = 0;
    if (arg0 <= 0xFFFE) {
        temp_v0 = func_800B2EBC();
        if (temp_v0 != NULL) {
            var_s0 = M2C_FIELD(temp_v0, u16 *, 4);
        }
    }
    return var_s0;
}

void func_800B2CAC(s32 arg0, s32 arg1) {
    switch (arg0) {
    case 0:
        D_800F83A6 = D_8009D288[arg1];
        break;
    case 1:
        D_8009D288[arg1] = D_800F83A6;
        break;
    }
}

void func_800B2CFC(s32 arg0, s32 arg1) {
    s32 d;
    s32 s;
    s32 e;
    s32 v;
    s32 d2;
    s32 s2;
    s32 e2;

    v = D_800F5BB4[arg1].f38;
    D_800F5BB4[arg1].f10 = arg0;
    D_800F5BB4[arg1].f38 = v | 1;
    D_800F83DC[arg0].f30 = D_800F83DC[arg1].f30;
    D_800F83DC[arg0].f2C = D_800F83DC[arg1].f2C;
    D_800F83DC[arg0].f04 = D_800F83DC[arg1].f04;
    D_800F83DC[arg0].f48 = D_800F83DC[arg1].f48;
    d = (s32)D_800F5BC8[arg0];
    D_800F5BB4[arg0].f0A = D_800F5BB4[arg1].f0A;
    s = (s32)D_800F5BC8[arg1];
    D_800F5BB4[arg0].f2C = D_800F5BB4[arg1].f2C;
    e = d + 0x10;
    D_800F5BB4[arg0].f2D = D_800F5BB4[arg1].f2D;
    do {
        *(u8 *)d = *(u8 *)s;
        d++;
        s++;
    } while (d < e);
    d2 = (s32)&D_800F5BD8[arg0];
    s2 = (s32)&D_800F5BD8[arg1];
    e2 = d2 + 8;
    do {
        *(u8 *)d2 = *(u8 *)s2;
        d2++;
        s2++;
    } while (d2 < e2);
    func_800AE954(arg0);
    func_800B108C(arg0);
}

void *func_800B2EBC(arg0) {
    E1C *r;
    s32 i;

    r = NULL;
    if (arg0 < 0x100) {
        r = &D_800708C4[arg0];
    } else {
        for (i = 0; i < 32; i++) {
            if (D_800F616C.id[i] == arg0) {
                r = &D_800F616C.e[i];
                break;
            }
        }
    }
    return r;
}

s32 func_800B2F30(void) {
    return func_80014B70() & 0xFF;
}

s32 func_800B2F50(void) {
    return func_80014BE4() & 0xFFFF;
}

s32 func_800B2F70(void) {
    u16 r;

    r = func_800B2F50();
    return r * 99 / 0xFFFF + 1;
}

s32 func_800B2FC4(s32 arg0) {
    return (arg0 * ((func_800B2F30() & 0xFF) + 0xF01)) >> 12;
}

s32 func_800B3000(u32 arg0) {
    s32 var_v1;
    u32 var_a0;

    var_a0 = arg0;
    var_v1 = 0;
    if (var_a0 & 0xFFFF) {
        do {
            if (var_a0 & 1) {
                var_v1 += 1;
            }
            var_a0 = (u32) (var_a0 & 0xFFFF) >> 1;
        } while (var_a0 != 0);
    }
    return var_v1;
}

s32 func_800B3030(s32 arg0) {
    s32 bit;
    s32 n;

    bit = 0;
    n = func_800B3000((u16) arg0);
    if (n != 0) {
        n = (func_800B2F30() & 0xFF) % n;
        for (bit = 1; (u16) bit != 0; bit <<= 1) {
            if ((arg0 & bit) & 0xFFFF) {
                if (--n < 0) {
                    break;
                }
            }
        }
    }
    return (u16) bit;
}
