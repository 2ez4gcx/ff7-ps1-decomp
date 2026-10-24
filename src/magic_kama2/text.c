#include "common.h"
#include "magic_kama2/decls.h"

void func_801B007C(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    frame = &D_801D12FC;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801D1300[p->unk18];
    D_801E9330 = (u8 *)func_800D4D90(q, D_801517C0 + 0x70, 0xC, (s32)D_801E9330);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D1300[p->unk18][1]) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_kama2/nonmatchings/text", func_801B0170);

INCLUDE_ASM("../asm/us/magic_kama2/nonmatchings/text", func_801B0238);

INCLUDE_ASM("../asm/us/magic_kama2/nonmatchings/text", func_801B046C);

void func_801B0914(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B046C)];
    func_800D3994(arg1, D_80151915[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_kama2/nonmatchings/text", func_801B09D4);
