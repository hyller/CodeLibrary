#include <libc-internal.h>
#include <errno.h>
#include <windows.h>

int getcpuspeed (int64_t *Result)
{
	LARGE_INTEGER Freq, Ticks, Ticks1Sec, TicksStart, TimeStamps;
	if (!QueryPerformanceFrequency(&Freq)) {
		set_werrno;
		return -1;
	}
	if (!QueryPerformanceCounter(&Ticks)) {
		set_werrno;
		return -1;
	}
	Ticks1Sec.QuadPart = Ticks.QuadPart + Freq.QuadPart;
	HP_TIMING_NOW(TimeStamps);
	TicksStart.QuadPart = TimeStamps.QuadPart;
	do {
		QueryPerformanceCounter(&Ticks);
	} while (Ticks.QuadPart <= Ticks1Sec.QuadPart) ;
	HP_TIMING_NOW(TimeStamps);
    *Result = TimeStamps.QuadPart - TicksStart.QuadPart;
	return 0;
}
