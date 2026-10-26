#include "common.h"
#include "magic_sdust/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B355C();
    return &D_801B7A00;
}

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B007C);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B0148);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B0318);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B04C4);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B05BC);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B0818);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B09AC);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B0DCC);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B1424);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B1ADC);

void func_801B2250(void) {
    MgTask *p;
    u8 *c;
    s32 i;
    s32 j;
    s32 n;
    s32 a;
    s32 b;
    s32 k;
    s32 r;
    s32 col;
    s16 t;
    u16 u;
    u8 pad[8];

    c = D_801B95E4;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 0x78; i++) {
        if (D_801E3224[i].f0 != 0) {
            col = -0x80 - (u8)D_801E3224[i].f2 * 4;
            c[2] = col;
            c[1] = col;
            c[0] = col;
            u = D_801E3224[i].f16;
            func_800D4368(&D_801E3224[i].f4, (s16)u, -((s16)u >> 3));
            D_801E15F8 = func_800D4D90(c - 4, D_801517C0 + 0x70, 0xC, D_801E15F8);
            if (D_80062D98 == 0) {
                D_801E3224[i].f4 += D_801E3224[i].fC;
                D_801E3224[i].f6 += D_801E3224[i].fE;
                D_801E3224[i].f8 += D_801E3224[i].f10;
                if (D_801E3224[i].f6 > 0 || D_801E3224[i].f2 >= 0x1F) {
                    D_801E3224[i].f0 = 0;
                }
                D_801E3224[i].f2++;
            }
        }
    }
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x37) {
            p->unk0 = -1;
        }
        t = p->unk2;
        if (t < 0x19) {
            n = 6 - (t >> 1);
            do {
                i = 0;
            } while (0);
            if (n < 3) {
                n = 3;
            }
            k = 0x1400;
            if (n > 0) {
                do {
                    for (j = 0; j < 0x78; j++) {
                        if (D_801E3224[j].f0 == 0) {
                            break;
                        }
                    }
                    if (j >= 0x78) {
                        break;
                    }
                    D_801E3224[j].f0 = 1;
                    D_801E3224[j].f2 = 0;
                    r = func_80042DA8();
                    a = r / 0x1000;
                    a = r - a * 0x1000;
                    b = func_80042DA8() % 180 + 0x50;
                    D_801E3224[j].f4 = p->unk4 + ((func_80039B40(a) * b) >> 12);
                    D_801E3224[j].f6 = p->unk6 + b;
                    D_801E3224[j].f8 = p->unk8 + ((func_80039A74(a) * b) >> 12);
                    i++;
                    b = func_80042DA8() % 110 + 0x5A;
                    D_801E3224[j].fC = (func_80039B40(a) * b) >> 12;
                    D_801E3224[j].fE = func_80042DA8() % 180 + 0x78;
                    D_801E3224[j].f10 = (func_80039A74(a) * b) >> 12;
                    a = func_80042DA8() % 4608 + 0xA00;
                    D_801E3224[j].f16 = (k * a) >> 12;
                } while (i < n);
            }
        }
        p->unk2++;
    }
}

void func_801B276C(void) {
    MgTask *p;
    u8 *c;
    s32 i;
    s32 j;
    s32 n;
    s32 a;
    s32 b;
    s32 k;
    s32 r;
    s32 col;
    s16 t;
    s16 v;
    u16 u;
    u8 pad[8];

    c = D_801B95F0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 0x78; i++) {
        if (D_801E3224[i].f0 != 0) {
            col = -0x80 - (u8)D_801E3224[i].f2 * 4;
            c[2] = col;
            c[1] = col;
            c[0] = col;
            u = D_801E3224[i].f16;
            func_800D4368(&D_801E3224[i].f4, (s16)u, -((s16)u >> 3));
            D_801E15F8 = func_800D4D90(c - 4, D_801517C0 + 0x70, 0xC, D_801E15F8);
            if (D_80062D98 == 0) {
                D_801E3224[i].f4 += D_801E3224[i].fC;
                D_801E3224[i].f6 += D_801E3224[i].fE;
                D_801E3224[i].f8 += D_801E3224[i].f10;
                v = D_801E3224[i].fE + D_801E3224[i].f12;
                D_801E3224[i].fE = v;
                if (v < 0) {
                    D_801E3224[i].fE = 0;
                } else {
                    D_801E3224[i].f12 -= 1;
                }
                if (D_801E3224[i].f6 > 0 || D_801E3224[i].f2 >= 0x1F) {
                    D_801E3224[i].f0 = 0;
                }
                D_801E3224[i].f2++;
            }
        }
    }
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x37) {
            p->unk0 = -1;
        }
        t = p->unk2;
        if (t < 0x19) {
            n = 6 - (t >> 1);
            do {
                i = 0;
            } while (0);
            if (n < 3) {
                n = 3;
            }
            k = 0x1400;
            if (n > 0) {
                do {
                    for (j = 0; j < 0x78; j++) {
                        if (D_801E3224[j].f0 == 0) {
                            break;
                        }
                    }
                    if (j >= 0x78) {
                        break;
                    }
                    D_801E3224[j].f0 = 1;
                    D_801E3224[j].f2 = 0;
                    r = func_80042DA8();
                    a = r / 0x1000;
                    a = r - a * 0x1000;
                    b = func_80042DA8() % 180 + 0x50;
                    D_801E3224[j].f4 = p->unk4 + ((func_80039B40(a) * b) >> 12);
                    D_801E3224[j].f6 = p->unk6 + b;
                    D_801E3224[j].f8 = p->unk8 + ((func_80039A74(a) * b) >> 12);
                    b = func_80042DA8() % 90 + 0x32;
                    D_801E3224[j].fC = (func_80039B40(a) * b) >> 12;
                    D_801E3224[j].fE = func_80042DA8() % 130 + 0xC8;
                    D_801E3224[j].f10 = (func_80039A74(a) * b) >> 12;
                    D_801E3224[j].f12 = -(func_80042DA8() % 4 + 4);
                    a = func_80042DA8() % 0x1000 + 0x800;
                    i++;
                    D_801E3224[j].f16 = (k * a) >> 12;
                } while (i < n);
            }
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B2D3C);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B2E38);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B2F04);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B3418);

INCLUDE_RODATA("../asm/us/magic_sdust/nonmatchings/text", D_801B0000);

void func_801B355C(arg0) {
    D_801E15FC = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B35D8, 0, 0, 0);
    func_800BBEAC(&func_801B3418);
    D_801E1600 = arg0;
}
