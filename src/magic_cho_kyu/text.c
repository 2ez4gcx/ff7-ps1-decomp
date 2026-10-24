#include "common.h"
#include "magic_cho_kyu/decls.h"

void func_801B0000(void) {
    func_801B2028();
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
    D_801EF498 = D_801D7498 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C8(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(0, 0, D_801D7320);
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 < 0x10) {
            D_801D7320 = (u16) D_801D7320 + 0xF;
        }
        if (temp_s0->unk2 >= 0x23) {
            D_801D7320 = (u16) D_801D7320 - 0xF;
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
    D_801D732C[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D732C[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D6F2C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_cho_kyu/nonmatchings/text", func_801B0664);

void func_801B07DC(void) {
    MgMat lw;
    MgMat m;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    u8 *rgb;
    s16 i;
    s16 n;

    p = &D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[2][i] = 0;
        m.m[1][i] = 0;
        m.m[0][i] = 0;
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
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x2000;
    func_8003C21C(&rot, &lw);
    func_8003B05C(&m, &lw);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801D7350 = p->unk16;
    D_801D734F = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801D734C;
    *rgb = D_801D734D = D_801D734E = n << 4;
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
        p->unk14 += 0x200;
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B09F8(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    MgTask *p;
    s16 *frame;
    s32 *q;

    rot.vy = 0;
    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vz = p->unk14;
    func_8003BF8C(&rot, &m);
    func_8003B35C(&m, &D_801D7354);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801D736E;
    q = (s32 *)((u8 *)frame - 0xA);
    M2C_SFIELD(frame, s16 *, 0) = 0x80 - p->unk2 * 6;
    *q = D_801D7374[p->unk16];
    D_801EF498 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801EF498);
    if (D_80062D98 == 0) {
        p->unk6 -= 200;
        p->unk14 += 0x100;
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B0B58(void) {
    MgTask *p;
    MgMat m;
    MgMat lw;
    MgVec scale;
    s32 t;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801D7384, &m);
    func_8003A79C(&D_801D746C, &m, &m);
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
    D_801D7396[0] = t << 8;
    D_801EF498 = func_800D29D4(&D_801D7396[-5], D_801517C0 + 0x70, 0xC, D_801EF498);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_cho_kyu/nonmatchings/text", func_801B0CB4);

INCLUDE_ASM("../asm/us/magic_cho_kyu/nonmatchings/text", func_801B0E38);

INCLUDE_ASM("../asm/us/magic_cho_kyu/nonmatchings/text", func_801B0F24);

void func_801B11F4(void) {
    MgMat m;
    MgMat lw;
    MgVec scale;
    MgTask *p;
    s16 *frame;
    s32 **q;
    s32 v;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801D73F8, &m);
    func_8003A79C(&D_801D746C, &m, &m);
    scale.vx = scale.vz = 0x4000 - p->unk2 * 300;
    scale.vy = p->unk2 * 900;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    frame = &D_801D73F2;
    q = (s32 **)((u8 *)frame - 0xA);
    M2C_SFIELD(q, s32 **, 0) = &D_801D2430;
    v = 0x1000 - (D_801D73E4 << 8);
    *frame = v;
    D_801EF498 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801EF498);
    *q = &D_801D2A34;
    D_801EF498 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801EF498);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 13) {
            D_801D73E4--;
        }
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_cho_kyu/nonmatchings/text", func_801B13E8);

INCLUDE_ASM("../asm/us/magic_cho_kyu/nonmatchings/text", func_801B19C4);

INCLUDE_ASM("../asm/us/magic_cho_kyu/nonmatchings/text", func_801B1B3C);

void func_801B2028(arg0, arg1) {
    MgVec v;
    MgSVec d;
    MgTask *p;

    func_800BBEAC(func_801B045C);
    D_801D748C = arg0;
    p = &D_80162978[func_800BBEAC(func_801B1B3C)];
    func_800D3994(arg1, D_8015191E[arg1][0], &p->unk4);
    func_801B0020(arg0, &D_801D7490);
    v.vx = d.vx = D_801D7490.vx - p->unk4;
    v.vy = d.vy = D_801D7492 - p->unk6;
    v.vz = d.vz = D_801D7494 - p->unk8;
    func_800D44E8(&d, &D_801D746C);
    func_8003A08C(&v, &v);
    p->unkC = (u32)(v.vx * 75) >> 9;
    p->unkE = (u32)(v.vy * 75) >> 9;
    p->unk10 = (u32)(v.vz * 75) >> 9;
    p->unk1E = arg1;
    func_800D2980(D_801B21F0, 0, 0, 0);
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    func_800D52A0(0x1000, 0x10);
}
