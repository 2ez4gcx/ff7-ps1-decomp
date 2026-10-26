#include "common.h"
#include "magic_garyu/decls.h"

M2C_UNK *func_801B0060(void) {
    func_801B36B0();
    return &D_801D48D8;
}

M2C_UNK *func_801B0088(void) {
    func_801B3780();
    return &D_801D48D8;
}

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B00B0);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B02B0);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B0480);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B0808);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B0C9C);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B12FC);

void func_801B1400(void) {
    MgTask *e;
    u16 *q;
    u16 *p0;
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 r;
    s32 s;
    s32 n;
    s32 u;

    e = &D_801621F0[D_801590D4];
    for (i = 0; i < 0x8C; i++) {
        if (D_801D90B0[i].unk0 != 0) {
            D_801D62BC[0] = D_801D90B0[i].unk2 << 1;
            func_800D4368(&D_801D90B0[i].unk4, D_801D90B0[i].unk16, -(D_801D90B0[i].unk16 >> 3));
            D_801D62EC = func_800D4D90(&D_801D62BC[-4], D_801517C0 + 0x70, 0xC, D_801D62EC);
            if (D_80062D98 == 0) {
                D_801D90B0[i].unk4 += D_801D90B0[i].unkC;
                D_801D90B0[i].unk8 += D_801D90B0[i].unk10;
                D_801D90B0[i].unkC -= D_801D90B0[i].unkC >> 3;
                D_801D90B0[i].unk10 -= D_801D90B0[i].unk10 >> 3;
                if (D_801D90B0[i].unk2 >= 7) {
                    D_801D90B0[i].unk0 = 0;
                }
                D_801D90B0[i].unk2++;
            }
        }
    }
    if (D_80062D98 == 0) {
        if (e->unk2 >= 0x4B) {
            e->unk0 = -1;
        }
        if (e->unk2 < 0x41) {
            p0 = &D_801D9DD6;
            s = (s16)((s16)p0[0] / 3) << 4;
            i = 0;
            q = &D_801D9DD6;
            do {
                for (j = 0; j < 0x8C; j++) {
                    if (D_801D90B0[j].unk0 == 0) {
                        break;
                    }
                }
                if (j >= 0x8C) {
                    break;
                }
                D_801D90B0[j].unk0 = 1;
                D_801D90B0[j].unk2 = 0;
                r = func_80042DA8();
                a = r / 0x1000;
                a = r - a * 0x1000;
                b = func_80042DA8();
                n = (s16)q[0];
                b = n + b % (n >> 2);
                D_801D90B0[j].unk4 = q[-3] + ((func_80039B40(a) * b) >> 12);
                D_801D90B0[j].unk6 = 0;
                D_801D90B0[j].unk8 = q[-1] - ((func_80039A74(a) * b) >> 12);
                i++;
                u = 0x3C;
                b = func_80042DA8() % 50 + (e->unk2 * 8 + u);
                D_801D90B0[j].unkC = (func_80039B40(a) * b) >> 12;
                D_801D90B0[j].unk10 = -((func_80039A74(a) * b) >> 12);
                u = 0x800;
                a = func_80042DA8() % 2560 + (e->unk2 * 8 + u);
                D_801D90B0[j].unk16 = (s * a) >> 12;
            } while (i < 9);
        }
        e->unk2++;
    }
}

void func_801B18DC(void) {
    u8 pad[8];
    MgTask *e;
    MgPart18 *base;
    MgPart18 *p;
    u16 *frame;
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 r;
    s32 s;

    i = 0;
    e = &D_80162978[D_8015169C];
    base = D_801D63B0[e->unk1C];
    frame = D_801D62C8;
    do {
        p = &base[i];
        if (p->unk0 != 0) {
            frame[0] = p->unk2;
            func_800D4368(&p->unk4, p->unk16, -(p->unk16 >> 3));
            D_801D62EC = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801D62EC);
            if (D_80062D98 == 0) {
                p->unk4 += p->unkC;
                p->unk8 += p->unk10;
                p->unkC -= p->unkC >> 3;
                p->unk10 -= p->unk10 >> 3;
                if (p->unk2 >= 0xF) {
                    p->unk0 = 0;
                }
                p->unk2++;
            }
        }
        i++;
    } while (i < 0x30);
    if (D_80062D98 == 0) {
        if (e->unk2 >= 0x14) {
            e->unk0 = -1;
        }
        if (e->unk2 < e->unk18) {
            i = 0;
            s = e->unk10 * 0x10;
            if (e->unk1A > 0) {
                do {
                    for (j = 0; j < 0x30; j++) {
                        if (base[j].unk0 == 0) {
                            break;
                        }
                    }
                    if (j >= 0x30) {
                        break;
                    }
                    p = (MgPart18 *)(j * 0x18 + (s32)base);
                    p->unk0 = 1;
                    p->unk2 = 0;
                    r = func_80042DA8();
                    a = r / 0x1000;
                    a = r - a * 0x1000;
                    b = e->unk14 + func_80042DA8() % e->unk16;
                    p->unk4 = e->unk4 + ((func_80039B40(a) * b) >> 12);
                    p->unk6 = e->unk6;
                    p->unk8 = e->unk8 - ((func_80039A74(a) * b) >> 12);
                    b = e->unkC + func_80042DA8() % e->unkE + (e->unk14 >> 4);
                    p->unkC = (func_80039B40(a) * b) >> 12;
                    p->unk10 = -((func_80039A74(a) * b) >> 12);
                    a = func_80042DA8() % 2816 + 0x600;
                    p->unk16 = (s * a) >> 12;
                    i++;
                } while (i < e->unk1A);
            }
        }
        e->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B1C9C);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B2654);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B27B0);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B2918);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B2AF4);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B2D34);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B3434);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B35F0);

void func_801B3654(void) {
    s32 var_v1;

    if (D_800F8368 != 0) {
        var_v1 = D_801D62E8 + 0xE000;
    } else {
        var_v1 = D_801D62E8;
    }
    D_801D62EC = var_v1;
    if (D_801D9F90 < 0) {
        *D_801D62F0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B36B0);

void func_801B3780(arg0, arg1) {
    D_80162994[func_800BBEAC((void *)func_801B35F0)].unk0 = 0x80;
    D_801D9F90 &= 0xBFFFFFFF;
    if (arg0 == (1 << arg1)) {
        D_801D9F90 |= 0x20000000;
    }
    D_801D62F4 = arg0;
    D_801D62F8 = arg1;
}

INCLUDE_RODATA("../asm/us/magic_garyu/nonmatchings/text", D_801B0000);
