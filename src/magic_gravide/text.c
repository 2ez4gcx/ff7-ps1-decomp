#include "common.h"
#include "magic_gravide/decls.h"

void func_801B0000(void) {
    MgTask *p;
    MgMat *m;
    s32 z;
    s16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    frame = &D_801D0A48;
    *frame = p->unk2;
    m = func_800D4368(&p->unk4, 0x800, 0);
    z = m->t[2];
    if (z > 0) {
        func_800D4484(*(s32 *)(((z >> 4) * 4) + D_801517C0 + 0x70), 0x20);
        D_801EEA64 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EEA64);
    }
    if (D_80062D98 == 0) {
        p->unk2 += 3;
        if (p->unk2 >= 5) {
            p->unk0 = -1;
        }
    }
}

void func_801B00F0(void) {
    MgTask *p;
    MgMat *m;
    s32 z;
    s16 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    a = p->unk14;
    m = func_800D4368(&p->unk4, a, -(a >> 4));
    z = m->t[2];
    if (z > 0) {
        func_800D4484(*(s32 *)(((z >> 4) * 4) + D_801517C0 + 0x70), 0x20);
        D_801EEA64 = (u8 *)func_800D4D90(&D_801D0A4C, D_801517C0 + 0x70, 0xC, (s32)D_801EEA64);
    }
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        p->unk16 -= 0x28;
        p->unk2++;
        if (p->unk2 >= 0x24) {
            p->unk0 = -1;
        }
    }
}

void func_801B01F4(void) {
    MgTask *p;
    s16 *frame;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    t = t % 12;
    frame = &D_801D0A60;
    *frame = t;
    ((void (*)(void *, s32, s32, s32))func_800D4368)(&p->unk4, 0x1000, -0xC8, t);
    D_801EEA64 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EEA64);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x24) {
            p->unk0 = -1;
        }
    }
}

void func_801B02E8(void) {
    MgObjGrav *p;
    MgObjGrav *q;

    p = (MgObjGrav *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = (MgObjGrav *)&D_80162978[func_800BBEAC(&func_801B0000)];
        q->pos = p->pos;
        q->unk2 = 2;
        p->pos.vx += p->vel.vx;
        p->pos.vy += p->vel.vy;
        p->pos.vz += p->vel.vz;
        q = (MgObjGrav *)&D_80162978[func_800BBEAC(&func_801B0000)];
        q->pos = p->pos;
        q->unk2 = 1;
        p->pos.vx += p->vel.vx;
        p->pos.vy += p->vel.vy;
        p->pos.vz += p->vel.vz;
        q = (MgObjGrav *)&D_80162978[func_800BBEAC(&func_801B0000)];
        q->pos = p->pos;
        p->pos.vx += p->vel.vx;
        p->pos.vy += p->vel.vy;
        p->pos.vz += p->vel.vz;
        p->unk2++;
        if (p->unk2 >= 8) {
            q = (MgObjGrav *)&D_80162978[func_800BBEAC(&func_801B01F4)];
            q->pos = p->pos;
            q = (MgObjGrav *)&D_80162978[func_800BBEAC(&func_801B00F0)];
            q->pos = p->pos;
            q->unk14 = 0x200;
            q->unk16 = 0x2D0;
            func_800D5774(p->unk18);
            func_800D55F4(0x20, func_800D56A8(D_80151A4C[p->unk18]), 0x1E);
            p->unk0 = -1;
        }
    }
}

void func_801B0568(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B02E8)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk18 = arg0;
    p->unkC = (p->unkC - p->unk4) / 24;
    p->unkE = (p->unkE - p->unk6) / 24;
    p->unk10 = (p->unk10 - p->unk8) / 24;
    func_800D55F4(0x20, func_800D56A8(D_80151A4C[arg1]), 0x50);
}

void func_801B06C4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EEA64 = D_801D0A64 + p->unk2 * 0xF000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0730(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B07A0, 0, 0, 0);
    func_800BBEAC(&func_801B06C4);
    func_800D5444(arg0, arg1, 8, &func_801B0568);
}
