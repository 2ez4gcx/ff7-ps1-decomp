#include "common.h"
#include "magic_search/decls.h"

INCLUDE_RODATA("../asm/us/magic_search/nonmatchings/text", D_801B0000);

void func_801B008C(s32 arg0, MgSVec *rot, s16 scale) {
    MgMat r;
    MgMat m;
    MgVec unused;

    m = D_801B0000;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    m.m[0][0] = m.m[1][1] = m.m[2][2] = scale;
    func_8003B05C(&m, &D_800FA63C);
    func_8003C21C(rot, &r);
    func_8003B05C(&m, &r);
    func_8003B48C(&m);
    func_8003B51C(&m);
}

void func_801B0170(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801B5414[0] = p->unk2;
    D_801CD45C = func_800D4D90(&D_801B5414[-4], D_801517C0 + 0x70, 0xC, D_801CD45C);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B5280) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B022C(void) {
    MgMat m;
    MgMat pad;
    SrSVec a;
    SrSVec b;
    SrSVec c;
    MgVec scale;
    s32 flag;
    SrObj2 *p;
    SrObj2 *q;
    s16 k;
    s32 t1; s32 t2; s32 t3; s32 t4;
    s16 w;
    u8 *model;
    SrDraw *s;
    s16 *wp;

    p = (SrObj2 *)&D_80162978[D_8015169C];
    k = ((s16)p->unk16 >> 1) * 2 - 1;
    t1 = (func_80039A74(p->unk2 << 8) / 40) * k;
    a.vx = t1;
    b.vx = t1;
    t2 = (func_80039A74(p->unk2 << 7) >> 5) * k;
    a.vz = 0;
    b.vz = 0;
    a.vx -= 0x400;
    a.vy = t2;
    b.vy = t2;
    func_8003C21C((MgSVec *)&a, &m);
    func_8003A79C(D_801B543C, &m, &m);
    scale.vy = p->unk14;
    t3 = 0x1E00;
    if (!(p->unk16 & 1)) {
        t3 = 0x1400;
    }
    scale.vz = t3;
    scale.vx = t3;
    func_8003B35C(&m, &scale);
    m.t[0] = (s16)p->unk4;
    m.t[1] = (s16)p->unk6;
    m.t[2] = (s16)p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    func_8003B69C(0, 0, 0);
    
    model = D_801B4994;
    
    s = &D_801B541C;
    
    wp = &s->unkA;
    
    if (!(p->unk16 & 1)) {
        model = D_801B4D78;
    }
    wp++; wp--;
    s->unk0 = model;
    if (!(p->unk16 & 1)) {
        t4 = D_801B5418;
        w = 0x1000 - (t4 << 5);
    } else {
        w = 0x1000 - D_801B5418 * 0x18;
    }
    *wp = w;
    D_801CD45C = func_800D29D4(&D_801B541C, D_801517C0 + 0x70, 0xC, D_801CD45C);
    if (D_80062D98 == 0) {
        if (!(p->unk16 & 1)) {
            q = (SrObj2 *)&D_80162978[func_800BBEAC((M2C_UNK *)func_801B0170)];
            q->unk4 = p->unk4;
            q->unk6 = p->unk6;
            q->unk8 = p->unk8;
            c.vx = 0;
            c.vy = 0;
            c.vz = p->unk1C;
            func_8003C21C((MgSVec *)&b, &m);
            func_8003A79C(D_801B543C, &m, &m);
            m.t[0] = (s16)q->unk4;
            m.t[1] = (s16)q->unk6;
            m.t[2] = (s16)q->unk8;
            func_8003B48C(&m);
            func_8003B51C(&m);
            func_8003BADC((MgSVec *)&c, &q->unk4, &flag);
            q->unkC = 0; q->unkE = p->unkE; q->unk10 = 0;
        }
        if (p->unk2 < 8) {
            D_801B5418++;
        }
        if (p->unk2 >= 0x19) {
            D_801B5418--;
        }
        p->unk2++;
        if (p->unk2 == 0x20) {
            p->unk0 = -1;
        }
    }
}

void func_801B05A0(void) {
    MgMat m;
    MgVec v;
    SrObj *p;
    SrObj *q;
    s16 dx;
    s16 dy;
    s16 dz;
    s16 len;
    s16 i;

    p = (SrObj *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            dx = p->unkC - p->unk4;
            D_801B5434.v = dx;
            dy = p->unkE - p->unk6;
            D_801B5436.v = dy;
            dz = p->unk10 - p->unk8;
            D_801B5438.v = dz;
            len = func_80039F5C(dx * dx + dy * dy + dz * dz);
            for (i = 0; i < 4; i++) {
                q = (SrObj *)&D_80162978[func_800BBEAC(&func_801B022C)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                q->unkE = func_8003CC1C((s16)p->unkC - (s16)p->unk4, (s16)p->unk10 - (s16)p->unk8);
                q->unk16 = i;
                q->unk1C = len;
                q->unk14 = len * 0x1500 / 2800;
            }
        }
        if (p->unk2 == 0x10) {
            func_800D5774(p->unk18);
        }
        p->unk2++;
        if (p->unk2 == 0x28) {
            p->unk0 = -1;
            func_800D52A0(0, 0xA);
        }
    }
}

void func_801B07B0(arg0, arg1) {
    MgSVec d;
    SrObj *p;

    p = (SrObj *)&D_80162978[func_800BBEAC(&func_801B05A0)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    d.vx = p->unkC - p->unk4;
    d.vy = p->unkE - p->unk6;
    d.vz = p->unk10 - p->unk8;
    func_800D44E8(&d, D_801B543C);
    p->unk18 = arg0;
}

INCLUDE_RODATA("../asm/us/magic_search/nonmatchings/text", D_801B0020);

void func_801B08B4(arg0, arg1) {
    func_800BBEAC((void *)D_801B0020);
    func_800D2980((void *)D_801B0954, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B07B0);
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    func_800D52A0(0x400, 0xA);
    func_800BBA84(0x62, arg1, 0x40);
}
