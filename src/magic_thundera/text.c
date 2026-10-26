#include "common.h"
#include "magic_thundera/decls.h"

void func_801B0000(void) {
    func_801B08F4();
}

void func_801B0020(void) {
    MgMat m;
    MgTask *p;
    s16 c;
    u16 f;
    u16 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    a = p->unkE;
    f = p->unk2;
    m.m[0][0] = m.m[2][1] = a;
    m.m[1][2] = -p->unkE;
    m.m[2][2] = 0;
    m.m[2][0] = 0;
    m.m[1][1] = 0;
    m.m[1][0] = 0;
    m.m[0][2] = 0;
    m.m[0][1] = 0;
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    c = 0x80 - f * 0x10;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    *(M2C_UNK **)0x1F800000 = &D_801B0C08;
    *(s32 *)0x1F800004 = 8;
    *(s16 *)0x1F800008 = 0;
    *(s16 *)0x1F80000A = c;
    *(s16 *)0x1F80000C = 0x20;
    *(s16 *)0x1F80000E = 0;
    D_801E90EC = func_800D29D4(0x1F800000, D_801517C0 + 0x70, 0xC, D_801E90EC);
    if (D_80062D98 == 0) {
        p->unkE += p->unk10;
        p->unk10 -= p->unk10 >> 2;
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B01A0(void) {
    MgObj20 *temp_s0;
    s16 temp_v0_2;
    s8 temp_v0;

    *(M2C_UNK **)0x1F800000 = &D_801B097C;
    *(s16 *)0x1F800008 = 0;
    temp_s0 = &D_80162978[D_8015169C];
    temp_v0 = ~(M2C_FIELD(temp_s0, u8 *, 2) << 6);
    *(s8 *)0x1F800007 = 0x2C;
    *(s8 *)0x1F800006 = temp_v0;
    *(s8 *)0x1F800005 = temp_v0;
    *(s8 *)0x1F800004 = temp_v0;
    func_800D4368(&temp_s0->unk4, 0x2000, M2C_FIELD(temp_s0, s16 *, 0x14));
    D_801E90EC = func_800D4D90(0x1F800000, D_801517C0 + 0x70, 0xC, D_801E90EC);
    if (D_80062D98 == 0) {
        temp_v0_2 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0_2;
        if (temp_v0_2 == 4) {
            temp_s0->unk0 = -1;
        }
    }
}

void func_801B028C(void) {
    MgTask *p;
    s16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, p->unk14);
    frame = &D_801C90C4;
    *frame = p->unk2 >> 1;
    D_801E90EC = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E90EC);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B0348(void) {
    s32 sp10[2];
    MgTask *p;
    u8 *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(&p->unk4, D_801C90C8.t, sp10);
    D_801C90C8.t[2] += p->unk14;
    q = (u8 *)0x1F800000;
    if (p->unk12 & 1) {
        D_801C90C8.m[0][0] = -0x2000;
    } else {
        D_801C90C8.m[0][0] = 0x2000;
    }
    if (p->unk12 & 2) {
        D_801C90C8.m[1][1] = -0x2000;
    } else {
        D_801C90C8.m[1][1] = 0x2000;
    }
    func_8003B48C(&D_801C90C8);
    func_8003B51C(&D_801C90C8);
    if (p->unk12 & 4) {
        *(M2C_UNK **)q = &D_801B09B0;
    } else {
        *(M2C_UNK **)q = &D_801B0A78;
    }
    *(s32 *)(q + 4) = 0x2C808080;
    *(s16 *)(q + 8) = p->unk2;
    D_801E90EC = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_801E90EC);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B04D8(void) {
    MgObjThunder *p;
    MgObjThunder *q;
    u16 t;

    p = (MgObjThunder *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 1) {
            q = (MgObjThunder *)&D_80162978[func_800BBEAC((M2C_UNK *)&func_801B01A0)];
            q->unk4 = p->unk4;
            q->unk4.vy = 0;
            q->unk14 = p->unk14;
            func_800D5774(p->unkC);
        }
        t = p->unk2;
        if (t < 0x15 && !(t & 1)) {
            q = (MgObjThunder *)&D_80162978[func_800BBEAC(&func_801B0020)];
            q->unk4.vx = p->unk4.vx + func_80042DA8() % 2000 - 1000;
            q->unk4.vy = 0;
            q->unk4.vz = p->unk4.vz + func_80042DA8() % 2000 - 1000;
            q->unkE = 0x1000;
            q->unk10 = 0x800;
        }
        if (p->unk2 == 8) {
            q = (MgObjThunder *)&D_80162978[func_800BBEAC(&func_801B028C)];
            q->unk4 = p->unk4;
            q->unk14 = p->unk14;
        }
        if ((u16)p->unk2 < 0x10) {
            q = (MgObjThunder *)&D_80162978[func_800BBEAC(&func_801B0348)];
            q->unk4.vx = p->unk4.vx + func_80042DA8() % 1000 - 500;
            q->unk4.vy = p->unk4.vy + func_80042DA8() % 1000 - 500;
            q->unk4.vz = p->unk4.vz + func_80042DA8() % 1000 - 500;
            q->unk12 = func_80042DA8() & 7;
            q->unk14 = p->unk14;
        }
        p->unk2++;
        if (p->unk2 == 0x15) {
            p->unk0 = -1;
        }
    }
}

void func_801B07F0(s32 arg0) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B04D8)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    p->unk14 = -D_801518F6[arg0][0];
    p->unkC = arg0;
}

void func_801B0894(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E90EC = D_801C90EC + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B08F4(arg0, arg1) {
    func_800D2980(&D_801B0E9C, 0, 0, 0);
    func_800BBEAC(func_801B0894);
    func_800D5444(arg0, arg1, 2, &func_801B07F0);
    func_800D55F4(0x20, func_800D574C(arg0), 0xC);
}
