#include "common.h"
#include "magic_hado/decls.h"

void func_801B0000(void) {
    func_801B1990();
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
    D_801EF234 = D_801D7234 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C8(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2800, 0);
    D_801D7160[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D7160[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D6E5C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0584(void) {
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
    rot.vz = p->unk14;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x2000;
    func_8003C21C(&rot, &lw);
    func_8003B05C(&m, &lw);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801D716C = p->unk16;
    D_801D716B = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801D7168;
    *rgb = D_801D7169 = D_801D716A = n << 4;
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
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B07A0(void) {
    MgTask *p;
    MgMat m;
    MgMat lw;
    MgVec scale;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801D7170, &m);
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
    D_801D7182[0] = t << 8;
    D_801EF234 = (u8 *)func_800D29D4(&D_801D7182[-5], D_801517C0 + 0x70, 0xC, (s32)D_801EF234);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 15) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_hado/nonmatchings/text", func_801B08E8);

void func_801B0D04(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D71A4;
    *frame = p->unk2;
    D_801EF234 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EF234);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D6FD4) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_hado/nonmatchings/text", func_801B0DC0);

void func_801B0EF8(void) {
    MgMat m;
    MgMat lw;
    MgVec scale;
    MgTask *p;
    s16 *frame;
    s32 **q;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D71C8, &m);
    func_8003A79C(&D_801D7214, &m, &m);
    scale.vx = scale.vz = 0x2000 - (p->unk2 << 9);
    scale.vy = p->unk18 * p->unk2 / 6;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    frame = &D_801D71C2;
    q = (s32 **)((u8 *)frame - 0xA);
    M2C_SFIELD(q, s32 **, 0) = D_801D2160;
    v = 0x1000 - (D_801D71B4 << 8);
    *frame = v;
    D_801EF234 = (u8 *)func_800D29D4(q, D_801517C0 + 0x70, 0xC, (s32)D_801EF234);
    *q = D_801D26C4;
    D_801EF234 = (u8 *)func_800D29D4(q, D_801517C0 + 0x70, 0xC, (s32)D_801EF234);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 7) {
            D_801D71B4 -= 2;
        }
        if (++p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_hado/nonmatchings/text", func_801B10F0);

INCLUDE_ASM("../asm/us/magic_hado/nonmatchings/text", func_801B13F4);

void func_801B1850(arg0, arg1) {
    MgSVec v;
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(func_801B13F4)];
    func_800D3994(arg1, D_80151915[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    v.vx = p->unkC.vx - p->unk4.vx;
    v.vy = p->unkC.vy - p->unk4.vy;
    v.vz = p->unkC.vz - p->unk4.vz;
    func_800D44E8(&v, &D_801D7214);
    p->unk1C = arg0;
    D_800F5B70 = D_800F5B71 = D_800F5B72 = 0;
    func_800D52A0(0xC00, 0xA);
    func_800BBA84(0xFA, arg1, 0x40);
}

void func_801B1990(arg0, arg1) {
    func_800BBEAC(&func_801B045C);
    func_800D2980(&D_801B19FC, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B1850);
}
