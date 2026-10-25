#include "common.h"
#include "ending/decls.h"

INCLUDE_ASM("../asm/us/ending/nonmatchings/text", func_800A0030);

INCLUDE_ASM("../asm/us/ending/nonmatchings/text", func_800A04C4);

void func_800A09DC(void) {
    u8 pad[0x100];
    s32 i;
    EndActor *p;

    for (i = 0; i < 0x20; i++) {
        if (D_800A652C[i].flags & 1) {
            p = &D_800A652C[i];
            D_800A652C[i].x = 0x28;
            D_800A652C[i].y = 0x20;
            D_800A652C[i].z = 0;
            func_800A34C4(p);
            func_800A343C((EndFade *)p);
            D_800AF3FC = func_800A358C(D_800AF3E8, 0, D_800AF3FC, p);
        }
    }
}

s32 func_800A0AB8(void) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        D_800A652C[i].flags = 0;
        D_800A652C[i].f6 = 0;
        D_800A652C[i].f8 = 0;
        D_800A652C[i].anim = 0;
        D_800A652C[i].x = 0;
        D_800A652C[i].y = 0;
        D_800A652C[i].z = 0;
        D_800A652C[i].r = 0;
        D_800A652C[i].g = 0;
        D_800A652C[i].b = 0;
    }
    func_800A3178(&D_800A762C, 4, 0x80, (s32)func_800A09DC);
    return 1;
}

s32 func_800A0BA8(void) {
    s32 i;
    s32 id;

    i = *D_800A6528++;
    id = *D_800A6528++;
    D_800A652C[i].flags = 7;
    D_800A652C[i].f6 = 0;
    D_800A652C[i].f8 = 0;
    D_800A652C[i].anim = func_80034D18(0x800D0000, id);
    D_800A652C[i].x = 0;
    D_800A652C[i].y = 0;
    D_800A652C[i].z = 0;
    D_800A652C[i].r = 0;
    D_800A652C[i].g = 0;
    D_800A652C[i].b = 0;
    return 1;
}

void func_800A0CAC(void) {
    s32 i;
    s32 n;
    s32 t;

    i = *D_800A6528++;
    n = *D_800A6528++;
    t = *D_800A6528++;
    D_800A652C[i].timer = n;
    D_800A652C[i].tr = t;
    D_800A652C[i].tg = t;
    D_800A652C[i].tb = t;
    D_800A652C[i].flags |= 8;
    D_800A652C[i].dr = (t - D_800A652C[i].r) / n;
    D_800A652C[i].dg = (t - D_800A652C[i].g) / n;
    D_800A652C[i].db = (t - D_800A652C[i].b) / n;
    D_800A6394 = 1;
}

INCLUDE_ASM("../asm/us/ending/nonmatchings/text", func_800A0E68);

INCLUDE_ASM("../asm/us/ending/nonmatchings/text", func_800A0F90);

s32 func_800A11B4(void) {
    s32 i;
    s32 id;
    s32 n;

    id = *D_800A6528++;
    n = *D_800A6528++;
    for (i = 0; i < 0x20; i++) {
        if (!(D_800A652C[i].flags & 1)) {
            D_800A652C[i].flags = 1;
            D_800A652C[i].f6 = 0;
            D_800A652C[i].f8 = n;
            D_800A652C[i].anim = func_80034D18(0x800D0000, id);
            D_800A652C[i].x = 0x18;
            D_800A652C[i].y = 0xC8;
            D_800A652C[i].z = 0;
            D_800A652C[i].r = 0x80;
            D_800A652C[i].g = 0x80;
            D_800A652C[i].b = 0x80;
            return 1;
        }
    }
    return 0;
}

void func_800A12F0(void) {
    s32 i;
    EndActor *p;

    for (i = 0; i < 0x20; i++) {
        if (D_800A652C[i].flags & 1) {
            p = &D_800A652C[i];
            func_800A3368(p);
            func_800A34C4(p);
            func_800A343C((EndFade *)p);
            D_800AF3FC = func_800A358C(D_800AF3E8, 0, D_800AF3FC, p);
        }
    }
}

s32 func_800A139C(void) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        D_800A652C[i].flags = 0;
        D_800A652C[i].f6 = 0;
        D_800A652C[i].f8 = 0;
        D_800A652C[i].anim = 0;
        D_800A652C[i].x = 0;
        D_800A652C[i].y = 0;
        D_800A652C[i].z = 0;
        D_800A652C[i].px = 0;
        D_800A652C[i].py = 0;
        D_800A652C[i].pz = 0;
        D_800A652C[i].r = 0;
        D_800A652C[i].g = 0;
        D_800A652C[i].b = 0;
    }
    func_800A3178(&D_800A762C, 4, 0x80, (s32)func_800A12F0);
    return 1;
}

INCLUDE_ASM("../asm/us/ending/nonmatchings/text", func_800A14BC);

s32 func_800A16E4(void) {
    s32 i;

    i = *D_800A6528++;
    D_800A652C[i].flags |= 0x10;
    D_800A652C[i].tx = *D_800A6528++;
    D_800A652C[i].ty = *D_800A6528++;
    D_800A652C[i].tz = *D_800A6528++;
    D_800A652C[i].f4 = (u16)*D_800A6528++;
    return 1;
}

INCLUDE_ASM("../asm/us/ending/nonmatchings/text", func_800A17C0);

INCLUDE_ASM("../asm/us/ending/nonmatchings/text", func_800A19A4);

void func_800A1E20(void) {
    s16 *p;

    do {
        p = D_800A6528;
        D_800A6394 = 0;
        D_800A6528 = p + 1;
        if (D_800A63DC[*p]() == 0) {
            D_800A6528 = p;
            D_800A6390 = 0;
        } else {
            D_800A6390 = 1;
        }
    } while (D_800A6394 != 0);
}

void func_800A1ED4(s32 arg0) {
    D_800A6528 = arg0;
}

s32 func_800A1EE4(void) {
    return 0;
}

s32 func_800A1EEC(void) {
    s16 *p;

    p = D_800A6528;
    D_800A6528 = p + 1;
    func_80033E34(((s32 *)D_800A6398)[*p * 2], ((s32 *)D_800A6398)[*p * 2 + 1], 0x800D0000, 0);
    return 1;
}

s32 func_800A1F48(void) {
    s16 *p;

    p = D_800A6528;
    D_800A6528 = p + 1;
    func_80033E74(((s32 *)D_800A6398)[*p * 2], ((s32 *)D_800A6398)[*p * 2 + 1], 0x800D0000, 0);
    return 1;
}

s32 func_800A1FA4(void) {
    return func_80034410() == 0;
}

s32 func_800A1FC8(void) {
    s16 sp10;
    s16 sp12;
    s16 *p;

    p = D_800A6528;
    D_800A6528 = p + 1;
    func_800A2888(func_80034D18(0x800D0000, *p), &sp10, &sp12);
    return 1;
}

s32 func_800A2014(void) {
    s16 sp10;
    s16 sp12;
    s16 *p;
    s32 id;

    p = D_800A6528;
    D_800A6528 = p + 1;
    id = *p;
    if (D_800A6390 != 0) {
        func_80034D2C(func_80034D18(0x800D0000, id), 0x80120000);
    }
    if (func_80034D5C() == 0) {
        func_800A2888(0x80120000, &sp10, &sp12);
        return 1;
    }
    return 0;
}

s32 func_800A208C(void) {
    s16 *p;

    p = D_800A6528;
    D_800A6524 = 0x801A0000;
    D_800A6528 = p + 1;
    func_80034FC8(0x801A0000, *p);
    return 1;
}

s32 func_800A20D4(void) {
    return func_80034410() == 0;
}

s32 func_800A20F8(void) {
    u8 pad[8];

    func_800A2504(*D_800A6528++, *D_800A6528++, *D_800A6528++, *(u8 *)D_800A6528++, *(u8 *)D_800A6528++, *(u8 *)D_800A6528++);
    func_800A273C(0);
    return 1;
}

s32 func_800A2190(void) {
    s16 *p;

    p = D_800A6528;
    D_800A6528 = p + 1;
    func_80043D3C(*p);
    return 1;
}

s32 func_800A21CC(void) {
    s32 n;

    if (D_800A6390 != 0) {
        D_800A63B0 = *D_800A6528++;
    } else {
        D_800A6528++;
    }
    n = D_800A63B0 - 1;
    D_800A63B0 = n;
    return n == 0;
}

s32 func_800A2248(void) {
    func_800A32D8(func_800A3314(4));
    return 1;
}

s32 func_800A2274(void) {
    s32 n;

    n = *D_800A6528 + 1;
    D_800A6528 = (s16 *)((u8 *)D_800A6528 - n * 2);
    return 1;
}

s32 func_800A22A4(void) {
    s16 *p;

    p = D_800A6528;
    D_800A6528 = p + 1;
    D_800AF40C = *p;
    return 1;
}

s32 func_800A22D4(void) {
    D_800AF410 = 0;
    return 1;
}

s32 func_800A22E4(void) {
    s16 *p;

    p = D_800A6528;
    D_800A6528 = p + 1;
    D_800A652C[*p].flags = 0;
    return 1;
}

s32 func_800A2328(void) {
    s16 *p;

    p = D_800A6528;
    D_8009A000 = 0x10;
    D_800A6528 = p + 1;
    D_8009A004 = func_80034D18(0x800D0000, *p);
    func_8002DA7C();
    return 1;
}

s32 func_800A2380(void) {
    D_8009A000 = (u16)*D_800A6528++;
    D_8009A004 = *D_800A6528++;
    D_8009A008 = *D_800A6528++;
    func_8002DA7C();
    return 1;
}

s32 func_800A23F8(void) {
    return func_80034410() == 8;
}

s32 func_800A2420(void) {
    s16 *p;

    p = D_800A6528;
    D_800A6528 = p + 1;
    return D_80075D00->f8 >= (u32)*p;
}

void func_800A2458(void) {
    func_8003D1B4();
    func_8003D0C0();
    func_80043938(0);
    func_8003CE3C(0);
    func_80039EDC();
    func_80036298();
    func_80033B70();
}

void func_800A24A8(void) {
    s32 t;

    while ((t = func_800484A8()) == -1) {
        func_8003CEDC(0);
    }
    if (t != 0) {
        while (func_80048540(1) != 0) {
        }
    }
}

INCLUDE_ASM("../asm/us/ending/nonmatchings/text", func_800A2504);

s32 func_800A273C(s32 arg0) {
    u32 pad;
    s32 old0;
    s32 old1;

    D_800AF408 ^= 1;
    func_80043DD8(0);
    func_8003CEDC(arg0);
    func_800444AC((M2C_UNK *)&D_800AF398[D_800AF408]);
    func_800443B0((M2C_UNK *)&D_800AF2E0[D_800AF408]);
    D_8007EBD8 = (u8 *)&D_800AF398[D_800AF408];
    D_8007EBD0 = (s16 *)&D_800AF2E0[D_800AF408];
    pad = func_8001C808();
    old0 = D_800AF3C0;
    old1 = D_800AF3C4;
    D_800AF3F4 = pad;
    D_800AF3F8 = pad >> 16;
    D_800AF3EC = old0 & pad;
    D_800AF3F0 = old1 & (pad >> 16);
    D_800AF3C0 = ~pad;
    D_800AF3C4 = ~(pad >> 16);
    return D_800AF408;
}

void func_800A2888(s32 arg0, s16 *arg1, s16 *arg2) {
    Unk80046D0C sp10;

    func_80046CFC(arg0);
    func_80046D0C(&sp10);
    if (sp10.b_arg != 0) {
        func_80044000(sp10.b, (void *)sp10.b_arg);
        *arg1 = func_8004656C(sp10.unk0, 0, sp10.b[0], sp10.b[1]);
    }
    if (sp10.a_arg != 0) {
        func_80044000(sp10.a, (void *)sp10.a_arg);
        *arg2 = func_80046634(sp10.a[0], sp10.a[1]);
    }
}

void func_800A2934(void *arg0, void *arg1) {
    M2C_FIELD(arg0, void **, 4) = arg1;
    M2C_FIELD(arg1, void **, 0) = arg0;
    M2C_FIELD(arg1, s32 *, 0x34) = 0x1000;
    M2C_FIELD(arg1, s32 *, 0x30) = 0x1000;
    M2C_FIELD(arg1, s32 *, 0x2C) = 0x1000;
    M2C_FIELD(arg1, s32 *, 0x28) = 0x1000;
    M2C_FIELD(arg1, s16 *, 0x46) = 0;
    M2C_FIELD(arg1, s16 *, 0x44) = 0;
    M2C_FIELD(arg1, s16 *, 0x42) = 0;
    M2C_FIELD(arg1, s16 *, 0x40) = 0;
    M2C_FIELD(arg1, s16 *, 0x3E) = 0;
    M2C_FIELD(arg1, s16 *, 0x3C) = 0;
    M2C_FIELD(arg1, s16 *, 0x3A) = 0;
    M2C_FIELD(arg1, s16 *, 0x38) = 0;
}

INCLUDE_ASM("../asm/us/ending/nonmatchings/text", func_800A2974);

INCLUDE_ASM("../asm/us/ending/nonmatchings/text", func_800A2A2C);

INCLUDE_ASM("../asm/us/ending/nonmatchings/text", func_800A2C68);

s32 func_800A2E80(EndModel *p) {
    s32 sp10;

    func_8003BF8C(p->rot, p->m);
    p->t[0] = p->pos[0];
    p->t[1] = p->pos[1];
    p->t[2] = p->pos[2];
    func_8003B35C(p->m, p->scale);
    func_8003B16C(p->parent->m, p->m);
    func_8003B48C(p->parent->m);
    func_8003B51C(p->parent->m);
    func_8003BC6C(p->pos, p->t, &sp10);
    return sp10;
}

s32 func_800A2F1C(EndModel *p) {
    s32 sp10;

    func_8003C21C(p->rot, p->m);
    p->t[0] = p->pos[0];
    p->t[1] = p->pos[1];
    p->t[2] = p->pos[2];
    func_8003B35C(p->m, p->scale);
    func_8003B16C(p->parent->m, p->m);
    func_8003B48C(p->parent->m);
    func_8003B51C(p->parent->m);
    func_8003BC6C(p->pos, p->t, &sp10);
    return sp10;
}

s32 func_800A2FB8(EndModel *m, s32 *tgt, s32 *d, s32 scale) {
    s32 v[3];

    v[0] = tgt[0] - m->pos[0];
    v[1] = tgt[1] - m->pos[1];
    v[2] = tgt[2] - m->pos[2];
    func_8003A08C(v, d);
    if ((u32)(v[0] + 2) < 4U && (u32)(v[1] + 2) < 4U) {
        if ((u32)(v[2] + 2) < 4U) {
            d[0] = v[0] << 12;
            d[1] = v[1] << 12;
            d[2] = v[2] << 12;
            return 1;
        }
    }
    if (scale != 0x1000) {
        d[0] = scale * d[0] / 4096;
        d[1] = scale * d[1] / 4096;
        d[2] = scale * d[2] / 4096;
    }
    return 0;
}

void func_800A310C(void) {
    D_800AF3C8.id = 0;
    D_800AF3C8.f = 1;
    D_800AF3C8.g = 0xFF;
    D_800AF3C8.prev = 0;
    D_800AF3C8.next = &D_800AF3D8;
    D_800AF3D8.id = 1;
    D_800AF3D8.f = 1;
    D_800AF3D8.g = 0;
    D_800AF3D8.prev = &D_800AF3C8;
    D_800AF3D8.next = 0;
}

void func_800A3178(EndSlot *node, s16 id, u8 prio, s32 data) {
    EndSlot *cur;

    cur = (EndSlot *)&D_800AF3C8;
    do {
        if (cur->prio < prio) {
            node->id = id;
            node->data = data;
            node->f = 2;
            goto link;
        }
        cur = cur->next;
    } while (cur->next != 0);
    if (cur->prio < prio) {
        node->id = id;
        node->data = data;
        node->f = 2;
link:
        node->prio = prio;
        node->next = cur;
        node->prev = cur->prev;
        cur->prev = node;
        cur = node->prev;
        cur->next = node;
    }
}

void func_800A3210(void) {
    EndSlot *p;

    for (p = (EndSlot *)D_800AF3CC; p->next != 0; p = p->next) {
        if (p->f == 4) {
            ((void (*)(EndSlot *))p->data)(p);
        }
    }
    for (p = (EndSlot *)D_800AF3CC; p->next != 0; p = p->next) {
        if (p->f == 2) {
            p->f = 4;
        }
    }
}

void func_800A32D8(void *arg0) {
    void **temp_v0;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0);
    temp_v0 = M2C_FIELD(arg0, void ***, 4);
    M2C_FIELD(temp_v1, void ***, 4) = temp_v0;
    *temp_v0 = temp_v1;
}

void func_800A32F0(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0xE) = 8;
}

void func_800A32FC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0xE) = 4;
}

void func_800A3308(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0xE) = 0x10;
}

EndNode *func_800A3314(s16 arg0) {
    EndNode *p;

    for (p = D_800AF3CC; p->next != 0; p = p->next) {
        if (p->id == arg0) {
            return p;
        }
    }
    return 0;
}

void func_800A3368(EndActor *p) {
    s32 d[3];

    if (p->flags & 0x10) {
        if (func_800A379C(p->pad1C, &p->tx, d, p->f4) != 0) {
            p->flags ^= 0x10;
        }
        p->px += d[0];
        p->py += d[1];
        p->pz += d[2];
        p->x = p->px / 0x1000;
        p->y = p->py / 0x1000;
        p->z = p->pz / 0x1000;
    }
}

void func_800A343C(EndFade *p) {
    s32 t;

    if (p->flags & 8) {
        p->r += p->dr;
        p->g += p->dg;
        p->b += p->db;
        t = p->timer - 1;
        p->timer = t;
        if ((s16)t == 0) {
            p->flags ^= 8;
            p->r = p->tr;
            p->g = p->tg;
            p->b = p->tb;
        }
    }
}

void func_800A34C4(EndActor *p) {
    u16 n;

    if (p->flags & 2) {
        n = *p->anim;
        if (p->f6 == 0) {
            p->f8++;
            if (p->f8 >= n) {
                if (p->flags & 4) {
                    p->f8 = 0;
                } else {
                    p->f8--;
                }
            }
            func_80036244(p->anim, p->f8);
            p->f6 = D_8003623C[1];
        }
        p->f6--;
    }
}

INCLUDE_ASM("../asm/us/ending/nonmatchings/text", func_800A358C);

s32 func_800A379C(EndModel *m, s32 *tgt, s32 *d, s32 scale) {
    s32 v[3];
    s32 t;

    v[0] = tgt[0] - m->pos[0];
    v[1] = tgt[1] - m->pos[1];
    v[2] = tgt[2] - m->pos[2];
    if (v[0] == 0) {
        t = 0x1000;
        if (v[1] < 0) {
            t = -0x1000;
        }
        d[0] = 0;
        d[1] = t;
        d[2] = 0;
    } else if (v[1] == 0) {
        t = 0x1000;
        if (v[0] < 0) {
            t = -0x1000;
        }
        d[0] = t;
        d[1] = 0;
        d[2] = 0;
    } else {
        func_8003A08C(v, d);
    }
    if ((u32)(v[0] + 2) < 4U && (u32)(v[1] + 2) < 4U) {
        if ((u32)(v[2] + 2) < 4U) {
            d[0] = v[0] << 12;
            d[1] = v[1] << 12;
            d[2] = v[2] << 12;
            return 1;
        }
    }
    if (scale != 0x1000) {
        d[0] = scale * d[0] / 4096;
        d[1] = scale * d[1] / 4096;
        d[2] = scale * d[2] / 4096;
    }
    return 0;
}
