#include "common.h"
#include "magic_reito/decls.h"

void func_801B0000(void) {
    func_801B2354();
}

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B0A48);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B1158);

void func_801B12E4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801ECB98 = D_801D4B98 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B1350(void) {
    MgMat m;
    MgTask *p;
    s16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D4ADC, &m);
    func_8003A79C(&D_801ED19C, &m, &m);
    func_8003B35C(&m, &D_801D4AE4);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    frame = &D_801D4AD8;
    *frame = p->unk2 % D_801D4A6C;
    D_801ECB98 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801ECB98);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B149C(void) {
    MgSVec pos;
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    pos.vx = p->unk4 + (func_80039B40(p->unk18) * p->unk1A >> 12);
    pos.vz = p->unk8 + (func_80039A74(p->unk18) * p->unk1A >> 12);
    pos.vy = p->unk6;
    func_800D4368(&pos, 0x2000, 0);
    frame = &D_801D4AFC;
    *frame = p->unk2;
    D_801ECB98 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801ECB98);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x32;
        p->unk18 += 0x100;
        if (++p->unk2 == D_801D49A4) {
            p->unk0 = -1;
        }
    }
}

void func_801B15CC(void) {
    MgObj20 *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, 0);
    frame = &D_801D4B08;
    *frame = p->unk2;
    D_801ECB98 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801ECB98);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D481C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B1684);

void func_801B1968(void) {
    MgMat m;
    u8 pad[0x20];
    MgSVec rot;
    MgVec scale;
    MgTask *p;
    MgTask *q;
    s16 i;

    rot.vz = 0;
    rot.vx = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vy = p->unk2 << 8;
    func_8003C21C(&rot, &m);
    scale.vy = 0x3000;
    scale.vx = scale.vz = ((func_80039A74(p->unk2 << 7) << 14) + 0x2000) >> 12;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801ECB98 = (u8 *)func_800D29D4(D_801D4B5C, D_801517C0 + 0x70, 0xC, (s32)D_801ECB98);
    rot.vz = 0;
    rot.vx = 0;
    rot.vy = -p->unk2 << 8;
    func_8003C21C(&rot, &m);
    scale.vx = scale.vz = (func_80039A74(p->unk2 << 7) * 0x3000 + 0x2000) >> 12;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801ECB98 = (u8 *)func_800D29D4(D_801D4B5C, D_801517C0 + 0x70, 0xC, (s32)D_801ECB98);
    i = 0;
    if (D_80062D98 == 0) {
        p->unk6 += 0xBE;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B149C)];
            q->unk4 = p->unk4;
            q->unk8 = p->unk8;
            q->unk6 = p->unk6;
            q->unk18 = func_80042DA8() % 0x1000;
            q->unk1A = (func_80039A74(p->unk2 << 7) * 0x320 + 0x190) >> 12;
        } while (++i < 3);
        if (++p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B1C2C(void) {
    MgMat m;
    MgMat unused;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801D4B8C, &m);
    func_8003A79C(&D_801ED19C, &m, &m);
    func_8003B35C(&m, &D_801D4B6C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    D_801ECB98 = (u8 *)func_800D29D4(D_801D4B7C, D_801517C0 + 0x70, 0xC, (s32)D_801ECB98);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (++p->unk2 == 7) {
            p->unk0 = -1;
        }
    }
}

void func_801B1D74(void) {
    u8 pad0[8];
    MgSVec rot;
    MgSVec d;
    MgSVec v;
    u8 pad[0x20];
    s32 flag;
    MgTask *p;
    MgTask *q;
    MgTask *r;
    s16 i;
    s32 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            v.vx = 0;
            v.vy = 0;
            v.vz = 0xC8;
            D_801ED19C.t[0] = p->unk4;
            D_801ED19C.t[1] = p->unk6;
            D_801ED19C.t[2] = p->unk8;
            func_8003B48C(&D_801ED19C);
            func_8003B51C(&D_801ED19C);
            func_8003BADC(&v, (MgSVec *)&p->unk4, &flag);
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1350)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
        }
        if (p->unk2 < 0xF) {
            D_801ED19C.t[0] = p->unk4;
            D_801ED19C.t[1] = p->unk6;
            D_801ED19C.t[2] = p->unk8;
            func_8003B48C(&D_801ED19C);
            func_8003B51C(&D_801ED19C);
            d.vx = (p->unkC - p->unk4) / 8;
            d.vy = (p->unkE - p->unk6) / 8;
            d.vz = (p->unk10 - p->unk8) / 8;
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1C2C)];
                a = i * 0x555;
                rot.vx = (u32)(func_80039B40((p->unk2 << 9) + a) * 5) >> 8;
                rot.vy = (u32)(func_80039A74((p->unk2 << 9) + a) * 5) >> 8;
                rot.vz = func_80042DA8() % 100 - 0x32;
                func_8003BADC(&rot, (MgSVec *)&q->unk4, &flag);
                q->unkC = d.vx;
                q->unkE = d.vy;
                q->unk10 = d.vz;
            } while (++i < 3);
        }
        if ((u16)(p->unk2 - 9) < 9) {
            r = (MgTask *)&D_80162978[func_800BBEAC(func_801B15CC)];
            r->unk4 = p->unkC + func_80042DA8() % 800 - 0x190;
            r->unk6 = p->unkE + func_80042DA8() % 800 - 0x190;
            r->unk8 = p->unk10 + func_80042DA8() % 800 - 0x190;
        }
        if (p->unk2 == 0xD) {
            r = (MgTask *)&D_80162978[func_800BBEAC(func_801B1684)];
            r->unk4 = p->unkC;
            r->unk6 = p->unkE;
            r->unk8 = p->unk10;
            r = (MgTask *)&D_80162978[func_800BBEAC(func_801B1968)];
            r->unk4 = p->unkC;
            r->unk6 = p->unkE - 0x578;
            r->unk8 = p->unk10;
            func_800BBA84(0x187, p->unk1C, 0);
        }
        if (p->unk2 == 0x41) {
            func_800D5774(p->unk1C);
        }
        if (++p->unk2 == 0x46) {
            func_800D52A0(0, 0xA);
            p->unk0 = -1;
        }
    }
}

void func_801B221C(s32 arg0, s32 arg1) {
    MgSVec d;
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B1D74)];
    func_800D3994(arg1, D_80151915[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    d.vx = (p->unkC.vx - p->unk4.vx) / 8;
    d.vy = (p->unkC.vy - p->unk4.vy) / 8;
    d.vz = (p->unkC.vz - p->unk4.vz) / 8;
    func_800D44E8(&d, &D_801ED19C);
}

s32 func_801B2354(arg0, arg1) {
    func_800BBEAC(func_801B12E4);
    func_800D2980(&D_801B2400, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B221C);
    func_800BBA84(0x65, arg1, 0);
    func_801B1158();
    D_800F5B70 = D_800F5B71 = 0;
    D_800F5B72 = 0x40;
    return func_800D52A0(0xB00, 0xA);
}
