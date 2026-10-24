#include "common.h"
#include "snobo/decls.h"

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A0390);

void func_800A057C(void) {
    s32 *p;
    u32 c;

    p = &D_800FF750;
    *p += 4;
    c = *(u8 *)p;
    func_800A62C4((c << 16) | (c << 8) | c, (s32) D_80102794);
    if (*p >= 0xFC) {
        *p = 0;
        D_800DD748 = func_800A05FC;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A05FC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A0820);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A0CDC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A0DC0);

void func_800A0EB0(void) {
    s32 *p;
    u8 *ot;
    s32 c;

    p = &D_800FF754;
    c = *p;
    ot = D_80102794;
    do {
        c -= 4;
        *p = c;
        c &= 0xFF;
        func_800A62C4((c << 16) | (c << 8) | c, (s32) ot);
    } while (0);
    if (*p <= 0) {
        D_800DD740 = 0;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A0F1C);

void func_800A12DC(void) {
    D_8009D456 = D_800BFEC0[D_801028E0];
}

void func_800A1300(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        D_8009A000 = arg0 + 0x9F;
        D_8009A004 = arg2;
        func_8002DA7C();
    }
    D_8009A000 = arg0 + 0x27;
    D_8009A004 = 0x40;
    D_8009A008 = arg1;
    func_8002DA7C();
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A1378);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A1470);

void func_800A1514(void) {
    func_80033E74(D_800BFD74, D_800BFD78, 0x801FC000, 0);
    do {

    } while (func_80034B44() != 0);
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A155C);

void func_800A1624(void) {
    func_80033E74(D_800BFD84, D_800BFD88, 0x80180000, 0);
    do {

    } while (func_80034B44() != 0);
    func_800AAE1C(0x80180000);
}

void func_800A1670(void) {
    D_800DD74C ^= 1;
    D_80102794 = D_800F7750[D_800DD74C];
    func_80044244(D_80102794, 0x1000);
    D_80102798 = D_800DD750[D_800DD74C];
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A16F0);

void func_800A17A4(void) {
    D_801028F8 = D_800DB1F8;
    D_80102908 = D_801027C4;
    D_8010290A = D_8010281C;
    D_8010290C = D_801027C8;
}

void func_800A180C(void) {
    D_800DB1F8 = D_801028F8;
    D_801027C4 = D_80102908;
    D_8010281C = D_8010290A;
    D_801027C8 = D_8010290C;
}

void func_800A1874(void) {
    void *temp_v0;

    temp_v0 = (D_801027C4 * 0xC) + M2C_FIELD(D_801028D4, s32 *, 0x1C);
    D_8010284C = M2C_FIELD(temp_v0, s32 *, 0);
    D_80102850 = M2C_FIELD(temp_v0, s32 *, 4);
    D_80102854 = M2C_FIELD(temp_v0, s32 *, 8);
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A18C4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A1978);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A1A68);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A1B08);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A1CC0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A212C);

void func_800A24C4(void *arg0) {
    SbFF784 *p;

    p = &D_800FF784[M2C_FIELD(arg0, s16 *, 0x36)];
    p->unk0 = M2C_FIELD(arg0, u16 *, 0x26);
    p->unk2 = M2C_FIELD(arg0, u16 *, 0x24);
    p->unk8 = M2C_FIELD(arg0, s32 *, 0x3C);
    p->unkC = M2C_FIELD(arg0, SbBlock32 *, 0x44);
    M2C_FIELD(arg0, s16 *, 0x36) += 1;
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A255C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A27FC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A2934);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A2FD4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A318C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A32E8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A3624);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A36C4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A38CC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A39CC);

s32 func_800A3C4C(u8 *arg0) {
    s32 r;

    r = func_800A39CC(arg0 + 0x34, *(s32 *)(arg0 + 0x3C), arg0);
    *(s16 *)(arg0 + 4) = r;
    if ((s16)r < 0) {
        return 1;
    }
    D_801027C8 = r;
    D_801028EC = arg0[0x63];
    return 0;
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A3CB4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A3E58);

s32 func_800A4144(u8 *arg0) {
    s32 r;

    r = func_800A39CC(arg0 + 0x34, *(s32 *)(arg0 + 0x3C), arg0);
    *(s16 *)(arg0 + 4) = r;
    if ((s16)r < 0) {
        return func_800A3CB4(arg0);
    }
    D_801027C8 = r;
    D_801028EC = arg0[0x63];
    return 0;
}

void func_800A41B0(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), u8 *, 4);
    func_800A41DC();
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A41DC);

void func_800A435C(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), u8 *, 5);
    func_800A41DC();
}

s32 func_800A4388(u8 *arg0) {
    s32 r;

    r = func_800A39CC(arg0 + 0x34, *(s32 *)(arg0 + 0x3C), arg0);
    *(s16 *)(arg0 + 4) = r;
    if ((s16)r < 0) {
        *(s16 *)arg0 = (*(u8 **)(arg0 + 0x10))[4];
        return func_800A41DC(arg0);
    }
    D_801027C8 = r;
    D_801028EC = arg0[0x63];
    return 0;
}

s32 func_800A4404(u8 *arg0) {
    s32 r;

    r = func_800A39CC(arg0 + 0x34, *(s32 *)(arg0 + 0x3C), arg0);
    *(s16 *)(arg0 + 4) = r;
    if ((s16)r < 0) {
        *(s16 *)arg0 = (*(u8 **)(arg0 + 0x10))[5];
        return func_800A41DC(arg0);
    }
    D_801027C8 = r;
    D_801028EC = arg0[0x63];
    return 0;
}

s32 func_800A4480(void) {
    return 1;
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A4488);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A45AC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A4728);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A4818);

void func_800A48D4(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0) = func_8003CC1C((s32) -M2C_FIELD(arg0, s16 *, 4), (s32) M2C_FIELD(arg0, s16 *, 2));
    M2C_FIELD(arg1, s16 *, 2) = 0;
    M2C_FIELD(arg1, s16 *, 4) = func_8003CC1C((s32) M2C_FIELD(arg0, s16 *, 0), (s32) M2C_FIELD(arg0, s16 *, 2));
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A4930);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A4A8C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A4D38);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A50B4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A5508);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A56C4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A5848);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A5964);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A5B3C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A5E80);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A61EC);

void func_800A62C4(s32 arg0, s32 arg1) {
    void *temp_s0;

    temp_s0 = D_80102798;
    M2C_FIELD(temp_s0, s32 *, 0) = 0x03000000;
    M2C_FIELD(temp_s0, s32 *, 4) = (s32) ((arg0 & 0xFFFFFF) | 0x61000000);
    M2C_FIELD(temp_s0, s32 *, 8) = 0xFF88FF60;
    M2C_FIELD(temp_s0, s32 *, 0xC) = 0xF00140;
    func_80046794(arg1, (s32) temp_s0);
    D_80102798 = temp_s0 + 0x10;
}

void func_800A633C(void) {
    if ((D_80102814 == 0) && (D_8010281C == 0x116)) {
        func_800A637C();
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A637C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A6480);

s32 func_800A65A8(void) {
    return 1;
}

s32 func_800A65B0(u8 *arg0) {
    D_800D71A8 = arg0[1];
    func_800A6968(0, arg0[2], arg0[3]);
    D_800FFC18 += 1;
    return 1;
}

s32 func_800A6600(u8 *arg0) {
    if (D_800FFC14 >= 3) {
        return 1;
    }
    D_800FFC14++;
    D_800FFC0C[D_800FFC14] = D_800FFC18 + 1;
    D_800FFC10[D_800FFC14] = arg0[1];
    D_800FFC18++;
    return 0;
}

s32 func_800A6690(void) {
    if (D_800FFC14 <= 0) {
        return 1;
    }
    if (D_800FFC10[D_800FFC14] != 0) {
        D_800FFC10[D_800FFC14]--;
        D_800FFC18 = D_800FFC0C[D_800FFC14];
    } else {
        D_800FFC14--;
        D_800FFC18++;
    }
    return 0;
}

s32 func_800A671C(void *arg0) {
    D_800FFC18 = (u16) M2C_FIELD(arg0, u8 *, 1);
    return 0;
}

s32 func_800A6730(u8 *arg0) {
    D_800FFC1C[arg0[1]] = 1;
    D_800FFC20[arg0[1]] = 0;
    D_800FFC24[arg0[1]] = arg0[2];
    D_800FFC18 += 1;
    return 0;
}

s32 func_800A6788(void) {
    return 1;
}

s32 func_800A6790(void *arg0) {
    D_800DB1E0 = (s16) M2C_FIELD(arg0, u8 *, 1);
    return 1;
}

s32 func_800A67A4(u8 *arg0) {
    s32 n;
    s32 t;

    t = arg0[1];
    do {
        n = D_800FFC18;
        D_800DB214 = 0x1000;
        D_800DB1E6 = 1;
        D_800DB20C = -t << 8;
        D_800FFC18 = ++n;
    } while (0);
    return 0;
}

s32 func_800A67EC(u8 *arg0) {
    u16 pad;

    pad = D_801027AC;
    if (arg0[2] != 0) {
        pad = ~pad;
    }
    if (pad & D_800DB2C4[arg0[1]]) {
        D_800FFC18 += 1;
        return 0;
    }
    return 1;
}

s32 func_800A6854(u8 *arg0) {
    if (D_800FFC28 != 0) {
        D_800FFC18 = arg0[D_800FFC28];
    } else {
        D_800FFC18 += 1;
    }
    return 0;
}

s32 func_800A6898(u8 *arg0) {
    D_800FFC1C[arg0[1]] = 0;
    D_800FFC18 += 1;
    return 0;
}

s32 func_800A68C8(void *arg0) {
    D_800FFC2C = M2C_FIELD(arg0, u8 *, 1);
    D_800FFC18 += 1;
    return 0;
}

s32 func_800A68F0(u8 *arg0) {
    D_8009A000 = arg0[1] + 0x27;
    D_8009A004 = arg0[3];
    D_8009A008 = D_800DB2D4[arg0[2]];
    func_8002DA7C();
    D_800FFC18 += 1;
    return 0;
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A6968);

void func_800A6AF8(s32 *arg0, s32 *arg1) {
    s32 i;

    for (i = 0x1C; i != -1; i--) {
        *arg0++ = *arg1++;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A6B20);

s32 func_800A6C78(s32 arg0) {
    return arg0;
}

s32 func_800A6C80(s32 arg0) {
    return (s32) (func_80039A74(((arg0 >> 2) * 2) - 0x400) + 0x1000) >> 1;
}

s32 func_800A6CB0(s32 arg0) {
    return 0x1000 - func_80039A74((arg0 >> 2) + 0x400);
}

s32 func_800A6CDC(s32 arg0) {
    return -func_80039A74((arg0 >> 2) + 0x800);
}

void func_800A6D04(void) {
    D_800D71A6 = 0;
    D_800FFC04 = 0;
    D_800FFC08 = 0x7F;
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A6D28);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A6F2C);

void func_800A7284(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        D_800DB264 = 0;
        D_800DB262 = 0;
        D_800DB260 = 0;
    }
    func_800A6480();
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A72C0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A7404);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A76E4);

s32 func_800A79BC(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x14) > 0x400) {
        if (D_801028EC & 8) {
            return 6;
        }
        if (M2C_FIELD(D_801028D4, u8 **, 0xC)[D_801027C4] & 1) {
            return 6;
        }
    }
    if (D_801027AC & 0x8000) {
        return 5;
    }
    if (D_801027AC & 0x2000) {
        return 4;
    }
    return 3;
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A7A4C);

s32 func_800A7BA0(void *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x14);
    return (0x8C - ((s32) (temp_v0 * temp_v0) >> 0x10)) < M2C_FIELD(arg0, s16 *, 0x10);
}

void func_800A7BC8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x66) = 0;
    func_800A6480();
    func_800A884C(arg0);
}

void func_800A7BFC(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x66) = 0;
    func_800A6480();
    func_800A884C(arg0);
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A7C30);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A7D90);

void func_800A7F7C(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_SFIELD(arg0, s32 *, 0x34) = 0;
        M2C_SFIELD(arg0, s32 *, 0x3C) = 0;
        D_800FFC28 = (s8) D_800FFC30;
        M2C_SFIELD(arg0, s32 *, 0) = (s32) (M2C_SFIELD(arg0, s32 *, 0) | 1);
    }
    func_800A6480();
    if (D_800FFC2C != 0) {
        M2C_SFIELD(arg0, s16 *, 0x76) = func_800A8B20((s32) D_801027BC, M2C_SFIELD(arg0, s16 *, 0x76), 0x10);
    }
}

void func_800A7FFC(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(arg0, s32 *, 0x3C) = 0;
        M2C_FIELD(arg0, s32 *, 0x34) = 0;
        M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0) | 1);
    }
    D_800FFC28 = ((u32) D_801027AC >> 0xC) & 1;
    func_800A6480();
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A8050);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A815C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A82F4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A848C);

void func_800A8554(void *arg0, s32 arg1) {
    s8 var_a0;

    if (arg1 != 0) {
        if (M2C_SFIELD(arg0, u8 *, 0xC) == 0xC) {
            M2C_SFIELD(arg0, s32 *, 0x34) = (s32) -M2C_SFIELD(arg0, s32 *, 0x34);
            M2C_SFIELD(arg0, s32 *, 0x3C) = (s32) -M2C_SFIELD(arg0, s32 *, 0x3C);
        }
        M2C_SFIELD(arg0, s16 *, 0x66) = 0;
        M2C_SFIELD(arg0, s16 *, 0x72) = 0;
        M2C_SFIELD(arg0, s32 *, 0x34) = (s32) ((s32) M2C_SFIELD(arg0, s32 *, 0x34) >> 1);
        M2C_SFIELD(arg0, s32 *, 0x3C) = (s32) ((s32) M2C_SFIELD(arg0, s32 *, 0x3C) >> 1);
        D_801027CC += 2;
        if (M2C_SFIELD(arg0, s16 *, 0x14) >= 0x501) {
            var_a0 = (D_80102958 % 3) + 1;
        } else {
            var_a0 = 0;
        }
        D_800FFC30 = var_a0;
    }
    if (D_800FFC2C != 0) {
        func_800A86A4(arg0);
    }
    func_800A6480();
    func_800A884C(arg0);
}

void func_800A864C(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_SFIELD(arg0, s16 *, 0x66) = 0;
        D_801027CC += 1;
    }
    func_800A86A4(arg0);
    func_800A6480();
    func_800A884C(arg0);
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A86A4);

void func_800A8740(void *arg0) {
    func_800A6480();
    if ((D_800FFC2C != 0) && (D_801027AC & 0x1000)) {
        M2C_FIELD(arg0, s16 *, 0xC) = 2;
    }
}

void func_800A8798(void) {
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A87A0);

void func_800A884C(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x14) >= 0x80) {
        M2C_FIELD(arg0, s16 *, 0x76) = func_800A8B20(func_8003CC1C(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x3C)) + 0x800, M2C_FIELD(arg0, s16 *, 0x76), 0x10);
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A88A8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A8A80);

s16 func_800A8B20(s32 arg0, s16 arg1, s32 arg2) {
    s32 d;

    d = (arg0 & 0xFFF) - (arg1 & 0xFFF);
    if (d < 0) {
        d += 0x1000;
    }
    if (d < 0x800) {
        if (arg2 < d) {
            d = arg2;
        }
    } else {
        d -= 0x1000;
        arg2 = -arg2;
        if (d < arg2) {
            d = arg2;
        }
    }
    return (arg1 + d) & 0xFFF;
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A8B68);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A8CB4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A8E20);

void func_800A9DB4(void) {
    func_80044A68(&D_800FFC34, 1, 0, func_8004656C(0, 0, 0x180, 0x100) & 0xFFFF, 0);
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A9DFC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800A9FF8);

void func_800AA15C(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_SFIELD(arg0, s32 *, 0) = 0x04000000;
    M2C_SFIELD(arg0, s32 *, 4) = 0x65000000;
    M2C_SFIELD(arg0, s32 *, 0xC) = (s32) (arg1 | 0x78400000);
    M2C_SFIELD(arg0, s32 *, 0x10) = (s32) ((arg2 & 0xFFFF) | 0xB0000);
    M2C_SFIELD(arg0, s32 *, 8) = arg3;
    M2C_SFIELD(arg0, s32 *, 0) = (s32) ((M2C_SFIELD(arg0, s32 *, 0) & 0xFF000000) | (M2C_SFIELD(D_80102794, s32 *, 4) & 0xFFFFFF));
    M2C_SFIELD(D_80102794, s32 *, 4) = (s32) ((M2C_SFIELD(D_80102794, s32 *, 4) & 0xFF000000) | ((s32) arg0 & 0xFFFFFF));
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AA1D0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AA44C);

u16 func_800AA574(u16 arg0) {
    s32 r;
    u16 *p;

    r = 0;
    p = D_800DBA64;
    while (arg0 != 0) {
        if (arg0 & 1) {
            r = func_800AA5E4(r, *p);
        }
        arg0 >>= 1;
        p++;
    }
    return r;
}

s32 func_800AA5E4(u16 arg0, u16 arg1) {
    s32 r;
    u16 carry;
    s16 sh;
    u16 d;

    r = 0;
    carry = 0;
    for (sh = 0; sh < 13; sh += 4) {
        carry += ((arg0 >> sh) & 0xF) + ((arg1 >> sh) & 0xF);
        d = carry;
        if (d >= 10) {
            d -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        r |= d << sh;
    }
    return (u16)r;
}

void func_800AA66C(void) {
    SbUnkFFC40 *p;
    s32 i;

    D_800FFD40 = 0;
    p = D_800FFC40;
    for (i = 7; i != -1; i--) {
        p->unk0 = 0;
        p++;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AA69C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AA7FC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AAB88);

void func_800AAE1C(SbRelocHdr *h) {
    SbRelocEnt *e;
    s32 n;
    u32 base;

    if (h->unk4 >= 0) {
        n = h->unk8;
        e = h->ents;
        base = (u32)e >> 2;
        while (--n != -1) {
            e->unk0 += base;
            e->unk8 += base;
            e->unk10 += base;
            e++;
        }
        h->unk4 |= 0x80000000;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AAE98);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AAFE8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AB154);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AB350);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AB5A0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AB7E4);

void func_800ABA64(void *arg0) {
    void (*var_v0)(void *);

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        D_80101190 = M2C_FIELD(arg0, u16 *, 2);
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFD8000;
            M2C_FIELD(arg0, s32 *, 0x6C) = (s32) M2C_FIELD(arg0, s32 *, 0x7C);
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x80);
            func_800A1300(3, 0xF0, 0);
            var_v0 = func_800ABAFC;
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
        } else {
            var_v0 = func_800ABB94;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = var_v0;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ABAFC);

void func_800ABB94(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ABBE0);

void func_800ABCE4(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1300(3, 0xF0, 0);
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ABD74;
        } else {
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ABDFC;
        }
    }
    if ((M2C_FIELD(arg0, s16 *, 4) - 0xEA) == 2) {
        func_800ABE74(arg0);
    }
}

void func_800ABD74(void *arg0) {
    u16 temp_v0;
    u16 temp_v1;

    M2C_FIELD(arg0, s16 *, 0x1E) = (s16) ((s32) -func_80039A74(func_80039A74(M2C_FIELD(arg0, s16 *, 0x84) << 5) >> 4) >> 3);
    temp_v1 = (u16) M2C_FIELD(arg0, s16 *, 0x84);
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v1 + 1);
    if ((s16) temp_v1 >= 0x79) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0 + 1);
        if ((s16) temp_v0 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

void func_800ABDFC(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
    if ((M2C_FIELD(arg0, s16 *, 4) - 0xEA) == 2) {
        func_800ABE74(arg0);
    }
}

void func_800ABE74(void *arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x86);
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_v0 + 1);
    M2C_FIELD(arg0, s16 *, 0x22) = (s16) (func_80039A74(func_80039A74((s32) (temp_v0 << 0x10) >> 0xB) >> 4) >> 3);
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
}

void func_800ABEC8(void *arg0) {
    s16 temp_v1;
    u16 temp_v0;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x84);
    if (temp_v1 != 0) {
        M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v1 + 1);
        if (temp_v1 >= 0x3D) {
            temp_v0 = M2C_FIELD(arg0, u16 *, 0x8A);
            M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0 + 1);
            if ((s16) temp_v0 >= 0x1F) {
                M2C_FIELD(arg0, s8 *, 0) = 0;
            }
        }
    } else if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1300(2, 0x10C, 0);
        }
        M2C_FIELD(arg0, s16 *, 0x84) = 1;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ABF74);

void func_800AC218(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x29) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
            return;
        }
    }
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + M2C_FIELD(arg0, s32 *, 0x6C));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + M2C_FIELD(arg0, s32 *, 0x70));
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) + M2C_FIELD(arg0, s32 *, 0x74));
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) (M2C_FIELD(arg0, s32 *, 0x70) + 0x1000);
}

void func_800AC2A8(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AC2F4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AC458);

void func_800AC518(void *arg0) {
    s32 var_a0;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
            return;
        }
    }
    temp_v0_3 = M2C_FIELD(arg0, u16 *, 0x86);
    var_a0 = temp_v0_3 & 0x1F;
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_v0_3 + 1);
    if (var_a0 >= 0x11) {
        var_a0 = 0x20 - var_a0;
    }
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (var_a0 << 7);
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AC598);

void func_800AC704(void *arg0) {
    s32 var_a0;
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x86);
    var_a0 = temp_v0 & 0x1F;
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_v0 + 1);
    if (var_a0 >= 0x11) {
        var_a0 = 0x20 - var_a0;
    }
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (var_a0 << 7);
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1300(3, 0x189, 0);
            M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFE0000;
            M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800AC458;
            M2C_FIELD(arg0, s32 *, 0x6C) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 0x7C) >> 1);
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 0x80) >> 1);
            return;
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800AC518;
    }
}

void func_800AC7BC(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1300(2, 0x10C, 0);
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800AC820;
    }
}

void func_800AC820(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AC86C);

void func_800AC950(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x88);
    M2C_FIELD(arg0, u16 *, 0x88) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x79) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
            return;
        }
    }
    temp_v0_3 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0_3 + 1);
    M2C_FIELD(arg0, s16 *, 4) = (s16) (((temp_v0_3 >> 3) & 3) + 0xF0);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + M2C_FIELD(arg0, s32 *, 0x70));
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) (M2C_FIELD(arg0, s32 *, 0x70) - 0x800);
}

void func_800AC9DC(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ACA48;
            func_800A1300(1, 0x10C, 0x7F);
            return;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ACAB8;
    }
}

void func_800ACA48(void *arg0) {
    u16 temp_a0;

    temp_a0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_a0 + 1);
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) + (func_80039A74((s32) (temp_a0 << 0x10) >> 0x11) >> 2));
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    if ((s16) M2C_FIELD(arg0, u16 *, 0x1E) >= 0x481) {
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ACAB8;
    }
}

void func_800ACAB8(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x86);
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ACB04);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ACC24);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ACCFC);

void func_800ACDE4(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

void func_800ACE30(void *arg0) {
    if (D_800DB200 < M2C_FIELD(arg0, s32 *, 0x40)) {
        if (D_800DB1E8 >= 0x201) {
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800ACE88;
            return;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800AD174;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ACE88);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ACF80);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AD068);

void func_800AD174(void *arg0) {
    M2C_UNK *var_v0;

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            var_v0 = &func_800ACCFC;
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
        } else {
            var_v0 = &func_800ACDE4;
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x38) = var_v0;
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AD1BC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AD2C0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AD3F8);

void func_800AD4FC(void *arg0) {
    s16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x84);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v0 - 1);
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            func_800A1300(2, 0xF0, 0);
            M2C_FIELD(arg0, u8 *, 1) = 0U;
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
        }
    } else {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, s16 *, 0x14) = 0;
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AD584);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AD70C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AD8F0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ADA8C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ADC20);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ADCC0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ADDD8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800ADF34);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AE090);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AE1EC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AE348);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AE5E4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AE740);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AEB2C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AEF18);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AF074);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AF1D0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AF32C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AF480);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AF5D4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AF728);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AF87C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AF9D8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AFB34);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AFDE4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800AFF44);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B00A0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B01FC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B035C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B04B8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B072C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0948);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0ACC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0C50);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0DF0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B0F90);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B1134);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B12D8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B15C4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B18B0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B1AE4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B1C5C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B1DD4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B1F4C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B20C4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B223C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B23B4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B27A0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B28F4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B2CE4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B2E5C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B30B0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B3304);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B3558);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B37AC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B3A38);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B3C8C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B3EE0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B4064);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B42B8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B450C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B469C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B482C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B49BC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B4B4C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B4CDC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B4FE4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B5164);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B52E4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B55D0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B5824);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B5B10);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B5D64);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B6050);

void func_800B61C8(void) {
    s32 var_v1;

    var_v1 = D_800DB20C;
    D_800DB1E0 = 0xB;
    if (var_v1 < 0) {
        var_v1 = -var_v1;
    }
    if (var_v1 <= 0x3FFFF) {
        var_v1 = 0x40000;
    }
    D_800DB20C = var_v1;
    func_800A1300(2, 0x10C, 0);
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B6228);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B63E0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B66D8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B6B10);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B6E08);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B6FC0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B72B8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B76F0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B79E8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B7E20);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B8118);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B8550);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B8AC8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B8C80);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B8F78);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B9630);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B9928);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B9B94);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800B9E00);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BA06C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BA2D8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BA544);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BA7B0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BAA1C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BAC88);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BAF30);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BB19C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BB408);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BB580);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BB964);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BBC00);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BBFE4);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BC280);

void func_800BC4EC(void) {
    s32 *p;
    s32 i;

    p = D_80100F34;
    for (i = 0x96; i != -1; i--) {
        *p++ = 0;
    }
    D_80101190 = 0;
}

void func_800BC51C(s16 arg0) {
    s32 first;

    first = 0;
    if (((u8 *)D_80100F34)[arg0] == 0) {
        first = 1;
        ((u8 *)D_80100F34)[arg0] = 1;
    }
    if (D_800DCDC8[arg0] != NULL) {
        D_800DCDC8[arg0](arg0, first);
    }
}

void func_800BC58C(void) {
    s32 var_v0;
    s8 *var_v1;

    var_v1 = &D_800FFDB0;
    var_v0 = 0x1F;
    do {
        *var_v1 = 0;
        var_v0 -= 1;
        var_v1 += 0x8C;
    } while (var_v0 != -1);
    D_80100F30 = 0;
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BC5BC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BCD30);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BCE0C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BCECC);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BD008);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BD144);

void func_800BD280(void) {
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BD288);

void func_800BD3C4(void) {
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BD3CC);

void func_800BD508(void) {
}

void func_800BD510(void) {
}

void func_800BD518(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B18B0();
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BD53C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BD678);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BD7A8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BD908);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BDA64);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BDBC0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BDD1C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BDE78);

void func_800BDFD4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADA8C(arg0, 0, &D_800DC378);
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BE008);

void func_800BE138(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADA8C(arg0, 2, &D_800DC3D8);
    }
}

void func_800BE16C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADA8C(arg0, 3, D_800DC408);
        func_800ADA8C(arg0, 0, D_800DC408 + 3);
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BE1C8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BE2F8);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BE458);

void func_800BE5B4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADA8C(arg0, 2, D_800DC45C);
        func_800ADA8C(arg0, 1, D_800DC45C + 3);
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BE610);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BE740);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BE870);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BE9A0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BEAD0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BEC00);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BED30);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BEE60);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BEF90);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BF0C0);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BF1F0);

void func_800BF320(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 0, D_800DC970);
        func_800AD8F0(arg0, 0x600, 1, D_800DC970 + 3);
    }
}

void func_800BF384(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 0, D_800DC9A0);
        func_800AD8F0(arg0, 0x600, 1, D_800DC9A0 + 3);
    }
}

void func_800BF3E8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 3, &D_800DCA00);
    }
}

void func_800BF420(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 2, &D_800DCA0C);
    }
}

void func_800BF458(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 1, D_800DCA48);
        func_800AD8F0(arg0, 0x600, 0, D_800DCA48 + 3);
    }
}

void func_800BF4BC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 3, &D_800DCA60);
    }
}

void func_800BF4F4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 3, &D_800DCA90);
    }
}

void func_800BF52C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 2, &D_800DCA9C);
    }
}

void func_800BF564(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD8F0(arg0, 0x600, 1, &D_800DCAA8);
    }
}

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BF59C);

INCLUDE_ASM("../asm/us/snobo/nonmatchings/text", func_800BF670);

void func_800BF744(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800A1300(4, 0xCD, 0);
    }
}

void func_800BF770(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 0, D_800DCB08);
        func_800AD584(arg0, 0xA00, 2, D_800DCB08 + 4);
        func_800AD584(arg0, 0x400, 3, D_800DCB08 + 8);
    }
}

void func_800BF7E8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0x800, 0, D_800DCB38);
        func_800AD584(arg0, 0x300, 2, D_800DCB38 + 4);
    }
}

void func_800BF84C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0xC00, 2, D_800DCB58);
        func_800AD584(arg0, 0, 1, D_800DCB58 + 4);
        func_800AD584(arg0, 0x700, 2, D_800DCB58 + 8);
    }
}

void func_800BF8C4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0x600, 2, D_800DCB88);
        func_800AD584(arg0, 0xC00, 2, D_800DCB88 + 4);
    }
}

void func_800BF928(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0x600, 2, D_800DCBA8);
        func_800AD584(arg0, 0xC00, 2, D_800DCBA8 + 4);
    }
}

void func_800BF98C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0xE00, 0, D_800DCBC8);
        func_800AD584(arg0, 0x700, 0, D_800DCBC8 + 4);
        func_800AD584(arg0, 0x100, 0, D_800DCBC8 + 6);
        func_800AD584(arg0, 0x300, 0, D_800DCBC8 + 8);
    }
}

void func_800BFA18(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 2, D_800DCC08);
        func_800AD584(arg0, 0x800, 2, D_800DCC08 + 4);
        func_800AD584(arg0, 0x400, 3, D_800DCC08 + 8);
    }
}

void func_800BFA90(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 0, D_800DCC38);
        func_800AD584(arg0, 0x100, 2, D_800DCC38 + 4);
    }
}

void func_800BFAF4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 0, D_800DCC58);
        func_800AD584(arg0, 0x500, 2, D_800DCC58 + 4);
    }
}

void func_800BFB58(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 0, D_800DCC78);
        func_800AD584(arg0, 0, 3, D_800DCC78 + 4);
    }
}

void func_800BFBBC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 2, D_800DCC98);
        func_800AD584(arg0, 0xC00, 0, D_800DCC98 + 4);
    }
}

void func_800BFC20(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0x300, 2, D_800DCCB8);
        func_800AD584(arg0, 0xF00, 3, D_800DCCB8 + 4);
    }
}

void func_800BFC84(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 0, D_800DCCD8);
        func_800AD584(arg0, 0x400, 0, D_800DCCD8 + 4);
        func_800AD584(arg0, 0x800, 2, D_800DCCD8 + 8);
        func_800AD584(arg0, 0xC00, 2, D_800DCCD8 + 12);
    }
}

void func_800BFD10(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AD584(arg0, 0, 1, D_800DCD18);
        func_800AD584(arg0, 0x200, 2, D_800DCD18 + 4);
    }
}

INCLUDE_RODATA("../asm/us/snobo/nonmatchings/text", D_800A0000);
