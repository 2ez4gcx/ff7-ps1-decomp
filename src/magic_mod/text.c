#include "common.h"
#include "magic_mod/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B1350();
    return &D_801B8FA8;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D23B0 = D_801BA3B0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0094(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    frame = &D_801BA268;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801BA26C[p->unk16];
    D_801D23B0 = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_801D23B0);
    if (D_80062D98 == 0) {
        if (p->unk16 == 2) {
            p->unk6 -= 0x64;
        }
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == D_801BA26C[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_mod/nonmatchings/text", func_801B01A4);

void func_801B081C(void) {
    MgVec sc;
    MgMat m;
    u8 pad[0x20];
    MgMat lw;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801BA314, &m);
    sc.vx = sc.vy = sc.vz = p->unk18 * 0x50;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801D23B0 = func_800D29D4(D_801BA304, D_801517C0 + 0x70, 0xC, D_801D23B0);
    if (D_80062D98 == 0) {
        p->unk1A += 1;
        if (p->unk2 < 0x10) {
            p->unk18 += 8;
        }
        if (p->unk2 >= 0x2D) {
            p->unk18 -= 8;
        }
        if (++p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_mod/nonmatchings/text", func_801B0994);

void func_801B0B4C(void) {
    MgTask *p;
    MgTask *q;
    s16 r;
    s16 i;
    s16 n;
    s32 t;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            r = func_80042DA8() % 0x1000;
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0094)];
            q->unk4 = p->unk4 + (func_80039A74(r) * 0x190 >> 12);
            t = func_80042DA8();
            k = (u16)p->unk6 + p->unk2 * 0x1E;
            q->unk6 = t % 600 + k - 0x320;
            q->unk8 = p->unk8 + (func_80039B40(r) * 0x190 >> 12);
            q->unk16 = p->unk16;
        } while (++i < 2);
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0CE8(void) {
    MgTask *p;
    MgTask *q;
    s16 a;
    s16 d;
    MgSVec m;
    MgSVec *v;
    s16 i;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0xA) {
            i = 0;
            a = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B01A4)];
            q->unk4 = p->unk4 - (func_80039A74(a) * 0x12C0 >> 12);
            q->unk8 = p->unk8 - (func_80039B40(a) * 0x12C0 >> 12);
            q->unk6 = -0x4B0;
            do {
                v = &D_801BA330[i];
                v->vx = q->unk4;
                v->vy = q->unk6;
                v->vz = q->unk8;
                i++;
            } while (i < 0x10);
            m.vx = p->unkC - q->unk4;
            m.vz = p->unk10 - q->unk8;
            d = func_80039F5C(m.vx * m.vx + m.vz * m.vz);
            q->unk18 = 0;
            q->unk1A = d / 200;
            q->unkC = (u32)(func_80039A74(a) * 0x19) >> 9;
            q->unk10 = (u32)(func_80039B40(a) * 0x19) >> 9;
            q->unkE = 0x3E8 / d;
            p->unk1A = q->unk1A + 0xA;
        }
        if (p->unk2 == 0x22) {
            D_8009A000 = 0x28;
            D_8009A004 = func_800D56A8(&p->unk4);
            D_8009A008 = 0x69;
            func_8002DA7C();
        }
        if (p->unk2 == p->unk1A) {
            i = 0;
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B081C)];
            q->unk4 = p->unkC;
            q->unk6 = p->unkE;
            q->unk8 = p->unk10;
            q->unk18 = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0994)];
                q->unk4 = p->unkC;
                q->unk6 = p->unkE;
                q->unk8 = p->unk10;
                q->unk16 = func_80042DA8() % 2;
                q->unk1A = func_80042DA8() % 4;
                q->unk18 = 0;
                q->unk14 = (i << 16) >> 9;
            } while (++i < 0x20);
            D_800F5B70 = D_800F5B71 = D_800F5B72 = 0x10;
            func_800D52A0(0x1000, 0xA);
            D_8009A000 = 0x29;
            D_8009A004 = func_800D56A8(&p->unk4 + 4);
            D_8009A008 = 0x241;
            func_8002DA7C();
        }
        if (p->unk2 == p->unk1A + 0x14) {
            func_800D5774(p->unk1C);
        }
        if (p->unk2 == p->unk1A + 0x28) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0B4C)];
            func_800D3994(p->unk1E, D_8015190F[p->unk1E][0], &q->unk4);
            q->unk16 = 0;
            D_8009A000 = 0x28;
            D_8009A004 = func_800D56A8(&p->unk4);
            D_8009A008 = 0x1F;
            func_8002DA7C();
        }
        if (p->unk2 == p->unk1A + 0x3C) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0B4C)];
            func_800D3994(p->unk1E, D_8015190F[p->unk1E][0], &q->unk4);
            q->unk16 = 1;
            D_8009A000 = 0x28;
            D_8009A004 = func_800D56A8(&p->unk4);
            D_8009A008 = 8;
            func_8002DA7C();
        }
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == p->unk1A + 0x5A) {
            func_800D52A0(0, 0xA);
            p->unk0 = -1;
        }
    }
}

void func_801B126C(arg0, arg1) {
    MgTask *p;
    s16 *q;
    s16 (*b)[0x5CE];

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0CE8)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    b = D_80151A4C;
    q = b[arg0];
    p->unkC = q[0];
    p->unkE = q[1];
    p->unk10 = q[2];
    p->unk1E = arg1;
    p->unk1C = arg0;
    p->unk1A = 0x12C;
}

void func_801B1350(arg0, arg1) {
    func_800BBEAC(&func_801B0028);
    func_800D2980(&D_801B13BC, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B126C);
}
