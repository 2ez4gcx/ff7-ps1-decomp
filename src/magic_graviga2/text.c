#include "common.h"
#include "magic_graviga2/decls.h"

void func_801B0000(void) {
    func_801B1D44();
}

INCLUDE_ASM("../asm/us/magic_graviga2/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_graviga2/nonmatchings/text", func_801B09D0);

INCLUDE_ASM("../asm/us/magic_graviga2/nonmatchings/text", func_801B0C78);

INCLUDE_ASM("../asm/us/magic_graviga2/nonmatchings/text", func_801B0CF8);

INCLUDE_ASM("../asm/us/magic_graviga2/nonmatchings/text", func_801B0DE8);

INCLUDE_ASM("../asm/us/magic_graviga2/nonmatchings/text", func_801B0EDC);

INCLUDE_ASM("../asm/us/magic_graviga2/nonmatchings/text", func_801B1220);

INCLUDE_ASM("../asm/us/magic_graviga2/nonmatchings/text", func_801B1520);

INCLUDE_ASM("../asm/us/magic_graviga2/nonmatchings/text", func_801B183C);

INCLUDE_ASM("../asm/us/magic_graviga2/nonmatchings/text", func_801B19C0);

INCLUDE_ASM("../asm/us/magic_graviga2/nonmatchings/text", func_801B1AB8);

void func_801B1CB8(void) {
    M2C_UNK *var_v1;
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    var_v1 = &D_801B1DF0;
    if (temp_s0->unk2 == 0) {
        var_v1 = &D_801D3C74;
    }
    D_801E3C74 = var_v1;
    temp_s0->unk2 = (u16) temp_s0->unk2 ^ 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 4);
        temp_s0->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_graviga2/nonmatchings/text", func_801B1D44);
