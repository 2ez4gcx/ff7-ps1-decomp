#include "common.h"
#include "magic_wlaser/decls.h"

void func_801B0000(void) {
    func_801B083C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E0E68 = D_801C8E68 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801C8E3C.unk0 = D_801C8E48[p->unk16];
    D_801C8E3C.unk8 = p->unk2;
    D_80163C74 = func_800D4D90(&D_801C8E3C, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801C8E48[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0180(void) {
    MgMat m;
    MgMat b;
    MgMat lw;
    MgSVec d;
    MgVec scale;
    MgTask *p;
    s16 *frame;
    s16 len;

    p = (MgTask *)&D_80162978[D_8015169C];
    d.vx = p->unkC - p->unk4;
    d.vy = p->unkE - p->unk6;
    d.vz = p->unk10 - p->unk8;
    len = func_80039F5C(d.vx * d.vx + d.vy * d.vy + d.vz * d.vz);
    func_800D44E8(&d, &m);
    func_8003BF8C(D_801C8E60, &b);
    func_8003A79C(&m, &b, &b);
    scale.vy = scale.vz = 0x4000;
    scale.vx = (len << 12) / 2000;
    func_8003B35C(&b, &scale);
    b.t[0] = p->unk4;
    b.t[1] = p->unk6;
    b.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &b, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801C8E5C;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801C893C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0364(void) {
    MgTask *p;
    MgTask *q;
    MgMat um;
    MgSVec us;
    MgSVec us2;
    s16 i;
    s32 j;
    u8 *row;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            i = 6;
loop:
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0180)];
            j = i;
            row = D_8015190F[p->unk1E];
            func_800D3994(p->unk1E, row[j], &q->unk4);
            q->unkC = p->unkC;
            q->unkE = p->unkE;
            q->unk10 = p->unk10;
            if (++i < 8) {
                goto loop;
            }
        }
        if ((u32)((u16)p->unk2 - 4) < 4) {
            q = &D_801621F0[func_800BC04C(func_801B008C)];
            q->unk4 = p->unkC + func_80042DA8() % 800 - 400;
            q->unk6 = p->unkE + func_80042DA8() % 800 - 400;
            q->unk8 = p->unk10 + func_80042DA8() % 800 - 400;
            q->unk16 = 0;
        }
        if ((u32)((u16)p->unk2 - 8) < 8) {
            q = &D_801621F0[func_800BC04C(func_801B008C)];
            q->unk4 = p->unkC + func_80042DA8() % 1200 - 600;
            q->unk6 = p->unkE + func_80042DA8() % 1200 - 600;
            q->unk8 = p->unk10 + func_80042DA8() % 1200 - 600;
            q->unk16 = 1;
            q = &D_801621F0[func_800BC04C(func_801B008C)];
            q->unk4 = p->unkC + func_80042DA8() % 1200 - 600;
            q->unk6 = p->unkE + func_80042DA8() % 1200 - 600;
            q->unk8 = p->unk10 + func_80042DA8() % 1200 - 600;
            q->unk16 = 2;
        }
        if (p->unk2 == 0xA) {
            func_800D5774(p->unk1C);
            func_800BBA84(0xFA, p->unk1C, 0);
        }
        p->unk2++;
        if (p->unk2 == 0x23) {
            p->unk0 = -1;
        }
    }
}

void func_801B07A8(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC((void *)func_801B0364)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    p->unk1E = arg1;
}

s32 func_801B083C(arg0, arg1) {
    func_800BBEAC(func_801B0020);
    func_800D2980(&D_801B08B8, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, (M2C_UNK *)func_801B07A8);
    return func_800BBA84(0x3A, arg1, 0);
}
