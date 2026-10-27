#include "common.h"
#include "magic_reiki/decls.h"

void func_801B0000(void) {
    func_801B0D5C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EE294 = D_801D6294 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(0, 0, D_801D61C4);
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 < 0x10) {
            D_801D61C4 = (u16) D_801D61C4 + 0xF;
        }
        if (temp_s0->unk2 >= 0x11) {
            D_801D61C4 = (u16) D_801D61C4 - 0xF;
        }
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 == 0x20) {
            temp_s0->unk0 = -1;
        }
    }
}

void func_801B016C(void) {
    MgMat m;
    MgMat m2;
    MgSVec rot;
    MgTask *p;
    u8 *r;
    u8 c;
    u8 *q;
    u16 *h;
    s32 t;
    s32 u;
    s16 n;

    rot.vz = 0;
    rot.vx = 0;
    rot.vy = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    D_801D6264.vx = D_801D6264.vy = D_801D6264.vz = p->unk2 << 10;
    func_8003B35C(&m, &D_801D6264);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    D_801D61C8.unk0 = D_801D10D8;
    D_801D61C8.unk4 = 0xA8;
    t = D_801D620C;
    D_801D61C8.unkA = 0x1000 - (t << 7);
    r = func_800D29D4(&D_801D61C8, D_801517C0 + 0x70, 0xC, D_801EE294);
    D_801EE294 = r;
    D_801D61C8.unk0 = D_801D61D8[p->unk2 % 10];
    D_801D61C8.unk4 = 0x28;
    D_801D61C8.unkA = D_801D620C * 8;
    D_801EE294 = func_800D29D4(&D_801D61C8, D_801517C0 + 0x70, 0xC, r);
    func_800D4368(&p->unk4, 0x2000, 0);
    q = &D_801D6204;
    c = D_801D620C * 8;
    D_801D6206 = c;
    D_801D6205 = c;
    *q = c;
    D_801EE294 = func_800D4D90(q - 4, D_801517C0 + 0x70, 0xC, D_801EE294);
    if (D_80062D98 == 0) {
        h = &D_801031EA;
        u = *h + 0x20;
        *h = u - p->unk2 % 2 * 64;
        if (p->unk2 >= 0xF) {
            D_801D620C--;
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0430(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D6218;
    *frame = p->unk2;
    D_801EE294 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EE294);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D6084) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_reiki/nonmatchings/text", func_801B04EC);

void func_801B065C(void) {
    MgTask *p;
    u8 c;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D6244[0] = p->unk16;
    c = 0x80 - p->unk2 * 8;
    D_801D6242 = c;
    D_801D6241 = c;
    D_801D6240 = c;
    D_801EE294 = func_800D4D90(&D_801D6244[-4], D_801517C0 + 0x70, 0xC, D_801EE294);
    if (D_80062D98 == 0) {
        p->unk6 -= 300;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 15) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_reiki/nonmatchings/text", func_801B0744);

INCLUDE_ASM("../asm/us/magic_reiki/nonmatchings/text", func_801B0BDC);

INCLUDE_ASM("../asm/us/magic_reiki/nonmatchings/text", func_801B0D5C);
