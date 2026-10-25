#include "common.h"
#include "magic_onpa/decls.h"

void func_801B0000(void) {
    func_801B059C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C0B1C = D_801B0B1C + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0080(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801B0B00[0] = p->unk2;
    D_801C0B1C = (u8 *)func_800D4D90(&D_801B0B00[-4], D_801517C0 + 0x70, 0xC, (s32)D_801C0B1C);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        if (++p->unk2 == D_801B0898) {
            p->unk0 = -1;
        }
    }
}

void func_801B0158(void) {
    MgMat m;
    MgMat m2;
    MgMat m3;
    MgVec scale;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D44E8((MgSVec *)&p->unkC, &m3);
    func_8003C21C(&D_801B0B14, &m);
    func_8003A79C(&m3, &m, &m);
    scale.vx = scale.vy = scale.vz = p->unk14;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    func_8003B69C(0, 0, 0);
    D_801C0B1C = (u8 *)func_800D29D4(D_801B0B04, D_801517C0 + 0x70, 0xC, (s32)D_801C0B1C);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk14 += 0x190;
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B02D0(void) {
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 0xA) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0158)];
            q->unk4 = (u16)p->unk4;
            q->unk6 = (u16)p->unk6;
            q->unk8 = (u16)p->unk8;
            q->unkC = (p->unkC - p->unk4) / 20;
            q->unkE = (p->unkE - p->unk6) / 20;
            q->unk10 = (p->unk10 - p->unk8) / 20;
            q->unk14 = 0x800;
        }
        if ((u32)((u16)p->unk2 - 0x10) < 9U) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0080)];
            q->unkC = (u32)(func_80039B40((p->unk2 << 9) - 0x2400) * 15) >> 10;
            q->unkE = (u32)(func_80039A74((p->unk2 << 9) - 0x2400) * 15) >> 10;
            q->unk4 = (u16)p->unkC + q->unkC * 10;
            q->unk6 = (u16)p->unkE + q->unkE * 10;
            q->unk8 = (u16)p->unk10;
        }
        if (++p->unk2 == 0x18) {
            func_800D5774(p->unk18);
            p->unk0 = -1;
        }
    }
}

void func_801B04DC(s32 arg0, s32 arg1) {
    MgTask *p;
    u8 pad[8];

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B02D0)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk18 = arg0;
}

s32 func_801B059C(arg0, arg1) {
    func_800BBEAC(func_801B0020);
    func_800D5444(arg0, arg1, 4, func_801B04DC);
    return func_800BBA84(0x118, arg1, 0x40);
}
