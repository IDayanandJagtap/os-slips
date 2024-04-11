/*
Write a C program to simulate Banker’s algorithm for the purpose of deadlock
avoidance. Consider the following snapshot of system, A, B, C and D is the
resource type.

a)Calculate and display the content of need matrix?
b)Is the system in safe state? If yes display the safe sequence.

*/
#include <stdio.h>

int main()
{
    int available[4] = {1, 5, 2, 0};
    int allocation[5][4] = {
        {0, 0, 1, 2},
        {1, 0, 0, 0},
        {1, 3, 5, 4},
        {0, 6, 3, 2},
        {0, 0, 1, 4},
    };

    int maximum[5][4] = {
        {0, 0, 1, 2},
        {1, 7, 5, 0},
        {2, 3, 5, 6},
        {0, 6, 5, 2},
        {0, 6, 5, 6},
    };
    int need[5][3];

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         printf("Enter allocation[%d][%d]", i+1, j+1);
    //         scanf("%d", &allocation[i][j]);
    //     }
    // }

    // display max matrix
    printf("\n********************** Max matrix ***************\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", maximum[i][j]);
        }
        printf("\n");
    }

    // calculate need matrix
    printf("\n********************** need matrix ***************\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    // banker algo :
    int process[5] = {0};
    int counter = 1;
    // make work matrix same as available;
    int work[4] = {1, 5, 2, 0};
    int isExecutable = 0;

    printf("\nSafe sequence : \n");
    while (counter <= 5)
    {
        for (int i = 0; i < 5; i++)
        {
            if (process[i] == 1)
            {
                continue;
            }

            isExecutable = 1;
            for (int j = 0; j < 4; j++)
            {
                if (need[i][j] > work[j])
                {
                    isExecutable = 0;
                }
            }

            if (isExecutable)
            {
                process[i] = 1;
                for (int j = 0; j < 4; j++)
                {
                    work[j] += allocation[i][j];
                }
                printf("%d\t", i);
                counter++;
            }
        }
    }

    return 0;
};
