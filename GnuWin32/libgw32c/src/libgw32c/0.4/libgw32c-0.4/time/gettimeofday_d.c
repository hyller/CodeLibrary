#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/time.h>

#define ft70sec 11644473600 /* seconds between 1/1/1601 and 1/1/1970 */

int
gettimeofday_d (struct timeval *p, struct timezone *z)
{
	int res = 0;
	LARGE_INTEGER fti;
	LONGLONG ltvsec; 
	
	if (z != NULL){
		_tzset();
		z->tz_minuteswest = _timezone / 60;
		z->tz_dsttime = _daylight;
    }

	if (p != NULL) {
		GetSystemTimeAsFileTime((LPFILETIME) &fti);
		ltvsec = fti.QuadPart / 10000000 - ft70sec;
		p->tv_sec = ltvsec;
		p->tv_usec = (fti.QuadPart - (ft70sec + ltvsec) * 10000000)/10;
	}

	return res;
}

int main()
{
	struct timeval p;
	struct timezone z;

//	gettimeofday(&p,&z);
//	fprintf(stderr, "The time is     %d sec %d microsec\n", p.tv_sec, p.tv_usec);
//	fprintf(stderr, "The timezone is %d min DST: %d\n", z.tz_minuteswest, z.tz_dsttime);

	gettimeofday_d(&p,&z);
	fprintf(stderr, "The time is     %d sec %d microsec\n", p.tv_sec, p.tv_usec);
	fprintf(stderr, "The timezone is %d min DST: %d\n", z.tz_minuteswest, z.tz_dsttime);

}
