#include "common.h"
#include "magic_flea/decls.h"

void func_801B0054(void) {
    func_801B15CC();
}

void func_801B0074(void) {
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
    ((MgScratch *)0x1F800000)->unk0 = &D_801D2058;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x10) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0x10) * 0x10;
    }
    D_801EB5D8 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801EB5D8);
    if (p->unk2 >= 0x18) {
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

void func_801B0234(void) {
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
    ((MgScratch *)0x1F800000)->unk0 = &D_801D327C;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x10) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0x10) * 0x10;
    }
    D_801EB5D8 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801EB5D8);
    if (p->unk2 >= 0x18) {
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

void func_801B03EC(void) {
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
    ((MgScratch *)0x1F800000)->unk0 = &D_801D327C;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x12) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0x12) * 0x10;
    }
    D_801EB5D8 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801EB5D8);
    if (p->unk2 >= 0x1A) {
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

void func_801B05A4(void) {
    u8 pad[0x38];
    MgTask *p;
    s32 t;
    s32 c;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk14, -p->unk12);
    t = p->unk2;
    c = 0x80;
    if (t >= 0x10) {
        c = 0x80 - (t - 0x10) * 0x10;
    }
    D_801D34EE = c;
    D_801D34ED = c;
    D_801D34EC[0] = c;
    D_801D34F0 = p->unkC;
    D_801EB5D8 = func_800D4D90(&D_801D34EC[-4], D_801517C0 + 0x70, 0xC, D_801EB5D8);
    if (p->unk2 >= 0x18) {
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

void func_801B06F8(void) {
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
    if (t >= 0x10) {
        c = 0x80 - (t - 0x10) * 0x10;
    }
    D_801D34FA = c;
    D_801D34F9 = c;
    D_801D34F8[0] = c;
    D_801D34FC = 0;
    D_801EB5D8 = func_800D4D90(&D_801D34F8[-4], D_801517C0 + 0x70, 0xC, D_801EB5D8);
    if (p->unk2 >= 0x18) {
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

void func_801B0880(void) {
    MgObj20 *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    frame = &D_801D3508;
    *frame = D_801D34D0[p->unk2];
    D_801EB5D8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EB5D8);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B094C(void) {
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
        D_801D3514[0] = 7 - (p->unk2 >> 1);
        t = p->unk2;
        c = 0x80;
        if (t >= 8) {
            c = 0x80 - (t - 8) * 0x15;
        }
        D_801D3510 = D_801D3511 = D_801D3512 = c;
    } else {
        n = 7;
        u = p->unk2;
        a = 0x2000 - (u << 9);
        D_801D3514[0] = u;
    }
    func_800D4368(&p->unk4, (s16)a, p->unk14);
    D_801EB5D8 = (u8 *)func_800D4D90(D_801D350C, D_801517C0 + 0x70, 0xC, (s32)D_801EB5D8);
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

void func_801B0ACC(void) {
    MgTask *p;
    MgTask *r;
    MgTask *q;

    if (D_80062D98 == 0) {
        p = (MgTask *)&D_80162978[D_8015169C];
        if (p->unk2 == 0x2C) {
            r = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B06F8)];
            *(MgB8 *)&r->unk4 = *(MgB8 *)&p->unk4;
            r->unk6 = 0;
            r->unk14 = 0;
            r->unk16 = (p->unk14 << 12) / 6912;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0234)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&r->unk4;
            q->unkE = 0;
            q->unk10 = 0;
            q->unk12 = -0x80;
            q->unk14 = 0;
            q->unk16 = (p->unk14 << 12) / 17200;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B03EC)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&r->unk4;
            q->unkE = 0;
            q->unk10 = 0;
            q->unk12 = -0x40;
            q->unk14 = 0;
            q->unk16 = (p->unk14 << 12) / 23600;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0074)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&r->unk4;
            q->unk6 = -(p->unk14 >> 1);
            q->unkE = 0;
            q->unk10 = 0;
            q->unk12 = -0x80;
            q->unk14 = 0;
            q->unk16 = (p->unk14 << 12) / 18000;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0074)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&r->unk4;
            q->unk6 = -(p->unk14 >> 1);
            q->unkE = 0;
            q->unk10 = 0x200;
            q->unk12 = -0x40;
            q->unk14 = 0;
            q->unk16 = (p->unk14 << 12) / 19200;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B05A4)];
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

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B0E34);

void func_801B147C(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s32 r;
    s16 t;

    D_80162978[D_8015169C].unk0 = -1;
    r = func_800BBEAC((M2C_UNK *)func_801B0E34);
    b = (MgTask *)D_80162978;
    p = &b[r];
    func_800D3994(D_801EB5E0, D_8015190F[D_801EB5E0][0], &p->unk4);
    p->unkC = 0;
    t = D_801518F6[D_801EB5E0][0] + 0x200;
    p->unk14 = t;
    if (t >= 0x76D) {
        p->unk14 = 0x76C;
    }
    p->unk6 = -p->unk14;
    q = &b[func_800BBEAC((M2C_UNK *)func_801B0ACC)];
    *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
    q->unk14 = p->unk14 << 1;
}

INCLUDE_RODATA("../asm/us/magic_flea/nonmatchings/text", D_801B0000);

s32 func_801B15CC(arg0) {
    s32 i;
    s32 n;

    D_801EB5DC = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B1698, 0, 0, 0);
    i = 0;
    n = 0;
    do {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801EB5E0 = i;
            }
        }
        i++;
    } while (i < 10);
    func_800BBEAC((M2C_UNK *)func_801B147C);
    return func_800D55F4(0x20, func_800D574C(arg0), 0x174);
}
