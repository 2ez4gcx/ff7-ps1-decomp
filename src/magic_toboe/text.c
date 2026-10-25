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

void func_801B0194(void) {
    MgMat m;
    MgMat m2;
    MgMat m3;
    MgVec scale;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D44E8((MgSVec *)&p->unkC, &m3);
    func_8003C21C(&D_801B1580, &m);
    func_8003A79C(&m3, &m, &m);
    scale.vx = scale.vy = scale.vz = p->unk14;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    func_8003B69C(0, 0, 0);
    D_801C95B0 = (u8 *)func_800D29D4(D_801B1570, D_801517C0 + 0x70, 0xC, (s32)D_801C95B0);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk14 += 0x190;
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

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

void func_801B0760(s32 arg0, s32 arg1) {
    MgTask *p;
    u8 pad[8];

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0484)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk18 = arg0;
}

INCLUDE_ASM("../asm/us/magic_toboe/nonmatchings/text", func_801B0820);
