#include "common.h"
#include "magic_bio/decls.h"

void func_801B0000(void) {
    MgTask *p;
    s16 *frame;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        *(s32 *)&D_801B7874 = 0x2C808080;
    } else {
        t -= 10;
        if (t < 10) {
            D_801B7877 = 0x2E;
            c = -(t << 7) / 10 - 0x80;
            D_801B7874 = D_801B7875 = D_801B7876 = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    frame = &D_801B7878;
    *frame = p->unk2 % 7;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801D7888 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801D7888);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unkA -= p->unk12;
    }
}

void func_801B0178(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    frame = &D_801B7884;
    *frame = p->unk2;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801D7888 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801D7888);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B0238(void) {
    MgTask *p;
    MgTask *q;
    s32 r;
    s32 c;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((u16)p->unk2 < 0xF && !(p->unk2 & 3)) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0000)];
            r = func_80042DA8();
            c = 0x1F4;
            q->unk8 = p->unk8 - c + r % 1000;
            q->unkA = 0;
            q->unkC = p->unkC - c + func_80042DA8() % 1000;
            q->unk10 = func_80042DA8() % 1280 + 0x1000;
            q->unk12 = func_80042DA8() % 90 + 0x3C;
        }
        if ((u16)p->unk2 < 0xF && !(p->unk2 & 1)) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0178)];
            q->unk8 = p->unk8 + func_80042DA8() % 800 - 0x190;
            q->unkA = p->unkA + func_80042DA8() % 800 - 0x190;
            q->unkC = p->unkC + func_80042DA8() % 800 - 0x190;
            q->unk10 = func_80042DA8() % 2304 + 0x700;
        }
        if (p->unk2 == 0xF) {
            func_800D5774(p->unk4);
            if (p->unk2 == 0xF) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0554(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0238)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk8);
}

void func_801B05E0(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D7888 = D_801B7888 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0640(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B06C8, 0, 0, 0);
    func_800BBEAC(&func_801B05E0);
    func_800D5444(arg0, arg1, 0, &func_801B0554);
    func_800D55F4(0x20, func_800D574C(arg0), 0x3F);
}
