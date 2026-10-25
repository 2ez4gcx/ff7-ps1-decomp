#include "common.h"
#include "magic_minimam/decls.h"

void func_801B0054(void) {
    func_801B0514();
}

void func_801B0074(void) {
    MgTask *p;
    s32 i;
    s32 n;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_801B48A8.v = p->unk2;
    i = p->unk18;
    for (n = 0; n < 3; n++) {
        v = D_801CC8B8[i].s;
        func_800D4368(&D_801CC8B8[i], v, -(v >> 2));
        D_801CC8AC = func_800D4D90(&D_801B48A0, D_801517C0 + 0x70, 0xC, D_801CC8AC);
        i++;
        if (i >= 0x1BC) {
            i = 0;
        }
    }
    if (p->unk2 >= 7) {
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
            n = D_801CC8B4;
            i = 0;
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0074)];
            q->unk18 = n;
            do {
                r = func_80042DA8();
                t = r % 0x1000 + 0x800;
                D_801CC8B8[n].x = (u16)p->unk4 + func_80042DA8() % p->unkE - (u16)p->unkC;
                D_801CC8B8[n].y = (u16)p->unk6 - func_80042DA8() % p->unk12 + (u16)p->unk10;
                D_801CC8B8[n].z = (u16)p->unk8 + func_80042DA8() % p->unkE - (u16)p->unkC;
                D_801CC8B8[n].s = (p->unk14 * t) >> 12;
                n++;
                if (n >= 0x1BC) {
                    n = 0;
                }
                i++;
            } while (i < 3);
            D_801CC8B4 = n;
        }
        if (p->unk2 == 0x1C) {
            func_800D5774(p->unk18);
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0xB1);
        }
        if (p->unk2 >= 0x23) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0414(arg0) {
    MgTask *q;
    s32 v;
    s32 t;
    s16 h;

    q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0190)];
    func_800D3994(arg0, D_8015190F[arg0][0], &q->unk4);
    v = *(s16 *)D_801518F6[arg0] + 0xE0;
    if (v >= 0x4F3) {
        v = 0x4F2;
    }
    q->unkC = v;
    q->unkE = v * 2;
    q->unk18 = arg0;
    h = q->unk6;
    t = -(h >> 1);
    q->unk10 = t;
    q->unk12 = t * 4;
    q->unk14 = (v << 12) / 540;
}

INCLUDE_RODATA("../asm/us/magic_minimam/nonmatchings/text", D_801B0000);

void func_801B0514(arg0, arg1) {
    D_801CC8B0 = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(D_801B05B8, 0, 0, 0);
    func_800D5444(arg0, arg1, 1, func_801B0414);
    D_801CC8B4 = 0;
    func_800D55F4(0x20, func_800D574C(arg0), 0x134);
}
