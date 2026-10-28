#include "common.h"
#include "magic_shower/decls.h"

void func_801B0000(void) {
    func_801B0D58();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DB454 = D_801C3454 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk1A == 0 ? 0x2000 : 0x3000, 0);
    frame = &D_801C33F8;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801C33FC[p->unk1A];
    D_801DB454 = (u8 *)func_800D4D90(q, D_801517C0 + 0x70, 0xC, (s32)D_801DB454);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801C33FC[p->unk1A][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B018C(void) {
    MgTask *p;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk18, 0);
    D_801C3408[0] = D_801C3408[1] = D_801C3408[2] = p->unk2 >= 0x16 ? (0x1E - p->unk2) << 4 : 0x80;
    D_801DB454 = (u8 *)func_800D4D90(D_801C3404, D_801517C0 + 0x70, 0xC, (s32)D_801DB454);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        n = p->unk2 + 1;
        p->unkE += 0xA;
        p->unk2 = n;
        if (n == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B02B4(void) {
    MgMat m;
    MgMat r;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 *frame;
    s16 i;
    s16 a;

    p = &D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = p->unk2 * 0xC8 + 0x800;
    func_8003C21C(&D_801C3420, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    frame = &D_801C341A;
    *frame = p->unk2 * 0x40;
    D_801DB454 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801DB454);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x23) {
            for (i = 0; i < 2; i++) {
                q = &D_80162978[func_800BBEAC(&func_801B018C)];
                q->unk4 = p->unk4;
                q->unk6 = 0;
                q->unk8 = p->unk8;
                a = func_80042DA8() % 0x1000;
                q->unkC = (u32)(func_80039A74(a) * 0xF) >> 10;
                q->unk10 = (u32)(func_80039B40(a) * 0xF) >> 10;
                q->unkE = -0x96 - func_80042DA8() % 50;
                q->unk18 = (func_80042DA8() % 3 << 8) + 0x600;
            }
        }
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B056C(void) {
    MgSVec v;
    MgTask *p;
    u16 *frame;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801C3430;
    *frame = p->unk1A;
    D_801DB454 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801DB454);
    v.vx = p->unk4 + (func_80039B40(p->unk14) * p->unk16 >> 12);
    v.vy = p->unk6 + (func_80039A74(p->unk14) * p->unk16 >> 12);
    v.vz = p->unk8;
    func_800D4368(&v, p->unk18, 0);
    D_801DB454 = (u8 *)func_800D4D90(D_801C3434, D_801517C0 + 0x70, 0xC, (s32)D_801DB454);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        n = p->unk2 + 1;
        p->unk14 += 0x100;
        p->unk2 = n;
        if (n >> 1 == D_801C303C) {
            p->unk0 = -1;
        }
    }
}

void func_801B06FC(void) {
    MgSVec rot;
    MgSVec pos;
    MgMat m;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 n;
    s32 r;
    s32 a;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = (func_80039A74(p->unk2 << 6) * 0x140 >> 12) + 0x140;
        q = &D_80162978[func_800BBEAC(&func_801B056C)];
        q->unk4 = p->unk4;
        q->unk6 = p->unk6;
        q->unk8 = p->unk8;
        a = p->unk2 >> 1;
        q->unk18 = n * 5;
        q->unk1A = a;
        q->unk16 = n;
        r = func_80042DA8(a);
        q->unk14 = r % 0x1000;
        pos.vx = 0;
        pos.vy = 0;
        pos.vz = p->unk18;
        rot.vx = 0;
        rot.vy = -func_80039A74(p->unk2 * 0x88) / 16;
        rot.vz = 0x200;
        func_8003C4AC(&rot, &m);
        func_8003C8DC(p->unk14, &m);
        m.t[0] = m.t[1] = m.t[2] = 0;
        func_8003B48C(&m);
        func_8003B51C(&m);
        func_8003BADC(&pos, (MgSVec *)&q->unkC, &flag);
        p->unk2++;
        if (p->unk2 == 0x20) {
            p->unk0 = -1;
        }
    }
}

void func_801B08A0(void) {
    u8 pad0[8];
    MgSVec v;
    u8 pad1[0x20];
    MgTask *p;
    MgTask *q;
    u16 t;
    s16 a;
    s32 r;
    s32 k;
    s32 u;
    s32 k2;
    s32 u2;
    s32 k3;
    s32 u3;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &D_80162978[func_800BBEAC(&func_801B06FC)];
            q->unk14 = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            v.vx = p->unkC - q->unk4;
            v.vz = p->unk10 - q->unk8;
            q->unk18 = func_80039F5C(v.vx * v.vx + v.vz * v.vz) / 24;
        }
        if (p->unk2 == 0x20) {
            func_800BBA84(0x10B, p->unk1C, 0);
        }
        if (p->unk2 == 0x30) {
            q = &D_80162978[func_800BBEAC(&func_801B02B4)];
            q->unk4 = p->unkC;
            q->unk6 = p->unkE;
            q->unk8 = p->unk10;
        }
        t = p->unk2;
        if ((u32)(t - 0x29) < 7) {
            a = (s16)t * 0x200 - 0x5400;
            q = &D_80162978[func_800BBEAC(&func_801B008C)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            q->unk4 += func_80039B40(a) * 0x320 >> 12;
            r = func_80039A74(a);
            q->unk1A = 1;
            q->unk6 += r * 0x320 >> 12;
            q = &D_80162978[func_800BBEAC(&func_801B008C)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            u = func_80042DA8();
            k = (u16)q->unk4 - 0x12C;
            q->unk4 = k + u % 600;
            u2 = func_80042DA8();
            k2 = (u16)q->unk6 - 0x12C;
            q->unk6 = k2 + u2 % 600;
            u3 = func_80042DA8();
            q->unk1A = 0;
            k3 = (u16)q->unk8 - 0x12C;
            q->unk8 = k3 + u3 % 600;
        }
        if (p->unk2 == 0x5A) {
            func_800D5774(p->unk1C);
        }
        p->unk2++;
        if (p->unk2 == 0x64) {
            p->unk0 = -1;
        }
    }
}

void func_801B0C80(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B08A0)];
    func_800D3994(arg1, D_8015190F[arg1][9], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    func_800BBA84(0x11F, arg1, 0);
}

void func_801B0D58(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B0DC4, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0C80);
}
