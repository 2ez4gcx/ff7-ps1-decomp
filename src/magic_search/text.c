#include "common.h"
#include "magic_search/decls.h"

INCLUDE_ASM("../asm/us/magic_search/nonmatchings/text", func_801B008C);

void func_801B0170(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801B5414[0] = p->unk2;
    D_801CD45C = func_800D4D90(&D_801B5414[-4], D_801517C0 + 0x70, 0xC, D_801CD45C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B5280) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_search/nonmatchings/text", func_801B022C);

INCLUDE_ASM("../asm/us/magic_search/nonmatchings/text", func_801B05A0);

INCLUDE_ASM("../asm/us/magic_search/nonmatchings/text", func_801B07B0);

INCLUDE_ASM("../asm/us/magic_search/nonmatchings/text", func_801B08B4);
