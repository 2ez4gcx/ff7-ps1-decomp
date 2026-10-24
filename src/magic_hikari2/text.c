#include "common.h"
#include "magic_hikari2/decls.h"

void func_801B0000(void) {
    func_801B0854();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D0AE4 = D_801B8AE4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(0, 0, D_801B8AC8);
    if (D_80062D98 == 0) {
        temp_v0 = (u16) D_801B8AC8 + (u16) D_801B8ACA;
        D_801B8AC8 = temp_v0;
        if ((temp_v0 << 0x10) == 0) {
            temp_s0->unk0 = -1;
        }
    }
}

void func_801B0120(s16 arg0) {
    D_801B8AC8 = 0;
    D_801B8ACA = (s16) (0xFF / arg0);
    func_800BBEAC(&func_801B008C);
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    func_800D52A0(0x1000, 0xF);
}

void func_801B01B4(s16 arg0) {
    D_801B8AC8 = 0xFF;
    D_801B8ACA = (s16) -(0xFF / arg0);
    func_800D52A0(0, 0xF);
}

void func_801B0228(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    frame = &D_801B8AD4;
    *frame = p->unk2;
    D_801D0AE4 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D0AE4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801B492C) {
            p->unk0 = -1;
        }
    }
}

void func_801B02E0(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801B8AE0[0] = p->unk2;
    D_801D0AE4 = func_800D4D90(&D_801B8AE0[-4], D_801517C0 + 0x70, 0xC, D_801D0AE4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B8A04) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_hikari2/nonmatchings/text", func_801B039C);

void func_801B07CC(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B039C)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    p->unk1A = arg0;
}

INCLUDE_ASM("../asm/us/magic_hikari2/nonmatchings/text", func_801B0854);
