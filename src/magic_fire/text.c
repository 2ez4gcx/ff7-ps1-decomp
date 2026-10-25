#include "common.h"
#include "magic_fire/decls.h"

void func_801B0000(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk8, 0x1000, p->unk12);
    frame = &D_801C0600;
    *frame = p->unk2;
    D_801C8604 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801C8604);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0xE) {
            p->unk0 = -1;
        }
    }
}

void func_801B00B8(void) {
    MgTask *p;
    MgTask *q;
    s32 r;
    u8 pad[16];

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_800D5774(p->unk4);
        }
        if (!(p->unk2 & 1)) {
            q = &D_80162978[func_800BBEAC(&func_801B0000)];
            r = (p->unk6 + (func_80042DA8() & 0xF) + 1) % D_801518F4[p->unk4][0];
            p->unk6 = r;
            func_800D3994(p->unk4, r, &q->unk8);
            q->unk12 = p->unk12;
        }
        p->unk2++;
        if (p->unk2 >= 5) {
            p->unk0 = -1;
        }
    }
}

void func_801B0210(s32 arg0) {
    MgTask *q;

    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B00B8)];
    q->unk4 = arg0;
    q->unk6 = 0;
    q->unk12 = -(u16)D_801518F4[arg0][1];
}

void func_801B0294(void) {
    MgTask *p;
    u8 *a;

    a = D_801C4604;
    p = &D_80162978[D_8015169C];
    if (D_800F8368 != 0) {
        a -= 0x4000;
    }
    D_801C8604 = a;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B02EC(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B039C, 0, 0, 0);
    func_800D5444(arg0, arg1, 0, &func_801B0210);
    func_800BBEAC(&func_801B0294);
    func_800D55F4(0x20, func_800D574C(D_80151774), 9);
}

void func_801B037C(void) {
    func_8001C3C4();
}
