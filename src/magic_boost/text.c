#include "common.h"
#include "magic_boost/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B046C();
    return &D_801B868C;
}

void func_801B0028(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801BA26C;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801B85F8) {
            p->unk0 = -1;
        }
    }
}

void func_801B00E0(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801BA278;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4.vx += p->unkC.vx;
        p->unk4.vy += p->unkC.vy;
        p->unk4.vz += p->unkC.vz;
        p->unk2++;
        if (p->unk2 == D_801B8530) {
            p->unk0 = -1;
        }
    }
}

void func_801B01C8(void) {
    MgObjAwa *p;
    MgObjAwa *q;
    s16 i;
    s32 a;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x20) {
            func_800BBA84(0x30, p->unk1E, 0);
        }
        if (p->unk2 == 0x3A) {
            i = 0;
            do {
                q = (MgObjAwa *)&D_80162978[func_800BBEAC(func_801B00E0)];
                a = (i << 16) >> 8;
                q->unk4.vx = p->unkC.vx;
                q->unk4.vy = 0;
                q->unk4.vz = p->unkC.vz;
                q->unkC.vx = (u32)(func_80039A74(a) * 0x19) >> 9;
                q->unkC.vz = (u32)(func_80039B40(a) * 0x19) >> 9;
                i++;
                q->unkC.vy = -func_80042DA8() % 200;
            } while (i < 0x10);
            func_800D4CBC(p->unk1C, 0x21, 0x1000);
            func_800BBA84(0x15A, p->unk1E, 0);
        }
        if (p->unk2 == 0x44) {
            q = (MgObjAwa *)&D_80162978[func_800BBEAC(func_801B0028)];
            q->unk4.vx = p->unkC.vx;
            q->unk4.vy = p->unkC.vy;
            q->unk4.vz = p->unkC.vz;
            func_800D5774(p->unk1C);
            func_800BBA84(0x141, p->unk1E, 0);
        }
        p->unk2++;
        if (p->unk2 == 0x64) {
            p->unk0 = -1;
        }
    }
}

void func_801B03D8(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC((void *)func_801B01C8)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    p->unk1E = arg1;
}

void func_801B046C(arg0, arg1) {
    func_800D2980(&D_801B04CC, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B03D8);
}
