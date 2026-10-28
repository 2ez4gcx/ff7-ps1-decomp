#include "common.h"
#include "field/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
extern s32 D_80083270;

INCLUDE_RODATA("../asm/us/field/nonmatchings/text2", D_800A0024);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text2", D_800A002C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text2", D_800A0034);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text2", D_800A003C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text2", D_800A0044);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text2", D_800A004C);

s32 func_800A2314(void) {
    FdRect8 r0;
    FdRect8 r1;
    FdRect8 r2;
    FdRect8 r3;
    FdRect8 r4;
    FdRect8 r5;
    FdBuf *s1;
    FdMain *m;
    u8 *sp;
    u8 *q;
    s16 n;
    s32 st;
    s32 a;

    r0 = D_800A0024;
    r1 = D_800A002C;
    r2 = D_800A0034;
    r3 = D_800A003C;
    r4 = D_800A0044;
    r5 = D_800A004C;
    D_8007EB90 = 0xA0;
    D_8007EB94 = 0x78;
    if (D_800965EC != 5 && D_800965EC != 0xD) {
        func_800AA930();
    }
    D_800E4274 = (s32)*D_8009A044 + 4;
    D_80114458 = **D_8009A044 * 0x18 + D_800E4274;
    if (D_800965EC != 5 && D_800965EC != 2 && D_800965EC != 0xD) {
        func_800A5FB4();
    }
    func_800A3020((FdPrim10 *)D_800E4DF0[0].spr, (FdPrim14 *)D_800E4DF0[0].big, (u8 *)D_800E4DF0[0].attr, (FdObj12 *)D_800E4DF0[0].obj);
    n = 1;
    func_800A3020((FdPrim10 *)D_800E4DF0[1].spr, (FdPrim14 *)D_800E4DF0[1].big, (u8 *)D_800E4DF0[1].attr, (FdObj12 *)D_800E4DF0[1].obj);
    func_800AB4AC((FdSprBuf *)&D_800E4DF0[0]);
    func_800AB4AC((FdSprBuf *)&D_800E4DF0[1]);
    m = &D_8009ABF4;
    q = (u8 *)m + 1;
    D_80114488 = 0;
    D_801142C8 = 0;
    D_800E4D44 = 0;
    D_80071C0C = 0;
    D_800965E8 = 0;
    while (1) {
        if (n == 0) {
            D_80075DEC++;
        }
        D_80075DEC &= 1;
        m->b0 = D_80075DEC;
        s1 = &D_800E4DF0[(s16)D_80075DEC];
        func_80044244(s1, 0x1000);
        func_80044244((u8 *)s1 + 0x1748C, 1);
        func_800AB2B4();
        D_80114454 = func_800A2F78(&D_80071E38, &D_80071E3C);
        m->w88 = (u16)D_80075D00->f8;
        func_800BA65C((s32)((u8 *)s1 + 0x1748C));
        D_800965E0 = m->w2A;
        func_800A4430();
        func_800A496C();
        func_800A424C((FdOsc *)((u8 *)m + 0x8A));
        func_800A424C((FdOsc *)((u8 *)m + 0x98));
        func_800A4BEC(s1);
        func_800A14D8((u8 *)D_80074EAC - 8 + D_800965E0 * 0x84, D_800716C4 + 0x38);
        if ((m->w68 & 0x90F) == 0x90F) {
            m->b1 = 0xA;
            func_80035658();
done:
            func_800A1498();
            return;
        }
        if (m->b1 == 1) {
            return;
        }
        if (m->b1 == 0xC) {
            goto done;
        }
        if (m->b1 == 0xD) {
            func_800A1498();
            D_8009C560 = 0xC;
            return;
        }
        if (m->b1 == 0x19) {
            st = 0x10;
        } else if (m->b1 == 0xF || m->b1 == 0x10 || m->b1 == 0x11 || m->b1 == 0x15 || m->b1 == 0x16 || m->b1 == 0x17 || m->b1 == 0x18) {
            st = 0xD;
        } else if (m->b1 == 6 || m->b1 == 7 || m->b1 == 9 || m->b1 == 0xE || m->b1 == 8 || m->b1 == 0x12 || m->b1 == 0x13) {
            st = 5;
        } else {
            goto rest;
        }
        D_8009C560 = st;
        goto done;
rest:
        if ((D_80114454 & 0x10) && m->b34 == 0 && *(u16 *)&D_800E4D44 == 0 && (u16)D_80114488 == 0) {
            D_8009C560 = 5;
            m->b1 = 9;
            m->s2 = 0;
            goto done;
        }
        if (*q == 5 || *q == 0x1A) {
            goto done;
        }
        if (*q == 2) {
            *(s16 *)(q + 3) = D_80074EAC[D_800965E0].x / 4096;
            *(s16 *)(q + 5) = D_80074EAC[D_800965E0].y / 4096;
            D_8009C560 = 2;
            *(u16 *)(q + 0x21) = D_80074EAC[D_800965E0].s6A;
            goto done;
        }
        func_800A65A4(D_80114454);
        func_800AA180((u8 *)D_80074EAC - 8 + D_800965E0 * 0x84, (FdTrig18 *)D_8007E7AC);
        func_800A8304();
        if ((u16)D_80114488 == 0 || D_8009A060 == 1) {
            func_800A364C(s1);
        }
        func_800AAB24(s1);
        func_800AB728();
        func_800AB5E8((u32 *)s1, (FdLineF2 *)((u8 *)s1 + 0x1749C), D_80071E40, (u32 *)((u8 *)s1 + 0x17490));
        func_800ABFE8((u8 *)s1, D_80071E40, (FdBox *)(D_800716C4 + 0x38));
        func_800138EC();
        D_80114478 = func_8003CEDC(1);
        while (func_80043DD8(1) != 0) {
        }
        D_8011447C = func_8003CEDC(1);
        a = 2;
        if ((u16)D_80114488 != 0 && D_800965E4 != 1) {
            a = 3;
        }
        func_8003CEDC(a);
        if (n != 0) {
            n--;
            if (n == 0) {
                func_80043D3C(1);
            }
        }
        func_80043938(1);
        if ((u16)D_80114488 == 0) {
            if (D_801142C8 == 0) {
                D_8007EB68[(s16)D_80075DEC].isrgb24 = 0;
            } else {
                D_801142C8 = 0;
            }
        }
        func_800444AC((M2C_UNK *)&D_8007EB68[(s16)D_80075DEC]);
        sp = (u8 *)D_8007EAAC;
        func_800443B0(sp + (s16)D_80075DEC * 0x5C);
        if ((u16)D_80114488 == 0) {
            func_80043F6C(sp + (s16)D_80075DEC * 0x5C, 0, 0, 0);
        } else if (D_8007EB68[(s16)D_80075DEC].isrgb24 == 0) {
            func_80043F6C(&r3, 0, 0, 0);
            func_80043F6C(&r4, 0, 0, 0);
            func_80043F6C(&r5, 0, 0, 0);
        } else {
            func_80043F6C(&r0, 0, 0, 0);
            func_80043F6C(&r1, 0, 0, 0);
            func_80043F6C(&r2, 0, 0, 0);
        }
        D_8007EBD8 = (u8 *)&D_8007EB68[(s16)D_80075DEC];
        D_8007EBD0 = (s16 *)(D_80113F2C + (s16)D_80075DEC * 0x5C);
        func_800AB310();
        if (*(u8 *)&D_8009AC2C == 0) {
            func_8004433C((u8 *)s1 + 0x4190);
            func_8004433C((u8 *)s1 + 0x3FFC);
            func_8004433C((u8 *)s1 + 0x418C);
            if (*(u16 *)&D_8009AC40 != 0) {
                func_8004433C(&D_8007E7A0[(s16)D_80075DEC * 4]);
            }
        }
        func_8004433C((u8 *)s1 + 0x1748C);
    }
}

void func_800A2D5C(s32 unused, u8 *p) {
    RECT16 r;
    u32 a;
    u32 b;
    u8 *q;
    u8 pad[0x28];

    a = *(u32 *)p;
    D_800E4D94 = a;
    D_800E4D98 = *(u16 *)(p + 4);
    D_800E4D9A = *(u16 *)(p + 6);
    D_800E4D9C = *(u16 *)(p + 8);
    D_800E4D9E = *(u16 *)(p + 0xA);
    q = p + 0xC;
    D_800E4D90 = q;
    q += (a >> 2) * 4 - 0xC;
    b = *(u32 *)q;
    D_800E4DA8 = b;
    q += 4;
    D_800E4DAC = *(u16 *)q;
    D_800E4DAE = *(u16 *)(q + 2);
    q += 4;
    D_800E4DB0 = *(u16 *)q * 2;
    D_800E4DB2 = *(u16 *)(q + 2);
    q += 4;
    D_800E4DA4 = q;
    q += (b >> 2) * 4 - 0xC;
    D_800E4DD8 = *(s32 *)q;
    q += 4;
    D_800E4DDC = *(u16 *)q;
    D_800E4DDE = *(u16 *)(q + 2);
    q += 4;
    D_800E4DE0 = *(u16 *)q * 2;
    D_800E4DE2 = *(u16 *)(q + 2);
    q += 4;
    D_800E4DD4 = q;
    r.x = 0;
    r.y = 0x1E0;
    r.w = 0x100;
    r.h = 0x10;
    func_80043DD8(0);
    func_80044000(&r, D_800E4D90);
    func_80043DD8(0);
    D_800E4DB4 = func_800436C0(D_800E4DA4, 1, 0, D_800E4DAC, D_800E4DAE, D_800E4DB0, D_800E4DB2);
    if (D_800E4DD8 != 0) {
        func_80043DD8(0);
        D_800E4DE4 = func_800436C0(D_800E4DD4, 1, 0, D_800E4DDC, D_800E4DDE, D_800E4DE0, D_800E4DE2);
    }
    func_80043DD8(0);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A2F78);

void func_800A3020(FdPrim10 *arg0, FdPrim14 *arg1, u8 *arg2, FdObj12 *arg3) {
    FdMdlHdr *h;
    s16 *p;
    FdSrc8 *src8;
    FdSrcE *srcE;
    u16 *sp18;
    u16 cnt1;
    u16 cnt2;
    s16 n;

    cnt1 = 0;
    cnt2 = 0;
    D_8011448C = 0;
    D_801144D0 = 0;
    h = *D_8009D848;
    p = (s16 *)(h + 1);
    src8 = (FdSrc8 *)((u8 *)h + h->off0);
    sp18 = (u16 *)((u8 *)h + h->off4);
    while (1) {
        if (p[0] == 0x7FFF) {
            p++;
            break;
        }
        if (p[0] == 0x7FFE) {
            func_80044A68(arg3, 0, 1, *sp18++, 0);
            D_8011448C++;
            arg3++;
        } else {
            n = p[2];
            if (n != 0) {
                do {
                    func_8004694C(arg0);
                    func_80046870(arg0, 1);
                    func_80046848(arg0, 0);
                    arg0->r = 0x80;
                    arg0->g = 0x80;
                    arg0->b = 0x80;
                    arg0->w8 = src8->w0;
                    arg0->wA = src8->w2;
                    arg0->bC = src8->b4;
                    arg0->bD = src8->b5;
                    arg0->wE = src8->w6;
                    src8++;
                    arg0++;
                    arg2 += 2;
                    n--;
                    cnt1++;
                } while (n != 0);
            }
        }
        p += 3;
    }
    D_8011448C = cnt1 - D_8011448C;
    srcE = (FdSrcE *)((u8 *)*D_8009D848 + (*D_8009D848)->off8);
    while (1) {
        if (p[0] == 0x7FFF) {
            p++;
            break;
        }
        n = p[2];
        if (n != 0) {
            do {
                func_80044A68(arg3, 0, 1, srcE->w8, 0);
                D_801144D0++;
                func_8004694C(arg0);
                func_80046870(arg0, 1);
                arg3++;
                if (!(srcE->bC & 0x80)) {
                    func_80046848(arg0, 0);
                } else {
                    func_80046848(arg0, 1);
                }
                arg0->r = srcE->wA;
                arg0->g = srcE->wA >> 8;
                arg0->b = 0x80;
                arg0->w8 = srcE->w0;
                arg0->wA = srcE->w2;
                arg0->bC = srcE->b4;
                arg0->bD = srcE->b5;
                arg0->wE = srcE->w6;
                arg2[0] = srcE->bC;
                arg2[1] = srcE->bD;
                srcE++;
                arg0++;
                n--;
                arg2 += 2;
                cnt1++;
            } while (n != 0);
        }
        p += 3;
    }
    D_801144C8 = cnt1;
    D_8007EBD4 = (FdSrcA *)((u8 *)*D_8009D848 + (*D_8009D848)->offC);
    while (1) {
        if (p[0] == 0x7FFF) {
            p++;
            break;
        }
        if (p[0] == 0x7FFE) {
            func_80044A68(arg3, 0, 1, *sp18, 0);
            arg3++;
            sp18++;
        } else {
            p[1] = cnt2;
            n = p[2];
            if (n != 0) {
                do {
                    func_80046960(arg1);
                    func_80046870(arg1, 1);
                    if (!(D_8007EBD4->b8 & 0x80)) {
                        func_80046848(arg1, 0);
                    } else {
                        func_80046848(arg1, 1);
                    }
                    arg1->p.r = 0x80;
                    arg1->p.g = 0x80;
                    arg1->p.b = 0x80;
                    arg1->p.w8 = D_8007EBD4->w0;
                    arg1->p.wA = D_8007EBD4->w2;
                    arg1->p.bC = D_8007EBD4->b4;
                    arg1->p.bD = D_8007EBD4->b5;
                    arg1->w10 = 0x20;
                    arg1->w12 = 0x20;
                    arg1->p.wE = D_8007EBD4->w6;
                    arg2[0] = D_8007EBD4->b8;
                    arg2[1] = D_8007EBD4->b9;
                    arg1++;
                    n--;
                    arg2 += 2;
                    cnt2++;
                    D_8007EBD4++;
                } while (n != 0);
            }
        }
        p += 3;
    }
    while (1) {
        if (p[0] == 0x7FFF) {
            p++;
            break;
        }
        if (p[0] == 0x7FFE) {
            func_80044A68(arg3, 0, 1, *sp18, 0);
            arg3++;
            sp18++;
        } else {
            p[1] = cnt2;
            n = p[2];
            if (n != 0) {
                do {
                    func_80046960(arg1);
                    func_80046870(arg1, 1);
                    if (!(D_8007EBD4->b8 & 0x80)) {
                        func_80046848(arg1, 0);
                    } else {
                        func_80046848(arg1, 1);
                    }
                    arg1->p.r = 0x80;
                    arg1->p.g = 0x80;
                    arg1->p.b = 0x80;
                    arg1->p.w8 = D_8007EBD4->w0;
                    arg1->p.wA = D_8007EBD4->w2;
                    arg1->p.bC = D_8007EBD4->b4;
                    arg1->p.bD = D_8007EBD4->b5;
                    arg1->w10 = 0x20;
                    arg1->w12 = 0x20;
                    arg1->p.wE = D_8007EBD4->w6;
                    arg2[0] = D_8007EBD4->b8;
                    arg2[1] = D_8007EBD4->b9;
                    arg1++;
                    n--;
                    arg2 += 2;
                    cnt2++;
                    D_8007EBD4++;
                } while (n != 0);
            }
        }
        p += 3;
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A364C);

s32 func_800A4094(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a1;

    temp_a1 = arg1 - arg0;
    if ((u32) (temp_a1 + 0x7FFFF) <= 0xFFFFEU) {
        arg0 += (temp_a1 * arg3) / arg2;
    } else {
        arg0 += (temp_a1 / arg2) * arg3;
    }
    return arg0;
}

s32 func_800A4134(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 t;
    s32 d;
    s32 a;

    t = (arg3 << 12) / arg2 / 32;
    a = (t - 0x80) & 0xFF;
    d = arg1 - arg0;
    return arg0 + (((s32 (*)(s32))func_800A8620)(a) + 0x1000) * d / 0x2000;
}

s32 func_800A41CC(s32 arg0, M2C_UNK arg1) {
    M2C_UNK sp10;
    M2C_UNK sp14;
    s32 temp_s0;

    func_8003AE38();
    func_8003B48C(D_80071E40);
    func_8003B51C(D_80071E40);
    func_8003B6BC(0, 0);
    temp_s0 = func_8003BBDC(arg0, arg1, &sp10, &sp14);
    func_8003AED8();
    return temp_s0;
}

void func_800A424C(FdOsc *s) {
    s16 t;
    s16 u;
    s16 w;
    u16 x;

    if (s->mode == 1) {
        if (s->phase == 0) {
            s->t = 0;
            s->from = 0;
            s->to = (s16)(D_800E0638[s->idx] * s->amp) / 256;
            s->phase = 1;
            s->idx++;
            return;
        }
        t = s->t;
        if (t > s->dur) {
            s->t = 0;
            s->from = s->to;
            if ((s16)s->from < 0) {
                s->to = (s16)(D_800E0638[s->idx] * s->amp) / 256;
            } else {
                s->to = -(s16)(D_800E0638[s->idx] * s->amp) / 256;
            }
            s->idx++;
            return;
        }
        s->t = t + 1;
        s->out = func_800A4134((s16)s->from, (s16)s->to, s->dur, s->t);
    } else if (s->phase == 1) {
        u = s->t;
        if (u > s->dur) {
            x = s->to;
            s->t = 0;
            s->to = 0;
            s->phase = 0;
            s->from = x;
            s->idx++;
            return;
        }
        s->t = u + 1;
        s->out = func_800A4134((s16)s->from, (s16)s->to, s->dur, s->t);
    } else {
        w = s->t;
        if (s->dur == w) {
            s->out = 0;
            return;
        }
        s->t = w + 1;
        s->out = func_800A4134((s16)s->from, (s16)s->to, s->dur, s->t);
    }
}

void func_800A4430(void) {
    if (D_8009AC13 == 0) {
        switch (D_8009AC11) {
        case 0:
            D_8009A100 = 0;
            D_80071E38 = 0;
            D_80071E3C = 0;
            D_8009AC13 = 2;
            break;
        case 1:
            D_8009A100 = 1;
            D_8009AC13 = 1;
            break;
        case 2:
        case 3:
            D_8009A100 = 1;
            D_80075CF8 = 0;
            D_8009AC13 = 1;
            D_8009C558 = D_8009AC14;
            D_80075E14 = D_80071E38;
            D_80075E1C = D_80071E3C;
            break;
        case 4:
            D_8009A100 = 1;
            D_8009AC13 = 2;
            D_80071E38 = D_8009ABFE;
            D_80071E3C = D_8009AC00;
            break;
        case 5:
        case 6:
            D_8009A100 = 1;
            D_80075CF8 = 0;
            D_8009AC13 = 1;
            D_8009C558 = D_8009AC14;
            D_80075E14 = D_80071E38;
            D_80075E1C = D_80071E3C;
            D_80075E18 = D_8009ABFE;
            D_80075E20 = D_8009AC00;
            break;
        case 7:
        case 8:
        case 9:
            break;
        }
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A45D4);

void func_800A47F8(void *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v1;
    s16 temp_v1_2;

    temp_v0 = M2C_FIELD(D_800716C4, s16 *, 0x10);
    if ((temp_v0 - 0xA0) < M2C_FIELD(arg0, s16 *, 0)) {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (temp_v0 - 0xA0);
    }
    temp_v1 = M2C_FIELD(D_800716C4, s16 *, 0xC);
    if (M2C_FIELD(arg0, s16 *, 0) < (temp_v1 + 0xA0)) {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (temp_v1 + 0xA0);
    }
    temp_v0_2 = M2C_FIELD(D_800716C4, s16 *, 0x12);
    if ((temp_v0_2 - 0x78) < M2C_FIELD(arg0, s16 *, 2)) {
        M2C_FIELD(arg0, s16 *, 2) = (s16) (temp_v0_2 - 0x78);
    }
    temp_v1_2 = M2C_FIELD(D_800716C4, s16 *, 0xE);
    if (M2C_FIELD(arg0, s16 *, 2) < (temp_v1_2 + 0x78)) {
        M2C_FIELD(arg0, s16 *, 2) = (s16) (temp_v1_2 + 0x78);
    }
}

void func_800A48B8(s32 arg0) {
    s16 v[3];
    u8 *p = &D_8009AC12;

    v[0] = D_80074EB0[*p * 33] >> 12;
    v[1] = D_80074EB4[*p * 33] >> 12;
    v[2] = (D_80074EB8[*p * 33] >> 12) + D_8009AC0A;
    func_800A41CC((s32)v, arg0);
}

void func_800A496C(void) {
    struct { s16 x; s16 y; } p;

    if (D_8009AC13 == 1) {
        switch (D_8009AC11) {
        case 0:
            break;
        case 1:
            func_800A48B8((s32)&p);
            func_800A47F8(&p);
            D_80071E38 = -p.x;
            D_80071E3C = -p.y;
            break;
        case 2:
            func_800A48B8((s32)&p);
            func_800A47F8(&p);
            D_80071E38 = func_800A4094((s16)D_80075E14, -p.x, (s16)D_8009C558, D_80075CF8);
            D_80071E3C = func_800A4094((s16)D_80075E1C, -p.y, (s16)D_8009C558, D_80075CF8);
            if ((s16)D_8009C558 == D_80075CF8) {
                D_8009AC13 = 2;
            } else {
                D_80075CF8 = D_80075CF8 + 1;
            }
            break;
        case 3:
            func_800A48B8((s32)&p);
            func_800A47F8(&p);
            D_80071E38 = func_800A4134((s16)D_80075E14, -p.x, (s16)D_8009C558, D_80075CF8);
            D_80071E3C = func_800A4134((s16)D_80075E1C, -p.y, (s16)D_8009C558, D_80075CF8);
            if ((s16)D_8009C558 == D_80075CF8) {
                D_8009AC13 = 2;
            } else {
                D_80075CF8 = D_80075CF8 + 1;
            }
            break;
        case 5:
            D_80071E38 = func_800A4094((s16)D_80075E14, (s16)D_80075E18, (s16)D_8009C558, D_80075CF8);
            D_80071E3C = func_800A4094((s16)D_80075E1C, (s16)D_80075E20, (s16)D_8009C558, D_80075CF8);
            if ((s16)D_8009C558 == D_80075CF8) {
                D_8009AC13 = 2;
            } else {
                D_80075CF8 = D_80075CF8 + 1;
            }
            break;
        case 6:
            D_80071E38 = func_800A4134((s16)D_80075E14, (s16)D_80075E18, (s16)D_8009C558, D_80075CF8);
            D_80071E3C = func_800A4134((s16)D_80075E1C, (s16)D_80075E20, (s16)D_8009C558, D_80075CF8);
            if ((s16)D_8009C558 == D_80075CF8) {
                D_8009AC13 = 2;
            } else {
                D_80075CF8 = D_80075CF8 + 1;
            }
            break;
        case 9:
            break;
        }
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A4BEC);

void func_800A5FB4(void) {
    FdVec sp10;
    FdVec sp20;
    FdVec sp30;
    s16 n;
    s32 t;
    s32 u;
    s32 t2;
    s32 u2;
    s32 v2;
    s16 i;

    if (D_8009AC26 == 0) {
        n = D_8009AC1E;
        D_800965E0 = n;
        D_80074EAC[n].s6A = D_8009AC16;
        do {
        } while (0);
        if ((s16)D_8009ABF8 == 0x7FFF) {
            D_80074EAC[n].x = ((M2C_FIELD(D_80074EAC[n].s6A * 0x18 + D_800E4274, s16 *, 0) + M2C_FIELD(D_80074EAC[n].s6A * 0x18 + D_800E4274, s16 *, 8) + M2C_FIELD(D_80074EAC[n].s6A * 0x18 + D_800E4274, s16 *, 16)) / 3) << 12;
            D_80074EAC[n].y = ((M2C_FIELD(D_80074EAC[n].s6A * 0x18 + D_800E4274, s16 *, 2) + M2C_FIELD(D_80074EAC[n].s6A * 0x18 + D_800E4274, s16 *, 10) + M2C_FIELD(D_80074EAC[n].s6A * 0x18 + D_800E4274, s16 *, 18)) / 3) << 12;
            D_80074EAC[n].z = ((M2C_FIELD(D_80074EAC[n].s6A * 0x18 + D_800E4274, s16 *, 4) + M2C_FIELD(D_80074EAC[n].s6A * 0x18 + D_800E4274, s16 *, 12) + M2C_FIELD(D_80074EAC[n].s6A * 0x18 + D_800E4274, s16 *, 20)) / 3) << 12;
        } else {
            D_80074EAC[n].x = (s16)D_8009ABF8 << 12;
            D_80074EAC[n].y = (s16)D_8009ABFA << 12;
            t = D_80074EAC[n].s6A * 0x18;
            u = t + 8;
            func_800A8DF4(&sp10, u + D_800E4274, t + D_800E4274);
            t2 = D_80074EAC[D_800965E0].s6A * 0x18;
            u2 = t2 + 0x10;
            v2 = t2 + 8;
            func_800A8DF4(&sp20, u2 + D_800E4274, v2 + D_800E4274);
            sp30.x = (s16)D_8009ABF8;
            sp30.y = (s16)D_8009ABFA;
            D_80074EAC[D_800965E0].z = func_800A8E34(&sp10, &sp20, &sp30, (s16 *)(D_80074EAC[D_800965E0].s6A * 0x18 + D_800E4274)) << 12;
        }
        D_80074F10[D_800965E0].a = (D_8009AC04[0] * 0x11) >> 8;
        D_80074F14[D_800965E0 * 66] = D_8009AC04[0] * 2;
        D_80074F04[D_800965E0 * 66] = 0x10;
    }
    for (i = 0; i < D_8009AC1C[0]; i++) {
        D_80074EAC[i].b2D = 0;
    }
}

void func_800A635C(s32 arg0, s16 arg1) {
    if (D_8009AC26 == 0) {
        if (D_8009AC6C & 8) {
            D_80074ED9[arg1 * 0x84] = 0xE0;
            return;
        }
        if (D_8009AC6C & 4) {
            D_80074ED9[arg1 * 0x84] = 0x20;
            return;
        }
        D_80074ED9[arg1 * 0x84] = 0;
    }
}

void func_800A6418(s32 arg0) {
    u8 m;
    u8 *p;
    u8 *base;
    u16 v;

    m = ((u8 *)D_8008357C)[arg0 * 8 + 4];
    if (m != 0xFF) {
        p = D_8004A62C[1] + m * 0x24;
        base = (u8 *)(*(u16 *)(p + 0x1A) + *(s32 *)(p + 0x1C));
        if (D_8009AC27 == 0) {
            D_80074F02[arg0].x4 += D_80074F02[arg0].x2;
            if (arg0 == D_800965E0 && D_8009AC26 == 0) {
                v = D_80074F02[arg0].x6 = *(u16 *)(base + D_80074F02[arg0].x0 * 16) - 1;
                if ((s16)v << 4 < D_80074F02[arg0].x4) {
                    D_80074F02[arg0].x4 = 0;
                }
            } else {
                v = D_80074F02[arg0].x6;
                if ((s16)v * 16 < D_80074F02[arg0].x4) {
                    D_80074F02[arg0].x4 = v << 4;
                }
            }
        }
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A65A4);

void func_800A82A0(void *arg0) {
    D_8009ABF5 = 1;
    D_8009ABF6 = M2C_FIELD(arg0, u16 *, 0x12);
    D_8009ABF8 = M2C_FIELD(arg0, u16 *, 0xC);
    D_8009ABFA = M2C_FIELD(arg0, u16 *, 0xE);
    D_8009AC16 = M2C_FIELD(arg0, u16 *, 0x10);
    D_8009AC18 = (s16) M2C_FIELD(arg0, u8 *, 0x14);
}

s32 func_800A8304(void) {
    struct { FdVec pos; FdVec other; s16 dist[16]; s32 d2; u8 pad[0x14]; } L;
    s32 i;
    u16 idx;
    s16 min;
    s32 n;
    s32 t;

    if (D_8009AC6C & 0x20) {
        if (!(D_8009AC70 & 0x20)) {
            i = 0;
            L.pos.x = D_80074EB0[D_800965E0 * 33] >> 12;
            L.pos.y = D_80074EB4[D_800965E0 * 33] >> 12;
            L.pos.z = D_80074EB8[D_800965E0 * 33] >> 12;
            if (D_8009AC1C[0] > 0) {
                do {
                    L.dist[i] = 0x100;
                    if (i != D_800965E0 && D_80074EFE[i].b == 0) {
                        L.other.x = D_80074EB0[i * 33] >> 12;
                        L.other.y = D_80074EB4[i * 33] >> 12;
                        L.other.z = D_80074EB8[i * 33] >> 12;
                        if ((L.pos.x != L.other.x || L.pos.y != L.other.y) && (u32)(L.pos.z - L.other.z + 0xFF) < 0x1FF) {
                            t = (D_80074EDC[D_800965E0].b - (func_800A8640(&L.pos, &L.other, &L.d2) & 0xFF)) & 0xFF;
                            L.dist[i] = t;
                            if (t > 0x80) {
                                L.dist[i] = 0x100 - t;
                            }
                            if (L.d2 >= D_80074F10[i].b + D_80074F10[D_800965E0].a) {
                                L.dist[i] = 0x100;
                            }
                        }
                    }
                    i++;
                } while (i < D_8009AC1C[0]);
            }
            min = 0x40;
            idx = D_800965E0;
            i = 0;
            if (D_8009AC1C[0] > 0) {
                n = D_8009AC1C[0];
                do {
                    if (L.dist[i] < min) {
                        min = L.dist[i];
                        idx = i;
                    }
                    i++;
                } while (i < n);
            }
            if ((s16)idx != D_800965E0 && min != 0x40) {
                D_80074EFE[(s16)idx].a = 1;
            }
        }
    }
}

s16 func_800A8600(u8 arg0) {
    return D_800DF120[arg0].a;
}

s16 func_800A8620(u8 arg0) {
    return D_800DF120[arg0].b;
}

s32 func_800A8640(FdVec *arg0, FdVec *arg1, s32 *arg2) {
    s32 dx;
    s32 dy;
    s32 d;
    s32 a;
    s32 t;

    dx = arg1->x - arg0->x;
    dy = arg1->y - arg0->y;
    t = dx * dx + dy * dy;
    *arg2 = t;
    d = (*arg2 = func_80039F5C(t));
    dx = (dx << 12) / d / 32;
    dy = (dy << 12) / d / 32;
    if (dx * dx > dy * dy) {
        if (dx > 0) {
            if (dy > 0) {
                a = D_800DEF88[dy * 2];
            } else {
                a = -D_800DEF88[-dy * 2];
            }
        } else if (dy > 0) {
            a = -0x80 - D_800DEF88[dy * 2];
        } else {
            a = D_800DEF88[-dy * 2] - 0x80;
        }
    } else if (dy > 0) {
        if (dx > 0) {
            a = 0x40 - D_800DEF88[dx * 2];
        } else {
            a = D_800DEF88[-dx * 2] + 0x40;
        }
    } else if (dx > 0) {
        a = D_800DEF88[dx * 2] - 0x40;
    } else {
        a = -0x40 - D_800DEF88[-dx * 2];
    }
    return (a + 0x40) & 0xFF;
}

s32 func_800A8858(FdMover *e, s16 step) {
    FdVec a;
    FdVec b;
    s32 d;
    s32 r;

    a.x = e->x >> 12;
    a.y = e->y >> 12;
    b.x = e->tx >> 12;
    b.y = e->ty >> 12;
    d = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
    r = e->x6C + step;
    r = r * r + 0x1000;
    if (step != 0 && r >= d) {
        return 0;
    }
    if (d < (e->x70 * e->x70) >> 16 || d < 4) {
        e->x = e->tx;
        e->y = e->ty;
        return 0;
    }
    e->x36 = func_800A8640(&a, &b, &d) - e->x35;
    return 1;
}

s32 func_800A8968(u16 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    s32 side;
    s32 *sp;
    s32 t1;
    s32 u1;
    s32 t2;
    s32 u2;
    s32 v2;
    s32 t3;
    s32 u3;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 x;
    s32 y;
    u16 w;
    u16 idx;
    s16 *e;

    side = 0;
    sp = (s32 *)0x1F800000;
    D_1F800030[0] = arg1[0] / 4096;
    D_1F800034 = arg1[1] / 4096;
    D_1F800038 = 0;
    D_80113F28 = 0xFFFF;
    while (1) {
        t1 = *arg0 * 0x18;
        u1 = t1 + 8;
        func_800A8DF4(sp, u1 + D_800E4274, t1 + D_800E4274);
        t2 = *arg0 * 0x18;
        u2 = t2 + 0x10;
        v2 = t2 + 8;
        func_800A8DF4(sp + 4, u2 + D_800E4274, v2 + D_800E4274);
        t3 = *arg0 * 0x18;
        u3 = t3 + 0x10;
        func_800A8DF4(sp + 8, t3 + D_800E4274, u3 + D_800E4274);
        idx = *arg0;
        x = sp[12];
        e = (s16 *)(idx * 0x18 + D_800E4274);
        y = sp[13];
        c0 = (x - e[0]) * sp[1] - (y - e[1]) * sp[0];
        c1 = (x - e[4]) * sp[5] - (y - e[5]) * sp[4];
        c2 = (x - e[8]) * sp[9] - (y - e[9]) * sp[8];
        if (c0 >= 0 && c1 >= 0 && c2 >= 0) {
            break;
        }
        if (c0 < 0) {
            w = *(u16 *)(idx * 6 + D_80114458);
            if ((s16)w >= 0 && !((D_8009ACA6[(s16)w >> 3] >> ((s16)w - (((s16)w >> 3) << 3))) & 1)) {
                *arg0 = w;
                continue;
            }
            arg3[0] = sp[0];
            arg3[1] = sp[1];
            arg3[2] = sp[2];
            side = -8;
            if (sp[0] * arg2[0] + sp[1] * arg2[1] >= 0) {
                side = 8;
            }
            D_80113F28 = *arg0;
            D_801144CC = 0;
            break;
        } else if (c1 < 0) {
            w = *(u16 *)(idx * 6 + D_80114458 + 2);
            if ((s16)w >= 0 && !((D_8009ACA6[(s16)w >> 3] >> ((s16)w - (((s16)w >> 3) << 3))) & 1)) {
                *arg0 = w;
                continue;
            }
            arg3[0] = sp[4];
            arg3[1] = sp[5];
            arg3[2] = sp[6];
            side = -8;
            if (sp[4] * arg2[0] + sp[5] * arg2[1] >= 0) {
                side = 8;
            }
            D_80113F28 = *arg0;
            D_801144CC = 1;
            break;
        } else if (c2 < 0) {
            w = *(u16 *)(idx * 6 + D_80114458 + 4);
            if ((s16)w >= 0 && !((D_8009ACA6[(s16)w >> 3] >> ((s16)w - (((s16)w >> 3) << 3))) & 1)) {
                *arg0 = w;
                continue;
            }
            arg3[0] = sp[8];
            arg3[1] = sp[9];
            arg3[2] = sp[10];
            side = -8;
            if (sp[8] * arg2[0] + sp[9] * arg2[1] >= 0) {
                side = 8;
            }
            D_80113F28 = *arg0;
            D_801144CC = 2;
            break;
        }
    }
    arg1[2] = func_800A8E34((FdVec *)sp, (FdVec *)(sp + 4), (FdVec *)(sp + 12), (s16 *)(*arg0 * 0x18 + D_800E4274));
    return side;
}

void func_800A8DF4(void *arg0, void *arg1, void *arg2) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg1, s16 *, 0) - M2C_FIELD(arg2, s16 *, 0));
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg1, s16 *, 2) - M2C_FIELD(arg2, s16 *, 2));
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg1, s16 *, 4) - M2C_FIELD(arg2, s16 *, 4));
}

s32 func_800A8E34(FdVec *a, FdVec *b, FdVec *c, s16 *d) {
    s32 n[3];

    n[0] = -a->y * b->z + b->y * a->z;
    n[1] = -a->z * b->x + a->x * b->z;
    n[2] = -a->x * b->y + b->x * a->y;
    a->x = d[0];
    a->y = d[1];
    a->z = d[2];
    return (n[0] * a->x + n[1] * a->y + n[2] * a->z - n[0] * c->x - n[1] * c->y) / n[2];
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A8F88);

s32 func_800A9B64(s16 arg0, FdVec *arg1) {
    s16 i;
    s32 hit;
    s32 r0;
    s32 r;
    s32 dx;
    s32 dy;

    hit = 0;
    r0 = D_80074EFC[arg0].x14;
    for (i = 0; i < D_8009AC1C[0]; i++) {
        if (i != arg0 && D_80074EFC[i].x1 == 0) {
            if ((u32)((D_80074EB8[i * 33] >> 12) - arg1->z + 0x7E) < 0xFE) {
                r = (r0 + D_80074EFC[i].x14) >> 1;
                r *= r;
                dx = (D_80074EB0[i * 33] - arg1->x) >> 12;
                dy = (D_80074EB4[i * 33] - arg1->y) >> 12;
                if (dx * dx + dy * dy < r) {
                    hit = 1;
                    if (arg0 == D_800965E0) {
                        D_80074EFC[i].x0 = 1;
                    }
                }
            }
        }
    }
    return hit;
}

s32 func_800A9CE8(FdGate18 *g, s32 *pos, s32 *out) {
    s32 t;

    t = -(((g->x0 - pos[0]) * (g->x1 - g->x0) + (g->y0 - pos[1]) * (g->y1 - g->y0) + (g->z0 - pos[2]) * (g->z1 - g->z0)) << 8)
        / ((g->x1 - g->x0) * (g->x1 - g->x0) + (g->y1 - g->y0) * (g->y1 - g->y0) + (g->z1 - g->z0) * (g->z1 - g->z0));
    out[0] = ((t * (g->x1 - g->x0)) >> 8) + g->x0;
    out[1] = ((t * (g->y1 - g->y0)) >> 8) + g->y0;
    out[2] = ((t * (g->z1 - g->z0)) >> 8) + g->z0;
    if ((g->x0 - out[0] >= 0 && g->x1 - out[0] <= 0) || (g->x0 - out[0] <= 0 && g->x1 - out[0] >= 0)) {
        if ((g->y0 - out[1] >= 0 && g->y1 - out[1] <= 0) || (g->y0 - out[1] <= 0 && g->y1 - out[1] >= 0)) {
            t = (out[0] - pos[0]) * (out[0] - pos[0]) + (out[1] - pos[1]) * (out[1] - pos[1]) + (out[2] - pos[2]) * (out[2] - pos[2]);
        } else {
            t = -1;
        }
    } else {
        t = -1;
    }
    return t;
}

s32 func_800A9EEC(u8 *e, FdGateT *t, s32 *v) {
    s32 i;
    s32 d;
    s32 on;
    s32 ret;
    s32 *pos;
    s32 *b;
    s32 *out;
    s32 sp10;
    s32 c1;
    s32 c2;

    b = (s32 *)0x1F800010;
    out = (s32 *)0x1F800020;
    pos = (s32 *)0x1F800000;
    pos[0] = M2C_FIELD(e, s32 *, 0xC) >> 12;
    pos[1] = M2C_FIELD(e, s32 *, 0x10) >> 12;
    ret = 0;
    pos[2] = M2C_FIELD(e, s32 *, 0x14) >> 12;
    i = 0;
    b[0] = v[0] >> 12;
    on = 1;
    b[1] = v[1] >> 12;
    b[2] = M2C_FIELD(e, s32 *, 0x14) >> 12;
    for (; i < 32; i++, t++) {
        if (t->xC == on) {
            t->x15 = 0;
            d = func_800A9CE8(t, pos, out);
            sp10 = d;
            if (d != -1 && d < M2C_FIELD(e, u16 *, 0x6C) * M2C_FIELD(e, u16 *, 0x6C)) {
                if (t->x16 == on) {
                    ret = 1;
                }
                if (t->xE == 0) {
                    t->x12 = on;
                }
                t->xE = on;
                c1 = (t->x1 - t->x0) * (pos[1] - t->y0) - (pos[0] - t->x0) * (t->y1 - t->y0);
                c2 = (t->x1 - t->x0) * (b[1] - t->y0) - (b[0] - t->x0) * (t->y1 - t->y0);
                if ((c1 >= 0 && c2 < 0) || (c2 >= 0 && c1 < 0) || (c1 > 0 && c2 <= 0) || (c2 > 0 && c1 <= 0)) {
                    t->xF = on;
                }
                if ((pos[0] == out[0] && pos[1] == out[1]) || (t->x14 = func_800A8640((FdVec *)pos, (FdVec *)out, &sp10), ((t->x14 - e[0x36] + 0x40) & 0xFF) < 0x80)) {
                    t->x10 = on;
                    t->x15 = on;
                }
            } else {
                if (t->xE == on) {
                    t->x13 = on;
                }
                t->xE = 0;
            }
        }
    }
    return ret;
}

void func_800AA180(u8 *e, FdTrig18 *t) {
    s32 i;
    s32 d;
    s32 on;
    s32 *pos;
    s32 *out;
    s32 *pad;

    out = (s32 *)0x1F800010;
    i = 0;
    on = 1;
    pos = (s32 *)0x1F800000;
    pos[0] = M2C_FIELD(e, s32 *, 0xC) >> 12;
    pos[1] = M2C_FIELD(e, s32 *, 0x10) >> 12;
    pos[2] = M2C_FIELD(e, s32 *, 0x14) >> 12;
    pad = &D_8009AC6C;
    for (; i < 32; i++, t++) {
        if (t->xC == on && e[0x5D] == 0) {
            d = func_800A9CE8(t, pos, out);
            if (d != -1 && d < M2C_FIELD(e, u16 *, 0x6C) * M2C_FIELD(e, u16 *, 0x6C)) {
                if (t->xE == 0) {
                    t->x12 = on;
                }
                t->xE = on;
            } else {
                if (t->xE == on) {
                    t->x13 = on;
                }
                t->xE = 0;
            }
            if (t->x15 == on && ((t->x14 - e[0x36] + 0x20) & 0xFF) < 0x40 && (pad[0] & 0x20) && !(pad[1] & 0x20)) {
                t->x11 = on;
            }
        }
    }
}

void func_800AA32C(void *arg0) {
    s32 var_v0;
    void *var_a0;

    var_a0 = arg0;
    var_v0 = 0x1F;
    do {
        M2C_FIELD(var_a0, s8 *, 0x15) = 0;
        var_v0 -= 1;
        var_a0 += 0x18;
    } while (var_v0 >= 0);
}

void func_800AA348(u8 *e, FdGate18 *g, s32 *v) {
    s32 i;
    s32 d;
    s32 *pos;
    s32 *pos2;
    s32 *out;
    s32 c1;
    s32 c2;

    pos2 = (s32 *)0x1F800010;
    pos = (s32 *)0x1F800000;
    pos[0] = M2C_FIELD(e, s32 *, 0xC) >> 12;
    pos[1] = M2C_FIELD(e, s32 *, 0x10) >> 12;
    out = (s32 *)0x1F800020;
    pos[2] = M2C_FIELD(e, s32 *, 0x14) >> 12;
    pos2[0] = v[0] >> 12;
    pos2[1] = v[1] >> 12;
    pos2[2] = M2C_FIELD(e, s32 *, 0x14) >> 12;
    for (i = 0; i < 12; i++, g++) {
        if (g->map != 0x7FFF) {
            d = func_800A9CE8(g, pos, out);
            if (d != -1 && d < M2C_FIELD(e, u16 *, 0x6C) * M2C_FIELD(e, u16 *, 0x6C)) {
                c1 = (g->x1 - g->x0) * (pos[1] - g->y0) - (pos[0] - g->x0) * (g->y1 - g->y0);
                c2 = (g->x1 - g->x0) * (pos2[1] - g->y0) - (pos2[0] - g->x0) * (g->y1 - g->y0);
                if ((c1 >= 0 && c2 < 0) || (c2 >= 0 && c1 < 0) || (c1 > 0 && c2 <= 0) || (c2 > 0 && c1 <= 0)) {
                    func_800A82A0(g);
                }
            }
        }
    }
}

s32 func_800AA514(u8 *p, u8 op) {
    s32 ret;
    u8 bit;
    u8 v;

    ret = 0;
    switch (op) {
    case 0:
    case 2:
    case 4:
        bit = 1 << p[0xD];
        v = D_8009ACE6[p[0xC]];
        if (!(v & bit)) {
            ret = 1;
        }
        D_8009ACE6[p[0xC]] = bit | v;
        break;
    case 1:
    case 3:
    case 5:
        if ((u8)(D_8009ACE6[p[0xC]] | ~(1 << p[0xD])) == 0xFF) {
            ret = 1;
        }
        D_8009ACE6[p[0xC]] = ~(1 << p[0xD]) & D_8009ACE6[p[0xC]];
        break;
    }
    return ret;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text2", D_800A00BC);

void func_800AA5E4(u8 *e, u8 *g) {
    FdTbl4 tbl;
    s32 i;
    s32 d;
    s16 r;
    u8 op;
    s32 *pos;
    s32 *out;

    out = (s32 *)0x1F800020;
    tbl = D_800A00BC;
    i = 0;
    pos = (s32 *)0x1F800000;
    pos[0] = *(s32 *)(e + 0xC) >> 12;
    pos[1] = *(s32 *)(e + 0x10) >> 12;
    pos[2] = *(s32 *)(e + 0x14) >> 12;
    for (; i < 12; i++, g += 0x10) {
        if (g[0xC] != 0xFF) {
            d = func_800A9CE8((FdGate18 *)g, pos, out);
            if (d != -1 && d < *(u16 *)(e + 0x6C) * *(u16 *)(e + 0x6C)) {
                if (pos[0] == out[0] && pos[1] == out[1]) {
                    r = func_800AA514(g, g[0xE]);
                    if (r == 1) {
                        func_8001117C(tbl.v[g[0xF]]);
                    }
                } else {
                    if ((((u8)func_800A8640((FdVec *)pos, (FdVec *)out, &d) - e[0x36] + 0x40) & 0xFF) < 0x80) {
                        r = func_800AA514(g, g[0xE]);
                        if (r == 1) {
                            func_8001117C(tbl.v[g[0xF]]);
                        }
                    }
                }
            } else {
                op = g[0xE];
                if (op >= 4) {
                    if ((*(s16 *)(g + 6) - *(s16 *)g) * (pos[1] - *(s16 *)(g + 2)) - (*(s16 *)(g + 8) - *(s16 *)(g + 2)) * (pos[0] - *(s16 *)g) > 0) {
                        continue;
                    }
                }
                if (op == 2 || op == 4) {
                    r = func_800AA514(g, 1);
                    if (r == 1) {
                        func_8001117C(tbl.v[g[0xF]]);
                    }
                }
                if (g[0xE] == 3 || g[0xE] == 5) {
                    r = func_800AA514(g, 0);
                    if (r == 1) {
                        func_8001117C(tbl.v[g[0xF]]);
                    }
                }
            }
        }
    }
}

void func_800AA870(u8 *p) {
    s32 i;

    i = 0;
    do {
        if (p[0xC] != 0xFF) {
            switch (p[0xE]) {
            case 0:
            case 2:
            case 4:
                func_800AA514(p, 1);
                break;
            case 1:
            case 3:
            case 5:
                func_800AA514(p, 0);
                break;
            }
        }
        i++;
        p += 0x10;
    } while (i < 12);
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text2", D_800A00DC);

void func_800AA930(void) {
    u32 i;
    u8 **nv;
    u32 t;
    u8 *q;

    D_800DFCA0 = 0x80128000;
    t = func_800ADAA4(D_8007E770, D_8004A62C);
    D_80075E10 = t;
    D_800E0204 = t;
    func_80033E74(D_800DA5C0[(s16)D_8009A05C * 6 + 2], D_800DA5C0[(s16)D_8009A05C * 6 + 3], 0x801B0000, 0);
    while (func_80034B44() != 0) {
    }
    *(s32 *)0x1F800000 = (s32)&D_800DF08C;
    *(s32 *)0x1F800004 = (s32)&D_800DF0D4;
    D_80075E10 = func_800ADC90((u8 *)D_8007E770, (s32)D_8004A62C, D_80075E10, 1);
    D_80075E10 = func_800AC35C(D_8007E770, D_8004A62C, &D_800A00DC, 0x801B0000);
    for (i = 1; i < *(u8 *)D_8004A62C; i++) {
        *(u8 *)(D_8004A62C[1] + i * 0x24) = 0;
    }
    for (i = 0; i < *(u8 *)D_8004A62C; i++) {
        *(u8 *)0x1F800001 = 1;
        *(u8 *)0x1F800002 = 0;
        nv = &D_8004A62C[1];
        *(u8 *)0x1F800003 = i;
        q = (u8 *)(*nv + i * 0x24);
        *(u8 *)0x1F800000 = 1;
        func_800B1C7C(q, (u8 *)0x1F800000);
    }
    func_800AFDE4();
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AAB24);

void func_800AB2AC(void) {
}

void func_800AB2B4(void) {
    s32 var_v0;

    if (((u16) D_80114488 == 0) || (D_8009AC2D == 1)) {
        var_v0 = *D_80083578;
    } else {
        var_v0 = D_80083270;
    }
    D_80071E40 = var_v0;
}

void func_800AB310(void) {
    u8 *p;

    if (D_800965E8 == 1) {
        if (func_80034B44() == 0) {
            D_800965E8 = 2;
        }
        return;
    }
    p = &D_8009ABF5;
    if (*p == 0x14) {
        func_80035658();
        D_80114488 = 0;
        D_800E4D44 = 0;
        D_8009AC1A = 2;
        return;
    }
    switch (func_80034B44()) {
    case 0:
        if (*p == 3 && D_8009AC1A == 0) {
            if (D_80075E10 <= 0x801AFFFF) {
                func_80034FC8(D_80075E10, (s16)D_8009ABF6);
            } else {
                func_80034FC8(0x801B0000, (s16)D_8009ABF6);
            }
            D_8009AC1A = 1;
            D_800E4D44 = 1;
        }
        if (D_80114488 == 1) {
            D_801142C8 = 1;
            D_80114488 = 0;
            D_800E4D44 = 0;
            D_8009AC1A = 2;
        }
        break;
    case 10:
        if (*p == 3) {
            D_8009AC1A = 2;
        }
        if (*p == 4) {
            D_8009AC1A = 1;
            func_800354CC();
            D_80114488 = 1;
        }
        break;
    }
}

void func_800AB4AC(FdSprBuf *arg0) {
    s32 i;

    for (i = 0; i < 64; i++) {
        D_800E42E8[i].x6 = 0;
        D_800E42E8[i].x2 = i * 4;
        D_800E42E8[i].x0 = i % 8;
        func_800469C4(&arg0->prims[i]);
        func_80046848(&arg0->prims[i], 1);
        arg0->prims[i].r0 = 0x10;
        arg0->prims[i].g0 = 0x10;
        arg0->prims[i].b0 = 0x10;
    }
    func_80044A68(arg0->dm, 0, 0, func_8004656C(0, 1, 0, 0) & 0xFFFF, 0);
}

void func_800AB5E8(u32 *ot, FdLineF2 *prims, s32 arg2, u32 *tag) {
    s32 p;
    s32 flag;
    s32 i;

    func_8003AE38();
    func_8003B48C(arg2);
    func_8003B51C(arg2);
    for (i = 0; i < 64; i++) {
        if (D_800E42D8[i].x6 == 1) {
            func_8003BBDC(&D_800E42D8[i].a, &prims->xy0, &p, &flag);
            func_8003BBDC(&D_800E42D8[i].b, &prims->xy1, &p, &flag);
            func_80046794((s32)ot, (s32)prims);
        }
        prims++;
    }
    func_8003AED8();
    *tag = (*tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)tag & 0xFFFFFF);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AB728);

u8 func_800AB9C8(void) {
    D_8009C540 += 1;
    if (D_8009C540 == 0) {
        D_8009AD2C += 0xD;
    }
    return D_800E0638[D_8009C540] - D_8009AD2C;
}

u8 func_800ABA34(void) {
    D_80071C20 += 1;
    return D_800E0638[D_80071C20];
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800ABA70);

void func_800ABF0C(SPRT16 *p, void *arg1) {
    s16 i;

    i = 0;
    do {
        func_8004694C(p);
        func_80046870(p, 1);
        func_80046848(p, 0);
        p->r0 = 0x80;
        p->g0 = 0x80;
        p->b0 = 0x80;
        p->clut = func_80046634(0x100, 0x1E9);
        i++;
        p++;
    } while (i < 24);
    func_80044A68(arg1, 0, 1, func_8004656C(0, 0, 0x3C0, 0x100) & 0xFFFF, 0);
}

void func_800ABFE8(u8 *arg0, s32 arg1, FdBox *arg2) {
    FdUVec v;
    s32 sp18;
    s32 sp1C;
    s16 i;
    s32 j;
    s16 *p;
    s16 x;
    s16 y;
    FdIcon *q;
    FdIcon *r;

    if ((D_8009D5A6 == 1 && D_8009AC26 == 0) || D_8009D5A6 == 2) {
        i = 0;
        func_8003AE38();
        func_8003B48C(arg1);
        func_8003B51C(arg1);
        do {
            j = i;
            if (M2C_FIELD(&D_800716C4[j], u8 *, 0x218) == 1) {
                p = (s16 *)(j * 0x18 + (s32)arg2);
                x = (p[0] + p[3]) / 2;
                v.x = x;
                y = (p[1] + p[4]) / 2;
                v.y = y;
                v.z = (p[2] + p[5]) / 2;
                if (x != 0 || y != 0) {
                    func_8003BBDC(&v, &v, &sp18, &sp1C);
                    ((FdIcon *)(arg0 + j * 0x10 + 0x4000))->c0 = ((D_8011446C * 4) & 0x30) + 0x30;
                    ((FdIcon *)(arg0 + j * 0x10 + 0x4000))->c1 = 0xD0;
                    ((FdIcon *)(arg0 + j * 0x10 + 0x4000))->x = v.x - 7;
                    ((FdIcon *)(arg0 + j * 0x10 + 0x4000))->y = v.y - 8;
                    ((FdIcon *)(arg0 + j * 0x10 + 0x4000))->tag.addr = ((FdTag *)arg0)->addr;
                    ((FdTag *)arg0)->addr = (u32)(arg0 + (j * 0x10 + 0x4000));
                }
            }
            i++;
        } while (i < 12);
        for (i = 0; i < 12; i++) {
            j = i;
            if (M2C_FIELD((s32)D_800716C4 + (j << 4), s32 *, 0x230) != 0) {
                v.x = M2C_FIELD((s32)D_800716C4 + (j << 4), u16 *, 0x224);
                v.y = M2C_FIELD((s32)D_800716C4 + (j << 4), u16 *, 0x228);
                v.z = M2C_FIELD((s32)D_800716C4 + (j << 4), u16 *, 0x22C);
                func_8003BBDC(&v, &v, &sp18, &sp1C);
                ((FdIcon *)(arg0 + j * 0x10 + 0x40C0))->c0 = ((D_8011446C * 4) & 0x30) + 0x30;
                ((FdIcon *)(arg0 + j * 0x10 + 0x40C0))->c1 = 0xD0;
                r = (FdIcon *)(arg0 + (j + 0xC) * 0x10 + 0x4000);
                r->x = v.x - 7;
                r->y = v.y - 8;
                if (M2C_FIELD((s32)D_800716C4 + (j << 4), s32 *, 0x230) == 2) {
                    r->e = func_80046634(0x100, 0x1E8);
                }
                ((FdIcon *)(arg0 + j * 0x10 + 0x40C0))->tag.addr = ((FdTag *)arg0)->addr;
                ((FdTag *)arg0)->addr = (u32)(arg0 + (j * 0x10 + 0x40C0));
            }
        }
        func_8003AED8();
        ((FdTag *)(arg0 + 0x4180))->addr = ((FdTag *)arg0)->addr;
        ((FdTag *)arg0)->addr = (u32)(arg0 + 0x4180);
        D_8011446C += 1;
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AC35C);

s32 func_800ACBA0(Unk800ACBA0 *arg0, s32 arg1, s32 arg2) {
    s32 base;
    u32 i;

    arg0->unk20 = arg1;
    arg1 += arg0->unk2 << 5;
    base = arg0->unk18 + arg0->unk1C;
    for (i = 0; i < arg0->count; i++) {
        arg1 = func_800ACC5C(base + i * 0x20, arg1, 0, arg2);
    }
    func_800AF6EC(arg0, arg0->unk16, 0);
    return arg1;
}

s32 func_800ACC5C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u16 *tab;
    u32 pass;
    s32 t30;
    s32 t38;
    s32 t40;
    s32 t48;
    u32 *mat;
    u8 *out;
    u8 *fp;
    u8 *src;
    u32 i;
    u32 n;
    u32 e0;
    u32 e1;
    u32 e2;
    u32 e3;
    u32 idx0;
    u32 idx1;
    u32 idx2;
    u32 idx3;
    u32 fl0;
    u32 fl1;
    u32 fl2;
    u32 fl3;
    s32 ctoff0;
    s32 ctoff1;
    s32 ctoff2;
    s32 ctoff3;
    u32 m0;
    u32 m1;
    u32 m2;
    u32 m3;
    s32 du0;
    s32 du1;
    s32 du2;
    s32 du3;
    s32 dv0;
    s32 dv1;
    s32 dv2;
    s32 dv3;
    FdPrGT4 *gt4;
    FdPrGT3 *gt3;
    FdPrFT4 *ft4;
    FdPrFT3 *ft3;
    FdPrF *pf;
    FdPrG3 *g3;
    FdPrG4 *g4;

    mat = (u32 *)(((FdPrimHdr *)arg0)->off12 + ((FdPrimHdr *)arg0)->base);
    tab = (u16 *)(((FdPrimHdr *)arg0)->off10 + ((FdPrimHdr *)arg0)->base);
    if (arg2 != 0) {
        ((FdPrimHdr *)arg0)->base = arg0 + 0x20;
    }
    ((FdPrimHdr *)arg0)->out = arg1;
    t30 = (arg3 % 4) << 6;
    t38 = (arg3 / 4) << 5;
    t40 = (arg3 - arg3 / 8 * 8) << 5;
    t48 = (arg3 / 8) << 5;
    pass = 0;
    do {
        out = (u8 *)arg1;
        fp = (u8 *)(((FdPrimHdr *)arg0)->off14 + ((FdPrimHdr *)arg0)->base);
        if (pass != 0) {
            out += ((FdPrimHdr *)arg0)->off16;
        }
        src = (u8 *)(((FdPrimHdr *)arg0)->offE + ((FdPrimHdr *)arg0)->base);
        /* the << 4 >> 4 pairs below are no-ops that pad the loops: they decide which constants GCC hoists */
        n = ((FdPrimHdr *)arg0)->n[0];
        for (i = 0; i < n; i++, out += 0x34, src += 0x18) {
            gt4 = (FdPrGT4 *)out;
            *(u32 *)gt4->rgb0 = ((FdSrcGT4 *)src)->c[0];
            *(u32 *)gt4->rgb1 = ((FdSrcGT4 *)src)->c[1];
            *(u32 *)gt4->rgb2 = ((FdSrcGT4 *)src)->c[2];
            *(u32 *)gt4->rgb3 = ((FdSrcGT4 *)src)->c[3];
            idx0 = ((FdSrcGT4 *)src)->idx;
            *(u16 *)gt4->uv0 = tab[idx0 & 0xFF];
            *(u16 *)gt4->uv1 = tab[(idx0 & 0xFF00) >> 8];
            *(u16 *)gt4->uv2 = tab[(idx0 >> 16) & 0xFF];
            *(u16 *)gt4->uv3 = tab[idx0 >> 24];
            fl0 = *fp++;
            e0 = mat[fl0 & 0xF];
            ctoff0 = arg3 & -((e0 & 0x3F) != 2);
            gt4->clut = (((e0 << 1) >> 23) + ctoff0) << 6 | ((e0 >> 16) & 0x3F);
            if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
                gt4->tpage = ((e0 & 0xC0) * 8) | ((fl0 * 4) & 0x180) | (((((e0 >> 12) & 1) << 8) & 0x100) >> 3) | ((e0 & 0xF00) >> 8);
            } else {
                gt4->tpage = ((e0 & 0xC0) * 2) | (fl0 & 0x60) | (((((e0 >> 12) & 1) << 8) & 0x100) >> 4) | ((e0 & 0xF00) >> 8) | (((((e0 >> 12) & 1) << 8) & 0x200) << 2);
            }
            m0 = e0 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 & 0x3F;
            if (m0 == 0) {
                du0 = t30;
                dv0 = t38;
            } else {
                dv0 = 0;
                if (m0 == 1) {
                    du0 = t40;
                    dv0 = t48;
                } else {
                    du0 = 0;
                }
            }
            gt4->len = 12;
            gt4->code = 0x3C;
            gt4->uv0[0] += du0;
            gt4->uv0[1] += dv0;
            gt4->uv1[0] += du0;
            gt4->uv1[1] += dv0;
            gt4->uv2[0] += du0;
            gt4->uv2[1] += dv0;
            gt4->uv3[0] += du0;
            gt4->uv3[1] += dv0;
            if (fl0 & 0x10) {
                gt4->code = 0x3E;
            }
        }
        n = ((FdPrimHdr *)arg0)->n[1];
        for (i = 0; i < n; i++, out += 0x28, src += 0x14) {
            gt3 = (FdPrGT3 *)out;
            *(u32 *)gt3->rgb0 = ((FdSrcGT3 *)src)->c[0];
            *(u32 *)gt3->rgb1 = ((FdSrcGT3 *)src)->c[1];
            *(u32 *)gt3->rgb2 = ((FdSrcGT3 *)src)->c[2];
            idx1 = ((FdSrcGT3 *)src)->idx;
            *(u16 *)gt3->uv0 = tab[idx1 & 0xFF];
            *(u16 *)gt3->uv1 = tab[(idx1 & 0xFF00) >> 8];
            *(u16 *)gt3->uv2 = tab[(idx1 >> 16) & 0xFF];
            fl1 = *fp++;
            e1 = mat[fl1 & 0xF];
            ctoff1 = arg3 & -((e1 & 0x3F) != 2);
            gt3->clut = (((e1 << 1) >> 23) + ctoff1) << 6 | ((e1 >> 16) & 0x3F);
            if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
                gt3->tpage = ((e1 & 0xC0) * 8) | ((fl1 * 4) & 0x180) | (((((e1 >> 12) & 1) << 8) & 0x100) >> 3) | ((e1 & 0xF00) >> 8);
            } else {
                gt3->tpage = ((e1 & 0xC0) * 2) | (fl1 & 0x60) | (((((e1 >> 12) & 1) << 8) & 0x100) >> 4) | ((e1 & 0xF00) >> 8) | (((((e1 >> 12) & 1) << 8) & 0x200) << 2);
            }
            m1 = e1 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 & 0x3F;
            if (m1 == 0) {
                du1 = t30;
                dv1 = t38;
            } else {
                dv1 = 0;
                if (m1 == 1) {
                    du1 = t40;
                    dv1 = t48;
                } else {
                    du1 = 0;
                }
            }
            gt3->len = 9;
            gt3->code = 0x34;
            gt3->uv0[0] += du1;
            gt3->uv0[1] += dv1;
            gt3->uv1[0] += du1;
            gt3->uv1[1] += dv1;
            gt3->uv2[0] += du1;
            gt3->uv2[1] += dv1;
            if (fl1 & 0x10) {
                gt3->code = 0x36;
            }
        }
        n = ((FdPrimHdr *)arg0)->n[2];
        for (i = 0; i < n; i++, out += 0x28, src += 0xC) {
            ft4 = (FdPrFT4 *)out;
            *(u32 *)ft4->rgb0 = ((FdSrcFT *)src)->c;
            idx2 = ((FdSrcFT *)src)->idx;
            *(u16 *)ft4->uv0 = tab[idx2 & 0xFF];
            *(u16 *)ft4->uv1 = tab[(idx2 & 0xFF00) >> 8];
            *(u16 *)ft4->uv2 = tab[(idx2 >> 16) & 0xFF];
            *(u16 *)ft4->uv3 = tab[idx2 >> 24];
            fl2 = *fp++;
            e2 = mat[fl2 & 0xF];
            ctoff2 = arg3 & -((e2 & 0x3F) != 2);
            ft4->clut = (((e2 << 1) >> 23) + ctoff2) << 6 | ((e2 >> 16) & 0x3F);
            if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
                ft4->tpage = ((e2 & 0xC0) * 8) | ((fl2 * 4) & 0x180) | (((((e2 >> 12) & 1) << 8) & 0x100) >> 3) | ((e2 & 0xF00) >> 8);
            } else {
                ft4->tpage = ((e2 & 0xC0) * 2) | (fl2 & 0x60) | (((((e2 >> 12) & 1) << 8) & 0x100) >> 4) | ((e2 & 0xF00) >> 8) | (((((e2 >> 12) & 1) << 8) & 0x200) << 2);
            }
            m2 = e2 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 & 0x3F;
            if (m2 == 0) {
                du2 = t30;
                dv2 = t38;
            } else {
                dv2 = 0;
                if (m2 == 1) {
                    du2 = t40;
                    dv2 = t48;
                } else {
                    du2 = 0;
                }
            }
            ft4->len = 9;
            ft4->code = 0x2C;
            ft4->uv0[0] += du2;
            ft4->uv0[1] += dv2;
            ft4->uv1[0] += du2;
            ft4->uv1[1] += dv2;
            ft4->uv2[0] += du2;
            ft4->uv2[1] += dv2;
            ft4->uv3[0] += du2;
            ft4->uv3[1] += dv2;
            if (fl2 & 0x10) {
                ft4->code = 0x2E;
            }
        }
        n = ((FdPrimHdr *)arg0)->n[3];
        for (i = 0; i < n; i++, out += 0x20, src += 0xC) {
            ft3 = (FdPrFT3 *)out;
            *(u32 *)ft3->rgb0 = ((FdSrcFT *)src)->c;
            idx3 = ((FdSrcFT *)src)->idx;
            *(u16 *)ft3->uv0 = tab[idx3 & 0xFF];
            *(u16 *)ft3->uv1 = tab[(idx3 & 0xFF00) >> 8];
            *(u16 *)ft3->uv2 = tab[(idx3 >> 16) & 0xFF];
            fl3 = *fp++;
            e3 = mat[fl3 & 0xF];
            ctoff3 = arg3 & -((e3 & 0x3F) != 2);
            ft3->clut = (((e3 << 1) >> 23) + ctoff3) << 6 | ((e3 >> 16) & 0x3F);
            if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
                ft3->tpage = ((e3 & 0xC0) * 8) | ((fl3 * 4) & 0x180) | (((((e3 >> 12) & 1) << 8) & 0x100) >> 3) | ((e3 & 0xF00) >> 8);
            } else {
                ft3->tpage = ((e3 & 0xC0) * 2) | (fl3 & 0x60) | (((((e3 >> 12) & 1) << 8) & 0x100) >> 4) | ((e3 & 0xF00) >> 8) | (((((e3 >> 12) & 1) << 8) & 0x200) << 2);
            }
            m3 = e3 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 & 0x3F;
            if (m3 == 0) {
                du3 = t30;
                dv3 = t38;
            } else {
                dv3 = 0;
                if (m3 == 1) {
                    du3 = t40;
                    dv3 = t48;
                } else {
                    du3 = 0;
                }
            }
            ft3->len = 7;
            ft3->code = 0x24;
            ft3->uv0[0] += du3;
            ft3->uv0[1] += dv3;
            ft3->uv1[0] += du3;
            ft3->uv1[1] += dv3;
            ft3->uv2[0] += du3;
            ft3->uv2[1] += dv3;
            if (fl3 & 0x10) {
                ft3->code = 0x26;
            }
        }
        n = ((FdPrimHdr *)arg0)->n[4];
        for (i = 0; i < n; i++, out += 0x14, src += 8) {
            pf = (FdPrF *)out;
            *(u32 *)pf->rgb0 = ((FdSrcF *)src)->c;
            pf->len = 4;
            pf->code = 0x20;
        }
        n = ((FdPrimHdr *)arg0)->n[5];
        for (i = 0; i < n; i++, out += 0x18, src += 8) {
            pf = (FdPrF *)out;
            *(u32 *)pf->rgb0 = ((FdSrcF *)src)->c;
            pf->len = 5;
            pf->code = 0x28;
        }
        n = ((FdPrimHdr *)arg0)->n[6];
        for (i = 0; i < n; i++, out += 0x1C, src += 0x10) {
            g3 = (FdPrG3 *)out;
            *(u32 *)g3->rgb0 = ((FdSrcG3 *)src)->c[0];
            *(u32 *)g3->rgb1 = ((FdSrcG3 *)src)->c[1];
            *(u32 *)g3->rgb2 = ((FdSrcG3 *)src)->c[2];
            g3->len = 6;
            g3->code = 0x30;
        }
        n = ((FdPrimHdr *)arg0)->n[7];
        for (i = 0; i < n; i++, out += 0x24, src += 0x14) {
            g4 = (FdPrG4 *)out;
            *(u32 *)g4->rgb0 = ((FdSrcG4 *)src)->c[0];
            *(u32 *)g4->rgb1 = ((FdSrcG4 *)src)->c[1];
            *(u32 *)g4->rgb2 = ((FdSrcG4 *)src)->c[2];
            *(u32 *)g4->rgb3 = ((FdSrcG4 *)src)->c[3];
            g4->len = 8;
            g4->code = 0x38;
        }
        pass++;
    } while (pass < 2);
    return arg1 + ((FdPrimHdr *)arg0)->off16 * 2;
}

void func_800AD7B8(void *arg0) {
    Func800AD7B8Hdr *h = arg0;
    Func800AD7B8Entry *e;
    u16 rect[4];
    u32 i;
    u32 n;

    i = 0;
    n = h->n;
    e = h->e;
    for (; i < n; i++) {
        rect[0] = e[i].x;
        rect[1] = e[i].y;
        rect[2] = e[i].w;
        rect[3] = e[i].h;
        func_80044000(rect, (u8 *) h + e[i].off);
    }
}

void func_800AD858(FdLdHdr *h) {
    s32 n;
    s32 i;
    s32 t;
    FdLdEnt *p;
    FdLdEnt *e;

    if (h != 0) {
        n = h->count;
        if (n != 0) {
            p = h->e;
            for (i = 0; i < n; i++) {
                e = &p[i];
                switch (e->type) {
                case 0:
                    func_80042D98(e->arg, (u8 *)h + e->off, e->len);
                    break;
                case 1:
                    if ((u32)e->arg < *(u16 *)(D_800DFCA0 + 4)) {
                        t = D_800DFCA0 + *(s32 *)(D_800DFCA0 + 8) + (e->arg << 9);
                        *(FdBlk200 *)t = *(FdBlk200 *)((u8 *)h + e->off);
                    }
                    break;
                case 2:
                    if ((u32)e->arg < *(u16 *)(D_800DFCA0 + 6)) {
                        *(FdBlk20 *)(D_800DFCA0 + *(s32 *)(D_800DFCA0 + 0xC) + (e->arg << 5)) = *(FdBlk20 *)((u8 *)h + e->off);
                    }
                    break;
                case 3:
                    func_80044000(&e->arg, (u8 *)h + e->off);
                    break;
                }
            }
        }
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800ADAA4);

s32 func_800ADC90(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 saved;
    s32 *q;
    u32 i;

    saved = *(s32 *)0x1F800000;
    q = *(s32 **)0x1F800004;
    for (i = 0; i < *(u16 *)(arg0 + 2); i++) {
        *(s32 *)0x1F800000 = saved;
        arg2 = func_800ADD70(arg0, arg1, arg2, i);
    }
    if (arg3 != 0) {
        func_80033E74(q[0], q[1], D_800DFCA0, 0);
        while (func_80034B44() != 0) {
        }
    }
    return arg2;
}
