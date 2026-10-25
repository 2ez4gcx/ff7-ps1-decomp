#include "common.h"
#include "magic_comet/decls.h"

void func_801B0000(void) {
    func_801B1364();
}

void func_801B0020(void) {
    s32 otz;
    s32 flag;
    MgTask *p;
    u8 *pkt;
    s32 n;

    pkt = D_801EB4C0;
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
        D_801EB4C0 = pkt + 0xC;
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

INCLUDE_ASM("../asm/us/magic_comet/nonmatchings/text", func_801B017C);

INCLUDE_ASM("../asm/us/magic_comet/nonmatchings/text", func_801B0608);

INCLUDE_ASM("../asm/us/magic_comet/nonmatchings/text", func_801B0850);

INCLUDE_ASM("../asm/us/magic_comet/nonmatchings/text", func_801B0B94);

INCLUDE_ASM("../asm/us/magic_comet/nonmatchings/text", func_801B0C58);

void func_801B1258(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0C58)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

void func_801B12D8(void) {
    M2C_UNK *var_v1;
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    var_v1 = &D_801B13E8;
    if (temp_s0->unk2 == 0) {
        var_v1 = &D_801D34C0;
    }
    D_801EB4C0 = var_v1;
    temp_s0->unk2 = (u16) temp_s0->unk2 ^ 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 4);
        temp_s0->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_comet/nonmatchings/text", func_801B1364);
