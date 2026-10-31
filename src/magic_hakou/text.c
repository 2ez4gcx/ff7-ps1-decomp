#include "common.h"
#include "magic_hakou/decls.h"

M2C_UNK *func_801B0010(void) {
    func_801B1B78();
    return &D_801B4EC0;
}

M2C_UNK *func_801B0038(void) {
    func_801B1C64();
    return &D_801B4EC0;
}

INCLUDE_RODATA("../asm/us/magic_hakou/nonmatchings/text", D_801B0000);

INCLUDE_RODATA("../asm/us/magic_hakou/nonmatchings/text", D_801B0008);

void func_801B0060(void) {
    MgSVec a;
    MgSVec b;
    MgSVec *off;
    MgTask *p;
    s16 *frame;
    s32 scale;

    a = D_801B0000;
    b = D_801B0008;
    off = (MgSVec *)0x1F800080;
    p = &D_80162978[D_8015169C];
    scale = p->unk6;
    *(s32 *)0x1F800078 = scale;
    *(s32 *)0x1F800074 = scale;
    *(s32 *)0x1F800070 = scale;
    func_800D44E8((MgSVec *)&p->unk10, (MgMat *)0x1F800000);
    off->vx = (s16)*(u16 *)0x1F80000C >> 6;
    off->vy = 0;
    off->vz = (s16)*(u16 *)0x1F800010 >> 6;
    func_8003C21C(&a, (MgMat *)0x1F800020);
    func_8003B16C((MgMat *)0x1F800000, (MgMat *)0x1F800020);
    ((MgMat *)0x1F800020)->t[0] = p->unk8 + off->vz;
    ((MgMat *)0x1F800020)->t[1] = p->unkA;
    ((MgMat *)0x1F800020)->t[2] = p->unkC + off->vx;
    func_8003A63C(&D_800FA63C, (MgMat *)0x1F800020, (MgMat *)0x1F800020);
    func_800D461C((MgMat *)0x1F800020);
    func_8003B35C((MgMat *)0x1F800020, (MgVec *)0x1F800070);
    func_8003B48C((MgMat *)0x1F800020);
    func_8003B51C((MgMat *)0x1F800020);
    frame = &D_801B5E2C;
    *frame = p->unk2 / 2;
    D_801D6778 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D6778);
    func_8003C21C(&b, (MgMat *)0x1F800020);
    func_8003B16C((MgMat *)0x1F800000, (MgMat *)0x1F800020);
    ((MgMat *)0x1F800020)->t[0] = p->unk8 - off->vz;
    ((MgMat *)0x1F800020)->t[1] = p->unkA;
    ((MgMat *)0x1F800020)->t[2] = p->unkC - off->vx;
    func_8003A63C(&D_800FA63C, (MgMat *)0x1F800020, (MgMat *)0x1F800020);
    func_800D461C((MgMat *)0x1F800020);
    func_8003B35C((MgMat *)0x1F800020, (MgVec *)0x1F800070);
    func_8003B48C((MgMat *)0x1F800020);
    func_8003B51C((MgMat *)0x1F800020);
    D_801D6778 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D6778);
    if (D_80062D98 == 0) {
        p->unk2 += 2;
        if (p->unk2 >= 10) {
            p->unk0 = -1;
        }
    }
}

void func_801B0378(void) {
    MgTask *p;
    s16 *frame;

    p = &D_801621F0[D_801590D4];
    func_8003C21C(&D_801B5E3C, (MgMat *)0x1F800000);
    func_8003B16C(*(MgMat **)&p->unk18, (MgMat *)0x1F800000);
    ((MgMat *)0x1F800000)->t[0] = p->unk8;
    ((MgMat *)0x1F800000)->t[1] = p->unkA;
    ((MgMat *)0x1F800000)->t[2] = p->unkC;
    func_8003A63C(&D_800FA63C, (MgMat *)0x1F800000, (MgMat *)0x1F800000);
    func_8003B48C((MgMat *)0x1F800000);
    func_8003B51C((MgMat *)0x1F800000);
    frame = &D_801B5E38;
    *frame = p->unk0;
    D_801D6778 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D6778);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 5) {
            p->unk0 = -1;
        }
    }
}

void func_801B0488(void) {
    MgTask *p;
    MgTask *q;
    MgMat *m0;
    s32 ang;
    s32 i;
    s32 t;
    s32 r;
    s32 u;
    u8 pad[16];

    m0 = (MgMat *)0x1F800000;
    p = &D_801621F0[D_801590D4];
    if (p->unk2 < 8) {
        ang = 0;
    } else {
        t = p->unk2 - 8;
        if (t < 4 && D_801B5FA4 <= 0) {
            /* dead test with identical arms: keeps ang in the game's saved register */
            if (p->unk12) {
                ang = t << 10;
            } else {
                ang = t << 10;
            }
        } else {
            p->unk0 = -1;
            return;
        }
    }
    (*(MgMat **)&p->unk18)->t[0] = p->unk8;
    (*(MgMat **)&p->unk18)->t[1] = p->unkA;
    (*(MgMat **)&p->unk18)->t[2] = p->unkC;
    func_8003A63C(&D_800FA63C, *(MgMat **)&p->unk18, m0);
    func_8003B48C(m0);
    func_8003B51C(m0);
    func_8003B69C(0, 0, 0);

    D_801B5E4E[0] = (ang >> 1) + 0x800;
    D_801D6778 = func_800D29D4((u8 *)D_801B5E4E - 0xA, D_801517C0 + 0x70, 0xC, D_801D6778);
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = &D_80162978[func_800BBEAC(&func_801B0060)];
            q->unk2 = i;
            q->unk8 = p->unk8 - p->unk10 * i / 2;
            q->unkA = 0;
            q->unkC = p->unkC - p->unk14 * i / 2;
            q->unk10 = -p->unk10;
            q->unk12 = 0;
            q->unk14 = -p->unk14;
            q->unk6 = func_80042DA8() % 0x800 + 0x1000;
            i++;
        } while (i < 2);
        if (p->unk2 > 0 && D_801B5FA4 > 0) {
            i = 0;
            do {
                i++;
                q = &D_801621F0[func_800BC04C(&func_801B0378)];
                q->unk0 = func_80042DA8() % 3;
                r = func_80042DA8() & 0xFFF;
                q->unk8 = p->unk8 - (p->unk10 * r >> 12);
                q->unkC = p->unkC - (p->unk14 * r >> 12);
                u = func_80042DA8() % 600 - 0x12C;
                q->unkA = p->unkA + u;
                q->unk2 = (u < 0 ? -u : u) / 60;
                *(s32 *)&q->unk18 = *(s32 *)&p->unk18;
            } while (i < 6);
        }
        p->unk2++;
        p->unk8 += p->unk10;
        p->unkA += p->unk12;
        p->unkC += p->unk14;
    }
}

INCLUDE_ASM("../asm/us/magic_hakou/nonmatchings/text", func_801B0820);

void func_801B0A70(void) {
    MgTask *p;
    u8 col[3];
    s32 i;

    p = &D_801621F0[D_801590D4];
    col[0] = col[1] = col[2] = p->unk2 * -0xFF / 10 - 1;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    for (i = 0; i < 100; i++) {
        func_801B0820(&D_801B5FA8[i], col);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 10) {
            p->unk0 = -1;
        }
    }
}

void func_801B0B74(void) {
    MgTask *p;
    s32 k;
    s32 c;
    s32 a;

    p = &D_801621F0[D_801590D4];
    k = p->unk2;
    a = k << 11;
    if (k < 0) {
        c = 0x80;
        goto store;
    }
    if (k < 8) {
        c = -(k << 7) / 8 - 0x80;
store:
        D_801B5E58 = D_801B5E59 = D_801B5E5A = c;
    } else {
        p->unk0 = -1;
        return;
    }
    func_800D4368(&p->unk8, (s16)a, 0);
    D_801D6778 = func_800D4D90(&D_801B5E54, D_801517C0 + 0x70, 0xC, D_801D6778);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0C70(void) {
    MgTask *p;
    MgTask *q;

    p = &D_801621F0[D_801590D4];
    if (D_80062D98 == 0) {
        if ((p->unk2 & 1) == 0) {
            q = &D_801621F0[func_800BC04C(&func_801B0B74)];
            *(HkB8 *)&q->unk8 = *(HkB8 *)&p->unk8;
        }
        p->unk2++;
        if (p->unk2 >= 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B0D30(HkPart *arg0, u8 *arg1) {
    s16 *frame;

    frame = &D_801B5E68;
    *frame = arg0->unk0;
    D_801B5E64.v = arg1[0];
    D_801B5E65.v = arg1[1];
    D_801B5E66.v = arg1[2];
    func_800D4368(&arg0->unk4, arg0->unk2, 0);
    D_801D6778 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D6778);
    if (D_80062D98 == 0) {
        arg0->unk4 += arg0->unkC;
        arg0->unk6 += arg0->unkE;
        arg0->unk8 += arg0->unk10;
        arg0->unkC -= arg0->unkC >> 2;
        arg0->unkE -= arg0->unkE >> 2;
        arg0->unk10 -= arg0->unk10 >> 2;
    }
}

void func_801B0E4C(void) {
    MgTask *p;
    u8 col[3];
    s32 i;

    p = &D_801621F0[D_801590D4];
    col[0] = col[1] = col[2] = p->unk2 * -0x80 / 15 - 0x80;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    for (i = 0; i < 50; i++) {
        func_801B0D30(&D_801B5FA8[i], col);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 15) {
            p->unk0 = -1;
        }
    }
}

void func_801B0F54(void) {
    MgTask *p;
    s16 *frame;

    p = &D_801621F0[D_801590D4];
    func_8003C21C((MgSVec *)&p->unk10, D_801B5E88);
    D_801B5E88->t[0] = p->unk8;
    D_801B5E88->t[1] = p->unkA;
    D_801B5E88->t[2] = p->unkC;
    func_8003A63C(&D_800FA63C, D_801B5E88, D_801B5E88);
    func_800D461C(D_801B5E88);
    func_8003B35C(D_801B5E88, &D_801B5E78);
    func_8003B48C(D_801B5E88);
    func_8003B51C(D_801B5E88);
    frame = &D_801B5E74;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B4D6C[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B1090(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 ang;

    p = &D_801621F0[D_801590D4];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = &D_801621F0[func_800BC04C(func_801B0F54)];
            ang = p->unk12 + (i << 10);
            q->unk8 = p->unk8 + (func_80039B40(ang) * 200 >> 12);
            q->unkA = 0;
            q->unkC = p->unkC - (func_80039A74(ang) * 200 >> 12);
            q->unk10 = 0;
            q->unk14 = 0x200;
            q->unk12 = ang;
            i++;
        } while (i < 4);
        p->unk2++;
        if (p->unk2 >= 0x19) {
            p->unk0 = -1;
        } else {
            p->unk12 += 0x147;
        }
    }
}

void func_801B11D0(void) {
    MgTask *p;
    MgTask *q;
    HkPart *e;
    MgSVec *ang;
    MgSVec *sv;
    MgMat *m;
    u8 pad[8];
    MgSVec v;
    s32 i;

    ang = (MgSVec *)0x1F800008;
    m = (MgMat *)0x1F800010;
    p = &D_801621F0[D_801590D4];
    sv = (MgSVec *)0x1F800000;
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &D_801621F0[func_800BC04C(&func_801B0488)];
            func_800D3994(((u8 *)p)[5], D_8015190F[((u8 *)p)[5]][0], &q->unk8);
            func_800D3994(((u8 *)p)[4], D_8015190F[((u8 *)p)[4]][0], &D_801B5E8C);
            D_801D677C = *(HkB8 *)&D_801B5E8C;
            q->unk10 = (D_801B5E8C.vx - q->unk8) / 8;
            q->unk12 = (D_801B5E8C.vy - q->unkA) / 8;
            q->unk14 = (D_801B5E8C.vz - q->unkC) / 8;
            v.vx = -q->unk10;
            v.vy = -q->unk12;
            v.vz = -q->unk14;
            func_800D44E8(&v, D_801B5F9C);
            *(MgMat **)&q->unk18 = D_801B5F9C++;
        }
        if (p->unk2 == 8) {
            if (D_80163A98 == 0) {
                i = 0;
                do {
                    e = &D_801B5FA8[i];
                    e->unk0 = (func_80042DA8() & 1) + 1;
                    e->unk2 = func_80042DA8() % 0x1000 + 0x2000;
                    *(HkB8 *)&e->unk4 = *(HkB8 *)&D_801B5E8C;
                    sv->vx = 0;
                    sv->vy = 0;
                    sv->vz = func_80042DA8() % 600 + 200;
                    ang->vx = func_80042DA8() % 0x900 - 0x80;
                    ang->vy = func_80042DA8() & 0xFFF;
                    ang->vz = 0;
                    func_8003C21C(ang, m);
                    func_8003B2CC(m, sv, (MgSVec *)&e->unkC);
                    i++;
                } while (i < 50);
                func_800BC04C(&func_801B0E4C);
                q = &D_801621F0[func_800BC04C(&func_801B0C70)];
                func_800D3994(((u8 *)p)[4], D_8015190F[((u8 *)p)[4]][0], &q->unk8);
            } else {
                i = 0;
                do {
                    e = &D_801B5FA8[i];
                    *(HkB8 *)&e->unk4 = *(HkB8 *)&D_801B5E8C;
                    e->unk0 = 0;
                    e->unk2 = 0;
                    sv->vx = 0;
                    sv->vy = 0;
                    sv->vz = func_80042DA8() % 600 + 200;
                    ang->vx = func_80042DA8() % 0x900 - 0x80;
                    ang->vy = func_80042DA8() & 0xFFF;
                    ang->vz = 0;
                    func_8003C21C(ang, m);
                    func_8003B2CC(m, sv, (MgSVec *)&e->unkC);
                    i++;
                } while (i < 100);
                func_800BC04C(&func_801B0A70);
                func_800D3994(((u8 *)p)[4], D_8015190F[((u8 *)p)[4]][0], sv);
                q = &D_801621F0[func_800BC04C(&func_801B0C70)];
                *(HkB8 *)&q->unk8 = *(HkB8 *)sv;
            }
        }
        if (p->unk2 == 8) {
            func_800D5774(((u8 *)p)[4]);
            func_800D55F4(0x20, func_800D56A8(D_80151A4C[((u8 *)p)[4]]), 0x1B);
        }
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B17D8(void) {
    MgTask *p;
    MgTask *q;
    u8 pad[8];
    MgSVec v;

    p = &D_801621F0[D_801590D4];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &D_801621F0[func_800BC04C(&func_801B0488)];
            *(HkB8 *)&q->unk8 = D_801D677C;
            func_800D3994(((u8 *)p)[4], D_8015190F[((u8 *)p)[4]][0], &D_801B5E94);
            q->unk10 = (D_801B5E94.vx - q->unk8) / 8;
            q->unk12 = (D_801B5E94.vy - q->unkA) / 8;
            q->unk14 = (D_801B5E94.vz - q->unkC) / 8;
            v.vx = -q->unk10;
            v.vy = -q->unk12;
            v.vz = -q->unk14;
            func_800D44E8(&v, D_801B5F9C);
            *(MgMat **)&q->unk18 = D_801B5F9C++;
        }
        if (p->unk2 == 8) {
            func_800D5774(((u8 *)p)[4]);
        }
        if (p->unk2 == 0x14) {
            D_801B4EBC = 1;
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B19CC(void) {
    MgTask *p;
    MgTask *q;

    p = &D_801621F0[D_801590D4];
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x1E) {
            q = &D_801621F0[func_800BC04C(&func_801B11D0)];
            ((u8 *)q)[4] = ((u8 *)p)[4];
            ((u8 *)q)[5] = ((u8 *)p)[5];
            p->unk0 = -1;
            func_800D55F4(0x20, func_800D56A8(D_80151A4C[((u8 *)p)[5]]), 0x173);
        }
    }
}

void func_801B1AAC(s32 arg0) {
    MgTask *p;

    p = &D_801621F0[func_800BC04C(&func_801B17D8)];
    *(u8 *)((u8 *)p + 4) = arg0;
    *(u8 *)((u8 *)p + 5) = D_801B4EB4;
}

void func_801B1B04(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    D_801D6778 = (p->unk2 << 16) + (s32)&D_801B6778;
    p->unk2 ^= 1;
    if (D_801B4EBC == 1 && D_80162080 == 0) {
        p->unk0 = -1;
    }
}

void func_801B1B78(arg0, arg1) {
    MgTask *p;
    s32 i;

    func_800D2980(&D_801B1D24, 0, 0, 0);
    i = 0;
    D_801B4EB8 = &D_801621F0[func_800BC04C(&func_801B1B04)];
    D_801B4EBC = 0;
    D_801B5FA4 = 1;
    for (; i < 10; i++) {
        if (arg0 >> i & 1) {
            break;
        }
    }
    D_801B4EB4 = i;
    p = &D_801621F0[func_800BC04C(&func_801B19CC)];
    ((u8 *)p)[4] = i;
    ((u8 *)p)[5] = arg1;
    D_801B5F9C = &D_801B5E9C;
}

void func_801B1C64(arg0, arg1) {
    if ((arg0 >> arg1) & 1) {
        D_801B4EBC = 1;
    } else {
        D_801B5FA4 = 0;
        D_801B5F9C = &D_801B5E9C;
        D_801B5FA0 = arg0;
        func_800D5444(arg0, D_801B4EB4, 0, &func_801B1AAC);
        func_800D55F4(0x20, func_800D56A8(D_80151A4C[D_801B4EB4]), 0x1A3);
        func_8001C3C4();
    }
}
