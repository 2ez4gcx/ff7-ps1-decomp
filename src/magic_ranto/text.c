#include "common.h"
#include "magic_ranto/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B079C();
    return &D_801B6C2C;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C9668 = D_801B9668 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0088(void) {
    MgTask *p;
    u16 *frame;
    s16 t;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x4000, 0);
    frame = &D_801B9650;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        t = p->unk2 + 1;
        p->unk2 = t;
        if (t == D_801B6874) {
            p->unk0 = -1;
        }
    }
}

void func_801B0170(void) {
    MgSVec a;
    MgSVec b;
    MgTask *p;
    MgTask *q;
    u16 *w;
    u16 *w2;
    u16 *w3;
    u16 *w4;
    u16 *s;
    s16 id;
    s32 n;
    MgTask *q2;
    s32 ang;
    s16 k;
    s16 i;
    s16 c;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (D_801B9654 < 8 && p->unk2 == D_801B9658[D_801B9654]) {
            id = D_801517F0[D_801B9654];
            n = id;
            s = (u16 *)D_80151A4C[n];
            a.vx = s[0];
            a.vy = s[1];
            a.vz = s[2];
            r = func_80042DA8();
            ang = r - r / 0x1000 * 0x1000;
            k = *(u16 *)D_801518F6[n] + 0x5DC;
            b.vx = a.vx = a.vx + (func_80039A74(ang) * k >> 12);
            b.vy = 0;
            b.vz = a.vz = a.vz + (func_80039B40(ang) * k >> 12);
            w = (u16 *)D_80151A4C[p->unk1E];
            w[0] = b.vx;
            w = (u16 *)D_80151A4C[p->unk1E];
            w[1] = b.vy;
            w = (u16 *)D_80151A4C[p->unk1E];
            w[2] = b.vz;
            w = (u16 *)(((u8 *)D_80151A4C - 8) + p->unk1E * 0xB9C);
            w[0] = 0;
            w = (u16 *)(((u8 *)D_80151A4C - 8) + p->unk1E * 0xB9C);
            w[1] = ang;
            w = (u16 *)(((u8 *)D_80151A4C - 8) + p->unk1E * 0xB9C);
            w[2] = 0;
            q2 = (MgTask *)func_800D4FA8(0xA);
            q2->unk0 = id;
            q2->unk10 = D_801B9654;
            func_800BBA84(0x15A, n, 0);
            D_801B9654++;
        }
        if ((u16)(p->unk2 - 0x1F) < 0x28U) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0088)];
                w2 = (u16 *)D_80151A4C[p->unk1E];
                q->unk4 = w2[0];
                w3 = (u16 *)D_80151A4C[p->unk1E];
                q->unk6 = w3[1];
                w4 = (u16 *)D_80151A4C[p->unk1E];
                q->unk8 = w4[2];
                r = func_80042DA8();
                c = r % 0x1000;
                q->unkC = (u32)(func_80039A74(c) * 0x19) >> 9;
                q->unkE = -func_80042DA8() % 100;
                q->unk10 = (u32)(func_80039B40(c) * 0x19) >> 9;
                i++;
            } while (i < 2);
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0088)];
                r = func_80042DA8();
                c = r % 0x1000;
                k = func_80042DA8() % 4000;
                q->unk4 = *(u16 *)D_801C9670 + (func_80039A74(c) * k >> 12);
                q->unk6 = 0;
                q->unk8 = *(u16 *)(D_801C9670 + 4) + (func_80039B40(c) * k >> 12);
                r = func_80042DA8();
                c = r % 0x1000;
                q->unkC = (u32)(func_80039A74(c) * 0x19) >> 10;
                q->unkE = -func_80042DA8() % 100;
                q->unk10 = (u32)(func_80039B40(c) * 0x19) >> 10;
                i++;
            } while (i < 2);
        }
        p->unk2++;
        if (p->unk2 == 0x50) {
            p->unk0 = -1;
        }
    }
}

void func_801B079C(arg0, arg1) {
    func_800BBEAC(func_801B0028);
    func_800D2980(D_801B0830, 0, 0, 0);
    D_801C966C = arg0;
    func_800D54EC(arg0, D_801C9670);
    D_80162996[func_800BBEAC(func_801B0170)].unk0 = arg1;
}
