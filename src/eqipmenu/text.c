#include "common.h"
#include "eqipmenu/decls.h"

void func_801D0124(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_801D0164(void) {
    func_8001F6AC();
}

void func_801D0184(s32 x, s32 y, u8 *slots) {
    s16 rect[4];
    s32 i;

    for (i = 0; i < 8; i++) {
        if (slots[i] != 0) {
            switch (slots[i]) {
            case 3:
            case 7:
                func_80028CA0((s16)(x + i * 0x10 - 8), (s16)y, 0x70, 0x30, 0x10, 0x10, 1, 0);
                break;
            }
        }
    }
    for (i = 0; i < 8; i++) {
        if (slots[i] != 0) {
            if (slots[i] >= 5) {
                func_80028CA0((s16)(x + i * 0x10), (s16)y, 0x80, 0x30, 0x10, 0x10, 1, 0);
            } else {
                func_80028CA0((s16)(x + i * 0x10), (s16)y, 0x70, 0x20, 0x10, 0x10, 1, 0);
            }
        }
    }
    rect[0] = x - 2;
    rect[2] = 0x80;
    rect[1] = y;
    rect[3] = 0xB;
    func_80027B84(rect);
    func_80026A34(0, 1, 0x1F, 0);
}

void func_801D0314(s32 arg0) {
    s32 n;
    s32 i;
    s32 id;
    u16 v;

    switch (arg0) {
    case 0:
        i = 0;
        n = 0;
        for (; i < 0x140; i++) {
            v = D_8009CBE0[i];
            if (v != 0xFFFF) {
                id = v & 0x1FF;
                if (id >= 0x80 && id < 0x100) {
                    id -= 0x80;
                    if ((D_800738AE[id][0] >> ((u8 *)D_8009CBE0 - 4)[D_801D8AE8]) & 1) {
                        D_801D88F8[n++] = id;
                    }
                }
            }
        }
        break;
    case 1:
        i = 0;
        n = 0;
        for (; i < 0x140; i++) {
            v = D_8009CBE0[i];
            if (v != 0xFFFF) {
                id = v & 0x1FF;
                if (id >= 0x100 && id < 0x120) {
                    id -= 0x100;
                    if ((D_80071E56[id][0] >> ((u8 *)D_8009CBE0 - 4)[D_801D8AE8]) & 1) {
                        D_801D88F8[n++] = id;
                    }
                }
            }
        }
        break;
    case 2:
        i = 0;
        n = 0;
        for (; i < 0x140; i++) {
            v = D_8009CBE0[i];
            if (v != 0xFFFF) {
                id = v & 0x1FF;
                if (id >= 0x120 && id < 0x160) {
                    id -= 0x120;
                    if ((D_80071C30[id][0] >> ((u8 *)D_8009CBE0 - 4)[D_801D8AE8]) & 1) {
                        D_801D88F8[n++] = id;
                    }
                }
            }
        }
        break;
    }
    D_801D8B04 = n;
    for (; n < 0x30; n++) {
        D_801D88F8[n] = 0xFF;
    }
}

void func_801D0574(void) {
    D_801D8AEC = 0;
    D_801D8AF0 = 0;
    D_801D8AE8 = D_80062F6C;
    func_80026448(D_801D8AA0, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0);
    func_80026448(D_801D8AA0 + 0x12, 0, 0, 1, 8, 0, 0, 1, 0x10, 0, 0, 0, 0, 0);
}

void func_801D064C(void) {
}

void func_801D0654(s32 arg0, s32 arg1) {
    s32 i;
    s32 slot;
    s32 ch;
    s32 col;
    s32 oa;
    s32 ob;
    s32 oc;
    s32 od;
    s32 oe;
    s32 of;
    s32 og;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;

    slot = D_8009CBDC[D_801D8AE8];
    for (i = 0; i < 7; i++) {
        func_80026F44(arg0, arg1 + i * 0xC - 3, D_801D831C[i], 5);
    }
    for (i = 0; i < 7; i++) {
        ((void (*)(s32, s32, s32, s32))func_8002708C)(arg0 + 0x74, arg1 + i * 0xC, 0xDA, 5);
    }
    ch = D_800491D0[slot];
    a = D_800738A4[D_8009C754[ch][0]][0];
    b = D_800738A8[D_8009C754[ch][0]][0];
    c = D_80071E46[D_8009C754[ch][1]].v;
    d = D_80071E48[D_8009C754[ch][1]][0];
    e = 0;
    f = D_80071E47[D_8009C754[ch][1]][0];
    g = D_80071E49[D_8009C754[ch][1]][0];
    og = g;
    oa = a;
    ob = b;
    oc = c;
    od = d;
    oe = e;
    of = f;
    func_80028E00(arg0 + 0x58, arg1, a, 3, 7);
    func_80028E00(arg0 + 0x58, arg1 + 0xC, b, 3, 7);
    func_80028E00(arg0 + 0x58, arg1 + 0x18, c, 3, 7);
    func_80028E00(arg0 + 0x58, arg1 + 0x24, d, 3, 7);
    func_80028E00(arg0 + 0x58, arg1 + 0x30, e, 3, 7);
    func_80028E00(arg0 + 0x58, arg1 + 0x3C, f, 3, 7);
    func_80028E00(arg0 + 0x58, arg1 + 0x48, g, 3, 7);
    if (D_801D8AEC != 0) {
        if (D_801D8AAB != 2) {
            switch (D_801D8AAB) {
            case 0:
                a = D_800738A4[D_801D88F8[D_801D8ABD + D_801D8AB4]][0];
                b = D_800738A8[D_801D88F8[D_801D8ABD + D_801D8AB4]][0];
                break;
            case 1:
                c = D_80071E46[D_801D88F8[D_801D8ABD + D_801D8AB4]].v;
                d = D_80071E48[D_801D88F8[D_801D8ABD + D_801D8AB4]][0];
                f = D_80071E47[D_801D88F8[D_801D8ABD + D_801D8AB4]][0];
                g = D_80071E49[D_801D88F8[D_801D8ABD + D_801D8AB4]][0];
                break;
            }
        }
        if (oa < a) {
            col = 6;
        } else {
            col = 7;
            if (a < oa) {
                col = 2;
            }
        }
        func_80028E00(arg0 + 0x82, arg1, a, 3, col);
        if (ob < b) {
            col = 6;
        } else {
            col = 7;
            if (b < ob) {
                col = 2;
            }
        }
        func_80028E00(arg0 + 0x82, arg1 + 0xC, b, 3, col);
        if (oc < c) {
            col = 6;
        } else {
            col = 7;
            if (c < oc) {
                col = 2;
            }
        }
        func_80028E00(arg0 + 0x82, arg1 + 0x18, c, 3, col);
        if (od < d) {
            col = 6;
        } else {
            col = 7;
            if (d < od) {
                col = 2;
            }
        }
        func_80028E00(arg0 + 0x82, arg1 + 0x24, d, 3, col);
        if (oe < e) {
            col = 6;
        } else {
            col = 7;
            if (e < oe) {
                col = 2;
            }
        }
        func_80028E00(arg0 + 0x82, arg1 + 0x30, e, 3, col);
        if (of < f) {
            col = 6;
        } else {
            col = 7;
            if (f < of) {
                col = 2;
            }
        }
        func_80028E00(arg0 + 0x82, arg1 + 0x3C, f, 3, col);
        if (og < g) {
            col = 6;
        } else {
            col = 7;
            if (g < og) {
                col = 2;
            }
        }
        func_80028E00(arg0 + 0x82, arg1 + 0x48, g, 3, col);
    }
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D0BD0);

void func_801D1B8C(void) {
}

void func_801D1B94(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

u32 func_801D1BD4(u32 arg0) {
    return arg0 >> 0x1F;
}

s32 func_801D1BDC(s32 arg0) {
    s32 var_v0;

    var_v0 = arg0;
    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }
    return var_v0;
}

void func_801D1BF4(void) {
    s32 i;
    s32 n;
    s32 color;

    n = 0;
    for (i = 0; i < 8; i++) {
        if (D_801D8B08->v[i] != 0) {
            if (func_801D1BD4(D_801D8B08->v[i]) != 0) {
                ((void (*)(s32, s32, s32, s32))func_8002708C)(0xB4, n * 0xB + 0x9A, 0xE1, 7);
                color = 2;
            } else {
                ((void (*)(s32, s32, s32, s32))func_8002708C)(0xB4, n * 0xB + 0x9A, 0xB3, 7);
                color = 6;
            }
            func_80029114(0xBC, n * 0xB + 0x9A, func_801D1BDC(D_801D8B08->v[i]), 2, color);
            func_80026A34(0, 1, 0x1F, 0);
            func_80026F44(0x78, n * 0xB + 0x98, D_801D8674[i], 7);
            if (i >= 6) {
                ((void (*)(s32, s32, s32, s32))func_8002708C)(0xCA, n * 0xB + 0x9A, 0xD3, 7);
            }
            n++;
        }
    }
    func_80026A34(0, 1, 0x1F, 0);
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D1D5C);

void func_801D26A4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *base;
    u8 *p;
    u8 *e;
    s32 c;
    s32 y;

    arg0 += 0xC;
    func_80028CA0((s16)(arg0 + 3), (s16)arg1, 0, 0x10, 0x28, 0x10, 1, 0);
    switch (arg4) {
    case 0:
        base = D_8009D954 + arg3 * 0x440;
        e = (u8 *)(arg2 * 8 + (s32)base);
        if (e[0] == 0xFF) {
            goto done;
        }
        if (e[2] != 0) {
            func_80026A34(0, 1, 0x3F, 0);
            func_80026F44(arg0 - 5, arg1 + 0x27, func_80015248(5, 0xE, 8), 7);
        }
        break;
    case 1:
        base = (u8 *)D_8009DB14[arg3];
        break;
    case 2:
        base = (u8 *)D_8009DB94[arg3];
        break;
    }
    p = (u8 *)(arg2 * 8 + (s32)base);
    if (p[0] == 0xFF) {
        goto done;
    }
    if (arg4 != 2) {
        if (p[4] != 0) {
            func_80026A34(0, 1, 0x3F, 0);
            func_80026F44(arg0 - 5, arg1 + 0x1C, func_80015248(5, 0xF, 8), 7);
            c = p[4];
            if (c != 0xFF) {
                func_80028E00(arg0 + 0x13, arg1 + 0x1E, c, 2, 7, 0);
            } else {
                func_80028CA0((s16)(arg0 + 0x13), (s16)(arg1 + 0x1E), 0x90, 0x60, 0x10, 8, 6, 0);
            }
            func_80028CA0((s16)(arg0 + 0x23), (s16)(arg1 + 0x1E), 0x78, 8, 8, 8, 7, 0);
        }
        c = (base + arg2 * 8)[2];
        if (c != 0) {
            if (c != 0xFF) {
                func_80028E00(arg0 + 0x13, arg1 + 0x2A, c, 2, 7, 0);
            } else {
                func_80028CA0((s16)(arg0 + 0x13), (s16)(arg1 + 0x2A), 0x90, 0x60, 0x10, 8, 6, 0);
            }
            func_80028CA0((s16)(arg0 + 0x23), (s16)(arg1 + 0x2A), 0x78, 8, 8, 8, 7, 0);
        }
    }
    func_80028E00(arg0, arg1 + 0x12, (base + arg2 * 8)[1], 3, 7);
done:
    y = arg1 + 0x12;
    func_80028E00(arg0 + 0x19, y, D_8009D860[arg3].hp, 3, 7);
    func_80028CA0((s16)(arg0 + 0x15), (s16)y, 0xD8, 0, 4, 8, 1, 0);
}

void func_801D2A80(s32 *arg0, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}

s32 func_801D2A94(void *base, u32 n, s32 (*cmp)(), void (*swap)()) {
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
                func_801D2A80(&r, &n);
                func_801D2A80(&l, &i);
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

void func_801D2CE4(s32 *arg0, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}

s32 func_801D2CF8(u8 arg0, u8 arg1, u32 arg2, u32 arg3) {
    if (arg0 == arg1) {
        if (arg2 == arg3) {
            return 0;
        }
        if (arg3 < arg2) {
            return -1;
        }
        return 1;
    }
    if (arg1 < arg0) {
        return 1;
    }
    return -1;
}

s16 func_801D2D40(u16 arg0, u16 arg1, u32 **arg2) {
    s32 ca;
    s32 cb;
    u32 ka;
    u32 kb;

    if ((*arg2)[arg0] == -1) {
        ca = 0x80;
        ka = 0;
    } else {
        ca = ((s32 (*)(u32))func_8002603C)((*arg2)[arg0]);
        ka = ((*arg2)[arg0] >> 8) + ((*arg2)[arg0] << 24);
    }
    if ((*arg2)[arg1] == -1) {
        cb = 0x80;
        kb = 0;
    } else {
        cb = ((s32 (*)(u32))func_8002603C)((*arg2)[arg1]);
        kb = ((*arg2)[arg1] >> 8) + ((*arg2)[arg1] << 24);
    }
    return func_801D2CF8(ca, cb, ka, kb);
}

void func_801D2E40(u16 arg0, u16 arg1, s32 **arg2) {
    func_801D2CE4(*arg2 + arg0, *arg2 + arg1);
}

void func_801D2E78(s32 arg0) {
    if (arg0 == 0) {
        func_801D2A94(D_8009CE60, 0xC8, &func_801D2D40, &func_801D2E40);
    }
}

void func_801D2EB4(void) {
}

s32 func_801D2EBC(s32 arg0, s32 arg1) {
    s32 ret;

    switch (arg0) {
    case 1:
        ret = func_80015248(0xD, arg1, 0);
        break;
    case 0:
        ret = func_80015248(5, arg1, 0);
        break;
    }
    return ret;
}

void func_801D2EFC(void) {
    s32 pad[2];
    Rect8 rect;
    u8 *rec;
    s32 rows;
    s32 i;
    s32 j;
    s32 dx;
    s32 x;
    u8 m;

    rec = D_8009D84C[D_801DF6B0];
    rows = rec[0x21];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < 4; j++) {
            m = ((Obj4C *)rec)->e[j + i * 4].a;
            if (m != 0xFF) {
                dx = (rows >= 2 && i > 0) ? 8 : 0;
                x = i * 0x2C + 6;
                func_80026F44(D_801D8834 + x + dx, D_801D8836 + j * 0xC + 5, func_80015248(5, m, 8), 7);
            }
        }
    }
    func_8001DE0C(&rect, D_801D8834, D_801D8836, D_801D884A[rows], D_801D883A);
    func_8001E040(&rect);
}

void func_801D3074(arg0) {
    s16 rect[4];
    Rect8 rect2;
    MainBox box;
    u8 *e;
    s32 i;
    s32 j;
    s32 n;
    s32 start;
    u8 *rec;
    s32 f;
    s32 id;
    s32 t;
    s32 u;

    rect[1] = 5;
    rect[2] = 0x16C;
    rect[3] = 0xDB;
    rect[0] = 0;
    func_80026A94((s16 *)D_800706A4[D_80062F58], (u16 *)rect);
    box.f0 = 3;
    box.f2 = 0x12;
    box.w = 0xA;
    box.h = 0x32;
    box.f4 = (u16)D_801DF5EC[0];
    box.x = (u16)D_801D883C.x + 0xEE;
    box.y = (u16)D_801D883C.y + 3;
    func_80028484(&box);
    n = 4;
    rec = D_8009D954 + D_801DF6B0 * 0x440;
    if (D_801DF5F2 == 0) {
        n = 3;
    }
    start = D_801DF5EC[0] * 3;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            id = rec[(i * 3 + j + start) * 8];
            t = j * 0x4E + 0x18;
            u = i * 0x10 + 6;
            if (id != 0xFF) {
                func_80026F44(D_801D883C.x + t - 3, D_801D883C.y + u + D_801DF5F9 * 4, func_80015248(0, id, 8), 7);
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            e = (u8 *)((i * 3 + (j + start)) * 8 + (s32)rec);
            if (e[0] != 0xFF) {
                if (e[2] != 0 || e[4] != 0) {
                    if ((e[5] & 0xC) == 0xC) {
                        f = 1;
                        goto done;
                    }
                }
                f = 0;
            done:
                if (f != 0) {
                    t = j * 0x4E + 0x44;
                    u = i * 0x10 + 8;
                    func_80028CA0((s16)((u16)D_801D883C.x + t + 5), (s16)((u16)D_801D883C.y + u + D_801DF5F9 * 4), 0x80, 8, 8, 8, 2, 0);
                }
            }
        }
    }
    rect[2] = 0x16C;
    rect[0] = 0;
    rect[1] = (u16)D_801D883C.y + 3;
    rect[3] = D_801D8842 - 6;
    func_80026A94((s16 *)D_800706A4[D_80062F58], (u16 *)rect);
    i = D_801D883C.y;
    j = D_801D883C.x + D_801D8840;
    func_801D26A4(j, i, D_801DF5F4 + D_801DF5F5 * 3 + D_801DF5EC[0] * 3, D_801DF6B0, 0);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x7F, (s32)rect);
    func_8001E040(&D_801D883C);
    ((void (*)(void *, s32, s32, s32, s32))func_8001DE0C)(&rect2, j, i, D_801D8848, D_801D884A[0]);
    func_8001E040(&rect2);
}

void func_801D3490(void) {
    s16 rect[4];
    Rect8 rect2;
    MainBox box;
    EqpMat8 *rec;
    s32 i;
    s32 n;
    s32 start;
    s32 t;
    s32 x;

    rect[1] = 5;
    rect[2] = 0x16C;
    rect[3] = 0xDB;
    rect[0] = 0;
    func_80026A94((s16 *)D_800706A4[D_80062F58], (u16 *)rect);
    box.f0 = 3;
    box.f2 = 0x10;
    box.w = 0xA;
    box.h = 0x32;
    box.f4 = (u16)D_801DF5FE[0];
    box.x = (u16)D_801D883C.x + 0xEE;
    box.y = (u16)D_801D883C.y + 3;
    func_80028484(&box);
    n = 4;
    rec = D_8009DB14[D_801DF6B0];
    if (D_801DF604 == 0) {
        n = 3;
    }
    start = D_801DF5FE[0];
    for (i = 0; i < n; i++) {
        if (rec[i + start].id != 0xFF) {
            t = i * 0x10 + 6;
            func_80026F44(D_801D883C.x + 0x38, D_801D883C.y + t + D_801DF60B * 4, func_80015248(1, rec[i + start].id, 8), 7);
        }
    }
    rect[2] = 0x16C;
    rect[0] = 0;
    rect[1] = (u16)D_801D883C.y + 3;
    rect[3] = D_801D8842 - 6;
    func_80026A94((s16 *)D_800706A4[D_80062F58], (u16 *)rect);
    i = D_801D883C.y;
    x = D_801D883C.x + D_801D8840;
    func_801D26A4(x, i, D_801DF606 + D_801DF607 + D_801DF5FE[0], D_801DF6B0, 1);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x7F, (s32)rect);
    func_8001E040(&D_801D883C);
    ((void (*)(void *, s32, s32, s32, s32))func_8001DE0C)(&rect2, x, i, D_801D8848, D_801D884A[0]);
    func_8001E040(&rect2);
}

void func_801D373C(void) {
    s16 rect[4];
    Rect8 rect2;
    MainBox box;
    EqpMat8 *rec;
    s32 i;
    s32 j;
    s32 n;
    s32 start;
    s32 t;
    s32 u;

    rect[1] = 5;
    rect[2] = 0x16C;
    rect[3] = 0xDB;
    rect[0] = 0;
    func_80026A94((s16 *)D_800706A4[D_80062F58], (u16 *)rect);
    box.f0 = 3;
    box.f2 = 0xC;
    box.w = 0xA;
    box.h = 0x32;
    box.f4 = (u16)D_801DF610[0];
    box.x = (u16)D_801D883C.x + 0xEE;
    box.y = (u16)D_801D883C.y + 3;
    func_80028484(&box);
    n = 4;
    rec = D_8009DB94[D_801DF6B0];
    if (D_801DF616 == 0) {
        n = 3;
    }
    start = D_801DF610[0] * 2;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2; j++) {
            if (rec[i * 2 + j + start].id != 0xFF) {
                t = j * 0x78 + 0x18;
                u = i * 0x10 + 6;
                func_80026F44(D_801D883C.x + t, D_801D883C.y + u + D_801DF61D * 4, func_80015248(2, rec[i * 2 + j + start].id, 8), 7);
            }
        }
    }
    rect[2] = 0x16C;
    rect[0] = 0;
    rect[1] = (u16)D_801D883C.y + 3;
    rect[3] = D_801D8842 - 6;
    func_80026A94((s16 *)D_800706A4[D_80062F58], (u16 *)rect);
    i = D_801D883C.y;
    j = D_801D883C.x + D_801D8840;
    func_801D26A4(j, i, D_801DF618 + D_801DF619 * 2 + D_801DF610[0] * 2, D_801DF6B0, 2);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x7F, (s32)rect);
    func_8001E040(&D_801D883C);
    ((void (*)(void *, s32, s32, s32, s32))func_8001DE0C)(&rect2, j, i, D_801D8848, D_801D884A[0]);
    func_8001E040(&rect2);
}

void func_801D3A24(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 0x38; j++) {
            if (((EqpChrMat *)D_8009D954)[i].e[j].id != 0xFF && ((EqpChrMat *)D_8009D954)[i].e[j].flag != 0 && (((EqpChrMat *)D_8009D954)[i].e[j].attr & 0xC) != 0xC) {
                ((EqpChrMat *)D_8009D954)[i].e[j].flag = 0;
            }
        }
    }
}

void func_801D3AA0(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3) {
    s16 rect[4];
    s32 i;
    for (i = 0; i < 8; i++) {
        if (arg2[i] != 0 && (arg2[i] == 3 || arg2[i] == 7)) {
            func_80028CA0((s16)(arg0 + i * 0x10 - 8), (s16)arg1, 0x70, 0x30, 0x10, 0x10, 1, 0);
        }
    }
    for (i = 0; i < 8; i++) {
        if (arg2[i] != 0) {
            if (arg3[i * 4] != 0xFF) {
                func_80028CA0((s16)(arg0 + i * 0x10), (s16)arg1, 0x80, 0x20, 0x10, 0x10, (s16)func_8002603C(arg3[i * 4]), 1);
            }
            if (arg2[i] >= 5) {
                func_80028CA0((s16)(arg0 + i * 0x10), (s16)arg1, 0x80, 0x30, 0x10, 0x10, 1, 0);
            } else {
                func_80028CA0((s16)(arg0 + i * 0x10), (s16)arg1, 0x70, 0x20, 0x10, 0x10, 1, 0);
            }
        }
    }
    func_80026A34(0, 1, 0x3F, 0);
    rect[0] = arg0 - 2;
    rect[1] = arg1;
    rect[2] = 0x80;
    rect[3] = 0xB;
    func_80027B84(rect);
    func_80026A34(0, 1, 0x1F, 0);
}

void func_801D3CB0(void) {
    s32 i;

    D_801D8830 = 1;
    D_801DF6B0 = D_80062F6C;
    func_80026448(&D_801DF590[0], 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0);
    func_80026448(&D_801DF590[1], 0, 0, 8, 2, 0, 0, 8, 2, 0, 0, 0, 0, 0);
    func_80026448(&D_801DF590[3], 0, 0, 1, 0xA, 0, 0, 1, 0xC8, 0, 0, 0, 0, 0);
    for (i = 0; i < 3; i++) {
        func_80020058(i);
        func_8001786C(i & 0xFF);
    }
    func_80017678();
    func_801D827C(0x73, 0x9D);
    D_80062D9C = 1;
}

s32 func_801D3E14(s32 arg0) {
    s16 rect[4];
    u8 *rec;
    s32 i;
    s32 x;
    s32 id;
    s32 k5;
    s32 j5;
    s32 k6;
    s32 k7;
    s32 tx;
    s32 ty4;
    s32 ty5;
    s32 ty6;
    s32 ty7;
    s32 ty8;
    s32 ty10;
    s8 *q;

    rec = D_8009D84C[D_801DF6B0];
    switch (D_801D8830) {
    case 0:
        func_8001EB2C(0x8A, D_801DF59B * 0x18 + 0x22);
        break;
    case 1:
        func_8001EB2C(D_801DF5AC * 0x10 + 0xBC, D_801DF5AD * 0x18 + 0x22);
        break;
    case 3:
        if (arg0 & 2) {
            func_8001EB2C(D_801DF5AC * 0x10 + 0xBC, D_801DF5AD * 0x18 + 0x22);
        }
        func_8001EB2C(0xD0, D_801DF5D1 * 0xC + 0x64);
        break;
    case 4:
        if (arg0 & 2) {
            func_8001EB2C(0x8A, D_801DF59B * 0x18 + 0x22);
        }
        q = &D_801DF5E2;
        tx = *q * 0x2C - 0x14;
        x = D_801D8834 + tx;
        if (*q != 0) {
            x += 8;
        }
        ty4 = D_801DF5E3 * 0xC + 8;
        func_8001EB2C(x, D_801D8836 + ty4);
        id = ((Obj4C *)rec)->e[D_801DF5E3 + *q * 4].a;
        if (id != 0xFF) {
            func_80026F44(0x10, D_801D8872 + 6, func_80015248(5, id, 0), 7);
        }
        break;
    case 5:
        if (arg0 & 2) {
            func_8001EB2C(0x8A, D_801DF59B * 0x18 + 0x22);
        }
        q = &D_801DF5F4;
        ty5 = D_801DF5F5 * 0x10 + 8;
        func_8001EB2C(D_801D883C.x + *q * 0x4E - 3, D_801D883C.y + ty5);
        j5 = D_801DF5F5 * 3;
        k5 = *q + j5;
        id = ((EqpObj *)rec)->m[k5 + D_801DF5EC[0] * 3].id;
        if (id != 0xFF) {
            func_80026F44(0x10, D_801D8872 + 6, func_80015248(0, id, 0), 7);
        }
        break;
    case 6:
        if (arg0 & 2) {
            func_8001EB2C(0x8A, D_801DF59B * 0x18 + 0x22);
        }
        q = &D_801DF607;
        ty6 = *q * 0x10 + 8;
        func_8001EB2C(D_801D883C.x + 0x1E, D_801D883C.y + ty6);
        k6 = D_801DF5FE[0] + 0x38;
        id = ((EqpObj *)rec)->m[*q + k6].id;
        if (id != 0xFF) {
            func_80026F44(0x10, D_801D8872 + 6, func_80015248(1, id, 0), 7);
        }
        break;
    case 7:
        if (arg0 & 2) {
            func_8001EB2C(0x8A, D_801DF59B * 0x18 + 0x22);
        }
        q = &D_801DF618;
        ty7 = D_801DF619 * 0x10 + 8;
        func_8001EB2C(D_801D883C.x + *q * 0x78, D_801D883C.y + ty7);
        k7 = D_801DF619 * 2 + 0x48;
        id = ((EqpObj *)rec)->m[*q + k7 + D_801DF610[0] * 2].id;
        if (id != 0xFF) {
            func_80026F44(0x10, D_801D8872 + 6, func_80015248(2, id, 0), 7);
        }
        break;
    case 9:
        func_8001EB2C(0xD0, D_801DF63D * 0xC + 0x64);
    case 8:
        if (D_801D8830 != 9 || (arg0 & 2)) {
            ty8 = D_801DF62B * 0xC + 5;
            func_8001EB2C(D_801D8890.x - 0x12, D_801D8890.y + ty8);
        }
        for (i = 0; i < 4; i++) {
            func_80026F44(D_801D8890.x + 8, D_801D8890.y + i * 0xC + 4, D_801D85AC[i], 7);
        }
        rect[0] = 0;
        rect[1] = 0;
        rect[2] = 0x100;
        rect[3] = 0x100;
        func_80026A34(0, 1, 0x7F, (s32)rect);
        func_8001E040(&D_801D8890);
        break;
    case 10:
        if (arg0 & 2) {
            func_8001EB2C(0xD0, D_801DF63D * 0xC + 0x64);
        }
        ty10 = D_801DF64F * 0xC + 0x18;
        func_8001EB2C(D_801D8898.x + 0x20, D_801D8898.y + ty10);
        func_80026F44(D_801D8898.x + 8, D_801D8898.y + 6, D_801D8454[0], 7);
        func_80026F44(D_801D8898.x + 0x40, D_801D8898.y + 0x15, D_801D8454[1], 7);
        func_80026F44(D_801D8898.x + 0x40, D_801D8898.y + 0x22, D_801D8454[2], 7);
        func_8001E040(&D_801D8898);
        break;
    }
}

s32 func_801D4418(void) {
    s32 mode;
    s32 v;

    mode = D_801D8830;
    D_801DF6B8 = -1;
    switch (mode) {
    case 1:
        ((void (*)(s32))func_80026B5C)(0x80);
        switch (D_801DF5AD) {
        case 0:
            v = D_801DF6C0[D_801D8B0C].wmat[D_801DF5AC];
            if (v != -1) {
                func_80026F44(0x10, D_801D8872 + 6, func_801D2EBC(1, v & 0xFF), 7);
            }
            D_801DF6B8 = (u8)D_801DF6C0[D_801D8B0C].wmat[D_801DF5AC];
            break;
        case 1:
            v = D_801DF6C0[D_801D8B0C].amat[D_801DF5AC];
            if (v != -1) {
                func_80026F44(0x10, D_801D8872 + 6, func_801D2EBC(1, v & 0xFF), 7);
            }
            D_801DF6B8 = (u8)D_801DF6C0[D_801D8B0C].amat[D_801DF5AC];
            break;
        }
        break;
    case 3:
        ((void (*)(s32))func_80026B5C)(0x80);
        v = D_8009CE60[D_801DF590[3].pos + D_801DF590[3].top];
        if (v != -1) {
            func_80026F44(0x10, D_801D8872 + 6, func_801D2EBC(1, v & 0xFF), 7);
        }
        D_801DF6B8 = (u8)D_8009CE60[D_801DF590[3].pos + D_801DF590[3].top];
        break;
    case 4:
        break;
    }
}

void func_801D4678(s32 arg0) {
    D_80063020 = 1;
    func_800197B8(D_8009CE60[D_801DF590[arg0].pos + D_801DF590[arg0].top]);
    func_801D1D5C(D_8009CE60[D_801DF590[arg0].pos + D_801DF590[arg0].top], D_801DF6BC, D_800706A4[D_80062F58]);
}

void func_801D4760(s32 arg0) {
    s16 rect[4];
    s32 i;
    s32 n;
    s32 v;
    s32 color;

    func_800269D0();
    func_800269C0((s32)(D_801D8B10 + D_80062F58 * 0x3500));
    ((void (*)(s32))func_80026B5C)(0xA);
    rect[1] = 5;
    rect[2] = 0x16C;
    rect[3] = 0xDB;
    rect[0] = 0;
    func_80026A94((s16 *)D_800706A4[D_80062F58], (u16 *)rect);
    n = 0xA;
    if (D_801DF598[arg0].f8 != 0) {
        n = 0xB;
    }
    for (i = 0; i < n; i++) {
        v = D_8009CE60[i + D_801DF590[arg0].top];
        if (v != -1) {
            func_80026F44(0xF6, i * 0xC + 0x62 + D_801DF59F[arg0].g * 3, ((void *(*)(s32))func_80021258)(v & 0xFF), 7);
        }
    }
    D_801DF6C8.f0 = 0xA;
    D_801DF6C8.f2 = 0xC8;
    D_801DF6C8.f4 = (u16)D_801DF590[arg0].top;
    D_801DF6C8.x = 0x160;
    D_801DF6C8.y = 0x61;
    D_801DF6C8.w = 0xA;
    D_801DF6C8.h = 0x79;
    i = 0;
    func_80028484(&D_801DF6C8);
    for (; i < n; i++) {
        color = func_8002603C((u8)D_8009CE60[i + D_801DF590[arg0].top]);
        if (D_8009CE60[i + D_801DF590[arg0].top] != -1) {
            func_80028CA0(0xE8, (s16)(i * 0xC + 0x62 + D_801DF59F[arg0].g * 3), 0x80, 0x20, 0x10, 0x10, (s16)color, 0);
        }
    }
    func_80026A34(0, 1, 0x3F, 0);
    rect[1] = 0x61;
    rect[2] = 0x16C;
    rect[3] = 0x79;
    rect[0] = 0;
    func_80026A94((s16 *)D_800706A4[D_80062F58], (u16 *)rect);
    func_800269E8();
}

void func_801D4AA8(void) {
    s16 rect[4];
    s32 i;
    s32 n;
    s32 x;
    s32 y;
    s32 v;
    s32 color;

    func_800269D0();
    func_800269C0((s32)(D_801D8B10 + D_80062F58 * 0x3500));
    ((void (*)(s32))func_80026B5C)(0xA);
    rect[1] = 5;
    rect[2] = 0x16C;
    rect[3] = 0xDB;
    rect[0] = 0;
    func_80026A94((s16 *)D_800706A4[D_80062F58], (u16 *)rect);
    n = 0xA;
    x = 0xF6;
    y = 0x3B;
    if (D_801DF658.f6 != 0) {
        n = 0xB;
    }
    for (i = 0; i < n; i++) {
        v = D_8009CE60[i + D_801DF658.top];
        if (v != -1) {
            func_80026F44(x, y + i * 0x10 + D_801DF658.g * 4, ((void *(*)(s32))func_80021258)(v & 0xFF), 7);
        }
    }
    D_801DF6C8.f0 = 0xA;
    D_801DF6C8.f2 = 0xC8;
    D_801DF6C8.x = 0x160;
    D_801DF6C8.y = 0x38;
    D_801DF6C8.w = 0xA;
    D_801DF6C8.h = 0xA2;
    D_801DF6C8.f4 = (u16)D_801DF658.top;
    i = 0;
    func_80028484(&D_801DF6C8);
    for (; i < n; i++) {
        color = func_8002603C((u8)D_8009CE60[i + D_801DF658.top]);
        if (D_8009CE60[i + D_801DF658.top] != -1) {
            func_80028CA0((s16)(x - 0x10), (s16)(y - 1 + i * 0x10 + D_801DF658.g * 4), 0x80, 0x20, 0x10, 0x10, (s16)color, 0);
        }
    }
    func_80026A34(0, 1, 0x3F, 0);
    rect[1] = 0x38;
    rect[2] = 0x16C;
    rect[3] = 0xA2;
    rect[0] = 0;
    func_80026A94((s16 *)D_800706A4[D_80062F58], (u16 *)rect);
    func_800269E8();
}

s32 func_801D4D94(void) {
    u8 pad[8];

    switch (D_801D8830) {
    case 1:
        func_801D2EB4();
        ((void (*)(s32))func_80026B5C)(0xA);
        D_80063020 = 1;
        switch (D_801DF5AD) {
        case 0:
            func_800197B8(D_801DF6C0[D_801D8B0C].wmat[D_801DF5AC]);
            func_801D1D5C(D_801DF6C0[D_801D8B0C].wmat[D_801DF5AC], D_801DF6BC, D_800706A4[D_80062F58]);
            break;
        case 1:
            func_800197B8(D_801DF6C0[D_801D8B0C].amat[D_801DF5AC]);
            func_801D1D5C(D_801DF6C0[D_801D8B0C].amat[D_801DF5AC], D_801DF6BC, D_800706A4[D_80062F58]);
            break;
        }
        func_80026A34(0, 1, 0x3F, 0);
        break;
    case 3:
        func_801D4678(3);
        func_801D4760(3);
        break;
    case 0:
        if (D_801DF59B != 0) {
            goto show;
        }
        func_801D2EFC();
    case 8:
    case 9:
    case 10:
        if (D_801DF59B == 0) {
            break;
        }
    show:
        if (D_801D8830 != 0 && D_801D8830 != 8) {
            func_801D4678(9);
        }
        func_801D4760(9);
        break;
    case 4:
        func_801D2EFC();
        break;
    default:
        func_801D2EFC();
        switch (D_801DF6C4[D_801DF5E2 * 4 + D_801DF5E3].type) {
        case 1:
        case 8:
            func_801D3074(D_800708C4);
            break;
        case 2:
        case 9:
            ((void (*)(void *))func_801D3490)(D_80070EE4);
            break;
        case 4:
            ((void (*)(void *))func_801D373C)(D_800710A4);
            break;
        }
        break;
    }
}

void func_801D509C(void) {
    s16 rect[4];

    func_80020B68(0x3E, 0x13, D_801DF6B0);
    func_8001CF3C(0xA, 0xE, 0x30, 0x30, 0, D_801DF6B0 * 0x30 + 0x38, 0x30, 0x30, D_801DF6B0 + 0xD, 0);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0x100;
    rect[3] = 0x100;
    func_80026A34(0, 1, 0x7F, (s32)rect);
}

void func_801D513C(u8 *a, u8 *b, s32 *c, s32 *d) {
    s32 i;
    s32 t;

    for (i = 0; i < 8; i++) {
        if (a[i] != 0 && b[i] != 0) {
            t = c[i];
            c[i] = d[i];
            d[i] = t;
        }
    }
}

void func_801D5194(void) {
    s32 i;
    s32 n;
    u8 *p;
    u16 *q;

    for (i = 0; i < 9; i++) {
        D_801DF6EC[i] = 0xFF;
    }
    i = 0;
    n = 0;
    q = D_8009D78A;
    p = D_801DF6EC;
    for (; i < 9; i++) {
        if ((*q >> i) & 1) {
            *p++ = i;
            n++;
        }
    }
    D_801DF6E8 = n;
    func_80026448(&D_801DF590[11], 0, 0, 1, 0xA, 0, 0, 1, 0xC8, 0, 0, 0, 0, 0);
    func_80026448(&D_801DF590[12], 0, 0, 8, 2, 0, 0, 8, 2, 0, 0, 0, 0, 0);
    func_80026448(&D_801DF590[13], 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 0, 0);
}

s32 func_801D5300(s32 x, s32 y, s32 item) {
    s16 rect[4];
    s32 i;
    s32 color;
    u8 id;

    id = item;
    func_80026F44(x + 0x10, y, ((void *(*)(s32))func_80021258)(id), 7);
    color = func_8002603C(id);
    func_80028CA0((s16)x, (s16)(y - 1), 0x80, 0x20, 0x10, 0x10, (s16)color, 0);
    func_80026A34(0, 1, 0x3F, 0);
    func_800197B8(item);
    if (id != 0x30 && id != 0x49 && id != 0x5A && id != 0x2C) {
        for (i = 0; i < D_801D8B08->count; i++) {
            if (i < D_801D8B08->filled) {
                func_80028CA0((s16)(0xAA + i * 0xF), 0xB, 0x90, 0x20, 0x10, 0x10, (s16)color, 0);
            } else {
                func_80028CA0((s16)(0xAA + i * 0xF), 0xB, 0x90, 0x30, 0x10, 0x10, (s16)color, 0);
            }
        }
    }
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0xFF;
    rect[3] = 0xFF;
    func_80026A34(0, 1, 0x7F, (s32)rect);
    return color;
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D54B0);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D5BD0);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D6C2C);

void func_801D7FDC(void) {
    D_80062D9C = 0;
}

void func_801D7FEC(void) {
}

void func_801D7FF4(void) {
    u16 *p;

    if (D_80062D80 & 8) {
        *(volatile s32 *)&D_801D88EC -= 0x80;
    }
    if (D_80062D80 & 2) {
        *(volatile s32 *)&D_801D88EC += 0x80;
    }
    p = &D_801D88E0;
    *p += 0x20;
}

void func_801D8070(s32 arg0, EqpTmdBuf *arg1) {
    MainTmdPrim prim;
    u8 pad[8];
    EqpTmdEnt *e;
    EqpFt3 *a;
    EqpFt3 *b;
    s32 n;
    s32 i;

    e = &arg1->e[0];
    a = &arg1->a[0];
    b = &arg1->b[0];
    n = ((s32 (*)(s32, s32))func_80046D74)(arg0, 0);
    if (n >= 2) {
        n = 1;
    }
    for (i = 0; i < n; i++) {
        if (func_80046DB4(&prim) == 0) {
            break;
        }
        func_800468AC(a);
        func_80046870(a, 1);
        e->n[0].vx = prim.n[0].vx;
        e->n[0].vy = prim.n[0].vy;
        e->n[0].vz = prim.n[0].vz;
        e->n[1].vx = prim.n[1].vx;
        e->n[1].vy = prim.n[1].vy;
        e->n[1].vz = prim.n[1].vz;
        e->n[2].vx = prim.n[2].vx;
        e->n[2].vy = prim.n[2].vy;
        e->n[2].vz = prim.n[2].vz;
        e->v[0].vx = prim.v[0].vx;
        e->v[0].vy = prim.v[0].vy;
        e->v[0].vz = prim.v[0].vz;
        e->v[1].vx = prim.v[1].vx;
        e->v[1].vy = prim.v[1].vy;
        e->v[1].vz = prim.v[1].vz;
        e->v[2].vx = prim.v[2].vx;
        e->v[2].vy = prim.v[2].vy;
        e->v[2].vz = prim.v[2].vz;
        a->clut = func_80046634(0, 0x1FE);
        a->tpage = func_8004656C(1, 1, 0x340, 0);
        *(EqpPkt *)b = *(EqpPkt *)a;
        e++;
        a++;
        b++;
    }
    arg1->count = i;
}

void func_801D827C(void) {
}

void func_801D8284(void) {
}

void func_801D828C(void) {
}

void func_801D8294(void) {
}

void func_801D829C(void) {
}
