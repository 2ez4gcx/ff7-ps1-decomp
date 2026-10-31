#include "common.h"
#include "magic_lgirl/decls.h"

s32 func_801B0054(void) {
    func_801B0C9C();
    return 0;
}

void func_801B0078(MgRing *r, s32 v) {
    s32 head;
    s32 tail;
    s32 count;
    s32 size;
    s32 last;

    tail = r->tail;
    last = r->head;
    count = r->count;
    r->prev = r->last;
    size = r->size;
    r->last = last;
    head = last;
    r->buf[head] = v;
    head++;
    count++;
    if (head >= size) {
        head = 0;
    }
    if (count >= size) {
        count = size;
    }
    if (head == tail) {
        tail++;
        count--;
        if (tail >= size) {
            tail = 0;
        }
    }
    r->head = head;
    r->tail = tail;
    r->count = count;
    r->size = size;
}

void func_801B00F8(void) {
    MgTask *p;
    LgFxList *l;
    LgFx *e;
    s32 t;
    s32 c;
    s32 a;
    s32 i;
    s32 n;
    s16 v;
    u8 pad[8];

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 8) {
        D_801D0E9C[3] = 0x2E;
        a = 1;
        c = p->unk2 << 4;
    } else {
        a = 0;
        if (t >= 0x2A) {
            a = 1;
            D_801D0E9C[3] = 0x2E;
            c = -0x80 - ((p->unk2 - 0x2A) << 4);
        } else {
            D_801D0E9C[3] = 0x2C;
            c = 0x80;
        }
    }
    D_801D0E9C[0] = D_801D0E9C[1] = D_801D0E9C[2] = c;
    i = 0;
    l = &D_801D0D72;
    n = l->cnt;
    if (n != 0) {
        e = l->e;
        do {
            i++;
            e->flag = (e->flag & 0xFE) | a;
            e++;
        } while (i < n);
    }
    v = p->unk14;
    func_800D4368(&p->unk4, v, -(v >> 3));
    D_801E8EBC = func_800D4D90(&D_801D0E98, D_801517C0 + 0x70, 0xC, D_801E8EBC);
    if (p->unk2 >= 0x32) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_lgirl/nonmatchings/text", func_801B0270);

void func_801B07D4(void) {
    MgTask *p;
    s32 t;
    s32 c;
    s16 v;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t >= 6) {
        c = -0x80 - (t - 6) * 0x15;
    } else {
        c = 0x80;
    }
    D_801D0EB4[0] = D_801D0EB4[1] = D_801D0EB4[2] = c;
    v = p->unk14;
    func_800D4368(&p->unk4, v, -(v >> 3));
    D_801E8EBC = func_800D4D90(D_801D0EB4 - 4, D_801517C0 + 0x70, 0xC, D_801E8EBC);
    if (p->unk2 >= 0xC) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk14 = p->unk16 * func_80039A74(p->unk18) >> 12;
        p->unk18 += p->unk1A;
        p->unk2++;
        p->unk1A -= p->unk1A / 6;
    }
}

void func_801B093C(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s32 i;

    if (D_80062D98 == 0) {
        b = D_80162978;
        p = &b[D_8015169C];
        if (p->unk2 == 6) {
            q = &b[func_800BBEAC(&func_801B00F8)];
            *(MgSVec *)&q->unk4 = D_801E8ECC;
            q->unk14 = 0xC00;
        }
        if (p->unk2 == 0xE) {
            q = &b[func_800BBEAC(&func_801B0270)];
            q->unk4 = 0xE6;
            q->unk6 = -0x10E;
            q->unk8 = -0x258;
            q->unkA = 0xC8;
            *(MgSVec *)&q->unkC = *(MgSVec *)&q->unk4;
            q->unk12 = 0x3C;
            q->unk14 = q->unk16 = 0x199;
            q->unk18 = 0x800;
            q->unk1A = 0x1F4;
            q->unk1C = 0;
            D_801E8ED4 = D_801E8ED8 = D_801E8EDC = 0;
            D_801E8EE4 = -1;
            D_801E8EE0 = 6;
            func_800D55F4(0x20, func_800D56A8(&D_801E8ECC), 0x10D);
        }
        if (p->unk2 == 0x1E) {
            i = 0;
            do {
                if ((1 << i) & D_801E8EC4) {
                    q = &D_80162978[func_800BBEAC(&func_801B07D4)];
                    func_800D3994(i, D_8015190F[i][0], &q->unk4);
                    q->unk14 = 0;
                    q->unk16 = 0x4B00;
                    q->unk18 = q->unk1A = 0x15E;
                }
                i++;
            } while (i < 10);
            func_800D55F4(0x20, func_800D574C(D_801E8EC4), 0x11C);
        }
        if (p->unk2 == 0x37) {
            i = 0;
            do {
                if ((1 << i) & D_801E8EC4) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
        }
        if (p->unk2 >= 0x3C) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0BFC(void) {
    D_80162978[D_8015169C].unk0 = -1;
    func_800D3994(D_801E8EC8, D_8015190F[D_801E8EC8][0], &D_801E8ECC);
    *(u16 *)&D_801E8ECC.vy -= 0x320;
    func_800BBEAC(&func_801B093C);
}

INCLUDE_RODATA("../asm/us/magic_lgirl/nonmatchings/text", D_801B0000);

void func_801B0C9C(arg0, arg1) {
    D_801E8EC0 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B0D28, 0, 0, 0);
    func_800BBEAC(&func_801B0BFC);
    D_801E8EC4 = arg0;
    D_801E8EC8 = arg1;
}
