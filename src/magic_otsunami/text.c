#include "common.h"
#include "magic_otsunami/decls.h"

void func_801B0000(void) {
    func_801B0BC8();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D8F8C = D_801C0F8C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk1A == 0 ? 0x1800 : 0x2800, 0);
    D_801C0F7C[0] = p->unk2;
    *(MgGesuiAnim **)&D_801C0F7C[-4] = D_801C0F80[p->unk1A];
    D_801D8F8C = func_800D4D90(&D_801C0F7C[-4], D_801517C0 + 0x70, 0xC, D_801D8F8C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801C0F80[p->unk1A]->unk4) {
            p->unk0 = -1;
        }
    }
}

void func_801B018C(u8 *arg0, u8 *arg1) {
    if (*arg0 == 0) {
        *arg0 = 0xFF;
    } else {
        *arg0 = -*arg0;
    }
    if (*arg1 == 0xFF) {
        *arg1 = 0;
    } else {
        *arg1 = -*arg1;
    }
}

s32 func_801B01DC(s32 arg0, s16 arg1) {
    s32 t;
    u8 pad[8];

    if ((u16)arg0 > 0x800) {
        arg0 = 0;
    }
    do {
        t = -D_801D8F90[(s16)arg0] * 625;
    } while (0);
    return (D_801D9190[arg1][0] * ((t * 64) >> 16) * 0x10) >> 16;
}

INCLUDE_ASM("../asm/us/magic_otsunami/nonmatchings/text", func_801B0270);

void func_801B07CC(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_800F5B70 = D_800F5B71 = D_800F5B72 = 0;
            func_800D52A0(0x1000, 4);
        }
        if (p->unk2 == 0x14) {
            func_800D52A0(0, 8);
        }
        if (p->unk2 == 0) {
            func_800BBEAC((void *)func_801B0270);
        }
        if ((u16)p->unk2 - 0x25 < 7U) {
            for (i = 0; i < 10; i++) {
                if ((D_801DAF90 >> i) & 1) {
                    k = i;
                    q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B008C)];
                    func_800D3994(k, D_8015190F[k][0], &q->unk4);
                    q->unk4 = q->unk4 + (func_80042DA8() % 600 - 0x12C);
                    q->unk6 = q->unk6 + (func_80042DA8() % 600 - 0x12C);
                    q->unk8 = q->unk8 + (func_80042DA8() % 600 - 0x12C);
                    q->unk1A = 1;
                    q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B008C)];
                    func_800D3994(k, D_8015190F[k][0], &q->unk4);
                    q->unk4 = q->unk4 + (func_80042DA8() % 1400 - 0x2BC);
                    q->unk6 = q->unk6 + (func_80042DA8() % 1400 - 0x2BC);
                    q->unk8 = q->unk8 + (func_80042DA8() % 1400 - 0x2BC);
                    q->unk1A = 0;
                }
            }
        }
        if (p->unk2 == 0x28) {
            for (i = 0; i < 10; i++) {
                if ((D_801DAF90 >> i) & 1) {
                    func_800D5774(i);
                }
            }
        }
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B0BC8(arg0, arg1) {
    MgTask *p;
    s16 i;
    s32 t;

    func_800BBEAC((void *)func_801B0020);
    func_800D2980(&D_801B0D20, 0, 0, 0);
    D_801DAF90 = arg0;
    for (i = 0; i < 0x1000; i++) {
        D_801D8F90[i] = func_80039A74(i);
    }
    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B07CC)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D54EC(arg0, &p->unkC);
    if (p->unk8 > p->unk10) {
        t = D_801C0F70;
        D_801C0F70 = -t;
    }
    return func_800BBA84(0x132, arg1, 0x40);
}
