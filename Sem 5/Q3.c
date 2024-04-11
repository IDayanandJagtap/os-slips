/*
Write the simulation program for demand paging and show the page
 scheduling and total number of page faults according the FIFO page
 replacement algorithm. Assume the memory of n frames.
 Reference String : 3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6
*/

#include <stdio.h>

void FIFO(int refString[], int n, int frameSize)
{
    int counter = 0;
    int pageFaults = 0, pageReplacements = 0;

    // Initialise frames array !
    int frames[frameSize];
    for (int i = 0; i < frameSize; i++)
    {
        frames[i] = 0;
    }

    printf("Frame : \n");
    // Paging
    for (int i = 0; i < n; i++)
    {
        int page = refString[i];
        int isPresent = 0;

        for (int j = 0; j < frameSize; j++)
        {
            if (page == frames[j])
            {
                isPresent = 1;
                break;
            }
        }

        if (!isPresent)
        {
            frames[counter % frameSize] = page;
            pageFaults++;
            counter++;

            // Print the frames if there is a page fault;
            for (int j = 0; j < frameSize; j++)
            {
                printf("%d\t", frames[j]);
            }
            printf("\n");
        }
    }
    printf("No of page faults : %d\n", pageFaults);
    printf("No of page replacements : %d\n", (pageFaults - frameSize));
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
    FIFO(refString, n, frameSize);
}