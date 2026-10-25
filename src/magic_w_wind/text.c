#include "common.h"
#include "magic_w_wind/decls.h"

INCLUDE_RODATA("../asm/us/magic_w_wind/nonmatchings/text", D_801B0000);

void func_801B0010(void) {
    MgSpr16 s;
    MgTask *p;
    MgSVec *sv;
    MgMat *m;
    s32 t;
    s32 d;
    s32 v;
    s32 a;
    u8 pad[8];

    s = D_801B0000;
    m = (MgMat *)0x1F800008;
    sv = (MgSVec *)0x1F800000;
    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xD) {
        s.r = s.g = s.b = 0x80;
    } else {
        d = t - 0xD;
        if (d < 4) {
            v = -(d << 7) / 4 - 0x80;
            s.r = s.g = s.b = v;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_800D4368((MgSVec *)&p->unk8, p->unk1A, 0);
    D_801D4854 = func_800D6260(&s, D_801517C0 + 0x70, 0xC, D_801D4854);
    if (D_80062D98 == 0) {
        p->unk2++;
        sv->vx = p->unk18;
        sv->vy = 0;
        sv->vz = 0;
        func_8003C21C((MgSVec *)&p->unk10, m);
        func_8003B2CC(m, sv, sv);
        p->unk8 += sv->vx >> 4;
        p->unkA += sv->vy >> 4;
        p->unkC += sv->vz >> 4;
        a = p->unk18;
        p->unk18 = a - ((s16)a >> 3);
        p->unk14 += (-0x400 - p->unk14) >> 3;
        p->unk10 += p->unk1C;
    }
}

void func_801B0208(void) {
    MgObjAlm *p;
    MgObjAlm *q;
    s32 i;

    p = (MgObjAlm *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 10) {
            i = 0;
            D_801B483E[0] = func_80042DA8() & 0xFFF;
            for (; i < D_801B484C; i++) {
                q = (MgObjAlm *)&D_80162978[func_800BBEAC(&func_801B0010)];
                q->unk8 = p->unk8;
                q->unk1A = func_80042DA8() % 0xC00 + 0x400;
                q->unk10 = *(MgSVec *)&D_801B483E[-1];
                q->unk18 = (func_80042DA8() % 600 + 200) << 4;
                q->unk1C = func_80042DA8() % 100 - 50;
                D_801B483E[0] += 0x1000 / D_801B484C;
            }
        } else {
            for (i = 0; i < 10; i++) {
                if ((D_801B4850 >> i) & 1) {
                    func_800D5774(i);
                }
            }
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0460(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D4854 = D_801B4854 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B04C0(arg0, arg1) {
    MgTask *p;
    s32 n;
    s32 i;
    s32 sel;

    func_800D2980(&D_801B061C, 0, 0, 0);
    func_800BBEAC(func_801B0460);
    n = func_800D54BC(arg0);
    D_801B484C = n == 1 ? 6 : 3;
    D_801B4850 = arg0;
    if ((arg0 >> arg1) & 1) {
        sel = arg1;
    } else {
        n = (n - 1) / 2;
        for (i = 0; i < 10; i++) {
            if ((arg0 >> i) & 1) {
                if (n == 0) {
                    sel = i;
                    break;
                }
                n--;
            }
        }
    }
    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B0208)];
    p->unk4 = sel;
    func_800D3994(sel, D_8015190F[sel][0], (u8 *)&p->unk8);
    p->unkA = 0;
    func_800D55F4(0x20, func_800D574C(arg0), 0x81);
}
