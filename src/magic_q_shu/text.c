#include "common.h"
#include "magic_q_shu/decls.h"

void func_801B007C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801BDA98;
    *frame = p->unk2;
    D_801D5AE8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D5AE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801BD9CC) {
            p->unk0 = -1;
        }
    }
}

void func_801B0138(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801BDAA4[0] = p->unk2 % D_801BDAA8[p->unk14]->unk4;
    *(MgAnim **)&D_801BDAA4[-4] = D_801BDAA8[p->unk14];
    D_801D5AE8 = func_800D4D90(&D_801BDAA4[-4], D_801517C0 + 0x70, 0xC, D_801D5AE8);
    if (D_80062D98 == 0) {
        p->unk6 += 0x64;
        p->unk2++;
        if (p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B0264(void) {
    MgSVec v;
    MgTask *p;
    s16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    v.vx = p->unk4 + (func_80039A74(p->unk14) * p->unk18 >> 12);
    v.vz = p->unk8 + (func_80039B40(p->unk14) * p->unk18 >> 12);
    v.vy = p->unk6 + p->unk1A;
    func_800D4368(&v, 0x2000, 0);
    frame = &D_801BDAB8;
    *frame = p->unk2 % D_801BD8E4;
    D_801D5AE8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D5AE8);
    if (D_80062D98 == 0) {
        p->unk1A -= 0x32;
        p->unk14 += 0x80;
        p->unk18 -= p->unk18 / 10;
        if (++p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B03FC(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801BDAC4;
    *frame = p->unk2;
    D_801D5AE8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D5AE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801BD84C) {
            p->unk0 = -1;
        }
    }
}

void func_801B04B4(void) {
    MgSVec v;
    MgTask *p;
    MgTask *q;
    s16 *frame;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    v.vx = p->unk4 + (func_80039A74(p->unk14) * p->unk18 >> 12);
    v.vy = p->unk6 + (func_80039B40(p->unk14) * p->unk18 >> 12);
    v.vz = p->unk8;
    func_800D4368(&v, (s16)(p->unk16 * 5 / p->unk1C), 0);
    frame = &D_801BDAD0;
    *frame = p->unk2 % D_801BD9AC;
    D_801D5AE8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D5AE8);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x1E) {
            p->unk16 += 0xC0;
        }
        if ((u16)p->unk2 - 0x1E < 0xAU) {
            t = p->unk1A + 0xCC;
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unk1A = t;
            p->unk18 = (u32)(func_80039A74(t) * 0x19) >> 8;
            p->unk14 += 0x200;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B03FC)];
            q->unk4 = p->unk4 + func_80042DA8() % 800 - 0x190;
            q->unk6 = p->unk6 + func_80042DA8() % 800 - 0x190;
            q->unk8 = p->unk8 + func_80042DA8() % 800 - 0x190;
        }
        if (p->unk2 > 0x28) {
            p->unk16 -= 0x100;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0138)];
            q->unk4 = p->unk4 + func_80042DA8() % 600 - 0x12C;
            q->unk6 = p->unk6 + func_80042DA8() % 600 - 0x12C;
            q->unk8 = p->unk8 + func_80042DA8() % 600 - 0x12C;
            q->unk14 = func_80042DA8() & 1;
        }
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_RODATA("../asm/us/magic_q_shu/nonmatchings/text", D_801B0000);

void func_801B08E0(void) {
    MgMat m;
    MgMat w;
    MgScratch s;
    MgSVec rot;
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 t;

    s = D_801B0000;
    rot.vz = 0;
    rot.vx = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vy = p->unk2 << 7;
    func_8003C21C(&rot, &m);
    func_8003B35C(&m, &D_801BDAD8);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &w);
    func_8003B48C(&w);
    func_8003B51C(&w);
    s.unkA = D_801BDAD4;
    s.unkE = p->unk2 % 5 * 0xC0;
    D_801D5AE8 = func_800D29D4(&s, D_801517C0 + 0x70, 0xC, D_801D5AE8);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x14) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            D_801BDAD4 += 6;
        }
        if ((u16)p->unk2 - 0x14 < 0x1EU) {
            for (i = 0; i < 1; i++) {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0264)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unk14 = func_80042DA8() & 0xFFF;
                q->unk18 = 0x3E8;
                q->unk1A = 0x3E8;
            }
        }
        if ((u16)p->unk2 - 0x26 < 6U && !(p->unk2 & 1)) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B04B4)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6 - 0x1F4;
            q->unk8 = p->unk8;
            q->unkC = -(u16)p->unkC * 2;
            q->unkE = -(u16)p->unkE * 2;
            q->unk10 = -(u16)p->unk10 * 2;
            q->unk16 = 0x100;
            q->unk1A = 0;
            q->unk18 = 0;
            q->unk1C = (p->unk2 - 0x26) / 2 + 5;
        }
        if (p->unk2 >= 0x33) {
            t = D_801BDAD4 - 6;
            D_801BDAD4 = t;
            if ((s16)t == 0) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0C5C(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B08E0)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6 - 0x190;
            q->unk8 = p->unk8;
            q->unkC = (p->unkC - q->unk4) / 20;
            k = q->unk6 + 0x320;
            q->unkE = (p->unkE - k) / 20;
            q->unk10 = (p->unk10 - q->unk8) / 20;
        }
        if (p->unk2 == 0x5A) {
            func_800D5774(p->unk1C);
            func_800BBA84(0x1F, p->unk1E, 0x40);
        }
        if ((u16)p->unk2 - 0x57 < 0xFU) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B007C)];
                func_800D3994(p->unk1E, func_80042DA8() % D_801518F4[p->unk1E][0], &q->unk4);
                k = 0x12C;
                q->unk4 = q->unk4 - k + func_80042DA8() % 600;
                k = 0x12C;
                q->unk6 = q->unk6 - k + func_80042DA8() % 600;
                i++;
                k = 0x12C;
                q->unk8 = q->unk8 - k + func_80042DA8() % 600;
            } while (i < 4);
        }
        p->unk2++;
        if (p->unk2 == 0x6E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0F5C(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B0C5C)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    p->unk1E = arg1;
}

INCLUDE_RODATA("../asm/us/magic_q_shu/nonmatchings/text", D_801B0010);

void func_801B1028(arg0, arg1) {
    func_800BBEAC(D_801B0010);
    func_800D2980(D_801B10A4, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0F5C);
    func_800BBA84(0x7E, arg1, 0x40);
}
