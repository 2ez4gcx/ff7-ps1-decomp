#include "common.h"
#include "main/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
extern struct { s16 a; s16 pad; s32 b; s32 c; } D_8009A000;
M2C_UNK func_8002988C(M2C_UNK, M2C_UNK);
extern volatile s16 D_8009AC42[];
void func_80013800(void);
void func_80012A8C(s32 arg0);

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

INCLUDE_ASM("../asm/us/main/nonmatchings/text1b", func_800138EC);
