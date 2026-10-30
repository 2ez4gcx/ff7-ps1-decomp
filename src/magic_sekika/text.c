#include "common.h"
#include "magic_sekika/decls.h"

void func_801B0008(void) {
    func_801B2914();
}

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_sekika/nonmatchings/text", func_801B0A50);

void func_801B1160(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E586C = D_801CD86C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_RODATA("../asm/us/magic_sekika/nonmatchings/text", D_801B0000);

INCLUDE_RODATA("../asm/us/magic_sekika/nonmatchings/text", D_801B0004);

void func_801B11CC(void) {
    MgPtrPair tbl;
    MgTask *p;
    s32 **hdr;

    tbl = D_801B0000;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2400, 0);
    hdr = &D_801CD778;
    M2C_SFIELD(hdr, s32 **, 0) = tbl.ptr[p->unk1A];
    D_801CD780 = p->unk2;
    D_801E586C = (u8 *)func_800D4D90(hdr, D_801517C0 + 0x70, 0xC, (s32)D_801E586C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= tbl.ptr[p->unk1A][1]) {
            if (p->unk1A == 0) {
                p->unk1A = 1;
                p->unk2 = 0;
            } else {
                p->unk0 = -1;
            }
        }
    }
}

void func_801B12E8(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    frame = &D_801CD78C;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801CD790[p->unk1A];
    D_801E586C = (u8 *)func_800D4D90(q, D_801517C0 + 0x70, 0xC, (s32)D_801E586C);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == D_801CD790[p->unk1A][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B1408(void) {
    MgSVec v;
    MgTask *p;
    u16 *frame;
    s16 n;

    p = &D_80162978[D_8015169C];
    v.vx = p->unk4 + (func_80039B40(p->unk16) * p->unk18 >> 12);
    v.vz = p->unk8 + (func_80039A74(p->unk16) * p->unk18 >> 12);
    v.vy = p->unk6;
    func_800D4368(&v, 0x2000, 0);
    frame = &D_801CD7A4;
    *frame = p->unk2;
    D_801E586C = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801E586C);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x32;
        p->unk16 += 0x100;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == D_801CD6B4) {
            p->unk0 = -1;
        }
    }
}

void func_801B1538(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    frame = &D_801CD7B0;
    *frame = p->unk2;
    D_801E586C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801E586C);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        n = p->unk2 + 1;
        p->unkE += 0x14;
        p->unk2 = n;
        if (n == D_801CD6B4) {
            p->unk0 = -1;
        }
    }
}

void func_801B162C(void) {
    MgTask *p;
    MgMat m;
    MgMat rot;
    s32 flag;
    s16 i;
    s32 t;

    p = &D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = p->unk2 * 600 + 0x800;
    func_8003C21C(&D_801CD7C4, &rot);
    func_8003B05C(&m, &rot);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801CD7BE[0] = t << 8;
    D_801E586C = func_800D29D4(&D_801CD7BE[-5], D_801517C0 + 0x70, 0xC, D_801E586C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 15) {
            p->unk0 = -1;
        }
    }
}

void func_801B17A4(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 r;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        p->unk6 += 0xBE;
        do {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1408)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            r = func_80042DA8();
            q->unk16 = r % 0x1000;
            q->unk18 = (func_80039A74(p->unk2 << 7) * 0x320 + 0x190) >> 12;
        } while (++i < 3);
        p->unk2++;
        if (p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B18D0(void) {
    s16 i;
    s16 r;
    s16 a;

    i = 0;
    do {
        r = func_80042DA8() % 180;
        a = func_80042DA8() % 0x1000;
        D_801E5870[i][0] = D_801E5870[i][1] = D_801E5870[i][2] = 0;
        D_801E5C70[i][0] = func_80039B40(a) * r >> 12;
        D_801E5C74[i][0] = func_80039A74(a) * r >> 12;
        D_801E5C70[i][1] = -func_80042DA8() % 100 - 0x64;
    } while (++i < 0x80);
}

void func_801B1A5C(void) {
    s16 i;

    i = 0;
    do {
        D_801E5870[i][0] += D_801E5C70[i][0];
        D_801E5870[i][1] += D_801E5C70[i][1];
        D_801E5874[i][0] += D_801E5C74[i][0];
        D_801E5C70[i][1] += 0x14;
        if (D_801E5870[i][1] > 0) {
            D_801E5870[i][1] = 0;
            D_801E5C70[i][1] = -D_801E5C70[i][1];
        }
        i++;
    } while (i < 0x80);
}

void func_801B1B98(void) {
    MgMat m;
    MgMat n;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 a;
    s16 r;
    s16 t;
    s32 *e;
    s32 *b;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801CD7CC, &m);
    func_8003B35C(&m, &D_801CD7D4);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    if (p->unk2 < 0x1E) {
        func_8003B48C(&m);
        func_8003B51C(&m);
        t = p->unk2;
        b = D_801CD7F4;
        if (t < 0x10) {
            e = b + (t >> 1);
        } else {
            e = b + 7;
        }
        D_801CD7E4 = *e;
        D_801E586C = (u8 *)func_800D29D4(&D_801CD7E4, D_801517C0 + 0x70, 0xC, (s32)D_801E586C);
    } else {
        D_801CD7EE[0] = 0x80 - (p->unk2 - 0x1E) * 8;
        func_8003C21C(&D_801CD7CC, &n);
        func_8003C73C((p->unk2 - 0x1E) << 8, &n);
        D_801E586C = func_801B0028(&D_801CD7EE[-5], D_801517C0 + 0x70, 0xC, D_801E586C, D_801E5870, &m, &n);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x1E) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1538)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                a = func_80042DA8() % 0x1000;
                r = func_80042DA8() % 400;
                q->unkC = func_80039B40(a) * r >> 12;
                q->unk10 = func_80039A74(a) * r >> 12;
                q->unkE = -func_80042DA8() % 400;
            } while (++i < 0x18);
        }
        if (p->unk2 >= 0x1E) {
            func_801B1A5C();
        }
        p->unk2++;
        if (p->unk2 == 0x2D) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B1EE0(void) {
    MgMat m;
    u8 pad[0x20];
    MgSVec rot;
    MgSVec rot2;
    MgSVec v;
    MgVec scale;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 k;
    s32 *e;
    SkFrame *f;
    s16 *h;
    s32 w;
    u16 t;

    p = &D_80162978[D_8015169C];
    k = ((s16)*(u16 *)&p->unk1A >> 1) * 2 - 1;
    rot2.vx = rot.vx = func_80039A74(p->unk2 << 8) / 40 * k;
    rot2.vy = rot.vy = (func_80039A74(p->unk2 << 7) >> 5) * k;
    rot2.vz = rot.vz = 0;
    rot.vx -= 0x400;
    func_8003C21C(&rot, &m);
    func_8003A79C(&D_801CD84C, &m, &m);
    scale.vy = p->unk14;
    scale.vx = scale.vz = 0x3000;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    f = &D_801CD818;
    e = (s32 *)D_801CAA9C;
    if (!(*(u16 *)&p->unk1A & 1)) {
        e = (s32 *)D_801CAD90;
    }
    h = &f->val;
    f->ptr = e;
    if (!(*(u16 *)&p->unk1A & 1)) {
        w = 0x1000 - (D_801CD814 << 5);
    } else {
        w = 0x1000 - D_801CD814 * 0x18;
    }
    *h = w;
    D_801E586C = (u8 *)func_800D29D4(&D_801CD818, D_801517C0 + 0x70, 0xC, (s32)D_801E586C);
    if (D_80062D98 == 0) {
        if (!(*(u16 *)&p->unk1A & 1)) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B11CC)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            v.vx = 0;
            v.vy = 0;
            v.vz = p->unk18;
            func_8003C21C(&rot2, &m);
            func_8003A79C(&D_801CD84C, &m, &m);
            m.t[0] = q->unk4;
            m.t[1] = q->unk6;
            m.t[2] = q->unk8;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&v, (MgSVec *)&q->unk4, &flag);
            q->unkC = 0;
            t = p->unkE;
            q->unk10 = 0;
            q->unk1A = 0;
            q->unkE = t;
        }
        if (p->unk2 < 8) {
            D_801CD814++;
        }
        if (p->unk2 >= 0x19) {
            D_801CD814--;
        }
        p->unk2++;
        if (p->unk2 == 0x20) {
            p->unk0 = -1;
        }
    }
}

void func_801B2240(void) {
    MgSVec a;
    MgSVec b;
    MgMat m;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 dx;
    s16 dy;
    s16 dz;
    s16 r;
    s16 i;
    s16 s;
    s32 n;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            dx = p->unkC - p->unk4;
            D_801CD844.v = dx;
            dy = p->unkE - p->unk6;
            D_801CD846.v = dy;
            dz = p->unk10 - p->unk8;
            D_801CD848.v = dz;
            r = func_80039F5C(dx * dx + dy * dy + dz * dz);
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1EE0)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unkE = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
                q->unk1A = i;
                q->unk18 = r;
                q->unk14 = r * 0x1500 / 2800;
            } while (++i < 4);
        }
        if (p->unk2 == 0x2D) {
            n = func_800BBEAC((M2C_UNK *)func_801B162C);
            q = (MgTask *)D_8016297C;
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q[n]);
            func_800BBA84(0x188, p->unk1C, 0);
        }
        if ((u16)p->unk2 - 0x2D < 0xCU) {
            k = 0x258;
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B12E8)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            q->unk4 = q->unk4 - k + func_80042DA8() % 1200;
            q->unk6 = q->unk6 - k + func_80042DA8() % 1200;
            q->unk8 = q->unk8 - k + func_80042DA8() % 1200;
            q->unk1A = func_80042DA8() % 3;
            q->unk14 = (func_80042DA8() % 3 << 11) + 0x1000;
            s = func_80042DA8() % 0x1000;
            a.vx = (u32)(func_80039B40(s) * 0xF) >> 10;
            a.vy = (u32)(func_80039A74(s) * 0xF) >> 10;
            a.vz = 0;
            b.vz = 0;
            b.vx = 0;
            b.vy = func_80042DA8() % 0x1000;
            func_8003C21C(&b, &m);
            m.t[0] = m.t[1] = m.t[2] = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&a, (MgSVec *)&q->unkC, &flag);
        }
        if (p->unk2 == 0x37) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1B98)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B17A4)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            q->unk6 -= 0x578;
            func_800BBA84(0x13C, p->unk1C, 0);
        }
        if (p->unk2 == 0x55) {
            func_800D5774(p->unk1C);
            func_800BBA84(0x189, p->unk1C, 0);
        }
        p->unk2++;
        if (p->unk2 == 0x64) {
            p->unk0 = -1;
            func_800D52A0(0, 0xA);
        }
    }
}

void func_801B27FC(arg0, arg1) {
    MgSVec d;
    SkObj *p;

    p = (SkObj *)&D_80162978[func_800BBEAC(&func_801B2240)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    d.vx = p->unkC - p->unk4;
    d.vy = p->unkE - p->unk6;
    d.vz = p->unk10 - p->unk8;
    func_800D44E8(&d, &D_801CD84C);
    func_800BBA84(0x62, arg1, 0);
}

void func_801B2914(arg0, arg1) {
    u8 pad[8];

    func_800BBEAC(func_801B1160);
    func_800D2980(&D_801B29BC, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B27FC);
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    func_800D52A0(0x1000, 0xA);
    func_800BBA84(0x62, arg1, 0x40);
    func_801B18D0();
}
