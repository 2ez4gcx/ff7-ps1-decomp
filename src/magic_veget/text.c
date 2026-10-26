#include "common.h"
#include "magic_veget/decls.h"

void func_801B0000(void) {
    D_801C4618 = &D_801B6A50;
    func_801B0940();
}

void func_801B0030(void) {
    D_801C4618 = &D_801B94D4;
    func_801B0940();
}

void func_801B0060(void) {
    D_801C4618 = &D_801BAF38;
    func_801B0940();
}

void func_801B0090(void) {
    D_801C4618 = &D_801BC99C;
    func_801B0940();
}

void func_801B00C0(void) {
    D_801C4618 = &D_801BF240;
    func_801B0940();
}

void func_801B00F0(void) {
    D_801C4618 = &D_801C06A4;
    func_801B0940();
}

void func_801B0120(void) {
    D_801C4618 = &D_801C2050;
    func_801B0940();
}

void func_801B0150(void) {
    D_801C4618 = &D_801C36AC;
    func_801B0940();
}

void func_801B0180(void) {
    VgTask *p;
    s32 t;
    s32 i;
    s32 x;

    p = (VgTask *)&D_80162978[D_8015169C];
    if (p->unk2 == 0) {
        D_801C45D4 = 0x180;
        D_801C45DA = 0;
        D_801C45EA = 0;
        D_801C45D0 = (s32)D_801C4618;
    }
    func_8003BF8C(&p->unk14, &D_801C4610->m);
    D_801C4610->m.t[0] = D_801C4604[0] = p->unk4;
    D_801C4610->m.t[1] = p->unk6;
    D_801C4610->m.t[2] = D_801C460C = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801C4610->m, &D_801C4610->m);
    func_8003B48C(&D_801C4610->m);
    func_8003B51C(&D_801C4610->m);
    func_8003B69C(0, 0, 0);
    D_801E461C = func_800D29D4(&D_801C45D0, D_801517C0 + 0x70, 0xC, D_801E461C);
    D_801C4608 = 0;
    func_8003A63C(&D_800FA63C, (MgMat *)&D_801C4604[-5], &D_801C4610->m);
    func_8003B48C(&D_801C4610->m);
    func_8003B51C(&D_801C4610->m);
    D_801E461C = func_800D29D4(&D_801C45E0, D_801517C0 + 0x4078, 0, D_801E461C);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0xF) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unkE += p->unk1C;
        } else {
            t -= 0xF;
            if (t < 4) {
                if (t == 0) {
                    p->unkC = p->unkC / 4;
                    p->unkE = -0x3C;
                    p->unk10 = p->unk10 / 4;
                    i = 0;
                    do {
                        x = (i++ << 12) / 5 + func_80042DA8() % 819;
                        D_801C4610->v.vx = p->unk4 + ((func_80039A74(x) * 100) >> 12);
                        D_801C4610->v.vy = 0;
                        D_801C4610->v.vz = p->unk8 + ((func_80039B40(x) * 100) >> 12);
                        func_800D3F0C(D_801C4610, 0x1000, 0x1000);
                    } while (i < 5);
                    func_800D55F4(0x20, func_800D56A8(&p->unk4), 0xCC);
                }
                p->unk4 += p->unkC;
                p->unk6 += p->unkE;
                p->unk8 += p->unk10;
                p->unkE += 0x1E;
            } else {
                t -= 4;
                if (t < 0xA) {
                    if (t == 0) {
                        i = 0;
                        do {
                            x = (i++ << 12) / 5 + func_80042DA8() % 819;
                            D_801C4610->v.vx = p->unk4 + ((func_80039A74(x) * 100) >> 12);
                            D_801C4610->v.vy = 0;
                            D_801C4610->v.vz = p->unk8 + ((func_80039B40(x) * 100) >> 12);
                            func_800D3F0C(D_801C4610, 0x1000, 0x1000);
                        } while (i < 5);
                        p->unk6 = 0;
                    }
                } else {
                    t -= 0xA;
                    if (t < 0xA) {
                        if (t == 0) {
                            D_801C45D4 |= 8;
                        }
                        D_801C45DA = D_801C45EA = (t << 12) / 10;
                    } else {
                        func_800D5774(p->unk0);
                        p->unk0 = -1;
                        return;
                    }
                }
            }
        }
        p->unk2++;
    }
}

void func_801B06C4(s32 arg0, s32 arg1) {
    VgObj *p;

    p = (VgObj *)&D_80162978[func_800BBEAC(func_801B0180)];
    p->unk0 = arg0;
    func_800D3994(arg1, D_8015190F[arg1][0], D_801C4614);
    p->pos = D_801C4614->a;
    D_801C4614->bx = D_80151A4C[arg0].v - ((func_80039A74(D_80151A46[arg0].v) * (D_801518F6[arg0].v + 0x12C)) >> 12);
    D_801C4614->by = 0;
    D_801C4614->bz = D_80151A50[arg0].v - ((func_80039B40(D_80151A46[arg0].v) * (D_801518F6[arg0].v + 0x12C)) >> 12);
    p->unkC = (D_801C4614->bx - D_801C4614->a.vx) / 16;
    p->unkE = -200;
    p->unk10 = (D_801C4614->bz - D_801C4614->a.vz) / 16;
    p->unk1C = (0xAF0 - D_801C4614->a.vy) / 98; p->unk14 = p->unk16 = p->unk18 = 0;
}

void func_801B08E0(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E461C = D_801C461C + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0940(arg0, arg1) {
    func_800D2980(&D_801B09B0, 0, 0, 0);
    func_800BBEAC(&func_801B08E0);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B06C4);
}
