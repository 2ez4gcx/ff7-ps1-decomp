#include "common.h"
#include "magic_zenbaku/decls.h"

void func_801B0054(void) {
    func_801B0860();
}

void func_801B0074(void) {
    MgTask *p;
    s32 i;
    s32 j;
    s16 v;

    p = &D_80162978[D_8015169C];
    D_801C1100.v = p->unk2;
    j = p->unk18 * 8;
    for (i = 0; i < 1; i++) {
        v = *(u16 *)(D_801D9126 + j);
        func_800D4368(D_801D9120 + j, v, -(v >> 4));
        j += 8;
        D_801D9110 = func_800D4D90(&D_801C10F8, D_801517C0 + 0x70, 0xC, D_801D9110);
        if (j >= 0xDE0) {
            j = 0;
        }
    }
    if (p->unk2 >= 0xF) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B018C(void) {
    MgTask *p;
    s32 i;
    s32 j;
    s16 v;

    p = &D_80162978[D_8015169C];
    D_801C110C.v = p->unk2;
    j = p->unk18 * 8;
    for (i = 0; i < 1; i++) {
        v = *(u16 *)(D_801D9126 + j);
        func_800D4368(D_801D9120 + j, v, -(v >> 4));
        j += 8;
        D_801D9110 = func_800D4D90(&D_801C1104, D_801517C0 + 0x70, 0xC, D_801D9110);
        if (j >= 0xDE0) {
            j = 0;
        }
    }
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B02A4(void) {
    u8 pad[16];
    MgTask *p;
    MgTask *q;
    s32 n;
    s32 i;
    s32 cnt;
    s32 scale;
    s32 j;
    s32 t;

    if (D_80062D98 == 0) {
        q = D_80162978;
        p = &q[D_8015169C];
        if ((u32)((u16)p->unk2 - 2) < 0x23) {
            n = D_801D911C;
            i = 0;
            q[func_800BBEAC(&func_801B0074)].unk18 = n;
            scale = (p->unk14 << 12) / 180;
            cnt = (func_80042DA8() & 1) + 1;
            if (cnt != 0) {
                j = n * 8;
                do {
                    n++;
                    t = func_80042DA8() % 5120 + 0x800;
                    *(u16 *)(D_801D9120 + j) = p->unk4 + func_80042DA8() % p->unkE - p->unkC;
                    *(u16 *)(D_801D9120 + j + 2) = p->unk6 - func_80042DA8() % p->unk12 + p->unk10;
                    *(u16 *)(D_801D9124 + j) = p->unk8 + func_80042DA8() % p->unkE - p->unkC;
                    *(u16 *)(D_801D9126 + j) = (scale * t) >> 12;
                    j += 8;
                    if (n >= 0x1BC) {
                        j = 0;
                        n = 0;
                    }
                    i++;
                } while (i < cnt);
            }
            i = 0;
            D_80162990[func_800BBEAC(&func_801B018C)].unk0 = n;
            scale = (p->unk14 << 12) / 200;
            cnt = (func_80042DA8() & 1) + 1;
            if (cnt != 0) {
                j = n * 8;
                do {
                    n++;
                    t = func_80042DA8() % 4352 + 0x700;
                    *(u16 *)(D_801D9120 + j) = p->unk4 + func_80042DA8() % p->unkE - p->unkC;
                    *(u16 *)(D_801D9120 + j + 2) = p->unk6 - func_80042DA8() % p->unk12 + p->unk10;
                    *(u16 *)(D_801D9124 + j) = p->unk8 + func_80042DA8() % p->unkE - p->unkC;
                    *(u16 *)(D_801D9126 + j) = (scale * t) >> 12;
                    j += 8;
                    if (n >= 0x1BC) {
                        j = 0;
                        n = 0;
                    }
                    i++;
                } while (i < cnt);
            }
            D_801D911C = n;
            if (!((u16)p->unk2 & 1)) {
                func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x7C);
            }
        }
        if (p->unk2 == 0x2C) {
            i = 0;
            do {
                if ((1 << i) & D_801D9118) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
        }
        if (p->unk2 >= 0x34) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B07A4(void) {
    MgTask *p;
    s32 t;
    MgTask *q;

    D_80162978[D_8015169C].unk0 = -1;
    q = D_80162978;
    p = &q[func_800BBEAC(&func_801B02A4)];
    func_800D54EC(D_801D9118, &p->unk4);
    p->unk6 = -0x540;
    p->unkC = 0x9A0;
    p->unkE = 0x1340;
    p->unk14 = 0x380;
    t = -(p->unk6 >> 1);
    p->unk10 = t;
    p->unk12 = t * 3;
    p->unk10 = (u16)p->unk10 * 2;
}

INCLUDE_RODATA("../asm/us/magic_zenbaku/nonmatchings/text", D_801B0000);

void func_801B0860(arg0) {
    D_801D9114 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B08E4, 0, 0, 0);
    func_800BBEAC(&func_801B07A4);
    D_801D9118 = arg0;
    D_801D911C = 0;
}
