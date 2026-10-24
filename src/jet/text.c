#include "common.h"
#include "jet/decls.h"

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A0450);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A0874);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A0D78);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A1198);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A12EC);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A13AC);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A1450);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A16A4);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A1A64);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A1B64);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A1CD8);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A1F18);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A2058);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A2214);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A2420);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A2518);

void func_800A27F0(s32 arg0) {
    Unk80046D0C sp10;

    func_80046CFC(arg0);
loop_1:
    if (func_80046D0C(&sp10) != 0) {
        if (sp10.a_arg != 0) {
            func_80044000(sp10.a, (void *) sp10.a_arg);
        }
        if (sp10.b_arg != 0) {
            func_80044000(sp10.b, (void *) sp10.b_arg);
        }
        goto loop_1;
    }
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A2860);

void func_800A2938(void) {
    s16 *p = &D_8009A000;

    *p = 0xC1;
    D_8009A004 = 0xF0;
    D_8009A008 = 0;
    func_8002DA7C();
    *p = 0xB9;
    D_8009A004 = 0xF0;
    D_8009A008 = 0;
    func_8002DA7C();
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A29AC);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A2AA0);

void func_800A2B78(void) {
    s16 *p = &D_8009A000;

    *p = 0xA2;
    D_8009A004 = D_800A8338;
    func_8002DA7C();
    *p = 0xA3;
    D_8009A004 = D_800A833C;
    func_8002DA7C();
}

void func_800A2BE0(void) {
    D_800A83CC = -0x1B76;
    D_800A83C8 = 0;
    D_800A83D0 = 0xC8;
    D_800E2604 = D_800D1BEC;
    D_800A8CC0 = D_800D1BE8;
    func_800A2DE4(0, 3);
    D_800D1960 = 1;
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A2C50);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A2DE4);

void func_800A2E30(void) {
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A2E38);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A334C);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A3414);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A35DC);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A372C);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A385C);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A38D4);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A3980);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A3A20);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A3AAC);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A3B58);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A3C04);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A3D50);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A3E58);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A40F4);

void func_800A4390(void *arg0) {
    s16 *p;

    if (M2C_FIELD(arg0, s16 *, 0xD8) != -1) {
        p = &D_800EE42C;
        *p -= 1;
        func_800A8204(M2C_FIELD(arg0, void **, 0xD4));
        func_800A442C(M2C_FIELD(arg0, s16 *, 0xD8));
        M2C_FIELD(arg0, s16 *, 0xD8) = -1;
        M2C_FIELD(arg0, s16 *, 0xDA) = 0;
    }
}

s16 func_800A4400(void) {
    s16 *p;
    s16 i;

    p = &D_800D9940;
    i = *p;
    *p = D_800D1970[i];
    return i;
}

void func_800A442C(s16 arg0) {
    s16 *p;
    s16 *q;

    q = &D_800D1970[arg0];
    p = &D_800D9940;
    *q = *p;
    *p = arg0;
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A4458);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A45C0);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A4650);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A46E8);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A6B08);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A6BD8);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A70D4);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A7414);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A7544);

s32 func_800A7688(s32 arg0, s32 arg1, s32 arg2) {
    s32 a, b, c;
    a = D_800A892C;
    b = D_800A8930;
    c = D_800A8934;
    return a * (arg0 >> 2) + b * (arg1 >> 2) + c * (arg2 >> 2) + D_800A8A5C;
}

s32 func_800A76DC(s32 arg0, s32 arg1, s32 arg2) {
    s32 a, b, c;
    a = D_800A893C;
    b = D_800A8940;
    c = D_800A8944;
    return a * (arg0 >> 2) + b * (arg1 >> 2) + c * (arg2 >> 2) + D_800A8A64;
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A7730);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A7928);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A7A10);

void func_800A7AF8(void) {
    D_800A8A70 = 0;
    D_800D171C = 0;
    D_800A8A8C = 0;
    D_800A8CCC = D_800D1BFC;
    D_800D1968 = D_800D1C14;
    D_800A89D8 = D_800D1BD8;
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A7B48);

JetUnk20 *func_800A7BF4(void) {
    s32 *p;
    JetUnk20 *base;
    s32 n;

    p = &D_800A8A8C;
    n = *p;
    *p = n + 1;
    base = D_800D0554;
    return base + n;
}

JetUnk24 *func_800A7C20(s32 arg0) {
    s32 *p;
    s32 n;
    JetUnk24 *base;

    p = &D_800A8A70;
    n = *p;
    *p = n + arg0;
    base = (JetUnk24 *)D_800A8CCC;
    return base + n;
}

JetUnk28 *func_800A7C54(s32 arg0) {
    s32 *p;
    s32 n;
    JetUnk28 *base;

    p = &D_800D171C;
    n = *p;
    *p = n + arg0;
    base = (JetUnk28 *)D_800D1968;
    return base + n;
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A7C88);

void func_800A7E1C(void) {
    s32 *p = &D_800D1964;

    func_80044244(*p + 0x70, 0x1000);
    func_80044244(*p + 0x4098, 0xB4);
    func_800A7FAC((void *)(*p + 0x4368));
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A7E70);

void func_800A7FAC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) (arg0 + 0x24);
    M2C_FIELD(arg0, void **, 4) = (void *) (arg0 + 0x38);
    M2C_FIELD(arg0, void **, 8) = (void *) (arg0 + 0x50);
    M2C_FIELD(arg0, void **, 0xC) = (void *) (arg0 + 0xAF50);
    M2C_FIELD(arg0, void **, 0x10) = (void *) (arg0 + 0xB388);
    M2C_FIELD(arg0, void **, 0x14) = (void *) (arg0 + 0xB3A8);
    M2C_FIELD(arg0, void **, 0x18) = (void *) (arg0 + 0xE288);
    M2C_FIELD(arg0, void **, 0x1C) = (void *) (arg0 + 0xE2B0);
    M2C_FIELD(arg0, void **, 0x20) = (void *) (arg0 + 0xE2E4);
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A8010);

void func_800A80A8(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 4) = 0x1000;
    M2C_FIELD(arg0, s16 *, 0xC) = 0x1000;
    M2C_FIELD(arg0, s16 *, 0x14) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 8) = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = 0;
    M2C_FIELD(arg0, s16 *, 0xE) = 0;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x24) = &D_800D16E4;
    M2C_FIELD(arg0, s16 *, 0x2A) = arg1;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A80F8);

void func_800A8204(void *arg0) {
    func_800A82F0(arg0);
    func_800A8264(M2C_FIELD(arg0, s16 *, 0x2A));
}

s16 func_800A8238(void) {
    s16 *p;
    s16 i;

    p = &D_800D9944;
    i = *p;
    *p = D_800D1A40[i];
    return i;
}

void func_800A8264(s16 arg0) {
    s16 *p;
    s16 *q;

    q = &D_800D1A40[arg0];
    p = &D_800D9944;
    *q = *p;
    *p = arg0;
}

void func_800A8290(JetNode *arg0, JetNode *arg1) {
    s16 depth;
    JetNode *head;

    arg0->parent = arg1;
    depth = arg1->depth + 1;
    arg0->depth = depth;
    head = &D_800EE1D4[depth];
    arg0->next = head->next;
    arg0->prev = arg0->next->prev;
    head->next->prev = arg0;
    head->next = arg0;
}

void func_800A82F0(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), void **, 0x34) = (void *) M2C_FIELD(arg0, void **, 0x34);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), void **, 0x30) = (void *) M2C_FIELD(arg0, void **, 0x30);
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A8310);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A83F0);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A84A4);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A84DC);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A8604);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A8734);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A882C);
