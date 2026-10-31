#include "common.h"
#include "magic_hvshot/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B103C();
    return &D_801B10AC;
}

void func_801B0028(void) {
    MgVec scale;
    MgMat m2;
    MgTask *p;
    s32 *q;
    s32 *r;
    u16 *a;
    u16 *b;
    s32 t;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x16) {
        u8 pad[0x18];
        v = t * 0xE00 / 22 + 0x200;
        scale.vx = scale.vy = scale.vz = v;
        if (D_80062D98 == 0) {
            a = &D_801B52E8;
            b = &D_801B52F0;
            *a += 0x280;
            *b -= 0x1C0;
        }
        func_8003C21C(D_801B52E4, &D_801B52B4);
        func_8003B35C(&D_801B52B4, &scale);
        func_8003A63C(&D_800FA6E0[p->unk6], &D_801B52B4, &m2);
        func_8003B48C(&m2);
        func_8003B51C(&m2);
        r = &D_801B52D8;
        q = r - 1;
        *r = 0;
        D_801D59F8 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801D59F8);
        func_8003C21C(D_801B52EC, &D_801B52B4);
        func_8003B35C(&D_801B52B4, &scale);
        func_8003A63C(&D_800FA6E0[p->unk6], &D_801B52B4, &m2);
        func_8003B35C(&m2, D_801B52F8);
        func_8003B48C(&m2);
        *r = 8;
        D_801D59F8 = func_800D29D4(q, D_801517C0 + 0x70, 0xC, D_801D59F8);
        if (t == 0x15) {
            func_800D5138(1);
            goto kill;
        }
    } else {
kill:
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_hvshot/nonmatchings/text", func_801B0258);

void func_801B03C0(void) {
    MgMat m;
    MgVec scale;
    s32 flag;
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xE) {
        s32 k;
        u8 *e;

        k = p->unk0;
        k = k * 0x10;
        e = D_801B5338;
        e = e + k;
        e[0xA] = 0x80;
        e[9] = 0x80;
        D_801B5340[k] = 0x80;
        D_801B5340[3 + p->unk0 * 0x10] = 0x2C;
        goto draw;
    }
    t -= 0xE;
    if (t >= 8) {
        goto kill;
    }
    {
        s32 k;
        u8 *e;
        s32 c;

        k = p->unk0 * 0x10;
        e = D_801B5338 + k;
        t <<= 7;
        t = -t;
        if (t < 0) {
            t += 7;
        }
        c = (t >> 3) - 0x80;
        e[0xA] = c;
        e[9] = c;
        D_801B5340[k] = c;
        D_801B5340[3 + p->unk0 * 0x10] = 0x2E;
    }
draw:
    func_8003C21C(&D_801B53B8[D_8015169C], &m);
    scale.vx = scale.vy = scale.vz = p->unk18;
    func_8003B35C(&m, &scale);
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C(&p->unk8, m.t, &flag);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801D59F8 = func_800D6260(D_801B5338 + p->unk0 * 0x10, D_801517C0 + 0x70, 0xC, D_801D59F8);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk8 += p->unk10;
        p->unkA += p->unk12;
        p->unkC += p->unk14;
        p->unk12 += 0xA;
        D_801B53B8[D_8015169C].x += D_801B53B8[D_8015169C].vx;
        D_801B53B8[D_8015169C].y += D_801B53B8[D_8015169C].vy;
        D_801B53B8[D_8015169C].z += D_801B53B8[D_8015169C].vz;
        if (p->unkA > 0) {
kill:
            p->unk0 = -1;
        }
    }
}

void func_801B0680(void) {
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xE) {
        s32 k;
        u8 *e;

        k = p->unk0;
        k = k * 0x10;
        e = D_801B5368;
        e = e + k;
        e[0xA] = 0x80;
        e[9] = 0x80;
        D_801B5370[k] = 0x80;
        goto draw;
    }
    t -= 0xE;
    if (t >= 8) {
        goto kill;
    }
    {
        s32 k;
        u8 *e;
        s32 c;

        k = p->unk0 * 0x10;
        e = D_801B5368 + k;
        t <<= 7;
        t = -t;
        if (t < 0) {
            t += 7;
        }
        c = (t >> 3) - 0x80;
        e[0xA] = c;
        e[9] = c;
        D_801B5370[k] = c;
    }
draw:
    func_800D4368(&p->unk8, p->unk18, 0);
    D_801D59F8 = func_800D6260(D_801B5368 + p->unk0 * 0x10, D_801517C0 + 0x70, 0xC, D_801D59F8);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk8 += p->unk10;
        p->unkA += p->unk12;
        p->unkC += p->unk14;
        if (p->unkA > 0) {
kill:
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_hvshot/nonmatchings/text", func_801B07F8);

void func_801B0F88(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B07F8)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B0FDC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D59F8 = D_801B59F8 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B103C(arg0, arg1) {
    func_800D2980(&D_801B1A18, 0, 0, 0);
    func_800BBEAC(&func_801B0FDC);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B0F88);
}
