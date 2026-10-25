#include "common.h"
#include "magic_scope/decls.h"

void func_801B0028(s16 mask, MgSVec *out) {
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

void func_801B01D4(s32 base, s16 range, MgSVec *out) {
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

void func_801B0304(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist) {
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

void func_801B0464(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D5964 = D_801BD964 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_RODATA("../asm/us/magic_scope/nonmatchings/text", D_801B0000);

void func_801B04D0(s32 arg0, MgSVec *rot, s16 scale) {
    MgMat r;
    MgMat m;
    MgVec unused;

    m = D_801B0000;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = scale;
    func_8003B05C(&m, &D_800FA63C);
    func_8003C21C(rot, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
}

INCLUDE_RODATA("../asm/us/magic_scope/nonmatchings/text", D_801B0020);

INCLUDE_RODATA("../asm/us/magic_scope/nonmatchings/text", D_801B0024);

void func_801B05B4(void) {
    MgPtrPair tbl;
    MgTask *p;
    s32 **hdr;

    tbl = D_801B0020;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2400, 0);
    hdr = &D_801BD910;
    M2C_SFIELD(hdr, s32 **, 0) = tbl.ptr[p->unk1A];
    D_801BD918 = p->unk2;
    D_801D5964 = (u8 *)func_800D4D90(hdr, D_801517C0 + 0x70, 0xC, (s32)D_801D5964);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= tbl.ptr[p->unk1A][1]) {
            if (p->unk1A == 0) {
                p->unk1A = 1;
                p->unk2 = 0;
            } else {
                p->unk0 = -1;
            }
        }
    }
}

INCLUDE_ASM("../asm/us/magic_scope/nonmatchings/text", func_801B06D0);

INCLUDE_ASM("../asm/us/magic_scope/nonmatchings/text", func_801B0A48);

INCLUDE_ASM("../asm/us/magic_scope/nonmatchings/text", func_801B0C94);
