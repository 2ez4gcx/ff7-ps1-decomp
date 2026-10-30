#include "common.h"
#include "magic_fullcare/decls.h"

void func_801B0000(void) {
    func_801B1034();
}

void func_801B0020(void) {
    s32 *p;
    s32 i;

    i = 199;
    p = &D_801E6494;
    for (; i >= 0; i--) {
        *p-- = 0;
    }
}

MgObj1C *func_801B0044(s32 arg0) {
    s32 i;

    for (i = 0; i < 200; i++) {
        if (D_801E6178[i] == 0) {
            D_801E6178[i] = arg0;
            D_801E4B98[i].unk0 = 0;
            D_801E4B98[i].unk2 = 0;
            return &D_801E4B98[i];
        }
    }
    return NULL;
}

void func_801B00BC(void) {
    MgTask *p;
    s32 i;
    s32 n;

    n = 0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 200; i++) {
        if (D_801E6178[i] != 0) {
            ((void (*)(MgObj1C *))D_801E6178[i])(&D_801E4B98[i]);
            if (D_801E4B98[i].unk0 == -1) {
                D_801E6178[i] = 0;
            } else {
                n++;
            }
        }
    }
    if (n == 0 && D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B01B4(void) {
    MgTask *p;
    s32 t;
    s32 v;
    s32 c;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xF) {
        v = (t << 12) / 15;
        c = (v * 0x780 >> 12) + 0x80;
        D_801C491A = c;
        D_801C4916 = c;
        D_801C490C = c;
        D_801C4906 = v;
    } else {
        p->unk0 = -1;
        return;
    }
    D_801C4924 = 0;
    D_801C4920[0] = p->unk4;
    D_801C4928 = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801C4920[-5], D_801C492C);
    func_8003B48C(D_801C492C);
    func_8003B51C(D_801C492C);
    func_8003B69C(0, 0, 0);
    D_801E4994 = func_800D29D4(&D_801C48FC, D_801517C0 + 0x70, 0xC, D_801E4994);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0324(void) {
    MgTask *p;
    MgTask *q;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 % 5 == 0) {
            q = &D_80162978[func_800BBEAC(&func_801B01B4)];
            *(FcB8 *)&q->unk4 = *(FcB8 *)&p->unk4;
        }
        p->unk2++;
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B0410(MgTask *p) {
    s32 t;
    u8 c;

    t = p->unk2;
    if (t < 10) {
        c = 0x80;
        goto store;
    }
    if ((t -= 10) < 5) {
        c = (-(((t << 12) / 5) << 7) >> 12) - 0x80;
store:
        D_801C493A = c;
        D_801C4939 = c;
        D_801C4938 = c;
    } else {
        p->unk0 = -1;
        return;
    }
    func_800D4368(&p->unk4, p->unk14, 0);
    D_801E4994 = func_800D6260(&D_801C4930, D_801517C0 + 0x70, 0xC, D_801E4994);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk6 += p->unkE;
        p->unkE = p->unkE * 31 >> 5;
    }
}

void func_801B0528(void) {
    MgTask *p;
    MgObj1C *q;
    s32 i;
    s32 r;
    s32 a;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        for (i = 0; i < 3; i++) {
            q = func_801B0044((s32)func_801B0410);
            r = func_80042DA8() % 1000;
            a = func_80042DA8() & 0xFFF;
            q->unk4 = (u16)p->unk4 + (r * func_80039A74(a) >> 12);
            q->unk6 = 0;
            q->unk8 = (u16)p->unk8 + (r * func_80039B40(a) >> 12);
            q->unkE = -(func_80042DA8() % 200 + 0xC8);
            q->unk14 = func_80042DA8() % 0x400 + 0x400;
        }
        p->unk2++;
        if (p->unk2 >= 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B06C8(MgTask *p) {
    s32 t;
    u8 c;

    t = p->unk2;
    if (t < 5) {
        c = (t << 12) / 5 >> 5;
        goto store;
    }
    if ((t -= 5) < 0x19) {
        c = 0x80;
        goto store;
    }
    if ((t -= 0x19) < 5) {
        c = (-(((t << 12) / 5) << 7) >> 12) - 0x80;
store:
        D_801C494A = c;
        D_801C4949 = c;
        D_801C4948 = c;
    } else {
        p->unk0 = -1;
        return;
    }
    func_8003C21C(&p->unkC, &D_801C4950->m);
    D_801C4950->v.vx = p->unk16;
    D_801C4950->v.vz = 0;
    D_801C4950->v.vy = 0;
    func_8003B2CC(&D_801C4950->m, &D_801C4950->v, &D_801C4950->v);
    D_801C4950->v.vx += p->unk4;
    D_801C4950->v.vy += p->unk6;
    D_801C4950->v.vz += p->unk8;
    func_800D4368(D_801C4950, p->unk14, 0);
    D_801E4994 = func_800D6260(&D_801C4940, D_801517C0 + 0x70, 0xC, D_801E4994);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk6 += p->unk18;
        p->unkC += 0x12;
        p->unkE += 0x45;
        p->unk10 += 0x78;
    }
}

void func_801B089C(void) {
    MgTask *p;
    MgObj1C *q;
    s32 i;
    s32 r;
    s32 a;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        for (i = 0; i < 3; i++) {
            q = func_801B0044((s32)func_801B06C8);
            r = func_80042DA8() % 2500 + 0x1F4;
            a = func_80042DA8() & 0xFFF;
            q->unk4 = (u16)p->unk4 + (r * func_80039A74(a) >> 12);
            q->unk6 = -0xBB8;
            q->unk8 = (u16)p->unk8 + (r * func_80039B40(a) >> 12);
            q->unkC = func_80042DA8() & 0xFFF;
            q->unkE = func_80042DA8() & 0xFFF;
            q->unk10 = func_80042DA8() & 0xFFF;
            q->unk14 = func_80042DA8() % 0x400 + 0x400;
            q->unk16 = func_80042DA8() % 190 + 10;
            q->unk18 = func_80042DA8() % 50 + 0x23;
        }
        p->unk2++;
        if (p->unk2 >= 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0AB4(void) {
    MgTask *p;
    s32 t;
    s32 c;
    s32 q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        q = (t << 12) / 10;
        D_801C4964 = D_801C4974 = 0x1000;
        D_801C495E = 0x1000 - q;
        goto store;
    }
    if ((t -= 10) < 0x28) {
        q = (t << 12) / 40;
        c = (-(q << 12) >> 12) + 0x1000;
        D_801C4974 = c;
        D_801C4964 = c;
        if (t < 0x14) {
            D_801C495E = 0;
        } else {
            q = ((t - 0x14) << 12) / 20;
            D_801C495E = q;
        }
    } else {
        p->unk0 = -1;
        return;
    }
store:
    D_801C497C = 0;
    D_801C4978[0] = p->unk4;
    D_801C4980 = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801C4978[-5], D_801C4990);
    func_8003B48C(D_801C4990);
    func_8003B51C(D_801C4990);
    func_8003B69C(0, 0, 0);
    D_801E4994 = func_800D29D4(&D_801C4954, D_801517C0 + 0x70, 0xC, D_801E4994);
    if (D_80062D98 == 0) {
        p->unk2++;
        func_800D2538(&D_801C4984, ((p->unk2 & 0xF) << 5) + (s32)D_801E4998);
    } else {
        func_800D2538(&D_801C4984, ((D_801C498C & 0xF) << 5) + (s32)D_801E4998);
        D_801C498C++;
    }
}

void func_801B0D04(void) {
    MgTask *p;
    MgTask *q;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_800F5B70 = 0;
            D_800F5B71 = 0;
            D_800F5B72 = 0;
            func_800D52A0(0x800, 5);
        }
        if (p->unk2 == 5) {
            q = &D_80162978[func_800BBEAC(&func_801B0324)];
            *(FcB8 *)&q->unk4 = *(FcB8 *)&p->unk4;
        }
        if (p->unk2 == 10) {
            q = &D_80162978[func_800BBEAC(&func_801B0528)];
            *(FcB8 *)&q->unk4 = *(FcB8 *)&p->unk4;
        }
        if (p->unk2 == 15) {
            q = &D_80162978[func_800BBEAC(&func_801B089C)];
            *(FcB8 *)&q->unk4 = *(FcB8 *)&p->unk4;
        }
        if (p->unk2 == 25) {
            q = &D_80162978[func_800BBEAC(&func_801B0AB4)];
            *(FcB8 *)&q->unk4 = *(FcB8 *)&p->unk4;
        }
        if (p->unk2 == 0x23) {
            func_800D5774(p->unk0);
        }
        t = p->unk2;
        if (t == 0x4B) {
            func_800D52A0(0, 5);
            if (p->unk2 == t) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B0EF8(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0D04)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

void func_801B0F78(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801E4994 = D_801C4994 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 3) {
        p->unk0 = -1;
    }
}

void func_801B0FD8(void) {
    s32 i;
    s32 j;
    u16 *p;
    u16 *row;
    u16 *tab;

    tab = D_801B10F0;
    i = 0;
    row = D_801E4998;
    for (; i < 0x10; i++) {
        j = 0;
        p = row;
        for (; j < 0x10; j++) {
            *p++ = tab[(j + i) & 0xF];
        }
        row += 0x10;
    }
}

s32 func_801B1034(arg0, arg1) {
    func_800D2980(&D_801B10DC, 0, 0, 0);
    func_801B0FD8();
    func_800BBEAC(&func_801B0F78);
    func_801B0020();
    func_800BBEAC(&func_801B00BC);
    func_800D5444(arg0, arg1, 0, &func_801B0EF8);
    return func_800D55F4(0x20, func_800D574C(arg0), 0x1FE);
}
