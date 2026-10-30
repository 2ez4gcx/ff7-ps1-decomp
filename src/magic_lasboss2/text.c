#include "common.h"
#include "magic_lasboss2/decls.h"

void func_801B0000(void) {
    func_801B1834();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E5EE8 = D_801CDEE8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

MgMat *func_801B008C(MgSVec *pos, MgSVec *rot, s16 s) {
    MgVec scale;

    func_8003C21C(rot, &D_801CD6F8);
    scale.vx = scale.vy = scale.vz = s;
    func_8003B35C(&D_801CD6F8, &scale);
    D_801CD70C[0] = pos->vx;
    D_801CD710[0] = pos->vy;
    D_801CD714[0] = pos->vz;
    func_8003B48C(&D_801CD6F8);
    func_8003B51C(&D_801CD6F8);
    return &D_801CD6F8;
}

void func_801B013C(void) {
    MgObj20 *p;
    u8 c;

    p = &D_80162978[D_8015169C];
    func_801B008C((MgSVec *)&p->unk4, &D_801CD5D8, 0x1000);
    c = p->pad[0x12] * 8;
    D_801CD5D2 = c;
    D_801CD5D1 = c;
    D_801CD5D0[0] = c;
    *(s32 *)&D_801CD5D0[-4] = D_801CD5E0[*(s16 *)((u8 *)p + 0x14)];
    D_801E5EE8 = func_800D4D90((s32 *)&D_801CD5D0[-4], D_801517C0 + 0x70, 0xC, D_801E5EE8);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x10) {
            *(s16 *)((u8 *)p + 0x1A) += 1;
        }
        p->unk2++;
        if (p->unk2 == 0xBE) {
            p->unk0 = -1;
        }
    }
}

void func_801B0248(void) {
    MgObj20 *p;
    s16 *frame;

    p = &D_80162978[D_8015169C];
    func_801B008C((MgSVec *)&p->unk4, &D_801CD5E8, p->unk2 * 0x3E8);
    func_8003B69C(0, 0, 0);
    frame = &D_801CD5FA;
    *frame = p->unk2 * 0x111;
    D_801E5EE8 = func_800D29D4(frame - 5, D_801517C0 + 0x70, 0xC, D_801E5EE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B0338(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    func_801B008C((MgSVec *)&p->unk4, &D_801CD600, func_80039A74(p->unk2 * 0x22) << 14 >> 16);
    func_8003B69C(0, 0, 0);
    D_801E5EE8 = func_800D29D4(D_801CD608, D_801517C0 + 0x70, 0xC, D_801E5EE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0410(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    func_801B008C((MgSVec *)&p->unk4, &D_801CD624, 0x800 - p->unk2 * 0x88);
    D_801CD618[0] = D_801CD62C[*(s16 *)((u8 *)p + 0x14)];
    D_801E5EE8 = func_800D4D90(D_801CD618, D_801517C0 + 0x70, 0xC, D_801E5EE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B04F4(void) {
    MgObj20 *p;
    s16 *frame;

    p = &D_80162978[D_8015169C];
    func_801B008C((MgSVec *)&p->unk4, &D_801CD634, *(s16 *)((u8 *)p + 0x18));
    func_8003B69C(0, 0, 0);
    frame = &D_801CD646;
    *frame = *(s16 *)((u8 *)p + 0x1A) * 0x200;
    D_801E5EE8 = func_800D29D4(frame - 5, D_801517C0 + 0x70, 0xC, D_801E5EE8);
    if (D_80062D98 == 0) {
        if (p->unk2 < 8) {
            *(s16 *)((u8 *)p + 0x18) += 0x80;
        }
        if (p->unk2 >= 8) {
            *(s16 *)((u8 *)p + 0x1A) += 1;
        }
        p->unk2++;
        if (p->unk2 == 0x10) {
            p->unk0 = -1;
        }
    }
}

void func_801B05FC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    func_801B008C((MgSVec *)&p->unk4, &D_801CD64C, *(s16 *)((u8 *)p + 0x18));
    func_8003B69C(0, 0, 0);
    D_801E5EE8 = func_800D29D4(D_801CD654, D_801517C0 + 0x70, 0xC, D_801E5EE8);
    if (D_80062D98 == 0) {
        if (p->unk2 < 8) {
            *(s16 *)((u8 *)p + 0x18) += 0x100;
        }
        p->unk2++;
        if (p->unk2 == 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B06DC(void) {
    MgObj20 *p;
    s16 k;
    u8 *r;

    p = &D_80162978[D_8015169C];
    func_801B008C((MgSVec *)&p->unk4, &D_801CD664, *(s16 *)((u8 *)p + 0x18));
    func_8003B69C(0, 0, 0);
    r = func_800D29D4(D_801CD66C, D_801517C0 + 0x70, 0xC, D_801E5EE8);
    k = *(s16 *)((u8 *)p + 0x18) / 65;
    D_801E5EE8 = r;
    D_80163C74 = func_800C4FC8(k, k, k);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x10) {
            *(s16 *)((u8 *)p + 0x18) += 0x400;
        }
        if (p->unk2 >= 0x20) {
            *(s16 *)((u8 *)p + 0x18) -= 0x200;
        }
        p->unk2++;
        if (p->unk2 == 0x40) {
            p->unk0 = -1;
        }
    }
}

void func_801B0824(void) {
    MgObj20 *p;
    s16 *rz;
    u8 *col;
    u8 c;

    p = &D_80162978[D_8015169C];
    rz = &D_801CD68C;
    *rz = *(u16 *)&p->unk2 * *(u16 *)((u8 *)p + 0x14) + *(s16 *)((u8 *)p + 0x14) * 0x300;
    func_801B008C((MgSVec *)&p->unk4, (MgSVec *)(rz - 2), 0x2000);
    col = &D_801CD680;
    c = *(s16 *)((u8 *)p + 0x1A) * 4;
    D_801CD682 = c;
    D_801CD681 = c;
    *col = c;
    D_801E5EE8 = func_800D4D90((s32 *)(col - 4), D_801517C0 + 0x70, 0xC, D_801E5EE8);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x10) {
            *(s16 *)((u8 *)p + 0x1A) += 1;
        }
        p->unk2++;
        if (p->unk2 == 0xA0) {
            p->unk0 = -1;
        }
    }
}

void func_801B0948(void) {
    MgObj20 *p;
    u8 *col;
    u8 c;

    p = &D_80162978[D_8015169C];
    func_801B008C((MgSVec *)&p->unk4, &D_801CD69C, 0x2000);
    col = &D_801CD694;
    c = p->pad[0x12];
    D_801CD696 = c;
    D_801CD695 = c;
    *col = c;
    D_801E5EE8 = func_800D4D90((s32 *)(col - 4), D_801517C0 + 0x70, 0xC, D_801E5EE8);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x58) {
            *(s16 *)((u8 *)p + 0x1A) -= 2;
        }
        p->unk2++;
        if (p->unk2 == 0x78) {
            p->unk0 = -1;
        }
    }
}

void func_801B0A34(void) {
    MgObj20 *p;
    s16 *rz;
    u8 *col;
    u8 c;

    p = &D_80162978[D_8015169C];
    rz = &D_801CD6B4;
    *rz = -p->unk2 * 6;
    func_801B008C((MgSVec *)&p->unk4, (MgSVec *)(rz - 2), 0x3000);
    col = &D_801CD6A8;
    c = p->pad[0x12];
    D_801CD6AA = c;
    D_801CD6A9 = c;
    *col = c;
    D_801E5EE8 = func_800D4D90((s32 *)(col - 4), D_801517C0 + 0x70, 0xC, D_801E5EE8);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x58) {
            *(s16 *)((u8 *)p + 0x1A) -= 2;
        }
        p->unk2++;
        if (p->unk2 == 0x78) {
            p->unk0 = -1;
        }
    }
}

void func_801B0B3C(void) {
    MgObj20 *p;
    u8 *col;
    u8 c;

    p = &D_80162978[D_8015169C];
    func_801B008C((MgSVec *)&p->unk4, &D_801CD6C4, 0x1800);
    col = &D_801CD6BC;
    c = p->pad[0x12];
    D_801CD6BE = c;
    D_801CD6BD = c;
    *col = c;
    D_801E5EE8 = func_800D4D90((s32 *)(col - 4), D_801517C0 + 0x70, 0xC, D_801E5EE8);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x58) {
            *(s16 *)((u8 *)p + 0x1A) -= 4;
        }
        p->unk2++;
        if (p->unk2 == 0x78) {
            p->unk0 = -1;
        }
    }
}

void func_801B0C28(void) {
    s16 i;
    s32 o;
    s32 r;

    for (i = 0; i < 100; i++) {
        o = i * 0x14;
        if (*(s16 *)(D_801CD718 + o) == 0) {
            func_80042DA8();
            *(s16 *)(D_801CD718 + o) = 1;
            *(s16 *)(D_801CD718 + o + 2) = 0;
            *(s16 *)(D_801CD71C + o) = func_80042DA8() % 3000 - 0x5DC;
            r = func_80042DA8();
            *(s16 *)(D_801CD720 + o) = 0x2EE0;
            *(s16 *)(D_801CD71C + o + 2) = r % 3000 - 0x5DC;
            return;
        }
    }
}

void func_801B0D8C(void) {
    MgObj20 *p;
    s16 i;
    s32 o;
    s32 o2;
    u8 *prim;
    s32 depth;
    s32 t;
    s32 ox;
    s32 oy;
    s32 sx;
    s32 sy;

    p = &D_80162978[D_8015169C];
    func_8003B64C(&ox, &oy);
    func_8003B6BC(0xA0, 0x5A);
    func_8003B48C(&D_801CD6CC);
    func_8003B51C(&D_801CD6CC);
    for (i = 0; i < 100; i++) {
        o = i * 0x14;
        if (((Lb2Rec *)(D_801CD718 + o))->flag == 1) {
            prim = D_801E5EE8;
            depth = func_8003BBDC(D_801CD71C + o, prim + 8, &sx, &sy);
            if (depth > 0) {
                func_80046974(prim);
                func_80046848(prim, 1);
                prim[4] = prim[5] = prim[6] = p->pad[0x12];
                t = (depth >> 2) * 4 + 0x70;
                func_80046794(t + D_801517C0, prim);
                D_801E5EE8 = prim + 0xC;
            }
        }
    }
    func_8003B6BC(ox, oy);
    if (D_80062D98 == 0) {
        for (i = 0; i < 4; i++) {
            func_801B0C28();
        }
        for (i = 0; i < 100; i++) {
            o2 = i * 0x14;
            if (((Lb2Rec *)(D_801CD718 + o2))->flag != 0) {
                ((Lb2Rec *)(D_801CD718 + o2))->vz -= 0x190;
                if (++((Lb2Rec *)(D_801CD718 + o2))->frame == 0x1E) {
                    ((Lb2Rec *)(D_801CD718 + o2))->flag = 0;
                }
            }
        }
        if (p->unk2 >= 0x58) {
            *(s16 *)((u8 *)p + 0x1A) -= 4;
        }
        p->unk2++;
        if (p->unk2 == 0x78) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_lasboss2/nonmatchings/text", func_801B1024);

void func_801B1834(arg0, arg1) {
    MgObj20 *p;
    s16 i;
    s32 o;

    func_800BBEAC(func_801B0020);
    D_801E5F00 = arg0;
    func_800D2980(D_801B19FC, 0, 0, 0);
    p = &D_80162978[func_800BBEAC(func_801B1024)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D54EC(arg0, &p->pad[4]);
    D_800F5B70 = D_800F5B71 = D_800F5B72 = 0;
    func_800D52A0(0x1000, 0x10);
    i = 0;
    do {
        D_80151922[i][0] |= 2;
        i++;
    } while (i < 10);
    i = 0;
    do {
        o = i * 0x14;
        *(s16 *)(D_801CD718 + o) = 0;
        i++;
    } while (i < 100);
    D_8009A000 = 0x29;
    D_8009A004 = 0x40;
    D_8009A008 = 0x28C;
    func_8002DA7C();
    D_800FAFDC = 1;
}
