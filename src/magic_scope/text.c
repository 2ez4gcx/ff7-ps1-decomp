#include "common.h"
#include "magic_scope/decls.h"

void func_801B0028(s16 mask, MgSVec *out) {
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

void func_801B01D4(s32 base, s16 range, MgSVec *out) {
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

void func_801B0304(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist) {
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

void func_801B0464(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D5964 = D_801BD964 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_RODATA("../asm/us/magic_scope/nonmatchings/text", D_801B0000);

void func_801B04D0(s32 arg0, MgSVec *rot, s16 scale) {
    MgMat r;
    MgMat m;
    MgVec unused;

    m = D_801B0000;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = scale;
    func_8003B05C(&m, &D_800FA63C);
    func_8003C21C(rot, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
}

INCLUDE_RODATA("../asm/us/magic_scope/nonmatchings/text", D_801B0020);

INCLUDE_RODATA("../asm/us/magic_scope/nonmatchings/text", D_801B0024);

void func_801B05B4(void) {
    MgPtrPair tbl;
    MgTask *p;
    s32 **hdr;

    tbl = D_801B0020;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2400, 0);
    hdr = &D_801BD910;
    M2C_SFIELD(hdr, s32 **, 0) = tbl.ptr[p->unk1A];
    D_801BD918 = p->unk2;
    D_801D5964 = (u8 *)func_800D4D90(hdr, D_801517C0 + 0x70, 0xC, (s32)D_801D5964);
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

s32 func_801B06D0(void) {
    MgMat m;
    MgMat pad;
    MgSVec ra;
    MgSVec rb;
    MgSVec v;
    MgVec scale;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s32 **hdr;
    s16 *f;
    s32 *t;
    s32 w;
    s32 r;
    s16 k;
    s16 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = ((s16)*(u16 *)&p->unk16 >> 1) * 2 - 1;
    rb.vx = ra.vx = func_80039A74(p->unk2 << 8) / 40 * k;
    c = (func_80039A74(p->unk2 << 7) >> 4) * k;
    rb.vz = ra.vz = 0;
    ra.vx -= 0x400;
    rb.vy = ra.vy = c;
    func_8003C21C(&ra, &m);
    func_8003A79C(&D_801BD940, &m, &m);
    scale.vy = p->unk14;
    w = 0x4000;
    if (!(p->unk16 & 1)) {
        w = 0x3000;
    }
    scale.vx = scale.vz = w;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    t = D_801BCE38;
    hdr = &D_801BD920;
    if (!(p->unk16 & 1)) {
        t = D_801BD21C;
    }
    f = (s16 *)((u8 *)hdr + 0xA);
    *hdr = t;
    if (!(p->unk16 & 1)) {
        r = 0x1000 - (D_801BD91C << 5);
    } else {
        r = 0x1000 - D_801BD91C * 0x18;
    }
    *f = r;
    D_801D5964 = func_800D29D4(&D_801BD920, D_801517C0 + 0x70, 0xC, D_801D5964);
    if (D_80062D98 == 0) {
        if (!(p->unk16 & 1)) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B05B4)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            v.vx = 0;
            v.vy = 0;
            v.vz = p->unk18;
            func_8003C21C(&rb, &m);
            func_8003A79C(&D_801BD940, &m, &m);
            m.t[0] = q->unk4;
            m.t[1] = q->unk6;
            m.t[2] = q->unk8;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&v, &q->unk4, &flag);
            q->unkC = 0;
            q->unkE = p->unkE;
            q->unk10 = 0;
            q->unk1A = 0;
        }
        if (p->unk2 < 8) {
            D_801BD91C++;
        }
        if (p->unk2 >= 0x19) {
            D_801BD91C--;
        }
        p->unk2++;
        if (p->unk2 == 0x20) {
            p->unk0 = -1;
        }
    }
}

void func_801B0A48(void) {
    MgTask *p;
    MgTask *q;
    s16 dx;
    s16 dy;
    s16 dz;
    s16 n;
    s16 i;
    u8 pad[0x30];

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            dx = p->unkC - p->unk4;
            D_801BD938.vx = dx;
            dy = p->unkE - p->unk6;
            D_801BD938.vy = dy;
            dz = p->unk10 - p->unk8;
            D_801BD938.vz = dz;
            i = 0;
            n = func_80039F5C(dx * dx + dy * dy + dz * dz);
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B06D0)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unkE = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
                q->unk16 = i;
                i++;
                q->unk18 = n;
                q->unk14 = n * 0x1500 / 2800;
            } while (i < 4);
        }
        if (p->unk2 == 0x20) {
            i = 0;
            do {
                if ((D_80151774 >> i) & 1) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 0xA);
        }
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
            func_800D52A0(0, 0xA);
        }
    }
}

void func_801B0C94(s32 arg0, s32 arg1) {
    MgSVec v;
    MgTask *p;

    func_800D2980(&D_801B0DD8, 0, 0, 0);
    func_800BBEAC(func_801B0464);
    D_801BD960 = arg0;
    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B0A48)];
    func_800D3994(arg1, D_8015190F[arg1][9], &p->unk4);
    func_801B0028(arg0, (MgSVec *)&p->unkC);
    v.vx = p->unkC - p->unk4;
    v.vy = p->unkE - p->unk6;
    v.vz = p->unk10 - p->unk8;
    func_800D44E8(&v, &D_801BD940);
    D_800F5B70 = D_800F5B71 = D_800F5B72 = 0;
    func_800D52A0(0x400, 0xA);
    func_800BBA84(0x62, arg1, 0x40);
}
