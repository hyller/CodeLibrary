#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

volatile int gotit = 0;

static void
alarm_handler (int signal)
{
    gotit = 1;
}

int
main (int argc, char ** argv)
{
  clock_t start, stop;
  int sleepsec = 5;
  uint64_t n;
  double x;

//  if (signal(SIGALRM, alarm_handler) == SIG_ERR)
//    {
//      perror ("signal");
//      exit (1);
//    }
//  alarm(1);
  start = clock ();
//  while (!gotit);
x = 1234567;
  for (n = 0; n < 1000000000; n++)
  	x = x / 10 * 11;
//  sleep (sleepsec);
  stop = clock ();

  printf ("start = %I64d\nstop  = %I64d\nstop - start=%I64d\n",
	  start, stop, stop-start);
  printf ("%I64d clock ticks per second\n",
	  (stop - start) * 10 / sleepsec);
  printf ("CLOCKS_PER_SEC=%ld, sysconf(_SC_CLK_TCK)=%ld\n",
	  CLOCKS_PER_SEC, sysconf(_SC_CLK_TCK));
  return 0;
}
