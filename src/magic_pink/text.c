#include "common.h"
#include "magic_pink/decls.h"

void func_801B0000(void) {
    func_801B11D4();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E1BD0 = D_801C9BD0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, 0);
    D_801C9B58[0] = p->unk2;
    D_801E1BD0 = func_800D4D90(&D_801C9B58[-4], D_801517C0 + 0x70, 0xC, D_801E1BD0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C9A28) {
            p->unk0 = -1;
        }
    }
}

MgObj8 *func_801B0148(void) {
    s16 i;

    for (i = 0; i < 200; i++) {
        if (D_801E1BD8[i].unk0 == 0) {
            D_801E1BD8[i].unk0 = 1;
            D_801E1BD8[i].unk6 = 0;
            return &D_801E1BD8[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B01C8);

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B04EC);

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B06D4);

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B0884);

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B09DC);

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B0C94);

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B1030);

void func_801B110C(void) {
    MgObj20 *p;
    s16 i;

    p = D_801E2218;
    for (i = 0; i < 150; i++) {
        p->unk2 = 0;
        p->unk0 = 0;
        p++;
    }
    func_800BBEAC(&func_801B1030);
}

s32 func_801B1164(void) {
    MgObj20 *p;
    s16 i;

    p = D_801E2218;
    for (i = 0; i < 150; i++) {
        if (p->unk0 == 0) {
            p->unk0 = 1;
            return i;
        }
        p++;
    }
    return func_800BBA84(6, -1, 0x40);
}

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B11D4);
