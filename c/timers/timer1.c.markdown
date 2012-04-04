# Description

This example prints ``Timeout!`` elapsed 5 seconds

## When to use

This timer is implemented in the program itself, so it is not strict. It
ensures that the maintenance task to run every 5 seconds.

Affected by blocking system calls and the application code itself. This
code can be used when you need to perform a task after 5 seconds or more.

# Compile

    $ gcc -o timer1 timer1.c -Wall

# Example

    $ ./timer1
    t1: 1333525126.992194, t2: 1333525126.992194, elapsed_time:0
    Do somenthing
    t1: 1333525126.992194, t2: 1333525129.992326, elapsed_time:3
    Do somenthing
    t1: 1333525126.992194, t2: 1333525132.992430, elapsed_time:6
    Timeout!
    Do somenthing
