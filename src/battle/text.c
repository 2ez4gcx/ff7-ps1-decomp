#include "common.h"
#include "battle/decls.h"

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A1158);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A1798);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A22C0);

void func_800A23BC(s32 arg0) {
    if (D_800E7A38 == arg0) {
        D_800E7A38 = -1;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A23E0);

void func_800A283C(void) {
    u32 i;
    u32 start;
    s32 k;

    k = 0;
    for (i = 0, start = 0; i < 0x6D; i++) {
        if (i == start) {
            D_800F38AC[k] = i;
            k++;
        }
        if (D_800A0098[i] == 0x1F) {
            start = i + 1;
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A2894);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A2974);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A2B28);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A0098);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A0108);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A010C);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", jtbl_800A0120);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A2BF4);

void func_800A2CC4(s32 arg0) {
    func_800B10F0(M2C_FIELD(D_80063014, s32 *, 0), arg0, M2C_FIELD(D_80063014, s32 *, 0x28), M2C_FIELD(D_80063014, s32 *, 0x24), M2C_FIELD(D_80063014, s32 *, 0x98), 0, 0);
}

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A01A8);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A2DB0);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A304C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A3354);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A3534);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A35F8);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A3828);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A38FC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A3D4C);

void func_800A3E98(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Q8 q;

    q.c = arg0;
    q.a = arg1;
    q.d = arg2;
    q.e = arg3;
    q.f = arg4;
    func_800A3D4C(&q);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A3ED0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4350);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4540);

void func_800A4844(s32 arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (arg0 != 0) {
        var_v0 = 3;
    }
    D_800F39EC = var_v0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4860);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4954);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4BA4);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4F60);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A50E0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A5250);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A56B0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A5750);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A5990);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A0240);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A5A5C);

void func_800A5A88(void) {
    func_80014BA8(0x36);
}

s32 func_800A5AA8(void) {
    return func_80014BA8(0x10) + 0x38;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A5AC8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A5BC8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A5E0C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A5EB0);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6000);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A61D4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6278);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A64A0);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6858);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A68FC);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6E9C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A7130);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A72C8);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A7458);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A7560);

void func_800A76AC(void) {
    M2C_FIELD(D_80063014, s32 *, 0x2C) = (s32) (M2C_FIELD(D_80063014, s32 *, 0x10) + 0x48);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A76CC);

void func_800A7784(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A778C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A784C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A79CC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A80DC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A81B8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A8424);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A866C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A8A6C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A8E84);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A9C24);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A9DA0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AA1C8);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AA574);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AA738);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AA950);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AABBC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AB308);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AB480);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AB674);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AB830);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AB9C4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ABA68);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ABB0C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AC73C);

void func_800ACA24(void) {
    M2C_FIELD(D_80063014, s32 *, 0x238) = 0;
    M2C_FIELD(D_80063014, s32 *, 0x23C) = 0;
    M2C_FIELD(D_80063014, s32 *, 0x240) = 0;
    M2C_FIELD(D_80063014, s32 *, 0x244) = 0;
    M2C_FIELD(D_80063014, s32 *, 0x230) = 0;
    M2C_FIELD(D_80063014, s32 *, 0x214) = 0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ACA4C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ACB98);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ACE88);

void func_800AD088(void *arg0) {
    s8 temp_v1;

    if ((M2C_FIELD(D_80063014, s32 *, 0x80) | M2C_FIELD(D_80063014, s32 *, 0x84) | M2C_FIELD(D_80063014, s32 *, 0x88)) & ~M2C_FIELD(D_80063014, s32 *, 0x22C)) {
        temp_v1 = M2C_FIELD(arg0, s8 *, 3);
        if (temp_v1 == -1) {
            func_800ABA68(arg0, -1, 0, -1, (s32) temp_v1);
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AD0FC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AD324);

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

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A04B0);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A04BC);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A04D0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AD4EC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AD5E8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AD73C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AD944);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ADBBC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ADC70);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ADD2C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE080);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE378);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE42C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE6C0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE764);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE82C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE954);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AEC10);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AEF68);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AF0C4);

void func_800AF1A8(s32 arg0) {
    func_800A7254(0, arg0, 8, 0);
}

void func_800AF1D4(s32 arg0, s32 arg1, s32 arg2) {
    if (!(D_800F83E0[arg0].a & 0x800040)) {
        func_800A7254(0, arg0, 9, 0);
        func_800AF0C4(arg0, arg1, arg2);
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AF264);

void func_800AF320(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_800AEBF0();
    func_800AEB80(arg0, arg1, arg2);
    func_800AF0C4(arg0, arg1, arg2);
}

void func_800AF380(s32 arg0) {
    func_800A7254(2, arg0, 0x15, 0xF);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AF3AC);

void func_800AF470(s32 arg0) {
    D_800F5BE0[arg0].a = 3;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AF494);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AF594);

void func_800AF63C(void) {
    func_800B108C();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AF65C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AF874);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AF9C8);

s32 func_800AFE98(s32 arg0) {
    return D_800F49F8[D_800F499C][arg0] >> 12;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AFECC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B0170);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B0234);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B0378);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B062C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B079C);

void func_800B089C(void) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(D_80063014, s32 *, 0x3C);
    if ((temp_v1 != 0) && (((s32) M2C_FIELD(D_80063014, s32 *, 0x254) % temp_v1) != 0)) {
        M2C_FIELD(D_80063014, s32 *, 0x218) = (s32) (M2C_FIELD(D_80063014, s32 *, 0x218) | 1);
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B0910);

void func_800B0B8C(void) {
}

void func_800B0B94(s32 arg0) {
    s32 v;

    if (arg0 < 4) {
        v = (D_800F83F4[arg0][0] >> 2) + D_800F83EF[arg0][0];
    } else {
        v = D_800F83EF[arg0][0];
    }
    func_800B1218(arg0, v, 4);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B0C14);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B0F04);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B10F0);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B141C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B153C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B1624);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B16D0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B17F0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B18A8);

s32 func_800B1A5C(void) {
    s32 t;
    s32 r;

    t = D_800F4AC4[2];
    r = func_800B18A8();
    D_800F4AC4[2] = t;
    return r;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B1AA0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B1B64);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B1C94);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B1D48);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B2A2C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B2B5C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B2CFC);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B3030);
