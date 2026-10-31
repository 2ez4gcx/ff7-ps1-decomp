#include "common.h"
#include "magic_bioga1/decls.h"

void func_801B0000(void) {
    func_801B0C8C();
}

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B03B0);

void func_801B0600(void) {
    MgTask *p;
    s16 *frame;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        *(s32 *)&D_801E1CEC = 0x2C808080;
    } else {
        t -= 10;
        if (t < 10) {
            D_801E1CEF = 0x2E;
            c = -(t << 7) / 10 - 0x80;
            D_801E1CEC = D_801E1CED = D_801E1CEE = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    frame = &D_801E1CF0;
    *frame = p->unk2 % 7;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801EDEF4 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EDEF4);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unkA -= p->unk12;
    }
}

void func_801B0778(void) {
    MgTask *p;
    MgTask *q;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0600)];
        q->unk8 = p->unk8 + ((func_80042DA8() % 2000 - 0x3E8) * p->unk10 >> 12);
        q->unkA = 0;
        q->unkC = p->unkC + ((func_80042DA8() % 2000 - 0x3E8) * p->unk10 >> 12);
        v = (func_80042DA8() % 2560 + 0x1000) * p->unk10 >> 12;
        if (v > 0x7FFF) {
            v = 0x7FFF;
        }
        q->unk10 = v;
        q->unk12 = func_80042DA8() % 140 + 10;
        if (++p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0958(void) {
    MgTask *p;
    MgTask *q;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B03B0)];
            *(MgB8 *)&q->unk8 = *(MgB8 *)&p->unk8;
            q->unk10 = p->unk10;
        }
        if ((u16)p->unk2 < 8) {
            if ((p->unk2 & 1) == 0) {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0020)];
                q->unk0 = p->unk2 / 2;
                q->unk8 = p->unk8 + func_80042DA8() % 0x800 - 0x400;
                q->unkA = p->unkA + func_80042DA8() % 0x800 - 0x400;
                q->unkC = p->unkC + func_80042DA8() % 0x800 - 0x400;
                q->unk10 = p->unk10;
            }
        }
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0778)];
            *(MgB8 *)&q->unk8 = *(MgB8 *)&p->unk8;
            q->unk10 = p->unk10;
        }
        k = p->unk2;
        if (k == 0x1E) {
            func_800D5774(p->unk4);
            if (p->unk2 == k) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0B94(s32 arg0) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B0958)];
    p->unk4 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk8);
    p->unk10 = func_800D55A4(arg0);
}

void func_801B0C24(void) {
    MgTask *p;
    u8 *buf;

    p = &D_80162978[D_8015169C];
    buf = D_801B0DA4;
    if (p->unk2 == 0) {
        buf = D_801E1EF4;
    }
    D_801EDEF4 = buf;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0C8C(arg0, arg1) {
    s32 i;
    s32 j;
    s32 k;
    u16 *tbl;

    func_800BBEAC(func_801B0C24);
    if (D_801517BC == 0) {
        tbl = D_801B0E38;
        for (i = 0; i < 0xF; i++) {
            D_801E1CF4[i][0] = 0;
            for (j = 1; j < 0x10; j++) {
                k = j - i;
                if (k >= 2) {
                    D_801E1CF4[i][j] = tbl[k];
                } else {
                    D_801E1CF4[i][j] = tbl[1];
                }
            }
        }
        func_800D2980(D_801B0DA4, 0, 0, 0);
    }
    func_800D5444(arg0, arg1, 0, func_801B0B94);
    func_800D55F4(0x20, func_800D574C(arg0), 0x5A);
}
