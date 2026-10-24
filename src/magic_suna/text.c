#include "common.h"
#include "magic_suna/decls.h"

INCLUDE_ASM("../asm/us/magic_suna/nonmatchings/text", func_801B006C);

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

INCLUDE_ASM("../asm/us/magic_suna/nonmatchings/text", func_801B01E0);

INCLUDE_ASM("../asm/us/magic_suna/nonmatchings/text", func_801B052C);

INCLUDE_ASM("../asm/us/magic_suna/nonmatchings/text", func_801B06FC);

INCLUDE_ASM("../asm/us/magic_suna/nonmatchings/text", func_801B08AC);

void func_801B0CD4(void) {
}

INCLUDE_ASM("../asm/us/magic_suna/nonmatchings/text", func_801B0CDC);
