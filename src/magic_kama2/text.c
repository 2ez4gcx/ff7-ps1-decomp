#include "common.h"
#include "magic_kama2/decls.h"

void func_801B007C(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    frame = &D_801D12FC;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801D1300[p->unk18];
    D_801E9330 = (u8 *)func_800D4D90(q, D_801517C0 + 0x70, 0xC, (s32)D_801E9330);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D1300[p->unk18][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0170(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1600, 0);
    frame = &D_801D131C;
    *frame = p->unk2;
    D_801E9330 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E9330);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x32;
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= D_801D0F38) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_RODATA("../asm/us/magic_kama2/nonmatchings/text", D_801B0000);

void func_801B0238(void) {
    MgMat m;
    MgMat lw;
    MgScratch sc;
    MgSVec rot;
    MgSVec v;
    s32 flag;
    MgTask *p;
    s16 n;

    sc = D_801B0000;
    p = &D_80162978[D_8015169C];
    v.vx = (func_80039A74((p->unk16 << 12) / 35 + 0x800) * p->unk1A) >> 12;
    v.vz = (func_80039B40((p->unk16 << 12) / 35 + 0x800) * p->unk1A) >> 12;
    v.vy = 0;
    func_8003C21C((MgSVec *)&p->unkC, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003BADC(&v, &v, &flag);
    rot.vx = 0;
    rot.vy = p->unk2 << 10;
    rot.vz = p->unk10;
    func_8003C4AC(&rot, &m);
    func_8003C8DC(p->unkE, &m);
    func_8003B35C(&m, &D_801D1320);
    m.t[0] = v.vx;
    m.t[1] = v.vy;
    m.t[2] = v.vz;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801E9330 = (u8 *)func_800D29D4(&sc, D_801517C0 + 0x70, 0xC, (s32)D_801E9330);
    if (D_80062D98 == 0) {
        p->unk16 += p->unk18;
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x23) {
            p->unk0 = -1;
        }
    }
}

void func_801B046C(void) {
    MgTask *p;
    MgTask *q;
    MgSVec u0;
    MgSVec u1;
    MgSVec u2;
    MgSVec d;
    MgMat um;
    s32 r;
    s16 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(func_801B0170)];
                q->unk4 = p->unk4 + func_80042DA8() % 800 - 400;
                q->unk6 = p->unk6 + func_80042DA8() % 800 - 400;
                q->unk8 = p->unk8 + func_80042DA8() % 800 - 400;
                q = &D_80162978[func_800BBEAC(func_801B0238)];
                q->unk4 = (p->unk4 + p->unkC) / 2;
                q->unk6 = (p->unk6 + p->unkE) / 2;
                q->unk8 = (p->unk8 + p->unk10) / 2;
                q->unkC = 0;
                q->unkE = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
                r = func_80042DA8();
                q->unk10 = r % 1024;
                d.vx = p->unkC - p->unk4;
                d.vy = p->unkE - p->unk6;
                d.vz = p->unk10 - p->unk8;
                q->unk1A = func_80039F5C(d.vx * d.vx + d.vy * d.vy + d.vz * d.vz) >> 1;
                q->unk16 = 0;
                if (!(i & 1)) {
                    q->unk18 = 1;
                } else {
                    q->unk18 = -1;
                }
            } while (++i < 6);
        }
        if (p->unk2 == 0x11) {
            func_800D4CBC(D_800FA6D4, 9, 0x1800);
            func_800D5774(p->unk1C);
        }
        if ((u32)((u16)p->unk2 - 0xE) < 3) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(func_801B007C)];
                func_800D3994(p->unk1C, D_8015190F[D_800FA6D4][0], &q->unk4);
                q->unk4 += func_80042DA8() % 1000 - 500;
                q->unk6 += func_80042DA8() % 1000 - 500;
                q->unk8 += func_80042DA8() % 1000 - 500;
                q->unk18 = func_80042DA8() % 5;
            } while (++i < 2);
        }
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0914(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B046C)];
    func_800D3994(arg1, D_80151915[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_RODATA("../asm/us/magic_kama2/nonmatchings/text", D_801B0010);

void func_801B09D4(arg0, arg1) {
    func_800BBEAC(&D_801B0010);
    func_800D2980(D_801B0A50, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0914);
    func_800BBA84(0x83, arg1, 0x40);
}
