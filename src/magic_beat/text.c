#include "common.h"
#include "magic_beat/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0DAC();
    return &D_801BB764;
}

void func_801B0028(void) {
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xF) {
        if (t == 0) {
            func_800D52A0(0x800, 0xF);
        }
        D_801BD50E = t * -0x800 / 15 + 0x1000;
    } else {
        t -= 0xF;
        if (t < 0x19) {
            D_801BD50E = 0x800;
        } else {
            t -= 0x19;
            if (t < 0xF) {
                if (t == 0) {
                    func_800D52A0(0, 0xF);
                }
                D_801BD50E = t * 0x800 / 15 + 0x800;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    func_800D4368(&p->unk4, 0x800, p->unk16);
    func_8003B69C(0, 0, 0);
    D_801DD540 = func_800D29D4(&D_801BD504, D_801517C0 + 0x70, 0xC, D_801DD540);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B01BC(void) {
    MgTask *p;
    s32 t;
    s32 s;
    u8 c;
    s32 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        c = (t << 7) / 5;
        D_801BD51A.v = c;
        D_801BD519.v = c;
        D_801BD518.v = c;
        s = p->unk14;
    } else {
        t -= 5;
        if (t < 0x14) {
            s = p->unk14;
            *(s32 *)&D_801BD518 = 0x2E808080;
        } else {
            t -= 0x14;
            if (t < 5) {
                c = -(t << 7) / 5 - 0x80;
                D_801BD51A.v = c;
                D_801BD519.v = c;
                D_801BD518.v = c;
                a = p->unk14;
                s = a + -a * t / 5;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801BD520->rot.vx = 0;
    D_801BD520->rot.vy = 0;
    D_801BD520->rot.vz = p->unk10;
    func_8003C21C(&D_801BD520->rot, &D_801BD520->m);
    D_801BD520->sc.vz = s;
    D_801BD520->sc.vy = s;
    D_801BD520->sc.vx = s;
    func_8003B35C(&D_801BD520->m, &D_801BD520->sc);
    func_800D4284(&p->unk4, p->unk16, &D_801BD520->m);
    func_8003B48C(&D_801BD520->m);
    func_8003B51C(&D_801BD520->m);
    D_801DD540 = func_800D4D90(&D_801BD514, D_801517C0 + 0x70, 0xC, D_801DD540);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x19) {
            p->unk6 += 0x4B;
            p->unk10 += 0x80;
        }
        p->unk2++;
    }
}

void func_801B03F0(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B01BC)];
            q->unk0 = 10 - p->unk2;
            func_800D3994(p->unk0, func_80042DA8() % D_801518F4[p->unk0][0], &q->unk4);
            k = 0x64;
            q->unk4 = q->unk4 - k + func_80042DA8() % 200;
            k = 0x7B7;
            q->unk6 = q->unk6 - k + func_80042DA8() % 200;
            k = 0x64;
            q->unk8 = q->unk8 - k + func_80042DA8() % 200;
            q->unk10 = func_80042DA8() & 0xFFF;
            q->unk14 = func_80042DA8() % 0x400 + 0x400;
            q->unk16 = p->unk16;
            i++;
        } while (i <= 0);
        p->unk2++;
        if (p->unk2 >= 10) {
            p->unk0 = -1;
        }
    }
}

void func_801B0624(void) {
    MgTask *p;
    s16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, -0x100);
    frame = &D_801BD52C;
    *frame = p->unk2 / 2;
    D_801DD540 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801DD540);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 / 2 >= D_801BB418) {
            p->unk0 = -1;
        } else {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unkC = p->unkC * 3 >> 2;
            p->unkE = (p->unkE * 7 >> 3) + 0x1E;
            p->unk10 = p->unk10 * 3 >> 2;
        }
    }
}

void func_801B0778(void) {
    MgTask *p;
    u8 *t;
    u8 **q;
    s16 *h;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk14, p->unk16);
    q = &D_801BD530;
    t = D_801BB66C;
    if (p->unk0 == 0) {
        t = D_801BB574;
    }
    *q = t;
    D_801BD538 = p->unk2;
    D_801DD540 = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_801DD540);
    if (D_80062D98 == 0) {
        h = &p->unk2;
        *h += 1;
        if (*h >= D_801BD530[4]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0858(void) {
    MgTask *p;
    MgTask *q;
    s16 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0778)];
        q->unk0 = p->unk2 & 1;
        q->unk4 = p->unk4 + (func_80039A74(p->unkE) * p->unk16 >> 12);
        q->unk6 = p->unk6 + func_80042DA8() % 100 - 0x32;
        q->unk8 = p->unk8 + (func_80039B40(p->unkE) * p->unk16 >> 12);
        k = func_80042DA8() % 0x1000 + 0x1000;
        q->unk14 = k;
        q->unk16 = -(k * 0x10) >> 9;
        p->unk6 -= 0x28;
        p->unkE += 0x280;
        p->unk2++;
        if (p->unk2 >= 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B09E0(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s32 i;

    b = (MgTask *)D_80162978;
    p = &b[D_8015169C];
    if (D_80062D98 == 0) {
        i = p->unk2;
        if (i == 0x38) {
            q = &b[func_800BBEAC((M2C_UNK *)func_801B0028)];
            q->unk4 = p->unk4;
            q->unk6 = 0;
            q->unk8 = p->unk8;
            q->unk16 = p->unk16;
            if (p->unk2 == i) {
                q = &b[func_800BBEAC((M2C_UNK *)func_801B03F0)];
                q->unk0 = p->unk0;
                q->unk16 = p->unk16;
            }
        }
        if (p->unk2 == 0x61) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0624)];
                *(BtB8 *)&q->unk4 = *(BtB8 *)&p->unk4;
                D_801BD53C->v.vx = 0;
                D_801BD53C->v.vy = func_80042DA8() & 0xFFF;
                D_801BD53C->v.vz = -(func_80042DA8() % 0x100 + 0x200);
                func_8003C21C(&D_801BD53C->v, &D_801BD53C->m);
                i++;
                D_801BD53C->v.vx = func_80042DA8() % 200 + 0x12C;
                D_801BD53C->v.vy = 0;
                D_801BD53C->v.vz = 0;
                func_8003B2CC(&D_801BD53C->m, &D_801BD53C->v, (MgSVec *)&q->unkC);
            } while (i < 0x14);
            func_800D5774(p->unk0);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0C00(s32 arg0) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B09E0)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    p->unk16 = -D_801518F6[arg0][0];
}

void func_801B0CA0(void) {
    MgObj20 *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t == 5) {
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x15);
        } else if (t == 0x38) {
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x11E);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0D4C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DD540 = D_801BD540 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B0DAC(arg0, arg1) {
    func_800D2980(&D_801B0E70, 0, 0, 0);
    func_800BBEAC((M2C_UNK *)func_801B0D4C);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)func_801B0C00);
    return func_800D3994(arg1, D_8015190F[arg1][0], (void *)((func_800BBEAC((M2C_UNK *)func_801B0CA0) << 5) + (s32)&D_8016297C));
}
