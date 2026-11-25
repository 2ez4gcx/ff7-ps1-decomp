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

#endif /* GTE_H */
