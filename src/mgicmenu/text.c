#include "common.h"
#include "mgicmenu/decls.h"

void func_801D0124(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_801D0164(void) {
    s32 i;
    s32 j;
    u8 (*rows)[0x440];
    u8 *p;

    func_80026448(D_801D2A7C, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0);
    func_80026448(D_801D2A7C + 0x12, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0);
    func_80026448(D_801D2A7C + 0x24, 0, 0, 3, 7, 0, 0, 3, 0x12, 0, 0, 2, 0, 0);
    func_80026448(D_801D2A7C + 0x36, 0, 0, 2, 7, 0, 0, 2, 8, 0, 0, 2, 0, 0);
    func_80026448(D_801D2A7C + 0x48, 0, 0, 2, 7, 0, 0, 2, 0xC, 0, 0, 2, 0, 0);
    D_801D2930 = 0;
    D_801D2AE8 = D_80062F6C;
    i = 0;
    do {
        j = 0;
        rows = (u8 (*)[0x440])D_8009D954;
        do {
            p = rows[i] + j * 8;
            if (p[0] != 0xFF && p[2] != 0 && (p[5] & 0xC) != 0xC) {
                p[2] = 0;
            }
            j++;
        } while (j < 0x38);
        i++;
    } while (i < 3);
}

s32 func_801D0378(s32 arg0) {
    return *(s16 *)((u8 *)&D_8009D85E + arg0 * 0x440) == D_8009D85C[arg0].hp;
}

s32 func_801D03B4(s32 arg0) {
    return *(s16 *)((u8 *)&D_8009D862 + arg0 * 0x440) == D_8009D860[arg0].hp;
}

void func_801D03F0(void) {
    s16 rect[4];

    func_80020B68(0x3E, 0x1C, D_801D2AE8);
    func_8001CF3C(0xA, 0x17, 0x30, 0x30, 0, D_801D2AE8 * 0x30 + 0x38, 0x30, 0x30, D_801D2AE8 + 0xD, 0);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0x100;
    rect[3] = 0x100;
    func_80026A34(0, 1, 0x7F, (s32)rect);
}

INCLUDE_ASM("../asm/us/mgicmenu/nonmatchings/text", func_801D0490);

void func_801D2928(void) {
}
