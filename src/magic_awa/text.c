#include "common.h"
#include "magic_awa/decls.h"

void func_801B0000(void) {
    func_801B1128();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E1EA8 = D_801C9EA8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, 0);
    D_801C9830[0] = p->unk2;
    D_801E1EA8 = func_800D4D90(&D_801C9830[-4], D_801517C0 + 0x70, 0xC, D_801E1EA8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C9704) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_awa/nonmatchings/text", func_801B0148);

void func_801B0458(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    func_800D4368((u8 *)&temp_s0->unk4, D_801C9836, -0x3E8);
    func_801B0148(8, M2C_SFIELD(temp_s0, s16 *, 0x16), 0x100, D_801C9834);
    M2C_SFIELD(temp_s0, s16 *, 0x16) = (s16) ((u16) M2C_SFIELD(temp_s0, s16 *, 0x16) + 0x100);
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 < 0xF) {
            D_801C9834 = (u16) D_801C9834 + 0x10;
        }
        if (temp_s0->unk2 >= 0x21) {
            D_801C9836 = (u16) D_801C9836 - 0x12C;
            D_801C9834 = (u16) D_801C9834 - 0x1E;
        }
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 == 0x28) {
            temp_s0->unk0 = -1;
        }
    }
}

MgObj8 *func_801B0560(void) {
    s16 i;

    for (i = 0; i < 200; i++) {
        if (D_801C9868[i].unk0 == 0) {
            D_801C9868[i].unk0 = 1;
            D_801C9868[i].unk6 = 0;
            return &D_801C9868[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_awa/nonmatchings/text", func_801B05E0);

INCLUDE_ASM("../asm/us/magic_awa/nonmatchings/text", func_801B0904);

void func_801B0B04(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 *frame;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    p->unkC = -p->unk2 << 7;
    func_8003C21C((MgSVec *)&p->unkC, &m);
    D_801C984C[0] = p->unk18;
    t = (p->unk1A + 0x100) * 0x1A;
    D_801C9850 = t;
    D_801C984C[-1] = t;
    func_8003B35C(&m, (MgVec *)&D_801C984C[-1]);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801C9862;
    *frame = D_801C9844 * 0x10;
    D_801E1EA8 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801E1EA8);
    if (D_80062D98 == 0) {
        p->unk1A += 8;
        if (p->unk2 < 8) {
            D_801C9844 += 1;
        }
        if (p->unk2 >= 0x26) {
            D_801C9844 -= 1;
        }
        if (++p->unk2 == 0x2D) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_awa/nonmatchings/text", func_801B0CB4);

void func_801B1068(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B0CB4)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_awa/nonmatchings/text", func_801B1128);
