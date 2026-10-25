#include "common.h"
#include "magic_laser2/decls.h"

void func_801B0010(void) {
    func_801B0E20();
}

void func_801B0030(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CD77C = D_801B577C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B009C);

void func_801B01F8(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801B3068;
    *frame = p->unk2;
    D_801CD77C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801CD77C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B2F8C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B02B4);

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B0340);

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B0558);

void func_801B065C(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u16 *, 4) + ((s32) (func_80039B40(M2C_FIELD(arg0, s16 *, 0x14)) * M2C_FIELD(arg0, s16 *, 0x18)) >> 0xC));
    M2C_FIELD(arg1, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 6);
    M2C_FIELD(arg1, s16 *, 4) = (s16) (M2C_FIELD(arg0, u16 *, 8) + ((s32) (func_80039A74(M2C_FIELD(arg0, s16 *, 0x14)) * M2C_FIELD(arg0, s16 *, 0x18)) >> 0xC));
}

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B06EC);

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B082C);

void func_801B0D30(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B082C)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    if (p->unk8 > p->unk10) {
        D_801B3050 = -1;
    }
    func_800BBEAC((void *)func_801B0558);
}

INCLUDE_ASM("../asm/us/magic_laser2/nonmatchings/text", func_801B0E20);
