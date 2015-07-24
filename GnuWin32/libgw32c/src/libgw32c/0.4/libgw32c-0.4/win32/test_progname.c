
#include <stdio.h>
#include <windows.h>

int
main (int argc, char **argv)
{
	char prog_name[MAX_PATH];
	char exec_dir[MAX_PATH];
	char exec_parent[MAX_PATH];
	
	fprintf(stderr, "Argv0:                 %s\n", argv[0]);

	fprintf(stderr, "Prog:                  %s\n", getprogname(prog_name));
	
	fprintf(stderr, "Progdir:               %s\n", getexecdir(exec_dir));

	fprintf(stderr, "Prog_parent:           %s\n", getexecparent(exec_parent));
	
}

