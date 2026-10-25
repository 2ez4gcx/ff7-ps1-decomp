#include "common.h"
#include "magic_gaisei/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B322C();
    return &D_801BD370;
}

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B0A50);

void func_801B1160(s16 mask, MgSVec *out) {
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

void func_801B130C(s32 base, s16 range, MgSVec *out) {
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

void func_801B143C(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist) {
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

void func_801B159C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D6EC0 = D_801BEEC0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B1608);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B181C);

void func_801B18D4(void) {
    MgMat lw;
    MgMat m;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    u8 *rgb;
    s16 i;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[2][i] = 0;
        m.m[1][i] = 0;
        m.m[0][i] = 0;
    }
    n = 8;
    if (p->unk2 >= 0x16) {
        n = 0x1E - p->unk2;
    }
    rot.vy = 0;
    rot.vx = 0;
    rot.vz = p->unk16;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x800;
    func_8003C21C(&rot, &lw);
    func_8003B05C(&m, &lw);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801BED88 = p->unk1A;
    D_801BED87 = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801BED84;
    *rgb = D_801BED85 = D_801BED86 = n << 4;
    D_80163C74 = func_800D4D90(rgb - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (p->unk6 > 0) {
            p->unk6 = 0;
            p->unkE *= -1;
        }
        p->unkE += 20;
        p->unk16 += 0x200;
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B1AF0);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B1C70);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B1EA0);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B1FE0);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B2128);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B226C);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B2420);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B24B4);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B25F0);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B28DC);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B2DFC);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B2EEC);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B2F9C);

INCLUDE_ASM("../asm/us/magic_gaisei/nonmatchings/text", func_801B322C);
