#include "common.h"
#include "magic_boost/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B046C();
    return &D_801B868C;
}

void func_801B0028(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801BA26C;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801B85F8) {
            p->unk0 = -1;
        }
    }
}

void func_801B00E0(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801BA278;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4.vx += p->unkC.vx;
        p->unk4.vy += p->unkC.vy;
        p->unk4.vz += p->unkC.vz;
        p->unk2++;
        if (p->unk2 == D_801B8530) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_boost/nonmatchings/text", func_801B01C8);

void func_801B03D8(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC((void *)func_801B01C8)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    p->unk1E = arg1;
}

void func_801B046C(arg0, arg1) {
    func_800D2980(&D_801B04CC, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B03D8);
}
