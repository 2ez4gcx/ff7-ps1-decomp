#include "common.h"
#include "battle/decls.h"

void func_800A2BF4(s32 arg0) {
    Ent8 *e;
    s32 start;
    s32 n;
    s32 i;

    start = 0;
    e = ((Row440 *)D_8009D84C)[arg0].e;
    n = 0;
    switch (M2C_FIELD(D_80063014, s32 *, 0xC)) {
    case 2:
    case 21:
        n = 0x38;
        break;
    case 3:
    case 22:
        start = 0x38;
        n = 0x10;
        break;
    case 13:
        start = 0x48;
        n = 0x18;
        break;
    }
    if (n != 0) {
        for (i = 0; i < n; i++) {
            if (e[i + start].a == M2C_FIELD(D_80063014, s32 *, 0x10)) {
                M2C_FIELD(D_80063014, s32 *, 0x14) = i + start;
                break;
            }
        }
    }
}

void func_800A2CC4(s32 arg0) {
    func_800B10F0(M2C_FIELD(D_80063014, s32 *, 0), arg0, M2C_FIELD(D_80063014, s32 *, 0x28), M2C_FIELD(D_80063014, s32 *, 0x24), M2C_FIELD(D_80063014, s32 *, 0x98), 0, 0);
}

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text1b", D_800A01A8);

u8 func_800A2D0C(void) {
    s32 i;
    u8 v;

    i = M2C_FIELD(D_80063014, s32 *, 0x208);
    if (i < 3) {
        v = D_800A01A8[M2C_FIELD(D_80063014, s32 *, 0xCC)];
    } else {
        v = D_800F83F1[i][0];
    }
    return v;
}

void func_800A2D68(s32 arg0) {
    s32 i;
    u8 *p;

    for (i = 0; i < 8; i++) {
        p = (u8 *) D_80063014 + i;
        if (p[0xD0] == 0xFF) {
            p[0xD0] = arg0;
            break;
        }
    }
}

void func_800A2DB0(void) {
    u16 sp10;
    s32 i;
    s32 j;

    i = M2C_FIELD(D_80063014, s32 *, 0x208);
    if (i >= 4 && !(D_800F5BE1[i].a & 0x10)) {
        sp10 = D_800F5FE4[D_80163658[i - 4].a].a;
        if (sp10 != 0xFFFF) {
            j = M2C_FIELD(D_80063014, s32 *, 0x208);
            if (D_801636BC[j].a < 0x11) {
                D_801636BC[j].a = 7;
            }
            func_800A7254(0, M2C_FIELD(D_80063014, s32 *, 0), 3, sp10);
            func_800B0FFC(M2C_FIELD(D_80063014, s32 *, 0), 0x56, 1, &sp10);
            j = M2C_FIELD(D_80063014, s32 *, 0x208);
            D_800F5BE1[j].a |= 0x10;
        }
    }
}

void func_800A2EFC(void) {
    D_800F3950 = D_800F3944;
    D_800F3954 = D_800F3948;
}

void func_800A2F24(void) {
    D_800F3944 = D_800F3950;
    D_800F3948 = D_800F3954;
}

BEnt12 *func_800A2F4C(void) {
    BEnt12 *p;

    p = &((BEnt12 *)&D_80163798)[D_800F3944];
    p->pad[1] = 0;
    p->pad[0] = 0;
    p->f = D_800F3948;
    if (D_800F3944 < 0x40) {
        D_800F3944 += 1;
    } else {
        func_800155A4(0x28);
    }
    return p;
}

s8 *func_800A2FD0(void) {
    S12b *p;

    p = &D_800FA9D0[D_800F3948];
    M2C_SFIELD(p, s8 *, 3) = -1;
    if (D_800F3948 < 0x80) {
        D_800F3948 += 1;
    } else {
        func_800155A4(0x28);
    }
    return &p->a;
}

void func_800A304C(void) {
    s32 tbl[10];
    s32 i;
    s32 k;

    for (i = 0; i < 10; i++) {
        tbl[i] = -1;
    }
    for (i = 0; i < D_800F3948; i++) {
        k = D_800FA9D0[i].a;
        if (k != -1 && (D_800FA9D0[i].b & 4)) {
            if (tbl[k] != -1) {
                D_800FA9D0[tbl[k]].b &= ~4;
            }
            tbl[k] = i;
        }
    }
}

void func_800A311C(u8 *arg0) {
    E0E *p;

    p = &D_800F9F3C[D_800F394C];
    arg0[3] = D_800F394C;
    p->a = (s8)arg0[0];
    p->d = -1;
    p->e = -1;
    D_800F394C = (D_800F394C + 1) & 0x7F;
}

void func_800A317C(void) {
    *func_800A2FD0() = -1;
}

s32 func_800A31A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    BEnt12 *p;

    p = func_800A2F4C();
    p->a = arg0;
    p->b = arg1;
    p->c = arg2;
    p->d = arg3;
    p->e = -1;
    p->f = -1;
    return (s32)p;
}

void func_800A3208(s32 arg0, s32 arg1) {
    S12 *p;

    if (D_800F3944 != 0) {
        p = &D_8016378C[D_800F3944];
        p->c = arg0;
        p->b = arg1;
    }
}

void func_800A3240(void) {
    if (D_800F3944 != 0) {
        D_801637A0[D_800F3944 - 1].a = -1;
    }
}

void func_800A3278(void) {
    D_800F3944 = 0;
    D_800F3948 = 0;
    D_80163798 = -1;
}

void func_800A329C(void) {
    if (D_800F3944 != 0) {
        D_800F3944 -= 1;
    }
}

void func_800A32C0(s32 arg0) {
    s32 v;
    if (D_800F7DAA != 0) {
        if (arg0 != 0) {
            if (D_800F7DBA == 6) {
                v = 1;
                if (D_800F6B9A != D_800F6BA1) v = 3;
                func_800A7254(0, 0, 7, v);
            }
        } else if (func_800A37F8(-1) != 0) {
            func_800A7254(0, 0, 7, 0);
        }
    }
}

void func_800A3354(void) {
    s32 i;
    s32 o;
    s32 c;

    func_800A32C0(D_800F3944);
    if (D_800F3944 != 0) {
        *(s8 *)func_800A2F4C() = -1;
    }
    func_800155B0();
    for (i = 0; i < 0x40; i++) {
        o = i * 12;
        c = (&D_80163798)[o];
        if (c == -1) {
            break;
        }
        if ((u32)(c - 4) < 6) {
            D_801636B8[c].pad[0] = D_800F83E0[c].pad[0xC];
        }
    }
    func_800B6D6C();
    func_800A3278();
    for (i = 4; i < 10; i++) {
        D_801636B8[i].pad[0] = D_800F83E0[i].pad[0xC];
    }
}

void func_800A345C(void) {
    if (D_800F3944 != 0) {
        func_800A3354();
    }
}

void func_800A3488(s32 arg0) {
    S12b *p;
    s32 i;

    for (i = 0; i < 128; i++) {
        p = &D_800FA9D0[i];
        if (p->a == arg0) {
            p->b &= ~4;
        }
    }
}

void func_800A34CC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    S12b *p;
    s32 i;

    for (i = 0; i < 0x80; i++) {
        p = &D_800FA9D0[i];
        if (p->a == arg0 && (s8)p->pad2[0] == arg1) {
            if (arg3 != 1 || (p->b & 4)) {
                p->pad2[0] = arg2;
            }
        }
    }
}

void func_800A3534(s32 arg0, s16 arg1) {
    s32 t;
    u16 a;
    u16 b;

    if (arg1 >= 0) {
        t = D_800F9F3C[arg1].a;
        if ((u32)t < 3) {
            a = D_800F9F3C[arg1].d;
            if ((u32)D_800F8410[t][0] >= a) {
                D_800F5BF4[t].a = a;
            }
            b = D_800F9F3C[arg1].e;
            if (D_800F840A[t][0] >= b) {
                D_800F5BF6[t].a = b;
            }
        }
    }
}

u16 func_800A35F8(void) {
    s32 mask;
    s32 i;
    s32 j;
    s32 s0;
    s32 s1;
    u16 ret;
    s32 t;
    s32 c;
    u16 *p;

    ret = 0xFFFF;
    mask = 0;
    for (i = 0; i < 4; i++) {
        if (D_8016361C[i] != 0xFFFF) {
            mask |= 1 << i;
        }
    }
    if (mask != 0) {
        func_80014578(9, 0x801C0000, 0);
        func_800145BC((s32 (*)())func_800A3354);
        func_80015B44(0x801C0000);
        while ((s0 = func_80015B50() & 0xFFFF) != 0xFFFF) {
            s1 = (s0 << 15) + 0x801B0000;
            func_80015BC0(s1);
            if (s0 == 1) {
                func_80014980((void *)s1);
            }
        }
        s1 = func_80014A38(func_80014A84(mask));
        for (i = 0; i < 3; i++) {
            c = D_8009CBDC[i];
            for (j = 0; j < 9; j++) {
                if (D_8009C738[j][0] == c) {
                    t = D_800F840C[i].a;
                    D_8009C764[j].v = t;
                    t = D_800F8408[i].a;
                    D_8009C768[j * 33].v = t;
                    break;
                }
            }
        }
        p = &D_8016361C[0xA8];
        (*p)++;
        if (*p < 8) {
            if (func_800A4860() != 0) {
                ret = D_8016361C[s1];
            } else {
                D_800F83C6[0] |= 4;
            }
        }
    }
    return ret;
}

s32 func_800A37F8(s32 arg0) {
    s32 r;

    r = 0;
    if (arg0 < 0) {
        r = D_800F39E0;
    } else {
        D_800F39E0 = arg0;
        D_800F39E4 = 0;
    }
    return r;
}
