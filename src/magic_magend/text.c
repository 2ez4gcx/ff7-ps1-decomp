#include "common.h"
#include "magic_magend/decls.h"

void func_801B0000(void) {
    func_801B0448();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C1748 = D_801B1748 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0080(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x200, 0);
    D_801C1748 = (u8 *)func_800D4D90(D_801B1734, D_801517C0 + 0x70, 0xC, (s32)D_801C1748);
    if (D_80062D98 == 0) {
        p->unkE += 3;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (p->unk6 > 0 || D_801B1730 == 1) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0174(void) {
    MgSVec rot;
    MgMat m;
    s32 flag;
    s32 r1, r2, r3;
    s32 t1, t2, t3;
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x38) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0080)];
            func_800D3994(p->unk1E, D_8015190F[p->unk1E][0], &q->unk4);
            r1 = func_80042DA8();
            t1 = (u16)q->unk4 - 0x64;
            q->unk4 = t1 + r1 % 200;
            r2 = func_80042DA8();
            t2 = (u16)q->unk6 - 0x64;
            q->unk6 = t2 + r2 % 200;
            r3 = func_80042DA8();
            t3 = (u16)q->unk8 - 0x64;
            q->unk8 = t3 + r3 % 200;
            rot.vx = func_80042DA8() % 500 + 0x15E;
            rot.vy = func_80042DA8() % 500 - 0xFA;
            rot.vz = 0;
            func_8003C21C(&rot, &m);
            m.t[0] = m.t[1] = m.t[2] = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&D_801B1740, (MgSVec *)&q->unkC, &flag);
        }
        if (++p->unk2 == 0x38) {
            func_800D5774(p->unk1C);
            D_801B1730 = 1;
            p->unk0 = -1;
        }
    }
}

void func_801B03F4(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0174)];
    p->unk1C = arg0;
    p->unk1E = arg1;
}

void func_801B0448(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B04B4, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B03F4);
}
