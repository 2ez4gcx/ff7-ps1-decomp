#include "common.h"
#include "brom/decls.h"

void func_800A0000(void) {
    func_80043938(0);
    func_80043BA8(0);
    func_80043D3C(1);
    func_800438D4(&D_800A0728, 0, 0xE8, 0x140, 0xF0);
    func_80043814(&D_800A06CC, 0, 0xF0, 0x140, 0xE0);
    D_800A0739 = 0;
    D_800A06E3 = 1;
    D_800A06E2 = 0;
    D_800A06E4 = 0;
    D_800A06E0 = 0;
    func_8003CEDC(0);
    func_800444AC(&D_800A0728);
    func_800443B0(&D_800A06CC);
}

void func_800A00CC(void) {
    while (D_80095DD4 != 0) {
    }
    D_80075DEC = 1;
    func_800A0000();
    func_800A01A0();
    if (*(u16 *)D_800707BE != 0) {
        D_8009C560 = 2;
        return;
    }
    D_8009C560 = 1;
    func_80014540();
}

void func_800A015C(void) {
    if (func_80017108(0x801B0000, 0x801C0000) > 0) {
        func_800A0534(0x801C0000);
        func_800A05D4(0x801C0000, -1, -1);
    }
}

void func_800A01A0(void) {
    u8 buf[0x60];
    s32 i;
    s32 quit;
    s32 prev;
    s32 cnt;
    s32 side;
    s32 id;
    s32 pad;
    s32 pressed;
    s32 n;
    u32 j;

    id = D_800707BC;
    D_800707BE[0] = 0;
    quit = 0;
    func_8001C980();
    func_8001C980();
    for (i = 0; i < 3; i++) {
        func_80020058(i);
        func_8001786C(i);
    }
    func_80017678();
    while (quit == 0) {
        cnt = 0;
        prev = 0;
        func_80014578(4, 0x801B0000, (s32)func_800A015C);
        func_800145BC(NULL);
        side = 0;
        while (1) {
            pad = func_8001C808();
            pressed = (prev ^ pad) & pad;
            func_8004418C(&D_800A473C[side], 1);
            func_80026A00((s32)&D_800A473C[side]);
            func_800269C0((s32)D_800A073C[side]);
            if (prev == pad) {
                if (cnt++ >= 9) {
                    pressed = prev;
                }
            } else {
                cnt = 0;
            }
            prev = pad;
            if (pressed & 0x100) {
                quit = 1;
                break;
            }
            if (pressed & 0x820) {
                *(u16 *)D_800707BE = 0x8000;
                quit = 1;
                break;
            }
            if (!(pressed & 0x20)) {
                if (pressed & 0x10) {
                    func_80020058(0);
                    func_8001786C(0);
                    func_80020058(1);
                    func_8001786C(1);
                    func_80020058(2);
                    func_8001786C(2);
                    func_80017678();
                    func_80025174();
                    func_80026090();
                    func_80020058(0);
                    func_8001786C(0);
                    func_80020058(1);
                    func_8001786C(1);
                    func_80020058(2);
                    func_8001786C(2);
                    func_80017678();
                    break;
                }
                if (pressed & 0x1000) {
                    id++;
                } else if (pressed & 0x4000) {
                    id--;
                } else if (pressed & 0x8000) {
                    if (id < 0) {
                        id = 0;
                    } else {
                        id += 10;
                    }
                } else if (pressed & 0x2000) {
                    id -= 10;
                }
            }
            if (id < 0) {
                id = 0;
            } else if (id >= 0x400) {
                id = 0x3FF;
            }
            n = id;
            for (j = 0; j < 8; j++) {
                buf[j] = D_800A06BC[j];
            }
            i = 4;
            while (n != 0) {
                i--;
                buf[i] += n % 10;
                n /= 10;
            }
            func_80027354(D_800A06C4.x, 0xB2, D_800A06B4, 0);
            ((void (*)(s32, s32, u8 *, s32))func_80027354)(D_800A06C4.x + 0x30, 0xB2, buf, 0);
            func_80043F6C(&D_800A06C4, 0xFF, 0xFF, 0xFF);
            func_8004433C((s32)&D_800A473C[side]);
            side ^= 1;
            func_80043DD8(0);
            func_8003CEDC(2);
        }
    }
    D_800707BC = id;
}

u32 func_800A0514(u32 arg0) {
    u32 r, g, b;
    g = arg0 & 0x3E0;
    r = arg0 & 0x1F;
    b = (arg0 & 0x7C00) >> 10;
    return (r << 10) | (b | g);
}

void func_800A0534(BromImg *img) {
    u32 tw, th;
    u16 w, h;
    s32 i;
    u32 c;

    tw = img->w;
    th = img->h;
    w = (tw >> 8) | (tw << 8);
    h = (th >> 8) | (th << 8);
    for (i = 0; i < w * h; i++) {
        c = img->data[i];
        img->data[i] = func_800A0514((u16)((c >> 8) | (c << 8)));
    }
}

s32 func_800A05D4(BromImg *arg0, s32 x, s32 y) {
    BromRect rect;
    u32 tw;
    u32 th;
    u16 w;
    u16 h;
    s32 v;
    s32 ry;

    if ((v = arg0->magic[0]) != 0x4152) {
        return v;
    }
    if ((v = arg0->magic[1]) != 0x2057) {
        return v;
    }
    if ((v = arg0->magic[2]) != 0x4752) {
        return v;
    }
    if ((v = arg0->magic[3]) != 0x2042) {
        return v;
    }
    tw = arg0->w;
    th = arg0->h;
    w = (tw >> 8) | (tw << 8);
    h = (th >> 8) | (th << 8);
    if (x == -1) {
        x = (0x140 - w) / 2;
    }
    ry = y + 0xE8;
    if (y == -1) {
        y = (0xF0 - h) / 2;
        ry = y + 0xE8;
    }
    rect.w = w;
    rect.x = x;
    rect.y = ry;
    rect.h = h;
    func_80044000(&rect, arg0->data);
    return 0;
}
