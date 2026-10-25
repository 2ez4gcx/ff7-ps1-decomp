#include "common.h"
#include "magic_stop/decls.h"

void func_801B0054(void) {
    func_801B0DB8();
}

INCLUDE_ASM("../asm/us/magic_stop/nonmatchings/text", func_801B0074);

void func_801B02AC(void) {
    MgSVec rot1;
    MgSVec rot2;
    MgSVec ofs;
    MgMat m1;
    MgMat m2;
    MgVec scale;
    MgTask *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 3) {
        if (D_80062D98 == 0) {
            p->unk2 = t + 1;
        }
    } else {
        rot1.vx = 0;
        rot1.vy = p->unkE;
        rot1.vz = p->unkC;
        func_8003BF8C(&rot1, &m1);
        rot2.vx = 0;
        rot2.vy = p->unkE;
        rot2.vz = 0;
        func_8003BF8C(&rot2, &m2);
        ofs.vx = 0;
        ofs.vy = 0;
        ofs.vz = -p->unk10;
        func_8003B27C(&m2, &ofs, (MgVec *)m1.t);
        m1.t[0] += p->unk4;
        m1.t[1] += p->unk6;
        m1.t[2] += p->unk8;
        scale.vx = scale.vy = scale.vz = p->unk14;
        func_8003B35C(&m1, &scale);
        func_8003A63C(&D_800FA63C, &m1, &m1);
        func_8003B48C(&m1);
        func_8003B51C(&m1);
        ((MgScratch *)0x1F800000)->unk0 = &D_801B3194;
        ((MgScratch *)0x1F800000)->unk4 = 0x28;
        ((MgScratch *)0x1F800000)->unkA = 0x80;
        ((MgScratch *)0x1F800000)->unk8 = 0;
        ((MgScratch *)0x1F800000)->unkC = 0x20;
        ((MgScratch *)0x1F800000)->unkE = 0;
        D_801CB280 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801CB280);
        if (p->unk2 >= 0x23) {
            p->unk0 = -1;
        }
        if (D_80062D98 == 0) {
            if (p->unk2 < 0xB) {
                p->unk14 += p->unk16;
            }
            if (p->unk2 >= 0x19) {
                p->unkC += 0x80;
                p->unk14 -= p->unk1A;
                p->unk10 -= p->unk12;
            }
            p->unk2++;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_stop/nonmatchings/text", func_801B0510);

INCLUDE_ASM("../asm/us/magic_stop/nonmatchings/text", func_801B0890);

INCLUDE_ASM("../asm/us/magic_stop/nonmatchings/text", func_801B0DB8);
