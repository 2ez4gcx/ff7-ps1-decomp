#ifndef M2C_H
#define M2C_H

/* What code drafted by m2c (--valid-syntax) uses for what it could not name.
 * A function still written with these matches the game; cleaning it up into
 * real types and fields is later work. */

typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;

/* A field at a byte offset that has no name yet. */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

/* The same, as a member of a struct. GCC 2.6.3 takes a struct member reached
 * through a pointer and a plain variable to be apart, and orders the two as
 * it likes; through a cast pointer as above, it keeps them in place. The
 * game's code was written with structs, so this is the one that matches
 * where the order differs. */
#define M2C_SFIELD(expr, type_ptr, offset) \
    (((struct { s8 pad[offset]; __typeof__(*(type_ptr)0) v; } *)(expr))->v)

#endif /* M2C_H */
