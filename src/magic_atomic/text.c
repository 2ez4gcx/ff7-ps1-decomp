#include "common.h"
#include "magic_atomic/decls.h"

void func_801B008C(MgSVec *pos, MgSVec *rot, s16 scale) {
    MgMat m[2];
    MgVec unused;
    s32 flag;
    s16 i;

    for (i = 0; i < 3; i++) {
        m[1].m[0][i] = m[1].m[1][i] = m[1].m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(pos, (MgVec *)m[1].t, &flag);
    m[1].m[0][0] = m[1].m[1][1] = m[1].m[2][2] = scale;
    func_8003C21C(rot, &m[0]);
    func_8003B05C(&m[1], &m[0]);
    func_8003B48C(&m[1]);
    func_8003B51C(&m[1]);
}

void func_801B0168(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk16 == 4 ? 0x4000 : 0x2000, 0);
    frame = &D_801D6880;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801D6884[p->unk16];
    D_801EEAA4 = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_801EEAA4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D6884[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0268(void) {
    MgVec sc;
    u8 pad1[16];
    MgMat m;
    u8 pad2[32];
    MgMat lw;
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_8003BF8C((MgSVec *)&p->unkC, &m);
    func_8003A79C(D_801D6A80, &m, &m);
    sc.vy = p->unk18;
    sc.vx = sc.vz = 0x2000;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D68A0[0] = D_801D68A4[p->unk2];
    D_80163C74 = func_800D4D90(&D_801D68A0[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x30) {
            p->unk0 = -1;
        }
    }
}

void func_801B03AC(void) {
    MgSVec v;
    u8 pad[16];
    MgMat m;
    s32 flag;
    MgTask *p;
    s16 n;
    s8 *col;
    s8 c;

    p = &D_80162978[D_8015169C];
    n = 8;
    if (p->unk2 >= 0x16) {
        n = 0x1E - p->unk2;
    }
    v.vx = (u32)(func_80039B40(p->unk14) * 0x19) >> 7;
    v.vz = (u32)(func_80039A74(p->unk14) * 0x19) >> 7;
    v.vy = 0;
    func_8003C21C((MgSVec *)&p->unkC, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003BADC(&v, &v, &flag);
    func_800D4368(&v, p->unk18, 0);
    col = &D_801D6908;
    c = n << 4;
    D_801D690A = c;
    D_801D6909 = c;
    *col = c;
    D_801EEAA4 = func_800D4D90(col - 4, D_801517C0 + 0x70, 0xC, D_801EEAA4);
    if (D_80062D98 == 0) {
        p->unk14 += 0x100;
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0548(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk2 % 2 * 0x400 + (p->unk16 == 0 ? 0x1000 : 0x2000), -0x320);
    D_801D6910[0] = D_801D691C[p->unk16];
    D_801EEAA4 = func_800D4D90(D_801D6910, D_801517C0 + 0x70, 0xC, D_801EEAA4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x30) {
            p->unk0 = -1;
        }
    }
}

void func_801B0654(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    MgTask *p;
    s32 n;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (p->unk2 >= 0x14) {
        n = 0x1C - p->unk2;
    } else {
        n = 8;
    }
    rot.vx = rot.vz = 0;
    D_801D6A48 = n;
    rot.vy = p->unk2 << 6;
    func_8003C21C(&rot, &m);
    D_801D6A4C[0] = D_801D6A50 = D_801D6A54 = p->unk2 * 0x190;
    func_8003B35C(&m, (MgVec *)D_801D6A4C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D6928[0] = 8;
    D_801D6928[-1] = (s32)D_801D4418;
    D_801D692E = D_801D6A48 * 0x10;
    D_801EEAA4 = func_800D29D4(&D_801D6928[-1], D_801517C0 + 0x70, 0xC, D_801EEAA4);
    D_801D6928[-1] = (s32)D_801D46BC;
    D_801EEAA4 = func_800D29D4(&D_801D6928[-1], D_801517C0 + 0x70, 0xC, D_801EEAA4);
    D_801D6928[0] = 0x88;
    D_801D6928[-1] = (s32)D_801D4890;
    t = D_801D6A48;
    D_801D692E = 0x1000 - (t << 9);
    D_801EEAA4 = func_800D29D4(&D_801D6928[-1], D_801517C0 + 0x70, 0xC, D_801EEAA4);
    func_800D4368(&p->unk4, p->unk2 % 2 * 0x400 + 0x1000, 0);
    D_801EEAA4 = func_800D4D90(D_801D6934, D_801517C0 + 0x70, 0xC, D_801EEAA4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x1C) {
            p->unk0 = -1;
        }
    }
}

void func_801B08E4(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801D6948[0] = D_801D6954[p->unk2];
    *(s32 *)&D_801D6948[-4] = D_801D694C[p->unk16];
    D_801EEAA4 = func_800D4D90(&D_801D6948[-4], D_801517C0 + 0x70, 0xC, D_801EEAA4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x1C) {
            p->unk0 = -1;
        }
    }
}

void func_801B09C8(void) {
    MgMat lw;
    MgMat m;
    MgSVec rot;
    MgTask *p;
    s16 *frame;

    p = &D_80162978[D_8015169C];
    rot.vx = rot.vz = 0;
    rot.vy = p->unk2 << 6;
    func_8003C21C(&rot, &m);
    D_801D6A5C[0] = D_801D6A64.v = p->unk2 * 0xFA + 0x800;
    D_801D6A60 = 0x4000 - p->unk2 * 0x320;
    func_8003B35C(&m, (MgVec *)D_801D6A5C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801D6996;
    *frame = 0x80 - p->unk2 * 4;
    D_801EEAA4 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801EEAA4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B0B44);

INCLUDE_RODATA("../asm/us/magic_atomic/nonmatchings/text", D_801B0000);

void func_801B0E88(void) {
    MgMat lw;
    MgMat m;
    MgTask *p;
    s16 *frame;
    s32 t;

    m = D_801B0000;
    p = &D_80162978[D_8015169C];
    D_801D6A6C[0] = D_801D6A6C[1] = D_801D6A6C[2] = p->unk2 < 8 ? p->unk2 * 0x600 : 0x3000;
    func_8003B35C(&m, (MgVec *)D_801D6A6C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    frame = &D_801D6A42;
    t = D_801D6A36;
    *frame = t << 9;
    D_801EEAA4 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801EEAA4);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x5D) {
            D_801D6A36++;
        }
        if (++p->unk2 == 0x64) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B1050);

void func_801B18B8(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B1050)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_RODATA("../asm/us/magic_atomic/nonmatchings/text", D_801B0020);

void func_801B1978(arg0, arg1) {
    func_800BBEAC(D_801B0020);
    func_800D2980(D_801B19F4, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B18B8);
    func_800BBA84(0xCF, arg1, 0);
}
