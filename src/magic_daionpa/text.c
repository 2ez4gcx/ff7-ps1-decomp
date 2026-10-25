#include "common.h"
#include "magic_daionpa/decls.h"

void func_801B0000(void) {
    func_801B0D98();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EC4B4 = D_801D44B4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801D4418[0] = p->unk2;
    *(MgAnim **)&D_801D4418[-4] = D_801D441C[p->unk14];
    D_801EC4B4 = func_800D4D90(&D_801D4418[-4], D_801517C0 + 0x70, 0xC, D_801EC4B4);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 == D_801D441C[p->unk14]->unk4) {
            p->unk0 = -1;
        }
    }
}

void func_801B01AC(void) {
    MgTask *p;
    MgMat m;
    MgMat rot;
    s32 flag;
    s16 i;
    s32 t;

    p = &D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = p->unk2 * 600 + 0x800;
    func_8003C21C(&D_801D4444, &rot);
    func_8003B05C(&m, &rot);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801D443E[0] = t << 8;
    D_801EC4B4 = func_800D29D4(&D_801D443E[-5], D_801517C0 + 0x70, 0xC, D_801EC4B4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 15) {
            p->unk0 = -1;
        }
    }
}

void func_801B0324(void) {
    MgMat m;
    MgMat pad;
    MgSVec rot;
    MgTask *p;
    s32 *t;
    s32 c;
    MgHalf *frame;

    p = &D_80162978[D_8015169C];
    func_8003B64C(&D_801D44AC, &D_801D44B0);
    func_8003B6BC(0xA0, 0x64);
    t = &D_801D4454;
    *t = p->unk2 * 0x12C + 0x2000;
    rot.vx = 0x400;
    rot.vy = p->unk2 << 5;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    func_8003B35C(&m, (MgVec *)((u8 *)t - 4));
    m.t[0] = 0;
    m.t[1] = 0;
    m.t[2] = 0x1F40;
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    frame = (MgHalf *)&D_801D446A;
    c = D_801D444C;
    frame->v = 0x1000 - (c << 8);
    D_801EC4B4 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801EC4B4);
    func_8003B6BC(D_801D44AC, D_801D44B0);
    if (D_80062D98 == 0) {
        if (p->unk2 < 8) {
            D_801D444C++;
        }
        if (p->unk2 >= 0x17) {
            D_801D444C--;
        }
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B04FC(void) {
    MgMat m;
    MgMat r;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    s16 i;
    s16 n;
    s16 t;
    s16 c;
    MgColTag *q;

    rot.vy = 0;
    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vz = p->unk2 << 8;
    for (i = 0; i < 3; i++) {
        m.m[i][0] = m.m[i][1] = m.m[i][2] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x1400;
    func_8003C21C(&rot, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
    t = p->unk2;
    if (t >= 12) {
        n = 20 - t;
    } else {
        n = 8;
    }
    q = &D_801D4470;
    q->tag = D_801D447C[p->unk14];
    q->r = q->g = q->b = n << 4;
    D_801EC4B4 = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_801EC4B4);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        c = p->unk2 + 1;
        p->unk2 = c;
        if (c == 20) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_daionpa/nonmatchings/text", func_801B06E4);

void func_801B0D98(arg0, arg1) {
    MgTask *p;
    

    func_800BBEAC(func_801B0020);
    D_801EC4B8 = arg0;
    func_800D2980(D_801B0E98, 0, 0, 0);
    p = &D_80162978[func_800BBEAC(func_801B06E4)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D54EC(arg0, &p->unkC);
    func_800BBA84(0x118, arg1, 0);
    func_800D52A0(0xF00, 0xA);
    D_800F5B70 = 0;
    D_800F5B71 = 0;
    D_800F5B72 = 0x20;
}
