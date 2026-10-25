#include "common.h"
#include "magic_tbreath/decls.h"

void func_801B0000(void) {
    func_801B1840();
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
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801E72D0 = D_801D715C[p->unk2];
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_tbreath/nonmatchings/text", func_801B04C0);

void func_801B063C(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(0, 0, D_801D7178);
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 < 0x10) {
            D_801D7178 = (u16) D_801D7178 + 0xF;
        }
        if (temp_s0->unk2 >= 0x11) {
            D_801D7178 = (u16) D_801D7178 - 0xF;
        }
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 == 0x20) {
            temp_s0->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_tbreath/nonmatchings/text", func_801B071C);

INCLUDE_ASM("../asm/us/magic_tbreath/nonmatchings/text", func_801B0948);

INCLUDE_ASM("../asm/us/magic_tbreath/nonmatchings/text", func_801B0A2C);

void func_801B0DD4(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    D_801D7244[0] = p->unk2;
    D_801E72D0 = func_800D4D90(&D_801D7244[-4], D_801517C0 + 0x70, 0xC, D_801E72D0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D69C4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0E8C(void) {
    MgMat m;
    MgMat m2;
    MgSVec rot;
    MgTask *p;
    s32 *q;

    rot.vx = rot.vy = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vz = p->unk14;
    func_8003BF8C(&rot, &m);
    q = &D_801D72B0;
    *q = D_801D72B4 = D_801D72B8 = 0x1000;
    func_8003B35C(&m, q);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    D_801D7252[0] = 0x80 - p->unk2 * 8;
    *(u8 **)&D_801D7252[-5] = D_801D7258[p->unk16];
    D_801E72D0 = (u8 *)func_800D29D4(&D_801D7252[-5], D_801517C0 + 0x70, 0xC, (s32)D_801E72D0);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x190;
        p->unk14 += 0x100;
        if (++p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B0FFC(void) {
    MgTask *p;
    u8 c;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D7270[0] = p->unk16;
    c = 0x80 - p->unk2 * 8;
    D_801D726E = c;
    D_801D726D = c;
    D_801D726C = c;
    D_801E72D0 = func_800D4D90(&D_801D7270[-4], D_801517C0 + 0x70, 0xC, D_801E72D0);
    if (D_80062D98 == 0) {
        p->unk6 -= 300;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 15) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_tbreath/nonmatchings/text", func_801B10E4);

INCLUDE_ASM("../asm/us/magic_tbreath/nonmatchings/text", func_801B15C4);

INCLUDE_ASM("../asm/us/magic_tbreath/nonmatchings/text", func_801B1840);
