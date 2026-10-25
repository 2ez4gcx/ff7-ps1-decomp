#include "common.h"
#include "magic_oil/decls.h"

void func_801B0000(void) {
    func_801B0AC4();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EC778 = D_801D4778 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_oil/nonmatchings/text", func_801B008C);

void func_801B01FC(void) {
    MgMat b;
    MgMat a;
    MgMat lw;
    MgTask *p;
    s32 *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D44E8((MgSVec *)&p->unkC, &a);
    func_8003BF8C(&D_801D473C, &b);
    func_8003A79C(&a, &b, &b);
    q = &D_801D4730;
    *q = p->unk18 * D_801D4744 / 4;
    func_8003B35C(&b, (MgVec *)(q - 1));
    b.t[0] = p->unk4;
    b.t[1] = p->unk6;
    b.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &b, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801EC778 = func_800D29D4(D_801D471C, D_801517C0 + 0x70, 0xC, D_801EC778);
    if (D_80062D98 == 0) {
        if (p->unk2 < 4) {
            D_801D4744 += 1;
        } else {
            q[-1] -= 0x800;
            D_801D4734 -= 0x800;
        }
        if (++p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_oil/nonmatchings/text", func_801B03B4);

INCLUDE_ASM("../asm/us/magic_oil/nonmatchings/text", func_801B057C);

void func_801B0A04(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B057C)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_oil/nonmatchings/text", func_801B0AC4);
