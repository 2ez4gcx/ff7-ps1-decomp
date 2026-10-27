#include "common.h"
#include "magic_kona/decls.h"

void func_801B0000(void) {
    func_801B0D14();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E1498 = D_801C9498 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(D_801C943E, 0, D_801C943E);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x10) {
            D_801C943E = (u16)D_801C943E + 3;
        }
        if (p->unk2 >= 0x55) {
            D_801C943E = (u16)D_801C943E - 3;
        }
        p->unk2 = (u16)p->unk2 + 1;
        if (p->unk2 == 0x64) {
            D_801C943C = 1;
            p->unk0 = -1;
        }
    }
}

void func_801B0178(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk1A == 0 ? 0x3000 : 0x2000, 0);
    frame = &D_801C9448;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801C944C[p->unk1A];
    D_801E1498 = (u8 *)func_800D4D90(q, D_801517C0 + 0x70, 0xC, (s32)D_801E1498);
    if (D_80062D98 == 0) {
        if (p->unk1A == 0) {
            p->unk6 += 0x14;
        }
        p->unk2++;
        if (p->unk2 == D_801C944C[p->unk1A][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0298(void) {
    MgMat m;
    MgMat r;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 a;
    s16 t;
    s32 w;
    s32 rr;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    t = p->unk2 * 0x12C + 0x800;
    m.m[0][0] = m.m[1][1] = m.m[2][2] = t;
    func_8003C21C(&D_801C9464, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    w = p->unk2;
    D_801C945E[0] = w << 7;
    D_801E1498 = (u8 *)func_800D29D4(&D_801C945E[-5], D_801517C0 + 0x70, 0xC, (s32)D_801E1498);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x14) {
            i = 0;
            do {
                a = func_80042DA8() % 0x1000;
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0178)];
                q->unk4 = p->unk4 + (func_80039A74(a) * 0x258 >> 12);
                rr = func_80042DA8();
                k = (u16)p->unk6 + p->unk2 * 0x32;
                q->unk6 = rr % 800 + k - 0x3E8;
                q->unk8 = p->unk8 + (func_80039B40(a) * 0x258 >> 12);
                q->unk1A = 0;
                i++;
            } while (i < 2);
        }
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0554(void) {
    MgSVec v;
    MgTask *p;
    u16 *frame;
    u16 *frame2;

    p = (MgTask *)&D_801E149C[(s16)D_801E275C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801C9474;
    M2C_SFIELD(frame, u16 *, 0) = p->unk1A;
    D_801E1498 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801E1498);
    v.vx = p->unk4 + (func_80039B40(p->unk14) * p->unk16 >> 12);
    v.vy = p->unk6 + (func_80039A74(p->unk14) * p->unk16 >> 12);
    v.vz = p->unk8;
    func_800D4368(&v, p->unk18, 0);
    frame2 = &D_801C9480;
    M2C_SFIELD(frame2, u16 *, 0) = p->unk2 % D_801C9188;
    D_801E1498 = (u8 *)func_800D4D90((u8 *)frame2 - 8, D_801517C0 + 0x70, 0xC, (s32)D_801E1498);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk14 += 0x100;
        if (++p->unk2 >> 1 == D_801C9000) {
            p->unk0 = -1;
        }
    }
}

void func_801B0728(void) {
    MgSVec rot;
    MgSVec v;
    MgMat m;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 s;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (!(((volatile MgTask *)p)->unk2 & 1)) {
            s = (func_80039A74(p->unk2 << 6) * 0x140 >> 12) + 0x140;
            q = (MgTask *)&D_801E149C[(s16)func_801B0CA4()];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk1A = p->unk2 >> 1;
            q->unk18 = s * 10 + 0x1000;
            q->unk16 = s;
            q->unk14 = func_80042DA8() % 0x1000;
            v.vx = 0;
            v.vy = 0;
            v.vz = p->unk18;
            rot.vx = 0;
            rot.vy = -func_80039A74(p->unk2 * 0x88) / 16;
            rot.vz = 0x200;
            func_8003C4AC(&rot, &m);
            func_8003C8DC(p->unk14, &m);
            m.t[0] = m.t[1] = m.t[2] = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&v, (MgSVec *)&q->unkC, &flag);
        }
        p->unk2++;
        if (p->unk2 == 0x20) {
            p->unk0 = -1;
        }
    }
}

void func_801B08EC(void) {
    MgTask *p;
    MgTask *q;
    u8 pad1[8];
    MgSVec pos;
    u8 pad2[0x20];

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0728)];
            q->unk14 = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            pos.vx = (u16)p->unkC - (u16)q->unk4;
            pos.vz = (u16)p->unk10 - (u16)q->unk8;
            q->unk18 = func_80039F5C(pos.vx * pos.vx + pos.vz * pos.vz) / 24;
        }
        if (p->unk2 == 0x46) {
            func_800D5774(p->unk1C);
        }
        if (p->unk2 == 0x30) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0298)];
            q->unk4 = p->unkC;
            q->unk6 = p->unkE;
            q->unk8 = p->unk10;
            func_800BBA84(0x19B, p->unk1C, 0);
        }
        p->unk2++;
        if (p->unk2 == 0x50) {
            p->unk0 = -1;
        }
    }
}

void func_801B0AB0(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B08EC)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B0B70(void) {
    MgObj20 *q;
    MgObj20 *p;

    q = D_801E149C;
    D_801E275C = 0;
    p = &D_80162978[D_8015169C];
    do {
        if (q->unk0 == 1) {
            func_801B0554();
            if (q->unk0 == -1) {
                q->unk2 = 0;
                q->unk0 = 0;
            }
        }
        D_801E275C++;
        q++;
    } while ((s16)D_801E275C < 0x96);
    if (D_801C943C == 1) {
        p->unk0 = -1;
    }
}

void func_801B0C4C(void) {
    MgObj20 *p;
    s16 i;

    p = D_801E149C;
    for (i = 0; i < 150; i++) {
        p->unk2 = 0;
        p->unk0 = 0;
        p++;
    }
    func_800BBEAC(&func_801B0B70);
}

s32 func_801B0CA4(void) {
    MgObj20 *p;
    s16 i;

    p = D_801E149C;
    for (i = 0; i < 150; i++) {
        if (p->unk0 == 0) {
            p->unk0 = 1;
            return i;
        }
        p++;
    }
    return func_800BBA84(6, -1, 0x40);
}

s32 func_801B0D14(arg0, arg1) {
    func_800BBEAC((void *)func_801B0020);
    func_800D2980(&D_801B0DA8, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B0AB0);
    func_800BBA84(0x11E, arg1, 0);
    func_801B0C4C();
    return func_800BBEAC((void *)func_801B008C);
}
