#include <stdio.h>
#include <fcntl.h>


int main ()
{
	int fd;
	fd = open ("tt.c", O_RDONLY);
	fprintf(stderr, "fd: %d\n", fd);
	for (fd=0; fd<=5; ++fd){
//	fd = 1;
	fprintf(stderr, "ptr: %s\n", &_iob[fd]._ptr);
	fprintf(stderr, "base: %s\n", &_iob[fd]._base);
	fprintf(stderr, "cnt: %u\n", &_iob[fd]._cnt);
	fprintf(stderr, "file: %u\n", &_iob[fd]._file);
	fprintf(stderr, "tmpfname: %s\n", &_iob[fd]._tmpfname);
	}
}