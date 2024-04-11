/*
Write the simulation program for demand paging and show the page
 scheduling and total number of page faults according the optimal page
 replacement algorithm. Assume the memory of n frames.
Reference String : 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2
*/

#include <stdio.h>

typedef struct frames
{
    int no;    // page no
    int count; // frequency (how many times the page will occur in future)
} Frame;

void optimal(int refString[], int n, int frameSize)
{
    int pageFaults = 0;
    int counter = 0;

    // Initialise frames
    Frame frames[frameSize];
    for (int i = 0; i < frameSize; i++)
    {
        frames[i].no = 0;
        frames[i].count = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int page = refString[i];
        int isPresent = 0;

        for (int j = 0; j < frameSize; j++)
        {
            if (frames[j].no == page)
            {
                isPresent = 1;
                break;
            }
        }

        if (!isPresent)
        {
            int victim = -1;

            if (counter < frameSize)
            {
                victim = counter;
                counter++;
            }
            else
            {
                // Count the no of future occurrences;
                for (int j = 0; j < frameSize; j++)
                {
                    for (int k = i; k < n; k++)
                    {
                        if (frames[j].no == refString[k])
                        {
                            frames[j].count++;
                        }
                    }
                }

                // Select the page with minimum future count;
                int minCount = 99;
                for (int j = 0; j < frameSize; j++)
                {
                    if (frames[j].count < minCount)
                    {
                        minCount = frames[j].count;
                        victim = j;
                    }
                }
            }

            frames[victim].no = page;
            frames[victim].count = 0;
            pageFaults++;

            // print the frames
            for (int j = 0; j < frameSize; j++)
            {
                printf("%d\t", frames[j].no);
            }
            printf("\n");
        }
    }
    printf("Page faults : %d\n", pageFaults);
}

int main()
{
    int n = 15;
    int refString[] = {8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2};

    int frameSize;
    printf("Enter the frame size : ");
    scanf("%d", &frameSize);

    optimal(refString, n, frameSize);
    return 0;
}
