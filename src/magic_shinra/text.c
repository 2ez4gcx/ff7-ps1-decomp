#include "common.h"
#include "magic_shinra/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0950();
    return &D_801BAD68;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CC8C0 = D_801BC8C0 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0088(void) {
    MgMat m;
    MgMat m2;
    MgVec scale;
    MgTask *p;
    s16 *q;

    p = &D_80162978[D_8015169C];
    func_8003BF8C(&D_801BC878, &m);
    scale.vx = scale.vy = scale.vz = 0x6000 - p->unk2 * 0x4B0;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    func_8003B69C(0, 0, 0);
    q = &D_801BC88A;
    *q = 0x1000 - p->unk2 * 0xC8;
    D_801CC8C0 = func_800D29D4(q - 5, D_801517C0 + 0x70, 0xC, D_801CC8C0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B01E8(void) {
    MgMat m;
    MgMat m2;
    MgTask *p;
    s16 *q;
    s32 *sc;
    s16 *q3;
    s32 *fl;
    MgSVec *a;
    MgSVec *b;
    MgSVec *d;
    MgSVec *sa;
    MgSVec *sb;
    MgSVec *sd;
    u16 t;
    s16 k;
    s16 i;
    s32 v;

    p = &D_80162978[D_8015169C];
    q = &D_801BC8A6;
    v = p->unk2;
    *q = v << 6;
    func_8003BF8C((MgSVec *)(q - 1), &m);
    func_8003C8DC(p->unk14, &m);
    sc = &D_801BC894;
    func_8003B35C(&m, (MgVec *)sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    func_8003B69C(0, 0, 0);
    q3 = &D_801BC8B6;
    *q3 = D_801BC890;
    D_801CC8C0 = func_800D29D4(q3 - 5, D_801517C0 + 0x70, 0xC, D_801CC8C0);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x28) {
            *sc = D_801BC898 = D_801BC89C = (func_80039A74(p->unk2 * 0x19) * 0xE10) >> 12;
        }
        t = p->unk2;
        if ((u32)(t - 0x2D) < 0x19) {
            k = (s16)t - 0x2D;
            if (k < 4) {
                a = D_801BA5C8;
                b = D_801BA998;
                d = D_801B9048;
                for (i = 0; i < 0x7A; i++) {
                    sa = &a[i];
                    sb = &b[i];
                    sd = &d[i];
                    sd->vx = sa->vx + (sb->vx - sa->vx) * k / 4;
                    sd->vy = sa->vy + (sb->vy - sa->vy) * k / 4;
                    sd->vz = sa->vz + (sb->vz - sa->vz) * k / 4;
                }
            } else {
                D_801BC898 += 0x320;
            }
        }
        if (p->unk2 >= 0x46) {
            v = D_801BC89C - 0xB4;
            D_801BC89C = v;
            D_801BC894 = v;
        }
        if (p->unk2 == 0x50) {
            fl = &D_801BC8B0;
            *fl |= 8;
        }
        p->unk2++;
        if (p->unk2 == 0x5A) {
            p->unk0 = -1;
        }
    }
}

void func_801B0504(void) {
    MgTask *p;
    s16 a;
    s16 b;

    a = D_801BC8BC + D_801BC8BE;
    b = a;
    p = &D_80162978[D_8015169C];
    if (a >= 0xF1) {
        b = 0xF0;
    }
    D_80163C74 = func_800C4FC8(b, D_801BC8BE, D_801BC8BE);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x1E) {
            D_801BC8BE -= 8;
        }
        if ((u32)((u16)p->unk2 - 0x1E) < 0xA) {
            D_801BC8BE += 0x18;
        }
        if (p->unk2 >= 0x37) {
            D_801BC8BE -= 8;
        }
        if ((s16)D_801BC8BC > 0) {
            D_801BC8BC = (s16)D_801BC8BC - 6;
        }
        p->unk2++;
        if (p->unk2 == 0x56) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_shinra/nonmatchings/text", func_801B0664);

void func_801B0950(arg0, arg1) {
    func_800BBEAC(func_801B0028);
    func_800D2980(&D_801B09F0, 0, 0, 0);
    D_801CC8C4 = arg0;
    func_800D54EC(arg0, &D_801CC8C8);
    D_80162978[func_800BBEAC(func_801B0664)].unk1E = arg1;
    D_800FAFDC = 1;
}
