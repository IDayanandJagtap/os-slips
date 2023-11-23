/*
Write the simulation program for Round Robin scheduling for given time
 quantum. The arrival time and first CPU-burst of different jobs should be input
 to the system. Accept no. of Processes, arrival time and burst time. The output
 should give the Gantt chart, turnaround time and waiting time for each
 process. Also display the average turnaround time and average waiting time.
*/

#include <stdio.h>

typedef struct Process
{
    int pid;
    int at;  // Arrival time
    int bt;  // burst time
    int rt;  // Remaining time
    int tat; // Tat
    int wt;  // Waiting time
} Process;

void rr(Process p[], int n, int timeQuantum)
{

    int currTime = 0;
    int processCompleted = 0;
    int execTime;

    while (processCompleted != n)
    {
        int execute = 0;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currTime && p[i].rt > 0)
            {
                execTime = p[i].rt < timeQuantum ? p[i].rt : timeQuantum;
                execute = 1;

                printf("| P%d : %d ", p[i].pid, currTime);
                currTime += execTime;
                p[i].rt -= execTime;

                if (p[i].rt == 0)
                {
                    p[i].tat = currTime - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    processCompleted++;
                }
            }
        }
        if (!execute)
        {
            printf("| idle : %d ", currTime);
        }
    }

    printf("| idle : %d |\n", currTime);

    // Calculate Average tat and wt :
    float avgTat = 0, avgWt = 0;

    for (int i = 0; i < n; i++)
    {
        avgTat += p[i].tat;
        avgWt += p[i].wt;
    }

    avgTat /= n;
    avgWt /= n;

    printf("\nAverage Turn around time : %.2f", avgTat);
    printf("\nAverage Waiting time : %.2f\n", avgWt);
}

void main()
{
    int n, timeQuantum;
    printf("Enter the no of processes : ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the at and bt of %dth process : ", i + 1);
        scanf("%d%d", &processes[i].at, &processes[i].bt);
        processes[i].rt = processes[i].bt;
        processes[i].pid = i + 1;
    }
    printf("Enter the time quantum : ");
    scanf("%d", &timeQuantum);

    rr(processes, n, timeQuantum);
}
