#include "common.h"
#include "magic_almighty/decls.h"

void func_801B0000(void) {
    func_801B04E8();
}

INCLUDE_ASM("../asm/us/magic_almighty/nonmatchings/text", func_801B0020);

void func_801B01C0(void) {
    MgObjAlm *p;
    MgObjAlm *q;
    s32 i;

    p = (MgObjAlm *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 10) {
            i = 0;
            D_801B059A[0] = func_80042DA8() & 0xFFF;
            for (; i < D_801B05A8; i++) {
                q = (MgObjAlm *)&D_80162978[func_800BBEAC(&func_801B0020)];
                q->unk8 = p->unk8;
                q->unk1A = func_80042DA8() % 0x2000 + 0x1000;
                q->unk10 = *(MgSVec *)&D_801B059A[-1];
                q->unk18 = (func_80042DA8() % 400 + 100) << 4;
                q->unk1C = func_80042DA8() % 100 - 50;
                D_801B059A[0] += 0x1000 / D_801B05A8;
            }
        } else {
            func_800D5774(p->unk4);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B03E4(s32 arg0) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B01C0)];
    p->unk4 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], (u8 *)&p->unk8);
    p->unkA = 0;
    func_800D55F4(0x20, func_800D56A8((u8 *)&p->unk8), 0x8B);
}

void func_801B0488(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D05AC = D_801B05AC + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B04E8(arg0, arg1) {
    s32 r;
    s32 ret;

    func_800BBEAC(func_801B0488);
    r = func_800D54BC(arg0);
    D_801B05A8 = r == 1 ? 6 : 3;
    ret = func_800D5444(arg0, arg1, -(r >= 4) & 0xA, &func_801B03E4);
    D_800F836C = 0;
    return ret;
}
