#include "common.h"
#include "magic_heatbu/decls.h"

void func_801B0054(void) {
    func_801B06CC();
}

void func_801B0074(void) {
    MgTask *p;
    s16 t;
    u8 c;
    s16 v;
    MgByte *q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t >= 10) {
        c = -0x80 - (t - 10) * 16;
    } else {
        c = 0x80;
    }
    q = &D_801C09E4;
    q->v = D_801C09E5.v = D_801C09E6.v = c;
    v = p->unk14;
    func_800D4368(&p->unk4, v, -(v >> 2));
    D_801D89EC = func_800D4D90(q - 4, D_801517C0 + 0x70, 0xC, D_801D89EC);
    if (p->unk2 >= 0x12) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x11) {
            p->unk4 += p->unkC;
            p->unk8 += p->unk10;
        }
        if (p->unk2 >= 7) {
            p->unk6 += p->unkE;
            if (p->unk2 >= 0x10) {
                p->unkE >>= 1;
            }
        }
        if (p->unk2 < 0xB) {
            p->unk14 += p->unk16;
        }
        p->unk2++;
    }
}

void func_801B0214(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 mask;
    s32 x;
    s32 y;
    s32 z;
    s32 r;
    s32 t;
    s16 v;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if ((u16)p->unk2 - 2 < 0x1FU) {
            for (i = 0; i < 1; i++) {
                q = &D_80162978[func_800BBEAC(&func_801B0074)];
                *(MgSVec *)&q->unk4 = D_801D89FC;
                x = p->unk4 + func_80042DA8() % p->unkE - p->unkC;
                y = p->unk6 - func_80042DA8() % p->unk12 + p->unk10;
                z = p->unk8 + func_80042DA8() % p->unkE - p->unkC;
                q->unkC = (x - D_801D89FC.vx) / 17;
                q->unkE = (y - D_801D89FC.vy) / 9;
                q->unk10 = (z - D_801D89FC.vz) / 17;
                if (q->unkE > 0) {
                    q->unkE = -q->unkE;
                }
                q->unk14 = 0;
                r = func_80042DA8();
                t = r % 0x1000 + 0x800;
                q->unk16 = ((p->unk14 * t) >> 12) / 11;
            }
        }
        if (p->unk2 < 8) {
            D_800F5B70.v = 0x20;
            D_800F5B72.v = 0;
            D_800F5B71.v = 0;
            v = p->unk2 * 0x140;
        } else {
            v = 0xA00;
            if (p->unk2 >= 0x2F) {
                v = 0xA00 - (p->unk2 - 0x2F) * 0x140;
                if (v < 0) {
                    v = 0;
                }
            }
        }
        if (p->unk2 == 0x2D) {
            i = 0;
            mask = 1;
            for (; i < 10; i++) {
                if (mask << i & D_801D89F4) {
                    func_800D5774(i);
                }
            }
        }
        if (p->unk2 >= 0x37) {
            v = 0;
            func_800D55F4(0x20, func_800D574C(D_801D89F4), 0);
            D_800F5B70.v = 0;
            p->unk0 = -1;
        }
        D_800F5B74.v = v;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_heatbu/nonmatchings/text", func_801B05CC);

INCLUDE_RODATA("../asm/us/magic_heatbu/nonmatchings/text", D_801B0000);

s32 func_801B06CC(arg0, arg1) {
    D_801D89F0 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B0774, 0, 0, 0);
    func_800BBEAC(&func_801B05CC);
    D_801D89F4 = arg0;
    D_801D89F8 = arg1;
    return func_800D55F4(0x20, func_800D574C(arg0), 0x165);
}
