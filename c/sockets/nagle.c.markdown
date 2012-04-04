# Description

This example disables Nagle's Algorithm.

## Nagle's Algorithm

Nagle's algorithm is a means of improving the efficiency of TCP/IP networks by
reducing the number of packets that need to be sent over the network.

[Wikipedia](http://en.wikipedia.org/wiki/Nagle%27s_algorithm)

## When to use

If necessary send packets independently, as in real-time applications.

# Compile

    $ gcc -o nagle nagle.c -Wall

