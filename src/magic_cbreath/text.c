#include "common.h"
#include "magic_cbreath/decls.h"

void func_801B008C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, 0);
    D_801C1AA0[0] = p->unk2;
    D_801DA120 = func_800D4D90(&D_801C1AA0[-4], D_801517C0 + 0x70, 0xC, D_801DA120);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C1914) {
            p->unk0 = -1;
        }
    }
}

MgObj8 *func_801B0148(void) {
    s16 i;

    for (i = 0; i < 200; i++) {
        if (D_801C1AE0[i].unk0 == 0) {
            D_801C1AE0[i].unk0 = 1;
            D_801C1AE0[i].unk6 = 0;
            return &D_801C1AE0[i];
        }
    }
    return NULL;
}

void func_801B01C8(MgTask *p) {
    MgSVec rot;
    MgSVec pt;
    MgMat m;
    s32 ext;
    s32 flag;
    u8 *q;
    s16 i;
    s16 k;
    s32 r;
    s32 t;

    rot.vx = rot.vz = 0;
    rot.vy = p->unk14;
    func_8003C21C(&rot, &m);
    for (i = 0; i < 200; i++) {
        if (D_801C1AE0[i].unk0 != 0) {
            pt.vx = ((func_80039B40(D_801C1AE0[i].unk4) * D_801C1AE0[i].unk2 * D_801C1AE0[i].unk6) / 20 * 0x100) >> 20;
            pt.vy = ((func_80039A74(D_801C1AE0[i].unk4) * D_801C1AE0[i].unk2 * D_801C1AE0[i].unk6) / 20 * 0x100) >> 20;
            pt.vz = 0;
            func_8003B2CC(&m, &pt, &pt);
            pt.vx += p->unk4 + p->unkC * D_801C1AE0[i].unk6;
            pt.vy += p->unk6 + p->unkE * D_801C1AE0[i].unk6;
            pt.vz += p->unk8 + p->unk10 * D_801C1AE0[i].unk6;
            func_8003B48C(&D_800FA63C);
            func_8003B51C(&D_800FA63C);
            q = D_801DA120;
            func_80046974(q);
            q[7] = 0x6A;
            r = func_8003BBDC(&pt, q + 8, &ext, &flag);
            if (D_801C1AE0[i].unk6 >= 0x11) {
                k = 0x19 - D_801C1AE0[i].unk6;
            } else {
                k = 8;
            }
            q[4] = k * 0x10;
            q[5] = k * 0x10;
            q[6] = k * 0x10;
            t = (r >> 2) * 4 + 0x70;
            func_80046794(t + D_801517C0, q);
            D_801DA120 = q + 0xC;
        }
    }
}

void func_801B04C8(void) {
    MgTask *p;
    MgObj8 *q;
    s16 i;
    s16 n;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B01C8(p);
    if (D_80062D98 == 0) {
        t = p->unk1A;
        if (t != 0) {
            p->unk1A = t + 8;
        }
        if ((u16)(p->unk2 - 1) < 0x13U) {
            for (i = 0; i < 8; i++) {
                q = func_801B0148();
                if (q != NULL) {
                    q->unk2 = func_80042DA8() % 0x200;
                    q->unk4 = func_80042DA8() & 0xFFF;
                }
            }
        }
        for (i = 0, n = 0; i < 200; i++) {
            if (D_801C1AE0[i].unk0 != 0) {
                D_801C1AE0[i].unk4 -= 0x80;
                n++;
                if (++D_801C1AE0[i].unk6 == 0x19) {
                    D_801C1AE0[i].unk0 = 0;
                }
            }
        }
        if (++p->unk2 >= 0x15 && n == 0) {
            p->unk0 = -1;
        }
    }
}

void func_801B06A8(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    p->unkC = -p->unk2 << 7;
    func_8003C21C((MgSVec *)&p->unkC, &m);
    D_801C1AAC[0] = p->unk18;
    D_801C1AB0 = 0x1A00;
    D_801C1AAC[-1] = 0x1A00;
    func_8003B35C(&m, (MgVec *)&D_801C1AAC[-1]);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801C1AC2;
    *frame = D_801C1AA4 * 0x10;
    D_801DA120 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801DA120);
    if (D_80062D98 == 0) {
        if (p->unk2 < 8) {
            D_801C1AA4 += 1;
        }
        if (p->unk2 >= 0x1A) {
            D_801C1AA4 -= 1;
        }
        if (++p->unk2 == 0x21) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_RODATA("../asm/us/magic_cbreath/nonmatchings/text", D_801B0000);

void func_801B083C(void) {
    MgMat lw;
    MgVec v;
    MgMat m;
    MgTask *p;
    s16 *frame;
    s32 t;

    m = D_801B0000;
    p = (MgTask *)&D_80162978[D_8015169C];
    v.vx = v.vy = v.vz = p->unk2 * 0x1E0;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801C1AD6;
    t = D_801C1AC8;
    *frame = t << 9;
    func_8003B69C(0, 0, 0);
    D_801DA120 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801DA120);
    if (D_80062D98 == 0) {
        p->unk6 += 0x28;
        p->unk4 += p->unkC;
        p->unk8 += p->unk10;
        if (p->unk2 >= 0xD) {
            D_801C1AC8++;
        }
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0A00(void) {
    MgSVec v;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 d;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801C1ADC = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B04C8)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unkC = (p->unkC - p->unk4) / 20;
            q->unkE = 0;
            q->unk10 = (p->unk10 - p->unk8) / 20;
            q->unk14 = D_801C1ADC;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B06A8)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk10 = 0x400;
            q->unkE = D_801C1ADC - 0x400;
            v.vx = p->unkC - p->unk4;
            v.vz = p->unk10 - p->unk8;
            d = func_80039F5C(v.vx * v.vx + v.vz * v.vz);
            q->unk1A = q->unk18 = d * 0x1500 / 2800;
        }
        if (p->unk2 == 0x14) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B083C)];
            q->unkC = (u32)(func_80039A74((s16)D_801C1ADC + 0x800) * 0xF) >> 0xB;
            q->unk10 = (u32)(func_80039B40((s16)D_801C1ADC + 0x800) * 0xF) >> 0xB;
            q->unk4 = p->unkC - q->unkC * 10;
            q->unk6 = p->unkE + 0x190;
            q->unk8 = p->unk10 - q->unk10 * 10;
        }
        if (p->unk2 == 0x28) {
            func_800D5774(p->unk1C);
            func_800BBA84(0x95, p->unk1C, 0x40);
        }
        if ((u16)(p->unk2 - 0x25) < 7U) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B008C)];
                func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
                q->unk4 += func_80042DA8() % 1000 - 500;
                q->unk6 += func_80042DA8() % 1000 - 500;
                i++;
                q->unk8 += func_80042DA8() % 1000 - 500;
            } while (i < 2);
        }
        p->unk2++;
        if (p->unk2 == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B0E54(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B0A00)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_RODATA("../asm/us/magic_cbreath/nonmatchings/text", D_801B0020);

void func_801B0F14(s32 arg0, s32 arg1) {
    s16 i;

    func_800BBEAC(&D_801B0020);
    func_800D2980(&D_801B18B0, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B0E54);
    func_800BBA84(0xB0, arg1, 0x40);
    for (i = 0; i < 200; i++) {
        D_801C1AE0[i].unk0 = 0;
    }
}
