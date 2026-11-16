#include "common.h"
#include "magic_debucho/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B1D64();
    return &D_801BAC54;
}

MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801C4058.m[0][0] = D_801C4058.m[1][1] = D_801C4058.m[2][2] = scale;
    func_8003B48C(&D_801C42A0);
    func_8003B51C(&D_801C42A0);
    func_8003BC6C(v, (MgVec *)D_801C4058.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801C4058.t, &n);
        D_801C4058.t[0] += (dist * n.vx) >> 12;
        D_801C4058.t[1] += (dist * n.vy) >> 12;
        D_801C4058.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801C4058);
    func_8003B51C(&D_801C4058);
    return &D_801C4058;
}

s32 func_801B0184(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801C42C2[-v];
    }
    return v;
}

void func_801B01C0(void) {
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
            D_801C4248.actor = -1;
            D_801C4270.actor = -1;
            D_801C4248.frames = 0;
            D_801C4270.frames = 0;
            p->unk2 = 1;
        }
        while (D_801C4248.frames == 0 || D_801C4270.frames == 0) {
            op = *p->script++;
            if (op & 0x40) {
                D_801C4298 = &D_801C4248;
                D_801C429C = &D_801C4270;
            } else {
                D_801C4298 = &D_801C4270;
                D_801C429C = &D_801C4248;
            }
            D_801C4298->mode = op & 0xFF3F;
            switch (D_801C4298->mode) {
            case 1:
                D_801C4298->pos.vx = *p->script++;
                D_801C4298->pos.vy = *p->script++;
                D_801C4298->pos.vz = *p->script++;
                break;
            case 2:
                D_801C4298->frames = func_801B0184(&p->script);
                D_801C4298->vel.vx = (*p->script++ - D_801C4298->pos.vx) / D_801C4298->frames;
                D_801C4298->vel.vy = (*p->script++ - D_801C4298->pos.vy) / D_801C4298->frames;
                D_801C4298->vel.vz = (*p->script++ - D_801C4298->pos.vz) / D_801C4298->frames;
                break;
            case 3:
                sv->vx = D_801C429C->pos.vx - D_801C4298->pos.vx;
                sv->vy = D_801C429C->pos.vy - D_801C4298->pos.vy;
                sv->vz = D_801C429C->pos.vz - D_801C4298->pos.vz;
                D_801C4298->unk4 = func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz);
                D_801C4298->unk18 = D_801C4298->pos;
                D_801C4298->frames = func_801B0184(&p->script);
                sv->vx = *p->script++;
                sv->vy = *p->script++;
                sv->vz = *p->script++;
                D_801C4298->vel.vx = (sv->vx - D_801C4298->pos.vx) / D_801C4298->frames;
                D_801C4298->vel.vy = (sv->vy - D_801C4298->pos.vy) / D_801C4298->frames;
                D_801C4298->vel.vz = (sv->vz - D_801C4298->pos.vz) / D_801C4298->frames;
                if (D_801C429C->mode == 2) {
                    sv2->vx = D_801C429C->pos.vx + D_801C429C->vel.vx * D_801C429C->frames;
                    sv2->vy = D_801C429C->pos.vy + D_801C429C->vel.vy * D_801C429C->frames;
                    sv2->vz = D_801C429C->pos.vz + D_801C429C->vel.vz * D_801C429C->frames;
                } else {
                    sv2->vx = D_801C429C->pos.vx;
                    sv2->vy = D_801C429C->pos.vy;
                    sv2->vz = D_801C429C->pos.vz;
                }
                sv->vx -= sv2->vx;
                sv->vy -= sv2->vy;
                sv->vz -= sv2->vz;
                D_801C4298->unk8 = (func_80039F5C(sv->vx * sv->vx + sv->vy * sv->vy + sv->vz * sv->vz) - D_801C4298->unk4) / D_801C4298->frames;
                break;
            case 4:
                D_801C4298->frames = func_801B0184(&p->script);
                sv->vx = *p->script++ - D_801C4298->pos.vx;
                sv->vy = *p->script++ - D_801C4298->pos.vy;
                sv->vz = *p->script++ - D_801C4298->pos.vz;
                D_801C4298->unk18.vx = ((sv->vx - D_801C4298->vel.vx * D_801C4298->frames) * 2) / (D_801C4298->frames * D_801C4298->frames);
                D_801C4298->unk18.vy = ((sv->vy - D_801C4298->vel.vy * D_801C4298->frames) * 2) / (D_801C4298->frames * D_801C4298->frames);
                D_801C4298->unk18.vz = ((sv->vz - D_801C4298->vel.vz * D_801C4298->frames) * 2) / (D_801C4298->frames * D_801C4298->frames);
                break;
            case 5:
                D_801C4298->frames = func_801B0184(&p->script);
                D_801C4298->unk4 = 0;
                D_801C4298->unk8 = 0x1000 / D_801C4298->frames;
                D_801C4298->unk18.vx = D_801C4298->pos.vx;
                D_801C4298->unk18.vy = D_801C4298->pos.vy;
                D_801C4298->unk18.vz = D_801C4298->pos.vz;
                D_801C4298->vel.vx = *p->script++ - D_801C4298->pos.vx;
                D_801C4298->vel.vy = *p->script++ - D_801C4298->pos.vy;
                D_801C4298->vel.vz = *p->script++ - D_801C4298->pos.vz;
                break;
            case 6:
                if ((D_801C4298->actor = *p->script++) == 0) {
                    D_801C4298->actor = p->actor;
                }
                D_801C4298->part = *p->script++;
                break;
            case 7:
                D_801C4298->actor = -1;
                break;
            case 0:
            case 8:
                D_801C4298->frames = func_801B0184(&p->script);
                break;
            default:
                p->unk0 = -1;
                return;
            }
        }
        D_801C4298 = &D_801C4248;
        D_801C429C = &D_801C4270;
        for (i = 0; i < 2; i++) {
            switch (D_801C4298->mode) {
            case 0:
            case 1:
                break;
            case 4:
                D_801C4298->vel.vx += D_801C4298->unk18.vx;
                D_801C4298->vel.vy += D_801C4298->unk18.vy;
                D_801C4298->vel.vz += D_801C4298->unk18.vz;
            case 2:
                D_801C4298->pos.vx += D_801C4298->vel.vx;
                D_801C4298->pos.vy += D_801C4298->vel.vy;
                D_801C4298->pos.vz += D_801C4298->vel.vz;
                break;
            case 3:
                D_801C4298->unk18.vx += D_801C4298->vel.vx;
                D_801C4298->unk18.vy += D_801C4298->vel.vy;
                D_801C4298->unk18.vz += D_801C4298->vel.vz;
                D_801C4298->unk4 += D_801C4298->unk8;
                vec->vx = D_801C429C->pos.vx - D_801C4298->unk18.vx;
                vec->vy = D_801C429C->pos.vy - D_801C4298->unk18.vy;
                vec->vz = D_801C429C->pos.vz - D_801C4298->unk18.vz;
                func_8003A078(vec, sv);
                D_801C4298->pos.vx = D_801C429C->pos.vx - ((sv->vx * D_801C4298->unk4) >> 12);
                D_801C4298->pos.vy = D_801C429C->pos.vy - ((sv->vy * D_801C4298->unk4) >> 12);
                D_801C4298->pos.vz = D_801C429C->pos.vz - ((sv->vz * D_801C4298->unk4) >> 12);
                break;
            case 5:
                D_801C4298->unk4 += D_801C4298->unk8;
                k = D_801C4298->unk4;
                k = ((s32 (*)(s32))func_80039A74)(((s32 (*)(s32))func_80039A74)(k / 4) / 4);
                D_801C4298->pos.vx = D_801C4298->unk18.vx + ((D_801C4298->vel.vx * k) >> 12);
                D_801C4298->pos.vy = D_801C4298->unk18.vy + ((D_801C4298->vel.vy * k) >> 12);
                D_801C4298->pos.vz = D_801C4298->unk18.vz + ((D_801C4298->vel.vz * k) >> 12);
                break;
            }
            cam = D_801C4298;
            D_801C4298 = &D_801C4270;
            D_801C429C = &D_801C4248;
            cam->frames--;
        }
    }
    if (p->mat != NULL) {
        if (D_801C4248.mode != 8) {
            func_8003B48C(p->mat);
            func_8003B51C(p->mat);
            if (D_801C4248.actor == -1) {
                func_8003BC6C(&D_801C4248.pos, vec, &flag);
                D_80158D00.vx = vec->vx;
                D_80158D00.vy = vec->vy;
                D_80158D00.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801C4248.pos, vec);
                if (D_801C4248.part != -1) {
                    func_800D3994(D_801C4248.actor, D_801C4248.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801C4248.actor].vx;
                    sv->vy = D_80151A4C[D_801C4248.actor].vy;
                    sv->vz = D_80151A4C[D_801C4248.actor].vz;
                }
                D_80158D00.vx = vec->vx + sv->vx;
                D_80158D00.vy = vec->vy + sv->vy;
                D_80158D00.vz = vec->vz + sv->vz;
                func_8003B48C(p->mat);
                func_8003B51C(p->mat);
            }
        }
        if (D_801C4270.mode != 8) {
            if (D_801C4270.actor == -1) {
                func_8003BC6C(&D_801C4270.pos, vec, &flag);
                D_801031E8.vx = vec->vx;
                D_801031E8.vy = vec->vy;
                D_801031E8.vz = vec->vz;
            } else {
                func_8003ACE4(&D_801C4270.pos, vec);
                if (D_801C4270.part != -1) {
                    func_800D3994(D_801C4270.actor, D_801C4270.part, sv);
                } else {
                    sv->vx = D_80151A4C[D_801C4270.actor].vx;
                    sv->vy = D_80151A4C[D_801C4270.actor].vy;
                    sv->vz = D_80151A4C[D_801C4270.actor].vz;
                }
                D_801031E8.vx = vec->vx + sv->vx;
                D_801031E8.vy = vec->vy + sv->vy;
                D_801031E8.vz = vec->vz + sv->vz;
            }
        }
    } else {
        if (D_801C4248.mode != 8) {
            D_80158D00 = D_801C4248.pos;
        }
        if (D_801C4270.mode != 8) {
            D_801031E8 = D_801C4270.pos;
        }
    }
}

void func_801B11DC(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B01C0)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B1240(void) {
    MgTask *p;
    s32 t;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x2D) {
        t = (t << 12) / 45;
        v = (t * 0x6000 >> 12) + 0x1000;
        D_801C4180 = D_801C4190 = v;
        D_801C417A = 0x1000 - t;
    } else {
        t -= 0x2D;
        if (t < 0x1E) {
            D_801C4180 = D_801C4190 = 0x6000;
            D_801C417A = 0;
        } else {
            t -= 0x1E;
            if (t < 0xF) {
                D_801C4180 = D_801C4190 = 0x6000;
                t = (t << 12) / 15;
                D_801C417A = t;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    func_8003A63C(&D_801C42A0, (MgMat *)&D_801C4180, D_801C41A0);
    func_8003B48C(D_801C41A0);
    func_8003B51C(D_801C41A0);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801C4170, D_801517C0 + 0x4078, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1414(void) {
    MgTask *p;
    s32 t;
    s16 v;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    do {
        if (t < 10) {
            D_801C41AE = 0;
        } else {
            t -= 10;
            if (t >= 5) {
                p->unk0 = -1;
                return;
            }
            D_801C41AE = (t << 12) / 5;
        }
        t = (p->unk2 << 12) / 15;
    } while (0);
    v = (t * 0x5000 >> 12) + 0x1000;
    D_801C41B4.m[0][0] = D_801C41B4.m[1][1] = D_801C41B4.m[2][2] = v;
    func_8003A63C(&D_801C42A0, &D_801C41B4, D_801C41D4);
    func_8003B48C(D_801C41D4);
    func_8003B51C(D_801C41D4);
    D_80163C74 = func_800D29D4(D_801C41A4, D_801517C0 + 0x406C, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1584(void) {
    MgTask *p;
    s32 *q;
    s16 n;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_801B0068((MgSVec *)&p->unk4, p->unk14, 0);
    q = &D_801C4218;
    *q = D_801C41D8[p->unk2];
    D_80163C74 = func_800D4D90(q, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0x10) {
            p->unk0 = -1;
        } else {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unkC = p->unkC * 0xF >> 4;
            p->unkE = p->unkE * 0x11 >> 4;
            p->unk10 = p->unk10 * 0xF >> 4;
        }
    }
}

void func_801B16BC(void) {
    MgTask *p;
    MgTask *q;
    s32 r;
    s32 n;
    s32 i;
    s16 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = (MgTask *)&D_80162978[func_800BBEAC(&func_801B1584)];
            r = func_80042DA8() & 0xFFF;
            n = func_80042DA8() % 200 + 0x64;
            q->unk4 = (u32)(func_80039A74(r) * 0x36B) >> 10;
            q->unk6 = 0;
            q->unk8 = (u32)(func_80039B40(r) * 0x36B) >> 10;
            q->unkC = n * func_80039A74(r) >> 12;
            q->unkE = -(func_80042DA8() % 100 + 0x32);
            q->unk10 = n * func_80039B40(r) >> 12;
            q->unk14 = func_80042DA8() % 0x4000 + 0x4000;
            i++;
        } while (i < 0xF);
        c = (u16)p->unk2 + 1;
        p->unk2 = c;
        if (c >= 6) {
            p->unk0 = -1;
        }
    }
}

void func_801B18B0(void) {
    MgObj20 *p;
    u16 *q;
    u16 *r;
    s16 n;
    s32 v;
    u16 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (!(t & 1)) {
            v = -((s16)t * 0x1F4) / 30 + 0x1F4;
            q = &D_801031EA;
            r = &D_80158D02;
            *q -= v;
            *r -= v;
        }
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B1980(void) {
    MgObj20 *p;
    u16 *q;
    s16 n;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        q = &D_80153D22;
        *q += 0x29A;
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0xF) {
            p->unk0 = -1;
        }
    }
}

void func_801B19EC(void) {
    MgObj20 *p;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_80046794(D_801517C0 + 0x406C, (s32)D_801C4224 + D_801C4244 * 0x10);
    D_801C4244 ^= 1;
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0xC) {
            p->unk0 = -1;
        }
    }
}

void func_801B1A98(void) {
    MgTask *p;
    s16 *w;
    s32 t;
    s32 i;
    u8 pad[8];

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801C4030, &D_801C42A0);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t > 0) {
            t -= 1;
            if (t < 0xF) {
                if (t == 0) {
                    func_800BBEAC(&func_801B1240);
                    func_800D55F4(0x22, 0x40, 0x1FB, 0x1FC, 0x1FD);
                }
            } else {
                t -= 0xF;
                if (t < 0xF) {
                    if (t == 0xE) {
                        w = (s16 *)func_800D4FA8(1);
                        *(s16 *)((u8 *)w + 4) = 0;
                        *(s16 *)((u8 *)w + 6) = -0x2710;
                        *(s16 *)((u8 *)w + 8) = D_801C404C;
                        *(s16 *)((u8 *)w + 0x10) = D_801C4052;
                    }
                } else {
                    t -= 0xF;
                    if (t < 0xC) {
                        if (t == 0) {
                            func_800BBEAC(&func_801B1980);
                            func_800BBEAC(&func_801B19EC);
                        }
                    } else {
                        t -= 0xC;
                        if (t < 0x30) {
                            if (t >= 3) {
                                t -= 3;
                                if (t < 0x1E) {
                                    if (t == 0) {
                                        func_800BBEAC(&func_801B1414);
                                        func_800BBEAC(&func_801B16BC);
                                        func_800BBEAC(&func_801B18B0);
                                    }
                                } else {
                                    t -= 0x1E;
                                    if (t < 0xF) {
                                        if (t == 0) {
                                            i = 0;
                                            D_80153BC8.c0 = D_80153BC8.c1 = D_80153BC8.c2 = 0;
                                            if (D_80153BC8.n > 0) {
                                                do {
                                                    D_80153BC8.f[i] |= 8;
                                                    i++;
                                                } while (i < D_80153BC8.n);
                                            }
                                        }
                                        D_80153BCC = (t << 12) / 15;
                                        if (t == 0xE) {
                                            func_800D4FA8(2);
                                        }
                                    }
                                }
                            }
                        } else {
                            i = 0;
                            do {
                                if ((D_801C42C0 >> i) & 1) {
                                    func_800D5774(i);
                                }
                                i++;
                            } while (i < 0xA);
                            D_800F8380 = 0;
                            p->unk0 = -1;
                        }
                    }
                }
            }
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_debucho/nonmatchings/text", func_801B1D64);
