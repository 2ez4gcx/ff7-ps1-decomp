#include "common.h"
#include "magic_kafun/decls.h"

void func_801B008C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801D16B4[0] = p->unk2;
    D_801E9D28 = func_800D4D90(&D_801D16B4[-4], D_801517C0 + 0x70, 0xC, D_801E9D28);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D1504) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_RODATA("../asm/us/magic_kafun/nonmatchings/text", D_801B0000);

void func_801B0148(void) {
    MgVec v;
    MgMat m;
    MgTask *p;
    MgByte *col;
    s32 c;

    m = D_801B0000;
    p = (MgTask *)&D_80162978[D_8015169C];
    v.vx = v.vy = v.vz = p->unk18;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = p->unk16 * 12;
    col = &D_801D16BC;
    col->v = D_801D16BD.v = D_801D16BE.v = c;
    D_801E9D28 = func_800D4D90((u8 *)col - 4, D_801517C0 + 0x70, 0xC, D_801E9D28);
    if (D_80062D98 == 0) {
        p->unk4 += p->unk14;
        p->unk6 += p->unk14;
        if (p->unk2 < 8) {
            p->unk16++;
        }
        if (p->unk2 >= 0x26) {
            p->unk16--;
        }
        if (++p->unk2 == 0x2D) {
            p->unk0 = -1;
        }
    }
}

MgObj8 *func_801B0308(void) {
    s16 i;

    for (i = 0; i < 200; i++) {
        if (D_801D16E8[i].unk0 == 0) {
            D_801D16E8[i].unk0 = 1;
            D_801D16E8[i].unk6 = 0;
            return &D_801D16E8[i];
        }
    }
    return NULL;
}

void func_801B0388(MgTask *p) {
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
    m.t[0] = m.t[1] = m.t[2] = 0;
    for (i = 0; i < 200; i++) {
        if (D_801D16E8[i].unk0 != 0) {
            pt.vx = ((func_80039B40(D_801D16E8[i].unk4) * D_801D16E8[i].unk2 * D_801D16E8[i].unk6) / 20 * (p->unk1A + 0x100)) >> 20;
            pt.vy = ((func_80039A74(D_801D16E8[i].unk4) * D_801D16E8[i].unk2 * D_801D16E8[i].unk6) / 20 * (p->unk1A + 0x100)) >> 20;
            pt.vz = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&pt, &pt, &ext);
            pt.vx += p->unk4 + p->unkC * D_801D16E8[i].unk6;
            pt.vy += p->unk6 + p->unkE * D_801D16E8[i].unk6;
            pt.vz += p->unk8 + p->unk10 * D_801D16E8[i].unk6;
            func_8003B48C(&D_800FA63C);
            func_8003B51C(&D_800FA63C);
            q = D_801E9D28;
            func_80046974(q);
            q[7] = 0x6A;
            r = func_8003BBDC(&pt, q + 8, &flag, &ext);
            if (D_801D16E8[i].unk6 >= 0x11) {
                k = 0x19 - D_801D16E8[i].unk6;
            } else {
                k = 8;
            }
            q[4] = k * 0xD;
            q[5] = k * 0xD;
            q[6] = 0;
            t = (r >> 2) * 4 + 0x70;
            func_80046794(t + D_801517C0, q);
            D_801E9D28 = q + 0xC;
        }
    }
}

void func_801B06E4(void) {
    MgTask *p;
    MgObj8 *q;
    s16 i;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B0388(p);
    if (D_80062D98 == 0) {
        p->unk1A += 8;
        if ((u16)(p->unk2 - 1) < 0x18U) {
            for (i = 0; i < 8; i++) {
                q = func_801B0308();
                if (q != NULL) {
                    q->unk2 = func_80042DA8() % 0x200;
                    q->unk4 = func_80042DA8() & 0xFFF;
                }
            }
        }
        for (i = 0, n = 0; i < 200; i++) {
            if (D_801D16E8[i].unk0 != 0) {
                D_801D16E8[i].unk4 -= 0x80;
                n++;
                if (++D_801D16E8[i].unk6 == 0x19) {
                    D_801D16E8[i].unk0 = 0;
                }
            }
        }
        if (++p->unk2 >= 0x1A && n == 0) {
            p->unk0 = -1;
        }
    }
}

void func_801B08B4(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 *frame;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    p->unkC = -p->unk2 << 7;
    func_8003C21C((MgSVec *)&p->unkC, &m);
    D_801D16CC[0] = p->unk18;
    t = (p->unk1A + 0x100) * 0x1A;
    D_801D16D0 = t;
    D_801D16CC[-1] = t;
    func_8003B35C(&m, (MgVec *)&D_801D16CC[-1]);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801D16E2;
    *frame = D_801D16C4 * 0x10;
    D_801E9D28 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801E9D28);
    if (D_80062D98 == 0) {
        p->unk1A += 8;
        if (p->unk2 < 8) {
            D_801D16C4 += 1;
        }
        if (p->unk2 >= 0x26) {
            D_801D16C4 -= 1;
        }
        if (++p->unk2 == 0x2D) {
            p->unk0 = -1;
        }
    }
}

void func_801B0A64(void) {
    MgSVec v;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 d;
    s16 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            a = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B06E4)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unkC = (p->unkC - p->unk4) / 20;
            q->unkE = 0;
            q->unk10 = (p->unk10 - p->unk8) / 20;
            q->unk1A = 0;
            q->unk14 = a;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B08B4)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk10 = 0x400;
            q->unkE = a - 0x400;
            v.vx = p->unkC - p->unk4;
            v.vz = p->unk10 - p->unk8;
            d = func_80039F5C(v.vx * v.vx + v.vz * v.vz);
            q->unk1A = 0;
            q->unk18 = d * 0x1500 / 2800;
            if (p->unk2 == 0) {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0148)];
                q->unk6 = -0x64;
                q->unk8 = 0x7D0;
                q->unk18 = 0xF00;
                q->unk4 = 0;
                q->unk14 = 6;
                q->unk16 = 0;
            }
        }
        if (p->unk2 == 0x28) {
            func_800D5774(p->unk1C);
        }
        if ((u16)(p->unk2 - 0x21) < 0xBU) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B008C)];
                q->unk4 = p->unkC + func_80042DA8() % 1400 - 0x2BC;
                q->unk6 = p->unkE + func_80042DA8() % 1400 - 0x2BC;
                i++;
                q->unk8 = p->unk10 + func_80042DA8() % 1400 - 0x2BC;
            } while (i < 2);
        }
        p->unk2++;
        if (p->unk2 == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B0E14(s32 arg0, s32 arg1) {
    MgTask *p;
    s16 i;
    u8 *q;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0A64)];
    q = D_8015190F[arg1];
    func_800D3994(arg1, q[D_801D16A8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    i = 0;
    p->unk1C = arg0;
    do {
        D_801D16E8[i].unk0 = 0;
        i++;
    } while (i < 200);
}

void func_801B0F18(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0020);
    func_800D2980(&D_801B1460, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0E14);
    func_800BBA84(0x69, arg1, 0x40);
}

void func_801B0F94(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0020);
    func_800D2980(&D_801B1460, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0E14);
    func_800BBA84(0x69, arg1, 0x40);
    D_801D16A8 = 9;
}

INCLUDE_RODATA("../asm/us/magic_kafun/nonmatchings/text", D_801B0020);
