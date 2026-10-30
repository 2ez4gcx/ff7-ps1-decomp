#include "common.h"
#include "magic_h_blow/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B11B4();
    return &D_801C2B3C;
}

void func_801B0028(void) {
    MgTask *p;
    MgMat *mp;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 >= 0) {
        if (p->unk2 >= 0xF) {
            p->unk0 = -1;
            return;
        }
        D_801C3452 = (p->unk2 << 12) / 15;
    }
    if (p->unk2 < 0xF) {
        k = ((p->unk2 << 12) / 15 << 9) >> 12;
    }
    func_8003C21C((MgSVec *)&p->unkC, &D_801C3458->m);
    D_801C3458->m.t[0] = p->unk4;
    D_801C3458->m.t[1] = p->unk6;
    D_801C3458->m.t[2] = p->unk8;
    D_801C3458->sc.vx = D_801C3458->sc.vy = D_801C3458->sc.vz = k;
    func_8003B35C(&D_801C3458->m, &D_801C3458->sc);
    mp = &D_801C3458->m;
    func_8003A63C(&D_801E34EC, mp, mp);
    func_8003B48C(&D_801C3458->m);
    func_8003B51C(&D_801C3458->m);
    func_8003B69C(0, 0, 0);
    D_801E34B8 = func_800D29D4(D_801C3448, D_801517C0 + 0x70, 0xC, D_801E34B8);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk10 += 0x20;
    }
}

void func_801B01E0(void) {
    MgTask *p;
    MgMat *mp;
    s32 k;
    s32 q;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 >= 0) {
        if (p->unk2 >= 0xA) {
            p->unk0 = -1;
            return;
        }
        q = (p->unk2 << 12) / 10;
        D_801C3466 = q;
    }
    if (p->unk2 < 0xA) {
        q = (p->unk2 << 12) / 10;
        for (k = 0; k < 2; k++) {
            q = func_80039A74(q / 4);
        }
        k = p->unk1C * q >> 12;
    }
    func_8003C21C((MgSVec *)&p->unkC, &D_801C346C->m);
    D_801C346C->m.t[0] = p->unk4;
    D_801C346C->m.t[1] = p->unk6;
    D_801C346C->m.t[2] = p->unk8;
    D_801C346C->sc.vx = D_801C346C->sc.vy = D_801C346C->sc.vz = k;
    func_8003B35C(&D_801C346C->m, &D_801C346C->sc);
    mp = &D_801C346C->m;
    func_8003A63C(&D_801E34EC, mp, mp);
    func_8003B48C(&D_801C346C->m);
    func_8003B51C(&D_801C346C->m);
    func_8003B69C(0, 0, 0);
    D_801E34B8 = func_800D29D4(D_801C345C, D_801517C0 + 0x70, 0xC, D_801E34B8);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B03C0(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s16 n;

    b = (MgTask *)D_80162978;
    p = &b[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 % 3 == 0) {
            q = &b[func_800BBEAC(&func_801B01E0)];
            q->unk4 = 0;
            q->unk6 = -0x1F4;
            q->unk8 = -(p->unk0 * 0x12C) - 0x1F4;
            q->unk10 = 0;
            q->unkE = 0;
            q->unkC = 0;
            q->unk1C = 0x200;
            n = p->unk0 + 1;
            p->unk0 = n;
            if (n >= 3) {
                p->unk0 = -1;
            }
        }
        p->unk2++;
    }
}

void func_801B04DC(void) {
    MgTask *p;
    MgMat *mp;
    u16 *frame;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    D_801C347C->rot.vx = p->unkC;
    D_801C347C->rot.vy = 0;
    D_801C347C->rot.vz = 0;
    func_8003C21C(&D_801C347C->rot, &D_801C347C->m);
    func_8003CA7C(p->unk10, &D_801C347C->m);
    D_801C347C->m.t[0] = p->unk4;
    D_801C347C->m.t[1] = p->unk6;
    D_801C347C->m.t[2] = p->unk8;
    D_801C347C->sc.vx = D_801C347C->sc.vy = D_801C347C->sc.vz = p->unk1C;
    func_8003B35C(&D_801C347C->m, &D_801C347C->sc);
    mp = &D_801C347C->m;
    func_8003A63C(&D_801E34EC, mp, mp);
    func_8003B48C(&D_801C347C->m);
    func_8003B51C(&D_801C347C->m);
    frame = &D_801C3478;
    *frame = p->unk2;
    D_801E34B8 = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801E34B8);
    if (D_80062D98 == 0) {
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n >= D_801C2890[0]) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_h_blow/nonmatchings/text", func_801B0640);

void func_801B078C(void) {
    MgTask *p;
    s32 k;
    s32 a;
    u8 pad[8];
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0x14) {
            D_801518EA[D_801E34BC][0] = p->unk1C;
            *(MgB8 *)D_80151A4C[D_801E34BC] = D_801E34C4;
            a = D_801E34BC;
            D_80151909[a][0] = D_801E350C;
            D_80151A48[a][0] = 0;
            func_800B8E48(D_801E34BC);
            p->unk0 = -1;
            return;
        }
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkE += 0x1E;
        D_80151A48[D_801E34BC][0] += 0x200;
    }
    D_801C34B0->rot.vx = p->unk14;
    D_801C34B0->rot.vy = p->unk16;
    D_801C34B0->rot.vz = p->unk18;
    func_8003C21C((MgSVec *)D_80151A44[D_801E34BC], &D_801C34B0->m);
    func_8003B2CC(&D_801C34B0->m, &D_801C34B0->rot, &D_801C34B0->rot);
    D_80151A4C[D_801E34BC][0] = p->unk4 - D_801C34B0->rot.vx + p->unk14;
    D_80151A4C[D_801E34BC][1] = p->unk6 - D_801C34B0->rot.vy + p->unk16;
    D_80151A50[D_801E34BC][0] = p->unk8 - D_801C34B0->rot.vz + p->unk18;
    k = p->unk1C + (-p->unk1C * p->unk2) / 20;
    D_801518EA[D_801E34BC][0] = k;
    D_801C3490.m[0][0] = D_801518EC[D_801E34BC][0] * (s16)k >> 12;
    D_801C3490.m[2][2] = D_801518EC[D_801E34BC][1] * (s16)D_801518EA[D_801E34BC][0] >> 12;
    D_801C3490.t[0] = p->unk4;
    D_801C3490.t[1] = 0;
    D_801C3490.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801C3490, &D_801C34B0->m);
    func_8003B48C(&D_801C34B0->m);
    func_8003B51C(&D_801C34B0->m);
    D_801E34B8 = func_800D29D4(D_801C3480, D_801517C0 + 0x4078, 0, D_801E34B8);
}

void func_801B0BAC(void) {
    MgSVec v;
    MgTask *p;
    MgTask *q;
    u8 *ab;
    u8 *pb;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801E34CC, &D_801E34EC);
    if (D_80062D98 == 0) {
        if (p->unk2 == 0xF) {
            ab = D_80151A24;
            func_8003C21C((MgSVec *)((s32)ab + D_801E34C0 * 0xB9C + 0x20), &D_801E34CC);
            func_800D3994(D_801E34C0, D_8015190F[D_801E34C0][0], D_801C34B4);
            D_801E34E0.vx = D_801C34B4->vx;
            D_801E34E0.vy = 0;
            D_801E34E0.vz = D_801C34B4->vz;
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0028)];
            q->unk4 = 0;
            q->unk6 = -0x1F4;
            q->unk8 = -0x1F4;
            q->unk10 = 0;
            q->unkE = 0;
            q->unkC = 0;
            func_800D55F4(0x20, func_800D56A8(D_801C34B4), 0x163);
        }
        if (p->unk2 == 0xF) {
            func_800BBEAC(&func_801B0640);
        }
        if (p->unk2 == 0xF) {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B03C0)];
            q->unk0 = 0;
        }
        if (p->unk2 == 0xF) {
            if ((D_80161DE8 >> D_801E34BC) & 1) {
                func_800D3994(D_801E34BC, D_8015190F[D_801E34BC][0], &v);
                pb = ab + 0x28;
                D_801E34C4 = *(MgB8 *)((s32)pb + D_801E34BC * 0xB9C);
                q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B078C)];
                *(MgB8 *)&q->unk4 = *(MgB8 *)((s32)pb + D_801E34BC * 0xB9C);
                q->unkC = -(func_80039A74(D_80151A44[D_801E34C0][1]) * 500) >> 12;
                q->unkE = -0x1F4;
                q->unk10 = -(func_80039B40(D_80151A44[D_801E34C0][1]) * 500) >> 12;
                q->unk14 = func_80039A74(D_80151A44[D_801E34BC][1]) * (v.vx - D_80151A4C[D_801E34BC][0]) >> 12;
                q->unk16 = v.vy - D_80151A4C[D_801E34BC][1];
                q->unk18 = func_80039B40(D_80151A44[D_801E34BC][1]) * (v.vz - D_80151A50[D_801E34BC][0]) >> 12;
                q->unk1C = D_801518EA[D_801E34BC][0];
                D_801E350C = D_80151909[D_801E34BC][0];
                D_80151909[D_801E34BC][0] |= 0x10;
            } else {
                func_800D5774();
            }
        }
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B111C(s32 arg0, s32 arg1) {
    D_801E34BC = arg0;
    D_801E34C0 = arg1;
    func_800BBEAC(&func_801B0BAC);
}

void func_801B1154(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E34B8 = D_801C34B8 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B11B4(arg0, arg1) {
    func_800D2980(&D_801B1224, 0, 0, 0);
    func_800BBEAC(&func_801B1154);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B111C);
}
