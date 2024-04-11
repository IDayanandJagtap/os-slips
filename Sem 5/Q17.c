/*
 Write a C program to simulate Preemptive Priority scheduling. The arrival
 time and first CPU-burst and priority for different n number of
 processes should be input to the algorithm. Assume the fixed IO
 waiting time (2 units). The next CPU-burst should be generated randomly. The
 output should give Gantt chart, turnaround time and waiting time for each
 process. Also find the average waiting time and turnaround time.

*/

#include <stdio.h>

typedef struct Process
{
    int pid;
    int at;  // Arrival time
    int bt;  // burst time
    int rt;  // Remaining time
    int pt;  // priority
    int tat; // Tat
    int wt;  // Waiting time
} Process;

void priority(Process p[], int n)
{

    int currTime = 0;
    int processCompleted = 0;
    int prevIndex = -1;

    while (processCompleted != n)
    {
        int selectedProcess = -1;
        int minPriority = 99;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currTime && p[i].pt < minPriority && p[i].rt > 0)
            {
                minPriority = p[i].pt;
                selectedProcess = i;
            }
        }

        if (selectedProcess != -1)
        {

            if (prevIndex != selectedProcess)
            {
                printf("| P%d : %d", p[selectedProcess].pid, currTime);
            }

            currTime++;
            p[selectedProcess].rt--;

            prevIndex = selectedProcess;

            if (p[selectedProcess].rt == 0)
            {
                p[selectedProcess].tat = currTime - p[selectedProcess].at;
                p[selectedProcess].wt = p[selectedProcess].tat - p[selectedProcess].bt;
                processCompleted++;
            }
        }
        else
        {
            printf("| idle : %d |\n", currTime);
            currTime++;
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
        printf("Enter the priority : ");
        scanf("%d", &processes[i].pt);
        processes[i].rt = processes[i].bt;
        processes[i].pid = i + 1;
    }

    priority(processes, n);
}
