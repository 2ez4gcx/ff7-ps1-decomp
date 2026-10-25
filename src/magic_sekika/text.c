#include "common.h"
#include "magic_sekika/decls.h"

void func_801B0008(void) {
    func_801B2914();
}

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B0A50);

void func_801B1160(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E586C = D_801CD86C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_RODATA("../asm/us/magic_sekika/nonmatchings/text", D_801B0000);

INCLUDE_RODATA("../asm/us/magic_sekika/nonmatchings/text", D_801B0004);

void func_801B11CC(void) {
    MgPtrPair tbl;
    MgTask *p;
    s32 **hdr;

    tbl = D_801B0000;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2400, 0);
    hdr = &D_801CD778;
    M2C_SFIELD(hdr, s32 **, 0) = tbl.ptr[p->unk1A];
    D_801CD780 = p->unk2;
    D_801E586C = (u8 *)func_800D4D90(hdr, D_801517C0 + 0x70, 0xC, (s32)D_801E586C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= tbl.ptr[p->unk1A][1]) {
            if (p->unk1A == 0) {
                p->unk1A = 1;
                p->unk2 = 0;
            } else {
                p->unk0 = -1;
            }
        }
    }
}

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B12E8);

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B1408);

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B1538);

void func_801B162C(void) {
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
    func_8003C21C(&D_801CD7C4, &rot);
    func_8003B05C(&m, &rot);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801CD7BE[0] = t << 8;
    D_801E586C = func_800D29D4(&D_801CD7BE[-5], D_801517C0 + 0x70, 0xC, D_801E586C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 15) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B17A4);

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B18D0);

void func_801B1A5C(void) {
    s16 i;

    i = 0;
    do {
        D_801E5870[i][0] += D_801E5C70[i][0];
        D_801E5870[i][1] += D_801E5C70[i][1];
        D_801E5874[i][0] += D_801E5C74[i][0];
        D_801E5C70[i][1] += 0x14;
        if (D_801E5870[i][1] > 0) {
            D_801E5870[i][1] = 0;
            D_801E5C70[i][1] = -D_801E5C70[i][1];
        }
        i++;
    } while (i < 0x80);
}

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B1B98);

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B1EE0);

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B2240);

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B27FC);

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B2914);
