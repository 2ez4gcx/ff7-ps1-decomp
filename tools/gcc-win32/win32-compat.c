/* BSD string functions GCC 2.6.3 expects of its host, for a Windows build. */
#include <string.h>
char *index (const char *s, int c) { return strchr (s, c); }
char *rindex (const char *s, int c) { return strrchr (s, c); }
int bcmp (const void *a, const void *b, size_t n) { return memcmp (a, b, n); }
void bcopy (const void *s, void *d, size_t n) { memmove (d, s, n); }
void bzero (void *p, size_t n) { memset (p, 0, n); }
