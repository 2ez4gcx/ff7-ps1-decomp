#include "common.h"
#include "magic_m_break/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0A54();
    return &D_801B0AC4;
}

void func_801B0028(void) {
    MgVec scale;
    MgMat m2;
    MgTask *p;
    s32 *q;
    s32 *r;
    u16 *a;
    u16 *b;
    s32 t;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x16) {
        u8 pad[0x18];
        v = t * 0x1C0 / 22 + 0x40;
        scale.vx = scale.vy = scale.vz = v;
        if (D_80062D98 == 0) {
            a = &D_801B5948;
            b = &D_801B5950;
            *a += 0x280;
            *b -= 0x1C0;
        }
        func_8003C21C(D_801B5944, &D_801B5914);
        func_8003B35C(&D_801B5914, &scale);
        func_8003A63C(&D_800FA6E0[p->unk6], &D_801B5914, &m2);
        func_8003B48C(&m2);
        func_8003B51C(&m2);
        r = &D_801B5938;
        q = r - 1;
        *r = 0;
        D_801D5FE0 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801D5FE0);
        func_8003C21C(D_801B594C, &D_801B5914);
        func_8003B35C(&D_801B5914, &scale);
        func_8003A63C(&D_800FA6E0[p->unk6], &D_801B5914, &m2);
        func_8003B35C(&m2, D_801B5958);
        func_8003B48C(&m2);
        *r = 8;
        D_801D5FE0 = func_800D29D4(q, D_801517C0 + 0x60, 0xC, D_801D5FE0);
        if (t == 0x15) {
            func_800D5138(1);
            goto kill;
        }
    } else {
kill:
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0258(void) {
    MgTask *p;
    u16 *fr;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 4) {
        c = t << 5;
    } else {
        t -= 4;
        if (t >= 4) {
            goto kill;
        }
        c = 0x80;
    }
    D_801B596C = D_801B596D = D_801B596E = c;
    goto draw;
kill:
    p->unk0 = -1;
    return;
draw:
    func_800D4368(&p->unk8, p->unk18, 0);
    fr = &D_801B5970;
    *fr = p->unk0;
    D_801D5FE0 = func_800D4D90((u8 *)fr - 8, D_801517C0 + 0x70, 0xC, D_801D5FE0);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk8 += p->unk10;
        p->unkA += p->unk12;
        p->unkC += p->unk14;
    }
}

void func_801B0370(void) {
    MgTask *p;
    u16 *fr;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        c = 0x80;
    } else {
        t -= 5;
        if (t >= 10) {
            goto kill;
        }
        c = -(t << 7) / 10 - 0x80;
    }
    do {
        D_801B5978[0] = D_801B5978[1] = D_801B5978[2] = c;
    } while (0);
    func_800D4368(&p->unk8, p->unk18, 0);
    fr = &D_801B597C;
    *fr = p->unk0;
    D_801D5FE0 = func_800D4D90((u8 *)fr - 8, D_801517C0 + 0x70, 0xC, D_801D5FE0);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk8 += p->unk10;
        p->unkA += p->unk12;
        p->unkC += p->unk14;
        p->unk10 = p->unk10 * 15 >> 4;
        p->unk12 = p->unk12 * 15 >> 4;
        p->unk14 = p->unk14 * 15 >> 4;
        if (p->unkA > 0) {
kill:
            p->unk0 = -1;
        }
    }
}

void func_801B04E8(void) {
    MgSVec a;
    MgSVec b;
    MgMat m;
    MgMat cam;
    MgVec out;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 i;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t >= 0) {
            if (t < 0x16) {
                if (t == 0) {
                    q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0028)];
                    q->unk4 = p->unk4;
                    q->unk6 = p->unk6;
                    func_800D55F4(0x20, func_800D56A8(D_80151A4C[p->unk6]), 0x28);
                }
                if (t < 0xE) {
                    func_800D41FC(&D_800FA63C, &D_800FA6E0[p->unk6], &cam);
                    i = 0;
                    do {
                        q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0258)];
                        b.vy = 0;
                        b.vx = 0;
                        b.vz = -(func_80042DA8() % 1000 + 0x3E8);
                        a.vx = (func_80042DA8() & 0x3FF) - 0x200;
                        a.vy = (func_80042DA8() & 0x3FF) - 0x200;
                        a.vz = 0;
                        func_8003C21C(&a, &m);
                        m.t[0] = m.t[1] = m.t[2] = -0xB4;
                        func_8003A63C(&cam, &m, &m);
                        func_8003B48C(&m);
                        func_8003B51C(&m);
                        func_8003BC6C(&b, &out, &flag);
                        q->unk8 = (u16)out.vx;
                        q->unkA = (u16)out.vy;
                        q->unkC = (u16)out.vz;
                        q->unk10 = (m.t[0] - out.vx) / 8;
                        q->unk12 = (m.t[1] - out.vy) / 8;
                        q->unk14 = (m.t[2] - out.vz) / 8;
                        i++;
                        q->unk0 = func_80042DA8() % 3;
                        q->unk18 = 0x1000;
                    } while (i < 2);
                }
            } else {
                t -= 0x16;
                if (t < 7) {
                    if (t == 0) {
                        func_800D51D4(2);
                        func_800D5774(p->unk4);
                    }
                    if (t < 3) {
                        i = 0;
                        do {
                            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0370)];
                            func_800D3994(p->unk4, D_8015190F[p->unk4][0], &q->unk8);
                            b.vy = 0;
                            b.vx = 0;
                            b.vz = -0x12C - func_80042DA8() % 500;
                            a.vx = (func_80042DA8() & 0x3FF) - 0x200;
                            a.vy = D_80151A46[p->unk6][0] + (func_80042DA8() & 0x3FF) - 0x200;
                            a.vz = 0;
                            func_8003C21C(&a, &m);
                            func_8003B2CC(&m, &b, &q->unk10);
                            r = func_80042DA8();
                            q->unk18 = r % 0x800 + 0x800;
                            q->unk0 = func_80042DA8() % 3;
                            i++;
                        } while (i < 0x14);
                    }
                } else if ((t -= 7) >= 0xF) {
                    p->unk0 = -1;
                }
            }
        }
        p->unk2++;
    }
}

void func_801B09A0(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B04E8)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B09F4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D5FE0 = D_801B5FE0 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0A54(arg0, arg1) {
    func_800D2980(&D_801B1430, 0, 0, 0);
    func_800BBEAC(&func_801B09F4);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B09A0);
}
