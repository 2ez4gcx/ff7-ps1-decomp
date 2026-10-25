#include "common.h"
#include "magic_jibaku1/decls.h"

void func_801B006C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801B8584;
    *frame = p->unk2;
    D_801D0588 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D0588);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B83F8) {
            p->unk0 = -1;
        }
    }
}

void func_801B0128(void) {
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((u16)p->unk2 < 10) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B006C)];
            q->unk4 = p->unk4 + func_80042DA8() % 1000 - 0x1F4;
            q->unk6 = p->unk6 + func_80042DA8() % 1000 - 0x1F4;
            q->unk8 = p->unk8 + func_80042DA8() % 1000 - 0x1F4;
        }
        if (p->unk2 == 0) {
            func_800D5774(p->unk14);
        }
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B02B0(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void (*)())func_801B0128)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    p->unk14 = arg0;
}

INCLUDE_RODATA("../asm/us/magic_jibaku1/nonmatchings/text", D_801B0000);

s32 func_801B0338(arg0, arg1) {
    func_800BBEAC(D_801B0000);
    func_800D2980(D_801B03B4, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B02B0);
    return func_800BBA84(0x7C, arg1, 0);
}
