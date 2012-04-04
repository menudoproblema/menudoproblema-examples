#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

struct timeval tim;
int keepalive = 5, elapsed_seconds;
double t1, t2;


void alive(int sig)
{
	gettimeofday(&tim, NULL);
	t2 = tim.tv_sec + (tim.tv_usec/1000000.0);
	elapsed_seconds = (int)(t2 - t1);
	printf("Timeout! Elapsed time: %d\n", elapsed_seconds);

	gettimeofday(&tim, NULL);
	t1 = tim.tv_sec + (tim.tv_usec/1000000.0);

	alarm(keepalive);
}

void do_something()
{
	printf("Do somenthing\n");
	sleep(3);
}

int main() {
	signal(SIGALRM, alive);
	gettimeofday(&tim, NULL);
	t1 = tim.tv_sec + (tim.tv_usec/1000000.0);

	alarm(keepalive);
	while(1)
	{
		do_something();
	}
	return 0;
}
