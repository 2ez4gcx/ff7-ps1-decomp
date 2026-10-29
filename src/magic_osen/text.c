#include "common.h"
#include "magic_osen/decls.h"

void func_801B0000(void) {
    func_801B100C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EAD48 = D_801D2D48 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgObj20 *p;
    MgMat *m;
    s32 z;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    m =func_800D4368(&p->unk4, 0x2000, 0);
    z = m->t[2];
    if (z > 0) {
        func_800D4484(*(s32 *)(((z >> 4) * 4) + D_801517C0 + 0x70), 0x20);
        frame = &D_801D2CD8;
        *frame = p->unk2;
        D_801EAD48 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EAD48);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D27BC) {
            p->unk0 = -1;
        }
    }
}

void func_801B0174(void) {
    MgObj20 *p;
    u16 *frame;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x1000, 0);
    frame = &D_801D2CE4;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D2944) {
            p->unk0 = -1;
        }
    }
}

MgMat *func_801B022C(MgSVec *pos, MgSVec *rot, s16 s) {
    MgVec scale;

    func_8003C21C(rot, &D_801D2D28);
    scale.vx = scale.vy = scale.vz = s;
    func_8003B35C(&D_801D2D28, &scale);
    D_801D2D3C[0] = pos->vx;
    D_801D2D40[0] = pos->vy;
    D_801D2D44[0] = pos->vz;
    func_8003B48C(&D_801D2D28);
    func_8003B51C(&D_801D2D28);
    return &D_801D2D28;
}

void func_801B02DC(void) {
    MgTask *p;
    s8 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B022C((MgSVec *)&p->unk4, (MgSVec *)&p->unkC, 0x1000);
    c = D_801D2CF4 * 6;
    D_801D2CEE = c;
    D_801D2CED = c;
    D_801D2CEC[0] = c;
    D_801EAD48 = (u8 *)func_800D4D90(&D_801D2CEC[-4], D_801517C0 + 0x70, 0xC, (s32)D_801EAD48);
    if (D_80062D98 == 0) {
        p->unk10 += 0x10;
        if (p->unk2 < 0x10) {
            D_801D2CF4++;
        }
        if (p->unk2 >= 0x2D) {
            D_801D2CF4--;
        }
        p->unk2++;
        if (p->unk2 == 0x3C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B040C);

void func_801B0718(void) {
    MgTask *p;
    MgMat *m;
    s16 *q;
    s32 z;
    s16 k;
    s16 c;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (p->unk2 >= 0x1B) {
        k = 0x23 - p->unk2;
    } else {
        k = 8;
    }
    q = &p->unk4;
    m = func_800D4368(q, 0x1800, 0);
    z = m->t[2];
    if (z > 0) {
        func_800D4484(*(s32 *)(((z >> 4) * 4) + D_801517C0 + 0x70), 0x20);
        func_801B040C(8, p->unk1A, 0x320, k * 4);
    }
    func_800D4368(q, 0x1800, 0);
    D_801D2D00[0] = p->unk2 % D_801D2A0C;
    c = k * 0xC;
    D_801D2CFC[0] = D_801D2CFC[1] = D_801D2CFC[2] = c;
    D_801EAD48 = (u8 *)func_800D4D90(&D_801D2D00[-4], D_801517C0 + 0x70, 0xC, (s32)D_801EAD48);
    p->unk1A += 0x100;
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        n = p->unk2 + 1;
        p->unk8 += p->unk10;
        p->unk2 = n;
        if (n == 0x23) {
            p->unk0 = -1;
        }
    }
}

void func_801B08F0(void) {
    MgMat m;
    u8 pad[0x20];
    MgSVec rot;
    s32 ox;
    s32 oy;
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    func_8003B64C(&ox, &oy);
    func_8003B6BC(0xA0, 0x64);
    D_801D2D0C[0] = p->unk2 * 0x12C + 0x2000;
    rot.vx = 0x400;
    rot.vy = (u16)p->unk2 * 0x10;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    func_8003B35C(&m, (MgVec *)&D_801D2D0C[-1]);
    m.t[0] = 0;
    m.t[1] = 0;
    m.t[2] = 0x1F40;
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801D2D22[0] = D_801D2D04 * 0x10;
    D_801EAD48 = func_800D29D4(&D_801D2D22[-5], D_801517C0 + 0x70, 0xC, D_801EAD48);
    func_8003B6BC(ox, oy);
    if (D_80062D98 == 0) {
        if (p->unk2 < 8) {
            D_801D2D04 += 1;
        }
        if (p->unk2 >= 0x2B) {
            D_801D2D04 -= 1;
        }
        if (++p->unk2 == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B0AA0(void) {
    MgSVec v;
    MgSVec rot;
    MgMat m;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 i;
    s32 ang;
    s32 k;
    s16 t;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 0xC) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B0718)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            ang = func_80042DA8() & 0xFFF;
            v.vx = (u32)(func_80039B40(ang) * 5) >> 8;
            v.vy = (u32)(func_80039A74(ang) * 5) >> 8;
            v.vz = 0;
            rot.vz = 0;
            rot.vx = 0;
            rot.vy = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            func_8003C21C(&rot, &m);
            m.t[0] = m.t[1] = m.t[2] = 0;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&v, &v, &flag);
            q->unkC = (p->unkC - p->unk4) / 30 + (u16)v.vx;
            q->unkE = (p->unkE - p->unk6) / 30 + (u16)v.vy;
            q->unk10 = (p->unk10 - p->unk8) / 30 + (u16)v.vz;
            q->unk1A = 0x32;
        }
        if ((u16)(p->unk2 - 0x1F) < 9U) {
            for (i = 0; i < 10; i++) {
                if ((D_801EAD4C >> i) & 1) {
                    q = (MgTask *)&D_80162978[func_800BBEAC(func_801B008C)];
                    func_800D3994(i, D_8015190F[i][0], &q->unk4);
                    k = 0x190;
                    q->unk4 = (u16)q->unk4 - k + func_80042DA8() % 800;
                    q->unk6 = (u16)q->unk6 - k + func_80042DA8() % 800;
                    q->unk8 = (u16)q->unk8 - k + func_80042DA8() % 800;
                    q = (MgTask *)&D_801621F0[func_800BC04C(func_801B0174)];
                    func_800D3994(i, D_8015190F[i][0], &q->unk4);
                    k = 0x258;
                    q->unk4 = (u16)q->unk4 - k + func_80042DA8() % 1200;
                    q->unk6 = (u16)q->unk6 - k + func_80042DA8() % 1200;
                    q->unk8 = (u16)q->unk8 - k + func_80042DA8() % 1200;
                }
            }
        }
        t = p->unk2;
        if (t == 0x1E) {
            q = (MgTask *)&D_80162978[func_800BBEAC(func_801B02DC)];
            q->unk4 = 0;
            q->unk6 = 0;
            q->unk8 = 0x7D0;
            q->unk10 = 0;
            q->unkE = 0;
            q->unkC = 0;
            if (p->unk2 == t) {
                func_800BBEAC(func_801B08F0);
            }
        }
        if (p->unk2 == 0x50) {
            for (i = 0; i < 10; i++) {
                if ((D_801EAD4C >> i) & 1) {
                    func_800D5774(i);
                }
            }
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x64) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B100C(arg0, arg1) {
    MgObj20 *p;

    func_800BBEAC(func_801B0020);
    D_801EAD4C = arg0;
    func_800D2980(&D_801B10DC, 0, 0, 0);
    func_800BBA84(0xBA, arg1, 0);
    p = &D_80162978[func_800BBEAC(func_801B0AA0)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    return func_800D54EC(arg0, &p->pad[4]);
}
