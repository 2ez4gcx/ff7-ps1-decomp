#include "common.h"
#include "magic_zenbaku/decls.h"

void func_801B0054(void) {
    func_801B0860();
}

void func_801B0074(void) {
    MgTask *p;
    s32 i;
    s32 j;
    s16 v;

    p = &D_80162978[D_8015169C];
    D_801C1100.v = p->unk2;
    j = p->unk18 * 8;
    for (i = 0; i < 1; i++) {
        v = *(u16 *)(D_801D9126 + j);
        func_800D4368(D_801D9120 + j, v, -(v >> 4));
        j += 8;
        D_801D9110 = func_800D4D90(&D_801C10F8, D_801517C0 + 0x70, 0xC, D_801D9110);
        if (j >= 0xDE0) {
            j = 0;
        }
    }
    if (p->unk2 >= 0xF) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B018C(void) {
    MgTask *p;
    s32 i;
    s32 j;
    s16 v;

    p = &D_80162978[D_8015169C];
    D_801C110C.v = p->unk2;
    j = p->unk18 * 8;
    for (i = 0; i < 1; i++) {
        v = *(u16 *)(D_801D9126 + j);
        func_800D4368(D_801D9120 + j, v, -(v >> 4));
        j += 8;
        D_801D9110 = func_800D4D90(&D_801C1104, D_801517C0 + 0x70, 0xC, D_801D9110);
        if (j >= 0xDE0) {
            j = 0;
        }
    }
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_zenbaku/nonmatchings/text", func_801B02A4);

void func_801B07A4(void) {
    MgTask *p;
    s32 t;
    MgTask *q;

    D_80162978[D_8015169C].unk0 = -1;
    q = D_80162978;
    p = &q[func_800BBEAC(&func_801B02A4)];
    func_800D54EC(D_801D9118, &p->unk4);
    p->unk6 = -0x540;
    p->unkC = 0x9A0;
    p->unkE = 0x1340;
    p->unk14 = 0x380;
    t = -(p->unk6 >> 1);
    p->unk10 = t;
    p->unk12 = t * 3;
    p->unk10 = (u16)p->unk10 * 2;
}

INCLUDE_RODATA("../asm/us/magic_zenbaku/nonmatchings/text", D_801B0000);

void func_801B0860(arg0) {
    D_801D9114 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B08E4, 0, 0, 0);
    func_800BBEAC(&func_801B07A4);
    D_801D9118 = arg0;
    D_801D911C = 0;
}
