#include "common.h"
#include "magic_yu_waku/decls.h"

void func_801B0000(void) {
    func_801B0DC8();
}

void func_801B0020(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801E8784 = D_801D0784 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 0xA);
        p->unk0 = -1;
    }
}

void func_801B00B0(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, 0);
    frame = &D_801D0714;
    *frame = p->unk2;
    D_801E8784 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801E8784);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC -= p->unkC / 8;
        p->unkE -= p->unkE / 8;
        p->unk10 -= p->unk10 / 8;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == D_801D0588) {
            p->unk0 = -1;
        }
    }
}

void func_801B01EC(void) {
    MgTask *p;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D0720[0] = p->unk2 % D_801D0724[p->unk16]->unk4;
    *(MgAnim **)&D_801D0720[-4] = D_801D0724[p->unk16];
    D_801E8784 = (u8 *)func_800D4D90(&D_801D0720[-4], D_801517C0 + 0x70, 0xC, (s32)D_801E8784);
    if (D_80062D98 == 0) {
        p->unk1A++;
        p->unk6 += func_80039A74(p->unk1A << 9) * 0x32 >> 12;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == D_801D0724[p->unk16]->unk4 * 2) {
            p->unk0 = -1;
        }
    }
}

void func_801B0370(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D073C;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801D0740[p->unk16];
    D_801E8784 = (u8 *)func_800D4D90(q, D_801517C0 + 0x70, 0xC, (s32)D_801E8784);
    if (D_80062D98 == 0) {
        p->unk6 += 0xB4;
        p->unk2++;
        if (p->unk2 == D_801D0740[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B046C(void) {
    MgMat m;
    MgMat m2;
    MgVec v;
    MgSVec rot;
    MgSVec *rp;
    MgVec *vp;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 n;

    p = &D_80162978[D_8015169C];
    vp = &v;
    rp = &rot;
    v.vx = v.vy = v.vz = p->unk18 * 9 >> 2;
    rot.vx = -0x400;
    rot.vy = p->unk16;
    rot.vz = 0;
    func_8003C21C(rp, &m);
    func_8003B35C(&m, vp);
    m.t[0] = p->unk4 + (func_80039A74((p->unk1A << 12) / 20) >> 2);
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    func_8003B69C(0, 0, 0);
    D_801D0754[0] = 0x88;
    *(u8 **)&D_801D0754[-1] = D_801CCF74;
    D_801E8784 = func_800D29D4(&D_801D0754[-1], D_801517C0 + 0x70, 0xC, D_801E8784);
    v.vx = v.vy = v.vz = p->unk18;
    func_8003C21C(rp, &m);
    func_8003B35C(&m, vp);
    m.t[0] = p->unk4 + (func_80039A74((p->unk1A << 12) / 20) >> 2);
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    D_801D0754[0] = 0x80;
    *(s32 **)&D_801D0754[-1] = D_801D0760[(s16)(p->unk2 % 7)];
    D_801E8784 = func_800D29D4(&D_801D0754[-1], D_801517C0 + 0x70, 0xC, D_801E8784);
    if (D_80062D98 == 0) {
        i = 0;
        if (p->unk2 < 0x14) {
            p->unk16 += 0x80;
            p->unk1A++;
            p->unk4 += p->unkC;
            p->unk8 += p->unk10;
            do {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B01EC)];
                q->unk4 = p->unk4 + func_80042DA8() % 400 - 0xC8;
                q->unk6 = p->unk6 + func_80042DA8() % 400 - 0xC8;
                q->unk8 = p->unk8 + func_80042DA8() % 400 - 0xC8;
                q->unk16 = func_80042DA8() % 4;
                q->unk1A = func_80042DA8();
                i++;
            } while (i < 2);
        }
        if (p->unk2 >= 0x14) {
            i = 0;
            p->unk16 += 0x200;
            p->unk6 += 0x28;
            p->unk18 -= 0xC8;
            do {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0370)];
                D_801D0780 = func_80042DA8() % 0x1000;
                q->unk4 = p->unk4 + (func_80039A74(D_801D0780) * p->unk18 / 12 >> 12);
                q->unk8 = p->unk8 + (func_80039B40(D_801D0780) * p->unk18 / 12 >> 12);
                q->unk6 = p->unk6 + func_80042DA8() % 200 - 0x64;
                q->unk16 = func_80042DA8() % 4;
                i++;
            } while (i < 2);
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0A48(void) {
    MgSVec rot;
    u8 pad[8];
    MgSVec pos;
    MgMat m;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 n;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B046C)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk1A = 0;
            q->unk16 = 0;
            q->unk18 = 0x1000;
            q->unk14 = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q->unk6 = -0x640;
            q->unkC = (p->unkC - p->unk4) / 20;
            q->unkE = 0;
            q->unk10 = (p->unk10 - p->unk8) / 20;
        }
        if (p->unk2 == 0x28) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B00B0)];
                func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
                pos.vz = 0x50;
                pos.vx = 0;
                pos.vy = 0;
                rot.vx = i * 0x100;
                rot.vy = func_80042DA8();
                rot.vz = 0;
                func_8003C21C(&rot, &m);
                func_8003B2CC(&m, &pos, (MgSVec *)&q->unkC);
                i++;
                q->unk4 += q->unkC * 4;
                q->unk6 += q->unkE * 4;
                q->unk8 += q->unk10 * 4;
            } while (i < 0x10);
            func_800D5774(p->unk1C);
        }
        if (p->unk2 < 8) {
            D_801D077C += 6;
        }
        if (p->unk2 >= 0x35) {
            D_801D077C -= 6;
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0D08(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0A48)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

s32 func_801B0DC8(arg0, arg1) {
    func_800BBEAC((M2C_UNK *)func_801B0020);
    func_800D2980((M2C_UNK *)D_801B0E74, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, (M2C_UNK *)func_801B0D08);
    func_800BBA84(0x7D, arg1, 0x40);
    D_800F5B70 = 0x40;
    D_800F5B71 = 0x20;
    D_800F5B72 = 0x60;
    return func_800D52A0(0x1000, 0xA);
}
