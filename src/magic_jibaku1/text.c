#include "common.h"
#include "magic_jibaku1/decls.h"

void func_801B006C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801B8584;
    *frame = p->unk2;
    D_801D0588 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D0588);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B83F8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_jibaku1/nonmatchings/text", func_801B0128);

INCLUDE_ASM("../asm/us/magic_jibaku1/nonmatchings/text", func_801B02B0);

INCLUDE_ASM("../asm/us/magic_jibaku1/nonmatchings/text", func_801B0338);
