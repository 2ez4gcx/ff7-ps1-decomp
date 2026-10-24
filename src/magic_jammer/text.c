#include "common.h"
#include "magic_jammer/decls.h"

void func_801B0000(void) {
    func_801B0B44();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E92D8 = D_801D12D8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_jammer/nonmatchings/text", func_801B008C);

void func_801B01AC(void) {
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
    func_8003C21C(&D_801D1294, &rot);
    func_8003B05C(&m, &rot);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801D128E[0] = t << 8;
    D_801E92D8 = func_800D29D4(&D_801D128E[-5], D_801517C0 + 0x70, 0xC, D_801E92D8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 15) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_jammer/nonmatchings/text", func_801B0324);

INCLUDE_ASM("../asm/us/magic_jammer/nonmatchings/text", func_801B050C);

INCLUDE_ASM("../asm/us/magic_jammer/nonmatchings/text", func_801B0A68);

void func_801B0B44(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B0BB0, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0A68);
}
