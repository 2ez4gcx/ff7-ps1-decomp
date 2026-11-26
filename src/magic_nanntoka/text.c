#include "common.h"
#include "magic_nanntoka/decls.h"

void func_801B006C(void) {
    func_801B2190();
}

void func_801B008C(arg0) {
    NnMove *q;
    MgTag *ot;
    u16 x;
    u16 xf;
    u16 y;
    u16 y2;

    q = D_801DBEF0;
    q[0].tag.len = 5;
    ((u8 *)&q[0])[7] = 1;
    q[1].tag.len = 5;
    ((u8 *)&q[1])[7] = 1;
    q[2].tag.len = 5;
    ((u8 *)&q[2])[7] = 1;
    q[3].tag.len = 5;
    ((u8 *)&q[3])[7] = 1;
    q[0].code = 0x80000000;
    q[1].code = 0x80000000;
    q[2].code = 0x80000000;
    q[3].code = 0x80000000;
    x = *(u16 *)(D_801517C0 + 0x5C);
    xf = x + 0xF0;
    q[0].sx = x;
    q[3].sx = xf;
    q[2].sx = xf;
    q[1].sx = xf;
    y = *(u16 *)(D_801517C0 + 0x5E);
    q[0].w = 0xF0;
    q[3].w = 0x50;
    q[2].w = 0x50;
    q[1].w = 0x50;
    q[1].sy = y;
    q[0].h = 0xA8;
    q[3].h = 0x38;
    q[2].h = 0x38;
    q[1].h = 0x38;
    q[0].sy = y;
    y2 = q[1].sy;
    q[2].sy = y2 + 0x38;
    q[3].sy = y2 + 0x70;
    q[1].dx = 0x300;
    q[0].dx = 0x300;
    q[2].dx = 0x350;
    q[3].dx = 0x3A0;
    q[3].dy = 0xA8;
    q[2].dy = 0xA8;
    q[1].dy = 0xA8;
    q[0].dy = 0;
    ot = (MgTag *)D_801517C0 + arg0;
    q[0].tag.addr = ot[0x1C].addr;
    ot[0x1C].addr = (u32)&q[0];
    q[1].tag.addr = ot[0x1C].addr;
    ot[0x1C].addr = (u32)&q[1];
    q[2].tag.addr = ot[0x1C].addr;
    ot[0x1C].addr = (u32)&q[2];
    q[3].tag.addr = ot[0x1C].addr;
    ot[0x1C].addr = (u32)&q[3];
    D_801DBEF0 = q + 4;
}

INCLUDE_ASM("../asm/us/magic_nanntoka/nonmatchings/text", func_801B0240);

INCLUDE_ASM("../asm/us/magic_nanntoka/nonmatchings/text", func_801B079C);

void func_801B0BF8(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_801B079C(0x1F800000);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0C74(void) {
    MgTask *p;
    NnPoly *q;
    s32 i;
    s32 x;
    s32 y;
    s32 u;
    s32 v;
    s32 t;

    x = 0;
    y = 0x140;
    i = 0;
    p = &D_80162978[D_8015169C];
    q = D_801DBEF0;
    u = D_801C3E94[p->unk2 * 2];
    v = D_801C3E98[p->unk2 * 2];
    do {
        t = (i * 7 / 10) << 8;
        *(s32 *)((u8 *)q + 0x10) = y;
        *(s32 *)((u8 *)q + 8) = x;
        *(s32 *)((u8 *)q + 0xC) = u + t;
        *(s32 *)((u8 *)q + 0x20) = y + 0x20000;
        *(s32 *)((u8 *)q + 0x18) = x + 0x20000;
        *(s32 *)((u8 *)q + 4) = 0x606060;
        x += 0x10000;
        y += 0x10000;
        *(s32 *)((u8 *)q + 0x14) = v + t;
        *(s32 *)((u8 *)q + 0x1C) = u + t + 0x10000;
        *(s32 *)((u8 *)q + 0x24) = v + t + 0x10000;
        q->tag.len = 9;
        ((u8 *)q)[7] = 0x2E;
        q->tag.addr = ((MgTag *)D_801517C0)[0x20].addr;
        ((MgTag *)D_801517C0)[0x20].addr = (u32)q;
        q++;
        i++;
    } while (i < 0xAA);
    D_801DBEF0 = q;
    if (p->unk2 >= 9) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0E10(void) {
    MgSVec rot;
    MgMat m;
    MgVec sc;
    MgTask *p;
    s16 t;

    rot.vx = 0x400;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unk14;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    sc.vx = sc.vy = sc.vz = p->unk1C;
    func_8003B35C(&m, &sc);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801C2294;
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801DBEF0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DBEF0);
    if (p->unk2 >= 0x87) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        t = p->unk4;
        if (t < 0) {
            p->unk4 = t + 2;
        }
        p->unk6 -= 3;
        p->unk8 += 0x50;
        if (p->unk2 < 0x3C) {
            p->unk14 += p->unk16;
        }
        p->unk2++;
    }
}

void func_801B0FAC(void) {
    MgSVec rot;
    MgMat m;
    MgVec sc;
    MgTask *p;
    void *tbl;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unk14;
    rot.vy = p->unk18;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    sc.vx = sc.vy = sc.vz = p->unk1C;
    func_8003B35C(&m, &sc);
    func_8003B48C(&m);
    func_8003B51C(&m);
    tbl = D_801C3EE4[p->unk1E];
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = tbl;
    D_801DBEF0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DBEF0);
    if (p->unk2 >= 0x41) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk14 += p->unk16;
        p->unk18 += p->unk1A;
        p->unk2++;
    }
}

void func_801B1154(void) {
    MgSVec rot;
    MgMat m;
    MgVec sc;
    MgTask *p;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unk10;
    rot.vz = p->unkC;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    sc.vx = sc.vy = sc.vz = p->unk14;
    func_8003B35C(&m, &sc);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801C3470;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x30;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801DBEF0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DBEF0);
    if (p->unk2 >= 0xC9) {
        p->unk0 = -1;
        if (D_801E2DEC != 0) {
            func_800BBEAC(func_801B0BF8);
            D_801E2DEC = 0;
            func_801B008C(6);
        }
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk10 += p->unk12;
        p->unk2++;
    }
}

void func_801B12F4(void) {
    MgSVec rot;
    MgMat m;
    MgVec sc;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = -0xAA;
    m.t[1] = -0x82;
    m.t[2] = 0x200;
    sc.vx = sc.vy = sc.vz = p->unk14;
    func_8003B35C(&m, &sc);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801C3244;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801DBEF0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DBEF0);
    if (p->unk2 >= 0x32) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x14) {
            p->unk14 += p->unk16;
        }
        if (p->unk2 == 0x1E) {
            p->unk16 = p->unk14 / 20;
        }
        if (p->unk2 >= 0x1F) {
            p->unk14 -= p->unk16;
        }
        p->unk2++;
    }
}

void func_801B14B8(void) {
    MgTask *p;
    MgTask *q;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        switch (p->unk1C) {
        case 0:
            q = &D_80162978[func_800BBEAC(func_801B12F4)];
            q->unk14 = 0;
            q->unk16 = 0xA3;
            p->unk1C++;
            break;
        case 1:
            if (p->unk2 == 0x17) {
                D_800F8380 |= 7;
                for (i = 0; i < 0xA; i++) {
                    D_80151909[i][0] |= 2;
                }
            }
            if (p->unk2 == 0x18) {
                q = &D_80162978[func_800BBEAC(func_801B1154)];
                q->unk4 = 0;
                q->unk6 = -0x474;
                q->unk8 = 0x4BC8;
                q->unkC = 0x100;
                q->unkE = 4;
                q->unk12 = 6;
                q->unk10 = 0;
                q->unk14 = 0xE66;
                q = &D_80162978[func_800BBEAC(func_801B1154)];
                q->unk6 = -0x460;
                q->unk8 = 0x4A9C;
                q->unkE = 3;
                q->unk4 = 0;
                q->unkC = 0;
                q->unk10 = 0;
                q->unk12 = 4;
                q->unk14 = 0xD99;
                p->unk1C++;
            }
            break;
        case 2:
            if (p->unk2 == 0x22) {
                q = &D_80162978[func_800BBEAC(func_801B0FAC)];
                q->unk4 = -0x514;
                q->unk6 = 0x64;
                q->unk8 = 0x7D0;
                q->unkC = 0x3F;
                q->unkE = -0xB;
                q->unk10 = -0x22;
                q->unk16 = 0x20;
                q->unk1A = 0x18;
                q->unk14 = 0;
                q->unk18 = 0;
                q->unk1C = 0x200;
                q->unk1E = 0;
            }
            if (p->unk2 == 0x23) {
                q = &D_80162978[func_800BBEAC(func_801B0FAC)];
                q->unk4 = -0x514;
                q->unk6 = -0x64;
                q->unk8 = 0x898;
                q->unkC = 0x34;
                q->unkE = 3;
                q->unk10 = -0x40;
                q->unk16 = 0x14;
                q->unk1A = 0x26;
                q->unk1C = 0x1F4;
                q->unk14 = 0;
                q->unk18 = 0;
                q->unk1E = 1;
            }
            if (p->unk2 == 0x25) {
                q = &D_80162978[func_800BBEAC(func_801B0FAC)];
                q->unk4 = 0x514;
                q->unk6 = 0x50;
                q->unk8 = 0x708;
                q->unkC = -0x27;
                q->unkE = -4;
                q->unk10 = -0x16;
                q->unk16 = 0x1C;
                q->unk1A = 0x24;
                q->unk1C = 0x199;
                q->unk14 = 0;
                q->unk18 = 0;
                q->unk1E = 2;
                p->unk1C++;
            }
            break;
        case 3:
            if (p->unk2 == 0x5A) {
                q = &D_80162978[func_800BBEAC(func_801B0E10)];
                q->unk4 = -0xC8;
                q->unk6 = -0x28;
                q->unk8 = 0x200;
                q->unk14 = -0x400;
                q->unk16 = 0x11;
                q->unk1C = 0xB60;
                p->unk1C++;
            }
            break;
        case 4:
            if (p->unk2 == 0xE1) {
                D_800F8380 &= 0xF8;
                for (i = 0; i < 0xA; i++) {
                    D_80151909[i][0] &= 0xFD;
                }
                p->unk1C++;
            }
            break;
        case 5:
            break;
        }
        if (p->unk2 == 0xFA) {
            for (i = 0; i < 0xA; i++) {
                if ((1 << i) & D_801E2DF0) {
                    func_800D5774(i);
                }
            }
        }
        if (p->unk2 >= 0xFF) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B192C(NnCtx2 *arg0, s32 arg1) {
    NnLine *p;
    NnPart *r;
    s32 *c;
    s32 i;
    s32 sc;
    s32 h;

    arg0->tm.m[2][2] = 0x1000;
    arg0->tm.m[1][1] = 0x1000;
    arg0->tm.m[0][0] = 0x1000;
    arg0->v[3].vy = -0x44C;
    arg0->tm.m[2][1] = 0;
    arg0->tm.m[2][0] = 0;
    arg0->tm.m[1][2] = 0;
    arg0->tm.m[1][0] = 0;
    arg0->tm.m[0][2] = 0;
    arg0->tm.m[0][1] = 0;
    arg0->tm.t[2] = 0;
    arg0->tm.t[1] = 0;
    arg0->tm.t[0] = 0;
    arg0->v[3].vx = 0;
    arg0->v[3].vz = 0x4E20;
    func_8003B48C(&arg0->tm);
    func_8003B51C(&arg0->tm);
    p = (NnLine *)D_801DBEF0;
    for (i = 0; i < 300; i++) {
        h = 0;
        r = &D_801E0EA8[i];
        c = &D_801E0EA8[i].col;
        if (D_801E0EA8[i].st != 0) {
            D_800D3544++;
            if (D_801E0EA8[i].st < 10) {
                if (D_80062D98 == 0) {
                    D_801E0EA8[i].x += D_801E0EA8[i].vx;
                    D_801E0EA8[i].y += D_801E0EA8[i].vy;
                    D_801E0EA8[i].z += D_801E0EA8[i].vz;
                    r->st = D_801E0EA8[i].st + 1;
                }
            } else {
                *(NnB8 *)&arg0->v[0] = *(NnB8 *)r;
                arg0->d[0] = arg0->v[3].vx - arg0->v[0].vx;
                arg0->d[1] = arg0->v[3].vy - arg0->v[0].vy;
                arg0->d[2] = arg0->v[3].vz - arg0->v[0].vz;
                gte_ldv0c(&arg0->v[0]);
                gte_rtps();
                sc = D_801E0EA8[i].sc;
                arg0->v[1].vx = arg0->v[0].vx + (sc * arg0->d[0] >> 12);
                arg0->v[1].vy = arg0->v[0].vy + (sc * arg0->d[1] >> 12);
                arg0->v[1].vz = arg0->v[0].vz + (sc * arg0->d[2] >> 12);
                gte_stsxy(&p->x0);
                gte_stflg(&arg0->flag);
                if ((u16)(p->x0 + 0x28) >= 0x191 || (u16)(p->y0 + 0x28) >= 0xF1 || (arg0->flag & 0x60000)) {
                    D_801E0EA8[i].st = 0;
                } else {
                    gte_ldv0c(&arg0->v[1]);
                    gte_rtps();
                    *(s32 *)((u8 *)p + 4) = *c;
                    *(s32 *)((u8 *)p + 0xC) = 0x10304;
                    if (D_80062D98 == 0) {
                        D_801E0EA8[i].x += D_801E0EA8[i].vx;
                        D_801E0EA8[i].y += D_801E0EA8[i].vy;
                        D_801E0EA8[i].z += D_801E0EA8[i].vz;
                        h = arg1 >> 1;
                        sc += (sc >> 5) + h;
                        D_801E0EA8[i].vz = D_801E0EA8[i].vz + (D_801E0EA8[i].vz >> 2) - h;
                    }
                    D_801E0EA8[i].sc = sc;
                    gte_stsxy(&p->xy1);
                    p->tag.len = 4;
                    *((u8 *)&p->rgbc + 3) = 0x52;
                    p->tag.addr = ((MgTag *)(D_801517C0 + 0x4060))->addr;
                    D_800D3546++;
                    ((MgTag *)(D_801517C0 + 0x4060))->addr = (u32)p;
                    p++;
                }
            }
        }
    }
    D_801DBEF0 = (NnPoly *)p;
}

void func_801B1D48(void) {
    u8 pad[8];
    s32 k;
    MgTask *p;
    s32 cnt;
    s32 i;
    s32 found;
    s32 t;
    s32 u;
    s32 d;
    s32 a;
    s32 r;
    s32 v;
    s32 sz;
    u8 *sc;

    p = &D_80162978[D_8015169C];
    func_801B192C(0x1F800000, p->unk2);
    do {
        sc = (u8 *)0x1F800000;
    } while (0);
    if (D_80062D98 == 0) {
        if ((u16)(p->unk2 - 0x1E) < 0xBA) {
            v = (s16)p->unk2;
            if (v < 0x64) {
                cnt = 7;
                sz = v;
            } else if (v < 0x8C) {
                cnt = 0xA;
                sz = v << 2;
            } else if (v < 0xA0) {
                cnt = 0xE;
                sz = v << 3;
            } else {
                cnt = 0x12;
                sz = v * 0x11;
            }
            do {
                k = 0;
            } while (0);
            if (cnt != 0) {
                d = 5460;
                do {
                    i = 0;
                    found = -1;
                    for (; i < 0x12C; i++) {
                        if (D_801E0EA8[i].st == 0) {
                            found = i;
                            break;
                        }
                    }
                    if (found < 0) {
                        break;
                    }
                    D_801E0EA8[found].y = -0x44C;
                    D_801E0EA8[found].z = 0x4E20;
                    D_801E0EA8[found].x = 0;
                    D_801E0EA8[found].st = 1;
                    *(s32 *)(sc + 0x240) = func_80042DA8() % d - 0xAAA;
                    *(s32 *)(sc + 0x244) = func_80042DA8() % d - 0xAAA;
                    r = func_80042DA8();
                    *(s32 *)(sc + 0x248) = r / 0x1000 * 0x1000 - r;
                    func_8003A08C((MgVec *)(sc + 0x240), (MgVec *)(sc + 0x240));
                    k++;
                    u = func_80042DA8();
                    a = p->unk2 + (p->unk2 >> 1);
                    t = u % 170 + 0x64;
                    a += t;
                    D_801E0EA8[found].vx = a * *(s32 *)(sc + 0x240) >> 12;
                    D_801E0EA8[found].vy = a * *(s32 *)(sc + 0x244) >> 12;
                    D_801E0EA8[found].vz = a * *(s32 *)(sc + 0x248) >> 12;
                    D_801E0EA8[found].sc = sz;
                    D_801E0EB8[found].r= (*(s32 *)(sc + 0x240) & 0x3F) + 0x48;
                    D_801E0EB8[found].g= (*(s32 *)(sc + 0x244) & 0x3F) + 0x4A;
                    D_801E0EB8[found].b= (*(s32 *)(sc + 0x248) & 0x3F) + 0x44;
                } while (k < cnt);
            }
        }
        if (p->unk2 >= 0xE1) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B20EC(void) {
    s32 i;

    for (i = 0x1F2C; i >= 0; i -= 0x14) {
        *(s16 *)(D_801E0EAE + i) = 0;
    }
}

void func_801B2114(void) {
    u8 pad[8];

    D_80162978[D_8015169C].unk0 = -1;
    D_80162978[func_800BBEAC(func_801B14B8)].unk1C = 0;
    func_800BBEAC(func_801B1D48);
    func_801B0240();
    func_801B20EC();
}

INCLUDE_RODATA("../asm/us/magic_nanntoka/nonmatchings/text", D_801B0018);

s32 func_801B2190(arg0) {
    D_801DBEF4 = &D_80162978[func_800BBEAC(D_801B0018)];
    func_800D2980(&D_801B2234, 0, 0, 0);
    func_800BBEAC(func_801B2114);
    D_801E2DF0 = arg0;
    D_801E2DEC = 1;
    D_801E2DE8 = 1;
    return func_800D55F4(0x21, 0x40, 0x127, 0x128);
}
