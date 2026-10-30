#include "common.h"
#include "magic_lasboss/decls.h"

void func_801B0040(void) {
    func_801B2A50();
}

s32 func_801B0060(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801E6C06[-v];
    }
    return v;
}

s32 func_801B009C(s32 t, s32 s) {
    s32 orig;
    s32 i;
    s32 n;

    orig = t;
    if (s > 0) {
        n = s >> 8;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
    } else {
        s = -s;
        n = s >> 8;
        t = 0x1000 - t;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
        t = 0x1000 - t;
    }
    n = (s & 0xFF) + 1;
    t = (t * n + orig * (0x100 - n)) >> 8;
    return t;
}

void func_801B018C(void) {
    MgCamTask *p;
    MgSVec *sv;
    MgSVec *sv2;
    MgVec *vec;
    s32 i;
    u16 op;
    s32 k;
    MgCam *cam;
    u8 pad[0x100];
    s32 flag;

    sv2 = (MgSVec *)0x1F800008;
    vec = (MgVec *)0x1F800010;
    p = (MgCamTask *)&D_80162978[D_8015169C];
    sv = (MgSVec *)0x1F800000;
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801D6B78.actor = -1;
            D_801D6BA4.actor = -1;
            D_801D6B78.frames = 0;
            D_801D6BA4.frames = 0;
            p->unk2 = 1;
        }
        while (D_801D6B78.frames == 0 || D_801D6BA4.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801D6BD0 = &D_801D6B78;
                D_801D6BD4 = &D_801D6BA4;
            } else {
                D_801D6BD0 = &D_801D6BA4;
                D_801D6BD4 = &D_801D6B78;
            }
            D_801D6BD0->mode = op & 0xFF3F;
            switch (D_801D6BD0->mode) {
            case 1:
                D_801D6BD0->pos.vx = *p->script++;
                D_801D6BD0->pos.vy = *p->script++;
                D_801D6BD0->pos.vz = *p->script++;
                break;
            case 2:
                D_801D6BD0->frames = func_801B0060(&p->script);
                D_801D6BD0->vel.vx = (*p->script++ - D_801D6BD0->pos.vx) / D_801D6BD0->frames;
                D_801D6BD0->vel.vy = (*p->script++ - D_801D6BD0->pos.vy) / D_801D6BD0->frames;
                D_801D6BD0->vel.vz = (*p->script++ - D_801D6BD0->pos.vz) / D_801D6BD0->frames;
                break;
            case 3:
                sv->vx = D_801D6BD4->pos.vx - D_801D6BD0->pos.vx;
                sv->vy = D_801D6BD4->pos.vy - D_801D6BD0->pos.vy;
                sv->vz = D_801D6BD4->pos.vz - D_801D6BD0->pos.vz;
                D_801D6BD0->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801D6BD0->unk18 = D_801D6BD0->pos;
                D_801D6BD0->frames = func_801B0060(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801D6BD0->vel.vx = (sv->vx - D_801D6BD0->pos.vx) / D_801D6BD0->frames;
                D_801D6BD0->vel.vy = (sv->vy - D_801D6BD0->pos.vy) / D_801D6BD0->frames;
                D_801D6BD0->vel.vz = (sv->vz - D_801D6BD0->pos.vz) / D_801D6BD0->frames;
                if (D_801D6BD4->mode == 2) {
                    sv2->vx = D_801D6BD4->pos.vx + D_801D6BD4->vel.vx * D_801D6BD4->frames;
                    sv2->vy = D_801D6BD4->pos.vy + D_801D6BD4->vel.vy * D_801D6BD4->frames;
                    sv2->vz = D_801D6BD4->pos.vz + D_801D6BD4->vel.vz * D_801D6BD4->frames;
                } else {
                    sv2->vx = D_801D6BD4->pos.vx;
                    sv2->vy = D_801D6BD4->pos.vy;
                    sv2->vz = D_801D6BD4->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801D6BD0->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801D6BD0->unk4) / D_801D6BD0->frames;
                break;
            case 4:
                D_801D6BD0->frames = func_801B0060(&p->script);
                sv->vx = *p->script++ - D_801D6BD0->pos.vx;
                sv->vy = *p->script++ - D_801D6BD0->pos.vy;
                sv->vz = *p->script++ - D_801D6BD0->pos.vz;
                D_801D6BD0->unk18.vx = ((sv->vx - D_801D6BD0->vel.vx * D_801D6BD0->frames) * 2) / (D_801D6BD0->frames * D_801D6BD0->frames);
                D_801D6BD0->unk18.vy = ((sv->vy - D_801D6BD0->vel.vy * D_801D6BD0->frames) * 2) / (D_801D6BD0->frames * D_801D6BD0->frames);
                D_801D6BD0->unk18.vz = ((sv->vz - D_801D6BD0->vel.vz * D_801D6BD0->frames) * 2) / (D_801D6BD0->frames * D_801D6BD0->frames);
                break;
            case 5:
                D_801D6BD0->frames = func_801B0060(&p->script);
                D_801D6BD0->unk28 = *p->script++;
                D_801D6BD0->unk4 = 0;
                D_801D6BD0->unk8 = 0x1000 / D_801D6BD0->frames;
                D_801D6BD0->unk18.vx = D_801D6BD0->pos.vx;
                D_801D6BD0->unk18.vy = D_801D6BD0->pos.vy;
                D_801D6BD0->unk18.vz = D_801D6BD0->pos.vz;
                D_801D6BD0->vel.vx = *p->script++ - D_801D6BD0->pos.vx;
                D_801D6BD0->vel.vy = *p->script++ - D_801D6BD0->pos.vy;
                D_801D6BD0->vel.vz = *p->script++ - D_801D6BD0->pos.vz;
                break;
            case 6:
                if ((D_801D6BD0->actor = *p->script++) == 0) {
                    D_801D6BD0->actor = p->actor;
                }
                D_801D6BD0->part = *p->script++;
                break;
            case 7:
                D_801D6BD0->actor = -1;
                break;
            case 0:
            case 9:
                D_801D6BD0->frames = func_801B0060(&p->script);
                break;
            case 8:
                D_80162084 = *p->script++;
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801D6BD0 = &D_801D6B78;
        D_801D6BD4 = &D_801D6BA4;
        for (i = 0; i < 2; i++) {
            switch (D_801D6BD0->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801D6BD0->vel.vx += D_801D6BD0->unk18.vx;
                D_801D6BD0->vel.vy += D_801D6BD0->unk18.vy;
                D_801D6BD0->vel.vz += D_801D6BD0->unk18.vz;
            case 2:
                D_801D6BD0->pos.vx += D_801D6BD0->vel.vx;
                D_801D6BD0->pos.vy += D_801D6BD0->vel.vy;
                D_801D6BD0->pos.vz += D_801D6BD0->vel.vz;
                break;
            case 3:
                D_801D6BD0->unk18.vx += D_801D6BD0->vel.vx;
                D_801D6BD0->unk18.vy += D_801D6BD0->vel.vy;
                D_801D6BD0->unk18.vz += D_801D6BD0->vel.vz;
                D_801D6BD0->unk4 += D_801D6BD0->unk8;
                vec->vx = D_801D6BD4->pos.vx - D_801D6BD0->unk18.vx;
                vec->vy = D_801D6BD4->pos.vy - D_801D6BD0->unk18.vy;
                vec->vz = D_801D6BD4->pos.vz - D_801D6BD0->unk18.vz;
                func_8003A078(vec, sv);
                D_801D6BD0->pos.vx = D_801D6BD4->pos.vx - ((sv->vx * D_801D6BD0->unk4) >> 12);
                D_801D6BD0->pos.vy = D_801D6BD4->pos.vy - ((sv->vy * D_801D6BD0->unk4) >> 12);
                D_801D6BD0->pos.vz = D_801D6BD4->pos.vz - ((sv->vz * D_801D6BD0->unk4) >> 12);
                break;
            case 5:
                D_801D6BD0->unk4 += D_801D6BD0->unk8;
                k = func_801B009C(D_801D6BD0->unk4, D_801D6BD0->unk28);
                D_801D6BD0->pos.vx = D_801D6BD0->unk18.vx + ((D_801D6BD0->vel.vx * k) >> 12);
                D_801D6BD0->pos.vy = D_801D6BD0->unk18.vy + ((D_801D6BD0->vel.vy * k) >> 12);
                D_801D6BD0->pos.vz = D_801D6BD0->unk18.vz + ((D_801D6BD0->vel.vz * k) >> 12);
                break;
            }
            cam = D_801D6BD0;
            D_801D6BD0 = &D_801D6BA4;
            D_801D6BD4 = &D_801D6B78;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801D6B78.mode != 9) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801D6B78.actor == -1) {
                func_8003BC6C(&D_801D6B78.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801D6B78.pos, vec);
                if (D_801D6B78.part != -1) {
                    func_800D3994(D_801D6B78.actor, D_801D6B78.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801D6B78.actor].vx;
                    sv->vy = D_80151A4C[D_801D6B78.actor].vy;
                    sv->vz = D_80151A4C[D_801D6B78.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801D6BA4.mode != 9) {
            if (D_801D6BA4.actor == -1) {
                func_8003BC6C(&D_801D6BA4.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801D6BA4.pos, vec);
                if (D_801D6BA4.part != -1) {
                    func_800D3994(D_801D6BA4.actor, D_801D6BA4.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801D6BA4.actor].vx;
                    sv->vy = D_80151A4C[D_801D6BA4.actor].vy;
                    sv->vz = D_80151A4C[D_801D6BA4.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801D6B78.mode != 9) {
            D_80158D00 = D_801D6B78.pos;
        }
        if (D_801D6BA4.mode != 9) {
            D_801031E8 = D_801D6BA4.pos;
        }
    }
}

void func_801B11C0(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B018C)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B1224(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801E6BD8 = D_801D6AB0[p->unk2];
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B1288(void) {
    MgTask *p;
    s16 k;
    s16 n;

    p = &D_80162978[D_8015169C];
    k = (0x3C - p->unk2 * 3) * 4;
    if (k < 0) {
        k = 0;
    }
    D_80163C74 = func_800C4FC8((0x3C - p->unk2) * 4, k, k);
    if (D_80062D98 == 0) {
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B1344(void) {
    MgTask *p;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368((MgSVec *)&p->unk4, 0x1000, 0);
    D_801E6BD8 = func_800D4D90(D_801D6AB8, D_801517C0 + 0x70, 0xC, D_801E6BD8);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B141C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D6ACC;
    *frame = p->unk2;
    D_801E6BD8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E6BD8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D5EA8) {
            p->unk0 = -1;
        }
    }
}

void func_801B14D4(void) {
    MgMat m1;
    MgMat m2;
    u8 pad[8];
    s32 flag;
    MgTask *p;
    s16 i;
    u16 *frame;
    s16 n;

    i = 0;
    p = &D_80162978[D_8015169C];
    do {
        m2.m[0][i] = m2.m[1][i] = m2.m[2][i] = 0;
        i++;
    } while (i < 3);
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)m2.t, &flag);
    m2.m[0][0] = m2.m[1][1] = m2.m[2][2] = 0x3000;
    func_8003C21C((MgSVec *)&p->unkC, &m1);
    func_8003B05C(&m2, &m1);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    frame = &D_801D6AD8;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == D_801D5CB0) {
            p->unk0 = -1;
        }
    }
}

void func_801B1620(void) {
    MgSVec rot;
    MgSVec pos;
    MgMat m;
    s32 flag;
    MgTask *p;
    MgTask *q;
    s16 i;
    s16 ang;
    s16 k;
    s16 n;
    s32 r;

    p = &D_80162978[D_8015169C];
    func_800D4368((MgSVec *)&p->unk4, p->unk18, -0x190);
    func_8003B69C(0, 0, 0);
    D_801E6BD8 = func_800D29D4(D_801D6ADC, D_801517C0 + 0x70, 0xC, D_801E6BD8);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x3C) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(&func_801B1344)];
                q->unk4 = p->unk4;
                q->unk6 = p->unk6;
                q->unk8 = p->unk8;
                rot.vx = func_80042DA8() % 1600 - 0x320;
                rot.vy = func_80042DA8() % 1600 - 0x320;
                rot.vz = 0;
                func_8003C4AC(&rot, &m);
                m.t[0] = m.t[1] = m.t[2] = 0;
                func_8003B48C(&m);
                func_8003B51C(&m);
                func_8003BADC(&D_801D6AEC, (MgSVec *)&q->unkC, &flag);
                i++;
                q->unk4 += -q->unkC * 10;
                q->unk6 += -q->unkE * 10;
                q->unk8 += -q->unk10 * 10;
            } while (i < 2);
            if (!(func_80042DA8() & 3)) {
                r = func_80042DA8();
                ang = r % 0x1000;
                k = p->unk18 / 5 + 0xC8;
                pos.vx = p->unk4 + (func_80039B40(ang) * k >> 12);
                pos.vy = p->unk6 + (func_80039A74(ang) * k >> 12);
                pos.vz = p->unk8;
                q = &D_80162978[func_800BBEAC(&func_801B14D4)];
                q->unk4 = pos.vx;
                q->unk6 = pos.vy;
                q->unk8 = pos.vz;
                q->unkC = 0;
                q->unkE = 0;
                q->unk10 = func_80042DA8() % 800 + 0x670;
                q = &D_80162978[func_800BBEAC(&func_801B141C)];
                q->unk4 = pos.vx;
                q->unk6 = pos.vy;
                q->unk8 = pos.vz;
            }
        }
        if (p->unk2 < 0x46) {
            p->unk18 += 0x50;
        } else {
            p->unk18 -= 0x28;
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x6E) {
            p->unk0 = -1;
        }
    }
}

void func_801B1A1C(void) {
    MgSVec v;
    MgTask *p;
    u16 *frame;
    s16 n;

    p = &D_80162978[D_8015169C];
    v.vx = p->unk4 + (func_80039A74(p->unk14) * p->unk18 >> 12);
    v.vz = p->unk8 + (func_80039B40(p->unk14) * p->unk18 >> 12);
    v.vy = p->unk6;
    func_800D4368(&v, p->unk1A, 0);
    frame = &D_801D6AFC;
    *frame = p->unk2;
    D_801E6BD8 = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801E6BD8);
    if (D_80062D98 == 0) {
        p->unk6 += p->unkE;
        p->unk14 -= 0x40;
        p->unk18 += 0x28;
        n = p->unk2 + 1;
        p->unkE -= 0x28;
        p->unk2 = n;
        if (n == D_801D6100) {
            p->unk0 = -1;
        }
    }
}

void func_801B1B6C(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_800D4368((MgSVec *)&p->unk4, 0x2000, 0);
    frame = &D_801D6B08;
    *frame = p->unk2;
    D_801E6BD8 = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801E6BD8);
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        n = p->unk2 + 1;
        p->unkE -= 0x32;
        p->unk2 = n;
        if (n == D_801D6354) {
            p->unk0 = -1;
        }
    }
}

void func_801B1C60(void) {
    MgMat m;
    MgMat lw;
    MgSVec rot;
    MgTask *p;
    s16 n;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unk2 << 8;
    rot.vy = p->unk2 << 8;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    func_8003B35C(&m, &D_801D6B0C);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801E6BD8 = func_800D29D4(D_801D6B1C, D_801517C0 + 0x70, 0xC, D_801E6BD8);
    if (D_80062D98 == 0) {
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x3C) {
            p->unk0 = -1;
        }
    }
}

void func_801B1D88(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s16 n;

    b = D_80162978;
    p = &b[D_8015169C];
    if (D_80062D98 == 0) {
        if (!(p->unk2 & 1)) {
            q = &b[func_800BBEAC(&func_801B1B6C)];
            q->unk4 = p->unk4;
            q->unk8 = p->unk8 + func_80042DA8() % 800 - 0x190;
            q->unk6 = -func_80042DA8() % 400;
            q->unkC = 0x64;
            q->unkE = -0x190;
            q->unk10 = -0x190 - func_80042DA8() % 200;
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B1F04(void) {
    MgMat m;
    MgMat lw;
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s16 n;

    b = D_80162978;
    p = &b[D_8015169C];
    func_8003C21C(&D_801D6B3C, &m);
    D_801D6B30[0] = p->unk2 * 0x640;
    func_8003B35C(&m, (MgVec *)&D_801D6B30[-1]);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801E6BD8 = func_800D29D4(D_801D6B44, D_801517C0 + 0x70, 0xC, D_801E6BD8);
    if (D_80062D98 == 0) {
        if (p->unk2 < 0xF) {
            q = &b[func_800BBEAC(&func_801B1D88)];
            q->unk4 = 0x7D0;
            q->unk8 = p->unk8 + p->unk2 * 0x320;
            q->unk6 = 0;
        }
        n = p->unk2 + 1;
        p->unk2 = n;
        if (n == 0x14) {
            p->unk0 = -1;
        }
    }
}

void func_801B2098(void) {
    MgMat m;
    MgMat lw;
    MgVec sc;
    MgTask *p;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_8003C21C(&D_801D6B54, &m);
    sc.vy = 0x5000;
    sc.vx = sc.vz = D_801D6A3C;
    func_8003B35C(&m, &sc);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &lw);
    func_8003B48C(&lw);
    func_8003B51C(&lw);
    func_8003B69C(0, 0, 0);
    D_801E6BD8 = func_800D29D4(D_801D6B5C, D_801517C0 + 0x70, 0xC, D_801E6BD8);
    if (D_80062D98 == 0) {
        n = p->unk2 + 1;
        p->unk8 += 0x2BA;
        p->unk2 = n;
        if (n == 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B21C8(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x46) {
            D_801D6B6C += 1;
        }
        D_801031EA[0] += -D_801D6B6C / 2 + p->unk2 % 2 * D_801D6B6C;
        D_80158D02[0] += -D_801D6B6C / 2 + p->unk2 % 2 * D_801D6B6C;
        p->unk2++;
        if (p->unk2 == 0x46) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_lasboss/nonmatchings/text", func_801B22EC);

void func_801B2A50(arg0, arg1) {
    MgTask *p;
    MgMat *m;
    s32 *t;

    func_800BBEAC((M2C_UNK *)func_801B1224);
    func_800D2980(&D_801B2B88, 0, 0, 0);
    D_801E6BDC = arg0;
    func_800D54EC(arg0, &D_801E6BE0);
    p = &D_80162978[func_800BBEAC(&func_801B22EC)];
    func_800D3994(arg1, D_8015191E[arg1][0], (MgSVec *)&p->unk4);
    func_800D54EC(D_801E6BDC, &p->unkC);
    t = &D_801E6BFC;
    m = (MgMat *)((u8 *)t - 0x14);
    D_801E6C00 = 0;
    *t = 0;
    D_801E6C04 = 0;
    func_8003C21C(&D_801D6B70, m);
    ((void (*)(s32, s32, s32))func_801B11C0)((s32)&D_801D6A40, (s32)m, arg1);
    func_800BBEAC(&func_801B21C8);
    D_800FAFDC = 1;
}
