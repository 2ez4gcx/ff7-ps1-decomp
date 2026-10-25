#include "common.h"
#include "magic_tsol/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B06EC();
    return &D_801B0760;
}

void func_801B007C(void) {
    MgMat out;
    MgTask *t;
    s32 *p;
    s32 i;
    s32 r; s32 *base;

    t = &D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801CDBCC, &D_801CDBEC);
    i = 0;
    do {
        base = D_801B5B5C; p = &base[i];
        if (*p != 0) {
            if (*p == 1) {
                r = func_80042DA8();
                if (r != r / 2 * 2 || t->unk2 >= 3) {
                    i++;
                    *p = (func_80042DA8() % 6 + 1) << 5;
                    continue;
                }
            } else {
                D_801B5B50[0] = *p & 0xF0;
                D_801B5B8C.t[0] = D_801B5B74[i];
                D_801B5B8C.t[1] = -0x32;
                D_801B5B8C.t[2] = -0x6E;
                func_8003A63C(&D_801CDBEC, &D_801B5B8C, &out);
                func_8003B48C(&D_801B5B8C);
                func_8003B51C(&out);
                D_801CDBAC = func_800D6260(&D_801B5B50[-4], D_801517C0 + 0x70, 0xC, D_801CDBAC);
                if (D_80062D98 == 0) {
                    *p += 1;
                }
                if ((*p & 0xF) >= 2) {
                    *p = 0;
                }
            }
        }
        i++;
    } while (i < 6);
    if (t->unk2 >= 4) {
        t->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        t->unk2++;
    }
}

void func_801B02AC(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 bit;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 4) {
            q = func_800D4FA8(1);
            *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
            q->unk10 = p->unkA;
        }
        if ((u16)(p->unk2 - 0x1A) < 0xD) {
            D_80153D20.vx += p->unkC;
            D_80153D20.vz += p->unk10;
            D_801CDBE0.vx = D_80153D20.vx;
            D_801CDBE0.vy = 0;
            D_801CDBE0.vz = D_80153D20.vz;
        }
        if (p->unk2 == 0x1C || p->unk2 == 0x21 || p->unk2 == 0x26) {
            func_800D55F4(0x20, func_800D56A8(&D_80153D20), 0xCC);
        }
        if (p->unk2 == 0x3A) {
            func_800BBEAC(&func_801B007C);
            func_800D55F4(0x20, func_800D56A8(&D_80153D20), 0x1C6);
        }
        if (p->unk2 == 0x46) {
            func_800D4FA8(2);
        }
        if (p->unk2 == 0x3C) {
            for (i = 0, bit = 1; i < 10; i++) {
                if (D_801CDBB4 & (bit << i)) {
                    func_800D5774(i);
                    func_800D4D4C(i, (func_80042DA8() % 2 << 8) | 0x29);
                }
            }
        }
        if (p->unk2 >= 0x4B) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_tsol/nonmatchings/text", func_801B04EC);

INCLUDE_RODATA("../asm/us/magic_tsol/nonmatchings/text", D_801B0000);

s32 func_801B06EC(arg0, arg1) {
    s32 v;

    D_801CDBB0 = &D_80162978[func_800BBEAC(D_801B0000)];
    v = func_800BBEAC(func_801B04EC);
    D_801CDBB4 = arg0;
    D_801CDBB8 = arg1;
    return v;
}
