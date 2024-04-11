/*
Write the simulation program for demand paging and show the page
 scheduling and total number of page faults according the MRU page
 replacement algorithm. Assume the memory of n frames.
Reference String : 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2
*/

#include <stdio.h>

typedef struct
{
    int no;     // Page no
    int usedAt; // the time(index) when the page was last used
} Frame;

void MRU(int refString[], int n, int frameSize)
{
    int pageFaults = 0;
    int victim = -1;
    int counter = 0;

    // Initialise frames
    Frame frames[frameSize];
    for (int i = 0; i < frameSize; i++)
    {
        frames[i].no = 0;
        frames[i].usedAt = 0;
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

            if (counter < frameSize)
            {
                victim = counter;
                counter++;
            }
            else
            {

                int mru = -99;
                // Select the victim page
                for (int j = 0; j < frameSize; j++)
                {
                    if (frames[j].usedAt > mru)
                    {
                        mru = frames[j].usedAt;
                        victim = j;
                    }
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

    // Paging
    MRU(refString, n, frameSize);
}