#include <stdio.h>
#include <time.h>
#include <windows.h>
int
main (int argc, char **argv)
{
     int64_t speed;
	 int res;
     
     res = getcpuspeed (&speed);
	 fprintf (stderr, "CPU speed: %I64d\n", (__int64) speed);
	 fprintf (stderr, "CPU resolution (nanosec): %5.2f\n", (double) ((NANOSEC_PER_SEC/1.0)/speed));
	 return res;
}
