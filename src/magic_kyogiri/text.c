#include "common.h"
#include "magic_kyogiri/decls.h"

void func_801B0000(void) {
    KyoPrim pr;
    MgVec vec;
    MgMat m;
    MgSVec rot;
    MgTask *p;
    s32 c;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    pr.tag = *(s32 *)&p->unk10;
    pr.f = 0;
    c = -(p->unk2 << 7) / 8 - 0x80;
    pr.r = pr.g = pr.b = c;
    pr.code = 0x2E;
    v = p->unk0 * 0x6FFF / 8 + 0x1000;
    vec.vx = vec.vy = vec.vz = v;
    rot.vx = rot.vy = 0;
    rot.vz = p->unk0 * 0x100;
    func_8003C21C(&rot, &m);
    func_8003B35C(&m, &vec);
    func_800D4284(&p->unk8, p->unk14, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801D3620 = func_800D4D90(&pr, D_801517C0 + 0x70, 0xC, D_801D3620);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B0168(void) {
    KyoPrim pr;
    MgVec vec;
    MgMat m;
    MgSVec rot;
    MgTask *p;
    MgTask *q;
    s32 c;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    pr.tag = *(s32 *)&p->unk10;
    pr.f = 0;
    if (p->unk2 < 4) {
        c = p->unk2 << 5;
        pr.r = pr.g = pr.b = c;
        pr.code = 0x2E;
        func_800D4368(&p->unk8, -(p->unk2 * 3 << 12) / 4 + 0x4000, p->unk14);
        D_801D3620 = func_800D4D90(&pr, D_801517C0 + 0x70, 0xC, D_801D3620);
    } else {
        v = p->unk2 + p->unk0;
        if (v < 0x25) {
            pr.r = pr.g = pr.b = 0x80;
            pr.code = 0x2E;
            func_800D4368(&p->unk8, 0x1000, p->unk14);
            D_801D3620 = func_800D4D90(&pr, D_801517C0 + 0x70, 0xC, D_801D3620);
        } else {
            v -= 0x25;
            if (v < 8) {
                if (D_80062D98 == 0) {
                    q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0000)];
                    q->unk2 = v * 3 / 4;
                    *(KyoCopy *)&q->unk8 = *(KyoCopy *)&p->unk8;
                    *(s32 *)&q->unk10 = *(s32 *)&p->unk10;
                    q->unk0 = v;
                    q->unk14 = p->unk14;
                }
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0348(void) {
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 5) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0168)];
            *(u8 **)&q->unk10 = D_801B350C;
            q->unk0 = p->unk2;
            *(KyoCopy *)&q->unk8 = *(KyoCopy *)&p->unk8;
            q->unk14 = p->unk14;
        }
        if (p->unk2 == 9) {
            func_800D55F4(0x20, func_800D56A8(&p->unk8), 0x12);
        }
        if (p->unk2 == 0xF) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0168)];
            *(u8 **)&q->unk10 = D_801B352C;
            q->unk0 = p->unk2;
            *(KyoCopy *)&q->unk8 = *(KyoCopy *)&p->unk8;
            q->unk14 = p->unk14;
        }
        if (p->unk2 == 0x13) {
            func_800D55F4(0x20, func_800D56A8(&p->unk8), 0x12);
        }
        if (p->unk2 == 0x1A) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0168)];
            *(u8 **)&q->unk10 = D_801B3588;
            q->unk0 = p->unk2;
            *(KyoCopy *)&q->unk8 = *(KyoCopy *)&p->unk8;
            q->unk14 = p->unk14;
        }
        if (p->unk2 == 0x1E) {
            func_800D55F4(0x20, func_800D56A8(&p->unk8), 0x1B);
        }
        if (p->unk2 == 0x25) {
            func_800D5774(p->unk4);
            func_800D55F4(0x20, func_800D56A8(&p->unk8), 0x21);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B059C(s32 arg0) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0348)];
    p->unk4 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk8);
    p->unk14 = -*(u16 *)D_801518F6[arg0];
}

void func_801B063C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D3620 = D_801B3620 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

M2C_UNK *func_801B069C(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B14CC, 0, 0, 0);
    func_800BBEAC(&func_801B063C);
    func_800D5444(arg0, arg1, 0, &func_801B059C);
    return &D_801B0714;
}
