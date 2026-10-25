#include "common.h"
#include "magic_kafun/decls.h"

void func_801B008C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801D16B4[0] = p->unk2;
    D_801E9D28 = func_800D4D90(&D_801D16B4[-4], D_801517C0 + 0x70, 0xC, D_801E9D28);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D1504) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B0148);

MgObj8 *func_801B0308(void) {
    s16 i;

    for (i = 0; i < 200; i++) {
        if (D_801D16E8[i].unk0 == 0) {
            D_801D16E8[i].unk0 = 1;
            D_801D16E8[i].unk6 = 0;
            return &D_801D16E8[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B0388);

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B06E4);

void func_801B08B4(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 *frame;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    p->unkC = -p->unk2 << 7;
    func_8003C21C((MgSVec *)&p->unkC, &m);
    D_801D16CC[0] = p->unk18;
    t = (p->unk1A + 0x100) * 0x1A;
    D_801D16D0 = t;
    D_801D16CC[-1] = t;
    func_8003B35C(&m, (MgVec *)&D_801D16CC[-1]);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801D16E2;
    *frame = D_801D16C4 * 0x10;
    D_801E9D28 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801E9D28);
    if (D_80062D98 == 0) {
        p->unk1A += 8;
        if (p->unk2 < 8) {
            D_801D16C4 += 1;
        }
        if (p->unk2 >= 0x26) {
            D_801D16C4 -= 1;
        }
        if (++p->unk2 == 0x2D) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B0A64);

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B0E14);

void func_801B0F18(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0020);
    func_800D2980(&D_801B1460, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0E14);
    func_800BBA84(0x69, arg1, 0x40);
}

void func_801B0F94(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0020);
    func_800D2980(&D_801B1460, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0E14);
    func_800BBA84(0x69, arg1, 0x40);
    D_801D16A8 = 9;
}

INCLUDE_RODATA("../asm/us/magic_kafun/nonmatchings/text", D_801B0020);
