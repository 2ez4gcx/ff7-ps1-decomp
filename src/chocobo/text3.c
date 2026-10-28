#include "common.h"
#include "chocobo/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
extern u8 D_8009D499[];

INCLUDE_RODATA("../asm/us/chocobo/nonmatchings/text3", D_800A0068);

void func_800A7924(ChoMat *arg0, ChoSVec *arg1, ChoSVec *arg2) {
    ChoVec sp10;
    ChoVec sp20;
    ChoVec sp30;
    ChoVec sp40;
    s32 t;

    sp40 = D_800A0068;
    sp10.vx = arg2->vx - arg1->vx;
    sp10.vy = arg2->vy - arg1->vy;
    sp10.vz = arg2->vz - arg1->vz;
    func_8003A08C(&sp10, &sp30);
    func_8003BA10(&sp30, &sp40, &sp10);
    func_8003A08C(&sp10, &sp20);
    func_8003BA10(&sp30, &sp20, &sp10);
    func_8003A08C(&sp10, &sp40);
    t = sp20.vx;
    arg0->m[0][0] = t;
    t = sp20.vy;
    arg0->m[0][1] = t;
    t = sp20.vz;
    arg0->m[0][2] = t;
    t = sp40.vx;
    arg0->m[1][0] = t;
    t = sp40.vy;
    arg0->m[1][1] = t;
    t = sp40.vz;
    arg0->m[1][2] = t;
    t = sp30.vx;
    arg0->m[2][0] = t;
    t = sp30.vy;
    arg0->m[2][1] = t;
    t = sp30.vz;
    arg0->m[2][2] = t;
    func_8003B27C(arg0, arg1, &sp10);
    arg0->t[0] = -sp10.vx;
    arg0->t[1] = -sp10.vy;
    arg0->t[2] = -sp10.vz;
}

void func_800A7AB8(s32 arg0, s32 arg1) {
    s32 *p;

    if (D_800F5054.b[0] == 2) {
        switch (D_800F5055) {
        case 0:
            arg1 = 0;
            break;
        case 1:
            arg1 = (s16)D_800B75D0[D_800B753C].f0 / 2;
            break;
        case 2:
            arg1 = D_800B75D0[D_800B753C].f0;
            break;
        case 3:
            arg1 = D_800B75D0[D_800B753C].f0 * 2;
            break;
        }
        p = &D_800B1358;
        if (*p != 0) {
            func_800A6B9C(D_800B753C, arg1, D_800F505E);
            *p = 0;
        }
    } else {
        func_800A68D4(D_800B753C);
    }
    if ((D_800F5048 != 0 && D_800B7A48 == 0) || (D_800B7A48 != 0 && D_800B764A != 0)) {
        D_800F5054.b[0] = 0xA;
        D_800B759C = -1;
        D_800B753C = D_800B7594;
    }
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text3", func_800A7CA4);

INCLUDE_RODATA("../asm/us/chocobo/nonmatchings/text3", D_800A00A8);

INCLUDE_RODATA("../asm/us/chocobo/nonmatchings/text3", D_800A00B8);

void func_800A869C(void) {
    ChoVec v;
    ChoMat m;
    ChoSVec r;
    s32 flag;
    s32 *p;

    v = D_800A00A8;
    r = D_800A00B8;
    p = &D_800B759C;
    if (*p != 0) {
        D_800B7340 = D_800B1348;
        D_800B7348 = D_800B1350;
        *p = 0;
    }
    D_800B7348.vx = (D_800B7348.vx * 3 + D_800B1350.vx) / 4;
    D_800B7348.vy = (D_800B7348.vy * 7 + D_800B1350.vy) / 8;
    D_800B7348.vz = (D_800B7348.vz * 3 + D_800B1350.vz) / 4;
    D_800B7340.vx = (D_800B7340.vx * 3 + D_800B1348.vx) / 4;
    D_800B7340.vy = (D_800B7340.vy * 7 + D_800B1348.vy) / 8;
    D_800B7340.vz = (D_800B7340.vz * 3 + D_800B1348.vz) / 4;
    func_800A7924(&m, &D_800B7340, &D_800B7348);
    func_8003C21C(&r, &D_800B7544);
    func_8003B32C(&D_800B7544, &v);
    func_8003B16C(&m, &D_800B7544);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003BC6C(&v, (ChoVec *)D_800B7544.t, &flag);
    func_8003B48C(&D_800B7544);
    func_8003B51C(&D_800B7544);
}

void func_800A8940(s16 arg0) {
    if (arg0 > 0x80) {
        D_800F5084->f40[arg0 - 0x80].f8 = -1;
    } else {
        D_800F5084->f40[arg0].f8 = 1;
    }
}

s32 func_800A89A0(s32 arg0, s32 arg1) {
    s32 v;
    s32 i;

    if ((s16)arg0 >= 0x1000) {
        return 0x400;
    }
    if ((s16)arg0 < -0xFFF) {
        return 0xC00;
    }
    i = (arg0 + 0x1000) & 0x1FFF;
    if ((s16)arg1 <= 0) {
        v = D_800B26CC[0x2000 - i] + 0xC00;
    } else {
        v = D_800B26CC[i] + 0x400;
    }
    return v & 0xFFF;
}

s32 func_800A8A18(ChoSVec *arg0, ChoSVec *arg1) {
    ChoVec v;
    s32 x;
    s32 y;
    s32 i;
    s32 r;

    v.vx = arg1->vx - arg0->vx;
    v.vy = arg1->vy - arg0->vy;
    v.vz = arg1->vz - arg0->vz;
    func_8003A08C(&v, &v);
    x = v.vx;
    y = v.vz;
    if ((s16)x >= 0x1000) {
        return 0x400;
    }
    if ((s16)x < -0xFFF) {
        return 0xC00;
    }
    i = (x + 0x1000) & 0x1FFF;
    if ((s16)y > 0) {
        r = D_800B26CC[i] + 0x400;
    } else {
        r = D_800B26CC[0x2000 - i] + 0xC00;
    }
    return r & 0xFFF;
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text3", func_800A8AE8);

INCLUDE_RODATA("../asm/us/chocobo/nonmatchings/text3", D_800A00C0);

void func_800A9828(void) {
    s32 buf[50];
    s32 *src;
    u32 i;

    *(ChoRect *)buf = D_800A00C0;
    for (i = 0; i < 48; i++) {
        buf[i + 2] = D_800B2188[i];
    }
    if (D_800B7A48 != 0) {
        switch (D_8009D499[0]) {
        case 1:
            src = D_800B2288;
            break;
        case 2:
            src = D_800B2268;
            break;
        case 3:
            src = D_800B2248;
            break;
        case 0:
        case 4:
            src = D_800B22A8;
            break;
        }
        for (i = 0; i < 8; i++) {
            buf[i + 2] = src[i];
        }
    }
    if (D_8009D499[5] != 0) {
        for (i = 8; i < 16; i++) {
            buf[i + 2] = D_800B2248[i - 8];
        }
    }
    func_80044000(buf, buf + 2);
    if (D_800B7A48 != 0) {
        D_800B1370 = D_800B1388[D_8009D499[0]];
    }
    if (D_8009D499[5] != 0) {
        D_800B1374 = D_800B1375 = D_800B1376 = 0x80;
    }
}

void func_800A9A94(void) {
    ChoRect r;
    s32 sel;
    s32 i;
    s32 tbl;
    u8 *p;
    u8 *q;
    s32 col;
    s32 *pad;
    u8 **pb;

    sel = 0;
    pb = &D_800F5074;
    tbl = (s32)D_8009D488;
    pad = &D_800B7534;
    while (1) {
        *pb = D_800B7A68;
        func_80044244(D_800B7A68, 1);
        func_8003CEDC(3);
        r.w = 0x140;
        r.x = 0;
        r.y = 0;
        r.h = 0x1E0;
        func_80043F6C(&r, 0, 0, 0);
        i = 0;
        p = (u8 *)(sel + tbl);
        q = (u8 *)tbl;
        func_80026A00((s32)*pb);
        func_800269C0((s32)D_80077F64);
        col = (sel & 0xF) * 12;
        for (; i < 0x40; i++) {
            if (sel == i) {
                func_80028E00((sel / 16) << 5, col + 0x10, *p, 4, 2);
            } else {
                func_80028E00((i / 16) << 5, (i & 0xF) * 12 + 0x10, *q, 4, 7);
            }
            q++;
        }
        D_800B7534 = func_8001C808();
        if (D_800B7534 != D_800F5080) {
            if (D_800B7534 & 0x8000) {
                sel--;
                if (sel < 0) {
                    sel = 0x3F;
                }
            }
            if (D_800B7534 & 0x2000) {
                sel++;
                if (sel >= 0x40) {
                    sel = 0;
                }
            }
            if (*pad & 0x20) {
                (*(u8 *)(sel + tbl))++;
            }
            if (*pad & 0x40) {
                (*(u8 *)(sel + tbl))--;
            }
            if (*pad & 0x100) {
                return;
            }
        }
        r.x = 0;
        r.y = 0;
        r.w = 0x100;
        r.h = 0x100;
        D_800F5080 = D_800B7534;
        func_80026A34(0, 1, func_8004656C(0, 1, 0x3C0, 0x100) & 0xFFFF, (s32)&r);
        func_8004433C((s32)D_800F5074);
    }
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text3", func_800A9D94);

void func_800AAC00(u32 arg0, s32 arg1, s32 arg2) {
    ChoSp pk[11];
    s32 *pi;
    u8 **pb;
    s32 *pi2;
    u8 **pb2;
    s32 i;
    ChoRowA *pa;
    s32 idx1;
    u8 *buf1;
    s32 d;
    ChoRowB *pc;
    s32 idx2;
    u8 *buf2;
    ChoRowB *pd;
    s32 idx3;
    u8 *buf3;

    D_800B159A = func_8004656C(0, 0, 0x280, 0x100);
    pi = &D_800F5034;
    pb = &D_800F5074;
    pa = (ChoRowA *)((s32)*pb + *pi * 0x28);
    pa->q = D_800B1584;
    idx1 = *pi;
    buf1 = *pb;
    ((ChoRowT *)(buf1 + idx1 * 0x28))->tag.addr = ((ChoTag *)(buf1 + 0xF4))->addr;
    ((ChoTag *)(buf1 + 0xF4))->addr = (u32)(buf1 + (idx1 * 0x28 + 0x4010));
    *pi = idx1 + 1;
    if (arg0 == 0) {
        pk[0].u = 8;
        pk[0].v = 0xF0;
        pk[0].clut = 0x79E4;
        pk[0].len = 3;
        pk[0].x = arg1;
        pk[0].y = arg2;
        pk[0].rgbc = 0x7C808080;
        pc = (ChoRowB *)((s32)*pb + *pi * 0x28);
        pc->q = pk[0];
        idx2 = *pi;
        buf2 = *pb;
        ((ChoRowT *)(buf2 + idx2 * 0x28))->tag.addr = ((ChoTag *)(buf2 + 0xF0))->addr;
        ((ChoTag *)(buf2 + 0xF0))->addr = (u32)(buf2 + (idx2 * 0x28 + 0x4010));
        *pi = idx2 + 1;
        return;
    }
    for (i = 0; i < 11; i++) {
        d = arg0 % 10;
        pk[i].x = arg1 - i * 12;
        pk[i].y = arg2;
        if (arg0 != 0) {
            pk[i].u = d * 16 + 8;
        } else {
            pk[i].u = 0xF0;
        }
        pk[i].clut = 0x79E4;
        pk[i].v = 0xF0;
        pk[i].len = 3;
        pk[i].rgbc = 0x7C808080;
        pb2 = &D_800F5074;
        pi2 = &D_800F5034;
        pd = (ChoRowB *)((s32)*pb2 + *pi2 * 0x28);
        pd->q = pk[i];
        idx3 = *pi2;
        buf3 = *pb2;
        ((ChoRowT *)(buf3 + idx3 * 0x28))->tag.addr = ((ChoTag *)(buf3 + 0xF0))->addr;
        ((ChoTag *)(buf3 + 0xF0))->addr = (u32)(buf3 + (idx3 * 0x28 + 0x4010));
        *pi2 = idx3 + 1;
        arg0 /= 10;
    }
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text3", func_800AAF1C);

void func_800AB410(void) {
    s32 t[2][16];
    s32 *p;
    s32 n;
    s32 found;
    s32 last;
    s32 cnt;
    s32 r;
    s32 i;
    s32 j;
    s32 k;
    s32 x;
    s32 u;
    s32 *t0;
    s32 **tp;
    u8 *e;
    u8 *e2;
    ChoSlot *s;

    switch (D_800F5098) {
    case 0:
        D_800B7458[0] = &D_800B23C0;
        break;
    case 1:
        D_800B7458[0] = &D_800B2380;
        break;
    case 2:
        D_800B7458[0] = &D_800B232C;
        break;
    case 3:
        D_800B7458[0] = &D_800B22D0;
        break;
    }
    n = 0;
    found = 0;
    t0 = D_800B7458[0];
    cnt = *t0;
    D_800B7458[0] = t0 + 1;
    *(s32 *)D_800B745C = ((s32 *)D_800B745C)[1] = ((s32 *)D_800B745C)[2] = -1;
    last = -1;
    tp = &D_800B7458[0];
    p = D_800B745C;
    do {
        r = func_80042DA8() % cnt;
        e = (u8 *)(r * 4 + (s32)*tp);
        if (e[0] != *(s32 *)D_800B745C && e[0] != ((s32 *)D_800B745C)[1] && e[0] != ((s32 *)D_800B745C)[2]) {
            if (e[1] != 0) {
                if (found == 0 || e[3] == 0) {
                    if (D_800B747C != 0) {
                        *p++ = e[0];
                        n++;
                    }
                    e2 = (u8 *)(r * 4 + (s32)*tp);
                    if (e2[3] != 0) {
                        last = e2[0];
                        found = -1;
                    }
                    if (n >= 3) {
                        break;
                    }
                }
            } else if (found == 0 || e[3] == 0) {
                *p++ = e[0];
                n++;
                if (e[3] != 0) {
                    last = e[0];
                    found = -1;
                }
                if (n >= 3) {
                    break;
                }
            }
        }
    } while (n != 3);
    for (n = 0; n < 3; n++) {
        for (j = 0; j < 2; j++) {
            if (((s32 *)D_800B745C)[j] > ((s32 *)D_800B745C)[j + 1]) {
                x = ((s32 *)D_800B745C)[j];
                ((s32 *)D_800B745C)[j] = ((s32 *)D_800B745C)[j + 1];
                ((s32 *)D_800B745C)[j + 1] = x;
            }
        }
    }
    if (last != -1) {
        if (*(s32 *)D_800B745C == last) {
            u = ((s32 *)D_800B745C)[2];
            ((s32 *)D_800B745C)[2] = last;
            *(s32 *)D_800B745C = u;
        } else if (((s32 *)D_800B745C)[1] == last) {
            u = ((s32 *)D_800B745C)[2];
            ((s32 *)D_800B745C)[2] = last;
            ((s32 *)D_800B745C)[1] = u;
        }
    }
    for (n = 0; n < 7; n++) {
        t[0][n] = *(s32 *)D_800B745C;
        t[1][n] = 0;
    }
    for (n = 7; n < 12; n++) {
        t[0][n] = ((s32 *)D_800B745C)[1];
        t[1][n] = 1;
    }
    for (n = 12; n < 15; n++) {
        t[0][n] = ((s32 *)D_800B745C)[2];
        t[1][n] = 2;
    }
    for (n = 0; n < 100; n++) {
        j = func_80042DA8() % 15;
        k = func_80042DA8() % 15;
        x = t[0][j];
        t[0][j] = t[0][k];
        t[0][k] = x;
        x = t[1][j];
        t[1][j] = t[1][k];
        t[1][k] = x;
    }
    for (i = 0; i < 3; i++) {
        for (n = 0; n < 5; n++) {
            s = (ChoSlot *)((u8 *)D_800B7480 + (i * 8 + n * 0x18));
            s->f0 = 0;
            s->f2 = 0;
            s->f3 = 0;
            s->f6 = t[0][i * 5 + n];
            s->f7 = t[1][i * 5 + n];
            s->f5 = 2;
            ((ChoPkt *)((u8 *)D_800D5DD0 + (i * 0x28 + n * 0x78)))->len = 9;
            D_800F48B3[i * 0x28 + n * 0x78] = 9;
        }
    }
    D_800F502C = D_8009D260;
    D_800B753C = 0;
}

INCLUDE_RODATA("../asm/us/chocobo/nonmatchings/text3", D_800A01B8);
