/* What GCC 2.7.2 takes from <sys/resource.h>, which Windows has not: only
 * getrusage, for its timing report (always zero here). */
#ifndef FF7_SYS_RESOURCE_H
#define FF7_SYS_RESOURCE_H

#include <sys/time.h>

#define RUSAGE_SELF 0

struct rusage {
    struct timeval ru_utime;
    struct timeval ru_stime;
};

int getrusage(int who, struct rusage *usage);

#endif
