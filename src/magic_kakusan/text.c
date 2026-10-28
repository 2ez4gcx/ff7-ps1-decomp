#include "common.h"
#include "magic_kakusan/decls.h"

void func_801B0000(void) {
    func_801B1190();
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
    D_801E98E4 = D_801D18E4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C8(void) {
    MgObj20 *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2800, 0);
    frame = &D_801D180C;
    *frame = p->unk2;
    D_801E98E4 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E98E4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D1740) {
            p->unk0 = -1;
        }
    }
}

void func_801B0580(void) {
    MgMat m;
    MgMat r;
    s32 flag;
    MgTask *p;
    s8 *rgb;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[i][2] = 0;
        m.m[i][1] = 0;
        m.m[i][0] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x2000;
    func_8003B05C(&m, &D_800FA63C);
    func_8003C21C((MgSVec *)&p->unkC, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
    rgb = &D_801D1814;
    *rgb = D_801D1815.v = D_801D1816.v = (u8)D_801D181C << 4;
    D_801D1818 = p->unk2 % 3;
    D_801E98E4 = func_800D4D90((u8 *)rgb - 4, D_801517C0 + 0x70, 0xC, D_801E98E4);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x21) {
            D_801D181C--;
        }
        if (++p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_kakusan/nonmatchings/text", func_801B075C);

void func_801B0958(void) {
    MgMat lw;
    MgMat m;
    MgTask *p;
    s8 *rgb;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D18B4, &m);
    func_8003B35C(&m, &D_801D18BC);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801D189A[0] = D_801D18B0 << 4;
    *(s32 *)&D_801D189A[-5] = D_801D18A0[(s16)(p->unk2 % 4)];
    D_801E98E4 = func_800D29D4(&D_801D189A[-5], D_801517C0 + 0x70, 0xC, D_801E98E4);
    func_800D4368(&p->unk4, 0x2000, 0);
    rgb = &D_801D1888;
    *rgb = D_801D1889.v = D_801D188A.v = (u8)D_801D18B0 << 4;
    D_801D188C = p->unk2 % 2;
    D_801E98E4 = func_800D4D90(rgb - 4, D_801517C0 + 0x70, 0xC, D_801E98E4);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x21) {
            D_801D18B0--;
        }
        if (++p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0B5C(void) {
    MgMat m;
    MgMat lw;
    MgVec scale;
    MgObj20 *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_8003BF8C(&D_801D18D8, &m);
    func_8003A79C(&D_801E98F4, &m, &m);
    scale.vx = (D_801E9914 << 12) / 2000;
    scale.vy = scale.vz = 0x4000;
    func_8003B35C(&m, &scale);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = ((MgTask *)p)->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801D18D4;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D1340) {
            p->unk0 = -1;
        }
    }
}

void func_801B0CB4() {
    MgMat m;
    MgSVec v;
    MgSVec rot;
    MgTask *p;
    MgTask *q;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B075C)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unk18 = D_801E9914 * 0x1800 / 2000;
                q->unkC = func_80042DA8() % 400 - 0xC8;
                q->unkE = func_80042DA8() % 400 + 0x338;
                q->unk10 = 0x400;
                q->unk14 = func_80042DA8() % 8;
                q->unk16 = i % 2;
            } while (++i < 0x14);
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0B5C)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0958)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0580)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk4 = p->unk4;
            q->unk6 = 0;
            q->unk8 = p->unk8;
            q->unkC = 0x400;
            q->unkE = func_8003CC1C(D_801E98EC.vx - p->unk4, (s16)D_801E98F0 - p->unk8);
            q->unk10 = 0;
        }
        if (p->unk2 < 0x28) {
            for (i = 0; i < 10; i++) {
                if (D_801E98E8 >> i & 1) {
                    q = (MgTask *)&D_80162978[func_800BBEAC(func_801B04C8)];
                    func_800D3994(i, D_8015190F[i][0], &q->unk4);
                    v.vx = 0;
                    v.vy = 0;
                    v.vz = func_80042DA8() % 400 + 0x190;
                    rot.vx = func_80042DA8() % 0x1000;
                    rot.vy = func_80042DA8() % 0x1000;
                    rot.vz = 0;
                    func_8003BF8C(&rot, &m);
                    func_8003B2CC(&m, &v, &v);
                    q->unk4 += v.vx;
                    q->unk6 += v.vy;
                    q->unk8 += v.vz;
                    q->unk16 = 1;
                }
            }
        }
        if (p->unk2 == 0x28) {
            for (i = 0; i < 10; i++) {
                if (D_801E98E8 >> i & 1) {
                    func_800D4CBC(i, 0x3A, 0x1000);
                    func_800D5774(i);
                }
            }
            func_800BBA84(0x95, -1, 0x40);
        }
        if (++p->unk2 == 0x32) {
            func_800D52A0(0, 0x14);
            p->unk0 = -1;
        }
    }
}

s32 func_801B1190(arg0, arg1) {
    MgSVec d;
    MgObj20 *q;

    func_800BBEAC(func_801B045C);
    func_800D2980(&D_801B1324, 0, 0, 0);
    D_801E98E8 = arg0;
    q = &D_80162978[func_800BBEAC(func_801B0CB4)];
    func_800D3994(arg1, D_8015190F[arg1][9], &q->unk4);
    func_801B0020(arg0, &D_801E98EC);
    d.vx = D_801E98EC.vx - q->unk4;
    d.vy = D_801E98EE - q->unk6;
    d.vz = D_801E98F0 - ((MgTask *)q)->unk8;
    func_800D44E8(&d, &D_801E98F4);
    D_801E9914 = func_80039F5C(d.vx * d.vx + d.vy * d.vy + d.vz * d.vz);
    func_800BBA84(0x131, arg1, 0);
    D_800F5B70 = D_800F5B71 = D_800F5B72 = 0;
    return func_800D52A0(0xC00, 0xA);
}
