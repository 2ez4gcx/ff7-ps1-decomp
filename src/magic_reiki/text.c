#include "common.h"
#include "magic_reiki/decls.h"

void func_801B0000(void) {
    func_801B0D5C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EE294 = D_801D6294 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(0, 0, D_801D61C4);
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 < 0x10) {
            D_801D61C4 = (u16) D_801D61C4 + 0xF;
        }
        if (temp_s0->unk2 >= 0x11) {
            D_801D61C4 = (u16) D_801D61C4 - 0xF;
        }
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 == 0x20) {
            temp_s0->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_reiki/nonmatchings/text", func_801B016C);

void func_801B0430(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D6218;
    *frame = p->unk2;
    D_801EE294 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EE294);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D6084) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_reiki/nonmatchings/text", func_801B04EC);

void func_801B065C(void) {
    MgTask *p;
    u8 c;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D6244[0] = p->unk16;
    c = 0x80 - p->unk2 * 8;
    D_801D6242 = c;
    D_801D6241 = c;
    D_801D6240 = c;
    D_801EE294 = func_800D4D90(&D_801D6244[-4], D_801517C0 + 0x70, 0xC, D_801EE294);
    if (D_80062D98 == 0) {
        p->unk6 -= 300;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 15) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_reiki/nonmatchings/text", func_801B0744);

INCLUDE_ASM("../asm/us/magic_reiki/nonmatchings/text", func_801B0BDC);

INCLUDE_ASM("../asm/us/magic_reiki/nonmatchings/text", func_801B0D5C);
