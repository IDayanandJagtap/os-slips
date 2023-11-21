#include <stdio.h>

void main(int argc, char *argv[])
{
    int *sortedArray = atoi(argv[1]);
    int size = atoi(argv[1][size - 2]);
    int key = atoi(argv[1][size - 1]);

        int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (sortedArray[mid] == key)
        {
            printf("Item %d found at index %d\n", key, mid);
            return;
        }
        else if (sortedArray[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("Item %d not found in the array\n", key);
}