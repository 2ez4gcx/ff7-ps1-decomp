#include "common.h"
#include "magic_rollfire/decls.h"

void func_801B0000(void) {
    func_801B08C4();
}

void func_801B0020(MgTask *p) {
    s32 t;
    s16 y;
    s16 *frame;
    s16 n;

    t = func_80039A74(p->unk1A * p->unk2 / 20);
    y = p->unk6 + ((p->unkE * t) >> 12) + p->unk14;
    D_801BCE38->vy = y;
    if (y > 0) {
        D_801BCE38->vy = -func_80042DA8() % 100;
    }
    D_801BCE38->vx = p->unk4 + ((p->unkC * t) >> 12);
    D_801BCE38->vz = p->unk8 + ((p->unk10 * t) >> 12);
    frame = &D_801BCE34;
    *frame = p->unk2 * 10 / p->unk1E;
    func_800D4368(D_801BCE38, 0x1800, -0x180);
    D_801DCE60 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801DCE60);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= p->unk1E) {
            p->unk0 = -1;
        } else {
            p->unk14 += p->unk16;
            p->unk16 += p->unk18;
        }
    }
}

void func_801B0230(void) {
    MgObj20 *p;
    s32 i;
    s32 off;
    s32 n;

    n = 0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 200; i++) {
        off = i * 0x20;
        if (*(s16 *)(&D_801DCE6C + off) != -1) {
            func_801B0020(&D_801DCE6C + off);
            n++;
        }
    }
    if (n == 0 && D_80162080 < 3) {
        p->unk0 = -1;
    }
}

void func_801B02F4(void) {
    s32 off;
    s16 c;

    c = -1;
    off = 0x18E0;
    do {
        *(s16 *)(&D_801DCE6C + off) = c;
        off -= 0x20;
    } while (off >= 0);
}

MgObj20 *func_801B0320(void) {
    s32 i;
    s32 off;

    for (i = 0; i < 200; i++) {
        off = i * 0x20;
        if (*(s16 *)(&D_801DCE6C + off) == -1) {
            *(s16 *)(&D_801DCE6C + off) = 0;
            *(s16 *)(&D_801DCE6C + 2 + off) = 0;
            return (MgObj20 *)(&D_801DCE6C + off);
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_rollfire/nonmatchings/text", func_801B0384);

void func_801B0610(void) {
    MgObj20 *p;
    s32 off;
    s32 i;
    s32 y;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_801B02F4();
            func_800BBEAC(func_801B0230);
        }
        if (p->unk2 == 0) {
            func_800D55F4(0x20, 0x40, 0x88);
        }
        if ((u32)(u16)p->unk2 < 0x3A) {
            func_800D41FC(&D_800FA63C, D_80151AC0[D_801DCE68], &D_801BCE5C->m);
            func_8003B48C(&D_801BCE5C->m);
            off = 0;
            func_8003B51C(&D_801BCE5C->m);
            do {
                func_8003BC6C(D_801BCE3C + off, &D_801BCE5C->v, &D_801BCE5C->flag);
                D_801BCE5C->a.vx = D_801BCE5C->v.vx;
                D_801BCE5C->a.vy = D_801BCE5C->v.vy;
                D_801BCE5C->a.vz = D_801BCE5C->v.vz;
                D_801BCE5C->b.vx = *(u16 *)(D_801BCE3C + off) << 3;
                y = *(u16 *)(D_801BCE3C + 2 + off) << 3;
                D_801BCE5C->b.vz = 0x960;
                D_801BCE5C->b.vy = y;
                func_8003ACE4(&D_801BCE5C->b, &D_801BCE5C->v, y);
                off += 8;
                D_801BCE5C->b.vx = D_801BCE5C->v.vx;
                D_801BCE5C->b.vy = D_801BCE5C->v.vy;
                D_801BCE5C->b.vz = D_801BCE5C->v.vz;
                func_801B0384(&D_801BCE5C->a, &D_801BCE5C->b, p->unk2, 2);
            } while (off < 0x20);
        }
        if (p->unk2 == 0x32) {
            i = 0;
            do {
                if ((D_801DCE64 >> i) & 1) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
        }
        if (p->unk2 == 0x4E) {
            func_800D55F4(0x20, 0x40, 0);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0864(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DCE60 = D_801BCE60 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B08C4(arg0, arg1) {
    func_800D2980(D_801B093C, 0, 0, 0);
    D_801DCE64 = arg0;
    D_801DCE68 = arg1;
    func_800BBEAC(func_801B0864);
    return func_800BBEAC(func_801B0610);
}
