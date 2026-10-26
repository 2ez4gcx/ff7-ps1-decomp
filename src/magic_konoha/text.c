#include "common.h"
#include "magic_konoha/decls.h"

void func_801B0000(void) {
    func_801B0704();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D5AA8 = D_801BDAA8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgMat m;
    MgMat lw;
    MgSVec a;
    MgSVec r;
    s32 flag;
    KoObj *p;

    p = (KoObj *)&D_80162978[D_8015169C];
    a.vx = (func_80039A74(p->unk18) * p->unk16) >> 12;
    a.vz = (func_80039B40(p->unk18) * p->unk16) >> 12;
    r.vx = p->unk1A;
    r.vy = p->unk1A << 1;
    r.vz = 0;
    func_8003C21C(&r, &m);
    func_8003B35C(&m, D_801BDA7C);
    m.t[0] = p->unk4 + a.vx;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8 + a.vz;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    D_801BDA90[0] = (D_801BDA78 != 8) * 8;
    D_801BDA96.v = D_801BDA78 << 4;
    D_801BDA90[-1] = D_801BDA9C[p->unk14];
    D_801D5AA8 = func_800D29D4(&D_801BDA90[-1], D_801517C0 + 0x70, 0xC, D_801D5AA8);
    if (D_80062D98 == 0) {
        if ((u16)p->unk2 - 0xA < 0xFU) {
            p->unk4 += p->unkC;
            p->unk8 += p->unk10;
        }
        if ((u16)p->unk2 - 0x19 < 0xAU) {
            p->unk6 += (-0x640 - p->unk6) / 8;
            p->unk16 -= p->unk16 / 6;
        }
        if (p->unk2 == 0x23) {
            a.vx = 0;
            a.vy = 0;
            a.vz = 0x190;
            r.vx = func_80042DA8() % 0x1000;
            r.vy = func_80042DA8() % 0x1000;
            r.vz = 0;
            func_8003BF8C(&r, &m);
            m.t[0] = m.t[1] = m.t[2] = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&a, &p->unkC, &flag);
        }
        if (p->unk2 >= 0x23) {
            p->unk16 += 0xC8;
            p->unk4 += p->unkC;
            p->unk8 += p->unk10;
            p->unk6 += p->unkE;
        }
        p->unk18 += 0x100;
        p->unk1A += 0x80;
        p->unk2++;
        if (p->unk2 == 0x2D) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_konoha/nonmatchings/text", func_801B03E0);

s32 func_801B0704(arg0, arg1) {
    MgObj20 *p;

    func_800BBEAC(func_801B0020);
    D_801D5AAC = arg0;
    func_800D2980(&D_801B07DC, 0, 0, 0);
    p = &D_80162978[func_800BBEAC(func_801B03E0)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D54EC(arg0, (u8 *)p + 0xC);
    func_800BBA84(0x68, arg1, 0x40);
}
