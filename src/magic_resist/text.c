#include "common.h"
#include "magic_resist/decls.h"

INCLUDE_RODATA("../asm/us/magic_resist/nonmatchings/text", D_801B0000);

void func_801B0010(void) {
    MgSprC loc;
    MgSVec *v;
    MgMat *m;
    MgTask *p;
    s32 t;

    loc = D_801B0000;
    v = (MgSVec *)0x1F800000;
    m = (MgMat *)0x1F800008;
    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xD) {
        loc.r = loc.g = loc.b = 0x80;
    } else {
        t -= 0xD;
        if (t < 4) {
            loc.r = loc.g = loc.b = -(t << 7) / 4 - 0x80;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_800D4368(&p->unk8, p->unk1A, 0);
    D_80163C74 = func_800D6260(&loc, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        v->vx = p->unk18;
        v->vy = 0;
        v->vz = 0;
        func_8003C21C(&p->unk10, m);
        func_8003B2CC(m, v, v);
        p->unk8 += v->vx >> 4;
        p->unkA += v->vy >> 4;
        p->unkC += v->vz >> 4;
        p->unk18 -= p->unk18 * 3 >> 4;
        p->unk14 += (-0x400 - p->unk14) * 3 >> 4;
        p->unk10 += p->unk1C;
    }
}

void func_801B0218(void) {
    MgObjAlm *p;
    MgObjAlm *q;
    s32 i;

    p = (MgObjAlm *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 10) {
            i = 0;
            D_801C075E[0] = func_80042DA8() & 0xFFF;
            for (; i < D_801C076C; i++) {
                q = (MgObjAlm *)&D_80162978[func_800BBEAC(&func_801B0010)];
                q->unk8 = p->unk8;
                q->unk1A = func_80042DA8() % 0x300 + 0x100;
                q->unk10 = *(MgSVec *)&D_801C075E[-1];
                q->unk18 = (func_80042DA8() % 400 + 100) << 4;
                q->unk1C = func_80042DA8() % 100 - 50;
                D_801C075E[0] += 0x1000 / D_801C076C;
            }
        } else {
            func_800D5774(p->unk4);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B044C(s32 arg0) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0218)];
    p->unk4 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], (u8 *)&p->unk8);
    p->unkA = 0;
    if (D_801E0774 >= 4) {
        func_800D55F4(0x20, func_800D56A8((u8 *)&p->unk8), 0x80);
    }
}

void func_801B0504(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E0770 = D_801C0770 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0564(s32 arg0, M2C_UNK arg1) {
    s32 temp_v0;
    s32 var_v1;

    func_800D2980(&D_801B063C, 0, 0, 0);
    func_800BBEAC(&func_801B0504);
    temp_v0 = func_800D54BC(arg0);
    D_801E0774 = temp_v0;
    var_v1 = 3;
    if (temp_v0 == 1) {
        var_v1 = 6;
    }
    D_801C076C = var_v1;
    func_800D5444(arg0, arg1, -(temp_v0 >= 4) & 0xA, &func_801B044C);
    if (D_801E0774 < 4) {
        func_800D55F4(0x20, func_800D574C(arg0), 0x80);
    }
}
