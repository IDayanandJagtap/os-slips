/*

Write a C Program to create a child process using fork (), display parent and
child process id. Child process will display the message “I am Child Process”
and the parent process should display “I am Parent Process”. 

*/


#include<stdio.h>
#include<unistd.h>

void main() {

    if(fork() == 0){ 
        printf("I am child process\n");
    }
    else { 
        printf("I am Parent process\n");
    }
}