#include "common.h"
#include "magic_kien/decls.h"

MgMat *func_801B006C(MgSVec *arg0, MgSVec arg1, s16 arg3) {
    s32 flag;
    s32 pad[4];
    MgMat *m;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(arg0, &D_801C20A4, &flag);
    m = (MgMat *)((u8 *)&D_801C20A4 - 0x14);
    *(s16 *)m = D_801C2098 = D_801C20A0 = arg3;
    func_8003B05C(m, &D_800FA63C);
    func_8003C21C(&arg1, &D_801C20F4);
    func_8003B05C(m, &D_801C20F4);
    func_8003B48C(m);
    func_8003B51C(m);
    return m;
}

void func_801B013C(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_801B006C((MgSVec *)&p->unk4, *(MgSVec *)&p->unkC, 0x1600);
    frame = &D_801C20B8;
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    D_801DA114 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801DA114);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C1FCC) {
            p->unk0 = -1;
        }
    }
}

void func_801B0214(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    frame = &D_801C20DC;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801C20BC[p->unk18];
    D_801DA114 = (u8 *)func_800D4D90(q, D_801517C0 + 0x70, 0xC, (s32)D_801DA114);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C20BC[p->unk18][1]) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B0308(void) {
    MgMat m;
    MgSVec rot;
    s32 scale[3];
    s32 n;
    MgTask *p;
    s32 v;
    s32 c;

    p = &D_80162978[D_8015169C];
    n = p->unk2;
    if (n >= 0xD) {
        n = 0xC;
    }
    rot.vx = (n << 10) / 12 + 0x400;
    rot.vy = p->unk1A;
    rot.vz = -p->unk2 << 9;
    func_8003C21C(&rot, &m);
    n <<= 8;
    n += 0x800;
    v = n * *(s16 *)D_801518F6[p->unk16] / 600;
    scale[0] = scale[1] = scale[2] = v;
    func_8003B35C(&m, scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    c = 0x80;
    D_801C20EE[0] = D_801C20E0 * 0x258;
    if (D_801C20E0 != 0) {
        c = 0x88;
    }
    D_801C20E8 = c;
    D_801DA114 = func_800D29D4(&D_801C20EE[-5], D_801517C0 + 0x70, 0xC, D_801DA114);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (p->unk2 >= 0xD) {
            D_801C20E0++;
        }
        p->unk2++;
        if (p->unk2 == 0x12) {
            p->unk0 = -1;
        }
    }
}

void func_801B055C(void) {
    MgMat m;
    MgSVec pos;
    MgSVec pad;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &D_80162978[func_800BBEAC(&func_801B013C)];
            q->unkC = 0;
            q->unkE = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            pos.vx = pos.vy = 0;
            pos.vz = 0xC8;
            func_8003C21C((MgSVec *)&q->unkC, &m);
            m.t[0] = m.t[1] = m.t[2] = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&pos, &pos, &flag);
            q->unk4 = p->unk4 + pos.vx;
            q->unk6 = p->unk6 + pos.vy;
            q->unk8 = p->unk8 + pos.vz;
        }
        if (p->unk2 == 2) {
            q = &D_80162978[func_800BBEAC(&func_801B0308)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unkC = (p->unkC - p->unk4) / 12;
            q->unkE = (p->unkE - p->unk6) / 12;
            q->unk10 = (p->unk10 - p->unk8) / 12;
            q->unk1A = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8) + 0x400;
            q->unk16 = p->unk16;
        }
        if (p->unk2 == 0x10) {
            func_800D4CBC(p->unk14, 9, 0x1000);
            func_800D5774(p->unk14);
        }
        if ((u16)p->unk2 - 0xB < 5U) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(&func_801B0214)];
                func_800D3994(p->unk14, D_8015190F[p->unk14][0], &q->unk4);
                i++;
                q->unk18 = func_80042DA8() % 6;
            } while (i < 2);
        }
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B087C(s32 arg0, s32 arg1) {
    MgTask *p;
    u8 pad[8];

    p = &D_80162978[func_800BBEAC(&func_801B055C)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk14 = arg0;
    p->unk16 = arg1;
}

INCLUDE_RODATA("../asm/us/magic_kien/nonmatchings/text", D_801B0000);

void func_801B0948(arg0, arg1) {
    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B09C4, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B087C);
    func_800BBA84(0x67, arg1, 0x40);
}
