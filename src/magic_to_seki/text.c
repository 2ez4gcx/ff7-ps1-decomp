#include "common.h"
#include "magic_to_seki/decls.h"

void func_801B0000(void) {
    func_801B1A58();
}

INCLUDE_ASM("../asm/us/magic_to_seki/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_to_seki/nonmatchings/text", func_801B0A48);

void func_801B1158(void) {
    MgMat m;
    MgSVec rot;
    MgSVec v;
    MgSVec *e;
    s16 i;

    for (i = 0; i < 0x14; i++) {
        e = &D_801B9DF4[i];
        e->vz = 0;
        e->vy = 0;
        D_801B9DF4[i].vx = 0;
        v.vx = 0;
        v.vy = 0;
        v.vz = 0x258;
        rot.vx = func_80042DA8();
        rot.vy = func_80042DA8();
        rot.vz = 0;
        func_8003C21C(&rot, &m);
        func_8003B2CC(&m, &v, &D_801B9E94[i]);
    }
}

void func_801B1214(void) {
    s16 i;

    for (i = 0; i < 0x14; i++) {
        D_801B9DF4[i].vx += D_801B9E94[i].vx;
        D_801B9DF4[i].vy += D_801B9E94[i].vy;
        D_801B9DF4[i].vz += D_801B9E94[i].vz;
    }
}

void func_801B12E0(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C1F34 = D_801B9F34 + p->unk2 * 0x4000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B1340(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801B9DC0;
    *frame = p->unk2;
    D_801C1F34 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801C1F34);
    if (D_80062D98 == 0) {
        p->unkC = p->unkC * 0xC0 / 256;
        p->unkE = p->unkE * 0xC0 / 256;
        p->unk10 = p->unk10 * 0xC0 / 256;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (++p->unk2 == D_801B9CF4) {
            p->unk0 = -1;
        }
    }
}

void func_801B1498(void) {
    MgMat m;
    MgMat m2;
    MgMat m3;
    MgTask *p;
    s32 k;
    s16 t;
    s16 *rot;
    s32 *hdr;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x14) {
        rot = &D_801B9DE4;
        *rot = -t * 0x80;
        func_8003C21C((MgSVec *)rot, &m);
        func_8003B35C(&m, D_801B9DD4);
        m.t[0] = p->unk4;
        m.t[1] = p->unk6 - ((func_80039A74(p->unk2 * 0x66) * 0x7D0) >> 12);
        m.t[2] = p->unk8;
        func_8003A63C(&D_800FA63C, &m, &m3);
        func_8003B48C(&m3);
        func_8003B51C(&m3);
        D_801C1F34 = func_800D29D4(&D_801B9DC4, D_801517C0 + 0x70, 0xC, D_801C1F34);
    } else {
        k = (s16)(t - 0x14);
        hdr = &D_801B9DC8;
        *hdr = 8;
        D_801B9DCE = 0x80 - k * 0x10;
        func_8003C21C((MgSVec *)&D_801B9DE4, &m);
        func_8003B35C(&m, D_801B9DD4);
        m.t[0] = p->unk4;
        m.t[1] = p->unk6;
        m.t[2] = p->unk8;
        func_8003A63C(&D_800FA63C, &m, &m3);
        rot = &D_801B9DEC;
        *rot = k << 8;
        func_8003C21C((MgSVec *)rot, &m2);
        D_801C1F34 = func_801B0020(hdr - 1, D_801517C0 + 0x70, 0xC, D_801C1F34, D_801B9DF4, &m3, &m2);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x14) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
        } else {
            func_801B1214();
        }
        if (++p->unk2 == 0x1C) {
            p->unk0 = -1;
        }
    }
}

void func_801B173C(void) {
    MgSVec v;
    MgSVec rot;
    MgMat m;
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s16 i;

    b = (MgTask *)D_80162978;
    p = &b[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &b[func_800BBEAC(&func_801B1498)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unkC = (p->unkC - p->unk4) / 20;
            q->unkE = (p->unkE - p->unk6) / 20;
            q->unk10 = (p->unk10 - p->unk8) / 20;
            q = &b[func_800BBEAC(&func_801B1340)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unkC = 0;
            q->unkE = -0x50;
            q->unk10 = 0;
        }
        if (p->unk2 == 0x14) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B1340)];
                q->unk4 = p->unkC;
                q->unk6 = p->unkE;
                q->unk8 = p->unk10;
                v.vx = 0;
                v.vy = 0;
                v.vz = 0x190;
                rot.vx = func_80042DA8();
                rot.vy = func_80042DA8();
                rot.vz = 0;
                func_8003C21C(&rot, &m);
                func_8003B2CC(&m, &v, (MgSVec *)&q->unkC);
                i++;
            } while (i < 10);
            func_800D5774(p->unk1C);
            func_800BBA84(0x14, p->unk1C, 0);
        }
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B198C(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = &D_80162978[func_800BBEAC(&func_801B173C)];
    func_800D3994(arg1, D_8015191E[arg1][0], &p->unk4);
    func_800D3994(arg0, D_80151919[arg0][0], &p->unkC);
    p->unk1E = arg1;
    p->unk1C = arg0;
}

void func_801B1A58(arg0, arg1) {
    func_800BBEAC((M2C_UNK *)func_801B12E0);
    func_800D2980(&D_801B1ADC, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B198C);
    func_800BBA84(0x163, arg1, 0);
    func_801B1158();
}
