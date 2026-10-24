#include "common.h"
#include "magic_thundera/decls.h"

void func_801B0000(void) {
    func_801B08F4();
}

INCLUDE_ASM("../asm/us/magic_thundera/nonmatchings/text", func_801B0020);

void func_801B01A0(void) {
    MgObj20 *temp_s0;
    s16 temp_v0_2;
    s8 temp_v0;

    *(M2C_UNK **)0x1F800000 = &D_801B097C;
    *(s16 *)0x1F800008 = 0;
    temp_s0 = &D_80162978[D_8015169C];
    temp_v0 = ~(M2C_FIELD(temp_s0, u8 *, 2) << 6);
    *(s8 *)0x1F800007 = 0x2C;
    *(s8 *)0x1F800006 = temp_v0;
    *(s8 *)0x1F800005 = temp_v0;
    *(s8 *)0x1F800004 = temp_v0;
    func_800D4368(&temp_s0->unk4, 0x2000, M2C_FIELD(temp_s0, s16 *, 0x14));
    D_801E90EC = func_800D4D90(0x1F800000, D_801517C0 + 0x70, 0xC, D_801E90EC);
    if (D_80062D98 == 0) {
        temp_v0_2 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0_2;
        if (temp_v0_2 == 4) {
            temp_s0->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_thundera/nonmatchings/text", func_801B028C);

INCLUDE_ASM("../asm/us/magic_thundera/nonmatchings/text", func_801B0348);

INCLUDE_ASM("../asm/us/magic_thundera/nonmatchings/text", func_801B04D8);

INCLUDE_ASM("../asm/us/magic_thundera/nonmatchings/text", func_801B07F0);

void func_801B0894(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E90EC = D_801C90EC + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_thundera/nonmatchings/text", func_801B08F4);
