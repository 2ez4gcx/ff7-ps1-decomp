#include "common.h"
#include "magic_lgirl/decls.h"

s32 func_801B0054(void) {
    func_801B0C9C();
    return 0;
}

void func_801B0078(MgRing *r, s32 v) {
    s32 head;
    s32 tail;
    s32 count;
    s32 size;
    s32 last;

    tail = r->tail;
    last = r->head;
    count = r->count;
    r->prev = r->last;
    size = r->size;
    r->last = last;
    head = last;
    r->buf[head] = v;
    head++;
    count++;
    if (head >= size) {
        head = 0;
    }
    if (count >= size) {
        count = size;
    }
    if (head == tail) {
        tail++;
        count--;
        if (tail >= size) {
            tail = 0;
        }
    }
    r->head = head;
    r->tail = tail;
    r->count = count;
    r->size = size;
}

INCLUDE_ASM("../asm/us/magic_lgirl/nonmatchings/text", func_801B00F8);

INCLUDE_ASM("../asm/us/magic_lgirl/nonmatchings/text", func_801B0270);

INCLUDE_ASM("../asm/us/magic_lgirl/nonmatchings/text", func_801B07D4);

INCLUDE_ASM("../asm/us/magic_lgirl/nonmatchings/text", func_801B093C);

INCLUDE_ASM("../asm/us/magic_lgirl/nonmatchings/text", func_801B0BFC);

INCLUDE_RODATA("../asm/us/magic_lgirl/nonmatchings/text", D_801B0000);

void func_801B0C9C(arg0, arg1) {
    D_801E8EC0 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B0D28, 0, 0, 0);
    func_800BBEAC(&func_801B0BFC);
    D_801E8EC4 = arg0;
    D_801E8EC8 = arg1;
}
