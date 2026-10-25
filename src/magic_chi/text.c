#include "common.h"
#include "magic_chi/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B061C();
    return &D_801B47E0;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C8080 = D_801B8080 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0088(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801B8034;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801B471C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_chi/nonmatchings/text", func_801B0140);

void func_801B061C(arg0, arg1) {
    func_800BBEAC((void *)func_801B0028);
    func_800D2980(D_801B06D8, 0, 0, 0);
    D_801C8084 = arg0;
    func_800D54EC(arg0, D_801C8088);
    D_80162996[func_800BBEAC((void *)func_801B0140)].unk0 = arg1;
    D_800F5B71 = 0;
    D_800F5B72 = 0;
    D_800F5B70 = 0x40;
    func_800D52A0(0x1000, 0xA);
}
