#include "common.h"
#include "magic_mdance/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B0754();
    return &D_801B07C8;
}

void func_801B007C(void) {
    MgTask *p;
    MgSprArg *s;
    s32 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk10, -500);
    s = (MgSprArg *)0x1F800000;
    s->y = -16;
    s->x = -16;
    s->u = D_801B6278[p->unk2];
    s->v = ((u8 *)&p->unkC)[1];
    s->w = 0x1F;
    s->h = 0x1F;
    s->tpage = p->unk16;
    s->clut = p->unkE;
    s->rgbc = 0x2E808080;
    D_801CE290 = func_800D6260(s, D_801517C0 + 0x70, 0xC, D_801CE290);
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

INCLUDE_ASM("../asm/us/magic_mdance/nonmatchings/text", func_801B01B8);

void func_801B0460(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B01B8)];
    p->unk12 = arg0;
    p->unk14 = 0;
    p->unk16 = 0x3A;
}

INCLUDE_ASM("../asm/us/magic_mdance/nonmatchings/text", func_801B04B4);

INCLUDE_ASM("../asm/us/magic_mdance/nonmatchings/text", func_801B0524);

INCLUDE_ASM("../asm/us/magic_mdance/nonmatchings/text", func_801B0678);

INCLUDE_ASM("../asm/us/magic_mdance/nonmatchings/text", func_801B0754);
