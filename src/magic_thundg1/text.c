#include "common.h"
#include "magic_thundg1/decls.h"

void func_801B000C(void) {
    func_801B0F00();
}

INCLUDE_RODATA("../asm/us/magic_thundg1/nonmatchings/text", D_801B0000);

void func_801B002C(void) {
    ThSprC t;
    MgTask *p;
    s32 c;
    s32 k;

    t = D_801B0000;
    p = (MgTask *)&D_80162978[D_8015169C];
    k = p->unk2;
    if (k < 0) {
        D_801D3BE4 = 0x100;
    } else if (k <= 0) {
        D_801D3BE4 = 0x2500;
    } else {
        k -= 1;
        if (k < 8) {
            c = -0x80 - k * 0x10;
            D_801D3BE4 = 0x2500;
            t.r = t.g = t.b = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_800D4284(&p->unk8, p->unk18, &D_801D3BE4);
    func_8003B48C(&D_801D3BE4);
    func_8003B51C(&D_801D3BE4);
    D_801D3BE0 = func_800D4D90(&t, D_801517C0 + 0x70, 0xC, D_801D3BE0);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_thundg1/nonmatchings/text", func_801B0174);

void func_801B0490(void) {
    MgTask *p;
    s16 *frame;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    frame = &D_801D3C4C;
    *frame = (u16)p->unk2 << 16 >> 24;
    func_800D4368(&p->unk8, 0x2000, 0);
    D_801D3BE0 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D3BE0);
    if (D_80062D98 == 0) {
        t = p->unk2 + 0x100;
        p->unk2 = t;
        if (t >> 8 >= D_801D16FC) {
            p->unk0 = -1;
        }
    }
}

void func_801B055C(void) {
    MgMat m;
    MgVec sc;
    u8 pad[8];
    MgTask *p;
    s32 t;
    u32 a;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = (u16)p->unk2 & 0xF;
    a = t << 16;
    D_801D3C58[0] = ((t & 1) << 7) | ((a >> 3) & 0xC000);
    D_801D3C58[2] = ((s32)a >> 19) | 0x20;
    sc.vx = sc.vy = sc.vz = p->unk2 * 0x2800 / 23;
    k = p->unk2;
    if (k < 0xF) {
        D_801D3C58[1] = 0x80;
    } else {
        k -= 0xF;
        if (k < 8) {
            D_801D3C58[1] = -(k << 7) / 8 + 0x80;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003C21C((MgSVec *)&p->unk10, &m);
    m.t[0] = p->unk8;
    m.t[1] = p->unkA;
    m.t[2] = p->unkC;
    func_8003B35C(&m, &sc);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801D3BE0 = func_800D29D4(&D_801D3C50, D_801517C0 + 0x70, 0xC, D_801D3BE0);
    if (D_80062D98 == 0) {
        *(u16 *)&p->unk10 = *(u16 *)&p->unk10;
        *(u16 *)&p->unk12 = *(u16 *)&p->unk12;
        *(u16 *)&p->unk14 = *(u16 *)&p->unk14;
        p->unk2++;
    }
}

void func_801B0724(void) {
    MgMat m;
    MgTask *p;
    s16 *q;
    s32 k;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = p->unk2;
    if (k < 8) {
        D_801D3C6A = 0x80;
    } else {
        k -= 8;
        if (k < 8) {
            D_801D3C6A = -(k << 7) / 8 + 0x80;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    v = p->unk2 * 0x600;
    q = &D_801D3C70;
    D_801D3C7A[2] = v;
    *q = v;
    D_801D3C7A[0] = -v;
    D_801D3C84[0] = p->unk8;
    D_801D3C84[1] = p->unkA;
    D_801D3C84[2] = p->unkC;
    func_8003A63C(&D_800FA63C, (MgMat *)q, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801D3BE0 = func_800D29D4(&D_801D3C60, D_801517C0 + 0x70, 0xC, D_801D3BE0);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0890(void) {
    MgTask *p;
    MgTask *q;
    ThBolt *b;
    MgSVec v;
    s32 k;
    s32 i;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t == 0) {
            func_800D52A0(0x800, 4);
            D_800F5B70[2] = D_800F5B70[1] = D_800F5B70[0] = 0;
            t = p->unk2;
        }
        k = t - 4;
        if (k == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B002C)];
            q->unk8 = p->unk8;
            q->unkA = 0;
            q->unkC = p->unkC;
            q->unk18 = -D_801518F6[p->unk4][0];
        }
        if (k == 4) {
            func_800D5774(p->unk4);
        }
        if (k == 2) {
            i = 0;
            do {
                i++;
                b = (ThBolt *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0174)];
                b->unk4 = p->unk8;
                b->unk6 = 0;
                b->unk8 = p->unkC;
                b->unkC = func_80042DA8() % 200 - 100;
                b->unkE = -(func_80042DA8() % 200 + 200);
                b->unk10 = func_80042DA8() % 200 - 100;
                b->unk18[0] = func_80042DA8() % 40 - 20;
                b->unk18[1] = func_80042DA8() % 20 - 10;
                b->unk18[2] = func_80042DA8() % 10 - 5;
                b->unk1C = func_80042DA8() % 0x1E00 + 0x200;
                b->unk0 = 0;
            } while (i < 10);
        }
        if ((u32)k < 0x10) {
            i = 0;
            do {
                i++;
                v.vx = p->unk8 + func_80042DA8() % 1600 - 800;
                v.vy = 0;
                v.vz = p->unkC + func_80042DA8() % 1600 - 800;
                func_800D3F0C(&v, 0x3000, 0x3000);
            } while (i < 3);
        }
        if ((u32)(k - 1) < 0xF) {
            i = 0;
            do {
                i++;
                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0490)];
                q->unk8 = p->unk8 + func_80042DA8() % 2000 - 1000;
                q->unkA = p->unkA + func_80042DA8() % 2000 - 1000;
                q->unkC = p->unkC + func_80042DA8() % 2000 - 1000;
            } while (i < 1);
        }
        if (k == 2) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B055C)];
            *(ThB8 *)&q->unk8 = *(ThB8 *)&p->unk8;
            q->unk14 = 0;
            q->unk12 = 0;
            q->unk10 = 0;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0724)];
            q->unk8 = p->unk8;
            q->unkA = 0;
            q->unkC = p->unkC;
        }
        if (k == 0x1E) {
            func_800D52A0(0, 4);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0E0C(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0890)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk8);
}

void func_801B0E98(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D3BE0 = D_801D3C90 + p->unk2 * 0xE000;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
    p->unk2 ^= 1;
}

void func_801B0F00(arg0, arg1) {
    func_800D2980(&D_801B0F80, 0, 0, 0);
    func_800BBEAC((M2C_UNK *)func_801B0E98);
    func_800D5444(arg0, arg1, 0, func_801B0E0C);
    func_800D55F4(0x20, 0x40, 0x46);
}
