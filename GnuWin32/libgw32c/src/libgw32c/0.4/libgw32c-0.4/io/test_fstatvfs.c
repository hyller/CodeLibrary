#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/statvfs.h>

#include <libc/sys/fsinfo.h>


int main (int argc, char *argv[])
{
	int fd;
	struct statvfs statfsbuf;
	fd = open (argv[1], O_RDONLY);
	if (fd == -1){
		fprintf(stderr, "Cannot open %s\n", argv[1]);
		return 0;
	}
	if (fstatvfs(fd, &statfsbuf)==-1)
		return 0;
//		printf("  File: \"%s\"\n", filename);
#ifdef __USE_FILE_OFFSET64 
//	printf("    ID: %-8x %-8x Namelen: %-7ld Type: ", statfsbuf.f_fsid.__val[0], statfsbuf.f_fsid.__val[1], statfsbuf.f_namelen);
	printf("    ID: %u         Namelen: %u       Type: ", statfsbuf.f_fsid, statfsbuf.f_namelen);
#else
//	printf("    ID: %-8x %-8x Namelen: %-7d Type: ", statfsbuf.f_fsid.__val[0], statfsbuf.f_fsid.__val[1], statfsbuf.f_namelen);
	printf("    ID: %+17Lu", statfsbuf.f_fsid);
	printf("   (%+12LX)", statfsbuf.f_fsid);
	printf(" Namelen: %+12u Type: ", statfsbuf.f_namemax);
#endif

#ifdef __USE_FILE_OFFSET64
	printf("Blocks: Total: %+10lld Free: %+10lld Available: %+10llu Size: %lu\n",  statfsbuf.f_blocks, statfsbuf.f_bfree, statfsbuf.f_bavail, statfsbuf.f_bsize);
	printf("Inodes: Total: %+10lld Free: %+10lld\n", statfsbuf.f_files, statfsbuf.f_ffree);
#else
	printf("Blocks: Total: %+10lu Free: %+10lu Available: %+10lu Size: %u\n", statfsbuf.f_blocks, statfsbuf.f_bfree, statfsbuf.f_bavail, statfsbuf.f_bsize);
	printf("Inodes: Total: %+10lu Free: %+10lu\n", statfsbuf.f_files, statfsbuf.f_ffree);
#endif
}