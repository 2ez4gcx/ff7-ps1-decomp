#include "common.h"
#include "magic_search/decls.h"

INCLUDE_RODATA("../asm/us/magic_search/nonmatchings/text", D_801B0000);

void func_801B008C(s32 arg0, MgSVec *rot, s16 scale) {
    MgMat r;
    MgMat m;
    MgVec unused;

    m = D_801B0000;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = scale;
    func_8003B05C(&m, &D_800FA63C);
    func_8003C21C(rot, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
}

void func_801B0170(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801B5414[0] = p->unk2;
    D_801CD45C = func_800D4D90(&D_801B5414[-4], D_801517C0 + 0x70, 0xC, D_801CD45C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B5280) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_search/nonmatchings/text", func_801B022C);

void func_801B05A0(void) {
    MgMat m;
    MgVec v;
    SrObj *p;
    SrObj *q;
    s16 dx;
    s16 dy;
    s16 dz;
    s16 len;
    s16 i;

    p = (SrObj *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            dx = p->unkC - p->unk4;
            D_801B5434.v = dx;
            dy = p->unkE - p->unk6;
            D_801B5436.v = dy;
            dz = p->unk10 - p->unk8;
            D_801B5438.v = dz;
            len = func_80039F5C(dx * dx + dy * dy + dz * dz);
            for (i = 0; i < 4; i++) {
                q = (SrObj *)&D_80162978[func_800BBEAC(&func_801B022C)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unkE = func_8003CC1C((s16)p->unkC - (s16)p->unk4, (s16)p->unk10 - (s16)p->unk8);
                q->unk16 = i;
                q->unk1C = len;
                q->unk14 = len * 0x1500 / 2800;
            }
        }
        if (p->unk2 == 0x10) {
            func_800D5774(p->unk18);
        }
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
            func_800D52A0(0, 0xA);
        }
    }
}

void func_801B07B0(arg0, arg1) {
    MgSVec d;
    SrObj *p;

    p = (SrObj *)&D_80162978[func_800BBEAC(&func_801B05A0)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    d.vx = p->unkC - p->unk4;
    d.vy = p->unkE - p->unk6;
    d.vz = p->unk10 - p->unk8;
    func_800D44E8(&d, D_801B543C);
    p->unk18 = arg0;
}

INCLUDE_RODATA("../asm/us/magic_search/nonmatchings/text", D_801B0020);

void func_801B08B4(arg0, arg1) {
    func_800BBEAC((void *)D_801B0020);
    func_800D2980((void *)D_801B0954, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B07B0);
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    func_800D52A0(0x400, 0xA);
    func_800BBA84(0x62, arg1, 0x40);
}
