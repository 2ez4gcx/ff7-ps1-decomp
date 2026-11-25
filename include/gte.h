#ifndef GTE_H
#define GTE_H

/* Inline GTE (cop2) sequences, the way the game's code has them: each macro is one `asm volatile` that produces the
 * game's instructions word for word, with the operand in the register GCC picks. $12 to $15 (t4 to t7) are the
 * scratch registers the sequences use. A volatile asm keeps its place relative to the other volatile asms and to
 * calls, so write the macros in the order the game executes them. Add a macro when a function needs a sequence that
 * is not here; keep the name of the PSY-Q macro it corresponds to (gte_ldv0, gte_rtps...) when there is one.
 */

/* rotation matrix (3x3 s16, 5 words) into control registers 0 to 4 */
#define gte_SetRotMatrix(m) \
    asm volatile("move $12,%0\n\tlw $13,0($12)\n\tlw $14,4($12)\n\tctc2 $13,$0\n\tctc2 $14,$1\n\t" \
                 "lw $13,8($12)\n\tlw $14,12($12)\n\tlw $15,16($12)\n\tctc2 $13,$2\n\tctc2 $14,$3\n\tctc2 $15,$4" \
                 : : "r"(m) : "$12", "$13", "$14", "$15")

/* vector 0 (3 s16: vxy in data register 0, vz in 1) */
#define gte_ldv0(v) \
    asm volatile("move $12,%0\n\tlwc2 $0,0($12)\n\tlwc2 $1,4($12)" : : "r"(v) : "$12")

/* the long vector in data registers 25 to 27 (MAC1 to MAC3) stored as three words */
#define gte_stlvnl(p) \
    asm volatile("move $12,%0\n\tswc2 $25,0($12)\n\tswc2 $26,4($12)\n\tswc2 $27,8($12)" : : "r"(p) : "$12", "memory")

/* GTE command with the two nops before it (cop2 imm25); mvmva: sf, mx, v, cv, lm */
#define gte_cmd(imm) asm volatile("nop\n\tnop\n\tcop2 %0" : : "i"(imm))
#define gte_mvmva(sf, mx, v, cv, lm) \
    gte_cmd(0x0400012 | ((sf) << 19) | ((mx) << 17) | ((v) << 15) | ((cv) << 13) | ((lm) << 10))

/* three vectors from six consecutive words (data registers 0 to 5) */
#define gte_ldv3c(r) \
    asm volatile("lwc2 $0,0(%0)\n\tlwc2 $1,4(%0)\n\tlwc2 $2,8(%0)\n\tlwc2 $3,12(%0)\n\tlwc2 $4,16(%0)\n\t" \
                 "lwc2 $5,20(%0)" : : "r"(r))

/* RTPT: perspective transform of the three vectors */
#define gte_rtpt() gte_cmd(0x0280030)

/* the three screen XY results (data registers 12 to 14) to three consecutive words */
#define gte_stsxy3c(r) \
    asm volatile("swc2 $12,0(%0)\n\tswc2 $13,4(%0)\n\tswc2 $14,8(%0)" : : "r"(r) : "memory")

/* move from / to a GTE control register (cfc2 / ctc2): n is the register number */
#define gte_cfc2(n, v) asm volatile("cfc2 %0,$" #n : "=r"(v))
#define gte_ctc2(n, v) asm volatile("ctc2 %0,$" #n : : "r"(v))

/* three vectors (xy word and z word each) from three pointers, as vectors 0 to 2 */
#define gte_ldv3(a, b, c) \
    asm volatile("lwc2 $0,0(%0)\n\tlwc2 $1,4(%0)\n\tlwc2 $2,0(%1)\n\tlwc2 $3,4(%1)\n\tlwc2 $4,0(%2)\n\t" \
                 "lwc2 $5,4(%2)" : : "r"(a), "r"(b), "r"(c))

/* the three screen XY results (data registers 12 to 14) to three pointers */
#define gte_stsxy3(a, b, c) \
    asm volatile("swc2 $12,0(%0)\n\tswc2 $13,0(%1)\n\tswc2 $14,0(%2)" : : "r"(a), "r"(b), "r"(c) : "memory")

/* average Z (SZ3, data register 19) divided by 4 to a word */
#define gte_stszotz(p) \
    asm volatile("mfc2 $12,$19\n\tnop\n\tsra $12,$12,2\n\tsw $12,0(%0)" : : "r"(p) : "$12", "memory")

/* the first two screen XY results to two consecutive words */
#define gte_stsxy2c(r) asm volatile("swc2 $12,0(%0)\n\tswc2 $13,4(%0)" : : "r"(r) : "memory")

/* hand-written pointer advance of the jet code: a += 0x18, b += 0xC through t0 and t1 ($8, $9) with the trapping add */
#define gte_adv18_c(a, b) \
    asm volatile("ori $8,$0,0x18\n\tori $9,$0,0xC\n\tadd %0,%0,$8\n\tadd %1,%1,$9" \
                 : "=r"(a), "=r"(b) : "0"(a), "1"(b) : "$8", "$9")

/* move to / from a GTE data register (mtc2 / mfc2): n is the register number; mfc2n has the nop the game puts after it */
#define gte_mtc2(n, v) asm volatile("mtc2 %0,$" #n : : "r"(v))
#define gte_mfc2(n, v) asm volatile("mfc2 %0,$" #n : "=r"(v))
#define gte_mfc2n(n, v) asm volatile("mfc2 %0,$" #n "\n\tnop" : "=r"(v))

/* GTE command with no nops before it (cop2 imm25) */
#define gte_cmd0(imm) asm volatile("cop2 %0" : : "i"(imm))

/* SQR 0 (square of IR1 to IR3, no shift) with the two nops, and GPF 0 without them */
#define gte_sqr0() gte_cmd(0x0A00428)
#define gte_gpf0() gte_cmd0(0x190003D)

/* GPF 1 (IR1 to IR3 times IR0, shifted) with the two nops */
#define gte_gpf1() gte_cmd(0x198003D)

/* rotation matrix (control registers 0 to 4) and translation vector (5 to 7) from a pointer register, as libgte's
 * SetRotMatrix and SetTransMatrix have them (no move of the pointer) */
#define gte_SetRotMatrix_d(m) \
    asm volatile("lw $12,0(%0)\n\tlw $13,4(%0)\n\tctc2 $12,$0\n\tctc2 $13,$1\n\tlw $12,8(%0)\n\tlw $13,12(%0)\n\t" \
                 "lw $14,16(%0)\n\tctc2 $12,$2\n\tctc2 $13,$3\n\tctc2 $14,$4" : : "r"(m) : "$12", "$13", "$14")
#define gte_SetTransMatrix(m) \
    asm volatile("lw $12,20(%0)\n\tlw $13,24(%0)\n\tctc2 $12,$5\n\tlw $14,28(%0)\n\tctc2 $13,$6\n\tctc2 $14,$7" \
                 : : "r"(m) : "$12", "$13", "$14")

/* vector 0 / vector 1 from a pointer register (xy word, z word) */
#define gte_ldv0c(v) asm volatile("lwc2 $0,0(%0)\n\tlwc2 $1,4(%0)" : : "r"(v))
#define gte_ldv1c(v) asm volatile("lwc2 $2,0(%0)\n\tlwc2 $3,4(%0)" : : "r"(v))

/* long vector (3 words) into IR1 to IR3 (data registers 9 to 11) from a pointer register, and the long vector
 * (MAC1 to MAC3, data registers 25 to 27) back to three words through a pointer register */
#define gte_ldlvl(r) \
    asm volatile("lwc2 $9,0(%0)\n\tlwc2 $10,4(%0)\n\tlwc2 $11,8(%0)" : : "r"(r))
#define gte_stlvnl_c(r) \
    asm volatile("swc2 $25,0(%0)\n\tswc2 $26,4(%0)\n\tswc2 $27,8(%0)" : : "r"(r) : "memory")

/* RTPS: perspective transform of vector 0, with the two nops */
#define gte_rtps() gte_cmd(0x0180001)

/* the way the game's SetXY-style code has them: the pointer is copied to t4 first ($12); average Z (SZ3 / 4) through
 * t5 to a word, the screen XY (data register 14) to a word */
#define gte_stszotz_m(p) \
    asm volatile("move $12,%0\n\tmfc2 $13,$19\n\tnop\n\tsra $13,$13,2\n\tsw $13,0($12)" \
                 : : "r"(p) : "$12", "$13", "memory")
#define gte_stsxy_m(p) asm volatile("move $12,%0\n\tswc2 $14,0($12)" : : "r"(p) : "$12", "memory")

/* translation vector (control registers 5 to 7) with the pointer copied to t4 first, like gte_SetRotMatrix */
#define gte_SetTransMatrix_m(m) \
    asm volatile("move $12,%0\n\tlw $13,20($12)\n\tlw $14,24($12)\n\tctc2 $13,$5\n\tlw $15,28($12)\n\tctc2 $14,$6\n\t" \
                 "ctc2 $15,$7" : : "r"(m) : "$12", "$13", "$14", "$15")

/* colour code (4 bytes) into the RGB register (data register 6) from a pointer register; the colour result (data
 * register 22, RGB2) to a word through a pointer register; DPCS (depth cue colour) with the two nops */
#define gte_ldrgb(r) asm volatile("lwc2 $6,0(%0)" : : "r"(r))
#define gte_strgb(r) asm volatile("swc2 $22,0(%0)" : : "r"(r) : "memory")
#define gte_dpcs() gte_cmd(0x0780010)

/* three vectors from three pointers / the three screen XY results to three pointers, each pointer copied to t4 to t6
 * ($12 to $14) by a statement of its own (the moves come out interleaved with the C computing the next pointer) */
#define gte_ldv3_m(a, b, c) \
    { \
        asm volatile("move $12,%0" : : "r"(a) : "$12"); \
        asm volatile("move $13,%0" : : "r"(b) : "$13"); \
        asm volatile("move $14,%0" : : "r"(c) : "$14"); \
        asm volatile("lwc2 $0,0($12)\n\tlwc2 $1,4($12)\n\tlwc2 $2,0($13)\n\tlwc2 $3,4($13)\n\tlwc2 $4,0($14)\n\t" \
                     "lwc2 $5,4($14)"); \
    }
#define gte_stsxy3_m(a, b, c) \
    { \
        asm volatile("move $12,%0" : : "r"(a) : "$12"); \
        asm volatile("move $13,%0" : : "r"(b) : "$13"); \
        asm volatile("move $14,%0" : : "r"(c) : "$14"); \
        asm volatile("swc2 $12,0($12)\n\tswc2 $13,0($13)\n\tswc2 $14,0($14)" : : : "memory"); \
    }

/* the three screen Z results (data registers 17 to 19) to three words through t4 */
#define gte_stsz3_m(p) \
    asm volatile("move $12,%0\n\tswc2 $17,0($12)\n\tswc2 $18,4($12)\n\tswc2 $19,8($12)" : : "r"(p) : "$12", "memory")

/* background colour (control registers 21 to 23), each component times 16 */
#define gte_SetBackColor(r, g, b) \
    asm volatile("move $12,%0\n\tmove $13,%1\n\tmove $14,%2\n\tsll $12,$12,4\n\tsll $13,$13,4\n\tsll $14,$14,4\n\t" \
                 "ctc2 $12,$21\n\tctc2 $13,$22\n\tctc2 $14,$23" : : "r"(r), "r"(g), "r"(b) : "$12", "$13", "$14")

/* the same background colour value in all three components (the game's three equal constants share one register) */
#define gte_SetBackColorN(v) \
    asm volatile("move $12,%0\n\tmove $13,%0\n\tmove $14,%0\n\tsll $12,$12,4\n\tsll $13,$13,4\n\tsll $14,$14,4\n\t" \
                 "ctc2 $12,$21\n\tctc2 $13,$22\n\tctc2 $14,$23" : : "r"(v) : "$12", "$13", "$14")

/* cfc2 with the nop the game puts after it; NCLIP with the two nops; the outer product (data register 24, MAC0) to a
 * word through a pointer register; the three screen XY results to offsets 8, 16 and 24 (polygon packets) */
#define gte_cfc2n(n, v) asm volatile("cfc2 %0,$" #n "\n\tnop" : "=r"(v))
#define gte_nclip() gte_cmd(0x1400006)
#define gte_stopz(p) asm volatile("swc2 $24,0(%0)" : : "r"(p) : "memory")
#define gte_stsxy3_8(r) \
    asm volatile("swc2 $12,8(%0)\n\tswc2 $13,16(%0)\n\tswc2 $14,24(%0)" : : "r"(r) : "memory")

/* the screen XY result (data register 14) to a word through a pointer register */
#define gte_stsxy(p) asm volatile("swc2 $14,0(%0)" : : "r"(p) : "memory")

/* AVSZ4 (average of the four Z values, to OTZ) with the two nops; OTZ (data register 7) to a word through a pointer */
#define gte_avsz4() gte_cmd(0x168002E)
#define gte_stotz(p) asm volatile("swc2 $7,0(%0)" : : "r"(p) : "memory")

/* MVMVA with no nops before it (sf, mx, v, cv, lm as gte_mvmva) */
#define gte_mvmva0(sf, mx, v, cv, lm) \
    gte_cmd0(0x0400012 | ((sf) << 19) | ((mx) << 17) | ((v) << 15) | ((cv) << 13) | ((lm) << 10))

/* three halfwords (u16 x, y, z) into IR1 to IR3 (data registers 9 to 11) through t4 to t6 */
#define gte_ldsv(r) \
    asm volatile("lhu $12,0(%0)\n\tlhu $13,2(%0)\n\tlhu $14,4(%0)\n\tmtc2 $12,$9\n\tmtc2 $13,$10\n\tmtc2 $14,$11" \
                 : : "r"(r) : "$12", "$13", "$14")

/* rotation (control registers 0 to 4) and translation (5 to 7) of a matrix from a pointer register through t5 to t7
 * ($13 to $15), the loads and ctc2 interleaved the way the game has them (libgte's SetRotMatrix and SetTransMatrix) */
#define gte_SetRotTrans_d(m) \
    asm volatile("lw $13,0(%0)\n\tlw $14,4(%0)\n\tctc2 $13,$0\n\tctc2 $14,$1\n\tlw $13,8(%0)\n\tlw $14,12(%0)\n\t" \
                 "lw $15,16(%0)\n\tctc2 $13,$2\n\tctc2 $14,$3\n\tctc2 $15,$4\n\tlw $13,20(%0)\n\tlw $14,24(%0)\n\t" \
                 "ctc2 $13,$5\n\tlw $15,28(%0)\n\tctc2 $14,$6\n\tctc2 $15,$7" \
                 : : "r"(m) : "$13", "$14", "$15", "memory")

/* column c (0 to 2) of a 3x3 s16 matrix (halfwords at 2c, 2c+6, 2c+12) into IR1 to IR3 through t5 to t7 */
#define gte_ldmcol(p, c) \
    asm volatile("lhu $13,%1(%0)\n\tlhu $14,%2(%0)\n\tlhu $15,%3(%0)\n\tmtc2 $13,$9\n\tmtc2 $14,$10\n\t" \
                 "mtc2 $15,$11" : : "r"(p), "i"((c) * 2), "i"((c) * 2 + 6), "i"((c) * 2 + 12) \
                 : "$13", "$14", "$15", "memory")

/* vector 0 from a vector packed as halfwords x at 0x14 and y at 0x18 plus the word z at 0x1C */
#define gte_ldv0t(p) \
    asm volatile("lhu $14,24(%0)\n\tlhu $13,20(%0)\n\tsll $14,$14,16\n\tor $13,$13,$14\n\tmtc2 $13,$0\n\t" \
                 "lwc2 $1,28(%0)" : : "r"(p) : "$13", "$14", "memory")

/* IR1 to IR3 (data registers 9 to 11) to three words at offsets o, o+4, o+8 of a pointer register */
#define gte_stir3(p, o) \
    asm volatile("swc2 $9,%1(%0)\n\tswc2 $10,%2(%0)\n\tswc2 $11,%3(%0)" \
                 : : "r"(p), "i"(o), "i"((o) + 4), "i"((o) + 8) : "memory")

/* NCCS: normal colour colour of vector 0, with the two nops */
#define gte_nccs() gte_cmd(0x108041B)

/* AVSZ3 and AVSZ4 (average Z of three / four points, to OTZ) with the two nops; the average Z (OTZ, data register 7)
 * to a word through a pointer register; the flag register (control register 31) to a word through t4 ($12) with the
 * nop the game puts after the cfc2 */
#define gte_avsz3() gte_cmd(0x158002D)
#define gte_avsz4() gte_cmd(0x168002E)
#define gte_stotz(p) asm volatile("swc2 $7,0(%0)" : : "r"(p) : "memory")
#define gte_stflg(p) asm volatile("cfc2 $12,$31\n\tnop\n\tsw $12,0(%0)" : : "r"(p) : "$12", "memory")

/* back colour (control registers 13 to 15) from three values, each times 16 (the shifts read the operands directly) */
#define gte_SetBackColor_k(r, g, b) \
    asm volatile("sll $12,%0,4\n\tsll $13,%1,4\n\tsll $14,%2,4\n\tctc2 $12,$13\n\tctc2 $13,$14\n\tctc2 $14,$15" \
                 : : "r"(r), "r"(g), "r"(b) : "$12", "$13", "$14")

/* the colour matrix (control registers 16 to 20) and the light matrix (8 to 12) from a pointer register through t4
 * to t6, like gte_SetRotMatrix_d */
#define gte_SetColorMatrix_d(m) \
    asm volatile("lw $12,0(%0)\n\tlw $13,4(%0)\n\tctc2 $12,$16\n\tctc2 $13,$17\n\tlw $12,8(%0)\n\tlw $13,12(%0)\n\t" \
                 "lw $14,16(%0)\n\tctc2 $12,$18\n\tctc2 $13,$19\n\tctc2 $14,$20" : : "r"(m) : "$12", "$13", "$14")
#define gte_SetLightMatrix_d(m) \
    asm volatile("lw $12,0(%0)\n\tlw $13,4(%0)\n\tctc2 $12,$8\n\tctc2 $13,$9\n\tlw $12,8(%0)\n\tlw $13,12(%0)\n\t" \
                 "lw $14,16(%0)\n\tctc2 $12,$10\n\tctc2 $13,$11\n\tctc2 $14,$12" : : "r"(m) : "$12", "$13", "$14")

/* IR1 to IR3 (data registers 9 to 11) to three halfwords at offsets 0, 6 and 12 of a pointer register (a matrix
 * column) through t4 to t6 */
#define gte_stir3h(p) \
    asm volatile("mfc2 $12,$9\n\tmfc2 $13,$10\n\tmfc2 $14,$11\n\tsh $12,0(%0)\n\tsh $13,6(%0)\n\tsh $14,12(%0)" \
                 : : "r"(p) : "$12", "$13", "$14", "memory")

/* vector 0 from a pointer register: the halfwords at 0 and 4 packed into data register 0, the word at 8 into 1 */
#define gte_ldv0w(p) \
    asm volatile("lhu $13,4(%0)\n\tlhu $12,0(%0)\n\tsll $13,$13,16\n\tor $12,$12,$13\n\tmtc2 $12,$0\n\t" \
                 "lwc2 $1,8(%0)" : : "r"(p) : "$12", "$13", "memory")

/* column c (0 to 2) of a 3x3 s16 matrix into IR1 to IR3 like gte_ldmcol, through t4 to t6 ($12 to $14) */
#define gte_ldmcol4(p, c) \
    asm volatile("lhu $12,%1(%0)\n\tlhu $13,%2(%0)\n\tlhu $14,%3(%0)\n\tmtc2 $12,$9\n\tmtc2 $13,$10\n\t" \
                 "mtc2 $14,$11" : : "r"(p), "i"((c) * 2), "i"((c) * 2 + 6), "i"((c) * 2 + 12) \
                 : "$12", "$13", "$14", "memory")

/* gte_ldv0 with t4 to t7 all listed as clobbers (a loop whose constants must stay out of t6 and t7) */
#define gte_ldv0_k(v) \
    asm volatile("move $12,%0\n\tlwc2 $0,0($12)\n\tlwc2 $1,4($12)" : : "r"(v) : "$12", "$13", "$14", "$15")

/* a value (loaded by the C around it) copied to t4, t5 or t6 ($12 to $14), one statement each; the three screen XY
 * values / the three Z values from t4 to t6 into data registers 12 to 14 (in the order 12, 14, 13) / 17 to 19;
 * the outer product (MAC0, data register 24) / the average Z (OTZ, data register 7) to a word through t4 */
#define gte_mv12(x) asm volatile("move $12,%0" : : "r"(x) : "$12")
#define gte_mv13(x) asm volatile("move $13,%0" : : "r"(x) : "$13")
#define gte_mv14(x) asm volatile("move $14,%0" : : "r"(x) : "$14")
#define gte_ldsxy3_t() asm volatile("mtc2 $12,$12\n\tmtc2 $14,$14\n\tmtc2 $13,$13")
#define gte_ldsz3_t() asm volatile("mtc2 $12,$17\n\tmtc2 $13,$18\n\tmtc2 $14,$19")
#define gte_stopz_m(p) asm volatile("move $12,%0\n\tswc2 $24,0($12)" : : "r"(p) : "$12", "memory")
#define gte_stotz_m(p) asm volatile("move $12,%0\n\tswc2 $7,0($12)" : : "r"(p) : "$12", "memory")

/* gte_ldsxy3_t / gte_ldsz3_t with t4 to t7 all listed as clobbers (the game's loop leaves t7 unused) */
#define gte_ldsxy3_k() asm volatile("mtc2 $12,$12\n\tmtc2 $14,$14\n\tmtc2 $13,$13" : : : "$12", "$13", "$14", "$15")
#define gte_ldsz3_k() asm volatile("mtc2 $12,$17\n\tmtc2 $13,$18\n\tmtc2 $14,$19" : : : "$12", "$13", "$14", "$15")

/* three colours into the colour FIFO (data registers 20 to 22, and the RGB register 6 again from the third) through
 * t4 to t6, which the C has set with gte_mv12 to gte_mv14; the colour FIFO back to three words through t4 to t6; IR0
 * (data register 8) from t4; DPCT (depth cue colour of the three FIFO colours) with the two nops */
#define gte_ldrgb3_t() \
    asm volatile("lwc2 $20,0($12)\n\tlwc2 $21,0($13)\n\tlwc2 $22,0($14)\n\tlwc2 $6,0($14)")
#define gte_strgb3_t() asm volatile("swc2 $20,0($12)\n\tswc2 $21,0($13)\n\tswc2 $22,0($14)" : : : "memory")
#define gte_mtir0_t() asm volatile("mtc2 $12,$8")
#define gte_dpct() gte_cmd(0x0F8002A)

/* the same colour FIFO loads / stores through three pointer registers the C computes (gte_ldrgb3_t and gte_strgb3_t
 * have them in t4 to t6) */
#define gte_ldrgb3(a, b, c) \
    asm volatile("lwc2 $20,0(%0)\n\tlwc2 $21,0(%1)\n\tlwc2 $22,0(%2)\n\tlwc2 $6,0(%2)" : : "r"(a), "r"(b), "r"(c))
#define gte_strgb3(a, b, c) \
    asm volatile("swc2 $20,0(%0)\n\tswc2 $21,0(%1)\n\tswc2 $22,0(%2)" : : "r"(a), "r"(b), "r"(c) : "memory")

/* the matrix helpers of the snobo code with the pointer copied to t4 ($12) first: a column (halfwords at 0, 6 and 12)
 * into IR1 to IR3 through t5 to t7; IR1 to IR3 back to a column; vector 0 from a vector of words 0 (xy halfwords at 0
 * and 4) and 8; IR1 to IR3 to three words */
#define gte_ldmcol_m(p) \
    asm volatile("move $12,%0\n\tlhu $13,0($12)\n\tlhu $14,6($12)\n\tlhu $15,12($12)\n\tmtc2 $13,$9\n\tmtc2 $14,$10\n\t" \
                 "mtc2 $15,$11" : : "r"(p) : "$12", "$13", "$14", "$15", "memory")
#define gte_stir3h_m(p) \
    asm volatile("move $12,%0\n\tmfc2 $13,$9\n\tmfc2 $14,$10\n\tmfc2 $15,$11\n\tsh $13,0($12)\n\tsh $14,6($12)\n\t" \
                 "sh $15,12($12)" : : "r"(p) : "$12", "$13", "$14", "$15", "memory")
#define gte_ldv0w_m(p) \
    asm volatile("move $12,%0\n\tlhu $14,4($12)\n\tlhu $13,0($12)\n\tsll $14,$14,16\n\tor $13,$13,$14\n\tmtc2 $13,$0\n\t" \
                 "lwc2 $1,8($12)" : : "r"(p) : "$12", "$13", "$14", "memory")
#define gte_stir3_m(p) \
    asm volatile("move $12,%0\n\tswc2 $9,0($12)\n\tswc2 $10,4($12)\n\tswc2 $11,8($12)" : : "r"(p) : "$12", "memory")

/* the far colour (control registers 21 to 23) from one value times 16, the shifts reading the operand directly */
#define gte_SetFarColorN(v) \
    asm volatile("sll $12,%0,4\n\tsll $13,%0,4\n\tsll $14,%0,4\n\tctc2 $12,$21\n\tctc2 $13,$22\n\tctc2 $14,$23" \
                 : : "r"(v) : "$12", "$13", "$14")

/* three packed screen XY words from three registers (copied to t4 to t6, then into data registers 12, 14, 13) */
#define gte_ldsxy3_r(a, b, c) \
    asm volatile("move $12,%0\n\tmove $13,%1\n\tmove $14,%2\n\tmtc2 $12,$12\n\tmtc2 $14,$14\n\tmtc2 $13,$13" \
                 : : "r"(a), "r"(b), "r"(c) : "$12", "$13", "$14")

/* gte_ldsxy3_r with t4 to t7 all listed as clobbers */
#define gte_ldsxy3_rk(a, b, c) \
    asm volatile("move $12,%0\n\tmove $13,%1\n\tmove $14,%2\n\tmtc2 $12,$12\n\tmtc2 $14,$14\n\tmtc2 $13,$13" \
                 : : "r"(a), "r"(b), "r"(c) : "$12", "$13", "$14", "$15")

/* IR0 (data register 8) to a word through t4; the flag register (control register 31) to a word through t4 with the
 * flags read through t5 and the nop the game puts after the cfc2 (the pointer copied to t4 first, like gte_stotz_m) */
#define gte_stdp_m(p) asm volatile("move $12,%0\n\tswc2 $8,0($12)" : : "r"(p) : "$12", "memory")
#define gte_stflg_m(p) \
    asm volatile("move $12,%0\n\tcfc2 $13,$31\n\tnop\n\tsw $13,0($12)" : : "r"(p) : "$12", "$13", "memory")

/* the diagonal of the rotation matrix (control registers 0, 2 and 4) from three words (libgte's SetRotDiag-style
 * helper of the look-at code, the pointer copied to t4 first); the long vector into IR1 to IR3 in the order 3, 1, 2
 * through t4; OP 1 (outer product of the diagonal and IR1 to IR3, shifted) with the two nops */
#define gte_SetRotDiag(m) \
    asm volatile("move $12,%0\n\tlw $13,0($12)\n\tlw $14,4($12)\n\tctc2 $13,$0\n\tlw $15,8($12)\n\tctc2 $14,$2\n\t" \
                 "ctc2 $15,$4" : : "r"(m) : "$12", "$13", "$14", "$15")
#define gte_ldlvl3_m(p) \
    asm volatile("move $12,%0\n\tlwc2 $11,8($12)\n\tlwc2 $9,0($12)\n\tlwc2 $10,4($12)" : : "r"(p) : "$12")
#define gte_op1() gte_cmd(0x178000C)

/* the three screen Z results (data registers 17 to 19) to three pointers, each pointer copied to t4 to t6 by a
 * statement of its own (like gte_stsxy3_m); the last screen Z (SZ3, data register 19) to a word through t4 */
#define gte_stsz3_m3(a, b, c) \
    { \
        asm volatile("move $12,%0" : : "r"(a) : "$12"); \
        asm volatile("move $13,%0" : : "r"(b) : "$13"); \
        asm volatile("move $14,%0" : : "r"(c) : "$14"); \
        asm volatile("swc2 $17,0($12)\n\tswc2 $18,0($13)\n\tswc2 $19,0($14)" : : : "memory"); \
    }
#define gte_stsz_m(p) asm volatile("move $12,%0\n\tswc2 $19,0($12)" : : "r"(p) : "$12", "memory")

/* gte_SetRotTrans_d with the scratch registers t4 to t6 ($12 to $14): rotation (control registers 0 to 4) and
 * translation (5 to 7) of a matrix from a pointer register, the loads and ctc2 interleaved the way the game has them */
#define gte_SetRotTrans_d4(m) \
    asm volatile("lw $12,0(%0)\n\tlw $13,4(%0)\n\tctc2 $12,$0\n\tctc2 $13,$1\n\tlw $12,8(%0)\n\tlw $13,12(%0)\n\t" \
                 "lw $14,16(%0)\n\tctc2 $12,$2\n\tctc2 $13,$3\n\tctc2 $14,$4\n\tlw $12,20(%0)\n\tlw $13,24(%0)\n\t" \
                 "ctc2 $12,$5\n\tlw $14,28(%0)\n\tctc2 $13,$6\n\tctc2 $14,$7" \
                 : : "r"(m) : "$12", "$13", "$14", "memory")

/* the back colour (control registers 13 to 15) and the far colour (21 to 23) from three registers, with no shift */
#define gte_SetBackColorR(r, g, b) \
    asm volatile("ctc2 %0,$13\n\tctc2 %1,$14\n\tctc2 %2,$15" : : "r"(r), "r"(g), "r"(b))
#define gte_SetFarColorR(r, g, b) \
    asm volatile("ctc2 %0,$21\n\tctc2 %1,$22\n\tctc2 %2,$23" : : "r"(r), "r"(g), "r"(b))

/* gte_cmd and gte_mvmva with a "memory" clobber: GCC's CSE forgets every register value at a volatile asm without
 * clobbers (gte_cmd), and keeps them across one with a clobber list; the game's code keeps an address in a register
 * across its GTE commands */
#define gte_cmdm(imm) asm volatile("nop\n\tnop\n\tcop2 %0" : : "i"(imm) : "memory")
#define gte_mvmva_m(sf, mx, v, cv, lm) \
    gte_cmdm(0x0400012 | ((sf) << 19) | ((mx) << 17) | ((v) << 15) | ((cv) << 13) | ((lm) << 10))

/* gte_stsxy3_m with a "memory" clobber on each pointer move: a pointer expression that reads a global
 * (&D_x->field) is loaded again for each of the three moves, as the game's code does */
#define gte_stsxy3_mm(a, b, c) \
    { \
        asm volatile("move $12,%0" : : "r"(a) : "$12", "memory"); \
        asm volatile("move $13,%0" : : "r"(b) : "$13", "memory"); \
        asm volatile("move $14,%0" : : "r"(c) : "$14", "memory"); \
        asm volatile("swc2 $12,0($12)\n\tswc2 $13,0($13)\n\tswc2 $14,0($14)" : : : "memory"); \
    }

/* the sequences of a loop whose pointer is copied to t4 by gte_mv12, one asm statement per group of instructions the
 * way the game's own macros expand (the loop optimizer counts each statement as an insn: a loop of 97 insns hoists
 * every constant it can, one of 105 or more only those with enough uses): the vector 0 load; a nop; the screen XY
 * (data register 14), IR0 (data register 8) to a word through t4; cfc2 / mfc2 into t5 ($13) with their clobber, the
 * sra by 2 of t5 and its store through t4 */
#define gte_nop() asm volatile("nop")
#define gte_ldv0_t() asm volatile("lwc2 $0,0($12)\n\tlwc2 $1,4($12)")
#define gte_stsxy_t() asm volatile("swc2 $14,0($12)" : : : "memory")
#define gte_stdp_t() asm volatile("swc2 $8,0($12)" : : : "memory")
#define gte_cfc2_t5(n) asm volatile("cfc2 $13,$" #n : : : "$13")
#define gte_mfc2_t5(n) asm volatile("mfc2 $13,$" #n : : : "$13")
#define gte_sra2_t5() asm volatile("sra $13,$13,2" : : : "$13")
#define gte_sw_t5() asm volatile("sw $13,0($12)" : : : "memory")

/* OTZ (data register 7) to a word through t4, with the pointer copied to t4 by gte_mv12 first (gte_stotz_m in two
 * statements: the pointer's last use comes one insn earlier, which the register allocator's priorities see) */
#define gte_stotz_t() asm volatile("swc2 $7,0($12)" : : : "memory")

/* gte_ldv3_m with a "memory" clobber on each pointer move (a pointer expression that reads a global is loaded again
 * for each of the three moves, like gte_stsxy3_mm) */
#define gte_ldv3_mm(a, b, c) \
    { \
        asm volatile("move $12,%0" : : "r"(a) : "$12", "memory"); \
        asm volatile("move $13,%0" : : "r"(b) : "$13", "memory"); \
        asm volatile("move $14,%0" : : "r"(c) : "$14", "memory"); \
        asm volatile("lwc2 $0,0($12)\n\tlwc2 $1,4($12)\n\tlwc2 $2,0($13)\n\tlwc2 $3,4($13)\n\tlwc2 $4,0($14)\n\t" \
                     "lwc2 $5,4($14)"); \
    }

/* gte_ldv3_m with t7 ($15) listed as clobbered by the load (the game's loop leaves t7 unused) */
#define gte_ldv3_mk(a, b, c) \
    { \
        asm volatile("move $12,%0" : : "r"(a) : "$12"); \
        asm volatile("move $13,%0" : : "r"(b) : "$13"); \
        asm volatile("move $14,%0" : : "r"(c) : "$14"); \
        asm volatile("lwc2 $0,0($12)\n\tlwc2 $1,4($12)\n\tlwc2 $2,0($13)\n\tlwc2 $3,4($13)\n\tlwc2 $4,0($14)\n\t" \
                     "lwc2 $5,4($14)" : : : "$15"); \
    }

/* the colour code into the RGB register (data register 6) / the colour result (data register 22, RGB2) to a word,
 * each through a pointer copied to t4 first (gte_ldrgb and gte_strgb with the move) */
#define gte_ldrgb_m(p) asm volatile("move $12,%0\n\tlwc2 $6,0($12)" : : "r"(p) : "$12")
#define gte_strgb_m(p) asm volatile("move $12,%0\n\tswc2 $22,0($12)" : : "r"(p) : "$12", "memory")

/* gte_stflg_m with t6 and t7 ($14, $15) listed as clobbered too (a loop that leaves them unused) */
#define gte_stflg_mk(p) \
    asm volatile("move $12,%0\n\tcfc2 $13,$31\n\tnop\n\tsw $13,0($12)" : : "r"(p) : "$12", "$13", "$14", "$15", "memory")

/* gte_stflg_mk in two statements (the pointer move, then the flag read and store): the loop optimizer and the register
 * allocator count one more insn in the loop, which changes the allocation priorities */
#define gte_stflg_ms(p) \
    { \
        asm volatile("move $12,%0" : : "r"(p) : "$12"); \
        asm volatile("cfc2 $13,$31\n\tnop\n\tsw $13,0($12)" : : : "$13", "$14", "$15", "memory"); \
    }

/* gte_ldv3_mm with t7 ($15) listed as clobbered by the load (a loop that leaves t7 unused) */
#define gte_ldv3_mmk(a, b, c) \
    { \
        asm volatile("move $12,%0" : : "r"(a) : "$12", "memory"); \
        asm volatile("move $13,%0" : : "r"(b) : "$13", "memory"); \
        asm volatile("move $14,%0" : : "r"(c) : "$14", "memory"); \
        asm volatile("lwc2 $0,0($12)\n\tlwc2 $1,4($12)\n\tlwc2 $2,0($13)\n\tlwc2 $3,4($13)\n\tlwc2 $4,0($14)\n\t" \
                     "lwc2 $5,4($14)" : : : "$15"); \
    }

/* gte_stsxy_m with t5 to t7 ($13 to $15) listed as clobbered too (code that leaves them to the macros) */
#define gte_stsxy_mk(p) \
    asm volatile("move $12,%0\n\tswc2 $14,0($12)" : : "r"(p) : "$12", "$13", "$14", "$15", "memory")

/* three screen XY words from three registers straight into data registers 12, 14, 13 (no copies); the three screen XY
 * (data registers 12 to 14) and Z (17 to 19) results to a cache of eight-byte entries; one screen XY and the last Z; the
 * three Z words (at offset 4 of three pointers) into the Z FIFO (data registers 17 to 19) */
#define gte_ldsxy3_d(a, b, c) \
    asm volatile("mtc2 %0,$12\n\tmtc2 %2,$14\n\tmtc2 %1,$13" : : "r"(a), "r"(b), "r"(c))
#define gte_stsxysz3(p) \
    asm volatile("swc2 $12,0(%0)\n\tswc2 $13,8(%0)\n\tswc2 $14,16(%0)\n\tswc2 $17,4(%0)\n\tswc2 $18,12(%0)\n\t" \
                 "swc2 $19,20(%0)" : : "r"(p) : "memory")
#define gte_stsxysz(p) asm volatile("swc2 $14,0(%0)\n\tswc2 $19,4(%0)" : : "r"(p) : "memory")
#define gte_ldsz3d(a, b, c) \
    asm volatile("lwc2 $17,4(%0)\n\tlwc2 $18,4(%1)\n\tlwc2 $19,4(%2)" : : "r"(a), "r"(b), "r"(c))

#endif /* GTE_H */
