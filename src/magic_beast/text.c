#include "common.h"
#include "magic_beast/decls.h"

s32 func_801B0054(void) {
    func_801B13EC();
    return 0;
}

INCLUDE_ASM("../asm/us/magic_beast/nonmatchings/text", func_801B0078);

INCLUDE_ASM("../asm/us/magic_beast/nonmatchings/text", func_801B0398);

void func_801B0408(void) {
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (p->unk1C < p->unk12) {
        if (D_80062D98 == 0) {
            p->unk1C++;
        }
        return;
    }
    t = p->unk18 * D_801C3498[p->unk2];
    func_800D4368(&p->unk4, (s16)(t << 4 >> 16), -(t >> 14));
    ((MgScratch *)0x1F800000)->unk0 = D_801C2ECC;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801DB4B0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DB4B0);
    if (p->unk2 >= 4) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_beast/nonmatchings/text", func_801B0550);

INCLUDE_ASM("../asm/us/magic_beast/nonmatchings/text", func_801B0AC8);

INCLUDE_ASM("../asm/us/magic_beast/nonmatchings/text", func_801B0D5C);

INCLUDE_ASM("../asm/us/magic_beast/nonmatchings/text", func_801B1320);

INCLUDE_ASM("../asm/us/magic_beast/nonmatchings/text", func_801B13EC);
