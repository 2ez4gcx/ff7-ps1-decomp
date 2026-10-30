#include "common.h"
#include "magic_sflea/decls.h"

void func_801B0054(void) {
    func_801B1D3C();
}

void func_801B0074(s32 arg0, s32 arg1, s32 arg2) {
    SfPoly *pk;
    s32 a;
    s32 b;
    s32 i;
    s32 n;
    s32 c;
    s32 step;

    pk = (SfPoly *)D_801EBD50;
    n = 0x1E;
    a = 0;
    b = 0x13F;
    step = 0x60000;
    c = (arg0 & 0xFF) | ((arg1 & 0xFF) << 8) | ((arg2 & 0xFF) << 16);
    step = 0x60000;
    for (i = 0; i < n; i++) {
        pk->xy2 = a;
        a += step;
        pk->xy3 = b;
        b += step;
        pk->xy0 = a;
        pk->xy1 = b;
        pk->c0 = c;
        pk->tag.len = 5;
        *((u8 *)&pk->c0 + 3) = 0x28;
        pk->tag.addr = ((SfOt *)D_801517C0)->head.addr;
        ((SfOt *)D_801517C0)->head.addr = (u32)pk;
        pk++;
    }
    D_801EBD50 = (s32)pk;
}

void func_801B0144(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 c;

    rot.vx = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vy = p->unkE + p->unk10;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk14;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    ((MgScratch *)0x1F800000)->unk0 = &D_801D27D0;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x40;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x16) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0x16) * 0x10;
    }
    D_801EBD50 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801EBD50);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        if (p->unk14 < 0) {
            p->unk14 = 0x7000;
        }
        p->unkE += p->unk12;
        p->unk2++;
    }
}

void func_801B0304(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 c;

    rot.vx = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vy = p->unkE;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk14;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    ((MgScratch *)0x1F800000)->unk0 = &D_801D39F4;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x40;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x16) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0x16) * 0x10;
    }
    D_801EBD50 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801EBD50);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        if (p->unk14 < 0) {
            p->unk14 = 0x7000;
        }
        p->unkE += p->unk12;
        p->unk2++;
    }
}

void func_801B04BC(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 c;

    rot.vx = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vy = p->unkE;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk14;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    ((MgScratch *)0x1F800000)->unk0 = &D_801D39F4;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x40;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x18) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0x18) * 0x10;
    }
    D_801EBD50 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801EBD50);
    if (p->unk2 >= 0x20) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        if (p->unk14 < 0) {
            p->unk14 = 0x7000;
        }
        p->unkE += p->unk12;
        p->unk2++;
    }
}

void func_801B0674(void) {
    u8 pad[0x38];
    MgTask *p;
    s32 t;
    s32 c;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk14, -p->unk12);
    t = p->unk2;
    c = 0x80;
    if (t >= 0x16) {
        c = 0x80 - (t - 0x16) * 0x10;
    }
    D_801D3C66 = c;
    D_801D3C65 = c;
    D_801D3C64[0] = c;
    D_801D3C68 = p->unkC;
    D_801EBD50 = func_800D4D90(&D_801D3C64[-4], D_801517C0 + 0x70, 0xC, D_801EBD50);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        v = p->unk14 + p->unk16;
        p->unk14 = v;
        if (v < 0) {
            p->unk14 = 0x7000;
        }
        if (p->unk2 >= 5) {
            p->unkC++;
        }
        if (p->unkC >= 0x10) {
            p->unkC = 0xF;
        }
        p->unk2++;
    }
}

void func_801B07C8(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgSVec a;
    MgSVec b;
    MgSVec c;
    MgSVec d;
    s32 ext;
    s32 flag;
    MgTask *p;
    SfFT4 *q;
    s32 col;
    s32 t;
    s32 r;

    rot.vx = 0x400;
    rot.vy = 0;
    rot.vz = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    col = 0x80;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk14;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    a.vx = -0x120;
    a.vy = -0x120;
    a.vz = 0;
    b.vx = 0x120;
    b.vy = -0x120;
    b.vz = 0;
    c.vx = -0x120;
    c.vy = 0x120;
    c.vz = 0;
    d.vx = 0x120;
    d.vy = 0x120;
    d.vz = 0;
    t = p->unk2;
    q = (SfFT4 *)D_801EBD50;
    if (t >= 0x16) {
        col = 0x80 - (t - 0x16) * 0x10;
    }
    col = col | (col << 8) | (col << 16);
    r = func_8003BD7C(&a, &b, &c, &d, &q->xy0, &q->xy1, &q->xy2, &q->xy3, &ext, &flag);
    q->tag.len = 9;
    *((u8 *)&q->rgbc + 3) = 0x2C;
    q->rgbc = col | 0x2E000000;
    q->tpage = 0x4F;
    q->clut = 0x7908;
    q->uv0 = 0x8000;
    q->uv1 = 0x8080;
    q->uv2 = 0xFF00;
    q->uv3 = 0xFF80;
    r = ((r >> 2) << 2) + D_801517C0;
    q->tag.addr = ((SfTag *)(r + 0x70))->addr;
    ((SfTag *)(r + 0x70))->addr = (u32)q;
    q++;
    D_801EBD50 = (s32)q;
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        if (p->unk14 < 0) {
            p->unk14 = 0x7000;
        }
        p->unk2++;
    }
}

void func_801B0A3C(void) {
    MgSVec rot;
    MgVec v;
    MgMat m;
    MgTask *p;
    s32 t;
    s32 c;

    rot.vx = 0x400;
    rot.vy = 0;
    rot.vz = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk14;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    t = p->unk2;
    c = 0x80;
    if (t >= 0x16) {
        c = 0x80 - (t - 0x16) * 0x10;
    }
    D_801D3C72 = c;
    D_801D3C71 = c;
    D_801D3C70[0] = c;
    D_801D3C74 = 0;
    D_801EBD50 = func_800D4D90(&D_801D3C70[-4], D_801517C0 + 0x70, 0xC, D_801EBD50);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        if (p->unk14 < 0) {
            p->unk14 = 0x7000;
        }
        p->unk2++;
    }
}

void func_801B0BC4(void) {
    MgObj20 *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    frame = &D_801D3C80;
    *frame = D_801D3C48[p->unk2];
    D_801EBD50 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EBD50);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0C90(void) {
    MgTask *p;
    s32 n;
    s32 t;
    s32 u;
    s32 c;
    u16 a;
    u8 pad[8];

    p = (MgTask *)&D_80162978[D_8015169C];
    n = 0xE;
    if (p->unk18 != 0) {
        a = p->unk16;
        D_801D3C8C[0] = 7 - (p->unk2 >> 1);
        t = p->unk2;
        c = 0x80;
        if (t >= 8) {
            c = 0x80 - (t - 8) * 0x15;
        }
        D_801D3C88 = D_801D3C89 = D_801D3C8A = c;
    } else {
        n = 7;
        u = p->unk2;
        a = 0x2000 - (u << 9);
        D_801D3C8C[0] = u;
    }
    func_800D4368(&p->unk4, (s16)a, p->unk14);
    D_801EBD50 = (u8 *)func_800D4D90(D_801D3C84, D_801517C0 + 0x70, 0xC, (s32)D_801EBD50);
    if (p->unk2 >= n) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
    }
}

void func_801B0E10(void) {
    MgTask *p;
    MgTask *r;
    MgTask *q;

    if (D_80062D98 == 0) {
        p = (MgTask *)&D_80162978[D_8015169C];
        if (p->unk2 == 0x2C) {
            r = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B07C8)];
            *(MgB8 *)&r->unk4 = *(MgB8 *)&p->unk4;
            r->unk6 = 0;
            r->unk14 = 0;
            r->unk16 = (p->unk14 << 12) / 6912;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0674)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&r->unk4;
            q->unk6 = -(p->unk14 >> 1);
            q->unkC = 0;
            q->unk12 = p->unk14 >> 3;
            q->unk14 = 0;
            q->unk16 = (p->unk14 << 12) / 9216;
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B0F7C);

s32 func_801B17C8(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s32 r;
    s16 t;

    D_80162978[D_8015169C].unk0 = -1;
    r = func_800BBEAC((M2C_UNK *)func_801B0F7C);
    do {
        b = (MgTask *)D_80162978;
    } while (0);
    p = &b[r];
    func_800D3994(D_801EBD58, D_8015190F[D_801EBD58][0], &p->unk4);
    p->unkC = 0;
    t = D_801518F6[D_801EBD58][0] + 0x200;
    p->unk14 = t;
    if (t >= 0x76D) {
        p->unk14 = 0x76C;
    }
    p->unk6 = -p->unk14;
    q = &b[func_800BBEAC((M2C_UNK *)func_801B0E10)];
    *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
    q->unk14 = p->unk14 << 1;
    return func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x174);
}

INCLUDE_ASM("../asm/us/magic_sflea/nonmatchings/text", func_801B1938);

INCLUDE_RODATA("../asm/us/magic_sflea/nonmatchings/text", D_801B0000);

s32 func_801B1D3C(arg0) {
    s32 i;
    s32 n;

    D_801EBD54 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B1E10, 0, 0, 0);
    i = 0;
    n = 0;
    do {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801EBD58 = i;
            }
        }
        i++;
    } while (i < 10);
    func_800BBEAC((M2C_UNK *)func_801B1938);
    D_800F5B70[0] = D_800F5B70[1] = D_800F5B70[2] = 0;
    D_801EBD5F = 0;
}
