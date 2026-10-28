#include "common.h"
#include "magic_bacume/decls.h"

void func_801B0000(void) {
    func_801B0D5C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CFED0 = D_801B7ED0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(MgTask *p) {
    MgSVec a;
    MgSVec b;
    MgSVec c;
    MgSVec d;
    s32 ext;
    s32 flag;
    u8 *q;
    s32 r;
    s32 t;
    s32 k0;
    s32 k1;
    s32 w;
    s32 k;

    w = 0x3A000000;
    k0 = (p->unk2 + 1) * 0x1E + 0x1E;
    k1 = p->unk2 * 0x1E + 0x1E;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    a.vx = p->unk4;
    a.vy = p->unk6 - k0;
    a.vz = p->unk8;
    b.vx = p->unkC;
    b.vy = p->unkE - k1;
    b.vz = p->unk10;
    c.vx = p->unk4;
    c.vy = k0 + p->unk6;
    c.vz = p->unk8;
    d.vx = p->unkC;
    q = D_801CFED0;
    d.vy = k1 + p->unkE;
    d.vz = p->unk10;
    r = func_8003BD7C(&a, &b, &c, &d, q + 8, q + 0x10, q + 0x18, q + 0x20, &ext, &flag);
    if (r > 0) {
        t = p->unk2;
        *(s32 *)q = 0x08000000;
        w += (8 - t) * 0x101010;
        *(s32 *)(q + 4) = *(s32 *)(q + 0x14) = w - 0x101010;
        *(s32 *)(q + 0xC) = *(s32 *)(q + 0x1C) = w;
        k = 0x70;
        ((void (*)(s32, u8 *, s32))func_80046794)(((r >> 2) << 2) + k + D_801517C0, q, t);
        D_801CFED0 = q + 0x24;
    }
    if (D_80062D98 == 0) {
        if (++p->unk2 == 8) {
            p->unk0 = 0;
        }
    }
}

s32 func_801B0294(void) {
    s32 i;
    s32 off;
    s32 n;

    n = 0;
    for (i = 0; i < 200; i++) {
        off = i * 0x14;
        if (*(s16 *)((u8 *)D_801B6F30 + off) != 0) {
            func_801B008C((MgTask *)((u8 *)D_801B6F30 + off));
            n++;
        }
    }
    return n;
}

MgObj14 *func_801B031C(void) {
    s32 i;

    for (i = 0; i < 200; i++) {
        if (D_801B6F30[i].unk0 == 0) {
            D_801B6F30[i].unk0 = 1;
            return &D_801B6F30[i];
        }
    }
    return NULL;
}

void func_801B0368(void) {
    MgSVec rot;
    MgMat m;
    s32 flag;
    MgTask *p;
    s16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vx = p->unkC;
    rot.vy = p->unkE;
    rot.vz = p->unk10;
    func_8003C21C((MgSVec *)&p->unk14, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003BADC(&rot, &rot, &flag);
    func_800D4368(&rot, 0x2000, 0);
    frame = &D_801B6ECC;
    *frame = p->unk2 % 2;
    D_801CFED0 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801CFED0);
    if (D_80062D98 == 0) {
        p->unkC += -p->unkC / 4;
        p->unkE += -p->unkE / 4;
        p->unk10 -= 0x12C;
        if (++p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B04F8(void) {
    u8 pad[8];
    MgSVec a;
    MgSVec b;
    MgMat m;
    s32 flag;
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        a.vx = p->unkC;
        a.vy = p->unkE;
        a.vz = p->unk10;
        p->unkC += -p->unkC / 4;
        b.vx = p->unkC;
        b.vy = p->unkE += -p->unkE / 4;
        p->unk10 -= 0x12C;
        b.vz = p->unk10;
        func_8003C21C((MgSVec *)&p->unk14, &m);
        m.t[0] = p->unk4;
        m.t[1] = p->unk6;
        m.t[2] = p->unk8;
        func_8003B48C(&m);
        func_8003B51C(&m);
        func_8003BADC(&a, &a, &flag);
        func_8003BADC(&b, &b, &flag);
        q = (MgTask *)func_801B031C();
        if (q != NULL) {
            q->unk4 = a.vx;
            q->unk6 = a.vy;
            q->unk8 = a.vz;
            q->unkC = b.vx;
            q->unkE = b.vy;
            q->unk10 = b.vz;
            q->unk2 = 0;
        }
        if (++p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B06AC(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    MgHalf *frame;
    u16 *g;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C((MgSVec *)&p->unk14, &m);
    func_8003B35C(&m, &D_801B6ED4);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801B6EF2;
    frame->v = p->unk2 % 5 * 0xC0;
    D_801B6EEE = D_801B6ED0 * 0x70 / 6;
    D_801CFED0 = func_800D29D4((u8 *)frame - 0xE, D_801517C0 + 0x70, 0xC, D_801CFED0);
    if (D_80062D98 == 0) {
        if (p->unk2 < 6) {
            D_801B6ED0 += 1;
        }
        if (p->unk2 >= 0x1F) {
            D_801B6ED0 -= 1;
        }
        g = &D_801031EA;
        t = *g - 0x20;
        *g = t + p->unk2 % 2 * 64;
        if (++p->unk2 == 0x24) {
            p->unk0 = -1;
        }
    }
}

void func_801B08C4(void) {
    s32 flag;
    MgTask *p;
    MgTask *q;
    s32 n;
    s32 t;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    n = func_801B0294();
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801B6EF6[0] = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            D_801B6EF8 = 0;
            D_801B6EF6[-1] = 0;
            func_8003C21C((MgSVec *)&D_801B6EF6[-1], &D_801B6F0C);
            D_801B6F20 = D_801B6F24 = D_801B6F28 = 0;
            func_8003B48C(&D_801B6F0C);
            func_8003B51C(&D_801B6F0C);
            D_801B6EFC.vx = 0;
            D_801B6EFC.vy = 0;
            D_801B6F00 = 0x960;
            func_8003BADC(&D_801B6EFC, &D_801B6EFC, &flag);
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B06AC)];
            q->unk4 = p->unk4 + D_801B6EFC.vx;
            q->unk6 = p->unk6 + D_801B6EFC.vy;
            q->unk8 = p->unk8 + D_801B6F00;
            q->unk16 = D_801B6EF6[0] + 0x800;
            q->unk14 = q->unk18 = 0;
        }
        if ((u16)(p->unk2 - 1) < 0x17U) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B04F8)];
            t = func_80042DA8();
            D_801B6F2C = t % 0x1000;
            i = 0;
            q->unkC = (u32)(func_80039B40(D_801B6F2C) * 0x177) >> 9;
            q->unkE = (u32)(func_80039A74(D_801B6F2C) * 0x177) >> 9;
            q->unk10 = 0x1388;
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk16 = D_801B6EF6[0];
            q->unk14 = q->unk18 = 0;
loop:
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0368)];
            t = func_80042DA8();
            D_801B6F2C = t % 0x1000;
            q->unkC = (u32)(func_80039B40(D_801B6F2C) * 0x177) >> 9;
            q->unkE = (u32)(func_80039A74(D_801B6F2C) * 0x177) >> 9;
            q->unk10 = 0x1388;
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            i++;
            q->unk16 = D_801B6EF6[0];
            q->unk14 = q->unk18 = 0;
            if (i < 2) {
                goto loop;
            }
        }
        if (p->unk2 == 0x14) {
            func_800D4CBC(p->unk1C, 0x31, 0x4000);
            func_800D5774(p->unk1C);
        }
        if (++p->unk2 >= 0x1E && (s16)n == 0) {
            func_800D52A0(0, 0xA);
            p->unk0 = -1;
        }
    }
}

void func_801B0C9C(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B08C4)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

s32 func_801B0D5C(arg0, arg1) {
    s16 i;

    func_800BBEAC((void *)func_801B0020);
    func_800D2980((void *)D_801B0E40, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, (void *)func_801B0C9C);
    i = 0;
    do {
        D_801B6F30[i].unk0 = 0;
        i++;
    } while (i < 200);
    func_800BBA84(0x61, arg1, 0x40);
    D_800F5B70 = D_800F5B71 = D_800F5B72 = 0;
    return func_800D52A0(0xC00, 8);
}
