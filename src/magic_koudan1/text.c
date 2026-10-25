#include "common.h"
#include "magic_koudan1/decls.h"

void func_801B0030(void) {
    func_801B0AC4();
}

void func_801B0050(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E33D0 = D_801CB3D0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_koudan1/nonmatchings/text", func_801B00BC);

INCLUDE_ASM("../asm/us/magic_koudan1/nonmatchings/text", func_801B01B0);

void func_801B052C(void) {
    MgMat m;
    MgMat r;
    s32 flag;
    s16 i;
    s32 t;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = p->unk2 * 0x320 + 0x1000;
    func_8003C21C(&D_801CB3B4, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801CB3AE[0] = t << 8;
    D_801E33D0 = (u8 *)func_800D29D4(&D_801CB3AE[-5], D_801517C0 + 0x70, 0xC, (s32)D_801E33D0);
    if (D_80062D98 == 0) {
        if (++p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_koudan1/nonmatchings/text", func_801B06A4);

INCLUDE_ASM("../asm/us/magic_koudan1/nonmatchings/text", func_801B09F0);

INCLUDE_ASM("../asm/us/magic_koudan1/nonmatchings/text", func_801B0AC4);
