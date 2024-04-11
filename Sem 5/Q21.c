/*

Write a C program that accepts an integer array. Main function forks child
 process. Parent process sorts an integer array and passes the sorted array to
 child process through the command line arguments of execve() system call.
 The child process uses execve() system call to load new program that uses this
 sorted array for performing the binary search to search the particular item in
 the array
*/

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = 7;
    int key = 4;

    if (fork() == 0)
    {
        char *argv[size + 4];

        char sizeInChar[10];
        char keyInChar[10];

        sprintf(sizeInChar, "%d", size);
        sprintf(keyInChar, "%d", key);

        argv[0] = strdup("binarySearch");
        argv[1] = strdup(sizeInChar);
        argv[2] = strdup(keyInChar);

        char str[10]; // to copy the sorted array
        int i = 0;
        for (i = 0; i < size; i++)
        {
            sprintf(str, "%d", arr[i]);
            argv[i + 3] = strdup(str);
        }

        argv[size + 3] = NULL;
        execve("./binarySearch", argv, NULL);
        // printf("Some thingi went wrong\n");
        perror("Execve failed");
    }
    else
    {
        int status;
        wait(&status);
        // printf("Exited with status : %d\n", status);
    }
}