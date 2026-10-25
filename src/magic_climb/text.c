#include "common.h"
#include "magic_climb/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0B44();
    return &D_801B4DFC;
}

void func_801B0028(MgSVec *a, MgSVec *b, s32 k, MgSVec *out) {
    MgVec d;

    d.vx = b->vx - a->vx;
    d.vy = b->vy - a->vy;
    d.vz = b->vz - a->vz;
    func_8003A08C(&d, &d);
    out->vx = a->vx + ((k * d.vx) >> 12) - b->vx;
    out->vy = a->vy + ((k * d.vy) >> 12) - b->vy;
    out->vz = a->vz + ((k * d.vz) >> 12) - b->vz;
}

INCLUDE_ASM("../asm/us/magic_climb/nonmatchings/text", func_801B0124);

INCLUDE_ASM("../asm/us/magic_climb/nonmatchings/text", func_801B0304);

INCLUDE_ASM("../asm/us/magic_climb/nonmatchings/text", func_801B07F4);

INCLUDE_ASM("../asm/us/magic_climb/nonmatchings/text", func_801B08B4);

void func_801B0AE4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D6AB0 = D_801B6AB0 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B0B44(arg0, arg1) {
    func_800D2980(D_801B0BBC, 0, 0, 0);
    D_801B6AA8 = arg0;
    D_801B6AAC = arg1;
    func_800BBEAC(func_801B0AE4);
    return func_800BBEAC(func_801B08B4);
}
