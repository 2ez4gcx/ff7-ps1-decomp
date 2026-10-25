#include "common.h"
#include "magic_hikari/decls.h"

void func_801B006C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    frame = &D_801B8914;
    *frame = p->unk2;
    D_801D0924 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D0924);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801B4770) {
            p->unk0 = -1;
        }
    }
}

void func_801B0124(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801B8920;
    *frame = p->unk2;
    D_801D0924 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D0924);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B8848) {
            p->unk0 = -1;
        }
    }
}

void func_801B01E0(void) {
    MgTask *p;
    MgHikariObj *q;
    MgSVec sv;
    MgMat m;
    s32 flag;
    s32 r;
    s32 k;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgHikariObj *)&D_80162978[func_800BBEAC(&func_801B006C)];
            q->unkC = 0;
            q->unkE = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            sv.vx = sv.vy = 0;
            sv.vz = 0x64;
            func_8003C21C((MgSVec *)&q->unkC, &m);
            m.t[0] = m.t[1] = m.t[2] = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&sv, &sv, &flag);
            q->unk4 = p->unk4 + sv.vx;
            q->unk6 = p->unk6 + sv.vy;
            q->unk8 = p->unk8 + sv.vz;
        }
        if (p->unk2 == 2) {
            D_800F5B70 = D_800F5B71 = D_800F5B72 = 0;
            D_800F5B74 = 0x1000;
            for (i = 0; i < 10; i++) {
                D_801D0928[i] = D_80151909[i][0];
                D_80151909[i][0] |= 2;
            }
        }
        if (p->unk2 == 4) {
            D_800F5B74 = 0;
            func_800D5138(0xF);
            for (i = 0; i < 10; i++) {
                D_80151909[i][0] = D_801D0928[i];
            }
        }
        if (p->unk2 == 0x14) {
            func_800D51D4(0xF);
        }
        if (p->unk2 == 0x1E) {
            func_800D5774(p->unk1A);
            func_800BBA84(0x95, p->unk1A, 0x40);
        }
        if ((u16)p->unk2 - 0x1F < 4U) {
            for (i = 0; i < 2; i++) {
                q = (MgHikariObj *)&D_80162978[func_800BBEAC(&func_801B0124)];
                func_800D3994(p->unk1A, D_8015190F[p->unk1A][0], &q->unk4);
                k = 0x1F4;
                q->unk4 = q->unk4 - k + func_80042DA8() % 1000;
                k = 0x1F4;
                q->unk6 = q->unk6 - k + func_80042DA8() % 1000;
                k = 0x1F4;
                q->unk8 = q->unk8 - k + func_80042DA8() % 1000;
            }
        }
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0610(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B01E0)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    p->unk1A = arg0;
}

INCLUDE_RODATA("../asm/us/magic_hikari/nonmatchings/text", D_801B0000);

void func_801B0698(s32 arg0, s32 arg1) {
    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B072C, 0, 0, 0);
    func_800D2980(&D_801B4804, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, (M2C_UNK *)func_801B0610);
    func_800BBA84(0x6B, arg1, 0x40);
}
