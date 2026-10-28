#include "common.h"
#include "main/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
extern struct { s16 a; s16 pad; s32 b; s32 c; } D_8009A000;
M2C_UNK func_8002988C(M2C_UNK, M2C_UNK);
extern volatile s16 D_8009AC42[];
void func_80013800(void);
void func_80012A8C(s32 arg0);
void func_800138EC(void);

void func_80013800(void) {
    s32 a0;

    if (D_80071A58 == 3) {
        D_8009AC42[0]++;
        if (D_8009AC42[0] == 0x22) {
            D_8009AC40 = 0;
            D_80095DD4 = 0;
            D_80071A58 = 0;
        }
        func_80012840(2);
        a0 = 0x10;
    } else {
        D_8009AC42[0]++;
        if (D_8009AC42[0] == 0x12) {
            D_8009AC40 = 0;
            D_80095DD4 = 0;
            D_80071A58 = 0;
        }
        func_80012840(2);
        a0 = 0x20;
    }
    func_80012A8C(a0);
}

void func_800138EC(void) {
    switch ((s16) *(volatile u16 *) (D_8009AC2B + 0x15)) {
    case 0:
        D_8009AC2B[1] = 0;
        D_8009AC4C = 0;
        D_8009AC4E = 0;
        D_8009AC50 = 0;
        break;
    case 1:
        func_80012840(2);
        func_800134F4();
        func_80012DB0(0x100 - *(volatile u16 *) (D_8009AC2B + 0x1B), 0x100 - (*(volatile u16 *) &D_8009AC48), 0x100 - (*(volatile u16 *) &D_8009AC4A));
        break;
    case 2:
        func_80012840(2);
        func_80013564();
        func_80012DB0(0x100 - *(volatile u16 *) (D_8009AC2B + 0x1B), 0x100 - (*(volatile u16 *) &D_8009AC48), 0x100 - (*(volatile u16 *) &D_8009AC4A));
        break;
    case 7:
        func_80012840(2);
        func_800134F4();
        func_800131B8(0x100 - *(volatile u16 *) (D_8009AC2B + 0x1B), 0x100 - (*(volatile u16 *) &D_8009AC48), 0x100 - (*(volatile u16 *) &D_8009AC4A));
        break;
    case 8:
        func_80012840(2);
        func_80013564();
        func_800131B8(0x100 - *(volatile u16 *) (D_8009AC2B + 0x1B), 0x100 - (*(volatile u16 *) &D_8009AC48), 0x100 - (*(volatile u16 *) &D_8009AC4A));
        break;
    case 3:
        D_8009AC42[0]++;
        if (D_8009AC42[0] == 0x22) {
            D_8009AC40 = 0;
            D_80095DD4 = 0;
        } else {
            func_80012840(2);
            func_80012A8C(0x10);
        }
        break;
    case 13:
        D_8009AC42[0]++;
        if (D_8009AC42[0] == 0x12) {
            D_8009AC40 = 0;
            D_80095DD4 = 0;
        } else {
            func_80012840(2);
            func_80012A8C(0x20);
        }
        break;
    case 4:
        D_8009AC2B[1] = 1;
        break;
    case 5:
        func_80012840(1);
        func_800134F4();
        func_80012DB0(*(volatile u16 *) (D_8009AC2B + 0x1B), (*(volatile u16 *) &D_8009AC48), (*(volatile u16 *) &D_8009AC4A));
        break;
    case 6:
        D_8009AC2B[1] = 0;
        func_80012840(1);
        func_80013564();
        func_80012DB0((*(volatile u16 *) &D_8009AC46), (*(volatile u16 *) &D_8009AC48), (*(volatile u16 *) &D_8009AC4A));
        break;
    case 9:
        func_80012840(1);
        func_800134F4();
        func_800131B8(*(volatile u16 *) (D_8009AC2B + 0x1B), (*(volatile u16 *) &D_8009AC48), (*(volatile u16 *) &D_8009AC4A));
        break;
    case 10:
        D_8009AC2B[1] = 0;
        func_80012840(1);
        func_80013564();
        func_800131B8((*(volatile u16 *) &D_8009AC46), (*(volatile u16 *) &D_8009AC48), (*(volatile u16 *) &D_8009AC4A));
        break;
    case 11:
        func_80012840(1);
        func_80013624();
        break;
    case 12:
        func_80012840(2);
        func_80013624();
        break;
    }
}
