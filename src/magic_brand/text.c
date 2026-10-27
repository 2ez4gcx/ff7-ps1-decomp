#include "common.h"
#include "magic_brand/decls.h"

M2C_UNK *func_801B0020(void) {
    func_801B0C38();
    return &D_801B5148;
}

void func_801B0048(void) {
    MgTask *p;
    s32 t;
    u8 c;
    s32 s;
    u16 *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    s = 0x1F800000;
    t = p->unk2;
    if (t < 5) {
        *(s32 *)&D_801B6D98 = 0x2E808080;
    } else {
        t -= 5;
        if (t < 5) {
            D_801B6D9B = 0x2E;
            c = -(t << 7) / 5 - 0x80;
            D_801B6D9A = c;
            D_801B6D99 = c;
            D_801B6D98 = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003C21C(&p->unkC, s);
    func_8003B35C(s, &D_801B6DA0);
    func_800D4284(&p->unk4, p->unk14, s);
    func_8003B48C(s);
    func_8003B51C(s);
    q = &D_801B6D9C;
    *q = p->unk0;
    D_801D6DFC = func_800D4D90(q - 4, D_801517C0 + 0x70, 0xC, D_801D6DFC);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B01B0(void) {
    M2C_UNK *a;
    BrFrame *q;
    MgTask *p;
    s16 n;

    a = &D_801B5080;
    p = (MgTask *)&D_80162978[D_8015169C];
    q = &D_801B6DB0;
    if (p->unk0 == 0) {
        a = &D_801B4FB8;
    }
    q->a = a;
    q->f = p->unk2;
    func_800D4368(&p->unk4, 0x1800, p->unk14);
    D_801D6DFC = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_801D6DFC);
    if (D_80062D98 == 0) {
        p->unk6 += p->unkE;
        n = ++p->unk2;
        if (n >= D_801B4FBC) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_RODATA("../asm/us/magic_brand/nonmatchings/text", D_801B0000);

void func_801B02A8(void) {
    MgMat m;
    MgTask *p;
    s16 *q;
    s16 n;
    s32 t;

    m = D_801B0000;
    p = (MgTask *)&D_80162978[D_8015169C];
    q = &D_801B6DC6;
    t = p->unk2;
    *q = t << 9;
    m.m[0][0] = m.m[1][1] = m.m[2][2] = p->unk16;
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, (MgMat *)0x1F800000);
    func_8003B48C((MgMat *)0x1F800000);
    func_8003B51C((MgMat *)0x1F800000);
    func_8003B69C(0, 0, 0);
    D_801D6DFC = func_800D29D4((u8 *)q - 0xA, D_801517C0 + 0x70, 0xC, D_801D6DFC);
    if (D_80062D98 == 0) {
        n = ++p->unk2;
        if (n >= 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B0404(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 r;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B02A8)];
            r = ((p->unk2 * 2 + i) << 11) / 30;
            i++;
            q->unk4 = p->unk4;
            q->unk6 = -((0x1000 - func_80039B40(r)) * 500 >> 12);
            q->unk8 = p->unk8;
            q->unk16 = (u32)(func_80039A74(r) * 3) >> 4;
        } while (i < 2);
        n = ++p->unk2;
        if (n >= 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B0540(void) {
    MgTask *p;
    s32 t;
    MgMat *s;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    s = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 5) {
        D_801B6DD6 = 0;
    } else {
        t -= 5;
        if (t < 10) {
            D_801B6DD6 = (t << 12) / 10;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    v = (p->unk2 << 12) / 15;
    D_801B6DDC.m[0][0] = D_801B6DDC.m[1][1] = D_801B6DDC.m[2][2] = v;
    D_801B6DDC.t[0] = p->unk4;
    D_801B6DDC.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801B6DDC, s);
    func_8003B48C(s);
    func_8003B51C(s);
    func_8003B69C(0, 0, 0);
    D_801D6DFC = func_800D29D4(&D_801B6DCC, D_801517C0 + 0x70, 0xC, D_801D6DFC);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B06C4(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 r;
    s32 n;
    s32 t;

    b = (MgTask *)D_80162978;
    p = &b[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x37) {
            q = &b[func_800BBEAC(&func_801B0048)];
            q->unk0 = 0;
            q->unk4 = p->unk4;
            q->unk6 = 0;
            q->unk8 = p->unk8;
            q->unkC = 0;
            q->unkE = 0;
            q->unk10 = -0x100;
            q->unk14 = p->unk14;
            func_800D5138(1);
        }
        if (p->unk2 == 0x38) {
            func_800D51D4(1);
        }
        if (p->unk2 == 0x39) {
            q = &b[func_800BBEAC(&func_801B0048)];
            q->unk0 = 0;
            q->unk4 = p->unk4;
            q->unk6 = 0;
            q->unk8 = p->unk8;
            q->unkC = 0;
            q->unkE = 0;
            q->unk10 = 0x100;
            q->unk14 = p->unk14;
            func_800D5138(1);
        }
        if (p->unk2 == 0x3A) {
            func_800D51D4(1);
        }
        if (p->unk2 == 0x3B) {
            q = &b[func_800BBEAC(&func_801B0048)];
            q->unk0 = 1;
            q->unk4 = p->unk4;
            q->unk6 = 0;
            q->unk8 = p->unk8;
            q->unkC = 0;
            q->unkE = 0;
            q->unk10 = 0;
            q->unk14 = p->unk14;
            func_800D5138(1);
        }
        if (p->unk2 == 0x3C) {
            func_800D51D4(1);
        }
        if ((u32)((u16)p->unk2 - 0x41) < 5) {
            i = 0;
            do {
                i++;
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B01B0)];
                q->unk0 = func_80042DA8() & 1;
                r = func_80042DA8() & 0xFFF;
                q->unk4 = p->unk4 + (func_80039A74(r) * 400 >> 12);
                q->unk6 = -(func_80042DA8() % 1000);
                q->unk8 = p->unk8 + (func_80039B40(r) * 400 >> 12);
                n = func_80042DA8();
                q->unk14 = 0;
                q->unkE = -(n % 50 + 0x32);
            } while (i < 3);
        }
        t = p->unk2;
        if (t == 0x4B) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0404)];
            *(BrB8 *)&q->unk4 = *(BrB8 *)&p->unk4;
            if (p->unk2 == t) {
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0540)];
                q->unk4 = p->unk4;
                q->unk8 = p->unk8;
            }
            t = p->unk2;
        }
        if (t == 0x55) {
            func_800D5774(p->unk0);
            if (p->unk2 == t) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0A8C(s32 arg0) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B06C4)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    p->unk14 = -D_801518F6[arg0][0];
}

void func_801B0B2C(void) {
    MgObj20 *p;
    s16 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t == 0x37) {
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x13A);
        } else if (t == 0x4B) {
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x174);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0BD8(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D6DFC = D_801B6DFC + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B0C38(arg0, arg1) {
    func_800D2980(&D_801B0CD0, 0, 0, 0);
    func_800BBEAC((M2C_UNK *)func_801B0BD8);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)func_801B0A8C);
    return func_800D54EC(arg0, (func_800BBEAC((M2C_UNK *)func_801B0B2C) << 5) + (s32)&D_8016297C);
}
