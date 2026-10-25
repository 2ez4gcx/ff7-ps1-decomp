#include "common.h"
#include "magic_mizu/decls.h"

void func_801B0000(void) {
    func_801B0AD8();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DA8A4 = D_801C28A4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_mizu/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_mizu/nonmatchings/text", func_801B01A8);

void func_801B032C(void) {
    MgMat b;
    MgMat a;
    MgMat lw;
    MgTask *p;
    s32 *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D44E8((MgSVec *)&p->unkC, &a);
    func_8003BF8C(&D_801C2898, &b);
    func_8003A79C(&a, &b, &b);
    q = &D_801C288C;
    *q = p->unk18 * D_801C28A0 / 4;
    func_8003B35C(&b, (MgVec *)(q - 1));
    b.t[0] = p->unk4;
    b.t[1] = p->unk6;
    b.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &b, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801DA8A4 = func_800D29D4(D_801C2878, D_801517C0 + 0x70, 0xC, D_801DA8A4);
    if (D_80062D98 == 0) {
        if (p->unk2 < 4) {
            D_801C28A0 += 1;
        } else {
            q[-1] -= 0x800;
            D_801C2890 -= 0x800;
        }
        if (++p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_mizu/nonmatchings/text", func_801B04E4);

void func_801B0A18(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B04E4)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_mizu/nonmatchings/text", func_801B0AD8);
