#include "common.h"
#include "savemenu/decls.h"

void func_801D0408(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

s32 func_801D0448(s32 arg0) {
    s16 rect[4];
    volatile SvPrim *p;
    volatile SvPrim *volatile *pp;

    pp = &D_80062F24;
    D_80062F24->len = 3;
    D_80062F24->code = 0x60;
    func_80046848(*pp, 1);
    D_80062F24->x = 0;
    D_80062F24->y = 0;
    D_80062F24->w = 0x180;
    D_80062F24->h = 0xE8;
    D_80062F24->r = D_801D4EC4;
    D_80062F24->g = D_801D4EC4;
    D_80062F24->b = D_801D4EC4;
    p = *pp; *(volatile SvPrim **)pp = p + 1; func_80046794(D_80062FC4, (s32)p);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x5F, (s32)rect);
    D_801D4EC4 += arg0;
    if (D_801D4EC4 < 0) {
        D_801D4EC4 = 0;
    }
    if (D_801D4EC4 >= 0x100) {
        D_801D4EC4 = 0xFF;
    }
    return D_801D4EC4;
}

void func_801D05C0(s32 arg0) {
    D_801E3860 = 0xF0;
    D_801E36B8 = arg0 & 0xFF;
    D_801E3850 = 0;
    func_80026448(&D_801E379C, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0U);
    func_80025B8C((s32) &D_801E8F44);
    func_80025C14((s32) &D_801E4538);
    func_80025DF8();
    func_801D19C4();
}

void func_801D0670(void) {
    func_80025BD0(&D_801E8F44);
    func_80025C54(&D_801E4538);
    func_801D1BA4();
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D06B0);

s32 func_801D1774(void) {
    s32 i;
    s32 ret;

    func_80021044(D_801E36BC, D_801E3774);
    i = 0;
    D_801E36B0 = 0;
    func_801D05C0(1);
    D_801E36B4 = 0;
    while (1) {
        func_8001CB48();
        func_800269C0((s32)(D_80077F64 + D_801E36B4 * 0x3400));
        D_801E3854 = D_801E3858 + D_801E36B4 * 4;
        func_8004418C(D_801E3854, 1);
        func_80026A00((s32)D_801E3854);
        func_8001F710();
        ret = func_801D06B0(i);
        if (D_801E36B0 == -1) {
            break;
        }
        func_80043DD8(0);
        func_8003CEDC(0);
        func_800444AC((void *)(D_801E3774 + D_801E36B4 * 0x14));
        func_800443B0((void *)(D_801E36BC + D_801E36B4 * 0x5C));
        i++;
        func_8004433C((s32)D_801E3854);
        D_801E36B4 ^= 1;
    }
    func_801D0670();
    func_8003CEDC(0);
    func_800444AC((void *)D_801E3774);
    func_800443B0((void *)D_801E36BC);
    func_8003CEDC(0);
    func_800444AC((void *)(D_801E3774 + 0x14));
    func_800443B0((void *)(D_801E36BC + 0x5C));
    return ret;
}

u16 func_801D1950(u16 arg0, u8 *arg1) {
    s32 crc;
    u16 i;
    u16 j;

    crc = 0xFFFF;
    for (i = 0; i < arg0; i++) {
        crc ^= arg1[i] << 8;
        for (j = 0; j < 8; j++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ 0x1021;
            } else {
                crc <<= 1;
            }
        }
    }
    return ~crc;
}

void func_801D19C4(void) {
    s32 i;
    s32 *p;

    if (D_80062DCC == 0) {
        i = 0;
        func_80042AF0();
        p = &D_8009A024;
        *p = func_80042A00(0xF4000001, 4, 0x2000, 0);
        D_8009A028 = func_80042A00(0xF4000001, 0x8000, 0x2000, 0);
        D_8009A02C = func_80042A00(0xF4000001, 0x100, 0x2000, 0);
        D_8009A030 = func_80042A00(0xF4000001, 0x2000, 0x2000, 0);
        D_8009A034 = func_80042A00(0xF0000011, 4, 0x2000, 0);
        D_8009A038 = func_80042A00(0xF0000011, 0x8000, 0x2000, 0);
        D_8009A03C = func_80042A00(0xF0000011, 0x100, 0x2000, 0);
        D_8009A040 = func_80042A00(0xF0000011, 0x2000, 0x2000, 0);
        func_800489F0(1);
        func_80048A44();
        func_80042BA0(0);
        func_800429B0();
        func_80048988(0);
        for (; i < 8; i++) {
            func_80042A40(p[i]);
        }
        func_80042B00();
        D_80062DCC = 1;
    }
    for (i = 0; i < 2; i++) {
        D_801E8F38[i].a = 0;
        D_801E8F38[i].b = 0;
        D_801E8F38[i].c = 0;
    }
}

void func_801D1BA4(void) {
}

void func_801D1BAC(s32 arg0, s32 arg1) {
    func_80042A30((&D_8009A024)[arg1]);
}

s32 func_801D1BE0(u8 *arg0, u8 *arg1) {
    do {
        if (*arg0++ != *arg1++) {
            return 0;
        }
    } while (*arg0 != 0 || *arg1 != 0);
    return 1;
}

INCLUDE_RODATA("../asm/us/savemenu/nonmatchings/text", D_801D0050);

u16 func_801D1C2C(s32 arg0) {
    u8 buf[0x28];
    s32 i;
    s32 dir;
    s32 mask;

    mask = 0;
    i = 0;
    do {
        dir = func_80042B70(arg0 ? "bu10:*" : "bu00:*", buf);
        i++;
    } while (dir == 0 && i < 100);
    if (dir != 0) {
        do {
            for (i = 0; i < 15; i++) {
                if (func_801D1BE0((u8 *)dir, D_801E2C78[i])) {
                    mask |= 1 << i;
                }
            }
            dir = func_80042B80(dir);
        } while (dir != 0);
    } else {
        mask = 0;
    }
    return mask;
}

u8 *func_801D1D1C(s32 arg0) {
    return D_801E3864[arg0];
}

s32 func_801D1D40(s32 arg0) {
    u8 pad[0x28];
    char path[0x20];
    s32 fd;
    s32 tries;
    s32 n;

    D_801E8F40 = 0x280;
    if (arg0 & 0x10) {
        func_80042DD8(path, D_801D018C, D_801E2C78[arg0 & 0xF]);
    } else {
        func_80042DD8(path, D_801D0194, D_801E2C78[arg0 & 0xF]);
    }
    fd = func_80042B20(path, 1);
    if (fd == -1) {
        return 1;
    }
    tries = 30;
    do {
        n = func_80042B30(fd, D_801E6F38, D_801E8F40);
        if (n == D_801E8F40) {
            goto ok;
        }
        tries--;
        if (n != -1) {
            D_801E8F40 -= n;
        }
    } while (tries != 0);
    func_80042B50(fd);
    return 2;
ok:
    func_80042B50(fd);
    *(SvHeadB *)D_801E3864[arg0 & 0xF] = *(SvHeadB *)D_801E7138;
    return 0;
}

s32 func_801D1F40(s32 arg0) {
    u8 pad[0x28];
    char path[0x20];
    s32 fd;
    s32 tries;
    s32 i;

    D_801E8F40 = 0x2000;
    if (arg0 & 0x10) {
        func_80042DD8(path, D_801D018C, D_801E2C78[arg0 & 0xF]);
    } else {
        fd = arg0;
        func_80042DD8(path, D_801D0194, D_801E2C78[fd & 0xF]);
    }
    fd = func_80042B20(path, 1);
    if (fd == -1) {
        return 1;
    }
    tries = 30;
    do {
        i = func_80042B30(fd, D_801E6F38, D_801E8F40);
        if (i == D_801E8F40) {
            goto ok;
        }
        tries++;
        if (i != -1) {
            D_801E8F40 -= i;
        }
    } while (tries != 0);
    func_80042B50(fd);
    return 2;
ok:
    func_80042B50(fd);
    *(SvSave *)D_8009C6E4 = *(SvSave *)D_801E7138;
    for (i = 0; i < 12; i++) {
        D_80049208[i] = D_8009C6E4[0x48 + i];
    }
    return 0;
}

s32 func_801D2150(u8 arg0) {
    s32 ret;

    if ((arg0 >= 0x99 && arg0 <= 0x9F) || (arg0 >= 0xE1 && arg0 <= 0xFC)) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

s32 func_801D2184(u8 arg0) {
    s32 ret;

    if ((arg0 >= 0x81 && arg0 <= 0x9F) || (arg0 >= 0xE0 && arg0 <= 0xFC)) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

void func_801D21B8(u8 *arg0, u8 *arg1) {
    s32 var_v1;
    u8 *var_a0;
    u8 *var_a1;
    u8 temp_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v1 = 0;
    do {
        temp_v0 = *var_a1;
        var_a1 += 1;
        var_v1 += 1;
        *var_a0 = temp_v0;
        var_a0 += 1;
    } while (var_v1 < 0x40);
}

void func_801D21E0(s32 arg0) {
    D_801E2CB4 = arg0;
}

void func_801D21F0(u8 *arg0, u8 *arg1) {
    s32 pad;
    s32 i;

    for (i = 0; i < D_801E2CB4; i++) {
        *arg0++ = *arg1;
        if (*arg1 == 0xFF) {
            break;
        }
        arg1++;
    }
}

void func_801D224C(void) {
    s32 i;
    u8 c;

    for (i = 0; i < 3; i++) {
        D_8009C6E4[5 + i] = D_8009CBDC[i];
    }
    func_801D21E0(16);
    for (i = 0; i < 3; i++) {
        c = D_8009CBDC[i];
        if (c != 0xFF) {
            func_801D21F0(((SvHeader *)D_8009C6E4)->name, &D_8009C6E4[0x64 + c * 0x84]);
            ((SvHeader *)D_8009C6E4)->level = D_8009C738[c][1];
            ((SvHeader *)D_8009C6E4)->hp = D_8009D85C[i].hp;
            ((SvHeader *)D_8009C6E4)->maxhp = ((u16 *)&D_8009D85C[i])[1];
            ((SvHeader *)D_8009C6E4)->mp = D_8009D860[i].hp;
            ((SvHeader *)D_8009C6E4)->maxmp = ((u16 *)&D_8009D860[i])[1];
            break;
        }
    }
    for (i = 0; i < 12; i++) {
        D_8009C6E4[0x48 + i] = D_80049208[i];
    }
    *(u32 *)&D_8009C6E4[0x20] = D_8009D260[0];
    *(u32 *)&D_8009C6E4[0x24] = D_8009D264;
    func_801D21E0(0x18);
    func_801D21F0(&D_8009C6E4[0x28], &D_8009C6E4[0xF0C]);
}

s16 func_801D2408(char *arg0, s32 arg1) {
    u8 pad[0x200];
    s32 i;
    s32 j;
    s32 fd;
    s32 n;
    u8 t;
    u8 c;

    func_801D224C();
    D_801E8F40 = 0x2000;
    D_801E6D38[0] = 'S';
    D_801E6D38[1] = 'C';
    D_801E6D38[2] = 0x11;
    D_801E6D38[3] = 1;
    func_801D21B8(D_801E6D38 + 4, (u8 *)arg1);
    for (j = 0; j < 28; j++) {
        D_801E6D38[0x44 + j] = 0;
    }
    t = func_80023788(*(s32 *)&D_8009C6E4[0x24]);
    c = (u8)(t / 10) * 2 + 0x20;
    D_801E6D38[0x1A] = D_801DEF08[c];
    D_801E6D38[0x1B] = D_801DEF08[c + 1];
    c = (u8)(t % 10) * 2 + 0x20;
    D_801E6D38[0x1C] = D_801DEF08[c];
    D_801E6D38[0x1D] = D_801DEF08[c + 1];
    t = func_8002382C(*(s32 *)&D_8009C6E4[0x24]);
    c = (u8)(t / 10) * 2 + 0x20;
    D_801E6D38[0x20] = D_801DEF08[c];
    D_801E6D38[0x21] = D_801DEF08[c + 1];
    c = (u8)(t % 10) * 2 + 0x20;
    D_801E6D38[0x22] = D_801DEF08[c];
    D_801E6D38[0x23] = D_801DEF08[c + 1];
    *(SvClut *)(D_801E6D38 + 0x60) = *(SvClut *)(D_801DF120 + D_801E3D50 * 0x3F6);
    *(SvIcon *)(D_801E6D38 + 0x80) = *(SvIcon *)(D_801DF120 + D_801E3D50 * 0x3F6 + 0x2C);
    *(SvBlock *)D_801E6F38 = *(SvBlock *)D_801E6D38;
    D_80062D99 = 1;
    *(u32 *)D_8009C6E4 = func_801D1950(0x10F0, D_8009C6E4 + 4);
    *(SvSave *)D_801E7138 = *(SvSave *)D_8009C6E4;
    D_80062D99 = 0;
    for (i = 0; i < 10; i++) {
        fd = func_80042B20(arg0, 1);
        if (fd != -1) {
            func_80042B90(arg0);
            func_80042B50(fd);
            break;
        }
    }
    i = 30;
    do {
        fd = func_80042B20(arg0, (D_801E6D38[3] << 16) | 0x200);
        if (fd != -1) {
            goto created;
        }
    } while (--i != 0);
    return 1;
created:
    func_80042B50(fd);
    i = 30;
    do {
        fd = func_80042B20(arg0, 2);
        if (fd != -1) {
            goto opened;
        }
    } while (--i != 0);
    return 2;
opened:
    i = 30;
    do {
        n = func_80042B40(fd, D_801E6F38, D_801E8F40);
        if (n == D_801E8F40) {
            goto ok;
        }
        i--;
        if (n != -1) {
            D_801E8F40 -= n;
        }
    } while (i != 0);
    func_80042B50(fd);
    return 3;
ok:
    func_80042B50(fd);
    return 0;
}

s16 func_801D2A34(s32 arg0) {
    char path[0x40];
    s32 n;
    s16 ret;

    if (arg0 & 0x10) {
        func_80042DD8(path, D_801D018C, D_801E2C78[arg0 & 0xF]);
    } else {
        func_80042DD8(path, D_801D0194, D_801E2C78[arg0 & 0xF]);
    }
    n = arg0 & 0xF;
    D_801E3D50 = n;
    ret = func_801D2408(path, D_801E2CB8[n]);
    if (ret == 0) {
        *(SvHead *)D_801E3864[n] = *(SvHead *)D_8009C6E4;
    }
    return ret;
}

void func_801D2B58(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

s32 func_801D2B98(s32 arg0) {
    s16 rect[4];
    volatile SvPrim *p;
    volatile SvPrim *volatile *pp;

    pp = &D_80062F24;
    D_80062F24->len = 3;
    D_80062F24->code = 0x60;
    func_80046848(*pp, 1);
    D_80062F24->x = 0;
    D_80062F24->y = 0;
    D_80062F24->w = 0x180;
    D_80062F24->h = 0xE8;
    D_80062F24->r = D_801E2CF4;
    D_80062F24->g = D_801E2CF4;
    D_80062F24->b = D_801E2CF4;
    p = *pp; *(volatile SvPrim **)pp = p + 1; func_80046794(D_80062FC4, (s32)p);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x5F, (s32)rect);
    D_801E2CF4 += arg0;
    if (D_801E2CF4 < 0) {
        D_801E2CF4 = 0;
    }
    if (D_801E2CF4 >= 0x100) {
        D_801E2CF4 = 0xFF;
    }
    return D_801E2CF4;
}

void func_801D2D10(s32 arg0) {
    switch (arg0) {
    case 0:
        D_8009A000 = 0x81;
        D_8009A004 = 0x81;
        D_8009A008 = 0x81;
        break;
    case 1:
        D_8009A000 = 0x80;
        D_8009A004 = 0x80;
        D_8009A008 = 0x80;
        break;
    case 2:
        D_8009A000 = 0x82;
        D_8009A004 = 0x82;
        D_8009A008 = 0x82;
        break;
    }
    func_8002DA7C();
}

void func_801D2DA8(SvCursor *arg0) {
    SvCursor *p;

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
                        p->anim = -7;
                        p->state = 1;
                        func_801D2B58(1);
                    }
                } else {
                    func_801D2B58(1);
                }
                break;
            case 1:
            case 2:
                if (p->row < 0) {
                    p->row = p->nrows - 1;
                }
                func_801D2B58(1);
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
                        func_801D2B58(1);
                    }
                } else {
                    func_801D2B58(1);
                }
                break;
            case 1:
            case 2:
                if (p->row >= p->nrows) {
                    p->row = 0;
                }
                func_801D2B58(1);
                break;
            }
        } else if (D_80062D7E & 0x8000) {
            switch (p->hwrap) {
            case 0:
                if (--p->col < 0) {
                    p->col = 0;
                } else {
                    func_801D2B58(1);
                }
                break;
            case 1:
                if (--p->col < 0) {
                    p->col = p->ncols - 1;
                }
                func_801D2B58(1);
                break;
            case 2:
                if (p->col != 0 || p->row != 0 || p->top != 0) {
                    if (--p->col < 0) {
                        p->col = p->ncols - 1;
                        if (--p->row < 0) {
                            p->row = 0;
                            if (p->top > 0) {
                                p->top--;
                                p->anim = -7;
                                p->state = 1;
                            }
                        }
                    }
                    func_801D2B58(1);
                }
                break;
            }
        } else if (D_80062D7E & 0x2000) {
            switch (p->hwrap) {
            case 0:
                if (++p->col >= p->ncols) {
                    p->col = p->ncols - 1;
                } else {
                    func_801D2B58(1);
                }
                break;
            case 1:
                if (++p->col >= p->ncols) {
                    p->col = 0;
                }
                func_801D2B58(1);
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
                    func_801D2B58(1);
                }
                break;
            }
        } else if (D_80062D7E & 8) {
            p->top += p->nrows;
            if (p->count - p->nrows < p->top) {
                p->top = p->count - p->nrows;
            } else {
                func_801D2B58(1);
            }
        } else if (D_80062D7E & 4) {
            p->top -= p->nrows;
            if (p->top < 0) {
                p->top = 0;
            } else {
                func_801D2B58(1);
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
            if (--p->anim == -8) {
                p->state = 0;
                p->anim = 0;
                p->top++;
            }
            break;
        }
    }
}

void func_801D32C0(void) {
    func_80042A30(D_8009A024);
    func_80042A30(D_8009A028);
    func_80042A30(D_8009A02C);
    func_80042A30(D_8009A030);
}

void func_801D3318(void) {
    func_80042A30(D_8009A034);
    func_80042A30(D_8009A038);
    func_80042A30(D_8009A03C);
    func_80042A30(D_8009A040);
}

s32 func_801D3370(void) {
    s32 *p;
    s32 ret;

    p = &D_8009A024;
    while (1) {
        if (func_80042A30(p[0]) == 1) {
            ret = 0;
            break;
        }
        if (func_80042A30(p[1]) == 1) {
            ret = 1;
            break;
        }
        if (func_80042A30(p[2]) == 1) {
            ret = 2;
            break;
        }
        if (func_80042A30(p[3]) == 1) {
            ret = 3;
            break;
        }
    }
    return ret;
}

s32 func_801D33F4(void) {
    s32 *p;
    s32 ret;

    p = &D_8009A034;
    while (1) {
        if (func_80042A30(p[0]) == 1) {
            ret = 0;
            break;
        }
        if (func_80042A30(p[1]) == 1) {
            ret = 1;
            break;
        }
        if (func_80042A30(p[2]) == 1) {
            ret = 2;
            break;
        }
        if (func_80042A30(p[3]) == 1) {
            ret = 3;
            break;
        }
    }
    return ret;
}

s32 func_801D3478(s32 arg0) {
    s32 chan;

    chan = (arg0 != 0) << 4;
    func_80048968(chan);
    switch (func_801D3370()) {
    case 0:
        if (D_801E8F38[arg0].a != 0) {
            return;
        }
        D_801E8F38[arg0].a = 1;
        break;
    case 1:
        D_801E8F38[arg0].b = 1;
        return;
    case 2:
        D_801E8F38[arg0].a = 0;
        D_801E8F38[arg0].b = 0;
        D_801E8F38[arg0].c = 0;
        return;
    case 3:
        func_801D3318();
        func_80048998(chan);
        func_801D33F4();
        break;
    default:
        D_801E8F38[arg0].b = 1;
        return;
    }
    func_801D32C0();
    func_80048978(chan);
    switch (func_801D3370()) {
    case 0:
        D_801E8F38[arg0].c = 0;
        break;
    case 1:
        D_801E8F38[arg0].b = 1;
        break;
    case 2:
        D_801E8F38[arg0].a = 0;
        break;
    case 3:
        D_801E8F38[arg0].c = 1;
        break;
    default:
        D_801E8F38[arg0].b = 1;
        break;
    }
}

void func_801D3668(s32 arg0) {
    if (!(arg0 & 0x3F)) {
        func_801D3478(0);
        func_801D3478(1);
    }
}

s32 func_801D3698(s32 arg0, s32 arg1) {
    s32 var_a0;
    s32 var_s0;
    s32 var_v1;

    var_s0 = 0;
loop_1:
    var_a0 = arg1;
    if (arg0 != 0) {
        var_a0 |= 0x10;
    }
    if (func_801D1D40(var_a0) == 0) {
        var_v1 = 0;
    } else {
        var_s0 += 1;
        var_v1 = 1;
        if (var_s0 < 0x14) {
            goto loop_1;
        }
    }
    return var_v1;
}

void func_801D370C(s32 arg0, s32 y, s32 slot) {
    s16 win[4];
    s16 rect[4];
    SvHeader *h;
    s32 i;
    s32 j;
    s32 x;
    u8 c;

    h = (SvHeader *)func_801D1D1C(slot);
    func_80026F44(0xC0, y + 0x2E, h->place, 7);
    for (i = 0; i < 3; i++) {
        c = h->party[i];
        if (c != 0xFF) {
            func_8001D180(i * 0x34 + 0x16, y + 6, 0x30, 0x30, c < 5 ? 0 : 0x30, (u8)(h->party[i] % 5) * 0x30, 0x30, 0x30, h->party[i], 0);
        }
    }
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x7F, (s32)rect);
    func_80028E00(func_80026B70(D_801E3684) + 0xC2, y + 0x1C, h->level, 2, 7);
    ((void (*)(s32, s32, s32, s32))func_8002708C)(0x152, y + 0xC, 0xD5, 7);
    func_80029114(0x144, y + 0xB, func_80023788(h->time), 2, 7);
    func_80029114(0x159, y + 0xB, func_8002382C(h->time), 2, 7);
    func_80028E00(0x135, y + 0x19, h->gil, 7, 7);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0x100;
    rect[3] = 0x100;
    func_80026A34(0, 1, 0x7F, (s32)rect);
    func_80026F44(0xBD, y + 0x1A, D_801E3684, 5);
    func_80026F44(0xB8, y + 8, h->name, 7);
    func_80026F44(0x11C, y + 9, D_800492F0, 7);
    func_80026F44(0x11C, y + 0x17, D_800492F0 + 0xC, 7);
    func_8001DEF0(h->colors);
    for (j = 0; j < 3; j++) {
        func_8001DE40(win, D_801E3650[j]);
        func_8001DE24(win, 0, y);
        func_8001E040(win);
    }
}

void func_801D39C4(void) {
    D_801E3698 = 0;
    D_801E2CF8 = 7;
    func_8001DEF0(&D_801E368C);
    func_80025D14(&D_801D4EDC, 0x380, 0, 0, 0x1E0);
    func_80043DD8(0);
    func_80026448(&D_801E3DFE, 0, 1, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0U);
    func_80025CD4((s32) &D_801E3F2C);
    func_80025B8C((s32) &D_801E8F44);
    func_80025C14((s32) &D_801E4538);
    func_80025DF8();
    func_801D19C4();
}

INCLUDE_RODATA("../asm/us/savemenu/nonmatchings/text", D_801D018C);

INCLUDE_RODATA("../asm/us/savemenu/nonmatchings/text", D_801D0194);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D3AB0);

void func_801D4C38(void) {
    func_80025ED4();
    func_80025CD4((s32)D_800756F8);
    func_80025C94(&D_801E3F2C);
    func_80025BD0(&D_801E8F44);
    func_80025C54(&D_801E4538);
    func_801D1BA4();
    func_800444AC(D_801E3EEC);
    func_800443B0(D_801E3E34);
}

s32 func_801D4CC0(void) {
    s32 i;
    s32 ret;

    func_80021044(D_801E3E34, D_801E3EEC);
    D_801E3D54 = 0;
    i = 0;
    func_801D39C4();
    D_801E3D58 = 0;
    while (1) {
        func_8001CB48();
        func_800269C0((s32)(D_80077F64 + D_801E3D58 * 0x3400));
        D_801E3D5C = D_801E3D60 + D_801E3D58 * 0x10;
        func_8004418C(D_801E3D5C, 1);
        func_80026A00((s32)D_801E3D5C);
        func_8001F710();
        ret = func_801D3AB0(i);
        if (D_801E3D54 == -1) {
            break;
        }
        func_80043DD8(0);
        func_8003CEDC(0);
        func_800444AC((void *)((u8 *)D_801E3EEC + D_801E3D58 * 0x14));
        func_800443B0((void *)((u8 *)D_801E3E34 + D_801E3D58 * 0x5C));
        i++;
        func_8004433C((s32)D_801E3D5C);
        D_801E3D58 ^= 1;
    }
    i = 0;
    func_801D4C38();
    func_8003CEDC(0);
    func_800444AC((void *)((u8 *)D_801E3EEC + 0x14));
    func_800443B0((void *)((u8 *)D_801E3E34 + 0x5C));
    do {
        if (D_8009CBDC[i] != 0xFF) {
            func_80020058(i);
            func_8001786C(i & 0xFF);
        }
        i++;
    } while (i < 3);
    func_80017678();
    return ret;
}
