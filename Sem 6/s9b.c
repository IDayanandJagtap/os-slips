// Write a simulation program for disk scheduling using LOOK algorithm. Accept total
// number of disk blocks, disk request string, and current head position from the user. Display
// the list of request in the order in which it is served. Also display the total number of head
// moments.
//  176, 79, 34, 60, 92, 11, 41, 114
//  Starting Head Position: 65
// Direction: Left

#include <stdio.h>
#include <stdlib.h>
void sort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int findHeadPosition(int a[], int n, int head)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == head)
            return i;
    }
    return -1;
}

void look(int a[], int n, int headPosition)
{
    int total = 0;
    int currentHead = a[headPosition];
    int i = headPosition;

    // goto  left
    while (i > 0)
    {
        printf("%d->", currentHead);
        total += abs(currentHead - a[--i]);
        currentHead = a[i];
    }
    printf("%d->", currentHead);

    i = headPosition + 1;
    total += abs(currentHead - a[i]);
    currentHead = a[i];

    // goto right
    while (i < n - 1)
    {
        printf("%d->", currentHead);
        total += abs(currentHead - a[++i]);
        currentHead = a[i];
    }

    printf("%d\n", currentHead);
    printf("\nTotal : %d\n", total);
}

int main()
{
    /*
         1. insert start end head
         2. sort
         3. find head position
         4. move acc to dir
    */
    int request[9] = {98, 183, 53, 41, 122, 14, 124, 65, 67};

    sort(request, 9);
    for (int i = 0; i < 9; i++)
    {
        printf("%d\t", request[i]);
    }
    printf("\n");

    int headPosition = findHeadPosition(request, 9, 53);

    look(request, 9, headPosition);

    return 0;
}