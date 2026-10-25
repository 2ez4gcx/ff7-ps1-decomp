#include "common.h"
#include "magic_sailess/decls.h"

void func_801B0054(void) {
    func_801B03FC();
}

void func_801B0074(void) {
    MgSVec rot;
    MgSVec rot2;
    MgSVec v;
    MgMat m;
    MgMat m2;
    MgVec scale;
    MgTask *p;
    s32 c;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkE;
    rot.vz = p->unkC;
    func_8003BF8C(&rot, &m);
    rot2.vx = 0;
    rot2.vy = p->unkE;
    rot2.vz = 0;
    func_8003BF8C(&rot2, &m2);
    v.vx = 0;
    v.vy = 0;
    v.vz = -p->unk10;
    func_8003B27C(&m2, &v, (MgVec *)m.t);
    m.t[0] += p->unk4;
    m.t[1] += p->unk6;
    m.t[2] += p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk14;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    ((MgScratch *)0x1F800000)->unk0 = &D_801B84D8;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0xC) {
        ((MgScratch *)0x1F800000)->unk4 = 8;
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0xC) * 8;
    }
    D_801D0E7C = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D0E7C);
    if (p->unk2 >= 0x1C) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x14) {
            func_800D5774(p->unk18);
        }
        if (p->unk2 < 8) {
            p->unkC += 0x200;
            p->unk14 += p->unk16;
        } else if (p->unk2 >= 0xC) {
            p->unk10 -= p->unk12;
        }
        p->unk2++;
    }
}

void func_801B02E0(arg0) {
    MgTask *p;
    s32 t;

    p = &D_80162978[func_800BBEAC((void *)func_801B0074)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    p->unkC = 0;
    p->unkE = D_80151A46[arg0][0];
    t = D_801518F6[arg0][0] + 0xE0;
    if (t >= 0x76D) {
        t = 0x76C;
    }
    p->unk10 = t;
    p->unk12 = t / 16;
    p->unk14 = 0;
    if (t >= 0x4F3) {
        t = 0x4F2;
    }
    p->unk18 = arg0;
    p->unk16 = (t << 12) / 2000;
}

INCLUDE_RODATA("../asm/us/magic_sailess/nonmatchings/text", D_801B0000);

s32 func_801B03FC(arg0, arg1) {
    D_801D0E80 = &D_80162978[func_800BBEAC((M2C_UNK *)D_801B0000)];
    func_800D2980(&D_801B0498, 0, 0, 0);
    func_800D5444(arg0, arg1, 1, func_801B02E0);
    return func_800D55F4(0x20, func_800D574C(arg0), 0x54);
}
