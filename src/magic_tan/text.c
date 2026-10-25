#include "common.h"
#include "magic_tan/decls.h"

void func_801B006C(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1C00, 0);
    frame = &D_801B2038;
    *frame = p->unk2;
    D_801CA054 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801CA054);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801B0F2C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0124(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, D_801B2048[p->unk14], 0);
    D_801CA054 = func_800D4D90(D_801B203C, D_801517C0 + 0x70, 0xC, D_801CA054);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 == 0xC) {
            p->unk0 = -1;
        }
    }
}

void func_801B0210(void) {
    TnTask *p;
    TnTask *q;
    s16 i;
    s32 k;

    p = (TnTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 3) {
            i = 0;
            do {
                q = (TnTask *)&D_80162978[func_800BBEAC(&func_801B0124)];
                q->unk4 = p->unk4 - i * ((s16)p->unkC / 2);
                q->unk6 = p->unk6 - i * ((s16)p->unkE / 2);
                q->unk8 = p->unk8 - i * ((s16)p->unk10 / 2);
                q->unkC = p->unkC;
                q->unkE = p->unkE;
                q->unk10 = p->unk10;
                q->unk14 = i + p->unk2 * 2;
                i++;
            } while (i < 2);
        }
        if (p->unk2 == 0xC) {
            func_800D5774(p->unk18);
        }
        if ((u16)p->unk2 - 0xB < 9U) {
            q = (TnTask *)&D_80162978[func_800BBEAC(&func_801B006C)];
            func_800D3994(p->unk18, D_8015190F[D_800FA6D4][0], &q->unk4);
            k = 0x190;
            q->unk4 = q->unk4 - k + func_80042DA8() % 800;
            k = 0x190;
            q->unk6 = q->unk6 - k + func_80042DA8() % 800;
            k = 0x190;
            q->unk8 = q->unk8 - k + func_80042DA8() % 800;
        }
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B04F8(s32 arg0, s32 arg1) {
    MgSVec v;
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0210)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &v);
    p->unkC = (v.vx - p->unk4) / 12;
    p->unkE = (v.vy - p->unk6) / 12;
    p->unk10 = (v.vz - p->unk8) / 12;
    p->unk18 = arg0;
}

INCLUDE_RODATA("../asm/us/magic_tan/nonmatchings/text", D_801B0000);

void func_801B0634(s32 arg0, s32 arg1) {
    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B06E8, 0, 0, 0);
    func_800D2980(&D_801B0FF0, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B04F8);
    func_800BBA84(0x66, arg1, 0x40);
}
