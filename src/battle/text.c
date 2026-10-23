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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A283C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A2D0C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A2F4C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A2FD0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A304C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A311C);

void func_800A317C(void) {
    *func_800A2FD0() = -1;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A31A0);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A32C0);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A34CC);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4480);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A44D8);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4B3C);

void func_800A4B9C(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4BA4);

u8 func_800A4CA8(s32 arg0) {
    return D_800F39F0[arg0].a;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4CC8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4D2C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4D88);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4E80);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4F14);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A4F60);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A50E0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A5250);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A555C);

void func_800A55BC(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_800F3A40[i].a = -1;
        D_800F3A40[i].b = -1;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A55F4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A5660);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A5FB0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6000);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A61D4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6278);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A64A0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A64B4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A653C);

void func_800A6590(void) {
    func_800A4D88();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A65B0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A661C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A66A4);

void func_800A6720(s32 arg0, s16 arg1) {
    func_800A5660(0xA, arg1);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6748);

void func_800A6798(s32 arg0, s32 arg1) {
    func_800A37F8(arg1);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A67B8);

void func_800A6834(s32 arg0) {
    u16 *p = &D_800F7DC4;
    *p = *p & ~(1 << arg0);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6858);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A68FC);

void func_800A6A3C(s32 arg0, s32 arg1) {
    D_800F5BC6[arg0].a |= arg1;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6A70);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6AC4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6B1C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6B88);

void func_800A6BFC(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6C04);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6C5C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6CC0);

void func_800A6D10(s32 arg0) {
    func_800A3E98(arg0, 3, 2, 0x36, 0);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6D3C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6D88);

void func_800A6DFC(void) {
}

void func_800A6E04(void) {
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A6E0C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A70C4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A7130);

void func_800A71E0(void) {
}

s32 func_800A71E8(s32 arg0) {
    return (arg0 + 1) & 0x7F;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A71F4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A7254);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A72C8);

void func_800A73C0(void) {
    M2C_FIELD(D_80063014, s32 *, 0x2C) = (s32) M2C_FIELD(D_80063014, s32 *, 0x10);
}

void func_800A73D8(void) {
    M2C_FIELD(D_80063014, s32 *, 0x2C) = (s32) (M2C_FIELD(D_80063014, s32 *, 0x10) + 0x38);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A73F8);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A85FC);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A8DCC);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AA468);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AA4FC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AA574);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AA688);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AC6B4);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ACD88);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ACE14);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AD420);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AD480);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A04B0);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A04BC);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A04D0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AD4EC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AD5E8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AD73C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AD804);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AD890);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ADDE8);

void func_800ADE5C(void) {
    M2C_FIELD(D_80063014, s32 *, 0x214) = (s32) (M2C_FIELD(D_80063014, s32 *, 0x48) * 0x14);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ADE84);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ADF38);

void func_800ADFC0(void) {
    s32 p = D_80063014;

    M2C_FIELD(p, s32 *, 0x214) = D_800F5BF4[M2C_FIELD(p, s32 *, 0)].a;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800ADFF4);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE2A0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE318);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE378);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE42C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE6C0);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE764);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE82C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AE954);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AEB20);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AEB80);

void func_800AEBF0(void) {
    func_800AE954();
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AEC10);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AEF68);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AF0C4);

void func_800AF1A8(s32 arg0) {
    func_800A7254(0, arg0, 8, 0);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800AF1D4);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B0B94);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B0C14);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B0DF8);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B0E5C);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B0EB4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B0F04);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B0FFC);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B11B4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B1218);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B1268);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B1304);

s32 func_800B1368(void) {
 s32 v; v = D_800F4AC0[D_800F4AC4[1]++]; v |= D_800F4AC0[D_800F4AC4[1]++] << 8; return v; }

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B13B0);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B1C1C);

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

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B2CAC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B2CFC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B2EBC);

s32 func_800B2F30(void) {
    return func_80014B70() & 0xFF;
}

s32 func_800B2F50(void) {
    return func_80014BE4() & 0xFFFF;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800B2F70);

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
