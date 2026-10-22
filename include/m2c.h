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

#endif /* M2C_H */
