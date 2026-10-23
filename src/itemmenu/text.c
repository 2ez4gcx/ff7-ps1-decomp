#include "common.h"
#include "itemmenu/decls.h"

void func_801D01E8(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_801D0228(s16 arg0, s16 arg1, s32 arg2) {
    u32 t;
    s32 u;
    s32 v;

    if (arg2 < 0x80) {
        t = 0;
    } else if (arg2 < 0x100) {
        arg2 -= 0x80;
        if (arg2 < 0x10) {
            t = 1;
        } else if (arg2 < 0x20) {
            t = 3;
        } else if (arg2 < 0x30) {
            t = 2;
        } else if (arg2 < 0x3E) {
            t = 5;
        } else if (arg2 < 0x49) {
            t = 4;
        } else if (arg2 < 0x57) {
            t = 9;
        } else if (arg2 < 0x65) {
            t = 6;
        } else if (arg2 < 0x72) {
            t = 7;
        } else {
            t = 8;
        }
    } else if (arg2 < 0x120) {
        t = 0xA;
    } else {
        t = 0xB;
    }
    u = (t & 1) * 0x10 | 0x60;
    v = (t >> 1) * 0x10 + 0x70;
    func_80028CA0(arg0, arg1, u, v, 0x10, 0x10, 1, 0);
}

void func_801D031C(void) {
    s32 i;
    s32 n;
    u8 *p;

    i = 0;
    n = 0;
    p = D_801D3D90;
    for (; i < 0x40; i++) {
        if ((D_8009D2C8[i / 8] >> (i & 7)) & 1) {
            *p++ = i;
            n++;
        }
    }
    for (; n < 0x40; n++) {
        D_801D3D90[n] = 0xFF;
    }
}

void func_801D03B4(s32 *arg0, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}

s32 func_801D03C8(void *base, u32 n, s32 (*cmp)(), void (*swap)()) {
    u32 lo[64];
    u32 hi[64];
    u32 r;
    u32 l;
    u32 i;
    u32 sp;

    if (n < 2) {
        return 1;
    }
    if (0) {
    overflow:
        return 0;
    }
    sp = 0;
    lo[0] = 0;
    hi[0] = n - 1;
    do {
        l = lo[sp];
        i = l + 1;
        n = r = hi[sp];
        while (i < r) {
            while (i < r && cmp(i, l, &base) <= 0) {
                i++;
            }
            while (i <= r && cmp(l, r, &base) <= 0) {
                r--;
            }
            if (i < r) {
                swap(i++, r--, &base);
            }
        }
        if (cmp(l, r, &base) > 0) {
            swap(l, r, &base);
        }
        if (l < r && l < --r) {
            if (i < n && r - l < n - i) {
                func_801D03B4(&r, &n);
                func_801D03B4(&l, &i);
            }
            if (r > l) {
                lo[sp] = l;
                hi[sp] = r;
                sp++;
            }
        }
        if (n > i) {
            lo[sp] = i;
            hi[sp] = n;
            sp++;
        }
        if (sp >= 0x40) {
            goto overflow;
        }
    } while (sp-- != 0);
    return 1;
}

void func_801D0618(u16 *arg0, u16 *arg1) {
    u16 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}

s32 func_801D062C(s32 arg0) {
    s32 var_v0;

    if (arg0 != 0) {
        var_v0 = 1;
        if (arg0 < 0) {
            return -1;
        }
        
        return var_v0;
    }
    var_v0 = 0;
    return var_v0;
}

s32 func_801D0650(s16 arg0, s16 arg1, u16 **arg2) {
    return func_801D062C(((*arg2)[arg0] & 0x1FF) - ((*arg2)[arg1] & 0x1FF));
}

s32 func_801D069C(s16 arg0, s16 arg1, u16 **arg2) {
    s16 a;
    s16 b;

    if ((*arg2)[arg0] == 0xFFFF) {
        a = 0;
    } else {
        a = (*arg2)[arg0] >> 9;
    }
    if ((*arg2)[arg1] == 0xFFFF) {
        b = 0;
    } else {
        b = (*arg2)[arg1] >> 9;
    }
    b -= a;
    return func_801D062C(b);
}

s32 func_801D0704(s16 arg0, s16 arg1, u16 **arg2) {
    s16 a;
    s16 b;

    if ((*arg2)[arg0] == 0xFFFF) {
        a = 20000;
    } else {
        a = (*arg2)[arg0] >> 9;
    }
    if ((*arg2)[arg1] == 0xFFFF) {
        b = 20000;
    } else {
        b = (*arg2)[arg1] >> 9;
    }
    return func_801D062C(a - b);
}

s32 func_801D076C(s16 arg0, s16 arg1, u16 **arg2) {
    s16 a;
    s16 b;

    if ((*arg2)[arg0] == 0xFFFF) {
        a = 20000;
    } else {
        a = D_801D35B4[(*arg2)[arg0] & 0x1FF];
    }
    if ((*arg2)[arg1] == 0xFFFF) {
        b = 20000;
    } else {
        b = D_801D35B4[(*arg2)[arg1] & 0x1FF];
    }
    return func_801D062C(a - b);
}

s32 func_801D081C(s16 arg0, s16 arg1, u16 **arg2) {
    s32 a;
    s32 b;

    if ((*arg2)[arg0] == 0xFFFF) {
        a = 0;
    } else if (func_8001FAF8((*arg2)[arg0] & 0x1FF) & 4) {
        a = 1;
    } else {
        a = 2;
    }
    if ((*arg2)[arg1] == 0xFFFF) {
        b = 0;
    } else if (func_8001FAF8((*arg2)[arg1] & 0x1FF) & 4) {
        b = 1;
    } else {
        b = 2;
    }
    return func_801D062C(b - a);
}

s32 func_801D08E4(s16 arg0, s16 arg1, u16 **arg2) {
    s32 a;
    s32 b;

    if ((*arg2)[arg0] == 0xFFFF) {
        a = 0;
    } else if (func_8001FAF8((*arg2)[arg0] & 0x1FF) & 2) {
        a = 1;
    } else {
        a = 2;
    }
    if ((*arg2)[arg1] == 0xFFFF) {
        b = 0;
    } else if (func_8001FAF8((*arg2)[arg1] & 0x1FF) & 2) {
        b = 1;
    } else {
        b = 2;
    }
    return func_801D062C(b - a);
}

s32 func_801D09AC(s16 arg0, s16 arg1, u16 **arg2) {
    s32 a;
    s32 b;

    if ((*arg2)[arg0] == 0xFFFF) {
        a = 0;
    } else if (func_8001FAF8((*arg2)[arg0] & 0x1FF) & 8) {
        a = 1;
    } else {
        a = 2;
    }
    if ((*arg2)[arg1] == 0xFFFF) {
        b = 0;
    } else if (func_8001FAF8((*arg2)[arg1] & 0x1FF) & 8) {
        b = 1;
    } else {
        b = 2;
    }
    return func_801D062C(b - a);
}

void func_801D0A74(s16 arg0, s16 arg1, u16 **arg2) {
    func_801D0618(*arg2 + arg0, *arg2 + arg1);
}

void func_801D0AAC(u32 arg0) {
    switch (arg0) {
    case 0:
        break;
    case 1:
        func_801D03C8(D_8009CBE0, 0x140, func_801D081C, func_801D0A74);
        break;
    case 2:
        func_801D03C8(D_8009CBE0, 0x140, func_801D08E4, func_801D0A74);
        break;
    case 3:
        func_801D03C8(D_8009CBE0, 0x140, func_801D09AC, func_801D0A74);
        break;
    case 4:
        func_801D03C8(D_8009CBE0, 0x140, func_801D0650, func_801D0A74);
        break;
    case 5:
        func_801D03C8(D_8009CBE0, 0x140, func_801D076C, func_801D0A74);
        break;
    case 6:
        func_801D03C8(D_8009CBE0, 0x140, func_801D069C, func_801D0A74);
        break;
    case 7:
        func_801D03C8(D_8009CBE0, 0x140, func_801D0704, func_801D0A74);
        break;
    }
}

void func_801D0BA0(void) {
    D_801D3E48 = 1;
    func_80026448(D_801D3DDC, 0, 0, 3, 1, 0, 0, 3, 1, 0, 0, 1, 0, 0);
    func_80026448(D_801D3DDC + 0x12, 0, 0, 1, 0xA, 0, 0, 1, 0x140, 0, 0, 0, 0, 0);
    func_80026448(D_801D3DDC + 0x24, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0);
    func_801D031C();
}

s32 func_801D0CAC(s32 arg0) {
    return *(s16 *)((u8 *)&D_8009D85E + arg0 * 0x440) == D_8009D85C[arg0].hp;
}

s32 func_801D0CE8(s32 arg0) {
    return *(s16 *)((u8 *)&D_8009D862 + arg0 * 0x440) == D_8009D860[arg0].hp;
}

s32 func_801D0D24(s32 arg0) {
    s32 i;
    s32 m;

    i = 0;
    m = 0;
    for (; i < 10; i++) {
        if (func_80015AFC(arg0, i) != 0x7F) {
            m |= 1 << i;
        }
    }
    m &= ~0x200;
    return D_8009C75A[arg0].v == m;
}

s32 func_801D0DCC(s32 arg0) {
    s32 v;

    v = ((s32 (*)(s32))func_8001FAF8)(arg0);
    switch (arg0) {
    case 0x62:
        if (!(D_8009D5E8 & 2)) {
            v |= 4;
        }
        break;
    case 0x46:
        if (D_80062F50 & 0x200) {
            v |= 4;
        }
        break;
    }
    return v;
}

void func_801D0E4C(u8 *arg0) {
    s32 i;

    for (i = 0; i < 0x50; i++) {
        D_801D3E60[i] = *arg0++;
    }
}

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D0E80);

void func_801D296C(void) {
}

void func_801D2974(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 0x30; i++) {
        if (D_801D3834[*(u8 *)&D_801D3F60[i]] == arg1) {
            D_801D3F60[i] = arg0;
            return;
        }
    }
}

s32 func_801D29C4(void) {
    s32 i;
    s32 min;
    s32 v;

    min = 0xFF;
    for (i = 0; i < 0x30; i++) {
        v = D_801D3834[*(u8 *)&D_801D3F60[i]];
        if (v < min) {
            min = v;
        }
    }
    return min;
}

void func_801D2A18(s32 *arg0) {
    s32 i;
    s32 min;

    if (*arg0 == -1) {
        return;
    }
    for (i = 0; i < 0x30; i++) {
        if (D_801D3F60[i] == -1) {
            D_801D3F60[i] = *arg0;
            return;
        }
    }
    min = func_801D29C4();
    if (D_801D3834[*arg0 & 0xFF] >= min) {
        func_801D2974(*arg0, min);
    }
}

s32 func_801D2ABC(s32 arg0) {
    s32 i;
    s32 j;
    s32 k;

    for (i = 8; i != -1; i--) {
        if ((D_8009D78A[0] >> i) & 1) {
            for (j = 0; j < 8; j++) {
                if (D_8009C778[i].wm[j] == -1 && D_800738BC[D_8009C754[i][0]][j] != 0) {
                    D_8009C778[i].wm[j] = arg0;
                    return 0;
                }
            }
            for (k = 0; k < 8; k++) {
                if (D_8009C778[i].am[k] == -1 && D_80071E48[D_8009C754[i][1]].slot[k] != 0) {
                    D_8009C778[i].am[k] = arg0;
                    return 0;
                }
            }
        }
    }
    return 1;
}

void func_801D2C00(s32 arg0) {
    s32 i;
    s32 j;
    s32 (*w)[0x21];
    s32 (*a)[0x21];
    u16 *fp;

    i = 0;
    fp = D_8009D78A;
    w = (s32 (*)[0x21])((u8 *)D_8009D78A - 0x1012);
    a = (s32 (*)[0x21])((u8 *)D_8009D78A - 0xFF2);
    for (; i < 9; i++) {
        if ((*fp >> i) & 1) {
            for (j = 0; j < 8; j++) {
                if (w[i][j] == arg0) {
                    w[i][j] = -1;
                    return;
                }
            }
            for (j = 0; j < 8; j++) {
                if (a[i][j] == arg0) {
                    a[i][j] = -1;
                    return;
                }
            }
        }
    }
    for (j = 0; j < 200; j++) {
        if (D_8009CE60[j] == arg0) {
            D_8009CE60[j] = -1;
            return;
        }
    }
}

void func_801D2CDC(void) {
    s32 i;

    for (i = 0; i < 0x30; i++) {
        if (D_801D3F60[i] != -1) {
            func_801D2C00(D_801D3F60[i]);
        }
    }
    for (i = 0; i < 0x30; i++) {
        D_8009D180[i] = D_801D3F60[i];
    }
}

s32 func_801D2D74(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    for (l = 0; l < 0x30; l++) {
        D_801D3F60[l] = -1;
    }
    for (i = 0; i < 9; i++) {
        if ((D_8009D78A[0] >> i) & 1) {
            for (j = 0; j < 8; j++) {
                func_801D2A18(&((ItmChr *)D_8009C738)[i].wm[j]);
            }
            for (k = 0; k < 8; k++) {
                func_801D2A18(&((ItmChr *)D_8009C738)[i].am[k]);
            }
        }
    }
    for (j = 0; j < 200; j++) {
        func_801D2A18(&D_8009CE60[j]);
    }
    func_801D2CDC();
}

s32 func_801D2E84(void) {
    s32 i;

    for (i = 0; i < 0x30; i++) {
        if (D_8009D180[i] != -1 && func_801D2ABC(D_8009D180[i]) != 0) {
            func_8002542C(D_8009D180[i]);
        }
    }
}

s32 func_801D2F00(s32 arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (D_8009C778[arg0].wm[i] != -1) {
            func_8002542C(D_8009C778[arg0].wm[i]);
            D_8009C778[arg0].wm[i] = -1;
        }
    }
    for (i = 0; i < 8; i++) {
        if (D_8009C798[arg0].m[i] != -1) {
            func_8002542C(D_8009C798[arg0].m[i]);
            D_8009C798[arg0].m[i] = -1;
        }
    }
    if (D_8009C754[arg0][2] != 0xFF) {
        ((void (*)(s32))func_80025380)((D_8009C754[arg0][2] + 0x120) | 0x200);
        D_8009C754[arg0][2] = 0xFF;
    }
}

s32 func_801D3018(s32 arg0) {
    s32 i;
    ItmSave *p;

    p = (ItmSave *)D_8009D180;
    for (i = 0; i < 3; i++) {
        p->party[i] = D_8009CBDC[i];
    }
    p->wpn = D_8009C754[arg0][0];
    p->arm = D_8009C754[arg0][1];
    for (i = 0; i < 3; i++) {
        p->m[i] = D_8009CE60[i];
        D_8009CE60[i] = -1;
    }
    for (i = 0; i < 8; i++) {
        p->wm[i] = D_8009C778[arg0].wm[i];
        D_8009C778[arg0].wm[i] = -1;
        p->am[i] = D_8009C778[arg0].am[i];
        D_8009C778[arg0].am[i] = -1;
    }
    D_8009C754[arg0][0] = 0;
}

s32 func_801D3138(s32 arg0) {
    s32 i;
    ItmSave *p;

    p = (ItmSave *)D_8009D180;
    for (i = 0; i < 3; i++) {
        D_8009CBDC[i] = p->party[i];
    }
    D_8009C754[arg0][0] = p->wpn;
    D_8009C754[arg0][1] = p->arm;
    for (i = 0; i < 3; i++) {
        D_8009CE60[i] = p->m[i];
    }
    for (i = 0; i < 8; i++) {
        D_8009C778[arg0].wm[i] = p->wm[i];
        D_8009C778[arg0].am[i] = p->am[i];
    }
}

s32 func_801D3228(void) {
    func_80025D14(D_801D3890, 0x3F0, 0x120, 0x110, 0x1E0);
}
