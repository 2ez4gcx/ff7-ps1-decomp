#include "common.h"
#include "magic_missile/decls.h"

void func_801B0000(void) {
    func_801B0AB0();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E19E8 = D_801C99E8 + p->unk2 * 0xC000;
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
    frame = &D_801C99A8;
    *frame = p->unk2;
    D_801E19E8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E19E8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801C981C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0148(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    MgSVec pos;
    MgSVec v;
    MgSVec d;
    s32 flag;
    s32 otz;
    MgTask *p;
    u8 *pkt;
    s16 i;
    s32 n;
    s32 t;
    u16 u;

    rot.vy = rot.vx = -0x400;
    rot.vz = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    func_8003C8DC(p->unk14, &m);
    func_8003B35C(&m, &D_801C99AC);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801E19E8 = func_800D29D4(D_801C99BC, D_801517C0 + 0x70, 0xC, D_801E19E8);
    rot.vy = p->unk14;
    rot.vx = rot.vz = 0;
    pos.vx = pos.vy = 0;
    pos.vz = -0x64;
    func_8003C21C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003BADC(&pos, &pos, &flag);
    func_800D4368(&pos, 0x2000, 0);
    D_801C99D4[0] = p->unk2 % D_801C9734;
    D_801E19E8 = func_800D4D90(&D_801C99D4[-4], D_801517C0 + 0x70, 0xC, D_801E19E8);
    if (p->unk2 >= 6) {
        v.vx = pos.vx;
        v.vy = pos.vy;
        v.vz = pos.vz;
        i = 0;
        d.vx = -func_80039A74(p->unk14) * (p->unk2 % 2 * 0x50 + 0x50) >> 12;
        d.vz = -func_80039B40(p->unk14) * (p->unk2 % 2 * 0x50 + 0x50) >> 12;
        do {
            func_800D4368(&v, 0x2000, 0);
            D_801C99E0[0] = i >> 1;
            D_801E19E8 = func_800D4D90(&D_801C99E0[-4], D_801517C0 + 0x70, 0xC, D_801E19E8);
            i++;
            v.vx += d.vx;
            v.vz += d.vz;
        } while (i < 12);
    }
    if (D_80062D98 == 0) {
        func_8003B48C(&D_800FA63C);
        func_8003B51C(&D_800FA63C);
        for (i = 0; i < 10; i++) {
            v.vx = pos.vx + func_80042DA8() % 400 - 0xC8;
            v.vy = pos.vy + func_80042DA8() % 400 - 0xC8;
            v.vz = pos.vz + func_80042DA8() % 400 - 0xC8;
            pkt = D_801E19E8;
            func_80046974(pkt);
            pkt[7] = 0x6A;
            n = func_8003BBDC(&v, pkt + 8, &otz, &flag);
            if (n > 0) {
                pkt[4] = 0x80;
                pkt[5] = 0x40;
                pkt[6] = 0x20;
                t = (n >> 2) * 4 + 0x70;
                func_80046794(t + D_801517C0, pkt);
                D_801E19E8 = pkt + 0xC;
            }
        }
        if (p->unk2 < 6) {
            p->unk4 += p->unkC >> 2;
            p->unk6 += (p->unkE >> 2) + p->unk1A;
            p->unk8 += p->unk10 >> 2;
            p->unk1A -= 5;
        }
        if (p->unk2 >= 6) {
            p->unk4 += p->unkC;
            u = p->unk6 - 0xA;
            p->unk6 = u + p->unkE;
            p->unk8 += p->unk10;
        }
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0704(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 k;
    u8 pad[56];

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0148)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk14 = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q->unkC = (p->unkC - p->unk4) / 15;
            q->unkE = (p->unkE - p->unk6) / 15;
            q->unk10 = (p->unk10 - p->unk8) / 15;
            q->unk1A = 0x32;
        }
        if (p->unk2 == 0x14) {
            func_800D5774(p->unk1C);
        }
        if ((u16)p->unk2 - 0x15 < 3U) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B008C)];
                func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
                k = 0x1F4;
                q->unk4 = q->unk4 - k + func_80042DA8() % 1000;
                k = 0x1F4;
                q->unk6 = q->unk6 - k + func_80042DA8() % 1000;
                i++;
                k = 0x1F4;
                q->unk8 = q->unk8 - k + func_80042DA8() % 1000;
            } while (i < 2);
        }
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B09F0(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0704)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B0AB0(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B0B2C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B09F0);
    func_800BBA84(0x82, arg1, 0x40);
}
