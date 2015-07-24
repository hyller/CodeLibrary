#include <time.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include <stdio.h>

#ifndef	GETTIMEOFDAY
# define TIMEVAL timeval
# define GETTIMEOFDAY gettimeofday
# define SETTIMEOFDAY settimeofday
# define TV_USEC tv_usec
# define UNSTR "microsec"
#endif

int main()
{
	struct TIMEVAL p;
	struct timezone z;

	GETTIMEOFDAY(&p, &z);
	fprintf(stderr, "The time is     %lu sec %lu " UNSTR "\n", p.tv_sec, p.TV_USEC);
	fprintf(stderr, "The timezone is %d min DST: %d\n", z.tz_minuteswest, z.tz_dsttime);

	p.tv_sec -= 3600;
	fprintf(stderr, "The time is     %lu sec %lu " UNSTR "\n", p.tv_sec, p.TV_USEC);
	fprintf(stderr, "The timezone is %d min DST: %d\n", z.tz_minuteswest, z.tz_dsttime);
	SETTIMEOFDAY(&p, &z);
	GETTIMEOFDAY(&p, &z);
	fprintf(stderr, "The time is     %lu sec %lu " UNSTR "\n", p.tv_sec, p.TV_USEC);
	fprintf(stderr, "The timezone is %d min DST: %d\n", z.tz_minuteswest, z.tz_dsttime);
	return 0;
}
