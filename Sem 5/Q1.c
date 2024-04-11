/*
Write the simulation program to implement demand paging and show the
page scheduling and total number of page faults according to the LFU page
replacement algorithm. Assume the memory of n frames.
Reference String : 3,4,5,4,3,4,7,2,4,5,6,7,2,4,6

*/

#include <stdio.h>

typedef struct
{
    int no;     // Page no
    int count;  // Store the frequency
    int cameAt; // Store the index value when the page came (for FCFS when the count value is same)
} Frame;

void LFU(int refString[], int n, int frameSize)
{
    int pageFault = 0;

    // Initialise frames to 0
    Frame frames[frameSize];
    for (int i = 0; i < frameSize; i++)
    {
        frames[i].no = 0;
        frames[i].count = 0;
        frames[i].cameAt = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int page = refString[i];
        int isPresent = 0;
        int victim = -1;

        for (int j = 0; j < frameSize; j++)
        {
            if (page == frames[j].no)
            {
                isPresent = 1;
                // Increment the frequency
                frames[j].count++;
                break;
            }
        }

        if (!isPresent)
        {
            int minFreq = 99;
            int victim = 99;
            // To find the least frequency
            for (int j = 0; j < frameSize; j++)
            {
                if (frames[j].count < minFreq)
                {
                    minFreq = frames[j].count;
                    victim = j;
                }
            }
            // to find who came first if there is a tie
            for (int j = 0; j < frameSize; j++)
            {
                if (frames[j].count == minFreq)
                {
                    if (frames[j].cameAt < frames[victim].cameAt)
                    {
                        victim = j;
                    }
                }
            }

            // replace
            frames[victim].no = page;
            frames[victim].count = 1;
            frames[victim].cameAt = i; // This page was inserted at (i)th index;

            pageFault++;

            // Print the frames
            for (int j = 0; j < frameSize; j++)
            {
                printf("%d\t", frames[j].no);
            }
        }
        printf("\n");
    }
    printf("No of page faults : %d\n", pageFault);
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
    LFU(refString, n, frameSize);
}