/*
Write a C program to simulate preemptive Shortest Job First (SJF) –
 scheduling. The arrival time and first CPU-burst of different jobs should be
 input to the system. Accept no. of Processes, arrival time and burst time. The
 output should give Gantt chart, turnaround time and waiting time for each
 process. Also find the average waiting time and turnaround time
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

void preSJF(Process p[], int n)
{

    int currTime = 0;
    int processCompleted = 0;
    int prevIndex = -1;

    while (processCompleted != n)
    {
        int index = -1;
        int minBurst = 99;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currTime && p[i].rt < minBurst && p[i].rt > 0)
            {
                minBurst = p[i].rt;
                index = i;
            }
        }

        if (index != -1)
        {

            if (prevIndex != index)
            {
                printf("| P%d : %d", p[index].pid, currTime);
            }

            prevIndex = index;

            currTime++;
            p[index].rt--;

            if (p[index].rt == 0)
            {
                p[index].tat = currTime - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;
                processCompleted++;
            }
        }
        else
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
    int n;
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

    preSJF(processes, n);
}