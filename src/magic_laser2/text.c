#include "common.h"
#include "magic_laser2/decls.h"

void func_801B0010(void) {
    func_801B0E20();
}

void func_801B0030(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CD77C = D_801B577C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_RODATA("../asm/us/magic_laser2/nonmatchings/text", D_801B0000);

void func_801B009C(void) {
    MgMat m;
    MgVec v;
    MgTask *p;
    s16 *q;
    s16 n;

    v = D_801B0000;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C((MgSVec *)&p->unkC, &m);
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    q = &D_801B305C;
    *q = p->unk2 % D_801B2F24;
    D_801CD77C = (u8 *)func_800D4D90((u8 *)q - 8, D_801517C0 + 0x70, 0xC, (s32)D_801CD77C);
    if (D_80062D98 == 0) {
        n = ++p->unk2;
        if (n == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B01F8(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801B3068;
    *frame = p->unk2;
    D_801CD77C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801CD77C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B2F8C) {
            p->unk0 = -1;
        }
    }
}

Lz2Obj *func_801B02B4(void) {
    s16 i;

    for (i = 0; i < 500; i++) {
        if (D_801B306C[i].unk0 == 0) {
            D_801B306C[i].unk0 = 1;
            D_801B306C[i].unk2 = 0;
            return &D_801B306C[i];
        }
    }
    return NULL;
}

void func_801B0340(void) {
    MgSVec a;
    MgSVec b;
    MgSVec c;
    MgSVec d;
    s32 ext;
    s32 flag;
    s16 i;
    MgPart *p;
    u8 *q;
    s32 r;
    s32 t;
    s32 k;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    for (i = 0; i < 500; i++) {
        if (D_801B306C[i].unk0 != 0) {
            p = (MgPart *)&D_801B306C[i];
            a.vx = p->unk4;
            a.vy = p->unk6 + 0x14;
            a.vz = p->unk8;
            c.vx = p->unk4;
            c.vy = p->unk6 - 0x14;
            c.vz = p->unk8;
            b.vx = p->unkC;
            b.vy = p->unkE + 0x14;
            b.vz = p->unk10;
            d.vx = p->unkC;
            q = D_801CD77C;
            d.vy = p->unkE - 0x14;
            d.vz = p->unk10;
            r = func_8003BD7C(&a, &b, &c, &d, q + 8, q + 0x10, q + 0x18, q + 0x20, &ext, &flag);
            if (r > 0) {
                q[7] = 0x3A;
                *(s32 *)q = 0x08000000;
                t = 0x80 - D_801B306C[i].unk2 * 0x10;
                q[4] = q[0xC] = q[0x14] = q[0x1C] = 0;
                q[5] = q[0xD] = q[0x15] = q[0x1D] = (u32)(t << 16) >> 17;
                q[6] = q[0xE] = q[0x16] = q[0x1E] = t;
                k = 0x70;
                func_80046794(((r >> 2) << 2) + k + D_801517C0, q);
                D_801CD77C = q + 0x24;
            }
        }
    }
}

void func_801B0558(void) {
    MgObj20 *p;
    s16 i;
    s16 n;
    Lz2Obj *q;

    p = &D_80162978[D_8015169C];
    func_801B0340();
    if (D_80062D98 == 0) {
        for (i = 0; i < 500; i++) {
            if (D_801B306C[i].unk0 != 0) {
                n = D_801B306C[i].unk2 + 1;
                q = &D_801B306C[i];
                q->unk2 = n;
                if (n == 8) {
                    D_801B306C[i].unk0 = 0;
                }
            }
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B065C(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u16 *, 4) + ((s32) (func_80039B40(M2C_FIELD(arg0, s16 *, 0x14)) * M2C_FIELD(arg0, s16 *, 0x18)) >> 0xC));
    M2C_FIELD(arg1, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 6);
    M2C_FIELD(arg1, s16 *, 4) = (s16) (M2C_FIELD(arg0, u16 *, 8) + ((s32) (func_80039A74(M2C_FIELD(arg0, s16 *, 0x14)) * M2C_FIELD(arg0, s16 *, 0x18)) >> 0xC));
}

void func_801B06EC(void) {
    MgTask *p;
    Lz2Obj *q;
    s16 n;
    u8 pad[16];

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = func_801B02B4();
        if (q != 0) {
            func_801B065C(p, (u8 *)q + 4);
        }
        if (p->unk2 < 10) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unk18 = ((s32 (*)(s32))func_80039A74)(p->unk2 * 200) * p->unk1A >> 12;
        } else {
            p->unk14 += p->unk16;
            p->unk18 -= p->unk18 / 16;
        }
        if (q != 0) {
            func_801B065C(p, (u8 *)q + 0xC);
        }
        n = ++p->unk2;
        if (n == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B082C(void) {
    MgSVec ang;
    MgSVec dir;
    MgMat m;
    s32 flag;
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 n;
    s16 a;
    s32 t;
    s32 k;

    b = (MgTask *)D_80162978;
    p = &b[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &b[func_800BBEAC((void *)func_801B009C)];
            q->unk10 = 0;
            q->unkC = 0;
            q->unkE = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            ang.vx = ang.vy = 0;
            ang.vz = 0x190;
            func_8003C21C((MgSVec *)&q->unkC, &m);
            m.t[0] = m.t[1] = m.t[2] = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&ang, &ang, &flag);
            q->unk4 = p->unk4 + ang.vx;
            q->unk6 = p->unk6 + ang.vy;
            i = 0;
            q->unk8 = p->unk8 + ang.vz;
            q->unkE -= 0x400;
            func_800D3994(p->unk1C, D_80151919[p->unk1C][0], &dir);
            a = dir.vy - 0xC8;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B06EC)];
                q->unk4 = p->unk4 + ang.vx;
                q->unk6 = p->unk6 + ang.vy;
                q->unk8 = p->unk8 + ang.vz;
                q->unkC = (p->unkC - q->unk4) / 10;
                q->unkE = (a / 10 * i - q->unk6) / 10;
                q->unk10 = (p->unk10 - q->unk8) / 10;
                if ((i & 1) == 0) {
                    q->unk14 = func_80042DA8() % 0x200 - 0x100;
                    q->unk16 = D_801B3050 * 0x180;
                } else {
                    q->unk14 = func_80042DA8() % 0x200 + 0x700;
                    q->unk16 = -(D_801B3050 * 0x180);
                }
                q->unk18 = 0;
                t = ((s32 (*)(s32))func_80039A74)(i * 0xCC);
                n = i + 1;
                i = n;
                q->unk1A = (t * 900 >> 12) + 0x12C;
            } while (n < 10);
        }
        if (p->unk2 == 10) {
            func_800D5774(p->unk1C);
        }
        if ((u32)((u16)p->unk2 - 0xB) < 4) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B01F8)];
            func_800D3994(p->unk1C, D_8015190F[D_800FA6D4][0], &q->unk4);
            k = 0x1F4;
            q->unk4 = q->unk4 - k + func_80042DA8() % 1000;
            q->unk6 = q->unk6 - k + func_80042DA8() % 1000;
            q->unk8 = q->unk8 - k + func_80042DA8() % 1000;
        }
        n = ++p->unk2;
        if (n == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0D30(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B082C)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    if (p->unk8 > p->unk10) {
        D_801B3050 = -1;
    }
    func_800BBEAC((void *)func_801B0558);
}

void func_801B0E20(arg0, arg1) {
    s16 i;

    func_800BBEAC((void *)func_801B0030);
    func_800D2980(&D_801B0EE0, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, (void *)func_801B0D30);
    func_800BBA84(0x6C, arg1, 0x40);
    i = 0;
    do {
        D_801B306C[i].unk0 = 0;
        i++;
    } while (i < 500);
}
