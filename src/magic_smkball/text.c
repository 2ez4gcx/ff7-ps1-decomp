#include "common.h"
#include "magic_smkball/decls.h"

void func_801B0000(void) {
    func_801B02B0();
}

void func_801B0020(void) {
    MgObj20 *p;
    s32 *t;
    MgHalf *frame;

    p = &D_80162978[D_8015169C];
    t = &D_801B6720;
    *t = p->unk4 * 4;
    D_801B6724 = p->unk6 * 4;
    t = (s32 *)((u8 *)t - 0x14);
    D_801B6728 = func_8003B66C() * 4;
    func_8003B48C(t);
    func_8003B51C(t);
    frame = (MgHalf *)&D_801B6734;
    frame->v = p->unk2;
    D_801D6738 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x4084, 0, D_801D6738);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B6354[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0124(void) {
    MgObj20 *p;
    MgObj20 *q;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x1E) {
            for (i = 0; i < 7; i++) {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0020)];
                q->unk4 = func_80042DA8() % 320 - 0xA0;
                q->unk6 = func_80042DA8() % 166 - 0x78;
            }
        } else {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0250(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D6738 = D_801B6738 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B02B0(void) {
    func_800D2980(&D_801B0310, 0, 0, 0);
    func_800BBEAC(&func_801B0250);
    func_800BBEAC(&func_801B0124);
    func_800D55F4(0x20, 0x40, 0x261);
}
