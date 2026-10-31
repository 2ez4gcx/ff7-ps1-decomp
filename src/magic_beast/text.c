#include "common.h"
#include "magic_beast/decls.h"

s32 func_801B0054(void) {
    func_801B13EC();
    return 0;
}

INCLUDE_ASM("../asm/us/magic_beast/nonmatchings/text", func_801B0078);

INCLUDE_ASM("../asm/us/magic_beast/nonmatchings/text", func_801B0398);

void func_801B0408(void) {
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (p->unk1C < p->unk12) {
        if (D_80062D98 == 0) {
            p->unk1C++;
        }
        return;
    }
    t = p->unk18 * D_801C3498[p->unk2];
    func_800D4368(&p->unk4, (s16)(t << 4 >> 16), -(t >> 14));
    ((MgScratch *)0x1F800000)->unk0 = D_801C2ECC;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801DB4B0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DB4B0);
    if (p->unk2 >= 4) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0550(void) {
    MgSVec rot;
    MgMat m1;
    MgMat m2;
    MgMat m3;
    MgVec v;
    BsScr *sc;
    MgTask *p;
    s16 h;
    s32 t;
    s32 r;
    s32 s;

    p = &D_80162978[D_8015169C];
    if (p->unk1C < p->unk12) {
        if (D_80062D98 == 0) {
            p->unk1C++;
        }
        return;
    }
    rot.vx = 0;
    rot.vy = p->unk14;
    rot.vz = 0;
    func_8003BF8C(&rot, &m1);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    rot.vx = 0;
    rot.vy = -((s16)p->unk14 >> 1) - 0x400;
    rot.vz = 0;
    func_8003BF8C(&rot, &m3);
    m3.t[0] = p->unk4;
    m3.t[1] = p->unk6;
    m3.t[2] = p->unk8;
    rot.vx = D_801DB4CC[p->unk1E][0];
    rot.vy = 0;
    rot.vz = D_801DB4CC[p->unk1E][2];
    func_8003BF8C(&rot, &m2);
    func_8003B16C(&m2, &m1);
    func_8003B16C(&m2, &m3);
    v.vx = v.vy = v.vz = p->unk18;
    func_8003B35C(&m1, &v);
    h = p->unk18 / 3;
    v.vx = v.vy = v.vz = h * 2;
    func_8003B35C(&m3, &v);
    func_8003A63C(&D_800FA63C, &m1, &m1);
    func_8003B48C(&m1);
    func_8003B51C(&m1);
    sc = (BsScr *)0x1F800000;
    sc->unk0 = D_801C15A8;
    ((BsScr *)0x1F800000)->unk8 = 0xC;
    ((BsScr *)0x1F800000)->unk4 = D_801517C0 + 0x70;
    ((BsScr *)0x1F800000)->unkC = D_801DB4B0;
    if (p->unk2 >= 0x14) {
        ((BsScr *)0x1F800000)->unkDC = ((BsScr *)0x1F800000)->unkDD = ((BsScr *)0x1F800000)->unkDE = 0x80;
        ((BsScr *)0x1F800000)->unkE0 = 0xC0;
        ((BsScr *)0x1F800000)->unkE1 = ((BsScr *)0x1F800000)->unkE2 = 0x40;
        ((BsScr *)0x1F800000)->unkCC = (p->unk2 - 0x14) * 0xBA;
        if (p->unk2 >= 0x1A) {
            ((BsScr *)0x1F800000)->unkD0 = (p->unk2 - 0x1A) << 8;
        } else {
            ((BsScr *)0x1F800000)->unkD0 = 0;
        }
    } else {
        ((BsScr *)0x1F800000)->unkDC = ((BsScr *)0x1F800000)->unkDD = ((BsScr *)0x1F800000)->unkDE = 0x80;
        ((BsScr *)0x1F800000)->unkD0 = 0;
        ((BsScr *)0x1F800000)->unkCC = 0;
    }
    D_801DB4B0 = func_801B0398(sc);
    func_8003A63C(&D_800FA63C, &m3, &m3);
    func_8003B48C(&m3);
    func_8003B51C(&m3);
    if (p->unk2 >= 0x14) {
        sc->unkDC = sc->unkDD = sc->unkDE = 0x60;
        sc->unkE0 = 0x50;
        sc->unkE1 = sc->unkE2 = 0x28;
    }
    D_801DB4B0 = func_801B0398(sc);
    if (p->unk2 >= 0x2A) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        t = p->unk2;
        if (t < 6) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unkC -= p->unkC >> 2;
            p->unk10 -= p->unk10 >> 2;
        } else if (t < 0x14) {
            s = func_80039A74(p->unkA);
            r = func_80042DA8();
            p->unk6 += s * 0x50 >> 12;
            p->unkA += 0x96;
            p->unkA += r % 44;
        } else {
            p->unk16 -= p->unk16 >> 3;
            p->unk18 += p->unk1A;
            p->unk1A -= p->unk1A / 5;
            if (p->unk1A < 0) {
                p->unk1A = 0;
            }
        }
        if (p->unk2 == 0x14 && D_801DB54C == 0) {
            func_800D55F4(0x20, func_800D574C(D_801DB4B8), 0x175);
            D_801DB54C = 1;
        }
        p->unk2++;
    }
}

void func_801B0AC8(void) {
    u8 pad[8];
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 cnt;
    s32 w;
    s32 n;
    s32 m;
    s32 sc;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 0) {
            cnt = func_80042DA8() % 2 + 5;
            w = p->unk18;
            n = w + 0xE0;
            if (n >= 0x4F3) {
                n = 0x4F2;
            }
            m = n * 2;
            sc = (w << 12) / 1300;
            i = 0;
            if (cnt > 0) {
                do {
                    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0408)];
                    *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                    q->unk4 += func_80042DA8() % m - n;
                    q->unk6 += func_80042DA8() % m - n;
                    q->unk8 += func_80042DA8() % m - n;
                    q->unk12 = func_80042DA8() % 4 + i * 2;
                    q->unk18 = sc * (func_80042DA8() % 0xC00 + 0xE00) >> 12;
                    q->unk1C = 0;
                    i++;
                } while (i < cnt);
            }
        }
        if (p->unk2 >= 0x10) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0D5C(void) {
    MgSVec rot;
    MgSVec tp;
    MgMat m;
    MgVec v;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 ang;
    s32 k;
    s32 c;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 0x19) {
            func_800D3994(D_801DB4BC, D_8015190F[D_801DB4BC][10], &D_801DB4C0);
            ang = func_80042DA8() % 0x1000;
            i = 0;
            rot.vz = 0;
            rot.vx = 0;
            do {
                ang = ang + (func_80042DA8() % 0x200 + 0x200);
                rot.vy = ang;
                func_8003BF8C(&rot, &m);
                func_8003AB84(&m, (MgVec *)&D_801C3488, &v);
                k = (s16)p->unk18 + func_80042DA8() % ((s16)p->unk18 >> 1);
                tp.vx = p->unk4 + (k * v.vx >> 12);
                tp.vy = p->unk6 + func_80042DA8() % (s16)p->unk1A - ((s16)p->unk1A >> 1);
                tp.vz = p->unk8 + (k * v.vz >> 12);
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0550)];
                *(MgB8 *)&q->unk4 = *(MgB8 *)&D_801DB4C0;
                q->unkA = func_80042DA8() % 2 << 11;
                q->unkC = (tp.vx - D_801DB4C0.vx) / 6 * 2;
                q->unkE = (tp.vy - D_801DB4C0.vy) / 6;
                q->unk10 = (tp.vz - D_801DB4C0.vz) / 6 * 2;
                q->unk12 = func_80042DA8() % 7 + i;
                q->unk14 = func_80042DA8() % 0x1000;
                q->unk16 = func_80042DA8() % 320 + 0x100;
                q->unk18 = 0x1A00;
                k = func_80042DA8() % 0x500 + 0xD00;
                q->unk1C = 0;
                q->unk1E = D_801DB4C8;
                q->unk18 = (q->unk18 * k >> 12) / 20;
                q->unk1A = q->unk18 * 6;
                D_801DB4CC[D_801DB4C8][0] = func_80042DA8() % 0x1000;
                D_801DB4CC[D_801DB4C8][2] = func_80042DA8() % 0x1000;
                D_801DB4C8++;
                i++;
            } while (i < 4);
            func_800D55F4(0x20, func_800D56A8(&D_801DB4C0), 0x14D);
        }
        c = 0;
        if (p->unk2 < 8) {
            D_800F5B70 = D_800F5B71 = D_800F5B72 = 0;
        } else if (p->unk2 < 0x10) {
            c = (p->unk2 - 8) * 0x180;
        } else if (p->unk2 < 0x42) {
            c = 0xC00;
        } else {
            c = 0xC00 - (p->unk2 - 0x42) * 0x180;
        }
        if (p->unk2 == 0x3E) {
            i = 0;
            do {
                if ((1 << i) & D_801DB4B8) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
        }
        if (p->unk2 >= 0x4A) {
            c = 0;
            p->unk0 = -1;
        }
        D_800F5B74.v = c;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_beast/nonmatchings/text", func_801B1320);

INCLUDE_RODATA("../asm/us/magic_beast/nonmatchings/text", D_801B0000);

s32 func_801B13EC(arg0, arg1) {
    s32 r;

    D_801DB4B4 = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(&D_801B1488, 0, 0, 0);
    r = func_800BBEAC((M2C_UNK *)func_801B1320);
    D_801DB4B8 = arg0;
    D_801DB4BC = arg1;
    D_801DB4C8 = 0;
    D_801DB54C = 0;
    return r;
}
