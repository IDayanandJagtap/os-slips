// binarySearch.c

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Key not found
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <size> <key> <sorted_array_elements...>\n", argv[0]);
        return 1;
    }

    int size = atoi(argv[1]);
    int key = atoi(argv[2]);

    if (argc != size + 3)
    {
        fprintf(stderr, "Incorrect number of array elements provided.\n");
        return 1;
    }

    int *arr = malloc(size * sizeof(int));

    if (!arr)
    {
        perror("Memory allocation error");
        return 1;
    }

    // Convert command line arguments to integers and fill the array
    for (int i = 0; i < size; i++)
    {
        arr[i] = atoi(argv[i + 3]);
    }

    // Perform binary search
    int result = binarySearch(arr, size, key);

    // Display the result
    if (result != -1)
    {
        printf("Key %d found at index %d.\n", key, result);
    }
    else
    {
        printf("Key %d not found in the array.\n", key);
    }

    // Free allocated memory
    free(arr);

    return 0;
}
