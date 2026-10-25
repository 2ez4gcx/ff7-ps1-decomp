#include "common.h"
#include "magic_mgbeam/decls.h"

void func_801B0000(void) {
    func_801B099C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CBD20 = D_801B3D20 + p->unk2 * 0xC000;
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
    func_8003C21C(&D_801B3CD0, &m);
    func_8003A79C(&D_801CBD24, &m, &m);
    func_8003B35C(&m, &D_801B3CD8);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    frame = &D_801B3CCC;
    *frame = p->unk2 % D_801B3C60;
    D_801CBD20 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801CBD20);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B01D8(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, p->unk16);
    frame = &D_801B3CF0;
    *frame = p->unk2;
    D_801CBD20 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801CBD20);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B1B58) {
            p->unk0 = -1;
        }
    }
}

void func_801B0294(void) {
    MgMat m;
    MgMat unused;
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&D_801B3D14, &m);
    func_8003A79C(&D_801CBD24, &m, &m);
    func_8003B35C(&m, &D_801B3CF4);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    D_801CBD20 = (u8 *)func_800D29D4(D_801B3D04, D_801517C0 + 0x70, 0xC, (s32)D_801CBD20);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (++p->unk2 == 7) {
            p->unk0 = -1;
        }
    }
}

void func_801B03DC(void) {
    u8 pad[8];
    MgSVec a;
    MgSVec d;
    MgSVec z;
    MgMat unused;
    MgSVec out;
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 t;
    s32 r;
    s32 r1;
    s32 r2;
    s32 r3;
    s32 t1;
    s32 t2;
    s32 t3;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            z.vx = 0;
            z.vy = 0;
            z.vz = 0x1F4;
            D_801CBD38[0].x = p->unk4;
            D_801CBD38[0].y = p->unk6;
            D_801CBD38[0].z = p->unk8;
            func_8003B48C((MgMat *)((s32 *)D_801CBD38 - 5));
            func_8003B51C((MgMat *)((s32 *)D_801CBD38 - 5));
            func_8003BADC(&z, &p->unk4, &out);
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B008C)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
        }
        if (p->unk2 < 0xF) {
            D_801CBD38[0].x = p->unk4;
            D_801CBD38[0].y = p->unk6;
            D_801CBD38[0].z = p->unk8;
            func_8003B48C((MgMat *)((s32 *)D_801CBD38 - 5));
            func_8003B51C((MgMat *)((s32 *)D_801CBD38 - 5));
            d.vx = (p->unkC - p->unk4) / 8;
            d.vy = (p->unkE - p->unk6) / 8;
            d.vz = (p->unk10 - p->unk8) / 8;
            i = 0;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B0294)];
                t = i * 0x555;
                a.vx = func_80039B40((p->unk2 << 9) + t) >> 5;
                a.vy = func_80039A74((p->unk2 << 9) + t) >> 5;
                r = func_80042DA8();
                a.vz = r % 100 - 0x32;
                func_8003BADC(&a, &q->unk4, &out, r / 100);
                q->unkC = d.vx;
                q->unkE = d.vy;
                i++;
                q->unk10 = d.vz;
            } while (i < 3);
        }
        if ((u16)(p->unk2 - 9) < 0x13) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B01D8)];
            func_800D3994(p->unk1C, D_8015190F[D_800FA6D4][0], &q->unk4);
            r1 = func_80042DA8();
            t1 = (u16)q->unk4 - 0x190; q->unk4 = t1 + r1 % 800;
            r2 = func_80042DA8();
            t2 = (u16)q->unk6 - 0x190; q->unk6 = t2 + r2 % 800;
            r3 = func_80042DA8();
            q->unk14 = 0x3000;
            t3 = (u16)q->unk8 - 0x190; q->unk8 = t3 + r3 % 800;
            q->unk16 = -*(u16 *)D_801518F6[D_800FA6D4];
        }
        if (p->unk2 == 0xF) {
            func_800D5774(p->unk1C);
        }
        if (++p->unk2 == 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0864(s32 arg0, s32 arg1) {
    MgSVec d;
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B03DC)];
    func_800D3994(arg1, D_80151915[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    d.vx = (p->unkC.vx - p->unk4.vx) / 8;
    d.vy = (p->unkC.vy - p->unk4.vy) / 8;
    d.vz = (p->unkC.vz - p->unk4.vz) / 8;
    func_800D44E8(&d, &D_801CBD24);
}

s32 func_801B099C(arg0, arg1) {
    func_800BBEAC((void *)func_801B0020);
    func_800D2980(&D_801B1C1C, 0, 0, 0);
    func_800D2980(&D_801B0B14, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, func_801B0864);
    return func_800BBA84(0x65, arg1, 0);
}
