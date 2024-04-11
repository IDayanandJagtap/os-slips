/*
 Write a C Menu driven Program to implement following functionality
a) Accept Available
b) Display Allocation, Max
c) Display the contents of need matrix
d) Display Available
*/

// request fullfill hotiye ka check kara
void s5a(int allocation[][], int need[][], int available[])
{
    // int request[3] = { 1,
    //                    2,
    //                    3,
    //                    4 };

    //                    avail -= request;
    //                    need -= request;
    //                    allocation[requestNo][i] += request;
}

#include <stdio.h>

int main()
{
    int available[3] = {3, 3, 2};
    int allocation[5][3] = {
        {2, 3, 2},
        {4, 0, 0},
        {5, 0, 4},
        {4, 3, 3},
        {2, 2, 4},
    };

    int maximum[5][3] = {
        {9, 7, 5},
        {5, 2, 2},
        {1, 0, 4},
        {4, 4, 4},
        {6, 5, 5},
    };
    int need[5][3];

    // display max matrix
    printf("\n********************** Max matrix ***************\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", maximum[i][j]);
        }
        printf("\n");
    }

    // calculate need matrix
    printf("\n********************** need matrix ***************\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    return 0;
};
