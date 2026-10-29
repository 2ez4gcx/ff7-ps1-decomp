#include "common.h"
#include "magic_rakuseki/decls.h"

void func_801B0020(void) {
    func_801B1048();
}

void func_801B0040(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DAA3C = D_801C2A3C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_RODATA("../asm/us/magic_rakuseki/nonmatchings/text", D_801B0000);

MgMat *func_801B00AC(MgSVec *pos, MgSVec *rot, s16 scale) {
    MgMat m;
    s32 flag;

    m = D_801B0000;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(pos, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = scale;
    func_8003B05C(&m, &D_800FA63C);
    func_8003C21C(rot, &D_801C2A18);
    func_8003B05C(&m, &D_801C2A18);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801C2A2C = m.t[0];
    D_801C2A30 = m.t[1];
    D_801C2A34 = m.t[2];
    return &D_801C2A18;
}

void func_801B01D4(void) {
    MgSVec rot;
    MgTask *p;
    u16 *frame;
    s16 n;

    rot.vx = rot.vy = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vz = p->unk2 << 8;
    func_801B00AC((MgSVec *)&p->unk4, &rot, 0x1800);
    frame = &D_801C297C;
    *frame = p->unk14;
    D_801DAA3C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801DAA3C);
    if (D_80062D98 == 0) {
        p->unkE += 0x28;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (p->unk6 > 0) {
            p->unk6 = -p->unk6;
            p->unkE = -p->unkE;
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B02F8(MgTask *src, s16 vel) {
    MgTask *q;
    s16 i;
    s16 speed;
    s16 ang;
    s32 t;

    i = 0;
    do {
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B01D4)];
        q->unk4 = src->unk4;
        q->unk6 = src->unk6;
        q->unk8 = src->unk8;
        speed = func_80042DA8() % 100 + 0x64;
        ang = func_80042DA8() % 0x1000;
        q->unkC = func_80039B40(ang) * speed >> 12;
        t = func_80039A74(ang);
        q->unkE = vel;
        q->unk10 = t * speed >> 12;
        q->unk14 = func_80042DA8() % 16;
        i++;
    } while (i < 6);
}

void func_801B0464(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801C2988[0] = p->unk2;
    D_801DAA3C = func_800D4D90(&D_801C2988[-4], D_801517C0 + 0x70, 0xC, D_801DAA3C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C26A8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_rakuseki/nonmatchings/text", func_801B0520);

void func_801B07E4(void) {
    MgMat m;
    u8 pad[0x20];
    MgSVec rot;
    MgTask *p;
    MgTask *q;
    s32 *frame;
    s16 i;
    s16 n;
    s32 v;
    s32 t;

    rot.vx = rot.vy = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vz = p->unk16;
    func_8003C21C(&rot, &m);
    func_8003B35C(&m, &D_801C29CC);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    frame = &D_801C29DC;
    *frame = D_801C29EC[p->unk14];
    D_801DAA3C = func_800D29D4(frame, D_801517C0 + 0x70, 0xC, D_801DAA3C);
    if (D_80062D98 == 0) {
        p->unkE += 0xA;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk16 += p->unk18;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xA) {
            p->unk0 = -1;
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0520)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                t = p->unkC;
                v = i == 0 ? t + 0x28 : t - 0x28;
                q->unkC = v;
                q->unkE = p->unkE;
                q->unk10 = func_80042DA8() % 200 - 100;
                q->unk16 = p->unk16;
                q->unk18 = i == 0 ? 0x64 : -0x64;
                q->unk14 = i + p->unk14 * 2;
                i++;
            } while (i < 2);
            func_801B02F8(p, p->unkE);
        }
    }
}

void func_801B0A54(void) {
    MgMat m;
    u8 pad[0x20];
    MgSVec rot;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 n;

    rot.vx = rot.vy = rot.vz = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&rot, &m);
    func_8003B35C(&m, &D_801C29F8);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801DAA3C = func_800D29D4(&D_801C2A08, D_801517C0 + 0x70, 0xC, D_801DAA3C);
    if (D_80062D98 == 0) {
        p->unkE += 0x1E;
        p->unk6 += p->unkE;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 5) {
            p->unk0 = -1;
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B07E4)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unkC = i == 0 ? 0x32 : -0x32;
                q->unkE = -0x8C;
                q->unk10 = func_80042DA8() % 200 - 100;
                q->unk16 = 0;
                q->unk18 = i == 0 ? 0x64 : -0x64;
                q->unk14 = i;
                i++;
            } while (i < 2);
            func_801B02F8(p, -0x8C);
        }
    }
}

void func_801B0C58(void) {
    MgTask *p;
    s16 t;
    s16 n;
    s32 a;
    s32 b;
    u16 *g;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        a = 6 - t;
        b = (1 - t % 2 * 2) * 5;
        g = &D_801031EA;
        *g += a * b;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B0D04(void) {
    u8 pad[0x40];
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 n;
    s32 a;
    s32 b;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0A54)];
            func_800D3994(p->unk1A, D_8015190F[p->unk1A][0], &q->unk4);
            q->unk6 = -0x7D0;
            q->unkE = 0x64;
        }
        if (p->unk2 == 4) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0464)];
                func_800D3994(p->unk1A, D_8015190F[p->unk1A][0], &q->unk4);
                a = 0x190;
                q->unk4 = q->unk4 - a + func_80042DA8() % 800;
                b = 0x320;
                q->unk6 = q->unk6 - b + func_80042DA8() % 400;
                i++;
                c = 0x190;
                q->unk8 = q->unk8 - c + func_80042DA8() % 800;
            } while (i < 5);
        }
        if (p->unk2 == 5 || p->unk2 == 0x14) {
            func_800BBEAC(func_801B0C58);
        }
        if (p->unk2 == 5) {
            func_800D5774(p->unk1A);
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B0F88(s32 arg0, s32 arg1) {
    MgTask *q;

    q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0D04)];
    func_800D3994(arg1, D_80151914[arg1][0], &q->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &q->unkC);
    q->unk1A = arg0;
}

s32 func_801B1048(arg0, arg1) {
    func_800BBEAC(func_801B0040);
    func_800D2980(&D_801B2604, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B0F88);
    return func_800BBA84(0xD6, arg1, 0x40);
}
