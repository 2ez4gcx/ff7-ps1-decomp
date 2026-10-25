#include "common.h"
#include "magic_wlaser/decls.h"

void func_801B0000(void) {
    func_801B083C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E0E68 = D_801C8E68 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801C8E3C.unk0 = D_801C8E48[p->unk16];
    D_801C8E3C.unk8 = p->unk2;
    D_80163C74 = func_800D4D90(&D_801C8E3C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801C8E48[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_wlaser/nonmatchings/text", func_801B0180);

INCLUDE_ASM("../asm/us/magic_wlaser/nonmatchings/text", func_801B0364);

void func_801B07A8(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC((void *)func_801B0364)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    p->unk1E = arg1;
}

INCLUDE_ASM("../asm/us/magic_wlaser/nonmatchings/text", func_801B083C);
