#include "common.h"
#include "magic_graviga2/decls.h"

void func_801B0000(void) {
    func_801B1D44();
}

INCLUDE_ASM("../asm/us/magic_graviga2/nonmatchings/text", func_801B0020);

void func_801B09D0(void) {
    MgMat *m;
    MgMat *m2;
    MgVec *sc;
    MgSVec *sv;
    MgTask *p;
    s32 t;
    s32 j;

    m = (MgMat *)0x1F800008;
    m2 = (MgMat *)0x1F800028;
    sc = (MgVec *)0x1F800048;
    p = &D_80162978[D_8015169C];
    sv = (MgSVec *)0x1F800000;
    t = p->unk2;
    if (t < 0xF) {
        D_801D3C06 = -(t << 12) / 15 + 0x1000;
    } else {
        t -= 0xF;
        if (t < 0x1E) {
            D_801D3C06 = 0;
        } else {
            t -= 0x1E;
            if (t < 10) {
                D_801D3C06 = (t << 12) / 10;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    func_8003B2CC(&D_800FA63C, &p->unk4, sv);
    *(u16 *)sv += D_800FA650;
    ((u16 *)sv)[1] += D_800FA654;
    ((u16 *)sv)[2] += D_800FA658;
    func_800D44E8(sv, m);
    sc->vx = sc->vy = sc->vz = 0x5800;
    func_8003B35C(m, sc);
    D_801D3C10[0] = p->unk2 * 0x18;
    func_8003C21C(&D_801D3C10[-2], m2);
    func_8003A79C(m, m2, m);
    m->t[0] = sv->vx;
    m->t[1] = sv->vy;
    m->t[2] = sv->vz;
    func_8003B48C(m);
    sv->vx = 0;
    sv->vy = 0;
    sv->vz = -0x3E8;
    func_8003ACE4(sv, sc);
    for (j = 0; j < 1; j++) {
        func_8003B51C(m);
        D_801E3C74 = func_800D29D4(D_801D3BFC, D_801517C0 + 0x70, 0xC, D_801E3C74);
        m->t[0] += sc->vx;
        m->t[1] += sc->vy;
        m->t[2] += sc->vz;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0C78(void *arg0, u8 *arg1, s32 arg2) {
    func_800D4368(arg0, 0x900, arg2);
    D_801D3C1C[0] = arg1[0];
    D_801D3C1D = arg1[1];
    D_801D3C1E = arg1[2];
    D_801E3C74 = func_800D6260(&D_801D3C1C[-8], D_801517C0 + 0x70, 0xC, D_801E3C74);
}

void func_801B0CF8(void) {
    u8 c[3];
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        c[0] = c[1] = c[2] = (t << 7) / 5;
    } else {
        t -= 5;
        if (t < 5) {
            c[0] = c[1] = c[2] = 0x80;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
    }
    func_801B0C78(&p->unk4, c, -0xE);
}

void func_801B0DE8(void) {
    u8 c[3];
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xA) {
        c[0] = c[1] = c[2] = 0x80;
    } else {
        t -= 0xA;
        if (t < 5) {
            c[0] = c[1] = c[2] = -(t << 7) / 5 - 0x80;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
    }
    func_801B0C78(&p->unk4, c, -0xE);
}

void func_801B0EDC(void) {
    MgTask *p;
    MgTask *q;
    MgMat *m;
    MgSVec *sv;
    s32 t;
    s32 i;
    s32 a;
    s32 b;
    s32 r;
    s32 w;

    m = (MgMat *)0x1F800008;
    p = &D_80162978[D_8015169C];
    sv = (MgSVec *)0x1F800000;
    t = p->unk2;
    if (t < 5) {
        r = t * 200;
    } else {
        t -= 5;
        if (t < 0x14) {
            r = 0x3E8;
        } else {
            func_8003C21C((MgSVec *)&p->unkC, m);
            for (i = 0; i < 12; i++) {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0DE8)];
                a = (i << 12) / 12;
                sv->vx = (u32)(func_80039A74(a) * 125) >> 9;
                sv->vy = 0;
                sv->vz = func_80039B40(a) * 1000 >> 12;
                func_8003B2CC(m, sv, sv);
                q->unk4 = sv->vx + p->unk4;
                q->unk6 = sv->vy + p->unk6;
                q->unk8 = sv->vz + p->unk8;
                w = func_80042DA8() % 0x700 + 0x500;
                q->unkC = sv->vx * w >> 12;
                q->unkE = sv->vy * w >> 12;
                q->unk10 = sv->vz * w >> 12;
            }
            p->unk0 = -1;
            return;
        }
    }
    func_8003C21C((MgSVec *)&p->unkC, m);
    for (i = 0; i < 12; i++) {
        b = (i << 12) / 12;
        sv->vx = r * func_80039A74(b) >> 12;
        sv->vy = 0;
        sv->vz = r * func_80039B40(b) >> 12;
        func_8003B2CC(m, sv, sv);
        sv->vx += p->unk4;
        sv->vy += p->unk6;
        sv->vz += p->unk8;
        func_801B0C78(sv, D_801D3C24, D_801E3C84 - 0xE);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unkC += 8;
        p->unkE += 0x80;
        p->unk10 += 0x20;
    }
}

void func_801B1220(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    MgSVec *rot;
    MgMat *m;
    MgSVec *sv;
    s32 i;
    s32 t;

    rot = (MgSVec *)0x1F800008;
    m = (MgMat *)0x1F800010;
    p = &D_80162978[D_8015169C];
    sv = (MgSVec *)0x1F800000;
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0xF) {
            for (i = 0; i < 2; i++) {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0CF8)];
                sv->vx = func_80042DA8() % 3000 + 3000;
                sv->vy = 0;
                sv->vz = 0;
                rot->vx = 0;
                rot->vy = func_80042DA8() & 0xFFF;
                rot->vz = func_80042DA8() % 2560 - 0x100;
                func_8003C21C(rot, m);
                func_8003B2CC(m, sv, sv);
                q->unk4 = ((u16 *)&D_801E3C7C)[0] + sv->vx;
                q->unk6 = ((u16 *)&D_801E3C7C)[1] + sv->vy;
                q->unk8 = ((u16 *)&D_801E3C7C)[2] + sv->vz;
                q->unkC = -sv->vx / 10;
                q->unkE = -sv->vy / 10;
                q->unk10 = -sv->vz / 10;
            }
        } else {
            t -= 0xF;
            if (t >= 10) {
                for (i = 0, b = D_80162978; i < 3; i++) {
                    q = (MgTask *)((func_800BBEAC((M2C_UNK *)func_801B0EDC) << 5) + (s32)b);
                    *(GvBytes8 *)&q->unk4 = *(GvBytes8 *)&D_801E3C7C;
                    q->unkE = 0;
                    q->unkC = (i << 9) / 3;
                    q->unk10 = (i << 11) / 3;
                }
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B1520(void) {
    MgTask *p;
    MgMat *s;
    MgMat *m;
    s16 *fr;
    u8 *g;
    s32 t;
    s32 c;
    s32 k;

    p = &D_80162978[D_8015169C];
    s = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 0xF) {
        c = t * 0x3000 / 15;
    } else {
        t -= 0xF;
        if (t < 0x23) {
            c = 0x3000;
        } else {
            t -= 0x23;
            if (t < 0xF) {
                c = -(t * 0x3000) / 15 + 0x3000;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    k = -(c * 500) >> 12;
    D_801E3C84 = k;
    m = func_800D4368(&p->unk4, c, k);
    *s = *m;
    func_8003B35C(s, D_801D3C44);
    func_8003B48C(s);
    fr = D_801D3C40;
    g = (u8 *)fr - 8;
    *fr = p->unk2 % D_801D2470[0];
    D_801E3C74 = func_800D4D90(g, D_801517C0 + 0x6C, 0xC, D_801E3C74);
    *s = *m;
    func_8003B35C(s, D_801D3C54);
    func_8003B48C(s);
    *fr = (p->unk2 + 5) % D_801D2470[0];
    D_801E3C74 = func_800D4D90(g, D_801517C0 + 0x6C, 0xC, D_801E3C74);
    func_8003B48C(m);
    D_801E3C74 = func_801B0020(D_801D3C28, D_801517C0 + 0x70, 0xC, D_801E3C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B183C(void) {
    MgTask *p;
    MgMat *s;
    MgVec *sc;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    s = (MgMat *)0x1F800000;
    sc = (MgVec *)0x1F800020;
    t = p->unk2;
    if (t <= 0) {
        D_801D3C6E = 0;
    } else {
        t -= 1;
        if (t < 0xF) {
            D_801D3C6E = (t << 12) / 15;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    k = p->unk2 * 0x600;
    sc->vx = sc->vy = sc->vz = k;
    func_8003C21C(&p->unkC, s);
    func_8003B35C(s, sc);
    s->t[0] = p->unk4;
    s->t[1] = p->unk6;
    s->t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, s, s);
    func_8003B48C(s);
    func_8003B51C(s);
    func_8003B69C(0, 0, 0);
    D_801E3C74 = func_801B0020(D_801D3C64, D_801517C0 + 0x70, 0xC, D_801E3C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B19C0(void) {
    MgTask *p;
    MgTask *q;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((p->unk2 & 3) == 0) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B183C)];
            *(GvBytes8 *)&q->unk4 = *(GvBytes8 *)&D_801E3C7C;
            q->unkC = (func_80042DA8() & 0x3FF) - 0x200;
            q->unkE = 0;
            q->unk10 = (func_80042DA8() & 0x3FF) - 0x200;
        }
        p->unk2++;
        if (p->unk2 >= 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B1AB8(void) {
    MgTask *p;
    MgTask *q;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_800D52A0(0x800, 4);
            D_800F5B72 = D_800F5B71 = D_800F5B70 = 0x80;
        }
        if (p->unk2 == 4) {
            func_800BBEAC((M2C_UNK *)func_801B1220);
        }
        if (p->unk2 == 4) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1520)];
            *(GvBytes8 *)&q->unk4 = *(GvBytes8 *)&D_801E3C7C;
        }
        if (p->unk2 == 0xA) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B09D0)];
            *(GvBytes8 *)&q->unk4 = *(GvBytes8 *)&D_801E3C7C;
        }
        if (p->unk2 == 0x36) {
            func_800BBEAC((M2C_UNK *)func_801B19C0);
        }
        if (p->unk2 == 0x45) {
            for (i = 0; i < 10; i++) {
                if ((D_801E3C78 >> i) & 1) {
                    func_800D5774(i);
                }
            }
            if (p->unk2 == 0x45) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B1CB8(void) {
    M2C_UNK *var_v1;
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    var_v1 = &D_801B1DF0;
    if (temp_s0->unk2 == 0) {
        var_v1 = &D_801D3C74;
    }
    D_801E3C74 = var_v1;
    temp_s0->unk2 = (u16) temp_s0->unk2 ^ 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 4);
        temp_s0->unk0 = -1;
    }
}

s32 func_801B1D44(arg0) {
    if (D_801517BC == 0) {
        func_800D2980(&D_801B1DF0, 0, 0, 0);
    }
    func_800BBEAC((M2C_UNK *)func_801B1CB8);
    D_801E3C78 = arg0;
    func_800D54EC(arg0, &D_801E3C7C);
    D_801E3C7C.unk2 -= 0x3E8;
    func_800BBEAC((M2C_UNK *)func_801B1AB8);
    return func_800D55F4(0x20, func_800D574C(arg0), 0x93);
}
