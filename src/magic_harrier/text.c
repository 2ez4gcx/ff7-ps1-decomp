#include "common.h"
#include "magic_harrier/decls.h"

void func_801B0000(void) {
    func_801B0D58();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E140C = D_801C940C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgMat m;
    MgTask *p;
    s16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003C21C(&D_801C93A8, &m);
    func_8003A79C(&D_801E1410, &m, &m);
    func_8003B35C(&m, &D_801C93B0);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    frame = &D_801C93A4;
    *frame = p->unk2 % D_801C9338;
    D_801E140C = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801E140C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B01D8(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, D_801C93D8[p->unk1A], 0);
    D_801C93C0[0] = (s32)D_801C93CC[p->unk1A];
    D_801C93C8 = p->unk2;
    D_801E140C = (u8 *)func_800D4D90(D_801C93C0, D_801517C0 + 0x70, 0xC, (s32)D_801E140C);
    if (D_80062D98 == 0) {
        if (p->unk1A == 0) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
        }
        if (++p->unk2 >= D_801C93CC[p->unk1A][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0324(void) {
    MgMat m;
    MgMat m2;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801C9400, &m);
    func_8003A79C(&D_801E1410, &m, &m);
    func_8003B35C(&m, &D_801C93E0);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    D_801C93F0[0] = D_801B0DD4;
    D_801E140C = (u8 *)func_800D29D4(D_801C93F0, D_801517C0 + 0x70, 0xC, (s32)D_801E140C);
    D_801C93F0[0] = D_801B0EB8;
    D_801E140C = (u8 *)func_800D29D4(D_801C93F0, D_801517C0 + 0x70, 0xC, (s32)D_801E140C);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;

        p->unk8 += p->unk10;
        if (++p->unk2 == 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B04B4(void) {
    u8 pad0[8];
    MgSVec a;
    u16 b[4];
    MgSVec c;
    u8 pad[0x20];
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 ang;
    s32 k;
    s32 m;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            c.vx = 0;
            c.vy = 0;
            c.vz = 0xC8;
            D_801E1410.t[0] = p->unk4;
            D_801E1410.t[1] = p->unk6;
            D_801E1410.t[2] = p->unk8;
            func_8003B48C(&D_801E1410);
            func_8003B51C(&D_801E1410);
            func_8003BADC(&c, (MgSVec *)&p->unk4, &flag);
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B008C)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
        }
        if (p->unk2 < 0xF) {
            D_801E1410.t[0] = p->unk4;
            D_801E1410.t[1] = p->unk6;
            D_801E1410.t[2] = p->unk8;
            func_8003B48C(&D_801E1410);
            func_8003B51C(&D_801E1410);
            b[0] = (p->unkC - p->unk4) / 8;
            b[1] = (p->unkE - p->unk6) / 8;
            b[2] = (p->unk10 - p->unk8) / 8;
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0324)];
                k = i * 0x555;
                a.vx = func_80039B40((p->unk2 << 9) + k) >> 5;
                a.vy = func_80039A74((p->unk2 << 9) + k) >> 5;
                a.vz = func_80042DA8() % 100 - 0x32;
                func_8003BADC(&a, (MgSVec *)&q->unk4, &flag);
                q->unkC = b[0];
                q->unkE = b[1];
                i++;
                q->unk10 = b[2];
            } while (i < 3);
        }
        if ((u16)p->unk2 - 5 < 0xAU) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B01D8)];
            func_800D3994(p->unk1C, D_8015190F[D_800FA6D4][0], &q->unk4);
            m = 0x190;
            q->unk4 = (u16)q->unk4 - m + func_80042DA8() % 800;
            q->unk6 = (u16)q->unk6 - m + func_80042DA8() % 800;
            q->unk8 = (u16)q->unk8 - m + func_80042DA8() % 800;
            q->unk1A = 1;
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B01D8)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            m = 0x190;
            q->unk4 = (u16)q->unk4 - m + func_80042DA8() % 800;
            q->unk6 = (u16)q->unk6 - m + func_80042DA8() % 800;
            q->unk8 = (u16)q->unk8 - m + func_80042DA8() % 800;
            q->unk1A = 2;
        }
        if ((u16)p->unk2 - 0x10 < 3U) {
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B01D8)];
                func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
                m = 0x190;
                q->unk4 = (u16)q->unk4 - m + func_80042DA8() % 800;
                q->unk6 = (u16)q->unk6 - m + func_80042DA8() % 800;
                q->unk8 = (u16)q->unk8 - m + func_80042DA8() % 800;
                ang = func_80042DA8() % 0x1000;
                D_801C9408 = ang;
                q->unkC = (u32)(func_80039B40(ang) * 0x19) >> 11;
                q->unk10 = (u32)(func_80039A74(D_801C9408) * 0x19) >> 11;
                q->unkE = -func_80042DA8() % 100;
                i++;
                q->unk1A = 0;
            } while (i < 2);
        }
        if (p->unk2 == 0xF) {
            func_800D5774(p->unk1C);
        }
        if (++p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0C20(s32 arg0, s32 arg1) {
    MgSVec d;
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B04B4)];
    func_800D3994(arg1, D_80151915[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    d.vx = (p->unkC.vx - p->unk4.vx) / 8;
    d.vy = (p->unkC.vy - p->unk4.vy) / 8;
    d.vz = (p->unkC.vz - p->unk4.vz) / 8;
    func_800D44E8(&d, &D_801E1410);
}

s32 func_801B0D58(arg0, arg1) {
    func_800BBEAC((M2C_UNK *)func_801B0020);
    func_800D2980(&D_801B0F9C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B0C20);
    return func_800BBA84(0x65, arg1, 0x40);
}
