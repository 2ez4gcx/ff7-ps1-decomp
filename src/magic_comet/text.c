#include "common.h"
#include "magic_comet/decls.h"

void func_801B0000(void) {
    func_801B1364();
}

void func_801B0020(void) {
    s32 otz;
    s32 flag;
    MgTask *p;
    u8 *pkt;
    s32 n;

    pkt = D_801EB4C0;
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
        D_801EB4C0 = pkt + 0xC;
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
    func_8003B35C((MgMat *)0x1F800000, &D_801D3400);
    func_8003A63C(&D_800FA63C, (MgMat *)0x1F800000, (MgMat *)0x1F800020);
    func_8003B48C((MgMat *)0x1F800020);
    func_8003B51C((MgMat *)0x1F800020);
    D_801EB4C0 = func_800D29D4(&D_801D33E8, D_801517C0 + 0x70, 0xC, D_801EB4C0);
    func_8003C21C(&D_801D33F8, (MgMat *)0x1F800040);
    func_8003A63C((MgMat *)0x1F800020, (MgMat *)0x1F800040, (MgMat *)0x1F800040);
    func_8003B48C((MgMat *)0x1F800040);
    r = func_800D29D4(&D_801D33D8, D_801517C0 + 0x70, 0xC, D_801EB4C0);
    D_801D3424[0] = p->unk4;
    D_801EB4C0 = r;
    D_801D342C = p->unk8;
    func_8003A63C(&D_800FA63C, (MgMat *)&D_801D3424[-5], (MgMat *)0x1F800020);
    func_8003B48C((MgMat *)0x1F800020);
    func_8003B51C((MgMat *)0x1F800020);
    D_801EB4C0 = func_800D29D4(&D_801D3430, D_801517C0 + 0x4078, 1, D_801EB4C0);
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
        D_801D33F0[0] ^= 0x80;
        D_801D33F8.vx += 0x80;
        D_801D33F8.vy += 0x100;
        D_801D33F8.vz += 0x180;
        p->unk2++;
        if (p->unk2 >= 0xF) {
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
        D_801D3444 = 0x88;
        D_801D344A = -(t << 12) / 10 + 0x1000;
        func_8003B69C(0xFF, 0xFF, 0xFF);
    } else {
        k = t - 10;
        if (k < 0) {
            D_801D3444 = 0x88;
            D_801D344A = 0;
        } else if (k < 15) {
            D_801D3444 = 0x88;
            D_801D344A = (k << 12) / 15;
            func_8003B69C(0, 0, 0);
        } else {
            p->unk0 = -1;
            return;
        }
    }
    v = p->unk2 * 0x1600 / 25 + 0xA00;
    D_801D3450.m[0][0] = D_801D3450.m[1][1] = D_801D3450.m[2][2] = v;
    D_801D3450.t[0] = p->unk4;
    D_801D3450.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801D3450, lw);
    func_8003B48C(lw);
    func_8003B51C(lw);
    D_801D3440[0] = &D_801D2288;
    D_801EB4C0 = func_800D29D4(D_801D3440, D_801517C0 + 0x70, 0xC, D_801EB4C0);
    D_801D3440[0] = &D_801D2CF4;
    D_801D3444 = 0x88;
    D_801EB4C0 = func_800D29D4(D_801D3440, D_801517C0 + 0x70, 0xC, D_801EB4C0);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0850(void) {
    MgMat m;
    MgVec v;
    MgSVec rot;
    MgTask *p;
    u8 *r;

    p = &D_80162978[D_8015169C];
    if (p->unk1E == 0) {
        D_801D3470.src = &D_801D2FA8;
    } else {
        D_801D3470.src = &D_801D315C;
    }
    if (p->unk0 < 2) {
        D_801D3470.mode = 0x80;
        D_801D3470.val = 0;
    } else {
        D_801D3470.mode = 0x88;
        D_801D3470.val = p->unk2 * 0x200;
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
    r = func_800D29D4(&D_801D3470, D_801517C0 + 0x70, 0xC, D_801EB4C0);
    D_801D3498 = 0;
    D_801EB4C0 = r;
    D_801D3494[0] = p->unk4;
    D_801D349C = p->unk8;
    func_8003A63C(&D_800FA63C, (MgMat *)&D_801D3494[-5], &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801EB4C0 = func_800D29D4(&D_801D34A0, D_801517C0 + 0x4078, 1, D_801EB4C0);
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

void func_801B0B94(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    frame = &D_801D34B8;
    *frame = p->unk2;
    func_800D4368(&p->unk4, 0x2800, 0);
    D_801EB4C0 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EB4C0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D3314) {
            p->unk0 = -1;
        }
    }
}

void func_801B0C58(void) {
    MgVec v;
    MgTask *p;
    MgTask *q;
    s32 k;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        k = p->unk2;
        if (k == 0) {
            func_800D52A0(0x800, 4);
            D_800F5B70[0] = D_800F5B70[1] = D_800F5B70[2] = 0;
        }
        k -= 4;
        if (k == 0) {
            q = &D_80162978[func_800BBEAC(func_801B017C)];
            q->unk4 = D_80151A4C[D_801D34BC][0] + (func_80039A74(D_80151A46[D_801D34BC][0]) * 2000 >> 12);
            q->unk6 = -0x1388;
            q->unk8 = D_80151A50[D_801D34BC][0] + (func_80039B40(D_80151A46[D_801D34BC][0]) * 2000 >> 12);
            v.vx = q->unkC = (p->unk4 - q->unk4) / 15;
            v.vy = q->unkE = -q->unk6 / 15;
            v.vz = q->unk10 = (p->unk8 - q->unk8) / 15;
            func_8003A08C(&v, &v);
            q->unk4 -= v.vx * 300 >> 12;
            q->unk6 -= v.vy * 300 >> 12;
            q->unk8 -= v.vz * 300 >> 12;
            func_800D55F4(0x21, 0x40, 0x4C, 0x4D);
        }
        if (k == 0xF) {
            q = &D_80162978[func_800BBEAC(func_801B0608)];
            q->unk4 = p->unk4;
            q->unk6 = 0;
            q->unk8 = p->unk8;
            i = 0;
            do {
                i++;
                q = &D_80162978[func_800BBEAC(func_801B0850)];
                *(CometB8 *)&q->unk4 = *(CometB8 *)&p->unk4;
                q->unk6 = 0;
                q->unkC = func_80042DA8() % 500 - 250;
                q->unkE = -(func_80042DA8() % 200 + 300);
                q->unk10 = func_80042DA8() % 500 - 250;
                ((u8 *)q)[0x18] = (func_80042DA8() & 0x3F) - 0x20;
                ((u8 *)q)[0x19] = (func_80042DA8() & 0x3F) - 0x20;
                ((u8 *)q)[0x1A] = (func_80042DA8() & 0x3F) - 0x20;
                q->unk1C = func_80042DA8() % 0xC00 + 0x200;
                q->unk0 = 0;
                q->unk1E = func_80042DA8() & 1;
            } while (i < 10);
            func_800D5138(1);
        }
        if (k == 0x10) {
            func_800D51D4(8);
        }
        if (k == 0xF) {
            func_800D5774(p->unk0);
        }
        if ((u32)(k - 0xF) < 0x14) {
            i = 0;
            do {
                i++;
                q = &D_80162978[func_800BBEAC(func_801B0B94)];
                q->unk4 = p->unk4 + (func_80042DA8() % 2000 - 1000);
                q->unk6 = -(func_80042DA8() % 1000);
                q->unk8 = p->unk8 + (func_80042DA8() % 2000 - 1000);
            } while (i < 1);
        }
        if (k == 0x23) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B1258(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0C58)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

void func_801B12D8(void) {
    M2C_UNK *var_v1;
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    var_v1 = &D_801B13E8;
    if (temp_s0->unk2 == 0) {
        var_v1 = &D_801D34C0;
    }
    D_801EB4C0 = var_v1;
    temp_s0->unk2 = (u16) temp_s0->unk2 ^ 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 4);
        temp_s0->unk0 = -1;
    }
}

s32 func_801B1364(arg0, arg1) {
    func_800BBEAC(func_801B12D8);
    D_801D34BC = arg1;
    if (D_801517BC == 0) {
        func_800D2980(&D_801B13E8, 0, 0, 0);
    }
    return func_800D5444(arg0, arg1, 0, func_801B1258);
}
