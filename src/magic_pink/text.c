#include "common.h"
#include "magic_pink/decls.h"

void func_801B0000(void) {
    func_801B11D4();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E1BD0 = D_801C9BD0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, 0);
    D_801C9B58[0] = p->unk2;
    D_801E1BD0 = func_800D4D90(&D_801C9B58[-4], D_801517C0 + 0x70, 0xC, D_801E1BD0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C9A28) {
            p->unk0 = -1;
        }
    }
}

MgObj8 *func_801B0148(void) {
    s16 i;

    for (i = 0; i < 200; i++) {
        if (D_801E1BD8[i].unk0 == 0) {
            D_801E1BD8[i].unk0 = 1;
            D_801E1BD8[i].unk6 = 0;
            return &D_801E1BD8[i];
        }
    }
    return NULL;
}

void func_801B01C8(MgTask *p) {
    MgSVec rot;
    MgSVec pt;
    MgMat m;
    s32 flag;
    s16 i;
    s16 k;

    rot.vx = rot.vz = 0;
    rot.vy = p->unk14;
    func_8003C21C(&rot, &m);
    m.t[0] = m.t[1] = m.t[2] = 0;
    for (i = 0; i < 200; i++) {
        if (D_801E1BD8[i].unk0 != 0) {
            pt.vx = ((func_80039B40(D_801E1BD8[i].unk4) * D_801E1BD8[i].unk2 * D_801E1BD8[i].unk6) / 20 * (p->unk1A + 0x100)) >> 20;
            pt.vy = ((func_80039A74(D_801E1BD8[i].unk4) * D_801E1BD8[i].unk2 * D_801E1BD8[i].unk6) / 20 * (p->unk1A + 0x100)) >> 20;
            pt.vz = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&pt, &pt, &flag);
            pt.vx += p->unk4 + p->unkC * D_801E1BD8[i].unk6;
            pt.vy += p->unk6 + p->unkE * D_801E1BD8[i].unk6;
            pt.vz += p->unk8 + p->unk10 * D_801E1BD8[i].unk6;
            if (D_801E1BD8[i].unk6 >= 0x11) {
                k = 0x19 - D_801E1BD8[i].unk6;
            } else {
                k = 8;
            }
            func_800D4368(&pt, (s16)(D_801E1BD8[i].unk6 * 0x40 + 0x800), 0);
            D_801C9B60[0] = D_801C9B60[1] = D_801C9B60[2] = k << 4;
            D_801E1BD0 = func_800D4D90(&D_801C9B60[-4], D_801517C0 + 0x70, 0xC, D_801E1BD0);
        }
    }
}

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B04EC);

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B06D4);

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B0884);

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B09DC);

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B0C94);

void func_801B1030(void) {
    MgObj20 *q;
    MgObj20 *p;

    q = D_801E2218;
    D_801E34D8 = 0;
    p = &D_80162978[D_8015169C];
    do {
        if (q->unk0 == 1) {
            func_801B0884();
            if (q->unk0 == -1) {
                q->unk2 = 0;
                q->unk0 = 0;
            }
        }
        D_801E34D8++;
        q++;
    } while ((s16)D_801E34D8 < 0x96);
    if (D_801C9B4C == 1) {
        p->unk0 = -1;
    }
}

void func_801B110C(void) {
    MgObj20 *p;
    s16 i;

    p = D_801E2218;
    for (i = 0; i < 150; i++) {
        p->unk2 = 0;
        p->unk0 = 0;
        p++;
    }
    func_800BBEAC(&func_801B1030);
}

s32 func_801B1164(void) {
    MgObj20 *p;
    s16 i;

    p = D_801E2218;
    for (i = 0; i < 150; i++) {
        if (p->unk0 == 0) {
            p->unk0 = 1;
            return i;
        }
        p++;
    }
    return func_800BBA84(6, -1, 0x40);
}

INCLUDE_ASM("../asm/us/magic_pink/nonmatchings/text", func_801B11D4);
