#include "common.h"
#include "magic_dia/decls.h"

void func_801B0000(void) {
    func_801B22F0();
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
    D_801EEB54 = D_801D6B54 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B04C8);

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B05D4);

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B06E4);

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B07F0);

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B09E0);

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B0CC4);

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B0EA0);

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B1004);

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B118C);

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B1374);

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B1634);

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B16DC);

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B22F0);
