#include "common.h"
#include "magic_echoes/decls.h"

void func_801B0000(void) {
    func_801B0404();
}

void func_801B0020(void) {
    MgTask *p;
    MgMat *m;

    p = (MgTask *)&D_80162978[D_8015169C];
    m = func_800D4368(&p->unk4, p->unk10, p->unk12);
    m->t[0] = p->unkC + m->t[0];
    m->t[1] = p->unkE + m->t[1];
    func_8003B51C(m);
    D_801B6878[0] = p->unk2;
    D_801D687C = (u8 *)func_800D4D90(&D_801B6878[-4], D_801517C0 + 0x70, 0xC, (s32)D_801D687C);
    if (D_80062D98 == 0) {
        if (++p->unk2 >= D_801B64B8.v) {
            p->unk0 = -1;
        }
    }
}

void func_801B0108(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 a;
    s32 v;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 0xF) {
            for (i = 0; i < 7; i++) {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0020)];
                *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
                a = func_80042DA8() & 0x7FF;
                if (a < 0x400) {
                    v = func_80039A74(a) - 0x1000;
                } else {
                    v = 0x1000 - func_80039A74(a);
                }
                q->unkC = (p->unkC * v) >> 12;
                a = func_80042DA8() & 0x7FF;
                if (a < 0x400) {
                    v = func_80039A74(a) - 0x1000;
                } else {
                    v = 0x1000 - func_80039A74(a);
                }
                q->unkE = (p->unkE * v) >> 12;
                r = func_80042DA8();
                q->unk10 = r % 0x1000 + 0x2000;
                q->unk12 = p->unk12;
            }
        } else {
            func_800D5774(p->unk0);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B02BC(arg0) {
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B0108)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    p->unkC = p->unkE = (u32)(D_801518F6[arg0][0] * 3) >> 1;
    t = D_801518F6[arg0][0];
    p->unk12 = -t;
    func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x134);
}

void func_801B03A4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D687C = D_801B687C + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0404(arg0, arg1) {
    func_800D2980(&D_801B0474, 0, 0, 0);
    func_800BBEAC(&func_801B03A4);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B02BC);
}
