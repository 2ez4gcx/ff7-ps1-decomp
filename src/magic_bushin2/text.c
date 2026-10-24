#include "common.h"
#include "magic_bushin2/decls.h"

M2C_UNK *func_801B0008(void) {
    func_801B352C();
    return &D_801D8A00;
}

void func_801B0030(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801F338C = D_801DB058[p->unk2];
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

MgMat *func_801B0094(MgSVec *pos, MgSVec *rot, s16 s) {
    MgVec scale;

    func_8003C21C(rot, &D_801DB354);
    scale.vx = scale.vy = scale.vz = s;
    func_8003B35C(&D_801DB354, &scale);
    D_801DB368[0] = pos->vx;
    D_801DB36C[0] = pos->vy;
    D_801DB370[0] = pos->vz;
    func_8003B48C(&D_801DB354);
    func_8003B51C(&D_801DB354);
    return &D_801DB354;
}

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B0144);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B02F0);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B0494);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B060C);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B0740);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B08B4);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B0A30);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B0D34);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B0F3C);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B103C);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B118C);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B12E4);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B139C);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B1580);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B1818);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B1A70);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B1BD0);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B1D2C);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B1FC8);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B20A4);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B3388);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B3464);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B34BC);

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B352C);
