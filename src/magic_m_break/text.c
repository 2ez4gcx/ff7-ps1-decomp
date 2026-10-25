#include "common.h"
#include "magic_m_break/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0A54();
    return &D_801B0AC4;
}

void func_801B0028(void) {
    MgVec scale;
    MgMat m2;
    MgTask *p;
    s32 *q;
    s32 *r;
    u16 *a;
    u16 *b;
    s32 t;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x16) {
        u8 pad[0x18];
        v = t * 0x1C0 / 22 + 0x40;
        scale.vx = scale.vy = scale.vz = v;
        if (D_80062D98 == 0) {
            a = &D_801B5948;
            b = &D_801B5950;
            *a += 0x280;
            *b -= 0x1C0;
        }
        func_8003C21C(D_801B5944, &D_801B5914);
        func_8003B35C(&D_801B5914, &scale);
        func_8003A63C(&D_800FA6E0[p->unk6], &D_801B5914, &m2);
        func_8003B48C(&m2);
        func_8003B51C(&m2);
        r = &D_801B5938;
        q = r - 1;
        *r = 0;
        D_801D5FE0 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801D5FE0);
        func_8003C21C(D_801B594C, &D_801B5914);
        func_8003B35C(&D_801B5914, &scale);
        func_8003A63C(&D_800FA6E0[p->unk6], &D_801B5914, &m2);
        func_8003B35C(&m2, D_801B5958);
        func_8003B48C(&m2);
        *r = 8;
        D_801D5FE0 = func_800D29D4(q, D_801517C0 + 0x60, 0xC, D_801D5FE0);
        if (t == 0x15) {
            func_800D5138(1);
            goto kill;
        }
    } else {
kill:
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_m_break/nonmatchings/text", func_801B0258);

INCLUDE_ASM("../asm/us/magic_m_break/nonmatchings/text", func_801B0370);

INCLUDE_ASM("../asm/us/magic_m_break/nonmatchings/text", func_801B04E8);

void func_801B09A0(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B04E8)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B09F4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D5FE0 = D_801B5FE0 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0A54(arg0, arg1) {
    func_800D2980(&D_801B1430, 0, 0, 0);
    func_800BBEAC(&func_801B09F4);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B09A0);
}
