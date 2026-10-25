#include "common.h"
#include "magic_jammer/decls.h"

void func_801B0000(void) {
    func_801B0B44();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E92D8 = D_801D12D8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801D1274[0] = p->unk2;
    *(MgAnim **)&D_801D1274[-4] = D_801D1278[p->unk14];
    D_801E92D8 = func_800D4D90(&D_801D1274[-4], D_801517C0 + 0x70, 0xC, D_801E92D8);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk2++;
        if (p->unk2 == D_801D1278[p->unk14]->unk4) {
            p->unk0 = -1;
        }
    }
}

void func_801B01AC(void) {
    MgTask *p;
    MgMat m;
    MgMat rot;
    s32 flag;
    s16 i;
    s32 t;

    p = &D_80162978[D_8015169C];
    for (i = 0; i < 3; i++) {
        m.m[0][i] = m.m[1][i] = m.m[2][i] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = p->unk2 * 600 + 0x800;
    func_8003C21C(&D_801D1294, &rot);
    func_8003B05C(&m, &rot);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    D_801D128E[0] = t << 8;
    D_801E92D8 = func_800D29D4(&D_801D128E[-5], D_801517C0 + 0x70, 0xC, D_801E92D8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == 15) {
            p->unk0 = -1;
        }
    }
}

void func_801B0324(void) {
    MgMat m;
    MgMat r;
    MgSVec rot;
    s32 flag;
    MgTask *p;
    s16 i;
    s16 n;
    s16 t;
    s16 c;
    MgColTag *q;

    rot.vy = 0;
    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vz = p->unk2 << 8;
    for (i = 0; i < 3; i++) {
        m.m[i][0] = m.m[i][1] = m.m[i][2] = 0;
    }
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m.t, &flag);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = 0x1400;
    func_8003C21C(&rot, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
    t = p->unk2;
    if (t >= 12) {
        n = 20 - t;
    } else {
        n = 8;
    }
    q = &D_801D129C;
    q->tag = D_801D12A8[p->unk14];
    q->r = q->g = q->b = n << 4;
    D_801E92D8 = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_801E92D8);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        c = p->unk2 + 1;
        p->unk2 = c;
        if (c == 20) {
            p->unk0 = -1;
        }
    }
}

void func_801B050C(void) {
    MgTask *p;
    MgTask *q;
    MgSVec v;
    MgSVec rot;
    MgMat m;
    s32 flag;
    s16 a;
    s16 i;
    s32 k;
    s32 r;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x14) {
            q = &D_80162978[func_800BBEAC(&func_801B0324)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            q->unkC = (p->unkC - p->unk4) / 15;
            q->unkE = (p->unkE - p->unk6) / 15;
            q->unk10 = (p->unk10 - p->unk8) / 15;
            a = func_80042DA8() % 0x1000;
            v.vx = (u32)(func_80039B40(a) * 0xF) >> 10;
            v.vy = (u32)(func_80039A74(a) * 0xF) >> 10;
            v.vz = 0;
            rot.vz = 0;
            rot.vx = 0;
            a = func_8003CC1C(p->unkC - p->unk4, p->unk10 - p->unk8);
            q->unk16 = a;
            rot.vy = a;
            func_8003C21C(&rot, &m);
            m.t[0] = q->unkC;
            m.t[1] = q->unkE;
            m.t[2] = q->unk10;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC(&v, &q->unkC, &flag);
            q->unk14 = func_80042DA8() % 7;
        }
        if (p->unk2 == 0x18) {
            q = &D_80162978[func_800BBEAC(&func_801B01AC)];
            q->unk4 = p->unkC;
            q->unk6 = p->unkE;
            q->unk8 = p->unk10;
            func_800BBA84(0x189, p->unk1C, 0);
        }
        if ((u16)p->unk2 - 0x19 < 0xBU) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(&func_801B008C)];
                func_800D3994(p->unk1C, D_8015190F[p->unk1C][0], &q->unk4);
                k = 0x258;
                q->unk4 = q->unk4 - k + func_80042DA8() % 1200;
                k = 0x258;
                q->unk6 = q->unk6 - k + func_80042DA8() % 1200;
                k = 0x258;
                q->unk8 = q->unk8 - k + func_80042DA8() % 1200;
                q->unk14 = func_80042DA8() % 3;
                q->unk18 = (func_80042DA8() % 3 << 11) + 0x1000;
                a = func_80042DA8() % 0x1000;
                v.vx = (u32)(func_80039B40(a) * 0xF) >> 10;
                v.vy = (u32)(func_80039A74(a) * 0xF) >> 10;
                v.vz = 0;
                rot.vz = 0;
                rot.vx = 0;
                r = func_80042DA8();
                rot.vy = r % 0x1000;
                func_8003C21C(&rot, &m);
                m.t[0] = m.t[1] = m.t[2] = 0;
                func_8003B48C(&m);
                func_8003B51C(&m);
                func_8003BADC(&v, &q->unkC, &flag);
                i++;
            } while (i < 2);
        }
        if (p->unk2 == 0x1E) {
            func_800D5774(p->unk1C);
        }
        p->unk2++;
        if (p->unk2 == 0x32) {
            p->unk0 = -1;
        }
    }
}

void func_801B0A68(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B050C)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
    p->unk1E = arg1;
    func_800BBA84(0x11E, arg1, 0);
}

void func_801B0B44(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B0BB0, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0A68);
}
