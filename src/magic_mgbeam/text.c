#include "common.h"
#include "magic_mgbeam/decls.h"

void func_801B0000(void) {
    func_801B099C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CBD20 = D_801B3D20 + p->unk2 * 0xC000;
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
    func_8003C21C(&D_801B3CD0, &m);
    func_8003A79C(&D_801CBD24, &m, &m);
    func_8003B35C(&m, &D_801B3CD8);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    frame = &D_801B3CCC;
    *frame = p->unk2 % D_801B3C60;
    D_801CBD20 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801CBD20);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B01D8(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, p->unk16);
    frame = &D_801B3CF0;
    *frame = p->unk2;
    D_801CBD20 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801CBD20);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B1B58) {
            p->unk0 = -1;
        }
    }
}

void func_801B0294(void) {
    MgMat m;
    MgMat unused;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801B3D14, &m);
    func_8003A79C(&D_801CBD24, &m, &m);
    func_8003B35C(&m, &D_801B3CF4);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    D_801CBD20 = (u8 *)func_800D29D4(D_801B3D04, D_801517C0 + 0x70, 0xC, (s32)D_801CBD20);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (++p->unk2 == 7) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_mgbeam/nonmatchings/text", func_801B03DC);

void func_801B0864(s32 arg0, s32 arg1) {
    MgSVec d;
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B03DC)];
    func_800D3994(arg1, D_80151915[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    d.vx = (p->unkC.vx - p->unk4.vx) / 8;
    d.vy = (p->unkC.vy - p->unk4.vy) / 8;
    d.vz = (p->unkC.vz - p->unk4.vz) / 8;
    func_800D44E8(&d, &D_801CBD24);
}

INCLUDE_ASM("../asm/us/magic_mgbeam/nonmatchings/text", func_801B099C);
