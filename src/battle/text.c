#include "common.h"
#include "battle/decls.h"

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A1158);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A1798);

void func_800A22C0(s32 arg0) {
    s32 i;

    if (D_800E7A38 != -1) {
        if (D_800E7A38 == arg0) {
            return;
        }
        for (i = 0; i < 0x40; i++) {
            if (D_800F6934[i].a == 6 && D_800F6934[i].c == D_800E7A38) {
                break;
            }
        }
        if (i == 0x40) {
            D_800F5BE2[D_800E7A38][0] += 1;
            func_800A56B0(D_800E7A38);
            func_800A7254(0, D_800E7A38, 0, 0);
        }
    }
    D_800E7A38 = arg0;
}

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

void func_800A2894(void) {
    s32 i;
    u16 *p;

    i = 0;
    p = &D_800F7DE2;
    for (; i < 3; i++) {
        if (D_800F840C[i].a == 0x1E61 && !(D_800F5BE0[i].b[0] & 0x80)) {
            if ((*p)++ < 0x40) {
                D_800F5BE0[i].b[0] |= 0x80;
                func_800A3E98(i, 1, 1, 0, 0);
            }
        }
    }
}

void func_800A2974(void) {
    u16 sp10;
    s32 a;
    s32 b;
    s32 r;
    s32 d;
    s32 t;
    BtlB0F04 *p;

    sp10 = 0;
    a = M2C_FIELD(D_80063014, s32 *, 0x20C);
    b = M2C_FIELD(D_80063014, s32 *, 0x208);
    r = 0x31;
    if (a != -1) {
        p = (BtlB0F04 *)&D_800F5F44[a];
        if (func_800B0F04(p, 0x80, 1, 0) != 0xFFFF) {
            if (!(D_800F5BE1[b].a & 1)) {
                t = M2C_FIELD(D_80063014, s32 *, 0x254) - 0x28;
                d = M2C_FIELD(D_80063014, s32 *, 4) - t;
                if (D_800F5BC5[M2C_FIELD(D_80063014, s32 *, 0) * 0x44] == 4 && d < 0x64) {
                    d = 0x64;
                }
                sp10 = func_800B0F04(p, 0x80, 0, (d << 9) / 100);
                if (sp10 == 0xFFFF) {
                    r = 0x30;
                } else {
                    func_800A7254(0, M2C_FIELD(D_80063014, s32 *, 0), 3, sp10);
                    r = 0x2F;
                    D_800F5BE1[b].a |= 1;
                }
            }
        }
    }
    func_800B0FFC(M2C_FIELD(D_80063014, s32 *, 0), r, 1, &sp10);
}

void func_800A2B28(s32 arg0) {
    if (arg0 & 1) {
        M2C_FIELD(D_80063014, s32 *, 0x90) |= 0x80;
    }
    if (arg0 & 2) {
        M2C_FIELD(D_80063014, s32 *, 0x90) |= 0x40;
    }
    if (arg0 & 8) {
        M2C_FIELD(D_80063014, s32 *, 0x90) |= 4;
    }
    if (arg0 & 0x10) {
        M2C_FIELD(D_80063014, s32 *, 0x90) |= 0x800;
    }
    if (arg0 & 0xE0) {
        M2C_FIELD(D_80063014, s32 *, 0xE8) = (arg0 >> 5) * 10;
    }
}

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A0098);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A0108);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A010C);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", jtbl_800A0120);
