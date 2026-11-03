#include "common.h"
#include "magic_hvshot/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B103C();
    return &D_801B10AC;
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
        v = t * 0xE00 / 22 + 0x200;
        scale.vx = scale.vy = scale.vz = v;
        if (D_80062D98 == 0) {
            a = &D_801B52E8;
            b = &D_801B52F0;
            *a += 0x280;
            *b -= 0x1C0;
        }
        func_8003C21C(D_801B52E4, &D_801B52B4);
        func_8003B35C(&D_801B52B4, &scale);
        func_8003A63C(&D_800FA6E0[p->unk6], &D_801B52B4, &m2);
        func_8003B48C(&m2);
        func_8003B51C(&m2);
        r = &D_801B52D8;
        q = r - 1;
        *r = 0;
        D_801D59F8 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801D59F8);
        func_8003C21C(D_801B52EC, &D_801B52B4);
        func_8003B35C(&D_801B52B4, &scale);
        func_8003A63C(&D_800FA6E0[p->unk6], &D_801B52B4, &m2);
        func_8003B35C(&m2, D_801B52F8);
        func_8003B48C(&m2);
        *r = 8;
        D_801D59F8 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801D59F8);
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

INCLUDE_ASM("../asm/us/magic_hvshot/nonmatchings/text", func_801B0258);

void func_801B03C0(void) {
    MgMat m;
    MgVec scale;
    s32 flag;
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xE) {
        s32 k;
        u8 *e;

        k = p->unk0;
        k = k * 0x10;
        e = D_801B5338;
        e = e + k;
        e[0xA] = 0x80;
        e[9] = 0x80;
        D_801B5340[k] = 0x80;
        D_801B5340[3 + p->unk0 * 0x10] = 0x2C;
        goto draw;
    }
    t -= 0xE;
    if (t >= 8) {
        goto kill;
    }
    {
        s32 k;
        u8 *e;
        s32 c;

        k = p->unk0 * 0x10;
        e = D_801B5338 + k;
        t <<= 7;
        t = -t;
        if (t < 0) {
            t += 7;
        }
        c = (t >> 3) - 0x80;
        e[0xA] = c;
        e[9] = c;
        D_801B5340[k] = c;
        D_801B5340[3 + p->unk0 * 0x10] = 0x2E;
    }
draw:
    func_8003C21C(&D_801B53B8[D_8015169C], &m);
    scale.vx = scale.vy = scale.vz = p->unk18;
    func_8003B35C(&m, &scale);
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(&p->unk8, m.t, &flag);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801D59F8 = func_800D6260(D_801B5338 + p->unk0 * 0x10, D_801517C0 + 0x70, 0xC, D_801D59F8);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk8 += p->unk10;
        p->unkA += p->unk12;
        p->unkC += p->unk14;
        p->unk12 += 0xA;
        D_801B53B8[D_8015169C].x += D_801B53B8[D_8015169C].vx;
        D_801B53B8[D_8015169C].y += D_801B53B8[D_8015169C].vy;
        D_801B53B8[D_8015169C].z += D_801B53B8[D_8015169C].vz;
        if (p->unkA > 0) {
kill:
            p->unk0 = -1;
        }
    }
}

void func_801B0680(void) {
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xE) {
        s32 k;
        u8 *e;

        k = p->unk0;
        k = k * 0x10;
        e = D_801B5368;
        e = e + k;
        e[0xA] = 0x80;
        e[9] = 0x80;
        D_801B5370[k] = 0x80;
        goto draw;
    }
    t -= 0xE;
    if (t >= 8) {
        goto kill;
    }
    {
        s32 k;
        u8 *e;
        s32 c;

        k = p->unk0 * 0x10;
        e = D_801B5368 + k;
        t <<= 7;
        t = -t;
        if (t < 0) {
            t += 7;
        }
        c = (t >> 3) - 0x80;
        e[0xA] = c;
        e[9] = c;
        D_801B5370[k] = c;
    }
draw:
    func_800D4368(&p->unk8, p->unk18, 0);
    D_801D59F8 = func_800D6260(D_801B5368 + p->unk0 * 0x10, D_801517C0 + 0x70, 0xC, D_801D59F8);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk8 += p->unk10;
        p->unkA += p->unk12;
        p->unkC += p->unk14;
        if (p->unkA > 0) {
kill:
            p->unk0 = -1;
        }
    }
}

void func_801B07F8(void) {
    MgSVec rot;
    MgSVec a;
    MgMat m;
    MgMat m2;
    MgVec v;
    s32 flag;
    MgTask *p;
    MgTask *q;
    MgMat *mp;
    MgMat *mp2;
    s32 t;
    s32 i;
    s32 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t >= 0) {
            if (t < 0x16) {
                if (t == 0) {
                    q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0028)];
                    q->unk4 = p->unk4;
                    q->unk6 = p->unk6;
                    func_800D55F4(0x20, func_800D56A8(D_80151A4C[p->unk6]), 0x28);
                }
                if (t < 0xE) {
                    func_800D41FC(&D_800FA63C, &D_800FA6E0[p->unk6], &m2);
                    i = 0;
                    while (1) {
                        q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0258)];
                        a.vy = 0;
                        a.vx = 0;
                        a.vz = -(func_80042DA8() % 1000 + 0x3E8);
                        rot.vx = (func_80042DA8() & 0x3FF) - 0x200;
                        rot.vy = (func_80042DA8() & 0x3FF) - 0x200;
                        rot.vz = 0;
                        func_8003C21C(&rot, &m);
                        m.t[2] = -0xB4;
                        m.t[1] = -0xB4;
                        m.t[0] = -0xB4;
                        func_8003A63C(&m2, &m, &m);
                        func_8003B48C(&m);
                        func_8003B51C(&m);
                        func_8003BC6C(&a, &v, &flag);
                        q->unk8 = v.vx;
                        q->unkA = v.vy;
                        q->unkC = v.vz;
                        q->unk10 = (m.t[0] - v.vx) / 8;
                        q->unk12 = (m.t[1] - v.vy) / 8;
                        q->unk14 = (m.t[2] - v.vz) / 8;
                        i++;
                        q->unk0 = func_80042DA8() % 3;
                        q->unk18 = 0x1000;
                        if (i >= 2) {
                            break;
                        }
                    }
                }
            } else {
                t -= 0x16;
                if (t < 7) {
                    if (t == 0) {
                        func_800D51D4(2);
                        func_800D5774(p->unk4);
                        i = 0;
                        mp = &m;
                        do {
                            i++;
                            n = func_800BBEAC((void *)func_801B03C0);
                            q = (MgTask *)&D_80162978[n];
                            func_800D3994(p->unk4, D_8015190F[p->unk4][0], &q->unk8);
                            a.vy = 0;
                            a.vx = 0;
                            a.vz = -0x64 - func_80042DA8() % 200;
                            rot.vx = (func_80042DA8() & 0x7FF) - 0x400;
                            rot.vy = D_80151A46[p->unk6][0] + (func_80042DA8() & 0x7FF) + 0x400;
                            rot.vz = 0;
                            func_8003C21C(&rot, mp);
                            func_8003B2CC(mp, &a, (MgSVec *)&q->unk10);
                            n <<= 4;
                            q->unk18 = func_80042DA8() % 6144 + 0x800;
                            q->unk0 = func_80042DA8() % 3;
                            D_801B53B8[n >> 4].x = func_80042DA8() & 0xFFF;
                            D_801B53B8[n >> 4].y = func_80042DA8() & 0xFFF;
                            D_801B53B8[n >> 4].z = func_80042DA8() & 0xFFF;
                            D_801B53B8[n >> 4].vx = func_80042DA8() % 150 + 0x32;
                            D_801B53B8[n >> 4].vy = func_80042DA8() % 150 + 0x32;
                            D_801B53B8[n >> 4].vz = func_80042DA8() % 150 + 0x32;
                        } while (i < 0x32);
                        i = 0;
                        mp2 = mp;
                        while (1) {
                            i++;
                            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0680)];
                            func_800D3994(p->unk4, D_8015190F[p->unk4][0], &q->unk8);
                            a.vy = 0;
                            a.vx = 0;
                            a.vz = -0x1F4 - func_80042DA8() % 300;
                            rot.vx = (func_80042DA8() & 0x7FF) - 0x400;
                            rot.vy = D_80151A46[p->unk6][0] + (func_80042DA8() & 0x7FF) + 0x400;
                            rot.vz = 0;
                            func_8003C21C(&rot, mp2);
                            func_8003B2CC(mp2, &a, (MgSVec *)&q->unk10);
                            q->unk18 = func_80042DA8() % 6144 + 0x800;
                            q->unk0 = func_80042DA8() % 3;
                            if (i >= 0x1E) {
                                break;
                            }
                        }
                    }
                } else if ((t -= 7) >= 0xF) {
                    p->unk0 = -1;
                }
            }
        }
        p->unk2++;
    }
}

void func_801B0F88(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B07F8)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B0FDC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D59F8 = D_801B59F8 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B103C(arg0, arg1) {
    func_800D2980(&D_801B1A18, 0, 0, 0);
    func_800BBEAC(&func_801B0FDC);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B0F88);
}
