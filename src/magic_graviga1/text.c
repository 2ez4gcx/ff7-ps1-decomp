#include "common.h"
#include "magic_graviga1/decls.h"

INCLUDE_ASM("../asm/us/magic_graviga1/nonmatchings/text", func_801B0000);

void func_801B00E8(void) {
    MgObjVel *p;
    MgObjVel *q;

    p = (MgObjVel *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        p->unk8.vx += p->unk10.vx;
        p->unk8.vy += p->unk10.vy;
        p->unk8.vz += p->unk10.vz;
        q = (MgObjVel *)&D_80162978[func_800BBEAC(&func_801B0000)];
        q->unk8 = p->unk8;
        p->unk2++;
        if (p->unk2 >= 8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_graviga1/nonmatchings/text", func_801B01C0);

INCLUDE_ASM("../asm/us/magic_graviga1/nonmatchings/text", func_801B03A8);

INCLUDE_ASM("../asm/us/magic_graviga1/nonmatchings/text", func_801B0634);

INCLUDE_ASM("../asm/us/magic_graviga1/nonmatchings/text", func_801B07D8);

INCLUDE_ASM("../asm/us/magic_graviga1/nonmatchings/text", func_801B0A34);

INCLUDE_ASM("../asm/us/magic_graviga1/nonmatchings/text", func_801B0AC8);

INCLUDE_ASM("../asm/us/magic_graviga1/nonmatchings/text", func_801B0E54);

void func_801B1348(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0E54)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk8);
}

INCLUDE_ASM("../asm/us/magic_graviga1/nonmatchings/text", func_801B13D4);

INCLUDE_ASM("../asm/us/magic_graviga1/nonmatchings/text", func_801B1464);
