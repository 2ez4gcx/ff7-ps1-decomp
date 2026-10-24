#include "common.h"
#include "magic_carel/decls.h"

void func_801B0000(void) {
    func_801B0FCC();
}

void func_801B0020(void) {
    MgTask *p;
    MgSprArg *s;
    s32 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk10, -500);
    s = (MgSprArg *)0x1F800000;
    s->y = -16;
    s->x = -16;
    s->u = D_801B111C[p->unk2];
    s->v = ((u8 *)&p->unkC)[1];
    s->w = 0x1F;
    s->h = 0x1F;
    s->tpage = p->unk16;
    s->clut = p->unkE;
    s->rgbc = 0x2E808080;
    D_801D1134 = func_800D6260(s, D_801517C0 + 0x70, 0xC, D_801D1134);
    if (D_80062D98 == 0) {
        p->unk2++;
        n = p->unk2;
        if (((u8 *)&p->unkC)[1] == 0x80) {
            if (n >= 8) {
                goto block;
            }
            return;
        }
        if (n >= 9) {
        block:
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_carel/nonmatchings/text", func_801B015C);

INCLUDE_ASM("../asm/us/magic_carel/nonmatchings/text", func_801B03A0);

INCLUDE_ASM("../asm/us/magic_carel/nonmatchings/text", func_801B0648);

void func_801B0814(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D1134 = D_801B1134 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_carel/nonmatchings/text", func_801B0874);

void func_801B08D4(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0874);
    func_800D55F4(0x20, func_800D574C(arg0), 6);
}

INCLUDE_ASM("../asm/us/magic_carel/nonmatchings/text", func_801B0954);

void func_801B09B8(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0954);
    func_800D55F4(0x20, func_800D574C(arg0), 8);
}

void func_801B0A38(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B03A0)];
    p->unk12 = arg0;
    p->unk14 = 0;
    p->unk16 = 0x3A;
}

void func_801B0A8C(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0A38);
    func_800D55F4(0x20, func_800D574C(arg0), 0x45);
}

void func_801B0B0C(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0648)];
    p->unk12 = arg0;
    p->unk14 = 0;
    p->unk16 = 0x3A;
}

void func_801B0B60(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0B0C);
    func_800D55F4(0x20, func_800D574C(arg0), 0x5C);
}

INCLUDE_ASM("../asm/us/magic_carel/nonmatchings/text", func_801B0BE0);

void func_801B0C44(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0BE0);
    func_800D55F4(0x20, func_800D574C(arg0), 0x5B);
}

INCLUDE_ASM("../asm/us/magic_carel/nonmatchings/text", func_801B0CC4);

void func_801B0D24(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0CC4);
    func_800D55F4(0x20, func_800D574C(arg0), 0x1F);
}

INCLUDE_ASM("../asm/us/magic_carel/nonmatchings/text", func_801B0DA4);

void func_801B0E08(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0DA4);
    func_800D55F4(0x20, func_800D574C(arg0), 0x1F);
}

INCLUDE_ASM("../asm/us/magic_carel/nonmatchings/text", func_801B0E88);

void func_801B0EEC(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0E88);
    func_800D55F4(0x20, func_800D574C(arg0), 0x17E);
}

INCLUDE_ASM("../asm/us/magic_carel/nonmatchings/text", func_801B0F6C);

INCLUDE_ASM("../asm/us/magic_carel/nonmatchings/text", func_801B0FCC);

INCLUDE_ASM("../asm/us/magic_carel/nonmatchings/text", func_801B1038);

void func_801B109C(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B1038);
    func_800D55F4(0x20, func_800D574C(arg0), 7);
}
