#include "common.h"
#include "magic_s_guard/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0B5C();
    return &D_801B10DC;
}

void func_801B0028(void) {
    MgTask *p;
    MgSVec *rot;
    SgRgb *col;
    MgVec *scale;
    s32 *flag;
    MgMat *m;
    s32 v;
    SgPart *a;
    s32 i;
    s32 n;
    MgMat *fp;

    p = (MgTask *)&D_80162978[D_8015169C];
    m = (MgMat *)0x1F800000;
    flag = (s32 *)0x1F800020;
    rot = (MgSVec *)0x1F800024;
    scale = (MgVec *)0x1F80002C;
    *(s16 *)0x1F800026 = 0;
    a = (SgPart *)D_801B3228;
    n = 0;
    i = 0;
    fp = &D_800FA63C;
    col = &D_801B3214;
    rot->vx = 0;
    do {
        i++;
        if (a->unk0 > 0) {
            func_8003B48C(fp);
            func_8003B51C(fp);
            func_8003BC6C((MgSVec *)&a->unk4, (MgVec *)m->t, flag);
            rot->vz = a->unkE;
            func_8003C21C(rot, m);
            v = (a->unkC << 9) * a->unk0 >> 12;
            scale->vx = scale->vy = scale->vz = v;
            func_8003B35C(m, scale);
            func_8003B48C(m);
            func_8003B51C(m);
            col->r = col->g = col->b = a->unk0 * 0x10;
            D_801D3B88 = (u8 *)func_800D4D90((u8 *)col - 4, D_801517C0 + 0x70, 0xC, (s32)D_801D3B88);
            n++;
            a->unk0 -= 2;
        }
        a++;
    } while (i < 0x96);
    if (n == 0 && D_80162080 < 3) {
        p->unk0 = -1;
    }
}

void func_801B0200(void) {
    s32 i;

    for (i = 0x950; i >= 0; i -= 0x10) {
        *(s16 *)(D_801B3228 + i) = 0;
    }
}

void *func_801B0228(void) {
    u8 *p;
    s32 i;
    void *r;

    p = D_801B3228;
    i = 0;
loop:
    if (*(s16 *)(D_801B3228 + i) <= 0) {
        r = p;
        goto done;
    }
    i += 0x10;
    r = (void *)(i < 0x960);
    p += 0x10;
    if (r != 0) {
        goto loop;
    }
done:
    return r;
}

void func_801B0268(void) {
    MgTask *p;
    SgPart *q;
    s32 ang;
    s32 i;
    s32 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            ang = p->unk16;
            if (p->unk0 == 0) {
                ang = -ang;
            }
            q = func_801B0228();
            q->unk0 = i + 7;
            q->unk4 = p->unk4 + (p->unk14 * func_80039A74(ang) >> 12);
            q->unk6 = p->unk6;
            q->unk8 = p->unk8 + (p->unk14 * func_80039B40(ang) >> 12);
            q->unkC = p->unk1A;
            q->unkE = p->unk1C;
            if (p->unk14 >= 0x1F5) {
                p->unk14 = p->unk14 * 13 >> 4;
            }
            n = 0x21555 / p->unk14;
            p->unk6 += p->unk18;
            p->unk16 += n;
            i++;
            if (p->unk18 >= 0x1F) {
                p->unk18 = p->unk18 * 7 >> 3;
            }
            p->unk1C += 0x100;
        } while (i < 2);
        p->unk2++;
        if (p->unk2 >= 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B0444(void) {
    MgTask *p;
    MgSVec *rot;
    MgMat *m;
    MgVec *scale;
    s32 d;
    s32 a;
    s32 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    rot = (MgSVec *)0x1F800000;
    m = (MgMat *)0x1F800008;
    scale = (MgVec *)0x1F800028;
    a = p->unk0;
    d = p->unk2;
    if (d < a) {
        *(s32 *)&D_801B3220 = 0x2E808080;
    } else {
        d = d - a;
        if (d < 5) {
            v = -(d << 7) / 5 - 0x80;
            D_801B3220 = D_801B3221 = D_801B3222 = v;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_800D4284(&p->unk4, 0, m);
    rot->vy = 0;
    rot->vx = 0;
    rot->vz = p->unk1C;
    func_8003C21C(rot, m);
    scale->vx = scale->vy = scale->vz = p->unk1A;
    func_8003B35C(m, scale);
    func_8003B48C(m);
    func_8003B51C(m);
    D_801D3B88 = (u8 *)func_800D4D90(&D_801B321C, D_801517C0 + 0x70, 0xC, (s32)D_801D3B88);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC = p->unkC * 7 >> 3;
        p->unkE = p->unkE * 7 >> 3;
        p->unk10 = p->unk10 * 7 >> 3;
    }
    p->unk1C += 0x100;
}

void func_801B064C(void) {
    MgTask *p;
    MgTask *b;
    MgTask *q;
    MgSVec *rot;
    MgMat *m;
    s32 i;
    s32 t;

    b = D_80162978;
    p = &b[D_8015169C];
    if (D_80062D98 == 0) {
        rot = (MgSVec *)0x1F800000;
        m = (MgMat *)0x1F800008;
        if (p->unk2 == 0) {
            D_800F5B70 = 0x80;
            D_800F5B71 = 0x60;
            D_800F5B72 = 0;
            func_800D52A0(0x800, 10);
        }
        t = (u16)p->unk2;
        if ((u32)(t - 0x19) < 0x19) {
            if (((s16)t - 0x19) % 5 == 0) {
                q = &b[func_800BBEAC(&func_801B0268)];
                q->unk4 = p->unk4;
                q->unk6 = -(func_80042DA8() % 1000 + 0x1194);
                q->unk8 = p->unk8;
                q->unk14 = 0x1388;
                q->unk16 = ((p->unk2 - 0x19) / 5 << 12) / 5;
                q->unk18 = 0x226;
                q->unk1A = func_80042DA8() % 0x1000 + 0x800;
                q->unk0 = func_80042DA8() & 1;
                q->unk1C = func_80042DA8() & 0xFFF;
            }
        }
        if (p->unk2 == 0x46) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(&func_801B0444)];
                q->unk0 = func_80042DA8() % 5 + 5;
                q->unk1A = func_80042DA8() % 0x1000 + 0x800;
                rot->vx = func_80042DA8() % 0x800 - 0x400;
                i++;
                rot->vy = func_80042DA8() & 0xFFF;
                rot->vz = 0;
                func_8003C21C(rot, m);
                rot->vx = 0;
                rot->vy = -(func_80042DA8() % 200 + 0x12C);
                rot->vz = 0;
                func_8003B2CC(m, rot, &q->unkC);
                *(SgB8 *)&q->unk4 = *(SgB8 *)&p->unk4;
                q->unk1C = func_80042DA8() & 0xFFF;
            } while (i < 0x14);
        }
        if (p->unk2 == 0x46) {
            func_800D5774(p->unk0);
            if (p->unk2 == 0x46) {
                func_800D52A0(0, 10);
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B09F0(void) {
    MgObj20 *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 == 0x20) {
            func_800D55F4(0x20, func_800D574C(D_801D3B8C), 0x7D);
            temp_s0->unk0 = -1;
        }
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

void func_801B0A7C(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B064C)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

void func_801B0AFC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D3B88 = D_801B3B88 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B0B5C(arg0, arg1) {
    func_800D2980(&D_801B0BFC, 0, 0, 0);
    func_800BBEAC(func_801B0AFC);
    func_801B0200();
    func_800BBEAC(func_801B0028);
    D_801D3B8C = arg0;
    func_800D5444(arg0, arg1, 0, func_801B0A7C);
    return func_800BBEAC(func_801B09F0);
}
