#include <stdio.h>

int
main (int argc, char **argv)
{
	unsigned long seconds;
	
	fprintf(stderr, "Seconds:  %s\n", argv[1]);
	seconds = strtoul(argv[1], '\0', 10);
	fprintf(stderr, "Seconds:  %d\n", seconds);
	alarm(seconds);
}
