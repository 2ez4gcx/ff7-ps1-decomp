#include "common.h"
#include "magic_freeze/decls.h"

void func_801B0000(void) {
    func_801B17D0();
}

void func_801B0020(void) {
    MgTask *p;
    s32 t;
    s32 a;
    s32 c;
    s32 v;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        c = (t << 7) / 5;
    } else {
        c = 0x80;
    }
    D_801D5E2E.v = c;
    D_801D5E2D.v = c;
    D_801D5E2C.v = c;
    a = p->unk2;
    v = a + p->unk0;
    if (v < 0x19) {
        if (D_80062D98 == 0) {
            p->unk6 += func_80039A74((a << 12) / 40) * 70 >> 12;
        }
    } else {
        v -= 0x19;
        if (v < 5) {
            if (v == 0) {
                *(s16 *)((u8 *)p + 0xC) = (D_801E5F38 - p->unk4) / 5;
                *(s16 *)((u8 *)p + 0xE) = (D_801E5F3A - p->unk6) / 5;
                *(s16 *)((u8 *)p + 0x10) = (D_801E5F3C - p->unk8) / 5;
            }
            if (D_80062D98 == 0) {
                p->unk4 += p->unkC;
                p->unk6 += p->unkE;
                p->unk8 += p->unk10;
            }
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_800D4368(&p->unk4, p->unk14, 0);
    D_801E5F30 = func_800D4D90(D_801D5E28, D_801517C0 + 0x70, 0xC, D_801E5F30);
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B026C(void) {
    MgTask *p;
    MgTask *q;
    MgMat *m;
    MgSVec *rot;
    MgVec *v;
    s32 *flag;
    MgSVec *e;
    s32 i;
    s32 r;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        m = (MgMat *)0x1F800000;
        rot = (MgSVec *)0x1F800020;
        v = (MgVec *)0x1F800028;
        flag = (s32 *)0x1F800038;
        i = 0;
        e = (MgSVec *)&D_801E5F38;
        do {
            i++;
            q = &D_80162978[func_800BBEAC(&func_801B0020)];
            q->unk0 = p->unk2;
            r = func_80042DA8() % 3000 + 0x7D0;
            rot->vx = 0;
            rot->vy = func_80042DA8() & 0xFFF;
            t = func_80042DA8();
            rot->vz = 0x100 - t % 2560;
            func_8003C21C(rot, m);
            m->t[0] = e->vx;
            m->t[1] = e->vy;
            m->t[2] = e->vz;
            func_8003B48C(m);
            func_8003B51C(m);
            rot->vx = r;
            rot->vy = 0;
            rot->vz = 0;
            func_8003BC6C(rot, v, flag);
            q->unk4 = *(u16 *)&v->vx;
            q->unk6 = *(u16 *)&v->vy;
            q->unk8 = *(u16 *)&v->vz;
            q->unk14 = func_80042DA8() % 3328 + 0x500;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B04B8(void) {
    MgTask *p;
    MgMat *m;
    s32 t;
    s32 u;

    m = (MgMat *)0x1F800000;
    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        D_801D5E38 = 0x88;
        D_801D5E3E = -(t << 12) / 5 + 0x1000;
    } else {
        t -= 5;
        if (t < 0x28) {
            D_801D5E38 = 0x80;
            D_801D5E3E = 0;
        } else {
            t -= 0x28;
            if (t < 0xF) {
                D_801D5E38 = 0x88;
                D_801D5E3E = (t << 12) / 15;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801D5E58[0] = p->unk4;
    u = p->unk6;
    D_801D5E5C = u;
    u = p->unk8;
    D_801D5E60 = u;
    func_8003A63C(D_800FA63C, (u8 *)D_801D5E58 - 0x14, m);
    func_8003B48C(m);
    func_8003B51C(m);
    func_8003B69C(0, 0, 0);
    D_801E5F30 = func_800D29D4(D_801D5E34, D_801517C0 + 0x70, 0xC, D_801E5F30);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B067C(void) {
    MgSVec sp10;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    MgTask *p;
    MgMat *m;
    s32 k;
    s32 t;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 4) {
        D_801D5E6E = 0;
        k = t * 0x440 + 0x400;
    } else {
        t -= 4;
        if (t < 4) {
            D_801D5E6E = t << 10;
            k = 0x1500;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003B48C(D_800FA63C);
    func_8003B51C(D_800FA63C);
    func_8003BBDC(&p->unk4, &sp10, &sp18, &sp1C);
    func_8003B64C(&sp20, &sp24);
    D_801D5E88[0] = (sp10.vx - sp20) << 5;
    D_801D5E8C = (sp10.vy - sp24) << 5;
    m = (MgMat *)((u8 *)D_801D5E88 - 0x14);
    D_801D5E90 = func_8003B66C(sp24) << 5;
    *(s16 *)((u8 *)D_801D5E88 - 0x14) = D_801D5E7C = D_801D5E84 = k;
    func_8003B48C(m);
    func_8003B51C(m);
    func_8003B69C(0, 0, 0);
    D_801E5F30 = func_800D29D4(D_801D5E64, D_801517C0 + 0x4084, 0, D_801E5F30);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0828(void) {
    MgTask *p;
    MgMat *m;
    s32 t;
    s32 u;

    m = (MgMat *)0x1F800000;
    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xA) {
        D_801D5E9E = 0;
    } else {
        t -= 0xA;
        if (t < 5) {
            D_801D5E9E = (t << 12) / 5;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    D_801D5EA4.m[0][0] = D_801D5EB4.v = p->unk2 * 0x100 + 0x100;
    D_801D5EAC.v = p->unk2 * 0x700 / 15 + 0x100;
    u = p->unk4;
    D_801D5EB8 = u;
    u = p->unk6;
    D_801D5EBC = u;
    u = p->unk8;
    D_801D5EC0 = u;
    func_8003A63C(D_800FA63C, &D_801D5EA4, m);
    func_8003B48C(m);
    func_8003B51C(m);
    func_8003B69C(0, 0, 0);
    D_801E5F30 = func_800D29D4(D_801D5E94, D_801517C0 + 0x70, 0xC, D_801E5F30);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B09D4(void) {
    MgTask *p;
    MgTask *q;
    s16 t;
    s16 r;
    s16 u;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        r = t % 5;
        if (r == 0) {
            q = &D_80162978[func_800BBEAC(&func_801B0828)];
            u = D_801E5F38;
            *(s16 *)((u8 *)q + 6) = 0;
            q->unk4 = u;
            u = D_801E5F3C;
            q->unk8 = u;
        }
        t = p->unk2 + 1;
        p->unk2 = t;
        if (t >= 5) {
            p->unk0 = -1;
        }
    }
}

void func_801B0AC0(void) {
    MgTask *p;
    MgMat *m;
    s32 t;
    s32 u;
    s32 k;

    m = (MgMat *)0x1F800000;
    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        D_801D5EC4.unk4 = 0x80;
        D_801D5EC4.unkA = 0;
        k = p->unk2 * 0x90 + 0x80;
        D_801D5ED4 = D_801D5EDC = D_801D5EE4 = k;
    } else {
        t -= 5;
        if (t < 0x1E) {
            D_801D5EC4.unk4 = 0x80;
            k = 0x350;
            D_801D5EC4.unkA = 0;
            D_801D5ED4 = D_801D5EDC = D_801D5EE4 = k;
        } else {
            t -= 0x1E;
            if (t < 0xF) {
                D_801D5EC4.unk4 = 0x88;
                k = 0x350;
                D_801D5ED4 = D_801D5EDC = D_801D5EE4 = k;
                D_801D5EC4.unkA = (t << 12) / 15;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801D5EE8[0] = p->unk4;
    u = p->unk6;
    D_801D5EEC = u;
    u = p->unk8;
    D_801D5EF0 = u;
    func_8003A63C(D_800FA63C, (u8 *)D_801D5EE8 - 0x14, m);
    func_8003B48C(m);
    func_8003B51C(m);
    func_8003B69C(0, 0, 0);
    D_801E5F30 = func_800D29D4(&D_801D5EC4, D_801517C0 + 0x70, 0xC, D_801E5F30);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0CA8(void) {
    MgTask *p;
    MgMat *m;
    s32 t;
    s32 u;

    m = (MgMat *)0x1F800000;
    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 3) {
        D_801D5EFE = 0;
    } else if (t - 3 < 0xA) {
        D_801D5EFE = (t - 3 << 12) / 10;
    } else {
        p->unk0 = -1;
        return;
    }
    D_801D5F04.m[0][0] = D_801D5F14.v = p->unk14;
    u = p->unk4;
    D_801D5F18 = u;
    u = p->unk6;
    D_801D5F1C = u;
    u = p->unk8;
    D_801D5F20 = u;
    func_8003A63C(D_800FA63C, &D_801D5F04, m);
    func_8003B48C(m);
    func_8003B51C(m);
    func_8003B69C(0, 0, 0);
    D_801E5F30 = func_800D29D4(D_801D5EF4, D_801517C0 + 0x70, 0xC, D_801E5F30);
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        p->unk16 = p->unk16 * 0x95 >> 8;
        p->unk2++;
    }
}

void func_801B0E44(void) {
    MgTask *p;
    MgTask *q;
    s16 t;
    s16 r;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        r = t % 3;
        if (r == 0) {
            q = &D_80162978[func_800BBEAC(&func_801B0CA8)];
            q->unk4 = p->unk4;
            q->unk6 = -(func_80042DA8() % 2180 + 0x140);
            q->unk8 = p->unk8;
            q->unk14 = func_80042DA8() % 768 + 0x400;
            q->unk16 = func_80042DA8() % 256 + 0x300;
        }
        t = p->unk2 + 1;
        p->unk2 = t;
        if (t >= 9) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B0FC4);

void func_801B10B0(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 a;
    s32 b;
    s32 r;
    s32 t;
    s32 u;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            i++;
            q = &D_80162978[func_800BBEAC(&func_801B0FC4)];
            a = func_80042DA8() & 0xFFF;
            b = func_80042DA8() % 500 + 0x3E8;
            q->unk4 = p->unk4 + (func_80039A74(a) * b >> 12);
            r = func_80042DA8();
            q->unk6 = -(r % 2500 + 0x1F4);
            t = func_80039B40(a) * b;
            u = (u16)p->unk8;
            q->unkC = 0;
            q->unkE = 0x32;
            q->unk10 = 0;
            u += t >> 12;
            q->unk8 = u;
            q->unk14 = func_80042DA8() % 10240 + 0x1000;
        } while (i < 3);
        i = 0;
        do {
            i++;
            q = &D_80162978[func_800BBEAC(&func_801B0FC4)];
            a = func_80042DA8() & 0xFFF;
            b = func_80042DA8() % 500 + 0x3E8;
            t = func_80039A74(a) * b;
            u = (u16)p->unk4;
            q->unk6 = 0;
            u += t >> 12;
            q->unk4 = u;
            q->unk8 = p->unk8 + (func_80039B40(a) * b >> 12);
            q->unkC = (u32)(func_80039A74(a) * 0x41) >> 11;
            q->unkE = 0;
            q->unk10 = (u32)(func_80039B40(a) * 0x41) >> 11;
            q->unk14 = func_80042DA8() % 10240 + 0x1000;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B13A8(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 u;
    s16 *e;
    s32 k;

    b = D_80162978;
    p = &b[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_800D52A0(0x400, 4);
            D_800F5B70[0] = 0;
            D_800F5B70[1] = 0;
            D_800F5B70[2] = 0x80;
        }
        if (p->unk2 == 4) {
            func_800D55F4(0x21, func_800D56A8(&D_801E5F38), 0x1C4, 0x1C5);
            func_800BBEAC(&func_801B026C);
        }
        t = p->unk2;
        if (t == 0x22) {
            s16 w1;
            s16 w2;

            k = -0x578;
            q = &b[func_800BBEAC(&func_801B04B8)];
            e = &D_801E5F38;
            w1 = *e;
            *(s16 *)((u8 *)q + 6) = k;
            *(s16 *)((u8 *)q + 4) = w1;
            w2 = D_801E5F3C;
            *(s16 *)((u8 *)q + 8) = w2;
            if (p->unk2 == t) {
                s16 w3;
                s16 w4;

                q = &b[func_800BBEAC(&func_801B067C)];
                w3 = *e;
                *(s16 *)((u8 *)q + 6) = k;
                *(s16 *)((u8 *)q + 4) = w3;
                w4 = D_801E5F3C;
                *(s16 *)((u8 *)q + 8) = w4;
            }
        }
        u = p->unk2;
        if (u == 0x36) {
            func_800BBEAC(&func_801B09D4);
            u = p->unk2;
        }
        if (u == 0x2C) {
            s16 w5;
            s16 w6;

            q = &D_80162978[func_800BBEAC(&func_801B0AC0)];
            w5 = D_801E5F38;
            *(s16 *)((u8 *)q + 6) = 0;
            *(s16 *)((u8 *)q + 4) = w5;
            w6 = D_801E5F3C;
            *(s16 *)((u8 *)q + 8) = w6;
        }
        t = 0x4F;
        if (p->unk2 == t) {
            q = &D_80162978[func_800BBEAC(&func_801B0E44)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
        }
        if (p->unk2 == 0x27) {
            q = &D_80162978[func_800BBEAC(&func_801B10B0)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
        }
        if (p->unk2 == t) {
            func_800D5774(D_801E5F34);
        }
        if (p->unk2 == 0x5E) {
            func_800D52A0(0, 4);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B16BC(arg0) {
    MgTask *p;

    D_801E5F34 = arg0;
    p = &D_80162978[func_800BBEAC(&func_801B13A8)];
    func_800D3994(arg0, D_8015190F[arg0][0], &D_801E5F38);
    *(MgSVec *)&p->unk4 = *(MgSVec *)&D_801E5F38;
}

void func_801B1770(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E5F30 = D_801D5F30 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B17D0(arg0, arg1) {
    func_800D2980(&D_801B1840, 0, 0, 0);
    func_800BBEAC(&func_801B1770);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B16BC);
}
