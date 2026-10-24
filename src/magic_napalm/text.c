#include "common.h"
#include "magic_napalm/decls.h"

void func_801B0000(void) {
    func_801B1884();
}

void func_801B0020(s16 mask, MgSVec *out) {
    MgVec sum;
    MgSVec pos;
    s16 i;
    s16 n;

    n = 0;
    sum.vx = sum.vy = sum.vz = 0;
    for (i = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            func_800D3994(i, D_8015190F[i][0], &pos);
            n++;
            sum.vx += pos.vx;
            sum.vy += pos.vy;
            sum.vz += pos.vz;
        }
    }
    out->vx = sum.vx / n;
    out->vy = sum.vy / n;
    out->vz = sum.vz / n;
}

void func_801B01CC(s32 base, s16 range, MgSVec *out) {
    MgSVec v;
    MgSVec rot;
    MgMat m;

    v.vz = 0;
    v.vx = 0;
    v.vy = base + ((func_80042DA8() % range) * 2 - range);
    rot.vy = 0;
    rot.vx = func_80042DA8() % 800 - 400;
    rot.vz = func_80042DA8() % 800 - 400;
    func_8003BF8C(&rot, &m);
    func_8003B2CC(&m, &v, out);
}

void func_801B02FC(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist) {
    MgMat m;
    MgMat r;
    MgVec n;
    s32 flag;
    s16 i;

    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(pos, (MgVec *)m.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)m.t, &n);
        m.t[0] += (dist * n.vx) >> 12;
        m.t[1] += (dist * n.vy) >> 12;
        m.t[2] += (dist * n.vz) >> 12;
    }
    m.m[0][0] = m.m[1][1] = m.m[2][2] = scale;
    func_8003C21C(rot, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
}

void func_801B045C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801F088C = D_801D888C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_napalm/nonmatchings/text", func_801B04C8);

INCLUDE_ASM("../asm/us/magic_napalm/nonmatchings/text", func_801B060C);

void func_801B06F0(void) {
    MgObj20 *temp_s0;
    MgObj20 *temp_v0;
    s16 temp_v0_2;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        M2C_FIELD(temp_s0, u16 *, 4) = (u16) (M2C_FIELD(temp_s0, u16 *, 4) + M2C_FIELD(temp_s0, u16 *, 0xC));
        M2C_FIELD(temp_s0, u16 *, 6) = (u16) (M2C_FIELD(temp_s0, u16 *, 6) + M2C_FIELD(temp_s0, u16 *, 0xE));
        M2C_FIELD(temp_s0, u16 *, 8) = (u16) (M2C_FIELD(temp_s0, u16 *, 8) + M2C_FIELD(temp_s0, u16 *, 0x10));
        M2C_FIELD(temp_s0, u16 *, 0xE) = (u16) (M2C_FIELD(temp_s0, u16 *, 0xE) + 0xA);
        temp_v0 = &D_80162978[func_800BBEAC(&func_801B04C8)];
        M2C_FIELD(temp_v0, u16 *, 4) = (u16) M2C_FIELD(temp_s0, u16 *, 4);
        M2C_FIELD(temp_v0, u16 *, 6) = (u16) M2C_FIELD(temp_s0, u16 *, 6);
        M2C_FIELD(temp_v0, u16 *, 8) = (u16) M2C_FIELD(temp_s0, u16 *, 8);
        M2C_FIELD(temp_v0, s16 *, 0x1A) = 1;
        temp_v0_2 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0_2;
        if (temp_v0_2 == 0xA) {
            temp_s0->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_napalm/nonmatchings/text", func_801B07D4);

INCLUDE_ASM("../asm/us/magic_napalm/nonmatchings/text", func_801B0B10);

void func_801B0D2C(void) {
    MgTask *p;
    MgMat m;
    MgMat lw;
    MgVec scale;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801D8860, &m);
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
    D_801D8872[0] = t << 8;
    D_801F088C = (u8 *)func_800D29D4(&D_801D8872[-5], D_801517C0 + 0x70, 0xC, (s32)D_801F088C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 15) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_napalm/nonmatchings/text", func_801B0E74);

INCLUDE_ASM("../asm/us/magic_napalm/nonmatchings/text", func_801B12D8);

INCLUDE_ASM("../asm/us/magic_napalm/nonmatchings/text", func_801B17AC);

void func_801B1884(arg0, arg1) {
    func_800BBEAC(&func_801B045C);
    func_800D2980(&D_801B18F0, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B17AC);
}
