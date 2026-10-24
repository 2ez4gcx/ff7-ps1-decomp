#include "common.h"
#include "magic_lasboss2/decls.h"

void func_801B0000(void) {
    func_801B1834();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E5EE8 = D_801CDEE8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

MgMat *func_801B008C(MgSVec *pos, MgSVec *rot, s16 s) {
    MgVec scale;

    func_8003C21C(rot, &D_801CD6F8);
    scale.vx = scale.vy = scale.vz = s;
    func_8003B35C(&D_801CD6F8, &scale);
    D_801CD70C[0] = pos->vx;
    D_801CD710[0] = pos->vy;
    D_801CD714[0] = pos->vz;
    func_8003B48C(&D_801CD6F8);
    func_8003B51C(&D_801CD6F8);
    return &D_801CD6F8;
}

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B013C);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0248);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0338);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0410);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B04F4);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B05FC);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B06DC);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0824);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0948);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0A34);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0B3C);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0C28);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B0D8C);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B1024);

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B1834);
