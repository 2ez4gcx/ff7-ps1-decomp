#include "common.h"
#include "magic_re_do/decls.h"

void func_801B0000(void) {
    func_801B1A54();
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
    D_801ED738 = D_801D5738 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C8(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(0, 0, D_801D5620);
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 < 0x10) {
            D_801D5620 = (u16) D_801D5620 + 0xF;
        }
        if (temp_s0->unk2 >= 0x23) {
            D_801D5620 = (u16) D_801D5620 - 0xF;
        }
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 == 0x32) {
            temp_s0->unk0 = -1;
        }
    }
}

void func_801B05A8(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2800, 0);
    D_801D562C[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D562C[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D5264) {
            p->unk0 = -1;
        }
    }
}

void func_801B0664(void) {
    MgMat lw;
    MgMat m;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    u8 *rgb;
    s16 i;
    s16 n;

    p = &D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[2][i] = 0;
        m.m[1][i] = 0;
        m.m[0][i] = 0;
    }
    n = 8;
    if (p->unk2 >= 12) {
        n = 20 - p->unk2;
    }
    rot.vy = 0;
    rot.vx = 0;
    rot.vz = p->unk14;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x2000;
    func_8003C21C(&rot, &lw);
    func_8003B05C(&m, &lw);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801D5638 = p->unk16;
    D_801D5637 = (n == 8) ? 0x2C : 0x2E;
    rgb = &D_801D5634;
    *rgb = D_801D5635 = D_801D5636 = n << 4;
    D_80163C74 = func_800D4D90(rgb - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (p->unk6 > 0) {
            p->unk6 = 0;
            p->unkE *= -1;
        }
        p->unkE += 20;
        p->unk14 += 0x200;
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B0880(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    MgTask *p;
    s16 *frame;
    s32 *q;

    rot.vy = 0;
    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vz = p->unk14;
    func_8003BF8C(&rot, &m);
    func_8003B35C(&m, &D_801D563C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801D5656;
    q = (s32 *)((u8 *)frame - 0xA);
    M2C_SFIELD(frame, s16 *, 0) = 0x80 - p->unk2 * 6;
    *q = D_801D565C[p->unk16];
    D_801ED738 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801ED738);
    if (D_80062D98 == 0) {
        p->unk6 -= 200;
        p->unk14 += 0x100;
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B09E0(void) {
    MgTask *p;
    MgMat m;
    MgMat lw;
    MgVec scale;
    s32 t;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801D566C, &m);
    func_8003A79C(&D_801D570C, &m, &m);
    scale.vx = scale.vy = scale.vz = p->unk2 * 1500;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801D567E[0] = t << 8;
    D_801ED738 = func_800D29D4(&D_801D567E[-5], D_801517C0 + 0x70, 0xC, D_801ED738);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B0B3C(void) {
    MgTask *p;
    MgMat m;
    MgMat lw;
    MgVec scale;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 >= 3) {
        func_8003C21C(&D_801D5684, &m);
        func_8003A79C(&D_801D570C, &m, &m);
        scale.vx = scale.vy = scale.vz = 0x4000 - p->unk2 * 400;
        func_8003B35C(&m, &scale);
        m.t[0] = p->unk4;
        m.t[1] = p->unk6;
        m.t[2] = p->unk8;
        func_8003A63C(&D_800FA63C, &m, &lw);
        func_8003B48C(&lw);
        func_8003B51C(&lw);
        func_8003B69C(0, 0, 0);
        t = p->unk2;
        D_801D5696[0] = t * 200;
        D_801ED738 = (u8 *)func_800D29D4(&D_801D5696[-5], D_801517C0 + 0x70, 0xC, (s32)D_801ED738);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B0CC0(void) {
    MgTask *p;
    u16 *frame;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x4000, 0);
    frame = &D_801D56A4;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 >= D_801D549C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_re_do/nonmatchings/text", func_801B0DAC);

void func_801B0EAC(void) {
    MgMat m;
    MgMat lw;
    MgVec scale;
    MgTask *p;
    s16 *frame;
    s32 **q;
    s32 v;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801D56C8, &m);
    func_8003A79C(&D_801D570C, &m, &m);
    scale.vx = scale.vz = 0x4000 - p->unk2 * 300;
    scale.vy = p->unk2 * 900;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    frame = &D_801D56C2;
    q = (s32 **)((u8 *)frame - 0xA);
    M2C_SFIELD(q, s32 **, 0) = &D_801D1C08;
    v = 0x1000 - (D_801D56B4 << 8);
    *frame = v;
    D_801ED738 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801ED738);
    *q = &D_801D220C;
    D_801ED738 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801ED738);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 13) {
            D_801D56B4--;
        }
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B10A0(void) {
    MgMat m1;
    MgMat m2;
    MgTask *p;
    MgTask *q;
    u16 *frame;
    u8 *pk;
    s8 *col;
    s32 r;
    s32 k;
    s8 c;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801D5700, &m1);
    func_8003A79C(&D_801D570C, &m1, &m1);
    func_8003B35C(&m1, &D_801D56D4);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m1, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    frame = &D_801D56EE;
    pk = (u8 *)frame - 0xA;
    ((MgPkt *)pk)->tag = D_801D2810;
    *frame = D_801D56D0 * 0x10;
    D_801ED738 = func_800D29D4(pk, D_801517C0 + 0x70, 0xC, D_801ED738);
    ((MgPkt *)pk)->tag = D_801D37B4;
    D_801ED738 = func_800D29D4(pk, D_801517C0 + 0x70, 0xC, D_801ED738);
    ((MgPkt *)pk)->tag = D_801D4758;
    D_801ED738 = func_800D29D4(pk, D_801517C0 + 0x70, 0xC, D_801ED738);
    func_800D4368(&p->unk4, 0x4000, 0);
    col = &D_801D56F8;
    c = (s16)D_801D56D0 * 0x14;
    D_801D56FA.v = c;
    D_801D56F9.v = c;
    *col = c;
    D_801D56FC = (s16)((u16 *)p)[1] % 2;
    D_801ED738 = func_800D4D90(col - 4, D_801517C0 + 0x70, 0xC, D_801ED738);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (!(p->unk2 & 1)) {
            q = &D_80162978[func_800BBEAC(func_801B0B3C)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
        }
        if (p->unk6 < 0) {
            q = &D_80162978[func_800BBEAC(func_801B0664)];
            q->unk4 = p->unk4;
            q->unk8 = p->unk8;
            q->unk6 = 0;
            D_801D5708 = func_80042DA8() % 0x1000;
            q->unkC = (u32)(func_80039B40(D_801D5708) * 0xF) >> 9;
            q->unk10 = (u32)(func_80039A74(D_801D5708) * 0xF) >> 9;
            q->unkE = -func_80042DA8() % 300 - 0x32;
            q->unk16 = func_80042DA8() % 7;
            if ((s16)(p->unk2 % 3) == 0) {
                q = &D_80162978[func_800BBEAC(func_801B0880)];
                q->unk4 = p->unk4 + func_80042DA8() % 4000 - 0x7D0;
                q->unk8 = p->unk8 + func_80042DA8() % 4000 - 0x7D0;
                q->unk6 = 0;
                q->unk16 = func_80042DA8() % 4;
            }
        }
        if (p->unk2 >= 0xD) {
            D_801D56D0--;
        }
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_re_do/nonmatchings/text", func_801B1590);

INCLUDE_ASM("../asm/us/magic_re_do/nonmatchings/text", func_801B1A54);
