#include "common.h"
#include "magic_ho_den/decls.h"

void func_801B0000(void) {
    func_801B10B0();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EED84 = D_801D6D84 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D6C64;
    *frame = p->unk2;
    D_801EED84 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EED84);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D6AD8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_ho_den/nonmatchings/text", func_801B0148);

void func_801B027C(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    MgTask *p;
    s16 *fp;
    s16 *frame;
    s32 t;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unk2 << 6;
    rot.vy = p->unk2 << 7;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    t = 0x2000 - p->unk2 * 0x199;
    D_801D6D48.vx = D_801D6D4C = D_801D6D50 = t;
    func_8003B35C(&m, &D_801D6D48);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    fp = &D_801D6C7E;
    frame = fp - 5;
    *fp = p->unk2 * 6;
    D_801EED84 = func_800D29D4(frame, D_801517C0 + 0x70, 0xC, D_801EED84);
    rot.vx = p->unk2 << 6;
    rot.vy = -p->unk2 << 7;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    t = 0x1800 - p->unk2 * 0x133;
    D_801D6D48.vx = D_801D6D4C = D_801D6D50 = t;
    func_8003B35C(&m, &D_801D6D48);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801EED84 = func_800D29D4(frame, D_801517C0 + 0x70, 0xC, D_801EED84);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B04E4(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 k;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801D6CA8, &m);
    func_8003A79C(D_801D6D64, &m, &m);
    D_801D6C8C[0] = p->unk18 * p->unk2 / 10;
    func_8003B35C(&m, (MgVec *)&D_801D6C8C[-1]);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D6CA2[0] = D_801D6C84 * 0x10;
    k = p->unk2 % 7;
    *(s32 *)&D_801D6CA2[-5] = D_801D6CB8[k];
    D_801EED84 = func_800D29D4(&D_801D6CA2[-5], D_801517C0 + 0x70, 0xC, D_801EED84);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 9) {
            D_801D6C84 -= 1;
        }
        if (++p->unk2 == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B06C4(void) {
    MgMat m;
    MgMat lw;
    s32 flag[2];
    MgTask *p;
    s16 *v;
    MgMat *wm;
    s16 *fp;
    s16 *frame;
    HoPtr *fd;
    s32 *q;
    s8 *bp;

    v = &D_801D6D58;
    *v = 0;
    D_801D6D5A.v = 0;
    p = &D_80162978[D_8015169C];
    D_801D6D5C.v = p->unk18 * p->unk2 / 10;
    q = &D_801D6D78;
    *q = p->unk4;
    wm = (MgMat *)((u8 *)q - 0x14);
    D_801D6D7C.a = p->unk6;
    D_801D6D7C.b = p->unk8;
    func_8003B48C(wm);
    func_8003B51C(wm);
    func_8003BADC((MgSVec *)v, (MgSVec *)v, flag);
    func_8003C21C(&D_801D6D10, &m);
    func_8003A79C(wm, &m, &m);
    func_8003B35C(&m, &D_801D6CE4);
    m.t[0] = *v;
    m.t[1] = *(s16 *)((u8 *)&D_801D6D58 + 2);
    m.t[2] = *(s16 *)((u8 *)&D_801D6D58 + 4);
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    fp = &D_801D6CFE[0];
    frame = fp - 5;
    fd = (HoPtr *)frame;
    fd->p = D_801D4A10;
    *fp = D_801D6CE0 * 0x10;
    D_801EED84 = func_800D29D4(frame, D_801517C0 + 0x70, 0xC, D_801EED84);
    fd->p = D_801D59B4;
    D_801EED84 = func_800D29D4(frame, D_801517C0 + 0x70, 0xC, D_801EED84);
    fd->p = D_801D6958;
    D_801EED84 = func_800D29D4(frame, D_801517C0 + 0x70, 0xC, D_801EED84);
    func_800D4368(v, 0x3000, 0);
    bp = &D_801D6D08;
    *bp = D_801D6D09.v = D_801D6D0A.v = (s16)D_801D6CE0 * 0x14;
    D_801D6D0C = p->unk2 % 2;
    D_801EED84 = func_800D4D90(bp - 4, D_801517C0 + 0x70, 0xC, D_801EED84);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 9) {
            D_801D6CE0 -= 1;
        }
        if (++p->unk2 == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B09CC(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_8003BF8C(&p->unkC, &m);
    func_8003A79C(D_801D6D64, &m, &m);
    func_8003B35C(&m, &D_801D6D18);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D6D32[0] = 0x80 - p->unk2 * 0x20;
    *(s32 *)&D_801D6D32[-5] = D_801D6D38[p->unk16];
    D_801EED84 = func_800D29D4(&D_801D6D32[-5], D_801517C0 + 0x70, 0xC, D_801EED84);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0B10(void) {
    MgSVec v;
    u8 pad[16];
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 d;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0148)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
        }
        if (p->unk2 < 0xC) {
            if ((((volatile MgTask *)p)->unk2 & 3) == 0) {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B027C)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
            }
        }
        if ((u16)(p->unk2 - 0x14) < 8U) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B09CC)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk16 = func_80042DA8() % 4;
            q->unkC = -0x400;
            q->unk10 = 0;
            q->unkE = func_80042DA8() % 0x1000;
        }
        if (p->unk2 == 0x14) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B04E4)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            v.vx = p->unkC - q->unk4;
            v.vy = p->unkE - q->unk6;
            v.vz = p->unk10 - q->unk8;
            d = func_80039F5C(v.vx * v.vx + v.vy * v.vy + v.vz * v.vz);
            q->unk1A = 0;
            q->unk18 = d * 0x1200 / 3000;
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B06C4)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk18 = d;
            q->unk1A = 0;
        }
        if ((u16)(p->unk2 - 0x1C) < 0xFU) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B008C)];
                q->unk4 = p->unkC + func_80042DA8() % 1200 - 0x258;
                q->unk6 = p->unkE + func_80042DA8() % 1200 - 0x258;
                i++;
                q->unk8 = p->unk10 + func_80042DA8() % 1200 - 0x258;
            } while (i < 2);
        }
        if (p->unk2 == 0x23) {
            func_800D5774(p->unk1C);
            func_800BBA84(0xFA, p->unk1C, 0x40);
        }
        p->unk2++;
        if (p->unk2 == 0x2D) {
            func_800D52A0(0, 0xA);
            p->unk0 = -1;
        }
    }
}

void func_801B0F70(arg0, arg1) {
    MgSVec d;
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B0B10)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    d.vx = p->unkC.vx - p->unk4.vx;
    d.vy = p->unkC.vy - p->unk4.vy;
    d.vz = p->unkC.vz - p->unk4.vz;
    func_800D44E8(&d, D_801D6D64);
    p->unk1C = arg0;
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    func_800D52A0(0x1000, 0x14);
    func_800BBA84(0x1C8, arg1, 0x40);
}

void func_801B10B0(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B111C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0F70);
}
