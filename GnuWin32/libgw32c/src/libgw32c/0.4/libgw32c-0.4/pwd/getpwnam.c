#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>

static char passwd[] = "";
static char shell [] = "sh";
static struct passwd pw;

struct passwd *getpwnam(const char *name)
{
	strcpy(pw.pw_name, name);
	pw.pw_uid = getuid();
	pw.pw_gid = getgid();
	pw.pw_dir = getenv("HOME");
	if (pw.pw_dir == NULL)
		pw.pw_dir = "C:/";
	pw.pw_shell = getenv("SHELL");
	if (pw.pw_shell == NULL)
		pw.pw_shell = getenv("COMSPEC");
	if (pw.pw_shell == NULL)
		pw.pw_shell = shell;
	pw.pw_gecos = getlogin();
	pw.pw_passwd = passwd;
	return &pw;
}
