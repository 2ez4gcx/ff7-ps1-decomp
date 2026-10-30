#include "common.h"
#include "magic_cometeo/decls.h"

void func_801B0000(void) {
    func_801B1488();
}

void func_801B0020(void) {
    s32 otz;
    s32 flag;
    MgTask *p;
    u8 *pkt;
    s32 n;

    pkt = D_801EC260;
    p = &D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    n = func_8003BBDC(&p->unk4, pkt + 8, &otz, &flag);
    if (!(flag & 0x60000)) {
        func_80046974(pkt);
        pkt[4] = 0xFF;
        pkt[5] = func_80042DA8();
        pkt[6] = 0;
        func_80046794((n >> 2) * 4 + (D_801517C0 + 0x70), (s32)pkt);
        D_801EC260 = pkt + 0xC;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 6) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
        }
        if (++p->unk2 >= 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B017C(void) {
    MgSVec rot;
    s32 flag;
    MgTask *p;
    MgTask *q;
    MgSVec *sv;
    MgVec *vp;
    s32 i;
    s32 t;
    u8 *r;

    sv = (MgSVec *)0x1F800060;
    vp = (MgVec *)0x1F800068;
    p = &D_80162978[D_8015169C];
    rot.vx = -p->unkC;
    rot.vy = -p->unkE;
    rot.vz = -p->unk10;
    func_800D44E8(&rot, (MgMat *)0x1F800000);
    ((MgMat *)0x1F800000)->t[0] = p->unk4;
    ((MgMat *)0x1F800000)->t[1] = p->unk6;
    ((MgMat *)0x1F800000)->t[2] = p->unk8;
    func_8003B35C((MgMat *)0x1F800000, &D_801D4194);
    func_8003A63C(&D_800FA63C, (MgMat *)0x1F800000, (MgMat *)0x1F800020);
    func_8003B48C((MgMat *)0x1F800020);
    func_8003B51C((MgMat *)0x1F800020);
    D_801EC260 = func_800D29D4(&D_801D417C, D_801517C0 + 0x70, 0xC, D_801EC260);
    func_8003C21C(&D_801D418C, (MgMat *)0x1F800040);
    func_8003A63C((MgMat *)0x1F800020, (MgMat *)0x1F800040, (MgMat *)0x1F800040);
    func_8003B48C((MgMat *)0x1F800040);
    r = func_800D29D4(&D_801D416C, D_801517C0 + 0x70, 0xC, D_801EC260);
    D_801D41B8[0] = p->unk4;
    D_801EC260 = r;
    D_801D41C0 = p->unk8;
    func_8003A63C(&D_800FA63C, (MgMat *)&D_801D41B8[-5], (MgMat *)0x1F800020);
    func_8003B48C((MgMat *)0x1F800020);
    func_8003B51C((MgMat *)0x1F800020);
    D_801EC260 = func_800D29D4(&D_801D41C4, D_801517C0 + 0x4078, 1, D_801EC260);
    if (D_80062D98 == 0) {
        func_8003B48C((MgMat *)0x1F800000);
        func_8003B51C((MgMat *)0x1F800000);
        i = 0;
        do {
            t = (i << 12) / 3 + func_80042DA8() % 1365;
            sv->vx = (u32)(func_80039A74(t) * 0x7D) >> 9;
            sv->vy = func_80039B40(t) * 0x3E8 >> 12;
            sv->vz = func_80042DA8() % 1000;
            func_8003BC6C(sv, vp, &flag);
            i++;
            q = &D_80162978[func_800BBEAC(func_801B0020)];
            q->unk4 = vp->vx;
            q->unk6 = vp->vy;
            q->unk8 = vp->vz;
            sv->vz = 0;
            func_8003ACE4(sv, vp);
            q->unkC = -vp->vx / 6;
            q->unkE = -vp->vy / 6;
            q->unk10 = -vp->vz / 6;
        } while (i < 3);
        D_801D4184[0] ^= 0x80;
        D_801D418C.vx += 0x80;
        D_801D418C.vy += 0x100;
        D_801D418C.vz += 0x180;
        p->unk2++;
        if (p->unk2 >= 0xA) {
            p->unk0 = -1;
        }
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
    }
}

void func_801B0608(void) {
    MgTask *p;
    MgMat *lw;
    s32 t;
    s32 k;
    s32 v;

    lw = (MgMat *)0x1F800000;
    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        D_801D41D8 = 0x88;
        D_801D41DE = -(t << 12) / 10 + 0x1000;
        func_8003B69C(0xFF, 0xFF, 0xFF);
    } else {
        k = t - 10;
        if (k < 0) {
            D_801D41D8 = 0x88;
            D_801D41DE = 0;
        } else if (k < 10) {
            D_801D41D8 = 0x88;
            D_801D41DE = (k << 12) / 10;
            func_8003B69C(0, 0, 0);
        } else {
            p->unk0 = -1;
            return;
        }
    }
    v = p->unk2 * 0x1200 / 10 + 0x800;
    D_801D41E4.m[0][0] = D_801D41E4.m[1][1] = D_801D41E4.m[2][2] = v;
    D_801D41E4.t[0] = p->unk4;
    D_801D41E4.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801D41E4, lw);
    func_8003B48C(lw);
    func_8003B51C(lw);
    D_801D41D4[0] = &D_801D23EC;
    D_801EC260 = func_800D29D4(D_801D41D4, D_801517C0 + 0x70, 0xC, D_801EC260);
    D_801D41D4[0] = &D_801D3A88;
    D_801D41D8 = 0x88;
    D_801EC260 = func_800D29D4(D_801D41D4, D_801517C0 + 0x70, 0xC, D_801EC260);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0844(void) {
    MgMat m;
    MgVec v;
    MgSVec rot;
    MgTask *p;
    u8 *r;

    p = &D_80162978[D_8015169C];
    if (p->unk1E == 0) {
        D_801D4204.src = &D_801D3D3C;
    } else {
        D_801D4204.src = &D_801D3EF0;
    }
    if (p->unk0 < 2) {
        D_801D4204.mode = 0x80;
        D_801D4204.val = 0;
    } else {
        D_801D4204.mode = 0x88;
        D_801D4204.val = p->unk2 * 0x200;
    }
    rot.vx = ((u8 *)p)[0x14] * 0x10;
    rot.vy = ((u8 *)p)[0x15] * 0x10;
    rot.vz = ((u8 *)p)[0x16] * 0x10;
    func_8003C21C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk1C;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    r = func_800D29D4(&D_801D4204, D_801517C0 + 0x70, 0xC, D_801EC260);
    D_801D422C = 0;
    D_801EC260 = r;
    D_801D4228[0] = p->unk4;
    D_801D4230 = p->unk8;
    func_8003A63C(&D_800FA63C, (MgMat *)&D_801D4228[-5], &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801EC260 = func_800D29D4(&D_801D4234, D_801517C0 + 0x4078, 1, D_801EC260);
    if (D_80062D98 == 0) {
        if (p->unk0 >= 2) {
            p->unk2++;
            if (p->unk2 >= 8) {
                p->unk0 = -1;
                return;
            }
        }
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkE += 0x32;
        if (p->unk6 > 0) {
            p->unk6 = -p->unk6;
            p->unkE = -p->unkE / 4;
            p->unkC >>= 1;
            p->unk10 >>= 1;
            p->unk0++;
            ((u8 *)p)[0x18] >>= 1;
            ((u8 *)p)[0x19] >>= 1;
            ((u8 *)p)[0x1A] >>= 1;
        }
        ((u8 *)p)[0x14] += ((u8 *)p)[0x18];
        ((u8 *)p)[0x15] += ((u8 *)p)[0x19];
        ((u8 *)p)[0x16] += ((u8 *)p)[0x1A];
    }
}

void func_801B0B88(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    frame = &D_801D424C;
    *frame = p->unk2;
    func_800D4368(&p->unk4, 0x2500, 0);
    D_801EC260 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EC260);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D40A8) {
            p->unk0 = -1;
        }
    }
}

void func_801B0C4C(void) {
    MgVec v;
    MgTask *p;
    MgTask *q;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &D_80162978[func_800BBEAC(func_801B017C)];
            q->unk4 = D_80151A4C[D_801D4250][0] + (func_80039A74(D_80151A46[D_801D4250][0]) * 3000 >> 12);
            q->unk6 = -0x1770;
            q->unk8 = D_80151A50[D_801D4250][0] + (func_80039B40(D_80151A46[D_801D4250][0]) * 3000 >> 12);
            v.vx = q->unkC = (p->unk4 - q->unk4) / 10;
            v.vy = q->unkE = (p->unk6 - q->unk6) / 10;
            v.vz = q->unk10 = (p->unk8 - q->unk8) / 10;
            func_8003A08C(&v, &v);
            q->unk4 -= v.vx * 500 >> 12;
            q->unk6 -= v.vy * 500 >> 12;
            q->unk8 -= v.vz * 500 >> 12;
        }
        if (p->unk2 == 9) {
            q = &D_80162978[func_800BBEAC(func_801B0608)];
            *(CometeoB8 *)&q->unk4 = *(CometeoB8 *)&p->unk4;
            i = 0;
            do {
                i++;
                q = &D_80162978[func_800BBEAC(func_801B0844)];
                *(CometeoB8 *)&q->unk4 = *(CometeoB8 *)&p->unk4;
                q->unk6 = 0;
                q->unkC = func_80042DA8() % 500 - 250;
                q->unkE = -(func_80042DA8() % 200 + 300);
                q->unk10 = func_80042DA8() % 500 - 250;
                ((u8 *)q)[0x18] = (func_80042DA8() & 0x3F) - 0x20;
                ((u8 *)q)[0x19] = (func_80042DA8() & 0x3F) - 0x20;
                ((u8 *)q)[0x1A] = (func_80042DA8() & 0x3F) - 0x20;
                q->unk1C = func_80042DA8() % 0xE00 + 0x200;
                q->unk0 = 0;
                q->unk1E = func_80042DA8() & 1;
            } while (i < 5);
        }
        if ((u32)((u16)p->unk2 - 10) < 0xF) {
            i = 0;
            do {
                i++;
                q = &D_80162978[func_800BBEAC(func_801B0B88)];
                q->unk4 = p->unk4 + (func_80042DA8() % 0xA00 - 0x500);
                q->unk6 = p->unk6 - func_80042DA8() % 0x500;
                q->unk8 = p->unk8 + (func_80042DA8() % 0xA00 - 0x500);
            } while (i < 1);
        }
        if (p->unk2 == 0x19) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B11F4(void) {
    MgTask *p;
    MgTask *q;
    MgTask *r;
    s32 k;
    s32 j;
    s32 id;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        k = p->unk2;
        if (k == 0) {
            func_800D52A0(0x800, 8);
            D_800F5B70[0] = D_800F5B70[1] = D_800F5B70[2] = 0;
        } else {
            k -= 8;
            if (k >= 0) {
                j = k - 0x14;
                if (j >= 0) {
                    if ((j & 7) == 0) {
                        id = D_801517F0[p->unk0];
                        if (id != 0xFF) {
                            r = func_800D4FA8(0xA);
                            r->unk0 = id;
                            r->unk10 = p->unk0;
                            p->unk0++;
                        }
                    }
                }
                if (k < 0x3C) {
                    if (k == k / 10 * 10) {
                        q = &D_80162978[func_800BBEAC(func_801B0C4C)];
                        q->unk4 = D_801D4258.vx + func_80042DA8() % 6000 - 3000;
                        q->unk6 = 0;
                        q->unk8 = D_801D4258.vz + func_80042DA8() % 6000 - 3000;
                    }
                } else {
                    p->unk0 = -1;
                }
            }
        }
        p->unk2++;
    }
}

void func_801B13FC(void) {
    M2C_UNK *var_v1;
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    var_v1 = &D_801B154C;
    if (temp_s0->unk2 == 0) {
        var_v1 = &D_801D4260;
    }
    D_801EC260 = var_v1;
    temp_s0->unk2 = (u16) temp_s0->unk2 ^ 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 4);
        temp_s0->unk0 = -1;
    }
}

s32 func_801B1488(arg0, arg1) {
    func_800BBEAC(func_801B13FC);
    D_801D4254 = arg0;
    D_801D4250 = arg1;
    func_800D54EC(arg0, &D_801D4258);
    if (D_801517BC == 0) {
        func_800D2980(&D_801B154C, 0, 0, 0);
    }
    D_80162978[func_800BBEAC(func_801B11F4)].unk0 = 0;
    return func_800D55F4(0x21, func_800D574C(arg0), 0x94, 0x19C);
}
