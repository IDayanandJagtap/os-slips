/*
Write a C program that demonstrates the use of nice() system call. After a
 child Process is started using fork (), assign higher priority to the child using
 nice () system call.
*/

#include <stdio.h>
#include <unistd.h>

void main()
{

    if (fork() == 0)
    {

        // current nice value -> nice(0) ... it returns the current priority
        printf("I am a child process ");
        printf("Current priority : %d\n", nice(0));
        printf("Priority after nice call : %d\n", nice(-10)); // lower the number higher the priority
    }
    else
    {
    }
}