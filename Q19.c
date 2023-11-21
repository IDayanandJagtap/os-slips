// Write a C program to illustrate the concept of orphan process. Parent process
// creates a child and terminates before child has finished its task. So child
// process becomes orphan process. (Use fork(), sleep(), getpid(), getppid()).


#include<stdio.h>
#include<unistd.h>

void main() { 

    if(fork() == 0) { 
        printf("Process Id of child process : %d\n", getpid());
        printf("Current Parent process Id of child process : %d\n", getppid());

        sleep(3);

        printf("Current Parent process Id of child process after becoming an orphan : %d\n", getppid());

    }
    else { 
        sleep(2);
        printf("Parent process Id : %d\n", getpid());
    }
}