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
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <linux/tcp.h>


int main(int argc, char* argv[])
{
	int sockfd, flag = 1;
	// Create the socket
	if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
		return -1;

	// Disable Nagle Algorithm
	if (setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, (char*)&flag, sizeof(flag)) < 0)
		return -2;

	struct sockaddr_in socket_address;
	// Create the stuff we need to connect
	socket_address.sin_family = AF_INET;
	socket_address.sin_port = htons(1883);
	socket_address.sin_addr.s_addr = inet_addr("192.168.10.40");

	// Connect the socket
	if((connect(sockfd, (struct sockaddr*)&socket_address, sizeof(socket_address))) < 0)
		return -1;

	close(sockfd);

	return 0;
}
