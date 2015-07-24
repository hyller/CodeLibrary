#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
                                          
enum { N = 5 };                           /* number of philosphers */

static HANDLE fork[N];          /* model forks as mutex semaphores */

void think(long n) {
   printf("Philosopher %d is thinking\n", n);
   Sleep(10);
   printf("Philosopher %d is hungry\n", n);
} 

void eat(long n) {
   printf("Philosopher %d is eating\n", n);
   Sleep(0);
} 

long WINAPI philosopher(long n) {   /* model philosophers as tasks */
   for (;;) {
      think(n);
      WaitForSingleObject(fork[(n + 1) % N], INFINITE);
      Sleep(0);             /* yield the CPU (simulate preemption) */
      WaitForSingleObject(fork[n], INFINITE);
      eat(n);
      ReleaseMutex(fork[(n + 1) % N]);
      ReleaseMutex(fork[n]);
   }
   return 0;
} 

main() {
   int n;
   for (n = 0; n < N; ++n) {                       /* create forks */
       fork[n] = CreateMutex(NULL, FALSE, NULL);      /* not owned */
   }
   for (n = 0; n < N; ++n) {                /* create philosophers */
      int threadID;
      CloseHandle(CreateThread(NULL, 0, 
                               (LPTHREAD_START_ROUTINE)philosopher,
                               (LPVOID)n, 0, &threadID));
   }
   scanf("%c", &n);            /* wait for the user to press Enter */    
   return 0;
}