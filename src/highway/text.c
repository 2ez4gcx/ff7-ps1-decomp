#include "common.h"
#include "highway/decls.h"

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A00EC);

void func_800A0554(void) {
    D_800B3BF8 = func_8003CEDC(1);
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A057C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A2ADC);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A2F4C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A30A0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A31C8);

void func_800A34A4(HwDrawCtx *arg0) {
    func_800AF640(arg0, D_80110B90, 0x55, 0x18, 1);
    func_800AF858(arg0, 2, 0x12, 0x14, 0x6C, 0x14, 0, 0x20, 0x6C, 0x14, 0);
    func_800AF41C(arg0, D_800BDFB4, 0xF8, 0x1A, 1);
    func_800AF858(arg0, 1, 0xC8, 0x14, 0x6D, 0x1B, 0, 0, 0x6D, 0x1B, 0);
    if (D_8011639C == 1) {
        func_800AF858(arg0, 1, 0x64, 0x50, 0x76, 0x3A, 0, 0x3C, 0x76, 0x3A, 0);
    }
    if (D_8011639C == 2) {
        func_800AF858(arg0, 1, 0x64, 0x50, 0x75, 0x38, 0x82, 0x3C, 0x75, 0x38, 0);
    }
    if (D_8011639C == 3) {
        func_800AF858(arg0, 1, 0x64, 0x50, 0x73, 0x3E, 0, 0x81, 0x73, 0x3E, 0);
    }
}

void func_800A3668(void) {
    s32 i;
    s32 j;

    func_80044A68(&D_80116358, 0, 1, func_8004656C(1, 1, 0x300, 0) & 0xFFFF, 0);
    func_800A3AF8();
    func_800AD0A4();
    func_800A3F98();
    for (i = 0; i < 0xB5; i++) {
        D_800BD81C[i] = (s32)func_800A3FE8(i);
    }
    func_800AC518();
    func_800A7050();
    func_800A5BA8();
    func_800AC680();
    func_800AB674();
    func_800AD534();
    func_800AD374();
    func_800AF990();
    func_800AFE98();
    D_801163E8->unkAA = 0;
    D_801163E8->unkAC = 0;
    D_801163E8->unkB2 = 0;
    D_801163E8->unkB4 = 0;
    D_801163E8->unkBA = -0x5A;
    D_801163E8->unkBC = 0;
    D_801163E8->unkC2 = -0x5A;
    D_801163E8->unkC4 = 0;
    for (j = 0; j < 0x50; j++) {
        D_800BE5A4[j].unk0 = j - j / 8 * 8;
        func_800A5D6C();
        D_8010EB88 += 1;
    }
}

void func_800A37C4(void) {
    u8 **s1;

    func_80043814(&D_800C4C4C, 0, 0, 0x140, 0xF0);
    func_800438D4((DispEnv *)((u8 *)&D_800C4C4C + 0x5C), 0, 0xF0, 0x140, 0xF0);
    func_80043814(&D_800E8FAC, 0, 0xF0, 0x140, 0xF0);
    func_800438D4(&D_800E9008, 0, 0, 0x140, 0xF0);
    D_800C4C64 = 0;
    D_800E8FC4 = 0;
    D_800C4C65 = 0;
    D_800C4C66 = 0;
    D_800C4C67 = 0;
    D_800E8FC5 = 0;
    D_800E8FC6 = 0;
    D_800E8FC7 = 0;
    func_8003B6BC(0xA0, 0x78);
    func_8003B6DC(0x12C);
    func_80043D3C(1);
    func_8003B67C(0x80, 0x80, 0x80);
    func_8003B69C(0, 0, 0);
    func_80039BE0(0x1964, 0x2CEC, 0x12C);
    s1 = (u8 **)((u8 *)&D_800C4C4C + 0x5088);
    func_800A39E0((s32)s1);
    func_800A39E0((s32)&D_800EE034);
    func_800A3AA0(s1);
    func_800A3AA0(&D_800EE034);
    func_80044244((s32)((u8 *)&D_800C4C4C + 0x98), 0x1000);
    func_80044244((s32)&D_800E9044, 0x1000);
    func_80044244((s32)((u8 *)&D_800C4C4C + 0x5038), 0x14);
    func_80044244((s32)&D_800EDFE4, 0x14);
    func_80044244((s32)((u8 *)&D_800C4C4C + 0x70), 0xA);
    func_80044244((s32)&D_800E901C, 0xA);
    D_80110A90 = (s32)&D_800C4C4C;
}

void func_800A397C(void) {
    func_80044244(D_80110A90 + 0x98, 0x1000);
    func_80044244(D_80110A90 + 0x5038, 0x14);
    func_80044244(D_80110A90 + 0x70, 0xA);
    func_800A3AA0(D_80110A90 + 0x5088);
}

void func_800A39E0(s32 arg0) {
    s32 i;

    do {
        for (i = 0; i < 2500; i++) {
            func_800468C0((void *)(arg0 + 0x20 + i * 0x1C));
        }
    } while (0);
    do {
        for (i = 0; i < 2; i++) {
            func_80046910((void *)(arg0 + 0x11190 + i * 0x24));
        }
    } while (0);
    do {
        for (i = 0; i < 800; i++) {
            func_800468AC((void *)(arg0 + 0x111D8 + i * 0x20));
        }
    } while (0);
    do {
        for (i = 0; i < 800; i++) {
            func_800468FC((void *)(arg0 + 0x175D8 + i * 0x28));
        }
    } while (0);
}

void func_800A3AA0(u8 **arg0) {
    u8 *p = (u8 *)arg0;

    arg0[0] = p + 0x20;
    arg0[1] = p + 0x20;
    arg0[2] = p + 0x20;
    arg0[3] = p + 0x11190;
    arg0[4] = p + 0x111D8;
    arg0[5] = p + 0x175D8;
    arg0[6] = p + 0x1F2D8;
    arg0[7] = p + 0x1F2D8;
}

void func_800A3AF8(void) {
    s32 i;

    func_800A3BC8(&D_8010EB90, 0);
    D_8010EBBC = 0;
    D_8010EA38 = 0;
    for (i = 0; i < 400; i++) {
        D_800BDFCC[i] = i + 1;
    }
    for (i = 0; i < 10; i++) {
        D_800BE33C[i].unk0 = D_80116444[i];
        D_80116474[i].unk0 = D_800BE308[i];
        D_800BE338[i].unk0 = 0;
        D_80116478[i].unk0 = 0;
    }
}

void func_800A3BC8(void *arg0, s16 arg1) {
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
    M2C_FIELD(arg0, M2C_UNK **, 0x24) = &D_8010EB90;
    M2C_FIELD(arg0, s16 *, 0x2A) = arg1;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
}

s32 func_800A3C18(s16 arg0, s32 arg1, s32 arg2, s32 arg3, M2C_UNK *arg4, s32 arg5, s32 arg6, s32 arg7, s16 arg8, s16 arg9, s16 arg10) {
    s16 rot[4];
    s16 idx;
    u8 *n;

    idx = func_800A3E98();
    n = D_800B6D50[idx];
    func_800A3EFC(n, (u8 *)arg4);
    *(s32 *)(n + 0) = D_800BD81C[arg0];
    *(s16 *)(n + 0x2A) = idx;
    *(s16 *)(n + 0x28) = arg0;
    rot[0] = arg8;
    rot[1] = arg9;
    rot[2] = arg10;
    func_8003BF8C(rot, n + 4);
    *(s32 *)(n + 0x18) = arg5;
    *(s32 *)(n + 0x1C) = arg6;
    *(s32 *)(n + 0x20) = arg7;
    return (s32)n;
}

void func_800A3D24(void *arg0, M2C_UNK arg1, void *arg2) {
    func_8003C21C(arg1, arg0 + 4);
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) M2C_FIELD(arg2, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) M2C_FIELD(arg2, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(arg2, s32 *, 8);
}

u8 *func_800A3D84(s16 arg0, u8 *arg1, s32 *arg2, s32 arg3) {
    s16 idx;
    u8 *n;
    u8 pad[4];

    idx = func_800A3E98();
    n = D_800B6D50[idx];
    func_800A3EFC(n, arg1);
    *(s32 *)(n + 0) = D_800BD81C[arg0];
    *(s16 *)(n + 0x28) = arg0;
    *(s16 *)(n + 0x2A) = idx;
    func_8003C21C(arg3, n + 4);
    *(s32 *)(n + 0x18) = arg2[0];
    *(s32 *)(n + 0x1C) = arg2[1];
    *(s32 *)(n + 0x20) = arg2[2];
    return n;
}

void func_800A3E64(void *arg0) {
    func_800A3F78(arg0);
    func_800A3ECC(M2C_FIELD(arg0, s16 *, 0x2A));
}

s16 func_800A3E98(void) {
    s16 i;

    i = D_8010EA38;
    D_8010EA38 = D_800BDFCC[i];
    return i;
}

void func_800A3ECC(s16 arg0) {
    s16 temp_v0;

    temp_v0 = D_8010EA38;
    D_8010EA38 = arg0;
    D_800BDFCC[arg0] = temp_v0;
}

void func_800A3EFC(u8 *arg0, u8 *arg1) {
    s16 depth;

    *(u8 **)(arg0 + 0x24) = arg1;
    depth = *(s16 *)(arg1 + 0x2C) + 1;
    *(s16 *)(arg0 + 0x2C) = depth;
    *(u8 **)(arg0 + 0x30) = D_80116474[depth].unk0;
    *(u8 **)(arg0 + 0x34) = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0x34);
    *(u8 **)(D_80116474[depth].unk0 + 0x34) = arg0;
    D_80116474[depth].unk0 = arg0;
}

void func_800A3F78(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), void **, 0x34) = (void *) M2C_FIELD(arg0, void **, 0x34);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), void **, 0x30) = (void *) M2C_FIELD(arg0, void **, 0x30);
}

void func_800A3F98(void) {
    D_800BDFBC = 0;
    D_8010EBD0 = 0;
    D_800BE304 = 0;
    D_800C4C3C = D_800B4258;
    D_80110AA8 = D_800B425C;
    D_800BD7EC = D_800B4254;
}

HwSegObj *func_800A3FE8(s32 arg0) {
    HwSegObj *p;
    HwSeg *e;
    s32 a;
    s32 b;

    p = func_800A40B0();
    e = (HwSeg *)(D_800BD7EC + arg0 * 0x18);
    a = e->unk0;
    b = e->unk2;
    p->unk16 = e->unk4;
    p->unk14 = e->unkC;
    p->unk1A = e->unk8;
    p->unk18 = e->unk10;
    p->unk2 = 0;
    p->unk4 = a;
    p->unk6 = b;
    p->unk8 = 0;
    p->unk0 = a + b;
    p->unkC = func_800A40DC(a);
    p->unk10 = func_800A4110(b);
    p->unk1C = ((HwSeg *)(D_800BD7EC + arg0 * 0x18))->unk14;
    return p;
}

void *func_800A40B0(void) {
    s32 temp_v0;

    temp_v0 = D_800BE304 * 0x20;
    D_800BE304 += 1;
    return D_8010D30C + temp_v0;
}

s32 func_800A40DC(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_800BDFBC * 0x24;
    D_800BDFBC += arg0;
    return temp_v0 + D_800C4C3C;
}

s32 func_800A4110(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_8010EBD0 * 0x28;
    D_8010EBD0 += arg0;
    return temp_v0 + D_80110AA8;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A4144);

void func_800A4914(s32 arg0) {
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

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A4984);

void func_800A5294(HwUv *s, HwUv *a, HwUv *b) {
    u32 mid;

    mid = (u32)(s->v0 + s->v2 - 1) >> 1;
    a->u0 = s->u0;
    a->v0 = s->v0;
    a->u1 = s->u1;
    a->v1 = s->v1;
    a->u2 = s->u2;
    a->v2 = mid;
    a->u3 = s->u3;
    a->v3 = mid;
    a->tpage = s->tpage;
    a->clut = s->clut;
    b->u0 = s->u0;
    b->v0 = mid;
    b->u1 = s->u1;
    b->v1 = mid;
    b->u2 = s->u2;
    b->v2 = s->v2;
    b->u3 = s->u3;
    b->v3 = s->v3;
    b->tpage = s->tpage;
    b->clut = s->clut;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A535C);

void func_800A59D8(u8 *arg0, s32 arg1) {
    u32 mid;
    s32 t;
    s32 t2;

    t = arg1 << 5;
    mid = (u32)(arg0[0] + arg0[4] - 1) >> 1;
    D_8010FDC4[t] = arg0[0];
    D_8010FDC4[t + 1] = arg0[1];
    D_8010FDC8[t] = mid;
    D_8010FDC8[t + 1] = arg0[5];
    D_8010FDCC[t] = arg0[8];
    D_8010FDCC[t + 1] = arg0[9];
    D_8010FDD0[t] = mid;
    D_8010FDD0[t + 1] = arg0[0xD];
    *(u16 *)&D_8010FDC4[t + 2] = *(u16 *)&arg0[2];
    *(u16 *)&D_8010FDC8[t + 2] = *(u16 *)&arg0[6];
    t2 = ((arg1 << 1) | 1) << 4;
    D_8010FDC4[t2] = mid;
    D_8010FDC4[t2 + 1] = arg0[1];
    D_8010FDC8[t2] = arg0[4];
    D_8010FDC8[t2 + 1] = arg0[5];
    D_8010FDCC[t2] = mid;
    D_8010FDCC[t2 + 1] = arg0[9];
    D_8010FDD0[t2] = arg0[0xC];
    D_8010FDD0[t2 + 1] = arg0[0xD];
    *(u16 *)&D_8010FDC4[t2 + 2] = *(u16 *)&arg0[2];
    *(u16 *)&D_8010FDC8[t2 + 2] = *(u16 *)&arg0[6];
}

void func_800A5BA8(void) {
    s32 i;
    s32 j;
    s32 k;

    func_800AB12C();
    if (D_800BC4D4 == 0) {
        D_800C4C44 = D_800B428C;
    }
    if (D_800BC4D4 == 1) {
        D_800C4C44 = D_800B42C4;
    }
    D_80110B98 = 0;
    D_801163EC = 0;
    D_8010FDA8 = 0;
    D_8010FDAC = 0;
    D_8010FDB0 = 0;
    D_8010FD3C = 1;
    D_800BE554 = 0;
    D_801163F4 = 0;
    D_80110B98 = 0;
    D_80116440 = 0;
    D_80110BE8 = 0;
    D_80110BBC = 0;
    D_80110BB0 = 0;
    D_80110B94 = 0;
    D_8010EBD4 = 0;
    D_8010EB8C = 0;
    D_8010EADC = 0;
    if (D_800BC4D4 == 0) {
        D_801163E4 = D_800B4290;
    }
    if (D_800BC4D4 == 1) {
        D_801163E4 = D_800B42C8;
    }
    D_80110BD4 = 0;
    D_80110CCC = 0;
    D_80110BCC = 0;
    D_80110CC8 = 0;
    for (i = 0; i < 0x50; i++) {
        for (j = 0; j < 10; j++) {
            D_800BE59E[i].v[j] = 0;
        }
    }
    for (k = 0; k < 10; k++) {
        D_800BD598[k].a = 0;
        D_800BD598[k].b = 0;
        D_800BD598[k].c = 0;
    }
    D_8010EBC8 = 0;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A5D6C);

void func_800A64B0(void) {
    s32 i;

    for (i = 0; i < D_800BE698[D_801163A0].n; i++) {
        func_800A3E64(D_800BE648[D_801163A0].p[i]);
    }
    D_800BE698[D_801163A0].n = 0;
}

void func_800A65B4(s32 arg0, s32 arg1, HwV3L *arg2) {
    s32 t;
    s32 f;
    HwRoadPt *p0;
    HwRoadPt *p1;

    t = arg0 >> 8;
    D_80110BB8->unk30.x = arg1 << 18;
    D_80110BB8->unk30.y = 0;
    D_80110BB8->unk30.z = 0;
    f = arg0 & 0xFF;
    p0 = &D_800BE558[t % 80];
    p1 = &D_800BE558[(t + 1) % 80];
    func_8003AB84(p0->unk18, &D_80110BB8->unk30, &D_80110BB8->unk40);
    func_8003AB84(p1->unk18, &D_80110BB8->unk30, &D_80110BB8->unk50);
    D_80110BB8->unk60.x = (D_80110BB8->unk40.x >> 18) + p0->unk0;
    D_80110BB8->unk60.y = (D_80110BB8->unk40.y >> 18) + p0->unk4;
    D_80110BB8->unk60.z = (D_80110BB8->unk40.z >> 18) + p0->unk8;
    D_80110BB8->unk70.x = (D_80110BB8->unk50.x >> 18) + p1->unk0;
    D_80110BB8->unk70.y = (D_80110BB8->unk50.y >> 18) + p1->unk4;
    D_80110BB8->unk70.z = (D_80110BB8->unk50.z >> 18) + p1->unk8;
    arg2->x = (((D_80110BB8->unk70.x - D_80110BB8->unk60.x) * f) >> 8) + D_80110BB8->unk60.x;
    arg2->y = (((D_80110BB8->unk70.y - D_80110BB8->unk60.y) * f) >> 8) + D_80110BB8->unk60.y;
    arg2->z = (((D_80110BB8->unk70.z - D_80110BB8->unk60.z) * f) >> 8) + D_80110BB8->unk60.z;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A67B8);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A6B18);

void func_800A6E00(void) {
    HwV3L a;
    HwSVec b;
    HwB8 c;
    u8 id;
    s16 x;
    s16 y;
    u16 fl;
    u16 w;
    s32 cnt;
    s32 i;

    cnt = 0;
    c = D_800A0008;
    for (i = 0; i < 10; i++) {
        func_800AB348((u8)i, &id, &x, &y, &fl, &w);
        if (id == 0) {
            if (fl & 2) {
                func_800A6B18(D_801163A0 << 8, x, &a, &b);
                D_800BD598[i].a = a.x;
                D_800BD598[i].b = a.y;
                D_800BD598[i].c = a.z;
            }
        }
        if (id != 0) {
            if (i < 6) {
                func_800A6B18(D_801163A0 << 8, x, &a, &b);
                b.x = 0;
                b.z = 0;
                b.y = b.y + w;
            } else {
                func_800A67B8(D_801163A0 << 8, x, &a, &b);
                b.y = b.y + w;
            }
            if (fl & 1) {
                a.y = D_800BD598[i].b - y;
            } else {
                a.y = a.y - y;
            }
            D_800BE558[D_801163A0].p[cnt] = func_800A3D84(id, (u8 *)&D_8010EB90, &a.x, (s32)&b);
            cnt++;
            D_800BE558[D_801163A0].n++;
        }
    }
}

void func_800A7050(void) {
    D_800BE2EC = 0x78;
    D_800BC4E0 = 0x8E;
    D_800BC4E4 = 0x95;
    D_800BC4E8 = 0x94;
    D_800BDFB8 = 0;
    D_800BC4EC = 0xB1;
    func_800A714C(0);
    func_800A714C(1);
    func_800A714C(2);
    func_800A714C(3);
    func_800A714C(4);
    func_800A714C(5);
    func_800A71E8();
}

void func_800A70E4(s32 arg0, s32 arg1) {
    D_800BE2F4 = arg1;
    D_800BD818 = arg0;
    func_800A7C34();
    func_800A8010();
    func_800A8B48();
    func_800A7A50();
    func_800A9658();
    func_800A9A9C();
    func_800AFC28();
    func_800AA03C();
}

void func_800A714C(s32 arg0) {
    s32 i;
    s32 *p;

    p = D_800B4F4C[arg0].unk40;
    D_800B4F4C[arg0].unk0 = 0;
    D_800B4F4C[arg0].unk4 = 0;
    D_800B4F4C[arg0].unk8 = 0;
    D_800B4F4C[arg0].unk10 = 0;
    D_800B4F4C[arg0].unk12 = 0;
    D_800B4F4C[arg0].unk14 = 0;
    for (i = 0; i < 80; i++) {
        p[i] = 0;
    }
    p[0] = 5;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A71E8);

void func_800A780C(s32 arg0, s32 *arg1) {
    s32 *p;
    s32 t;

    p = (s32 *)((u8 *)&D_800B4F8C + arg0 * 0x180);
    p[0x2C / 4] = 0xBB800;
    p[0x38 / 4] = 0x1F400;
    D_800BDFB8 += 1;
    p[4 / 4] = 2;
    p[0x14 / 4] = 3;
    p[0x10 / 4] = 2;
    p[0x4C / 4] = 0x46;
    p[0x50 / 4] = 0x46;
    p[0x48 / 4] = 0;
    p[0xA0 / 4] = 1;
    p[0x60 / 4] = 0x14;
    p[0x64 / 4] = 0x64;
    p[0x68 / 4] = 0x24;
    p[0] = 5;
    p[0x6C / 4] = 0x24;
    p[0x78 / 4] = 0x400;
    p[0x80 / 4] = 0x400;
    p[0x7C / 4] = 0x1C2;
    p[0x84 / 4] = 0x14;
    t = func_800A3C18(0x61, 0, 0, 1, &D_8010EB90, 0, 0, 0, 0, 0, 0);
    D_800B4F4C[arg0].unk18[0] = (void *)t;
    D_800B4F4C[arg0].unk18[1] = (void *)func_800A3C18(0x9B, 0, 0, 1, (M2C_UNK *)t, 0, 0, 0x78, 0, 0, 0);
    D_800B4F4C[arg0].unk18[2] = (void *)func_800A3C18(0x94, 0, 0, 1, (M2C_UNK *)D_800B4F4C[arg0].unk18[0], 0, 0, 0, 0, 0, 0);
    switch (arg0) {
    case 2:
        p[0x18 / 4] = 0xFFFF3800;
        p[0x20 / 4] = 0xFFF44800;
        break;
    case 3:
        p[0x18 / 4] = 0;
        p[0x20 / 4] = 0xFFF44800;
        break;
    case 4:
        p[0x18 / 4] = 0xC800;
        p[0x20 / 4] = 0xFFF44800;
        break;
    }
}

void func_800A7A48(void) {
}

void func_800A7A50(void) {
    func_800A7AF0(0);
    func_800A7AF0(1);
    if (D_800B528C != 5) {
        func_800A7AF0(2);
    }
    if (D_800B540C != 5) {
        func_800A7AF0(3);
    }
    if (D_800B558C != 5) {
        func_800A7AF0(4);
    }
    if (D_800B570C != 5) {
        func_800A7AF0(5);
    }
}

void func_800A7AF0(s32 arg0) {
    u8 pad[0x20];
    s32 *p;
    s32 v;
    s32 t;
    s32 n;
    s32 a;
    s32 i;

    p = (s32 *)((u8 *)&D_800B4F8C + arg0 * 0x180);
    v = (p[8] >> 8) + D_8011668C;
    i = (v >> 8) % 80;
    t = ((((s16)D_800BE59C[i].h >> 1) - 0x60) << 8);
    if (arg0 != 5) {
        if (t < p[6]) {
            p[6] = t;
        }
        n = -t;
        if (p[6] < n) {
            p[6] = n;
        }
    } else {
        a = t - 0x7800;
        if (a < p[6]) {
            p[6] = a;
        }
        n = -t + 0x7800;
        if (p[6] < n) {
            p[6] = n;
        }
    }
    if (arg0 == 0) {
        if (p[8] > p[11]) {
            p[8] = p[11];
        }
        if (p[8] < p[14]) {
            p[8] = p[14];
        }
    }
}

void func_800A7C34(void) {
    if (D_800BD594 == 0 && D_800BE2EC == 0) {
        if (func_80042DA8() % 60 == 0 && D_800B528C == 5) {
            func_800A7DA0(2);
        }
        if (func_80042DA8() % 60 == 0 && D_800B540C == 5) {
            func_800A7DA0(3);
        }
        if (func_80042DA8() % 60 == 0 && D_800B558C == 5) {
            func_800A7DA0(4);
        }
    }
    if (D_800BE2EC != 0) {
        D_800BE2EC--;
    }
}

void func_800A7DA0(s32 arg0) {
    s32 i;
    s32 *p;
    s32 *q;
    s32 m;
    s32 a;
    s32 v;

    p = D_800B4F4C[arg0].unk40;
    D_800B4F4C[arg0].unk0 = 0;
    D_800B4F4C[arg0].unk4 = 0;
    D_800B4F4C[arg0].unk8 = 0;
    D_800B4F4C[arg0].unk10 = 0;
    D_800B4F4C[arg0].unk12 = 0;
    D_800B4F4C[arg0].unk14 = 0;
    for (i = 0; i < 80; i++) {
        p[i] = 0;
    }
    p[0] = 5;
    func_800A780C(arg0, p);
    q = D_800B4F4C[arg0].unk40;
    m = func_80042DA8() % 3;
    switch (m) {
    case 0:
        a = arg0 + 1;
        q[0x22] = 5;
        q[0x23] = 5;
        break;
    case 1:
        a = arg0 + 7;
        v = 0x3C;
        q[0x22] = v;
        q[0x23] = v;
        break;
    case 2:
        a = arg0 + 0xC;
        v = 0x1E;
        q[0x22] = v;
        q[0x23] = v;
        break;
    default:
        a = arg0 + 1;
        v = 0x28;
        q[0x22] = v;
        q[0x23] = v;
        break;
    }
    q = D_800B4F4C[arg0].unk40;
    q[3] = arg0 + 4;
    q[0] = 0;
    q[2] = a;
    q[0x24] = m + 0xA;
}

void func_800A7F48(s32 arg0) {
    s32 *p;
    s32 i;

    p = D_800B4F4C[arg0].unk40;
    D_800BD658[p[2]].unk0 = 0;
    D_800BD658[p[3]].unk0 = 0;
    p[0] = 5;
    for (i = 0; i < p[5]; i++) {
        func_800A3E64(D_800B4F4C[arg0].unk18[i]);
    }
}

void func_800A8010(void) {
    if (D_800B4F8C != 5) {
        func_800A80D4(0);
    }
    if (D_800B510C != 5) {
        func_800A80D4(1);
    }
    if (D_800B570C != 5) {
        func_800A80D4(5);
    }
    if (D_800B528C != 5) {
        func_800A8ADC(2);
    }
    if (D_800B540C != 5) {
        func_800A8ADC(3);
    }
    if (D_800B558C != 5) {
        func_800A8ADC(4);
    }
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A80D4);

void func_800A8ADC(s32 arg0) {
    u8 pad[0x48];
    u8 *p;

    p = (u8 *)&D_800B4F8C + arg0 * 0x180;
    if (*(s32 *)p != 5) {
        func_800AAB3C(arg0);
        if (*(s32 *)(p + 0x20) > *(s32 *)(p + 0x2C)) {
            *(s32 *)(p + 0x20) = *(s32 *)(p + 0x2C);
        }
    }
}

void func_800A8B48(void) {
    if (D_800B4F8C != 5) {
        func_800A8C0C(0);
    }
    if (D_800B510C != 5) {
        func_800A8C0C(1);
    }
    if (D_800B528C != 5) {
        func_800A8C0C(2);
    }
    if (D_800B540C != 5) {
        func_800A8C0C(3);
    }
    if (D_800B558C != 5) {
        func_800A8C0C(4);
    }
    if (D_800B570C != 5) {
        func_800A8C0C(5);
    }
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A8C0C);

void func_800A9658(void) {
    if (D_800B4F8C != 5) {
        func_800A971C(0);
    }
    if (D_800B510C != 5) {
        func_800A971C(1);
    }
    if (D_800B528C != 5) {
        func_800A971C(2);
    }
    if (D_800B540C != 5) {
        func_800A971C(3);
    }
    if (D_800B558C != 5) {
        func_800A971C(4);
    }
    if (D_800B570C != 5) {
        func_800A971C(5);
    }
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A971C);

void func_800A9A9C(void) {
    if (D_800B4F8C != 5) {
        func_800A9B60(0);
    }
    if (D_800B510C != 5) {
        func_800A9B60(1);
    }
    if (D_800B528C != 5) {
        func_800A9B60(2);
    }
    if (D_800B540C != 5) {
        func_800A9B60(3);
    }
    if (D_800B558C != 5) {
        func_800A9B60(4);
    }
    if (D_800B570C != 5) {
        func_800A9B60(5);
    }
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A9B60);

void func_800A9DE8(void *arg0, void *arg1) {
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg1, s32 *, 0x58);
    func_8003CC1C(M2C_FIELD(arg1, s32 *, 0x60) - M2C_FIELD(arg0, s32 *, 0x60), temp_a2 - M2C_FIELD(arg0, s32 *, 0x58), temp_a2);
}

void func_800A9E1C(void *arg0, void *arg1) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    void *temp_a0;
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg1, void **, 0x18);
    temp_a0 = M2C_FIELD(arg0, void **, 0x18);
    temp_v0 = M2C_FIELD(temp_a2, s32 *, 0x18) - M2C_FIELD(temp_a0, s32 *, 0x18);
    temp_v0_2 = M2C_FIELD(temp_a2, s32 *, 0x1C) - M2C_FIELD(temp_a0, s32 *, 0x1C);
    temp_v0_3 = M2C_FIELD(temp_a2, s32 *, 0x20) - M2C_FIELD(temp_a0, s32 *, 0x20);
    temp_a1 = (temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2);
    func_80039F5C(temp_a1 + (temp_v0_3 * temp_v0_3), temp_a1, temp_a2);
}

void func_800A9E88(s16 arg0, HwSVec *arg1, HwSVec *arg2, s16 *arg3) {
    HwSVec a;
    HwSVec b;
    s32 x;
    s32 y;
    s32 d;
    s32 z0;
    s32 z1;

    z0 = D_800B4F4C[arg0].unk40[0x18];
    z1 = D_800B4F4C[arg0].unk40[0x19];
    a.x = 0;
    a.y = 0;
    a.z = z0;
    b.x = 0;
    b.y = 0;
    b.z = z1;
    d = x - y;
    *arg3 = (d < 0 ? -d : d) >> 2;
    func_8003B2CC((u8 *)D_800B4F4C[arg0].unk18[0] + 4, &a, arg1);
    func_8003B2CC((u8 *)D_800B4F4C[arg0].unk18[0] + 4, &b, arg2);
    arg1->x += *(s16 *)((u8 *)D_800B4F4C[arg0].unk18[0] + 0x18);
    arg1->y += *(s16 *)((u8 *)D_800B4F4C[arg0].unk18[0] + 0x1C);
    arg1->z += *(s16 *)((u8 *)D_800B4F4C[arg0].unk18[0] + 0x20);
    arg2->x += *(s16 *)((u8 *)D_800B4F4C[arg0].unk18[0] + 0x18);
    arg2->y += *(s16 *)((u8 *)D_800B4F4C[arg0].unk18[0] + 0x1C);
    arg2->z += *(s16 *)((u8 *)D_800B4F4C[arg0].unk18[0] + 0x20);
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AA03C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AA438);

void func_800AA7FC(s32 arg0, s32 arg1) {
    s32 *p;
    typeof(D_800B4F4C[0]) *a;
    s32 t;
    s32 x;
    s32 r;

    p = D_800B4F4C[arg0].unk40;
    switch (p[1]) {
    case 0:
        break;
    case 1:
        a = &D_800B4F4C[arg0];
        x = D_800B5124;
        func_8003CC1C(D_800B512C - a->unk40[8], x - a->unk40[6], x);
        p[0] = 1;
        p[0x40] = 0x12;
        break;
    case 2:
        if (p[0x22] <= 0) {
            D_800BDFB4 += 0x1F4;
            func_800AD94C(0x138, 1, 0xA);
            p[0] = 2;
            r = func_80042DA8();
            p[0x42] = 0x3B;
            p[0x44] = 0;
            p[4] = p[4] - 1;
            p[0x46] = r % 3;
            if (D_800BDFB8 != 1 && D_80110A8C == 1) {
                func_800AC304(func_80042DA8() % 2 + 3, 4, 0x9C40);
            }
            D_800BDFB8--;
        } else {
            p[0x22] = p[0x22] - arg1;
            p[0] = 1;
            p[0x41] = 0x1C;
            t = D_800B4F4C[arg0].unk40[3];
            if (t != 0x13) {
                D_800BC75C[t].unk0 = 0xFF;
            }
        }
        break;
    }
}

void func_800AA9E4(s32 arg0, s32 arg1) {
    if (D_800BDFB4 != 0) {
        D_800BDFB4 -= 0x32;
    }
    arg1 += 0x800;
    arg1 -= (arg1 / 0x1000) * 0x1000;
    if ((u32)arg1 < 0x400) {
        func_800AE98C(2, 0x190);
    }
    if ((u32)(arg1 - 0x400) < 0x400) {
        func_800AE98C(3, 0x190);
    }
    if ((u32)(arg1 - 0x800) < 0x400) {
        func_800AE98C(1, 0x190);
    }
    if ((u32)(arg1 - 0xC00) < 0x400) {
        func_800AE98C(4, 0x190);
    }
    D_800BC75C[D_800B5114].unk0 = 0xFF;
}

void func_800AAACC(s32 arg0, s32 arg1) {
    u8 *p;
    s32 a;
    s32 b;

    p = (u8 *)&D_800B4F8C + arg0 * 0x180;
    func_800AC374(arg1);
    a = D_800BC67C;
    b = D_800BD550;
    *(s32 *)(p + 0xCC) = 1;
    *(s32 *)(p + 0xD8) = 0;
    *(s32 *)(p + 0xD0) = a;
    *(s32 *)(p + 0xD4) = ((b - 1) << 0x10) - 1;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AAB3C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AB12C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AB348);

void func_800AB634(u8 arg0, u8 arg1, u8 *arg2, u8 *arg3) {
    u8 *p;

    p = D_800BDB00[arg0] + arg1 * 3;
    *arg2 = p[0];
    *arg3 = p[1];
}

void func_800AB674(void) {
    D_80110A8C = 1;
    D_800B41E0 = -0x7D0;
    D_800B41D8 = 0;
    D_800B41DC = 0;
    D_800B41E8 = 0;
    D_800B41EC = 0;
    D_800B41F0 = 0;
    D_800B41F8 = 0;
    D_800B41FC = 0;
    D_800B4200 = 0;
    D_800B4208 = 0;
    D_800B420C = 0;
    D_800B4210 = -0x1F4;
    D_8010EA2C = 0;
    D_801163A8 = 0;
    D_800BE2F8 = 0;
    D_800BE2FA = 0;
    D_800BE2FC = 0;
    D_801163F8 = D_800B42D0;
    D_800BE550 = D_800B42D4;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AB738);

void func_800AC2FC(void) {
}

void func_800AC304(s32 arg0, s8 arg1, s32 arg2) {
    D_80110A8C = arg1;
    func_800AC374(arg0 & 0xFF);
    D_800BE538 = 0;
    D_800BDFC8 = arg2;
    D_800BDFAC = D_800BC67C;
    D_800BDFC0 = ((D_800BD550 - 1) << 0x10) - 1;
}

void func_800AC374(u8 arg0) {
    D_800BD550 = ((s32 *)D_800B42D0)[arg0];
    D_800BC67C = ((s32 *)D_800B42D4)[arg0] + D_800B42D8;
}

void func_800AC3C4(u32 arg0, s32 arg1, HwV3L *arg2, u8 arg3) {
    HwV3S a;
    HwV3S b;
    HwV3L d;
    HwV3S *e;
    HwV3S *f;
    s32 t;

    e = (HwV3S *)((arg0 >> 16) * 8 + arg1);
    f = e + 1;
    a.x = e->x;
    a.y = e->y;
    a.z = e->z;
    t = arg0 & 0xFFFF;
    b.x = f->x;
    b.y = f->y;
    b.z = f->z;
    d.x = b.x - a.x;
    d.y = b.y - a.y;
    d.z = b.z - a.z;
    d.x = t * d.x;
    d.y = t * d.y;
    d.z = t * d.z;
    d.x >>= 16;
    d.y >>= 16;
    d.z >>= 16;
    if (arg3 == 0) {
        arg2->x = -e->x - d.x;
        arg2->y = -e->y - d.y;
        arg2->z = -e->z - d.z;
    } else {
        arg2->x = -e->x - d.x;
        arg2->y = e->y + d.y;
        arg2->z = e->z + d.z;
    }
}

void func_800AC518(void) {
    D_80110ABC = 0;
    D_800BDFB0 = 0;
    D_800BDFC4 = 0;
    D_800BC4D8 = 0;
}

void func_800AC540(void) {
    s32 r;
    u8 pad[16];

    if (D_800BC4D8 == 0) {
        D_800BD580 = ((s32 (*)(s32))func_8001C808)(1);
        r = 0;
    } else {
        D_800BD580 = 0;
        r = 0;
    }
    if (r == 0) {
        D_800BDFB0 = 0;
        D_800BDFC4 = 0;
        if (D_800BD580 & 0x8000) {
            D_800BDFB0 = 4;
        }
        if (D_800BD580 & 0x2000) {
            D_800BDFB0 = 6;
        }
        if (D_800BD580 & 0x1000) {
            D_800BDFB0 = 8;
            if (D_800BD580 & 0x8000) {
                D_800BDFB0 = 7;
            }
            if (D_800BD580 & 0x2000) {
                D_800BDFB0 = 9;
            }
        }
        if (D_800BD580 & 0x4000) {
            D_800BDFB0 = 2;
            if (D_800BD580 & 0x8000) {
                D_800BDFB0 = 1;
            }
            if (D_800BD580 & 0x2000) {
                D_800BDFB0 = 3;
            }
        }
        if (D_800BD580 & 0x80) {
            D_800BDFC4 = 1;
        }
        if (D_800BD580 & 0x20) {
            D_800BDFC4 = 2;
        }
    }
}

INCLUDE_RODATA("../asm/us/highway/nonmatchings/text", D_800A0008);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AC680);

s32 func_800AC9C0(void *arg0) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_v1;
    s32 var_a2;
    s32 var_t2;

    temp_a2 = (s32) M2C_FIELD(arg0, s32 *, 0) >> 2;
    temp_a1 = (s32) M2C_FIELD(arg0, s32 *, 4) >> 2;
    temp_v1 = (s32) M2C_FIELD(arg0, s32 *, 8) >> 2;
    var_t2 = 0;
    var_a2 = 0;
    temp_a3 = (temp_a2 * D_80110A98) + (temp_a1 * D_80110A9C) + (temp_v1 * D_80110AA0) + D_800BDFA4;
    temp_a0 = (temp_a2 * D_80110AAC) + (temp_a1 * D_80110AB0) + (temp_v1 * D_80110AB4) + D_800BDFA8;
    if (temp_a3 > 0) {
        var_t2 = D_800BC674 > 0;
    }
    if ((temp_a3 < 0) && (D_800BC674 < 0)) {
        var_t2 = 1;
    }
    if ((temp_a0 > 0) && (D_800BC6AC > 0)) {
        var_a2 = 1;
    }
    if ((temp_a0 < 0) && (D_800BC6AC < 0)) {
        var_a2 = 1;
    }
    return var_t2 & var_a2;
}

s32 func_800ACAF0(void *arg0) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_v1;
    s32 var_a2;
    s32 var_t2;

    temp_a2 = (s32) (M2C_FIELD(arg0, u16 *, 0) << 0x10) >> 0x12;
    temp_a1 = (s32) (M2C_FIELD(arg0, u16 *, 2) << 0x10) >> 0x12;
    temp_v1 = (s32) (M2C_FIELD(arg0, u16 *, 4) << 0x10) >> 0x12;
    var_t2 = 0;
    var_a2 = 0;
    temp_a3 = (temp_a2 * D_80110A98) + (temp_a1 * D_80110A9C) + (temp_v1 * D_80110AA0) + D_800BDFA4;
    temp_a0 = (temp_a2 * D_80110AAC) + (temp_a1 * D_80110AB0) + (temp_v1 * D_80110AB4) + D_800BDFA8;
    if (temp_a3 > 0) {
        var_t2 = D_800BC674 > 0;
    }
    if ((temp_a3 < 0) && (D_800BC674 < 0)) {
        var_t2 = 1;
    }
    if ((temp_a0 > 0) && (D_800BC6AC > 0)) {
        var_a2 = 1;
    }
    if ((temp_a0 < 0) && (D_800BC6AC < 0)) {
        var_a2 = 1;
    }
    return var_t2 & var_a2;
}

s32 func_800ACC34(s32 arg0, s32 arg1, s32 arg2) {
    return ((arg0 >> 2) * D_80110A98) + ((arg1 >> 2) * D_80110A9C) + ((arg2 >> 2) * D_80110AA0) + D_800BDFA4;
}

s32 func_800ACC88(s32 arg0, s32 arg1, s32 arg2) {
    return ((arg0 >> 2) * D_80110AAC) + ((arg1 >> 2) * D_80110AB0) + ((arg2 >> 2) * D_80110AB4) + D_800BDFA8;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800ACCDC);

u32 func_800ACED4(s32 arg0, s32 arg1, s32 arg2, s16 arg3) {
    s32 v;
    s32 d;
    u32 r;

    r = 0;
    v = ((arg0 >> 2) * D_80110A98) + ((arg1 >> 2) * D_80110A9C) + ((arg2 >> 2) * D_80110AA0) + D_800BDFA4;
    if (D_800BC674 > 0) {
        r = (u32)~v >> 0x1F;
    }
    if ((D_800BC674 < 0) && (v <= 0)) {
        r = 1;
    }
    if (r == 0) {
        d = D_800C4C40;
        if (v < 0) {
            v = -v;
        }
        if ((v / d) < arg3) {
            r = 1;
        }
    }
    return r;
}

u32 func_800ACFBC(s32 arg0, s32 arg1, s32 arg2, s16 arg3) {
    s32 v;
    s32 d;
    u32 r;

    r = 0;
    v = ((arg0 >> 2) * D_80110AAC) + ((arg1 >> 2) * D_80110AB0) + ((arg2 >> 2) * D_80110AB4) + D_800BDFA8;
    if (D_800BC6AC > 0) {
        r = (u32)~v >> 0x1F;
    }
    if ((D_800BC6AC < 0) && (v <= 0)) {
        r = 1;
    }
    if (r == 0) {
        d = D_800C4C48;
        if (v < 0) {
            v = -v;
        }
        if ((v / d) < arg3) {
            r = 1;
        }
    }
    return r;
}

void func_800AD0A4(void) {
    D_801163E8 = (void *)&D_8010EBDC;
    D_80110BB8 = (HwRoadTmp *)0x1F800000;
    D_8010EA30 = 0x1F800000;
    D_80116678 = 0x1F8000A8;
    D_8010EA34 = 0x1F8000C8;
    D_8011632C = 0x1F800108;
    D_80116330 = 0x1F800110;
    D_80116334 = 0x1F800118;
    D_80116338 = 0x1F800120;
    D_8011633C = 0x1F800128;
    D_80116340 = 0x1F800130;
    D_80116344 = 0x1F800138;
    D_80116348 = 0x1F800140;
    D_8011634C = 0x1F800148;
    D_80116350 = 0x1F800150;
    D_80116354 = 0x1F800158;
    D_8011636C = 0x1F800160;
    D_80116370 = 0x1F800164;
    D_80116374 = 0x1F800168;
    D_80116378 = 0x1F80016C;
    D_8011637C = 0x1F800170;
    D_80116380 = 0x1F800174;
    D_80116384 = 0x1F800178;
    D_80116388 = 0x1F80017C;
    D_8011638C = 0x1F800180;
    D_80116390 = 0x1F800184;
    D_80116394 = 0x1F800188;
    func_8003BF8C(&D_800B4220, &D_8010EBDC);
    func_8003BF8C(&D_800B4220, (u8 *)D_801163E8 + 0x20);
    func_8003BF8C(&D_800B4220, (u8 *)D_801163E8 + 0x40);
    func_8003B32C(D_801163E8, &D_800B4228);
    func_8003B32C((u8 *)D_801163E8 + 0x20, &D_800B4228);
    func_8003B32C((u8 *)D_801163E8 + 0x40, &D_800B4228);
    func_8003B32C((u8 *)D_801163E8 + 0x60, &D_800B4228);
    func_8003BF8C(&D_800B4220, &D_800BD55C);
    func_8003B32C(&D_800BD55C, &D_800B4228);
}

void func_800AD374(void) {
    D_800BD4C0 = func_800A3C18(0xAE, 0, 0, 1, &D_8010EB90, 0, 0, 0, 0, 0, 0);
    D_800BD4C4 = func_800A3C18(0xA5, 0, 0, 1, &D_8010EB90, 0, 0, 0, 0, 0, 0);
    D_800BD4C8 = func_800A3C18(0xA3, 0, 0, 1, &D_8010EB90, 0, 0, 0, 0, 0, 0);
    D_800BD4CC = func_800A3C18(0xA7, 0, 0, 1, &D_8010EB90, 0, 0, 0, 0, 0, 0);
}

void func_800AD47C(s32 arg0) {
    if (D_801163AC == 1) {
        func_800A2F4C(arg0, D_800BD4C0, -0x1F4);
    }
    if (D_801163B0 == 1) {
        func_800A2F4C(arg0, D_800BD4C4, -0x12C);
    }
    if (D_801163B4 == 1) {
        func_800A2F4C(arg0, D_800BD4C8, 0);
    }
    if (D_801163B8 == 1) {
        func_800A30A0(arg0, D_800BD4CC, -0x1F4);
    }
}

INCLUDE_RODATA("../asm/us/highway/nonmatchings/text", D_800A0050);

void func_800AD534(void) {
    HwMat32 m;
    s32 i;
    u16 t;

    m = D_800A0050;
    func_8003B4BC(&m);
    func_80039BE0(D_800BD63C, D_80116424, 0x12C);
    D_800BD63C = 0x1964;
    D_80116424 = 0x2CEC;
    D_800BD640 = 0x41A0;
    D_80116428 = 0x4F4C;
    D_800BD534 = 0x7A;
    D_800BD638 = 0x80;
    D_80110B88 = 0;
    D_8010EBCC = 0;
    D_800BD594 = 0;
    D_80110CD4 = 0;
    D_8010EB88 = 0;
    D_8010FDB8 = 0;
    D_800BC680 = 0;
    D_801163A4 = 0;
    D_80110BC4 = 0;
    D_80110BC8 = 0;
    D_80110BD0 = 0;
    D_80110BD8 = 0;
    D_800C4C30 = 0;
    D_800C4C34 = 0;
    D_80110044[0].h = 0xFFFF;
    D_80110044[2].h = 0xFFFF;
    D_80110044[4].h = 0xFFFF;
    D_80110044[1].h = 0xFFFF;
    D_80110044[3].h = 0xFFFF;
    for (i = 0; i < 5; i++) {
        t = D_80110044[i].h;
        D_80110048[i].h = 0;
        D_80110048[i].h2 = 0;
        D_8011004C[i].a = 0;
        D_8011004C[i].b = 1;
        D_80110046[i].h = t;
    }
    D_80116680 = 0;
    D_800BC678 = 0;
    D_801163AC = 0;
    D_801163B0 = 0;
    D_801163B4 = 0;
    D_801163B8 = 0;
    D_8010EAE0 = 0;
    D_800BC670 = 0;
    D_800BC4DC = 1;
    D_800BD558 = 0;
    if (D_800BC4D4 == 0) {
        D_8010EB84 = D_800B4294;
    }
    if (D_800BC4D4 == 1) {
        D_8010EB84 = D_800B42CC;
    }
}

void func_800AD7AC(void) {
    func_80033E34(D_800B4238, D_800B423C, 0x80120000, 0);
    do {

    } while (func_80034B44() != 0);
    func_800A4144();
    func_800A4984();
    func_80033E34(D_800B4240, D_800B4244, 0x801A0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80033E34(D_800B4248, D_800B424C, 0x80120000, 0);
    do {

    } while (func_80034B44() != 0);
}

void func_800AD854(void) {
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

void func_800AD8C8(void) {
    s16 *p = &D_8009A000;

    *p = 0xC0;
    D_8009A004 = 0x7F;
    func_8002DA7C();
    *p = 0xB8;
    D_8009A004 = 0x7F;
    func_8002DA7C();
    *p = 0x10;
    D_8009A004 = D_800B4250;
    func_8002DA7C();
}

void func_800AD94C(s32 arg0, s32 arg1, s32 arg2) {
    s32 r;

    r = 0;
    if (arg1 == 1) {
        r = D_800C4C30 > 0;
    }
    if (arg1 == 2 && D_800C4C34 > 0) {
        r = 1;
    }
    if (arg1 == 1) {
        if (arg2 < 0) {
            D_8009A000 = 0x28;
            D_8009A004 = 0;
            D_8009A008 = arg0;
            r = 0;
            func_8002DA7C();
        }
    }
    if (arg1 == 2) {
        if (arg2 < 0) {
            D_8009A000 = 0x29;
            D_8009A004 = 0;
            D_8009A008 = arg0;
            r = 0;
            func_8002DA7C();
        }
    }
    if (r != 1) {
        if (arg1 == 1) {
            D_8009A000 = 0x28;
        }
        if (arg1 == 2) {
            D_8009A000 = 0x29;
        }
        if (arg1 == 3) {
            D_8009A000 = 0x2A;
        }
        if (arg1 == 4) {
            D_8009A000 = 0x2B;
        }
        D_8009A004 = 0x40;
        D_8009A008 = arg0;
        func_8002DA7C();
    }
    if (r == 0) {
        if (arg1 == 1) {
            D_800C4C30 = arg2;
        }
        if (arg1 == 2) {
            D_800C4C34 = arg2;
        }
    }
    if (arg1 == 1) {
        if (arg2 < 0) {
            D_800C4C30 = -arg2;
        }
    }
    if (arg1 == 2 && arg2 < 0) {
        D_800C4C34 = -arg2;
    }
}

void func_800ADB20(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        D_8009A000 = 0xB0;
    }
    if (arg1 == 2) {
        D_8009A000 = 0xB1;
    }
    if (arg1 == 3) {
        D_8009A000 = 0xB2;
    }
    if (arg1 == 4) {
        D_8009A000 = 0xB3;
    }
    D_8009A004 = arg0;
    func_8002DA7C();
}

void func_800ADBA0(s32 arg0, u8 arg1) {
    if (arg1 == 1) {
        D_8009A000 = 0xA0;
    }
    if (arg1 == 2) {
        D_8009A000 = 0xA1;
    }
    if (arg1 == 3) {
        D_8009A000 = 0xA2;
    }
    if (arg1 == 4) {
        D_8009A000 = 0xA3;
    }
    D_8009A004 = arg0;
    func_8002DA7C();
}

void func_800ADC24(s16 arg0, u8 arg1) {
    if (arg1 == 1) {
        D_8009A000 = 0xA8;
    }
    if (arg1 == 2) {
        D_8009A000 = 0xA9;
    }
    if (arg1 == 3) {
        D_8009A000 = 0xAA;
    }
    if (arg1 == 4) {
        D_8009A000 = 0xAB;
    }
    D_8009A004 = arg0;
    func_8002DA7C();
}

void func_800ADCB4(void) {
    s32 i;

    D_80110CD4 += D_800BD534;
    D_8010FDB8 += D_800BD534;
    D_800BC680 = D_8010FDB8 >> 8;
    D_8010FDB8 &= 0xFF;
    D_8010EB88 += D_800BC680;
    D_8011668C = D_80110CD4 + 0x2300;
    for (i = 0; i < D_800BC680; i++) {
        func_800A64B0();
        func_800A5D6C();
    }
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800ADD6C);

s32 func_800AE6B4(HwFadeCtx *arg0, s32 arg1) {
    HwPolyG4 *g;
    HwPolyFT4 *p;

    switch (arg1 & 0xFF) {
    case 1:
        D_800BC670 = 0xFC;
        arg1 = 3;
        break;
    case 2:
        D_800BC670 = 0;
        arg1 = 4;
        break;
    case 3:
        D_800BC670 += 0xFC;
        if (D_800BC670 == 0) {
            arg1 = 0;
        }
        break;
    case 4:
        D_800BC670 = D_800BC670 < 0xF0 ? D_800BC670 + 4 : 0xFF;
        break;
    }
    g = arg0->prim4;
    p = arg0->prim;
    g->r0 = D_800BC670;
    g->g0 = D_800BC670;
    g->b0 = D_800BC670;
    g->r1 = D_800BC670;
    g->g1 = D_800BC670;
    g->b1 = D_800BC670;
    g->r2 = D_800BC670;
    g->g2 = D_800BC670;
    g->b2 = D_800BC670;
    g->r3 = D_800BC670;
    g->g3 = D_800BC670;
    g->x0 = 0;
    g->y0 = 0;
    g->x1 = 0x140;
    g->y1 = 0;
    g->x2 = 0;
    g->y2 = 0xF0;
    g->x3 = 0x140;
    g->y3 = 0xF0;
    g->b3 = D_800BC670;
    func_80046848(g, 1);
    g->tag.addr = arg0->ot.addr;
    arg0->ot.addr = (u32)g;
    g++;
    p->x0 = 0;
    p->y0 = 0;
    p->x1 = 0;
    p->y1 = 0;
    p->x2 = 0;
    p->y2 = 0;
    p->x3 = 0;
    p->y3 = 0;
    p->r0 = 0;
    p->g0 = 0;
    p->b0 = 0;
    p->u0 = 0;
    p->v0 = 0;
    p->u1 = 0;
    p->v1 = 0;
    p->u2 = 0;
    p->v2 = 0;
    p->u3 = 0;
    p->v3 = 0;
    p->tpage = func_8004656C(1, 2, 0x140, 0xE0);
    p->clut = func_80046634(0x10, 0x1E4);
    p->tag.addr = arg0->ot.addr;
    arg0->ot.addr = (u32)p;
    p++;
    arg0->prim = p;
    arg0->prim4 = g;
    return arg1 & 0xFF;
}

void func_800AE98C(s32 arg0, s16 arg1) {
    u32 n;
    u8 f;
    s32 t;
    s32 a;

    if (D_8011005A < 0x1E) {
        if ((arg0 & 0xFF) == 2) {
            arg1 = 0;
        }
    }
    D_8011004C[arg0 & 0xFF].a = 0x70;
    D_80110048[arg0 & 0xFF].h = arg1 + D_80110048[arg0 & 0xFF].h;
    if (arg1 < D_80110046[arg0 & 0xFF].h) {
        D_80110046[arg0 & 0xFF].h = D_80110046[arg0 & 0xFF].h - arg1;
    } else {
        D_80110046[arg0 & 0xFF].h = 0;
    }
    if (D_80110046[arg0 & 0xFF].h == 0) {
        f = 0;
        n = 0;
        do {
            t = (arg0 & 0xFF) + (n & 0xFF);
            a = (t % 4) + 1;
            n += 1;
            if (D_80110046[a & 0xFF].h != 0) {
                arg0 = a;
                f = 1;
            }
        } while ((n & 0xFF) < 4);
        if (f == 1) {
            D_8011004C[arg0 & 0xFF].a = 0x70;
            D_80110048[arg0 & 0xFF].h = arg1 + D_80110048[arg0 & 0xFF].h;
            if (arg1 < D_80110046[arg0 & 0xFF].h) {
                D_80110046[arg0 & 0xFF].h = D_80110046[arg0 & 0xFF].h - arg1;
            } else {
                D_80110046[arg0 & 0xFF].h = 0;
            }
        }
    }
}

void func_800AEB88(s32 arg0) {
    s32 i;
    s32 r;

    for (i = 0; i < 5; i++) {
        r = func_80042DA8();
        if (r == r / 30 * 30) {
            if (D_8011004C[i].b == 1 && D_80110046[i].h >= 0xB) {
                D_8011004C[i].b = 3;
            }
        }
        if (D_8011004C[i].b >= 2) {
            D_8011004C[i].b--;
        }
        func_800AECE4(arg0, i, D_8011004C[i].a, D_8011004C[i].b);
        if (D_8011004C[i].a != 0) {
            D_8011004C[i].a -= 8;
        }
    }
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AECE4);

void func_800AF41C(HwDrawCtx *arg0, s32 arg1, u16 arg2, s32 arg3, s16 arg4) {
    HwPolyFT4 *p;
    s32 d;
    s32 v;
    s32 i;
    s32 a;
    s32 w;
    u8 f;

    d = 10000;
    f = 1;
    v = arg1 + 1;
    i = 0;
    p = arg0->prim;
    do {
        a = 0;
        while (d < v) {
            v -= d;
            a++;
        }
        if (a != 0) {
            f = 0;
        }
        if (arg1 == 0 && d == 1) {
            f = 0;
        }
        if (arg4 == 1 || a != 0 || f == 0) {
            p->x0 = arg2 + i * 12;
            p->y0 = arg3;
            w = i * 12 + 16;
            p->x1 = arg2 + w;
            p->y1 = arg3;
            p->x2 = arg2 + i * 12;
            p->y2 = arg3 + 0x10;
            p->x3 = arg2 + w;
            p->y3 = arg3 + 0x10;
            p->r0 = 0x80;
            p->g0 = 0x80;
            p->b0 = 0x80;
            p->u0 = a * 16;
            p->v0 = 0xC8;
            p->u1 = a * 16 + 15;
            p->v1 = 0xC8;
            p->u2 = a * 16;
            p->v2 = 0xD7;
            p->u3 = a * 16 + 15;
            p->v3 = 0xD7;
            p->tpage = D_800BD7F0[0];
            p->clut = D_80116690[0];
            func_80046848(p, 0);
            p->tag.addr = arg0->ot.addr;
            arg0->ot.addr = (u32)p;
            p++;
        }
        i++;
        d /= 10;
    } while (i < 5);
    arg0->prim = p;
}

void func_800AF640(HwDrawCtx *arg0, s32 arg1, u16 arg2, s32 arg3, s16 arg4) {
    HwPolyFT4 *p;
    s32 d;
    s32 v;
    s32 i;
    s32 a;
    s32 w;
    u8 f;

    d = 10000;
    f = 1;
    v = arg1 + 1;
    i = 0;
    p = arg0->prim;
    do {
        a = 0;
        while (d < v) {
            v -= d;
            a++;
        }
        if (a != 0) {
            f = 0;
        }
        if (arg1 == 0 && d == 1) {
            f = 0;
        }
        if (arg4 == 1 || a != 0 || f == 0) {
            p->x0 = arg2 + i * 8;
            p->y0 = arg3;
            w = i * 8 + 8;
            p->x1 = arg2 + w;
            p->y1 = arg3;
            p->x2 = arg2 + i * 8;
            p->y2 = arg3 + 0x10;
            p->x3 = arg2 + w;
            p->y3 = arg3 + 0x10;
            p->r0 = 0x80;
            p->g0 = 0x80;
            p->b0 = 0x80;
            p->u0 = a * 8;
            p->v0 = 0xE0;
            p->u1 = (a * 8 + 8);
            p->v1 = 0xE0;
            p->u2 = a * 8;
            p->v2 = 0xEF;
            p->u3 = (a * 8 + 8);
            p->v3 = 0xEF;
            p->tpage = D_800BD7F0[0];
            p->clut = D_80116690[0];
            func_80046848(p, 0);
            p->tag.addr = arg0->ot.addr;
            arg0->ot.addr = (u32)p;
            p++;
        }
        i++;
        d /= 10;
    } while (i < 5);
    arg0->prim = p;
}

void func_800AF858(HwDrawCtx *arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, u8 arg10) {
    HwPolyFT4 *p;
    s16 x;
    s16 y;
    s16 u;
    s16 v;

    x = arg2;
    y = arg3;
    p = arg0->prim;
    p->x0 = x;
    p->y0 = y;
    p->x1 = arg2 + arg4;
    p->y1 = y;
    p->x2 = x;
    p->y2 = arg3 + arg5;
    p->x3 = arg2 + arg4;
    p->y3 = arg3 + arg5;
    p->r0 = 0x80;
    p->g0 = 0x80;
    p->b0 = 0x80;
    u = arg6;
    v = arg7;
    p->u0 = u;
    p->v0 = v;
    p->u1 = arg6 + arg8;
    p->v1 = v;
    p->u2 = u;
    p->v2 = arg7 + arg9;
    p->u3 = arg6 + arg8;
    p->v3 = arg7 + arg9;
    p->tpage = D_800BD7F0[arg1];
    p->clut = D_80116690[arg1];
    func_80046848(p, arg10);
    p->tag.addr = arg0->ot.addr;
    arg0->ot.addr = (u32)p;
    p++;
    arg0->prim = p;
}

void func_800AF990(void) {
    HwObj *p;
    u16 *r;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 v;

    D_800B6D4C = 0;
    D_800BE53C = 0;
    D_80110A94 = 0;
    D_8010FDC0 = 0x801C0000;
    D_80116688 = (u8 *)0x801A0000;
    D_800BD658 = *(HwObj **)0x801A0004;
    for (i = 0; i < *D_80116688; i++) {
        D_8010FDC0 = func_800B0698((u8 *)&D_800BD658[i], D_8010FDC0, i);
        D_800BD658[i].unk0 = 0;
        p = &D_800BD658[i];
        D_800BC6B0[i].unkB0 = p->unk4 - 1;
        p->unk5 = 0x40;
        D_800BD658[i].unk6 = 0;
        D_800BD658[i].unk7 = 0x80;
    }
    for (i = 0; i < *D_80116688; i++) {
        for (j = 0; j < 20; j++) {
            D_800BC6B0[i].unk20[j] = 0;
        }
        n = D_800BD658[i].unk4;
        for (k = 0; k < n; k++) {
            r = (u16 *)(D_800BD658[i].unk1A + D_800BD658[i].unk1C + k * 0x10);
            v = *r;
            D_800BDF00 = r;
            D_800BC6B0[i].unk20[k] = v - 1;
        }
        D_800BC6B0[i].unk14 = 0;
        D_800BC6B0[i].unk18 = 0;
        D_800BC6B0[i].unk1C = 0;
        D_800BC6B0[i].unk98 = 0;
        D_800BC6B0[i].unk9C = 0;
        D_800BC6B0[i].unkA0 = 0;
        D_800BC6B0[i].unkA4 = 0;
        D_800BC6B0[i].unkA8 = 0;
        D_800BC6B0[i].unkAC = 0;
        D_800BC6B0[i].unkAE = 0;
    }
}

void func_800AFC28(void) {
    HwEnt *e;
    s32 i;
    s16 v;

    e = D_800BC6B0;
    for (i = 0; i < *D_80116688; i++, e++) {
        *(s32 *)0x1F800000 = 3;
        func_800B1E98(&D_800BD658[i], e, e->unkA0, e->unkA4);
    }
    e = D_800BC6B0;
    for (i = 0; i < *D_80116688; i++, e++) {
        if (e->unkAE == 1) {
            D_800BD4D0[0] = e->unkAC;
            D_800BD4D0[1] = e->unkAC >> 8;
            D_800BD4D0[2] = e->unkAC;
            D_800BD4D0[3] = e->unkAC >> 8;
            D_800BD4D0[4] = e->unkAC;
            D_800BD4D0[5] = e->unkAC >> 8;
            D_800BD4D0[6] = 1;
            func_800B2E58((u8 *)&D_800BD658[i], D_800BD4D0);
            e->unkAE = 0;
        }
        v = e->unkAC;
        if (v > 0) {
            e->unkAC = v - 0x80;
            D_800BD4D0[0] = e->unkAC;
            D_800BD4D0[1] = e->unkAC >> 8;
            D_800BD4D0[2] = e->unkAC;
            D_800BD4D0[3] = e->unkAC >> 8;
            D_800BD4D0[4] = e->unkAC;
            D_800BD4D0[5] = e->unkAC >> 8;
            D_800BD4D0[6] = 1;
            func_800B2E58((u8 *)&D_800BD658[i], D_800BD4D0);
            if (e->unkAC < 0) {
                e->unkAC = 0;
            }
            e->unkAE = 1;
        }
    }
    for (i = 0; i < *D_80116688; i++) {
        func_800B12B0(&D_800BD658[i]);
    }
}

void func_800AFE98(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        D_80110E14[i].unk0 = -1;
        D_80110E14[i].unk2 = 0;
    }
    D_80116364 = 0;
    for (i = 0; i < 100; i++) {
        D_80110AC0[i] = i + 1;
    }
}

s16 func_800AFF0C(HwRoadReq *arg0, s32 arg1, s16 arg2, s16 arg3) {
    s16 slot;
    s16 id;
    s32 off;
    M2C_UNK *parent;

    if (D_80116684 < 99) {
        D_80116684 = D_80116684 + 1;
        slot = func_800B0148();
        *(HwRoadBuf *)(D_80110D3C + slot * 0xDC) = *(HwRoadBuf *)arg0;
        off = slot * 0xDC;
        id = *(s16 *)((u8 *)arg0 + 0x2C);
        *(s16 *)((u8 *)D_80110E14 + off + 2) = 1;
        *(s16 *)((u8 *)D_80110E14 + off) = slot;
        if ((s16)arg1 == 0) {
            parent = &D_8010EB90;
        } else {
            parent = (M2C_UNK *)D_80110E10[(s16)arg1].unk0;
        }
        *(s32 *)((u8 *)D_80110E10 + off) = func_800A3C18(id, 0, 0, 1, parent, arg0->unk0, arg0->unk4, arg0->unk8, *(s16 *)((u8 *)arg0 + 0x18), *(s16 *)((u8 *)arg0 + 0x1A), *(s16 *)((u8 *)arg0 + 0x1C));
    }
    return slot;
}

void func_800B00DC(void *arg0) {
    if (M2C_SFIELD(arg0, s16 *, 0xD8) != -1) {
        D_80116684 -= 1;
        func_800A3E64(M2C_SFIELD(arg0, s32 *, 0xD4));
        func_800B017C(M2C_SFIELD(arg0, s16 *, 0xD8));
        M2C_SFIELD(arg0, s16 *, 0xD8) = -1;
        M2C_SFIELD(arg0, s16 *, 0xDA) = 0;
    }
}

s16 func_800B0148(void) {
    s16 i;

    i = D_80116364;
    D_80116364 = D_80110AC0[i];
    return i;
}

void func_800B017C(s16 arg0) {
    s16 temp_v0;

    temp_v0 = D_80116364;
    D_80116364 = arg0;
    D_80110AC0[arg0] = temp_v0;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B01AC);

void *func_800B05E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    HwRoadReq *p = &D_80110BEC;

    p->unk0 = arg0;
    D_80110BEC.unk4 = arg1;
    D_80110BEC.unk8 = arg2;
    D_80110BEC.unk28 = arg3;
    D_80110BEC.unk34 = 1;
    D_80110BEC.unkA8 = 0;
    D_80110BEC.unk2C = arg4;
    return D_80110D3C + func_800AFF0C(p, 0, arg2, arg3) * 0xDC;
}

s32 func_800B0698(u8 *arg0, s32 arg1, s32 arg2) {
    s32 pad;
    s32 ptr;
    u32 i;

    *(s32 *)(arg0 + 0x20) = arg1;
    arg1 += arg0[2] << 5;
    ptr = *(u16 *)(arg0 + 0x18) + *(s32 *)(arg0 + 0x1C);
    for (i = 0; i < arg0[3]; i++) {
        arg1 = func_800B0754(ptr + i * 0x20, arg1, 0, arg2);
    }
    func_800B2760(arg0, *(s16 *)(arg0 + 0x16), 0);
    return arg1;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B0754);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B12B0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B1550);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B1E98);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B2760);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B29E0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B2B38);

s32 func_800B2E58(u8 *arg0, u8 *arg1) {
    s16 x;
    s16 y;
    s16 z;
    u32 i;
    s32 ptr;
    s32 n;
    u8 pad[8];

    n = arg0[3];
    ptr = *(u16 *)(arg0 + 0x18) + *(s32 *)(arg0 + 0x1C);
    x = (arg1[1] << 8) | arg1[0];
    y = (arg1[3] << 8) | arg1[2];
    z = (arg1[5] << 8) | arg1[4];
    *(s32 *)0x1F800200 = arg1[6];
    for (i = 0; i < n; i++) {
        func_800B2F2C(ptr + i * 0x20, x, y, z);
    }
    return 1;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B2F2C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B3BFC);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B3D28);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B3E04);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B3EC0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B3F74);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B404C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B4114);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B414C);

INCLUDE_RODATA("../asm/us/highway/nonmatchings/text", D_800A00D0);
