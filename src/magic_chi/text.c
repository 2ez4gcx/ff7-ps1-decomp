#include "common.h"
#include "magic_chi/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B061C();
    return &D_801B47E0;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C8080 = D_801B8080 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0088(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801B8034;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801B471C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0140(void) {
    MgTask *p;
    u16 *w;
    MgTask *wv;
    u8 *a;
    s16 id;
    s32 r;
    s16 ang;
    s16 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (D_801B8064 < 0xA && p->unk2 == D_801B8038[D_801B8064]) {
            D_801B807C = p->unk1E;
            id = D_801517F0[D_801B8064];
            a = D_80151A4C[id];
            D_801B8068[0] = *(u16 *)a;
            D_801B806A = *(u16 *)(a + 2);
            D_801B8068[2] = *(u16 *)(a + 4);
            D_801B8078 = id;
            r = func_80042DA8();
            ang = r % 0x1000;
            k = *(u16 *)D_801518F6[D_801B8078] + 0x5DC;
            D_801B8068[0] += func_80039A74(ang) * k >> 12;
            D_801B8070[0] = D_801B8068[0];
            D_801B8070[1] = 0;
            D_801B8068[2] += func_80039B40(ang) * k >> 12;
            D_801B8070[2] = D_801B8068[2];
            w = (u16 *)D_80151A4C[p->unk1E];
            w[0] = D_801B8070[0];
            w = (u16 *)D_80151A4C[p->unk1E];
            w[1] = D_801B8070[1];
            w = (u16 *)D_80151A4C[p->unk1E];
            w[2] = D_801B8070[2];
            w = (u16 *)(((u8 *)D_80151A4C - 8) + p->unk1E * 0xB9C);
            w[0] = 0;
            w = (u16 *)(((u8 *)D_80151A4C - 8) + p->unk1E * 0xB9C);
            w[1] = ang;
            w = (u16 *)(((u8 *)D_80151A4C - 8) + p->unk1E * 0xB9C);
            w[2] = 0;
            D_801B8066 = D_801B8050[D_801B8064] - D_801B8038[D_801B8064];
            func_800D61AC(D_80151A4C[D_801B807C] + 0xC + D_80151915[D_801B807C][0] * 0x34, 0xC8, 0x208020, 4, D_801B8038[D_801B8064 + 1] - D_801B8038[D_801B8064]);
        }
        if (D_801B8066 > 0) {
            D_801B8066--;
            if (D_801B8066 == 0) {
                wv = (MgTask *)func_800D4FA8(0xA);
                wv->unk0 = D_801B8078;
                wv->unk10 = D_801B8064;
                func_800D3994(D_801B8078, D_8015190F[D_801B8078][0], (u8 *)&D_80162978[func_800BBEAC((void *)func_801B0088)] + 4);
                D_8009A000 = 0x21;
                D_8009A004 = func_800D56A8(D_801B8070);
                D_8009A008 = 0x159;
                D_8009A00C = 0x142;
                func_8002DA7C();
                D_801B8064++;
            }
        }
        if (++p->unk2 == 0x82) {
            func_800D52A0(0, 0xA);
            p->unk0 = -1;
        }
    }
}

void func_801B061C(arg0, arg1) {
    func_800BBEAC((void *)func_801B0028);
    func_800D2980(D_801B06D8, 0, 0, 0);
    D_801C8084 = arg0;
    func_800D54EC(arg0, D_801C8088);
    D_80162996[func_800BBEAC((void *)func_801B0140)].unk0 = arg1;
    D_800F5B71 = 0;
    D_800F5B72 = 0;
    D_800F5B70 = 0x40;
    func_800D52A0(0x1000, 0xA);
}
