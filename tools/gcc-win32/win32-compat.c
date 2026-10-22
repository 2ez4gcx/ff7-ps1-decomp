/* What GCC 2.6.3 and 2.7.2 expect of their host that Windows lacks: BSD
 * string functions, and getrusage (include/sys/resource.h). */
#include <string.h>
#include "sys/resource.h"
char *index (const char *s, int c) { return strchr (s, c); }
char *rindex (const char *s, int c) { return strrchr (s, c); }
int bcmp (const void *a, const void *b, size_t n) { return memcmp (a, b, n); }
void bcopy (const void *s, void *d, size_t n) { memmove (d, s, n); }
void bzero (void *p, size_t n) { memset (p, 0, n); }
int getrusage (int who, struct rusage *usage) { (void) who; memset (usage, 0, sizeof *usage); return 0; }
