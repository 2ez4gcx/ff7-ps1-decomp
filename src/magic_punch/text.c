#include "common.h"
#include "magic_punch/decls.h"

void func_801B0010(void) {
    D_801C9794 = 6;
    D_801B176C = 1;
    func_801B0880();
}

void func_801B0048(void) {
    D_801C9794 = 6;
    func_801B0880();
}

void func_801B0074(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C9790 = D_801B1790 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B00E0(void) {
    MgTask *p;
    PunchU16 *g;
    s16 t;
    s16 r;
    s32 k;
    s32 m;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(D_801B176E * 0x10, 0, 0);
    if (D_80062D98 == 0) {
        t = p->unk2;
        k = 4 - t;
        r = t % 2;
        m = (1 - r * 2) * 20;
        g = &D_801031EA;
        g->v += k * m;
        D_801B176E -= 2;
        if (++p->unk2 == 4) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_RODATA("../asm/us/magic_punch/nonmatchings/text", D_801B0000);

void func_801B01D8(void) {
    MgMat a;
    MgMat b;
    MgMat lw;
    u8 pad[8];
    MgVec scale;
    MgTask *p;
    s32 *frame;
    s32 *q;
    s32 c;

    scale = D_801B0000;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D44E8((MgSVec *)&p->unkC, &a);
    func_8003C21C(&D_801B1770, &b);
    func_8003A79C(&a, &b, &b);
    func_8003B35C(&b, &scale);
    b.t[0] = p->unk4;
    b.t[1] = p->unk6;
    b.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &b, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    frame = &D_801B177C;
    *frame = 0x80;
    c = 0x80;
    if (p->unk2 != 0) {
        c = 0x88;
    }
    *frame = c;
    q = (s32 *)((u8 *)frame - 4);
    D_801B1782.v = p->unk2 * 0x300;
    M2C_SFIELD(q, s32 *, 0) = D_801B1788[p->unk16];
    D_801C9790 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801C9790);
    if (D_80062D98 == 0) {
        if (++p->unk2 == 4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0388(void) {
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B01D8)];
        q->unk4 = p->unk4;
        q->unk6 = p->unk6;
        q->unk8 = p->unk8;
        q->unkC = p->unkC;
        q->unkE = p->unkE;
        q->unk10 = p->unk10;
        q->unk16 = p->unk16;
        p->unk2++;
        if (p->unk2 == D_801C9794) {
            p->unk0 = -1;
        }
    }
}

void func_801B0490() {
    MgTask *p;
    MgTask *q;
    u8 pad[0x28];

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0388)];
            func_800D3994(p->unk1E, D_80151915[p->unk1E][0], &q->unk4);
            q->unkC = (p->unkC - q->unk4) / D_801C9794;
            q->unkE = (p->unkE - q->unk6) / D_801C9794;
            q->unk10 = (p->unk10 - q->unk8) / D_801C9794;
            q->unk16 = 0;
            func_800D4D6C(&q->unk4, 0x27, 0);
            if (D_801B176C == 1) {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0388)];
                func_800D3994(p->unk1E, D_80151916[p->unk1E][0], &q->unk4);
                q->unkC = (p->unkC - q->unk4) / D_801C9794;
                q->unkE = (p->unkE - q->unk6) / D_801C9794;
                q->unk10 = (p->unk10 - q->unk8) / D_801C9794;
                q->unk16 = 1;
                func_800D4D6C(&q->unk4, 0x27, 0);
            }
        }
        if (p->unk2 == D_801C9794) {
            func_800BBEAC(func_801B00E0);
            func_800D4CBC(p->unk1C, 0x3A, 0x1000);
            func_800D5774(p->unk1C);
            func_800BBA84(0x14, p->unk1C, 0);
        }
        if (++p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B07EC(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0490)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1E = arg1;
    p->unk1C = arg0;
}

s32 func_801B0880(arg0, arg1) {
    func_800BBEAC(func_801B0074);
    func_800D5444(arg0, arg1, 4, func_801B07EC);
    return func_800BBA84(0x163, arg1, 0);
}
