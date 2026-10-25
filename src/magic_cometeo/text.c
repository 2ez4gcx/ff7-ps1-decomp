#include "common.h"
#include "magic_cometeo/decls.h"

void func_801B0000(void) {
    func_801B1488();
}

void func_801B0020(void) {
    s32 otz;
    s32 flag;
    MgTask *p;
    u8 *pkt;
    s32 n;

    pkt = D_801EC260;
    p = &D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    n = func_8003BBDC(&p->unk4, pkt + 8, &otz, &flag);
    if (!(flag & 0x60000)) {
        func_80046974(pkt);
        pkt[4] = 0xFF;
        pkt[5] = func_80042DA8();
        pkt[6] = 0;
        func_80046794((n >> 2) * 4 + (D_801517C0 + 0x70), (s32)pkt);
        D_801EC260 = pkt + 0xC;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 6) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
        }
        if (++p->unk2 >= 8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B017C);

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B0608);

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B0844);

void func_801B0B88(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    frame = &D_801D424C;
    *frame = p->unk2;
    func_800D4368(&p->unk4, 0x2500, 0);
    D_801EC260 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EC260);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D40A8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B0C4C);

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B11F4);

void func_801B13FC(void) {
    M2C_UNK *var_v1;
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    var_v1 = &D_801B154C;
    if (temp_s0->unk2 == 0) {
        var_v1 = &D_801D4260;
    }
    D_801EC260 = var_v1;
    temp_s0->unk2 = (u16) temp_s0->unk2 ^ 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 4);
        temp_s0->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B1488);
