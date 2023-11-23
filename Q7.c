/*
Write the simulation program for demand paging and show the page
 scheduling and total number of page faults according the MFU page
 replacement algorithm. Assume the memory of n frames.
Reference String : 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2
*/

#include <stdio.h>

typedef struct
{
    int no;     // Page no
    int count;  // Store the frequency
    int cameAt; // Store the index value when the page came (for FCFS when the count value is same)
} Frame;

void MFU(int refString[], int n, int frameSize)
{
    int pageFault = 0;
    int counter = 0;
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
            if (counter < frameSize)
            {
                victim = counter;
                counter++;
            }
            else
            {
                int maxFreq = -1;

                for (int j = 0; j < frameSize; j++)
                {
                    if (frames[j].count > maxFreq)
                    {
                        maxFreq = frames[j].count;
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
            printf("\n");
        }
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
    MFU(refString, n, frameSize);
}