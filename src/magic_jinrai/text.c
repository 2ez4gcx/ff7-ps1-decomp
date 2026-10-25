#include "common.h"
#include "magic_jinrai/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B02B0();
    return &D_801B3470;
}

void func_801B0028(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    D_801B5228[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801B5228[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801B3354) {
            p->unk0 = -1;
        }
    }
}

void func_801B00E0(void) {
    MgTask *p;
    MgTask *q;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t == 0x16 || t == 0x37) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0028)];
            q->unk4 = p->unkC;
            q->unk6 = p->unkE;
            q->unk8 = p->unk10;
            func_800BBA84(0x155, p->unk1E, 0);
        }
        if (p->unk2 == 0x1E) {
            func_800BBA84(0x30, p->unk1E, 0);
        }
        if (p->unk2 == 0x37) {
            func_800D5774(p->unk1C);
        }
        p->unk2++;
        if (p->unk2 == 0x46) {
            p->unk0 = -1;
        }
    }
}

void func_801B01E4(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B00E0)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    p->unk1E = arg1;
}

void func_801B02B0(arg0, arg1) {
    func_800D2980(&D_801B0310, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B01E4);
}
