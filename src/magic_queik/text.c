#include "common.h"
#include "magic_queik/decls.h"

void func_801B0054(void) {
    func_801B0330();
}

void func_801B0074(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = (p->unkC << 12) / 600;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801B840C;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801D0AE8 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D0AE8);
    if (p->unk2 >= 0x16) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0xE) {
            func_800D5774(p->unk10);
        }
        if (p->unk2 < 8) {
            p->unkC += p->unkE;
        } else if (p->unk2 >= 0xE) {
            p->unkC -= p->unkE;
        }
        p->unk2++;
    }
}

void func_801B024C(arg0) {
    MgTask *p;
    s16 t;

    p = &D_80162978[func_800BBEAC((void *)func_801B0074)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    p->unk6 = 0;
    p->unkC = 0;
    t = D_801518F6[arg0][0] + 0xE0;
    p->unkE = t;
    if (t >= 0x76D) {
        p->unkE = 0x76C;
    }
    p->unkE = p->unkE / 8;
    p->unk10 = arg0;
}

INCLUDE_ASM("../asm/us/magic_queik/nonmatchings/text", func_801B0330);
