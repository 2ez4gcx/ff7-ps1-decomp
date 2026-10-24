#include "common.h"
#include "magic_osen/decls.h"

void func_801B0000(void) {
    func_801B100C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EAD48 = D_801D2D48 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B0174);

MgMat *func_801B022C(MgSVec *pos, MgSVec *rot, s16 s) {
    MgVec scale;

    func_8003C21C(rot, &D_801D2D28);
    scale.vx = scale.vy = scale.vz = s;
    func_8003B35C(&D_801D2D28, &scale);
    D_801D2D3C[0] = pos->vx;
    D_801D2D40[0] = pos->vy;
    D_801D2D44[0] = pos->vz;
    func_8003B48C(&D_801D2D28);
    func_8003B51C(&D_801D2D28);
    return &D_801D2D28;
}

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B02DC);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B040C);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B0718);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B08F0);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B0AA0);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B100C);
