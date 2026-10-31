#include "common.h"
#include "magic_bushin2/decls.h"

M2C_UNK *func_801B0008(void) {
    func_801B352C();
    return &D_801D8A00;
}

void func_801B0030(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801F338C = D_801DB058[p->unk2];
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

MgMat *func_801B0094(MgSVec *pos, MgSVec *rot, s16 s) {
    MgVec scale;

    func_8003C21C(rot, &D_801DB354);
    scale.vx = scale.vy = scale.vz = s;
    func_8003B35C(&D_801DB354, &scale);
    D_801DB368[0] = pos->vx;
    D_801DB36C[0] = pos->vy;
    D_801DB370[0] = pos->vz;
    func_8003B48C(&D_801DB354);
    func_8003B51C(&D_801DB354);
    return &D_801DB354;
}

void func_801B0144(void) {
    MgMat m;
    MgMat lw;
    MgVec sc;
    u8 pad[8];
    MgTask *p;
    s16 *frame;
    s32 a;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_8003BF8C((MgSVec *)&p->unkC, &m);
    sc.vx = sc.vy = sc.vz = p->unk18 * p->unk1A / 100;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    frame = &D_801DB06A;
    *frame = p->unk2 * 0x199;
    D_801F338C = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801F338C);
    if (D_80062D98 == 0) {
        a = p->unk1A;
        n = p->unk2 + 1;
        p->unk2 = n;
        p->unk1A = a + (0x64 - a) / p->unk14;
        if (n == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B02F0(void) {
    MgMat m;
    MgMat lw;
    MgVec sc;
    u8 pad[8];
    MgTask *p;
    s16 *frame;
    s32 a;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_8003BF8C((MgSVec *)&p->unkC, &m);
    sc.vx = sc.vy = sc.vz = p->unk18 * p->unk1A / 150;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    frame = &D_801DB07A;
    *frame = p->unk2 * 0x111;
    D_80163C74 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        a = p->unk1A;
        n = p->unk2 + 1;
        p->unk2 = n;
        p->unk1A = a + (0x96 - a) / p->unk14;
        if (n == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B0494(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s32 *t;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D44E8((MgSVec *)&p->unkC, &m);
    t = &D_801DB098;
    *t = func_80039A74(p->unk2 * 0xCC) * p->unk18 >> 12;
    func_8003B35C(&m, (MgVec *)((u8 *)t - 8));
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801F338C = func_800D29D4(&D_801DB080, D_801517C0 + 0x70, 0xC, D_801F338C);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B060C(void) {
    MgMat m;
    u8 pad[0x20];
    s32 flag;
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    frame = &D_801DB0CC;
    *frame = p->unk14;
    func_8003C21C((MgSVec *)((u8 *)frame - 4), &m);
    D_801DB0B8.vx = func_80039A74(p->unk2 << 8) * 0x7F00 >> 0xC;
    func_8003B35C(&m, &D_801DB0B8);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    D_801F338C = func_800D29D4(&D_801DB0A8, D_801517C0 + 0x70, 0xC, D_801F338C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B0740(void) {
    MgMat m;
    u8 pad[0x20];
    s32 flag;
    MgTask *p;
    u16 *frame;
    s16 *light;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    frame = &D_801DB0F4;
    *frame = p->unk14;
    func_8003C21C((MgSVec *)((u8 *)frame - 4), &m);
    D_801DB0E0.vx = func_80039A74(p->unk2 << 8) * 0x7F00 >> 0xC;
    D_801DB0E4 = p->unk18;
    func_8003B35C(&m, &D_801DB0E0);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    light = &D_801DB0DA;
    *light = 0x1000 - (func_80039A74(p->unk2 << 8) << 12 >> 12);
    D_801F338C = func_800D29D4((u8 *)light - 0xA, D_801517C0 + 0x70, 0xC, D_801F338C);
    if (D_80062D98 == 0) {
        p->unk14 += 0x60;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B08B4(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    s32 ox;
    s32 oy;
    MgTask *p;
    s32 *t;
    s16 n;

    p = (MgTask *)&D_801F33A0[(s16)D_801F4CA0];
    func_8003B64C(&ox, &oy);
    func_8003B6BC(0xA0, 0x5A);
    func_800D44E8((MgSVec *)&p->unkC, &lw);
    rot.vx = -0x400;
    rot.vy = p->unk14 + 0x400;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    func_8003A79C(&lw, &m, &m);
    t = &D_801DB10C;
    *t = p->unk18;
    func_8003B35C(&m, (MgVec *)((u8 *)t - 4));
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    D_801F338C = func_800D29D4(&D_801DB0F8, D_801517C0 + 0x4070, 1, D_801F338C);
    func_8003B6BC(ox, oy);
    if (D_80062D98 == 0) {
        p->unk8 += p->unk10;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xC) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_RODATA("../asm/us/magic_bushin2/nonmatchings/text", D_801B0000);

void func_801B0A30(void) {
    u8 pad[0x20];
    MgSVec rot;
    u8 pad2[8];
    MgTask *p;
    MgTask *q;
    MgSVec *pos;
    u8 *col;
    u8 *fd;
    s32 n;
    s32 m;
    s32 i;
    s32 ang;
    s32 v;
    s32 c;

    rot = D_801B0000;
    p = &D_80162978[D_8015169C];
    pos = (MgSVec *)&p->unk4;
    rot.vz = -p->unk2 * 0x20;
    func_801B0094(pos, &rot, 0x4000);
    col = &D_801DB120;
    fd = col - 4;
    c = D_801DB118 << 3;
    *col = D_801DB121 = D_801DB122 = c;
    D_801F338C = func_800D4D90(fd, D_801517C0 + 0x4070, 1, D_801F338C);
    rot.vz = p->unk2 * 0x20;
    func_801B0094(pos, &rot, 0x3000);
    c = D_801DB118 << 3;
    *col = D_801DB121 = D_801DB122 = c;
    D_801F338C = func_800D4D90(fd, D_801517C0 + 0x4070, 1, D_801F338C);
    if (D_80062D98 == 0) {
        i = 0;
        n = (s16)(8 - (func_80039A74(p->unk2 * 14 + 0x400) * 8 >> 12));
        if (n > 0) {
            m = n;
            do {
                q = (MgTask *)&D_801F33A0[(s16)func_801B34BC()];
                q->unk8 = 0x36B0;
                q->unk4 = 0;
                q->unk6 = 0;
                q->unk10 = -0x4B0;
                q->unk18 = p->unk2 * 0x78 + 0x800;
                ang = func_80042DA8() % 0x1000;
                q->unk14 = ang;
                i++;
                v = func_80042DA8() % 500 + 0x1F4;
                q->unk4 += func_80039B40(ang) * v >> 12;
                q->unk6 += func_80039A74(ang) * v >> 12;
            } while (i < m);
        }
        if (p->unk2 < 0x10) {
            D_801DB118++;
        }
        p->unk2++;
        if (p->unk2 == 0x55) {
            p->unk0 = -1;
        }
    }
}

void func_801B0D34(void) {
    u8 pad[0x40];
    MgSVec pos;
    MgTask *p;
    MgTask *q;

    p = &D_80162978[D_8015169C];
    func_800D3994(D_801F3394, D_80151915[D_801F3394][0], &pos);
    pos.vy -= 0x2BC;
    func_800D4368(&pos, p->unk18, 0xC8);
    func_8003B69C(0, 0, 0);
    D_801F338C = func_800D29D4(&D_801DB128, D_801517C0 + 0x70, 0xC, D_801F338C);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0xA) {
            p->unk18 = p->unk18 * 0xC0 / 256;
            D_801DB138++;
        } else if (p->unk2 < 0x1C) {
            q = &D_80162978[func_800BBEAC(func_801B060C)];
            q->unk4 = pos.vx;
            q->unk6 = pos.vy;
            q->unk8 = pos.vz;
            q->unk14 = func_80042DA8() % 0x1000;
        }
        if (p->unk2 >= 0x20) {
            p->unk18 = p->unk18 * 0xE0 / 256;
        }
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0F3C(void) {
    MgTask *p;
    u16 *frame;
    u8 pad[0x40];

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk18, 0);
    func_8003B69C(0, 0, 0);
    frame = &D_801DB146;
    *frame = p->unk1A;
    D_801F338C = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801F338C);
    if (D_80062D98 == 0) {
        if (p->unk2 < 2) {
            p->unk18 += 0x2000;
        }
        if (p->unk2 >= 2) {
            p->unk1A += 0x2A8;
        }
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B103C(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk18, 0);
    frame = &D_801DB154;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC = p->unkC * 0xC0 / 256;
        p->unkE = p->unkE * 0xC0 / 256;
        p->unk10 = p->unk10 * 0xC0 / 256;
        if (++p->unk2 == D_801D87F0) {
            p->unk0 = -1;
        }
    }
}

void func_801B118C(MgTask *src, s16 speed, s16 vel, s16 n) {
    MgTask *q;
    s16 i;
    s16 ang;

    i = 0;
    if (n > 0) {
        do {
            q = &D_80162978[func_800BBEAC(func_801B103C)];
            q->unk4 = src->unk0;
            q->unk6 = src->unk2;
            q->unk8 = src->unk4;
            ang = func_80042DA8() % 0x1000;
            q->unkC = func_80039A74(ang) * speed >> 12;
            q->unk10 = func_80039B40(ang) * speed >> 12;
            q->unk18 = func_80042DA8() % 0x1800 + 0x1000;
            q->unkE = vel;
            i++;
        } while (i < n);
    }
}

void func_801B12E4(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk18, 0);
    frame = &D_801DB160;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D8728) {
            p->unk0 = -1;
        }
    }
}

void func_801B139C(void) {
    MgTask *p;
    MgTask *q;
    s16 w;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = &D_80162978[func_800BBEAC(func_801B12E4)];
        func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
        w = D_801518F6[p->unk1C][0];
        q->unk4 += func_80042DA8() % w * 2 - w;
        q->unk6 += func_80042DA8() % w * 2 - w;
        q->unk8 += func_80042DA8() % w * 2 - w;
        q->unk18 = p->unk18;
        p->unk2++;
        if (p->unk2 == p->unk14) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B1580);

void func_801B1818(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 *r;
    MgSVec *rot;

    r = &D_801DB176;
    rot = (MgSVec *)((u8 *)r - 2);
    p = &D_80162978[D_8015169C];
    *r = p->unk2 * 0x80;
    func_8003BF8C(rot, &m);
    D_801DB17C.vx = D_801DB184 = 0x6000;
    func_8003B35C(&m, &D_801DB17C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_801B1580(D_801DB18C);
    *r = p->unk2 * 0xC4;
    func_8003BF8C(rot, &m);
    D_801DB17C.vx = D_801DB184 = 0x7000;
    func_8003B35C(&m, &D_801DB17C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_801B1580(D_801DB18C);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x14) {
            D_801DB180 += (0x14 - p->unk2) * 0x64;
        }
        if (p->unk2 < 0x30) {
            func_801B118C((MgTask *)&p->unk4, 0x258, -0x64, 4);
        }
        if (p->unk2 >= 0x34) {
            D_801DB18C -= 0x10;
        }
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B1A70(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 *rot;
    s16 *frame;
    s32 t;

    p = &D_80162978[D_8015169C];
    rot = &D_801DB1A2;
    *rot = p->unk2 * 0x80;
    func_8003BF8C((MgSVec *)((u8 *)rot - 2), &m);
    t = func_80039A74(p->unk2 << 6) * 0x7F00 >> 12;
    D_801DB1B0 = t;
    D_801DB1A8.vx = t;
    func_8003B35C(&m, &D_801DB1A8);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801DB19A;
    *frame = (u32)func_80039A74(p->unk2 << 7) >> 5;
    D_801F338C = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801F338C);
    if (D_80062D98 == 0) {
        func_801B118C((MgTask *)&p->unk4, 0x258, -0x64, 1);
        p->unk2++;
        if (p->unk2 == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B1BD0(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 *rot;
    s16 *frame;
    s32 t;

    p = &D_80162978[D_8015169C];
    rot = &D_801DB1CA;
    *rot = p->unk2 * 0x80;
    func_8003BF8C((MgSVec *)((u8 *)rot - 2), &m);
    t = func_80039A74(p->unk2 << 6) * p->unk18 >> 12;
    D_801DB1D8 = t;
    D_801DB1D0.vx = t;
    func_8003B35C(&m, &D_801DB1D0);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    frame = &D_801DB1C2;
    *frame = p->unk2 * 0x100;
    D_801F338C = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801F338C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B1D2C(void) {
    u8 pad[0x40];
    MgSVec pos;
    MgTask *p;
    MgTask *q;
    u16 *frame;
    s16 t;
    s16 u;
    s32 z;

    p = &D_80162978[D_8015169C];
    func_800D3994(D_801F3394, D_80151915[D_801F3394][0], &pos);
    z = pos.vz;
    if (D_80151A46[D_801F3394][0] == 0) {
        z += 0x1F4;
    } else {
        z -= 0x1F4;
    }
    pos.vz = z;
    pos.vy += 0x2BC;
    func_800D4368(&pos, p->unk18, 0xC8);
    func_8003B69C(0, 0, 0);
    frame = &D_801DB1EA;
    *frame = D_801DB1F0;
    D_801F338C = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801F338C);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0xA) {
            p->unk18 += (s16)(0xA - t) * 0x14;
        }
        if (p->unk2 < 0x1C) {
            q = &D_80162978[func_800BBEAC(func_801B0740)];
            q->unk4 = pos.vx;
            q->unk6 = pos.vy;
            q->unk8 = pos.vz;
            q->unk14 = func_80042DA8() % 0x1000;
            q->unk18 = func_80042DA8() % 0x1000 + 0x2000;
        }
        u = p->unk2;
        if (u >= 0x20) {
            p->unk18 += (s16)(0x28 - u) * 0xC8;
            D_801DB1F0 += 0x200;
        }
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B1FC8(void) {
    MgTask *p;
    s32 t;
    s32 c;

    p = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(D_801DB1F2, D_801DB1F2, D_801DB1F2);
    if (D_80062D98 == 0) {
        t = func_80039A74(p->unk2 * 0x66) * 0x180 >> 0xC;
        D_801DB1F2 = t;
        c = (s16)t;
        if (c >= 0x100) {
            c = 0xFF;
        }
        D_801DB1F2 = c;
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B20A4);

void func_801B3388(void) {
    MgObj20 *q;
    MgTask *p;
    u16 t;

    q = D_801F33A0;
    D_801F4CA0 = 0;
    p = &D_80162978[D_8015169C];
    do {
        if (q->unk0 == 1) {
            func_801B08B4();
            if (q->unk0 == -1) {
                q->unk2 = 0;
                q->unk0 = 0;
            }
        }
        t = D_801F4CA0 + 1;
        D_801F4CA0 = t;
        q++;
    } while ((s16)t < 0xC8);
    if (D_801DB054 == 1) {
        p->unk0 = -1;
    }
}

void func_801B3464(void) {
    MgObj20 *p;
    s16 i;

    p = D_801F33A0;
    for (i = 0; i < 200; i++) {
        p->unk2 = 0;
        p->unk0 = 0;
        p++;
    }
    func_800BBEAC(&func_801B3388);
}

s32 func_801B34BC(void) {
    MgObj20 *p;
    s16 i;

    p = D_801F33A0;
    for (i = 0; i < 200; i++) {
        if (p->unk0 == 0) {
            p->unk0 = 1;
            return i;
        }
        p++;
    }
    return func_800BBA84(6, -1, 0x40);
}

INCLUDE_ASM("../asm/us/magic_bushin2/nonmatchings/text", func_801B352C);
