#include "common.h"
#include "magic_reito/decls.h"

void func_801B0000(void) {
    func_801B2354();
}

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B0A48);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B1158);

void func_801B12E4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801ECB98 = D_801D4B98 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B1350(void) {
    MgMat m;
    MgTask *p;
    s16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D4ADC, &m);
    func_8003A79C(&D_801ED19C, &m, &m);
    func_8003B35C(&m, &D_801D4AE4);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    frame = &D_801D4AD8;
    *frame = p->unk2 % D_801D4A6C;
    D_801ECB98 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801ECB98);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B149C);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B15CC);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B1684);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B1968);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B1C2C);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B1D74);

void func_801B221C(s32 arg0, s32 arg1) {
    MgSVec d;
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B1D74)];
    func_800D3994(arg1, D_80151915[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    d.vx = (p->unkC.vx - p->unk4.vx) / 8;
    d.vy = (p->unkC.vy - p->unk4.vy) / 8;
    d.vz = (p->unkC.vz - p->unk4.vz) / 8;
    func_800D44E8(&d, &D_801ED19C);
}

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B2354);
