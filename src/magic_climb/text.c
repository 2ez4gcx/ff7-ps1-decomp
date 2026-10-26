#include "common.h"
#include "magic_climb/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0B44();
    return &D_801B4DFC;
}

void func_801B0028(MgSVec *a, MgSVec *b, s32 k, MgSVec *out) {
    MgVec d;

    d.vx = b->vx - a->vx;
    d.vy = b->vy - a->vy;
    d.vz = b->vz - a->vz;
    func_8003A08C(&d, &d);
    out->vx = a->vx + ((k * d.vx) >> 12) - b->vx;
    out->vy = a->vy + ((k * d.vy) >> 12) - b->vy;
    out->vz = a->vz + ((k * d.vz) >> 12) - b->vz;
}

void func_801B0124(void) {
    MgObjP *p;
    u8 *q;
    s32 t;
    s32 k0;
    s32 k1;
    s32 ext;
    s32 flag;
    s32 c;
    s32 r;
    s32 k;

    p = (MgObjP *)&D_80162978[D_8015169C];
    t = p->unk2;
    k0 = ((t + 1) << 12) / 40;
    k1 = (t << 12) / 40;
    func_8003B48C(D_800FA63C);
    func_8003B51C(D_800FA63C);
    q = D_801D6AB0;
    r = func_8003BD7C(p->unkC - 2, p->unkC - 1, p->unkC, p->unkC + 1, q + 8, q + 0x10, q + 0x18, q + 0x20, &ext, &flag);
    if (!(flag & 0x60000)) {
        *(s32 *)q = 0x08000000;
        func_8003B710(D_801B66C0, k0, &c);
        *(s32 *)(q + 4) = *(s32 *)(q + 0xC) = c | 0x3A000000;
        func_8003B710(D_801B66C0, k1, &c);
        *(s32 *)(q + 0x14) = *(s32 *)(q + 0x1C) = c;
        k = 0x70;
        func_80046794(((r >> 2) << 2) + k + D_801517C0, q);
        D_801D6AB0 = q + 0x24;
    }
    if (D_80062D98 == 0) {
        p->unk2 += 4;
        if (p->unk2 >= 0x28) {
            p->unk0 = -1;
        }
    }
}

void func_801B0304(void) {
    MgObjP *p;
    MgObjP *q;
    s32 i;
    s32 k;
    s32 n;
    ClB8 *src;

    p = (MgObjP *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        func_800D41FC(D_800FA63C, D_800FA6E0[D_801B6AAC], &D_801B66D4->m);
        func_8003B48C(&D_801B66D4->m);
        func_8003B51C(&D_801B66D4->m);
        func_8003BC6C(&D_801B66C4[0], &D_801B66D4->a, &D_801B66D4->flag);
        func_8003BC6C(&D_801B66C4[1], &D_801B66D4->b, &D_801B66D4->flag);
        if (p->unk0 != 0) {
            n = p->unk0 - 1;
            src = (ClB8 *)&D_801B66E8[n].a;
            *(ClB8 *)&D_801B66D4->p0 = *src;
            n = p->unk0 - 1;
            *(ClB8 *)&D_801B66D4->p1 = *(ClB8 *)&D_801B66E8[n].b;
            for (i = 1; i < 5; i++) {
                k = (i << 12) / 4;
                D_801B66D4->q0.vx = (k * D_801B66D4->a.vx + D_801B66D4->p0.vx * (0x1000 - k)) >> 12;
                D_801B66D4->q0.vy = (k * D_801B66D4->a.vy + D_801B66D4->p0.vy * (0x1000 - k)) >> 12;
                D_801B66D4->q0.vz = (k * D_801B66D4->a.vz + D_801B66D4->p0.vz * (0x1000 - k)) >> 12;
                D_801B66D4->q1.vx = (k * D_801B66D4->b.vx + D_801B66D4->p1.vx * (0x1000 - k)) >> 12;
                D_801B66D4->q1.vy = (k * D_801B66D4->b.vy + D_801B66D4->p1.vy * (0x1000 - k)) >> 12;
                D_801B66D4->q1.vz = (k * D_801B66D4->b.vz + D_801B66D4->p1.vz * (0x1000 - k)) >> 12;
                func_801B0028(&D_801B66D4->q0, &D_801B66D4->q1, 0x3E8, &D_801B66D4->out);
                D_801B66E8[p->unk0].a.vx = D_801B66D4->q0.vx + D_801B66D4->out.vx;
                D_801B66E8[p->unk0].a.vy = D_801B66D4->q0.vy + D_801B66D4->out.vy;
                D_801B66E8[p->unk0].a.vz = D_801B66D4->q0.vz + D_801B66D4->out.vz;
                D_801B66E8[p->unk0].b.vx = D_801B66D4->q1.vx + D_801B66D4->out.vx * 2;
                D_801B66E8[p->unk0].b.vy = D_801B66D4->q1.vy + D_801B66D4->out.vy * 2;
                D_801B66E8[p->unk0].b.vz = D_801B66D4->q1.vz + D_801B66D4->out.vz * 2;
                q = (MgObjP *)&D_80162978[func_800BBEAC(func_801B0124)];
                q->unk0 = p->unk2 * 4 + i - 1;
                q->unk2 = 4 - i;
                q->unkC = &D_801B66E8[p->unk0].a;
                p->unk0++;
            }
        } else {
            D_801B66E8[p->unk0].a.vx = D_801B66D4->a.vx;
            D_801B66E8[p->unk0].a.vy = D_801B66D4->a.vy;
            D_801B66E8[p->unk0].a.vz = D_801B66D4->a.vz;
            D_801B66E8[p->unk0].b.vx = D_801B66D4->b.vx;
            D_801B66E8[p->unk0].b.vy = D_801B66D4->b.vy;
            D_801B66E8[p->unk0].b.vz = D_801B66D4->b.vz;
            p->unk0++;
        }
        p->unk2++;
        if (p->unk2 >= 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B07F4(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, p->unk12);
    frame = &D_801B66E0;
    *frame = p->unk2;
    D_801D6AB0 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D6AB0);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B4C00.v) {
            p->unk0 = -1;
        }
    }
}

void func_801B08B4(void) {
    MgTask *p;
    MgTask *q;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x24) {
            func_800D5138(1);
        }
        if (p->unk2 == 0x25) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B07F4)];
            func_800D41FC(D_800FA63C, D_800FA6E0[D_801B6AAC], &D_801B66E4->m);
            D_801B66E4->v.vx = 0;
            D_801B66E4->v.vy = 0;
            D_801B66E4->v.vz = -0x1F4;
            func_8003B2CC(&D_801B66E4->m, &D_801B66E4->v, &D_801B66E4->v);
            q->unk4 = D_801B66E4->v.vx + D_801B66E4->m.t[0];
            q->unk6 = D_801B66E4->v.vy + D_801B66E4->m.t[1];
            q->unk8 = D_801B66E4->v.vz + D_801B66E4->m.t[2];
            q->unk12 = -0x3E8;
            func_800D51D4(5);
            func_800D55F4(0x20, func_800D56A8(&q->unk4), 0x12);
        }
        if (p->unk2 == 0x38) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0304)];
            q->unk0 = 0;
        }
        if (p->unk2 == 0x3B) {
            func_800D55F4(0x20, func_800D56A8(D_80151A4C[D_801B6AAC]), 0x1B);
        }
        if (p->unk2 == 0x4F) {
            i = 0;
            do {
                if ((D_801B6AA8 >> i) & 1) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0AE4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D6AB0 = D_801B6AB0 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B0B44(arg0, arg1) {
    func_800D2980(D_801B0BBC, 0, 0, 0);
    D_801B6AA8 = arg0;
    D_801B6AAC = arg1;
    func_800BBEAC(func_801B0AE4);
    return func_800BBEAC(func_801B08B4);
}
