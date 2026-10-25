#include "common.h"
#include "magic_harrier/decls.h"

void func_801B0000(void) {
    func_801B0D58();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E140C = D_801C940C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgMat m;
    MgTask *p;
    s16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801C93A8, &m);
    func_8003A79C(&D_801E1410, &m, &m);
    func_8003B35C(&m, &D_801C93B0);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    frame = &D_801C93A4;
    *frame = p->unk2 % D_801C9338;
    D_801E140C = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801E140C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B01D8(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, D_801C93D8[p->unk1A], 0);
    D_801C93C0[0] = (s32)D_801C93CC[p->unk1A];
    D_801C93C8 = p->unk2;
    D_801E140C = (u8 *)func_800D4D90(D_801C93C0, D_801517C0 + 0x70, 0xC, (s32)D_801E140C);
    if (D_80062D98 == 0) {
        if (p->unk1A == 0) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
        }
        if (++p->unk2 >= D_801C93CC[p->unk1A][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0324(void) {
    MgMat m;
    MgMat m2;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801C9400, &m);
    func_8003A79C(&D_801E1410, &m, &m);
    func_8003B35C(&m, &D_801C93E0);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    D_801C93F0[0] = D_801B0DD4;
    D_801E140C = (u8 *)func_800D29D4(D_801C93F0, D_801517C0 + 0x70, 0xC, (s32)D_801E140C);
    D_801C93F0[0] = D_801B0EB8;
    D_801E140C = (u8 *)func_800D29D4(D_801C93F0, D_801517C0 + 0x70, 0xC, (s32)D_801E140C);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;

        p->unk8 += p->unk10;
        if (++p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_harrier/nonmatchings/text", func_801B04B4);

void func_801B0C20(s32 arg0, s32 arg1) {
    MgSVec d;
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B04B4)];
    func_800D3994(arg1, D_80151915[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    d.vx = (p->unkC.vx - p->unk4.vx) / 8;
    d.vy = (p->unkC.vy - p->unk4.vy) / 8;
    d.vz = (p->unkC.vz - p->unk4.vz) / 8;
    func_800D44E8(&d, &D_801E1410);
}

s32 func_801B0D58(arg0, arg1) {
    func_800BBEAC((M2C_UNK *)func_801B0020);
    func_800D2980(&D_801B0F9C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B0C20);
    return func_800BBA84(0x65, arg1, 0x40);
}
