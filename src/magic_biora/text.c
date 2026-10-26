#include "common.h"
#include "magic_biora/decls.h"

void func_801B0000(void) {
    func_801B0B90();
}

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0020);

void func_801B0350(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    frame = &D_801CCC68;
    *frame = p->unk2;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801ECC78 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801ECC78);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B0410(void) {
    MgTask *p;
    s16 *frame;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        *(s32 *)&D_801CCC70 = 0x2C808080;
    } else {
        t -= 10;
        if (t < 10) {
            D_801CCC73 = 0x2E;
            c = -(t << 7) / 10 - 0x80;
            D_801CCC70 = D_801CCC71 = D_801CCC72 = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    frame = &D_801CCC74;
    *frame = p->unk2 % 7;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801ECC78 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801ECC78);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unkA -= p->unk12;
    }
}

void func_801B0588(void) {
    MgTask *p;
    MgTask *q;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (!(p->unk2 & 3)) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0410)];
            r = func_80042DA8();
            q->unk8 = p->unk8 + r % 2000 - 0x3E8;
            q->unkA = 0;
            q->unkC = p->unkC + func_80042DA8() % 2000 - 0x3E8;
            q->unk10 = func_80042DA8() % 1280 + 0x1000;
            q->unk12 = func_80042DA8() % 50 + 0x32;
        }
        p->unk2++;
        if (p->unk2 >= 0x14) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0734);

void func_801B0A94(s32 arg0, s32 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B0734)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    func_800D3994(arg0, D_8015190F[arg0][0], p->pad);
    func_800D55F4(0x20, 0x40, 0x5A);
}

void func_801B0B30(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801ECC78 = D_801CCC78 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0B90(arg0, arg1) {
    func_800D2980(&D_801B0C00, 0, 0, 0);
    func_800BBEAC((M2C_UNK *)func_801B0B30);
    func_800D5444(arg0, arg1, 4, func_801B0A94);
}
