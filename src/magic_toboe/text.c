#include "common.h"
#include "magic_toboe/decls.h"

void func_801B0000(void) {
    func_801B0820();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C95B0 = D_801B15B0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_toboe/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_toboe/nonmatchings/text", func_801B0194);

void func_801B030C(void) {
    MgTask *p;
    MgMat m;
    MgMat rot;
    s32 flag;
    s16 i;
    s32 t;

    p = &D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = p->unk2 * 600 + 0x800;
    func_8003C21C(&D_801B1598, &rot);
    func_8003B05C(&m, &rot);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801B1592[0] = t << 8;
    D_801C95B0 = func_800D29D4(&D_801B1592[-5], D_801517C0 + 0x70, 0xC, D_801C95B0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 15) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_toboe/nonmatchings/text", func_801B0484);

INCLUDE_ASM("../asm/us/magic_toboe/nonmatchings/text", func_801B0760);

INCLUDE_ASM("../asm/us/magic_toboe/nonmatchings/text", func_801B0820);
