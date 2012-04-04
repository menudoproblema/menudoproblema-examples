#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

void do_something()
{
	printf("Do somenthing\n");
	sleep(3);
}

int main()
{
	struct timeval tim;
	int keepalive = 5, elapsed_seconds;
	double t1, t2;


	gettimeofday(&tim, NULL);
	t1 = tim.tv_sec + (tim.tv_usec/1000000.0);

	while(1)
	{
		gettimeofday(&tim, NULL);
		t2 = tim.tv_sec + (tim.tv_usec/1000000.0);
		elapsed_seconds = (int)(t2 - t1);
		printf("t1: %f, t2: %f, elapsed_time:%d\n", t1, t2, elapsed_seconds);
		if(elapsed_seconds > keepalive)
		{
			printf("Timeout!\n");
			// Keep alive
			gettimeofday(&tim, NULL);
			t1 = tim.tv_sec + (tim.tv_usec/1000000.0);
		}

		do_something();

	}

	return 0;
}
