#include "common.h"
#include "magic_mizufuki/decls.h"

void func_801B0000(void) {
    func_801B140C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E9DAC = D_801D1DAC + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368((MgSVec *)&p->unk4, 0x3000, 0);
    frame = &D_801D1D38;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801D1D3C[p->unk1A];
    D_801E9DAC = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_801E9DAC);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D1D3C[p->unk1A][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B017C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D1D4C;
    *frame = p->unk2;
    D_801E9DAC = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E9DAC);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D1724) {
            p->unk0 = -1;
        }
    }
}

void func_801B0234(void) {
    s32 otz;
    s32 flag;
    MgTask *p;
    u8 *pkt;
    s32 n;
    s32 k;

    p = &D_801621F0[D_801590D4];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    pkt = D_80163C74;
    func_80046974(pkt);
    n = func_8003BBDC(&p->unk4, pkt + 8, &otz, &flag);
    if (n > 0) {
        pkt[4] = pkt[5] = pkt[6] = 0x80;
        k = (n >> 2) * 4 + 0x70;
        func_80046794(k + D_801517C0, (s32)pkt);
        D_80163C74 = pkt + 0xC;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC -= p->unkC / 4;
        p->unkE -= p->unkE / 4;
        p->unk10 -= p->unk10 / 4;
        if (++p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B03B0(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D1D58;
    *frame = p->unk2;
    D_801E9DAC = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E9DAC);
    if (D_80062D98 == 0) {
        p->unk4.vx += p->unkC.vx;
        p->unk4.vy += p->unkC.vy;
        p->unk4.vz += p->unkC.vz;
        p->unk2++;
        if (p->unk2 == D_801D1914) {
            p->unk0 = -1;
        }
    }
}

void func_801B0498(void) {
    MgSVec pos;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    pos.vx = p->unk4 + (func_80039A74(p->unk14) * p->unk16 >> 12);
    pos.vz = p->unk8 + (func_80039B40(p->unk14) * p->unk16 >> 12);
    pos.vy = p->unk6;
    func_800D4368(&pos, 0x1000, 0);
    D_801D1D5C[0] = D_801D1D68[p->unk1A];
    D_801E9DAC = func_800D4D90(D_801D1D5C, D_801517C0 + 0x70, 0xC, D_801E9DAC);
    if (D_80062D98 == 0) {
        p->unk6 -= 0xC8;
        p->unk14 += 0x100;
        p->unk16 += 0x64;
        if (++p->unk2 == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B05E0(void) {
    MgTask *p;
    s16 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 >= 0xC) {
        k = 0x14 - p->unk2;
    } else {
        k = 8;
    }
    func_800D4368((MgSVec *)&p->unk4, 0x800, 0);
    D_801D1D74[0] = D_801D1D74[1] = D_801D1D74[2] = k << 4;
    D_801E9DAC = func_800D4D90(D_801D1D74 - 4, D_801517C0 + 0x70, 0xC, D_801E9DAC);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkE += 0xA;
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0708(void) {
    MgSVec rot;
    MgMat m2;
    MgMat m1;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 a;
    s32 t;

    rot.vx = rot.vz = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vy = p->unk2 << 6;
    func_8003C21C(&rot, &m1);
    func_8003B35C(&m1, &D_801D1D7C);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6 + 0x190;
    m1.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m1, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    D_801D1D96[0] = D_801D1D9C << 3;
    D_801E9DAC = func_800D29D4((u8 *)D_801D1D96 - 0xA, D_801517C0 + 0x70, 0xC, D_801E9DAC);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x25) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B03B0)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unkC = (u32)(func_80039A74(p->unk2 * 0xC0 + i * 0x800) * 0x23) >> 11;
                q->unk10 = (u32)(func_80039B40(p->unk2 * 0xC0 + i * 0x800) * 0x23) >> 11;
                q->unkE = -0xB4;
                i++;
            } while (i < 2);
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0498)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk14 = func_80042DA8() % 0x1000;
            q->unk16 = 0;
            q->unk1A = func_80042DA8() % 2;
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B05E0)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                a = func_80042DA8() % 0x1000;
                q->unkC = (u32)(func_80039A74(a) * 0xF) >> 9;
                q->unk10 = (u32)(func_80039B40(a) * 0xF) >> 9;
                i++;
                q->unkE = -0x64 - func_80042DA8() % 100;
            } while (i < 2);
        }
        if (p->unk2 < 0x10) {
            D_801D1D9C += 1;
        }
        if (p->unk2 >= 0x1E) {
            D_801D1D9C -= 1;
        }
        if (++p->unk2 == 0x2D) {
            p->unk0 = -1;
        }
    }
}

void func_801B0AE8(void) {
    MgSVec rot;
    MgSVec v2;
    MgMat m;
    MgTask *p;
    MgTask *q;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368((MgSVec *)&p->unk4, (s16)(p->unk1A * 0xC8 + 0x1000), 0);
    D_801E9DAC = func_800D4D90(&D_801D1DA0, D_801517C0 + 0x70, 0xC, D_801E9DAC);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk14 += 0x80;
        if (p->unk2 == D_801E9DB0) {
            if (p->unk1C == 0) {
                i = 0;
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B008C)];
                func_800D3994(D_801E9DB4, D_8015190F[D_801E9DB4][0], &q->unk4);
                q->unk4 = q->unk4 + (func_80042DA8() % 800 - 0x190);
                q->unk6 = q->unk6 + (func_80042DA8() % 800 - 0x190);
                q->unk8 = q->unk8 + (func_80042DA8() % 800 - 0x190);
                q->unk1A = 0;
                do {
                    q = &D_801621F0[func_800BC04C(func_801B0234)];
                    func_800D3994(D_801E9DB4, D_8015190F[D_801E9DB4][0], &q->unk4);
                    v2.vx = 0;
                    v2.vy = 0;
                    v2.vz = func_80042DA8() % 100 + 0xFA;
                    rot.vx = func_80042DA8();
                    rot.vy = func_80042DA8();
                    rot.vz = 0;
                    func_8003BF8C(&rot, &m);
                    func_8003B2CC(&m, &v2, (MgSVec *)&q->unkC);
                    i++;
                } while (i < 10);
            }
            p->unk0 = -1;
        }
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0E40(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 a;
    s32 k;
    s32 t;
    s32 r;
    u8 pad[16];

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B017C)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
        }
        if (p->unk2 < 5) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0AE8)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                k = 7 - i;
                q->unk4 += p->unkC * k / 8;
                q->unk6 += p->unkE * k / 8;
                q->unk8 += p->unk10 * k / 8;
                q->unkC = p->unkC;
                q->unkE = p->unkE;
                q->unk10 = p->unk10;
                q->unk1A = (5 - p->unk2) * 8 - i;
                q->unk14 = func_80042DA8() % 0x1000;
                q->unk18 = func_80042DA8() % 2;
                r = func_80042DA8();
                q->unk1C = i;
                i++;
                q->unk16 = q->unk1A * 20 + r % 200;
            } while (i < 8);
        }
        if (p->unk2 == 0x37) {
            func_800D5774(p->unk1C);
        }
        t = (u16)p->unk2;
        if ((u32)(t - 10) < 9) {
            a = (s16)t * 0x200 - 0x1800;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B008C)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            q->unk4 += func_80039B40(a) * 0x258 >> 12;
            k = func_80039A74(a);
            q->unk1A = 1;
            q->unk6 += k * 0x258 >> 12;
        }
        if (p->unk2 == 0xF) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0708)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            q->unk6 = 0;
            func_800BBA84(0x1BE, p->unk1C, 0);
        }
        if (++p->unk2 == 0x46) {
            func_800D52A0(0, 0xA);
            p->unk0 = -1;
        }
    }
}

void func_801B124C(arg0, arg1) {
    MgVec a;
    MgVec b;
    MgSVec loc;
    MgTask *p;
    s16 k;

    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B0E40)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &loc);
    b.vx = loc.vx - p->unk4;
    b.vy = loc.vy - p->unk6;
    b.vz = loc.vz - p->unk8;
    func_8003A08C(&b, &a);
    p->unkC = (u32)(a.vx * 0x7D) >> 9;
    p->unkE = (u32)(a.vy * 0x7D) >> 9;
    k = p->unk10 = a.vz * 0x3E8 >> 12;
    if (k != 0) {
        D_801E9DB0 = b.vz / k;
    } else {
        D_801E9DB0 = 1;
    }
    p->unk1C = D_801E9DB4 = arg0;
}

s32 func_801B140C(arg0, arg1) {
    func_800BBEAC(func_801B0020);
    func_800D2980(&D_801B149C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, (M2C_UNK *)func_801B124C);
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    return func_800D52A0(0xC00, 0xA);
}
