#include "common.h"
#include "magic_q_ketsu/decls.h"

void func_801B007C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801BDA98;
    *frame = p->unk2;
    D_801D5AE8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D5AE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801BD9CC) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_q_ketsu/nonmatchings/text", func_801B0138);

INCLUDE_ASM("../asm/us/magic_q_ketsu/nonmatchings/text", func_801B0264);

void func_801B03FC(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801BDAC4;
    *frame = p->unk2;
    D_801D5AE8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D5AE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801BD84C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_q_ketsu/nonmatchings/text", func_801B04B4);

INCLUDE_ASM("../asm/us/magic_q_ketsu/nonmatchings/text", func_801B08E0);

INCLUDE_ASM("../asm/us/magic_q_ketsu/nonmatchings/text", func_801B0C5C);

INCLUDE_ASM("../asm/us/magic_q_ketsu/nonmatchings/text", func_801B0F5C);

INCLUDE_ASM("../asm/us/magic_q_ketsu/nonmatchings/text", func_801B1028);
