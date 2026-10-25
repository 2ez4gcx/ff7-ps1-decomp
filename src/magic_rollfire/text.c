#include "common.h"
#include "magic_rollfire/decls.h"

void func_801B0000(void) {
    func_801B08C4();
}

INCLUDE_ASM("../asm/us/magic_rollfire/nonmatchings/text", func_801B0020);

void func_801B0230(void) {
    MgObj20 *p;
    s32 i;
    s32 off;
    s32 n;

    n = 0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 200; i++) {
        off = i * 0x20;
        if (*(s16 *)(&D_801DCE6C + off) != -1) {
            func_801B0020(&D_801DCE6C + off);
            n++;
        }
    }
    if (n == 0 && D_80162080 < 3) {
        p->unk0 = -1;
    }
}

void func_801B02F4(void) {
    s32 off;
    s16 c;

    c = -1;
    off = 0x18E0;
    do {
        *(s16 *)(&D_801DCE6C + off) = c;
        off -= 0x20;
    } while (off >= 0);
}

MgObj20 *func_801B0320(void) {
    s32 i;
    s32 off;

    for (i = 0; i < 200; i++) {
        off = i * 0x20;
        if (*(s16 *)(&D_801DCE6C + off) == -1) {
            *(s16 *)(&D_801DCE6C + off) = 0;
            *(s16 *)(&D_801DCE6C + 2 + off) = 0;
            return (MgObj20 *)(&D_801DCE6C + off);
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_rollfire/nonmatchings/text", func_801B0384);

INCLUDE_ASM("../asm/us/magic_rollfire/nonmatchings/text", func_801B0610);

void func_801B0864(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DCE60 = D_801BCE60 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B08C4(arg0, arg1) {
    func_800D2980(D_801B093C, 0, 0, 0);
    D_801DCE64 = arg0;
    D_801DCE68 = arg1;
    func_800BBEAC(func_801B0864);
    return func_800BBEAC(func_801B0610);
}
