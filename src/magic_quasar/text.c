#include "common.h"
#include "magic_quasar/decls.h"

void func_801B0000(void) {
    func_801B1470();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EF54C = D_801D754C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D7410;
    *frame = p->unk2;
    D_801EF54C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EF54C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D7344) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_quasar/nonmatchings/text", func_801B0144);

INCLUDE_ASM("../asm/us/magic_quasar/nonmatchings/text", func_801B0340);

INCLUDE_ASM("../asm/us/magic_quasar/nonmatchings/text", func_801B045C);

INCLUDE_ASM("../asm/us/magic_quasar/nonmatchings/text", func_801B05B0);

INCLUDE_ASM("../asm/us/magic_quasar/nonmatchings/text", func_801B07BC);

INCLUDE_ASM("../asm/us/magic_quasar/nonmatchings/text", func_801B0E88);

INCLUDE_ASM("../asm/us/magic_quasar/nonmatchings/text", func_801B0F74);

INCLUDE_ASM("../asm/us/magic_quasar/nonmatchings/text", func_801B1318);

INCLUDE_ASM("../asm/us/magic_quasar/nonmatchings/text", func_801B1470);
