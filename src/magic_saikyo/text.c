#include "common.h"
#include "magic_saikyo/decls.h"

void func_801B0000(void) {
    func_801B10A8();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EE0F4 = D_801D60F4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B008C);

void func_801B0274(void) {
    MgTask *p;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = D_801D6030;
    D_80163C74 = func_800C4FC8(t, t >> 2, 0);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x10) {
            D_801D6030 += 0xF;
        }
        if (p->unk2 >= 0x11) {
            D_801D6030 -= 0xF;
        }
        p->unk2++;
        if (p->unk2 == 0x20) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B035C);

void func_801B0758(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    D_801D607C[0] = p->unk2;
    D_801EE0F4 = func_800D4D90(&D_801D607C[-4], D_801517C0 + 0x70, 0xC, D_801EE0F4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D5DA4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0810(void) {
    MgMat m;
    MgMat m2;
    MgSVec rot;
    MgTask *p;
    s32 *q;

    rot.vx = rot.vy = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vz = p->unk14;
    func_8003BF8C(&rot, &m);
    q = &D_801D60D4;
    *q = D_801D60D8 = D_801D60DC = 0x1000;
    func_8003B35C(&m, q);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    D_801D608A[0] = 0x80 - p->unk2 * 8;
    *(u8 **)&D_801D608A[-5] = D_801D6090[p->unk16];
    D_801EE0F4 = (u8 *)func_800D29D4(&D_801D608A[-5], D_801517C0 + 0x70, 0xC, (s32)D_801EE0F4);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x190;
        p->unk14 += 0x100;
        if (++p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B0980(void) {
    MgTask *p;
    u8 c;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D60A8[0] = p->unk16;
    c = 0x80 - p->unk2 * 8;
    D_801D60A6 = c;
    D_801D60A5 = c;
    D_801D60A4 = c;
    D_801EE0F4 = func_800D4D90(&D_801D60A8[-4], D_801517C0 + 0x70, 0xC, D_801EE0F4);
    if (D_80062D98 == 0) {
        p->unk6 -= 300;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 15) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_saikyo/nonmatchings/text", func_801B0A68);

void func_801B0F3C(void) {
    u8 pad[0x30];
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 k;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            k = -0x4B0;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B035C)];
            q->unk4 = 0;
            q->unk6 = k;
            q->unk8 = 0;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0A68)];
            q->unk4 = 0;
            q->unk6 = k;
            q->unk8 = 0;
            func_800BBA84(0x164, -1, 0x40);
        }
        if (p->unk2 == 0xC) {
            func_800BBEAC((M2C_UNK *)func_801B0274);
        }
        if (p->unk2 == 0x1C) {
            func_800D52A0(0, 0x10);
        }
        if (p->unk2 == 0x28) {
            for (i = 0; i < 10; i++) {
                if ((D_801EE0F8 >> i) & 1) {
                    func_800D5774(i);
                }
            }
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x32) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B10A8(arg0, arg1) {
    MgTask *p;

    func_800BBEAC((M2C_UNK *)func_801B0020);
    func_800D2980(&D_801B118C, 0, 0, 0);
    D_801EE0F8 = arg0;
    p = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0F3C)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D54EC(arg0, &p->unkC);
    D_800F5B72.v = 0;
    D_800F5B71.v = 0;
    D_800F5B70.v = 0;
    return func_800D52A0(0x1000, 0x10);
}
