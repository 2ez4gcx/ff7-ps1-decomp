#include "common.h"
#include "magic_seed/decls.h"

void func_801B006C(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, p->unk16);
    frame = &D_801B3E54;
    *frame = p->unk2;
    D_801CBE8C = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801CBE8C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B3D88) {
            p->unk0 = -1;
        }
    }
}

void func_801B0128(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    MgTask *p;
    s16 *q;
    s32 ang;
    s16 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vx = p->unk1A;
    rot.vy = p->unk18;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    func_8003B35C(&m, &D_801B3E5C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    do {
        q = &D_801B3E7A;
        *q = 0;
        D_801B3E76.v = 0x80;
        q -= 7;
        if (p->unk14 == 0) {
            q = &D_801B3E7C;
        }
        D_801CBE8C = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801CBE8C);
    } while (0);
    if (D_80062D98 == 0) {
        if (p->unk2 == 8) {
            ang = func_80042DA8() & 0xFFF;
            k = func_80042DA8() % 6;
            p->unkC = func_80039B40(ang) * k >> 8;
            p->unk10 = func_80039A74(ang) * k >> 8;
            p->unkE = -0x100;
            p->unk1A = func_80042DA8() & 0xFFF;
            p->unk18 = func_80042DA8() & 0xFFF;
        }
        if (p->unk2 >= 9) {
            p->unk1A += 0x80;
            p->unkE += 0x34;
        }
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (p->unk6 > 0) {
            p->unk6 = 0;
            p->unkE = -(p->unkE >> 1);
        }
        if (++p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B038C(void) {
    MgSVec rot;
    MgSVec sv;
    MgSVec d;
    MgMat m;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 0xF) {
            rot.vy = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            rot.vx = rot.vz = 0;
            func_8003C21C(&rot, &m);
            m.t[0] = m.t[1] = m.t[2] = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            d.vx = (p->unkC - p->unk4) / 8;
            d.vy = (p->unkE - p->unk6) / 8;
            d.vz = (p->unk10 - p->unk8) / 8;
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0128)];
                sv.vx = func_80042DA8() % 300 - 0x96;
                sv.vy = func_80042DA8() % 300 - 0x96;
                sv.vz = func_80042DA8() % 100 - 0x32;
                func_8003BADC(&sv, &sv, &flag);
                q->unk4 = p->unk4 + sv.vx;
                q->unk6 = p->unk6 + sv.vy;
                q->unk8 = p->unk8 + sv.vz;
                q->unkC = d.vx;
                q->unkE = d.vy;
                q->unk10 = d.vz;
                q->unk18 = rot.vy;
                q->unk1A = -0x400;
                q->unk14 = func_80042DA8() % 2;
                i++;
            } while (i < 2);
        }
        if (p->unk2 == 0xF) {
            func_800D5774(p->unk1C);
        }
        if ((u32)((u16)p->unk2 - 9) < 0x13) {
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B006C)];
            func_800D3994(p->unk1C, D_8015190F[D_800FA6D4][0], &q->unk4);
            k = 0x190;
            q->unk4 = q->unk4 - k + func_80042DA8() % 800;
            q->unk6 = q->unk6 - k + func_80042DA8() % 800;
            q->unk8 = q->unk8 - k + func_80042DA8() % 800;
            q->unk14 = 0x3000;
            q->unk16 = -D_801518F6[D_800FA6D4][0];
        }
        if (++p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0810(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B038C)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_RODATA("../asm/us/magic_seed/nonmatchings/text", D_801B0000);

void func_801B08D0(s32 arg0, s32 arg1) {
    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B0CC4, 0, 0, 0);
    func_800D2980(&D_801B1D04, 0, 0, 0);
    func_800D2980(&D_801B2D44, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B0810);
    func_800BBA84(0x64, arg1, 0x40);
}
