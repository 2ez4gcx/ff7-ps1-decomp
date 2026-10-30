#include "common.h"
#include "magic_timedmg/decls.h"

void func_801B0000(void) {
    func_801B171C();
}

void func_801B0020(s32 arg0, void *arg1) {
    M2C_UNK sp10;
    M2C_UNK sp14;
    s16 temp_a0;
    s16 temp_a0_2;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BBDC(arg0, arg1, &sp10, &sp14);
    temp_a0 = M2C_FIELD(arg1, s16 *, 0);
    if (temp_a0 < D_801B3164) {
        M2C_FIELD(arg1, s16 *, 0) = (s16) (u16) D_801B3164;
    } else if ((0x13F - D_801B3164) < temp_a0) {
        M2C_FIELD(arg1, s16 *, 0) = (s16) (0x13F - (u16) D_801B3164);
    }
    temp_a0_2 = M2C_FIELD(arg1, s16 *, 2);
    if (temp_a0_2 < D_801B3164) {
        M2C_FIELD(arg1, s16 *, 2) = (s16) (u16) D_801B3164;
        return;
    }
    if ((0xA6 - D_801B3164) < temp_a0_2) {
        M2C_FIELD(arg1, s16 *, 2) = (s16) (0xA6 - (u16) D_801B3164);
    }
}

INCLUDE_ASM("../asm/us/magic_timedmg/nonmatchings/text", func_801B0124);

void func_801B06E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    MgSVec v;
    s32 sp18;
    s32 sp1C;
    MgSVec *s;
    MgSVec *o;
    s32 *row;
    s32 *e;
    s32 i;
    s32 j;
    s32 k;
    s32 r;
    s32 d;
    s32 z;

    s = (MgSVec *)0x1F800000;
    o = (MgSVec *)0x1F800008;
    D_801B3184[0] = func_8003B66C() * 4;
    func_8003B64C(&v.vx, &v.vz);
    func_8003B48C(&D_801B3184[-7]);
    func_8003B51C(&D_801B3184[-7]);
    i = 0;
    row = D_801B9628;
    do {
        r = i * D_801B3164 / 16;
        j = 0;
        k = i << 6;
        e = row;
        do {
            s->vx = r * func_80039A74(j << 8) >> 12;
            s->vy = r * func_80039B40(j << 8) >> 12;
            s->vz = arg0 * *e >> 12;
            func_8003BBDC((s32)s, o, &sp18, &sp1C);
            e++;
            if (arg2 != 0) {
                o->vx -= v.vx;
                o->vy -= v.vz;
                d = func_80039F5C(o->vx * o->vx + o->vy * o->vy);
                z = (func_80039A74(d * 100 + arg1) * arg2 >> 12) + 0x1000;
                o->vx = (o->vx * z >> 12) + v.vx;
                o->vy = (o->vy * z >> 12) + v.vz;
            }
            *(s16 *)((u8 *)D_801B91E8 + k) = o->vx - v.vx;
            *(s16 *)((u8 *)D_801B91E8 + k + 2) = o->vy - v.vz;
            k += 4;
            j++;
        } while (j < 16);
        i++;
        row += 16;
    } while (i < 16);
}

INCLUDE_ASM("../asm/us/magic_timedmg/nonmatchings/text", func_801B095C);

void func_801B0DD0(void) {
    TdObj *p;
    s32 t;
    s32 u;
    s32 a;
    s32 b;
    s32 c;

    p = &D_80162978[D_8015169C];
    u = p->unk2;
    t = u;
    if (u < 10) {
        a = u * 150;
        b = 0;
        c = 0;
    } else {
        u -= 10;
        a = 0x5DC;
        if (u < 5) {
            b = 0;
            c = 0;
        } else {
            u -= 5;
            if (u < 5) {
                b = -t << 9;
                a = -(u * 0x5DC) / 5 + 0x5DC;
                c = (u << 9) / 5;
            } else {
                u -= 5;
                if (u < 15) {
                    a = 0;
                    b = -t << 9;
                    c = 0x200;
                } else {
                    u -= 15;
                    if (u < 10) {
                        a = 0;
                        b = -t << 9;
                        c = -(u << 9) / 10 + 0x200;
                    } else {
                        p->unk0 = -1;
                        return;
                    }
                }
            }
        }
    }
    func_801B06E0(a, b, c, b);
    func_801B0124(*(s16 *)D_801B9A68, D_801B9A6A);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0F74(void) {
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    MgSVec *sv;
    MgMat *m1;
    MgSVec *out;
    MgMat *m2;
    s16 *f;
    TdObj *p;
    s32 t;
    s32 a;
    s32 i;

    sv = (MgSVec *)0x1F800008;
    m1 = (MgMat *)0x1F800010;
    out = (MgSVec *)0x1F800030;
    m2 = (MgMat *)0x1F800034;
    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        a = t * 100;
        D_801B318C[0] = D_801B318C[1] = D_801B318C[2] = (t << 7) / 10;
    } else {
        t -= 10;
        a = 0x3E8;
        if (t < 0x19) {
            D_801B318C[0] = D_801B318C[1] = D_801B318C[2] = 0x80;
        } else {
            t -= 0x19;
            if (t >= 10) {
                p->unk0 = -1;
                return;
            }
            do {
                a = t * 0x190 + 0x3E8;
                D_801B318C[0] = D_801B318C[1] = D_801B318C[2] = -(t << 7) / 10 - 0x80;
            } while (0);
        }
    }
    func_8003B64C(&sp10, &sp14);
    func_8003C21C((MgSVec *)&p->unkC, m1);
    m1->t[0] = 0;
    m1->t[1] = 0;
    m1->t[2] = func_8003B66C() * 5;
    i = 0;
    f = D_801B9A68;
    do {
        func_8003B48C(m1);
        func_8003B51C(m1);
        sv->vx = func_80039A74(i << 8) * a >> 12;
        sv->vy = func_80039A74(i << 10) * a >> 15;
        sv->vz = func_80039B40(i << 8) * a >> 12;
        i++;
        func_8003BBDC((s32)sv, out, &sp18, &sp1C);
        m2->t[0] = out->vx - sp10 + (f[0] - sp10) * 5;
        m2->t[1] = out->vy - sp14 + (f[1] - sp14) * 5;
        m2->t[2] = m1->t[2];
        func_8003B48C(&D_801B319C);
        func_8003B51C(m2);
        D_801D9D1C = func_800D4D90(D_801B3188, D_801517C0 + 0x4088, 0, D_801D9D1C);
    } while (i < 16);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x23) {
            p->unkC += 0x10;
            p->unkE += 0xC0;
            p->unk10 += 0x40;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_timedmg/nonmatchings/text", func_801B128C);

void func_801B1504(void) {
    TdObj *p;
    TdObj *q;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_800D52A0(0x400, 4);
            D_800F5B70.v = D_800F5B71.v = D_800F5B72.v = 0;
        }
        if (p->unk2 == 4) {
            i = 0;
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0DD0)];
            q->unk4 = p->unk4;
            do {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0F74)];
                q->unkC = q->unkE = q->unk0 = 0;
                q->unk10 = i << 9;
                q->unk4 = p->unk4;
            } while (++i < 4);
            func_800BBEAC((M2C_UNK *)func_801B128C);
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x181);
        }
        if (p->unk2 == 0x27) {
            func_800D5774(p->unk0);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B1688(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_801B0020((s32)&p->unk4, D_801B9A68);
    D_801D9D1C = D_801B9D1C + (p->unk2 << 16);
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 4);
        p->unk0 = -1;
    }
}

void func_801B171C(arg0) {
    MgSVec pos;
    MgObjAwa *p;
    s32 i;

    func_800D2980(D_801B1834, 0, 0, 0);
    D_801D9D20 = arg0;
    for (i = 0; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            func_800D3994(i, D_8015190F[i][0], &pos);
            break;
        }
    }
    func_801B095C();
    p = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1688)];
    p->unk4 = pos;
    p = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B1504)];
    p->unk0 = i;
    p->unk4 = pos;
}
