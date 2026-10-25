#include "common.h"
#include "magic_ayasii/decls.h"

void func_801B0054(void) {
    func_801B04E4();
}

void func_801B0074(void) {
    MgTask *p;
    s32 i;
    s32 j;
    s16 v;

    p = &D_80162978[D_8015169C];
    D_801B6988.v = p->unk2;
    j = p->unk18 * 0x10;
    for (i = 0; i < 4; i++) {
        v = *(u16 *)(D_801CE9A4 + j);
        func_800D4368(D_801CE99C + j, v, -(v >> 2));
        j += 0x10;
        D_801CE98C = func_800D4D90(D_801B6980, D_801517C0 + 0x70, 0xC, D_801CE98C);
        if (j >= 0xDE0) {
            j = 0;
        }
    }
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0190(void) {
    MgTask *p;
    MgTask *q;
    s32 r;
    s32 t;
    s32 v;
    s32 i;
    s32 j;
    s32 k;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if ((u32)((u16)p->unk2 - 2) < 0x1F) {
            k = D_801CE998;
            i = 0;
            j = k * 0x10;
            q = &D_80162978[func_800BBEAC((void *)func_801B0074)];
            q->unk18 = k;
            do {
                r = func_80042DA8();
                t = r;
                if (r < 0) {
                    t = r + 0xFFF;
                }
                v = r - ((t >> 12) << 12) + 0x800;
                *(s16 *)(D_801CE99C + j) = p->unk4 + func_80042DA8() % p->unkE - p->unkC;
                k++;
                *(s16 *)(D_801CE99C + 2 + j) = p->unk6 - func_80042DA8() % p->unk12 + p->unk10;
                *(s16 *)(D_801CE9A0 + j) = p->unk8 + func_80042DA8() % p->unkE - p->unkC;
                *(s16 *)(D_801CE9A4 + j) = p->unk14 * v >> 12;
                j += 0x10;
                if (k >= 0xDE) {
                    j = 0;
                    k = 0;
                }
                i++;
            } while (i < 4);
            D_801CE998 = k;
        }
        if (p->unk2 == 0x28) {
            for (i = 0; i < 10; i++) {
                if ((1 << i) & D_801CE994) {
                    func_800D5774(i);
                }
            }
        }
        if (p->unk2 >= 0x30) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0428(void) {
    MgTask *p;
    MgTask *base;
    s32 t;
    s32 n;

    D_80162978[D_8015169C].unk0 = -1;
    n = func_800BBEAC((void *)func_801B0190);
    base = D_80162978;
    p = base + n;
    func_800D54EC(D_801CE994, &p->unk4);
    p->unk6 = -0x540;
    p->unkC = 0x8C0;
    p->unkE = 0x1180;
    p->unk14 = 0x27D2;
    t = (s16)*(u16 *)&p->unk6 >> 1;
    p->unk10 = -t;
    p->unk12 = -t * 3;
    p->unk10 = *(u16 *)&p->unk10 * 2;
}

INCLUDE_RODATA("../asm/us/magic_ayasii/nonmatchings/text", D_801B0000);

void func_801B04E4(arg0) {
    D_801CE990 = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(D_801B0584, 0, 0, 0);
    func_800BBEAC(func_801B0428);
    D_801CE994 = arg0;
    D_801CE998 = 0;
    func_800D55F4(0x20, func_800D574C(arg0), 0xA2);
}
