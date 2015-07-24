#define TIMEVAL timespec
#define GETTIMEOFDAY getntptimeofday
#define SETTIMEOFDAY setntptimeofday
#define TV_USEC tv_nsec
#define UNSTR "nanosec"

#include <test_settimeofday.c>
