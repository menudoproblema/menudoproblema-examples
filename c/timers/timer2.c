/*
 * This file is an example named ``This example``.
 *
 * ``This example`` is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ``This example`` is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with ``This example``.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * Copyright 2012 Vicente Ruiz Rodríguez <vruiz2.0@gmail.com>. All rights reserved.
 * http://www.menudoproblema.com/
 *
 */
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
