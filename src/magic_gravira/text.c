#include "common.h"
#include "magic_gravira/decls.h"

void func_801B0000(void) {
    func_801B0C10();
}

void func_801B0020(void) {
    MgTask *p;
    MgMat *m;

    p = (MgTask *)&D_80162978[D_8015169C];
    m = func_800D4368(&p->unk8, 0xD00, 0);
    if (m->t[2] > 0) {
        func_800D4484(D_801517C0 + 0x70 + (m->t[2] >> 4) * 4, 0x20);
        D_801D0F10[0] = p->unk2;
        D_801EEF40 = (u8 *)func_800D4D90(&D_801D0F10[-4], D_801517C0 + 0x70, 0xC, (s32)D_801EEF40);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 5) {
            p->unk0 = -1;
        }
    }
}

void func_801B0108(void) {
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

void func_801B01E0(void) {
    MgTask *p;
    MgMat *m;
    s32 t;
    s32 c;
    s32 scale;

    p = (MgTask *)&D_80162978[D_8015169C];
    scale = -(p->unk2 * 3 << 12) / 40 + 0x3000; t = p->unk2;
    if (t < 0x14) {
        c = (t << 7) / 20;
        D_801D0F1C = D_801D0F1D = D_801D0F1E = c;
    } else {
        t -= 0x14;
        if (t < 0x14) {
            c = 0x80;
            D_801D0F1C = D_801D0F1D = D_801D0F1E = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    m = func_800D4368(&p->unk8, scale, p->unk18);
    if (m->t[2] > 0) {
        func_800D4484(D_801517C0 + 0x70 + (m->t[2] >> 4) * 4, 0x20);
        D_801EEF40 = func_800D6260(D_801D0F14, D_801517C0 + 0x70, 0xC, D_801EEF40);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B033C(void) {
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
        D_801D0F2C = D_801D0F2D = D_801D0F2E = (t << 7) / 5;
    } else {
        t -= 5;
        if (t < 0xF) {
            D_801D0F2C = D_801D0F2D = D_801D0F2E = 0x80;
        } else {
            t -= 0xF;
            if (t >= 5) {
                p->unk0 = -1;
                return;
            }
            D_801D0F2C = D_801D0F2D = D_801D0F2E = -(t << 7) / 5 - 0x80;
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
        D_801EEF40 = func_800D6260(D_801D0F24, D_801517C0 + 0x70, 0xC, D_801EEF40);
    }
    if (D_80062D98 == 0) {
        p->unk10 += 0x50;
        p->unk12 += 0x40;
        p->unk14 += 0x50;
        p->unk2++;
    }
}

void func_801B0558(void) {
    MgTask *p;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        c = (t << 7) / 5;
        D_801D0F38 = D_801D0F39 = D_801D0F3A = c;
    } else {
        t -= 5;
        if (t < 0x23) {
            c = 0x80;
            D_801D0F38 = D_801D0F39 = D_801D0F3A = c;
        } else {
            t -= 0x23;
            if (t < 5) {
                c = -(t << 7) / 5 - 0x80;
                D_801D0F38 = D_801D0F39 = D_801D0F3A = c;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801D0F3C[0] = p->unk2 % 12;
    func_800D4368(&p->unk8, 0x2000, p->unk18);
    D_801EEF40 = (u8 *)func_800D4D90(&D_801D0F3C[-4], D_801517C0 + 0x70, 0xC, (s32)D_801EEF40);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B06D4(void) {
    GrObj *p;
    GrObj *q;
    MgSVec v;
    MgSVec pad;
    s16 n;

    p = (GrObj *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (GrObj *)&D_80162978[func_800BBEAC(&func_801B0108)];
            func_800D3994(p->unk6, D_8015190F[p->unk6][0], &q->pos);
            func_800D3994(p->unk4, D_8015190F[p->unk4][0], &v);
            q->vel.vx = (v.vx - q->pos.vx) / 8;
            q->vel.vy = (v.vy - q->pos.vy) / 8;
            q->vel.vz = (v.vz - q->pos.vz) / 8;
            func_800D55F4(0x20, func_800D56A8(&q->pos), 0x50);
        }
        if (p->unk2 == 8) {
            q = (GrObj *)&D_80162978[func_800BBEAC(&func_801B01E0)];
            func_800D3994(p->unk4, D_8015190F[p->unk4][0], &q->pos);
            q->unk18 = -D_801518F6[p->unk4].v;
            func_800D55F4(0x20, func_800D56A8(&q->pos), 0x4B);
        }
        if (p->unk2 == 8) {
            func_800D3994(p->unk4, D_8015190F[p->unk4][0], &v);
            q = (GrObj *)&D_80162978[func_800BBEAC(&func_801B033C)];
            q->pos = v;
            n = -D_801518F6[p->unk4].v; q->vel.vx = q->vel.vy = q->vel.vz = 0; q->unk18 = n;
            q = (GrObj *)&D_80162978[func_800BBEAC(&func_801B033C)];
            q->pos = v;
            q->unk18 = -D_801518F6[p->unk4].v; q->vel.vx = 0; q->vel.vy = 0x400; q->vel.vz = 0;
        }
        if (p->unk2 == 8) {
            q = (GrObj *)&D_80162978[func_800BBEAC(&func_801B0558)];
            func_800D3994(p->unk4, D_8015190F[p->unk4][0], &q->pos);
            q->unk18 = -D_801518F6[p->unk4].v;
        }
        if (p->unk2 == 8) {
            func_800D5774(p->unk4);
        }
        if (p->unk2 >= 8) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0B50(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B06D4)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B0BA4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EEF40 = D_801D0F40 + p->unk2 * 0xF000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B0C10(arg0, arg1) {
    func_800D2980(&D_801B0C80, 0, 0, 0);
    func_800BBEAC(&func_801B0BA4);
    func_800D5444(arg0, arg1, 8, &func_801B0B50);
}
