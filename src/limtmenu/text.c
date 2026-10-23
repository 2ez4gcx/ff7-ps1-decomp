#include "common.h"
#include "limtmenu/decls.h"

void func_801D002C(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_801D006C(void) {
    func_80026448(D_801D235C, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 1, 1, 0);
    func_80026448(D_801D235C + 0x12, 0, 0, 2, 1, 0, 0, 2, 1, 0, 0, 1, 0, 0);
    D_801D2320 = 1;
    D_801D2410 = D_80062F6C;
}

void func_801D013C(s32 arg0) {
    s16 rect[4];
    u8 id;
    u8 r;
    u8 g;
    u8 b;
    s32 k;
    s32 v;

    func_80020B68(0x3E, 0xE, D_801D2410);
    func_8001CF3C(0xA, 9, 0x30, 0x30, 0, D_801D2410 * 0x30 + 0x38, 0x30, 0x30, D_801D2410 + 0xD, 0);
    func_80026F44(0xBA, 0xE, D_80049314, 7);
    id = D_800491D0[D_8009CBDC[D_801D2410]];
    if (D_8009C747[id * 0x84] == 0xFF) {
        k = ((arg0 >> 1) & 7) * 3;
        r = D_801D2344[k];
        g = D_801D2345[k];
        b = D_801D2346[k];
    } else {
        v = D_8009C757[id * 0x84];
        if (v & 0x10) {
            r = D_801D2344[0];
            g = D_801D2345[0];
            b = D_801D2346[0];
        } else {
            r = 0x80;
            if (v & 0x20) {
                r = D_801D234A;
                g = D_801D234B;
                b = D_801D234C;
            } else {
                g = 0x20;
                b = 0x50;
            }
        }
    }
    v = D_8009C747[id * 0x84] * 0x3D / 256;
    func_800285AC(0xCB, 0x1A, v, 6, r, g, b);
    func_80028CA0(0xCA, 0x19, 0x88, 8, 0x40, 8, 7, 0);
    func_80028E00(0xFA, 0x10, D_8009C746[D_800491D0[D_8009CBDC[D_801D2410]] * 0x84], 1, 7);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0x100;
    rect[3] = 0x100;
    func_80026A34(0, 1, 0x3F, (s32)rect);
    func_80026F44(0xCA, 0x2B, D_801D21DC, 7);
    func_80026F44(0xFA, 0x2B, D_801D21DC + 0x24, 7);
}

INCLUDE_ASM("../asm/us/limtmenu/nonmatchings/text", func_801D042C);

void func_801D11A0(void) {
}

s32 func_801D11A8(void) {
    s32 i;
    s32 j;
    s32 id;
    s32 base;
    s32 k;
    u8 c;

    for (i = 0; i < 3; i++) {
        c = D_8009CBDC[i];
        if (c != 0xFF) {
            id = D_800491D0[c];
            base = (D_8009C738[id][0xE] - 1) * 3;
            for (j = 0; j < 3; j++) {
                k = base + j;
                D_8009D8F8[i].a[j] = func_80015AFC(id, k);
                D_8009D8F8[i].b[j] = D_801D1324[func_80015AFC(id, k)];
            }
        }
    }
}
