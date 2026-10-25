#include "common.h"
#include "magic_kama/decls.h"

void func_801B0010(void) {
    func_801B09C4();
}

void func_801B0030(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E12C0 = D_801C92C0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B009C(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    frame = &D_801C928C;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801C9290[p->unk18];
    D_801E12C0 = (u8 *)func_800D4D90(q, D_801517C0 + 0x70, 0xC, (s32)D_801E12C0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C9290[p->unk18][1]) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_kama/nonmatchings/text", func_801B0190);

INCLUDE_ASM("../asm/us/magic_kama/nonmatchings/text", func_801B0258);

INCLUDE_ASM("../asm/us/magic_kama/nonmatchings/text", func_801B049C);

void func_801B0904(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B049C)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B09C4(arg0, arg1) {
    func_800BBEAC(&func_801B0030);
    func_800D2980(D_801B0A40, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0904);
    func_800BBA84(0x83, arg1, 0x40);
}
