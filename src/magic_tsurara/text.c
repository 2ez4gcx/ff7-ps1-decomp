#include "common.h"
#include "magic_tsurara/decls.h"

void func_801B0000(void) {
    func_801B0C38();
}

void func_801B0020(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801E9B4C = D_801D1B4C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 0xA);
        p->unk0 = -1;
    }
}

MgMat *func_801B00B0(MgSVec *arg0, MgSVec *arg1, s16 arg2) {
    s32 flag;
    MgMat *m;
    s16 i;

    for (i = 0; i < 3; i++) {
        D_801D1B0C[i] = D_801D1B0C[i + 3] = D_801D1B0C[i + 6] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(arg0, &D_801D1B20, &flag);
    m = (MgMat *)((u8 *)&D_801D1B20 - 0x14);
    *(s16 *)m = D_801D1B14 = D_801D1B1C = arg2;
    func_8003C21C(arg1, m);
    func_8003B48C(m);
    func_8003B51C(m);
    return m;
}

void func_801B01A8(void) {
    MgSVec rot;
    MgTask *p;
    s16 c;
    MgColTag *q;

    rot.vy = 0;
    rot.vx = 0;
    p = &D_801621F0[D_801590D4];
    rot.vz = p->unk2 << 8;
    func_801B00B0((MgSVec *)&p->unk4, &rot, 0x1800);
    q = &D_801D1A88;
    q->tag = D_801D1A94[p->unk14];
    D_801D1A88.r = D_801D1A88.g = D_801D1A88.b = (p->unk2 >= 12) ? (20 - (u8)p->unk2) * 0x10 : 0x80;
    D_80163C74 = func_800D4D90(&D_801D1A88, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unkE += 0x28;
        p->unk4 += p->unkC;
        p->unk8 += p->unk10;
        c = p->unk2 + 1;
        p->unk2 = c;
        p->unk6 += p->unkE;
        if (c == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B0304(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D1AA4;
    *frame = p->unk2;
    D_801E9B4C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E9B4C);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= D_801D18C4) {
            p->unk0 = -1;
        }
    }
}

void func_801B03F0(void) {
    MgMat m;
    u8 pad[0x20];
    MgSVec rot;
    MgTask *p;
    TsFrame *q;
    MgHalf *f;
    s16 t;
    s16 c;
    s16 n;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unk18;
    rot.vy = p->unk16;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    func_8003B35C(&m, &D_801D1AAC);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    q = &D_801D1ABC;
    q->tag = D_801D1ACC[p->unk14];
    t = p->unk2;
    f = (MgHalf *)((u8 *)q + 0xA);
    if (t >= 0x11) {
        n = 0x19 - t;
        c = n << 4;
    } else {
        c = 0x80;
    }
    f->v = c;
    D_801E9B4C = func_800D29D4(&D_801D1ABC, D_801517C0 + 0x70, 0xC, D_801E9B4C);
    if (D_80062D98 == 0) {
        if (p->unk6 < 0x64) {
            p->unkE += 0x32;
            p->unk6 += p->unkE;
        } else {
            p->unk18 += 0x40;
        }
        c = p->unk2 + 1;
        p->unk2 = c;
        if (c == 0x19) {
            p->unk0 = -1;
        }
    }
}

void func_801B058C(void) {
    MgMat m;
    MgTask *p;
    MgHalf *frame;
    s16 n;

    p = &D_80162978[D_8015169C];
    D_801D1ADC.m[0][0] = D_801D1ADC.m[1][1] = D_801D1ADC.m[2][2] = p->unk2 * 0x7D0;
    D_801D1ADC.t[0] = p->unk4;
    D_801D1ADC.t[1] = p->unk6;
    D_801D1ADC.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801D1ADC, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    frame = (MgHalf *)&D_801D1B06;
    frame->v = p->unk2 * 0x111;
    D_801E9B4C = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801E9B4C);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xF) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_tsurara/nonmatchings/text", func_801B06D0);

void func_801B0B78(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B06D0)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1A = arg0;
}

s32 func_801B0C38(arg0, arg1) {
    func_800BBEAC(func_801B0020);
    func_800D2980(&D_801B0CDC, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0B78);
    func_800BBA84(0x16E, arg1, 0x40);
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    D_800F5B72 = 0x40;
    return func_800D52A0(0x1000, 0xA);
}
