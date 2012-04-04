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
		if(elapsed_seconds > keepalive)
		{
			printf("Timeout! Elapsed time: %d\n", elapsed_seconds);

			gettimeofday(&tim, NULL);
			t1 = tim.tv_sec + (tim.tv_usec/1000000.0);
		}

		do_something();

	}

	return 0;
}
