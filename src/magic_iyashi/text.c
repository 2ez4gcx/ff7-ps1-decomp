#include "common.h"
#include "magic_iyashi/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0D64();
    return &D_801B0E3C;
}

INCLUDE_ASM("../asm/us/magic_iyashi/nonmatchings/text", func_801B0028);

void func_801B028C(void) {
    IyTask *p;
    IyFrame *q;

    p = (IyTask *)&D_80162978[D_8015169C];
    q = &D_801B834C;
    q->rec = p->unk14;
    q->f = p->unk2;
    func_800D4368(&p->unk8, p->unk18, 0);
    D_801DA778 = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_801DA778);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= p->unk14->unk4) {
            p->unk0 = -1;
        }
    }
}

void func_801B035C(void) {
    MgMat m;
    MgSVec v;
    IyTask *p;
    IyTask *q;
    s16 *r;

    p = (IyTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        r = &D_801B835A;
        *r = p->unk10;
        func_8003C21C((MgSVec *)(r - 1), &m);
        func_8003B2CC(&m, (MgSVec *)&p->unk8, &v);
        v.vx += D_80151A4C[p->unk4][0];
        v.vy += D_80151A4C[p->unk4][1];
        v.vz += D_80151A4C[p->unk4][2];
        q = (IyTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B028C)];
        *(IyB8 *)&q->unk8 = *(IyB8 *)&v;
        if (p->unk2 & 1) {
            q->unk14 = &D_801B81A8;
        } else {
            q->unk14 = &D_801B8258;
        }
        q->unk18 = 0x1000;
        p->unk10 = (p->unk10 + p->unk12) & 0xFFF;
        p->unkA += 0x21;
        p->unk2++;
        if (p->unk2 >= 0x1E) {
            func_800D5774(p->unk4);
            p->unk0 = -1;
        }
    }
}

void func_801B055C(void) {
    MgTask *p;
    u8 *b;

    p = (MgTask *)&D_80162978[D_8015169C];
    b = &D_801B8364;
    *b = p->unk2 * 0x20 - 0x80;
    func_800D4368(&p->unk8, 0x1000, -0x80);
    D_801DA778 = func_800D6260(b - 4, D_801517C0 + 0x70, 0xC, D_801DA778);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 4) {
            p->unk0 = -1;
        }
    }
}

void func_801B0624(IyObj *arg0) {
    MgSVec a;
    MgSVec b;
    MgSVec c;
    MgSVec d;
    s32 ext;
    s32 flag;
    IyPart *p;
    u8 *q;
    s32 n;
    s32 s;
    s32 k;
    s32 i;
    s32 r;
    u32 col;
    s32 t;

    p = (IyPart *)arg0;
    col = 0x3A000000;
    t = p->unk8;
    if (t < 9) {
        n = t;
    } else if (t < 0xD) {
        n = 8;
    } else if (t < 0x15) {
        n = 0x14 - t;
    } else {
        return;
    }
    if (n < 2) {
        return;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    s = n * 0x14;
    k = (p->unk2 - n) & 7;
    for (i = 1; i < n; i++) {
        a.vx = b.vx = p->trail[k].vx;
        a.vy = p->trail[k].vy - s;
        b.vy = p->trail[k].vy + s;
        a.vz = b.vz = p->trail[k].vz;
        k = (k + 1) & 7;
        s -= 0x14;
        c.vx = d.vx = p->trail[k].vx;
        c.vy = p->trail[k].vy - s;
        d.vy = p->trail[k].vy + s;
        c.vz = d.vz = p->trail[k].vz;
        q = D_801DA778;
        r = func_8003BD7C(&a, &b, &c, &d, q + 8, q + 0x10, q + 0x18, q + 0x20, &ext, &flag);
        if (r > 0) {
            *(u32 *)(q + 4) = *(u32 *)(q + 0xC) = col;
            col += 0x101010;
            *(s32 *)q = 0x08000000;
            *(u32 *)(q + 0x14) = *(u32 *)(q + 0x1C) = col;
            func_80046794(D_801517C0 + 0x70 + ((r >> 2) << 2), q);
            D_801DA778 = q + 0x24;
        }
    }
}

void func_801B082C(IyObj *arg0) {
    MgMat m;
    u8 pad[8];
    IyPart *p;
    s16 *q;
    MgSVec *g;

    p = (IyPart *)arg0;
    if (D_80062D98 == 0) {
        q = &D_801B8372;
        *q = p->unk4;
        func_8003C21C((MgSVec *)(q - 1), &m);
        func_8003B2CC(&m, (MgSVec *)&p->unkC, &p->trail[p->unk2]);
        g = D_801B8380;
        p->trail[p->unk2].vx += g->vx;
        p->trail[p->unk2].vy += g->vy;
        p->trail[p->unk2].vz += g->vz;
        p->unk2 = (p->unk2 + 1) & 7;
        p->unk4 = (p->unk4 + p->unk6) & 0xFFF;
        p->unkC -= p->unkC >> 2;
        p->unkE -= p->unkE >> 3;
        p->unk8++;
        if (p->unk8 >= 0x14) {
            p->unk0 = 0;
            return;
        }
    }
    func_801B0624(arg0);
}

void func_801B0978(void) {
    MgObj20 *p;
    s32 i;
    s32 n;

    n = 0;
    p = &D_80162978[D_8015169C];
    for (i = 0; i < 100; i++) {
        if (D_801B8388[i].unk0 != 0) {
            func_801B082C(&D_801B8388[i]);
            n++;
        }
    }
    if (n == 0) {
        p->unk0 = -1;
    }
}

IyObj *func_801B0A28(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_801B8388[i].unk0 == 0) {
            D_801B8388[i].unk0 = 1;
            return &D_801B8388[i];
        }
    }
    return NULL;
}

void func_801B0A74(void) {
    u8 pad[0x40];
    MgTask *p;
    MgTask *q;
    MgTask *r;
    s32 t;
    s32 i;
    s32 off;
    s32 a;
    s32 b;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t == 0) {
            func_800D55F4(0x20, func_800D56A8((s16 *)D_80151A4C[D_801B8378]), 0x22);
        }
        if (t == 0xB) {
            func_800BBEAC((M2C_UNK *)func_801B0028);
            func_800BBEAC((M2C_UNK *)func_801B0978);
        }
        if (t == 0x34) {
            for (i = 0, off = 0; i < 10; i++, off += 0xB9C) {
                if ((D_801B8384 >> i) & 1) {
                    q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B035C)];
                    q->unk4 = i;
                    q->unk8 = *(u16 *)((u8 *)D_801518F6 + off);
                    q->unkA = -0x3E8;
                    q->unkC = 0;
                    q->unk10 = func_80042DA8() & 0xFFF;
                    q->unk12 = 0x200;
                }
            }
        }
        if (t >= 0xB) {
            t -= 0xB;
            if (t < 0x50 && (t & 3) == 0) {
                r = (MgTask *)func_801B0A28();
                if (r != 0) {
                    a = t * 0x19 + 0x3E8;
                    b = t * 6 + 0x1F4;
                    r->unkC = func_80042DA8() % a + a;
                    r->unkE = -(func_80042DA8() % b) - b;
                    r->unk10 = 0;
                    r->unk4 = func_80042DA8() & 0xFFF;
                    r->unk6 = (func_80042DA8() & 0x3F) + 0x80;
                    r->unk2 = 0;
                    r->unk8 = 0;
                }
            }
        }
        if (p->unk2 == 0x5B) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0D04(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DA778 = D_801BA778 + p->unk2 * 0x10000;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
    p->unk2 ^= 1;
}

INCLUDE_ASM("../asm/us/magic_iyashi/nonmatchings/text", func_801B0D64);
