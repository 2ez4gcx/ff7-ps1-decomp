#include "common.h"
#include "magic_dia/decls.h"

void func_801B0000(void) {
    func_801B22F0();
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
    D_801EEB54 = D_801D6B54 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C8(void) {
    MgObj20 *p;
    s16 *frame;

    p = &D_80162978[D_8015169C];
    func_801B02FC((MgSVec *)&p->unk4, &D_801D6A20, func_80039A74(p->unk2 * 0x33) * 6, -0x3E8);
    func_8003B69C(0, 0, 0);
    frame = &D_801D6A1A;
    *frame = func_80039A74(p->unk2 * 0x33);
    D_801EEB54 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801EEB54);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B05D4(void) {
    MgObj20 *p;
    s16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, (s16)(func_80039A74(p->unk2 * 0xC) * 6), -0x3E8);
    func_8003B69C(0, 0, 0);
    frame = &D_801D6A32;
    *frame = 0x1000 - (func_80039A74(p->unk2 * 0x19) << 12 >> 12);
    D_801EEB54 = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801EEB54);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x50) {
            p->unk0 = -1;
        }
    }
}

void func_801B06E4(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B02FC((MgSVec *)&p->unk4, &D_801D6A50, func_80039A74(p->unk2 * 0x44) << 15 >> 16, -0x3E8);
    func_8003B69C(0, 0, 0);
    D_801EEB54 = func_800D29D4(D_801D6A40, D_801517C0 + 0x70, 0xC, D_801EEB54);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B07F0(void) {
    MgMat m;
    MgMat n;
    MgMat lw;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C4AC(&p->unkC, &n);
    D_801D6B3C.vx = 0;
    D_801D6B3C.vy = 0;
    D_801D6B40 = p->unk1A;
    func_8003B2CC(&n, &D_801D6B3C, &D_801D6B3C);
    D_801D6B3C.vx += D_801EEB60;
    /* struct reads keep these loads after the vx store, as in the game */
    D_801D6B3C.vy += ((DiHalf *)&D_801EEB62)->v;
    D_801D6B40 += ((DiHalf *)&D_801EEB64)->v;
    func_8003BF8C(&D_801D6A78, &m);
    func_8003A79C(&n, &m, &m);
    func_8003B35C(&m, &D_801D6A58);
    m.t[0] = D_801D6B3C.vx;
    m.t[1] = D_801D6B3C.vy;
    m.t[2] = (s16)D_801D6B40;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801D6A72[0] = func_80039B40(p->unk2 * 0x44);
    D_801EEB54 = func_800D29D4((u8 *)D_801D6A72 - 0xA, D_801517C0 + 0x70, 0xC, D_801EEB54);
    if (D_80062D98 == 0) {
        p->unk1A -= 0x215;
        p->unk2++;
        if (p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B09E0);

void func_801B0CC4(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 i;
    s32 *g;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D44E8((MgSVec *)&p->unkC, (M2C_UNK *)&m);
    g = &D_801D6A9C;
    *g = (func_80039A74(p->unk2 << 7) << 12 >> 12) + 0x1000;
    func_8003B35C(&m, (MgVec *)((u8 *)g - 8));
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    for (i = 0; i < 3; i++) {
        D_801D6AA4[0] = D_801D6AB4[p->unk16 * 3 + i];
        D_801EEB54 = func_800D29D4(D_801D6AA4, D_801517C0 + 0x70, 0xC, D_801EEB54);
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (++p->unk2 == 8 || p->unk6 > 0) {
            p->unk0 = -1;
        }
    }
}

void func_801B0EA0(void) {
    MgTask *p;
    u16 *frame;
    u16 t;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2800, 0);
    frame = &D_801D6AD4;
    t = p->unk2;
    *frame = t;
    if (p->unk16 != 0) {
        *frame = t | 0x8000;
        D_801D6AD6 = 0x40;
    }
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unkC -= p->unkC / 8;
        p->unkE -= p->unkE / 8;
        p->unk10 -= p->unk10 / 8;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (++p->unk2 >= D_801D6758) {
            p->unk0 = -1;
        }
    }
}

void func_801B1004(void) {
    MgMat m;
    MgMat lw;
    MgVec v;
    MgTask *p;

    p = &D_80162978[D_8015169C];
    if (p->unk2 >= 3) {
        func_8003C21C(&D_801D6AD8, &m);
        func_8003A79C(&D_801EEB90, &m, &m);
        v.vx = v.vy = v.vz = 0x6000 - p->unk2 * 0x258;
        func_8003B35C(&m, &v);
        m.t[0] = p->unk4;
        m.t[1] = p->unk6;
        m.t[2] = p->unk8;
        func_8003A63C(&D_800FA63C, &m, &lw);
        func_8003B48C(&lw);
        func_8003B51C(&lw);
        func_8003B69C(0, 0, 0);
        D_801D6AEA[0] = func_80039A74(p->unk2 * 0x33);
        D_801EEB54 = func_800D29D4((u8 *)D_801D6AEA - 0xA, D_801517C0 + 0x70, 0xC, D_801EEB54);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B118C(void) {
    MgMat m;
    MgMat lw;
    MgVec v;
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D6B00, &m);
    func_8003A79C(&D_801EEB90, &m, &m);
    v.vx = v.vz = 0x6000 - p->unk2 * 0x1C2;
    t = p->unk2;
    if (t >= 7) {
        t = 6;
    }
    v.vy = t * 0x708;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801D6AFA[0] = (u32)func_80039A74(p->unk2 * 0x33) >> 1;
    *(s32 *)&D_801D6AFA[-5] = (s32)&D_801D5668;
    D_801EEB54 = func_800D29D4(&D_801D6AFA[-5], D_801517C0 + 0x70, 0xC, D_801EEB54);
    *(s32 *)&D_801D6AFA[-5] = (s32)&D_801D5C6C;
    D_801EEB54 = func_800D29D4(&D_801D6AFA[-5], D_801517C0 + 0x70, 0xC, D_801EEB54);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B1374(void) {
    MgMat m;
    MgMat lw;
    u8 pad[8];
    MgTask *p;
    MgTask *q;
    u32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D6B34, &m);
    func_8003A79C(&D_801EEB90, &m, &m);
    func_8003B35C(&m, &D_801D6B08);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D6B22[0] = (u32)func_80039B40(p->unk2 * 0x33) >> 5;
    *(s32 *)&D_801D6B22[-5] = (s32)&D_801D35DC;
    D_801EEB54 = func_800D29D4(&D_801D6B22[-5], D_801517C0 + 0x70, 0xC, D_801EEB54);
    *(s32 *)&D_801D6B22[-5] = (s32)&D_801D4580;
    D_801EEB54 = func_800D29D4(&D_801D6B22[-5], D_801517C0 + 0x70, 0xC, D_801EEB54);
    *(s32 *)&D_801D6B22[-5] = (s32)&D_801D5524;
    D_801EEB54 = func_800D29D4(&D_801D6B22[-5], D_801517C0 + 0x70, 0xC, D_801EEB54);
    func_800D4368(&p->unk4, 0x4000, 0);
    c = (u32)func_80039A74(p->unk2 * 0x33) >> 5;
    D_801D6B2C[0] = D_801D6B2D = D_801D6B2E = c;
    D_801D6B30 = p->unk2 % 2;
    D_801EEB54 = func_800D4D90(&D_801D6B2C[-4], D_801517C0 + 0x70, 0xC, D_801EEB54);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B1004)];
        q->unk4 = p->unk4;
        q->unk6 = p->unk6;
        q->unk8 = p->unk8;
        if (++p->unk2 == 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B1634(void) {
    MgObj20 *p;
    s32 c;

    p = &D_80162978[D_8015169C];
    c = func_80039A74(p->unk2 * 0x44) * 0xFF0 >> 16;
    D_80163C74 = func_800C4FC8(c, c, c);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_dia/nonmatchings/text", func_801B16DC);

s32 func_801B22F0(arg0, arg1) {
    MgSVec d;
    MgTask *p;
    s32 t;
    u16 *q;

    func_800BBEAC((M2C_UNK *)func_801B045C);
    func_800D2980(&D_801B243C, 0, 0, 0);
    D_801EEB5C = arg1;
    D_801EEB58 = arg0;
    p = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B16DC)];
    p->unk1E = arg1;
    q = &D_801EEB60;
    func_800D3994(arg1, D_80151918[arg1][0], q);
    func_800D54EC(arg0, &p->unk4);
    d.vx = p->unk4 - *q;
    t = D_801EEB62 + 0x320;
    d.vy = p->unk6 - t;
    d.vz = p->unk8 - D_801EEB64;
    func_800D44E8(&d, &D_801EEB90);
    D_800F5B70[0] = D_800F5B70[1] = D_800F5B70[2] = 0;
    return func_800D52A0(0xE00, 0x14);
}
