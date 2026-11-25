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

#endif /* GTE_H */
