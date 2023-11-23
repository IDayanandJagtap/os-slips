#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
    int remaining_time[n];
    for (int i = 0; i < n; i++)
        remaining_time[i] = bt[i];

    int t = 0; // Current time

    while (1)
    {
        int done = 1;

        for (int i = 0; i < n; i++)
        {
            if (remaining_time[i] > 0)
            {
                done = 0;

                if (remaining_time[i] > quantum)
                {
                    t += quantum;
                    remaining_time[i] -= quantum;
                }
                else
                {
                    t += remaining_time[i];
                    wt[i] = t - bt[i];
                    remaining_time[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTimes(int processes[], int n, int bt[], int quantum)
{
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnaroundTime(processes, n, bt, wt, tat);

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", (float)total_tat / (float)n);
    printf("\nAverage Waiting Time: %.2f", (float)total_wt / (float)n);
}

int main()
{
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1; // Process IDs
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    findAverageTimes(processes, n, burst_time, quantum);

    return 0;
}
