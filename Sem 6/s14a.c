/*
 Write a program to simulate Sequential (Contiguous) file allocation method.
Assume disk with n number of blocks. Give value of n as input. Randomly mark some
block as allocated and accordingly maintain the list of free blocks Write menu driver
program with menu options as mentioned below and implement each option.
• Show Bit Vector
• create file
• Show Directory
• Delete File
• Exit
*/

/*

    1. memory - bitvector (n)
    2. directory : array of {filename, start , length}
    [1,0,1,]
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char filename[20];
    int start;
    int length;
} Dir;

Dir directory[10];
int filePointer = 0;

// show bit vector
void showBitVector(int memory[], int n)
{
    int i;
    printf("\n******************* MEMORY ***********************\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", memory[i]);
    }
    printf("\n**************************************************\n");
}

// create file
void createFile(int memory[], int n)
{
    int start, length, i;
    char filename[20];

    // accept from user
    printf("Enter file name : ");
    scanf("%s", filename);
    printf("Enter start block : ");
    scanf("%d", &start);
    printf("Enter size : ");
    scanf("%d", &length);

    // check whether requested memory is free
    for (i = start; i < start + length; i++)
    {
        if (memory[i] == 0)
        {
            printf("Requested memory is occupied\n");
            return;
        }
    }

    // Memory is available;
    // Allocate memory
    for (i = start; i < start + length; i++)
    {
        memory[i] = 0;
    }

    // directory entry
    strcpy(directory[filePointer].filename, filename);
    directory[filePointer].start = start;
    directory[filePointer].length = length;
    filePointer++;
    printf("\nFile created successfully\n");
}

void deleteFile(int memory[], int n)
{
    // free memory
    char filename[20];
    printf("Enter file to be deleted : ");
    scanf("%s", filename);

    for (int i = 0; i < filePointer; i++)
    {
        if (strcmp(directory[i].filename, filename) == 0)
        {
            // free memory;
            for (int j = directory[i].start; j < directory[i].start + directory[i].length; j++)
            {
                memory[j] = 1;
            }
            // remove from directory;
            strcpy(directory[i].filename, "free");
            directory[i].start = 0;
            directory[i].length = 0;
            return;
        }
    }

    printf("File not found !");
}

// show directory
void showDirectory()
{
    int i;
    printf("\n******************* MEMORY ***********************\n");
    for (i = 0; i < filePointer; i++)
    {
        if (strcmp(directory[i].filename, "free") != 0)
        {
            printf("\nFilename : %s\n", directory[i].filename);
            printf("Start block : %d\n", directory[i].start);
            printf("Size  : %d\n\n", directory[i].length);
        }
    }
    printf("\n**************************************************\n");
}
int main()
{
    int n, ch, i;
    printf("Enter the size of memory : ");
    scanf("%d", &n);

    // create memory
    int memory[n];

    // initialise to 1(free)
    for (i = 0; i < n; i++)
    {
        memory[i] = 1;
    }

    // randomly allocate some blocks
    srand(100);
    for (i = 0; i < 25; i++)
    {
        int randNum = rand() / 100000000;
        memory[randNum] = 0;
    }

    while (1)
    {
        printf("\nSelect an option\n");
        printf("\n\t1. Show bit vector\n");
        printf("\n\t2. create new file\n");
        printf("\n\t3. delete file\n");
        printf("\n\t4. show directory\n");
        printf("\n\t5. exit\n");

        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            showBitVector(memory, n);
            break;
        case 2:
            createFile(memory, n);
            break;
        case 3:
            deleteFile(memory, n);
            break;
        case 4:
            showDirectory();
            break;

        default:
            break;
        }
    }

    return 0;
}