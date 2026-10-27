#include "common.h"
#include "magic_ito/decls.h"

void func_801B0000(void) {
    func_801B0D98();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CD578 = D_801B5578 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    frame = &D_801B555C;
    *frame = p->unk2 % D_801B551C;
    D_801CD578 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801CD578);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B0178(void) {
    MgTask *p;
    s32 **tbl;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801B5568[0].v = p->unk2;
    *(s32 *)&D_801B5568[-4] = (s32)D_801B556C[p->unk16];
    D_801CD578 = func_800D4D90(&D_801B5568[-4], D_801517C0 + 0x70, 0xC, D_801CD578);
    tbl = D_801B556C;
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == tbl[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

ItoObj *func_801B0268(void) {
    s16 i;

    for (i = 0; i < 200; i++) {
        if (D_801CD57C[i].unk0 == 0) {
            D_801CD57C[i].unk0 = 1;
            D_801CD57C[i].unk2 = 0;
            return &D_801CD57C[i];
        }
    }
    return NULL;
}

void func_801B02F4(u32 arg0) {
    s32 v[2];
    s32 *fp;
    s16 i;
    s32 o;
    u8 *a;
    u8 *b;
    u8 *pkt;
    s32 n;

    func_8003B48C(D_800FA63C);
    func_8003B51C(D_800FA63C);
    i = 0;
    fp = &v[1];
    a = D_801CD57C[0].pad4;
    b = a + 8;
    for (; i < 200; i++) {
        o = i * 20;
        if (*(s16 *)((u8 *)D_801CD57C + o) != 0) {
            pkt = D_801CD578;
            func_800469C4(pkt);
            pkt[7] = 0x42;
            func_8003BBDC((u8 *)(o + (s32)a), pkt + 8, &v[0], fp);
            n = func_8003BBDC((u8 *)(o + (s32)b), pkt + 0xC, &v[0], fp);
            if (n > 0) {
                pkt[4] = pkt[5] = pkt[6] = arg0 >> 1;
                func_80046794((n >> 2) * 4 + (0x70 + D_801517C0), pkt);
                D_801CD578 = pkt + 0x10;
            }
        }
    }
}

void func_801B0440(void) {
    MgTask *p;
    s16 c;
    s16 i;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 >= 0x20) {
        c = 0x28 - p->unk2;
        c <<= 4;
    } else {
        c = 0x80;
    }
    func_801B02F4(c);
    if (D_80062D98 == 0) {
        for (i = 0; i < 200; i++) {
            if (D_801CD57C[i].unk0 != 0) {
                if (++D_801CD57C[i].unk2 == 10) {
                    D_801CD57C[i].unk0 = 0;
                }
            }
        }
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0574(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u16 *, 4) + ((s32) (func_80039B40(M2C_FIELD(arg0, s16 *, 0x14)) * M2C_FIELD(arg0, s16 *, 0x18)) >> 0xC));
    M2C_FIELD(arg1, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 6);
    M2C_FIELD(arg1, s16 *, 4) = (s16) (M2C_FIELD(arg0, u16 *, 8) + ((s32) (func_80039A74(M2C_FIELD(arg0, s16 *, 0x14)) * M2C_FIELD(arg0, s16 *, 0x18)) >> 0xC));
}

void func_801B0604(void) {
    MgTask *p;
    ItoObj *q;
    s16 n;
    u8 pad[16];

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = func_801B0268();
        if (q != 0) {
            func_801B0574(p, (u8 *)q + 4);
        }
        if (p->unk2 < 10) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unk18 = ((s32 (*)(s32))func_80039A74)(p->unk2 * 200) * p->unk1A >> 12;
        } else {
            p->unk14 += p->unk16;
            p->unk6 -= 5;
        }
        if (p->unk2 >= 0x15) {
            p->unk18 += p->unk18 / 64;
        }
        if (q != 0) {
            func_801B0574(p, (u8 *)q + 0xC);
        }
        n = ++p->unk2;
        if (n == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B076C(void) {
    u8 pad[8];
    MgSVec ang;
    MgSVec dir;
    MgMat m;
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
            i = 0;
            q = &b[func_800BBEAC((void *)func_801B008C)];
            q->unkC = q->unkE = 0;
            q->unkE = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            ang.vx = ang.vy = 0;
            ang.vz = 0x190;
            func_8003C21C((MgSVec *)&q->unkC, &m);
            func_8003B2CC(&m, &ang, &ang);
            q->unk4 = p->unk4 += ang.vx;
            q->unk6 = p->unk6 += ang.vy;
            q->unk8 = p->unk8 += ang.vz;
            func_800D3994(p->unk1C, D_80151919[D_800FA6D4][0], &dir);
            a = dir.vy - 0xC8;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0604)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unkC = (p->unkC - q->unk4) / 10;
                q->unkE = (a / 20 * i - q->unk6) / 10;
                q->unk10 = (p->unk10 - q->unk8) / 10;
                if ((i & 1) == 0) {
                    q->unk14 = func_80042DA8() % 0x200 - 0x100;
                    q->unk16 = D_801B5550 * 0x180;
                } else {
                    q->unk14 = func_80042DA8() % 0x200 + 0x700;
                    q->unk16 = -(D_801B5550 * 0x180);
                }
                q->unk18 = 0;
                t = ((s32 (*)(s32))func_80039A74)(i * 0x66);
                k = ((s32 (*)(s32))func_80039A74)(i * 0x320);
                n = i + 1;
                i = n;
                q->unk1A = (t * 0x258 >> 12) + 0x258 + (k * 0xC8 >> 12);
            } while (n < 0x14);
        }
        if (p->unk2 == 0x24) {
            func_800D4D4C(p->unk1C, 0x33);
            func_800D5774(p->unk1C);
        }
        if ((u32)((u16)p->unk2 - 0x11) < 0xE) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0178)];
            func_800D3994(p->unk1C, D_8015190F[D_800FA6D4][0], &q->unk4);
            k = 0x1F4;
            q->unk4 = q->unk4 - k + func_80042DA8() % 1000;
            q->unk6 = q->unk6 - k + func_80042DA8() % 1000;
            q->unk8 = q->unk8 - k + func_80042DA8() % 1000;
            q->unk16 = func_80042DA8() % 2;
        }
        n = ++p->unk2;
        if (n == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B0CA8(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B076C)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    if (p->unk8 > p->unk10) {
        D_801B5550 = -1;
    }
    func_800BBEAC((void *)func_801B0440);
}

void func_801B0D98(arg0, arg1) {
    s16 i;

    func_800BBEAC((void *)func_801B0020);
    func_800D2980(&D_801B50D8, 0, 0, 0);
    func_800D2980(&D_801B0E70, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, (void *)func_801B0CA8);
    func_800BBA84(0x6A, arg1, 0x40);
    i = 0;
    do {
        D_801CD57C[i].unk0 = 0;
        i++;
    } while (i < 200);
}
