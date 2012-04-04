# Description

This example prints ``Timeout! Elpased time: #s`` every 5 seconds

## When to use

This example uses a kernel timer through the alarm system call.
Therefore it's necessary to handle signals. Use blocking system calls
doesn't affect the operation of the timer.

It can be used where necessary to perform a task accurately. For
example, to keep alive a connection.

# Compile

    $ gcc -o timer2 timer2.c -Wall

# Example

    $ ./timer2
    Do somenthing
    Do somenthing
    Timeout! Elapsed time: 5
    Do somenthing
    Do somenthing
    Timeout! Elapsed time: 5
    Do somenthing
    Do somenthing
    Timeout! Elapsed time: 5
