#include "common.h"
#include "magic_netsu/decls.h"

void func_801B0000(void) {
    func_801B0D0C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EE21C = D_801D621C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgObj20 *temp_s0;
    s16 temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    D_80163C74 = func_800C4FC8(D_801D615C, 0, 0);
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 < 0x10) {
            D_801D615C = (u16) D_801D615C + 0xF;
        }
        if (temp_s0->unk2 >= 0x11) {
            D_801D615C = (u16) D_801D615C - 0xF;
        }
        temp_v0 = (u16) temp_s0->unk2 + 1;
        temp_s0->unk2 = temp_v0;
        if (temp_v0 == 0x20) {
            temp_s0->unk0 = -1;
        }
    }
}

void func_801B016C(void) {
    MgMat m;
    MgMat m2;
    MgSVec rot;
    MgTask *p;
    u8 *r;
    u8 c;
    u8 *q;
    u16 *h;
    s32 t;
    s32 u;
    s16 n;

    rot.vz = 0;
    rot.vx = 0;
    rot.vy = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    D_801D620C.vx = D_801D620C.vy = D_801D620C.vz = p->unk2 << 10;
    func_8003B35C(&m, &D_801D620C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    D_801D6160.unk0 = D_801D1070;
    D_801D6160.unk4 = 0xA8;
    t = D_801D61A4;
    D_801D6160.unkA = 0x1000 - (t << 7);
    r = func_800D29D4(&D_801D6160, D_801517C0 + 0x70, 0xC, D_801EE21C);
    D_801EE21C = r;
    D_801D6160.unk0 = D_801D6170[p->unk2 % 10];
    D_801D6160.unk4 = 0x28;
    D_801D6160.unkA = D_801D61A4 * 8;
    D_801EE21C = func_800D29D4(&D_801D6160, D_801517C0 + 0x70, 0xC, r);
    func_800D4368(&p->unk4, 0x2000, 0);
    q = &D_801D619C;
    c = D_801D61A4 * 8;
    D_801D619E = c;
    D_801D619D = c;
    *q = c;
    D_801EE21C = func_800D4D90(q - 4, D_801517C0 + 0x70, 0xC, D_801EE21C);
    if (D_80062D98 == 0) {
        h = &D_801031EA;
        u = *h + 0x20;
        *h = u - p->unk2 % 2 * 64;
        if (p->unk2 >= 0xF) {
            D_801D61A4--;
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0430(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D61B0;
    *frame = p->unk2;
    D_801EE21C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EE21C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D601C) {
            p->unk0 = -1;
        }
    }
}

void func_801B04EC(void) {
    MgMat m;
    MgMat m2;
    MgSVec rot;
    MgTask *p;
    s16 n;

    rot.vy = 0;
    rot.vx = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vz = p->unk14;
    func_8003BF8C(&rot, &m);
    func_8003B35C(&m, D_801D61B4);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    D_801D61CE[0] = 0x80 - p->unk2 * 8;
    *(s32 *)&D_801D61CE[-5] = D_801D61D4[p->unk16];
    D_801EE21C = func_800D29D4(&D_801D61CE[-5], D_801517C0 + 0x70, 0xC, D_801EE21C);
    if (D_80062D98 == 0) {
        p->unk6 -= 0x64;
        p->unk14 += 0x100;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 15) {
            p->unk0 = -1;
        }
    }
}

void func_801B0644(void) {
    MgTask *p;
    u8 c;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D61EC[0] = p->unk16;
    c = 0x80 - p->unk2 * 8;
    D_801D61EA = c;
    D_801D61E9 = c;
    D_801D61E8 = c;
    D_801EE21C = func_800D4D90(&D_801D61EC[-4], D_801517C0 + 0x70, 0xC, D_801EE21C);
    if (D_80062D98 == 0) {
        p->unk6 -= 300;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 15) {
            p->unk0 = -1;
        }
    }
}

void func_801B072C(void) {
    MgVec v;
    MgSVec rot;
    MgMat m2;
    MgMat m;
    MgTask *p;
    MgTask *q;
    u8 *w;
    u8 c;
    s16 ang;
    s16 i;
    s32 k;
    s16 n;

    rot.vx = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    rot.vy = p->unk2 << 6;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    v.vx = v.vy = v.vz = p->unk2 * 0x7D0;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    D_801D61FA[0] = 0x80 - p->unk2 * 6;
    D_801EE21C = func_800D29D4(&D_801D61FA[-5], D_801517C0 + 0x70, 0xC, D_801EE21C);
    rot.vy = 0;
    rot.vz = 0;
    rot.vx = 0x400;
    func_8003BF8C(&rot, &m);
    v.vx = v.vy = v.vz = p->unk2 * 0x320;
    func_8003B35C(&m, &v);
    m.t[0] = p->unk4;
    m.t[1] = 0;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    w = &D_801D6204;
    c = -0x80 - p->unk2 * 6;
    D_801D6206 = c;
    D_801D6205 = c;
    *w = c;
    D_801EE21C = func_800D4D90(w - 4, D_801517C0 + 0x70, 0xC, D_801EE21C);
    i = 0;
    if (D_80062D98 == 0) {
        k = p->unk2 * 0xF0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0644)];
            ang = func_80042DA8() % 0x1000;
            q->unk4 = (func_80039B40(ang) * (s16)k) >> 12;
            q->unk8 = (func_80039A74(ang) * (s16)k) >> 12;
            q->unk6 = 0;
            q->unk16 = func_80042DA8() % 16;
            i++;
        } while (i < 2);
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B04EC)];
        ang = func_80042DA8() % 0x1000;
        q->unk4 = (func_80039B40(ang) * (s16)k) >> 12;
        q->unk8 = (func_80039A74(ang) * (s16)k) >> 12;
        q->unk6 = 0;
        q->unk16 = func_80042DA8() % 4;
        q->unk14 = func_80042DA8() % 0x1000;
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0430)];
            ang = func_80042DA8() % 0x1000;
            q->unk4 = (func_80039B40(ang) * (s16)k) >> 12;
            q->unk8 = (func_80039A74(ang) * (s16)k) >> 12;
            q->unk6 = 0;
            i++;
        } while (i < 4);
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0BB0(void) {
    u8 pad[0x30];
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 k;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            k = -0x4B0;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B016C)];
            q->unk4 = 0;
            q->unk6 = k;
            q->unk8 = 0;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B072C)];
            q->unk4 = 0;
            q->unk6 = k;
            q->unk8 = 0;
        }
        if (p->unk2 == 0xC) {
            func_800BBEAC(func_801B008C);
        }
        if (p->unk2 == 0x1C) {
            func_800D52A0(0, 0x10);
        }
        if (p->unk2 == 0x23) {
            for (i = 0; i < 10; i++) {
                if ((D_801EE220 >> i) & 1) {
                    func_800D5774(i);
                }
            }
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B0D0C(arg0, arg1) {
    MgObj20 *p;

    func_800BBEAC(func_801B0020);
    func_800D2980(D_801B0DCC, 0, 0, 0);
    D_801EE220 = arg0;
    p = &D_80162978[func_800BBEAC(func_801B0BB0)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D54EC(arg0, &p->pad[4]);
}
