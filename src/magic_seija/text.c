#include "common.h"
#include "magic_seija/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0D2C();
    return &D_801C3C28;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D7528 = D_801C7528 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0088(void) {
    MgTask *p;
    s32 c;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, 0);
    D_801C7474[0] = D_801C7480[p->unk1A];
    c = -0x80 - p->unk2 * 0xC;
    D_801C7478 = D_801C7479 = D_801C747A = c;
    D_80163C74 = func_800D4D90(D_801C7474, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x190;
        if (++p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B018C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    D_801C7490[0] = D_801C749C[p->unk1A];
    D_801C7498 = p->unk2;
    D_80163C74 = func_800D4D90(D_801C7490, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801C749C[p->unk1A][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0280(void) {
    MgTask *p;
    s32 c;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801C74B0[0] = p->unk1A;
    c = -0x80 - (p->unk2 << 4);
    D_801C74AC = D_801C74AD = D_801C74AE = c;
    D_80163C74 = func_800D4D90((s32 **)&D_801C74B0[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (++p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B038C(void) {
    MgMat m1;
    MgMat m2;
    MgVec scale;
    MgTask *p;
    s16 *q;
    void *pkt;
    s32 t;

    p = &D_80162978[D_8015169C];
    D_801C74C6[0] = p->unk2 * 0x200;
    func_8003BF8C(&D_801C74C6[-1], &m1);
    scale.vx = scale.vz = func_80039A74(p->unk2 * 0x66) * 0x7F00 >> 12;
    scale.vy = 0x1800 - (func_80039A74(p->unk2 * 0x66) * 0x1000 >> 12);
    func_8003B35C(&m1, &scale);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m1, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    func_8003B69C(0, 0, 0);
    q = D_801C74BE;
    pkt = (u8 *)q - 0xA;
    *q = p->unk2 * 0x199;
    *(M2C_UNK **)((u8 *)q - 0xA) = &D_801C34EC;
    D_801D7528 = func_800D29D4(pkt, D_801517C0 + 0x70, 0xC, D_801D7528);
    *(M2C_UNK **)((u8 *)q - 0xA) = &D_801C2F08;
    D_801D7528 = func_800D29D4(pkt, D_801517C0 + 0x70, 0xC, D_801D7528);
    if (D_80062D98 == 0) {
        if (++p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B0580(void) {
    MgTask *temp_s0;
    MgTask *temp_v0;
    s16 temp_v0_2;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 == 0) {
            temp_v0 = &D_80162978[func_800BBEAC(&func_801B038C)];
            temp_v0->unk4 = (s16) (u16) temp_s0->unk4;
            temp_v0->unk6 = (s16) (u16) temp_s0->unk6;
            temp_v0->unk8 = (s16) (u16) temp_s0->unk8;
        }
        temp_v0_2 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0_2;
        if (temp_v0_2 == 0xC) {
            temp_s0->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_seija/nonmatchings/text", func_801B0638);

void func_801B0D2C(arg0, arg1) {
    func_800BBEAC((void *)func_801B0028);
    func_800D2980(D_801B0DE8, 0, 0, 0);
    D_801D752C = arg0;
    func_800D54EC(arg0, D_801D7530);
    D_80162996[func_800BBEAC((void *)func_801B0638)].unk0 = arg1;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    D_800F5B72 = 0x40;
    func_800D52A0(0x1000, 0xA);
}
