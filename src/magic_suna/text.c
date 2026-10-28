#include "common.h"
#include "magic_suna/decls.h"

void func_801B006C(void) {
    MgTask *p;
    u16 *frame;
    s32 **q;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1000, 0);
    frame = &D_801BA5F0;
    q = (s32 **)((u8 *)frame - 8);
    M2C_SFIELD(frame, u16 *, 0) = p->unk2;
    *q = D_801BA5F4[p->unk16];
    D_801D2C6C = (u8 *)func_800D4D90(q, D_801517C0 + 0x70, 0xC, (s32)D_801D2C6C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801BA5F4[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

MgObj8 *func_801B0160(void) {
    s16 i;

    for (i = 0; i < 200; i++) {
        if (D_801BA628[i].unk0 == 0) {
            D_801BA628[i].unk0 = 1;
            D_801BA628[i].unk6 = 0;
            return &D_801BA628[i];
        }
    }
    return NULL;
}

void func_801B01E0(MgTask *p) {
    MgSVec rot;
    MgSVec pt;
    MgMat m;
    s32 ext;
    s32 flag;
    u8 *q;
    s16 i;
    s16 k;
    s32 r;
    s32 t;

    rot.vx = rot.vz = 0;
    rot.vy = p->unk14;
    func_8003C21C(&rot, &m);
    m.t[0] = m.t[1] = m.t[2] = 0;
    for (i = 0; i < 200; i++) {
        if (D_801BA628[i].unk0 != 0) {
            pt.vx = ((func_80039B40(D_801BA628[i].unk4) * D_801BA628[i].unk2 * D_801BA628[i].unk6) / 20 * (p->unk1A + 0x100)) >> 20;
            pt.vy = ((func_80039A74(D_801BA628[i].unk4) * D_801BA628[i].unk2 * D_801BA628[i].unk6) / 20 * (p->unk1A + 0x100)) >> 20;
            pt.vz = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&pt, &pt, &ext);
            pt.vx += p->unk4 + p->unkC * D_801BA628[i].unk6;
            pt.vy += p->unk6 + p->unkE * D_801BA628[i].unk6;
            pt.vz += p->unk8 + p->unk10 * D_801BA628[i].unk6;
            func_8003B48C(&D_800FA63C);
            func_8003B51C(&D_800FA63C);
            q = D_801D2C6C;
            func_80046974(q);
            q[7] = 0x6A;
            r = func_8003BBDC(&pt, q + 8, &flag, &ext);
            if (D_801BA628[i].unk6 >= 0x11) {
                k = 0x19 - D_801BA628[i].unk6;
            } else {
                k = 8;
            }
            q[4] = k * 0x10;
            q[5] = k * 0x10;
            q[6] = 0;
            t = (r >> 2) * 4 + 0x70;
            func_80046794(t + D_801517C0, q);
            D_801D2C6C = q + 0xC;
        }
    }
}

void func_801B052C(void) {
    MgTask *p;
    MgObj8 *q;
    s16 i;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B01E0(p);
    if (D_80062D98 == 0) {
        p->unk1A += 8;
        if ((u16)(p->unk2 - 1) < 0x27U) {
            for (i = 0; i < 8; i++) {
                q = func_801B0160();
                if (q != NULL) {
                    q->unk2 = func_80042DA8() % 0x200;
                    q->unk4 = func_80042DA8() & 0xFFF;
                }
            }
        }
        for (i = 0, n = 0; i < 200; i++) {
            if (D_801BA628[i].unk0 != 0) {
                D_801BA628[i].unk4 -= 0x80;
                n++;
                if (++D_801BA628[i].unk6 == 0x19) {
                    D_801BA628[i].unk0 = 0;
                }
            }
        }
        if (++p->unk2 >= 0x29 && n == 0) {
            p->unk0 = -1;
        }
    }
}

void func_801B06FC(void) {
    MgMat m;
    MgMat lw;
    MgTask *p;
    s16 *frame;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    p->unkC = -p->unk2 << 7;
    func_8003C21C((MgSVec *)&p->unkC, &m);
    D_801BA60C[0] = p->unk18;
    t = (p->unk1A + 0x100) * 0x1A;
    D_801BA610 = t;
    D_801BA60C[-1] = t;
    func_8003B35C(&m, (MgVec *)&D_801BA60C[-1]);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    frame = &D_801BA622;
    *frame = D_801BA604 * 0x10;
    D_801D2C6C = func_800D29D4((u8 *)frame - 0xA, D_801517C0 + 0x70, 0xC, D_801D2C6C);
    if (D_80062D98 == 0) {
        p->unk1A += 8;
        if (p->unk2 < 8) {
            D_801BA604 += 1;
        }
        if (p->unk2 >= 0x2E) {
            D_801BA604 -= 1;
        }
        if (++p->unk2 == 0x35) {
            p->unk0 = -1;
        }
    }
}

void func_801B08AC(void) {
    MgSVec v;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 j;
    s16 d;
    s16 a;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            a = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B052C)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unkC = (p->unkC - p->unk4) / 20;
            q->unkE = 0;
            q->unk10 = (p->unk10 - p->unk8) / 20;
            q->unk1A = 0;
            q->unk14 = a;
            q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B06FC)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unk10 = 0x400;
            q->unkE = a - 0x400;
            v.vx = p->unkC - p->unk4;
            v.vz = p->unk10 - p->unk8;
            d = func_80039F5C(v.vx * v.vx + v.vz * v.vz);
            q->unk1A = 0;
            q->unk18 = d * 0x1500 / 2800;
        }
        if (p->unk2 == 0x23) {
            for (i = 0; i < 10; i++) {
                if ((D_801BAC68 >> i) & 1) {
                    func_800D5774(i);
                }
            }
        }
        if ((u16)(p->unk2 - 0x20) < 7U) {
            for (i = 0; i < 10; i++) {
                if ((D_801BAC68 >> i) & 1) {
                    j = 0;
                    do {
                        q = (MgTask *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B006C)];
                        func_800D3994(i, D_8015190F[i][0], &q->unk4);
                        q->unk4 += func_80042DA8() % 1000 - 500;
                        q->unk6 += func_80042DA8() % 1000 - 500;
                        q->unk8 += func_80042DA8() % 1000 - 500;
                        q->unk16 = func_80042DA8() & 3;
                    } while (++j < 2);
                }
            }
        }
        p->unk2++;
        if (p->unk2 == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B0CD4(void) {
}

INCLUDE_RODATA("../asm/us/magic_suna/nonmatchings/text", D_801B0000);

void func_801B0CDC(s32 arg0, s32 arg1) {
    MgTask *p;
    s16 i;

    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B1248, 0, 0, 0);
    func_800D2980(&D_801B9288, 0, 0, 0);
    for (i = 0; i < 200; i++) {
        D_801BA628[i].unk0 = 0;
    }
    D_801BAC68 = arg0;
    p = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B08AC)];
    func_800D3994(arg1, D_80151917[arg1][0], &p->unk4);
    func_800D54EC(arg0, &p->unkC);
    func_800BBA84(0x69, arg1, 0x40);
}
