#include "common.h"
#include "magic_sumi/decls.h"

void func_801B006C(void) {
    MgTask *p;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk14 * 200, 0);
    D_801B5028[0] = p->unk2;
    *(s32 *)&D_801B5028[-4] = (s32)D_801B502C[p->unk16];
    D_801CD060 = func_800D4D90(&D_801B5028[-4], D_801517C0 + 0x70, 0xC, D_801CD060);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801B502C[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0174(void) {
    MgMat m;
    MgSVec pos;
    MgSVec rot;
    MgSVec out;
    MgTask *p;
    MgTask *q;
    MgMat *r;
    s16 *frame;
    s32 z;
    s32 ang;
    u16 a;
    s16 n;

    frame = &D_801B5044;
    p = (MgTask *)&D_80162978[D_8015169C];
    *frame = 0;
    p->unk14 = func_80039A74(p->unk2 * 0x44) * 0x28 >> 12;
    r = func_800D4368(&p->unk4, p->unk14 * 400, 0);
    z = r->t[2];
    if (z > 0) {
        func_800D4484(*(s32 *)(((z >> 4) * 4) + D_801517C0 + 0x70), 0x20);
        D_801CD060 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801CD060);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 10) {
            a = p->unk14 + 4;
        } else {
            a = p->unk14 - 1;
        }
        p->unk14 = a;
        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B006C)];
        ang = func_80042DA8() & 0xFFF;
        pos.vx = (u32)(func_80039B40(ang) * p->unk14 * 5) >> 11;
        pos.vy = (u32)(func_80039A74(ang) * p->unk14 * 5) >> 11;
        pos.vz = 0;
        rot.vz = 0;
        rot.vx = 0;
        rot.vy = func_80042DA8() & 0xFFF;
        func_8003C21C(&rot, &m);
        m.t[0] = p->unk4;
        m.t[1] = p->unk6;
        m.t[2] = p->unk8;
        func_8003B48C(&m);
        func_8003B51C(&m);
        func_8003BADC(&pos, &q->unk4, &out);
        q->unk16 = func_80042DA8() % 4;
        q->unk14 = p->unk14;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B03E8(void) {
    MgTask *p;
    MgMat *m;
    s32 z;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    m = func_800D4368(&p->unk4, D_801B5054[p->unk14] * 3 >> 1, 0);
    z = m->t[2];
    if (z > 0) {
        func_800D4484(*(s32 *)(((z >> 4) * 4) + D_801517C0 + 0x70), 0x20);
        D_801CD060 = func_800D4D90(D_801B5048, D_801517C0 + 0x70, 0xC, D_801CD060);
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xC) {
            p->unk0 = -1;
        }
    }
}

void func_801B0514(void) {
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 n;
    s16 a;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        switch (D_801B501C) {
        case 0:
            if (p->unk2 < 12) {
                if (p->unk2 % 4 != 3) {
                    for (i = 0; i < 2; i++) {
                        q = (MgTask *)&D_80162978[func_800BBEAC(func_801B03E8)];
                        q->unk4 = p->unk4 - i * ((s16)p->unkC / 2);
                        q->unk6 = p->unk6 - i * ((s16)p->unkE / 2);
                        q->unk8 = p->unk8 - i * ((s16)p->unk10 / 2);
                        q->unkC = p->unkC;
                        q->unkE = p->unkE;
                        q->unk10 = p->unk10;
                        q->unk14 = i + p->unk2 % 4 * 2;
                    }
                }
            }
            if (p->unk2 == 0xC) {
                func_800D5774(p->unk18);
                if (p->unk2 == 0xC) {
                    q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0174)];
                    a = p->unk18;
                    func_800D3994(a, D_8015190F[a][0], &q->unk4);
                    q->unk14 = 0;
                }
            }
            n = p->unk2 + 1;
            p->unk2 = n;
            if (n == 0x28) {
                p->unk0 = -1;
            }
            break;
        case 1:
            if (p->unk2 < 3) {
                for (i = 0; i < 2; i++) {
                    q = (MgTask *)&D_80162978[func_800BBEAC(func_801B03E8)];
                    q->unk4 = p->unk4 - i * ((s16)p->unkC / 2);
                    q->unk6 = p->unk6 - i * ((s16)p->unkE / 2);
                    q->unk8 = p->unk8 - i * ((s16)p->unk10 / 2);
                    q->unkC = p->unkC;
                    q->unkE = p->unkE;
                    q->unk10 = p->unk10;
                    q->unk14 = i + p->unk2 % 3 * 2;
                }
            }
            if (p->unk2 == 0xA) {
                func_800D5774(p->unk18);
            }
            if (p->unk2 == 8) {
                k = func_800BBEAC(func_801B0174);
                q = (MgTask *)D_8016297C;
                func_800D3994(p->unk18, D_8015190F[p->unk18][0], (u8 *)q + (k << 5));
            }
            n = p->unk2 + 1;
            p->unk2 = n;
            if (n == 0x28) {
                p->unk0 = -1;
            }
            break;
        }
    }
}

void func_801B0964(arg0, arg1) {
    MgSVec v;
    MgTask *q;

    q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0514)];
    func_800D3994(arg1, D_80151918[arg1][0], &q->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &v);
    switch (D_801B501C) {
    case 0:
        q->unkC = (v.vx - q->unk4) / 12;
        q->unkE = (v.vy - q->unk6) / 12;
        q->unk10 = (v.vz - q->unk8) / 12;
        break;
    case 1:
        q->unkC = (v.vx - q->unk4) / 10;
        q->unkE = (v.vy - q->unk6) / 10;
        q->unk10 = (v.vz - q->unk8) / 10;
        break;
    default:
        q->unk18 = arg0;
        return;
    }
    q->unk18 = arg0;
}

void func_801B0B38(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B0C3C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0964);
    func_800BBA84(0x8A, arg1, 0x40);
}

void func_801B0BB4(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B0C3C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0964);
    func_800BBA84(0x8A, arg1, 0x40);
    D_801B501C = 1;
}

INCLUDE_RODATA("../asm/us/magic_sumi/nonmatchings/text", D_801B0000);
