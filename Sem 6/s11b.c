
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

// source /home/cslogin/File/source.sh
// source /home/cslogin/images/source.sh

int main(int argc, char **argv)
{

    int rank, size;
    int min = 999999999999999;
    int globalMin;
    int max = -1, globalMax;
    int numbers[1000];

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // logic
    srand(rank);
    for (int i = 0; i < 1000; i++)
    {
        numbers[i] = rand() / 100;
        if (numbers[i] < min)
            min = numbers[i];

        if (numbers[i] > max)
            max = numbers[i];
    }

    printf("Min of process %d is : %d\n", rank, min);

    MPI_Reduce(&min, &globalMin, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&max, &globalMax, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Min : %d\n", globalMin);
        printf("Max : %d\n", globalMax);
    }

    MPI_Finalize();

    return 0;
}