#include "common.h"
#include "magic_siva/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B49CC();
    return &D_801D9E98;
}

MgMat *func_801B007C(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801F0040.m[0][0] = D_801F0040.m[1][1] = D_801F0040.m[2][2] = scale;
    func_8003B48C(&D_801F1374);
    func_8003B51C(&D_801F1374);
    func_8003BC6C(v, (MgVec *)D_801F0040.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801F0040.t, &n);
        D_801F0040.t[0] += (dist * n.vx) >> 12;
        D_801F0040.t[1] += (dist * n.vy) >> 12;
        D_801F0040.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801F0040);
    func_8003B51C(&D_801F0040);
    return &D_801F0040;
}

s32 func_801B0198(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F139E[-v];
    }
    return v;
}

s32 func_801B01D4(s32 t, s32 s) {
    s32 orig;
    s32 i;
    s32 n;

    orig = t;
    if (s > 0) {
        n = s >> 8;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
    } else {
        s = -s;
        n = s >> 8;
        t = 0x1000 - t;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
        t = 0x1000 - t;
    }
    n = (s & 0xFF) + 1;
    t = (t * n + orig * (0x100 - n)) >> 8;
    return t;
}

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B02C4);

void func_801B1300(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B02C4)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B1364);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B1760);

INCLUDE_ASM("../asm/us/magic_siva/nonmatchings/text", func_801B1B5C);

void func_801B2078(MgSVec *a) {
    u8 *q;
    s32 r;
    s32 ext;
    s32 flag;
    s32 t;

    q = (u8 *)D_80163C74;
    r = func_8003BBDC(a, q + 8, &ext, &flag);
    if (!(flag & 0x60000)) {
        func_800468E8(q);
        q[4] = 0xFF;
        q[5] = 0xFF;
        q[6] = 0xFF;
        q[7] |= 2;
        *(s32 *)(q + 0xC) = *(s32 *)(q + 8) + 2;
        *(s32 *)(q + 0x10) = *(s32 *)(q + 8) + 0x20000;
        *(s32 *)(q + 0x14) = *(s32 *)(q + 8) + 0x20002;
        t = (r >> 2) * 4 + 0x70;
        func_80046794(t + D_801517C0, q);
        q += 0x18;
    }
    D_80163C74 = (s32)q;
}

void func_801B2150(MgSVec *a, MgSVec *b) {
    u8 *q;
    s32 r;
    s32 ext;
    s32 flag;
    s32 t;

    q = (u8 *)D_80163C74;
    r = func_8003BC0C(a, a, b, q + 8, q + 8, q + 0x10, &ext, &flag);
    if (!(flag & 0x60000)) {
        func_800469D8(q);
        q[4] = 0xFF;
        q[5] = 0xFF;
        q[6] = 0xFF;
        q[0xC] = 0x80;
        q[0xD] = 0x80;
        q[0xE] = 0x80;
        q[7] |= 2;
        t = (r >> 2) * 4 + 0x70;
        func_80046794(t + D_801517C0, q);
        q += 0x14;
    }
    D_80163C74 = (s32)q;
}

s32 func_801B2224(void) {
    MgSVec *sp;
    s32 i;
    s32 n;

    n = 0;
    sp = (MgSVec *)0x1F800000;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    for (i = 0; i < 200; i++) {
        if (D_801F13B4[i].life != 0) {
            if (D_80062D98 == 0) {
                func_801B1B5C(&D_801F13B4[i]);
            }
            sp->vx = D_801F13B4[i].x + D_801F13B4[i].vx;
            sp->vy = D_801F13B4[i].y + D_801F13B4[i].vy;
            sp->vz = D_801F13B4[i].z + D_801F13B4[i].vz;
            D_801F13B4[i].fn(sp, &D_801F13B4[i].x, D_801F13B4[i].life);
            if (D_80062D98 == 0) {
                *(MgSVec *)&D_801F13B4[i].x = *sp;
                D_801F13B4[i].vx -= D_801F13B4[i].vx >> 2;
                D_801F13B4[i].vy -= D_801F13B4[i].vy >> 2;
                D_801F13B4[i].vz -= D_801F13B4[i].vz >> 2;
                D_801F13B4[i].life--;
                if ((u16)(D_801F13B4[i].x + 0x4E20) > 0x9C40 || (u16)(D_801F13B4[i].z + 0x4E20) > 0x9C40 || D_801F13B4[i].y > 0) {
                    D_801F13B4[i].life = 0;
                }
            }
            n++;
        }
    }
    return n;
}

void func_801B249C(void) {
    s32 i;

    for (i = 0x12A8; i >= 0; i -= 0x18) {
        *(s16 *)(D_801F13B6 + i) = 0;
    }
}

SvPtcl *func_801B24C0(MgB8 *a, MgB8 *b, s16 life) {
    s32 i;

    for (i = 0; i < 200; i++) {
        if (D_801F13B4[i].life == 0) {
            *(MgB8 *)&D_801F13B4[i].x = *a;
            *(MgB8 *)&D_801F13B4[i].vx = *b;
            D_801F13B4[i].pad0 = -1;
            D_801F13B4[i].life = life;
            return &D_801F13B4[i];
        }
    }
    return 0;
}

SvSlot *func_801B257C(s32 arg0) {
    SvSlot *p;
    s32 i;

    i = 0;
    p = (SvSlot *)D_801F2674;
    for (; i < 5; i++) {
        if (p->unk0 == 0) {
            p->unk0 = arg0;
            p->unk2 = 0;
            return p;
        }
        p++;
    }
    return 0;
}

void func_801B25C4(void) {
    s32 i;
    s32 *p;

    i = 0x1F3;
    p = D_801F45B4;
    do {
        *p = 0;
        i--;
        p--;
    } while (i >= 0);
}

SvPart *func_801B25E8(s32 arg0) {
    s32 i;

    for (i = 0; i < 500; i++) {
        if (D_801F3DE8[i] == 0) {
            D_801F3DE8[i] = arg0;
            D_801F2678[i].unk0 = 0;
            D_801F2678[i].unk2 = 0;
            return &D_801F2678[i];
        }
    }
    return 0;
}

void func_801B2658(void) {
    MgObj20 *p;
    s32 n;
    s32 i;

    p = &D_80162978[D_8015169C];
    n = 0;
    for (i = 0; i < 500; i++) {
        if (D_801F3DE8[i] != 0) {
            ((void (*)(SvPart *))D_801F3DE8[i])(&D_801F2678[i]);
            if (D_801F2678[i].unk0 == -1) {
                D_801F3DE8[i] = 0;
            } else {
                n++;
            }
        }
    }
    if (n == 0 && D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B274C(s32 arg0) {
    D_801F2674 = arg0;
}

void func_801B275C(MgSVec *arg0) {
    func_801B007C(arg0, 0x1000, 0);
    D_80163C74 = func_800D4D90(&D_801F0298, D_801517C0 + 0x70, 0xC, D_80163C74);
}

void func_801B27AC(MgSVec *a, s32 arg1, s32 t) {
    u8 *q;
    s32 r;
    s32 ext;
    s32 flag;
    s32 c;
    s32 k;

    q = (u8 *)D_80163C74;
    func_8003B48C(&D_801F1374);
    func_8003B51C(&D_801F1374);
    r = func_8003BBDC(a, q + 8, &ext, &flag);
    if (!(flag & 0x60000)) {
        c = (0x14 - t) * 8 + 0x14;
        *(s32 *)q = 0x03000000;
        c = c | (c << 8) | (c << 16);
        *(s32 *)(q + 4) = c | 0x62000000;
        *(s32 *)(q + 0xC) = 0x20002;
        k = (r >> 2) * 4 + 0x70;
        func_80046794(k + D_801517C0, q);
        D_80163C74 = (s32)(q + 0x10);
    }
}

void func_801B28A0(void) {
    MgObj20 *p;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 0xA5) {
            for (i = 0; i < 1; i++) {
                D_801F02AC->vx = func_80042DA8() % 6000 - 0xBB8;
                D_801F02AC->vy = -0x1388;
                D_801F02AC->vz = func_80042DA8() % 6000 - 0xBB8;
                func_801B24C0((MgB8 *)D_801F02AC, (MgB8 *)&D_801F02A4, 0x64)->fn = (void (*)(MgSVec *, void *, s32))func_801B275C;
            }
        }
        if ((u16)(p->unk2 - 0x69) < 0x3C) {
            for (i = 0; i < 5; i++) {
                D_801F02AC->vx = func_80042DA8() % 10000 - 0x1388;
                D_801F02AC->vy = func_80042DA8() % 10000 - 0x1B58;
                D_801F02AC->vz = func_80042DA8() % 10000 - 0x1388;
                func_801B24C0((MgB8 *)D_801F02AC, (MgB8 *)&D_801F02A4, 0x14)->fn = (void (*)(MgSVec *, void *, s32))func_801B27AC;
            }
        }
        p->unk2++;
    }
    if (func_801B2224() == 0) {
        p->unk0 = -1;
    }
}

void func_801B2B1C(void) {
    MgObj20 *p;
    s32 t;
    s32 q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x1E) {
        q = (t << 12) / 30;
        D_801F02BA = 0x1000 - q;
        goto draw;
    }
    t -= 0x1E;
    if (t < 0x32) {
        D_801F02BA = 0;
        goto draw;
    }
    t -= 0x32;
    if (t < 0x14) {
        q = (t << 12) / 20;
        D_801F02BA = q;
        goto draw;
    }
    p->unk0 = -1;
    return;
draw:
    func_801B007C((MgSVec *)&p->unk4, 0x3000, 0x1F4);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801F02B0, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B2C6C(void) {
    MgObj20 *p;
    s32 t;
    s32 q;
    s32 c;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x32) {
        D_801F02CA = 0;
        q = (t << 12) / 50;
        c = (q * 0xB80 >> 12) + 0x80;
        goto draw;
    }
    t -= 0x32;
    if (t < 0xF) {
        q = (t << 12) / 15;
        D_801F02CA = q;
        q = func_801B01D4(q, 0x3C0);
        c = (q * 0x3400 >> 12) + 0xC00;
        goto draw;
    }
    p->unk0 = -1;
    return;
draw:
    func_801B007C((MgSVec *)&D_801F1398, c, -0x1F4);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801F02C0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B2DE0(void) {
    MgObj20 *p;
    s32 t;
    s32 q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 8) {
        D_801F02DA = 0x1000 - (t << 12) / 8;
        goto draw;
    }
    t -= 8;
    if (t < 2) {
        D_801F02DA = 0;
        goto draw;
    }
    p->unk0 = -1;
    return;
draw:
    func_8003C21C((u8 *)p + 0xC, &D_801F02E0->m);
    D_801F02E0->m.t[0] = ((MgSVec *)&D_801F1398)->vx;
    D_801F02E0->m.t[1] = ((MgSVec *)&D_801F1398)->vy;
    D_801F02E0->m.t[2] = ((MgSVec *)&D_801F1398)->vz;
    t = p->unk2;
    t = (t << 12) / 10;
    q = t;
    D_801F02E0->scale.vx = D_801F02E0->scale.vy = D_801F02E0->scale.vz = (q * -0x3000 >> 12) + 0x3000;
    func_8003B35C(&D_801F02E0->m, &D_801F02E0->scale);
    func_8003A63C(&D_801F1374, &D_801F02E0->m, &D_801F02E0->m);
    func_8003B48C(&D_801F02E0->m);
    func_8003B51C(&D_801F02E0->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801F02D0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B2FAC(void) {
    MgObj20 *p;
    SvTask *q;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (SvTask *)&D_80162978[func_800BBEAC(&func_801B2C6C)];
            q->unk6 = -0xBB8;
            q->unk4 = 0;
            q->unk8 = 0x3E8;
        }
        if ((p->unk2 & 3) == 0) {
            q = (SvTask *)&D_80162978[func_800BBEAC(&func_801B2DE0)];
            q->unk4 = D_801F1398.x;
            q->unk6 = D_801F1398.y;
            q->unk8 = D_801F1398.z;
            q->unkC = func_80042DA8() & 0xFFF;
            q->unkE = func_80042DA8() & 0xFFF;
            q->unk10 = func_80042DA8() & 0xFFF;
        }
        p->unk2++;
        if (p->unk2 >= 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B30DC(MgObj20 *p) {
    func_801B007C((MgSVec *)&p->unk4, 0x2000, 0);
    D_801F02F0[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801F02F0[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D9C2C[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B3188(void) {
    SvTask *p;
    SvTask *q;
    s32 k;

    p = (SvTask *)&D_80162978[D_8015169C];
    p->unk14->t[0] = p->unk4;
    p->unk14->t[1] = p->unk6;
    p->unk14->t[2] = p->unk8;
    func_8003A63C(&D_801F1374, p->unk14, &D_801F0304->m1);
    D_801F0304->scale.vx = D_801F0304->scale.vy = D_801F0304->scale.vz = p->pad18;
    func_8003B35C(&D_801F0304->m1, &D_801F0304->scale);
    func_8003B48C(&D_801F0304->m1);
    func_8003B51C(&D_801F0304->m1);
    D_80163C74 = func_800D29D4(&D_801F02F4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0xF) {
            p->unk0 = -1;
            return;
        }
        p->unk4 -= p->unkC;
        p->unk6 -= p->unkE;
        p->unk8 -= p->unk10;
        D_801F02E4 += 0xA0;
        if (D_801F02E4 >= 0x100) {
            do {
                q = (SvTask *)func_801B25E8((s32)func_801B30DC);
                k = 0x64;
                q->unk4 = p->unk4 - k + func_80042DA8() % 200;
                q->unk6 = p->unk6 - k + func_80042DA8() % 200;
                q->unk8 = p->unk8 - k + func_80042DA8() % 200;
                D_801F02E4 -= 0x100;
            } while (D_801F02E4 >= 0x100);
        }
    }
}

void func_801B3408(void) {
    MgObj20 *p;
    SvTask *q;
    MgSVec *v;
    s32 n;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = (p->unk2 * 0x400 & 0xFF) + 0x400;
        while (n >= 0x100) {
            q = (SvTask *)&D_80162978[func_800BBEAC(&func_801B3188)];
            q->unk6 = -0xBB8;
            q->unk4 = 0;
            q->unk8 = 0x3E8;
            D_801F030C->v.vx = func_80042DA8() & 0xFFF;
            D_801F030C->v.vy = 0x400;
            D_801F030C->v.vz = func_80042DA8() % 1024 - 0x200;
            func_8003C21C(&D_801F030C->v, &D_801F030C->m);
            v = (MgSVec *)&q->unkC;
            k = func_80042DA8() % 500 + 0x5DC;
            D_801F030C->v.vy = 0;
            D_801F030C->v.vz = 0;
            D_801F030C->v.vx = k;
            func_8003B2CC(&D_801F030C->m, (M2C_UNK *)&D_801F030C->v, (s32)v);
            func_800D44E8(v, &D_801F03F4[D_801F0308]);
            q->unk14 = &D_801F03F4[D_801F0308];
            D_801F0308 = (D_801F0308 + 1) % 60;
            n -= 0x100;
            q->pad18 = func_80042DA8() % 192 + 0x40;
        }
        p->unk2++;
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B3644(s32 *arg0, s32 k) {
    u8 *base;
    s16 *tri;
    s32 n;
    s32 i;
    s16 *a;
    s16 *b;
    s16 *c;
    SvShard *q;

    base = (u8 *)(arg0 + 1);
    tri = (s16 *)(base + *arg0);
    n = tri[0];
    tri += 2;
    for (i = 0; i < n; i++) {
        a = (s16 *)(base + tri[0]);
        b = (s16 *)(base + tri[1]);
        c = (s16 *)(base + tri[2]);
        D_801F92B8[k].x = (a[0] + b[0] + c[0]) / 3;
        D_801F92B8[k].y = (a[1] + b[1] + c[1]) / 3;
        D_801F92B8[k].z = (a[2] + b[2] + c[2]) / 3;
        D_801F0330[0].vx = b[0] - a[0];
        D_801F0330[0].vy = b[1] - a[1];
        D_801F0330[0].vz = b[2] - a[2];
        D_801F0330[1].vx = c[0] - b[0];
        D_801F0330[1].vy = c[1] - b[1];
        D_801F0330[1].vz = c[2] - b[2];
        func_8003BA68(&D_801F0330[0], &D_801F0330[1], &D_801F0330[2]);
        D_801F92B8[k].vx = (u32)(-D_801F0330[2].vx * 3) >> 7;
        D_801F92B8[k].vy = (u32)(-D_801F0330[2].vy * 3) >> 7;
        D_801F92B8[k].vz = (u32)(-D_801F0330[2].vz * 3) >> 7;
        q = &D_801F92B8[k];
        *(s16 *)((u8 *)q + 0x14) = 0;
        *(s16 *)((u8 *)q + 0x12) = 0;
        D_801F92C8[k].f0 = 0;
        D_801F92C8[k].f8 = func_80042DA8() % 256 - 0x80;
        D_801F92C8[k].fA = func_80042DA8() % 256 - 0x80;
        D_801F92C8[k].fC = func_80042DA8() % 256 - 0x80;
        k++;
        tri += 10;
    }
    return k;
}

void func_801B3938(s32 *arg0, s32 first, MgMat *m1, MgMat *m2) {
    s32 n;
    s32 i;

    n = *(s16 *)((u8 *)arg0 + *arg0 + 4);
    for (i = first; i < first + n; i++) {
        if (D_80062D98 == 0) {
            D_801F92B8[i].x += D_801F92B8[i].vx;
            D_801F92B8[i].y += D_801F92B8[i].vy;
            D_801F92B8[i].z += D_801F92B8[i].vz;
            D_801F92B8[i].vx = D_801F92B8[i].vx * 7 >> 3;
            D_801F92B8[i].vy = D_801F92B8[i].vy * 7 >> 3;
            D_801F92B8[i].vz = D_801F92B8[i].vz * 7 >> 3;
        }
        m1->t[0] = D_801F92B8[i].x;
        m1->t[1] = D_801F92B8[i].y;
        m1->t[2] = D_801F92B8[i].z;
        func_8003A63C(m2, m1, (MgMat *)(D_801F45B8 + i * 0x20));
    }
}

void func_801B3B10(void) {
    SvTask *p;
    s32 t;
    s32 q;

    p = (SvTask *)&D_80162978[D_8015169C];
    D_801F0338.v = D_801F0008[p->unk0];
    t = p->unk2;
    if (t < 0x19) {
        if (t < 5) {
            q = (t << 12) / 5;
            D_801F0348->scale.vx = D_801F0348->scale.vy = D_801F0348->scale.vz = q * 0x1200 >> 12;
        } else {
            D_801F0348->scale.vx = D_801F0348->scale.vy = D_801F0348->scale.vz = 0x1200;
        }
        func_8003A63C(&D_801F1374, p->unk14, &D_801F0348->m1);
        func_8003B35C(&D_801F0348->m1, &D_801F0348->scale);
        func_8003B48C(&D_801F0348->m1);
        func_8003B51C(&D_801F0348->m1);
        D_80163C74 = func_801B1364(&D_801F0338, D_801517C0 + 0x70, 0xC, D_80163C74);
    } else {
        t -= 0x19;
        if (t < 0x1E) {
            q = (t << 12) / 30;
            if (t == 0) {
                D_801F0348->scale.vx = D_801F0348->scale.vy = D_801F0348->scale.vz = 0x1200;
                func_8003B35C(p->unk14, &D_801F0348->scale);
            }
            func_8003C21C(&p->unk4, &D_801F0348->m1);
            if (D_80062D98 == 0) {
                p->unk4 += p->unkC;
                p->unk6 += p->unkE;
                p->unk8 += p->unk10;
            }
            func_8003A63C(&D_801F1374, p->unk14, &D_801F0348->m2);
            func_801B3938(D_801F0008[p->unk0], p->unk1A, &D_801F0348->m1, &D_801F0348->m2);
            func_8003B69C(0, 0, 0);
            D_801F0342 = q;
            D_80163C74 = func_801B1760(&D_801F0338, D_801517C0 + 0x70, 0xC, D_80163C74, D_801F45B8 + (*(s16 *)((u8 *)p + 0x1A) << 5));
        } else {
            p->unk0 = -1;
            return;
        }
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3E00(void) {
    MgObj20 *p;
    SvTask *q;
    MgMat *m;
    MgSVec *v;
    s32 k;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        k = 0;
        for (i = 0; i < 4; i++) {
            q = (SvTask *)&D_80162978[func_800BBEAC(&func_801B3B10)];
            q->unk0 = i;
            q->unk8 = 0;
            q->unk6 = 0;
            q->unk4 = 0;
            q->unkC = func_80042DA8() % 256 - 0x80;
            q->unkE = func_80042DA8() % 256 - 0x80;
            q->unk10 = func_80042DA8() % 256 - 0x80;
            v = &D_801F0310[i];
            m = &D_801F0B74[i];
            func_800D44E8(v, m);
            D_801F0B74[i].t[0] = D_801F0310[i].vx;
            D_801F0B74[i].t[1] = D_801F0310[i].vy;
            D_801F0B74[i].t[2] = D_801F0310[i].vz;
            q->unk14 = m;
            q->unk1A = k;
            k = func_801B3644((s32 *)D_801F0008[i], k);
        }
        p->unk0 = -1;
    }
}

void func_801B3FD4(void) {
    SvTask *p;

    p = (SvTask *)&D_80162978[D_8015169C];
    func_8003A63C(&D_801F1374, p->unk14, &D_801F0358->m);
    func_800D461C(&D_801F0358->m);
    D_801F0358->scale.vx = D_801F0358->scale.vy = D_801F0358->scale.vz = p->pad18;
    func_8003B35C(&D_801F0358->m, &D_801F0358->scale);
    func_8003B48C(&D_801F0358->m);
    func_8003B51C(&D_801F0358->m);
    D_801F0354[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801F0354[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D9CF4[0]) {
            p->unk0 = -1;
        }
    }
}

void func_801B40F0(void) {
    MgObj20 *p;
    SvTask *q;
    s32 i;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        for (i = 0; i < 4; i++) {
            q = (SvTask *)&D_80162978[func_800BBEAC((s32 *)func_801B3FD4)];
            k = 0x320;
            D_801F0368->v.vx = (u16)D_801F0310[i].vx - k + func_80042DA8() % 1600;
            D_801F0368->v.vy = 0;
            D_801F0368->v.vz = (u16)D_801F0310[i].vz - k + func_80042DA8() % 1600;
            func_800D44E8(&D_801F0368->v, &D_801F0BF4[D_801F035C]);
            func_8003C21C(&D_801F0360, &D_801F0368->m);
            func_8003B05C(&D_801F0BF4[D_801F035C], &D_801F0368->m);
            D_801F0BF4[D_801F035C].t[0] = D_801F0368->v.vx;
            D_801F0BF4[D_801F035C].t[1] = D_801F0368->v.vy;
            D_801F0BF4[D_801F035C].t[2] = D_801F0368->v.vz;
            q->unk14 = &D_801F0BF4[D_801F035C];
            q->pad18 = func_80042DA8() % 0x2000 + 0x4000;
            D_801F035C++;
        }
        p->unk2++;
        if (p->unk2 >= 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B4334(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;
    u16 temp_v1;
    u16 temp_v1_2;
    u16 temp_v1_3;

    temp_s0 = &D_80162978[D_8015169C];
    func_800D41FC(&D_801F1374, &D_801546EC, D_801F0374);
    temp_v1 = M2C_FIELD(D_801F0374, u16 *, 0x14);
    M2C_FIELD(D_801F2674, u16 *, 0x18) = temp_v1;
    M2C_FIELD(D_801F2674, u16 *, 4) = temp_v1;
    temp_v1_2 = M2C_FIELD(D_801F0374, u16 *, 0x18);
    M2C_FIELD(D_801F2674, u16 *, 0x1A) = temp_v1_2;
    M2C_FIELD(D_801F2674, u16 *, 6) = temp_v1_2;
    temp_v1_3 = M2C_FIELD(D_801F0374, u16 *, 0x1C);
    M2C_FIELD(D_801F2674, u16 *, 0x1C) = temp_v1_3;
    M2C_FIELD(D_801F2674, u16 *, 8) = temp_v1_3;
    func_8003B2CC(D_801F0374, &D_801F036C, D_801F2674 + 0x20);
    if (D_80062D98 == 0) {
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 >= 0x3C) {
            temp_s0->unk0 = -1;
        }
    }
}

void func_801B440C(void) {
    SvTask *p;
    SvTask *q;
    s32 t;
    s32 i;
    u8 pad[0x20];

    p = (SvTask *)&D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801F0020, &D_801F1374);
    func_800D41FC(&D_801F1374, &D_801546B8, &D_801F0384->m);
    func_8003B2CC(&D_801F0384->m, &D_801F037C, (s32)D_801F0384);
    D_801F1398.x = (u16)D_801F0384->v.vx + ((SvHW *)&D_801F0384->m.t[0])->v;
    D_801F1398.y = (u16)D_801F0384->v.vy + ((SvHW *)&D_801F0384->m.t[1])->v;
    D_801F1398.z = (u16)D_801F0384->v.vz + ((SvHW *)&D_801F0384->m.t[2])->v;
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 5) {
            func_800D52A0(0x800, 5);
            D_800F5B70[0] = D_800F5B70[1] = D_800F5B70[2] = 0;
        } else {
            t -= 5;
            if (t < 0x1E) {
                if (t == 0) {
                    func_801B274C((s32)&D_801F020C);
                    func_800BBEAC((M2C_UNK *)func_801B28A0);
                    q = (SvTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B2B1C)];
                    q->unk4 = 0;
                    q->unk6 = 0;
                    q->unk8 = 0;
                    func_800D55F4(0x22, 0x40, 0x264, 0x265, 0x266);
                }
            } else {
                t -= 0x1E;
                if (t >= 0x1E) {
                    t -= 0x1E;
                    if (t >= 0x14) {
                        t -= 0x14;
                        if (t < 0x19) {
                            if (t == 0) {
                                func_800D55F4(0x21, 0x40, 0x267, 0x268);
                            }
                        } else {
                            t -= 0x19;
                            if (t < 0xA) {
                                if (t == 0) {
                                    func_801B274C((s32)&D_801F0234);
                                    func_800BBEAC((M2C_UNK *)func_801B4334);
                                }
                            } else {
                                t -= 0xA;
                                if (t >= 0) {
                                    if (t < 0x32) {
                                        if (t == 0) {
                                            func_800BBEAC((M2C_UNK *)func_801B2FAC);
                                        }
                                    } else {
                                        t -= 0x32;
                                        if (t < 0x1E) {
                                            if (t == 0) {
                                                func_801B274C((s32)&D_801F0270);
                                                func_800BBEAC(&func_801B3408);
                                                func_800D55F4(0x22, 0x40, 0x269, 0x26A, 0x26B);
                                            }
                                        } else {
                                            t -= 0x1E;
                                            if (t < 0x23) {
                                                if (t == 0) {
                                                    func_800BBEAC((M2C_UNK *)func_801B3E00);
                                                    func_800BBEAC((M2C_UNK *)func_801B40F0);
                                                    func_800D55F4(0x22, 0x40, 0x26C, 0x26D, 0x26E);
                                                }
                                            } else {
                                                t -= 0x23;
                                                if (t < 0x14) {
                                                    if (t == 0) {
                                                        i = 0;
                                                        while (1) {
                                                            if ((D_801F1394 >> i) & 1) {
                                                                func_800D5774(i);
                                                            }
                                                            i++;
                                                            if (i >= 10) {
                                                                break;
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    func_800D52A0(0, 4);
                                                    D_800F8380 = 0;
                                                    p->unk0 = -1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        p->unk2++;
    }
}

void func_801B47B4(void) {
    MgObj20 *p;
    SvTask *q;
    u8 *cam;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    cam = D_80153BB8;
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t >= 0x22) {
            t -= 0x22;
            if (t < 0x4B) {
                if (t == 0) {
                    q = func_800D4FA8(1);
                    func_8003B2CC(&D_801F0020, (M2C_UNK *)&D_801F0388, (s32)D_801F0390);
                    q->unk4 = D_801F0390[0] + ((SvHW *)&D_801F0020.t[0])->v;
                    q->unk6 = D_801F0390[1] + ((SvHW *)&D_801F0020.t[1])->v;
                    q->unk8 = D_801F0390[2] + ((SvHW *)&D_801F0020.t[2])->v;
                    *(s16 *)((u8 *)q + 0x10) = ((SvHW *)&D_801F001A)->v + 0x800;
                    D_80153BBE = 0x1800;
                }
                k = (t << 12) / 75;
                D_801F0388.vy = (k * 2000 >> 12) - 0xBB8;
            } else {
                t -= 0x4B;
                if (t < 0x5A) {
                    if (t == 0x59) {
                        func_800D4FA8(2);
                        p->unk0 = -1;
                    }
                }
            }
        }
        func_8003B2CC(&D_801F0020, (M2C_UNK *)&D_801F0388, (s32)D_801F0390);
        *(u16 *)(cam + 0x168) = D_801F0390[0] + ((SvHW *)&D_801F0020.t[0])->v;
        *(u16 *)(cam + 0x16A) = D_801F0390[1] + ((SvHW *)&D_801F0020.t[1])->v;
        *(u16 *)(cam + 0x16C) = D_801F0390[2] + ((SvHW *)&D_801F0020.t[2])->v;
        p->unk2++;
    }
}

s32 func_801B49CC(arg0, arg1) {
    MgSVec v;
    u8 pad[8];
    s32 t;
    s32 a;

    func_800D2980(&D_801B4B1C, 0, 0, 0);
    D_801F1394 = arg0;
    func_800D54EC(arg0, &v);
    if (v.vz < D_80151A50[arg1][0]) {
        D_801F001A = 0x800;
        t = v.vz + 0x1388;
    } else {
        t = v.vz - 0x1388;
    }
    D_801F003C = t;
    func_8003C21C(&D_801F0018, &D_801F0020);
    func_801B249C();
    func_800BBEAC(&func_801B47B4);
    t = func_80042DA8() & 0x100;
    a = (s32)&D_801F0134;
    if (t) {
        a = (s32)&D_801F0060;
    }
    ((void (*)(s32, s32, s32))func_801B1300)(a, (s32)&D_801F0020, arg1);
    func_800BBEAC(&func_801B440C);
    func_801B25C4();
    func_800BBEAC((s32 *)func_801B2658);
    D_800F8380 |= 8;
}
