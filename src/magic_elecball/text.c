#include "common.h"
#include "magic_elecball/decls.h"

void func_801B0000(void) {
    func_801B0E98();
}

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B0020);

void func_801B00E8(void) {
    MgObjVel *p;
    MgObjVel *q;

    p = (MgObjVel *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        p->unk8.vx += p->unk10.vx;
        p->unk8.vy += p->unk10.vy;
        p->unk8.vz += p->unk10.vz;
        q = (MgObjVel *)&D_80162978[func_800BBEAC(&func_801B0020)];
        q->unk8 = p->unk8;
        p->unk2++;
        if (p->unk2 >= 8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B01C0);

void func_801B02FC(void) {
    MgSVec v;
    u8 pad[8];
    MgMat m;
    MgTask *p;
    s32 t;
    s32 i;
    s32 ang;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        D_801D11C4 = D_801D11C5 = D_801D11C6 = (t << 7) / 5;
    } else {
        t -= 5;
        if (t < 0xF) {
            D_801D11C4 = D_801D11C5 = D_801D11C6 = 0x80;
        } else {
            t -= 0xF;
            if (t >= 5) {
                p->unk0 = -1;
                return;
            }
            D_801D11C4 = D_801D11C5 = D_801D11C6 = -(t << 7) / 5 - 0x80;
        }
    }
    for (i = 0; i < 0x10; i++) {
        ang = i << 8;
        v.vx = (u32)(func_80039A74(ang) * 0x7D) >> 10;
        v.vy = (u32)(func_80039B40(ang) * 0x7D) >> 10;
        v.vz = 0;
        func_8003C21C((MgSVec *)&p->unk10, &m);
        func_8003B2CC(&m, &v, &v);
        v.vx += p->unk8;
        v.vy += p->unkA;
        v.vz += p->unkC;
        func_800D4368(&v, 0x600, p->unk18);
        D_801EF1E4 = func_800D6260(D_801D11BC, D_801517C0 + 0x70, 0xC, D_801EF1E4);
    }
    if (D_80062D98 == 0) {
        p->unk10 += 0x50;
        p->unk12 += 0x40;
        p->unk14 += 0x50;
        p->unk2++;
    }
}

void func_801B0518(void) {
    MgTask *p;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        c = (t << 7) / 5;
        D_801D11D0 = D_801D11D1 = D_801D11D2 = c;
    } else {
        t -= 5;
        if (t < 0x23) {
            c = 0x80;
            D_801D11D0 = D_801D11D1 = D_801D11D2 = c;
        } else {
            t -= 0x23;
            if (t < 5) {
                c = -(t << 7) / 5 - 0x80;
                D_801D11D0 = D_801D11D1 = D_801D11D2 = c;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801D11D4[0] = p->unk2 % 12;
    func_800D4368(&p->unk8, 0x2000, p->unk18);
    D_801EF1E4 = (u8 *)func_800D4D90(&D_801D11D4[-4], D_801517C0 + 0x70, 0xC, (s32)D_801EF1E4);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B0694);

void func_801B0B10(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B0694)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B0B64(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EF1E4 = D_801D11E4 + p->unk2 * 0xF000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B0BD0);

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B0D4C);

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B0E98);
