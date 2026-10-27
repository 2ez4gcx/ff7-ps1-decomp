#include "common.h"
#include "magic_yami/decls.h"

void func_801B0000(void) {
    func_801B0D5C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EDDD4 = D_801D5DD4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D5D60;
    *frame = p->unk2;
    D_801EDDD4 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EDDD4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D5C94) {
            p->unk0 = -1;
        }
    }
}

void func_801B0144(void) {
    MgTask *p;
    MgMat *m;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    m = func_800D4368((MgSVec *)&p->unk4, 0x4000, 0);
    frame = &D_801D5D6C;
    *frame = p->unk2;
    if (m->t[2] > 0) {
        func_800D4484(*(s32 *)(((m->t[2] >> 4) * 4) + D_801517C0 + 0x70), 0x20);
        D_801EDDD4 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EDDD4);
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 == D_801D5B0C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0264(void) {
    MgMat m1;
    MgMat m2;
    MgSVec rot;
    MgSVec pt;
    MgSVec pt2;
    MgSVec d;
    s32 ext;
    s32 flag;
    MgTask *p;
    u8 *q;
    s16 i;
    s16 k;
    s32 r;
    s32 t;

    rot.vy = rot.vx = -0x400;
    rot.vz = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m1);
    func_8003C8DC(p->unk14, &m1);
    func_8003B35C(&m1, &D_801D5D70);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m1, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    if (p->unk2 < 10) {
        k = 0;
    } else if (p->unk2 >= 0x13) {
        k = 9;
    } else {
        k = p->unk2 - 10;
    }
    D_801D5D80[0] = D_801D5DA8[k];
    func_8003B69C(0, 0, 0);
    D_801EDDD4 = func_800D29D4(D_801D5D80, D_801517C0 + 0x70, 0xC, D_801EDDD4);
    rot.vy = p->unk14;
    rot.vx = rot.vz = 0;
    pt.vx = pt.vy = 0;
    pt.vz = -0x64;
    func_8003C21C(&rot, &m1);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    func_8003B48C(&m1);
    func_8003B51C(&m1);
    func_8003BADC(&pt, &pt, &ext);
    func_800D4368(&pt, 0x2000, 0);
    D_801D5D98[0] = p->unk2 % D_801D5A24;
    D_801EDDD4 = func_800D4D90(&D_801D5D98[-4], D_801517C0 + 0x70, 0xC, D_801EDDD4);
    if (p->unk2 >= 0x14) {
        pt2.vx = pt.vx;
        pt2.vy = pt.vy;
        pt2.vz = pt.vz;
        i = 0;
        d.vx = (-func_80039A74(p->unk14) * (p->unk2 % 2 * 100 + 100)) >> 12;
        d.vz = (-func_80039B40(p->unk14) * (p->unk2 % 2 * 100 + 100)) >> 12;
        do {
            func_800D4368(&pt2, 0x2000, 0);
            D_801D5DA4[0] = i >> 1;
            D_801EDDD4 = func_800D4D90(&D_801D5DA4[-4], D_801517C0 + 0x70, 0xC, D_801EDDD4);
            i++;
            pt2.vx += d.vx;
            pt2.vz += d.vz;
        } while (i < 0xC);
    }
    if (D_80062D98 == 0) {
        func_8003B48C(&D_800FA63C);
        func_8003B51C(&D_800FA63C);
        for (i = 0; i < 10; i++) {
            pt2.vx = pt.vx + func_80042DA8() % 400 - 0xC8;
            pt2.vy = pt.vy + func_80042DA8() % 400 - 0xC8;
            pt2.vz = pt.vz + func_80042DA8() % 400 - 0xC8;
            q = (u8 *)D_801EDDD4;
            func_80046974(q);
            q[7] = 0x6A;
            r = func_8003BBDC(&pt2, q + 8, &flag, &ext);
            if (r > 0) {
                q[4] = 0x80;
                q[5] = 0x40;
                q[6] = 0x20;
                t = (r >> 2) * 4 + 0x70;
                func_80046794(t + D_801517C0, q);
                D_801EDDD4 = (s32)(q + 0xC);
            }
        }
        if (p->unk2 < 0x14) {
            p->unk4 += p->unkC >> 3;
            p->unk6 += (p->unkE >> 3) + p->unk1A;
            p->unk1A--;
            p->unk8 += p->unk10 >> 3;
        }
        if (p->unk2 >= 0x14) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE - 10;
            p->unk8 += p->unk10;
        }
        p->unk2++;
        if (p->unk2 == 0x21) {
            p->unk0 = -1;
        }
    }
}

void func_801B0878(void) {
    u8 pad[8];
    MgSVec pt;
    MgSVec rot;
    MgMat m;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 a;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0264)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk14 = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q->unkC = (p->unkC - p->unk4) / 15;
            q->unkE = (p->unkE - p->unk6) / 15;
            q->unk10 = (p->unk10 - p->unk8) / 15;
            q->unk1A = 0x14;
        }
        if (p->unk2 == 0x23) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0144)];
                q->unk4 = p->unkC;
                q->unk6 = p->unkE;
                q->unk8 = p->unk10;
                a = func_80042DA8() % 0x1000;
                pt.vx = (u32)(func_80039B40(a) * 0xF) >> 10;
                pt.vy = (u32)(func_80039A74(a) * 0xF) >> 10;
                pt.vz = 0;
                rot.vx = rot.vz = 0;
                rot.vy = i << 8;
                func_8003C21C(&rot, &m);
                m.t[0] = m.t[1] = m.t[2] = 0;
                func_8003B48C(&m);
                func_8003B51C(&m);
                func_8003BADC(&pt, (MgSVec *)&q->unkC, &flag);
                q->unk18 = func_80042DA8() % 0x1000;
                i++;
            } while (i < 0x10);
            func_800D5774(p->unk1C);
            func_800BBA84(0xFA, p->unk1C, 0x40);
        }
        if (p->unk2 == 0x21) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B008C)];
                func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
                k = 0x1F4;
                q->unk4 = q->unk4 - k + func_80042DA8() % 1000;
                k = 0x1F4;
                q->unk6 = q->unk6 - k + func_80042DA8() % 1000;
                i++;
                k = 0x1F4;
                q->unk8 = q->unk8 - k + func_80042DA8() % 1000;
            } while (i < 3);
        }
        p->unk2++;
        if (p->unk2 == 0x2D) {
            p->unk0 = -1;
        }
    }
}

void func_801B0C9C(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B0878)];
    func_800D3994(arg1, D_8015190F[arg1][9], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B0D5C(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B0DD8, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0C9C);
    func_800BBA84(0x82, arg1, 0x40);
}
