#include "common.h"
#include "magic_seed/decls.h"

void func_801B006C(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, p->unk16);
    frame = &D_801B3E54;
    *frame = p->unk2;
    D_801CBE8C = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801CBE8C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B3D88) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_seed/nonmatchings/text", func_801B0128);

INCLUDE_ASM("../asm/us/magic_seed/nonmatchings/text", func_801B038C);

void func_801B0810(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B038C)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_seed/nonmatchings/text", func_801B08D0);
