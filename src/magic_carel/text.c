#include "common.h"
#include "magic_carel/decls.h"

void func_801B0000(void) {
    func_801B0FCC();
}

void func_801B0020(void) {
    MgTask *p;
    MgSprArg *s;
    s32 n;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk10, -500);
    s = (MgSprArg *)0x1F800000;
    s->y = -16;
    s->x = -16;
    s->u = D_801B111C[p->unk2];
    s->v = ((u8 *)&p->unkC)[1];
    s->w = 0x1F;
    s->h = 0x1F;
    s->tpage = p->unk16;
    s->clut = p->unkE;
    s->rgbc = 0x2E808080;
    D_801D1134 = func_800D6260(s, D_801517C0 + 0x70, 0xC, D_801D1134);
    if (D_80062D98 == 0) {
        p->unk2++;
        n = p->unk2;
        if (((u8 *)&p->unkC)[1] == 0x80) {
            if (n >= 8) {
                goto block;
            }
            return;
        }
        if (n >= 9) {
        block:
            p->unk0 = -1;
        }
    }
}

void func_801B015C(void) {
    MgSpark *p;
    MgSpark *q;
    s32 i;
    s32 k;
    s16 n;

    p = (MgSpark *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            i++;
            p->unk14 = (p->unk14 + (func_80042DA8() & 3) + 1) % D_801518F4[p->unk12].unk0;
            q = (MgSpark *)&D_80162978[func_800BBEAC((s32 *)&func_801B0020)];
            func_800D3994(p->unk12, p->unk14, &q->unk4);
            k = 0xFA;
            q->unk4 = q->unk4 - k + func_80042DA8() % 500;
            k = 0xFA;
            q->unk6 = q->unk6 - k + func_80042DA8() % 500;
            k = 0xFA;
            q->unk8 = q->unk8 - k + func_80042DA8() % 500;
            q->unkD = p->unkD;
            q->unkE = p->unkE;
            q->unk10 = (func_80042DA8() & 0xFFF) + 0x1000;
            q->unk16 = p->unk16;
        } while (i < 2);
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0x1E) {
            func_800D5774(p->unk12);
            p->unk0 = -1;
        }
    }
}

void func_801B03A0(void) {
    MgSpark *p;
    MgSpark *q;
    s32 i;
    s32 k;
    s16 n;

    p = (MgSpark *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            i++;
            q = (MgSpark *)&D_80162978[func_800BBEAC((s32 *)&func_801B0020)];
            p->unk14 = (p->unk14 + (func_80042DA8() & 3) + 1) % D_801518F4[p->unk12].unk0;
            func_800D3994(p->unk12, p->unk14, &q->unk4);
            k = 0xFA;
            q->unk4 = q->unk4 - k + func_80042DA8() % 500;
            k = 0xFA;
            q->unk6 = q->unk6 - k + func_80042DA8() % 500;
            k = 0xFA;
            q->unk8 = q->unk8 - k + func_80042DA8() % 500;
            q->unkD = (func_80042DA8() % 3) << 5;
            q->unkE = D_801B1128[func_80042DA8() % 5];
            q->unk10 = (func_80042DA8() & 0xFFF) + 0x1000;
            q->unk16 = p->unk16;
        } while (i < 2);
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0x1E) {
            func_800D5774(p->unk12);
            p->unk0 = -1;
        }
    }
}

void func_801B0648(void) {
    MgSpark *p;
    MgSpark *q;
    s32 i;
    s32 k;

    p = (MgSpark *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            i++;
            q = (MgSpark *)&D_80162978[func_800BBEAC((s32 *)&func_801B0020)];
            p->unk14 = (p->unk14 + (func_80042DA8() & 3) + 1) % D_801518F4[p->unk12].unk0;
            func_800D3994(p->unk12, p->unk14, &q->unk4);
            k = 0xFA;
            q->unk4 = q->unk4 - k + (func_80042DA8() & 0x1F4);
            k = 0xFA;
            q->unk6 = q->unk6 - k + (func_80042DA8() & 0x1F4);
            k = 0xFA;
            q->unk8 = q->unk8 - k + (func_80042DA8() & 0x1F4);
            q->unkD = (func_80042DA8() & 1) * 0x60 + 0x20;
            q->unkE = 0x7887;
            q->unk10 = (func_80042DA8() & 0xFFF) + 0x1000;
            q->unk16 = p->unk16;
        } while (i < 2);
        if ((s16)p->unk2++ >= 0xF) {
            func_800D5774(p->unk12);
            p->unk0 = -1;
        }
    }
}

void func_801B0814(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D1134 = D_801B1134 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0874(arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B015C)];
    p->unkE = 0x7807;
    p->unk12 = arg0;
    p->unk14 = 0;
    *((u8 *)p + 0xD) = 0;
    p->unk16 = 0x3A;
}

void func_801B08D4(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0874);
    func_800D55F4(0x20, func_800D574C(arg0), 6);
}

void func_801B0954(arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B015C)];
    *((u8 *)p + 0xD) = 0x40;
    p->unkE = 0x7947;
    p->unk12 = arg0;
    p->unk14 = 0;
    p->unk16 = 0x3A;
}

void func_801B09B8(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0954);
    func_800D55F4(0x20, func_800D574C(arg0), 8);
}

void func_801B0A38(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B03A0)];
    p->unk12 = arg0;
    p->unk14 = 0;
    p->unk16 = 0x3A;
}

void func_801B0A8C(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0A38);
    func_800D55F4(0x20, func_800D574C(arg0), 0x45);
}

void func_801B0B0C(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0648)];
    p->unk12 = arg0;
    p->unk14 = 0;
    p->unk16 = 0x3A;
}

void func_801B0B60(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0B0C);
    func_800D55F4(0x20, func_800D574C(arg0), 0x5C);
}

void func_801B0BE0(arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B015C)];
    *((u8 *)p + 0xD) = 0x60;
    p->unkE = 0x7887;
    p->unk12 = arg0;
    p->unk14 = 0;
    p->unk16 = 0x3A;
}

void func_801B0C44(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0BE0);
    func_800D55F4(0x20, func_800D574C(arg0), 0x5B);
}

void func_801B0CC4(arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B015C)];
    p->unkE = 0x7A47;
    p->unk12 = arg0;
    p->unk14 = 0;
    *((u8 *)p + 0xD) = 0;
    p->unk16 = 0x3A;
}

void func_801B0D24(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0CC4);
    func_800D55F4(0x20, func_800D574C(arg0), 0x1F);
}

void func_801B0DA4(arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B015C)];
    *((u8 *)p + 0xD) = 0x20;
    p->unkE = 0x7907;
    p->unk12 = arg0;
    p->unk14 = 0;
    p->unk16 = 0x3A;
}

void func_801B0E08(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0DA4);
    func_800D55F4(0x20, func_800D574C(arg0), 0x1F);
}

void func_801B0E88(arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B015C)];
    *((u8 *)p + 0xD) = 0x20;
    p->unkE = 0x78C7;
    p->unk12 = arg0;
    p->unk14 = 0;
    p->unk16 = 0x3A;
}

void func_801B0EEC(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B0E88);
    func_800D55F4(0x20, func_800D574C(arg0), 0x17E);
}

void func_801B0F6C(arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B015C)];
    p->unkE = 0x7A07;
    p->unk12 = arg0;
    p->unk14 = 0;
    *((u8 *)p + 0xD) = 0;
    p->unk16 = 0x3A;
}

s32 func_801B0FCC(arg0, arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, 0, &func_801B0F6C);
    func_800D55F4(0x20, func_800D574C(arg0), 0x166);
}

void func_801B1038(arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B015C)];
    *((u8 *)p + 0xD) = 0x20;
    p->unkE = 0x7847;
    p->unk12 = arg0;
    p->unk14 = 0;
    p->unk16 = 0x3A;
}

void func_801B109C(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B0814);
    func_800D5444(arg0, arg1, -(func_800D54BC(arg0) >= 5) & 0xA, &func_801B1038);
    func_800D55F4(0x20, func_800D574C(arg0), 7);
}
