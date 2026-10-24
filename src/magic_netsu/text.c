#include "common.h"
#include "magic_netsu/decls.h"

void func_801B0000(void) {
    func_801B0D0C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EE21C = D_801D621C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(D_801D615C, 0, 0);
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 < 0x10) {
            D_801D615C = (u16) D_801D615C + 0xF;
        }
        if (temp_s0->unk2 >= 0x11) {
            D_801D615C = (u16) D_801D615C - 0xF;
        }
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 == 0x20) {
            temp_s0->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_netsu/nonmatchings/text", func_801B016C);

void func_801B0430(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D61B0;
    *frame = p->unk2;
    D_801EE21C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EE21C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D601C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_netsu/nonmatchings/text", func_801B04EC);

void func_801B0644(void) {
    MgTask *p;
    u8 c;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D61EC[0] = p->unk16;
    c = 0x80 - p->unk2 * 8;
    D_801D61EA = c;
    D_801D61E9 = c;
    D_801D61E8 = c;
    D_801EE21C = func_800D4D90(&D_801D61EC[-4], D_801517C0 + 0x70, 0xC, D_801EE21C);
    if (D_80062D98 == 0) {
        p->unk6 -= 300;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 15) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_netsu/nonmatchings/text", func_801B072C);

INCLUDE_ASM("../asm/us/magic_netsu/nonmatchings/text", func_801B0BB0);

INCLUDE_ASM("../asm/us/magic_netsu/nonmatchings/text", func_801B0D0C);
