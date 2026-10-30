#include "common.h"
#include "magic_triangle/decls.h"

void func_801B0000(void) {
    func_801B1340();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EB1C0 = D_801D31C0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;
    s8 c;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D30C8;

    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    c = 0x60;
    if (p->unk14 == 4) {
        c = 0x40;
    }
    q = (s32 **)((u8 *)frame - 8);
    D_801D30C4[0] = D_801D30C4[1] = D_801D30C4[2] = c;
    *q = D_801D30CC[p->unk14];
    D_801EB1C0 = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_801EB1C0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D30CC[p->unk14][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B01A8(void) {
    MgMat m;
    MgMat r;
    s32 flag;
    MgTask *p;
    s16 *frame;
    s16 i;

    p = &D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = p->unk2 * 0x258 + 0x800;
    func_8003C21C(&D_801D30F0, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    frame = &D_801D30EA;
    *frame = p->unk2 * 0x100;
    D_801EB1C0 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801EB1C0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x10) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_triangle/nonmatchings/text", func_801B0320);

void func_801B07A0(void) {
    MgMat m[2];
    MgSVec unused;
    s32 flag;
    MgTask *p;
    u16 *frame;
    s32 **q;
    s16 i;

    p = &D_801621F0[D_801590D4];
    for (i = 0; i < 3; i++) {
        m[1].m[0][i] = m[1].m[1][i] = m[1].m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m[1].t, &flag);
    m[1].m[0][0] = m[1].m[1][1] = m[1].m[2][2] = 0x3000;
    func_8003C21C((MgSVec *)&p->unkC, &m[0]);
    func_8003B05C(&m[1], &m[0]);
    func_8003B48C(&m[1]);
    func_8003B51C(&m[1]);
    frame = &D_801D314C;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801D3150[p->unk14];
    D_80163C74 = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D3150[p->unk14][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B091C(void) {
    MgMat m;
    MgSVec rot;
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    rot.vy = p->unk2 << 6;
    rot.vx = rot.vz = 0;
    func_8003BF8C(&rot, &m);
    D_801D315C.vx = D_801D315C.vz = 0x1800;
    func_8003B35C(&m, &D_801D315C);
    m.t[0] = p->unk4;
    m.t[1] = 0;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801D3176[0] = D_801D3158 * 6;
    *(s32 *)&D_801D3176[-5] = (s32)D_801D317C[(s16)(p->unk2 % 4)];
    D_801EB1C0 = func_800D29D4(&D_801D3176[-5], D_801517C0 + 0x70, 0xC, D_801EB1C0);
    rot.vy = -p->unk2 << 6;
    rot.vx = rot.vz = 0;
    func_8003BF8C(&rot, &m);
    D_801D315C.vx = D_801D315C.vz = 0x2800;
    func_8003B35C(&m, &D_801D315C);
    m.t[0] = p->unk4;
    m.t[1] = 0;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    t = p->unk2;
    *(s32 *)&D_801D3176[-5] = (s32)D_801D317C[(t + 2) % 4];
    D_801EB1C0 = func_800D29D4(&D_801D3176[-5], D_801517C0 + 0x70, 0xC, D_801EB1C0);
    if (D_80062D98 == 0) {
        if (p->unk2 < 8) {
            D_801D3158 += 1;
        }
        if (p->unk2 >= 0xD) {
            D_801D3158 -= 1;
        }
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0BDC(void) {
    MgTask *p;
    MgTask *q;
    s16 *frame;
    s16 t;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, (s16)(func_80039A74(p->unk2 * 0x66) * 4), 0);
    frame = &D_801D3194;
    *frame = p->unk2 % 2;
    D_801EB1C0 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EB1C0);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0xC) {
            q = &D_801621F0[func_800BC04C(func_801B07A0)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            t = p->unk8;
            q->unkE = 0;
            q->unkC = 0;
            q->unk8 = t;
            q->unk10 = D_801D3198[p->unk2] * 0x154 + func_80042DA8() % 200 - 0x64;
            q->unk14 = func_80042DA8() % 2;
        }
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0DC4(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 r1;
    s32 r2;
    s32 r3;
    s32 r4;
    s32 r5;
    s32 r6;
    s32 r7;
    s32 k1;
    s32 k2;
    s32 k3;
    s32 k4;
    s32 k5;
    s32 k6;
    u8 pad[0x30];

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &D_80162978[func_800BBEAC(func_801B0320)];
            q->unk6 = -0x258;
            q->unk4 = 0;
            q->unk8 = -0x6A4;
            q->unkC = (p->unkC - q->unk4) / 5;
            q->unkE = (-0x7D0 - q->unk6) / 5;
            q->unk10 = (p->unk10 - q->unk8) / 5;
            q->unk16 = 0;
            q->unk18 = 0x6000;
            D_800F5B70[0] = 0x20;
            D_800F5B70[1] = D_800F5B70[2] = 8;
            func_800D52A0(0x1000, 0x14);
        }
        if (p->unk2 == 0x26) {
            q = &D_80162978[func_800BBEAC(func_801B091C)];
            q->unk4 = p->unkC;
            q->unk6 = p->unkE;
            q->unk8 = p->unk10;
            q = &D_80162978[func_800BBEAC(func_801B0BDC)];
            q->unk4 = p->unkC;
            q->unk6 = p->unkE;
            q->unk8 = p->unk10;
        }
        if (p->unk2 == 0x3C) {
            q = &D_80162978[func_800BBEAC(func_801B01A8)];
            q->unk4 = p->unkC;
            q->unk6 = p->unkE;
            q->unk8 = p->unk10;
        }
        if (p->unk2 == 0x3F) {
            func_800D5774(p->unk1C);
            func_800BBA84(0x95, p->unk1C, 0);
        }
        if ((u32)((u16)p->unk2 - 0x3B) < 4) {
            q = &D_80162978[func_800BBEAC(func_801B008C)];
            q->unk4 = p->unkC;
            q->unk6 = p->unkE;
            q->unk8 = p->unk10;
            r1 = func_80042DA8();
            k1 = (u16)q->unk4 - 0x12C;
            q->unk4 = k1 + r1 % 600;
            r2 = func_80042DA8();
            k2 = (u16)q->unk6 - 0x12C;
            q->unk6 = k2 + r2 % 600;
            r3 = func_80042DA8();
            k3 = (u16)q->unk8 - 0x12C;
            q->unk8 = k3 + r3 % 600;
            r4 = func_80042DA8();
            q->unk14 = r4 % 4;
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(func_801B008C)];
                q->unk4 = p->unkC;
                q->unk6 = p->unkE;
                q->unk8 = p->unk10;
                r5 = func_80042DA8();
                k4 = (u16)q->unk4 - 0x320;
                q->unk4 = k4 + r5 % 1600;
                r6 = func_80042DA8();
                k5 = (u16)q->unk6 - 0x320;
                q->unk6 = k5 + r6 % 1600;
                r7 = func_80042DA8();
                i++;
                q->unk14 = 4;
                k6 = (u16)q->unk8 - 0x320;
                q->unk8 = k6 + r7 % 1600;
            } while (i < 2);
        }
        p->unk2++;
        if (p->unk2 == 0x50) {
            func_800D52A0(0, 0xA);
            p->unk0 = -1;
        }
    }
}

void func_801B1280(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0DC4)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

s32 func_801B1340(arg0, arg1) {
    func_800BBEAC(func_801B0020);
    func_800D2980(&D_801B13BC, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B1280);
    return func_800BBA84(0xFF, arg1, 0);
}
