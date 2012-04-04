# Description

This example prints ``Timeout! Elpased time: #s`` elapsed 5 seconds or more.

## When to use

This timer is implemented in the program itself, so it is not strict. It
ensures that the maintenance task to run every 5 seconds.

Affected by blocking system calls and the application code itself. This
code can be used when you need to perform a task after 5 seconds or more.

# Compile

    $ gcc -o timer1 timer1.c -Wall

# Example

    $ ./timer1 
	Do somenthing
	Do somenthing
	Timeout! Elapsed time: 6
	Do somenthing
	Do somenthing
	Timeout! Elapsed time: 6
	Do somenthing
	Do somenthing
	Timeout! Elapsed time: 6

