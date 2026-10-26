#include "common.h"
#include "magic_break/decls.h"

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B0000);

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B024C);

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B0440);

void func_801B05E0(void) {
    MgTask *q;
    MgTask *p;
    MgTask *r;
    s32 t;
    s32 u;

    q = D_80162978;
    p = &q[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            r = &q[func_800BBEAC(&func_801B0000)];
            r->unk4 = p->unk4;
            r->unk6 = 0;
            r->unk8 = p->unk8;
            r->unkC = p->unkC;
        }
        if (p->unk2 == 0xF) {
            r = &q[func_800BBEAC(&func_801B024C)];
            r->unk4 = p->unk4;
            r->unk6 = 0;
            r->unk8 = p->unk8;
            r->unkC = p->unkC;
        }
        t = p->unk2;
        if (t == 0x14) {
            r = &q[func_800BBEAC(&func_801B0440)];
            r->unk4 = p->unk4;
            r->unk6 = 0;
            r->unk8 = p->unk8;
            r->unkC = p->unkC;
            u = p->unk2;
            if (u == t) {
                func_800D5774(p->unk0);
                if (p->unk2 == u) {
                    p->unk0 = -1;
                }
            }
        }
        p->unk2++;
    }
}

void func_801B0758(s32 arg0) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B05E0)];
    p->unk0 = arg0;
    p->unkC = func_800D55A4(arg0) / 2;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

void func_801B07F4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801ED328 = D_801CD328 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0854(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B08DC, 0, 0, 0);
    func_800BBEAC(&func_801B07F4);
    func_800D5444(arg0, arg1, 0, &func_801B0758);
    func_800D55F4(0x20, func_800D574C(arg0), 0x55);
}
