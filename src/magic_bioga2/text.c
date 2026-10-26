#include "common.h"
#include "magic_bioga2/decls.h"

void func_801B0000(void) {
    func_801B0AB8();
}

INCLUDE_ASM("../asm/us/magic_bioga2/nonmatchings/text", func_801B0020);

void func_801B0328(void) {
    MgTask *p;
    s32 t;
    s32 c;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xA) {
        *(s32 *)&D_801E37D4 = 0x2C808080;
    } else {
        t -= 0xA;
        if (t < 0xF) {
            D_801E37D7 = 0x2E;
            c = -(t << 7) / 15 - 0x80;
            D_801E37D4 = D_801E37D5 = D_801E37D6 = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    D_801E37D8[0] = p->unk2 % 7;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801EF7F4 = (u8 *)func_800D4D90(&D_801E37D8[-4], D_801517C0 + 0x70, 0xC, (s32)D_801EF7F4);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unkA -= p->unk12;
    }
}

void func_801B04A4(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    frame = &D_801E37E4;
    *frame = p->unk2;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801EF7F4 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EF7F4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B0564(void) {
    MgTask *p;
    MgTask *q;
    s32 n;
    s32 r0;
    s32 r1;
    s32 r2;
    s32 t0;
    s32 t1;
    s32 t2;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = p->unk2;
        if (n < 0x19) {
            if (!(n & 1)) {
                q = &D_80162978[func_800BBEAC(func_801B04A4)];
                func_800D3994(p->unk4, D_8015190F[p->unk4][0], &q->unk8);
                r0 = func_80042DA8();
                t0 = (u16)q->unk8 - 0x1F4;
                q->unk8 = t0 + r0 % 1000;
                r1 = func_80042DA8();
                t1 = (u16)q->unkA - 0x1F4;
                q->unkA = t1 + r1 % 1000;
                r2 = func_80042DA8();
                t2 = (u16)q->unkC - 0x1F4;
                q->unkC = t2 + r2 % 1000;
                q->unk10 = func_80042DA8() % 0x1000 + 0x1000;
            }
        } else {
            p->unk0 = -1;
            return;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_bioga2/nonmatchings/text", func_801B0734);

void func_801B0A50(void) {
    MgTask *p;
    u8 *buf;

    p = &D_80162978[D_8015169C];
    buf = D_801B0B50;
    if (p->unk2 == 0) {
        buf = D_801E37F4;
    }
    D_801EF7F4 = buf;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0AB8(arg0) {
    if (D_801517BC == 0) {
        func_800D2980(D_801B0B50, 0, 0, 0);
        func_800D2980(D_801B7BB0, 0, 0, 0);
    }
    func_800BBEAC(func_801B0A50);
    D_801E37F0 = arg0;
    func_800D54EC(arg0, D_801E37E8);
    func_800BBEAC(func_801B0734);
}
