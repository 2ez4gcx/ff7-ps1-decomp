#include "common.h"
#include "magic_renbaku/decls.h"

void func_801B0054(void) {
    func_801B08C4();
}

void func_801B0074(void) {
    MgVec d;
    MgTask *p;
    MgSVec *q;
    s32 i;
    s32 j;
    s32 k;
    s32 t;
    s16 v;

    p = &D_80162978[D_8015169C];
    i = 0;
    D_801C1168.v = p->unk2;
    k = p->unk18;
    q = &D_801D9B34;
    j = k * 8;
    do {
        k++;
        if (D_80062D98 == 0) {
            d.vx = q->vx - *(s16 *)(D_801D917C + j);
            d.vy = q->vy - *(s16 *)(D_801D917C + 2 + j);
            d.vz = q->vz - *(s16 *)(D_801D9180 + j);
            t = func_80039F5C(func_8003A08C(&d, &d)) >> 5;
            *(s16 *)(D_801D917C + j) += t * d.vx >> 12;
            *(s16 *)(D_801D917C + 2 + j) += t * d.vy >> 12;
            *(s16 *)(D_801D9180 + j) += t * d.vz >> 12;
        }
        do {
            v = *(u16 *)(D_801D9182 + j);
            func_800D4368(D_801D917C + j, v, -(v >> 3));
            j += 8;
            D_801D916C = func_800D4D90(D_801C1160, D_801517C0 + 0x70, 0xC, D_801D916C);
        } while (0);
        i++;
        if (k >= 0x137) {
            j = 0;
            k = 0;
        }
    } while (i < 4);
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_renbaku/nonmatchings/text", func_801B02D0);

INCLUDE_ASM("../asm/us/magic_renbaku/nonmatchings/text", func_801B067C);

INCLUDE_RODATA("../asm/us/magic_renbaku/nonmatchings/text", D_801B0000);

void func_801B08C4(arg0) {
    D_801D9170 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B0948, 0, 0, 0);
    func_800BBEAC(&func_801B067C);
    D_801D9174 = arg0;
    D_801D9178 = 0;
}
