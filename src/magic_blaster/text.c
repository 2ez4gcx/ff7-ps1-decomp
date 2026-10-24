#include "common.h"
#include "magic_blaster/decls.h"

void func_801B0000(void) {
    func_801B19DC();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E9A0C = D_801D9A0C + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_blaster/nonmatchings/text", func_801B0080);

INCLUDE_ASM("../asm/us/magic_blaster/nonmatchings/text", func_801B01C0);

INCLUDE_ASM("../asm/us/magic_blaster/nonmatchings/text", func_801B030C);

INCLUDE_ASM("../asm/us/magic_blaster/nonmatchings/text", func_801B0654);

INCLUDE_ASM("../asm/us/magic_blaster/nonmatchings/text", func_801B0778);

INCLUDE_ASM("../asm/us/magic_blaster/nonmatchings/text", func_801B08FC);

INCLUDE_ASM("../asm/us/magic_blaster/nonmatchings/text", func_801B0BC4);

INCLUDE_ASM("../asm/us/magic_blaster/nonmatchings/text", func_801B0F50);

void func_801B116C(void) {
    MgTask *p;
    MgMat m;
    MgMat lw;
    MgVec scale;
    s32 t;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801D99A8, &m);
    func_8003A79C(&D_801D99EC, &m, &m);
    scale.vx = scale.vy = scale.vz = p->unk2 * 1500;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801D99BA[0] = t << 8;
    D_801E9A0C = func_800D29D4(&D_801D99BA[-5], D_801517C0 + 0x70, 0xC, D_801E9A0C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_blaster/nonmatchings/text", func_801B12C8);

INCLUDE_ASM("../asm/us/magic_blaster/nonmatchings/text", func_801B18D8);

INCLUDE_ASM("../asm/us/magic_blaster/nonmatchings/text", func_801B19DC);
