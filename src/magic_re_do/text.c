#include "common.h"
#include "magic_re_do/decls.h"

void func_801B0000(void) {
    func_801B1A54();
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
    D_801ED738 = D_801D5738 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C8(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(0, 0, D_801D5620);
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 < 0x10) {
            D_801D5620 = (u16) D_801D5620 + 0xF;
        }
        if (temp_s0->unk2 >= 0x23) {
            D_801D5620 = (u16) D_801D5620 - 0xF;
        }
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 == 0x32) {
            temp_s0->unk0 = -1;
        }
    }
}

void func_801B05A8(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2800, 0);
    D_801D562C[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D562C[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D5264) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_re_do/nonmatchings/text", func_801B0664);

INCLUDE_ASM("../asm/us/magic_re_do/nonmatchings/text", func_801B0880);

INCLUDE_ASM("../asm/us/magic_re_do/nonmatchings/text", func_801B09E0);

INCLUDE_ASM("../asm/us/magic_re_do/nonmatchings/text", func_801B0B3C);

INCLUDE_ASM("../asm/us/magic_re_do/nonmatchings/text", func_801B0CC0);

INCLUDE_ASM("../asm/us/magic_re_do/nonmatchings/text", func_801B0DAC);

INCLUDE_ASM("../asm/us/magic_re_do/nonmatchings/text", func_801B0EAC);

INCLUDE_ASM("../asm/us/magic_re_do/nonmatchings/text", func_801B10A0);

INCLUDE_ASM("../asm/us/magic_re_do/nonmatchings/text", func_801B1590);

INCLUDE_ASM("../asm/us/magic_re_do/nonmatchings/text", func_801B1A54);
