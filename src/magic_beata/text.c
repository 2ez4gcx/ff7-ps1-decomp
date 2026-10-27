#include "common.h"
#include "magic_beata/decls.h"

void func_801B0054(void) {
    func_801B1184();
}

void func_801B0074(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s16 k;
    s32 c;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    k = p->unk10;
    scale.vy = scale.vz = k;
    scale.vz = scale.vx = (s16)(k / 3) + k;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    ((MgScratch *)0x1F800000)->unk0 = D_801C133C;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x2A) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0x2A) * 0x10;
    }
    D_801DAD30 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DAD30);
    if (p->unk2 >= 0x32) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk2++;
    }
}

void func_801B0238(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s16 k;
    s32 c;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    k = p->unk10;
    scale.vy = scale.vz = k;
    scale.vz = scale.vx = (s16)(k / 3) + k;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    c = 0x80;
    ((MgScratch *)0x1F800000)->unk0 = D_801C2130;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x2A) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0x2A) * 0x10;
    }
    D_801DAD30 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DAD30);
    if (p->unk2 >= 0x32) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_beata/nonmatchings/text", func_801B03FC);

s32 func_801B0620(BtScr2 *s) {
    s32 i;
    s32 j;
    s32 tx;
    s32 ty;
    s32 tz;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 cur;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    for (i = 0; i < 0x78; i++) {
        if (D_801DAD38[i].unk0 != 0) {
            tx = D_801DAD38[i].x;
            ty = D_801DAD38[i].y;
            tz = D_801DAD38[i].z;
            s->far = 0x7FFFFFFF;
            s->near = 0x7FFFFFFF;
            j = 0;
            do {
                cur = s->near;
                dx = tx - (s16)D_801C2C2C[j].x;
                dx = dx < 0 ? -dx : dx;
                dy = ty - (s16)D_801C2C2C[j].y;
                dy = dy < 0 ? -dy : dy;
                dz = tz - (s16)D_801C2C2C[j].z;
                dz = dz < 0 ? -dz : dz;
                dx = dx + dy + dz;
                if (dx < cur) {
                    if (cur < s->far) {
                        s->far = cur;
                        s->j2 = s->j1;
                    }
                    s->near = dx;
                    s->j1 = j;
                }
                j++;
            } while (j < 0x10);
            j = D_801DAD38[i].unk1C;
            dz = 0;
            if (D_80062D98 != 0) {
                dy = 0;
                dx = 0;
            } else {
                dx = D_801C2C34[s->j1].vx / j + (s16)(D_801C2C34[s->j2].vx >> 1) / j;
                dy = D_801C2C34[s->j1].vy / j + (s16)(D_801C2C34[s->j2].vy >> 1) / j;
                dz = D_801C2C34[s->j1].vz / j + (s16)(D_801C2C34[s->j2].vz >> 1) / j;
                D_801DAD38[i].unk0--;
            }
            s->vx = tx + dx;
            s->vy = ty + dy;
            s->vz = tz + dz;
            func_801B03FC(s, &s->vx, &D_801DAD38[i].x);
            D_801DAD38[i].x = s->vx;
            D_801DAD38[i].y = s->vy;
            D_801DAD38[i].z = s->vz;
        }
    }
    return s->pkt;
}

void func_801B0A04(void) {
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    s32 z;
    s32 nx;
    s32 ny;
    s32 nz;
    s32 c;
    s32 d;

    nx = 0x1F40;
    ny = 0xBB8;
    nz = 0x1F40;
    for (i = 0; i < 0x78; i++) {
        D_801DAD38[i].unk0 = 0;
        x = D_801DBC3C.vx + func_80042DA8() % nx - (nx >> 1);
        z = D_801DBC3C.vz + func_80042DA8() % nz - (nz >> 1);
        y = -(func_80042DA8() % ny);
        if (x > 0) {
            if (x < 0x320) {
                x += 0x320;
            }
        } else {
            if (x >= -0x31F) {
                x -= 0x320;
            }
        }
        if (z > 0) {
            if (z < 0x320) {
                z += 0x320;
            }
        } else {
            if (z >= -0x31F) {
                z -= 0x320;
            }
        }
        D_801DAD38[i].x = x;
        D_801DAD38[i].y = y;
        D_801DAD38[i].z = z;
        for (j = 0; j < 4; j++) {
            D_801DAD38[i].w[j] = 0;
        }
        d = x & 0xF;
        c = (z & 0xF) + 0x56;
        D_801DAD38[i].unk1C = d + c + ((y & 3) << 4);
    }
    for (i = 0; i < 0x10; i++) {
        D_801C2C2C[i].x += D_801DBC3C.vx;
        D_801C2C2C[i].y += D_801DBC3C.vy;
        D_801C2C2C[i].z += D_801DBC3C.vz;
    }
}

INCLUDE_ASM("../asm/us/magic_beata/nonmatchings/text", func_801B0C90);

void func_801B0E28(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 m;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            func_800D5138(0xA);
        }
        if (p->unk2 == 0xE) {
            func_800D51D4(0x24);
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0074)];
            *(BtB8 *)&q->unk4 = *(BtB8 *)&p->unk4;
            q->unkC = 0;
            q->unkE = -0x10;
            q->unk10 = (p->unk10 << 12) / 2200;
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0238)];
            *(BtB8 *)&q->unk4 = *(BtB8 *)&p->unk4;
            q->unk6 = -0x9C4;
            q->unkC = 0;
            q->unkE = -0xC;
            q->unk10 = (p->unk10 << 12) / 2400;
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0C90)];
            q->unk12 = 0;
            D_800F5B70 = D_800F5B71 = D_800F5B72 = 0;
        }
        if ((u16)(p->unk2 - 0xE) < 0x14) {
            D_801C2D2C = (p->unk2 - 0xE) * 0xCC;
            if (D_801C2D2C > 0x1000) {
                D_801C2D2C = 0x1000;
            }
        }
        if (p->unk2 >= 0x40) {
            D_801C2D2C = 0x1000 - (p->unk2 - 0x40) * 0x200;
            if (D_801C2D2C < 0) {
                D_801C2D2C = 0;
            }
        }
        if (p->unk2 == 0x3C) {
            i = 0;
            m = 1;
            for (; i < 10; i++) {
                if (D_801DBC38 & (m << i)) {
                    func_800D5774(i);
                }
            }
        }
        if (p->unk2 >= 0x48) {
            D_801C2D2C = 0;
            p->unk0 = -1;
        }
        D_800F5B74.v = D_801C2D2C;
        p->unk2++;
    }
}

void func_801B10DC(void) {
    MgTask *q;
    MgTask *b;

    D_80162978[D_8015169C].unk0 = -1;
    b = D_80162978;
    q = &b[func_800BBEAC((M2C_UNK *)func_801B0E28)];
    func_800D54EC(D_801DBC38, &q->unk4);
    q->unk10 = 0xF00;
    *(BtB8 *)&D_801DBC3C = *(BtB8 *)&q->unk4;
    func_801B0A04();
}

INCLUDE_RODATA("../asm/us/magic_beata/nonmatchings/text", D_801B0000);

void func_801B1184(arg0) {
    D_801DAD34 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B121C, 0, 0, 0);
    func_800BBEAC((M2C_UNK *)func_801B10DC);
    D_801DBC38 = arg0;
    func_800D55F4(0x20, func_800D574C(arg0), 0x8C);
}
