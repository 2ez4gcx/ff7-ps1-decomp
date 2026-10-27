#include "common.h"
#include "magic_debucho/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B1D64();
    return &D_801BAC54;
}

MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801C4058.m[0][0] = D_801C4058.m[1][1] = D_801C4058.m[2][2] = scale;
    func_8003B48C(&D_801C42A0);
    func_8003B51C(&D_801C42A0);
    func_8003BC6C(v, (MgVec *)D_801C4058.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801C4058.t, &n);
        D_801C4058.t[0] += (dist * n.vx) >> 12;
        D_801C4058.t[1] += (dist * n.vy) >> 12;
        D_801C4058.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801C4058);
    func_8003B51C(&D_801C4058);
    return &D_801C4058;
}

s32 func_801B0184(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801C42C2[-v];
    }
    return v;
}

INCLUDE_ASM("../asm/us/magic_debucho/nonmatchings/text", func_801B01C0);

void func_801B11DC(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B01C0)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B1240(void) {
    MgTask *p;
    s32 t;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x2D) {
        t = (t << 12) / 45;
        v = (t * 0x6000 >> 12) + 0x1000;
        D_801C4180 = D_801C4190 = v;
        D_801C417A = 0x1000 - t;
    } else {
        t -= 0x2D;
        if (t < 0x1E) {
            D_801C4180 = D_801C4190 = 0x6000;
            D_801C417A = 0;
        } else {
            t -= 0x1E;
            if (t < 0xF) {
                D_801C4180 = D_801C4190 = 0x6000;
                t = (t << 12) / 15;
                D_801C417A = t;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    func_8003A63C(&D_801C42A0, (MgMat *)&D_801C4180, D_801C41A0);
    func_8003B48C(D_801C41A0);
    func_8003B51C(D_801C41A0);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801C4170, D_801517C0 + 0x4078, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1414(void) {
    MgTask *p;
    s32 t;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    do {
        if (t < 10) {
            D_801C41AE = 0;
        } else {
            t -= 10;
            if (t >= 5) {
                p->unk0 = -1;
                return;
            }
            D_801C41AE = (t << 12) / 5;
        }
        t = (p->unk2 << 12) / 15;
    } while (0);
    v = (t * 0x5000 >> 12) + 0x1000;
    D_801C41B4.m[0][0] = D_801C41B4.m[1][1] = D_801C41B4.m[2][2] = v;
    func_8003A63C(&D_801C42A0, &D_801C41B4, D_801C41D4);
    func_8003B48C(D_801C41D4);
    func_8003B51C(D_801C41D4);
    D_80163C74 = func_800D29D4(D_801C41A4, D_801517C0 + 0x406C, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1584(void) {
    MgTask *p;
    s32 *q;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B0068((MgSVec *)&p->unk4, p->unk14, 0);
    q = &D_801C4218;
    *q = D_801C41D8[p->unk2];
    D_80163C74 = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0x10) {
            p->unk0 = -1;
        } else {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unkC = p->unkC * 0xF >> 4;
            p->unkE = p->unkE * 0x11 >> 4;
            p->unk10 = p->unk10 * 0xF >> 4;
        }
    }
}

void func_801B16BC(void) {
    MgTask *p;
    MgTask *q;
    s32 r;
    s32 n;
    s32 i;
    s16 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B1584)];
            r = func_80042DA8() & 0xFFF;
            n = func_80042DA8() % 200 + 0x64;
            q->unk4 = (u32)(func_80039A74(r) * 0x36B) >> 10;
            q->unk6 = 0;
            q->unk8 = (u32)(func_80039B40(r) * 0x36B) >> 10;
            q->unkC = n * func_80039A74(r) >> 12;
            q->unkE = -(func_80042DA8() % 100 + 0x32);
            q->unk10 = n * func_80039B40(r) >> 12;
            q->unk14 = func_80042DA8() % 0x4000 + 0x4000;
            i++;
        } while (i < 0xF);
        c = (u16)p->unk2 + 1;
        p->unk2 = c;
        if (c >= 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B18B0(void) {
    MgObj20 *p;
    u16 *q;
    u16 *r;
    s16 n;
    s32 v;
    u16 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (!(t & 1)) {
            v = -((s16)t * 0x1F4) / 30 + 0x1F4;
            q = &D_801031EA;
            r = &D_80158D02;
            *q -= v;
            *r -= v;
        }
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B1980(void) {
    MgObj20 *p;
    u16 *q;
    s16 n;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = &D_80153D22;
        *q += 0x29A;
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B19EC(void) {
    MgObj20 *p;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_80046794(D_801517C0 + 0x406C, (s32)D_801C4224 + D_801C4244 * 0x10);
    D_801C4244 ^= 1;
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0xC) {
            p->unk0 = -1;
        }
    }
}

void func_801B1A98(void) {
    MgTask *p;
    s16 *w;
    s32 t;
    s32 i;
    u8 pad[8];

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801C4030, &D_801C42A0);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t > 0) {
            t -= 1;
            if (t < 0xF) {
                if (t == 0) {
                    func_800BBEAC(&func_801B1240);
                    func_800D55F4(0x22, 0x40, 0x1FB, 0x1FC, 0x1FD);
                }
            } else {
                t -= 0xF;
                if (t < 0xF) {
                    if (t == 0xE) {
                        w = (s16 *)func_800D4FA8(1);
                        *(s16 *)((u8 *)w + 4) = 0;
                        *(s16 *)((u8 *)w + 6) = -0x2710;
                        *(s16 *)((u8 *)w + 8) = D_801C404C;
                        *(s16 *)((u8 *)w + 0x10) = D_801C4052;
                    }
                } else {
                    t -= 0xF;
                    if (t < 0xC) {
                        if (t == 0) {
                            func_800BBEAC(&func_801B1980);
                            func_800BBEAC(&func_801B19EC);
                        }
                    } else {
                        t -= 0xC;
                        if (t < 0x30) {
                            if (t >= 3) {
                                t -= 3;
                                if (t < 0x1E) {
                                    if (t == 0) {
                                        func_800BBEAC(&func_801B1414);
                                        func_800BBEAC(&func_801B16BC);
                                        func_800BBEAC(&func_801B18B0);
                                    }
                                } else {
                                    t -= 0x1E;
                                    if (t < 0xF) {
                                        if (t == 0) {
                                            i = 0;
                                            D_80153BC8.c0 = D_80153BC8.c1 = D_80153BC8.c2 = 0;
                                            if (D_80153BC8.n > 0) {
                                                do {
                                                    D_80153BC8.f[i] |= 8;
                                                    i++;
                                                } while (i < D_80153BC8.n);
                                            }
                                        }
                                        D_80153BCC = (t << 12) / 15;
                                        if (t == 0xE) {
                                            func_800D4FA8(2);
                                        }
                                    }
                                }
                            }
                        } else {
                            i = 0;
                            do {
                                if ((D_801C42C0 >> i) & 1) {
                                    func_800D5774(i);
                                }
                                i++;
                            } while (i < 0xA);
                            D_800F8380 = 0;
                            p->unk0 = -1;
                        }
                    }
                }
            }
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_debucho/nonmatchings/text", func_801B1D64);
