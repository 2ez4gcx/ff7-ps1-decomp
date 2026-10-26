#include "common.h"
#include "magic_hari1000/decls.h"

void func_801B0030(s16 mask, MgSVec *out) {
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

void func_801B01DC(s32 base, s16 range, MgSVec *out) {
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

void func_801B030C(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist) {
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

void func_801B046C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CC540 = D_801B4540 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04D8(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk14, p->unk16);
    frame = &D_801B4514;
    *frame = p->unk2;
    D_801CC540 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801CC540);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B4448) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_RODATA("../asm/us/magic_hari1000/nonmatchings/text", D_801B0000);

void func_801B0594(MgSVec *pos, s16 scale, s16 ang) {
    MgMat r;
    MgMat m;
    MgVec n;
    s32 flag;
    s16 *q;

    m = D_801B0000;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(pos, (MgVec *)m.t, &flag);
    func_8003A08C((MgVec *)m.t, &n);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = scale;
    q = &D_801B451C;
    *q = ang;
    func_8003C21C((MgSVec *)((u8 *)q - 4), &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
}

void func_801B069C(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B0594(&p->unk4, p->unk14, p->unk1A);
    frame = &D_801B4528;
    *frame = p->unk1C;
    D_801CC540 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801CC540);
    if (D_80062D98 == 0) {
        p->unk1A += 0x80;
        p->unkE += 0x20;
        p->unk4 += p->unkC;
        p->unk8 += p->unk10;
        p->unk6 += p->unkE;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n >= D_801B4260) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_hari1000/nonmatchings/text", func_801B07A0);

void func_801B0A38(void) {
    MgSVec rot;
    MgSVec sv;
    MgSVec d;
    MgMat m;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 n;
    s32 k;
    s32 ang;
    u16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            rot.vy = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            rot.vx = rot.vz = 0;
            func_8003C21C(&rot, &m);
            m.t[0] = m.t[1] = m.t[2] = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            d.vx = (p->unkC - p->unk4) / 8;
            d.vy = (p->unkE - p->unk6) / 8;
            d.vz = (p->unk10 - p->unk8) / 8;
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B07A0)];
                ang = func_80042DA8() & 0xFFF;
                sv.vx = (u32)(func_80039B40(ang) * i / 30 * 5) >> 6;
                sv.vy = (u32)(func_80039A74(ang) * i / 30 * 5) >> 6;
                sv.vz = func_80042DA8() % (func_80039B40((i << 10) / 30) / 6);
                if (func_80042DA8() & 1) {
                    v = sv.vz;
                } else {
                    v = -sv.vz;
                }
                sv.vz = v;
                func_8003BADC(&sv, &sv, &flag);
                q->unk4 = p->unk4 + sv.vx;
                q->unk6 = p->unk6 + sv.vy;
                q->unk8 = p->unk8 + sv.vz;
                q->unkC = d.vx;
                n = i + 1;
                q->unkE = d.vy;
                q->unk10 = d.vz;
                q->unk18 = rot.vy;
                q->unk1A = -0x400;
                i = n;
            } while (n < 0x1E);
        }
        if (p->unk2 == 8) {
            func_800D5774(p->unk1C);
        }
        if ((u32)((u16)p->unk2 - 9) < 3) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B04D8)];
            func_800D3994(p->unk1C, D_8015190F[D_800FA6D4][0], &q->unk4);
            k = 0x1F4;
            q->unk4 = q->unk4 - k + func_80042DA8() % 1000;
            q->unk6 = q->unk6 - k + func_80042DA8() % 1000;
            q->unk8 = q->unk8 - k + func_80042DA8() % 1000;
            q->unk14 = 0x3000;
            q->unk16 = -D_801518F6[D_800FA6D4][0];
        }
        if (++p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0F04(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0A38)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B0FC4(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B046C);
    func_800D2980(&D_801B21DC, 0, 0, 0);
    func_800D2980(&D_801B119C, 0, 0, 0);
    func_800D2980(&D_801B321C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0F04);
    func_800BBA84(0x63, arg1, 0x40);
}
