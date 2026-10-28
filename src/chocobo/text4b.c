#include "common.h"
#include "chocobo/decls.h"

s32 func_800AD9D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u16 *tab;
    u32 pass;
    s32 t30;
    s32 t38;
    s32 t40;
    s32 t48;
    u32 *mat;
    u8 *out;
    u8 *fp;
    u8 *src;
    u32 i;
    u32 n;
    u32 e0;
    u32 e1;
    u32 e2;
    u32 e3;
    u32 idx0;
    u32 idx1;
    u32 idx2;
    u32 idx3;
    u32 fl0;
    u32 fl1;
    u32 fl2;
    u32 fl3;
    s32 ctoff0;
    s32 ctoff1;
    s32 ctoff2;
    s32 ctoff3;
    u32 m0;
    u32 m1;
    u32 m2;
    u32 m3;
    s32 du0;
    s32 du1;
    s32 du2;
    s32 du3;
    s32 dv0;
    s32 dv1;
    s32 dv2;
    s32 dv3;
    FdPrGT4 *gt4;
    FdPrGT3 *gt3;
    FdPrFT4 *ft4;
    FdPrFT3 *ft3;
    FdPrF *pf;
    FdPrG3 *g3;
    FdPrG4 *g4;

    mat = (u32 *)(((FdPrimHdr *)arg0)->off12 + ((FdPrimHdr *)arg0)->base);
    tab = (u16 *)(((FdPrimHdr *)arg0)->off10 + ((FdPrimHdr *)arg0)->base);
    if (arg2 != 0) {
        ((FdPrimHdr *)arg0)->base = arg0 + 0x20;
    }
    ((FdPrimHdr *)arg0)->out = arg1;
    t30 = (arg3 % 4) << 6;
    t38 = (arg3 / 4) << 5;
    t40 = (arg3 - arg3 / 8 * 8) << 5;
    t48 = (arg3 / 8) << 5;
    pass = 0;
    do {
        out = (u8 *)arg1;
        fp = (u8 *)(((FdPrimHdr *)arg0)->off14 + ((FdPrimHdr *)arg0)->base);
        if (pass != 0) {
            out += ((FdPrimHdr *)arg0)->off16;
        }
        src = (u8 *)(((FdPrimHdr *)arg0)->offE + ((FdPrimHdr *)arg0)->base);
        /* the << 4 >> 4 pairs below are no-ops that pad the loops: they decide which constants GCC hoists */
        n = ((FdPrimHdr *)arg0)->n[0];
        for (i = 0; i < n; i++, out += 0x34, src += 0x18) {
            gt4 = (FdPrGT4 *)out;
            *(u32 *)gt4->rgb0 = ((FdSrcGT4 *)src)->c[0];
            *(u32 *)gt4->rgb1 = ((FdSrcGT4 *)src)->c[1];
            *(u32 *)gt4->rgb2 = ((FdSrcGT4 *)src)->c[2];
            *(u32 *)gt4->rgb3 = ((FdSrcGT4 *)src)->c[3];
            idx0 = ((FdSrcGT4 *)src)->idx;
            *(u16 *)gt4->uv0 = tab[idx0 & 0xFF];
            *(u16 *)gt4->uv1 = tab[(idx0 & 0xFF00) >> 8];
            *(u16 *)gt4->uv2 = tab[(idx0 >> 16) & 0xFF];
            *(u16 *)gt4->uv3 = tab[idx0 >> 24];
            fl0 = *fp++;
            e0 = mat[fl0 & 0xF];
            ctoff0 = arg3 & -((e0 & 0x3F) != 2);
            gt4->clut = (((e0 << 1) >> 23) + ctoff0) << 6 | ((e0 >> 16) & 0x3F);
            if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
                gt4->tpage = ((e0 & 0xC0) * 8) | ((fl0 * 4) & 0x180) | (((((e0 >> 12) & 1) << 8) & 0x100) >> 3) | ((e0 & 0xF00) >> 8);
            } else {
                gt4->tpage = ((e0 & 0xC0) * 2) | (fl0 & 0x60) | (((((e0 >> 12) & 1) << 8) & 0x100) >> 4) | ((e0 & 0xF00) >> 8) | (((((e0 >> 12) & 1) << 8) & 0x200) << 2);
            }
            m0 = e0 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 & 0x3F;
            if (m0 == 0) {
                du0 = t30;
                dv0 = t38;
            } else {
                dv0 = 0;
                if (m0 == 1) {
                    du0 = t40;
                    dv0 = t48;
                } else {
                    du0 = 0;
                }
            }
            gt4->len = 12;
            gt4->code = 0x3C;
            gt4->uv0[0] += du0;
            gt4->uv0[1] += dv0;
            gt4->uv1[0] += du0;
            gt4->uv1[1] += dv0;
            gt4->uv2[0] += du0;
            gt4->uv2[1] += dv0;
            gt4->uv3[0] += du0;
            gt4->uv3[1] += dv0;
            if (fl0 & 0x10) {
                gt4->code = 0x3E;
            }
        }
        n = ((FdPrimHdr *)arg0)->n[1];
        for (i = 0; i < n; i++, out += 0x28, src += 0x14) {
            gt3 = (FdPrGT3 *)out;
            *(u32 *)gt3->rgb0 = ((FdSrcGT3 *)src)->c[0];
            *(u32 *)gt3->rgb1 = ((FdSrcGT3 *)src)->c[1];
            *(u32 *)gt3->rgb2 = ((FdSrcGT3 *)src)->c[2];
            idx1 = ((FdSrcGT3 *)src)->idx;
            *(u16 *)gt3->uv0 = tab[idx1 & 0xFF];
            *(u16 *)gt3->uv1 = tab[(idx1 & 0xFF00) >> 8];
            *(u16 *)gt3->uv2 = tab[(idx1 >> 16) & 0xFF];
            fl1 = *fp++;
            e1 = mat[fl1 & 0xF];
            ctoff1 = arg3 & -((e1 & 0x3F) != 2);
            gt3->clut = (((e1 << 1) >> 23) + ctoff1) << 6 | ((e1 >> 16) & 0x3F);
            if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
                gt3->tpage = ((e1 & 0xC0) * 8) | ((fl1 * 4) & 0x180) | (((((e1 >> 12) & 1) << 8) & 0x100) >> 3) | ((e1 & 0xF00) >> 8);
            } else {
                gt3->tpage = ((e1 & 0xC0) * 2) | (fl1 & 0x60) | (((((e1 >> 12) & 1) << 8) & 0x100) >> 4) | ((e1 & 0xF00) >> 8) | (((((e1 >> 12) & 1) << 8) & 0x200) << 2);
            }
            m1 = e1 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 & 0x3F;
            if (m1 == 0) {
                du1 = t30;
                dv1 = t38;
            } else {
                dv1 = 0;
                if (m1 == 1) {
                    du1 = t40;
                    dv1 = t48;
                } else {
                    du1 = 0;
                }
            }
            gt3->len = 9;
            gt3->code = 0x34;
            gt3->uv0[0] += du1;
            gt3->uv0[1] += dv1;
            gt3->uv1[0] += du1;
            gt3->uv1[1] += dv1;
            gt3->uv2[0] += du1;
            gt3->uv2[1] += dv1;
            if (fl1 & 0x10) {
                gt3->code = 0x36;
            }
        }
        n = ((FdPrimHdr *)arg0)->n[2];
        for (i = 0; i < n; i++, out += 0x28, src += 0xC) {
            ft4 = (FdPrFT4 *)out;
            *(u32 *)ft4->rgb0 = ((FdSrcFT *)src)->c;
            idx2 = ((FdSrcFT *)src)->idx;
            *(u16 *)ft4->uv0 = tab[idx2 & 0xFF];
            *(u16 *)ft4->uv1 = tab[(idx2 & 0xFF00) >> 8];
            *(u16 *)ft4->uv2 = tab[(idx2 >> 16) & 0xFF];
            *(u16 *)ft4->uv3 = tab[idx2 >> 24];
            fl2 = *fp++;
            e2 = mat[fl2 & 0xF];
            ctoff2 = arg3 & -((e2 & 0x3F) != 2);
            ft4->clut = (((e2 << 1) >> 23) + ctoff2) << 6 | ((e2 >> 16) & 0x3F);
            if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
                ft4->tpage = ((e2 & 0xC0) * 8) | ((fl2 * 4) & 0x180) | (((((e2 >> 12) & 1) << 8) & 0x100) >> 3) | ((e2 & 0xF00) >> 8);
            } else {
                ft4->tpage = ((e2 & 0xC0) * 2) | (fl2 & 0x60) | (((((e2 >> 12) & 1) << 8) & 0x100) >> 4) | ((e2 & 0xF00) >> 8) | (((((e2 >> 12) & 1) << 8) & 0x200) << 2);
            }
            m2 = e2 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 & 0x3F;
            if (m2 == 0) {
                du2 = t30;
                dv2 = t38;
            } else {
                dv2 = 0;
                if (m2 == 1) {
                    du2 = t40;
                    dv2 = t48;
                } else {
                    du2 = 0;
                }
            }
            ft4->len = 9;
            ft4->code = 0x2C;
            ft4->uv0[0] += du2;
            ft4->uv0[1] += dv2;
            ft4->uv1[0] += du2;
            ft4->uv1[1] += dv2;
            ft4->uv2[0] += du2;
            ft4->uv2[1] += dv2;
            ft4->uv3[0] += du2;
            ft4->uv3[1] += dv2;
            if (fl2 & 0x10) {
                ft4->code = 0x2E;
            }
        }
        n = ((FdPrimHdr *)arg0)->n[3];
        for (i = 0; i < n; i++, out += 0x20, src += 0xC) {
            ft3 = (FdPrFT3 *)out;
            *(u32 *)ft3->rgb0 = ((FdSrcFT *)src)->c;
            idx3 = ((FdSrcFT *)src)->idx;
            *(u16 *)ft3->uv0 = tab[idx3 & 0xFF];
            *(u16 *)ft3->uv1 = tab[(idx3 & 0xFF00) >> 8];
            *(u16 *)ft3->uv2 = tab[(idx3 >> 16) & 0xFF];
            fl3 = *fp++;
            e3 = mat[fl3 & 0xF];
            ctoff3 = arg3 & -((e3 & 0x3F) != 2);
            ft3->clut = (((e3 << 1) >> 23) + ctoff3) << 6 | ((e3 >> 16) & 0x3F);
            if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
                ft3->tpage = ((e3 & 0xC0) * 8) | ((fl3 * 4) & 0x180) | (((((e3 >> 12) & 1) << 8) & 0x100) >> 3) | ((e3 & 0xF00) >> 8);
            } else {
                ft3->tpage = ((e3 & 0xC0) * 2) | (fl3 & 0x60) | (((((e3 >> 12) & 1) << 8) & 0x100) >> 4) | ((e3 & 0xF00) >> 8) | (((((e3 >> 12) & 1) << 8) & 0x200) << 2);
            }
            m3 = e3 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 << 4 >> 4 & 0x3F;
            if (m3 == 0) {
                du3 = t30;
                dv3 = t38;
            } else {
                dv3 = 0;
                if (m3 == 1) {
                    du3 = t40;
                    dv3 = t48;
                } else {
                    du3 = 0;
                }
            }
            ft3->len = 7;
            ft3->code = 0x24;
            ft3->uv0[0] += du3;
            ft3->uv0[1] += dv3;
            ft3->uv1[0] += du3;
            ft3->uv1[1] += dv3;
            ft3->uv2[0] += du3;
            ft3->uv2[1] += dv3;
            if (fl3 & 0x10) {
                ft3->code = 0x26;
            }
        }
        n = ((FdPrimHdr *)arg0)->n[4];
        for (i = 0; i < n; i++, out += 0x14, src += 8) {
            pf = (FdPrF *)out;
            *(u32 *)pf->rgb0 = ((FdSrcF *)src)->c;
            pf->len = 4;
            pf->code = 0x20;
        }
        n = ((FdPrimHdr *)arg0)->n[5];
        for (i = 0; i < n; i++, out += 0x18, src += 8) {
            pf = (FdPrF *)out;
            *(u32 *)pf->rgb0 = ((FdSrcF *)src)->c;
            pf->len = 5;
            pf->code = 0x28;
        }
        n = ((FdPrimHdr *)arg0)->n[6];
        for (i = 0; i < n; i++, out += 0x1C, src += 0x10) {
            g3 = (FdPrG3 *)out;
            *(u32 *)g3->rgb0 = ((FdSrcG3 *)src)->c[0];
            *(u32 *)g3->rgb1 = ((FdSrcG3 *)src)->c[1];
            *(u32 *)g3->rgb2 = ((FdSrcG3 *)src)->c[2];
            g3->len = 6;
            g3->code = 0x30;
        }
        n = ((FdPrimHdr *)arg0)->n[7];
        for (i = 0; i < n; i++, out += 0x24, src += 0x14) {
            g4 = (FdPrG4 *)out;
            *(u32 *)g4->rgb0 = ((FdSrcG4 *)src)->c[0];
            *(u32 *)g4->rgb1 = ((FdSrcG4 *)src)->c[1];
            *(u32 *)g4->rgb2 = ((FdSrcG4 *)src)->c[2];
            *(u32 *)g4->rgb3 = ((FdSrcG4 *)src)->c[3];
            g4->len = 8;
            g4->code = 0x38;
        }
        pass++;
    } while (pass < 2);
    return arg1 + ((FdPrimHdr *)arg0)->off16 * 2;
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800AE534);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800AE7D4);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800AF11C);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800AF9E4);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800AFC64);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800AFDBC);

s32 func_800B00DC(WmHdr3 *arg0, u8 *arg1) {
    u32 i;
    u32 cnt;
    s32 pad[2];
    s32 q;
    s16 x;
    s16 y;
    s16 z;

    cnt = arg0->cnt;
    q = arg0->off + arg0->base;
    x = (arg1[1] << 8) | arg1[0];
    y = (arg1[3] << 8) | arg1[2];
    z = (arg1[5] << 8) | arg1[4];
    *(s32 *)0x1F800200 = arg1[6];
    for (i = 0; i < cnt; i++) {
        func_800B01B0(q + i * 0x20, x, y, z);
    }
    return 1;
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800B01B0);

s32 func_800B0E7C(WmHdr3 *arg0, u8 *arg1) {
    ChoBlk *q;
    ChoBlk *blk;
    u8 *p;
    u32 flag;
    u32 n;
    u32 i;
    u32 j;
    u32 k;

    q = (ChoBlk *)(arg0->off + arg0->base);
    flag = *arg1;
    for (k = 0; k < arg0->cnt; k++) {
        blk = &q[k];
        for (j = 0; j < 2; j++) {
            p = blk->base;
            if (j != 0) {
                p += blk->off;
            }
            n = blk->n[0];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x34;
            }
            n = blk->n[1];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x28;
            }
            n = blk->n[2];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x28;
            }
            n = blk->n[3];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x20;
            }
            n = blk->n[4];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x14;
            }
            n = blk->n[5];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x18;
            }
            n = blk->n[6];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x1C;
            }
            n = blk->n[7];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x24;
            }
        }
    }
    return 1;
}
