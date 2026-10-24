#include "common.h"
#include "magic_knights/decls.h"

void func_801B0050(void) {
    func_801BE87C();
}

MgMat *func_801B0070(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EC474.m[0][0] = D_801EC474.m[1][1] = D_801EC474.m[2][2] = scale;
    func_8003B48C(&D_801EE9AC);
    func_8003B51C(&D_801EE9AC);
    func_8003BC6C(v, (MgVec *)D_801EC474.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EC474.t, &n);
        D_801EC474.t[0] += (dist * n.vx) >> 12;
        D_801EC474.t[1] += (dist * n.vy) >> 12;
        D_801EC474.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EC474);
    func_8003B51C(&D_801EC474);
    return &D_801EC474;
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B018C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B0264);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B02E8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B0DA8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B1244);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B15E8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B1C30);

s32 func_801B1E40(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801FA76E[-v];
    }
    return v;
}

s32 func_801B1E7C(s32 a, s32 b) {
    s32 i;
    s32 n;
    s32 orig;

    orig = a;
    if (b > 0) {
        n = b >> 8;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
    } else if (b < 0) {
        b = -b;
        n = b >> 8;
        a = 0x1000 - a;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
        a = 0x1000 - a;
    } else {
        return a;
    }
    n = (b & 0xFF) + 1;
    a = (a * n + orig * (0x100 - n)) >> 8;
    return a;
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B1F74);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B2048);

void func_801B3154(s32 arg0, s32 arg1, s16 arg2) {
    D_8016207C = &func_801B2048;
    D_801635D8 = 0;
    D_801635E4 = arg0;
    D_801635E8 = arg1;
    D_801635EC = arg2;
    D_80162080 += 1;
}

void func_801B31A0(void) {
    MgTask *p;
    s32 t;
    s32 d;
    s32 v;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        d = p->unk6;
        if (t < d) {
            d = (t << 12) / d;
            v = (p->unk4 * d) >> 12;
        } else {
            t -= d;
            if (t < p->unk8) {
                v = p->unk4;
            } else {
                t -= p->unk8;
                d = p->unkA;
                if (t >= d) {
                    p->unk0 = -1;
                    D_800FA666[0] = 0;
                    return;
                }
                d = (t << 12) / d;
                v = (p->unk4 * (0x1000 - d)) >> 12;
            }
        }
        D_800FA666[0] = (p->unk2 & 1) ? v : -v;
        p->unk2++;
    }
}

void func_801B32DC(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B31A0)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

void func_801B3350(void) {
    MgMat m;

    D_801EC868 = D_801EC334;
    D_801EC858 = D_801EC334;
    if (D_801EC32E != 0) {
        D_801EC874 = D_801EC350;
    } else {
        D_801EC874 = -D_801EC350;
    }
    func_8003A63C(&D_801EC838, &D_801EC858, &m);
    func_801B1C30(&m, &D_801EC878);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B33E0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B3748);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B3890);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B3DB0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B40F4);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4198);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B440C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4694);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4B04);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4B70);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4BF8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4E78);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5670);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B56D4);

void func_801B5B24(void *arg0) {
    s32 temp_a1;
    s32 temp_v0;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0xBA0);
    if (temp_a1 != -1) {
        temp_v0 = func_800D376C(arg0 + 0x40, temp_a1, M2C_FIELD(arg0, s16 *, 0xBA4), M2C_FIELD(arg0, s32 *, 0xB9C));
        M2C_FIELD(arg0, s32 *, 0xBA0) = temp_v0;
        if (temp_v0 == 0) {
            M2C_FIELD(arg0, s32 *, 0xBA0) = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5B7C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5C5C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5E4C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B5F0C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B603C);

void func_801B6248(void) {
    MgTask *temp_s0;
    s16 temp_v1;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        temp_v1 = temp_s0->unk2;
        if (temp_v1 == 0) {
            func_800D5138(1);
        } else if (temp_v1 == 1) {
            func_800D51D4(7);
            temp_s0->unk0 = -1;
        }
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

void func_801B62D4(void *arg0) {
    M2C_UNK sp10;

    func_801B0264(arg0 + ((M2C_FIELD(arg0, s16 *, 0xBB0) * 0x34) + 0x40), &sp10);
    func_801B603C(&sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B631C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B63E4);

void func_801B6624(s32 arg0, void *arg1) {
    MgTask *temp_v0;

    temp_v0 = &D_80162978[func_800BBEAC(&func_801B63E4)];
    temp_v0->unk4 = (s16) M2C_FIELD(arg1, u16 *, 0);
    temp_v0->unk6 = (s16) M2C_FIELD(arg1, u16 *, 2);
    temp_v0->unk8 = (s16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(temp_v0, s32 *, 0xC) = arg0;
}

void func_801B6690(s32 arg0) {
    func_801B6624((s32)&D_801EC954, &D_801EE9D8[arg0]);
}

void func_801B66C4(void) {
    MgTask *p;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            for (i = 0; i < 10; i++) {
                if ((D_801EE9CC >> i) & 1) {
                    func_801B018C(i, D_8015190F[i][0], &D_801EE9D8[i]);
                }
            }
        }
        func_800D5444(D_801EE9CC, 0, 0, (M2C_UNK *)func_801B6690);
        p->unk2++;
        if (p->unk2 > 0) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B67C4);

void func_801B6B78(s32 arg0) {
    func_801B6624((s32)&D_801EC98C, &D_801EE9D8[arg0]);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B6BAC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B6CAC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B6F9C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B7090);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B72AC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B7498);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B786C);

void func_801B7C28(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624(&D_801ECA58, sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B7C84);

void func_801B8014(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624(&D_801ECA90, sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8070);

void func_801B831C(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624((s32)&D_801ECAC8, sp10);
    func_801B6624((s32)&D_801ECAE8, sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8388);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B85F8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8744);

void func_801B8924(void) {
    MgTask *temp_s0;
    MgTask *temp_v0;
    s16 temp_s1;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 == 0) {
            func_800BBEAC(&func_801B85F8);
        }
        if (temp_s0->unk2 == 0xA) {
            temp_v0 = &D_80162978[func_800BBEAC(&func_801B8744)];
            temp_v0->unk10 = 0;
            temp_v0->unkE = 0;
            temp_v0->unkC = 0;
        }
        temp_s1 = temp_s0->unk2;
        if (temp_s1 == 0x14) {
            func_801B5E4C();
            if (temp_s0->unk2 == temp_s1) {
                temp_s0->unk0 = -1;
            }
        }
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8A00);

void func_801B8D7C(s32 arg0) {
    func_801B6624((s32)&D_801ECB80, &D_801EE9D8[arg0]);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8DB0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B8EB0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B91C8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9408);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9700);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9834);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9AA0);

void func_801B9DF0(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624(&D_801ECC40, sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B9E4C);

void func_801BA230(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624((s32)&D_801ECC94, sp10);
    func_801B6624((s32)&D_801ECCB4, sp10);
}

void func_801BA29C(void) {
    func_801B6624(&D_801ECCD4, &D_801ECCF4);
    func_800D5444(D_801EE9CC, 0, 0, &func_801BA230);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BA2E8);

void func_801BA598(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624((s32)&D_801ECD14, sp10);
    func_801B6624((s32)&D_801ECD34, sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BA604);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BA964);

void func_801BAAFC(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624(&D_801ECDA4, sp10);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BAB58);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BAD78);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BAF80);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB270);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB500);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB548);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB6EC);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BB8C4);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BBA64);

void *func_801BBC20(void *arg0, s32 arg1, void *arg2) {
    void *temp_s2;

    M2C_FIELD(arg2, s32 *, 0) = 0x04000000;
    M2C_FIELD(arg2, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(arg2, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(arg2, u8 *, 0xC) = (u8) M2C_FIELD(arg0, u8 *, 4);
    M2C_FIELD(arg2, u8 *, 0xD) = (u8) M2C_FIELD(arg0, u8 *, 6);
    M2C_FIELD(arg2, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x12);
    M2C_FIELD(arg2, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 8);
    func_80046794(arg1, (s32) arg2);
    temp_s2 = arg2 + 0x14;
    func_80044A68(temp_s2, 0, 1, (s32) M2C_FIELD(arg0, u16 *, 0x10), 0);
    func_80046794(arg1, (s32) temp_s2);
    return arg2 + 0x20;
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BBCE0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BBEC8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC0E0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC334);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC65C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC6BC);

void func_801BC71C(void) {
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    func_801BB500(&D_801ECFE0);
    func_800BBEAC(&func_801BB6EC);
    temp_s0->unk0 = -1;
}

void func_801BC778(void) {
    MgTask *temp_s0;
    MgTask *temp_v0;
    s16 temp_v1;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        temp_v1 = temp_s0->unk2;
        if (temp_v1 == 0) {
            temp_v0 = &D_80162978[func_800BBEAC(&func_801BBCE0)];
            temp_v0->unk4 = 0x25;
            temp_v0->unk6 = 0x73;
            temp_v0->unk8 = 0x6C;
        } else if (temp_v1 == 0x25) {
            func_801BB500(&D_801ED014);
            temp_s0->unk0 = -1;
        }
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

void func_801BC838(void) {
    MgTask *temp_s0;
    MgTask *temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    func_800BBEAC(&func_801BC334);
    func_801BB500(&D_801ED07C);
    temp_v0 = &D_80162978[func_800BBEAC(&func_801BC0E0)];
    M2C_FIELD(temp_v0, M2C_UNK **, 0x14) = &D_801ED0B0;
    temp_v0->unk6 = -0x25;
    temp_v0->unk4 = 0;
    temp_v0->unk8 = 0x200;
    temp_s0->unk0 = -1;
}

void func_801BC8D4(void) {
    MgTask *temp_s0;
    MgTask *temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    temp_v0 = &D_80162978[func_800BBEAC(&func_801BC0E0)];
    M2C_FIELD(temp_v0, M2C_UNK **, 0x14) = &D_801ED0C8;
    temp_v0->unk6 = -0x25;
    temp_v0->unk4 = 0;
    temp_v0->unk8 = 0x200;
    temp_s0->unk0 = -1;
}

void func_801BC950(void) {
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    func_800BBEAC(&func_801BBA64);
    temp_s0->unk0 = -1;
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BC99C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BCB04);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BCF1C);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD080);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD2D0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD718);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD758);

void func_801BD7FC(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *temp_v0;

    temp_v0 = &D_80162978[func_800BBEAC(&func_801BD758)];
    temp_v0->unk0 = arg0;
    temp_v0->unk4 = arg1;
    temp_v0->unk6 = arg2;
    temp_v0->unk8 = arg3;
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD870);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BE87C);
