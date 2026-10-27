#include "common.h"
#include "magic_flame/decls.h"

void func_801B0000(s32 arg0) {
    D_801DD870 = 0;
    func_801B1014();
    func_800D55F4(0x20, func_800D574C(arg0), 0x1DE);
}

void func_801B0048(void) {
    D_801DD870 = 1;
    func_801B1014(D_80151774);
    func_800D55F4(0x20, func_800D574C((s32) D_80151774), 0x1FA);
}

void func_801B009C(void) {
    D_801DD870 = 1;
    ((void (*)(s32))func_801B1084)((s32) D_80151774);
    func_800D55F4(0x20, func_800D574C((s32) D_80151774), 0x1FA);
}

void func_801B00F0(s32 arg0) {
    D_801DD870 = 0;
    func_801B10F4();
    func_800D55F4(0x20, func_800D574C(arg0), 0x1DE);
}

void func_801B0138(void) {
    D_801DD870 = 1;
    func_801B10F4();
}

void func_801B0164(s32 arg0) {
    D_801DD870 = 2;
    func_801B10F4();
    ((void (*)(s32, s32, s32, s32))func_800D55F4)(0x21, func_800D574C(arg0), 0x1DE, 0x1FA);
}

void func_801B01B4(s32 arg0) {
    D_801DD870 = 0;
    func_801B1220();
    func_800D55F4(0x20, func_800D574C(arg0), 0x1DE);
}

void func_801B01FC(MgTask *p) {
    s32 d;
    s16 *frame;

    d = func_80039A74(p->unk1A * p->unk2 / 20);
    D_801BD848->vx = p->unk4 + (p->unkC * d >> 12);
    D_801BD848->vy = p->unk6 + (p->unkE * d >> 12) + p->unk14;
    D_801BD848->vz = p->unk8 + (p->unk10 * d >> 12);
    frame = &D_801BD844;
    *frame = (p->unk2 * 10 / p->unk1E) | 0x8000;
    D_801BD846 = p->unk1C;
    func_800D4368(D_801BD848, 0x1800, -0x180);
    D_801DD868 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801DD868);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= p->unk1E) {
            p->unk0 = -1;
        } else {
            p->unk14 += p->unk16;
            p->unk16 += p->unk18;
        }
    }
}

void func_801B03C0(void) {
    MgObj20 *p;
    s32 i;
    s32 off;
    s32 n;

    n = 0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 200; i++) {
        off = i * 0x20;
        if (*(s16 *)(&D_801DD874 + off) != -1) {
            func_801B01FC(&D_801DD874 + off);
            n++;
        }
    }
    if (n == 0 && D_80162080 < 3) {
        p->unk0 = -1;
    }
}

void func_801B0484(void) {
    s32 off;
    s16 c;

    c = -1;
    off = 0x18E0;
    do {
        *(s16 *)(&D_801DD874 + off) = c;
        off -= 0x20;
    } while (off >= 0);
}

MgObj20 *func_801B04B0(void) {
    s32 i;
    s32 off;

    for (i = 0; i < 200; i++) {
        off = i * 0x20;
        if (*(s16 *)(&D_801DD874 + off) == -1) {
            *(s16 *)(&D_801DD874 + off) = 0;
            *(s16 *)(&D_801DD874 + 2 + off) = 0;
            return (MgObj20 *)(&D_801DD874 + off);
        }
    }
    return NULL;
}

void func_801B0514(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    MgTask *q;
    s32 i;
    s32 d;
    s32 t;
    s32 r;
    s32 m;
    s32 v;

    for (i = 0; i < arg3; i++) {
        q = (MgTask *)func_801B04B0();
        q->unk1E = func_80042DA8() % 15 + 10;
        q->unk4 = ((FlSVec *)arg0)->vx + (func_80042DA8() % 200 - 0x64);
        q->unk6 = ((FlSVec *)arg0)->vy + (func_80042DA8() % 200 - 0x64);
        q->unk8 = ((FlSVec *)arg0)->vz + (func_80042DA8() % 200 - 0x64);
        d = func_80039A74((arg2 << 12) / 6);
        r = func_80042DA8();
        m = r;
        d <<= 10;
        d >>= 12;
        if (m < 0) {
            m += 0x3FF;
        }
        t = r - (m >> 10 << 10) + 0xE00;
        v = d + t;
        q->unkC = ((FlSVec *)arg1)->vx * v >> 12;
        q->unkE = ((FlSVec *)arg1)->vy * v >> 12;
        q->unk10 = ((FlSVec *)arg1)->vz * v >> 12;
        q->unk14 = 0;
        q->unk16 = 0x4B;
        q->unk18 = -(func_80042DA8() % 15 + 5);
        q->unk1A = func_80042DA8() % 384 + 0x440;
        switch (D_801DD870) {
        case 0:
            q->unk1C = 0;
            break;
        case 1:
            q->unk1C = 0x40;
            break;
        case 2:
            q->unk1C = D_801BD84C;
            break;
        }
    }
    D_801BD84C ^= 0x40;
}

void func_801B082C(void) {
    MgTask *p;
    u16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_801B0484();
            func_800BBEAC(func_801B03C0);
        }
        n = p->unk2;
        if (n < 0x12U) {
            func_801B0514(&p->unk4, &p->unkC, (s16)n, 4);
        }
        if (p->unk2 == 0x1E) {
            func_800D5774(p->unk0);
            if (p->unk2 == 0x1E) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0908(void) {
    MgTask *p;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_801B0484();
            func_800BBEAC(func_801B03C0);
        }
        if ((u16)p->unk2 < 0x12U) {
            D_801BD850->rot.vx = 0;
            D_801BD850->rot.vy = p->unk14;
            D_801BD850->rot.vz = 0;
            func_8003C21C(&D_801BD850->rot, &D_801BD850->m);
            func_8003B2CC(&D_801BD850->m, (FlSVec *)&p->unkC, &D_801BD850->rot);
            func_800D3994(p->unk0, D_80151917[p->unk0][0], &D_801BD850->pos);
            func_801B0514(&D_801BD850->pos, &D_801BD850->rot, p->unk2, 4);
            D_801BD850->rot.vx = 0;
            D_801BD850->rot.vy = -p->unk14;
            D_801BD850->rot.vz = 0;
            func_8003C21C(&D_801BD850->rot, &D_801BD850->m);
            func_8003B2CC(&D_801BD850->m, (FlSVec *)&p->unkC, &D_801BD850->rot);
            func_800D3994(p->unk0, D_80151918[p->unk0][0], &D_801BD850->pos);
            func_801B0514(&D_801BD850->pos, &D_801BD850->rot, p->unk2, 4);
            p->unk14 += p->unk16;
        }
        if (p->unk2 == 0x1E) {
            for (i = 0; i < 10; i++) {
                if ((D_801DD86C >> i) & 1) {
                    func_800D5774(i);
                }
            }
            if (p->unk2 == 0x1E) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0B38(void) {
    MgTask *p;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_801B0484();
            func_800BBEAC(func_801B03C0);
        }
        if ((u16)p->unk2 < 0x12U) {
            func_800D41FC(&D_800FA63C, D_80151AC0[p->unk0], &D_801BD864->m);
            func_8003B48C(&D_801BD864->m);
            func_8003B51C(&D_801BD864->m);
            func_8003BC6C(&D_801BD854, &D_801BD864->v1, &D_801BD864->flag);
            func_8003BC6C(&D_801BD85C, &D_801BD864->v2, &D_801BD864->flag);
            D_801BD864->rot.vx = 0;
            D_801BD864->rot.vy = p->unk14;
            D_801BD864->rot.vz = 0;
            func_8003C21C(&D_801BD864->rot, &D_801BD864->m);
            func_8003B2CC(&D_801BD864->m, (FlSVec *)&p->unkC, &D_801BD864->rot);
            D_801BD864->pos.vx = D_801BD864->v1.vx;
            D_801BD864->pos.vy = D_801BD864->v1.vy;
            D_801BD864->pos.vz = D_801BD864->v1.vz;
            func_801B0514(&D_801BD864->pos, &D_801BD864->rot, p->unk2, 4);
            D_801BD864->rot.vx = 0;
            D_801BD864->rot.vy = -p->unk14;
            D_801BD864->rot.vz = 0;
            func_8003C21C(&D_801BD864->rot, &D_801BD864->m);
            func_8003B2CC(&D_801BD864->m, (FlSVec *)&p->unkC, &D_801BD864->rot);
            D_801BD864->pos.vx = D_801BD864->v2.vx;
            D_801BD864->pos.vy = D_801BD864->v2.vy;
            D_801BD864->pos.vz = D_801BD864->v2.vz;
            func_801B0514(&D_801BD864->pos, &D_801BD864->rot, p->unk2, 4);
            p->unk14 += p->unk16;
        }
        if (p->unk2 == 0x1E) {
            for (i = 0; i < 10; i++) {
                if ((D_801DD86C >> i) & 1) {
                    func_800D5774(i);
                }
            }
            if (p->unk2 == 0x1E) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0DBC(s32 arg0, s32 arg1) {
    MgTask *p;
    MgSVec v;
    u8 pad[8];

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B082C)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &v);
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    p->unkC = v.vx - p->unk4;
    p->unkE = v.vy - p->unk6;
    p->unk10 = v.vz - p->unk8;
}

void func_801B0EB8(s32 arg0, s32 arg1) {
    MgTask *p;
    MgSVec v;
    u8 pad[8];

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B082C)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &v);
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    p->unkC = v.vx - p->unk4;
    p->unkE = v.vy - p->unk6;
    p->unk10 = v.vz - p->unk8;
}

void func_801B0FB4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DD868 = D_801BD868 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B1014(arg0, arg1) {
    func_800D2980(&D_801B134C, 0, 0, 0);
    func_800BBEAC(&func_801B0FB4);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B0DBC);
}

void func_801B1084(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B134C, 0, 0, 0);
    func_800BBEAC(&func_801B0FB4);
    func_800D5444(arg0, arg1, 0, &func_801B0EB8);
}

void func_801B10F4(arg0, arg1) {
    MgSVec v;
    MgSVec w;
    MgTask *p;

    func_800D2980(&D_801B134C, 0, 0, 0);
    func_800BBEAC(func_801B0FB4);
    D_801DD86C = arg0;
    func_800D54EC(arg0, &v);
    v.vy = -0x1F4;
    func_800D3994(arg1, D_8015190F[arg1][0], &w);
    v.vx -= w.vx;
    v.vy -= w.vy;
    v.vz -= w.vz;
    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B0908)];
    p->unk0 = arg1;
    *(MgSVec *)&p->unkC = v;
    p->unk14 = 0x200;
    p->unk16 = -0x38;
}

void func_801B1220(arg0, arg1) {
    MgSVec v;
    MgSVec w;
    MgTask *p;

    func_800D2980(&D_801B134C, 0, 0, 0);
    func_800BBEAC(func_801B0FB4);
    D_801DD86C = arg0;
    func_800D54EC(arg0, &v);
    v.vy = -0x1F4;
    func_800D3994(arg1, D_8015190F[arg1][0], &w);
    v.vx -= w.vx;
    v.vy -= w.vy;
    v.vz -= w.vz;
    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B0B38)];
    p->unk0 = arg1;
    *(MgSVec *)&p->unkC = v;
    p->unk14 = 0x200;
    p->unk16 = -0x38;
}
