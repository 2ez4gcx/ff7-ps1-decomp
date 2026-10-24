#include "common.h"
#include "magic_cbreath/decls.h"

void func_801B008C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, 0);
    D_801C1AA0[0] = p->unk2;
    D_801DA120 = func_800D4D90(&D_801C1AA0[-4], D_801517C0 + 0x70, 0xC, D_801DA120);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C1914) {
            p->unk0 = -1;
        }
    }
}

MgObj8 *func_801B0148(void) {
    s16 i;

    for (i = 0; i < 200; i++) {
        if (D_801C1AE0[i].unk0 == 0) {
            D_801C1AE0[i].unk0 = 1;
            D_801C1AE0[i].unk6 = 0;
            return &D_801C1AE0[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_cbreath/nonmatchings/text", func_801B01C8);

INCLUDE_ASM("../asm/us/magic_cbreath/nonmatchings/text", func_801B04C8);

INCLUDE_ASM("../asm/us/magic_cbreath/nonmatchings/text", func_801B06A8);

INCLUDE_ASM("../asm/us/magic_cbreath/nonmatchings/text", func_801B083C);

INCLUDE_ASM("../asm/us/magic_cbreath/nonmatchings/text", func_801B0A00);

void func_801B0E54(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B0A00)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_cbreath/nonmatchings/text", func_801B0F14);
