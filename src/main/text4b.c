#include "common.h"
#include "main/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
extern volatile s32 D_80062FC4;
extern u8 *volatile D_80062F24;
void func_8001D3C0(s16 arg0, s16 arg1);
M2C_UNK func_801D4CC0();
M2C_UNK func_801D1774();
M2C_UNK func_801D2D74();
M2C_UNK func_801D2E84();
M2C_UNK func_801D3228();
M2C_UNK func_801D027C();
M2C_UNK func_801D1A6C(s32);
M2C_UNK func_801D4118(s32);
M2C_UNK func_801D2F00(s32);
M2C_UNK func_801D3138(s32);
M2C_UNK func_801D3018(s32);
M2C_UNK func_801D05C4(s32);
M2C_UNK func_801D0704(s32);
M2C_UNK func_801D131C(s32);
M2C_UNK func_801D11A8();
extern Main2C D_800738A4[];
void func_800262D8(void);
M2C_UNK func_800258BC(s32, M2C_UNK);
void func_8001EB2C(s16 arg0, s16 arg1);
void func_80025ED4(void);
extern M2C_UNK D_800756F8;
void func_80021044(Spr *arg0, DispEnv *arg1);
M2C_UNK func_80017678();
M2C_UNK func_8001786C(s32);
M2C_UNK func_80020058(s32);
s32 func_800484A8();
s32 func_80048540(M2C_UNK);
extern u16 D_80062D78;
extern u16 D_80062D80;
void func_8001CB48(void);
extern u16 D_80062D7C;
extern u16 D_80062D7E;
extern struct { u8 pad[0x3400]; } D_80077F64[];
void func_8001CF3C(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, s16 arg8, s16 arg9);
void func_8001D180(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, s16 arg8, s16 arg9);
s32 func_80024A3C(s32 arg0);
void func_8001F710(void);
extern s8 D_80062DFD;
void func_80020B68(s32 arg0, s32 arg1, s32 arg2);
extern struct { s16 v; u8 pad[0x43E]; } D_8009D862[];
void func_800264A8(MnCursor *arg0);
void func_800230C4(s32 arg0);
extern u16 D_80062F50;

void func_8001FCDC(s32 arg0, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 0:
        D_8009D84C[arg0][2] += arg2;
        break;
    case 1:
        D_8009D84C[arg0][3] += arg2;
        break;
    case 2:
        D_8009D84C[arg0][4] += arg2;
        break;
    case 3:
        D_8009D84C[arg0][5] += arg2;
        break;
    case 4:
        D_8009D84C[arg0][6] += arg2;
        break;
    case 5:
        D_8009D84C[arg0][7] += arg2;
        break;
    }
}

void func_8001FE6C(s32 arg0, s32 arg1, u16 arg2) {
    switch (arg1) {
    case 0:
        D_8009D88C[arg0].b |= arg2;
        break;
    case 1:
        D_8009D88C[arg0].a |= arg2;
        break;
    case 2:
        D_8009D88A[arg0].a |= arg2;
        break;
    }
}

void func_8001FF50(s32 arg0, s32 arg1) {
    D_8009D888[arg0].flags |= arg1;
}

void func_8001FF8C(s32 arg0, s32 arg1) {
    if (arg1 < 0x41) {
        D_8009D890[arg0][0] |= 1 << arg1;
    }
}

void func_8001FFD4(s32 arg0, s32 arg1) {
    s32 off;

    if (arg1 < 0x41) {
        off = arg0 * 0x440;
        *(u32 *) (D_8009D894 + off) |= 1 << arg1;
    }
}

void func_8002001C(s32 arg0, u32 arg1) {
    s32 off;

    off = arg0 * 0x440;
    *(u32 *) (D_8009D894 + off) |= arg1;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4b", func_80020058);

void func_800206E4(s32 arg0, s32 arg1, s32 arg2) {
    Rect16 rc;
    MainGauge g;
    s32 dead;
    s32 hpc;
    s32 mpc;
    u16 hp;
    s16 sx;

    g.x = arg0 + 0x12;
    g.y = arg1 + 0x1F;
    g.w = 0x3C;
    g.h = 1;
    g.f8 = D_8009C764[arg2].v;
    g.fE = D_8009C764[arg2].v;
    g.fA = D_8009C770[arg2].hp;
    g.fC = 0;
    g.r = 0;
    g.g = 0x80;
    g.b = 0xFF;
    func_80027408(&g);
    g.x = arg0 + 0x12;
    g.y = arg1 + 0x29;
    g.w = 0x3C;
    g.h = 1;
    g.f8 = D_8009C768[arg2 * 33].v;
    g.fE = D_8009C768[arg2 * 33].v;
    g.fA = D_8009C770[arg2].mp;
    g.fC = 0;
    g.r = 0;
    g.g = 0xFF;
    g.b = 0x80;
    func_80027408(&g);
    hp = D_8009C764[arg2].v;
    dead = hp == 0;
    if ((D_8009C770[arg2].hp >> 2) < hp) {
        hpc = 7;
    } else {
        hpc = 6;
    }
    if ((D_8009C770[arg2].mp >> 2) < (u16)D_8009C768[arg2 * 33].v) {
        mpc = 7;
    } else {
        mpc = 6;
    }
    if (D_8009C756[arg2][1] & 0x10) {
        func_80026F44(arg0 + 0x24, arg1 + 0xB, D_80049350, 3);
    }
    if (D_8009C756[arg2][1] & 0x20) {
        func_80026F44(arg0 + 0x24, arg1 + 0xB, D_80049344, 3);
    }
    func_80026F44(arg0, arg1, D_8009C748[arg2], dead ? 2 : 7);
    ((void (*)())func_80027354)(arg0, arg1 + 0xD, D_800493A0, 5);
    func_80028E00(arg0 + 0x12, arg1 + 0xD, ((u8 *)&D_8009C739)[arg2 * 0x84], 2, dead ? 2 : 7);
    ((void (*)())func_80027354)(arg0, arg1 + 0x18, D_80049390, 5);
    func_80028E00(arg0 + 0x12, arg1 + 0x17, D_8009C764[arg2].v, 4, dead ? 2 : hpc);
    func_80028E00(arg0 + 0x32, arg1 + 0x17, D_8009C770[arg2].hp, 4, dead ? 2 : 7);
    ((void (*)())func_80027354)(arg0, arg1 + 0x22, D_80049398, 5);
    func_80028E00(arg0 + 0x12, arg1 + 0x21, (u16)D_8009C768[arg2 * 33].v, 4, dead ? 2 : mpc);
    func_80028E00(arg0 + 0x32, arg1 + 0x21, D_8009C770[arg2].mp, 4, dead ? 2 : 7);
    sx = (s16)(arg0 + 0x2E);
    func_80028CA0(sx, (s16)(arg1 + 0x21), 0xD8, 0, 4, 8, 1, 0);
    func_80028CA0(sx, (s16)(arg1 + 0x17), 0xD8, 0, 4, 8, 1, 0);
    rc.x = 0;
    rc.y = 0;
    rc.w = 0x100;
    rc.h = 0x100;
    func_80026A34(0, 1, 0x7F, (s32)&rc);
}

void func_80020B68(s32 arg0, s32 arg1, s32 arg2) {
    Rect16 rc;
    MainGauge g;
    s32 ci;
    s32 dead;
    s32 hpc;
    s32 mpc;
    s16 hp;
    s16 sx;

    ci = D_800491D0[D_8009CBDC[arg2]];
    g.x = arg0 + 0x12;
    g.y = arg1 + 0x1F;
    g.w = 0x3C;
    g.h = 1;
    g.f8 = (u16)D_8009D85C[arg2].hp;
    g.fE = (u16)D_8009D85C[arg2].hp;
    g.fA = (u16)D_8009D85C[arg2].maxhp;
    g.fC = 0;
    g.r = 0;
    g.g = 0x80;
    g.b = 0xFF;
    func_80027408(&g);
    g.x = arg0 + 0x12;
    g.y = arg1 + 0x29;
    g.w = 0x3C;
    g.h = 1;
    g.f8 = (u16)D_8009D860[arg2].hp;
    g.fE = (u16)D_8009D860[arg2].hp;
    g.fA = (u16)D_8009D862[arg2].v;
    g.fC = 0;
    g.r = 0;
    g.g = 0xFF;
    g.b = 0x80;
    func_80027408(&g);
    hp = D_8009D85C[arg2].hp;
    dead = hp == 0;
    if (D_8009D85C[arg2].maxhp / 4 < hp) {
        hpc = 7;
    } else {
        hpc = 6;
    }
    if (D_8009D862[arg2].v / 4 < D_8009D860[arg2].hp) {
        mpc = 7;
    } else {
        mpc = 6;
    }
    if (D_8009C756[ci][1] & 0x10) {
        func_80026F44(arg0 + 0x24, arg1 + 0xB, D_80049350, 3);
    }
    if (D_8009C756[ci][1] & 0x20) {
        func_80026F44(arg0 + 0x24, arg1 + 0xB, D_80049344, 3);
    }
    func_80026F44(arg0, arg1, D_8009C748[ci], dead ? 2 : 7);
    ((void (*)())func_80027354)(arg0, arg1 + 0xD, D_800493A0, 5);
    func_80028E00(arg0 + 0x12, arg1 + 0xD, ((u8 *)&D_8009C739)[ci * 0x84], 2, dead ? 2 : 7);
    ((void (*)())func_80027354)(arg0, arg1 + 0x18, D_80049390, 5);
    func_80028E00(arg0 + 0x12, arg1 + 0x17, D_8009D85C[arg2].hp, 4, dead ? 2 : hpc);
    func_80028E00(arg0 + 0x32, arg1 + 0x17, D_8009D85C[arg2].maxhp, 4, dead ? 2 : 7);
    ((void (*)())func_80027354)(arg0, arg1 + 0x22, D_80049398, 5);
    func_80028E00(arg0 + 0x12, arg1 + 0x21, D_8009D860[arg2].hp, 4, dead ? 2 : mpc);
    func_80028E00(arg0 + 0x32, arg1 + 0x21, D_8009D862[arg2].v, 4, dead ? 2 : 7);
    sx = (s16)(arg0 + 0x2E);
    func_80028CA0(sx, (s16)(arg1 + 0x21), 0xD8, 0, 4, 8, 1, 0);
    func_80028CA0(sx, (s16)(arg1 + 0x17), 0xD8, 0, 4, 8, 1, 0);
    rc.x = 0;
    rc.y = 0;
    rc.w = 0x100;
    rc.h = 0x100;
    func_80026A34(0, 1, 0x7F, (s32)&rc);
}

void func_80021044(Spr *arg0, DispEnv *arg1) {
    Spr *s2;
    s16 e;

    func_8003CEDC(0);
    func_80043814(arg0, 0, 0, 0x180, 0x1D8);
    arg0->f = 1;
    arg0->g = 1;
    func_800443B0((s32 *)arg0);
    func_8003CEDC(0);
    func_80043814(arg0, 0, 8, 0x180, 0xE0);
    func_80043814((Spr *)((u8 *)arg0 + 0x5C), 0, 0xF0, 0x180, 0xE0);
    func_800438D4(arg1, 0, 0xE8, 0x16C, 0xF0);
    func_800438D4(arg1 + 1, 0, 0, 0x16C, 0xF0);
    s2 = (Spr *)((u8 *)arg0 + 0x5C);
    M2C_FIELD(arg0, s8 *, 0x74) = 1;
    arg0->g = 1;
    M2C_FIELD(arg0, s8 *, 0x73) = 1;
    arg0->f = 1;
    M2C_FIELD(arg0, s8 *, 0x72) = 1;
    arg0->pad16[0] = 1;
    arg0->rest[0] = 0;
    arg0->rest[1] = 0;
    arg0->rest[2] = 0;
    M2C_FIELD(arg0, s8 *, 0x75) = 0;
    M2C_FIELD(arg0, s8 *, 0x76) = 0;
    M2C_FIELD(arg0, s8 *, 0x77) = 0;
    if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
        e = 0xAF;
    } else {
        e = 0x3F;
    }
    s2->e = e;
    arg0->e = e;
    func_8003CEDC(0);
    func_800444AC((s32 *)arg1);
    func_800443B0((s32 *)arg0);
    func_80043D3C(1);
}

void func_800211B8(s32 arg0) {
    D_80062DEC = arg0;
}

s32 func_800211C4(s32 arg0) {
    func_80033E34(D_80048F60[arg0 * 2], D_80048F60[arg0 * 2 + 1], D_80062DEC, 0);
    return func_80034B44();
}

void func_8002120C(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_80062DD4;
    D_80062DD4 = arg0;
    D_80062DD0 = temp_v0;
    if ((arg0 != 0) && (((u32) (temp_v0 - 3) >= 2U) || ((u32) (arg0 - 3) >= 2U))) {
        func_800211C4(arg0);
    }
}

void func_80021258(s32 arg0) {
    func_80015248(0xD, arg0, 8);
}

void func_80021280(s32 arg0) {
    func_80015248(4, arg0, 8);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4b", func_800212A8);

void func_80021BAC(s32 arg0, s32 arg1) {
    struct { s16 x, y, w, h; } rect;
    u8 buf[8];

    rect.x = 0;
    rect.y = 0;
    rect.w = 0x100;
    rect.h = 0x100;
    func_80026A34(0, 1, 0x7F, (s32) &rect);
    func_80026F44(arg0 + 8, arg1 + 6, D_80049338, 6);
    ((void (*)()) func_8001DE0C)(buf, arg0, arg1, 0x50, 0x14);
    func_8001E040(buf);
}

void func_80021C4C(s32 arg0, s32 arg1, s32 arg2) {
    struct { s16 x, y, w, h; } rect;
    s32 buf[2];
    s32 s;

    func_80028CA0((s16) (arg0 + 8), (s16) (s = arg1 + 5), 0x80, 0x20, 0x10, 0x10, (s16) ((s32 (*)(s32)) func_8002603C)(arg2), 0);
    rect.x = 0;
    rect.y = 0;
    rect.w = 0x100;
    rect.h = 0x100;
    func_80026A34(0, 1, 0x7F, (s32) &rect);
    func_80026F44(arg0 + 0x18, s, (void *) ((s32 (*)(s32)) func_80021258)(arg2), 7);
    func_80026F44(arg0 + 0x38, arg1 + 0x12, D_80049338, 6);
    ((void (*)()) func_8001DE0C)(buf, arg0, arg1, 0x82, 0x20);
    func_8001E040(buf);
}

void func_80021D5C(s32 arg0, s32 arg1) {
    struct { s16 x, y, w, h; } rect;
    s32 buf[2];
    s32 s;

    func_80028CA0((s16) (arg0 + 8), (s16) (s = arg1 + 5), 0x80, 0x20, 0x10, 0x10, (s16) func_8002603C(D_80062EC0), 0);
    rect.x = 0;
    rect.y = 0;
    rect.w = 0x100;
    rect.h = 0x100;
    func_80026A34(0, 1, 0x7F, (s32) &rect);
    func_80026F44(arg0 + 0x20, arg1 + 0x12, (void *) func_80015248(8, 0x25, 8), 7);
    func_80026F44(arg0 + 0x18, s, (void *) ((s32 (*)(s32)) func_80021258)(D_80062EC0), 7);
    ((void (*)()) func_8001DE0C)(buf, arg0, arg1, 0x82, 0x23);
    func_8001E040(buf);
}

void func_80021E70(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 pad[2];
    s32 buf[2];
    s32 *p;

    func_80026F44(arg0 + 0x2F, arg1 + 0x12, (void *)func_80015248(8, 0x24, 8), 7);
    func_80026F44(arg0 + 8, arg1 + 5, (void *)func_80015248(3, func_80015AFC(D_800491D0[D_8009CBDC[arg2]], arg3), 8), 6);
    p = buf;
    ((void (*)()) func_8001DE0C)(p, arg0, arg1, 0x82, 0x23);
    func_8001E040(p);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4b", func_80021F58);

s32 func_80022B5C(void) {
    s16 rect[4];
    s32 r;
    Tile16 *t;
    Tile16 *q;

    r = func_80043DD8(1);
    if (r == 0) {
        func_800444AC((M2C_UNK *) D_8007075C[D_80062F58]);
        func_800443B0((M2C_UNK *) D_800706A4[D_80062F58]);
        if (D_80062EB0 == 0) {
            D_80062EB0 = 1;
            func_80043938(1);
            func_80025C94(&D_800756F8);
        } else {
            func_8004433C(D_80062EA4);
        }
        D_80062F58 ^= 1;
        if (D_80062DD8 == 5) {
            D_80062F98 = 0xFF;
            func_80022FE0();
            D_80095DD4 = 0;
        }
        func_8001CB48();
        D_80062EA4 = (s32) &D_8006974C[D_80062F58];
        func_8004418C(D_80062EA4, 0x14);
        func_800269C0((s32) &D_80077F64[D_80062F58]);
        func_80026A00(D_80062EA4);
        switch (D_80062DD8) {
        case 0:
            func_80021F58();
            break;
        case 1:
            func_80021F58();
        case 2:
        case 3:
            func_800212A8();
            break;
        case 4:
            t = (Tile16 *) D_800696FC;
            func_800469B0(&t[D_80062F58]);
            func_80046848(&t[D_80062F58], 1);
            q = &t[D_80062F58];
            q->w = 0x180;
            q->r0 = D_80062EAC;
            q->x0 = 0;
            q->y0 = 0;
            q->h = 0xE0;
            t[D_80062F58].g0 = D_80062EAC;
            t[D_80062F58].b0 = D_80062EAC;
            func_80046794(D_80062EA4, (s32) &t[D_80062F58]);
            rect[0] = 0;
            rect[1] = 0;
            rect[2] = 0x100;
            rect[3] = 0x100;
            func_80026A34(0, 1, 0x5F, (s32) rect);
            D_80062DD8 = 5;
            break;
        }
        r = D_80062FEC + 1;
        D_80062FEC = r;
    }
    return r;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4b", func_80022DE4);

void func_80022FE0(void) {
    func_800159B0();
    func_800444AC(D_8007075C[D_80062F58]);
    func_800443B0(D_800706A4[D_80062F58]);
}

s32 func_80023050(void) {
    return D_80062DF8;
}

void func_8002305C(s32 arg0, s32 arg1) {
    s32 t;

    t = D_80062F94;
    D_80062DF8 = arg0;
    D_80062F94 = arg1 - 1;
    D_80062F0C = t;
    switch (arg0) {
    case 1: break;
    case 2:
        D_80062F20 = 0x10;
        break;

    case 4:
        D_80062F20 = 0x10;
        break;
    case 5:
        D_8009A0D3 = t;
        D_80062ECC = 0;
        D_80062F20 = 0x10;
        break;

    }
}

void func_800230C4(s32 arg0) {
    s16 rect[4];
    s32 buf[2];
    s32 r;
    s32 i;
    s32 y;
    s32 tmp;
    s32 e;
    s32 e2;
    s32 tmp2;
    s32 c;
    Tile16 *t;
    Tile16 *q;

    r = func_80034B44();
    rect[1] = 5;
    rect[2] = 0x16C;
    rect[0] = 0;
    rect[3] = 0xDB;
    func_80026A94((s16 *)D_800706A4[arg0], (u16 *)rect);
    y = 0;
    switch (D_80062DF8) {
    case 2:
        if (D_80062F20 != 0) {
            D_80062F20--;
        } else if (r == 0) {
            D_800493A8[D_80062DD4](0);
            D_80062DF8 = 3;
        }
        tmp = D_80062F20 * 0xC;
        e = D_80062F94 * tmp / 16;
        e += 0xB;
        func_80026F44(0x126, e, D_80049248[D_80062F94], 7);
        D_80062DF0 = D_80062F20 * 0x6C / 16 + 0x18;
        break;
    case 4:
        if (D_80062F20 != 0) {
            D_80062F20--;
        } else {
            D_80062DF8 = 3;
            D_800493A8[D_80062DD4]();
        }
        func_80026F44(0x126, 0xB, D_80049248[D_80062F0C], 7);
        D_80062DF0 = 0x18;
        break;
    case 3:
        if (D_80062F20 < 0xF) {
            D_80062F20++;
        } else {
            D_80062DF8 = 0;
        }
        D_80062DF0 = 0x18;
        func_80026F44(0x126, 0xB, D_80049248[D_80062F94], 7);
        break;
    case 0:
        D_80062DF0 = 0x18;
        func_80026F44(0x126, 0xB, D_80049248[D_80062F94], 7);
        break;
    case 1:
        D_80062DF0 = 0x84;
        i = 0;
        if (D_80062FC0 != 1) {
            y = D_80062EA8 * 5 - 0x64;
        }
        for (; i < 10; i++) {
            if ((D_80062F4C >> i) & 1) {
                func_80026F44(0x126, y + 0xB + i * 0xC, D_80049248[i], -(((D_80062F50 >> i) & 1) == 0) & 7);
            }
        }
        break;
    case 5:
        if (D_80062F20 != 0) {
            D_80062F20--;
            if (D_80062F20 == 0) {
                if (D_80062FC0 == 2) {
                    D_80062FC0 = -1;
                    D_80062DF8 = 1;
                }
            }
        } else {
            D_80062DF8 = 6;
        }
        func_80026F44(0x126, 0xB, D_80049248[D_80062F0C], 7);
        D_80062DF0 = 0x18;
        break;
    case 6:
        if (D_80062F20 < 0xF) {
            D_80062F20++;
        } else {
            D_80062DF8 = 1;
        }
        tmp2 = D_80062ECC * 0xC;
        e2 = D_80062F0C * tmp2 / 16;
        e2 += 0xB;
        func_80026F44(0x126, e2, D_80049248[D_80062F0C], 7);
        D_80062DF0 = D_80062ECC * 0x6C / 16 + 0x18;
        D_80062ECC++;
        break;
    }
    if (D_80062FC0 == 1) {
        rect[0] = 0x11A;
        rect[1] = y + 8;
        rect[2] = 0x56;
        rect[3] = D_80062DF0 - 6;
        func_80026A94((s16 *)D_800706A4[arg0], (u16 *)rect);
    }
    ((void (*)())func_8001DE0C)(buf, 0x116, y + 5, 0x56, D_80062DF0);
    func_8001E040(buf);
    if ((u32)D_80062DF8 >= 2) {
        c = 0xFF - D_80062F20 * 0x10;
        t = (Tile16 *)D_800696FC;
        func_800469B0(&t[D_80062F58]);
        func_80046848(&t[D_80062F58], 1);
        q = &t[D_80062F58];
        q->w = 0x180;
        q->r0 = c;
        q->x0 = 0;
        q->y0 = 0;
        q->h = 0xE0;
        t[D_80062F58].g0 = c;
        t[D_80062F58].b0 = c;
        func_80046794(D_80062EA4, &t[D_80062F58]);
    }
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x5F, (s32)rect);
    rect[1] = 5;
    rect[2] = 0x16C;
    rect[3] = 0xDB;
    rect[0] = 0;
    func_80026A94((s16 *)D_800706A4[D_80062F58], (u16 *)rect);
}

void func_8002368C(void) {
    D_80062F64 = 0;
    func_80026448(D_8009A0C8, 0, 0, 1, 0xA, 0, 0, 1, 0xA, 0, 0, 0, 1, 0);
    func_80026448(D_8009A0C8 + 0x12, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0);
    func_80026448(D_8009A0C8 + 0x24, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0);
}

s32 func_80023788(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0;
    if (var_a0 > 0x57E3F) {
        var_a0 = 0x57E3F;
    }
    return ((var_a0 / (s32) D_80049474) * 0xA) + ((s32) (var_a0 % (s32) D_80049474) / (s32) D_80049478);
}

s32 func_8002382C(s32 arg0) {
    if (arg0 > 0x57E3F) {
        arg0 = 0x57E3F;
    }
    arg0 = arg0 % D_80049474;
    arg0 = arg0 % D_80049478;
    return (arg0 / D_8004947C) * 10 + arg0 % D_8004947C / D_80049480;
}

s32 func_80023940(s32 arg0) {
    s32 n;

    n = arg0;
    if (n > 0x57E3F) {
        n = 0x57E3F;
    }
    n %= D_80049474;
    n %= D_80049478;
    n %= D_8004947C;
    n %= D_80049480;
    return (n / D_80049484) * 10 + (n % D_80049484) / D_80049488;
}

void func_80023AC4(void) {
    D_80062FC0 = 2;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4b", func_80023AD4);

void func_80024A04(void) {
    func_800444AC(&D_8007075C);
    func_800443B0(&D_80070700);
}

s32 func_80024A3C(s32 arg0) {
    u8 pad[8];
    u8 sp20[0x700];
    u8 sp720[0x18];
    s32 i;
    s32 j;
    s32 r;

    D_80062DF8 = 1;
    D_80062FC0 = 0;
    D_80062F0C = 0;
    D_80062F94 = 0;
    D_80062DD0 = 0;
    D_80062DD4 = 0;
    D_80062DFD = 0;
    if (arg0 == 0) {
        func_8001F6E4(0, 0, 0);
        D_80062FA0 = 0;
    } else {
        func_8001C484(arg0);
        D_80062FA0 = 1;
    }
    i = D_8009D2A4;
    if (i & 4) {
        D_80063024 = 1;
        i = 0;
    } else {
        D_80063024 = 0;
        i = 0;
    }
    do {
        if (D_8009CBDC[i & 0xFFFF] != 0xFF) {
            func_80020058(i & 0xFFFF);
            func_8001786C(i & 0xFF);
            func_80017678();
        }
        i += 1;
    } while ((u32) (i & 0xFFFF) < 3U);
    j = 0;
    func_80021044(D_800706A4, D_8007075C);
    D_80062EA8 = 0x64;
    D_80062FF4 = -3;
    func_80025CD4((s32) sp20);
    func_80025C94(&D_800756F8);
    D_80062FC0 = 0;
    func_8002368C();
    D_80062F58 = 0;
    do {
        func_8001CB48();
        func_800269C0((s32) &D_80077F64[D_80062F58]);
        D_80062EA4 = (s32) D_80069844[D_80062F58];
        func_8004418C((void *) D_80062EA4, 0x14);
        func_80026A00(D_80062EA4);
        if ((D_80062FA0 != 0) && (D_80062FC0 != -1) && (j & 0x10)) {
            func_80026F44(0x28, 0xCE, D_80049320, 4);
            ((void (*)()) func_8001DE0C)(sp720, 0x20, 0xC8, func_80026B70(D_80049320) + 0x10, 0x18);
            func_8001E040(sp720);
        }
        func_8001F710();
        r = func_80023050();
        if (r == 2 || (u32) (r - 4) < 2U) {
            D_800493FC[D_80062DD0](j);
        } else {
            D_800493FC[D_80062DD4](j);
        }
        func_80043DD8(0);
        func_8003CEDC(0);
        func_800444AC((s32 *) D_8007075C[D_80062F58]);
        func_800443B0(D_800706A4[D_80062F58]);
        j += 1;
        func_8004433C(D_80062EA4);
        D_80062F58 ^= 1;
    } while (D_80062FC0 != -1);
    func_80025C94(sp20);
    func_80024A04();
    D_80062FA0 = 0;
    func_8003CEDC(4);
    return 0;
}

void func_80024D88(s32 arg0) {
    func_800211C4(0xD);
    do {

    } while (func_80034B44() != 0);
    func_8003CEDC(0x1E);
    func_801D131C(arg0);
}

void func_80024DD4(s32 arg0) {
    func_800211C4(0xE);
    do {

    } while (func_80034B44() != 0);
    func_801D1A6C(arg0);
}

void func_80024E18(s32 arg0) {
    func_800211C4(0xF);
    do {

    } while (func_80034B44() != 0);
    func_801D4118(arg0);
}

void func_80024E5C(void) {
    func_800211C4(0x10);
    do {

    } while (func_80034B44() != 0);
    func_801D4CC0();
}

void func_80024E94(void) {
    func_800211C4(0xA);
    do {

    } while (func_80034B44() != 0);
    func_801D1774();
}

void func_80024ECC(void) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D2D74();
}

void func_80024F04(void) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D2E84();
}

void func_80024F3C(s32 arg0) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D2F00(arg0);
}

void func_80024F80(s32 arg0) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D3138(arg0);
}

void func_80024FC4(s32 arg0) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D3018(arg0);
}

void func_80025008(void) {
    func_800211C4(1);
    do {

    } while (func_80034B44() != 0);
    func_801D3228();
}

void func_80025040(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if ((D_8009D78A[0] >> D_80049500[i]) & 1) {
            D_8009D44C[i] = D_8009C738[D_80049500[i]][1];
        }
    }
}

void func_800250B4(void) {
    func_800211C4(0xC);
    do {

    } while (func_80034B44() != 0);
    func_801D027C();
}

void func_800250EC(s32 arg0) {
    func_800211C4(0xC);
    do {

    } while (func_80034B44() != 0);
    func_801D05C4(arg0);
}

void func_80025130(s32 arg0) {
    func_800211C4(0xC);
    do {

    } while (func_80034B44() != 0);
    func_801D0704(arg0);
}

void func_80025174(void) {
    s32 pad;
    s32 i;
    s32 j;
    s32 k;

    pad = func_8001C808();
    if (pad & 4) {
        func_80024E18(0);
    } else if (pad & 8) {
        func_80024E5C();
        for (i = 0; i < 5; i++) {
            k = 0x13F - i * 6;
            for (j = 0; j < 6; j++) {
                D_8009CBE0[k - j] = (j + 0x47) | 0xC600;
            }
        }
        func_80024E94();
    } else if (pad & 1) {
        func_80024DD4(0);
    } else if (pad & 2) {
        for (i = 0; i < 9; i++) {
            func_80024D88(i);
        }
        func_80024D88(0x64);
    } else {
        D_8009D2A4 = 0xFF;
        D_8009D2A5 = 0xFF;
        func_80024A3C(0);
    }
}

u16 func_80025288(u16 item) {
    s32 id;
    s32 count;
    s32 i;
    s32 n;
    u16 v;
    u16 res;

    id = item & 0x1FF;
    res = 0xFFFF;
    count = item >> 9;
    for (i = 0; i < 320; i++) {
        v = D_8009CBE0[i];
        if (v != 0xFFFF && id == (v & 0x1FF)) {
            res = v >> 9;
            n = res;
            if (count < n) {
                res = item | (count << 9);
                D_8009CBE0[i] = ((n - count) << 9) | id;
            } else {
                res = v;
                D_8009CBE0[i] = 0xFFFF;
            }
            break;
        }
    }
    return res;
}

s32 func_80025310(s32 arg0) {
    s32 id;
    s32 i;
    u16 v;
    u16 none;

    id = arg0 & 0x1FF;
    none = 0xFFFF;
    for (i = 0; i < 320; i++) {
        v = D_8009CBE0[i];
        if (v != 0xFFFF && id == (v & 0x1FF)) {
            return v;
        }
    }
    return none;
}

void func_80025360(void) {
    func_8001FA28(0x19F);
}

void func_80025380(u16 item) {
    s32 id;
    s32 count;
    s32 i;
    u16 v;

    id = item & 0x1FF;
    count = item >> 9;
    for (i = 0; i < 320; i++) {
        v = D_8009CBE0[i];
        if (v != 0xFFFF && id == (v & 0x1FF)) {
            count += v >> 9;
            if (count > 99) {
                count = 99;
            }
            D_8009CBE0[i] = (count << 9) | id;
            return;
        }
    }
    for (i = 0; i < 320; i++) {
        if (D_8009CBE0[i] == 0xFFFF) {
            D_8009CBE0[i] = item;
            return;
        }
    }
}

s32 func_8002542C(s32 arg0) {
    s32 i;
    u8 id;

    id = arg0;
    for (i = 0; i < 200; i++) {
        if (D_8009CE60[i] == -1) {
            D_8009CE60[i] = arg0;
            if (func_8002603C(id) == 0xA) {
                *((u8 *) D_8009CE60 + 0x473) |= 1;
            }
            if (id == 0x2C) {
                *((u8 *) D_8009CE60 + 0x473) |= 2;
            }
            return -1;
        }
    }
    return arg0;
}

void func_800254D8(void) {
    D_80062EBC = 0;
}

void func_800254E4(u8 arg0) {
    D_80069800[D_80062EBC] = arg0;
    D_80062EBC = D_80062EBC + 1;
}

void func_80025514(s32 arg0) {
    s32 i;
    s32 x;
    s32 best;
    u8 id;
    u8 pri;
    u8 bestpri;

    id = arg0 & 0xFF;
    for (i = 0; i < 0xC8; i++) {
        if (D_8009CE60[i] == -1) {
            D_8009CE60[i] = arg0;
            if (func_8002603C(id) == 0xA) {
                ((u8 *)D_8009CE60)[0x473] |= 1;
            }
            if (id == 0x2C) {
                ((u8 *)D_8009CE60)[0x473] |= 2;
            }
            func_800254E4(id);
            return;
        }
    }
    best = -1;
    bestpri = 0xFF;
    for (i = 0; i < 0xC8; i++) {
        x = D_8009CE60[i];
        pri = D_800494A4[x & 0xFF];
        if (pri < bestpri) {
            bestpri = pri;
            best = x;
        }
    }
    for (i = 0; i < 0xC8; i++) {
        if (D_8009CE60[i] == best) {
            D_8009CE60[i] = arg0;
            return;
        }
    }
}

void func_80025648(void) {
}

void func_80025650(void) {
}

u8 func_80025658(void) {
    return D_8009C739;
}

void *func_80025668(s32 arg0) {
    u8 idx;
    void *ret;

    idx = D_8009CBDC[arg0];
    ret = (void *)0xFF;
    if (idx != 0xFF) {
        ret = &D_80071E4D[D_8009C754[D_800491D0[idx]][1] * 0x24];
    }
    return ret;
}

void *func_800256DC(s32 arg0) {
    u8 idx;
    void *ret;

    idx = D_8009CBDC[arg0];
    ret = (void *)0xFF;
    if (idx != 0xFF) {
        ret = D_800738BC[D_8009C754[D_800491D0[idx]][0]];
    }
    return ret;
}

S24 *func_80025758(s32 arg0) {
    return &D_80071E44[arg0];
}

void *func_80025774(s32 arg0) {
    return &D_80071C24[arg0 * 0x10];
}

void *func_80025788(s32 arg0) {
    u8 idx;
    void *ret;

    idx = D_8009CBDC[arg0];
    if (idx == 0xFF) {
        ret = (void *)0xFF;
    } else {
        ret = D_8009D84C[arg0];
    }
    return ret;
}

void func_800257C4(void) {
}

void *func_800257CC(s32 arg0) {
    return D_8009C748[D_800491D0[arg0]];
}

void func_80025800(s32 arg0, s32 arg1) {
    u8 id;
    s32 k;
    s32 hp;

    id = D_8009CBDC[arg0];
    if (id != 0xFF) {
        k = D_800491D0[id];
        hp = D_8009D85C[arg0].hp - arg1;
        if (hp < 0) {
            D_8009D85C[arg0].hp = 0;
        } else {
            D_8009D85C[arg0].hp = hp;
        }
        D_8009C764[k].v = *(u16 *) &D_8009D85C[arg0];
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4b", func_800258BC);

void func_80025988(s32 arg0, s32 arg1) {
    u8 id;
    s32 v;
    s32 t;

    id = D_8009CBDC[arg0];
    if (id != 0xFF) {
        v = D_800491D0[id];
        t = D_8009D860[arg0].hp - arg1;
        if (t < 0) {
            D_8009D860[arg0].hp = 0;
        } else {
            D_8009D860[arg0].hp = t;
        }
        D_8009C768[v * 33].v = *(u16 *)&D_8009D860[arg0].hp;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4b", func_80025A44);

u32 func_80025B10(u32 arg0) {
    u32 v;

    v = D_8009D260[0];
    if (arg0 > v) {
        D_8009D260[0] = 0;
        return v;
    } else {
        D_8009D260[0] = v - arg0;
        return arg0;
    }
}

void func_80025B48(u32 arg0) {
    u32 t;
    u32 *p = (u32 *)&D_8009C6E4[0xB7C];

    t = *p + arg0;
    if (t < *p) {
        *p = -1;
        return;
    }
    *p = t;
}

s32 func_80025B7C(void) {
    return D_8009D260[0];
}

void func_80025B8C(s32 arg0) {
    Rect16 r;

    r.x = 0x340;
    r.y = 0x184;
    r.w = 0x30;
    r.h = 0x78;
    func_80044064(&r, arg0);
}

void func_80025BD0(void *arg0) {
    Rect16 r;

    r.x = 0x340;
    r.y = 0x184;
    r.w = 0x30;
    r.h = 0x78;
    func_80044000(&r, arg0);
}

void func_80025C14(s32 arg0) {
    Rect16 r;

    r.x = 0x180;
    r.w = 0x100;
    r.y = 0;
    r.h = 9;
    func_80044064(&r, arg0);
}

void func_80025C54(void *arg0) {
    Rect8 r;

    r.x = 0x180;
    r.w = 0x100;
    r.y = 0;
    r.h = 9;
    func_80044000(&r, arg0);
}

void func_80025C94(void *arg0) {
    s16 r[4];

    r[0] = 0x100;
    r[1] = 0x1ED;
    r[2] = 0x100;
    r[3] = 3;
    func_80044000(r, arg0);
}

void func_80025CD4(s32 arg0) {
    Rect16 r;

    r.x = 0x100;
    r.y = 0x1ED;
    r.w = 0x100;
    r.h = 3;
    func_80044064(&r, arg0);
}

void func_80025D14(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Unk80046D0C s;

    func_80046CFC((s32)arg0);
    while (func_80046D0C(&s) != 0) {
        if (s.a_arg != 0) {
            s.a[0] = arg3;
            s.a[1] = arg4;
            func_80044000(s.a, (void *)s.a_arg);
            func_80043DD8(0);
        }
        if (s.b_arg != 0) {
            s.b[0] = arg1;
            s.b[1] = arg2;
            func_80044000(s.b, (void *)s.b_arg);
            func_80043DD8(0);
        }
    }
}

void func_80025DF8(void) {
    u8 pad[8];
    u8 buf[0x1000];
    u8 *p;
    s32 i;

    i = 0;
    p = buf;
    do {
        func_80033F40(D_80048FE8[i * 2], D_80048FE8[i * 2 + 1], (s32)p, 0);
        func_80025D14(p, (i / 5) * 0x18 + 0x340, (i % 5) * 0x30 + 0x100, 0x180, i);
        func_80043DD8(0);
        i++;
    } while (i < 9);
}

void func_80025ED4(void) {
    Rect16 r;
    s32 i;
    s32 c;

    func_80043DD8(0);
    for (i = 0; i < 3; i++) {
        c = D_8009C9EF[0x1ED + i];
        if (c != -1) {
            r.w = 0x18;
            r.h = 0x30;
            r.x = 0x340;
            r.y = 0x100;
            if (c >= 5) {
                r.x = 0x358;
            } else {
                r.x = 0x340;
            }
            r.y += (c % 5) * 0x30;
            func_800440C8(&r, 0x3C0, 0x138 + i * 0x30);
            func_80043DD8(0);
            r.x = 0x180;
            r.y = c;
            r.w = 0x100;
            r.h = 1;
            func_800440C8(&r, 0x100, 0x1ED + i);
            func_80043DD8(0);
        }
    }
    func_80025CD4((s32)&D_800756F8);
    func_80043DD8(0);
}

void func_80026034(void) {
}

s32 func_8002603C(u8 arg0) {
    return D_80049520[D_80049528[D_800730DD[arg0].a & 0xF]];
}

void func_80026090(void) {
    do {

    } while (func_80034B44() != 0);
    func_800211C4(7);
    do {

    } while (func_80034B44() != 0);
    func_801D11A8();
    D_80062F90 = 0;
}

void func_800260DC(void) {
    Rect16 r;
    u8 buf1[0x1200];
    u8 buf2[0x1000];
    s32 i;
    s32 c;

    do {
    } while (func_80034B44() != 0);
    func_80043DD8(0);
    func_80025C14((s32)buf1);
    func_80043DD8(0);
    for (i = 0; i < 3; i++) {
        c = D_8009CBDC[i];
        if (c != 0xFF) {
            func_80020058(i);
            func_8001786C(i & 0xFF);
            func_80017678();
            func_80033F40(D_80048FE8[c * 2], D_80048FE8[c * 2 + 1], (s32)buf2, 0);
            func_80025D14(buf2, 0x3C0, 0x138 + i * 0x30, 0x180, i);
            func_80043DD8(0);
        }
    }
    r.x = 0x180;
    r.w = 0x100;
    r.y = 0;
    r.h = 3;
    func_80044064(&r, (s32)&D_800756F8);
    func_80043DD8(0);
    func_80025C54(buf1);
    func_80043DD8(0);
    func_8003CEDC(6);
    do {
    } while (func_800484A8() == -1);
    do {
    } while (func_80048540(1) != 0);
}

void func_80026258(void) {
    Unk8009D7BC *s;
    s32 i;
    u8 *p;

    D_80062F90 = 0;
    func_8001C434();
    func_80026090();
    func_80025008();
    func_800260DC();
    s = &D_8009D7BC;
    i = 15;
    p = &s->unk4[15];
    s->unk0 = 0x80;
    s->unk1 = 0x80;
    s->unk14 = 0x80;
    s->unk2 = 0x41;
    do {
        *p = i;
        i--;
        p--;
    } while (i >= 0);
}

void func_800262D8(void) {
    s32 i;
    u8 c;

    for (i = 0; i < 3; i++) {
        c = D_8009CBDC[i];
        if (c != 0xFF && (D_8009C756[D_800491D0[c]][0] + 0x120) == 0x13B) {
            func_800258BC(i, 3);
            if (D_8009D85C[i].hp != D_8009D85C[i].maxhp) {
                D_8009D85C[i].hp = D_8009D85C[i].hp & 0xFFFE;
                D_8009C764[D_8009CBDC[i]].v = D_8009C764[D_8009CBDC[i]].v & 0xFFFE;
            }
        }
    }
}

void func_80026408(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_80026448(void *arg0, s8 arg1, s8 arg2, s8 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, u16 arg13) {
    M2C_FIELD(arg0, s8 *, 0xA) = arg1;
    M2C_FIELD(arg0, s8 *, 0xB) = arg2;
    M2C_FIELD(arg0, s8 *, 0xC) = arg3;
    M2C_FIELD(arg0, s8 *, 0xD) = (s8) arg4;
    M2C_FIELD(arg0, s16 *, 0) = (s16) arg5;
    M2C_FIELD(arg0, s16 *, 2) = (s16) arg6;
    M2C_FIELD(arg0, s16 *, 4) = (s16) arg7;
    M2C_FIELD(arg0, s16 *, 6) = (s16) arg8;
    M2C_FIELD(arg0, s8 *, 0xE) = (s8) arg9;
    M2C_FIELD(arg0, s8 *, 0xF) = (s8) arg10;
    M2C_FIELD(arg0, s8 *, 0x10) = (s8) arg11;
    M2C_FIELD(arg0, s8 *, 0x11) = (s8) arg12;
    M2C_FIELD(arg0, u16 *, 8) = arg13;
}

void func_800264A8(MnCursor *arg0) {
    MnCursor *p;

    p = arg0;
    if (p->state == 0) {
        if (D_80062D7E & 0x1000) {
            p->row--;
            switch (p->vwrap) {
            case 0:
                if (p->row < 0) {
                    p->row = 0;
                    if (p->top > 0) {
                        p->top--;
                        p->anim = -3;
                        p->state = 1;
                        func_80026408(1);
                    }
                } else {
                    func_80026408(1);
                }
                break;
            case 1:
            case 2:
                if (p->row < 0) {
                    p->row = p->nrows - 1;
                }
                func_80026408(1);
                break;
            }
        } else if (D_80062D7E & 0x4000) {
            p->row++;
            switch (p->vwrap) {
            case 0:
                if (p->row >= p->nrows) {
                    p->row = p->nrows - 1;
                    if (p->top < p->count - p->nrows) {
                        p->anim = -1;
                        p->state = 2;
                        func_80026408(1);
                    }
                } else {
                    func_80026408(1);
                }
                break;
            case 1:
            case 2:
                if (p->row >= p->nrows) {
                    p->row = 0;
                }
                func_80026408(1);
                break;
            }
        } else if (D_80062D7E & 0x8000) {
            switch (p->hwrap) {
            case 0:
                if (--p->col < 0) {
                    p->col = 0;
                } else {
                    func_80026408(1);
                }
                break;
            case 1:
                if (--p->col < 0) {
                    p->col = p->ncols - 1;
                }
                func_80026408(1);
                break;
            case 2:
                if (p->col != 0 || p->row != 0 || p->top != 0) {
                    if (--p->col < 0) {
                        p->col = p->ncols - 1;
                        if (--p->row < 0) {
                            p->row = 0;
                            if (p->top > 0) {
                                p->top--;
                                p->anim = -3;
                                p->state = 1;
                            }
                        }
                    }
                    func_80026408(1);
                }
                break;
            }
        } else if (D_80062D7E & 0x2000) {
            switch (p->hwrap) {
            case 0:
                if (++p->col >= p->ncols) {
                    p->col = p->ncols - 1;
                } else {
                    func_80026408(1);
                }
                break;
            case 1:
                if (++p->col >= p->ncols) {
                    p->col = 0;
                }
                func_80026408(1);
                break;
            case 2:
                if (p->col != p->ncols - 1 || p->row != p->nrows - 1 || p->top != p->count - p->nrows) {
                    if (++p->col >= p->ncols) {
                        p->col = 0;
                        if (p->row >= p->ncols) {
                            p->col = 0;
                        }
                        if (++p->row >= p->nrows) {
                            p->row = p->nrows - 1;
                            if (p->top < p->count - p->nrows) {
                                p->anim = -1;
                                p->state = 2;
                            }
                        }
                    }
                    func_80026408(1);
                }
                break;
            }
        } else if (D_80062D7E & 8) {
            p->top += p->nrows;
            if (p->count - p->nrows < p->top) {
                p->top = p->count - p->nrows;
            } else {
                func_80026408(1);
            }
        } else if (D_80062D7E & 4) {
            p->top -= p->nrows;
            if (p->top < 0) {
                p->top = 0;
            } else {
                func_80026408(1);
            }
        }
    } else {
        switch (p->state) {
        case 1:
            if (++p->anim == 0) {
                p->state = 0;
                p->anim = 0;
            }
            break;
        case 2:
            if (--p->anim == -4) {
                p->state = 0;
                p->anim = 0;
                p->top++;
            }
            break;
        }
    }
}

void func_800269C0(s32 arg0) {
    D_80062F24 = arg0;
}

void func_800269D0(void) {
    D_80063008 = D_80062F24;
}

void func_800269E8(void) {
    D_80062F24 = D_80063008;
}
