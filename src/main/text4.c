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

void func_8001BDB0(u8 arg0, u8 *arg1) {
    s32 i;
    u8 *p;
    Unk80069554 *q;

    D_80062E64 = 0;
    D_80062E68 = 0;
    D_80062E90 = 0;
    D_80062E8C = 0;
    for (i = 0; i < 0x38; i++) {
        D_80069554[i].id = 0xFF;
        q = &D_80069554[i];
        q->unk3 = 0;
        q->unk2 = 0;
        D_80069554[i].unk1 = 0;
        D_80069554[i].unk4 = 0;
    }
    for (i = 0; i < 0x60; i++) {
        arg1[i * 8 + 0x108] = 0xFF;
        arg1[i * 8 + 0x10C] = 0;
        arg1[i * 8 + 0x10B] = 0;
        arg1[i * 8 + 0x10A] = 0;
        arg1[i * 8 + 0x10F] = 0;
    }
    for (i = 0; i < 0x10; i++) {
        D_800694D4[i] = 0;
        D_800694C4[i] = 0;
        D_800694B4[i] = 0;
    }
    for (i = 0; i < 12; i++) {
        D_800694E4[i] = 0;
    }
    for (i = 0; i < 6; i++) {
        D_800694FC[i] = 0;
    }
    for (i = 0; i < 0x10; i++) {
        D_80069508[i].a = 0xFF;
        D_80069508[i].b = 0;
        D_80069508[i].c = 0;
    }
    for (i = 0; i < 0x10; i++) {
        arg1[i * 6 + 0x4C] = 0xFF;
        arg1[i * 6 + 0x4F] = 1;
        arg1[i * 6 + 0x51] = 0;
    }
    for (i = 0; i < 8; i++) {
        p = D_80062E60 + i * 3;
        p[0x26] = 0;
        p[0x25] = 0;
        p[0x24] = 0;
    }
    D_8006953C = D_80062E60[2];
    D_8006953E = D_80062E60[3];
    D_80069540 = D_80062E60[4];
    D_80069542 = D_80062E60[5];
    D_80069544 = D_80062E60[6];
    D_80069546 = D_80062E60[7];
    D_80069550 = *(u16 *) (D_80062E60 + 0x12);
    D_80069552 = *(u16 *) (D_80062E60 + 0x16);
    D_80069538 = D_80062E60[0];
    D_8006953A = D_80062E60[1];
    D_80062E60[0x23] = 0;
    D_80069548 = ((s32 (*)()) func_8001FBAC)(arg0, 0);
    D_8006954A = ((s32 (*)()) func_8001FBAC)(arg0, 1);
    D_8006954C = ((s32 (*)()) func_8001FBAC)(arg0, 2);
    D_8006954E = ((s32 (*)()) func_8001FBAC)(arg0, 3);
    func_8001B834(1);
    func_8001B834(4);
    for (i = 0; i < 4; i++) {
        D_80062E6C[i] = 0;
    }
    D_80062E74 = 0;
    D_80062E60[0x43C] = 0;
    D_80062E60[0x43D] = 0;
    D_80062E60[0x437] = 0;
    D_80062E60[0x43E] = 0;
    D_80062E60[0x43F] = 0;
    D_80062E5C = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001C0EC);

void func_8001C3C4(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001C3CC);

void func_8001C434(void) {
    if (D_80062D70 == 0) {
        D_80062D70 = 1;
        func_80042A70();
        func_80042A60(D_800696AB + 1, 4, D_800696AB + 0x23, 4);
    }
    D_80062FA0 = 0;
}

void func_8001C484(s32 arg0) {
    D_80062E9C = arg0;
    D_80062E94 = 0x14;
}

u16 func_8001C498(void) {
    u16 r;

    if (D_800696AC != 0xFF && D_800696AD == 0x41) {
        r = ~(D_800696AF | (D_800696AE << 8));
    } else {
        r = 0;
    }
    return r;
}

u8 *func_8001C4E8(u8 *arg0) {
    s32 i;
    s32 c;

    D_80062D71 = 1;
    func_8001F6E4(1, D_80062D72, D_80062D74);
    func_8001F6C0((s32) arg0, 7);
    for (i = 0; i < 0x100; i++) {
        c = *arg0;
        if (c < 0xFF) {
            if (c >= 0xFA) {
                arg0 += 2;
                goto next;
            }
        }
        arg0 += 1;
    next:
        if (*arg0 == 0xFF) {
            arg0 += 1;
            break;
        }
    }
    return arg0;
}

void func_8001C58C(void) {
    if (!(func_8001F6B4() & 0xFF)) {
        D_80062D71 = 0;
    }
}

s32 func_8001C5BC(void) {
    s32 ret;
    u8 a;
    u8 *t;
    u8 *p0;
    u8 *p1;

    ret = 0;
    if (*(u8 *)&D_80062D71 != 0) {
        func_8001C58C();
    } else {
        t = (u8 *)D_80062E9C;
        D_80062E9C = (s32)(t + 1);
        switch (*t) {
        case 0:
            p0 = (u8 *)D_80062E9C;
            D_80062E9C = (s32)(p0 + 1);
            a = *p0;
            D_80062E94 = a;
            D_80062E94 = a + (p0[1] << 8);
            D_80062E9C = (s32)(p0 + 2);
            break;
        case 2:
            ret = 0x1000;
            goto done;
        case 3:
            ret = 0x4000;
            goto done;
        case 4:
            ret = 0x8000;
            goto done;
        case 5:
            ret = 0x2000;
            goto done;
        case 8:
            ret = 0x80;
            goto done;
        case 9:
            ret = 0x20;
            goto done;
        case 6:
            ret = 0x10;
            goto done;
        case 7:
            ret = 0x40;
            goto done;
        case 10:
            ret = 8;
            goto done;
        case 11:
            ret = 2;
            goto done;
        case 12:
            ret = 4;
            goto done;
        case 13:
            ret = 1;
        done:
            D_80062E94 = 0x14;
            break;
        case 16:
            D_80062E9C = (s32)func_8001C4E8((u8 *)D_80062E9C);
            D_80062E94 = 0x50;
            break;
        case 18:
            p1 = (u8 *)D_80062E9C;
            D_80062E9C = (s32)(p1 + 1);
            a = *p1;
            D_80062D72 = a;
            D_80062D72 = a + (p1[1] << 8);
            D_80062E9C = (s32)(p1 + 3);
            a = p1[2];
            D_80062D74 = a;
            D_80062D74 = a + (p1[3] << 8);
            D_80062E9C = (s32)(p1 + 4);
            D_80062E94 = 0x3C;
            break;
        case 17:
            func_8001F6E4(0, 0, 0);
            D_80062FA0 = 0;
            D_80062E94 = 0;
            break;
        default:
            break;
        }
    }
    return ret;
}

u16 func_8001C788(void) {
    u16 r;

    r = 0;
    if (D_80062E94 != 0) {
        D_80062E94 -= 1;
    } else if (func_80023050() == 0 || func_80023050() == 1) {
        if (func_80034B44() == 0) {
            r = func_8001C5BC();
        }
    }
    return r;
}

s32 func_8001C808(void) {
    u16 a;
    u16 b;

    if (D_80062FA0 == 0) {
        if (D_800696AC != 0xFF && D_800696AD == 0x41) {
            a = ~(D_800696AF | (D_800696AE << 8));
        } else {
            a = 0;
        }
    } else {
        a = func_8001C788();
    }
    if (D_800696CE != 0xFF && D_800696CF == 0x41) {
        b = ~(D_800696D1 | (D_800696D0 << 8));
    } else {
        b = 0;
    }
    return a | (b << 16);
}

s32 func_8001C8D4(void) {
    s32 pad;
    s32 hi;
    s32 out;
    s32 i;
    s32 bit;

    pad = func_8001C808();
    hi = pad & 0xFFFF0000;
    if (((D_8009D7BC.unk2 >> 2) & 3) && D_80062FA0 == 0) {
        out = 0;
        i = 0;
        while (1) {
            bit = 1 << i;
            if (pad & bit) {
                out |= 1 << D_8009D7BC.unk4[i];
            }
            i++;
            if (i >= 16) {
                goto end;
            }
        }
    }
    out = pad & 0xFFFF;
end:
    return out | hi;
}

void func_8001C980(void) {
    u16 t;
    D_80062D90.a = D_80062D80;
    D_80062D88 = D_80062D78;
    t = D_80062D78 ^ D_80062D8A;
    D_80062D8C.a = t & D_80062D78;
    if (D_80062D78 != D_80062D8A) {
        D_80062D68 = 0;
        D_80062D6C = 0;
    } else if (D_80062D68 != 0) {
        if (D_80062D6C == 1) {
            D_80062D8C.b = D_80062D78;
            D_80062D6C = 0;
        } else {
            D_80062D6C += 1;
            D_80062D8C.b = 0;
        }
    } else {
        if (D_80062D6C == 7) {
            D_80062D68 = 1;
            D_80062D6C = 0;
        } else {
            D_80062D6C += 1;
        }
        D_80062D8C.b = 0;
    }
    t = D_80062D90.a ^ D_80062D90.b;
    D_80062D94.a = t & D_80062D90.a;
    if (D_80062D90.a != D_80062D90.b) {
        D_80062D6A = 0;
        D_80062D6E = 0;
    } else if (D_80062D6A != 0) {
        if (D_80062D6E == 1) {
            D_80062D94.b = D_80062D90.a;
            D_80062D6E = 0;
        } else {
            D_80062D6E += 1;
            D_80062D94.b = 0;
        }
    } else {
        if (D_80062D6E == 7) {
            D_80062D6A = 1;
            D_80062D6E = 0;
        } else {
            D_80062D6E += 1;
        }
        D_80062D94.b = 0;
    }
    D_80062D8C.b |= D_80062D8C.a;
    D_80062D94.b |= D_80062D94.a;
    D_80062D8A = D_80062D88;
    D_80062D90.b = D_80062D90.a;
}

void func_8001CB48(void) {
    u32 pad;
    s32 i;
    s32 bit;
    u16 t;

    pad = func_8001C808();
    D_80062D80 = pad >> 16;
    if (((D_8009D7BC.unk2 >> 2) & 3) && D_80062FA0 == 0) {
        D_80062D78 = 0;
        i = 0;
        do {
            bit = 1 << i;
            if (pad & bit) {
                D_80062D78 |= 1 << D_8009D7BC.unk4[i];
            }
            i++;
        } while (i < 16);
    } else {
        D_80062D78 = pad;
    }
    D_80062D7E = 0;
    t = D_80062D78 ^ D_80062D7A;
    D_80062D7C = t & D_80062D78;
    if (D_80062D78 != D_80062D7A) {
        D_80062D64 = 0;
        D_80062D60 = 0;
    } else if (D_80062D60 != 0) {
        if (D_80062D64 == 3) {
            D_80062D7E = D_80062D78;
            D_80062D64 = 0;
        } else {
            D_80062D64 += 1;
        }
    } else {
        if (D_80062D64 == 0xF) {
            D_80062D60 = 1;
            D_80062D64 = 0;
        } else {
            D_80062D64 += 1;
        }
    }
    t = D_80062D80 ^ D_80062D82;
    D_80062D84.a = t & D_80062D80;
    if (D_80062D80 != D_80062D82) {
        D_80062D62 = 0;
        D_80062D66 = 0;
    } else if (D_80062D62 != 0) {
        if (D_80062D66 == 3) {
            D_80062D84.b = D_80062D80;
            D_80062D66 = 0;
        } else {
            D_80062D66 += 1;
            D_80062D84.b = 0;
        }
    } else {
        if (D_80062D66 == 0xF) {
            D_80062D62 = 1;
            D_80062D66 = 0;
        } else {
            D_80062D66 += 1;
        }
        D_80062D84.b = 0;
    }
    D_80062D7E |= D_80062D7C;
    D_80062D84.b |= D_80062D84.a;
    D_80062D7A = D_80062D78;
    D_80062D82 = D_80062D80;
}

void func_8001CDA4(void) {
    func_800468FC(D_80062F24);
    func_80046870(D_80062F24, 1);
    M2C_FIELD(D_80062F24, s16 *, 8) = 0;
    M2C_FIELD(D_80062F24, s16 *, 0xA) = 5;
    M2C_FIELD(D_80062F24, s16 *, 0x10) = 0x40;
    M2C_FIELD(D_80062F24, s16 *, 0x12) = 5;
    M2C_FIELD(D_80062F24, s16 *, 0x18) = 0;
    M2C_FIELD(D_80062F24, s16 *, 0x1A) = 0x45;
    M2C_FIELD(D_80062F24, s16 *, 0x20) = 0x40;
    M2C_FIELD(D_80062F24, s16 *, 0x22) = 0x45;
    M2C_FIELD(D_80062F24, s8 *, 0xC) = 0;
    M2C_FIELD(D_80062F24, s8 *, 0xD) = 0;
    M2C_FIELD(D_80062F24, u8 *, 0x14) = 0x80;
    M2C_FIELD(D_80062F24, s8 *, 0x15) = 0;
    M2C_FIELD(D_80062F24, s8 *, 0x1C) = 0;
    M2C_FIELD(D_80062F24, u8 *, 0x1D) = 0x80;
    M2C_FIELD(D_80062F24, u8 *, 0x24) = 0x80;
    M2C_FIELD(D_80062F24, u8 *, 0x25) = 0x80;
    M2C_FIELD(D_80062F24, s16 *, 0xE) = func_80046634(0, 0x1FE);
    M2C_FIELD(D_80062F24, s16 *, 0x16) = func_8004656C(1, 0, 0x340, 0);
    func_80046794(*(const s32 *)&D_80062FC4, (s32) D_80062F24);
    D_80062F24 += 0x28;
}

void func_8001CF3C(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, s16 arg8, s16 arg9) {
    s16 temp_a0;

    u8 * volatile *new_var;
    s16 temp_v1;
    s8 temp_a1;
    s8 temp_v1_2;
    func_800468FC(D_80062F24);
    func_80046870(D_80062F24, 1);
    new_var = &D_80062F24;
    if (arg9 != 0) {
        func_80046848(*new_var, 1);
    }
    *((s16 *)(((s8 *)(*new_var)) + 8)) = arg0;
    *((s16 *)(((s8 *)(*new_var)) + 0xA)) = arg1;
    temp_a0 = arg0 + arg2;
    *((s16 *)(((s8 *)D_80062F24) + 0x10)) = temp_a0;
    *((s16 *)(((s8 *)(*new_var)) + 0x12)) = arg1;
    *((s16 *)(((s8 *)D_80062F24) + 0x18)) = arg0;
    temp_v1 = arg1 + arg3;
    *((s16 *)(((s8 *)D_80062F24) + 0x1A)) = temp_v1;
    *((s16 *)(((s8 *)D_80062F24) + 0x20)) = temp_a0;
    *((s16 *)(((s8 *)D_80062F24) + 0x22)) = temp_v1;
    *((s8 *)(((s8 *)(*new_var)) + 0xC)) = (s8)arg4;
    *((s8 *)(((s8 *)(*new_var)) + 0xD)) = (s8)arg5;
    temp_a1 = arg4 + arg6;
    *((s8 *)(((s8 *)(*new_var)) + 0x14)) = temp_a1;
    *((s8 *)(((s8 *)(*new_var)) + 0x15)) = (s8)arg5;
    *((s8 *)(((s8 *)D_80062F24) + 0x1C)) = (s8)arg4;
    temp_v1_2 = arg5 + arg7;
    *((s8 *)(((s8 *)D_80062F24) + 0x1D)) = temp_v1_2;
    *((s8 *)(((s8 *)D_80062F24) + 0x24)) = temp_a1;
    *((s8 *)(((s8 *)(*new_var)) + 0x25)) = temp_v1_2;
    *((s16 *)(((s8 *)(*new_var)) + 0xE)) = func_80046634(0x100, arg8 + 0x1E0);
    *((s16 *)(((s8 *)(*new_var)) + 0x16)) = func_8004656C(1, 0, 0x3C0, 0x100);
    func_80046794(*((const s32 *)(&D_80062FC4)), (s32)(*new_var));
    D_80062F24 += 0x28;
}

void func_8001D180(s16 arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, s16 arg8, s16 arg9) {
    s16 temp_a0;

    u8 * volatile *new_var;
    s16 temp_v1;
    s8 temp_a1;
    s8 temp_v1_2;
    func_800468FC(D_80062F24);
    func_80046870(D_80062F24, 1);
    new_var = &D_80062F24;
    if (arg9 != 0) {
        func_80046848(*new_var, 1);
    }
    *((s16 *)(((s8 *)(*new_var)) + 8)) = arg0;
    *((s16 *)(((s8 *)(*new_var)) + 0xA)) = arg1;
    temp_a0 = arg0 + arg2;
    *((s16 *)(((s8 *)D_80062F24) + 0x10)) = temp_a0;
    *((s16 *)(((s8 *)(*new_var)) + 0x12)) = arg1;
    *((s16 *)(((s8 *)D_80062F24) + 0x18)) = arg0;
    temp_v1 = arg1 + arg3;
    *((s16 *)(((s8 *)D_80062F24) + 0x1A)) = temp_v1;
    *((s16 *)(((s8 *)D_80062F24) + 0x20)) = temp_a0;
    *((s16 *)(((s8 *)D_80062F24) + 0x22)) = temp_v1;
    *((s8 *)(((s8 *)(*new_var)) + 0xC)) = (s8)arg4;
    *((s8 *)(((s8 *)(*new_var)) + 0xD)) = (s8)arg5;
    temp_a1 = arg4 + arg6;
    *((s8 *)(((s8 *)(*new_var)) + 0x14)) = temp_a1;
    *((s8 *)(((s8 *)(*new_var)) + 0x15)) = (s8)arg5;
    *((s8 *)(((s8 *)D_80062F24) + 0x1C)) = (s8)arg4;
    temp_v1_2 = arg5 + arg7;
    *((s8 *)(((s8 *)D_80062F24) + 0x1D)) = temp_v1_2;
    *((s8 *)(((s8 *)D_80062F24) + 0x24)) = temp_a1;
    *((s8 *)(((s8 *)(*new_var)) + 0x25)) = temp_v1_2;
    *((s16 *)(((s8 *)(*new_var)) + 0xE)) = func_80046634(0x180, arg8);
    *((s16 *)(((s8 *)(*new_var)) + 0x16)) = func_8004656C(1, 0, 0x340, 0x100);
    func_80046794(*((const s32 *)(&D_80062FC4)), (s32)(*new_var));
    D_80062F24 += 0x28;
}

void func_8001D3C0(s16 arg0, s16 arg1) {
    func_80046974(D_80062F24);
    *(s16 *)(D_80062F24 + 8) = arg0;
    *(s16 *)(D_80062F24 + 10) = arg1;
    D_80062F24[4] = 0xFF;
    D_80062F24[5] = 0xFF;
    D_80062F24[6] = 0;
    func_80046794(D_80062FC4, (s32)D_80062F24);
    D_80062F24 += 12;
}

void func_8001D47C(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    func_800469C4(D_80062F24);
    ((volatile PrimL *) D_80062F24)->r = arg3 >> 16;
    ((volatile PrimL *) D_80062F24)->g = arg3 >> 8;
    ((volatile PrimL *) D_80062F24)->b = arg3;
    ((volatile PrimL *) D_80062F24)->x0 = arg0;
    ((volatile PrimL *) D_80062F24)->y0 = arg2;
    ((volatile PrimL *) D_80062F24)->x1 = arg1;
    ((volatile PrimL *) D_80062F24)->y1 = arg2;
    func_80046794(*(s32 *) &D_80062FC4, (s32) D_80062F24);
    D_80062F24 += 16;
}

void func_8001D56C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    s32 t;
    u8 *p;

    if (arg4 != 0) {
        func_800469C4(D_80062F24);
        D_80062F24[4] = 0xFF;
        D_80062F24[5] = 0xFF;
        D_80062F24[6] = 0;
    } else {
        func_800469C4(D_80062F24);
        D_80062F24[4] = 0x80;
        D_80062F24[5] = 0x80;
        D_80062F24[6] = 0x80;
    }
    p = D_80062F24;
    t = D_80062FC4;
    *(s16 *)(p + 8) = arg0;
    *(s16 *)(D_80062F24 + 10) = arg1;
    *(s16 *)(D_80062F24 + 12) = arg2;
    *(s16 *)(D_80062F24 + 14) = arg3;
    func_80046794(t, (s32)D_80062F24);
    D_80062F24 += 16;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001D6A8);

void func_8001DE0C(void *arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    M2C_FIELD(arg0, s16 *, 0) = arg1;
    M2C_FIELD(arg0, s16 *, 2) = arg2;
    M2C_FIELD(arg0, s16 *, 4) = arg3;
    M2C_FIELD(arg0, s16 *, 6) = (s16) arg4;
}

void func_8001DE24(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, u16 *, 0) = (u16) (M2C_FIELD(arg0, u16 *, 0) + arg1);
    M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + arg2);
}

void func_8001DE40(void *arg0, void *arg1) {
    M2C_FIELD(arg0, u16 *, 0) = (u16) M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg1, u16 *, 2);
    M2C_FIELD(arg0, u16 *, 4) = (u16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg1, u16 *, 6);
}

void func_8001DE70(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        D_800696F0[i] = D_80049208[i];
    }
}

void func_8001DEB0(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        D_80049208[i] = D_800696F0[i];
    }
}

void func_8001DEF0(u8 *arg0) {
    s32 i;

    for (i = 0; i < 12; i++) {
        D_80049208[i] = *arg0++;
    }
}

void func_8001DF24(u16 *arg0, s32 arg1, s8 arg2, s8 arg3) {
    u8 *p;
    s32 t;

    D_80062F24[3] = 3;
    D_80062F24[7] = 0x60;
    func_80046870(*(u8 **)&D_80062F24, 1);
    *(u16 *)(D_80062F24 + 8) = arg0[0];
    *(u16 *)(D_80062F24 + 10) = arg0[1];
    *(u16 *)(D_80062F24 + 12) = arg0[2];
    *(u16 *)(D_80062F24 + 14) = arg0[3];
    D_80062F24[4] = arg1;
    D_80062F24[5] = arg2;
    D_80062F24[6] = arg3;
    p = D_80062F24;
    t = D_80062FC4;
    D_80062F24 = p + 0x10;
    func_80046794(t, (s32)p);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001E040);

void func_8001EB2C(s16 arg0, s16 arg1) {
    Rect16 r;
    u8 *p;
    s32 t;

    D_80062F24[3] = 4;
    D_80062F24[7] = 0x64;
    func_80046848(D_80062F24, 1);
    func_80046870(D_80062F24, 1);
    *(s16 *)(D_80062F24 + 8) = arg0;
    *(s16 *)(D_80062F24 + 10) = arg1;
    D_80062F24[12] = 0xE0;
    D_80062F24[13] = 8;
    *(s16 *)(D_80062F24 + 16) = 0x18;
    *(s16 *)(D_80062F24 + 18) = 0x10;
    *(s16 *)(D_80062F24 + 14) = func_80046634(0x100, 0x1E1);
    p = D_80062F24;
    t = D_80062FC4;
    D_80062F24 = p + 0x14;
    func_80046794(t, (s32)p);
    r.x = 0;
    r.y = 0;
    r.w = 0xFF;
    r.h = 0xFF;
    func_80026A34(0, 1, func_8004656C(0, 2, 0x3C0, 0x100) & 0xFFFF, (s32)&r);
}

void func_8001EC70(s32 x, s32 y, s32 value) {
    s16 rect[4];
    s32 i;
    s32 digit;
    u8 *p;

    M2C_FIELD(D_80062F24, s8 *, 3) = 4;
    M2C_FIELD(D_80062F24, s8 *, 7) = 0x64;
    func_80046870(D_80062F24, 1);
    M2C_FIELD(D_80062F24, s16 *, 8) = x + 0x20;
    M2C_FIELD(D_80062F24, s16 *, 0xA) = y;
    M2C_FIELD(D_80062F24, u8 *, 0xC) = (value & 1) ? 0xA8 : 0xA0;
    M2C_FIELD(D_80062F24, s8 *, 0xD) = 0x50;
    M2C_FIELD(D_80062F24, s16 *, 0x10) = 8;
    M2C_FIELD(D_80062F24, s16 *, 0x12) = 0x15;
    M2C_FIELD(D_80062F24, s16 *, 0xE) = func_80046634(0x100, 0x1EC);
    p = D_80062F24;
    D_80062F24 = p + 0x14;
    func_80046794(*(s32 *) &D_80062FC4, (s32) p);
    if (value >= 0x1770) {
        value = 0x176F;
    }
    for (i = 0; i < 4; i++) {
        digit = value / D_80049214[i];
        M2C_FIELD(D_80062F24, s8 *, 3) = 4;
        M2C_FIELD(D_80062F24, s8 *, 7) = 0x64;
        func_80046870(D_80062F24, 1);
        M2C_FIELD(D_80062F24, s16 *, 8) = x;
        M2C_FIELD(D_80062F24, s16 *, 0xA) = y;
        M2C_FIELD(D_80062F24, s8 *, 0xC) = (digit % 5) * 0x10 - 0x50;
        M2C_FIELD(D_80062F24, u8 *, 0xD) = (digit >= 5) ? 0x68 : 0x50;
        M2C_FIELD(D_80062F24, s16 *, 0x10) = 0x10;
        M2C_FIELD(D_80062F24, s16 *, 0x12) = 0x15;
        M2C_FIELD(D_80062F24, s16 *, 0xE) = func_80046634(0x100, 0x1EC);
        p = D_80062F24;
        D_80062F24 = p + 0x14;
        func_80046794(*(s32 *) &D_80062FC4, (s32) p);
        if (i == 1) {
            x += 8;
        }
        x += 0x10;
        value = value % D_80049214[i];
    }
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, func_8004656C(0, 1, 0x3C0, 0x100) & 0xFFFF, (s32) rect);
}

void func_8001EF84(s32 x, s32 y, s32 value, s32 count) {
    s16 rect[4];
    s32 i;
    s32 digit;
    u8 *p;

    for (i = 0; i < 8; i++) {
        digit = value / D_80049224[i];
        M2C_FIELD(D_80062F24, s8 *, 3) = 4;
        M2C_FIELD(D_80062F24, s8 *, 7) = 0x64;
        func_80046870(D_80062F24, 1);
        M2C_FIELD(D_80062F24, s16 *, 8) = x;
        M2C_FIELD(D_80062F24, s16 *, 0xA) = y;
        M2C_FIELD(D_80062F24, s8 *, 0xC) = (digit % 5) * 0x10 - 0x50;
        M2C_FIELD(D_80062F24, u8 *, 0xD) = (digit >= 5) ? 0x68 : 0x50;
        M2C_FIELD(D_80062F24, s16 *, 0x10) = 0x10;
        M2C_FIELD(D_80062F24, s16 *, 0x12) = 0x15;
        M2C_FIELD(D_80062F24, s16 *, 0xE) = func_80046634(0x100, 0x1EC);
        if (count >= 8 - i) {
            p = D_80062F24;
            D_80062F24 = p + 0x14;
            func_80046794(*(s32 *) &D_80062FC4, (s32) p);
            do { } while (0);
            x += 0x10;
        }
        value = value % D_80049224[i];
    }
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, func_8004656C(0, 1, 0x3C0, 0x100) & 0xFFFF, (s32) rect);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text4", func_8001F1BC);

void func_8001F6AC(void) {
}

u8 func_8001F6B4(void) {
    return D_80062DDB;
}

void func_8001F6C0(s32 arg0, s8 arg1) {
    D_80062DDB = 1;
    D_80062DDC = arg1;
    D_80062DE0 = 0x28;
    D_80062EB8 = arg0;
    D_80062DE5 = 1;
}

void func_8001F6E4(s32 arg0, s16 arg1, s16 arg2) {
    D_80062DE4 = (s8) arg0;
    if ((arg0 << 0x10) != 0) {
        D_80062DE6 = arg1;
        D_80062DE8 = arg2;
        return;
    }
    D_80062DDB = 0;
}

void func_8001F710(void) {
    u8 sp18[8];
    s32 w;
    s32 cx;
    s32 cy;
    s32 bw;
    s32 k;
    s32 x;
    u32 h;

    if (D_80062DDB == 0) {
        return;
    }
    w = func_80026B70(D_80062EB8);
    switch (D_80062DDB) {
    case 1:
        bw = (w / 3) * D_80062DE5;
        h = D_80062DE5 << 3;
        if (D_80062DE4 == 0) {
            cx = 0xB4;
            cy = 0x68;
            ((void (*)()) func_8001DE0C)(sp18, cx - bw / 2, cy - (h >> 1), bw, h);
        } else {
            cx = D_80062DE6;
            cy = D_80062DE8;
            k = 0xC;
            ((void (*)()) func_8001DE0C)(sp18, cx + (w + 0x10) / 2 - bw / 2, cy - ((h >> 1) - k), bw, h);
        }
        D_80062DE5 = D_80062DE5 + 1;
        if (D_80062DE5 == 3) {
            D_80062DDB = D_80062DE5 = 2;
        }
        break;
    case 2:
        if (D_80062DE4 == 0) {
            cx = 0xB4;
            x = cx - w / 2;
            func_80026F44(x, 0x62, D_80062EB8, D_80062DDC);
            ((void (*)()) func_8001DE0C)(sp18, x - 8, 0x5C, w + 0x10, 0x18);
        } else {
            cx = D_80062DE6;
            cy = D_80062DE8;
            func_80026F44(cx + 8, cy + 6, D_80062EB8, D_80062DDC);
            ((void (*)()) func_8001DE0C)(sp18, cx, cy, w + 0x10, 0x18);
        }
        if (D_80062DE0 != 0) {
            D_80062DE0 = D_80062DE0 - 1;
        }
        if (D_80062DE0 < 0x14) {
            if (func_80034B44() == 0) {
                if (D_80062DE4 != 0 || D_80062DE0 != 0) {
                    if (((s32 (*)(void))func_8001C498)() == 0) {
                        break;
                    }
                }
                D_80062DDB = 3;
            }
        }
        break;
    case 3:
        bw = (w / 3) * D_80062DE5;
        h = D_80062DE5 << 3;
        if (D_80062DE4 == 0) {
            cx = 0xB4;
            cy = 0x68;
            ((void (*)()) func_8001DE0C)(sp18, cx - bw / 2, cy - (h >> 1), bw, h);
        } else {
            cx = D_80062DE6;
            cy = D_80062DE8;
            k = 0xC;
            ((void (*)()) func_8001DE0C)(sp18, cx + (w + 0x10) / 2 - bw / 2, cy - ((h >> 1) - k), bw, h);
        }
        D_80062DE5 = D_80062DE5 - 1;
        if (D_80062DE5 == 0) {
            D_80062DDB = 0;
        }
        break;
    }
    func_8001DE70();
    func_8001DEF0(D_80049384);
    func_8001E040(sp18);
    func_8001DEB0();
}

s32 func_8001FA28(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    return func_8002DA7C(temp_a0);
}

void func_8001FA68(s32 arg0) {
    s32 temp_a0;

    D_8009A000 = 0x28;
    temp_a0 = arg0 & 0xFFFF;
    D_8009A004 = 0x40;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_8001FAAC(s32 arg0) {
    s32 temp_a0;

    D_8009A000 = 0x29;
    temp_a0 = arg0 & 0xFFFF;
    D_8009A004 = 0x40;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_8001FAF0(void) {
}

u16 func_8001FAF8(s32 arg0) {
    if (arg0 < 0x80) {
        return D_800722D6[arg0].v;
    }
    if (arg0 < 0x100) {
        return D_800738CA[arg0 - 0x80].v;
    }
    if (arg0 < 0x120) {
        return D_80071E64[arg0 - 0x100].v;
    }
    return D_80071C32[arg0 - 0x120].v;
}

s32 func_8001FBAC(s32 arg0, s32 arg1, s32 arg2) {
    s32 idx;

    idx = D_800491D0[D_8009CBDC[arg0]];
    switch (arg1) {
    case 0:
        arg2 = D_800738A4[D_8009C754[D_800491D0[idx]][0]].v;
        break;
    case 1:
        arg2 = D_80071E46[D_8009C755[D_800491D0[idx]][0]].v;
        break;
    case 2:
        arg2 = 0;
        break;
    case 3:
        arg2 = 0;
        break;
    }
    return arg2;
}
