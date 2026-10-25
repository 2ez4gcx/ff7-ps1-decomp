#include "common.h"
#include "magic_tears/decls.h"

void func_801B0000(void) {
    func_801B03E4();
}

void func_801B0020(void) {
    MgTask *p;
    s32 v;
    s32 a;
    s32 b;

    p = (MgTask *)&D_80162978[D_8015169C];
    v = p->unk2;
    if (v < 5) {
        D_801B0458 = D_801B0459 = D_801B045A = (v << 7) / 5;
    } else {
        *(u32 *)&D_801B0458 = 0x2E808080;
    }
    func_800D4368(&p->unk4, p->unk14, 0);
    a = p->unk2;
    b = p->unk0;
    D_801B0454[0] = ((a + b) & 7) << 5;
    D_801D0460 = (u8 *)func_800D6260(&D_801B0454[-4], D_801517C0 + 0x70, 0xC, (s32)D_801D0460);
    if (D_80062D98 == 0) {
        p->unk6 += p->unkE;
        p->unk2++;
        p->unkE = p->unkE;
        if (p->unk6 > 0) {
            p->unk0 = -1;
        }
    }
}

void func_801B0158(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 a;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        if (p->unk2 < 0x1E) {
            do {
                i++;
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0020)];
                a = func_80042DA8() & 0xFFF;
                r = func_80042DA8() % 1000;
                q->unk4 = (u16)p->unk4 + ((func_80039A74(a) * r) >> 12);
                q->unk6 = func_80042DA8() % 100 - 0x834;
                q->unk8 = (u16)p->unk8 + ((func_80039B40(a) * r) >> 12);
                q->unkE = 0x64;
                q->unk14 = 0x1000;
                q->unk0 = func_80042DA8() & 7;
            } while (i < 3);
        } else {
            func_800D5774(p->unk0);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0304(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0158)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

void func_801B0384(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D0460 = D_801B0460 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B03E4(arg0, arg1) {
    func_800BBEAC(func_801B0384);
    func_800D5444(arg0, arg1, 0, func_801B0304);
    return func_800D55F4(0x20, func_800D574C(arg0), 0x11E);
}
