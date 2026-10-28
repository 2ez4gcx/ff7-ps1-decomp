#include "common.h"
#include "magic_quasar/decls.h"

void func_801B0000(void) {
    func_801B1470();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EF54C = D_801D754C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D7410;
    *frame = p->unk2;
    D_801EF54C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EF54C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D7344) {
            p->unk0 = -1;
        }
    }
}

void func_801B0144(void) {
    u8 pad0[0x10];
    MgMat m;
    u8 pad1[0x20];
    MgMat lw;
    MgTask *p;
    s16 k;
    s16 a;
    u8 *v;
    s32 c;
    u16 u;
    u16 fr;
    M2C_UNK **q;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = p->unk2;
    a = 8;
    if (k >= 0x2F) {
        a = 0x37 - k;
    }
    func_8003BF8C((MgSVec *)&p->unkC, &m);
    func_8003A79C(&D_801EF55C, &m, &m);
    D_801D7424[0] = p->unk18;
    D_801D7428 = 0x2000;
    D_801D7424[-1] = 0x2000;
    func_8003B35C(&m, (MgVec *)&D_801D7424[-1]);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    q = &D_801D7414;
    v = D_801D7278;
    if (p->unk16 == 0) {
        v = D_801D70F0;
    }
    *q = (M2C_UNK *)v;
    fr = D_801D7470[p->unk16][p->unk14];
    D_801D7418.v = D_801D7419.v = D_801D741A.v = a * 0x10;
    D_801D741C = fr;
    D_80163C74 = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        c = 0xC;
        if (p->unk16 == 0) {
            c = 0x14;
        }
        u = p->unk14;
        n = u + 1;
        p->unk14 = n;
        if (n == c) {
            p->unk14 = u - 3;
        }
        p->unk2++;
        if (p->unk2 == 0x37) {
            p->unk0 = -1;
        }
    }
}

void func_801B0340(void) {
    MgTask *p;
    s16 k;
    s16 a;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = p->unk2;
    a = 8;
    if (k >= 7) {
        a = 0xF - k;
    }
    func_800D4368((MgSVec *)&p->unk4, p->unk18, 0);
    D_801D747C[0] = D_801D747D = D_801D747E = a << 4;
    D_801EF54C = func_800D4D90(&D_801D747C[-4], D_801517C0 + 0x70, 0xC, D_801EF54C);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        n = (u16)p->unk2 + 1;
        p->unk8 += p->unk10;
        p->unk2 = n;
        if (n == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B045C(void) {
    MgSVec rot;
    MgMat lw;
    MgMat m;
    MgTask *p;
    s16 *frame;
    s32 t;

    rot.vx = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vy = p->unk2 << 8;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    t = (p->unk2 << 8) + 0x1000;
    D_801D7518[0] = D_801D751C = D_801D7520 = t;
    func_8003B35C(&m, (MgVec *)D_801D7518);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801D748E;
    *frame = 0x80 - p->unk2 * 6;
    D_801EF54C = (s32)func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, (u8 *)D_801EF54C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B05B0(void) {
    MgSVec rot;
    MgMat lw;
    MgMat m;
    MgTask *p;
    MgTask *r;
    s32 *q;
    s16 k;
    s16 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = p->unk2;
    if (k >= 0xC) {
        a = 0x14 - k;
    } else {
        a = 8;
    }
    rot.vx = 0;
    rot.vy = p->unk2 << 9;
    rot.vz = p->unk2 << 8;
    func_8003C21C(&rot, &m);
    D_801D7528[0] = D_801D752C = D_801D7530 = p->unk18;
    func_8003B35C(&m, (MgVec *)D_801D7528);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    q = &D_801D7494;
    *q = (s32)((s32 **)((u8 *)D_801D749E + 6))[p->unk16];
    D_801D749E[0] = a << 4;
    D_801EF54C = (s32)func_800D29D4(q, D_801517C0 + 0x70, 0xC, (u8 *)D_801EF54C);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk18 += 0x80;
        if (p->unk6 >= -0x63) {
            r = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B045C)];
            r->unk4 = p->unk4;
            r->unk6 = 0;
            r->unk8 = p->unk8;
            p->unk0 = -1;
        }
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_quasar/nonmatchings/text", func_801B07BC);

void func_801B0E88(void) {
    MgTask *p;
    s32 c;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368((MgSVec *)&p->unk4, p->unk18, 0);
    c = D_801D7504 * 8;
    D_801D74FC[0] = D_801D74FD = D_801D74FE = c;
    D_801EF54C = func_800D4D90(&D_801D74FC[-4], D_801517C0 + 0x70, 0xC, D_801EF54C);
    if (D_80062D98 == 0) {
        p->unk18 += 0x800;
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        D_801D7504--;
        if (n == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B0F74(void) {
    MgSVec v;
    MgTask *p;
    MgTask *q;
    u16 *frame;
    s16 i;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368((MgSVec *)&p->unk4, (s16)((func_80039A74(p->unk2 * 0x300) << 11 >> 12) + 0x3000), 0);
    frame = &D_801D7510;
    *frame = D_801D7514;
    c = D_801D7516 * 8;
    D_801D750C = D_801D750D = D_801D750E = c;
    D_801EF54C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EF54C);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0xF) {
            p->unk6 -= 0x64;
        }
        if (p->unk2 == 0xF) {
            D_801D7514 += 1;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0E88)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk18 = 0x800;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B07BC)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            v.vx = *(u16 *)D_801EF554 - p->unk4;
            v.vy = D_801EF556 - p->unk6;
            v.vz = D_801EF558 - p->unk8;
            func_800D44E8(&v, &D_801EF55C);
            i = 0;
            D_801EF57C = func_80039F5C(v.vx * v.vx + v.vy * v.vy + v.vz * v.vz);
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0144)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unk18 = (D_801EF57C << 12) / 2000;
                q->unkC = func_80042DA8() % 1024 - 0x200;
                q->unkE = func_80042DA8() % 1024 + 0x200;
                q->unk10 = 0x400;
                q->unk14 = func_80042DA8() % 8;
                q->unk16 = i % 2;
            } while (++i < 10);
        }
        if (p->unk2 >= 0x10) {
            D_801D7516--;
        }
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B1318(void) {
    u8 pad[0x38];
    MgTask *p;
    MgTask *q;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0F74)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            D_800F5B74.v = 0x1000;
        }
        if (p->unk2 == 0xD) {
            func_800D5138(2);
        }
        if (p->unk2 == 0xF) {
            func_800D51D4(0xF);
        }
        if (p->unk2 == 0x46) {
            for (i = 0; i < 10; i++) {
                if ((D_801EF550 >> i) & 1) {
                    func_800D5774(i);
                }
            }
        }
        p->unk2++;
        if (p->unk2 == 0x50) {
            func_800D52A0(0, 0x14);
            p->unk0 = -1;
        }
    }
}

s32 func_801B1470(arg0, arg1) {
    func_800BBEAC((M2C_UNK *)func_801B0020);
    func_800D2980(&D_801B1540, 0, 0, 0);
    D_801EF550 = arg0;
    func_800D3994(arg1, D_80151918[arg1][0], &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1318)].unk4);
    func_800D54EC(arg0, D_801EF554);
    return func_800BBA84(0x131, arg1, 0);
}
