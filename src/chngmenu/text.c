#include "common.h"
#include "chngmenu/decls.h"

void func_801D0000(void) {
    u8 pad[8];

    func_80026448(&D_801D01E0, 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0U);
    func_80026448((u8 *)&D_801D01E0 + 0x12, 0, 0, 1, 3, 0, 0, 1, 9, 0, 0, 0, 0, 0U);
    D_801D01C4 = 0;
}

void func_801D00C4(void) {
    u8 pad[16];
    s32 i;
    u8 *p;

    func_800230C4(D_80062F58);
    if (D_801D01C4 == 0) {
        func_8001EB2C(0, D_801D01D2 + (D_801D01EB << 6) + 0x20);
    }
    func_80026F44(0x10, 0xB, D_801D01D8, 7);
    i = 0;
    p = D_801D01C8;
    do {
        func_8001E040(p);
        i++;
        p += 8;
    } while (i < 2);
    func_800264A8(D_801D01E0 + D_801D01C4 * 0x12);
    if (D_80062D7E & 0x40) {
        func_8002305C(5, 0);
        func_8002120C(0);
    }
}

void func_801D01BC(void) {
}
