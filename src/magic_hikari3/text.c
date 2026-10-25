#include "common.h"
#include "magic_hikari3/decls.h"

void func_801B0000(void) {
    func_801B0814();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D0AA4 = D_801B8AA4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(D_801B8A88, 0, 0);
    if (D_80062D98 == 0) {
        D_801B8A88 += D_801B8A8A;
        if (D_801B8A88 == 0) {
            p->unk0 = -1;
        }
    }
}

void func_801B0120(s16 arg0) {
    D_801B8A88 = 0;
    D_801B8A8A = (s16) (0xFF / arg0);
    func_800BBEAC(&func_801B008C);
}

void func_801B0190(s16 arg0) {
    D_801B8A88 = 0xFF;
    D_801B8A8A = (s16) -(0xFF / arg0);
}

void func_801B01E8(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    frame = &D_801B8A94;
    *frame = p->unk2;
    D_801D0AA4 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D0AA4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801B48EC) {
            p->unk0 = -1;
        }
    }
}

void func_801B02A0(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801B8AA0[0] = p->unk2;
    D_801D0AA4 = func_800D4D90(&D_801B8AA0[-4], D_801517C0 + 0x70, 0xC, D_801D0AA4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B89C4) {
            p->unk0 = -1;
        }
    }
}

void func_801B035C(void) {
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
            q = (MgHikariObj *)&D_80162978[func_800BBEAC(&func_801B01E8)];
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
                D_801D0AA8[i] = D_80151909[i][0];
                D_80151909[i][0] |= 2;
            }
        }
        if (p->unk2 == 4) {
            D_800F5B74 = 0;
            func_801B0120(0xF);
            for (i = 0; i < 10; i++) {
                D_80151909[i][0] = D_801D0AA8[i];
            }
        }
        if (p->unk2 == 0x14) {
            func_801B0190(0xF);
        }
        if (p->unk2 == 0x1E) {
            func_800D5774(p->unk1A);
            func_800BBA84(0x95, p->unk1A, 0x40);
        }
        if ((u16)p->unk2 - 0x1F < 4U) {
            for (i = 0; i < 2; i++) {
                q = (MgHikariObj *)&D_80162978[func_800BBEAC(&func_801B02A0)];
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

void func_801B078C(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B035C)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    p->unk1A = arg0;
}

s32 func_801B0814(arg0, arg1) {
    func_800BBEAC((M2C_UNK *)func_801B0020);
    func_800D2980(&D_801B08A8, 0, 0, 0);
    func_800D2980(&D_801B4980, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B078C);
    return func_800BBA84(0x6B, arg1, 0x40);
}
