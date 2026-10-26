#include "common.h"
#include "magic_elecball/decls.h"

void func_801B0000(void) {
    func_801B0E98();
}

void func_801B0020(void) {
    MgTask *p;
    MgMat *m;

    p = (MgTask *)&D_80162978[D_8015169C];
    m = func_800D4368(&p->unk8, 0xD00, 0);
    if (m->t[2] > 0) {
        D_801D11A8[0] = p->unk2;
        D_801EF1E4 = (u8 *)func_800D4D90(&D_801D11A8[-4], D_801517C0 + 0x70, 0xC, (s32)D_801EF1E4);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 5) {
            p->unk0 = -1;
        }
    }
}

void func_801B00E8(void) {
    MgObjVel *p;
    MgObjVel *q;

    p = (MgObjVel *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        p->unk8.vx += p->unk10.vx;
        p->unk8.vy += p->unk10.vy;
        p->unk8.vz += p->unk10.vz;
        q = (MgObjVel *)&D_80162978[func_800BBEAC(&func_801B0020)];
        q->unk8 = p->unk8;
        p->unk2++;
        if (p->unk2 >= 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B01C0(void) {
    MgTask *p;
    MgMat *m;
    s32 t;
    s32 c;
    s32 scale;

    p = (MgTask *)&D_80162978[D_8015169C];
    scale = -(p->unk2 * 0x3000) / 0x28 + 0x3000;
    t = p->unk2;
    if (t < 0x14) {
        c = (t << 7) / 0x14;
        D_801D11B4 = D_801D11B5 = D_801D11B6 = c;
    } else {
        t -= 0x14;
        if (t < 0x14) {
            c = 0x80;
            D_801D11B4 = D_801D11B5 = D_801D11B6 = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    m = func_800D4368(&p->unk8, scale, p->unk18);
    if (m->t[2] > 0) {
        D_801EF1E4 = func_800D6260(D_801D11AC, D_801517C0 + 0x70, 0xC, D_801EF1E4);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B02FC(void) {
    MgSVec v;
    u8 pad[8];
    MgMat m;
    MgTask *p;
    s32 t;
    s32 i;
    s32 ang;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        D_801D11C4 = D_801D11C5 = D_801D11C6 = (t << 7) / 5;
    } else {
        t -= 5;
        if (t < 0xF) {
            D_801D11C4 = D_801D11C5 = D_801D11C6 = 0x80;
        } else {
            t -= 0xF;
            if (t >= 5) {
                p->unk0 = -1;
                return;
            }
            D_801D11C4 = D_801D11C5 = D_801D11C6 = -(t << 7) / 5 - 0x80;
        }
    }
    for (i = 0; i < 0x10; i++) {
        ang = i << 8;
        v.vx = (u32)(func_80039A74(ang) * 0x7D) >> 10;
        v.vy = (u32)(func_80039B40(ang) * 0x7D) >> 10;
        v.vz = 0;
        func_8003C21C((MgSVec *)&p->unk10, &m);
        func_8003B2CC(&m, &v, &v);
        v.vx += p->unk8;
        v.vy += p->unkA;
        v.vz += p->unkC;
        func_800D4368(&v, 0x600, p->unk18);
        D_801EF1E4 = func_800D6260(D_801D11BC, D_801517C0 + 0x70, 0xC, D_801EF1E4);
    }
    if (D_80062D98 == 0) {
        p->unk10 += 0x50;
        p->unk12 += 0x40;
        p->unk14 += 0x50;
        p->unk2++;
    }
}

void func_801B0518(void) {
    MgTask *p;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        c = (t << 7) / 5;
        D_801D11D0 = D_801D11D1 = D_801D11D2 = c;
    } else {
        t -= 5;
        if (t < 0x23) {
            c = 0x80;
            D_801D11D0 = D_801D11D1 = D_801D11D2 = c;
        } else {
            t -= 0x23;
            if (t < 5) {
                c = -(t << 7) / 5 - 0x80;
                D_801D11D0 = D_801D11D1 = D_801D11D2 = c;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801D11D4[0] = p->unk2 % 12;
    func_800D4368(&p->unk8, 0x2000, p->unk18);
    D_801EF1E4 = (u8 *)func_800D4D90(&D_801D11D4[-4], D_801517C0 + 0x70, 0xC, (s32)D_801EF1E4);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0694(void) {
    ElTask *p;
    ElTask *q;
    MgSVec v;
    u8 pad[8];
    s32 n;

    p = (ElTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (ElTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B00E8)];
            func_800D3994(p->unk6, D_8015190F[p->unk6][8], &q->unk8);
            func_800D3994(p->unk4, D_8015190F[p->unk4][0], &v);
            q->unk10.vx = (v.vx - q->unk8.vx) / 8;
            q->unk10.vy = (v.vy - q->unk8.vy) / 8;
            q->unk10.vz = (v.vz - q->unk8.vz) / 8;
            func_800D55F4(0x20, func_800D56A8(&q->unk8), 0x50);
        }
        n = p->unk2;
        if (n == 8) {
            q = (ElTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B01C0)];
            func_800D3994(p->unk4, D_8015190F[p->unk4][0], &q->unk8);
            q->unk18 = -D_801518F6[p->unk4][0];
            func_800D55F4(0x20, func_800D56A8(&q->unk8), 0x4B);
            if (p->unk2 == n) {
                func_800D3994(p->unk4, D_8015190F[p->unk4][0], &v);
                q = (ElTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B02FC)];
                q->unk8 = v;
                q->unk18 = -D_801518F6[p->unk4][0];
                q->unk10.vx = q->unk10.vy = q->unk10.vz = 0;
                q = (ElTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B02FC)];
                q->unk8 = v;
                q->unk18 = -D_801518F6[p->unk4][0];
                q->unk10.vx = 0;
                q->unk10.vy = 0x400;
                q->unk10.vz = 0;
                if (p->unk2 == n) {
                    q = (ElTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0518)];
                    func_800D3994(p->unk4, D_8015190F[p->unk4][0], &q->unk8);
                    q->unk18 = -D_801518F6[p->unk4][0];
                    if (p->unk2 == n) {
                        func_800D5774(p->unk4);
                    }
                }
            }
        }
        if (p->unk2 >= 8) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0B10(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B0694)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B0B64(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EF1E4 = D_801D11E4 + p->unk2 * 0xF000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0BD0(void) {
    MgTask *p;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        c = (t << 7) / 5;
        D_801D11DC = D_801D11DD = D_801D11DE = c;
    } else {
        t -= 5;
        if (t < 0xA) {
            c = 0x80;
            D_801D11DC = D_801D11DD = D_801D11DE = c;
        } else {
            t -= 0xA;
            if (t < 5) {
                c = -(t << 7) / 5 - 0x80;
                D_801D11DC = D_801D11DD = D_801D11DE = c;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801D11E0[0] = p->unk2 % 12;
    func_800D4368(&p->unk8, 0x1000, p->unk18);
    D_801EF1E4 = (u8 *)func_800D4D90(&D_801D11E0[-4], D_801517C0 + 0x70, 0xC, (s32)D_801EF1E4);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0D4C(void) {
    MgObj20 *p;
    MgObj20 *q;
    u8 *d;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &D_80162978[func_800BBEAC(&func_801B0BD0)];
            d = (u8 *)q + 8;
            func_800D3994(p->unk6, D_8015190F[p->unk6][8], d);
            *(s16 *)((u8 *)q + 0x18) = -*(u16 *)D_801518F6[p->unk6];
            func_800D55F4(0x20, func_800D56A8(d), 0x13F);
        }
        if (p->unk2 == 0xF) {
            func_800D5444(p->unk4, p->unk6, 0, func_801B0B10);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0E98(arg0, arg1) {
    MgObj20 *p;

    func_800D2980(D_801B0F18, 0, 0, 0);
    func_800BBEAC((M2C_UNK *)func_801B0B64);
    p = &D_80162978[func_800BBEAC(&func_801B0D4C)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}
