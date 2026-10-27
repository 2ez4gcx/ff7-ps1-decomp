#include "common.h"
#include "magic_frog/decls.h"

void func_801B0008(void) {
    func_801B1E14();
}

INCLUDE_ASM("../asm/us/magic_frog/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_frog/nonmatchings/text", func_801B0A50);

void func_801B1160(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E2AE8 = D_801CAAE8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_RODATA("../asm/us/magic_frog/nonmatchings/text", D_801B0000);

INCLUDE_RODATA("../asm/us/magic_frog/nonmatchings/text", D_801B0004);

void func_801B11CC(void) {
    MgPtrPair tbl;
    MgTask *p;
    s32 **hdr;

    tbl = D_801B0000;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2400, 0);
    hdr = &D_801CAA60;
    M2C_SFIELD(hdr, s32 **, 0) = tbl.ptr[p->unk1A];
    D_801CAA68 = p->unk2;
    D_801E2AE8 = (u8 *)func_800D4D90(hdr, D_801517C0 + 0x70, 0xC, (s32)D_801E2AE8);
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

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    D_801CAA74[0] = p->unk2;
    D_801E2AE8 = func_800D4D90(&D_801CAA74[-4], D_801517C0 + 0x70, 0xC, D_801E2AE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801CA93C) {
            p->unk0 = -1;
        }
    }
}

void func_801B13A0(void) {
    MgTask *p;
    MgMat m;
    MgMat rot;
    s32 flag;
    s16 i;
    s32 t;
    p = (MgTask *)&D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = p->unk2 * 1000 + 0x400;
    func_8003C21C(&D_801CAA88, &rot);
    func_8003B05C(&m, &rot);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801CAA82[0] = t << 8;
    D_801E2AE8 = func_800D29D4(&D_801CAA82[-5], D_801517C0 + 0x70, 0xC, D_801E2AE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 15) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B1518(void) {
    MgMat m;
    MgMat w;
    MgSVec a;
    MgSVec b;
    MgSVec c;
    MgVec scale;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 k;
    s16 fl;
    s16 n;
    s32 t1;
    s32 t2;
    u16 u;
    s32 v;
    u8 *x;
    s16 *r;
    MgScratch *d;

    p = (MgTask *)&D_80162978[D_8015169C];
    fl = p->unk1A;
    k = (fl >> 1) * 2 - 1;
    b.vx = a.vx = func_80039A74(p->unk2 << 8) / 40 * k;
    b.vy = a.vy = (func_80039A74(p->unk2 << 7) >> 5) * k;
    b.vz = a.vz = 0;
    a.vx -= 0x400;
    func_8003C21C(&a, &m);
    func_8003A79C((MgMat *)D_801CAAC8, &m, &m);
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
    d = &D_801CAA94;
    x = D_801C9F8C;
    if (!(p->unk1A & 1)) {
        x = D_801CA280;
    }
    d->unk0 = x;
    r = &d->unkA;
    if (!(p->unk1A & 1)) {
        t1 = D_801CAA90;
        v = 0x1000 - t1 * 0x60;
    } else {
        t2 = D_801CAA90;
        v = 0x1000 - (t2 << 5);
    }
    *r = v;
    D_801E2AE8 = func_800D29D4(&D_801CAA94, D_801517C0 + 0x70, 0xC, D_801E2AE8);
    if (D_80062D98 == 0) {
        if (!(p->unk1A & 1)) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B11CC)];
            q->unk4 = (u16)p->unk4;
            q->unk6 = (u16)p->unk6;
            q->unk8 = (u16)p->unk8;
            c.vy = c.vx = 0;
            c.vz = (u16)p->unk18;
            func_8003C21C(&b, &m);
            func_8003A79C((MgMat *)D_801CAAC8, &m, &m);
            m.t[0] = q->unk4;
            m.t[1] = q->unk6;
            m.t[2] = q->unk8;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&c, (MgSVec *)&q->unk4, &flag);
            q->unkC = 0;
            u = p->unkE;
            q->unk10 = 0;
            q->unk1A = 0;
            q->unkE = u;
        }
        if (p->unk2 < 8) {
            D_801CAA90++;
        }
        if (p->unk2 >= 0x19) {
            D_801CAA90--;
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x20) {
            p->unk0 = -1;
        }
    }
}

void func_801B1878(void) {
    MgSVec v;
    MgSVec rot;
    MgMat m;
    s32 flag;
    MgTask *p;
    MgTask *q;
    MgSVec *qv;
    MgMat *mp;
    u16 *w;
    s16 a;
    s16 b;
    s16 c;
    s16 len;
    s32 t;
    s32 r;
    s16 i;
    s16 id;
    s16 ang;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801CAAC0.vx = a = p->unkC - p->unk4;
            D_801CAAC0.vy = b = p->unkE - p->unk6;
            D_801CAAC0.vz = c = p->unk10 - p->unk8;
            t = a * a + b * b;
            len = func_80039F5C(t + c * c, t);
            for (i = 0; i < 4; i++) {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1518)];
                q->unk4 = (u16)p->unk4;
                q->unk6 = (u16)p->unk6;
                q->unk8 = (u16)p->unk8;
                ang = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
                q->unk1A = i;
                q->unkE = ang;
                q->unk18 = len;
                q->unk14 = len * 0x1500 / 2800;
            }
        }
        if (p->unk2 == 0x23) {
            r = func_800BBEAC(func_801B13A0);
            q = (MgTask *)D_8016297C;
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &((MgObj20 *)q)[r]);
        }
        if (p->unk2 == 0x2D) {
            func_800BBA84(0x134, p->unk1C, 0x40);
        }
        if ((u16)p->unk2 - 0x2D < 0x14U) {
            i = 0;
            mp = &m;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B12E8)];
                qv = (MgSVec *)&q->unk4;
                id = p->unk1C;
                func_800D3994(id, D_8015190F[id][0], qv);
                r = func_80042DA8() % p->unk14;
                v.vz = 0;
                v.vx = 0;
                v.vy = r;
                rot.vx = func_80042DA8() % 0x1000;
                rot.vz = func_80042DA8() % 0x1000;
                rot.vy = 0;
                func_8003C21C(&rot, mp);
                m.t[0] = q->unk4;
                m.t[1] = q->unk6;
                m.t[2] = q->unk8;
                func_8003B48C(mp);
                func_8003B51C(mp);
                func_8003BADC(&v, qv, &flag);
                i++;
            } while (i < 5);
        }
        if (p->unk2 == 0x32) {
            if ((D_800F836C >> p->unk1C) & 1) {
                w = func_800D4FA8(6);
            } else if ((D_801517B4 >> p->unk1C) & 1) {
                w = func_800D4FA8(4);
                w[8] = 0;
            } else {
                w = func_800D4FA8(4);
            }
            *w = p->unk1C;
        }
        p->unk2++;
        if (p->unk2 == 0x50) {
            func_800D52A0(0, 0xA);
            p->unk0 = -1;
        }
    }
}

void func_801B1CDC(arg0, arg1) {
    MgSVec v;
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B1878)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk14 = D_801518F6[arg0][0] + 0xC8;
    p->unk1C = arg0;
    v.vx = (u16)p->unkC - (u16)p->unk4;
    v.vy = (u16)p->unkE - (u16)p->unk6;
    v.vz = (u16)p->unk10 - (u16)p->unk8;
    func_800D44E8(&v, D_801CAAC8);
    func_800BBA84(0x62, arg1, 0x40);
}

void func_801B1E14(arg0, arg1) {
    u8 pad[8];

    func_800BBEAC(func_801B1160);
    func_800D2980(D_801B1EAC, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B1CDC);
    func_800D52A0(0x1000, 0xA);
    D_800F5B70 = 0x18;
    D_800F5B71 = 0x10;
    D_800F5B72 = 0;
}
