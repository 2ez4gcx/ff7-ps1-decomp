#include "common.h"
#include "magic_aeroga/decls.h"

void func_801B0000(void) {
    func_801B09F0();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C9A48 = D_801B1A48 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(MgPart *p) {
    MgSVec a;
    MgSVec b;
    MgSVec c;
    MgSVec d;
    MgRgb ca;
    MgRgb cb;
    s32 ext;
    s32 flag;
    u8 *q;
    s32 r;
    s32 code;
    s32 k;

    code = 0x3A000000;
    func_8003B48C(D_800FA63C);
    func_8003B51C(D_800FA63C);
    a.vx = p->unk4;
    a.vy = p->unk6 - 0x32;
    a.vz = p->unk8;
    b.vx = p->unkC;
    b.vy = p->unkE - 0x32;
    b.vz = p->unk10;
    c.vx = p->unk4;
    c.vy = p->unk6 + 0x32;
    c.vz = p->unk8;
    d.vx = p->unkC;
    q = D_801C9A48;
    d.vy = p->unkE + 0x32;
    d.vz = p->unk10;
    r = func_8003BD7C(&a, &b, &c, &d, q + 8, q + 0x10, q + 0x18, q + 0x20, &ext, &flag);
    if (r > 0) {
        ca.r = D_801B0A68[p->unk2 % 7].r * (s16)D_801B0A64 >> 1;
        ca.g = D_801B0A68[p->unk2 % 7].g * (s16)D_801B0A64 >> 1;
        ca.b = D_801B0A68[p->unk2 % 7].b * (s16)D_801B0A64 >> 1;
        cb.r = D_801B0A68[(p->unk2 + 1) % 7].r * (s16)D_801B0A64 >> 1;
        cb.g = D_801B0A68[(p->unk2 + 1) % 7].g * (s16)D_801B0A64 >> 1;
        cb.b = D_801B0A68[(p->unk2 + 1) % 7].b * (s16)D_801B0A64 >> 1;
        *(s32 *)q = 0x08000000;
        *(s32 *)(q + 4) = *(s32 *)(q + 0x14) = ca.r | code | (ca.g << 8) | (ca.b << 16);
        *(s32 *)(q + 0xC) = *(s32 *)(q + 0x1C) = cb.r | code | (cb.g << 8) | (cb.b << 16);
        k = 0x70;
        func_80046794(((r >> 2) << 2) + k + D_801517C0, q);
        D_801C9A48 = q + 0x24;
    }
    if (D_80062D98 == 0) {
        p->unk2 += 2;
        if (p->unk2 >= 0x10) {
            p->unk0 = 0;
        }
    }
}

void func_801B04E8(void) {
    MgObj14 *p;
    s32 off;
    s32 i;

    i = 0;
    p = D_801B0AA8;
    off = 0;
    do {
        if (*(s16 *)((u8 *)D_801B0AA8 + off) != 0) {
            func_801B008C(p);
        }
        off += 0x14;
        i++;
        p++;
    } while (i < 200);
}

MgObj14 *func_801B055C(void) {
    s32 i;

    for (i = 0; i < 200; i++) {
        if (D_801B0AA8[i].unk0 == 0) {
            D_801B0AA8[i].unk0 = 1;
            return &D_801B0AA8[i];
        }
    }
    return NULL;
}

void func_801B05A8(void) {
    MgTask *p;
    MgPart *q;
    MgSVec a;
    MgSVec b;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            b.vx = func_80039B40(p->unk14) * p->unk16 >> 12;
            b.vz = func_80039A74(p->unk14) * p->unk16 >> 12;
            p->unk14 += 0x100;
            p->unk16 += p->unk18;
            a.vx = func_80039B40(p->unk14) * p->unk16 >> 12;
            a.vz = func_80039A74(p->unk14) * p->unk16 >> 12;
            q = (MgPart *)func_801B055C();
            if (q != NULL) {
                q->unk4 = a.vx + p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = a.vz + p->unk8;
                q->unkC = b.vx + p->unk4;
                q->unkE = p->unk6;
                q->unk10 = b.vz + p->unk8;
                q->unk2 = 1 - i;
            }
            i++;
        } while (i < 2);
        if (D_801B0A66 != 0) {
            p->unk0 = -1;
        }
    }
}

void func_801B0754(void) {
    MgTask *p;
    MgTask *q;
    s32 h;
    s32 a;
    s32 r;
    s32 b;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B04E8();
    if (D_80062D98 == 0) {
        if ((u16)p->unk2 < 0x10 && !(p->unk2 & 1)) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B05A8)];
            h = D_801B0A94[p->unk2 >> 1];
            q->unk4 = p->unkC;
            r = func_80042DA8();
            b = (h << 7) + (u16)p->unkE;
            q->unk6 = r % 100 + b - 0x232;
            a = (h << 0x17) >> 0xF;
            q->unk8 = p->unk10;
            q->unk16 = (func_80039A74(a) * 0x258 >> 12) + 0xC8;
            q->unk18 = (func_80039A74(a) * 5 >> 12) + 5;
            q->unk14 = func_80042DA8() % 0x1000;
        }
        if (p->unk2 == 0x32) {
            func_800D5774(p->unk1C);
        }
        if (p->unk2 >= 0x2D) {
            D_801B0A64--;
        }
        p->unk2++;
        if (p->unk2 == 0x3C) {
            D_801B0A66 = 1;
            p->unk0 = -1;
        }
    }
}

void func_801B095C(s32 arg0) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0754)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    func_800BBA84(0xA3, arg0, 0x40);
}

s32 func_801B09F0(arg0, arg1) {
    s32 i;

    func_800BBEAC(func_801B0020);
    func_800D5444(arg0, arg1, 4, &func_801B095C);
    for (i = 0xF8C; i >= 0; i -= 0x14) {
        *(s16 *)((u8 *)D_801B0AA8 + i) = 0;
    }
}
