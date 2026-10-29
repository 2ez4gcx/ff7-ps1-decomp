#include "common.h"
#include "magic_thundg2/decls.h"

void func_801B000C(void) {
    func_801B0F1C();
}

INCLUDE_RODATA("../asm/us/magic_thundg2/nonmatchings/text", D_801B0000);

void func_801B002C(void) {
    ThSprC t;
    MgSVec v;
    MgTask *p;
    s32 c;
    s32 k;
    s32 i;

    t = D_801B0000;
    p = (MgTask *)&D_80162978[D_8015169C];
    k = p->unk2;
    if (k < 0) {
        D_801D1DB8 = 0;
    } else if (k <= 0) {
        D_801D1DB8 = 0x2500;
    } else {
        k -= 1;
        if (k < 4) {
            c = -0x80 - k * 0x20;
            D_801D1DB8 = 0x2500;
            t.r = t.g = t.b = c;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_800D4284(&p->unk8, -0x1F4, &D_801D1DB8);
    func_8003B48C((MgMat *)&D_801D1DB8);
    func_8003B51C((MgMat *)&D_801D1DB8);
    D_801EDE8C = func_800D4D90(&t, D_801517C0 + 0x70, 0xC, D_801EDE8C);
    i = 0;
    if (D_80062D98 == 0) {
        do {
            i++;
            v.vx = p->unk8 + func_80042DA8() % 1600 - 800;
            v.vy = 0;
            v.vz = p->unkC + func_80042DA8() % 1600 - 800;
            func_800D3F0C(&v, 0x3000, 0x3000);
        } while (i < 3);
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_thundg2/nonmatchings/text", func_801B0224);

void func_801B0540(void) {
    MgTask *p;
    MgMat *m;
    s32 *q;
    s32 t;
    s32 k;
    s16 v;
    u8 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = (u16)p->unk2 & 7;
    if (t < 4) {
        v = 0x1800;
    } else {
        t -= 4;
        v = -0x1800;
    }
    D_801D1E24 = v;
    if (t < 2) {
        D_801D1E18 = &D_801D17E4;
    } else {
        D_801D1E18 = &D_801D1844;
    }
    D_801D1E20 = t & 1;
    k = *(s16 *)((u8 *)p + 2);
    if (k < 4) {
        c = k << 5;
        D_801D1E1C = D_801D1E1D = D_801D1E1E = c;
    } else {
        k -= 4;
        if (k < 0xF) {
            c = 0x80;
            D_801D1E1C = D_801D1E1D = D_801D1E1E = c;
        } else {
            k -= 0xF;
            if (k < 4) {
                c = -(k << 7) / 4 - 0x80;
                D_801D1E1C = D_801D1E1D = D_801D1E1E = c;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    q = &D_801D1E40;
    m = (MgMat *)(q - 7);
    *q = func_8003B66C() * 8;
    func_8003B48C(m);
    func_8003B51C(m);
    D_801EDE8C = func_800D4D90(&D_801D1E18, D_801517C0 + 0x4084, 3, D_801EDE8C);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B06D0(void) {
    MgTask *p;
    s16 *frame;
    s16 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    frame = &D_801D1E4C;
    *frame = (u16)p->unk2 << 16 >> 24;
    func_800D4368(&p->unk8, 0x3000, 0);
    D_801EDE8C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EDE8C);
    if (D_80062D98 == 0) {
        t = p->unk2 + 0x100;
        p->unk2 = t;
        if (t >> 8 >= D_801D1738) {
            p->unk0 = -1;
        }
    }
}

void func_801B079C(void) {
    MgMat m;
    MgTask *p;
    s16 *q;
    s32 k;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = p->unk2;
    if (k < 8) {
        D_801D1E5A = 0x80;
    } else {
        k -= 8;
        if (k < 8) {
            D_801D1E5A = -(k << 7) / 8 + 0x80;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    v = p->unk2 * 0x480;
    q = &D_801D1E60;
    D_801D1E6A[2] = v;
    *q = v;
    D_801D1E6A[0] = -v;
    D_801D1E74[0] = p->unk8;
    D_801D1E74[1] = p->unkA;
    D_801D1E74[2] = p->unkC;
    func_8003A63C(&D_800FA63C, (MgMat *)q, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801EDE8C = func_800D29D4(&D_801D1E50, D_801517C0 + 0x70, 0xC, D_801EDE8C);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0908(void) {
    u8 pad[0x30];
    MgTask *p;
    MgTask *q;
    MgTask *r;
    ThBolt *b;
    s32 i;
    s32 j;
    s32 k;
    u16 t;
    s32 t2;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_800F5B70 = 0;
            D_800F5B71 = 0;
            D_800F5B72 = 0;
            func_800D52A0(0x800, 4);
        }
        t = p->unk2;
        if (t - 6 < 0x14U) {
            if (((s16)t - 6 & 3) == 0) {
                i = 0;
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B002C)];
                q->unk8 = *(u16 *)&D_801D1E84 + func_80042DA8() % 3000 * 2 - 3000;
                *(u16 *)((u8 *)q + 0xA) = 0;
                q->unkC = D_801D1E88 + func_80042DA8() % 1500 * 2 - 1500;
                do {
                    i++;
                    b = (ThBolt *)&D_80162978[func_800BBEAC(func_801B0224)];
                    *(ThB8 *)&b->unk4 = *(ThB8 *)&q->unk8;
                    b->unkC = func_80042DA8() % 200 - 100;
                    b->unkE = -(func_80042DA8() % 200 + 200);
                    b->unk10 = func_80042DA8() % 200 - 100;
                    b->unk18[0] = func_80042DA8() % 10 - 5;
                    b->unk18[1] = func_80042DA8() % 20 - 10;
                    b->unk18[2] = func_80042DA8() % 40 - 20;
                    b->unk1C = func_80042DA8() % 0x2400 + 0x400;
                    b->unk0 = 0;
                } while (i < 3);
                r = (MgTask *)&D_80162978[func_800BBEAC(func_801B079C)];
                *(ThB8 *)&r->unk8 = *(ThB8 *)&q->unk8;
            }
        }
        if (p->unk2 == 0x28) {
            i = 0;
            do {
                if (D_801D1E80 >> i & 1) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
        }
        if ((u16)(p->unk2 - 0x18) < 4U) {
            i = 0;
            do {
                j = 0;
                do {
                    if (D_801D1E80 >> j & 1) {
                        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B06D0)];
                        func_800D3994(j, D_8015190F[j][0], &q->unk8);
                        k = 0x4B0;
                        q->unk8 = q->unk8 - k + func_80042DA8() % 2400;
                        q->unkA = q->unkA - k + func_80042DA8() % 2400;
                        q->unkC = q->unkC - k + func_80042DA8() % 2400;
                    }
                    j++;
                } while (j < 10);
                i++;
            } while (i < 1);
        }
        if (p->unk2 == 0x24) {
            func_800BBEAC(func_801B0540);
        }
        t2 = p->unk2;
        if (t2 == 0x44) {
            func_800D52A0(0, 4);
            if (p->unk2 == t2) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0EB4(void) {
    MgTask *p;
    u8 *buf;

    p = &D_80162978[D_8015169C];
    buf = D_801B0FDC;
    if (p->unk2 == 0) {
        buf = D_801D1E8C;
    }
    D_801EDE8C = buf;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B0F1C(arg0, arg1) {
    MgTask *p;
    s32 c;

    if (D_801517BC == 0) {
        func_800D2980(D_801B0FDC, 0, 0, 0);
    }
    func_800BBEAC(func_801B0EB4);
    D_801D1E80 = arg0;
    func_800D54EC(arg0, &D_801D1E84);
    p = &D_80162978[func_800BBEAC(func_801B0908)];
    c = D_800FA6D4;
    p->unk6 = arg1;
    p->unk4 = c;
    return func_800D55F4(0x20, 0x40, 0x56, c);
}
