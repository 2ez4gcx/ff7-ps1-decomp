#include "common.h"
#include "magic_aqua/decls.h"

void func_801B0054(void) {
    func_801B0680();
}

void func_801B0074(void) {
    MgTask *p;
    s32 i;
    s32 k;
    s16 v;
    u16 w;

    p = &D_80162978[D_8015169C];
    k = p->unk18;
    for (i = 0; i < 2; i++) {
        v = D_801D89A8[k].v[5];
        func_800D4368(&D_801D89A8[k], v, -(v >> 2));
        D_801D8998 = func_800D4D90(D_801C098C, D_801517C0 + 0x70, 0xC, D_801D8998);
        if (D_80062D98 == 0) {
            if (p->unk2 < 6) {
                w = D_801D89A8[k].v[5] + D_801D89A8[k].v[6];
                D_801D89A8[k].v[5] = w;
                if ((s16)w >= 0x7001) {
                    D_801D89A8[k].v[5] = 0x7000;
                }
            } else if (p->unk2 >= 7) {
                w = D_801D89A8[k].v[5] - D_801D89A8[k].v[7];
                D_801D89A8[k].v[5] = w;
                if ((s16)w < 0) {
                    D_801D89A8[k].v[5] = 0;
                }
            } else {
                D_801D89A8[k].v[5] = D_801D89A8[k].v[4];
            }
        }
        k++;
        if (k >= 0xDE) {
            k = 0;
        }
    }
    if (p->unk2 >= 0xD) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0254(void) {
    MgTask *b;
    MgTask *p;
    s32 i;
    s32 k;
    s32 o;
    s32 u;
    s32 r;
    s32 q;
    s32 t;
    s32 c;
    s16 w;

    if (D_80062D98 == 0) {
        b = D_80162978;
        p = &b[D_8015169C];
        if ((u16)(p->unk2 - 2) < 0x1FU) {
            do {
                k = D_801D89A4;
                i = 0;
                b[func_800BBEAC(func_801B0074)].unk18 = k;
                o = k * 0x10;
            } while (0);
            do {
                r = func_80042DA8();
                u = r % 0x1000 + 0x800;
                *(u16 *)((u8 *)D_801D89A8 + o) = (u16)p->unk4 + func_80042DA8() % p->unkE - (u16)p->unkC;
                k++;
                *(u16 *)((u8 *)D_801D89A8 + o + 2) = (u16)p->unk6 - func_80042DA8() % p->unk12 + (u16)p->unk10;
                *(u16 *)((u8 *)D_801D89A8 + o + 4) = (u16)p->unk8 + func_80042DA8() % p->unkE - (u16)p->unkC;
                t = p->unk14 * u >> 12;
                *(u16 *)((u8 *)D_801D89A8 + o + 8) = t;
                *(u16 *)((u8 *)D_801D89A8 + o + 10) = 0;
                q = t / 6;
                *(u16 *)((u8 *)D_801D89A8 + o + 12) = q;
                *(u16 *)((u8 *)D_801D89A8 + o + 14) = q;
                o += 0x10;
                if (k >= 0xDE) {
                    o = 0;
                    k = 0;
                }
                i++;
            } while (i < 2);
            D_801D89A4 = k;
        }
        if (p->unk2 < 8) {
            D_800F5B71.v = 0;
            D_800F5B70.v = 0;
            D_800F5B72.v = 0x30;
            w = p->unk2 * 0x180;
        } else {
            w = 0xC00;
            if (p->unk2 >= 0x28) {
                c = 0xC00 - (p->unk2 - 0x28) * 0x180;
                w = c;
                if ((s16)c < 0) {
                    w = 0;
                }
            }
        }
        if (p->unk2 == 0x28) {
            i = 0;
            do {
                if ((1 << i) & D_801D89A0) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
        }
        if (p->unk2 >= 0x30) {
            w = 0;
            D_800F5B72.v = 0;
            p->unk0 = -1;
        }
        D_800F5B74.v = w;
        p->unk2++;
    }
}

void func_801B05C4(void) {
    MgTask *p;
    MgTask *base;
    s32 t;
    s32 n;

    D_80162978[D_8015169C].unk0 = -1;
    n = func_800BBEAC(&func_801B0254);
    base = D_80162978;
    p = base + n;
    func_800D54EC(D_801D89A0, &p->unk4);
    p->unk6 = -0x600;
    p->unkC = 0xA00;
    p->unkE = 0x1400;
    p->unk14 = 0xBB3;
    t = (s16)*(u16 *)&p->unk6 >> 1;
    p->unk10 = -t;
    p->unk12 = -t * 3;
    p->unk10 = *(u16 *)&p->unk10 * 2;
}

INCLUDE_RODATA("../asm/us/magic_aqua/nonmatchings/text", D_801B0000);

void func_801B0680(arg0) {
    D_801D899C = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(D_801B0720, 0, 0, 0);
    func_800BBEAC(func_801B05C4);
    D_801D89A0 = arg0;
    D_801D89A4 = 0;
    func_800D55F4(0x20, func_800D574C(arg0), 0x9D);
}
