/*
Write a C program to accept n integers to be sorted. Main function
 creates child process using fork system call. Parent process sorts the integers
 using bubble sort and waits for child process using wait system call. Child
 process sorts the integers using insertion sort.
*/

/*
    int i,j,key;
    for(i=1; i<n; i++){
        key = a[i];                 // element to be inserted

        j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;

    }

*/

#include <stdio.h>
#include <unistd.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\n");
}

void main()
{
    int n;
    printf("Enter the no of elements : ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth number : ", i + 1);
        scanf("%d", &arr[i]);
    }

    if (fork() == 0)
    {

        int i, j, key;
        for (i = 1; i < n; i++)
        {
            key = arr[i]; // element to be inserted

            j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }

        printArray(arr, n);
    }
    else
    {
        int temp;
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        printArray(arr, n);
    }
}