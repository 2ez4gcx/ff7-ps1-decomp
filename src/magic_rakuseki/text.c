#include "common.h"
#include "magic_rakuseki/decls.h"

void func_801B0020(void) {
    func_801B1048();
}

void func_801B0040(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DAA3C = D_801C2A3C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_rakuseki/nonmatchings/text", func_801B00AC);

INCLUDE_ASM("../asm/us/magic_rakuseki/nonmatchings/text", func_801B01D4);

INCLUDE_ASM("../asm/us/magic_rakuseki/nonmatchings/text", func_801B02F8);

void func_801B0464(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801C2988[0] = p->unk2;
    D_801DAA3C = func_800D4D90(&D_801C2988[-4], D_801517C0 + 0x70, 0xC, D_801DAA3C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C26A8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_rakuseki/nonmatchings/text", func_801B0520);

INCLUDE_ASM("../asm/us/magic_rakuseki/nonmatchings/text", func_801B07E4);

INCLUDE_ASM("../asm/us/magic_rakuseki/nonmatchings/text", func_801B0A54);

INCLUDE_ASM("../asm/us/magic_rakuseki/nonmatchings/text", func_801B0C58);

INCLUDE_ASM("../asm/us/magic_rakuseki/nonmatchings/text", func_801B0D04);

INCLUDE_ASM("../asm/us/magic_rakuseki/nonmatchings/text", func_801B0F88);

INCLUDE_ASM("../asm/us/magic_rakuseki/nonmatchings/text", func_801B1048);
