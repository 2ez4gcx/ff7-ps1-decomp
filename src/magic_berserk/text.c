#include "common.h"
#include "magic_berserk/decls.h"

void func_801B0018(void) {
    func_801B07D0();
}

void func_801B0038(void) {
    MgMat m;
    MgVec scale;
    u8 pad[0x30];
    MgTask *p;
    u32 t;
    s32 v;
    s16 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = (u16)p->unk2 & 3;
    D_801D1324.v = (t & 1) << 7;
    D_801D1328.v = (t >> 1) | 0x20;
    D_801D132C.vy = (p->unk2 * 0x50) & 0xFFF;
    if (p->unk2 < 0) {
        v = scale.vz = (p->unk2 << 12) / 0;
    } else {
        v = scale.vz = 0x1000;
    }
    scale.vx = scale.vy = v;
    if (p->unk2 < 0xC) {
        c = 0x80;
    } else {
        do {
            c = 0x80 - ((p->unk2 - 0xC) << 7) / 10;
        } while (0);
    }
    do {
        D_801D1326 = c;
    } while (0);
    func_8003B69C(0, 0, 0);
    func_8003C21C(&D_801D132C, &m);
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk8;
    m.t[1] = p->unkA;
    m.t[2] = p->unkC;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801EF334 = func_800D29D4(D_801D131C, D_801517C0 + 0x70, 0xC, D_801EF334);
    if (D_80062D98 == 0) {
        if (++p->unk2 >= 0x16) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_RODATA("../asm/us/magic_berserk/nonmatchings/text", D_801B0000);

void func_801B0228(void) {
    BsSprC t;
    MgTask *p;
    s32 c;

    t = D_801B0000;
    p = (MgTask *)&D_80162978[D_8015169C];
    t.frame = p->unk2 & 3;
    if (p->unk2 < 0xC) {
        c = 0x80;
    } else {
        do {
            c = -0x80 - ((p->unk2 - 0xC) << 7) / 5;
        } while (0);
    }
    do {
        t.r = t.g = t.b = c;
    } while (0);
    func_800D4368(&p->unk8, 0x2500, p->unk18);
    D_801EF334 = func_800D4D90(&t, D_801517C0 + 0x70, 0xC, D_801EF334);
    if (D_80062D98 == 0) {
        if (++p->unk2 >= 0x11) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_RODATA("../asm/us/magic_berserk/nonmatchings/text", D_801B000C);

void func_801B034C(void) {
    BsSpr t;
    MgTask *p;

    t = D_801B000C;
    p = (MgTask *)&D_80162978[D_8015169C];
    t.frame = p->unk2;
    func_800D4368(&p->unk8, 0x1500, 0);
    D_801EF334 = func_800D4D90(&t, D_801517C0 + 0x70, 0xC, D_801EF334);
    if (D_80062D98 == 0) {
        p->unk8 += p->unk10;
        p->unkA += p->unk12;
        p->unkC += p->unk14;
        p->unk12 -= 8;
        if (++p->unk2 >= 0xE) {
            p->unk0 = -1;
        }
    }
}

void func_801B0454(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 r;

    b = (MgTask *)D_80162978;
    p = &b[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &b[func_800BBEAC(&func_801B0038)];
            *(BsB8 *)&q->unk8 = *(BsB8 *)&p->unk8;
            q->unkA = 0;
        }
        if (p->unk2 == 0) {
            q = &b[func_800BBEAC(&func_801B0228)];
            *(BsB8 *)&q->unk8 = *(BsB8 *)&p->unk8;
            q->unk18 = -D_801518F6[p->unk4][0];
        }
        if ((u16)p->unk2 < 8) {
            i = 0;
            do {
                i++;
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B034C)];
                *(BsB8 *)&q->unk8 = *(BsB8 *)&p->unk8;
                q->unkA = 0;
                r = func_80042DA8() & 0xFFF;
                q->unk8 += func_80039A74(r) * 250 >> 12;
                q->unkC += func_80039B40(r) * 250 >> 12;
                q->unk10 = (u32)(func_80039A74(r) * 35) >> 11;
                q->unk14 = (u32)(func_80039B40(r) * 35) >> 11;
                q->unk12 = 0;
            } while (i < 3);
        }
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B06B0(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0454)];
    p->unk6 = arg1;
    p->unk4 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk8);
    func_800D5774(arg0);
    func_800D55F4(0x20, func_800D56A8(D_80151A4C[arg0]), 0x42);
}

void func_801B0764(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EF334 = D_801D1334 + p->unk2 * 0xF000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B07D0(arg0, arg1) {
    s32 t;

    t = (func_800D54BC() >= 4) * 8;
    func_800D2980(&D_801B0858, 0, 0, 0);
    func_800BBEAC(func_801B0764);
    return func_800D5444(arg0, arg1, t, &func_801B06B0);
}
