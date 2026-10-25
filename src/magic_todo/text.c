#include "common.h"
#include "magic_todo/decls.h"

void func_801B0054(void) {
    func_801B04E8();
}

void func_801B0074(void) {
    MgTask *p;
    s32 i;
    s32 n;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_801B6990.v = p->unk2;
    i = p->unk18;
    for (n = 0; n < 4; n++) {
        v = D_801CE9A0[i].s;
        func_800D4368(&D_801CE9A0[i], v, -(v >> 2));
        D_801CE994 = func_800D4D90(&D_801B6988, D_801517C0 + 0x70, 0xC, D_801CE994);
        i++;
        if (i >= 0x1BC) {
            i = 0;
        }
    }
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0190(void) {
    MgTask *p;
    MgTask *q;
    s32 n;
    s32 i;
    s32 r;
    s32 t;

    if (D_80062D98 == 0) {
        p = (MgTask *)&D_80162978[D_8015169C];
        if ((u16)p->unk2 - 2 < 0x1AU) {
            n = D_801CE99C;
            i = 0;
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0074)];
            q->unk18 = n;
            do {
                r = func_80042DA8();
                t = r % 0x1000 + 0x800;
                D_801CE9A0[n].x = (u16)p->unk4 + func_80042DA8() % p->unkE - (u16)p->unkC;
                D_801CE9A0[n].y = -(func_80042DA8() % p->unk10);
                D_801CE9A0[n].z = (u16)p->unk8 + func_80042DA8() % p->unkE - (u16)p->unkC;
                D_801CE9A0[n].s = (p->unk14 * t) >> 12;
                n++;
                if (n >= 0x1BC) {
                    n = 0;
                }
                i++;
            } while (i < 4);
            D_801CE99C = n;
        }
        if (p->unk2 == 0xC) {
            func_800D5774(p->unk18);
        }
        if (p->unk2 >= 0x28) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B03F4(arg0) {
    MgTask *q;
    s32 v;

    q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0190)];
    func_800D3994(arg0, D_8015190F[arg0][0], &q->unk4);
    v = *(s16 *)D_801518F6[arg0] + 0xE0;
    if (v >= 0x4F3) {
        v = 0x4F2;
    }
    q->unkC = v;
    q->unkE = v * 2;
    q->unk18 = arg0;
    q->unk10 = -((u16)q->unk6 * 2);
    q->unk14 = (v << 12) / 450;
}

INCLUDE_RODATA("../asm/us/magic_todo/nonmatchings/text", D_801B0000);

void func_801B04E8(arg0, arg1) {
    D_801CE998 = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(D_801B058C, 0, 0, 0);
    func_800D5444(arg0, arg1, 1, func_801B03F4);
    D_801CE99C = 0;
    func_800D55F4(0x20, func_800D574C(arg0), 0x134);
}
