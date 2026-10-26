#include "common.h"
#include "magic_bioga2/decls.h"

void func_801B0000(void) {
    func_801B0AB8();
}

void func_801B0020(void) {
    MgTask *p;
    MgMat *s;
    s16 *q;
    BgB8 *src;
    BgB8 *d;
    s16 w;
    s32 i;
    s32 t;

    p = &D_80162978[D_8015169C];
    *(q = &D_801E37A0.w) = w = ((func_80039A74(((p->unk2 % 5) << 12) / 5) + 0x1000) * 0x9F >> 13) + 0x60;
    D_801E37B0.m[0][0] = p->unk2 * 0x2500 / 30 + 0xB00;
    D_801E37B0.m[1][1] = p->unk2 * 0x1A00 / 30 + 0xB00;
    D_801E37B0.m[2][2] = p->unk2 * 0x2500 / 30 + 0xB00;
    s = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t >= 0x14) {
        t -= 0x14;
        if (t < 10) {
            *q = w * (10 - t) / 10;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    src = D_801E361C[p->unk2 % 15];
    d = D_801C7CD4;
    for (i = 0; i < 0x2EA; i++) {
        *d++ = *src++;
    }
    D_801E37B0.t[0] = p->unk8;
    D_801E37B0.t[2] = p->unkC;
    func_8003A63C(D_800FA63C, &D_801E37B0, s);
    func_8003B48C(s);
    func_8003B51C(s);
    D_801EF7F4 = func_800D29D4(&D_801E37A0, D_801517C0 + 0x70, 0xC, D_801EF7F4);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0328(void) {
    MgTask *p;
    s32 t;
    s32 c;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xA) {
        *(s32 *)&D_801E37D4 = 0x2C808080;
    } else {
        t -= 0xA;
        if (t < 0xF) {
            D_801E37D7 = 0x2E;
            c = -(t << 7) / 15 - 0x80;
            D_801E37D4 = D_801E37D5 = D_801E37D6 = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    D_801E37D8[0] = p->unk2 % 7;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801EF7F4 = (u8 *)func_800D4D90(&D_801E37D8[-4], D_801517C0 + 0x70, 0xC, (s32)D_801EF7F4);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unkA -= p->unk12;
    }
}

void func_801B04A4(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    frame = &D_801E37E4;
    *frame = p->unk2;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801EF7F4 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EF7F4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B0564(void) {
    MgTask *p;
    MgTask *q;
    s32 n;
    s32 r0;
    s32 r1;
    s32 r2;
    s32 t0;
    s32 t1;
    s32 t2;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = p->unk2;
        if (n < 0x19) {
            if (!(n & 1)) {
                q = &D_80162978[func_800BBEAC(func_801B04A4)];
                func_800D3994(p->unk4, D_8015190F[p->unk4][0], &q->unk8);
                r0 = func_80042DA8();
                t0 = (u16)q->unk8 - 0x1F4;
                q->unk8 = t0 + r0 % 1000;
                r1 = func_80042DA8();
                t1 = (u16)q->unkA - 0x1F4;
                q->unkA = t1 + r1 % 1000;
                r2 = func_80042DA8();
                t2 = (u16)q->unkC - 0x1F4;
                q->unkC = t2 + r2 % 1000;
                q->unk10 = func_80042DA8() % 0x1000 + 0x1000;
            }
        } else {
            p->unk0 = -1;
            return;
        }
        p->unk2++;
    }
}

void func_801B0734(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 i;
    s32 r0;
    s32 r1;
    s32 t0;
    s32 t1;
    s32 z;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_800D52A0(0x800, 5);
            D_800F5B70 = 0;
            D_800F5B71 = 0x50;
            D_800F5B72 = 0;
        }
        t = p->unk2 - 5;
        if (t == 0) {
            func_800D55F4(0x20, func_800D574C(D_801E37F0), 0x52);
        }
        z = t == 0;
        if (z) {
            q = &D_80162978[func_800BBEAC(func_801B0020)];
            *(BgB8 *)&q->unk8 = *(BgB8 *)D_801E37E8;
        }
        if ((u32)t < 0xF && !(t & 1)) {
            q = &D_80162978[func_800BBEAC(func_801B0328)];
            r0 = func_80042DA8();
            q->unkA = 0;
            t0 = *(u16 *)D_801E37E8 - 0x7D0;
            q->unk8 = t0 + r0 % 4000;
            r1 = func_80042DA8();
            t1 = D_801E37EC - 0x7D0;
            q->unkC = t1 + r1 % 4000;
            q->unk10 = func_80042DA8() % 0x1B00 + 0x1500;
            q->unk12 = func_80042DA8() % 50 + 0x32;
        }
        if (t == 0) {
            for (i = 0; i < 10; i++) {
                if ((D_801E37F0 >> i) & 1) {
                    q = &D_80162978[func_800BBEAC(func_801B0564)];
                    q->unk4 = i;
                }
            }
        }
        if (t == 0x14) {
            for (i = 0; i < 10; i++) {
                if ((D_801E37F0 >> i) & 1) {
                    func_800D5774(i);
                }
            }
        }
        if (t == 0x1E) {
            func_800D52A0(0, 5);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0A50(void) {
    MgTask *p;
    u8 *buf;

    p = &D_80162978[D_8015169C];
    buf = D_801B0B50;
    if (p->unk2 == 0) {
        buf = D_801E37F4;
    }
    D_801EF7F4 = buf;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0AB8(arg0) {
    if (D_801517BC == 0) {
        func_800D2980(D_801B0B50, 0, 0, 0);
        func_800D2980(D_801B7BB0, 0, 0, 0);
    }
    func_800BBEAC(func_801B0A50);
    D_801E37F0 = arg0;
    func_800D54EC(arg0, D_801E37E8);
    func_800BBEAC(func_801B0734);
}
