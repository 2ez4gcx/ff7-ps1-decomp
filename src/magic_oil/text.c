#include "common.h"
#include "magic_oil/decls.h"

void func_801B0000(void) {
    func_801B0AC4();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EC778 = D_801D4778 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;
    MgMat *m;
    u16 *frame;
    s32 **q;
    s8 c;
    s32 z;

    p = &D_801621F0[D_801590D4];
    m = func_800D4368(&p->unk4, p->unk1A == 0 ? 0x1800 : 0x2000, 0);
    frame = &D_801D4710;
    *frame = p->unk2;
    c = 0x60;
    if (p->unk1A == 4) {
        c = 0x40;
    }
    D_801D470C.b = c;
    D_801D470C.g = c;
    D_801D470C.r = c;
    q = (s32 **)(frame - 4);
    *q = D_801D4714[p->unk1A];
    z = m->t[2];
    if (z > 0) {
        func_800D4484(*(s32 *)(((z >> 4) * 4) + D_801517C0 + 0x70), 0x20, m);
        D_80163C74 = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_80163C74);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D4714[p->unk1A][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B01FC(void) {
    MgMat b;
    MgMat a;
    MgMat lw;
    MgTask *p;
    s32 *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D44E8((MgSVec *)&p->unkC, &a);
    func_8003BF8C(&D_801D473C, &b);
    func_8003A79C(&a, &b, &b);
    q = &D_801D4730;
    *q = p->unk18 * D_801D4744 / 4;
    func_8003B35C(&b, (MgVec *)(q - 1));
    b.t[0] = p->unk4;
    b.t[1] = p->unk6;
    b.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &b, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801EC778 = func_800D29D4(D_801D471C, D_801517C0 + 0x70, 0xC, D_801EC778);
    if (D_80062D98 == 0) {
        if (p->unk2 < 4) {
            D_801D4744 += 1;
        } else {
            q[-1] -= 0x800;
            D_801D4734 -= 0x800;
        }
        if (++p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B03B4(void) {
    MgMat lw;
    MgVec s;
    u8 pad[8];
    MgSVec r;
    MgMat m;
    MgTask *p;
    s32 t;
    s32 *q;

    r.vx = 0x400;
    r.vz = 0;
    r.vy = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&r, &m);
    s.vz = 0x2800;
    s.vy = 0x2800;
    s.vx = 0x2800;
    func_8003B35C(&m, &s);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    t = p->unk2;
    q = &D_801D4748;
    *q = D_801D4758[(s16)(t % 8)];
    D_801D4752 = D_801D4746 * 12;
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801EC778 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801EC778);
    if (D_80062D98 == 0) {
        if (p->unk2 < 8) {
            D_801D4746++;
        }
        if (p->unk2 >= 0xD) {
            D_801D4746--;
        }
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B057C(void) {
    u8 pad[8];
    MgSVec d;
    MgMat pad2;
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B01FC)];
            q->unk14 = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            d.vx = q->unkC = p->unkC - p->unk4;
            d.vy = q->unkE = p->unkE - p->unk6;
            d.vz = q->unk10 = p->unk10 - p->unk8;
            n = func_80039F5C(d.vx * d.vx + d.vy * d.vy + d.vz * d.vz);
            q->unk18 = ((s16)n << 12) / 2800;
        }
        if (p->unk2 == 0xF) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B03B4)];
            q->unk4 = p->unkC;
            q->unk6 = 0;
            q->unk8 = p->unk10;
            func_800BBA84(0xA, p->unk1C, 0);
        }
        if (p->unk2 == 0x28) {
            func_800D5774(p->unk1C);
        }
        if ((u32)((u16)p->unk2 - 5) < 4) {
            i = 0;
            do {
                q = &D_801621F0[func_800BC04C(&func_801B008C)];
                func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
                q->unk4 += func_80042DA8() % 1200 - 600;
                q->unk6 += func_80042DA8() % 1200 - 600;
                i++;
                q->unk8 += func_80042DA8() % 1200 - 600;
                q->unk1A = 0;
            } while (i < 2);
            q = &D_801621F0[func_800BC04C(&func_801B008C)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            q->unk4 += func_80042DA8() % 600 - 300;
            q->unk6 += func_80042DA8() % 600 - 300;
            q->unk8 += func_80042DA8() % 600 - 300;
            q->unk1A = 1;
        }
        p->unk2++;
        if (p->unk2 == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B0A04(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B057C)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B0AC4(arg0, arg1) {
    func_800BBEAC(func_801B0020);
    func_800D2980(&D_801B0B40, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B0A04);
    func_800BBA84(0xD5, arg1, 0);
}
