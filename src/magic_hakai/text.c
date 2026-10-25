#include "common.h"
#include "magic_hakai/decls.h"

void func_801B0000(void) {
    func_801B0448();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CE768 = D_801B6768 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk18, p->unk14);
    D_801B6754[0] = (s32)D_801B6760[p->unk16];
    D_801B675C = p->unk2;
    D_801CE768 = (u8 *)func_800D4D90(D_801B6754, D_801517C0 + 0x70, 0xC, (s32)D_801CE768);
    if (D_80062D98 == 0) {
        if (++p->unk2 == D_801B6760[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0180(void) {
    MgTask *p;
    MgTask *q;
    u16 t;
    u16 h;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    D_80163C74 = func_800C4FC8(0, 0, (s16)((s16)t % 2) * 32 + 0x20);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x16) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B008C)];
            func_800D3994(p->unk1C, func_80042DA8() % D_801518F4[p->unk1C][0], &q->unk4);
            q->unk14 = -(u16)D_801518F4[p->unk1C][1];
            h = D_801518F4[p->unk1C][1];
            if (D_801518F4[p->unk1C][1] >= 0xAAB) {
                h = 0xAAA;
            }
            q->unk18 = (s16)h * 6 + func_80042DA8() % ((s16)h * 6);
            q->unk16 = func_80042DA8() % 2;
        }
        if (++p->unk2 == 0x1E) {
            func_800D5774(p->unk1C);
            p->unk0 = -1;
        }
    }
}

void func_801B03F4(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0180)];
    p->unk1C = arg0;
    p->unk1E = arg1;
}

s32 func_801B0448(arg0, arg1) {
    func_800BBEAC(func_801B0020);
    func_800D2980(&D_801B04C4, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B03F4);
    return func_800BBA84(0x186, arg1, 0);
}
