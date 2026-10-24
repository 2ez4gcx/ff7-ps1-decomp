#include "common.h"
#include "magic_nonoshi/decls.h"

void func_801B0000(void) {
    func_801B2400();
}

INCLUDE_ASM("../asm/us/magic_nonoshi/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_nonoshi/nonmatchings/text", func_801B0A48);

void func_801B1158(s16 mask, MgSVec *out) {
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

void func_801B1304(s32 base, s16 range, MgSVec *out) {
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

void func_801B1434(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist) {
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

void func_801B1594(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DE41C = D_801C641C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B1600(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x1000, 0);
    D_801C5BA4[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801C5BA4[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C5938) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_nonoshi/nonmatchings/text", func_801B16BC);

INCLUDE_ASM("../asm/us/magic_nonoshi/nonmatchings/text", func_801B1784);

INCLUDE_ASM("../asm/us/magic_nonoshi/nonmatchings/text", func_801B1818);

INCLUDE_ASM("../asm/us/magic_nonoshi/nonmatchings/text", func_801B1954);

INCLUDE_ASM("../asm/us/magic_nonoshi/nonmatchings/text", func_801B1AA8);

INCLUDE_ASM("../asm/us/magic_nonoshi/nonmatchings/text", func_801B1C0C);

INCLUDE_ASM("../asm/us/magic_nonoshi/nonmatchings/text", func_801B1EE0);

void func_801B2340(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B1EE0)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_nonoshi/nonmatchings/text", func_801B2400);
