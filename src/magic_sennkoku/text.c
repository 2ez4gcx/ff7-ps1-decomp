#include "common.h"
#include "magic_sennkoku/decls.h"

M2C_UNK *func_801B0054(void) {
    D_801CD5B0 = 0;
    func_801B089C();
    return &D_801B0A70;
}

M2C_UNK *func_801B0084(void) {
    D_801CD5B0 = 1;
    func_801B089C();
    return &D_801B0A70;
}

void func_801B00B8(void) {
    MgTask *p;
    MgTask *q;

    p = &D_80162978[D_8015169C];
    if (p->unk2 == 1) {
        q = func_800D4FA8(1);
        *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
        q->unk10 = p->unkC;
    } else if (p->unk2 == 0x11) {
        func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x1A4);
    } else if (p->unk2 == 0x20) {
        func_800D4FA8(2);
    }
    if (p->unk2 >= 0x32) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x24) {
            func_800D5774(D_801CD5AC);
        }
        p->unk2++;
    }
}

void func_801B01C8(void) {
    MgTask *p;
    MgTask *q;
    MgSenSc *sc;
    MgSenPrim *prim;
    MgTag *ot;
    void *s;
    void *t;
    s32 n;
    s32 i;

    p = &D_80162978[D_8015169C];
    sc = (MgSenSc *)0x1F800000;
    if (D_801CD5EC == 0) {
        if (D_80062D98 == 0) {
            D_801CD5E8--;
            if (D_801CD5E8 <= 0) {
                D_801CD5DC++;
                if (D_801CD5DC >= D_801CD5E0) {
                    D_801CD5DC = 0;
                }
                n = D_801CD5E4 + 1;
                D_801CD5E4 = n;
                if (n >= 0x30) {
                    if (D_801CD5AC == D_801CD5B4[D_801CD5DC]) {
                        D_801CD5EC = 1;
                    }
                    D_801CD5E8 = D_801B5598;
                } else {
                    D_801CD5E8 = D_801B54DC[n];
                }
                t = sc->unk30;
                i = D_801CD5B4[D_801CD5DC];
                func_800D3994(i, D_8015190F[i][0], t);
                func_800D55F4(0x20, func_800D56A8(t), 0x1E3);
            }
        }
    }
    s = sc->unk30;
    i = D_801CD5B4[D_801CD5DC];
    D_800D3544 = D_801CD5A8;
    D_800D3546 = D_801CD5A4;
    func_800D3994(i, D_8015190F[i][0], s);
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BBDC(s, &sc->p[0], &sc->unk4, &sc->unkC);
    sc->p[1] = sc->p[2] = sc->p[3] = sc->p[0];
    prim = D_80163C74;
    if (i < 4) {
        sc->p[0].x -= 0x18;
        sc->p[2].x -= 0x18;
        prim->unkC = 0x78480018;
        prim->unk14 = 0x4D0000;
        prim->unk1C = 0x1018;
        prim->unk24 = 0x1000;
    } else {
        sc->p[1].x += 0x18;
        sc->p[3].x += 0x18;
        prim->unkC = 0x78480000;
        prim->unk14 = 0x4D0018;
        prim->unk1C = 0x1000;
        prim->unk24 = 0x1018;
    }
    sc->p[2].y += 0x10;
    sc->p[3].y += 0x10;
    prim->xy0 = *(s32 *)&sc->p[0];
    prim->xy1 = *(s32 *)&sc->p[1];
    prim->xy2 = *(s32 *)&sc->p[2];
    *(s32 *)((u8 *)prim + 0x20) = *(s32 *)&sc->p[3];
    prim->tag.len = 9;
    prim->col = 0x808080;
    ((u8 *)prim)[7] = 0x2E;
    ot = (MgTag *)D_801517C0;
    prim->tag.addr = ot[0x1F].addr;
    ot[0x1F].addr = (u32)prim;
    prim++;
    D_80163C74 = prim;
    if (D_801CD5EC != 0) {
        if (D_801CD5EC == 0xA) {
            q = &D_80162978[func_800BBEAC(func_801B00B8)];
            *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
            q->unkC = p->unkC;
        }
        if (D_801CD5EC >= 0x2D) {
            p->unk0 = -1;
        }
        D_801CD5EC++;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0650(void) {
    MgTask *q;
    MgTask *b;
    s32 *pi;
    s32 m;
    s32 i;
    s32 n;
    s32 r;
    s32 one;

    D_80162978[D_8015169C].unk0 = -1;
    b = D_80162978;
    if (D_801CD5B0 != 0) {
        q = &b[func_800BBEAC(func_801B01C8)];
        func_800D3994(D_801CD5AC, D_80151919[D_801CD5AC][0], &q->unk4);
        n = 0;
        i = 0;
        one = 1;
        q->unkC = D_80151A46[D_801CD5AC][0];
        m = D_80163758.v & ~D_80163766.v;
        *(s32 *)&D_801CD5A4 = m;
        pi = D_801CD5B4;
        for (; i < 10; i++) {
            if (m & (one << i)) {
                *pi = i;
                pi++;
                n++;
            }
        }
        D_801CD5E0 = n;
        r = func_80042DA8() % n;
        D_801CD5E4 = 0;
        D_801CD5EC = 0;
        D_801CD5E8 = D_801B54DC[0];
        D_801CD5DC = r;
    } else {
        q = &b[func_800BBEAC(func_801B00B8)];
        func_800D3994(D_801CD5AC, D_80151919[D_801CD5AC][0], &q->unk4);
        q->unkC = D_80151A46[D_801CD5AC][0];
    }
}

s32 func_801B089C(arg0) {
    s32 i;
    s32 n;

    func_800D2980(D_801B0930, 0, 0, 0);
    i = 0;
    n = 0;
    *(s32 *)&D_801CD5A8 = arg0;
    for (; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801CD5AC = i;
            }
        }
    }
    return func_800BBEAC(&func_801B0650);
}

INCLUDE_RODATA("../asm/us/magic_sennkoku/nonmatchings/text", D_801B0000);
