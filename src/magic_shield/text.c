#include "common.h"
#include "magic_shield/decls.h"

void func_801B0010(void) {
    D_801C8F54 = 6;
    D_801B0F2C = 1;
    func_801B0880();
}

void func_801B0048(void) {
    D_801C8F54 = 6;
    func_801B0880();
}

void func_801B0074(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C8F50 = D_801B0F50 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_shield/nonmatchings/text", func_801B00E0);

INCLUDE_ASM("../asm/us/magic_shield/nonmatchings/text", func_801B01D8);

void func_801B0388(void) {
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B01D8)];
        q->unk4 = p->unk4;
        q->unk6 = p->unk6;
        q->unk8 = p->unk8;
        q->unkC = p->unkC;
        q->unkE = p->unkE;
        q->unk10 = p->unk10;
        q->unk16 = p->unk16;
        p->unk2++;
        if (p->unk2 == D_801C8F54) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_shield/nonmatchings/text", func_801B0490);

void func_801B07EC(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0490)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1E = arg1;
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_shield/nonmatchings/text", func_801B0880);
