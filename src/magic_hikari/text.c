#include "common.h"
#include "magic_hikari/decls.h"

void func_801B006C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    frame = &D_801B8914;
    *frame = p->unk2;
    D_801D0924 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D0924);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801B4770) {
            p->unk0 = -1;
        }
    }
}

void func_801B0124(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801B8920;
    *frame = p->unk2;
    D_801D0924 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D0924);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B8848) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_hikari/nonmatchings/text", func_801B01E0);

void func_801B0610(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B01E0)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    p->unk1A = arg0;
}

INCLUDE_RODATA("../asm/us/magic_hikari/nonmatchings/text", D_801B0000);

void func_801B0698(s32 arg0, s32 arg1) {
    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B072C, 0, 0, 0);
    func_800D2980(&D_801B4804, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, (M2C_UNK *)func_801B0610);
    func_800BBA84(0x6B, arg1, 0x40);
}
