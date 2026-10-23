#include "common.h"
#include "battle/decls.h"

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1b", func_800A2BF4);

void func_800A2CC4(s32 arg0) {
    func_800B10F0(M2C_FIELD(D_80063014, s32 *, 0), arg0, M2C_FIELD(D_80063014, s32 *, 0x28), M2C_FIELD(D_80063014, s32 *, 0x24), M2C_FIELD(D_80063014, s32 *, 0x98), 0, 0);
}

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text1b", D_800A01A8);

u8 func_800A2D0C(void) {
    s32 i;
    u8 v;

    i = M2C_FIELD(D_80063014, s32 *, 0x208);
    if (i < 3) {
        v = D_800A01A8[M2C_FIELD(D_80063014, s32 *, 0xCC)];
    } else {
        v = D_800F83F1[i][0];
    }
    return v;
}

void func_800A2D68(s32 arg0) {
    s32 i;
    u8 *p;

    for (i = 0; i < 8; i++) {
        p = (u8 *) D_80063014 + i;
        if (p[0xD0] == 0xFF) {
            p[0xD0] = arg0;
            break;
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1b", func_800A2DB0);

void func_800A2EFC(void) {
    D_800F3950 = D_800F3944;
    D_800F3954 = D_800F3948;
}

void func_800A2F24(void) {
    D_800F3944 = D_800F3950;
    D_800F3948 = D_800F3954;
}

BEnt12 *func_800A2F4C(void) {
    BEnt12 *p;

    p = &((BEnt12 *)&D_80163798)[D_800F3944];
    p->pad[1] = 0;
    p->pad[0] = 0;
    p->f = D_800F3948;
    if (D_800F3944 < 0x40) {
        D_800F3944 += 1;
    } else {
        func_800155A4(0x28);
    }
    return p;
}

s8 *func_800A2FD0(void) {
    S12b *p;

    p = &D_800FA9D0[D_800F3948];
    M2C_SFIELD(p, s8 *, 3) = -1;
    if (D_800F3948 < 0x80) {
        D_800F3948 += 1;
    } else {
        func_800155A4(0x28);
    }
    return &p->a;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1b", func_800A304C);

void func_800A311C(u8 *arg0) {
    E0E *p;

    p = &D_800F9F3C[D_800F394C];
    arg0[3] = D_800F394C;
    p->a = (s8)arg0[0];
    p->d = -1;
    p->e = -1;
    D_800F394C = (D_800F394C + 1) & 0x7F;
}

void func_800A317C(void) {
    *func_800A2FD0() = -1;
}

s32 func_800A31A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    BEnt12 *p;

    p = func_800A2F4C();
    p->a = arg0;
    p->b = arg1;
    p->c = arg2;
    p->d = arg3;
    p->e = -1;
    p->f = -1;
    return (s32)p;
}

void func_800A3208(s32 arg0, s32 arg1) {
    S12 *p;

    if (D_800F3944 != 0) {
        p = &D_8016378C[D_800F3944];
        p->c = arg0;
        p->b = arg1;
    }
}

void func_800A3240(void) {
    if (D_800F3944 != 0) {
        D_801637A0[D_800F3944 - 1].a = -1;
    }
}

void func_800A3278(void) {
    D_800F3944 = 0;
    D_800F3948 = 0;
    D_80163798 = -1;
}

void func_800A329C(void) {
    if (D_800F3944 != 0) {
        D_800F3944 -= 1;
    }
}

void func_800A32C0(s32 arg0) {
    s32 v;
    if (D_800F7DAA != 0) {
        if (arg0 != 0) {
            if (D_800F7DBA == 6) {
                v = 1;
                if (D_800F6B9A != D_800F6BA1) v = 3;
                func_800A7254(0, 0, 7, v);
            }
        } else if (func_800A37F8(-1) != 0) {
            func_800A7254(0, 0, 7, 0);
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1b", func_800A3354);

void func_800A345C(void) {
    if (D_800F3944 != 0) {
        func_800A3354();
    }
}

void func_800A3488(s32 arg0) {
    S12b *p;
    s32 i;

    for (i = 0; i < 128; i++) {
        p = &D_800FA9D0[i];
        if (p->a == arg0) {
            p->b &= ~4;
        }
    }
}

void func_800A34CC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    S12b *p;
    s32 i;

    for (i = 0; i < 0x80; i++) {
        p = &D_800FA9D0[i];
        if (p->a == arg0 && (s8)p->pad2[0] == arg1) {
            if (arg3 != 1 || (p->b & 4)) {
                p->pad2[0] = arg2;
            }
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1b", func_800A3534);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text1b", func_800A35F8);

s32 func_800A37F8(s32 arg0) {
    s32 r;

    r = 0;
    if (arg0 < 0) {
        r = D_800F39E0;
    } else {
        D_800F39E0 = arg0;
        D_800F39E4 = 0;
    }
    return r;
}
