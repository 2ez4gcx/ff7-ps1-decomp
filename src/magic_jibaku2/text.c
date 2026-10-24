#include "common.h"
#include "magic_jibaku2/decls.h"

void func_801B0000(void) {
    func_801B164C();
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
    D_801EA548 = D_801D2548 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_jibaku2/nonmatchings/text", func_801B04C8);

INCLUDE_ASM("../asm/us/magic_jibaku2/nonmatchings/text", func_801B0560);

void func_801B06B0(void) {
    s32 f;
    MgObjAwa *p;
    s16 *frame;
    s16 n;
    s32 c;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    n = p->unk2;
    f = n;
    if (f >= 8) {
        f = 7;
    }
    func_800D4368(&p->unk4, (s16)(n * 0xC0 + 0x2000), 0);
    frame = &D_801D250C;
    *frame = f;
    c = 0x60 - p->unk2 * 4;
    D_801D2508 = D_801D2509 = D_801D250A = c;
    D_801EA548 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EA548);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 24) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_jibaku2/nonmatchings/text", func_801B07C4);

void func_801B09F4(void) {
    MgMat lw;
    MgMat m;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    u8 *rgb;
    s16 i;
    s32 c;

    p = &D_801621F0[D_801590D4];
    for (i = 0; i < 3; i++) {
        m.m[2][i] = 0;
        m.m[1][i] = 0;
        m.m[0][i] = 0;
    }
    rot.vz = p->unk14 + 0x400;
    rot.vx = 0;
    rot.vy = p->unk16;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x6000;
    func_8003B05C(&m, &D_800FA63C);
    func_8003C21C(&rot, &lw);
    func_8003B05C(&m, &lw);
    func_8003B48C(&m);
    func_8003B51C(&m);
    rgb = &D_801D2520;
    c = -0x80 - p->unk2 * 16;
    *rgb = D_801D2521 = D_801D2522 = c;
    D_80163C74 = func_800D4D90(rgb - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B0BB4(void) {
    MgSVec rot;
    MgMat lw;
    MgMat m;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vx = 0;
    rot.vy = p->unk2 << 6;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    D_801D2538.vx = D_801D2540[0] = (p->unk2 << 8) + 0x3000;
    D_801D253C = (p->unk2 << 8) + 0x2000;
    func_8003B35C(&m, &D_801D2538);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D2532[0] = 0x80 - p->unk2 * 4;
    D_801EA548 = (u8 *)func_800D29D4(&D_801D2532[-5], D_801517C0 + 0x70, 0xC, (s32)D_801EA548);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 30) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_jibaku2/nonmatchings/text", func_801B0D10);

INCLUDE_ASM("../asm/us/magic_jibaku2/nonmatchings/text", func_801B15B8);

INCLUDE_ASM("../asm/us/magic_jibaku2/nonmatchings/text", func_801B164C);
