#include "common.h"
#include "magic_saikyo/decls.h"

void func_801B0000(void) {
    func_801B10A8();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EE0F4 = D_801D60F4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B0274);

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B035C);

void func_801B0758(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    D_801D607C[0] = p->unk2;
    D_801EE0F4 = func_800D4D90(&D_801D607C[-4], D_801517C0 + 0x70, 0xC, D_801EE0F4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D5DA4) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B0810);

void func_801B0980(void) {
    MgTask *p;
    u8 c;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D60A8[0] = p->unk16;
    c = 0x80 - p->unk2 * 8;
    D_801D60A6 = c;
    D_801D60A5 = c;
    D_801D60A4 = c;
    D_801EE0F4 = func_800D4D90(&D_801D60A8[-4], D_801517C0 + 0x70, 0xC, D_801EE0F4);
    if (D_80062D98 == 0) {
        p->unk6 -= 300;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 15) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B0A68);

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B0F3C);

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B10A8);
