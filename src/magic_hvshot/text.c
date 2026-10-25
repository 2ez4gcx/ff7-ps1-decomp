#include "common.h"
#include "magic_hvshot/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B103C();
    return &D_801B10AC;
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
        v = t * 0xE00 / 22 + 0x200;
        scale.vx = scale.vy = scale.vz = v;
        if (D_80062D98 == 0) {
            a = &D_801B52E8;
            b = &D_801B52F0;
            *a += 0x280;
            *b -= 0x1C0;
        }
        func_8003C21C(D_801B52E4, &D_801B52B4);
        func_8003B35C(&D_801B52B4, &scale);
        func_8003A63C(&D_800FA6E0[p->unk6], &D_801B52B4, &m2);
        func_8003B48C(&m2);
        func_8003B51C(&m2);
        r = &D_801B52D8;
        q = r - 1;
        *r = 0;
        D_801D59F8 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801D59F8);
        func_8003C21C(D_801B52EC, &D_801B52B4);
        func_8003B35C(&D_801B52B4, &scale);
        func_8003A63C(&D_800FA6E0[p->unk6], &D_801B52B4, &m2);
        func_8003B35C(&m2, D_801B52F8);
        func_8003B48C(&m2);
        *r = 8;
        D_801D59F8 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801D59F8);
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

INCLUDE_ASM("../asm/us/magic_hvshot/nonmatchings/text", func_801B0258);

INCLUDE_ASM("../asm/us/magic_hvshot/nonmatchings/text", func_801B03C0);

INCLUDE_ASM("../asm/us/magic_hvshot/nonmatchings/text", func_801B0680);

INCLUDE_ASM("../asm/us/magic_hvshot/nonmatchings/text", func_801B07F8);

void func_801B0F88(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B07F8)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B0FDC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D59F8 = D_801B59F8 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B103C(arg0, arg1) {
    func_800D2980(&D_801B1A18, 0, 0, 0);
    func_800BBEAC(&func_801B0FDC);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B0F88);
}
