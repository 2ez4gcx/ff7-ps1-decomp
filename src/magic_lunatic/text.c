#include "common.h"
#include "magic_lunatic/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B0D44();
    return &D_801C96E0;
}

void func_801B007C(void) {
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
    base = D_801E23EC[e->unk14];
    frame = D_801CA3C8;
    do {
        p = &base[i];
        if (p->unk0 != 0) {
            frame[0] = p->unk2;
            func_800D4368(&p->unk4, p->unk16, -(p->unk16 >> 3));
            D_801E23D8 = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801E23D8);
            if (D_80062D98 == 0) {
                p->unk4 += p->unkC;
                p->unk6 += p->unkE;
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
    } while (i < 0x64);
    if (D_80062D98 == 0) {
        if (e->unk2 >= 0x23) {
            e->unk0 = -1;
        }
        if (e->unk2 < 0x13) {
            s = 0xDC0;
            i = 0;
            do {
                for (j = 0; j < 0x64; j++) {
                    if (base[j].unk0 == 0) {
                        break;
                    }
                }
                if (j >= 0x64) {
                    break;
                }
                p = (MgPart18 *)(j * 0x18 + (s32)base);
                p->unk0 = 1;
                p->unk2 = 0;
                r = func_80042DA8();
                a = r / 0x1000;
                a = r - a * 0x1000;
                b = ((s16)(e->unkC / 3) << 1) + func_80042DA8() % 100;
                p->unk4 = e->unk4 + ((func_80039B40(a) * b) >> 12);
                p->unk6 = e->unk6;
                p->unk8 = e->unk8 + ((func_80039A74(a) * b) >> 12);
                b = func_80042DA8() % 90 + 0x5A;
                p->unkC = (func_80039B40(a) * b) >> 12;
                p->unkE = -(func_80042DA8() % 10 + 0x14);
                p->unk10 = (func_80039A74(a) * b) >> 12;
                a = func_80042DA8() % 2816 + 0xE00;
                p->unk16 = (s * a) >> 12;
                i++;
            } while (i < 5);
        }
        e->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_lunatic/nonmatchings/text", func_801B0484);

INCLUDE_ASM("../asm/us/magic_lunatic/nonmatchings/text", func_801B05F0);

INCLUDE_ASM("../asm/us/magic_lunatic/nonmatchings/text", func_801B0798);

INCLUDE_ASM("../asm/us/magic_lunatic/nonmatchings/text", func_801B0944);

INCLUDE_ASM("../asm/us/magic_lunatic/nonmatchings/text", func_801B0B28);

INCLUDE_RODATA("../asm/us/magic_lunatic/nonmatchings/text", D_801B0000);

void func_801B0D44(mask, arg1) {
    s32 i;
    s32 n;

    D_801E23DC = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B0E10, 0, 0, 0);
    D_801E23E0 = mask;
    for (i = 0, n = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            n++;
            if (n == 1) {
                D_801E23E4 = i;
            }
        }
    }
    D_801E23E8 = arg1;
    func_800BBEAC(&func_801B0B28);
}
