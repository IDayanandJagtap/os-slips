
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

// source /home/cslogin/File/source.sh
// source /home/cslogin/images/source.sh

int main(int argc, char **argv)
{

    int rank, size;
    int localSum = 0, globalSum = 0;
    double localAvg = 0.0, globalAvg = 0;
    int numbers[1000];

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // logic
    srand(rank);
    for (int i = 0; i < 1000; i++)
    {
        numbers[i] = rand() / 100;
        localSum += numbers[i]
    }
    localAvg = localSum / 1000.0;
    printf("Local sum of process %d is : %d\n", rank, localSum);

    MPI_Reduce(&localSum, &globalSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&localAvg, &globalAvg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        globalAvg = globalAvg / size;
        printf("Global sum : %d\n", globalSum);
        printf("Average : %d\n", globalAvg)
    }

    MPI_Finalize();

    return 0;
}