#include "common.h"
#include "magic_dokufuki/decls.h"

INCLUDE_ASM("../asm/us/magic_dokufuki/nonmatchings/text", func_801B006C);

INCLUDE_ASM("../asm/us/magic_dokufuki/nonmatchings/text", func_801B01E8);

void func_801B031C(void) {
    MgSVec rot;
    MgSVec pos;
    MgMat m;
    MgTask *p;
    MgTask *q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B01E8)];
        q->unk4 = p->unk4;
        q->unk6 = p->unk6;
        q->unk8 = p->unk8;
        q->unk1A = p->unk2 >> 1;
        pos.vx = 0;
        pos.vy = 0;
        pos.vz = p->unk18;
        rot.vx = 0;
        rot.vy = -func_80039A74(p->unk2 * 0x88) / 16;
        rot.vz = 0x200;
        func_8003C4AC(&rot, &m);
        func_8003C8DC(p->unk14, &m);
        func_8003B2CC(&m, &pos, (MgSVec *)&q->unkC);
        p->unk2++;
        if (p->unk2 == 0x20) {
            p->unk0 = -1;
        }
    }
}

void func_801B0454(void) {
    MgSVec e;
    MgSVec d;
    MgMat m;
    MgTask *p;
    MgTask *q;
    s16 ang;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B031C)];
            q->unk14 = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            d.vx = p->unkC - q->unk4;
            d.vz = p->unk10 - q->unk8;
            q->unk18 = func_80039F5C(d.vx * d.vx + d.vz * d.vz) / 24;
        }
        if (p->unk2 == 0x32) {
            func_800D5774(p->unk1C);
            D_8009A000 = 0x29;
            D_8009A004 = 0x40;
            D_8009A008 = 0x95;
            func_8002DA7C();
        }
        if ((u16)(p->unk2 - 0x29) < 7U) {
            ang = p->unk2 * 0x200 - 0x5400;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B006C)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            q->unk4 += func_80039B40(ang) * 0x320 >> 12;
            q->unk6 += func_80039A74(ang) * 0x320 >> 12;
            q->unk1A = 1;
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B006C)];
            func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
            k = 0x12C;
            q->unk4 = q->unk4 - k + func_80042DA8() % 600;
            k = 0x12C;
            q->unk6 = q->unk6 - k + func_80042DA8() % 600;
            k = 0x12C;
            q->unk8 = q->unk8 - k + func_80042DA8() % 600;
            q->unk1A = 0;
        }
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B07F8(s32 arg0, s32 arg1) {
    MgObj20 *p;
    u8 *row;

    p = &D_80162978[func_800BBEAC(func_801B0454)];
    row = D_8015190F[arg1];
    func_800D3994(arg1, row[D_801C8E78], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->pad[4]);
    *(s16 *)&p->pad[0x14] = arg0;
}

void func_801B08C4(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B0A20, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B07F8);
    func_800BBA84(0x6B, arg1, 0);
    D_8009A000 = 0x28;
    D_8009A004 = 0x40;
    D_8009A008 = 0xB2;
    func_8002DA7C();
}

void func_801B096C(s32 arg0, M2C_UNK arg1) {
    D_801C8E78 = 8;
    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B0A20, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B07F8);
    func_800BBA84(0x6B, arg1, 0);
    D_8009A000 = 0x28;
    D_8009A004 = 0x40;
    D_8009A008 = 0xB2;
    func_8002DA7C();
}

INCLUDE_RODATA("../asm/us/magic_dokufuki/nonmatchings/text", D_801B0000);
