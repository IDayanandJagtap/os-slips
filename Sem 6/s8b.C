/*
Write a simulation program for disk scheduling using SSTF algorithm. Accept total
number of disk blocks, disk request string, and current head position from the user. Display
the list of request in the order in which it is served. Also display the total number of head
moments.
 186, 89, 44, 70, 102, 22, 51, 124
 Start Head Position: 70 

*/

#include <stdio.h>
#include <stdlib.h>


int findNearest(int a[], int visited[] ,int n, int head){ 
    int minDiff = 999; 
    int minIndex = -1; 

    for(int i=0; i<n; i++) { 
        if(!visited[i]){ 
            
            if(abs(a[i]-head) < minDiff){
                minDiff= abs(a[i] -head);
                minIndex =i;
            }
        }
    }

    return minIndex;
}


void sstf(int a[], int n, int start)
{
    // visited array 
    int visited[n] = {0};
    int previousHead = start;
    int total = 0;

    for(int i=0; i<n; i++){ 
        int currentHeadPosition = findNearest(a, visited, n, previousHead);
        total += abs(previousHead - a[currentHeadPosition]); 
        printf("%d->", a[currentHeadPosition]);
        previousHead = a[currentHeadPosition];
        visited[currentHeadPosition] =  1;

    }

    printf("\nTotal : %d\n", total);

}

int main()
{
    
    int request[8] = {98, 183,  40, 122, 14, 124, 65, 67};
    int head = 53;
    sstf(request, 8, head);

    return 0;
}