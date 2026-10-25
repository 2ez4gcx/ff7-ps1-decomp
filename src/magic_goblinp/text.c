#include "common.h"
#include "magic_goblinp/decls.h"

void func_801B0054(void) {
    func_801B0E64();
}

INCLUDE_ASM("../asm/us/magic_goblinp/nonmatchings/text", func_801B0074);

void func_801B0188(void) {
    u8 pad[16];
    MgLineG2 *prim;
    MgTask *p;
    s32 i;
    GbScratch *sc;
    void *pa;
    void *pb;
    s32 a;
    s32 k;

    i = 0;
    p = &D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    sc = (GbScratch *)0x1F800000;
    pa = (void *)0x1F800004;
    pb = (void *)0x1F80000C;
    prim = (MgLineG2 *)D_801D23C8;
    a = p->unk2 << 9;
    func_8003B69C(0, 0, 0);
    sc->w10 = 0x1C1450;
    sc->w14 = 0x6050F0;
    func_8003B710(&sc->w10, a, &sc->c0);
    func_8003B710(&sc->w14, a, &sc->c1);
    *((u8 *)&sc->c0 + 3) = 0x52;
    k = p->unk18;
    do {
        sc->vx = D_801D23D8[k].x + D_801D23D8[k].a;
        sc->vy = D_801D23D8[k].y + D_801D23D8[k].b;
        sc->vz = D_801D23D8[k].z + D_801D23D8[k].c;
        sc->otz = func_8003BBDC(&D_801D23D8[k], &prim->x0, pa, pb);
        func_8003BBDC(&sc->vx, &prim->x1, pa, pb);
        prim->tag.len = 4;
        *(s32 *)&prim->r0 = sc->c0;
        *(s32 *)&prim->r1 = sc->c1;
        prim->tag.addr = ((MgTag *)D_801517C0 + (sc->otz >> 2) + 0x1C)->addr;
        ((MgTag *)D_801517C0 + (sc->otz >> 2) + 0x1C)->addr = (u32)prim;
        if (D_80062D98 == 0) {
            D_801D23D8[k].x += D_801D23D8[k].vx;
            D_801D23D8[k].y += D_801D23D8[k].vy;
            D_801D23D8[k].z += D_801D23D8[k].vz;
        }
        k++;
        if (k >= 0xDE) {
            k = 0;
        }
        prim++;
        i++;
    } while (i < 0x12);
    D_801D23C8 = (s32)prim;
    if (p->unk2 >= 8) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0518(void) {
    MgTask *p;
    u16 *frame;
    s16 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801BA3C4;
    *frame = p->unk2;
    t = p->unkC;
    func_800D4368(&p->unk4, t, -(t >> 2));
    D_801D23C8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D23C8);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_goblinp/nonmatchings/text", func_801B05E4);

INCLUDE_ASM("../asm/us/magic_goblinp/nonmatchings/text", func_801B0D14);

INCLUDE_ASM("../asm/us/magic_goblinp/nonmatchings/text", func_801B0E64);
