#include "common.h"
#include "magic_kien/decls.h"

INCLUDE_ASM("../asm/us/magic_kien/nonmatchings/text", func_801B006C);

INCLUDE_ASM("../asm/us/magic_kien/nonmatchings/text", func_801B013C);

void func_801B0214(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    frame = &D_801C20DC;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801C20BC[p->unk18];
    D_801DA114 = (u8 *)func_800D4D90(q, D_801517C0 + 0x70, 0xC, (s32)D_801DA114);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C20BC[p->unk18][1]) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_kien/nonmatchings/text", func_801B0308);

INCLUDE_ASM("../asm/us/magic_kien/nonmatchings/text", func_801B055C);

INCLUDE_ASM("../asm/us/magic_kien/nonmatchings/text", func_801B087C);

INCLUDE_ASM("../asm/us/magic_kien/nonmatchings/text", func_801B0948);
