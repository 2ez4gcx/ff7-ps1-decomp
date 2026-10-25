#include "common.h"
#include "magic_southern/decls.h"

void func_801B0000(void) {
    func_801B0E30();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E4294 = D_801CC294 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_southern/nonmatchings/text", func_801B008C);

void func_801B018C(void) {
    MgSVec rot;
    MgMat lw;
    MgMat m;
    MgTask *p;
    s16 *frame;
    s32 **q;
    s32 v;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unk2 << 8;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    v = p->unk2 * 0x200 + 0x1000;
    D_801CC280.vx = D_801CC280.vy = D_801CC280.vz = v;
    func_8003B35C(&m, &D_801CC280);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801CC25E;
    q = (s32 **)((u8 *)frame - 0xA);
    *frame = 0x80 - p->unk2 * 6;
    D_801CC258 = 0x28;
    M2C_SFIELD(q, s32 **, 0) = D_801CB6E8;
    D_801E4294 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801E4294);
    M2C_SFIELD(q, s32 **, 0) = D_801CB5EC;
    D_801E4294 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801E4294);
    if (D_80062D98 == 0) {
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0334(void) {
    MgSVec v;
    MgTask *p;
    MgByte *q;
    u16 n;
    s16 t;
    u16 c;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    n = 8;
    if (t >= 0x16) {
        n = 0x1E - t;
    }
    v.vx = func_80039A74(p->unk14) * p->unk18 >> 12;
    v.vz = func_80039B40(p->unk14) * p->unk18 >> 12;
    v.vx += p->unk4;
    v.vz += p->unk8;
    v.vy = p->unk6;
    func_800D4368(&v, (func_80039A74(p->unk2 * 0x300) << 11 >> 12) + 0x1000, 0);
    q = &D_801CC268;
    c = (u32)(n << 16) >> 12;
    q->v = D_801CC269.v = D_801CC26A.v = c;
    D_80163C74 = func_800D4D90(q - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk6 += 0x85;
        k = p->unk16;
        p->unk14 += 0x40 - (k << 7);
        if (++p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B04E8(void) {
    MgVec scale;
    MgMat lw;
    MgMat m;
    MgSVec v;
    MgSVec rot;
    MgTask *p;
    MgTask *q;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    v.vx = func_80039A74(p->unk14) * p->unk18 >> 12;
    v.vz = func_80039B40(p->unk14) * p->unk18 >> 12;
    v.vx += p->unk4;
    v.vz += p->unk8;
    v.vy = p->unk6;
    rot.vx = p->unk2 << 8;
    rot.vy = p->unk2 << 9;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    scale.vx = scale.vy = scale.vz = 0x1000;
    func_8003B35C(&m, &scale);
    m.t[0] = v.vx;
    m.t[1] = v.vy;
    m.t[2] = v.vz;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801E4294 = func_800D29D4(D_801CC270, D_801517C0 + 0x70, 0xC, D_801E4294);
    if (D_80062D98 == 0) {
        p->unk6 += 0x85;
        k = p->unk16;
        p->unk14 += 0x40 - (k << 7);
        if (++p->unk2 == 0x1E) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B018C)];
            q->unk4 = v.vx;
            q->unk6 = v.vy;
            q->unk8 = v.vz;
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_southern/nonmatchings/text", func_801B06FC);

void func_801B0E30(arg0, arg1) {
    func_800D2980(D_801B0F28, 0, 0, 0);
    D_801E42A0 = arg0;
    func_800D3994(arg1, D_80151918[arg1][0], &D_8016297C[func_800BBEAC((void *)func_801B06FC)]);
    func_800D54EC(arg0, D_801E4298);
    func_800BBA84(0x123, arg1, 0x40);
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    func_800D52A0(0x1000, 0x14);
    func_800BBEAC((void *)func_801B0020);
}
