#include "common.h"
#include "magic_bioga1/decls.h"

void func_801B0000(void) {
    func_801B0C8C();
}

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B03B0);

void func_801B0600(void) {
    MgTask *p;
    s16 *frame;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        *(s32 *)&D_801E1CEC = 0x2C808080;
    } else {
        t -= 10;
        if (t < 10) {
            D_801E1CEF = 0x2E;
            c = -(t << 7) / 10 - 0x80;
            D_801E1CEC = D_801E1CED = D_801E1CEE = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    frame = &D_801E1CF0;
    *frame = p->unk2 % 7;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801EDEF4 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EDEF4);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unkA -= p->unk12;
    }
}

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B0778);

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B0958);

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B0B94);

void func_801B0C24(void) {
    MgTask *p;
    u8 *buf;

    p = &D_80162978[D_8015169C];
    buf = D_801B0DA4;
    if (p->unk2 == 0) {
        buf = D_801E1EF4;
    }
    D_801EDEF4 = buf;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B0C8C);
