#include "common.h"
#include "magic_debaria/decls.h"

void *func_801B0054(DbCtx *arg0, u8 *arg1, s32 *arg2) {
    u16 *e;
    s16 *a;
    s32 i;
    s32 n;
    s32 cnt;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    s32 r;
    s32 row;

    e = (u16 *)(arg2 + 1);
    i = 0;
    n = arg0->unk24;
    cnt = *arg2;
    k = 0x61A8;
    row = arg0->unk2C;
    for (; i < cnt; i++) {
        a = (s16 *)(arg1 + e[0]);
        x = a[0];
        y = a[1];
        z = a[2];
        a = (s16 *)(arg1 + e[1]);
        x += a[0];
        y += a[1];
        z += a[2];
        a = (s16 *)(arg1 + e[2]);
        x += a[0];
        y += a[1];
        z += a[2];
        x /= 3;
        y /= 3;
        z /= 3;
        D_801CAB24[row][n].vz = z;
        z = z * z / k;
        D_801CAB24[row][n].vx = x;
        D_801CAB24[row][n].vy = y;
        D_801CAB24[row][n].f6 = 10 - z;
        D_801CAB24[row][n].f8 = D_801CAB24[row][n].fA = D_801CAB24[row][n].fC = D_801CAB24[row][n].fE = 0;
        r = func_80042DA8();
        if (r & 0x800) {
            D_801CAB24[row][n].f10 = (r & 7) * 12;
        } else {
            D_801CAB24[row][n].f10 = -((r & 7) * 12);
        }
        D_801CAB24[row][n].f12 = 0;
        if (r & 0x204080) {
            D_801CAB24[row][n].f14 = ((r >> 3) & 7) * 12;
        } else {
            D_801CAB24[row][n].f14 = -(((r >> 3) & 7) * 12);
        }
        D_801CAB24[row][n].f16 = (z + 8) * ((r & 3) + 8);
        n++;
        e += 10;
    }
    arg0->unk24 = n;
    return e;
}

INCLUDE_ASM("../asm/us/magic_debaria/nonmatchings/text", func_801B0314);

INCLUDE_ASM("../asm/us/magic_debaria/nonmatchings/text", func_801B036C);

s32 func_801B0A18(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801B22EC[a];
        } else {
            r = D_801B22EC[0x800 - a];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801B22EC[a - 0x800];
        } else {
            r = -D_801B22EC[0x1000 - a];
        }
    }
    return r;
}

s32 func_801B0ABC(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801B22EC[0x400 - a];
        } else {
            r = -D_801B22EC[a - 0x400];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801B22EC[0xC00 - a];
        } else {
            r = D_801B22EC[a - 0xC00];
        }
    }
    return r;
}

void func_801B0B58(s16 *arg0, s16 *arg1) {
    s32 c0;
    s32 c1;
    s32 c2;
    s32 s0;
    s32 s1;
    s32 s2;
    s32 ca;
    s32 cb;

    c0 = func_801B0ABC(arg0[0]);
    c1 = func_801B0ABC(arg0[1]);
    c2 = func_801B0ABC(arg0[2]);
    s0 = func_801B0A18(arg0[0]);
    s1 = func_801B0A18(arg0[1]);
    s2 = func_801B0A18(arg0[2]);
    ca = (c2 * -s1) >> 12;
    cb = (s2 * -s1) >> 12;
    arg1[2] = s1;
    arg1[0] = (c2 * c1) >> 12;
    arg1[3] = ((s2 * c0) >> 12) - ((ca * s0) >> 12);
    arg1[6] = ((s2 * s0) >> 12) + ((ca * c0) >> 12);
    arg1[1] = (-s2 * c1) >> 12;
    arg1[4] = ((c2 * c0) >> 12) + ((cb * s0) >> 12);
    arg1[7] = ((c2 * s0) >> 12) - ((cb * c0) >> 12);
    arg1[5] = (-c1 * s0) >> 12;
    arg1[8] = (c1 * c0) >> 12;
}

INCLUDE_ASM("../asm/us/magic_debaria/nonmatchings/text", func_801B0CD4);

void func_801B0D4C(void) {
    func_801B12F8();
}

void func_801B0D6C(void) {
    MgSVec rot;
    MgSVec ang;
    MgMat m;
    u8 pad[0x10];
    MgTask *p;
    s32 scale;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B69C(0, 0, 0);
    ((DbTask *)0x1F800000)->unk0 = D_801B136C;
    ((DbTask *)0x1F800000)->unk8 = 0xC;
    ((DbTask *)0x1F800000)->unk4 = D_801517C0 + 0x70;
    ((DbTask *)0x1F800000)->unkC = D_801CAB18;
    ((DbTask *)0x1F800000)->unk2C = p->unk14;
    rot.vx = 0;
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    ang.vx = 0;
    ang.vy = 0;
    ang.vz = -p->unkE;
    func_8003B27C(&m, &ang, m.t);
    m.t[0] += p->unk4;
    m.t[1] += p->unk6;
    m.t[2] += p->unk8;
    func_8003A63C(&D_800FA63C, &m, (MgMat *)0x1F800030);
    scale = p->unk10;
    *(s32 *)0x1F800078 = scale;
    *(s32 *)0x1F800074 = scale;
    *(s32 *)0x1F800070 = scale;
    func_8003B35C((MgMat *)0x1F800030, (s32 *)0x1F800070);
    D_801CAB18 = func_801B0CD4((DbTask *)0x1F800000, p->unk2);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x16) {
            func_800D5774(p->unk12);
        }
        p->unk2++;
    }
}

void func_801B0F30(void) {
    MgSVec rot;
    MgSVec pad1;
    MgSVec ofs;
    MgMat m;
    MgMat pad2;
    MgTask *p;
    u16 a;

    rot.vx = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    ofs.vx = 0;
    ofs.vy = 0;
    ofs.vz = -p->unkE;
    func_8003B2CC(&m, &ofs, &ofs);
    ofs.vx += p->unk4;
    ofs.vy += p->unk6;
    ofs.vz += p->unk8;
    switch (p->unk2) {
    case 1:
    case 2:
        a = p->unk10;
        break;
    case 0:
    case 3:
        a = (s32)((u16)p->unk10 << 16) >> 17;
        break;
    default:
        a = 0;
        break;
    }
    func_800D4368(&ofs, (s16)a, 0);
    ((MgScratch *)0x1F800000)->unk0 = D_801B19C8;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801CAB18 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801CAB18);
    if (p->unk2 >= 3) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 1) {
            func_800D5138(1);
        }
        if (p->unk2 == 2) {
            func_800D51D4(1);
        }
        p->unk2++;
    }
}

s32 func_801B112C(arg0) {
    MgTask *a;
    MgTask *b;
    MgSVec *p;
    s32 v;

    a = (MgTask *)&D_80162978[func_800BBEAC(func_801B0F30)];
    b = (MgTask *)&D_80162978[func_800BBEAC(func_801B0D6C)];
    p = (MgSVec *)&a->unk4;
    func_800D3994(arg0, D_8015190F[arg0][0], p);
    *(MgSVec *)&b->unk4 = *p;
    a->unkC = b->unkC = D_80151A46[arg0][0];
    v = D_801518F6[arg0][0] + 0xE0;
    if (v > 0x76C) {
        v = 0x76C;
    }
    b->unkE = v;
    a->unkE = v + 0xFA;
    if (v > 0x4F2) {
        v = 0x4F2;
    }
    a->unk10 = (v << 12) / 375;
    b->unk10 = (v << 12) / 500;
    b->unk12 = arg0;
    b->unk14 = D_801CAB20;
    ((DbTask *)0x1F800000)->unk0 = D_801B136C;
    D_801CAB20++;
    ((DbTask *)0x1F800000)->unk2C = b->unk14;
    func_801B0314((DbTask *)0x1F800000);
    return func_800D55F4(0x20, func_800D56A8(p), 0x7F);
}

INCLUDE_RODATA("../asm/us/magic_debaria/nonmatchings/text", D_801B0000);

s32 func_801B12F8(arg0, arg1) {
    s32 temp_v0;

    D_801CAB1C = &D_80162978[func_800BBEAC(&D_801B0000)];
    temp_v0 = func_800D5444(arg0, arg1, 3, &func_801B112C);
    D_801CAB20 = 0;
    return temp_v0;
}
