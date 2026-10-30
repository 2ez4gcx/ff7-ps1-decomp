#include "common.h"
#include "magic_hyper/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B254C();
    return &D_801D2440;
}

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B0A50);

s32 func_801B1160(void) {
    MgSVec *q;
    s16 i;
    s16 a;
    s16 ang;
    s32 r1;
    s32 r2;
    s32 r3;

    i = 0;
    do {
        r1 = func_80042DA8();
        a = r1 % 200;
        r2 = func_80042DA8();
        ang = r2 % 0x1000;
        q = &D_801EC7A0[i];
        q->vz = 0;
        q->vy = 0;
        D_801EC7A0[i].vx = 0;
        D_801ECD20[i].vx = func_80039B40(ang) * a >> 12;
        D_801ECD20[i].vz = func_80039A74(ang) * a >> 12;
        r3 = func_80042DA8();
        D_801ECD20[i].vy = -r3 % 100 - 0x64;
        i++;
    } while (i < 0xB0);
}

void func_801B12E8(void) {
    s16 i;

    i = 0;
    do {
        D_801EC7A0[i].vx += D_801ECD20[i].vx;
        D_801EC7A0[i].vy += D_801ECD20[i].vy;
        D_801EC7A0[i].vz += D_801ECD20[i].vz;
        D_801ECD20[i].vy += 0x14;
        if (D_801EC7A0[i].vy > 0) {
            D_801EC7A0[i].vy = 0;
            D_801ECD20[i].vy = -D_801ECD20[i].vy;
        }
        i++;
    } while (i < 0xB0);
}

void func_801B1424(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EC780 = D_801D4780 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B1490(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D46A4;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D2374) {
            p->unk0 = -1;
        }
    }
}

void func_801B1548(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D46B0;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk4.vx += p->unkC.vx;
        p->unk4.vy += p->unkC.vy;
        p->unk4.vz += p->unkC.vz;
        p->unk2++;
        if (p->unk2 == D_801D22AC) {
            p->unk0 = -1;
        }
    }
}

void func_801B1630(void) {
    MgMat m;
    MgMat lw;
    MgVec sc;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801D46B4, &m);
    sc.vx = sc.vy = sc.vz = p->unk2 * 0x4B0;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801D46C6[0] = p->unk2 * 0xC8;
    *(s32 *)&D_801D46C6[-5] = (s32)D_801D46CC[p->unk1A];
    D_801EC780 = func_800D29D4(&D_801D46C6[-5], D_801517C0 + 0x70, 0xC, D_801EC780);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B179C(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    MgTask *p;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 >= 0x14) {
        v = (p->unk2 - 0x14) * 0xC8;
    } else {
        v = 0;
    }
    D_801D46DE[0] = v;
    rot.vx = p->unkC + ((func_80039A74(p->unk2 << 9) << 6 >> 12) * p->unk1A);
    rot.vy = p->unkE;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    D_801D46E8[0] = p->unk18;
    func_8003B35C(&m, (MgVec *)&D_801D46E8[-1]);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801EC780 = func_800D29D4(D_801D46D4, D_801517C0 + 0x70, 0xC, D_801EC780);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x14) {
            p->unk18 += 0x78;
        }
        p->unkE += p->unk14;
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B1958(void) {
    MgMat m;
    MgMat m2;
    MgMat lw;
    MgObjAwa *p;
    s16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D4714, &m);
    func_8003B35C(&m, &D_801D4704);
    m.t[0] = p->unk4.vx;
    m.t[1] = p->unk4.vy;
    m.t[2] = p->unk4.vz;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003C21C(&D_801D4714, &m2);
    func_8003C73C(p->unk2 << 8, &m2);
    func_8003B69C(0, 0, 0);
    frame = &D_801D46FE;
    *frame = 0x80 - p->unk2 * 6;
    D_801EC780 = func_801B0028((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801EC780, D_801EC7A0, &lw, &m2);
    if (D_80062D98 == 0) {
        func_801B12E8();
        p->unk2++;
        if (p->unk2 == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B1AC0(void) {
    MgMat m;
    u8 pad1[0x20];
    MgMat lw;
    MgTask *p;
    MgTask *q;
    u8 *tab;
    s16 t;
    MgSVec *ba;
    MgSVec *bb;
    MgSVec *bd;
    MgSVec *pa;
    MgSVec *pb;
    MgSVec *pd;
    s16 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801D472C, &m);
    D_801D471C.vx = D_801D471C.vy = D_801D471C.vz = p->unk2 * 0xC8 + 0x2000;
    func_8003B35C(&m, &D_801D471C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    tab = D_801CE7FC;
    D_801D4734[0] = tab;
    D_801EC780 = func_800D29D4(D_801D4734, D_801517C0 + 0x70, 0xC, D_801EC780);
    D_801D4734[0] = D_801CF720;
    D_801EC780 = func_800D29D4(D_801D4734, D_801517C0 + 0x70, 0xC, D_801EC780);
    D_801D4734[0] = D_801CE0C0;
    D_801EC780 = func_800D29D4(D_801D4734, D_801517C0 + 0x70, 0xC, D_801EC780);
    if (D_80062D98 == 0) {
        t = p->unk2;
        ba = D_801D1468;
        bb = D_801D17F8;
        bd = (MgSVec *)(tab + 4);
        i = 0;
        do {
            pa = &ba[i];
            pb = &bb[i];
            pd = &bd[i];
            pd->vx = pa->vx + (pb->vx - pa->vx) * t / 20;
            pd->vy = pa->vy + (pb->vy - pa->vy) * t / 20;
            pd->vz = pa->vz + (pb->vz - pa->vz) * t / 20;
            i++;
        } while (i < 0x72);
        ba = D_801D1B88;
        bb = D_801D1F18;
        bd = D_801CF724;
        i = 0;
        do {
            pa = &ba[i];
            pb = &bb[i];
            pd = &bd[i];
            pd->vx = pa->vx + (pb->vx - pa->vx) * t / 20;
            pd->vy = pa->vy + (pb->vy - pa->vy) * t / 20;
            pd->vz = pa->vz + (pb->vz - pa->vz) * t / 20;
            i++;
        } while (i < 0x72);
        p->unk2++;
        if (p->unk2 == 0x14) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1958)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            func_800BBA84(0x98, p->unk1E, 0);
            p->unk0 = -1;
        }
    }
}

void func_801B1EA4(void) {
    MgMat m;
    MgMat lw;
    MgMat m3;
    u8 pad[8];
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D3994(p->unk1E, D_80151916[p->unk1E][0], &p->unk4);
    func_800D44E8(&D_801EC798, &m3);
    func_8003C21C(&D_801D4760, &m);
    func_8003A79C(&m3, &m, &m);
    func_8003B35C(&m, &D_801D4750);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801EC780 = func_800D29D4(D_801D4768, D_801517C0 + 0x70, 0xC, D_801EC780);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B2014(void) {
    u8 pad[8];
    MgSVec v;
    u8 pad2[8];
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 ang;
    s16 t;
    s32 r;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        func_800D3994(p->unk1E, D_8015190F[p->unk1E][0], &v);
        D_801EC798.vx = v.vx - D_801EC790.vx;
        D_801EC798.vy = v.vy - D_801EC790.vy;
        D_801EC798.vz = v.vz - D_801EC790.vz;
        D_801EC790.vx = v.vx;
        D_801EC790.vy = v.vy;
        D_801EC790.vz = v.vz;
        if (p->unk2 == 0x1C) {
            func_800BBA84(0x30, p->unk1E, 0);
        }
        if (p->unk2 == 0x36) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1EA4)];
            q->unk1E = p->unk1E;
            func_800BBA84(0xD4, p->unk1E, 0);
        }
        if (p->unk2 == 0x3C) {
            func_800D3994(p->unk1E, D_8015190F[p->unk1E][0], &p->unk4);
            p->unk6 = 0;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1630)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            t = p->unk8;
            q->unk1A = 0;
            q->unk8 = t;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1490)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B179C)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unkC = (i / 4 << 8) + 0x200;
                q->unkE = i * 0x400;
                q->unk14 = 0x100;
                q->unk18 = 0x3E8;
                q->unk1A = i / 4 * 2 - 1;
                i++;
            } while (i < 8);
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1AC0)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            func_800BBA84(0x98, p->unk1E, 0);
        }
        if ((u32)((u16)p->unk2 - 0x3C) < 6 && !((u16)p->unk2 & 1)) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1630)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk6 += D_801D4778[(p->unk2 - 0x3C) / 2];
            q->unk1A = 1;
        }
        if ((u32)((u16)p->unk2 - 0x3C) < 0x14) {
            i = 0;
            do {
                r = func_80042DA8();
                ang = r % 0x1000;
                q = (MgTask *)&D_80162978[func_800BBEAC(func_801B1548)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unkC = (u32)(func_80039A74(ang) * 0x4B) >> 10;
                q->unk10 = (u32)(func_80039B40(ang) * 0x4B) >> 10;
                q->unkE = -func_80042DA8() % 100;
                i++;
            } while (i < 3);
        }
        if (p->unk2 == 0x50) {
            i = 0;
            do {
                if (D_801EC784 >> i & 1) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
            func_800BBA84(0xFA, p->unk1E, 0);
        }
        p->unk2++;
        if (p->unk2 == 0x64) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B254C(arg0, arg1) {
    func_800BBEAC(func_801B1424);
    func_800D2980(D_801B25E8, 0, 0, 0);
    D_801EC784 = arg0;
    func_800D54EC(arg0, D_801EC788);
    D_80162996[func_800BBEAC(func_801B2014)].unk0 = arg1;
    return func_801B1160();
}
