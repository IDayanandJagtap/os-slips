/*
Write the simulation program to implement demand paging and show the page
 scheduling and total number of page faults according to the LRU (using
 counter method) page replacement algorithm. Assume the memory of n
 frames.
 Reference String : 3,5,7,2,5,1,2,3,1,3,5,3,1,6,2
*/

#include <stdio.h>

typedef struct
{
    int no;     // Page no
    int usedAt; // the time(index) when the page was last used
} Frame;

void LRU(int refString[], int n, int frameSize)
{
    int pageFaults = 0;
    int victim = -1;
    int counter = 0;

    // Initialise frames
    Frame frames[frameSize];
    for (int i = 0; i < frameSize; i++)
    {
        frames[i].no = 0;
        frames[i].usedAt = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int page = refString[i];
        int isPresent = 0; // if the page is already present in frame

        for (int j = 0; j < frameSize; j++)
        {
            if (page == frames[j].no)
            {
                isPresent = 1;
                frames[j].usedAt = i; // set the current index as the accessed time;
                break;
            }
        }

        if (!isPresent)
        {

            int lru = 99;
            // Select the victim page
            for (int j = 0; j < frameSize; j++)
            {
                if (frames[j].usedAt < lru)
                {
                    lru = frames[j].usedAt;
                    victim = j;
                }
            }

            // replace
            frames[victim].no = page;
            frames[victim].usedAt = i;

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

void main()
{
    int n, frameSize;
    printf("Enter the size of reference string : ");
    scanf("%d", &n);

    int refString[n];

    printf("Enter the reference string : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Value %d : ", i + 1);
        scanf("%d", &refString[i]);
    }

    printf("Enter the Frame size : ");
    scanf("%d", &frameSize);

    // FIFO
    LRU(refString, n, frameSize);
}