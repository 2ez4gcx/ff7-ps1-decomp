#include "common.h"
#include "magic_fubuki/decls.h"

void func_801B0020(void) {
    func_801B0F20();
}

void func_801B0040(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EA7CC = D_801D27CC + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B00AC(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x1000, 0);
    D_801D1AFC[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D1AFC[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D1970) {
            p->unk0 = -1;
        }
    }
}

void func_801B0168(void) {
    MgVec v;
    MgMat m;
    MgTask *p;
    MgByte *col;
    s32 c;

    m = D_801B0000;
    v.vx = v.vy = v.vz = 0xC00;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = (s16)D_801D1B0C * 0x10;
    col = &D_801D1B04;
    col->v = D_801D1B05.v = D_801D1B06.v = c;
    D_80163C74 = func_800D4D90((u8 *)col - 4, D_801517C0 + 0x4070, 1, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += 4;
        p->unk6 += 4;
        if (p->unk2 < 8) {
            D_801D1B0C++;
        }
        if (p->unk2 >= 0x26) {
            D_801D1B0C--;
        }
        if (++p->unk2 == 0x2D) {
            p->unk0 = -1;
        }
    }
}

void func_801B032C(s32 arg0) {
    s16 i;
    s32 c;
    s32 code;
    s32 head;
    s32 layer;
    FbDot *q;
    FbTag *ot;

    i = 0;
    code = 0x6A;
    head = 0x02000000;
    c = (s16)arg0 * 0x10;
    layer = 0x40;
    do {
        q = (FbDot *)D_80163C74;
        q->code = code;
        *(s32 *)q = head;
        q->x = D_801D1B4E[i].x;
        q->y = D_801D1B50[i].x;
        i++;
        q->r = c;
        q->g = c;
        q->b = c;
        ot = (FbTag *)(layer + D_801517C0);
        q->tag.addr = ot[0x1C].addr;
        ot[0x1C].addr = (u32)q;
        D_80163C74 = (u8 *)(q + 1);
    } while (i < 0x190);
}

void func_801B0400(void) {
    MgObj20 *p;
    s16 i;
    s16 k;

    p = &D_80162978[D_8015169C];
    func_801B032C((s16)D_801D1B0E);
    if (D_80062D98 == 0) {
        for (i = 0; i < 0x190; i++) {
            k = (i % 2) * 2 + 2;
            D_801D1B4E[i].x = ((s16)D_801D1B4E[i].x + k) % 320;
            D_801D1B50[i].x = ((s16)D_801D1B50[i].x + k) % 160;
        }
        if (p->unk2 < 8) {
            D_801D1B0E += 1;
        }
        if (p->unk2 >= 0x2B) {
            D_801D1B0E -= 1;
        }
        if (++p->unk2 == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B05BC(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 *rot;
    s16 *frame;
    s32 t;

    rot = &D_801D1B32;
    p = (MgTask *)&D_80162978[D_8015169C];
    *rot = p->unk2 * 0x80;
    func_8003BF8C((MgSVec *)((u8 *)rot - 2), &m);
    func_8003A79C(&D_801EA7D0, &m, &m);
    D_801D1B14[0] = p->unk18;
    t = 0x5DC0 - p->unk2 * 0x320;
    D_801D1B18 = t;
    D_801D1B14[-1] = t;
    func_8003B35C(&m, (MgVec *)&D_801D1B14[-1]);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C((MgMat *)D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801D1B2A;
    *frame = p->unk2 * 6;
    D_80163C74 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0730(void) {
    MgMat lw;
    MgVec v;
    MgMat m;
    MgTask *p;
    s16 *frame;
    s16 k;

    m = D_801B0000;
    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 >= 0xC) {
        k = 0x14 - p->unk2;
    } else {
        k = 8;
    }
    v.vx = v.vy = v.vz = p->unk2 * 0x1E0;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C((MgMat *)D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    frame = &D_801D1B42;
    *frame = 0x1000 - (k * 0x200);
    D_80163C74 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk6 += 0x28;
        p->unk4 += p->unkC;
        p->unk8 += p->unk10;
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B08FC(void) {
    MgSVec v;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 d;
    s32 u1;
    s32 u2;
    s32 u3;
    s32 k1;
    s32 k2;
    s32 k3;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_800BBEAC(func_801B0400);
            D_801D1B48 = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B05BC)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            v.vx = p->unkC - p->unk4;
            v.vy = p->unkE - p->unk6;
            v.vz = p->unk10 - p->unk8;
            func_800D44E8(&v, &D_801EA7D0);
            d = func_80039F5C(v.vx * v.vx + v.vy * v.vy + v.vz * v.vz);
            q->unk18 = d * 0x1500 / 2800;
        }
        if (p->unk2 == 8) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0168)];
            q->unk4 = -0x64;
            q->unk6 = -0x64;
            q->unk8 = 0x7D0;
            func_800BBA84(0xB0, -1, 0x40);
            D_800F8380 |= 7;
        }
        if ((u16)(p->unk2 - 0xF) < 0xFU && p->unk2 % 5 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0730)];
            q->unkC = (u32)(func_80039A74(D_801D1B48 + 0x800) * 0xF) >> 0xA;
            q->unk10 = (u32)(func_80039B40(D_801D1B48 + 0x800) * 0xF) >> 0xA;
            q->unk4 = p->unkC - q->unkC * 10;
            q->unk6 = p->unkE + 0x190;
            q->unk8 = p->unk10 - q->unk10 * 10;
        }
        if (p->unk2 == 0x2D) {
            func_800D5774(p->unk1C);
            func_800BBA84(0x95, p->unk1C, 0x40);
        }
        if ((u16)(p->unk2 - 0x2A) < 7U) {
            i = 0;
            do {
                q = (MgTask *)&D_801621F0[func_800BC04C(func_801B00AC)];
                func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
                u1 = func_80042DA8();
                k1 = (u16)q->unk4 - 0x1F4;
                q->unk4 = k1 + u1 % 1000;
                u2 = func_80042DA8();
                k2 = (u16)q->unk6 - 0x1F4;
                q->unk6 = k2 + u2 % 1000;
                i++;
                u3 = func_80042DA8();
                k3 = (u16)q->unk8 - 0x1F4;
                q->unk8 = k3 + u3 % 1000;
            } while (i < 2);
        }
        p->unk2++;
        if (p->unk2 == 0x41) {
            D_800F8380 &= 0xF8;
            func_800D52A0(0, 0xA);
            p->unk0 = -1;
        }
    }
}

void func_801B0DAC(s32 arg0, s32 arg1) {
    MgTask *p;
    s16 i;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B08FC)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    for (i = 0; i < 0x190; i++) {
        D_801D1B4E[i].x = func_80042DA8() % 320;
        D_801D1B50[i].x = func_80042DA8() % 160;
    }
}

s32 func_801B0F20(arg0, arg1) {
    func_800BBEAC(func_801B0040);
    func_800D2980(&D_801B1898, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0DAC);
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    return func_800D52A0(0x1000, 5);
}

INCLUDE_RODATA("../asm/us/magic_fubuki/nonmatchings/text", D_801B0000);
