#include "common.h"
#include "magic_mizu/decls.h"

void func_801B0000(void) {
    func_801B0AD8();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DA8A4 = D_801C28A4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;
    s16 *k;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = &p->unk1A;
    func_800D4368(&p->unk4, *k == 0 ? 0x1800 : 0x2000, 0);
    D_801C286C[0] = p->unk2;
    D_801C2868 = D_801C2869 = D_801C286A = 0x60;
    *(MgAnim **)&D_801C286C[-4] = D_801C2870[*k];
    D_801DA8A4 = func_800D4D90(&D_801C286C[-4], D_801517C0 + 0x70, 0xC, D_801DA8A4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801C2870[p->unk1A]->unk4) {
            p->unk0 = -1;
        }
    }
}

void func_801B01A8(void) {
    s32 otz;
    s32 flag;
    MgTask *p;
    u8 *pkt;
    s32 n;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    pkt = D_801DA8A4;
    func_80046974(pkt);
    pkt[7] = 0x6A;
    n = func_8003BBDC(&p->unk4, pkt + 8, &otz, &flag);
    if (n > 0) {
        pkt[6] = 0x80;
        pkt[5] = 0x80;
        pkt[4] = 0x80;
        t = (n >> 2) * 4 + 0x70;
        func_80046794(t + D_801517C0, pkt);
        D_801DA8A4 = pkt + 0xC;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC -= p->unkC / 4;
        p->unkE -= p->unkE / 4;
        p->unk10 -= p->unk10 / 4;
        if (++p->unk2 == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B032C(void) {
    MgMat b;
    MgMat a;
    MgMat lw;
    MgTask *p;
    s32 *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D44E8((MgSVec *)&p->unkC, &a);
    func_8003BF8C(&D_801C2898, &b);
    func_8003A79C(&a, &b, &b);
    q = &D_801C288C;
    *q = p->unk18 * D_801C28A0 / 4;
    func_8003B35C(&b, (MgVec *)(q - 1));
    b.t[0] = p->unk4;
    b.t[1] = p->unk6;
    b.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &b, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801DA8A4 = func_800D29D4(D_801C2878, D_801517C0 + 0x70, 0xC, D_801DA8A4);
    if (D_80062D98 == 0) {
        if (p->unk2 < 4) {
            D_801C28A0 += 1;
        } else {
            q[-1] -= 0x800;
            D_801C2890 -= 0x800;
        }
        if (++p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B04E4(void) {
    MgSVec rot;
    MgSVec pos;
    MgSVec d;
    MgMat m;
    MgTask *p;
    MgTask *q;
    u16 n;
    s16 i;
    s32 k;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B032C)];
            q->unk14 = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            d.vx = q->unkC = (u16)p->unkC - (u16)p->unk4;
            d.vy = q->unkE = (u16)p->unkE - (u16)p->unk6;
            d.vz = q->unk10 = (u16)p->unk10 - (u16)p->unk8;
            q->unk18 = func_80039F5C(d.vx * d.vx + d.vy * d.vy + d.vz * d.vz) * 0x1000 / 2800;
        }
        if (p->unk2 == 0xA) {
            func_800D5774(p->unk1C);
        }
        n = p->unk2;
        if ((u32)(n - 6) < 4U) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B008C)];
                func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
                k = 0x258;
                q->unk4 = q->unk4 - k + func_80042DA8() % 1200;
                k = 0x258;
                q->unk6 = q->unk6 - k + func_80042DA8() % 1200;
                i++;
                k = 0x258;
                q->unk8 = q->unk8 - k + func_80042DA8() % 1200;
                q->unk1A = 0;
            } while (i < 2);
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B008C)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            k = 0x12C;
            q->unk4 = q->unk4 - k + func_80042DA8() % 600;
            k = 0x12C;
            q->unk6 = q->unk6 - k + func_80042DA8() % 600;
            k = 0x12C;
            q->unk8 = q->unk8 - k + func_80042DA8() % 600;
            q->unk1A = 1;
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B01A8)];
                func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
                pos.vx = 0;
                pos.vy = 0;
                r = func_80042DA8();
                pos.vz = r % 100 + 0xFA;
                rot.vx = func_80042DA8();
                rot.vy = func_80042DA8();
                rot.vz = 0;
                func_8003BF8C(&rot, &m);
                func_8003B2CC(&m, &pos, (MgSVec *)&q->unkC);
                i++;
            } while (i < 10);
        }
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0A18(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B04E4)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

void func_801B0AD8(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B0B54, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0A18);
    func_800BBA84(0xEB, arg1, 0);
}
