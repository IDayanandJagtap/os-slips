#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = 7;
    int key = 4;

    if (fork() == 0)
    {
        char *argv[size + 3];

        char sizeInChar[10];
        char keyInChar[10];

        sprintf(sizeInChar, "%d", size);
        sprintf(keyInChar, "%d", key);

        argv[0] = strdup("binarySearch"); // Corrected executable name
        argv[1] = strdup(sizeInChar);
        argv[2] = strdup(keyInChar);

        // Check for NULL after each strdup
        if (argv[0] == NULL || argv[1] == NULL || argv[2] == NULL)
        {
            perror("strdup failed");
            exit(EXIT_FAILURE);
        }

        char str[10]; // to copy the sorted array
        for (int i = 0; i < size; i++)
        {
            sprintf(str, "%d", arr[i]);
            argv[i + 3] = strdup(str);

            // Check for NULL after each strdup
            if (argv[i + 3] == NULL)
            {
                perror("strdup failed");
                exit(EXIT_FAILURE);
            }
        }

        // Explicitly null-terminate the args array
        argv[size + 3] = NULL;

        execve("./binarySearch", argv, NULL);

        // If execve fails
        perror("Execve failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        wait(&status);
        // printf("Exited with status: %d\n", status);
    }

    return 0;
}
