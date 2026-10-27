#include "common.h"
#include "magic_geki2/decls.h"

void func_801B0000(void) {
    func_801B18DC();
}

void func_801B0020(s16 mask, MgSVec *out) {
    MgVec sum;
    MgSVec pos;
    s16 i;
    s16 n;

    n = 0;
    sum.vx = sum.vy = sum.vz = 0;
    for (i = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            func_800D3994(i, D_8015190F[i][0], &pos);
            n++;
            sum.vx += pos.vx;
            sum.vy += pos.vy;
            sum.vz += pos.vz;
        }
    }
    out->vx = sum.vx / n;
    out->vy = sum.vy / n;
    out->vz = sum.vz / n;
}

void func_801B01CC(s32 base, s16 range, MgSVec *out) {
    MgSVec v;
    MgSVec rot;
    MgMat m;

    v.vz = 0;
    v.vx = 0;
    v.vy = base + ((func_80042DA8() % range) * 2 - range);
    rot.vy = 0;
    rot.vx = func_80042DA8() % 800 - 400;
    rot.vz = func_80042DA8() % 800 - 400;
    func_8003BF8C(&rot, &m);
    func_8003B2CC(&m, &v, out);
}

void func_801B02FC(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist) {
    MgMat m;
    MgMat r;
    MgVec n;
    s32 flag;
    s16 i;

    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(pos, (MgVec *)m.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)m.t, &n);
        m.t[0] += (dist * n.vx) >> 12;
        m.t[1] += (dist * n.vy) >> 12;
        m.t[2] += (dist * n.vz) >> 12;
    }
    m.m[0][0] = m.m[1][1] = m.m[2][2] = scale;
    func_8003C21C(rot, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
}

void func_801B045C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EBB0C = D_801D3B0C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C8(void) {
    MgMat a;
    MgMat b;
    MgSVec rot;
    MgTask *p;
    s32 *q;
    s32 *tbl;
    s16 n;
    s32 t;

    rot.vz = 0;
    rot.vx = 0;
    rot.vy = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&rot, &a);
    D_801D3AE4.vx = D_801D3AE4.vy = D_801D3AE4.vz = p->unk2 * 0x280;
    func_8003B35C(&a, (s32 *)&D_801D3AE4);
    a.t[0] = p->unk4;
    a.t[1] = p->unk6;
    a.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &a, &b);
    func_8003B48C(&b);
    func_8003B51C(&b);
    q = &D_801D39CC;
    t = D_801D39DC[p->unk2 % 4];
    D_801D39D0.v = 0x28;
    *q = t;
    D_801D39D6 = func_80039B40(p->unk2 * 0x44) >> 5;
    D_801EBB0C = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801EBB0C);
    tbl = D_801D39DC;
    *q = tbl[(p->unk2 + 1) % 4];
    D_801D39D6 = (func_80039B40(p->unk2 * 0x44) * 3) >> 7;
    D_801EBB0C = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801EBB0C);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B06F8(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    frame = &D_801D39F4;
    *frame = p->unk2;
    D_801EBB0C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EBB0C);
    if (D_80062D98 == 0) {
        p->unkE -= p->unkE / 4;
        p->unk6 += p->unkE;
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == D_801D3840) {
            p->unk0 = -1;
        }
    }
}

void func_801B07DC(void) {
    MgMat m;
    s32 flag;
    MgTask *p;
    u16 *q;
    s16 *frame;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    q = &D_801D3A06;
    *q = p->unk1A;
    func_8003C21C((MgSVec *)&p->unkC, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003BADC((MgSVec *)((u8 *)q - 2), &D_801D3AF4, &flag);
    func_800D4368(&D_801D3AF4, 0x1200, 0);
    frame = &D_801D3A00;
    *frame = (s16)(u16)p->unk2 >> 1;
    D_801EBB0C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EBB0C);
    if (D_80062D98 == 0) {
        p->unkC += p->unk14;
        p->unk14 -= p->unk14 / 4;
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == D_801D3840 * 2) {
            p->unk0 = -1;
        }
    }
}

void func_801B0930(void) {
    MgObj20 *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2800, 0);
    frame = &D_801D3A14;
    *frame = p->unk2;
    D_801EBB0C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EBB0C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D3908) {
            p->unk0 = -1;
        }
    }
}

void func_801B09E8(void) {
    MgMat a;
    MgMat b;
    MgTask *p;
    MgHalf *frame;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D3A18, &b);
    D_801D3AFC.vx = D_801D3AFC.vz = (func_80039A74(p->unk2 * 0x44) << 15) >> 12;
    D_801D3AFC.vy = ((s32)func_80039B40(p->unk2 * 0x44) << 11) >> 12;
    func_8003B35C(&b, (s32 *)&D_801D3AFC);
    b.t[0] = p->unk4;
    b.t[1] = p->unk6;
    b.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &b, &a);
    func_8003B48C(&a);
    func_8003B51C(&a);
    frame = (MgHalf *)&D_801D3A2A;
    frame->v = func_80039B40(p->unk2 * 0x44) >> 5;
    D_801EBB0C = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801EBB0C);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B0B6C(void) {
    MgMat a;
    MgMat b;
    MgTask *p;
    MgHalf *frame;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D3A40, &b);
    D_801D3A30.vx = D_801D3A30.vz = p->unk18;
    func_8003B35C(&b, (s32 *)&D_801D3A30);
    b.t[0] = p->unk4;
    b.t[1] = p->unk6;
    b.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &b, &a);
    func_8003B48C(&a);
    func_8003B51C(&a);
    func_8003B69C(0, 0, 0);
    frame = &D_801D3A52;
    frame->v = func_80039A74(p->unk2 * 0x33);
    D_801EBB0C = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801EBB0C);
    if (D_80062D98 == 0) {
        p->unk1A -= p->unk1A / 16;
        p->unk18 += p->unk1A;
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0CDC(void) {
    MgMat a;
    MgMat b;
    MgTask *p;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D3A88, &b);
    D_801D3A58.vx = D_801D3A58.vz = p->unk2 << 9;
    func_8003B35C(&b, (s32 *)&D_801D3A58);
    b.t[0] = p->unk4;
    b.t[1] = p->unk6;
    b.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &b, &a);
    func_8003B48C(&a);
    func_8003B51C(&a);
    D_801D3A72[0] = 0x80 - p->unk2 * 6;
    *(s32 *)&D_801D3A72[-5] = D_801D3A78[p->unk2 % 4];
    D_801EBB0C = func_800D29D4(&D_801D3A72[-5], D_801517C0 + 0x70, 0xC, D_801EBB0C);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B0E48(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D3A98;
    *frame = p->unk16;
    D_801D3A94 = D_801D3A95 = D_801D3A96 = func_80039B40(p->unk2 << 6) >> 5;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x12C;
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B0F38(void) {
    MgMat a;
    MgMat b;
    MgTask *p;
    MgHalf *frame;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D3ABC, &b);
    D_801D3A9C.vx = D_801D3A9C.vz = p->unk2 * 0x190 + 0x800;
    D_801D3A9C.vy = (((s32)func_80039B40(p->unk2 * 0x44) << 10) >> 12) + 0x400;
    func_8003B35C(&b, (s32 *)&D_801D3A9C);
    b.t[0] = p->unk4;
    b.t[1] = p->unk6;
    b.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &b, &a);
    func_8003B48C(&a);
    func_8003B51C(&a);
    frame = &D_801D3AB6;
    frame->v = func_80039B40(p->unk2 * 0x44) >> 5;
    D_801EBB0C = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801EBB0C);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xF) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_geki2/nonmatchings/text", func_801B10BC);

s32 func_801B18DC(arg0, arg1) {
    MgObj20 *p;

    func_800BBEAC(func_801B045C);
    func_800D2980(&D_801B19F8, 0, 0, 0);
    D_801EBB10 = arg0;
    p = &D_80162978[func_800BBEAC(func_801B10BC)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D54EC(arg0, &p->pad[4]);
    D_8009A000 = 0x21;
    D_8009A004 = 0x40;
    D_8009A008 = 0x173;
    D_8009A00C = 0x7C;
    func_8002DA7C();
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    return func_800D52A0(0x1000, 0x10);
}
