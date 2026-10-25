#include "common.h"
#include "magic_thunder/decls.h"

void func_801B0000(void) {
    func_801B06CC();
}

void func_801B0020(void) {
    MgMat m;
    MgTask *p;
    s32 f;
    u16 *q;
    u16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    f = p->unk2;
    if (f < 8) {
        D_801C0E56 = 0x80;
    } else if (f < 0x10) {
        D_801C0E56 = 0x80 - ((f - 8) * 0x10);
    } else {
        p->unk0 = -1;
        return;
    }
    q = &D_801C0E2C;
    t = p->unk16;
    D_801C0E3A.v = t;
    *q = t;
    D_801C0E36 = -p->unk16;
    D_801C0E40 = M2C_FIELD(p, s16 *, 4);
    D_801C0E44 = M2C_FIELD(p, s16 *, 6);
    D_801C0E48 = M2C_FIELD(p, s16 *, 8);
    func_8003A63C(&D_800FA63C, (MgMat *)q, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801E0E78 = func_800D29D4(&D_801C0E4C, D_801517C0 + 0x70, 0xC, D_801E0E78);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk16 += p->unk18;
    }
}

void func_801B0180(void) {
    MgTask *p;
    s16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, p->unk1C);
    frame = &D_801C0E64;
    *frame = p->unk2 >> 1;
    D_801E0E78 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801E0E78);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 9) {
            p->unk0 = -1;
        }
    }
}

void func_801B023C(void) {
    MgTask *p;
    s16 *m;
    s16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    m = func_800D4368(&p->unk4, 0x2000, p->unk1C);
    if (p->unk1A & 1) {
        m[0] = -m[0];
    }
    if (p->unk1A & 2) {
        m[4] = -m[4];
    }
    func_8003B48C(m);
    func_8003B51C(m);
    frame = &D_801C0E70;
    *frame = p->unk2;
    D_801E0E78 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801E0E78);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B0350(void) {
    MgObjThunder *p;
    MgObjThunder *q;

    p = (MgObjThunder *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgObjThunder *)&D_80162978[func_800BBEAC(&func_801B0180)];
            q->unk4 = p->unk4;
            q->unk4.vy = 0;
            q->unk1C = p->unk1C;
            func_800D5774(p->unk14);
        }
        if (p->unk2 == 0) {
            q = (MgObjThunder *)&D_80162978[func_800BBEAC(&func_801B0020)];
            q->unk4 = p->unk4;
            q->unk16 = 0x1000;
            q->unk4.vy = 0;
            q->unk18 = 0x200;
            q->unk1C = p->unk1C;
        }
        if (p->unk2 >= 2) {
            q = (MgObjThunder *)&D_80162978[func_800BBEAC(&func_801B023C)];
            q->unk4.vx = p->unk4.vx + func_80042DA8() % 1000 - 500;
            q->unk4.vy = p->unk4.vy + func_80042DA8() % 1000 - 500;
            q->unk4.vz = p->unk4.vz + func_80042DA8() % 1000 - 500;
            q->unk1A = func_80042DA8() & 3;
            q->unk1C = p->unk1C;
        }
        p->unk2++;
        if (p->unk2 == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B05A4(s32 arg0) {
    MgTask *p;
    s16 *q;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0350)];
    q = &p->unk4;
    func_800D3994(arg0, D_8015190F[arg0][0], q);
    p->unk14 = arg0;
    p->unk1C = -D_801518F6[arg0][0];
    func_800D55F4(0x20, func_800D56A8(q), 0xB);
}

void func_801B066C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E0E78 = D_801C0E78 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B06CC(arg0, arg1) {
    func_800D2980(&D_801B0DAC, 0, 0, 0);
    func_800BBEAC(func_801B066C);
    return func_800D5444(arg0, arg1, 2, &func_801B05A4);
}
