#include <stdio.h>
#include <errno.h>

int
main (int argc, char **argv)
{
	unsigned long useconds;
	
	fprintf(stderr, "Micro-seconds:  %s\n", argv[1]);
	useconds = strtoul(argv[1], '\0', 10);
	fprintf(stderr, "Micro-seconds:  %d\n", useconds);
	if (usleep(useconds))
		perror("Usleep");	
}
