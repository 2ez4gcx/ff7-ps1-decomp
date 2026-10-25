#include "common.h"
#include "magic_koudan2/decls.h"

void func_801B0030(void) {
    func_801B0FF0();
}

void func_801B0050(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E3A6C = D_801CBA6C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_koudan2/nonmatchings/text", func_801B00BC);

INCLUDE_ASM("../asm/us/magic_koudan2/nonmatchings/text", func_801B01E4);

INCLUDE_ASM("../asm/us/magic_koudan2/nonmatchings/text", func_801B0308);

void func_801B0684(void) {
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
    func_8003C21C(&D_801CBA50, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801CBA4A[0] = t << 8;
    D_801E3A6C = (u8 *)func_800D29D4(&D_801CBA4A[-5], D_801517C0 + 0x70, 0xC, (s32)D_801E3A6C);
    if (D_80062D98 == 0) {
        if (++p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_koudan2/nonmatchings/text", func_801B07FC);

void func_801B0F30(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B07FC)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_koudan2/nonmatchings/text", func_801B0FF0);
