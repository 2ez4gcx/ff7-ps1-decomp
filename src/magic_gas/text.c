#include "common.h"
#include "magic_gas/decls.h"

void func_801B0010(void) {
    func_801B0F84();
}

void func_801B0030(s16 mask, MgSVec *out) {
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

void func_801B01DC(s32 base, s16 range, MgSVec *out) {
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

void func_801B030C(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist) {
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

void func_801B046C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EBFF8 = D_801D3FF8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_gas/nonmatchings/text", func_801B04D8);

void func_801B05DC(void) {
    MgMat m[2];
    MgSVec rot;
    s32 flag;
    MgGas *p;
    MgMat *mp;
    s16 n;
    s16 i;
    s16 scale;
    s8 *col;
    s8 c;
    s32 t;

    p = (MgGas *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m[1].m[0][i] = m[1].m[1][i] = m[1].m[2][i] = 0;
    }
    n = 8;
    if (p->unk2 >= 12) {
        n = 20 - p->unk2;
    }
    rot.vy = 0;
    rot.vx = 0;
    rot.vz = p->unk14;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(&p->unk4, (MgVec *)m[1].t, &flag);
    mp = &m[1];
    scale = 0x2000;
    if (p->unk16 < 4) {
        scale = 0x1400;
    }
    m[1].m[0][0] = m[1].m[1][1] = m[1].m[2][2] = scale;
    func_8003C21C(&rot, &m[0]);
    func_8003B05C(mp, &m[0]);
    func_8003B48C(mp);
    func_8003B51C(mp);
    D_801D3FB0 = p->unk16;
    D_801D3FAF = (n == 8) ? 0x2C : 0x2E;
    col = &D_801D3FAC;
    c = n << 4;
    D_801D3FAE = c;
    D_801D3FAD = c;
    *col = c;
    D_80163C74 = func_800D4D90(col - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4.vx += p->unkC.vx;
        p->unk4.vy += p->unkC.vy;
        p->unk4.vz += p->unkC.vz;
        if (p->unk4.vy > 0) {
            p->unk4.vy = 0;
            t = p->unkC.vy;
            p->unkC.vy = -t;
        }
        p->unkC.vy += 0x14;
        p->unk14 += 0x200;
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_gas/nonmatchings/text", func_801B080C);

INCLUDE_ASM("../asm/us/magic_gas/nonmatchings/text", func_801B0AEC);

INCLUDE_ASM("../asm/us/magic_gas/nonmatchings/text", func_801B0EAC);

void func_801B0F84(arg0, arg1) {
    func_800BBEAC(&func_801B046C);
    func_800D2980(&D_801B0FF0, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0EAC);
}
