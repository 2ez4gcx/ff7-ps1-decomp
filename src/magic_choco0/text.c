#include "common.h"
#include "magic_choco0/decls.h"

M2C_UNK *func_801B0038(void) {
    func_801B1F68();
    return &D_801D267C;
}

s32 func_801B0060(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801E5A12[-v];
    }
    return v;
}

INCLUDE_ASM("../asm/us/magic_choco0/nonmatchings/text", func_801B009C);

void func_801B103C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B009C)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

MgMat *func_801B10A0(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801E5898.m[0][0] = D_801E5898.m[1][1] = D_801E5898.m[2][2] = scale;
    func_8003B48C(&D_801E59F0);
    func_8003B51C(&D_801E59F0);
    func_8003BC6C(v, (MgVec *)D_801E5898.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801E5898.t, &n);
        D_801E5898.t[0] += (dist * n.vx) >> 12;
        D_801E5898.t[1] += (dist * n.vy) >> 12;
        D_801E5898.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801E5898);
    func_8003B51C(&D_801E5898);
    return &D_801E5898;
}

void func_801B11BC(void) {
    MgTask *p;
    s32 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B10A0((MgSVec *)&p->unk4, p->unk14, 0);
    frame = &D_801E58B8;
    *frame = D_801D2574[p->unk2];
    D_80163C74 = func_800D4D90(frame, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x10) {
            p->unk0 = -1;
        } else {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unkC = p->unkC * 7 >> 3;
            p->unk10 = p->unk10 * 7 >> 3;
        }
    }
}

void func_801B12DC(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 r;
    s32 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B11BC)];
            q->unk4 = ((u16 *)&D_801E575C)[0];
            q->unk6 = ((u16 *)&D_801E575C)[1];
            q->unk8 = ((u16 *)&D_801E575C)[2];
            r = func_80042DA8() % 100 + 100;
            a = func_80042DA8() & 0x7FF;
            q->unkC = func_80039B40(a) * r >> 12;
            q->unkE = -(func_80042DA8() % 30 + 20);
            q->unk10 = -func_80039A74(a) * r >> 12;
            q->unk14 = func_80042DA8() % 0x800 + 0x1000;
            i++;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B14A8(void) {
    MgObj20 *p;
    s32 t;
    s32 v;
    s32 *q;
    MgMat *m;

    p = &D_80162978[D_8015169C];
    t = (s16)(p->unk2 % 7);
    if (t < 3) {
        v = (t << 12) / 3 + 0x1000;
    } else {
        t -= 3;
        v = -(t << 12) / 4 + 0x2000;
    }
    D_801E58D4 = D_801E58DC = v;
    v = func_8003B66C();
    q = &D_801E58F0;
    m = (MgMat *)(q - 7);
    *q = v * 8;
    func_8003B48C(m);
    func_8003B51C(m);
    D_80163C74 = func_800D6260(&D_801E58C4, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B1614(void) {
    MgObj20 *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x3C) {
            D_801E5760 = t * 0xFA - 0x3A98;
        } else {
            t -= 0x3C;
            if (t >= 0x14) {
                t -= 0x14;
                if (t >= 0x32) {
                    p->unk0 = -1;
                    return;
                }
            } else if (t == 0x13) {
                D_801E5760 = -0x1388;
                D_801E575C.vx = -0x2EE;
                D_80153D1A[0] += 0x400;
            }
        }
        func_8003B48C(&D_801E59D0);
        func_8003B51C(&D_801E59D0);
        func_8003BC6C(&D_801E575C, D_801E58F4, &D_801E58F4[1].vx);
        D_80153D1A[3] = D_801E58F4->vx;
        D_80153D1A[4] = D_801E58F4->vy;
        D_80153D1A[5] = D_801E58F4->vz;
        p->unk2++;
    }
}

void func_801B1760(void) {
    MgTask *p;
    s32 ang;
    s32 i;

    i = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    ang = p->unkE;
    do {
        D_801E5904->vx = p->unk4 + (func_80039A74(ang) * 0x96 >> 12);
        D_801E5904->vy = p->unk6;
        D_801E5904->vz = p->unk8 + (func_80039B40(ang) * 0x96 >> 12);
        ang += 0x400;
        i++;
        func_801B10A0(D_801E5904, 0x500, 0);
        D_80163C74 = func_800D4D90(&D_801E58F8, D_801517C0 + 0x70, 0xC, D_80163C74);
    } while (i < 4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x23) {
            p->unk0 = -1;
        } else {
            p->unkE += 0x40;
        }
    }
}

void func_801B18BC(void) {
    MgTask *p;
    s32 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B10A0((MgSVec *)&p->unk4, p->unk14, 0);
    frame = &D_801E5908;
    *frame = D_801D2574[p->unk2];
    D_80163C74 = func_800D4D90(frame, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x10) {
            p->unk0 = -1;
        } else {
            p->unk6 += p->unkE;
        }
    }
}

void func_801B1998(void) {
    MgTask *p;
    MgTask *q;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B18BC)];
            q->unk4 = func_80042DA8() % 4000 - 2000;
            q->unk6 = 0;
            q->unk8 = func_80042DA8() % 3000 - 3000;
            q->unkC = 0;
            q->unkE = -(func_80042DA8() % 30 + 20);
            q->unk10 = 0;
            q->unk14 = func_80042DA8() % 0x2000 + 0x1000;
            i++;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B1B40(void) {
    s32 flag;
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    func_8003B48C(&D_80153FD0);
    func_8003B51C(&D_80153FD0);
    func_8003BC6C(&D_801E5914, &D_801E5938, &flag);
    func_8003BC6C(&D_801E591C, &D_801E5958, &flag);
    D_801E596C[0] = p->unk2 & 7;
    func_8003B48C((MgMat *)((u8 *)&D_801E5938 - 0x14));
    func_8003B51C((MgMat *)((u8 *)&D_801E5938 - 0x14));
    D_80163C74 = func_800D4D90(&D_801E596C[-4], D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B48C((MgMat *)((u8 *)&D_801E5958 - 0x14));
    func_8003B51C((MgMat *)((u8 *)&D_801E5958 - 0x14));
    D_80163C74 = func_800D4D90(&D_801E596C[-4], D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B1CA8(void) {
    MgTask *p;
    MgTask *q;
    MgTask *r;
    s32 t;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801E59D0, &D_801E59F0);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 5) {
            if (t == 4) {
                q = func_800D4FA8(1);
                q->unk4 = 0;
                q->unk6 = 0;
                *(s16 *)((u8 *)q + 8) = ((s16 *)D_801E59E4)[4] - 0x3A98;
                q->unk10 = D_801E5756 + 0x800;
            }
        } else {
            t -= 5;
            if (t < 0x14) {
                if (t == 0) {
                    func_800BBEAC((M2C_UNK *)func_801B12DC);
                    func_800BBEAC((M2C_UNK *)func_801B1614);
                    func_800D55F4(0x22, 0x40, 0x24D, 0x24E, 0x24F);
                }
            } else {
                t -= 0x14;
                if (t >= 0x14) {
                    t -= 0x14;
                    if (t >= 0x14) {
                        t -= 0x14;
                        if (t < 0x14) {
                            if (t == 0) {
                                func_800BBEAC((M2C_UNK *)func_801B14A8);
                                func_800BBEAC((M2C_UNK *)func_801B1998);
                            }
                            if (t == 0x13) {
                                func_800D25C0(&D_801E5970, 0, 0, 0);
                            }
                            if (t == 0) {
                                func_800D55F4(0x22, 0x40, 0x250, 0x251, 0x252);
                            }
                        } else {
                            t -= 0x14;
                            if (t < 0x19) {
                                if (t == 0) {
                                    r = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B1760)];
                                    r->unk4 = 0x32;
                                    r->unk6 = -0x1F4;
                                    r->unk8 = -0x1388;
                                    func_800BBEAC((M2C_UNK *)func_801B1B40);
                                }
                            } else {
                                t -= 0x19;
                                if (t >= 5) {
                                    t -= 5;
                                    if (t < 0x14) {
                                        if (t == 0x12) {
                                            func_800D4FA8(2);
                                        }
                                    } else {
                                        t -= 0x14;
                                        if (t < 0xF) {
                                            if (t == 0) {
                                                i = 0;
                                                while (1) {
                                                    if ((D_801E5A10 >> i) & 1) {
                                                        func_800D5774(i);
                                                    }
                                                    i++;
                                                    if (i >= 10) {
                                                        break;
                                                    }
                                                }
                                            }
                                        } else {
                                            p->unk0 = -1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        p->unk2++;
    }
}

void func_801B1F68(arg0, arg1) {
    MgSVec v;
    MgMat *m;
    s32 *p;

    func_800D2980(&D_801B2074, 0, 0, 0);
    D_801E5A10 = arg0;
    func_800D54EC(arg0, &v);
    p = D_801E59E4;
    D_801E59E4[1] = 0;
    p[0] = 0;
    D_801E59E4[2] = v.vz;
    if (v.vz < D_80151A50[arg1][0]) {
        D_801E5756 = 0x800;
    }
    m = (MgMat *)(p - 5);
    func_8003C21C(&D_801E5754, m);
    func_800BBEAC(&func_801B1CA8);
    if (func_80042DA8() & 0x100) {
        ((void (*)(s32, s32, s32))func_801B103C)((s32)&D_801E5764, (s32)m, arg1);
    } else {
        ((void (*)(s32, s32, s32))func_801B103C)((s32)&D_801E5804, (s32)m, arg1);
    }
}
