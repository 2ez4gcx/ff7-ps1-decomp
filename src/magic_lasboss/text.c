#include "common.h"
#include "magic_lasboss/decls.h"

void func_801B0040(void) {
    func_801B2A50();
}

s32 func_801B0060(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801E6C06[-v];
    }
    return v;
}

s32 func_801B009C(s32 t, s32 s) {
    s32 orig;
    s32 i;
    s32 n;

    orig = t;
    if (s > 0) {
        n = s >> 8;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
    } else {
        s = -s;
        n = s >> 8;
        t = 0x1000 - t;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
        t = 0x1000 - t;
    }
    n = (s & 0xFF) + 1;
    t = (t * n + orig * (0x100 - n)) >> 8;
    return t;
}

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B018C);

void func_801B11C0(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B018C)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1224);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1288);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1344);

void func_801B141C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D6ACC;
    *frame = p->unk2;
    D_801E6BD8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E6BD8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D5EA8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B14D4);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1620);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1A1C);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1B6C);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1C60);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1D88);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B1F04);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B2098);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B21C8);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B22EC);

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B2A50);
