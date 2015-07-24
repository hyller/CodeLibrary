#include <time.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include <stdio.h>

int main()
{
	struct timespec tp;
	struct timezone z;
	struct timeval p;

	struct _timeb timebuffer;
	_ftime(&timebuffer);
	fprintf(stderr, "ftime: %lu sec %d millisec\n", timebuffer.time, timebuffer.millitm);
	_tzset();
	fprintf(stderr, "tzset: %s %s\n", _tzname[0], _tzname[1]);
	fprintf(stderr, "tzset: %ld sec DST: %d\n", _timezone, _daylight);

	gettimeofday(&p,&z);
	fprintf(stderr, "gettimeofday: %lu sec %lu microsec\n", p.tv_sec, p.tv_usec);
	fprintf(stderr, "gettimeofday: %d min DST: %d\n", z.tz_minuteswest, z.tz_dsttime);

	getntptimeofday(&tp,&z);
	fprintf(stderr, "getntptimeofday: %lu sec %lu nanosec\n", tp.tv_sec, tp.tv_nsec);
	fprintf(stderr, "getntptimeofday: %d min DST: %d\n", z.tz_minuteswest, z.tz_dsttime);
	return 0;
}
