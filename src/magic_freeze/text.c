#include "common.h"
#include "magic_freeze/decls.h"

void func_801B0000(void) {
    func_801B17D0();
}

void func_801B0020(void) {
    MgTask *p;
    s32 t;
    s32 a;
    s32 c;
    s32 v;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        c = (t << 7) / 5;
    } else {
        c = 0x80;
    }
    D_801D5E2E.v = c;
    D_801D5E2D.v = c;
    D_801D5E2C.v = c;
    a = p->unk2;
    v = a + p->unk0;
    if (v < 0x19) {
        if (D_80062D98 == 0) {
            p->unk6 += func_80039A74((a << 12) / 40) * 70 >> 12;
        }
    } else {
        v -= 0x19;
        if (v < 5) {
            if (v == 0) {
                *(s16 *)((u8 *)p + 0xC) = (D_801E5F38 - p->unk4) / 5;
                *(s16 *)((u8 *)p + 0xE) = (D_801E5F3A - p->unk6) / 5;
                *(s16 *)((u8 *)p + 0x10) = (D_801E5F3C - p->unk8) / 5;
            }
            if (D_80062D98 == 0) {
                p->unk4 += p->unkC;
                p->unk6 += p->unkE;
                p->unk8 += p->unk10;
            }
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_800D4368(&p->unk4, p->unk14, 0);
    D_801E5F30 = func_800D4D90(D_801D5E28, D_801517C0 + 0x70, 0xC, D_801E5F30);
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B026C);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B04B8);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B067C);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B0828);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B09D4);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B0AC0);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B0CA8);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B0E44);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B0FC4);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B10B0);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B13A8);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B16BC);

void func_801B1770(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E5F30 = D_801D5F30 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B17D0(arg0, arg1) {
    func_800D2980(&D_801B1840, 0, 0, 0);
    func_800BBEAC(&func_801B1770);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B16BC);
}
