#include "common.h"
#include "magic_hiwind/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0E48();
    return &D_801D2ED0;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EC010 = D_801D4010 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0094(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    D_801D3F8C[0] = p->unk2;
    D_801EC010 = func_800D4D90(&D_801D3F8C[-4], D_801517C0 + 0x70, 0xC, D_801EC010);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D26DC) {
            p->unk0 = -1;
        }
    }
}

void func_801B0150(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8((s16)D_801D3F90, (s16)D_801D3F90, (s16)D_801D3F90);
    if (D_80062D98 == 0) {
        D_801D3F90 -= 0xF;
        if (++p->unk2 == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B01EC(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C((MgSVec *)&p->unkC, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_800D461C(&lw);
    func_8003B35C(&lw, &D_801D3FA0);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D3F9C[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D3F9C[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D2470) {
            p->unk0 = -1;
        }
    }
}

void func_801B0300(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 a;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            a = func_80042DA8() % 0x1000;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B01EC)];
            q->unk4 = D_801EC018[0];
            q->unk6 = D_801EC018[1];
            q->unk8 = D_801EC018[2];
            q->unk4 += func_80039A74(a) * 0x3E8 >> 12;
            q->unk8 += func_80039B40(a) * 0x3E8 >> 12;
            t = func_80042DA8();
            i++;
            q->unkE = a;
            q->unk10 = 0;
            q->unkC = -0x1F4 - t % 0x1F4;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B04B4(void) {
    MgTask *p;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 >= 2) {
        func_800D4368(&p->unk4, 0x1C00, 0);
        D_801D3FB8[0] = (u16)p->unk2 - 2;
        if (p->unk2 == 2) {
            c = 0x80;
        } else {
            c = 0x20;
        }
        D_801D3FB6 = c;
        D_801D3FB5 = c;
        D_801D3FB4 = c;
        D_801EC010 = func_800D4D90(&D_801D3FB8[-4], D_801517C0 + 0x70, 0xC, D_801EC010);
    }
    if (D_80062D98 == 0) {
        if (++p->unk2 == D_801D21C8 + 2) {
            p->unk0 = -1;
        }
    }
}

void func_801B05B4(void) {
    MgMat m;
    MgMat a;
    MgMat lw;
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D44E8((MgSVec *)&p->unkC, &a);
    func_8003C21C(&D_801D3FDC, &m);
    func_8003A79C(&a, &m, &m);
    func_8003B35C(&m, &D_801D3FBC);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801EC010 = func_800D29D4(D_801D3FCC, D_801517C0 + 0x70, 0xC, D_801EC010);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkE -= 0x3C;
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B04B4)];
        q->unk4 = p->unk4;
        q->unk6 = p->unk6;
        q->unk8 = p->unk8;
        p->unk2++;
        if (p->unk2 == 0xA) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0094)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            p->unk0 = -1;
        }
    }
}

void func_801B0798(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    MgVec *v;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801D3FF4, &m);
    v = &D_801D3FFC;
    k = 0x14;
    v->vx = D_801D4004 = (k - p->unk2) * 0x640;
    func_8003B35C(&m, v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801EC010 = func_800D29D4(D_801D3FE4, D_801517C0 + 0x70, 0xC, D_801EC010);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == k) {
            p->unk0 = -1;
        }
    }
}

void func_801B08DC(void) {
    MgTask *p;
    MgTask *q;
    u16 *e;
    u8 pad[8];
    MgSVec v;
    u8 pad2[0x20];
    s16 i;
    s16 ang;
    s32 u1;
    s32 u2;
    s32 k1;
    s32 k2;
    s32 id;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x35) {
            D_8009A000 = 0x29;
            D_8009A004 = 0x40;
            D_8009A008 = 0x21B;
            func_8002DA7C();
        }
        if (p->unk2 == 0x45 || p->unk2 == 0x6F) {
            D_8009A000 = 0x28;
            D_8009A004 = 0x40;
            D_8009A008 = 0x223;
            func_8002DA7C();
        }
        if (((u16)(p->unk2 - 0x3C) < 0x1EU || (u16)(p->unk2 - 0x66) < 0x1EU) && p->unk2 % 3 != 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B05B4)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            ang = func_80042DA8() % 0x1000;
            q->unk4 += func_80039A74(ang) * 0x3E8 >> 12;
            q->unk8 += func_80039B40(ang) * 0x3E8 >> 12;
            v.vx = D_801EC018[0];
            v.vy = D_801EC018[1];
            v.vz = D_801EC018[2];
            if (func_80042DA8() % 3 == 0) {
                ang = func_80042DA8() % 0x1000;
                v.vx += func_80039A74(ang) * 0xFA0 >> 12;
                v.vz += func_80039B40(ang) * 0xFA0 >> 12;
            } else {
                u1 = func_80042DA8();
                k1 = (u16)v.vx - 0x5DC;
                v.vx = k1 + u1 % 3000;
                u2 = func_80042DA8();
                k2 = (u16)v.vz - 0x5DC;
                v.vz = k2 + u2 % 3000;
            }
            q->unkC = (v.vx - q->unk4) / 10;
            q->unkE = 0x258;
            q->unk10 = (v.vz - q->unk8) / 10;
        }
        if (((u16)(p->unk2 - 0x45) < 0x1BU || (u16)(p->unk2 - 0x6F) < 0x1BU) && p->unk2 % 3 == 0) {
            e = func_800D4FA8(0xA);
            id = D_801517F0[D_801D400C];
            e[8] = D_801D400C;
            D_801D400C++;
            e[0] = id;
        }
        if (p->unk2 == 0x8C) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0798)];
            q->unk4 = D_801EC018[0];
            q->unk6 = D_801EC018[1];
            q->unk8 = D_801EC018[2];
            func_800BBEAC(func_801B0150);
            func_800BBEAC(func_801B0300);
            D_8009A000 = 0x28;
            D_8009A004 = 0x40;
            D_8009A008 = 0x7C;
            func_8002DA7C();
            if (p->unk2 == 0x8C) {
                i = 0;
                do {
                    if ((D_801EC014 >> i) & 1) {
                        func_800D5774(i);
                    }
                    i++;
                } while (i < 10);
            }
        }
        p->unk2++;
        if (p->unk2 == 0xAA) {
            D_800FAFDC = 0;
            p->unk0 = -1;
        }
    }
}

s32 func_801B0E48(arg0, arg1) {
    MgTask *p;
    u16 *r;
    u8 (*b)[0xB9C];

    func_800BBEAC(func_801B0028);
    func_800D2980(&D_801B0F2C, 0, 0, 0);
    D_801EC014 = arg0;
    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B08DC)];
    func_800D54EC(arg0, &D_801EC018);
    b = D_80151A4C;
    r = (u16 *)b[arg1];
    p->unk4 = r[0];
    D_800FAFDC = 1;
    p->unk6 = r[1];
    p->unk8 = r[2];
    p->unk6 = -0xFA0;
}
